package cn.edu.xust.iot.entity.po;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;

@Getter
@Setter
@ToString
@ApiModel(value = "RegionCamera", description = "区域相机实体类，此对象用于个数据库交互")
public class RegionCamera implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = 7972710474214262193L;

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

}