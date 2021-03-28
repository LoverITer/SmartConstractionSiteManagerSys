package cn.edu.xust.iot.sdc.core;

import edu.umd.cs.findbugs.annotations.SuppressFBWarnings;

/**
 * SDK接口参数：设备信息
 *
 * @author HuangXin
 *
 */
@SuppressFBWarnings({ "UUF_UNUSED_PUBLIC_OR_PROTECTED_FIELD", "URF_UNREAD_PUBLIC_OR_PROTECTED_FIELD" })
public class DeviceInfo {

	/**
	 * 设备编号
	 */
	public int iDeviceIndex;
	/**
	 * 设备登陆的ID
	 */
	public long lLoginID;
	/**
	 * erserved
	 */
	public long dwDevSoftVer;
	/**
	 * 实时播放
	 */
	public long lRealPlayHwnd;
	/**
	 * 本地节点名
	 */
	public String chLocalNodeName; // local device node
	/**
	 * 设备名称
	 */
	public String chDeviceName; // device name
	/**
	 * 设备IP
	 */
	public String chDeviceIP; // device IP: IP,pppoe address, or network gate address, etc
	/**
	 * 登陆用户名
	 */
	public String chLoginUserName; // login user name
	/**
	 * 用户密码
	 */
	public String chLoginPwd; // pwd
	public String chDeviceMultiIP; // multi-cast group address

	public String chSerialNumber; // SN
	public int iDeviceChanNum; // channel numder
	public int iVideoChanNum; // channel numder-add
	public int iLinkMethod; // link method-add
	public int iStreamtype; // stream type-add
	public int iVideotype; // video type-add
	public int iEncryptiontype; // encryption type-add
	public String chEncrytionKey; // encrytion key-add
	public int iMediaCallBack; // media callBack-add
	public int iCallbackType; // callback type-add

	public String chLocalAddress; // local address-add
	public int iIsNeedActive; // bool need active-add
	public String chBroadcastAddress; // broadcast address-add

	public int iStartChan; // start channel number
	public int iDeviceType; // device type
	public int iDiskNum; // HD number
	public long lDevicePort; // port number
	public int iAlarmInNum; // alarm in number
	public int iAlarmOutNum; // alarm out number
	public int iAudioNum; // voice talk number
	public int iIPChanNum; // max IP channel number

	public boolean bCycle; // if this device is on cycle recording
	public boolean bPlayDevice; // will be added later
	public boolean bVoiceTalk; // on voice talkor not

	public long lFortifyHandle; // on guard handle
	public boolean bAlarm; // whether there is alarm
	public int iDeviceLoginType; // register mode 0 - fix IP 1- IPSERVER mode 2 - domain name
	public long dwImageType; // device status icon
	public boolean bIPRet; // support IP conection
	public int iEnableChanNum; // valid channel number
	public int bDVRLocalAllRec; // local recording

	public long lFirstEnableChanIndex; // first enabled channel index
	public long lTranHandle; // 232 transparent channel handle
	public long lMaxStreamNum; // 最大视频流
	public long lCruiseTrackNum; // 最大巡航规矩数目
	public long lPresetNum; // 最大预置位数目
	public byte byZeroChanNum; // Zero channel number
	public byte byMainProto; // main stream protocol type 0-Private, 1-rtsp
	public byte bySubProto; // sub stream protocol type -Private, 1-rtsp
	public byte bySupport; // ability
	public long ulFedVoiceHandle;
	public ChannelInfo[] struChanInfo;

	public String chMulticastIP; // device name
	public DeviceInfo pNext;
	public ChannelInfo[] struZeroChan;

	public DeviceInfo() {
		lRealPlayHwnd = -1;
		iDeviceIndex = -1;
		lLoginID = -1;
		dwDevSoftVer = 0;
		chLocalNodeName = "";
		chDeviceName = "";
		chDeviceIP = "";

		chLoginUserName = "";
		chLoginPwd = "0";
		chDeviceMultiIP = "";
		chSerialNumber = "";
		iDeviceChanNum = -1;
		chEncrytionKey = "";

		iStartChan = 0;
		iDeviceType = 0;
		iDiskNum = 0;
		lDevicePort = 6060;
		iAlarmInNum = 0;
		iAlarmOutNum = 0;
		iIPChanNum = 0;

		bCycle = false;
		bPlayDevice = false;
		bVoiceTalk = false;

		lFortifyHandle = -1;
		bAlarm = false;
		iDeviceLoginType = 0;
		dwImageType = 1;
		bIPRet = false;
		pNext = null;

		lFirstEnableChanIndex = 0;
		lTranHandle = -1;
		lMaxStreamNum = 1;
		lCruiseTrackNum = 0;
		lPresetNum = 0;
		byZeroChanNum = 0;
		ulFedVoiceHandle = 0;

		struChanInfo = new ChannelInfo[64];
		struZeroChan = new ChannelInfo[16];
	}
}
