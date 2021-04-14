package cn.edu.xust.iot.controller;

import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;

/**
 * Controller层抽取出来公共代用的方法
 *
 * @author ：huangxin
 * @modified ：
 * @since ：2020/06/15 19:54
 */
@Slf4j
@Component
public abstract class BaseController {

    /**
     * 登录页面
     */
    protected static final String LOGIN_PAGE = "redirect:/user/login.html";
    /**
     * 404页面路径
     */
    protected static final String PAGE404 = "redirect:/error/404";
    /**
     * 错误页面
     */
    protected static final String ERROR_PAGE = "redirect:/error/error";
    /**
     * 用户登录token
     */
    public static final String USER_LOGIN_TOKEN = "user_login_token";
    /**
     * 用户信息标记
     */
    protected static final String REMEMBER_ME_COOKIE = "REMEMBER-ME-COOKIE";

    /**
     * 用户登录信息最大保存时间（免登陆最大时间）:60天
     */
    protected static final int MAX_USER_LOGIN_STATUS_KEEP_TIME = 60 * 60 * 24 * 60;

    /**
     * 浏览器保存用户名，密码90天
     */
    protected static final int REMEMBER_ME_TIME = 60 * 60 * 24 * 90;


}
