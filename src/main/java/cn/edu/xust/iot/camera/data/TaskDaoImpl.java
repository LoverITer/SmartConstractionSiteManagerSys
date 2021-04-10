package cn.edu.xust.iot.camera.data;

import java.util.Collection;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

/**
 * 任务信息持久层实现
 * 
 * @author eguid
 * @since jdk1.7
 * @version 2016年10月29日
 */
public class TaskDaoImpl implements TaskDao {
	// 存放任务信息
	private ConcurrentMap<String, CommandTask> map = null;

	public TaskDaoImpl(int size) {
		map = new ConcurrentHashMap<>(size);
	}

	@Override
	public CommandTask get(String id) {
		return map.get(id);
	}

	@Override
	public Collection<CommandTask> getAll() {
		return map.values();
	}

	@Override
	public int add(CommandTask CommandTask) {
		String id = CommandTask.getId();
		if (id != null && !map.containsKey(id)) {
			map.put(CommandTask.getId(), CommandTask);
			if(map.get(id)!=null)
			{
				return 1;
			}
		}
		return 0;
	}

	@Override
	public int remove(String id) {
		if(map.remove(id) != null){
			return 1;
		};
		return 0;
	}

	@Override
	public int removeAll() {
		int size = map.size();
		try {
			map.clear();
		} catch (Exception e) {
			return 0;
		}
		return size;
	}

	@Override
	public boolean isHave(String id) {
		return map.containsKey(id);
	}

}
