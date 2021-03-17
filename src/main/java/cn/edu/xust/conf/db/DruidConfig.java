package cn.edu.xust.conf.db;

import javax.sql.DataSource;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.alibaba.druid.pool.DruidDataSource;

/**
 * @author HuangXin
 */
@Configuration
public class DruidConfig {

	/**
	 * 让Spring boot去加载这些属性，完成对连接池的初始化
	 *
	 * @return
	 */
	@Bean
	@ConfigurationProperties(prefix = "spring.datasource")
	public DataSource druid() {
		return new DruidDataSource();
	}
}
