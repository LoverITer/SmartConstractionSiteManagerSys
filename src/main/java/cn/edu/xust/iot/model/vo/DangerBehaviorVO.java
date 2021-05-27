package cn.edu.xust.iot.model.vo;

import lombok.Data;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/5/22 12:28
 */
@Data
public class DangerBehaviorVO implements Serializable {

    //数据ID
    private  Integer id;
    //发生时间
    private String createTime;
    //危险行为名称
    private String dangerBehaviorName;
    //危险行为图片
    private String dangerBehaviorPic;
    //发生区域
    private String regionName;
    //处理状态
    private String state;

}
