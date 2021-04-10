package cn.edu.xust.iot.camera.handler;

import cn.edu.xust.iot.camera.data.CommandTask;
import cn.edu.xust.iot.camera.data.TaskDao;
import cn.edu.xust.iot.utils.ExecUtil;
import lombok.extern.slf4j.Slf4j;

import java.io.IOException;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * 任务保活处理器（一个后台保活线程，用于处理异常中断的持久任务）
 *
 * @author HuangXin
 * @since 2021/4/9 8:57
 */
@Slf4j
public class KeepAliveHandler extends Thread {

    /**
     * 待处理队列
     */
    private static Queue<String> queue = null;

    public int err_index = 0;//错误计数

    public volatile int stop_index = 0;//安全停止线程标记

    /**
     * 任务持久化器
     */
    private TaskDao taskDao = null;

    public KeepAliveHandler(TaskDao taskDao) {
        super();
        this.taskDao = taskDao;
        queue = new ConcurrentLinkedQueue<>();
    }

    public static void add(String id) {
        if (queue != null) {
            queue.offer(id);
        }
    }

    public boolean stop(Process process) {
        if (process != null) {
            process.destroy();
            return true;
        }
        return false;
    }

    @Override
    public void run() {
        for (; stop_index == 0; ) {
            if (queue == null) {
                continue;
            }
            String id = null;
            CommandTask task = null;

            try {
                while (queue.peek() != null) {
                    log.info("准备重启任务：" + queue);
                    id = queue.poll();
                    task = taskDao.get(id);
                    //重启任务
                    ExecUtil.restart(task);
                }
            } catch (IOException e) {
                log.error(id + " 任务重启失败，详情：" + task);
                //重启任务失败
                err_index++;
            } catch (Exception e) {
                log.error(e.getMessage());
            }
        }
    }

    @Override
    public void interrupt() {
        stop_index = 1;
    }


}
