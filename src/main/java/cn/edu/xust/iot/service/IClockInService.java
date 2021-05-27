package cn.edu.xust.iot.service;

import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.vo.ClockInManagerVO;
import cn.edu.xust.iot.model.vo.ClockInWeeklyAmountVO;

import java.sql.SQLException;
import java.time.LocalTime;
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
     * 获取上下班打卡时间的状态参数state
     *
     * @return
     */
    Map<String,String> getClockTimeState();


    /**
     * 设置系统上班打卡时间段
     *
     * @return
     */
    boolean setStartWorkClockInTime(LocalTime workClockInStart, LocalTime workClockInEnd);

    /**
     * 设置系统下班打卡时间段
     *
     * @return
     */
    boolean setEndWorkClockInTime(LocalTime workClockInStart, LocalTime workClockInEnd);

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
    CommonResponse<List<ClockInManagerVO>> getAllManagerClockRecord();


    /**
     * 获取过去7天人员打卡情况
     *
     * @return
     */
    CommonResponse<List<ClockInWeeklyAmountVO>> getPast7DaysClockInNum();

}
