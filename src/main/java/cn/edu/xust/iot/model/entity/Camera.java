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
public class Camera {

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
		cameraVO.setId(this.getId());
		cameraVO.setDeviceName(this.getDeviceName());
		cameraVO.setUserName(this.getUserName());
		cameraVO.setPassword(this.getPassword());
		cameraVO.setDeviceStatus(this.getDeviceStatus());
		cameraVO.setMacAddress(this.getMacAddress());
		cameraVO.setCreateTime(new SimpleDateFormat("yyyy-MM-ss").format(this.getCreateTime()));
		cameraVO.setIp(this.getIp());
		cameraVO.setPort(this.getPort());
		cameraVO.setModel(this.getModel());
		cameraVO.setAlgorithmName(this.getAlgorithm().equals("0") ?"系统自带算法":"第三方算法");
		cameraVO.setSdcVersion(this.getSdcVersion());
		return cameraVO;
	}

}