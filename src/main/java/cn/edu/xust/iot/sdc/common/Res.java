package cn.edu.xust.iot.sdc.common;


import java.util.Locale;
import java.util.ResourceBundle;

public final class Res {

    private ResourceBundle bundle;

    private Res() {
        switchLanguage(LanguageType.Chinese);
    }

    private static class StringBundleHolder {
        private static Res instance = new Res();
    }

    public static Res string() {
        return StringBundleHolder.instance;
    }

    public static enum LanguageType {
        English,
        Chinese
    }

    public ResourceBundle getBundle() {
        return bundle;
    }

    /**
     * \if ENGLISH_LANG
     * Switch between Chinese and English
     * \else
     * 涓嫳鏂囧垏鎹�
     * \endif
     */
    public void switchLanguage(LanguageType type) {
        switch (type) {
            case Chinese:
                bundle = ResourceBundle.getBundle("language", new Locale("zh"));
                break;
            case English:
                bundle = ResourceBundle.getBundle("language", new Locale("en"));
                break;
            default:
                break;
        }
    }

    public String getRegisterSDKEventCallback() {
        return bundle.getString("REGISTER_SDK_EVENT_CALLBACK");
    }

    public String getMainTitle() {
        return bundle.getString("MainTitle");
    }

    public String getDeviceLogin() {
        return bundle.getString("DEVICE_LOGIN");
    }

    public String getLogin() {
        return bundle.getString("LOGIN");
    }

    public String getLogout() {
        return bundle.getString("LOGOUT");
    }

    public String getDeviceIp() {//"\u8bbe\u5907IP\uff1a"
        return bundle.getString("DEVICE_IP");
    }

    public String getIp() {
        return bundle.getString("IP");
    }

    public String getPort() {
        return bundle.getString("DEVICE_PORT");
    }

    public String getUserName() {
        return bundle.getString("USERNAME");
    }

    public String getPassword() {
        return bundle.getString("PASSWORD");
    }


    public String getChn() {
        return bundle.getString("CHN");
    }

    public String getChannel() {
        return bundle.getString("CHANNEL");
    }

    public String getPTZControl() {
        return bundle.getString("PTZ_CONTROL");
    }


    public String getLeft() {
        return bundle.getString("LEFT");
    }

    public String getRight() {
        return bundle.getString("RIGHT");
    }

    public String getUp() {
        return bundle.getString("UP");
    }

    public String getDown() {
        return bundle.getString("DOWN");
    }

    public String getLeftUp() {
        return bundle.getString("LEFT_UP");
    }

    public String getRightUp() {
        return bundle.getString("RIGHT_UP");
    }

    public String getLeftDown() {
        return bundle.getString("LEFT_DOWN");
    }

    public String getRightDown() {
        return bundle.getString("RIGHT_DOWN");
    }

    public String getZoom() {
        return bundle.getString("ZOOM");
    }

    public String getFocus() {
        return bundle.getString("FOCUS");
    }

    public String getIris() {
        return bundle.getString("IRIS");
    }

    public String getInc() {
        return bundle.getString("ZOOM_FOCUS_IRIS_INC");
    }

    public String getDec() {
        return bundle.getString("ZOOM_FOCUS_IRIS_DEC");
    }

    public String getSpeed() {
        return bundle.getString("SPEED");
    }

    public String getYes() {
        return bundle.getString("YES");
    }

    public String getNo() {
        return bundle.getString("NO");
    }

    public String getExit() {
        return bundle.getString("EXIT");
    }


    public String getDelete() {
        return bundle.getString("DELETE");
    }


    public String getPlaySetting() {
        return bundle.getString("PLAYSETTING");
    }

    public String getVideoChanel() {
        return bundle.getString("VIDEO_CHANEL");
    }

    public String getStreamType() {
        return bundle.getString("STREAM_TYPE");
    }

    public String getMainStream() {
        return bundle.getString("MAIN_STREAM");
    }

    public String getSubStream() {
        return bundle.getString("SBU_STREAM");
    }

    public String getLinkWay() {
        return bundle.getString("LINKWAY");
    }

    public String getMulticast() {
        return bundle.getString("MULTICAST");
    }

    public String getKeepAlive() {
        return bundle.getString("KEEPALIVE");
    }

    public String getVideoType() {
        return bundle.getString("VIDEO_TYPE");
    }

    public String getVideo() {
        return bundle.getString("VIDEO");
    }

    public String getAUDIO() {
        return bundle.getString("AUDIO");
    }

    public String getMulti() {
        return bundle.getString("MULTI");
    }

    public String getRecord() {
        return bundle.getString("RECORD");
    }

    public String getMetaData() {
        return bundle.getString("METADATA");
    }

    public String getVideoAndMetaData() {
        return bundle.getString("VIDEO&METADATA");
    }

    public String getPlay() {
        return bundle.getString("PLAY");
    }

    public String getStop() {
        return bundle.getString("STOP");
    }

    public String getPresetTitle() {
        return bundle.getString("PRESETPOINT_TITLE");
    }

    public String getPreset() {
        return bundle.getString("PRESETPOINT");
    }

    public String getGoto() {
        return bundle.getString("GOTO");
    }

    public String getSetting() {
        return bundle.getString("SETTING");
    }

    public String getSetPreset() {
        return bundle.getString("SET_PRESET");
    }

    public String getChanelId() {
        return bundle.getString("CHANEL_ID");
    }

    public String getPresetName() {
        return bundle.getString("PRESET_NAME");
    }

    public String getPresetIndex() {
        return bundle.getString("PRESET_INDEX");
    }

    public String getAddPreset() {
        return bundle.getString("ADD_PRESET");
    }
    public String getTrip(){
        return bundle.getString("TRIP");
    }

