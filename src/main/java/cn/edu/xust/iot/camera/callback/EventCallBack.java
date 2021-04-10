package cn.edu.xust.iot.camera.callback;

import cn.edu.xust.iot.camera.data.CommandTask;

/**
 * 事件回调
 * @author eguid
 *
 */
public interface EventCallBack {
	
	/**
	 * 命令行执行开始事件
	 * @param t -事件类型
	 * @param task -任务信息
	 */
	boolean callback(EventCallBackType t, CommandTask task);
}
