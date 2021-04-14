package cn.edu.xust.iot.model;

import lombok.Data;
import lombok.ToString;
import org.hibernate.validator.constraints.NotEmpty;
import org.hibernate.validator.constraints.Range;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/4/11 19:12
 */
@Data
@ToString
public class CameraModel implements Serializable {

    private static final long serialVersionUID = -9219693696973011411L;

    /**
     * 摄像机设别名称
     */
    @NotEmpty(message = "摄像机名称不能为空")
    private String deviceName;

    /**
     * 摄像机内网ip
     */
    @NotEmpty(message = "摄像机IP不能为空")
    private String ip;

    /**
     * 摄像机使用的端口
     */
    @Range(min = 0, max = 65535,message = "输入的端口不符合要求")
    private Integer port;

    /**
     * 摄像机用户名
     */
    @NotEmpty(message = "摄像机用户名不能为空")
    private String userName;

    /**
     * 摄像机密码
     */
    @NotEmpty(message = "摄像机密码不能为空")
    private String password;

    /**
     * 摄像机所在区域名
     */
    @NotEmpty(message = "地区名不能为空")
    private String regionName;


}
