package cn.edu.xust.iot.camera.pojo;

import lombok.Data;
import lombok.ToString;
import org.hibernate.validator.constraints.NotBlank;

import java.io.Serializable;

/**
 * 摄像机设备信息
 */
@Data
@ToString
public class CameraInfo implements Serializable {

    private static final long serialVersionUID = 8183688502930584159L;
    @NotBlank(message = "摄像机登陆用户名不能为空")
    private String username;// 摄像头账号
    @NotBlank(message = "摄像机登陆密码不能为空")
    private String password;// 摄像头密码
    @NotBlank(message = "摄像机登陆IP地址不能为空")
    private String ip;// 摄像头ip
    @NotBlank(message = "摄像机连接通道不能为空")
    private String channel;// 摄像头通道
    @NotBlank(message = "摄像机码流不能为空")
    private String stream;// 摄像头码流
    private String rtsp;// rtsp地址
    private String rtmp;// rtmp地址
    private String url;// 播放地址
    private String startTime;// 回放开始时间
    private String endTime;// 回放结束时间
    private String openTime;// 打开时间
    private int count = 0;// 使用人数
    private String token;

}
