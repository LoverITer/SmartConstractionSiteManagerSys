package cn.edu.xust.iot.model;

import lombok.Data;
import org.hibernate.validator.constraints.NotEmpty;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/4/13 12:30
 */
@Data
public class AdminUserModel implements Serializable {

    @NotEmpty(message = "登陆用户名不能为空")
    private String username;

    @NotEmpty(message = "登陆用户密码不能为空")
    private String password;

}
