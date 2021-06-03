package cn.edu.xust.iot.model.vo;

import lombok.Data;
import lombok.ToString;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/6/1 20:11
 */
@Data
@ToString
public class RoleVO implements Serializable {
    private Integer id;
    private String roleName;
    private String powerName;
    private String description;
    private String status;
}
