package cn.edu.xust.iot.sdc.core.impl;

import cn.edu.xust.iot.conf.ApplicationContextHolder;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.service.impl.HWPuSDKServiceImpl;
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.platform.win32.WinDef;
import com.sun.jna.ptr.PointerByReference;
import lombok.extern.slf4j.Slf4j;

import java.text.SimpleDateFormat;

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

    private boolean procMetaData(HWPuSDK.PU_META_DATA data) {
        return false;
    }
}
