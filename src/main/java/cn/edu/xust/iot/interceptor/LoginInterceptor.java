package cn.edu.xust.iot.interceptor;

import cn.edu.xust.iot.conf.http.RequestWrapper;
import cn.edu.xust.iot.service.impl.RedisService;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
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
        String token ="";
        String method = request.getMethod();
        log.info("登陆拦截器 拦截到 {} 请求：{}",method.toUpperCase(), request.getRequestURL());
        if("GET".equals(method.toUpperCase())){
            token = request.getParameter("token");
        }else{
            RequestWrapper requestWrapper = new RequestWrapper(request);
            JSONObject jsonObject = JSON.parseObject(requestWrapper.getBody());
            token =(String) jsonObject.get("token");
        }
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
