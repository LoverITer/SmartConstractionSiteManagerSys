package cn.edu.xust.iot.service;

import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.AdminUserModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.AdminUser;
import com.github.pagehelper.PageInfo;

import java.util.List;

/**
 * 后台用户服务接口，功能包括：管理人员注册\登陆
 *
 * @author HuangXin
 * @since 2021/4/13 13:12
 */
public interface IAdminUserService {


    /**
     * 检查用户名和密码是否正确
     *
     * @param userModel
     * @return
     */
    AdminUser checkUser(AdminUserModel userModel);

    /**
     * 添加新的管理员用户
     *
     * @param userModel
     * @return
     */
    CommonResponse<String> addNewAdminUser(AdminUserModel userModel);

    /**
     * 获取所有的用户的数据
     *
     * @param pageParam
     * @return
     */
    PageInfo<AdminUserModel> getAllAdminUserList(PageParam pageParam);

    /**
     * 获取所有管理员的人数
     *
     * @return
     */
    CommonResponse<Integer> getAllAdminUserSize();

    /**
     * 修改管理员信息
     *
     * @param userModel
     * @return
     */
    CommonResponse<String> editAdminUser(AdminUserModel userModel);

    /**
     * 删除管理员用户，支持批量删除
     *
     * @param adminUserIds
     * @return
     */
    CommonResponse<String> removeAdminUser(List<Integer> adminUserIds);

}
