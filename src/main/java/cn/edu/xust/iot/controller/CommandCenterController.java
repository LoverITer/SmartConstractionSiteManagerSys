package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.RegionHumanCount;
import cn.edu.xust.iot.service.IRegionHumanCountService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * 指挥中心控制器
 * @author HuangXin
 * @since 2021/5/9 11:04
 */
@Slf4j
@RequestMapping(value = "/center")
@Api(tags = "指挥中心信息展示接口—指挥中心页面所需接口")
@RestController
public class CommandCenterController {

    @Autowired
    private IRegionHumanCountService regionHumanCountService;

    @ApiOperation(value = "实时获取当天逐小时（例如：10:00-11:00）各区域的人流量数据",
            notes = "可以获取到的数据包括：进7天每天的打卡人数以及对应的日期")
    @GetMapping(value = "/humanCount")
    public CommonResponse<List<RegionHumanCount>> getRegionHumanCountInfo(){
       return regionHumanCountService.getRegionHumanCountHourly();
    }


}