package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.sdc.HWPuSDKResourceConfig;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.sdc.core.constraints.LinkModel;
import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.utils.CommonUtils;
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;
import com.sun.jna.platform.win32.WinDef;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/**
 * 华为摄像机服务接口实现
 *
 * @author HuangXin
 * @since 2021/4/18 0:55
 */
@Slf4j
@Service
public class HWPuSDKServiceImpl implements IHWPuSDKService {

    //SDK实例
    private static final HWPuSDK hwPuSDKInstance = HWPuSDK.INSTANCE;
    //SSL端口
    private static final int Local_SSL_Port = 5051;
    //秘钥
    private static final String CRYPT = "11A6A68F4FCBBA3C";
    //默认IP
    private static final String DEFAULT_DEVICE_IP = "192.168.0.120";
    //默认端口
    private static final int DEFAULT_DEVICE_PORT = 6060;
    //华为摄像机默认登陆用户名
    private static final String DEFAULT_USER_NAME = "admin";
    //华为摄像机默认登陆密码
    private static final String DEFAULT_USER_PASSWORD = "HuaWei123";
    //用户登陆map  key 相机的ip value 登陆后的用户ID
    public static final Map<String, Long> CAMERAS_LOGIN_MAP = new ConcurrentHashMap<>(16);
    //相机是否者在播放视频中  key 相机IP  value 打开实时监控之后返回的句柄，关闭实时监控时需要传入此句柄
    private static final Map<String, WinDef.ULONG> CAMERA_PLAYING_MAP = Collections.synchronizedMap(new HashMap<>(16));


    /**
     * 显示错误信息
     */
    private static void showErrMsg() {
        long errorCode = hwPuSDKInstance.IVS_PU_GetLastError();
        String errMsg = "error code : " + errorCode +
                ", error message : " +
                HWPuSDK.INSTANCE.IVS_PU_GetErrorMsg(errorCode);
        log.error(errMsg);
    }

    @Override
    public boolean close() {
        boolean res = hwPuSDKInstance.IVS_PU_Cleanup();
        log.info("IVS_PU_Cleanup {}!", res ? "Success" : "Fail");
        return res;
    }

    @Override
    public boolean init() {
        log.info("IVS_PU_InitEx 开始初始化SDK资源");
        //设置CA证书资源
        HWPuSDK.PU_CERT_FILE_PATH_PARA_S.ByReference certFilePath = new HWPuSDK.PU_CERT_FILE_PATH_PARA_S.ByReference();
        try {
            //分配直接内存
            ByteBuffer szCACertFilePathBuffer = ByteBuffer.allocate(HWPuSDK.PU_CERT_FILE_PATH_MAX);
            ByteBuffer szCertFilePathBuffer = ByteBuffer.allocate(HWPuSDK.PU_CERT_FILE_PATH_MAX);
            ByteBuffer szKeyFilePathPathBuffer = ByteBuffer.allocate(HWPuSDK.PU_CERT_FILE_PATH_MAX);
            ByteBuffer szKeyPasswdBuffer = ByteBuffer.allocate(HWPuSDK.PU_PASSWORD_LEN + 4);

            //加载证书路径
            String szCACertFilePath = HWPuSDKResourceConfig.getCAPath(HWPuSDKResourceConfig.CertificateType.CERT_CA_CERT);
            String szCertFilePath = HWPuSDKResourceConfig.getCAPath(HWPuSDKResourceConfig.CertificateType.CERT_CERT);
            String szKeyFilePath = HWPuSDKResourceConfig.getCAPath(HWPuSDKResourceConfig.CertificateType.CERT_KEY);

            //读入内存
            szCACertFilePathBuffer.put(szCACertFilePath.getBytes());
            szCertFilePathBuffer.put(szCertFilePath.getBytes());
            szKeyFilePathPathBuffer.put(szKeyFilePath.getBytes());
            szKeyPasswdBuffer.put(CRYPT.getBytes());

            //赋值
            certFilePath.szCACertFilePath = szCACertFilePathBuffer.array();
            certFilePath.szCertFilePath = szCertFilePathBuffer.array();
            certFilePath.szKeyFilePath = szKeyFilePathPathBuffer.array();
            certFilePath.szKeyPasswd = szKeyPasswdBuffer.array();
        } catch (Exception e) {
            e.printStackTrace();
            log.error(e.getMessage());
        }
        boolean rlt = hwPuSDKInstance.IVS_PU_InitEx(new WinDef.ULONG(LinkModel.MANUAL_LINK.getModel()), null,
                null, new WinDef.ULONG(Local_SSL_Port), certFilePath);
        log.info("IVS_PU_InitEx 初始化SDK{}!", rlt ? "成功！" : "失败！");
        if (!rlt) {
            showErrMsg();
        }
        return rlt;
    }


