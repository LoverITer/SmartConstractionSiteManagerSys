package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.RegionHumanCountMapper;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.RegionHumanCount;
import cn.edu.xust.iot.service.IRegionHumanCountService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.sql.SQLException;
import java.util.Collections;
import java.util.List;

/**
 * 人流量统计服务接口实现类
 *
 * @author HuangXin
 * @since 2021/5/7 23:15
 */
@Slf4j
@Service(value = "regionHumanCountService")
public class RegionHumanCountServiceImpl implements IRegionHumanCountService {

    @Autowired
    private RegionHumanCountMapper regionHumanCountMapper;

    @Override
    public void addHumanCountInRecord(Integer regionId, Integer humanCountIn) throws SQLException {
        if (null == regionId || regionId <= 0) {
            throw new IllegalArgumentException("Incorrect parameter regionId");
        }
        RegionHumanCount humanCounter = regionHumanCountMapper.selectByRegionIdHourly(regionId);
        if (null == humanCounter) {
            //数据库中没有该时间段的人群数量记录，直接插入新记录
            humanCounter = new RegionHumanCount(regionId, humanCountIn,null);
            addNewHumanCountRecord(humanCounter);
        } else {
            //数据库中有该时间段(比如10:00-11:00)的人群数量记录，尝试更新
            Integer allHumanInNum = humanCounter.getHumanIn()+humanCountIn;

            try{
                int rows = regionHumanCountMapper.updateHumanCountInByRegionIdAndTime(regionId, allHumanInNum);
                if (rows <= 0) {
                    throw new SQLException("更新区域人数记录失败");
                }
                log.info("更新区域人数记录：更新成功，当前区域人数小于历史最大区域人数");
            }catch (Exception e){
                log.error("更新区域人数记录：更新发生异常");
                e.printStackTrace();
            }
        }
    }

    @Override
    public void addHumanCountOutRecord(Integer regionId, Integer humanCountOut) throws SQLException {
        if (null == regionId || regionId <= 0) {
            throw new IllegalArgumentException("Incorrect parameter regionId");
        }
        RegionHumanCount humanCounter = regionHumanCountMapper.selectByRegionIdHourly(regionId);
        if (null == humanCounter) {
            //数据库中没有该时间段的人群数量记录，直接插入新记录
            humanCounter = new RegionHumanCount(regionId,null, humanCountOut);
            addNewHumanCountRecord(humanCounter);
        } else {
            //数据库中有该时间段(比如10:00-11:00)的人群数量记录，尝试更新
            Integer allHumanInNum = humanCounter.getHumanIn()+humanCountOut;

            try{
                int rows = regionHumanCountMapper.updateHumanCountOutByRegionIdAndTime(regionId, allHumanInNum);
                if (rows <= 0) {
                    throw new SQLException("更新区域人数记录失败");
                }
                log.info("更新区域人数记录：更新成功，当前区域人数小于历史最大区域人数");
            }catch (Exception e){
                log.error("更新区域人数记录：更新发生异常");
                e.printStackTrace();
            }
        }
    }


    public boolean addNewHumanCountRecord(RegionHumanCount regionHumanCount){
        try{
            int rows = regionHumanCountMapper.insertSelective(regionHumanCount);
            if (rows <= 0) {
                throw new SQLException("插入新的区域失败");
            }
            log.info("新增区域{}人数记录：新增成功，当前区域人数小于历史最大区域人数",regionHumanCount.getRegionId());
            return true;
        }catch (Exception e){
            log.info("新增区域{}人数记录：新增发生异常",regionHumanCount.getRegionId());
            e.printStackTrace();
        }
        return false;
    }


    @Override
    public void addRegionAllHumanCountInRecord(Integer regionId, Integer allHumanInCount) {
        if (null == regionId || regionId <= 0) {
            throw new IllegalArgumentException("Incorrect parameter regionId");
        }
        RegionHumanCount humanCounter = regionHumanCountMapper.selectByRegionIdHourly(regionId);
        if(null==humanCounter){
            humanCounter = new RegionHumanCount(regionId,allHumanInCount, null);
            addNewHumanCountRecord(humanCounter);
        }else{
            if(!humanCounter.getHumanIn().equals(allHumanInCount)){
                try{
                    int rows = regionHumanCountMapper.updateHumanCountInByRegionIdAndTime(regionId, allHumanInCount);
                    if (rows <= 0) {
                        throw new SQLException("更新区域人数记录失败");
                    }
                    log.info("更新区域人数记录：更新成功，当前区域人数小于历史最大区域人数");
                }catch (Exception e){
                    log.error("更新区域人数记录：更新发生异常");
                    e.printStackTrace();
                }
            }
        }
    }

    @Override
    public void addRegionAllHumanCountOutRecord(Integer regionId, Integer allHumanOutCount) {
        if (null == regionId || regionId <= 0) {
            throw new IllegalArgumentException("Incorrect parameter regionId");
        }
        RegionHumanCount humanCounter = regionHumanCountMapper.selectByRegionIdHourly(regionId);
        if(null==humanCounter){
            humanCounter = new RegionHumanCount(regionId,null, allHumanOutCount);
            addNewHumanCountRecord(humanCounter);
        }else{
            if(!humanCounter.getHumanOut().equals(allHumanOutCount)){
                try{
                    int rows = regionHumanCountMapper.updateHumanCountOutByRegionIdAndTime(regionId, allHumanOutCount);
                    if (rows <= 0) {
                        throw new SQLException("更新区域人数记录失败");
                    }
                    log.info("更新区域人数记录：更新成功，当前区域人数小于历史最大区域人数");
                }catch (Exception e){
                    log.error("更新区域人数记录：更新发生异常");
                    e.printStackTrace();
                }
            }
        }
    }

    @Override
    public CommonResponse<List<RegionHumanCount>> getRegionHumanCountHourly() {
        List<RegionHumanCount> regionHumanCountList=null;
        try{
             regionHumanCountList = regionHumanCountMapper.selectHourPeriodHumanCount();
            Collections.sort(regionHumanCountList);
        }catch (Exception e){
            log.error("获取区域人流量数据发生异常：");
            e.printStackTrace();
        }
        return CommonResponse.create(AppResponseCode.SUCCESS,regionHumanCountList);
    }
}
