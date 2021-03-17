package cn.edu.xust.conf.qiniu;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import com.qiniu.common.Zone;
import com.qiniu.storage.Configuration;
import com.qiniu.storage.UploadManager;

import lombok.Data;

/**
 * @author HuangXin
 * @since 2019/12/29 13:57
 */
@Data
@Component
@ConfigurationProperties(prefix = "qiniucloud", ignoreInvalidFields = true)
public class QiNiuCloudProperties {

	/**
	 * 设置需要操作的账号的AK和SK
	 */
	private String accessKey;
	private String secretKey;
	/**
	 * 要上传的空间
	 */
	private String bucketName;
	/**
	 * 外链默认域名
	 */
	private String domain;
	/**
	 * 自定义图片样式
	 */
	private String style;
	/**
	 * 配置云服务器区域
	 */
	private final Configuration configuration = new Configuration(Zone.huanan());
	/**
	 * 七牛云图片上传管理器
	 */
	private final UploadManager uploadManager = new UploadManager(configuration);

	@Override
	public String toString() {
		return "QiNiuCloudProperties{" + "accessKey='" + accessKey + '\'' + ", secretKey='" + secretKey + '\''
				+ ", bucketName='" + bucketName + '\'' + ", domain='" + domain + '\'' + ", style='" + style + '\''
				+ ", configuration=" + configuration + ", uploadManager=" + uploadManager + '}';
	}
}
