package cn.edu.xust.entity.po;

import io.swagger.annotations.ApiModel;

@ApiModel(value = "Danger", description = "危险分类实体类，此对象用于个数据库交互")
public class Danger {

	/**
	 * 危险分类编号
	 */
	private Integer id;

	/**
	 * 危险分类名
	 */
	private String dangerName;

	/**
	 * 危险分类父危险分类编号
	 */
	private String parentDangerName;

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getDangerName() {
		return dangerName;
	}

	public void setDangerName(String dangerName) {
		this.dangerName = dangerName == null ? null : dangerName.trim();
	}

	public String getParentDangerName() {
		return parentDangerName;
	}

	public void setParentDangerName(String parentDangerName) {
		this.parentDangerName = parentDangerName == null ? null : parentDangerName.trim();
	}
}