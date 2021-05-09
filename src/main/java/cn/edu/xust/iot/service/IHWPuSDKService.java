package cn.edu.xust.iot.service;

import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.sdc.core.SnapShotParam;
import cn.edu.xust.iot.sdc.core.constraints.PlayType;
import com.sun.jna.Pointer;
import com.sun.jna.platform.win32.WinDef;
import com.sun.jna.ptr.PointerByReference;

import java.io.IOException;

/**
 * 华为摄像机服务接口
 *
 * @author HuangXin
 * @since 2021/4/18 0:54
 */
public interface IHWPuSDKService {


    /**
     * 关闭并清除摄像机SDK
     *
     * @return
     */
    boolean close();

    /**
     * 初始化监控摄像机SDK
     *
     * @return
     */
    boolean init();


    /**
     * 登陆监控摄像机
     *
     * @param chDeviceIP
     * @param lDevicePort
     * @param chLoginUserName
     * @param chLoginPwd
     * @return
     */
    long login(String chDeviceIP, Integer lDevicePort, String chLoginUserName, String chLoginPwd);

    /**
     * 退出监控摄像机
     *
     * @return
     */
    boolean logout(String chDeviceIP);

    /**
     * 改变SDK用户admin的登录密码。  IVS_PU_ChangeDevicePassword
     *
     * @param oldPassword 旧密码
     * @param newPassword 新密码
     * @return
     */
    boolean changeAdminPassword(String oldPassword, String newPassword);

    /**
     * 开启摄像头实况播放
     *
     * @param chDeviceIP 相机IP
     * @return
     */
    long startRealPlay(String chDeviceIP, PlayType playType);


    /**
     * 停止摄像投实况播放
     *
     * @return
     */
    boolean stopRealPlay(String chDeviceIP);

    /**
     * 停止所有实况播放
     *
     * @param chDeviceIP 需要停止播放的摄像机IP
     * @return
     */
    boolean stopAllRealPlay(String chDeviceIP);

    /**
     * 获取设备信息
     *
     * @return
     */
    CameraModel getDeviceInfo(String chDeviceIP);

    /**
     * 保存实时视屏数据到硬盘 IVS_PU_SaveRealData
     *
     * @return
     */
    boolean saveRealTimeData();

    /**
     * 获取元数据  IVS_User_GetMetaData
     *
     * @param pFBuffer
     * @param ulFBLength
     * @param eLayTwo
     * @param pstMetaData
     * @return
     */
    boolean getMetaData(Pointer pFBuffer, WinDef.ULONG ulFBLength, int eLayTwo, PointerByReference pstMetaData);


    /**
     * 释放智能元数据
     *
     * @param pstMetaData
     * @return
     */
    boolean freeMetaData(PointerByReference pstMetaData);


    /**
     * 添加人脸图片 （人脸库名：智慧工地人员）
     *
     * @param chDeviceIP 摄像机IP
     * @param faceRecord 添加的人脸信息 HWPuSDK.PU_FACE_RECORD_S.ByValue
     * @return 添加成功返回 true  添加失败返回 false
     * @throws IOException
     */
    boolean addFace(String chDeviceIP, HWPuSDK.PU_FACE_RECORD_S.ByValue faceRecord) throws IOException;

    /**
     * 设置获取人群密度参数
     *
     * @return
     */
    boolean setCrowdDensityParam(String chDeviceIP,String regionName);

    /**
     * 保存抓怕的照片到本地  IVS_PU_SavePicture
     *
     * @return
     */
    boolean savePicture(String chDeviceIP);

    /**
     * 开始抓拍   IVS_PU_StartSnapShot
     *
     * @return
     */
    boolean startSnapShot(String chDeviceIp, String channelId, SnapShotParam snapShotParam);


    /**
     * 设置告警参数  IVS_PU_SetAlarmPara
     *
     * @return
     */
    boolean setAlarmParam(String chDeviceIp);

    /**
     * 获取告警参数 IVS_PU_GetAlarmPara
     *
     * @return
     */
    boolean getAlarmParam(String chDeviceIp);

    /**
     * 获取智能算法信息 IVS_PU_GetItgtAlthmInfo
     *
     * @return
     */
    boolean getIntelligentAlgorithmInfo(String chDeviceIp);

    /**
     * 获取区域告警信息  IVS_PU_GetIgtAreaDtcAlarmPara
     *
     * @return
     */
    boolean getAreaAlarmInfo(String chDeviceIp);

    /**
     * 设置区域告警参数  IVS_PU_SetIgtAreaDtcAlarmPara
     *
     * @param chDeviceIp
     * @return
     */
    boolean setAreaAlarmInfo(String chDeviceIp);

    /**
     * 获取人头计数报表  用于人员打卡计数
     *
     * @param chDeviceIp IVS_PU_GetHumanCountTable
     * @return
     */
    boolean getHumanCountTable(String chDeviceIp);

    /**
     * 设置清除人头计数
     *
     * @param chDeviceIp
     * @return
     */
    boolean clearHumanCountTable(String chDeviceIp);

}
