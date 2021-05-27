package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.vo.*;
import cn.edu.xust.iot.service.IDangerService;
import cn.edu.xust.iot.utils.CommonUtils;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * 安全管理控制器
 *
 * @author HuangXin
 * @since 2021/4/21 22:15
 */
@Slf4j
@RequestMapping(value = "/warning")
@Api(tags = "人员危险行为预警展示接口")
@RestController
public class SafetyManagementController {

    @Autowired
    private IDangerService dangerService;

    @GetMapping(value = "/index")
    public CommonResponse<Object> index() {
        return CommonResponse.create(AppResponseCode.SUCCESS);
    }


    @ApiOperation(value = "实时获取最近15天各天的危险行为预警数量",
            notes = "可以获取到的数据包括：每天的预警数量以及对应的日期")
    @GetMapping(value = "/half_month_danger_trend")
    public CommonResponse<List<DangerBehaviorHalfMonthAmountVO>> getRHalfMonthDangerBehaviorTrend() {
        return dangerService.getHalfMonthDangerBehaviorAmount();
    }

    @ApiOperation(value = "实时获取最近15天各天的危险行为预警数量",
            notes = "可以获取到的数据包括：每天的预警数量以及对应的日期")
    @GetMapping(value = "/half_month_unsafe_trend")
    public CommonResponse<List<DangerBehaviorHalfMonthAmountVO>> getRHalfMonthUnsafeBehaviorTrend() {
        return dangerService.getHalfMonthUnsafeBehaviorAmount();
    }


    @ApiOperation(value = "实时获取今日各类不安全行为预警数量",
            notes = "可以获取到的数据包括：今日各类不安全行为预警数量以及对应的不安全行为名称")
    @GetMapping(value = "/unsafe_num")
    public CommonResponse<List<UnSafeBehaviorAmountVO>> getTodayUnsafeBehaviorAmount() {
        return dangerService.getTodayUnsafeBehaviorAmount();
    }

    @ApiOperation(value = "实时获取今日全部类型不安全行为预警数量",
            notes = "可以获取到的数据包括：今日各类不安全行为预警数量以及对应的不安全行为名称,并且没有发生的以危险行为0表示")
    @GetMapping(value = "/all_type_unsafe_num")
    public CommonResponse<List<UnSafeBehaviorAmountVO>> getTodayAllTypeUnsafeBehaviorAmount(){
        return dangerService.getAllTypeDangerBehaviorAmount();
    }

    @ApiOperation(value = "实时获取今日TOP5不安全行为或违规佩戴安全设备占比",
            notes = "可以获取到的数据包括：不安全行为和违规佩戴安全设备行为名以及占比,路径参数有两个:UNSAFE表示获取TOP5不安全行为比例分布，DANGER表示获取违规佩戴安全设备行为比例分布")
    @GetMapping(value = "/{type}/rate")
    public CommonResponse<List<UnSafeBehaviorAmountVO>> getTodayAllTypeUnsafeBehaviorReta(@PathVariable(value = "type") String rateType){
        if(CommonUtils.isNull(rateType)){
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }

        return dangerService.getTodayBehaviorAmountTop5(rateType);
    }

    @ApiOperation(value = "实时获取今日各类危险行为告警详细信息",
            notes = "可以获取到的数据包括：告警信息名、告警时间、告警抓拍图片")
    @GetMapping(value = "/today_all_info")
    public CommonResponse<List<DangerBehaviorVO>> getTodayAllDangerBehavior() {
        return dangerService.getTodayDangerBehavior();
    }

    @ApiOperation(value = "实时获取今日全部告警数量",
            notes = "可以获取到的数据包括：告警数量")
    @GetMapping(value = "/today_all_size")
    public CommonResponse<Integer> getTodayAllDangerBehaviorAmount() {
        return dangerService.getTodayDangerBehaviorNum();
    }

    @ApiOperation(value = "实时获取三大类各自告警数量",
            notes = "可以获取到的数据包括：三大类各自告警数量")
    @GetMapping(value = "/today_overview_size")
    public CommonResponse<DangerBehaviorTodayOverviewAmountVO> getTodayDangerBehaviorTodayOverviewAmount() {
        return dangerService.getTodayDangerBehaviorTodayOverviewNum();
    }

    @ApiOperation(value = "处理危险行为",
            notes = "可以获取到的数据包括：处理结果，成功返回true，失败返回false")
    @GetMapping(value = "/deal_danger/{id}")
    public CommonResponse<Boolean> dealDangerBehavior(@PathVariable(value = "id") Integer id){
        return dangerService.dealDangerBehavior(id);
    }

    @ApiOperation(value = "获取所有人员的历史违规记录",
            notes = "可以获取到的数据包括：人员姓名、工种、最近违规时间、危险行为，人员状态，人员历史违规次数")
    @GetMapping(value = "/personnel_history_danger_behavior")
    public CommonResponse<List<DangerBehaviorPersonnelNoticeVO>> getPersonnelDangerBehaviorNotice(){
        return dangerService.getHistoryPersonnelDangerBehavior();
    }
}
