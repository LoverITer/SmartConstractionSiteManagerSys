package cn.edu.xust.iot.model.entity;

import cn.edu.xust.iot.model.vo.CameraVO;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * @author Administrator
 */
@Getter
@Setter
@ToString
public class Camera implements Cloneable{

    /**
     * 摄像机ID
     */
    private Integer id;

    /**
     * 摄像机设别名称，预留
     */
    private String deviceName;

    /**
     * 摄像机状态
     */
    private String deviceStatus;

    /**
     * 摄像机安装区域
     */
    private Integer regionId;

    /**
     * 摄像机所使用的的算法
     */
    private String algorithm;

    /**
     * 摄像机内网ip
     */
    private String ip;

    /**
     * 摄像机使用的端口
     */
    private Integer port;

    /**
     * 摄像机用户名
     */
    private String userName;

    /**
     * 摄像机密码
     */
    private String password;

    /**
     * 摄像机型号
     */
    private String model;

    /**
     * 摄像机MAC地址
     */
    private String macAddress;

    /**
     * 摄像机SDC版本
     */
    private String sdcVersion;

    /**
     * 创建日期
     */
    private Date createTime;

    /**
     * 将Camera对象转换成CameraVO对象
     *
     * @return
     */
    public CameraVO conventCamera2CameraVO() {
        CameraVO cameraVO = new CameraVO();
        cameraVO.setRegionName("未知");
        cameraVO.setId(this.getId());
        cameraVO.setDeviceName(this.getDeviceName());
        cameraVO.setUserName(this.getUserName());
        cameraVO.setPassword(this.getPassword());
        cameraVO.setDeviceStatus(this.getDeviceStatus());
        cameraVO.setMacAddress(this.getMacAddress());
        cameraVO.setCreateTime(new SimpleDateFormat("yyyy-MM-dd").format(this.getCreateTime()));
        cameraVO.setIp(this.getIp());
        cameraVO.setPort(this.getPort());
        cameraVO.setModel(this.getModel());
        cameraVO.setAlgorithmName(this.getAlgorithm().equals("0") ? "系统自带算法" : "第三方算法");
        cameraVO.setSdcVersion(this.getSdcVersion());
        return cameraVO;
    }


    /**
     * 比较两个相机是否是同一个设备
     *
     * @param obj
     * @return
     */
    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj instanceof Camera) {
            Camera camera = (Camera) obj;
            if (!this.deviceName.equals(camera.getDeviceName())) {
                return false;
            }
            if (!this.regionId.equals(camera.getRegionId())) {
                return false;
            }
            if (!this.userName.equals(camera.getUserName())) {
                return false;
            }
            if (!this.sdcVersion.equals(camera.getSdcVersion())) {
                return false;
            }
            if (!this.port.equals(camera.getPort())) {
                return false;
            }
            if (!this.password.equals(camera.getPassword())) {
                return false;
            }
            if (!this.model.equals(camera.getModel())) {
                return false;
            }
            if (!this.ip.equals(camera.getIp())) {
                return false;
            }
            if (!this.deviceStatus.equals(camera.getDeviceStatus())) {
                return false;
            }
            if (!this.createTime.equals(camera.getCreateTime())) {
                return false;
            }
            if (!this.algorithm.equals(camera.getAlgorithm())) {
                return false;
            }
            return true;
        }
        return false;
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        Camera camera = new Camera();
        camera.setRegionId(this.getRegionId());
        camera.setId(this.getId());
        camera.setDeviceName(this.getDeviceName());
        camera.setUserName(this.getUserName());
        camera.setPassword(this.getPassword());
        camera.setDeviceStatus(this.getDeviceStatus());
        camera.setMacAddress(this.getMacAddress());
        camera.setCreateTime(this.getCreateTime());
        camera.setIp(this.getIp());
        camera.setPort(this.getPort());
        camera.setModel(this.getModel());
        camera.setAlgorithm(this.getAlgorithm());
        camera.setSdcVersion(this.getSdcVersion());
        return camera;
    }
}