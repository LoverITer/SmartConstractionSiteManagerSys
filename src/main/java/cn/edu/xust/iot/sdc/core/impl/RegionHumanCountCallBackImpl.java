package cn.edu.xust.iot.sdc.core.impl;

import cn.edu.xust.iot.conf.ApplicationContextHolder;
import cn.edu.xust.iot.mapper.CameraMapper;
import cn.edu.xust.iot.model.entity.Camera;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.service.IRegionHumanCountService;
import cn.edu.xust.iot.service.impl.HWPuSDKServiceImpl;
import cn.edu.xust.iot.utils.CommonUtils;
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.platform.win32.WinDef;
import com.sun.jna.ptr.PointerByReference;
import lombok.extern.slf4j.Slf4j;

import java.text.SimpleDateFormat;

/**
 * @author HuangXin
 * @since 2021/5/7 10:35
 */
@Slf4j
public class RegionHumanCountCallBackImpl implements HWPuSDK.pfRealDataCallBack {

    private HWPuSDK.PU_META_DATA targetMetaData = new HWPuSDK.PU_META_DATA();
    private PointerByReference targetMetaDataPointer = new PointerByReference(targetMetaData.getPointer());
    private static final SimpleDateFormat HALF_DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd");
    private static final SimpleDateFormat FULL_DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

    private IHWPuSDKService hwPuSDKService = ApplicationContextHolder.getBean("hwPuSDKService");
    private CameraMapper cameraMapper = ApplicationContextHolder.getBean("cameraMapper");
    private IRegionHumanCountService regionHumanCountService = ApplicationContextHolder.getBean("regionHumanCountService");

    @Override
    public Pointer invoke(Pointer szBuffer, NativeLong lSize, Pointer pUsrData) {
        if (szBuffer == null) {
            log.error("RegionHumanCountCallBackImpl: szBuffer is null");
            return null;
        }

        //摄像机IP
        String ip = pUsrData.getString(0);
        if (CommonUtils.isNull(ip) || !CommonUtils.isCorrectIp(ip)) {
            log.error("pUsrData is null");
            return null;
        }

        //获取元数据
        boolean isOk = hwPuSDKService.getMetaData(szBuffer, new WinDef.ULONG(lSize.longValue()),
                HWPuSDK.LAYER_TWO_TYPE.TARGET, targetMetaDataPointer);
        if (isOk) {
            boolean isProcessed=false;
            try {
                //获取智能元数据
                HWPuSDK.PU_META_DATA data = Structure.newInstance(HWPuSDK.PU_META_DATA.class, targetMetaDataPointer.getValue());
                if (null != data) {
                    data.read();
                    isProcessed=procMetaData(data, ip); // Resolving metadata
                }

            } catch (Exception e) {
                e.printStackTrace();
                HWPuSDKServiceImpl.showErrMsg();
                log.error("解析智能元数据发生异常：{}", e.getMessage());
            } finally {
                //这里必须释放元数据，不然会导致内存泄漏
                if (isProcessed) {
                    hwPuSDKService.freeMetaData(targetMetaDataPointer);
                }
            }

        }
        return null;
    }


    /**
     * 处理实时视频智能元数据
     */
    private boolean procMetaData(HWPuSDK.PU_META_DATA metaData, String ip) throws Exception {
        HWPuSDK.PU_UserData[] userData;
        if (metaData == null || metaData.usValidNumber.intValue() == 0) {
            log.debug("No smart metadata was read.Program return");
            return false;
        } else {
            userData = (HWPuSDK.PU_UserData[]) metaData.pstMetaUserData.toArray(metaData.usValidNumber.intValue());
        }
        log.debug("Read the smart metadata and start parsing the smart metadata");

        Camera camera = cameraMapper.selectByCameraIp(ip);
        if (null == camera) {
            throw new IllegalArgumentException("Incorrect Argument camera：the camera with ip " + ip + " may not exist or is not configured");
        }

        //处理智能元数据
        for (int i = 0; i < metaData.usValidNumber.intValue(); i++) {
            StringBuilder processLog = new StringBuilder("Processing metadata：current eType=>0x" + Integer.toHexString(userData[i].eType) + ". ");
            switch (userData[i].eType) {
                case HWPuSDK.LAYER_THREE_TYPE_E.HUMAN_COUNT_IN: {
                    //进入区域人数
                    int inHumanNum = userData[i].unMetaData.IntValue;
                    log.info("Get HUMAN_COUNT_IN 获取到进入人数==>{}", inHumanNum);
                    if (inHumanNum > 0) {
                        regionHumanCountService.addHumanCountInRecord(camera.getRegionId(), inHumanNum);
                    }
                }
                break;
                case HWPuSDK.LAYER_THREE_TYPE_E.HUMAN_COUNT_OUT: {
                    //离开区域统计
                    int outHumanNum = userData[i].unMetaData.IntValue;
                    log.info("Get HUMAN_COUNT_OUT 获取到离开人数==>{}", outHumanNum);
                    if (outHumanNum > 0) {
                        regionHumanCountService.addHumanCountOutRecord(camera.getRegionId(), outHumanNum);
                    }
                }
                break;
                case HWPuSDK.LAYER_THREE_TYPE_E.HUMANCOUNT_ALL_IN_NUM: {
                    //进入区域总人数统计
                    int allInHumanNum = userData[i].unMetaData.IntValue;
                    log.info("Get HUMANCOUNT_ALL_IN_NUM 获取到进入总人数==>{}", allInHumanNum);
                    if (allInHumanNum > 0) {
                        regionHumanCountService.addRegionAllHumanCountInRecord(camera.getRegionId(), allInHumanNum);
                    }
                }
                break;
                case HWPuSDK.LAYER_THREE_TYPE_E.HUMANCOUNT_ALL_OUT_NUM: {
                    //离开区域的总数人数统计
                    int allOutHumanNum = userData[i].unMetaData.IntValue;
                    log.info("Get HUMANCOUNT_ALL_OUT_NUM 获取到离开总人数==>{}", allOutHumanNum);
                    if (allOutHumanNum > 0) {
                        regionHumanCountService.addRegionAllHumanCountOutRecord(camera.getRegionId(), allOutHumanNum);
                    }
                }
                break;
                default:
                    processLog.append("Discard!");
                    log.debug(processLog.toString());
                    break;
            }
        }
        return true;
    }


}
