package cn.edu.xust.iot.utils;


import cn.edu.xust.iot.camera.data.CommandTask;
import cn.edu.xust.iot.camera.handler.OutHandler;
import cn.edu.xust.iot.camera.handler.OutHandlerMethod;
import lombok.extern.slf4j.Slf4j;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 命令行操作工具类
 *
 * @author HuangXin
 */
@Slf4j
public class ExecUtil {

    /**
     * 执行命令行并获取进程
     *
     * @param cmd
     * @return
     * @throws IOException
     */
    public static Process exec(String cmd) throws IOException {
        log.info("执行命令：{}",cmd);
        Runtime runtime = Runtime.getRuntime();
        return runtime.exec(cmd);
    }

    /**
     * 销毁进程
     *
     * @param process
     * @return
     */
    public static boolean stop(Process process) {
        if (process != null) {
            process.destroy();
            return true;
        }
        return false;
    }

    /**
     * 销毁输出线程
     *
     * @param outHandler
     * @return
     */
    public static boolean stop(Thread outHandler) {
        if (outHandler != null && outHandler.isAlive()) {
            outHandler.stop();
            outHandler.destroy();
            return true;
        }
        return false;
    }

    /**
     * 销毁
     *
     * @param task
     */
    public static void stop(CommandTask task) {
        if (task != null) {
            stop(task.getThread());
            stop(task.getProcess());
        }
    }

    /**
     * 创建命令行任务
     *
     * @param id
     * @param command
     * @return
     * @throws IOException
     */
    public static CommandTask createTask(String id, String command, OutHandlerMethod ohm) throws IOException {
        // 执行本地命令获取任务主进程
        Process process = exec(command);
        // 创建输出线程
        OutHandler outHandler = OutHandler.create(process.getErrorStream(), id, ohm);

        return new CommandTask(id, command, process, outHandler);
    }

    /**
     * 中断故障缘故重启
     *
     * @param task
     * @return
     * @throws IOException
     */
    public static CommandTask restart(CommandTask task) throws IOException {
        if (task != null) {
            String id = task.getId(), command = task.getCommand();
            OutHandlerMethod ohm = null;
            if (task.getThread() != null) {
                ohm = task.getThread().getMessageHandler();
            }

            //安全销毁命令行进程和输出子线程
            stop(task);
            // 执行本地命令获取任务主进程
            Process process = exec(command);
            task.setProcess(process);
            // 创建输出线程
            OutHandler outHandler = OutHandler.create(process.getErrorStream(), id, ohm);
            task.setThread(outHandler);
        }
        return task;
    }

    /**
     * 强制通过进程镜像名(比如nginx.exe)命令杀死进程
     *
     * @param processName
     * @throws IOException
     */
    public static void killProc(String processName) throws IOException {
        log.info("关闭应用程序：" + processName);
        if (!CommonUtils.isNull(processName)) {
            executeCmd("taskkill /F /IM " + processName);
        }
    }

	/**
	 * 模拟在window cmd窗口执行命令
	 * @param command  Windows执行命令输出
	 * @return
	 * @throws IOException
	 */
    public static String executeCmd(String command) throws IOException {
        log.info("执行Windows命令: " + command);
        Runtime runtime = Runtime.getRuntime();
        Process process = runtime.exec("cmd /c " + command);
        BufferedReader br = new BufferedReader(new InputStreamReader(process.getInputStream(), "UTF-8"));
        String line = null;
        StringBuilder builder = new StringBuilder();
        while ((line = br.readLine()) != null) {
			log.info(line);
			builder.append(line);
		}
		String winOutput = builder.toString();
        log.info("Windows执行命令输出：{}",winOutput);
		return winOutput;
    }

	/**
	 * 判断进程是否还运行着
	 * @param processName
	 * @return
	 */
	public static boolean findProcess(String processName){
    	BufferedReader br=null;
    	try{
			Process process = Runtime.getRuntime().exec("tasklist -fi " + '"' + "imagename eq " + processName + '"');
			br=new BufferedReader(new InputStreamReader(process.getInputStream()));
			String line=null;
			while((line=br.readLine())!=null){
				if(line.contains(processName)){
					return true;
				}
			}
			return false;
		}catch (Exception e){
            log.error("查找进程出错,{}",e.getMessage());
            return false;
		}finally {
    		if(br!=null){
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}

}