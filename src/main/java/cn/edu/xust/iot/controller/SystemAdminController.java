package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.SUserModel;
import cn.edu.xust.iot.model.vo.SUserVO;
import cn.edu.xust.iot.service.ISUserService;
import cn.edu.xust.iot.utils.CommonUtils;
import com.github.pagehelper.PageInfo;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * 系统后台管理接口，主要功能包括系统管理员登陆、摄像机设备的增删改查、建筑施工人员的增删改查等
 *
 * @author HuangXin
 * @since 2021/4/13 10:29
 */
@Slf4j
@Api(tags = "系统后台管理接口")
@Controller
@RequestMapping(value = "/admin")
public class SystemAdminController {

    @Autowired
    private ISUserService userService;

    @ApiOperation(value = "后台管理系统首页", notes = "后台管理系统首页")
    @GetMapping(value = "/index")
    public String index(@RequestParam(value = "token") String token, ModelMap model) {
        model.addAttribute("token", token);
        return "index";
    }


    /**
     * 获得所有人员的个人信息
     *
     * @return
     */
    @ApiOperation(value = "获得所有人员的个人信息", notes = "获得所有人员的个人信息")
    @ResponseBody
    @GetMapping(value = "/members/list")
    public CommonResponse<PageInfo<SUserVO>> getAllMembers(@RequestParam(required = false,defaultValue = "1") int page, @RequestParam(required = false,defaultValue = "5") int pageSize) {
        if(-1==pageSize){
            //查询全部的数据
            pageSize=userService.getAllMembersSize().getData();
        }
        PageInfo<SUserVO> allMembers = userService.getAllMembers(PageParam.create(page, pageSize));
        if (null == allMembers) {
            return CommonResponse.create(AppResponseCode.FAIL);
        }
        return CommonResponse.create(AppResponseCode.SUCCESS, allMembers);
    }

    @ApiOperation(value = "获得所有人员的个人信息")
    @ResponseBody
    @GetMapping(value = "/members/count")
    public CommonResponse<Integer> getAllMembersSize() {
        return  userService.getAllMembersSize();
    }


    @ApiOperation(value = "添加新人员接口")
    @ResponseBody
    @PostMapping(value = "/members/add")
    public CommonResponse<String> addNewMembers(@RequestBody @Valid SUserModel userModel, BindingResult result) {
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("添加新成员接口 添加失败，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID, builder.toString());
        }
        return userService.addNewMembers(userModel);
    }

    @ApiOperation(value = "修改人员信息接口")
    @ResponseBody
    @PostMapping(value = "/members/edit")
    public CommonResponse<String> editMember(@RequestBody @Valid SUserModel userModel, BindingResult result) {
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("修改人员接口 修改人员信息失败，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID, builder.toString());
        }
        return userService.editMemberInfo(userModel);
    }


    /**
     * 删除人员接口，传入需要删除的用人员的id，支持批量删除，多个人员id之间使用';'隔开
     *
     * @param userIds
     * @return
     */
    @ApiOperation(value = "删除人员接口")
    @ResponseBody
    @GetMapping(value = "/members/remove")
    public CommonResponse<String> removeMemberBatch(@RequestParam String userIds) {
        if (CommonUtils.isNull(userIds)) {
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        //需要删除的人员id列表
        List<Integer> userIdList = Arrays.stream(userIds.split(","))
                .map(s -> Integer.parseInt(s.trim()))
                .collect(Collectors.toList());
        return userService.removeMemberBatch(userIdList);
    }

}