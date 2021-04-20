package cn.edu.xust.iot.model.vo;

import lombok.Data;
import lombok.ToString;

import java.io.Serializable;

/**
 * @author HuangXin
 * @since 2021/4/15 10:02
 */
@Data
@ToString
public class SUserVO implements Serializable {

    private Integer userId;

    /**
     * 性别 0 男性 1女性
     */
    private String gender="男";

    /**
     * 姓名
     */
    private String name="NA";

    /**
     * 年龄
     */
    private String phone="NA";

    /**
     * 出生日期
     */
    private String birth="NA";

    /**
     * 家庭地址
     */
    private String address="NA";

    /**
     * 证件号(身份证号)
     */
    private String certificateNo="NA";

    /**
     * 职位
     */
    private String job="NA";

    /**
     * 是否是管理人员  0 表示不是 1 表示是
     */
    private boolean isManager=false;

    /**
     * 创建时间
     */
    private String createTime="NA";

    /**
     * 备注信息
     */
    private String memo="NA";

    /**
     * 用户头像URL地址
     */
    private String userAvatarUrl="NA";

    /**
     * 管理员用户的角色名
     */
    private String roleName;


    public boolean getIsManager(){
        return this.isManager;
    }

}
