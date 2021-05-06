package cn.edu.xust.iot.model;

import lombok.Data;
import lombok.ToString;

/**
 * @author HuangXin
 * @since 2021/4/21 22:41
 */
@Data
@ToString
public class WorkerNumModel {

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

    /**
     * 木工人数
     */
    Integer woodWorkerNum;

    /**
     * 钢筋工数量
     */
    Integer steelWorkerNum;

    /**
     * 混凝土工数量
     */
    Integer concreteWorkerNum;

    /**
     * 砖瓦工数量
     */
    Integer bricklayerWorkerNum;

    /**
     * 抹灰工数量
     */
    Integer plastererWorkerNum;

    /**
     * 涂料工数量
     */
    Integer coaterWorkerNum;

    /**
     * 装修工数量
     */
    Integer decorationWorkerNum;

    /**
     * 电工数量
     */
    Integer electricianWorkerNum;

    /**
     * 水暖工数量
     */
    Integer plumberWorkerNum;

    /**
     * 机修工数量
     */
    Integer mechanicWorkerNum;

    /**
     * 机械司工人数量
     */
    Integer machineryDepartmentNum;

    /**
     * 杂工工人数量
     */
    Integer assistantWorkerNum;
}
