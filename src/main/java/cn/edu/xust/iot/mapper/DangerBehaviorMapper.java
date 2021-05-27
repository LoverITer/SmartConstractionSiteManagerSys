package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.entity.DangerBehavior;
import cn.edu.xust.iot.model.vo.*;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;


/**
 * 危险行为查询DAO
 *
 * @author HuangXin
 */
@Repository
public interface DangerBehaviorMapper {
    /**
     * 根据数据库主键删除一条记录
     *
     * @param id
     * @return 受影响的行数 1 表示删除成功 ， 0 表示删除失败
     */
    int deleteByPrimaryKey(Integer id);

    /**
     * 向危险行为记录表中新增一条记录
     *
     * @param record
     * @return 插入本条记录的ID
     */
    int insert(DangerBehavior record);

    /**
     * 向危险行为记录表中新增一条记录，但是只有不为null的字段才会保存值
     *
     * @param record
     * @return
     */
    int insertSelective(DangerBehavior record);

    /**
     * 根据主键ID查询一条记录
     *
     * @param id
     * @return 危险行为信息
     */
    DangerBehavior selectByPrimaryKey(Integer id);

    /**
     * 统计全部告警数
     *
     * @return
     */
    int countTotalDangerBehaviorNum();

    /**
     * 统计今日告警数
     *
     * @return
     */
    int countTodayDangerBehaviorNum();

    /**
     * 近15天危险行为告警数量
     *
     * @return
     */
    List<DangerBehaviorHalfMonthAmountVO> countHalfMonthDangerBehaviorNum();

    /**
     * 近15天不安全行为告警数量
     *
     * @return
     */
    List<DangerBehaviorHalfMonthAmountVO> countHalfMonthUnsafeBehaviorNum();

    /**
     * 不安全行为数量统计
     *
     * @return
     */
    List<UnSafeBehaviorAmountVO> countTodayUnsafeNumBehaviorByBehaviorType(@Param(value = "isOrder") Integer isOrder);

    /**
     * 安全装备违规佩戴统计
     *
     * @return
     */
    List<UnSafeBehaviorAmountVO> countTodayDangerNumBehaviorByBehaviorType(@Param(value = "isOrder") Integer isOrder);

    /**
     * 获取当天所有危险行为告警
     *
     * @return
     */
    List<DangerBehaviorVO> selectTodayDangerBehaviorByBehaviorType();

    /**
     * 人员历史累计违规行为信息信息统计
     *
     * @return
     */
    List<DangerBehaviorPersonnelNoticeVO> selectPersonnelDangerRecords();

    /**
     * 统计人员今日所有不安全行为
     *
     * @return
     */
    List<UnSafeBehaviorAmountVO> countAllTypeDangerBehaviorNum();

    /**
     * 人员历史违规行为数量统计
     *
     * @return
     */
    List<DangerBehaviorPersonnelAmountVO> countPersonnelAllDangerRecordsNum();

    /**
     * 三类危险行为数据概览
     *
     * @return
     */
    DangerBehaviorTodayOverviewAmountVO countTodayAllDangerBehaviorNum();

    /**
     * 更新传入对象中某条危险行为记录
     *
     * @param record
     * @return
     */
    int updateByPrimaryKey(DangerBehavior record);

    /**
     * 更新传入对象中某条危险行为记录不为空的字段
     *
     * @param record
     * @return
     */
    int updateByPrimaryKeySelective(DangerBehavior record);

}