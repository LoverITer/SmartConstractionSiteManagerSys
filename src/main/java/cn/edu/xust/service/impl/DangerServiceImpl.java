package cn.edu.xust.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import cn.edu.xust.entity.po.Danger;
import cn.edu.xust.mapper.DangerMapper;
import cn.edu.xust.service.IDangerService;

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
