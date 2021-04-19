package cn.edu.xust.iot.model;

import cn.edu.xust.iot.model.entity.Camera;
import lombok.Data;
import lombok.ToString;
import org.hibernate.validator.constraints.NotEmpty;
import org.hibernate.validator.constraints.Range;

import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;

/**
 * @author HuangXin
 * @since 2021/4/11 19:12
 */
@Data
@ToString
public class CameraModel implements Serializable {

    private static final long serialVersionUID = -9219693696973011411L;

    //数据库主键ID
    private int id;

    /**
     * 摄像机设别名称
     */
    @NotEmpty(message = "摄像机名称不能为空")
    protected String deviceName;

    /**
     * 摄像机状态
     */
    protected String deviceStatus;

    /**
     * 摄像机内网ip
     */
    @NotEmpty(message = "摄像机IP不能为空")
    protected String ip;

    /**
     * 摄像机使用的端口
     */
    @Range(min = 0, max = 65535,message = "输入的端口不符合要求")
    protected Integer port;

    /**
     * 摄像机用户名
     */
    @NotEmpty(message = "摄像机用户名不能为空")
    protected String userName;

    /**
     * 摄像机密码
     */
    @NotEmpty(message = "摄像机密码不能为空")
    protected String password;

    /**
     * 摄像机所在区域名
     */
    @NotEmpty(message = "地区名不能为空")
    protected String regionName;

    /**
     * 摄像机所使用的识别算法
     */
    protected String algorithmName;

    /**
     * 摄像机MAC地址
     */
    protected String macAddress;

    /**
     * 摄像机型号
     */
    protected String model;

    /**
     * 摄像机SDC版本
     */
    protected String sdcVersion;

    /**
     * 摄像机创建时间
     */
    protected String createTime;


    public Camera convertCameraModel2Camera(){
        Camera camera = new Camera();
        camera.setId(this.getId());
        camera.setDeviceName(this.getDeviceName());
        camera.setUserName(this.getUserName());
        camera.setIp(this.getIp());
        camera.setPort(this.getPort());
        camera.setUserName(this.getUserName());
        camera.setPassword(this.getPassword());
        camera.setAlgorithm(this.getAlgorithmName());
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        try {
            camera.setCreateTime(sdf.parse(this.getCreateTime()));
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return camera;
    }

}
