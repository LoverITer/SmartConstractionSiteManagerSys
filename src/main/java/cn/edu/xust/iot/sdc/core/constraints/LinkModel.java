package cn.edu.xust.iot.sdc.core.constraints;

/**
 * 前端的连接模式，有三种连接模式： 自动连接 、手动连接和混合连接三种模式
 * <br/>
 * ●	0：自动连接模式，解码器上电后主动连接到SDK，需要在前端配置SDK所在设备的IP和端口；对接C20解码器需采用此模式。
 * <br/>
 * ●	1：手动连接模式， SDK主动连接前端设备，在此模式下，SDK需要知道前端的用户名和密码。
 * <br/>
 * ●	3：混合连接模式， SDK支持自动连接与手动连接两种模式
 * @author HuangXin
 * @since 2021/4/18 16:23
 */
public enum LinkModel {


    AUTO_LINK(0),
    MANUAL_LINK(1),
    MIXED(3);

    private final int model;

    LinkModel(final int model){
        this.model=model;
    }

    public int getModel() {
        return model;
    }
}
