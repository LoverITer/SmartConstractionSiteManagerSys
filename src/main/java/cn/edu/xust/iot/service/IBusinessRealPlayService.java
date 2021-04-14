package cn.edu.xust.iot.service;

/**
 * 实现SDC相机的实时监控录像功能
 *
 * @author HuangXin
 * @since 2021/03/26 17:10
 */
public interface IBusinessRealPlayService {

	/**
	 * 开启摄像头实况播放
	 *
	 * @param uid 登录成功时 返回的用户ID
	 * @return
	 */
	long play(long uid);

	/**
	 * 停止摄像投实况播放
	 *
	 * @return
	 */
	boolean stop();

	/**
	 * 停止所有实况播放
	 *
	 * @param uid 登录成功时 返回的用户ID
	 * @return
	 */
	boolean stopAll(long uid);

}
