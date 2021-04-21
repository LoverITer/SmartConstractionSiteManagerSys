package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.entity.FaceLib;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;


/**
 * 人脸库查询DAO
 *
 * @author HuangXin
 *
 */
@Repository
public interface FaceLibMapper {
	/**
	 * 根据数据库主键删除一条记录
	 *
	 * @param id
	 * @return 受影响的行数 1 表示删除成功 ， 0 表示删除失败
	 */
	int deleteByPrimaryKey(Long id);

	int deleteByPrimaryKeyBatch(@Param(value = "faceLibIds") List<Integer> faceLibIds);

	/**
	 * 向人脸库表中新增一条记录
	 *
	 * @param record
	 * @return 插入本条记录的ID
	 */
	int insert(FaceLib record);

	/**
	 * 向人脸库表中新增一条记录，但是只有不为null的字段才会保存值
	 *
	 * @param record
	 * @return
	 */
	int insertSelective(FaceLib record);

	/**
	 * 根据主键ID查询一条记录
	 *
	 * @param id
	 * @return 人脸库
	 */
	FaceLib selectByPrimaryKey(Integer id);

	/**
	 * 更新传入对象中某条人脸库记录
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKey(FaceLib record);

	/**
	 * 更新传入对象中某条人脸库记录不为空的字段
	 *
	 * @param record
	 * @return
	 */
	int updateByPrimaryKeySelective(FaceLib record);
}