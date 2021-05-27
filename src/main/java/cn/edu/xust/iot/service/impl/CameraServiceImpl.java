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
import cn.edu.xust.iot.mapper.DangerBehaviorMapper;
import cn.edu.xust.iot.mapper.RegionCameraMapper;
import cn.edu.xust.iot.mapper.RegionMapper;
import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.CameraAISettingModel;
import cn.edu.xust.iot.model.CameraInfoModel;
import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Camera;
import cn.edu.xust.iot.model.entity.Region;
import cn.edu.xust.iot.model.entity.RegionCamera;
import cn.edu.xust.iot.model.vo.CameraAmountVO;
import cn.edu.xust.iot.model.vo.CameraVO;
import cn.edu.xust.iot.service.ICameraService;
import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.utils.CommonUtils;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

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

    @Qualifier("cameraMapper")
    @Autowired
    private CameraMapper cameraMapper;

    @Autowired
    private RegionMapper regionMapper;

    @Autowired
    private RegionCameraMapper regionCameraMapper;

    @Autowired
    private IHWPuSDKService hwPuSDKService;

    @Autowired
    private DangerBehaviorMapper dangerBehaviorMapper;

    //摄像机智能业务开启状态 key是相机IP
    private static final Map<String, CameraAISettingModel> AI_SERVICE_ENABLE_MAPPING = new ConcurrentHashMap<>(16);


    @Override
    public CommonResponse<Object> openCamera(CameraInfoModel cameraInfoModel) {
        CommonResponse<Object> response = CommonResponse.create(AppResponseCode.SUCCESS);
        if (!CommonUtils.isNull(cameraInfoModel.getStartTime())) {
            // 开始时间校验
            if (!CommonUtils.isTrueTime(cameraInfoModel.getStartTime())) {
                return CommonResponse.create(AppResponseCode.CAMERA_REQUEST_PARAMETER_VALID);
            }
            if (!CommonUtils.isNull(cameraInfoModel.getEndTime())) {
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
        String token = CommonUtils.getRandomString();
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
    public List<Camera> getAllCamera() {
        return cameraMapper.selectAll();
    }


    @Transactional(isolation = Isolation.REPEATABLE_READ, rollbackFor = Exception.class)
    @Override
    public CommonResponse<String> addNewCamera(CameraModel cameraModel) {
        Camera camera = cameraModel.convertCameraModel2Camera();
        CameraModel deviceInfo = null;
        try {
            Region region = regionMapper.selectByRegionName(cameraModel.getRegionName());
            if (region == null) {
                //还不存在此区域，就插入新区域
                region = new Region(cameraModel.getRegionName());
                int insertRes = regionMapper.insert(region);
                if (insertRes <= 0) {
                    log.error("新增监控摄像机 插入新区域失败");
                    return CommonResponse.create(AppResponseCode.FAIL);
                }

            }
            camera.setRegionId(region.getId());

            if (hwPuSDKService.checkSDKLogin(camera)) {
                //调用SDK获取摄像机当前状态
                deviceInfo = hwPuSDKService.getDeviceInfo(cameraModel.getIp());
                if (deviceInfo == null) {
                    //表示调用SDK发生异常
                    return CommonResponse.create(AppResponseCode.NOT_FOUND_NEW_CAMERA);
                }
                //调动摄像机的SDK获取摄像机的软件版本
                camera.setSdcVersion(deviceInfo.getSdcVersion());
                //调用摄像机SDK获取摄像的物理地址
                camera.setMacAddress(deviceInfo.getMacAddress());
                //调用摄像机SDK获取摄像的型号
                camera.setModel(deviceInfo.getModel());
                camera.setDeviceStatus(deviceInfo.getDeviceStatus());
            }

            int selective = cameraMapper.insertSelective(camera);
            if (selective > 0) {
                RegionCamera regionCamera = new RegionCamera(camera.getId(), region.getId());
                int insert = regionCameraMapper.insert(regionCamera);
                if (insert > 0) {
                    //返回新增的主键ID
                    return CommonResponse.create(AppResponseCode.SUCCESS);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            log.error(e.getMessage());
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }


    @Override
    public PageInfo<CameraVO> getCameraList(PageParam pageParam) {
        PageInfo<CameraVO> pages = null;
        try {
            PageHelper.startPage(pageParam.getPage(), pageParam.getPageSize());
            List<Camera> cameras = cameraMapper.selectAll();
            List<CameraVO> list = new ArrayList<>();
            for (Camera camera : cameras) {
                CameraVO cameraVO = camera.conventCamera2CameraVO();
                Region region = regionMapper.selectByPrimaryKey(camera.getRegionId());
                if (null != region) {
                    cameraVO.setRegionName(region.getRegionName());
                }
                list.add(cameraVO);
            }
            pages = new PageInfo<>(list);
            return pages;
        } catch (Exception e) {
            e.printStackTrace();
            log.error(e.getMessage());
        }
        return null;
    }

    @Override
    public CommonResponse<CameraVO> getCameraByID(Integer id) {
        try {
            Camera camera = cameraMapper.selectByPrimaryKey(id);
            CameraVO cameraVO = camera.conventCamera2CameraVO();
            Region region = regionMapper.selectByPrimaryKey(camera.getRegionId());
            if (null != region) {
                cameraVO.setRegionName(region.getRegionName());
            }
            return CommonResponse.create(AppResponseCode.SUCCESS, cameraVO);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Transactional(isolation = Isolation.REPEATABLE_READ, rollbackFor = Exception.class)
    @Override
    public CommonResponse<List<CameraVO>> getCameraListByRegionName(String regionName) {
        try {
            List<Camera> cameras = cameraMapper.selectCameraByRegionName(regionName);
            List<CameraVO> list = new ArrayList<>();
            for (Camera camera : cameras) {
                CameraVO cameraVO = camera.conventCamera2CameraVO();
                Region region = regionMapper.selectByPrimaryKey(camera.getRegionId());
                if (null != region) {
                    cameraVO.setRegionName(region.getRegionName());
                }
                list.add(cameraVO);
            }
            return CommonResponse.create(AppResponseCode.SUCCESS, list);
        } catch (Exception e) {
            e.printStackTrace();
            log.error("查询摄像机信息发生错误：{}", e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }


    @Override
    public CommonResponse<Integer> getAllCamerasSize() {
        int camerasSize = 0;
        try {
            camerasSize = cameraMapper.countCameras();
            return CommonResponse.create(AppResponseCode.SUCCESS, camerasSize);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL, camerasSize);
    }


    @Transactional(isolation = Isolation.REPEATABLE_READ, rollbackFor = Exception.class)
    @Override
    public CommonResponse<String> editCameraInfo(CameraModel cameraModel) {
        Camera camera = cameraModel.convertCameraModel2Camera();
        try {
            Region region = regionMapper.selectByRegionName(cameraModel.getRegionName());
            if (region == null) {
                //修改提交了新区域，增加新区域
                region = new Region(cameraModel.getRegionName());
                int insertRes = regionMapper.insert(region);
                if (insertRes <= 0) {
                    log.error("修改监控摄像机 插入新区域失败");
                    return CommonResponse.create(AppResponseCode.FAIL);
                }
            }
            //设置RegionId
            camera.setRegionId(region.getId());
            int rows = cameraMapper.updateByPrimaryKeySelective(camera);
            if (rows > 0) {
                log.info("摄像机信息更新成功");
                return CommonResponse.create(AppResponseCode.SUCCESS);
            }
        } catch (Exception e) {
            e.printStackTrace();
            log.error("修改监控摄像机 修改监控摄像的信息发生错误：{}", e.getMessage());
        }
        log.error("修改监控摄像机 更新摄像机信息失败");
        return CommonResponse.create(AppResponseCode.FAIL);
    }


    @Transactional(isolation = Isolation.REPEATABLE_READ, rollbackFor = Exception.class)
    @Override
    public CommonResponse<String> removeCameraBatch(List<Integer> userIdList) {
        try {
            for (Integer cameraId : userIdList) {
                regionMapper.deleteByCameraId(cameraId);
            }
            int rows = cameraMapper.batchDeleteByPrimaryKey(userIdList);
            if (rows <= 0) {
                log.error("删除监控摄像机时发生错误");
                return CommonResponse.create(AppResponseCode.FAIL);
            }
            return CommonResponse.create(AppResponseCode.SUCCESS);
        } catch (Exception e) {
            log.error("删除监控摄像机时发生错误，详细：{}", e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }


    @Override
    public CommonResponse<CameraAISettingModel> getCameraAIEnableState(String ip) {
        if (CommonUtils.isNull(ip) || !CommonUtils.isCorrectIp(ip)) {
            //请求参数不合法
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        CameraAISettingModel cameraAISetting = AI_SERVICE_ENABLE_MAPPING.get(ip);
        if (cameraAISetting == null) {
            cameraAISetting = new CameraAISettingModel();
        }
        return CommonResponse.create(AppResponseCode.SUCCESS, cameraAISetting);
    }

    @Override
    public CommonResponse<Boolean> enableCameraAISetting(String ip, String AIServiceTypeId) {
        if (CommonUtils.isNull(ip) || !CommonUtils.isCorrectIp(ip) || CommonUtils.isNull(AIServiceTypeId)) {
            //请求参数不合法
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        CameraAISettingModel cameraAISetting = AI_SERVICE_ENABLE_MAPPING.get(ip);
        if (null == cameraAISetting) {
            cameraAISetting = new CameraAISettingModel();
        }

        if (!cameraAISetting.isConflict()) {
            cameraAISetting = cameraAISetting.open(ip, AIServiceTypeId);
            if (null == cameraAISetting) {
                //开启失败
                return CommonResponse.create(AppResponseCode.FAIL, false);
            }
            AI_SERVICE_ENABLE_MAPPING.put(ip, cameraAISetting);
            return CommonResponse.create(AppResponseCode.SUCCESS, true);
        }
        //冲突了，直接返回
        return CommonResponse.create(AppResponseCode.AI_SERVICE_CONFLICT, false);

    }


    @Override
    public CommonResponse<Boolean> closeCameraAISetting(String ip, String AIServiceTypeId) {
        if (CommonUtils.isNull(ip) || !CommonUtils.isCorrectIp(ip) || CommonUtils.isNull(AIServiceTypeId)) {
            //请求参数不合法
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        CameraAISettingModel cameraAISetting = AI_SERVICE_ENABLE_MAPPING.get(ip);
        if (null == cameraAISetting) {
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        //存在相关设置：从map中取出之前的设置，然后根据关闭之
        cameraAISetting = cameraAISetting.close(ip, AIServiceTypeId);
        if (null == cameraAISetting) {
            //关闭失败
            return CommonResponse.create(AppResponseCode.FAIL, false);
        }
        AI_SERVICE_ENABLE_MAPPING.put(ip, cameraAISetting);
        return CommonResponse.create(AppResponseCode.SUCCESS, true);

    }

    @Override
    public CommonResponse<CameraAmountVO> getCameraAmountInDiffState() {
        try {
            //获取到在线、离线以及总相机数
            CameraAmountVO cameraAmountVO = cameraMapper.countCamerasByState();
            if(null==cameraAmountVO){
                cameraAmountVO=new CameraAmountVO();
            }
            int algorithmNum = cameraMapper.countCamerasByAlgorithm();
            //获取总告警数
            int totalDangerBehavior = dangerBehaviorMapper.countTotalDangerBehaviorNum();
            //获取今日告警数
            int todayDangerBehavior = dangerBehaviorMapper.countTodayDangerBehaviorNum();
            cameraAmountVO.setAlgorithmNum(algorithmNum);
            cameraAmountVO.setTotalWarningNum(totalDangerBehavior);
            cameraAmountVO.setTodayWarningNum(todayDangerBehavior);
            return CommonResponse.create(AppResponseCode.SUCCESS, cameraAmountVO);
        } catch (Exception e) {
            log.error("获取相机数量发生异常");
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }
}
