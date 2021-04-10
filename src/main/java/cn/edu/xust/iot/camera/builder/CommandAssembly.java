package cn.edu.xust.iot.camera.builder;

import java.util.Map;

/**
 * 命令组装器接口
 *
 * @author HuangXin
 * @since 2021/4/9 8:39
 */
public interface CommandAssembly {

    /**
     * 将参数转为ffmpeg命令
     * @param paramMap
     * @return
     */
    public String assembly(Map<String, String> paramMap);

    public String assembly();

}
