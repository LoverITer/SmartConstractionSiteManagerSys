package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.AdminUserMapper;
import cn.edu.xust.iot.mapper.SUserMapper;
import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.AdminUserModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.constration.AdminUserType;
import cn.edu.xust.iot.model.entity.AdminUser;
import cn.edu.xust.iot.model.entity.SUser;
import cn.edu.xust.iot.service.IAdminUserService;
import cn.edu.xust.iot.utils.EncryptUtils;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

/**
 * @author HuangXin
 * @since 2021/4/13 13:14
 */
@Slf4j
@Service
public class AdminUserServiceImpl implements IAdminUserService {

    @Autowired
    private AdminUserMapper adminUserMapper;

    @Autowired
    private SUserMapper normalUserMapper;

    /**
     * SHA1用户登陆加密秘钥
     **/
    public static final String SHA1_SECRET_KEY = "839bea2f-c18f-4338-9b76-7f74e57aee1b";

    @Override
    public AdminUser checkUser(AdminUserModel userModel) {
        try {
            //将输入的明文加密获得数据库密文
            String cipherText = EncryptUtils.getInstance().AESEncode(userModel.getPassword(), SHA1_SECRET_KEY);
            AdminUser adminUser = adminUserMapper.selectByUserName(userModel.getUsername());
            if (null == adminUser) {
                log.error("用户登陆 管理账号 {} 还未注册", userModel.getUsername());
                return null;
            }
            if (adminUser.getPassword().equals(cipherText)) {
                return adminUser;
            }
        } catch (Exception e) {
            log.error(e.getMessage());
        }
        return null;
    }

    @Transactional(rollbackFor = Exception.class, isolation = Isolation.REPEATABLE_READ)
    @Override
    public CommonResponse<String> addNewAdminUser(AdminUserModel userModel) {
        try {
            AdminUser adminUser = adminUserMapper.selectByUserName(userModel.getUsername());
            if (null != adminUser) {
                log.error("管理员注册 新增管理员用户失败,原因是：管理员用户名重复");
                return CommonResponse.create(AppResponseCode.ADMIN_USER_EXIST);
            }
            SUser sUser = new SUser();
            sUser.setName("Admin");  //管理员的普通用户名就默认是Admin
            sUser.setPhone(userModel.getPhone());
            sUser.setCreateTime(userModel.getCreateTime());
            sUser.setIsManager("1");
            sUser.setJob(AdminUserType.getRoleByDataBaseId(Integer.parseInt(userModel.getRoleName())));
            int rows = normalUserMapper.insertSelective(sUser);
            if (rows > 0) {
                adminUser = userModel.convertAdminUserModel2AdminUser();
                adminUser.setUserId(sUser.getId());
                int res2 = adminUserMapper.insertSelective(adminUser);
                if (res2 > 0) {
                    log.debug("管理员注册 新增管理员用户 {} 成功", userModel.getUsername());
                    return CommonResponse.create(AppResponseCode.SUCCESS);
                }
            }
        } catch (Exception e) {
            log.error("管理员注册 新增管理员用户失败,原因是：{}", e.getMessage());
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }


    @Override
    public PageInfo<AdminUserModel> getAllAdminUserList(PageParam pageParam) {
        PageInfo<AdminUserModel> pages = null;
        try {
            PageHelper.startPage(pageParam.getPage(), pageParam.getPageSize());
            List<AdminUserModel> adminUserModel = adminUserMapper.selectWithRoleName();
            adminUserModel.forEach(adminUser -> {
                String ciphertext = adminUser.getPassword();
                String plaintext = EncryptUtils.getInstance().AESDecode(ciphertext, SHA1_SECRET_KEY);
                adminUser.setPassword(plaintext);
                adminUser.setRoleName(AdminUserType.getRoleByRoleType(adminUser.getRoleName()));
            });
            pages = new PageInfo<>(adminUserModel);
            return pages;
        } catch (Exception e) {
            e.printStackTrace();
            log.error("查询用户数据发生错误:{}", e.getMessage());
            return null;
        }
    }

    @Override
    public CommonResponse<Integer> getAllAdminUserSize() {
        int camerasSize = 0;
        try {
            camerasSize = adminUserMapper.countAdminUsers();
            return CommonResponse.create(AppResponseCode.SUCCESS, camerasSize);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL, camerasSize);
    }

    @Transactional(rollbackFor = Exception.class, isolation = Isolation.REPEATABLE_READ)
    @Override
    public CommonResponse<String> editAdminUser(AdminUserModel userModel) {
        try {
            AdminUser adminUser = adminUserMapper.selectByPrimaryKey(userModel.getAdminId());
            SUser sUser = new SUser();
            sUser.setPhone(userModel.getPhone());
            sUser.setCreateTime(userModel.getCreateTime());
            sUser.setId(adminUser.getUserId());
            sUser.setJob(AdminUserType.getRoleByDataBaseId(Integer.parseInt(userModel.getRoleName())));
            int rows = normalUserMapper.updateByPrimaryKeySelective(sUser);
            if (rows > 0) {
                adminUser = userModel.convertAdminUserModel2AdminUser();
                rows = adminUserMapper.updateByPrimaryKeySelective(adminUser);
                if (rows <= 0) {
                    log.error("修改管理员 修改管理员信息失败,发生未知错误，插入数据库失败");
                    return CommonResponse.create(AppResponseCode.FAIL, "系统错误");
                }
                log.debug("修改管理员 修改管理员信息成功");
            }
            return CommonResponse.create(AppResponseCode.SUCCESS);
        } catch (Exception e) {
            e.printStackTrace();
            log.error("修改管理员 修改管理员信息失败 发生未知错误，详细原因：{}", e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }

    @Override
    public CommonResponse<String> removeAdminUser(List<Integer> adminUserIds) {
        try {
            adminUserIds.forEach(adminUserId -> {
                AdminUser adminUser = adminUserMapper.selectByPrimaryKey(adminUserId);
                normalUserMapper.deleteByPrimaryKey(adminUser.getUserId());
            });
            int rows = adminUserMapper.batchDeleteByPrimaryKey(adminUserIds);
            if (rows <= 0) {
                log.error("删除管理员信息时发生错误");
                return CommonResponse.create(AppResponseCode.FAIL);
            }
            return CommonResponse.create(AppResponseCode.SUCCESS);
        } catch (Exception e) {
            log.error("删除管理员信息时发生错误，详细：{}", e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }
}
