package cn.edu.xust.error;

/**
 * @author Huangxin
 * @Date 2020/3/9 3:27 下午
 */
public interface CommonError {
    int getErrCode();

    String getErrMsg();

    CommonError setErrMsg(String errMsg);
}
