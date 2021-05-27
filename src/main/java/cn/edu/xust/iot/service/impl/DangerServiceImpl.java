package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.DangerBehaviorMapper;
import cn.edu.xust.iot.mapper.DangerMapper;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.Danger;
import cn.edu.xust.iot.model.entity.DangerBehavior;
import cn.edu.xust.iot.model.vo.*;
import cn.edu.xust.iot.service.IDangerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;

import java.util.HashMap;
import java.util.List;
import java.util.Map;


/**
 * @author HuangXin
 * @since 2021/03/16 19:59
 */
@Service
public class DangerServiceImpl implements IDangerService {

    @Autowired
    private DangerMapper dangerMapper;
    @Autowired
    private DangerBehaviorMapper dangerBehaviorMapper;

    @Override
    public Danger getDangerInfo(int id) {
        return dangerMapper.selectByPrimaryKey(id);
    }

    @Override
    public CommonResponse<List<DangerBehaviorHalfMonthAmountVO>> getHalfMonthDangerBehaviorAmount() {
        try {
            List<DangerBehaviorHalfMonthAmountVO> halfMonthAmount = dangerBehaviorMapper.countHalfMonthDangerBehaviorNum();
            return CommonResponse.create(AppResponseCode.SUCCESS, halfMonthAmount);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<List<DangerBehaviorHalfMonthAmountVO>> getHalfMonthUnsafeBehaviorAmount() {
        try {
            List<DangerBehaviorHalfMonthAmountVO> halfMonthAmount = dangerBehaviorMapper.countHalfMonthUnsafeBehaviorNum();
            return CommonResponse.create(AppResponseCode.SUCCESS, halfMonthAmount);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<List<UnSafeBehaviorAmountVO>> getTodayUnsafeBehaviorAmount() {
        try {
            List<UnSafeBehaviorAmountVO> unSafeBehaviorAmount = dangerBehaviorMapper.countTodayUnsafeNumBehaviorByBehaviorType(null);
            return CommonResponse.create(AppResponseCode.SUCCESS, unSafeBehaviorAmount);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<List<UnSafeBehaviorAmountVO>> getTodayBehaviorAmountTop5(String behaviorType) {
        try {
            List<UnSafeBehaviorAmountVO> unSafeBehaviorList = null;
            if("UNSAFE".equals(behaviorType)){
                unSafeBehaviorList=dangerBehaviorMapper.countTodayUnsafeNumBehaviorByBehaviorType(1);
            }else if("DANGER".equals(behaviorType)) {
                unSafeBehaviorList = dangerBehaviorMapper.countTodayDangerNumBehaviorByBehaviorType(1);
            }
            return CommonResponse.create(AppResponseCode.SUCCESS, unSafeBehaviorList);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<List<DangerBehaviorVO>> getTodayDangerBehavior() {
        try {
            List<DangerBehaviorVO> dangerBehaviorList = dangerBehaviorMapper.selectTodayDangerBehaviorByBehaviorType();
            return CommonResponse.create(AppResponseCode.SUCCESS, dangerBehaviorList);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<Integer> getTodayDangerBehaviorNum() {
        try {
            int todayDangerBehaviorNum = dangerBehaviorMapper.countTodayDangerBehaviorNum();
            return CommonResponse.create(AppResponseCode.SUCCESS, todayDangerBehaviorNum);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<DangerBehaviorTodayOverviewAmountVO> getTodayDangerBehaviorTodayOverviewNum() {
        try {
            DangerBehaviorTodayOverviewAmountVO todayOverviewAmount = dangerBehaviorMapper.countTodayAllDangerBehaviorNum();
            return CommonResponse.create(AppResponseCode.SUCCESS, todayOverviewAmount);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Transactional(isolation = Isolation.REPEATABLE_READ,rollbackFor = Exception.class)
    @Override
    public CommonResponse<Boolean> dealDangerBehavior(Integer id) {
        try {
            DangerBehavior dangerBehavior = new DangerBehavior();
            dangerBehavior.setId(id);
            dangerBehavior.setState("1");
            int rows = dangerBehaviorMapper.updateByPrimaryKeySelective(dangerBehavior);
            if(rows>=0){
                return CommonResponse.create(AppResponseCode.SUCCESS,true);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }

    @Override
    public CommonResponse<List<DangerBehaviorPersonnelNoticeVO>> getHistoryPersonnelDangerBehavior() {
        try {
            List<DangerBehaviorPersonnelNoticeVO> personnelNoticeList = dangerBehaviorMapper.selectPersonnelDangerRecords();
            if(null!=personnelNoticeList&&personnelNoticeList.size()>0){
                List<DangerBehaviorPersonnelAmountVO> personnelAmount = dangerBehaviorMapper.countPersonnelAllDangerRecordsNum();
                if(null!=personnelAmount&&personnelAmount.size()>0){
                    //合并两个 List
                    HashMap<String, Integer> map = new HashMap<>();
                    personnelAmount.forEach(amount->{
                        map.put(amount.getName(),amount.getPersonNoticeTimeSum());
                    });

                    personnelNoticeList.forEach(notices->{
                        notices.setPersonNoticeTimeSum(map.get(notices.getName()));
                    });
                    return CommonResponse.create(AppResponseCode.SUCCESS,personnelNoticeList);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }


    @Override
    public CommonResponse<List<UnSafeBehaviorAmountVO>> getAllTypeDangerBehaviorAmount() {
        try {
            List<Danger> dangerTypeList = dangerMapper.selectAllDangerType();
            if(null!=dangerTypeList&&dangerTypeList.size()>0) {
                List<UnSafeBehaviorAmountVO> behaviorAmountList = dangerBehaviorMapper.countAllTypeDangerBehaviorNum();
                if(null!=behaviorAmountList&&behaviorAmountList.size()>0){
                    Map<String,String> map = new HashMap<>();
                    for (UnSafeBehaviorAmountVO unSafeBehaviorAmount : behaviorAmountList) {
                        map.put(unSafeBehaviorAmount.getUnsafeBehaviorName(),unSafeBehaviorAmount.getUnsafeBehaviorName());
                    }

                    for (Danger danger : dangerTypeList) {
                        if(null==map.get(danger.getDangerName())){
                            UnSafeBehaviorAmountVO unSafeBehaviorAmountVO = new UnSafeBehaviorAmountVO();
                            unSafeBehaviorAmountVO.setUnsafeBehaviorName(danger.getDangerName());
                            behaviorAmountList.add(unSafeBehaviorAmountVO);
                        }
                    }
                    return  CommonResponse.create(AppResponseCode.SUCCESS,behaviorAmountList);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.FAIL);
    }
}
