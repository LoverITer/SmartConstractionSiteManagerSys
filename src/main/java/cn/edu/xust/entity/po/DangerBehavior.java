package cn.edu.xust.entity.po;

import java.util.Date;

import io.swagger.annotations.ApiModel;

@ApiModel(value = "DangerBehavior", description = "危险行为记录实体类，此对象用于个数据库交互")
public class DangerBehavior {

	/**
	 * 主键ID
	 */
	private Integer id;

	/**
	 * 危险行为抓拍图片（URL地址）
	 */
	private String behaviorPic;

	/**
	 * 危险行为对应编号
	 */
	private Integer behaviorType;

	/**
	 * 行为发生时间
	 */
	private Date createTime;

	/**
	 * 行为发生的区域
	 */
	private Integer regionId;

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getBehaviorPic() {
		return behaviorPic;
	}

	public void setBehaviorPic(String behaviorPic) {
		this.behaviorPic = behaviorPic == null ? null : behaviorPic.trim();
	}

	public Integer getBehaviorType() {
		return behaviorType;
	}

	public void setBehaviorType(Integer behaviorType) {
		this.behaviorType = behaviorType;
	}

	public Date getCreateTime() {
		return createTime;
	}

	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	}

	public Integer getRegionId() {
		return regionId;
	}

	public void setRegionId(Integer regionId) {
		this.regionId = regionId;
	}
}