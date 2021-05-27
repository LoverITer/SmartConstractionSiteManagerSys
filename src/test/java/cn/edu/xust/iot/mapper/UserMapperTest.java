package cn.edu.xust.iot.mapper;

import cn.edu.xust.iot.utils.IDCardNo;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.text.ParseException;

/**
 * @author HuangXin
 * @since 2021/5/27 10:57
 */
@RunWith(SpringRunner.class)
@SpringBootTest
public class UserMapperTest {

    @Autowired
    private SUserMapper userMapper;


    //批量添加工人
    @Test
    public void addWorkerBatch() throws ParseException {
        for(int i=1000;i<9999;i++){

            String IDCardNum = "50011319860624"+i;
            if(IDCardNo.IDCardValidate(IDCardNum).length()==0){

            }

        }
    }

}
