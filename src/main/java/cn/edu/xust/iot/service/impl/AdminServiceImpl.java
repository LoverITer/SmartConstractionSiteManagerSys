package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.AdminUserMapper;
import cn.edu.xust.iot.mapper.SUserMapper;
import cn.edu.xust.iot.model.AdminUserModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.AdminUser;
import cn.edu.xust.iot.model.entity.SUser;
import cn.edu.xust.iot.service.IAdminService;
import cn.edu.xust.iot.utils.EncryptUtils;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @author HuangXin
 * @since 2021/4/13 13:14
 */
@Slf4j
@Service
public class AdminServiceImpl implements IAdminService {

    @Autowired
    private AdminUserMapper adminUserMapper;

    @Autowired
    private SUserMapper normalUserMapper;

    /**
     * SHA1 秘钥
     **/
    private static final String SHA1_SECRET_KEY = "839bea2f-c18f-4338-9b76-7f74e57aee1b";

    @Override
    public AdminUser checkUser(AdminUserModel userModel) {
        try {
            //将输入的明文加密获得数据库密文
            String cipherText = EncryptUtils.getInstance().SHA1(userModel.getPassword(), SHA1_SECRET_KEY);
            AdminUser adminUser = adminUserMapper.selectByUserName(userModel.getUsername());
            if(null==adminUser){
                log.error("用户登陆 管理账号 {} 还未注册",userModel.getUsername());
                return null;
            }
            if(adminUser.getPassword().equals(cipherText)){
                return adminUser;
            }
        } catch (Exception e) {
            log.error(e.getMessage());
        }
        return null;
    }

    @Override
    public CommonResponse<String> addNewAdminUser(AdminUserModel userModel) {
        try {
            AdminUser adminUser = adminUserMapper.selectByUserName(userModel.getUsername());
            if (null != adminUser) {
                log.error("管理员注册 新增管理员用户失败,原因是：管理员用户名重复");
                return CommonResponse.create(AppResponseCode.FAIL,"管理员用户名已经存在");
            }
            //将输入的明文加密后存储到数据库
            String cipherText = EncryptUtils.getInstance().SHA1(userModel.getPassword(), SHA1_SECRET_KEY);
            adminUser = new AdminUser();
            adminUser.setUsername(userModel.getUsername());
            adminUser.setPassword(cipherText);
            SUser sUser = new SUser();
            sUser.setName("Admin");  //管理员的普通用户名就默认是Admin
            int res1 = normalUserMapper.insertSelective(sUser);
            if (res1 > 0) {
                adminUser.setUserId(sUser.getId());
                int res2 = adminUserMapper.insert(adminUser);
                if (res2 > 0) {
                    log.error("管理员注册 新增管理员用户 {} 成功",userModel.getUsername());
                    return CommonResponse.create(AppResponseCode.SUCCESS,"新管理员注册成功");
                }
            }
        } catch (Exception e) {
            log.error("管理员注册 新增管理员用户失败,原因是：{}", e.getMessage());
        }
        return CommonResponse.create(AppResponseCode.FAIL,"注册新管理员失败");
    }
}
