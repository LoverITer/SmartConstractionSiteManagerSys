package cn.edu.xust.iot.camera.builder;

/**
 * @author HuangXin
 * @since 2021/4/9 8:36
 */
public class CommandBuilderFactory {

    public static CommandBuilder createBuilder() {
        return new DefaultCommandBuilder();
    };

    public static  CommandBuilder createBuilder(String rootPath) {
        return new DefaultCommandBuilder(rootPath);
    };

}
