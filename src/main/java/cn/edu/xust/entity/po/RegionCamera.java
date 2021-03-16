package cn.edu.xust.entity.po;

import io.swagger.annotations.ApiModel;

@ApiModel(value = "RegionCamera", description = "区域相机实体类，此对象用于个数据库交互")
public class RegionCamera {

	/**
	 * 主键ID
	 */
	private Integer id;

	/**
	 * 相机ID
	 */
	private Integer cameraId;

	/**
	 * 区域ID
	 */
	private Integer regionId;

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public Integer getCameraId() {
		return cameraId;
	}

	public void setCameraId(Integer cameraId) {
		this.cameraId = cameraId;
	}

	public Integer getRegionId() {
		return regionId;
	}

	public void setRegionId(Integer regionId) {
		this.regionId = regionId;
	}
}