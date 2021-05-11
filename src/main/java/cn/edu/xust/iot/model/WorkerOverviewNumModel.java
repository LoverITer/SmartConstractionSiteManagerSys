package cn.edu.xust.iot.model;

import lombok.Data;
import lombok.ToString;

/**
 * @author HuangXin
 * @since 2021/4/21 22:41
 */
@Data
@ToString
public class WorkerOverviewNumModel {

    /**
     * 总共人数
     */
    Integer total;

    /**
     * 系统管理人员数量
     */
    Integer adminUserNum;

    /**
     * 工人数量
     */
    Integer workerNum;

    /**
     * 实名制人员数量
     */
    Integer realNameNum;
}
