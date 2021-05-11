package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.conf.redis.RedisKeyManager;
import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.model.AdminUserModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.AdminUser;
import cn.edu.xust.iot.service.IAdminUserService;
import cn.edu.xust.iot.service.impl.RedisService;
import cn.edu.xust.iot.utils.CommonUtils;
import com.alibaba.fastjson.JSON;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;

/**
 * @author HuangXin
 * @since 2021/4/13 12:22
 */
@Api(tags = "管理员用户登陆控制器接口")
@Slf4j
@Controller
@RequestMapping(value = "/user")
public class LoginController {

    /**
     * 管理员用户登录会话的最大有效时间  3小时
     */
    private static final long MAX_USER_LOGIN_STATUS_KEEP_TIME = 3600*3;
    @Autowired
    private IAdminUserService adminService;

    @Autowired
    private RedisService redisService;

    @ApiOperation(value = "管理员用户登陆接口")
    @ResponseBody
    @PostMapping(value = "/login")
    public CommonResponse<String> login(@RequestBody @Valid AdminUserModel userModel, BindingResult result){
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("用户登陆参数校验不合法，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID.getCode(),builder.toString(),null);
        }
        //检查用户名密码
        AdminUser adminUser = adminService.checkUser(userModel);
        if(null==adminUser){
            return CommonResponse.create(AppResponseCode.USER_NOT_FOUND,"管理员账号"+userModel.getUsername()+"未注册");
        }
        //用户登录token的key:当前毫秒时间戳+UUID
        String userLoginToken = String.format(RedisKeyManager.USER_LOGIN_TOKEN, System.currentTimeMillis(), CommonUtils.getRandomString());
        Boolean res = redisService.setnx(userLoginToken, JSON.toJSONString(adminUser),  RedisService.RedisDataBaseSelector.DB_0);
        if (res == null) {
            return CommonResponse.create(AppResponseCode.USER_LOGIN_FAIL, "管理员登陆失败，请重试！");
        } else if (!res) {
            return CommonResponse.create(AppResponseCode.USER_LOGIN_REPEAT, "管理员账号"+userModel.getUsername()+"已登录,请不要重复登录！");
        }
        redisService.expire(userLoginToken, MAX_USER_LOGIN_STATUS_KEEP_TIME, RedisService.RedisDataBaseSelector.DB_0);
        //将用户登录的token返回前端
        return CommonResponse.create(AppResponseCode.USER_LOGIN_SUCCESS, userLoginToken);
    }

    @ApiOperation(value = "获取管理员用户的会话信息")
    @ResponseBody
    @GetMapping(value = "/session_status")
    public CommonResponse<Boolean> getUserSessionStatus(String token){
        Object o = redisService.get(token, RedisService.RedisDataBaseSelector.DB_0);
        if(null!=o){
            return CommonResponse.create(AppResponseCode.SUCCESS,true);
        }
        return CommonResponse.create(AppResponseCode.SUCCESS,false);
    }


    @ApiOperation(value = "管理员退出接口", notes = "管理员退出接口")
    @GetMapping(value = "/logout")
    public String logout(@RequestParam(value = "token") String token){
        if(CommonUtils.isNull(token)){
            return "redirect:/admin/index";
        }
        Boolean res = redisService.delete(RedisService.RedisDataBaseSelector.DB_0, token);
        if(null==res||!res){
            return "redirect:/admin/index?token="+token;
        }
        return "login";
    }


    @ApiOperation(value = "获取登陆用户的信息",notes = "获取登陆用户的信息")
    @ResponseBody
    @GetMapping(value = "/info")
    public CommonResponse<AdminUser> getAdminUserInfo(@RequestParam(value = "token") String token){
        if(CommonUtils.isNull(token)){
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        AdminUser adminUser = JSON.parseObject((String) redisService.get(token, RedisService.RedisDataBaseSelector.DB_0), AdminUser.class);

        if(null==adminUser){
            return CommonResponse.create(AppResponseCode.FAIL);
        }
        return CommonResponse.create(AppResponseCode.SUCCESS,adminUser);
    }


}
