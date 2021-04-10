package cn.edu.xust.iot.camera.data;

import java.util.Collection;

/**
 * 任务信息持久层接口
 * @author eguid
 * @since jdk1.7
 * @version 2016年10月29日
 */
public interface TaskDao {
	/**
	 * 通过id查询任务信息
	 * @param id - 任务ID
	 * @return CommandTasker -任务实体
	 */
	public CommandTask get(String id);
	/**
	 * 查询全部任务信息
	 * @return Collection<CommandTasker>
	 */
	public Collection<CommandTask> getAll();
	/**
	 * 增加任务信息
	 * @param CommandTask -任务信息实体
	 * @return 增加数量：<1-增加失败，>=1-增加成功
	 */
	public int add(CommandTask CommandTask);
	/**
	 * 删除id对应的任务信息
	 * @param id
	 * @return 数量：<1-操作失败，>=1-操作成功
	 */
	public int remove(String id);
	/**
	 * 删除全部任务信息
	 * @return 数量：<1-操作失败，>=1-操作成功
	 */
	public int removeAll();
	/**
	 * 是否存在某个ID
	 * @param id - 任务ID
	 * @return true:存在，false：不存在
	 */
	public boolean isHave(String id);
}
