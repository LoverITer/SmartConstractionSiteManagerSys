package cn.edu.xust.iot;

import cn.edu.xust.iot.camera.CommandManagerImpl;
import cn.edu.xust.iot.camera.data.CameraWorkerCache;
import cn.edu.xust.iot.camera.handler.CameraThread;
import cn.edu.xust.iot.camera.push.CameraPusher;
import cn.edu.xust.iot.camera.timer.CameraTimer;
import cn.edu.xust.iot.controller.CameraController;
import lombok.extern.slf4j.Slf4j;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.ServletComponentScan;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.EnableAspectJAutoProxy;
import org.springframework.transaction.annotation.EnableTransactionManagement;

import javax.annotation.PreDestroy;
import java.util.Date;
import java.util.Set;

@Slf4j
@EnableAspectJAutoProxy
@EnableTransactionManagement
@MapperScan("cn.edu.xust.iot.mapper")
@ServletComponentScan(basePackages = "cn.edu.xust.iot.conf.http")
@SpringBootApplication
public class SmartSecurityMonitoringAndEarlyWarningPlatformApplication {

    public static void main(String[] args) {
        log.info("启动应用");
        CameraWorkerCache.START_TIME = new Date().getTime();
        ApplicationContext applicationContext = SpringApplication.run(SmartSecurityMonitoringAndEarlyWarningPlatformApplication.class, args);
        //从Spring上下文环境中获取关于相机的配置赋值给CameraPusher的config成员属性
        CameraPusher.setCameraConfiguration(applicationContext);
        CommandManagerImpl.setFFmpegConfig(applicationContext);
    }


    @PreDestroy
    public void destroy() {
        log.info("服务结束，开始释放空间...");
        // 结束正在进行的任务
        Set<String> keys = CameraController.WORK_MAP.keySet();
        for (String key : keys) {
             CameraController.WORK_MAP.get(key);
        }
        //关闭正在推流的所有服务
        CommandManagerImpl.stopAllPushTask();
        // 关闭线程池
        CameraThread.MyRunnable.executor.shutdown();
        // 销毁定时器
        CameraTimer.timer.cancel();
    }

}
