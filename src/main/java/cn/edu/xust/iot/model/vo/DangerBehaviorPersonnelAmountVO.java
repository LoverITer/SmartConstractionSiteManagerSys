package cn.edu.xust.iot.model.vo;

import lombok.Data;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/5/22 19:52
 */
@Data
public class DangerBehaviorPersonnelAmountVO implements Serializable {

    private String name;
    private Integer personNoticeTimeSum;

}
