package cn.edu.xust.iot.model.entity;

import lombok.Data;
import lombok.ToString;

import java.util.Date;

@Data
@ToString
public class SUser  {

	/**
	 * 主键ID
	 */
	private Integer id;

	/**
	 * 外键：人脸库ID
	 */
	private Long faceLibId;

	/**
	 * 性别 0 男性 1女性
	 */
	private String gender;

	/**
	 * 姓名
	 */
	private String name;

	/**
	 * 年龄
	 */
	private String phone;

	/**
	 * 出生日期
	 */
	private Date birth;

	/**
	 * 家庭地址
	 */
	private String address;

	/**
	 * 认证证书
	 */
	private String certificateType;

	/**
	 * 证件号
	 */
	private String certificateNo;

	/**
	 * 职位
	 */
	private String job;

	/**
	 * 是否是管理人员
	 */
	private String isManager;

	/**
	 * 创建时间
	 */
	private Date createTime;

	/**
	 * 备注信息
	 */
	private String memo;
}