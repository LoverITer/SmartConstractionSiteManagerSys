package cn.edu.xust.iot.entity.po;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;
import java.util.Date;

@Getter
@Setter
@ToString
@ApiModel(value = "DangerBehavior", description = "危险行为记录实体类，此对象用于个数据库交互")
public class DangerBehavior implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = -6971206228041434455L;

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

}