package cn.edu.xust.entity.po;

import java.io.Serializable;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel(value = "Region", description = "区域实体类，此对象用于个数据库交互")
public class Region implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = 3658097471071643460L;

	/**
	 * 区域ID
	 */
	private Integer id;

	/**
	 * 区域名（编号）
	 */
	private String regionName;

}