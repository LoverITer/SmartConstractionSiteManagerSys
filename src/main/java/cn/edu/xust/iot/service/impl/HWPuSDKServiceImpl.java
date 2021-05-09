package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.sdc.HWPuSDKResourceConfig;
import cn.edu.xust.iot.sdc.core.FaceRecognitionCallbackImpl;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.sdc.core.RegionHumanCountCallBackImpl;
import cn.edu.xust.iot.sdc.core.SnapShotParam;
import cn.edu.xust.iot.sdc.core.constraints.LinkModel;
import cn.edu.xust.iot.sdc.core.constraints.PlayType;
import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.utils.CommonUtils;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;
import com.sun.jna.Memory;
import com.sun.jna.NativeLong;
import com.sun.jna.Platform;
import com.sun.jna.Pointer;
import com.sun.jna.platform.win32.WinDef;
import com.sun.jna.ptr.PointerByReference;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

import static cn.edu.xust.iot.sdc.core.HWPuSDK.IPV4_ADDR_LEN;

/**
 * 华为摄像机服务接口实现
 *
 * @author HuangXin
 * @since 2021/4/18 0:55
 */
@Slf4j
@Service(value = "hwPuSDKService")
public class HWPuSDKServiceImpl implements IHWPuSDKService {

    //SDK实例
    private static final HWPuSDK hwPuSDKInstance = HWPuSDK.INSTANCE;
    //SSL端口
    private static final int Local_SSL_Port = 5051;
    //默认实时播放channel id
    private static final int DEFAULT_CHANNEL_ID = 101;
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
    //保存告警图片的路径
    public static final String DEFAULT_PICTURE_LOCAL_PATH = "D:\\warning_picture\\";
    //文件大小
    private static final int BUFFER_SIZE_1KB = 1024;
    //人脸库名称
    private static final String FACE_LIB_NAME = "智慧工地人员";
    //用户登陆map：key->相机的ip value->登陆后的用户ID
    public static final Map<String, Long> CAMERAS_LOGIN_MAP = new ConcurrentHashMap<>(16);
    //相机是否者在播放视频中：key->相机IP  value->打开实时监控之后返回的句柄，关闭实时监控时需要传入此句柄
    public static final Map<String, WinDef.ULONG> CAMERA_PLAYING_MAP = Collections.synchronizedMap(new HashMap<>(16));
    //相机登陆ID和相机播放句柄之间的映射关系
    public static final Map<Long, WinDef.ULONG> CAMERA_LOGIN_PLAYING_MAP = Collections.synchronizedMap(new LinkedHashMap<>(16));
    //摄像机设备信息map：key->相机IP  value->设备信息
    private static final Map<String, HWPuSDK.LPPU_DEVICEINFO_S> CAMERA_INFO_MAP = new ConcurrentHashMap<>(16);
    //提供给回调接口的用于区分多路相机的参数：设备IP
    private static List<Pointer> pointerArrayList = new ArrayList<>();
    //实时播放回调
    private static final Map<Integer,HWPuSDK.pfRealDataCallBack> REAL_DATA_CALLBACK_MAP=new ConcurrentHashMap<>(16);



