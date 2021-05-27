package cn.edu.xust.iot.model.vo;

import lombok.Data;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/5/22 10:30
 */
@Data
public class DangerBehaviorHalfMonthAmountVO implements Serializable {

    //发生日期
    private String date;
    //预警数
    private Integer warningNum;
}
