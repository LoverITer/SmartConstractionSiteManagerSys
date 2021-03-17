package cn.edu.xust.entity.po;

import java.io.Serializable;
import java.util.Date;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel(value = "FaceLib", description = "人脸库实体类，此对象用于个数据库交互")
public class FaceLib implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = 8698247745281784139L;

	/**
	 * 主键ID
	 */
	private Long id;

	/**
	 * 人脸图片 URL
	 */
	private String facePic;

	/**
	 * 创建时间
	 */
	private Date createTime;

	/**
	 * 备注信息
	 */
	private String memo;

}