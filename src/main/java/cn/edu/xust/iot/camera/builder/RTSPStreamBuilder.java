package cn.edu.xust.iot.camera.builder;

import cn.edu.xust.iot.camera.pojo.CameraInfo;

/**
 * RSTP流工厂，根据使用的摄像机类型自动生成对应的RSTP流格式
 * @author HuangXin
 * @since 2021/4/6 23:03
 */
public interface RTSPStreamBuilder {

    /**
     * 构建RSTP流格式
     * @return
     */
    String builder(CameraInfo cameraInfo);

}
