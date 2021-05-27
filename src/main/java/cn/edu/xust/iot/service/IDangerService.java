package cn.edu.xust.iot.service;


import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Danger;
import cn.edu.xust.iot.model.vo.*;

import java.util.List;

/**
 * @author HuangXin
 * @since 2021/03/16 19:57
 */
public interface IDangerService {

    Danger getDangerInfo(int id);


    /**
     * 获取系统近15天的危险行为每天各发生数量
     *
     * @return
     */
    CommonResponse<List<DangerBehaviorHalfMonthAmountVO>> getHalfMonthDangerBehaviorAmount();

    /**
     * 获取系统近15天的危险行为每天各发生数量
     *
     * @return
     */
    CommonResponse<List<DangerBehaviorHalfMonthAmountVO>> getHalfMonthUnsafeBehaviorAmount();

    /**
     * 获取当天各类不安全行为数量
     *
     * @return
     */
    CommonResponse<List<UnSafeBehaviorAmountVO>> getTodayUnsafeBehaviorAmount();


    /**
     * 获取当天各类不安全行为TOP5的各自占比
     * 获取当天违规佩戴安全设备行为TOP5的各自占比
     * @param behaviorType
     * @return
     */
    CommonResponse<List<UnSafeBehaviorAmountVO>> getTodayBehaviorAmountTop5(String behaviorType);

    /**
     * 获取当天所有危险行为告警详细信息
     *
     * @return
     */
    CommonResponse<List<DangerBehaviorVO>> getTodayDangerBehavior();

    /**
     * 获取当天所有危险行为告警数量
     *
     * @return
     */
    CommonResponse<Integer> getTodayDangerBehaviorNum();

    /**
     * 获取当天三大类危险行为的总告警数量
     *
     * @return
     */
    CommonResponse<DangerBehaviorTodayOverviewAmountVO> getTodayDangerBehaviorTodayOverviewNum();

    /**
     * 处理危险行为
     *
     * @return
     */
    CommonResponse<Boolean> dealDangerBehavior(Integer id);

    /**
     * 获取所有人员的历史违规行为统计数据
     *
     * @return
     */
    CommonResponse<List<DangerBehaviorPersonnelNoticeVO>> getHistoryPersonnelDangerBehavior();

    /**
     * 统计所有人员今日不安全行为违规次数
     *
     * @return
     */
    CommonResponse<List<UnSafeBehaviorAmountVO>> getAllTypeDangerBehaviorAmount();

}
