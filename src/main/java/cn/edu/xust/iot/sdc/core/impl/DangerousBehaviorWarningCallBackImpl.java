package cn.edu.xust.iot.sdc.core.impl;

import cn.edu.xust.iot.conf.ApplicationContextHolder;
import cn.edu.xust.iot.conf.qiniu.QiNiuCloudService;
import cn.edu.xust.iot.mapper.DangerBehaviorMapper;
import cn.edu.xust.iot.mapper.DangerMapper;
import cn.edu.xust.iot.mapper.RegionMapper;
import cn.edu.xust.iot.model.entity.Danger;
import cn.edu.xust.iot.model.entity.DangerBehavior;
import cn.edu.xust.iot.model.entity.Region;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.service.impl.HWPuSDKServiceImpl;
import cn.edu.xust.iot.utils.CommonUtils;
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.platform.win32.WinDef;
import com.sun.jna.ptr.PointerByReference;
import lombok.extern.slf4j.Slf4j;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * 危险行为元数据解析回调
 *
 * @author HuangXin
 * @since 2021/5/17 22:51
 */
@Slf4j
public class DangerousBehaviorWarningCallBackImpl implements HWPuSDK.pfRealDataCallBack {

    private HWPuSDK.PU_META_DATA targetMetaData = new HWPuSDK.PU_META_DATA();
    private PointerByReference targetMetaDataPointer = new PointerByReference(targetMetaData.getPointer());
    private static final SimpleDateFormat HALF_DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd");

    private IHWPuSDKService hwPuSDKService = ApplicationContextHolder.getBean("hwPuSDKService");
    private QiNiuCloudService qiNiuCloudService=ApplicationContextHolder.getBean("qiNiuCloudService");
    private DangerBehaviorMapper dangerBehaviorMapper=ApplicationContextHolder.getBean("dangerBehaviorMapper");
    private RegionMapper regionMapper=ApplicationContextHolder.getBean("regionMapper");
    private DangerMapper dangerMapper=ApplicationContextHolder.getBean("dangerMapper");

    @Override
    public Pointer invoke(Pointer szBuffer, NativeLong lSize, Pointer pUsrData) {
        if (szBuffer == null) {
            log.error("DangerousBehaviorWarningCallBackImpl: szBuffer is null");
            return null;
        }
        //获取元数据
        boolean isOk = hwPuSDKService.getMetaData(szBuffer, new WinDef.ULONG(lSize.longValue()),
                HWPuSDK.LAYER_TWO_TYPE.TARGET, targetMetaDataPointer);

        if (isOk) {
            boolean isProcessed = false;
            try {
                //获取智能元数据
                HWPuSDK.PU_META_DATA data = Structure.newInstance(HWPuSDK.PU_META_DATA.class, targetMetaDataPointer.getValue());
                if (data != null) {
                    data.read();
                    isProcessed = procMetaData(data); // Resolving metadata
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

    private boolean procMetaData(HWPuSDK.PU_META_DATA data) throws Exception {
        HWPuSDK.PU_UserData[] userData;
        if (data == null || data.usValidNumber.intValue() == 0) {
            log.debug("No smart metadata was read.Program return");
            return false;
        } else {
            userData = (HWPuSDK.PU_UserData[]) data.pstMetaUserData.toArray(data.usValidNumber.intValue());
        }
        log.debug("Get smart metadata and start parsing the smart metadata");

        String[] IDCardInfo=new String[2];    //人员身份信息
        String[] behaviorInfo=new String[2];  //不安全动作信息
        int isWarning = 0;
        //处理智能元数据
        for (int i = 0; i < data.usValidNumber.intValue(); i++) {
            StringBuilder processLog = new StringBuilder("Processing metadata：current eType=>0x" + Integer.toHexString(userData[i].eType) + ". ");
            switch (userData[i].eType) {
                case HWPuSDK.LAYER_THREE_TYPE_E.FACE_INFO: {
                    /*证件类型
                     * IDENTITY = 0, // 身份证
                     * PASSPORT = 1, // 护照
                     * OFFICER = 2, // 军官证
                     * DRIVING = 3, // 驾驶证
                     * OTHERS = 4, // 其他
                     * MAX = 512
                     */
                    int cardType = userData[i].unMetaData.stFaceInfo.iCardType;
                    //根据人脸获取人员证件ID   这里统一都是身份证ID
                    String cardId = CommonUtils.byteToString(userData[i].unMetaData.stFaceInfo.cardID);
                    processLog.append("Get Face_INFO=>{cardType:{},cardId:{}}");
                    log.debug(processLog.toString(), cardType, cardId);
                    IDCardInfo[0]=String.valueOf(cardType);
                    IDCardInfo[1]=String.valueOf(cardId);
                }
                break;
                case HWPuSDK.LAYER_THREE_TYPE_E.FACE_FEATURE: {
                    //触发危险行为 0表示没有危险行为  大于0表示有危险行为
                    isWarning = userData[i].unMetaData.IntValue;
                    if(isWarning>1){
                        //元数据会将不安全行为的名称和区域传递过来
                        //不安全行为发生区域名称
                        behaviorInfo[0]=String.valueOf(userData[i].unMetaData.ucharValue);
                        //不安全行为名称
                        behaviorInfo[1]=userData[i].unMetaData.charValue;
                    }
                }
                break;
                case HWPuSDK.LAYER_THREE_TYPE_E.FACE_PANORAMA: {
                    //触发了危险报警
                    if(isWarning>0){
                        String formatData = HALF_DATE_FORMAT.format(new Date());
                        //处理全景图片
                        byte[] panoramaPicBytes = userData[i].unMetaData.stBinay.pBinaryData.getByteArray(0,
                                userData[i].unMetaData.stBinay.ulBinaryLenth);
                        //保存全景图片
                        String fileName = HWPuSDKServiceImpl.DEFAULT_PICTURE_LOCAL_PATH + formatData +
                                "\\panorama_pic\\" +
                                CommonUtils.getRandomString() + ".jpg";
                        String fileUrl=qiNiuCloudService.uploadByByteArray(panoramaPicBytes, fileName);
                        processLog.append("Get FACE_PANORAMA：{} to save panorama picture {} !");
                        DangerBehavior dangerBehavior = new DangerBehavior();
                        dangerBehavior.setState("0"); //未处理
                        dangerBehavior.setBehaviorPic(fileUrl);  //抓拍图片
                        dangerBehavior.setCertNo(IDCardInfo[1]); //身份证号
                        //根据区域名称查询区域ID作为DangerBehavior的外键
                        Region region = regionMapper.selectByRegionName(behaviorInfo[0]);
                        dangerBehavior.setRegionId(region.getId());
                        //根据危险名称查询危险ID作为DangerBehavior的外键
                        Danger danger = dangerMapper.selectByDangerName(behaviorInfo[1]);
                        dangerBehavior.setBehaviorType(danger.getId());
                        //插入数据库
                        int affectedRows = dangerBehaviorMapper.insertSelective(dangerBehavior);
                        if(affectedRows>0){
                            log.info("人员不安全行为记录成功!");
                        }else{
                            throw new RuntimeException("人员不安全行为记录失败!");
                        }
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
