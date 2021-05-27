package cn.edu.xust.iot.model.vo;

import lombok.Data;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/5/22 13:36
 */
@Data
public class DangerBehaviorTodayOverviewAmountVO implements Serializable {

    //不安全行为检测
    private int unsafeBehaviorNum;
    //危险区域闯入
    private int dangerAreaBreakInNum;
    //高空违规操作告警数
    private int highWarningNum;


}
