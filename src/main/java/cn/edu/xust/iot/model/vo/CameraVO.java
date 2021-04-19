package cn.edu.xust.iot.model.vo;

import cn.edu.xust.iot.model.CameraModel;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;

/**
 * 相机视图显示对象
 *
 * @author HuangXin
 * @since 2021/4/12 14:06
 */
@EqualsAndHashCode(callSuper = true)
@Data
public class CameraVO extends CameraModel implements Serializable {

}
