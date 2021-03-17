package cn.edu.xust.entity.po;

import java.io.Serializable;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel(value = "Danger", description = "危险分类实体类，此对象用于个数据库交互")
public class Danger implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = 4067603036182167037L;

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