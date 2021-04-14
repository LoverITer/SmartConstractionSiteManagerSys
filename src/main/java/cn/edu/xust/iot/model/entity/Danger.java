package cn.edu.xust.iot.model.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
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

}