package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.AdminUserModel;
import cn.edu.xust.iot.model.entity.AdminUser;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface AdminUserMapper {
    int deleteByPrimaryKey(Integer adminId);

    int batchDeleteByPrimaryKey(@Param("adminUserIds") List<Integer> adminUserIds);

    int insert(AdminUser record);

    int insertSelective(AdminUser record);

    AdminUser selectByPrimaryKey(Integer adminId);

    List<AdminUserModel> selectWithRoleName();

    AdminUser selectByUserName(@Param("username") String username);

    int updateByPrimaryKeySelective(AdminUser record);

    int updateByPrimaryKey(AdminUser record);

    int countAdminUsers();
}