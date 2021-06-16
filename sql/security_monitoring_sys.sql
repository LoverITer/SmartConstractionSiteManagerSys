/*
 Navicat Premium Data Transfer

 Source Server         : 47.99.161.205
 Source Server Type    : MySQL
 Source Server Version : 80024
 Source Host           : 47.99.161.205:3306
 Source Schema         : security_monitoring_sys

 Target Server Type    : MySQL
 Target Server Version : 80024
 File Encoding         : 65001

 Date: 14/06/2021 22:57:02
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin_user
-- ----------------------------
DROP TABLE IF EXISTS `admin_user`;
CREATE TABLE `admin_user`  (
  `admin_id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `username` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `password` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `user_id` int NULL DEFAULT NULL,
  `role_id` int NULL DEFAULT NULL COMMENT '管理员的权限',
  PRIMARY KEY (`admin_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1000017 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of admin_user
-- ----------------------------
INSERT INTO `admin_user` VALUES (1000000, 'admin', '0B46FB79A8A4607414229F9A22635AE0', 1000000, 1);
INSERT INTO `admin_user` VALUES (1000004, 'frank', '257D153C66DF93655C2CC27998FC5E92', 1000012, 3);
INSERT INTO `admin_user` VALUES (1000005, 'jinghua', '6EA0F4B884628C5CFFC4480411AE65C2', 1000013, 4);
INSERT INTO `admin_user` VALUES (1000007, 'anyuan', 'A805D92E7EDA474544321922C27486CA', 1000015, 2);
INSERT INTO `admin_user` VALUES (1000015, 'easyblog', 'B19E4B863182BBA079D0614B712EC069', 1000028, 4);
INSERT INTO `admin_user` VALUES (1000016, 'yunlong', '0B46FB79A8A4607414229F9A22635AE0', 1000029, 5);

-- ----------------------------
-- Table structure for attendance
-- ----------------------------
DROP TABLE IF EXISTS `attendance`;
CREATE TABLE `attendance`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `user_id` int NOT NULL COMMENT '人员ID',
  `stark_work_time` datetime NULL DEFAULT NULL COMMENT '上班打卡时间',
  `after_work_time` datetime NULL DEFAULT NULL COMMENT '下班打卡时间',
  `stark_work_device_id` int NULL DEFAULT NULL COMMENT '上班打卡机器',
  `after_work_device_id` int NULL DEFAULT NULL COMMENT '下班打卡机器',
  `late` enum('0','1') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '是否迟到 0 未迟到  1迟到',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 32 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of attendance
-- ----------------------------
INSERT INTO `attendance` VALUES (1, 1000000, '2021-06-05 08:08:33', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (2, 1000001, '2021-06-06 09:09:22', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (3, 1000005, '2021-06-06 18:09:59', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (4, 1000006, '2021-06-06 18:10:13', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (5, 1000007, '2021-06-07 18:10:26', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (6, 1000008, '2021-06-07 18:10:36', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (7, 1000012, '2021-06-07 18:10:54', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (8, 1000000, '2021-06-07 18:36:29', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (9, 1000000, '2021-06-08 19:24:22', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (10, 1000012, '2021-06-08 19:51:51', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (11, 1000013, '2021-06-08 20:35:26', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (12, 1000013, '2021-06-09 16:52:13', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (13, 1000012, '2021-06-09 16:52:27', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (14, 1000008, '2021-06-09 16:52:47', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (15, 1000008, '2021-06-10 17:35:17', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (16, 1000005, '2021-06-10 17:35:49', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (17, 1000006, '2021-06-10 17:35:59', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (19, 1000001, '2021-06-10 14:14:03', NULL, NULL, NULL, '1');
INSERT INTO `attendance` VALUES (20, 1000000, '2021-06-10 15:07:17', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (21, 1000000, '2021-06-11 14:00:46', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (22, 1000001, '2021-06-11 14:01:04', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (23, 1000012, '2021-06-11 14:01:42', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (24, 1000013, '2021-06-11 14:02:01', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (25, 1000005, '2021-06-11 14:02:20', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (26, 1000006, '2021-06-11 14:02:59', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (27, 1000007, '2021-06-11 14:03:08', NULL, NULL, NULL, '0');
INSERT INTO `attendance` VALUES (28, 1000008, '2021-06-11 14:03:27', NULL, NULL, NULL, '0');

-- ----------------------------
-- Table structure for camera
-- ----------------------------
DROP TABLE IF EXISTS `camera`;
CREATE TABLE `camera`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `device_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `device_status` enum('0','1','2','3') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '摄像机状态  0 离线   1  在线  2 告警  3 故障',
  `region_id` int NOT NULL COMMENT '摄像机所在区域ID',
  `algorithm` enum('0','1') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT '0' COMMENT '摄像机所使用的算法  0 系统默认  1 自定义算法',
  `ip` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '摄像机ip',
  `port` int NULL DEFAULT NULL COMMENT '摄像机端口',
  `user_name` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT 'Admin' COMMENT '摄像机用户名',
  `password` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '摄像机密码',
  `model` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '摄像机型号',
  `mac_address` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '摄像机MAC地址',
  `sdc_version` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT 'SDC版本',
  `create_time` datetime NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP COMMENT '创建时间',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 15 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of camera
-- ----------------------------
INSERT INTO `camera` VALUES (3, 'SDC摄像机', '0', 4, '0', '192.168.0.120', 6060, 'admin', 'HuaWei123', 'D2120-10-SIU', 'DC:21:E2:47:B9:94', 'SDC 8.1.1', '2021-06-04 10:40:30');
INSERT INTO `camera` VALUES (4, 'SDC摄像机', '0', 3, '0', '192.168.0.110', 6060, 'admin', '123456', 'D2120-10-SIU', 'DC:21:E2:47:B9:94', 'SDC 8.1.1', '2021-05-09 00:00:00');
INSERT INTO `camera` VALUES (5, 'SDC摄像机', '0', 5, '0', '192.168.1.122', 6060, 'admin', '123456', 'D2120-10-SIU', 'DC:21:E2:47:B9:94', 'SDC 8.1.1', '2021-05-09 00:00:00');
INSERT INTO `camera` VALUES (13, 'SDC摄像机', '0', 8, '0', '192.168.0.244', 6060, 'admin123', 'HuaWei123', 'C2120-I-P', '未知', '未知', '2021-06-10 18:02:58');

-- ----------------------------
-- Table structure for danger
-- ----------------------------
DROP TABLE IF EXISTS `danger`;
CREATE TABLE `danger`  (
  `id` int NOT NULL,
  `danger_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `parent_danger_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of danger
-- ----------------------------
INSERT INTO `danger` VALUES (100000, '人员不安全行为', NULL);
INSERT INTO `danger` VALUES (100001, '危险区域入侵', NULL);
INSERT INTO `danger` VALUES (100002, '安全装备违规佩戴', NULL);
INSERT INTO `danger` VALUES (100003, '未系安全冒带', '100002');
INSERT INTO `danger` VALUES (100004, '未佩戴安全带', '100002');
INSERT INTO `danger` VALUES (100005, '未使用安全挂钩', '100002');
INSERT INTO `danger` VALUES (100006, '未佩戴安全帽', '100002');
INSERT INTO `danger` VALUES (100007, '无防护设备', '100002');
INSERT INTO `danger` VALUES (100008, '投掷', '100000');
INSERT INTO `danger` VALUES (100009, '睡觉', '100000');
INSERT INTO `danger` VALUES (100010, '追逐打闹', '100000');
INSERT INTO `danger` VALUES (100011, '抽烟', '100000');
INSERT INTO `danger` VALUES (100012, '高空违规投掷', '100002');

-- ----------------------------
-- Table structure for danger_behavior
-- ----------------------------
DROP TABLE IF EXISTS `danger_behavior`;
CREATE TABLE `danger_behavior`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `behavior_pic` varchar(512) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '危险行为图片',
  `behavior_type` int NULL DEFAULT NULL COMMENT '危险行为种类ID',
  `create_time` datetime NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP COMMENT '发生时间',
  `region_id` int NOT NULL COMMENT '发生的区域',
  `cert_no` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '违规人员身份证',
  `state` enum('0','1') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT '0' COMMENT '事件处理状态',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 14 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of danger_behavior
-- ----------------------------
INSERT INTO `danger_behavior` VALUES (1, 'https://image.easyblog.top/49f16d57812c42718b4b09e5566b5226.jpg', 100004, '2021-06-10 09:22:03', 3, '610526198704214033', '0');
INSERT INTO `danger_behavior` VALUES (2, 'https://image.easyblog.top/49f16d57812c42718b4b09e5566b5226.jpg', 100004, '2021-06-10 09:25:17', 3, '610526198704214033', '0');
INSERT INTO `danger_behavior` VALUES (3, 'https://image.easyblog.top/49f16d57812c42718b4b09e5566b5226.jpg', 100004, '2021-06-10 09:30:37', 3, '610526198704214033', '0');
INSERT INTO `danger_behavior` VALUES (4, 'https://image.easyblog.top/49f16d57812c42718b4b09e5566b5226.jpg', 100005, '2021-06-10 10:23:19', 4, '610526198704214033', '1');
INSERT INTO `danger_behavior` VALUES (5, 'https://image.easyblog.top/u=2818443100,1578742810&fm=26&gp=0.jpg', 100011, '2021-06-10 11:18:43', 5, '500101198401133397', '1');
INSERT INTO `danger_behavior` VALUES (6, 'https://image.easyblog.top/u=2818443100,1578742810&fm=26&gp=0.jpg', 100011, '2021-06-11 12:32:39', 4, '61232419981230223X', '1');
INSERT INTO `danger_behavior` VALUES (7, 'https://image.easyblog.top/u=2818443100,1578742810&fm=26&gp=0.jpg', 100010, '2021-06-11 15:50:56', 4, '370722197812222517', '1');
INSERT INTO `danger_behavior` VALUES (8, 'https://image.easyblog.top/49f16d57812c42718b4b09e5566b5226.jpg', 100008, '2021-06-11 13:59:03', 5, '610526198704214033', '0');
INSERT INTO `danger_behavior` VALUES (9, 'https://image.easyblog.top/u=3326481052,3558768807&fm=26&gp=0.jpg', 100006, '2021-06-11 14:15:29', 3, '610526198704214033', '0');
INSERT INTO `danger_behavior` VALUES (10, 'https://image.easyblog.top/u=2894906372,2843838646&fm=26&gp=0.jpg', 100006, '2021-06-11 14:18:30', 4, '610523198305134774', '0');
INSERT INTO `danger_behavior` VALUES (11, 'https://image.easyblog.top/u=2894906372,2843838646&fm=26&gp=0.jpg', 100003, '2021-06-11 16:45:12', 4, '61232419981230223X', '0');
INSERT INTO `danger_behavior` VALUES (12, 'https://image.easyblog.top/49f16d57812c42718b4b09e5566b5226.jpg', 100004, '2021-06-11 16:46:33', 5, '61232419981230223X', '0');
INSERT INTO `danger_behavior` VALUES (13, 'https://image.easyblog.top/src=http_%252F%252Fimages.china.cn%252Fattachement%252Fjpg%252Fsite1000%252F20150429%252Fc03fd556705c16aae12c4d.jpg&refer=http_%252F%252Fimages.china.jpg', 100005, '2021-06-11 16:32:03', 3, '61232419981230223X', '0');

-- ----------------------------
-- Table structure for face_lib
-- ----------------------------
DROP TABLE IF EXISTS `face_lib`;
CREATE TABLE `face_lib`  (
  `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT COMMENT '人员唯一识别码',
  `face_pic` varchar(512) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '人脸图片链接',
  `create_time` datetime NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP COMMENT '库的创建时间',
  `memo` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '备注信息',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 22 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of face_lib
-- ----------------------------
INSERT INTO `face_lib` VALUES (1, 'http://image.easyblog.top/16184832192016284bcc0-cc04-4776-b8d0-cab7353bb820.jpg', '2021-04-15 18:41:54', NULL);
INSERT INTO `face_lib` VALUES (3, 'http://scss.easyblog.top/1618554633707bb6a7789-8748-4057-a5e0-60a5bd1044aa.jpg', '2021-04-16 14:31:22', NULL);
INSERT INTO `face_lib` VALUES (4, 'http://scss.easyblog.top/161855591834847dfb6bd-6ab5-4130-94ec-87c8564d5f1b.jpg', '2021-04-16 14:52:11', NULL);
INSERT INTO `face_lib` VALUES (5, 'http://scss.easyblog.top/161855658170447fcc852-e536-4f0e-b56f-b5e08835d7b6.jpg', '2021-04-16 15:03:04', NULL);
INSERT INTO `face_lib` VALUES (6, 'http://scss.easyblog.top/1618557990065c05d10ba-6a71-49a4-9d19-2a4640af0761.jpg', '2021-04-16 15:30:28', NULL);
INSERT INTO `face_lib` VALUES (7, 'http://scss.easyblog.top/16186495634036292fe70-062b-4d4e-a8c2-300b44fd847a.jpg', '2021-04-17 16:52:46', NULL);
INSERT INTO `face_lib` VALUES (8, 'http://scss.easyblog.top/161864977985969394580-f9e1-410d-8954-af9fad8898bc.jpg', '2021-04-17 16:56:22', NULL);
INSERT INTO `face_lib` VALUES (9, 'http://scss.easyblog.top/16186501888600dd8878d-28fa-425e-aa35-368c9bef0827.jpg', '2021-04-17 17:03:42', NULL);
INSERT INTO `face_lib` VALUES (10, 'http://scss.easyblog.top/1618655768005059a1a1b-5b3e-4772-b8b2-ad5f47f63bbf.jpg', '2021-04-17 18:36:36', NULL);
INSERT INTO `face_lib` VALUES (11, 'http://scss.easyblog.top/161897965892880760d78-de9b-4f34-aaf8-199f9c3378f1.jpg', '2021-04-21 12:34:21', NULL);
INSERT INTO `face_lib` VALUES (12, 'http://scss.easyblog.top/16198723588854d61f7ab-c2ec-45f9-a1b9-83726eafc8c6.jpg', '2021-05-01 20:34:44', NULL);
INSERT INTO `face_lib` VALUES (13, 'http://scss.easyblog.top/1620639767808ce240b63-dd28-4b86-98e0-ff10ffa11f51.jpg', '2021-05-10 17:43:12', NULL);
INSERT INTO `face_lib` VALUES (14, 'http://scss.easyblog.top/1620639888555f71be8af-b804-4cb2-964e-f6d5e4101e9f.jpg', '2021-05-10 17:44:51', NULL);
INSERT INTO `face_lib` VALUES (15, 'http://scss.easyblog.top/16206399793090684ec30-568a-4e34-96b1-b370008f466a.jpg', '2021-05-10 17:46:22', NULL);
INSERT INTO `face_lib` VALUES (16, 'http://scss.easyblog.top/162064014039078d779ab-fc63-45d2-bca3-a263d2422c07.jpg', '2021-05-10 17:49:03', NULL);
INSERT INTO `face_lib` VALUES (19, 'http://scss.easyblog.top/1623396470512f48b6765-6227-4a6f-9cd9-3cac31d7423d.jpg', '2021-06-11 15:27:53', NULL);
INSERT INTO `face_lib` VALUES (20, 'http://scss.easyblog.top/1623396545283f6144d34-854f-49a7-9e20-f5ef8c0588df.jpg', '2021-06-11 15:29:08', NULL);
INSERT INTO `face_lib` VALUES (21, 'http://scss.easyblog.top/1623396658432a77da415-1ef7-4d1f-8898-98a701801964.jpg', '2021-06-11 15:31:14', NULL);

-- ----------------------------
-- Table structure for power
-- ----------------------------
DROP TABLE IF EXISTS `power`;
CREATE TABLE `power`  (
  `id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `power_rule` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `power_name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 8 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of power
-- ----------------------------
INSERT INTO `power` VALUES (1, '/admin/member/*,/admin/device/*,/admin/administor/*,/admin/process/*,/admin/eastimate/*', '高级管理权限');
INSERT INTO `power` VALUES (2, '/admin/member/*,/admin/device/*,/admin/process/*,/admin/eastimate/*', '中级管理权限');
INSERT INTO `power` VALUES (3, '/admin/device/*,/admin/process/*,/admin/eastimate/*', '低级管理权限');
INSERT INTO `power` VALUES (4, '/', '无管理权限');

-- ----------------------------
-- Table structure for region
-- ----------------------------
DROP TABLE IF EXISTS `region`;
CREATE TABLE `region`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `region_name` varchar(251) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '区域名称 格式 地区编号#工程编号#楼号#层号 比如 610115#001#03#2  表示临潼区编号为001的工程的3号楼的2层',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 16 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of region
-- ----------------------------
INSERT INTO `region` VALUES (3, '区域1');
INSERT INTO `region` VALUES (4, '区域2');
INSERT INTO `region` VALUES (5, '高空1');
INSERT INTO `region` VALUES (6, '地区4');
INSERT INTO `region` VALUES (7, '区域3');
INSERT INTO `region` VALUES (8, '区域4');
INSERT INTO `region` VALUES (9, '区域5');
INSERT INTO `region` VALUES (10, '区域6');
INSERT INTO `region` VALUES (11, '区域7');
INSERT INTO `region` VALUES (12, '区域8');
INSERT INTO `region` VALUES (13, '区域9');
INSERT INTO `region` VALUES (14, '区域10');
INSERT INTO `region` VALUES (15, '区域12');

-- ----------------------------
-- Table structure for region_camera
-- ----------------------------
DROP TABLE IF EXISTS `region_camera`;
CREATE TABLE `region_camera`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `camera_id` int NOT NULL COMMENT '摄像机ID',
  `region_id` int NOT NULL COMMENT '摄像机所在区域ID',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 15 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of region_camera
-- ----------------------------
INSERT INTO `region_camera` VALUES (3, 3, 4);
INSERT INTO `region_camera` VALUES (4, 5, 5);
INSERT INTO `region_camera` VALUES (7, 4, 3);
INSERT INTO `region_camera` VALUES (9, 9, 9);
INSERT INTO `region_camera` VALUES (13, 13, 8);

-- ----------------------------
-- Table structure for region_human_count
-- ----------------------------
DROP TABLE IF EXISTS `region_human_count`;
CREATE TABLE `region_human_count`  (
  `id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `region_id` int NULL DEFAULT NULL COMMENT '区域ID',
  `human_in` int NULL DEFAULT NULL COMMENT '进入区域的人数',
  `create_date` datetime NULL DEFAULT NULL COMMENT '记录时间',
  `human_out` int NULL DEFAULT NULL COMMENT '离开区域的人数',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 31 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of region_human_count
-- ----------------------------
INSERT INTO `region_human_count` VALUES (1, 1, 4, '2021-06-05 21:25:52', NULL);
INSERT INTO `region_human_count` VALUES (2, 1, 3, '2021-06-05 22:26:21', NULL);
INSERT INTO `region_human_count` VALUES (3, 3, 6, '2021-06-05 21:26:34', NULL);
INSERT INTO `region_human_count` VALUES (4, 6, 33, '2021-06-06 22:26:45', NULL);
INSERT INTO `region_human_count` VALUES (5, 3, 7, '2021-06-06 22:27:06', NULL);
INSERT INTO `region_human_count` VALUES (6, 6, 56, '2021-06-06 21:27:17', NULL);
INSERT INTO `region_human_count` VALUES (7, 7, 44, '2021-06-07 22:30:27', NULL);
INSERT INTO `region_human_count` VALUES (8, 1, 6, '2021-06-07 20:55:43', 1);
INSERT INTO `region_human_count` VALUES (9, 4, 5, '2021-06-08 23:33:12', NULL);
INSERT INTO `region_human_count` VALUES (10, 6, 4, '2021-06-08 23:56:29', 4);
INSERT INTO `region_human_count` VALUES (11, 4, 42, '2021-06-09 16:35:17', 43);
INSERT INTO `region_human_count` VALUES (12, 4, 16, '2021-06-09 16:39:00', 9);
INSERT INTO `region_human_count` VALUES (13, 4, 31, '2021-06-09 19:35:17', NULL);
INSERT INTO `region_human_count` VALUES (14, 4, 6, '2021-06-10 14:26:23', 5);
INSERT INTO `region_human_count` VALUES (15, 4, 35, '2021-06-10 16:18:17', 64);
INSERT INTO `region_human_count` VALUES (16, 3, 23, '2021-06-10 16:27:05', 12);
INSERT INTO `region_human_count` VALUES (17, 5, 5, '2021-06-11 13:45:35', 6);
INSERT INTO `region_human_count` VALUES (18, 9, 2, '2021-06-11 16:06:00', 5);
INSERT INTO `region_human_count` VALUES (19, 10, 55, '2021-06-11 16:06:14', 50);
INSERT INTO `region_human_count` VALUES (20, 3, 21, '2021-06-11 16:06:35', 14);
INSERT INTO `region_human_count` VALUES (21, 4, 14, '2021-06-11 16:06:48', 13);
INSERT INTO `region_human_count` VALUES (22, 5, 44, '2021-06-11 16:07:00', 55);
INSERT INTO `region_human_count` VALUES (23, 6, 6, '2021-06-11 16:07:13', 20);
INSERT INTO `region_human_count` VALUES (24, 7, 41, '2021-06-11 16:07:33', 34);
INSERT INTO `region_human_count` VALUES (25, 8, 16, '2021-06-11 16:07:49', 34);
INSERT INTO `region_human_count` VALUES (26, 11, 34, '2021-06-11 16:08:29', 22);
INSERT INTO `region_human_count` VALUES (27, 12, 23, '2021-06-11 16:12:04', 14);

-- ----------------------------
-- Table structure for role
-- ----------------------------
DROP TABLE IF EXISTS `role`;
CREATE TABLE `role`  (
  `id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `role_name` enum('Admin','PM','CE','SO','CW','CC') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT 'Admin',
  `power_id` int NULL DEFAULT NULL COMMENT 'Admin  管理员， PM  项目经理 ，CE  总工程师，SO  安全员，CW 施工员，CC   造价员 ',
  `description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `status` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 8 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of role
-- ----------------------------
INSERT INTO `role` VALUES (1, 'Admin', 1, '公司领导具有对系统最高的访问控制权限', '1');
INSERT INTO `role` VALUES (2, 'PM', 1, '项目经理角色，是公司在施工现场的代理人，拥有系统的全部访问权限', '0');
INSERT INTO `role` VALUES (3, 'CE', 2, '总工程师角色，对管理员管理没有权限', '0');
INSERT INTO `role` VALUES (4, 'SO', 3, '安全员角色，只对安全管理和安全设备管理有权限', '1');
INSERT INTO `role` VALUES (5, 'CW', 3, '施工员角色，只对工程进度管理有权限', '1');
INSERT INTO `role` VALUES (6, 'CC', 3, '造价员，只对工程预算管理有权限', '1');

-- ----------------------------
-- Table structure for s_user
-- ----------------------------
DROP TABLE IF EXISTS `s_user`;
CREATE TABLE `s_user`  (
  `id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `face_lib_id` bigint NULL DEFAULT NULL COMMENT '录入的人脸库ID',
  `gender` enum('0','1','-1') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT '0' COMMENT '性别 0 男性  1 女性',
  `name` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '姓名',
  `phone` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '手机',
  `birth` datetime NULL DEFAULT NULL COMMENT '生日',
  `address` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '户籍地址',
  `certificate_type` enum('0','1','2','3','4') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT '0' COMMENT '证件类型 ：0 身份证  1 护照  2 军官证 3 驾驶证  4 其他',
  `certificate_no` varchar(32) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '证件号',
  `job` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '岗位',
  `is_manager` enum('0','1','-1') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT '0' COMMENT '标识该人员是否是重要人员 0 不是  1 是 -1 未知',
  `create_time` datetime NULL DEFAULT NULL COMMENT '创建时间',
  `memo` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '备注信息',
  `state` enum('0','1') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT '1' COMMENT '人员状态 0 已经离职  1 在职',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1000033 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of s_user
-- ----------------------------
INSERT INTO `s_user` VALUES (1000000, 1, '0', '黄鑫', '15709160159', '1998-12-30 08:00:00', '陕西汉中', '0', '61232419981230221X', '系统管理员', '1', '2021-05-16 08:00:00', '   无', '1');
INSERT INTO `s_user` VALUES (1000001, 3, '0', '唐哲瀚', '15922798077', '1984-04-17 08:00:00', '四川省 成都市', '0', '510704198104183738', '项目经理', '1', '2021-04-16 08:00:00', '  无', '1');
INSERT INTO `s_user` VALUES (1000005, 7, '0', '罗高卓', '18996888888', '1987-04-17 09:00:00', '安徽省 合肥市', '0', '500101198401133397', '电工', '0', '2021-04-17 08:00:00', '', '1');
INSERT INTO `s_user` VALUES (1000006, 8, '0', '冯德海', '16223011112', '1999-04-17 08:00:00', '河北省', '0', '130426198908106712', '木工', '0', '2021-04-17 08:00:00', '', '1');
INSERT INTO `s_user` VALUES (1000007, 9, '0', '平明远', '18983588888', '1987-04-17 09:00:00', '陕西宝鸡', '0', '610523198305134774', '钢筋工', '0', '2021-04-17 08:00:00', ' ', '1');
INSERT INTO `s_user` VALUES (1000008, 10, '0', '葛黎昕', '17711177777', '1992-04-17 08:00:00', '河北省', '0', '130928198905281793', '混凝土工', '0', '2021-04-17 08:00:00', ' 无', '1');
INSERT INTO `s_user` VALUES (1000012, 11, '0', '孙策', '18666490869', '2021-04-21 08:00:00', 'NA', '0', '370722197812222517', '总工程师', '1', '2021-04-20 08:00:00', '  NA', '1');
INSERT INTO `s_user` VALUES (1000013, 12, '0', '孙京华', '15667895534', '2021-05-01 08:00:00', 'NA', '0', '610526198704214033', '安全员', '1', '2021-05-01 08:00:00', 'NA', '1');
INSERT INTO `s_user` VALUES (1000015, 13, '0', '李刚', '15766668977', '2021-05-10 08:00:00', 'NA', '0', '61232419981230222X', '项目经理', '0', '2021-05-09 08:00:00', 'NA', '1');
INSERT INTO `s_user` VALUES (1000016, 14, '0', '黄磊', '17655889008', '1991-05-10 09:00:00', '湖北武汉', '0', '61232419981230223X', '电工', '0', '2021-05-10 08:00:00', '', '1');
INSERT INTO `s_user` VALUES (1000017, 15, '0', '祝建国', '13677460922', '1999-04-15 08:00:00', '陕西咸阳', '0', '61232419981230224x', '水暖工', '0', '2021-05-10 08:00:00', '', '1');
INSERT INTO `s_user` VALUES (1000018, 16, '0', '祝国尧', '15709883321', '1997-08-04 08:00:00', '陕西汉中', '0', '612324199808042214', '涂料工', '0', '2021-05-10 08:00:00', '', '1');
INSERT INTO `s_user` VALUES (1000030, 19, '0', '李云龙', '15677889966', '1987-04-17 09:00:00', '河北省', '0', '61231419981230221X', '木工', '0', '2021-06-11 08:00:00', '', '1');
INSERT INTO `s_user` VALUES (1000031, 20, '0', '李伟', '15709160159', '2021-04-15 08:00:00', '陕西咸阳', '0', '612423199812302212', '钢筋工', '0', '2021-06-11 08:00:00', '', '1');
INSERT INTO `s_user` VALUES (1000032, 21, '0', '王超', '13566778899', '1999-04-17 08:00:00', '陕西西安', '0', '61232419981203221X', '木工', '0', '2021-06-11 08:00:00', '', '1');

SET FOREIGN_KEY_CHECKS = 1;
