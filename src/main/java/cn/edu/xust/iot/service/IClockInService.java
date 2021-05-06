package cn.edu.xust.iot.service;

import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.vo.ManagerClockInVO;
import cn.edu.xust.iot.model.vo.SevenDaysClockIn;

import java.sql.SQLException;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/**
 * 签到打卡服务化接口
 *
 * @author HuangXin
 * @since 2021/4/30 14:08
 */
public interface IClockInService {

    /**
     * 上班打卡开始时间  打卡时间 2小时 6~8点
     */
    int START_WORK_CLOCK_IN_START_TIME = 6;

    int START_WORK_CLOCK_IN_END_TIME = START_WORK_CLOCK_IN_START_TIME + 2;

    /**
     * 下班打卡开始时间  打卡21点开始 次日 5点结束
     */
    int AFTER_WORK_CLOCK_OUT_START_TIME = 21;

    /**
     * 次日5点
     */
    int AFTER_WORK_CLOCK_OUT_END_TIME = 5;

    /**
     * 人员当前签到打卡记录  会在 每天的5:10清空打卡记录
     */
    Map<String, Integer> CLOCK_RECORDS = new ConcurrentHashMap<>(16);

    /**
     * 判断当前时间是否在打卡时间内
     *
     * @return
     */
    int isStartWorkOrAfterWork();

    /**
     * 增加或修改打卡记录
     *
     * @return
     */
    boolean addClockInRecord(String cardType, String cardId) throws SQLException;

    /**
     * 全部打卡日志
     *
     * @return
     */
    Integer getClockInUserNum();

    /**
     * @return
     */
    Integer getAllClockInManagerNum();

    /**
     * @return
     */
    Integer getAllClockInWorkerNum();

    /**
     * 获取当天所有重要人员（管理人员）的打卡详细信息
     *
     * @return
     */
    CommonResponse<List<ManagerClockInVO>> getAllManagerClockRecord();


    /**
     * 获取过去7天人员打卡情况
     *
     * @return
     */
    CommonResponse<List<SevenDaysClockIn>> getPast7DaysClockInNum();

}
