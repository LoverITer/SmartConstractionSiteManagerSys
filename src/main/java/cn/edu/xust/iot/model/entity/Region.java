package cn.edu.xust.iot.model.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
public class Region {


	/**
	 * 区域ID
	 */
	private Integer id;

	/**
	 * 区域名（编号）
	 */
	private String regionName;

	public Region(String regionName) {
		this.regionName = regionName;
	}
}