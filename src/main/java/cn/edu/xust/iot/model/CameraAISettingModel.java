package cn.edu.xust.iot.model;

import cn.edu.xust.iot.conf.ApplicationContextHolder;
import cn.edu.xust.iot.model.constration.CameraAISettingChoice;
import cn.edu.xust.iot.sdc.core.constraints.PlayType;
import cn.edu.xust.iot.service.IHWPuSDKService;
import lombok.Data;
import lombok.ToString;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/5/17 17:23
 */
@Data
@ToString
public class CameraAISettingModel implements Serializable {

    /**
     *
     */
    private transient IHWPuSDKService hwPuSDKService = ApplicationContextHolder.getBean("hwPuSDKService");

    /**
     * 当前相机是否开启了人脸打卡业务： 0 未开启 ，1 开启了
     */
    private int isClockInEnable;
    /**
     * 当前相机是否开启了区域人流量签到业务： 0 未开启 ，1 开启了
     */
    private int isCrowdCountEnable;
    /**
     * 当前相机是否开启了危险行为监测与报警业务： 0 未开启 ，1 开启了
     */
    private int isDangerWarningEnable;

    /**
     * 相机打卡功能是否开启
     *
     * @return
     */
    public boolean isClockInEnable() {
        return this.isClockInEnable == 1;
    }

    /**
     * 相机区域人流量统计是否开启
     *
     * @return
     */
    public boolean isCrowdCountEnable() {
        return this.isCrowdCountEnable == 1;
    }

    /**
     * 相机危险行为功能是否开启
     *
     * @return
     */
    public boolean isDangerWarningEnable() {
        return this.isDangerWarningEnable == 1;
    }


    /**
     * 待开启的智能业务与正在运行的业务是否冲突
     *
     * @return
     */
    public boolean isConflict() {
        return this.isClockInEnable == 1 || this.isCrowdCountEnable == 1 || this.isDangerWarningEnable == 1;
    }


    //在这里调用方法
    public CameraAISettingModel open(String ip, String typeID) {
        if (CameraAISettingChoice.Face_Punching_Business.equals(typeID)) {
            //开启人脸打卡功能回调
            long winID = hwPuSDKService.startRealPlay(ip, PlayType.FACE_RECOGNITION_CALLBACK_IMPL);
            if (winID > 0) {
                this.setIsClockInEnable(1);
            }
            return this;
        } else if (CameraAISettingChoice.Region_Crowd_Count_Business.equals(typeID)) {
            //开启区域人流量统计回调功能
            long winID = hwPuSDKService.startRealPlay(ip, PlayType.REGION_CROWD_DENSITY_CALLBACK_IMPL);
            if (winID > 0) {
                this.setIsCrowdCountEnable(1);
            }
            return this;
        } else if (CameraAISettingChoice.Danger_Warning_Business.equals(typeID)) {
            //开启危险行为检测回调功能
            long winID = hwPuSDKService.startRealPlay(ip, PlayType.DANGEROUS_BEHAVIOR_WARNING_CALLBACK_IMPL);
            if (winID > 0) {
                this.setIsDangerWarningEnable(1);
            }
            return this;
        }
        return null;
    }


    //关闭智能业务
    public CameraAISettingModel close(String ip, String typeID) {
        boolean stopRes = hwPuSDKService.stopRealPlay(ip);
        if(stopRes) {
            if (CameraAISettingChoice.Face_Punching_Business.equals(typeID)) {
                this.setIsClockInEnable(0);
            } else if (CameraAISettingChoice.Region_Crowd_Count_Business.equals(typeID)) {
                this.setIsCrowdCountEnable(0);
            } else if (CameraAISettingChoice.Danger_Warning_Business.equals(typeID)) {
                this.setIsDangerWarningEnable(0);
            }
            return this;
        }
        return null;
    }

}
