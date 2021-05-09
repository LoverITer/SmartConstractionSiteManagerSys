package cn.edu.xust.iot.sdc.core.constraints;

/**
 * 播放类型
 * @author HuangXin
 * @since 2021/5/7 17:22
 */
public enum PlayType {

    FACE_RECOGNITION_CALLBACK_IMPL(1),
    REGION_CROWD_DENSITY_CALLBACK_IMPL(2);
    private final int type;

    PlayType(int type) {
        this.type = type;
    }

    public int getType() {
        return type;
    }


    public boolean equals(PlayType type){
        return this.getType()==type.getType();
    }

}
