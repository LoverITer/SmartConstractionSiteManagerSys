package cn.edu.xust.iot.model.vo;

import lombok.Data;
import lombok.ToString;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/4/30 18:57
 */
@Data
@ToString
public class ClockInManagerVO implements Serializable {

    /**
     * 姓名
     */
    private String name="NA";

    /**
     * 用户头像URL地址
     */
    private String facePic="NA";

    /**
     * 职位
     */
    private String job="NA";

    /**
     * 打卡上班时间
     */
    private String starkWorkTime="NA";

    /**
     * 打卡下班时间
     */
    private String afterWorkTime="NA";

}
