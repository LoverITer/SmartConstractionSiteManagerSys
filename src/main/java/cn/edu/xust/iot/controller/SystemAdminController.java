package cn.edu.xust.iot.controller;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * 系统后台管理接口，主要功能包括系统管理员登陆、摄像机设备的增删改查、建筑施工人员的增删改查等
 * @author HuangXin
 * @since 2021/4/13 10:29
 */
@Api(tags = "系统后台管理接口")
@Controller
@RequestMapping(value = "/admin")
public class SystemAdminController {


    @ApiOperation(value = "后台管理系统首页")
    @GetMapping(value = "/index")
    public String index(@RequestParam(value = "token",required = true) String token, ModelMap model){
        System.out.println(token);
        model.addAttribute("token",token);
        return "index";
    }


}
