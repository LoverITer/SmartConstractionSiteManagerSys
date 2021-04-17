package cn.edu.xust.iot.model.entity;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;

@Getter
@Setter
@NoArgsConstructor
@ToString
public class FaceLib{


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

	public FaceLib(String facePic, Date createTime) {
		this.facePic = facePic;
		this.createTime = createTime;
	}
}