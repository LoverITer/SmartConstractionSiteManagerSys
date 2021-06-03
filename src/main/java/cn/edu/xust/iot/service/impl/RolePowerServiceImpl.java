package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.PowerMapper;
import cn.edu.xust.iot.mapper.RoleMapper;
import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Power;
import cn.edu.xust.iot.model.entity.Role;
import cn.edu.xust.iot.model.vo.RoleVO;
import cn.edu.xust.iot.service.IRolePowerService;
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
 * @since 2021/6/1 20:13
 */
@Slf4j
@Service
public class RolePowerServiceImpl implements IRolePowerService {

    @Autowired
    private PowerMapper powerMapper;

    @Autowired
    private RoleMapper roleMapper;

    @Transactional(rollbackFor = Exception.class, isolation = Isolation.REPEATABLE_READ)
    @Override
    public CommonResponse<String> addNewRole(RoleVO roleVO) {
        try {
            Integer powerId = powerMapper.selectPowerIdByPowerRule(roleVO.getPowerName());
            if (null == powerId || powerId <= 0) {
                return CommonResponse.create(AppResponseCode.POWER_RULE_NOT_FOUND);
            }
            Role role = new Role();
            role.setRoleName(roleVO.getRoleName());
            role.setDescription(roleVO.getDescription());
            role.setStatus("1");
            role.setPowerId(powerId);
            int rows = roleMapper.insert(role);
            if (rows > 0) {
                log.debug("添加角色 新增角色 {} 成功", role.getRoleName());
                return CommonResponse.create(AppResponseCode.SUCCESS);
            }
        } catch (Exception e) {
            log.error("添加角色 新增角色失败,原因是：{}", e.getMessage());
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public PageInfo<RoleVO> getRoleList(PageParam pageParam) {
        PageInfo<RoleVO> pages = null;
        try {
            PageHelper.startPage(pageParam.getPage(), pageParam.getPageSize());
            List<RoleVO> roleList = roleMapper.selectWithPowerName();
            pages = new PageInfo<>(roleList);
        } catch (Exception e) {
            e.printStackTrace();
            log.error("查询角色数据发生错误:{}", e.getMessage());

        }
        return pages;
    }

    @Override
    public CommonResponse<Integer> getAllRoleSize() {
        int roleSize = 0;
        try {
            roleSize = roleMapper.countRoleNum();
            return CommonResponse.create(AppResponseCode.SUCCESS, roleSize);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL, roleSize);
    }

    @Override
    public CommonResponse<String> editAdminUser(RoleVO roleVO) {
        return null;
    }

    @Override
    public CommonResponse<String> removeRole(List<Integer> roleIds) {
        try {
            int rows = roleMapper.deleteByPrimaryKeyBatch(roleIds);
            if (rows <= 0) {
                log.error("删除角色信息时发生错误");
                return CommonResponse.create(AppResponseCode.FAIL);
            }
            return CommonResponse.create(AppResponseCode.SUCCESS);
        } catch (Exception e) {
            log.error("删除角色信息时发生错误，详细：{}", e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }

    @Override
    public CommonResponse<String> addNewPower(Power power) {
        try {
            int rows = powerMapper.insertSelective(power);
            if (rows > 0) {
                log.debug("添加权限规则 新增权限规则  {} 成功", power.getPowerRule());
                return CommonResponse.create(AppResponseCode.SUCCESS);
            }
        } catch (Exception e) {
            log.error("添加权限规则 新增权限规则失败,原因是：{}", e.getMessage());
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<String> updateRoleStatus(String status, Integer roleId) {
        Role role = new Role();
        role.setStatus(status);
        role.setId(roleId);
        int rows = roleMapper.updateByPrimaryKeySelective(role);
        if (rows > 0) {
            return CommonResponse.create(AppResponseCode.SUCCESS);
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public PageInfo<Power> getPowerList(PageParam pageParam) {
        PageInfo<Power> pages = null;
        try {
            PageHelper.startPage(pageParam.getPage(), pageParam.getPageSize());
            List<Power> powerList = powerMapper.selectAll();
            pages = new PageInfo<>(powerList);
        } catch (Exception e) {
            e.printStackTrace();
            log.error("查询权限规则数据发生错误:{}", e.getMessage());

        }
        return pages;
    }

    @Override
    public CommonResponse<Integer> getAllPowerSize() {
        int roleSize = 0;
        try {
            roleSize = powerMapper.countPowerRuleNum();
            return CommonResponse.create(AppResponseCode.SUCCESS, roleSize);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL, roleSize);
    }
}
