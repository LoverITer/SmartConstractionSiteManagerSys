package cn.edu.xust.iot.model.vo;

import lombok.Data;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/5/22 11:04
 */
@Data
public class UnSafeBehaviorAmountVO implements Serializable {

    //不安全行为名
    private String unsafeBehaviorName;

    //对应不安全行为数量
    private int num;
}
