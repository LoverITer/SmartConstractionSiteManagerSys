package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.sdc.common.GlobalVariant;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.service.IBusinessRealPlayService;
import com.sun.jna.Pointer;
import com.sun.jna.platform.win32.WinDef.ULONG;
import lombok.extern.slf4j.Slf4j;

/**
 * @author HuangXin
 * @since 2021/03/26 17:28
 */
@Slf4j
public class BusinessRealPlayServiceImpl implements IBusinessRealPlayService {

	public static long ret = 0l;
	public static boolean isPlaying = false;
	public static HWPuSDK.pfRealDataCallBack callBack = null;

	@Override
	public long play(long uid) {
		try {
			HWPuSDK.PU_REAL_PLAY_INFO_S.ByReference info = new HWPuSDK.PU_REAL_PLAY_INFO_S.ByReference();
//			info.ulChannelId = new WinDef.ULONG(101);
//			info.hPlayWnd = new WinDef.HWND(Native.getComponentPointer(RealPlayPanel));
//			info.enStreamType = boxCodeStreamtype.getSelectedIndex();
//			info.enVideoType = boxVideoStreamType.getSelectedIndex();
//			info.enProtocolType = boxLinkway.getSelectedIndex();
//			info.enMediaCallbackType = HWPuSDK.PU_MEDIA_CALLBACK_TYPE_E.PU_MEDIA_CALLBACK_TYPE_RTP;
//			info.bKeepLive = boxKeepAlive.getSelectedIndex() == 0 ? false : true;

			Pointer usrData = new Pointer(0);

			if (info == null) {
				log.error("Error: PU_REAL_PLAY_INFO_S 参数有误，请核对 :{}", info);
				return 0;
			}
			ULONG id = HWPuSDK.INSTANCE.IVS_PU_RealPlay(new ULONG(uid), info, callBack, usrData);
			ret = id.longValue();
			log.debug("start real play {}", ret != 0 ? "Success" : "Fail");
			if (0 != ret) {
				//GlobalVariant.gStruDeviceInfo.lRealPlayHwnd = ret;
				isPlaying = true;
				log.debug("IVS_PU_RealPlay Success!");
			} else {
				log.debug("IVS_PU_RealPlay Fail!");
			}
		} catch (Throwable e) {
			log.debug("IVS_PU_RealPlay Fail!");
			BusinessUserServiceImpl.showErrMsg();
			e.printStackTrace();
		}

		return ret;
	}

	@Override
	public boolean stop() {
		try {
			boolean ret = HWPuSDK.INSTANCE.IVS_PU_StopRealPlay(new ULONG(GlobalVariant.lLoginID),
					new ULONG(BusinessRealPlayServiceImpl.ret));
			HWPuSDK.INSTANCE.IVS_PU_StopAllRealPlay(new ULONG(GlobalVariant.lLoginID));
			if (ret) {
				isPlaying = false;
				log.debug("IVS_PU_StopRealPlay Success![DeviceIP={}]", GlobalVariant.chDeviceIP);
			} else {
				log.debug("IVS_PU_StopRealPlay Fail![DeviceIP={}]", GlobalVariant.chDeviceIP);
				BusinessUserServiceImpl.showErrMsg();
			}
			return ret;
		} catch (Throwable e) {
			BusinessUserServiceImpl.showErrMsg();
			log.debug("IVS_PU_StopRealPlay Success![DeviceIP={}]", GlobalVariant.chDeviceIP);
			e.printStackTrace();
		}
		return false;
	}

	@Override
	public boolean stopAll(long uid) {
		boolean isOK = false;
		try {
			isOK = HWPuSDK.INSTANCE.IVS_PU_StopAllRealPlay(new ULONG(uid));
			if (isOK) {
				log.debug("IVS_PU_StopAllRealPlay Success![DeviceIP={}]", GlobalVariant.chDeviceIP);
			} else {
				log.debug("IVS_PU_StopAllRealPlay Fail![DeviceIP={}]", GlobalVariant.chDeviceIP);
				BusinessUserServiceImpl.showErrMsg();
			}
		} catch (Throwable e) {
			log.debug("IVS_PU_StopAllRealPlay Fail![DeviceIP={}]", GlobalVariant.chDeviceIP);
			e.printStackTrace();
		}

		return isOK;
	}

}
