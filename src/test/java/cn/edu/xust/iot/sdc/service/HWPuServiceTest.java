package cn.edu.xust.iot.sdc.service;

import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.utils.IdWorker;
import com.sun.jna.platform.win32.WinDef;
import org.junit.After;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.io.IOException;


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
    private static final IdWorker idWorker=new IdWorker(1, 1, 1);

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
        CameraModel deviceInfo = hwPuSDKService.getDeviceInfo("192.168.0.120");
        if (deviceInfo != null) {
            System.out.println("获取设备信息成功");
        }
    }


    @Test
    public void testGetMetaData() throws InterruptedException {
        long winID = hwPuSDKService.startRealPlay(DEVICE_IP);
        Thread.sleep(60 * 1000 * 5);
        if (winID > 0) {
            hwPuSDKService.stopAllRealPlay(DEVICE_IP);
        }
    }

    @Test
    public void testAddOneFace() throws InterruptedException, IOException {
        HWPuSDK.PU_FACE_RECORD_S.ByValue faceRecord = new HWPuSDK.PU_FACE_RECORD_S.ByValue();
        faceRecord.ulFaceId=new WinDef.ULONG(idWorker.nextId());
        faceRecord.szName="孙京华".getBytes();
        faceRecord.enGender=1;
        faceRecord.szBirthday="1997-12-02".getBytes();
        faceRecord.szProvince="陕西省".getBytes();
        faceRecord.szCity="蓝田县".getBytes();
        faceRecord.enCardType=0;
        faceRecord.szCardID="370722197812222517".getBytes();
        faceRecord.szPicPath="C:\\Users\\Administrator\\Desktop\\设计\\face_lib\\FACE_3.jpg".getBytes();
        boolean isOk = hwPuSDKService.addFace(DEVICE_IP,faceRecord);
        assert isOk = true;
    }


    public void testGetCrowdDensityParam() throws InterruptedException {
        boolean isOK = hwPuSDKService.setCrowdDensityParam(DEVICE_IP, "区域1");
        long winID = hwPuSDKService.startRealPlay(DEVICE_IP);
        Thread.sleep(60 * 1000 * 5);
        if (winID > 0) {
            hwPuSDKService.stopAllRealPlay(DEVICE_IP);
        }
    }

}
