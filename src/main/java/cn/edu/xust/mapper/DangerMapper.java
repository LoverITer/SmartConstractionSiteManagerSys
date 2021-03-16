package cn.edu.xust.mapper;

import org.springframework.stereotype.Repository;

import cn.edu.xust.entity.po.Danger;

/**
 * 危险类型查询DAO
 *
 * @author HuangXin
 *
 */
@Repository
public interface DangerMapper {
	/**
	 * 根据数据库主键删除一条记录
	 *
	 * @param id
	 * @return 受影响的行数 1 表示删除成功 ， 0 表示删除失败
	 */
	int deleteByPrimaryKey(Integer id);

	/**
	 * 向危险类型记录表中新增一条记录
	 *
	 * @param record
	 * @return 插入本条记录的ID
	 */
	int insert(Danger record);

	/**
	 * 向危险类型表中新增一条记录，但是只有不为null的字段才会保存值
	 *
	 * @param record
	 * @return
	 */
	int insertSelective(Danger record);

	/**
	 * 根据主键ID查询一条记录
	 *
	 * @param id
	 * @return 危险类型信息
	 */
	Danger selectByPrimaryKey(Integer id);

	/**
	 * 更新传入对象中某条危险类型记录
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKey(Danger record);

	/**
	 * 更新传入对象中某条危险类型记录不为空的字段
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKeySelective(Danger record);
}