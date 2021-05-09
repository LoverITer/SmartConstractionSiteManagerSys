package cn.edu.xust.iot.conf.schedule;

import cn.edu.xust.iot.mapper.CameraMapper;
import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.model.entity.Camera;
import cn.edu.xust.iot.sdc.core.constraints.CameraStatus;
import cn.edu.xust.iot.service.IHWPuSDKService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Configuration;
import org.springframework.scheduling.annotation.Scheduled;

import java.util.List;

/**
 * 刷新摄像机设备信息定时任务
 *
 * @author HuangXin
 * @since 2021/5/9 14:13
 */
@Configuration
@Slf4j
public class RefreshCameraInformationScheduleTask {

    @Qualifier("cameraMapper")
    @Autowired
    private CameraMapper cameraMapper;

    @Autowired
    private IHWPuSDKService hwPuSDKService;


    /**
     * 每小时执行一次该任务 0 0 *\/1 * * ?
     * 秒 分钟 小时 日 月 星期
     */
    @Scheduled(cron = "0 0 */1 * * ?")
    public void configureRefreshTask() {
        try {
            List<Camera> cameras = cameraMapper.selectAll();
            for (Camera camera : cameras) {
                Camera oldCamera = (Camera) camera.clone();
                if (hwPuSDKService.checkSDKLogin(camera)) {
                    CameraModel deviceInfo = hwPuSDKService.getDeviceInfo(camera.getIp());
                    if (deviceInfo != null) {
                        camera.setSdcVersion(deviceInfo.getSdcVersion());
                        camera.setModel(deviceInfo.getModel());
                        camera.setMacAddress(deviceInfo.getMacAddress());
                        camera.setDeviceStatus(CameraStatus.ONLINE.getStatus());
                    }
                } else {
                    camera.setDeviceStatus(CameraStatus.OFFLINE.getStatus());
                }
                //如果当前相机信息和数据库中的相机信息一直就不用更新
                if (!oldCamera.equals(camera)) {
                    int rows = cameraMapper.updateByPrimaryKeySelective(camera);
                    log.debug("定时更新摄像机{}:{}设备信息{}", camera.getIp(), camera.getPort(), rows > 0 ? "成功" : "失败");
                }
            }
        } catch (Exception e) {
            log.error("定时更新摄像机设备信息发生异常");
            e.printStackTrace();
        }

    }


}
