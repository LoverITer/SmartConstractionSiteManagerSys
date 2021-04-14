package cn.edu.xust.iot.camera.constraints;

/**
 * 定义摄像机状态
 * @author HuangXin
 * @since 2021/4/11 13:16
 */
public enum CameraStatus {
    /**
     * 离线
     */
    OFFLINE("00"),

    /**
     * 在线
     */
    ONLINE("11"),

    /**
     * 未知故障
     */
    FAULT("10");

    private final String status;

    CameraStatus(final String status) {
        this.status = status;
    }

    public String getStatus(){
        return this.status;
    }
}
