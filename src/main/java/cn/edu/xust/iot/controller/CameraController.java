package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.CommonResponse;
import cn.edu.xust.iot.camera.CameraWorkerCache;
import cn.edu.xust.iot.camera.builder.CameraType;
import cn.edu.xust.iot.camera.builder.RTSPStreamBuilderFactory;
import cn.edu.xust.iot.camera.conf.CameraRTSPToHttpFlvConfig;
import cn.edu.xust.iot.camera.handler.CameraThread;
import cn.edu.xust.iot.camera.pojo.CameraInfo;
import cn.edu.xust.iot.camera.push.CameraPusher;
import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.utils.CommonUtils;
import io.swagger.annotations.*;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;


/**
 * @author HuangXin
 * @Title CameraController.java
 * @description controller
 * @time 2020年4月9日 上午9:00:27
 **/

@Slf4j
@RequestMapping(value = "/cameras")
@Api(value = "CameraController", tags = "摄像机控制接口，主要用户打开/停止摄像机实时监控、获取摄像机配置信息等")
@RestController
public class CameraController {


    @Autowired
    public CameraRTSPToHttpFlvConfig config;// 配置文件bean

    /**
     * 存放执行任务的线程
     */
    public static Map<String, CameraThread.MyRunnable> WORK_MAP = new ConcurrentHashMap<>();

