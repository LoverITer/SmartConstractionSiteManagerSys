/*
 * @Author: https://github.com/WangEn
 * @Author: https://gitee.com/lovetime/
 * @Date:   2018-03-27
 * @lastModify 2018-3-28
 * +----------------------------------------------------------------------
 * | WeAdmin 表格table中多个删除等操作公用js
 * | 有改用时直接复制到对应页面也不影响使用
 * +----------------------------------------------------------------------
 */
var $="";

layui.extend({
	admin: '{/}../../static/js/admin'
});
//删除表格中的用户数据
function deleteTableItem(userId){
	$.ajax({
		//请求获得所有的工人数据
		url: "/admin/members/remove?token="+localStorage.getItem(USER_LOGIN_TOKEN)+"&userIds="+userId,
		method: "get",
		contentType: "application/json",
		sync: false,
		success: function (response) {
			if (response.code == 200) {
				layer.msg('删除成功!', {icon: 1});
				//重新加载table
				loadTable();
			} else {
				layer.msg(response.msg, {icon: 2});
			}
		},
		error: function (response) {
			layer.msg(response.msg, {icon: 2});
		}
	});
}
layui.use(['laydate', 'jquery', 'admin'], function() {
	var laydate = layui.laydate,
		admin = layui.admin;
	$ = layui.jquery;
	//执行一个laydate实例
	laydate.render({
		elem: '#start' //指定元素
	});
	//执行一个laydate实例
	laydate.render({
		elem: '#end' //指定元素
	});


	window.member_del = function (obj, userId) {
		console.log("删除的id:"+userId);
		layer.confirm('确认要删除吗？', function() {
			deleteTableItem(userId);
		});
	};

	window.delAll = function () {
		var data = tableCheck.getData();
		console.log("批量删除:"+data);
		if(data.length<=0){
			layer.msg("请选中需要删除的数据",{icon:3});
			return;
		}
		layer.confirm('确认要删除吗？' + data, function(index) {
			//捉到所有被选中的，发异步进行删除
			deleteTableItem(data);
		});
	}
	
});