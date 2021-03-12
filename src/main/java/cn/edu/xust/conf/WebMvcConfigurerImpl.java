package cn.edu.xust.conf;

import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.*;


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
		WebMvcConfigurer.super.addResourceHandlers(registry);
	}

	@Override
	public void addViewControllers(ViewControllerRegistry registry) {
		// 登录
		/*
		 * registry.addViewController("/login.html").setViewName("login");
		 * registry.addViewController("/getitem.html").setViewName("getitem");
		 * registry.addViewController("/getotp.html").setViewName("getotp");
		 * registry.addViewController("/register.html").setViewName("register");
		 */
	}

}
