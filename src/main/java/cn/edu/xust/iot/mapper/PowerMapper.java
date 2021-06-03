package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.model.entity.Power;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface PowerMapper {
    int deleteByPrimaryKey(Integer id);

    int insert(Power record);

    int insertSelective(Power record);

    Integer selectPowerIdByPowerRule(@Param("powerRule") String powerRule);

    Power selectByPrimaryKey(Integer id);

    List<Power>  selectAll();

    int countPowerRuleNum();

    int updateByPrimaryKeySelective(Power record);

    int updateByPrimaryKey(Power record);
}