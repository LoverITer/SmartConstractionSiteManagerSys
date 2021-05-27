package cn.edu.xust.iot.model.entity;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;

@Getter
@Setter
@ToString
public class DangerBehavior{


	/**
	 * 主键ID
	 */
	private Integer id;

	/**
	 * 危险行为抓拍图片（URL地址）
	 */
	private String behaviorPic;

	/**
	 * 危险行为对应编号
	 */
	private Integer behaviorType;

	/**
	 * 行为发生时间
	 */
	private Date createTime;

	/**
	 * 行为发生的区域
	 */
	private Integer regionId;

	//处理状态
	private String state;

	//违规人员身份证
	private String certNo;

}