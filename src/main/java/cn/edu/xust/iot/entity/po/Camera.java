package cn.edu.xust.iot.entity.po;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;

/**
 *
 * @author Administrator
 *
 */
@Getter
@Setter
@ToString
@ApiModel(value = "Camera", description = "摄像机设备实体类，此对象用于个数据库交互")
public class Camera implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = -9219693696973011411L;

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

}