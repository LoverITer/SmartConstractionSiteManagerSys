package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.AttendanceMapper;
import cn.edu.xust.iot.mapper.SUserMapper;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Attendance;
import cn.edu.xust.iot.model.vo.ClockInManagerVO;
import cn.edu.xust.iot.model.vo.ClockInWeeklyAmountVO;
import cn.edu.xust.iot.service.IClockInService;
import cn.edu.xust.iot.utils.AudioUtils;
import cn.edu.xust.iot.utils.CommonUtils;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.sql.SQLException;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 签到打卡服务化接口实现类
 *
 * @author HuangXin
 * @since 2021/4/30 17:36
 */
@Slf4j
@Service("clockInService")
public class ClockInServiceImpl implements IClockInService {

    /**
     * 上班打卡开始时间  打卡时间 2小时 6~8点
     */
    private static LocalTime START_WORK_CLOCK_IN_START_TIME = LocalTime.of(6,30,0);

    private static LocalTime START_WORK_CLOCK_IN_END_TIME = LocalTime.of(9,0,0);

    /**
     * 下班打卡开始时间  打卡21点开始 次日 5点结束
     */
    private static LocalTime AFTER_WORK_CLOCK_OUT_START_TIME = LocalTime.of(17,0,0);

    /**
     * 次日5点
     */
    private static LocalTime AFTER_WORK_CLOCK_OUT_END_TIME = LocalTime.of(22,0,0);

    public static final String TIME_PATTERN = "HH:mm:ss";
    public static final DateTimeFormatter TIME_FORMATTER = DateTimeFormatter.ofPattern(TIME_PATTERN);


    @Autowired
    private SUserMapper userMapper;
    @Autowired
    private AttendanceMapper attendanceMapper;

    /**
     * 判断当前时间是否在打卡时间内
     *
     * @return  返回 0表示上班打卡   返回 1 表示下班打卡
     */
    @Override
    public int isStartWorkOrAfterWork() {
        if (LocalTime.now().isAfter(START_WORK_CLOCK_IN_START_TIME) &&
                LocalTime.now().isBefore(START_WORK_CLOCK_IN_END_TIME)) {
            //上班打卡
            return 0;
        } else if (LocalTime.now().isAfter(AFTER_WORK_CLOCK_OUT_START_TIME) &&
                LocalTime.now().isBefore(AFTER_WORK_CLOCK_OUT_END_TIME)) {
            //下班打卡
            return 1;
        }
        //不在打卡时间
        return -1;
    }

    @Override
    public boolean setStartWorkClockInTime(LocalTime workClockInStart, LocalTime workClockInEnd) {
        START_WORK_CLOCK_IN_START_TIME = workClockInStart;
        START_WORK_CLOCK_IN_END_TIME = workClockInEnd;
        return true;
    }

    @Override
    public boolean setEndWorkClockInTime(LocalTime workClockInStart, LocalTime workClockInEnd) {
        AFTER_WORK_CLOCK_OUT_START_TIME = workClockInStart;
        AFTER_WORK_CLOCK_OUT_END_TIME = workClockInEnd;
        return true;
    }

    @Override
    public Map<String,String> getClockTimeState() {
        Map<String,String> clockTime=new HashMap<>(16);
        clockTime.put("startWorkStartTime",TIME_FORMATTER.format(START_WORK_CLOCK_IN_START_TIME));
        clockTime.put("startWorkEndTime",TIME_FORMATTER.format(START_WORK_CLOCK_IN_END_TIME));
        clockTime.put("afterWorkStartTime",TIME_FORMATTER.format(AFTER_WORK_CLOCK_OUT_START_TIME));
        clockTime.put("afterWorkEndTime",TIME_FORMATTER.format(AFTER_WORK_CLOCK_OUT_END_TIME));

        return clockTime;
    }

    @Override
    public boolean addClockInRecord(String cardType, String cardId) throws SQLException {
        if (CommonUtils.isNull(cardType) || CommonUtils.isNull(cardId)) {
            throw new NullPointerException("param cannot be null or empty");
        }
        Integer userId = userMapper.selectByIDCard(cardType, cardId);
        //打卡记录key(证件类型::证件ID)
        String clockRecordKey = String.format("%s::%s", cardType, cardId);
        Integer attendanceId = IClockInService.CLOCK_RECORDS.get(clockRecordKey);
        int startWorkOrAfterWork = isStartWorkOrAfterWork();
        if (startWorkOrAfterWork == 0) {
            //上班打卡 只有在规定时间内打卡才有效，超过时间不予打卡
            //打卡时间多次打卡 后面的打卡记录并保存
            if ((attendanceId == null || attendanceId <= 0) && null != userId && userId > 0) {
                Attendance attendance = new Attendance();
                attendance.setStarkWorkTime(new Date());
                attendance.setLate("0");
                attendance.setUserId(userId);
                int rows = attendanceMapper.insertSelective(attendance);
                if (rows <= 0) {
                    AudioUtils.textToSpeech("系统发生错误，打卡失败");
                    throw new SQLException("Clock in failure：Failed to insert punch record into database！");
                }
                //保存当天打卡人员的数据库打卡记录ID保存Map中
                IClockInService.CLOCK_RECORDS.put(clockRecordKey, attendance.getId());
                AudioUtils.textToSpeech("打卡成功");
                log.debug("Clock in Successful！");
            }
        } else if (startWorkOrAfterWork == 1) {
            //下班打卡  正常打卡
            if (attendanceId != null && attendanceId > 0) {
                Attendance attendance = attendanceMapper.selectByPrimaryKey(attendanceId);
                if (attendance != null) {
                    attendance.setAfterWorkTime(new Date());
                }
                int rows = attendanceMapper.updateByPrimaryKey(attendance);
                if(rows<=0){
                    AudioUtils.textToSpeech("打卡失败");
                }
                AudioUtils.textToSpeech("打卡成功");
            } else {
                //都下班打卡了，还未上班打卡，就是缺勤
                AudioUtils.textToSpeech("打卡失败");
                log.error("编号为 {} 的员工缺勤", userId);
            }
        }else{
            AudioUtils.textToSpeech("不在打卡时间");
        }
        return true;
    }


    @Override
    public Integer getClockInUserNum() {
        try {
            return attendanceMapper.countAllClockInUser();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return -1;
    }

    @Override
    public Integer getAllClockInManagerNum() {
        try {
            return attendanceMapper.countAllClockInManager();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return -1;
    }

    @Override
    public Integer getAllClockInWorkerNum() {
        try {
            return attendanceMapper.countAllClockInWorker();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return -1;
    }

    @Override
    public CommonResponse<List<ClockInManagerVO>> getAllManagerClockRecord() {
        try {
            List<ClockInManagerVO> clockInManagerList = attendanceMapper.selectTodayClockInManager();
            return CommonResponse.create(AppResponseCode.SUCCESS, clockInManagerList);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<List<ClockInWeeklyAmountVO>> getPast7DaysClockInNum() {
        try {
            List<ClockInWeeklyAmountVO> clockInWeeklyAmountVOList = attendanceMapper.countPastSevenDaysClockIn();
            return CommonResponse.create(AppResponseCode.SUCCESS, clockInWeeklyAmountVOList);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }
}
