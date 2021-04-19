package cn.edu.xust.iot.conf;

import cn.edu.xust.iot.interceptor.LoginInterceptor;
import org.springframework.beans.factory.annotation.Autowired;
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


	@Autowired
	private LoginInterceptor loginInterceptor;

	@Override
	public void addInterceptors(InterceptorRegistry registry) {
		InterceptorRegistration registration = registry.addInterceptor(loginInterceptor);
		//只对包含/admin路径的请求拦截
		registration.addPathPatterns("/admin/**");
		registration.excludePathPatterns("/admin/member/*");
		registration.excludePathPatterns("/admin/device/*");
		registration.excludePathPatterns("/admin/administrator/*");

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
		registry.addViewController("/login.html").setViewName("login");
		registry.addViewController("/register.html").setViewName("register");
		registry.addViewController("/welcome.html").setViewName("welcome");
		registry.addViewController("/admin/member/list.html").setViewName("/member/list");
		registry.addViewController("/admin/member/add.html").setViewName("/member/add");
		registry.addViewController("/admin/member/edit.html").setViewName("/member/edit");
		registry.addViewController("/admin/device/list.html").setViewName("/device/list");
		registry.addViewController("/admin/device/add.html").setViewName("/device/add");
		registry.addViewController("/admin/device/edit.html").setViewName("/device/edit");
		registry.addViewController("/admin/administrator/list.html").setViewName("/administrator/list");
	}

}
