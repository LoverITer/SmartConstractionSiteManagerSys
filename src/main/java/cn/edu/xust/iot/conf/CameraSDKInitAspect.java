package cn.edu.xust.iot.conf;

import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.service.IHWPuSDKService;
import lombok.extern.slf4j.Slf4j;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.*;
import org.aspectj.lang.reflect.MethodSignature;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.lang.reflect.Method;

/**
 * @author HuangXin
 * @since 2021/4/19 11:13
 */
@Slf4j
@Aspect
@Component
public class CameraSDKInitAspect {

    @Autowired
    private IHWPuSDKService hwPuSDKService;

    //指定拦截InitSDK注解
    @Pointcut("@annotation(cn.edu.xust.iot.sdc.core.annotation.InitSDK)")
    public void pointCut() {
    }


    /**
     * 在有注解@InitSDK的方法执行之前执行初始化SDK的工作
     *
     * @param joinPoint
     */
    @Before(value = "pointCut()")
    public void doBefore(JoinPoint joinPoint) {
        CameraModel cameraModel = getArg(joinPoint, "cn.edu.xust.iot.model.CameraModel");
        if(cameraModel==null){
            log.error("CameraSDKInitAspect 方法没有所需参数，无法执行SDK初始化");
            return;
        }
        boolean initRes = hwPuSDKService.init();
        if (initRes) {
            long loginRes = hwPuSDKService.login(cameraModel.getIp(), cameraModel.getPort(),
                    cameraModel.getUserName(), cameraModel.getPassword());
            if(loginRes>0){
                log.error("CameraSDKInitAspect 初始化SDK服务成功");
                return;
            }
        }
        log.error("CameraSDKInitAspect 初始化SDK服务失败");
    }


    /**
     * 在有注解@InitSDK方法执行结束之后执行清理工作
     *
     * @param joinPoint
     */
    @After(value = "pointCut()")
    public void doAfter(JoinPoint joinPoint) {
        CameraModel cameraModel = getArg(joinPoint, "cn.edu.xust.iot.model.CameraModel");
        if(cameraModel==null){
            log.error("CameraSDKInitAspect 方法没有所需参数，无法执行SDK初始化");
            return;
        }
        closeSdk(cameraModel.getIp());
    }

    /**
     * 发生异常之后也需要清理SDK
     */
    @AfterThrowing(value = "pointCut()", throwing = "e")
    public void doException(JoinPoint joinPoint, Exception e) {
        log.error("方法发生异常,{}",e.getMessage());
        CameraModel cameraModel = getArg(joinPoint, "cn.edu.xust.iot.model.CameraModel");
        if(cameraModel==null){
            log.error("CameraSDKInitAspect 方法没有所需参数，无法执行SDK初始化");
            return;
        }
        closeSdk(cameraModel.getIp());
    }


    public CameraModel getArg(JoinPoint joinPoint,String clazz){
        MethodSignature signature = (MethodSignature) joinPoint.getSignature();
        Method method = signature.getMethod();
        String classType = joinPoint.getTarget().getClass().getName();
        String methodName = method.getName();
        log.debug("CameraSDKInitAspect {}.{} 被拦截",classType,methodName);
        // 参数值
        Object[] args = joinPoint.getArgs();
        if(args==null||args.length==0){
            return null;
        }
        //参数类型   这里需要 cn.edu.xust.iot.model.CameraModel
        Class<?>[] parameterTypes = method.getParameterTypes();
        int index = 0;
        for (int i = 0; i < parameterTypes.length; i++) {
            //找到参数的位置
            if (clazz.equals(parameterTypes[i].toString().split(" ")[1])) {
                index = i;
                break;
            }
        }
        return (CameraModel) args[index];
    }

    private void closeSdk(String ip) {
        try {
            hwPuSDKService.logout(ip);
            hwPuSDKService.close();
            log.error("CameraSDKInitAspect 关闭SDK资源成功");
        } catch (Exception e) {
            log.error("CameraSDKInitAspect 关闭SDK资源发生错误");
            e.printStackTrace();
        }
    }

}
