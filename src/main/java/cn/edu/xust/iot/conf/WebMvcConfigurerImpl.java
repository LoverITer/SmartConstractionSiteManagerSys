package cn.edu.xust.iot.conf;

import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.ViewControllerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;


/**
 * 自定义Web MVC配置
 * 
 * @author HuangXin
 * @since  2021/03/12 10:40
 */
@Configuration
public class WebMvcConfigurerImpl implements WebMvcConfigurer {

	@Override
	public void addInterceptors(InterceptorRegistry registry) {
    
	}

	@Override
	public void addResourceHandlers(ResourceHandlerRegistry registry) {
		registry.addResourceHandler("/static/**").addResourceLocations("classpath:/static/");
		registry.addResourceHandler("swagger-ui.html").addResourceLocations("classpath:/META-INF/resources/");
		registry.addResourceHandler("/webjars/**").addResourceLocations("classpath:/META-INF/resources/webjars/");
		registry.addResourceHandler("doc.html").addResourceLocations("classpath:/META-INF/resources/");
		WebMvcConfigurer.super.addResourceHandlers(registry);
	}

	@Override
	public void addViewControllers(ViewControllerRegistry registry) {
		registry.addRedirectViewController("/api", "/swagger-ui.html");
		registry.addRedirectViewController("/docs", "/doc.html");
		// 登录
		/*
		 * registry.addViewController("/login.html").setViewName("login");
		 * registry.addViewController("/getitem.html").setViewName("getitem");
		 * registry.addViewController("/getotp.html").setViewName("getotp");
		 * registry.addViewController("/register.html").setViewName("register");
		 */
	}

}
