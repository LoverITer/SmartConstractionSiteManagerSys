package cn.edu.xust.iot.model;

import com.fasterxml.jackson.annotation.JsonInclude;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 * 实体接收类
 */
@lombok.Data
@JsonInclude(JsonInclude.Include.NON_EMPTY)
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class WeatherDto implements Serializable {

    private String message;
    private int status;
    //第一天时间
    private String date;
    private String time;
    //当前主题信息
    private CityInfo cityInfo;
    private WeatherData data;


    public boolean isSuccess(){
        return this.status == 200;
    }
    /**
     * 当前城市信息
     */
    @lombok.Data
    @JsonInclude(JsonInclude.Include.NON_NULL)
    public static class CityInfo implements Serializable {
        //城市name 如 茶陵
        private String city;
        //城市id
        private String citykey;
        //父级城市，比如市级，省级
        private String parent;
        //更新时间
        private String updateTime;


    }


    ///////////////////////////  天气主体信息 ///////////////////////////////////
    @lombok.Data
    @JsonInclude(JsonInclude.Include.NON_EMPTY)
    @AllArgsConstructor
    @NoArgsConstructor
    @Builder
    public static class WeatherData  implements Serializable{

        //兼容字段
        private String shidu;
        private Double pm25;
        private Double pm10;
        private String quality;
        private String wendu;
        private String ganmao;
        private List<Forecast> forecast = new ArrayList<>();
        //昨天，从forecast取一条放到 yesterday
        private Forecast yesterday;

        /**
         * 天气预报，一天
         */
        @lombok.Data
        @JsonInclude(JsonInclude.Include.NON_NULL)
        public static class Forecast implements Serializable {

            //日期
            private String date;
            //最高温度，最低温度
            private String high;
            private String low;
            private String ymd;
            private String week;
            //日出 & 日落
            private String sunrise;
            private String sunset;
            //空气质量
            private Integer aqi;

            //兼容字段
            //风向
            private String fx;
            //风力
            private String fl;
            //天气类型
            private String type;
            private String notice;
        }
    }
}


