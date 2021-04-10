package cn.edu.xust.iot.camera.data;

import cn.edu.xust.iot.camera.handler.OutHandler;

/**
 * 用于存放任务id,任务主进程，任务输出线程
 *
 * @author HuangXin
 * @since 2021/4/9 8:50
 */
public class CommandTask {
    private final String id;// 任务id
    private final String command;//命令行
    private Process process;// 命令行运行主进程
    private OutHandler thread;// 命令行消息输出子线程

    public CommandTask(String id, String command) {
        this.id = id;
        this.command = command;
    }

    public CommandTask(String id, String command, Process process, OutHandler thread) {
        this.id = id;
        this.command = command;
        this.process = process;
        this.thread = thread;
    }

    public String getId() {
        return id;
    }

    public Process getProcess() {
        return process;
    }

    public OutHandler getThread() {
        return thread;
    }

    public String getCommand() {
        return command;
    }

    public void setProcess(Process process) {
        this.process = process;
    }

    public void setThread(OutHandler thread) {
        this.thread = thread;
    }

    @Override
    public String toString() {
        return "CommandTasker [id=" + id + ", command=" + command + ", process=" + process + ", thread=" + thread + "]";
    }


}
