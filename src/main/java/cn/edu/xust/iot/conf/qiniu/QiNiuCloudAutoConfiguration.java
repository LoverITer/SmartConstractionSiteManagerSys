package cn.edu.xust.iot.conf.qiniu;

import org.springframework.boot.autoconfigure.condition.ConditionalOnClass;
import org.springframework.boot.autoconfigure.condition.ConditionalOnMissingBean;
import org.springframework.boot.autoconfigure.condition.ConditionalOnProperty;
import org.springframework.boot.autoconfigure.condition.ConditionalOnWebApplication;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

/**
 * @author HuangXin
 * @since 2019/12/29 14:23
 */
@Configuration
@EnableConfigurationProperties(QiNiuCloudProperties.class)
@ConditionalOnClass(QiNiuCloudProperties.class)
@ConditionalOnWebApplication
@ConditionalOnProperty(prefix = "qiniucloud", value = "enable", matchIfMissing = true)
public class QiNiuCloudAutoConfiguration {

	@Bean
	@ConditionalOnMissingBean(QiNiuCloudService.class)
	public QiNiuCloudService qiNiuCloudService() {
		return new QiNiuCloudService();
	}
}
