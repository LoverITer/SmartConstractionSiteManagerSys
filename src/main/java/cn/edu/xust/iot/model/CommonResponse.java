package cn.edu.xust.iot.model;


import cn.edu.xust.iot.error.AppResponseCode;

import java.util.Collection;
import java.util.Map;

/**
 * 通用JSON响应返回体
 *
 * @param <T>
 * @author Administrator
 */
public class CommonResponse<T> {

    private Integer code;
    private String msg;
    private int size; //数据大小
    private T data;

    public CommonResponse(Integer code, String msg, T data){
        this.code = code;
        this.msg = msg;
        this.data = data;
    }

    public CommonResponse(Integer code, String msg, T data,int size) {
        this.code = code;
        this.msg = msg;
        this.data = data;
        this.size=size;
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

    public void setSize(int size){
        this.size=size;
    }

    public int getSize(){
        return this.size;
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
        int size=1;
        if(null!=data){
            if(data instanceof Collection){
                size=((Collection) data).size();
            }else if(data instanceof Map){
                size= ((Map) data).size();
            }
        }
        return create(statusCode.getCode(), statusCode.getMessage(), data,size);
    }

    public static <T> CommonResponse<T> create(AppResponseCode statusCode) {
        return create(statusCode.getCode(), statusCode.getMessage(), null,0);
    }

    public static <T> CommonResponse<T> create(Integer code, String msg, T data){
        return new CommonResponse<>(code, msg, data,0);
    }

    public static <T> CommonResponse<T> create(Integer code, String msg, T data,int size) {
        return new CommonResponse<>(code, msg, data,size);
    }

}
