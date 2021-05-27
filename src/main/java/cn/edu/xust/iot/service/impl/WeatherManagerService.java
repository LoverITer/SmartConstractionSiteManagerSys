package cn.edu.xust.iot.service.impl;


import cn.edu.xust.iot.model.WeatherDto;
import cn.edu.xust.iot.model.vo.WeatherResultVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestClientException;
import org.springframework.web.client.RestTemplate;

@Service
@Slf4j
public class WeatherManagerService {
    //请求连接地址
    final static String SOJSON_WEATHER_URL = "http://t.weather.itboy.net/api/weather/city/{1}";

    /**
     * 获取数据
     * @param id
     * @return
     */
    public WeatherResultVO getById(String id) {
        log.info("WeatherManager#getById: id={}", id);
        try {
            RestTemplate restTemplate = new RestTemplate();
            WeatherDto dto = restTemplate.getForObject(SOJSON_WEATHER_URL , WeatherDto.class,id);
            WeatherResultVO result = new WeatherResultVO();
            result.setDate(dto.getDate());
            result.setTime(dto.getTime());
            result.setCity(dto.getCityInfo().getCity());
            result.setCitykey(dto.getCityInfo().getCitykey());
            result.setParent(dto.getCityInfo().getParent());
            result.setUpdateTime(dto.getCityInfo().getUpdateTime());
            result.setShidu(dto.getData().getShidu());
            result.setPm25(dto.getData().getPm25());
            result.setPm10(dto.getData().getPm10());
            result.setQuality(dto.getData().getQuality());
            result.setWendu(dto.getData().getWendu());
            if(result != null && dto.isSuccess()){
                return result;
            }else{
                log.error("获取天气数据返回错误：{}", dto);
            }
        } catch (RestClientException e) {
            log.error("获取天气数据返回错误，出现异常.", e);
        }
        return null;
    }

}
