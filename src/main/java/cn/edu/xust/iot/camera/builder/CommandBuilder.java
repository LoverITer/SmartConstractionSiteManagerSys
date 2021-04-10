package cn.edu.xust.iot.camera.builder;

/**
 * FFmpeg流式命令行构建器
 * @author HuangXin
 * @since 2021/4/9 8:24
 */
public interface CommandBuilder {

    /**
     * 创建命令行
     *
     * @param root
     *            -命令行运行根目录或FFmpeg可执行文件安装目录
     * @return
     */
    CommandBuilder create(String root);

    /**
     * 创建默认根目录或默认FFmpeg可执行文件安装目录
     *
     * @return
     */
    CommandBuilder create();

    /**
     * 累加键-值命令
     *
     * @param key
     * @param val
     * @return
     */
    CommandBuilder add(String key, String val);

    /**
     * 累加命令
     *
     * @param val
     * @return
     */
    CommandBuilder add(String val);

    /**
     * 生成完整命令行
     *
     * @return
     */
    CommandBuilder build();

    /**
     * 获取已经构建好的命令行
     * @return
     */
    String get();
    
}
