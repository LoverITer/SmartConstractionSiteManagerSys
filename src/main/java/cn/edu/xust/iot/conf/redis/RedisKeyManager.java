package cn.edu.xust.iot.conf.redis;

/**
 * @author Huang Xin
 * @Description 专门用于管理系统使用到的Redis key的一个类
 * @data 2020/12/23 00:05
 */
public class RedisKeyManager {

    /**
     * 用户登录生成的token的key,格式是：当前毫秒时间戳+UUID
     */
    public static final String USER_LOGIN_TOKEN="%d%s";


}
