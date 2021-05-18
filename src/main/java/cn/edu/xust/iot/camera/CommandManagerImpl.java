package cn.edu.xust.iot.camera;

import cn.edu.xust.iot.camera.builder.CommandAssembly;
import cn.edu.xust.iot.camera.builder.CommandAssemblyImpl;
import cn.edu.xust.iot.camera.builder.CommandBuilder;
import cn.edu.xust.iot.camera.conf.FFmpegConfig;
import cn.edu.xust.iot.camera.data.CameraWorkerCache;
import cn.edu.xust.iot.camera.data.CommandTask;
import cn.edu.xust.iot.camera.data.TaskDao;
import cn.edu.xust.iot.camera.data.TaskDaoImpl;
import cn.edu.xust.iot.camera.handler.*;
import cn.edu.xust.iot.camera.push.CameraPusher;
import cn.edu.xust.iot.utils.ExecUtil;
import lombok.extern.slf4j.Slf4j;
import org.springframework.context.ApplicationContext;

import java.io.IOException;
import java.util.Collection;
import java.util.Iterator;
import java.util.Map;

/**
 * FFmpeg命令操作管理器实现
 *
 * @author HuangXin
 * @since 2021/4/9 8:45
 */
@Slf4j
public class CommandManagerImpl implements CommandManager {

    public static FFmpegConfig config;

    public static void setFFmpegConfig(ApplicationContext applicationContext) {
        config = applicationContext.getBean(FFmpegConfig.class);
    }

    /**
     * 任务持久化器
     */
    private TaskDao taskDao = null;
    /**
     * 任务执行处理器
     */
    private TaskHandler taskHandler = null;
    /**
     * 命令组装器
     */
    private CommandAssembly commandAssembly = null;
    /**
     * 任务消息处理器
     */
    private OutHandlerMethod ohm = null;

    /**
     * 保活处理器
     */
    private KeepAliveHandler keepAliveHandler = null;

    /**
     * 全部默认初始化，自动查找配置文件
     */
    public CommandManagerImpl() {
        this(null);
    }

    /**
     * 指定任务池大小的初始化，其他使用默认
     *
     * @param size
     */
    public CommandManagerImpl(Integer size) {
        init(size);
    }

    /**
     * 初始化
     *
     * @param taskDao
     * @param taskHandler
     * @param commandAssembly
     * @param ohm
     * @param size
     */
    public CommandManagerImpl(TaskDao taskDao, TaskHandler taskHandler, CommandAssembly commandAssembly, OutHandlerMethod ohm, Integer size) {
        super();
        this.taskDao = taskDao;
        this.taskHandler = taskHandler;
        this.commandAssembly = commandAssembly;
        this.ohm = ohm;
        init(size);
    }

    /**
     * 初始化，如果几个处理器未注入，则使用默认处理器
     *
     * @param size
     */
    public void init(Integer size) {
        if (config == null) {
            log.error("配置文件加载失败！配置文件不存在或配置错误");
            return;
        }
        boolean iskeepalive = false;
        if (size == null) {
            size = config.getSize() == null ? 10 : config.getSize();
            iskeepalive = config.isKeepalive();
        }

        if (this.ohm == null) {
            this.ohm = new DefaultOutHandlerMethod();
        }

        if (this.taskDao == null) {
            this.taskDao = new TaskDaoImpl(size);
            //初始化保活线程
            if (iskeepalive) {
                keepAliveHandler = new KeepAliveHandler(taskDao);
                keepAliveHandler.start();
            }
        }

        if (this.taskHandler == null) {
            this.taskHandler = new TaskHandlerImpl(this.ohm);
        }

        if (this.commandAssembly == null) {
            this.commandAssembly = new CommandAssemblyImpl();
        }

    }

    public void setTaskDao(TaskDao taskDao) {
        this.taskDao = taskDao;
    }

    public void setTaskHandler(TaskHandler taskHandler) {
        this.taskHandler = taskHandler;
    }

    public void setCommandAssembly(CommandAssembly commandAssembly) {
        this.commandAssembly = commandAssembly;
    }

    public void setOhm(OutHandlerMethod ohm) {
        this.ohm = ohm;
    }

