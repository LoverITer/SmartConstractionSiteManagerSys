package cn.edu.xust.iot.service;

import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Power;
import cn.edu.xust.iot.model.vo.RoleVO;
import com.github.pagehelper.PageInfo;

import java.util.List;

/**
 * @author HuangXin
 * @since 2021/6/1 20:13
 */
public interface IRolePowerService {

    /**
     * 添加新的角色
     *
     * @param roleVO
     * @return
     */
    CommonResponse<String> addNewRole(RoleVO roleVO);

    /**
     * 获取所有的角色数据
     *
     * @param pageParam
     * @return
     */
    PageInfo<RoleVO> getRoleList(PageParam pageParam);

    /**
     * 获取所有角色数
     *
     * @return
     */
    CommonResponse<Integer> getAllRoleSize();

    /**
     * 修改角色信息
     *
     * @param roleVO
     * @return
     */
    CommonResponse<String> editAdminUser(RoleVO roleVO);

    /**
     * 删除角色，支持批量删除
     *
     * @param roleIds
     * @return
     */
    CommonResponse<String> removeRole(List<Integer> roleIds);

    /**
     * 更新角色状态
     *
     * @param status
     * @return
     */
    CommonResponse<String> updateRoleStatus(String status,Integer roleId);

    /**
     * 添加新的权限规则
     *
     * @param power
     * @return
     */
    CommonResponse<String> addNewPower(Power power);


    /**
     * 获取所有的角色数据
     *
     * @param pageParam
     * @return
     */
    PageInfo<Power> getPowerList(PageParam pageParam);

    /**
     * 获取所有角色数
     *
     * @return
     */
    CommonResponse<Integer> getAllPowerSize();

}
