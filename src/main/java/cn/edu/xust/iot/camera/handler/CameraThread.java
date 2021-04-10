package cn.edu.xust.iot.camera.handler;

import cn.edu.xust.iot.camera.CameraWorkerCache;
import cn.edu.xust.iot.camera.pojo.CameraInfo;
import cn.edu.xust.iot.camera.push.CameraPusher;
import cn.edu.xust.iot.controller.CameraController;
import lombok.extern.slf4j.Slf4j;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * @Title CameraThread.java
 * @description TODO
 * @time 2019年12月16日 上午9:32:43
 * @author wuguodong
 **/
@Slf4j
public class CameraThread {

	public static class MyRunnable implements Runnable {

		// 创建线程池
		public static ExecutorService executor = Executors.newCachedThreadPool();
		/**
		 * 摄像机信息
		 */
		private CameraInfo cameraInfo;


		public MyRunnable(CameraInfo cameraInfo) {
			this.cameraInfo = cameraInfo;
		}


		@Override
		public void run() {
			// 直播流
			try {
				log.info("开始异步线程推流");
				CameraWorkerCache.START_MAP.put(cameraInfo.getToken(), cameraInfo);
				// 执行转流推流任务
				CameraPusher pusher = new CameraPusher(cameraInfo);
				CameraWorkerCache.PUSH_MAP.put(cameraInfo.getToken(), pusher);
				pusher.publish();
			} catch (Exception e) {
				CameraWorkerCache.START_MAP.remove(cameraInfo.getToken());
				CameraController.WORK_MAP.remove(cameraInfo.getToken());
				CameraWorkerCache.PUSH_MAP.remove(cameraInfo.getToken());
				log.error("推流发生错误,详细信息：{}",e.getMessage());
			}
		}
	}
}
