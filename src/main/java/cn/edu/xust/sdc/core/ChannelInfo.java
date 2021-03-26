package cn.edu.xust.sdc.core;

import edu.umd.cs.findbugs.annotations.SuppressFBWarnings;

/**
 * SDK接口参数：通道信息
 *
 * @author HuangXin
 *
 */
@SuppressFBWarnings({ "URF_UNREAD_FIELD", "UUF_UNUSED_FIELD" })
public class ChannelInfo {
	/**
	 * device index
	 */
	int iDeviceIndex;
	/**
	 * channel index
	 */
	int iChanIndex;
	/**
	 * channel name
	 */
	String chChanName;
	/**
	 * network protocol
	 */
	long dwProtocol;
	/**
	 * 码流类型
	 */
	long lStreamType;

	/**
	 * resolution 分辨率
	 */
	int iPicResolution;
	/**
	 * image quality
	 */
	int iPicQuality;
	/**
	 * preview handle
	 */
	long lRealHandle;
	/**
	 * manual record
	 */
	boolean bLocalManualRec;
	/**
	 * alarm
	 */
	boolean bAlarm;
	/**
	 * enable
	 */
	boolean bEnable;
	/**
	 * channel status icon
	 */
	long dwImageType;
	/**
	 * ip addr of IP channel
	 */
	String chAccessChanIP;
	/**
	 * 
	 */
	int playHWNDIndex;
	/**
	 * KeepLive
	 */
	boolean bKeepLive;
	/**
	 * Local IP
	 */
	String chLocalIP;
	/**
	 * video type: 0-视频流 1-音频流 2-复合流 3-录像流
	 */
	int iVideoType;

	/**
	 * 加密类型，只支持AES加密
	 */
	int enMediaCryptoType;
	/**
	 * 加密密钥
	 */
	String szMediaCrypto;
	/**
	 * 是否回调收流
	 */
	boolean bCallback;
	/**
	 * 回调类型：0:RTP解密 1:RTP不解密 2:Frame 3:YUV
	 */
	int enMediaCallbackType;

	ChannelInfo pNext;

	ChannelInfo() {
		iDeviceIndex = -1;
		iChanIndex = -1;
		chChanName = "";
		dwProtocol = 0;
		lStreamType = 0;

		iPicResolution = 0;
		iPicQuality = 2;

		lRealHandle = -1;
		bLocalManualRec = false;
		bAlarm = false;
		bEnable = false;
		dwImageType = 3;
		chAccessChanIP = "";
		playHWNDIndex = -1;
		bKeepLive = false;
		chLocalIP = "";
		iVideoType = 0;
		enMediaCryptoType = -1;
		enMediaCallbackType = -1;

		pNext = null;
	}
}
