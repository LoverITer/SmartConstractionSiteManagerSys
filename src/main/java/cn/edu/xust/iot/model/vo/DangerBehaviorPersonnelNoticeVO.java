package cn.edu.xust.iot.model.vo;

import lombok.Data;

import java.io.Serializable;

/**
 * 违规人员通报
 *
 * @author HuangXin
 * @since 2021/5/22 18:50
 */
@Data
public class DangerBehaviorPersonnelNoticeVO implements Serializable {

    //姓名
    private String name;
    //职位
    private String job;
    //人脸头像
    private String facePic;
    //最近一次告警时间
    private String nearNoticeTime;
    //危险行为名称
    private String dangerName;
    //人员状态
    private String personState;
    //累计违规次数
    private Integer personNoticeTimeSum;


}
