package cn.edu.xust.entity.po;

import io.swagger.annotations.ApiModel;

/**
 * 
 * @author Administrator
 *
 */
@ApiModel(value = "Camera", description = "摄像机设备实体类，此对象用于个数据库交互")
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

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getDeviceName() {
		return deviceName;
	}

	public void setDeviceName(String deviceName) {
		this.deviceName = deviceName == null ? null : deviceName.trim();
	}

	public String getDeviceStatus() {
		return deviceStatus;
	}

	public void setDeviceStatus(String deviceStatus) {
		this.deviceStatus = deviceStatus == null ? null : deviceStatus.trim();
	}

	public Integer getRegionId() {
		return regionId;
	}

	public void setRegionId(Integer regionId) {
		this.regionId = regionId;
	}

	public String getAlgorithm() {
		return algorithm;
	}

	public void setAlgorithm(String algorithm) {
		this.algorithm = algorithm == null ? null : algorithm.trim();
	}

	public String getIp() {
		return ip;
	}

	public void setIp(String ip) {
		this.ip = ip == null ? null : ip.trim();
	}

	public Integer getPort() {
		return port;
	}

	public void setPort(Integer port) {
		this.port = port;
	}

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName == null ? null : userName.trim();
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password == null ? null : password.trim();
	}

	public String getModel() {
		return model;
	}

	public void setModel(String model) {
		this.model = model == null ? null : model.trim();
	}

	public String getMacAddress() {
		return macAddress;
	}

	public void setMacAddress(String macAddress) {
		this.macAddress = macAddress == null ? null : macAddress.trim();
	}

	public String getSdcVersion() {
		return sdcVersion;
	}

	public void setSdcVersion(String sdcVersion) {
		this.sdcVersion = sdcVersion == null ? null : sdcVersion.trim();
	}
}