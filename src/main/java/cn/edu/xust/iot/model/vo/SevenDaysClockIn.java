package cn.edu.xust.iot.model.vo;

import lombok.Data;
import lombok.ToString;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/4/30 23:57
 */
@Data
@ToString
public class SevenDaysClockIn implements Serializable {

    /**
     * 统计日期
     */
    private String dateTime;

    /**
     * 每天的打卡总数
     */
    private int total;
}
