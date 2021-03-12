package cn.edu.xust.controller;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import cn.edu.xust.CommonResponse;
import cn.edu.xust.error.AppResponseCode;
import cn.edu.xust.sdc.sdk.HWPuSDK;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;

/**
 * 
 * @author HuangXin
 *
 */
@Api(value = "HelloController",description = "演示接口")
@Controller
public class HelloController {
	
	@ApiOperation(value = "初始化SDK演示",notes = "用于演示初始化华为SDK接口HWPuSDK")
	@ApiResponses({
		@ApiResponse(code = 200,message = "正确",response = CommonResponse.class),
		@ApiResponse(code = 500,message = "错误",response = CommonResponse.class)
	})
	@ResponseBody
	@GetMapping(value = "/hello")
	public CommonResponse<Map<String,Object>> hello(){
		HWPuSDK inSdk=HWPuSDK.INSTANCE;
		Map<String,Object> modelMap=new HashMap<>();
		modelMap.put("java.library.path",System.getProperty("java.library.path"));
	
		modelMap.put("HWPuSDK", inSdk.hashCode());
		return CommonResponse.create(AppResponseCode.SUCCESS, modelMap);
	}
	

}
