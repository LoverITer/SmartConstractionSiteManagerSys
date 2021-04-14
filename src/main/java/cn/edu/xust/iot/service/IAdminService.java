package cn.edu.xust.iot.service;

import cn.edu.xust.iot.model.AdminUserModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.AdminUser;

/**
 * 后台用户服务接口，功能包括：管理人员注册\登陆
 *
 * @author HuangXin
 * @since 2021/4/13 13:12
 */
public interface IAdminService {


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

}
