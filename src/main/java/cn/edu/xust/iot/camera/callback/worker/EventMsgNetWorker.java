package cn.edu.xust.iot.camera.callback.worker;

import cn.edu.xust.iot.camera.CommandManagerImpl;
import cn.edu.xust.iot.camera.callback.EventCallBack;
import cn.edu.xust.iot.camera.callback.EventCallBackType;
import cn.edu.xust.iot.camera.data.CommandTask;
import cn.edu.xust.iot.camera.data.TaskEventMsg;

import java.io.IOException;
import java.net.URL;
import java.net.URLConnection;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * 事件消息独立发送线程
 * 
 * @author eguid
 *
 */
public class EventMsgNetWorker extends Thread implements EventCallBack {

	protected static Queue<TaskEventMsg> queue = null;// 一个事件消息队列，发送失败的事件消息将会进入队列队尾等待下次再次发送

	// 一个网络库，用于快速发送http消息
	private int timeout = 300;// 默认300毫秒

	public EventMsgNetWorker(int timeout) {
		super();
		this.timeout = timeout;
		queue = new ConcurrentLinkedQueue<>();
	}

	@Override
	public void run() {
		for (;;) {
			try {
				while (queue.peek() != null) {
					TaskEventMsg t = queue.poll();
					// 借助网络库发送该消息
					String url = CommandManagerImpl.config.getCallback();
					if (reqGET(url)) {
						System.err.println("发送成功");
					} else {
						System.err.println("发送失败");
						// 发送失败的事件消息将会进入队列队尾等待下次再次发送
						queue.offer(t);
					}
				}
			} catch (Exception e) {

			}
		}

	}

	/**
	 * 发送get请求
	 */
	private boolean reqGET(String url) {
		URL realUrl;
//		PrintWriter out = null;
		try {
			realUrl = new URL(url);
			// 打开和URL之间的连接
			URLConnection connection = realUrl.openConnection();
			// 设置通用的请求属性
			connection.setUseCaches(false);
			connection.setConnectTimeout(timeout);
			connection.setRequestProperty("accept", "*/*");
			connection.setRequestProperty("connection", "Keep-Alive");
			connection.setRequestProperty("user-agent", "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1;SV1)");
			connection.setDoOutput(false);
			connection.setDoInput(false);
			connection.connect();
			return true;
		} catch (IOException e) {
			return false;
		}
	}

	@Override
	public boolean callback(EventCallBackType ecbt, CommandTask tasker) {
		return queue.add(new TaskEventMsg(ecbt, tasker));
	}

}
