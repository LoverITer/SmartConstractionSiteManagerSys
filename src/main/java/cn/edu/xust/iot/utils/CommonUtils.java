package cn.edu.xust.iot.utils;


import com.alibaba.fastjson.JSONObject;
import lombok.extern.slf4j.Slf4j;

import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.text.SimpleDateFormat;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

/**
 * @Title CommonUtils.java
 * @description 通用工具类
 * @time 2020年10月27日 上午9:15:56
 * @author wuguodong
 **/
@Slf4j
public class CommonUtils {

	/**
	 * 当前项目根路径
	 */
	public static final String rootPath = getProjectRootPath();
	public static final String TRUE="true";
	public static final String NULL_STRING="";
	public static final String H_LINE="-";
	public static String getUUID(){
		return UUID.randomUUID().toString().trim().replaceAll(H_LINE, NULL_STRING);
	}

	/**
	 * @Title: IpConvert
	 * @Description:域名转ip
	 * @param domainName
	 * @return ip
	 **/
	public static String IpConvert(String domainName) {
		String ip = domainName;
		try {
			ip = InetAddress.getByName(domainName).getHostAddress();
		} catch (UnknownHostException e) {
			e.printStackTrace();
			return domainName;
		}
		return ip;
	}

	/**
	 * @Title: CheckParameters
	 * @Description:接口参数非空校验
	 * @param cameraJson
	 * @param isNullArr
	 * @return boolean
	 **/
	public static boolean isNullParameters(JSONObject cameraJson, String[] isNullArr) {
		Map<String, Object> checkMap = new HashMap<>();
		// 空值校验
		for (String key : isNullArr) {
			if (null == cameraJson.get(key) || "".equals(cameraJson.get(key))) {
				return false;
			}
		}
		return true;
	}

	/**
	 * @Title: isTrueIp
	 * @Description:接口参数ip格式校验
	 * @param ip
	 * @return boolean
	 **/
	public static boolean isCorrectIp(String ip) {
		return ip.matches("([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])(\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3}");
	}

	/**
	 * @Title: isTrueTime
	 * @Description:接口参数时间格式校验
	 * @param time
	 * @return boolean
	 **/
	public static boolean isTrueTime(String time) {
		try {
			new SimpleDateFormat("yyyy-MM-dd HH:ss:mm").parse(time);
			return true;
		} catch (Exception e) {
			log.error(e.getMessage());
			return false;
		}
	}

	/**
	 * @Title: getTime
	 * @Description:获取转换后的时间
	 * @param time
	 * @return String
	 **/
	public static String getTime(String time) {
		String timestamp = null;
		try {
			timestamp = new SimpleDateFormat("yyyyMMddHHmmss")
					.format(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").parse(time));
		} catch (Exception e) {
			log.error("时间格式化错误");
			e.printStackTrace();
		}
		return timestamp;
	}

	/**
	 * @Title: getStarttime
	 * @Description:获取回放开始时间
	 * @param time
	 * @return starttime
	 **/
	public static String getStartTime(String time) {
		String starttime = null;
		try {
			starttime = new SimpleDateFormat("yyyyMMddHHmmss")
					.format(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").parse(time).getTime() - 60 * 1000);
		} catch (Exception e) {
			log.error("时间格式化错误");
			e.printStackTrace();
		}
		return starttime;
	}

	/**
	 * @Title: getEndtime
	 * @Description:获取回放结束时间
	 * @param time
	 * @return endString
	 **/
	public static String getEndTime(String time) {
		String endString = null;
		try {
			endString = new SimpleDateFormat("yyyyMMddHHmmss")
					.format(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").parse(time).getTime() + 60 * 1000);
		} catch (Exception e) {
			log.error("时间格式化错误");
			e.printStackTrace();
		}
		return endString;
	}


	/**
	 * 获取两个日期的时间差
	 * @param startTime
	 * @param endTime
	 * @return 字符串
	 */
	public static String dateDiff(long startTime, long endTime) {
		long nd = 1000 * 24 * 60 * 60;// 一天的毫秒数
		long nh = 1000 * 60 * 60;// 一小时的毫秒数
		long nm = 1000 * 60;// 一分钟的毫秒数
		long ns = 1000;// 一秒钟的毫秒数
		long diff;
		long day = 0;
		long hour = 0;
		long min = 0;
		long sec = 0;
		// 获得两个时间的毫秒时间差异
		diff = Math.abs(endTime - startTime);
		day = diff / nd;// 计算差多少天
		hour = diff % nd / nh ;// 计算差多少小时
		min = diff % nd % nh / nm ;// 计算差多少分钟
		sec = diff % nd % nh % nm / ns;// 计算差多少秒
        return String.format("%d days %d h %d m %d s",day,hour,min,sec);
	}

	/**
	 * 获取格式化后的UUID随机字符串
	 * @return
	 */
	public static String getRandomStr(){
		return UUID.randomUUID().toString().replaceAll("-","");
	}


	/**
	 * 是否为空
	 *
	 * @param str
	 * @return boolean true:为空，false：不为空
	 */
	public static boolean isNull(String str) {
		return str == null || NULL_STRING.equals(str.trim());
	}
	/**
	 * 字符串是否是"true"
	 * @param str
	 * @return
	 */
	public static boolean isTrue(String str){
		return TRUE.equals(str)?true:false;
	}

	/**
	 * 获取项目根目录（静态）
	 * @return
	 */
	public static String getRootPath() {
		return rootPath;
	}
	/**
	 * 获取项目根目录（动态）
	 * @return
	 */
	public static String getProjectRootPath() {
		String path=null;
		try{
			path = CommonUtils.class.getResource("/").getPath();
		}catch(Exception e){
			File directory = new File(NULL_STRING);
			path= directory.getAbsolutePath()+File.separator;
		}
		return path;
	}
	/**
	 * 获取类路径
	 * @param cla
	 * @return
	 */
	public static String getClassPath(Class<?> cla){
		return cla.getResource("").getPath();
	}


	public static void main(String[] args) {
		String projectRootPath = CommonUtils.getProjectRootPath();
		StringBuffer sb = new StringBuffer();
		System.out.println(sb.append(projectRootPath).append("ffmpeg/bin").toString());
	}

}
