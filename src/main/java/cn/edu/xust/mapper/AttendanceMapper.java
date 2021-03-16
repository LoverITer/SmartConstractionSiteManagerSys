package cn.edu.xust.mapper;

import org.springframework.stereotype.Repository;

import cn.edu.xust.entity.po.Attendance;

/**
 * 考勤查询DAO
 *
 * @author HuangXin
 *
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