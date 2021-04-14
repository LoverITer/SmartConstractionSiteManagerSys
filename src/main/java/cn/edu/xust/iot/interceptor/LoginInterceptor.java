package cn.edu.xust.iot.interceptor;

import cn.edu.xust.iot.service.impl.RedisService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.HandlerInterceptor;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * 非法访问拦截器
 *
 * @author huangxin
 */

@Slf4j
@Configuration
public class LoginInterceptor implements HandlerInterceptor {


    @Autowired
    private RedisService redisService;

    public LoginInterceptor() {

    }


    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        log.info("登陆拦截器 拦截到请求：{}", request.getRequestURL());
        String token = request.getParameter("token");
        if (null != token) {
            Boolean exists = redisService.exists(token, RedisService.RedisDataBaseSelector.DB_0);
            String url = request.getRequestURL().toString();
            if (url.contains("/admin") && (null == exists || !exists)) {
                log.warn("登陆拦截器  用户未登录，重定向到登陆页面");
                response.sendRedirect(request.getContextPath() + "/login.html");
                return false;
            }
            log.info("登陆拦截器 用户{}，拦截器返回true", url.contains("/admin") ? "已经登陆" : "访问的业务不需要登陆");
            return true;
        }
        log.warn("登陆拦截器  用户未登录，重定向到登陆页面");
        response.sendRedirect(request.getContextPath() + "/login.html");
        return false;
    }


}
