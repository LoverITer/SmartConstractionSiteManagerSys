package cn.edu.xust.iot.model.vo;

import lombok.Data;
import lombok.ToString;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/5/21 15:53
 */
@Data
@ToString
public class HumanAmountVO implements Serializable {

    //区域名
    private String regionName;

    //进入人数
    private Integer humanIn;

    //离开人数
    private Integer humanOut;

}
