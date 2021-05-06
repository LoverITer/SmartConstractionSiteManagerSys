package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.entity.Attendance;
import cn.edu.xust.iot.model.vo.ManagerClockInVO;
import cn.edu.xust.iot.model.vo.SevenDaysClockIn;
import org.springframework.stereotype.Repository;

import java.util.List;


/**
 * 考勤查询DAO
 *
 * @author HuangXin
 */
@Repository
public interface AttendanceMapper {

    /**
     * 根据数据库主键删除一条记录
     *
     * @param id 主键ID
     * @return
     */
    int deleteByPrimaryKey(Integer id);

    /**
     * 向考勤表中插入一条新记录
     *
     * @param record Attendance对象
     * @return
     */
    int insert(Attendance record);

    /**
     * 向考勤表中插入一条新记录 ，某些字段可以为空
     *
     * @param record Attendance对象
     * @return
     */
    int insertSelective(Attendance record);

    /**
     * 根据主键查询一条考勤记录
     *
     * @param id 主键ID
     * @return 考勤信息
     */
    Attendance selectByPrimaryKey(Integer id);

    /**
     * 实时统计当天全部签到人数
     *
     * @return
     */
    int countAllClockInUser();

    /**
     * 实时统计当天全部管理员签到人数
     *
     * @return
     */
    int countAllClockInManager();

    /**
     * 实时统计当天全部工人签到人数
     *
     * @return
     */
    int countAllClockInWorker();

    /**
     * 统计连续过去7天的人员打卡数据
     *
     * @return
     */
    List<SevenDaysClockIn> countPastSevenDaysClockIn();

    /**
     * 查询当天打卡的管理人员的详细信息
     *
     * @return
     */
    List<ManagerClockInVO> selectTodayClockInManager();


    /**
     * 更新传入对象中某条考勤记录
     *
     * @param record Attendance对象
     * @return
     */
    int updateByPrimaryKey(Attendance record);

    /**
     * 更新传入对象中某条考勤记录不为空的字段
     *
     * @param record Attendance对象
     * @return
     */
    int updateByPrimaryKeySelective(Attendance record);
}