package cn.edu.xust.iot.mapper;


import cn.edu.xust.iot.model.entity.RegionHumanCount;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface RegionHumanCountMapper {
    int deleteByPrimaryKey(Integer id);

    int insert(RegionHumanCount record);

    int insertSelective(RegionHumanCount record);

    RegionHumanCount selectByPrimaryKey(Integer id);

    /**
     * 查询小时段内所有区域的人数统计
     *
     * @return
     */
    List<RegionHumanCount> selectHourPeriodHumanCount();

    /**
     * 查询小时区间段内的某个区域的人流量记录
     *
     * @param regionId
     * @return
     */
    RegionHumanCount selectByRegionIdHourly(@Param("regionId") Integer regionId);

    int updateByPrimaryKeySelective(RegionHumanCount record);

    int updateByPrimaryKey(RegionHumanCount record);

    int updateHumanCountInByRegionIdAndTime(@Param("regionId") Integer regionId, @Param("humanIn") Integer humanIn);

    int updateHumanCountOutByRegionIdAndTime(@Param("regionId") Integer regionId, @Param("humanOut") Integer humanOut);

}