package cn.edu.xust.iot.service;

import cn.edu.xust.iot.model.CameraInfoModel;
import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Camera;

import java.util.List;

/**
 * 摄像机服务接口
 *
 * @author HuangXin
 * @since 2021/4/11 19:26
 */
public interface ICameraService {


    /**
     * 开启视频流
     *
     * @param cameraInfoModel
     * @return
     */
    CommonResponse<Object> openCamera(CameraInfoModel cameraInfoModel);

    /**
     * 关闭指定token的视频流
     *
     * @param token
     * @return
     */
    boolean closeCamera(String token);


    /**
     * 添加新的摄像机
     *
     * @param cameraModel
     * @return
     */
    int addNewCamera(CameraModel cameraModel);


    /**
     * 获取到所有的摄像头
     *
     * @return
     */
    List<Camera> getAllCamera();
}
