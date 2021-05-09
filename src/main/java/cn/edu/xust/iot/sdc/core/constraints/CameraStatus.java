package cn.edu.xust.iot.sdc.core.constraints;

/**
 * 监控摄像机状态
 *
 * @author HuangXin
 * @since 2021/5/9 15:00
 */
public enum CameraStatus {

    /**
     * 摄像机离线
     */
    OFFLINE("0"),
    /**
     * 摄像机在线
     */
    ONLINE("1"),
    /**
     * 摄像机告警
     */
    WARNING("2"),
    /**
     * 摄像机故障
     */
    MALFUNCTION("3"),
    /**
     * 摄像机状态未知
     */
    UNKNOWN("");
    ;
    private String status;


    CameraStatus(String status) {
        this.status = status;
    }

    public String getStatus() {
        return status;
    }
}
