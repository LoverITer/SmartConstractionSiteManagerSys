package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.CommonResponse;
import cn.edu.xust.iot.entity.po.Danger;
import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.sdc.core.HWPuSDK;
import cn.edu.xust.iot.service.IDangerService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author HuangXin
 *
 */
@Api(value = "HelloController", description = "演示接口")
@Controller
public class HelloController {

	@Autowired
	private IDangerService dangerService;

	/**
	 * 演示接口——接口会初始化华为提供的dll库，借助这个对象我们就可以访问华为SDC提供的服务
	 *
	 * @return
	 */
	@ApiOperation(value = "初始化SDK演示", notes = "用于演示初始化华为SDK接口HWPuSDK")
	@ApiResponses({ @ApiResponse(code = 200, message = "正确", response = CommonResponse.class),
			@ApiResponse(code = 500, message = "错误", response = CommonResponse.class) })
	@ResponseBody
	@GetMapping(value = "/hello")
	public CommonResponse<Map<String, Object>> hello() {
		HWPuSDK inSdk = HWPuSDK.INSTANCE;
		Map<String, Object> modelMap = new HashMap<>();
		modelMap.put("java.library.path", System.getProperty("java.library.path"));

		modelMap.put("HWPuSDK", inSdk.hashCode());
		return CommonResponse.create(AppResponseCode.SUCCESS, modelMap);
	}

	/**
	 *
	 * @param id
	 * @return
	 */
	@ApiOperation(value = "CRUD测试", notes = "用于测试程序是否可以正常的走通整个CRUD流程 : controller<-->service<-->mapper<-->database")
	@ApiResponses({ @ApiResponse(code = 200, message = "正确", response = Danger.class) })
	@ResponseBody
	@GetMapping(value = "/crud/{id}")
	public CommonResponse<Danger> testCanCRUD(@PathVariable(value = "id", required = true) Integer id) {
		System.out.println("输入参数 id=" + id);
		Danger danger = dangerService.getDangerInfo(id);
		return CommonResponse.create(AppResponseCode.SUCCESS, danger);
	}

}
