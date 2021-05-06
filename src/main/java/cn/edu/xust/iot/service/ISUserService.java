package cn.edu.xust.iot.service;

import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.SUserModel;
import cn.edu.xust.iot.model.WorkerNumModel;
import cn.edu.xust.iot.model.vo.SUserVO;
import com.github.pagehelper.PageInfo;

import java.util.List;

/**
 * 成员管理服务接口
 *
 * @author HuangXin
 * @since 2021/4/15 9:35
 */
public interface ISUserService {

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
     * 获取系统各种人员的数量
     *
     * @return
     */
    CommonResponse<WorkerNumModel> getWorkerNums();

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
