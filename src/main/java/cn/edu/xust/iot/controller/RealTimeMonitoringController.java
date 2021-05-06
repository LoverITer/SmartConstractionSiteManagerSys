package cn.edu.xust.iot.controller;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * 监控视屏实时播放控制器
 *
 * @author HuangXin
 * @since 2021/3/29 10:43
 */
@Controller
@RequestMapping(value = "/realTime")
@Api(tags="实时监控页面控制器接口—只用于内部测试")
public class RealTimeMonitoringController {

    @ApiOperation(value = "",notes = "查询数据（摄像机数据）并跳转到实时监控页面")
    @GetMapping(value = "/index")
    public String realPlay(){

        return "video";
    }


}
