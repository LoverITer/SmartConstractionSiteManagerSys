package cn.edu.xust.entity.po;

import java.util.Date;

import io.swagger.annotations.ApiModel;

@ApiModel(value = "User", description = "人员信息实体类，此对象用于个数据库交互")
public class SUser {

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

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public Long getFaceLibId() {
		return faceLibId;
	}

	public void setFaceLibId(Long faceLibId) {
		this.faceLibId = faceLibId;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender == null ? null : gender.trim();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name == null ? null : name.trim();
	}

	public Integer getAge() {
		return age;
	}

	public void setAge(Integer age) {
		this.age = age;
	}

	public Date getBirth() {
		return birth;
	}

	public void setBirth(Date birth) {
		this.birth = birth;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address == null ? null : address.trim();
	}

	public String getCertificateType() {
		return certificateType;
	}

	public void setCertificateType(String certificateType) {
		this.certificateType = certificateType == null ? null : certificateType.trim();
	}

	public String getCertificateNo() {
		return certificateNo;
	}

	public void setCertificateNo(String certificateNo) {
		this.certificateNo = certificateNo == null ? null : certificateNo.trim();
	}

	public String getJob() {
		return job;
	}

	public void setJob(String job) {
		this.job = job == null ? null : job.trim();
	}

	public String getIsManager() {
		return isManager;
	}

	public void setIsManager(String isManager) {
		this.isManager = isManager == null ? null : isManager.trim();
	}

	public Date getCreateTime() {
		return createTime;
	}

	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	}

	public String getMemo() {
		return memo;
	}

	public void setMemo(String memo) {
		this.memo = memo == null ? null : memo.trim();
	}
}