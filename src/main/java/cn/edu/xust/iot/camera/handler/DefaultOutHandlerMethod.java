package cn.edu.xust.iot.camera.handler;

import lombok.extern.slf4j.Slf4j;

/**
 * 默认任务消息输出处理
 *
 * @author HuangXin
 * @since 2021/4/9 9:04
 */
@Slf4j
public class DefaultOutHandlerMethod implements OutHandlerMethod {

    /**
     * 任务是否异常中断，如果
     */
    public boolean isInterrupted = false;

    @Override
    public void parse(String id, String msg) {
        //过滤消息
        if (msg.contains("fail")) {
            log.error(id + "任务可能发生故障：" + msg + " 设置中断状态");
            isInterrupted = true;
        } else if (msg.contains("miss")) {
            log.error(id + "任务可能发生丢包：" + msg + " 设置中断状态");
            isInterrupted = true;
        } else {
            isInterrupted = false;
            System.out.println(id + "消息：" + msg);
        }

    }

    @Override
    public boolean isInterrupted() {
        return isInterrupted;
    }

}
