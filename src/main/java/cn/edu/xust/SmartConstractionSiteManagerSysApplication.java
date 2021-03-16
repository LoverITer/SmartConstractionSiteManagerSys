package cn.edu.xust;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;


@MapperScan("cn.edu.xust.mapper")
@EnableWebMvc
@SpringBootApplication
public class SmartConstractionSiteManagerSysApplication {

	public static void main(String[] args) {
		SpringApplication.run(SmartConstractionSiteManagerSysApplication.class, args);
	}

}
