package cn.edu.xust.iot.service.impl;


import cn.edu.xust.iot.conf.ApplicationContextHolder;
import cn.edu.xust.iot.conf.redis.StringObjectRedisTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.connection.lettuce.LettuceConnectionFactory;
import org.springframework.data.redis.core.*;
import org.springframework.stereotype.Component;
import org.springframework.util.CollectionUtils;

import java.util.*;
import java.util.concurrent.TimeUnit;


/**
 * Redis工具类，封装了对象和Redis基本数据类型的大部分存,取,删除,设置过期时间等操作. 所有操作可以指定数据库索引.
 * 存,取可以设置过期时间. 没有设置默认过期时间,存值时尽量设置过期时间
 *
 * @author ：huangxin
 * @modified ：
 * @since ：2020/02/27 11:56
 */
@Component(value = "redisService")
public class RedisService {

    @Autowired
    private StringObjectRedisTemplate redisTemplate;
    @Autowired
    private ValueOperations<String, Object> redisValueOps;
    @Autowired
    private HashOperations<String, String, Object> redisHashOps;
    @Autowired
    private ListOperations<String, Object> redisListOps;
    @Autowired
    private SetOperations<String, Object> redisSetOps;
    @Autowired
    private ZSetOperations<String, Object> redisZSetOps;


    public enum RedisDataBaseSelector {
        /***Redis默认的16个数据库索引**/
        DB_0(0), DB_1(1), DB_2(2), DB_3(3), DB_4(4), DB_5(5), DB_6(6), DB_7(7),
        DB_8(8), DB_9(9), DB_10(10), DB_11(11), DB_12(12), DB_13(13), DB_14(14), DB_15(15);

        private final int dbIndex;

        RedisDataBaseSelector(int dbIndex) {
            this.dbIndex = dbIndex;
        }

        public int getDbIndex() {
            return dbIndex;
        }

    }


    /**
     * Redis数据库最大索引
     */
    private static final int MAX_DB_INDEX = 15;
    /**
     * Redis数据库最小索引
     */
    private static final int MIN_DB_INDEX = 0;

    /**
     * redis读写工具类
     */
    private static RedisService redisUtils = null;

    public static RedisService getRedisUtils() {
        if (Objects.isNull(redisUtils)) {
            synchronized (RedisService.class) {
                redisUtils = ApplicationContextHolder.getBean("redisUtils");
            }
        }
        return redisUtils;
    }


    //=============================common============================

    /**
     * 向外暴露RedisTemplate
     *
     * @param dbIndex
     * @return
     */
    public RedisTemplate getRedisTemplate(RedisDataBaseSelector dbIndex) {
        setDbIndex(dbIndex);
        return redisTemplate;
    }

    /**
     * 设置数据库索引
     *
     * @param dbIndex
     */
    private void setDbIndex(RedisDataBaseSelector dbIndex) {
        if (dbIndex == null || dbIndex.getDbIndex() > MAX_DB_INDEX || dbIndex.getDbIndex() < MIN_DB_INDEX) {
            dbIndex = RedisDataBaseSelector.DB_0;
        }
        LettuceConnectionFactory connectionFactory = (LettuceConnectionFactory) redisTemplate.getConnectionFactory();
        if (connectionFactory == null) {
            throw new NullPointerException("Get Redis Connection failure!");
        }
        connectionFactory.setDatabase(dbIndex.getDbIndex());
        redisTemplate.setConnectionFactory(connectionFactory);
    }

