package cn.edu.xust.iot.camera.handler;

/**
 * 输出消息处理
 *
 * @author HuangXin
 * @since 2021/4/9 8:57
 */
public interface OutHandlerMethod {
    /**
     * 解析消息
     *
     * @param id-任务ID
     * @param msg     -消息
     */
    public void parse(String id, String msg);

    /**
     * 任务是否异常中断
     *
     * @return
     */
    public boolean isInterrupted();

}
