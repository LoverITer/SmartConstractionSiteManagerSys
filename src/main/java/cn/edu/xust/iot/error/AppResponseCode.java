package cn.edu.xust.iot.error;

/**
 * 程序处理响应码，参照Http响应码设计
 * 1xx 表示一些提示信息
 * 2xx 表示成功
 * 4xx 表示用户请求参数有误
 * 5xx  表示处理过程中服务器出现错误
 *
 * @author HuangXin
 * @Date 2020/3/9 3:29 下午
 */
public enum AppResponseCode {

    CAMERA_STREAM_CLOSING_ALTER_TYPE1(true,100,"设备正在结束回放,请稍后再试"),
    CAMERA_STREAM_CLOSING_ALTER_TYPE2(true,101,"设备正在结束回放,请稍后再试"),

    /**
     * 程序正常处理并返回正确结果
     */
    SUCCESS(true, 200, "成功"),
    CAMERA_OPEN_VIDEO_STREAM_SUCCESS(true,201,"打开视频流成功"),
    USER_LOGIN_SUCCESS(true,202,"用户登陆成功"),
    UPLOAD_SUCCESS(true,203,"上传成功"),


    /**
     * 请求资源不存在
     */
    NOT_FOUND(false, 404, "请求资源不存在"),

    /**
     * 通用请求参数有误
     */
    REQUEST_PARAMETER_VALID(false, 405, "请求参数有误"),
	CAMERA_REQUEST_PARAMETER_VALID(false, 4051,"摄像机直播流请求参数不完整" ),
    CAMERA_REQUEST_IP_VALID(false,4052,"摄像机直播流ip格式输入错误"),
    CAMERA_REQUEST_START_TIME_VALID(false,4053,"摄像机直播流start time格式输入错误"),
    CAMERA_REQUEST_END_TIME_VALID(false,4054,"摄像机直播流end time格式输入错误"),
    NEW_CAMERA_NOT_FOUND(false,406,"系统监测未发现摄像机"),
    AI_SERVICE_CONFLICT(false,407,"智能业务冲突"),
    CLOCK_IN_TIME_NOT_SET(false,408,"请检查是否设置上下班打卡时间段"),
    POWER_RULE_NOT_FOUND(false,409,"请先创建对应的权限规则名"),

    /**
     * 程序处理异常，发生未知错误
     */
    FAIL(false, 500, "服务器错误"),
    CAMERA_OPEN_VIDEO_STREAM_FAIL(false,501,"打开视频流失败"),
    USER_LOGIN_REPEAT(false,502,"用户重复登录"),
    USER_LOGIN_FAIL(false,503,"用户登陆失败"),
    USER_NOT_FOUND(false,504,"用户还未注册"),
    UPLOAD_FAIL(false,505,"上传失败"),
    INIT_SDK_FAIL(false,506,"初始化SDK失败"),
    ADMIN_USER_EXIST(false,507,"管理员用户名重复"),
    INCONSISTENT_PASSWORDS(false,508,"两次密码不一致");

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
