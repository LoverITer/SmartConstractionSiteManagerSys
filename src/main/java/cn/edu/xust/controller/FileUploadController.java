package cn.edu.xust.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import cn.edu.xust.CommonResponse;
import cn.edu.xust.conf.qiniu.QiNiuCloudService;
import cn.edu.xust.error.AppResponseCode;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;
import lombok.extern.slf4j.Slf4j;

/**
 * 文件上传控制器
 *
 * @author HuangXin
 * @since 2021/03/17 13:56
 */
@Api(value = "FileUploadController", description = "文件上传接口")
@Slf4j
@RestController
@RequestMapping("/upload")
public class FileUploadController {

	@Autowired
	private QiNiuCloudService qiNiuCloudService;

	@ApiImplicitParam(name = "picFile", value = "上传的图片数据", required = true, dataTypeClass = MultipartFile.class)
	@ApiResponses({ @ApiResponse(code = 200, message = "图片上传成功", response = MultipartFile.class),
			@ApiResponse(code = 500, message = "图片上传失败", response = MultipartFile.class) })
	@PostMapping(value = "/pic")
	public CommonResponse<String> uploadPicToQiNiu(@RequestParam MultipartFile picFile) {
		CommonResponse<String> reslut = CommonResponse.create(AppResponseCode.FAIL);
		if (picFile.isEmpty()) {
			reslut.setMsg("请选择图片");
			return reslut;
		}
		log.info("上传图片 '%s',大小 %d bytes", picFile.getOriginalFilename(), picFile.getSize());
		try {
			String imageUrl = qiNiuCloudService.uploadByMultipartFile(picFile);
			reslut.setCode(AppResponseCode.SUCCESS.getCode());
			reslut.setMsg("图片上传成功");
			reslut.setData(imageUrl);
			log.info("图片上传成功");
		} catch (Exception e) {
			log.error("上传图片失败，原因是：" + e.getMessage());
			reslut.setMsg("图片上传失败，原因是：" + e.getMessage());
		}
		return reslut;
	}

}
