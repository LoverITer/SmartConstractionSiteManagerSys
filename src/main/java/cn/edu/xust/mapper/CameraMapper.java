package cn.edu.xust.mapper;

import org.springframework.stereotype.Repository;

import cn.edu.xust.entity.po.Camera;

/**
 * 摄像机查询DAO
 *
 * @author HuangXin
 *
 */
@Repository
public interface CameraMapper {

	/**
	 * 根据数据库主键删除一条记录
	 *
	 * @param id
	 * @return 受影响的行数 1 表示删除成功 ， 0 表示删除失败
	 */
	int deleteByPrimaryKey(Integer id);

	/**
	 * 向摄像机设备表中新增一条记录
	 *
	 * @param record
	 * @return 插入本条记录的ID
	 */
	int insert(Camera record);

	/**
	 * 向摄像机设备表中新增一条记录，但是只有不为null的字段才会保存值
	 *
	 * @param record
	 * @return
	 */
	int insertSelective(Camera record);

	/**
	 * 根据主键ID查询一条记录
	 *
	 * @param id
	 * @return 摄像机信息
	 */
	Camera selectByPrimaryKey(Integer id);

	/**
	 * 更新传入对象中某条摄像机记录
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKey(Camera record);

	/**
	 * 更新传入对象中某条摄像机记录不为空的字段
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKeySelective(Camera record);
}