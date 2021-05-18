package cn.edu.xust.iot.service;

import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.SUserModel;
import cn.edu.xust.iot.model.WorkerOverviewNumModel;
import cn.edu.xust.iot.model.vo.SUserVO;
import com.github.pagehelper.PageInfo;

import java.util.List;
import java.util.Map;

/**
 * 成员管理服务接口
 *
 * @author HuangXin
 * @since 2021/4/15 9:35
 */
public interface ISUserService {

    /**
     * 根据用户ID查询用户信息
     *
     * @param id
     * @return
     */
    CommonResponse<SUserVO> getMemberByID(Integer id);


    /**
     * 获得所有的成员（工人）
     *
     * @return
     */
    PageInfo<SUserVO> getAllMembers(PageParam pageParam);


    /**
     * 获取人员数量
     *
     * @return
     */
    CommonResponse<Integer> getAllMembersSize();

    /**
     * 获取系统各种人员的数量概况
     *
     * @return
     */
    CommonResponse<WorkerOverviewNumModel> getWorkerOverviewNums();

    /**
     * 获取系统各种人员的数量详细数据
     *
     * @return
     */
    CommonResponse<Map<String, List<String>>> getWorkerDetailNums();

    /**
     * 添加新成员（工人）
     *
     * @param userModel
     * @return
     */
    CommonResponse<String> addNewMembers(SUserModel userModel);

    /**
     * 修改人员信息
     *
     * @param userModel
     * @return
     */
    CommonResponse<String> editMemberInfo(SUserModel userModel);

    /**
     * 删除人员，支持批量删除
     *
     * @param userIdList
     * @return
     */
    CommonResponse<String> removeMemberBatch(List<Integer> userIdList);

}
