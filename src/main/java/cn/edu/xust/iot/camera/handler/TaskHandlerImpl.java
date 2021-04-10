package cn.edu.xust.iot.camera.handler;


import cn.edu.xust.iot.camera.CommandManagerImpl;
import cn.edu.xust.iot.camera.data.CommandTask;
import cn.edu.xust.iot.utils.ExecUtil;
import lombok.extern.slf4j.Slf4j;

import java.io.IOException;

/**
 * 任务执行处理器，可以执行用户给定命令
 *
 * @author HuangXin
 * @since 2021/4/9 9:03
 */
@Slf4j
public class TaskHandlerImpl implements TaskHandler {


    private OutHandlerMethod ohm = null;

    public TaskHandlerImpl(OutHandlerMethod ohm) {
        this.ohm = ohm;
    }

    public void setOhm(OutHandlerMethod ohm) {
        this.ohm = ohm;
    }

    @Override
    public CommandTask process(String id, String command) {
        CommandTask task = null;
        try {
            task = ExecUtil.createTask(id, command, ohm);

            if (CommandManagerImpl.config.isDebug())
                log.info(id + " 执行命令行：" + command);

            return task;
        } catch (IOException e) {
            //运行失败，停止任务
            ExecUtil.stop(task);
            log.error(e.getMessage());
            if (CommandManagerImpl.config.isDebug())
                log.error(id + " 执行命令失败！进程和输出线程已停止");

            // 出现异常说明开启失败，返回null
            return null;
        }
    }

    @Override
    public boolean stop(Process process) {
        return ExecUtil.stop(process);
    }

    @Override
    public boolean stop(Thread outHandler) {
        return ExecUtil.stop(outHandler);
    }

    @Override
    public boolean stop(Process process, Thread thread) {
        boolean ret = false;
        ret = stop(thread);
        ret = stop(process);
        return ret;
    }

}
