package cn.edu.xust.iot.service;

import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.CameraAISettingModel;
import cn.edu.xust.iot.model.CameraInfoModel;
import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Camera;
import cn.edu.xust.iot.model.vo.CameraVO;
import com.github.pagehelper.PageInfo;

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
     * 添加新的监控摄像机
     *
     * @param cameraModel
     * @return
     */
    CommonResponse<String> addNewCamera(CameraModel cameraModel);


    /**
     * 获取所有监控摄像机的详细信息
     *
     * @return
     */
    PageInfo<CameraVO> getCameraList(PageParam pageParam);

    /**
     * 根据ID获取相机详细信息
     *
     * @param id
     * @return
     */
    CommonResponse<CameraVO> getCameraByID(Integer id);

    /**
     * 获取所有监控摄像机数量
     *
     * @return
     */
    CommonResponse<Integer> getAllCamerasSize();

    /**
     * 修改监控摄像机信息
     *
     * @param cameraModel
     * @return
     */
    CommonResponse<String> editCameraInfo(CameraModel cameraModel);

    /**
     * 删除人员，支持批量删除
     *
     * @param userIdList
     * @return
     */
    CommonResponse<String> removeCameraBatch(List<Integer> userIdList);


    /**
     * 获取到所有的摄像头
     *
     * @return
     */
    List<Camera> getAllCamera();

    /**
     * 根据区域名称获取区域内的所有相机
     *
     * @param regionName
     * @return
     */
    CommonResponse<List<CameraVO>> getCameraListByRegionName(String regionName);

    /**
     * 获取相机智能业务的开启状况
     *
     * @param ip
     * @return
     */
    CommonResponse<CameraAISettingModel> getCameraAIEnableState(String ip);

    /**
     * 开启某项相机智能业务
     *
     * @param ip
     * @return
     */
    CommonResponse<Boolean> enableCameraAISetting(String ip, String AIServiceName);

    /**
     * 关闭某项相机智能业务
     *
     * @param ip
     * @param AIServiceName
     * @return
     */
    CommonResponse<Boolean> closeCameraAISetting(String ip, String AIServiceName);


}
