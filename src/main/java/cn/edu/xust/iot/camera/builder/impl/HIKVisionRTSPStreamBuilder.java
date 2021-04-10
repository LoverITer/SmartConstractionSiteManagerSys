package cn.edu.xust.iot.camera.builder.impl;

import cn.edu.xust.iot.camera.builder.RTSPStreamBuilder;
import cn.edu.xust.iot.camera.pojo.CameraInfo;

/**
 * @author HuangXin
 * @since 2021/4/7 11:18
 */
public class HIKVisionRTSPStreamBuilder implements RTSPStreamBuilder {
    @Override
    public String builder(CameraInfo cameraInfo) {
        if(cameraInfo==null){
            throw new RuntimeException("相机配置不可为空");
        }
        return "rtsp://" + cameraInfo.getUsername() + ":" + cameraInfo.getPassword() + "@" +
                cameraInfo.getIp() + ":554/h264/ch" + cameraInfo.getChannel() + "/" + cameraInfo.getStream()
                + "/av_stream";
    }
}
