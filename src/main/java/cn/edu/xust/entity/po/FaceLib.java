package cn.edu.xust.entity.po;

import java.util.Date;

import io.swagger.annotations.ApiModel;

@ApiModel(value = "FaceLib", description = "人脸库实体类，此对象用于个数据库交互")
public class FaceLib {

	/**
	 * 主键ID
	 */
	private Long id;

	/**
	 * 人脸图片 URL
	 */
	private String facePic;

	/**
	 * 创建时间
	 */
	private Date createTime;

	/**
	 * 备注信息
	 */
	private String memo;

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getFacePic() {
		return facePic;
	}

	public void setFacePic(String facePic) {
		this.facePic = facePic == null ? null : facePic.trim();
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