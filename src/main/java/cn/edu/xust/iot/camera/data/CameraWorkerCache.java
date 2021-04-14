package cn.edu.xust.iot.camera.data;

import cn.edu.xust.iot.camera.push.CameraPusher;
import cn.edu.xust.iot.model.CameraInfoModel;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;


/**
 * @Title CameraWorkerCacheUtil.java
 * @description 推流缓存信息
 * @time 2019年12月17日 下午3:12:45
 * @author wuguodong
 **/
public final class CameraWorkerCache {
	/*
	 * 保存已经开始推的流
	 */
	public static final Map<String, CameraInfoModel> START_MAP = new ConcurrentHashMap<>();

	/*
	 * 保存push
	 */
	public static final Map<String, CameraPusher> PUSH_MAP = new ConcurrentHashMap<>();
	/*
	 * 保存服务启动时间
	 */
	public static long START_TIME;

}
