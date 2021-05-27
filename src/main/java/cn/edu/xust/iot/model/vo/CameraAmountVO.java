package cn.edu.xust.iot.model.vo;

import lombok.Data;
import lombok.ToString;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/5/22 7:55
 */
@Data
@ToString
public class CameraAmountVO implements Serializable {

    //相机总数
    private int total;
    //在线摄像机数量
    private int onlineNum;
    //离线摄像机数量
    private int offlineNum;
    //总告警摄像机数量
    private int totalWarningNum;
    //今日告警摄像机数量
    private int todayWarningNum;
    //摄像机算法数量
    private int algorithmNum;

}
