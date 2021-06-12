package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.entity.Region;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;


/**
 * 区域信息查询DAO
 *
 * @author HuangXin
 */
@Repository
public interface RegionMapper {
    /**
     * 根据数据库主键删除一条记录
     *
     * @param id
     * @return 受影响的行数 1 表示删除成功 ， 0 表示删除失败
     */
    int deleteByPrimaryKey(@Param(value = "id") Integer id);


    /**
     * 向区域信息表中新增一条记录
     *
     * @param record
     * @return 插入本条记录的ID
     */
    int insert(Region record);


    /**
     * 根据主键ID查询一条记录
     *
     * @param id
     * @return 区域信息
     */
    Region selectByPrimaryKey(Integer id);

    /**
     * 根据区域名查询数据
     *
     * @param regionName
     * @return
     */
    Region selectByRegionName(String regionName);

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