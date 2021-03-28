package cn.edu.xust.iot.sdc.core;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

/**
 * @author HuangXin
 * @since 2021/3/28 21:04
 */
@RunWith(SpringRunner.class)
@SpringBootTest
public class CoreTest {

    @Test
    public void testGetSDKInstance(){
        HWPuSDK instance = HWPuSDK.INSTANCE;
        //只要可以正常打印出hashCode就说明SDK已经正常被JNA加载并初始化了
        System.out.println(instance.hashCode());
    }


}
