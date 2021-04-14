package cn.edu.xust.iot.service.impl;

import cn.edu.xust.iot.mapper.DangerMapper;
import cn.edu.xust.iot.model.entity.Danger;
import cn.edu.xust.iot.service.IDangerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


/**
 * @author HuangXin
 * @since 2021/03/16 19:59
 */
@Service
public class DangerServiceImpl implements IDangerService {

	@Autowired
	private DangerMapper dangerMapper;

	@Override
	public Danger getDangerInfo(int id) {
		return dangerMapper.selectByPrimaryKey(id);
	}

}
