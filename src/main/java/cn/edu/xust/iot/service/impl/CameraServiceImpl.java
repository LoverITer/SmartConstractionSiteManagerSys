package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.camera.builder.CameraType;
import cn.edu.xust.iot.camera.builder.RTSPStreamBuilderFactory;
import cn.edu.xust.iot.camera.conf.CameraRTSPToHttpFlvConfig;
import cn.edu.xust.iot.camera.data.CameraWorkerCache;
import cn.edu.xust.iot.camera.handler.CameraThread;
import cn.edu.xust.iot.camera.push.CameraPusher;
import cn.edu.xust.iot.controller.CameraController;
import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.CameraMapper;
import cn.edu.xust.iot.mapper.RegionMapper;
import cn.edu.xust.iot.model.CameraInfoModel;
import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Camera;
import cn.edu.xust.iot.model.entity.Region;
import cn.edu.xust.iot.service.ICameraService;
import cn.edu.xust.iot.utils.CommonUtils;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 提供摄像机的相关操作，比如打开视频实时监控，关闭视频实时监控，管理摄像机设备等功能
 *
 * @author HuangXin
 * @since 2021/4/11 19:29
 */
@Slf4j
@Service
public class CameraServiceImpl implements ICameraService {


    @Autowired
    private CameraRTSPToHttpFlvConfig config;// 配置文件bean

    @Autowired
    private CameraMapper cameraMapper;

    @Autowired
    private RegionMapper regionMapper;

