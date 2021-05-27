package cn.edu.xust.iot.controller;



import cn.edu.xust.iot.model.vo.WeatherResultVO;
import cn.edu.xust.iot.service.impl.WeatherManagerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;


@RestController
@RequestMapping("/api")
public class WeatherController {

    @Autowired
    private WeatherManagerService weatherManager;

    //用来校验传参是否正确
    @Value("${city.code}")
    private String cityCode;

    /**
     * 天气数据
     * @param id
     * @return
     */
    @RequestMapping(value = "city/{id:1[0-9]{8}}", method = RequestMethod.GET)
    public WeatherResultVO loadApi(@PathVariable("id") String id){
        String vliCode = String.format(",%s,", id);
        if(!cityCode.contains(vliCode)){
            throw new RuntimeException("no_city_id");
        }
        return weatherManager.getById(id);
    }
}
