package cn.edu.xust.iot.model.vo;

import com.fasterxml.jackson.annotation.JsonInclude;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@Data
@JsonInclude(JsonInclude.Include.NON_EMPTY)
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class WeatherResultVO implements Serializable{
    private String date;
    private String time;
    //城市name 如 茶陵
    private String city;
    //城市id
    private String citykey;
    //父级城市，比如市级，省级
    private String parent;
    //更新时间
    private String updateTime;
    private String shidu;
    private Double pm25;
    private Double pm10;
    private String quality;
    private String wendu;
//    //风速
    private String windPower;
//    //风向
    private String windDirection;

}
