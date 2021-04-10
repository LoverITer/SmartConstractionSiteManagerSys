package cn.edu.xust.iot.camera.conf;

import cn.edu.xust.iot.utils.CommonUtils;
import lombok.Data;
import lombok.ToString;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

/**
 * 程序基础配置
 *
 * @author HuangXin
 * @since 2021/4/9 8:47
 */
@ToString
@Data
@Component
@ConfigurationProperties(prefix = "ffmpeg.config",ignoreInvalidFields = true)
public class FFmpegConfig {

    private String path;//默认命令行执行根路径
    private boolean debug;//是否开启debug模式
    private Integer size;//任务池大小
    private String callback;//回调通知地址
    private boolean keepalive;//是否开启保活

    /**
     * 设置FFmpeg的路径：首先判断配置文件中是否配置了路径，如果没有配置则默认从项目的resources目录下加载FFmpeg
     */
    public String getPath(){
        if(CommonUtils.isNull(path)){
            String projectRootPath = CommonUtils.getProjectRootPath();
            StringBuilder sb = new StringBuilder();
            path=sb.append(projectRootPath).append("ffmpeg/bin").toString();
        }
        return path;
    }


}
