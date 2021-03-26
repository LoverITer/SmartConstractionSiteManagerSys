package cn.edu.xust.error;

/**
 * @author HuangXin
 * @Date 2020/3/9 3:29 下午
 */

public enum AppResponseCode {

	/**
	 * 程序正常处理并返回正确结果
	 */
	SUCCESS(true, 200, "正确"),

	/**
	 * 请求资源不存在
	 */
	NOT_FOUND(false, 404, "请求资源不存在"),

	/**
	 * 请求参数有误
	 */
	REQUEST_PARAMETER_VALID(false, 405, "请求参数有误"),

	/**
	 * 程序处理异常，发生未知错误
	 */
	FAIL(false, 500, "错误");

	Boolean success;
	Integer code;
	String message;

	AppResponseCode(Boolean success, Integer code, String message) {
		this.success = success;
		this.code = code;
		this.message = message;
	}

	public Integer getCode() {
		return code;
	}

	public String getMessage() {
		return message;
	}

	public Boolean getSuccess() {
		return success;
	}

	public void setCode(Integer code) {
		this.code = code;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public void setSuccess(Boolean success) {
		this.success = success;
	}

	@Override
	public String toString() {
		return "ShopCode{" + "success=" + success + ", code=" + code + ", message='" + message + '\'' + '}';
	}
}
