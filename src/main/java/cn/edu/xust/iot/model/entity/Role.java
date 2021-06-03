package cn.edu.xust.iot.model.entity;

import lombok.Data;
import lombok.ToString;

@Data
@ToString
public class Role {
    private Integer id;

    private String roleName;

    private Integer powerId;

    private String description;

    private String status;

}