package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.entity.Danger;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;


/**
 * 危险类型查询DAO
 *
 * @author HuangXin
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
     * 查询全部
     *
     * @return
     */
    List<Danger> selectAll();

    /**
     * 根据主键ID查询一条记录
     *
     * @param id
     * @return 危险类型信息
     */
    Danger selectByPrimaryKey(Integer id);

    /**
     * 获取系统所有危险名称
     *
     * @return
     */
    List<Danger> selectAllDangerType();

    /**
     * 根据危险行为名称查询记录
     *
     * @param dangerName
     * @return
     */
    Danger selectByDangerName(@Param("dangerName") String dangerName);

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