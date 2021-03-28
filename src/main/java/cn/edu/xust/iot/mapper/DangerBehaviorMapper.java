package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.entity.po.DangerBehavior;
import org.springframework.stereotype.Repository;


/**
 * 危险行为查询DAO
 *
 * @author HuangXin
 *
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