package cn.edu.xust.iot.service;

import cn.edu.xust.iot.model.CameraModel;

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
     * @param lDeviceport
     * @param chLoginUserName
     * @param chLoginPwd
     * @return
     */
    long login(String chDeviceIP, Integer lDeviceport, String chLoginUserName, String chLoginPwd);

    /**
     * 退出监控摄像机
     *
     * @return
     */
    boolean logout(String chDeviceIP);

    /**
     * 改变SDK用户admin的登录密码。  IVS_PU_ChangeDevicePassword
     *
     * @param oldPassword   旧密码
     * @param newPassword   新密码
     * @return
     */
    boolean changeAdminPassword(String oldPassword, String newPassword);

    /**
     * 开启摄像头实况播放
     *
     * @param chDeviceIP 相机IP
     * @return
     */
    long startRealPlay(String chDeviceIP);

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
     * 保存抓怕的照片  IVS_PU_SavePicture
     *
     * @return
     */
    boolean savePicture();

}
