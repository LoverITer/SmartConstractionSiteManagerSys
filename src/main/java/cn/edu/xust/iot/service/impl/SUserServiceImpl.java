package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.FaceLibMapper;
import cn.edu.xust.iot.mapper.SUserMapper;
import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.SUserModel;
import cn.edu.xust.iot.model.WorkerDetailNumModel;
import cn.edu.xust.iot.model.WorkerOverviewNumModel;
import cn.edu.xust.iot.model.entity.FaceLib;
import cn.edu.xust.iot.model.entity.SUser;
import cn.edu.xust.iot.model.vo.SUserVO;
import cn.edu.xust.iot.service.ISUserService;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;

import java.util.*;

/**
 * @author HuangXin
 * @since 2021/4/15 9:37
 */
@Slf4j
@Service
public class SUserServiceImpl implements ISUserService {

    @Autowired
    private SUserMapper userMapper;

    @Autowired
    private FaceLibMapper faceLibMapper;


    @Override
    public CommonResponse<SUserVO> getMemberByID(Integer id) {
       try{
           SUserModel userModel = userMapper.selectByPrimaryKeyV2(id);
           SUserVO sUserVO = userModel.convertUserModel2UserVO();
           return CommonResponse.create(AppResponseCode.SUCCESS,sUserVO);
       }catch (Exception e){
           e.printStackTrace();
       }
       return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public PageInfo<SUserVO> getAllMembers(PageParam pageParam) {
        PageInfo<SUserVO> pages=null;
        try{
            PageHelper.startPage(pageParam.getPage(),pageParam.getPageSize());
            List<SUserModel> users = userMapper.selectAll();
            List<SUserVO> lists=new ArrayList<>();
            if(null!=users){
                users.forEach(user->{
                    SUserVO sUserVO = user.convertUserModel2UserVO();
                    lists.add(sUserVO);
                });
            }
            pages=new PageInfo<>(lists);
        }catch (Exception e){
            e.printStackTrace();
            log.error(e.getMessage());
            return null;
        }
        return pages;
    }

    @Override
    public CommonResponse<Integer> getAllMembersSize() {
        try{
            return CommonResponse.create(AppResponseCode.SUCCESS,userMapper.countMembers());
        }catch (Exception e){
            e.printStackTrace();
            log.error("获取人员数量发生错误,信息错误：{}",e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL,0);
        }
    }

    @Override
    public CommonResponse<WorkerOverviewNumModel> getWorkerOverviewNums(){
        try{
            WorkerOverviewNumModel workerNum = userMapper.countWorkerOverviewNum();
            return CommonResponse.create(AppResponseCode.SUCCESS,workerNum);
        }catch (Exception e){
            e.printStackTrace();
            log.error("获取人员数量发生错误,信息错误：{}",e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }


    @Override
    public CommonResponse<Map<String,List<String>>> getWorkerDetailNums(){
        try{
            Map<String,List<String>> workerDetailNumMap=new HashMap<>();
            List<WorkerDetailNumModel> workDetailNumModel = userMapper.countWorkerDetailNum();
            List<String> jobNameList=new ArrayList<>();
            List<String> workerNumList=new ArrayList<>();
            if(null!=workDetailNumModel){
                workDetailNumModel.forEach(workerDetail->{
                    jobNameList.add(workerDetail.getJob());
                    workerNumList.add(String.valueOf(workerDetail.getNum()));
                });
            }
            workerDetailNumMap.put("jobNameList",jobNameList);
            workerDetailNumMap.put("workerNumList",workerNumList);
            return CommonResponse.create(AppResponseCode.SUCCESS,workerDetailNumMap);
        }catch (Exception e){
            e.printStackTrace();
            log.error("获取人员数量详细数据发生错误,信息错误：{}",e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }

    @Transactional(isolation= Isolation.REPEATABLE_READ,rollbackFor = Exception.class)
    @Override
    public CommonResponse<String> addNewMembers(SUserModel userModel) {
        if(null==userModel){
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        SUser sUser = userModel.convertUserModel2SUser();
        FaceLib faceLib = new FaceLib(userModel.getUserAvatarUrl(),new Date());
        try {
            int rows = faceLibMapper.insertSelective(faceLib);
            if(rows<=0){
                log.error("添加新成员 插入人脸库发生错误");
                return CommonResponse.create(AppResponseCode.FAIL);
            }
            sUser.setFaceLibId(faceLib.getId());
            int rows2 = userMapper.insertSelective(sUser);
            if(rows2<=0){
                log.error("添加新成员 插入人员库发生错误");
                return CommonResponse.create(AppResponseCode.FAIL);
            }
            return CommonResponse.create(AppResponseCode.SUCCESS);
        } catch (Exception e){
            e.printStackTrace();
            log.error("添加新成员 发生未知错误，详细原因：{}",e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }

    @Transactional(isolation= Isolation.REPEATABLE_READ,rollbackFor = Exception.class)
    @Override
    public CommonResponse<String> editMemberInfo(SUserModel userModel) {
        try{
            SUser sUser = userModel.convertUserModel2SUser();
            Integer userId = userModel.getUserId();
            SUser user = userMapper.selectByPrimaryKey(userId);
            if(null==user){
                return CommonResponse.create(AppResponseCode.FAIL);
            }
            //处理管理员人脸库后来修改的那种情况
            if(user.getFaceLibId()==null){
                FaceLib faceLib = new FaceLib(userModel.getUserAvatarUrl(), new Date());
                int rows = faceLibMapper.insert(faceLib);
                if(rows>0){
                    sUser.setFaceLibId(faceLib.getId());
                }
            }else {
                //同步更新人脸库
                FaceLib faceLib = new FaceLib();
                faceLib.setId(user.getFaceLibId());
                faceLib.setFacePic(userModel.getUserAvatarUrl());
                faceLibMapper.updateByPrimaryKeySelective(faceLib);
            }
            int rows = userMapper.updateByPrimaryKeySelective(sUser);
            if(rows<=0){
                return CommonResponse.create(AppResponseCode.FAIL);
            }
            return CommonResponse.create(AppResponseCode.SUCCESS);
        }catch (Exception e){
            e.printStackTrace();
            log.error("修改人员信息失败 发生未知错误，详细原因：{}",e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }

    @Transactional(isolation= Isolation.REPEATABLE_READ,rollbackFor = Exception.class)
    @Override
    public CommonResponse<String> removeMemberBatch(List<Integer> userIdList) {
        try{
            List<Integer> faceLibIds = userMapper.selectFaceLibIdBatch(userIdList);
            faceLibMapper.deleteByPrimaryKeyBatch(faceLibIds);
            int rows = userMapper.batchDeleteByPrimaryKey(userIdList);
            if(rows<=0){
                log.error("删除人员信息时发生错误");
                return CommonResponse.create(AppResponseCode.FAIL);
            }
            return CommonResponse.create(AppResponseCode.SUCCESS);
        }catch (Exception e){
            log.error("删除人员信息时发生错误，详细：{}",e.getMessage());
            return CommonResponse.create(AppResponseCode.FAIL);
        }
    }
}
