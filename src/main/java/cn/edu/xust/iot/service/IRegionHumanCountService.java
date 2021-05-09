package cn.edu.xust.iot.service;

import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.entity.RegionHumanCount;

import java.sql.SQLException;
import java.util.List;

/**
 * 人流量统计服务接口
 *
 * @author HuangXin
 * @since 2021/5/7 23:15
 */
public interface IRegionHumanCountService {

    /**
     * 添加或更新进入区域的人数
     *
     * @param regionId           区域ID标记一个区域
     * @param regionCrowdDensity 区域密度数（等价于区域人数）
     */
    void addHumanCountInRecord(Integer regionId, Integer regionCrowdDensity) throws SQLException;


    /**
     * 添加或更新离开区域的人数
     *
     * @param regionId           区域ID标记一个区域
     * @param regionCrowdDensity 区域密度数（等价于区域人数）
     * @throws SQLException
     */
    void addHumanCountOutRecord(Integer regionId, Integer regionCrowdDensity) throws SQLException;


    /**
     * 添加或更新总的进入区域的人数
     *
     * @param regionId
     * @param allHumanInCount
     */
    void addRegionAllHumanCountInRecord(Integer regionId, Integer allHumanInCount);

    /**
     * 添加或更新总的离开区域的人数
     *
     * @param regionId
     * @param allHumanOutCount
     */
    void addRegionAllHumanCountOutRecord(Integer regionId, Integer allHumanOutCount);

    /**
     * 获取当前小时段内的所有监控区域的人流量
     *
     * @return
     */
    CommonResponse<List<RegionHumanCount>> getRegionHumanCountHourly();

}