    @Override
    public CommonResponse<Object> openCamera(CameraInfoModel cameraInfoModel) {
        CommonResponse<Object> response = CommonResponse.create(AppResponseCode.SUCCESS);
        if (null != cameraInfoModel.getStartTime() || "".equals(cameraInfoModel.getStartTime())) {
            // 开始时间校验
            if (!CommonUtils.isTrueTime(cameraInfoModel.getStartTime())) {
                return CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID);
            }
            if (null != cameraInfoModel.getEndTime() || "".equals(cameraInfoModel.getEndTime())) {
                if (!CommonUtils.isTrueTime(cameraInfoModel.getEndTime())) {
                    return CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID);
                }
                // 结束时间要大于开始时间
                try {
                    long startTime = new SimpleDateFormat("yyyy-MM-dd HH:ss:mm").parse(cameraInfoModel.getStartTime()).getTime();
                    long endTime = new SimpleDateFormat("yyyy-MM-dd HH:ss:mm").parse(cameraInfoModel.getEndTime()).getTime();
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
        cameraInfoModel.setOpenTime(openTime);
        cameraInfoModel.setCount(cameraInfoModel.getCount() + 1);
        Map<String, Object> openMap = openStream(cameraInfoModel, openTime);
        if (Integer.parseInt(openMap.get("error_code").toString()) == 0) {
            response.setCode(AppResponseCode.CAMERA_OPEN_VIDEO_STREAM_SUCCESS.getCode());
            response.setMsg(AppResponseCode.CAMERA_OPEN_VIDEO_STREAM_SUCCESS.getMessage());
            response.setData(openMap.get("cameraInfo"));
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
    private Map<String, Object> openStream(CameraInfoModel cameraInfoModel, String openTime) {
        Map<String, Object> map = new HashMap<>();
        // 生成token
        String token = CommonUtils.getRandomStr();
        String rtsp = "";
        String rtmp = "";
        String IP = CommonUtils.IpConvert(cameraInfoModel.getIp());
        String url = "";
        String startTime = cameraInfoModel.getStartTime();
        String endTime = cameraInfoModel.getEndTime();
        String username = cameraInfoModel.getUsername();
        String password = cameraInfoModel.getPassword();
        String channel = cameraInfoModel.getChannel();
        boolean sign = false;// 该NVR是否再回放，true：在回放；false： 没在回放
        // 历史流
        if (null != startTime && !"".equals(startTime)) {
            if (null != endTime && !"".equals(endTime)) {
                rtsp = "rtsp://" + username + ":" + password + "@" + IP + ":554/Streaming/tracks/"
                        + (Integer.parseInt(channel) - 32) + "01?starttime=" + CommonUtils.getTime(startTime).substring(0, 8)
                        + "t" + CommonUtils.getTime(startTime).substring(8) + "z'&'endtime="
                        + CommonUtils.getTime(endTime).substring(0, 8) + "t" + CommonUtils.getTime(endTime).substring(8) + "z";
                cameraInfoModel.setStartTime(CommonUtils.getTime(cameraInfoModel.getStartTime()));
                cameraInfoModel.setEndTime(CommonUtils.getTime(endTime));
            } else {
                startTime = CommonUtils.getStartTime(cameraInfoModel.getStartTime());
                endTime = CommonUtils.getEndTime(cameraInfoModel.getStartTime());
                rtsp = "rtsp://" + username + ":" + password + "@" + IP + ":554/Streaming/tracks/"
                        + (Integer.parseInt(channel) - 32) + "01?starttime=" + startTime.substring(0, 8) + "t"
                        + startTime.substring(8) + "z'&'endtime=" + endTime.substring(0, 8) + "t" + endTime.substring(8)
                        + "z";
                cameraInfoModel.setStartTime(CommonUtils.getStartTime(startTime));
                cameraInfoModel.setEndTime(CommonUtils.getEndTime(startTime));
            }
            log.debug("推流 RTSP：{}", rtsp);
            rtmp = "rtmp://" + CommonUtils.IpConvert(config.getPushHost()) + ":" + config.getPushPort() + "/history/test";
            if (config.getHostExtra().equals("127.0.0.1")) {
                url = rtmp;
            } else {
                url = "rtmp://" + CommonUtils.IpConvert(config.getHostExtra()) + ":" + config.getPushPort() + "/history/" + token;
            }
        } else {// 直播流
            rtsp = RTSPStreamBuilderFactory.generateRTSPStreamURL(CameraType.HUAWEI, cameraInfoModel);
            rtmp = "rtmp://" + CommonUtils.IpConvert(config.getPushHost()) + ":" + config.getPushPort() + "/live/" + token;
            if ("127.0.0.1".equals(config.getHostExtra()) || "localhost".equals(config.getHostExtra())) {
                url = rtmp;
            } else {
                url = "rtmp://" + CommonUtils.IpConvert(config.getHostExtra()) + ":" + config.getPushPort() + "/live/" + token;
            }
        }

        cameraInfoModel.setRtsp(rtsp);
        cameraInfoModel.setRtmp(rtmp);
        //远程访问URL
        cameraInfoModel.setUrl(url);
        cameraInfoModel.setOpenTime(openTime);
        cameraInfoModel.setToken(token);

        // 开启异步线程执行任务
        CameraThread.MyRunnable job = new CameraThread.MyRunnable(cameraInfoModel);
        CameraThread.MyRunnable.executor.execute(job);
        CameraController.WORK_MAP.put(token, job);
        map.put("cameraInfo", cameraInfoModel);
        map.put("error_code", 0);
        return map;
    }

    @Override
    public boolean closeCamera(String token) {
        if (CameraController.WORK_MAP.containsKey(token) && CameraWorkerCache.START_MAP.containsKey(token)) {
            log.info("关闭会话token为 {} 的设备,设备信息：{}", token, CameraWorkerCache.START_MAP.get(token).toString());
            CameraPusher pusher = CameraWorkerCache.PUSH_MAP.get(token);
            pusher.stopPublish();
            //从START_MAP中移除
            CameraWorkerCache.START_MAP.remove(token);
            //移除
            CameraController.WORK_MAP.remove(token);
            log.info("成功关闭会话token为 {} 的设备", token);
            return true;
        }
        return false;
    }

    @Override
    public int addNewCamera(CameraModel cameraModel) {
        Camera camera = new Camera();
        camera.setDeviceName(cameraModel.getDeviceName());
        camera.setUserName(cameraModel.getUserName());
        camera.setIp(cameraModel.getIp());
        camera.setPassword(cameraModel.getPassword());
        camera.setPort(cameraModel.getPort());
        try{
            Region region=null;
            List<Region> regions = regionMapper.selectByRegionName(cameraModel.getRegionName());
            if(regions==null){
                region = new Region(cameraModel.getRegionName());
                int insertRes = regionMapper.insert(region);
                if(insertRes<=0){
                    log.error("插入新区域失败");
                    return 0;
                }
            }
            //如果存在已有区域信息默认取第一个
            if(region==null){
                region=regions.get(0);
            }
            camera.setRegionId(region.getId());
            int selective = cameraMapper.insertSelective(camera);
            if(selective>0){
                //返回新增的主键ID
                return camera.getId();
            }
        }catch (Exception e){
            log.error(e.getMessage());
        }
        return 0;
    }

    @Override
    public List<Camera> getAllCamera() {
        return cameraMapper.selectAll();
    }
}
