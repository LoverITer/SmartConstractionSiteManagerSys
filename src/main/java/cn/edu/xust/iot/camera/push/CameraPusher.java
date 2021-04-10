package cn.edu.xust.iot.camera.push;

import cn.edu.xust.iot.camera.CommandManager;
import cn.edu.xust.iot.camera.CommandManagerImpl;
import cn.edu.xust.iot.camera.builder.CommandBuilderFactory;
import cn.edu.xust.iot.camera.conf.CameraRTSPToHttpFlvConfig;
import cn.edu.xust.iot.camera.pojo.CameraInfo;
import lombok.extern.slf4j.Slf4j;
import org.bytedeco.javacv.FFmpegFrameGrabber;
import org.bytedeco.javacv.FFmpegFrameRecorder;
import org.springframework.context.ApplicationContext;

/**
 * @author HuangXin
 * @Title CameraPusher.java
 * @description 推数据帧
 * @time 2020年4月5日 下午2:32:42
 **/
@Slf4j
public class CameraPusher {

    // 配置类
    private static CameraRTSPToHttpFlvConfig config;

    /**
     * 本地命令执行管理器
     */
    private CommandManager manager;

    /**
     * 设备信息
     */
    private CameraInfo cameraInfo;
    /**
     * 解码器
     */
    private FFmpegFrameRecorder recorder;
    /**
     * 采集器
     */
    private FFmpegFrameGrabber grabber;


    public CameraPusher(CameraInfo cameraInfo) {
        this.cameraInfo = cameraInfo;
    }


    // 通过applicationContext上下文获取Config类
    public static void setCameraConfiguration(ApplicationContext applicationContext) {
        config = applicationContext.getBean(CameraRTSPToHttpFlvConfig.class);
    }


    /**
     * 执行本地FFmpeg命令开始推送视频流到指定URL
     */
    public void publish() {
        manager = new CommandManagerImpl(10);
        //视频流源地址
        String input = cameraInfo.getRtsp();
        //视频流推动目的地址
        String output = cameraInfo.getRtmp();
        //设备随机生成的token作为应用名
        String token = cameraInfo.getToken();
        /*
         *优化到2s的推流命令:
         *  ffmpeg -re -thread_queue_size 1024 -i rtsp://admin:HuaWei123@192.168.0.120/LiveMedia/ch1/Media1/trackID=1 -vcodec copy -map 0:0 -preset ultrafast -tune zerolatency -g 5 -max_interleave_delta 2  -f flv rtmp://127.0.0.1:1935/live
         */
        //流式命令行组装执行
        try {
            manager.start(token, CommandBuilderFactory.createBuilder()
                    .add("ffmpeg")
                    .add("-re")
                    .add("-thread_queue_size", "1024")
                    .add("-i", input)
                    .add("-vcodec", "copy")
                    .add("-map", "0:0")
                    .add("-preset", "ultrafast")
                    .add("-tune", "zerolatency")
                    .add("-sc_threshold", "499")
                    .add("-max_interleave_delta", " 2")
                    .add("profile","high")
                    .add("-an")
                    .add("-g", "5")
                    .add("-f", "flv")
                    .add(output));
            log.info("启动推流成功");
        } catch (Exception e) {
            log.error("启动推流失败，{}", e.getMessage());
            stopPublish();
        }
    }

    /**
     * 结束推送
     */
    public void stopPublish() {
        manager.stop(cameraInfo.getToken());//停止
        //用于销毁保活线程等
        manager.destroy();
    }

}