    /**
     * 显示错误信息
     */
    public static void showErrMsg() {
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
            chDeviceIP = DEFAULT_DEVICE_IP;
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
        long userLogInID = hwPuSDKInstance.IVS_PU_Login(chDeviceIP, new WinDef.ULONG(lDevicePort), chLoginUserName, chLoginPwd);
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
        boolean logOutRes = hwPuSDKInstance.IVS_PU_Logout(new WinDef.ULONG(userLogInID));
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
    public long startRealPlay(String chDeviceIP,PlayType playType) {
        if(!CommonUtils.isCorrectIp(chDeviceIP)) {
            throw new IllegalArgumentException("非法参数:ip");
        }
        Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
        if (uid <= 0) {
            log.error("IVS_PU_RealPlay 摄像机 {} 还未登陆，请登录后再进行操作", chDeviceIP);
            return -1;
        }
        WinDef.ULONG isPlaying = CAMERA_PLAYING_MAP.get(chDeviceIP);
        if (null != isPlaying) {
            log.error("IVS_PU_RealPlay 摄像机 {} 正在实况播放中请不要重复播放", chDeviceIP);
            return -1;
        }
        long winDefId = 0L;
        try {
            //实时播放参数设置
            HWPuSDK.PU_REAL_PLAY_INFO_S.ByReference realPlayInfo = new HWPuSDK.PU_REAL_PLAY_INFO_S.ByReference();
            realPlayInfo.ulChannelId = new WinDef.ULONG(DEFAULT_CHANNEL_ID);
            //这里只需要视频流，不需要视频实时显示，窗口数据设置为null
            realPlayInfo.hPlayWnd = null;
            //选择视频参数
            realPlayInfo.enStreamType = HWPuSDK.PU_STREAM_TYPE_E.PU_VIDEO_MAIN_STREAM;
            realPlayInfo.enVideoType = HWPuSDK.PU_VIDEO_TYPE_E.PU_VIDEO_TYPE_META;
            realPlayInfo.enProtocolType = HWPuSDK.PU_PROTOCOL_TYPE_E.PU_PROTOCOL_TYPE_TCP;
            //Data will be provide as META Frame
            realPlayInfo.enMediaCallbackType = HWPuSDK.PU_MEDIA_CALLBACK_TYPE_E.PU_MEDIA_CALLBACK_TYPE_META_FRAME;
            //是否开启保活功能
            realPlayInfo.bKeepLive = true;
            realPlayInfo.szReserved[22] = 1;
            realPlayInfo.write();


            HWPuSDK.pfRealDataCallBack callback=REAL_DATA_CALLBACK_MAP.get(playType.getType());
            if(callback==null){
                //如果Map中没有目标PlayType的回调方法就实例化对应的回调并且放到Map中不用多次初始化
                if(PlayType.FACE_RECOGNITION_CALLBACK_IMPL.equals(playType)) {
                    //人脸识别回调
                    callback=new FaceRecognitionCallbackImpl();
                    REAL_DATA_CALLBACK_MAP.put(PlayType.FACE_RECOGNITION_CALLBACK_IMPL.getType(),callback);
                }else if(PlayType.REGION_CROWD_DENSITY_CALLBACK_IMPL.equals(playType)){
                    //区域人数检测
                    callback=new RegionHumanCountCallBackImpl();
                    REAL_DATA_CALLBACK_MAP.put(PlayType.REGION_CROWD_DENSITY_CALLBACK_IMPL.getType(),callback);
                }
            }

            Pointer usrData = new Memory(IPV4_ADDR_LEN +1);
            usrData.setString(0, chDeviceIP);
            WinDef.ULONG winDef = hwPuSDKInstance.IVS_PU_RealPlay(new WinDef.ULONG(uid), realPlayInfo, callback, usrData);
            winDefId = winDef.longValue();
            if (0 != winDefId) {
                CAMERA_PLAYING_MAP.put(chDeviceIP, winDef);
                log.debug("IVS_PU_RealPlay 开启码流回调成功!句柄ID：{}", winDefId);
            } else {
                log.error("IVS_PU_RealPlay 开启码流回调失败!");
                showErrMsg();
            }
        } catch (Throwable e) {
            log.error("IVS_PU_RealPlay 开启码流回调失败!");
            showErrMsg();
            e.printStackTrace();
        }

        return winDefId;
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
            //停止实时播放并且停止执行回调函数
            boolean res = hwPuSDKInstance.IVS_PU_StopRealPlay(new WinDef.ULONG(uid), ulRealPlayHnd);
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
            log.error("IVS_PU_StopRealPlay 停止码流回调发生异常![DeviceIP={}]", chDeviceIP);
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
                log.error("IVS_PU_StopAllRealPlay 停止所有码流回调失败，用户未登陆");
                return false;
            }
            res = HWPuSDK.INSTANCE.IVS_PU_StopAllRealPlay(new WinDef.ULONG(uid));
            if (res) {
                log.debug("IVS_PU_StopAllRealPlay 停止所有码流回调成功![DeviceIP={}]", chDeviceIP);
            } else {
                log.error("IVS_PU_StopAllRealPlay 停止所有码流回调失败![DeviceIP={}]", chDeviceIP);
                showErrMsg();
            }
        } catch (Throwable e) {
            log.error("IVS_PU_StopAllRealPlay 停止所有码流回调发生异常![DeviceIP={}]", chDeviceIP);
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
        Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
        if (null == uid || uid <= 0) {
            log.debug("IVS_PU_GetDeviceInfo 获取摄像机 {} 信息失败", chDeviceIP);
            showErrMsg();
            return null;
        }
        HWPuSDK.LPPU_DEVICEINFO_S deviceInfo;
        if ((deviceInfo = CAMERA_INFO_MAP.get(chDeviceIP)) == null) {
            try {
                deviceInfo = new HWPuSDK.LPPU_DEVICEINFO_S();
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
            CAMERA_INFO_MAP.put(chDeviceIP, deviceInfo);
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
    public boolean getMetaData(Pointer pFBuffer, WinDef.ULONG ulFBLength, int eLayTwo, PointerByReference pstMetaData) {
        boolean isOK = false;
        try {
            if (null == pFBuffer || null == pstMetaData) {
                return false;
            }

            isOK = hwPuSDKInstance.IVS_User_GetMetaData(pFBuffer, ulFBLength, eLayTwo, pstMetaData);
            if (!isOK) {
                log.error("IVS_User_GetMetaData 获取元数据失败");
                showErrMsg();
            } else {
                log.info("IVS_User_GetMetaData 获取元数据成功!");
            }
        } catch (Throwable e) {
            log.error("IVS_User_GetMetaData 获取元数据发生异常:{}", e.getMessage());
            e.printStackTrace();
        }

        return isOK;
    }

    @Override
    public boolean freeMetaData(PointerByReference pstMetaData) {
        boolean isOK = false;
        try {
            if (null == pstMetaData) {
                throw new NullPointerException("param pstMetaData cannot be null");
            }

            isOK = hwPuSDKInstance.IVS_User_FreeMetaData(pstMetaData);
            log.debug("IVS_User_FreeMetaData 释放元数据{}!", isOK ? "成功" : "失败");
            if (!isOK) {
                showErrMsg();
            }
        } catch (Throwable e) {
            log.error("IVS_User_FreeMetaData 释放元数据发生异常：{}", e.getMessage());
            e.printStackTrace();
        }

        return isOK;
    }

    @Override
    public boolean savePicture(String chDeviceIP) {
        log.debug("IVS_PU_SavePicture 开始保存摄像机 {} 抓拍图片", chDeviceIP);
        Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
        if (null == uid || uid <= 0) {
            log.debug("IVS_PU_SavePicture 保存摄像机 {} 抓拍图片失败", chDeviceIP);
            showErrMsg();
            return false;
        }
        WinDef.ULONG playingHandle = CAMERA_PLAYING_MAP.get(chDeviceIP);
        if (playingHandle == null) {
            log.debug("IVS_PU_SavePicture 保存摄像机 {} 抓拍图片失败,请先开启实时视屏监控", chDeviceIP);
            return false;
        }
        //设置图片保存参数
        HWPuSDK.PU_SAVE_PICTURE_INFO pictureInfo = new HWPuSDK.PU_SAVE_PICTURE_INFO();
        pictureInfo.enSavePicType = HWPuSDK.PU_SAVE_PICTURE_TYPE.PU_SAVE_PICTURE_TYPE_JEPG;
        String fileName = DEFAULT_PICTURE_LOCAL_PATH + CommonUtils.getRandomString() + ".jpg";
        File file = new File(fileName);
        if (!file.getParentFile().exists()) {
            file.getParentFile().mkdirs();
        }
        pictureInfo.szFilePath = fileName.getBytes();
        boolean isOk = hwPuSDKInstance.IVS_PU_SavePicture(new WinDef.ULONG(uid), playingHandle, pictureInfo);
        if (!isOk) {
            log.debug("IVS_PU_SavePicture 保存摄像机 {} 抓拍图片失败", chDeviceIP);
            showErrMsg();
        }
        return isOk;
    }


    @Override
    public boolean getAlarmParam(String chDeviceIP) {
        log.debug("IVS_PU_GetAlarmPara 获取摄像机 {} 信息", chDeviceIP);
        Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
        if (null == uid || uid <= 0) {
            log.debug("IVS_PU_GetAlarmPara 获取摄像机 {} 信息失败", chDeviceIP);
            showErrMsg();
            return false;
        }
        //设置人头计数参数
        Pointer pointer = new Pointer(0);
        HWPuSDK.PU_HUMANCOUNT_PARAM_S headCountParam = new HWPuSDK.PU_HUMANCOUNT_PARAM_S();
        headCountParam.ulChannelId = new WinDef.ULONG(DEFAULT_CHANNEL_ID);
        HWPuSDK.PU_HUMANCOUNT_ALG_PARAM_S algParams = new HWPuSDK.PU_HUMANCOUNT_ALG_PARAM_S();
        algParams.enHCEnable = new WinDef.BOOL(true);
        algParams.enCleaAtZero = new WinDef.BOOL(true);
        algParams.enOSDEnable = new WinDef.BOOL(true);
        HWPuSDK.PU_POINT_S OSDLocation = new HWPuSDK.PU_POINT_S();
        OSDLocation.usPosX = new WinDef.USHORT(255);
        OSDLocation.usPosY = new WinDef.USHORT(255);
        algParams.stOSDLocation = OSDLocation;
        headCountParam.stAlgParams = algParams;
        headCountParam.stGuardAreaList = null;
        headCountParam.stHCGuardPlan = null;
        hwPuSDKInstance.IVS_PU_GetAlarmPara(new WinDef.ULONG(uid), HWPuSDK.PU_ALARM_TYPE.PU_ALARM_TYPE_HUMAN_COUNT,
                headCountParam.getPointer());
        return false;
    }


    @Override
    public boolean addFace(String chDeviceIP, HWPuSDK.PU_FACE_RECORD_S.ByValue faceRecord) throws IOException {
        Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
        if (null == uid || uid <= 0) {
            log.debug("IVS_PU_GetAlarmPara 获取摄像机 {} 信息失败", chDeviceIP);
            showErrMsg();
            return false;
        }
        HWPuSDK.PU_FACE_LIB_GET_S puFaceLib = new HWPuSDK.PU_FACE_LIB_GET_S();
        puFaceLib.ulChannelId = new WinDef.ULONG(DEFAULT_CHANNEL_ID);
        if (Platform.isWindows()) {
            File file = new File("C://face_lib//face.json");
            if (!file.exists()) {
                file.getParentFile().mkdirs();
            }
            puFaceLib.szFindResultPath = "C://face_lib//face.json".getBytes();
        } else if (Platform.isLinux()) {
            File file = new File("/home/face_lib/face.json");
            if (!file.exists()) {
                file.getParentFile().mkdirs();
            }
            puFaceLib.szFindResultPath = "/home/face_lib/face.json".getBytes();
        }
        boolean isOK = hwPuSDKInstance.IVS_PU_GetFaceLib(new WinDef.ULONG(uid), puFaceLib);
        log.debug("IVS_PU_GetFaceLib 获取摄像机人脸库{}！", isOK ? "成功" : "失败");
        if (!isOK) {
            showErrMsg();
            throw new RuntimeException("获取摄像机" + chDeviceIP + "人脸库失败");
        }
        //获取写入本地磁盘的JSON格式数据
        String jsonResultPath = CommonUtils.byteToString(puFaceLib.szFindResultPath);
        StringBuilder jsonResult = new StringBuilder();
        File file = new File(jsonResultPath);
        FileInputStream fis = new FileInputStream(file);
        byte[] bytes = new byte[BUFFER_SIZE_1KB];
        int len = 0;
        while ((len = fis.read(bytes)) != -1) {
            jsonResult.append(new String(bytes, 0, len));
        }
        JSONObject jsonObject = JSON.parseObject(jsonResult.toString());
        JSONArray faceListsArray = jsonObject.getJSONArray("FaceListsArry");
        JSONObject faceLibJsonObj = null;
        if (faceListsArray != null && (len = faceListsArray.size()) > 0) {
            for (int i = 0; i < len; i++) {
                faceLibJsonObj = faceListsArray.getJSONObject(i);
                if (null != faceLibJsonObj.get("FaceListName") && FACE_LIB_NAME.equals(faceLibJsonObj.get("FaceListName"))) {
                    break;
                }
            }
        }
        if (faceLibJsonObj == null) {
            throw new NullPointerException("没有找到人脸库[" + FACE_LIB_NAME + "]");
        }

        /*
         *  public ULONG ulChannelId;// Channel ID.
         *  public PU_FACE_LIB_S.ByValue stFacelib;// Face list.
         *  public PU_FACE_RECORD_S.ByValue stRecord;// Information.
         */
        HWPuSDK.PU_FACE_INFO_ADD_S faceInfo = new HWPuSDK.PU_FACE_INFO_ADD_S();
        faceInfo.ulChannelId = new WinDef.ULONG(DEFAULT_CHANNEL_ID);
        HWPuSDK.PU_FACE_LIB_S.ByValue faceLib = new HWPuSDK.PU_FACE_LIB_S.ByValue();
        faceLib.ulFaceLibID = new WinDef.ULONG((long) faceLibJsonObj.get("ID"));
        faceLib.szLibName = faceLibJsonObj.get("FaceListName").toString().getBytes();
        faceLib.enLibType = HWPuSDK.PU_FACE_LIB_TYPE_E.FACE_LIB_WHITE;
        faceLib.isControl = (int) faceLibJsonObj.get("OnControl");
        faceLib.uiThreshold = new WinDef.ULONG((long) faceLibJsonObj.get("Threshold"));
        faceInfo.stFacelib = faceLib;
        faceInfo.stRecord = faceRecord;
        boolean saveOk = hwPuSDKInstance.IVS_PU_AddOneFace(new WinDef.ULONG(uid), faceInfo);
        if (!saveOk) {
            showErrMsg();
        }
        return saveOk;
    }

    /**
     * 设置获取区域人群密度参数
     *
     * @return
     */
    @Override
    public boolean setCrowdDensityParam(String chDeviceIP, String regionName) {
        Long uid = CAMERAS_LOGIN_MAP.get(chDeviceIP);
        if (null == uid || uid <= 0) {
            log.debug("IVS_PU_SetAlarmPara 获取摄像机 {} 信息失败", chDeviceIP);
            showErrMsg();
            return false;
        }
        //人群密度采集结构体
        HWPuSDK.PU_ITGT_CROWD_DENSITY_DETECT_PARAM_S crowdDensityDetectParam = new HWPuSDK.PU_ITGT_CROWD_DENSITY_DETECT_PARAM_S();

        //人群密度算法参数设置
        HWPuSDK.PU_ITGT_CROWD_DENSITY_DETECT_ALG_PARAM_S crowdDensityDetectAlgParams = new HWPuSDK.PU_ITGT_CROWD_DENSITY_DETECT_ALG_PARAM_S();
        //算法使能
        crowdDensityDetectAlgParams.enEnable = HWPuSDK.PU_ENABLE_TYPE_E.PU_ENABLE_TRUE;
        //人数上限阈值
        crowdDensityDetectAlgParams.fPeopleNumThreshold = new WinDef.ULONG(1);
        //告警上报间隔
        crowdDensityDetectAlgParams.ulAlarmTime = new WinDef.ULONG(500);
        //检测阈值(1-5)
        crowdDensityDetectAlgParams.ulSensitivity = new WinDef.ULONG(1);

        //人群密度检测区域设置
        HWPuSDK.PU_IGT_AERADTC_LIST areaList = new HWPuSDK.PU_IGT_AERADTC_LIST();
        //区域数量
        areaList.ulAreaNum = new WinDef.ULONG(1);
        //区域信息设置
        HWPuSDK.PU_IGT_AREA_S area = new HWPuSDK.PU_IGT_AREA_S();

        //区域使能
        area.bEnable = new WinDef.BOOL(true);
        //区域多边形定点数目
        area.uPointNum = new WinDef.UINT(4);
        area.szAreaName = regionName.getBytes();
        area.ulAreaIndex = new WinDef.ULONG(1);
        //区域点坐标
        area.stPoint[0] = new HWPuSDK.PU_IGT_POINT_S((short) 0, (short) 0);
        area.stPoint[1] = new HWPuSDK.PU_IGT_POINT_S((short) 352, (short) 0);
        area.stPoint[2] = new HWPuSDK.PU_IGT_POINT_S((short) 0, (short) 288);
        area.stPoint[3] = new HWPuSDK.PU_IGT_POINT_S((short) 352, (short) 288);
        area.stLocation = null;
        //设置区域信息
        areaList.stArea[0] = area;

        //布放计划设置
        HWPuSDK.PU_ALARM_TIME_LIST_S alarmTimeList = new HWPuSDK.PU_ALARM_TIME_LIST_S();
        HWPuSDK.PU_ALARM_TIME_S alarmTime = new HWPuSDK.PU_ALARM_TIME_S();
        alarmTime.ulCycleType = new NativeLong(1);
        alarmTime.ulPeriod = new NativeLong(0);
        //布放开始时间
        HWPuSDK.PU_TIME_S.ByValue startTime = new HWPuSDK.PU_TIME_S.ByValue();
        Calendar calendar = Calendar.getInstance();
        startTime.szYear = String.valueOf(calendar.get(Calendar.YEAR)).getBytes();
        startTime.szMonth = String.valueOf(calendar.get(Calendar.MONTH)).getBytes();
        startTime.szDay = String.valueOf(calendar.get(Calendar.DATE)).getBytes();
        startTime.szHour = String.valueOf(calendar.get(Calendar.HOUR)).getBytes();
        startTime.szMinute = String.valueOf(calendar.get(Calendar.MINUTE)).getBytes();
        startTime.szSecond = String.valueOf(calendar.get(Calendar.SECOND)).getBytes();
        //布放结束时间
        HWPuSDK.PU_TIME_S.ByValue endTime = new HWPuSDK.PU_TIME_S.ByValue();
        endTime.szYear = String.valueOf(calendar.get(Calendar.YEAR)).getBytes();
        endTime.szMonth = String.valueOf(calendar.get(Calendar.MONTH)).getBytes();
        endTime.szDay = String.valueOf(calendar.get(Calendar.DATE)).getBytes();
        endTime.szHour = String.valueOf(calendar.get(Calendar.HOUR)).getBytes();
        endTime.szMinute = String.valueOf(calendar.get(Calendar.MINUTE)).getBytes();
        endTime.szSecond = String.valueOf(calendar.get(Calendar.SECOND)).getBytes();
        alarmTime.stStart = startTime;
        alarmTime.stEnd = endTime;
        //布放计划时间个数
        alarmTimeList.ulNum = new WinDef.ULONG(1);
        //设置布放时间
        alarmTimeList.stAlarmTime[0] = alarmTime;

        crowdDensityDetectParam.ulChannelID = new WinDef.ULONG(DEFAULT_CHANNEL_ID);
        crowdDensityDetectParam.stAlgParams = crowdDensityDetectAlgParams;
        crowdDensityDetectParam.stAreaList = areaList;
        crowdDensityDetectParam.stGuardPlan = alarmTimeList;

        //IVS_PU_SetAlarmPara(ULONG ulIdentifyID, int enAlarmType, Pointer arg)
        boolean isOk = hwPuSDKInstance.IVS_PU_SetAlarmPara(new WinDef.ULONG(uid), HWPuSDK.PU_ALARM_TYPE.PU_ALARM_TYPE_CROWD_DENSITY_DETECT, crowdDensityDetectParam.getPointer());
        if (!isOk) {
            showErrMsg();
        }
        return isOk;
    }

    @Override
    public boolean startSnapShot(String chDeviceIp, String channelId, SnapShotParam snapShotParam) {
        return false;
    }

    @Override
    public boolean setAlarmParam(String chDeviceIp) {
        return false;
    }


    @Override
    public boolean getIntelligentAlgorithmInfo(String chDeviceIp) {
        return false;
    }

    @Override
    public boolean getAreaAlarmInfo(String chDeviceIp) {
        return false;
    }

    @Override
    public boolean setAreaAlarmInfo(String chDeviceIp) {
        return false;
    }

    @Override
    public boolean getHumanCountTable(String chDeviceIp) {
        return false;
    }

    @Override
    public boolean clearHumanCountTable(String chDeviceIp) {
        return false;
    }
}
