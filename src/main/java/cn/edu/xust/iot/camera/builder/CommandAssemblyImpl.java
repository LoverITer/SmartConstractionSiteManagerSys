package cn.edu.xust.iot.camera.builder;

import java.util.Map;

/**
 * 命令组装器
 *
 * @author HuangXin
 * @since 2021/4/9 8:40
 */
public class CommandAssemblyImpl implements CommandAssembly {

    /**
     * @param paramMap -要组装的命令参数
     * @return
     */
    public String assembly(Map<String, String> paramMap) {
        try {
            if (paramMap.containsKey("ffmpegPath")) {
                String ffmpegPath = (String) paramMap.get("ffmpegPath");
                // -i：输入流地址或者文件绝对地址
                StringBuilder comm = new StringBuilder(ffmpegPath + " -i ");
                // 是否有必输项：输入地址，输出地址，应用名，twoPart：0-推一个元码流；1-推一个自定义推流；2-推两个流（一个是自定义，一个是元码）
                if (paramMap.containsKey("input") && paramMap.containsKey("output") && paramMap.containsKey("appName")
                        && paramMap.containsKey("twoPart")) {
                    String input = (String) paramMap.get("input");
                    String output = (String) paramMap.get("output");
                    String appName = (String) paramMap.get("appName");
                    String twoPart = (String) paramMap.get("twoPart");
                    String codec = (String) paramMap.get("codec");
                    // 默认h264解码
                    codec = (codec == null ? "h264" : (String) paramMap.get("codec"));
                    // 输入地址
                    comm.append(input);
                    // 当twoPart为0时，只推一个元码流
                    if ("0".equals(twoPart)) {
                        comm.append(" -vcodec ").append(codec).append(" -f flv -an ").append(output).append(appName);
                    } else {
                        // -f ：转换格式，默认flv
                        if (paramMap.containsKey("fmt")) {
                            String fmt = (String) paramMap.get("fmt");
                            comm.append(" -f ").append(fmt);
                        }
                        // -r :帧率，默认25；-g :帧间隔
                        if (paramMap.containsKey("fps")) {
                            String fps = (String) paramMap.get("fps");
                            comm.append(" -r ").append(fps);
                            comm.append(" -g ").append(fps);
                        }
                        // -s 分辨率 默认是原分辨率
                        if (paramMap.containsKey("rs")) {
                            String rs = (String) paramMap.get("rs");
                            comm.append(" -s ").append(rs);
                        }
                        // 输出地址+发布的应用名
                        comm.append(" -an ").append(output).append(appName);
                        // 当twoPart为2时推两个流，一个自定义流，一个元码流
                        if ("2".equals(twoPart)) {
                            // 一个视频源，可以有多个输出，第二个输出为拷贝源视频输出，不改变视频的各项参数并且命名为应用名+HD
                            comm.append(" -vcodec copy  -f flv -an ").append(output).append(appName).append("HD");
                        }
                    }
                    return comm.toString();
                }
            }
        } catch (Exception e) {
            return null;
        }
        return null;
    }

    @Override
    public String assembly() {
        // TODO Auto-generated method stub
        return null;
    }

}
