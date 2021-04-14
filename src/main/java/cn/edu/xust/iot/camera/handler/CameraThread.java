package cn.edu.xust.iot.camera.handler;

import cn.edu.xust.iot.camera.data.CameraWorkerCache;
import cn.edu.xust.iot.camera.push.CameraPusher;
import cn.edu.xust.iot.controller.CameraController;
import cn.edu.xust.iot.model.CameraInfoModel;
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
		private CameraInfoModel cameraInfoModel;


		public MyRunnable(CameraInfoModel cameraInfoModel) {
			this.cameraInfoModel = cameraInfoModel;
		}


		@Override
		public void run() {
			// 直播流
			try {
				log.info("开始异步线程推流");
				CameraWorkerCache.START_MAP.put(cameraInfoModel.getToken(), cameraInfoModel);
				// 执行转流推流任务
				CameraPusher pusher = new CameraPusher(cameraInfoModel);
				CameraWorkerCache.PUSH_MAP.put(cameraInfoModel.getToken(), pusher);
				pusher.publish();
			} catch (Exception e) {
				CameraWorkerCache.START_MAP.remove(cameraInfoModel.getToken());
				CameraController.WORK_MAP.remove(cameraInfoModel.getToken());
				CameraWorkerCache.PUSH_MAP.remove(cameraInfoModel.getToken());
				log.error("推流发生错误,详细信息：{}",e.getMessage());
			}
		}
	}
}
