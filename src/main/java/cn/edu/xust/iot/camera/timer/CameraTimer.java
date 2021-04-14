package cn.edu.xust.iot.camera.timer;

import cn.edu.xust.iot.camera.conf.CameraRTSPToHttpFlvConfig;
import cn.edu.xust.iot.camera.data.CameraWorkerCache;
import cn.edu.xust.iot.controller.CameraController;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Set;
import java.util.Timer;
import java.util.TimerTask;

/**
 * @Title TimerUtil.java
 * @description 定时任务
 * @Time 2019年12月16日 下午3:10:08
 * @author wuguodong
 **/
@Component
@Slf4j
public class CameraTimer implements CommandLineRunner {


	// 配置文件bean
	@Autowired
	private CameraRTSPToHttpFlvConfig config;

	public static Timer timer;

	@Override
	public void run(String... args) {
		timer = new Timer("TimeTimer");
		timer.schedule(new TimerTask() {
			@Override
			public void run() {
				log.info("定时任务  当前有" + CameraController.WORK_MAP.size() + "个推流任务正在进行推流");
				// 管理缓存
				if (null != CameraWorkerCache.START_MAP && 0 != CameraWorkerCache.START_MAP.size()) {
					Set<String> keys = CameraWorkerCache.START_MAP.keySet();
					for (String key : keys) {
						try {
							// 最后打开时间
							long openTime = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss")
									.parse(CameraWorkerCache.START_MAP.get(key).getOpenTime()).getTime();
							// 当前系统时间
							long newTime = new Date().getTime();

							// 如果通道使用人数为0，则关闭推流
							if (CameraWorkerCache.START_MAP.get(key).getCount() == 0) {
								log.info("定时任务 当前设备使用人数为0结束推流 设备信息：[ip：" + CameraWorkerCache.START_MAP.get(key).getIp()
										+ " channel:" + CameraWorkerCache.START_MAP.get(key).getChannel() + " stream:"
										+ CameraWorkerCache.START_MAP.get(key).getStream() + " startTime:"
										+ CameraWorkerCache.START_MAP.get(key).getStartTime() + " endTime:"
										+ CameraWorkerCache.START_MAP.get(key).getEndTime() + " rtsp:"
										+ CameraWorkerCache.START_MAP.get(key).getRtsp() + " url:"
										+ CameraWorkerCache.START_MAP.get(key).getUrl() + "]");
								//当使用人数为的时候停止推送
								CameraWorkerCache.PUSH_MAP.get(key).stopPublish();
							} else if (-1!=Integer.parseInt(config.getKeepalive())&&
									null == CameraWorkerCache.START_MAP.get(key).getStartTime() &&
									(newTime - openTime) / 1000 / 60 >= Integer.parseInt(config.getKeepalive())) {
								log.info("定时任务 当前设备使用时间超时结束推流 设备信息：[ip:" + CameraWorkerCache.START_MAP.get(key).getIp()
										+ " channel:" + CameraWorkerCache.START_MAP.get(key).getChannel() + " stream:"
										+ CameraWorkerCache.START_MAP.get(key).getStream() + " startTime:"
										+ CameraWorkerCache.START_MAP.get(key).getStartTime() + " endTime:"
										+ CameraWorkerCache.START_MAP.get(key).getEndTime() + " rtsp:"
										+ CameraWorkerCache.START_MAP.get(key).getRtsp() + " url:"
										+ CameraWorkerCache.START_MAP.get(key).getUrl() + "]");
							}
						} catch (ParseException e) {
							e.printStackTrace();
						}
					}
				}
			}
		}, 1, 1000 * 60);
	}
}
