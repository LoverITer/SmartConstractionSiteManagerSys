package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.AttendanceMapper;
import cn.edu.xust.iot.mapper.SUserMapper;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Attendance;
import cn.edu.xust.iot.model.vo.ManagerClockInVO;
import cn.edu.xust.iot.model.vo.SevenDaysClockIn;
import cn.edu.xust.iot.service.IClockInService;
import cn.edu.xust.iot.utils.CommonUtils;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.sql.SQLException;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

/**
 * 签到打卡服务化接口实现类
 *
 * @author HuangXin
 * @since 2021/4/30 17:36
 */
@Service("clockInService")
@Slf4j
public class ClockInServiceImpl implements IClockInService {


    @Autowired
    private SUserMapper userMapper;
    @Autowired
    private AttendanceMapper attendanceMapper;

    /**
     * 判断当前时间是否在打卡时间内
     *
     * @return
     */
    @Override
    public int isStartWorkOrAfterWork() {
        Calendar calendar = Calendar.getInstance();
        int hourOfNow = calendar.get(Calendar.HOUR_OF_DAY);
        if (hourOfNow >= IClockInService.START_WORK_CLOCK_IN_START_TIME && hourOfNow <= IClockInService.START_WORK_CLOCK_IN_END_TIME) {
            return 0;
        } else if ((hourOfNow >= IClockInService.AFTER_WORK_CLOCK_OUT_START_TIME && hourOfNow <= 23) ||
                (hourOfNow >= 0 && hourOfNow <= IClockInService.AFTER_WORK_CLOCK_OUT_END_TIME)) {
            return 1;
        }
        return -1;
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
        if (startWorkOrAfterWork == 0 || startWorkOrAfterWork == -1) {
            //上班打卡 只有在规定时间内打卡才有效，超过时间不予打卡
            //打卡时间多次打卡 后面的打卡记录并保存
            if ((attendanceId == null || attendanceId <= 0) && null != userId && userId > 0) {
                Attendance attendance = new Attendance();
                attendance.setStarkWorkTime(new Date());
                attendance.setLate(startWorkOrAfterWork == 0 ? "0" : "1");
                attendance.setUserId(userId);
                int rows = attendanceMapper.insertSelective(attendance);
                if (rows <= 0) {
                    throw new SQLException("Clock in failure：Failed to insert punch record into database！");
                }
                //保存当天打卡人员的数据库打卡记录ID保存Map中
                IClockInService.CLOCK_RECORDS.put(clockRecordKey, attendance.getId());
                log.debug("Clock in Successful！");
            }
        } else if (startWorkOrAfterWork == 1) {
            //下班打卡  正常打卡
            if (attendanceId != null && attendanceId > 0) {
                Attendance attendance = attendanceMapper.selectByPrimaryKey(attendanceId);
                if (attendance != null) {
                    attendance.setAfterWorkTime(new Date());
                }
                attendanceMapper.updateByPrimaryKey(attendance);
            } else {
                //都下班打卡了，还未上班打卡，就是缺勤
                log.error("编号为 {} 的员工缺勤", userId);
            }
        }
        return true;
    }


    @Override
    public Integer getClockInUserNum() {
        try{
            return attendanceMapper.countAllClockInUser();
        }catch (Exception e){
            e.printStackTrace();
        }
        return -1;
    }

    @Override
    public Integer getAllClockInManagerNum() {
        try{
            return attendanceMapper.countAllClockInManager();
        }catch (Exception e){
            e.printStackTrace();
        }
        return -1;
    }

    @Override
    public Integer getAllClockInWorkerNum() {
        try{
            return attendanceMapper.countAllClockInWorker();
        }catch (Exception e){
            e.printStackTrace();
        }
        return -1;
    }

    @Override
    public CommonResponse<List<ManagerClockInVO>> getAllManagerClockRecord() {
        try{
            List<ManagerClockInVO> clockInManagerList = attendanceMapper.selectTodayClockInManager();
            return CommonResponse.create(AppResponseCode.SUCCESS,clockInManagerList);
        }catch (Exception e){
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<List<SevenDaysClockIn>> getPast7DaysClockInNum() {
        try{
            List<SevenDaysClockIn> sevenDaysClockInList = attendanceMapper.countPastSevenDaysClockIn();
            return CommonResponse.create(AppResponseCode.SUCCESS,sevenDaysClockInList);
        }catch (Exception e){
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }
}
