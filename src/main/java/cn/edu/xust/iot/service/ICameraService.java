package cn.edu.xust.iot.service;

import cn.edu.xust.iot.mapper.pagehelper.PageParam;
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


    CommonResponse<List<CameraVO>>  getCameraListByRegionName(String regionName);
}
