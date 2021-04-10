package cn.edu.xust.iot.camera.conf;

import lombok.Data;
import lombok.ToString;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

/**
 * @Title ConfigPojo.java
 * @description 读取配置文件的bean
 * @time 2019年12月25日 下午5:11:21
 * @author wuguodong
 **/
@Data
@ToString
@Component
@ConfigurationProperties(prefix = "camera.config",ignoreInvalidFields = true)
public class CameraRTSPToHttpFlvConfig {
	private String keepalive;// 保活时长（分钟）
	private String pushHost;// 推送地址
	private String hostExtra;// 额外地址
	private String pushPort;// 推送端口
	private String mainCode;// 主码流最大码率
	private String subCode;// 主码流最大码率
	private String version;// 版本信息

}
