package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.model.CommonResponse;
import io.swagger.annotations.Api;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * 安全管理控制器
 *
 * @author HuangXin
 * @since 2021/4/21 22:15
 */
@Slf4j
@RequestMapping(value = "/warning")
@Api(tags = "人员危险行为预警展示接口—安全管理页面所需接口")
@RestController
public class SafetyManagementController {


    @GetMapping(value = "/index")
    public CommonResponse index() {
        return CommonResponse.create(AppResponseCode.SUCCESS);
    }

}
