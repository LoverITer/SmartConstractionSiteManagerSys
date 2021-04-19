package cn.edu.xust.iot.sdc.service;

import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.service.IHWPuSDKService;
import org.junit.After;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;


/**
 * TDD：Test-Driven Development 测试驱动开发
 *
 * @author HuangXin
 * @since 2021/03/25 14:51
 */
@RunWith(SpringRunner.class)
@SpringBootTest
public class HWPuServiceTest {

    @Autowired
    private IHWPuSDKService hwPuSDKService;
    private static final String DEVICE_IP = "192.168.0.120";

    @After
    public void after() {
        // 退出登陆并清除SDK初始化
        if (hwPuSDKService != null) {
            hwPuSDKService.logout(DEVICE_IP);
            hwPuSDKService.close();
        }
    }


    @Test
    public void testInitSDK() {
        boolean init = hwPuSDKService.init();
        System.out.println(init);
    }

    /**
     * 测试登陆设备
     */
    @Test
    public void testDefaultLogin() {
        boolean init = hwPuSDKService.init();
        if (init) {
            long loginRes2 = hwPuSDKService.login("192.168.0.120", 6060, "admin", "HuaWei123");
            System.out.println("登陆成功，ID：" + loginRes2);
        }
    }


    /**
     * 测试获取设备信息
     */
    @Test
    public void testGetDeviceInfo() {
        boolean init = hwPuSDKService.init();
        if (init) {
            long loginRes2 = hwPuSDKService.login("192.168.0.120", 6060, "admin", "HuaWei123");
            CameraModel deviceInfo = hwPuSDKService.getDeviceInfo("192.168.0.120");
            if(deviceInfo!=null){
                System.out.println("获取设备信息成功");
            }
        }
    }

}
