package cn.edu.xust.iot.camera.builder.impl;

import cn.edu.xust.iot.camera.builder.RTSPStreamBuilder;
import cn.edu.xust.iot.model.CameraInfoModel;

/**
 * @author HuangXin
 * @since 2021/4/7 11:18
 */
public class HIKVisionRTSPStreamBuilder implements RTSPStreamBuilder {
    @Override
    public String builder(CameraInfoModel cameraInfoModel) {
        if(cameraInfoModel ==null){
            throw new RuntimeException("相机配置不可为空");
        }
        return "rtsp://" + cameraInfoModel.getUsername() + ":" + cameraInfoModel.getPassword() + "@" +
                cameraInfoModel.getIp() + ":554/h264/ch" + cameraInfoModel.getChannel() + "/" + cameraInfoModel.getStream()
                + "/av_stream";
    }
}
