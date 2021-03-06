#ifndef _HW_PU_SDK_H_
#define _HW_PU_SDK_H_

#ifdef _WIN32
//for windows
#ifdef HWFEDSDK_EXPORTS
#define _HW_PU_API extern "C" __declspec(dllexport)
#else
#define _HW_PU_API extern "C" __declspec(dllimport)
#endif

#else
//for linux
#define _HW_PU_API extern "C"
#define __stdcall
#define CALLBACK
#define WINAPI
#endif

#ifdef _WIN32
#define PU_TRUE TRUE
#define PU_FALSE FALSE
#include "stdafx.h"
#else
#define PU_TRUE 1
#define PU_FALSE 0

#ifndef CONST
#define CONST const
#endif

typedef char                CHAR;
typedef unsigned char       UCHAR;
typedef short               SHORT;
typedef unsigned short      USHORT;
typedef int                 INT;
typedef unsigned int        UINT;
typedef int                 BOOL;
typedef long                LONG;
typedef long                DWORD;
typedef unsigned long       ULONG;
typedef unsigned long long  ULONGLONG;
typedef long long           LONGLONG;
typedef void *              HANDLE;
typedef void                VOID;
typedef int                 SOCKET;
typedef void *              HWND;
typedef float               FLOAT;

#endif

#pragma pack(push,1)
/********************************宏定义**********************************************/
#define PU_RESERVE_LEN             32            //预留字节长
#define PU_RESERVE_EX_LEN          256           //预留字节长扩充

#define PU_VERSION_LEN             32            //版本长度
#define PU_DEVICE_NAME_LEN         32            //设备名称长度
#define PU_FAC_NAME_LEN            12            //厂商名称长度
#define PU_DEVICE_TYPE_LEN         32            //设备类型长度
#define PU_SERIAL_LEN              32            //序列号长度

#define PU_ESN_INFO_LEN	32		   //设备ESN号长度

#define PU_IP4_ADDR_LEN            16            //ipv4
#define PU_MULTICAST_ADDR_LEN      32            //组播地址长度
#define PU_IP6_ADDR_LEN            40            //ipv6
//#define PU_MAC_ADDR_LEN_MAX        (6)           //MAC地址长度
#define PU_HEX_MAC_ADDR_LEN        (18)          //十六进制MAC地址长度

#define PU_PLATFORM_INFO_LEN       32            //平台信息长度

#define PU_PTZ_NAME_LEN            32            //云台名称最大值
#define PU_PTZ_CRUISE_LEN          32            //预置位长度
#define PU_PTZ_CRUISE_POINT_MAX    32            //轨迹点最大值
#define PU_PTZ_PRESET_NUM          10            //预置位数
#define PU_PTZ_GEAR_NUM_MAX       (10)           //云台连续离散档位最大值

#define PU_PRIVACY_MASK_MAX        10            //隐私保护矩形最大值
#define PU_ALARM_TIME_MAX          8             //告警时间段最大值
#define PU_ALARM_AREA_MAX          16            //告警矩形最大值

#define PU_CRUISE_DWELL_MIN        3             //巡航轨迹最小停留时间
#define PU_CRUISE_DWELL_MAX        3600          //巡航轨迹最大停留时间
#define PU_CRUISE_SPEED_MIN        1             //巡航轨迹最小转动速度
#define PU_CRUISE_SPEED_MAX        10            //巡航轨迹最大转动速度

#define PU_TIME_YEAR_LEN           5             //日期中"年"字符串长度
#define PU_TIME_OTHERS_LEN         3             //日期中除"年"外其他字符串长度
#define PU_TIME_TOTAL_LEN          32            //日期字符串总长度

#define PU_UPGRADE_FILE_NUM_MAX    16            //上传文件最大数
#define PU_UPGRADE_FILE_LEN_MAX    300           //上传文件路径长度

#define PU_INVADE_LINE_NUM_MAX     5             //入侵线最大数

#define PU_SAVE_FILE_PATH_MAX      128           //保存文件的最大路径

#define PU_ALARM_CAMERA_MAX        4             //最大告警联动镜头数
#define PU_ALARM_DO_MAX            4             //最大告警联动输出开关数

#define PU_USER_NAME_LEN           32            //用户名最大长度
#define PU_PASSWORD_LEN            (64 + 4)      //Pwd最大长度
#define PU_CLIENT_USERNAME_LEN     (32 + 4)      //FTP用户名最大长度
#define PU_FTP_UPLOAD_PATH_LEN     (128 + 4)     //FTP上传目录长度

#define PU_CAMERA_NUM_MAX          4             //摄像机支持的最大镜头数

#define PU_TRIPWIRE_LEN_NUM_MAX    5             //绊线告警最大线数
#define PU_IGT_AREA_POINTS_NUM     10            //区域顶点最大数目
#define PU_IGT_AREA_NUM            4             //最大区域数目
#define PU_IGT_LINE_NAME_LEN       (32 + 4)      //智能拌线名称长度
#define PU_IGT_AREA_NAME_LEN       (32 + 4)      //智能区域名称长度

#define PU_DEVICE_NUM_MAX          (1000)        //最大接入1000路设备
#define PU_DEVICE_LOGIN_NUM_MAX    (20000)       //最大接入20000路设备
#define PU_TRANSPARENT_CMD_MAX     256           //透明通道命令长度
#define PU_DOMAIN_LEN              256           //域名最大长度
#define PU_IRLIGHT_NUM_MAX         4             //红外球机支持的红外灯个数

#define PU_DIO_NAME_LEN            (32 + 4)      //开关量名称长度
#define PU_DIO_NUM_MAX             8             //开关量输入/输出最大个数
#define PU_RECORD_PLAN_NUM         28            //平台录像计划条数
#define PU_RECORD_PLAN_NUM_SD      24            //SDcard录像计划条数
#define MAX_RECORD_CONTENTID_LEN   64            //录像文件名最大长度
#define PU_LOG_INFO_LEN            256           //每条日志的最大长度
#define PU_LOG_INFO_NUM            100           //日志查询每次返回的最大长度
#define PU_NAT_SESSIONID_LEN       32            //NAT穿越的sessid长度
#define PU_NAT_URL_LEN             256           //NAT穿越的会话URL长度
#define PU_RECORD_TYPE_NUM         4             //录像类型个数
#define PU_RECORD_INFO_NUM_MAX     5             //录像信息最大个数
#define PU_RECORD_CONTENTID_LEN    (40)            //录像文件名长度
#define PU_VIDEO_FORMAT_NUM        4             //视频编码格式个数
#define PU_STREAM_NUM              4             //最大码流个数
#define PU_STREAM_NUM_V2           5             //最大码流个数(从之前的三码流变为五码流)
#define PU_OSD_STRING_LEN          (96 + 4)      //OSD场名最大值
#define PU_OSD_STRING_NUM          7             //OSD字符串个数
#define PU_OSD_STRING_EX_NUM       10            //扩充后OSD字符串个数
#define PU_MAC_ADDR_LEN            30            //MAC地址长度
#define PU_SNAP_IMAGE_NAME_LEN     24            //抓拍图片文件名长度
#define PU_MAX_URL_LEN             512           //URL长度
#define PU_CONFIG_FILE_PATH_MAX    512           //配置文件最大路径
#define PU_CONFIG_LOAD_UP_KEY_LEN  (32 + 1)      //下载、上传配置文件使用的密钥长度(RSA加密后长度)
#define PU_SNAPSHOT_PIC_PATH_LEN   512           //抓拍图片最大路径
#define PU_DEVICE_USER_NUM_MAX     10            //设备最大支持10个用户
#define PU_CERT_FILE_PATH_MAX      512           //802.1x EAP-TLS证书文件最大路径

#define PU_TYPICAL_SCENE_NUM_MAX   12            //典型场景套餐个数
#define PU_TYPICAL_SCENE_NUM_MAX_EX   15         //典型场景套餐个数
#define PU_TYPICAL_SCENE_NAME_LEN  (64 + 4)      //典型场景名称长度
#define PU_TYPICAL_SCENE_DESCRIBE_LEN 128        //典型场景描述

#define PU_PLAN_NUM_MAX            8             //计划个数
#define PU_MONTH_NUM               12            //月份个数
#define FAC_NAME_LEN_MAX           12            //设备厂商名字长度
#define STREAM_PROFILES_MAX        8             //最大流套餐数
#define STREAMPROFILES_NAME_LEN    (64 + 4)      //流套餐名字长度
#define PRIVACY_AREA_POINTS_NUM    4             //隐私保护区域顶点数
#define VW_ZONE_ROW                15            //曝光权重区域行数
#define VW_ZONE_COLUMN             17            //曝光权重区域列数
#define ISP_PARA_NUM               22            //ISP参数个数
#define ETH_RECV_RATE_MAX          16000         //收包速率限制上限
#define ETH_RECV_RATE_MIN          2000          //收包速率限制下限
#define PU_ENC_STREAM_MAX_NUM      3             //一个通道最大码流数目
#define PU_ENC_STREAM_MAX_NUM_V2   5             //一个通道最大码流数目（三码流变五码流）
#define PU_FOCUSREGION_NUM_MAX     256           //自动聚焦区域数据长度
#define PU_FOCUSAREA_ROW           15            //自动聚焦区域数据长度一维
#define PU_FOCUSAREA_COL           17            //自动聚焦区域数据长度二维
#define VW_VIM_MAX_AREA_POINTS_NUM (10)          //聚集检测区域最大定点个数与commcenter.h中的VW_VIM_MAX_AREA_POINTS_NUM相对应
#define GATHER_AREA_NAME_LEN       (32)          //聚集检测名称长度
#define MAX_AREA_NUM               (4)           //最大区域数目，与commcenter.h中的MAX_AREA_NUM相对应

#define MAX_BURST_SHOOTING_NUM     5             //最大车牌抓拍数
#define MAX_LANE_NUM               (4)           //车道总数
#define TDOME_MAX_LANE_NUM         (6)           //交通球车道总数
#define MAX_AREA_VERTEX            (MAX_LANE_NUM+1) //车道结构体总数
#define MAX_PLATE_LOCAL_ZH_LEN     (24)          //默认省份字符长度

#define CAM_POSITION_STR_LEN       (15)          //地理位置

#define MAX_SUPPLEMENT_LIGHT_LAMP_NUM (8)        //补光灯个数
#define FD_AREA_NUM                (16)          //人脸检测区域个数
#define FD_AREA_POINT_NUM          (12)          //人脸检测区域最大顶点个数
#define FD_AREA_NAME_LEN           (36)          //人脸检测名称长度
#define PU_SNAPSHOT_INQUIRE_NUM    (10)          // 一次图片查询的最大图片数量
#define PU_SNAPSHOT_PICTURE_NAME_LEN (64)        // 抓拍图片名长度
#define PU_VLPR_PIC_OSD_TYPE_MAX    (15)         // OSD最大叠加类型
#define PU_VLPR_PIC_OSD_TYPE_MAX_EX (50)         // OSD最大叠加类型扩充，比智能多预留一些

#define PU_MEDIA_ENC_AES_KEY_STR_LEN (65)        //媒体流加密AES密钥长度
#define PU_MEDIA_ENC_AES_CBC_IV_LEN  (17)        //媒体流加密AES CBC模式IV长度

#define MAX_ITS_SNAPSHOT_INTERVAL (60000) // 最大抓拍间隔(ms)
#define MIN_ITS_SNAPSHOT_INTERVAL (67)    // 最小抓拍间隔(ms)

/********* SNMP *********/
#define PU_SNMPV3_USER_NUM         3
#define PU_SNMP_COMMUNITY_NUM      3
#define PU_SNMP_COMMUNITY_NAME_LEN (16+1)
#define PU_SNMP_COMMUNITY_NAME_LEN_EX (32+1)    
#define PU_SNMP_TRAP_NUM           3
#define PU_SNMP_ENGINEID_LEN       (32+1)
#define PU_SNMP_CONTEXT_NAME_LEN   (16+1)

//解码器宏定义
#define PU_ROI_AREA_NUM_MAX        8             //ROI区域最大数
#define PU_PORT_MODE_NUM_MAX       16            //最大端口模式
#define PU_BNC_PORT_MAX            32            //最大BNC输出端口
#define PU_VGA_PORT_MAX            8             //最大VGA输出端口
#define PU_DVI_PORT_MAX            8             //最大DVI输出端口
#define PU_HDMI_PORT_MAX           8             //最大HDMI输出端口

#define PU_DECODE_TYPE_MAX         4             //解码器支持的解码类型
#define PU_PORT_NUM_MAX            32            //最大端口数
#define PU_CHANNEL_NUM_MAX         32            //最大通道数

#define PU_OSD_MAX_LENGTH          (96 + 1)      //解码器OSD场名的长度
#define PU_OSD_MAX_LENGTH_EX       (176 + 1)     //OSD长度扩充

#define PU_CRYPTION_PASSWD_LEN     44            //密钥长度

#define PU_DEC_CHANNEL_NAME_LEN    32            //解码器通道名称长度
#define PU_DECODER_ID_LEN          20            //解码器ID
#define PU_DECODER_NAME_LEN        32            //解码器通道名称长度
#define PU_DEC_PAY_LOAD_TYPE_NUM   16            //PayLoadType的最大个数
#define PU_DECODER_ENCODING_LEN    16            //解码器编码格式最大长度
#define PU_CERT_FIELD_NAME_LEN_MAX (128+4)       //证书使用者各字段最大长度
#define PU_IP_FILTER_NUM_MAX       3             //IP地址过滤最大条目
#define PU_IP_FILTER_NUM_MAXV2     (48)          //IP地址过滤最大条目48个 对应IP_FILTER_NUM_MAX
#define PU_IP_FILTER_NUM_MAXV3     (100)          //IP地址过滤最大条目48个 对应IP_FILTER_NUM_MAX
#define PU_DDNS_MAX_LEN            256           //DDNS
#define OSDI_AREA_NUM_MAX          (8)           //OSDI区域最大数量

#define  PU_H264DEC_OK               0
#define  PU_H264DEC_NEED_MORE_BITS  -1
#define  PU_H264DEC_NO_PICTURE      -2
#define  PU_H264DEC_ERR_HANDLE      -3

/******* SMTP ********/
#define PU_SMTP_NAME_LEN_MAX (32 + 4)
#define PU_SMTP_MAIL_LEN 128
#define PU_SMTP_RECV_MAX_NUM 3

#define PU_IRCUT_MODE_MAX_NUM      3             //IRCUT模式最大值

#define PU_HUMANCOUNT_TABLE_LEN_MAX      32       //过线人数表最大长度

           
#define PU_MAX_CUSTOM_CONTENT_LEN (24)         //目录或者图片名称长度最大值
#define PU_MAX_DIR_NAMING_ELEM (4)             //微卡口款型FTP上传目录级别
#define PU_MAX_PIC_NAMING_ELEM (20)            //FTP上传图片个数最大值
#define PU_MAX_PIC_NAMING_ELEM_EX (90)         //FTP上传图片个数最大值扩充

#define PU_ITS_MAX_ROAD_NUM    (5)
#define PU_MAX_EXT_LAMP_NUM            (8)     //外置灯最大数量
#define PU_MAX_INNER_LAMP_NUM          (3)     // 内置灯最大数量

#define PU_LIC_SERVICE_AGE_MAX_LEN          256      //license服务年限长度
#define PU_LIC_REVOKE_KEY_LEN               136      //license 失效码长度
#define PU_LIC_DATE_MAX_LEN                 72       //license日期大长度
#define PU_3RD_APP_MAX_NUM                  16       //第三方算法APP最大数
#define PU_ITGT_TYPE_MAX_NUM                16       //智能算法种类最大数
#define PU_ITGT_TYPE_MAX_EX_NUM             64       //智能算法种类最大数
#define PU_ITGT_ALTHM_VERSION_LEN           48       //版本号长度
#define PU_ITGT_ALTHM_VENDOR_LEN            48       //算法厂家长度
#define PU_ISP_TYPE_MAX_NUM                 64       //图像算法种类最大数

#define PU_IMPORT_FILE_LEN_MAX        256      //上传人脸库文件路径长度
#define PU_IMPORT_FILENAME_LEN_MAX    128      //上传人脸库文件名最大长度

#define PU_SNAP_NUM_MAX	                3      //抓拍最大张数
#define PU_SNAP_NUM_MAX2                4      //抓拍最大张数

#define PU_RL_NUM_MAX 4                       //灯组个数最大值
#define PU_ITS_MAX_LIGHTAREA_NUM   4      //ITS红绿灯区域最大数量

#define PU_ITS_ILLEGAL_TYPE_NUM_MAX   (96)       //违法字典项数
#define PU_ITS_ILLEGAL_TYPE_LEN_MAX   (64 + 4)       //违法类型长度最大值
#define PU_ITS_ILLEGAL_NUM_LEN_MAX    (8 + 1)        //违法代码长度最大值
#define PU_ITS_ILLEGAL_NAME_LEN_MAX   (64 + 4)       //违法叠加名称长度最大值

#define PU_MIN_GPS_SYNC_INTERVAL = (5*60);
#define PU_MAX_GPS_SYNC_INTERVAL = (1000*60);

#define TD_MAX_SNAP_FRAME_NUM    (4)      //交通球机最大抓拍帧数
#define TD_MAX_SCENE_NUM         (16)     //交通球机最大场景数
#define TD_MAX_DAY_ONE_WEEK      (7)      //一周天数
#define TD_MAX_STRING_LENGTH     (64 + 1) //最大字符串长度

#define PU_CALIBRATION_POINT_MAX_NUM   14         //标定点最大数目
#define PU_MASTER_SLAVE_GROUP_MAX_NUM  4          //主从组合最大数目

#define PU_MASTER_NUM_MAX         (8)     //主设备最大个数
#define PU_SLAVE_NUM_MAX          (8)     //从设备最大个数
#define PU_1TN_SLAVE_NUM_MAX      (8)     //1拖N从机个数

/******* hot map ********/
#define PU_MONTH_NUM_PER_YEAR     (12)       //年报表热度图数据长度
#define PU_DAY_NUM_PER_MONTH      (31)       //月报表热度图数据长度
#define PU_DAY_NUM_PER_WEEK       (7)        //周报表热度图数据长度
#define PU_HOUR_NUM_PER_DAY       (24)       //日报表热度图数据长度 
#define PU_GUARD_PLAN_NUM_PER_DAY (8)        //每天布防计划个数
#define PU_HOTMAP_AREA_NUM        (8)        //最大区域数目

#define PU_ITGT_AUTOTRACKING_PRIORITY_ITEM_NUM (3) //机非人自动跟踪优先级Item数量

#define PU_MAX_RECORD_LEN_16 (16)              // 人员信息字符串16位 
#define PU_MAX_RECORD_LEN_32 (32)              // 人员信息字符串32位   
#define PU_MAX_RECORD_LEN_48 (48)              // 人员信息字符串48位   
#define PU_MAX_RECORD_LEN_64 (64)              // 人员信息字符串64位 
#define PU_MAX_EX_FIELD_LEN  (512)             //人脸信息扩展字段长度

#define PU_MAX_DELETE_NUM    (100)


/*********begin:尾号限行*********/
#define MAX_RESTRICTED_NUM           (10)   //限行尾号的总数
#define MAX_RESTRICTED_EVENT_NUM     (30)   //限行项总数
#define MAX_RESTRICTED_DATE_NUM      (10)   //尾号限行的使能数
#define MAX_RESTRICTED_LOCALPLATE_LEN     (5)    //尾号限行本地车牌
#define MAX_RESTRICTED_LOCALPLATE_NUM     (32)   //尾号限行本地车牌数量
#define MAX_RESTRICTED_LOCALPLATE_ALL_NUM (26)   //尾号限行本地车牌为全时，记为数量26
/************************** 宏定义结束   ***************************/


/********************************枚举类型**********************************************/
//全局错误码
typedef enum ERROR_CODE
{
    PU_ERROR_CODE_NOERROR = 0,                                      //没有错误

    PU_ERROR_CODE_COMMON_ERROR = 1,                                 //一般错误
    PU_ERROR_CODE_PASSWORD_ERROR = 2,                               //用户名或Pwd错误
    PU_ERROR_CODE_NO_PRIORITY = 3,                                  //没有操作权限
    PU_ERROR_CODE_NO_INIT = 4,                                      //SDK未初始化
    PU_ERROR_CODE_HAS_INIT = 5,                                     //SDK已初始化
    PU_ERROR_CODE_VERSION_NO_MATCH = 6,                             //SDK与设备版本不匹配
    PU_ERROR_CODE_STARTUP_NETWORK_ERROR = 7,                        //网络启动错误
    PU_ERROR_CODE_SOCKET_ERROR = 8,                                 //网络套接字错误
    PU_ERROR_CODE_CONNECT_ERROR = 9,                                //网络连接错误
    PU_ERROR_CODE_SEND_TIMEOUT = 10,                                //发送消息超时
    PU_ERROR_CODE_RECV_TIMEOUT = 11,                                //接收消息超时
    PU_ERROR_CODE_OPERATION_TIMEOUT = 12,                           //设备操作超时
    PU_ERROR_CODE_OUT_OF_MEMORY = 13,                               //内存不足，无法分配内存
    PU_ERROR_CODE_SERVER_IS_SHUTDOWN = 14,                          //服务端关闭连接
    PU_ERROR_CODE_TOO_MANY_REALPLAY = 15,                           //实况路数超过最大值
    PU_ERROR_CODE_LOG_ERROR = 16,                                   //日志出错
    PU_ERROR_CODE_NO_FREE_PORT = 17,                                //没有多余的端口资源
    PU_ERROR_CODE_HAS_REG_EVENT_CALLBACK = 18,                      //事件回调函数已注册
    PU_ERROR_CODE_REGISTER_FAIL = 19,                               //前端主动注册平台失败
    PU_ERROR_CODE_REGISTER_REDIRECT = 20,                           //前端主动注册平台重定向
    PU_ERROR_CODE_INPUT_NULL_PTR = 21,                              //输入参数为空指针
    PU_ERROR_CODE_OPR_LOCAL_FILE_FAIL = 22,                         //操作本地文件失败
    PU_ERROR_CODE_FILE_FORMAT_INVALID = 23,                         //文件格式错误
    PU_ERROR_CODE_VLPR_WATERMARK_INVALID = 24,                      //抓拍图片数字水印校验失败
	PU_ERROR_CODE_REST_PKG_TYPE_ERROR = 25,                         //REST协议报文格式错误

    //API调用错误
    PU_ERROR_CODE_SDKINIT_LINK_MODE_ERROR = 101,                    //SDK初始化连接模式出错
    PU_ERROR_CODE_SDKINIT_LOCALIP_ERROR = 102,                      //SDK初始化本地IP出错
    PU_ERROR_CODE_SDKLOGIN_PARA_ERROR = 103,                        //登录参数错误
    PU_ERROR_CODE_CODE_IS_INVALID = 104,                            //错误码无效
    PU_ERROR_CODE_SDKGETVERSION_PARA_ERROR = 105,                   //获取版本参数出错
    PU_ERROR_CODE_IDENTIFYID_ERROR = 106,                           //错误的用户ID号
    PU_ERROR_CODE_SDKGETDEVICE_PARA_ERROR = 107,                    //获取设备参数错误
    PU_ERROR_CODE_ALARMREPORT_CB_IS_NULL = 108,                     //告警上报回调函数为空
    PU_ERROR_CODE_VOICETB_CB_IS_NULL = 109,                         //语音对讲回调函数为空
    PU_ERROR_CODE_REALPLAY_CB_IS_NULL = 110,                        //实况播放回调函数为空
    PU_ERROR_CODE_LOAD_PLAYDLL_ERROR = 111,                         //加载播放库出错
    PU_ERROR_CODE_CFGFILE_ERROR = 112,                              //配置文件出错
    PU_ERROR_CODE_UNSUPPORT_ALARM_TYPE = 113,                       //未知告警类型
    PU_ERROR_CODE_SDKUPGRADE_PARA_ERROR = 114,                      //升级参数错误
    PU_ERROR_CODE_SDKUPGRADE_ERROR = 115,                           //升级错误
    PU_ERROR_CODE_SDKUPGRADE_FILE_ERROR = 116,                      //升级文件错误
    PU_ERROR_CODE_UNSUPPORT_PLATFORM_TYPE = 117,                    //未知平台类型
    PU_ERROR_CODE_SDKSETPLATFORM_PARA_ERROR = 118,                  //设置平台参数出错
    PU_ERROR_CODE_UNSUPPORT_ENCODE_TYPE = 119,                      //未知音视频编码类型
    PU_ERROR_CODE_UNSUPPORT_STREAM_TYPE = 120,                      //未知码流类型
    PU_ERROR_CODE_UNSUPPORT_BITRATE_TYPE = 121,                     //未知码率类型
    PU_ERROR_CODE_UNSUPPORT_PTZ_CMD = 122,                          //未知云台命令
    PU_ERROR_CODE_CRUISE_PARA_ERROR = 123,                          //巡航轨迹参数错误
    PU_ERROR_CODE_ALARM_TMP_PARA_ERROR = 124,                       //温度告警参数错误
    PU_ERROR_CODE_ALARM_MOTION_DETEC_PARA_ERROR = 125,              //移动侦测告警参数错误
    PU_ERROR_CODE_ALARM_INPUT_PARA_ERROR = 126,                     //输入告警参数错误
    PU_ERROR_CODE_ALARM_HIDE_PARA_ERROR = 127,                      //遮挡告警参数错误
    PU_ERROR_CODE_ALARM_INVADE_PARA_ERROR = 128,                    //入侵检测告警参数错误
    PU_ERROR_CODE_ALARM_COUNT_PARA_ERROR = 129,                     //目标计数告警参数错误
    PU_ERROR_CODE_ALARM_DISTURB_PARA_ERROR = 130,                   //干扰告警参数错误
    PU_ERROR_CODE_PRIVACY_PARA_ERROR = 131,                         //隐私保护参数错误
    PU_ERROR_CODE_OSD_PARA_ERROR = 132,                             //OSD参数错误
    PU_ERROR_CODE_PTZ_PARA_ERROR = 133,                             //云台控制参数错误
    PU_ERROR_CODE_SDKGUARD_PARA_ERROR = 134,                        //布撤防参数错误
    PU_ERROR_CODE_SDKGETALARAM_PARA_ERROR = 135,                    //获取告警参数错误
    PU_ERROR_CODE_PARA_ERROR = 136,                                 //参数出错
    PU_ERROR_CODE_PLAYER_FUNC_ERROR = 137,                          //播放库函数调用出错
    PU_ERROR_CODE_SDKSAVEREALDATA_ERROR = 138,                      //保存实况数据
    PU_ERROR_CODE_SDKGETGUARDSTATE_PARA_ERROR = 139,                //获取布防状态参数出错
    PU_ERROR_CODE_MUTUALLYEXCLUSIVE_RELATIONSHIP = 140,             //因互斥关系而导致不能设置成功
    PU_ERROR_CODE_DEVICE_RELOGIN = 141,                             //重复登录设备
    PU_ERROR_CODE_INVALID_CONFIG_FILE = 142,                        //配置文件不合法
    PU_ERROR_CODE_WRONG_RSP_TYPE = 143,                             //响应消息类型错误
    PU_ERROR_CODE_RSP_MEG_PARSE_ERROR = 144,                        //响应消息解析失败
    PU_ERROR_CODE_MISMATCH_PWD_COMPLEXITY = 145,                    //密码不符合密码复杂度要求
    PU_ERROR_CODE_ALARM_AUDIO_UP_PARA_ERROR = 146,                	//音频陡升告警参数错误
    PU_ERROR_CODE_ALARM_AUDIO_DOWN_PARA_ERROR = 147,                //音频陡降告警参数错误
    PU_ERROR_CODE_TRANSPARENT_CHANNEL_DATA_CB_IS_NULL = 148,        //透明通道数据回调函数为空
    PU_ERROR_CODE_NO_ENOUGH_CONTINUOUS_MEM = 149,                   //不存在足够的连续内存
    PU_ERROR_CODE_IRCMODE_PARA_ERROR = 150,                         //IRCUT模式类型错误
    PU_ERROR_CODE_CERT_PARA_ERROR = 151,                            //证书路径错误
    PU_ERROR_CODE_IMPORT_FACELIBRARY_ERROR = 152,                   //人脸库导入错误
    PU_ERROR_CODE_IMPORTING_FACELIB_ERROR = 153,                    //人脸库正在导入
    PU_ERROR_CODE_UNKNOWN_SV_TYPE = 154,                            //未知的业务类型
    PU_ERROR_CODE_NOT_OPEN_TLS = 155,                               //未开启TLS，不能操作人脸库相关
    PU_ERROR_INVALID_UPDATEFILE_NUM = 156,                        //升级文件数量超出限制
    PU_ERROR_USER_CANCEL_UPGRADE = 157,                           //用户取消升级
	PU_ERROR_NOT_ENOUGH_MEMORY_ALLOCATED = 160,                   //输入接收缓存过小，无法加载JSON数据
    //解码器错误码
    PU_ERROR_CODE_DEC_INITDEC_ERROR = 1001,                         //初始化解码失败
    PU_ERROR_CODE_DEC_STARTDEC_ERROR = 1002,                        //开始解码失败
    PU_ERROR_CODE_DEC_STOPDEC_ERROR = 1003,                         //停止解码失败
    PU_ERROR_CODE_DEC_TOO_MANY_CHANNEL = 1004,                      //太多的解码通道
    PU_ERROR_CODE_DEC_ERROR_PORT_NUM = 1005,                        //端口数错误
    PU_ERROR_CODE_DEC_ERROR_DEC_HANDEL = 1006,                      //错误的解码句柄
    PU_ERROR_CODE_DEC_ERROR_UNSUPPORT_DECODE_TYPE = 1007,           //不支持的解码类型
    PU_ERROR_CODE_DEC_ERROR_INVALID_CHANNEL_ID = 1008,              //无效的通道号

    //服务端错误码
    PU_ERROR_CODE_SERVER_COMMON_ERROR = 10001,                      //一般错误
    PU_ERROR_CODE_SYNTAX_ERROR = 10002,                             //配置语法错误
    PU_ERROR_CODE_UNSUPPORT_ERROR = 10003,                          //不支持的请求
    PU_ERROR_CODE_PARAMETER_ERROR = 10004,                          //参数错误
    PU_ERROR_CODE_INVALID_VCU_ID = 10005,                           //设备ID错误
    PU_ERROR_CODE_INVALID_CHANNEL = 10006,                          //通道号错误
    PU_ERROR_CODE_INVALID_SERIAL_NO = 10007,                        //串口号错误
    PU_ERROR_CODE_INVALID_ALARM_NO = 10008,                         //报警端口错误
    PU_ERROR_CODE_UNSUPPORTED_MEDIA_TYPE = 10009,                   //不支持的媒体类型
    PU_ERROR_CODE_PARTLY_SUPPORT = 10011,                           //仅部分参数配置成功
    PU_ERROR_CODE_TOO_MANY_PLANS = 10012,                           //计划条数超过限制
    PU_ERROR_CODE_NO_DISK = 10013,                                  //设备无硬盘
    PU_ERROR_CODE_OPEN_SOUND_FAIL = 10014,                          //打开声音失败
    PU_ERROR_CODE_VOICE_OPEND = 10015,                              //服务器语音对讲被占用
    PU_ERROR_CODE_DEVICE_BUSY = 10016,                              //设备忙
    PU_ERROR_CODE_OPERATE_FLASH_ERROR = 10019,                      //FLASH出错 
    PU_ERROR_CODE_UNSUPPORTED_VIDEO_FORMAT = 10020,                 //不支持的视频制式
    PU_ERROR_CODE_IP_ADDRESS_CONFLICT = 10022,                      //IP地址冲突
    PU_ERROR_CODE_LTE_DHCP_CONFLICT = 10023,                        //设置LTH和DHCP冲突
    PU_ERROR_CODE_SIP_STACK_ERROR = 10024,                          //SIP协议栈错误

    PU_ERROR_CODE_NULL_ELEMENT = 10101,                             //XML文件没有相应节点
    PU_ERROR_CODE_INVALID_VERIFICATION = 10102,                     //错误的用户名或Pwd
    PU_ERROR_CODE_INVALID_VERSION_FILE = 10103,                     //VERSION文件校验失败
    PU_ERROR_CODE_INVALID_KERNEL_FILE = 10104,                      //内核升级文件校验失败
    PU_ERROR_CODE_INVALID_ROOTFS_FILE = 10105,                      //文件系统升级文件校验失败
    PU_ERROR_CODE_FIRST_LOGIN = 10106,                              //第一次登录
    PU_ERROR_CODE_CLIENT_ALREADY_LOGIN = 10107,                     //已有客户端登录
    PU_ERROR_CODE_USER_LOCKED = 10108,                              //用户被锁定
    PU_ERROR_CODE_MANY_USER = 10109,                                //用户个数超过限制
    PU_ERROR_CODE_USER_NAME_CONFLICT = 10110,                       //用户名冲突
    PU_ERROR_CODE_NO_USER_NAME = 10111,                             //没有该用户
    PU_ERROR_CODE_USER_NOPOWER = 10112,                             //当前用户没该权限
    PU_ERROR_CODE_NOT_NEED_UPDATE = 10113,                          //版本号一致，不需要升级
    PU_ERROR_CODE_NOT_SUPPORT_ABILITY = 10114,                      //不支持的能力参数
    PU_ERROR_CODE_PRESET_IN_GUARD_POSITION = 10115,                 //预置位在看守位中
    PU_ERROR_CODE_PRESET_IN_CRUISE_TRACK = 10116,                   //预置位在巡航轨迹中
    PU_ERROR_CODE_SET_ETHPHY_OUTPUT_TYPE_ERROR = 10117,             //设置网口类型失败
    PU_ERROR_CODE_SET_ETHMODE_ERROR = 10118,                        //设置网口速率失败
    PU_ERROR_CODE_UPLOAD_CONFIG_TYPE_ERROR = 10119,                 //上传配置文件类型错误
    PU_ERROR_CODE_DNS_SERVER_UNREACH = 10120,                       //DNS服务器不可达
    PU_ERROR_CODE_DNS_SERVER_NO_DOMAIN = 10121,                     //DNS服务器获取域名失败
    PU_ERROR_CODE_THE_CRUISE_IS_RUNNING = 10122,                    //巡航轨迹正在运行
    PU_ERROR_CODE_SD_FORMATTING = 10124,                            //SD卡正在格式化
    PU_ERROR_CODE_UPDATE = 10125,                                   //系统正在升级
    PU_ERROR_CODE_REBOOT = 10126,                                   //系统正在重启
    PU_ERROR_CODE_RESTORE = 10127,                                  //正在恢复默认配置
    PU_ERROR_CODE_RECOVER_OPRATE_FORBIDDEN = 10128,                 //恢复默认配置禁止配置等操作
    PU_ERROR_CODE_ROI_ERROR_BY_MJPEG = 10129,                       //MJPEG下设置ROI 失败
    PU_ERROR_CODE_ROI_ERROR_BY_NOSUBSTREAM = 10130,                 //只有主码流，设置子码流ROI失败
    PU_ERROR_CODE_TZ_ERROR_BY_CONFLICT = 10131,                     //设置绊线检测使能有冲突
    PU_ERROR_CODE_OC_ERROR_BY_CONFLICT = 10132,                     //设置目标计数使能有冲突
    PU_ERROR_CODE_MD_ERROR_BY_CONFLICT = 10133,                     //设置移动侦测使能有冲突
    PU_ERROR_CODE_TW_ERROR_BY_CONFLICT = 10134,                     //设置绊线检测使能有冲突
    PU_ERROR_CODE_AREA_ERROR_BY_CONFLICT = 10135,                   //设置区域检(周界入侵、物品遗留、物品移走）测使能有冲突
    PU_ERROR_CODE_VD_ERROR_BY_CONFLICT = 10136,                     //设置视频干扰使能有冲突
    PU_ERROR_CODE_IGT_ENABLE_CONFLICT = 10137,                      //智能开关已打开  设置照度增强失败,设置遮挡失败
    PU_ERROR_CODE_ILLUMINATION_ENABLE_CONFLICT = 10138,             //照度开关已使能  设置智能开关失败，设置遮挡失败
    PU_ERROR_CODE_VIDEOBLOCK_ENABLE_CONFLICT = 10139,               //视频遮挡已使能，设置智能开关、找到增强失败
    PU_ERROR_CODE_IGT_FAIL_BY_SWITCHOFF = 10140,                    //智能开关未使能，设置智能业务失败
    PU_ERROR_CODE_TW_ERROR_BY_OVER_NUM = 10141,                     //设置绊线条数超过最大数
    PU_ERROR_CODE_AREA_ERROR_BY_OVER_NUM = 10142,                   //设置区域个数超过最大数4
    PU_ERROR_CODE_AREA_ERROR_BY_OVER_TOTAL_NUM = 10143,             //设置区域个数超过最大总数10
    PU_ERROR_CODE_AREA_ERROR_BY_ZERO_NUM = 10144,                   //设置区域个数为0
    PU_ERROR_CODE_AREA_POINT_ERROR_BY_OVER_NUM = 10145,             //设置区域顶点数超过最大数
    PU_ERROR_CODE_AREA_ABN_ERROR_BY_CONFLICT = 10146,               //设置区域检物品移走，遗留使能已开启有冲突
    PU_ERROR_CODE_AREA_RMV_ERROR_BY_CONFLICT = 10147,               //设置区域检物品遗留，移走使能已开启有冲突
    PU_ERROR_CODE_VIM_GLOBAL_PARA_ERROR = 10148,                    //设置智能分析算法全局参数失败
    PU_ERROR_CODE_AREA_NOTSURPORT_ERROR = 10149,                    //设置智能分析区域无效
    PU_ERROR_CODE_PRIVACY_MASK_AREA_BEYOND = 10150,                 //隐私保护区域超出总面积
    PU_ERROR_CODE_MEDIA_ADAPT_BW_MUTEX = 10151,                     //带宽自适应与编码类型或者码率类型冲突
    PU_ERROR_CODE_IP_FILTER_RULE_SAME = 10152,                      //存在相同的IP过滤规则
    PU_ERROR_CODE_WD_FRAME_CONFLICT = 10153,                        //宽动态手动或自动，采集帧不能设置50、60
    PU_ERROR_CODE_FRAME_WD_CONFLICT = 10154,                        //采集帧为50、60，宽动态不能设置手动或自动
    PU_ERROR_CODE_CONFLICT_VIDEOBLOCK_OR_IGT_IS_ENABLE = 10155,     //视频遮挡或行为分析已使能,设置照度增强失败
    PU_ERROR_CODE_BUSY_CURISE = 10156,                              //正在巡航，无法设置巡航轨迹参数
    PU_ERROR_CODE_DEVICE_CLOSE = 10157,                             //设备未开启
    PU_ERROR_CODE_BUSY_PRESET = 10158,                              //预置位被使用，无法删除
    PU_ERROR_CODE_INVALID_IGT_AREA_ID = 10159,                      //智能分析区域不存在
    PU_ERROR_CODE_INVALID_IGT_LINE_ID = 10160,                      //智能分析线条不存在
    PU_ERROR_CODE_INVALID_PRIVACY_ID = 10161,                       //隐私保护区域不存在
    PU_ERROR_CODE_IN_USER_DEFINE_SCAN = 10162,                      //正在花样扫描录制（很多功能不能用）
    PU_ERROR_CODE_SET_DRC_BACKLIGHT_CONFLICT = 10163,               //背光补偿使能与DRC使能冲突
    PU_ERROR_CODE_CURISE_IN_GUARD_POSITION = 10164,                 //巡航轨迹在看守位中
    PU_ERROR_CODE_DISK_ABNORMAL = 10165,                            //SD卡异常
	PU_ERROR_CODE_PRIVACYMASK_REGION_INTERSECT = 10166,             //隐私保护区域重叠
	PU_ERROR_CODE_INVALID_SAMEPASSWD = 10167,                       //修改Pwd与原Pwd相同
	PU_ERROR_CODE_NOT_SUPPORTED_UPDATE = 10168,                     //升级文件版本过低，请选择高版本升级
	PU_ERROR_CODE_MANY_RECORD_FILES = 10169,                        //录像文件过多

    PU_ERROR_CODE_CONFLICT_WITH_MOSAIC = 10170,                     //操作与马赛克冲突
    PU_ERROR_CODE_CONFLICT_WITH_OSD = 10171,                        //操作与OSD冲突
    PU_ERROR_CODE_CONFLICT_WITH_PIC = 10172,                        //操作与图片叠加冲突
    PU_ERROR_CODE_VIDEO_ENC_CLOSE = 10173,                          //视频编码器未打开
    PU_ERROR_CODE_ISP_PARA_CONFLICT = 10174,                        //ISP参数冲突
    PU_ERROR_CODE_WB_HIGH_TEMP_LOWER = 10175,                       //白平衡自动追踪模式下色温下限大于等于色温上限
    PU_ERROR_CODE_MJPEG_UNSUPPORT_WATERMARK = 10176,                //MJPEG不支持数字水印功能
    PU_ERROR_CODE_ISP_CONFLICT_WITH_FRAMERATE = 10177,              //宽动态/背光补偿与全帧率互斥    
    PU_ERROR_CODE_FRAMERATE_CONFLICT_WITH_ISP = 10178,              //全帧率与宽动态/背光补偿互斥
    PU_ERROR_CODE_OSD_STRING_LEN_ERR = 10179,                       //OSD字符长度错误
    PU_ERROR_CODE_DISK_MOUNT_ERROR = 10183,                         //磁盘未挂载
    PU_ERROR_CODE_IMPORTING_FACE_LIB = 10184,                       //正在导入人脸库，稍后
    PU_ERROR_CODE_ADDING_ONE_FACE = 10185,                          //正在添加人脸，稍后
        
    PU_ERROR_CODE_AUDIO_DETECT_MIC_NOT_SUPPORT = 10200,             //音频输入为mic in模式下不支持音频异常检测
	PU_ERROR_CODE_CIF_CONFLICT = 10202,                             //因与走廊互斥，CIF不可设
    PU_ERROR_CODE_CORRIDOR_CONFLICT = 10203,                        //因与CIF互斥，走廊不可设

	PU_RESULT_ERR_POINT_OUTOF_RANGE = 10211,
	PU_RESULT_ERR_LINE_BECOME_POINT = 10212,    
	PU_RESULT_ERR_LINE_CROSS = 10213,
    
    PU_ERROR_ISP_AE_MANUAL_CONFLICT_WD = 10214,        //手动曝光与宽动态互斥
    PU_ERROR_ISP_AE_MANUAL_CONFLICT_FLICKER,   //手动曝光与背景频率互斥
    PU_ERROR_ISP_AE_MANUAL_CONFLICT_HLC,       //手动曝光与强光抑制
    PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_WD,       //手动曝光与宽动态互斥
    PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_FLICKER, //曝光模式快门优先与背景频率互斥
    PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_HLC, //曝光模式快门优先与强光抑制
    PU_ERROR_ISP_BACKLIGHT_CONFLICT_WD,   //背光补偿与宽动态互斥
    PU_ERROR_ISP_BACKLIGHT_CONFLICT_HLC,  //背光补偿与强光抑制互斥
    PU_ERROR_ISP_WD_CONFLICT_HLC, //宽动态与强光抑制互斥
    PU_ERROR_ISP_DEFOG_CONFLICT_WD,   //透雾模式与宽动态互斥
    PU_ERROR_ISP_HLC_CONFLICT_FRAMERATE,  //强光抑制与50帧60帧互斥
    PU_ERROR_ISP_WD_CONFLICT_FRAMERATE,   //宽动态与50帧60帧互斥
    PU_ERROR_ISP_AE_MANUAL_CONFLICT_BACKLIGHT,    //手动曝光与背光补偿
    PU_ERROR_ISP_HLC_CONFLICT_SLOW_SHUTTER,   //强光抑制与慢快门互斥
    PU_ERROR_ISP_WD_CONFLICT_SLOW_SHUTTER,    //宽动态与慢快门互斥    
    
    PU_ERROR_CODE_DOWNLOAD_FILE_ERROR = 10300,                      //文件下载失败
    PU_ERROR_CODE_CONNECTION_SERVER_INTERRUPTED = 10301,            //连接服务器中断
    PU_ERROR_CODE_REQUEST_OVERTIME = 10302,                         //请求超时
    PU_ERROR_CODE_CONNECTION_SERVER_FAIL = 10303,                   //连接服务器失败
    PU_ERROR_CODE_CONNECTION_NOT_FOUND = 10304,                     //连接未找到
    PU_ERROR_CODE_RECONNECTING_TO_SERVER = 10305,                   //正在重新连接服务器
    PU_ERROR_CODE_FILE_NOT_EXIST = 10306,                           //文件不存在

    PU_ERROR_CODE_INVALID_UPDATEFILE = 10310,                       //升级文件非法
    PU_ERROR_CODE_UPDATEFILE_BAD = 10311,                           //文件损坏
    PU_ERROR_CODE_INVALID_FILE_FORMAT = 10312,                      //文件格式错误

    PU_ERROR_CODE_UPGRADE_TYPE_ERR    = 10350,                      // 升级文件类型与请求类型不符
    PU_ERROR_CODE_UPGRADE_PARAM_NULL  = 10351,                      // 升级参数为空
    PU_ERROR_CODE_UPGRADE_NOT_UPLOAD  = 10352,                      //升级文件未上传
    PU_ERROR_CODE_UPGRADE_VERIFY_FAIL = 10353,                      //升级文件完整性校验失败
    PU_ERROR_CODE_UPGRADE_SIGN_FAIL   = 10354,                      //升级文件数字签名验证失败
    PU_ERROR_CODE_UPGRADE_SPACE_FULL  = 10355,                      //升级存储空间满
    PU_ERROR_CODE_UPGRADE_DEVICE_FAIL = 10356,                      //设备支持列表适配失败

	PU_ERROR_RESULT_ALG_VER_ERR_U = 10357,                         //算法包版本错误(算法需要和软件包VRC版本一致)
	PU_ERROR_RESULT_ALG_VER_NEED_UPGRADE_U = 10358,                //版本包升级后提示需要升级算法包

    PU_ERROR_SD_NOT_FORMAT = 10601,                                 //SD卡未格式化
	PU_ERROR_CODE_CUSTOM_PACKAGE_UNDEFINED = 10602,					//自定义套餐未定义
	PU_ERROR_CODE_PTZ_BUSY = 10603,                                 //云台未停止

	PU_ERROR_CODE_OSDI_AREA_NOT_EXIST = 10700,						// 区域不存在，索引值错误
	PU_ERROR_CODE_OSDI_AREA_TOO_LARGE = 10701,						// 区域水平宽度超过180度
	PU_ERROR_CODE_OSDI_AREA_INVALID_VERDEGREE = 10702,			    // 区域坐标点不符合左下右上规则
	PU_ERROR_CODE_OSDI_INDEX_AlREADY_EXIST = 10705,                 // 新增区域索引号非法，索引已存在
	PU_ERROR_CODE_OSDI_HOR_OR_VER_EQUAL = 10708,                    // 区域坐标点水平或垂直坐标相等
	PU_ERROR_CODE_OSDI_INDEX_INVALID = 10709,                       // 区域索引号非法，小于1
	PU_ERROR_CODE_OSDI_INDEX_EQUAL = 10710,                         // 区域索引号重复

    PU_ERROR_CODE_DST_ALREADY_OPEN = 10800,                         // 夏令时已经打开

    PU_STABILIZER_CONFLICT_AREA_CROP = 10900,                       // 电子防抖开启失败，与区域裁剪互斥
    PU_AREA_CROP_CONFLICT_STABILIZER = 10901,                       // 区域裁剪开启失败，与电子防抖互斥

    PU_ERROR_CODE_ITGT_IMRS_ERR_POINT_NULL = 10950,                 // 指针为空
    PU_ERROR_CODE_ITGT_IMRS_ERR_READ_FILE = 10951,                  // 读取文件失败
    PU_ERROR_CODE_ITGT_IMRS_ERR_XML_PARSER = 10952,                 // xml解析
    PU_ERROR_CODE_ITGT_IMRS_ERR_IMG_TPYE = 10953,                   // 图像类型
    PU_ERROR_CODE_ITGT_IMRS_ERR_RESOLUTION_DIFF = 10954,            // 分辨率与初始不同
    PU_ERROR_CODE_ITGT_IMRS_ERR_VERTEX_ILLEGAL = 10955,             // 点坐标不合理
    PU_ERROR_CODE_ITGT_IMRS_ERR_RESOLUTION_UNSUPPORT = 10956,       // 分辨率不支持
    PU_ERROR_CODE_ITGT_IMRS_ERR_PARAM_ERR = 10957,					//参数错误
    PU_ERROR_CODE_ITGT_IMRS_ERR_MALLOC_FAILED = 10958,              // 内存分配失败
    // 控制错误
    PU_ERROR_CODE_ITGT_IMRS_ERR_NOT_CONFIG = 10961,                 //配置错误
    PU_ERROR_CODE_ITGT_IMRS_ERR_PARAM_SET = 10962,                  //参数设置错误
    //车道线错误
    PU_ERROR_CODE_ITGT_IMRS_ERR_LANE_OVERLAP = 10963,               //车道线错误
	PU_ERROR_RESULT_VLPR_ERR_LINE_OUTOF_RANGE = 10964,              //设置失败，检测线不在车道线范围内

    PU_ERROR_CODE_SHORT_KEY = 11001,                                //证书密钥过短
    PU_ERROR_CODE_WEAK_CERT = 11002,                                //证书密钥过弱
    PU_ERROR_CODE_GET_TEMPERTURE_VW_RET_FAIL = 11024,               //调动 VM 接口失败，如调用驱动获取温度

	PU_RESULT_ITS_ERR_INVALID_LANE_TYPE = 11100,		            //车道线类型超出范围
    PU_RESULT_ITS_ERR_INVALID_LANE_NUM,							//车道个数不在有效范围内
    PU_RESULT_ITS_ERR_INVALID_LANE_DIR,							//车道方向无效
    PU_RESULT_ITS_ERR_INVALID_LANE_DRV_DIR,						//车道行驶方向无效
    PU_RESULT_ITS_ERR_INVALID_LANE_PURPOSE,						//车道用途无效
    PU_RESULT_ITS_ERR_INVALID_LANE_ATTR,							//车道属性无效
    PU_RESULT_ITS_ERR_INVALID_CAR_DRV_DIR,							//行驶方向无效
    PU_RESULT_ITS_ERR_INVALID_SIGN_DIR,							//指示方向无效
    PU_RESULT_ITS_ERR_INVALID_NORMAL_SIGN_SPEED,					//小车标志速度无效
    PU_RESULT_ITS_ERR_INVALID_NORMAL_LOW_SPEED,					//小车限制低速无效
    PU_RESULT_ITS_ERR_INVALID_NORMAL_HIGH_SPEED,					//小车限制高速无效
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SIGN_SPEED,				//大车标志速度无效
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_LOW_SPEED,				//大车限制低速无效
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_HIGH_SPEED,				//大车限制高速无效
    PU_RESULT_ITS_ERR_INVALID_EXTERN_LAMP_BITMAP,					//外置灯关联无效
  
    PU_RESULT_ITS_ERR_INVALID_SNAP_INTERVAL,						//抓拍间隔不在有效范围内
    PU_RESULT_ITS_ERR_INVALID_DT_TYPE,								//检测方式不在有效范围内
    PU_RESULT_ITS_ERR_INVALID_REGULATION_NUM,						//违章数目超出限制
    PU_RESULT_ITS_ERR_INVALID_REGULATION_TYPE,						//违章类型无效
    PU_RESULT_ITS_ERR_INVALID_SNAP_NUM,							//违章抓拍张数不在有效范围内
    PU_RESULT_ITS_ERR_INVALID_RUNNINGRED_PRIORITY,					//闯红灯优先级无效
    PU_RESULT_ITS_ERR_INVALID_OVER_LANE_SENSITIVITY,				//压车道线灵敏度无效
    PU_RESULT_ITS_ERR_INVALID_VINBIKELANE_STAYTIME,				//机占非停留时间无效
    PU_RESULT_ITS_ERR_INVALID_OVER_BUSLANE_STAYTIME,				//占用公交车道时间无效
    PU_RESULT_ITS_ERR_INVALID_PARKINGTIME,							//黄网格线停留时间无效
    PU_RESULT_ITS_ERR_INVALID_LIGHT_DT_TYPE,						//信号灯接入方式不在有效范围内
    PU_RESULT_ITS_ERR_INVALID_LIGHT_AREA_NUM,						//信号灯区域数目无效
    PU_RESULT_ITS_ERR_INVALID_LIGHT_NUM,							//信号灯个数无效
    PU_RESULT_ITS_ERR_INVALID_LIGHT_ARRANGE_TYPE,					//信号灯方向无效
    PU_RESULT_ITS_ERR_INVALID_YELLOW_TIME,							//黄灯持续时间无效	
    PU_RESULT_ITS_ERR_INVALID_LIGHT_AREA,							//信号灯区域无效
    PU_RESULT_ITS_ERR_LINE_OUTOF_RANGE,							//检测线、停止线不在车道线或右边界线有效范围内
    PU_RESULT_ITS_ERR_INVALID_NORMAL_SPEED_RANGE_CONFIG,          //若小车限制低速大于限制高速 ,返回错误 
    PU_RESULT_ITS_ERR_INVALID_NORMAL_SIGN_SPEED_CONFIG,             //小车标志速度不在低高速内 ,返回错误
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SPEED_RANGE_CONFIG,    //若大车低速大于高速, 返回错误
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SIGN_SPEED_CONFIG,      //若大车标志速度不在低高速内, 返回错误
    PU_RESULT_ITS_ERR_INVALID_RETURNDATA,
    PU_RESULT_ITS_ERR_INVALID_CONGESTION_THRESHOLD,
	PU_RESULT_ITS_ERR_INVALID_SNAP_INTERVAL_TYPE,               //抓拍间隔类型无效
	PU_RESULT_ITS_ERR_INVALID_ADAPT_SNAP_LOWSPEED,              //自适应抓拍间隔低速最大值无效
	PU_RESULT_ITS_ERR_INVALID_ADAPT_SNAP_MIDSPEED,              //自适应抓拍间隔中速最大值无效
	PU_RESULT_ITS_ERR_INVALID_ADAPT_LOWSPEED_INTERVAL,          //自适应低速抓拍间隔无效
	PU_RESULT_ITS_ERR_INVALID_ADAPT_MIDSPEED_INTERVAL,          //自适应中速抓拍间隔无效
	PU_RESULT_ITS_ERR_INVALID_ADAPT_HISPEED_INTERVAL,           //自适应高速抓拍间隔无效
	PU_RESULT_ITS_ERR_INVALID_LANE_ORDER,                       //设置失败，车道线、车道右边线请由左往右按序绘制


    // 算法 互斥错误码
    PU_RESULT_TGT_FUNCTION_MUTUAL_LRPR = 12000,                     //车牌设置失败，和人脸或者行为分析或者停车侦测冲突
    PU_RESULT_TGT_FUNCTION_MUTUAL_FD,                               //人脸设置失败，和车牌或者停车侦测冲突
    PU_RESULT_TGT_FUNCTION_MUTUAL_CD,                               //停车侦测设置失败，和人脸或者车牌或者行为分析冲突
    PU_RESULT_TGT_FUNCTION_MUTUAL_VA,                               //行为分析设置失败，和车牌或者行为分析冲突     
    PU_RESULT_TGT_FUNCTION_MUTUAL_HC,                               //人头计数设置失败，和车牌、人脸、停车、自动跟踪冲突
    PU_RESULT_TGT_FUNCTION_MUTUAL_AT,                               //自动跟踪设置失败，和车牌、人脸、停车、人头计数冲?
    PU_RESULT_TGT_FUNCTION_MUTUAL_VHD,                            //请先关闭机非人检测功能
    PU_RESULT_TGT_FUNCTION_MUTUAL_ITS,                             //请先关闭智能交通功能
    PU_RESULT_TGT_FUNCTION_MUTUAL_QD,                              //请先关闭排队检测功能
    PU_RESULT_TGT_FUNCTION_MUTUAL_CDD,                            //请先关闭人群密度功能
    PU_RESULT_TGT_FUNCTION_MUTUAL_IBALL,                         //请先关闭智能交通-违章球功能
    PU_RESULT_TGT_FUNCTION_MUTUAL_VHDFACE, 	                     //请先关闭一机多用功能
    PU_RESULT_ITGT_MODE_NOTSUPPORT_ALG,                          // 当前模式下不支持该算法
	PU_RESULT_TGT_VHD_DETECTION_ERR_WRONG_VIDEO_MODE,           //机非人不支持走廊模式，先关闭走廊模式
	PU_RESULT_TGT_FUNCTION_MUTUAL_BEH,                          // 请先关闭增强模式行为分析功能
	PU_RESULT_TGT_FUNCTION_MUTUAL_CAMPUS_TRAFFICEVENT,          // 请先关闭出入口业务
	PU_RESULT_TGT_FUNCTION_MUTUAL_CAMPUS_ALG_TYPE,				// 出入口业务功能只支持国内车牌算法，不支持海外车牌算法
	PU_RESULT_TGT_FUNCTION_MUTUAL_MD,							//请先关闭移动侦测功能
	PU_RESULT_TGT_FUNCTION_MUTUAL_OD,							//请先关闭遮挡告警功能
	PU_RESULT_TGT_FUNCTION_MUTUAL_SC,							//请先关闭场景变更功能
	PU_RESULT_TGT_FUNCTION_MUTUAL_OOD,							//请先关闭虚焦检测功能
	PU_RESULT_TGT_FUNCTION_MUTUAL_CA,							//请先关闭人员聚集功能
	PU_RESULT_TGT_FUNCTION_MUTUAL_HM,							//请先关闭热度图功能
	PU_RESULT_TGT_FUNCTION_MUTUAL_TRAFFICEVENT_CAMPUS,          // 请先关闭全部车辆事件业务
	PU_RESULT_TGT_FUNCTION_MUTUAL_TRAFFIC_STATISTIC_CAMPUS,    // 请先关闭交通流量统计业务
    
    //人脸及人脸库相关错误码
    PU_RESULT_ITGT_ERR_FACE_SUCCESS = 12100,               // 人脸导库成功
    PU_RESULT_ITGT_ERR_FACEREC_DISABLE,                    // 人脸识别未使能
    PU_RESULT_ITGT_ERR_DATA_UPDATE,                        // 数据更新失败
    PU_RESULT_ITGT_ERR_OPREATION_NOTSUPPORT,               // 操作不支持
    PU_RESULT_ITGT_ERR_OPREATION_UNFINISHED,               // 批量导库操作未完成
    PU_RESULT_ITGT_ERR_FACELIB_OVERSIZE,                   // 底库个数超出上限
    PU_RESULT_ITGT_ERR_FACENUM_OVERSIZE,                   // 人脸个数超出上限
    PU_RESULT_ITGT_ERR_DB_ERROR,                           // 数据库操作失败
    PU_RESULT_ITGT_ERR_FACELIST_REPAT,                     // 人脸库重复
    PU_RESULT_ITGT_ERR_FACEPIC_OVERSIZE,                   // 图片宽高超范围
    PU_RESULT_ITGT_ERR_FACE_DECODE,                        // 图片解码失败
    PU_RESULT_ITGT_ERR_FACE_DETECTION,                     // 人脸检测失败
    PU_RESULT_ITGT_ERR_FACE_FEATURE,                       // 人脸特征提取失败
    PU_RESULT_ITGT_ERR_FACE_DAO,                           // 人脸持久化数据库失败  
    PU_RESULT_ITGT_ERR_FACE_FILE,                          // 人脸持写文件失败
    PU_RESULT_ITGT_ERR_FACE_ALGDISABLE,                    // 人脸算法未开启
    PU_RESULT_ITGT_ERR_FACE_NOFEATURE,                     // 人脸底库无特征
    PU_RESULT_ITGT_ERR_FACE_UZIP,                          // zip包解压失败
    PU_RESULT_ITGT_ERR_FACE_CSV,                           // csv文件解析失败
    PU_RESULT_ITGT_ERR_FACE_ENCRYPT,                       // face加解密失败
    PU_RESULT_ITGT_ERR_FACE_TASKUNKNOW,                    // 任务未处理
	PU_RESULT_ITGT_ERR_FEATURE_EXTRACT_SUCCESS,            // 特征提取成功
	PU_RESULT_ITGT_ERR_FEATURE_EXTRACTED,                  // 特征已提取
	PU_RESULT_ITGT_ERR_FACEREC_ENABLE_FAIL,                // 人脸识别使能失败，针对算法包不存在或版本不匹配的情况
	PU_RESULT_ITGT_ERR_FACE_FEATURE_LOAD_PROCESSING,       // 人脸识别存在历史布控，系统启动时需要加载特征
	PU_RESULT_ITGT_ERR_FACE_FEATURE_PAC_IMPORT_PROCESSING, // 人脸导库正在导入特征包
	PU_RESULT_ITGT_ERR_FACE_PIC_PAC_IMPORT_PROCESSING,     // 人脸导库正在图片包导入
	PU_RESULT_ITGT_ERR_FACE_FEATURE_GET_PROCESSING,        // 人脸导库正在特征导出
	PU_RESULT_ITGT_ERR_FACE_FEATURE_EXTRACT_PROCESSING,    // 人脸导库正在特征提取
    
    //停车侦测错误码
    PU_RESULT_TGT_CAR_DATECTION_ERR_WRONG_VIDEO_MODE=12200,     //停车检测打开时走廊模式和镜像模式必须关闭
    PU_RESULT_ITGT_VHD_ERR_WRONG_VIDEO_MODE,                    //机非人打开时走廊模式必须关闭
    PU_RESULT_ITGT_VLPR_ERR_WRONG_VIDEO_MODE,                   //车辆识别打开时走廊模式必须关闭
    PU_RESULT_ITGT_NOT_FACE_DETETION_MODE_ERR_WRONG_VIDEO_MODE, //-H款型非人卡模式时走廊模式必须关闭(混行、微卡、行为分析不支持)
    
    PU_RESULT_LIC_INVALID = 12300,                          //license非法，获取license内容失败
    PU_RESULT_LIC_REPEATED_ESN_VER_MISMATCH,               //不允许重复加载 ESN 或版本不匹配的License文件
    PU_RESULT_LIC_FORMAT_ERROR,                            //License文件不合法
    PU_RESULT_LIC_NO_PRD_FEATURES_PRESENT,                 //License文件中没有产品特征段
    PU_RESULT_LIC_PRODUCT_INVALID,                         //产品名称无效
    PU_RESULT_LIC_EXPIRED,                                 //License文件过期  
    PU_RESULT_LIC_GET_CONFIG_ERROR,                        //获取控制项配置值失败
    PU_RESULT_LIC_LSN_REVOKED,                             //License文件已经失效
    PU_RESULT_LIC_ESNANY_AND_SIX_MON_VLDITY_NOT_ALLOWED,   //不允许重复加载ESN=ANY且有效期为 6个月的调测License 文件 
    PU_RESULT_LIC_MAX_FEATURES_REACHED,                    //License文件中Feature的数量超过最大值 
    PU_RESULT_LIC_INVALID_FEATURE_TYPE,                    //License文件中Feature的类型错误
    PU_RESULT_LIC_LM_NOT_ENABLED,                          //License组件没有启动 
    PU_RESULT_LIC_NO_FEATURES_IN_NORMAL_STATE,             //License文件中所有的Feature过期或者处于试用期
    PU_RESULT_LIC_ESN_MISMATCH,                            //License文件ESN和实际ESN不一致 
    PU_RESULT_LIC_VERSION_MISMATCH,                        //License文件版本和实际版本不一致
    PU_RESULT_LIC_NO_LICENSE_ACTIVITED,                    //没有激活的license
    PU_RESULT_MTU_ERR_WITH_IPV6_OPEN = 12520,              //IPV6场景下MTU错误
    PU_RESULT_ITGT_ERR_INVALID = 12600,                    //智能license无效状态
    PU_RESULT_MEDIA_UTGT_NOT_ENABLED = 12780,              /*媒体创建智能通道，智能模块没有使能*/

    //算法切换
    PU_RESULT_TGT_SWITCH_MODE_ERR_WRONG_VIDEO_MODE = 12800, //切换的模式不支持走廊模式
    PU_RESULT_TGT_SWITCH_MODE_ERR_ENABLE_ALG,               //切换的模式算法启用失败，先检查模型
    PU_RESULT_TGT_SWITCH_MODE_FTP_NEED_RECONFIG,            //切换模式成功，ftp需要重新配置

    PU_ERROR_MAX = 20000,
}PU_ERROR_CODE_E;


//请求类型 REQ_NULL为了标示初始化后并未赋值的情况   2018/06/26 By y00445101
typedef enum PU_REQ_TYPE
{
    REQ_NULL,
    REQ_GET,
    REQ_SET
}PU_REQ_TYPE_E;


//新接口类型 供公共接口函数使用   2018/06/29 By y00445101
typedef enum PU_INTERFACE_TYPE
{
    PU_ITF_TYPE_SIM_PHONE_NUM = 1,      //SIM手机号码
    PU_ITF_TYPE_MAX                     //预留
}PU_INTERFACE_TYPE_E;


//前端注册模式
typedef enum PU_LINK_MODE                          
{
    PU_AUTOLOGIN_MODE = 0,                                          //主动登陆模式，初始化后前端设备主动登录到SDK，仅解码器支持
    PU_MANUALLOGIN_MODE = 1,                                        //手动登陆模式，需手动调用IVS_PU_Login登录前端设备
    PU_BOTHLOGIN_MODE = 3,                                          //以上两种登陆模式都支持，仅IPC支持

    PU_LINK_MODE_MAX
}PU_LINK_MODE_E;

//device event callback type
typedef enum PU_EVENT_TYPE
{
    /* 连接状态回调 */
    PU_EVENT_TYPE_CONNCET = 1,                                      //前端主动连接，网络连接上
    PU_EVENT_TYPE_REGISTER,                                         //前端主动注册
    PU_EVENT_TYPE_NOT_REGISTER,                                     //前端主动连接后未注册
    PU_EVENT_TYPE_UNREGISTER,                                       //前端主动注销
    PU_EVENT_TYPE_DISCONNECT,                                       //前端网络连接断开
    PU_EVENT_TYPE_SEND_RECV_ERROR,                                  //发送或接收失败
    PU_EVENT_TYPE_KEEPLIVE_FAIL,                                    //前端保活失败

    /* 事件通知回调 */
    PU_EVENT_TYPE_STREAM_PACKAGE_CHANGE,                            //流套餐变更
    PU_EVENT_TYPE_WATERMARK_ERR,                                    //数字水印校验错误
    PU_EVENT_TYPE_UPLOAD_IMAGE_URL,                                 //前端主动获取抓拍图片上传URL请求
    PU_EVENT_TYPE_UPLOAD_IMAGE_COMP_NOTIFY,                         //前端抓拍图片上载完成通知
    PU_EVENT_TYPE_TRANSPARENT_CHANNEL_NOTIFY,                       //透明通道数据上报
    PU_EVENT_TYPE_REALPALY_ERROR,                                   //实况异常
    PU_EVENT_TYPE_REPORT_VISUAL_INFO,                               //上报可视化信息
    PU_EVENT_TYPE_PUPU_INFO,                                        //多机协同数据上报
	PU_EVENT_TYPE_RECORD_COMP_NOTIFY,								//录像下载完成通知
    PU_EVENT_TYPE_SLAVE_DEVICE_ADD,                                 //新增从设备事件
    PU_EVENT_TYPE_SLAVE_DEVICE_MODIFY,                              //修改从设备事件
    PU_EVENT_TYPE_SLAVE_DEVICE_DELETE,                              //删除从设备事件
    PU_EVENT_TYPE_SLAVE_DEVICE_ONLINE,                              //从设备上线事件
    PU_EVENT_TYPE_SLAVE_DEVICE_OFFLINE,                             //从设备下线事件

    PU_EVENT_TYPE_MAX
}PU_EVENT_TYPE_E;

//音视频编码类型
typedef enum PU_ENCODE_TYPE
{
    PU_ENC_PCMU          = 0,
    PU_ENC_1016          = 1,
    PU_ENC_G721          = 2,
    PU_ENC_GSM           = 3,
    PU_ENC_G723          = 4,
    PU_ENC_DVI4_8K       = 5,
    PU_ENC_DVI4_16K      = 6,
    PU_ENC_LPC           = 7,
    PU_ENC_PCMA          = 8,
    PU_ENC_G722          = 9,
    PU_ENC_S16BE_STEREO  = 10,
    PU_ENC_S16BE_MONO    = 11,
    PU_ENC_QCELP         = 12,
    PU_ENC_CN            = 13,
    PU_ENC_MPEGAUDIO     = 14,
    PU_ENC_G728          = 15,
    PU_ENC_DVI4_3        = 16,
    PU_ENC_DVI4_4        = 17,
    PU_ENC_G729          = 18,
    PU_ENC_G711A         = 19,                 //g711a
    PU_ENC_G711U         = 20,                 //g711u
    PU_ENC_G726          = 21,                 //g726
    PU_ENC_G729A         = 22,
    PU_ENC_LPCM          = 23,
    PU_ENC_CelB          = 25,
    PU_ENC_JPEG          = 26,
    PU_ENC_CUSM          = 27,
    PU_ENC_NV            = 28,
    PU_ENC_PICW          = 29,
    PU_ENC_CPV           = 30,
    PU_ENC_H261          = 31,
    PU_ENC_MPEGVIDEO     = 32,
    PU_ENC_MPEG2TS       = 33,
    PU_ENC_H263          = 34,
    PU_ENC_SPEG          = 35,
    PU_ENC_MPEG2VIDEO    = 36,
    PU_ENC_AAC           = 37,
    PU_ENC_WMA9STD       = 38,
    PU_ENC_HEAAC         = 39,
    PU_ENC_PCM_VOICE     = 40,
    PU_ENC_PCM_AUDIO     = 41,
    PU_ENC_AACLC         = 42,
    PU_ENC_MP3           = 43,
    PU_ENC_ADPCMA        = 49,
    PU_ENC_AEC           = 50,
    PU_ENC_X_LD          = 95,
    PU_ENC_H264          = 96,
    PU_ENC_D_GSM_HR      = 200,
    PU_ENC_D_GSM_EFR     = 201,
    PU_ENC_D_L8          = 202,
    PU_ENC_D_RED         = 203,
    PU_ENC_D_VDVI        = 204,
    PU_ENC_D_BT656       = 220,
    PU_ENC_D_H263_1998   = 221,
    PU_ENC_D_MP1S        = 222,
    PU_ENC_D_MP2P        = 223,
    PU_ENC_D_BMPEG       = 224,
    PU_ENC_MP4VIDEO      = 230,             //mepg-4
    PU_ENC_MP4AUDIO      = 237,
    PU_ENC_VC1           = 238,
    PU_ENC_JVC_ASF       = 255,
    PU_ENC_D_AVI         = 256,
    PU_ENC_OPUS          = 258,             //opus
    PU_ENC_H265          = 265,

    PU_ENC_AMR           = 1001,
    PU_ENC_MJPEG         = 1002,            //motion jpeg

    PU_ENC_MAX
}PU_ENCODE_TYPE_E;


//视频分辨率类型
typedef enum PU_RESOLUTION_TYPE
{
    PU_RESOLUTION_480I = 0,
    PU_RESOLUTION_576I,
    PU_RESOLUTION_QCIF_PAL,
    PU_RESOLUTION_QCIF_NTSC,
    PU_RESOLUTION_CIF_PAL,
    PU_RESOLUTION_CIF_NTSC,
    PU_RESOLUTION_2CIF,
    PU_RESOLUTION_HD1,
    PU_RESOLUTION_D1_PAL,                       //720 * 576
    PU_RESOLUTION_D1_NTSC,

    PU_RESOLUTION_QVGA,                         //320 * 240
    PU_RESOLUTION_VGA,                          //640 * 480
    PU_RESOLUTION_XGA,                          //1024 * 768
    PU_RESOLUTION_SXGA,                         //1400 * 1050
    PU_RESOLUTION_UXGA,                         //1600 * 1200
    PU_RESOLUTION_QXGA,                         //2048 * 1536

    PU_RESOLUTION_WVGA,                         //854 * 480
    PU_RESOLUTION_WSXGA,                        //1680 * 1050
    PU_RESOLUTION_WUXGA,                        //1920 * 1200
    PU_RESOLUTION_WQXGA,                        //2560 * 1600

    PU_RESOLUTION_HD720,                        //1280 * 720
    PU_RESOLUTION_HD1080,                       //1920 * 1080
    PU_RESOLUTION_HD1080I,

    PU_RESOLUTION_HD960,                        // 1280 * 960
    PU_RESOLUTION_HD1024,                       // 1280 * 1024

    PU_RESOLUTION_HD1296P = 25,                 // 2304 * 1296
    PU_RESOLUTION_HD1440P = 26,                 // 2560 * 1440
    PU_RESOLUTION_HD1728P = 27,                 // 3072 * 1728
    PU_RESOLUTION_HD4K    = 28,                 // 3840 * 2160

	PU_RESOLUTION_HD1536P = 29, 				// 2048 * 1536
    PU_RESOLUTION_HD1920P = 30,                 // 2560 * 1920
    PU_RESOLUTION_HD1944P = 31,                 // 2592 * 1944
    PU_RESOLUTION_HD2448P = 32,                 // 3264 * 2448
    PU_RESOLUTION_HD2160P = 33,                 // 4096 * 2160
    PU_RESOLUTION_HD2736P = 34,                 // 3648 * 2736

	PU_RESOLUTION_2592_1520P = 35,              /*2592*1520      400W*/
	PU_RESOLUTION_2560_2048 = 36,               /*2560*2048  5:4 500W*/
	PU_RESOLUTION_3072_2048 = 37,               /*3072*2048  3:2 600W*/
    
    PU_RESOLUTION_MAX
}PU_RESOLUTION_TYPE_E;

//视频流模式
typedef enum PU_STREAM_MODE_E
{
    PU_VIEDO_STREAM_NONE   = 0,             //不设置流套餐
    PU_VIEDO_STREAM_SINGLE = 1,             //视频单流
    PU_VIEDO_STREAM_DOUBLE = 2,             //视频双流
    PU_VIEDO_STREAM_TRIPLE = 3,             //视频三流
    PU_VIEDO_STREAM_FOUR   = 4,             //视频四流
	PU_VIEDO_STREAM_FIVE   = 5,             //视频五流         
    PU_VIEDO_STREAM_MAX
}PU_STREAM_MODE_E;

//视频流类型
typedef enum PU_STREAM_TYPE
{
    PU_VIDEO_MAIN_STREAM = 0,                //视频主码流
    PU_VIDEO_SUB_STREAM1,                    //视频子码流1
    PU_VIDEO_SUB_STREAM2,                    //视频子码流2
    PU_VIDEO_SUB_STREAM3,                    //视频子码流3
	PU_VIDEO_SUB_STREAM4,                    //视频子码流4
	PU_VIDEO_SUB_STREAM5,                    //
    PU_VIDEO_STREAM_MAX
}PU_STREAM_TYPE_E;

//图像质量
typedef enum PU_PIC_QUALITY                                          
{
    PU_PIC_QUALITY_BEST = 0,                //最好
    PU_PIC_QUALITY_MORE_BETTER,             //次好
    PU_PIC_QUALITY_BETTER,                  //较好
    PU_PIC_QUALITY_ORDINARY,                //一般
    PU_PIC_QUALITY_BAD,                     //较差
    PU_PIC_QUALITY_BADEST,                  //差
    PU_PIC_QUALITY_MAX
}PU_PIC_QUALITY_E;

//传输类型
typedef enum PU_PROTOCOL_TYPE
{
    PU_PROTOCOL_TYPE_UDP = 0,                  //UDP方式
    PU_PROTOCOL_TYPE_TCP,                      //TCP方式
    PU_PROTOCOL_TYPE_MULTICAST,                //组播方式
    PU_PROTOCOL_TYPE_MAX
}PU_PROTOCOL_TYPE_E;

//媒体回调类型
typedef enum PU_MEDIA_CALLBACK_TYPE
{
    PU_MEDIA_CALLBACK_TYPE_RTP = 0,         //RTP包方式
    PU_MEDIA_CALLBACK_TYPE_RTP_CRYPTO,      //RTP包形式，不解密
    PU_MEDIA_CALLBACK_TYPE_FRAME,           //帧回调方式
    PU_MEDIA_CALLBACK_TYPE_YUV,             //YUV方式，Linux不支持
    PU_MEDIA_CALLBACK_TYPE_FOR_STORAGE,
    PU_MEDIA_CALLBACK_TYPE_META_FRAME,
    PU_MEDIA_CALLBACK_TYPE_MAX
}PU_MEDIA_CALLBACK_TYPE_E;

//流类型
typedef enum PU_VIDEO_TYPE
{
    PU_VIDEO_TYPE_VIDEO = 0,                    //视频流
    PU_VIDEO_TYPE_AUDIO,                        //音频流
    PU_VIDEO_TYPE_MUX,                          //复合流
    PU_VIDEO_TYPE_RECORD,                       //录像流
    PU_VIDEO_TYPE_META,                         //元数据流
    PU_VIDEO_TYPE_VIDEO_META,                   //视频 + 元数据流
    PU_VIDEO_TYPE_MAX
}PU_VIDEO_TYPE_E;

//媒体加密类型
typedef enum PU_MEDIA_CRYPTO_TYPE
{
    PU_MEDIA_CRYPTO_NONE = 0,               //不加密
    PU_MEDIA_CRYPTO_HW_SIMPLE = 1,          //华为加密
    PU_MEDIA_CRYPTO_AES_128BIT = 2,         //128位AES加密
    PU_MEDIA_CRYPTO_AES_192BIT = 3,         //192位AES加密
    PU_MEDIA_CRYPTO_AES_256BIT = 4,         //256位AES加密
    PU_MEDIA_CRYPTO_AES256_CBC = 5,         //AES CBC模式256位
    PU_MEDIA_CRYPTO_MAX,
}PU_MEDIA_CRYPTO_TYPE_E;

//码率类型
typedef enum PU_BIT_RATE_TYPE
{
    PU_BIT_RATE_TYPE_FIXED = 0,             //定码率
    PU_BIT_RATE_TYPE_VARIABLE,              //变码率
    PU_BIT_RATE_TYPE_QP,                    //MJPEG码流
    PU_BIT_RATE_TYPE_MAX
}PU_BITRATE_TYPE_E;

//视频制式
typedef enum PU_VIDEO_FORMAT
{
    PU_VIDEO_FORMAT_PAL = 0,                //P制
    PU_VIDEO_FORMAT_NTSC,                   //N制
    PU_VIDEO_FORMAT_MAX
}PU_VIDEO_FORMAT_E;

/*帧率优先码率优先*/
typedef enum PU_H264_RC_PRI
{
    PU_H264_RC_FRAMERATE_PRI = 1,           //帧率优先
    PU_H264_RC_BITRATE_PRI,                 //码流优先

    PU_H264_RC_PRI_MAX
}PU_H264_RC_PRI_E;

//语言类型
typedef enum PU_LANGUAGE_TYPE
{
    PU_LANGUAGE_TYPE_CHINESE = 0,              //中文
    PU_LANGUAGE_TYPE_ENGLISH,                  //英文
    PU_LANGUAGE_TYPE_MAX
}PU_LANGUAGE_TYPE_E;

//本地保存录像方式
typedef enum PU_SAVE_REALDATA_TYPE
{
    PU_SAVE_REALDATA_TYPE_TIME = 0,         //按时间保存(单位：min)
    PU_SAVE_REALDATA_TYPE_SIZE = 1,         //按大小保存(单位：MBytes)
    PU_SAVE_REALDATA_TYPE_MAX
}PU_SAVE_REALDATA_TYPE_E;

//本地保存图片方式
typedef enum PU_SAVE_PICTURE_TYPE
{
    PU_SAVE_PICTURE_TYPE_BMP = 0,              //BMP文件
    PU_SAVE_PICTURE_TYPE_JEPG = 1,             //JPEG文件
    PU_SAVE_PICTURE_TYPE_MAX
}PU_SAVE_PICTURE_TYPE_E;

//串口类型
typedef enum PU_SERIAL_PORT_MODE
{
    PU_SERIAL_PORT_RS232 = 0,                  //232串口
    PU_SERIAL_PORT_RS422,                      //422串口
    PU_SERIAL_PORT_RS485,                      //485串口
    PU_SERIAL_PORT_MAX
}PU_SERIAL_PORT_MODE_E;

//波特率
typedef enum PU_BAUD_RATE
{
    PU_BAUD_R2400 = 0,
    PU_BAUD_R4800,
    PU_BAUD_R9600,
    PU_BAUD_R19200,
    PU_BAUD_R38400,
    PU_BAUD_R57600,
    PU_BAUD_R115200,
    PU_BAUD_R230400,
    PU_BAUD_R460800,
    PU_BAUD_R921600,
    PU_BAUD_MAX
}PU_BAUD_RATE_E;

//数据位
typedef enum PU_DATA_BIT
{
    PU_DATA_BIT_CS5 = 0,
    PU_DATA_BIT_CS6,
    PU_DATA_BIT_CS7,
    PU_DATA_BIT_CS8,
    PU_DATA_BIT_MAX
}PU_DATA_BIT_E;

//校验位
typedef enum PU_PARITY_BIT
{
    PU_PARITY_BIT_NONE = 0,
    PU_PARITY_BIT_ODD,
    PU_PARITY_BIT_EVEN,
    PU_PARITY_BIT_MARK,
    PU_PARITY_BIT_SPACE,
    PU_PARITY_BIT_MAX
}PU_PARITY_BIT_E;

//停止位
typedef enum PU_STOP_BIT
{
    PU_STOP_BIT_OFF = 0,
    PU_STOP_BIT_ON,
    PU_STOP_BIT_MAX
}PU_STOP_BIT_E; 

//串口流控制类型
typedef enum PU_FLOW_CONTROL
{
    PU_FLOW_CONTROL_NONE = 0,
    PU_FLOW_CONTROL_SOFT,
    PU_FLOW_CONTROL_HARD,
    PU_FLOW_CONTROL_MAX
}PU_FLOW_CONTROL_E;

//云台解码器类型
typedef enum PU_PTZ_DECODER_TYPE
{
    PU_PTZ_DECODER_PELCO_P = 1,
    PU_PTZ_DECODER_PELCO_D,
    PU_PTZ_DECODER_YAAN,
    PU_PTZ_DECODER_SAMSUNG,
    PU_PTZ_DECODER_REDAPPLE_5052,
    PU_PTZ_DECODER_TAISHUO,
    PU_PTZ_DECODER_REDAPPLE_5051,
    PU_PTZ_DECODER_USER_DEF,
    PU_PTZ_DECODER_MAX
}PU_PTZ_DECODER_TYPE_E;

//正反向控制
typedef enum PU_PTZ_CONTROL_MODE
{
    PU_PTZ_CONTROL_MODE_FORWARD = 1,
    PU_PTZ_CONTROL_MODE_BACK,
    PU_PTZ_CONTROL_MODE_MAX
}PU_PTZ_CONTROL_MODE_E;

//告警布防
typedef enum PU_ALARM_ACTION
{
    PU_ALARM_ACTION_MOVE = 1,                  //告警移除
    PU_ALARM_ACTION_HAPPEN,                    //告警发生
    PU_ALARM_ACTION_MAX
}PU_ALARM_ACTION_E;

// 云台控制
typedef enum PU_PTZ_OPCODE
{
    PU_PTZ_STOP = 1,                            //云台停止,忽略para1、para2
    PU_PTZ_UP = 2,                              //云台向上,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_DOWN = 3,                            //云台向下,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_LEFT = 4,                            //云台向左,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_UP_LEFT = 5,                         //云台左上,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_DOWN_LEFT = 6,                       //云台左下,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_RIGHT = 7,                           //云台向右,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_UP_RIGHT = 8,                        //云台右上,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_DOWN_RIGHT = 9,                      //云台右下,para1代表运动模式(1：点动，2：连续),para2代表云台转动速度（范围1-10）
    PU_PTZ_AUTO = 10,                           //云台自动,忽略para1、para2
    PU_PTZ_PRESET_RUN = 11,                     //预置位运行,para1代表预置位序号,忽略para2
    PU_PTZ_CRUISE_RUN = 12,                     //巡航轨迹运行,para1代表巡航轨迹序号,忽略para2
    PU_PTZ_CRUISE_STOP = 13,                    //巡航轨迹停止,忽略para1、para2
    PU_PTZ_FLIP = 17,                           //云台翻转180度,忽略para1、para2
    PU_PTZ_HOMING = 18,                         //云台归位,忽略para1、para2

    // 镜头控制
    PU_PTZ_LENS_APERTURE_OPEN = 19,             //光圈放大,忽略para1,忽略para2
    PU_PTZ_LENS_APERTURE_CLOSE = 20,            //光圈缩小,忽略para1,忽略para2
    PU_PTZ_LENS_ZOOM_WIDE = 21,                 //视野范围放大,即ZOOM OUT,para1固定为连续模式(2),para2代表速度
    PU_PTZ_LENS_ZOOM_TELESCOPE = 22,            //拉近景物,视野范围缩小,即ZOOM IN,para1固定为连续模式(2),para2代表速度

    /************************************************************************/
    /* 不建议在新版本中使用该参数*/
    PU_PTZ_LENS_ZOOM_IN = 21,                   //（不建议在新版本中使用该参数,请使用PU_PTZ_LENS_ZOOM_WIDE）范围放大
    PU_PTZ_LENS_ZOOM_OUT = 22,                  //（不建议在新版本中使用该参数,请使用PU_PTZ_LENS_ZOOM_TELESCOPE）范围缩小
    /************************************************************************/
    
    PU_PTZ_LENS_ZOOM_STOP = 23,                 //缩放关闭
    PU_PTZ_LENS_FOCAL_NEAR = 24,                //聚焦近,para1固定为连续模式(2),para2代表速度（范围1-10）
    PU_PTZ_LENS_FOCAL_FAR = 25,                 //聚焦远,para1固定为连续模式(2),para2代表速度（范围1-10）
    PU_PTZ_LENS_FOCAL_STOP = 26,                //聚焦关闭
    PU_PTZ_AUX_OPEN = 27,                       //辅助设备打开,para1代表设备名称,忽略para2
    PU_PTZ_AUX_STOP = 28,                       //辅助设备关闭,para1代表设备名称,忽略para2

    PU_PTZ_HORIZONTAL_SCAN = 29,                //水平扫描,para1代表方向,para2代表速度（范围1-10）
    PU_PTZ_VERTICAL_SCAN = 30,                  //垂直扫描,para1忽略,para2代表速度（范围1-10）

    PU_PTZ_MODE_SET_START =31,                  //花样轨迹记录开始
    PU_PTZ_MODE_SET_STOP =32,                   //花样轨迹记录停止
    PU_PTZ_FAST_LOCATE =33,                     //3d定位
    PU_PTZ_FAST_RETURN =34,                     //3d返回
    PU_PTZ_REBOOT = 35,                         //机电板重启
    PU_PTZ_RESTORE = 36,                        //机电板恢复默认配置
    PU_PTZ_SET_LEFT_LIMIT = 37,                 //设置左限位
    PU_PTZ_SET_RIGHT_LIMIT = 38,                //设置右限位
    PU_PTZ_MODE_CRUISE_START = 39,              //花样轨迹开始 para1代表巡航轨迹序号,忽略para2
    PU_PTZ_MODE_CRUISE_STOP = 40,               //.花样轨迹停止para1代表巡航轨迹序号,忽略para2
    PU_PTZ_FAST_MOVE = 41,                      //点选快速定位.para1表示x坐标、para2表示y坐标

    PU_PTZ_HORIZONTAL_LIMIT_SCAN = 51,          //水平限位扫描,para1固定为连续模式,para2代表速度（范围1-10）
    PU_PTZ_LENS_AUTO_FOCAL = 52,                //自动聚焦  
    PU_PTZ_GOTO_HOME = 53,                      //转动到home位
    PU_PTZ_ONE_PUSH = 54,                       //一体枪对焦OnePush
	PTZ_VERTICAL_LIMIT_SCAN = 55,               //垂直限位扫描,para1固定为连续模式,para2代表速度
	PTZ_SET_UP_LIMIT = 56,                      //设置上限位
	PTZ_SET_DOWN_LIMIT = 57,                    //设置下限位

    PU_PTZ_CMD_MAX
}PU_PTZ_OPCODE_E;
                                            
//云台运动模式
typedef enum PU_PTZ_MOTION_MODE
{
    PU_PTZ_MOTION_MODE_BURST = 1,               //点动模式
    PU_PTZ_MOTION_MODE_CONTINUOUS,              //连续模式

    PU_PTZ_MOTION_MODE_MAX
}PU_PTZ_MOTION_MODE_E;

//云台预置位操作命令字
typedef enum PU_PTZ_PRESET_CMD
{
    PU_PTZ_PRESET_SET = 1,                      //设置预置位
    PU_PTZ_PRESET_GET,                          //获取预置位
    PU_PTZ_PRESET_CLR,                          //清除预置位
    PU_PTZ_PRESET_GOTO,                         //转到预置位
    PU_PTZ_PRESET_MAX
}PU_PTZ_PRESET_CMD_E;

//巡航轨迹操作命令字
typedef enum PU_PTZ_CRUISE_TRACK
{
    PU_PTZ_CRUISE_TRACK_SET = 1,                //设置巡航轨迹
    PU_PTZ_CRUISE_TRACK_GET,                    //获取巡航轨迹
    PU_PTZ_CRUISE_TRACK_CLR,                    //清除巡航轨迹
    PU_PTZ_CRUISE_TRACK_GOTO,                   //云台巡航
    PU_PTZ_CRUISE_TRACK_STOP,                   //停止巡航
    PU_PTZ_CRUISE_TRACK_MAX
}PU_PTZ_CRUISE_TRACK_E;

typedef enum PU_OSD_DATE_TYPE
{
    PU_YYYY_MM_DD = 0,                          //YYYY-MM-DD
    PU_MM_DD_YYYY,                              //MM-DD-YYYY
    PU_YYYY_MM_DD_CH,                           //年-月-日
    PU_MM_DD_YYYY_CH,                           //月-日-年
    PU_DD_MM_YYYY,                              //DD-MM-YYYY
	PU_DD_MM_YYY_CH,                            //dd日mm月yyyy年
	PU_OSD_DATA_TYPE_MAX
}PU_OSD_DATE_TYPE_E;

//告警种类
typedef enum PU_ALARM_CATEGORY_TYPE
{
    PU_ALARM_CATEGORY_TYPE_ALL = 0,     //业务和设备类告警
    PU_ALARM_CATEGORY_TYPE_DEVICE,      //设备类告警
    PU_ALARM_CATEGORY_TYPE_SERVICE,     //业务类告警
    PU_ALARM_CATEGORY_TYPE_MAX
}PU_ALARM_CATEGORY_E;

//告警类型,注意:该枚举类型与智能的ALARM_TYPE_E保持完全一致
typedef enum PU_ALARM_TYPE
{
    PU_ALARM_TYPE_DI = 1,                       //开关量输入
    PU_ALARM_TYPE_DISK_FULL,                    //硬盘满告警
    PU_ALARM_TYPE_NO_SIGNAL,                    //无视频告警（视频丢失）
    PU_ALARM_TYPE_MOVE_DECTION,                 //移动侦测告警
    PU_ALARM_TYPE_DISK_FAULT,                   //硬盘故障
    PU_ALARM_TYPE_SHIELD,                       //遮挡告警，包括智能遮挡告警
    PU_ALARM_TYPE_NETWORK_INTERRUPT,            //网络中断
    PU_ALARM_TYPE_IP_ADDRESS_CONFLICT,          //IP冲突
    PU_ALARM_TYPE_TEMPERATURE,                  //温度告警
    PU_ALARM_TYPE_FACE_DETECTION,               //人脸检测
    PU_ALARM_TYPE_INVADE,                       //拌线检测
    PU_ALARM_TYPE_COUNT,                        //目标计数
    PU_ALARM_TYPE_DISTURB,                      //干扰检测

    /* 智能告警 */
    PU_ALARM_TYPE_TRIPWIRE = 14,                //越线检测
    PU_ALARM_TYPE_INTRUSION = 15,               //入侵检测
    PU_ALARM_TYPE_HOVER = 16,                   //徘徊检测
    PU_ALARM_TYPE_LEGACY = 17,                  //遗留检测
    PU_ALARM_TYPE_REMOVE = 18,                  //移走检测
    
    PU_ALARM_TYPE_MEDIA_INTERRUPT = 30,         //媒体流中断
    PU_ALARM_TYPE_DISK_EXCEPTION = 31,          //SD卡异常
    PU_ALARM_TYPE_AUDIO_EXCEPTION = 32,         //音频异常侦测
    PU_ALARM_TYPE_STORAGE_FAIL,                 //驱动存储器告警
    PU_ALARM_TYPE_RECORDING_JOBSTATE,           //录像任务状态变化
    PU_ALARM_TYPE_DEV_TEMPE,                    //温度芯片错误告警
    PU_ALARM_TYPE_LOG_WR,                       //日志读写告警
    PU_ALARM_TYPE_PTZ_CONFIG_WR,                //PTZ云台协议配置告警

    PU_ALARM_TYPE_FAN_PWR_BLOCKED = 38,         //半罩球电源板风扇堵转告警
    PU_ALARM_TYPE_FAN_HEC_BLOCKED,              //半罩球编码板风扇堵转告警
    PU_ALARM_TYPE_SFP_TEMP_HIGH,                //光模块温度过高告警
    PU_ALARM_TYPE_SFP_TEMP_LOW,                 //光模块温度过低告警
    PU_ALARM_TYPE_SFP_VOL_HIGH,                 //光模块电压过高告警
    PU_ALARM_TYPE_SFP_VOL_LOW,                  //光模块电压过低告警
    PU_ALARM_TYPE_SFP_BIAS_HIGH,                //光模块偏置电流过高告警
    PU_ALARM_TYPE_SFP_BIAS_LOW,                 //光模块偏置电流过低告警
    PU_ALARM_TYPE_SFP_TX_PWR_HIGH,              //光模块发送功率过高告警
    PU_ALARM_TYPE_SFP_TX_PWR_LOW,               //光模块发送功率过低告警
    PU_ALARM_TYPE_SFP_RX_PWR_HIGH,              //光模块接收功率过高告警
    PU_ALARM_TYPE_SFP_RX_PWR_LOW,               //光模块接收功率过低告警
    PU_ALARM_TYPE_SFP_LASER_TEMP_HIGH,          //光模块laser温度过高告警
    PU_ALARM_TYPE_SFP_LASER_TEMP_LOW,           //光模块laser温度过低告警
    PU_ALARM_TYPE_SFP_TEC_CURRENT_HIGH,         //光模块tec电流过高告警
    PU_ALARM_TYPE_SFP_TEC_CURRENT_LOW,          //光模块tec电流过低告警
    PU_ALARM_TYPE_DISC_PULLOUT,                 //硬盘移除
    PU_ALARM_TYPE_LIGHT_SENSOR_INCVALID,        //光敏芯片失效告警
    PU_ALARM_TYPE_EXTERNAL_POWER_DOWN,          //外部电源掉电告警
    PU_ALARM_TYPE_WIPER_FAILURE_ALARM,          //雨刷失败告警
    PU_ALARM_TYPE_SFP_NOT_EXIST,                //光模块不在位告警
    PU_ALARM_TYPE_TYPE_PTOPT_HOR_FAIL,          // 水平方向光耦失败
    PU_ALARM_TYPE_TYPE_PTOPT_VER_FAIL,          // 垂直方向光耦失败
	
	PU_ALARM_TYPE_ITS_RADAR_EXCEPTION_ALARM = 62,                      //its雷达异常的告警
	PU_ALARM_TYPE_ITS_IOCOIL_EXCEPTION_ALARM,                         //its的IO线圈异常的告警
	PU_ALARM_TYPE_ITS_485COIL_EXCEPTION_ALARM,                        //its的485线圈异常的告警
	PU_ALARM_TYPE_ITS_REDTOR_EXCEPTION_ALARM,                         //its红绿灯检测器异常的告警
	PU_ALARM_TYPE_LENS_FAILURE_ALARM,                                 //镜头PT光耦失效告警

    /* 硬件模块告警新增: 注意不能篡改其他值, 不能超过 200 */
    PU_ALARM_TYPE_AUDIO_UP = 100,               //音频陡升
    PU_ALARM_TYPE_AUDIO_DOWN,                   //音频陡降

    PU_ALARM_TYPE_ENTER,                        //区域进入检测
    PU_ALARM_TYPE_EXIT,                         //区域离开检测
    PU_ALARM_TYPE_FASTMOVE,                     //快速移动检测
    PU_ALARM_TYPE_CPU_HIGHT,                    //CPU过高告警
    PU_ALARM_TYPE_MEM_HIGHT,                    //内存过高告警
    PU_ALARM_TYPE_SCENECHANGE = 107,            //场景变更
    PU_ALARM_TYPE_AUTOTRACKING,                 //自动跟踪
    PU_ALARM_TYPE_OUTOFFOCUS_DETECT,            //虚焦检测
    PU_ALARM_TYPE_CROWD_ANALYSIS,               //人员聚集

    PU_ALARM_TYPE_SHAKE_DIAGNOSIS,                 // 抖动检测
    PU_ALARM_TYPE_FROZEN_DIAGNOSIS,                // 视频画面冻结
    PU_ALARM_TYPE_SNOW_NOISE_DIAGNOSIS,            // 雪花噪声检测
    PU_ALARM_TYPE_STRIPENOISE_DIAGNOSIS,           // 条纹噪声检测
    PU_ALARM_TYPE_BRIGHT_DIAGNOSIS,                // 增益失衡
    PU_ALARM_TYPE_COLORCAST_DIAGNOSIS,             // 偏色检测
    
    PU_ALARM_TYPE_CAR_DETECTION,                   //停车侦测
    PU_ALARM_TYPE_HUMAN_COUNT,                     //过线统计
    PU_ALARM_TYPE_FD_DL,                        //3559人脸检测 

	PU_ALARM_TYPE_QUEUE_DETECT  = 121,                 //排队长度
	PU_ALARM_TYPE_CROWD_DENSITY_DETECT,                //人群密度
	PU_ALARM_TYPE_ILLEGAL_PARKING,                     // 违停球
	PU_ALARM_TYPE_VLPR_TRAFFIC_CONGESTION,             // 交通拥堵
	PU_ALARM_TYPE_TRAFFIC_CONGESTION,                  // ITS交通拥堵
	
	PU_ALARM_TYPE_FACE_RECOGNITION = 130,                             //3559人脸识别
	
    PU_LPR_CAPTURE_RES = 200,                   //车牌抓拍结果
    PU_MANUAL_LPR_CAPTURE_RES = 201,            //手动车牌抓拍结果



    PU_ALARM_TYPE_HTTPS_CERT_EXPIRE = 300,      //https证书超期告警
    PU_ALARM_TYPE_HTTPS_CERT_WILL_EXPIRE,       //https证书即将超期告警
    PU_ALARM_TYPE_DOT1X_CERT_EXPIRE,            //802.1x证书超期告警
    PU_ALARM_TYPE_DOT1X_CERT_WILL_EXPIRE,       //802.1x证书即将超期告警
    PU_ALARM_TYPE_SDK_PWD_STILL_INITIAL_PWD,    //SDK密码未修改

    PU_AlARM_TYPE_PTZ_MOVE,                     //genetec PTZ 移动
    PU_ALARM_TYPE_SSH_OPEN = 306,               //SSH被打开
    PU_ALARM_TYPE_SDK_USR_LOCK = 307,           //SDK用户被锁定
    PU_ALARM_TYPE_WEB_USR_LOCK = 308,           //WEB用户被锁定
    PU_ALARM_TYPE_ONVIF_USR_LOCK = 309,         //ONVIF用户被锁定
    PU_ALARM_TYPE_GENETEC_USR_LOCK = 310,       //GENETEC用户被锁定
    
    PU_ALARM_TYPE_DOT1X_CA_CERT_EXPIRE,         //802.1x CA证书超期告警
    PU_ALARM_TYPE_DOT1X_CA_CERT_WILL_EXPIRE,    //802.1x CA证书即将超期告警

    PU_ALARM_TYPE_WEB_PWD_EXPIRE,               //WEB密码超期告警
    PU_ALARM_TYPE_ATTITUDE_ABNORMAL,            //姿态异常告警类型
    
    PU_ALARM_TYPE_VE_ILLEGAL_PARKING = 400,     // 违章停车
    PU_ALARM_TYPE_VE_ON_VEHICLE_LANE,           // 非占机
    PU_ALARM_TYPE_VE_ON_NONEVEHICLE_LANE,       // 机占非
    PU_ALARM_TYPE_VE_PRESSING_LINE,             // 压线
    PU_ALARM_TYPE_VE_WRONG_DIRECTION,           // 倒车/逆行
    //PU_ALARM_TYPE_VE_ABNORMAL_PLATE,            // 异常车牌，注意不要删除，智能要求暂时注释掉，后面还要放开
    PU_ALARM_TYPE_VE_REVERSE = 406,             // 倒车,由于异常车牌没有删掉，为了枚举值和智能保持一致，此处写死为406

    //多机互助
    PU_ALARM_TYPE_SLAVE_RTSP_KEEP_ALIVE_FAIL = 500, //从机rtsp保活失败
    PU_ALARM_TYPE_SLAVE_STREAM_NORMAL = 506,        //从机rtsp流正常
    
    PU_ALARM_TYPE_WIFI_ALARM = 550,                 //wifi异常
    PU_ALARM_TYPE_UPDATE_ROLLBACK_ALARM = 560,      //升级版本失败回退告警
    PU_ALARM_TYPE_ALL,                          //所有告警
    PU_ALARM_TYPE_MAX                           //预留
}PU_ALARM_TYPE_E;

//平台类型(平台配置)
typedef enum PU_PLATFORM_TYPE
{
    PU_PLATFORM_TYPE_NVS = 1,                   //NVS平台
    PU_PLATFORM_TYPE_IVS = 2,                   //IVS平台
    PU_PLATFORM_TYPE_GBT,                       //28281平台
    PU_PLATFORM_TYPE_IVS_ENABLE,                //IVS平台，带使能
    PU_PLATFORM_TYPE_GBT_ENABLE,                //28281平台，带使能
    PU_PLATFORM_TYPE_SDK_ENABLE,                //SDK平台参数，带使能
    PU_PLATFORM_TYPE_OTHERS,
    PU_PLATFORM_TYPE_MAX
}PU_PLATFORM_TYPE_E;

typedef enum PU_SDK_PLATFORM_MODE_E
{
    PU_SDK_PALTFORM_MODE_SINGEL = 1,           //单服务器模式
    PU_SDK_PLATFORM_MODE_DUAL,                 //双服务器模式
    PU_SDK_PLATFORM_MODE_MAX
}PU_SDK_PLATFORM_MODE_E;

typedef enum PU_CONNECT_TYPE
{
    PU_CONNECT_TYPE_PWD = 0,
    PU_CONNECT_TYPE_SSL_PWD,
    PU_CONNECT_TYPE_MAX
}PU_CONNECT_TYPE_E;

//日志类型
typedef enum PU_LOG_TYPE
{
    PU_LOG_TYPE_OPERATION = 1,                  //操作日志
    PU_LOG_TYPE_EXCEPT,                         //异常日志
    PU_LOG_TYPE_ALARM,                          //告警日志
    PU_LOG_TYPE_MAX
}PU_LOG_TYPE_E;

//解码器类型定义

//分辨率模式
typedef enum PU_DISRESOLUTION_MODE
{
    PU_VGA_NOT_AVALIABLE,
    PU_VGA_MODE_SVGA_60HZ = 1,
    PU_VGA_MODE_SVGA_75HZ,
    PU_VGA_MODE_XGA_60HZ,
    PU_VGA_MODE_XGA_70HZ,
    PU_VGA_MODE_SXGA_60HZ,
    PU_VGA_MODE_720P_60HZ,
    PU_VGA_MODE_1080I_60HZ,
    PU_VGA_MODE_1080P_30HZ,
    PU_VGA_MODE_UXGA_30HZ,
    PU_HDMI_MODE_XGA_60HZ = 21,
    PU_HDMI_MODE_SXGA_60HZ,
    PU_HDMI_MODE_SXGA2_60HZ,
    PU_HDMI_MODE_720P_60HZ,    
    PU_HDMI_MODE_720P_50HZ,        
    PU_HDMI_MODE_1080I_60HZ,
    PU_HDMI_MODE_1080I_50HZ,
    PU_HDMI_MODE_1080P_25HZ,
    PU_HDMI_MODE_1080P_30HZ,
    PU_HDMI_MODE_1080P_50HZ,
    PU_HDMI_MODE_1080P_60HZ,
    PU_HDMI_MODE_UXGA_60HZ,
    PU_DVI_MODE_XGA_60HZ = 41,
    PU_DVI_MODE_SXGA_60HZ,
    PU_DVI_MODE_SXGA2_60HZ,
    PU_DVI_MODE_720P_60HZ,    
    PU_DVI_MODE_720P_50HZ,        
    PU_DVI_MODE_1080I_60HZ,
    PU_DVI_MODE_1080I_50HZ,
    PU_DVI_MODE_1080P_25HZ,
    PU_DVI_MODE_1080P_30HZ,
    PU_DVI_MODE_1080P_50HZ,
    PU_DVI_MODE_1080P_60HZ,
    PU_DVI_MODE_UXGA_60HZ,
    PU_BNC_MODE_D1PAL_60HZ = 61,
    PU_BNC_MODE_D1PAL_50HZ,
    PU_BNC_MODE_D1NTSC_60HZ,
    PU_BNC_MODE_D1NTSC_50HZ,

    PU_DISRESOLUTION_MODE_MAX
}PU_DISRESOLUTION_MODE_E;

//端口类型
typedef enum PU_PORT_TYPE
{
    PU_PORT_TYPE_HDMI = 0,
    PU_PORT_TYPE_VGA = 1,
    PU_PORT_TYPE_BNC = 2,
    PU_PORT_TYPE_DVI = 3,

    PU_PORT_TYPE_MAX
}PU_PORT_TYPE_E;

//端口模式
typedef enum PU_PORT_MODE
{
    PU_PORT_MODE_1 = 1,                        //1画面
    PU_PORT_MODE_2 = 2,                        //2画面
    PU_PORT_MODE_4 = 4,                        //4画面
    PU_PORT_MODE_9 = 9,                        //9画面
    PU_PORT_MODE_16 = 16,                      //16画面

    PU_PORT_MODE_MAX
}PU_PORT_MODE_E;

//帧率
typedef enum PU_FRAME_RATE
{
    PU_FRAME_RATE_30 = 0,
    PU_FRAME_RATE_50,
    PU_FRAME_RATE_60
}PU_FRAME_RATE_E;

//码流加密类型
typedef enum PU_ENCRYPT_TYPE
{
    PU_ENCRYPT_TYPE_HUAWEI_VIDEO = 0,          //实行华为码流加密算法,加密视频
    PU_ENCRYPT_TYPE_HUAWEI_AUDIO,              //实行华为码流加密算法,加密音频
    PU_ENCRYPT_TYPE_HUAWEI_MUX,                //实行华为码流加密算法,加密复合流
    PU_ENCRYPT_TYPE_NONE,                      //不实行码流加密
    PU_ENCRYPT_TYPE_MAX
}PU_ENCRYPT_TYPE_E;

//音频端口类型
typedef enum PU_AUDIO_PORT_TYPE
{
    PU_AUDIO_PORT_TYPE_BNC_PLAY = 0,           //BNC放音端口
    PU_AUDIO_PORT_TYPE_HDMI_PLAY = 1,          //HDMI放音端口

    PU_AUDIO_PORT_TYPE_MAX
}PU_AUDIO_PORT_TYPE_E;

//音频采样率
typedef enum PU_AUDIO_SAMPLERATE
{
    PU_AUDIO_SAMPLERATE_8000 = 8000,
    PU_AUDIO_SAMPLERATE_12000 = 12000,
    PU_AUDIO_SAMPLERATE_11025 = 11025,
    PU_AUDIO_SAMPLERATE_16000 = 16000,
    PU_AUDIO_SAMPLERATE_22050 = 22050,
    PU_AUDIO_SAMPLERATE_24000 = 24000,
    PU_AUDIO_SAMPLERATE_32000 = 32000,
    PU_AUDIO_SAMPLERATE_44100 = 44100,
    PU_AUDIO_SAMPLERATE_48000 = 48000,

    PU_AUDIO_SAMPLERATE_MAX
}PU_AUDIO_SAMPLERATE_E, *LPPU_AUDIO_SAMPLERATE_E;

//G726编码格式的码率
typedef enum PU_AUDIO_G726_BPS
{
    PU_AUDIO_G726_16K = 0,                  /* G726 16kbps, */ 
    PU_AUDIO_G726_24K,                      /* G726 24kbps, */
    PU_AUDIO_G726_32K,                      /* G726 32kbps, */
    PU_AUDIO_G726_40K,                      /* G726 40kbps, */
    PU_AUDIO_G726_64K,                      /* G726 64kbps, */
    PU_AUDIO_G726_96K,                      /* G726 96kbps, */
    PU_AUDIO_G726_128K,                     /* G726 128kbps, */
    PU_AUDIO_G726_160K,                     /* G726 160kbps, */
    PU_AUDIO_G726_192K,                     /* G726 192kbps, */
    PU_AUDIO_G726_224K,                     /* G726 224kbps, */
    PU_AUDIO_G726_256K,                     /* G726 256kbps, */
    PU_AUDIO_G726_288K,                     /* G726 288kbps, */
    PU_AUDIO_G726_320K,                     /* G726 320kbps, */
    PU_AUDIO_G726_352K,                     /* G726 352kbps, */
    PU_AUDIO_G726_384K,                     /* G726 384kbps, */
    PU_AUDIO_G726_416K,                     /* G726 416kbps, */
    PU_AUDIO_G726_448K,                     /* G726 448kbps, */
    PU_AUDIO_G726_480K,                     /* G726 480kbps, */
    PU_AUDIO_G726_512K,                     /* G726 512kbps, */
    PU_AUDIO_G726_48K,                      /* G726 48kbps, */
    PU_AUDIO_G726_22K,                      /* G726 22kbps, */
    PU_AUDIO_G726_MAX,
}PU_AUDIO_G726_BPS_E;

/* 视频昼夜模式  */
typedef enum PU_VIDEO_DAYNIGHT_MODE
{
    PU_VIDEO_DAYNIGHT_MODE_AUTO = 0,           //自动模式
    PU_VIDEO_DAYNIGHT_MODE_COLOR,              //彩色模式
    PU_VIDEO_DAYNIGHT_MODE_GRAY,               //黑白模式
    PU_VIDEO_DAYNIGHT_MODE_MAX
}PU_VIDEO_DAYNIGHT_MODE_E;

/* 图像镜像和旋转方式 */
typedef enum PU_VIDEO_MIRROR_MODE
{
    PU_VIDEO_MIRROR_MODE_NORMAL = 0,           //正常图像
    PU_VIDEO_MIRROR_MODE_MIRROR,               //左右镜像
    PU_VIDEO_MIRROR_MODE_FLIP,                 //上下
    PU_VIDEO_MIRROR_MODE_BOTH,                 //上下左右
    PU_VIDEO_MIRROR_MODE_MAX
}PU_VIDEO_MIRROR_MODE_E;

/* 背景频率  */
typedef enum PU_VIDEO_FLICKER_MODE
{
    PU_VIDEO_FLICKER_NONE = 0,                 //关闭
    PU_VIDEO_FLICKER_50HZ,                     //50HZ
    PU_IDEO_FLICKER_60HZ,                      //60HZ

    PU_VIDEO_FLICKER_MAX
}PU_VIDEO_FLICKER_MODE_E;

/* 降噪模式 */
typedef enum PU_DENOISE_MODE
{
    DENOISE_NORMOL = 0,               //普通模式
    DENOISE_CLOSE,                    //关闭降噪
    DENOISE_EXPERT,                   //专家模式

    DENOISE_MAX
}PU_DENOISE_MODE_E;

/* 测光模式 */
typedef enum PU_VIDEO_AEMETERING_MODE
{
    PU_VIDEO_AEMETERING_CENTER = 0,            //中心测光(不支持)
    PU_VIDEO_AEMETERING_SPOT,                  //中心点测光(不支持)
    PU_VIDEO_AEMETERING_AVERAGE,               //平均测光
    PU_VIDEO_AEMETERING_BACKLIGHT,             //背光测光(不支持)
    PU_VIDEO_AEMETERING_CLOSE,                 //关闭(不支持)
    PU_VIDEO_AEMETERING_USER,                  //用户自定义

    PU_VIDEO_AEMETERING_MAX
}PU_VIDEO_AEMETERING_MODE_E;

/* 镜头类型 */
typedef enum PU_LENS_TYPE
{
    PU_LENS_TYPE_SA = 0,           //Fuji lens(DV3.4x3.8SA-SA1L)
    PU_LENS_TYPE_SE                //Fuji lens(D8x7.8A-SE2N)
}PU_LENS_TYPE_E;

/* AE曝光模式 */
typedef enum PU_AE_MODE
{
    PU_AE_MODE_AUTO = 0,                       //自动曝光，自动光圈增益、固定的快门值
    PU_AE_MODE_MANUAL,                         //手动曝光
    PU_AE_MODE_SHUTTER_PRI,                    //快门优先
    PU_AE_MODE_IRIS_PRI,                       //光圈优先
    PU_AE_MODE_LOW_NOISE,                      //噪声优先
    PU_AE_MODE_FRAME_RATE,                     //帧率优先
    PU_AE_MODE_BRIGHT,                         //亮度优先

    PU_AE_MODE_MAX
}PU_AE_MODE_E;

//宽动态模式
typedef enum PU_WDR_SWITCH_MODE
{
    PU_WDR_SWITCH_AUTO,                     //自动模式
    PU_WDR_SWITCH_CLOSE,                    //关闭
    PU_WDR_SWITCH_MANUAL,                   //手动模式
    PU_WDR_SWITCH_MAX,
}PU_WDR_SWITCH_MODE_E;

/*抓拍类型*/
typedef enum PU_SNAPSHOT_TYPE
{
    PU_SNAPSHOT_TYPE_MANUAL = 0,               //手动抓拍
    PU_SNAPSHOT_TYPE_ALARM,                    //告警抓拍
    PU_SNAPSHOT_TYPE_TIMER,                    //定时抓拍
    PU_SNAPSHOT_TYPE_MANUAL_EX,                //
    PU_SNAPSHOT_TYPE_FACEDT,				   //人脸抓拍
    PU_SNAPSHOT_TYPE_ITGT,					   //智能触发
	PU_SNAPSHOT_TYPE_ITS,	  		           //ITS抓拍
	PU_SNAPSHOT_TYPE_VEHICLE,		           //车辆事件触发
    PU_SNAPSHOT_TYPE_MAX
}PU_SNAPSHOT_TYPE_E;

//业务类型
typedef enum PU_BUSINESS_TYPE
{
    PU_BUSINESS_REAL_VIDEO = 0,                //实时浏览
    PU_BUSINESS_AUDIO_TALK,                    //语音对讲
    PU_BUSINESS_AUDIO_BROADCAST,               //语音广播
    PU_BUSINESS_RECORD_DOWNLOAD,               //录像下载
    PU_BUSINESS_RECORD_PLAY_BACK,              //录像回放
    PU_BUSINESS_SNAPSHOT_DOWNLOAD,             //图片下载

    PU_BUSINESS_TYPE_MAX
}PU_BUSINESS_TYPE_E;

//视频流的传输类型
typedef enum PU_VIDEO_CODE_TYPE
{
    PU_VIDEO_CODE_TYPE_ES,                     //ES流
    PU_VIDEO_CODE_TYPE_PS,                     //PS流
    PU_VIDEO_CODE_TYPE_TS,                     //TS流
    PU_VIDEO_CODE_TYPE_MAX
}PU_VIDEO_CODE_TYPE_E;

typedef enum PU_RECORD_TYPE
{
    PU_RECORD_TYPE_ALARM = 0,               //告警录像
    PU_RECORD_TYPE_MANUAL,                  //手动录像
    PU_RECORD_TYPE_TIMING,                  //计划录像
    PU_RECORD_METHOD_ADD,                   //补录录像
    PU_RECORD_METHOD_ALL,                   //所有类型录像
    PU_RECORD_TYPE_MAX,
}PU_RECORD_TYPE_E;

/* 硬盘类型 */
typedef enum PU_DISK_TYPE
{
    PU_DISK_TYPE_IDE = 1,                   //IDE硬盘
    PU_DISK_TYPE_SATA,                      //串行接口硬盘
    PU_DISK_TYPE_FLASH,                     //闪存，如SD、CF

    PU_DISK_TYPE_UNKNOWN
}PU_DISK_TYPE_E;

/* 降噪模式 */
typedef enum PU_NOISE_REDUCTION_MODE
{
    PU_NOISE_REDUCTION_CLOSE = 0,           //关闭
    PU_NOISE_REDUCTION_NORMAL,              //普通模式
    PU_NOISE_REDUCTION_EXPERT,              //专家模式

    PU_NOISE_REDUCTION_MAX
}PU_NOISE_REDUCTION_MODE_E;


typedef enum PU_FEC_PACKET_LOSS_RATIO
{
    PU_FEC_PACKET_LOSS_RATIO_1 = 0,                  /**<  0: 1%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_2 = 1,                  /**<  1: 2%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_3 = 2,                  /**<  2: 3%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_4 = 3,                  /**<  3: 4%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_5 = 4,                  /**<  4: 5%丢包  */
    PU_FEC_PACKET_LOSS_RATIO_MAX
} PU_FEC_PACKET_LOSS_RATIO_E;

//SEC丢包率
typedef enum PU_SEC_PACKET_LOSS_RATIO
{
    PU_SEC_PACKET_LOSS_RATIO_1 = 0,                  /* 0: 4%丢包 */
    PU_SEC_PACKET_LOSS_RATIO_2 = 1,                  /* 1: 8%丢包 */
    PU_SEC_PACKET_LOSS_RATIO_3 = 2,                  /* 2: 12%丢包 */
    PU_SEC_PACKET_LOSS_RATIO_4 = 3,                  /* 3: 16%丢包 */
    PU_SEC_PACKET_LOSS_RATIO_5 = 4,                  /* 4: 20%丢包 */
    PU_SEC_PACKET_LOSS_RATIO_MAX
} PU_SEC_PACKET_LOSS_RATIO_E;

//颜色
typedef enum PU_COLOR_TYPE
{
    PU_COLOR_BLACK = 0,
    PU_COLOR_WHITE,
    PU_COLOR_MAX
}PU_COLOR_TYPE_E;

//透明度
typedef enum PU_ALPHA_TYPE
{
    PU_ALPHA_NONE = 0,
    PU_ALPHA_HALF,
    PU_ALPHA_ALL,
    PU_ALPHA_MAX
}PU_ALPHA_TYPE_E;

typedef enum PU_DSCP_TYPE
{
    PU_DSCP_TYPE_MEDIA = 0,                 //媒体DSCP值 包括音频和视频
    PU_DSCP_TYPE_CMD,                       //信令DSCP值 包含告警
    PU_DSCP_TYPE_MAX
}PU_DSCP_TYPE_E;

/*智能区域检测类型*/
typedef enum PU_IGT_AREA_ALARM_TYPE
{
    PU_IGT_TYPE_INTRUSION  = 0,             //入侵检测
    PU_IGT_TYPE_HOVER,                      //徘徊检测
    PU_IGT_TYPE_LEGACY,                     //遗留检测
    PU_IGT_TYPE_REMOVE,                     //移走检测
    PU_IGT_TYPE_ENTER,                      //区域进入
    PU_IGT_TYPE_EXIT,                       //区域离开
    PU_IGT_TYPE_FASTMOVE,                   //快速移动
    PU_IGT_TYPE_MAX
}PU_IGT_AREA_ALARM_TYPE_E;  

/* 智能场景使能 */
typedef enum PU_IGT_FIELD_TYPE
{
    PU_IGT_FIELD_LONGSHOT = 0,              //远景
    PU_IGT_FIELD_CLOSESHOT = 1,             //近景
    PU_IGT_FIELD_MAX
}PU_IGT_FIELD_TYPE_E;

/* 前景目标尺寸设置 */
typedef enum PU_IGT_MINTARGET_SIZE
{
    PU_IGT_TARGETSIZE_SMALL = 0,            //小目标
    PU_IGT_TARGETSIZE_MIDDLE = 1,           //中目标
    PU_IGT_TARGETSIZE_BIG = 2,              //大目标
    PU_IGT_TARGETSIZE_MAX
}PU_IGT_MINTARGET_SIZE_E;

/* 去阴影模式 */
typedef enum PU_IGT_SHADOW_MODE
{
    PU_IGT_SHADOW_WEAK = 0,                 //弱阴影
    PU_IGT_SHADOW_COMMON = 1,               //普通阴影
    PU_IGT_SHADOW_STRONG = 2,               //强阴影
    PU_IGT_SHADOW_MAX
}PU_IGT_SHADOW_MODE_E;

/* 灵敏度设置 */
typedef enum PU_IGT_DETECT_SENS
{
    PU_IGT_SENS_LOW = 0,                    //低灵敏度
    PU_IGT_SENS_MIDDLE = 1,                 //中灵敏度
    PU_IGT_SENS_HIGH = 2,                   //高灵敏度
    PU_IGT_SENS_LOWER = 3,                  //更低灵敏度
    PU_IGT_SENS_LOWEST = 4,                 //最低灵敏度
    PU_IGT_SENS_MAX
}PU_IGT_DETECT_SENS_E;

/* 智能目标识别模式 */
typedef enum PU_IGT_TARGET_MODE
{
    PU_IGT_TARGETMODE_CENTRE = 0,           //中心
    PU_IGT_TARGETMODE_BOTTOM = 1,           //底部
    PU_IGT_TARGETMODE_TOP = 2,              //顶部
    PU_IGT_TARGETMODE_MAX
}PU_IGT_TARGET_MODE_E;

typedef enum PU_IRLIGHT_MODE
{
    PU_IRLIGHT_MODE_ATUO = 0,               //自动
    PU_IRLIGHT_MODE_MANUAL,                 //手动

    PU_IRLIGHT_MODE_MAX
}PU_IRLIGHT_MODE_E;

typedef enum PU_IGT_OPT_TYPE
{
    PU_IGT_OPT_TYPE_ADD = 0,                //新增：需要带LPPU_IGT_TW_LINE_S或LPPU_IGT_AREA_S的所有信息
    PU_IGT_OPT_TYPE_MOD = 1,                //修改：需要带LPPU_IGT_TW_LINE_S或LPPU_IGT_AREA_S的所有信息
    PU_IGT_OPT_TYPE_DEL = 2,                //删除：只需要带LPPU_IGT_TW_LINE_S或LPPU_IGT_AREA_S的channelid和index
    PU_IGT_OPT_TYPE_MOV = 3,                /*移动至添加绊线或区域时的视图：只需要带LPPU_IGT_TW_LINE_S或LPPU_IGT_AREA_S的channelid和index，*/
                                            /*具体绊线或坐标信息同时会作为出参带回来*/
    PU_IGT_OPT_TYPE_MAX
}PU_IGT_OPT_TYPE_E;

typedef enum PU_ITGT_TYPE
{
    PU_ITGT_TYPE_FACE_BODY_DETECT = 1,            //人脸人体检测 Face and body detection 
    PU_ITGT_TYPE_FACE_RECOGTION,                  //人脸识别Facial recognition 
    PU_ITGT_TYPE_OBJ_CLASSIFICATION,              //机非人车牌检测Object classification 
    PU_ITGT_TYPE_ILLEG_PARK_DETECT,               //违停检测Illegal parking detection 
    //PU_ITGT_TYPE_NON_CHINA_VEH_RECOGTION,       //海外车牌检测Non-China vehicle recognition，被收编
	PU_ITGT_TYPE_VLPR_VEH_RECOGTION,			  //车牌算法检测License plate algorithm recognition，收编海外车牌、国内/印尼车牌检测
    PU_ITGT_TYPE_SCENE_ADAPT_FOG,                 //透雾自适应Fog scene adaptive
    PU_ITGT_TYPE_SCENE_ADAPT_SPEED,               //拖影自适应speed scene adaptive
    PU_ITGT_TYPE_SCENE_ADAPT_BACK_LIGHT,          //背光自适应Backlight scene adaptive
    PU_ITGT_TYPE_FACE_ATTRIBUTE,                  //人脸属性 face attribute
    PU_ITGT_TYPE_BODY_ATTRIBUTE,                  //人体属性 body attribute
    PU_ITGT_TYPE_QUEUE_DETECT,                    //排队检测 queue detect
    PU_ITGT_TYPE_CROWD_DENSITY_DETECITON,         //人群密度检测  crowd density detection
    PU_ITGT_TYPE_CHINA_INDO_VEH_RECOGTION,        //国内/印尼车牌 Chn & Indo vehicle recognition，被收编	
    PU_ITGT_TYPE_STRATEGY_MMC,                    //多机协同 multi-cooperation
    PU_ITGT_TYPE_STRATEGY_YTN,                    //一拖N组网
    PU_ITGT_TYPE_STRATEGY_ONLINELEARNING,          //在线自学习
    PU_ITGT_TYPE_STRATEGY_PORTTRAIT_VALUE_BASIC,   //人像基础
    PU_ITGT_TYPE_STRATEGY_PORTTRAIT_VALUE_ENHANCED,//人像增强
    PU_ITGT_TYPE_STRATEGY_VEHICLE_VALUE_BASE,      //车辆基础  
    PU_ITGT_TYPE_STRATEGY_VEHICLE_VALUE_enhanced,  //车辆增强  
    PU_ITGT_TYPE_STRATEGY_BEHAVIOR_ANALYSIS,       //行为分析态势    
    PU_GB35114SW,                                  //GB35114软件SDK License
    PU_ITGT_TYPE_EBI_TYPE,                         //BEI周界专用款型  
    PU_ITGT_TYPE_MAX
}PU_ITGT_TYPE_E;

/* 典型场景模式 */
typedef enum PU_TYPICAL_SCENE_MODE
{
    PU_TYPICAL_SCENE_DEFAULT = 0,/* 默认场景 */
    PU_TYPICAL_SCENE_OUT_DOOR,   /* 室外场景 */
    PU_TYPICAL_SCENE_IN_DOOR,    /* 室内场景 */
    PU_TYPICAL_SCENE_LOW_LIGHT,  /* 低照场景 */
    PU_TYPICAL_SCENE_MOVE,       /* 运动场景 */
    PU_TYPICAL_SCENE_BACKLIGHT,  /* 逆光场景 */

    PU_TYPICAL_SCENE_USER_1,     /* 用户自定义场景1*/
    PU_TYPICAL_SCENE_USER_2,     /* 用户自定义场景2*/
    PU_TYPICAL_SCENE_USER_3,     /* 用户自定义场景3*/
    PU_TYPICAL_SCENE_USER_4,     /* 用户自定义场景4*/
    PU_TYPICAL_SCENE_USER_5,     /* 用户自定义场景5*/
    PU_TYPICAL_SCENE_USER_6,     /* 用户自定义场景6*/
    PU_TYPICAL_SCENE_USER_7,     /* 用户自定义场景7*/
    PU_TYPICAL_SCENE_USER_8,     /* 用户自定义场景8*/

    PU_TYPICAL_SCENE_FOGGY = 14, /* 雾天场景 */
    PU_TYPICAL_SCENE_FACE = 15,  /* 人脸场景 */
    PU_TYPICAL_SCENE_NONE = 128, /* 不设置场景 */
    PU_TYPICAL_SCENE_MAX
}PU_TYPICAL_SCENE_MODE_E;

/* 码流套餐 */
typedef enum PU_STREAM_PROFILE_MODE
{
    PU_STREAM_PROFILE_DEFAULT = 0,      /* 默认 */
    PU_STREAM_PROFILE_HIGH_QUALITY,     /* 高清品质 */
    PU_STREAM_PROFILE_BALANCED,         /* 带宽平滑 */
    PU_STREAM_PROFILE_LOW_BANDWIDTH,    /* 低带宽 */
    PU_STREAM_PROFILE_MOBILE_DEVICE,    /* 移动设备 */

    PU_STREAM_PROFILE_USER_1,           /* 用户自定义场景1*/
    PU_STREAM_PROFILE_USER_2,           /* 用户自定义场景2*/
    PU_STREAM_PROFILE_USER_3,           /* 用户自定义场景3*/
    PU_STREAM_PROFILE_USER_4,           /* 用户自定义场景4*/
    
    PU_STREAM_PROFILE_MAX
}PU_STREAM_PROFILE_E;

//前端IPC模块
typedef enum IPC_MODULE
{
    IPC_WEB_MODULE = 0,     //WEB模块
    IPC_SDK_MODULE = 1,     //SDK模块
}PU_IPC_MODULE_E;

/* ISP通用开关 */
typedef enum PU_COMMONMODE_SWITCH
{
    MODE_OPEN = 0,               //打开模式
    MODE_CLOSE,                  //关闭模式
    MODE_AUTO,                   //自动模式
    MODE_MANUAL,                 //手动模式

    MODE_MAX
}PU_COMMONMODE_SWITCH_E;

//快门参数
typedef enum PU_CAM_SHUTTER_MODE
{
    PU_SHUTTER_MODE_1 = 0,          //快门值1秒
    PU_SHUTTER_MODE_2,              //快门值1/2秒
    PU_SHUTTER_MODE_4,              //快门值1/4秒，依次类推
    PU_SHUTTER_MODE_8,
    PU_SHUTTER_MODE_12,              
    PU_SHUTTER_MODE_15,
    PU_SHUTTER_MODE_25,
    PU_SHUTTER_MODE_30,
    PU_SHUTTER_MODE_50,
    PU_SHUTTER_MODE_60,
    PU_SHUTTER_MODE_90,
    PU_SHUTTER_MODE_100,
    PU_SHUTTER_MODE_120,
    PU_SHUTTER_MODE_125,
    PU_SHUTTER_MODE_180,
    PU_SHUTTER_MODE_250,
    PU_SHUTTER_MODE_350,
    PU_SHUTTER_MODE_500,
    PU_SHUTTER_MODE_725,
    PU_SHUTTER_MODE_1000,
    PU_SHUTTER_MODE_1500,
    PU_SHUTTER_MODE_2000,
    PU_SHUTTER_MODE_3000,
    PU_SHUTTER_MODE_4000,
    PU_SHUTTER_MODE_6000,
    PU_SHUTTER_MODE_10000,
    PU_SHUTTER_MODE_30000,
    PU_SHUTTER_MODE_100000,
    PU_SHUTTER_MODE_3 = 28,         //快门值1/3秒
    
    PU_SHUTTER_MODE_MAX
}PU_CAM_SHUTTER_MODE_E;

/*ISP场景类型*/
typedef enum PU_ISP_SCENE_TYPE
{
    ISP_SCNEN_NORMAL = 0,  //通用场景
    ISP_SCENE_OBJECT,           // 客观场景，用于型检
    ISP_SCENE_INDOOR,               // 室内场景
    ISP_SCENE_OUTDOOR,              // 室外场景
    ISP_SCENE_LOW_BRIGHT,           // 低照场景
    ISP_SCENE_BACK_LIGHT,           // 背光场景
    ISP_SCENE_VIRTUAL_BAYONET,      // 虚拟卡口场景
    ISP_SCENE_FOG,                  // 雾天场景
    ISP_SCENE_FACE,                 // 人脸应用场景 (当前针对人脸相机增加, 后续考虑是否增加应用模式修改
    ISP_SCENE_MAX
}PU_ISP_SCENE_TYPE_E;

//智能数据打包格式
typedef enum PU_IGT_DATA_TYPE
{
    XML_TYPE,
    META_TYPE,
}PU_IGT_DATA_TYPE_E;

// 外置灯类型
typedef enum PU_EXT_LAMP_TYPE
{
    PU_EXPOSURE_LAMP,     // 曝闪灯 
    PU_STROBE_LAMP,       // 频闪灯
}PU_EXT_LAMP_TYPE_E;

// 外置灯工作模式
typedef enum PU_EXT_LAMP_WORK_MODE
{
    PU_WORK_MODE_OFF,   // 常闭 
    PU_WORK_MODE_ON,    // 常亮 
}PU_EXT_LAMP_WORK_MODE_E;

// 曝光灯触发电平
typedef enum PU_EXP_LAMP_TRIG_LEVEL
{
    PU_TRIG_HIGH_LEVEL,    // 高电平触发
    PU_TRIG_LOW_LEVEL,     // 低电平触发
}PU_EXP_LAMP_TRIG_LEVEL_E;

/* 频闪灯频率*/
typedef enum PU_EXT_LAMP_FREQ
{
    PU_FREQ_50 = 0,    /* 50hz*/
    PU_FREQ_60,        /* 60hz*/
    PU_FREQ_100,       /* 100hz*/
    PU_FREQ_120,       /* 120hz*/
}PU_EXT_LAMP_FREQ_E;

/* 昼夜模式  */
typedef enum PU_VIDEO_BLACKWHITE_MODE
{
    PU_VIDEO_MODE_AUTO = 0,    //自动模式
    PU_VIDEO_MODE_COLOR,       //彩色模式
    PU_VIDEO_MODE_GRAY,        //黑白模式
    PU_VIDEO_MODE_NEGART
}PU_VIDEO_BLACKWHITE_MODE_E;

//码流套餐信息
typedef struct PU_STREAMPROFILES_INFO
{
	ULONG ulIndex;                                          //编号
	CHAR szName[STREAMPROFILES_NAME_LEN];                   //套餐名称名称
	CHAR szDescrip[STREAMPROFILES_NAME_LEN*2];              //描述
	CHAR szReserved[PU_RESERVE_LEN];  						//预留字段
}PU_STREAMPROFILES_INFO_S;

//码流套餐列表
typedef struct PU_STREAMPROFILES_INFO_LIST                           
{
	ULONG            ulStreamProfilesNum;									  //流套餐个数
	ULONG            ulStreamId;                                              //当前激活的码流套餐
	PU_STREAMPROFILES_INFO_S   szStreamProfile[STREAM_PROFILES_MAX];          //信息列表
	CHAR  szReserved[PU_RESERVE_LEN];  									      //预留字段
}PU_STREAMPROFILES_INFO_LIST_S;

/* 去雾等级 */
typedef enum PU_DEFOG_TYPR
{
	PU_DEFOG_TYPE_CLOSE = 0,    //关闭去雾
	PU_DEFOG_TYPE_LOW,          //低级去雾
	PU_DEFOG_TYPE_MIDDLING,     //中级去雾
	PU_DEFOG_TYPE_HIGH,         //高级去雾
	PU_DEFOG_TYPE_AUTO,         //自动去雾

	PU_DEFOG_TYPE_MAX
}PU_DEFOG_TYPE_E;

typedef enum PU_OPT_TYPE
{
	PU_OPT_TYPE_ADD = 0,                //新增  
	PU_OPT_TYPE_DEL = 1,                //删除	
	PU_OPT_TYPE_MOD = 2,                //修改
	PU_OPT_TYPE_MAX
}PU_OPT_TYPE_E;

typedef enum PU_DEV_OPT_TYPE
{
    PU_DEV_OPT_TYPE_REBOOT = 0,         // 重启
    PU_DEV_OPT_TYPE_FORMAT = 1,         //格式化磁盘
    PU_DEV_OPT_TYPE_MAX
}PU_DEV_OPT_TYPE_E;

/* SNMP版本 */
typedef enum PU_SNMP_VERSION_TYPE
{
    PU_SNMP_VERSION_V1 = 0,
    PU_SNMP_VERSION_V2C,
    PU_SNMP_VERSION_V3,

    PU_SNMP_VERSION_MAX
}PU_SNMP_VERSION_TYPE_E;

/* SNMP v1/v2c社团属性 */
typedef enum PU_SNMP_COMMUNITY_ATTR
{
    PU_SNMP_COMMUNITY_READONLY = 0,
    PU_SNMP_COMMUNITY_READWRITE,

    PU_SNMP_COMMUNITY_MAX
}PU_SNMP_COMMUNITY_ATTR_E;

/* SNMP v3 用户安全级别 */
typedef enum PU_SNMPV3_SECURITY_LEVEL
{
    PU_SNMPV3_SECURITY_NOAUTH = 0,   //未经授权
    PU_SNMPV3_SECURITY_AUTH,         //授权
    PU_SNMPV3_SECURITY_PRIV,         //私有密钥加密授权

    PU_SNMPV3_SECURITY_MAX
}PU_SNMPV3_SECURITY_LEVEL_E;

/* SNMP v3 Pwd认证协议 */
typedef enum PU_SNMPV3_AUTH_PROTOCOL
{
    PU_SNMPV3_AUTH_MD5 = 0,
    PU_SNMPV3_AUTH_SHA,
    PU_SNMPV3_AUTH_NONE,

    PU_SNMPV3_AUTH_MAX
}PU_SNMPV3_AUTH_PROTOCOL_E;

/* SNMP v3 私有密钥协议 */
typedef enum PU_SNMPV3_PRIV_PROTOCOL
{
    PU_SNMPV3_PRIV_DES = 0,
    PU_SNMPV3_PRIV_AES,
    PU_SNMPV3_PRIV_NONE,

    PU_SNMPV3_PRIV_MAX
}PU_SNMPV3_PRIV_PROTOCOL_E;

/********* 802.1x *********/
/* EAPOL版本号 */
typedef enum PU_DOT1X_EAPOL_VERSION
{
    PU_DOT1X_EAPOL_VERSION_1 = 1,
    PU_DOT1X_EAPOL_VERSION_2,

    PU_DOT1X_EAPOL_VERSION_MAX
}PU_DOT1X_EAPOL_VERSION_E;


/********* 看守位（全） *********/
typedef enum PU_GUARD_POINT_TYPE
{
	PU_GUARD_POINT_PRESET,       //预置位
	PU_GUARD_POINT_CRUISE,       //巡航轨迹
	PU_GUARD_POINT_USER_DEFINED, //花样扫描
	PU_GUARD_POINT_HORIZONTAL,   //水平扫描
	PU_GUARD_POINT_FRAME,        //帧扫描
	PU_GUARD_POINT_RANDOM,       //随机扫描
	PU_GUARD_POINT_PANORAMA,     //全景扫描
	PU_GUARD_POINT_VERTICAL,     //垂直扫描

	PU_GUARD_POINT_MAX
}PU_GUARD_POINT_TYPE_E;

typedef enum PU_PTZ_DIRECTION
{
	PU_PTZ_DIRECTION_UP,         //上
	PU_PTZ_DIRECTION_DOWN,       //下
	PU_PTZ_DIRECTION_LEFT,       //左
	PU_PTZ_DIRECTION_RIGHT,      //右

	PU_PTZ_DIRECTION_MAX
}PU_PTZ_DIRECTION_E;

typedef enum PU_PTZ_AUX_MODE
{
    PU_AUX_MODE_PROTOCOL = 0,              //雨刷协议模式
    PU_AUX_MODE_ALARMOUT = 1,              //开关量输出模式
    PU_AUX_MODE_TORRENTIAL_RAIN = 2,       //雨刷暴雨模式
    PU_AUX_MODE_MODERATE_RAIN = 3,         //雨刷中雨模式
    PU_AUX_MODE_BRUSH_FIVE_TIMES = 4,      //雨刷连刷5次
    PU_AUX_MODE_MAX
}PU_PTZ_AUX_MODE_E;

typedef enum PU_WEB_HTTP_MODE
{
    PU_WEB_HTTPS_HTTP = 0,                 //支持https & http
    PU_WEB_HTTPS_ONLY = 1,                 //只支持https
    PU_WEB_HTTP_MAX,
}PU_WEB_HTTP_MODE_E;

//用户类型
typedef enum PU_USER_TYPE
{
    PU_USER_TYPE_SYSTEM_ADMIN = 0,         //管理员
    PU_USER_TYPE_ADVANCED_OPERATOR,        //高级操作员
    PU_USER_TYPE_COMMON_OPERATOR,          //一般操作员
    PU_USER_TYPE_MAX
}PU_USER_TYPE_E;

//AF对焦模式
typedef enum PU_FOCUS_MODE
{
    PU_FOCUS_MODE_AUTO = 0,                //自动对焦模式
    PU_FOCUS_MODE_MANUAL = 1,              //手动对焦模式
    PU_FOCUS_MODE_TRIGGER = 2,             //半自动对焦模式

    PU_FOCUS_MODE_MAX
}PU_FOCUS_MODE_E;

typedef enum PU_CHAR_ENCODE_TYPE
{
    PU_CHAR_ENCODE_ANSI = 0,                //ANSI编码
    PU_CHAR_ENCODE_UTF_8 = 1,               //utf-8编码
    
    PU_CHAR_ENCODE_MAX,
}PU_CHAR_ENCODE_TYPE_E;

/* 白平衡模式 */
typedef enum PU_CAM_WB_MODE
{
    PU_WB_MODE_AUTO = 0,                 //自动    (环境比较稳定，色彩鲜艳)
    PU_WB_MODE_ATW,                      //自动跟踪  (白平衡差距大的地方)
    PU_WB_MODE_INDOOR,                   //室内
    PU_WB_MODE_OUTDOOR,                  //室外
    PU_WB_MODE_ONEPUSH_TRIGGER,          //一键触发
    PU_WB_MODE_MANUAL,                   //手动
	PU_WB_MODE_OUTDOOR_AUTO,             //室外自动
	PU_WB_MODE_SODIUM_VAPOR_LAMP_AUTO,   //钠灯自动
	PU_WB_MODE_SODIUM_VAPOR_LAMP,        //钠灯固定
	PU_WB_MODE_MERCURE_VAPOR_LAMP,       //汞水银灯
	PU_WB_MODE_FLUO_4200k,               // 4200k
	PU_WB_MODE_FLUORESCENTLAMP1,         //日光灯1 （2500~3500k）
	PU_WB_MODE_FLUORESCENTLAMP2,         //日光灯2 （3500~4500k）
	PU_WB_MODE_INCANDESCENTLAMP,         //白炽灯 2700~2900K
    PU_WB_MODE_SUNLIGHT,                 //太阳光

    PU_WB_MODE_MAX,                      
}PU_CAM_WB_MODE_E;

/* 宽动态模式 */
typedef enum PU_VIDEO_WD_MODE
{
    PU_WD_MODE_AUTO_WDR = 0,            //正常宽动态
    PU_WD_MODE_AUTO_ADWDR,              //修正暗色部分，宽动态增加了10db
    PU_WD_MODE_AUTO_CNT,                //宽动态由一副图像构成，图像处理
    PU_WD_MODE_AUTO_WDR_CNT,            //通过对比偏移来增加宽动态阶数
    PU_WD_MODE_AUTO_ADWDR_CNT,          //在对比偏移的基础上再增加10db
    PU_WD_MODE_RATIOFIX,                //短曝光快门速度固定，设置比例来确定长曝光
    PU_WD_MODE_HISTOGRAM,               //利用直方图来纠正过亮和过暗
    PU_WD_MODE_OFF_MODE,                //TI芯片专用，关闭
    PU_WD_MODE_FRAMESWITCH,             //TI芯片专用，帧切换
    PU_WD_MODE_STATIC_CHECK,            //TI芯片专用，静态模式
    PU_WD_MODE_DYNAMIC_CHECK,           //TI芯片专用，动态模式

    PU_WD_MODE_MAX
}PU_VIDEO_WD_MODE_E;

/* 日夜模式 */
typedef enum PU_IRC_MODE
{
    PU_IRC_MODE_COLOR = 0,           //彩色模式
    PU_IRC_MODE_GRAY,                //黑白模式
    PU_IRC_MODE_AUTO,                //自动模式

    PU_IRC_MODE_MAX
}PU_IRC_MODE_E;

/*日夜模式触发方式*/
typedef enum PU_IRC_TRIGGER_MODE
{
    PU_IRC_CAM_TRIGGER = 0,       //机芯触发
    PU_IRC_LUM_TRIGGER,           //光敏触发,默认光敏触发
    PU_IRC_SWITCH_TRIGGER,        //外部告警开关触发
    PU_IRC_TRIGGER_MAX
}PU_IRC_TRIGGER_MODE_E;

/* 增益类型 */
typedef enum PU_GAIN_TYPE
{
    PU_GAIN_TYPE_AUTO = 0,           //自动增益
    PU_GAIN_TYPE_DIGITAL,            //数字增益
    PU_GAIN_TYPE_ANALOG,             //模拟信号

    PU_GAIN_TYPE_MAX
}PU_GAIN_TYPE_E;

//光圈参数
typedef enum PU_IRIS_VALUE
{
    IRIS_VALUE_1_2 = 0,
    IRIS_VALUE_1_4,
    IRIS_VALUE_1_6,              //光圈值为F1.6
    IRIS_VALUE_2_0,              //光圈值为F2.0 依次类推
    IRIS_VALUE_2_3,
    IRIS_VALUE_2_4,
    IRIS_VALUE_2_8,
    IRIS_VALUE_3_2,
    IRIS_VALUE_3_4,
    IRIS_VALUE_4_0,
    IRIS_VALUE_4_5,
    IRIS_VALUE_4_8,
    IRIS_VALUE_5_6,
    IRIS_VALUE_6_4,
    IRIS_VALUE_6_8,
    IRIS_VALUE_8_0,
    IRIS_VALUE_9_1,
    IRIS_VALUE_9_6,
    IRIS_VALUE_11_0,
    IRIS_VALUE_14_0,
    IRIS_VALUE_16_0,
    IRIS_VALUE_22_0,
    IRIS_VALUE_32_0,
    IRIS_VALUE_CLOSE,           //光圈关闭

    IRIS_VALUE_MAX
}PU_IRIS_VALUE_E;

//最小聚焦距离(单位mm)
typedef enum PU_MIN_FOCUS
{
    PU_MIN_FOCUS_10    = 10,    //1cm
    PU_MIN_FOCUS_100   = 100,    
    PU_MIN_FOCUS_300   = 300,
    PU_MIN_FOCUS_500   = 500,
    PU_MIN_FOCUS_1000  = 1000,    //1m
    PU_MIN_FOCUS_1500  = 1500,
    PU_MIN_FOCUS_2000  = 2000,
    PU_MIN_FOCUS_3000  = 3000,
    PU_MIN_FOCUS_5000  = 5000,
    PU_MIN_FOCUS_6000  = 6000,
    PU_MIN_FOCUS_10000 = 10000,    //10m
    PU_MIN_FOCUS_20000 = 20000,
    PU_MIN_FOCUS_50000 = 50000,
    PU_MIN_FOCUS_100000 = 100000,    //100m

    PU_MIN_FOCUS_MAX
}PU_MIN_FOCUS_E;

typedef enum PU_IRIS_TYPE         
{ 
    PU_IRIS_TYPE_DC = 0,               //DC光圈
    PU_IRIS_TYPE_P_IRIS,               //P-iris光圈
    PU_IRIS_TYPE_MANUAL,               //手动
    PU_IRIS_TYPE_BUTT,
} PU_IRIS_TYPE_E; 
/*视频采集帧制式*/
typedef enum PU_FRAMERATE_FORMAT
{
    PU_FRAME_RATE_25F = 1,                  //25帧
    PU_FRAME_RATE_30F,                      //30帧
    PU_FRAME_RATE_50F,                      //50帧
    PU_FRAME_RATE_60F,                      //60帧
    PU_FRAME_RATE_MAX,
}PU_FRAMERATE_FORMAT_E;
/* 流套餐操作 */
typedef enum PU_STREAM_MANIPULATE_TYPE
{
	PU_STREAM_MANIPULATE_ADD = 0,      //增加
	PU_STREAM_MANIPULATE_DELETE,       //删除
	PU_STREAM_MANIPULATE_MODIFY,       //修改
    PU_STREAM_MANIPULATE_MAX
}PU_STREAM_MANIPULATE_TYPE_E;

//IP地址过滤协议
typedef enum PU_IP_PROTOCOL_TYPE
{
    PU_IP_PROTOCOL_TYPE_UDP = 0,              //UDP协议
    PU_IP_PROTOCOL_TYPE_TCP,                  //TCP协议
    PU_IP_PROTOCOL_TYPE_ICMP,                 //ICMP协议
    PU_IP_PROTOCOL_TYPE_ALL,                  //所有协议
    PU_IP_PROTOCOL_TYPE_MAX
}PU_IP_PROTOCOL_TYPE_E;

//IP过滤策略
typedef enum PU_IP_FILTER_STRATEGY
{
    PU_IP_FILTER_STRATEGY_ALLOW = 0,   //白名单方式
    PU_IP_FILTER_STRATEGY_DENY,        //黑名单方式
    PU_IP_FILTER_STRATEGY_MAX
}PU_IP_FILTER_STRATEGY_E;

/* 802.1x EAP-TLS证书上传类型 */
typedef enum PU_DOT1X_TLS_CERT_UPLOAD_TYPE
{
	PU_DOT1X_TLS_CA_CERT_UPLOAD_TYPE = 0,
	PU_DOT1X_TLS_CLIENT_CERT_UPLOAD_TYPE,

	PU_DOT1X_TLS_CERT_UPLOAD_TYPE_MAX
}PU_DOT1X_TLS_CERT_UPLOAD_TYPE_E;

/* SDK -TLS证书上传类型 */
typedef enum PU_SDK_TLS_CERT_UPLOAD_TYPE
{
	PU_SDK_TLS_CA_CERT_UPLOAD_TYPE = 0,
	PU_SDK_TLS_CLIENT_CERT_UPLOAD_TYPE,

	PU_SDK_TLS_CERT_UPLOAD_TYPE_MAX
}PU_SDK_TLS_CERT_UPLOAD_TYPE_E;

/* 背景更新速率 */
typedef enum PU_IGT_BG_UPDATE
{
    PU_BGUPDATE_LOW = 0,
    PU_BGUPDATE_MID,
    PU_BGUPDATE_HIGH,

    PU_BGUPDATE_MAX
}PU_IGT_BG_UPDATE_E;

typedef enum PU_IGT_OBJ_TRACK
{
    PU_OBJTRACK_LOW = 0,
    PU_OBJTRACK_MID,
    PU_OBJTRACK_HIGH,
    
    PU_OBJTRACK_MAX,
}PU_IGT_OBJ_TRACK_E;

/*抓拍图片格式*/
typedef enum PU_SNAPSHOT_FORMAT
{
    PU_SNAPSHOT_FORMAT_BMP = 0,
    PU_SNAPSHOT_FORMAT_JPEG
}PU_SNAPSHOT_FORMAT_E;

/* 上传类型 */
typedef enum PU_FTP_UPLOAD_PROTOCOL_TYPE
{
    PU_FTP_UPLOAD_PROTOCOL_TYPE_FTP = 0,
    PU_FTP_UPLOAD_PROTOCOL_TYPE_SFTP,

    FTP_UPLOAD_PROTOCOL_TYPE_MAX
}PU_FTP_UPLOAD_PROTOCOL_TYPE_E;

/* 目录结构 */
typedef enum PU_FTP_UPLOAD_DIR_TYPE
{
    PU_FTP_UPLOAD_DIR_TYPE_ROOT_DIR = 0,   //上传到根目录
    PU_FTP_UPLOAD_DIR_TYPE_FIRST_DIR,      //上传到一级目录
    PU_FTP_UPLOAD_DIR_TYPE_SECOND_DIR,     //上传到二级目录 
    PU_FTP_UPLOAD_DIR_TYPE_THIRD_DIR,      //上传到三级目录
    PU_FTP_UPLOAD_DIR_TYPE_FOURTH_DIR,     //上传到四级目录
    FTP_UPLOAD_DIR_TYPE_MAX
}PU_FTP_UPLOAD_DIR_TYPE_E;

/* 一级目录类型 */
typedef enum PU_FTP_UPLOAD_FIRST_DIR_TYPE
{
    PU_FTP_UPLOAD_FIRST_DIR_TYPE_IP = 0,   //一级目录为设备IP
    PU_FTP_UPLOAD_FIRST_DIR_TYPE_SELF,     //一级目录为自定义

    FTP_UPLOAD_FIRST_DIR_TYPE_MAX
}PU_FTP_UPLOAD_FIRST_DIR_TYPE_E;

/* 二级目录类型 */
typedef enum PU_FTP_UPLOAD_SECOND_DIR_TYPE
{
    PU_FTP_UPLOAD_SECOND_DIR_TYPE_CHANNEL = 0, //二级目录为通道号
    PU_FTP_UPLOAD_SECOND_DIR_TYPE_SELF,        //二级目录为自定义

    PU_FTP_UPLOAD_SECOND_DIR_TYPE_MAX
}PU_FTP_UPLOAD_SECOND_DIR_TYPE_E;

/* 上传文件命名规则 */
typedef enum PU_FTP_UPLOAD_FILE_NAMING_RULE
{
    PU_FTP_UPLOAD_FILE_NAMING_RULE_DATE = 0,   //以时间命名

    PU_FTP_UPLOAD_FILE_NAMING_RULE_MAX
}PU_FTP_UPLOAD_FILE_NAMING_RULE_E;

//变倍变焦动作控制
typedef enum PU_CamControl             
{
    PU_CAM_CONTROL_UP = 0,
    PU_CAM_CONTROL_DOWN,
    PU_CAM_CONTROL_STOP
} PU_CAMCTRL_E;

typedef enum PU_CACHERECORD
{
    PU_RECORD_CLOSE = 0,
    PU_RECORD_OFFLINE,
    PU_RECORD_MAX
}PU_CACHERECORD_E;

//OSDI操作类型
typedef enum PU_OSDI_OPTYPE
{
    PU_OSDI_AREA_ADD = 0,           //增加OSDI区域
    PU_OSDI_AREA_DEL = 1,           //删除OSDI区域
    PU_OSDI_AREA_MOD = 2,           //修改OSDI区域
    PU_OSDI_AREA_ENABLE = 3,        //使能OSDI区域
    PU_OSDI_MOVE_TO_AREA = 4,       //移动到某个OSDI区域
    PU_OSDI_BUSINESS_ENABLE = 5,    //OSDI总开关使能
    PU_OSDI_GET_CUR_CONFIG = 6,     //获取当前OSDI配置           
}PU_OSDI_OPTYPE_E;

//抓拍图片质量
typedef enum PU_SNAPSHOT_QUALITY
{
    PU_QUAILTY_BEST = 0,            
    PU_QUAILTY_MORE_BETTER,
    PU_QUAILTY_BETTER,
    PU_QUAILTY_ORDINARY,
    PU_QUAILTY_LOW,
    PU_QUAILTY_WORST,
    PU_QUAILTY_MAX
}PU_SNAPSHOT_QUALITY_E;

//流量整形系数
typedef enum PU_TS_COEFFICIENT
{
    PU_TS_COEFFICIENT_11 = 11,
    PU_TS_COEFFICIENT_12 = 12,
    PU_TS_COEFFICIENT_13 = 13,
    PU_TS_COEFFICIENT_14 = 14,
    PU_TS_COEFFICIENT_15 = 15,
    PU_TS_COEFFICIENT_16 = 16,
    PU_TS_COEFFICIENT_17 = 17,
    PU_TS_COEFFICIENT_18 = 18,
    PU_TS_COEFFICIENT_19 = 19,
    PU_TS_COEFFICIENT_20 = 20,
    PU_TS_COEFFICIENT_21 = 21,
    PU_TS_COEFFICIENT_22 = 22,
    PU_TS_COEFFICIENT_23 = 23,
    PU_TS_COEFFICIENT_24 = 24,
    PU_TS_COEFFICIENT_25 = 25,
    PU_TS_COEFFICIENT_26 = 26,
    PU_TS_COEFFICIENT_27 = 27,
    PU_TS_COEFFICIENT_28 = 28,
    PU_TS_COEFFICIENT_29 = 29,
    PU_TS_COEFFICIENT_30 = 30,
    PU_TS_COEFFICIENT_31 = 31,
    PU_TS_COEFFICIENT_32 = 32,
    PU_TS_COEFFICIENT_33 = 33,
    PU_TS_COEFFICIENT_34 = 34,
    PU_TS_COEFFICIENT_35 = 35,
    PU_TS_COEFFICIENT_36 = 36,
    PU_TS_COEFFICIENT_37 = 37,
    PU_TS_COEFFICIENT_38 = 38,
    PU_TS_COEFFICIENT_39 = 39,
    PU_TS_COEFFICIENT_40 = 40,
}PU_TS_COEFFICIENT_E;

//夏令时实施方式
typedef enum PU_DST_TYPE
{
    DST_WEEK_WAY = 0,
    DST_DATE_WAY = 1,
    DST_TYPE_MAX = 2,
}PU_DST_TYPE_E;

//夏令时偏移量
typedef enum PU_DST_OFFSET
{
    OFFSET_NONE    = 0,
    OFFSET_30_MIN  = 30,
    OFFSET_60_MIN  = 60,
    OFFSET_90_MIN  = 90,
    OFFSET_120_MIN = 120,
}PU_DST_OFFSET_E;

//ONVIF鉴权类型
typedef enum PU_ONVIF_AUTH_TYPE
{
    AUTH_TYPE_DIGGEST           = 0,    //仅支持Diggest认证
    AUTH_TYPE_DIGGEST_AND_WSSE  = 1,    //同时支持Diggest认证、WSSE认证，Diggest认证优先
    AUTH_TYPE_NONE              = 2,    //不鉴权
    AUTH_TYPE_WSSE              = 3,    //仅支持WSSE认证
    AUTH_TYPE_MAX,
}PU_ONVIF_AUTH_TYPE_E;

//车牌颜色
typedef enum PU_LPR_PLATE_COLOR
{
    PU_LPR_LC_UNKNOWN   = 0,     // 未知
    PU_LPR_LC_BLUE      = 1,     // 蓝色
    PU_LPR_LC_YELLOW    = 2,     // 黄色
    PU_LPR_LC_WHITE     = 3,     // 白色
    PU_LPR_LC_BLACK     = 4,     // 黑色
    PU_LPR_LC_GREEN     = 5,     // 绿色
    PU_LPR_LC_GRADIENT_GREEN = 6,//渐变绿底黑字
    PU_LPR_LC_YELLOW_GREEN   = 7,//黄绿双拼底黑字
}PU_PLATE_COLOR_E;

//车牌类型
typedef enum PU_LPR_PLATE_TYPE
{
    PU_LPR_PLT_UNKNOWN       = 0,  //未知类型
    PU_LPR_PLT_NORMBLUE      = 1,  //普通蓝牌
    PU_LPR_PLT_NORMBLACK     = 2,  //普通黑牌
    PU_LPR_PLT_NORMYELLOW    = 3,  //普通单层黄牌
    PU_LPR_PLT_DBLYELLOW     = 4,  //双层黄牌
    PU_LPR_PLT_POLICE        = 5,  //白色警牌
    PU_LPR_PLT_WJ            = 6,  //白色武警
    PU_LPR_PLT_DBLWJ         = 7,  //双层白色武警
    PU_LPR_PLT_ARMY          = 8,  //单层军牌
    PU_LPR_PLT_DBLARMY       = 9,  //双层军牌
    PU_LPR_PLT_EMBASSY       = 10, //领使馆牌
    PU_LPR_PLT_HK            = 11, //港牌
    PU_LPR_PLT_MACAU         = 13, //澳门牌
    PU_LPR_PLT_AGRICULTURE   = 14, //农用车牌 拖拉机
    PU_LPR_PLT_CHANGNEI      = 15, //厂内牌
    PU_LPR_PLT_INDIVI        = 16, //个性化车牌
    PU_LPR_PLT_NEWNENRGY     = 17, //新能源牌  
    PU_LPR_PLT_OTHER         = 18, //其他类型
	
	PU_VLPR_LPT_INA_PRIVATE  = 100,  //印尼私家车
	PU_VLPR_LPT_INA_PUBLIC   = 101,  //印尼公共交通
	PU_VLPR_LPT_INA_EMBASSY  = 102,  //印尼使馆牌
	PU_VLPR_LPT_KSA_PRIVATE  = 110,  //沙特车牌
	PU_VLPR_LPT_HK_PRIVATE   = 120,   //香港车牌

}PU_PLATE_TYPE_E;

//车身颜色
typedef enum PU_VEHICLE_COLOR
{
    PU_LPR_VC_NOT,      //未知

    PU_LPR_VC_WHITE,    //白色
    PU_LPR_VC_GRAY,     //灰色(银色)
    PU_LPR_VC_YELLOW,   //黄色
    PU_LPR_VC_PINK,     //粉色
    PU_LPR_VC_RED,      //红色
    PU_LPR_VC_GREEN,    //绿色
    PU_LPR_VC_BLUE,     //蓝色
    PU_LPR_VC_BROWN,    //棕色
    PU_LPR_VC_BLACK,    //黑色
    PU_LPR_VC_PURPLE,   //紫色
    PU_LPR_VC_ORANGE,   //桔色
    PU_LPR_VC_CYAN,     //青色
    PU_LPR_VC_GOLDEN,   //金色
    PU_LPR_VC_SILVER,   //银色
}PU_VEHICLE_COLOR_E;

//车辆类型
typedef enum PU_VEHICLE_TYPE
{
	PU_LPR_VT_NOT, //未知
	PU_LPR_VT_CAR, //轿车 占位
	PU_LPR_VT_TRUCK, //货车 占位
	PU_LPR_VT_VAN, //面包车
	PU_LPR_VT_PAS, //客车
	PU_LPR_VT_BUGGY, //小货车 占位
	PU_LPR_VT_SUV, //SUV 占位
	PU_LPR_VT_MEDIUM_BUS, //中型客车
	PU_LPR_VT_MOT, //摩托车-非机动车
	PU_LPR_VT_PEDESTRAIN, //行人
	PU_LPR_VT_SCHOOL_BUS, //校车
	PU_LPR_VT_HEAVY_TRUCK, //泥头车-渣土车
	PU_LPR_VT_TANKER, //高危车
	PU_LPR_VT_RIDEMAN, //骑行人 占位
	//=================以上是老版本支持

	PU_VLPR_VT_CAR_M, //微型轿车
	PU_VLPR_VT_CAR_L, //小型轿车
	PU_VLPR_VT_CAR_S, //紧凑型轿车
	PU_VLPR_VT_CAR_TWO, //两厢轿车
	PU_VLPR_VT_CAR_THR, //三厢轿车

	PU_VLPR_VT_SUV_QINGKE, //轻客

	PU_VLPR_VT_SUV_L, //小 型SUV
	PU_VLPR_VT_SUV_S, //紧凑型SUV
	PU_VLPR_VT_SUV_Z, //中型SUV
	PU_VLPR_VT_SUV_M, //中大型SUV 
	PU_VLPR_VT_SUV_B, //大型SUV

	PU_VLPR_VT_WEIMIAN, //微型面包车

	PU_VLPR_VT_MPV, //MPV
	PU_VLPR_VT_JP, //轿跑

	PU_VLPR_VT_WEIKA, //微卡
	PU_VLPR_VT_SUV_PIKA, //皮卡
	PU_VLPR_VT_TRUCK_Z, //中卡
	PU_VLPR_VT_TRUCK_KEI, //轻卡
	PU_VLPR_VT_ZHONGKA, //重卡

	PU_VLPR_VT_TAXI, //出租车 
	PU_VLPR_VT_TANK, //油罐车
	PU_VLPR_VT_CRANE, //吊车

	PU_LPR_VT_ALL = 512 //全部
}PU_VEHICLE_TYPE_E;

//车牌移动方向
typedef enum PU_PLATE_DIR
{
	PU_LPR_UNKNOWN = 0,             //未知
	PU_LPR_LEFT = 1,                //左
	PU_LPR_RIGHT = 2,		        //右
	PU_LPR_UP = 3,					//上
	PU_LPR_DOWN = 4,				//下
}PU_PLATE_DIR_E;

//车辆方向定义
typedef enum PU_VEHICLE_DIR
{
	PU_VLPR_VD_HEAD = 0,                //车头方向
	PU_VLPR_VD_TAIL = 1,                //车尾方向
	PU_VLPR_VD_HEAD_AND_TAIL = 2        //双向
}PU_VEHICLE_DIR_E;

typedef enum PU_VLPR_CATCH_MODE
{
    PU_VLPR_MODE_MOTORWAY = 0,        //机动车模式
    PU_VLPR_MODE_COEXISTED = 1,       //机非人模式 Coexisted motorway-bicycle lane-sidewalk
}PU_VLPR_CATCH_MODE_E;

// 车牌抓拍算法类型
typedef enum PU_VLPR_ALG_MODE
{
    PU_VLPR_ALG_CHINESE,      // 中国车牌
    PU_VLPR_ALG_EURO,         // 欧洲车牌
    PU_VLPR_ALG_INA,          // 印尼车牌
    PU_VLPR_ALG_MAX,
} PU_VLPR_ALG_MODE_E;

typedef enum BACKLIGHT_MODE
{ 
    VIDEO_MODE_AVERAGE = 0,     //背光区域为默认设置
    VIDEO_MODE_CENTER,          //背光区域为画面中心区域 
    VIDEO_MODE_UP,              //背光区域为画面上部区域, 该变量作为预留
    VIDEO_MODE_DOWN,            //背光区域为画面下部区域, 该变量作为预留
    VIDEO_MODE_LEFT,            //背光区域为画面左部区域, 该变量作为预留
    VIDEO_MODE_RIGHT,           //背光区域为画面右部区域, 该变量作为预留
    VIDEO_MODE_USER             //背光区域为自定义区域
}BACKLIGHT_MODE_E;

typedef enum PTZ_OSD_MODE
{
    PTZ_OSD_NONE,               //不显示
    PTZ_OSD_PTZ_INFO,           //云镜信息模式
    PTZ_OSD_ORIENTATION,        //方位角模式
    PTZ_OSD_POSITION,           //经纬度模式
    PTZ_OSD_ZOOM,               //变倍信息模式
}PTZ_OSD_MODE_E;

//补光灯IO模式
typedef enum  PU_SUPPLEMENT_LIGHT_LAMP_IO_MODE
{
	PU_IO_CONTINUE_MODE = 0,
	PU_IO_MODE_MAX
} PU_SUPPLEMENT_LIGHT_LAMP_IO_MODE_E;

//补光灯控制模式
typedef enum  PU_SUPPLEMENT_LIGHT_LAMP_CTRL_MODE
{
	PU_CONTROL_DISABLE_MODE = 0,
	PU_CONTROL_AUTO_MODE,
	PU_CONTROL_TIME_MODE,
	PU_CONTROL_MODE_MAX
} PU_SUPPLEMENT_LIGHT_LAMP_CTRL_MODE_E;

typedef enum PU_ISP_IRCUT_MODULE           
{ 
    PU_IRCUT_MODE_DUMMY = 0,         //彩色模式
    PU_IRCUT_MODE_NIGHT,           //黑白模式
    PU_IRCUT_MODE_DEFOG,         //光学透雾(部分设备支持)
    PU_IRCUT_MODE_MAX
} PU_ISP_IRCUT_MODULE_E;

//告警联动PTZ优先级
typedef enum PU_ALARM_LINK_PTZ_PRIORITY
{
    PU_GUARD_FIRST = 0, //守望优先    --> 当守望时间到时，直接触发，无论当前是否在告警
    PU_ALARM_FIRST,     //告警联动优先 --> 当告警发生到告警结束，守望不生效
    PU_LINK_MAX,
}PU_ALARM_LINK_PTZ_PRIORITY_E;

//人脸人体检测模式
typedef enum PU_FACE_DETECTION_DL_MODE
{
    FACE_MODE = 0,  //人脸检测
    BODY_MODE,      //人体检测
    FACE_BODY_MODE, //人脸、人体检测
}PU_FACE_DETECTION_DL_MODE_E;

//绊线方向
typedef enum PU_TRIPWIRE_DIR
{
	PU_TRIPWIRE_CLOCKWISE = 0,    // 向量顺时针越线
	PU_TRIPWIRE_ANTICLOCKWISE,     // 向量逆时针越线
	PU_TRIPWIRE_MAX
}PU_TRIPWIRE_DIR_E;

typedef enum PU_TABLE_TYPE
{
	PU_TABLE_DAY,			//日报表
	PU_TABLE_WEEK,			//周报表
	PU_TABLE_MONTH,		//月报表
	PU_TABLE_YEAR			//年报表
}PU_TABLE_TYPE_E;

typedef enum  PU_SUPPLEMENTLAMP_TYPE
{
     PU_TYPE_LAMP_WHITE= 0, //白光灯
     PU_TYPE_LAMP_RED,   //红外灯
     PU_TYPE_LAMP_MAX
} PU_SUPPLEMENTLAMP_TYPE_E;

//补光灯手、自动模式控制
typedef enum  PU_LAMP_CTRL_MODE
{
    LAMP_CTRL_MODE_AUTO = 0,                   //自动
    LAMP_CTRL_MODE_MANUAL,                     //手动
} PU_LAMP_CTRL_MODE_E;


typedef enum 
{
    SINGLE_PACKET     = 0xAA,
    SLICE_HEAD_PACKET = 0xBB,
    SLICE_MID_PACKET  = 0xCC,
    SLICE_TAIL_PACKET = 0xDD,
    META_DATA_PACKET_TYPE_MAX = 0xFF
} META_DATA_PACKET_TYPE_E;

#define MAX_POINT_NUM (10)
// 第一层元数据TYPE
typedef enum LAYER_ONE_TYPE
{
    METADATA_TYPE = 0x4154454D, // 'M''E''T''A' 小端序
} LAYER_ONE_TYPE_E;

// 第二层元数据TYPE
typedef enum LAYER_TWO_TYPE
{
	COMMON  = 0x00000001, // 通用
	TARGET  = 0x00000002, // 目标(车、人、人脸等等) 
	RULE    = 0x00000003, // 规则(设定的规则框)
	TALARM  = 0x00000004, // 智能报警
	TRECORD = 0x00000005  // 智能触发录像
} LAYER_TWO_TYPE_E;

typedef enum LAYER_THREE_TYPE
{
	PTS                 = 0x09000001, // 时间戳
    ITGT_TYPE           = 0x07000011, // 智能类型
    IMG_WIDTH           = 0x07000100, // 处理图片宽
    IMG_HEIGHT          = 0x07000101, // 处理图片高

    FACE_SCORE          = 0x04000013, // 人脸置信度
    FACE_ANGLE          = 0x04000014, // 人脸角度
    FACE_ID             = 0x07000016, // 人脸ID
    FACE_PANOPIC_SIZE   = 0x07000018, // 人脸全景图片大小
    FACE_FACEPIC_SIZE   = 0x07000019, // 人脸抠图图片大小
    FACE_PIC_TIME       = 0x08000015, // 人脸抠图产生时间
    FACE_PIC_TZONE      = 0x08000020, // 人脸抠图设备时区(单位ms 东区为+ 西区为-)
    HUMAN_FEATURE       = 0x10000002, // 人体属性
    FACE_FEATURE		= 0x11000003, // 人脸属性
    PANORAMA_PIC        = 0x0A00000A, // 全景图片
    FACE_PIC            = 0x0A000012, // 人脸抠图
	FACE_PIC_KPS		= 0x07000012, // 人脸抠图kps质量过滤标志位
    HUMAN_PIC           = 0x0A000013, // 人体抠图
	HUMAN_PIC_KPS		= 0x07000013, // 人体抠图kps质量过滤标志位
	HUMAN_PIC_ROI       = 0x0B000017, // 人体抠图中的人体目标框
    FACE_PANORAMA       = 0x0A000017, // 人脸全景
    FACE_PIC_POSITION   = 0x0B000011, // 人脸抠图小框位置
    FACE_POS            = 0x0B000012, // 人脸位置(实时位置框)
    HUMAN_RECT          = 0x0B000013, // 人体位置(实时位置框)
    HUMAN_RECT_POSITION = 0x0B000014, // 人体抠图小框位置
  
    FACE_MATCH          = 0x0A000014, // 人脸数据库中匹配图片
    FACELIB_RECORDID    = 0x07000017, // 名单库中的人脸ID，用来维持特征 record的一致性
    FACE_MATCHRATE      = 0x07000020, // 人脸匹配率
    FACE_INFO           = 0x12000001, // 人脸信息,对应数据库中信息
    FACE_LIB_TYPE       = 0x07000022, // 名单库类型
    FACE_LIB_NAME       = 0x0A000015, // 名单库名字
    TARGET_TYPE         = 0x07000023, // target类型，当前用于区分人脸后处理抠图和人脸识别以及人脸识别多机协同
    FACE_LIB_ID        = 0x07000024, // 名单库ID
    MMC_FACE_COMPARE_NUM_MAX = 0x07000025, //多机协同算法参数- 人脸比对数据
    MMC_FACE_WARNING_RECALL_RATE_MAX = 0x07000026, //多机协同算法参数- 人脸上报告警的召回率
    MMC_FACE_WARNING_RECALL_RATE_MIN = 0x07000027, //多机协同算法参数- 人脸预警率的下限值

    OBJ_ID              = 0x07000021, // 目标ID
    OBJ_STATUS          = 0x06000022, // 目标状态
    OBJ_POS             = 0x0B000023, // 目标位置
    OBJ_TYPE            = 0x06000024, // 目标类型
    OBJ_SPEED           = 0x0C000025, // 目标速度
    OBJ_UPHALF_COLOR    = 0x0F000026, // 目标上半部颜色
    OBJ_DOWNHALF_COLOR  = 0x0F000027, // 目标下半部颜色
    RULE_TYPE           = 0x07000031, // 规则类型
    RULE_LINE_POS       = 0x0D000032, // 规则线位置
    RULE_LINE_DIR       = 0x07000033, // 规则线方向
    RULE_AREA_POS       = 0x0E000034, // 规则框位置
    OBJ_POS_R           = 0x0B000035, // 目标位置(相对位置)
	OBJ_SPEED_R         = 0x0C000036, // 目标速度(相对位置)
	RULE_LINE_POS_R     = 0x0D000037, // 规则线位置(相对位置)
	RULE_AREA_POS_R     = 0x0E000038, // 规则框位置(相对位置)

	LANE_ID             = 0x07000002, // 车道号
	VEHICLE_TYPE        = 0x07000003, // 车辆类型
	VEHICLE_TYPE_EXT    = 0x07000406, //C50车辆类型
	VEHICLE_COLOR       = 0x07000004, // 车辆颜色
	VEHICLE_DIRECTION   = 0x07000005, // 车辆行驶方向
	VEHICLE_POS         = 0x0B000005, // 车辆位置
	PLATE_TYPE          = 0x07000006, // 车牌类型
	PLATE_POS           = 0x0B000007, // 车牌位置
	PLATE_CHAR          = 0x0A000008, // 车牌字符
	PLATE_PIC           = 0x0A000009, // 车牌抠图
	PLATE_CONFIDENCE    = 0x07000061, // 车牌置信度
	PLATE_COLOR         = 0x07000062, // 车牌颜色
	PLATE_CHAR_POS      = 0x0B000063, // 车牌字符位置
	PLATE_FACE_POS      = 0x0B000064, // 车脸位置
	PLATE_MOVE_DIR      = 0x07000065, // 车牌运动方向
	PLATE_SNAPSHOT_TYPE = 0x07000066, // 车牌抓拍类型
	VEHICLE_PIC         = 0x0A000067, // 车辆特写图
	PIC_SNAPSHOT_TIMEMS = 0x09000003, // 抓拍时间(单位ms)
	PIC_SNAPSHOT_TIME   = 0x07000068, // 抓拍时间
	PIC_SNAPSHOT_TZONE  = 0x08000069, // 设备时区(单位ms 东区为+ 西区为-)
	DEVICE_ID           = 0x0A000025,    //设备编号
	ROID_ID             = 0x0A000026,    //道路编号
	DIR_ID              = 0x0A000027,    //方向编号
	DIR_INFO            = 0x0A000028,    //方向信息
	PANORAMA_PIC_SIZE   = 0x07000073,  //全景图大小
	PLATE_PIC_SIZE      = 0x07000074,    //车牌图大小
	VLPR_ALG_TYPE       = 0x07000079, // 车牌算法类型
	REGULATION_CODE     = 0x0A000029,//违章代码字符串

    ITS_TYPE            = 0x04000032, // ITS 应用模式
    VEHICLE_TL_X        = 0x0400002A, // 车辆位置左上角X坐标
    VEHICLE_TL_Y        = 0x0400002B, // 车辆位置左上角Y坐标
    VEHICLE_BR_X        = 0x0400002C, // 车辆位置右下角X坐标
    VEHICLE_BR_Y        = 0x0400002D, // 车辆位置右下角Y坐标
    PLATE_TL_X          = 0x0400002E, // 车牌位置左上角X坐标
    PLATE_TL_Y          = 0x0400002F, // 车牌位置左上角Y坐标
    PLATE_BR_X          = 0x04000030, // 车牌位置右下角X坐标
    PLATE_BR_Y          = 0x04000031, // 车牌位置右下角Y坐标

    MICRO_PORT_TRAFFIC_STATISTICS                       = 0x070000A0,//车流量统计参数
    MICRO_PORT_TRAFFIC_STATISTICS_LANE_COUNT            = 0x070000A1,//微卡口车流量统计车道数量
    MICRO_PORT_TRAFFIC_STATISTICS_LANE_INDEX            = 0x070000A2,//微卡口车流量统计当前车道
    MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_COUNT         = 0x070000A3,//车辆计数
    MICRO_PORT_TRAFFIC_STATISTICS_AVG_SPEED             = 0x070000A4,//平均速度
    MICRO_PORT_TRAFFIC_STATISTICS_LANE_TIME_USED_RATIO  = 0x070000A5,//车道时间占有率
    MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_DENSITY       = 0x070000A6,//车流密度
    MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_HEAD_INTERVAL = 0x070000A7,//车头时间间隔
    MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_HEAD_SPACE_INTERVAL = 0x070000A8,//车头间隔
    MICRO_PORT_TRAFFIC_STATISTICS_CONGESTION_DEGREE     = 0x070000A9,//交通状态
    MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE1_COUNT   = 0x070000AA,//大型车数量
    MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE2_COUNT   = 0x070000AB,//中型车数量
    MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE3_COUNT   = 0x070000AC,//小型车数量
    MICRO_PORT_TRAFFIC_STATISTICS_QUEUE_LENGTH          = 0x070000AD,//排队长度
    MICRO_PORT_TRAFFIC_STATISTICS_LANE_SPACE_USED_RATIO = 0x070000AE,//车道空间占有率
    ITS_TRAFFIC_LEFT_VEHICLE_COUNT     = 0x070000AF, //its左转车数量
    ITS_TRAFFIC_STRAIGHT_VHEICLE_COUNT = 0x070000B0, //its直行车数量
    ITS_TRAFFIC_RIGHT_VHEICLE_COUNT    = 0x070000B1, //its右转车数量
    ITS_TRAFFIC_TIME_ZONE              = 0x070000B2, //its车流量统计时区
    ITS_TRAFFIC_SNAP_TIME              = 0x070000B3, //its车流量统计抓拍时间
	VEHICLE_SPEED       = 0x07000075,   //车辆速度
	REGULATION_TYPE     = 0x07000076,   //违章类型
	ITS_FLOWRATE_FEATURE = 0x07000077, //its流量统计属性
	VEHICLE_MFR_TYPE     = 0x07000078,   //机动车二次特征
    ITS_VEHICLE_FLOWRATE_FEATURE = 0x0700009A, //its车流量统计属性

    MFR_MAIN_CALL       = 0x06000025,  //主驾驶打电话
    MFR_MAIN_BELT       = 0x06000026,  //主驾驶安全带
    MFR_VICE_EXIST      = 0x06000027,  //是否有副驾驶
    MFR_VICE_BELT       = 0x06000035,  //副驾驶安全带
    MFR_YEAR_LOG        = 0x06000036,  //年检标
    MFR_MAIN_SUN_VISOR  = 0x06000030,  //主驾驶遮阳板
    MFR_VICE_SUN_VISOR  = 0x06000031,  //副驾驶遮阳板
    MFR_NAP_KIN_BOX     = 0x06000032,  //纸巾盒
    MFR_CAR_PENDANT     = 0x06000034,  //挂件

    ITS_TRAFFIC_STATE    = 0x07000079,  //车道交通状态
	CARDETECTION_POS    = 0x0B000015, //停车位置
	HUMANCOUNT_NUM		= 0x0B000016, //过线人数

	VEHICLE_BODY_RECT   = 0x0B000008, // 车身位置
	NOMOTOR_BODY_RECT   = 0x0B000009, // 非机动车车身位置

	CAR_PRE_BRAND       = 0x0A000007, // 品牌字符 （大  众）
	CAR_SUB_BRAND       = 0x0A000022, // 子款字符 （桑塔纳）
	CAR_TYPE_BRAND      = 0x0A000023, // 车型字符 （轿  车）
	CAR_YEAR_BRAND      = 0x0A000024, // 年款字符 （2011）
	VHD_OBJ_ID          = 0x09000006, //机非人ID
	CAR_PRE_BRAND_INDEX = 0x06000028, // 品牌字符索引 （大  众）
	CAR_SUB_BRAND_INDEX = 0x06000029, // 子款字符索引 （桑塔纳）

	DEV_CNT				= 0x03000070, // 设备数
	CHAN_ID				= 0x03000071, // 通道号

	SHOULDER_RECT = 0x0B000018, // 头肩位置(排队长度)
	SHOULDER_NUM = 0x06000001, // 头肩个数（排队长度）
	QUEUE_TIME = 0x06000002, // 排队时长

	PEOPLE_NUM          = 0X07000087, //人群密度检测算法人数
    HEADSHOULDER_POS    = 0X0B000088, //人群密度检测算法返回框的地址
    AREARATIO           = 0X07000089, //人群密度检测算法人群密度
    TRACK_OBJECT        = 0x07000028, //跟踪目标id
    SEX                 = 0X0700008A, //性别
    AGE                 = 0X0700008B, //年龄
    META_GLASSES        = 0X0700008C, //眼镜
    MOUTHMASK           = 0X0700008D, //口罩
    UMBRELLA            = 0X0700008E, //雨伞
    BACKPACK            = 0X0700008F, //背包
    SHAPE               = 0X07000090, //体型
    HAIR                = 0X07000091, //发型
    SATCHEL             = 0X07000092, //挎包
    LUGGAGE             = 0X07000093, //行李
    CARRY               = 0X07000094, //手拎物
    MOVEDIRECT		    = 0X07000095, //行进方向
    UPPERSTYLE          = 0X07000096, //上衣款色
    UPPERCOLOR          = 0X07000097, //上衣颜色
    LOWERSTYLE	        = 0X07000098, //下衣款色
    LOWERCOLOR          = 0X07000099, //下衣颜色
    CHANNEL_ID          = 0x09000078  //相机通道号
} LAYER_THREE_TYPE_E;


/*灯类型*/
typedef enum PU_RL_LIGHT_TYPE
{
    RL_TYPE_DISC = 1,                             //圆盘
    RL_TYPE_ARROW,                                //箭头
    RL_TYPE_NUMBER,                               //倒计时
    RL_TYPE_MAX,
} PU_RL_LIGHT_TYPE_E;

/*灯状态*/
typedef enum PU_RL_LIGHT_STATUS
{
    RL_STATUS_GREEN = 0,                             //绿灯
    RL_STATUS_RED,                                   //红灯
    RL_STATUS_MAX,
} PU_RL_LIGHT_STATUS_E;

/* AES 密钥类型*/
typedef enum PU_AES_KEY_MODULE
{
	PU_AES_KEY_MODULE_WEB = 0,                //WEB
	PU_AES_KEY_MODULE_ONVIF,                  //ONVIF
	PU_AES_KEY_MODULE_T28181,                 //T28181
	PU_AES_KEY_MODULE_CA_PWD,                 //CA证书 
	PU_AES_KEY_MODULE_8021X,                  //8021X
	PU_AES_KEY_MODULE_SNMP,                   //SNMP
	PU_AES_KEY_MODULE_DDNS,                   //DDNS
	PU_AES_KEY_MODULE_SDK,                    //SDK
	PU_AES_KEY_MODULE_FACE_REC_DATABASE = 15, //人脸识别数据库
	PU_AES_KEY_MODULE_MAX
} PU_AES_KEY_MODULE_E;

typedef enum PU_FACE_PACKET_TYPE
{
    FACE_PACKET_TYPE_PICMODE = 0,        // 图片 + 人员信息
    FACE_PACKET_TYPE_FEATUREMODE,        // 仅特征只支持SDK,需配合平台使用
    FACE_PACKET_TYPE_ALLPACKET,           // 整包模式 图片 + 人员信息 + 人脸特征值
    FACE_PACKET_TYPE_MAX
}PU_FACE_PACKET_TYPE_E;

// 矩形
typedef struct _META_RECT_S 
{
    USHORT usX;      // 矩形左上顶点的x坐标
    USHORT usY;      // 矩形左上顶点的y坐标
    USHORT usWidth;  // 矩形宽
    USHORT usHeight; // 矩形高
} META_RECT_S;

// 点
typedef struct _META_POINT_S 
{
    USHORT usX; // x
    USHORT usY; // y
} META_POINT_S;

// 线
typedef struct _META_LINE_S 
{
    META_POINT_S stStartPoint; // 起始点
    META_POINT_S stEndPoint;   // 终止点
} META_LINE_S;

// 多边形
typedef struct _META_POLYGON_S 
{
    UINT uPointNum;         // 点个数
    META_POINT_S astPts[MAX_POINT_NUM]; // 
} META_POLYGON_S;

// 颜色
typedef struct _META_COLOR_S 
{
    UCHAR auc_r[3];
    UCHAR auc_g[3];
    UCHAR auc_b[3];
    UCHAR auc_ConfLev[3]; // 置信度
    UCHAR auc_ColorID[3]; // ID
} META_COLOR_S;

// 颜色
typedef struct _ST_BINARY 
{
    ULONG ulBinaryLenth;
    UCHAR *pBinaryData;   
}ST_BINARY;

//行进方向，前后
typedef enum  META_MOVE_DIRECT
{
    DIRECT_UNKNOWN = 0, //未知
    DIRECT_FORWARD,     //向前
    DIRECT_BACKWARD,    //向后
}META_MOVE_DIRECT_E;

//行进速度，慢、快
typedef enum META_MOVE_SPEED
{
    SPEED_UNKNOWN = 0, //未知
    SPEED_SLOW,        //慢
    SPEED_FAST,        //快
}META_MOVE_SPEED_E;

// 人体属性结果 
typedef struct META_HUMAN_ATTRIBUTES
{
    BOOL isVaild;

    //INT 定义的属性 0 代表 未知，1-n依次代表后面的属性具体含义
    INT age;                            //年龄 {少年,青年,老年} 
    INT gender;                         //性别{男，女}
    INT upperStyle;                     //上衣款式 {长袖，短袖} 
    INT upperColor;                     //上衣颜色 {黑，蓝，绿，白/灰，黄/橙/棕，红/粉/紫}  
    INT upperTexture;                   //上衣纹理 {纯色，条纹} 
    INT lowerStyle;                   	//下衣款式 {长裤,短裤}      
    INT lowerColor;                  	//下衣颜色 {黑，蓝，绿，白/灰，黄/橙/棕，红/粉/紫}  
    INT shape;                        	//体型{standard, fat, thin}
    INT mouthmask;                    	//口罩{no,yes}  
    INT hair;                           //发型{ long, short }
    INT backpack;                     	//背包{no,yes} 
    INT carry;                        	//是否拎东西{no,yes}
    INT satchel;                      	//斜挎包{no,yes} 
    INT umbrella;                     	//雨伞{no,yes}
    INT frontpack;                    	//前面背包{no,yes}
    INT luggage;                      	//行李箱{no,yes} 

    META_MOVE_DIRECT_E enMoveDirect;	//行进方向{direct_unknow,forward,backward}
    META_MOVE_SPEED_E enMoveSpeed;		//行进速度{speed_unknow,slow,fast}
}META_HUMAN_ATTRIBUTES_S;

//人脸属性
typedef struct META_FACE_ATTRIBUTES
{
    BOOL isVaild;

    //INT 定义的属性 0 代表 未知，1-n依次代表后面的属性具体含义
    INT glasses;              //眼镜{无，有} 
    INT gender;               //性别{女，男} 
    INT age;                  //年龄，具体的年龄值1~99 
    INT mouthmask;            //遮档 {无，是} 
    INT expression;           //人脸表情{微笑、愤怒、悲伤、正常、惊讶}
}META_FACE_ATTRIBUTES_S;

//人脸信息
typedef struct META_FACE_INFO
{
    CHAR name[PU_MAX_RECORD_LEN_64];    //名字
    INT iGender;      //性别
    CHAR birthday[PU_MAX_RECORD_LEN_32];//生日
    CHAR province[PU_MAX_RECORD_LEN_32];//省级
    CHAR city[PU_MAX_RECORD_LEN_48];    //地市
    INT iCardType;    //证件类型，参见PU_CARDTYPE_E
    CHAR cardID[PU_MAX_RECORD_LEN_32];  //证件号
}META_FACE_INFO_S;

typedef struct PU_UserData
{
    LAYER_THREE_TYPE_E eType;
    union _unMetadata
    {
        BOOL bBoolValue;
        CHAR charValue;
        UCHAR ucharValue;
        SHORT shortValue;
        USHORT ushortValue;
        INT IntValue;
        UINT uIntValue;
        LONGLONG longlongValue;
        ULONGLONG uLonglongValue;
        ST_BINARY stBinay;    
        META_RECT_S stRec;
        META_POINT_S stPoint;
        META_LINE_S stLine;
        META_POLYGON_S stPolyGon;
        META_COLOR_S stColor;
        META_HUMAN_ATTRIBUTES_S stHumanAttr;
        META_FACE_ATTRIBUTES_S stFaceAttr;
        META_FACE_INFO_S stFaceInfo;
        CHAR szUserData[1];
    }unMetaData; 
}PU_UserData;

typedef struct _PU_META_TLV
{
    INT iType;
    UINT uLength;
    UCHAR *pValue;
}PU_META_TLV;

typedef struct _PU_META_DATA
{
    USHORT usCapacity;
    USHORT usValidNumber;
    PU_UserData *pstMetaUserData;
}PU_META_DATA;
/********************************结构体**********************************************/
//设备版本
typedef struct PU_DEVICE_VERSION
{
    CHAR szVerSoftware[PU_VERSION_LEN];        //软件版本        
    CHAR szVerUboot[PU_VERSION_LEN];           //UBoot版本
    CHAR szVerKernel[PU_VERSION_LEN];          //内核版本
    CHAR szVerHardware[PU_VERSION_LEN];        //硬件版本
    CHAR szReserved[PU_RESERVE_LEN];           //前24 字节表示Mac地址,
                                               //szReserved[24],入参,表示网口索引,0表示网卡1,1表示网卡2,获取时使用
                                               //szReserved[25],出参,表示网口数量,获取时使用
}PU_DEVICE_VERSION, *LPPU_DEVICE_VERSION;

//设备信息结构
typedef struct PU_DEVICE_INFO
{
    CHAR szDeviceName[PU_DEVICE_NAME_LEN];    //设备名称最长32位
    CHAR szDeviceFac[PU_FAC_NAME_LEN];        //设备厂商
    CHAR szDeviceType[PU_DEVICE_TYPE_LEN];    //设备型号,只可查询不可设置
    CHAR szSerialNumber[PU_SERIAL_LEN];       //硬件序列号
    PU_DEVICE_VERSION stDeviceVersion;        //设备版本
    CHAR szReserved[PU_RESERVE_LEN];          //Bom编码
}PU_DEVICEINFO_S, *LPPU_DEVICEINFO_S;

//视频参数结构
typedef struct PU_VIDEO_ATTRIBUTE
{
    ULONG    ulBitRate;                        //码率
    ULONG    ulIFrameInterval;                 //I帧间隔
    ULONG    ulFrameRate;                      //帧率
    PU_ENCODE_TYPE_E enVideoEncodeMode;        //视频编码类型
    PU_RESOLUTION_TYPE_E  enResolution;        //分辨率
    PU_BITRATE_TYPE_E     enBitRateType;       //码率类型
    PU_PIC_QUALITY_E      enPicQuality;        //图像质量
    PU_VIDEO_FORMAT_E     enVideoFormat;       //图像制式
    PU_H264_RC_PRI_E      enRcPriMode;         //帧率优先码率优先模式,仅H264下有效
    PU_VIDEO_MIRROR_MODE_E enMirrorMode;       //镜像模式(实际以主码流镜像模式生效)
    CHAR  szReserve[PU_RESERVE_LEN];           //szReserve[0]标识编码复杂度: H264 0 BP,   1 MP,     2 HP
                                               //                            H265 0 Main, 1 Main10, 2 MainSP (现只支持Main)
	                                           //szReserve[1]标识MJPEG质量的值[2,99]
	                                           //szReserve[2]标识分层编码使能，0不使能，1使能(仅在设置、获取码流套餐时有效)
	                                           //szReserve[3]标识智能编码等级，0不使能，1~5各可设档位
	                                           //szReserve[4]标识MultiSliceEnable 0不使能，1使能
}PU_VIDEO_ATTRIBUTE_S, *LPPU_VIDEO_ATTRIBUTE_S;

//视频流信息结构
typedef struct PU_STREAM_ATTRIBUTE
{
    PU_STREAM_TYPE_E enStreamId;                                    //码流类型
    PU_VIDEO_ATTRIBUTE_S stVideoAttribute;                          //视频流参数
}PU_STREAM_ATTRIBUTE_S, *LPPU_STREAM_ATTRIBUTE_S;

//视频流信息
typedef struct PU_VIDEO_STREAM_INFO
{
    ULONG ulChannelId;                                              //通道ID
    PU_STREAM_MODE_E enStreamMode;                                  //视频流类型
    PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_VIEDO_STREAM_TRIPLE];//视频属性
    CHAR szReserved[PU_RESERVE_LEN];                                //szReserve[0]标识全帧率
                                                                    //szReserve[1]标识分辨率宽窄屏
}PU_VIDEO_STREAM_INFO_S, *LPPU_VIDEO_STREAM_INFO_S;

//视频流信息
typedef struct PU_VIDEO_STREAM_INFO_V2
{
	ULONG ulChannelId;                                              //通道ID
	PU_STREAM_MODE_E enStreamMode;                                  //视频流类型
	PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_VIEDO_STREAM_FIVE];//视频属性
	CHAR szReserved[PU_RESERVE_LEN];                                //szReserve[0]标识全帧率  25:25HZ 30:30HZ 50：50HZ 60:60HZ
																	//szReserve[1]标识分辨率宽窄屏 0表示宽屏 1表示窄屏
}PU_VIDEO_STREAM_INFO_V2_S, *LPPU_VIDEO_STREAM_INFO_V2_S;

//音频流信息
typedef struct PU_AUDIO_INFO
{
    ULONG ulAudioChannelId;                                         //音频通道ID
    PU_ENCODE_TYPE_E enAudioEncodeMode;                             //音频编码类型
    ULONG ulInputVolume;                                            //输入音量
    ULONG ulOutputVolume;                                           //输出音量
    PU_AUDIO_G726_BPS_E enAudioRate;                                //音频G726码率
    CHAR szReserved[PU_RESERVE_LEN];                                //szReserved[0]标识采样率 : 0 8K, 1 12K, 2 16K, 3 24K, 4 48K, 5 22.05K, 6 32K, 7 44.1K
                                                                    //szReserved[1]标识音频端口输入类型 : 0: Line in 1: Mic in
                                                                    //szReserved[2]标识音频自动增益 : 0:不开启 1:开启
}PU_AUDIO_INFO_S, *LPPU_AUDIO_INFO_S;

//视频显示效果结构体
typedef struct PU_VIDEO_DISPLAY_INFO
{
    ULONG ulChannelId;                      //通道ID
    LONG lBrightValue;                      //亮度
    LONG lHueValue;                         //色度
    LONG lSaturationValue;                  //饱和度
    LONG lContrastValue;                    //对比度
    LONG lSharpValue;                       //锐度
	PU_COMMONMODE_SWITCH_E enSharpSwitch;   //锐度开关
	ULONG ulBitMap;							//修改位，00000（从低位依次为锐度，色度，饱和度，对比度，亮度）按位修改置1表示修改，置0不修改
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG) - sizeof(PU_COMMONMODE_SWITCH_E)];
}PU_VIDEO_DISPLAY_INFO_S, *LPPU_VIDEO_DISPLAY_INFO_S;

//H264解码初始化参数用户数据
typedef struct PU_H264_USERDATA
{
    UINT   uUserDataType;   //用户数据
    UINT   uUserDataSize;   //用户数据长度
    UCHAR *pData;           //用户数据缓冲区
    struct PU_H264_USERDATA *pNext;    //下一段用户数据
}PU_H264_USERDATA_S;

//H264解码初始化参数
typedef struct PU_H264_DEC_ATTR
{
    UINT  uPictureFormat;       //输出图像格式，0x00:YUV420 0x01:YUV422 0x02:YUV444
    UINT  uStreamInType;        //输入码流类型
    UINT  uPicWidthInMB;        //支持的图像宽度，单位:MB
    UINT  uPicHeightInMB;       //支持的图像高度，单位:MB
    UINT  uBufNum;              //最大参考帧缓冲区数
    UINT  uWorkMode;            //解码模式
    PU_H264_USERDATA_S *pUserData;  //用户数据
    UINT  uReserved;                //保留
	CHAR szReserved[PU_RESERVE_LEN];  //预留字段
}PU_H264_DEC_ATTR_S;

//H264解码帧信息
typedef struct PU_H264_DEC_OUTPUT_INFO
{
	UINT uPicBytes;            //当前帧字节数
	UINT uI4MbNum;             //当前帧的I4x4 宏块个数
	UINT uI8MbNum;             //当前帧的I8x8 宏块个数
	UINT uI16MbNum;            //当前帧的I16x16 宏块个数
	UINT uP16MbNum;            //当前帧的P16x16 宏块个数
	UINT uP16x8MbNum;          //当前帧的P16x8 宏块个数
	UINT uP8x16MbNum;          //当前帧的P8x16 宏块个数
	UINT uP8MbNum;             //当前帧的P8x8 宏块个数
	UINT uPskipMbNum;          //当前帧的PSkip 宏块个数
	UINT uIpcmMbNum;           //当前帧的IPCM 宏块个数
}PU_H264_DEC_OUTPUT_INFO_S;

//H264帧信息
typedef struct PU_H264_DEC_FRAME
{
    UCHAR*  pY;                   //Y分量地址
    UCHAR*  pU;                   //U分量地址
    UCHAR*  pV;                   //V分量地址
    UINT    uWidth;               //输出图像宽度，单位: 像素
    UINT    uHeight;              //输出图像高度，单位: 像素
    UINT    uYStride;             //输出Y分量stride
    UINT    uUVStride;            //输出U/Y分量stride
    UINT    uCroppingLeftOffset;  //输出图像左边裁剪量，单位: 像素
    UINT    uCroppingRightOffset; //输出图像右边裁剪量，单位: 像素
    UINT    uCroppingTopOffset;   //输出图像上边裁剪量，单位: 像素
    UINT    uCroppingBottomOffset;//输出图像下边裁剪量，单位: 像素
    UINT    uDpbIdx;              //输出图像缓存区序号
    UINT    uPicFlag;             //输出图像属性，0: 帧; 1: 顶场; 2: 底场
    UINT    uError;               //当前图像错误标示，0: 输出图像无错; 1: 输出图像有错
    UINT    uIntra;               //输出图像是否为IDR帧，0: 非IDR帧; 1:IDR帧
    ULONGLONG ullPTS;             //时间戳
    UINT    uPictureID;           //输出图像序号
    UINT    uReserved;            //保留
    PU_H264_USERDATA_S *pUserData;   //用户数据
	PU_H264_DEC_OUTPUT_INFO_S stFrameInfo; //当前帧信息
	CHAR szReserved[PU_RESERVE_LEN];  //预留字段
}PU_H264_DEC_FRAME_S;

//H265解码相关结构返回值
typedef enum PU_H265D_RETURN
{
    // 成功返回
    PU_H265D_OK                        = 0,              // 函数调用成功
    PU_H265D_NEED_MORE_BITS            = 1,              // 函数调用成功，但需要更多bit数才能输出一帧
    PU_H265D_FIND_NEW_PIC              = 2,
    
	//警告返回码：
	PU_H265D_NAL_HEADER_WARNING		= 0x00000004,       //NAL头解码告警
	PU_H265D_VPS_WARNING			= 0x00000008,       //VPS解码告警
	PU_H265D_SPS_WARNING			= 0x00000010,       //SPS解码告警
	PU_H265D_PPS_WARNING			= 0x00000020,       //PPS解码告警
	PU_H265D_SLICEHEADER_WARNING	= 0x00000040,       //SliceHeader解码告警
	PU_H265D_SLICEDATA_WARNING		= 0x00000080,       //SliceData解码告警

    // 一般错误
    PU_H265D_INVALID_ARGUMENT          = 0xF0401000,     //输入的形参不正确
    PU_H265D_DECODER_NOT_CREATE,                         //解码器未创建

    // 初始化错误
    PU_H265D_MALLOC_FAIL               = 0xF0402000,     //内存分配失败
    PU_H265D_INVALID_MAX_WIDTH,                          //最大宽度超过范围
    PU_H265D_INVALID_MAX_HEIGHT,                         //最大高度超过范围
    PU_H265D_INVALID_MAX_REF_PIC,                        //最大参考帧数超过范围
	PU_H265D_INVALID_THREAD_CONTROL,                     //非法线程控制
    PU_H265D_INVALID_MALLOC_FXN,                         //Malloc回调函数指针无效
    PU_H265D_INVALID_FREE_FXN,                           //Free回调函数指针无效
    PU_H265D_INVALID_LOG_FXN,                            //Log回调函数指针无效
    PU_H265D_STREAMBUF_NULL,                             //解码器输入码流buf为空
    PU_H265D_INVALID_STREAMBUF_LENGTH,                   //解码器输入码流字节数错误
    PU_H265D_YUVBUF_NULL,                                //解码器输出YUV buffer指针为空
    PU_H265D_YUVBUF_ADDR_NOT_ALIGN_16,                   //解码器输出YUV buffer address未16字节对齐
    PU_H265D_POSTPROCESS_ERR,                            //后处理方法选择错误
    PU_H265D_ERRCONCEAL_ERR,                             //错误隐藏参数配置错误

    // 解码错误
    PU_H265D_NAL_HEADER_ERR				= 0xF0404001,   //NAL头解码错误
	PU_H265D_VPS_ERR					= 0xF0404002,   //VPS解码错误
	PU_H265D_SPS_ERR					= 0xF0404003,   //SPS解码错误
	PU_H265D_PPS_ERR					= 0xF0404004,   //PPS解码错误
	PU_H265D_SLICEHEADER_ERR			= 0xF0404005,   //SliceHeader解码错误
	PU_H265D_SLICEDATA_ERR				= 0xF0404006,   //SliceData解码错误
	
    //解码警告
    PU_H265D_FRAME_DECODE_WARN			= 0xE0404007,   //帧数据错误，该码流可能有误码，YUV输出图像质量不做保证
	PU_H265D_THREAD_ERROR    			= 0xE0404008    //多线程错误 lcc

}PU_H265D_RETURN_E;

//线程类型
typedef enum PU_H265D_THREADTYPE
{
    PU_H265D_SINGLE_THREAD     = 0,       //单线程
    PU_H265D_MULTI_THREAD                 //多线程
}PU_H265D_THREADTYPE_E;

//输出序
typedef enum PU_H265D_OUTPUTORDER
{
    PU_H265D_DECODE_ORDER     = 0,       //按解码序输出
    PU_H265D_DISPLAY_ORDER               //按显示序输出
}PU_H265D_OUTPUTORDER_E;

//用户数据
typedef struct PU_H265D_USERDATA 
{ 
    UINT uiUserDataType;              /* 用户数据类型  */ 
    UINT uiUserDataSize;              /* 用户数据长度  */ 
    UCHAR *pucData;                   /* 用户数据缓冲区*/ 
    struct PU_H265D_USERDATA *pNext;  /* 指向下一段用户数据 */ 
}PU_H265D_USERDATA_S;

// LOG等级
typedef enum PU_VIDEO_ALG_LOG_LEVEL
{
    PU_VIDEO_ALG_LOG_ERROR = 0,   // 出错时的LOG信息
    PU_VIDEO_ALG_LOG_WARNING,     // 报警时的LOG信息
    PU_VIDEO_ALG_LOG_INFO,        // 打印的辅助信息
    PU_VIDEO_ALG_LOG_DEBUG        // 打印的调试信息，用于开发人员调试

}PU_VIDEO_ALG_LOG_LEVEL;

/*元数据请求分类，用于元数据网关分类*/
typedef enum PU_METADATA_REQUEST_TYPE
{
    PU_METADATA_REQUEST_COMMON = 0,    //不区分元数据类型
    PU_METADATA_REQUEST_REST = 1,      //只请求检测框信息
    PU_METADATA_REQUEST_OTHERS = 2,    //除去检测框信息的其他信息
    PU_METADATA_REQUEST_MAX,
}PU_METADATA_REQUEST_TYPE_E;

/******************************************************************************
* 说明   :  内存分配回调函数类型
* 参数   :  uiChannelID - [in] 通道ID
*                  uiSize      - [in] 内存大小
* 返回值 :  成功返回内存地址
*                     失败返回NULL
*******************************************************************************/
typedef void *(* PU_VIDEO_ALG_MALLOC_FXN)(UINT uiChannelID, UINT uiSize);

/******************************************************************************
* 说明   :  内存释放回调函数类型
* 参数   :  uiChannelID - [in] 通道ID
*                  pMem          - [in] 内存地址
* 返回值 :  无
*******************************************************************************/
typedef void  (* PU_VIDEO_ALG_FREE_FXN)(UINT uiChannelID, void *pMem);

/******************************************************************************
* 说明   :  日志回调函数类型
* 参数   :  uiChannelID - [in]  通道ID
*                  eLevel         - [in] 设置日志级别
*                  pszMsg        - [in] 日志的内容(字符串)
*                  ...               - [in] 可变参数
* 返回值 :  无
*******************************************************************************/
typedef void  (* PU_VIDEO_ALG_LOG_FXN)(UINT uiChannelID, PU_VIDEO_ALG_LOG_LEVEL eLevel, CHAR *pszMsg, ...);


//H265解码器初始化参数
typedef struct PU_H265D_INIT_PARAM
{
    UINT  uiChannelID;                 // 通道ID，用于标识通道信息
    INT   iMaxWidth;                   // 最大宽度
    INT   iMaxHeight;                  // 最大高度  
    INT   iMaxRefNum;                  //最大参考帧数  
    PU_H265D_THREADTYPE_E  enThreadType; //线程类型  TODO：暂时不支持多线程，后续会添加多种线程划分方式（tile、Slice、LCU行）
    PU_H265D_OUTPUTORDER_E enOutputOrder;//输出顺序  TODO：仅在DecodeFrame有效，DecodeAU无效
    PU_H265D_USERDATA_S *pstUserData;    //用户数据
    PU_VIDEO_ALG_MALLOC_FXN  MallocFxn;  // 内存分配回调
    PU_VIDEO_ALG_FREE_FXN    FreeFxn;    //内存释放回调
    PU_VIDEO_ALG_LOG_FXN     LogFxn;     // 日志输出回调函数
    CHAR szReserved[PU_RESERVE_LEN];     //预留字段
}PU_H265D_INIT_PARAM_S;

//H265解码模式
typedef enum PU_H265D_DECODEMODE
{
    PU_H265D_DECODE = 0,       //正常解码
    PU_H265D_DECODE_END        //解码完毕并要求解码器输出残留图像
}PU_H265D_DECODEMODE_E;

//H265解码输入参数
typedef struct PU_H265DEC_INARGS
{
    UCHAR  *pStream;           //待解码帧地址
    UINT uiStreamLen;          //待解码帧长度
    ULONGLONG uiTimeStamp;     //时间戳
    PU_H265D_DECODEMODE_E enDecodeMode; //解码模式
	CHAR szReserved[PU_RESERVE_LEN];    //预留字段
}PU_H265DEC_INARGS_S;

//H265帧类型
typedef enum PU_H265D_FRAMETYPE
{
    PU_H265D_FRAME_I = 0, //I帧
    PU_H265D_FRAME_P,     //P帧
    PU_H265D_FRAME_B,     //B帧
    PU_H265D_FRAME_UNKNOWN
}PU_H265D_FRAMETYPE_E;

//H265解码类型
typedef enum PU_H265D_DECODESTATUS
{
	PU_H265_DEC_GETDISPLAY = 0, //已经解码出一帧并输出，可用于显示
	PU_H265_DEC_NEED_MORE_BITS, //解码器没有图像输出，需要更多的码流
	PU_H265_DEC_NO_PICTURE,     //解码完毕，已经输出全部图像
	PU_H265_DEC_ERR_HANDLE      //句柄错误
}PU_H265D_DECODESTATUS_E;

//每帧图像各种CU 数量信息
typedef struct PU_CU_OUTPUT_INFO
{
	UINT uiCuNumIntra4;   // intra 4x4 CU number
	UINT uiCuNumIntra8;   // intra 8x8 CU number
	UINT uiCuNumIntra16;  // intra 16x16 CU number
	UINT uiCuNumIntra32;  // intra 32x32 CU number
	UINT uiCuNumIntra64;  // intra 64x64 CU number
	UINT uiCuNumPcm4;     // IPCM 4x4 CU number
	UINT uiCuNumPcm8;     // IPCM 8x8 CU number
	UINT uiCuNumPcm16;    // IPCM 16x16 CU number
	UINT uiCuNumPcm32;    // IPCM 32x32 CU number
	UINT uiCuNumPcm64;    // IPCM 64x64 CU number
	UINT uiCuNumInter8;   // inter 8x8 CU number
	UINT uiCuNumInter16;  // inter 16x16 CU number
	UINT uiCuNumInter32;  // inter 32x32 CU number
	UINT uiCuNumInter64;  // inter 64x64 CU number
	UINT uiCuNumSkip8;    // skip 8x8 CU number
	UINT uiCuNumSkip16;   // skip 16x16 CU number
	UINT uiCuNumSkip32;   // skip 32x32 CU number
	UINT uiCuNumSkip64;   // skip 64x64 CU number
}PU_CU_OUTPUT_INFO_S;

//H265解码输出参数
typedef struct PU_H265DEC_OUTARGS
{
	UINT uiChannelID;         //通道ID
	UINT uiBytsConsumed;      //消耗的字节数
	ULONGLONG uiTimeStamp;    //时间戳
	PU_H265D_FRAMETYPE_E enFrameType;       //帧类型
	PU_H265D_DECODESTATUS_E enDecodeStatus; //解码器状态
	UINT uiDecWidth;     //图像宽
	UINT uiDecHeight;    //图像高
	UINT uiYStride;      //Y分量stride
	UINT uiUVStride;     //U/V分量stride
	UCHAR *pucOutYUV[3]; //YUV地址，依次存放YUV  
	UINT uiCodingBytesOfCurFrm;       //原始码流长度
	PU_H265D_USERDATA_S stUserData;     //用户数据
	UINT uiAspectRatioIdc;            //幅形比信息
	UINT uiSarWidth;                  //幅形比宽度，当uiAspectRatioIdc 为255时有效
	UINT uiSarHeight;                 //幅形比高度，当uiAspectRatioIdc 为255时有效
	UINT uiVpsNumUnitsInTick;         //帧率信息
	UINT uiVpsTimeScale;              //帧率信息
	PU_CU_OUTPUT_INFO_S stCuOutInfo;  //输出当前帧信息, 包含一帧中各种类型CU的个数
	INT iIsError;                     //帧错误标志，0:无错，1:有错
}PU_H265DEC_OUTARGS_S;

/*自动光圈参数*/
typedef struct PU_AUTO_APERTURE_PARA
{
	ULONG ulChannelId;                //通道号
	BOOL bEnable;                     //开关模式：0：打开、1：关闭
    CHAR szReserved[PU_RESERVE_LEN];  //预留字段
}PU_AUTO_APERTURE_PARA_S, *LPPU_AUTO_APERTURE_PARA;

//ROI矩形参数结构体
typedef struct PU_ROI_AREA_INFO
{
    LONG lQuality;                          //图像质量：
    ULONG ulPointX;                         //ROI区域X坐标
    ULONG ulPointY;                         //ROI区域Y坐标
    ULONG ulWidth;                          //ROI区域宽度
    ULONG ulHeight;                         //ROI区域高度
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ROI_AREA_INFO_S, *LPPU_ROI_AREA_INFO_S;

//ROI参数结构体
typedef struct PU_ROI_INFO
{
    ULONG ulChannelId;                      //通道ID
    PU_STREAM_TYPE_E enStreamId;            //码流ID
    LONG lEnable;                           //使能
    ULONG ulROINum;                         //有效的ROI区域数目
    PU_ROI_AREA_INFO_S stROIAreaInfo[PU_ROI_AREA_NUM_MAX];             //ROI矩形参数
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ROI_INFO_S, *LPPU_ROI_INFO_S;

//光圈校正结构体
typedef struct PU_IRIS_EMENDATION
{
    ULONG ulChannelId;                      //通道ID
    PU_LANGUAGE_TYPE_E enLanguageType;      //语言类型
    CHAR szReserved[PU_RESERVE_LEN];
}PU_IRIS_EMENDATION_S, *LPPU_IRIS_EMENDATION_S;

//媒体端口信息
typedef struct PU_PORT_INFO
{
    ULONG ulInterLeavedPort;                //交织端口
    ULONG ulVideoRtpPort;                   //视频RTP端口
    ULONG ulVideoRtcpPort;                  //视频RTCP端口
    ULONG ulAudioRtpPort;                   //音频RTP端口
    ULONG ulAudioRtcpPort;                  //音频RTCP端口
    ULONG ulIgtRtpPort;                     //智能RTP端口
    ULONG ulIgtRtcpPort;                    //智能RTCP端口
    CHAR szReserved[PU_RESERVE_LEN];
}PU_PORT_INFO_S, *LPPU_PORT_INFO_S;

//实况保存结构体
typedef struct PU_SAVE_REALDATA_INFO
{
    CHAR szFilePath[PU_SAVE_FILE_PATH_MAX]; //文件保存路径
    PU_SAVE_REALDATA_TYPE_E enSaveType;     //保存方式
    ULONG ulSaveSize;                       //保存文件大小或者录像长度(根据enSaveType判断)
}PU_SAVE_REALDATA_INFO_S, *LPPU_SAVE_REALDATA_INFO_S;

//保存图片结构体
typedef struct PU_SAVE_PICTURE_INFO
{
    CHAR szFilePath[PU_SAVE_FILE_PATH_MAX]; //文件保存路径+文件名
    PU_SAVE_PICTURE_TYPE_E enSavePicType;   //保存方式
}PU_SAVE_PICTURE_INFO_S, *LPPU_SAVE_PICTURE_INFO_S;

//巡航轨迹点信息
typedef struct PU_CRUISE_POINT
{
    ULONG ulPresetIndex;                    //预置位序列号
    ULONG ulDwellTime;                      //预置位停留时间(3-3600s)
    ULONG ulSpeed;                          //转到下一个点的速度(1-10)
}PU_CRUISE_POINT_S, *LPPU_CRUISE_POINT_S;

//巡航轨迹信息
typedef struct PU_PTZ_CRUISE_TRACK_PARA
{
    ULONG ulPtzId;                                                  //云台编号
    ULONG ulCruiseTrackIndex;                                       //巡航轨迹编号
    ULONG ulCruiseType;                                             //巡航模式（1：轨迹扫描，2：花样扫描）
    CHAR szCuriseTrackName[PU_PTZ_CRUISE_LEN];                      //巡航轨迹名称
    ULONG ulPointNum;                                               //轨迹点个数
    PU_CRUISE_POINT_S stCruisePoint[PU_PTZ_CRUISE_POINT_MAX];       //轨迹点列表
    PU_PTZ_CRUISE_TRACK_E enPtzCruiseTrack;                         //巡航轨迹操作命令字
}PU_PTZ_CRUISE_TRACK_PARA_S, *LPPU_PTZ_CRUISE_TRACK_PARA_S;

//坐标信息
typedef struct PU_SQUARE_PARA
{
    ULONG ulX;
    ULONG ulY;
}PU_SQUARE_PARA_S, *LPPU_SQUARE_PARA_S;

//矩形区域信息
typedef struct PU_AREA_INFO
{
    ULONG ulStartX;                         //矩形左上角X
    ULONG ulStartY;                         //矩形左上角Y
    ULONG ulWidth;
    ULONG ulHeight;
}PU_AREA_INFO_S,*LPPU_AREA_INFO_S;

/* OSD位置和颜色参数 */
typedef struct PU_OSD_INFO
{
    ULONG ulStartX;
    ULONG ulStartY;
    ULONG ulTextColor;                      //字体颜色 0x00RGB
    PU_COLOR_TYPE_E enBackgroundColor;      //背景颜色
    PU_ALPHA_TYPE_E enBackgroundAlpha;      //背景景透明度
    CHAR szReserve[PU_RESERVE_LEN];         //第[0]位标识是否反色(0不反色,1反色)
                                            //第[1]位标识OSD字体(0小号,1中号,2大号)
}PU_OSD_INFO_S, *LPPU_OSD_INFO_S;

/* OSD字符串参数 */
typedef struct PU_OSD_STRING_PARA
{
    BOOL bEnable;                           //使能与否
    PU_OSD_INFO_S stOSDInfo;
    ULONG ulStringLen;                      // 字符串长度
    CHAR szString[PU_OSD_STRING_LEN];       // 字符串内容
}PU_OSD_STRING_PARA_S, *LPPU_OSD_STRING_PARA_S;

/* OSD时间参数 */
typedef struct PU_OSD_DATETIME_PARA
{
    BOOL bShowWeekday;                      //是否显示星期
    BOOL bDateEnable;                       //时间使能与否
    PU_OSD_DATE_TYPE_E enDateType;          //日期格式
    PU_LANGUAGE_TYPE_E enLanguageType;      //OSD显示的语言类型: 0:简体中文 1:英文
    PU_OSD_INFO_S stOsdPara;                //位置及颜色
    CHAR szReserve[PU_RESERVE_LEN];
}PU_OSD_DATETIME_PARA_S, *LPPU_OSD_DATETIME_PARA_S;

/* OSD数组 */
typedef struct PU_OSD_STRING_ARRAY
{
    ULONG ulChannelID;                                              //通道ID
    PU_OSD_DATETIME_PARA_S stOsdDateTimePara;                       //OSD时间参数
    ULONG ulOSDStringNum;                                           //有效的字符串个数
    PU_OSD_STRING_PARA_S szStringPara[PU_OSD_STRING_NUM];           //OSD字符串参数
}PU_OSD_PARTICULAR_PARA_S, *LPPU_OSD_PARTICULAR_PARA_S;

/* OSD数组扩充 */
typedef struct PU_OSD_STRING_ARRAY_EX_OUT
{
    ULONG ulChannelID;                                              //通道ID
    PU_OSD_DATETIME_PARA_S stOsdDateTimePara;                       //OSD时间参数
    ULONG ulOSDStringNum;                                           //有效的字符串个数
    PU_OSD_STRING_PARA_S *pszStringPara;                            //OSD字符串参数指针
}PU_OSD_PARTICULAR_PARA_EX_OUT_S, *LPPU_OSD_PARTICULAR_PARA_EX_OUT_S;

/* 图片OSD 参数结构体 */
typedef struct PU_OSD_PICTURE_PARA
{
    ULONG ulChannelID;
    BOOL bEnable;                              //使能与否
    PU_AREA_INFO_S stAreaInfo;                 //图片区域信息
    CHAR szPicFileName[PU_SAVE_FILE_PATH_MAX]; //图片的路径及名称
	CHAR szReserve[PU_RESERVE_LEN];
}PU_OSD_PICTURE_PARA_S, *LPPU_OSD_PICTURE_PARA_S;

//隐私保护区域
typedef struct PU_MASK_PARA
{
    ULONG ulStartX;                         //隐私保护矩形左上角X
    ULONG ulStartY;                         //隐私保护矩形左上角Y
    ULONG ulWidth;
    ULONG ulHeight;
}PU_MASK_PARA_S,*LPPU_MASK_PARA_S;

//隐私保护列表
typedef struct PU_PRIVACY_MASK_ARRAY
{
    ULONG ulChannelID;
    ULONG ulNum;
    BOOL bEnable;
    PU_MASK_PARA_S stMaskPara[PU_PRIVACY_MASK_MAX];
}PU_PRIVACY_MASK_ARRAY_S, *LPPU_PRIVACY_MASK_ARRAY_S;

//隐私保护区域
typedef struct PU_MASK_PARA_EX
{
    ULONG ulStartX;                         //隐私保护矩形左上角X
    ULONG ulStartY;                         //隐私保护矩形左上角Y
    ULONG ulWidth;
    ULONG ulHeight;
    ULONG ulColor;                          //颜色
    UCHAR ucAlpha;                          //透明度，暂不支持
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_MASK_PARA_EX_S,*LPPU_MASK_PARA_EX_S;

//隐私保护列表
typedef struct PU_PRIVACY_MASK_ARRAY_EX
{
    ULONG ulChannelID;
    ULONG ulNum;
    BOOL bEnable;
    PU_MASK_PARA_EX_S stMaskParaEx[PU_PRIVACY_MASK_MAX];
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_PRIVACY_MASK_ARRAY_EX_S, *LPPU_PRIVACY_MASK_ARRAY_EX_S;

//温度
typedef struct PU_TEMPERATURE_PARA
{
    LONG lIntTemp;                          //整数部分温度值
    ULONG ulDotTemp;                        //小数部分温度值
}PU_TEMPERATURE_PARA_S, *LPPU_TEMPERATURE_PARA_S;

//串口参数
typedef struct PU_SERIAL_PORT_PARA
{
    ULONG ulSerialPort;                     //串口编号
    PU_SERIAL_PORT_MODE_E enPortMode;       //串口类型
    PU_BAUD_RATE_E enBaudRate;              //波特率
    PU_DATA_BIT_E enDataBit;                //数据位
    PU_PARITY_BIT_E enParityBit;            //校验位
    PU_STOP_BIT_E enStopBit;                //停止位
    PU_FLOW_CONTROL_E enFlowControl;        //串口流控制
}PU_SERIAL_PORT_PARA_S, *LPPU_SERIAL_PORT_PARA_S;

//云台参数
typedef struct PU_PTZ_PARA
{
    ULONG ulPtzId;                          //云台编号
    ULONG ulSerialPort;                     //串口编号
    PU_PTZ_DECODER_TYPE_E enDecoderType;    //解码器类型
    ULONG ulDecoderAddress;                 //解码器地址
    PU_PTZ_CONTROL_MODE_E enPtzControlMode; //正反控制模式
    BOOL  bEnable;                          //是否使能
}PU_PTZ_PARA_S, *LPPU_PTZ_PARA_S;

//透明通道命令
typedef struct PU_TRANSPARENT_CMD
{
    ULONG ulSerialPort;                                             //串口编号
    ULONG ulCmdLen;                                                 //透明通道命令长度
    CHAR  szTransparentCmd[PU_TRANSPARENT_CMD_MAX];                 //透明通道命令
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_TRANSPARENT_CMD_S, *LPPU_TRANSPARENT_CMD_S;

//时间，时、分、秒，24小时制
typedef struct PU_TIME
{
    CHAR szYear[PU_TIME_YEAR_LEN];
    CHAR szMonth[PU_TIME_OTHERS_LEN];
    CHAR szDay[PU_TIME_OTHERS_LEN];
    CHAR szHour[PU_TIME_OTHERS_LEN];
    CHAR szMinute[PU_TIME_OTHERS_LEN];
    CHAR szSecond[PU_TIME_OTHERS_LEN];
}PU_TIME_S, *LPPU_TIME_S;

//布防时间
typedef struct PU_ALARM_TIME
{
    ULONG ulCycleType;                      //循环方式，0：不循环；1：每周循环；
    ULONG ulPeriod;                         //0：每天，1-7：礼拜一至礼拜天
    PU_TIME_S stStart;                      //起始时间
    PU_TIME_S stEnd;                        //结束时间
}PU_ALARM_TIME_S, *LPPU_ALARM_TIME_S;

//布防时间列表
typedef struct PU_ALARM_TIME_PARA_LIST
{
    ULONG ulNum;                                                    //布防时间段个数
    PU_ALARM_TIME_S stAlarmTime[PU_ALARM_TIME_MAX];                 //布防时间段数组
}PU_ALARM_TIME_LIST_S, *LPPU_ALARM_TIME_LIST_S;

//温度告警参数
typedef struct PU_TEMPERATURE_ALARM_PARA
{
    LONG lEnable;                           //使能
    ULONG ulDeteInterval;                   //告警检测时间间隔1~256,每x秒检测一次是否在告警状态
    LONG lTemperatureMax;
    LONG lTemperatureMin;
}PU_TEMPERATURE_ALARM_PARA_S, *LPPU_TEMPERATURE_ALARM_PARA_S;

//开关量(输入)告警参数
typedef struct PU_INPUT_ALARM_PARA
{
    ULONG ulDeviceId;                       //告警设备ID
    CHAR szName[PU_DIO_NAME_LEN];           //告警设备名称
    LONG lEnable;                           //使能
    ULONG ulType;                           //常开，常闭，0：常开，1：常闭
    ULONG ulDeteInterval;                   //告警检测时间间隔1~256,每x秒检测一次是否在告警状态
    PU_ALARM_TIME_LIST_S stAlarmTimeList;
}PU_INPUT_ALARM_PARA_S, *LPPU_INPUT_ALARM_PARA_S;

//移动侦测/视频遮挡矩形参数
typedef struct PU_DETECTION_AREA
{
    ULONG ulNum;                                                    //检测矩形个数
    PU_MASK_PARA_S stMaskPara[PU_ALARM_AREA_MAX];                   //矩形参数
}PU_DETECTION_AREA_S, *LPPU_DETECTION_AREA_S;

//移动侦测告警参数
typedef struct PU_MOTION_DETECTION_PARA
{
    ULONG ulChannelId;                      //视频通道ID
    LONG lEnable;                           //使能
    ULONG ulInterval;                       //检测事件间隔1~30s，在该间隔内的运动都作为统一运动
    ULONG ulSensitivity;                    //运动检测灵敏度1~5，数字越高越灵敏
    ULONG ulDeteInterval;                   //告警检测时间间隔1~256，每x秒检测一次是否在告警状态
    PU_DETECTION_AREA_S stDetectionArea;    //告警检测区域
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_MOTION_DETECTION_PARA_S, *LPPU_MOTION_DETECTION_PARA_S;

//视频遮挡告警参数
typedef struct PU_HIDE_ALARM_PARA
{
    ULONG ulChannel;                        //视频通道ID
    LONG lEnable;                           //告警使能
    ULONG ulDeteInterval;                   //告警检测时间间隔1~255s，每x秒检测一次是否在告警状态
    ULONG ulSensitivity;                    //运动检测灵敏度1~5，数字越高越灵敏
    PU_DETECTION_AREA_S stDetectionArea;    //告警检测区域
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_HIDE_ALARM_PARA_S, *LPPU_HIDE_ALARM_PARA_S;

//入侵检测点
typedef struct PU_INVADE_POINT
{
    ULONG ulPosX;                           //点X轴坐标(0-352)
    ULONG ulPosY;                           //点Y轴坐标(0-288)
}PU_INVADE_POINT_S, *LPPU_INVADE_POINT_S;

//入侵检测线
typedef struct PU_INVADE_LINE
{
    ULONG ulDirection;                      //检测方向（0：双向；1：左向右；2：右向左）
    PU_INVADE_POINT_S stStartPoint;         //检测线起始点
    PU_INVADE_POINT_S stEndPoint;           //检测线的终点
}PU_INVADE_LINE_S, *LPPU_INVADE_LINE_S;

//入侵检测线列表
typedef struct PU_INVADE_LINE_LIST
{
    ULONG ulLineNum;                                                //入侵线有效数量
    PU_INVADE_LINE_S stLine[PU_INVADE_LINE_NUM_MAX];                //入侵线
}PU_INVADE_LINE_LIST_S, *LPPU_INVADE_LINE_LIST_S;

//入侵检测参数
typedef struct PU_INVADE_PARA
{
    LONG lEnable;                           //使能
    ULONG ulSensitivity;                    //灵敏度
    ULONG ulDeteInterval;                   //告警检测时间间隔1~255s，每x秒检测一次是否在告警状态
    ULONG ulMiniSize;                       //目标最小尺寸(5-20)
    ULONG ulMaxSize;                        //目标最大尺寸(10-30)
    PU_INVADE_LINE_LIST_S stLineList;       //入侵检测线列表
}PU_INVADE_PARA_S, *LPPU_INVADE_PARA_S;

//入侵检测告警参数
typedef struct PU_INVADE_ALARM_PARA
{
    ULONG ulChannel;                        //视频通道ID
    PU_INVADE_PARA_S stInvadePara;          //入侵检测参数
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_INVADE_ALARM_PARA_S, *LPPU_INVADE_ALARM_PARA_S;

//目标计数参数
typedef struct PU_COUNT_PARA
{
    LONG lEnable;                           //使能
    ULONG ulSensitivity;                    //灵敏度
    ULONG ulDeteInterval;                   //告警检测时间间隔1~255s，每x秒检测一次是否在告警状态
    ULONG ulMiniSize;                       //目标最小尺寸
    BOOL bOrientation;                      //识别模式设置（0：水平；1：垂直）
    ULONG ulDirection;                      //检测方向（0：双向；1：区域A向区域B；2：区域B向区域A）
}PU_COUNT_PRAR_S, *LPPU_COUNT_PARA_S;

//目标计数告警参数
typedef struct PU_COUNT_ALARM_PARA
{
    ULONG ulChannelId;                      //视频通道ID
    PU_COUNT_PRAR_S stCountPara;            //目标计数参数
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_COUNT_ALARM_PARA_S, *LPPU_COUNT_ALARM_PARA_S;

//干扰检测参数
typedef struct PU_DISTURB_PARA
{
    LONG lEnable;                           //使能
    ULONG ulSensitivity;                    //灵敏度
    ULONG ulResetTime;                      //检测重置延迟(1~5S)
    ULONG ulDeteInterval;                   //告警检测时间间隔1~255s，每x秒检测一次是否在告警状态
}PU_DISTURB_PARA_S, *LPPU_DISTURB_PARA_S;

//干扰检测告警参数
typedef struct PU_DISTURB_ALARM_PARA
{
    ULONG ulChannelId;                      //视频通道ID
    PU_DISTURB_PARA_S stDisturbPara;        //干扰检测参数
    PU_ALARM_TIME_LIST_S stAlarmTimeList;   //布防时间列表
}PU_DISTURB_ALARM_PARA_S, *LPPU_DISTURB_ALARM_PARA_S;

//音频检测参数
typedef struct PU_AUDIO_DECT_PARA
{
    BOOL bEnable;                           //使能
    ULONG ulSensitivity;                    //灵敏度
    CHAR szReserve[PU_RESERVE_LEN];         //预留字段
}PU_AUDIO_DECT_PARA_S;

//音频检测告警参数
typedef struct PU_AUDIO_DECT_ALARM_PARA
{
    ULONG ulChannelId;                          //通道号
    PU_AUDIO_DECT_PARA_S stAudioDectPara;       //音频检测参数
    PU_ALARM_TIME_LIST_S stAlarmTimeList;       //布防时间列表
}PU_AUDIO_DECT_ALARM_PARA_S;

//音频陡升告警参数
typedef struct PU_AUDIO_UP_ALARM_PARA
{
    ULONG ulChannelId;                          //通道号  
    BOOL bEnable;                           	//使能
    ULONG ulSensitivity;                    	//灵敏度
    PU_ALARM_TIME_LIST_S stAlarmTimeList;       //布防时间列表
}PU_AUDIO_UP_ALARM_PARA_S;

//音频陡降告警参数
typedef struct PU_AUDIO_DOWN_ALARM_PARA
{
    ULONG ulChannelId;                          //通道号
    BOOL bEnable;                           	//使能
    ULONG ulSensitivity;                    	//灵敏度
    PU_ALARM_TIME_LIST_S stAlarmTimeList;       //布防时间列表
}PU_AUDIO_DOWN_ALARM_PARA_S;

//布防参数
typedef struct PU_GUARD_PARA
{
    ULONG ulDeviceId;                       //设备ID，0-所有告警设备
    ULONG ulState;                          //布防：0，撤防：1
}PU_GUARD_PARA_S, *LPPU_GUARD_PARA_S;

typedef struct PU_GUARD_STATE
{
    PU_GUARD_PARA_S szChannelStateList[PU_CAMERA_NUM_MAX];          //镜头布防状态,ulDeviceId=0为无效
    PU_GUARD_PARA_S szInputStateList[PU_DIO_NUM_MAX];               //输入设备告警状态,ulDeviceId=0为无效
    CHAR szReserve[PU_RESERVE_LEN];
}PU_GUARD_STATE_S, *LPPU_GUARD_STATE_S;

//设备系统时间结构体
typedef struct PU_SYSTEM_TIME
{
    PU_TIME_S stSystime;                    //UTC时间
    LONG  lTimeZone;                        //时区的整数部分
    ULONG ulDotTimeZone;                    //时区的小数部分
    CHAR szReserve[PU_RESERVE_LEN];
}PU_SYSTEM_TIME_S, *LPPU_SYSTEM_TIME_S;

typedef struct PU_PTZ_ACTION
{
    BOOL bPresetFlag;
    ULONG ulPresetIndex;
    BOOL bCruiseFlag;
    ULONG ulCruiseIndex; 
}PU_PTZ_ACTION_S,*LPPU_PTZ_ACTION_S;

//云台预置位
typedef struct PU_PTZ_PRESET_PARA
{
    ULONG ulChannelId;                      //通道ID
    CHAR szPresetName[PU_PTZ_NAME_LEN];     //预置位名称
    ULONG ulIndex;                          //预置位索引
    PU_PTZ_PRESET_CMD_E enPresetCmd;        //预置位命令字
}PU_PTZ_PRESET_PARA_S, *LPPU_PTZ_PRESET_PARA_S;

//云台预置位(包含聚焦记忆使能开关)
typedef struct PU_PTZ_PRESET_PARA_EX
{
	ULONG ulChannelId;                      //通道ID
	CHAR szPresetName[PU_PTZ_NAME_LEN];     //预置位名称
	ULONG ulIndex;                          //预置位索引
	PU_PTZ_PRESET_CMD_E enPresetCmd;        //预置位命令字
	BOOL bEnableFocusInfo;					//驱动层聚焦记忆使能开关,0:不使能,1:使能
	CHAR szReserve[PU_RESERVE_LEN];		    //预留字
}PU_PTZ_PRESET_PARA_EX_S, *LPPU_PTZ_PRESET_PARA_EX_S;

//预置位信息
typedef struct PU_PTZ_PRESET_INFO
{
    ULONG ulIndex;
    CHAR szPresetName[PU_PTZ_NAME_LEN];
}PU_PTZ_PRESET_INFO_S, *LPPU_PTZ_PRESET_INFO_S;

//预置位信息（包含聚焦记忆使能开关）
typedef struct PU_PTZ_PRESET_INFO_EX
{
	ULONG ulIndex;
	CHAR szPresetName[PU_PTZ_NAME_LEN];
	BOOL bEnableFocusInfo;		 //驱动层聚焦记忆使能开关
	CHAR szReserve[PU_RESERVE_LEN];			 //预留字
}PU_PTZ_PRESET_INFO_EX_S, *LPPU_PTZ_PRESET_INFO_EX_S;

//云台预置位列表
typedef struct PU_PTZ_PRESET_LIST_PARA
{
    ULONG ulChannelId;                                              //通道ID
    ULONG ulBeginIndex;                                             //预置位开始编号
    ULONG ulEndIndex;                                               //预置位结束编号
    ULONG ulTotalNum;                                               //返回的预置位实际个数
    PU_PTZ_PRESET_INFO_S stPtzPresetInfo[PU_PTZ_PRESET_NUM];        //预置位信息
}PU_PTZ_PRESET_LIST_PARA_S, *LPPU_PTZ_PRESET_LIST_PARA_S;

//云台预置位列表 (包含聚焦记忆使能开关)
typedef struct PU_PTZ_PRESET_LIST_PARA_EX
{
	ULONG ulChannelId;                                              //通道ID
	ULONG ulBeginIndex;                                             //预置位开始编号
	ULONG ulEndIndex;                                               //预置位结束编号
	ULONG ulTotalNum;                                               //返回的预置位实际个数
	PU_PTZ_PRESET_INFO_EX_S stPtzPresetInfo[PU_PTZ_PRESET_NUM];     //预置位信息
	CHAR szReserve[PU_RESERVE_LEN];									//预留字
}PU_PTZ_PRESET_LIST_PARA_EX_S, *LPPU_PTZ_PRESET_LIST_PARA_EX_S;

//云台控制
typedef struct PU_PTZ_CONTROL_PARA
{
    ULONG ulChannel;                        //通道ID
    ULONG ulOpCode;                         //云台控制码
    ULONG ulParam1;                         //参数1
    ULONG ulParam2;                         //参数2
}PU_PTZ_CONTROL_PARA_S, *LPPU_PTZ_CONTROL_PARA_S;

//告警上报信息结构
typedef struct PU_ALARM_REPORT      
{                                        
    ULONG ulDeviceId;                       //告警设备ID
    PU_ALARM_TYPE_E enAlarmType;            //告警类型
    PU_TIME_S stTime;                       //告警发生时间
    PU_ALARM_ACTION_E enAction;             //告警发生/消除
    ULONG ulAlarmId;                        //告警ID
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ALARM_REPORT_S, *LPPU_ALARM_REPORT_S;

//NVS平台参数
typedef struct PU_PLATFORM_NVS_PARAM
{
    CHAR szNvsIp[PU_PLATFORM_INFO_LEN];        //NVS IP地址
    ULONG ulNvsPort;                           //NVS端口
    CHAR pszDeviceID[PU_PLATFORM_INFO_LEN];    //设备ID
    CHAR pszLoginName[PU_PLATFORM_INFO_LEN];   //NVS登录名
    CHAR pszLoginDomain[PU_PLATFORM_INFO_LEN]; //NVS登录域
    CHAR pszPassword[PU_PLATFORM_INFO_LEN];    //NVS登录Pwd
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_NVS_PARAM_S, *LPPU_PLATFORM_NVS_PARAM_S;

//IVS平台参数
typedef struct PU_PLATFORM_IVS_PARAM_S
{
    CHAR szNvsIp[PU_PLATFORM_INFO_LEN];        //IVS IP地址
    ULONG ulNvsPort;                           //IVS端口
    CHAR pszDeviceID[PU_PLATFORM_INFO_LEN];    //设备ID
    CHAR pszLoginName[PU_PLATFORM_INFO_LEN];   //IVS登录名
    CHAR pszLoginDomain[PU_PLATFORM_INFO_LEN]; //IVS登录域
    CHAR pszPassword[PU_PLATFORM_INFO_LEN];    //IVS登录Pwd
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_IVS_PARAM_S, *LPPU_PLATFORM_IVS_PARAM_S;

//千里眼平台参数地址，适用于IVS
typedef struct PU_PLATFORM_IVS_PARA
{
    BOOL bEnable;
    CHAR szLoginDomain[PU_PLATFORM_INFO_LEN];
    CHAR szLoginName[PU_PLATFORM_INFO_LEN];
    CHAR szDeviceId[PU_PLATFORM_INFO_LEN];
    CHAR szPassword[PU_PLATFORM_INFO_LEN];
    CHAR szProductName[PU_PLATFORM_INFO_LEN];
    CHAR szServerIp[PU_IP4_ADDR_LEN];
    ULONG ulServerPort;
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PLATFORM_IVS_PARA_S, *LPPU_PLATFORM_IVS_PARA_S;

//28281平台参数地址
typedef struct PU_PLATFORM_GBT_PARA
{
    BOOL bEnable;
    CHAR szLoginDomain[PU_PLATFORM_INFO_LEN];
    CHAR szLoginName[PU_PLATFORM_INFO_LEN];    //设备ID与登录名相同
    CHAR szPlatformId[PU_PLATFORM_INFO_LEN];   //服务器编码
    CHAR szPassword[PU_PLATFORM_INFO_LEN];
    CHAR szServerIp[PU_IP4_ADDR_LEN];
    ULONG ulServerPort;
    CHAR szReserve[PU_RESERVE_LEN];            //szReserve[0]:网卡索引;
                                               //szReserve[1]:平台类型,入参,0:GB28181-1, 1:GB28181-2;
}PU_PLATFORM_GBT_PARA_S, *LPPU_PLATFORM_GBT_PARA_S;

//SDK主动注册的地址
typedef struct PU_PLATFORM_SDK_PARA
{
    BOOL bEnable;
    PU_SDK_PLATFORM_MODE_E enSdkPlatformMode;
    CHAR szDeviceId[PU_PLATFORM_INFO_LEN];
    CHAR szPlatformIp[PU_IP4_ADDR_LEN];
    ULONG szPlatformPort;
    CHAR szBackupPlatformIp[PU_IP4_ADDR_LEN];
    ULONG szBackupPlatformPort;
    PU_CONNECT_TYPE_E enConnectType;
    ULONG ulMeshIndex;                        //网卡索引
    CHAR szReserve[PU_RESERVE_LEN - sizeof(PU_CONNECT_TYPE_E) - sizeof(ULONG)];
}PU_PLATFORM_SDK_PARA_S, *LPPU_PLATFORM_SDK_PARA_S;

//ONVIF开关
typedef struct PU_ONVIF_SWITCH
{
    BOOL bEnable;                           //ONVIF开关
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ONVIF_SWITCH_S, *LPPU_ONVIF_SWITCH_S;


typedef enum PU_ONVIF_VERSION_ENUM
{
	ONVIF_VERSION_2_6 = 0,
	ONVIF_VERSION_2_6_1,
	ONVIF_VERSION_MAX
}PU_ONVIF_VERSION_ENUM_E;

/*** ONVIF 版本信息 ***/
typedef struct PU_ONVIF_VERSION_TYPE
{
	ULONG ulChannelId;                          //通道ID(预留，暂不用)
	PU_ONVIF_VERSION_ENUM_E enOnvifVersionType; //ONVIF 版本信息
	CHAR szReserve[PU_RESERVE_LEN];
}PU_ONVIF_VERSION_TYPE_S;

//ONVIFPwd参数
typedef struct PU_ONVIF_PWD_PARA
{
    CHAR szUserName[PU_USER_NAME_LEN];
    CHAR szOldPassword[PU_PASSWORD_LEN];
    CHAR szNewPassword[PU_PASSWORD_LEN];
    CHAR szReserve[PU_RESERVE_LEN];
}PU_ONVIF_PWD_PARA_S, *LPPU_ONVIF_PWD_PARA_S;

//升级上传文件路径结构体
typedef struct PU_UPGRADE_FILE_INFO
{
    CHAR cFileNum;                                                          //文件数目,最大文件数为 UPGRADE_FILE_NUM_MAX
    CHAR szFileName[PU_UPGRADE_FILE_NUM_MAX][PU_UPGRADE_FILE_LEN_MAX];    //文件路径及文件名，第一个为uImage,第二个为jffs2，第三、四个为扩展预留
    CHAR szReserve[PU_RESERVE_LEN];
}PU_UPGRADE_FILE_INFO_S, *LPPU_UPGRADE_FILE_INFO_S;

//升级回调数据结构，当前只包含传输的文件大小和总文件大小
typedef struct PU_UPGRADE_CALLBACK
{    
    ULONG ulCurrentSize;            //当前传输文件大小
    ULONG ulTotalSize;              //当前文件总大小
    ULONG ulCurrentFileNum;         //当前传输文件序号
    ULONG ulTotalFileNum;           //当前文件总个数
    CHAR szReserve[PU_RESERVE_LEN];
}PU_UPGRADE_CALLBACK_S, *LPPU_UPGRADE_CALLBACK_S;

//系统信息结构体
typedef struct PU_SYS_STATUS_INFO
{
    FLOAT fCpuOccupancyRate;                //CPU占用率
    ULONG ulMemTotal;                       //设备总内存(KB)
    ULONG ulMemFree;                        //空闲内存(KB)
    ULONG ulMemBuffer;                      //BUFF内存(KB)
    ULONG ulMemCache;                       //CACHE内存(KB)
    ULONG ulRecvRate;                       //网络接收速率byte
    ULONG ulSendRate;                       //网络发送速率byte
    ULONG ulFlashTotal;                     //总共Flash大小(KB)
    ULONG ulFlashFree;                      //空闲Flash大小(KB)
    CHAR szReserve[PU_RESERVE_LEN];
}PU_SYS_STATUS_INFO_S, *LPPU_SYS_STATUS_INFO_S;

//解码器结构体

//解码器通道信息
typedef struct PU_DECODER_CHANNEL_INFO
{
    unsigned long ulChannelID;                                      //解码器通道号
    char          szChannelName[PU_DEC_CHANNEL_NAME_LEN + 1];          //解码器通道名称
}PU_DECODER_CHANNEL_INFO_S;

//连接信息
typedef struct PU_DECLINK_INFO
{
    CHAR szDecVIP[PU_IP6_ADDR_LEN];         //视频IP地址
    ULONG ulDecVPort;                       //视频端口
    CHAR szDecAIP[PU_IP6_ADDR_LEN];         //音频IP地址
    ULONG ulDecAPort;                       //音频端口
    CHAR chTransProtocol;                   //传输协议: 1:RTP(TCP Client) 2:RTP(UDP) ...  音频视频解码需相同,当TCP时，以上IP、PORT为入参，当UDP时，IP、PORT为出参
    CHAR chDecFlags;                        //解码标志：0 仅解视频; 1 仅解音频; 2 同时解,同时解时使用VIP及VPORT即可
    CHAR chKeepaliveFlags;                  //保活标志,在VIP/VPort 发送RTSP保活信令: 0 不保活,1 保活 
    CHAR szRes[PU_RESERVE_LEN];             //预留,通过sdk发流:szRes[0]= 0;sdk建立信令，调用者直接发流:szRes[0]=1
}PU_DECLINK_INFO_S, *LPPU_DECLINK_INFO_S;

//解码信息结构体
typedef struct PU_DEC_INFO
{
    ULONG ulChannelId;                      //通道ID
    PU_DECLINK_INFO_S stDecLinkInfo;        //连接信息
}PU_DEC_INFO_S, *LPPU_DEC_INFO_S;

//初始化解码响应结构体
typedef struct PU_INIT_DECODE_INFO_RSP
{
    CHAR szDecMediaIp[PU_IP4_ADDR_LEN];     //解码器的媒体IP
    PU_PORT_INFO_S stDecPortInfo;           //解码器的端口信息
    CHAR szReserve[PU_RESERVE_LEN];
}PU_INIT_DECODE_INFO_RSP_S, *LPPU_INIT_DECODE_INFO_RSP_S;

//启动解码结构体
typedef struct PU_START_DECODE_INFO
{
    ULONG ulChannelId;                      //通道号
    PU_ENCODE_TYPE_E enVideoEncodeType;     //视频解码类型
    PU_ENCODE_TYPE_E enAudioEncodeType;     //音频解码类型
    PU_PROTOCOL_TYPE_E enProtocolType;      //初始化解码传输协议
    PU_PORT_INFO_S stLocalPortInfo;         //SDK的端口信息
    CHAR szLocalMediaIp[PU_IP4_ADDR_LEN];   //SDK的媒体IP
    CHAR szSessionID[PU_NAT_SESSIONID_LEN]; //会话ID
    CHAR szSessionUrl[PU_NAT_URL_LEN];      //会话URL
    CHAR szReserve[PU_RESERVE_LEN];
}PU_START_DECODE_INFO_S,*LPPU_START_DECODE_INFO_S;

//解码器端口能力
typedef struct PU_DEC_PORT_ABILITY
{
    CHAR szOutPutModes[PU_PORT_MODE_NUM_MAX];  //1\2\4\9\16 mode,0 the end
    ULONG ulPortType;                       //0:Audio, 1:Video 2:both
    BOOL bSupportEnlarge;                   //端口是否支持放大显示
}PU_DEC_PORT_ABILITY_S,*LPPU_DEC_PORT_ABILITY_S;

//解码器端口能力列表
typedef struct PU_DEC_PORT_ABILITY_LIST
{
    ULONG ulBNCNum;
    ULONG ulVGANum;
    ULONG ulHDMINum;
    ULONG ulDVINum;
    PU_ENCODE_TYPE_E enDecodeType[PU_DECODE_TYPE_MAX];                 //解码支持的类型
    PU_DEC_PORT_ABILITY_S stBNCAttribute[PU_BNC_PORT_MAX];             //输出类型：A/V/AV，输出窗口模式:共有1、2、4、9、16等几种模式；
    PU_DEC_PORT_ABILITY_S stVGAAttribute[PU_VGA_PORT_MAX];             //输出类型：A/V/AV，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；
    PU_DEC_PORT_ABILITY_S stHDMIAttribute[PU_HDMI_PORT_MAX];           //输出类型：A/V/AV，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；
    PU_DEC_PORT_ABILITY_S stDVIAttribute[PU_DVI_PORT_MAX];             //输出类型：A/V/AV，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；**/
}PU_DEC_PORT_ABILITY_LIST_S, *LPPU_DEC_PORT_ABILITY_LIST_S;

//解码器端口信息
typedef struct PU_DEC_PORT_INFO
{
    BOOL bEnable;                           //端口使能
    PU_PORT_MODE_E enPortMode;              //通道模式
    PU_FRAME_RATE_E enFrameRate;            //帧率  :30帧|| 60 帧
    PU_RESOLUTION_TYPE_E enDecResolution;   //解码输出分辨率
//     BOOL bEnlargeFlag;                   //是否支持放大,0: no support, 1: support
}PU_DEC_PORT_INFO_S, *LPPU_DEC_PORT_INFO_S;

//解码器端口信息列表
typedef struct PU_DEC_PORT_INFO_LIST
{
    ULONG ulBNCNum;
    ULONG ulVGANum;
    ULONG ulHDMINum;
    ULONG ulDVINum;
    PU_ENCODE_TYPE_E enDecodeType;                                  //解码类型
    PU_DEC_PORT_INFO_S stBNCAttribute[PU_BNC_PORT_MAX];                //输出类型：A/V/AV    ，输出窗口模式:共有1、2、4、9、16等几种模式；
    PU_DEC_PORT_INFO_S stVGAAttribute[PU_VGA_PORT_MAX];                //输出类型：A/V/AV    ，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；
    PU_DEC_PORT_INFO_S stHDMIAttribute[PU_HDMI_PORT_MAX];              //输出类型：A/V/AV    ，输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；
    PU_DEC_PORT_INFO_S stDVIAttribute[PU_DVI_PORT_MAX];                //输出类型：A/V/AV   ， 输出窗口模式:共有1、2、4、9、16等几种模式，放大支持标志；**/
//    CHAR chSameVInput;                                            //VGA/HDMI/DVI 是否同源模式：0000 0000 不同源, 0000 0111  同源 */
    CHAR chRes[PU_RESERVE_LEN];
}PU_DEC_PORT_INFO_LIST_S, *LPPU_DEC_PORT_INFO_LIST_S;

//通道与端口的映射关系
typedef struct PU_DEC_CHANNEL_PORT_MAP
{
    ULONG ulChannelID;                      //通道号
    PU_PORT_TYPE_E enPortType;              //端口类型
    ULONG ulPortIndex;                      //端口索引
    ULONG ulLayoutIndex;                    //通道所在的布局索引
}PU_DEC_CHANNEL_PORT_MAP_S, *LPPU_DEC_CHANNEL_PORT_MAP_S;

/*通道能力 :音频& 视频*/
/*例子能力：2 ----1 BNC1+D1 1 VGA1||HDMI1 + 1080P
5 ----1 BNC1+D1  4 VGA1||HDMI1 + D1
3 ----1 BNC1+D1  1 VGA1+720P  1 HDMI1+720P   ====   不同源
2 ----1 VGA1+720P  1 HDMI1+720P ====   不同源*/
typedef struct PU_DEC_CHANNEL_ABILITY
{
    PU_DEC_CHANNEL_PORT_MAP_S stChannelPortMap;                     //映射关系
    PU_ENCODE_TYPE_E enVideoDecFormats[PU_DECODE_TYPE_MAX];            //解码视频格式
    PU_ENCODE_TYPE_E enAudioDecFormats[PU_DECODE_TYPE_MAX];            //解码音频格式
    PU_RESOLUTION_TYPE_E enMaxDecResolution ;                       //解码最大分辨率
    PU_FRAME_RATE_E enMaxFrameRate;                                 //最大帧率  :30帧|| 60 帧
    BOOL bSupportDecryption;                                        //0: no support 1: support
    BOOL bSupportWaterMark;                                         //0: no support 1: support
//    BOOL bAudioFlag;                                              //音频开关:一个解码器仅支持一路音频输出，在一个通道里开启后，原来如果有通道开启过，会被默认开闭掉
}PU_DEC_CHANNEL_ABILITY_S,*LPPU_DEC_CHANNEL_ABILITY_S;

//通道能力列表
typedef struct PU_DEC_CHANNEL_ABILITY_LIST
{
    ULONG ulChannelNums;                                            //通道数
    PU_DEC_CHANNEL_ABILITY_S stChnAttri[PU_CHANNEL_NUM_MAX];           //通道属性
}PU_DEC_CHANNEL_ABILITY_LIST_S, *LPPU_DEC_CHANNEL_ABILITY_LIST_S;

/* OSD位置和颜色参数 */
typedef struct PU_DEC_OSD_PARA
{
    ULONG ulStartX;                                         
    ULONG ulStartY;
    ULONG ulFgColor;                        //字体颜色
    UCHAR ucFgAlpha;                        //前景透明度
    UCHAR ucBgAlpha;                        //背景透明度
    ULONG ulBgColor;                        //背景颜色
}PU_DEC_OSD_PARA_S, *LPPU_DEC_OSD_PARA_S;

//解码器OSD字符参数
typedef struct PU_DEC_OSD_STRING_INFO
{
    BOOL bEnable;                           //使能与否
    ULONG ulStringLen;                      //字符串长度
    CHAR szString[PU_OSD_MAX_LENGTH];       //字符串内容
    PU_DEC_OSD_PARA_S stOSDPara;            //OSD文字信息
}PU_DEC_OSD_STRING_INFO_S, *LPPU_DEC_OSD_STRING_INFO_S;

//通道信息
typedef struct PU_DEC_CHANNEL_INFO
{
    ULONG ulChannelId;                      //通道ID号
    BOOL bDenoiseFlag;                      //降噪使能
    BOOL bDemistFlag;                       //去雾使能
    BOOL bEnlargeStatus;                    //图像放大状态
    PU_DEC_OSD_STRING_INFO_S stOsdTextInfo; //OSD文字信息
}PU_DEC_CHANNEL_INFO_S, *LPPU_DEC_CHANNEL_INFO_S;

//通道信息列表
typedef struct PU_DEC_CHANNEL_INFO_LIST
{
    ULONG ulChannnelNums;                                           //通道数
    PU_DEC_CHANNEL_INFO_S stChannelInfo[PU_CHANNEL_NUM_MAX];           //通道信息
}PU_DEC_CHANNEL_INFO_LIST_S, *LPPU_DEC_CHANNEL_INFO_LIST_S;

//解码器解码信息
typedef struct PU_DEC_DECRYPTION_INFO
{
    ULONG               ulChannelId;                                //解密的通道号
    BOOL                bEnable;                                    //解密使能状态
    PU_ENCRYPT_TYPE_E   enDecryptionType;                           //解密算法类型
    CHAR                szVideoCrypto[PU_CRYPTION_PASSWD_LEN];         //视频密钥
    CHAR                szAudioCrypto[PU_CRYPTION_PASSWD_LEN];         //音频密钥
}PU_DEC_DECRYPTION_INFO_S, *LPPU_DEC_DECRYPTION_INFO_S;

//解码器音频端口信息
typedef struct PU_DEC_AUDIO_INFO
{
    PU_AUDIO_PORT_TYPE_E enAudioPortType;                           //音频端口类型
    BOOL bEnable;                                                   //音频端口使能与否
    ULONG ulChannelId;                                              //音频解码的通道号
    PU_ENCODE_TYPE_E enAudioDecodeType;                             //音频解码类型
    ULONG ulAudioVolume;                                            //音量
    PU_AUDIO_SAMPLERATE_E enAudioSampleRate;                        //音频采样率
}PU_DEC_AUDIO_INFO_S, *LPPU_DEC_AUDIO_INFO_S;

typedef struct PU_TIME_PLAN
{
    ULONG ulCycle;                          // 周期控制，0：仅一次，1：每周都按照时间段
    ULONG ulPeriod;                         // 周期： 0:一周全部 1~7:表示各天
    PU_TIME_S stStartTime;                  // 开始时间:  UTC 时间
    PU_TIME_S stEndTime;                    // 结束时间:  UTC 时间
    CHAR szReserved[PU_RESERVE_LEN];
}PU_TIME_PLAN_S, *LPPU_TIME_PALN_S;

/*通道录像计划*/
typedef struct PU_RECORD_PLAN
{
    ULONG ulChannelId;
    ULONG ulTotalPlanNum;                                           //总记录数
    PU_TIME_PLAN_S szRecordPlanList[PU_RECORD_PLAN_NUM];            //录像计划数组
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_PLAN_S, *LPPU_RECORD_PLAN_S;

/* 录像信息查询 */
typedef struct PU_RECORD_INQUIRE
{
    ULONG ulChannelId;
    PU_TIME_S stBeginTime;
    PU_TIME_S stEndTime;
    ULONG     ulBeginIndex;
    PU_RECORD_TYPE_E enRecordTypeList[PU_RECORD_TYPE_NUM];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_INQUIRE_S, *LPPU_RECORD_INQUIRE_S;

/* 前端录像信息 */
typedef struct PU_RECORD_INFO
{
    PU_RECORD_TYPE_E enRecordType;                                  // 录像类型
    PU_TIME_S stBeginTime;                                          // 开始时段
    PU_TIME_S stEndTime;                                            // 结束时段
    ULONG ulContentSize;                                            // 录像文件大小
    CHAR szContentID[PU_RECORD_CONTENTID_LEN];                      // 录像文件名
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_INFO_S, *LPPU_RECORD_INFO_S;

/* 前端录像信息列表 */
typedef struct PU_RECORD_LIST
{
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    PU_RECORD_INFO_S szRecordInfoList[PU_RECORD_INFO_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_RECORD_LIST_S, *LPPU_RECORD_LIST_S;


/************************开关量输出参数设置**************************/
typedef struct PU_SWITCH_OUTPUT_PARA
{
    ULONG  ulOutputId;
    CHAR   szOutputName[PU_DIO_NAME_LEN];   //名称，最大支持32字节
    ULONG  ulHoldTime;                      //保持时间 1-600  默认10秒
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_OUTPUT_PARA_S, *LPPU_SWITCH_OUTPUT_PARA_S;

/************************开关量输出状态设置**************************/
typedef struct PU_SWITCH_OUTPUT_STATE
{
    ULONG  ulOutputId;
    ULONG  ulSwitchType;                    //常开/常闭= 0：常开 1：常闭
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_DO_STATE_S, *LPPU_SWITCH_DO_STATE_S;

/************************开关量输入参数设置**************************/
typedef struct PU_SWITCH_INPUT_PARA
{
    ULONG ulInputId;
    CHAR  szInputName[PU_DIO_NAME_LEN];     //名称，最大支持32字节
    ULONG ulSwitchType;                     //常开/常闭= 0：常开 1：常闭
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SWITCH_INPUT_PARA_S, *LPPU_SWITCH_INPUT_PARA_S;

/************************开关量输入输出参数设置**********************/
typedef struct PU_DIO_PARA
{
    PU_SWITCH_INPUT_PARA_S  stInput[PU_DIO_NUM_MAX];
    PU_SWITCH_OUTPUT_PARA_S stOutput[PU_DIO_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DIO_PARA_S, *LPPU_DIO_PARA_S;

/**************告警联动 镜头信息**********************/
typedef struct PU_ALARM_LINKAGE_CAMERA_INFO
{
    ULONG  ulChannelId;
    ULONG  ulPreId;
    ULONG  ulCruiseId;
    ULONG  ulRecord;
    ULONG  ulSnap;
    ULONG  ulSnapInterval;  //联动抓拍间隔(毫秒)
	ULONG  ulDesignScan;    //0无效  1 2 3 4  5 分别 代表5个 扫描轨迹
	LONG   lHorizontalScan; //0无效  1 ~10    -1 ~ -10 分别 代表正反向 速度
	ULONG  ulFrameScan;     //0无效  5 ~3600  分别代表扫描间隔
	ULONG  ulRandomScan;    //0无效  5 ~3600  分别代表扫描间隔
	LONG   lPanormaScan;    //0无效  1 ~10    -1 ~ -10 分别 代表正反向 速度
	ULONG  ulVerticalScan;  //0无效  1 ~10  分别代表速度
    BOOL   bMailSend;       //是否联动到邮件发送 0:不联动 1:联动
}PU_ALARM_LINKAGE_CAMERA_INFO, *LPPU_ALARM_LINKAGE_CAMERA_INFO;

/*******************告警联动参数 ***************************/
typedef struct PU_ALARM_LINKAGE_PARA
{
    ULONG ulChannelNum;                                             //联动镜头个数
    ULONG ulDoNum;                                                  //联动开关量输出个数
    PU_ALARM_LINKAGE_CAMERA_INFO stCameraList[PU_ALARM_CAMERA_MAX]; //联动镜头信息列表
    ULONG szDoIdList[PU_ALARM_DO_MAX];                              //联动开关量输出ID
    CHAR szReserved[PU_RESERVE_LEN];                            	//szReserved[0]表示是否联动到邮件发送 0:不联动 1:联动
}PU_ALARM_LINKAGE_PARA_S, *LPPU_ALARM_LINKAGE_PARA_S;

//获取前端设备日志
typedef struct PU_LOG_REQ_PARA
{
    PU_TIME_S stStartTime;
    PU_TIME_S stEndTime;
    ULONG ulStartIndex;
    ULONG ulPrePageNum;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_LOG_REQ_PARA_S, *LPPU_LOG_REQ_PARA_S;

typedef struct PU_OPLOG_INFO
{
    PU_TIME_S stTime;
    CHAR acUser[PU_USER_NAME_LEN]; 
    CHAR acDeviceIp[PU_IP4_ADDR_LEN]; 
    CHAR acOptDetailDes[PU_LOG_INFO_NUM][PU_LOG_INFO_LEN];  
    ULONG ulOptObject; 
    ULONG ulOptResult; 
    ULONG ulRiskLevel; 
    CHAR szReserved[PU_RESERVE_LEN];
}PU_OPLOG_INFO_S, *LPPU_OPLOG_INFO_S;

//前端日志信息
typedef struct PU_LOG_INFO
{
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    CHAR  szLogInfoList[PU_LOG_INFO_NUM][PU_LOG_INFO_LEN];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_LOG_INFO_S, *LPPU_LOG_INFO_S;

//实时浏览结构体
typedef struct PU_REAL_PLAY_INFO
{
    ULONG ulChannelId;                                              //通道ID
    HWND hPlayWnd;                                                  //Windows窗口句柄    
    PU_STREAM_TYPE_E enStreamType;                                  //码流类型,主码流、子码流
    PU_VIDEO_TYPE_E enVideoType;                                    //流类型：视频流、音频流、复合流、录像流
    PU_PROTOCOL_TYPE_E enProtocolType;                              //传输协议类型，UDP,TCP
    PU_MEDIA_CALLBACK_TYPE_E enMediaCallbackType;                   //回调类型：0:RTP解密 1:RTP不解密  2:Frame 3:YUV  
    CHAR szLocalIp[PU_IP4_ADDR_LEN];                                //请求端IP
    BOOL bKeepLive;                                                 //是否保活
    PU_TIME_S stStartTime;                                          //请求预录、录像开始时间
    PU_TIME_S stEndTime;                                            //请求预录、录像结束时间
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;                       //加密类型，只支持AES加密
    CHAR szMediaCrypto[PU_CRYPTION_PASSWD_LEN];                     //加密密钥
    CHAR szReserved[PU_RESERVE_LEN];                                //szReserved[0-15]表示组播IP地址 szReserved[16-19]表示组播端口
                                                                    //szReserved[22]表示智能分析数据打包格式 0:XML,1:元数据
                                                                    //szReserved[23]表示元数据请求类型，取值参考枚举PU_METADATA_REQUEST_TYPE_E
}PU_REAL_PLAY_INFO_S, *LPPU_REAL_PLAY_INFO_S;




typedef struct PU_MEDIA_AES_CBC_ENC_PARA
{
    CHAR  szKey[PU_MEDIA_ENC_AES_KEY_STR_LEN];                      //加密密钥
    CHAR  szIv[PU_MEDIA_ENC_AES_CBC_IV_LEN];                        //IV
}PU_MEDIA_AES_CBC_ENC_PARA_S;

typedef struct PU_MEDIA_ENC_PARA
{
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;                       //加密类型，目前仅支持AES256 CBC模式
    VOID *pstEncPara;                                               //指向加密类型对应结构体的指针
}PU_MEDIA_ENC_PARA_S;

//实时浏览结构体
typedef struct PU_REAL_PLAY_INFO_V20
{
    ULONG ulChannelId;                                              //通道ID
    HWND hPlayWnd;                                                  //Windows窗口句柄    
    PU_STREAM_TYPE_E enStreamType;                                  //码流类型:主码流、子码流1、子码流2
    PU_VIDEO_TYPE_E enVideoType;                                    //流类型：视频流、音频流、复合流、录像流、元数据流
    PU_PROTOCOL_TYPE_E enProtocolType;                              //传输协议类型: 0:UDP 1:TCP 2:组播
    PU_MEDIA_CALLBACK_TYPE_E enMediaCallbackType;                   //回调类型：0:RTP解密 1:RTP不解密  2:Frame 3:YUV  
    CHAR szLocalIp[PU_IP6_ADDR_LEN];                                //请求端IP
    BOOL bKeepLive;                                                 //是否保活
    PU_TIME_S stStartTime;                                          //请求预录、录像开始时间
    PU_TIME_S stEndTime;                                            //请求预录、录像结束时间
    PU_IGT_DATA_TYPE_E enIGTDataType;                               //智能数据格式 0:XML格式 1:元数据格式
    CHAR szMulticastIP[PU_IP6_ADDR_LEN];                            //组播IP(组播流需要该参数)
    ULONG ulMulticastPort;                                          //组播端口(组播流需要该参数)
    CHAR szReserved[PU_RESERVE_LEN];                                //szReserved[0]表示元数据请求类型，取值参考枚举PU_METADATA_REQUEST_TYPE_E  
}PU_REAL_PLAY_INFO_V20_S, *LPPU_REAL_PLAY_INFO_V20_S;

//语音对讲/语音广播结构体
typedef struct PU_VOICE_INFO
{
    ULONG ulChannelId;                      //通道ID
    CHAR  szLocalAudioIp[PU_IP4_ADDR_LEN];  //本地音频IP
    BOOL  bFeedAudioData;                   //是否喂数据(语音对讲：TRUE时回调函数不能为空，FLASE时回调函数必须为空)
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_VOICE_INFO_S, *LPPU_VOICE_INFO_S;

//实时浏览结构体
typedef struct PU_MEDIA_PLAY_INFO
{
    ULONG ulChannelId;                                              //通道号
    PU_BUSINESS_TYPE_E enBusinessType;                              //实时浏览、语音对讲、语音广播、录像下载
    PU_STREAM_TYPE_E enStreamType;                                  //主码流、子码流1、子码流2
    PU_PROTOCOL_TYPE_E enProtocolType;                              //TCP、UDP、组播方式
    PU_VIDEO_CODE_TYPE_E enTansmitType;                             //ES、PS、TS
    PU_VIDEO_TYPE_E enVideoType;                                    //视频流、音频流、复合流
    CHAR szLocalIp[PU_IP4_ADDR_LEN];                                //请求端IP
    PU_PORT_INFO_S stLocalPortInfo;                                 //请求端的端口号
    ULONG ulLinkMode;                                               //连接类型，0直连 1中转
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;                       //加密类型
    CHAR szVideoCrypto[PU_CRYPTION_PASSWD_LEN];                     //视频密钥
    CHAR szAudioCrypto[PU_CRYPTION_PASSWD_LEN];                     //音频密钥
    PU_TIME_S stStartTime;                                          //请求预录、录像开始时间
    PU_TIME_S stEndTime;                                            //请求预录、录像结束时间
    CHAR szSessionIDForNAT[PU_NAT_SESSIONID_LEN];                   //用于NAT穿越的Session
    CHAR szSessionUrl[PU_NAT_URL_LEN];                              //用于NAT的会话URL
    CHAR szReserved[PU_RESERVE_LEN];                                //szReserved[0]表示是否保活 0:保活,1:不保活
                                                                    //szReserved[1]表示智能分析数据打包格式 0:XML,1:元数据
                                                                    //szReserved[2]~szReserved[18]表示AES256 CBC模式IV值(16字节+1结束符)
                                                                    //szReserved[20]表示请求的元数据分类，取值参见枚举PU_METADATA_REQUEST_TYPE_E
}PU_MEDIA_PLAY_INFO_S, *LPPU_MEDIA_PLAY_INFO_S;

//媒体流开始响应、录像下载响应
typedef struct PU_MEDIA_PLAY_RSP
{
    ULONG               ulSessionId;                                //媒体流的唯一标志
    PU_PORT_INFO_S      stPeerPortInfo;                             //发送端的端口信息
    CHAR                szPeerIp[PU_IP4_ADDR_LEN];                  //发送端的IP
    PU_ENCODE_TYPE_E    enVideoEncodeType;                          //视频编码类型
    PU_ENCODE_TYPE_E    enAudioEncodeType;                          //音频编码类型
    PU_TIME_S           stStartTime;                                //录像实际开始时间
    PU_TIME_S           stEndTime;                                  //录像实际结束时间
    CHAR                szReserved[PU_RESERVE_LEN];
}PU_MEDIA_PLAY_RSP_S, *LPPU_MEDIA_PLAY_RSP_S;

//实时浏览ACK参数
typedef struct PU_MEDIA_PLAY_ACK_INFO
{
    ULONG ulChannelId;                 //通道号
    ULONG ulSessionId;                 //媒体流的唯一标志
    ULONG ulVideoPayload;              //视频负载(载荷)类型
    ULONG ulAudioPayload;              //音频负载(载荷)类型
    ULONG ulIgtPayload;                //元数据负载(载荷)类型
    CHAR  szReserved[PU_RESERVE_LEN];  //保留
}PU_MEDIA_PLAY_ACK_INFO_S;

//实时浏览stop参数
typedef struct PU_MEDIA_PLAY_STOP_INFO
{
    ULONG ulChannelId;                 //通道号
    ULONG ulSessionId;                 //媒体流的唯一标志
    CHAR  szReserved[PU_RESERVE_LEN];  //保留
}PU_MEDIA_PLAY_STOP_INFO_S;

/* 硬盘信息 */
typedef struct PU_HARD_DISK_PARA
{
    CHAR szDiskFac[PU_FAC_NAME_LEN];
    PU_DISK_TYPE_E enDiskType;
    ULONG ulAllSpace;
    ULONG ulLeftSpace;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_HARD_DISK_PARA_S;

//主设备能力
typedef struct PU_DEVICE_ABILITY
{
    ULONG ulVideoInputChannelNum;           //视频输入通道数
    ULONG ulAudioInputChannelNum;           //音频输入通道数
    ULONG ulAlarmDINum;                     //告警输入数
    ULONG ulAlarmDONum;                     //告警输出数
    ULONG ulSerialPortNum;                  //串口数
    ULONG ulNetworkCardNum;                 //网口数
    ULONG ulHardDiskNum;                    //硬盘数
    ULONG ulPTZNum;                         //云台数
    ULONG ulTalkbackInputNum;               //语音对讲输入数
    ULONG ulTalkbackOutputNum;              //语音对讲输出数
    ULONG ulRTPOverFlag;                    //传输协议: 0:RTPoverUDP 1:RTPoverTCP 2:RTPoverUDP&TCP
    PU_HARD_DISK_PARA_S stHardDiskInfo;     //硬盘信息
    CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICE_ABILITY_S, *LPPU_DEVICE_ABILITY_S;

/* 流能力 */
typedef struct PU_STREAM_ABILITY_PARA
{
    PU_STREAM_TYPE_E enStreamType;                                  //视频流类型
    PU_ENCODE_TYPE_E enVideoFormat[PU_VIDEO_FORMAT_NUM];            //视频编码格式
    PU_RESOLUTION_TYPE_E enMaxResolution;                           //最大分辨率
    ULONG ulMaxBitRate;                                             //最大码率
    ULONG ulMaxFrmRate;                                             //最大帧率
    ULONG ulMaxIFrameInterval;                                      //最大I帧间隔
    PU_VIDEO_TYPE_E enVideoType;                                    //视频流类型
    CHAR szReserved[PU_RESERVE_LEN];
}PU_STREAM_ABILITY_PARA_S, *LPPU_STREAM_ABILITY_PARA_S;

/* 通道流能力 */
typedef struct PU_STREAM_ABILITY
{
    ULONG ulChannelId;
    CHAR  szCameraName[PU_DEVICE_NAME_LEN];
    ULONG ulPTZType;
    ULONG ulPresetNum;
    ULONG ulCruiseTrackNum;
    ULONG ulMaxStreamNum;
    BOOL  bPtzFastLocate;
    BOOL  bPtzHorizotalScan;
    BOOL  bPtzVerticalScan;
    PU_STREAM_ABILITY_PARA_S stStreamAbility[PU_STREAM_NUM];  
    CHAR szReserved[PU_RESERVE_LEN];
}PU_STREAM_ABILITY_S, *LPPU_STREAM_ABILITY_S;

/* 通道流能力V2 */
typedef struct PU_STREAM_ABILITYV2
{
	ULONG ulChannelId;
    CHAR  szCameraName[PU_DEVICE_NAME_LEN];
    ULONG ulPTZType;
    ULONG ulPresetNum;
    ULONG ulCruiseTrackNum;
    ULONG ulMaxStreamNum;
    BOOL  bPtzFastLocate;
    BOOL  bPtzHorizotalScan;
    BOOL  bPtzVerticalScan;
    PU_STREAM_ABILITY_PARA_S stStreamAbility[PU_STREAM_NUM_V2];  
    CHAR szReserved[PU_RESERVE_LEN];
}PU_STREAM_ABILITYV2_S, *LPPU_STREAM_ABILITYV2_S;

/*前向纠错*/
typedef struct PU_FEC_PARA
{
    ULONG ulChannelId;
    BOOL bEnable;                                       //前向纠错使能
    PU_FEC_PACKET_LOSS_RATIO_E enPacketLossRatio;       //前向纠错丢包率
    CHAR szReserved[PU_RESERVE_LEN];
}PU_FEC_PARA_S, *LPPU_FEC_PARA_S;

/*SEC参数*/
typedef struct PU_SEC_PARA
{
    ULONG ulChannelId;
    BOOL bEnable;                                       //前向纠错使能
    PU_SEC_PACKET_LOSS_RATIO_E enPacketLossRatio;       //前向纠错丢包率
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SEC_PARA_S, *LPPU_SEC_PARA_S;

//动态码流/帧率
typedef struct PU_DYNAMIC_STREAM_INFO
{
    ULONG ulChannelId;
    BOOL  ulEnable;                         //动态码流是否使能
    ULONG ulDynamicFrameRate;               //动态帧率
    ULONG ulDynamicBitRate;                 //动态码率
    CHAR szReserved[PU_RESERVE_LEN];        //szReserved[0]动态帧率是否使能
}PU_DYNAMIC_STREAM_INFO_S, *LPPU_DYNAMIC_STREAM_INFO_S;

typedef struct PU_DEVICE_REGISTER_RSP
{
    PU_ERROR_CODE_E enErrorCode;
    CHAR  szRedirectIp[PU_IP4_ADDR_LEN];
    ULONG ulRedirectPort;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DEVICE_REGISTER_RSP_S, *LPPU_DEVICE_REGISTER_RSP_S;

//device common callback event struct, include: off line, upload image complete notify 
typedef struct PU_EVENT_COMMON
{
    PU_EVENT_TYPE_E enEventType;            //事件类型
    ULONG           ulIdentifyID;           //唯一标识的ID号
    ULONG           ulChannelId;
}PU_EVENT_COMMON_S, *LPPU_EVENT_COMMON_S;

//device stream package change callback event struct
typedef struct PU_EVENT_STEAM_PACKAGE_CHANGE
{
    PU_EVENT_COMMON_S stPuEventCommon;      //通用事件
    PU_STREAM_MODE_E enStreamMode;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_STEAM_PACKAGE_CHANGE_S, *LPPU_EVENT_STEAM_PACKAGE_CHANGE_S;

//device stream package change callback event struct
typedef struct PU_EVENT_UPLOAD_IMAGE_URL
{
    PU_EVENT_COMMON_S stPuEventCommon;                              // 通用事件
    ULONG ulSessionId;                                              // 前端获取抓拍图片上载URL请求会话ID,用于前端标识一次唯一的会话
    CHAR  szContentID[PU_SNAP_IMAGE_NAME_LEN];                      // 图片名
    ULONG ulLocation;                                               // 图片存储位置: 0:平台  1:前端
    PU_SNAPSHOT_TYPE_E enSnapshotType;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_UPLOAD_IMAGE_URL_S, *LPPU_EVENT_UPLOAD_IMAGE_URL_S;

typedef struct PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    ULONG ulSessionId;                                              //上传完成通知会话ID,用于前端标识一次唯一的会话
    CHAR  szContentID[PU_SNAP_IMAGE_NAME_LEN];                      //图片名
    ULONG ulContentSize;                                            //图片大小
    CHAR  szSnapTime[PU_TIME_TOTAL_LEN];                            //抓拍时间 格式："2009-07-14 15:41:14"
    PU_SNAPSHOT_TYPE_E enSnapshotType;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S, *LPPU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S;

//device auto register callback event struct
typedef struct PU_EVENT_REGISTER
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    CHAR  szDeviceId[PU_MAC_ADDR_LEN];
    CHAR  szDeviceIp[PU_IP4_ADDR_LEN];
    CHAR  szDeviceType[PU_DEVICE_TYPE_LEN];
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_EVENT_REGISTER_S, *LPPU_EVENT_REGISTER_S;

//解码器注册回调
typedef struct PU_DEC_CALLBACK_INFO
{
    PU_EVENT_COMMON_S stPuEventCommon;                                 //通用事件
    CHAR szDecoderID[PU_DECODER_ID_LEN + 4];                           //解码器ID
    CHAR szDecIP[PU_IP4_ADDR_LEN];                                     //解码器IP
    ULONG ulDecPort;                                                   //解码器port
    CHAR szDeviceType[PU_DEC_CHANNEL_NAME_LEN];                        //设备型号
    ULONG ulVideoPayloadTypeNum;                                       //支持的视频PayloadType个数。最大值不超过16
    ULONG ulAudioPayloadTypeNum;                                       //支持的音频PayloadType个数。最大值不超过16
    ULONG ulChannelNum;                                                //解码器有效通道个数，最大不超过
    CHAR szDecoderName[PU_DECODER_NAME_LEN + 4];                       //解码器名称
    CHAR szDecoderEncoding[PU_DECODER_ENCODING_LEN + 4];               //解码器编码格式 
    UCHAR ucVideoPayloadTypeArray[PU_DEC_PAY_LOAD_TYPE_NUM];           //支持的视频PayloadType固定数组。元素个数为16。实际元素个数为ulVideoPayloadTypeNum
    UCHAR ucAudioPayloadTypeArray[PU_DEC_PAY_LOAD_TYPE_NUM];           //支持的音频PayloadType固定数组。元素个数为16。实际元素个数为ulAudioPayloadTypeNum
    PU_DECODER_CHANNEL_INFO_S stChannelInfoArray[PU_CHANNEL_NUM_MAX];  //解码器通道信息的数组元素个数为ulChannelNum
}PU_DEC_CALLBACK_INFO_S, *LPPU_DEC_CALLBACK_INFO_S;

//连接状态回调
typedef struct PU_CONNECT_STATUS
{
    PU_EVENT_COMMON_S         stPuEventCommon;                      //通用事件
    CHAR                      szDeviceIP[PU_IP4_ADDR_LEN];          //设备IP
    ULONG                     ulDevicePort;                         //设备port
    CHAR                      szDeviceFac[PU_FAC_NAME_LEN];         //设备厂商,固定为：HUAWEI PU
    CHAR                      szDeviceID[PU_MAC_ADDR_LEN + 4];      //设备ID
    CHAR                      szDeviceType[PU_DEVICE_NAME_LEN];     //设备型号
    CHAR                      szReserved[PU_RESERVE_LEN];
}PU_CONNECT_STATUS_S, *LPPU_CONNECT_STATUS_S;

typedef struct PU_EVENT_TRANSPARENT
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    PU_TRANSPARENT_CMD_S stTransparentCmd;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EVENT_TRANSPARENT_S, *LPPU_EVENT_TRANSPARENT_S;

typedef struct PU_WATER_MARK
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    PU_ALARM_ACTION_E enAction;                                     //告警发生/消除
}PU_WATER_MARK_S, *LPPU_WATER_MARK_S;

//精确数字
typedef struct PU_PRECISE_FIGURES
{
    ULONG ulIntValue;   //数字整数部分
    ULONG ulDotValue;   //数字小数部分
}PU_PRECISE_FIGURES_S;

//镜头信息
typedef struct PU_LENS_INFO
{
    ULONG ulChnID;
    PU_PRECISE_FIGURES_S stLZoomRatio;                  //镜头变倍
    PU_PRECISE_FIGURES_S stDZoomRatio;                  //数字变倍
    PU_PRECISE_FIGURES_S stHorDegree;                   //水平视场角
    PU_PRECISE_FIGURES_S stVerDegree;                   //垂直视场角
    PU_PRECISE_FIGURES_S stFocalMillimeter;             //焦距
    CHAR szReserved[PU_RESERVE_LEN];
}PU_LENS_INFO_S;

//地理位置信息
typedef struct PU_CAM_GEOG_POSITION
{
    ULONG ulChnID;                              //通道号
    CHAR  szAzimuth[CAM_POSITION_STR_LEN];      //方位角
    CHAR  szPitch[CAM_POSITION_STR_LEN];		//俯仰角
    CHAR  szLongitude[CAM_POSITION_STR_LEN];	//经度
    CHAR  szLatitude[CAM_POSITION_STR_LEN];	    //纬度  
    CHAR  szReserved[PU_RESERVE_LEN];   //szReserved[0]代表获取经纬度方式; szReserved[1] bit0对应nHeight, bit1对应fAzimuth, bit2对应fPitch, bit3对应dLongitude，bit4对应dLatitude
}PU_CAM_GEOG_POSITION_S;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
//架设高度
typedef struct PU_CAM_INSTALL_HEIGHT
{
    ULONG ulChnID;
    ULONG ulCentimeter;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_CAM_INSTALL_HEIGHT_S;

//CMOS尺寸
typedef struct PU_CMOS_SIZE_PARA
{
    ULONG ulChnID;
    ULONG ulIntHorSize;
    ULONG ulDotHorSize;
    ULONG ulIntVerSize;
    ULONG ulDotVerSize;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_CMOS_SIZE_PARA_S;

typedef struct PU_PTZ_REPORT_INFO
{
    PU_EVENT_COMMON_S       stPuEventCommon;                       //通用事件
    PU_LENS_INFO_S          stCamDegree;
    PU_CAM_GEOG_POSITION_S  stCamPosition;
    PU_CAM_INSTALL_HEIGHT_S stCamFixHeight;
    PU_CMOS_SIZE_PARA_S     stCamCMOSSize;
}PU_PTZ_REPORT_INFO_S, *LPPU_PTZ_REPORT_INFO_S;


typedef union PU_EVENT_NOTIFY_BODY
{
    PU_EVENT_COMMON_S stPuEventCommon;                              //通用事件
    PU_EVENT_STEAM_PACKAGE_CHANGE_S stPuStreamPackgeChange;         //IPC流套餐变更
    PU_EVENT_UPLOAD_IMAGE_URL_S stPuUploadImageURL;                 //前端请求上传图片URL
    PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S stUploadCompNotify;         //前端图片上传完成通知

    PU_DEC_CALLBACK_INFO_S stPuDecRegister;                         //前端DEC主动注册
    PU_CONNECT_STATUS_S    stPuConnetStatus;                        //前端设备连接状态
    PU_EVENT_REGISTER_S    stPuIpcRegister;                         //前端IPC主动注册
    PU_EVENT_TRANSPARENT_S stTransparentChannelNotify;              //透明通道数据上报
    PU_WATER_MARK_S        stPuWaterMark;                           //数字水印
    PU_PTZ_REPORT_INFO_S   stVisualInfo;                            //可视化信息上报
    
}PU_EVENT_NOTIFY_BODY_U, *LPPU_EVENT_NOTIFY_BODY_U;

//磁盘满策略
typedef struct RECORD_STRATEGY
{
    ULONG ulChannelId;
    ULONG ulStrategy;                       // 存储策略:0循环覆盖  1停止录像
    ULONG ulMinRecordTime;                  // 最小预录时间
    ULONG ulPreAlarmRecordTime;             // 警前预录时间 V2R3版本 0:不预录 65535:按照内存能力最大时间预录 其余根据设备能力5-20s可设
                                            // V2R3之前版本 <=10s
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_RECORD_STRATEGY_S, *LPPU_RECORD_STRATEGY_S;

//看守位参数(仅预置位)
typedef struct GUARD_POSITION_PARA
{
    ULONG ulPtzId;
    BOOL  bEnable;
    ULONG ulPresetIndex;
    ULONG ulWaitTime;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_GUARD_POSITION_PARA_S, *LPPU_GUARD_POSITION_PARA_S;

typedef struct PU_HORIZONTAL_SCAN_PARA
{
	ULONG ulSpeed;             //速度
	PU_PTZ_DIRECTION_E enDirection; //方向，支持左/右
}PU_HORIZONTAL_SCAN_PARA_S;

typedef struct PU_RANDOM_SCAN_PARA
{
	ULONG ulInterval;          //间隔
}PU_RANDOM_SCAN_PARA_S;

typedef struct PU_PANORAMA_SCAN_PARA
{
	ULONG ulSpeed;             //速度
	PU_PTZ_DIRECTION_E enDirection; //方向，支持左/右
}PU_PANORAMA_SCAN_PARA_S;

typedef struct PU_VERTICAL_SCAN_PARA
{
	ULONG ulSpeed;              //速度
}PU_VERTICAL_SCAN_PARA_S;

typedef struct PU_FRAME_SCAN_PARA
{
	ULONG     ulFrameInterval;    //帧间隔
}PU_FRAME_SCAN_PARA_S;

typedef struct PU_USER_DEFINED_SCAN_PARA
{
	ULONG     ulUserDefineIndex;  //花样扫描路径
}PU_USER_DEFINED_SCAN_PARA_S;

typedef struct PU_CRUISE_SCAN_PARA
{
	ULONG     ulCruiseIndex;      //巡航轨迹序列号
}PU_CRUISE_SCAN_PARA_S;

typedef struct PU_PRESET_SCAN_PARA
{
	ULONG     ulPresetIndex;      //预置位序列号
}PU_PRESET_SCAN_PARA_S;

typedef union PU_GUARD_POINT_PARA
{
	PU_PRESET_SCAN_PARA_S stPresetPara;           //预置位
	PU_CRUISE_SCAN_PARA_S stCruisePara;           //巡航轨迹
	PU_USER_DEFINED_SCAN_PARA_S stUserDefinedPara;//花样扫描
	PU_HORIZONTAL_SCAN_PARA_S stHorPara;          //水平扫描
	PU_FRAME_SCAN_PARA_S stFramePara;             //帧扫描
	PU_RANDOM_SCAN_PARA_S stRandomPara;           //随机扫描
	PU_PANORAMA_SCAN_PARA_S stPanoramePara;       //全景扫描
	PU_VERTICAL_SCAN_PARA_S stVerticalPara;       //垂直扫描
}PU_GUARD_POINT_PARA_U;

//守望参数
typedef struct GUARD_POSITION_PARA_EX
{
	ULONG ulPtzId;
	BOOL  bEnable;
	ULONG ulWaitTime;
	PU_GUARD_POINT_TYPE_E enGuardType;                         //看守类型
	PU_GUARD_POINT_PARA_U unGuardPara;                         //看守参数
	CHAR  szReserved[PU_RESERVE_LEN];
}PU_GUARD_POSITION_PARA_EX_S, *LPPU_GUARD_POSITION_PARA_EX_S;

//电子云台参数
typedef struct PU_EPTZ_PARA
{
    ULONG ulChannelId;
    PU_STREAM_TYPE_E enStreamType;
    BOOL  bEnable;
    ULONG ulLeftPercent;
    ULONG ulTopPercent;
    ULONG ulWidthPercent;
    ULONG ulHeightPercent;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_EPTZ_PARA_S, *LPPU_EPTZ_PARA_S;

//码流平滑参数
typedef struct PU_STREAM_SMOOTH_PARA
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulTcpUpperCoefficient;
    ULONG ulUdpUpperCoefficient;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_STREAM_SMOOTH_PARA_S, *LPPU_STREAM_SMOOTH_PARA_S;

typedef struct PU_STREAM_SMOOTH_PARA_EX
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulUpperCoefficient;   //码流平滑倍数,范围1-8,对应设备倍数1.5-5.0,步长0.5
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_STREAM_SMOOTH_PARA_EX_S, *LPPU_STREAM_SMOOTH_PARA_EX_S;

//云台位置信息：总变倍数（1 ~ 30*12=240）
typedef struct PU_PTZ_CURRENT_LOCATION
{
    LONG  lPTZHorDegree;                    //水平角度(0~359)
    LONG  lPTZVerDegree;                    //垂直角度(-10~90)
    ULONG ulLenMultiple;                    //镜头变倍整数部分(1~30，如果数字变倍不为0镜头变倍默认为最大值30)
    ULONG ulDotLenMultiple;                 //镜头变倍小数部分(0~99，支持小数点后一位数字）
    ULONG ulZoomRatio;                      //数字变倍整数部分(0~12，镜头变倍达到最大值后设置，0表示不设置，总变倍数为相乘关系)
    ULONG ulDotZoomRatio;                   //数字变倍小数部分(0~99，支持小数点后一位数字）
    LONG  lPTZDotHorDegree;                 //水平角度小数部分(0~99，支持小数点后一位数字）
    LONG  lPTZDotVerDegree;                 //垂直角度小数部分(-99~99，支持小数点后一位数字）
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_PTZ_CURRENT_LOCATION_S, *LPPU_PTZ_CURRENT_LOCATION_S;

//云台位置信息扩展：总变倍数（1 ~ 30*12=240）
typedef struct PU_PTZ_CURRENT_LOCATION_EX
{
    LONG  lPTZHorDegree;                    //水平角度(0~359)
    LONG  lPTZVerDegree;                    //垂直角度(-10~90)
    ULONG ulLenMultiple;                    //镜头变倍整数部分(1~30，如果数字变倍不为0镜头变倍默认为最大值30)
    ULONG ulDotLenMultiple;                 //镜头变倍小数部分(0~99，支持小数点后一位数字）
    ULONG ulZoomRatio;                      //数字变倍整数部分(0~12，镜头变倍达到最大值后设置，0表示不设置，总变倍数为相乘关系)
    ULONG ulDotZoomRatio;                   //数字变倍小数部分(0~99，支持小数点后一位数字）
    LONG  lPTZDotHorDegree;                 //水平角度小数部分(0~99，支持小数点后一位数字）
    LONG  lPTZDotVerDegree;                 //垂直角度小数部分(-99~99，支持小数点后一位数字）
	FLOAT fAbsPTZHorDegree;                 //水平绝对角度
	FLOAT fAbsPTZVerDegree;                 //垂直绝对角度
	LONG  lZoomPos;                         //变焦位置
	LONG  lFocusPos;                        //对焦位置
	BOOL  bZoomFlag;                        //ture使用倍率，false使用电机位置
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_PTZ_CURRENT_LOCATION_EX_S;

typedef struct PU_IGT_ALARM_PARA
{
    ULONG ulChannelId;
    BOOL  bIgtEnable;                       //智能总开关
    BOOL  bTrackEnable;                     //目标轨迹跟踪使能
    PU_IGT_FIELD_TYPE_E enFieldType;        //场景模式类型
    PU_IGT_MINTARGET_SIZE_E enMinTargetSize;//前景目标最小尺寸设定
    PU_IGT_SHADOW_MODE_E enShadowMode;      //去阴影模式设定
    PU_IGT_DETECT_SENS_E enDetectSens;      //目标检测灵敏度设定
    BOOL bInsensitiveObject;                //是否显示不敏感目标信息
    UCHAR szReserved[PU_RESERVE_LEN];       //szReserved[0] 表示最小目标尺寸宽(5~200且小于最大尺寸)
                                            //szReserved[1] 表示最小目标尺寸高(5~200且小于最大尺寸)
                                            //szReserved[2] 表示最大目标尺寸宽(5~200)
                                            //szReserved[3] 表示最大目标尺寸高(5~200)
                                            //szReserved[4] 表示背景更新速率
                                            //szReserved[5] 表示最大目标个数
}PU_IGT_ALARM_PARA_S, *LPPU_IGT_ALARM_PARA_S;

typedef struct PU_IGT_POINT
{
    USHORT usPointPosX;                     /*点X轴坐标(0-352)*/
    USHORT usPointPosY;                     /*点Y轴坐标(0-288)*/
}PU_IGT_POINT_S;

typedef struct PU_POINT
{
    USHORT usPosX;                          //X轴坐标(0-352)
    USHORT usPosY;                          //Y轴坐标(0-288)
}PU_POINT_S;

typedef struct PU_IGT_TW_LINE
{
    UCHAR ucDirection;                      /*检测方向: 0:both 1:Left->right 2:right->left */
    PU_IGT_POINT_S stStartPoit;             /*绊线起始点*/
    PU_IGT_POINT_S stEndPoit;               /*绊线终止点*/
    ULONG ulLineIndex;                      /*绊线索引*/
    BOOL bEnable;                           /*该线是否使能*/
    CHAR szLineName[PU_IGT_LINE_NAME_LEN];  /*绊线名称*/
}PU_IGT_TW_LINE_S, *LPPU_IGT_TW_LINE_S;

typedef struct PU_IGT_TW_LINE_LIST
{
    ULONG ulLineNum;
    PU_IGT_TW_LINE_S szTWLineList[PU_TRIPWIRE_LEN_NUM_MAX];
}PU_IGT_TW_LINE_LIST_S;

/* ------------绊线检测参数结构体------------ */
typedef struct PU_TW_ALARM_PARA
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulAlarmInterval;                  //告警检测间隔
    PU_IGT_TARGET_MODE_E  enTargetDetecMode;//目标识别模式
    PU_IGT_TW_LINE_LIST_S stlineList;       /*绊线数组：获取时会返回所有绊线坐标信息，如果坐标为0说明不再当前镜头范围内（会返回索引）；*/
                                            /*设置时该参数可选，如果ulLineNum不等于0会全部下放，等于0时不下发*/
    PU_ALARM_TIME_LIST_S stTWGuardPlan;     //布防计划
    ULONG ulSensitivity;
    CHAR  szReserved[PU_RESERVE_LEN-sizeof(ULONG)];
}PU_TW_ALARM_PARA_S, *LPPU_TW_ALARM_PARA_S;

typedef struct PU_IGT_TW_LINE_ITEM
{
    ULONG ulChannelId;
    PU_IGT_OPT_TYPE_E enOptType;
    PU_IGT_TW_LINE_S stIgtTwLine;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IGT_TW_LINE_ITEM_S, *LPPU_IGT_TW_LINE_ITEM_S;

/*区域检测*/
typedef struct PU_IGT_AREA
{
    UINT uPointNum;                                                 /*区域多边形顶点数目*/
    PU_IGT_POINT_S stPoint[PU_IGT_AREA_POINTS_NUM];                 /*点坐标*/
    ULONG ulAreaIndex;                                              /*区域索引*/
    BOOL bEnable;                                                   /*改区域是否使能*/
    CHAR szAreaName[PU_IGT_AREA_NAME_LEN];                          /*区域名称*/
    PU_PTZ_CURRENT_LOCATION_S stLocation;                           /*云台位置信息*/
}PU_IGT_AREA_S, *LPPU_IGT_AREA_S;

typedef struct PU_IGT_AERADTC_LIST
{
    ULONG ulAreaNum;
    PU_IGT_AREA_S stArea[PU_IGT_AREA_NUM];
}PU_IGT_AERADTC_LIST_S;

typedef struct PU_IGT_AEREDTC_ALARM_PARA
{
    ULONG ulChannelId;
    BOOL  bEnable;
    ULONG ulAlarmInterval;                  //告警检测间隔
    PU_IGT_TARGET_MODE_E enTargetDetecMode; //目标识别模式
    ULONG ulRemainTime;                     //停留时间
    PU_IGT_AERADTC_LIST_S stAreaDtcList;    //区域数组：获取时会返回所有区域信息，如果区域坐标为0说明不再当前镜头范围内(会返回索引)
                                            //设置时该参数可选，如果ulAreaNum不等于0会全部下放，等于0时不下发
    PU_ALARM_TIME_LIST_S stAreaGuardPlan;   //布防计划
    CHAR  szReserved[PU_RESERVE_LEN];       
}PU_IGT_AREADTC_ALARM_PARA_S, *LPPU_IGT_AREADTC_ALARM_PARA_S;

typedef struct PU_IGT_AREA_ITEM
{
    ULONG ulChannelId;
    PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType;
    PU_IGT_OPT_TYPE_E enOptType;
    PU_IGT_AREA_S stIgtArea;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IGT_AREA_ITEM_S, *LPPU_IGT_AREA_ITEM_S;

//Discover 发现响应包
typedef struct PU_DISCOVER_DEVICE_INFO
{
    CHAR  szDeviceMac[PU_MAC_ADDR_LEN];        //设备MAC地址
    CHAR  szDeviceType[PU_DEVICE_TYPE_LEN];    //设备型号
    CHAR  szDeviceVersion[PU_VERSION_LEN];     //设备版本号
    CHAR  szDeviceName[PU_DEVICE_NAME_LEN];    //设备名称
    CHAR  szDeviceIp[PU_IP4_ADDR_LEN];         //设备IP
    CHAR  szDeviceMask[PU_IP4_ADDR_LEN];       //设备掩码
    CHAR  szDeviceGateway[PU_IP4_ADDR_LEN];    //设备网关
    CHAR  szSerialNumber[PU_SERIAL_LEN];       //SN号
	UINT  uDhcpEnable;                         //DHCP是否使能 0：未使能  ,  1：使能 ,  2：未知，为兼容老版本
	CHAR  szReserved[PU_RESERVE_LEN];          //预留
}PU_DISCOVER_DEVICE_INFO_S, *LPPU_DISCOVER_DEVICE_INFO_S;

typedef struct PU_DISCOVER_DEVICE_LIST
{
    ULONG ulDeviceNum;
    PU_DISCOVER_DEVICE_INFO_S stDeviceInfo[PU_DEVICE_NUM_MAX];
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DISCOVER_DEVICE_LIST_S, *LPPU_DISCOVER_DEVICE_LIST_S;

/* 网口地址参数 */
typedef struct PU_DEVICE_ETHERNET_PARA
{
    BOOL bDhcpEnable;                          //是否启用DHCP
    CHAR szIPAddress[PU_IP4_ADDR_LEN];         //IP地址
    CHAR szSubNetMask[PU_IP4_ADDR_LEN];        //子网掩码
    CHAR szGateWayAddress[PU_IP4_ADDR_LEN];    //网关地址
    CHAR szFirstDNSAddress[PU_IP4_ADDR_LEN];   //第一组DNS地址
    CHAR szSecondDNSAddress[PU_IP4_ADDR_LEN];  //第二组DNS地址
    CHAR szReserved[PU_RESERVE_LEN];           //szReserved[0],表示网口索引,0表示网卡1,1表示网卡2
}PU_DEVICE_ETHERNET_PARA_S, *LPPU_DEVICE_ETHERNET_PARA_S;

/* NTP参数 */
typedef struct PU_NTP_PARA
{
    BOOL  bNTPEnable;                       //NTP使能
    ULONG ulSynInterval;                    //NTP同步间隔
    CHAR  szNTPAddress[PU_DOMAIN_LEN];      //NTP服务器地址:域名或者IP地址
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_NTP_PARA_S, *LPPU_NTP_PARA_S;

/* GPS校时参数 */
typedef struct PU_GPS_PARA
{
	BOOL  enGPSEnable;  //GPS使能
	ULONG ulInterval;   //GPS时间同步间隔
	CHAR  szReserved[PU_RESERVE_LEN];
}PU_GPS_PARA_S,*LPPU_GPS_PARA_S;

//组播参数 
typedef struct PU_MULTICAST_PARA
{
    ULONG ulMeshIndex;                       //网卡索引
    CHAR szLocalIP[PU_MULTICAST_ADDR_LEN];   //多播地址
    ULONG ulPort;                            //多播端口
    CHAR szReserved[PU_RESERVE_LEN];         //保留
}PU_MULTICAST_PARA_S;

//红外灯参数
typedef struct  PU_IRLIGHT_PARA
{
    BOOL  bEnable;                          //使能
    ULONG ulIRLightLum;                     //亮度
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_IRLIGHT_PARA_S;

typedef struct PU_IRLIGHT_LIST
{
    ULONG ulChannelId;
    PU_IRLIGHT_MODE_E enIRLightMode;
    PU_IRLIGHT_PARA_S stIRLightMPara[PU_IRLIGHT_NUM_MAX];           //红外灯数据，手动模式时必填
    CHAR szReserved[PU_RESERVE_LEN];                                //szReserved[0] 智能红外开关，0:打开 1:关闭
                                                                    //szReserved[1] 表示智能红外系数 1-100
    																//szReserved[2] 激光安全限制开关，0:关闭 1:打开
}PU_IRLIGHT_LIST_S, *LPPU_IRLIGHT_LIST_S;

/* SNMPv1v2c社团信息 */
typedef struct PU_SNMP_COMMUNITY_INFO
{
    PU_SNMP_COMMUNITY_ATTR_E enCommunityAttr;                       //社团属性
    CHAR szCommunityName[PU_SNMP_COMMUNITY_NAME_LEN];               //社团名
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNMP_COMMUNITY_INFO_S, *LPPU_SNMP_COMMUNITY_INFO_S;

/* SNMPv1v2c社团列表 */
typedef struct PU_SNMP_COMMUNITY_LIST
{
    ULONG ulCommunityNum;                                             //社团数目
    PU_SNMP_COMMUNITY_INFO_S szCommunityInfo[PU_SNMP_COMMUNITY_NUM];  //社团信息
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNMP_COMMUNITY_LIST_S, *LPPU_SNMP_COMMUNITY_LIST_S;

/* SNMPv1v2c社团信息 拓展-支持更长的社团名*/

typedef struct PU_SNMP_COMMUNITY_INFO_EX
{
    PU_SNMP_COMMUNITY_ATTR_E enCommunityAttr;              //社团属性
    CHAR szCommunityName[PU_SNMP_COMMUNITY_NAME_LEN_EX];   //社团名
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNMP_COMMUNITY_INFO_S_EX, *LPPU_SNMP_COMMUNITY_INFO_S_EX;

/* SNMPv1v2c社团列表 拓展-支持更长的社团名 */
typedef struct PU_SNMP_COMMUNITY_LIST_EX
{
    ULONG ulCommunityNum;                                               //社团数目
    PU_SNMP_COMMUNITY_INFO_S_EX szCommunityInfo[PU_SNMP_COMMUNITY_NUM]; //社团信息
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNMP_COMMUNITY_LIST_S_EX, *LPPU_SNMP_COMMUNITY_LIST_S_EX;

/* SNMPv3用户信息 */
typedef struct PU_SNMPV3_USER_INFO
{
    CHAR szUserName[PU_USER_NAME_LEN];               //用户名
    BOOL bEngineIdEnable;                            //是否需要指定ENGINEID(暂时只在配置Trap时使用)
    CHAR szEngineId[PU_SNMP_ENGINEID_LEN];           //ENGINEID(暂时只在配置Trap时使用)
    BOOL bContextEnable;                             //是否需要指定上下文名(暂时只在配置Trap时使用)
    CHAR szContextName[PU_SNMP_CONTEXT_NAME_LEN];    //上下文名(暂时只在配置Trap时使用)
    CHAR szAuthPassword[PU_PASSWORD_LEN];            //认证Pwd(当被WEB配置的时候为原文下发;记录在配置文件中为密文形式)
    CHAR szPrivKey[PU_PASSWORD_LEN];                 //密钥(当被WEB配置的时候为原文下发;记录在配置文件中为密文形式)
    PU_SNMPV3_SECURITY_LEVEL_E enSecurityLevel;      //安全级别
    PU_SNMPV3_AUTH_PROTOCOL_E enAuthProtocol;        //认证协议
    PU_SNMPV3_PRIV_PROTOCOL_E enPrivProtocol;        //密钥协议
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNMPV3_USER_INFO_S, *LPPU_SNMPV3_USER_INFO_S;

/* SNMPv3用户列表 */
typedef struct PU_SNMPV3_USER_LIST
{
    ULONG ulUserNum;                                           //用户数目
    PU_SNMPV3_USER_INFO_S szUserInfo[PU_SNMPV3_USER_NUM];      //用户信息
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNMPV3_USER_LIST_S, *LPPU_SNMPV3_USER_LIST_S;

/* SNMPv3用户管理 */
typedef struct PU_SNMPV3_USER_MGMT
{
    PU_OPT_TYPE_E enManipulateType;                      //操作类型
    PU_SNMPV3_USER_INFO_S stMgmtUserInfo;                //操作信息
    CHAR szModifyVerifyPwd[PU_PASSWORD_LEN];             //当前snmp用户的认证Pwd(安全级别不为noauth)
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNMPV3_USER_MGMT_S, *LPPU_SNMPV3_USER_MGMT_S;

typedef union PU_SNMP_AUTH_INFO
{
    CHAR szCommunityName[PU_SNMP_COMMUNITY_NAME_LEN];     //社团名，发送v1/v2c版本的trap使用
    PU_SNMPV3_USER_INFO_S stUserInfo;                     //用户信息，发送v3版本的trap使用
}PU_SNMP_AUTH_INFO_U;

/* SNMP Trap接收方信息 */
typedef struct PU_SNMP_TRAP_INFO
{
    CHAR szTrapPeerIp[PU_IP4_ADDR_LEN];                   //接收方IP
    USHORT usTrapPeerPort;                                //接收方端口
    PU_SNMP_VERSION_TYPE_E enSnmpVer;                     //版本
    PU_SNMP_AUTH_INFO_U unSnmmpAuthInfo;                  //鉴权信息
    CHAR szReserved[PU_RESERVE_LEN];                      //szReserved[0],应用的网卡,0:作用于网卡1,1:作用于网卡2,以此类推
}PU_SNMP_TRAP_INFO_S, *LPPU_SNMP_TRAP_INFO_S;

/* SNMP Trap接收方列表 */
typedef struct PU_SNMP_TRAP_LIST
{
    ULONG ulTrapNum;                                      //Trap接收端数目
    PU_SNMP_TRAP_INFO_S szTrapInfo[PU_SNMP_TRAP_NUM];     //Trap接收端信息
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNMP_TRAP_LIST_S, *LPPU_SNMP_TRAP_LIST_S;

/********* 802.1x *********/
/* 802.1x配置信息 */
typedef struct PU_DOT1X_CONFIG_INFO
{
    BOOL bDot1xEnable;                                    //启用标志
    PU_DOT1X_EAPOL_VERSION_E enEapolVersion;              //EAPOL版本
    CHAR szEapUserName[PU_USER_NAME_LEN];                 //EAP用户名
    CHAR szEapPassWord[PU_PASSWORD_LEN];                  //EAPPwd
    CHAR szReserved[PU_RESERVE_LEN];                      //szReserved[0]表示EAP MD5开关 0:关闭 1:开启
}PU_DOT1X_CONFIG_INFO_S, *LPPU_DOT1X_CONFIG_INFO_S;

typedef struct PU_USER_INFO
{
    PU_USER_TYPE_E enUserType;                            //用户类型
    CHAR szUserName[PU_USER_NAME_LEN];                    //用户名,最长支持16位
    CHAR szUserPwd[PU_PASSWORD_LEN];                      //Pwd
    CHAR szReserved[PU_RESERVE_LEN];                      //szReserved[0]代表WEB多点登陆用户数，范围1-10
}PU_USER_INFO_S, *LPPU_USER_INFO_S;

//所有用户列表
typedef struct PU_USER_LIST
{
    ULONG ulCurrentUserNum;                               //当前用户个数
    PU_USER_INFO_S szUserList[PU_DEVICE_USER_NUM_MAX];    //当前用户列表
    CHAR szReserved[PU_RESERVE_LEN];
}PU_USER_LIST_S, *LPPU_USER_LIST_S;

//用户管理
typedef struct PU_USER_MANAGEMENT
{
    CHAR szOperaterUserName[PU_USER_NAME_LEN];              //操作人名称
    PU_OPT_TYPE_E enOptType;                                //操作类型
    PU_USER_INFO_S stUserInfo;                              //操作信息
    CHAR szVerifyPwd[PU_PASSWORD_LEN];                      //验证Pwd
    CHAR szReserved[PU_RESERVE_LEN];
}PU_USER_MANAGEMENT_S;

typedef struct PU_LOCAL_RECORD
{
	ULONG ulChannelId;                                     // 录像通道
	ULONG ulAction;                                        // 动作标志 0 停止 非0 开始
	PU_RECORD_TYPE_E enRecordType;                         // 录像方式
	CHAR szReserved[PU_RESERVE_LEN];
}PU_LOCAL_RECORD_S, *LPPU_LOCAL_RECORD_S;

//简易典型场景套餐信息
typedef struct PU_TYPICAL_SCENE_INFO
{
    PU_TYPICAL_SCENE_MODE_E enSceneMode;                  //典型场景类型
    CHAR szName[PU_TYPICAL_SCENE_NAME_LEN];               //典型场景餐名称名称
    CHAR szDescribe[PU_TYPICAL_SCENE_DESCRIBE_LEN];       //描述
    CHAR szReserved[PU_RESERVE_LEN];
}PU_TYPICAL_SCENE_INFO_S, *LPPU_TYPICAL_SCENE_INFO_S;

//简易典型场景套餐列表
typedef struct PU_TYPICAL_SCENE_LIST                           
{
    ULONG ulChannelId;                                    //属于哪个通道
    ULONG ulTypicalScenesNum;				              //典型场景套餐个数
    PU_TYPICAL_SCENE_MODE_E enSceneMode;                  //当前激活的典型场景套餐
    PU_TYPICAL_SCENE_INFO_S stTypicalSceneInfo[PU_TYPICAL_SCENE_NUM_MAX];  //信息列表
    CHAR szReserved[PU_RESERVE_LEN];
}PU_TYPICAL_SCENE_LIST_S, *LPPU_TYPICAL_SCENE_LIST_S;

//简易典型场景套餐列表
typedef struct PU_TYPICAL_SCENE_LIST_EX_OUT                           
{
    ULONG ulChannelId;                                    //属于哪个通道
    ULONG ulTypicalScenesNum;				              //典型场景套餐个数
    PU_TYPICAL_SCENE_MODE_E enSceneMode;                  //当前激活的典型场景套餐
    PU_TYPICAL_SCENE_INFO_S *pstTypicalSceneInfo;  //信息列表
    CHAR szReserved[PU_RESERVE_LEN];               //预留字段,[0]表示参数类型，见PU_SCENE_PARAM_TYPE_E
}PU_TYPICAL_SCENE_LIST_EX_OUT_S, *LPPU_TYPICAL_SCENE_LIST_EX_OUT_S;

//计划任务时间段数据结构
typedef struct PU_TIME_QUANTUM_INFO
{
    ULONG ulTimeQuantumId;                                //时间段 索引 1 ~ 8
    ULONG ulStartTime;                                    //开始时间:本地时间
    PU_TYPICAL_SCENE_MODE_E enSceneMode;                  //典型场景类型
    ULONG ulEndTime;                                      //结束时间:本地时间,占用之前的Reserve字段。
    CHAR szReserved[PU_RESERVE_LEN-sizeof(ULONG)];        //预留字段
}PU_TIME_QUANTUM_INFO_S;

//计划任务总时间段数据结构列表
typedef struct PU_TIME_QUANTUM_LIST
{
    ULONG ulTimeQuantumNum;                               //有效前几个时间段，一般都为MAX_TIMEQAUMTUM_NUM 值
    PU_TIME_QUANTUM_INFO_S stTimeQuantumInfo[PU_PLAN_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
}PU_TIME_QUANTUM_LIST_S, *LPPU_TIME_QUANTUM_LIST_S;

//计划任务一年数据结构列表
typedef struct PU_MONTHS_PLAN
{
    ULONG ulMonth;                                        //对应月份，如果为0表示12个月份全需要设置，1~12表对应的月份需要保存
    BOOL  bEnable;                                        //使能与否
    PU_TIME_QUANTUM_LIST_S stTimeQaumtumMonths[PU_MONTH_NUM];
    CHAR szReserved[PU_RESERVE_LEN];                      //szReserve[0]不要使用，SDK内部使用
}PU_MONTHS_PLAN_S, *LPPU_MONTHS_PLAN_S;

//日夜联动ISP套餐模式结构体
typedef struct PU_ISP_PROFILES_LINK_MODE
{
    PU_ISP_IRCUT_MODULE_E enIRCMode;           //IRCUT模式类型
    ULONG ulISPProfilesIndex;                  //ISP套餐索引    
    CHAR  szReserved[PU_RESERVE_LEN];     //预留字段
}PU_ISP_PROFILES_LINK_MODE_S, *LPPU_ISP_PROFILES_LINK_MODE_S;

//日夜联动ISP套餐设置结构体
typedef struct PU_ISP_PROFILES_LINK_INFO
{
    ULONG ulChannelID;
    BOOL bEnable;                                               //是否开启日夜联动ISP套餐
    PU_ISP_PROFILES_LINK_MODE_S szLinkMode[PU_IRCUT_MODE_MAX_NUM];  //联动列表
    CHAR                        szReserved[PU_RESERVE_LEN];     //预留字段
}PU_ISP_PROFILES_LINK_INFO_S, *LPPU_ISP_PROFILES_LINK_INFO_S;


typedef struct PU_HARD_DISK_INFO
{
    CHAR                szHardDiskFac[FAC_NAME_LEN_MAX];
    PU_DISK_TYPE_E      enHardDiskType;
    ULONG               ulAllSpace;
    ULONG               ulLeftSpace;
    ULONG				ulUsedSpace;
    ULONG				ulUsedPercentage;
    CHAR                szReserved[PU_RESERVE_LEN];    //预留字段
}PU_HARD_DISK_INFO_S, *LPPU_PU_HARD_DISK_INFO_S;

/*磁盘状态*/
typedef struct PU_HARD_DISK_STATE
{
    ULONG ulDiskThreshold;              //存储空间门限限额
    ULONG ulDiskState;                  //硬盘状态 0-正常
    PU_HARD_DISK_INFO_S stHardDiskInfo; //磁盘信息
    CHAR szReserved[PU_RESERVE_LEN];    //预留字段,szReserved[0]表示DiskID 0号磁盘为SD卡，1号磁盘为EMMC
}PU_HARD_DISK_STATE_S, *LPPU_HARD_DISK_STATE_S;

/*磁盘ID*/
typedef struct PU_HARD_DISK
{
    ULONG ulDiskId;                     //磁盘编号，0号磁盘为SD卡，1号磁盘为EMMC
    CHAR  szReserved[PU_RESERVE_LEN];   //预留字段
}PU_HARD_DISK_S, *LPPU_HARD_DISK_S;

/*降噪模式*/
typedef struct PU_NOISE_REDUCTION
{
    ULONG ulChannelId;                              //通道号
    PU_NOISE_REDUCTION_MODE_E enNoiseReductionMode; //降噪模式
    ULONG ulNRLevel;                                //普通模式降噪系数
    ULONG ulSfcLevel;                               //专家模式空域降噪系数
    ULONG ulTfcLevel;                               //专家模式时域降噪系数
    CHAR szReserved[PU_RESERVE_LEN];                //预留字段
    
} PU_NOISE_REDUCTION_S, *LPPU_NOISE_REDUCTION_S;

//隐私保护区域
typedef struct PU_MASK_AREA_PARA
{
    PU_IGT_POINT_S stAreaPara[PRIVACY_AREA_POINTS_NUM];
    ULONG ulColor;                          //颜色
    UCHAR ucAlpha;                          //透明度，暂不支持
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_MASK_AREA_PARA_S,*LPPU_MASK_AREA_PARA_S;

typedef struct PU_MASK_AREA_PARA_V20
{
    PU_IGT_POINT_S stAreaPara[PRIVACY_AREA_POINTS_NUM];
    ULONG ulColor;                          
    UCHAR ucAlpha;                        
    ULONG ulIndex;
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_MASK_AREA_PARA_V20_S,*LPPU_MASK_AREA_PARA_V20_S;

typedef struct PU_ADD_MASK_PARA
{
    ULONG ulChnID;
    ULONG ulIndex;
    PU_MASK_AREA_PARA_S stMaskAreaPara;
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_ADD_MASK_PARA_S;

typedef struct PU_DEL_MASK_PARA
{
    ULONG ulChnID;
    ULONG ulIndex;
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_DEL_MASK_PARA_S;

//隐私保护列表
typedef struct PU_PRIVACY_MASK_AREA_ARRAY
{
    ULONG ulChannelID;
    ULONG ulNum;
    BOOL bEnable;
    PU_MASK_AREA_PARA_S stMaskParaEx[PU_PRIVACY_MASK_MAX];
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PRIVACY_MASK_AREA_ARRAY_S, *LPPU_PRIVACY_MASK_AREA_ARRAY_S;

//隐私保护列表
typedef struct PU_PRIVACY_MASK_AREA_LIST
{
    ULONG ulChnID;
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    BOOL bEnable;
    PU_MASK_AREA_PARA_V20_S stMaskPara[PU_PRIVACY_MASK_MAX];
    CHAR szReserve[PU_RESERVE_LEN];
}PU_PRIVACY_MASK_AREA_LIST_S, *LPPU_PRIVACY_MASK_AREA_LIST_S;

typedef struct PU_IPCA_RULES   
{
    BOOL                bEnable;                   
    ULONG               ulPeriod;                   //周期              
	USHORT              usSrcPort;                  //源端口       
	USHORT              usDstPort;                  //目的端口     
	CHAR                szSrcIP[PU_IP4_ADDR_LEN];   //源IP
	CHAR                szDstIP[PU_IP4_ADDR_LEN];   //目的IP
	PU_PROTOCOL_TYPE_E  enProtocolType;             //协议类型
	ULONG               ulInstanceId;               //五元组规则唯一标识    
    CHAR                szMcpIp[PU_IP4_ADDR_LEN];   //MAC
    CHAR                szDcpIp[PU_IP4_ADDR_LEN];   //DCP
    ULONG               ulTlpId;                    //TLP
    ULONG               ulMcpPort;                  //MCP PORT
    CHAR                szReserve[PU_RESERVE_LEN];
} PU_IPCA_RULES_S;

/*******************************************************************************************************************/
/*                                             SDK ISP Parameter Declaration                                       */
/*******************************************************************************************************************/

/* 曝光补偿 */
typedef struct PU_CAM_EXPCOMP_PARA
{
    PU_COMMONMODE_SWITCH_E enExpComp;        //曝光补偿(关闭、打开)
    LONG lExpComp;                           //系数 0~255
    CHAR szReserve[PU_RESERVE_LEN];
}PU_EXPCOMP_PARA_S;

/* 白平衡设置，手动时R、B值可以微调 */
typedef struct PU_CAM_WB_MANUAL_PARA
{
    PU_CAM_WB_MODE_E enWBMode;               //白平衡模式
    ULONG ulROffset;                         //R值强调量 0~255
    ULONG ulBOffset;                         //B值强调量 0~255
    ULONG ulRStrong;                         //R值微调量 0~255
    ULONG ulBStrong;                         //B值微调量 0~255
    ULONG ulHighTemp;                     //色温上限   1500~10000k
    ULONG ulLowTemp;                     //色温下限   1500~10000k
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG) - sizeof(ULONG)];
}PU_WB_MANUAL_PARA_S;

/* 宽动态参数 */
typedef struct PU_CAM_WD_PARA
{
    PU_COMMONMODE_SWITCH_E enSwitchMode;         //开关(关闭、打开、自动)
    PU_VIDEO_WD_MODE_E enWDMode;                 //宽动态模式  为WD_MODE_RATIOFIX值需要设置lExpRatio
    LONG lExpRatio;                              //索尼：x1~x64,日立：127
    ULONG ulAutoModeMaxExpRatio;                 //在自动宽动态模式下最大的曝光比例值 TI:1~16，默认8
    CHAR szReserve[PU_RESERVE_LEN];
}PU_WD_PARA_S;

/* 昼夜模式 */
typedef struct PU_BLACKWHITE_MODE
{
    PU_VIDEO_BLACKWHITE_MODE_E enBKMode;        //视频模式
}PU_BLACKWHITE_MODE_S;

/* 设置慢快门模式 */
typedef struct PU_CAM_SLOW_SHUTTER_MODE
{
    PU_COMMONMODE_SWITCH_E enSlowShutterMode;    //设置慢快门模式
    PU_CAM_SHUTTER_MODE_E  enShutterValue;       //快门值
    CHAR szReserve[PU_RESERVE_LEN];
}PU_SLOW_SHUTTER_MODE_S;

/* 设置测光模式 */
typedef struct PU_AEMETERING_MODE
{
    PU_COMMONMODE_SWITCH_E enAEMeterSwitch;             //开关(关闭、打开)
    PU_VIDEO_AEMETERING_MODE_E enAEMetering;            //测光模式(支持中心测光、平均测光、用户自定义)
    UCHAR aucAreaWeight[VW_ZONE_ROW][VW_ZONE_COLUMN];   //曝光区域权重,Range:[0, 0xF]
    CHAR szReserve[PU_RESERVE_LEN];
}PU_AEMETERING_MODE_S;

/* 快门范围 */
typedef struct PU_SHUTTER_VALUE
{
    PU_COMMONMODE_SWITCH_E enShutterMode;       //快门模式
    PU_CAM_SHUTTER_MODE_E enShutterValue;       //快门值
    LONG lShutterValueSlow;
    LONG lShutterValueFast;
    CHAR szReserve[PU_RESERVE_LEN];
}PU_SHUTTER_VALUE_S;

/* 背光补偿模式 */
typedef struct PU_BACKLIGHT_MODE
{
    PU_COMMONMODE_SWITCH_E enBackLightMode;     //模式开关(关闭、打开)
    LONG lBackLight;                            //补偿范围0~255
    BACKLIGHT_MODE_E enMode;                    //背光补偿模式
    PU_AREA_INFO_S stAreaInfo;                  //背光补偿区域     
    CHAR szReserve[12];
}PU_BACKLIGHT_MODE_S;

/* IRC参数 */
typedef struct PU_IRC_PARA
{
    PU_IRC_MODE_E enIRCMode;                       //日夜模式
    ULONG ulDayToNightThreshold;                   //彩转黑灵敏度
    ULONG ulNightToDayThreshold;                   //黑转彩灵敏度   
    ULONG ulSwitchLevel;                           //外部告警触发转黑白0：低电平 1：高电平      
    PU_IRC_TRIGGER_MODE_E enIRCutSwitchMode;       //日夜模式触发方式，默认IRC_LUM_TRIGGER
    PU_COMMONMODE_SWITCH_E enPolarzerMode;     //偏振片开关模式
    CHAR szReserve[PU_RESERVE_LEN-sizeof(PU_COMMONMODE_SWITCH_E)];
}PU_IRC_PARA_S;

/* 控制机芯增益 */
typedef struct PU_GAIN_CONTROL
{
    PU_COMMONMODE_SWITCH_E enGainSwitch;     //机芯增益控制开关(关闭、打开)
    PU_GAIN_TYPE_E enGainType;               //机芯增益类型
    ULONG ulGainValue;                       //增益值
    CHAR szReserve[PU_RESERVE_LEN];
}PU_GAIN_CONTROL_S;

/* 机芯防抖功能 */
typedef struct PU_STABILIZER_PARA
{
    PU_COMMONMODE_SWITCH_E  enStabilizerMode;     //模式开关
    LONG lStabilizerLevel;                        //防抖级别
    LONG lEfl;                                    //等效焦距
    CHAR szReserve[PU_RESERVE_LEN];
}PU_STABILIZER_PARA_S;

/* 控制机芯光圈 */
typedef struct PU_IRIS_CONTROL
{
    PU_COMMONMODE_SWITCH_E enIris;             //控制机芯光圈(DC)
    PU_IRIS_VALUE_E enIRISValue;               //光圈值(P-Iris)
    CHAR szReserve[PU_RESERVE_LEN];
}PU_IRIS_CONTROL_S;

/* 除雾参数 */
typedef struct PU_DEFOG_PARA
{
    PU_COMMONMODE_SWITCH_E enDefog;            //去雾开关
    ULONG ulDefogLevel;                        //去雾等级
    ULONG ulDefogSensitivity;
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)];
}PU_DEFOG_PARA_S;

/* 设置DRC */
typedef struct PU_IMG_DRC
{
	PU_COMMONMODE_SWITCH_E enDRC;
	ULONG ulDRCStrength;            //海思0~255 TI 0~255
	CHAR szReserve[PU_RESERVE_LEN];
}PU_IMG_DRC_S;

/*强光抑制*/
typedef struct PU_ISP_HLC
{
	PU_COMMONMODE_SWITCH_E enHlc;    //强光抑制模式(关闭、打开)
	ULONG ulHlcLevel;                //panasonic等级1-3
	CHAR szReserve[PU_RESERVE_LEN];
} PU_ISP_CAM_HLC_S;


//感兴趣区域测光类型(微卡口车牌测光/人脸检测人脸测光)
typedef enum PU_ROIMETER_TYPE
{
    ROIMETER_TYPE_FACE = 0,    //人脸曝光
    ROIMETER_TYPE_VEHICLE,     //车牌曝光
    ROIMETER_TYPE_INVALID,
} PU_ROIMETER_TYPE_E;

//微卡口感兴趣区域测光参数
typedef struct PU_ROI_METER_MODE
{
    PU_COMMONMODE_SWITCH_E enRoiMeter;    //开、关
    ULONG ulRoiMeterLevel;                //级别1~100
}PU_ROI_METER_MODE_S;

//P-IRIS光圈子类型
typedef enum PU_CAM_P_IRIS_TYPE
{
    CAM_P_IRIS_HV1250P        = 0,       //Piris或hall光圈
    CAM_P_IRIS_HV03617P       = 1,       //客户自选镜头类型
    CAM_P_IRIS_BUTT,    
}PU_CAM_P_IRIS_TYPE_E;


/* ISP详细参数 */
typedef struct PU_ISP_PARTICULAR_PARA
{
    ULONG ulChannelID;                                          //通道号
    ULONG ulBitMap;                                             //修改位 （低位从AE曝光模式开始）
    PU_AE_MODE_E enAEMode;                                      //AE曝光模式1
    LONG lAEResponseTime;                                       //AE响应时间2
    PU_EXPCOMP_PARA_S stCamExpcompPara;                         //曝光补偿3
    PU_WB_MANUAL_PARA_S stCamWBManualPara;                      //白平衡4
    PU_WD_PARA_S stCamWDPara;                                   //宽动态5
    PU_SLOW_SHUTTER_MODE_S stSlowShutterMode;                   //慢快门开关6-----ITS款型、多算法款型（混行模式）不支持
    PU_VIDEO_FLICKER_MODE_E enCamFlickerMode;                   //背景频率7
    PU_AEMETERING_MODE_S stCamAEMeterMode;                      //AE测光模式8
    PU_SHUTTER_VALUE_S stCamshutterValue;                       //快门范围及其值9
    PU_BACKLIGHT_MODE_S stCamBackLightMode;                     //背光补偿模式10
    PU_IRC_PARA_S stCamIRCPara;                                 //日夜模式11
    LONG lAutoGainMaxValue;                                     //自动增益最大值12
    PU_GAIN_CONTROL_S stCamGainControl;                         //机芯增益控制13
    PU_NOISE_REDUCTION_S stCamDenoisePara;                      //降噪模式14
    PU_STABILIZER_PARA_S stCamStabilizerPara;                   //机芯防抖模式15
    PU_IRIS_CONTROL_S stCamIrisControl;                         //控制机芯光圈16
    PU_DEFOG_PARA_S stISPDefogPara;                             //去雾效果17
    PU_IMG_DRC_S stImgDRCPara;					                //DRC参数18
    PU_MIN_FOCUS_E enMinFocusValue;                             //最小聚焦距离值19
	PU_ISP_CAM_HLC_S stHlc;                                     //强光抑制20
	PU_IRIS_TYPE_E enIrisType;                                  //Iris类型21
	PU_CAM_SHUTTER_MODE_E enShutterValueLimit;                  //快门限制22
    PU_ROI_METER_MODE_S stCamRoiMeterMode;                      //微卡口感兴趣区域测光
    PU_ROIMETER_TYPE_E enRoiMeterType;                          //曝光补偿类型
    ULONG              ulFaceExposureTime;                      //人脸曝光时间 10~300
    CHAR enPirisType;                                           //P-IRIS光圈子类型,参见PU_CAM_P_IRIS_TYPE_E
	CHAR szReserve[PU_RESERVE_LEN-sizeof(PU_ROI_METER_MODE_S)-sizeof(PU_ROIMETER_TYPE_E)-sizeof(ULONG)-sizeof(CHAR)];

}PU_ISP_PARTICULAR_PARA_S, *LPPU_ISP_PARTICULAR_PARA_S;

/* CVBS参数 */
typedef struct PU_CVBS_PARA
{
   ULONG ulChannelID;                         //通道ID
   BOOL bEnable;                             //使能与否
   PU_RESOLUTION_TYPE_E enResolution;        //分辨率
}PU_CVBS_PARA_S;

/* 视频编码参数 */
typedef struct PU_VIDEO_ENCODE_PARA
{
    PU_STREAM_MODE_E enVideoStreamMode;                             //流套餐方式
    BOOL bDynamicFrmRateEnable;                                     //动态帧率是否使能
    ULONG ulDynamicFrmRate;                                         //动态帧率
    BOOL bDynamicBitRateEnable;                                     //动态码率是否使能
    ULONG ulDynamicBitRate;                                         //动态码率
    PU_FRAMERATE_FORMAT_E enFrameMat;                               //视频采集帧制式
    PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_ENC_STREAM_MAX_NUM]; //视频属性
    CHAR szReserve[PU_RESERVE_LEN];                                 //szReserved[0]标识宽窄屏模式 0:宽屏 1:窄屏
}PU_VIDEO_ENCODE_PARA_S;

/* 码流套餐参数 */
typedef struct PU_STREAM_PROFILES_PARA
{
	ULONG ulIndex;                                           //唯一标识 1-4是基本配置不能删除,0标示自动适配
	CHAR szName[STREAMPROFILES_NAME_LEN];                    //名称
	CHAR szDescrip[STREAMPROFILES_NAME_LEN * 2];             //描述
	PU_VIDEO_ENCODE_PARA_S stVideoEncodePara;                //视频流参数
	PU_AUDIO_INFO_S stAudioInfo;                             //音频参数
	BOOL bAiVqeStatus;                                       //音频质量增强
	BOOL bCorridorEnable;                                    //走廊模式
	CHAR szReserve[PU_RESERVE_LEN];                          //预留
}PU_STREAM_PROFILES_PARA_S;

/* 码流套餐 */
typedef struct PU_CHANNEL_STREAM_PROFILES
{
    ULONG ulChannelID;                                  //通道ID
    PU_STREAM_MANIPULATE_TYPE_E enStreamOptionType;     //操作类型
    PU_STREAM_PROFILES_PARA_S stStreamProfilesPara;     //码流套餐参数
    CHAR szReserve[PU_RESERVE_LEN];                     //预留
}PU_CHANNEL_STREAM_PROFILES_S;


/* 视频编码参数V2五码流 */
typedef struct PU_VIDEO_ENCODE_PARAV2
{
	PU_STREAM_MODE_E enVideoStreamMode;                             //流套餐方式
	BOOL bDynamicFrmRateEnable;                                     //动态帧率是否使能
	ULONG ulDynamicFrmRate;                                         //动态帧率
	BOOL bDynamicBitRateEnable;                                     //动态码率是否使能
	ULONG ulDynamicBitRate;                                         //动态码率
	PU_FRAMERATE_FORMAT_E enFrameMat;                               //视频采集帧制式
	PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_ENC_STREAM_MAX_NUM_V2]; //视频属性
	CHAR szReserve[PU_RESERVE_LEN];                                 //szReserved[0]标识宽窄屏模式 0:宽屏 1:窄屏
}PU_VIDEO_ENCODE_PARAV2_S;

/* 码流套餐参数V2五码流 */
typedef struct PU_STREAM_PROFILES_PARAV2
{
	ULONG ulIndex;                                           //唯一标识 1-4是基本配置不能删除,0标示自动适配
	CHAR szName[STREAMPROFILES_NAME_LEN];                    //名称
	CHAR szDescrip[STREAMPROFILES_NAME_LEN * 2];             //描述
	PU_VIDEO_ENCODE_PARAV2_S stVideoEncodePara;              //视频流参数
	PU_AUDIO_INFO_S stAudioInfo;                             //音频参数
	BOOL bAiVqeStatus;                                       //音频质量增强
	BOOL bCorridorEnable;                                    //走廊模式
	CHAR szReserve[PU_RESERVE_LEN];                          //预留
}PU_STREAM_PROFILES_PARAV2_S;

/* 码流套餐V2五码流 */
typedef struct PU_CHANNEL_STREAM_PROFILESV2
{
	ULONG ulChannelID;                                  //通道ID
	PU_STREAM_MANIPULATE_TYPE_E enStreamOptionType;     //操作类型
	PU_STREAM_PROFILES_PARAV2_S stStreamProfilesPara;     //码流套餐参数
	CHAR szReserve[PU_RESERVE_LEN];                     //预留
}PU_CHANNEL_STREAM_PROFILESV2_S;

/*创建https证书*/
typedef struct PU_CREATE_HTTPS_CERT
{
	CHAR szCommonName[PU_CERT_FIELD_NAME_LEN_MAX];        //证书CN
	CHAR szCountry[PU_CERT_FIELD_NAME_LEN_MAX];           //国家
	CHAR szState[PU_CERT_FIELD_NAME_LEN_MAX];             //省/州
	CHAR szLocation[PU_CERT_FIELD_NAME_LEN_MAX];          //地区
	CHAR szOrganization[PU_CERT_FIELD_NAME_LEN_MAX];      //组织
	CHAR szUnit[PU_CERT_FIELD_NAME_LEN_MAX];              //单位
	CHAR szEmail[PU_CERT_FIELD_NAME_LEN_MAX];             //邮件地址
	ULONG ulExpiredDays;                                  //有效天数
	CHAR szCreateCertPsw[STREAMPROFILES_NAME_LEN];        //创建证书的Pwd
    CHAR szReserve[PU_RESERVE_LEN];
}PU_CREATE_HTTPS_CERT_S;

//IP地址过滤规则
typedef struct PU_IPFILTER_RULES
{
    CHAR szIPAddress[PU_IP4_ADDR_LEN];                         //过滤的IP地址
    CHAR szSubNetAddress[PU_IP4_ADDR_LEN];                     //过滤的子网掩码
    ULONG ulIpBeginPort;                                       //过滤起始端口
    ULONG ulIpEndPort;                                         //过滤终止端口
    PU_IP_PROTOCOL_TYPE_E enProtocolType;                      //过滤该协议数据包
    BOOL bStatus;                                              //IP过滤规则状态，生效或未生效
    CHAR szReserve[PU_RESERVE_LEN];
}PU_IPFILTER_RULES_S;
//IP地址过滤
typedef struct PU_IPFILTER_RULES_INFO
{
    BOOL bIpFilterEnable;                                           //是否启用IP过滤
    PU_IP_FILTER_STRATEGY_E enIpFilterStrategy;                     //IP过滤策略:白名单 or 黑名单
    ULONG ulIpFilterRulesNum;                                       //IP地址规则条目
    PU_IPFILTER_RULES_S stIpFilterRulesList[PU_IP_FILTER_NUM_MAX];  //IP地址规则列表
    CHAR szReserve[PU_RESERVE_LEN];                                 

}PU_IPFILTER_RULES_INFO_S;

//IP过滤匹配方式
typedef enum PU_IPFILTER_MATCH_TYPE
{
	MATCH_IP = 0,         //当IP匹配时进行过滤
	MATCH_MAC = 1,        //当MAC匹配时进行过滤
	MATCH_IP_AND_MAC = 2, //当IP和MAC均匹配时进行过滤
}PU_IPFILTER_MATCH_TYPE_E;

//IP地址过滤规则
typedef struct PU_IPFILTER_RULESV2
{
	PU_IPFILTER_MATCH_TYPE_E enMatchType;                      //匹配方式
	CHAR szIPAddress[PU_IP4_ADDR_LEN];                         //过滤的IP地址
	CHAR szSubNetAddress[PU_IP4_ADDR_LEN];                     //过滤的子网掩码
	ULONG ulIpBeginPort;                                       //过滤起始端口
	ULONG ulIpEndPort;                                         //过滤终止端口
	PU_IP_PROTOCOL_TYPE_E enProtocolType;                      //过滤该协议数据包
	CHAR szMACAddress[PU_HEX_MAC_ADDR_LEN+1];                    //过滤的MAC地址
	BOOL bStatus;                                              //IP过滤规则状态，生效或未生效
	CHAR szReserve[PU_RESERVE_LEN];                            //szReserve[0],应用的网卡,0:应用于网卡1,1:应用于网卡2,以此类推,
	                                                           //64:应用于所有网卡
}PU_IPFILTER_RULESV2_S;
//IP地址过滤
typedef struct PU_IPFILTER_RULES_INFOV2
{
    BOOL bIpFilterEnable;                                           //是否启用IP过滤
    PU_IP_FILTER_STRATEGY_E enIpFilterStrategy;                     //IP过滤策略:白名单 or 黑名单
    ULONG ulIpFilterRulesNum;                                       //IP地址规则条目
    PU_IPFILTER_RULESV2_S stIpFilterRulesList[PU_IP_FILTER_NUM_MAXV2];  //IP地址规则列表
    CHAR szReserve[PU_RESERVE_LEN];                                 
}PU_IPFILTER_RULES_INFOV2_S;

typedef struct PU_IPFILTER_RULES_INFOV3
{
	BOOL bIpFilterEnable;                                           //是否启用IP过滤
	PU_IP_FILTER_STRATEGY_E enIpFilterStrategy;                     //IP过滤策略:白名单 or 黑名单
	ULONG ulIpFilterRulesNum;                                       //IP地址规则条目
	PU_IPFILTER_RULESV2_S stIpFilterRulesList[PU_IP_FILTER_NUM_MAXV3];  //IP地址规则列表
	CHAR szReserve[PU_RESERVE_LEN];                                 
}PU_IPFILTER_RULES_INFOV3_S;



//聚焦区域设置
typedef struct PU_PTZ_FOCUSAREA
{
    ULONG ulChannelID;                                      // 通道ID
    ULONG ulFocusArea[PU_FOCUSAREA_ROW][PU_FOCUSAREA_COL];  // 自动聚焦环境数据
} PU_PTZ_FOCUSAREA_S;

/* 802.1x EAP-TLS证书上传 */
typedef struct PU_DOT1X_TLS_CERT_UPLOAD
{
	PU_DOT1X_TLS_CERT_UPLOAD_TYPE_E enAction;  //上传类型
	CHAR szPassword[PU_PASSWORD_LEN];          //私钥文件的加密Pwd
}PU_DOT1X_TLS_CERT_UPLOAD_S;

/* SDK TLS证书上传 */
typedef struct PU_SDK_TLS_CERT_UPLOAD
{
	CHAR szCaFile[PU_CONFIG_FILE_PATH_MAX];
	CHAR szCertFile[PU_CONFIG_FILE_PATH_MAX];
	CHAR szKeyFile[PU_CONFIG_FILE_PATH_MAX];
	CHAR szPassword[PU_PASSWORD_LEN];          //私钥文件的加密Pwd
}PU_SDK_TLS_CERT_UPLOAD_S;

/* licence文件上传类型 */
typedef enum PU_LICENCE_UPLOAD_TYPE
{
	PU_LICENCE_ITGT_UPLOAD_TYPE = 0,
	PU_LICENCE_OTHER_UPLOAD_TYPE,
	PU_LICENCE_UPLOAD_TYPE_MAX
}PU_LICENCE_UPLOAD_TYPE_E;

/*licence文件上传 */
typedef struct PU_LICENCE_FILE_UPLOAD
{
	PU_LICENCE_UPLOAD_TYPE_E enLicenceType;  //上传类型
	CHAR szLicenceFile[PU_CONFIG_FILE_PATH_MAX];  //文件路径
}PU_LICENCE_FILE_UPLOAD_S;

//垂直限位
typedef struct PU_VERTICAL_LIMIT
{
    INT iVerticalLimit;       // 垂直限位
    CHAR szReserve[PU_RESERVE_LEN];
}PU_VERTICAL_LIMIT_S;

//DDNS
typedef struct PU_DDNS_CONF_INFO
{
    BOOL bEnable;
	CHAR szUserID[PU_DDNS_MAX_LEN];     //用户账号名
	CHAR szUserPWD[PU_DDNS_MAX_LEN];	//用户Pwd明码
	CHAR szReserve[PU_RESERVE_LEN];     //szReserve[0],应用的网卡,0:网卡1,1:网卡2,以此类推,
}PU_DDNS_CONF_INFO_S;
//设置预置位冻结使能
typedef struct PU_PTZ_PRESET_FREEZE
{
    ULONG ulChannelID;                     //通道ID
    BOOL bFreezeEnable;                    //使能
}PU_PTZ_PRESET_FREEZE_S;

/*ISP套餐场景基本参数*/
typedef struct PU_ISP_SCENE_PARA
{
    ULONG ulIndex;                                  //唯一标识 1-4是基本配置不能删除；新增时设0，修改、删除请输入指定索引
    CHAR szName[PU_TYPICAL_SCENE_NAME_LEN];         //典型场景餐名称名称
    CHAR szDescrip[PU_TYPICAL_SCENE_DESCRIBE_LEN];  //描述
    PU_ISP_PARTICULAR_PARA_S stSceneModeISP;        //ISP参数
    PU_VIDEO_DISPLAY_INFO_S stVideoDisplayPara;     //视频效果
    PU_IRLIGHT_LIST_S stIrLightArrayPara;           //红外灯设置
    CHAR szReserved[PU_RESERVE_LEN];                //预留字段
}PU_ISP_SCENE_PARA_S;

/*ISP场景参数类型*/
typedef enum PU_SCENE_PARAM_TYPE
{
	PU_SCENE_PARAM_COMM = 0,     //操作通用场景参数
	PU_SCENE_PARAM_SNAPSHOT = 1, //操作ITS抓拍/多算法并行设备混行模式下微卡场景参数	
	PU_SCENE_PARAM_HUMAN = 2,    //操作多算法并行设备人卡模式/行为分析模式场景参数	
	PU_SCENE_PARAM_VEHICLE = 3,  //操作多算法并行设备微卡模式场景参数	
	PU_SCENE_PARAM_MAX
}PU_SCENE_PARAM_TYPE_E;

/*ISP套餐参数设置*/
typedef struct PU_ISP_PROFILES_PARA
{
    ULONG ulChannelID;                              //通道号
    PU_OPT_TYPE_E enOptionType;                     //操作类型
    PU_ISP_SCENE_PARA_S stClassiscalScenePara;      //ISP套餐场景参数
    CHAR szReserved[PU_RESERVE_LEN];                //预留字段,[0]表示参数类型，见PU_SCENE_PARAM_TYPE_E
}PU_ISP_PROFILES_PARA_S;

/*ISP典型场景模式*/
typedef struct PU_ISP_TYPICAL_SCENE_MODE
{
    ULONG ulChannelID;                  //通道号
    PU_SCENE_PARAM_TYPE_E enParamType;  //参数类型
    PU_TYPICAL_SCENE_MODE_E enMode;     //场景模式
    CHAR szReserved[PU_RESERVE_LEN];    //预留字段
}PU_ISP_TYPICAL_SCENE_MODE_S;

//红外聚焦补偿信息
typedef struct PU_FOCUS_COMPENSATION_S
{
    ULONG ulChannelId; // 通道ID
    BOOL bEnable;      // 使能开关
} PU_FOCUS_COMPENSATION_S;

/*抓拍空间设置*/
typedef struct PU_SNAPSHOT_SPACE
{
	ULONG   ulPercentDecimal;          // 抓拍空间占百分比(小数部分(2位有效,精确至百分位,1表示0.01%))
	ULONG   ulPercentInt;              // 抓拍空间占百分比(整数部分)
}PU_SNAPSHOT_SPACE_S;

/*定时抓拍参数*/
typedef struct PU_SNAPSHOT_TIMING_PARA
{
	BOOL                        bEnable;            // 是否启用定时抓拍功能
	ULONG						ulChannelID;		// 通道ID
	ULONG						ulStreamID;         // 码流ID
	ULONG						ulSnapCount;		// 抓拍间隔(秒)
	PU_SNAPSHOT_FORMAT_E	    enPictureFormat;	// 图片格式
	CHAR szReserved[PU_RESERVE_LEN];                // 预留字段
}PU_SNAPSHOT_TIMING_PARA_S;

/* FTP上传参数 */
typedef struct PU_FTP_FILE_UPLOAD_PARA
{
	BOOL bSnapPic;                                        //是否上传抓拍图片
	PU_FTP_UPLOAD_PROTOCOL_TYPE_E enProtocol;             //上传协议
	CHAR szServerIP[PU_IP4_ADDR_LEN];                     //服务器IP地址
	ULONG ulServerPort;                                   //服务器端口
	CHAR szUserName[PU_CLIENT_USERNAME_LEN];              //用户名
	CHAR szUserPwd[PU_PASSWORD_LEN];                      //Pwd
	PU_FTP_UPLOAD_DIR_TYPE_E enDirType;                   //上传目录结构
	PU_FTP_UPLOAD_FIRST_DIR_TYPE_E enFirstDirType;        //上传一级目录类型
	PU_FTP_UPLOAD_SECOND_DIR_TYPE_E enSecondDirType;      //上传二级目录类型
	PU_FTP_UPLOAD_FILE_NAMING_RULE_E enFileNamingRule;    //上传文件命名规则
	CHAR szFirstDir[PU_FTP_UPLOAD_PATH_LEN];              //自定义一级目录名
	CHAR szSecondDir[PU_FTP_UPLOAD_PATH_LEN];             //自定义二级目录名
	CHAR szReserved[PU_RESERVE_LEN];                      //预留字段
}PU_FTP_FILE_UPLOAD_PARA_S;

/* 录像计划数组 */
typedef struct PU_TIME_PLAN_LIST
{
	ULONG				ulCycle;						// 周期控制，0：仅一次，1：每周都按照时间段
	ULONG				ulStartTime;				    // 开始时间:从0点开始
	ULONG				ulEndTime;						// 结束时间:从0点开始
	CHAR szReserved[PU_RESERVE_LEN]; 
}PU_TIME_PLAN_LIST_S;

/*前端录像计划*/
typedef struct PU_LOCAL_RECORD_PLAN
{
	BOOL                        bEnable;                                // 是否启用计划任务录像
    ULONG                       ulChannelID;                            // 通道ID
    ULONG                       ulTotalNum;                             // 总记录数
    ULONG                       ulBeginIndex;                           // 当前开始记录数
    ULONG                       ulEndIndex;                             // 当前结束记录数
    PU_TIME_PLAN_LIST_S         szRecordPlanList[PU_RECORD_PLAN_NUM_SD];// 录像计划数组
    CHAR szReserved[PU_RESERVE_LEN]; 
}PU_LOCAL_RECORD_PLAN_S;

/* 人车分离结构体 */
typedef struct PU_HV_ALARM_PARA
{
	ULONG ulChannelId;    //通道ID
    BOOL  bEnable;        //使能
}PU_HV_ALARM_PARA_S;

/******************目标颜色提取结构体****************************************/
typedef struct PU_COLOR_ALARM_PARA
{
	ULONG ulChannelId;          //通道ID
    BOOL  bEnable;              //使能
}PU_COLOR_ALARM_PARA_S;

//变焦控制及其参数
typedef struct CAM_FOCUSCTRL
{
    ULONG ulChannelId;          //通道ID
    PU_CAMCTRL_E  enFocus;    
    ULONG  ulFocusSpeed;                // 索尼0~7阶，日立31阶
    CHAR szReserved[PU_RESERVE_LEN]; 
} PU_CAM_FOCUSCTRL_S;

//手动抓拍参数
typedef struct SNAPSHOT_PARA
{
	ULONG                   ulChannelID;		// 通道ID
	ULONG                   ulStreamID;			// 码流ID(目前仅支持主码流)
	PU_RESOLUTION_TYPE_E    enResolution;		// 分辨率(暂不支持设置,以主码流分辨率为准)
	PU_SNAPSHOT_FORMAT_E    enPictureFormat;	// 图片格式(目前仅支持JPEG格式)
	CHAR                    szPicPath[PU_SNAPSHOT_PIC_PATH_LEN + 4]; //抓拍文件目录
	CHAR                    szReserved[PU_RESERVE_LEN];              //预留
}PU_SNAPSHOT_PARA_S;

//抓拍图片质量参数
typedef struct PU_SNAPSHOT_QUAILTY_PARA
{
    ULONG ulChannelID;                  // 通道号(暂不支持)
    PU_SNAPSHOT_QUALITY_E enQuality;    // 抓拍图片质量
    CHAR szReserved[PU_RESERVE_LEN];    // 预留
}PU_SNAPSHOT_QUAILTY_PARA_S;

//抓拍重传参数
typedef struct PU_SNAPSHOT_RETRANS_PARA
{
    BOOL bEnable;                       // 使能
    CHAR szReserved[PU_RESERVE_LEN];    // 预留
}PU_SNAPSHOT_RETRANS_PARA_S;

//OSDI区域顶点信息
typedef struct PU_OSDI_POINT_INFO
{
    FLOAT   fHorDegree;
    FLOAT   fVerDegree;
}PU_OSDI_POINT_INFO_S;

//OSDI区域信息
typedef struct PU_OSDI_AREA_CFG_PARA
{
    ULONG ulIndex;                                  //区域索引
    BOOL bEnable;                                   //使能
    ULONG ulOSDINameLen;                            //OSDI名称长度
    CHAR szOSDIName[PU_OSD_STRING_LEN];             //OSDI名称内容
    PU_OSDI_POINT_INFO_S stLowerLeftPoint;          //左下坐标
    PU_OSDI_POINT_INFO_S stUpperRightPoint;         //右下坐标
}PU_OSDI_AREA_CFG_PARA_S;

//OSDI参数
typedef struct PU_OSDI_BUSINESS_PARA
{
    ULONG ulChannelID;                                          //通道号
    BOOL bOSDIEnable;                                           //OSDI总开关
    ULONG ulOSDINum;                                            //当前区域数量
    PU_OSDI_AREA_CFG_PARA_S stOSDIAreaPara[OSDI_AREA_NUM_MAX];  //OSDI区域信息
}PU_OSDI_BUSINESS_PARA_S;

//OSDI区域信息
typedef struct PU_OSDI_AREA_CFG_PARA_V20
{
    ULONG ulIndex;                                  //区域索引
    BOOL bEnable;                                   //使能
    ULONG ulOSDINameLen;                            //OSDI名称长度
    CHAR szOSDIName[PU_OSD_STRING_LEN];             //OSDI名称内容
    PU_OSDI_POINT_INFO_S stLowerLeftPoint;          //左下坐标
    PU_OSDI_POINT_INFO_S stUpperRightPoint;         //右下坐标
    PU_POINT_S stOSDITopLeftPos;                    //OSDI左上角坐标
}PU_OSDI_AREA_CFG_PARA_V20_S;

//OSDI参数
typedef struct PU_OSDI_BUSINESS_PARA_V20
{
    ULONG ulChannelID;                                          //通道号
    BOOL bOSDIEnable;                                           //OSDI总开关
    ULONG ulOSDINum;                                            //当前区域数量
    PU_OSDI_AREA_CFG_PARA_V20_S stOSDIAreaPara[OSDI_AREA_NUM_MAX];  //OSDI区域信息
}PU_OSDI_BUSINESS_PARA_V20_S;

//TCP 加速参数
typedef struct PU_TCP_ACCELERATE_PARA
{
    BOOL bEnable;                               //使能
    CHAR szReserved[PU_RESERVE_LEN];            //预留
}PU_TCP_ACCELERATE_PARA_S;

//流量整形参数
typedef struct PU_TRAFFIC_SHAPING_PARA
{
    BOOL bEnable;                               //流量整形使能
    PU_TS_COEFFICIENT_E enCoefficient;          //流量整形系数
    CHAR szReserved[PU_RESERVE_LEN];            //预留
}PU_TRAFFIC_SHAPING_PARA_S;

//端口配置参数
typedef struct PU_DEVICE_PORT_CONFIG
{
    USHORT usHTTPPort;                          //HTTP端口
    USHORT usHTTPSPort;                         //HTTPS端口
    USHORT usRTSPPort;                          //RTSP端口
}PU_DEVICE_PORT_CONFIG_S;

//端口配置参数扩展
typedef struct PU_DEVICE_PORT_CONFIG_EX
{
    USHORT usHTTPPort;                          //HTTP端口
    USHORT usHTTPSPort;                         //HTTPS端口
    USHORT usRTSPPort;                          //RTSP端口
    ULONG ulMeshIndex;                          //网口索引
    CHAR szReserved[PU_RESERVE_LEN];            //预留
}PU_DEVICE_PORT_CONFIG_EX_S;

//星期方式施行夏令时参数
typedef struct PU_DST_WEEK_WAY
{
    UINT uiMonth;                               //[0,11],分别表示1-12月
    UINT uiWeek;                                //[0,4],0-第一周,1-第二周,2-第三周,3-第四周,4-最后一周
    UINT uiDayofWeek;                           //[0,6],表示星期X,0表示星期日,1表示星期一,以此类推
    UINT uiHour;                                //[0,23],表示一天中的第X个小时
    UINT uiMinute;                              //[0,59],表示第X个小时的第X分钟
	CHAR szReserved[PU_RESERVE_LEN];            //预留
}PU_DST_WEEK_WAY_S;

//日期方式施行夏令时参数
typedef struct PU_DST_DATE_WAY
{
    UINT uiYear;                                //表示XXXX年,0-每年,[2014-2024]分别表示对应的年份
    UINT uiMonth;                               //[0,11],分别表示1-12月
    UINT uiDay;                                 //[0,30],分别表示1-31日
    UINT uiHour;                                //[0,23],表示一天中的第X个小时
    UINT uiMinute;                              //[0,59],表示第X个小时的第X分钟
	CHAR szReserved[PU_RESERVE_LEN];            //预留    
}PU_DST_DATE_WAY_S;

//夏令时起止时间
typedef struct PU_DST_DATE
{
    PU_DST_WEEK_WAY_S stDSTWeekWay;             //星期方式实施的夏令时时间点
    PU_DST_DATE_WAY_S stDSTDateWay;             //日期方式实施的夏令时时间点
	CHAR szReserved[PU_RESERVE_LEN];            //预留
}PU_DST_DATE_S;

//夏令时参数
typedef struct PU_DAYLIGHT_SAVING_TIME
{
    PU_DST_TYPE_E enDSTType;                    //夏令时实施方式
    BOOL bEnable;                               //夏令时使能
    PU_DST_OFFSET_E enOffset;                   //夏令时时间偏移
    PU_DST_DATE_S stDSTStartTime;               //夏令时起始时间
    PU_DST_DATE_S stDSTEndTime;                 //夏令时结束时间
    PU_DST_OFFSET_E enDateWayOffset;            //夏令时日期方式时间偏移
    CHAR szReserved[PU_RESERVE_LEN - sizeof(PU_DST_OFFSET_E)];        //预留
}PU_DAYLIGHT_SAVING_TIME_S;

//抓拍分辨率
typedef struct PU_SNAPSHOT_RESOLUTION_PARA
{
    ULONG ulChannelID;                  // 通道号
    PU_STREAM_TYPE_E enStreamType;      // 抓拍码流
    PU_RESOLUTION_TYPE_E enResolution;  // 抓拍图片分辨率
    CHAR szReserved[PU_RESERVE_LEN];    // szReserved[0]表示是否是微卡口 1:微卡口，0:非微卡口
}PU_SNAPSHOT_RESOLUTION_PARA_S;

/********* SMTP *********/
typedef enum PU_SMTP_SECURITY_TYPE
{
	PU_NO_SECURITY =0,
	PU_USE_TLS,
	PU_USE_SSL,
	PU_DO_NOT_SET
}PU_SMTP_SECURITY_TYPE_E;
//邮件类型
typedef enum PU_SMTP_MAIL_TYPE
{
	FOR_TEST,
	FOR_EVENT
}PU_SMTP_MAIL_TYPE;

typedef struct PU_SMTP_RECVEIVER_INFO
{
	CHAR szReceiverName[PU_SMTP_NAME_LEN_MAX];   //收件人用户名
	CHAR szReceiverMail[PU_SMTP_MAIL_LEN];        //收件人邮箱
}PU_SMTP_RECVEIVER_INFO_S;

typedef struct SMTP_CONFIG_INFO
{
	PU_SMTP_MAIL_TYPE enMailType;	//标志本次是下发参数or测试收件人,0:测试,1,
	BOOL bSMTPEnable;                //启用标志
	CHAR szSenderName[PU_SMTP_NAME_LEN_MAX];   //发件人用户名
	CHAR szSenderMail[PU_SMTP_MAIL_LEN];        //发件人邮箱
	CHAR szServerIP[PU_IP4_ADDR_LEN];        //服务器IP地址
	ULONG ulServerPort;        //服务器端口
	PU_SMTP_SECURITY_TYPE_E enSecurityType;       //加密类型
	BOOL bPicEnable;                //启用图片附件
	ULONG ulPicNum;					//图片附件数量
	ULONG ulSnapTimeInterval;          //抓拍间隔
	BOOL bServerCrtEnable;                //启用服务器认证
	CHAR szServerName[PU_CLIENT_USERNAME_LEN];   //服务器用户名
	CHAR szPassword[PU_PASSWORD_LEN];        //服务器Pwd
	ULONG ulReceiverNum;             //收件人数目
	PU_SMTP_RECVEIVER_INFO_S szReceiverInfo[PU_SMTP_RECV_MAX_NUM];         //收件人列表
	CHAR szReserved[64];				//预留字段
}PU_SMTP_CONFIG_INFO_S, *LPPU_SMTP_CONFIG_INFO_S;

//车辆信息
typedef struct PU_VEHICLE_INFO
{
	PU_AREA_INFO_S stVehicleLoc;		//车辆位置
	PU_VEHICLE_COLOR_E enVehicleColor;	//车辆颜色
	PU_VEHICLE_TYPE_E enVehicleType;	//车辆类型
	PU_AREA_INFO_S stVehicleFaceLoc;	//车脸位置
	CHAR szReserved[64];				//预留字段
}PU_VEHICLE_INFO_S;

//车牌信息
typedef struct PU_PLATE_INFO
{
	BOOL bHavePlate;					//是否抓拍到车牌
	INT iConfidence;					//车牌置信度
	INT iPlateCharNum;                  //车牌字符数
	CHAR szPlateChar[36];               //车牌字符，从24扩充到36字节
	PU_AREA_INFO_S stPlateLoc;			//车牌位置
	PU_PLATE_TYPE_E enPlateType;		//车牌类型
	PU_PLATE_COLOR_E enPlateColor;		//车牌颜色
	PU_PLATE_DIR_E enMoveDir;			//车牌移动方向 
	CHAR szReserved[64-12];				//预留字段，由于车牌字符szPlateChar扩充12字节，此处减少12字节
}PU_PLATE_INFO_S;

typedef struct LPR_CAPTURE_RES
{
    CHAR szLocalTime[32];                               //抓拍时间
	INT iLaneID;										//车道号
	PU_VEHICLE_INFO_S stVehicleInfo;					//车辆信息
	PU_PLATE_INFO_S stPlateInfo;						//车牌信息
    CHAR *pPicBuffer;                                   //全景图片Buffer
    UINT uiPicSize;                                     //全景图片大小
    CHAR *pLPBuffer;                                    //车牌特写图片Buffer
    UINT uiLPPicSize;                                   //车牌特写图片大小
	CHAR szReserved[512];								//预留字段szReserved[0]-szReserved[32]预留给485外设序列号
}LPR_CAPTURE_RES_S;

typedef struct AREA_CROP_PARA
{
    ULONG ulChnID;                                      //通道号
    BOOL bEnable;                                       //使能
    PU_STREAM_TYPE_E enStreamType;                      //码流类型
    PU_RESOLUTION_TYPE_E enResolution;                  //分辨率
    PU_AREA_INFO_S stAreaInfo;                          //区域信息
    CHAR szReserved[64];
}PU_AREA_CROP_PARA_S;

//手动车牌抓拍参数
typedef struct MANUAL_LPR_CAPTURE_S 
{
    ULONG ulSnapNum;
    ULONG aulSnapInterval[MAX_BURST_SHOOTING_NUM - 1];
    CHAR  szReserved[PU_RESERVE_LEN];
} PU_MANUAL_LPR_CAPTURE_S;

//EPTZ控制
typedef struct PU_EPTZ_CTRL
{
    ULONG ulChnID;                           
    PU_STREAM_TYPE_E enStreamType;
    BOOL bMoveEnable;
    LONG lHorizonalSpeed;
    LONG lVerticalSpeed;
    LONG lZoomSpeed;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EPTZ_CTRL_S;

//回声消除
typedef struct PU_AEC_ENABLE
{
    ULONG ulChnID;
    BOOL bEnable;
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_AEC_ENABLE_S;

//车道线配置
typedef struct PU_IMRS_LINE
{
    PU_IGT_POINT_S stStartPoint;
    PU_IGT_POINT_S stEndPoint;
}PU_IMRS_LINE_S;

//车牌参数
typedef struct PU_VLP_PARA
{
    CHAR szPlateLocalZH[MAX_PLATE_LOCAL_ZH_LEN]; // 优先城市类型，最多6个，超过6个取6个，如“沪苏浙″(C20版本仅支持一个)
    BOOL bInclineRectify;                        // 开启倾斜矫正
    INT  iPlateSize;                             // 大小车牌配置，0小车牌，1大车牌，2微小车牌；小车牌[40,200]，大车牌[200,400]
}PU_VLP_PARA_S;

//车牌全局参数配置
typedef struct PU_VLPR_PARA
{
    ULONG                ulChnID;                // 通道ID
    BOOL                 bEnable;                // 是否使能
    INT                  iLaneNum;               // 车道数量
    PU_IMRS_LINE_S       stLane[MAX_AREA_VERTEX];// 车道线 = 车道数+1
    PU_VEHICLE_DIR_E     enVehicleDir;           // 车辆方向，默认车头
    PU_VLPR_CATCH_MODE_E enCatchMode;            // 抓拍类型 0:机动车 1:机非人
    PU_VLP_PARA_S        stVLPParam;             // 车牌参数
    BOOL bVColorDetection;                       // 车辆颜色检测启用
    BOOL bVTypeDetection;                        // 车辆类型检测启用
    BOOL bSendPanoramaPic;                       // 是否发送全景图
    BOOL bSendPlatePic;                          // 是否发送车牌小图
}PU_VLPR_PARA_S;

//车牌全局参数配置，扩展车牌算法类型字段
typedef struct PU_VLPR_PARA_V2
{
    ULONG                ulChnID;                // 通道ID
    BOOL                 bEnable;                // 是否使能
    INT                  iLaneNum;               // 车道数量
    PU_IMRS_LINE_S       stLane[MAX_AREA_VERTEX];// 车道线 = 车道数+1
    PU_VEHICLE_DIR_E     enVehicleDir;           // 车辆方向，默认车头
    PU_VLPR_CATCH_MODE_E enCatchMode;            // 抓拍类型 0:机动车 1:机非人
    PU_VLP_PARA_S        stVLPParam;             // 车牌参数
    BOOL bVColorDetection;                       // 车辆颜色检测启用
    BOOL bVTypeDetection;                        // 车辆类型检测启用
    BOOL bSendPanoramaPic;                       // 是否发送全景图
    BOOL bSendPlatePic;                          // 是否发送车牌小图
    PU_VLPR_ALG_MODE_E enAlgMode;  //车牌算法类型
    CHAR szReserved[PU_RESERVE_LEN];
}PU_VLPR_PARA_V2_S;

//车牌补光灯 时间布防结构体
typedef struct PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO
{
	ULONG	ulStartTime;				    // 开始时间
	ULONG	ulEndTime;						// 结束时间
    CHAR    szReserved[PU_RESERVE_LEN];
}PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO_S;

typedef enum  PU_CAPLAMPCTRL_TYPE
{
	TYPE_CTRLTYPE_IO     = 0,   //IO控制
	TYPE_CTRLTYPE_RS485  = 1,   //485控制
	TYPE_CTRLTYPE_PWM    = 2,   //PWM控制
	TYPE_CTRLTYPE_MAX
}PU_CAPLAMPCTRL_TYPE_E;


//补光灯参数
typedef struct PU_SUPPLEMENT_LIGHT_LAMP_INFO
{
	ULONG ulOutputId;
    ULONG ulLampGroupLum;                               //灯组亮度控制1-100
    ULONG ulSensitivity;                                //开启补光灯画面亮度灵敏度0-2
	PU_SUPPLEMENT_LIGHT_LAMP_IO_MODE_E enIOMode;
	PU_SUPPLEMENT_LIGHT_LAMP_CTRL_MODE_E enControlMode;
	PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO_S stTimePlan;
    CHAR szReserved[PU_RESERVE_LEN];					//szReserver[0]表示红外灯亮度1-100,默认50
}PU_SUPPLEMENT_LIGHT_LAMP_INFO_S;


//补光参数
typedef struct PU_SUPPLEMENT_LIGHT_INFO
{
	ULONG ulChannelId;          // 通道ID
	ULONG ulActiveNum;
	PU_SUPPLEMENT_LIGHT_LAMP_INFO_S stLampInfo[MAX_SUPPLEMENT_LIGHT_LAMP_NUM];
    CHAR szReserved[PU_RESERVE_LEN];     //szReserved[0]表示补光灯类型 PU_SUPPLEMENTLAMP_TYPE_E
                                         //szReserved[1]表示补光灯手、自动模式控制类型PU_LAMP_CTRL_MODE_E
	                                     //szReserved[2]表示补光灯控制类型PU_CAPLAMPCTRL_TYPE_E
										 //szReserved[3]表示智能红外等级0~100默认50
} PU_SUPPLEMENT_LIGHT_INFO_S;


//证书到期周期参数
typedef struct PU_CERT_EXPIRE_PERIOD_PARA
{
    ULONG ulCheckPeriod;					//检测周期(当前不支持配置)
    ULONG ulAdvancedAlarmPeriod;			//提前告警周期
}PU_CERT_EXPIRE_PERIOD_PARA_S;

//I/P帧编码策略
typedef struct PU_KF_CODING_STRATEGY_PARA
{
    ULONG ulChnID;
    BOOL bEnable;
    PU_STREAM_TYPE_E enStreamType;
    ULONG ulLevel;
}PU_KF_CODING_STRATEGY_PARA_S;

//OSD边距
typedef struct PU_OSD_MARGIN_INFO
{
    ULONG ulChnID;
    ULONG ulDirect;                        //OSD边距方向,0:上 1:下 2:左 3:右
    BOOL  bEnable;
    ULONG ulMarginLength;			       //边距宽度,字符个数(0~2)
}PU_OSD_MARGIN_INFO_S;

typedef struct FD_AREA
{
	BOOL bEnable;
    UINT uiPointNum;
    PU_SQUARE_PARA_S stPoint[FD_AREA_POINT_NUM];
    CHAR szAreaName[FD_AREA_NAME_LEN];
}FD_AREA_S;

typedef struct PU_FD_AREA_LIST
{
	ULONG       ulAreaNum;
    FD_AREA_S   szAreaList[FD_AREA_NUM];
}PU_FD_AREA_LIST_S;

typedef struct PU_FACE_DETC_PARA
{
	ULONG ulAlarmTime;          // 告警检测时间
	BOOL  bEnable;              // 使能
    ULONG ulSensitivity;        // 检测灵敏度
	ULONG ulMinDectFace;        // 最小检测人脸，范围66-486，切到远景模式，建议最小人脸70，最大人脸180；切到近景模式，建议最小人脸131，最大人脸273
    ULONG ulMaxDectFace;        // 最大检测人脸，范围66-486，切到远景模式，建议最小人脸70，最大人脸180；切到近景模式，建议最小人脸131，最大人脸273
    ULONG ulDectMode;           // 检测模式 0：远景模式  1：近景模式
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_FACE_DETC_PARA_S;

typedef struct PU_FACE_TRACKING_PARAMETER
{
    BOOL bFilter;               // 启用跟踪矫正模式(也称为误检过滤模式)
    BOOL bCrowded;              // 启用人员密集模式
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_FACE_TRACKING_PARAMETER_S;

typedef struct PU_FACE_PROCESS_PARAM
{
    BOOL bSendFaceImg;                  // 发送人脸抠图
    BOOL bSendPanorama;                 // 发送全景图
    ULONG ulImgQuality;                 // 图像抓拍质量(1-10)
    CHAR  szReserved[PU_RESERVE_LEN];   // szReserved[0]表示人脸抠图张数（1-5），默认为1
                                        //szReserved[1]表示图像增强
                                        //szReserved[2]表示人脸图抓拍质量(1-10)，默认为10
                                        //szReserved[3]表示全景图抓拍质量(1-10)，默认为5
                                        //szReserved[4]表示人脸属性开关
                                        //szReserved[5]表示启用人脸误检DetectErrFilter (0关闭,1启用)
                                        //szReserved[6]表示人脸误检过滤灵敏度DtEFSen (1-10)，默认为5
}PU_FACE_PROCESS_PARAM_S;

//场景变更
typedef struct PU_SCENECHANGE_PARA
{
    ULONG ulChnID;              //通道号
    BOOL  bEnable;              //使能
    ULONG ulSensitivity;        //灵敏度
    ULONG ulCheckInterval;      //检测间隔
    ULONG ulAlarmInterval;      //告警上报间隔
    PU_ALARM_TIME_LIST_S stAlarmTimeList;       //布防时间列表
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_SCENECHANGE_PARA_S;

//虚焦检测  
typedef struct PU_OUTOFFOCUS_DETECT_PARA
{
    ULONG ulChnID;              //通道号
    BOOL  bEnable;              //使能
    ULONG ulSensitivity;        //灵敏度
    ULONG ulAlarmInterval;      //告警上报间隔
    PU_ALARM_TIME_LIST_S stAlarmTimeList;       //布防时间列表
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_OUTOFFOCUS_DETECT_PARA_S;

//聚集检测
typedef struct PU_GATHER_CHECK_PARA
{
    ULONG                        ulChnID;                           //通道号
    BOOL                         bEnable;                           //使能
    ULONG                        ulSensitivity;                     //灵敏度
    ULONG                        ulAlarmInterval;                   //检测间隔
    PU_ALARM_TIME_LIST_S         stAlarmTimeList;                   //布防时间列表
    PU_IGT_AERADTC_LIST_S        szAreaList;                        //划线区域
    CHAR                         szReserved[PU_RESERVE_LEN];
}PU_GATHER_CHECK_PARA_S;

//新增告警质量诊断“抖动”“画面冻结”“雪花噪声”“条纹噪声”“亮度”“偏色”“云台失控”
//的参数类型与虚焦检测参数类型相同，用同一个结构体 + by g00380004

typedef enum PU_ALARM_VIDEODIAGNOSIS_TYPE
{
	//    ALARM_BLUR = 0,    // 模糊度诊断
	ALARM_SHAKE=0,            // 抖动诊断
	ALARM_FROZEN,           // 画面冻结诊断
	ALARM_NOISE,           // 雪花噪声诊断
	ALARM_STRIPENOISE,            // 条纹噪声诊断
	ALARM_BRIGHT,             // 亮度诊断
	ALARM_COLORCAST,         // 偏色诊断
	//    ALARM_VIDEOLOSE,      //信号丢失
	//    ALARM_SHELTE,           //视频遮挡
	//ALARM_PTZLOSECONTROL,      //云台失控

	ALARM_VIDEODIAGNOSIS_TYPE_MAX
}PU_ALARM_VIDEODIAGNOSIS_TYPE_E;

//视频诊断
typedef struct PU_VIDEODIAGNOSIS_PARA
{
	ULONG ulChnID;								 //通道号
	PU_ALARM_VIDEODIAGNOSIS_TYPE_E enAlarmType;  //告警类型
	BOOL  bEnable;								 //使能
	ULONG ulSensitivity;						 //灵敏度
	ULONG ulAlarmInterval;						 //告警上报间隔
	PU_ALARM_TIME_LIST_S stAlarmTimeList;        //布防时间列表
	CHAR  szReserved[PU_RESERVE_LEN];
}PU_VIDEODIAGNOSIS_PARA_S;

/**************** 视频诊断使能消息参数***************************/
typedef struct PU_VIDEODIAGNOSIS_ENABLE_PARAM
{
	ULONG                            ulChnID;    // 通道ID
	BOOL                             bEnable;       // 算法使能
	PU_ALARM_TIME_LIST_S             stAlarmTimeList;// 暂时没用，对应接口

}PU_VIDEODIAGNOSIS_ENABLE_PARAM_S;

//人脸检测
typedef struct PU_FACE_DETC_ALARM_PARA
{
	ULONG ulChnID;                                       //通道ID
	ULONG ulBitMap;                                      //0000,最后一位置1，表示设置第一个结构体内参数
	PU_FACE_DETC_PARA_S stFDPara;                        //人脸检测参数
	PU_FACE_TRACKING_PARAMETER_S stFDTrackPara;          //人脸跟踪参数
	PU_FACE_PROCESS_PARAM_S stFDProcPara;                //人脸处理参数
	PU_FD_AREA_LIST_S stAreaList;                        //人脸检测区域
	PU_ALARM_TIME_LIST_S stFDGuardPlan;                  //人脸检测布防计划
}PU_FACE_DETC_ALARM_PARA_S;

typedef enum FACE_DT_CAP_MODE
{
    FACE_CAP_DEFAULT_MODE = 0, //默认抓拍模式,目标离开后抓拍
    FACE_CAP_QUICK_MODE,                //快速抓拍模式
}FACE_DT_CAP_MODE_E;

//人脸人体检测算法参数
typedef struct PU_FACE_DETC_DL_PARA
{
	BOOL  bEnable;						// 使能
	ULONG ulAlarmTime;					// 告警检测时间
    ULONG ulSensitivity;				// 检测灵敏度
    ULONG ulFaceSensitivity;			// 人脸检测灵敏度
    ULONG ulBodySensitivity;			// 人体检测灵敏度
    ULONG ulFaceKpsSensitivity;			// 人脸质量过滤灵敏度
    ULONG ulBodyKpsSensitivity;			// 人体质量过滤灵敏度
    ULONG ulMinPupilDist;				// 最小人脸
    ULONG ulMaxPupilDist;				// 最大人脸
    PU_FACE_DETECTION_DL_MODE_E enMode; // 检测模式
    BOOL  bFaceExposure;				// 人脸曝光
    ULONG ulROIMeterLevel;				// 人脸曝光灵敏度
    FACE_DT_CAP_MODE_E   enFaceCapMode;	// 抓拍模式
	UCHAR ulFaceCapSensitivity;			// 快速抓拍灵敏度
    UCHAR uchFaceExposureTime;			// 人脸曝光时间
	BOOL  bSensitivityFlage;			// 质量灵敏度开关 对应上面质量灵敏度
    CHAR  szReserved[PU_RESERVE_LEN - sizeof(FACE_DT_CAP_MODE_E) - sizeof(UCHAR)*2 - sizeof(BOOL)];
}PU_FACE_DETC_DL_PARA_S;

//人脸人体检测处理参数
typedef struct PU_FACE_PROCESS_DL_PARAM
{
     BOOL bSendFaceImg;          // 发送人脸抠图
    BOOL bSendBodyImg;          // 发送人体抠图
    BOOL bSendPanorama;         // 发送全景图
    BOOL bFaceEnhancement;      // 图像增强
    ULONG ulFaceImgQuality;     // 人脸图抓拍质量(1-10)
    ULONG ulBodyImgQuality;     // 人体抠图质量(1-10)
    ULONG ulPanoramaImgQuality; // 全景图抓拍质量(1-10)
    ULONG ulSendFaceNum;        // 发送的人脸小图数量
    ULONG ulSendBodyNum;        // 发送的人体小图数量
    CHAR  szReserved[PU_RESERVE_LEN];   
}PU_FACE_PROCESS_DL_PARAM_S;

//人脸人体检测
typedef struct PU_FACE_DETC_DL_ALARM_PARA
{
	ULONG ulChnID;                                       //通道ID
	ULONG ulBitMap;                                      //0000,最后一位置1，表示设置第一个结构体内参数
	PU_FACE_DETC_DL_PARA_S stFDPara;                     //人脸检测参数
	PU_FACE_PROCESS_DL_PARAM_S stFDProcPara;             //人脸处理参数
	PU_FD_AREA_LIST_S stAreaList;                        //人脸检测区域
	PU_FD_AREA_LIST_S stUnGuardAreaList;                 //人脸不检测区域
	PU_ALARM_TIME_LIST_S stFDGuardPlan;                  //人脸检测布防计划
}PU_FACE_DETC_DL_ALARM_PARA_S;

//人脸识别
typedef struct PU_FACE_RECOGNITION_PARA
{
    BOOL            bEnable;            // 算法使能
    ULONG           ulChannelId;        // 通道ID
    ULONG           ulAlarmTime;        // 告警上报间隔
}PU_FACE_RECOGNITION_PARA_S;



//机非人参数
typedef struct PU_VHD_PARA
{
    ULONG                  ulChannelId;          // 通道ID
    BOOL                    bEnable;              // 是否使能
    BOOL                    bSendSnapPicture;     //上传目标小图
    BOOL                    bSendPanorama;        //上传全景
    BOOL                    bLaneLineEnable;                        //车道线是否使能
    PU_VLPR_ALG_MODE_E      enAlgMode;                              //抓拍算法类型
    INT                     iWidth;                                 //配置图像宽度
    INT                     iHeight;                                //配置图像高度
    INT                     iLaneNum;                               //车道数量
    PU_IMRS_LINE_S          stLane[MAX_AREA_VERTEX];                //车道线 = 车道数+1
    CHAR                    szPlateLocalZH[MAX_PLATE_LOCAL_ZH_LEN]; // 优先城市类型，最多6个，超过6个取6个，如“沪苏浙”

    BOOL                    bExposureEnable;    //曝光使能
    CHAR                    ulROIMeterLevel;    //曝光系数
    
    CHAR            szReserved[PU_RESERVE_LEN - sizeof(BOOL) - sizeof(BOOL)-sizeof(BOOL)-sizeof(CHAR)];//
}PU_VHD_PARA_S,*LPPU_VHD_PARA_S;

/* 关联录像信息*/
typedef struct PU_ASSOCIATE_RECORD_INFO
{
    BOOL    bRecordExist;     // 是否存在关联录像
    ULONG   ulStartTime;    // 关联录像的起始时间
    ULONG   ulEndTime;      // 关联录像的结束时间
}PU_ASSOCIATE_RECORD_INFO_S;

//图片信息
typedef struct PU_IMAGE_INFO_LIST
{
    ULONG ulSnapTime;                                   //抓拍时间
    ULONG ulContentSize;                                //图片大小
    CHAR  szContentID[PU_SNAPSHOT_PICTURE_NAME_LEN];    //图片名
    PU_ASSOCIATE_RECORD_INFO_S stRecordInfo;    // 关联录像信息(仅电子警察设备有效,且IVS_PU_GetITSSnapshotPicList有指定违章类型)
    CHAR  szReserved[PU_RESERVE_LEN - sizeof(PU_ASSOCIATE_RECORD_INFO_S)];
}PU_IMAGE_INFO_LIST_S;

//图片查询请求
typedef struct PU_SNAPSHOT_INQUIRE
{
    ULONG ulChnID;
    ULONG ulBeginIndex;		            // 当前开始记录索引(>=1)
    ULONG ulBeginTime;                  // 开始时间(time_t/localTime=GMT+时区)
    ULONG ulEndTime;                    // 结束时间
    PU_SNAPSHOT_TYPE_E enSnapShotType;  // 抓拍类型
    CHAR szReserved[PU_RESERVE_LEN];//szReserved[0]单页查询flag
 }PU_SNAPSHOT_INQUIRE_S;

//图片查询结果
typedef struct PU_SNAPSHOT_LIST
{
    ULONG ulTotalNum;			// 总记录数
    ULONG ulBeginIndex;		    // 当前开始记录数
    ULONG ulEndIndex;			// 当前结束记录数
    PU_IMAGE_INFO_LIST_S szImageInfoList[PU_SNAPSHOT_INQUIRE_NUM];  //图片信息
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SNAPSHOT_LIST_S;

// 一张合成方式
typedef enum PU_ONE_PIC_SYNTHESIS_TYPE
{
    PU_ONE_PIC_SYNTHESIS_TYPE1 = 0, // 特写在上
    PU_ONE_PIC_SYNTHESIS_TYPE2,     // 特写在下
    PU_ONE_PIC_SYNTHESIS_TYPE3,     // 特写在左
    PU_ONE_PIC_SYNTHESIS_TYPE4,     // 特写在右
    PU_ONE_PIC_NO_SYNTHESIS,        // 不合成
    PU_ONE_PIC_SYNTHESIS_TYPE_MAX
} PU_ONE_PIC_SYNTHESIS_TYPE_E;

// 两张合成方式
typedef enum PU_TWO_PIC_SYNTHESIS_TYPE
{
    PU_TWO_PIC_SYNTHESIS_TYPE1 = 0, // 上下合成
    PU_TWO_PIC_SYNTHESIS_TYPE2,     // 左右合成
    PU_TWO_PIC_SYNTHESIS_TYPE3,     // 三张图片上下排列，特写图在最上方
    PU_TWO_PIC_SYNTHESIS_TYPE4,     // 三张图片上下排列，特写图在最下方
    PU_TWO_PIC_SYNTHESIS_TYPE5,     // 三张图片左右排列，特写图在最左方
    PU_TWO_PIC_SYNTHESIS_TYPE6,     // 三张图片左右排列，特写图在最右方
    PU_TWO_PIC_SYNTHESIS_TYPE7,     // 三张图片品字型排列，特写图在最上方
    PU_TWO_PIC_SYNTHESIS_TYPE8,     // 三张图片品字型排列，特写图在最下方
    PU_TWO_PIC_SYNTHESIS_TYPE9,     // 三张图片品字型排列，特写图在最左方
    PU_TWO_PIC_SYNTHESIS_TYPE10,    // 三张图片品字型排列，特写图在最右方
    PU_TWO_PIC_NO_SYNTHESIS,        // 不合成
    PU_TWO_PIC_SYNTHESIS_TYPE_MAX
} PU_TWO_PIC_SYNTHESIS_TYPE_E;

// 三张合成方式
typedef enum PU_THREE_PIC_SYNTHESIS_TYPE
{
    PU_THREE_PIC_SYNTHESIS_TYPE1 = 0, // 上下合成
    PU_THREE_PIC_SYNTHESIS_TYPE2,     // 左右合成
    PU_THREE_PIC_SYNTHESIS_TYPE3,     // 三张+特写田字合成上下排列，特写图在左上方
    PU_THREE_PIC_SYNTHESIS_TYPE4,     // 三张+特写田字合成上下排列，特写图在右上方
    PU_THREE_PIC_SYNTHESIS_TYPE5,     // 三张+特写田字合成上下排列，特写图在左下方
    PU_THREE_PIC_SYNTHESIS_TYPE6,     // 三张+特写田字合成上下排列，特写图在右下方
    PU_THREE_PIC_SYNTHESIS_TYPE7,     // 三张品字形，第二张在上
    PU_THREE_PIC_SYNTHESIS_TYPE8,     // 三张品字形，第二张在下
    PU_THREE_PIC_NO_SYNTHESIS,        // 不合成
    PU_THREE_PIC_SYNTHESIS_TYPE_MAX
} PU_THREE_PIC_SYNTHESIS_TYPE_E;

//PU_PIC_SYNTHESIS_PARA_S 新接口使用的枚举类型
typedef enum PU_COMBINE_TYPE
{
    PU_COMB_SIGNEL_NOROI, /* 抓拍一张无特写 */
    PU_COMB_SIGNEL_HOR, /* 一张抓拍，原图加特写，水平合成 */
    PU_COMB_SIGNEL_VER, /* 一张抓拍，原图加特写，垂直合成 */

    PU_COMB_DOUBLE_HOR_NOROI, /* 抓拍两张无特写，水平合成 */
    PU_COMB_DOUBLE_VER_NOROI, /* 抓拍两张无特写，垂直合成 */
    PU_COMB_DOUBLE_HOR, /* 两张抓拍，原图加特写，水平合成 */
    PU_COMB_DOUBLE_VER, /* 两张抓拍，原图加特写，垂直合成 */
    PU_COMB_DOUBLE_PYRAMIDAL_TOP, /* 两张抓拍，原图加特写，品字形合成 */
    PU_COMB_DOUBLE_PYRAMIDAL_BUTT, /* 两张抓拍，原图加特写，倒品字形合成 */
    PU_COMB_DOUBLE_PYRAMIDAL_LEFT, /* 两张抓拍，原图加特写，品字形头朝左合成 */
    PU_COMB_DOUBLE_PYRAMIDAL_RIGHT, /* 两张抓拍，原图加特写，品字形头朝右合成 */

    PU_COMB_TREBLE_HOR_NOROI, /* 抓拍三张无特写，水平合成 */
    PU_COMB_TREBLE_VER_NOROI, /* 抓拍三张无特写，垂直合成 */
    PU_COMB_TREBLE_HOR, /* 三张抓拍，原图加特写，水平合成 */
    PU_COMB_TREBLE_VER, /* 三张抓拍，原图加特写，垂直合成 */
    PU_COMB_TREBLE_PYRAMIDAL_TOP, /* 三张抓拍，原图加特写，品字形合成 */
    PU_COMB_TREBLE_PYRAMIDAL_BUTT, /* 三张抓拍，原图加特写，倒品字形合成 */
    PU_COMB_TREBLE_PYRAMIDAL_LEFT, /* 三张抓拍，原图加特写，品字形头朝左合成 */
    PU_COMB_TREBLE_PYRAMIDAL_RIGHT, /* 三张抓拍，原图加特写，品字形头朝右合成 */
    PU_COMB_TREBLE_SQUARE, /* 三张抓拍，原图加特写，田字形合成 */
	PU_COMB_TREBLE_SQUARE_NOROI,   /*抓拍四张无特写，田字形合成*/
	
	PU_COMB_SIX_IN_ONE_HOR,   /* ITS电警6合1，横条，框*3 高*2 */
    PU_COMB_SIX_IN_ONE_VER,   /* ITS电警6合1，竖条，框*2 高*3 */

	//若需新增1张合成方式枚举值，从50开始

	//新增2张合成方式枚举值，从100开始
	PU_COMB_DOUBLE_PYRAMIDAL_TOP_ADAPT = 100, /* 两张抓拍，原图加特写，品字形合成调整大小 */
    PU_COMB_DOUBLE_PYRAMIDAL_BUTT_ADAPT, /* 两张抓拍，原图加特写，倒品字形合成调整大小 */
    PU_COMB_DOUBLE_PYRAMIDAL_LEFT_ADAPT, /* 两张抓拍，原图加特写，品字形头朝左合成调整大小 */
    PU_COMB_DOUBLE_PYRAMIDAL_RIGHT_ADAPT, /* 两张抓拍，原图加特写，品字形头朝右合成 调整大小*/

	//新增3张合成方式枚举值，从150开始
	PU_COMB_TREBLE_PYRAMIDAL_TOP_ADAPT = 150, /* 三张抓拍，无特写，品字形合成 调整大小 */
    PU_COMB_TREBLE_PYRAMIDAL_BUTT_ADAPT, /* 三张抓拍，无特写，倒品字形合成调整大小  */
    PU_COMB_TREBLE_PYRAMIDAL_LEFT_ADAPT, /* 三张抓拍，无特写，品字形头朝左合成调整大小  */
    PU_COMB_TREBLE_PYRAMIDAL_RIGHT_ADAPT, /* 三张抓拍，无特写，品字形头朝右合成调整大小  */

    PU_COMB_TREBLE_BUTT,
} PU_COMBINE_TYPE_E;

typedef enum PU_COMBINE_IMG_ROI
{
	PU_COMBINE_IMG0_ORI, /* 第0张抓拍原图 */
	PU_COMBINE_IMG0_ROI, /* 第0张抓拍抠图, 不支持 */
	PU_COMBINE_IMG1_ORI, /* 第1张抓拍原图 */
	PU_COMBINE_IMG1_ROI, /* 第1张抓拍抠图，不支持*/
	PU_COMBINE_IMG2_ORI, /* 第2张抓拍原图 */
	PU_COMBINE_IMG2_ROI, /* 第2张抓拍抠图，不支持 */
	PU_COMBINE_IMG3_ORI, /* 第3张抓拍原图 */
	PU_COMBINE_IMGS_ROI, /* 特写图，具体哪张的特写图由智能定*/

	PU_COMB_IMG_GW_ORI, /* 6合1卡口抓拍原图 */
	PU_COMB_IMG_GW_ROI, /* 6合1卡口抓拍特写图 */

	PU_COMBINE_IMG_BUTT,
} PU_COMBINE_IMG_ROI_E;

typedef enum PU_COMBINE_SCALE
{
	PU_COMB_SIZE_ORG,	//原图尺寸
	PU_COMB_SIZE_QUARTER, //四分之一
	PU_COMB_SIZE_RESERVE,
}PU_COMBINE_SCALE_E;

typedef enum PU_PIC_OSD_LOCATION
{
    PU_PIC_IN_TOP = 0,
    PU_PIC_IN_BOTTOM,
    PU_PIC_OUT_TOP,
    PU_PIC_OUT_BOTTOM,
    PU_PIC_OSD_LOCATION_MAX
}PU_PIC_OSD_LOCATION_E;

// 叠加图片类型
typedef enum PU_OVERLAY_PIC_TYPE
{
    PU_ORG_PIC = 0,   // 原图
    PU_SYNTHESIS_PIC, // 合成图
    PU_OVERLAY_PIC_TYPE_MAX
}PU_OVERLAY_PIC_TYPE_E;

typedef enum
{
    PU_OSD_FONT_SIZE_SMALL = 0,
    PU_OSD_FONT_SIZE_MEDIUM,
    PU_OSD_FONT_SIZE_LARGE,
    PU_OSD_FONT_SIZE_MAX
} PU_FONT_SIZE_E;

typedef enum PU_FONT_SIZE_EXT
{
    PU_OSD_FONT_SIZE_16,
    PU_OSD_FONT_SIZE_24,
    PU_OSD_FONT_SIZE_32,
    PU_OSD_FONT_SIZE_48,
    PU_OSD_FONT_SIZE_64,
    PU_OSD_FONT_SIZE_96,
    PU_OSD_FONT_SIZE_128,
    PU_OSD_FONT_SIZE_EXT_MAX,
}PU_FONT_SIZE_EXT_E;

// 图片OSD类型
typedef enum PU_PIC_OSD_TYPE
{
    PU_TIME_OSD = 0,
    PU_PLATE_ID_OSD,
    PU_VEHICLE_TYPE_OSD,
    PU_LANE_ID_OSD,
    PU_PLATE_COLOR_OSD,
    PU_VEHICLE_COLOR_OSD,
    PU_ROAD_ID_OSD,
    PU_DEV_ID_OSD,
    PU_DIR_ID_OSD,
    PU_DIR_OSD,
    PU_CUSTOM_OSD,
    PU_SECURITY_CODE_OSD,
    PU_PRE_BRAND_TYPE_OSD,                              //车款
    PU_SUB_BRAND_TYPE_OSD,                              //子款
    PU_YEAR_BRAND_TYPE_OSD,                             //年款
    PU_LOCATE_DESC_OSD,                                 //路口信息位置描述
    PU_MONITOR_INFO_OSD,                                //监测信息点
    PU_BRAND_INFO_OSD,                                  //品牌信息
    PU_VEHICLE_SPEED_OSD,                               //车速
    PU_LANE_DESC_OSD,                                   //车道描述
    PU_SNAP_SERIAL_NUM_OSD,                             //抓拍序号
    PU_ILLEGAL_NUM_OSD,                                 //违法代码
    PU_ILLEGAL_DESC_OSD,                                //违法代码描述
    PU_SPEED_LIMIT_OSD,                                 //限速信息
    PU_ILLEGAL_SPEED_OSD,                               //超速/低速等违章速度比计算
    PU_LANE_DIR_DESC_OSD,                               //车道方向描述
    PU_VEHICLE_LEN_DESC_OSD,                            //车长
    PU_REDLIGHT_START_OSD,                              //红灯开始时间
    PU_REDLIGHT_END_OSD,                                //红灯结束时间
    PU_REDLIGHT_PERIOD_OSD,                             //红灯持续时间
    
    PU_SNAPTRIG_OSD,                                    //抓拍触发源
    PU_VEHICLE_MFR_TYPE_OSD,                            //机动车二次特征
    PU_RADAR_CHECK_DIR_OSD,                             //雷达测速方向
    PU_VEHICLE_DIR_OSD,                                 //车辆行驶方向
    PU_VEHICLE_TYPE_EXT_OSD,                            //扩展车型
    PU_PIC_OSD_TYPE_MAX
}PU_PIC_OSD_TYPE_E;


typedef enum PU_ITS_PIC_SYNTHESIS_TYPE
{
    ITS_TYPE_EPOLICE_PIC_SYNTHESIS = 0,       //电警
    ITS_TYPE_TGATEWAY_PIC_SYNTHESIS = 1,      //卡口
    ITS_TYPE_PIC_SYNTHESIS_MAX,
}PU_ITS_PIC_SYNTHESIS_TYPE;

typedef enum PU_FACE_SYN_SCALE_TYPE
{
	FACE_SYN_SCALE_LAYER1 = 0,		//小
	FACE_SYN_SCALE_LAYER2 = 1,		//中
	FACE_SYN_SCALE_LAYER3 = 2,		//大
	FACE_SYN_SCALE_MAX,
}PU_FACE_SYN_SCALE_TYPE_E;


// 新版本图片合成数据结构
typedef struct PU_PIC_SYNTHESIS_PARA_V3
{
	ULONG ulChnID;          // 通道ID
	BOOL  bEnable;          // 是否启用合成

	//旧版本使用成员变量(为向前兼容)    //新版暂停使用
	PU_ONE_PIC_SYNTHESIS_TYPE_E   enOnePicSynthesisType;
	PU_TWO_PIC_SYNTHESIS_TYPE_E   enTwoPicSynthesisType;
	PU_THREE_PIC_SYNTHESIS_TYPE_E enThreePicSynthesisType;

	//新版本使用的成员变量
	PU_COMBINE_TYPE_E               astCombineType[PU_SNAP_NUM_MAX2];
	PU_COMBINE_IMG_ROI_E            astOnePicROI[2];
	PU_COMBINE_IMG_ROI_E            astTwoPicROI[3];
	PU_COMBINE_IMG_ROI_E            astThreePicROI[6];
	PU_COMBINE_SCALE_E enCombineScale;      //合成图尺寸
	ULONG  ulJpegQuality;               //合成图编码质量    
	ULONG   ulPicSynthesisEnableMask[ITS_TYPE_PIC_SYNTHESIS_MAX];  // 掩码[2~2^32)，每一位对应PU_ITS_REGULA_TYPE_E中违章是否启用图片合成,手动抓拍(0)不支持合成
	BOOL   bFaceSynthesisEnable;		//是否启用人脸合成
	PU_FACE_SYN_SCALE_TYPE_E enFaceSynthesisScale;	//人脸抠图大小
	CHAR   szReserved[PU_RESERVE_EX_LEN];
} PU_PIC_SYNTHESIS_PARA_V3_S;

// 旧版本图片合成数据结构
typedef struct PU_PIC_SYNTHESIS_PARA_V2
{
    ULONG ulChnID;          // 通道ID
    BOOL  bEnable;          // 是否启用合成

    //旧版本使用成员变量(为向前兼容)    //新版暂停使用
    PU_ONE_PIC_SYNTHESIS_TYPE_E   enOnePicSynthesisType;
    PU_TWO_PIC_SYNTHESIS_TYPE_E   enTwoPicSynthesisType;
    PU_THREE_PIC_SYNTHESIS_TYPE_E enThreePicSynthesisType;

    //新版本使用的成员变量
    PU_COMBINE_TYPE_E               astCombineType[PU_SNAP_NUM_MAX];
    PU_COMBINE_IMG_ROI_E            astOnePicROI[2];
    PU_COMBINE_IMG_ROI_E            astTwoPicROI[3];
    PU_COMBINE_IMG_ROI_E            astThreePicROI[4];
    PU_COMBINE_SCALE_E enCombineScale;      //合成图尺寸
    ULONG  ulJpegQuality;               //合成图编码质量    
    ULONG  ulPicSynthesisEnableMask[ITS_TYPE_PIC_SYNTHESIS_MAX];  // 掩码[2~2^32)，每一位对应PU_ITS_REGULA_TYPE_E中违章是否启用图片合成,手动抓拍(0)不支持合成
	BOOL   bFaceSynthesisEnable;		//是否启用人脸合成
	PU_FACE_SYN_SCALE_TYPE_E enFaceSynthesisScale;	//人脸抠图大小
    CHAR   szReserved[PU_RESERVE_LEN-(sizeof(ULONG)*ITS_TYPE_PIC_SYNTHESIS_MAX) - sizeof(BOOL) - sizeof(PU_FACE_SYN_SCALE_TYPE_E)];
} PU_PIC_SYNTHESIS_PARA_V2_S;

// 旧版本图片合成数据结构
typedef struct PU_PIC_SYNTHESIS_PARA
{
    ULONG ulChnID;          // 通道ID
    BOOL  bEnable;          // 是否启用合成

    //旧版本使用成员变量(为向前兼容)
    PU_ONE_PIC_SYNTHESIS_TYPE_E   enOnePicSynthesisType;
    PU_TWO_PIC_SYNTHESIS_TYPE_E   enTwoPicSynthesisType;
    PU_THREE_PIC_SYNTHESIS_TYPE_E enThreePicSynthesisType;
    
} PU_PIC_SYNTHESIS_PARA_S;

typedef struct PU_PIC_OSD_INFO_S 
{
    UINT uPicOSDNum;                                    // 需叠加的OSD数目
    PU_PIC_OSD_TYPE_E aenPicOSDType[PU_VLPR_PIC_OSD_TYPE_MAX];  // 叠加的类型
    PU_PIC_OSD_LOCATION_E enPicOSDLocation;             // OSD叠加位置
    PU_FONT_SIZE_E enFontSize;                          // 字体大小
    ULONG ulFgColor;                                    // 前景(文字)色彩格式0xRRGGBB或换算成十进制
    UCHAR ucFgAlpha;                                    // 前景（文字）透明度 范围0~128
    ULONG ulBgColor;                                    // 背景色彩 格式0xRRGGBB 或换算成十进制
    UCHAR ucBgAlpha;                                    // 背景透明度 范围0~128(海思)
} PU_PIC_OSD_INFO_S;

typedef struct PU_PIC_OSD_INFO_EX_S 
{
    UINT uPicOSDNum;                                    // 需叠加的OSD数目
    PU_PIC_OSD_TYPE_E aenPicOSDType[PU_VLPR_PIC_OSD_TYPE_MAX_EX];  // 叠加的类型
    PU_PIC_OSD_LOCATION_E enPicOSDLocation;             // OSD叠加位置
    PU_FONT_SIZE_E enFontSize;                          // 字体大小
    PU_FONT_SIZE_EXT_E enFontSizeExt;                   // 扩展OSD字体大小，新增枚举
    ULONG ulFgColor;                                    // 前景(文字)色彩格式0xRRGGBB或换算成十进制
    UCHAR ucFgAlpha;                                    // 前景（文字）透明度 范围0~128
    ULONG ulBgColor;                                    // 背景色彩 格式0xRRGGBB 或换算成十进制
    UCHAR ucBgAlpha;                                    // 背景透明度 范围0~128(海思)
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_PIC_OSD_INFO_EX_S;

typedef struct PU_TIME_OSD_PARA
{
    BOOL bNeedAccurateToMs;// 是否精确到ms
}PU_TIME_OSD_PARA_S;

typedef struct PU_CUSTOM_OSD_PARA  
{
    CHAR acOSDContent[PU_OSD_MAX_LENGTH]; // OSD内容
} PU_CUSTOM_OSD_PARA_S;

typedef struct PU_CUSTOM_OSD_PARA_EX  
{
    CHAR acOSDContent[PU_OSD_MAX_LENGTH_EX]; // OSD内容
} PU_CUSTOM_OSD_PARA_EX_S;

typedef struct PU_PIC_OSD_PARA
{
    ULONG ulChnID;                          // 通道ID
    PU_OVERLAY_PIC_TYPE_E enOverlayPicType; // 叠加OSD的图片类型
    PU_PIC_OSD_INFO_S stPicOSDInfo;         // 图片叠加信息
    PU_TIME_OSD_PARA_S stTimeOSDPara;       // 时间OSD参数
    PU_CUSTOM_OSD_PARA_S stRoadIdOSDPara;   // 路口编号参数
    PU_CUSTOM_OSD_PARA_S stDevIdOSDPara;    // 设备编号参数
    PU_CUSTOM_OSD_PARA_S stDirIdOSDPara;    // 方向编号参数
    PU_CUSTOM_OSD_PARA_S stDirOSDPara;      // 方向OSD参数
    PU_CUSTOM_OSD_PARA_S stCustomOSDPara;   // 自定义OSD参数
} PU_PIC_OSD_PARA_S;

typedef struct PU_PIC_OSD_PARA_V2
{
    ULONG ulChnID;                          // 通道ID
    PU_OVERLAY_PIC_TYPE_E enOverlayPicType; // 叠加OSD的图片类型
    PU_PIC_OSD_INFO_S stPicOSDInfo;         // 图片叠加信息
    PU_TIME_OSD_PARA_S stTimeOSDPara;       // 时间OSD参数
    PU_CUSTOM_OSD_PARA_S stRoadIdOSDPara;   // 路口编号参数
    PU_CUSTOM_OSD_PARA_S stDevIdOSDPara;    // 设备编号参数
    PU_CUSTOM_OSD_PARA_S stDirIdOSDPara;    // 方向编号参数
    PU_CUSTOM_OSD_PARA_S stDirOSDPara;      // 方向OSD参数
    PU_CUSTOM_OSD_PARA_S stCustomOSDPara;   // 自定义OSD参数
    BOOL  bDirOSDParaEn;      //行驶方向参数使能，1:表示ITS，不采用方向OSD参数 0:其他，采用方向OSD参数
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PIC_OSD_PARA_V2_S;


typedef struct PU_PIC_OSD_PARA_V3
{
    ULONG ulChnID;                          // 通道ID
    PU_OVERLAY_PIC_TYPE_E enOverlayPicType; // 叠加OSD的图片类型
    PU_PIC_OSD_INFO_EX_S stPicOSDInfo;         // 图片叠加信息
    PU_TIME_OSD_PARA_S stTimeOSDPara;       // 时间OSD参数
    PU_CUSTOM_OSD_PARA_EX_S stRoadIdOSDPara;   // 路口编号参数
    PU_CUSTOM_OSD_PARA_EX_S stDevIdOSDPara;    // 设备编号参数
    PU_CUSTOM_OSD_PARA_EX_S stDirIdOSDPara;    // 方向编号参数
    PU_CUSTOM_OSD_PARA_EX_S stDirOSDPara;      // 方向OSD参数
    PU_CUSTOM_OSD_PARA_EX_S stCustomOSDPara;   // 自定义OSD参数
    PU_CUSTOM_OSD_PARA_EX_S stLocateDescOSDPara;   // 路口位置描述参数
    PU_CUSTOM_OSD_PARA_EX_S stMonitorInfoOSDPara;  // 监测点位置描述参数
    PU_CUSTOM_OSD_PARA_EX_S stLaneDescOSDPara;     // 车道描述
    PU_CUSTOM_OSD_PARA_EX_S stLaneDirDescOSDPara;  // 车道方向描述
    BOOL  bDirOSDParaEn;      //行驶方向参数使能，1:表示ITS，不采用方向OSD参数 0:其他，采用方向OSD参数
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_PIC_OSD_PARA_V3_S;

//人脸OSD叠加类型
typedef enum PU_FACE_OSD_TYPE
{
    FACE_TIME_OSD = 0,       //时间叠加
    FACE_DEV_ID_OSD,         //设备编号
    FACE_MONITOR_INFO_OSD,  //监测点信息
    FACE_OSD_TYPE_MAX
}PU_FACE_OSD_TYPE_E;

//人脸OSD信息
typedef struct PU_FACE_OSD_INFO
{
    ULONG uPicOSDNum;                                // 需叠加的OSD数目
    PU_FACE_OSD_TYPE_E aenPicOSDType[FACE_OSD_TYPE_MAX]; // 叠加的类型
    PU_PIC_OSD_LOCATION_E enPicOSDLocation;            // OSD叠加位置
    PU_FONT_SIZE_E enFontSize;                         // 字体大小
    PU_FONT_SIZE_EXT_E enFontSizeExt;                  //扩展OSD字体大小，新增枚举，暂不支持
    ULONG ulFgColor;                                   // 前景(文字)色彩格式0xRRGGBB或换算成十进制
    UCHAR ucFgAlpha;                                   // 前景（文字）透明度 范围0~128，暂不支持
    ULONG ulBgColor;                                   // 背景色彩 格式0xRRGGBB 或换算成十进制
    UCHAR ucBgAlpha;                                   // 背景透明度 范围0~128(海思)，暂不支持
} PU_FACE_OSD_INFO_S;

//人脸OSD叠加参数
typedef struct PU_FACE_OSD_PARA
{
    ULONG ulChannelId;                       // 通道ID
    //BOOL bEnablePicOSD;                     // 是否开启图片OSD叠加 
    BOOL   bEnableLiveOSD;                    // 是否开启实况OSD叠加
    PU_OVERLAY_PIC_TYPE_E enOverlayPicType;   // 叠加OSD的图片类型
    PU_FACE_OSD_INFO_S stPicOSDInfo;              // 图片叠加信息
    PU_TIME_OSD_PARA_S stTimeOSDPara;            // 时间OSD参数
    PU_CUSTOM_OSD_PARA_EX_S stDevIdOSDPara;         // 设备编号参数
    PU_CUSTOM_OSD_PARA_EX_S stMonitorInfoOSDPara;   // 监测点位置描述参数       
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_FACE_OSD_PARA_S;


//云台各档位PT速度
typedef struct PU_PTZ_GEAR_SPEED
{
    INT nGear;                              // 档位
    INT nPanSpeed;                          // 水平速度
    INT nTiltSpeed;                         // 垂直速度
}PU_PTZ_GEAR_SPEED_S;

//云台速度
typedef struct PU_PTZ_GEARS_SPEED
{
    PU_PTZ_GEAR_SPEED_S stPtzGearSpeed[PU_PTZ_GEAR_NUM_MAX];
}PU_PTZ_SPEED_S;

//告警录像信息
typedef struct PU_ALARM_REC_INFO
{
    PU_ALARM_REPORT_S stAlarmReport;        // 录像对应告警信息
    PU_TIME_S stBeginTime;                  // 录像起始时间(UTC时间)
    PU_TIME_S stEndTime;                    // 录像结束时间(UTC时间)
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ALARM_REC_INFO_S;

//告警录像查询参数
typedef struct PU_ALARM_REC_INQ_REQ
{
    ULONG ulChnID;                          // 通道号
    PU_ALARM_TYPE_E enAlarmType;            // 告警类型 0表示所有告警
    PU_TIME_S stBeginTime;                  // 起始时间(UTC时间)
    PU_TIME_S stEndTime;                    // 终止时间(UTC时间)
    ULONG ulBeginIndex;                     // 起始索引(从1开始)
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ALARM_REC_INQ_REQ_S;

//告警录像查询响应参数
typedef struct PU_ALARM_REC_INQ_RSP
{
    ULONG ulTotalNum;                       // 告警录像总数
    ULONG ulBeginIndex;                     // 起始索引
    ULONG ulEndIndex;                       // 结束索引
    PU_ALARM_REC_INFO_S astAlarmRecInfoList[PU_RECORD_INFO_NUM_MAX];    //告警录像信息列表
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ALARM_REC_INQ_RSP_S;

//云台速度限制
typedef struct PU_PTZ_SPEED_LIMIT
{
    ULONG ulPanSpeedLimit;                  // 水平速度限制(单位:度/秒)
    ULONG ulTiltSpeedLimit;                 // 垂直速度限制(单位:度/秒)
}PU_PTZ_SPEED_LIMIT_S;

//云台速度能力
typedef struct PU_PTZ_SPEED_ABILITY
{
    ULONG ulPanSpeedMax;                    // 水平最大速度(单位:度/秒)
    ULONG ulTiltSpeedMax;                   // 垂直最大速度(单位:度/秒)
}PU_PTZ_SPEED_ABILITY;

//OSDI位置
typedef struct PU_OSDI_POSITION
{
    ULONG ulChnID;                          // 通道号
    ULONG ulOSDIIndex;                      // OSDI索引
    PU_POINT_S stOSDITopLeftPos;            // OSDI左上角坐标
}PU_OSDI_POSITION_S;

//自动ARP广播
typedef struct PU_AUTO_ARP_BROADCAST_PARA
{
    BOOL  bEnable;                          // 启用
    ULONG ulCycleDay;                       // 周期(单位:1~120天)
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_AUTO_ARP_BROADCAST_PARA_S;

//SSH使能
typedef struct PU_SSH_ENABLE_PARA
{
    BOOL bEnable;                         // 启用
}PU_SSH_ENABLE_PARA_S;

//SFTP使能
typedef struct PU_SFTP_ENABLE_PARA
{
    BOOL bEnable;                         // 启用
}PU_SFTP_ENABLE_PARA_S;

/*** ONVIF媒体保活时间 ***/
typedef struct ONVIF_RTSP_SESSION_TIMEOUT
{
    ULONG ulChannelId;
	PU_STREAM_TYPE_E enStreamId;       //主码流、子码流1、子码流2
	ULONG ulTimeOut;
}PU_ONVIF_RTSP_SESSION_TIMEOUT_PARA_S;

//告警联动ptz运动的优先级
typedef struct PU_ALARM_LINK_PRIORITY_PARA
{
    ULONG                       ulChannelId;     //通道号
    PU_ALARM_LINK_PTZ_PRIORITY_E  enAlarmPriority; //优先级
    CHAR                        szReserved[PU_RESERVE_LEN];
}PU_ALARM_LINK_PRIORITY_PARA_S,*LPPU_ALARM_LINK_PRIORITY_PARA_S;

/****停车侦测消息结构体****/
typedef struct PU_CARDETECT_PARAM
{
    ULONG                 ulChannelId;   //通道ID
    BOOL                  bEnable;       //算法使能
    ULONG                 ulSensitivity; //算法检测灵敏度
    ULONG                 ulAlarmTime;   //告警上报间隔
    ULONG                 ulParkTimeThr; //停车阈值
    PU_IGT_AERADTC_LIST_S stAreaList;    //停车侦测检测区域
    PU_ALARM_TIME_LIST_S  stAlarmTimeList;   //停车侦测布防计划
    CHAR                  szReserved[PU_RESERVE_LEN];
}PU_CARDETECT_PARAM_S,*LPPU_CARDETECT_PARAM_S;


/****行为分析智能跟踪****/
typedef struct PU_VA_LINK_AT
{
    ULONG           ulChannelId;    //通道号
    BOOL            bEnable;        //算法使能
    PU_ALARM_TYPE_E enAlarmType;    //需要联动自动跟踪的告警
    CHAR            szReserved[PU_RESERVE_LEN];
}PU_VA_LINK_AT_S,*LPPU_VA_LINK_AT_S;

/****自动跟踪消息结构体****/
typedef struct PU_VW_ITGT_AUTOTRACKING_PARAM
{
    ULONG                 ulChannelId;    //通道ID
    BOOL                  bEnable;        //算法使能
    ULONG                 ulSensitivity;  //算法检测灵敏度
    ULONG                 ulAlarmTime;    //告警上报间隔
    ULONG                 ulMaxTraceTime; //最大跟踪时间
    PU_ALARM_TIME_LIST_S  stAlarmTimeList;//场景变更布防计划
    PU_IGT_AERADTC_LIST_S szAreaList;                        //划线区域
    CHAR                  szReserved[PU_RESERVE_LEN];
}PU_VW_ITGT_AUTOTRACKING_PARAM_S,*LPPU_VW_ITGT_AUTOTRACKING_PARAM_S;

/****自动跟踪手动跟踪目标****/
typedef struct PU_VW_ITGT_AT_MANUAL_TARGET
{
    ULONG   ulX;
    ULONG   ulY;
    ULONG   ulWidth;
    ULONG   ulHeight;
}PU_VW_ITGT_AT_MANUAL_TARGET_S,*LPPU_VW_ITGT_AT_MANUAL_TARGET_S;

// 线段结构体
typedef struct PU_HC_LINE
{
    PU_POINT_S stPtS; // 线段起始端点
    PU_POINT_S stPtE; //线段截止端点
}PU_HC_LINE_S;

// 矩形结构体
typedef struct PU_HC_RECT
{
    USHORT startX;  
    USHORT startY;
    USHORT width;
    USHORT height;
} PU_HC_RECT_S;

/******************过线计数算法参数结构体********************************/
typedef struct PU_HUMANCOUNT_ALG_PARAM
{
    BOOL            enHCEnable;         //过线计数算法使能
    BOOL            enOSDEnable;        // OSD叠加使能
    BOOL            enClearAtZero;      // 零点清零使能
    PU_POINT_S      stOSDLocation;      // OSD叠加位置
    ULONG           ulSensitivity;      // 算法检测灵敏度
    ULONG           ulAlarmTime;        // 告警上报间隔
    ULONG           ulAlarmHumanNum;    // 告警人数（超过此值触发告警）
    ULONG           ulMinHeadSize;      // 人头最小尺寸
    PU_HC_LINE_S    stRefLine;          // 进出参考线，推荐配置在画面中央, 线段接近水平或垂直
    PU_TRIPWIRE_DIR_E  enInDir;         // 进入方向(若顺时针越线为进,若逆时针越线为出)
    CHAR szReserved[PU_RESERVE_LEN];
}PU_HUMANCOUNT_ALG_PARAM_S;

/******************过线计数消息结构体************************************/
typedef struct PU_HUMANCOUNT_PARAM
{
    ULONG                          ulChannelId;    // 通道ID
    PU_HUMANCOUNT_ALG_PARAM_S      stAlgParams;    // 过线计数算法参数
    PU_IGT_AERADTC_LIST_S          stGuardAreaList;//过线计数检测区域
    PU_ALARM_TIME_LIST_S           stHCGuardPlan;  // 过线计数布防计划
    CHAR szReserved[PU_RESERVE_LEN];
}PU_HUMANCOUNT_PARAM_S;

typedef struct PU_HUMANCOUT_RECORD
{
    ULONG ulStartTime;      //查询起始时间
    ULONG ulEndTime;        //查询结束时间
    ULONG HumanNum;         //过线人数
    CHAR szReserved[PU_RESERVE_LEN];
}PU_HUMANCOUT_RECORD;

/******************过线计数报表结构体************************************/
typedef struct PU_HUMANCOUNT_TABLE
{
    ULONG               ulChannelId;                    // 通道ID
    PU_TABLE_TYPE_E     enTableType;                    // 报告类型
    PU_TRIPWIRE_DIR_E   enInDir;                        // 进入方向(若顺时针越线为进,若逆时针越线为出)
    ULONG               ulRecordNum;                    // 查询记录的条数
    PU_HUMANCOUT_RECORD astTable[PU_HUMANCOUNT_TABLE_LEN_MAX];  // 各时间段过线人数表
    CHAR szReserved[PU_RESERVE_LEN];
}PU_HUMANCOUNT_TABLE_S;

/*************智能新增3559人脸属性*************/
typedef struct PU_ATTRI_DL_PARAMETER
{
    ULONG    ulChannelId;          //通道ID
    BOOL     enEnableAttri;        //属性分析使能
//    BOOL     enEnableFaceAttri;    // 人脸属性分析使能
//    BOOL     enEnableBodyAttri;    // 人体属性分析使能    
    CHAR     szReserved[PU_RESERVE_LEN];
}PU_ATTRI_DL_PARAMETER_S;

/*************球机自检*************/
typedef struct PU_PTZ_CHECK_PARA
{
    BOOL    enEnable;
    ULONG   ulInterval; //自检间隔
    CHAR    szReserved[PU_RESERVE_LEN];
}PU_PTZ_CHECK_PARA_S;

/*************手动除雾***************/
typedef struct PU_MANAUL_DEFOG_ENABLE
{
     BOOL bEnable;    
     CHAR szReserved[PU_RESERVE_LEN];
}PU_MANAUL_DEFOG_ENABLE_S;
// 曝光灯参数
typedef struct ITS_EXPOSURE_LAMP_ATTR
{
    PU_EXT_LAMP_WORK_MODE_E enExtLampWorkMode;    // 外置灯工作模式
    ULONG ulPulseWidth;                        // 脉宽
    ULONG ulDelayTime;                         // 延后时间，用于调节同步
    PU_EXP_LAMP_TRIG_LEVEL_E enExpLampTrigLevel;  // 爆闪灯触发电平
    ULONG ulLightThreshold;                 // 亮度阈值，自动模式时生效
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EXPOSURE_LAMP_ATTR_S;

// 频闪灯参数
typedef struct PU_STROBE_LAMP_ATTR
{
    PU_EXT_LAMP_WORK_MODE_E enExtLampWorkMode;    // 外置灯工作模式
    ULONG ulPulseWidth;                        // 脉宽
    ULONG ulDelayTime;                         // 延后时间，用于调节同步
    PU_EXT_LAMP_FREQ_E enFrequency;      // 频闪灯频率
    ULONG ulLightThreshold;                 // 亮度阈值，自动模式时生效 
    CHAR szReserved[PU_RESERVE_LEN];
}PU_STROBE_LAMP_ATTR_S;

// 外置灯参数
typedef struct PU_EXT_LAMP_ATTR
{
    PU_EXT_LAMP_TYPE_E 		enExtLampType;    // 外置灯类型
    PU_EXPOSURE_LAMP_ATTR_S 	stExposureLampAttr;    // 曝光灯属性
    PU_STROBE_LAMP_ATTR_S 	stStrobeLampAttr;    // 频闪灯属性
    CHAR szReserved[PU_RESERVE_LEN];
}PU_EXT_LAMP_ATTR_S;

// 补光灯参数
typedef struct PU_SUPPLEMENT_LAMP_ATTR
{
	ULONG               ulChannelId;                    // 通道ID
    PU_STROBE_LAMP_ATTR_S 	stStrobeLampAttr[PU_MAX_INNER_LAMP_NUM]; // 内置频闪灯属性
    PU_EXT_LAMP_ATTR_S 	stExtLampAttr[PU_MAX_EXT_LAMP_NUM]; // 外置灯属性
    CHAR szReserved[PU_RESERVE_LEN];
}PU_SUPPLEMENT_LAMP_ATTR_S;

//AE曝光模式
typedef struct PU_CAM_AE_MODE
{
    PU_AE_MODE_E enAEMode;                  //AE曝光模式
}PU_CAM_AE_MODE_S;

/* AE响应时间 */
typedef struct PU_CAM_AE_RESPONSE_TIME
{
    LONG lAEResponseTime;
}PU_CAM_AE_RESPONSE_TIME_S;

/*GAMMA参数*/
typedef struct PU_GAMMA
{
    PU_COMMONMODE_SWITCH_E enGammaMode;
    ULONG ulStrength;
}PU_GAMMA_S;

/* 背景频率 */
typedef struct PU_FLICKER_MODE
{
    PU_VIDEO_FLICKER_MODE_E enFlicker;          //背景频率
}PU_FLICKER_MODE_S;

//镜头类型参数
typedef struct PU_CAM_LENS_TYPE
{
    PU_LENS_TYPE_E enLensType;
}PU_CAM_LENS_TYPE_S;

//增益最大值参数
typedef struct PU_AUTOGAIN_MAXVALUE
{
    LONG lMaxAutoGain;                       //自动增益最大值
}PU_AUTOGAIN_MAXVALUE_S;

//降噪参数
typedef struct PU_DENOISE_PARA
{
    PU_DENOISE_MODE_E enDenoiseMode;           //模式开关
    LONG lNRLevel;                              //范围，索尼1~5 日立1~3
    ULONG ulTfcLevel;                           //时域降噪
    ULONG ulSfcLevel;                           //空域降噪
}PU_DENOISE_PARA_S;


//最小聚焦距离参数
typedef struct PU_MIN_FOCUS_VALUE
{
    PU_MIN_FOCUS_E enMinFocus;                   //最小聚焦距离
}PU_MIN_FOCUS_VALUE_S;

/* 抓拍详细参数、多算法并行多个模式ISP参数 */
typedef struct PU_SNAPSHOT_PARTICULAR_PARA
{
    ULONG ulChannelID;                                          //通道号
    ULONG ulBitMap;                                             //修改位 （低位从AE曝光模式开始）
    PU_CAM_AE_MODE_S stCamAEMode;                               //AE曝光模式1
    PU_CAM_AE_RESPONSE_TIME_S stCamAEResponseTime;              //AE响应时间2(V2R2设备此参数无效)
    PU_EXPCOMP_PARA_S stCamExpcompPara;                     //曝光补偿3
    PU_WB_MANUAL_PARA_S stCamWBManualPara;                  //白平衡4
    PU_WD_PARA_S stCamWDPara;                               //宽动态5
    PU_BLACKWHITE_MODE_S stCamBlackWhiteMode;               //昼夜模式6
    PU_SLOW_SHUTTER_MODE_S stSlowShutterMode;               //慢快门开关7
    PU_GAMMA_S stImageGammaCtrl;                                        //GAMMA参数8
    PU_FLICKER_MODE_S stCamFlickerMode;                     //背景频率9
    PU_AEMETERING_MODE_S stCamAEMeterMode;                  //AE测光模式10
    PU_SHUTTER_VALUE_S stCamshutterValue;                   //快门范围及其值11
    PU_BACKLIGHT_MODE_S stCamBackLightMode;                 //背光补偿模式12
    PU_IRC_PARA_S stCamIRCPara;                             //日夜模式开关及阙值(阈值为昼夜灵敏度)13
    PU_CAM_LENS_TYPE_S stCamLensType;                           //镜头类型14
    PU_AUTOGAIN_MAXVALUE_S stAutoGainMaxValue;                  //自动增益最大值15
    PU_GAIN_CONTROL_S stCamGainControl;                     //机芯增益控制16
    PU_DENOISE_PARA_S stCamDenoisePara;                     //降噪模式17
    PU_STABILIZER_PARA_S stCamStabilizerPara;               //机芯防抖模式18
    PU_IRIS_CONTROL_S stCamIrisControl;                     //控制机芯光圈19
    PU_DEFOG_PARA_S stISPDefogPara;                         //去雾效果20
    PU_ROI_METER_MODE_S stCamRoiMeterMode;                  //微卡口感兴趣区域测光21
    PU_IMG_DRC_S stImgDRCPara;					            //TI枪机，DRC参数25
    PU_MIN_FOCUS_VALUE_S stMinFocusValue;                       //最小聚焦距离值26
    PU_ISP_CAM_HLC_S stHlc;                                     //强光抑制27
    PU_IRIS_TYPE_E enIrisType;                              //Iris类型28
    PU_CAM_SHUTTER_MODE_E enShutterValueLimit;                     //快门限制29
    PU_ISP_SCENE_TYPE_E enSceneType;                            //ISP场景模式30
}PU_SNAPSHOT_PARTICULAR_PARA_S;

// ISP详细参数类型
typedef enum PU_ISP_PARTICULAR_PARA_TYPE
{
    PU_ISP_HUMAN,            // 多算法并行设备单模式人卡、行为分析ISP参数
    PU_ISP_HUMAN_DEFAULT,    // 多算法并行设备单模式人卡、行为分析ISP默认参数，只支持获取
    PU_ISP_VEHICLE,          // 多算法并行设备单模式微卡ISP参数
    PU_ISP_VEHICLE_DEFAULT,   // 多算法并行设备单模式微卡ISP默认参数，只支持获取
    PU_ISP_NORMAL   // 普通ISP 参数
}PU_ISP_PARTICULAR_PARA_TYPE_E;

//ISP详细参数扩展
typedef struct PU_ISP_PARTICULAR_PARA_EX
{
    PU_ISP_PARTICULAR_PARA_TYPE_E enISPParamType;  //操作的ISP参数类型
    PU_SNAPSHOT_PARTICULAR_PARA_S stISPParam;      //ISP参数
}PU_ISP_PARTICULAR_PARA_EX_S;

/*************BEGIN:微卡口FTP/SFTP上传参数***************/
/*************分隔符类型***************/
typedef enum PU_SEPARATOR_TYPE
{
    PU_SEPARATOR_TYPE_DOT = 0,   // '.'
    PU_SEPARATOR_TYPE_PLUS,      // '+'
    PU_SEPARATOR_TYPE_MINUS,     // '-'
    PU_SEPARATOR_TYPE_UNDERLINE, // '_'
    PU_SEPARATOR_TYPE_EQUAL,     // '='
    PU_SEPARATOR_TYPE_MAX
}PU_SEPARATOR_TYPE_E;

/*************图片命令类型***************/
typedef enum PU_PIC_NAMING_TYPE
{
	//机非人_机动车
	PU_PIC_NAMING_TYPE_NO = 0,
	PU_PIC_NAMING_TYPE_DEV_IP,
	PU_PIC_NAMING_TYPE_DEV_ID,
	PU_PIC_NAMING_TYPE_TIME,
	PU_PIC_NAMING_TYPE_PLATE_ID,
	PU_PIC_NAMING_TYPE_PLATE_COLOR,
	PU_PIC_NAMING_TYPE_LANE_ID,
	PU_PIC_NAMING_TYPE_VEHICLE_TYPE,
	PU_PIC_NAMING_TYPE_VEHICLE_COLOR,
	PU_PIC_NAMING_TYPE_ROAD_ID,
	PU_PIC_NAMING_TYPE_DIR_ID,
	PU_PIC_NAMING_TYPE_DIR,
	PU_PIC_NAMING_TYPE_CUSTOM,
	PU_PIC_NAMING_TYPE_PLATE_TYPE,
	PU_PIC_NAMING_TYPE_VEHICLE_BRAND,
	PU_PIC_NAMING_TYPE_SUB_BRAND,
	PU_PIC_NAMING_TYPE_YEAR,       //年款
	PU_PIC_NAMING_TYPE_OBJ_ID,   //车追踪ID
	PU_PIC_NAMING_TYPE_VEHICLE_SIZE,//车辆大小
	PU_PIC_NAMING_TYPE_REGULATION_NUM,//违章编号
	PU_PIC_NAMING_TYPE_PIC_NUM,//图片编号
	PU_PIC_NAMING_TYPE_VEHICLE_DIRECTION,
	PU_PIC_NAMING_TYPE_VEHICLE_SPEED,//车辆速度
	PU_PIC_NAMING_TYPE_VERSION,//平台版本号，针对东软平台增加此项功能
	PU_PIC_NAMING_TYPE_VEHICLE_RECT,//车辆位置
	PU_PIC_NAMING_TYPE_PLATE_RECT,//车牌位置
	PU_PIC_NAMING_TYPE_VEHICLE_BRAND_ID,//车辆主品牌ID
	PU_PIC_NAMING_TYPE_SUB_BRAND_ID,//车辆子品牌ID
	//人脸人体
	PU_PIC_NAMING_TYPE_GENDER = 50,//性别
	PU_PIC_NAMING_TYPE_AGE, //年龄
	PU_PIC_NAMING_TYPE_EXPRESSION, //表情
	PU_PIC_NAMING_TYPE_GLASESS, //眼镜
	PU_PIC_NAMING_TYPE_MOUTHMASK, //口罩
	PU_PIC_NAMING_TYPE_AGEGROUP, //年龄段
	PU_PIC_NAMING_TYPE_SHAPE,//体型
	PU_PIC_NAMING_TYPE_HAIR,//发型
	PU_PIC_NAMING_TYPE_UMBRELLA,//雨伞
	PU_PIC_NAMING_TYPE_BACKPACK,//背包
	PU_PIC_NAMING_TYPE_FRONTPACK,//前面背包
	PU_PIC_NAMING_TYPE_SATCHEL,//挎包
	PU_PIC_NAMING_TYPE_LUGGAGE,//行李
	PU_PIC_NAMING_TYPE_CARRY,//手拎物
	PU_PIC_NAMING_TYPE_MOVESPEED,//行进速度
	PU_PIC_NAMING_TYPE_MOVEDIRECT,//行进方向
	PU_PIC_NAMING_TYPE_UPPERTEXTURE, //上衣纹理
	PU_PIC_NAMING_TYPE_UPPERSTYLE,//上衣款型
	PU_PIC_NAMING_TYPE_UPPERCOLOR,//上衣颜色
	PU_PIC_NAMING_TYPE_LOWERSTYLE,//下衣款型
	PU_PIC_NAMING_TYPE_LOWERCOLOR,//下衣颜色
	PU_PIC_NAMING_TYPE_HUMANDEV_IP,// 人设备ip
	PU_PIC_NAMING_TYPE_HUMANTIME, //人时间
	PU_PIC_NAMING_TYPE_HUMANOBJ_ID,//人追踪ID
	PU_PIC_NAMING_TYPE_HUMANCUSTOM, //人自定义
	// 机非人_骑行人
	PU_PIC_NAMING_TYPE_RIDERMAN_GENDER = 80,//骑行人性别
	PU_PIC_NAMING_TYPE_RIDERMAN_AGE,//骑行人年龄
	PU_PIC_NAMING_TYPE_RIDERMAN_UPPERSTYLE, //骑行人上衣款式
	PU_PIC_NAMING_TYPE_RIDERMAN_UPPERCOLOR,//骑行人上衣颜色
	PU_PIC_NAMING_TYPE_RIDERMAN_HELMET,    // 头盔
	PU_PIC_NAMING_TYPE_RIDERMAN_HELMETCOLOR, // 头盔颜色
	PU_PIC_NAMING_TYPE_RIDERMAN_OBJID,// 骑行人追踪ID
	PU_PIC_NAMING_TYPE_RIDERMAN_IP,// 骑行人设备ip
	PU_PIC_NAMING_TYPE_RIDERMAN_TIME, //骑行人时间
	PU_PIC_NAMING_TYPE_RIDERMAN_CUSTOM,//骑行人自定义
	PU_PIC_NAMING_TYPE_MAX
}PU_PIC_NAMING_TYPE_E;

// FTP方式，微卡口和机非人不同
typedef enum PU_FTP_TYPE
{
    PU_VHD_FTP,    //机非人
    PU_BAYONET_FTP,//微卡口
    PU_ITS_FTP,    //智能交通
	PU_COMMON_FTP, //其他
	PU_IBALL_FTP,  //违停球
	PU_EAST_SOFT_FTP, //东软
	PU_HUMANFACE_FTP, //人脸
	PU_VEHFACEMIX_FTP,//混行
    PU_FTP_TYPE_MAX
} PU_FTP_TYPE_E;

//图片参数
typedef struct PU_PIC_NAMING_ELEM
{
    PU_PIC_NAMING_TYPE_E enPicNamingType;            // 命名类型
    CHAR acCustomContent[PU_MAX_CUSTOM_CONTENT_LEN]; // 自定义内容
    CHAR szReserved[PU_RESERVE_LEN];          //预留字段
} PU_PIC_NAMING_ELEM_S;

typedef struct PU_PIC_NAMING_PARA
{
    PU_SEPARATOR_TYPE_E  enSeparatorType; // 分隔符类型
    PU_PIC_NAMING_ELEM_S astPicNamingElem[PU_MAX_PIC_NAMING_ELEM];
    CHAR szReserved[PU_RESERVE_LEN];          //预留字段
} PU_PIC_NAMING_PARA_S;

typedef struct PU_PIC_NAMING_PARA_EX
{
	PU_SEPARATOR_TYPE_E  enSeparatorType; // 分隔符类型
	PU_PIC_NAMING_ELEM_S astPicNamingElem[PU_MAX_PIC_NAMING_ELEM_EX];
	CHAR szReserved[PU_RESERVE_LEN];          //预留字段
} PU_PIC_NAMING_PARA_EX_S;

typedef enum PU_VLPR_FTP_DIR_NAMING_TYPE_E
{
    VLPR_FTP_DIR_NAMING_TYPE_DEV_IP = 0, // 设备IP
    VLPR_FTP_DIR_NAMING_TYPE_DEV_ID,     // 设备ID
    VLPR_FTP_DIR_NAMING_TYPE_TIME_YM,    // 时间(年月)
    VLPR_FTP_DIR_NAMING_TYPE_TIME_YMD,   // 时间(年月日)
    VLPR_FTP_DIR_NAMING_TYPE_DIR,        // 方向
    VLPR_FTP_DIR_NAMING_TYPE_LANE_ID,    // 车道号
    VLPR_FTP_DIR_NAMING_TYPE_CUSTOM,     // 自定义
    VLPR_FTP_DIR_NAMING_TYPE_CHANNEL,	 // 通道号
    VLPR_FTP_DIR_NAMING_TYPE_REGULATION, // 违章类型
} PU_VLPR_FTP_DIR_NAMING_TYPE_E;

typedef struct PU_VLPR_FTP_DIR_NAMING_ELEM_S 
{
    PU_VLPR_FTP_DIR_NAMING_TYPE_E enFtpDirNamingType;
    CHAR acCustomContent[PU_MAX_CUSTOM_CONTENT_LEN]; // 自定义内容
    CHAR szReserved[PU_RESERVE_LEN];          //预留字段
} PU_VLPR_FTP_DIR_NAMING_ELEM_S;

typedef struct PU_VLPR_FTP_DIR_PARA_S 
{
    PU_FTP_UPLOAD_DIR_TYPE_E      enDirType;
    PU_VLPR_FTP_DIR_NAMING_ELEM_S astDirNamingElem[PU_MAX_DIR_NAMING_ELEM];    
    CHAR szReserved[PU_RESERVE_LEN];          //预留字段
} PU_VLPR_FTP_DIR_PARA_S;

/*************微卡口FTP上传参数**************/
typedef struct PU_VLPR_FTP_UPLOAD_PARA
{
    BOOL bSnapPicEnable;                      // 使能
    BOOL bSendPlatePic;                       // 是否发送车牌小图
    PU_FTP_UPLOAD_PROTOCOL_TYPE_E enProtocol; // 上传协议
    CHAR szServerIP[PU_IP4_ADDR_LEN];         // 服务器IP地址
    ULONG ulServerPort;                       // 服务器端口
    CHAR szUserName[PU_CLIENT_USERNAME_LEN];  //用户名
    PU_VLPR_FTP_DIR_PARA_S stDirNameingPara;  // 目录命名参数
    PU_PIC_NAMING_PARA_S stPicNamingPara;     // 图片命名参数
    PU_FTP_TYPE_E        eFtpType;   
	BOOL bSendFacePic;                       // 是否发送人脸小图
    CHAR szReserved[PU_RESERVE_LEN - sizeof(BOOL)];          //预留字段
    CHAR szUserPwd[PU_PASSWORD_LEN];          //Pwd
} PU_VLPR_FTP_UPLOAD_PARA_S;

typedef struct PU_VLPR_FTP_UPLOAD_PARA_V2
{
	BOOL bSnapPicEnable;                      // 使能
	BOOL bSendPlatePic;                       // 是否发送车牌小图
	PU_FTP_UPLOAD_PROTOCOL_TYPE_E enProtocol; // 上传协议
	CHAR szServerIP[PU_IP4_ADDR_LEN];         // 服务器IP地址
	ULONG ulServerPort;                       // 服务器端口
	CHAR szUserName[PU_CLIENT_USERNAME_LEN];  //用户名
	PU_VLPR_FTP_DIR_PARA_S stDirNameingPara;  // 目录命名参数
	PU_PIC_NAMING_PARA_EX_S stPicNamingPara;     // 图片命名参数
	PU_FTP_TYPE_E        eFtpType;   
	BOOL bSendFacePic;                       // 是否发送人脸小图
	CHAR szReserved[PU_RESERVE_LEN - sizeof(BOOL)];          //预留字段
	CHAR szUserPwd[PU_PASSWORD_LEN];          //Pwd
} PU_VLPR_FTP_UPLOAD_PARA_V2_S;

/*************END:微卡口FTP/SFTP上传参数***************/

//密码超期告警
typedef struct PU_ALARM_REPORT_PWD_EXP_ALARM
{
    CHAR szUsrName[PU_USER_NAME_LEN];
}PU_ALARM_REPORT_PWD_EXP_ALARM_S;

//ITS手动抓拍参数
typedef struct PU_ITS_MANUAL_SNAPSHOT_PARA
{
    ULONG ulSnapNum;    //抓拍张数,最大值MAX_BURST_SHOOTING_NUM  (目前只支持1,其他值无效)
    ULONG aulSnapInterval[MAX_BURST_SHOOTING_NUM - 1];  //抓拍间隔(ms) 范围[MIN_ITS_SNAPSHOT_INTERVAL, MAX_ITS_SNAPSHOT_INTERVAL]
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_ITS_MANUAL_SNAPSHOT_PARA_S;

/* 通道下的透雾自适应 */
typedef struct PU_VW_FOG_ADAPT_PARA
{
    ULONG ulChannelID;                                      //通道号
    BOOL  enFogAdaptEnable;                         //透雾自适应是否使能
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_VW_FOG_ADAPT_PARA_S;

/* 通道下的拖影(速度)自适应 */
typedef struct PU_VW_SPEED_ADAPT_PARA
{
    ULONG ulChannelID;                                      //通道号
    BOOL  enSpeedAdaptEnable;                         //拖影(速度)自适应是否使能
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_VW_SPEED_ADAPT_PARA_S;

/* 通道下的背光自适应 */
typedef struct PU_VW_BACKLIGHT_ADAPT_PARA
{
    ULONG ulChannelID;                                    //通道号
    BOOL  enBackLightAdaptEnable;                         //背光自适应是否使能    
    BACKLIGHT_MODE_E enBackLightMode;                     //背光区域类型
    PU_AREA_INFO_S stBackLightAdaptStart;                 //背光自适应区域信息
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_VW_BACKLIGHT_ADAPT_PARA_S;

typedef enum PU_ALARM_LEVEL
{
    PU_ALARM_LEVEL_INFO,      // 提示
    PU_ALARM_LEVEL_GENERAL,   //一般
    PU_ALARM_LEVEL_CRITICAL,  //严重
    PU_ALARM_LEVEL_FATAL,     //致命
    PU_ALARM_LEVEL_MAX 
} PU_ALARM_LEVEL_E;

//告警上报信息结构
typedef struct PU_DEV_ALARM_INFO_REPORT      
{  
    ULONG ulIdentifyID;                  //设备登入ID
    ULONG ulAlarmModID;                  //告警模块ID
    BOOL IsIntact;                       //是否完好, 1:完好；0:不完好
    PU_ALARM_LEVEL_E enAlarmLevel;       //告警级别
    PU_ALARM_TYPE_E enAlarmType;         //告警类型
    PU_TIME_S stTime;                    //告警发生/消除时间UTC 时间
    PU_ALARM_ACTION_E enAction;          //告警发生/消除
    ULONG ulAlarmId;                     //告警序列号
    CHAR szAlarmDesc[64];                //告警描述
    CHAR szAlarmCleanDesc[64];           //告警清除描述
    CHAR szReserve[PU_RESERVE_LEN];
}PU_DEV_ALARM_INFO_REPORT_S, *LPPU_DEV_ALARM_INFO_REPORT_S;

//设备配置参数枚举类型
typedef enum PU_DEV_CONFIG_TYPE
{
    PU_DEV_CONFIG_TYPE_IP_FILTER,              //IP 过滤
    PU_DEV_CONFIG_TYPE_DEV_PORT,               //设备端口
    PU_DEV_CONFIG_TYPE_TCP_ACCELERATE,         //网络智能加速
    PU_DEV_CONFIG_TYPE_DDNS,                   //DDNS
    PU_DEV_CONFIG_TYPE_802DOT1x,               //802.1x
    PU_DEV_CONFIG_TYPE_SSH,                    //SSH
    PU_DEV_CONFIG_TYPE_SFTP,                   //SFTP
    PU_DEV_CONFIG_TYPE_SNMP_COMMUNITY,         // SNMPv1v2c社团列表
    PU_DEV_CONFIG_TYPE_SNMPV3_USER_MANAGE,     // SNMP v3用户管理
    PU_DEV_CONFIG_TYPE_SNMPV3_USER,            // SNMP v3用户列表
    PU_DEV_CONFIG_TYPE_SNMPV3_TRAP,            //SNMP Trap接收方列表
    PU_DEV_CONFIG_TYPE_MAX
} PU_DEV_CONFIG_TYPE_E;

//设备配置信息
typedef union PU_DEV_CONFIG_PARA
{
    PU_IPFILTER_RULES_INFOV2_S  stIPFilterPara;     //IP 过滤
    PU_TCP_ACCELERATE_PARA_S  stTcpAcceleratePara;  //网络智能加速
    PU_DEVICE_PORT_CONFIG_S  stDevPortConfig;       //设备端口
    PU_DDNS_CONF_INFO_S stDDNSpara;                 //DDNS
    PU_DOT1X_CONFIG_INFO_S stDot1xInfo;             //802.1x
    PU_SSH_ENABLE_PARA_S stSshPara;                 //SSH 
    PU_SFTP_ENABLE_PARA_S stSftpPara;               //SFTP 
    PU_SNMP_COMMUNITY_LIST_S_EX stCommunityList;    // SNMPv1v2c社团列表
    PU_SNMPV3_USER_MGMT_S stUserMgmtInfo;           //SNMP v3用户管理信息
    PU_SNMPV3_USER_LIST_S stUserList;               //SNMP v3用户列表
    PU_SNMP_TRAP_LIST_S stTrapList;                 //SNMP Trap接收方列表
    CHAR szReserved[PU_RESERVE_LEN];
 }PU_DEV_CONFIG_PARA_U, *LPPU_DEV_CONFIG_PARA_U;

//设备配置信息用于get
typedef struct PU_DEV_CONFIG_INFO
{
    PU_IPFILTER_RULES_INFOV2_S  stIPFilterPara;     //IP 过滤
    PU_TCP_ACCELERATE_PARA_S  stTcpAcceleratePara;  //网络智能加速
    PU_DEVICE_PORT_CONFIG_S  stDevPortConfig;       //设备端口
    PU_DDNS_CONF_INFO_S stDDNSpara;                 //DDNS
    PU_DOT1X_CONFIG_INFO_S stDot1xInfo;             //802.1x
    PU_SSH_ENABLE_PARA_S stSshPara;                 //SSH 
    PU_SFTP_ENABLE_PARA_S stSftpPara;               //SFTP 
    PU_SNMP_COMMUNITY_LIST_S_EX stCommunityList;    // SNMPv1v2c社团列表
    PU_SNMPV3_USER_LIST_S stUserList;               //SNMP v3用户列表
    PU_SNMPV3_USER_MGMT_S stUserMgmtInfo;           // SNMPv3用户管理
    PU_SNMP_TRAP_LIST_S stTrapList;                 //SNMP Trap接收方列表 
    CHAR  szReserved[PU_RESERVE_LEN];
 }PU_DEV_CONFIG_INFO_S, *LPPU_DEV_CONFIG_INFO_S;

//设备视频分辨率参数
typedef struct PU_RESOLUTION_BASIC_PARA
{
    BOOL bdevIsHD;                       //是否高清
    PU_RESOLUTION_TYPE_E  enResolution;  //设备视频分辨率
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_RESOLUTION_BASIC_PARA_S, *PPU_RESOLUTION_BASIC_PARA_S;

//设备视频分辨率信息
typedef struct PU_RESOLUTION_INFO
{
    PU_RESOLUTION_BASIC_PARA_S astResolutionPara[PU_VIEDO_STREAM_TRIPLE];  //设备视频分辨率基本参数
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_RESOLUTION_INFO_S, *PPU_RESOLUTION_INFO_S;

typedef struct PU_DEVICE_INFO_EX
{
    PU_DEVICEINFO_S  stDeviceInfo;                       //设备基本信息
    PU_DEVICE_ETHERNET_PARA_S   stDeviceEthernetPara;    //网络参数
    PU_DEV_CONFIG_INFO_S stConfigPara;                   //设备配置信息
    PU_RESOLUTION_INFO_S stResolution;                   //设备视频分辨率信息
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DEVICEINFO_EX_S, *LPPU_DEVICEINFO_EX_S;

typedef struct PU_DEV_REALSTATUS_INFO
{
    LONG     lCurretTemp;                          //温度 
    PU_SYS_STATUS_INFO_S  stSysStatusInfo;         //CPU、内存
    PU_HARD_DISK_STATE_S  stDiskState;             // SDCard 磁盘状态
    PU_CAM_GEOG_POSITION_S  stCamGeogPostion;      // 地理位置
    CHAR  szReserved[PU_RESERVE_LEN];
}PU_DEV_REALSTATUS_INFO_S, *LPPU_DEV_REALSTATUS_INFO_S;

#define PU_OPERATE_3RD_APP_NAME_LEN 32          // 第三方APP 名称最大长度
#define PU_OPERATE_3RD_APP_PATH_LEN 64          // 第三方APP 文件路径长度
#define PU_OPERATE_3RD_APP_CMD_LEN  128         // 第三方APP 操作命令最大长度
#define PU_MANAGE_3RD_APP_NUM_MAX   1           // 第三方APP 信息最大个数
#define PU_MANAGE_3RD_APP_URL_MAX   64          // 第三方APP url 最大长度


typedef enum
{
	PU_STATUS_3RD_APP_UNKNOWN = 0,
	PU_STATUS_3RD_APP_STOP,
	PU_STATUS_3RD_APP_RUN,
	PU_STATUS_3RD_APP_MAX
}PU_VW_3RD_APP_STATUS;

typedef enum
{
	PU_ACTION_3RD_APP_START = 0,
	PU_ACTION_3RD_APP_STOP,
	PU_ACTION_3RD_APP_MAX
}PU_VW_3RD_APP_ACTION;

typedef struct PU_3RD_APP_BASIC_INFO
{
	CHAR szAppName[PU_OPERATE_3RD_APP_NAME_LEN];
	CHAR szVersion[PU_OPERATE_3RD_APP_NAME_LEN];
	CHAR szURL[PU_MANAGE_3RD_APP_URL_MAX];
	PU_VW_3RD_APP_STATUS enAppStatus;
	PU_VW_3RD_APP_ACTION enAction;
	CHAR szReserved[PU_RESERVE_LEN];       
}PU_3RD_APP_BASIC_INFO_S, *LPPU_3RD_APP_BASIC_INFO_S;


typedef struct PU_MANAGE_3RD_APP_INFO
{
	UINT uiValidCount;                                             //有效的算法App个数
	PU_3RD_APP_BASIC_INFO_S ast3RdAppInfo[PU_3RD_APP_MAX_NUM];     //三方算法App信息
	CHAR szReserved[PU_RESERVE_LEN]; 
}PU_MANAGE_3RD_APP_INFO_S, *LPPU_MANAGE_3RD_APP_INFO_S;


typedef enum
{
	PU_OPERATE_3RD_APP_START = 0,
	PU_OPERATE_3RD_APP_STOP,
	PU_OPERATE_3RD_APP_UNINSTALL,
	PU_OPERATE_3RD_APP_MAX
} PU_VW_OPERATE_3RD_APP_TYPE;

typedef struct PU_VW_OPERATE_3RD_APP
{
	PU_VW_OPERATE_3RD_APP_TYPE enOperateType;
	CHAR szAppName[PU_OPERATE_3RD_APP_NAME_LEN];
}PU_VW_OPERATE_3RD_APP_S,*LPPU_VW_OPERATE_3RD_APP_S;

typedef enum PU_LICENSE_TYPE
{
    PU_LICENSE_TYPE_IGTALTHM,   //智能算法license
    PU_LICENSE_TYPE_MAX
}PU_LICENSE_TYPE_E;

typedef struct PU_LICENSE_INFO
{
    PU_LICENSE_TYPE_E emLicenseType;     //算法license类型
    CHAR FileName[128];                  //Licnese文件路径 
    CHAR szReserve[PU_RESERVE_LEN];
}PU_LICENSE_INFO_S, *LPPU_LICENSE_INFO_S;

typedef enum PU_UPGRADE_ITGT_TYPE
{
    PU_UPGRADE_ITGT_TYPE_APP = 0,                              //APP包
    PU_UPGRADE_ITGT_TYPE_FACE_BODY_DETECT = 1,                 //人脸人体检测算法包  Face and body detection algorithms
    PU_UPGRADE_ITGT_TYPE_FACE_RECOGTION  = 2,                  //人脸识别算法包Facial recognition algorithms
    PU_UPGRADE_ITGT_TYPE_ILLEG_PARK_DETECT = 4,                //违停检测算法包Illegal parking detection algorithms
    PU_UPGRADE_ITGT_TYPE_OBJ_CLASSIFICATION = 8,               //机非人车牌检测算法包Object classification algorithms
    PU_UPGRADE_ITGT_TYPE_NON_CHINA_VEHICLE_RECOGTION = 16,     //海外车牌检测算法包Non-China vehicle recognition algorithms
    PU_UPGRADE_ITGT_TYPE_SCENE_ADAPTATION = 32,                //场景自适应算法包Scene adaptation algorithms
    PU_UPGRADE_ITGT_TYPE_QUEUE_LENTH_CROWD_COUNT,              //派对长度人群密度估计算法包The Queue of Party crowd  count algorithms
    PU_UPGRADE_ITGT_3RD_TYPE_APP = 64,                         //三方APP包
    PU_UPGRADE_LET_4G_MODEL,                                   //4G软件包
	PU_UPGRADE_DCHIP_TYPE_APP,                                 //D芯片升级包，设备要重启
	PU_UPGRADE_DCHIP_TYPE_ALG,                                 //D芯片算法包, 含多个，需全升且版本一致方生效
    PU_UPGRADE_EBI_TYPE_APP,                                   //BEI周界专用款型算法包
    PU_UPGRADE_TYPE_MAX  = 127                                 //升级包类型最大值
}PU_UPGRADE_ITGT_TYPE_E;

typedef struct PU_UPGRADE_ITGT_MODEL_PARA
{
    PU_UPGRADE_ITGT_TYPE_E enUpgradeItgtType;    //智能升级包类型
    CHAR szModelPath[PU_UPGRADE_FILE_LEN_MAX];   //智能升级包路径
    CHAR szReserve[PU_RESERVE_LEN];
}PU_UPGRADE_ITGT_MODEL_PARA_S, *LPPU_UPGRADE_ITGT_MODEL_PARA_S;

typedef struct PU_UPGRADE_ITGT_FILE_INFO
{
    PU_UPGRADE_ITGT_MODEL_PARA_S astItgtModelPara[PU_UPGRADE_FILE_NUM_MAX]; //智能算法升级包模型信息
    CHAR szReserve[PU_RESERVE_LEN];
}PU_UPGRADE_ITGT_FILE_INFO_S, *LPPU_UPGRADE_ITGT_FILE_INFO_S;

#define PU_SAVE_FILE_PATH_MAX      128           //保存文件的最大路径

//证书路径参数
typedef struct PU_CERT_FILE_PATH_PARA
{
    CHAR szCACertFilePath[PU_CERT_FILE_PATH_MAX];       //CA文件路径
    CHAR szKeyFilePath[PU_CERT_FILE_PATH_MAX];          //客户端端私钥路径
    CHAR szCertFilePath[PU_CERT_FILE_PATH_MAX];         //客户端端证书路径
	CHAR szKeyPasswd[PU_PASSWORD_LEN];                  //私钥密码
    CHAR szReserve[PU_RESERVE_LEN];
}PU_CERT_FILE_PATH_PARA_S;

//// 4G 无线配置和获取
typedef enum DIAL_MODE
{
	MANUL_DIAL = 0,
	AUTO_DIAL,
	DIAL_MAX
}DIAL_MODE_E;

typedef enum WIRELESS_NET_MODE
{
	WL_NET_TYPE_AUTO = 0,
	WL_NET_TYPE_4G,
	WL_NET_TYPE_3G,
	WL_NET_TYPE_MAX
}WIRELESS_NET_MODE_E;

typedef enum DIAL_AUTH_TYPE
{
    DIAL_AUTH_NONE     = 0x00,   /*不鉴权*/
    DIAL_AUTH_PAP      = 0x01,    /*PAP鉴权*/
    DIAL_AUTH_CHAP     = 0x02,    /*CHAP鉴权*/
    DIAL_AUTH_CHAP_PAP = 0x03    /*先尝试CHAP鉴权，失败后再尝试PAP鉴权*/
}DIAL_AUTH_TYPE_E;

/******** DIAL   ********/
#define DIAL_APP_LEN_MAX (32 + 1)
#define DIAL_USR_NAME_LEN_MAX (32 + 1)
#define DIAL_PASSWD_LEN_MAX (32 + 1)
#define DIAL_PLAN_AREA_MAX  (8)
#define DIAL_SMS_WHITE_LIST_MAX (8)
#define DIAL_RC_NUM_LEN_MAX (4+1)
#define DIAL_PHONE_NUM_LEN (16)
#define IPV4_ADDR_LEN           (16)        //点分十进制IP地址长度
#define DAYS_PER_WEEK       (7)
#define DIAL_PLMN_NAME_MAX (40)

typedef struct PU_DIALING_PARA
{
    DIAL_AUTH_TYPE_E enAuthType;					/*鉴权类型，为不鉴权时用户名密码可以为空*/
	CHAR szApn[DIAL_APP_LEN_MAX];
	CHAR szUserName[DIAL_USR_NAME_LEN_MAX];
	CHAR szPassWd[DIAL_PASSWD_LEN_MAX];
}PU_DIALING_PARA_S;

/* 使能 */
typedef enum PU_ENABLE_TYPE
{
    /* 枚举值定义需从大到小排列，否则，须对每个枚举值赋值 */
    PU_ENABLE_FALSE = 0,              //不使能
    PU_ENABLE_TRUE  = 1,              //使能
    PU_ENABLE_MAX
}PU_ENABLE_TYPE_E;

typedef struct PU_DIALING_CONFIG_INFO
{
	PU_ENABLE_TYPE_E enEnable;
	DIAL_MODE_E   enDialingMode;
	WIRELESS_NET_MODE_E enWirelessNetMode;
	PU_DIALING_PARA_S stDialingPara;
}PU_DIALING_CONFIG_INFO_S;

typedef enum DIAL_SIM_STATUS_TYPE
{
    DIAL_SIM_STATUS_ABSENT = 0,          /*无卡状态*/
    DIAL_SIM_STATUS_READY,               /*卡状态正常状态*/
    DIAL_SIM_STATUS_FAILURE,             /*卡状态异常*/
    DIAL_SIM_STATUS_PIN_REQUIRED,        /*待输入PIN码解锁*/
    DIAL_SIM_STATUS_PIN2_REQUIRED,       /*待输入PIN2码解锁*/
    DIAL_SIM_STATUS_PUK_REQUIRED,        /*待输入PUK码解锁*/
    DIAL_SIM_STATUS_PUK2_REQUIRED,       /*待输入PUK2码解锁*/
    DIAL_SIM_STATUS_OPERATION_NOT_ALLOW, /*操作不允许*/
    DIAL_SIM_STATUS_INCORRECT_PASSWORD,  /*密码错误*/
    DIAL_SIM_STATUS_PIN_ERROR_MAX
}DIAL_SIM_STATUS_TYPE_E;

typedef enum DIAL_NET_ACT_TYPE
{
    DIAL_REGISTER_ST_NO_SERVICE     = 0x00,
    DIAL_REGISTER_ST_GSM            = 0x01,
    DIAL_REGISTER_ST_WCDMA          = 0x02,
    DIAL_REGISTER_ST_LTE            = 0x03,
    DIAL_REGISTER_ST_MAX,
}DIAL_NET_ACT_TYPE_E;


typedef enum DIAL_CONNECT
{
	DIAL_DISCONNECT = 0,
	DIAL_CONNECT,
	DIAL_CONNECT_MAX
}DIAL_CONNECT_E;

typedef struct PU_DIALING_STATUS_INFO
{
    DIAL_SIM_STATUS_TYPE_E  enSimStatus;                //SIM卡状态
    DIAL_NET_ACT_TYPE_E     enActType;                  //网络制式
    INT                     nSignalStrength;            //信号强度
    DIAL_CONNECT_E          enIPv4ConnectStat;                         /*IPV4拨号状态*/
    CHAR                    szIPv4Address[IPV4_ADDR_LEN];   /*IPV4地址*/
    CHAR                    szIPv4NetMask[IPV4_ADDR_LEN];   /*IPV4子网掩码*/
    CHAR                    szIPv4NetGate[IPV4_ADDR_LEN];   /*IPV4子网网关*/
    CHAR                    szIPv4pDnsAddr[IPV4_ADDR_LEN];      /*IPV4主DNS*/
    CHAR                    szIPv4sDnsAddr[IPV4_ADDR_LEN];      /*IPV4辅DNS*/
    CHAR                    szPLMNName[DIAL_PLMN_NAME_MAX];     /*运营商状态*/
}PU_DIALING_STATUS_INFO_S;

typedef struct PU_MANUL_DIALING
{
	DIAL_CONNECT_E enDialConnect;
}PU_MANUL_DIALING_S;

typedef struct PU_TIME_RANGE_MIN
{
	SHORT sStartTime;
	SHORT sEndTime;
}PU_TIME_RANGE_MIN_S;

typedef struct PU_DIALING_PLAN_DAY
{
	PU_TIME_RANGE_MIN_S szTimeRange[DIAL_PLAN_AREA_MAX];
}PU_DIALING_PLAN_DAY_S;

typedef struct PU_AUTO_DIALING_PLAN
{
	PU_DIALING_PLAN_DAY_S szDalingPlan[DAYS_PER_WEEK];
}PU_AUTO_DIALING_PLAN_S;

typedef struct PU_SMS_CMD_INFO
{
    CHAR szRcNum[DIAL_RC_NUM_LEN_MAX];
    CHAR szPeerNum[DIAL_PHONE_NUM_LEN];
    PU_ENABLE_TYPE_E enRestartEnable;
    PU_ENABLE_TYPE_E enDialEnable;
}PU_SMS_CMD_INFO_S;

typedef struct PU_SMS_WHITE_LISTS
{
	PU_SMS_CMD_INFO_S szSmsWhiteList[DIAL_SMS_WHITE_LIST_MAX];
}PU_SMS_WHITE_LISTS_S;

//***************************************************************************************************************************************************************

//智能算法license控制状态
typedef enum PU_ITGT_LIC_STATUS
{
    PU_ITGT_LIC_STATUS_DEFAULT = 0,  //控制项处于默认状态
    PU_ITGT_LIC_STATUS_TRIAL,        //控制项处于宽限期状态
    PU_ITGT_LIC_STATUS_NORMAL,       //控制项处于正常状态
    PU_ITGT_LIC_STATUS_EMERGENCY,    //控制项处于紧急状态
    PU_ITGT_LIC_STATUS_NO_USE,       //不使用
    PU_ITGT_LIC_STATUS_NA            //不涉及
}PU_ITGT_LIC_STATUS_E;

typedef struct PU_ITGT_ALTHM_BASIC_INFO
{
    PU_ITGT_TYPE_E enAlthmType;                       //算法类型
    PU_ITGT_LIC_STATUS_E enAlthmStatus;               //算法控制状态
    BOOL bEnableAlthm;                                //算法是否启用 0：关闭 1:启用
    CHAR szAlthmVer[PU_ITGT_ALTHM_VERSION_LEN];       //算法版本
    CHAR szAlthmOwner[PU_ITGT_ALTHM_VENDOR_LEN];      //算法厂家 
    CHAR szReserved[PU_RESERVE_LEN];       
}PU_ITGT_ALTHM_BASIC_INFO_S, *LPPU_ITGT_ALTHM_BASIC_INFO_S;

typedef struct PU_ITGT_ALTHM_INFO
{   
    UINT ulChannelID;                                      //通道号
    UINT uiValidCount;                                                      //有效的算法个数
    PU_ITGT_ALTHM_BASIC_INFO_S astItgtAlthmBasInfo[PU_ITGT_TYPE_MAX_NUM];   //具体的算法信息
    CHAR szReserved[PU_RESERVE_LEN]; 
}PU_ITGT_ALTHM_INFO_S, *LPPU_ITGT_ALTHM_INFO_S;

typedef struct PU_ITGT_ALTHM_INFO_EX
{   
    UINT ulChannelID;                                      //通道号
    UINT uiValidCount;                                                      //有效的算法个数
    PU_ITGT_ALTHM_BASIC_INFO_S astItgtAlthmBasInfo[PU_ITGT_TYPE_MAX_EX_NUM];   //具体的算法信息
    CHAR szReserved[PU_RESERVE_LEN]; 
}PU_ITGT_ALTHM_INFO_EX_S, *LPPU_ITGT_ALTHM_INFO_EX_S;


//智能算法license控制信息
typedef struct PU_ITGT_LIC_CONTROL_INFO
{
    PU_ITGT_TYPE_E enItgtType;
    PU_ITGT_LIC_STATUS_E enItgtStatus;
    CHAR szLicExpiryDate[PU_LIC_DATE_MAX_LEN];
}PU_ITGT_LIC_CONTROL_INFO_S, *LPPU_ITGT_LIC_CONTROL_INFO_S;

//license 服务消息结构体
typedef struct PU_ITGT_LIC_SERVICE_INFO
{
    UINT uiLicItgtNum;                                                     //license 里面的智能算法个数
    CHAR szLicCreatDate[PU_LIC_DATE_MAX_LEN];                              //license文件创建日期
    CHAR szLicServiceAge[PU_LIC_SERVICE_AGE_MAX_LEN];                      //服务年份
    PU_ITGT_LIC_CONTROL_INFO_S  astLicControlInfo[PU_ITGT_TYPE_MAX_NUM];   //智能算法license控制信息
}PU_ITGT_LIC_SERVICE_INFO_S, *LPPU_ITGT_LIC_SERVICE_INFO_S;


//license 服务消息结构体扩充(16->64)
typedef struct PU_ITGT_LIC_SERVICE_INFO_EX
{
    UINT uiLicItgtNum;                                                     //license 里面的智能算法个数
    CHAR szLicCreatDate[PU_LIC_DATE_MAX_LEN];                              //license文件创建日期
    CHAR szLicServiceAge[PU_LIC_SERVICE_AGE_MAX_LEN];                      //服务年份
    PU_ITGT_LIC_CONTROL_INFO_S  astLicControlInfo[PU_ITGT_TYPE_MAX_EX_NUM];   //智能算法license控制信息
    CHAR szReserved[PU_RESERVE_LEN]; 
}PU_ITGT_LIC_SERVICE_INFO_EX_S, *LPPU_ITGT_LIC_SERVICE_INFO_EX_S;

//失效码
typedef struct PU_ITGT_LIC_REVOKE_INFO
{
    CHAR szRevokeKey[PU_LIC_REVOKE_KEY_LEN];
}PU_ITGT_LIC_REVOKE_INFO_S, *LPPU_ITGT_LIC_REVOKE_INFO_S;

/*************begin:人脸库相关数据结构**************/
//人脸库操作类型:增删改
typedef enum PU_FACELIB_OPERATE
{
    FACELIB_ADD = 1,
    FACELIB_MODIFY,
    FACELIB_DEL,
    FACELIB_DEL_ALL,
    
    FACELIB_MAX,
}PU_FACELIB_OPERATE_E;

//人脸库名单类型
typedef enum PU_FACE_LIB_TYPE
{
    FACE_LIB_DEFAULT = 0,
    FACE_LIB_BLACK,         //黑名单
    FACE_LIB_WHITE,         //白名单

    FACE_LIB_MAX,
}PU_FACE_LIB_TYPE_E;


//人员性别
typedef enum PU_GENDER
{
    PU_GENDER_ALL = -1,    // 全部：搜索时专用，添加、修改时禁止
    PU_MALE = 0,            // 男
    PU_FEMALE,              // 女
    PU_GENDER_UNKNOW,       // 未知
    PU_GENDER_MAX,
}PU_GENDER_E;

//人员证件类型
typedef enum PU_CARDTYPE
{
	CARDTYPE_ALL = -1,  // 全部：搜索时专用，添加、修改时禁止
    IDENTITY = 0,       // 身份证
    PASSPORT,           // 护照
    OFFICER,            // 军官证
    DRIVING,            // 驾驶证
    OTHERS,             // 其他
    MAX
}PU_CARDTYPE_E;

typedef enum PU_FEATURE_STATUS_TYPE
{
    FEATURE_STATUS_UNKNOWN = 0,         // 新建人脸库状态
    FEATURE_STATUS_QUERY_ALL,           // 查询全部
    FEATURE_STATUS_REEXTRACT,           // 重新提取，用于人脸库状态，算法升级时触发
    FEATURE_STATUS_UNEXTRACT,           // 未提取
    FEATURE_STATUS_EXTRACTED,           // 已提取
    FEATURE_STATUS_FAILED,              // 提取失败，用于查询失败的人脸图片
    FEATURE_STATUS_ERRIMGSIZE,          // 图片尺寸不规范
    FEATURE_STATUS_DECODE_FAIL,         // 图片解码失败
    FEATURE_STATUS_DETECTION_FAIL,      // 人脸检测失败
    FEATURE_STATUS_EXTRACT_FAIL,        // 特征提取失败
    FEATURE_STATUS_ADD_FEATURE_FAIL,    // 特征写入失败
    FEATURE_STATUS_MAX,
}PU_FEATURE_STATUS_TYPE_E;

// 人脸相关信息
typedef struct PU_FACE_RECORD
{
    ULONG ulFaceId;                                     // 人脸ID
    CHAR szName[PU_MAX_RECORD_LEN_64];                  // 姓名
    PU_GENDER_E enGender;                               // 性别 
    CHAR szBirthday[PU_MAX_RECORD_LEN_32];              // 生日
    CHAR szProvince[PU_MAX_RECORD_LEN_32];              // 省级
    CHAR szCity[PU_MAX_RECORD_LEN_48];                  // 地市
    PU_CARDTYPE_E enCardType;                           // 证件类型  
    CHAR szCardID[PU_MAX_RECORD_LEN_32];                // 证件号
    CHAR szExtensionField[PU_MAX_EX_FIELD_LEN];         // 人脸信息扩充字段，预留
    CHAR szPicPath[PU_SAVE_FILE_PATH_MAX];              // 图片路径，客户端用来上传图片，设备上保存图片的全路径，在sdkserver写即可
                                                        // example：/tmp/mmcblk0/face_basic/test_sdk.jpg   
    CHAR szReserve[PU_RESERVE_LEN];
}PU_FACE_RECORD_S;


//名单库
typedef struct PU_FACE_LIB_S
{
    ULONG              ulFaceLibID;                        // 人脸库ID
    PU_FACE_LIB_TYPE_E enLibType;                          // 名单库类型
    BOOL               isControl;                          // 是否布控
    ULONG              uiThreshold;                        // 布控阈值
    CHAR               szLibName[PU_MAX_RECORD_LEN_64 + 1];// 名单库名称
    CHAR               szReserve[PU_RESERVE_LEN];
}PU_FACE_LIB_S;


//人脸库信息设置
typedef struct PU_FACE_LIB_SET_S
{
    ULONG                  ulChannelId;                     //通道ID
    PU_FACELIB_OPERATE_E   enOptType;                       //操作类型
    PU_FACE_LIB_S          stFacelib;                       //名单库
    CHAR                   szReserve[PU_RESERVE_LEN];
}PU_FACE_LIB_SET_S;

//人脸库信息获取
typedef struct PU_FACE_LIB_GET_S
{
    ULONG           ulChannelId;                            //通道ID
    ULONG           ulFaceLibNum;                           //库总数
    CHAR            szFindResultPath[PU_SAVE_FILE_PATH_MAX];//查询结果路径，客户端是在本地的一个目录，设备上是一个json文件路径由智能提供
    CHAR            szReserve[PU_RESERVE_LEN];
}PU_FACE_LIB_GET_S;

//人脸导库操作
typedef struct PU_FACE_LIB_IMPORT_S
{
    ULONG               ulChannelId;                    //通道ID
    PU_FACE_PACKET_TYPE_E   enPacketType;                  // 包类型
    PU_FACE_LIB_S       stFacelib;                      //名单库
    CHAR                szPath[PU_IMPORT_FILE_LEN_MAX];    //文件路径及文件名
    CHAR                szFileName[PU_IMPORT_FILENAME_LEN_MAX];    //文件名
    CHAR                szImportResult[PU_IMPORT_FILE_LEN_MAX];    //导出结果CSV保存路径，在IVS_PU_ImportFaceLibEx接口中该字段不使用
    ULONG               taskID;                         // 人脸导库任务ID
    CHAR                szReserve[PU_RESERVE_LEN-sizeof(ULONG)];
}PU_FACE_LIB_IMPORT_S;

//人脸导库、特征提取状态查询
typedef struct PU_FACE_LIB_STATUS_S
{
    ULONG               ulChannelId;                                   // 通道ID
    PU_FACE_LIB_S       stFacelib;                                     // 名单库
    ULONG               taskID;                                        // 人脸导库、特征提取任务ID
    BOOL                status;                                        // 导入、特征提取状态 1:完成 0:未完成
    ULONG               totalPicNum;                                   // 所有导入、特征提取数量
    ULONG               finishPicNum;                                  // 成功导入、特征提取数量
    CHAR                szResultCsvPath[PU_IMPORT_FILE_LEN_MAX];       // 导入、特征提取结果CSV保存路径 
    CHAR                szReserve[PU_RESERVE_LEN];
}PU_FACE_LIB_STATUS_S;

//单张人脸添加
typedef struct PU_FACE_INFO_ADD_S
{
    ULONG               ulChannelId;                    //通道ID
    PU_FACE_LIB_S       stFacelib;                      //名单库
    PU_FACE_RECORD_S    stRecord;                       //信息
    CHAR                szReserve[PU_RESERVE_LEN];
}PU_FACE_INFO_ADD_S;

// 人脸相关信息
typedef struct FACE_FIND_CONDITION {
    CHAR szName[PU_MAX_RECORD_LEN_64];                          // 姓名
    PU_GENDER_E enGender;                                       // 性别 
    CHAR szProvince[PU_MAX_RECORD_LEN_32];                      // 省级
    CHAR szCity[PU_MAX_RECORD_LEN_48];                          // 地市
    PU_CARDTYPE_E enCardType;                                   // 证件类型  
    CHAR szCardID[PU_MAX_RECORD_LEN_32];                        // 证件号
    CHAR szBirthdayStart[PU_MAX_RECORD_LEN_32];                 // 生日开始
    CHAR szBirthdayEnd[PU_MAX_RECORD_LEN_32];                   // 生日结束
    PU_FEATURE_STATUS_TYPE_E enFeatureStatus;                   // 特征值状态
    CHAR szReserve[PU_RESERVE_LEN-sizeof(PU_FEATURE_STATUS_TYPE_E)];
}PU_FACE_FIND_CONDITION_S;

//人脸信息查询
typedef struct PU_FACE_INFO_FIND_S
{
    ULONG                    ulChannelId;                            //通道ID
    PU_FACE_LIB_S            stFacelib;                              //名单库
    PU_FACE_FIND_CONDITION_S stCondition;                            //查询条件
    UINT                     uFindNum;                               //查询结果数目
    UINT                     uStartIndex;                            //起始查询ID
    CHAR                     szFindResultPath[PU_SAVE_FILE_PATH_MAX + 1];//查询结果路径 设备上是一个json文件路径/tmp/mmcblk0/facelist.json，可以对客户端不可见
    CHAR                szReserve[PU_RESERVE_LEN];
}PU_FACE_INFO_FIND_S;

//人脸信息修改
typedef struct PU_FACE_INFO_MODIFY_S
{
    ULONG            ulChannelId;                        //通道ID
    PU_FACE_LIB_S    stFacelib;                          //名单库
    PU_FACE_RECORD_S stRecord;                           //修改后的结果
    CHAR             szReserve[PU_RESERVE_LEN];
}PU_FACE_INFO_MODIFY_S;

//人脸信息删除
typedef struct PU_FACE_INFO_DELETE_S
{
    ULONG           ulChannelId;                        //通道ID
    PU_FACE_LIB_S   stFacelib;                          //名单库
    UINT            uFaceNum;                           //需要删除的数目
    UINT            uFaceID[PU_MAX_DELETE_NUM];         //需要删除的人脸id
    CHAR            szReserve[PU_RESERVE_LEN];
}PU_FACE_INFO_DELETE_S;

//人脸图片获取
typedef struct PU_FACE_PIC_GET_S
{
    ULONG                    ulChannelId;            //通道ID
    PU_FACE_LIB_S            stFacelib;              //名单库
    ULONG                    uFaceID;                 //人脸ID
    CHAR                     szFindResultPath[PU_SAVE_FILE_PATH_MAX + 1];    //查询结果路径 (SDK本地)
    CHAR                     szReserve[PU_RESERVE_LEN];
}PU_FACE_PIC_GET_S;

typedef struct PU_FACE_FEATURE_GET_S
{
    ULONG            ulChannelId;                                //通道ID
    PU_FACE_LIB_S     stFacelib;                                  //名单库
    CHAR              szFeatureFilePath[PU_SAVE_FILE_PATH_MAX];   //导出的特征文件路径
    //CHAR              szExportCsvPath[PU_SAVE_FILE_PATH_MAX];     //导出结果CSV路径    
    CHAR              szReserve[PU_RESERVE_LEN];
}PU_FACE_FEATURE_GET_S;

// 人脸特征提取
typedef struct PU_FACE_FEATURE_EXTRACT_S
{
    ULONG            ulChannelId;                                      //通道ID
    PU_FACE_LIB_S    stFacelib;                                        //名单库
    ULONG            taskID;                                           //任务ID
    CHAR             szReserve[PU_RESERVE_LEN];
}PU_FACE_FEATURE_EXTRACT_S;

/*************end:人脸库相关数据结构**************/

/*ITS 车流量统计参数 */
typedef struct PU_ITS_FLOW_RATE_PARA
{
	ULONG          ulChannelId;             //通道IDF
	PU_ENABLE_TYPE_E   bEnable;	            //是否启用
	ULONG          uInterval;  			    //统计周期(分钟)
	ULONG          uCameraFromIntersection; //相机位置距离路口距离(米)
	ULONG          uDetectionAreaLength;    //检测区域长度(米)
	ULONG          uCongestionLaneThreshold;//拥堵上报阈值
	ULONG          uCongestionThreshold;    //拥塞阈值(Km/h)
	ULONG          uSlowThreshold;          //缓行阈值(Km/h)
	CHAR           szReserve[PU_RESERVE_LEN];
}PU_ITS_FLOW_RATE_PARA_S;


//矩形结构体
typedef struct PU_RECTANGLE
{
    ULONG ulStartX;
    ULONG ulStartY;
    ULONG ulWeight;
    ULONG ulHeight;
}PU_RECTANGLE_S;

/*灯组的信息*/
typedef struct PU_RL_LIGHTINFOS_PARA
{
    PU_RECTANGLE_S stRLCropStart;           //红灯区域起始坐标
    PU_RL_LIGHT_TYPE_E enType;              //红灯类型
    BOOL bEnable;                           //灯组使能开关
    CHAR szReserve[PU_RESERVE_LEN];
}PU_RL_LIGHTINFOS_PARA_S;

/*处理帧的信息*/
typedef struct PU_RL_FRAME_PARA
{
    PU_RL_LIGHTINFOS_PARA_S stLightInfo[PU_RL_NUM_MAX];   //红灯状态
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_RL_FRAME_PARA_S;

/*红灯区域增强参数 */
typedef struct PU_RL_CROP_ENHANCE_PARA
{
    ULONG ulChannelID;    //通道号
	INT iLevel;               //强度(0-100)
	INT iEnable;              //使能开关
	PU_RL_FRAME_PARA_S stFrameInfo; //帧信息
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_RL_CROP_ENHANCE_PARA_S;


//测速配置
typedef struct PU_ITS_SPEED_MEASURE_PARAM
{
    ULONG ulChannelId;                // 通道ID
    INT   iCameraHeightH;             //摄像机距离地面亮度H
    INT   iImageBottom2CameraL1;      //视野图像下沿到摄像机所在地面边线L1
    INT   iImageCenter2CameraL2;      //视野图像中间到摄像机所在地面边线L2
    CHAR    szReserve[PU_RESERVE_LEN];
}PU_ITS_SPEED_MEASURE_PARAM_S;


typedef enum tagEN_ITS_TYPE
{
    ITS_TYPE_EPOLICE = 0,       //电警
    ITS_TYPE_TGATEWAY = 1,      //卡口
    ITS_TYPE_MAX,
}EN_ITS_TYPE;

/* ITS业务类型结构体 */
typedef struct PU_ITS_BUSINESS_TYPE_PARA
{
    ULONG            ulChannelID;          // 通道ID
    EN_ITS_TYPE      enITSBusinessType;    // ITS业务类型
	CHAR szReserved[PU_RESERVE_LEN];
}PU_ITS_BUSINESS_TYPE_PARA_S;

// 方向编号
typedef enum PU_ITS_ROAD_DIR_TYPE
{
    ITS_ROAD_UNKNOW,         // 未知
    ITS_ROAD_EAST_TO_WEST,   // 东向西
    ITS_ROAD_WEST_TO_EAST,   // 西向东
    ITS_ROAD_SOUTH_TO_NORTH, // 南向北
    ITS_ROAD_NORTH_TO_SOUTH, // 北向南
    ITS_ROAD_ES_TO_WN,       // 东南向西北
    ITS_ROAD_WN_TO_ES,       // 西北向东南
    ITS_ROAD_EN_TO_WS,       // 东北向西南
    ITS_ROAD_WS_TO_EN        // 西南向东北
}PU_ITS_ROAD_DIR_TYPE_E;

// 车道线行驶方向
typedef enum PU_ITS_ROAD_DRV_DIR
{
    ITS_ROAD_DRV_DIR_UNKNOW,           // 未知
    ITS_ROAD_DRV_DIR_LEFT,             // 左转
    ITS_ROAD_DRV_DIR_STRAIGHT,         // 直行
    ITS_ROAD_DRV_DIR_LFT_STR,          // 左转+直行
    ITS_ROAD_DRV_DIR_RIGHT,            // 右转
    ITS_ROAD_DRV_DIR_RHT_LFT,          // 右转+左转
    ITS_ROAD_DRV_DIR_RHT_STR,          // 右转+直行
    ITS_ROAD_DRV_DIR_RHT_STR_LFT,      // 右转+左转+直行
    ITS_ROAD_DRV_DIR_LFT_WAIT          // 左转待行
}PU_ITS_ROAD_DRV_DIR_E;

// 车辆在视频中的运动方向
typedef enum PU_ITS_CAR_DRV_DIR
{
    ITS_CAR_UNKNOW,             // 未知
    ITS_CAR_BOTTOM_TO_TOP,      // 从下向上
    ITS_CAR_TOP_TO_BOTTOM,      // 从上向下
}PU_ITS_CAR_DRV_DIR_E;

// 车道用途
typedef enum PU_ITS_ROAD_PURPOSE
{
    ITS_UNKNOW_ROAD,             // 未知车道
    ITS_COMMON_ROAD,             // 普通车道
    ITS_BUS_ROAD,                // 公交车道
    ITS_FAST_ROAD,               // 快车道
    ITS_SLOW_ROAD,               // 慢车道
    ITS_MOTOR_ROAD,              // 摩托车道
    ITS_NONMOTOR_ROAD,           // 非机动车道
    ITS_REVERSE_ROAD,            // 反向车道
    ITS_FORBIT_BIGCAR_ROAD,      // 禁止大车道
    ITS_EMERGENCY                // 应急车道
}PU_ITS_ROAD_PURPOSE_E;

// 车道属性
typedef enum PU_ITS_ROAD_ATTRIBUTE
{
    ITS_ROAD_HIGHWAY,       // 高速公路
    ITS_ROAD_EXPRESSWAY,    // 城市快速路
    ITS_ROAD_OTHER,         // 其他道路
}PU_ITS_ROAD_ATTRIBUTE_E;

//车道旁边场景类型
typedef enum tagRoadSideScene
{
    ITS_MEDIAN_ROAD_SIDE,             // 隔离带类型
    ITS_REALLINE_ROAD_SIDE,           // 实线类型
    ITS_DOTLINE_ROAD_SIDE,            // 虚线类型
    ITS_UNKNOWN_ROAD_SIDE=10             //未知场景类型
} ITS_ROAD_SIDE_SCENE_E;

// 基本车道信息
typedef struct PU_ITS_LANE_INFO_BASE_UNIT
{
    PU_ITS_ROAD_DIR_TYPE_E      enLaneDirType;                      // 车道方向类型
    PU_ITS_ROAD_DRV_DIR_E       enLaneDrvDir;                       // 车道行驶方向
    PU_ITS_CAR_DRV_DIR_E        enCarDrvDir;                        // 车辆在视频中运动方向
    PU_ITS_ROAD_PURPOSE_E       enLanePurpose;                      // 车道用途
    PU_ITS_ROAD_ATTRIBUTE_E     enLaneAttribute;                    // 车道属性
    INT                         iOSDLaneNO;                         // 叠加车道号, OSD 叠加，一般与实际车道匹配
    INT                         iBindingDeviceCode;                 // 关联车道号, 用于对应雷达、车检器、IO 外设
    INT                         iPreRecordStart;                    // 预录开始时间
    ITS_ROAD_SIDE_SCENE_E       enLaneSideScene;                    // 车道场景类型，用于掉头违章判
    CHAR                        szReserve[PU_RESERVE_LEN-1];
} PU_ITS_LANE_INFO_BASE_UNIT_S;

// 限速值
typedef struct PU_ITS_SPEED_LIMIT
{
    INT                       iNormalSignSpeed;               // 小车标志速度(限速值范围为0~255km/h)
    INT                       iNormalLowSpeed;                // 小车限制低速(限速值范围为0~255km/h)
    INT                       iNormalHighSpeed;               // 小车限制高速(限速值范围为0~255km/h)
    INT                       iBigVehicleSignSpeed;           // 大车标志速度(限速值范围为0~255km/h)
    INT                       iBigVehicleLowSpeed;            // 大车限制低速(限速值范围为0~255km/h)
    INT                       iBigVehicleHighSpeed;           // 大车限制高速(限速值范围为0~255km/h)
    CHAR                      szReserve[PU_RESERVE_LEN];
} PU_ITS_SPEED_LIMIT_S;

// 车道参数单元
typedef struct PU_ITS_LANE_PARAM_UNIT
{
    PU_ITS_LANE_INFO_BASE_UNIT_S stLaneInfoBaseU;                // 基础车道信息
    PU_ITS_SPEED_LIMIT_S         stSpeedLimit;                   // 速度限制配置
    BOOL                         bRegulationRecord;              // 违章录像使能
    INT                          iExterLampBitMap;               // 外置灯关联BitMap
    CHAR                         szReserve[PU_RESERVE_LEN];
} PU_ITS_LANE_PARAM_UNIT_S;

//视频电警车道参数
typedef struct PU_ITS_EPOLICE_LANE_PARAM
{
    ULONG                        ulChannelId;                    // 通道ID
    EN_ITS_TYPE                  enITSType;                      // ITS业务类型
    INT                          iLaneNum;                       // 车道数量
    PU_ITS_LANE_PARAM_UNIT_S     astLaneParamU[MAX_AREA_VERTEX]; // 车道参数
    CHAR                         szReserve[PU_RESERVE_LEN];
}PU_ITS_LANE_PARAM_S,PU_ITS_EPOLICE_LANE_PARAM_S, PU_ITS_TGATEWAY_LANE_PARAM_S;

#define ITS_REGULATION_TYPE_NUM_MAX  32
#define ITS_SNAP_NUM_MAX  4

// 违章类型检测方式
typedef enum ITS_REGULA_DT_TYPE
{
    ITS_REGULA_DT_TYPE_EXTDEV,          // 外设接入
    ITS_REGULA_DT_TYPE_VIDEODT,         // 视频检测
    ITS_REGULA_DT_TYPE_EXTDEV_FIRST,    // 外设优先
    ITS_REGULA_DT_TYPE_MAX
}EN_ITS_REGULA_DT_TYPE;

// 违章类型
typedef enum PU_ITS_REGULA_TYPE
{
    ITS_REGULA_NULL = 0, /* 无违章判断, 初始值 */
    ITS_REGULA_PASS_SNAP = 1, /* 卡口抓拍 */
    ITS_REGULA_RUNNINGRED = 2, /* 闯红灯     1625*/
    ITS_REGULA_EXCEET_SPEED = 3, /* 超速 */
    ITS_REGULA_UNDER_SPEED = 4, /* 低速    4306*/
    ITS_REGULA_WRONG_DIRECTION = 5, /* 不按导向行驶, 左转/直行/右转 1208*/
    ITS_REGULA_REVERSE_DIRECTION = 6, /* 逆行 1301  */
    ITS_REGULA_LICENCE_RESTRICTE = 7, /* 尾号限行 */
    ITS_REGULA_OVER_LANE_LINE = 8, /* 压车道线 1345*/
    ITS_REGULA_CHANGE_LANE = 9, /* 违法变道 13453*/
    ITS_REGULA_MOTOR_IN_BICYCLE_LANE = 10, /* 机占非 1018*/
    ITS_REGULA_ACCOMMODATION_LANE = 11, /* 占用专用车道  1019*/
    ITS_REGULA_PROHIBITION = 12, /* 闯禁令 1344*/
    ITS_REGULA_REMAIN_CROSS = 13, /* 路口滞留 1228*/
    ITS_REGULA_STOP_LIGHT_GREEN = 14, /* 绿灯停车 16251*/
    ITS_REGULA_EMERGENCY = 15, /* 占用应急车道   */
    ITS_REGULA_SAFETY_BELT = 16, /* 未系安全带 1240*/
    ITS_REGULA_U_TURN = 17, /* 违章掉头 1044*/
    ITS_REGULA_PORT_VEHICLE_DRIVER_CALL = 18,  /* 主驾驶打电话 卡口设备触发*/
    ITS_REGULA_PORT_VEHICLE_COPILOT_NO_BELT = 19,  /* 副驾驶未系安全带 卡口设备触发*/
    ITS_REGULA_PORT_VEHICLE_NO_YEAR_LOG = 20,  /* 无年检标 卡口设备触发*/
    ITS_REGULA_ILLEGAL_PARKING = 21,        /*黄网格违停*/
    ITS_REGULA_IMPOLITE_PEDESTRIANS = 22, /*不礼让行人*/
    ITS_REGULA_OCCUPANCY_BUSLANE = 23, /*违法占用公交车道*/
    ITS_REGULA_LARGER_VEHICLE_OUTOFLANE = 24, /*大车不按车道行驶*/
	ITS_REGULA_IBALL_ILLEGAL_PARKING = 25,   /*违法停车*/
	ITS_REGULA_VEHICLEBAN = 26, /*闯禁令*/
	ITS_REGULA_NOVEHICLE_IN_LANE = 27, /*非占机*/

	ITS_REGULA_RECOGNIZE_ONLY = 30,          /* 电警六合一,车流量等只需识别不需上传元数据的用此枚举 */
    ITS_REGULA_ALL = 31,                    /* 内核栈空间最大只支持32个违章 */
    ITS_REGULA_BUTT = 32,

} PU_ITS_REGULA_TYPE_E;

// 闯灯优先级
typedef enum PU_ITS_RUNLIGHT_PRIORITY
{
    ITS_RUNLIGHT_NONE_PRIORITY,     // 无
    ITS_RUNLIGHT_RED_PRIORITY       // 闯红灯优先
}PU_ITS_RUNLIGHT_PRIORITY_E;

// 闯灯违规逻辑
typedef enum PU_ITS_RUNLIGHT_RULE
{
    ITS_RUNLIGHT_BYLANE,            // 按车道
    ITS_RUNLIGHT_BYDIR              // 按方向
}PU_ITS_RUNLIGHT_RULE_E;

// 闯灯参数
typedef struct tagITSRunLightPara
{
    PU_ITS_RUNLIGHT_PRIORITY_E  enRunLightPriority;     // 优先级别
    PU_ITS_RUNLIGHT_RULE_E      enRunLightRule;         // 违规逻辑
    INT                         iSecondSnapOffset;      // 第二张抓图偏移
    INT                         iPicMinOffset;          // 图片最小偏移
    CHAR                        szReserve[PU_RESERVE_LEN];
}PU_ITS_RUNLIGHT_PARA_S;

// 压线违章抓拍附加参数
typedef struct tagITSRegulationCfgAttchPressLine
{
    INT  nSensitivity; // 压线灵敏度（0~100ms）
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_REGULATION_CFG_ATTCH_PRESS_LINE_UNIT_S;

// 机占非违章抓拍附加参数
typedef struct tagITSRegulationCfgAttchInvadeDriverWay
{
    INT  nStayTime; // 停留时间（0~180ms）
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S;

typedef union tagITSRegulationCfgAttch
{
    PU_ITS_RUNLIGHT_PARA_S                                stRunningRed;       // 预留，当前不使用, 闯红灯抓拍参数,对应违章类型ITS_REGULA_RUNNINGRED
    PU_ITS_REGULATION_CFG_ATTCH_PRESS_LINE_UNIT_S         stPressLine;        // 压线,对应违章类型ITS_REGULA_OVER_LANE_LINE
    PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S   stInvadeDriverWay;  // 机占非,对应违章类型ITS_REGULA_MOTOR_IN_BICYCLE_LANE
    PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S   stInvadeBusLane;    // 非法占用公交车道,对应违章类型ITS_REGULA_OCCUPANCY_BUSLANE
    PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S   stIllegalParkTime;  // 黄网格违停时间,对应违章类型ITS_REGULA_ILLEGAL_PARKING
    PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S   stImpolitePedestriansTime;//行人等待时间

} PU_ITS_REGULATION_CFG_ATTCH_UNIT_S;

// 违章抓拍参数单元
typedef struct tagRegulationSnapConfigUnit
{
    PU_ITS_REGULA_TYPE_E               enRegulationType; // 抓拍类型
    BOOL                               bEnable;          // 抓拍使能
    INT                                iSnapNum;         // 抓拍张数
    PU_ITS_REGULATION_CFG_ATTCH_UNIT_S uniAttach;        // 附加信息
    CHAR                               szReserve[PU_RESERVE_LEN];
} PU_ITS_REGULATION_SNAP_CONFIG_UNIT_S;

// 视频电警检测抓拍类型
typedef struct tagItsEPoliceSnapType
{
    ULONG                   ulChannelId;     // 通道ID
    EN_ITS_TYPE             enITSType;       // ITS业务类型
    EN_ITS_REGULA_DT_TYPE   enRegulaDtType;  // 违章类型检测方式
    INT                     aiMultiSnapInterval[ITS_SNAP_NUM_MAX];  // 连拍间隔, 单位时间 ms

    /* 电警：1卡口 2闯红灯 3超速 4低速 5不按导向行驶 6逆行 7尾号限行 8压车道线 9违法变道
     *       10机占非 21黄网格违停 22不礼让行人 23违法占用公交车道 24大车不按车道行驶
     *
     * 卡口：1卡口 3超速 4低速 6逆行 7尾号限行 8压车道线 9违法变道 10机占非 18开车打手机
     *      19不系安全带 21黄网格违停 22不礼让行人 23违法占用公交车道 24大车不按车道行驶
     *
    */
    INT                     iRegulationNum;  // 违章抓拍项数（电警14，卡口15）
    PU_ITS_REGULATION_SNAP_CONFIG_UNIT_S astRegulationSnapCfgU[ITS_REGULATION_TYPE_NUM_MAX]; // 违章抓拍类型
    CHAR                    szReserve[PU_RESERVE_LEN];
}PU_ITS_SNAP_TYPE_PARAM_S, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_S, PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_S;

// 抓拍时间间隔检测方式
typedef enum tagItsSnapItervalType
{
	PU_ITS_SNAP_INTERVAL,                  // 固定抓拍间隔
	PU_ITS_ADAPTIVE_SNAP_INTERVAL,         // 自适应抓拍间隔
	PU_ITS_SNAP_INTERVAL_TYPE_MAX
}PU_ITS_SNAP_INTERVAL_TYPE;

#define ITS_ADAPT_SNAP_INTERVAL_NUM_MAX  2
// 违章抓拍方式(单快门、双快门)
typedef enum tagItsRegulaSnapType
{
    PU_ITS_REGULA_SNAP_SINGLE_SHUTTER,         // 单快门
    PU_ITS_REGULA_SNAP_DOUBLE_SHUTTER,         // 双快门
    PU_ITS_REGULA_SNAP_TYPE_MAX
}PU_ITS_REGULA_SNAP_TYPE;

//自适应抓拍间隔配置
typedef struct tagItsAdaptSnapIntervalType
{
	ULONG                               uiLowSpeedMax;                           //自适应低速最大值
	ULONG                               uiMidSpeedMax;                           //自适应中速最大值
	INT                                 aiAdaptLowSpeedInterval[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX];  //自适应低速连拍间隔, 单位时间 ms
	INT                                 aiAdaptMidSpeedInterval[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX];  // 自适应中速连拍间隔, 单位时间 ms
	INT                                 aiAdaptHighSpeedInterval[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX];  //自适应高速 连拍间隔, 单位时间 ms
}PU_ITS_ADAPT_INTERVAL_PARAM_S;
// 视频电警检测抓拍类型扩充
typedef struct tagItsEPoliceSnapType_V2
{
    ULONG                   ulChannelId;     // 通道ID
    EN_ITS_TYPE             enITSType;       // ITS业务类型
    EN_ITS_REGULA_DT_TYPE   enRegulaDtType;  // 违章类型检测方式
    INT                     aiMultiSnapInterval[ITS_SNAP_NUM_MAX];  // 连拍间隔, 单位时间 ms

    /* 电警：1卡口 2闯红灯 3超速 4低速 5不按导向行驶 6逆行 7尾号限行 8压车道线 9违法变道
     *       10机占非 21黄网格违停 22不礼让行人 23违法占用公交车道 24大车不按车道行驶
     *
     * 卡口：1卡口 3超速 4低速 6逆行 7尾号限行 8压车道线 9违法变道 10机占非 18开车打手机
     *      19不系安全带 21黄网格违停 22不礼让行人 23违法占用公交车道 24大车不按车道行驶
     *
    */
    INT                     iRegulationNum;  // 违章抓拍项数（电警14，卡口15）
    PU_ITS_REGULATION_SNAP_CONFIG_UNIT_S astRegulationSnapCfgU[ITS_REGULATION_TYPE_NUM_MAX]; // 违章抓拍类型

    PU_ITS_SNAP_INTERVAL_TYPE            enITSSnapIntervalType;                  // 抓拍间隔类型 
    PU_ITS_ADAPT_INTERVAL_PARAM_S        stAdaptSnapInterval;                    //自适应抓拍间隔配置
    PU_ITS_REGULA_SNAP_TYPE              enRegulaSnapType;                       // 违章抓拍方式(单快门、双快门)
    CHAR                    szReserve[PU_RESERVE_EX_LEN-sizeof(PU_ITS_REGULA_SNAP_TYPE)];
}PU_ITS_SNAP_TYPE_PARAM_V2_S, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_V2_S, PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_V2_S;



#define MAX_AREA_POINTS_NUM    10          //区域顶点最大数目
#define IGT_AREA_NAME_LEN (32 + 4)         //智能区域名称

//视频电警检测线使能
typedef struct tagItsEPoliceDtLineEnable
{
    BOOL    abRoadLane[MAX_LANE_NUM];       // 车道线使能
    BOOL    abStopLine[MAX_LANE_NUM];       // 停止线使能
    BOOL    abTripLine[MAX_LANE_NUM];       // 绊线使能
    BOOL    bLaneRhtBorderLine;             // 车道右边界限
    BOOL    bLftBorderLine;                 // 左转边界线
    BOOL    bRhtBorderLine;                 // 右转边界线
    BOOL    bStrightTrigger;                // 直行触发线
    BOOL    bRunningRedTrigger;             // 闯红灯触发线
    BOOL    bTurnAroundLine;                // 掉头检测线
    BOOL    bPosBox;                        // 定位框
}PU_ITS_EPOLICE_DT_LINE_ENABLE_S;

typedef struct PU_VIM_POINT
{
    INT lPointPosX;
    INT lPointPosY;
}PU_VIM_POINT_ST;

/* 图像镜像和旋转方式 */
typedef enum VIDEO_VENC_ROTATION
{
    VIDEO_ROTATION_NORMAL = 0,               //正常图像
    VIDEO_ROTATION_MIRROR,                   //左右镜像
    VIDEO_ROTATION_FILP,                     //上下
    VIDEO_ROTATION_BOTH,                     //上下左右
    VIDEO_ROTATION_MAX
}VIDEO_VENC_ROTATION_E;

typedef struct LOCATION_INFO
{
	FLOAT fxDegree;       //球机角度
	FLOAT fyDegree;
	FLOAT fDZoomRatio;
	INT   lPOS;          //POS
	VIDEO_VENC_ROTATION_E enVideoRotation; //视频镜像模式
}LOCATION_INFO_S;

/*区域检测*/
typedef struct PU_AREA
{
	ULONG            ulIndex;
	PU_ENABLE_TYPE_E enEnable;
    ULONG            uPointNum;                      /* 区域多边形顶点数目 */
    PU_VIM_POINT_ST  stPoint[MAX_AREA_POINTS_NUM];   /*点坐标*/
    LOCATION_INFO_S  stLocation;                     //云台位置信息
    CHAR             stAreaName[IGT_AREA_NAME_LEN];  //区域名称
}PU_AREA_S;

typedef enum tagLaneDirection
{
    LANE_DIRECTION_DOWN, /* 向下运动 */
    LANE_DIRECTION_UP, /* 向上运动 */
    LANE_DIRECTION_UNDEF, /* 未定义运动方向, 无法判断逆行, 只有速度值 */
} LANE_DIRECTION_E;

typedef enum tagDirectionSignType
{
    DERICTION_TYPE_LEFT, /* 左转 */
    DERICTION_TYPE_STRAIGHT, /* 直行 */
    DERICTION_TYPE_LEFT_STRAIGHT, /* 左转直行 */
    DERICTION_TYPE_RIGHT, /* 右转 */
    DERICTION_TYPE_LEFT_RIGHT, /* 左转右转 */
    DERICTION_TYPE_RIGHT_STRAIGHT, /* 右转直行 */
    DERICTION_TYPE_LEFT_RIGHT_STRAIGHT, /* 左转右转直行 */
    DERICTION_TYPE_LEFT_STAY, /* 左转待行 */
    DERICTION_TYPE_STRAIGHT_STAY, /* 直行待行 */
    DERICTION_TYPE_RIGHT_STAY, /* 右转待行 */
    DERICTION_TYPE_BUTT
} DERICTION_SIGN_TYPE_E;

typedef enum tagITSRoadLineType
{
    ITS_ROAD_LINE_TYPE_WHITE_SOLOD,   /* 白实线 */
    ITS_ROAD_LINE_TYPE_WHITE_DOTTED,  /* 白虚线 */
    ITS_ROAD_LINE_TYPE_SINGLE_YELLOW, /* 单黄线 */
    ITS_ROAD_LINE_TYPE_DOUBLE_YELLOW, /* 双黄线 */
    ITS_ROAD_LINE_TYPE_GUARD_BAR,     /* 有护栏车道线 */
} ITS_ROAD_LINE_TYPE_E;

typedef struct tagRoadPropertyUnit
{
    PU_ITS_CAR_DRV_DIR_E  enLaneDirection; /* 车道行驶方向: 来向去向, 到画面中是向上向下 */
    PU_ITS_ROAD_DRV_DIR_E enSignDirection; /* 标志车辆行驶方向: 左右转、直行等 */
    ITS_ROAD_LINE_TYPE_E  enLineType; /* 车道线类型 */
    ITS_ROAD_SIDE_SCENE_E enLaneSideScene;   /* 车道场景类型，用于掉头违章判断 */
    PU_IMRS_LINE_S stLine; /* 车道线 */
} ROAD_PROPERTY_UNIT_S;


typedef enum tagPositionBoxType
{
    ITS_POS_BOX_TYPE_BIG,
    ITS_POS_BOX_TYPE_MID,
    ITS_POS_BOX_TYPE_SMALL
}PU_ITS_POS_BOX_TYPE_E;

typedef struct AERADTC_LIST
{
    ULONG      ulAreaNum;
    PU_AREA_S  stArea[MAX_AREA_NUM];
}AERADTC_LIST_S;

//视频电警检测线参数
typedef struct tagItsEPoliceDtLineParam
{
    PU_ITS_EPOLICE_DT_LINE_ENABLE_S     stEnableList;                   // 线参数使能表
    INT                                 iLaneNum;                       // 车道线数量
    ROAD_PROPERTY_UNIT_S                stLane[MAX_LANE_NUM];           // 车道线 = 车道数+1
    ROAD_PROPERTY_UNIT_S                stLaneRhtBorderLine;            // 车道右边界限
    INT                                 iStopNum;                       // 停止线数量
    PU_IMRS_LINE_S                      stStopLine[MAX_LANE_NUM];       // 停止线
    PU_IMRS_LINE_S                      stTripLine[MAX_LANE_NUM];       // 检测线（虚拟绊线，卡口模式过线抓拍）
    PU_IMRS_LINE_S                      stLftBorderLine;                // 左转边界线
    PU_IMRS_LINE_S                      stRhtBorderLine;                // 右转边界线
    PU_IMRS_LINE_S                      stStrightTrigger;               // 直行触发线
    PU_IMRS_LINE_S                      stRunningRedTrigger;            // 闯红灯触发线
    PU_IMRS_LINE_S                      stTurnAroundLine;               // 掉头检测线

    PU_ITS_POS_BOX_TYPE_E               enPosBoxType;                   // 定位框
    AERADTC_LIST_S                      stVLPRAreaList;                 // 最佳车牌识别区域
    AERADTC_LIST_S                      stIllegalParkAreaList;          // 黄网格区域
	AERADTC_LIST_S                      stImpolitePedestriansAreaList;  // 行人监视区
	CHAR                                aucLocalPlate[MAX_RESTRICTED_LOCALPLATE_LEN];   //优先省（市）
}PU_ITS_EPOLICE_DT_LINE_PARAM_S;

/* ITS检测线参数结构体 */
typedef struct PU_ITS_DT_LINE_PARAM
{
    ULONG                       ulChannelId;          // 通道ID
    EN_ITS_TYPE                 enITSType;            // ITS业务类型
    BOOL                        bEnable;              // ITS业务是否使能
    //【与业务结构的区别】此处取消联合体，直接定义参数结构体
    PU_ITS_EPOLICE_DT_LINE_PARAM_S  stEPolice;        // ITS视频电警检测线参数

}PU_ITS_DT_LINE_PARAM_S;


//ITS图片查询参数
typedef struct PU_ITS_SNAPSHOT_INQUIRE
{
    ULONG ulChnID;
    ULONG ulBeginIndex;		            // 当前开始记录索引(>=1)
    ULONG ulBeginTime;                  // 开始时间(time_t/localTime=GMT+时区)
    ULONG ulEndTime;                    // 结束时间
    PU_SNAPSHOT_TYPE_E enSnapShotType;  // 抓拍类型
    ULONG ulLaneID;                         // 车道号
    PU_VEHICLE_TYPE_E enVehicleType;        // 车辆类型
    PU_ITS_REGULA_TYPE_E enVehicleRegulationType;    // 违章类型
	ULONG		ulRegulationRecordTime;		//违章录像时间长度
	BOOL 		bOnceInquireFlag;	  		//单页查询标记，TRUE 表示图片查询只返回一页查询结果即可	

    CHAR szReserved[PU_RESERVE_LEN];
}PU_ITS_SNAPSHOT_INQUIRE_S;

// 红绿灯接入方式
typedef enum PU_ItS_LIGHT_DT_TYPE
{
    ITS_LIGHT_DT_TYPE_485,   // 485接入
    ITS_LIGHT_DT_TYPE_VIDEO, // 视频接入
    ITS_LIGHT_DT_TYPE_UNKNOW,
}PU_ITS_LIGHT_DT_TYPE_S;



// 信号灯导向
typedef struct PU_ITS_LIGHT_DIR
{
    BOOL bLeft;         // 左转
    BOOL bStraight;     // 直行
    BOOL bRight;        // 右转
}PU_ITS_LIGHT_DIR_S;
// 信号灯颜色
typedef struct PU_ITS_LIGHT_COLOR
{
    BOOL bRed;          // 红灯
    BOOL bGreen;        // 绿灯
    BOOL bYellow;       // 黄灯
}PU_ITS_LIGHT_COLOR_S;
// 信号灯方式方式
typedef enum PU_ITS_LIGHT_ARRANGE_TYPE
{
    ITS_LIGHT_ARRANGE_TYPE_BROADWISE, /* 横向 */
    ITS_LIGHT_ARRANGE_TYPE_ENDWISE,   /* 纵向 */
    ITS_LIGHT_ARRANGE_TYPE_UNKOWN,
} PU_ITS_LIGHT_ARRANGE_TYPE_E;

/**************区域********************/
typedef struct PU_MD_AREA
{
	FLOAT  fX1;
	FLOAT  fY1;
	FLOAT  fX2;
	FLOAT  fY2;
}PU_MD_AREA_S;
// 信号灯区域参数
typedef struct PU_ITS_SIGNAL_LIGHT_AREA_PARAM
{
    PU_ITS_LIGHT_DIR_S             stLightDir;         // 信号灯导向
    PU_ITS_LIGHT_COLOR_S           stLightColor;       // 信号灯颜色
    INT                       iLightNum;          // 灯个数
    PU_ITS_LIGHT_ARRANGE_TYPE_E    enLightArrangeType; // 信号灯安装方式
    INT                       iYellowTime;        // 黄灯持续时间
    PU_MD_AREA_S                   stLightArea;        // 信号灯位置框
    CHAR    szReserve[PU_RESERVE_LEN];  //szReserve[0]: 绘制的使能标志，szReserve[1]: 选择的使能标志
}PU_ITS_SIGNAL_LIGHT_AREA_PARAM_S;


// 电警信号灯参数
typedef struct PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM
{
    ULONG                              ulChannelId;                                       // 通道ID
    PU_ITS_LIGHT_DT_TYPE_S              enLightDtType;                                     // 红绿灯检测接入方式
    INT                              iSignalLightAreaNum;                               // 信号灯区域个数
    PU_ITS_SIGNAL_LIGHT_AREA_PARAM_S    astSignalLightList[PU_ITS_MAX_LIGHTAREA_NUM];         // 信号灯参数
    CHAR    szReserve[PU_RESERVE_LEN];
}PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM_S;

//视频电警模拟红绿灯参数
typedef struct PU_ITS_SIM_TRAFFIC_LIGHT_PARAM
{
    ULONG                              ulChannelId;                    // 通道ID
    BOOL                                bLeftTurn;                      // 左转信号灯
    BOOL                                bRightTurn;                     // 右转信号灯
    BOOL                                bGoStraight;                    // 直行信号灯
    CHAR                               szReserve[PU_RESERVE_LEN];
}PU_ITS_SIM_TRAFFIC_LIGHT_PARAM_S;

/* 单个违法字典中的违法类型 */
typedef struct PU_ITS_ILLEGAI_DIC_PARA_UNIT
{
    CHAR szIllTypeString[PU_ITS_ILLEGAL_TYPE_LEN_MAX];       // 违法类型，修改无效,最大长度PU_ITS_ILLEGAL_TYPE_LEN_MAX - 4
    CHAR szIllCodeString[PU_ITS_ILLEGAL_NUM_LEN_MAX];        // 违法代码，最大长度PU_ITS_ILLEGAL_NUM_LEN_MAX - 1
    CHAR szIllNameString[PU_ITS_ILLEGAL_NAME_LEN_MAX];       // 违法叠加名称，最大长度PU_ITS_ILLEGAL_NAME_LEN_MAX - 4
}PU_ITS_ILLEGAI_DIC_PARA_UNIT_S;

/* 违法字典参数 */
typedef struct PU_ITS_ILLEGAI_DIC_PARA
{
   ULONG ulChannelID;                   //通道ID
   PU_LANGUAGE_TYPE_E enLanguageType;   //语言，获取参数时候使用
   ULONG ulIllegalNum;                  // 违法字典项数
   PU_ITS_ILLEGAI_DIC_PARA_UNIT_S astIllegals[PU_ITS_ILLEGAL_TYPE_NUM_MAX];   //违法项
   CHAR  szReserve[PU_RESERVE_LEN];
}PU_ITS_ILLEGAI_DIC_PARAM_S;

/*************begin:交通球机**************/
// 抓拍图片类型
typedef enum PU_IBALL_FRAME_TYPE
{
    PU_IBALL_FRAME_TYPE_FAR=0,   //远景图
    PU_IBALL_FRAME_TYPE_NEAR,    //近景图
    PU_IBALL_FRAME_TYPE_FEATURE, //特征图
    PU_IBALL_FRAME_TYPE_MAX
}PU_IBALL_FRAME_TYPE_E;

// 交通球机违法停车类型
typedef enum PU_TD_ILLEGAL_TYPE
{
    TDOME_ILLEGAL_TYPE_A = 0, //机动车违反规定停放
    TDOME_ILLEGAL_TYPE_B,     //机动车违反禁停标志
    TDOME_ILLEGAL_TYPE_C,     //非紧急情况高速应急车道或行车道停车
    TDOME_ILLEGAL_TYPE_D,     //未使用
    TDOME_ILLEGAL_TYPE_MAX
}PU_TD_ILLEGAL_TYPE_E;

// 交通球机算法参数
typedef struct PU_TD_ALG_PARAMS
{
    ULONG   ulChannelId;         // 通道ID
    BOOL    bEnable;             // 算法使能
    ULONG   ulFilterThreshold;   // 违章过滤阈值，单位:分钟，范围:1-1440
    LONG    lPTZCalibrationHorizontal;  // 云台校准参数(水平)，范围:-2 - 2
    LONG    lPTZCalibrationVertical;    // 云台校准参数(垂直)，范围:-2 - 2
    BOOL    bRecordEnable;              //录像功能使能
    PU_TD_ILLEGAL_TYPE_E enIllegalType; // 违法停车类型
    CHAR    szReserve[PU_RESERVE_LEN];
}PU_TD_ALG_PARAMS_S;

// 交通球机算法参数
typedef struct PU_TD_ALG_PARAMSV2
{
    ULONG   ulChannelId;         // 通道ID
    BOOL    bEnable;             // 算法使能
    CHAR    szReserve[PU_RESERVE_LEN];
}PU_TD_ALG_PARAMSV2_S;

// 交通球机手动检测屏幕位置
typedef struct PU_TD_MANUAL_DETECTION_POSITION
{
    ULONG          ulChannelId;    // 通道ID
    PU_RECTANGLE_S stRectArea;     // 手动框矩形位置，355*288坐标系  
    CHAR           szReserve[PU_RESERVE_LEN];
}PU_TD_MANUAL_DETECTION_POS_S;

// 交通球机定时锁定参数
typedef struct PU_TD_TIMING_LOCK_PARAMS
{
    BOOL bEnable;  //使能
	CHAR szReserve[PU_RESERVE_LEN];
}PU_TD_TIMING_LOCK_PARAMS_S;

// 交通球机解锁参数
typedef struct PU_TD_UNLOCK_PARAMS_S
{
    BOOL bEnable;  //使能
	CHAR szReserve[PU_RESERVE_LEN];
}PU_TD_UNLOCK_PARAMS_S;

// 交通球机转动到场景参数
typedef struct PU_TD_SCENE_MOVE_TO_SCENE
{
    ULONG ulChannelId;    // 通道ID
    ULONG ulIndex;        // 场景编号
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_TD_SCENE_MOVE_TO_SCENE_S;

// 违停检测抓拍规则
typedef struct PU_TD_ILLEGAL_PARKINK_SNAP_RULE
{
    ULONG                   ulFrameNum;                          // 抓拍数量
    PU_IBALL_FRAME_TYPE_E   enFrameType[TD_MAX_SNAP_FRAME_NUM];  // 抓拍图片类型
    ULONG                   ulInterval[TD_MAX_SNAP_FRAME_NUM];   // 抓拍间隔
}PU_TD_ILLEGAL_PARKINK_SNAP_RULE_S;

// 违停检测参数 
typedef struct PU_TD_ILLEGAL_PARKINK_PARAMS
{
    BOOL    bEnable;                                        // 违停检测使能
    BOOL    abRelatedLane[MAX_LANE_NUM];                    // 关联车道
    ULONG   ulDetectInterval;                               // 检测间隔(目前用来代替抓拍规则)
    PU_TD_ILLEGAL_PARKINK_SNAP_RULE_S stSnapRules;          // 抓拍规则
}PU_TD_ILLEGAL_PARKINK_PARAMS_S;

// 交通球机手动违停检测算法参数
typedef struct PU_TD_MANUAL_DETECTION_PARAMS
{
    ULONG   ulChannelId;                              // 通道ID
    PU_TD_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;  // 违停检测参数
}PU_TD_MANUAL_DETECTION_PARAMS_S;

// 循环模式
typedef enum PU_CYCLIC_MODE
{
    PU_E_NOT_CYCLIC = 0, // 不循环
    PU_E_WEEK_CYCLIC,    // 周循环
}PU_CYCLIC_MODE_E;

// 巡航模式
typedef enum PU_TOUR_MODE
{
    PU_E_DETECT_PRIORITY = 0, // 检测优先
    PU_E_SCENE_PRIORITY,      // 场景优先
}PU_TOUR_MODE_E;

//巡航轨迹点
typedef struct PU_TD_TOUR_TRACK_POINT_PARAMS
{
    ULONG ulIndex;        // 场景编号, 与场景配置里的场景选择ID 一致
    ULONG ulStayDruation; //场景停留时间(分钟)
}PU_TD_TOUR_TRACK_POINT_PARAMS_S;

//每天巡航计划参数
typedef struct PU_TD_TOUR_PLAN_ONE_DAY_PARAMS
{
    ULONG  ulBeginTime;        // 巡航开始时间(分钟)
    ULONG  ulEndTime;          // 巡航结束时间 (分钟)
    ULONG  ulSceneNum;         //每天巡航计划包含的巡航轨迹点个数
    PU_TD_TOUR_TRACK_POINT_PARAMS_S stTourTrackPoint[TD_MAX_SCENE_NUM];//每天巡航计划
}PU_TD_TOUR_PLAN_ONE_DAY_PARAMS_S;

//交通球机巡航计划参数
typedef struct PU_TD_TOUR_PLAN_PARAMS
{
    ULONG ulChannelId;             // 通道ID
    BOOL  bTourPlanEnable;         //巡航计划使能
    PU_CYCLIC_MODE_E enCyclicMode; //循环模式
    PU_TOUR_MODE_E enTourMode;     //巡航模式
    PU_TD_TOUR_PLAN_ONE_DAY_PARAMS_S  stTourPlanDay[TD_MAX_DAY_ONE_WEEK];   // 巡航计划参数
}PU_TD_TOUR_PLAN_PARAMS_S;

// 交通球机检测线使能
typedef struct PU_TD_DTLINE_ENABLE
{
    BOOL abRoadLane[MAX_LANE_NUM];  // 车道线使能
    BOOL bLaneRhtBorderLine;        // 车道右边界限
}PU_TD_DTLINE_ENABLE_S;

// 交通球机检测线使能
typedef struct PU_TD_DTLINE_ENABLEV2
{
    BOOL abRoadLane[TDOME_MAX_LANE_NUM];  // 车道线使能
    BOOL bLaneRhtBorderLine;        // 车道右边界限
}PU_TD_DTLINE_ENABLEV2_S;

// 交通球机车道参数
typedef struct PU_TD_LINE_PARAM
{
    ULONG                 ulLaneNum;             // 车道线数量
    PU_TD_DTLINE_ENABLE_S stEnableList;          // 线参数使能表
    ROAD_PROPERTY_UNIT_S  stLane[MAX_LANE_NUM];  // 车道线 = 车道数+1
    ROAD_PROPERTY_UNIT_S  stLaneRhtBorderLine;   // 车道右边界限
}PU_TD_LINE_PARAM_S;


// 交通球机车道参数
typedef struct PU_TD_LINE_PARAMV2
{
    ULONG                 ulLaneNum;             // 车道线数量
    PU_TD_DTLINE_ENABLEV2_S stEnableList;          // 线参数使能表
    ROAD_PROPERTY_UNIT_S  stLane[TDOME_MAX_LANE_NUM];  // 车道线 = 车道数+1
    ROAD_PROPERTY_UNIT_S  stLaneRhtBorderLine;   // 车道右边界限
}PU_TD_LINE_PARAMV2_S;


// 交通球机场景应用参数
typedef struct PU_TD_SCENE_APP_PARAMS
{
    ULONG  ulChannelId;    // 通道ID
    ULONG  ulIndex;        // 场景编号
    PU_TD_LINE_PARAM_S             stLaneLine;         // 车道线参数
    PU_TD_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;   // 违停检测参数
}PU_TD_SCENE_APP_PARAMS_S;

typedef struct PU_TD_MD_AREA
{
	ULONG  ulX1;
	ULONG  ulY1;
	ULONG  ulX2;
	ULONG  ulY2;
}PU_TD_MD_AREA_S;

//交通球手动跟踪取证目标信息
typedef struct PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_TARGET
{
    ULONG      ulChannelId;    // 通道ID 
    ULONG      ulObjID;       // 机非人目标ID
    PU_TD_MD_AREA_S   stRectArea;     // 目标框矩形位置  
}PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_TARGET_S;

// 交通球手动跟踪取证开关
typedef struct PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_SWITCH
{
    ULONG      ulChannelId;    // 通道ID 
    BOOL       bEnable;        // 打开或关闭
}PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_SWITCH_S;

// 图片叠加智能信息
typedef struct PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO
{
    BOOL bNearSnapAddTargetInfoFlag;              // 报警抓图叠加目标信息
    BOOL bNearSnapAddRuleInfoFlag;                  // 报警抓图叠加规则信息
    BOOL bFarSnapAddTargetInfoFlag;                 // 远景图叠加目标信息
    BOOL bFarSnapAddRuleInfoFlag;                    // 远景图叠加规则信息
}PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO_S;


// 交通球违章智能分析参数
typedef struct PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS
{
    ULONG ulChannelId;    // 通道ID 
    CHAR  szPlateLocalZH[MAX_PLATE_LOCAL_ZH_LEN]; // 优先城市类型
    PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO_S stOverlayIntelInfo; // 图片叠加智能信息
    BOOL bPlateSmallPic; // 车牌小图，默认FALSE
    BOOL bEventUploadFlag;                           // 违章事件数据上传    默认TRUE
    BOOL bEvidenceUploadFlag;                       // 违章取证数据上传   默认TRUE
    ULONG  ulFilterThreshold;   // 违章过滤阈值            默认是最大值    
    LONGLONG   lPTZCalibrationHorizontal;  // 云台校准参数(水平)
    LONGLONG   lPTZCalibrationVertical;    // 云台校准参数(垂直)
    PU_TD_ILLEGAL_TYPE_E enIllegalType; // 违法停车类型
    BOOL bRecordEnable;              // 录像功能使能      默认是FALSE
} PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS_S;

// 交通球机应用参数 - 违停检测
typedef struct PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG  ulSnapFrameNum;                             // 抓拍数量
    ULONG ulSensitivity;                                   // 灵敏度
    ULONG ulContinuousDuration;                     // 持续时间
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
    ULONG  ulDetectInterval;                               // 检测间隔(目前用来代替抓拍规则)
    PU_TD_ILLEGAL_PARKINK_SNAP_RULE_S stSnapRules;  // V2接口已弃用结构体，不必填写    
}PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S;

// 交通球机手动违停检测算法参数
typedef struct PU_TD_MANUAL_DETECTION_PARAMSV2
{
    ULONG   ulChannelId;                              // 通道ID
    INT     iVersion; /*接口版本号，用户不必填写*/
    PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;
}PU_TD_MANUAL_DETECTION_PARAMSV2_S;


// 交通球机手动违停检测算法参数
typedef struct tagTRAFFIC_DOME_MANUAL_DETECTION_PARAMS_S
{
    ULONG  ulChannelId;    // 通道ID
    PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S     stIllegalParking;
}PU_TD_TRAFFIC_DOME_MANUAL_DETECTION_PARAMS_S;


// ===Begin 交通球机场景应用参数===
// 交通球机应用参数 - 违停检测
// TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S

// 交通球机应用参数- 逆行检测
typedef struct PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG  ulSnapFrameNum;                         // 抓拍数量
    ULONG ulSensitivity;                                   // 灵敏度    
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
}PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS_S;

// 交通球机应用参数- 掉头检测
typedef struct PU_TD_TRAFFIC_DOME_U_TURN_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG  ulSnapFrameNum;                         // 抓拍数量
    ULONG ulSensitivity;                                   // 灵敏度    
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
}PU_TD_TRAFFIC_DOME_U_TURN_PARAMS_S;

// 交通球机应用参数- 压线检测
typedef struct PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG  ulSnapFrameNum;                         // 抓拍数量
    ULONG ulSensitivity;                                   // 灵敏度    
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
}PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS_S;

// 交通球机应用参数- 变道检测
typedef struct PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG  ulSnapFrameNum;                         // 抓拍数量
    ULONG ulSensitivity;                                   // 灵敏度    
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
}PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS_S;

// 交通球机应用参数- 机占非检测
typedef struct PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG  ulSnapFrameNum;                         // 抓拍数量
    ULONG ulSensitivity;                                   // 灵敏度    
    ULONG ulContinuousDuration;                     // 持续时间    
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
}PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS_S;

// 交通球机应用参数 - 违章取证
typedef struct PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS
{
    PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S stIllegalParkingParams;   // 违停检测参数
    PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS_S stRevDirectParams;   // 逆行检测抓拍规则
    PU_TD_TRAFFIC_DOME_U_TURN_PARAMS_S stUTurnParams;   // 违法掉头抓拍规则
    PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS_S stOverLaneLineParams;   // 压线检测抓拍规则
    PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS_S stChangeLaneParams;   // 违法变道抓拍规则    
    PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS_S stMiBLaneParams;   // 机占非抓拍规则
}PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS_S;

// 交通球机应用参数- 交通事件行人检测参数
typedef struct PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG ulSensitivity;                                   // 灵敏度   
    ULONG ulContinuousDuration;                     // 持续时间        
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
}PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS_S;

// 交通球机应用参数- 交通事件拥堵检测参数
typedef struct PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG ulSensitivity;                                   // 灵敏度   
    ULONG ulContinuousDuration;                     // 持续时间        
    ULONG  ulFilterDuration;                             // 过滤时间
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
}PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS_S;

// 交通球机应用参数 - 交通事件
typedef struct PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS
{
    PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS_S stPedDtParams; // 行人检测
    PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS_S stCongestionDtParams; // 拥堵检测
}PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS_S;

// 交通球机应用参数 - 交通数据采集
typedef struct PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS
{
    BOOL    bEnable;                                        // 检测使能
    ULONG ulStatisticsInterval;                         // 统计间隔
    BOOL    abRelatedLane[TDOME_MAX_LANE_NUM];  // 关联车道
}PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS_S;




// 交通球机场景应用参数
typedef struct PU_TD_SCENE_APP_PARAMSV2
{
    ULONG  ulChannelId;    // 通道ID
    ULONG  ulIndex;        // 场景编号
    PU_TD_LINE_PARAMV2_S             stLaneLine;         // 车道线参数
    PU_TD_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;   // 不使用，主要考虑兼容老设备使用
    PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS_S stIllegalEviParams; // 违章取证参数
    PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS_S stTrafficEventParams; // 交通事件参数
    PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS_S stTrafficDataCollectParams; // 交通数据采集参数
}PU_TD_SCENE_APP_PARAMSV2_S;


// 交通球机场景方向
typedef enum PU_TD_SCENE_DIRECTION
{
    PU_TD_SCENE_DIRECTION_SINGLE = 0,   //单向
    PU_TD_SCENE_DIRECTION_DOUBLE,       //双向
    PU_TD_SCENE_DIRECTION_MAX
}PU_TD_SCENE_DIRECTION_E;

// 交通球机场景基础参数
typedef struct PU_TD_SCENE_BASE_PARAMS
{
    ULONG   ulChannelId;                         // 通道ID
    ULONG   ulIndex;                             // 场景编号
    BOOL    bEnable;                             // 场景使能
    PU_TD_SCENE_DIRECTION_E enDirection;         // 场景方向
    CHAR    szSceneName[TD_MAX_STRING_LENGTH];   // 场景名称
    CHAR    szSceneSite[TD_MAX_STRING_LENGTH];   // 场景位置描述
    PU_PTZ_CURRENT_LOCATION_EX_S stPtzLocation;  // 云台位置信息
}PU_TD_SCENE_BASE_PARAMS_S;

//交通球机场景使能信息
typedef struct PU_TD_SCENE_ENABLE_INFO
{
    ULONG  ulChannelId;                         // 通道ID
    BOOL   abSceneEnable[TD_MAX_SCENE_NUM];     //场景使能
    CHAR   szSceneName[TD_MAX_SCENE_NUM][TD_MAX_STRING_LENGTH];   // 场景名称
}PU_TD_SCENE_ENABLE_INFO_S;

/*************end:交通球机**************/

/*************begin:多机协同**************/
typedef enum PU_AI_LEVEL
{
    PU_AI_LEVEL_ONLY = 0, 
    PU_AI_LEVEL_PU_PU,    //多机协作
    //PU_AI_LEVEL_CLOUD,    //全网智能
}PU_AI_LEVEL_E;

// 多机协同类型
typedef enum PU_MMC_TYPE
{
    PU_MMC_FACE_RECOG = 0,
    //MMC_XXX_RECOG, // 扩展使用
    PU_MMC_MAX,
}PU_MMC_TYPE_E;

//多机协同名称
typedef enum PU_AI_NAME 
{
    PU_PU_AI_SUBS = 0,   //订阅接口，针对入口IPC调用
    PU_PU_AI_TRANS_DATA, //转发接口
}PU_AI_NAME_E;
//多机协同数据转发
typedef struct PU_PU_AI_TRANS_DATA_PARAM {
    VOID* pucData;  
    UINT  uiLen;   //数据的长度
}PU_PU_AI_TRANS_DATA_PARAM_S, *LPPU_PU_AI_TRANS_DATA_PARAM_S;

typedef LONG(CALLBACK *pfGetPuPuInfoCallBack)(ULONG ulIdentifyID,const PU_PU_AI_TRANS_DATA_PARAM_S * pstTransData,VOID* ctx);
//多机协同订阅参数
typedef struct PU_PU_AI_SUBS_PARAM 
{
    ULONG     ulChannelId;
    PU_MMC_TYPE_E enMMCType;               // 多机协同类型(目前只支持人脸识别) 人脸识别=0
    ULONG     ulComparisonNumMax;          // 黑名单比对人数
    ULONG     ulRecallRateWarningMax;      // 召回率告警值
    ULONG     ulRecallRateWarningMin;      // 召回率预警下限值
    ULONG     ulCacheDuration;             // 广播的黑名单库在备IPC的缓存时长(单位:分钟，默认值是60分钟，取值范围10 - 240)
    BOOL      bOnOff; //关闭此功能
    pfGetPuPuInfoCallBack puCallBack;
    void*      pUsrData;
}PU_PU_AI_SUBS_PARAM_S, *LPPU_PU_AI_SUBS_PARAM_S;

/*************end:多机协同**************/

/******************排队长度算法参数结构体********************************/
typedef struct PU_ITGT_QUEUEDETECT_ALG_PARAM
{
    PU_ENABLE_TYPE_E enEnable;             // 算法使能
    ULONG            ulTimeThreshold;      // 排队时长告警阈值
    ULONG            ulAlarmTime;          // 告警上报间隔
    ULONG            ulSensitivity;        // 检测阈值(1-5)
    ULONG            ulAverTimePerCapita;  // 单人出队列平均时长
    CHAR  szReserve[PU_RESERVE_LEN];         //后续可能新增方向等参数
} PU_ITGT_QUEUEDETECT_ALG_PARAM_S;


/******************排队长度消息结构体****************************************/
typedef struct PU_ITGT_QUEUE_DETECT_PARAM
{
    ULONG                           ulChannelId;    // 通道ID
    PU_ITGT_QUEUEDETECT_ALG_PARAM_S stAlgParams;    // 排队长度算法参数
    PU_IGT_AERADTC_LIST_S           stAreaList;     // 排队长度检测区域
    PU_ALARM_TIME_LIST_S            stGuardPlan;    // 布防计划
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_ITGT_QUEUE_DETECT_PARAM_S;

//交通拥堵参数结构体
typedef struct PU_VLPR_TRAFFIC_CONGESTION_PARA
{
	ULONG                          ulChannelId;    			// 通道ID
	PU_ENABLE_TYPE_E    		   enEnable;				// 使能
	ULONG           			   ulAlarmTime;        		// 告警上报间隔
	PU_ALARM_TIME_LIST_S           stGuardPlan;    			// 布防计划
	CHAR  szReserve[PU_RESERVE_LEN];
}PU_VLPR_TRAFFIC_CONGESTION_PARA_S;

/******************交通拥堵算法参数结构体********************************/
typedef struct PU_ITGT_TRAFFIC_CONGESTION_ALG_PARAM
{
	PU_ENABLE_TYPE_E     enEnable;             // 算法使能
	ULONG            ulAlarmTime;          // 告警上报间隔
}PU_ITGT_TRAFFIC_CONGESTION_PARAM_S;

typedef struct PU_ITS_TRAFFIC_CONGESTION_PARAM
{
	ULONG                                ulChannelId;   //通道ID
	PU_ITGT_TRAFFIC_CONGESTION_PARAM_S   stAlgParams;   //算法参数
	PU_ALARM_TIME_LIST_S                 stGuardPlan;   //布防计划
	CHAR  szReserve[PU_RESERVE_LEN];
}PU_ITS_TRAFFIC_CONGESTION_PARAM_S;

/******************人群密度算法参数结构体********************************/
typedef struct PU_ITGT_CROWD_DENSITY_DETECT_ALG_PARAM
{
    PU_ENABLE_TYPE_E enEnable;             // 算法使能
    ULONG            fPeopleNumThreshold;  // 人数上限阈值
    ULONG            ulAlarmTime;          // 告警上报间隔
    ULONG            ulSensitivity;        //检测阈值(1-5)
    CHAR  szReserve[PU_RESERVE_LEN];
} PU_ITGT_CROWD_DENSITY_DETECT_ALG_PARAM_S;

/******************人群密度消息结构体****************************************/
typedef struct PU_ITGT_CROWD_DENSITY_DETECT_PARAM
{
    ULONG                                    ulChannelId;    // 通道ID
    PU_ITGT_CROWD_DENSITY_DETECT_ALG_PARAM_S stAlgParams;    // 人群密度算法参数
    PU_IGT_AERADTC_LIST_S                    stAreaList;     // 人群密度检测区域
    PU_ALARM_TIME_LIST_S                     stGuardPlan;    // 布防计划
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_ITGT_CROWD_DENSITY_DETECT_PARAM_S;

/********** BEGIN: ITS外设参数 **********/
//波特率
typedef enum
{
    ITS_RS_BAUD_B2400 = 0,
    ITS_RS_BAUD_B4800,
    ITS_RS_BAUD_B9600,
    ITS_RS_BAUD_B19200,
    ITS_RS_BAUD_B38400,
    ITS_RS_BAUD_B57600,
    ITS_RS_BAUD_B115200,
    ITS_RS_BAUD_B230400,
    ITS_RS_BAUD_B460800,
    ITS_RS_BAUD_B921600,
    ITS_RS_BAUD_MAX,
} PU_ITS_RS_BAUD_E;

//数据位
typedef enum {
    ITS_RS_CSIZE_CS5 = 0,
    ITS_RS_CSIZE_CS6,
    ITS_RS_CSIZE_CS7,
    ITS_RS_CSIZE_CS8,
    ITS_RS_CSIZE_MAX
} PU_ITS_RS_CSIZE_E;

//停止位
typedef enum {
    ITS_RS_STOPBIT_ONE = 0,
    ITS_RS_STOPBIT_TWO,
    ITS_RS_STOPBIT_MAX
} PU_ITS_RS_STOPBIT_E;

//奇偶校验位
typedef enum {
    ITS_RS_PARITY_NONE = 0,
    ITS_RS_PARITY_ODD,
    ITS_RS_PARITY_EVEN,
    ITS_RS_PARITY_MARK,
    ITS_RS_PARITY_SPACE,
    ITS_RS_PARITY_MAX
} PU_ITS_RS_PARITY_E;

//流控
typedef enum {
    ITS_RS_FLOWCTL_NONE = 0,
    ITS_RS_FLOWCTL_SW,
    ITS_RS_FLOWCTL_HW,
    ITS_RS_FLOWCTL_MAX
} PU_ITS_RS_FLOWCTL_E;

//串口参数结构体
typedef struct
{
    PU_ITS_RS_BAUD_E RS485Baud;
    PU_ITS_RS_CSIZE_E RS485CSize;
    PU_ITS_RS_STOPBIT_E RS485StopBit;
    PU_ITS_RS_PARITY_E RS485Parity;
    PU_ITS_RS_FLOWCTL_E RS485FlowCtl;
} PU_ITS_RS_PARA_S;

//设备类型
typedef enum
{
     EP_VIDEO_MODE= 0,      //视频电警
     GT_VIDEO_MODE,          //视频卡口
     ITS_MODE_MAX
} PU_DEVICE_MODE_E;

//外设大类型
typedef enum
{
     ITS_DEVICE_NONE,               //无外设
     ITS_DEVICE_RADAR,              //雷达外设
     ITS_DEVICE_VEHICLE,            //车检外设
     ITS_DEVICE_IO,                 //IO外设
} PU_ITS_EXTRA_DEVICE_TYPE_E;

//IO触发方式
typedef enum
{
     DEVICE_IO_NONE,                //不触发
     DEVICE_IO_RISE,                //上升沿触发
     DEVICE_IO_DOWN,                //下降沿触发
     DEVICE_IO_BOTH,                //都触发
} PU_DEVICE_IO_TYPE_E;

//检测器外设的类型
typedef enum
{
    ITS_EQUIP_TYPE_INVALID = 0,

    ITS_EQUIP_RS485_RADAR_CSR_1K,       //北京川速公司的CSR-IK单车道雷达
    ITS_EQUIP_RS485_RADAR_CSR_IN,       //北京川速公司的CSR-IN单车道雷达
    ITS_EQUIP_RS485_RADAR_CSR_IM,       //北京川速公司的CSR-IM多车道雷达
    ITS_EQUIP_RS485_RADAR_MPR_LV,       //上海慧昌公司的MPR-LV流量雷达

    ITS_EQUIP_RS485_COIL_TULI_PK600K = 100,   //上海图立公司的线圈车检器

    ITS_EQUIP_RS485_LIGHT_DTOR_TL01 = 200,    //北京信路威公司的红绿灯检测器

    ITS_EQUIP_IO                    = 300,    //IO协议

    ITS_EQUIP_TYPE_MAX
}PU_EXTRA_DEVICE_TYPE_E;

//串口号
typedef enum
{
    SERIAL_PORT_485_1 = 0,    //485-1
    SERIAL_PORT_232_1,        //485-2
    SERIAL_PORT_485_2,        //232-1
    SERIAL_PORT_485_3,        //485-3
    ITS_SERIAL_PORT_MAX = 255    //串口无
}PU_ITS_SERIAL_PORT_E;

//雷达信息的发送方式
typedef enum
{
    ITS_RADAR_MSG_SEND_SINGLE,      //单次发送(有车经过将上报消息)
    ITS_RADAR_MSG_SEND_CONTINOUS,   //连续发送(无论是否有车，都上报消息)
    ITS_RADAR_MSG_SEND_MANUAL,      //手工查询模式(查询一次，给一次消息)

    ITS_RADAR_MSG_SENDTYPE_MAX
}PU_ITS_RADAR_MSG_SENDTYPE_E;

//雷达类型
typedef enum
{
    ITS_RADAR_TYPE_SINGLE_DIR_DETECT, //单向探测
    ITS_RADAR_TYPE_DOUBLE_DIR_DETECT, //双向探测

    ITS_RADAR_TYPE_MAX
}PU_ITS_RADAR_WORK_TYPE_E;


//雷达监测方向
typedef enum
{
    ITS_DETECT_DIR_UNKNOWN = 0,
    ITS_DETECT_DIR_COMING,  //来向
    ITS_DETECT_DIR_GOING,   //去向
    ITS_DETECT_DIR_BOTH,    //双向
}PU_ITS_DETECT_DIR_E;

/* 线圈抓拍方案*/
typedef enum
{
    ITS_COIL_SNAP_SINGLE_NONE = 0,               //不抓拍
    ITS_COIL_SNAP_SINGLE_IN1,                    //单_入1抓拍
    ITS_COIL_SNAP_SINGLE_OUT1,                   //单_出1抓拍
    ITS_COIL_SNAP_DOUBLE_HEAD_IN2 = 21,          //双_车头_入2抓拍
    ITS_COIL_SNAP_DOUBLE_TAIL_OUT1_IN2,          //双_车尾_出1入2抓拍
    ITS_COIL_SNAP_DOUBLE_TAIL_OUT2,              //双_车尾_出2抓拍
    ITS_COIL_SNAP_TRIPLE_HEAD_IN3,               //三_车头_入3抓拍
    ITS_COIL_SNAP_TRIPLE_TAIL_OUT2_IN3,          //三_车尾_出2入3抓拍
    ITS_COIL_SNAP_TRIPLE_TAIL_OUT3,              //三_车尾_出3抓拍

    ITS_COIL_SNAP_DOUBLE_OUT1_OUT2_OUT2DELAY = 41,    //双_出1_出2_出2延时抓拍
    ITS_COIL_SNAP_DOUBLE_IN1_OUT2_OUT2DELAY,     //双_入1_出2_出2延时抓拍
    ITS_COIL_SNAP_DOUBLE_IN2_OUT2_OUT2DELAY,     //双_入2_出2_出2延时抓拍
    ITS_COIL_SNAP_TRIPLE_OUT1_OUT2_OUT3,         //三_出1_出2_出3抓拍
    ITS_COIL_SNAP_TRIPLE_OUT1_OUT2_OUT3DELAY,    //三_出1_出2_出3延时抓拍

    ITS_COIL_SNAP_TYPE_MAX
}PU_ITS_COIL_SNAP_TYPE_E;

//一机多用
typedef enum PU_ITGT_MODE
{
    COMMON_MODE           = 0,  //普通摄像机模式
    FACE_DETECTION_MODE   = 1,  //人脸检测模式/C30人卡模式
    FACE_RECOGNITION_MODE = 2,  //人脸识别模式
    BAYONET_MODE          = 3,  //微卡口模式
    MOTOR_DETECTION_MODE  = 4,  //机非人模式/C30微卡模式
    ITS_MODE              = 5,  //ITS模式
    VHD_FACE_MODE         = 6,  //一机多用(机非人+ 人脸检测)/C30混行模式
    BA_MODE               = 7,  //行为分析模式/C30新增
    CLOSE_ALG_MODE            = 8,  //一拖N，全去使能模式
    ITS_EPOLICE_SINGLE_PIPE   = 9,  //ITS电警单路流模式
    ITS_EPOLICE_DOUBLE_PIPE   = 10, //ITS电警双路流模式
    ITS_TGATEWAY_SINGLE_PIPE  = 11, //ITS卡口单路流模式
    ITS_TGATEWAY_DOUBLE_PIPE  = 12, //ITS卡口双路流模式
}PU_ITGE_MODE_E;

typedef struct PU_ITGT_MODE_E
{
    PU_ITGE_MODE_E  enITGEMode;
    ULONG ulChannelId;   //通道ID
    CHAR  szReserve[PU_RESERVE_LEN-sizeof(ULONG)];
}PU_ITGT_MODE_S;


//川速雷达的配置
typedef struct PU_RADA_PARA_CHUANSU
{
    PU_ITS_RADAR_WORK_TYPE_E           enRadarWorkType;                         //雷达工作类型
    PU_ITS_RADAR_MSG_SENDTYPE_E        enMsgSendType;                           //雷达信息发送方式
    PU_ITS_DETECT_DIR_E                enDetectDir;                             //探测方向
    ULONG                          uiFixedAngle;                            //修正角度, 如果雷达测速和实际速度不一致，需要修正角度
    ULONG                          uiSensitivity;                           //雷达灵敏度
    ULONG                          uiTrigMinInterval;                       //触发的最小距离
    ULONG                          uiTrigMinSpeed;                          //触发的最小速度，车速低于下限将不会触发
    ULONG                          uiHardwareHeight;                        //安装高度
}PU_RADA_PARA_CHUANSU_S;

//川速多车道雷达的配置
typedef struct PU_ITS_RADA_CTRL_CSRIM
{
    PU_ITS_SERIAL_PORT_E  enSerialPortId;                         //串口号
    ULONG                          uiRoadEnable;                       //车道是否使能
    ULONG                          uiLaneId;                           //道路ID，使用bitmap 0位置1表示1车道使能，以此类推
    ULONG                          uiLaneIdBase;                       //起始车道编号
    ULONG                          uiLaneNum;                          //车道个数
    ULONG                          uiLaneWidth[4];       //车道宽度，WEB配置使用cm，驱动转换成米
    ULONG                          uiTrigMinInterval;                  //触发的最小距离，WEB配置使用cm，驱动转换成米
    ULONG                          uiInstallHeight;                    //安装高度， WEB配置使用cm，驱动转换成米
    LONG                           iInstallHOffset;                    //雷达距离车道中心点的偏移, WEB配置使用cm，驱动转换成米
                                                                        //使用雷达照射方向的视角，在中心点的左边，偏移为负整数，反之为正整数
    LONG                           iDeflectionAngle;                   //雷达照射方向和车道之间的偏转角度
                                                                        //照射方向向左偏移，则值为负整数，反之为正整数
    ULONG                          uiSensitivity;                      //雷达灵敏度
    ULONG                          uiSensitiveBase;                    //雷达灵敏度的基数
    ULONG                          uiTrigMinSpeed;                     //测速下限，车速低于下限将不会触发(km/h)
    ULONG                          uiTrigMaxSpeed;                     //测速上限，车速高于上限将按照上限速度报告
    PU_ITS_DETECT_DIR_E                eDetectDir;                         //探测方向过滤
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_ITS_RADA_CTRL_CSRIM_S;

//信路威TL-01-8红绿灯信号检测器
typedef struct PU_ITS_XLW_DETECTOR_INFO
{
    ULONG                          uiTotalNum;                             //总共有几路端口
    ULONG                		    uiLeftLightNo;                          //左转灯对应ID
    ULONG                	        uiStraitLightNo;                        //直行灯对应ID
    ULONG                          uiRightLightNo;                         //右转灯对应ID
    ULONG                          uiTurnRoundLightNo;                     //调头等灯对应ID
}PU_ITS_XLW_DETECTOR_INFO_S;

//线圈车检器配置
typedef struct PU_ITS_COIL_DETECTOR_INFO
{
    PU_ITS_COIL_SNAP_TYPE_E            enSnapType;
    ULONG                		    uiDelayTime;                            //延时时间，0~80ms
    ULONG                		    uiCoilNum;                              //线圈的个数 1 2 3
    ULONG               		    uiCoilInterval;                         //线圈中心的间隔 厘米
    ULONG               		    uiCoilWidth;                            //线圈的宽度      厘米
}PU_ITS_COIL_DETECTOR_INFO_S;

//线圈车检器配置
typedef struct PU_ITS_IO_DETECTOR_INFO
{
    PU_ITS_COIL_SNAP_TYPE_E            enSnapType;                            //抓拍类型
    PU_DEVICE_IO_TYPE_E                enTrigType;                            //GPIO触发方式
}PU_ITS_IO_DETECTOR_INFO_S;

//红绿灯检测器信息
typedef struct PU_LIGHT_DETECTOR_INFO
{
    PU_EXTRA_DEVICE_TYPE_E      enDeviceProtelType;                     //外设协议类型
    ULONG                      uiLightRoadEnable;                      //该外设是否使能
    ULONG                      uiLightLaneId;                          //外设覆盖的车道，使用bitmap 0位置1表示1车道使能，以此类推
    PU_ITS_SERIAL_PORT_E           enLightSerialPortId;                    //该外设使用的串口号
    PU_ITS_RS_PARA_S            stLightDevSerialCfg;                    //串口配置
    PU_ITS_XLW_DETECTOR_INFO_S     stCfgLightDetector;                     //信路威TL-01-8红绿灯信号检测器
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_LIGHT_DETECTOR_INFO_S;


//车检查器信息
typedef struct PU_VEHICLE_DETECTOR_INFO
{
    ULONG                      uiDetectRoadEnable;                     //该外设是否使能
    ULONG                      uiDetectLaneId;                         //外设覆盖的车道，使用bitmap 0位置1表示1车道使能，以此类推
    PU_ITS_SERIAL_PORT_E           enDetecSerialPortId;                    //该外设使用的串口号
    PU_ITS_RS_PARA_S            stDetectDevSerialCfg;                   //串口配置
    PU_ITS_COIL_DETECTOR_INFO_S    stCfgCoilDetector;                      //线圈车检器
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_VEHICLE_DETECTOR_INFO_S;

//车检查器信息
typedef struct PU_IO_DETECTOR_INFO
{
    BOOL                      uiIOEnable;                             //该外设是否使能
    ULONG                      uiIOLaneId;                             //外设覆盖的车道，使用bitmap 0位置1表示1车道使能，以此类推
    PU_ITS_IO_DETECTOR_INFO_S      stCfgIODetector;                      //线圈车检器
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_IO_DETECTOR_INFO_S;

//川速雷达的控制信息
typedef struct PU_RADAR_CTRL_INFO
{
    ULONG                      uiRoadEnable;                           //车道是否使能
    ULONG                      uiLaneId;                               //道路ID，使用bitmap 0位置1表示1车道使能，以此类推
    PU_ITS_SERIAL_PORT_E           enSerialPortId;                         //串口号

    PU_ITS_RS_PARA_S            stDevSerialCfg;                         //串口配置
    PU_RADA_PARA_CHUANSU_S      stCfgChuanshu;                          //川速雷达
    PU_ITS_RADA_CTRL_CSRIM_S       stCfgMultiChuanshu;                     //川速多车道雷达
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_RADAR_CTRL_INFO_S;

//ITS外设的概要信息
typedef struct PU_ITS_DEV_INFO
{
    PU_EXTRA_DEVICE_TYPE_E      enDeviceProtelType;                     //外设协议类型
    PU_RADAR_CTRL_INFO_S        stRadarInfo;                            //雷达设备信息
    PU_VEHICLE_DETECTOR_INFO_S  stVehicleDetectorInfo;                  //车检器协议
    PU_IO_DETECTOR_INFO_S       stIODetectorInfo;                       //IO协议
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_ITS_DEV_INFO_S;

//ITS外设参数
typedef struct PU_ITS_DEV_SPEC
{
	ULONG                       ulChannelId;    // 通道ID
    PU_DEVICE_MODE_E            enDeviceMode;                           //设备抓拍模式
    ULONG                                 ulTotalRoadNum;                         //设备车道总数
    PU_ITS_EXTRA_DEVICE_TYPE_E     enExtraType;                            //外设类型:0 无外设 1 雷达，2车检器，3 IO，三者互斥(下方协议类型参数,需与此类型匹配,如雷达设备,协议须选择雷达相关类型)
    PU_ITS_DEV_INFO_S           stDevSpecInfo[PU_ITS_MAX_ROAD_NUM];        //按车道下配参数
    PU_LIGHT_DETECTOR_INFO_S    stLightDetectorInfo;                    //红绿灯检测器,不和车道关联
    BOOL                        bInputState;                            //告警输入使用状态
    CHAR  szReserve[PU_RESERVE_LEN];
}PU_ITS_DEV_SPEC_S;
/********** END: ITS外设参数 **********/

//本机SIM卡号码
typedef struct PU_SIM_PHONE_NUM_S
{
	CHAR szPhoneNum[DIAL_PHONE_NUM_LEN];
	CHAR  szReserve[PU_RESERVE_LEN];
}PU_SIM_PHONE_NUM_S;

//设备ESN号 
typedef struct PU_DEVICE_ESN_INFO
{
	CHAR szDeviceESNInfo[PU_ESN_INFO_LEN];
	CHAR szReserved[PU_RESERVE_LEN];
}PU_DEVICE_ESN_INFO_S;


//master slave role enum
typedef enum PU_MASTER_SLAVE_ROLE
{
	PU_ROLE_NONE = 0, //用于删除主从关系
    PU_ROLE_MASTRE, //主从关联中的主机
	PU_ROLE_SLAVE, //主从关联中的从机
    PU_ROLE_MAX,
}PU_MASTER_SLAVE_ROLE_E;

//单个主从关联参数
typedef struct PU_MASTER_SLAVE_PER_GROUP_PARA
{
	PU_MASTER_SLAVE_ROLE_E enRole; //主从角色
	ULONG ulGroupID; //主从关联ID, 扩展预留，当前不使用
	CHAR szMasterIP[PU_IP4_ADDR_LEN]; //主机IP
	CHAR szSlaveIP[PU_IP4_ADDR_LEN]; //从机IP
	INT iSlavePort; //从机端口号
	CHAR szReserved[PU_RESERVE_LEN];
 }PU_MASTER_SLAVE_PER_GROUP_PARA_S;

//主从关联参数
typedef struct PU_MASTER_SLAVE_GROUP_PARA
{
	INT iMasterSlaveGroupNum; //主从组合数目
	PU_MASTER_SLAVE_PER_GROUP_PARA_S *stGroupPara;
	CHAR szReserved[PU_RESERVE_LEN];
 }PU_MASTER_SLAVE_GROUP_PARA_S;
 
  //多机交互用户名密码
typedef struct PU_MASTER_SLAVE_AUTH_PARA
{
	ULONG ulChannelID; //通道ID, 扩展预留，当前不使用
	CHAR szUserName [PU_USER_NAME_LEN]; //用户名
	CHAR szUserPwd [PU_PASSWORD_LEN]; //密码
	CHAR szReserved[PU_RESERVE_LEN];
 }PU_MASTER_SLAVE_AUTH_PARA_S;

//主从通信端口
typedef struct PU_MASTER_SLAVE_COMMUNICATION_PARA
{
	ULONG ulGroupID; ////主从关联ID, 扩展预留，当前不使用
	PU_MASTER_SLAVE_ROLE_E enRole; //主从角色
	INT iPort; //主从通信端口
	CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVE_COMMUNICATION_PARA_S;

//主从跟踪策略
typedef enum PU_MASTER_SLAVE_TRACK_MODE
{
  PU_MODE_OBJ_DISAPPEAR = 0, //目标消失，跟踪直至目标离开枪机画面
  PU_MODE_TIME_FIXED // 固定时间，跟踪目标指定时间，到时间后切换目标
} PU_MASTER_SLAVE_TRACK_MODE_E;

//跟踪目标占画面比例
typedef enum PU_TRACK_OBJECT_SIZE
{
	PU_OBJECT_SIZE_HALF = 0, //目标占画面二分之一
	PU_OBJECT_SIZE_ONE_THIRD, //目标占画面三分之一
	PU_OBJECT_SIZE_QUARTER, //目标占画面四分之一
	PU_OBJECT_SIZE_FIFTH, //目标占画面五分之一
} PU_TRACK_OBJECT_SIZE_E;

//主从跟踪配置
typedef struct PU_MASTER_SLAVE_TRACK_PARA
{
	BOOL bEnable; //主从跟踪是否使能
	ULONG ulGroupID; ////主从关联ID, 扩展预留，当前不使用
	PU_MASTER_SLAVE_TRACK_MODE_E enMode; //跟踪策略
	PU_TRACK_OBJECT_SIZE_E enObjectSize; //目标大小占从机画面的比例
	INT iTrackTime; //跟踪时长,单位s
	CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVE_TRACK_PARA_S;

typedef enum PU_LOCATE_TYPE
{
	PU_LOCATE_POINT, //点定位
	PU_LOCATE_RECT, //框定位
} PU_LOCATE_TYPE_E;

//画框方向
typedef enum PU_DRAW_DIR
{
	PU_DIR_TOP_LEFT_TO_RIGHT_BOTTOM, //从左上到右下画框
	PU_DIR_RIGHT_BOTTOM_TO_TOP_LEFT, //从右下到左上画框
} PU_DRAW_DIR_E;

//主从框定位参数
typedef struct PU_RECT_LOCATE_PARA
{
	PU_DRAW_DIR_E enDirection; //画框方向
	PU_AREA_INFO_S stRect; //框信息
} PU_RECT_LOCATE_PARA_S;

//主从定位参数
typedef struct PU_MASTER_SLAVE_LOCATE_PARA
{
	ULONG ulGroupID; //主从关联ID, 扩展预留，当前不使用
	PU_LOCATE_TYPE_E enType; //主从定位类型
	union {
		PU_POINT_S stPointLocate; //点定位参数
		PU_RECT_LOCATE_PARA_S stRectLocate; //框定位参数
	} config;
} PU_MASTER_SLAVE_LOCATE_PARA_S;

//主从定位参数
typedef struct PU_MASTER_SLAVE_LOCATE_CONFIG
{
	ULONG ulGroupID; //主从关联ID, 扩展预留，当前不使用
	BOOL bEnable; //是否使能
	CHAR szReserved[PU_RESERVE_LEN];
}PU_MASTER_SLAVE_LOCATE_CONFIG_S;

//标定类型
typedef enum PU_CALIBRATION_TYPE
{
 	PU_CALIBRATION_MANUAL = 0, //手动
 	PU_CALIBRATION_AUTO, //自动
 	PU_CALIBRATION_MAX
}PU_CALIBRATION_TYPE_E;

typedef struct PU_MANUAL_CALIBRATION_PAIR
{
	PU_POINT_S stMaster; //枪机标定点坐标
	PU_PTZ_CURRENT_LOCATION_S stSlave; //球机标定点坐标
}PU_MANUAL_CALIBRATION_PAIR_S;

typedef struct PU_MANUAL_CALIBRATION_CONFIG
{
	INT iPairNum; //标定坐标对个数
	PU_MANUAL_CALIBRATION_PAIR_S stPair[PU_CALIBRATION_POINT_MAX_NUM]; 
}PU_MANUAL_CALIBRATION_CONFIG_S;

typedef struct PU_AUTO_CALIBRATION_CONFIG
{
	PU_PTZ_CURRENT_LOCATION_S stCenter; //自动标定时球机中心点ptz
	CHAR szMasterScreenPicPath[PU_SNAPSHOT_PICTURE_NAME_LEN]; //球机画面截图存储路径
	CHAR szSlaveScreenPicPath[PU_SNAPSHOT_PICTURE_NAME_LEN]; //从机画面截图存储路径
}PU_AUTO_CALIBRATION_CONFIG_S;

//图片尺寸
typedef struct PU_PIC_SIZE
{
	ULONG ulWidth;                      //图片宽度
	ULONG ulHeight;                     //图片高度
}PU_PIC_SIZE_S;

// 标定用镜头信息
typedef struct PU_CALIBRATION_LEN_INFO
{
	PU_PIC_SIZE_S stPicSize; //画面宽高
	PU_PRECISE_FIGURES_S stZoom; //镜头倍率
}PU_CALIBRATION_LEN_INFO_S;

//主从标定配置
typedef struct PU_MASTER_SLAVE_CALIBRATION
{
	ULONG ulGroupID; //主从关联ID, 扩展预留，当前不使用
	PU_CALIBRATION_TYPE_E enType; //标定类型
	PU_CALIBRATION_LEN_INFO_S stMasterLen; // 主镜头信息
	PU_CALIBRATION_LEN_INFO_S stSlaveLen; // 从镜头信息
	union {
		PU_MANUAL_CALIBRATION_CONFIG_S stManual; //手动标定配置
		PU_AUTO_CALIBRATION_CONFIG_S stAuto; //自动标定配置
	} config;
	CHAR szReserved[PU_RESERVE_LEN];
}PU_MASTER_SLAVE_CALIBRATION_S;

//主从标定状态
typedef enum PU_CALIBRATION_STATUS
{
	CALIBRATION_INIT = 0, //未进行标定
	CALIBRATION_COMPLETE, //标定已完成
	CALIBRATION_MAX
}PU_CALIBRATION_STATUS_E;

//主从标定状态查询参数
typedef struct PU_MASTER_SLAVE_CALIBRATION_STATUS
{
	ULONG ulGroupID; ////主从关联ID, 扩展预留，当前不使用
	PU_CALIBRATION_STATUS_E enStatus; 
	CHAR szReserved[PU_RESERVE_LEN];
}PU_MASTER_SLAVE_CALIBRATION_STATUS_S;

//手动跟踪参数
typedef struct PU_MASTER_SLAVE_MANUAL_TRACK_PARA
{
	ULONG ulGroupID; ////主从关联ID, 扩展预留，当前不使用
	INT iObjectId; //手动跟踪目标ID
	CHAR szReserved[PU_RESERVE_LEN];
}PU_MASTER_SLAVE_MANUAL_TRACK_PARA_S;

/********** BEGIN: 从设备管理 **********/
//从设备基础参数
typedef struct PU_SLAVE_DEVICE_INFO
{
    ULONG  ulSlaveID;                            //从设备ID
    BOOL   bValid;                               //是否有效标志位
    CHAR   szIPAddress[PU_IP4_ADDR_LEN];         //从设备IP地址
    CHAR   szSlaveName[PU_CLIENT_USERNAME_LEN];  //从设备名称,不超过32字节字符
    CHAR   szReserved[PU_RESERVE_LEN];
}PU_SLAVE_DEVICE_INFO_S;

//从设备基础参数列表
typedef struct PU_SLAVE_DEVICE_LIST
{
    PU_SLAVE_DEVICE_INFO_S astSlaveInfo[PU_SLAVE_NUM_MAX]; //从设备列表
    ULONG ulSlaveCap; //从设备能力，支持的最大从设备数
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];
}PU_SLAVE_DEVICE_LIST_S;

//从设备Onvif参数
typedef struct PU_SLAVE_ONVIF_PARAM
{   
    ULONG  ulSlaveID;                       //从设备ID
    BOOL   bEnable;                         //使能
    ULONG  ulChannelId;                     //从设备通道id
    ULONG  ulOnvifPort;                     //从设备Onvif端口
    CHAR   szUserName[PU_CLIENT_USERNAME_LEN]; //从设备Onvif用户名
    CHAR   szPassWord[PU_PASSWORD_LEN];        //从设备Onvif密码
    CHAR   szReserved[PU_RESERVE_LEN];
}PU_SLAVE_ONVIF_PARAM_S;

//从设备Rtsp参数
typedef struct PU_SLAVE_RTSP_PARAM
{
    ULONG  ulSlaveID;                       //从设备ID
    BOOL   bEnable;                         //使能
    ULONG  ulChannelId;                     //从设备通道id
	ULONG  ulRtspPort;                      //从设备RTSP端口
	CHAR   szUserName[PU_CLIENT_USERNAME_LEN];   //从设备RTSP用户名
    CHAR   szPassWord[PU_PASSWORD_LEN];          //从设备RTSP密码
    CHAR   szReserved[PU_RESERVE_LEN];
}PU_SLAVE_RTSP_PARAM_S;

//从设备onvif状态
typedef enum PU_SLAVE_ONVIF_STATUS_TYPE
{
    SLAVE_ONVIF_STATUS_NORMAL,        //正常
    SLAVE_ONVIF_STATUS_USER_ERROR,	  //用户名密码错误
    SLAVE_ONVIF_STATUS_ABNORMAL,      //异常
    SLAVE_ONVIF_STATUS_FRAMERATE_INAPPROPRIATE,      //帧率不合适
    SLAVE_ONVIF_STATUS_RESOLUTION_INAPPROPRIATE,     //分辨率不合适
    SLAVE_ONVIF_STATUS_MEDIA_ENCODING_INAPPROPRIATE, //不符合MEDIA模式的编码模式
    SLAVE_ONVIF_STATUS_MEDIA2_ENCODING_INAPPROPRIATE,//不符合MEDIA2模式的编码模式
    SLAVE_ONVIF_STATUS_MAX
}PU_SLAVE_ONVIF_STATUS_TYPE_E;

//从设备onvif状态
typedef struct PU__SLAVE_ONVIF_STATUS
{
    ULONG  ulSlaveID;                      //从设备id，唯一标识
    PU_SLAVE_ONVIF_STATUS_TYPE_E enStatus; //状态值
}PU_SLAVE_ONVIF_STATUS_S;

//从设备rtsp状态
typedef enum PU_SLAVE_RTSP_STATUS_TYPE
{
	SLAVE_RTSP_STATUS_NORMAL,        //正常
	SLAVE_RTSP_STATUS_URL_ERR,       //rtsp url异常
	SLAVE_RTSP_STATUS_USER_ERR,      //用户名密码错误
	SLAVE_RTSP_STATUS_ABNORMAL,      //其他异常
    SLAVE_RTSP_STATUS_MAX
}PU_SLAVE_RTSP_STATUS_TYPE_E;

//从设备rtsp状态
typedef struct PU_SLAVE_RTSP_STATUS
{
    ULONG  ulSlaveID;                      //从设备id，唯一标识
    PU_SLAVE_RTSP_STATUS_TYPE_E enStatus;  //状态值
}PU_SLAVE_RTSP_STATUS_S;

/********** END: 从设备管理 **********/
//1拖N场景类型
typedef enum PU_1TN_SUPPORT_MODE
{
	TN_COMMON_SUPPORT_MODE			= 0,		//不支持智能模式
	TN_FACE_TWO_SUPPORT_MODE		= 1,		//两路人脸模式
	TN_VHD_TWO_SUPPORT_MODE			= 2,		//两路机非人模式
	TN_VHD_THREE_SUPPORT_MODE		= 3,		//三路机非人模式
	TN_FACE_THREE_SUPPORT_MODE		= 4,		//三路人脸
	TN_FACE_OR_VHD_TWO_SUPPORT_MODE   = 5,		//两路：机非人人脸任意组合
	TN_FACE_OR_VHD_THREE_SUPPORT_MODE = 6,		//三路：机非人人脸任意组合
	TN_FACE_FOUR_SUPPORT_MODE		   = 7,		//4路人脸+一路识别
	TN_FACE_FIVE_SUPPORT_MODE         = 8,		//5路人脸+一路识别
	TN_FACE_TWO_VHD_TWO_SUPPORT_MODE  = 9,		//2机非人+2人脸模式+一路识别
	TN_VHD_FOUR_SUPPORT_MODE          = 10,		//4机非人模式
	TN_ITGT_SUPPORT_MODE_MAX		  = 64
}PU_1TN_SUPPORT_MODE_E;

//多机互助从设备使能参数
typedef struct PU_SLAVE_DEVICE_ENABLE
{
    ULONG  ulSlaveID;    //从设备ID
    BOOL   bEnable;      //使能标志位
}PU_SLAVE_DEVICE_ENABLE_S;

//1拖N功能使能
typedef struct PU_1TN_ENABLE
{
   BOOL bEnable; //使能
   CHAR szReserved[PU_RESERVE_EX_LEN];
}PU_1TN_ENABLE_S;

//1拖N,拖的方式
typedef struct PU_1TN_SUPPORT_MODE_SWITCH
{
	ULONG                ulChannelId;		//通道号
	PU_1TN_SUPPORT_MODE_E enMode;
	CHAR szReserved[PU_RESERVE_LEN];
}PU_1TN_SUPPORT_MODE_SWITCH_S;

//1拖N,设备支持拖的种类能力列表
typedef struct PU_1TN_SupportModeLIST
{
	ULONG   ulChannelId;						//通道号
	ULONG	uSupportModeNum;					//数量
	PU_1TN_SUPPORT_MODE_E  enSpptModelist[TN_ITGT_SUPPORT_MODE_MAX];//设备支持的最大智能能力列表
	CHAR szReserved[PU_RESERVE_LEN];
}PU_1TN_SUPPORT_MODE_LIST_S;


//通道状态
typedef enum PU_CHANNEL_STATUS
{
    CHANNEL_STATUS_ERR = 0,   //异常
    CHANNEL_STATUS_NORMAL,    //正常
    CHANNEL_STATUS_MAX
}PU_CHANNEL_STATUS_E;

//单个通道信息
typedef struct PU_PRE_CHANNEL_INFO
{
    ULONG ulChannelID;  //通道id
    PU_CHANNEL_STATUS_E enSlaveChanStatus; //通道状态
    CHAR szReserved[PU_RESERVE_LEN];
}PU_PRE_CHANNEL_INFO_S;

//通道信息
typedef struct PU_MASTER_SLAVER_CHANNEL_INFO
{
    ULONG ulMasterChanCap;  //主通道能力
    ULONG ulSlaveChanCap;   //从通道能力，即支持的从通道最大数
    ULONG ulMasterChanNum;  //主通道数
    ULONG ulSlaveChanNum;   //从通道数
    PU_PRE_CHANNEL_INFO_S astMasterChanInfo[PU_MASTER_NUM_MAX];  //主通道信息
    PU_PRE_CHANNEL_INFO_S astSlaveChanInfo[PU_SLAVE_NUM_MAX];    //从通道信息
    CHAR szReserved[PU_RESERVE_LEN];
}PU_MASTER_SLAVER_CHANNEL_INFO_S;

/*****************  车辆事件检测******************/

//违法停车参数结构体
typedef struct PU_VEHICLEEVENTS_ILLEGALPARKING_PARA
{
    ULONG                           ulChannelId;                // 通道ID
    BOOL                            enEnable;                   // 算法使能
    BOOL                            enSnapEnable;               // 抓拍使能
    ULONG                           ulParkTimeThr;              // 停车触发时间
    ULONG                           ulAlarmTime;                // 告警上报间隔
    AERADTC_LIST_S                  stAreaList;                 // 违法停车检测区域
    PU_ALARM_TIME_LIST_S            stGuardPlan;                // 布防计划
    UINT                            ulVehicleStopSensitivity;   // 停车灵敏度
    CHAR                            szReserved[PU_RESERVE_EX_LEN];
}PU_VEHICLEEVENTS_ILLEGALPARKING_PARA_S;

//非占机参数结构体
typedef struct PU_VEHICLEEVENTS_ONVEHICLELANE_PARA
{
    ULONG                           ulChannelId;                // 通道ID
    BOOL                            enEnable;                   // 算法使能
    BOOL                            enSnapEnable;               // 抓拍使能
    UINT                            unVehicleSensitivity;       // 车身灵敏度1~100
    UINT                            unOccupiedTime;             // 占用时间单位秒0~10    
    ULONG                           ulAlarmTime;                // 告警上报间隔
    AERADTC_LIST_S                  stAreaList;                 // 布控区域
    PU_ALARM_TIME_LIST_S            stGuardPlan;                // 布防计划
    CHAR                            szReserved[PU_RESERVE_EX_LEN];
}PU_VEHICLEEVENTS_ONVEHICLELANE_PARA_S;

//机占非参数结构体
typedef struct PU_VEHICLEEVENTS_ONBICYCLELANE_PARA
{
    ULONG                           ulChannelId;                // 通道ID
    BOOL                            enEnable;                   // 算法使能
    BOOL                            enSnapEnable;               // 抓拍使能
    UINT                            unVehicleSensitivity;       // 车身灵敏度1~100
    UINT                            unOccupiedTime;             // 占用时间单位秒0~10   
    ULONG                           ulAlarmTime;                // 告警上报间隔    
    AERADTC_LIST_S                  stAreaList;                 // 布控区域
    PU_ALARM_TIME_LIST_S            stGuardPlan;                // 布防计划
    CHAR                            szReserved[PU_RESERVE_EX_LEN];
}PU_VEHICLEEVENTS_ONBICYCLELANE_PARA_S;

//逆行倒车参数结构体
typedef struct PU_VEHICLEEVENTS_WRONGDIRECTION_PARA
{
    ULONG                          ulChannelId;                // 通道ID
    BOOL                            enEnable;                   // 算法使能
    BOOL                            enSnapEnable;               // 抓拍使能
    UINT                            ulSensitivity;              // 下配给业务，辅助违章判断，用于调整违章触发的灵敏度调整，此处主要针对车辆溜坡的行为检测，以免误检
    ULONG                           ulAlarmTime;                // 告警上报间隔
    AERADTC_LIST_S                  stAreaList;                 // 布控区域
    PU_ALARM_TIME_LIST_S            stGuardPlan;                // 布防计划
    CHAR                            szReserved[PU_RESERVE_EX_LEN];
}PU_VEHICLEEVENTS_WRONGDIRECTION_PARA_S;


//压线参数结构体
typedef struct PU_VEHICLEEVENTS_COVERLINE_PARA
{
    ULONG                           ulChannelId;                // 通道ID
    BOOL                            enEnable;                   // 算法使能
    BOOL                            enSnapEnable;               // 抓拍使能
    UINT                            unVehicleSensitivity;       // 车身灵敏度1~100
    ULONG                           ulAlarmTime;                // 告警上报间隔
    AERADTC_LIST_S                  stAreaList;                 // 布控区域
    PU_ALARM_TIME_LIST_S            stGuardPlan;                // 布防计划
    CHAR                            szReserved[PU_RESERVE_EX_LEN];
}PU_VEHICLEEVENTS_COVERLINE_PARA_S;

//异常车牌参数结构体
typedef struct PU_VEHICLEEVENTS_ABNORMALPLATE_PARA
{
    ULONG                          ulChannelId;                // 通道ID
    BOOL                           enEnable;                   // 算法使能
    BOOL                           enSnapEnable;               // 抓拍使能
    //PU_PLATE_TYPE_E                enPlateType;                // 车牌类型
    ULONG                          ulAlarmTime;                // 告警上报间隔
    PU_ALARM_TIME_LIST_S           stGuardPlan;                // 布防计划
    CHAR                           szReserved[PU_RESERVE_EX_LEN];
}PU_VEHICLEEVENTS_ABNORMALPLATE_PARA_S;


/**********begin:微卡口/机非人参数再次修改*****************/

//车道属性参数
typedef struct PU_LANE_ATTR_PARA
{
    PU_ITS_ROAD_PURPOSE_E       enLanePurpose;              //  车道类型/用途
    PU_ITS_CAR_DRV_DIR_E        enLaneDirection;            //  车道方向
}PU_LANE_ATTR_PARA_S;

// 触发类型枚举值
typedef enum PU_CAMPUS_TRIG_TYPE
{
    PU_CAMPUS_TRIG_MODE_GROUND = 0, // 地感线圈触发
    PU_CAMPUS_TRIG_MODE_DT_LINE,       // 视频拌线触发
    PU_CAMPUS_TRIG_MODE_HYBRID,        // 混合触发模式(线圈触发优先，拌线触发为辅)

    PU_CAMPUS_TRIG_MODE_MAX
}PU_CAMPUS_TRIG_TYPE_E;

// 园区出入口参数配置
typedef struct PU_CAMPUS_MODE_PARA
{
    BOOL bEnable;                     // 园区出入口业务功能使能开关
    PU_CAMPUS_TRIG_TYPE_E enTrigType; // 触发类型                         // 触发类型:0-线圈触发  1-视频拌线触发   2-混合模式触发
    BOOL bEnableNoPlateVeh;    // 是否上报无牌车
    BOOL bEnableDataAck;         // 启用数据回传
}PU_CAMPUS_MODE_PARA_S;

//车牌全局参数配置扩充车道属性
typedef struct PU_VLPR_PARA_V3
{
    ULONG                      ulChnID;                               //  通道ID
    BOOL                       bEnable;                                   //  是否使能
    LONG                       iLaneNum;                                  //  车道数量
    PU_IMRS_LINE_S             stLane[MAX_AREA_VERTEX];                   //  车道线 = 车道数+1，包括车道线属性
 
    PU_VEHICLE_DIR_E     enVehicleDir;           // 车辆方向，默认车头
    PU_VLPR_CATCH_MODE_E enCatchMode;            // 抓拍类型 0:机动车 1:机非人
    PU_VLP_PARA_S        stVLPParam;             // 车牌参数
    BOOL bVColorDetection;                       // 车辆颜色检测启用
    BOOL bVTypeDetection;                        // 车辆类型检测启用
    BOOL bSendPanoramaPic;                       // 是否发送全景图
    BOOL bSendPlatePic;                          // 是否发送车牌小图
    PU_VLPR_ALG_MODE_E enAlgMode;  //车牌算法类型

    BOOL  bExposureEnable;                                                //车牌曝光使能
    ULONG ulROIMeterLevel;                                               //车牌曝光系数
    BOOL bVlprEnhancement;
    PU_LANE_ATTR_PARA_S        stLaneAttr[MAX_LANE_NUM];                  //  车道属性
	AERADTC_LIST_S             stAreaList; //ROI检测区域
    PU_IMRS_LINE_S             stDetectLine[MAX_AREA_VERTEX];             //  检测线
    BOOL				 	   bEnableVehicleMfrType;	//是否启用二次特征
	BOOL				 	   bEnableFacePic;		 	//是否启用人脸抠图
    PU_CAMPUS_MODE_PARA_S      stCampusModePara;
    CHAR szReserved[PU_RESERVE_EX_LEN - (sizeof(BOOL) * 2) - sizeof(PU_CAMPUS_MODE_PARA_S)];
}PU_VLPR_PARA_V3_S;


//机非人参数扩充
typedef struct PU_VHD_PARA_EX
{
    ULONG                   ulChannelId;          // 通道ID
    BOOL                    bEnable;              // 是否使能
    BOOL                    bSendSnapPicture;     //上传目标小图
    BOOL                    bSendPanorama;        //上传全景
    BOOL                    bLaneLineEnable;                        //车道线是否使能
    PU_VLPR_ALG_MODE_E      enAlgMode;                              //抓拍算法类型
    INT                     iWidth;                                 //配置图像宽度
    INT                     iHeight;                                //配置图像高度
    INT                     iLaneNum;                               //车道数量    
    PU_IMRS_LINE_S          stLane[MAX_AREA_VERTEX];                //车道线 = 车道数+1
    CHAR                    szPlateLocalZH[MAX_PLATE_LOCAL_ZH_LEN]; // 优先城市类型，最多6个，超过6个取6个，如“沪苏浙”

    BOOL                    bExposureEnable;    //曝光使能
    CHAR                    ulROIMeterLevel;    //曝光系数
    
    PU_LANE_ATTR_PARA_S     stLaneAttr[MAX_LANE_NUM];               //  车道属性
    AERADTC_LIST_S          stAreaList; //ROI检测区域

    CHAR            szReserved[PU_RESERVE_EX_LEN];
}PU_VHD_PARA_EX_S,*LPPU_VHD_PARA_EX_S;


/**********end:微卡口/机非人参数再次修改*****************/


/*尾号限行索引方式*/
typedef enum PU_ITS_RESTRICTED_INDEX_TYPE
{
    RESTRICTE_INDEX_BY_WEEK, // 按星期索引
    RESTRICTE_INDEX_BY_DATE, // 按日期索引
    RESTRICTE_INDEX_MAX
} PU_ITS_RESTRICTED_INDEX_TYPE_E;

/*尾号限行的本地车牌*/
typedef struct PU_ITS_RESTRICTED_REGION
{
    char aucLocalPlate[MAX_RESTRICTED_LOCALPLATE_LEN];  //本地车牌-省,如浙A、沪C...
} PU_ITS_RESTRICTED_REGION_S;

/*尾号限行的时间段*/
typedef struct PU_ITS_RESTRICTED_DATA
{
    PU_ITS_RESTRICTED_INDEX_TYPE_E enIndexType;         //索引方式，日期尾号或者星期
    BOOL abRestrictedU[MAX_RESTRICTED_DATE_NUM]; //使能, 按星期 7 项, 按日期10项
    ULONG ulStartTime;     //尾号限行起始时间
    ULONG ulEndTime;       //尾号限行结束时间
} PU_ITS_RESTRICTED_DATA_S;


/*尾号限行一条约束项的结构体*/
typedef struct PU_ITS_RESTRICTED_PARA_UNIT
{
    BOOL abRestrictedNum[MAX_RESTRICTED_NUM];  /* 限制的尾号，支持0~9一共10个*/
    PU_ITS_RESTRICTED_DATA_S      stRestrictedDate;       //限制的日期和时间段
    PU_ITS_RESTRICTED_REGION_S astLocalPlate[MAX_RESTRICTED_LOCALPLATE_NUM];  //本地车牌
    BOOL abLocalRestrictedNum[MAX_RESTRICTED_NUM];                            //本地限制的尾号，支持0~9一共10个
    BOOL abNonLocalRestrictedNum[MAX_RESTRICTED_NUM];                         //外地限制的尾号，支持0~9一共10个

} PU_ITS_RESTRICTED_PARA_UNIT_S;

/*尾号限行总约束项结构体*/
typedef struct PU_ITS_RESTRICTED_PARA
{
    ULONG ulChannelId;          // 通道ID
    INT   iRestrictedNum;                                                       //配置的尾号限行项数
    PU_ITS_RESTRICTED_PARA_UNIT_S astRestricteds[MAX_RESTRICTED_EVENT_NUM];     //尾号限行项总数    
    CHAR            szReserved[PU_RESERVE_EX_LEN];
}PU_ITS_RESTRICTED_PARAM_S;
/*********end:尾号限行*********/

//车流量统计
typedef struct PU_VLPR_TRAFFIC_STATISTICS
{
    ULONG   ulChannelId;          // 通道ID
    BOOL    bEnable;              //是否使能
    ULONG   ulInterval;           //统计间隔
    ULONG   uDistanceToCrossing;  //相机距离路口距离
    ULONG   uDetectAreaLength;    //监测区域长度
    ULONG    uCongestionLaneThreshold; // 拥堵车道数阈值，当拥堵车道数大于等于此阈值时，判定道路拥堵
    FLOAT    fCongestThreholdForUnblocked; //拥堵阈值----畅通
    FLOAT    fCongestThreholdForAmble;       //拥堵阈值------缓行
    FLOAT    fCongestThreholdForCongest;    //拥堵阈值------拥堵
    CHAR    szReserved[PU_RESERVE_EX_LEN];
}PU_VLPR_TRAFFIC_STATISTICS_S;

//热度图检测区域
typedef struct PU_HOTMAP_AERADTC_LIST
{
    ULONG ulAreaNum;
    PU_IGT_AREA_S stArea[PU_HOTMAP_AREA_NUM];
}PU_HOTMAP_AERADTC_LIST_S;

//热度图参数
typedef struct PU_HOTMAP_PARA
{
	ULONG                      ulChannelId;       // 通道ID 
    PU_ENABLE_TYPE_E           enEnable;          // 算法使能
	PU_ENABLE_TYPE_E           enSendMeta;        //发送元数据，默认开启
	PU_PTZ_CURRENT_LOCATION_S  stPtzPara;         // PTZ位置
	PU_HOTMAP_AERADTC_LIST_S   stAreaList;        // 热度图检测区域
    CHAR                       szReserved[PU_RESERVE_LEN];
}PU_HOTMAP_PARA_S;  

//热度图查询类型
typedef enum PU_HOTMAP_TYPE
{
    TYPE_HOTMAP_SPACE,    //空间维度热度图
    TYPE_HOTMAP_TIME      //时间维度热度图
}PU_HOTMAP_TYPE_E;

//热度图灰度图参数
typedef struct PU_HOTMAP_TABLE_SPACE
{
	USHORT  usWidth;         //灰度图宽
    USHORT  usHeight;        //灰度图高
}PU_HOTMAP_TABLE_SPACE_S;

//热度图时间报表
typedef struct PU_HOTMAP_TABLE_TIME
{
	USHORT usHotMapRecordNum;   //数据长度
	union
	{
		USHORT  ausHotMapTableYear[PU_MONTH_NUM_PER_YEAR];   // 年报表返回结果
		USHORT  ausHotMapTableMonth[PU_DAY_NUM_PER_MONTH];   // 月报表返回结果
		USHORT  ausHotMapTableWeek[PU_DAY_NUM_PER_WEEK];     // 周报表返回结果
		USHORT  ausHotMapTableDay[PU_HOUR_NUM_PER_DAY];      // 日报表返回结果
	} map;
}PU_HOTMAP_TABLE_TIME_S;

//热度图查询参数
typedef struct PU_HOTMAP_TABLE_PARA
{
    ULONG                        ulChannelId;     //通道ID
    PU_HOTMAP_TYPE_E             enHotmapType;    //查询类型
    PU_TABLE_TYPE_E		         enTableType;	  //报表类型
    PU_TIME_S                    stBeginTime;     //起始时间,本地时间
    CHAR                         szPath[PU_SAVE_FILE_PATH_MAX + 1]; // 报表文件存储路径，调用者定义 ，
                                                                    //空间热度图为灰度图，时间热度图为CSV格式文件
    union 
    {
        PU_HOTMAP_TABLE_SPACE_S  stHotMapSapceTable;//对应查询类型为TYPE_HOTMAP_SPACE
        PU_HOTMAP_TABLE_TIME_S   stHotMapTimeTable; //对应查询类型为TYPE_HOTMAP_TIME
    }hotMapTable;	
    CHAR                         szReserved[PU_RESERVE_LEN];
}PU_HOTMAP_TABLE_PARA_S;

//每日布防计划计划
typedef struct PU_TIME_PLAN_PER_DAY
{
	ULONG  ulStartTime; //开始时间,距0点的时间,单位:秒
	ULONG  ulEndTime;   //结束时间,距0点的时间,单位:秒
}PU_TIME_PLAN_PER_DAY_S;

//热度图布防计划时间
typedef struct PU_HOTMAP_TIME_PLAN
{
	ULONG                   ulGuardNum; //布防计划数，最大PU_GUARD_PLAN_NUM_PER_DAY
	PU_TIME_PLAN_PER_DAY_S  astTimePalnPerDay[PU_GUARD_PLAN_NUM_PER_DAY]; //每天布防计划时间段
}PU_HOTMAP_TIME_PLAN_S;

//热度图布防计划参数
typedef struct GUARD_PLAN_PARA
{
    ULONG                 ulChannelId;     //通道ID，预留
    PU_HOTMAP_TIME_PLAN_S astGuadTime[PU_DAY_NUM_PER_WEEK]; //一周布防计划
    CHAR                  szReserved[PU_RESERVE_LEN];
}PU_HOTMAP_GUARD_PLAN_PARA_S;

//3559人脸识别元数据发送匿名设置结构体
typedef struct PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA
{
	ULONG           ulChannelId;        // 通道ID
	PU_ENABLE_TYPE_E  enAnonymousEnable;   // 元数据发送匿名使能开关   
	ULONG           ulAlarmTime;        // 告警上报间隔
	CHAR     szReserved[PU_RESERVE_LEN];
}PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S;

/*图像算法类型*/
typedef enum PU_IPS_ALGORITHM_TYPE
{
    ISP_ALG_TYPE_ADPAT = 0,            // 场景自适应算法
    ISP_ALG_TYPE_MAX_EX
}PU_IPS_ALGORITHM_TYPE_E;

/*算法版本信息*/
typedef struct PU_ALG_INFO
{
    PU_IPS_ALGORITHM_TYPE_E enAlgType;         //算法类型    
    CHAR szAlgVer[PU_ITGT_ALTHM_VERSION_LEN];    //算法版本
    CHAR szAlgOwner[PU_ITGT_ALTHM_VERSION_LEN];   //算法厂家    
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ALG_INFO_S;

/********* 图像算法信息*********/
typedef struct PU_ISP_ALG_INFO
{
    ULONG ulChannelId;                           //预留通道ID
    PU_ALG_INFO_S szAlgInfos[PU_ISP_TYPE_MAX_NUM];  //算法版本信息，为以后扩充考虑，预留64种算法，目前只有场景自适应一种算法
    CHAR szReserved[PU_RESERVE_LEN];
}PU_ISP_ALG_INFO_S;

/********* 机非人对象类型*********/
typedef enum PU_ITGT_VHD_OBJ_TYPE
{
	PU_OBJ_VEH,		//Vehicle
	PU_OBJ_PED,		//Pedestrian
	PU_OBJ_NMV		//Non-Motorized Vehicle
}PU_ITGT_VHD_OBJ_TYPE_E;

/********* 机非人自动跟踪优先级*********/
typedef struct PU_ITGT_VHD_OBJECT_ITEM
{
 	PU_ITGT_VHD_OBJ_TYPE_E objType;    // 目标类型
 	BOOL                  enable;     // 使能
 	ULONG                priority;   // 优先级
}PU_ITGT_VHD_OBJECT_ITEM_S;

/********* 机非人自动跟踪*********/
typedef struct PU_ITGT_VHD_AUTO_TRACK_PARA
{
	ULONG                 ulChannelID;         // 通道ID
	BOOL                  bEnable;        //算法使能
    ULONG                 ulSensitivity;  //算法检测灵敏度
    ULONG                 ulAlarmTime;    //告警上报间隔
    ULONG                 ulMaxTraceTime; //最大跟踪时间
    AERADTC_LIST_S        stAreaList;    //布防区域
    PU_ALARM_TIME_LIST_S  stAlarmTimeList;//布防计划
	PU_ITGT_VHD_OBJECT_ITEM_S          objItem[PU_ITGT_AUTOTRACKING_PRIORITY_ITEM_NUM];   // 自动跟踪优先级
	CHAR                            szReserved[PU_RESERVE_EX_LEN];
}PU_ITGT_VHD_AUTO_TRACK_PARA_S;

/********* 机非人手动跟踪*********/
typedef struct PU_ITGT_VHD_MANUAL_TRACK_PARA
{
	ULONG ulChannelID;       //预留通道ID
    ULONG ulTargetID;		 //跟踪对象ID
	CHAR  szReserved[PU_RESERVE_EX_LEN];
}PU_ITGT_VHD_MANUAL_TRACK_PARA_S;
	
/********* 聚焦模式*********/
typedef struct PU_PTZ_FOCUS_MODE
{
	ULONG ulPtzId;       //云台编号
    PU_FOCUS_MODE_E enFocusMode;		 //聚焦模式
    ULONG ulFocusSensitivity;//聚焦灵敏度(仅在自动聚焦模式有效)，范围0~2
	CHAR  szReserved[PU_RESERVE_EX_LEN];
}PU_PTZ_FOCUS_MODE_S;

#ifdef _WIN32
typedef enum PLAYER_COLOR
{
	PLAYER_COLOR_GREEN = 0,						//绿色
	PLAYER_COLOR_PURPLE = 1,					//紫色
	PLAYER_COLOR_RED = 2,						//红色
	PLAYER_COLOR_YELLOW = 3,					//黄色
	PLAYER_COLOR_WHITE = 4,						//白色
	PLAYER_COLOR_BLACK = 5,						//黑色
	PLAYER_COLOR_MAX,
}PLAYER_COLOR_E;

typedef struct PLAYER_POINT
{
    double x;
    double y;
}PLAYER_POINT_S;

typedef struct PU_CROSS_INFO
{
	PLAYER_POINT_S stCenter;	//十字中心点
	ULONG ulGraphID;	//索引用
	ULONG ulFrom;		//决定是自绘，还是由web传入，设置为0
	PLAYER_COLOR_E enCrossColor;//图形颜色
}PU_CROSS_INFO_S;

typedef struct PU_GRAPH_INFO
{
    double dPointX;
    double dPointY;
    ULONG ulWidth; //3d定位时此处为第二个点的坐标
    ULONG ulHeight;
    ULONG ulType;   //类型RT_NORMAL  = 0, RT_PRIVACY = 1, RT_ROI = 2
	ULONG ulGraphID;
    LONG lROIQuality;
	ULONG ulFrom;
	ULONG ulRectangleType;
}PU_GRAPH_INFO_S;

typedef enum PU_CURSOR_SHAPE
{
    PU_CURSOR_TOPDOWN  = 0,   //鼠标形状为上下向
    PU_CURSOR_LEFTRIGHT = 1,  //鼠标形状为左右向
    PU_CURSOR_NWSE = 2,       //鼠标形状为东南或者西北向
    PU_CURSOR_NESW = 3,       //鼠标形状为西南或者东北向
    PU_CURSOR_HAND = 4,       //鼠标形状为手形
    PU_CURSOR_ARROW =5,
	PU_CURSOR_START_BIG =6,
	PU_CURSOR_END_BIG =7,
}PU_CURSOR_SHAPE_E;

#endif

//透传接口输入参数结构体
typedef struct  PU_CONFIG_JSON_INPUT{ 
    VOID* pRequestUrl;      //请求信令，字符串格式
    ULONG ulRequestUrlLen;  //请求信令长度，字符串长度
    VOID* pInBuffer;        //输入参数缓冲区，JSON格式
    ULONG ulInBufferSize;   //输入参数缓冲区大小
    ULONG ulRecvTimeOut;    //接收超时时间，单位：ms，填0则使用默认超时5s 
    CHAR  szReserved [PU_RESERVE_EX_LEN];    //保留，置为0
} PU_CONFIG_JSON_INPUT_ST,*LPPU_CONFIG_JSON_INPUT_ST;

//透传接口输出参数结构体 
typedef struct PU_CONFIG_JSON_OUTPUT{ 
    VOID* pOutBuffer;       //输出参数缓冲区，JSON格式，注意：应用层需要申请足够大内存,如果用户申请内存不够大接口返回对应错误码。
    ULONG ulInputBufferSize;//用户输入 输出参数缓冲区大小(内存大小) 
    ULONG ulRealBufferSize; //实际输出参数缓冲区大小 
    CHAR  szReserved [PU_RESERVE_EX_LEN]; //保留，置为0
} PU_CONFIG_JSON_OUTPUT_ST,*LPPU_CONFIG_JSON_CONFIG_OUTPUT_ST;  

//***************************************************************************************************************************************************************
#pragma pack(pop)

/*******************************************************************************************************************/
/*                                             SDK Function Declaration                                            */
/*******************************************************************************************************************/


/******************************************************************************************************/
/*                                         Common Use Function                                        */
/******************************************************************************************************/

//initialize sdk resources
_HW_PU_API BOOL __stdcall IVS_PU_Init(ULONG ulLinkMode, CHAR *szLocalIP, ULONG ulLocalPort);
_HW_PU_API BOOL __stdcall IVS_PU_InitEx(ULONG ulLinkMode, CHAR *szLocalIP, ULONG ulLocalPort,ULONG ulLocalTlsPort,PU_CERT_FILE_PATH_PARA_S * pstCertFilePath);

_HW_PU_API BOOL __stdcall IVS_PU_MutualAuth(ULONG ulIdentifyID,CHAR *szUserName,CHAR *szPasswd);

//set local ip for login
_HW_PU_API BOOL __stdcall IVS_PU_SetValidLocalIp(CHAR *szLocalIP);

//login to device
_HW_PU_API ULONG __stdcall IVS_PU_Login(CHAR *szLoginIP, ULONG ulLoginPort, CHAR *szUserName, CHAR *szPasswd);

//login to device
_HW_PU_API BOOL __stdcall IVS_PU_LoginByID(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

//logout from device
_HW_PU_API BOOL __stdcall IVS_PU_Logout(ULONG ulIdentifyID);

//sdk event callback function type
typedef LONG(CALLBACK * pfGetEventInfoCallBack)(VOID *arg);

//register sdk event callback 
_HW_PU_API BOOL __stdcall IVS_PU_EventStatesCallBack(pfGetEventInfoCallBack fEventResportCallBack);

//release sdk resources
_HW_PU_API BOOL __stdcall IVS_PU_Cleanup();

//get device version info
_HW_PU_API BOOL __stdcall IVS_PU_GetVersion(ULONG *pulVersion);

//get sdk last error
_HW_PU_API ULONG __stdcall IVS_PU_GetLastError();

//get sdk last login lock time
_HW_PU_API BOOL __stdcall IVS_PU_GetLastLoginLockTime(ULONG *pulLockTime);

//get error message by error number
_HW_PU_API CONST CHAR* __stdcall IVS_PU_GetErrorMsg(ULONG ulErrorNo);

//get device log info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceLogInfo(ULONG ulIdentifyID, PU_LOG_TYPE_E enLogType, LPPU_LOG_REQ_PARA_S pstLogReqPara, LPPU_LOG_INFO_S pstDeviceLogInfo);

//device time 
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceTime(ULONG ulIdentifyID, LPPU_SYSTEM_TIME_S pstSystemTime);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceTime(ULONG ulIdentifyID, LPPU_SYSTEM_TIME_S pstSystemTime);

//daylight saving time para
_HW_PU_API BOOL __stdcall IVS_PU_GetDaylightSavingTimePara(ULONG ulIdentifyID, PU_DAYLIGHT_SAVING_TIME_S *pstDSTPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetDaylightSavingTimePara(ULONG ulIdentifyID, PU_DAYLIGHT_SAVING_TIME_S *pstDSTPara);

//reboot device
_HW_PU_API BOOL __stdcall IVS_PU_Reboot(ULONG ulIdentifyID);

//restore device default config (keep IP address)
_HW_PU_API BOOL __stdcall IVS_PU_Restore(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

//restore device default config (set IP to default IP)
_HW_PU_API BOOL __stdcall IVS_PU_TotallyRestore(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

//get device info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceInfo(ULONG ulIdentifyID, LPPU_DEVICEINFO_S pstDeviceInfo);

//设置设备名称，最长28字节(含'\0')
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceName(ULONG ulIdentifyID, CHAR * pcDeviceName);

//get device system status info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceStatusInfo(ULONG ulIdentifyID, LPPU_SYS_STATUS_INFO_S pstSysStatusInfo);

//remote upgrade device
_HW_PU_API BOOL __stdcall IVS_PU_Upgrade(ULONG ulIdentifyID, LPPU_UPGRADE_FILE_INFO_S pstFileInfo);

//upgrade schedule callback function 
typedef BOOL(CALLBACK *pfUpgradeScheduleCallBack)(LPPU_UPGRADE_CALLBACK_S pstUpgradeData,VOID *pUsrData);//传入当前上传文件的进度，传出值如果为TRUE，表示要取消升级
_HW_PU_API BOOL __stdcall IVS_PU_UpgradeWithSchedule(ULONG ulIdentifyID, LPPU_UPGRADE_FILE_INFO_S pstFileInfo,pfUpgradeScheduleCallBack fScheduleCallBack,VOID *pUsrData);
//write sdk log to file
_HW_PU_API BOOL __stdcall IVS_PU_WriteLogToFile(ULONG ulLogEnable, CHAR *szFileName, ULONG ulFileNum, ULONG ulSizePerFile);

//device config file 
_HW_PU_API BOOL __stdcall IVS_PU_GetConfigFile(ULONG ulIdentifyID, CHAR szConfigFile[PU_CONFIG_FILE_PATH_MAX] ,CHAR *pszLoadUpKey);
_HW_PU_API BOOL __stdcall IVS_PU_SetConfigFile(ULONG ulIdentifyID, CHAR szConfigFile[PU_CONFIG_FILE_PATH_MAX], CHAR *pszUserName, CHAR *pszPasswd, CHAR *pszLoadUpKey);

//802.1x证书导入导出 
_HW_PU_API BOOL __stdcall IVS_PU_SetDot1xTlsCert(ULONG ulIdentifyID, CHAR szCertFileFirst[PU_CONFIG_FILE_PATH_MAX], CHAR szCertFileSecond[PU_CONFIG_FILE_PATH_MAX], PU_DOT1X_TLS_CERT_UPLOAD_S stDot1xTlsCert);

//证书有效期周期参数
_HW_PU_API BOOL __stdcall IVS_PU_GetCertExpirePeriodPara(ULONG ulIdentifyID, PU_CERT_EXPIRE_PERIOD_PARA_S *pstCertExpirePeriodPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetCertExpirePeriodPara(ULONG ulIdentifyID, PU_CERT_EXPIRE_PERIOD_PARA_S *pstCertExpirePeriodPara);

//device log language
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceLogLanguage(ULONG ulIdentifyID, PU_LANGUAGE_TYPE_E *penLanguage);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceLogLanguage(ULONG ulIdentifyID, PU_LANGUAGE_TYPE_E enLanguage);

#ifdef _WIN32
//device list info by auto discovery
_HW_PU_API BOOL __stdcall IVS_PU_DiscoveryLocalDeviceList(LPPU_DISCOVER_DEVICE_LIST_S pstDeviceList);
//Check if IP conflicts, return non-conflicting IP list and number
_HW_PU_API BOOL __stdcall IVS_PU_PingIPLocal(ULONG ulStartIP, ULONG ulEndIP, ULONG ulNeedNum, ULONG* out_pIPList, ULONG* out_pulIPNum);
//change device IP address by MAC
_HW_PU_API BOOL __stdcall IVS_PU_ModifyIPByLocalMac(CHAR* szSrcNetMac, CHAR* szDstMac, CHAR* szPwd, char* szDstIP, char* szMask, char* szGateway);
#endif

//search device list info by UDP connect
_HW_PU_API BOOL __stdcall IVS_PU_DiscoveryDeviceByIpAddresses(CHAR* pszStartIpAddr, CHAR* pszEndIpAddr, ULONG ulSearchNum, PU_DISCOVER_DEVICE_INFO_S* pszDeviceList, ULONG *pulDeviceNum);

//change device password
_HW_PU_API BOOL __stdcall IVS_PU_ChangeDevicePassword(ULONG ulIdentifyID, CHAR* pszUserName, CHAR* pszOldPasswd, CHAR* pszNewPasswd);

//change destination module admin password
_HW_PU_API BOOL __stdcall IVS_PU_ChangeAdminPassword(ULONG ulIdentifyID, CHAR* pszOldPasswd, CHAR* pszNewPasswd, PU_IPC_MODULE_E enDstModule);

//change device ip address
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceEthernetPara(ULONG ulIdentifyID, LPPU_DEVICE_ETHERNET_PARA_S pstDeviceEthernetPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceEthernetPara(ULONG ulIdentifyID, LPPU_DEVICE_ETHERNET_PARA_S pstDeviceEthernetPara);

//检测IP是否冲突 
_HW_PU_API BOOL __stdcall IVS_PU_CheckIPConflict(ULONG ulIdentifyID, LPPU_DEVICE_ETHERNET_PARA_S pstDeviceEthernetPara);

//设置IP地址过滤
_HW_PU_API BOOL __stdcall IVS_PU_SetIPFilterPara(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFO_S stIPFilterPara); 
//获取IP地址过滤
_HW_PU_API BOOL __stdcall IVS_PU_GetIPFilterPara(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFO_S *pstIPFilterPara);

//设置IP地址过滤
_HW_PU_API BOOL __stdcall IVS_PU_SetIPFilterParaV2(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFOV2_S stIPFilterPara); 
//获取IP地址过滤
_HW_PU_API BOOL __stdcall IVS_PU_GetIPFilterParaV2(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFOV2_S *pstIPFilterPara);

//设置IP地址过滤
_HW_PU_API BOOL __stdcall IVS_PU_SetIPFilterParaV3(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFOV3_S* pstIPFilterPara); 
//获取IP地址过滤
_HW_PU_API BOOL __stdcall IVS_PU_GetIPFilterParaV3(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFOV3_S *pstIPFilterPara);


//response pu register message
_HW_PU_API BOOL __stdcall IVS_PU_ResponseDeviceRegister(ULONG ulIdentifyID, LPPU_DEVICE_REGISTER_RSP_S pstDevRegisterRsp);

//device rsa secret key length
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceRSASecretKeyLen(ULONG ulIdentifyID, ULONG* pulSecretKeyLen);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceRSASecretKeyLen(ULONG ulIdentifyID, ULONG ulSecretKeyLen);

//one key collection device informations: logs, system information, ssh information, etc.
_HW_PU_API BOOL __stdcall IVS_PU_OneKeyCollectionDeviceInfo(ULONG ulIdentifyID, CHAR* szFilePath);

//device user management
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceUserList(ULONG ulIdentifyID, PU_USER_LIST_S* pstUserList);

//设置WEB多点登陆用户数，请注意:接口废弃，SDK接口不支持
_HW_PU_API BOOL __stdcall IVS_PU_SetMultiLoginNum(ULONG ulIdentifyID, CHAR *szUserNmae, CHAR *szPassword, ULONG ulMultiLoginNum, CHAR *szTargetName);
//设置码流套餐
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamProfile(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_PROFILE_E enStreamProfile);
//获取码流套餐列表
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamProfileList(ULONG ulIdentifyID, PU_STREAMPROFILES_INFO_LIST_S* pstStreamProfilesInfo);
//设置iPCA参数
_HW_PU_API BOOL __stdcall IVS_PU_SetIPCAPara(ULONG ulIdentifyID, PU_IPCA_RULES_S stIPCARulePara);

//设置码流套餐参数
_HW_PU_API BOOL __stdcall IVS_PU_SetChannelStreamProfilesPara(ULONG ulIdentifyID, PU_CHANNEL_STREAM_PROFILES_S stStreamProfile);

//获取码流套餐参数
_HW_PU_API BOOL __stdcall IVS_PU_GetChannelStreamProfilesPara(ULONG ulIdentifyID, PU_CHANNEL_STREAM_PROFILES_S *pstStreamProfile);


//设置码流套餐参数V2五码流
_HW_PU_API BOOL __stdcall IVS_PU_SetChannelStreamProfilesParaV2(ULONG ulIdentifyID, PU_CHANNEL_STREAM_PROFILESV2_S stStreamProfile);
//获取码流套餐参数V2五码流
_HW_PU_API BOOL __stdcall IVS_PU_GetChannelStreamProfilesParaV2(ULONG ulIdentifyID, PU_CHANNEL_STREAM_PROFILESV2_S *pstStreamProfile);

//获取/设置视频诊断开关
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoDiagnosisEnableInfo(ULONG ulIdentifyID, PU_VIDEODIAGNOSIS_ENABLE_PARAM_S *pstVideoDiagnosisEnableInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoDiagnosisEnableInfo(ULONG ulIdentifyID, PU_VIDEODIAGNOSIS_ENABLE_PARAM_S *pstVideoDiagnosisEnableInfo);


//SMTP参数
_HW_PU_API BOOL __stdcall IVS_PU_GetSMTPConfig(ULONG ulIdentifyID, LPPU_SMTP_CONFIG_INFO_S pstSMTPConfig);
_HW_PU_API BOOL __stdcall IVS_PU_SetSMTPConfig(ULONG ulIdentifyID, LPPU_SMTP_CONFIG_INFO_S pstSMTPConfig);

//主动ARP广播参数
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoARPBroadcastPara(ULONG ulIdentifyID, ULONG ulEthIndex, PU_AUTO_ARP_BROADCAST_PARA_S *pstAutoARPBroadcastPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoARPBroadcastPara(ULONG ulIdentifyID, ULONG ulEthIndex, PU_AUTO_ARP_BROADCAST_PARA_S *pstAutoARPBroadcastPara);

//SSH使能
_HW_PU_API BOOL __stdcall IVS_PU_SetSSHEnable(ULONG ulIdentifyID, PU_SSH_ENABLE_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSSHEnable(ULONG ulIdentifyID, PU_SSH_ENABLE_PARA_S *pstPara);

//SFTP使能
_HW_PU_API BOOL __stdcall IVS_PU_SetSFTPEnable(ULONG ulIdentifyID, PU_SFTP_ENABLE_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSFTPEnable(ULONG ulIdentifyID, PU_SFTP_ENABLE_PARA_S *pstPara);

//ONVIF-RTSP媒体保活时间
_HW_PU_API BOOL __stdcall IVS_PU_SetOnvifRtspSessionTimeOut(ULONG ulIdentifyID, PU_ONVIF_RTSP_SESSION_TIMEOUT_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetOnvifRtspSessionTimeOut(ULONG ulIdentifyID, PU_ONVIF_RTSP_SESSION_TIMEOUT_PARA_S *pstPara);

//AES 密钥更新
_HW_PU_API BOOL __stdcall IVS_PU_UpdateAesKey(ULONG ulIdentifyID, PU_AES_KEY_MODULE_E enAesKeyModule, CHAR *szUserName, CHAR *szPasswd);

//H264 dec
_HW_PU_API HWND __stdcall IVS_PU_H264DecCreate(PU_H264_DEC_ATTR_S *pstDecAttr);
_HW_PU_API VOID __stdcall IVS_PU_H264DecDestroy(HWND pH264Handle);
_HW_PU_API INT __stdcall IVS_PU_H264DecAU(HWND pH264Handle, UCHAR *pucStream, UINT iStreamLen, ULONGLONG ullPTS, UINT iFlags, PU_H264_DEC_FRAME_S *pstDecFrame);

//H265 dec
_HW_PU_API INT __stdcall IVS_PU_H265DecCreate(HWND *ppH265Handle, PU_H265D_INIT_PARAM_S *pstInitParam);
_HW_PU_API INT __stdcall IVS_PU_H265DecDestroy(HWND pH265Handle);
_HW_PU_API INT __stdcall IVS_PU_H265DecAU(HWND pH265Handle, PU_H265DEC_INARGS_S *pstInArgs, PU_H265DEC_OUTARGS_S *pstOutArgs);

//设置、获取从设备基础参数
_HW_PU_API BOOL __stdcall IVS_PU_SetSlaveDeviceBasePara(ULONG ulIdentifyID, PU_SLAVE_DEVICE_INFO_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceBaseParaList(ULONG ulIdentifyID, PU_SLAVE_DEVICE_LIST_S *pstParaList);

//设置、获取从设备Onvif参数
_HW_PU_API BOOL __stdcall IVS_PU_SetSlaveDeviceOnvifPara(ULONG ulIdentifyID, PU_SLAVE_ONVIF_PARAM_S *pstSlaveOnvifPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceOnvifPara(ULONG ulIdentifyID, PU_SLAVE_ONVIF_PARAM_S *pstSlaveOnvifPara);

//设置、获取从设备Rtsp参数
_HW_PU_API BOOL __stdcall IVS_PU_SetSlaveDeviceRtspPara(ULONG ulIdentifyID, PU_SLAVE_RTSP_PARAM_S *pstSlaveRtspPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceRtspPara(ULONG ulIdentifyID, PU_SLAVE_RTSP_PARAM_S *pstSlaveRtspPara);

//获取从设备Onvif状态
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceOnvifStatus(ULONG ulIdentifyID, PU_SLAVE_ONVIF_STATUS_S *pstSlaveOnvifStatus);

//获取从设备Rtsp状态
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceRtspStatus(ULONG ulIdentifyID, PU_SLAVE_RTSP_STATUS_S *pstSlaveRtspStatus);

//设置、获取多机互助从设备使能参数
_HW_PU_API BOOL __stdcall IVS_PU_SetSlaveDeviceEnablePara(ULONG ulIdentifyID, PU_SLAVE_DEVICE_ENABLE_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceEnablePara(ULONG ulIdentifyID, PU_SLAVE_DEVICE_ENABLE_S *pstPara);

//设置、获取1拖N功能使能
//注意切换1拖N功能使能会导致设备重启
_HW_PU_API BOOL __stdcall IVS_PU_Set1TNEnable(ULONG ulIdentifyID, PU_1TN_ENABLE_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_Get1TNEnable(ULONG ulIdentifyID, PU_1TN_ENABLE_S *pstPara);

//获取多机互助主从通道信息
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveChannelInfo(ULONG ulIdentifyID, PU_MASTER_SLAVER_CHANNEL_INFO_S *pstPara);

//1拖N的方式列表获取，及当前类型的状态获取和切换
_HW_PU_API BOOL __stdcall IVS_PU_Get1TNSpptModeList(ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_LIST_S *pstParaList);
_HW_PU_API BOOL __stdcall IVS_PU_Set1TNSpptMode(ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_SWITCH_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_Get1TNSpptMode(ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_SWITCH_S *pstPara);

/******************************************************************************************************/
/*                                      IPC Dedicated Functions                                       */
/******************************************************************************************************/


/************************           Device Parameters Functions     ******************************/

//device video stream infos
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoStreamInfo(ULONG ulIdentifyID, LPPU_VIDEO_STREAM_INFO_S pstVideoStreamInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoStreamInfo(ULONG ulIdentifyID, LPPU_VIDEO_STREAM_INFO_S pstVideoStreamInfo);

//device video stream infos v2
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoStreamInfoV2(ULONG ulIdentifyID, LPPU_VIDEO_STREAM_INFO_V2_S pstVideoStreamInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoStreamInfoV2(ULONG ulIdentifyID, LPPU_VIDEO_STREAM_INFO_V2_S pstVideoStreamInfo);

//area crop parameter
_HW_PU_API BOOL __stdcall IVS_PU_GetAreaCropPara(ULONG ulIdentifyID, PU_AREA_CROP_PARA_S *pstAreaCropPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetAreaCropPara(ULONG ulIdentifyID, PU_AREA_CROP_PARA_S *pstAreaCropPara);
//设置恢复区域裁剪的按钮
_HW_PU_API BOOL __stdcall IVS_PU_SetAreaCropRestore(ULONG ulIdentifyID,PU_AREA_CROP_PARA_S *pstAreaCropPara);

//EPTZ control
_HW_PU_API BOOL __stdcall IVS_PU_EPTZControl(ULONG ulIdentifyID, PU_EPTZ_CTRL_S *pstEPTZCtrl);

//device audio stream infos
_HW_PU_API BOOL __stdcall IVS_PU_GetAudioStreamInfo(ULONG ulIdentifyID, LPPU_AUDIO_INFO_S pstAudioInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetAudioStreamInfo(ULONG ulIdentifyID, LPPU_AUDIO_INFO_S pstAudioInfo);

//音频质量增强
_HW_PU_API BOOL __stdcall IVS_PU_SetAiVqeStatus(ULONG ulIdentifyID, BOOL bAiVqeStatus);
_HW_PU_API BOOL __stdcall IVS_PU_GetAiVqeStatus(ULONG ulIdentifyID, BOOL *pbAiVqeStatus);

//回声消除
_HW_PU_API BOOL __stdcall IVS_PU_SetEchoCancelEnable(ULONG ulIdentifyID, PU_AEC_ENABLE_S *pstEchoCancelEnable);
_HW_PU_API BOOL __stdcall IVS_PU_GetEchoCancelEnable(ULONG ulIdentifyID, PU_AEC_ENABLE_S *pstEchoCancelEnable);

//device video display infos, and restore default display params
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoDisplayInfo(ULONG ulIdentifyID, LPPU_VIDEO_DISPLAY_INFO_S pstVideoDisplayInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoDisplayInfo(ULONG ulIdentifyID, LPPU_VIDEO_DISPLAY_INFO_S pstVideoDisplayInfo);
_HW_PU_API BOOL __stdcall IVS_PU_RestoreDefaultDisplayPara(ULONG ulIdentifyID, ULONG ulChannelId); 

//device ROI params
_HW_PU_API BOOL __stdcall IVS_PU_GetROIInfo(ULONG ulIdentifyID, LPPU_ROI_INFO_S pstROIInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetROIInfo(ULONG ulIdentifyID, LPPU_ROI_INFO_S pstROIInfo);

//device OSD params extern, can set at most 7 OSD strings
_HW_PU_API BOOL __stdcall IVS_PU_GetOsdText(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetOsdText(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara);

//device OSD margin
_HW_PU_API BOOL __stdcall IVS_PU_GetOSDMargin(ULONG ulIdentifyID, PU_OSD_MARGIN_INFO_S *pstOSDMarginInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetOSDMargin(ULONG ulIdentifyID, PU_OSD_MARGIN_INFO_S *pstOSDMarginInfo);

_HW_PU_API BOOL __stdcall IVS_PU_GetOsdTextEx(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);
_HW_PU_API BOOL __stdcall IVS_PU_SetOsdTextEx(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);

_HW_PU_API BOOL __stdcall IVS_PU_GetOsdTextExV2(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_EX_OUT_S pstOsdPartcularPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);
_HW_PU_API BOOL __stdcall IVS_PU_SetOsdTextExV2(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_EX_OUT_S pstOsdPartcularPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);

//device OSDI parameters setting
_HW_PU_API BOOL __stdcall IVS_PU_SetOSDIConfig(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA_S *pstOSDIConfig);
_HW_PU_API BOOL __stdcall IVS_PU_GetOSDIConfig(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA_S *pstOSDIConfig);
_HW_PU_API BOOL __stdcall IVS_PU_GetOSDIConfigV20(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA_V20_S *pstOSDIConfig);
_HW_PU_API BOOL __stdcall IVS_PU_MoveToOSDIArea(ULONG ulIdentifyID, ULONG ulChnID, ULONG ulIndex);
_HW_PU_API BOOL __stdcall IVS_PU_SetOSDIPosition(ULONG ulIdentifyID, PU_OSDI_POSITION_S *pstOSDIPostion);

//device privacy mask
_HW_PU_API BOOL __stdcall IVS_PU_GetPrivacyMask(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_ARRAY_S pstPrivacyMaskArray);
_HW_PU_API BOOL __stdcall IVS_PU_SetPrivacyMask(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_ARRAY_S pstPrivacyMaskArray);

//device privacy mask with color
_HW_PU_API BOOL __stdcall IVS_PU_GetPrivacyMaskEx(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_ARRAY_EX_S pstPrivacyMaskArrayEx);
_HW_PU_API BOOL __stdcall IVS_PU_SetPrivacyMaskEx(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_ARRAY_EX_S pstPrivacyMaskArrayEx);

//device privacy mask
_HW_PU_API BOOL __stdcall IVS_PU_GetPrivacyMaskArea(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_AREA_ARRAY_S pstPrivacyMaskAreaArray);
_HW_PU_API BOOL __stdcall IVS_PU_SetPrivacyMaskArea(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_AREA_ARRAY_S pstPrivacyMaskAreaArray);

_HW_PU_API BOOL __stdcall IVS_PU_AddPrivacyMaskArea(ULONG ulIdentifyID, PU_ADD_MASK_PARA_S *pstPrivacyMaskArea);
_HW_PU_API BOOL __stdcall IVS_PU_DelPrivacyMaskArea(ULONG ulIdentifyID, PU_DEL_MASK_PARA_S *pstPrivacyMaskArea);
_HW_PU_API BOOL __stdcall IVS_PU_PagedQueryPrivacyMask(ULONG ulIdentifyID, PU_PRIVACY_MASK_AREA_LIST_S *pstPrivacyMaskList);

#ifdef _WIN32
//set platform params
_HW_PU_API BOOL __stdcall IVS_PU_SetPlatformPara(ULONG ulIdentifyID, PU_PLATFORM_TYPE_E enPlatform, VOID *arg);
#endif

//IVS platform params 请注意:接口废弃,SDK接口不支持
_HW_PU_API BOOL __stdcall IVS_PU_GetIVSPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_IVS_PARA_S pstIvsPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIVSPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_IVS_PARA_S pstIvsPlatformPara);

//GBT 28281 platform params
_HW_PU_API BOOL __stdcall IVS_PU_GetGBTPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_GBT_PARA_S pstGbtPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGBTPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_GBT_PARA_S pstGbtPlatformPara);

//SDK platform params
_HW_PU_API BOOL __stdcall IVS_PU_GetSDKPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_SDK_PARA_S pstSdkPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSDKPlatformPara(ULONG ulIdentifyID, LPPU_PLATFORM_SDK_PARA_S pstSdkPlatformPara);

//get/set device dynamic stream info
_HW_PU_API BOOL __stdcall IVS_PU_GetDynamicStreamInfo(ULONG ulIdentifyID, LPPU_DYNAMIC_STREAM_INFO_S pstDynamicStreamInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetDynamicStreamInfo(ULONG ulIdentifyID, LPPU_DYNAMIC_STREAM_INFO_S pstDynamicStreamInfo);

//device watermark params
_HW_PU_API BOOL __stdcall IVS_PU_SetWaterMark(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enStreamType, BOOL bWaterMarkEnable);
_HW_PU_API BOOL __stdcall IVS_PU_GetWaterMark(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enStreamType, BOOL* pbWaterMarkEnable);

//device record plans (请注意:接口废弃,SDK接口不支持)
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordPlanList(ULONG ulIdentifyID, LPPU_RECORD_PLAN_S pstRecordPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordPlanList(ULONG ulIdentifyID, LPPU_RECORD_PLAN_S pstRecordPlan);

//get device record info
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordInfoList(ULONG ulIdentifyID, LPPU_RECORD_INQUIRE_S pstRecordInquire, LPPU_RECORD_LIST_S pstRecordList);
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordInfoListByUTC(ULONG ulIdentifyID, LPPU_RECORD_INQUIRE_S pstRecordInquire, LPPU_RECORD_LIST_S pstRecordList);
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmRecInfoList(ULONG ulIdentifyID, PU_ALARM_REC_INQ_REQ_S *pstAlarmRecInqReq, PU_ALARM_REC_INQ_RSP_S *pstAlarmRecInqRsp);

//delect device record file
_HW_PU_API BOOL __stdcall IVS_PU_DelRecordFile(ULONG ulIdentifyID, ULONG ulChannelId, CHAR* pszRecordFileName);

//device record full strategy
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordFullStrategy(ULONG ulIdentifyID, LPPU_RECORD_STRATEGY_S pstRecordStrategy);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordFullStrategy(ULONG ulIdentifyID, LPPU_RECORD_STRATEGY_S pstRecordStrategy);

//set cache record enable
_HW_PU_API BOOL __stdcall IVS_PU_SetCacheRecordType(ULONG ulIdentifyID, PU_CACHERECORD_E enCacheRecType);
_HW_PU_API BOOL __stdcall IVS_PU_GetCacheRecordType(ULONG ulIdentifyID, PU_CACHERECORD_E *penCacheRecType);

//set device stream layer code mode 
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamLayerCodeMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enStreamType, BOOL bEnable);
//get device stream layer code mode 
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamLayerCodeMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enStreamType, BOOL *pbEnable);

//set device stream function params
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamFunctionPara(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enPURecordStream, PU_STREAM_TYPE_E enPlatRecordStream);

//get device ability params 
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceAbility(ULONG ulIdentifyID, LPPU_DEVICE_ABILITY_S pstDeviceAbility);

//get device stream ability params
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamAbility(ULONG ulIdentifyID, LPPU_STREAM_ABILITY_S pstStreamAbilityPara);

//get device stream abilityV2 params
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamAbilityV2(ULONG ulIdentifyID, LPPU_STREAM_ABILITYV2_S pstStreamAbilityPara);
//device snapshot
_HW_PU_API BOOL __stdcall IVS_PU_StartSnapShot(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulSnapCount, ULONG ulSnapInterval, PU_SNAPSHOT_TYPE_E enSnapType);
_HW_PU_API BOOL __stdcall IVS_PU_ResponseUploadImageURL(ULONG ulIdentifyID, ULONG ulSessionId, PU_ERROR_CODE_E enErrorCode, CHAR *pszUploadURL);
_HW_PU_API BOOL __stdcall IVS_PU_ResponseUploadImageCompleteNotify(ULONG ulIdentifyID, ULONG ulSessionId, PU_ERROR_CODE_E enErrorCode);

//Manual snapshot 
_HW_PU_API BOOL __stdcall IVS_PU_ManualSnapshot(ULONG ulIdentifyID, PU_SNAPSHOT_PARA_S *pstSnapshotPara);

//Snapshot quality parameters
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotQuality(ULONG ulIdentifyID, PU_SNAPSHOT_QUAILTY_PARA_S *pstSnapshotQuality);
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotQuality(ULONG ulIdentifyID, PU_SNAPSHOT_QUAILTY_PARA_S *pstSnapshotQuality);

//Snapshot resolution parameters
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotResolution(ULONG ulIdentifyID, PU_SNAPSHOT_RESOLUTION_PARA_S *pstSnapshotRes);
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotResolution(ULONG ulIdentifyID, PU_SNAPSHOT_RESOLUTION_PARA_S *pstSnapshotRes);

//Snapshot retrans enable
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotRetransPara(ULONG ulIdentifyID, PU_SNAPSHOT_RETRANS_PARA_S *pstSnapshotRetrans);
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotRetransPara(ULONG ulIdentifyID, PU_SNAPSHOT_RETRANS_PARA_S *pstSnapshotRetrans);

_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotPicList(ULONG ulIdentifyID, PU_SNAPSHOT_INQUIRE_S *pstSnapshotInquire, PU_SNAPSHOT_LIST_S *pstSnapshotList);
_HW_PU_API BOOL __stdcall IVS_PU_DownloadSnapshotPic(ULONG ulIdentifyID, ULONG ulChnID, CHAR *szContentID, CHAR *szDownloadPath);

//device FEC params  请注意:接口废弃,SDK接口不支持
_HW_PU_API BOOL __stdcall IVS_PU_GetFECPara(ULONG ulIdentifyID, LPPU_FEC_PARA_S pstFecPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetFECPara(ULONG ulIdentifyID, LPPU_FEC_PARA_S pstFecPara);

//device SEC params
_HW_PU_API BOOL __stdcall IVS_PU_GetSECPara(ULONG ulIdentifyID, LPPU_SEC_PARA_S pstSecPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSECPara(ULONG ulIdentifyID, PU_SEC_PARA_S stSecPara);

//device EPTZ params  请注意:接口废弃,SDK接口不支持
_HW_PU_API BOOL __stdcall IVS_PU_GetEPTZPara(ULONG ulIdentifyID, LPPU_EPTZ_PARA_S pstEPTZPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetEPTZPara(ULONG ulIdentifyID, LPPU_EPTZ_PARA_S pstEPTZPara);

//device ONVIF protocol 
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFSwitch(ULONG ulIdentifyID, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFSwitch(ULONG ulIdentifyID, BOOL bEnable);

//ONVIF 消息有效期开关
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFExpiresSwitch(ULONG ulIdentifyID, PU_ONVIF_SWITCH_S *pstONVIFSwitch);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFExpiresSwitch(ULONG ulIdentifyID, PU_ONVIF_SWITCH_S *pstONVIFSwitch);

//ONVIF 版本信息
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFVersionType(ULONG ulIdentifyID, PU_ONVIF_VERSION_TYPE_S *pstONVIFVersionType);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFVersionType(ULONG ulIdentifyID, PU_ONVIF_VERSION_TYPE_S *pstONVIFVersionType);

//device ONVIF params
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFPwdPara(ULONG ulIdentifyID, LPPU_ONVIF_PWD_PARA_S pstOnvifPwdPara);

//device ONVIF stream params
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFStreamCodeType(ULONG ulIdentifyID, PU_VIDEO_CODE_TYPE_E *penVideoCodeType);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFStreamCodeType(ULONG ulIdentifyID, PU_VIDEO_CODE_TYPE_E enVideoCodeType);

//device ONVIF authentication type
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFAuthType(ULONG ulIdentifyID, PU_ONVIF_AUTH_TYPE_E *penOnvifAuthType);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFAuthType(ULONG ulIdentifyID, PU_ONVIF_AUTH_TYPE_E enOnvifAuthType);

//device Genetec protocol switch(请注意:接口废弃,SDK接口不支持)
_HW_PU_API BOOL __stdcall IVS_PU_GetGenetecSwitch(ULONG ulIdentifyID, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetGenetecSwitch(ULONG ulIdentifyID, BOOL bEnable);

//device Genetec protocol digest authentication switch(请注意:接口废弃,SDK接口不支持)
_HW_PU_API BOOL __stdcall IVS_PU_GetGenetecDigestAuthSwitch(ULONG ulIdentifyID, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetGenetecDigestAuthSwitch(ULONG ulIdentifyID, BOOL bEnable);

//device stream buffering params (请注意:接口废弃,SDK接口不支持)
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamSmoothPara(ULONG ulIdentifyID, LPPU_STREAM_SMOOTH_PARA_S pstStreamSmoothPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamSmoothPara(ULONG ulIdentifyID, LPPU_STREAM_SMOOTH_PARA_S pstStreamSmoothPara);

//I/P帧编码策略
_HW_PU_API BOOL __stdcall IVS_PU_GetKFCodingStrategyPara(ULONG ulIdentifyID, PU_KF_CODING_STRATEGY_PARA_S *pstKFCodingStrategyPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetKFCodingStrategyPara(ULONG ulIdentifyID, PU_KF_CODING_STRATEGY_PARA_S *pstKFCodingStrategyPara);

//device stream buffering params (请注意:接口废弃,SDK接口不支持)
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamSmoothParaEx(ULONG ulIdentifyID, LPPU_STREAM_SMOOTH_PARA_EX_S pstStreamSmoothPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamSmoothParaEx(ULONG ulIdentifyID, LPPU_STREAM_SMOOTH_PARA_EX_S pstStreamSmoothPara);

//device traffic shaping parameter
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficShapingPara(ULONG ulIdentifyID, PU_TRAFFIC_SHAPING_PARA_S *pstTrafficShapingPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficShapingPara(ULONG ulIdentifyID, PU_TRAFFIC_SHAPING_PARA_S *pstTrafficShapingPara);

//HTTP/HTTPS/RTSP port setting
_HW_PU_API BOOL __stdcall IVS_PU_GetDevicePortConfig(ULONG ulIdentifyID, PU_DEVICE_PORT_CONFIG_S *pstDevPortConfig);
_HW_PU_API BOOL __stdcall IVS_PU_SetDevicePortConfig(ULONG ulIdentifyID, PU_DEVICE_PORT_CONFIG_S *pstDevPortConfig);

//HTTP/HTTPS/RTSP port setting ex
_HW_PU_API BOOL __stdcall IVS_PU_GetDevicePortConfigEx(ULONG ulIdentifyID, PU_DEVICE_PORT_CONFIG_EX_S *pstDevPortConfig);
_HW_PU_API BOOL __stdcall IVS_PU_SetDevicePortConfigEx(ULONG ulIdentifyID, PU_DEVICE_PORT_CONFIG_EX_S *pstDevPortConfig);

//device qos dscp params
_HW_PU_API BOOL __stdcall IVS_PU_GetQosDscpPara(ULONG ulIdentifyID, PU_DSCP_TYPE_E *penDscpType, ULONG *pulDscpValue);
_HW_PU_API BOOL __stdcall IVS_PU_SetQosDscpPara(ULONG ulIdentifyID, PU_DSCP_TYPE_E enDscpType, ULONG ulDscpValue);

//device MTU value
_HW_PU_API BOOL __stdcall IVS_PU_GetMTUPara(ULONG ulIdentifyID, ULONG *pulMtuValue);
_HW_PU_API BOOL __stdcall IVS_PU_SetMTUPara(ULONG ulIdentifyID, ULONG ulMtuValue);

//device record upload band width
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordUploadBandwidth(ULONG ulIdentifyID, BOOL *pbEnable, ULONG *pulMaxUploadRate);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordUploadBandwidth(ULONG ulIdentifyID, BOOL bEnable, ULONG ulMaxUploadRate);

//device band width self adaption
_HW_PU_API BOOL __stdcall IVS_PU_GetBandwidthSelfAdaption(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetBandwidthSelfAdaption(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);

//device NTP params
_HW_PU_API BOOL __stdcall IVS_PU_GetNTPPara(ULONG ulIdentifyID, LPPU_NTP_PARA_S pstNtpPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetNTPPara(ULONG ulIdentifyID, LPPU_NTP_PARA_S pstNtpPara);

//device GPS params
_HW_PU_API BOOL __stdcall IVS_PU_GetGPSPara(ULONG ulIdentifyID, LPPU_GPS_PARA_S pstGPSPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGPSPara(ULONG ulIdentifyID, LPPU_GPS_PARA_S pstGPSPara);


//device TCP Accelerate Parameter
_HW_PU_API BOOL __stdcall IVS_PU_SetTCPAcceleratePara(ULONG ulIdentifyID, PU_TCP_ACCELERATE_PARA_S *pstTcpAcceleratePara);
_HW_PU_API BOOL __stdcall IVS_PU_GetTCPAcceleratePara(ULONG ulIdentifyID, PU_TCP_ACCELERATE_PARA_S *pstTcpAcceleratePara);

//device corridor mode
_HW_PU_API BOOL __stdcall IVS_PU_GetCorridorMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetCorridorMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);

//device OSD picture info
_HW_PU_API BOOL __stdcall IVS_PU_GetOSDPicturePara(ULONG ulIdentifyID, LPPU_OSD_PICTURE_PARA_S pstPicturePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetOSDPicturePara(ULONG ulIdentifyID, LPPU_OSD_PICTURE_PARA_S pstPicturePara);

//device snmp protocol params for v1/v2c
_HW_PU_API BOOL __stdcall IVS_PU_GetSnmpCommunityList(ULONG ulIdentifyID, LPPU_SNMP_COMMUNITY_LIST_S pstCommunityList);
_HW_PU_API BOOL __stdcall IVS_PU_SetSnmpCommunityList(ULONG ulIdentifyID, LPPU_SNMP_COMMUNITY_LIST_S pstCommunityList);

//device snmp protocol params for v1/v2c
_HW_PU_API BOOL __stdcall IVS_PU_GetSnmpCommunityListEx(ULONG ulIdentifyID, LPPU_SNMP_COMMUNITY_LIST_S_EX pstCommunityList);
_HW_PU_API BOOL __stdcall IVS_PU_SetSnmpCommunityListEx(ULONG ulIdentifyID, LPPU_SNMP_COMMUNITY_LIST_S_EX pstCommunityList);

//device snmp protocol params for v3
_HW_PU_API BOOL __stdcall IVS_PU_GetSnmpUserList(ULONG ulIdentifyID, LPPU_SNMPV3_USER_LIST_S pstUserList);
_HW_PU_API BOOL __stdcall IVS_PU_SetSnmpUserInfo(ULONG ulIdentifyID, LPPU_SNMPV3_USER_MGMT_S pstUserMgmtInfo);

//device snmp protocol trap params
_HW_PU_API BOOL __stdcall IVS_PU_GetSnmpTrapList(ULONG ulIdentifyID, LPPU_SNMP_TRAP_LIST_S pstTrapList);
_HW_PU_API BOOL __stdcall IVS_PU_SetSnmpTrapList(ULONG ulIdentifyID, LPPU_SNMP_TRAP_LIST_S pstTrapList);

//device 802.1x protocol params
_HW_PU_API BOOL __stdcall IVS_PU_Get802Dot1xConfig(ULONG ulIdentifyID, LPPU_DOT1X_CONFIG_INFO_S pstDot1xInfo);
_HW_PU_API BOOL __stdcall IVS_PU_Set802Dot1xConfig(ULONG ulIdentifyID, LPPU_DOT1X_CONFIG_INFO_S pstDot1xInfo);

//device web http/https 
_HW_PU_API BOOL __stdcall IVS_PU_GetWebHttpMode(ULONG ulIdentifyID, PU_WEB_HTTP_MODE_E* penHttpMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetWebHttpMode(ULONG ulIdentifyID, PU_WEB_HTTP_MODE_E enHttpMode);

//创建新HTTPS证书
_HW_PU_API BOOL __stdcall IVS_PU_SetHttpsCertificate(ULONG ulIdentifyID, PU_CREATE_HTTPS_CERT_S stHttpsCert);

//device onvif media keeplive
_HW_PU_API BOOL __stdcall IVS_PU_GetOnvifMediaKeepAliveMode(ULONG ulIdentifyID, BOOL* pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetOnvifMediaKeepAliveMode(ULONG ulIdentifyID, BOOL bEnable);

//device disk format
_HW_PU_API BOOL __stdcall IVS_PU_DiskFormat(ULONG ulIdentifyID);

//device disk format Ex
_HW_PU_API BOOL __stdcall IVS_PU_DiskFormatEx(ULONG ulIdentifyID,LPPU_HARD_DISK_S pstDisk);

//device sd card record status
_HW_PU_API BOOL __stdcall IVS_PU_GetSDCardRecordStatus(ULONG ulIdentifyID, LPPU_LOCAL_RECORD_S pstLocalRecord);
_HW_PU_API BOOL __stdcall IVS_PU_SetSDCardRecordStatus(ULONG ulIdentifyID, LPPU_LOCAL_RECORD_S pstLocalRecord);

//device sd card record time
_HW_PU_API BOOL __stdcall IVS_PU_GetSDCardRecordTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG* pulSeconds);
_HW_PU_API BOOL __stdcall IVS_PU_SetSDCardRecordTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulSeconds);

//查询SD卡状态
_HW_PU_API BOOL __stdcall IVS_PU_GetDiskState(ULONG ulIdentifyID, PU_HARD_DISK_STATE_S* pstDiskState);

//device video format
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceVideoFormat(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_FORMAT_E* penVideoFormat);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceVideoFormat(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_FORMAT_E enVideoFormat);

//设置收包速率限制
_HW_PU_API BOOL __stdcall IVS_PU_SetRecvRateLimit(ULONG ulIdentifyID, ULONG ulRecvRateLimit);
//获取收包速率限制
_HW_PU_API BOOL __stdcall IVS_PU_GetRecvRateLimit(ULONG ulIdentifyID, ULONG * pulRecvRateLimit);

//设置CVBS参数
_HW_PU_API BOOL __stdcall IVS_PU_SetCVBSPara(ULONG ulIdentifyID, PU_CVBS_PARA_S stCVBSResolution);
//获取CVBS参数
_HW_PU_API BOOL __stdcall IVS_PU_GetCVBSPara(ULONG ulIdentifyID, PU_CVBS_PARA_S *pstCVBSResolution);

//设置抓拍空间
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotSpace(ULONG ulIdentifyID, PU_SNAPSHOT_SPACE_S stSnapshotSpace);
//获取抓拍空间
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotSpace(ULONG ulIdentifyID, PU_SNAPSHOT_SPACE_S *pstSnapshotSpace);

//设置定时抓拍
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotTiming(ULONG ulIdentifyID, PU_SNAPSHOT_TIMING_PARA_S stSnapshotTiming);
//获取定时抓拍
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotTiming(ULONG ulIdentifyID, PU_SNAPSHOT_TIMING_PARA_S *pstSnapshotTiming);

//设置抓拍图片通过FTP/SFTP上传参数
_HW_PU_API BOOL __stdcall IVS_PU_SetFTPFileUploadPara(ULONG ulIdentifyID, PU_FTP_FILE_UPLOAD_PARA_S stFTPFileUpload);
//获取抓拍图片通过FTP/SFTP上传参数
_HW_PU_API BOOL __stdcall IVS_PU_GetFTPFileUploadPara(ULONG ulIdentifyID, PU_FTP_FILE_UPLOAD_PARA_S *pstFTPFileUpload);

//设置SD卡录像计划
_HW_PU_API BOOL __stdcall IVS_PU_SetSDCardRecordPlan(ULONG ulIdentifyID, PU_LOCAL_RECORD_PLAN_S stLocalRecordPlan);
//获取SD卡录像计划
_HW_PU_API BOOL __stdcall IVS_PU_GetSDCardRecordPlan(ULONG ulIdentifyID, PU_LOCAL_RECORD_PLAN_S *pstLocalRecordPlan);

//设置ABF后焦FOCUS变化，控制FOCUS往FAR或是NEAR方向运动，完成后不会自动聚焦
_HW_PU_API BOOL __stdcall IVS_PU_SetABFFocusAction(ULONG ulIdentifyID, PU_CAM_FOCUSCTRL_S *pstFocus);
//设置ABF后焦自动聚焦
_HW_PU_API BOOL __stdcall IVS_PU_SetABFAutoBackFocus(ULONG ulIdentifyID, ULONG ulChannelId);
//设置ABF后焦初始化
_HW_PU_API BOOL __stdcall IVS_PU_SetABFInitialPos(ULONG ulIdentifyID, ULONG ulChannelId);

//获取CMOS尺寸
_HW_PU_API BOOL __stdcall IVS_PU_GetCMOSSize(ULONG ulIdentifyID, PU_CMOS_SIZE_PARA_S *pstCMOSSizePara);

//架设高度
_HW_PU_API BOOL __stdcall IVS_PU_SetInstallHeight(ULONG ulIdentifyID, PU_CAM_INSTALL_HEIGHT_S *pstInstallHeight);
_HW_PU_API BOOL __stdcall IVS_PU_GetInstallHeight(ULONG ulIdentifyID, PU_CAM_INSTALL_HEIGHT_S *pstInstallHeight);

//地理位置
_HW_PU_API BOOL __stdcall IVS_PU_SetCamGeogPostion(ULONG ulIdentifyID, PU_CAM_GEOG_POSITION_S *pstCamGeogPostion);
_HW_PU_API BOOL __stdcall IVS_PU_GetCamGeogPostion(ULONG ulIdentifyID, PU_CAM_GEOG_POSITION_S *pstCamGeogPostion);

/******************************           Stream Functions     **********************************/

//key frame request
_HW_PU_API BOOL __stdcall IVS_PU_KeyFrameRequest(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulStreamId);

//real play callback function type
typedef VOID(CALLBACK *pfRealDataCallBack)(CHAR *szBuffer, LONG lSize, VOID *pUsrData);

//real play
_HW_PU_API ULONG __stdcall IVS_PU_RealPlay(ULONG ulIdentifyID, LPPU_REAL_PLAY_INFO_S pstRealPlayInfo, pfRealDataCallBack fRealDataCallBack, VOID *pUsrData);
_HW_PU_API ULONG __stdcall IVS_PU_RealPlay_V20(ULONG ulIdentifyID, PU_REAL_PLAY_INFO_V20_S *pstRealPlayInfo, PU_MEDIA_ENC_PARA_S *pstMediaEncPara, pfRealDataCallBack fRealDataCallBack, VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_StopRealPlay(ULONG ulIdentifyID, ULONG ulRealHandle);
_HW_PU_API BOOL __stdcall IVS_PU_StopAllRealPlay(ULONG ulIdentifyID);

//voice broadcast
_HW_PU_API ULONG __stdcall IVS_PU_StartVoiceBroadcast(ULONG ulIdentifyID, LPPU_VOICE_INFO_S pstVoiceBroadcastInfo);
_HW_PU_API BOOL __stdcall IVS_PU_StopVoiceBroadcast(ULONG ulIdentifyID, ULONG ulVBHandle);

//voice talk back callback function type
typedef VOID(CALLBACK *pfVoiceTBCallBack)(CHAR *szBuffer, LONG lSize, VOID *pUsrData);

//voice talk back
_HW_PU_API ULONG __stdcall IVS_PU_StartVoiceTB(ULONG ulIdentifyID, LPPU_VOICE_INFO_S pstVoiceTBInfo, pfVoiceTBCallBack fVoiceTBCallBack, VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_StopVoiceTB(ULONG ulIdentifyID, ULONG ulVoiceTBHandle);

//Feed voice data for voice talk back and broadcast
_HW_PU_API BOOL __stdcall IVS_PU_FeedVoiceData(ULONG ulIdentifyID, ULONG ulVBHandle, CHAR *pSendBuf, ULONG ulBufSize, ULONG ulType);

//save real play data
_HW_PU_API BOOL __stdcall IVS_PU_SaveRealData(ULONG ulIdentifyID, ULONG ulRealHandle, LPPU_SAVE_REALDATA_INFO_S pstSaveRealDataInfo);
_HW_PU_API BOOL __stdcall IVS_PU_StopSaveRealData(ULONG ulIdentifyID, ULONG ulRealHandle);

//save local snapshot picture 
_HW_PU_API BOOL __stdcall IVS_PU_SavePicture(ULONG ulIdentifyID, ULONG ulRealHandle, LPPU_SAVE_PICTURE_INFO_S pstSavePictureInfo);

//media signal 
_HW_PU_API BOOL __stdcall IVS_PU_MediaPlay(ULONG ulIdentifyID, LPPU_MEDIA_PLAY_INFO_S pstMediaPlayReqInfo, LPPU_MEDIA_PLAY_RSP_S pstMediaPlayRspInfo);
_HW_PU_API BOOL __stdcall IVS_PU_MeidaPlayAck(ULONG ulIdentifyID, ULONG ulSessionId, ULONG ulVideoPayload, ULONG ulAudioPayload, ULONG ulIgtPayload);
_HW_PU_API BOOL __stdcall IVS_PU_MeidaStop(ULONG ulIdentifyID, ULONG ulSessionId);
//新接口，功能与IVS_PU_MeidaPlayAck、IVS_PU_MeidaStop一致
_HW_PU_API BOOL __stdcall IVS_PU_MediaPlayAck(ULONG ulIdentifyID, ULONG ulSessionId, ULONG ulVideoPayload, ULONG ulAudioPayload, ULONG ulIgtPayload);
_HW_PU_API BOOL __stdcall IVS_PU_MediaStop(ULONG ulIdentifyID, ULONG ulSessionId);

//接口废弃，SDK不再支持
_HW_PU_API BOOL __stdcall IVS_PU_MediaPlayAckEx(ULONG ulIdentifyID, PU_MEDIA_PLAY_ACK_INFO_S *pstMediaPlayAckInfo);
_HW_PU_API BOOL __stdcall IVS_PU_MediaStopEx(ULONG ulIdentifyID, PU_MEDIA_PLAY_STOP_INFO_S *pstMediaPlayStopInfo);

//Set Multicast IP Address & Port
_HW_PU_API BOOL __stdcall IVS_PU_SetMulticastPara(ULONG ulIdentifyID, CHAR *szLocalIP, ULONG ulVideoPort);
_HW_PU_API BOOL __stdcall IVS_PU_GetMulticastPara(ULONG ulIdentifyID, CHAR *szLocalIP, ULONG *ulVideoPort);

//Set Multicast IP Address & Port ex
_HW_PU_API BOOL __stdcall IVS_PU_SetMulticastParaEx(ULONG ulIdentifyID, PU_MULTICAST_PARA_S *pstParam);
_HW_PU_API BOOL __stdcall IVS_PU_GetMulticastParaEx(ULONG ulIdentifyID, PU_MULTICAST_PARA_S *pstParam);

//Start Multicast
_HW_PU_API ULONG __stdcall IVS_PU_StartMulticast(ULONG ulIdentifyID, CHAR *szLocalIP, ULONG ulVideoPort);
_HW_PU_API BOOL __stdcall IVS_PU_StopMulticast(ULONG ulIdentifyID, ULONG ulSessionId);

//Set Sound Switch
_HW_PU_API BOOL __stdcall IVS_PU_SetSoundSwitch(ULONG ulIdentifyID, ULONG ulRealHandle, BOOL bEnable);

/***************************           ISP Parameters Functions     *********************************/

//device ISP parameter
_HW_PU_API BOOL __stdcall IVS_PU_SetISPPara(ULONG ulIdentifyID, LPPU_ISP_PARTICULAR_PARA_S pstISPPara, ULONG *ulBitmap);
_HW_PU_API BOOL __stdcall IVS_PU_GetISPPara(ULONG ulIdentifyID, LPPU_ISP_PARTICULAR_PARA_S pstISPPara);

//device iris emendation
_HW_PU_API BOOL __stdcall IVS_PU_IrisEmendation(ULONG ulIdentifyID, LPPU_IRIS_EMENDATION_S pstIrisEmendation);

//device flicker mode
_HW_PU_API BOOL __stdcall IVS_PU_GetFlickerMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_FLICKER_MODE_E *penFlickerMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetFlickerMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_FLICKER_MODE_E enFlickerMode);

//device AE metering mode
_HW_PU_API BOOL __stdcall IVS_PU_GetAEMeteringMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_AEMETERING_MODE_E *penAEMeteringMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetAEMeteringMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_VIDEO_AEMETERING_MODE_E enAEMeteringMode);

//device WDR enable state
_HW_PU_API BOOL __stdcall IVS_PU_GetWDR(ULONG ulIdentifyID, ULONG ulChannelId, PU_WDR_SWITCH_MODE_E *penSwitchMode, ULONG *pulAutoType, ULONG *pulSensitivity);
_HW_PU_API BOOL __stdcall IVS_PU_SetWDR(ULONG ulIdentifyID, ULONG ulChannelId, PU_WDR_SWITCH_MODE_E enSwitchMode, ULONG ulAutoType, ULONG ulSensitivity);

//device white balance mode  请注意:接口废弃，使用IVS_PU_GetISPPara/IVS_PU_SetISPPara设置白平衡
_HW_PU_API BOOL __stdcall IVS_PU_GetWhiteBalanceMode(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulWBMode, ULONG *pulRedOffset, ULONG *pulBlueOffset);
_HW_PU_API BOOL __stdcall IVS_PU_SetWhiteBalanceMode(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulWBMode, ULONG ulRedOffset, ULONG ulBlueOffset);

//device slow shutter mode
_HW_PU_API BOOL __stdcall IVS_PU_GetSlowShutterMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetSlowShutterMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);

//device automatic exposure response time 请注意:接口废弃,SDK接口不支持
_HW_PU_API BOOL __stdcall IVS_PU_GetAEResponseTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulAERspTime);
_HW_PU_API BOOL __stdcall IVS_PU_SetAEResponseTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulAERspTime);

//device exposure compensation
_HW_PU_API BOOL __stdcall IVS_PU_GetExposureCompensation(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulCoefficient);
_HW_PU_API BOOL __stdcall IVS_PU_SetExposureCompensation(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulCoefficient);

//device typical scene
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalSceneMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_TYPICAL_SCENE_MODE_E *penMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetTypicalSceneMode(ULONG ulIdentifyID, ULONG ulChannelId, PU_TYPICAL_SCENE_MODE_E enMode);

//device typical scene extension
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalSceneModeEx(ULONG ulIdentifyID, PU_ISP_TYPICAL_SCENE_MODE_S *pstParam);
_HW_PU_API BOOL __stdcall IVS_PU_SetTypicalSceneModeEx(ULONG ulIdentifyID, PU_ISP_TYPICAL_SCENE_MODE_S *pstParam);

//device typical scene information
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalSceneList(ULONG ulIdentifyID, LPPU_TYPICAL_SCENE_LIST_S pstTypecalSceneList);

//device typical scene information
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalSceneListEx(ULONG ulIdentifyID, LPPU_TYPICAL_SCENE_LIST_EX_OUT_S pstTypecalSceneList);

//device typical scene parameter
_HW_PU_API BOOL __stdcall IVS_PU_SetISPProfilePara(ULONG ulIdentifyID, PU_ISP_PROFILES_PARA_S *pstIspProfilePara);
_HW_PU_API BOOL __stdcall IVS_PU_GetISPProfilePara(ULONG ulIdentifyID, PU_ISP_PROFILES_PARA_S *pstIspProfilePara);

//device typical scene plan
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalScenePlan(ULONG ulIdentifyID, LPPU_MONTHS_PLAN_S pstMonthPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetTypicalScenePlan(ULONG ulIdentifyID, LPPU_MONTHS_PLAN_S pstMonthPlan);
//典型场景计划扩充，增加EndTime
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalScenePlanV2(ULONG ulIdentifyID, LPPU_MONTHS_PLAN_S pstMonthPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetTypicalScenePlanV2(ULONG ulIdentifyID, LPPU_MONTHS_PLAN_S pstMonthPlan);

//isp profiles link
_HW_PU_API BOOL __stdcall IVS_PU_GetIspProfilesLink(ULONG ulIdentifyID, LPPU_ISP_PROFILES_LINK_INFO_S pstIspProfileLink);
_HW_PU_API BOOL __stdcall IVS_PU_SetIspProfilesLink(ULONG ulIdentifyID,  LPPU_ISP_PROFILES_LINK_INFO_S pstIspProfileLink);

//device blaze restrain
_HW_PU_API BOOL __stdcall IVS_PU_GetBlazeRestrain(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable, ULONG *pulBlazeRestrainLevel);
_HW_PU_API BOOL __stdcall IVS_PU_SetBlazeRestrain(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable,	ULONG ulBlazeRestrainLevel);

//device defog type
_HW_PU_API BOOL __stdcall IVS_PU_GetDefogType(ULONG ulIdentifyID, ULONG ulChannelId, PU_DEFOG_TYPE_E *penDefogType);
_HW_PU_API BOOL __stdcall IVS_PU_SetDefogType(ULONG ulIdentifyID, ULONG ulChannelId, PU_DEFOG_TYPE_E enDefogType);

//device Noise reduction switch
_HW_PU_API BOOL __stdcall IVS_PU_GetNoiseReductionMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable, ULONG *pulCoefficient);
_HW_PU_API BOOL __stdcall IVS_PU_SetNoiseReductionMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable, ULONG ulCoefficient);

//设置降噪模式
_HW_PU_API BOOL __stdcall IVS_PU_GetNoiseReductionModeEx(ULONG ulIdentifyID, PU_NOISE_REDUCTION_S *pstNoiseReduction);
_HW_PU_API BOOL __stdcall IVS_PU_SetNoiseReductionModeEx(ULONG ulIdentifyID, PU_NOISE_REDUCTION_S stNoiseReduction);

//自动光圈参数 
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoAperturePara(ULONG ulIdentifyID, PU_AUTO_APERTURE_PARA_S * pstAutoAperturePara);
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoAperturePara(ULONG ulIdentifyID, PU_AUTO_APERTURE_PARA_S * pstAutoAperturePara);

//聚焦区域设置功能
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoFocusArea(ULONG ulIdentifyID, PU_PTZ_FOCUSAREA_S stAutoFocusArea);
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoFocusArea(ULONG ulIdentifyID, PU_PTZ_FOCUSAREA_S *pstAutoFocusArea);


/***************************           PTZ Parameters Functions     *********************************/

//device serial port info
_HW_PU_API BOOL __stdcall IVS_PU_GetSerialPortInfo(ULONG ulIdentifyID, LPPU_SERIAL_PORT_PARA_S pstSerialPortPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSerialPortInfo(ULONG ulIdentifyID, LPPU_SERIAL_PORT_PARA_S pstSerialPortPara);

//device ptz preset
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_Preset(ULONG ulIdentifyID, LPPU_PTZ_PRESET_PARA_S pstPtzPresetPara);
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_PresetWithFocusInfo(ULONG ulIdentifyID, LPPU_PTZ_PRESET_PARA_EX_S pstPtzPresetPara);
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_GetPresetList(ULONG ulIdentifyID, LPPU_PTZ_PRESET_LIST_PARA_S pstPtzPresetList);
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_GetPresetListWithFocusInfo(ULONG ulIdentifyID, LPPU_PTZ_PRESET_LIST_PARA_EX_S pstPtzPresetList);

//device ptz control
_HW_PU_API BOOL __stdcall IVS_PU_PTZControl(ULONG ulIdentifyID, LPPU_PTZ_CONTROL_PARA_S pstPtzControlPara);

//device ptz cruise track
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_CruiseTrack(ULONG ulIdentifyID, LPPU_PTZ_CRUISE_TRACK_PARA_S pstPtzCruiseTrack);

//device ptz info
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZInfo(ULONG ulIdentifyID, LPPU_PTZ_PARA_S pstPtzPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZInfo(ULONG ulIdentifyID, LPPU_PTZ_PARA_S pstPtzPara);

//device guard position params(only guard preset)
_HW_PU_API BOOL __stdcall IVS_PU_GetGuardPositionPara(ULONG ulIdentifyID, LPPU_GUARD_POSITION_PARA_S pstGuardPositionPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGuardPositionPara(ULONG ulIdentifyID, LPPU_GUARD_POSITION_PARA_S pstGuardPositionPara);

//delete device guard position
_HW_PU_API BOOL __stdcall IVS_PU_DelGuardPosition(ULONG ulIdentifyID);

//device guard position params
_HW_PU_API BOOL __stdcall IVS_PU_GetGuardPositionParaEx(ULONG ulIdentifyID, LPPU_GUARD_POSITION_PARA_EX_S pstGuardPositionParaEx);
_HW_PU_API BOOL __stdcall IVS_PU_SetGuardPositionParaEx(ULONG ulIdentifyID, LPPU_GUARD_POSITION_PARA_EX_S pstGuardPositionParaEx);

//device ptz current location 
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCurrentLocation(ULONG ulIdentifyID, LPPU_PTZ_CURRENT_LOCATION_S pstCurrentLocation);
_HW_PU_API BOOL __stdcall IVS_PU_RotatePTZLocation(ULONG ulIdentifyID, LPPU_PTZ_CURRENT_LOCATION_S pstDstLocation);

//device ptz multi motor
_HW_PU_API BOOL __stdcall IVS_PU_PTZMultiMotor(ULONG ulIdentifyID, PU_PTZ_OPCODE_E enDirection, ULONG ulHorSpeed, ULONG ulVerSpeed);
_HW_PU_API BOOL __stdcall IVS_PU_MultiDirectionMove(ULONG ulIdentifyID, PU_PTZ_OPCODE_E enDirection, ULONG ulHorSpeed, ULONG ulVerSpeed);

//device transparent channel
_HW_PU_API BOOL __stdcall IVS_PU_GetTransparentChannelPara(ULONG ulIdentifyID, ULONG ulSerialPort, BOOL* pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetTransparentChannelPara(ULONG ulIdentifyID, ULONG ulSerialPort, BOOL bEnable);
_HW_PU_API BOOL __stdcall IVS_PU_InvokeTransparentCmd(ULONG ulIdentifyID, LPPU_TRANSPARENT_CMD_S pstTransparentCmdInfo);

typedef VOID(CALLBACK *pfTransChnDataCallBack)(LONG lHandle, CHAR *szBuffer, LONG lSize, VOID *pUsrData);
_HW_PU_API LONG __stdcall IVS_PU_RecvTransChnDataStart(ULONG ulIdentifyID, ULONG ulSerialPort, pfTransChnDataCallBack pfTransChnCBFunc, VOID *pUserData);
_HW_PU_API LONG __stdcall IVS_PU_RecvTransChnDataStop(ULONG ulIdentifyID);

//device infrared light params
_HW_PU_API BOOL __stdcall IVS_PU_GetInfraredLightPara(ULONG ulIdentifyID, LPPU_IRLIGHT_LIST_S pstIRLightPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetInfraredLightPara(ULONG ulIdentifyID, LPPU_IRLIGHT_LIST_S pstIRLightPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetInfraredLightStatus(ULONG ulIdentifyID, LPPU_IRLIGHT_LIST_S pstIRLightPara);

//补光灯参数
_HW_PU_API BOOL __stdcall IVS_PU_GetSupplementLightPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LIGHT_INFO_S *pstSupplementLightInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetSupplementLightPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LIGHT_INFO_S *pstSupplementLightInfo);

//device ptz relative location
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZRelativeLocation(ULONG ulIdentifyID, ULONG ulPtzId, BOOL* pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZRelativeLocation(ULONG ulIdentifyID, ULONG ulPtzId, BOOL bEnable);

//device ptz aux mode 
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZAuxMode(ULONG ulIdentifyID, ULONG ulPtzId, PU_PTZ_AUX_MODE_E* penAuxMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZAuxMode(ULONG ulIdentifyID, ULONG ulPtzId, PU_PTZ_AUX_MODE_E enAuxMode);

//device ptz camera information 
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCameraInfoMode(ULONG ulIdentifyID, ULONG ulPtzId, BOOL* pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZCameraInfoMode(ULONG ulIdentifyID, ULONG ulPtzId, BOOL bEnable);

_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCameraInfoModeV20(ULONG ulIdentifyID, ULONG ulPtzId, PTZ_OSD_MODE_E *penOSDMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZCameraInfoModeV20(ULONG ulIdentifyID, ULONG ulPtzId, PTZ_OSD_MODE_E *penOSDMode);

//device ptz focus mode 
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZFocusMode(ULONG ulIdentifyID, ULONG ulPtzId, PU_FOCUS_MODE_E* penFocusMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZFocusMode(ULONG ulIdentifyID, ULONG ulPtzId, PU_FOCUS_MODE_E enFocusMode);

_HW_PU_API BOOL __stdcall IVS_PU_GetPTZFocusModeV20(ULONG ulIdentifyID, PU_PTZ_FOCUS_MODE_S* pstFocusMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZFocusModeV20(ULONG ulIdentifyID, PU_PTZ_FOCUS_MODE_S* pstFocusMode);

_HW_PU_API BOOL __stdcall IVS_PU_GetPTZSpeed(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_S *pstPTZSpeed);
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZSpeedAbility(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_ABILITY *pstPTZSpeedAbility);
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZSpeedLimit(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_LIMIT_S *pstPTZSpeedLimit);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZSpeedLimit(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_LIMIT_S *pstPTZSpeedLimit);

//device ptz presetting_position camera freeze
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZPresetFreezing(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZPresetFreezing(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);

//垂直限位
_HW_PU_API BOOL __stdcall IVS_PU_SetVerticalLimit(ULONG ulIdentifyID, PU_VERTICAL_LIMIT_S stVerticalLimit);
_HW_PU_API BOOL __stdcall IVS_PU_GetVerticalLimit(ULONG ulIdentifyID, PU_VERTICAL_LIMIT_S *pstVerticalLimit);

//DDNS
_HW_PU_API BOOL __stdcall IVS_PU_SetDDNSPara(ULONG ulIdentifyID, PU_DDNS_CONF_INFO_S stDDNSpara);
_HW_PU_API BOOL __stdcall IVS_PU_GetDDNSPara(ULONG ulIdentifyID, PU_DDNS_CONF_INFO_S *pstDDNSpara);

//聚焦补偿信息 
_HW_PU_API BOOL __stdcall IVS_PU_SetFocusCompensation(ULONG ulIdentifyID, PU_FOCUS_COMPENSATION_S stFocusCompensation);
_HW_PU_API BOOL __stdcall IVS_PU_GetFocusCompensation(ULONG ulIdentifyID, PU_FOCUS_COMPENSATION_S *pstFocusCompensation);

//获取镜头信息
_HW_PU_API BOOL __stdcall IVS_PU_GetCurrentLensInfo(ULONG ulIdentifyID, PU_LENS_INFO_S *pstLensInfo);

/************************      Intelligent Traffic System Functions     ******************************/

//车牌参数信息
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPara(ULONG ulIdentifyID, PU_VLPR_PARA_S *pstVLPRPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPara(ULONG ulIdentifyID, PU_VLPR_PARA_S *pstVLPRPara);
//车牌参数信息，扩展算法类型
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRParaV2(ULONG ulIdentifyID, PU_VLPR_PARA_V2_S *pstVLPRPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRParaV2(ULONG ulIdentifyID, PU_VLPR_PARA_V2_S *pstVLPRPara);
//车牌参数信息，继续扩展
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRParaV3(ULONG ulIdentifyID, PU_VLPR_PARA_V3_S *pstVLPRPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRParaV3(ULONG ulIdentifyID, PU_VLPR_PARA_V3_S *pstVLPRPara);

//手动触发车牌抓拍
_HW_PU_API BOOL __stdcall IVS_PU_ManualLicensePlateCapture(ULONG ulIdentifyID, PU_MANUAL_LPR_CAPTURE_S *pstManualLprCapture);

//图片叠加参数
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicSynthesisPara(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicSynthesisPara(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicSynthesisParaV2(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_V2_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicSynthesisParaV2(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_V2_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicSynthesisParaV3(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_V3_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicSynthesisParaV3(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_V3_S *pstVLPRPicSynthesisPara);

//OSD叠加参数(不支持电警款型)
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicOSDPara(ULONG ulIdentifyID, PU_PIC_OSD_PARA_S *pstVLPRPicOSDPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicOSDPara(ULONG ulIdentifyID, PU_PIC_OSD_PARA_S *pstVLPRPicOSDPara);

_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicOSDParaV2(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V2_S *pstVLPRPicOSDPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicOSDParaV2(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V2_S *pstVLPRPicOSDPara);

_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicOSDParaV3(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V3_S *pstVLPRPicOSDPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicOSDParaV3(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V3_S *pstVLPRPicOSDPara);

//图片数字水印校验
_HW_PU_API BOOL __stdcall IVS_PU_CheckVLPRPicWaterMark(CHAR *szFilePath);

//车牌抓拍数据订阅
_HW_PU_API BOOL __stdcall IVS_PU_RecvVLPRDataStart(ULONG ulIdentifyID);
_HW_PU_API BOOL __stdcall IVS_PU_RecvVLPRDataStop(ULONG ulIdentifyID);

/************************      Intelligent outoffocus Functions     ******************************/
//虚焦检测标定值计算
_HW_PU_API BOOL __stdcall IVS_PU_SetOFDStandValueCal(ULONG ulIdentifyID, PU_OUTOFFOCUS_DETECT_PARA_S *pstPara);

/***************************          Alarm Parameters Functions     ********************************/

//device alarm callback function type
typedef LONG(CALLBACK *pfGetAlarmInfoCallBack)(LPPU_ALARM_REPORT_S pstAlarmReport, VOID *pUsrData);
//register device alarm callback function
_HW_PU_API BOOL __stdcall IVS_PU_AlarmInfoStatesCallBack(ULONG ulIdentifyID, pfGetAlarmInfoCallBack fAlarmResportCallBack, VOID *pUsrData);

typedef LONG(CALLBACK *pfGetAlarmInfoCallBack_V20)(LPPU_ALARM_REPORT_S pstAlarmReport, VOID *pAlarmInfo, ULONG ulAlarmInfoSize, VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_AlarmInfoStatesCallBack_V20(ULONG ulIdentifyID, pfGetAlarmInfoCallBack_V20 fAlarmResportCallBack, VOID *pUsrData);


//device alarm params, include: temperature alarm, motion detection alarm, hide alarm
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmPara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, VOID *arg);
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmPara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, VOID *arg);

//set device guard 
_HW_PU_API BOOL __stdcall IVS_PU_GuardAlarm(ULONG ulIdentifyID, LPPU_GUARD_PARA_S pstGuardPara);

//get device guard state
_HW_PU_API BOOL __stdcall IVS_PU_GetGuardState(ULONG ulIdentifyID, LPPU_GUARD_STATE_S pstGuardStates);

//get device current temperature
_HW_PU_API BOOL __stdcall IVS_PU_GetTemperature(ULONG ulIdentifyID, LONG *plCurretTemp);

//device switch input and output params
_HW_PU_API BOOL __stdcall IVS_PU_GetDIOPara(ULONG ulIdentifyID, LPPU_DIO_PARA_S pstSwitchDioPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetDIOPara(ULONG ulIdentifyID, LPPU_DIO_PARA_S pstSwitchDioPara);

//device DI state
_HW_PU_API BOOL __stdcall IVS_PU_GetDIState(ULONG ulIdentifyID, ULONG ulInputId, LONG *plInputState);

//device DO state
_HW_PU_API BOOL __stdcall IVS_PU_GetDOState(ULONG ulIdentifyID, ULONG ulOutputId, LONG *plOutputState);
_HW_PU_API BOOL __stdcall IVS_PU_SetDOState(ULONG ulIdentifyID, ULONG ulOutputId, LONG lOutputState);

//device alarm linkage para with alarm type
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmLinkagePara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, ULONG ulAlarmId, LPPU_ALARM_LINKAGE_PARA_S pstAlarmLinkagePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmLinkagePara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, ULONG ulAlarmId, LPPU_ALARM_LINKAGE_PARA_S pstAlarmLinkagePara);

//人车分离
//函数接口未过期，但由于内存原因，基于该接口的参数（人车物分离）某些型号不支持。具体支持情况如下:
// （1）颜色提取：除IPC6125-WDL-Fb、IPC6126-WDL-E、IPC6224-VRZ-B、IPC6325-WD-VRZ-B、IPC6256-VRZ、IPC6355-VRZ款型外，其他款型均不支持该功能，元数据发送的颜色参数均为默认值0;
// （2）人车物分离：
//      <1> C系列：除IPC6125-WDL-Fb、IPC6126-WDL-E、IPC6224-VRZ-B、IPC6325-WD-VRZ-B、IPC6256-VRZ、IPC6355-VRZ款型外，其他款型均不支持人车物分离功能，元数据发送的颜色参数均为默认值0;
//      <2> X系列和M系列均不支持人车物分离功能，元数据发送的颜色参数均为默认值0。

_HW_PU_API BOOL __stdcall IVS_PU_SetHVAlarmPara(ULONG ulIdentifyID, PU_HV_ALARM_PARA_S stAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetHVAlarmPara(ULONG ulIdentifyID, PU_HV_ALARM_PARA_S *pstAlarmPara);





/************************      Intelligent Parameters Functions     ******************************/

//device intelligent switch params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtPara(ULONG ulIdentifyID, LPPU_IGT_ALARM_PARA_S pstIgtAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtPara(ULONG ulIdentifyID, LPPU_IGT_ALARM_PARA_S pstIgtAlarmPara);

//device intelligent tripwire alarm params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtTripwireAlarmPara(ULONG ulIdentifyID, LPPU_TW_ALARM_PARA_S pstIgtTwAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtTripwireAlarmPara(ULONG ulIdentifyID, LPPU_TW_ALARM_PARA_S pstIgtTwAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_IgtTripwireLineItem(ULONG ulIdentifyID, LPPU_IGT_TW_LINE_ITEM_S pstLineItem);

//device intelligent area detection alarm params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtAreaDtcAlarmPara(ULONG ulIdentifyID, PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType, LPPU_IGT_AREADTC_ALARM_PARA_S pstIgtAreaDtcAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtAreaDtcAlarmPara(ULONG ulIdentifyID, PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType, LPPU_IGT_AREADTC_ALARM_PARA_S pstIgtAreaDtcAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_IgtAreaItem(ULONG ulIdentifyID, LPPU_IGT_AREA_ITEM_S pstAreaItem);

//该接口是机器学习人脸检测接口，适用于V5R19C20版本之前所有款型，以及V5R19C20版本之后C系列款型的摄像机。
//若需在V5R19C20及之后版本的其他款型调用该功能，请使用IVS_PU_GetAlarmPara、IVS_PU_SetAlarmPara (告警类型：PU_ALARM_TYPE_FD_DL)。
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceDetectPara(ULONG ulIdentifyID, PU_FACE_DETC_ALARM_PARA_S *pstFDAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceDetectPara(ULONG ulIdentifyID, PU_FACE_DETC_ALARM_PARA_S *pstFDAlarmPara);

//机非人
_HW_PU_API BOOL __stdcall IVS_PU_GetVHDPara(ULONG ulIdentifyID, PU_VHD_PARA_S *pstVHDPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVHDPara(ULONG ulIdentifyID, PU_VHD_PARA_S *pstVHDPara);

//机非人扩充,扩充
_HW_PU_API BOOL __stdcall IVS_PU_GetVHDParaEx(ULONG ulIdentifyID, PU_VHD_PARA_EX_S *pstVHDPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVHDParaEx(ULONG ulIdentifyID, PU_VHD_PARA_EX_S *pstVHDPara);

//智能新增3559人脸属性
_HW_PU_API BOOL __stdcall IVS_PU_Get3559FaceAttribute(ULONG ulIdentifyID, PU_ATTRI_DL_PARAMETER_S *pstFaceAttribute);
_HW_PU_API BOOL __stdcall IVS_PU_Set3559FaceAttribute(ULONG ulIdentifyID, PU_ATTRI_DL_PARAMETER_S *pstFaceAttribute);

//3559人脸识别元数据发送匿名设置
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceRecogDLAnonymousPara(ULONG ulIdentifyID, PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S *pstFaceRecogDLAnonymous);
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceRecogDLAnonymousPara(ULONG ulIdentifyID, PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S *pstFaceRecogDLAnonymous);

//人脸识别参数
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceRecogPara(ULONG ulIdentifyID, PU_FACE_RECOGNITION_PARA_S *pstFaceRecogPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceRecogPara(ULONG ulIdentifyID, PU_FACE_RECOGNITION_PARA_S *pstFaceRecogPara);

//球机自检
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZCheck(ULONG ulIdentifyID, PU_PTZ_CHECK_PARA_S *pstPTZCheck);

_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCheck(ULONG ulIdentifyID, PU_PTZ_CHECK_PARA_S *pstPTZCheck);



/******************************************************************************************************/
/*                                      DEC Dedicated Functions                                       */
/******************************************************************************************************/


//获取解码器端口能力列表(接口废弃，sdk不支持)
_HW_PU_API BOOL __stdcall IVS_PU_GetDecPortAbility(ULONG ulIdentifyID, LPPU_DEC_PORT_ABILITY_LIST_S pstDecIOAbilityList);

//获取解码器端口信息列表（接口废弃，sdk不支持）
_HW_PU_API BOOL __stdcall IVS_PU_GetDecPortInfoList(ULONG ulIdentifyID, LPPU_DEC_PORT_INFO_LIST_S pstDecPortInfoList);

//设置解码器端口参数（接口废弃，sdk不支持）
_HW_PU_API BOOL __stdcall IVS_PU_SetDecPortInfoList(ULONG ulIdentifyID, LPPU_DEC_PORT_INFO_LIST_S pstDecPortInfoList);

//获取解码器通道能力列表
_HW_PU_API BOOL __stdcall IVS_PU_GetDecChannelAbility(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_ABILITY_LIST_S pstDecChannelAbilityList);

//获取解码器通道信息列表(接口废弃，sdk不支持)
_HW_PU_API BOOL __stdcall IVS_PU_GetDecChannelInfoList(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_INFO_LIST_S pstDecChannelInfoList);

//设置通道参数(接口废弃，sdk不支持)
_HW_PU_API BOOL __stdcall IVS_PU_SetDecChannelInfo(ULONG ulIdentifyID, LPPU_DEC_CHANNEL_INFO_S pstDecChannelInfo);

//设置解码器的解密信息(接口废弃，sdk不支持)    
_HW_PU_API BOOL __stdcall IVS_PU_SetDecDecryptionInfo(ULONG ulIdentifyID, LPPU_DEC_DECRYPTION_INFO_S pstDecDecryptionInfo);

//设置解码器音频端口参数(接口废弃，sdk不支持)
_HW_PU_API BOOL __stdcall IVS_PU_SetDecAudioPortInfo(ULONG ulIdentifyID, LPPU_DEC_AUDIO_INFO_S pstDecAudioInfo);

//获取解码器音频端口参数(接口废弃，sdk不支持)
_HW_PU_API BOOL __stdcall IVS_PU_GetDecAudioPortInfo(ULONG ulIdentifyID, LPPU_DEC_AUDIO_INFO_S pstDecAudioInfo);

//开始解码(接口废弃，sdk不支持)
_HW_PU_API LONG __stdcall IVS_PU_StartDec(ULONG ulIdentifyID, LPPU_DEC_INFO_S *pstDecInfo);

//向解码器发送数据流,只支持25帧的发流
_HW_PU_API BOOL __stdcall IVS_PU_MatrixSendData(ULONG ulPassiveHandle, CHAR *pSendBuf, ULONG ulBufSize, ULONG ulType);

//向解码器发送数据流,支持动态修改帧率
_HW_PU_API BOOL __stdcall IVS_PU_MatrixSendDataEx(ULONG ulPassiveHandle, CHAR *pSendBuf, ULONG ulBufSize, ULONG ulType, ULONG ulFrameRate);

//初始化解码业务（接口废弃，sdk不支持）
_HW_PU_API BOOL __stdcall IVS_PU_InitDecBusiness(ULONG ulIdentifyID, ULONG ulChannelId, PU_PROTOCOL_TYPE_E enProtocolType, LPPU_INIT_DECODE_INFO_RSP_S pstInitDecRspInfo);

//开始解码业务（接口废弃，sdk不支持）
_HW_PU_API BOOL __stdcall IVS_PU_StartDecBusiness(ULONG ulIdentifyID, LPPU_START_DECODE_INFO_S pstStartDecInfo);

//停止解码（接口废弃，sdk不支持）
_HW_PU_API BOOL __stdcall IVS_PU_StopDec(ULONG ulIdentifyID, ULONG ulChannelId);

//停止所有解码（接口废弃，sdk不支持）
_HW_PU_API BOOL __stdcall IVS_PU_StopDecAll(ULONG ulIdentifyID);

//获取实际OSD信息
_HW_PU_API BOOL __stdcall IVS_PU_GetRealOsdText(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_EX_OUT_S pstRealOsdPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);

//获取告警联动优先级
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmLinkPriority(ULONG ulIdentifyID, LPPU_ALARM_LINK_PRIORITY_PARA_S pstAlarmLinkPriority);

//设置告警联动优先级
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmLinkPriority(ULONG ulIdentifyID, LPPU_ALARM_LINK_PRIORITY_PARA_S pstAlarmLinkPriority);

//获取行为分析联动智能跟踪
_HW_PU_API BOOL __stdcall IVS_PU_GetVALinkAT(ULONG ulIdentifyID, LPPU_VA_LINK_AT_S pstVALinkAT);

//设置行为分析联动智能跟踪
_HW_PU_API BOOL __stdcall IVS_PU_SetVALinkAT(ULONG ulIdentifyID, LPPU_VA_LINK_AT_S pstVALinkAT);

//设置初始跟踪位置
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoTrackStartPos(ULONG ulIdentifyID);

//设置手动跟踪目标
_HW_PU_API BOOL __stdcall IVS_PU_SetATManualTarget(ULONG ulIdentifyID, LPPU_VW_ITGT_AT_MANUAL_TARGET_S pstATManualTarget);

//获取人头计数报表
_HW_PU_API BOOL __stdcall IVS_PU_GetHumanCountTable(ULONG ulIdentifyID, PU_HUMANCOUNT_TABLE_S *pstHCTable);

//设置清除人头计数
_HW_PU_API BOOL __stdcall IVS_PU_SetHumanCountClear(ULONG ulIdentifyID);

//获取手动除雾
_HW_PU_API BOOL __stdcall IVS_PU_GetManualDefog(ULONG ulIdentifyID, PU_MANAUL_DEFOG_ENABLE_S *pstManualDefog);
//设置手动除雾
_HW_PU_API BOOL __stdcall IVS_PU_SetManualDefog(ULONG ulIdentifyID, PU_MANAUL_DEFOG_ENABLE_S *pstManualDefog);
//licence文件导入
_HW_PU_API BOOL __stdcall IVS_PU_UploadLicenceFile(ULONG ulIdentifyID, PU_LICENCE_FILE_UPLOAD_S * pstLicenceFile);

//设置SDK 证书导入
_HW_PU_API BOOL __stdcall IVS_PU_SetSdkTlsCert(ULONG ulIdentifyID, PU_SDK_TLS_CERT_UPLOAD_S * pstSdkTlsCert);

//设置微卡口款型图片FTP上传参数
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRFTPFileUploadPara(ULONG ulIdentifyID, PU_VLPR_FTP_UPLOAD_PARA_S *pstFTPFileUpload);
//获取微卡口款型图片FTP上传参数
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRFTPFileUploadPara(ULONG ulIdentifyID, PU_VLPR_FTP_UPLOAD_PARA_S *pstFTPFileUpload);

//设置微卡口款型图片FTP上传参数扩充
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRFTPFileUploadParaV2(ULONG ulIdentifyID, PU_VLPR_FTP_UPLOAD_PARA_V2_S *pstFTPFileUpload);
//获取微卡口款型图片FTP上传参数扩充
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRFTPFileUploadParaV2(ULONG ulIdentifyID, PU_VLPR_FTP_UPLOAD_PARA_V2_S *pstFTPFileUpload);

//获取ITS抓拍图片列表
_HW_PU_API BOOL __stdcall IVS_PU_GetITSSnapshotPicList(ULONG ulIdentifyID, PU_ITS_SNAPSHOT_INQUIRE_S *pstSnapshotInquire, PU_SNAPSHOT_LIST_S *pstSnapshotList);

//获取补光灯参数
_HW_PU_API BOOL __stdcall IVS_PU_GetLampPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LAMP_ATTR_S *pstLampPara);

//设置补光灯参数
_HW_PU_API BOOL __stdcall IVS_PU_SetLampPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LAMP_ATTR_S *pstLampPara);

//获取抓拍详细参数/微卡ISP参数
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotParticularPara(ULONG ulIdentifyID, PU_SNAPSHOT_PARTICULAR_PARA_S *pstSnapshotPara);

//设置抓拍详细参数/微卡ISP参数
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotParticularPara(ULONG ulIdentifyID, PU_SNAPSHOT_PARTICULAR_PARA_S *pstSnapshotPara);

//ITS手动抓拍(使用智能触发类型搜索图片)
_HW_PU_API BOOL __stdcall IVS_PU_ITSManualSnapshot(ULONG ulIdentifyID, PU_ITS_MANUAL_SNAPSHOT_PARA_S *pstManualSnapshotPara);

//ISP详细参数扩展
_HW_PU_API BOOL __stdcall IVS_PU_GetISPParticularParamEx(ULONG ulIdentifyID, PU_ISP_PARTICULAR_PARA_EX_S *pstParam);
_HW_PU_API BOOL __stdcall IVS_PU_SetISPParticularParamEx(ULONG ulIdentifyID, PU_ISP_PARTICULAR_PARA_EX_S *pstParam);

//设置通道下的透雾自适应参数
_HW_PU_API BOOL __stdcall IVS_PU_SetVWFogAdaptPara(ULONG ulIdentifyID, PU_VW_FOG_ADAPT_PARA_S *pstVWFogAdaptPara);
//获取通道下的透雾自适应参数
_HW_PU_API BOOL __stdcall IVS_PU_GetVWFogAdaptPara(ULONG ulIdentifyID, PU_VW_FOG_ADAPT_PARA_S *pstVWFogAdaptPara);

//设置通道下的拖影（速度）自适应参数
_HW_PU_API BOOL __stdcall IVS_PU_SetVWSpeedAdaptPara(ULONG ulIdentifyID, PU_VW_SPEED_ADAPT_PARA_S *pstVWSpeedAdaptPara);
//获取通道下的拖影（速度）自适应参数
_HW_PU_API BOOL __stdcall IVS_PU_GetVWSpeedAdaptPara(ULONG ulIdentifyID, PU_VW_SPEED_ADAPT_PARA_S *pstVWSpeedAdaptPara);

//设置通道下的背光自适应参数
_HW_PU_API BOOL __stdcall IVS_PU_SetVWBacklightAdaptPara(ULONG ulIdentifyID, PU_VW_BACKLIGHT_ADAPT_PARA_S *pstVWBacklightAdaptPara);
//获取通道下的背光自适应参数
_HW_PU_API BOOL __stdcall IVS_PU_GetVWBacklightAdaptPara(ULONG ulIdentifyID, PU_VW_BACKLIGHT_ADAPT_PARA_S *pstVWBacklightAdaptPara);


//获取前端设备信息
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceInfoEx(ULONG ulIdentifyID, LPPU_DEVICEINFO_EX_S pstDeviceInfo);

//获取前端实时状态信息
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceRealStatusInfo(ULONG ulIdentifyID, LPPU_DEV_REALSTATUS_INFO_S pstRealStatusInfo);

//远程设置前端设备配置参数
_HW_PU_API BOOL __stdcall IVS_PU_SetDevConfigPara(ULONG ulIdentifyID, PU_DEV_CONFIG_TYPE_E enConfigType, VOID *arg);

//远程获取前端设备配置参数
_HW_PU_API BOOL __stdcall IVS_PU_GetDevConfigPara(ULONG ulIdentifyID, LPPU_DEV_CONFIG_INFO_S pstDevConfigInfo);

//远程操作前端设备
_HW_PU_API BOOL __stdcall IVS_PU_OptDevice(ULONG ulIdentifyID, PU_DEV_OPT_TYPE_E enOptType);

//设置设备告警事件回调函数
typedef LONG(CALLBACK *pfGetDevAlarmInfoCallBack)(LPPU_DEV_ALARM_INFO_REPORT_S pstDevAlarmReport, VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmEnventCallBack(ULONG ulIdentifyID,  pfGetDevAlarmInfoCallBack fDevAlarmResportCallBack, VOID *pUsrData);

//获取智能算法信息
_HW_PU_API BOOL __stdcall IVS_PU_GetItgtAlthmInfo(ULONG ulIdentifyID, LPPU_ITGT_ALTHM_INFO_S pstItgtAlthmInfo);

//获取智能算法信息扩充
_HW_PU_API BOOL __stdcall IVS_PU_GetItgtAlthmInfoV2(ULONG ulIdentifyID, LPPU_ITGT_ALTHM_INFO_EX_S pstItgtAlthmInfo);

//获取ISP算法信息
_HW_PU_API BOOL __stdcall IVS_PU_GetISPAlthmInfo(ULONG ulIdentifyID, PU_ISP_ALG_INFO_S *pstISPAlthmInfo);

//获取三方算法信息
_HW_PU_API BOOL __stdcall IVS_PU_Get3RdAppAlthmInfo(ULONG ulIdentifyID, LPPU_MANAGE_3RD_APP_INFO_S pst3RdAppManageInfo);

//设置三方算法App
_HW_PU_API BOOL __stdcall IVS_PU_Set3RdAppAlthmOptInfo(ULONG ulIdentifyID, LPPU_VW_OPERATE_3RD_APP_S pst3RdAppOperateInfo);

//获取license服务信息
_HW_PU_API BOOL __stdcall IVS_PU_GetLicServiceInfo(ULONG ulIdentifyID, LPPU_ITGT_LIC_SERVICE_INFO_S pstLicServiceInfo);

//获取license服务信息扩充
_HW_PU_API BOOL __stdcall IVS_PU_GetLicServiceInfoV2(ULONG ulIdentifyID, LPPU_ITGT_LIC_SERVICE_INFO_EX_S pstLicServiceInfo);

//去激活license，并获取失效码信息
_HW_PU_API BOOL __stdcall IVS_PU_DeactLicForRevokeKey(ULONG ulIdentifyID, LPPU_ITGT_LIC_REVOKE_INFO_S pstLicRevokeInfo);

//智能包升级
_HW_PU_API BOOL __stdcall IVS_PU_ItgtUpgrade(ULONG ulIdentifyID, LPPU_UPGRADE_ITGT_FILE_INFO_S pstItgtFileInfo);
_HW_PU_API BOOL __stdcall IVS_PU_ItgtUpgradeWithSchedule(ULONG ulIdentifyID, LPPU_UPGRADE_ITGT_FILE_INFO_S pstItgtFileInfo,pfUpgradeScheduleCallBack fScheduleCallBack,VOID *pUsrData);


//D芯片升级(请注意:接口废弃,使用IVS_PU_ItgtUpgrade接口升级D芯片)
_HW_PU_API BOOL __stdcall IVS_PU_DminiUpgrade(ULONG ulIdentifyID, CHAR *pszModelPath);

// 4G 无线配置和获取
_HW_PU_API BOOL __stdcall IVS_PU_GetDialingInfo(ULONG ulIdentifyID, PU_DIALING_CONFIG_INFO_S *pstDialingConfigInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetDialingInfo(ULONG ulIdentifyID, PU_DIALING_CONFIG_INFO_S *pstDialingConfigInfo);
_HW_PU_API BOOL __stdcall IVS_PU_GetDialingStatus(ULONG ulIdentifyID, PU_DIALING_STATUS_INFO_S *pstDialingStatus);
_HW_PU_API BOOL __stdcall IVS_PU_SetManualDialing(ULONG ulIdentifyID, PU_MANUL_DIALING_S *pstManulDialing);
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoDialingPlan(ULONG ulIdentifyID, PU_AUTO_DIALING_PLAN_S *pstAutoDialingPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoDialingPlan(ULONG ulIdentifyID, PU_AUTO_DIALING_PLAN_S *pstAutoDialingPlan);
_HW_PU_API BOOL __stdcall IVS_PU_GetWhiteLists(ULONG ulIdentifyID, PU_SMS_WHITE_LISTS_S *pstSmsWhiteLists);
_HW_PU_API BOOL __stdcall IVS_PU_SetWhiteLists(ULONG ulIdentifyID, PU_SMS_WHITE_LISTS_S *pstSmsWhiteLists);
//4G升级(请注意:接口废弃,使用IVS_PU_ItgtUpgrade接口升级4G)
_HW_PU_API BOOL __stdcall IVS_PU_LTEUpgrade(ULONG ulIdentifyID, CHAR *pszModelPath);

//人脸库导入，配套IPC版本:V5R19C30 TR5版本以及之前
_HW_PU_API BOOL __stdcall IVS_PU_ImportFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_IMPORT_S *pstFaceLibInfo);

//人脸库导入接口扩充(可提升导库速度)，与IVS_PU_CheckImportStatus配合使用，配套IPC版本:V5R19C30 TR6版本以及之后
_HW_PU_API BOOL __stdcall IVS_PU_ImportFaceLibEx(ULONG ulIdentifyID, PU_FACE_LIB_IMPORT_S *pstFaceLibInfo);

//定时查询人脸库导入状态、定时查询特征提取状态
_HW_PU_API BOOL __stdcall IVS_PU_CheckImportStatus(ULONG ulIdentifyID, PU_FACE_LIB_STATUS_S *pstFaceLibStatus);

_HW_PU_API BOOL __stdcall IVS_PU_FeatureExtract(ULONG ulIdentifyID, PU_FACE_FEATURE_EXTRACT_S *pstExtractStatus);

//添加单张人脸
_HW_PU_API BOOL __stdcall IVS_PU_AddOneFace(ULONG ulIdentifyID, PU_FACE_INFO_ADD_S *pstOneFaceInfo);

//添加单张人脸，扩展图片名字段
_HW_PU_API BOOL __stdcall IVS_PU_AddOneFaceV2(ULONG ulIdentifyID, PU_FACE_INFO_ADD_S *pstOneFaceInfo, CHAR *pcPicname);

//获取人脸库信息
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_GET_S *pstGetFaceLib);

//查询人脸信息
_HW_PU_API BOOL __stdcall IVS_PU_FindFaceInfo(ULONG ulIdentifyID, PU_FACE_INFO_FIND_S *pstFindFaceInfo);

//设置人脸库信息
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_SET_S *faceLibInfo);

//删除人脸信息
_HW_PU_API BOOL __stdcall IVS_PU_DelFaceInfo(ULONG ulIdentifyID, PU_FACE_INFO_DELETE_S *delFaceInfo);

//修改人脸信息
_HW_PU_API BOOL __stdcall IVS_PU_FaceInfoModify(ULONG ulIdentifyID, PU_FACE_INFO_MODIFY_S *modifyFaceInfo);

//获取人脸图片
_HW_PU_API BOOL __stdcall IVS_PU_GetFacePicture(ULONG ulIdentifyID, PU_FACE_PIC_GET_S *pstGetFacePic);

//获取人脸特征库，请注意:接口废弃，SDK接口不支持
//_HW_PU_API BOOL __stdcall IVS_PU_GetFeatureLib(ULONG ulIdentifyID, PU_FACE_FEATURE_GET_S *pstGetFeature);

//获取ITS外设参数
_HW_PU_API BOOL __stdcall IVS_PU_GetITSExtraDevicePara(ULONG ulIdentifyID, PU_ITS_DEV_SPEC_S *pstExtraDevPara);

//设置ITS外设参数
_HW_PU_API BOOL __stdcall IVS_PU_SetITSExtraDevicePara(ULONG ulIdentifyID, PU_ITS_DEV_SPEC_S *pstExtraDevPara);

// 获取/设置车流量统计
_HW_PU_API BOOL __stdcall IVS_PU_GetITSFlowRateParam(ULONG ulIdentifyID, PU_ITS_FLOW_RATE_PARA_S *pstFlowRatePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSFlowRateParam(ULONG ulIdentifyID, PU_ITS_FLOW_RATE_PARA_S *pstFlowRatePara);

/************add 于皓***************/
// 获取/设置红灯增强参数
_HW_PU_API BOOL __stdcall IVS_PU_GetRLCropEnhancePara(ULONG ulIdentifyID, PU_RL_CROP_ENHANCE_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetRLCropEnhancePara(ULONG ulIdentifyID, PU_RL_CROP_ENHANCE_PARA_S *pstPara);

// 获取/设置测速配置参数
_HW_PU_API BOOL __stdcall IVS_PU_GetITSSpeedMeasureParam(ULONG ulIdentifyID, PU_ITS_SPEED_MEASURE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSSpeedMeasureParam(ULONG ulIdentifyID, PU_ITS_SPEED_MEASURE_PARAM_S *pstPara);

// 获取/设置视频电警车道参数
_HW_PU_API BOOL __stdcall IVS_PU_GetITSTGateWayLaneParam(ULONG ulIdentifyID, PU_ITS_TGATEWAY_LANE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSTGateWayLaneParam(ULONG ulIdentifyID, PU_ITS_TGATEWAY_LANE_PARAM_S *pstPara);

// 获取/设置视频电警检测抓拍参数
_HW_PU_API BOOL __stdcall IVS_PU_GetITSTGateWaySnapTypeParam(ULONG ulIdentifyID, PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSTGateWaySnapTypeParam(ULONG ulIdentifyID, PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_S *pstPara);

// 获取/设置视频电警检测抓拍参数扩充
_HW_PU_API BOOL __stdcall IVS_PU_GetITSTGateWaySnapTypeParamV2(ULONG ulIdentifyID, PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_V2_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSTGateWaySnapTypeParamV2(ULONG ulIdentifyID, PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_V2_S *pstPara);

// 获取/设置绘制检测线参数
_HW_PU_API BOOL __stdcall IVS_PU_GetITSDtLineParam(ULONG ulIdentifyID, PU_ITS_DT_LINE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSDtLineParam(ULONG ulIdentifyID, PU_ITS_DT_LINE_PARAM_S *pstPara);

// 获取/设置本机SIM卡号码 
_HW_PU_API BOOL __stdcall IVS_PU_GetSIMPhoneNum(ULONG ulIdentifyID, PU_SIM_PHONE_NUM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSIMPhoneNum(ULONG ulIdentifyID, PU_SIM_PHONE_NUM_S *pstPara);

//获取设备ESN号
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceESNInfo (ULONG ulIdentifyID, PU_DEVICE_ESN_INFO_S *pstPara);
//一机多用多算法切换
_HW_PU_API BOOL __stdcall IVS_PU_SetITGEMode (ULONG ulIdentifyID, PU_ITGT_MODE_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetITGEMode (ULONG ulIdentifyID, PU_ITGT_MODE_S *pstPara);


/************add 肖增瑞、陈超***************/
//获取电警信号灯参数
_HW_PU_API BOOL __stdcall IVS_PU_GetEpoliceSigLightPara(ULONG ulIdentifyID, PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM_S *pstPara);
//设置电警信号灯参数
_HW_PU_API BOOL __stdcall IVS_PU_SetEpoliceSigLightPara(ULONG ulIdentifyID, PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM_S *pstPara);

//获取电警模拟红绿灯参数
_HW_PU_API BOOL __stdcall IVS_PU_GetITSEpoliceSimTrafficLightParam(ULONG ulIdentifyID, PU_ITS_SIM_TRAFFIC_LIGHT_PARAM_S *pstPara);

//设置电警模拟红绿灯参数
_HW_PU_API BOOL __stdcall IVS_PU_SetITSEpoliceSimTrafficLightParam(ULONG ulIdentifyID, PU_ITS_SIM_TRAFFIC_LIGHT_PARAM_S *pstPara);

//获取电警抓拍类型参数
_HW_PU_API BOOL __stdcall IVS_PU_GetEPoliceSnapTypePara(ULONG ulIdentifyID, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_S *pstEPoliceSnapTypePara);

//设置电警抓拍类型参数
_HW_PU_API BOOL __stdcall IVS_PU_SetEPoliceSnapTypePara(ULONG ulIdentifyID, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_S *pstEPoliceSnapTypePara);

//获取电警抓拍类型参数扩充
_HW_PU_API BOOL __stdcall IVS_PU_GetEPoliceSnapTypeParaV2(ULONG ulIdentifyID, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_V2_S *pstEPoliceSnapTypePara);

//设置电警抓拍类型参数扩充
_HW_PU_API BOOL __stdcall IVS_PU_SetEPoliceSnapTypeParaV2(ULONG ulIdentifyID, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_V2_S *pstEPoliceSnapTypePara);


//获取电警车道参数
_HW_PU_API BOOL __stdcall IVS_PU_GetEPoliceLanePara(ULONG ulIdentifyID, PU_ITS_LANE_PARAM_S *pstEPoliceLanePara);

//设置电警车道参数
_HW_PU_API BOOL __stdcall IVS_PU_SetEPoliceLanePara(ULONG ulIdentifyID, PU_ITS_LANE_PARAM_S *pstEPoliceLanePara);

//获取ITS 应用模式参数
_HW_PU_API BOOL __stdcall IVS_PU_GetITSBusinessTypePara(ULONG ulIdentifyID, PU_ITS_BUSINESS_TYPE_PARA_S *pstITSBusinessTypePara);

//获取/设置违法字典参数
_HW_PU_API BOOL __stdcall IVS_PU_GetITSIllegalDicPara(ULONG ulIdentifyID, PU_ITS_ILLEGAI_DIC_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSIllegalDicPara(ULONG ulIdentifyID, PU_ITS_ILLEGAI_DIC_PARAM_S *pstPara);

//获取违法字典默认参数
_HW_PU_API BOOL __stdcall IVS_PU_GetDefaultITSIllegalDicPara(ULONG ulIdentifyID, PU_ITS_ILLEGAI_DIC_PARAM_S *pstPara);

//获取/设置交通球机算法参数
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeAlgParams(ULONG ulIdentifyID, PU_TD_ALG_PARAMS_S *pstAlgParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeAlgParams(ULONG ulIdentifyID, PU_TD_ALG_PARAMS_S *pstAlgParams);

//获取/设置交通球机算法参数V2
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeAlgParamsV2(ULONG ulIdentifyID, PU_TD_ALG_PARAMSV2_S *pstAlgParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeAlgParamsV2(ULONG ulIdentifyID, PU_TD_ALG_PARAMSV2_S *pstAlgParams);

//设置交通球机手动检测屏幕位置
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeManualDetectionPos(ULONG ulIdentifyID, PU_TD_MANUAL_DETECTION_POS_S *pstPosParams);

//设置交通球机定时锁定参数
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeTimingLockParam(ULONG ulIdentifyID, PU_TD_TIMING_LOCK_PARAMS_S *pstTimingLockPara);

//设置交通球机解锁参数
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeUlockParam(ULONG ulIdentifyID, PU_TD_UNLOCK_PARAMS_S *pstUlockPara);

//交通球机转动到某场景
_HW_PU_API BOOL __stdcall IVS_PU_TrafficDomeMoveToScene(ULONG ulIdentifyID, PU_TD_SCENE_MOVE_TO_SCENE_S *pstMoveToScene);

//获取/设置交通球机手动违停检测算法参数
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeManualDetectionParams(ULONG ulIdentifyID, PU_TD_MANUAL_DETECTION_PARAMS_S *pstManualDecetionParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeManualDetectionParams(ULONG ulIdentifyID, PU_TD_MANUAL_DETECTION_PARAMS_S *pstManualDecetionParams);

//获取/设置交通球机手动违停检测算法参数V2
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeManualDetectionParamsV2(ULONG ulIdentifyID, PU_TD_MANUAL_DETECTION_PARAMSV2_S *pstManualDecetionParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeManualDetectionParamsV2(ULONG ulIdentifyID, PU_TD_MANUAL_DETECTION_PARAMSV2_S *pstManualDecetionParams);


//获取/设置交通球机巡航计划参数
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeTourPlanParams(ULONG ulIdentifyID, PU_TD_TOUR_PLAN_PARAMS_S *pstTourPlanParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeTourPlanParams(ULONG ulIdentifyID, PU_TD_TOUR_PLAN_PARAMS_S *pstTourPlanParams);

//获取/设置交通球机场景应用参数
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneAppParams(ULONG ulIdentifyID, PU_TD_SCENE_APP_PARAMS_S *pstSceneAppParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeSceneAppParams(ULONG ulIdentifyID, PU_TD_SCENE_APP_PARAMS_S *pstSceneAppParams);

//获取/设置交通球机场景应用参数V2
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneAppParamsV2(ULONG ulIdentifyID, PU_TD_SCENE_APP_PARAMSV2_S *pstSceneAppParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeSceneAppParamsV2(ULONG ulIdentifyID, PU_TD_SCENE_APP_PARAMSV2_S *pstSceneAppParams);

//获取/设置交通球违章智能分析参数
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeIllegalIntelligentParams(ULONG ulIdentifyID, PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS_S *pstTDomeIllegalIntelligentParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeIllegalIntelligentParams(ULONG ulIdentifyID, PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS_S *pstTDomeIllegalIntelligentParams);

//获取交通球违章智能分析默认参数
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeIllegalIntelligentDeFaultParams(ULONG ulIdentifyID, PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS_S *pstTDomeIllegalIntelligentParams);

//获取/设置交通球机场景基础参数
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneBaseParams(ULONG ulIdentifyID, PU_TD_SCENE_BASE_PARAMS_S *pstSceneBaseParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeSceneBaseParams(ULONG ulIdentifyID, PU_TD_SCENE_BASE_PARAMS_S *pstSceneBaseParams);

//获取交通球机巡航场景使能信息
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneEnableInfo(ULONG ulIdentifyID, PU_TD_SCENE_ENABLE_INFO_S *pstSceneEnableInfo);
/*枪球联动*/
//master slave group para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveGroupPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_GROUP_PARA_S *pstMasterSlaveGroupPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveGroupPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_PER_GROUP_PARA_S *pstMasterSlavePerGroupPara);

//master slave auth para 
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveAuthPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_AUTH_PARA_S *pstMasterSlaveAuthPara);

//master slave communication para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveCommunicationPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_COMMUNICATION_PARA_S *pstMasterSlaveCommunicationPara);

//master slave track para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveTrackPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_TRACK_PARA_S *pstMasterSlaveTrackPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveTrackPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_TRACK_PARA_S *pstMasterSlaveTrackPara);

//master slave watch point para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveWatchPointPara(ULONG ulIdentifyID, PU_PTZ_CURRENT_LOCATION_S *pstMasterSlaveWatchPointPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveWatchPointPara(ULONG ulIdentifyID, PU_PTZ_CURRENT_LOCATION_S *pstMasterSlaveWatchPointPara);

//master slave locate para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveLocateConfig(ULONG ulIdentifyID, PU_MASTER_SLAVE_LOCATE_CONFIG_S *pstMasterSlaveLocateConfig);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveLocateConfig(ULONG ulIdentifyID, PU_MASTER_SLAVE_LOCATE_CONFIG_S *pstMasterSlaveLocateConfig);

//start master slave locate
_HW_PU_API BOOL __stdcall IVS_PU_StartMasterSlaveLocate(ULONG ulIdentifyID,  PU_MASTER_SLAVE_LOCATE_PARA_S *pstMasterSlaveLocatePara);

//master slave calibration para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveCalibrationPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_CALIBRATION_S *pstMasterSlaveCalibrationPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveCalibrationPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_CALIBRATION_S *pstMasterSlaveCalibrationPara);

//master slave calibration status
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveCalibrationStatus(ULONG ulIdentifyID, PU_MASTER_SLAVE_CALIBRATION_STATUS_S *pstMasterSlaveCalibrationStatus);

//master slave track para
_HW_PU_API BOOL __stdcall IVS_PU_MasterSlaveManualTrack(ULONG ulIdentifyID, PU_MASTER_SLAVE_MANUAL_TRACK_PARA_S *pstMasterSlaveManualTrackPara);

//ITS尾号限行策略
_HW_PU_API BOOL __stdcall IVS_PU_GetITSRestrictPara(ULONG ulIdentifyID, PU_ITS_RESTRICTED_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSRestrictPara(ULONG ulIdentifyID, PU_ITS_RESTRICTED_PARAM_S *pstPara);
//车流量统计
_HW_PU_API BOOL __stdcall IVS_PU_GetVlprTrafficStat(ULONG ulIdentifyID, PU_VLPR_TRAFFIC_STATISTICS_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVlprTrafficStat(ULONG ulIdentifyID, PU_VLPR_TRAFFIC_STATISTICS_S *pstPara);


//hot map para
_HW_PU_API BOOL __stdcall IVS_PU_GetHotMapPara(ULONG ulIdentifyID, PU_HOTMAP_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetHotMapPara(ULONG ulIdentifyID, PU_HOTMAP_PARA_S *pstPara);

//hot map guard plan
_HW_PU_API BOOL __stdcall IVS_PU_GetHotMapPlan(ULONG ulIdentifyID, PU_HOTMAP_GUARD_PLAN_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetHotMapPlan(ULONG ulIdentifyID, PU_HOTMAP_GUARD_PLAN_PARA_S *pstPara);

//query hot map table
_HW_PU_API BOOL __stdcall IVS_PU_QueryHotMapTable(ULONG ulIdentifyID, PU_HOTMAP_TABLE_PARA_S *pstPara);

//clear hot map table
_HW_PU_API BOOL __stdcall IVS_PU_ClearHotMapData(ULONG ulIdentifyID, ULONG ulChannelId);
/*机非人自动跟踪*/
_HW_PU_API BOOL __stdcall IVS_PU_GetVHDAutoTrackPara(ULONG ulIdentifyID, PU_ITGT_VHD_AUTO_TRACK_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVHDAutoTrackPara(ULONG ulIdentifyID, PU_ITGT_VHD_AUTO_TRACK_PARA_S *pstPara);
/*机非人手动跟踪*/
_HW_PU_API BOOL __stdcall IVS_PU_SetVHDManualTrackPara(ULONG ulIdentifyID, PU_ITGT_VHD_MANUAL_TRACK_PARA_S *pstPara);
/*人脸OSD叠加*/
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceOsdPara(ULONG ulIdentifyID, PU_FACE_OSD_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceOsdPara(ULONG ulIdentifyID, PU_FACE_OSD_PARA_S *pstPara);

/*******************************************************************************************************************/
/*                                             SDK Function Declaration                                            */
/*******************************************************************************************************************/

_HW_PU_API BOOL __stdcall IVS_User_GetMetaData(CHAR *pFBuffer,ULONG ulFBLength,LAYER_TWO_TYPE eLayTwo,PU_META_DATA **pstMetaData);
_HW_PU_API VOID __stdcall IVS_User_FreeMetaData(PU_META_DATA **ppstMetaData);

//多机协同
_HW_PU_API ULONG __stdcall IVS_PU_AI_SetOption(ULONG ulIdentifyID,PU_AI_LEVEL_E bussLevel,PU_AI_NAME_E bussName,const void* param,UINT param_len);

_HW_PU_API ULONG __stdcall IVS_PU_AI_GetOption(ULONG ulIdentifyID,PU_AI_LEVEL_E bussLevel,PU_AI_NAME_E bussName,void* param,UINT *pparam_len);

//SDK通用接口
_HW_PU_API ULONG __stdcall IVS_PU_CommonOption(ULONG ulIdentifyID,PU_REQ_TYPE enGetOrSet,PU_INTERFACE_TYPE_E enServiceType,VOID* pstParam,ULONG ulParam_len);


//JSON格式参数设置获取接口
_HW_PU_API ULONG __stdcall IVS_PU_JsonConfig_Option(ULONG ulIdentifyID,LPPU_CONFIG_JSON_INPUT_ST pInputParam,LPPU_CONFIG_JSON_CONFIG_OUTPUT_ST pOutputParam);

//JSON格式告警回调设置
typedef LONG(CALLBACK *pfJsonMsgCallBack)(ULONG ulIdentifyID, CHAR*pMsginfo, DWORD dwBufLen, void *pUserData );
_HW_PU_API ULONG __stdcall IVS_PU_SetJsonMessageCallBack(ULONG ulIdentifyID,pfJsonMsgCallBack fMessageCallBack, void *pUserData);


#endif 