    public String getUpdatePreset() {
        return bundle.getString("UPDATE_PRESET");
    }

    public String getDelPreset() {
        return bundle.getString("DEL_PRESET");
    }


    public String getCruiseTrack() {
        return bundle.getString("CRUISE_TITLE");
    }

    public String getCruiseNumber() {
        return bundle.getString("CRUISENUMBER");
    }

    public String getRun() {
        return bundle.getString("RUN");
    }

    public String getStayTime() {
        return bundle.getString("STAYTIME");
    }

    public String getSetCruise() {
        return bundle.getString("SETCRUISE");
    }

    public String getCruiseIndex() {
        return bundle.getString("CRUISE_INDEX");
    }

    public String getCruiseName() {
        return bundle.getString("CRUISE_NAME");
    }

    public String getClearCruise() {
        return bundle.getString("CLEAR_CRUISE");
    }

    public String getCruiseInfo() {
        return bundle.getString("CRUISE_INFO");
    }

    public String getCruiseAddPreset() {
        return bundle.getString("CRUISE_ADD_PRESET");
    }

    public String getCruiseSetPreset() {
        return bundle.getString("CRUISE_SET_PRESET");
    }

    public String getCruiseDelPreset() {
        return bundle.getString("CRUISE_DEL_PRESET");
    }

    public String getCruisePreset() {
        return bundle.getString("CRUISE_PRESET");
    }

    public String getConfirm() {
        return bundle.getString("CONFIRM");
    }

    public String getCancel() {
        return bundle.getString("CANCEL");
    }

    public String getNewPresetIndex() {
        return bundle.getString("NEW_PRESET_INDEX");
    }

    public String getNewPresetName() {
        return bundle.getString("NEW_PRESET_NAME");
    }

    public String getNewStayTime() {
        return bundle.getString("NEW_STAYTIME");
    }


    /**
     * tips
     *
     * @return
     */

    public String getTip() {
        return bundle.getString("Tip");
    }

    public String getTipLogon() {
        return bundle.getString("TipLogon");
    }

    public String getTipCruiseIndex() {
        return bundle.getString("TipCruiseIndex");
    }

    public String getTipPreIndex() {
        return bundle.getString("TipPreIndex");
    }

    public String getTipUpdate() {
        return bundle.getString("TipUpdate");
    }

    public String getTipSave() {
        return bundle.getString("TipSave");
    }

    public String getTipCruiseNameOverLen() {
        return bundle.getString("TipCruiseNameOverLen");
    }

    public String getTipCruisePointsOver() {
        return bundle.getString("TipCruisePointsOver");
    }

    public String getTipNotNullPreName() {
        return bundle.getString("TipNotNullPreName");
    }

    public String getTipPreNameOverLen() {
        return bundle.getString("TipPreNameOverLen");
    }

    public String getTipStayTimeLim() {
        return bundle.getString("TipStayTimeLim");
    }

    public String getTipNotNullStayTime() {
        return bundle.getString("TipNotNullStayTime");
    }

    public String getTipStayTimeErr() {
        return bundle.getString("TipStayTimeErr");
    }

    public String getTipaddSuccess() {
        return bundle.getString("TipaddSuccess");
    }

    public String getTipupdateSuccess() {
        return bundle.getString("TipupdateSuccess");
    }

    public String getTipdelSuccess() {
        return bundle.getString("TipdelSuccess");
    }

    public String getTipdelFail() {
        return bundle.getString("TipdelFail");
    }

    public String getTipCuiseNotSet() {
        return bundle.getString("TipCuiseNotSet");
    }

    public String getTipCruisePresetDelConfirm() {
        return bundle.getString("TipCruisePresetDelConfirm");
    }

    public String getTipDelCruisePreset() {
        return bundle.getString("TipDelCruisePreset");
    }

    public String getTipCruiseClearConfirm() {
        return bundle.getString("TipCruiseClearConfirm");
    }

    public String getTipClearCruise() {
        return bundle.getString("TipClearCruise");
    }

    public String getTipPresetInfoMax() {
        return bundle.getString("TipPresetInfoMax");
    }

    public String getTipPresetDelConfirm() {
        return bundle.getString("TipPresetDelConfirm");
    }

    public String getTipExitConfirm() {
        return bundle.getString("TipExitConfirm");
    }

    public String getTipDeviceAlreadyLogin() {
        return bundle.getString("TipDeviceAlreadyLogin");
    }

    public String getTipLoginSuccess() {
        return bundle.getString("TipLoginSuccess");
    }

    public String getTipLogoutSuccess() {
        return bundle.getString("TipLogoutSuccess");
    }
    public String getTipInputIp() {
        return bundle.getString("TipInputIp");
    }
    public String getTipIpErr() {
        return bundle.getString("TipIpErr");
    }

    public String getTipInputUserName() {
        return bundle.getString("TipInputUserName");
    }

    public String getTipInputPassword() {
        return bundle.getString("TipInputPassword");
    }

    public String getTipInputPort() {
        return bundle.getString("TipInputPort");
    }

    public String getTipPortRange() {
        return bundle.getString("TipPortRange");
    }

    public String getTipPortErr() {
        return bundle.getString("TipPortErr");
    }

    public String getTipDeviceNotLogin() {
        return bundle.getString("TipDeviceNotLogin");
    }

    public String getEventCaseFive(){return bundle.getString("TIPS_EVENTCASEFIVE");}

    public String getEventCaseSix(){return bundle.getString("TIPS_EVENTCASESIX");}

    public String getEventCaseSeven(){return bundle.getString("TIPS_EVENTCASESEVEN");}


}
