package cn.edu.xust.iot.sdc.service;

import cn.edu.xust.iot.service.impl.BusinessUserServiceImpl;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;


/**
 * TDD：Test-Driven Development 测试驱动开发
 *
 * @author HuangXin
 * @since 2021/03/25 14:51
 */
@RunWith(SpringRunner.class)
@SpringBootTest
public class BusinessUserImplTest {

    private static BusinessUserServiceImpl businessUser = null;

    @After
    public void after() {
        // 退出登陆并清除SDK初始化
        if (businessUser != null) {
            businessUser.logout();
            businessUser.close();
        }
    }

    @Before
    public void before() {
        if (businessUser == null) {
            businessUser = new BusinessUserServiceImpl();
        }
        businessUser.init();
    }


    @Test
    public void testInitSDK() {
        businessUser = new BusinessUserServiceImpl();
        boolean init = businessUser.init();
        System.out.println(init);
    }

    /**
     * 测试登陆设备
     */
    @Test
    public void testDefaultLogin() {
		//long loginRes = businessUser.login();
		//System.out.println("登陆成功，ID：" + loginRes);

        long loginRes2 = businessUser.login("192.168.0.120", 6060, "admin", "HuaWei123");
        System.out.println("登陆成功，ID：" + loginRes2);
    }

}
