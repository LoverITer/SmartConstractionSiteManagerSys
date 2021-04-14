package cn.edu.xust.iot.camera.builder.impl;

import cn.edu.xust.iot.camera.builder.RTSPStreamBuilder;
import cn.edu.xust.iot.model.CameraInfoModel;

/**
 * 生成华为摄像机RSTP流URL的工厂类
 * @author HuangXin
 * @since 2021/4/6 23:18
 */
public class HuaWeiRTSPStreamBuilder implements RTSPStreamBuilder {

    /**
     * 调用此方法生成华为摄像机的RSTP流地址 获取摄像机的实况流
     * @return
     */
    @Override
    public String builder(CameraInfoModel camera) {
        if(camera==null){
            throw new RuntimeException("相机配置不可为空");
        }
        return String.format("rtsp://%s:%s@%s/LiveMedia/%s/%s/trackID=1",
                             camera.getUsername(),camera.getPassword(),camera.getIp(),
                             camera.getChannel(),camera.getStream());
    }


}
