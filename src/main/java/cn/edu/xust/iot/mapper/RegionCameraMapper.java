package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.entity.RegionCamera;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;


/**
 * 区域相机查询DAO
 *
 * @author HuangXin
 */
@Repository
public interface RegionCameraMapper {
	/**
	 * 根据数据库主键删除一条记录
	 *
	 * @param id
	 * @return 受影响的行数 1 表示删除成功 ， 0 表示删除失败
	 */
	int deleteByPrimaryKey(Integer id);

	/**
	 * 根据摄像机ID删除记录
	 *
	 * @param cameraIdList
	 * @return
	 */
	int deleteByCameraId(@Param(value = "cameraIdList") List<Integer> cameraIdList);

	/**
	 * 向区域相机表中新增一条记录
	 *
	 * @param record
	 * @return 插入本条记录的ID
	 */
	int insert(RegionCamera record);

	/**
	 * 向区域相机表中新增一条记录，但是只有不为null的字段才会保存值
	 *
	 * @param record
	 * @return
	 */
	int insertSelective(RegionCamera record);

	/**
	 * 根据主键ID查询一条记录
	 *
	 * @param id
	 * @return 区域相机
	 */
	RegionCamera selectByPrimaryKey(Integer id);

	/**
	 * 更新传入对象中某条区域相机记录
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKey(RegionCamera record);

	/**
	 * 更新传入对象中某条区域相机记录不为空的字段
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKeySelective(RegionCamera record);
}