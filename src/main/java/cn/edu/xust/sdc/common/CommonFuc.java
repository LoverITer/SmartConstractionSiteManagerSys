package cn.edu.xust.sdc.common;

import java.io.UnsupportedEncodingException;

/**
 * 公共接口函数类
 *
 * @author HuangXin
 *
 */
public class CommonFuc {

	// 字节数组（含无效元素）转字符串
	public static String byteToString(byte[] bytes) {
		int length = 0;
		for (int i = 0; i < bytes.length; i++) {
			if (bytes[i] == 0) {
				length = i;
				break;
			} else {
				// codex :: to do nothing
			}
		}

		String s = null;
		try {
			s = new String(bytes, 0, length, "GBK");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
		return s;
	}

	// 校验起始、结束ip
	/*
	 * public static boolean checkIPAddress(String startIp, String endIp) { String
	 * pattern =
	 * "([1-9]|[1-9]\\d|1\\d{2}|2[0-1]\\d|25[0-5])(\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3}";
	 * Pattern r = Pattern.compile(pattern); boolean matchStartIP =
	 * r.matcher(startIp).matches(); boolean matchEndIP =
	 * r.matcher(endIp).matches(); if (!matchStartIP) {
	 * JOptionPane.showMessageDialog(null, Res.string().getTip_STARTIP_ERR(),
	 * GlobalVariant.strTip, JOptionPane.INFORMATION_MESSAGE); return false; } else
	 * if (!matchEndIP) { JOptionPane.showMessageDialog(null,
	 * Res.string().getTip_ENDIP_ERR(), GlobalVariant.strTip,
	 * JOptionPane.INFORMATION_MESSAGE); return false; } else if
	 * (!compareIP(startIp, endIp)) { JOptionPane.showMessageDialog(null,
	 * Res.string().getTip_ENDIPLESSTHANSTARTIP(), GlobalVariant.strTip,
	 * JOptionPane.INFORMATION_MESSAGE); return false; } else if (countIp(startIp,
	 * endIp) > 6000) { // 支持最大IP数量6000 JOptionPane.showMessageDialog(null,
	 * Res.string().getTip_IP_OVERRANGE(), GlobalVariant.strTip,
	 * JOptionPane.INFORMATION_MESSAGE); return false; } return true; }
	 */

	// 比较两个ip大小
	public static boolean compareIP(String startIp, String endIp) {
		String[] startIps = startIp.split("\\.");
		String[] endIps = endIp.split("\\.");
		for (int i = 0; i < 4; i++) {
			int intIpS = Integer.parseInt(startIps[i]);
			int intIpE = Integer.parseInt(endIps[i]);
			if (intIpE > intIpS) {
				return true;
			} else if (intIpE == intIpS) {
				continue;
			} else {
				return false;
			}
		}
		return true;
	}

	// 计算ip区间中ip数量
	public static int countIp(String startIp, String endIp) {
		String[] startIps = startIp.split("\\.");
		String[] endIps = endIp.split("\\.");
		int first = (Integer.parseInt(endIps[0]) - Integer.parseInt(startIps[0])) * (256 ^ 3);
		int second = (Integer.parseInt(endIps[1]) - Integer.parseInt(startIps[1])) * (256 ^ 2);
		int third = (Integer.parseInt(endIps[2]) - Integer.parseInt(startIps[2])) * 256;
		int fourth = Integer.parseInt(endIps[3]) - Integer.parseInt(startIps[3]) + 1;
		int count = first + second + third + fourth;
		System.out.println("IP数量：" + count);
		return count;
	}

	// 拼接ip地址
	public static String makeUpIPAddress(String strIpA, String strIpB, String strIpC, String strIpD) {
		String tIP = strIpA;
		tIP += GlobalVariant.strDot;
		tIP += strIpB;
		tIP += GlobalVariant.strDot;
		tIP += strIpC;
		tIP += GlobalVariant.strDot;
		tIP += strIpD;
		return tIP;
	}
}
