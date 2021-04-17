package cn.edu.xust.iot.model;

import cn.edu.xust.iot.model.entity.SUser;
import cn.edu.xust.iot.model.vo.SUserVO;
import io.swagger.annotations.Api;
import lombok.Data;
import lombok.ToString;
import org.hibernate.validator.constraints.NotEmpty;

import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * @author HuangXin
 * @since 2021/4/15 9:23
 */
@ToString
@Data
@Api(value = "成员模型")
public class SUserModel implements Serializable {

    private Integer userId = 0;

    /**
     * 性别 0 男性 1女性
     */
    @NotEmpty(message = "性别不能为空")
    private String gender = "NA";

    /**
     * 姓名
     */
    @NotEmpty(message = "姓名必须设置")
    private String name = "NA";

    /**
     * 年龄
     */
    @NotEmpty(message = "手机必须设置")
    private String phone = "NA";

    /**
     * 出生日期
     */
    private Date birth = new Date();

    /**
     * 家庭地址
     */
    @NotEmpty(message = "地址必须设置")
    private String address = "NA";

    /**
     * 证件号(身份证号)
     */
    @NotEmpty(message = "身份证号必须设置")
    private String certificateNo = "NA";

    /**
     * 职位
     */
    @NotEmpty(message = "工种必须设置")
    private String job = "NA";

    /**
     * 是否是管理人员
     */
    @NotEmpty(message = "是否为管理员必须设置")
    private String isManager = "0";

    /**
     * 创建时间
     */
    private Date createTime = new Date();

    /**
     * 备注信息
     */
    private String memo = "NA";

    /**
     * 用户头像URL地址
     */
    @NotEmpty(message = "头像URL不能为空")
    private String userAvatarUrl = "NA";

    /**
     * 将UserModel对象转换成UserVO对象并返回
     *
     * @return
     */
    public SUserVO convertUserModel2UserVO() {
        SUserVO userVO = new SUserVO();
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        userVO.setUserId(this.getUserId());
        userVO.setName(this.getName());
        userVO.setGender("0".equals(this.getGender()) ? "男" : "女");
        userVO.setAddress(this.getAddress());
        if (this.getBirth() != null) {
            userVO.setBirth(sdf.format(this.getBirth()));
        }
        userVO.setCertificateNo(this.getCertificateNo());
        if (this.getCreateTime() != null) {
            userVO.setCreateTime(sdf.format(this.getCreateTime()));
        }
        userVO.setManager("1".equals(this.getIsManager()));
        userVO.setPhone(this.getPhone());
        userVO.setUserAvatarUrl(this.getUserAvatarUrl());
        userVO.setJob(this.getJob());
        userVO.setMemo(this.getMemo());
        return userVO;
    }

    public SUser convertUserModel2SUser() {
        SUser sUser = new SUser();
        sUser.setId(this.getUserId());
        sUser.setName(this.getName());
        sUser.setAddress(this.getAddress());
        sUser.setBirth(this.getBirth());
        sUser.setCreateTime(this.getCreateTime());
        sUser.setCertificateNo(this.getCertificateNo());
        sUser.setGender(this.getGender());
        sUser.setIsManager(this.getIsManager());
        sUser.setJob(this.getJob());
        sUser.setMemo(this.getMemo());
        sUser.setPhone(this.getPhone());

        return sUser;
    }


}
