package cn.edu.xust.iot.conf;

import cn.edu.xust.iot.mapper.CameraMapper;
import cn.edu.xust.iot.model.entity.Camera;
import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.service.impl.HWPuSDKServiceImpl;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * 在项目启动的时候自动查询数据库中的摄像机初始化SDK并登陆到摄像机,并且在程序退出的时候自动销毁已经注册过的程序
 *
 * @author HuangXin
 * @since 2021/4/19 15:04
 */
@Slf4j
@Component
public class HWPuSDKResourceManager implements ApplicationRunner, DisposableBean {

    @Autowired
    private CameraMapper cameraMapper;

    @Autowired
    private IHWPuSDKService hwPuSDKService;

    @Override
    public void run(ApplicationArguments args) throws Exception {
        List<Camera> cameras = cameraMapper.selectCameraLoginParam();
        boolean init = hwPuSDKService.init();
        if (!init) {
            log.error("HWPuSDKInitConfig 初始化SDK发生错误");
            return;
        }
        for (Camera camera : cameras) {
            String ip = camera.getIp();
            int port = camera.getPort();
            String username = camera.getUserName();
            String password = camera.getPassword();
            try {
                long login = hwPuSDKService.login(ip, port, username, password);
                if (login <= 0) {
                    continue;
                }
                log.debug("HWPuSDKInitConfig 登陆摄像机 {}:{} 成功", ip, port);
            } catch (Exception e) {
                e.printStackTrace();
                log.error("HWPuSDKInitConfig 登陆摄像机发生错误");
            }
        }
    }

    @Override
    public void destroy() throws Exception {
        Map<String, Long> loginMap = HWPuSDKServiceImpl.CAMERAS_LOGIN_MAP;
        Set<String> ipSet = loginMap.keySet();
        hwPuSDKService.close();
        ipSet.forEach(ip-> hwPuSDKService.logout(ip));
    }


}
