package cn.edu.xust.mapper;

import java.util.List;

import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import cn.edu.xust.entity.po.Danger;
import cn.edu.xust.mapper.DangerMapper;

/**
 * Mapper查询数据库测试
 *
 * @author HuangXin
 * @since 2021/03/17 09:49
 */
@RunWith(SpringRunner.class)
@SpringBootTest
public class MapperTest {

	@Autowired
	DangerMapper dangerMapper;

	@Test
	public void getAllDangerInfoList() {
		List<Danger> res = dangerMapper.selectAll();

		res.forEach(ele -> {
			System.out.println(ele);
		});
	}

}