    /**
     * 使用默认参数登陆摄像机
     *
     * @param chDeviceIP      摄像机默认IP,默认192.168.0.120
     * @param lDevicePort     摄像机默认打开的端口,默认6060
     * @param chLoginUserName 默认登陆用户名,默认admin
     * @param chLoginPwd      默认登陆密码，默认HuaWei123
     * @return 用户ID
     */
    public long login(String chDeviceIP, Integer lDevicePort, String chLoginUserName, String chLoginPwd) {
        if (chDeviceIP == null || "".equals(chDeviceIP)) {
            chDeviceIP =DEFAULT_DEVICE_IP;
        }
        if (lDevicePort == null || lDevicePort <= 0) {
            lDevicePort = DEFAULT_DEVICE_PORT;
        }
        if (chLoginUserName == null || "".equals(chLoginUserName)) {
            chLoginUserName = DEFAULT_USER_NAME;
        }
        if (chLoginPwd == null || "".equals(chLoginPwd)) {
            chLoginPwd = DEFAULT_USER_PASSWORD;
        }
        log.debug("IVS_PU_Login 登陆摄像机[ip={}]", chDeviceIP);
        log.debug("IVS_PU_Login 登陆摄像机[port={}]", lDevicePort);
        log.debug("IVS_PU_Login 登陆摄像机[username={}]", chLoginUserName);
        log.debug("IVS_PU_Login 登陆摄像机[password={}]", chLoginPwd);
        long userLogInID = HWPuSDK.INSTANCE.IVS_PU_Login(chDeviceIP, new WinDef.ULONG(lDevicePort), chLoginUserName, chLoginPwd);
        if (userLogInID >= 1) {
            CAMERAS_LOGIN_MAP.put(chDeviceIP, userLogInID);
        } else {
            showErrMsg();
        }
        log.debug("IVS_PU_Login 用户{}登陆{}", chLoginUserName, userLogInID >= 1 ? "成功!" : "失败!");
        return userLogInID;
    }

    @Override
    public boolean logout(String chDeviceIP) {
        Long userLogInID = CAMERAS_LOGIN_MAP.get(chDeviceIP);
        if (userLogInID == null || userLogInID <= 0) {
            log.error("IVS_PU_Logout 退出异常，用户未登陆");
            return false;
        }
        boolean logOutRes = HWPuSDK.INSTANCE.IVS_PU_Logout(new WinDef.ULONG(userLogInID));
        if (!logOutRes) {
            log.error("IVS_PU_Logout 摄像机退出登陆失败！");
            showErrMsg();
        } else {
            log.debug("IVS_PU_Logout 摄像机退出登陆成功！");
            CAMERAS_LOGIN_MAP.put(chDeviceIP, -1L);
        }
        return logOutRes;
    }


    @Override
    public long startRealPlay(String chDeviceIP) {
        WinDef.ULONG isPlaying = CAMERA_PLAYING_MAP.get(chDeviceIP);
        if (null != isPlaying) {
            log.error("IVS_PU_RealPlay 摄像机 {} 正在实况播放中请不要重复播放", chDeviceIP);
            return -1;
        }
        long ret = 0L;
        try {
            Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
            //实时播放参数设置
            HWPuSDK.PU_REAL_PLAY_INFO_S.ByReference info = new HWPuSDK.PU_REAL_PLAY_INFO_S.ByReference();
            info.ulChannelId = new WinDef.ULONG(101);
            //这里只需要视频流，不需要视频实时显示，窗口数据设置为null
            info.hPlayWnd = null;
            //选择视频参数
            info.enStreamType = HWPuSDK.PU_STREAM_TYPE_E.PU_VIDEO_MAIN_STREAM;
            info.enVideoType = HWPuSDK.PU_VIDEO_TYPE_E.PU_VIDEO_TYPE_VIDEO;
            info.enProtocolType = HWPuSDK.PU_PROTOCOL_TYPE_E.PU_PROTOCOL_TYPE_TCP;
            info.enMediaCallbackType = HWPuSDK.PU_MEDIA_CALLBACK_TYPE_E.PU_MEDIA_CALLBACK_TYPE_RTP;
            //是否持久播放
            info.bKeepLive = true;

            HWPuSDK.pfRealDataCallBack callBack = (szBuffer, lSize, pUsrData) -> {
                System.out.println(szBuffer + " " + lSize + " " + pUsrData);
                return null;
            };
            Pointer usrData = new Pointer(0);
            WinDef.ULONG winDef = HWPuSDK.INSTANCE.IVS_PU_RealPlay(new WinDef.ULONG(uid), info, callBack, usrData);
            long winDefId = winDef.longValue();
            if (0 != winDefId) {
                CAMERA_PLAYING_MAP.put(chDeviceIP, winDef);
                log.debug("IVS_PU_RealPlay 开启码流回调成功!");
            } else {
                log.error("IVS_PU_RealPlay 开启码流回调失败!");
                showErrMsg();
            }
        } catch (Throwable e) {
            log.error("IVS_PU_RealPlay 开启码流回调失败!");
            showErrMsg();
            e.printStackTrace();
        }

        return ret;
    }

