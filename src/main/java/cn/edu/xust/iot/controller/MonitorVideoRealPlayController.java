package cn.edu.xust.iot.controller;

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
@RequestMapping(value = "/stream")
public class MonitorVideoRealPlayController {

    @GetMapping(value = "/real_play")
    public String realPlay(){

        return "video";
    }


}
