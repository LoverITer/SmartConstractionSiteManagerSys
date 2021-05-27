package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.WorkerOverviewNumModel;
import cn.edu.xust.iot.model.vo.ClockInManagerVO;
import cn.edu.xust.iot.model.vo.ClockInWeeklyAmountVO;
import cn.edu.xust.iot.model.vo.HumanAmountVO;
import cn.edu.xust.iot.service.IClockInService;
import cn.edu.xust.iot.service.IRegionHumanCountService;
import cn.edu.xust.iot.service.ISUserService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.math.BigDecimal;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 人员管理控制器
 *
 * @author HuangXin
 * @since 2021/4/21 22:12
 */
@Slf4j
@RequestMapping(value = "/member")
@Api(tags = "人员信息展示接口")
@RestController
public class PersonnelManagementController {

    @Autowired
    private ISUserService userService;
    @Autowired
    private IClockInService clockInService;
    @Autowired
    private IRegionHumanCountService regionHumanCountService;


    @ApiOperation(value = "获取不同工作人员的数量概况数据", notes = "无参数,直接请求接口就可以获得系统所有工人的数量概况数据")
    @GetMapping(value = "/num/overview")
    public CommonResponse<WorkerOverviewNumModel> getWorkerOverviewNums() {
        return userService.getWorkerOverviewNums();
    }

    @ApiOperation(value = "获取不同工作人员的数量详细数据", notes = "无参数,直接请求接口就可以获得系统所有工人的数量详细数据")
    @GetMapping(value = "/num/detail")
    public CommonResponse<Map<String,List<String>>> getWorkerDetailsNums() {
        return userService.getWorkerDetailNums();
    }

    @ApiOperation(value = "实时获取当天工作人员的签到打卡情况",
            notes = "可以获取到的数据包括：今日出勤总人数(clockInUserNum)、今日出勤非管理人员总数(allClockInWorkerNum)、" +
                    "今日出勤管理人员总数(allClockInManagerNum)、出勤率(clockRate)")
    @GetMapping(value = "/clockInNum")
    public CommonResponse<Map<String, String>> getClockInWorkerNum() {
        //获取当天工人打卡数据
        Integer allClockInWorkerNum = clockInService.getAllClockInWorkerNum();
        //获取当天管理人员打卡数据
        Integer allClockInManagerNum = clockInService.getAllClockInManagerNum();
        //今日总的打卡人数
        Integer clockInUserNum = clockInService.getClockInUserNum();
        //获取系统所有人员数量
        CommonResponse<Integer> allMembersSize = userService.getAllMembersSize();
        Integer allUserNum = allMembersSize.getData();
        double clockRate = new BigDecimal((float) clockInUserNum / allUserNum)
                .setScale(4, BigDecimal.ROUND_HALF_UP)
                .multiply(BigDecimal.valueOf(100)).doubleValue();
        Map<String, String> modelMap = new HashMap<String, String>() {{
            put("allClockInWorkerNum", String.valueOf(allClockInWorkerNum));
            put("allClockInManagerNum", String.valueOf(allClockInManagerNum));
            put("clockInUserNum", String.valueOf(clockInUserNum));
            put("clockRate", String.valueOf(clockRate));
        }};
        return CommonResponse.create(AppResponseCode.SUCCESS, modelMap);
    }

    @ApiOperation(value = "实时获取当天管理人员的签到打卡详细情况",
            notes = "可以获取到的数据包括：管理人员的头像、管理人员姓名、管理人员职位、管理人员打卡签到时间（包括上班打卡时间和下班打卡时间）")
    @GetMapping(value = "/clockInManagerInfo")
    public CommonResponse<List<ClockInManagerVO>> getClockInManagerInfo() {
        return clockInService.getAllManagerClockRecord();
    }

    @ApiOperation(value = "实时获取最近7天工作人员的签到打卡情况",
            notes = "可以获取到的数据包括：进7天每天的打卡人数以及对应的日期")
    @GetMapping(value = "/pastSevenDaysClockInTrend")
    public CommonResponse<List<ClockInWeeklyAmountVO>> getPast7DaysClockInTrend() {
        return clockInService.getPast7DaysClockInNum();
    }

    @ApiOperation(value = "实时获取当天逐小时（例如：10:00-11:00）各区域的人流量数据",
            notes = "可以获取到的数据包括：各区域的进入人数和出场以及对应区域名")
    @GetMapping(value = "/human_num/hourly")
    public CommonResponse<List<HumanAmountVO>> getRegionHumanCountHourly(){
        return regionHumanCountService.getRegionHumanCountHourly();
    }

    @ApiOperation(value = "实时获取当天各区域的人流量数据",
            notes = "可以获取到的数据包括：各区域的进入人数和出场以及对应区域名")
    @GetMapping(value = "/human_num/daily")
    public CommonResponse<List<HumanAmountVO>> getRegionHumanCountDaily(){
        return regionHumanCountService.getRegionHumanCountDaily();
    }

}
