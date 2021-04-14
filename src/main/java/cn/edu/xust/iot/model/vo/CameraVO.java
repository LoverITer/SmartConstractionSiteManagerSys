package cn.edu.xust.iot.model.vo;

import lombok.Data;

import java.io.Serializable;

/**
 * 相机视图显示对象
 *
 * @author HuangXin
 * @since 2021/4/12 14:06
 */
@Data
public class CameraVO implements Serializable {


    /**
     * 摄像机设别名称，实际情况下是region的补充
     */
    private String deviceName;

    /**
     * 摄像机状态
     */
    private String deviceStatus;

    /**
     * 摄像机安装区域
     */
    private String regionName;

    /**
     * 摄像机内网ip
     */
    private String ip;

    /**
     * 摄像机用户名
     */
    private String username;

    /**
     * 摄像机密码
     */
    private String password;


}
