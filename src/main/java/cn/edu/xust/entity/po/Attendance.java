package cn.edu.xust.entity.po;

import java.util.Date;

import io.swagger.annotations.ApiModel;

/**
 * 实体类 ：Attendance用户考勤
 * 
 * @author Administrator
 *
 */
@ApiModel(value = "Attendance", description = "考勤实体类，此对象用于个数据库交互")
public class Attendance {

	/**
	 * 主键id
	 */
	private Integer id;

	/**
	 * 外键：人员ID
	 */
	private Integer userId;

	/**
	 * 上班打卡时间
	 */
	private Date starkWorkTime;

	/**
	 * 下班打卡时间
	 */
	private Date afterWorkTime;

	/**
	 * 上班打卡机器ID
	 */
	private Integer starkWorkDeviceId;

	/**
	 * 下班打卡机器ID
	 */
	private Integer afterWorkDeviceId;

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public Integer getUserId() {
		return userId;
	}

	public void setUserId(Integer userId) {
		this.userId = userId;
	}

	public Date getStarkWorkTime() {
		return starkWorkTime;
	}

	public void setStarkWorkTime(Date starkWorkTime) {
		this.starkWorkTime = starkWorkTime;
	}

	public Date getAfterWorkTime() {
		return afterWorkTime;
	}

	public void setAfterWorkTime(Date afterWorkTime) {
		this.afterWorkTime = afterWorkTime;
	}

	public Integer getStarkWorkDeviceId() {
		return starkWorkDeviceId;
	}

	public void setStarkWorkDeviceId(Integer starkWorkDeviceId) {
		this.starkWorkDeviceId = starkWorkDeviceId;
	}

	public Integer getAfterWorkDeviceId() {
		return afterWorkDeviceId;
	}

	public void setAfterWorkDeviceId(Integer afterWorkDeviceId) {
		this.afterWorkDeviceId = afterWorkDeviceId;
	}
}