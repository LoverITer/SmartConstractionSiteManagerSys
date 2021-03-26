package cn.edu.xust.sdc.common;

import cn.edu.xust.sdc.core.DeviceInfo;

/**
 * SDC全局变量
 *
 * @author Administrator
 *
 */
public class GlobalVariant {

	public static final int MINSEARCHNUM = 1;
	public static boolean sdkInit = false; // SDK初始化

	public static final int MAX_DEVICES = 512;
	public static final int gLocalRTPPort = 5050;
	public static final int gLocalSSLPort = 5051;
	public static final int gLocalInitIPPort = 6060;

	public static final String strSuccess = "Success";
	public static final String strError = "Error";
	public static final String strFailedDetail = "Failed:ulIdentifyID lost";

	public static final int ONE = 1;
	public static final int ZERO = 0;
	public static final int NEGATIVE_ONE = -1;
	public static final int NEGATIVE_TWO = -2;

	public static final int linkModulePUAutologinMode = 0; // 主动登陆模式，初始化后前端设备主动登录到SDK，仅解码器支持
	public static final int linkModulePUMaualLoginMode = 1; // 手动登陆模式，需手动调用IVS_PU_Login登录前端设备
	public static final int linkModulePUBothLoginMode = 3; // 以上两种登陆模式都支持，仅IPC支持

	public static final String EMPTY = "";
	public static final String strDot = ".";

	public static final String pathCACert = "\\bin\\cert\\cacert.pem";
	public static final String pathCert = "\\bin\\cert\\cert.pem";
	public static final String pathKey = "\\bin\\cert\\key.pem";
	public static final String pathCryptStr = "11A6A68F4FCBBA3C";

	/*
	 * public static final String strTip = Res.string().getTip(); public static
	 * final String strMenuLogon = Res.string().getLogin(); public static final
	 * String strMenuLogout = Res.string().getLogout(); public static final String
	 * strTipLogon = Res.string().getTipLogon(); public static final String
	 * strTipCruiseIndex = Res.string().getTipCruiseIndex(); public static final
	 * String strTipPreIndex = Res.string().getTipPreIndex(); public static final
	 * String strTipUpdate = Res.string().getTipUpdate(); public static final String
	 * strTipSave = Res.string().getTipSave(); public static final String
	 * strTipCruiseNameOverLen = Res.string().getTipCruiseNameOverLen(); public
	 * static final String strTipCruisePointsOver =
	 * Res.string().getTipCruisePointsOver(); public static final String
	 * strTipNotNullPreName = Res.string().getTipNotNullPreName(); public static
	 * final String strTipPreNameOverLen = Res.string().getTipPreNameOverLen();
	 * public static final String strTipStayTimeLim =
	 * Res.string().getTipStayTimeLim(); public static final String
	 * strTipNotNullStayTime = Res.string().getTipNotNullStayTime(); public static
	 * final String strTipStayTimeErr = Res.string().getTipStayTimeErr(); public
	 * static final String addSuccess = Res.string().getTipaddSuccess(); public
	 * static final String updateSuccess = Res.string().getTipupdateSuccess();
	 * public static final String delSuccess = Res.string().getTipdelSuccess();
	 * public static final String delFail = Res.string().getTipdelFail();
	 */

	public static DeviceInfo[] gStruDeviceInfo;
	public static boolean changeLanguage = true;
	public static long lLoginID = -1;
	public static String chDeviceIP = "192.168.0.120";
	public static int lDevicePort = 6060;
	public static String chLoginUserName = "admin";
	public static String chLoginPwd = "HuaWei123";
	public static final int CHANNEL_ID = 101;
	public static int length;

	public static int indexCurrentDevice = 0;
	public static int countMaxDevice = 0;

}
