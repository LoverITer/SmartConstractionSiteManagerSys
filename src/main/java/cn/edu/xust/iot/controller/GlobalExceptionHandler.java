package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.error.BusinessException;
import cn.edu.xust.iot.error.EmBusinessError;
import cn.edu.xust.iot.model.CommonResponse;
import org.springframework.web.bind.ServletRequestBindingException;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.NoHandlerFoundException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.HashMap;
import java.util.Map;



/**
 * 全局异常处理
 * 
 * @author HuangXin
 * @since 2021/03/17 09:38
 */
@ControllerAdvice
public class GlobalExceptionHandler {

	@ExceptionHandler(Exception.class)
	@ResponseBody
	public CommonResponse<Map<String, Object>> doError(HttpServletRequest httpServletRequest,
													   HttpServletResponse httpServletResponse, Exception ex) {
		ex.printStackTrace();
		Map<String, Object> responseData = new HashMap<>();
		if (ex instanceof BusinessException) {
			BusinessException businessException = (BusinessException) ex;
			responseData.put("errCode", businessException.getErrCode());
			responseData.put("errMsg", businessException.getErrMsg());
		} else if (ex instanceof ServletRequestBindingException) {
			responseData.put("errCode", EmBusinessError.UNKNOWN_ERROR.getErrCode());
			responseData.put("errMsg", "url绑定路由问题");
		} else if (ex instanceof NoHandlerFoundException) {
			responseData.put("errCode", EmBusinessError.UNKNOWN_ERROR.getErrCode());
			responseData.put("errMsg", "没有找到对应的访问路径");
		} else {
			responseData.put("errCode", EmBusinessError.UNKNOWN_ERROR.getErrCode());
			responseData.put("errMsg", EmBusinessError.UNKNOWN_ERROR.getErrMsg());
		}
		return CommonResponse.create(AppResponseCode.FAIL, responseData);
	}

}
