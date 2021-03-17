package cn.edu.xust.error;

/**
 * @author HuangXin
 * @Date 2020/3/9 3:29 下午
 */

public enum AppResponseCode {
	// 正确
	SUCCESS(true, 200, "正确"),
	// 错误
	FAIL(false, 500, "错误"),
	// 请求参数有误
	REQUEST_PARAMETER_VALID(false, 405, "请求参数有误"),

	// 订单已取消
	ORDER_CANCEL(false, 80001, "订单已取消"),
	// 订单无效,系统行为
	ORDER_INVALID(false, 80002, "订单无效"),
	// 订单已退货
	ORDER_RETURNED(true, 80003, "订单已退货"),
	// 订单未付款
	ORDER_PAY_STATUS_NO_PAY(false, 80004, "订单未付款"),
	// 订单已付款
	ORDER_PAY_STATUS_HAS_PAY(true, 80005, "订单已付款"),

	// 消息正在处理
	MQ_MESSAGE_STATUS_PROCESSING(true, 100001, "消息正在处理"),
	// 消息处理成功
	MQ_MESSAGE_STATUS_SUCCESS(true, 100002, "消息处理成功"),
	// 消息处理失败
	MQ_MESSAGE_STATUS_FAIL(false, 100003, "消息处理失败"),

	// 优惠券已经使用
	COUPON_ISUSED(true, 110001, "优惠券已经使用"),
	// 优惠券未使用
	COUPON_UNUSED(false, 110002, "优惠券未使用"),

	// 快递运费不正确
	ORDER_STATUS_UPDATE_FAIL(false, 10001, "订单状态修改失败"),
	// 快递运费不正确
	ORDER_SHIPPINGFEE_INVALID(false, 10002, "订单运费不正确"),
	// 订单总价格不合法
	ORDERAMOUNT_INVALID(false, 10003, "订单总价格不正确"),
	// 订单保存失败
	ORDER_SAVE_ERROR(false, 10004, "订单保存失败"),
	// 订单确认失败
	ORDER_CONFIRM_FAIL(false, 10005, "订单确认失败"),

	// 商品不存在
	GOODS_NO_EXIST(false, 20001, "商品不存在"),
	// 订单价格非法
	GOODS_PRICE_INVALID(false, 20002, "商品价格非法"),
	// 商品库存不足
	GOODS_STOCK_NOT_ENOUGH(false, 20003, "商品库存不足"),

	// 扣减库存失败
	REDUCE_GOODS_NUM_FAIL(false, 20004, "扣减库存失败"),
	// 库存记录为空
	REDUCE_GOODS_NUM_EMPTY(false, 20005, "扣减库存失败"),

	// 用户账号不能为空
	USER_IS_NULL(false, 30001, "用户账号不能为空"),
	// 用户信息不存在
	USER_NO_EXIST(false, 30002, "用户不存在"),
	// 余额扣减失败
	USER_MONEY_REDUCE_FAIL(false, 30003, "余额扣减失败"),
	// 已经退款
	USER_MONEY_REFUND_ALREADY(true, 30004, "订单已经退过款"),
	// 用户没有登录
	USER_NOT_LOGIN(false, 30005, "用户未登录"),
	// 用户登录成功
	USER_LOGIN_SUCCESS(true, 30006, "用户登录成功"),
	// 用户登录失败
	USER_LOGIN_FAILE(false, 30007, "用户登录失败"),
	// 用户重复登录
	USER_LOGIN_REPEAT(false, 30008, "用户重复登录"),
	// 用户退出成功
	USER_LOGOUT_SUCCESS(true, 30008, "用户退出成功"),
	// 用户退出失败
	USER_LOGOUT_FAILE(false, 30009, "用户退出失败"),

	// 优惠券不不存在
	COUPON_NO_EXIST(false, 40001, "优惠券不存在"),
	// 优惠券不合法
	COUPON_INVALIED(false, 40002, "优惠券不合法"),
	// 优惠券使用失败
	COUPON_USE_FAIL(false, 40003, "优惠券使用失败"),

	// 余额不能小于0
	MONEY_PAID_LESS_ZERO(false, 50001, "余额不能小于0"),
	// 余额非法
	MONEY_PAID_INVALID(false, 50002, "余额非法"),

	// Topic不能为空
	MQ_TOPIC_IS_EMPTY(false, 60001, "Topic不能为空"),
	// 消息体不能为空
	MQ_MESSAGE_BODY_IS_EMPTY(false, 60002, "消息体不能为空"),
	// 消息发送失败
	MQ_SEND_MESSAGE_FAIL(false, 60003, "消息发送失败"),

	// 支付订单未找到
	PAYMENT_NOT_FOUND(false, 70001, "支付订单未找到"),
	// 支付订单已支付
	PAYMENT_IS_PAID(false, 70002, "支付订单已支付"),
	// 订单付款失败
	PAYMENT_PAY_ERROR(false, 70002, "订单支付失败");

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
