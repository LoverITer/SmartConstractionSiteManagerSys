package cn.edu.xust.entity.po;

import io.swagger.annotations.ApiModel;

@ApiModel(value = "Region", description = "区域实体类，此对象用于个数据库交互")
public class Region {

	/**
	 * 区域ID
	 */
	private Integer id;

	/**
	 * 区域名（编号）
	 */
	private String regionName;

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getRegionName() {
		return regionName;
	}

	public void setRegionName(String regionName) {
		this.regionName = regionName == null ? null : regionName.trim();
	}
}