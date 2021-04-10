package cn.edu.xust.iot.camera.builder;

import cn.edu.xust.iot.camera.builder.impl.HIKVisionRTSPStreamBuilder;
import cn.edu.xust.iot.camera.builder.impl.HuaWeiRTSPStreamBuilder;
import cn.edu.xust.iot.camera.pojo.CameraInfo;
import lombok.extern.slf4j.Slf4j;

import java.util.Objects;

/**
 * RTSP流工厂
 * @author HuangXin
 * @since 2021/4/6 23:21
 */
@Slf4j
public class RTSPStreamBuilderFactory {

    public static String generateRTSPStreamURL(CameraType type, CameraInfo cameraInfo){
        if(Objects.isNull(type)){
            throw new RuntimeException("相机类型不能为空");
        }
        switch (type){
            case AXIS: return "";
            case Canon: return "";
            case HUAWEI: return new HuaWeiRTSPStreamBuilder().builder(cameraInfo);
            case HIKVISION: return new HIKVisionRTSPStreamBuilder().builder(cameraInfo);
            default: return null;
        }
    }


}
