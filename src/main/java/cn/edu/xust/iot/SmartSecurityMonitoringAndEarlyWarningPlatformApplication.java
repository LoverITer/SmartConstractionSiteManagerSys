package cn.edu.xust.iot;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

@MapperScan("cn.edu.xust.iot.mapper")
@EnableWebMvc
@SpringBootApplication
public class SmartSecurityMonitoringAndEarlyWarningPlatformApplication {

    public static void main(String[] args) {
        SpringApplication.run(SmartSecurityMonitoringAndEarlyWarningPlatformApplication.class, args);
    }

}
