package cn.edu.xust.iot.camera.handler;

import cn.edu.xust.iot.camera.data.CommandTask;

/**
 * 任务执行接口
 *
 * @author HuangXin
 * @since 2021/4/9 9:02
 */
public interface TaskHandler {

    /**
     * 按照命令执行主进程和输出线程
     *
     * @param id
     * @param command
     * @return
     */
    public CommandTask process(String id, String command);

    /**
     * 停止主进程（停止主进程需要保证输出线程已经关闭，否则输出线程会出错）
     *
     * @param process
     * @return
     */
    public boolean stop(Process process);

    /**
     * 停止输出线程
     *
     * @param thread
     * @return
     */
    public boolean stop(Thread thread);

    /**
     * 正确的停止输出线程和主进程
     *
     * @param process
     * @param thread
     * @return
     */
    public boolean stop(Process process, Thread thread);

}
