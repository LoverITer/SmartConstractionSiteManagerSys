package cn.edu.xust.iot.sdc.core.impl;

import cn.edu.xust.iot.conf.ApplicationContextHolder;
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
    private static final SimpleDateFormat FULL_DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

    private IHWPuSDKService hwPuSDKService = ApplicationContextHolder.getBean("hwPuSDKService");

    @Override
    public Pointer invoke(Pointer szBuffer, NativeLong lSize, Pointer pUsrData) {
        if (szBuffer == null) {
            log.error("FaceRecognitionCallbackImpl: szBuffer is null");
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
                if(data!=null) {
                    data.read();
                    isProcessed=procMetaData(data); // Resolving metadata
                }
            } catch (Exception e) {
                e.printStackTrace();
                HWPuSDKServiceImpl.showErrMsg();
                log.error("解析智能元数据发生异常：{}", e.getMessage());
            } finally {
                //这里必须释放元数据，不然会导致内存泄漏
                if(isProcessed){
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

        int target = 0;
        //人脸匹配结果  0：失败 ，1：成功
        int matchRes = -1;
        //处理智能元数据
        for (int i = 0; i < data.usValidNumber.intValue(); i++) {
            StringBuilder processLog = new StringBuilder("Processing metadata：current eType=>0x" + Integer.toHexString(userData[i].eType) + ". ");
            switch (userData[i].eType) {
                case HWPuSDK.LAYER_THREE_TYPE_E.FACE_INFO: {
                    /*人脸信息 0x12000001*/
                    //姓名
                    String name = CommonUtils.byteToString(userData[i].unMetaData.stFaceInfo.name);
                    //年龄
                    int gender = userData[i].unMetaData.stFaceInfo.iGender;
                    //生日
                    String birth = CommonUtils.byteToString(userData[i].unMetaData.stFaceInfo.birthday);
                    //省份
                    String province = CommonUtils.byteToString(userData[i].unMetaData.stFaceInfo.province);
                    //城市
                    String city = CommonUtils.byteToString(userData[i].unMetaData.stFaceInfo.city);
                    /*证件类型
                     * IDENTITY = 0, // 身份证
                     * PASSPORT = 1, // 护照
                     * OFFICER = 2, // 军官证
                     * DRIVING = 3, // 驾驶证
                     * OTHERS = 4, // 其他
                     * MAX = 512
                     */
                    int cardType = userData[i].unMetaData.stFaceInfo.iCardType;
                    //证件ID   这里统一都是证件ID
                    String cardId = CommonUtils.byteToString(userData[i].unMetaData.stFaceInfo.cardID);
                    processLog.append("Get Face_INFO=>{name:{},gender:{},birth:{},province:{},city:{},cardType:{},cardId:{}}");
                    log.debug(processLog.toString(), name, gender, birth, province, city, cardType, cardId);

                    //如果目标是人脸并且人脸匹配
                    if (HWPuSDK.ITGT_TARGET_TYPE_E.TARGET_FACE_RECOGNITION == target && matchRes == 1) {

                    }

                }
                break;
                case HWPuSDK.LAYER_THREE_TYPE_E.FACE_PANORAMA: {
                    String formatData = HALF_DATE_FORMAT.format(new Date());
                    //处理全景图片
                    StringBuilder fileName = new StringBuilder(HWPuSDKServiceImpl.DEFAULT_PICTURE_LOCAL_PATH).append(formatData)
                            .append("\\panorama_pic\\")
                            .append(CommonUtils.getRandomString()).append(".jpg");
                    byte[] panoramaPicBytes = userData[i].unMetaData.stBinay.pBinaryData.getByteArray(0,
                            userData[i].unMetaData.stBinay.ulBinaryLenth);
                    //保存全景图片
                    boolean saveOk = CommonUtils.savePicture(fileName.toString(), panoramaPicBytes, userData[i].unMetaData.stBinay.ulBinaryLenth);
                    processLog.append("Get FACE_PANORAMA：{} to save panorama picture {} !");
                    log.debug(processLog.toString(), saveOk ? "Success" : "Failed", fileName);
                }
                break;
                case HWPuSDK.LAYER_THREE_TYPE_E.FACE_FEATURE: {
                    /* 人脸特征
                     * typedef struct _FACE_ATTRIBUTES
                     * {
                     *    BOOL isVaild;
                     *    //INT 定义的属性 0 代表 未知，1-n依次代表后面的属性具体含义
                     *    INT glasses; // 眼镜{无，有}
                     *    INT gender; // 性别{女，男}
                     *    INT age; // 年龄，具体的年龄值1~99
                     *    INT32 mouthmask; //遮档 {无，是}
                     *    INT32 expression; //人脸表情{微笑、愤怒、悲伤、正常、惊讶}
                     * }FACE_ATTRIBUTES;
                     */
                    int isGlasses = userData[i].unMetaData.stFaceAttr.glasses;
                    int gender = userData[i].unMetaData.stFaceAttr.gender;
                    int mouthMask = userData[i].unMetaData.stFaceAttr.mouthmask;
                    String age = String.valueOf(userData[i].unMetaData.stFaceAttr.age);
                    int expression = userData[i].unMetaData.stFaceAttr.exspression;
                    log.debug("Get FACE_FEATURE=>{isGlasses={},gender={},mouthMask={},age={},expression={}}",
                            isGlasses, gender, mouthMask, age, expression);
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
