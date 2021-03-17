package cn.edu.xust.entity.po;

import java.io.Serializable;
import java.util.Date;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel(value = "User", description = "人员信息实体类，此对象用于个数据库交互")
public class SUser implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = -8832318117479487915L;

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
	private Integer age;

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