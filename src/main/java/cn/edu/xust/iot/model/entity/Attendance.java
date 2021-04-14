package cn.edu.xust.iot.model.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;

/**
 * 实体类 ：Attendance用户考勤
 *
 * @author Administrator
 *
 */
@Getter
@Setter
@ToString
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

	public Integer getAfterWorkDeviceId() {
		return afterWorkDeviceId;
	}

	public Date getAfterWorkTime() {
		return afterWorkTime;
	}

	public Integer getId() {
		return id;
	}

	public Integer getStarkWorkDeviceId() {
		return starkWorkDeviceId;
	}

	public Date getStarkWorkTime() {
		return starkWorkTime;
	}

	public Integer getUserId() {
		return userId;
	}

	public void setAfterWorkDeviceId(Integer afterWorkDeviceId) {
		this.afterWorkDeviceId = afterWorkDeviceId;
	}

	public void setAfterWorkTime(Date afterWorkTime) {
		this.afterWorkTime = afterWorkTime;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public void setStarkWorkDeviceId(Integer starkWorkDeviceId) {
		this.starkWorkDeviceId = starkWorkDeviceId;
	}

	public void setStarkWorkTime(Date starkWorkTime) {
		this.starkWorkTime = starkWorkTime;
	}

	public void setUserId(Integer userId) {
		this.userId = userId;
	}
}