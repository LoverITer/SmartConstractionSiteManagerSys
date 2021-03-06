package cn.edu.xust.controller;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.sun.jna.ptr.PointerByReference;

import cn.edu.xust.CommonResponse;
import cn.edu.xust.error.AppResponseCode;
import cn.edu.xust.sdc.sdk.HWPuSDK;

/**
 * 
 * @author HuangXin
 *
 */
@Controller
public class HelloController {
	
	
	@ResponseBody
	@RequestMapping(value = "/hello")
	public CommonResponse<Map<String,Object>> hello(){
		HWPuSDK inSdk=HWPuSDK.INSTANCE;
		Map<String,Object> modelMap=new HashMap<>();
		modelMap.put("java.library.path",System.getProperty("java.library.path"));
	
		modelMap.put("HWPuSDK", inSdk.hashCode());
		return CommonResponse.create(AppResponseCode.SUCCESS, modelMap);
	}
	

}
