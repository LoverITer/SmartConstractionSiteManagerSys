package cn.edu.xust.iot.model.entity;

import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

import java.util.Date;

/**
 * 区域人流量统计实体类
 */
@Data
@ToString
@NoArgsConstructor
public class RegionHumanCount implements Comparable<RegionHumanCount>{
    private Integer id;

    private Integer regionId;

    /**
     * 进入区域的人数
     */
    private Integer humanIn;

    /**
     * 离开区域的人数
     */
    private Integer humanOut;

    private Date createDate;

    public RegionHumanCount(Integer regionId, Integer humanIn,Integer humanOut) {
        this.regionId = regionId;
        this.humanIn = humanIn;
        this.humanOut=humanOut;
        this.createDate = new Date();
    }


    @Override
    public int compareTo(RegionHumanCount regionHumanCount) {
        int cnt1=this.humanIn=this.humanOut;
        int cnt2=regionHumanCount.humanIn+regionHumanCount.humanOut;
        if(cnt1-cnt2<0){
            return -1;
        }else if(cnt1-cnt2>0){
            return 1;
        }
        return 0;
    }
}