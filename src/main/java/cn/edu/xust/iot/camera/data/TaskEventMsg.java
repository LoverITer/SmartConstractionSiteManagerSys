package cn.edu.xust.iot.camera.data;


import cn.edu.xust.iot.camera.callback.EventCallBackType;

/**
 * 命令行事件消息
 * @author eguid
 *
 */
public class TaskEventMsg {

	EventCallBackType ecbt;
	CommandTask tasker;

	public TaskEventMsg(EventCallBackType ecbt, CommandTask tasker) {
		super();
		this.ecbt = ecbt;
		this.tasker = tasker;
	}

	public EventCallBackType getEcbt() {
		return ecbt;
	}

	public void setEcbt(EventCallBackType ecbt) {
		this.ecbt = ecbt;
	}

	public CommandTask getTasker() {
		return tasker;
	}

	public void setTasker(CommandTask tasker) {
		this.tasker = tasker;
	}

	@Override
	public String toString() {
		return "CommandEventMsg [ecbt=" + ecbt + ", tasker=" + tasker + "]";
	}

}
