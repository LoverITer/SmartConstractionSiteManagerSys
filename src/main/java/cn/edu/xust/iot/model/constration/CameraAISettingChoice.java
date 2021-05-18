package cn.edu.xust.iot.model.constration;

/**
 * 摄像机智能业务功能枚举类
 *
 * @author HuangXin
 * @since 2021/5/17 19:23
 */
public enum CameraAISettingChoice {

    //人脸打卡业务
    Face_Punching_Business("d45e808403c84981b79fb85dd6f55968"),
    Region_Crowd_Count_Business("c9355aeb373b4dc4a7445dc442af8c90"),
    Danger_Warning_Business("f2e7885eb3d346a99983083e5a47d460");

    private String typeID;

    CameraAISettingChoice(String typeID) {
        this.typeID = typeID;
    }

    public String getType() {
        return typeID;
    }

    public boolean equals(String typeID){
        return this.getType().equals(typeID);
    }
}
