package cn.edu.xust.iot.sdc.service.impl;

import cn.edu.xust.iot.sdc.LibraryPath;
import cn.edu.xust.iot.sdc.common.GlobalVariant;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.sdc.core.HWPuSDK.PU_CERT_FILE_PATH_PARA_S;
import cn.edu.xust.iot.sdc.service.IBussinessUser;
import com.sun.jna.platform.win32.WinDef.ULONG;
import lombok.extern.slf4j.Slf4j;

import java.nio.ByteBuffer;

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
			buff.put(LibraryPath.getCertificatePath(LibraryPath.CertificateType.CERT_CA_CERT).getBytes());
			ByteBuffer buff2 = ByteBuffer.allocate(512);
			buff2.put(LibraryPath.getCertificatePath(LibraryPath.CertificateType.CERT_CERT).getBytes());
			ByteBuffer buff3 = ByteBuffer.allocate(512);
			buff3.put(LibraryPath.getCertificatePath(LibraryPath.CertificateType.CERT_KEY).getBytes());
			ByteBuffer buff4 = ByteBuffer.allocate(512);
			buff4.put(GlobalVariant.pathCryptStr.getBytes());
			filePath.szCACertFilePath = buff.array();
			filePath.szCertFilePath = buff2.array();
			filePath.szKeyFilePath = buff3.array();
			filePath.szKeyPasswd = buff4.array();
		} catch (Exception e) {
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
	 * chDeviceIP      摄像机默认IP,默认192.168.0.120
	 * lDeviceport     摄像机默认打开的端口,默认6060
	 * chLoginUserName 默认登陆用户名,默认admin
	 * chLoginPwd      默认登陆密码，默认HuaWei123
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
		if (lUserID >= 1) {
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
		if (lUserID >= 1) {
			GlobalVariant.lLoginID = (int) lUserID;
		}
        log.debug("IVS_PU_Login {}",lUserID>=1?"Success!":"Fail!");
		return lUserID;
	}

	@Override
	public boolean logout() {
		boolean logOutRes = HWPuSDK.INSTANCE.IVS_PU_Logout(new ULONG(GlobalVariant.lLoginID));
		log.debug("IVS_PU_Logout {}", logOutRes ? "Success" : "Fail");
		if (!logOutRes) {
			showErrMsg();
		} else {
			GlobalVariant.lLoginID = -1;
		}
		return logOutRes;
	}

}