    /**
     * 指定缓存失效时间，单位s
     *
     * @param key     键
     * @param time    时间(秒)
     * @param dbIndex 读写操作的库
     * @return
     */
    public Boolean expire(String key, long time, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            if (time > 0) {
                return redisTemplate.expire(key, time, TimeUnit.SECONDS);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    /**
     * 根据key 获取过期时间
     *
     * @param key 键 不能为null
     * @return 时间(秒) 返回0代表为永久有效
     */
    public Long getExpire(String key, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisTemplate.getExpire(key, TimeUnit.SECONDS);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0L;
    }

    /**
     * 判断key是否存在
     *
     * @param key 键
     * @return true 存在 false不存在
     */
    public Boolean exists(String key, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisTemplate.hasKey(key);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    /**
     * 删除缓存
     *
     * @param key 可以传一个值 或多个
     */
    @SuppressWarnings("unchecked")
    public Boolean delete(RedisDataBaseSelector dbIndex, String... key) {
        if (key != null && key.length > 0) {
            this.setDbIndex(dbIndex);
            if (key.length == 1) {
                return redisTemplate.delete(key[0]);
            } else {
                Long deleted = redisTemplate.delete((Collection<String>) CollectionUtils.arrayToList(key));
                if (Objects.nonNull(deleted) && deleted > 0) {
                    return true;
                }
            }
        }
        return false;
    }

    //============================String=============================

    /**
     * 普通缓存获取
     *
     * @param key 键
     * @return 值
     */
    public Object get(String key, RedisDataBaseSelector dbIndex) {
        this.setDbIndex(dbIndex);
        return key == null ? null : redisValueOps.get(key);
    }

    /**
     * 普通缓存放入
     *
     * @param key   键
     * @param value 值
     * @return true成功 false失败
     */
    public boolean set(String key, Object value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisValueOps.set(key, value);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

    }

    /**
     * 普通缓存放入并设置时间
     *
     * @param key   键
     * @param value 值
     * @param time  时间(秒) time要大于0 如果time小于等于0 将设置无限期
     * @return true成功 false 失败
     */
    public boolean set(String key, Object value, long time, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            if (time > 0) {
                redisValueOps.set(key, value, time, TimeUnit.SECONDS);
            } else {
                redisValueOps.set(key, value);
            }
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 如果数据库中没有这个值的时候添加，如果有的话就不添加
     *
     * @param key
     * @param value
     * @param dbIndex
     * @return
     */
    public Boolean setnx(String key, String value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisValueOps.setIfAbsent(key, value);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 如果数据库中有这个值的时候添加，如果没有的话就不添加
     *
     * @param key
     * @param value
     * @param dbIndex
     * @return
     */
    public Boolean setpx(String key, String value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisValueOps.setIfPresent(key, value);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public Object getAndSet(String key, String value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisValueOps.getAndSet(key, value);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * 递增
     *
     * @param key   键
     * @param delta 要增加几(大于0)
     * @return
     */
    public Long incr(String key, long delta, RedisDataBaseSelector dbIndex) {
        if (delta < 0) {
            throw new RuntimeException("递增因子必须大于0");
        }
        this.setDbIndex(dbIndex);
        return redisValueOps.increment(key, delta);
    }

    /**
     * 递减
     *
     * @param key   键
     * @param delta 要减少几(小于0)
     * @return
     */
    public Long decr(String key, long delta, RedisDataBaseSelector dbIndex) {
        if (delta < 0) {
            throw new RuntimeException("递减因子必须大于0");
        }
        this.setDbIndex(dbIndex);
        return redisValueOps.increment(key, -delta);
    }

    //================================Map=================================

    /**
     * HashGet
     *
     * @param key  键 不能为null
     * @param item 项 不能为null
     * @return 值
     */
    public Object hget(String key, String item, RedisDataBaseSelector dbIndex) {
        this.setDbIndex(dbIndex);
        return redisHashOps.get(key, item);
    }

    /**
     * 获取hashKey对应的所有键值
     *
     * @param key 键
     * @return 对应的多个键值
     */
    public Map<String, Object> hmget(String key, RedisDataBaseSelector dbIndex) {
        this.setDbIndex(dbIndex);
        return redisHashOps.entries(key);
    }

    /**
     * HashSet
     *
     * @param key 键
     * @param map 对应多个键值
     * @return true 成功 false 失败
     */
    public boolean hmset(String key, Map<String, Object> map, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisHashOps.putAll(key, map);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * HashSet 并设置时间
     *
     * @param key  键
     * @param map  对应多个键值
     * @param time 时间(秒)
     * @return true成功 false失败
     */
    public boolean hmset(String key, Map<String, Object> map, long time, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisHashOps.putAll(key, map);
            if (time > 0) {
                expire(key, time, dbIndex);
            }
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 向一张hash表中放入数据,如果不存在将创建
     *
     * @param key   键
     * @param item  项
     * @param value 值
     * @return true 成功 false失败
     */
    public boolean hset(String key, String item, Object value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisHashOps.put(key, item, value);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 向一张hash表中放入数据,如果不存在将创建
     *
     * @param h   键
     * @param hk  项
     * @param hv 值
     * @param time  时间(秒)  注意:如果已存在的hash表有时间,这里将会替换原有的时间
     * @return true 成功 false失败
     */
    public boolean hset(String h, String hk, Object hv, long time, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisHashOps.put(h, hk, hv);
            if (time > 0) {
                expire(h, time, dbIndex);
            }
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 删除hash表中的值
     *
     * @param hk  Redis中可以每一确定map的key
     * @param key map中元素的key
     */
    public Long hdel(RedisDataBaseSelector dbIndex, String hk, Object... key) {
        this.setDbIndex(dbIndex);
        return redisHashOps.delete(hk, key);
    }

    /**
     * 判断hash表中是否有该项的值
     *
     * @param hk  Redis中可以每一确定map的key
     * @param key map中元素的key
     * @return true 存在 false不存在
     */
    public boolean hHasKey(String hk, String key, RedisDataBaseSelector dbIndex) {
        this.setDbIndex(dbIndex);
        return redisHashOps.hasKey(hk, key);
    }

    /**
     * hash递增 如果不存在,就会创建一个 并把新增后的值返回
     *
     * @param hk  Redis中可以每一确定map的key
     * @param key map中元素的key
     * @param delta 要增加几(大于0)
     * @return
     */
    public double hincr(String hk, String key, double delta, RedisDataBaseSelector dbIndex) {
        this.setDbIndex(dbIndex);
        return redisHashOps.increment(hk, key, delta);
    }

    /**
     * hash递减
     *
     * @param key  键
     * @param item 项
     * @param by   要减少记(小于0)
     * @return
     */
    public double hdecr(String key, String item, double by, RedisDataBaseSelector dbIndex) {
        this.setDbIndex(dbIndex);
        return redisHashOps.increment(key, item, -by);
    }

    //===============================list=================================

    /**
     * 获取list缓存的内容
     *
     * @param key   键
     * @param start 开始
     * @param end   结束  0 到 -1代表所有值
     * @return
     */
    public List<Object> lGet(String key, long start, long end, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisListOps.range(key, start, end);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * 获取list缓存的长度
     *
     * @param key 键
     * @return
     */
    public Long lGetListSize(String key, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisListOps.size(key);
        } catch (Exception e) {
            e.printStackTrace();
            return 0L;
        }
    }

    /**
     * 通过索引 获取list中的值
     *
     * @param key   键
     * @param index 索引  index>=0时， 0 表头，1 第二个元素，依次类推；index<0时，-1，表尾，-2倒数第二个元素，依次类推
     * @return
     */
    public Object lGetIndex(String key, long index, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisListOps.index(key, index);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * 将list放入缓存
     *
     * @param key   键
     * @param value 值
     * @return
     */
    public boolean lSet(String key, Object value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisListOps.rightPush(key, value);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 将list放入缓存
     *
     * @param key   键
     * @param value 值
     * @param time  时间(秒)
     * @return
     */
    public boolean lSet(String key, Object value, long time, RedisDataBaseSelector dbIndex) {
        try {
            redisListOps.rightPush(key, value);
            if (time > 0) {
                expire(key, time, dbIndex);
            }
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 将list放入缓存
     *
     * @param key   键
     * @param value 值
     * @return
     */
    public boolean lSet(String key, List<Object> value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisListOps.rightPushAll(key, value);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 将list放入缓存
     *
     * @param key   键
     * @param value 值
     * @param time  时间(秒)
     * @return
     */
    public boolean lSet(String key, List<Object> value, long time, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisListOps.rightPushAll(key, value);
            if (time > 0) {
                expire(key, time, dbIndex);
            }
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 根据索引修改list中的某条数据
     *
     * @param key   键
     * @param index 索引
     * @param value 值
     * @return
     */
    public boolean lUpdateIndex(String key, long index, Object value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            redisListOps.set(key, index, value);
            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 移除N个值为value
     *
     * @param key   键
     * @param count 移除多少个
     * @param value 值
     * @return 移除的个数
     */
    public Long lRemove(String key, long count, Object value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisListOps.remove(key, count, value);
        } catch (Exception e) {
            e.printStackTrace();
            return 0L;
        }
    }


    //============================set=============================

    /**
     * 根据key获取Set中的所有值
     *
     * @param key 键
     * @return
     */
    public Set<Object> sGet(String key, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisSetOps.members(key);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * 根据value从一个set中查询,是否存在
     *
     * @param key   键
     * @param value 值
     * @return true 存在 false不存在
     */
    public Boolean sHasKey(String key, Object value, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisSetOps.isMember(key, value);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 将数据放入set缓存
     *
     * @param key    键
     * @param values 值 可以是多个
     * @return 成功个数
     */
    public Long sSet(String key, RedisDataBaseSelector dbIndex, Object... values) {
        try {
            this.setDbIndex(dbIndex);
            return redisSetOps.add(key, values);
        } catch (Exception e) {
            e.printStackTrace();
            return 0L;
        }
    }

    /**
     * 将set数据放入缓存
     *
     * @param key    键
     * @param time   时间(秒)
     * @param member 值 可以是多个
     * @return 成功个数
     */
    public Long sadd(String key, long time, RedisDataBaseSelector dbIndex, Object... member) {
        try {
            this.setDbIndex(dbIndex);
            Long count = redisSetOps.add(key, member);
            if (time > 0) {
                expire(key, time, dbIndex);
            }
            return count;
        } catch (Exception e) {
            e.printStackTrace();
            return 0L;
        }
    }

    /**
     * 获取set中成员的总数
     *
     * @param key 键
     * @return
     */
    public Long scard(String key, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisSetOps.size(key);
        } catch (Exception e) {
            e.printStackTrace();
            return 0L;
        }
    }

    /**
     * 移除set中一个或多个
     *
     * @param key     键
     * @param members 需要移除的一个或多个成员
     * @return 移除的个数
     */
    public Long srem(RedisDataBaseSelector dbIndex, String key, Object... members) {
        try {
            this.setDbIndex(dbIndex);
            return redisSetOps.remove(key, members);
        } catch (Exception e) {
            e.printStackTrace();
            return 0L;
        }
    }


    //====================================ZSet=============================================

    /**
     * 向zset中添加一个成员
     *
     * @param key
     * @param member
     * @param score
     * @param dbIndex
     * @return
     */
    public Boolean zadd(String key, Object member, double score, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisZSetOps.add(key, member, score);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * 向zset中批量添加成员
     *
     * @param key
     * @param set
     * @param dbIndex
     * @return
     */
    public Long zadd(String key, Set<ZSetOperations.TypedTuple<Object>> set, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisZSetOps.add(key, set);
        } catch (Exception e) {
            e.printStackTrace();
            return 0L;
        }
    }

    /**
     * 给zset中一个成员的分数增加或减去score
     *
     * @param key
     * @param member
     * @param score
     * @param dbIndex
     * @return
     */
    public Double zincrby(String key, Object member, double score, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisZSetOps.incrementScore(key, member, score);
        } catch (Exception e) {
            e.printStackTrace();
            return 0.0;
        }
    }

    /**
     * 获取一个zset中一个成员的分数
     *
     * @param key
     * @param member
     * @param dbIndex
     * @return
     */
    public Double zscore(String key, Object member, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisZSetOps.score(key, member);
        } catch (Exception e) {
            e.printStackTrace();
            return 0.0;
        }
    }

    /**
     * 获取得分数介于min 以及 max 其间的成员从高到低排序的排序集。
     *
     * @param key     键
     * @param min     分数下界（包括）
     * @param max     分数上界 （包括）
     * @param dbIndex 数据库号
     * @return
     */
    public Set<Object> zRevRangeByScore(String key, double min, double max, RedisDataBaseSelector dbIndex) {
        try {
            this.setDbIndex(dbIndex);
            return redisZSetOps.reverseRangeByScore(key, min, max);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }



    public Set<Object> rangeByScore(String key, double min, double max, RedisDataBaseSelector dbIndex){
        try {
            this.setDbIndex(dbIndex);
            return redisZSetOps.rangeByScore(key, min, max);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }


}