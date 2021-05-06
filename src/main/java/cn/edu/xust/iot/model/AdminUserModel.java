package cn.edu.xust.iot.model;

import cn.edu.xust.iot.model.entity.AdminUser;
import cn.edu.xust.iot.service.impl.AdminUserServiceImpl;
import cn.edu.xust.iot.utils.EncryptUtils;
import lombok.Data;
import org.hibernate.validator.constraints.NotEmpty;

import java.io.Serializable;
import java.util.Date;

/**
 * @author HuangXin
 * @since 2021/4/13 12:30
 */
@Data
public class AdminUserModel implements Serializable {

    /**
     * 管理员ID
     */
    Integer adminId;

    /**
     * 管理员登陆姓名
     */
    private String name;

    /**
     * 管理员登陆用户名
     */
    @NotEmpty(message = "登陆用户名不能为空")
    private String username;

    /**
     * 管理密码
     */
    @NotEmpty(message = "登陆用户密码不能为空")
    private String password;

    /**
     * 管理人员在用户表的ID
     */
    private Integer userId;

    /**
     * 管理员用户的角色名
     */
    private String roleName;

    /**
     * 管理员角色创建时间
     */
    private Date createTime;

    /**
     * 管理员联系方式
     */
    private String phone;


    public AdminUser convertAdminUserModel2AdminUser() {
        AdminUser adminUser = new AdminUser();
        adminUser.setAdminId(this.getAdminId());
        adminUser.setUsername(this.getUsername());
        adminUser.setPassword(EncryptUtils.getInstance().AESEncode(this.getPassword(), AdminUserServiceImpl.SHA1_SECRET_KEY));
        //这里要求前端会直接传递对应数据库中role的id
        adminUser.setRoleId(Integer.parseInt(this.getRoleName()));
        return adminUser;
    }

}
