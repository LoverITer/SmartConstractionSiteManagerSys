package cn.edu.xust.iot.conf;

import cn.edu.xust.iot.conf.qiniu.QiNiuCloudService;
import org.junit.Ignore;
import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.util.UUID;

/**
 * 七牛云图片上传服务测试
 *
 * @author HuangXin
 * @since 2021/03/17 10:05
 */
@RunWith(SpringRunner.class)
@SpringBootTest
public class QiNiuCloudPicServiceTest {

	@Autowired
	private QiNiuCloudService qiNiuCloudService;

	@Test
	public void deleteFileByUrlTest() {
		boolean res = qiNiuCloudService
				.delete("http://scss.easyblog.top/161594823788626b5dabc-7c7d-458b-a612-59db7b430307.jpg");
		if (res) {
			System.out.println("删除成功");
		} else {
			System.out.println("删除失败");
		}
	}

	@Ignore
	private byte[] getFileBytesArray(String filePath) {
		File image = new File(filePath);
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		byte[] bytes = null;
		try {
			BufferedImage bi = ImageIO.read(image);
			ImageIO.write(bi, "jpg", baos);
			bytes = baos.toByteArray();
			System.out.println(bytes.length);
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				baos.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return bytes;
	}

	/**
	 * 测试七牛云以字节数组的形式上传图片
	 *
	 * @throws IOException
	 */
	@Test
	public void uploadByByteArrayTest() throws IOException {
		byte[] bytes = getFileBytesArray("C:\\Users\\Administrator\\Pictures\\IMAGE\\hello-world.jpg");
		String imageName = System.currentTimeMillis() + UUID.randomUUID().toString() + ".jpg";
		// 上传图片byte数组
		String imageUrl = qiNiuCloudService.uploadByByteArray(bytes, imageName);
		System.out.println(imageUrl);
	}

	@Test
	public void uploadByFileLocalPath() {
		String imageName = System.currentTimeMillis() + UUID.randomUUID().toString() + ".jpg";
		String imgUrl;
		try {
			imgUrl = qiNiuCloudService.uploadByFileLocalPath(
					"C:\\Users\\Administrator\\Pictures\\IMAGE\\微信图片_20210125141655.jpg", imageName);
			System.out.println(imgUrl);
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
