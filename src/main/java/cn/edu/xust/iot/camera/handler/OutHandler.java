package cn.edu.xust.iot.camera.handler;

import cn.edu.xust.iot.camera.CommandManagerImpl;
import lombok.extern.slf4j.Slf4j;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * @author HuangXin
 * @since 2021/4/9 8:55
 */
@Slf4j
public class OutHandler extends Thread {

    /**控制状态 */
    private volatile boolean desstatus = true;

    /**读取输出流*/
    private BufferedReader br = null;

    /**任务ID*/
    private String id = null;

    /**消息处理方法*/
    private OutHandlerMethod ohm;

    /**
     * 创建输出线程（默认立即开启线程）
     * @param is
     * @param id
     * @param ohm
     * @return
     */
    public static OutHandler create(InputStream is, String id, OutHandlerMethod ohm) {
        return create(is, id, ohm,true);
    }

    /**
     * 创建输出线程
     * @param is
     * @param id
     * @param ohm
     * @param start-是否立即开启线程
     * @return
     */
    public static OutHandler create(InputStream is, String id,OutHandlerMethod ohm,boolean start) {
        OutHandler out= new OutHandler(is, id, ohm);
        if(start)
            out.start();
        return out;
    }

    public void setOhm(OutHandlerMethod ohm) {
        this.ohm = ohm;
    }

    public void setDesStatus(boolean desStatus) {
        this.desstatus = desStatus;
    }

    public void setId(String id) {
        this.id = id;
    }

    public OutHandlerMethod getOhm() {
        return ohm;
    }

    public OutHandler(InputStream is, String id,OutHandlerMethod ohm) {
        br = new BufferedReader(new InputStreamReader(is));
        this.id = id;
        this.ohm=ohm;
    }

    /**
     * 重写线程销毁方法，安全的关闭线程
     */
    @Override
    public void destroy() {
        setDesStatus(false);
    }

    /**
     * 执行输出线程
     */
    @Override
    public void run() {
        String msg = null;
        try {
            if (CommandManagerImpl.config.isDebug()) {
                log.info(id + "开始推流！");
            }
            while (desstatus && (msg = br.readLine()) != null) {
                ohm.parse(id,msg);
                if(ohm.isInterrupted()) {
                    log.error("检测到中断，提交重启任务给保活处理器");
                    //如果发生异常中断，立即进行保活
                    //把中断的任务交给保活处理器进行进一步处理
                    KeepAliveHandler.add(id);
                }
            }
        } catch (IOException e) {
            log.error("发生内部异常错误：{}，自动关闭[" + this.getId() + "]线程",e.getMessage());
            destroy();
        } finally {
            if (this.isAlive()) {
                destroy();
            }
        }
    }

}
