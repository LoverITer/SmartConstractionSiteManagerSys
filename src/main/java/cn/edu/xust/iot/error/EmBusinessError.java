package cn.edu.xust.iot.error;

/**
 * @author HuangXin
 * @Date 2020/3/9 3:29 下午
 */
public enum EmBusinessError implements CommonError {
    // 通用错误类型
    PARAMETER_VALIDATION_ERROR(10001, "参数不合法"),
    UNKNOWN_ERROR(10002, "未知错误"),

    // 2开头为用户信息相关错误定义
    USER_NOT_EXIST(20001, "用户不存在"),
    USER_LOGIN_FAIL(20002, "登陆失败"),
    USER_NOT_LOGIN(20003, "用户还未登陆"),
    HAS_REGISTERED(20004, "该手机号已注册"),

    // 3开头为交易信息错误定义
    STOCK_NOT_ENOUGH(30001, "库存不足!"),
    MQ_SEND_ERROR(30002, "库存异步消息发送失败"),

    //4 开头的是商品信息错误
    ITEM_NOT_FOND(40001,"不存在的商品记录"),
    ITEM_USER_KILLED(40002,"您已经抢购过该商品了"),


    //5开头的都是订单的一些信息
    ORDER_INVAILD(50001, "订单无效")
    ;

    private int errCode;
    private String errMsg;

    EmBusinessError(int errCode, String errMsg) {
        this.errCode = errCode;
        this.errMsg = errMsg;
    }

    @Override
    public int getErrCode() {
        return this.errCode;
    }

    @Override
    public String getErrMsg() {
        return this.errMsg;
    }

    @Override
    public CommonError setErrMsg(String errMsg) {
        this.errMsg = errMsg;
        return this;
    }
}
