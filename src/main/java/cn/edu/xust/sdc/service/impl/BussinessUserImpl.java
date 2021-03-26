package cn.edu.xust.sdc.service.impl;

import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;

import com.sun.jna.platform.win32.WinDef.ULONG;

import cn.edu.xust.sdc.common.GlobalVariant;
import cn.edu.xust.sdc.core.HWPuSDK;
import cn.edu.xust.sdc.core.HWPuSDK.PU_CERT_FILE_PATH_PARA_S;
import cn.edu.xust.sdc.service.IBussinessUser;
import lombok.extern.slf4j.Slf4j;

/**
 * 实现SDC摄像机的初始化、登陆、退出等功能
 *
 * @author HuangXin
 * @since 2021/03/25 13:27
 */
@Slf4j
public class BussinessUserImpl implements IBussinessUser {
	public static long lUserID = -1;

	/**
	 * 显示错误信息
	 */
	public static void showErrMsg() {
		long errorCode = HWPuSDK.INSTANCE.IVS_PU_GetLastError();
		StringBuilder errMsg = new StringBuilder("error code : ");
		errMsg.append(errorCode);
		errMsg.append(", error message : ");
		errMsg.append(HWPuSDK.INSTANCE.IVS_PU_GetErrorMsg(errorCode));
		log.error(errMsg.toString());
	}

	@Override
	public boolean close() {
		boolean res = HWPuSDK.INSTANCE.IVS_PU_Cleanup();
		log.info("IVS_PU_Cleanup {}!", res ? "Success" : "Fail");
		return res;
	}

	@Override
	public boolean init() {
		log.info("开始初始化SDK资源");
		PU_CERT_FILE_PATH_PARA_S.ByReference filePath = new PU_CERT_FILE_PATH_PARA_S.ByReference();
		ByteBuffer buff = ByteBuffer.allocate(512);
		try {
			buff.put((new File(".").getCanonicalPath() + "\\bin\\cert\\cacert.pem").getBytes());
			ByteBuffer buff2 = ByteBuffer.allocate(512);
			buff2.put((new File(".").getCanonicalPath() + "\\bin\\cert\\cert.pem").getBytes());
			ByteBuffer buff3 = ByteBuffer.allocate(512);
			buff3.put((new File(".").getCanonicalPath() + "\\bin\\cert\\key.pem").getBytes());
			ByteBuffer buff4 = ByteBuffer.allocate(512);
			buff4.put(GlobalVariant.pathCryptStr.getBytes());
			filePath.szCACertFilePath = buff.array();
			filePath.szCertFilePath = buff2.array();
			filePath.szKeyFilePath = buff3.array();
			filePath.szKeyPasswd = buff4.array();
		} catch (IOException e) {
			log.error(e.getMessage());
		}
		boolean rlt = HWPuSDK.INSTANCE.IVS_PU_InitEx(new ULONG(GlobalVariant.linkModulePUMaualLoginMode), "",
				new ULONG(GlobalVariant.gLocalRTPPort), new ULONG(GlobalVariant.gLocalSSLPort), filePath);
		log.info("IVS_PU_InitEx {}!", rlt ? "Success" : "Fail");
		return rlt;
	}

	/**
	 * 使用默认参数登陆摄像机
	 *
	 * @param chDeviceIP      摄像机默认IP,默认192.168.0.120
	 * @param lDeviceport     摄像机默认打开的端口,默认6060
	 * @param chLoginUserName 默认登陆用户名,默认admin
	 * @param chLoginPwd      默认登陆密码，默认HuaWei123
	 * @return 用户ID
	 */
	@Override
	public long login() {
		System.out.println(GlobalVariant.chDeviceIP);
		System.out.println(GlobalVariant.lDevicePort);
		System.out.println(GlobalVariant.chLoginUserName);
		System.out.println(GlobalVariant.chLoginPwd);
		lUserID = HWPuSDK.INSTANCE.IVS_PU_Login(GlobalVariant.chDeviceIP, new ULONG(GlobalVariant.lDevicePort),
				GlobalVariant.chLoginUserName, GlobalVariant.chLoginPwd);
		if (lUserID == 1) {
			GlobalVariant.lLoginID = (int) lUserID;
		}

		return lUserID;
	}

	/**
	 * 使用非默认参数登陆摄像机
	 *
	 * @param chDeviceIP      摄像机IP
	 * @param lDeviceport     摄像机打开的端口
	 * @param chLoginUserName 登陆用户名
	 * @param chLoginPwd      登陆密码
	 * @return 用户ID
	 */
	public long login(String chDeviceIP, Integer lDeviceport, String chLoginUserName, String chLoginPwd) {
		if (chDeviceIP == null || "".equals(chDeviceIP)) {
			chDeviceIP = GlobalVariant.chDeviceIP;
		}
		if (lDeviceport == null || lDeviceport <= 0) {
			lDeviceport = GlobalVariant.lDevicePort;
		}
		if (chLoginUserName == null || "".equals(chLoginUserName)) {
			chLoginUserName = GlobalVariant.chLoginUserName;
		}
		if (chLoginPwd == null || "".equals(chLoginPwd)) {
			chLoginPwd = GlobalVariant.chLoginPwd;
		}
		log.debug("登陆摄像机[ip={}]", chDeviceIP);
		log.debug("登陆摄像机[port={}]", lDeviceport);
		log.debug("登陆摄像机[username={}]", chLoginUserName);
		log.debug("登陆摄像机[password={}]", chLoginPwd);
		lUserID = HWPuSDK.INSTANCE.IVS_PU_Login(chDeviceIP, new ULONG(lDeviceport), chLoginUserName, chLoginPwd);
		if (lUserID == 1) {
			GlobalVariant.lLoginID = (int) lUserID;
		}

		return lUserID;
	}

	@Override
	public boolean logout() {
		boolean iVal = HWPuSDK.INSTANCE.IVS_PU_Logout(new ULONG(GlobalVariant.lLoginID));
		if (!iVal) {
			showErrMsg();
		} else {
			GlobalVariant.lLoginID = -1;
		}
		return iVal;
	}

}
