package cn.edu.xust.iot.camera;

import cn.edu.xust.iot.camera.builder.CommandAssembly;
import cn.edu.xust.iot.camera.builder.CommandBuilder;
import cn.edu.xust.iot.camera.data.CommandTask;
import cn.edu.xust.iot.camera.data.TaskDao;
import cn.edu.xust.iot.camera.handler.TaskHandler;

import java.util.Collection;
import java.util.Map;

/**
 * FFmpeg命令操作管理器，可执行FFmpeg命令/停止/查询任务信息
 *
 * @author HuangXin
 * @since 2021/4/9 8:42
 */
public interface CommandManager {


    /**
     * 注入自己实现的持久层
     *
     * @param taskDao
     */
    void setTaskDao(TaskDao taskDao);

    /**
     * 注入ffmpeg命令处理器
     *
     * @param taskHandler
     */
    void setTaskHandler(TaskHandler taskHandler);

    /**
     * 注入ffmpeg命令组装器
     *
     * @param commandAssembly
     */
    void setCommandAssembly(CommandAssembly commandAssembly);

    /**
     * 通过命令发布任务（默认命令前不加FFmpeg路径）
     *
     * @param id      - 任务标识
     * @param command - FFmpeg命令
     * @return
     */
    String start(String id, String command);

    /**
     * 通过命令发布任务
     *
     * @param id      - 任务标识
     * @param commond - FFmpeg命令
     * @param hasPath - 命令中是否包含FFmpeg执行文件的绝对路径
     * @return
     */
    String start(String id, String commond, boolean hasPath);

    /**
     * 通过流式命令构建器发布任务
     *
     * @param commandBuilder
     * @return
     */
    String start(String id, CommandBuilder commandBuilder);

    /**
     * 通过组装命令发布任务
     *
     * @param assembly -组装命令（详细请参照readme文档说明）
     * @return
     */
    String start(Map<String, String> assembly);

    /**
     * 停止任务
     *
     * @param id
     * @return
     */
     boolean stop(String id);

    /**
     * 停止全部任务
     *
     * @return
     */
     int stopAll();

    /**
     * 通过id查询任务信息
     *
     * @param id
     */
     CommandTask query(String id);

    /**
     * 查询全部任务信息
     */
     Collection<CommandTask> queryAll();

    /**
     * 销毁一些后台资源和保活线程
     */
     void destroy();


}
