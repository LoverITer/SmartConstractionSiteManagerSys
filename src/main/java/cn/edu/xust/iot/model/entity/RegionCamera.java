package cn.edu.xust.iot.model.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
public class RegionCamera{


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

	public RegionCamera(Integer cameraId, Integer regionId) {
		this.cameraId = cameraId;
		this.regionId = regionId;
	}
}