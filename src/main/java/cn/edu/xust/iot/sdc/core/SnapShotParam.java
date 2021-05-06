package cn.edu.xust.iot.sdc.core;

import com.sun.jna.platform.win32.WinDef;
import lombok.Getter;

/**
 * 抓拍参数
 *
 * @author HuangXin
 * @since 2021/4/23 20:19
 */
@Getter
public class SnapShotParam {

    /**
     * 每次抓拍图片张数 0~10张
     */
    private WinDef.ULONG ulSnapCount;
    /**
     * 抓怕间隔 500~1000ms
     */
    private WinDef.ULONG ulSnapInterval;
    /**
     * 抓怕类型
     */
    private HWPuSDK.PU_SNAPSHOT_TYPE enSnapType;

    public SnapShotParam(int ulSnapCount, long ulSnapInterval, HWPuSDK.PU_SNAPSHOT_TYPE enSnapType) {
        this.ulSnapCount = new WinDef.ULONG(ulSnapCount);
        this.ulSnapInterval = new WinDef.ULONG(ulSnapInterval);
        this.enSnapType = enSnapType;
    }
}
