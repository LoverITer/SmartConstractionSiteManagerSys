package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.mapper.pagehelper.PageParam;
import cn.edu.xust.iot.model.AdminUserModel;
import cn.edu.xust.iot.model.CameraModel;
import cn.edu.xust.iot.model.CommonResponse;
import cn.edu.xust.iot.model.SUserModel;
import cn.edu.xust.iot.model.vo.CameraVO;
import cn.edu.xust.iot.model.vo.SUserVO;
import cn.edu.xust.iot.service.IAdminUserService;
import cn.edu.xust.iot.service.ICameraService;
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
import java.util.Date;
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

    @Autowired
    private ICameraService cameraService;

    @Autowired
    private IAdminUserService adminUserService;


    @ApiOperation(value = "后台管理系统首页", notes = "后台管理系统首页")
    @GetMapping(value = "/index")
    public String index(@RequestParam(value = "token") String token, ModelMap model) {
        model.addAttribute("token", token);
        return "admin_index";
    }


    /**
     * 获得所有人员的个人信息
     *
     * @return
     */
    @ApiOperation(value = "获得所有人员的个人信息", notes = "获得所有人员的个人信息")
    @ResponseBody
    @GetMapping(value = "/members/list")
    public CommonResponse<PageInfo<SUserVO>> getAllMembers(@RequestParam(required = false, defaultValue = "1") int page, @RequestParam(required = false, defaultValue = "5") int pageSize) {
        if (-1 == pageSize) {
            //查询全部的数据
            pageSize = userService.getAllMembersSize().getData();
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
        return userService.getAllMembersSize();
    }


    @ApiOperation(value = "添加新成员接口")
    @ResponseBody
    @PostMapping(value = "/members/add")
    public CommonResponse<String> addNewMember(@RequestBody @Valid SUserModel userModel, BindingResult result) {
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
            StringBuilder builder = new StringBuilder("修改人员信息接口 修改人员信息失败，原因是：");
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
    @ApiOperation(value = "删除人员接口", notes = "删除人员接口，传入需要删除的用人员的id，支持批量删除，多个人员id之间使用';'隔开")
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


    @ApiOperation(value = "获取系统监控摄像机的信息", notes = "获取系统监控摄像机的信息，如果查询到数据响应码是200，否者响应码一律都是500")
    @ResponseBody
    @GetMapping(value = "/cameras/list")
    public CommonResponse<PageInfo<CameraVO>> getAllCameras(@RequestParam(required = false, defaultValue = "1") int page,
                                                            @RequestParam(required = false, defaultValue = "5") int pageSize) {
        if (-1 == pageSize) {
            //查询全部的数据
            pageSize = cameraService.getAllCamerasSize().getData();
        }
        PageInfo<CameraVO> allCameras = cameraService.getCameraList(PageParam.create(page, pageSize));
        if (null == allCameras) {
            return CommonResponse.create(AppResponseCode.FAIL);
        }
        return CommonResponse.create(AppResponseCode.SUCCESS, allCameras);
    }

    @ApiOperation(value = "获取系统监控摄像机的数量")
    @ResponseBody
    @GetMapping(value = "/cameras/count")
    public CommonResponse<Integer> getAllCamerasSize() {
        return cameraService.getAllCamerasSize();
    }


    @ApiOperation(value = "添加新监控摄像头接口")
    @ResponseBody
    @PostMapping(value = "/cameras/add")
    public CommonResponse<String> addNewCamera(@RequestBody @Valid CameraModel cameraModel, BindingResult result) {
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("添加新监控摄像头接口 添加失败，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID, builder.toString());
        }
        return cameraService.addNewCamera(cameraModel);
    }

    @ApiOperation(value = "修改监控摄像机信息接口")
    @ResponseBody
    @PostMapping(value = "/cameras/edit")
    public CommonResponse<String> editCamera(@RequestBody @Valid CameraModel cameraModel, BindingResult result) {
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("修改监控摄像机信息接口 修改摄像机信息失败，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID, builder.toString());
        }
        return cameraService.editCameraInfo(cameraModel);
    }


    /**
     * 删除监控摄像机接口，传入需要删除的监控摄像机的id，支持批量删除，多个监控摄像机id之间使用';'隔开
     *
     * @param cameraIds
     * @return
     */
    @ApiOperation(value = "删除监控摄像机接口", notes = "删除监控摄像机接口，传入需要删除的监控摄像机的id，支持批量删除，多个监控摄像机id之间使用';'隔开")
    @ResponseBody
    @GetMapping(value = "/cameras/remove")
    public CommonResponse<String> removeCamerasBatch(@RequestParam String cameraIds) {
        if (CommonUtils.isNull(cameraIds)) {
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        //需要删除的监控摄像机id列表
        List<Integer> cameraIdList = Arrays.stream(cameraIds.split(","))
                .map(s -> Integer.parseInt(s.trim()))
                .collect(Collectors.toList());
        return cameraService.removeCameraBatch(cameraIdList);
    }

    @ApiOperation(value = "获取系统所有管理人员数据接口", notes = "获取系统所有管理人员数据接口")
    @ResponseBody
    @GetMapping(value = "/administrator/list")
    public CommonResponse<PageInfo<AdminUserModel>> getAllAdministratorList(@RequestParam(required = false, defaultValue = "1") int page,
                                                                            @RequestParam(required = false, defaultValue = "5") int pageSize) {
        if (-1 == pageSize) {
            //查询全部的数据
            pageSize = adminUserService.getAllAdminUserSize().getData();
        }
        PageInfo<AdminUserModel> allAdminUserList = adminUserService.getAllAdminUserList(PageParam.create(page, pageSize));
        if (null == allAdminUserList) {
            return CommonResponse.create(AppResponseCode.FAIL);
        }
        return CommonResponse.create(AppResponseCode.SUCCESS, allAdminUserList);
    }


    @ApiOperation(value = "获取系统所有管理人员数据接口", notes = "获取系统所有管理人员数据接口")
    @ResponseBody
    @GetMapping(value = "/administrator/count")
    public CommonResponse<Integer> getAllAdministratorSize() {
        return adminUserService.getAllAdminUserSize();
    }

    @ApiOperation(value = "添加新的管理员接口", notes = "添加新的管理员")
    @ResponseBody
    @PostMapping(value = "/administrator/add")
    public CommonResponse<String> addNewAdminUser(@RequestBody @Valid AdminUserModel userModel,BindingResult result) {
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("添加新管理员接口 添加失败，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID, builder.toString());
        }
        //验证两次输入的密码是否一致
        String password = userModel.getPassword();
        String[] pass = password.split(",");
        if(pass[0].equals(pass[1])){
            userModel.setPassword(pass[0]);
            if(null==userModel.getCreateTime()){
                userModel.setCreateTime(new Date());
            }
            return adminUserService.addNewAdminUser(userModel);
        }
        return CommonResponse.create(AppResponseCode.INCONSISTENT_PASSWORDS);
    }

    @ApiOperation(value = "添加新的管理员接口", notes = "添加新的管理员")
    @ResponseBody
    @PostMapping(value = "/administrator/edit")
    public CommonResponse<String> editAdminUser(@RequestBody @Valid AdminUserModel userModel,BindingResult result) {
        if (result.getErrorCount() > 0) {
            StringBuilder builder = new StringBuilder("修改管理员信息接口 修改摄像机信息失败，原因是：");
            for (FieldError error : result.getFieldErrors()) {
                builder.append(error.getField()).append(":").append(error.getDefaultMessage());
            }
            log.error(builder.toString());
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID, builder.toString());
        }
        return adminUserService.editAdminUser(userModel);
    }

    @ApiOperation(value = "添加新的管理员接口", notes = "添加新的管理员")
    @ResponseBody
    @GetMapping(value = "/administrator/remove")
    public CommonResponse<String> removeAdminUser(@RequestParam String adminUserIds) {
        if (CommonUtils.isNull(adminUserIds)) {
            return CommonResponse.create(AppResponseCode.REQUEST_PARAMETER_VALID);
        }
        //需要删除的监控摄像机id列表
        List<Integer> cameraIdList = Arrays.stream(adminUserIds.split(","))
                .map(s -> Integer.parseInt(s.trim()))
                .collect(Collectors.toList());
        return adminUserService.removeAdminUser(cameraIdList);
    }


}