    /**
     * 是否已经初始化
     *
     * @param b 如果未初始化时是否初始化
     * @return
     */
    public boolean isInit(boolean b) {
        boolean ret = this.ohm == null || this.taskDao == null || this.taskHandler == null || this.commandAssembly == null;
        if (ret && b) {
            init(null);
        }
        return ret;
    }

    @Override
    public String start(String id, String command) {
        return start(id, command, false);
    }

    @Override
    public String start(String id, String command, boolean hasPath) {
        if (isInit(true)) {
            log.error("执行失败，未进行初始化或初始化失败！");
            return null;
        }
        if (id != null && command != null) {
            CommandTask task = taskHandler.process(id, hasPath ? command : config.getPath() + command);
            if (task != null) {
                int ret = taskDao.add(task);
                if (ret > 0) {
                    return task.getId();
                } else {
                    // 持久化信息失败，停止处理
                    taskHandler.stop(task.getProcess(), task.getThread());
                    if (config.isDebug())
                        log.error("持久化失败，停止任务！");
                }
            }
        }
        return null;
    }

    @Override
    public String start(Map<String, String> assembly) {
        // ffmpeg环境是否配置正确
        if (checkConfig()) {
            log.error("配置未正确加载，无法执行");
            return null;
        }
        // 参数是否符合要求
        if (assembly == null || assembly.isEmpty() || !assembly.containsKey("appName")) {
            log.error("参数不正确，无法执行");
            return null;
        }
        String appName = (String) assembly.get("appName");
        if (appName != null && "".equals(appName.trim())) {
            log.error("appName不能为空");
            return null;
        }
        assembly.put("ffmpegPath", config.getPath() + "ffmpeg");
        String command = commandAssembly.assembly(assembly);
        if (command != null) {
            return start(appName, command, true);
        }

        return null;
    }

    @Override
    public String start(String id, CommandBuilder commandBuilder) {
        // ffmpeg环境是否配置正确
        if (checkConfig()) {
            log.error("配置未正确加载，无法执行");
            return null;
        }
        String command = commandBuilder.get();
        if (command != null) {
            return start(id, command, true);
        }
        return null;
    }

    private boolean checkConfig() {
        return config == null;
    }

    @Override
    public boolean stop(String id) {
        if (id != null && taskDao.isHave(id)) {
            if (config.isDebug())
                log.info("正在停止任务：" + id);
            CommandTask tasker = taskDao.get(id);
            if (taskHandler.stop(tasker.getProcess(), tasker.getThread())) {
                taskDao.remove(id);
                return true;
            }
        }
        log.error("停止任务失败！id=" + id);
        return false;
    }

    /**
     * 结束所有的推流任务
     * @return
     */
    public static boolean stopAllPushTask(){
        final int[] res={0}; //标志是否关闭成功，0表示成功  1表示失败
        Collection<CameraPusher> pushers = CameraWorkerCache.PUSH_MAP.values();
        pushers.forEach(pusher->{
            try{
                pusher.stopPublish();
            }catch (Exception e){
                res[0]=-1;
                //如果通过API关闭失败，就强制使用cmd命令关闭打开的推流服务，避免占用系统资源
                if(ExecUtil.findProcess("ffmpeg.exe")) {
                    log.error("销毁推流服务ffmpeg服务失败,尝试使用命令行强制结束进程'ffmpeg.exe' ");
                    try {
                        ExecUtil.killProc("ffmpeg.exe");
                        res[0]=0;
                    } catch (IOException ex) {
                        log.error("强制结束进程失败,{}", ex.getMessage());
                    }
                }
            }
        });
        return res[0]==0;
    }

    @Override
    public int stopAll() {
        Collection<CommandTask> list = taskDao.getAll();
        Iterator<CommandTask> iter = list.iterator();
        CommandTask task = null;
        int index = 0;
        while (iter.hasNext()) {
            task = iter.next();
            if (taskHandler.stop(task.getProcess(), task.getThread())) {
                taskDao.remove(task.getId());
                index++;
            }
        }
        if (config.isDebug())
            log.info("停止了" + index + "个任务！");
        return index;
    }

    @Override
    public CommandTask query(String id) {
        return taskDao.get(id);
    }

    @Override
    public Collection<CommandTask> queryAll() {
        return taskDao.getAll();
    }

    @Override
    public void destroy() {
        if (keepAliveHandler != null) {
            //安全停止保活线程
            keepAliveHandler.interrupt();
        }
    }

}