    @Override
    public boolean stopRealPlay(String chDeviceIP) {
        WinDef.ULONG ulRealPlayHnd = CAMERA_PLAYING_MAP.get(chDeviceIP);
        if (ulRealPlayHnd == null) {
            log.error("IVS_PU_StopRealPlay 停止码流回调失败，原因是码流未开始");
            return false;
        }
        try {
            Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
            boolean res = HWPuSDK.INSTANCE.IVS_PU_StopRealPlay(new WinDef.ULONG(uid), ulRealPlayHnd);
            if (res) {
                CAMERA_PLAYING_MAP.put(chDeviceIP, null);
                log.debug("IVS_PU_StopRealPlay 停止码流回调成功![DeviceIP={}]", chDeviceIP);
            } else {
                log.error("IVS_PU_StopRealPlay 停止码流回调失败![DeviceIP={}]", chDeviceIP);
                showErrMsg();
            }
            return res;
        } catch (Exception e) {
            showErrMsg();
            log.error("IVS_PU_StopRealPlay 停止码流回调失败![DeviceIP={}]", chDeviceIP);
            e.printStackTrace();
        }
        return false;
    }

    @Override
    public boolean stopAllRealPlay(String chDeviceIP) {
        boolean res = false;
        try {
            Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
            if (uid == null || uid <= 0) {
                log.error("IVS_PU_StopAllRealPlay 停止码流回调失败");
                return false;
            }
            res = HWPuSDK.INSTANCE.IVS_PU_StopAllRealPlay(new WinDef.ULONG(uid));
            if (res) {
                log.debug("IVS_PU_StopAllRealPlay 停止码流回调成功![DeviceIP={}]", chDeviceIP);
            } else {
                log.error("IVS_PU_StopAllRealPlay 停止码流回调失败![DeviceIP={}]", chDeviceIP);
                showErrMsg();
            }
        } catch (Throwable e) {
            log.error("IVS_PU_StopAllRealPlay 停止码流回调失败![DeviceIP={}]", chDeviceIP);
            e.printStackTrace();
        }

        return res;
    }

    @Override
    public boolean changeAdminPassword(String oldPassword, String newPassword) {
        return false;
    }

    @Override
    public CameraModel getDeviceInfo(String chDeviceIP) {
        log.debug("IVS_PU_GetDeviceInfo 获取摄像机 {} 信息", chDeviceIP);
        HWPuSDK.LPPU_DEVICEINFO_S deviceInfo = new HWPuSDK.LPPU_DEVICEINFO_S();
        Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
        if (null == uid || uid <= 0) {
            log.debug("IVS_PU_GetDeviceInfo 获取摄像机 {} 信息失败", chDeviceIP);
            showErrMsg();
            return null;
        }

        try {
            boolean res = hwPuSDKInstance.IVS_PU_GetDeviceInfo(new NativeLong(uid), deviceInfo);
            if (!res) {
                showErrMsg();
                return null;
            }
        } catch (Exception e) {
            e.printStackTrace();
            log.debug("IVS_PU_GetDeviceInfo 获取摄像机 {} 信息失败", chDeviceIP);
            return null;
        }
        //设备软件版本信息
        HWPuSDK.PU_DEVICE_VERSION stDeviceVersion = deviceInfo.stDeviceVersion;
        //设备内核版本
        byte[] szVerKernel = stDeviceVersion.szVerKernel;
        String deviceKernelVersion = CommonUtils.byteToString(szVerKernel);
        log.debug("IVS_PU_GetDeviceInfo 内核版本：" + deviceKernelVersion);
        //设备物理地址
        //前24个字节是摄像机的MAC地址
        String szHardAddress = CommonUtils.byteToString(Arrays.copyOf(stDeviceVersion.szReserved, 24));
        log.debug("物理地址：" + szHardAddress);
        //设备SDC版本号
        String szVerSoftware = CommonUtils.byteToString(stDeviceVersion.szVerSoftware);
        log.debug("IVS_PU_GetDeviceInfo SDC版本号：" + szVerSoftware);
        //设备型号
        String szDeviceModel = CommonUtils.byteToString(deviceInfo.szDeviceType);
        log.debug("IVS_PU_GetDeviceInfo 设备型号：" + szDeviceModel);

        CameraModel cameraModel = new CameraModel();
        cameraModel.setDeviceStatus("1");
        cameraModel.setModel(szDeviceModel);
        cameraModel.setMacAddress(szHardAddress);
        cameraModel.setSdcVersion(szVerSoftware);
        log.debug("IVS_PU_GetDeviceInfo 获取摄像机 {} 信息成功", chDeviceIP);
        return cameraModel;
    }

    @Override
    public boolean saveRealTimeData() {
        return false;
    }

    @Override
    public boolean savePicture() {
        return false;
    }
}
