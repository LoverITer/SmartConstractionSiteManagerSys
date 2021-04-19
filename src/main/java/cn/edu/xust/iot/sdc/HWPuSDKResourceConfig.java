package cn.edu.xust.iot.sdc;

import com.sun.jna.Platform;

import java.io.File;
import java.io.IOException;

/**
 * 华为SDC有关配置文件的路径
 *
 * @author HuangXin
 * @since 2021/3/28 20:28
 */
public class HWPuSDKResourceConfig {

    /**
     * 在项目中已经将libs目录设置为本地类库了
     */
    public static final String LIBRARY_ROOT_PATH = "libs";

    public static final String LINUX_SDK_ROOT_PATH = "libs\\linux";

    public static final String WINDOWS_SDK_ROOT_PATH = "libs\\windows";

    public static String CA_ROOT_PATH = null;

    static {
        try {
            CA_ROOT_PATH = new File(".").getCanonicalPath() + "\\src\\main\\resources\\libs\\cert";
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public enum CertificateType {
        CERT_CA_CERT(0), CERT_CERT(1), CERT_KEY(2);

        private final int typeId;

        CertificateType(final int typeId) {
            this.typeId = typeId;
        }

        public int getTypeId() {
            return typeId;
        }
    }

    /**
     * 获得SDK的根路径，可以让程序判断在不同操作系统下加载不同的动态库
     *
     * @return
     */
    public static String getSdkRootPath() {
        if (Platform.isWindows()) {
            return WINDOWS_SDK_ROOT_PATH + "\\HWPuSDK";
        } else if (Platform.isLinux()) {
            return LINUX_SDK_ROOT_PATH + "\\libhwpusdk";
        } else {
            throw new RuntimeException("Unsupported platforms, currently only supports Windows and Linux platforms");
        }
    }

    /**
     * 获取CA认证证书的公钥、秘钥
     *
     * @param type
     * @return
     */
    public static String getCAPath(CertificateType type) throws IOException {
        if (type == null) {
            throw new NullPointerException("type can not be null or empty");
        }
        switch (type) {
            case CERT_CA_CERT:
                return CA_ROOT_PATH + "\\cacert.pem";
            case CERT_CERT:
                return CA_ROOT_PATH + "\\cert.pem";
            case CERT_KEY:
                return CA_ROOT_PATH + "\\key.pem";
            default:
                throw new RuntimeException("error certificate type");
        }
    }


}
