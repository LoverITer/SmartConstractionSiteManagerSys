package cn.edu.xust.mapper;

import org.springframework.stereotype.Repository;

import cn.edu.xust.entity.po.Region;

/**
 * 区域信息查询DAO
 *
 * @author HuangXin
 *
 */
@Repository
public interface RegionMapper {
	/**
	 * 根据数据库主键删除一条记录
	 *
	 * @param id
	 * @return 受影响的行数 1 表示删除成功 ， 0 表示删除失败
	 */
	int deleteByPrimaryKey(Integer id);

	/**
	 * 向区域信息表中新增一条记录
	 *
	 * @param record
	 * @return 插入本条记录的ID
	 */
	int insert(Region record);

	/**
	 * 向区域信息表中新增一条记录，但是只有不为null的字段才会保存值
	 *
	 * @param record
	 * @return
	 */
	int insertSelective(Region record);

	/**
	 * 根据主键ID查询一条记录
	 *
	 * @param id
	 * @return 区域信息
	 */
	Region selectByPrimaryKey(Integer id);

	/**
	 * 更新传入对象中某区域信息记录
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKey(Region record);

	/**
	 * 更新传入对象中某条区域信息不为空的字段
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKeySelective(Region record);
}