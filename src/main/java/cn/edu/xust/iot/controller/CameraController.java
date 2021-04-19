package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.camera.conf.CameraRTSPToHttpFlvConfig;
import cn.edu.xust.iot.camera.data.CameraWorkerCache;
import cn.edu.xust.iot.camera.handler.CameraThread;
import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.model.CameraInfoModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Camera;
import cn.edu.xust.iot.model.vo.CameraVO;
import cn.edu.xust.iot.service.ICameraService;
import cn.edu.xust.iot.utils.CommonUtils;
import io.swagger.annotations.*;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;


/**
 * 摄像机控制接口，主要用户打开/停止摄像机实时监控、获取摄像机配置信息等
 *
 * @author HuangXin
 * @Title CameraController.java
 * @description controller
 * @time 2020年4月9日 上午9:00:27
 **/

@Slf4j
@RequestMapping(value = "/camera")
@Api(tags = "摄像机控制接口")
@RestController
public class CameraController {


    @Autowired
    private CameraRTSPToHttpFlvConfig config;// 配置文件bean

    @Autowired
    private ICameraService cameraService;

    /**
     * 存放执行任务的线程
     */
    public static Map<String, CameraThread.MyRunnable> WORK_MAP = new ConcurrentHashMap<>();

    /**
     * 先校验参数，然后判断缓存是否为空（如果为空说明目前没有推流任务，否则遍历缓存，通过参数判断当前通道是否在推流。
     * 如果找到，则该路视频的推流人数count+1，否则直接调用openStream()方法创建新的推流并将其放置到缓存中）。
     *
     * @param cameraInfoModel 表单传入的信息
     * @param result     进行数据校验的结果
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
            required = true, dataTypeClass = CameraInfoModel.class, paramType = "body")})
    @RequestMapping(value = "/live", method = RequestMethod.POST)
    public CommonResponse<Object> openCamera(@RequestBody @Valid CameraInfoModel cameraInfoModel, BindingResult result) {
        //首先处理数据校验结果，如果有错误直接不处理后续流程了
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("开启摄像头实时监控失败，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            return CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID,builder.toString());
        }
        // ip格式校验
        if (!CommonUtils.isCorrectIp(cameraInfoModel.getIp())) {
            return CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID);
        }
        return cameraService.openCamera(cameraInfoModel);
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
    public CommonResponse<Map<String,String>> closeCamera(@PathVariable("tokens") String tokens) {
        if (null != tokens && !"".equals(tokens)) {
            String[] tokenArr = tokens.split(",");
            HashMap<String, String> resMap = new HashMap<>(16);
            for (String token : tokenArr) {
                boolean closeRes = cameraService.closeCamera(token);
                if(closeRes){
                    resMap.put(token,"关闭token="+token+"的摄像机成功");
                }else{
                    resMap.put(token,"关闭token="+token+"的摄像机失败");
                }
            }
            return CommonResponse.create(AppResponseCode.SUCCESS,resMap);
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
    @GetMapping(value = "/all-in-working")
    public Map<String, CameraInfoModel> getCameras() {
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
                CameraInfoModel cameraPojo;
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
        String upTime = CommonUtils.getDateDiff(CameraWorkerCache.START_TIME, nowTime);
        log.info("获取服务信息：" + config.toString() + ";服务运行时间：" + upTime);
        Map<String, Object> status = new HashMap<>();
        status.put("cameraRTSPToHttpFlvConfig", config);
        status.put("uptime", upTime);
        return CommonResponse.create(AppResponseCode.SUCCESS, status);
    }



    @ApiOperation(value="获取系统所有摄像机信息",notes="查询数据库，获得所有摄像头数据")
    @GetMapping(value = "/all")
    public CommonResponse<List<CameraVO>> getAllCameras(){
        List<Camera> allCameras = cameraService.getAllCamera();
        List<CameraVO> res = new ArrayList<>();
        for(Camera camera:allCameras){
            CameraVO cameraVO = new CameraVO();
            cameraVO.setDeviceName(camera.getDeviceName());
            cameraVO.setDeviceStatus(camera.getDeviceStatus());
            cameraVO.setIp(camera.getIp());
            cameraVO.setPassword(camera.getPassword());
            cameraVO.setUserName(camera.getUserName());
            res.add(cameraVO);
        }
        return CommonResponse.create(AppResponseCode.SUCCESS,res);
    }


}
