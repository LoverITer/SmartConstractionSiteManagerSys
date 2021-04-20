package cn.edu.xust.iot.model.entity;

import lombok.Data;
import lombok.ToString;

@Data
@ToString
public class AdminUser {
    private Integer adminId;

    private String username;

    private String password;

    private Integer userId;

    private Integer roleId;

}