    /**
     * 先校验参数，然后判断缓存是否为空（如果为空说明目前没有推流任务，否则遍历缓存，通过参数判断当前通道是否在推流。
     * 如果找到，则该路视频的推流人数count+1，否则直接调用openStream()方法创建新的推流并将其放置到缓存中）。
     *
     * @param cameraInfo   表单传入的信息
     * @param result 进行数据校验的结果
     * @return Map<String, String>
     * @Title: openCamera
     * @Description: 开启视频流
     **/
    @ApiOperation(value = "开启视频流", notes = "先校验参数，然后判断缓存是否为空（如果为空说明目前没有推流任务，否则遍历缓存，" +
            "通过参数判断当前通道是否在推流。如果找到，则该路视频的推流人数count+1，否则直接调用openStream()方法创建新的推流并将其放置到缓存中）。")
    @ApiResponses({@ApiResponse(code = 201, message = "打开视频流成功", response = CommonResponse.class),
            @ApiResponse(code = 4051, message = "摄像机直播流请求参数不完整（或有误）", response = CommonResponse.class),
            @ApiResponse(code = 501, message = "打开视频流失败", response = CommonResponse.class),
            @ApiResponse(code = 100, message = "设备正在结束回放,请稍后再试", response = CommonResponse.class),
            @ApiResponse(code = 101, message = "设备正在结束回放,请稍后再试", response = CommonResponse.class)
    })
    @ApiImplicitParams({@ApiImplicitParam(name = "cameraInfo", value = "需要开始监控的摄像机信息",
                        required = true, dataTypeClass = CameraInfo.class, paramType = "body")})
    @RequestMapping(value = "/live", method = RequestMethod.POST)
    public CommonResponse<Object> openCamera(@RequestBody @Valid CameraInfo cameraInfo, BindingResult result) {
        // 返回数据，除了msg和code  之外只需要返回打开推流相机的信息给前端即可
        CommonResponse<Object> response = CommonResponse.create(AppResponseCode.SUCCESS);
        //首先处理数据校验结果，如果有错误直接不处理后续流程了
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("开启摄像头实时监控失败，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            response = CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID);
            response.setData(builder.toString());
        }
        // ip格式校验
        if (!CommonUtils.isCorrectIp(cameraInfo.getIp())) {
            return CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID);
        }
        if (null != cameraInfo.getStartTime() || "".equals(cameraInfo.getStartTime())) {
            // 开始时间校验
            if (!CommonUtils.isTrueTime(cameraInfo.getStartTime())) {
                return CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID);
            }
            if (null != cameraInfo.getEndTime() || "".equals(cameraInfo.getEndTime())) {
                if (!CommonUtils.isTrueTime(cameraInfo.getEndTime())) {
                    return CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID);
                }
                // 结束时间要大于开始时间
                try {
                    long startTime = new SimpleDateFormat("yyyy-MM-dd HH:ss:mm").parse(cameraInfo.getStartTime()).getTime();
                    long endTime = new SimpleDateFormat("yyyy-MM-dd HH:ss:mm").parse(cameraInfo.getEndTime()).getTime();
                    if (endTime - startTime < 0) {
                        return CommonResponse.create(AppResponseCode.FAIL.getCode(), "end time需要大于start time", null);
                    }
                } catch (ParseException e) {
                    log.error(e.getMessage());
                }
            }
        }

        // 获取当前时间
        String openTime = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date().getTime());
       /* Set<String> keys = CameraWorkerCache.START_MAP.keySet();
        boolean sign = false;
        // 遍历缓存中是否此摄像机之前是否开启过，如果开启过就重新打开
        for (String key : keys) {
            if (info.getIp().equals(CameraWorkerCache.START_MAP.get(key).getIp())
                    && info.getChannel().equals(CameraWorkerCache.START_MAP.get(key).getChannel())
                    && null == CameraWorkerCache.START_MAP.get(key).getStartTime()) {// 存在直播流
                cameraInfo = CameraWorkerCache.START_MAP.get(key);
                sign = true;
                break;
            }
        }
        if (sign) {// 存在
            cameraInfo.setCount(cameraInfo.getCount() + 1);
            cameraInfo.setOpenTime(openTime);
            response.setData(cameraInfo);
        }*/
        cameraInfo.setOpenTime(openTime);
        Map<String, Object> openMap = openStream(cameraInfo, openTime);
        if (Integer.parseInt(openMap.get("error_code").toString()) == 0) {
            response.setCode(AppResponseCode.CAMERA_OPEN_VIDEO_STREAM_SUCCESS.getCode());
            response.setMsg(AppResponseCode.CAMERA_OPEN_VIDEO_STREAM_SUCCESS.getMessage());
            response.setData((CameraInfo) openMap.get("cameraInfo"));
        } else {
            response.setCode(AppResponseCode.CAMERA_OPEN_VIDEO_STREAM_FAIL.getCode());
            response.setMsg(AppResponseCode.CAMERA_OPEN_VIDEO_STREAM_FAIL.getMessage());
        }
        return response;
    }


    /**
     * openStream()方法内先判断是否存在starttime参数（是否为null），如果有则说明该流为历史流；在判断是否存在endtime，
     * 若无endtime则使用starttime前后各加一分钟作为历史流的开始时间和结束时间。若无starttime则视为该流为直播流。
     * ffmpeg在拉取rtsp直播流和历史流时的命令不相同，所以需要上述判断！！
     * <p>
     * 通过openStream()组装rtsp命令和rtmp命令以及UUID生成的token和其他参数，set进cameraInfo中。提交当前任务到线程池，
     * 并将当前任务线程存入WORK_MAP(存放推流线程任务的缓存)中。
     *
     * @return Map<String, Object>
     * @Title: openStream
     * @Description: 推流器
     **/
    private Map<String, Object> openStream(CameraInfo cameraInfo, String openTime) {
        Map<String, Object> map = new HashMap<>();
        // 生成token
        String token = CommonUtils.getRandomStr();
        String rtsp = "";
        String rtmp = "";
        String IP = CommonUtils.IpConvert(cameraInfo.getIp());
        String url = "";
        String startTime = cameraInfo.getStartTime();
        String endTime = cameraInfo.getEndTime();
        String username = cameraInfo.getUsername();
        String password = cameraInfo.getPassword();
        String channel = cameraInfo.getChannel();
        boolean sign = false;// 该NVR是否再回放，true：在回放；false： 没在回放
        // 历史流
        if (null != startTime && !"".equals(startTime)) {
            if (null != endTime && !"".equals(endTime)) {
                rtsp = "rtsp://" + username + ":" + password + "@" + IP + ":554/Streaming/tracks/"
                        + (Integer.parseInt(channel) - 32) + "01?starttime=" + CommonUtils.getTime(startTime).substring(0, 8)
                        + "t" + CommonUtils.getTime(startTime).substring(8) + "z'&'endtime="
                        + CommonUtils.getTime(endTime).substring(0, 8) + "t" + CommonUtils.getTime(endTime).substring(8) + "z";
                cameraInfo.setStartTime(CommonUtils.getTime(cameraInfo.getStartTime()));
                cameraInfo.setEndTime(CommonUtils.getTime(endTime));
            } else {
                startTime = CommonUtils.getStartTime(cameraInfo.getStartTime());
                endTime = CommonUtils.getEndTime(cameraInfo.getStartTime());
                rtsp = "rtsp://" + username + ":" + password + "@" + IP + ":554/Streaming/tracks/"
                        + (Integer.parseInt(channel) - 32) + "01?starttime=" + startTime.substring(0, 8) + "t"
                        + startTime.substring(8) + "z'&'endtime=" + endTime.substring(0, 8) + "t" + endTime.substring(8)
                        + "z";
                cameraInfo.setStartTime(CommonUtils.getStartTime(startTime));
                cameraInfo.setEndTime(CommonUtils.getEndTime(startTime));
            }
            log.debug("推流 RTSP：{}", rtsp);
            rtmp = "rtmp://" + CommonUtils.IpConvert(config.getPushHost()) + ":" + config.getPushPort() + "/history/test";
            if (config.getHostExtra().equals("127.0.0.1")) {
                url = rtmp;
            } else {
                url = "rtmp://" + CommonUtils.IpConvert(config.getHostExtra()) + ":" + config.getPushPort() + "/history/" + token;
            }
        } else {// 直播流
            rtsp = RTSPStreamBuilderFactory.generateRTSPStreamURL(CameraType.HUAWEI, cameraInfo);
            rtmp = "rtmp://" + CommonUtils.IpConvert(config.getPushHost()) + ":" + config.getPushPort() + "/live/" + token;
            if ("127.0.0.1".equals(config.getHostExtra()) || "localhost".equals(config.getHostExtra())) {
                url = rtmp;
            } else {
                url = "rtmp://" + CommonUtils.IpConvert(config.getHostExtra()) + ":" + config.getPushPort() + "/live/" + token;
            }
        }

        cameraInfo.setRtsp(rtsp);
        cameraInfo.setRtmp(rtmp);
        //远程访问URL
        cameraInfo.setUrl(url);
        cameraInfo.setOpenTime(openTime);
        cameraInfo.setToken(token);

        // 开启异步线程执行任务
        CameraThread.MyRunnable job = new CameraThread.MyRunnable(cameraInfo);
        CameraThread.MyRunnable.executor.execute(job);
        WORK_MAP.put(token, job);
        map.put("cameraInfo", cameraInfo);
        map.put("error_code", 0);
        return map;
    }

    /**
     * 传入参数为tokens，通过","分隔,即可以同时关闭多路视频。通过token查找缓存判断是否存在，如果存在，则人数count-1。
     * 不直接调用结束线程的方法是为了满足如果多个客户端同时观看该路视频，一人关闭会影响其他人使用。
     * 故调用该接口只是使该路视频的使用人数-1，最终结束线程的操作交由定时任务处理，如果定时器查询到视频使用人数的count为0，
     * 则结束该路视频的推流操作，并清除缓存。
     *
     * @param tokens
     * @return void
     * @Title: closeCamera
     * @Description:关闭视频流
     **/
    @ApiOperation(value = "关闭视频流", notes = "传入参数为tokens，通过\",\"分隔,即可以同时关闭多路视频。通过token查找缓存判断是否存在，如果存在，则人数count-1。\n" +
            "不直接调用结束线程的方法是为了满足如果多个客户端同时观看该路视频，一人关闭会影响其他人使用。                    \n" +
            "故调用该接口只是使该路视频的使用人数-1，最终结束线程的操作交由定时任务处理，如果定时器查询到视频使用人数的count为0，    \n" +
            "则结束该路视频的推流操作，并清除缓存。")
    @ApiResponses({@ApiResponse(code = 200, message = "操作成功", response = CommonResponse.class),
            @ApiResponse(code = 405, message = "请求参数有误，无法操作", response = CommonResponse.class)})
    @ApiImplicitParams({@ApiImplicitParam(name = "tokens", value = "需要关闭实时监控的摄像机唯一ID",
            required = true, dataTypeClass = String.class, paramType = "path")})
    @RequestMapping(value = "/close/{tokens}", method = RequestMethod.GET)
    public CommonResponse<String> closeCamera(@PathVariable("tokens") String tokens) {
        if (null != tokens && !"".equals(tokens)) {
            String[] tokenArr = tokens.split(",");
            for (String token : tokenArr) {
                if (WORK_MAP.containsKey(token) && CameraWorkerCache.START_MAP.containsKey(token)) {
                    log.info("关闭会话token为 {} 的设备,设备信息：{}",token,CameraWorkerCache.START_MAP.get(token).toString());
                    CameraPusher pusher = CameraWorkerCache.PUSH_MAP.get(token);
                    pusher.stopPublish();
                    //从START_MAP中移除
                    CameraWorkerCache.START_MAP.remove(token);
                    //移除
                    WORK_MAP.remove(token);
                    log.info("成功关闭会话token为 {} 的设备",token);
                }
            }
            return CommonResponse.create(AppResponseCode.SUCCESS);
        }
        return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
    }

    /**
     * 获取当前进行的推流任务。
     *
     * @return Map<String, CameraPojo>
     * @Title: getCameras
     * @Description:获取视频流
     **/
    @ApiOperation(value = "获取视频流信息", notes = "获取当前正在进行的推流任务")
    @GetMapping(value = "/all")
    public Map<String, CameraInfo> getCameras() {
        log.info("获取视频流信息：" + CameraWorkerCache.START_MAP.toString());
        return CameraWorkerCache.START_MAP;
    }

    /**
     * 视频流保活的作用是为了处理以下场景：
     * 如果客户端比如浏览器直接关闭掉，并不会通知服务客户已经不再观看视频了，这是服务还在进行推流。所以添加保活机制，
     * 如果客户端没有触发保活机制，定时任务执行时，如果该路视频的最后打开时间距当前时间超过配置的保活时间时，关闭该路视频的推流任务。
     * 如果客户端触发保活机制时，更新该路视频的最后打开时间（opentime）为当前系统时间。
     *
     * @param tokens
     * @return void
     * @Title: keepAlive
     * @Description:视频流保活
     **/
    @RequestMapping(value = "/keepAlive/{tokens}", method = RequestMethod.PUT)
    public void keepAlive(@PathVariable("tokens") String tokens) {
        // 校验参数
        if (null != tokens && !"".equals(tokens)) {
            String[] tokenArr = tokens.split(",");
            for (String token : tokenArr) {
                CameraInfo cameraPojo;
                // 直播流token
                if (null != CameraWorkerCache.START_MAP.get(token)) {
                    cameraPojo = CameraWorkerCache.START_MAP.get(token);
                    // 更新当前系统时间
                    cameraPojo.setOpenTime(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date().getTime()));
                    log.info("设置保活成功 设备信息：[ip：" + cameraPojo.getIp() + " channel:" + cameraPojo.getChannel()
                            + " stream:" + cameraPojo.getStream() + " starttime:" + cameraPojo.getStartTime()
                            + " endtime:" + cameraPojo.getEndTime() + " url:" + cameraPojo.getUrl() + "]");
                }
            }
        }
    }

    /**
     * 通过该接口获取服务运行时间，以及配置文件的配置
     *
     * @return Map<String, Object>
     * @Title: getConfig
     * @Description: 获取服务信息
     **/
    @ApiOperation(value = "获取服务信息", notes = "通过该接口获取服务运行时间，以及摄像机推流有关的配置信息")
    @GetMapping(value = "/status")
    public CommonResponse<Map<String, Object>> getConfig() {
        // 获取当前时间
        long nowTime = new Date().getTime();
        String upTime = CommonUtils.dateDiff(CameraWorkerCache.START_TIME, nowTime);
        log.info("获取服务信息：" + config.toString() + ";服务运行时间：" + upTime);
        Map<String, Object> status = new HashMap<>();
        status.put("cameraRTSPToHttpFlvConfig", config);
        status.put("uptime", upTime);
        return CommonResponse.create(AppResponseCode.SUCCESS, status);
    }

}
