package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.entity.Role;
import cn.edu.xust.iot.model.vo.RoleVO;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface RoleMapper {
    int deleteByPrimaryKey(Integer id);

    int deleteByPrimaryKeyBatch(@Param("roleIds") List<Integer> roleIds);

    int insert(Role record);

    int insertSelective(Role record);

    Role selectByPrimaryKey(Integer id);

    /**
     * 查询所有的角色信息
     *
     * @return
     */
    List<RoleVO> selectWithPowerName();

    /**
     * 统计角色数量
     *
     * @return
     */
    int countRoleNum();

    int updateByPrimaryKeySelective(Role record);

    int updateByPrimaryKey(Role record);
}