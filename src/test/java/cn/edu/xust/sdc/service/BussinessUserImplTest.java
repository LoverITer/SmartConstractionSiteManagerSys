package cn.edu.xust.sdc.service;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import cn.edu.xust.sdc.service.impl.BussinessUserImpl;

/**
 * TDD：Test-Driven Development 测试驱动开发
 *
 * @author HuangXin
 * @since 2021/03/25 14:51
 */
@RunWith(SpringRunner.class)
@SpringBootTest
public class BussinessUserImplTest {

	private static BussinessUserImpl bussinessUser = null;

	@AfterAll
	public static void after() {
		// 退出登陆并清除SDK初始化
		if (bussinessUser != null) {
			bussinessUser.logout();
			bussinessUser.close();
		}
	}

	@BeforeAll
	public static void brfore() {
		if (bussinessUser == null) {
			bussinessUser = new BussinessUserImpl();
		}
		bussinessUser.init();
	}

	/**
	 * 测试登陆设备
	 */
	@Test
	public void testDefaultLogin() {
		/*
		 * long loginRes = bussinessUser.login(); System.out.println("登陆成功，ID：" +
		 * loginRes);
		 */

		long loginRes2 = bussinessUser.login("192.168.0.120", 6060, "admin", "HuaWei123");
		System.out.println("登陆成功，ID：" + loginRes2);
	}

}
