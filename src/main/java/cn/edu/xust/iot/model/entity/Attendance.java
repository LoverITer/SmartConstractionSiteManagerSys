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

	/**
	 * 是否迟到
	 */
	private String late;

}