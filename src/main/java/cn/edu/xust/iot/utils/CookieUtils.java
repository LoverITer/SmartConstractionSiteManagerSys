package cn.edu.xust.iot.utils;

import lombok.extern.slf4j.Slf4j;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.util.Objects;

/**
 * 对Cookie进行增删改的工具类
 *
 * @author ：huangxin
 * @modified ：
 * @since ：2020/03/11 12:01
 */
@Slf4j
public class CookieUtils {

    private CookieUtils() {
    }


    /**
     * 添加cookie
     * 注意若添加的cookie包含中文则必须设置编码，读取也必须设置编码
     *
     * @param resp
     */
    @Deprecated
    public static void addCookie(HttpServletResponse resp, String name, String value, int expire) {
        //创建cookie值
        Cookie cookie = null;
        try {
            cookie = new Cookie(name, URLEncoder.encode(value, String.valueOf(StandardCharsets.UTF_8)));
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        //设置cookie路径
        assert cookie != null;
        cookie.setPath("/");
        //不设置的话，则cookies不写入硬盘,而是写在内存,只在当前页面有用,以秒为单位
        cookie.setMaxAge(expire);
        resp.addCookie(cookie);
    }


    /**
     * 根据指定名称修改cookie<br/>
     * 注意一、修改、删除Cookie时，新建的Cookie除value、maxAge之外的所有属性，例如name、path、domain等，都要与原Cookie完全一样。
     * 否则，浏览器将视为两个不同的Cookie不予覆盖，导致修改、删除失败。
     *
     * @param request
     * @param response
     * @param cookieName     Cookie name
     * @param newCookieValue Cookie value
     * @param expire         Cookie 过期时间
     */
    public static boolean updateCookie(HttpServletRequest request, HttpServletResponse response, String cookieName, String newCookieValue, int expire) {
        Cookie[] cookies = request.getCookies();
        if (Objects.nonNull(cookies)) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals(cookieName)) {
                    deleteCookie(request, response, cookieName);
                    setCookie(request, response, cookieName, newCookieValue, expire, true);
                    return true;
                }
            }
        } else {
            setCookie(request, response, cookieName, newCookieValue, expire, true);
            return true;
        }
        return false;
    }


    /**
     * 得到Cookie的值, 不编码
     *
     * @param request
     * @param cookieName
     */
    public static String getCookieValue(HttpServletRequest request, String cookieName) {
        return getCookieValue(request, cookieName, false);
    }

    /**
     * 得到Cookie的值,可以指定isDecode为true来进行街解码
     *
     * @param request    请求对象
     * @param cookieName Cookie名
     */
    public static String getCookieValue(HttpServletRequest request, String cookieName, boolean isDecoder) {
        Cookie[] cookieList = request.getCookies();
        if (cookieList == null || cookieName == null) {
            return null;
        }
        String retValue = null;
        try {
            for (Cookie cookie : cookieList) {
                if (cookie.getName().equals(cookieName)) {
                    if (isDecoder) {
                        retValue = URLDecoder.decode(cookie.getValue(), "UTF-8");
                    } else {
                        retValue = cookie.getValue();
                    }
                    break;
                }
            }
        } catch (UnsupportedEncodingException e) {
            log.error("Cookie Decode Error.", e);
        }
        return retValue;
    }

    /**
     * 得到Cookie的值
     *
     * @param request
     * @param cookieName
     * @return
     */
    public static String getCookieValue(HttpServletRequest request, String cookieName, String encodeString) {
        Cookie[] cookieList = request.getCookies();
        if (cookieList == null || cookieName == null) {
            return null;
        }
        String retValue = null;
        try {
            for (Cookie cookie : cookieList) {
                if (cookie.getName().equals(cookieName)) {
                    retValue = URLDecoder.decode(cookie.getValue(), encodeString);
                    break;
                }
            }
        } catch (UnsupportedEncodingException e) {
            log.error("Cookie Decode Error.", e);
        }
        return retValue;
    }

    /**
     * 设置Cookie的值 不设置生效时间默认浏览器关闭即失效,也不编码
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName, String cookieValue) {
        setCookie(request, response, cookieName, cookieValue, -1);
    }

    /**
     * 设置Cookie的值 在指定时间内生效,但不编码
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName, String cookieValue, int cookieMaxAge) {
        setCookie(request, response, cookieName, cookieValue, cookieMaxAge, false);
    }

    /**
     * 设置Cookie的值 不设置生效时间,但编码
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName, String cookieValue, boolean isEncode) {
        setCookie(request, response, cookieName, cookieValue, -1, isEncode);
    }

    /**
     * 设置Cookie的值 在指定时间内生效, 编码参数
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName, String cookieValue, int cookieMaxAge, boolean isEncode) {
        doSetCookie(request, response, cookieName, cookieValue, cookieMaxAge, isEncode);
    }

    /**
     * 设置Cookie的值 在指定时间内生效, 编码参数(指定编码)
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName, String cookieValue, int cookieMaxAge, String encodeString) {
        doSetCookie(request, response, cookieName, cookieValue, cookieMaxAge, encodeString);
    }

    /**
     * 删除Cookie带cookie域名
     */
    public static boolean deleteCookie(HttpServletRequest request, HttpServletResponse response, String cookieName) {
        Cookie[] cookies = request.getCookies();
        if (Objects.nonNull(cookies)) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equalsIgnoreCase(cookieName)) {
                    //设置值为null
                    cookie.setValue(null);
                    //立即销毁cookie
                    cookie.setMaxAge(0);
                    cookie.setPath("/");
                    response.addCookie(cookie);
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * 设置Cookie的值，并使其在指定时间内生效
     *
     * @param cookieMaxAge cookie生效的最大秒数
     */
    private static final void doSetCookie(HttpServletRequest request, HttpServletResponse response, String cookieName, String cookieValue, int cookieMaxAge, boolean isEncode) {
        try {
            if (cookieValue == null) {
                cookieValue = "";
            } else if (isEncode) {
                cookieValue = URLEncoder.encode(cookieValue, StandardCharsets.UTF_8.toString());
            }
            Cookie cookie = new Cookie(cookieName, cookieValue);
            if (cookieMaxAge > 0) {
                cookie.setMaxAge(cookieMaxAge);
            }
            if (null != request) {
                // 设置域名的cookie
                cookie.setDomain(getDomainName(request));
            }
            cookie.setPath("/");
            response.addCookie(cookie);
        } catch (Exception e) {
            log.error("Cookie Encode Error.", e);
        }
    }

    /**
     * 设置Cookie的值，并使其在指定时间内生效
     *
     * @param cookieMaxAge cookie生效的最大秒数
     */
    private static final void doSetCookie(HttpServletRequest request, HttpServletResponse response, String cookieName, String cookieValue, int cookieMaxAge, String encodeString) {
        try {
            if (cookieValue == null) {
                cookieValue = "";
            } else {
                cookieValue = URLEncoder.encode(cookieValue, encodeString);
            }
            Cookie cookie = new Cookie(cookieName, cookieValue);
            if (cookieMaxAge > 0) {
                cookie.setMaxAge(cookieMaxAge);
            }
            if (null != request) {
                // 设置域名的cookie
                cookie.setDomain(getDomainName(request));
            }
            cookie.setPath("/");
            response.addCookie(cookie);
        } catch (Exception e) {
            log.error("Cookie Encode Error.", e);
        }
    }

    /**
     * 得到cookie的域名
     */
    private static final String getDomainName(HttpServletRequest request) {
        String domainName = null;

        String serverName = request.getRequestURL().toString();
        if (serverName == null || "".equals(serverName)) {
            domainName = "";
        } else {
            serverName = serverName.toLowerCase();
            serverName = serverName.substring(serverName.indexOf("//") + 2);
            final int end = serverName.indexOf("/");
            if (end != -1) {
                serverName = serverName.substring(0, end);
            }
            final String[] domains = serverName.split("\\.");
            int len = domains.length;

            if (len >= 4) {
                //127.0.0.1:8080
                domainName = domains[len - 4] + "." + domains[len - 3] + "." + domains[len - 2] + "." + domains[len - 1];
            } else if (len > 3) {
                // www.xxx.com.cn
                domainName = domains[len - 3] + "." + domains[len - 2] + "." + domains[len - 1];
            } else if (len <= 3 && len > 1) {
                // xxx.com or xxx.cn
                domainName = domains[len - 2] + "." + domains[len - 1];
            } else {
                domainName = serverName;
            }
        }

        if (domainName != null && domainName.indexOf(":") > 0) {
            String[] ary = domainName.split(":");
            domainName = ary[0];
        }
        return domainName;
    }


    public static void expire() {

    }


   /* public static void main(String[] args) {
        String domainName = null;

        String serverName = "https://www.easyblog.top/usr/login";
        serverName = serverName.toLowerCase();
        serverName = serverName.substring(serverName.indexOf("//")+2);
        final int end = serverName.indexOf("/");
        if(end!=-1) {
            serverName = serverName.substring(0, end);
        }
        final String[] domains = serverName.split("\\.");
        int len = domains.length;

        if (len >= 4) {
            //127.0.0.1:8080
            domainName = domains[len - 4] + "." + domains[len - 3] + "." + domains[len - 2] + "." + domains[len - 1];
        } else if (len > 3) {
            // www.xxx.com.cn  为解决跨域的问题，应该在域名前加一个“.”
            domainName = "."+domains[len - 3] + "." + domains[len - 2] + "." + domains[len - 1];
        } else if (len <= 3 && len > 1) {
            // xxx.com or xxx.cn
            domainName = "."+domains[len - 2] + "." + domains[len - 1];
        } else {
            domainName = serverName;
        }
        System.out.println(domainName);
    }*/
}
