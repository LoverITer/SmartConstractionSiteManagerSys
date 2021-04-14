package cn.edu.xust.iot.service;

/**
 * 实现SDC摄像机的初始化、登陆、退出等功能
 *
 * @author HuangXin
 * @since 2021/03/25 13:29
 */
public interface IBusinessUserService {

	/**
	 * 关闭并清除摄像机SDK
	 * 
	 * @return
	 */
	boolean close();

	/**
	 * 初始化摄像机SDK
	 *
	 * @return
	 */
	boolean init();

	/**
	 * 使用用户名密码登陆摄像机
	 *
	 * @return
	 */
	long login();

	/**
	 * 退出登陆摄像机
	 *
	 * @return
	 */
	boolean logout();

}
