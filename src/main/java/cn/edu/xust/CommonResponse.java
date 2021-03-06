package cn.edu.xust;

import cn.edu.xust.error.AppResponseCode;

/**
 * 通用JSON响应返回体
 *
 * @param <T>
 * @author Administrator
 */
public class CommonResponse<T> {

    private Integer code;
    private String msg;
    private T data;


    public CommonResponse(Integer code, String msg, T data) {
        this.code = code;
        this.msg = msg;
        this.data = data;
    }

    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    /**
     * 响应数据
     *
     * @param statusCode
     * @param data
     * @param <T>
     * @return
     */
    public static <T> CommonResponse<T> create(AppResponseCode statusCode, T data) {
        return create(statusCode.getCode(), statusCode.getMessage(), data);
    }

    public static <T> CommonResponse<T> create(AppResponseCode statusCode) {
        return create(statusCode.getCode(), statusCode.getMessage(), null);
    }


    public static <T> CommonResponse<T> create(Integer code, String msg, T data) {
        return new CommonResponse<>(code, msg, data);
    }

}
