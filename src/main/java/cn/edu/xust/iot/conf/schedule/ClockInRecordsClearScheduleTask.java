package cn.edu.xust.iot.conf.schedule;

import cn.edu.xust.iot.service.IClockInService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.context.annotation.Configuration;
import org.springframework.scheduling.annotation.Scheduled;

/**
 * 清空打卡记录定时任务，定时记录保存在IClockInService接口中，每天在5:10清空Map中的所有记录，为新的一天打卡记录做准备
 *
 * @author HuangXin
 * @since 2021/4/30 16:54
 */
@Configuration
@Slf4j
public class ClockInRecordsClearScheduleTask {

    /**
     * 每天早上的5:10执行清理任务
     */
    @Scheduled(cron = "0 10 5 ? * *")
    public void configureClearTask() {
        log.info("Start to clear clock in records.");
        IClockInService.CLOCK_RECORDS.clear();
        log.info("Clear clock in records Successful!");
    }

}
