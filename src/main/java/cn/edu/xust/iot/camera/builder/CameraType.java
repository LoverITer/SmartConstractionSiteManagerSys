package cn.edu.xust.iot.camera.builder;

/**
 * 使用的摄像机类型
 *
 * @author HuangXin
 * @since 2021/4/6 23:11
 */
public enum CameraType {

    /**
     * 安讯士
     */
    AXIS(5),
    /**
     * 佳能
     */
    Canon(8),
    /**
     * 大华股份
     */
    DAHUA(7),
    /**
     * 海康威视
     */
    HIKVISION(1),
    /**
     * 华为
     */
    HUAWEI(2),
    /**
     * 三星
     */
    SAMSUNG(3),
    /**
     * 索尼
     */
    SONY(4),
    /**
     * 晶睿通讯
     */
    VIVOTEK(6);


    private int code;

    CameraType(final int code) {
        this.code = code;
    }
}
