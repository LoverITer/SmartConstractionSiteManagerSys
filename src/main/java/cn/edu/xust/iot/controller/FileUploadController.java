package cn.edu.xust.iot.controller;

import cn.edu.xust.iot.conf.qiniu.QiNiuCloudService;
import cn.edu.xust.iot.error.AppResponseCode;
import cn.edu.xust.iot.model.CommonResponse;
import io.swagger.annotations.*;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

/**
 * 文件上传控制器
 *
 * @author HuangXin
 * @since 2021/03/17 13:56
 */
@Api(tags="文件上传接口")
@Slf4j
@RestController
@RequestMapping("/upload")
public class FileUploadController {

	@Autowired
	private QiNiuCloudService qiNiuCloudService;

	@ApiOperation(value = "图片上传接口",notes = "调用此接口之后文件将会被上传到七牛云图床，上传成功之后会返回图片的URL。注意！上的图片的input的name的名字必须命名为file")
	@ApiImplicitParam(name = "picFile", value = "上传的图片数据", required = true, dataTypeClass = MultipartFile.class)
	@ApiResponses({ @ApiResponse(code = 200, message = "图片上传成功", response = MultipartFile.class),
			@ApiResponse(code = 500, message = "图片上传失败", response = MultipartFile.class) })
	@PostMapping(value = "/default")
	public CommonResponse<String> uploadPicToQiNiu(@RequestParam(value = "file") MultipartFile file) {
		if (file.isEmpty()) {
			CommonResponse<String> result = CommonResponse.create(AppResponseCode.UPLOAD_FAIL);
			result.setMsg("请选择图片");
			return result;
		}
		log.info("图片上传接口 上传图片 '{}',大小： {} bytes", file.getOriginalFilename(), file.getSize());
		try {
			String imageUrl = qiNiuCloudService.uploadByMultipartFile(file);
			log.info("图片上传接口 图片上传成功");
			return CommonResponse.create(AppResponseCode.UPLOAD_SUCCESS,imageUrl);
		} catch (Exception e) {
			log.error("图片上传接口 上传图片失败，原因是：" + e.getMessage());
			return CommonResponse.create(AppResponseCode.UPLOAD_FAIL);
		}
	}

}
