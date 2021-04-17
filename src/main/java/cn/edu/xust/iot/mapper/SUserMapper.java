package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.SUserModel;
import cn.edu.xust.iot.model.entity.SUser;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;


/**
 * 人员信息查询DAO
 *
 * @author HuangXin
 */
@Repository
public interface SUserMapper {
    /**
     * 根据数据库主键删除一条记录
     *
     * @param id
     * @return 受影响的行数 1 表示删除成功 ， 0 表示删除失败
     */
    int deleteByPrimaryKey(Integer id);

    /**
     * 根据数据库主键批量删除记录
     *
     * @param idList
     * @return 受影响的行数 大于等于1 表示删除成功 ， 0 表示删除失败
     */
    int batchDeleteByPrimaryKey(@Param(value = "idList") List<Integer> idList);

    /**
     * 向人员信息表中新增一条记录
     *
     * @param record
     * @return 插入本条记录的ID
     */
    int insert(SUser record);

    /**
     * 向人员信息表中新增一条记录，但是只有不为null的字段才会保存值
     *
     * @param record
     * @return
     */
    int insertSelective(SUser record);

    /**
     * 根据主键ID查询一条记录
     *
     * @param id
     * @return 人员信息
     */
    SUser selectByPrimaryKey(Integer id);


    /**
     * 查询所有人员的信息
     *
     * @return
     */
    List<SUserModel> selectAll();

    /**
     * 查询人员的数量
     *
     * @return
     */
    int countMembers();

    /**
     * 更新传入对象中某条人员信息记录
     *
     * @param record
     * @return
     */
    int updateByPrimaryKey(SUser record);

    /**
     * 更新传入对象中某条人员信息不为空的字段
     *
     * @param record
     * @return
     */
    int updateByPrimaryKeySelective(SUser record);
}