package cn.edu.xust.iot.sdc.core;

import cn.edu.xust.iot.service.IHWPuSDKService;
import cn.edu.xust.iot.service.impl.HWPuSDKServiceImpl;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.platform.win32.WinDef;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import static cn.edu.xust.iot.sdc.core.HWPuSDK.PU_EVENT_TYPE.*;

/**
 * SDK事件回调接口，实现eventStatus方法
 *
 * @author HuangXin
 * @since 2021/5/6 10:56
 */
@Component
public class EventStatusImpl implements HWPuSDK.pfGetEventInfoCallBack {

    @Autowired
    private IHWPuSDKService hwPuSDKService;
    //已连接设备ID和
    private static final Map<Long,String> CONNECTED_CAMERA_MAP=new ConcurrentHashMap<>(16);


    /**
     * 处理相机事件
     *
     * @param args
     * @return 返回int类型的值，-1 表示执行出现异常  0 表示程序执行失败或没有需要处理的事件类型  1 表示程序处理事件成功
     */
    @Override
    public long eventStatus(Pointer args) {
        try {
            long ulLoginId = 0;
            HWPuSDK.PU_EVENT_COMMON stPuEventCommon = Structure.newInstance(HWPuSDK.PU_EVENT_COMMON.class, args);
            stPuEventCommon.read();

            switch (stPuEventCommon.enEventType) {
                case PU_EVENT_TYPE_REGISTER:
                    break;
                case PU_EVENT_TYPE_UNREGISTER:
                    break;
                case PU_EVENT_TYPE_CONNCET:
                    //设别连接网络
                    ulLoginId = stPuEventCommon.ulIdentifyID.longValue();

                    break;
                case PU_EVENT_TYPE_DISCONNECT: {
                    // Front-end device unconnected
                    ulLoginId = stPuEventCommon.ulIdentifyID.longValue();
                    Map<String, Long> camerasLoginMap = HWPuSDKServiceImpl.CAMERAS_LOGIN_MAP;

                    if (ulLoginId > 0) {
                        WinDef.ULONG ulRealPlayHnd = HWPuSDKServiceImpl.CAMERA_LOGIN_PLAYING_MAP.get(ulLoginId);
                        if (ulRealPlayHnd.longValue() > 0L) {
                            boolean res = HWPuSDK.INSTANCE.IVS_PU_StopRealPlay(new WinDef.ULONG(ulLoginId), ulRealPlayHnd);
                        }
                        //先退出
                        HWPuSDK.INSTANCE.IVS_PU_Logout(new WinDef.ULONG(ulLoginId));
                        //重新登陆HWPuSDK.INSTANCE.IVS_PU_Login()

                       /* if (login > 0) {
                            if (faceReHnd > 0) {
                                faceRecoginRealPlay();
                            }
                        } else {
                            return 0;
                        }*/

                    }
                    break;
                }

                case PU_EVENT_TYPE_SEND_RECV_ERROR: {
                    //Failed to send or receive
                    ulLoginId = stPuEventCommon.ulIdentifyID.longValue();

                    /*if (ulLoginId > 0) {
                        if (faceReHnd > 0) {
                            stopReconginTion();
                        }

                        logout();

                        long login = login();

                        if (login > 0) {
                            if (faceReHnd > 0) {
                                faceRecoginRealPlay();
                            }
                        } else {
                            return 0;
                        }

                    }*/
                    break;
                }
                case PU_EVENT_TYPE_KEEPLIVE_FAIL: {
                    //Front-end survival failure
                    ulLoginId = stPuEventCommon.ulIdentifyID.longValue();
                    //long faceReHnd = faceReRealPlayHnd;

                    /*if (ulLoginId > 0) {
                        if (faceReHnd > 0) {
                            stopReconginTion();
                        }

                        logout();
                        JOptionPane.showMessageDialog(parentContatiner, Res.string().getEventCaseSeven(), HWPuSDK.strTip, JOptionPane.INFORMATION_MESSAGE);

                        long login = login();

                        if (login > 0) {
                            if (faceReHnd > 0) {
                                faceRecoginRealPlay();
                            }
                        } else {
                            return 0;
                        }

                    }*/
                    break;
                }

                case PU_EVENT_TYPE_REALPALY_ERROR: {
                    // Live exception
                    break;
                }
                default:
                    break;
            }

        } catch (Exception e) {
            e.printStackTrace();
            return -1;
        }
        return 1;
    }
}
