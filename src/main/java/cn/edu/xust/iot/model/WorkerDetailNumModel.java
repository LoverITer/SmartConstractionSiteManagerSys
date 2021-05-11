package cn.edu.xust.iot.model;

import lombok.Data;
import lombok.ToString;

/**
 * 统计各种施工人员的实体类
 *
 * @author HuangXin
 * @since 2021/5/10 16:32
 */
@Data
@ToString
public class WorkerDetailNumModel {

    /**
     * 工种名称
     */
    private String job;

    /**
     * 工种人数
     */
    private Integer num;

}
