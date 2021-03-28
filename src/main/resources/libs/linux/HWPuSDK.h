#ifndef _HW_PU_SDK_H_
#define _HW_PU_SDK_H_

#ifdef _WIN32
// for windows
#ifdef HWFEDSDK_EXPORTS
#define _HW_PU_API extern "C" __declspec(dllexport)
#else
#define _HW_PU_API extern "C" __declspec(dllimport)
#endif

#else
// for linux
#define _HW_PU_API extern "C"
#define __stdcall
#define CALLBACK
#define WINAPI
#endif

#ifdef _WIN32
#define PU_TRUE  TRUE
#define PU_FALSE FALSE
#include "stdafx.h"
#else
#define PU_TRUE  1
#define PU_FALSE 0

#ifndef CONST
#define CONST const
#endif

typedef char CHAR;
typedef unsigned char UCHAR;
typedef short SHORT;
typedef unsigned short USHORT;
typedef int INT;
typedef unsigned int UINT;
typedef int BOOL;
typedef long LONG;
typedef long DWORD;
typedef unsigned long ULONG;
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
typedef void *HANDLE;
#ifndef _ODS_SDK_
typedef void VOID;
#endif
typedef int SOCKET;
typedef void *HWND;
typedef float FLOAT;

#endif

#pragma pack(push, 1)
/********************************�궨��**********************************************/
#define PU_RESERVE_LEN    32  // Ԥ���ֽڳ�
#define PU_RESERVE_EX_LEN 256 // Ԥ���ֽڳ�����

#define PU_SUBPOLICE_LEN      32        // �ɳ�������
#define PU_VERSION_LEN        32        // �汾����
#define PU_DEVICE_NAME_LEN    32        // �豸���Ƴ���
#define PU_DEVICE_NAME_EX_LEN (256 + 4) // �豸���Ƴ�������
#define PU_FAC_NAME_LEN       12        // �������Ƴ���
#define PU_DEVICE_TYPE_LEN    32        // �豸���ͳ���
#define PU_SERIAL_LEN         32        // ���кų���
#define PU_BOM_NUMBER_LEN     32        // BOM���볤��

#define PU_ESN_INFO_LEN 32  // �豸ESN�ų���

#define PU_IP4_ADDR_LEN       16   // ipv4
#define PU_MULTICAST_ADDR_LEN 32   // �鲥��ַ����
#define PU_IP6_ADDR_LEN       40   // ipv6
// #define PU_MAC_ADDR_LEN_MAX   (6)  //MAC��ַ����
#define PU_HEX_MAC_ADDR_LEN   (18) // ʮ������MAC��ַ����

#define PU_PLATFORM_INFO_LEN      32        // ƽ̨��Ϣ����
#define PU_PLATFORM_INFO_EX_LEN   (256 + 4) // ƽ̨��Ϣ��������
#define PU_PLATFORM_DEVICE_ID_LEN 24        // �豸id����

#define PU_PTZ_NAME_LEN         32       // ��̨�������ֵ
#define PU_PTZ_CRUISE_LEN       32       // Ԥ��λ����
#define PU_PTZ_CRUISE_POINT_MAX 32       // �켣�����ֵ
#define PU_PTZ_PRESET_NUM       10       // Ԥ��λ��
#define PU_PTZ_GEAR_NUM_MAX     (10)     // ��̨������ɢ��λ���ֵ
#define PU_CRUISE_NUM_MAX       8        // Ѳ���켣�����
#define PU_CRUISE_NAME_LEN      (32 + 4) // Ѳ���켣������󳤶�

#define PU_PRIVACY_MASK_MAX    10 // ��˽�����������ֵ
#define PU_PRIVACY_MASK_MAX_V2 32 // ��˽�����ı������ֵ
#define PU_PRIVACY_MOSAIC_MAX  32 // �����˾��Σ�ȫ������������ֵ����֧ͨ��4��
#define PU_ALARM_TIME_MAX      8  // �澯ʱ������ֵ
#define PU_ALARM_AREA_MAX      16 // �澯�������ֵ

#define PU_CRUISE_DWELL_MIN 3    // Ѳ���켣��Сͣ��ʱ��
#define PU_CRUISE_DWELL_MAX 3600 // Ѳ���켣���ͣ��ʱ��
#define PU_CRUISE_SPEED_MIN 1    // Ѳ���켣��Сת���ٶ�
#define PU_CRUISE_SPEED_MAX 10   // Ѳ���켣���ת���ٶ�

#define PU_TIME_YEAR_LEN   5  // ������"��"�ַ�������
#define PU_TIME_OTHERS_LEN 3  // �����г�"��"�������ַ�������
#define PU_TIME_TOTAL_LEN  32 // �����ַ����ܳ���

#define PU_UPGRADE_FILE_NUM_MAX 16  // �ϴ��ļ������
#define PU_UPGRADE_FILE_LEN_MAX 300 // �ϴ��ļ�·������

#define PU_INVADE_LINE_NUM_MAX 5  // �����������

#define PU_SAVE_FILE_PATH_MAX 128  // �����ļ������·��

#define PU_ALARM_CAMERA_MAX 4 // ���澯������ͷ��
#define PU_ALARM_DO_MAX     4 // ���澯�������������

#define PU_USER_NAME_LEN       32        // �û�����󳤶�
#define PU_PASSWORD_LEN        (64 + 4)  // Pwd��󳤶�
#define PU_CLIENT_USERNAME_LEN (32 + 4)  // FTP�û�����󳤶�
#define PU_FTP_UPLOAD_PATH_LEN (128 + 4) // FTP�ϴ�Ŀ¼����

#define PU_IMG_QUALITY_INFO_LEN 1024  // ͼƬ�����жϽ����Ϣ�ĳ���

#define PU_CAMERA_NUM_MAX 4  // �����֧�ֵ����ͷ��

#define PU_TRIPWIRE_LEN_NUM_MAX 5        // ���߸澯�������
#define PU_IGT_AREA_POINTS_NUM  10       // ���򶥵������Ŀ
#define PU_IGT_AREA_NUM         4        // ���������Ŀ
#define PU_IGT_LINE_NAME_LEN    (32 + 4) // ���ܰ������Ƴ���
#define PU_IGT_AREA_NAME_LEN    (32 + 4) // �����������Ƴ���

#define PU_DEVICE_NUM_MAX       (1000)  // ������1000·�豸
#define PU_DEVICE_LOGIN_NUM_MAX (20000) // ������20000·�豸
#define PU_TRANSPARENT_CMD_MAX  256     // ͸��ͨ�������
#define PU_DOMAIN_LEN           256     // ������󳤶�
#define PU_FACE_FEATURE_LEN     256     // ������������
#define PU_IRLIGHT_NUM_MAX      4       // �������֧�ֵĺ���Ƹ���

#define PU_DIO_NAME_LEN           (32 + 4) // ���������Ƴ���
#define PU_DIO_NUM_MAX            8        // ����������/���������
#define PU_RECORD_PLAN_NUM        28       // ƽ̨¼��ƻ�����
#define PU_RECORD_PLAN_NUM_SD     24       // SDcard¼��ƻ�����
#define MAX_RECORD_CONTENTID_LEN  64       // ¼���ļ�����󳤶�
#define PU_LOG_TIME_LEN           20       // ÿ����־��ʱ����󳤶�
#define PU_LOG_LEVEL_LEN          8        // ÿ����־�ĵȼ���󳤶�
#define PU_LOG_INFO_LEN           256      // ÿ����־����󳤶�
#define PU_LOG_INFO_NUM           100      // ��־��ѯÿ�η��ص���󳤶�
#define PU_NAT_SESSIONID_LEN      32       // NAT��Խ��sessid����
#define PU_NAT_URL_LEN            256      // NAT��Խ�ĻỰURL����
#define PU_RECORD_TYPE_NUM        4        // ¼�����͸���
#define PU_RECORD_INFO_NUM_MAX    5        // ¼����Ϣ������
#define PU_RECORD_CONTENTID_LEN   (40)     // ¼���ļ�������
#define PU_VIDEO_FORMAT_NUM       4        // ��Ƶ�����ʽ����
#define PU_STREAM_NUM             4        // �����������
#define PU_STREAM_NUM_V2          5        // �����������(��֮ǰ����������Ϊ������)
#define PU_OSD_STRING_LEN         (96 + 4) // OSD�������ֵ
#define PU_OSD_STRING_NUM         7        // OSD�ַ�������
#define PU_OSD_STRING_EX_NUM      10       // �����OSD�ַ�������
#define PU_MAC_ADDR_LEN           30       // MAC��ַ����
#define PU_SNAP_IMAGE_NAME_LEN    24       // ץ��ͼƬ�ļ�������
#define PU_MAX_URL_LEN            512      // URL����
#define PU_CONFIG_FILE_PATH_MAX   512      // �����ļ����·��
#define PU_CONFIG_LOAD_UP_KEY_LEN (32 + 1) // ���ء��ϴ������ļ�ʹ�õ���Կ����(RSA���ܺ󳤶�)
#define PU_SNAPSHOT_PIC_PATH_LEN  512      // ץ��ͼƬ���·��
#define PU_DEVICE_USER_NUM_MAX    10       // �豸���֧��10���û�
#define PU_CERT_FILE_PATH_MAX     512      // 802.1x EAP-TLS֤���ļ����·��

#define PU_TYPICAL_SCENE_NUM_MAX      12       // ���ͳ����ײ͸���
#define PU_TYPICAL_SCENE_NUM_MAX_EX   15       // ���ͳ����ײ͸���
#define PU_TYPICAL_SCENE_NAME_LEN     (64 + 4) // ���ͳ������Ƴ���
#define PU_TYPICAL_SCENE_DESCRIBE_LEN 128      // ���ͳ�������

#define PU_PLAN_NUM_MAX            8        // �ƻ�����
#define PU_MONTH_NUM               12       // �·ݸ���
#define FAC_NAME_LEN_MAX           12       // �豸�������ֳ���
#define STREAM_PROFILES_MAX        8        // ������ײ���
#define STREAMPROFILES_NAME_LEN    (64 + 4) // ���ײ����ֳ���
#define PRIVACY_AREA_POINTS_NUM    4        // ��˽�������򶥵���
#define VW_ZONE_ROW                15       // �ع�Ȩ����������
#define VW_ZONE_COLUMN             17       // �ع�Ȩ����������
#define ISP_PARA_NUM               22       // ISP��������
#define ETH_RECV_RATE_MAX          200000   // �հ�������������
#define ETH_RECV_RATE_MIN          2000     // �հ�������������
#define PU_ENC_STREAM_MAX_NUM      3        // һ��ͨ�����������Ŀ
#define PU_ENC_STREAM_MAX_NUM_V2   5        // һ��ͨ�����������Ŀ������������������
#define PU_FOCUSREGION_NUM_MAX     256      // �Զ��۽��������ݳ���
#define PU_FOCUSAREA_ROW           15       // �Զ��۽��������ݳ���һά
#define PU_FOCUSAREA_COL           17       // �Զ��۽��������ݳ��ȶ�ά
#define VW_VIM_MAX_AREA_POINTS_NUM (10)     // �ۼ����������󶨵������commcenter.h�е�VW_VIM_MAX_AREA_POINTS_NUM���Ӧ
#define GATHER_AREA_NAME_LEN       (32)     // �ۼ�������Ƴ���
#define MAX_AREA_NUM               (4)      // ���������Ŀ����commcenter.h�е�MAX_AREA_NUM���Ӧ

#define MAX_BURST_SHOOTING_NUM 5                  // �����ץ����
#define MAX_LANE_NUM           (4)                // ��������
#define TDOME_MAX_LANE_NUM     (6)                // ��ͨ�򳵵�����
#define MAX_AREA_VERTEX        (MAX_LANE_NUM + 1) // �����ṹ������
#define PED_RUN_RED_LINE_NUM   (3)                // ���˴���ƴ���������
#define MAX_PLATE_LOCAL_ZH_LEN (24)               // Ĭ��ʡ���ַ�����

#define CAM_POSITION_STR_LEN (15)  // ����λ��

#define MAX_SUPPLEMENT_LIGHT_LAMP_NUM (8)  // ����Ƹ���
#define FD_AREA_NUM                   (16) // ��������������
#define FD_AREA_POINT_NUM             (12) // �������������󶥵����
#define FD_AREA_NAME_LEN              (36) // ����������Ƴ���
#define PU_SNAPSHOT_INQUIRE_NUM       (10) // һ��ͼƬ��ѯ�����ͼƬ����
#define PU_SNAPSHOT_PICTURE_NAME_LEN  (64) // ץ��ͼƬ������
#define PU_VLPR_PIC_OSD_TYPE_MAX      (15) // OSD����������
#define PU_VLPR_PIC_OSD_TYPE_MAX_EX   (50) // OSD�������������䣬�����ܶ�Ԥ��һЩ

#define PU_MEDIA_ENC_AES_KEY_STR_LEN (65) // ý��������AES��Կ����
#define PU_MEDIA_ENC_AES_CBC_IV_LEN  (17) // ý��������AES CBCģʽIV����

#define MAX_ITS_SNAPSHOT_INTERVAL (60000) // ���ץ�ļ��(ms)
#define MIN_ITS_SNAPSHOT_INTERVAL (67)    // ��Сץ�ļ��(ms)

/********* SNMP *********/
#define PU_SNMPV3_USER_NUM            3
#define PU_SNMP_COMMUNITY_NUM         3
#define PU_SNMP_COMMUNITY_NAME_LEN    (16 + 1)
#define PU_SNMP_COMMUNITY_NAME_LEN_EX (32 + 1)
#define PU_SNMP_TRAP_NUM              3
#define PU_SNMP_ENGINEID_LEN          (32 + 1)
#define PU_SNMP_CONTEXT_NAME_LEN      (16 + 1)

// �������궨��
#define PU_ROI_AREA_NUM_MAX  8  // ROI���������
#define PU_PORT_MODE_NUM_MAX 16 // ���˿�ģʽ
#define PU_BNC_PORT_MAX      32 // ���BNC����˿�
#define PU_VGA_PORT_MAX      8  // ���VGA����˿�
#define PU_DVI_PORT_MAX      8  // ���DVI����˿�
#define PU_HDMI_PORT_MAX     8  // ���HDMI����˿�

#define PU_DECODE_TYPE_MAX 4  // ������֧�ֵĽ�������
#define PU_PORT_NUM_MAX    32 // ���˿���
#define PU_CHANNEL_NUM_MAX 32 // ���ͨ����

#define PU_OSD_MAX_LENGTH    (96 + 1)  // ������OSD�����ĳ���
#define PU_OSD_MAX_LENGTH_EX (176 + 1) // OSD��������

#define PU_CRYPTION_PASSWD_LEN 44  // ��Կ����

#define PU_DEC_CHANNEL_NAME_LEN    32        // ������ͨ�����Ƴ���
#define PU_DECODER_ID_LEN          20        // ������ID
#define PU_DECODER_NAME_LEN        32        // ������ͨ�����Ƴ���
#define PU_DEC_PAY_LOAD_TYPE_NUM   16        // PayLoadType��������
#define PU_DECODER_ENCODING_LEN    16        // �����������ʽ��󳤶�
#define PU_CERT_FIELD_NAME_LEN_MAX (128 + 4) // ֤��ʹ���߸��ֶ���󳤶�
#define PU_IP_FILTER_NUM_MAX       3         // IP��ַ���������Ŀ
#define PU_IP_FILTER_NUM_MAXV2     (48)      // IP��ַ���������Ŀ48�� ��ӦIP_FILTER_NUM_MAX
#define PU_IP_FILTER_NUM_MAXV3     (100)     // IP��ַ���������Ŀ48�� ��ӦIP_FILTER_NUM_MAX
#define PU_DDNS_MAX_LEN            256       // DDNS
#define OSDI_AREA_NUM_MAX          (8)       // OSDI�����������

#define PU_H264DEC_OK             0
#define PU_H264DEC_NEED_MORE_BITS -1
#define PU_H264DEC_NO_PICTURE     -2
#define PU_H264DEC_ERR_HANDLE     -3

/******* SMTP ********/
#define PU_SMTP_NAME_LEN_MAX (32 + 4)
#define PU_SMTP_MAIL_LEN     128
#define PU_SMTP_RECV_MAX_NUM 3

#define PU_IRCUT_MODE_MAX_NUM 3  // IRCUTģʽ���ֵ

#define PU_HUMANCOUNT_TABLE_LEN_MAX 32  // ������������󳤶�

#define PU_MAX_CUSTOM_CONTENT_LEN (24) // Ŀ¼����ͼƬ���Ƴ������ֵ
#define PU_MAX_DIR_NAMING_ELEM    (4)  // ΢���ڿ���FTP�ϴ�Ŀ¼����
#define PU_MAX_PIC_NAMING_ELEM    (20) // FTP�ϴ�ͼƬ�������ֵ
#define PU_MAX_PIC_NAMING_ELEM_EX (90) // FTP�ϴ�ͼƬ�������ֵ����

#define PU_ITS_MAX_ROAD_NUM    (5)
#define PU_MAX_EXT_LAMP_NUM    (8) // ���õ��������
#define PU_MAX_EXT_485LAMP_NUM (4) // 485���õ��������
#define PU_MAX_INNER_LAMP_NUM  (3) // ���õ��������
#define PU_MAX_ITS_485LAMP_NUM (4) // 485�����״̬�����������

#define PU_LIC_SERVICE_AGE_MAX_LEN 256 // license�������޳���
#define PU_LIC_REVOKE_KEY_LEN      136 // license ʧЧ�볤��
#define PU_LIC_DATE_MAX_LEN        72  // license���ڴ󳤶�
#define PU_3RD_APP_MAX_NUM         16  // �������㷨APP�����
#define PU_ITGT_TYPE_MAX_NUM       16  // �����㷨���������
#define PU_ITGT_TYPE_MAX_EX_NUM    64  // �����㷨���������
#define PU_ITGT_ALTHM_VERSION_LEN  48  // �汾�ų���
#define PU_ITGT_ALTHM_VENDOR_LEN   48  // �㷨���ҳ���
#define PU_ISP_TYPE_MAX_NUM        64  // ͼ���㷨���������

#define PU_IMPORT_FILE_LEN_MAX     256 // �ϴ��������ļ�·������
#define PU_IMPORT_FILENAME_LEN_MAX 128 // �ϴ��������ļ�����󳤶�

#define PU_SNAP_NUM_MAX  3 // ץ���������
#define PU_SNAP_NUM_MAX2 4 // ץ���������

#define PU_RL_NUM_MAX            4 // ����������ֵ
#define PU_RL_NUM_MAX8           8 // ����������ֵ
#define PU_ITS_MAX_LIGHTAREA_NUM 4 // ITS���̵������������

#define PU_ITS_ILLEGAL_TYPE_NUM_MAX (96)     // Υ���ֵ�����
#define PU_ITS_ILLEGAL_TYPE_LEN_MAX (64 + 4) // Υ�����ͳ������ֵ
#define PU_ITS_ILLEGAL_NUM_LEN_MAX  (8 + 1)  // Υ�����볤�����ֵ
#define PU_ITS_ILLEGAL_NAME_LEN_MAX (64 + 4) // Υ���������Ƴ������ֵ

#define PU_MIN_GPS_SYNC_INTERVAL = (5 * 60);
#define PU_MAX_GPS_SYNC_INTERVAL = (1000 * 60);

#define TD_MAX_SNAP_FRAME_NUM (4)      // ��ͨ������ץ��֡��
#define TD_MAX_SCENE_NUM      (16)     // ��ͨ�����󳡾���
#define TD_MAX_DAY_ONE_WEEK   (7)      // һ������
#define TD_MAX_STRING_LENGTH  (64 + 1) // ����ַ�������

#define PU_CALIBRATION_POINT_MAX_NUM  14 // �궨�������Ŀ
#define PU_MASTER_SLAVE_GROUP_MAX_NUM 4  // ������������Ŀ

#define PU_MASTER_NUM_MAX    (8) // ���豸������
#define PU_SLAVE_NUM_MAX     (8) // ���豸������
#define PU_1TN_SLAVE_NUM_MAX (8) // 1��N�ӻ�����

/******* hot map ********/
#define PU_MONTH_NUM_PER_YEAR     (12) // �걨���ȶ�ͼ���ݳ���
#define PU_DAY_NUM_PER_MONTH      (31) // �±����ȶ�ͼ���ݳ���
#define PU_DAY_NUM_PER_WEEK       (7)  // �ܱ����ȶ�ͼ���ݳ���
#define PU_HOUR_NUM_PER_DAY       (24) // �ձ����ȶ�ͼ���ݳ���
#define PU_GUARD_PLAN_NUM_PER_DAY (8)  // ÿ�첼���ƻ�����
#define PU_HOTMAP_AREA_NUM        (8)  // ���������Ŀ

#define PU_ITGT_AUTOTRACKING_PRIORITY_ITEM_NUM (3)  // �������Զ��������ȼ�Item����

#define PU_MAX_RECORD_LEN_16 (16)  // ��Ա��Ϣ�ַ���16λ
#define PU_MAX_RECORD_LEN_32 (32)  // ��Ա��Ϣ�ַ���32λ
#define PU_MAX_RECORD_LEN_48 (48)  // ��Ա��Ϣ�ַ���48λ
#define PU_MAX_RECORD_LEN_64 (64)  // ��Ա��Ϣ�ַ���64λ
#define PU_MAX_EX_FIELD_LEN  (512) // ������Ϣ��չ�ֶγ���

#define PU_MAX_DELETE_NUM (100)

/*********begin:β������*********/
#define MAX_RESTRICTED_NUM                (10) // ����β�ŵ�����
#define MAX_RESTRICTED_EVENT_NUM          (30) // ����������
#define MAX_RESTRICTED_DATE_NUM           (10) // β�����е�ʹ����
#define MAX_RESTRICTED_LOCALPLATE_LEN     (5)  // β�����б��س���
#define MAX_RESTRICTED_LOCALPLATE_NUM     (32) // β�����б��س�������
#define MAX_RESTRICTED_LOCALPLATE_ALL_NUM (26) // β�����б��س���Ϊȫʱ����Ϊ����26

#define PU_CLIENT_PWD_LEN_MAX   (64  + 4)   //��¼Pwd����󳤶�

/************************** �궨�����   ***************************/

/********************************ö������**********************************************/
// ȫ�ִ�����
typedef enum ERROR_CODE {
    PU_ERROR_CODE_NOERROR = 0,  // û�д���

    PU_ERROR_CODE_COMMON_ERROR = 1,             // һ�����
    PU_ERROR_CODE_PASSWORD_ERROR = 2,           // �û�����Pwd����
    PU_ERROR_CODE_NO_PRIORITY = 3,              // û�в���Ȩ��
    PU_ERROR_CODE_NO_INIT = 4,                  // SDKδ��ʼ��
    PU_ERROR_CODE_HAS_INIT = 5,                 // SDK�ѳ�ʼ��
    PU_ERROR_CODE_VERSION_NO_MATCH = 6,         // SDK���豸�汾��ƥ��
    PU_ERROR_CODE_STARTUP_NETWORK_ERROR = 7,    // ������������
    PU_ERROR_CODE_SOCKET_ERROR = 8,             // �����׽��ִ���
    PU_ERROR_CODE_CONNECT_ERROR = 9,            // �������Ӵ���
    PU_ERROR_CODE_SEND_TIMEOUT = 10,            // ������Ϣ��ʱ
    PU_ERROR_CODE_RECV_TIMEOUT = 11,            // ������Ϣ��ʱ
    PU_ERROR_CODE_OPERATION_TIMEOUT = 12,       // �豸������ʱ
    PU_ERROR_CODE_OUT_OF_MEMORY = 13,           // �ڴ治�㣬�޷������ڴ�
    PU_ERROR_CODE_SERVER_IS_SHUTDOWN = 14,      // ����˹ر�����
    PU_ERROR_CODE_TOO_MANY_REALPLAY = 15,       // ʵ��·���������ֵ
    PU_ERROR_CODE_LOG_ERROR = 16,               // ��־����
    PU_ERROR_CODE_NO_FREE_PORT = 17,            // û�ж���Ķ˿���Դ
    PU_ERROR_CODE_HAS_REG_EVENT_CALLBACK = 18,  // �¼��ص�������ע��
    PU_ERROR_CODE_REGISTER_FAIL = 19,           // ǰ������ע��ƽ̨ʧ��
    PU_ERROR_CODE_REGISTER_REDIRECT = 20,       // ǰ������ע��ƽ̨�ض���
    PU_ERROR_CODE_INPUT_NULL_PTR = 21,          // �������Ϊ��ָ��
    PU_ERROR_CODE_OPR_LOCAL_FILE_FAIL = 22,     // ���������ļ�ʧ��
    PU_ERROR_CODE_FILE_FORMAT_INVALID = 23,     // �ļ���ʽ����
    PU_ERROR_CODE_VLPR_WATERMARK_INVALID = 24,  // ץ��ͼƬ����ˮӡУ��ʧ��
    PU_ERROR_CODE_REST_PKG_TYPE_ERROR = 25,     // RESTЭ�鱨�ĸ�ʽ����
    PU_ERROR_CODE_XML_TYPE_ERROR = 26,          // ���ݽṹת����xml����60k��sdkֻ�ܷ���64k����
    PU_ERROR_CODE_REQ_RSP_ERROR = 27,           // ���ص�REQ��Ԥ�ڵ�RSP���Ͳ���Ӧ

    // API���ô���
    PU_ERROR_CODE_SDKINIT_LINK_MODE_ERROR = 101,              // SDK��ʼ������ģʽ����
    PU_ERROR_CODE_SDKINIT_LOCALIP_ERROR = 102,                // SDK��ʼ������IP����
    PU_ERROR_CODE_SDKLOGIN_PARA_ERROR = 103,                  // ��¼��������
    PU_ERROR_CODE_CODE_IS_INVALID = 104,                      // ��������Ч
    PU_ERROR_CODE_SDKGETVERSION_PARA_ERROR = 105,             // ��ȡ�汾��������
    PU_ERROR_CODE_IDENTIFYID_ERROR = 106,                     // ������û�ID��
    PU_ERROR_CODE_SDKGETDEVICE_PARA_ERROR = 107,              // ��ȡ�豸��������
    PU_ERROR_CODE_ALARMREPORT_CB_IS_NULL = 108,               // �澯�ϱ��ص�����Ϊ��
    PU_ERROR_CODE_VOICETB_CB_IS_NULL = 109,                   // �����Խ��ص�����Ϊ��
    PU_ERROR_CODE_REALPLAY_CB_IS_NULL = 110,                  // ʵ�����Żص�����Ϊ��
    PU_ERROR_CODE_LOAD_PLAYDLL_ERROR = 111,                   // ���ز��ſ����
    PU_ERROR_CODE_CFGFILE_ERROR = 112,                        // �����ļ�����
    PU_ERROR_CODE_UNSUPPORT_ALARM_TYPE = 113,                 // δ֪�澯����
    PU_ERROR_CODE_SDKUPGRADE_PARA_ERROR = 114,                // ������������
    PU_ERROR_CODE_SDKUPGRADE_ERROR = 115,                     // ��������
    PU_ERROR_CODE_SDKUPGRADE_FILE_ERROR = 116,                // �����ļ�����
    PU_ERROR_CODE_UNSUPPORT_PLATFORM_TYPE = 117,              // δ֪ƽ̨����
    PU_ERROR_CODE_SDKSETPLATFORM_PARA_ERROR = 118,            // ����ƽ̨��������
    PU_ERROR_CODE_UNSUPPORT_ENCODE_TYPE = 119,                // δ֪����Ƶ��������
    PU_ERROR_CODE_UNSUPPORT_STREAM_TYPE = 120,                // δ֪��������
    PU_ERROR_CODE_UNSUPPORT_BITRATE_TYPE = 121,               // δ֪��������
    PU_ERROR_CODE_UNSUPPORT_PTZ_CMD = 122,                    // δ֪��̨����
    PU_ERROR_CODE_CRUISE_PARA_ERROR = 123,                    // Ѳ���켣��������
    PU_ERROR_CODE_ALARM_TMP_PARA_ERROR = 124,                 // �¶ȸ澯��������
    PU_ERROR_CODE_ALARM_MOTION_DETEC_PARA_ERROR = 125,        // �ƶ����澯��������
    PU_ERROR_CODE_ALARM_INPUT_PARA_ERROR = 126,               // ����澯��������
    PU_ERROR_CODE_ALARM_HIDE_PARA_ERROR = 127,                // �ڵ��澯��������
    PU_ERROR_CODE_ALARM_INVADE_PARA_ERROR = 128,              // ���ּ��澯��������
    PU_ERROR_CODE_ALARM_COUNT_PARA_ERROR = 129,               // Ŀ������澯��������
    PU_ERROR_CODE_ALARM_DISTURB_PARA_ERROR = 130,             // ���Ÿ澯��������
    PU_ERROR_CODE_PRIVACY_PARA_ERROR = 131,                   // ��˽������������
    PU_ERROR_CODE_OSD_PARA_ERROR = 132,                       // OSD��������
    PU_ERROR_CODE_PTZ_PARA_ERROR = 133,                       // ��̨���Ʋ�������
    PU_ERROR_CODE_SDKGUARD_PARA_ERROR = 134,                  // ��������������
    PU_ERROR_CODE_SDKGETALARAM_PARA_ERROR = 135,              // ��ȡ�澯��������
    PU_ERROR_CODE_PARA_ERROR = 136,                           // ��������
    PU_ERROR_CODE_PLAYER_FUNC_ERROR = 137,                    // ���ſ⺯�����ó���
    PU_ERROR_CODE_SDKSAVEREALDATA_ERROR = 138,                // ����ʵ������
    PU_ERROR_CODE_SDKGETGUARDSTATE_PARA_ERROR = 139,          // ��ȡ����״̬��������
    PU_ERROR_CODE_MUTUALLYEXCLUSIVE_RELATIONSHIP = 140,       // �򻥳��ϵ�����²������óɹ�
    PU_ERROR_CODE_DEVICE_RELOGIN = 141,                       // �ظ���¼�豸
    PU_ERROR_CODE_INVALID_CONFIG_FILE = 142,                  // �����ļ����Ϸ�
    PU_ERROR_CODE_WRONG_RSP_TYPE = 143,                       // ��Ӧ��Ϣ���ʹ���
    PU_ERROR_CODE_RSP_MEG_PARSE_ERROR = 144,                  // ��Ӧ��Ϣ����ʧ��
    PU_ERROR_CODE_MISMATCH_PWD_COMPLEXITY = 145,              // ���벻�������븴�Ӷ�Ҫ��
    PU_ERROR_CODE_ALARM_AUDIO_UP_PARA_ERROR = 146,            // ��Ƶ�����澯��������
    PU_ERROR_CODE_ALARM_AUDIO_DOWN_PARA_ERROR = 147,          // ��Ƶ�����澯��������
    PU_ERROR_CODE_TRANSPARENT_CHANNEL_DATA_CB_IS_NULL = 148,  // ͸��ͨ�����ݻص�����Ϊ��
    PU_ERROR_CODE_NO_ENOUGH_CONTINUOUS_MEM = 149,             // �������㹻�������ڴ�
    PU_ERROR_CODE_IRCMODE_PARA_ERROR = 150,                   // IRCUTģʽ���ʹ���
    PU_ERROR_CODE_CERT_PARA_ERROR = 151,                      // ֤��·������
    PU_ERROR_CODE_IMPORT_FACELIBRARY_ERROR = 152,             // �����⵼�����
    PU_ERROR_CODE_IMPORTING_FACELIB_ERROR = 153,              // ���������ڵ���
    PU_ERROR_CODE_UNKNOWN_SV_TYPE = 154,                      // δ֪��ҵ������
    PU_ERROR_CODE_NOT_OPEN_TLS = 155,                         // δ����TLS�����ܲ������������
    PU_ERROR_INVALID_UPDATEFILE_NUM = 156,                    // �����ļ�������������
    PU_ERROR_USER_CANCEL_UPGRADE = 157,                       // �û�ȡ������
    PU_ERROR_NOT_ENOUGH_MEMORY_ALLOCATED = 160,               // ������ջ����С���޷�����JSON����
    PU_ERROR_MUTUALAUTH_ERROR = 161,                          // ������֤ʧ��
    PU_ERROR_CODE_GetConfigFile = 162,                        // ���ڻ�ȡ�����ļ�
    PU_ERROR_CODE_GetFaceLib = 163,                           // ���ڻ�ȡ��������Ϣ
    PU_ERROR_CODE_GetFaceInfo = 164,                          // ���ڻ�ȡ������Ϣ
    PU_ERROR_CODE_ManualSnapshot = 165,                       // �����ֶ�ץ��
    PU_ERROR_CODE_OneKeyCollection = 166,                     // ����һ���ռ�
    PU_ERROR_CODE_GetFacePic = 167,                           // ���ڻ�ȡ����ͼƬ
    PU_ERROR_CODE_GetImportCsv = 168,                         // ���ڻ�ȡ����������
    PU_ERROR_CODE_GetQualityJudge = 169,                      // ���ڻ�ȡͼƬ�����жϽ��
    PU_ERROR_AUTO_RECONNECTING_ERROR = 170,                   // ���������У����Ժ�
	PU_ERROR_CODE_GETKEYFILE = 171,                           // ���ڻ�ȡ��Կ�ļ�
	PU_ERROR_CODE_LACKWPCAP = 172,                            // ȱ��WPCAP������
	PU_ERROR_RSA_KEY_CREATE_ERROR = 173,					  // RSA��Կ����ʧ��
	PU_ERROR_RSA_KEY_ENCRYPT_ERROR = 174,					  // RSA����ʧ��
	PU_ERROR_MANUAL_SNATSHOT_BUF_LEN_ERROR = 175,			  // �ֶ�ץ�Ļ��������Ȳ���
    PU_ERROR_JSON_ERROR = 176,                                // json�������
    PU_ERROR_CODE_GetHotMap = 177,                            // ���ڻ�ȡ�ȶ�ͼ
    PU_ERROR_HTTP_BAD_REQUEST = 400,  // HTTP ��Ч����
    PU_ERROR_HTTP_CONFLICT = 409,     // HTTP �����ͻ

    // ������������
    PU_ERROR_CODE_DEC_INITDEC_ERROR = 1001,                // ��ʼ������ʧ��
    PU_ERROR_CODE_DEC_STARTDEC_ERROR = 1002,               // ��ʼ����ʧ��
    PU_ERROR_CODE_DEC_STOPDEC_ERROR = 1003,                // ֹͣ����ʧ��
    PU_ERROR_CODE_DEC_TOO_MANY_CHANNEL = 1004,             // ̫��Ľ���ͨ��
    PU_ERROR_CODE_DEC_ERROR_PORT_NUM = 1005,               // �˿�������
    PU_ERROR_CODE_DEC_ERROR_DEC_HANDEL = 1006,             // ����Ľ�����
    PU_ERROR_CODE_DEC_ERROR_UNSUPPORT_DECODE_TYPE = 1007,  // ��֧�ֵĽ�������
    PU_ERROR_CODE_DEC_ERROR_INVALID_CHANNEL_ID = 1008,     // ��Ч��ͨ����

    // ����˴�����
    PU_ERROR_CODE_SERVER_COMMON_ERROR = 10001,       // һ�����
    PU_ERROR_CODE_SYNTAX_ERROR = 10002,              // �����﷨����
    PU_ERROR_CODE_UNSUPPORT_ERROR = 10003,           // ��֧�ֵ�����
    PU_ERROR_CODE_PARAMETER_ERROR = 10004,           // ��������
    PU_ERROR_CODE_INVALID_VCU_ID = 10005,            // �豸ID����
    PU_ERROR_CODE_INVALID_CHANNEL = 10006,           // ͨ���Ŵ���
    PU_ERROR_CODE_INVALID_SERIAL_NO = 10007,         // ���ںŴ���
    PU_ERROR_CODE_INVALID_ALARM_NO = 10008,          // �����˿ڴ���
    PU_ERROR_CODE_UNSUPPORTED_MEDIA_TYPE = 10009,    // ��֧�ֵ�ý������
    PU_ERROR_CODE_PARTLY_SUPPORT = 10011,            // �����ֲ������óɹ�
    PU_ERROR_CODE_TOO_MANY_PLANS = 10012,            // �ƻ�������������
    PU_ERROR_CODE_NO_DISK = 10013,                   // �豸��Ӳ��
    PU_ERROR_CODE_OPEN_SOUND_FAIL = 10014,           // ������ʧ��
    PU_ERROR_CODE_VOICE_OPEND = 10015,               // �����������Խ���ռ��
    PU_ERROR_CODE_DEVICE_BUSY = 10016,               // �豸æ
    PU_ERROR_CODE_OPERATE_FLASH_ERROR = 10019,       // FLASH����
    PU_ERROR_CODE_UNSUPPORTED_VIDEO_FORMAT = 10020,  // ��֧�ֵ���Ƶ��ʽ
    PU_ERROR_CODE_IP_ADDRESS_CONFLICT = 10022,       // IP��ַ��ͻ
    PU_ERROR_CODE_LTE_DHCP_CONFLICT = 10023,         // ����LTH��DHCP��ͻ
    PU_ERROR_CODE_SIP_STACK_ERROR = 10024,           // SIPЭ��ջ����
    PU_ERROR_CODE_RESULT_UNSUPPORTED_DEST = 10031,   // ��Ӧ�������APP�޷�����
	PU_ERROR_CODE_RESULT_PASSWD_WEAK = 10032,                       // ����ǿ����

    PU_ERROR_CODE_NULL_POINTER = 10100,                          // ��ָ��
    PU_ERROR_CODE_NULL_ELEMENT = 10101,                          // XML�ļ�û����Ӧ�ڵ�
    PU_ERROR_CODE_INVALID_VERIFICATION = 10102,                  // ������û�����Pwd
    PU_ERROR_CODE_INVALID_VERSION_FILE = 10103,                  // VERSION�ļ�У��ʧ��
    PU_ERROR_CODE_INVALID_KERNEL_FILE = 10104,                   // �ں������ļ�У��ʧ��
    PU_ERROR_CODE_INVALID_ROOTFS_FILE = 10105,                   // �ļ�ϵͳ�����ļ�У��ʧ��
    PU_ERROR_CODE_FIRST_LOGIN = 10106,                           // ��һ�ε�¼
    PU_ERROR_CODE_CLIENT_ALREADY_LOGIN = 10107,                  // ���пͻ��˵�¼
    PU_ERROR_CODE_USER_LOCKED = 10108,                           // �û�������
    PU_ERROR_CODE_MANY_USER = 10109,                             // �û�������������
    PU_ERROR_CODE_USER_NAME_CONFLICT = 10110,                    // �û�����ͻ
    PU_ERROR_CODE_NO_USER_NAME = 10111,                          // û�и��û�
    PU_ERROR_CODE_USER_NOPOWER = 10112,                          // ��ǰ�û�û��Ȩ��
    PU_ERROR_CODE_NOT_NEED_UPDATE = 10113,                       // �汾��һ�£�����Ҫ����
    PU_ERROR_CODE_NOT_SUPPORT_ABILITY = 10114,                   // ��֧�ֵ���������
    PU_ERROR_CODE_PRESET_IN_GUARD_POSITION = 10115,              // Ԥ��λ�ڿ���λ��
    PU_ERROR_CODE_PRESET_IN_CRUISE_TRACK = 10116,                // Ԥ��λ��Ѳ���켣��
    PU_ERROR_CODE_SET_ETHPHY_OUTPUT_TYPE_ERROR = 10117,          // ������������ʧ��
    PU_ERROR_CODE_SET_ETHMODE_ERROR = 10118,                     // ������������ʧ��
    PU_ERROR_CODE_UPLOAD_CONFIG_TYPE_ERROR = 10119,              // �ϴ������ļ����ʹ���
    PU_ERROR_CODE_DNS_SERVER_UNREACH = 10120,                    // DNS���������ɴ�
    PU_ERROR_CODE_DNS_SERVER_NO_DOMAIN = 10121,                  // DNS��������ȡ����ʧ��
    PU_ERROR_CODE_THE_CRUISE_IS_RUNNING = 10122,                 // Ѳ���켣��������
    PU_ERROR_CODE_SD_FORMATTING = 10124,                         // SD�����ڸ�ʽ��
    PU_ERROR_CODE_UPDATE = 10125,                                // ϵͳ��������
    PU_ERROR_CODE_REBOOT = 10126,                                // ϵͳ��������
    PU_ERROR_CODE_RESTORE = 10127,                               // ���ڻָ�Ĭ������
    PU_ERROR_CODE_RECOVER_OPRATE_FORBIDDEN = 10128,              // �ָ�Ĭ�����ý�ֹ���õȲ���
    PU_ERROR_CODE_ROI_ERROR_BY_MJPEG = 10129,                    // MJPEG������ROI ʧ��
    PU_ERROR_CODE_ROI_ERROR_BY_NOSUBSTREAM = 10130,              // ֻ��������������������ROIʧ��
    PU_ERROR_CODE_TZ_ERROR_BY_CONFLICT = 10131,                  // ���ð��߼��ʹ���г�ͻ
    PU_ERROR_CODE_OC_ERROR_BY_CONFLICT = 10132,                  // ����Ŀ�����ʹ���г�ͻ
    PU_ERROR_CODE_MD_ERROR_BY_CONFLICT = 10133,                  // �����ƶ����ʹ���г�ͻ
    PU_ERROR_CODE_TW_ERROR_BY_CONFLICT = 10134,                  // ���ð��߼��ʹ���г�ͻ
    PU_ERROR_CODE_AREA_ERROR_BY_CONFLICT = 10135,                // ���������(�ܽ����֡���Ʒ��������Ʒ���ߣ���ʹ���г�ͻ
    PU_ERROR_CODE_VD_ERROR_BY_CONFLICT = 10136,                  // ������Ƶ����ʹ���г�ͻ
    PU_ERROR_CODE_IGT_ENABLE_CONFLICT = 10137,                   // ���ܿ����Ѵ�  �����ն���ǿʧ��,�����ڵ�ʧ��
    PU_ERROR_CODE_ILLUMINATION_ENABLE_CONFLICT = 10138,          // �նȿ�����ʹ��  �������ܿ���ʧ�ܣ������ڵ�ʧ��
    PU_ERROR_CODE_VIDEOBLOCK_ENABLE_CONFLICT = 10139,            // ��Ƶ�ڵ���ʹ�ܣ��������ܿ��ء��ҵ���ǿʧ��
    PU_ERROR_CODE_IGT_FAIL_BY_SWITCHOFF = 10140,                 // ���ܿ���δʹ�ܣ���������ҵ��ʧ��
    PU_ERROR_CODE_TW_ERROR_BY_OVER_NUM = 10141,                  // ���ð����������������
    PU_ERROR_CODE_AREA_ERROR_BY_OVER_NUM = 10142,                // ��������������������4
    PU_ERROR_CODE_AREA_ERROR_BY_OVER_TOTAL_NUM = 10143,          // ����������������������10
    PU_ERROR_CODE_AREA_ERROR_BY_ZERO_NUM = 10144,                // �����������Ϊ0
    PU_ERROR_CODE_AREA_POINT_ERROR_BY_OVER_NUM = 10145,          // �������򶥵������������
    PU_ERROR_CODE_AREA_ABN_ERROR_BY_CONFLICT = 10146,            // �����������Ʒ���ߣ�����ʹ���ѿ����г�ͻ
    PU_ERROR_CODE_AREA_RMV_ERROR_BY_CONFLICT = 10147,            // �����������Ʒ����������ʹ���ѿ����г�ͻ
    PU_ERROR_CODE_VIM_GLOBAL_PARA_ERROR = 10148,                 // �������ܷ����㷨ȫ�ֲ���ʧ��
    PU_ERROR_CODE_AREA_NOTSURPORT_ERROR = 10149,                 // �������ܷ���������Ч
    PU_ERROR_CODE_PRIVACY_MASK_AREA_BEYOND = 10150,              // ��˽�������򳬳������
    PU_ERROR_CODE_MEDIA_ADAPT_BW_MUTEX = 10151,                  // ��������Ӧ��������ͻ����������ͳ�ͻ
    PU_ERROR_CODE_IP_FILTER_RULE_SAME = 10152,                   // ������ͬ��IP���˹���
    PU_ERROR_CODE_WD_FRAME_CONFLICT = 10153,                     // ��̬�ֶ����Զ����ɼ�֡��������50��60
    PU_ERROR_CODE_FRAME_WD_CONFLICT = 10154,                     // �ɼ�֡Ϊ50��60����̬���������ֶ����Զ�
    PU_ERROR_CODE_CONFLICT_VIDEOBLOCK_OR_IGT_IS_ENABLE = 10155,  // ��Ƶ�ڵ�����Ϊ������ʹ��,�����ն���ǿʧ��
    PU_ERROR_CODE_BUSY_CURISE = 10156,                           // ����Ѳ�����޷�����Ѳ���켣����
    PU_ERROR_CODE_DEVICE_CLOSE = 10157,                          // �豸δ����
    PU_ERROR_CODE_BUSY_PRESET = 10158,                           // Ԥ��λ��ʹ�ã��޷�ɾ��
    PU_ERROR_CODE_INVALID_IGT_AREA_ID = 10159,                   // ���ܷ������򲻴���
    PU_ERROR_CODE_INVALID_IGT_LINE_ID = 10160,                   // ���ܷ�������������
    PU_ERROR_CODE_INVALID_PRIVACY_ID = 10161,                    // ��˽�������򲻴���
    PU_ERROR_CODE_IN_USER_DEFINE_SCAN = 10162,                   // ���ڻ���ɨ��¼�ƣ��ܶ๦�ܲ����ã�
    PU_ERROR_CODE_SET_DRC_BACKLIGHT_CONFLICT = 10163,            // ���ⲹ��ʹ����DRCʹ�ܳ�ͻ
    PU_ERROR_CODE_CURISE_IN_GUARD_POSITION = 10164,              // Ѳ���켣�ڿ���λ��
    PU_ERROR_CODE_DISK_ABNORMAL = 10165,                         // SD���쳣
    PU_ERROR_CODE_PRIVACYMASK_REGION_INTERSECT = 10166,          // ��˽���������ص�
    PU_ERROR_CODE_INVALID_SAMEPASSWD = 10167,                    // �޸�Pwd��ԭPwd��ͬ
    PU_ERROR_CODE_NOT_SUPPORTED_UPDATE = 10168,                  // �����ļ��汾���ͣ���ѡ��߰汾����
    PU_ERROR_CODE_MANY_RECORD_FILES = 10169,                     // ¼���ļ�����

    PU_ERROR_CODE_CONFLICT_WITH_MOSAIC = 10170,         // �����������˳�ͻ
    PU_ERROR_CODE_CONFLICT_WITH_OSD = 10171,            // ������OSD��ͻ
    PU_ERROR_CODE_CONFLICT_WITH_PIC = 10172,            // ������ͼƬ���ӳ�ͻ
    PU_ERROR_CODE_VIDEO_ENC_CLOSE = 10173,              // ��Ƶ������δ��
    PU_ERROR_CODE_ISP_PARA_CONFLICT = 10174,            // ISP������ͻ
    PU_ERROR_CODE_WB_HIGH_TEMP_LOWER = 10175,           // ��ƽ���Զ�׷��ģʽ��ɫ�����޴��ڵ���ɫ������
    PU_ERROR_CODE_MJPEG_UNSUPPORT_WATERMARK = 10176,    // MJPEG��֧������ˮӡ����
    PU_ERROR_CODE_ISP_CONFLICT_WITH_FRAMERATE = 10177,  // ��̬/���ⲹ����ȫ֡�ʻ���
    PU_ERROR_CODE_FRAMERATE_CONFLICT_WITH_ISP = 10178,  // 50֡/60֡���̬/���ⲹ������
    PU_ERROR_CODE_OSD_STRING_LEN_ERR = 10179,           // OSD�ַ����ȴ���
    PU_ERROR_CODE_DISK_MOUNT_ERROR = 10183,             // ����δ����
    PU_ERROR_CODE_IMPORTING_FACE_LIB = 10184,           // ���ڵ��������⣬�Ժ�
    PU_ERROR_CODE_ADDING_ONE_FACE = 10185,              // ��������������Ժ�
    PU_ERROR_CODE_EXTRA_DEVICE_OPEN_FAIL = 10190,       // ���迪��ʧ��

    PU_ERROR_CODE_AUDIO_DETECT_MIC_NOT_SUPPORT = 10200,  // ��Ƶ����Ϊmic inģʽ�²�֧����Ƶ�쳣���
    PU_ERROR_CODE_CIF_CONFLICT = 10202,                  // �������Ȼ��⣬CIF������
    PU_ERROR_CODE_CORRIDOR_CONFLICT = 10203,             // ����CIF���⣬���Ȳ�����

    PU_RESULT_ERR_POINT_OUTOF_RANGE = 10211,
    PU_RESULT_ERR_LINE_BECOME_POINT = 10212,
    PU_RESULT_ERR_LINE_CROSS = 10213,

    PU_ERROR_ISP_AE_MANUAL_CONFLICT_WD = 10214,  // �ֶ��ع����̬����
    PU_ERROR_ISP_AE_MANUAL_CONFLICT_FLICKER,     // �ֶ��ع��뱳��Ƶ�ʻ���
    PU_ERROR_ISP_AE_MANUAL_CONFLICT_HLC,         // �ֶ��ع���ǿ������
    PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_WD,         // �ع�ģʽ�����������̬����
    PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_FLICKER,    // �ع�ģʽ���������뱳��Ƶ�ʻ���
    PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_HLC,        // �ع�ģʽ����������ǿ������
    PU_ERROR_ISP_BACKLIGHT_CONFLICT_WD,          // ���ⲹ�����̬����
    PU_ERROR_ISP_BACKLIGHT_CONFLICT_HLC,         // ���ⲹ����ǿ�����ƻ���
    PU_ERROR_ISP_WD_CONFLICT_HLC,                // ��̬��ǿ�����ƻ���
    PU_ERROR_ISP_DEFOG_CONFLICT_WD,              // ͸��ģʽ���̬����
    PU_ERROR_ISP_HLC_CONFLICT_FRAMERATE,         // ǿ��������50֡60֡����
    PU_ERROR_ISP_WD_CONFLICT_FRAMERATE,          // ��̬��50֡60֡����
    PU_ERROR_ISP_AE_MANUAL_CONFLICT_BACKLIGHT,   // �ֶ��ع��뱳�ⲹ��
    PU_ERROR_ISP_HLC_CONFLICT_SLOW_SHUTTER,      // ǿ�������������Ż���
    PU_ERROR_ISP_WD_CONFLICT_SLOW_SHUTTER,       // ��̬�������Ż���
    PU_ERROR_MULTI_STREAM_CONFLICT_FACE_DT,      // ��������������⻥��(��ǰ��M2120-EFI�������������˫����(������1�ֱ���D1����))

    PU_ERROR_CODE_DOWNLOAD_FILE_ERROR = 10300,            // �ļ�����ʧ��
    PU_ERROR_CODE_CONNECTION_SERVER_INTERRUPTED = 10301,  // ���ӷ������ж�
    PU_ERROR_CODE_REQUEST_OVERTIME = 10302,               // ����ʱ
    PU_ERROR_CODE_CONNECTION_SERVER_FAIL = 10303,         // ���ӷ�����ʧ��
    PU_ERROR_CODE_CONNECTION_NOT_FOUND = 10304,           // ����δ�ҵ�
    PU_ERROR_CODE_RECONNECTING_TO_SERVER = 10305,         // �����������ӷ�����
    PU_ERROR_CODE_FILE_NOT_EXIST = 10306,                 // �ļ�������

    PU_ERROR_CODE_INVALID_UPDATEFILE = 10310,   // �����ļ��Ƿ�
    PU_ERROR_CODE_UPDATEFILE_BAD = 10311,       // �ļ���
    PU_ERROR_CODE_INVALID_FILE_FORMAT = 10312,  // �ļ���ʽ����

    PU_ERROR_CODE_UPGRADE_TYPE_ERR = 10350,     // �����ļ��������������Ͳ���
    PU_ERROR_CODE_UPGRADE_PARAM_NULL = 10351,   // ��������Ϊ��
    PU_ERROR_CODE_UPGRADE_NOT_UPLOAD = 10352,   // �����ļ�δ�ϴ�
    PU_ERROR_CODE_UPGRADE_VERIFY_FAIL = 10353,  // �����ļ�������У��ʧ��
    PU_ERROR_CODE_UPGRADE_SIGN_FAIL = 10354,    // �����ļ�����ǩ����֤ʧ��
    PU_ERROR_CODE_UPGRADE_SPACE_FULL = 10355,   // �����洢�ռ���
    PU_ERROR_CODE_UPGRADE_DEVICE_FAIL = 10356,  // �豸֧���б�����ʧ��

    PU_ERROR_RESULT_ALG_VER_ERR_U = 10357,           // �㷨���汾����(�㷨��Ҫ�������VRC�汾һ��)
    PU_ERROR_RESULT_ALG_VER_NEED_UPGRADE_U = 10358,  // �汾����������ʾ��Ҫ�����㷨��

    PU_ERROR_RESULT_NEED_FACE_ALG_UPGRADE = 10361,  // ��Ҫ���������㷨��
    PU_ERROR_RESULT_NEED_VHD_ALG_UPGRADE = 10362,   // ��Ҫ�����������㷨��

    PU_ERROR_SD_NOT_FORMAT = 10601,                  // SD��δ��ʽ��
    PU_ERROR_CODE_CUSTOM_PACKAGE_UNDEFINED = 10602,  // �����ײ͡�ISP�ײ�δ����
    PU_ERROR_CODE_PTZ_BUSY = 10603,                  // ��̨δֹͣ

    PU_ERROR_CODE_OSDI_AREA_NOT_EXIST = 10700,          // ���򲻴��ڣ�����ֵ����
    PU_ERROR_CODE_OSDI_AREA_TOO_LARGE = 10701,          // ����ˮƽ��ȳ���180��
    PU_ERROR_CODE_OSDI_AREA_INVALID_VERDEGREE = 10702,  // ��������㲻�����������Ϲ���
    PU_ERROR_CODE_OSDI_INDEX_AlREADY_EXIST = 10705,     // �������������ŷǷ��������Ѵ���
    PU_ERROR_CODE_OSDI_HOR_OR_VER_EQUAL = 10708,        // ���������ˮƽ��ֱ�������
    PU_ERROR_CODE_OSDI_INDEX_INVALID = 10709,           // ���������ŷǷ���С��1
    PU_ERROR_CODE_OSDI_INDEX_EQUAL = 10710,             // �����������ظ�

    PU_ERROR_CODE_DST_ALREADY_OPEN = 10800,       // ����ʱ�Ѿ���
    PU_ERROR_CODE_SET_TIME_OUT_OF_RANGE = 10801,  // ����ʱ�䳬��ϵͳʱ�䷶Χ

    PU_STABILIZER_CONFLICT_AREA_CROP = 10900,    // ����������ü�����
    PU_AREA_CROP_CONFLICT_STABILIZER = 10901,    // ����ü����������
    PU_RESULT_STABILIZER_CONFLICT_VLPR = 10902,  // ���ӷ�����ҵ���복�Ƽ�⻥��

    PU_ERROR_CODE_ITGT_IMRS_ERR_POINT_NULL = 10950,            // ָ��Ϊ��
    PU_ERROR_CODE_ITGT_IMRS_ERR_READ_FILE = 10951,             // ��ȡ�ļ�ʧ��
    PU_ERROR_CODE_ITGT_IMRS_ERR_XML_PARSER = 10952,            // xml����
    PU_ERROR_CODE_ITGT_IMRS_ERR_IMG_TPYE = 10953,              // ͼ������
    PU_ERROR_CODE_ITGT_IMRS_ERR_RESOLUTION_DIFF = 10954,       // �ֱ������ʼ��ͬ
    PU_ERROR_CODE_ITGT_IMRS_ERR_VERTEX_ILLEGAL = 10955,        // �����겻����
    PU_ERROR_CODE_ITGT_IMRS_ERR_RESOLUTION_UNSUPPORT = 10956,  // �ֱ��ʲ�֧��
    PU_ERROR_CODE_ITGT_IMRS_ERR_PARAM_ERR = 10957,             // ��������
    PU_ERROR_CODE_ITGT_IMRS_ERR_MALLOC_FAILED = 10958,         // �ڴ����ʧ��
    // ���ƴ���
    PU_ERROR_CODE_ITGT_IMRS_ERR_NOT_CONFIG = 10961,  // ���ô���
    PU_ERROR_CODE_ITGT_IMRS_ERR_PARAM_SET = 10962,   // �������ô���
    // �����ߴ���
    PU_ERROR_CODE_ITGT_IMRS_ERR_LANE_OVERLAP = 10963,   // �����ߴ���
    PU_ERROR_RESULT_VLPR_ERR_LINE_OUTOF_RANGE = 10964,  // ����ʧ�ܣ�����߲��ڳ����߷�Χ��

    PU_ERROR_CODE_SHORT_KEY = 11001,                   // ֤����Կ����
    PU_ERROR_CODE_WEAK_CERT = 11002,                   // ֤����Կ����
    PU_ERROR_CODE_GET_TEMPERTURE_VW_RET_FAIL = 11024,  // ���� VM �ӿ�ʧ�ܣ������������ȡ�¶�

    PU_RESULT_ITS_ERR_INVALID_LANE_TYPE = 11100,      // ���������ͳ�����Χ
    PU_RESULT_ITS_ERR_INVALID_LANE_NUM,               // ��������������Ч��Χ��
    PU_RESULT_ITS_ERR_INVALID_LANE_DIR,               // ����������Ч
    PU_RESULT_ITS_ERR_INVALID_LANE_DRV_DIR,           // ������ʻ������Ч
    PU_RESULT_ITS_ERR_INVALID_LANE_PURPOSE,           // ������;��Ч
    PU_RESULT_ITS_ERR_INVALID_LANE_ATTR,              // ����������Ч
    PU_RESULT_ITS_ERR_INVALID_CAR_DRV_DIR,            // ��ʻ������Ч
    PU_RESULT_ITS_ERR_INVALID_SIGN_DIR,               // ָʾ������Ч
    PU_RESULT_ITS_ERR_INVALID_NORMAL_SIGN_SPEED,      // С����־�ٶ���Ч
    PU_RESULT_ITS_ERR_INVALID_NORMAL_LOW_SPEED,       // С�����Ƶ�����Ч
    PU_RESULT_ITS_ERR_INVALID_NORMAL_HIGH_SPEED,      // С�����Ƹ�����Ч
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SIGN_SPEED,  // �󳵱�־�ٶ���Ч
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_LOW_SPEED,   // �����Ƶ�����Ч
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_HIGH_SPEED,  // �����Ƹ�����Ч
    PU_RESULT_ITS_ERR_INVALID_EXTERN_LAMP_BITMAP,     // ���õƹ�����Ч

    PU_RESULT_ITS_ERR_INVALID_SNAP_INTERVAL,                  // ץ�ļ��������Ч��Χ��
    PU_RESULT_ITS_ERR_INVALID_DT_TYPE,                        // ��ⷽʽ������Ч��Χ��
    PU_RESULT_ITS_ERR_INVALID_REGULATION_NUM,                 // Υ����Ŀ��������
    PU_RESULT_ITS_ERR_INVALID_REGULATION_TYPE,                // Υ��������Ч
    PU_RESULT_ITS_ERR_INVALID_SNAP_NUM,                       // Υ��ץ������������Ч��Χ��
    PU_RESULT_ITS_ERR_INVALID_RUNNINGRED_PRIORITY,            // ��������ȼ���Ч
    PU_RESULT_ITS_ERR_INVALID_OVER_LANE_SENSITIVITY,          // ѹ��������������Ч
    PU_RESULT_ITS_ERR_INVALID_VINBIKELANE_STAYTIME,           // ��ռ��ͣ��ʱ����Ч
    PU_RESULT_ITS_ERR_INVALID_OVER_BUSLANE_STAYTIME,          // ռ�ù�������ʱ����Ч
    PU_RESULT_ITS_ERR_INVALID_PARKINGTIME,                    // ��������ͣ��ʱ����Ч
    PU_RESULT_ITS_ERR_INVALID_LIGHT_DT_TYPE,                  // �źŵƽ��뷽ʽ������Ч��Χ��
    PU_RESULT_ITS_ERR_INVALID_LIGHT_AREA_NUM,                 // �źŵ�������Ŀ��Ч
    PU_RESULT_ITS_ERR_INVALID_LIGHT_NUM,                      // �źŵƸ�����Ч
    PU_RESULT_ITS_ERR_INVALID_LIGHT_ARRANGE_TYPE,             // �źŵƷ�����Ч
    PU_RESULT_ITS_ERR_INVALID_YELLOW_TIME,                    // �ƵƳ���ʱ����Ч	
    PU_RESULT_ITS_ERR_INVALID_LIGHT_AREA,                     // �źŵ�������Ч
    PU_RESULT_ITS_ERR_LINE_OUTOF_RANGE,                       // ����ߡ�ֹͣ�߲��ڳ����߻��ұ߽�����Ч��Χ��
    PU_RESULT_ITS_ERR_INVALID_NORMAL_SPEED_RANGE_CONFIG,      // ��С�����Ƶ��ٴ������Ƹ��� ,���ش���
    PU_RESULT_ITS_ERR_INVALID_NORMAL_SIGN_SPEED_CONFIG,       // С����־�ٶȲ��ڵ͸����� ,���ش���
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SPEED_RANGE_CONFIG,  // ���󳵵��ٴ��ڸ���, ���ش���
    PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SIGN_SPEED_CONFIG,   // ���󳵱�־�ٶȲ��ڵ͸�����, ���ش���
    PU_RESULT_ITS_ERR_INVALID_RETURNDATA,
    PU_RESULT_ITS_ERR_INVALID_CONGESTION_THRESHOLD,
    PU_RESULT_ITS_ERR_INVALID_SNAP_INTERVAL_TYPE,       // ץ�ļ��������Ч
    PU_RESULT_ITS_ERR_INVALID_ADAPT_SNAP_LOWSPEED,      // ����Ӧץ�ļ���������ֵ��Ч
    PU_RESULT_ITS_ERR_INVALID_ADAPT_SNAP_MIDSPEED,      // ����Ӧץ�ļ���������ֵ��Ч
    PU_RESULT_ITS_ERR_INVALID_ADAPT_LOWSPEED_INTERVAL,  // ����Ӧ����ץ�ļ����Ч
    PU_RESULT_ITS_ERR_INVALID_ADAPT_MIDSPEED_INTERVAL,  // ����Ӧ����ץ�ļ����Ч
    PU_RESULT_ITS_ERR_INVALID_ADAPT_HISPEED_INTERVAL,   // ����Ӧ����ץ�ļ����Ч
    PU_RESULT_ITS_ERR_INVALID_LANE_ORDER,               // ����ʧ�ܣ������ߡ������ұ������������Ұ������

    PU_RESULT_ITS_ERR_INVALID_LIGHT_CONFIGDUPLICATION = 11146,  // �źŵƵ����ظ�
    PU_RESULT_ITS_ERR_INVALID_PRETESTLINE_LOCATION,             // ǰ����Ӧ������ֹͣ�ߵ��·�

    PU_RESULT_ITS_ERR_PORTID_REPEAT = 11152,  // ����ʧ�ܣ��˿ں��ظ�

    PU_ERROR_RESULT_HBTP_ERR_BAD_REQUEST = 11400,   //HBTP_CODE ӳ�������
    PU_ERROR_RESULT_HBTP_ERR_UNAUTHORIZED = 11401,
    PU_ERROR_RESULT_HBTP_ERR_FORBIDDEN = 11403,
    PU_ERROR_RESULT_HBTP_ERR_NOT_FOUND = 11404,
    PU_ERROR_RESULT_HBTP_ERR_INTERNAL_SERVER_ERROR =11500,

    // �㷨 ���������
    PU_RESULT_TGT_FUNCTION_MUTUAL_LRPR = 12000,         // ���ȹرճ���ʶ����
    PU_RESULT_TGT_FUNCTION_MUTUAL_FD,                   // ���ȹر�������⹦��
    PU_RESULT_TGT_FUNCTION_MUTUAL_CD,                   // ���ȹر�ͣ����⹦��
    PU_RESULT_TGT_FUNCTION_MUTUAL_VA,                   // ���ȹر���Ϊ��������
    PU_RESULT_TGT_FUNCTION_MUTUAL_HC,                   // ���ȹرչ���ͳ�ƹ���
    PU_RESULT_TGT_FUNCTION_MUTUAL_AT,                   // ���ȹر��Զ����ٹ���
    PU_RESULT_TGT_FUNCTION_MUTUAL_VHD,                  // ���ȹرջ����˼�⹦��
    PU_RESULT_TGT_FUNCTION_MUTUAL_ITS,                  // ���ȹر����ܽ�ͨ����
    PU_RESULT_TGT_FUNCTION_MUTUAL_QD,                   // ���ȹر��ŶӼ�⹦��
    PU_RESULT_TGT_FUNCTION_MUTUAL_CDD,                  // ���ȹر���Ⱥ�ܶȹ���
    PU_RESULT_TGT_FUNCTION_MUTUAL_IBALL,                // ���ȹر����ܽ�ͨ-Υ������
    PU_RESULT_TGT_FUNCTION_MUTUAL_VHDFACE,              // ���ȹر�һ�����ù���
    PU_RESULT_ITGT_MODE_NOTSUPPORT_ALG,                 // ��ǰģʽ�²�֧�ָ��㷨
    PU_RESULT_TGT_VHD_DETECTION_ERR_WRONG_VIDEO_MODE,   // �����˲�֧������ģʽ���ȹر�����ģʽ
    PU_RESULT_TGT_FUNCTION_MUTUAL_BEH,                  // ���ȹر���ǿģʽ��Ϊ��������
    PU_RESULT_TGT_FUNCTION_MUTUAL_CAMPUS_TRAFFICEVENT,  // ���ȹرճ����ҵ��
    PU_RESULT_TGT_FUNCTION_MUTUAL_CAMPUS_ALG_TYPE,      // �����ҵ����ֻ֧�ֹ��ڳ����㷨����֧�ֺ��⳵���㷨
    PU_RESULT_TGT_FUNCTION_MUTUAL_MD,                   // ���ȹر��ƶ���⹦��
    PU_RESULT_TGT_FUNCTION_MUTUAL_OD,                   // ���ȹر��ڵ��澯����
    PU_RESULT_TGT_FUNCTION_MUTUAL_SC,                   // ���ȹرճ����������
    PU_RESULT_TGT_FUNCTION_MUTUAL_OOD,                  // ���ȹر��齹��⹦��
    PU_RESULT_TGT_FUNCTION_MUTUAL_CA,                   // ���ȹر���Ա�ۼ�����
    PU_RESULT_TGT_FUNCTION_MUTUAL_HM,                   // ���ȹر��ȶ�ͼ����

    PU_RESULT_TGT_FUNCTION_MUTUAL_TRAFFICEVENT_CAMPUS,       // ���ȹر�ȫ�������¼�ҵ��
    PU_RESULT_TGT_FUNCTION_MUTUAL_TRAFFIC_STATISTIC_CAMPUS,  // ���ȹرս�ͨ����ͳ��ҵ��
    PU_RESULT_TGT_FUNCTION_MUTUAL_VD,                        // ���ȹر���Ƶ�������
    PU_RESULT_TGT_FUNCTION_MUTUAL_STABILIZER,                // ���ȹرյ��ӷ���ҵ��

    PU_RESULT_TGT_FUNCTION_MUTUAL_IMG_QUALITY_JUDGE = 12027,  // ͼ�������ж�ʱ��ر���������ҵ��

	PU_RESULT_TGT_FUNCTION_MUTUAL_FACE_REC = 12029,                  // ���ȹر�����ʶ����
	PU_RESULT_TGT_FUNCTION_MUTUAL_FC,                        // ���ȹرո�������

    // ��������������ش�����
    PU_RESULT_ITGT_ERR_FACE_SUCCESS = 12100,                // ��������ɹ�
    PU_RESULT_ITGT_ERR_FACEREC_DISABLE,                     // ����ʶ��δʹ��
    PU_RESULT_ITGT_ERR_DATA_UPDATE,                         // ���ݸ���ʧ��
    PU_RESULT_ITGT_ERR_OPREATION_NOTSUPPORT,                // ������֧��
    PU_RESULT_ITGT_ERR_OPREATION_UNFINISHED,                // �����������δ���
    PU_RESULT_ITGT_ERR_FACELIB_OVERSIZE,                    // �׿������������
    PU_RESULT_ITGT_ERR_FACENUM_OVERSIZE,                    // ����������������
    PU_RESULT_ITGT_ERR_DB_ERROR,                            // ���ݿ����ʧ��
    PU_RESULT_ITGT_ERR_FACELIST_REPAT,                      // �������ظ�
    PU_RESULT_ITGT_ERR_FACEPIC_OVERSIZE,                    // ͼƬ��߳���Χ
    PU_RESULT_ITGT_ERR_FACE_DECODE,                         // ͼƬ����ʧ��
    PU_RESULT_ITGT_ERR_FACE_DETECTION,                      // �������ʧ��
    PU_RESULT_ITGT_ERR_FACE_FEATURE,                        // ����������ȡʧ��
    PU_RESULT_ITGT_ERR_FACE_DAO,                            // �����־û����ݿ�ʧ��
    PU_RESULT_ITGT_ERR_FACE_FILE,                           // ������д�ļ�ʧ��
    PU_RESULT_ITGT_ERR_FACE_ALGDISABLE,                     // �����㷨δ����
    PU_RESULT_ITGT_ERR_FACE_NOFEATURE,                      // �����׿�������
    PU_RESULT_ITGT_ERR_FACE_UZIP,                           // zip����ѹʧ��
    PU_RESULT_ITGT_ERR_FACE_CSV,                            // csv�ļ�����ʧ��
    PU_RESULT_ITGT_ERR_FACE_ENCRYPT,                        // face�ӽ���ʧ��
    PU_RESULT_ITGT_ERR_FACE_TASKUNKNOW,                     // ����δ����
    PU_RESULT_ITGT_ERR_FEATURE_EXTRACT_SUCCESS,             // ������ȡ�ɹ�
    PU_RESULT_ITGT_ERR_FEATURE_EXTRACTED,                   // ��������ȡ
    PU_RESULT_ITGT_ERR_FACEREC_ENABLE_FAIL,                 // ����ʶ��ʹ��ʧ�ܣ�����㷨�������ڻ�汾��ƥ������
    PU_RESULT_ITGT_ERR_FACE_FEATURE_LOAD_PROCESSING,        // ����ʶ�������ʷ���أ�ϵͳ����ʱ��Ҫ��������
    PU_RESULT_ITGT_ERR_FACE_FEATURE_PAC_IMPORT_PROCESSING,  // �����������ڵ���������
    PU_RESULT_ITGT_ERR_FACE_PIC_PAC_IMPORT_PROCESSING,      // ������������ͼƬ������
    PU_RESULT_ITGT_ERR_FACE_FEATURE_GET_PROCESSING,         // ��������������������
    PU_RESULT_ITGT_ERR_FACE_FEATURE_EXTRACT_PROCESSING,     // ������������������ȡ
    PU_RESULT_ITGT_ERR_FACE_QUALITY_CLEARNESS,              // ����ͼƬ�����Ȳ���    2129
    PU_RESULT_ITGT_ERR_FACE_QUALITY_KPS,                    // ����ͼƬ�ڵ�������    
    PU_RESULT_ITGT_ERR_FACE_CROWD_NOTSUPPORT,               // ��֧�ָ�������ץ��     
    PU_RESULT_ITGT_ERR_EMMC_STATUS_ABNORMAL = 12132,        // EMMC״̬�쳣
    PU_RESULT_ITGT_ERR_FACE_QUICKCAP_NOTSUPPORT_BLACK,      // ����ץ�Ĳ�֧�ֺ���������
    PU_RESULT_ITGT_ERR_FACEREC_DISK_SPACE_NOT_ENOUGH,       // ���̿ռ䲻��              
    PU_RESULT_ITGT_ERR_FACE_RECORD_CHECK,                   // ������¼��ϢУ��ʧ��
    PU_RESULT_ITGT_ERR_FACEREC_MULTI_FRAME,                 // ��֧�ֶ�֡����ʶ��
    PU_RESULT_ITGT_ERR_CLOSE_MULTI_FRAME_INFO,              // ���ȹر�����ʶ���֡�ں�
    PU_RESULT_ITGT_ERR_FEATURE_FILE,                        // ��feature.bin�ļ��ж�ȡ�����ṹ��ʧ��
    PU_RESULT_ITGT_ERR_FEATURE_NOTIFYONE,                   // ��װ����NotifyOneʧ��
    PU_RESULT_ITGT_ERR_DATABASE_ENCRYPT_KEY,                // ���ݿ���Կ����

    // ͣ����������
    PU_RESULT_TGT_CAR_DATECTION_ERR_WRONG_VIDEO_MODE = 12200,    // ͣ������ʱ����ģʽ�;���ģʽ����ر�
    PU_RESULT_ITGT_VHD_ERR_WRONG_VIDEO_MODE,                     // �����˴�ʱ����ģʽ����ر�
    PU_RESULT_ITGT_VLPR_ERR_WRONG_VIDEO_MODE,                    // ����ʶ���ʱ����ģʽ����ر�
    PU_RESULT_ITGT_NOT_FACE_DETETION_MODE_ERR_WRONG_VIDEO_MODE,  // -H���ͷ��˿�ģʽʱ����ģʽ����ر�(���С�΢������Ϊ������֧��)

    PU_RESULT_LIC_INVALID = 12300,                        // license�Ƿ�����ȡlicense����ʧ��
    PU_RESULT_LIC_REPEATED_ESN_VER_MISMATCH,              // �������ظ����� ESN ��汾��ƥ���License�ļ�
    PU_RESULT_LIC_FORMAT_ERROR,                           // License�ļ����Ϸ�
    PU_RESULT_LIC_NO_PRD_FEATURES_PRESENT,                // License�ļ���û�в�Ʒ������
    PU_RESULT_LIC_PRODUCT_INVALID,                        // ��Ʒ������Ч
    PU_RESULT_LIC_EXPIRED,                                // License�ļ�����
    PU_RESULT_LIC_GET_CONFIG_ERROR,                       // ��ȡ����������ֵʧ��
    PU_RESULT_LIC_LSN_REVOKED,                            // License�ļ��Ѿ�ʧЧ
    PU_RESULT_LIC_ESNANY_AND_SIX_MON_VLDITY_NOT_ALLOWED,  // �������ظ�����ESN=ANY����Ч��Ϊ 6���µĵ���License �ļ�
    PU_RESULT_LIC_MAX_FEATURES_REACHED,                   // License�ļ���Feature�������������ֵ
    PU_RESULT_LIC_INVALID_FEATURE_TYPE,                   // License�ļ���Feature�����ʹ���
    PU_RESULT_LIC_LM_NOT_ENABLED,                         // License���û������
    PU_RESULT_LIC_NO_FEATURES_IN_NORMAL_STATE,            // License�ļ������е�Feature���ڻ��ߴ���������
    PU_RESULT_LIC_ESN_MISMATCH,                           // License�ļ�ESN��ʵ��ESN��һ��
    PU_RESULT_LIC_VERSION_MISMATCH,                       // License�ļ��汾��ʵ�ʰ汾��һ��
    PU_RESULT_LIC_NO_LICENSE_ACTIVITED,                   // û�м����license
    PU_RESULT_MTU_ERR_WITH_IPV6_OPEN = 12520,             // IPV6������MTU����
	PU_RESULT_IP_NOT_SUPPORT = 12522,          //�������ε�IP�������ã���127.0.0.1/8��169.254.0.0/16���β�������
    PU_RESULT_ITGT_ERR_INVALID = 12600,                   // ����license��Ч״̬
    PU_RESULT_MEDIA_UTGT_NOT_ENABLED = 12780,             /* ý�崴������ͨ��������ģ��û��ʹ�� */

    // �㷨�л�
    PU_RESULT_TGT_SWITCH_MODE_ERR_WRONG_VIDEO_MODE = 12800,  // �л���ģʽ��֧������ģʽ
    PU_RESULT_TGT_SWITCH_MODE_ERR_ENABLE_ALG,                // �л���ģʽ�㷨����ʧ�ܣ��ȼ��ģ��
    PU_RESULT_TGT_SWITCH_MODE_FTP_NEED_RECONFIG,             // �л�ģʽ�ɹ���ftp��Ҫ��������

    // ��ͼ������
    PU_RESULT_ODS_MOVE_DEVICE_NOT_INIT = 13250,   // δ��ʼ������
    PU_RESULT_ODS_MOVE_DEVICE_ABNORMAL,           // �����쳣
    PU_RESULT_GET_ODS_MOVE_DEVICE_LOG_INFO_FAIL,  // ��ȡ������־ʧ��
    PU_RESULT_GET_ODS_MOVE_DEVICE_CONFIG_FAIL,    // ��ȡ���������ļ�ʧ��
    PU_RESULT_SET_ODS_MOVE_DEVICE_CONFIG_FAIL,    // ���ö��������ļ�ʧ��
    PU_RESULT_SET_ODS_MOVE_DEVICE_REBOOT_FAIL,    // ��������ʧ��
    PU_RESULT_SET_ODS_MOVE_DEVICE_RESTORE_FAIL,   // ����ָ�Ĭ��ʧ��
    PU_RESULT_ODS_SDK_FAIL,                       // SDK�ڲ�����
    PU_RESULT_NEED_STOP_TRACK_ERR,                // ���ٿ���״̬��(1)�޷��궨(2)�޷�������λ����ʾ�ȹرո���
    PU_RESULT_IN_CALIBRATING_ERR,                 // ���ڱ궨�У��޷��궨����ʾ���ڱ궨
    PU_RESULT_NOT_CALIBRATING_ERR,                // δ��ɱ궨��(1)�޷�������λ(2)�޷��������٣���ʾδ��ɱ궨��������ɱ궨
    PU_RESULT_NOT_IN_CALIBRATING_ERR,             // ���ڱ궨�У�����ȡ������ѯ���ȣ���ʾ��δ�ڱ궨������
	PU_RESULT_CLOSE_YTN_INFO,                     // ���㿪����1��N����ʾ�ȹر�
	PU_RESULT_FORCED_VHD_FACE_INFO,               // �л����� ������Ҫǿ���л�Ϊ����
	PU_RESULT_NOT_SUPPORT_FACE_SELCTED_IN_TRACK = 13269,	// �����������ٿ������޷�������ѡģʽ����ʾ�������������٣��޷�����������ѡģʽ
	PU_RESULT_CALIB_NOT_SUPPORT_MIRROR,						// �궨��֧�־���ģʽ����ʾ������ģʽ�£��޷��궨  3270

    PU_RESULT_SET_FIXED_FACEREC_FAIL = 13293,     // ��ͼ����ʶ�𶨵�����ʧ��
    PU_RESULT_SET_MOV1_FACEREC_FAIL,              // ��ͼ����ʶ�𶯵�1����ʧ��
    PU_RESULT_SET_MOV2_FACEREC_FAIL,              // ��ͼ����ʶ�𶯵�2����ʧ��


    PU_RESULT_Onvif_28181_CONFLICT = 13600 ,           //Onvif 28181Э���ͻ

    PU_RESULT_ITGT_NO_DISK = 13700,               // ��SD��
	PU_RESULT_ITGT_ERR_NEED_EVAL_FIRST = 13800, // ��Ҫ�Ƚ����ֶ�ץ�ģ���������
	PU_RESULT_NO_KEY_FILE_ERR = 13550,          //û����Կ�ļ�
	PU_RESULT_SET_CHECK_KEY_FILE_FAIL = 13551, //��Կ�ļ�У��ʧ��

	//������app��װ������
	PU_RESULT_EXIT_3APP_CONFIG = 14201, 				// ������������ʧ��
	PU_RESULT_EXIT_3APP_STOP_CONTAINER = 14203, 		// ֹͣ����ʧ��
	PU_RESULT_EXIT_3APP_START_CONTAINER, 				// ��������ʧ��  14204
	PU_RESULT_EXIT_3APP_SPACE_NOT_ENOUGH = 14211, 		// �ռ䲻��
	PU_RESULT_EXIT_3APP_PARA_CNT = 14215, 				// �����Ƿ���������μ��������������־
	PU_RESULT_EXIT_3APP_CREATE_CONTAINER = 14220, 		// ��������ʧ��
	PU_RESULT_EXIT_3APP_NAME_INVALID = 14222, 			// app���ַǷ�
	PU_RESULT_EXIT_3APP_FILE_NOT_EXISTS, 				// �ļ�������  14223
	PU_RESULT_EXIT_3APP_BASE_VERSION_NOT_INSTALLED,		// �����汾��δ��װ  14224
	PU_RESULT_EXIT_3APP_INVALID_POSITION = 14227, 		// ��װλ�÷Ƿ�
	PU_RESULT_EXIT_3APP_DATA_DISK_SIZE_UNKNOWN, 		// ������δָ����С
	PU_RESULT_EXIT_3APP_START_LCRD, 					// ������������ʧ��
	PU_RESULT_EXIT_3APP_ENTRY_NOT_SPECIFIED, 			// ����appδָ����ڳ���
	PU_RESULT_EXIT_3APP_VENDOR_INVALID,					// VENDOR���ַǷ�
	PU_RESULT_EXIT_3APP_ARCH_NOT_MATCH, 				// ��װ����SDC�ܹ���һ�� 14232
    PU_RESULT_EXIT_RUNNING_CAN_NOT_FORMAT_SD,           // ��ǰ��APP�����У��޷���ʽ��SD��

	//�ؼ������룬50000����
	PU_RESULT_PLAYER_RET_ERROR = 50001,            //ʧ�ܣ� �ؼ�����Ϊ1 ����ӳ��
	PU_RESULT_PLAYER_RET_PARAM_INVALID = 50002,		     //��������Ƿ��� �ؼ�����Ϊ2�� ��ӳ��
	PU_RESULT_PLAYER_RET_SAVE_PIC_FILE_ERROR = 510004,  // ����ͼƬ�ļ�ʧ��
	PU_RESULT_PLAYER_RET_ALLOC_MEM_ERROR = 510007,  // �������ʧ��
	PU_RESULT_PLAYER_RET_ORDER_ERROR = 510023,  // ����˳�򲻶�
	PU_RESULT_PLAYER_RET_CHANNEL_NOT_EXIST_ERROR = 510026,  // ͨ��������
	PU_RESULT_PLAYER_RET_JPEG_COMPRESS_ERROR = 510040,  // JPEGѹ��ʧ��
	PU_RESULT_PLAYER_RET_CREATE_FILE_ERROR = 510045,  // ¼�񴴽��ļ�ʧ��
    PU_ERROR_MAX ,
} PU_ERROR_CODE_E;

// ��־��ӡ����
typedef enum PU_LOG_LEVEL {
    PU_LOG_LEVEL_NOTICE = 0,     // ��ʾ��־
    PU_LOG_LEVEL_DEBUG = 1,      // ������־
    PU_LOG_LEVEL_WARNING = 2,    // �澯��־
    PU_LOG_LEVEL_ERROR = 3,      // ������־
    PU_LOG_LEVEL_OPERATION = 4,  // ������־
    PU_LOG_LEVEL_RUNNING = 5,    // ������־
    PU_LOG_LEVEL_CRITICAL = 6,   // ������־
    PU_LOG_LEVEL_MAX
} PU_SDK_LOG_LEVEL_E;

// �������� REQ_NULLΪ�˱�ʾ��ʼ����δ��ֵ�����   2018/06/26 By y00445101
typedef enum PU_REQ_TYPE {
    REQ_NULL,
    REQ_GET,
    REQ_SET
} PU_REQ_TYPE_E;

// �½ӿ����� �������ӿں���ʹ��   2018/06/29 By y00445101
typedef enum PU_INTERFACE_TYPE {
    PU_ITF_TYPE_SIM_PHONE_NUM = 1,  // SIM�ֻ�����
    PU_ITF_TYPE_MAX                 // Ԥ��
} PU_INTERFACE_TYPE_E;

// ǰ��ע��ģʽ
typedef enum PU_LINK_MODE {
    PU_AUTOLOGIN_MODE = 0,    // ������½ģʽ����ʼ����ǰ���豸������¼��SDK����������֧��
    PU_MANUALLOGIN_MODE = 1,  // �ֶ���½ģʽ�����ֶ�����IVS_PU_Login��¼ǰ���豸
    PU_BOTHLOGIN_MODE = 3,    // �������ֵ�½ģʽ��֧�֣���IPC֧��

    PU_LINK_MODE_MAX
} PU_LINK_MODE_E;

// device event callback type
typedef enum PU_EVENT_TYPE {
    /* ����״̬�ص� */
    PU_EVENT_TYPE_CONNCET = 1,      // ǰ���������ӣ�����������
    PU_EVENT_TYPE_REGISTER,         // ǰ������ע��
    PU_EVENT_TYPE_NOT_REGISTER,     // ǰ���������Ӻ�δע��
    PU_EVENT_TYPE_UNREGISTER,       // ǰ������ע��
    PU_EVENT_TYPE_DISCONNECT,       // ǰ���������ӶϿ�
    PU_EVENT_TYPE_SEND_RECV_ERROR,  // ���ͻ����ʧ��
    PU_EVENT_TYPE_KEEPLIVE_FAIL,    // ǰ�˱���ʧ��

    /* �¼�֪ͨ�ص� */
    PU_EVENT_TYPE_STREAM_PACKAGE_CHANGE,       // ���ײͱ��
    PU_EVENT_TYPE_WATERMARK_ERR,               // ����ˮӡУ�����
    PU_EVENT_TYPE_UPLOAD_IMAGE_URL,            // ǰ��������ȡץ��ͼƬ�ϴ�URL����
    PU_EVENT_TYPE_UPLOAD_IMAGE_COMP_NOTIFY,    // ǰ��ץ��ͼƬ�������֪ͨ
    PU_EVENT_TYPE_TRANSPARENT_CHANNEL_NOTIFY,  // ͸��ͨ�������ϱ�
    PU_EVENT_TYPE_REALPALY_ERROR,              // ʵ���쳣
    PU_EVENT_TYPE_REPORT_VISUAL_INFO,          // �ϱ����ӻ���Ϣ
    PU_EVENT_TYPE_PUPU_INFO,                   // ���Эͬ�����ϱ�
    PU_EVENT_TYPE_RECORD_COMP_NOTIFY,          // ¼���������֪ͨ
    PU_EVENT_TYPE_SLAVE_DEVICE_ADD,            // �������豸�¼�
    PU_EVENT_TYPE_SLAVE_DEVICE_MODIFY,         // �޸Ĵ��豸�¼�
    PU_EVENT_TYPE_SLAVE_DEVICE_DELETE,         // ɾ�����豸�¼�
    PU_EVENT_TYPE_SLAVE_DEVICE_ONLINE,         // ���豸�����¼�
    PU_EVENT_TYPE_SLAVE_DEVICE_OFFLINE,        // ���豸�����¼�
    PU_EVENT_TYPE_SDMS_MOVING_TO_FIX,          // ��ͼ�����������ϱ������¼�������������

    PU_EVENT_TYPE_MAX
} PU_EVENT_TYPE_E;

// ����Ƶ��������
typedef enum PU_ENCODE_TYPE {
    PU_ENC_PCMU = 0,
    PU_ENC_1016 = 1,
    PU_ENC_G721 = 2,
    PU_ENC_GSM = 3,
    PU_ENC_G723 = 4,
    PU_ENC_DVI4_8K = 5,
    PU_ENC_DVI4_16K = 6,
    PU_ENC_LPC = 7,
    PU_ENC_PCMA = 8,
    PU_ENC_G722 = 9,
    PU_ENC_S16BE_STEREO = 10,
    PU_ENC_S16BE_MONO = 11,
    PU_ENC_QCELP = 12,
    PU_ENC_CN = 13,
    PU_ENC_MPEGAUDIO = 14,
    PU_ENC_G728 = 15,
    PU_ENC_DVI4_3 = 16,
    PU_ENC_DVI4_4 = 17,
    PU_ENC_G729 = 18,
    PU_ENC_G711A = 19,  // g711a
    PU_ENC_G711U = 20,  // g711u
    PU_ENC_G726 = 21,   // g726
    PU_ENC_G729A = 22,
    PU_ENC_LPCM = 23,
    PU_ENC_CelB = 25,
    PU_ENC_JPEG = 26,
    PU_ENC_CUSM = 27,
    PU_ENC_NV = 28,
    PU_ENC_PICW = 29,
    PU_ENC_CPV = 30,
    PU_ENC_H261 = 31,
    PU_ENC_MPEGVIDEO = 32,
    PU_ENC_MPEG2TS = 33,
    PU_ENC_H263 = 34,
    PU_ENC_SPEG = 35,
    PU_ENC_MPEG2VIDEO = 36,
    PU_ENC_AAC = 37,
    PU_ENC_WMA9STD = 38,
    PU_ENC_HEAAC = 39,
    PU_ENC_PCM_VOICE = 40,
    PU_ENC_PCM_AUDIO = 41,
    PU_ENC_AACLC = 42,
    PU_ENC_MP3 = 43,
    PU_ENC_ADPCMA = 49,
    PU_ENC_AEC = 50,
    PU_ENC_X_LD = 95,
    PU_ENC_H264 = 96,
    PU_ENC_D_GSM_HR = 200,
    PU_ENC_D_GSM_EFR = 201,
    PU_ENC_D_L8 = 202,
    PU_ENC_D_RED = 203,
    PU_ENC_D_VDVI = 204,
    PU_ENC_D_BT656 = 220,
    PU_ENC_D_H263_1998 = 221,
    PU_ENC_D_MP1S = 222,
    PU_ENC_D_MP2P = 223,
    PU_ENC_D_BMPEG = 224,
    PU_ENC_MP4VIDEO = 230,  // mepg-4
    PU_ENC_MP4AUDIO = 237,
    PU_ENC_VC1 = 238,
    PU_ENC_JVC_ASF = 255,
    PU_ENC_D_AVI = 256,
    PU_ENC_OPUS = 258,  // opus
    PU_ENC_H265 = 265,

    PU_ENC_AMR = 1001,
    PU_ENC_MJPEG = 1002,  // motion jpeg

    PU_ENC_MAX
} PU_ENCODE_TYPE_E;

// ��Ƶ�ֱ�������
typedef enum PU_RESOLUTION_TYPE {
    PU_RESOLUTION_480I = 0,
    PU_RESOLUTION_576I,
    PU_RESOLUTION_QCIF_PAL,
    PU_RESOLUTION_QCIF_NTSC,
    PU_RESOLUTION_CIF_PAL,
    PU_RESOLUTION_CIF_NTSC,
    PU_RESOLUTION_2CIF,
    PU_RESOLUTION_HD1,
    PU_RESOLUTION_D1_PAL,  // 720 * 576
    PU_RESOLUTION_D1_NTSC,

    PU_RESOLUTION_QVGA,  // 320 * 240
    PU_RESOLUTION_VGA,   // 640 * 480
    PU_RESOLUTION_XGA,   // 1024 * 768
    PU_RESOLUTION_SXGA,  // 1400 * 1050
    PU_RESOLUTION_UXGA,  // 1600 * 1200
    PU_RESOLUTION_QXGA,  // 2048 * 1536

    PU_RESOLUTION_WVGA,   // 854 * 480
    PU_RESOLUTION_WSXGA,  // 1680 * 1050
    PU_RESOLUTION_WUXGA,  // 1920 * 1200
    PU_RESOLUTION_WQXGA,  // 2560 * 1600

    PU_RESOLUTION_HD720,   // 1280 * 720
    PU_RESOLUTION_HD1080,  // 1920 * 1080
    PU_RESOLUTION_HD1080I,

    PU_RESOLUTION_HD960,   // 1280 * 960
    PU_RESOLUTION_HD1024,  // 1280 * 1024

    PU_RESOLUTION_HD1296P = 25,  // 2304 * 1296
    PU_RESOLUTION_HD1440P = 26,  // 2560 * 1440
    PU_RESOLUTION_HD1728P = 27,  // 3072 * 1728
    PU_RESOLUTION_HD4K = 28,     // 3840 * 2160

    PU_RESOLUTION_HD1536P = 29,  // 2048 * 1536
    PU_RESOLUTION_HD1920P = 30,  // 2560 * 1920
    PU_RESOLUTION_HD1944P = 31,  // 2592 * 1944
    PU_RESOLUTION_HD2448P = 32,  // 3264 * 2448
    PU_RESOLUTION_HD2160P = 33,  // 4096 * 2160
    PU_RESOLUTION_HD2736P = 34,  // 3648 * 2736

    PU_RESOLUTION_2592_1520P = 35, /* 2592*1520      400W */
    PU_RESOLUTION_2560_2048 = 36,  /* 2560*2048  5:4 500W */
    PU_RESOLUTION_3072_2048 = 37,  /* 3072*2048  3:2 600W */

    PU_RESOLUTION_MAX
} PU_RESOLUTION_TYPE_E;

// ��Ƶ��ģʽ
typedef enum PU_STREAM_MODE_E {
    PU_VIEDO_STREAM_NONE = 0,    // ���������ײ�
    PU_VIEDO_STREAM_SINGLE = 1,  // ��Ƶ����
    PU_VIEDO_STREAM_DOUBLE = 2,  // ��Ƶ˫��
    PU_VIEDO_STREAM_TRIPLE = 3,  // ��Ƶ����
    PU_VIEDO_STREAM_FOUR = 4,    // ��Ƶ����
    PU_VIEDO_STREAM_FIVE = 5,    // ��Ƶ����
    PU_VIEDO_STREAM_MAX
} PU_STREAM_MODE_E;

// ��Ƶ������
typedef enum PU_STREAM_TYPE {
    PU_VIDEO_MAIN_STREAM = 0,  // ��Ƶ������
    PU_VIDEO_SUB_STREAM1,      // ��Ƶ������1
    PU_VIDEO_SUB_STREAM2,      // ��Ƶ������2
    PU_VIDEO_SUB_STREAM3,      // ��Ƶ������3
    PU_VIDEO_SUB_STREAM4,      // ��Ƶ������4
    PU_VIDEO_SUB_STREAM5,      //
    PU_VIDEO_STREAM_MAX
} PU_STREAM_TYPE_E;

// ͼ������
typedef enum PU_PIC_QUALITY {
    PU_PIC_QUALITY_BEST = 0,     // ���
    PU_PIC_QUALITY_MORE_BETTER,  // �κ�
    PU_PIC_QUALITY_BETTER,       // �Ϻ�
    PU_PIC_QUALITY_ORDINARY,     // һ��
    PU_PIC_QUALITY_BAD,          // �ϲ�
    PU_PIC_QUALITY_BADEST,       // ��
    PU_PIC_QUALITY_MAX
} PU_PIC_QUALITY_E;

// ��������
typedef enum PU_PROTOCOL_TYPE {
    PU_PROTOCOL_TYPE_UDP = 0,    // UDP��ʽ
    PU_PROTOCOL_TYPE_TCP,        // TCP��ʽ
    PU_PROTOCOL_TYPE_MULTICAST,  // �鲥��ʽ
    PU_PROTOCOL_TYPE_MAX
} PU_PROTOCOL_TYPE_E;

// ý��ص�����
typedef enum PU_MEDIA_CALLBACK_TYPE {
    PU_MEDIA_CALLBACK_TYPE_RTP = 0,     // RTP����ʽ
    PU_MEDIA_CALLBACK_TYPE_RTP_CRYPTO,  // RTP����ʽ��������
    PU_MEDIA_CALLBACK_TYPE_FRAME,       // ֡�ص���ʽ
    PU_MEDIA_CALLBACK_TYPE_YUV,         // YUV��ʽ��Linux��֧��
    PU_MEDIA_CALLBACK_TYPE_FOR_STORAGE,
    PU_MEDIA_CALLBACK_TYPE_META_FRAME,
    PU_MEDIA_CALLBACK_TYPE_MAX
} PU_MEDIA_CALLBACK_TYPE_E;

// ������
typedef enum PU_VIDEO_TYPE {
    PU_VIDEO_TYPE_VIDEO = 0,   // ��Ƶ��
    PU_VIDEO_TYPE_AUDIO,       // ��Ƶ��
    PU_VIDEO_TYPE_MUX,         // ������
    PU_VIDEO_TYPE_RECORD,      // ¼����
    PU_VIDEO_TYPE_META,        // Ԫ������
    PU_VIDEO_TYPE_VIDEO_META,  // ��Ƶ + Ԫ������
    PU_VIDEO_TYPE_MAX
} PU_VIDEO_TYPE_E;

// ý���������
typedef enum PU_MEDIA_CRYPTO_TYPE {
    PU_MEDIA_CRYPTO_NONE = 0,        // ������
    PU_MEDIA_CRYPTO_HW_SIMPLE = 1,   // ��Ϊ����
    PU_MEDIA_CRYPTO_AES_128BIT = 2,  // 128λAES����
    PU_MEDIA_CRYPTO_AES_192BIT = 3,  // 192λAES����
    PU_MEDIA_CRYPTO_AES_256BIT = 4,  // 256λAES����
    PU_MEDIA_CRYPTO_AES256_CBC = 5,  // AES CBCģʽ256λ
    PU_MEDIA_CRYPTO_MAX,
} PU_MEDIA_CRYPTO_TYPE_E;

// ��������
typedef enum PU_BIT_RATE_TYPE {
    PU_BIT_RATE_TYPE_FIXED = 0,  // ������
    PU_BIT_RATE_TYPE_VARIABLE,   // ������
    PU_BIT_RATE_TYPE_QP,         // MJPEG����
    PU_BIT_RATE_TYPE_MAX
} PU_BITRATE_TYPE_E;

// ��Ƶ��ʽ
typedef enum PU_VIDEO_FORMAT {
    PU_VIDEO_FORMAT_PAL = 0,  // P��
    PU_VIDEO_FORMAT_NTSC,     // N��
    PU_VIDEO_FORMAT_MAX
} PU_VIDEO_FORMAT_E;

/* ֡�������������� */
typedef enum PU_H264_RC_PRI {
    PU_H264_RC_FRAMERATE_PRI = 1,  // ֡������
    PU_H264_RC_BITRATE_PRI,        // ��������

    PU_H264_RC_PRI_MAX
} PU_H264_RC_PRI_E;

// ��������
typedef enum PU_LANGUAGE_TYPE {
    PU_LANGUAGE_TYPE_CHINESE = 0,  // ����
    PU_LANGUAGE_TYPE_ENGLISH,      // Ӣ��
    PU_LANGUAGE_TYPE_MAX
} PU_LANGUAGE_TYPE_E;

// ������Ϣ
typedef struct PU_LOG_LANGUAGE_INFO {
    ULONG ulChannelId;              // ͨ��ID
    PU_LANGUAGE_TYPE_E enLanguage;  // ��������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_LOG_LANGUAGE_INFO_S;

// ���ر���¼��ʽ
typedef enum PU_SAVE_REALDATA_TYPE {
    PU_SAVE_REALDATA_TYPE_TIME = 0,  // ��ʱ�䱣��(��λ��min)
    PU_SAVE_REALDATA_TYPE_SIZE = 1,  // ����С����(��λ��MBytes)
    PU_SAVE_REALDATA_TYPE_MAX
} PU_SAVE_REALDATA_TYPE_E;

// ���ر���ͼƬ��ʽ
typedef enum PU_SAVE_PICTURE_TYPE {
    PU_SAVE_PICTURE_TYPE_BMP = 0,   // BMP�ļ�
    PU_SAVE_PICTURE_TYPE_JEPG = 1,  // JPEG�ļ�
    PU_SAVE_PICTURE_TYPE_MAX
} PU_SAVE_PICTURE_TYPE_E;

// ��������
typedef enum PU_SERIAL_PORT_MODE {
    PU_SERIAL_PORT_RS232 = 0,  // 232����
    PU_SERIAL_PORT_RS422,      // 422����
    PU_SERIAL_PORT_RS485,      // 485����
    PU_SERIAL_PORT_MAX
} PU_SERIAL_PORT_MODE_E;

// ������
typedef enum PU_BAUD_RATE {
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
} PU_BAUD_RATE_E;

// ����λ
typedef enum PU_DATA_BIT {
    PU_DATA_BIT_CS5 = 0,
    PU_DATA_BIT_CS6,
    PU_DATA_BIT_CS7,
    PU_DATA_BIT_CS8,
    PU_DATA_BIT_MAX
} PU_DATA_BIT_E;

// У��λ
typedef enum PU_PARITY_BIT {
    PU_PARITY_BIT_NONE = 0,
    PU_PARITY_BIT_ODD,
    PU_PARITY_BIT_EVEN,
    PU_PARITY_BIT_MARK,
    PU_PARITY_BIT_SPACE,
    PU_PARITY_BIT_MAX
} PU_PARITY_BIT_E;

// ֹͣλ
typedef enum PU_STOP_BIT {
    PU_STOP_BIT_OFF = 0,
    PU_STOP_BIT_ON,
    PU_STOP_BIT_MAX
} PU_STOP_BIT_E;

// ��������������
typedef enum PU_FLOW_CONTROL {
    PU_FLOW_CONTROL_NONE = 0,
    PU_FLOW_CONTROL_SOFT,
    PU_FLOW_CONTROL_HARD,
    PU_FLOW_CONTROL_MAX
} PU_FLOW_CONTROL_E;

// ��̨����������
typedef enum PU_PTZ_DECODER_TYPE {
    PU_PTZ_DECODER_PELCO_P = 1,
    PU_PTZ_DECODER_PELCO_D,
    PU_PTZ_DECODER_YAAN,
    PU_PTZ_DECODER_SAMSUNG,
    PU_PTZ_DECODER_REDAPPLE_5052,
    PU_PTZ_DECODER_TAISHUO,
    PU_PTZ_DECODER_REDAPPLE_5051,
    PU_PTZ_DECODER_USER_DEF,
    PU_PTZ_DECODER_MAX
} PU_PTZ_DECODER_TYPE_E;

// ���������
typedef enum PU_PTZ_CONTROL_MODE {
    PU_PTZ_CONTROL_MODE_FORWARD = 1,
    PU_PTZ_CONTROL_MODE_BACK,
    PU_PTZ_CONTROL_MODE_MAX
} PU_PTZ_CONTROL_MODE_E;

// �澯����
typedef enum PU_ALARM_ACTION {
    PU_ALARM_ACTION_MOVE = 1,  // �澯�Ƴ�
    PU_ALARM_ACTION_HAPPEN,    // �澯����
    PU_ALARM_ACTION_MAX
} PU_ALARM_ACTION_E;

// ��̨����
typedef enum PU_PTZ_OPCODE {
    PU_PTZ_STOP = 1,          // ��ֹ̨ͣ,����para1��para2
    PU_PTZ_UP = 2,            // ��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_DOWN = 3,          // ��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_LEFT = 4,          // ��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_UP_LEFT = 5,       // ��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_DOWN_LEFT = 6,     // ��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_RIGHT = 7,         // ��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_UP_RIGHT = 8,      // ��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_DOWN_RIGHT = 9,    // ��̨����,para1�����˶�ģʽ(1���㶯��2������),para2������̨ת���ٶȣ���Χ1-10��
    PU_PTZ_AUTO = 10,         // ��̨�Զ�,����para1��para2
    PU_PTZ_PRESET_RUN = 11,   // Ԥ��λ����,para1����Ԥ��λ���,����para2
    PU_PTZ_CRUISE_RUN = 12,   // Ѳ���켣����,para1����Ѳ���켣���,����para2
    PU_PTZ_CRUISE_STOP = 13,  // Ѳ���켣ֹͣ,����para1��para2
    PU_PTZ_FLIP = 17,         // �ݲ�֧�֣���̨��ת180��,����para1��para2
    PU_PTZ_HOMING = 18,       // �ݲ�֧�֣���̨��λ,����para1��para2

    // ��ͷ����
    PU_PTZ_LENS_APERTURE_OPEN = 19,   // ��Ȧ�Ŵ�,����para1,����para2
    PU_PTZ_LENS_APERTURE_CLOSE = 20,  // ��Ȧ��С,����para1,����para2
    PU_PTZ_LENS_ZOOM_WIDE = 21,       // ��Ұ��Χ�Ŵ�,��ZOOM OUT,para1�̶�Ϊ����ģʽ(2),para2�����ٶ�
    PU_PTZ_LENS_ZOOM_TELESCOPE = 22,  // ��������,��Ұ��Χ��С,��ZOOM IN,para1�̶�Ϊ����ģʽ(2),para2�����ٶ�

    /************************************************************************/
    /* ���������°汾��ʹ�øò��� */
    PU_PTZ_LENS_ZOOM_IN = 21,   // �����������°汾��ʹ�øò���,��ʹ��PU_PTZ_LENS_ZOOM_WIDE����Χ�Ŵ�
    PU_PTZ_LENS_ZOOM_OUT = 22,  // �����������°汾��ʹ�øò���,��ʹ��PU_PTZ_LENS_ZOOM_TELESCOPE����Χ��С
    /************************************************************************/

    PU_PTZ_LENS_ZOOM_STOP = 23,   // ���Źر�
    PU_PTZ_LENS_FOCAL_NEAR = 24,  // �۽���,para1�̶�Ϊ����ģʽ(2),para2�����ٶȣ���Χ1-10��
    PU_PTZ_LENS_FOCAL_FAR = 25,   // �۽�Զ,para1�̶�Ϊ����ģʽ(2),para2�����ٶȣ���Χ1-10��
    PU_PTZ_LENS_FOCAL_STOP = 26,  // �۽��ر�
    PU_PTZ_AUX_OPEN = 27,         // �����豸��,para1�����豸����,����para2
    PU_PTZ_AUX_STOP = 28,         // �����豸�ر�,para1�����豸����,����para2

    PU_PTZ_HORIZONTAL_SCAN = 29,  // ˮƽɨ��,para1������,para2�����ٶȣ���Χ1-10��
    PU_PTZ_VERTICAL_SCAN = 30,    // ��ֱɨ��,para1����,para2�����ٶȣ���Χ1-10��

    PU_PTZ_MODE_SET_START = 31,     // �����켣��¼��ʼ
    PU_PTZ_MODE_SET_STOP = 32,      // �����켣��¼ֹͣ
    PU_PTZ_FAST_LOCATE = 33,        // 3d��λ
    PU_PTZ_FAST_RETURN = 34,        // 3d����
    PU_PTZ_REBOOT = 35,             // ���������
    PU_PTZ_RESTORE = 36,            // �����ָ�Ĭ������
    PU_PTZ_SET_LEFT_LIMIT = 37,     // ��������λ
    PU_PTZ_SET_RIGHT_LIMIT = 38,    // ��������λ
    PU_PTZ_MODE_CRUISE_START = 39,  // �����켣��ʼ para1����Ѳ���켣���,����para2
    PU_PTZ_MODE_CRUISE_STOP = 40,   // .�����켣ֹͣpara1����Ѳ���켣���,����para2
    PU_PTZ_FAST_MOVE = 41,          // ��ѡ���ٶ�λ.para1��ʾx���ꡢpara2��ʾy����

    PU_PTZ_HORIZONTAL_LIMIT_SCAN = 51,  // ˮƽ��λɨ��,para1�̶�Ϊ����ģʽ,para2�����ٶȣ���Χ1-10��
    PU_PTZ_LENS_AUTO_FOCAL = 52,        // �Զ��۽�
    PU_PTZ_GOTO_HOME = 53,              // ת����homeλ
    PU_PTZ_ONE_PUSH = 54,               // һ��ǹ�Խ�OnePush
    PTZ_VERTICAL_LIMIT_SCAN = 55,       // ��ֱ��λɨ��,para1�̶�Ϊ����ģʽ,para2�����ٶ�
    PTZ_SET_UP_LIMIT = 56,              // ��������λ
    PTZ_SET_DOWN_LIMIT = 57,            // ��������λ
	PTZ_LENS_RESET = 58,             // �۽���ͷ����

    PTZ_PRESET_ALARM_RUN = 92,      //�澯��Ԥ��λ���У�para1����Ԥ��λ��ţ�para2�����ͻָ���1��������0���ָ���
    PU_PTZ_CMD_MAX
} PU_PTZ_OPCODE_E;

// ��̨�˶�ģʽ
typedef enum PU_PTZ_MOTION_MODE {
    PU_PTZ_MOTION_MODE_BURST = 1,   // �㶯ģʽ
    PU_PTZ_MOTION_MODE_CONTINUOUS,  // ����ģʽ

    PU_PTZ_MOTION_MODE_MAX
} PU_PTZ_MOTION_MODE_E;

// ��̨Ԥ��λ����������
typedef enum PU_PTZ_PRESET_CMD {
    PU_PTZ_PRESET_SET = 1,  // ����Ԥ��λ
    PU_PTZ_PRESET_GET,      // ��ȡԤ��λ
    PU_PTZ_PRESET_CLR,      // ���Ԥ��λ
    PU_PTZ_PRESET_GOTO,     // ת��Ԥ��λ
    PU_PTZ_PRESET_MAX
} PU_PTZ_PRESET_CMD_E;

// Ѳ���켣����������
typedef enum PU_PTZ_CRUISE_TRACK {
    PU_PTZ_CRUISE_TRACK_SET = 1,  // ����Ѳ���켣
    PU_PTZ_CRUISE_TRACK_GET,      // ��ȡѲ���켣
    PU_PTZ_CRUISE_TRACK_CLR,      // ���Ѳ���켣
    PU_PTZ_CRUISE_TRACK_GOTO,     // ��̨Ѳ��
    PU_PTZ_CRUISE_TRACK_STOP,     // ֹͣѲ��
    PU_PTZ_CRUISE_TRACK_MAX
} PU_PTZ_CRUISE_TRACK_E;

typedef enum PU_OSD_DATE_TYPE {
    PU_YYYY_MM_DD = 0,  // YYYY-MM-DD
    PU_MM_DD_YYYY,      // MM-DD-YYYY
    PU_YYYY_MM_DD_CH,   // ��-��-��
    PU_MM_DD_YYYY_CH,   // ��-��-��
    PU_DD_MM_YYYY,      // DD-MM-YYYY
    PU_DD_MM_YYY_CH,    // dd��mm��yyyy��
    PU_YYYY_MM_DD_ONLY, // ֻ��ʾ������
    PU_HH_MM_SS_ONLY,   // ֻ��ʾʱ����
    PU_OSD_DATA_TYPE_MAX
} PU_OSD_DATE_TYPE_E;

// �澯����
typedef enum PU_ALARM_CATEGORY_TYPE {
    PU_ALARM_CATEGORY_TYPE_ALL = 0,  // ҵ����豸��澯
    PU_ALARM_CATEGORY_TYPE_DEVICE,   // �豸��澯
    PU_ALARM_CATEGORY_TYPE_SERVICE,  // ҵ����澯
    PU_ALARM_CATEGORY_TYPE_MAX
} PU_ALARM_CATEGORY_E;

// �澯����,ע��:��ö�����������ܵ�ALARM_TYPE_E������ȫһ��
typedef enum PU_ALARM_TYPE {
    PU_ALARM_TYPE_DI = 1,               // ����������
    PU_ALARM_TYPE_DISK_FULL,            // Ӳ�����澯
    PU_ALARM_TYPE_NO_SIGNAL,            // ����Ƶ�澯����Ƶ��ʧ��
    PU_ALARM_TYPE_MOVE_DECTION,         // �ƶ����澯
    PU_ALARM_TYPE_DISK_FAULT,           // Ӳ�̹���
    PU_ALARM_TYPE_SHIELD,               // �ڵ��澯�����������ڵ��澯
    PU_ALARM_TYPE_NETWORK_INTERRUPT,    // �����ж�
    PU_ALARM_TYPE_IP_ADDRESS_CONFLICT,  // IP��ͻ
    PU_ALARM_TYPE_TEMPERATURE,          // �¶ȸ澯
    PU_ALARM_TYPE_FACE_DETECTION,       // �������
    PU_ALARM_TYPE_INVADE,               // ���߼��
    PU_ALARM_TYPE_COUNT,                // Ŀ�����
    PU_ALARM_TYPE_DISTURB,              // ���ż��

    /* ���ܸ澯 */
    PU_ALARM_TYPE_TRIPWIRE = 14,   // Խ�߼��
    PU_ALARM_TYPE_INTRUSION = 15,  // ���ּ��
    PU_ALARM_TYPE_HOVER = 16,      // �ǻ����
    PU_ALARM_TYPE_LEGACY = 17,     // �������
    PU_ALARM_TYPE_REMOVE = 18,     // ���߼��

    PU_ALARM_TYPE_MEDIA_INTERRUPT = 30,  // ý�����ж�
    PU_ALARM_TYPE_DISK_EXCEPTION = 31,   // SD���쳣
    PU_ALARM_TYPE_AUDIO_EXCEPTION = 32,  // ��Ƶ�쳣���
    PU_ALARM_TYPE_STORAGE_FAIL,          // �����洢���澯
    PU_ALARM_TYPE_RECORDING_JOBSTATE,    // ¼������״̬�仯
    PU_ALARM_TYPE_DEV_TEMPE,             // �¶�оƬ����澯
    PU_ALARM_TYPE_LOG_WR,                // ��־��д�澯
    PU_ALARM_TYPE_PTZ_CONFIG_WR,         // PTZ��̨Э�����ø澯

    PU_ALARM_TYPE_FAN_PWR_BLOCKED = 38,   // �������Դ����ȶ�ת�澯
    PU_ALARM_TYPE_FAN_HEC_BLOCKED,        // ������������ȶ�ת�澯
    PU_ALARM_TYPE_SFP_TEMP_HIGH,          // ��ģ���¶ȹ��߸澯
    PU_ALARM_TYPE_SFP_TEMP_LOW,           // ��ģ���¶ȹ��͸澯
    PU_ALARM_TYPE_SFP_VOL_HIGH,           // ��ģ���ѹ���߸澯
    PU_ALARM_TYPE_SFP_VOL_LOW,            // ��ģ���ѹ���͸澯
    PU_ALARM_TYPE_SFP_BIAS_HIGH,          // ��ģ��ƫ�õ������߸澯
    PU_ALARM_TYPE_SFP_BIAS_LOW,           // ��ģ��ƫ�õ������͸澯
    PU_ALARM_TYPE_SFP_TX_PWR_HIGH,        // ��ģ�鷢�͹��ʹ��߸澯
    PU_ALARM_TYPE_SFP_TX_PWR_LOW,         // ��ģ�鷢�͹��ʹ��͸澯
    PU_ALARM_TYPE_SFP_RX_PWR_HIGH,        // ��ģ����չ��ʹ��߸澯
    PU_ALARM_TYPE_SFP_RX_PWR_LOW,         // ��ģ����չ��ʹ��͸澯
    PU_ALARM_TYPE_SFP_LASER_TEMP_HIGH,    // ��ģ��laser�¶ȹ��߸澯
    PU_ALARM_TYPE_SFP_LASER_TEMP_LOW,     // ��ģ��laser�¶ȹ��͸澯
    PU_ALARM_TYPE_SFP_TEC_CURRENT_HIGH,   // ��ģ��tec�������߸澯
    PU_ALARM_TYPE_SFP_TEC_CURRENT_LOW,    // ��ģ��tec�������͸澯
    PU_ALARM_TYPE_DISC_PULLOUT,           // Ӳ���Ƴ�
    PU_ALARM_TYPE_LIGHT_SENSOR_INCVALID,  // ����оƬʧЧ�澯
    PU_ALARM_TYPE_EXTERNAL_POWER_DOWN,    // �ⲿ��Դ����澯
    PU_ALARM_TYPE_WIPER_FAILURE_ALARM,    // ��ˢʧ�ܸ澯
    PU_ALARM_TYPE_SFP_NOT_EXIST,          // ��ģ�鲻��λ�澯
    PU_ALARM_TYPE_TYPE_PTOPT_HOR_FAIL,    // ˮƽ�������ʧ��
    PU_ALARM_TYPE_TYPE_PTOPT_VER_FAIL,    // ��ֱ�������ʧ��

    PU_ALARM_TYPE_ITS_RADAR_EXCEPTION_ALARM = 62,  // its�״��쳣�ĸ澯
    PU_ALARM_TYPE_ITS_IOCOIL_EXCEPTION_ALARM,      // its��IO��Ȧ�쳣�ĸ澯
    PU_ALARM_TYPE_ITS_485COIL_EXCEPTION_ALARM,     // its��485��Ȧ�쳣�ĸ澯
    PU_ALARM_TYPE_ITS_REDTOR_EXCEPTION_ALARM,      // its���̵Ƽ�����쳣�ĸ澯
    PU_ALARM_TYPE_LENS_FAILURE_ALARM,              // ��ͷPT����ʧЧ�澯

    /* Ӳ��ģ��澯����: ע�ⲻ�ܴ۸�����ֵ, ���ܳ��� 200 */
    PU_ALARM_TYPE_AUDIO_UP = 100,  // ��Ƶ����
    PU_ALARM_TYPE_AUDIO_DOWN,      // ��Ƶ����

    PU_ALARM_TYPE_ENTER,              // ���������
    PU_ALARM_TYPE_EXIT,               // �����뿪���
    PU_ALARM_TYPE_FASTMOVE,           // �����ƶ����
    PU_ALARM_TYPE_CPU_HIGHT,          // CPU���߸澯
    PU_ALARM_TYPE_MEM_HIGHT,          // �ڴ���߸澯
    PU_ALARM_TYPE_SCENECHANGE = 107,  // �������
    PU_ALARM_TYPE_AUTOTRACKING,       // �Զ�����
    PU_ALARM_TYPE_OUTOFFOCUS_DETECT,  // �齹���
    PU_ALARM_TYPE_CROWD_ANALYSIS,     // ��Ա�ۼ�

    PU_ALARM_TYPE_SHAKE_DIAGNOSIS,        // �������
    PU_ALARM_TYPE_FROZEN_DIAGNOSIS,       // ��Ƶ���涳��
    PU_ALARM_TYPE_SNOW_NOISE_DIAGNOSIS,   // ѩ���������
    PU_ALARM_TYPE_STRIPENOISE_DIAGNOSIS,  // �����������
    PU_ALARM_TYPE_BRIGHT_DIAGNOSIS,       // ����ʧ��
    PU_ALARM_TYPE_COLORCAST_DIAGNOSIS,    // ƫɫ���

    PU_ALARM_TYPE_CAR_DETECTION,  // ͣ�����
    PU_ALARM_TYPE_HUMAN_COUNT,    // ����ͳ��
    PU_ALARM_TYPE_FD_DL,          // 3559�������

    PU_ALARM_TYPE_QUEUE_DETECT = 121,       // �Ŷӳ���
    PU_ALARM_TYPE_CROWD_DENSITY_DETECT,     // ��Ⱥ�ܶ�
    PU_ALARM_TYPE_ILLEGAL_PARKING,          // Υͣ��
    PU_ALARM_TYPE_VLPR_TRAFFIC_CONGESTION,  // ��ͨӵ��
    PU_ALARM_TYPE_TRAFFIC_CONGESTION,       // ITS��ͨӵ��

    PU_ALARM_TYPE_FACE_RECOGNITION = 130,  // 3559����ʶ��
    
    PU_ALARM_TYPE_HBA_FIGHTING = 135,         // ���
    PU_ALARM_TYPE_HBA_CLIMBING,               // ����
    PU_ALARM_TYPE_HBA_FALL_DOWN,              // ����
    PU_ALARM_TYPE_HBA_RUNNING,                // �ܲ�
    PU_ALARM_TYPE_FIRE_DETECT,                //���
    PU_ALARM_TYPE_TEMPERATURE_CONTROL,        //�¿�
    
    PU_LPR_CAPTURE_RES = 200,         // ����ץ�Ľ��
    PU_MANUAL_LPR_CAPTURE_RES = 201,  // �ֶ�����ץ�Ľ��
    PU_AUTOTRANS_FACEPIC_RES = 202,             //���������Զ�����ͼƬ

    PU_ALARM_TYPE_HTTPS_CERT_EXPIRE = 300,    // https֤�鳬�ڸ澯
    PU_ALARM_TYPE_HTTPS_CERT_WILL_EXPIRE,     // https֤�鼴�����ڸ澯
    PU_ALARM_TYPE_DOT1X_CERT_EXPIRE,          // 802.1x֤�鳬�ڸ澯
    PU_ALARM_TYPE_DOT1X_CERT_WILL_EXPIRE,     // 802.1x֤�鼴�����ڸ澯
    PU_ALARM_TYPE_SDK_PWD_STILL_INITIAL_PWD,  // SDK����δ�޸�

    PU_AlARM_TYPE_PTZ_MOVE,                // genetec PTZ �ƶ�
    PU_ALARM_TYPE_SSH_OPEN = 306,          // SSH����
    PU_ALARM_TYPE_SDK_USR_LOCK = 307,      // SDK�û�������
    PU_ALARM_TYPE_WEB_USR_LOCK = 308,      // WEB�û�������
    PU_ALARM_TYPE_ONVIF_USR_LOCK = 309,    // ONVIF�û�������
    PU_ALARM_TYPE_GENETEC_USR_LOCK = 310,  // GENETEC�û�������

    PU_ALARM_TYPE_DOT1X_CA_CERT_EXPIRE,       // 802.1x CA֤�鳬�ڸ澯
    PU_ALARM_TYPE_DOT1X_CA_CERT_WILL_EXPIRE,  // 802.1x CA֤�鼴�����ڸ澯

    PU_ALARM_TYPE_WEB_PWD_EXPIRE,     // WEB���볬�ڸ澯
    PU_ALARM_TYPE_ATTITUDE_ABNORMAL,  // ��̬�쳣�澯����

    PU_ALARM_TYPE_VE_ILLEGAL_PARKING = 400,  // Υ��ͣ��
    PU_ALARM_TYPE_VE_ON_VEHICLE_LANE,        // ��ռ��
    PU_ALARM_TYPE_VE_ON_NONEVEHICLE_LANE,    // ��ռ��
    PU_ALARM_TYPE_VE_PRESSING_LINE,          // ѹ��
    PU_ALARM_TYPE_VE_WRONG_DIRECTION,        // ����
    // PU_ALARM_TYPE_VE_ABNORMAL_PLATE,            // �쳣���ƣ�ע�ⲻҪɾ��������Ҫ����ʱע�͵������滹Ҫ�ſ�
    PU_ALARM_TYPE_VE_REVERSE = 406,  // ����,�����쳣����û��ɾ����Ϊ��ö��ֵ�����ܱ���һ�£��˴�д��Ϊ406
    PU_ALARM_TYPE_VE_SHELTER_PLATE,  //�ڵ�����

    // �������
    PU_ALARM_TYPE_SLAVE_RTSP_KEEP_ALIVE_FAIL = 500,  // �ӻ�rtsp����ʧ��
    PU_ALARM_TYPE_SLAVE_STREAM_NORMAL = 506,         // �ӻ�rtsp������; ��Ŀ(����)�豸�ϡ������¼�

    PU_ALARM_TYPE_WIFI_ALARM = 550,             // wifi�쳣
    PU_ALARM_TYPE_UPDATE_ROLLBACK_ALARM = 560,  // �����汾ʧ�ܻ��˸澯

    PU_ALARM_TYPE_ITS_485STROBE_EXCEPTION_ALARM = 562,  // 485Ƶ���Ƹ澯
    PU_ALARM_TYPE_ALL,                                  // ���и澯
    PU_ALARM_TYPE_MAX                                   // Ԥ��
} PU_ALARM_TYPE_E;

// ƽ̨����(ƽ̨����)
typedef enum PU_PLATFORM_TYPE {
    PU_PLATFORM_TYPE_NVS = 1,     // NVSƽ̨
    PU_PLATFORM_TYPE_IVS = 2,     // IVSƽ̨
    PU_PLATFORM_TYPE_GBT,         // 28281ƽ̨
    PU_PLATFORM_TYPE_IVS_ENABLE,  // IVSƽ̨����ʹ��
    PU_PLATFORM_TYPE_GBT_ENABLE,  // 28281ƽ̨����ʹ��
    PU_PLATFORM_TYPE_SDK_ENABLE,  // SDKƽ̨��������ʹ��
    PU_PLATFORM_TYPE_OTHERS,
    PU_PLATFORM_TYPE_MAX
} PU_PLATFORM_TYPE_E;

typedef enum PU_SDK_PLATFORM_MODE_E {
    PU_SDK_PALTFORM_MODE_SINGEL = 1,  // ��������ģʽ
    PU_SDK_PLATFORM_MODE_DUAL,        // ˫������ģʽ
    PU_SDK_PLATFORM_MODE_MAX
} PU_SDK_PLATFORM_MODE_E;

typedef enum PU_CONNECT_TYPE {
    PU_CONNECT_TYPE_PWD = 0,
    PU_CONNECT_TYPE_SSL_PWD,
    PU_CONNECT_TYPE_MAX
} PU_CONNECT_TYPE_E;

// ��־����
typedef enum PU_LOG_TYPE {
    PU_LOG_TYPE_OPERATION = 1,  // ������־
    PU_LOG_TYPE_EXCEPT,         // �쳣��־
    PU_LOG_TYPE_ALARM,          // �澯��־
    PU_LOG_TYPE_HARD_ALARM,     // Ӳ����澯��־
    PU_LOG_TYPE_SOFTWAREINFO,   // ���롢B�汾����Ϣ��־
    PU_LOG_TYPE_MAX
} PU_LOG_TYPE_E;

// ���������Ͷ���

// �ֱ���ģʽ
typedef enum PU_DISRESOLUTION_MODE {
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
} PU_DISRESOLUTION_MODE_E;

// �˿�����
typedef enum PU_PORT_TYPE {
    PU_PORT_TYPE_HDMI = 0,
    PU_PORT_TYPE_VGA = 1,
    PU_PORT_TYPE_BNC = 2,
    PU_PORT_TYPE_DVI = 3,

    PU_PORT_TYPE_MAX
} PU_PORT_TYPE_E;

// �˿�ģʽ
typedef enum PU_PORT_MODE {
    PU_PORT_MODE_1 = 1,    // 1����
    PU_PORT_MODE_2 = 2,    // 2����
    PU_PORT_MODE_4 = 4,    // 4����
    PU_PORT_MODE_9 = 9,    // 9����
    PU_PORT_MODE_16 = 16,  // 16����

    PU_PORT_MODE_MAX
} PU_PORT_MODE_E;

// ֡��
typedef enum PU_FRAME_RATE {
    PU_FRAME_RATE_30 = 0,
    PU_FRAME_RATE_50,
    PU_FRAME_RATE_60
} PU_FRAME_RATE_E;

// ������������
typedef enum PU_ENCRYPT_TYPE {
    PU_ENCRYPT_TYPE_HUAWEI_VIDEO = 0,  // ʵ�л�Ϊ���������㷨,������Ƶ
    PU_ENCRYPT_TYPE_HUAWEI_AUDIO,      // ʵ�л�Ϊ���������㷨,������Ƶ
    PU_ENCRYPT_TYPE_HUAWEI_MUX,        // ʵ�л�Ϊ���������㷨,���ܸ�����
    PU_ENCRYPT_TYPE_NONE,              // ��ʵ����������
    PU_ENCRYPT_TYPE_MAX
} PU_ENCRYPT_TYPE_E;

// ��Ƶ�˿�����
typedef enum PU_AUDIO_PORT_TYPE {
    PU_AUDIO_PORT_TYPE_BNC_PLAY = 0,   // BNC�����˿�
    PU_AUDIO_PORT_TYPE_HDMI_PLAY = 1,  // HDMI�����˿�

    PU_AUDIO_PORT_TYPE_MAX
} PU_AUDIO_PORT_TYPE_E;

// ��Ƶ������
typedef enum PU_AUDIO_SAMPLERATE {
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
} PU_AUDIO_SAMPLERATE_E,
*LPPU_AUDIO_SAMPLERATE_E;

// G726�����ʽ������
typedef enum PU_AUDIO_G726_BPS {
    PU_AUDIO_G726_16K = 0, /* G726 16kbps, */
    PU_AUDIO_G726_24K,     /* G726 24kbps, */
    PU_AUDIO_G726_32K,     /* G726 32kbps, */
    PU_AUDIO_G726_40K,     /* G726 40kbps, */
    PU_AUDIO_G726_64K,     /* G726 64kbps, */
    PU_AUDIO_G726_96K,     /* G726 96kbps, */
    PU_AUDIO_G726_128K,    /* G726 128kbps, */
    PU_AUDIO_G726_160K,    /* G726 160kbps, */
    PU_AUDIO_G726_192K,    /* G726 192kbps, */
    PU_AUDIO_G726_224K,    /* G726 224kbps, */
    PU_AUDIO_G726_256K,    /* G726 256kbps, */
    PU_AUDIO_G726_288K,    /* G726 288kbps, */
    PU_AUDIO_G726_320K,    /* G726 320kbps, */
    PU_AUDIO_G726_352K,    /* G726 352kbps, */
    PU_AUDIO_G726_384K,    /* G726 384kbps, */
    PU_AUDIO_G726_416K,    /* G726 416kbps, */
    PU_AUDIO_G726_448K,    /* G726 448kbps, */
    PU_AUDIO_G726_480K,    /* G726 480kbps, */
    PU_AUDIO_G726_512K,    /* G726 512kbps, */
    PU_AUDIO_G726_48K,     /* G726 48kbps, */
    PU_AUDIO_G726_22K,     /* G726 22kbps, */
    PU_AUDIO_G726_MAX,
} PU_AUDIO_G726_BPS_E;

/* ��Ƶ��ҹģʽ */
typedef enum PU_VIDEO_DAYNIGHT_MODE {
    PU_VIDEO_DAYNIGHT_MODE_AUTO = 0,  // �Զ�ģʽ
    PU_VIDEO_DAYNIGHT_MODE_COLOR,     // ��ɫģʽ
    PU_VIDEO_DAYNIGHT_MODE_GRAY,      // �ڰ�ģʽ
    PU_VIDEO_DAYNIGHT_MODE_MAX
} PU_VIDEO_DAYNIGHT_MODE_E;

/* ͼ�������ת��ʽ */
typedef enum PU_VIDEO_MIRROR_MODE {
    PU_VIDEO_MIRROR_MODE_NORMAL = 0,  // ����ͼ��
    PU_VIDEO_MIRROR_MODE_MIRROR,      // ���Ҿ���
    PU_VIDEO_MIRROR_MODE_FLIP,        // ����
    PU_VIDEO_MIRROR_MODE_BOTH,        // ��������
    PU_VIDEO_MIRROR_MODE_MAX
} PU_VIDEO_MIRROR_MODE_E;

/* ����Ƶ�� */
typedef enum PU_VIDEO_FLICKER_MODE {
    PU_VIDEO_FLICKER_NONE = 0,  // �ر�
    PU_VIDEO_FLICKER_50HZ,      // 50HZ
    PU_IDEO_FLICKER_60HZ,       // 60HZ

    PU_VIDEO_FLICKER_MAX
} PU_VIDEO_FLICKER_MODE_E;

/* ����ģʽ */
typedef enum PU_DENOISE_MODE {
    DENOISE_NORMOL = 0,  // ��ͨģʽ
    DENOISE_CLOSE,       // �رս���
    DENOISE_EXPERT,      // ר��ģʽ

    DENOISE_MAX
} PU_DENOISE_MODE_E;

/* ���ģʽ */
typedef enum PU_VIDEO_AEMETERING_MODE {
    PU_VIDEO_AEMETERING_CENTER = 0,  // ���Ĳ��(��֧��)
    PU_VIDEO_AEMETERING_SPOT,        // ���ĵ���(��֧��)
    PU_VIDEO_AEMETERING_AVERAGE,     // ƽ�����
    PU_VIDEO_AEMETERING_BACKLIGHT,   // ������(��֧��)
    PU_VIDEO_AEMETERING_CLOSE,       // �ر�(��֧��)
    PU_VIDEO_AEMETERING_USER,        // �û��Զ���

    PU_VIDEO_AEMETERING_MAX
} PU_VIDEO_AEMETERING_MODE_E;

/* ��ͷ���� */
typedef enum PU_LENS_TYPE {
    PU_LENS_TYPE_SA = 0,  // Fuji lens(DV3.4x3.8SA-SA1L)
    PU_LENS_TYPE_SE       // Fuji lens(D8x7.8A-SE2N)
} PU_LENS_TYPE_E;

/* AE�ع�ģʽ */
typedef enum PU_AE_MODE {
    PU_AE_MODE_AUTO = 0,     // �Զ��ع⣬�Զ���Ȧ���桢�̶��Ŀ���ֵ
    PU_AE_MODE_MANUAL,       // �ֶ��ع�
    PU_AE_MODE_SHUTTER_PRI,  // ��������
    PU_AE_MODE_IRIS_PRI,     // ��Ȧ����
    PU_AE_MODE_LOW_NOISE,    // ��������
    PU_AE_MODE_FRAME_RATE,   // ֡������
    PU_AE_MODE_BRIGHT,       // ��������

    PU_AE_MODE_MAX
} PU_AE_MODE_E;

// ��̬ģʽ
typedef enum PU_WDR_SWITCH_MODE {
    PU_WDR_SWITCH_AUTO,    // �Զ�ģʽ
    PU_WDR_SWITCH_CLOSE,   // �ر�
    PU_WDR_SWITCH_MANUAL,  // �ֶ�ģʽ
    PU_WDR_SWITCH_MAX,
} PU_WDR_SWITCH_MODE_E;

/* ץ������ */
typedef enum PU_SNAPSHOT_TYPE {
    PU_SNAPSHOT_TYPE_MANUAL = 0,  // �ֶ�ץ��
    PU_SNAPSHOT_TYPE_ALARM,       // �澯ץ��
    PU_SNAPSHOT_TYPE_TIMER,       // ��ʱץ��
    PU_SNAPSHOT_TYPE_MANUAL_EX,   //
    PU_SNAPSHOT_TYPE_FACEDT,      // ����ץ��
    PU_SNAPSHOT_TYPE_ITGT,        // ���ܴ���
    PU_SNAPSHOT_TYPE_ITS,         // ITSץ��
    PU_SNAPSHOT_TYPE_VEHICLE,     // �����¼�����
    PU_SNAPSHOT_TYPE_MAX
} PU_SNAPSHOT_TYPE_E;

// ͼ�������ж���ͼƬ����
typedef enum PU_IMG_QUALITY_JUDGE_TYPE {
    PU_FACE_IMG,      // ����ͼƬ
    PU_MV_ATGATE_IMG  // ����ͼƬ
} PU_IMG_QUALITY_JUDGE_TYPE_E;

// ҵ������
typedef enum PU_BUSINESS_TYPE {
    PU_BUSINESS_REAL_VIDEO = 0,     // ʵʱ���
    PU_BUSINESS_AUDIO_TALK,         // �����Խ�
    PU_BUSINESS_AUDIO_BROADCAST,    // �����㲥
    PU_BUSINESS_RECORD_DOWNLOAD,    // ¼������
    PU_BUSINESS_RECORD_PLAY_BACK,   // ¼��ط�
    PU_BUSINESS_SNAPSHOT_DOWNLOAD,  // ͼƬ����

    PU_BUSINESS_TYPE_MAX
} PU_BUSINESS_TYPE_E;

// ��Ƶ���Ĵ�������
typedef enum PU_VIDEO_CODE_TYPE {
    PU_VIDEO_CODE_TYPE_ES,  // ES��
    PU_VIDEO_CODE_TYPE_PS,  // PS��
    PU_VIDEO_CODE_TYPE_TS,  // TS��
    PU_VIDEO_CODE_TYPE_MAX
} PU_VIDEO_CODE_TYPE_E;

typedef enum PU_RECORD_TYPE {
    PU_RECORD_TYPE_ALARM = 0,  // �澯¼��
    PU_RECORD_TYPE_MANUAL,     // �ֶ�¼��
    PU_RECORD_TYPE_TIMING,     // �ƻ�¼��
    PU_RECORD_METHOD_ADD,      // ��¼¼��
    PU_RECORD_METHOD_ALL,      // ��������¼��
    PU_RECORD_TYPE_MAX,
} PU_RECORD_TYPE_E;

/* Ӳ������ */
typedef enum PU_DISK_TYPE {
    PU_DISK_TYPE_IDE = 1,  // IDEӲ��
    PU_DISK_TYPE_SATA,     // ���нӿ�Ӳ��
    PU_DISK_TYPE_FLASH,    // ���棬��SD��CF

    PU_DISK_TYPE_UNKNOWN
} PU_DISK_TYPE_E;

/* ����ģʽ */
typedef enum PU_NOISE_REDUCTION_MODE {
    PU_NOISE_REDUCTION_CLOSE = 0,  // �ر�
    PU_NOISE_REDUCTION_NORMAL,     // ��ͨģʽ
    PU_NOISE_REDUCTION_EXPERT,     // ר��ģʽ

    PU_NOISE_REDUCTION_MAX
} PU_NOISE_REDUCTION_MODE_E;

typedef enum PU_FEC_PACKET_LOSS_RATIO {
    PU_FEC_PACKET_LOSS_RATIO_1 = 0, /**<  0: 1%���� */
    PU_FEC_PACKET_LOSS_RATIO_2 = 1, /**<  1: 2%���� */
    PU_FEC_PACKET_LOSS_RATIO_3 = 2, /**<  2: 3%���� */
    PU_FEC_PACKET_LOSS_RATIO_4 = 3, /**<  3: 4%���� */
    PU_FEC_PACKET_LOSS_RATIO_5 = 4, /**<  4: 5%���� */
    PU_FEC_PACKET_LOSS_RATIO_MAX
} PU_FEC_PACKET_LOSS_RATIO_E;

// SEC������
typedef enum PU_SEC_PACKET_LOSS_RATIO {
    PU_SEC_PACKET_LOSS_RATIO_1 = 0, /* 0: 4%���� */
    PU_SEC_PACKET_LOSS_RATIO_2 = 1, /* 1: 8%���� */
    PU_SEC_PACKET_LOSS_RATIO_3 = 2, /* 2: 12%���� */
    PU_SEC_PACKET_LOSS_RATIO_4 = 3, /* 3: 16%���� */
    PU_SEC_PACKET_LOSS_RATIO_5 = 4, /* 4: 20%���� */
    PU_SEC_PACKET_LOSS_RATIO_MAX
} PU_SEC_PACKET_LOSS_RATIO_E;

// ��ɫ
typedef enum PU_COLOR_TYPE {
    PU_COLOR_BLACK = 0,
    PU_COLOR_WHITE,
    PU_COLOR_MAX
} PU_COLOR_TYPE_E;

// ͸����
typedef enum PU_ALPHA_TYPE {
    PU_ALPHA_NONE = 0,
    PU_ALPHA_HALF,
    PU_ALPHA_ALL,
    PU_ALPHA_MAX
} PU_ALPHA_TYPE_E;

typedef enum PU_DSCP_TYPE {
    PU_DSCP_TYPE_MEDIA = 0,  // ý��DSCPֵ ������Ƶ����Ƶ
    PU_DSCP_TYPE_CMD,        // ����DSCPֵ �����澯
    PU_DSCP_TYPE_MAX
} PU_DSCP_TYPE_E;

/* �������������� */
typedef enum PU_IGT_AREA_ALARM_TYPE {
    PU_IGT_TYPE_INTRUSION = 0,  // ���ּ��
    PU_IGT_TYPE_HOVER,          // �ǻ����
    PU_IGT_TYPE_LEGACY,         // �������
    PU_IGT_TYPE_REMOVE,         // ���߼��
    PU_IGT_TYPE_ENTER,          // �������
    PU_IGT_TYPE_EXIT,           // �����뿪
    PU_IGT_TYPE_FASTMOVE,       // �����ƶ�
    PU_IGT_TYPE_MAX
} PU_IGT_AREA_ALARM_TYPE_E;

/* ���ܳ���ʹ�� */
typedef enum PU_IGT_FIELD_TYPE {
    PU_IGT_FIELD_LONGSHOT = 0,   // Զ��
    PU_IGT_FIELD_CLOSESHOT = 1,  // ����
    PU_IGT_FIELD_MAX
} PU_IGT_FIELD_TYPE_E;

/* ǰ��Ŀ��ߴ����� */
typedef enum PU_IGT_MINTARGET_SIZE {
    PU_IGT_TARGETSIZE_SMALL = 0,   // СĿ��
    PU_IGT_TARGETSIZE_MIDDLE = 1,  // ��Ŀ��
    PU_IGT_TARGETSIZE_BIG = 2,     // ��Ŀ��
    PU_IGT_TARGETSIZE_MAX
} PU_IGT_MINTARGET_SIZE_E;

/* ȥ��Ӱģʽ */
typedef enum PU_IGT_SHADOW_MODE {
    PU_IGT_SHADOW_WEAK = 0,    // ����Ӱ
    PU_IGT_SHADOW_COMMON = 1,  // ��ͨ��Ӱ
    PU_IGT_SHADOW_STRONG = 2,  // ǿ��Ӱ
    PU_IGT_SHADOW_MAX
} PU_IGT_SHADOW_MODE_E;

/* ���������� */
typedef enum PU_IGT_DETECT_SENS {
    PU_IGT_SENS_LOW = 0,     // ��������
    PU_IGT_SENS_MIDDLE = 1,  // ��������
    PU_IGT_SENS_HIGH = 2,    // ��������
    PU_IGT_SENS_LOWER = 3,   // ����������
    PU_IGT_SENS_LOWEST = 4,  // ���������
    PU_IGT_SENS_MAX
} PU_IGT_DETECT_SENS_E;

/* ����Ŀ��ʶ��ģʽ */
typedef enum PU_IGT_TARGET_MODE {
    PU_IGT_TARGETMODE_CENTRE = 0,  // ����
    PU_IGT_TARGETMODE_BOTTOM = 1,  // �ײ�
    PU_IGT_TARGETMODE_TOP = 2,     // ����
    PU_IGT_TARGETMODE_MAX
} PU_IGT_TARGET_MODE_E;

typedef enum PU_IRLIGHT_MODE {
    PU_IRLIGHT_MODE_ATUO = 0,  // �Զ�
    PU_IRLIGHT_MODE_MANUAL,    // �ֶ�

    PU_IRLIGHT_MODE_MAX
} PU_IRLIGHT_MODE_E;

typedef enum PU_IGT_OPT_TYPE {
    PU_IGT_OPT_TYPE_ADD = 0,  // ��������Ҫ��LPPU_IGT_TW_LINE_S��LPPU_IGT_AREA_S��������Ϣ
    PU_IGT_OPT_TYPE_MOD = 1,  // �޸ģ���Ҫ��LPPU_IGT_TW_LINE_S��LPPU_IGT_AREA_S��������Ϣ
    PU_IGT_OPT_TYPE_DEL = 2,  // ɾ����ֻ��Ҫ��LPPU_IGT_TW_LINE_S��LPPU_IGT_AREA_S��channelid��index
    PU_IGT_OPT_TYPE_MOV = 3,  /* �ƶ�����Ӱ��߻�����ʱ����ͼ��ֻ��Ҫ��LPPU_IGT_TW_LINE_S��LPPU_IGT_AREA_S��channelid��index�� */
    /* ������߻�������Ϣͬʱ����Ϊ���δ����� */
    PU_IGT_OPT_TYPE_MAX
} PU_IGT_OPT_TYPE_E;

typedef enum PU_ITGT_TYPE {
    PU_ITGT_TYPE_FACE_BODY_DETECT = 1,               // ���������� Face and body detection
    PU_ITGT_TYPE_FACE_RECOGTION,                     // ����ʶ��Facial recognition
    PU_ITGT_TYPE_OBJ_CLASSIFICATION,                 // �����˳��Ƽ��Object classification
    PU_ITGT_TYPE_ILLEG_PARK_DETECT,                  // Υͣ���Illegal parking detection
    // PU_ITGT_TYPE_NON_CHINA_VEH_RECOGTION,       //���⳵�Ƽ��Non-China vehicle recognition�����ձ�
    PU_ITGT_TYPE_VLPR_VEH_RECOGTION,                 // �����㷨���License plate algorithm recognition���ձຣ�⳵�ơ�����/ӡ�ᳵ�Ƽ��
    PU_ITGT_TYPE_SCENE_ADAPT_FOG,                    // ͸������ӦFog scene adaptive
    PU_ITGT_TYPE_SCENE_ADAPT_SPEED,                  // ��Ӱ����Ӧspeed scene adaptive
    PU_ITGT_TYPE_SCENE_ADAPT_BACK_LIGHT,             // ��������ӦBacklight scene adaptive
    PU_ITGT_TYPE_FACE_ATTRIBUTE,                     // �������� face attribute
    PU_ITGT_TYPE_BODY_ATTRIBUTE,                     // �������� body attribute
    PU_ITGT_TYPE_QUEUE_DETECT,                       // �ŶӼ�� queue detect
    PU_ITGT_TYPE_CROWD_DENSITY_DETECITON,            // ��Ⱥ�ܶȼ��  crowd density detection
    PU_ITGT_TYPE_CHINA_INDO_VEH_RECOGTION,           // ����/ӡ�ᳵ�� Chn & Indo vehicle recognition�����ձ�	
    PU_ITGT_TYPE_STRATEGY_MMC,                       // ���Эͬ multi-cooperation
    PU_ITGT_TYPE_STRATEGY_YTN,                       // һ��N����
    PU_ITGT_TYPE_STRATEGY_ONLINELEARNING,            // ������ѧϰ
    PU_ITGT_TYPE_STRATEGY_PORTTRAIT_VALUE_BASIC,     // �������
    PU_ITGT_TYPE_STRATEGY_PORTTRAIT_VALUE_ENHANCED,  // ������ǿ
    PU_ITGT_TYPE_STRATEGY_VEHICLE_VALUE_BASE,        // ��������
    PU_ITGT_TYPE_STRATEGY_VEHICLE_VALUE_enhanced,    // ������ǿ
    PU_ITGT_TYPE_STRATEGY_BEHAVIOR_ANALYSIS,         // ��Ϊ����̬��
    PU_GB35114SW,                                    // GB35114���SDK License
    PU_ITGT_TYPE_EBI_TYPE,                           // BEI�ܽ�ר�ÿ���
    PU_ITGT_TYPE_MAX
} PU_ITGT_TYPE_E;

/* ���ͳ���ģʽ */
typedef enum PU_TYPICAL_SCENE_MODE {
    PU_TYPICAL_SCENE_DEFAULT = 0, /* Ĭ�ϳ��� */
    PU_TYPICAL_SCENE_OUT_DOOR,    /* ���ⳡ�� */
    PU_TYPICAL_SCENE_IN_DOOR,     /* ���ڳ��� */
    PU_TYPICAL_SCENE_LOW_LIGHT,   /* ���ճ��� */
    PU_TYPICAL_SCENE_MOVE,        /* �˶����� */
    PU_TYPICAL_SCENE_BACKLIGHT,   /* ��ⳡ�� */

    PU_TYPICAL_SCENE_USER_1, /* �û��Զ��峡��1 */
    PU_TYPICAL_SCENE_USER_2, /* �û��Զ��峡��2 */
    PU_TYPICAL_SCENE_USER_3, /* �û��Զ��峡��3 */
    PU_TYPICAL_SCENE_USER_4, /* �û��Զ��峡��4 */
    PU_TYPICAL_SCENE_USER_5, /* �û��Զ��峡��5 */
    PU_TYPICAL_SCENE_USER_6, /* �û��Զ��峡��6 */
    PU_TYPICAL_SCENE_USER_7, /* �û��Զ��峡��7 */
    PU_TYPICAL_SCENE_USER_8, /* �û��Զ��峡��8 */

    PU_TYPICAL_SCENE_FOGGY = 14, /* ���쳡�� */
    PU_TYPICAL_SCENE_FACE = 15,  /* �������� */
    PU_TYPICAL_SCENE_NONE = 128, /* �����ó��� */
    PU_TYPICAL_SCENE_MAX
} PU_TYPICAL_SCENE_MODE_E;

/* �����ײ� */
typedef enum PU_STREAM_PROFILE_MODE {
    PU_STREAM_PROFILE_DEFAULT = 0,   /* Ĭ�� */
    PU_STREAM_PROFILE_HIGH_QUALITY,  /* ����Ʒ�� */
    PU_STREAM_PROFILE_BALANCED,      /* ����ƽ�� */
    PU_STREAM_PROFILE_LOW_BANDWIDTH, /* �ʹ��� */
    PU_STREAM_PROFILE_MOBILE_DEVICE, /* �ƶ��豸 */

    PU_STREAM_PROFILE_USER_1, /* �û��Զ��峡��1 */
    PU_STREAM_PROFILE_USER_2, /* �û��Զ��峡��2 */
    PU_STREAM_PROFILE_USER_3, /* �û��Զ��峡��3 */
    PU_STREAM_PROFILE_USER_4, /* �û��Զ��峡��4 */

    PU_STREAM_PROFILE_MAX
} PU_STREAM_PROFILE_E;

// ǰ��IPCģ��
typedef enum IPC_MODULE {
    IPC_WEB_MODULE = 0,  // WEBģ��
    IPC_SDK_MODULE = 1,  // SDKģ��
	IPC_WEBSDK_MODULE,  // WEB/SDKģ��
} PU_IPC_MODULE_E;

/* ISPͨ�ÿ��� */
typedef enum PU_COMMONMODE_SWITCH {
    MODE_OPEN = 0,  // ��ģʽ
    MODE_CLOSE,     // �ر�ģʽ
    MODE_AUTO,      // �Զ�ģʽ
    MODE_MANUAL,    // �ֶ�ģʽ

    MODE_MAX
} PU_COMMONMODE_SWITCH_E;

// ���Ų���
typedef enum PU_CAM_SHUTTER_MODE {
    PU_SHUTTER_MODE_1 = 0,  // ����ֵ1��
    PU_SHUTTER_MODE_2,      // ����ֵ1/2��
    PU_SHUTTER_MODE_4,      // ����ֵ1/4�룬��������
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
    PU_SHUTTER_MODE_3 = 28,  // ����ֵ1/3��

    PU_SHUTTER_MODE_MAX
} PU_CAM_SHUTTER_MODE_E;

/* GAMMA���� */
typedef struct PU_ISP_GAMMA {
    CHAR enGammaMode;   // GAMMAģʽ���μ�PU_COMMONMODE_SWITCH_E
    USHORT usStrength;  // GAMMA������0-100
} PU_ISP_GAMMA_S;

/* ISP�������� */
typedef enum PU_ISP_SCENE_TYPE {
    ISP_SCNEN_NORMAL = 0,       // ͨ�ó���
    ISP_SCENE_OBJECT,           // �͹۳����������ͼ�
    ISP_SCENE_INDOOR,           // ���ڳ���
    ISP_SCENE_OUTDOOR,          // ���ⳡ��
    ISP_SCENE_LOW_BRIGHT,       // ���ճ���
    ISP_SCENE_BACK_LIGHT,       // ���ⳡ��
    ISP_SCENE_VIRTUAL_BAYONET,  // ���⿨�ڳ���
    ISP_SCENE_FOG,              // ���쳡��
    ISP_SCENE_FACE,             // ����Ӧ�ó��� (��ǰ��������������, ���������Ƿ�����Ӧ��ģʽ�޸�
    ISP_SCENE_MAX
} PU_ISP_SCENE_TYPE_E;

// �������ݴ����ʽ
typedef enum PU_IGT_DATA_TYPE {
    XML_TYPE,
    META_TYPE,
} PU_IGT_DATA_TYPE_E;

// ���õ�����
typedef enum PU_EXT_LAMP_TYPE {
    PU_EXPOSURE_LAMP,      // ������
    PU_STROBE_LAMP,        // Ƶ����
    PU_YB_485_STROBE_LAMP, /* YB485Ƶ���� */
} PU_EXT_LAMP_TYPE_E;

// ���õƹ���ģʽ
typedef enum PU_EXT_LAMP_WORK_MODE {
    PU_WORK_MODE_OFF,   // ����
    PU_WORK_MODE_ON,    // ����
    PU_WORK_MODE_AUTO,  // �Զ�
    PU_WORK_MODE_TIME,  // ʱ��
} PU_EXT_LAMP_WORK_MODE_E;

// �ع�ƴ�����ƽ
typedef enum PU_EXP_LAMP_TRIG_LEVEL {
    PU_TRIG_HIGH_LEVEL,  // �ߵ�ƽ����
    PU_TRIG_LOW_LEVEL,   // �͵�ƽ����
} PU_EXP_LAMP_TRIG_LEVEL_E;

/* Ƶ����Ƶ�� */
typedef enum PU_EXT_LAMP_FREQ {
    PU_FREQ_50 = 0, /* 50hz */
    PU_FREQ_60,     /* 60hz */
    PU_FREQ_100,    /* 100hz */
    PU_FREQ_120,    /* 120hz */
} PU_EXT_LAMP_FREQ_E;

/* ��ҹģʽ */
typedef enum PU_VIDEO_BLACKWHITE_MODE {
    PU_VIDEO_MODE_AUTO = 0,  // �Զ�ģʽ
    PU_VIDEO_MODE_COLOR,     // ��ɫģʽ
    PU_VIDEO_MODE_GRAY,      // �ڰ�ģʽ
    PU_VIDEO_MODE_NEGART
} PU_VIDEO_BLACKWHITE_MODE_E;

// �����ײ���Ϣ
typedef struct PU_STREAMPROFILES_INFO {
    ULONG ulIndex;                                // ���
    CHAR szName[STREAMPROFILES_NAME_LEN];         // �ײ���������
    CHAR szDescrip[STREAMPROFILES_NAME_LEN * 2];  // ����
    CHAR szReserved[PU_RESERVE_LEN];              // Ԥ���ֶ�
} PU_STREAMPROFILES_INFO_S;

// �����ײ��б�
typedef struct PU_STREAMPROFILES_INFO_LIST {
    ULONG ulStreamProfilesNum;                                      // ���ײ͸���
    ULONG ulStreamId;                                               // ��ǰ����������ײ�
    PU_STREAMPROFILES_INFO_S szStreamProfile[STREAM_PROFILES_MAX];  // ��Ϣ�б�
    ULONG ulChannelId;                                              // ͨ���ţ����
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];                // Ԥ���ֶ�
} PU_STREAMPROFILES_INFO_LIST_S;

/* ȥ��ȼ� */
typedef enum PU_DEFOG_TYPR {
    PU_DEFOG_TYPE_CLOSE = 0,  // �ر�ȥ��
    PU_DEFOG_TYPE_LOW,        // �ͼ�ȥ��
    PU_DEFOG_TYPE_MIDDLING,   // �м�ȥ��
    PU_DEFOG_TYPE_HIGH,       // �߼�ȥ��
    PU_DEFOG_TYPE_AUTO,       // �Զ�ȥ��

    PU_DEFOG_TYPE_MAX
} PU_DEFOG_TYPE_E;

typedef enum PU_OPT_TYPE {
    PU_OPT_TYPE_ADD = 0,  // ����
    PU_OPT_TYPE_DEL = 1,  // ɾ��	
    PU_OPT_TYPE_MOD = 2,  // �޸�
    PU_OPT_TYPE_MAX
} PU_OPT_TYPE_E;

typedef enum PU_DEV_OPT_TYPE {
    PU_DEV_OPT_TYPE_REBOOT = 0,  // ����
    PU_DEV_OPT_TYPE_FORMAT = 1,  // ��ʽ������
    PU_DEV_OPT_TYPE_MAX
} PU_DEV_OPT_TYPE_E;

/* SNMP�汾 */
typedef enum PU_SNMP_VERSION_TYPE {
    PU_SNMP_VERSION_V1 = 0,
    PU_SNMP_VERSION_V2C,
    PU_SNMP_VERSION_V3,

    PU_SNMP_VERSION_MAX
} PU_SNMP_VERSION_TYPE_E;

/* SNMP v1/v2c�������� */
typedef enum PU_SNMP_COMMUNITY_ATTR {
    PU_SNMP_COMMUNITY_READONLY = 0,
    PU_SNMP_COMMUNITY_READWRITE,

    PU_SNMP_COMMUNITY_MAX
} PU_SNMP_COMMUNITY_ATTR_E;

/* SNMP v3 �û���ȫ���� */
typedef enum PU_SNMPV3_SECURITY_LEVEL {
    PU_SNMPV3_SECURITY_NOAUTH = 0,  // δ����Ȩ
    PU_SNMPV3_SECURITY_AUTH,        // ��Ȩ
    PU_SNMPV3_SECURITY_PRIV,        // ˽����Կ������Ȩ

    PU_SNMPV3_SECURITY_MAX
} PU_SNMPV3_SECURITY_LEVEL_E;

/* SNMP v3 Pwd��֤Э�� */
typedef enum PU_SNMPV3_AUTH_PROTOCOL {
    PU_SNMPV3_AUTH_MD5 = 0,
    PU_SNMPV3_AUTH_SHA,
    PU_SNMPV3_AUTH_NONE,

    PU_SNMPV3_AUTH_MAX
} PU_SNMPV3_AUTH_PROTOCOL_E;

/* SNMP v3 ˽����ԿЭ�� */
typedef enum PU_SNMPV3_PRIV_PROTOCOL {
    PU_SNMPV3_PRIV_DES = 0,
    PU_SNMPV3_PRIV_AES,
    PU_SNMPV3_PRIV_NONE,

    PU_SNMPV3_PRIV_MAX
} PU_SNMPV3_PRIV_PROTOCOL_E;

/********* 802.1x *********/
/* EAPOL�汾�� */
typedef enum PU_DOT1X_EAPOL_VERSION {
    PU_DOT1X_EAPOL_VERSION_1 = 1,
    PU_DOT1X_EAPOL_VERSION_2,

    PU_DOT1X_EAPOL_VERSION_MAX
} PU_DOT1X_EAPOL_VERSION_E;

/********* ����λ��ȫ�� *********/
typedef enum PU_GUARD_POINT_TYPE {
    PU_GUARD_POINT_PRESET,        // Ԥ��λ
    PU_GUARD_POINT_CRUISE,        // Ѳ���켣
    PU_GUARD_POINT_USER_DEFINED,  // ����ɨ��
    PU_GUARD_POINT_HORIZONTAL,    // ˮƽɨ��
    PU_GUARD_POINT_FRAME,         // ֡ɨ��
    PU_GUARD_POINT_RANDOM,        // ���ɨ��
    PU_GUARD_POINT_PANORAMA,      // ȫ��ɨ��
    PU_GUARD_POINT_VERTICAL,      // ��ֱɨ��

    PU_GUARD_POINT_MAX
} PU_GUARD_POINT_TYPE_E;

typedef enum PU_PTZ_DIRECTION {
    PU_PTZ_DIRECTION_UP,     // ��
    PU_PTZ_DIRECTION_DOWN,   // ��
    PU_PTZ_DIRECTION_LEFT,   // ��
    PU_PTZ_DIRECTION_RIGHT,  // ��

    PU_PTZ_DIRECTION_MAX
} PU_PTZ_DIRECTION_E;

typedef enum PU_PTZ_AUX_MODE {
    PU_AUX_MODE_PROTOCOL = 0,          // ��ˢЭ��ģʽ
    PU_AUX_MODE_ALARMOUT = 1,          // ���������ģʽ
    PU_AUX_MODE_TORRENTIAL_RAIN = 2,   // ��ˢ����ģʽ
    PU_AUX_MODE_MODERATE_RAIN = 3,     // ��ˢ����ģʽ
    PU_AUX_MODE_BRUSH_FIVE_TIMES = 4,  // ��ˢ��ˢ5��
    PU_AUX_MODE_MAX
} PU_PTZ_AUX_MODE_E;

typedef enum PU_WEB_HTTP_MODE {
    PU_WEB_HTTPS_HTTP = 0,  // ֧��https & http
    PU_WEB_HTTPS_ONLY = 1,  // ֻ֧��https
    PU_WEB_HTTP_MAX,
} PU_WEB_HTTP_MODE_E;

// web������Ч�ڲ���
typedef struct PU_WEB_PWD_PERIOD_PARA {
    ULONG ulChannelID;                                // Ԥ��ͨ��ID
    CHAR szUsrName[PU_CLIENT_USERNAME_LEN];           // �����û��û���
    CHAR szModifiedUserName[PU_CLIENT_USERNAME_LEN];  // ���޸ĵ��û��û���
    ULONG ulPwdPeriod;                                // ������Ч��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_WEB_PWD_PERIOD_PARA_S;

// ͨ�������ȡ��Կ�ļ�
typedef struct PU_PWD_RESET_OPTAIN
{
	CHAR     *pszKeyFilePath;               //���ر�����Կ�ļ�·��
    UINT     uOprType;                      // �������ͣ�0����ȡ��ǰ��Կ��1����������Կ
    CHAR     szWebUserPwd[PU_PASSWORD_LEN];    // Web admin�û�����
	CHAR     szReserved[PU_RESERVE_LEN];
}PU_PWD_RESET_OPTAIN_S;

// ͨ����Կ�������� 
typedef struct PU_PWD_RESET_WORK
{
	CHAR*                  pszKeyFilePath;				//�����ϴ���Կ�ļ�·��
    PU_IPC_MODULE_E        enDstModule;					// Ҫ�޸ĵ�ģ�����ƣ�0��WEB��1��SDK��2��WEB & SDK
	CHAR szModifiedWebPwd[PU_PASSWORD_LEN];				// WEB admin�û�����
	CHAR szModifiedSDKPwd[PU_PASSWORD_LEN];				// SDK admin�û�����
	CHAR                   szLoginIP[PU_IP4_ADDR_LEN];	// IPC IP addr				
	CHAR                   szReserved[PU_RESERVE_EX_LEN];
}PU_PWD_RESET_WORK_S;

// �û�����
typedef enum PU_USER_TYPE {
    PU_USER_TYPE_SYSTEM_ADMIN = 0,   // ����Ա
    PU_USER_TYPE_ADVANCED_OPERATOR,  // �߼�����Ա
    PU_USER_TYPE_COMMON_OPERATOR,    // һ�����Ա
    PU_USER_TYPE_MAX
} PU_USER_TYPE_E;

// AF�Խ�ģʽ
typedef enum PU_FOCUS_MODE {
    PU_FOCUS_MODE_AUTO = 0,     // �Զ��Խ�ģʽ
    PU_FOCUS_MODE_MANUAL = 1,   // �ֶ��Խ�ģʽ
    PU_FOCUS_MODE_TRIGGER = 2,  // ���Զ��Խ�ģʽ

    PU_FOCUS_MODE_MAX
} PU_FOCUS_MODE_E;

typedef enum PU_CHAR_ENCODE_TYPE {
    PU_CHAR_ENCODE_ANSI = 0,   // ANSI����
    PU_CHAR_ENCODE_UTF_8 = 1,  // utf-8����

    PU_CHAR_ENCODE_MAX,
} PU_CHAR_ENCODE_TYPE_E;

/* ��ƽ��ģʽ */
typedef enum PU_CAM_WB_MODE {
    PU_WB_MODE_AUTO = 0,                // �Զ�    (�����Ƚ��ȶ���ɫ������)
    PU_WB_MODE_ATW,                     // �Զ�����  (��ƽ�����ĵط�)
    PU_WB_MODE_INDOOR,                  // ����
    PU_WB_MODE_OUTDOOR,                 // ����
    PU_WB_MODE_ONEPUSH_TRIGGER,         // һ������
    PU_WB_MODE_MANUAL,                  // �ֶ�
    PU_WB_MODE_OUTDOOR_AUTO,            // �����Զ�
    PU_WB_MODE_SODIUM_VAPOR_LAMP_AUTO,  // �Ƶ��Զ�
    PU_WB_MODE_SODIUM_VAPOR_LAMP,       // �Ƶƹ̶�
    PU_WB_MODE_MERCURE_VAPOR_LAMP,      // ��ˮ����
    PU_WB_MODE_FLUO_4200k,              // 4200k
    PU_WB_MODE_FLUORESCENTLAMP1,        // �չ��1 ��2500~3500k��
    PU_WB_MODE_FLUORESCENTLAMP2,        // �չ��2 ��3500~4500k��
    PU_WB_MODE_INCANDESCENTLAMP,        // �׳�� 2700~2900K
    PU_WB_MODE_SUNLIGHT,                // ̫����

    PU_WB_MODE_MAX,
} PU_CAM_WB_MODE_E;

/* ��̬ģʽ */
typedef enum PU_VIDEO_WD_MODE {
    PU_WD_MODE_AUTO_WDR = 0,    // ������̬
    PU_WD_MODE_AUTO_ADWDR,      // ������ɫ���֣���̬������10db
    PU_WD_MODE_AUTO_CNT,        // ��̬��һ��ͼ�񹹳ɣ�ͼ����
    PU_WD_MODE_AUTO_WDR_CNT,    // ͨ���Ա�ƫ�������ӿ�̬����
    PU_WD_MODE_AUTO_ADWDR_CNT,  // �ڶԱ�ƫ�ƵĻ�����������10db
    PU_WD_MODE_RATIOFIX,        // ���ع�����ٶȹ̶������ñ�����ȷ�����ع�
    PU_WD_MODE_HISTOGRAM,       // ����ֱ��ͼ�����������͹���
    PU_WD_MODE_OFF_MODE,        // TIоƬר�ã��ر�
    PU_WD_MODE_FRAMESWITCH,     // TIоƬר�ã�֡�л�
    PU_WD_MODE_STATIC_CHECK,    // TIоƬר�ã���̬ģʽ
    PU_WD_MODE_DYNAMIC_CHECK,   // TIоƬר�ã���̬ģʽ

    PU_WD_MODE_MAX
} PU_VIDEO_WD_MODE_E;

/* ��ҹģʽ */
typedef enum PU_IRC_MODE {
    PU_IRC_MODE_COLOR = 0,  // ��ɫģʽ
    PU_IRC_MODE_GRAY,       // �ڰ�ģʽ
    PU_IRC_MODE_AUTO,       // �Զ�ģʽ

    PU_IRC_MODE_MAX
} PU_IRC_MODE_E;

/* ��ҹģʽ������ʽ */
typedef enum PU_IRC_TRIGGER_MODE {
    PU_IRC_CAM_TRIGGER = 0,  // ��о����
    PU_IRC_LUM_TRIGGER,      // ��������,Ĭ�Ϲ�������
    PU_IRC_SWITCH_TRIGGER,   // �ⲿ�澯���ش���
    PU_IRC_TRIGGER_MAX
} PU_IRC_TRIGGER_MODE_E;

/* �������� */
typedef enum PU_GAIN_TYPE {
    PU_GAIN_TYPE_AUTO = 0,  // �Զ�����
    PU_GAIN_TYPE_DIGITAL,   // ��������
    PU_GAIN_TYPE_ANALOG,    // ģ���ź�

    PU_GAIN_TYPE_MAX
} PU_GAIN_TYPE_E;

// ��Ȧ����
typedef enum PU_IRIS_VALUE {
    IRIS_VALUE_1_2 = 0,
    IRIS_VALUE_1_4,
    IRIS_VALUE_1_6,  // ��ȦֵΪF1.6
    IRIS_VALUE_2_0,  // ��ȦֵΪF2.0 ��������
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
    IRIS_VALUE_CLOSE,  // ��Ȧ�ر�

    IRIS_VALUE_MAX
} PU_IRIS_VALUE_E;

// ��С�۽�����(��λmm)
typedef enum PU_MIN_FOCUS {
    PU_MIN_FOCUS_10 = 10,  // 1cm
    PU_MIN_FOCUS_100 = 100,
    PU_MIN_FOCUS_300 = 300,
    PU_MIN_FOCUS_500 = 500,
    PU_MIN_FOCUS_1000 = 1000,  // 1m
    PU_MIN_FOCUS_1500 = 1500,
    PU_MIN_FOCUS_2000 = 2000,
    PU_MIN_FOCUS_3000 = 3000,
    PU_MIN_FOCUS_5000 = 5000,
    PU_MIN_FOCUS_6000 = 6000,
    PU_MIN_FOCUS_10000 = 10000,  // 10m
    PU_MIN_FOCUS_20000 = 20000,
    PU_MIN_FOCUS_50000 = 50000,
    PU_MIN_FOCUS_100000 = 100000,  // 100m

    PU_MIN_FOCUS_MAX
} PU_MIN_FOCUS_E;

typedef enum PU_IRIS_TYPE {
    PU_IRIS_TYPE_DC = 0,  // DC��Ȧ
    PU_IRIS_TYPE_P_IRIS,  // P-iris��Ȧ
    PU_IRIS_TYPE_MANUAL,  // �ֶ�
    PU_IRIS_TYPE_BUTT,
} PU_IRIS_TYPE_E;
/* ��Ƶ�ɼ�֡��ʽ */
typedef enum PU_FRAMERATE_FORMAT {
    PU_FRAME_RATE_25F = 1,  // 25֡
    PU_FRAME_RATE_30F,      // 30֡
    PU_FRAME_RATE_50F,      // 50֡
    PU_FRAME_RATE_60F,      // 60֡
	PU_FRAME_RATE_20F,      // 20֡
    PU_FRAME_RATE_MAX,
} PU_FRAMERATE_FORMAT_E;
/* ���ײͲ��� */
typedef enum PU_STREAM_MANIPULATE_TYPE {
    PU_STREAM_MANIPULATE_ADD = 0,  // ����
    PU_STREAM_MANIPULATE_DELETE,   // ɾ��
    PU_STREAM_MANIPULATE_MODIFY,   // �޸�
    PU_STREAM_MANIPULATE_MAX
} PU_STREAM_MANIPULATE_TYPE_E;

// IP��ַ����Э��
typedef enum PU_IP_PROTOCOL_TYPE {
    PU_IP_PROTOCOL_TYPE_UDP = 0,  // UDPЭ��
    PU_IP_PROTOCOL_TYPE_TCP,      // TCPЭ��
    PU_IP_PROTOCOL_TYPE_ICMP,     // ICMPЭ��
    PU_IP_PROTOCOL_TYPE_ALL,      // ����Э��
    PU_IP_PROTOCOL_TYPE_MAX
} PU_IP_PROTOCOL_TYPE_E;

// IP���˲���
typedef enum PU_IP_FILTER_STRATEGY {
    PU_IP_FILTER_STRATEGY_ALLOW = 0,  // ��������ʽ
    PU_IP_FILTER_STRATEGY_DENY,       // ��������ʽ
    PU_IP_FILTER_STRATEGY_MAX
} PU_IP_FILTER_STRATEGY_E;

/* 802.1x EAP-TLS֤���ϴ����� */
typedef enum PU_DOT1X_TLS_CERT_UPLOAD_TYPE {
    PU_DOT1X_TLS_CA_CERT_UPLOAD_TYPE = 0,
    PU_DOT1X_TLS_CLIENT_CERT_UPLOAD_TYPE,

    PU_DOT1X_TLS_CERT_UPLOAD_TYPE_MAX
} PU_DOT1X_TLS_CERT_UPLOAD_TYPE_E;

/* SDK -TLS֤���ϴ����� */
typedef enum PU_SDK_TLS_CERT_UPLOAD_TYPE {
    PU_SDK_TLS_CA_CERT_UPLOAD_TYPE = 0,
    PU_SDK_TLS_CLIENT_CERT_UPLOAD_TYPE,

    PU_SDK_TLS_CERT_UPLOAD_TYPE_MAX
} PU_SDK_TLS_CERT_UPLOAD_TYPE_E;

/* ������������ */
typedef enum PU_IGT_BG_UPDATE {
    PU_BGUPDATE_LOW = 0,
    PU_BGUPDATE_MID,
    PU_BGUPDATE_HIGH,

    PU_BGUPDATE_MAX
} PU_IGT_BG_UPDATE_E;

typedef enum PU_IGT_OBJ_TRACK {
    PU_OBJTRACK_LOW = 0,
    PU_OBJTRACK_MID,
    PU_OBJTRACK_HIGH,

    PU_OBJTRACK_MAX,
} PU_IGT_OBJ_TRACK_E;

/* ץ��ͼƬ��ʽ */
typedef enum PU_SNAPSHOT_FORMAT {
    PU_SNAPSHOT_FORMAT_BMP = 0,
    PU_SNAPSHOT_FORMAT_JPEG
} PU_SNAPSHOT_FORMAT_E;

/* �ϴ����� */
typedef enum PU_FTP_UPLOAD_PROTOCOL_TYPE {
    PU_FTP_UPLOAD_PROTOCOL_TYPE_FTP = 0,
    PU_FTP_UPLOAD_PROTOCOL_TYPE_SFTP,

    FTP_UPLOAD_PROTOCOL_TYPE_MAX
} PU_FTP_UPLOAD_PROTOCOL_TYPE_E;

/* Ŀ¼�ṹ */
typedef enum PU_FTP_UPLOAD_DIR_TYPE {
    PU_FTP_UPLOAD_DIR_TYPE_ROOT_DIR = 0,  // �ϴ�����Ŀ¼
    PU_FTP_UPLOAD_DIR_TYPE_FIRST_DIR,     // �ϴ���һ��Ŀ¼
    PU_FTP_UPLOAD_DIR_TYPE_SECOND_DIR,    // �ϴ�������Ŀ¼
    PU_FTP_UPLOAD_DIR_TYPE_THIRD_DIR,     // �ϴ�������Ŀ¼
    PU_FTP_UPLOAD_DIR_TYPE_FOURTH_DIR,    // �ϴ����ļ�Ŀ¼
    FTP_UPLOAD_DIR_TYPE_MAX
} PU_FTP_UPLOAD_DIR_TYPE_E;

/* һ��Ŀ¼���� */
typedef enum PU_FTP_UPLOAD_FIRST_DIR_TYPE {
    PU_FTP_UPLOAD_FIRST_DIR_TYPE_IP = 0,  // һ��Ŀ¼Ϊ�豸IP
    PU_FTP_UPLOAD_FIRST_DIR_TYPE_SELF,    // һ��Ŀ¼Ϊ�Զ���

    FTP_UPLOAD_FIRST_DIR_TYPE_MAX
} PU_FTP_UPLOAD_FIRST_DIR_TYPE_E;

/* ����Ŀ¼���� */
typedef enum PU_FTP_UPLOAD_SECOND_DIR_TYPE {
    PU_FTP_UPLOAD_SECOND_DIR_TYPE_CHANNEL = 0,  // ����Ŀ¼Ϊͨ����
    PU_FTP_UPLOAD_SECOND_DIR_TYPE_SELF,         // ����Ŀ¼Ϊ�Զ���

    PU_FTP_UPLOAD_SECOND_DIR_TYPE_MAX
} PU_FTP_UPLOAD_SECOND_DIR_TYPE_E;

/* �ϴ��ļ��������� */
typedef enum PU_FTP_UPLOAD_FILE_NAMING_RULE {
    PU_FTP_UPLOAD_FILE_NAMING_RULE_DATE = 0,  // ��ʱ������

    PU_FTP_UPLOAD_FILE_NAMING_RULE_MAX
} PU_FTP_UPLOAD_FILE_NAMING_RULE_E;

// �䱶�佹��������
typedef enum PU_CamControl {
    PU_CAM_CONTROL_UP = 0,
    PU_CAM_CONTROL_DOWN,
    PU_CAM_CONTROL_STOP
} PU_CAMCTRL_E;

typedef enum PU_CACHERECORD {
    PU_RECORD_CLOSE = 0,
    PU_RECORD_OFFLINE,
    PU_RECORD_MAX
} PU_CACHERECORD_E;

// OSDI��������
typedef enum PU_OSDI_OPTYPE {
    PU_OSDI_AREA_ADD = 0,         // ����OSDI����
    PU_OSDI_AREA_DEL = 1,         // ɾ��OSDI����
    PU_OSDI_AREA_MOD = 2,         // �޸�OSDI����
    PU_OSDI_AREA_ENABLE = 3,      // ʹ��OSDI����
    PU_OSDI_MOVE_TO_AREA = 4,     // �ƶ���ĳ��OSDI����
    PU_OSDI_BUSINESS_ENABLE = 5,  // OSDI�ܿ���ʹ��
    PU_OSDI_GET_CUR_CONFIG = 6,   // ��ȡ��ǰOSDI����
} PU_OSDI_OPTYPE_E;

// ץ��ͼƬ����
typedef enum PU_SNAPSHOT_QUALITY {
    PU_QUAILTY_BEST = 0,
    PU_QUAILTY_MORE_BETTER,
    PU_QUAILTY_BETTER,
    PU_QUAILTY_ORDINARY,
    PU_QUAILTY_LOW,
    PU_QUAILTY_WORST,
    PU_QUAILTY_MAX
} PU_SNAPSHOT_QUALITY_E;

// ��������ϵ��
typedef enum PU_TS_COEFFICIENT {
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
} PU_TS_COEFFICIENT_E;

// ����ʱʵʩ��ʽ
typedef enum PU_DST_TYPE {
    DST_WEEK_WAY = 0,
    DST_DATE_WAY = 1,
    DST_TYPE_MAX = 2,
} PU_DST_TYPE_E;

// ����ʱƫ����
typedef enum PU_DST_OFFSET {
    OFFSET_NONE = 0,
    OFFSET_30_MIN = 30,
    OFFSET_60_MIN = 60,
    OFFSET_90_MIN = 90,
    OFFSET_120_MIN = 120,
} PU_DST_OFFSET_E;

// ONVIF��Ȩ����
typedef enum PU_ONVIF_AUTH_TYPE {
    AUTH_TYPE_DIGGEST = 0,            // ��֧��Digest��֤
    AUTH_TYPE_DIGGEST_AND_WSSE = 1,   // ͬʱ֧��Digest��֤��WSSE��֤��Digest��֤����
    AUTH_TYPE_NONE = 2,               // ����Ȩ
    AUTH_TYPE_WSSE = 3,               // ��֧��WSSE��֤
    AUTH_TYPE_DIGEST_SHA256,          // ֧��SHA256�㷨��Digest��֤
    AUTH_TYPE_DIGEST_MD5_AND_SHA256,  // ֧��MD5��SHA256�㷨��Digest��֤
    AUTH_TYPE_MAX,
} PU_ONVIF_AUTH_TYPE_E;

// ����Э������
typedef enum PU_TRANS_PROTOCOL_TYPE {
    HTTP_ONLY = 0,
    HTTPS_ONLY,
    HTTP_AND_HTTPS,
} PU_TRANS_PROTOCOL_TYPE_E;

// onvif����Э�����
typedef struct PU_ONVIF_TRANS_PROTOCOL_TYPE {
    PU_TRANS_PROTOCOL_TYPE_E enTransProtocolType;
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_ONVIF_TRANS_PROTOCOL_TYPE_S;

// rest��֤��ʽ
typedef enum PU_REST_AUTHORIZATION_TYPE {
    PU_REST_AUTHORIZATION_DIGEST_MD5,            // digest with algorithm MD5
    PU_REST_AUTHORIZATION_DIGEST_SHA256,         // digest with algorithm SHA256
    PU_REST_AUTHORIZATION_DIGEST_MD5_AND_SHA256  // support MD5 and SHA256
} PU_REST_AUTHORIZATION_TYPE_E;

// rest����Э�����
typedef struct PU_REST_SUPPORT_PROTOCOL_PARAM {
    PU_TRANS_PROTOCOL_TYPE_E enRestProtocol;
    PU_REST_AUTHORIZATION_TYPE_E enRestAuthType;
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_REST_SUPPORT_PROTOCOL_PARAM_S;

// ������ɫ
typedef enum PU_LPR_PLATE_COLOR {
    PU_LPR_LC_UNKNOWN = 0,         // δ֪
    PU_LPR_LC_BLUE = 1,            // ��ɫ
    PU_LPR_LC_YELLOW = 2,          // ��ɫ
    PU_LPR_LC_WHITE = 3,           // ��ɫ
    PU_LPR_LC_BLACK = 4,           // ��ɫ
    PU_LPR_LC_GREEN = 5,           // ��ɫ
    PU_LPR_LC_GRADIENT_GREEN = 6,  // �����̵׺���
    PU_LPR_LC_YELLOW_GREEN = 7,    // ����˫ƴ�׺���
    PU_LPR_LC_RED_WHITE = 8,       // ��װ���
    PU_LPR_LC_WHITE_RED = 9,       // �׵׺���
    PU_LPR_LC_BLUE_WHITE = 10,     // ���װ���
    PU_LPR_LC_WHITE_BLUE = 11,     // �׵�����
    PU_LPR_LC_WHITE_YELLOW = 12,   // �׵׻���
    PU_LPR_LC_WHITE_GREEN = 13,    // �׵�����
    PU_LPR_LC_WHITE_SILVER = 14,   // �׵׻���
    PU_LPR_LC_SILVER_BLACK = 15,   // �ҵ׺���
} PU_PLATE_COLOR_E;

// ��������
typedef enum PU_LPR_PLATE_TYPE {
    PU_LPR_PLT_UNKNOWN = 0,       // δ֪����
    PU_LPR_PLT_NORMBLUE = 1,      // ��ͨ����
    PU_LPR_PLT_NORMBLACK = 2,     // ��ͨ����
    PU_LPR_PLT_NORMYELLOW = 3,    // ��ͨ�������
    PU_LPR_PLT_DBLYELLOW = 4,     // ˫�����
    PU_LPR_PLT_POLICE = 5,        // ��ɫ����
    PU_LPR_PLT_WJ = 6,            // ��ɫ�侯
    PU_LPR_PLT_DBLWJ = 7,         // ˫���ɫ�侯
    PU_LPR_PLT_ARMY = 8,          // �������
    PU_LPR_PLT_DBLARMY = 9,       // ˫�����
    PU_LPR_PLT_EMBASSY = 10,      // ��ʹ����
    PU_LPR_PLT_HK = 11,           // ����
    PU_LPR_PLT_MACAU = 13,        // ������
    PU_LPR_PLT_AGRICULTURE = 14,  // ũ�ó��� ������
    PU_LPR_PLT_CHANGNEI = 15,     // ������
    PU_LPR_PLT_INDIVI = 16,       // ���Ի�����
    PU_LPR_PLT_NEWNENRGY = 17,    // ����Դ��
    PU_LPR_PLT_OTHER = 18,        // ��������

    PU_VLPR_LPT_INA_PRIVATE = 100,  // ӡ��˽�ҳ�
    PU_VLPR_LPT_INA_PUBLIC = 101,   // ӡ�ṫ����ͨ
    PU_VLPR_LPT_INA_EMBASSY = 102,  // ӡ��ʹ����

    PU_VLPR_LPT_KSA_PRIVATE = 110,  // ɳ�س���
    PU_VLPR_LPT_SAU_OTHER = 112,    // ɳ��������

    PU_VLPR_LPT_HK_PRIVATE = 120,  // ��۳���

    PU_VLPR_LPR_BRA_PRIVATE = 130,     // ����˽�ҳ�
    PU_VLPR_LPR_BRA_COMMERCIAL = 131,  // ��������
    PU_VLPR_LPR_BRA_OFFICIAL = 132,    // �����ٷ���
    PU_VLPR_LPR_BRA_DIPLOMATIC = 133,  // ����ʹ�ݳ�
    PU_VLPR_LPR_BRA_MOTO = 134,        // ����Ħ�г�
    PU_VLPR_LPR_BRA_OTHER = 135,       // ����������
    PU_VLPR_LPR_MEX_PRIVATE = 140,     // ī����˽�ҳ�
    PU_VLPR_LPR_MEX_BUS = 141,         // ī���繫����
    PU_VLPR_LPR_MEX_TAXI = 142,        // ī������⳵
    PU_VLPR_LPR_MEX_TRUCK = 143,       // ī���翨��
    PU_VLPR_LPR_MEX_MOTO = 144,        // ī����Ħ�г�
    PU_VLPR_LPR_MEX      = 145,        // ī���糵��
    PU_VLPR_LPR_ARG_PRIVATE = 150,     // ����͢˽�ҳ�
    PU_VLPR_LPR_ARG_OFFICIAL = 151,    // ����͢�ٷ���
    PU_VLPR_LPR_ARG_MOTO = 152,        // ����͢Ħ�г�
    PU_VLPR_LPR_ARG_OTHER = 153,       // ����͢������
    PU_VLPR_LPR_ZAF_PRIVATE = 160,     // �Ϸǻ�����
    PU_VLPR_LPR_ZAF_OFFICIAL = 161,    // �Ϸ�������
    PU_VLPR_LPR_ZAF_DIPLOMATIC = 162,  // �Ϸ�ʹ�ݳ�
    PU_VLPR_LPR_ZAF_POLICE = 163,      // �ϷǾ���
    PU_VLPR_LPR_ZAF_MILITARY = 164,    // �ϷǾ���
    PU_VLPR_LPR_ZAF_MOTO = 165,        // �Ϸ�Ħ�г�
    PU_VLPR_LPR_ZAF_OTHER = 166,       // �Ϸ�������
    PU_VLPR_LPR_GHA_PRIVATE = 170,     // ����˽�ҳ�
    PU_VLPR_LPR_GHA_OFFICIAL = 171,    // ����������
    PU_VLPR_LPR_GHA_DIPLOMATIC = 172,  // �����⽻��
    PU_VLPR_LPR_GHA_COMMERCIAL = 173,  // �������ó�
    PU_VLPR_LPR_GHA_MOTO = 174,        // ����Ħ�г�
    PU_VLPR_LPR_GHA_OTHER = 175,       // ����������

} PU_PLATE_TYPE_E;

// ������ɫ
typedef enum PU_VEHICLE_COLOR {
    PU_LPR_VC_NOT,  // δ֪

    PU_LPR_VC_WHITE,   // ��ɫ
    PU_LPR_VC_GRAY,    // ��ɫ(��ɫ)
    PU_LPR_VC_YELLOW,  // ��ɫ
    PU_LPR_VC_PINK,    // ��ɫ
    PU_LPR_VC_RED,     // ��ɫ
    PU_LPR_VC_GREEN,   // ��ɫ
    PU_LPR_VC_BLUE,    // ��ɫ
    PU_LPR_VC_BROWN,   // ��ɫ
    PU_LPR_VC_BLACK,   // ��ɫ
    PU_LPR_VC_PURPLE,  // ��ɫ
    PU_LPR_VC_ORANGE,  // ��ɫ
    PU_LPR_VC_CYAN,    // ��ɫ
    PU_LPR_VC_GOLDEN,  // ��ɫ
    PU_LPR_VC_SILVER,  // ��ɫ
} PU_VEHICLE_COLOR_E;

// ��������
typedef enum PU_VEHICLE_TYPE {
    PU_LPR_VT_NOT,          // δ֪
    PU_LPR_VT_CAR,          // �γ� ռλ
    PU_LPR_VT_TRUCK,        // ���� ռλ
    PU_LPR_VT_VAN,          // �����
    PU_LPR_VT_PAS,          // �ͳ�
    PU_LPR_VT_BUGGY,        // С���� ռλ
    PU_LPR_VT_SUV,          // SUV ռλ
    PU_LPR_VT_MEDIUM_BUS,   // ���Ϳͳ�
    PU_LPR_VT_MOT,          // Ħ�г�-�ǻ�����
    PU_LPR_VT_PEDESTRAIN,   // ����
    PU_LPR_VT_SCHOOL_BUS,   // У��
    PU_LPR_VT_HEAVY_TRUCK,  // ��ͷ��-������
    PU_LPR_VT_TANKER,       // ��Σ��
    PU_LPR_VT_RIDEMAN,      // ������ ռλ
    // =================�������ϰ汾֧��

    PU_VLPR_VT_CAR_M,    // ΢�ͽγ�
    PU_VLPR_VT_CAR_L,    // С�ͽγ�
    PU_VLPR_VT_CAR_S,    // �����ͽγ�
    PU_VLPR_VT_CAR_TWO,  // ����γ�
    PU_VLPR_VT_CAR_THR,  // ����γ�

    PU_VLPR_VT_SUV_QINGKE,  // ���

    PU_VLPR_VT_SUV_L,  // С ��SUV
    PU_VLPR_VT_SUV_S,  // ������SUV
    PU_VLPR_VT_SUV_Z,  // ����SUV
    PU_VLPR_VT_SUV_M,  // �д���SUV
    PU_VLPR_VT_SUV_B,  // ����SUV

    PU_VLPR_VT_WEIMIAN,  // ΢�������

    PU_VLPR_VT_MPV,  // MPV
    PU_VLPR_VT_JP,   // ����

    PU_VLPR_VT_WEIKA,      // ΢��
    PU_VLPR_VT_SUV_PIKA,   // Ƥ��
    PU_VLPR_VT_TRUCK_Z,    // �п�
    PU_VLPR_VT_TRUCK_KEI,  // �Ῠ
    PU_VLPR_VT_ZHONGKA,    // �ؿ�

    PU_VLPR_VT_TAXI,   // ���⳵
    PU_VLPR_VT_TANK,   // �͹޳�
    PU_VLPR_VT_CRANE,  // ����

    PU_VLPR_VT_MOTOR = 120,  // Ħ�г�

    PU_LPR_VT_ALL = 512  // ȫ��
} PU_VEHICLE_TYPE_E;

// �����ƶ�����
typedef enum PU_PLATE_DIR {
    PU_LPR_UNKNOWN = 0,  // δ֪
    PU_LPR_LEFT = 1,     // ��
    PU_LPR_RIGHT = 2,    // ��
    PU_LPR_UP = 3,       // ��
    PU_LPR_DOWN = 4,     // ��
} PU_PLATE_DIR_E;

// ����������
typedef enum PU_VEHICLE_DIR {
    PU_VLPR_VD_HEAD = 0,          // ��ͷ����
    PU_VLPR_VD_TAIL = 1,          // ��β����
    PU_VLPR_VD_HEAD_AND_TAIL = 2  // ˫��
} PU_VEHICLE_DIR_E;

typedef enum PU_VLPR_CATCH_MODE {
    PU_VLPR_MODE_MOTORWAY = 0,   // ������ģʽ
    PU_VLPR_MODE_COEXISTED = 1,  // ������ģʽ Coexisted motorway-bicycle lane-sidewalk
} PU_VLPR_CATCH_MODE_E;

// ����ץ���㷨����
typedef enum PU_VLPR_ALG_MODE {
    PU_VLPR_ALG_CHINESE,  // �й�����
    PU_VLPR_ALG_EURO,     // ŷ�޳���
    PU_VLPR_ALG_INA,      // ӡ�ᳵ��
    PU_VLPR_ALG_HK,       // ��۳���
    PU_VLPR_ALG_GHA,      // ���ɳ���
    PU_VLPR_ALG_BRA,      // ��������
    PU_VLPR_ALG_SAU,      // ɳ�س���
    PU_VLPR_ALG_MEX,      // ī���糵��
    PU_VLPR_ALG_MAX,
} PU_VLPR_ALG_MODE_E;

typedef enum BACKLIGHT_MODE {
    VIDEO_MODE_AVERAGE = 0,  // ��������ΪĬ������
    VIDEO_MODE_CENTER,       // ��������Ϊ������������
    VIDEO_MODE_UP,           // ��������Ϊ�����ϲ�����, �ñ�����ΪԤ��
    VIDEO_MODE_DOWN,         // ��������Ϊ�����²�����, �ñ�����ΪԤ��
    VIDEO_MODE_LEFT,         // ��������Ϊ����������, �ñ�����ΪԤ��
    VIDEO_MODE_RIGHT,        // ��������Ϊ�����Ҳ�����, �ñ�����ΪԤ��
    VIDEO_MODE_USER          // ��������Ϊ�Զ�������
} BACKLIGHT_MODE_E;

typedef enum PTZ_OSD_MODE {
    PTZ_OSD_NONE,         // ����ʾ
    PTZ_OSD_PTZ_INFO,     // �ƾ���Ϣģʽ
    PTZ_OSD_ORIENTATION,  // ��λ��ģʽ
    PTZ_OSD_POSITION,     // ��γ��ģʽ
    PTZ_OSD_ZOOM,         // �䱶��Ϣģʽ
} PTZ_OSD_MODE_E;

// �����IOģʽ
typedef enum PU_SUPPLEMENT_LIGHT_LAMP_IO_MODE {
    PU_IO_CONTINUE_MODE = 0,
    PU_IO_MODE_MAX
} PU_SUPPLEMENT_LIGHT_LAMP_IO_MODE_E;

// ����ƿ���ģʽ
typedef enum PU_SUPPLEMENT_LIGHT_LAMP_CTRL_MODE {
    PU_CONTROL_DISABLE_MODE = 0,
    PU_CONTROL_AUTO_MODE,
    PU_CONTROL_TIME_MODE,
    PU_CONTROL_MODE_MAX
} PU_SUPPLEMENT_LIGHT_LAMP_CTRL_MODE_E;

typedef enum PU_ISP_IRCUT_MODULE {
    PU_IRCUT_MODE_DUMMY = 0,  // ��ɫģʽ
    PU_IRCUT_MODE_NIGHT,      // �ڰ�ģʽ
    PU_IRCUT_MODE_DEFOG,      // ��ѧ͸��(�����豸֧��)
    PU_IRCUT_MODE_MAX
} PU_ISP_IRCUT_MODULE_E;

// �澯����PTZ���ȼ�
typedef enum PU_ALARM_LINK_PTZ_PRIORITY {
    PU_GUARD_FIRST = 0,  // ��������    --> ������ʱ�䵽ʱ��ֱ�Ӵ��������۵�ǰ�Ƿ��ڸ澯
    PU_ALARM_FIRST,      // �澯�������� --> ���澯�������澯��������������Ч
    PU_LINK_MAX,
} PU_ALARM_LINK_PTZ_PRIORITY_E;

// ����������ģʽ
typedef enum PU_FACE_DETECTION_DL_MODE {
    FACE_MODE = 0,   // �������
    BODY_MODE,       // ������
    FACE_BODY_MODE,  // ������������
} PU_FACE_DETECTION_DL_MODE_E;

// ���߷���
typedef enum PU_TRIPWIRE_DIR {
    PU_TRIPWIRE_CLOCKWISE = 0,  // ����˳ʱ��Խ��
    PU_TRIPWIRE_ANTICLOCKWISE,  // ������ʱ��Խ��
    PU_TRIPWIRE_MAX
} PU_TRIPWIRE_DIR_E;

typedef enum PU_TABLE_TYPE {
    PU_TABLE_DAY,    // �ձ���
    PU_TABLE_WEEK,   // �ܱ���
    PU_TABLE_MONTH,  // �±���
    PU_TABLE_YEAR    // �걨��
} PU_TABLE_TYPE_E;

typedef enum PU_SUPPLEMENTLAMP_TYPE {
    PU_TYPE_LAMP_WHITE = 0,  // �׹��
    PU_TYPE_LAMP_RED,        // �����
    PU_TYPE_LAMP_MAX
} PU_SUPPLEMENTLAMP_TYPE_E;

// ������֡��Զ�ģʽ����
typedef enum PU_LAMP_CTRL_MODE {
    LAMP_CTRL_MODE_AUTO = 0,  // �Զ�
    LAMP_CTRL_MODE_MANUAL,    // �ֶ�
} PU_LAMP_CTRL_MODE_E;

typedef enum FRAME_TYPE {
    FRAME_TYPE_VIDEO = 1,
    FRAME_TYPE_AUDIO = 2,

    FRAME_TYPE_MAX
} PU_FRAME_TYPE_E;

typedef enum PU_VIDEO_FRAME_TYPE {
    PU_VIDEO_FRAME_I = 0,  // I֡    
    PU_VIDEO_FRAME_P,      // P֡    
    PU_VIDEO_FRAME_B,      // B֡    
    PU_VIDEO_FRAME_UNKNOWN
   } PU_VIDEO_FRAME_TYPE_E;

typedef enum {
    SINGLE_PACKET = 0xAA,
    SLICE_HEAD_PACKET = 0xBB,
    SLICE_MID_PACKET = 0xCC,
    SLICE_TAIL_PACKET = 0xDD,
    META_DATA_PACKET_TYPE_MAX = 0xFF
} META_DATA_PACKET_TYPE_E;

#define MAX_POINT_NUM (10)
// ��һ��Ԫ����TYPE
typedef enum LAYER_ONE_TYPE {
    METADATA_TYPE = 0x4154454D,  // 'M''E''T''A' С����
} LAYER_ONE_TYPE_E;

// �ڶ���Ԫ����TYPE
typedef enum LAYER_TWO_TYPE {
    COMMON = 0x00000001,  // ͨ��
    TARGET = 0x00000002,  // Ŀ��(�����ˡ������ȵ�)
    RULE = 0x00000003,    // ����(�趨�Ĺ����)
    TALARM = 0x00000004,  // ���ܱ���
    TRECORD = 0x00000005,  // ���ܴ���¼��
    TRAFFIC_LIGHT = 0x00000006 //�źŵ�״̬
} LAYER_TWO_TYPE_E;

// Ԫ���������� << ȫ�����ܽӿڶԽ�TLV��������ĵ�Ϊ׼>>
// ��������:https://support.huawei.com/enterprise/zh/doc/EDOC1100084903
typedef enum LAYER_THREE_TYPE {
    PTS = 0x09000001,         // ʱ���
    IMG_WIDTH = 0x07000100,   // ����ͼƬ��
    IMG_HEIGHT = 0x07000101,  // ����ͼƬ��

    // ����
    FACE_ID = 0x07000016,              // ����ID
    FACE_PANOPIC_SIZE = 0x07000018,    // ����ȫ��ͼƬ��С
    FACE_PIC_TIME = 0x08000015,        // ������ͼ����ʱ��
    FACE_PIC_TZONE = 0x08000020,       // ������ͼ�豸ʱ��(��λms ����Ϊ+ ����Ϊ-)
    HUMAN_FEATURE = 0x10000002,        // ��������(������ʹ�ã�ʹ��0X070003xx��ʼ�ĵ����������Դ���)
    FACE_FEATURE = 0x11000003,         // ��������(������ʹ�ã�ʹ��0X070002xx��ʼ�ĵ����������Դ���)
    PANORAMA_PIC = 0x0A00000A,         // ȫ��ͼƬ
    FACE_PIC = 0x0A000012,             // ������ͼ
    FACE_PIC_KPS = 0x07000012,         // ������ͼkps�������˱�־λ
    HUMAN_PIC = 0x0A000013,            // �����ͼ
    HUMAN_PIC_KPS = 0x07000013,        // �����ͼkps�������˱�־λ
    HUMAN_PIC_ROI = 0x0B000017,        // �����ͼ�е�����Ŀ���
    FACE_PANORAMA = 0x0A000017,        // ����ȫ��
    FACE_PIC_POSITION = 0x0B000011,    // ������ͼС��λ��
    FACE_POS = 0x0B000012,             // ����λ��(ʵʱλ�ÿ� ��ֱ�) (��ʼ֧�ְ汾:SDC V500R019C30)
    FACE_MATCH          = 0x0A000014, // �������ݿ���ƥ��ͼƬ
    FACELIB_RECORDID    = 0x07000017, // �������е�����ID������ά������ record��һ����
    FACE_MATCHRATE      = 0x07000020, // ����ƥ����
    FACE_INFO           = 0x12000001, // ������Ϣ,��Ӧ���ݿ�����Ϣ
    FACE_LIB_TYPE       = 0x07000022, // ����������
    FACE_LIB_NAME       = 0x0A000015, // ����������
    TARGET_TYPE         = 0x07000023, // target���ͣ��������ܵ�ҵ������(��ʼ֧�ְ汾:SDC V500R019C30)

    // �������ԣ� ��FACE��ͷ 0 ��ʾδ֪ 1~n���ζ�Ӧע�͵�����
    FACE_GLASS          = 0X07000200, // �۾�{�ޣ���} 
    FACE_GENDER         = 0X07000201, // �Ա�{Ů����} 
    FACE_AGE            = 0X07000202, // ���䣬���������ֵ1~99 
    FACE_MOUTHMASK      = 0X07000203, // �ڵ�(����) {�ޣ���} 
    FACE_EXPRESSION     = 0X07000204, // ��������{΢Ц����ŭ�����ˡ�����������}
    FACE_HAT            = 0X07000205, // ñ��{��, ��}
    FACE_MUSTACHE       = 0X07000206, // ����{��, ��} (֧�ְ汾:SDC 8.0.1)
    FACE_HAIR           = 0X07000207, // ����{��, ��}(֧�ְ汾:SDC 8.0.1)
    FACE_GLASS_TYPE     = 0X07000208, // �۾�{�ޣ���ͨ�۾���̫���۾�} (��ʼ֧�ְ汾:SDC 8.0.1)

    // ���������� ��HUMAN��ͷ 0 ��ʾδ֪ 1~n���ζ�Ӧע�͵�����
    HUMAN_AGE           = 0X07000300, // ���� {����,����,����} 
    HUMAN_GENDER        = 0X07000301, // �Ա�{�У�Ů}
    HUMAN_UPPERSTYLE    = 0X07000302, // ���¿�ʽ {���䣬����} 
    HUMAN_UPPERCOLOR    = 0X07000303, // ������ɫ {�ڣ������̣���/�ң���/��/�أ���/��/��}
    HUMAN_UPPERTEXTURE  = 0X07000304, // �������� {��ɫ�����ƣ�����} 
    HUMAN_LOWSTYLE      = 0X07000305, // ���¿�ʽ {����,�̿㣬ȹ��}      
    HUMAN_LOWERCOLOR    = 0X07000306, // ������ɫ {�ڣ������̣���/�ң���/��/�أ���/��/��}  
    HUMAN_SHAPE         = 0X07000307, // ����{standard, fat, thin}
    HUMAN_MOUTHMASK     = 0X07000308, // ����{no,yes}  
    HUMAN_HAIR          = 0X07000309, // ����{ long, short }
    HUMAN_BACKPACK      = 0X0700030A, // ����{no,yes} 
    HUMAN_CARRY         = 0X0700030B, // �Ƿ��ණ��{no,yes}
    HUMAN_SATCHEL       = 0X0700030C, // б���{no,yes} 
    HUMAN_UMBRELLA      = 0X0700030D, // ��ɡ{no,yes}
    HUMAN_FRONTPACK     = 0X0700030E, // ǰ�汳��{no,yes}
    HUMAN_LUGGAGE       = 0X0700030F, // ������{no,yes} 
    HUMAN_DIRECT        = 0X07000310, // �н�����{forward,backward}
    HUMAN_SPEED         = 0X07000311, // �н��ٶ�{slow,fast}
    HUMAN_VIEW          = 0X07000312, // ����{frontal, back, leftprofiled, rightprofiled}
    HUMAN_GLASS         = 0X07000313, // �۾�{no,glass, sunglass}
    HUMAN_HAT           = 0X07000314, // ��ñ��{no, yes}

    // �ǻ����������� ��RIDERMAN��ͷ 0 ��ʾδ֪ 1~n���ζ�Ӧע�͵�����
    RIDERMAN_AGE        = 0X07000400, // ���� {����,����,����}   
    RIDERMAN_GENDER     = 0X07000401, // �Ա�{�У�Ů}     
    RIDERMAN_UPPERSTYLE = 0X07000402, // ���¿�ʽ {���䣬����}        
    RIDERMAN_UPPERCOLOR = 0X07000403, // ������ɫ {�ڣ������̣���/�ң���/��/�أ���/��/��}        
    RIDERMAN_HELMET     = 0X07000404, // �Ƿ��ͷ�� {no, yes} 
    RIDERMAN_HELMETCOLOR= 0X07000405, // ͷ����ɫ {�ڣ������̣���/�ң���/��/�أ���/��/��} 
    APPROACH_LANE_ID    = 0x07000605, // �ٽ�������(��ʼ֧�ְ汾:SDC 8.0.1)

    // ����
    HUMAN_RECT = 0x0B000013,           // ����λ��(ʵʱλ�ÿ�)
    HUMAN_RECT_POSITION = 0x0B000014,  // �����ͼС��λ��
    SHOULDER_RECT       = 0x0B000018, // ͷ��λ��
    SHOULDER_NUM        = 0x06000001, // ͷ�����
    QUEUE_TIME          = 0x06000002, // �Ŷ�ʱ��

    OBJ_ID = 0x07000021,              // Ŀ��ID
    OBJ_STATUS = 0x06000022,          // Ŀ��״̬
    OBJ_POS = 0x0B000023,             // Ŀ��λ��
    OBJ_TYPE = 0x06000024,            // Ŀ������
    OBJ_SPEED = 0x0C000025,           // Ŀ���ٶ�
    OBJ_UPHALF_COLOR = 0x0F000026,    // Ŀ���ϰ벿��ɫ
    OBJ_DOWNHALF_COLOR = 0x0F000027,  // Ŀ���°벿��ɫ
    RULE_TYPE = 0x07000031,           // ��������
    RULE_LINE_POS = 0x0D000032,       // ������λ��
    RULE_LINE_DIR = 0x07000033,       // �����߷���
    RULE_AREA_POS = 0x0E000034,       // �����λ��
    OBJ_POS_R = 0x0B000035,           // Ŀ��λ��(���λ��)
    OBJ_SPEED_R = 0x0C000036,         // Ŀ���ٶ�(���λ��)
    RULE_LINE_POS_R = 0x0D000037,     // ������λ��(���λ��)
    RULE_AREA_POS_R = 0x0E000038,     // �����λ��(���λ��)

    LANE_ID = 0x07000002,              // ������
    TRAFFIC_LIGHT_COLOR_ONE  = 0x07000106, // �źŵ� 1 ��ɫ
    TRAFFIC_LIGHT_DIREC_ONE  = 0x07000107, // �źŵ�1����
    TRAFFIC_LIGHT_COLOR_TWO  = 0x07000108, // �źŵ�2��ɫ
    TRAFFIC_LIGHT_DIREC_TWO = 0x07000109, // �źŵ�2����
    TRAFFIC_LIGHT_COLOR_THREE  = 0x07000110, // �źŵ�3��ɫ
    TRAFFIC_LIGHT_DIREC_THREE  = 0x07000111, // �źŵ�3����
    TRAFFIC_LIGHT_COLOR_FOUR  = 0x07000112, // �źŵ�4��ɫ
    TRAFFIC_LIGHT_DIREC_FOUR  = 0x07000113, // �źŵ�4����
    VEHICLE_TYPE = 0x07000003,         // ��������
    VEHICLE_TYPE_EXT    = 0x07000406, // ����������չ(��ʼ֧�ְ汾:SDC V500R019C50)
    VEHICLE_COLOR = 0x07000004,        // ������ɫ
    VEHICLE_DIRECTION = 0x07000005,    // ������ʻ����
    VEHICLE_POS = 0x0B000005,          // ����λ��  (��ֱȣ���ʼ֧�ְ汾:SDC V500R019C30)
    VEHICLE_POS_ABS     = 0x0B000020, // ����λ�þ�������              
    VEHICLE_POS_COM     = 0x0B000021, // ����λ�����������ֱ�
    PLATE_TYPE = 0x07000006,           // ��������
    PLATE_POS = 0x0B000007,            // ����λ��(��ʼ֧�ְ汾:SDC V500R019C30)
    PLATE_POS_ABS       = 0x0B000026, // ����λ�þ�������             
    PLATE_POS_COM       = 0x0B000027, // ����λ�����������ֱ� 
    PLATE_CHAR = 0x0A000008,           // �����ַ�
    PLATE_PIC = 0x0A000009,            // ���ƿ�ͼ(��ʼ֧�ְ汾:SDC V500R019C60)
    PLATE_BMP_BIT       = 0x0A00000B, // ���ƶ�ֵͼ(��ʼ֧�ְ汾:SDC 8.0.1)
    PLATE_BMP_BYTE      = 0x0A00000C, // ����BMPͼ(��ʼ֧�ְ汾:SDC 8.0.1)    
    PLATE_CONFIDENCE = 0x07000061,     // �������Ŷ�(��ʼ֧�ְ汾:SDC V500R019C60)
    PLATE_COLOR = 0x07000062,          // ������ɫ
    PLATE_SNAPSHOT_TYPE = 0x07000066,  // ����ץ������
    VEHICLE_PIC = 0x0A000067,          // ������дͼ(��ʼ֧�ְ汾:SDC V500R019C30)
    FACE_FEATURE_PIC    = 0x0A000068, // ���˴����������дͼ(��ʼ֧�ְ汾:SDC 8.0.1)
    PIC_SNAPSHOT_TIMEMS = 0x09000003,  // ץ��ʱ��(��λms)(��ʼ֧�ְ汾:SDC V500R019C50)
    PIC_SNAPSHOT_TIME = 0x07000068,    // ץ��ʱ��
    PIC_SNAPSHOT_TZONE = 0x08000069,   // �豸ʱ��(��λms ����Ϊ+ ����Ϊ-)
    DEVICE_ID = 0x0A000025,            // �豸���
    ROID_ID = 0x0A000026,              // ��·���
    DIR_ID = 0x0A000027,               // ������
    DIR_INFO = 0x0A000028,             // ������Ϣ
    REGULATION_CODE = 0x0A000029,      // Υ�´����ַ���(��ʼ֧�ְ汾:SDC 8.0.1)
    LANE_DESC           = 0x070000B2, // ��������(��ʼ֧�ְ汾:SDC V500R019C30)
    LANE_DIR_DESC       = 0x070000B3, // ������������(��ʼ֧�ְ汾:SDC V500R019C30)
    CAR_DRV_DIR         = 0x070000B6, // ������ʻ��������(��ʼ֧�ְ汾:SDC V500R019C30)
    RADER_CAR_DIR       = 0x070000B7, // �״���ٷ���(��ʼ֧�ְ汾:SDC V500R019C30)
    CUR_SNAP_INDEX      = 0x070000B8, // ��ǰץ�����к�(��ʼ֧�ְ汾:SDC V500R019C30)

    ITS_COMBINE = 0x01000003, // Υ��ͼƬ �Ƿ����ϳ�
    ITS_OSD_PIC_OFFSET = 0x06000037, // ITS ����һ����osd���µĳ���λ��ƫ����,��ֵ��ʾ��������ϱ�Ե,
                                        // ��ֵ��ʾ��������±�Ե(��ʼ֧�ְ汾:SDC V500R019C30)

    TRAFFIC_STATISTICS = 0x070000A0,                              // ������ͳ�Ʋ���(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_LANE_COUNT = 0x070000A1,                   // ������ͳ�Ƴ�������(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_LANE_INDEX = 0x070000A2,                   // ������ͳ�Ƶ�ǰ����(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_VEHICLE_COUNT = 0x070000A3,                // ��������(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_AVG_SPEED = 0x070000A4,                    // ƽ���ٶ�(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_LANE_TIME_USED_RATIO = 0x070000A5,         // ����ʱ��ռ����(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_VEHICLE_DENSITY = 0x070000A6,              // �����ܶ�(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_VEHICLE_HEAD_INTERVAL = 0x070000A7,        // ��ͷʱ����(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_VEHICLE_HEAD_SPACE_INTERVAL = 0x070000A8,  // ��ͷ���(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_CONGESTION_DEGREE = 0x070000A9,            // ��ͨ״̬(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_VEHICLE_TYPE1_COUNT = 0x070000AA,          // ���ͳ�����(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_VEHICLE_TYPE2_COUNT = 0x070000AB,          // ���ͳ�����(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_VEHICLE_TYPE3_COUNT = 0x070000AC,          // С�ͳ�����(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_QUEUE_LENGTH = 0x070000AD,                 // �Ŷӳ���(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_LANE_SPACE_USED_RATIO = 0x070000AE,        // �����ռ�ռ����(��ʼ֧�ְ汾:SDC V500R019C30)
    ITS_TRAFFIC_LEFT_VEHICLE_COUNT = 0x070000AF,                  //  its��ת������(��ʼ֧�ְ汾:SDC V500R019C30)
    ITS_TRAFFIC_STRAIGHT_VHEICLE_COUNT = 0x070000B0,              //  itsֱ�г�����(��ʼ֧�ְ汾:SDC V500R019C30)
    ITS_TRAFFIC_RIGHT_VHEICLE_COUNT = 0x070000B1,                 //  its��ת������(��ʼ֧�ְ汾:SDC V500R019C30)
    TRAFFIC_STATISTICS_CYCLE        = 0x070000B9,                 // ������ͳ������(��ʼ֧�ְ汾:SDC V500R019C50)
    TRAFFIC_STATISTICS_NONMOTOR_COUNT = 0x070000C0,               // �ǻ���������(��ʼ֧�ְ汾:SDC 8.0.0)
    TRAFFIC_STATISTICS_PEDESTRIAN_COUNT = 0x070000C1,             // ��������(��ʼ֧�ְ汾:SDC 8.0.0)
    TRAFFIC_STATISTICS_TOTAL_VEHICLE_COUNT = 0x070000C2,          // ��������(��ʼ֧�ְ汾:SDC 8.0.0)
    VEHICLE_SPEED = 0x07000075,                                   // �����ٶ�
    REGULATION_TYPE = 0x07000076,                                 // Υ������
    
    MFR_MAIN_CALL = 0x06000025,       // ����ʻ��绰(��ʼ֧�ְ汾:SDC V500R019C30)
    MFR_MAIN_BELT = 0x06000026,       // ����ʻ��ȫ��(��ʼ֧�ְ汾:SDC V500R019C30)
    MFR_VICE_EXIST = 0x06000027,      // �Ƿ��и���ʻ(��ʼ֧�ְ汾:SDC V500R019C30)
    MFR_VICE_BELT = 0x06000035,       // ����ʻ��ȫ��(��ʼ֧�ְ汾:SDC V500R019C30)
    MFR_YEAR_LOG = 0x06000036,        // ����(��ʼ֧�ְ汾:SDC V500R019C30)
    MFR_MAIN_SUN_VISOR = 0x06000030,  // ����ʻ������(��ʼ֧�ְ汾:SDC V500R019C30)
    MFR_VICE_SUN_VISOR = 0x06000031,  // ����ʻ������(��ʼ֧�ְ汾:SDC V500R019C30)
    MFR_NAP_KIN_BOX = 0x06000032,     // ֽ���(��ʼ֧�ְ汾:SDC V500R019C30)
    MFR_CAR_PENDANT = 0x06000034,     // �Ҽ�(��ʼ֧�ְ汾:SDC V500R019C30)
    
    VEHICLE_BODY_RECT = 0x0B000008,     // ����λ��
    NOMOTOR_BODY_RECT = 0x0B000009,     // �ǻ���������λ��
    MOTOR_COLOR = 0X07000600,           // �ǻ�������ɫ {��(1)����(2)����(3)����/��(4)����/��/��(5)����/��/��(6)} (��ʼ֧�ְ汾:SDC 8.0.1)
    MOTOR_SUNSHADE = 0X07000601,        // �Ƿ�������ɡ{��(1),��(2)} (��ʼ֧�ְ汾:SDC 8.0.1)
    MOTOR_SUNSHADE_COLOR = 0X07000602,  // ����ɡ��ɫ {��(1)����(2)����(3)����/��(4)����/��/��(5)����/��/��(6)} (��ʼ֧�ְ汾:SDC 8.0.1)
    MOTOR_MOTOR_CARRY = 0X07000603,     // �Ƿ���Я���� {��(1),��(2)} (��ʼ֧�ְ汾:SDC 8.0.1)
    MOTOR_LICENSE_PLATE = 0X07000604,   // �Ƿ��г���{��(1),��(2)} (��ʼ֧�ְ汾:SDC 8.0.1)

    CAR_PRE_BRAND = 0x0A000007,        // Ʒ���ַ� ����  �ڣ�(��ʼ֧�ְ汾:SDC V500R019C60 )
    CAR_SUB_BRAND = 0x0A000022,        // �ӿ��ַ� ��ɣ���ɣ�(��ʼ֧�ְ汾:SDC V500R019C60 )
    CAR_YEAR_BRAND = 0x0A000024,       // ����ַ� ��2011��(��ʼ֧�ְ汾:SDC V500R019C60 )
    VHD_OBJ_ID = 0x09000006,           // ������ID
    CAR_PRE_BRAND_INDEX = 0x06000028,  // Ʒ���ַ����� ����  �ڣ�(��ʼ֧�ְ汾:SDC V500R019C30 )
    CAR_SUB_BRAND_INDEX = 0x06000029,  // �ӿ��ַ����� ��ɣ���ɣ�(��ʼ֧�ְ汾:SDC V500R019C30 )

    DEV_CNT = 0x03000070,  // �豸��
    CHAN_ID = 0x03000071,  // ͨ����

    PEOPLE_NUM = 0X07000087,        // ��Ⱥ�ܶȼ���㷨����
    HEADSHOULDER_POS = 0X0B000088,  // ��Ⱥ�ܶȼ���㷨���ؿ�ĵ�ַ
    AREARATIO = 0X07000089,         // ��Ⱥ�ܶȼ���㷨��Ⱥ�ܶ�
    TRACK_OBJECT = 0x07000028,      // ����Ŀ��id (��ʼ֧�ְ汾:SDC V500R019C30 )
    CHANNEL_ID = 0x09000078         // ���ͨ����(��ʼ֧�ְ汾:SDC V500R019C30 )
} LAYER_THREE_TYPE_E;

/* ������ */
typedef enum PU_RL_LIGHT_TYPE {
    RL_TYPE_DISC = 1,  // Բ��
    RL_TYPE_ARROW,     // ��ͷ
    RL_TYPE_NUMBER,    // ����ʱ
    RL_TYPE_SIDEWALK,  // ���е�
    RL_TYPE_MAX,
} PU_RL_LIGHT_TYPE_E;
/* ��״̬ */
typedef enum PU_RL_LIGHT_STATUS {
    RL_STATUS_GREEN = 0,  // �̵�
    RL_STATUS_RED,        // ���
    RL_STATUS_MAX,
} PU_RL_LIGHT_STATUS_E;

/* �źŵƵ��� */
typedef enum PU_RL_LIGHT_WAIT_TYPE {
    RL_TRAFFIC_LIGHT_WAIT_TURN_LEFT = 0x0,       // ��ת����
    RL_TRAFFIC_LIGHT_WAIT_GO_STRAIGHT = 0x1,     // ֱ�д���
    RL_TRAFFIC_LIGHT_WAIT_TURN_RIGHT = 0x2,      // ��ת����
    RL_TRAFFIC_LIGHT_WAIT_TURN_ROUND = 0x3,      // ��ͷת�����
    RL_TRAFFIC_LIGHT_STRAIGHT_LEFT = 0x4,        // ֱ����ת����
    RL_TRAFFIC_LIGHT_STRAIGHT_RIGHT = 0x5,       // ֱ����ת����
    RL_TRAFFIC_LIGHT_LEFT_RIGHT = 0x6,           // ��ת��ת����
    RL_TRAFFIC_LIGHT_STRAIGHT_LEFT_RIGHT = 0x7,  // ֱ����ת��ת����
    RL_TRAFFIC_LIGHT_WAIT_BUTT
} PU_RL_LIGHT_WAIT_TYPE_E;

/* AES ��Կ���� */
typedef enum PU_AES_KEY_MODULE {
    PU_AES_KEY_MODULE_WEB = 0,                 // WEB
    PU_AES_KEY_MODULE_ONVIF,                   // ONVIF
    PU_AES_KEY_MODULE_T28181,                  // T28181
    PU_AES_KEY_MODULE_CA_PWD,                  // CA֤��
    PU_AES_KEY_MODULE_8021X,                   // 8021X
    PU_AES_KEY_MODULE_SNMP,                    // SNMP
    PU_AES_KEY_MODULE_DDNS,                    // DDNS
    PU_AES_KEY_MODULE_SDK,                     // SDK
    PU_AES_KEY_MODULE_FACE_REC_DATABASE = 15,  // ����ʶ�����ݿ�
    PU_AES_KEY_MODULE_MAX
} PU_AES_KEY_MODULE_E;

typedef enum PU_FACE_PACKET_TYPE {
    FACE_PACKET_TYPE_PICMODE = 0,  // ͼƬ + ��Ա��Ϣ
    FACE_PACKET_TYPE_FEATUREMODE,  // ������ֻ֧��SDK,�����ƽ̨ʹ��
    FACE_PACKET_TYPE_ALLPACKET,    // ����ģʽ ͼƬ + ��Ա��Ϣ + ��������ֵ
    FACE_PACKET_TYPE_MAX
} PU_FACE_PACKET_TYPE_E;

typedef enum PU_FACE_LIB_IO_TYPE {
	FACE_IO_TYPE_LIB_IMPORT = 0,	// �׿⵼��
	FACE_IO_TYPE_FEATURE_EXTRACT,   // ������ȡ
	FACE_IO_TYPE_FEATURE_EXPORT,    // �����⵼��
} PU_FACE_LIB_IO_TYPE_E;

typedef enum PU_PIC_EXTRACT_TYPE {
    PU_PIC_EXTRACT_TYPE_FACE = 0,  // ����ͼƬ
    PU_PIC_EXTRACT_TYPE_MAX
} PU_PIC_EXTRACT_TYPE_E;

// ����
typedef struct _META_RECT_S {
    USHORT usX;       // �������϶����x����
    USHORT usY;       // �������϶����y����
    USHORT usWidth;   // ���ο�
    USHORT usHeight;  // ���θ�
} META_RECT_S;

// ��
typedef struct _META_POINT_S {
    USHORT usX;  // x
    USHORT usY;  // y
} META_POINT_S;

// ��
typedef struct _META_LINE_S {
    META_POINT_S stStartPoint;  // ��ʼ��
    META_POINT_S stEndPoint;    // ��ֹ��
} META_LINE_S;

// �����
typedef struct _META_POLYGON_S {
    UINT uPointNum;                      // �����
    META_POINT_S astPts[MAX_POINT_NUM];  //
} META_POLYGON_S;

// ��ɫ
typedef struct _META_COLOR_S {
    UCHAR auc_r[3];
    UCHAR auc_g[3];
    UCHAR auc_b[3];
    UCHAR auc_ConfLev[3];  // ���Ŷ�
    UCHAR auc_ColorID[3];  // ID
} META_COLOR_S;

// ��ɫ
typedef struct _ST_BINARY {
    ULONG ulBinaryLenth;
    UCHAR *pBinaryData;
} ST_BINARY;

// �н�����ǰ��
typedef enum META_MOVE_DIRECT {
    DIRECT_UNKNOWN = 0,  // δ֪
    DIRECT_FORWARD,      // ��ǰ
    DIRECT_BACKWARD,     // ���
} META_MOVE_DIRECT_E;

// �н��ٶȣ�������
typedef enum META_MOVE_SPEED {
    SPEED_UNKNOWN = 0,  // δ֪
    SPEED_SLOW,         // ��
    SPEED_FAST,         // ��
} META_MOVE_SPEED_E;

// �������Խ��
typedef struct META_HUMAN_ATTRIBUTES {
    BOOL isVaild;

    // INT ��������� 0 ���� δ֪��1-n���δ����������Ծ��庬��
    INT age;           // ���� {����,����,����}
    INT gender;        // �Ա�{�У�Ů}
    INT upperStyle;    // ���¿�ʽ {���䣬����}
    INT upperColor;    // ������ɫ {�ڣ������̣���/�ң���/��/�أ���/��/��}
    INT upperTexture;  // �������� {��ɫ������}
    INT lowerStyle;    // ���¿�ʽ {����,�̿�}
    INT lowerColor;    // ������ɫ {�ڣ������̣���/�ң���/��/�أ���/��/��}
    INT shape;         // ����{standard, fat, thin}
    INT mouthmask;     // ����{no,yes}
    INT hair;          // ����{ long, short }
    INT backpack;      // ����{no,yes}
    INT carry;         // �Ƿ��ණ��{no,yes}
    INT satchel;       // б���{no,yes}
    INT umbrella;      // ��ɡ{no,yes}
    INT frontpack;     // ǰ�汳��{no,yes}
    INT luggage;       // ������{no,yes}

    META_MOVE_DIRECT_E enMoveDirect;  // �н�����{direct_unknow,forward,backward}
    META_MOVE_SPEED_E enMoveSpeed;    // �н��ٶ�{speed_unknow,slow,fast}
} META_HUMAN_ATTRIBUTES_S;

// ��������
typedef struct META_FACE_ATTRIBUTES {
    BOOL isVaild;

    // INT ��������� 0 ���� δ֪��1-n���δ����������Ծ��庬��
    INT glasses;     // �۾�{�ޣ���}
    INT gender;      // �Ա�{Ů����}
    INT age;         // ���䣬���������ֵ1~99
    INT mouthmask;   // �ڵ� {�ޣ���}
    INT expression;  // ��������{΢Ц����ŭ�����ˡ�����������}
} META_FACE_ATTRIBUTES_S;

// ������Ϣ
typedef struct META_FACE_INFO {
    CHAR name[PU_MAX_RECORD_LEN_64];      // ����
    INT iGender;                          // �Ա�
    CHAR birthday[PU_MAX_RECORD_LEN_32];  // ����
    CHAR province[PU_MAX_RECORD_LEN_32];  // ʡ��
    CHAR city[PU_MAX_RECORD_LEN_48];      // ����
    INT iCardType;                        // ֤�����ͣ��μ�PU_CARDTYPE_E
    CHAR cardID[PU_MAX_RECORD_LEN_32];    // ֤����
} META_FACE_INFO_S;

typedef struct PU_UserData {
    LAYER_THREE_TYPE_E eType;
    union _unMetadata {
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
    } unMetaData;
} PU_UserData;

typedef struct _PU_META_TLV {
    INT iType;
    UINT uLength;
    UCHAR *pValue;
} PU_META_TLV;

typedef struct _PU_META_DATA {
    USHORT usCapacity;
    USHORT usValidNumber;
    PU_UserData *pstMetaUserData;
} PU_META_DATA;

typedef struct _PU_META_DATA_LAYER_SECOND {
    LAYER_TWO_TYPE_E eType;
    PU_META_DATA stMetaData;
} PU_META_DATA_LAYER_SECOND;

typedef struct _PU_META_DATA_ALL {
    USHORT usCapacity;
    USHORT usValidNumber;
    PU_META_DATA_LAYER_SECOND *pstMetaDataLayerSecond;
} PU_META_DATA_ALL;

/********************************�ṹ��**********************************************/
// �豸�汾
typedef struct PU_DEVICE_VERSION {
    CHAR szVerSoftware[PU_VERSION_LEN];  // ����汾
    CHAR szVerUboot[PU_VERSION_LEN];     // UBoot�汾
    CHAR szVerKernel[PU_VERSION_LEN];    // �ں˰汾
    CHAR szVerHardware[PU_VERSION_LEN];  // Ӳ���汾
    CHAR szReserved[PU_RESERVE_LEN];     // ǰ24 �ֽڱ�ʾMac��ַ,
    // szReserved[24],���,��ʾ��������,0��ʾ����1,1��ʾ����2,��ȡʱʹ��
    // szReserved[25],����,��ʾ��������,��ȡʱʹ��
} PU_DEVICE_VERSION, *LPPU_DEVICE_VERSION;

// �豸��Ϣ�ṹ
typedef struct PU_DEVICE_INFO {
    CHAR szDeviceName[PU_DEVICE_NAME_LEN];  // �豸�����32λ
    CHAR szDeviceFac[PU_FAC_NAME_LEN];      // �豸����
    CHAR szDeviceType[PU_DEVICE_TYPE_LEN];  // �豸�ͺ�,ֻ�ɲ�ѯ��������
    CHAR szSerialNumber[PU_SERIAL_LEN];     // Ӳ�����к�
    PU_DEVICE_VERSION stDeviceVersion;      // �豸�汾
    CHAR szReserved[PU_RESERVE_LEN];        // Bom����
} PU_DEVICEINFO_S, *LPPU_DEVICEINFO_S;

// �豸��Ϣ�ṹ����
typedef struct PU_DEVICE_INFO_V2 {
    CHAR szDeviceName[PU_DEVICE_NAME_EX_LEN];  // �豸�����(256 + 4)λ
    CHAR szDeviceFac[PU_FAC_NAME_LEN];         // �豸����
    CHAR szDeviceType[PU_DEVICE_TYPE_LEN];     // �豸�ͺ�,ֻ�ɲ�ѯ��������
    CHAR szSerialNumber[PU_SERIAL_LEN];        // Ӳ�����к�
    PU_DEVICE_VERSION stDeviceVersion;         // �豸�汾
    CHAR szBomEncod[PU_BOM_NUMBER_LEN];        // Bom����
    CHAR szReserved[PU_RESERVE_LEN];           // Ԥ���ֶ�
} PU_DEVICEINFO_V2_S, *LPPU_DEVICEINFO_V2_S;

// ��Ƶ�����ṹ
typedef struct PU_VIDEO_ATTRIBUTE {
    ULONG ulBitRate;                      // ����
    ULONG ulIFrameInterval;               // I֡���
    ULONG ulFrameRate;                    // ֡��
    PU_ENCODE_TYPE_E enVideoEncodeMode;   // ��Ƶ��������
    PU_RESOLUTION_TYPE_E enResolution;    // �ֱ���
    PU_BITRATE_TYPE_E enBitRateType;      // ��������
    PU_PIC_QUALITY_E enPicQuality;        // ͼ������
    PU_VIDEO_FORMAT_E enVideoFormat;      // ͼ����ʽ
    PU_H264_RC_PRI_E enRcPriMode;         // ֡��������������ģʽ,��H264����Ч
    PU_VIDEO_MIRROR_MODE_E enMirrorMode;  // ����ģʽ(ʵ��������������ģʽ��Ч)
    CHAR szReserve[PU_RESERVE_LEN];       // szReserve[0]��ʶ���븴�Ӷ�: H264 0 BP,   1 MP,     2 HP
    // H265 0 Main, 1 Main10, 2 MainSP (��ֻ֧��Main)
    // szReserve[1]��ʶMJPEG������ֵ[2,99]
    // szReserve[2]��ʶ�ֲ����ʹ�ܣ�0��ʹ�ܣ�1ʹ��(�������á���ȡ�����ײ�ʱ��Ч)
    // szReserve[3]��ʶ���ܱ���ȼ���0��ʹ�ܣ�1~5�����赵λ
    // szReserve[4]��ʶMultiSliceEnable 0��ʹ�ܣ�1ʹ��
	// szReserve[5]��ʶ�������� AECEnable 0��ʹ�ܣ�1ʹ��
} PU_VIDEO_ATTRIBUTE_S, *LPPU_VIDEO_ATTRIBUTE_S;

// ��Ƶ����Ϣ�ṹ
typedef struct PU_STREAM_ATTRIBUTE {
    PU_STREAM_TYPE_E enStreamId;            // ��������
    PU_VIDEO_ATTRIBUTE_S stVideoAttribute;  // ��Ƶ������
} PU_STREAM_ATTRIBUTE_S, *LPPU_STREAM_ATTRIBUTE_S;

// ��Ƶ����Ϣ
typedef struct PU_VIDEO_STREAM_INFO {
    ULONG ulChannelId;                                                // ͨ��ID
    PU_STREAM_MODE_E enStreamMode;                                    // ��Ƶ������
    PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_VIEDO_STREAM_TRIPLE];  // ��Ƶ����
    CHAR szReserved[PU_RESERVE_LEN];                                  // szReserve[0]��ʶȫ֡��
    // szReserve[1]��ʶ�ֱ��ʿ�խ��
} PU_VIDEO_STREAM_INFO_S, *LPPU_VIDEO_STREAM_INFO_S;

// ��Ƶ����Ϣ
typedef struct PU_VIDEO_STREAM_INFO_V2 {
    ULONG ulChannelId;                                              // ͨ��ID
    PU_STREAM_MODE_E enStreamMode;                                  // ��Ƶ������
    PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_VIEDO_STREAM_FIVE];  // ��Ƶ����
    CHAR szReserved[PU_RESERVE_LEN];                                // szReserve[0]��ʶȫ֡��  25:25HZ 30:30HZ 50��50HZ 60:60HZ
    // szReserve[1]��ʶ�ֱ��ʿ�խ�� 0��ʾ���� 1��ʾխ��
} PU_VIDEO_STREAM_INFO_V2_S, *LPPU_VIDEO_STREAM_INFO_V2_S;

// ��Ƶ����Ϣ
typedef struct PU_AUDIO_INFO {
    ULONG ulAudioChannelId;              // ��Ƶͨ��ID
    PU_ENCODE_TYPE_E enAudioEncodeMode;  // ��Ƶ��������
    ULONG ulInputVolume;                 // ��������
    ULONG ulOutputVolume;                // �������
    PU_AUDIO_G726_BPS_E enAudioRate;     // ��ƵG726����
    CHAR szReserved[3];                  // szReserved[0]��ʶ������ : 0 8K, 1 12K, 2 16K, 3 24K, 4 48K, 5 22.05K, 6 32K, 7 44.1K
    // szReserved[1]��ʶ��Ƶ�˿��������� : 0: Line in 1: Mic in
    // szReserved[2]��ʶ��Ƶ�Զ����� : 0:������ 1:����
    CHAR enEnableType;                   // �˿�ʹ��
    CHAR szReservedPlus[PU_RESERVE_LEN - 4];
} PU_AUDIO_INFO_S, *LPPU_AUDIO_INFO_S;

// ��Ƶ��ʾЧ���ṹ��
typedef struct PU_VIDEO_DISPLAY_INFO {
    ULONG ulChannelId;                     // ͨ��ID
    LONG lBrightValue;                     // ����
    LONG lHueValue;                        // ɫ��
    LONG lSaturationValue;                 // ���Ͷ�
    LONG lContrastValue;                   // �Աȶ�
    LONG lSharpValue;                      // ���
    PU_COMMONMODE_SWITCH_E enSharpSwitch;  // ��ȿ���
    // �ֶ���չ���������ֶ�ʹ��ʱ���밴���ϵ��µ��ֶ�˳����bitλ(�ӵ�����)
    USHORT usSetBitmap;
    USHORT usBitMap;  // �޸�λ��00000���ӵ�λ����Ϊ����, �Աȶ�, ���Ͷ�, ɫ��, ��ȣ���λ�޸���1��ʾ�޸ģ���0���޸�
    CHAR szReserved[PU_RESERVE_LEN - sizeof(USHORT) * 2 - sizeof(PU_COMMONMODE_SWITCH_E)];
} PU_VIDEO_DISPLAY_INFO_S, *LPPU_VIDEO_DISPLAY_INFO_S;

// H264�����ʼ�������û�����
typedef struct PU_H264_USERDATA {
    UINT uUserDataType;              // �û�����
    UINT uUserDataSize;              // �û����ݳ���
    UCHAR *pData;                    // �û����ݻ�����
    struct PU_H264_USERDATA *pNext;  // ��һ���û�����
} PU_H264_USERDATA_S;

// H264�����ʼ������
typedef struct PU_H264_DEC_ATTR {
    UINT uPictureFormat;              // ���ͼ���ʽ��0x00:YUV420 0x01:YUV422 0x02:YUV444
    UINT uStreamInType;               // ������������
    UINT uPicWidthInMB;               // ֧�ֵ�ͼ���ȣ���λ:MB
    UINT uPicHeightInMB;              // ֧�ֵ�ͼ��߶ȣ���λ:MB
    UINT uBufNum;                     // ���ο�֡��������
    UINT uWorkMode;                   // ����ģʽ
    PU_H264_USERDATA_S *pUserData;    // �û�����
    UINT uReserved;                   // ����
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_H264_DEC_ATTR_S;

// H264����֡��Ϣ
typedef struct PU_H264_DEC_OUTPUT_INFO {
    UINT uPicBytes;    // ��ǰ֡�ֽ���
    UINT uI4MbNum;     // ��ǰ֡��I4x4 ������
    UINT uI8MbNum;     // ��ǰ֡��I8x8 ������
    UINT uI16MbNum;    // ��ǰ֡��I16x16 ������
    UINT uP16MbNum;    // ��ǰ֡��P16x16 ������
    UINT uP16x8MbNum;  // ��ǰ֡��P16x8 ������
    UINT uP8x16MbNum;  // ��ǰ֡��P8x16 ������
    UINT uP8MbNum;     // ��ǰ֡��P8x8 ������
    UINT uPskipMbNum;  // ��ǰ֡��PSkip ������
    UINT uIpcmMbNum;   // ��ǰ֡��IPCM ������
} PU_H264_DEC_OUTPUT_INFO_S;

// H264֡��Ϣ
typedef struct PU_H264_DEC_FRAME {
    UCHAR *pY;                              // Y������ַ
    UCHAR *pU;                              // U������ַ
    UCHAR *pV;                              // V������ַ
    UINT uWidth;                            // ���ͼ���ȣ���λ: ����
    UINT uHeight;                           // ���ͼ��߶ȣ���λ: ����
    UINT uYStride;                          // ���Y����stride
    UINT uUVStride;                         // ���U/Y����stride
    UINT uCroppingLeftOffset;               // ���ͼ����߲ü�������λ: ����
    UINT uCroppingRightOffset;              // ���ͼ���ұ߲ü�������λ: ����
    UINT uCroppingTopOffset;                // ���ͼ���ϱ߲ü�������λ: ����
    UINT uCroppingBottomOffset;             // ���ͼ���±߲ü�������λ: ����
    UINT uDpbIdx;                           // ���ͼ�񻺴������
    UINT uPicFlag;                          // ���ͼ�����ԣ�0: ֡; 1: ����; 2: �׳�
    UINT uError;                            // ��ǰͼ������ʾ��0: ���ͼ���޴�; 1: ���ͼ���д�
    UINT uIntra;                            // ���ͼ���Ƿ�ΪIDR֡��0: ��IDR֡; 1:IDR֡
    ULONGLONG ullPTS;                       // ʱ���
    UINT uPictureID;                        // ���ͼ�����
    UINT uReserved;                         // ����
    PU_H264_USERDATA_S *pUserData;          // �û�����
    PU_H264_DEC_OUTPUT_INFO_S stFrameInfo;  // ��ǰ֡��Ϣ
    CHAR szReserved[PU_RESERVE_LEN];        // Ԥ���ֶ�
} PU_H264_DEC_FRAME_S;

// H265������ؽṹ����ֵ
typedef enum PU_H265D_RETURN {
    // �ɹ�����
    PU_H265D_OK = 0,              // �������óɹ�
    PU_H265D_NEED_MORE_BITS = 1,  // �������óɹ�������Ҫ����bit���������һ֡
    PU_H265D_FIND_NEW_PIC = 2,

    // ���淵���룺
    PU_H265D_NAL_HEADER_WARNING = 0x00000004,   // NALͷ����澯
    PU_H265D_VPS_WARNING = 0x00000008,          // VPS����澯
    PU_H265D_SPS_WARNING = 0x00000010,          // SPS����澯
    PU_H265D_PPS_WARNING = 0x00000020,          // PPS����澯
    PU_H265D_SLICEHEADER_WARNING = 0x00000040,  // SliceHeader����澯
    PU_H265D_SLICEDATA_WARNING = 0x00000080,    // SliceData����澯

    // һ�����
    PU_H265D_INVALID_ARGUMENT = 0xF0401000,  // ������ββ���ȷ
    PU_H265D_DECODER_NOT_CREATE,             // ������δ����

    // ��ʼ������
    PU_H265D_MALLOC_FAIL = 0xF0402000,  // �ڴ����ʧ��
    PU_H265D_INVALID_MAX_WIDTH,         // ����ȳ�����Χ
    PU_H265D_INVALID_MAX_HEIGHT,        // ���߶ȳ�����Χ
    PU_H265D_INVALID_MAX_REF_PIC,       // ���ο�֡��������Χ
    PU_H265D_INVALID_THREAD_CONTROL,    // �Ƿ��߳̿���
    PU_H265D_INVALID_MALLOC_FXN,        // Malloc�ص�����ָ����Ч
    PU_H265D_INVALID_FREE_FXN,          // Free�ص�����ָ����Ч
    PU_H265D_INVALID_LOG_FXN,           // Log�ص�����ָ����Ч
    PU_H265D_STREAMBUF_NULL,            // ��������������bufΪ��
    PU_H265D_INVALID_STREAMBUF_LENGTH,  // ���������������ֽ�������
    PU_H265D_YUVBUF_NULL,               // ���������YUV bufferָ��Ϊ��
    PU_H265D_YUVBUF_ADDR_NOT_ALIGN_16,  // ���������YUV buffer addressδ16�ֽڶ���
    PU_H265D_POSTPROCESS_ERR,           // ������ѡ�����
    PU_H265D_ERRCONCEAL_ERR,            // �������ز������ô���

    // �������
    PU_H265D_NAL_HEADER_ERR = 0xF0404001,   // NALͷ�������
    PU_H265D_VPS_ERR = 0xF0404002,          // VPS�������
    PU_H265D_SPS_ERR = 0xF0404003,          // SPS�������
    PU_H265D_PPS_ERR = 0xF0404004,          // PPS�������
    PU_H265D_SLICEHEADER_ERR = 0xF0404005,  // SliceHeader�������
    PU_H265D_SLICEDATA_ERR = 0xF0404006,    // SliceData�������

    // ���뾯��
    PU_H265D_FRAME_DECODE_WARN = 0xE0404007,  // ֡���ݴ��󣬸��������������룬YUV���ͼ������������֤
    PU_H265D_THREAD_ERROR = 0xE0404008        // ���̴߳��� lcc

} PU_H265D_RETURN_E;

// �߳�����
typedef enum PU_H265D_THREADTYPE {
    PU_H265D_SINGLE_THREAD = 0,  // ���߳�
    PU_H265D_MULTI_THREAD        // ���߳�
} PU_H265D_THREADTYPE_E;

// �����
typedef enum PU_H265D_OUTPUTORDER {
    PU_H265D_DECODE_ORDER = 0,  // �����������
    PU_H265D_DISPLAY_ORDER      // ����ʾ�����
} PU_H265D_OUTPUTORDER_E;

// �û�����
typedef struct PU_H265D_USERDATA {
    UINT uiUserDataType;             /* �û��������� */
    UINT uiUserDataSize;             /* �û����ݳ��� */
    UCHAR *pucData;                  /* �û����ݻ����� */
    struct PU_H265D_USERDATA *pNext; /* ָ����һ���û����� */
} PU_H265D_USERDATA_S;

// LOG�ȼ�
typedef enum PU_VIDEO_ALG_LOG_LEVEL {
    PU_VIDEO_ALG_LOG_ERROR = 0,  // ����ʱ��LOG��Ϣ
    PU_VIDEO_ALG_LOG_WARNING,    // ����ʱ��LOG��Ϣ
    PU_VIDEO_ALG_LOG_INFO,       // ��ӡ�ĸ�����Ϣ
    PU_VIDEO_ALG_LOG_DEBUG       // ��ӡ�ĵ�����Ϣ�����ڿ�����Ա����

} PU_VIDEO_ALG_LOG_LEVEL;

/* Ԫ����������࣬����Ԫ�������ط��� */
typedef enum PU_METADATA_REQUEST_TYPE {
    PU_METADATA_REQUEST_COMMON = 0,  // ������Ԫ��������
    PU_METADATA_REQUEST_REST = 1,    // ֻ���������Ϣ
    PU_METADATA_REQUEST_OTHERS = 2,  // ��ȥ������Ϣ��������Ϣ
    PU_METADATA_REQUEST_MAX,
} PU_METADATA_REQUEST_TYPE_E;

/******************************************************************************
* ˵��   :  �ڴ����ص���������
* ����   :  uiChannelID - [in] ͨ��ID
*                  uiSize      - [in] �ڴ��С
* ����ֵ :  �ɹ������ڴ��ַ
*                     ʧ�ܷ���NULL
*******************************************************************************/
typedef void *(*PU_VIDEO_ALG_MALLOC_FXN)(UINT uiChannelID, UINT uiSize);

/******************************************************************************
* ˵��   :  �ڴ��ͷŻص���������
* ����   :  uiChannelID - [in] ͨ��ID
*                  pMem          - [in] �ڴ��ַ
* ����ֵ :  ��
*******************************************************************************/
typedef void (*PU_VIDEO_ALG_FREE_FXN)(UINT uiChannelID, void *pMem);

/******************************************************************************
* ˵��   :  ��־�ص���������
* ����   :  uiChannelID - [in]  ͨ��ID
*                  eLevel         - [in] ������־����
*                  pszMsg        - [in] ��־������(�ַ���)
*                  ...               - [in] �ɱ����
* ����ֵ :  ��
*******************************************************************************/
typedef void (*PU_VIDEO_ALG_LOG_FXN)(UINT uiChannelID, PU_VIDEO_ALG_LOG_LEVEL eLevel, CHAR *pszMsg, ...);

// H265��������ʼ������
typedef struct PU_H265D_INIT_PARAM {
    UINT uiChannelID;                      // ͨ��ID�����ڱ�ʶͨ����Ϣ
    INT iMaxWidth;                         // �����
    INT iMaxHeight;                        // ���߶�
    INT iMaxRefNum;                        // ���ο�֡��
    PU_H265D_THREADTYPE_E enThreadType;    // �߳�����  TODO����ʱ��֧�ֶ��̣߳���������Ӷ����̻߳��ַ�ʽ��tile��Slice��LCU�У�
    PU_H265D_OUTPUTORDER_E enOutputOrder;  // ���˳��  TODO������DecodeFrame��Ч��DecodeAU��Ч
    PU_H265D_USERDATA_S *pstUserData;      // �û�����
    PU_VIDEO_ALG_MALLOC_FXN MallocFxn;     // �ڴ����ص�
    PU_VIDEO_ALG_FREE_FXN FreeFxn;         // �ڴ��ͷŻص�
    PU_VIDEO_ALG_LOG_FXN LogFxn;           // ��־����ص�����
    CHAR szReserved[PU_RESERVE_LEN];       // Ԥ���ֶ�
} PU_H265D_INIT_PARAM_S;

// H265����ģʽ
typedef enum PU_H265D_DECODEMODE {
    PU_H265D_DECODE = 0,  // ��������
    PU_H265D_DECODE_END   // ������ϲ�Ҫ��������������ͼ��
} PU_H265D_DECODEMODE_E;

// H265�����������
typedef struct PU_H265DEC_INARGS {
    UCHAR *pStream;                      // ������֡��ַ
    UINT uiStreamLen;                    // ������֡����
    ULONGLONG uiTimeStamp;               // ʱ���
    PU_H265D_DECODEMODE_E enDecodeMode;  // ����ģʽ
    CHAR szReserved[PU_RESERVE_LEN];     // Ԥ���ֶ�
} PU_H265DEC_INARGS_S;

// H265֡����
typedef enum PU_H265D_FRAMETYPE {
    PU_H265D_FRAME_I = 0,  // I֡
    PU_H265D_FRAME_P,      // P֡
    PU_H265D_FRAME_B,      // B֡
    PU_H265D_FRAME_UNKNOWN
} PU_H265D_FRAMETYPE_E;

// H265��������
typedef enum PU_H265D_DECODESTATUS {
    PU_H265_DEC_GETDISPLAY = 0,  // �Ѿ������һ֡���������������ʾ
    PU_H265_DEC_NEED_MORE_BITS,  // ������û��ͼ���������Ҫ���������
    PU_H265_DEC_NO_PICTURE,      // ������ϣ��Ѿ����ȫ��ͼ��
    PU_H265_DEC_ERR_HANDLE       // �������
} PU_H265D_DECODESTATUS_E;

// ÿ֡ͼ�����CU ������Ϣ
typedef struct PU_CU_OUTPUT_INFO {
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
} PU_CU_OUTPUT_INFO_S;

// H265�����������
typedef struct PU_H265DEC_OUTARGS {
    UINT uiChannelID;                        // ͨ��ID
    UINT uiBytsConsumed;                     // ���ĵ��ֽ���
    ULONGLONG uiTimeStamp;                   // ʱ���
    PU_H265D_FRAMETYPE_E enFrameType;        // ֡����
    PU_H265D_DECODESTATUS_E enDecodeStatus;  // ������״̬
    UINT uiDecWidth;                         // ͼ���
    UINT uiDecHeight;                        // ͼ���
    UINT uiYStride;                          // Y����stride
    UINT uiUVStride;                         // U/V����stride
    UCHAR *pucOutYUV[3];                     // YUV��ַ�����δ��YUV
    UINT uiCodingBytesOfCurFrm;              // ԭʼ��������
    PU_H265D_USERDATA_S stUserData;          // �û�����
    UINT uiAspectRatioIdc;                   // ���α���Ϣ
    UINT uiSarWidth;                         // ���αȿ�ȣ���uiAspectRatioIdc Ϊ255ʱ��Ч
    UINT uiSarHeight;                        // ���αȸ߶ȣ���uiAspectRatioIdc Ϊ255ʱ��Ч
    UINT uiVpsNumUnitsInTick;                // ֡����Ϣ
    UINT uiVpsTimeScale;                     // ֡����Ϣ
    PU_CU_OUTPUT_INFO_S stCuOutInfo;         // �����ǰ֡��Ϣ, ����һ֡�и�������CU�ĸ���
    INT iIsError;                            // ֡�����־��0:�޴�1:�д�
} PU_H265DEC_OUTARGS_S;

/* �Զ���Ȧ���� */
typedef struct PU_AUTO_APERTURE_PARA {
    ULONG ulChannelId;                // ͨ����
    BOOL bEnable;                     // ����ģʽ��0���򿪡�1���ر�
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_AUTO_APERTURE_PARA_S, *LPPU_AUTO_APERTURE_PARA;

// ROI���β����ṹ��
typedef struct PU_ROI_AREA_INFO {
    LONG lQuality;   // ͼ��������
    ULONG ulPointX;  // ROI����X����
    ULONG ulPointY;  // ROI����Y����
    ULONG ulWidth;   // ROI������
    ULONG ulHeight;  // ROI����߶�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ROI_AREA_INFO_S, *LPPU_ROI_AREA_INFO_S;

// ROI�����ṹ��
typedef struct PU_ROI_INFO {
    ULONG ulChannelId;                                      // ͨ��ID
    PU_STREAM_TYPE_E enStreamId;                            // ����ID
    LONG lEnable;                                           // ʹ��
    ULONG ulROINum;                                         // ��Ч��ROI������Ŀ
    PU_ROI_AREA_INFO_S stROIAreaInfo[PU_ROI_AREA_NUM_MAX];  // ROI���β���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ROI_INFO_S, *LPPU_ROI_INFO_S;

// ��ȦУ���ṹ��
typedef struct PU_IRIS_EMENDATION {
    ULONG ulChannelId;                  // ͨ��ID
    PU_LANGUAGE_TYPE_E enLanguageType;  // ��������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_IRIS_EMENDATION_S, *LPPU_IRIS_EMENDATION_S;

// ý��˿���Ϣ
typedef struct PU_PORT_INFO {
    ULONG ulInterLeavedPort;  // ��֯�˿�
    ULONG ulVideoRtpPort;     // ��ƵRTP�˿�
    ULONG ulVideoRtcpPort;    // ��ƵRTCP�˿�
    ULONG ulAudioRtpPort;     // ��ƵRTP�˿�
    ULONG ulAudioRtcpPort;    // ��ƵRTCP�˿�
    ULONG ulIgtRtpPort;       // ����RTP�˿�
    ULONG ulIgtRtcpPort;      // ����RTCP�˿�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PORT_INFO_S, *LPPU_PORT_INFO_S;

// ʵ������ṹ��
typedef struct PU_SAVE_REALDATA_INFO {
    CHAR szFilePath[PU_SAVE_FILE_PATH_MAX];  // �ļ�����·��
    PU_SAVE_REALDATA_TYPE_E enSaveType;      // ���淽ʽ
    ULONG ulSaveSize;                        // �����ļ���С����¼�񳤶�(����enSaveType�ж�)
} PU_SAVE_REALDATA_INFO_S, *LPPU_SAVE_REALDATA_INFO_S;

// ����ͼƬ�ṹ��
typedef struct PU_SAVE_PICTURE_INFO {
    CHAR szFilePath[PU_SAVE_FILE_PATH_MAX];  // �ļ�����·��+�ļ���
    PU_SAVE_PICTURE_TYPE_E enSavePicType;    // ���淽ʽ
} PU_SAVE_PICTURE_INFO_S, *LPPU_SAVE_PICTURE_INFO_S;

// Ѳ���켣����Ϣ
typedef struct PU_CRUISE_POINT {
    ULONG ulPresetIndex;  // Ԥ��λ���к�
    ULONG ulDwellTime;    // Ԥ��λͣ��ʱ��(15-3600s)
    ULONG ulSpeed;        // �ٶȵȼ�,1:�� 2:�� 3:��
} PU_CRUISE_POINT_S, *LPPU_CRUISE_POINT_S;

// Ѳ���켣��Ϣ
typedef struct PU_PTZ_CRUISE_TRACK_PARA {
    ULONG ulPtzId;                                             // ��̨���
    ULONG ulCruiseTrackIndex;                                  // Ѳ���켣���
    ULONG ulCruiseType;                                        // Ѳ��ģʽ��1���켣ɨ�裬2������ɨ�裩
    CHAR szCuriseTrackName[PU_PTZ_CRUISE_LEN];                 // Ѳ���켣����
    ULONG ulPointNum;                                          // �켣�����
    PU_CRUISE_POINT_S stCruisePoint[PU_PTZ_CRUISE_POINT_MAX];  // �켣���б�
    PU_PTZ_CRUISE_TRACK_E enPtzCruiseTrack;                    // Ѳ���켣����������
} PU_PTZ_CRUISE_TRACK_PARA_S, *LPPU_PTZ_CRUISE_TRACK_PARA_S;

// ������Ϣ
typedef struct PU_SQUARE_PARA {
    ULONG ulX;
    ULONG ulY;
} PU_SQUARE_PARA_S, *LPPU_SQUARE_PARA_S;

// ����������Ϣ
typedef struct PU_AREA_INFO {
    ULONG ulStartX;  // �������Ͻ�X
    ULONG ulStartY;  // �������Ͻ�Y
    ULONG ulWidth;
    ULONG ulHeight;
} PU_AREA_INFO_S, *LPPU_AREA_INFO_S;

/* OSDλ��(����) */
typedef enum PU_OSD_POSITION {
    OSD_TOP_LEFT,
    OSD_TOP_RIGHT,
    OSD_BOTTOM_LEFT,
    OSD_BOTTOM_RIGHT,
    OSD_CUSTOMIZE,  // Ԥ��
    OSD_OSD_LOCATION_MAX
} PU_OSD_POSITION_E;

/* OSDλ�ú���ɫ���� */
typedef struct PU_OSD_INFO {
    ULONG ulStartX;
    ULONG ulStartY;
    ULONG ulTextColor;                  // ������ɫ 0x00RGB
    PU_COLOR_TYPE_E enBackgroundColor;  // ������ɫ
    PU_ALPHA_TYPE_E enBackgroundAlpha;  // ������͸����
    CHAR szReserve[2];                  // ��[0]λ��ʶ�Ƿ�ɫ(0����ɫ,1��ɫ)
    // ��[1]λ��ʶOSD����(������OSD����ģʽenAlignMode���Զ���ģʽ:0С��,1�к�,2���, ����ģʽ:3�����׼��4����С��)
    ULONG ulLength;                     // OSD������
    PU_OSD_POSITION_E enOSDPosition;    // OSDλ��
    CHAR szReserveSub[PU_RESERVE_LEN - 2 - sizeof(ULONG) - sizeof(PU_OSD_POSITION_E)];
} PU_OSD_INFO_S, *LPPU_OSD_INFO_S;

/* OSD�ַ������� */
typedef struct PU_OSD_STRING_PARA {
    BOOL bEnable;  // ʹ�����
    PU_OSD_INFO_S stOSDInfo;
    ULONG ulStringLen;                 // �ַ�������
    CHAR szString[PU_OSD_STRING_LEN];  // �ַ�������
} PU_OSD_STRING_PARA_S, *LPPU_OSD_STRING_PARA_S;

/* OSDʱ����� */
typedef struct PU_OSD_DATETIME_PARA {
    BOOL bShowWeekday;                  // �Ƿ���ʾ����
    BOOL bDateEnable;                   // ʱ��ʹ�����
    PU_OSD_DATE_TYPE_E enDateType;      // ���ڸ�ʽ
    PU_LANGUAGE_TYPE_E enLanguageType;  // OSD��ʾ����������: 0:�������� 1:Ӣ��
    PU_OSD_INFO_S stOsdPara;            // λ�ü���ɫ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_OSD_DATETIME_PARA_S, *LPPU_OSD_DATETIME_PARA_S;

/* OSDģʽ(����) */
typedef enum PU_OSD_ALIGN_TYPE {
    PU_ALIGN_CUSTOMIZE = 0,  // �Զ���ģʽ
    PU_ALIGN_GAT_7512008,    // ����ģʽ
    PU_ALIGN_BUTT,
} PU_OSD_ALIGN_TYPE_E;

/* OSD���� */
typedef struct PU_OSD_STRING_ARRAY {
    ULONG ulChannelID;                                     // ͨ��ID
    PU_OSD_DATETIME_PARA_S stOsdDateTimePara;              // OSDʱ�����
    ULONG ulOSDStringNum;                                  // ��Ч���ַ�������(����)
    PU_OSD_STRING_PARA_S szStringPara[PU_OSD_STRING_NUM];  // OSD�ַ�������
} PU_OSD_PARTICULAR_PARA_S, *LPPU_OSD_PARTICULAR_PARA_S;

/* OSD�������� */
typedef struct PU_OSD_STRING_ARRAY_EX_OUT {
    ULONG ulChannelID;                         // ͨ��ID
    PU_OSD_DATETIME_PARA_S stOsdDateTimePara;  // OSDʱ�����
    ULONG ulOSDStringNum;                      // ��Ч���ַ�������
    PU_OSD_STRING_PARA_S *pszStringPara;       // OSD�ַ�������ָ��
} PU_OSD_PARTICULAR_PARA_EX_OUT_S, *LPPU_OSD_PARTICULAR_PARA_EX_OUT_S;

/* OSD������������ģʽ��߾� */
typedef struct PU_OSD_STRING_ARRAY_EX3_OUT {
    ULONG ulChannelID;                         // ͨ��ID
    PU_OSD_DATETIME_PARA_S stOsdDateTimePara;  // OSDʱ�����
    ULONG ulOSDStringNum;                      // ��Ч���ַ�������
    PU_OSD_STRING_PARA_S *pszStringPara;       // OSD�ַ�������ָ��
    PU_OSD_ALIGN_TYPE_E enAlignMode;           // OSD����ģʽ(�Զ���/����)
    ULONG ulGatMarginLen;                      // OSD����߾���,�ַ�����(����ģʽOSD�������߾�ϲ�Ϊһ���ӿ��·�)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_OSD_PARTICULAR_PARA_EX3_OUT_S, *LPPU_OSD_PARTICULAR_PARA_EX3_OUT_S;

/* ͼƬOSD �����ṹ�� */
typedef struct PU_OSD_PICTURE_PARA {
    ULONG ulChannelID;
    BOOL bEnable;                               // ʹ�����
    PU_AREA_INFO_S stAreaInfo;                  // ͼƬ������Ϣ
    CHAR szPicFileName[PU_SAVE_FILE_PATH_MAX];  // ͼƬ��·��������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_OSD_PICTURE_PARA_S, *LPPU_OSD_PICTURE_PARA_S;

// ��˽��������
typedef struct PU_MASK_PARA {
    ULONG ulStartX;  // ��˽�����������Ͻ�X
    ULONG ulStartY;  // ��˽�����������Ͻ�Y
    ULONG ulWidth;
    ULONG ulHeight;
} PU_MASK_PARA_S, *LPPU_MASK_PARA_S;

// ��˽�����б�
typedef struct PU_PRIVACY_MASK_ARRAY {
    ULONG ulChannelID;
    ULONG ulNum;
    BOOL bEnable;
    PU_MASK_PARA_S stMaskPara[PU_PRIVACY_MASK_MAX];
} PU_PRIVACY_MASK_ARRAY_S, *LPPU_PRIVACY_MASK_ARRAY_S;

// ��˽��������
typedef struct PU_MASK_PARA_EX {
    ULONG ulStartX;  // ��˽�����������Ͻ�X
    ULONG ulStartY;  // ��˽�����������Ͻ�Y
    ULONG ulWidth;
    ULONG ulHeight;
    ULONG ulColor;  // ��ɫ
    UCHAR ucAlpha;  // ͸���ȣ��ݲ�֧��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_MASK_PARA_EX_S, *LPPU_MASK_PARA_EX_S;

// ��˽�����б�
typedef struct PU_PRIVACY_MASK_ARRAY_EX {
    ULONG ulChannelID;
    ULONG ulNum;
    BOOL bEnable;
    PU_MASK_PARA_EX_S stMaskParaEx[PU_PRIVACY_MASK_MAX];
    CHAR szReserve[PU_RESERVE_LEN];
} PU_PRIVACY_MASK_ARRAY_EX_S, *LPPU_PRIVACY_MASK_ARRAY_EX_S;

// �¶�
typedef struct PU_TEMPERATURE_PARA {
    LONG lIntTemp;    // ���������¶�ֵ
    ULONG ulDotTemp;  // С�������¶�ֵ
} PU_TEMPERATURE_PARA_S, *LPPU_TEMPERATURE_PARA_S;

// ���ڲ���
typedef struct PU_SERIAL_PORT_PARA {
    ULONG ulSerialPort;                // ���ڱ��
    PU_SERIAL_PORT_MODE_E enPortMode;  // ��������
    PU_BAUD_RATE_E enBaudRate;         // ������
    PU_DATA_BIT_E enDataBit;           // ����λ
    PU_PARITY_BIT_E enParityBit;       // У��λ
    PU_STOP_BIT_E enStopBit;           // ֹͣλ
    PU_FLOW_CONTROL_E enFlowControl;   // ����������
} PU_SERIAL_PORT_PARA_S, *LPPU_SERIAL_PORT_PARA_S;

// ��̨����
typedef struct PU_PTZ_PARA {
    ULONG ulPtzId;                           // ��̨���
    ULONG ulSerialPort;                      // ���ڱ��
    PU_PTZ_DECODER_TYPE_E enDecoderType;     // ����������
    ULONG ulDecoderAddress;                  // ��������ַ
    PU_PTZ_CONTROL_MODE_E enPtzControlMode;  // ��������ģʽ
    BOOL bEnable;                            // �Ƿ�ʹ��
} PU_PTZ_PARA_S, *LPPU_PTZ_PARA_S;

// ͸��ͨ������
typedef struct PU_TRANSPARENT_CMD {
    ULONG ulSerialPort;                             // ���ڱ��
    ULONG ulCmdLen;                                 // ͸��ͨ�������
    CHAR szTransparentCmd[PU_TRANSPARENT_CMD_MAX];  // ͸��ͨ������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_TRANSPARENT_CMD_S, *LPPU_TRANSPARENT_CMD_S;

// ʱ�䣬ʱ���֡��룬24Сʱ��
typedef struct PU_TIME {
    CHAR szYear[PU_TIME_YEAR_LEN];
    CHAR szMonth[PU_TIME_OTHERS_LEN];
    CHAR szDay[PU_TIME_OTHERS_LEN];
    CHAR szHour[PU_TIME_OTHERS_LEN];
    CHAR szMinute[PU_TIME_OTHERS_LEN];
    CHAR szSecond[PU_TIME_OTHERS_LEN];
} PU_TIME_S, *LPPU_TIME_S;

// ����ʱ��
typedef struct PU_ALARM_TIME {
    ULONG ulCycleType;  // ѭ����ʽ��0����ѭ����1��ÿ��ѭ����
    ULONG ulPeriod;     // 0��ÿ�죬1-7�����һ�������
    PU_TIME_S stStart;  // ��ʼʱ��
    PU_TIME_S stEnd;    // ����ʱ��
} PU_ALARM_TIME_S, *LPPU_ALARM_TIME_S;

// ����ʱ���б�
typedef struct PU_ALARM_TIME_PARA_LIST {
    ULONG ulNum;                                     // ����ʱ��θ���
    PU_ALARM_TIME_S stAlarmTime[PU_ALARM_TIME_MAX];  // ����ʱ�������
} PU_ALARM_TIME_LIST_S, *LPPU_ALARM_TIME_LIST_S;

// �¶ȸ澯����
typedef struct PU_TEMPERATURE_ALARM_PARA {
    LONG lEnable;          // ʹ��
    ULONG ulDeteInterval;  // �澯���ʱ����1~256,ÿx����һ���Ƿ��ڸ澯״̬
    LONG lTemperatureMax;  // �澯�����¶�
    LONG lTemperatureMin;  // �澯�����¶�
} PU_TEMPERATURE_ALARM_PARA_S, *LPPU_TEMPERATURE_ALARM_PARA_S;

// �¶ȸ澯��չ����
typedef struct PU_TEMPERATURE_ALARM_PARA_V2 {
    ULONG ulChannelId;     // ͨ��ID
    LONG lEnable;          // ʹ��
    ULONG ulDeteInterval;  // �澯���ʱ����1~256,ÿx����һ���Ƿ��ڸ澯״̬
    LONG lTemperatureMax;  // �澯�����¶�
    LONG lTemperatureMin;  // �澯�����¶�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_TEMPERATURE_ALARM_PARA_V2_S, *LPPU_TEMPERATURE_ALARM_PARA_V2_S;
// ������(����)�澯����
typedef struct PU_INPUT_ALARM_PARA {
    ULONG ulDeviceId;              // �澯�豸ID
    CHAR szName[PU_DIO_NAME_LEN];  // �澯�豸����
    LONG lEnable;                  // ʹ��
    ULONG ulType;                  // ���������գ�0��������1������
    ULONG ulDeteInterval;          // �澯���ʱ����1~256,ÿx����һ���Ƿ��ڸ澯״̬
    PU_ALARM_TIME_LIST_S stAlarmTimeList;
} PU_INPUT_ALARM_PARA_S, *LPPU_INPUT_ALARM_PARA_S;

// �ƶ����/��Ƶ�ڵ����β���
typedef struct PU_DETECTION_AREA {
    ULONG ulNum;                                   // �����θ���
    PU_MASK_PARA_S stMaskPara[PU_ALARM_AREA_MAX];  // ���β���
} PU_DETECTION_AREA_S, *LPPU_DETECTION_AREA_S;

// �ƶ����澯����
typedef struct PU_MOTION_DETECTION_PARA {
    ULONG ulChannelId;                     // ��Ƶͨ��ID
    LONG lEnable;                          // ʹ��
    ULONG ulInterval;                      // ����¼����1~30s���ڸü���ڵ��˶�����Ϊͳһ�˶�
    ULONG ulSensitivity;                   // �˶����������1~5������Խ��Խ����
    ULONG ulDeteInterval;                  // �澯���ʱ����1~256��ÿx����һ���Ƿ��ڸ澯״̬
    PU_DETECTION_AREA_S stDetectionArea;   // �澯�������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
} PU_MOTION_DETECTION_PARA_S, *LPPU_MOTION_DETECTION_PARA_S;

// ��Ƶ�ڵ��澯����
typedef struct PU_HIDE_ALARM_PARA {
    ULONG ulChannel;                       // ��Ƶͨ��ID
    LONG lEnable;                          // �澯ʹ��
    ULONG ulDeteInterval;                  // �澯���ʱ����1~255s��ÿx����һ���Ƿ��ڸ澯״̬
    ULONG ulSensitivity;                   // �˶����������1~5������Խ��Խ����
    PU_DETECTION_AREA_S stDetectionArea;   // �澯�������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
} PU_HIDE_ALARM_PARA_S, *LPPU_HIDE_ALARM_PARA_S;

// ���ּ���
typedef struct PU_INVADE_POINT {
    ULONG ulPosX;  // ��X������(0-352)
    ULONG ulPosY;  // ��Y������(0-288)
} PU_INVADE_POINT_S, *LPPU_INVADE_POINT_S;

// ���ּ����
typedef struct PU_INVADE_LINE {
    ULONG ulDirection;               // ��ⷽ��0��˫��1�������ң�2��������
    PU_INVADE_POINT_S stStartPoint;  // �������ʼ��
    PU_INVADE_POINT_S stEndPoint;    // ����ߵ��յ�
} PU_INVADE_LINE_S, *LPPU_INVADE_LINE_S;

// ���ּ�����б�
typedef struct PU_INVADE_LINE_LIST {
    ULONG ulLineNum;                                  // ��������Ч����
    PU_INVADE_LINE_S stLine[PU_INVADE_LINE_NUM_MAX];  // ������
} PU_INVADE_LINE_LIST_S, *LPPU_INVADE_LINE_LIST_S;

// ���ּ�����
typedef struct PU_INVADE_PARA {
    LONG lEnable;                      // ʹ��
    ULONG ulSensitivity;               // ������
    ULONG ulDeteInterval;              // �澯���ʱ����1~255s��ÿx����һ���Ƿ��ڸ澯״̬
    ULONG ulMiniSize;                  // Ŀ����С�ߴ�(5-20)
    ULONG ulMaxSize;                   // Ŀ�����ߴ�(10-30)
    PU_INVADE_LINE_LIST_S stLineList;  // ���ּ�����б�
} PU_INVADE_PARA_S, *LPPU_INVADE_PARA_S;

// ���ּ��澯����
typedef struct PU_INVADE_ALARM_PARA {
    ULONG ulChannel;                       // ��Ƶͨ��ID
    PU_INVADE_PARA_S stInvadePara;         // ���ּ�����
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
} PU_INVADE_ALARM_PARA_S, *LPPU_INVADE_ALARM_PARA_S;

// Ŀ���������
typedef struct PU_COUNT_PARA {
    LONG lEnable;          // ʹ��
    ULONG ulSensitivity;   // ������
    ULONG ulDeteInterval;  // �澯���ʱ����1~255s��ÿx����һ���Ƿ��ڸ澯״̬
    ULONG ulMiniSize;      // Ŀ����С�ߴ�
    BOOL bOrientation;     // ʶ��ģʽ���ã�0��ˮƽ��1����ֱ��
    ULONG ulDirection;     // ��ⷽ��0��˫��1������A������B��2������B������A��
} PU_COUNT_PRAR_S, *LPPU_COUNT_PARA_S;

// Ŀ������澯����
typedef struct PU_COUNT_ALARM_PARA {
    ULONG ulChannelId;                     // ��Ƶͨ��ID
    PU_COUNT_PRAR_S stCountPara;           // Ŀ���������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
} PU_COUNT_ALARM_PARA_S, *LPPU_COUNT_ALARM_PARA_S;

// ���ż�����
typedef struct PU_DISTURB_PARA {
    LONG lEnable;          // ʹ��
    ULONG ulSensitivity;   // ������
    ULONG ulResetTime;     // ��������ӳ�(1~5S)
    ULONG ulDeteInterval;  // �澯���ʱ����1~255s��ÿx����һ���Ƿ��ڸ澯״̬
} PU_DISTURB_PARA_S, *LPPU_DISTURB_PARA_S;

// ���ż��澯����
typedef struct PU_DISTURB_ALARM_PARA {
    ULONG ulChannelId;                     // ��Ƶͨ��ID
    PU_DISTURB_PARA_S stDisturbPara;       // ���ż�����
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
} PU_DISTURB_ALARM_PARA_S, *LPPU_DISTURB_ALARM_PARA_S;

// ��Ƶ������
typedef struct PU_AUDIO_DECT_PARA {
    BOOL bEnable;                    // ʹ��
    ULONG ulSensitivity;             // ������
    CHAR szReserve[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_AUDIO_DECT_PARA_S;

// ��Ƶ���澯����
typedef struct PU_AUDIO_DECT_ALARM_PARA {
    ULONG ulChannelId;                     // ͨ����
    PU_AUDIO_DECT_PARA_S stAudioDectPara;  // ��Ƶ������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
} PU_AUDIO_DECT_ALARM_PARA_S;

// ��Ƶ�����澯����
typedef struct PU_AUDIO_UP_ALARM_PARA {
    ULONG ulChannelId;                     // ͨ����
    BOOL bEnable;                          // ʹ��
    ULONG ulSensitivity;                   // ������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
} PU_AUDIO_UP_ALARM_PARA_S;

// ��Ƶ�����澯����
typedef struct PU_AUDIO_DOWN_ALARM_PARA {
    ULONG ulChannelId;                     // ͨ����
    BOOL bEnable;                          // ʹ��
    ULONG ulSensitivity;                   // ������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
} PU_AUDIO_DOWN_ALARM_PARA_S;

// ��������
typedef struct PU_GUARD_PARA {
    ULONG ulDeviceId;  // �豸ID��0-���и澯�豸
    ULONG ulState;     // ������0��������1
} PU_GUARD_PARA_S, *LPPU_GUARD_PARA_S;

typedef struct PU_GUARD_STATE {
    PU_GUARD_PARA_S szChannelStateList[PU_CAMERA_NUM_MAX];  // ��ͷ����״̬,ulDeviceId=0Ϊ��Ч
    PU_GUARD_PARA_S szInputStateList[PU_DIO_NUM_MAX];       // �����豸�澯״̬,ulDeviceId=0Ϊ��Ч
    CHAR szReserve[PU_RESERVE_LEN];
} PU_GUARD_STATE_S, *LPPU_GUARD_STATE_S;

// �豸ϵͳʱ��ṹ��
typedef struct PU_SYSTEM_TIME {
    PU_TIME_S stSystime;  // UTCʱ��
    LONG lTimeZone;       // ʱ������������
    ULONG ulDotTimeZone;  // ʱ����С������
	ULONG ulChannelID;   // ͨ����101,��ͼ�豸����ȡʱͨ���ţ�101��2001��2002������ʱͨ���ţ�2000��
    CHAR  isRtc;         // �ڲ�ʹ�ã�����ʹ�ã�������������
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)-sizeof(CHAR)];
} PU_SYSTEM_TIME_S, *LPPU_SYSTEM_TIME_S;

typedef struct PU_PTZ_ACTION {
    BOOL bPresetFlag;
    ULONG ulPresetIndex;
    BOOL bCruiseFlag;
    ULONG ulCruiseIndex;
} PU_PTZ_ACTION_S, *LPPU_PTZ_ACTION_S;

// ��̨Ԥ��λ
typedef struct PU_PTZ_PRESET_PARA {
    ULONG ulChannelId;                   // ͨ��ID
    CHAR szPresetName[PU_PTZ_NAME_LEN];  // Ԥ��λ����
    ULONG ulIndex;                       // Ԥ��λ����
    PU_PTZ_PRESET_CMD_E enPresetCmd;     // Ԥ��λ������
} PU_PTZ_PRESET_PARA_S, *LPPU_PTZ_PRESET_PARA_S;

// ��̨Ԥ��λ(�����۽�����ʹ�ܿ���)
typedef struct PU_PTZ_PRESET_PARA_EX {
    ULONG ulChannelId;                   // ͨ��ID
    CHAR szPresetName[PU_PTZ_NAME_LEN];  // Ԥ��λ����
    ULONG ulIndex;                       // Ԥ��λ����
    PU_PTZ_PRESET_CMD_E enPresetCmd;     // Ԥ��λ������
    BOOL bEnableFocusInfo;               // ������۽�����ʹ�ܿ���,0:��ʹ��,1:ʹ��
    CHAR szReserve[PU_RESERVE_LEN];      // Ԥ����
} PU_PTZ_PRESET_PARA_EX_S, *LPPU_PTZ_PRESET_PARA_EX_S;

// Ԥ��λ��Ϣ
typedef struct PU_PTZ_PRESET_INFO {
    ULONG ulIndex;
    CHAR szPresetName[PU_PTZ_NAME_LEN];
} PU_PTZ_PRESET_INFO_S, *LPPU_PTZ_PRESET_INFO_S;

// Ԥ��λ��Ϣ�������۽�����ʹ�ܿ��أ�
typedef struct PU_PTZ_PRESET_INFO_EX {
    ULONG ulIndex;
    CHAR szPresetName[PU_PTZ_NAME_LEN];
    BOOL bEnableFocusInfo;           // ������۽�����ʹ�ܿ���
    CHAR szReserve[PU_RESERVE_LEN];  // Ԥ����
} PU_PTZ_PRESET_INFO_EX_S, *LPPU_PTZ_PRESET_INFO_EX_S;

// ��̨Ԥ��λ�б�
typedef struct PU_PTZ_PRESET_LIST_PARA {
    ULONG ulChannelId;                                        // ͨ��ID
    ULONG ulBeginIndex;                                       // Ԥ��λ��ʼ���
    ULONG ulEndIndex;                                         // Ԥ��λ�������
    ULONG ulTotalNum;                                         // ���ص�Ԥ��λʵ�ʸ���
    PU_PTZ_PRESET_INFO_S stPtzPresetInfo[PU_PTZ_PRESET_NUM];  // Ԥ��λ��Ϣ
} PU_PTZ_PRESET_LIST_PARA_S, *LPPU_PTZ_PRESET_LIST_PARA_S;

// ��̨Ԥ��λ�б� (�����۽�����ʹ�ܿ���)
typedef struct PU_PTZ_PRESET_LIST_PARA_EX {
    ULONG ulChannelId;                                           // ͨ��ID
    ULONG ulBeginIndex;                                          // Ԥ��λ��ʼ���
    ULONG ulEndIndex;                                            // Ԥ��λ�������
    ULONG ulTotalNum;                                            // ���ص�Ԥ��λʵ�ʸ���
    PU_PTZ_PRESET_INFO_EX_S stPtzPresetInfo[PU_PTZ_PRESET_NUM];  // Ԥ��λ��Ϣ
    CHAR szReserve[PU_RESERVE_LEN];                              // Ԥ����
} PU_PTZ_PRESET_LIST_PARA_EX_S, *LPPU_PTZ_PRESET_LIST_PARA_EX_S;

// ��̨����
typedef struct PU_PTZ_CONTROL_PARA {
    ULONG ulChannel;  // ͨ��ID
    ULONG ulOpCode;   // ��̨������,ȡֵ�ο�PU_PTZ_OPCODE_E
    ULONG ulParam1;   // ����1
    ULONG ulParam2;   // ����2
} PU_PTZ_CONTROL_PARA_S, *LPPU_PTZ_CONTROL_PARA_S;

// �澯�ϱ���Ϣ�ṹ
typedef struct PU_ALARM_REPORT {
    ULONG ulDeviceId;             // �澯�豸ID
    PU_ALARM_TYPE_E enAlarmType;  // �澯����
    PU_TIME_S stTime;             // �澯����ʱ��
    PU_ALARM_ACTION_E enAction;   // �澯����/����
    ULONG ulAlarmId;              // �澯ID
    ULONG ulAlarmAreaId;          //�澯����ID  
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_ALARM_REPORT_S, *LPPU_ALARM_REPORT_S;

// NVSƽ̨����
typedef struct PU_PLATFORM_NVS_PARAM {
    CHAR szNvsIp[PU_PLATFORM_INFO_LEN];         // NVS IP��ַ
    ULONG ulNvsPort;                            // NVS�˿�
    CHAR pszDeviceID[PU_PLATFORM_INFO_LEN];     // �豸ID
    CHAR pszLoginName[PU_PLATFORM_INFO_LEN];    // NVS��¼��
    CHAR pszLoginDomain[PU_PLATFORM_INFO_LEN];  // NVS��¼��
    CHAR pszPassword[PU_PLATFORM_INFO_LEN];     // NVS��¼Pwd
    CHAR szReserve[PU_RESERVE_LEN];
} PU_PLATFORM_NVS_PARAM_S, *LPPU_PLATFORM_NVS_PARAM_S;

// IVSƽ̨����
typedef struct PU_PLATFORM_IVS_PARAM_S {
    CHAR szNvsIp[PU_PLATFORM_INFO_LEN];         // IVS IP��ַ
    ULONG ulNvsPort;                            // IVS�˿�
    CHAR pszDeviceID[PU_PLATFORM_INFO_LEN];     // �豸ID
    CHAR pszLoginName[PU_PLATFORM_INFO_LEN];    // IVS��¼��
    CHAR pszLoginDomain[PU_PLATFORM_INFO_LEN];  // IVS��¼��
    CHAR pszPassword[PU_PLATFORM_INFO_LEN];     // IVS��¼Pwd
    CHAR szReserve[PU_RESERVE_LEN];
} PU_PLATFORM_IVS_PARAM_S, *LPPU_PLATFORM_IVS_PARAM_S;

// ǧ����ƽ̨������ַ��������IVS
typedef struct PU_PLATFORM_IVS_PARA {
    BOOL bEnable;
    CHAR szLoginDomain[PU_PLATFORM_INFO_LEN];
    CHAR szLoginName[PU_PLATFORM_INFO_LEN];
    CHAR szDeviceId[PU_PLATFORM_INFO_LEN];
    CHAR szPassword[PU_PLATFORM_INFO_LEN];
    CHAR szProductName[PU_PLATFORM_INFO_LEN];
    CHAR szServerIp[PU_IP4_ADDR_LEN];
    ULONG ulServerPort;
    CHAR szReserve[PU_RESERVE_LEN];
} PU_PLATFORM_IVS_PARA_S, *LPPU_PLATFORM_IVS_PARA_S;

// 28281ƽ̨������ַ
typedef struct PU_PLATFORM_GBT_PARA {
    BOOL bEnable;
    CHAR szLoginDomain[PU_PLATFORM_INFO_LEN];
    CHAR szLoginName[PU_PLATFORM_INFO_LEN];   // �豸ID���¼����ͬ
    CHAR szPlatformId[PU_PLATFORM_INFO_LEN];  // ����������
    CHAR szPassword[PU_PLATFORM_INFO_LEN];
    CHAR szServerIp[PU_IP4_ADDR_LEN];
    ULONG ulServerPort;
    CHAR szReserve[PU_RESERVE_LEN];  // szReserve[0]:��������;
    // szReserve[1]:ƽ̨����,���,0:GB28181-1, 1:GB28181-2;
} PU_PLATFORM_GBT_PARA_S, *LPPU_PLATFORM_GBT_PARA_S;

// 28281ƽ̨������ַ����
typedef struct PU_PLATFORM_GBT_PARA_V2 {
    BOOL bEnable;
    CHAR szLoginDomain[PU_PLATFORM_INFO_LEN];
    CHAR szLoginName[PU_PLATFORM_INFO_EX_LEN];   // ��¼��
    CHAR szDeviceId[PU_PLATFORM_DEVICE_ID_LEN];  // �豸ID
    CHAR szPlatformId[PU_PLATFORM_INFO_LEN];     // ����������
    CHAR szPassword[PU_PLATFORM_INFO_LEN];
    CHAR szServerIp[PU_IP4_ADDR_LEN];
    ULONG ulServerPort;
    CHAR szReserve[PU_RESERVE_LEN];  // szReserve[0]:��������;
    // szReserve[1]:ƽ̨����,���,0:GB28181-1, 1:GB28181-2;
} PU_PLATFORM_GBT_PARA_V2_S, *LPPU_PLATFORM_GBT_PARA_V2_S;

// SDK����ע��ĵ�ַ
typedef struct PU_PLATFORM_SDK_PARA {
    BOOL bEnable;
    PU_SDK_PLATFORM_MODE_E enSdkPlatformMode;
    CHAR szDeviceId[PU_PLATFORM_INFO_LEN];
    CHAR szPlatformIp[PU_IP4_ADDR_LEN];
    ULONG szPlatformPort;
    CHAR szBackupPlatformIp[PU_IP4_ADDR_LEN];
    ULONG szBackupPlatformPort;
    PU_CONNECT_TYPE_E enConnectType;
    ULONG ulMeshIndex;  // ��������
    CHAR szReserve[PU_RESERVE_LEN - sizeof(PU_CONNECT_TYPE_E) - sizeof(ULONG)];
} PU_PLATFORM_SDK_PARA_S, *LPPU_PLATFORM_SDK_PARA_S;

// ONVIF����
typedef struct PU_ONVIF_SWITCH {
    BOOL bEnable;  // ONVIF����
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ONVIF_SWITCH_S, *LPPU_ONVIF_SWITCH_S;

typedef enum PU_ONVIF_VERSION_ENUM {
    ONVIF_VERSION_2_6 = 0,
    ONVIF_VERSION_2_6_1,
    ONVIF_VERSION_MAX
} PU_ONVIF_VERSION_ENUM_E;

/*** ONVIF �汾��Ϣ ***/
typedef struct PU_ONVIF_VERSION_TYPE {
    ULONG ulChannelId;                           // ͨ��ID(Ԥ�����ݲ���)
    PU_ONVIF_VERSION_ENUM_E enOnvifVersionType;  // ONVIF �汾��Ϣ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ONVIF_VERSION_TYPE_S;

// ONVIFPwd����
typedef struct PU_ONVIF_PWD_PARA {
    CHAR szUserName[PU_USER_NAME_LEN];
    CHAR szOldPassword[PU_PASSWORD_LEN];
    CHAR szNewPassword[PU_PASSWORD_LEN];
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ONVIF_PWD_PARA_S, *LPPU_ONVIF_PWD_PARA_S;

// RESTPwd����
typedef struct PU_REST_PWD_PARA {
    CHAR szOperateUserName[PU_USER_NAME_LEN];
    CHAR szOperatePwd[PU_PASSWORD_LEN];
    CHAR szNewPassword[PU_PASSWORD_LEN];
    CHAR szReserve[PU_RESERVE_LEN];
} PU_REST_PWD_PARA_S, *LPPU_REST_PWD_PARA_S;

// GA/T1400 ƽ̨����
typedef struct PU_GAT1400_ENABLE_PARAM {
	ULONG ulChannelID;							// ͨ��ID(Ԥ�����ݲ���)
	BOOL  bEnable;								// ʹ��
	BOOL  bHttpsEnable;							// ����Э������
	BOOL  bAbsPosEnable;						// ��������ʹ��
	CHAR  szDeviceId[PU_PLATFORM_DEVICE_ID_LEN];// ����20λ
	CHAR  szServerDomain[PU_DOMAIN_LEN];		// ƽ̨��ַ
	USHORT usServerPort;						// �˿ں�
	CHAR  szLoginName[PU_CLIENT_USERNAME_LEN];	// 
	CHAR  szPassword[PU_PASSWORD_LEN];
	CHAR   szReserve[PU_RESERVE_LEN];  //
} PU_GAT1400_ENABLE_PARAM_S, *LPPU_GAT1400_ENABLE_PARAM_S;

// �����ϴ��ļ�·���ṹ��
typedef struct PU_UPGRADE_FILE_INFO {
    CHAR cFileNum;                                                      // �ļ���Ŀ,����ļ���Ϊ UPGRADE_FILE_NUM_MAX
    CHAR szFileName[PU_UPGRADE_FILE_NUM_MAX][PU_UPGRADE_FILE_LEN_MAX];  // �ļ�·�����ļ�������һ��ΪuImage,�ڶ���Ϊjffs2���������ĸ�Ϊ��չԤ��
    ULONG ulChannelID;							//��ͼ�������� 2000
	INT nMaxCpu;                                //���CPUռ�� (�ٷ�֮һ)   //����App ��Ч
	INT nMaxMem;                                //����ڴ�ռ��(��λMB)     //����App ��Ч
    CHAR szReserve[PU_RESERVE_LEN-sizeof(ULONG) - 2 * sizeof(INT)];
} PU_UPGRADE_FILE_INFO_S, *LPPU_UPGRADE_FILE_INFO_S;

// �����ص����ݽṹ����ǰֻ����������ļ���С�����ļ���С
typedef struct PU_UPGRADE_CALLBACK {
    ULONG ulCurrentSize;     // ��ǰ�����ļ���С
    ULONG ulTotalSize;       // ��ǰ�ļ��ܴ�С
    ULONG ulCurrentFileNum;  // ��ǰ�����ļ����
    ULONG ulTotalFileNum;    // ��ǰ�ļ��ܸ���
    CHAR szReserve[PU_RESERVE_LEN];
} PU_UPGRADE_CALLBACK_S, *LPPU_UPGRADE_CALLBACK_S;

// ϵͳ��Ϣ�ṹ��
typedef struct PU_SYS_STATUS_INFO {
    FLOAT fCpuOccupancyRate;  // CPUռ����
    ULONG ulMemTotal;         // �豸���ڴ�(KB)
    ULONG ulMemFree;          // �����ڴ�(KB)
    ULONG ulMemBuffer;        // BUFF�ڴ�(KB)
    ULONG ulMemCache;         // CACHE�ڴ�(KB)
    ULONG ulRecvRate;         // �����������byte
    ULONG ulSendRate;         // ���緢������byte
    ULONG ulFlashTotal;       // �ܹ�Flash��С(KB)
    ULONG ulFlashFree;        // ����Flash��С(KB)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_SYS_STATUS_INFO_S, *LPPU_SYS_STATUS_INFO_S;

// ������־ģ��
typedef enum PU_DEBUG_MODEL {
    PU_DEBUG_MODEL_ALL = 0,       // ����ģ��
    PU_DEBUG_MODEL_CONTROL,       // ����ģ��
    PU_DEBUG_MODEL_COMM,          // COMMģ��
    PU_DEBUG_MODEL_RTP,           // RTPģ��
    PU_DEBUG_MODEL_CODEC,         // ����ģ��
    PU_DEBUG_MODEL_PTZ,           // �ƾ�ģ��
    PU_DEBUG_MODEL_ALARM,         // �澯ģ��
    PU_DEBUG_MODEL_WEB,           // webģ��
    PU_DEBUG_MODEL_IQ_IMG,        // IO IMGģ��
    PU_DEBUG_MODEL_ONVIF,         // ONVIFģ��
    PU_DEBUG_MODEL_RECORD = 10,   // ¼��ģ��
    PU_DEBUG_MODEL_RDA,           // RDAģ��
    PU_DEBUG_MOEDL_SDK,           // SDKģ��
    PU_DEBUG_MODEL_DECODER,       // ����ģ��
    PU_DEBUG_MODEL_DISCOVER,      // �豸����ģ��
    PU_DEBUG_MODEL_UPDATE,        // ����ģ��
    PU_DEBUG_MODEL_DAEMON,        // �ػ�ģ��
    PU_DEBUG_MODEL_DRIVER,        // ����ģ��
    PU_DEBUG_MODEL_28181,         // 28181ģ��
    PU_DEBUG_MODEL_NET,           // ����ģ��
    PU_DEBUG_MODEL_GENETEC = 20,  // GENETECģ��
    PU_DEBUG_MODEL_ITGT,          // ����ģ��
    PU_DEBUG_MODEL_SEP,           // SEPģ��
    PU_DEBUG_MODEL_RC,            // RtspClientģ��
    PU_DEBUG_MODEL_RS,            // ������������ģ��
    PU_DEBUG_MODEL_ITGT_ALG,      // �����㷨
    PU_DEBUG_MODEL_REST,          // HTTPRESTģ��
    PU_DEBUG_MODEL_ODS,           // Omni data Structuring����ͼģ��
    PU_DEBUG_MODEL_ITGT_PERF,     // �������ܵ�����Ϣģ��
    PU_DEBUG_MODEL_ITGT_ALG_DET,  // ���ܿ����㷨Ŀ�����Ԫ���ݵķ��͵�����Ϣģ��
    PU_DEBUG_MODEL_END
} PU_DEBUG_MODEL_E;

// ������־����
typedef struct PU_DEBUG_SWITCH {
    ULONG ulChannelID;         // ͨ����
    BOOL bDebugFlag;           // ���Կ���
    PU_DEBUG_MODEL_E enModel;  // ģ��
} PU_DEBUG_SWITCH_S;

// �������ṹ��

// ������ͨ����Ϣ
typedef struct PU_DECODER_CHANNEL_INFO {
    unsigned long ulChannelID;                        // ������ͨ����
    char szChannelName[PU_DEC_CHANNEL_NAME_LEN + 1];  // ������ͨ������
} PU_DECODER_CHANNEL_INFO_S;

// ������Ϣ
typedef struct PU_DECLINK_INFO {
    CHAR szDecVIP[PU_IP6_ADDR_LEN];  // ��ƵIP��ַ
    ULONG ulDecVPort;                // ��Ƶ�˿�
    CHAR szDecAIP[PU_IP6_ADDR_LEN];  // ��ƵIP��ַ
    ULONG ulDecAPort;                // ��Ƶ�˿�
    CHAR chTransProtocol;            // ����Э��: 1:RTP(TCP Client) 2:RTP(UDP) ...  ��Ƶ��Ƶ��������ͬ,��TCPʱ������IP��PORTΪ��Σ���UDPʱ��IP��PORTΪ����
    CHAR chDecFlags;                 // �����־��0 ������Ƶ; 1 ������Ƶ; 2 ͬʱ��,ͬʱ��ʱʹ��VIP��VPORT����
    CHAR chKeepaliveFlags;           // �����־,��VIP/VPort ����RTSP��������: 0 ������,1 ����
    CHAR szRes[PU_RESERVE_LEN];      // Ԥ��,ͨ��sdk����:szRes[0]= 0;sdk�������������ֱ�ӷ���:szRes[0]=1
} PU_DECLINK_INFO_S, *LPPU_DECLINK_INFO_S;

// ������Ϣ�ṹ��
typedef struct PU_DEC_INFO {
    ULONG ulChannelId;                // ͨ��ID
    PU_DECLINK_INFO_S stDecLinkInfo;  // ������Ϣ
} PU_DEC_INFO_S, *LPPU_DEC_INFO_S;

// ��ʼ��������Ӧ�ṹ��
typedef struct PU_INIT_DECODE_INFO_RSP {
    CHAR szDecMediaIp[PU_IP4_ADDR_LEN];  // ��������ý��IP
    PU_PORT_INFO_S stDecPortInfo;        // �������Ķ˿���Ϣ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_INIT_DECODE_INFO_RSP_S, *LPPU_INIT_DECODE_INFO_RSP_S;

// ��������ṹ��
typedef struct PU_START_DECODE_INFO {
    ULONG ulChannelId;                       // ͨ����
    PU_ENCODE_TYPE_E enVideoEncodeType;      // ��Ƶ��������
    PU_ENCODE_TYPE_E enAudioEncodeType;      // ��Ƶ��������
    PU_PROTOCOL_TYPE_E enProtocolType;       // ��ʼ�����봫��Э��
    PU_PORT_INFO_S stLocalPortInfo;          // SDK�Ķ˿���Ϣ
    CHAR szLocalMediaIp[PU_IP4_ADDR_LEN];    // SDK��ý��IP
    CHAR szSessionID[PU_NAT_SESSIONID_LEN];  // �ỰID
    CHAR szSessionUrl[PU_NAT_URL_LEN];       // �ỰURL
    CHAR szReserve[PU_RESERVE_LEN];
} PU_START_DECODE_INFO_S, *LPPU_START_DECODE_INFO_S;

// �������˿�����
typedef struct PU_DEC_PORT_ABILITY {
    CHAR szOutPutModes[PU_PORT_MODE_NUM_MAX];  // 1\2\4\9\16 mode,0 the end
    ULONG ulPortType;                          // 0:Audio, 1:Video 2:both
    BOOL bSupportEnlarge;                      // �˿��Ƿ�֧�ַŴ���ʾ
} PU_DEC_PORT_ABILITY_S, *LPPU_DEC_PORT_ABILITY_S;

// �������˿������б�
typedef struct PU_DEC_PORT_ABILITY_LIST {
    ULONG ulBNCNum;
    ULONG ulVGANum;
    ULONG ulHDMINum;
    ULONG ulDVINum;
    PU_ENCODE_TYPE_E enDecodeType[PU_DECODE_TYPE_MAX];        // ����֧�ֵ�����
    PU_DEC_PORT_ABILITY_S stBNCAttribute[PU_BNC_PORT_MAX];    // ������ͣ�A/V/AV���������ģʽ:����1��2��4��9��16�ȼ���ģʽ��
    PU_DEC_PORT_ABILITY_S stVGAAttribute[PU_VGA_PORT_MAX];    // ������ͣ�A/V/AV���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��
    PU_DEC_PORT_ABILITY_S stHDMIAttribute[PU_HDMI_PORT_MAX];  // ������ͣ�A/V/AV���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��
    PU_DEC_PORT_ABILITY_S stDVIAttribute[PU_DVI_PORT_MAX];    // ������ͣ�A/V/AV���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��**/
} PU_DEC_PORT_ABILITY_LIST_S, *LPPU_DEC_PORT_ABILITY_LIST_S;

// �������˿���Ϣ
typedef struct PU_DEC_PORT_INFO {
    BOOL bEnable;                          // �˿�ʹ��
    PU_PORT_MODE_E enPortMode;             // ͨ��ģʽ
    PU_FRAME_RATE_E enFrameRate;           // ֡��  :30֡|| 60 ֡
    PU_RESOLUTION_TYPE_E enDecResolution;  // ��������ֱ���
    // BOOL bEnlargeFlag;                   //�Ƿ�֧�ַŴ�,0: no support, 1: support
} PU_DEC_PORT_INFO_S, *LPPU_DEC_PORT_INFO_S;

// �������˿���Ϣ�б�
typedef struct PU_DEC_PORT_INFO_LIST {
    ULONG ulBNCNum;
    ULONG ulVGANum;
    ULONG ulHDMINum;
    ULONG ulDVINum;
    PU_ENCODE_TYPE_E enDecodeType;                         // ��������
    PU_DEC_PORT_INFO_S stBNCAttribute[PU_BNC_PORT_MAX];    // ������ͣ�A/V/AV    ���������ģʽ:����1��2��4��9��16�ȼ���ģʽ��
    PU_DEC_PORT_INFO_S stVGAAttribute[PU_VGA_PORT_MAX];    // ������ͣ�A/V/AV    ���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��
    PU_DEC_PORT_INFO_S stHDMIAttribute[PU_HDMI_PORT_MAX];  // ������ͣ�A/V/AV    ���������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��
    PU_DEC_PORT_INFO_S stDVIAttribute[PU_DVI_PORT_MAX];    // ������ͣ�A/V/AV   �� �������ģʽ:����1��2��4��9��16�ȼ���ģʽ���Ŵ�֧�ֱ�־��**/
    // CHAR chSameVInput;                                            //VGA/HDMI/DVI �Ƿ�ͬԴģʽ��0000 0000 ��ͬԴ, 0000 0111  ͬԴ */
    CHAR chRes[PU_RESERVE_LEN];
} PU_DEC_PORT_INFO_LIST_S, *LPPU_DEC_PORT_INFO_LIST_S;

// ͨ����˿ڵ�ӳ���ϵ
typedef struct PU_DEC_CHANNEL_PORT_MAP {
    ULONG ulChannelID;          // ͨ����
    PU_PORT_TYPE_E enPortType;  // �˿�����
    ULONG ulPortIndex;          // �˿�����
    ULONG ulLayoutIndex;        // ͨ�����ڵĲ�������
} PU_DEC_CHANNEL_PORT_MAP_S, *LPPU_DEC_CHANNEL_PORT_MAP_S;

/* ͨ������ :��Ƶ& ��Ƶ */
/* ����������2 ----1 BNC1+D1 1 VGA1||HDMI1 + 1080P
5 ----1 BNC1+D1  4 VGA1||HDMI1 + D1
3 ----1 BNC1+D1  1 VGA1+720P  1 HDMI1+720P   ====   ��ͬԴ
2 ----1 VGA1+720P  1 HDMI1+720P ====   ��ͬԴ */
typedef struct PU_DEC_CHANNEL_ABILITY {
    PU_DEC_CHANNEL_PORT_MAP_S stChannelPortMap;              // ӳ���ϵ
    PU_ENCODE_TYPE_E enVideoDecFormats[PU_DECODE_TYPE_MAX];  // ������Ƶ��ʽ
    PU_ENCODE_TYPE_E enAudioDecFormats[PU_DECODE_TYPE_MAX];  // ������Ƶ��ʽ
    PU_RESOLUTION_TYPE_E enMaxDecResolution;                 // �������ֱ���
    PU_FRAME_RATE_E enMaxFrameRate;                          // ���֡��  :30֡|| 60 ֡
    BOOL bSupportDecryption;                                 // 0: no support 1: support
    BOOL bSupportWaterMark;                                  // 0: no support 1: support
    // BOOL bAudioFlag;                                              //��Ƶ����:һ����������֧��һ·��Ƶ�������һ��ͨ���￪����ԭ�������ͨ�����������ᱻĬ�Ͽ��յ�
} PU_DEC_CHANNEL_ABILITY_S, *LPPU_DEC_CHANNEL_ABILITY_S;

// ͨ�������б�
typedef struct PU_DEC_CHANNEL_ABILITY_LIST {
    ULONG ulChannelNums;                                      // ͨ����
    PU_DEC_CHANNEL_ABILITY_S stChnAttri[PU_CHANNEL_NUM_MAX];  // ͨ������
} PU_DEC_CHANNEL_ABILITY_LIST_S, *LPPU_DEC_CHANNEL_ABILITY_LIST_S;

/* OSDλ�ú���ɫ���� */
typedef struct PU_DEC_OSD_PARA {
    ULONG ulStartX;
    ULONG ulStartY;
    ULONG ulFgColor;  // ������ɫ
    UCHAR ucFgAlpha;  // ǰ��͸����
    UCHAR ucBgAlpha;  // ����͸����
    ULONG ulBgColor;  // ������ɫ
} PU_DEC_OSD_PARA_S, *LPPU_DEC_OSD_PARA_S;

// ������OSD�ַ�����
typedef struct PU_DEC_OSD_STRING_INFO {
    BOOL bEnable;                      // ʹ�����
    ULONG ulStringLen;                 // �ַ�������
    CHAR szString[PU_OSD_MAX_LENGTH];  // �ַ�������
    PU_DEC_OSD_PARA_S stOSDPara;       // OSD������Ϣ
} PU_DEC_OSD_STRING_INFO_S, *LPPU_DEC_OSD_STRING_INFO_S;

// ͨ����Ϣ
typedef struct PU_DEC_CHANNEL_INFO {
    ULONG ulChannelId;                       // ͨ��ID��
    BOOL bDenoiseFlag;                       // ����ʹ��
    BOOL bDemistFlag;                        // ȥ��ʹ��
    BOOL bEnlargeStatus;                     // ͼ��Ŵ�״̬
    PU_DEC_OSD_STRING_INFO_S stOsdTextInfo;  // OSD������Ϣ
} PU_DEC_CHANNEL_INFO_S, *LPPU_DEC_CHANNEL_INFO_S;

// ͨ����Ϣ�б�
typedef struct PU_DEC_CHANNEL_INFO_LIST {
    ULONG ulChannnelNums;                                     // ͨ����
    PU_DEC_CHANNEL_INFO_S stChannelInfo[PU_CHANNEL_NUM_MAX];  // ͨ����Ϣ
} PU_DEC_CHANNEL_INFO_LIST_S, *LPPU_DEC_CHANNEL_INFO_LIST_S;

// ������������Ϣ
typedef struct PU_DEC_DECRYPTION_INFO {
    ULONG ulChannelId;                           // ���ܵ�ͨ����
    BOOL bEnable;                                // ����ʹ��״̬
    PU_ENCRYPT_TYPE_E enDecryptionType;          // �����㷨����
    CHAR szVideoCrypto[PU_CRYPTION_PASSWD_LEN];  // ��Ƶ��Կ
    CHAR szAudioCrypto[PU_CRYPTION_PASSWD_LEN];  // ��Ƶ��Կ
} PU_DEC_DECRYPTION_INFO_S, *LPPU_DEC_DECRYPTION_INFO_S;

// ��������Ƶ�˿���Ϣ
typedef struct PU_DEC_AUDIO_INFO {
    PU_AUDIO_PORT_TYPE_E enAudioPortType;     // ��Ƶ�˿�����
    BOOL bEnable;                             // ��Ƶ�˿�ʹ�����
    ULONG ulChannelId;                        // ��Ƶ�����ͨ����
    PU_ENCODE_TYPE_E enAudioDecodeType;       // ��Ƶ��������
    ULONG ulAudioVolume;                      // ����
    PU_AUDIO_SAMPLERATE_E enAudioSampleRate;  // ��Ƶ������
} PU_DEC_AUDIO_INFO_S, *LPPU_DEC_AUDIO_INFO_S;

typedef struct PU_TIME_PLAN {
    ULONG ulCycle;          // ���ڿ��ƣ�0����һ�Σ�1��ÿ�ܶ�����ʱ���
    ULONG ulPeriod;         // ���ڣ� 0:һ��ȫ�� 1~7:��ʾ����
    PU_TIME_S stStartTime;  // ��ʼʱ��:  UTC ʱ��
    PU_TIME_S stEndTime;    // ����ʱ��:  UTC ʱ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_TIME_PLAN_S, *LPPU_TIME_PALN_S;

/* ͨ��¼��ƻ� */
typedef struct PU_RECORD_PLAN {
    ULONG ulChannelId;
    ULONG ulTotalPlanNum;                                 // �ܼ�¼��
    PU_TIME_PLAN_S szRecordPlanList[PU_RECORD_PLAN_NUM];  // ¼��ƻ�����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_RECORD_PLAN_S, *LPPU_RECORD_PLAN_S;

/* ¼���������� */
typedef enum PU_RECORD_DATA_TYPE {
    PU_RECORD_VIDEO = 0,  // ��Ƶ����
    PU_RECORD_META,       // Ԫ����

    PU_RECORD_DATA_MAX
} PU_RECORD_DATA_TYPE_E;

/* ¼����Ϣ��ѯ */
typedef struct PU_RECORD_INQUIRE {
    ULONG ulChannelId;
    PU_TIME_S stBeginTime;
    PU_TIME_S stEndTime;
    ULONG ulBeginIndex;
    PU_RECORD_TYPE_E enRecordTypeList[PU_RECORD_TYPE_NUM];
    PU_RECORD_DATA_TYPE_E enRecordDataType;
    CHAR szReserved[PU_RESERVE_LEN - sizeof(PU_RECORD_DATA_TYPE_E)];
} PU_RECORD_INQUIRE_S, *LPPU_RECORD_INQUIRE_S;

/* ǰ��¼����Ϣ */
typedef struct PU_RECORD_INFO {
    PU_RECORD_TYPE_E enRecordType;              // ¼������
    PU_TIME_S stBeginTime;                      // ��ʼʱ��
    PU_TIME_S stEndTime;                        // ����ʱ��
    ULONG ulContentSize;                        // ¼���ļ���С
    CHAR szContentID[PU_RECORD_CONTENTID_LEN];  // ¼���ļ���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_RECORD_INFO_S, *LPPU_RECORD_INFO_S;

/* ǰ��¼����Ϣ�б� */
typedef struct PU_RECORD_LIST {
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    PU_RECORD_INFO_S szRecordInfoList[PU_RECORD_INFO_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
} PU_RECORD_LIST_S, *LPPU_RECORD_LIST_S;

/************************�����������������**************************/
typedef struct PU_SWITCH_OUTPUT_PARA {
    ULONG ulOutputId;
    CHAR szOutputName[PU_DIO_NAME_LEN];  // ���ƣ����֧��32�ֽ�
    ULONG ulHoldTime;                    // ����ʱ�� 1-600  Ĭ��10��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SWITCH_OUTPUT_PARA_S, *LPPU_SWITCH_OUTPUT_PARA_S;

/************************���������״̬����**************************/
typedef struct PU_SWITCH_OUTPUT_STATE {
    ULONG ulOutputId;
    ULONG ulSwitchType;  // ����/����= 0������ 1������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SWITCH_DO_STATE_S, *LPPU_SWITCH_DO_STATE_S;

/************************�����������������**************************/
typedef struct PU_SWITCH_INPUT_PARA {
    ULONG ulInputId;
    CHAR szInputName[PU_DIO_NAME_LEN];  // ���ƣ����֧��32�ֽ�
    ULONG ulSwitchType;                 // ����/����= 0������ 1������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SWITCH_INPUT_PARA_S, *LPPU_SWITCH_INPUT_PARA_S;

/************************���������������������**********************/
typedef struct PU_DIO_PARA {
    PU_SWITCH_INPUT_PARA_S stInput[PU_DIO_NUM_MAX];
    PU_SWITCH_OUTPUT_PARA_S stOutput[PU_DIO_NUM_MAX];
	ULONG ulChannelID;									// ͨ����
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_DIO_PARA_S, *LPPU_DIO_PARA_S;

/************************��ǰ�¶Ȳ���**********************/
typedef struct PU_CURRENT_TEMPERATURE {
    ULONG ulChannelId;  // ͨ����
    LONG lCurrentTemp;  // ��ǰ�¶�ֵ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_CURRENT_TEMPERATURE_S, *LPPU_CURRENT_TEMPERATURE_S;

/**************�澯���� ��ͷ��Ϣ**********************/
typedef struct PU_ALARM_LINKAGE_CAMERA_INFO {
    ULONG ulChannelId;
    ULONG ulPreId;
    ULONG ulCruiseId;
    ULONG ulRecord;
    ULONG ulSnap;
    ULONG ulSnapInterval;  // ����ץ�ļ��(����)
    ULONG ulDesignScan;    // 0��Ч  1 2 3 4  5 �ֱ� ����5�� ɨ��켣
    LONG lHorizontalScan;  // 0��Ч  1 ~10    -1 ~ -10 �ֱ� ���������� �ٶ�
    ULONG ulFrameScan;     // 0��Ч  5 ~3600  �ֱ����ɨ����
    ULONG ulRandomScan;    // 0��Ч  5 ~3600  �ֱ����ɨ����
    LONG lPanormaScan;     // 0��Ч  1 ~10    -1 ~ -10 �ֱ� ���������� �ٶ�
    ULONG ulVerticalScan;  // 0��Ч  1 ~10  �ֱ�����ٶ�
    BOOL bMailSend;        // �Ƿ��������ʼ����� 0:������ 1:����
} PU_ALARM_LINKAGE_CAMERA_INFO, *LPPU_ALARM_LINKAGE_CAMERA_INFO;

/*******************�澯�������� ***************************/
typedef struct PU_ALARM_LINKAGE_PARA {
    ULONG ulChannelNum;                                              // ������ͷ����
    ULONG ulDoNum;                                                   // �����������������
    PU_ALARM_LINKAGE_CAMERA_INFO stCameraList[PU_ALARM_CAMERA_MAX];  // ������ͷ��Ϣ�б�
    ULONG szDoIdList[PU_ALARM_DO_MAX];                               // �������������ID
    CHAR szReserved[PU_RESERVE_LEN];                                 // szReserved[0]��ʾ�Ƿ��������ʼ����� 0:������ 1:����
} PU_ALARM_LINKAGE_PARA_S, *LPPU_ALARM_LINKAGE_PARA_S;

// ��ȡǰ���豸��־
typedef struct PU_LOG_REQ_PARA {
    PU_TIME_S stStartTime;
    PU_TIME_S stEndTime;
    ULONG ulStartIndex;
    ULONG ulPrePageNum;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_LOG_REQ_PARA_S, *LPPU_LOG_REQ_PARA_S;

// ��ȡǰ���豸��־��չ
typedef struct PU_LOG_REQ_PARA_EX {
    ULONG ulChannelID;        // ͨ����
    PU_LOG_TYPE_E enLogType;  // ��־����
    PU_TIME_S stStartTime;    // ��ʼʱ��
    PU_TIME_S stEndTime;      // ����ʱ��
    ULONG ulStartIndex;       // ��ʼ����
    ULONG ulPrePageNum;       // ÿ�β�ѯ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_LOG_REQ_PARA_EX_S, *LPPU_LOG_REQ_PARA_EX_S;

typedef struct PU_OPLOG_INFO {
    PU_TIME_S stTime;
    CHAR acUser[PU_USER_NAME_LEN];
    CHAR acDeviceIp[PU_IP4_ADDR_LEN];
    CHAR acOptDetailDes[PU_LOG_INFO_NUM][PU_LOG_INFO_LEN];
    ULONG ulOptObject;
    ULONG ulOptResult;
    ULONG ulRiskLevel;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_OPLOG_INFO_S, *LPPU_OPLOG_INFO_S;

// ǰ����־��Ϣ
typedef struct PU_LOG_INFO {
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    CHAR szLogInfoList[PU_LOG_INFO_NUM][PU_LOG_INFO_LEN];  // ��־���ݣ���ʱ�䡢�ȼ�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_LOG_INFO_S, *LPPU_LOG_INFO_S;

// ǰ����־��Ϣ��չ
typedef struct PU_LOG_INFO_EX {
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    CHAR szTime[PU_LOG_INFO_NUM][PU_LOG_TIME_LEN];     // ��־ʱ��
    CHAR szLevel[PU_LOG_INFO_NUM][PU_LOG_LEVEL_LEN];   // ��־�ȼ�
    CHAR szContent[PU_LOG_INFO_NUM][PU_LOG_INFO_LEN];  // ��־����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_LOG_INFO_EX_S, *LPPU_LOG_INFO_EX_S;

// ʵʱ����ṹ��
typedef struct PU_REAL_PLAY_INFO {
    ULONG ulChannelId;                             // ͨ��ID
    HWND hPlayWnd;                                 // Windows���ھ��
    PU_STREAM_TYPE_E enStreamType;                 // ��������,��������������
    PU_VIDEO_TYPE_E enVideoType;                   // �����ͣ���Ƶ������Ƶ������������¼����
    PU_PROTOCOL_TYPE_E enProtocolType;             // ����Э�����ͣ�UDP,TCP
    PU_MEDIA_CALLBACK_TYPE_E enMediaCallbackType;  // �ص����ͣ�0:RTP���� 1:RTP������  2:Frame 3:YUV
    CHAR szLocalIp[PU_IP4_ADDR_LEN];               // �����IP��������ƽ̨���Բ��SDK���Զ���ȡ
    BOOL bKeepLive;                                // �Ƿ񱣻�
    PU_TIME_S stStartTime;                         // ����Ԥ¼��¼��ʼʱ��
    PU_TIME_S stEndTime;                           // ����Ԥ¼��¼�����ʱ��
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;      // �������ͣ�ֻ֧��AES����
    CHAR szMediaCrypto[PU_CRYPTION_PASSWD_LEN];    // ������Կ
    CHAR szReserved[PU_RESERVE_LEN];               // szReserved[0-15]��ʾ�鲥IP��ַ szReserved[16-19]��ʾ�鲥�˿�
    // szReserved[22]��ʾ���ܷ������ݴ����ʽ 0:XML,1:Ԫ����
    // szReserved[23]��ʾԪ�����������ͣ�ȡֵ�ο�ö��PU_METADATA_REQUEST_TYPE_E
} PU_REAL_PLAY_INFO_S, *LPPU_REAL_PLAY_INFO_S;

typedef struct PU_MEDIA_AES_CBC_ENC_PARA {
    CHAR szKey[PU_MEDIA_ENC_AES_KEY_STR_LEN];  // ������Կ
    CHAR szIv[PU_MEDIA_ENC_AES_CBC_IV_LEN];    // IV
} PU_MEDIA_AES_CBC_ENC_PARA_S;

typedef struct PU_MEDIA_ENC_PARA {
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;  // �������ͣ�Ŀǰ��֧��AES256 CBCģʽ
    VOID *pstEncPara;                          // ָ��������Ͷ�Ӧ�ṹ���ָ��
} PU_MEDIA_ENC_PARA_S;

typedef struct PU_VIDEO_FRAME_INFO {
    PU_VIDEO_FRAME_TYPE_E enFrameType;  // ��Ƶ֡����
    PU_ENCODE_TYPE_E enEncodeType;      // ��Ƶ�����ʽ
    UINT nFrameWidth;                   // ��Ƶ֡���
    UINT nFrameHeight;                  // ��Ƶ֡�߶�
    ULONG ulTimeStamp;                  // ��Ƶ֡ʱ��� 
    CHAR szReserved[PU_RESERVE_EX_LEN]; 
} PU_VIDEO_FRAME_INFO_S;

typedef struct PU_AUDIO_FRAME_INFO {
    PU_ENCODE_TYPE_E enEncodeType;       // ��Ƶ�����ʽ;
    PU_AUDIO_SAMPLERATE_E enSampleRate;  // ��Ƶ������ ;
    PU_AUDIO_G726_BPS_E enBitRate;     // ��Ƶ����
    ULONG ulTimeStamp;                   // ��Ƶ֡ʱ��� 
    CHAR szReserved[PU_RESERVE_EX_LEN]; 
} PU_AUDIO_FRAME_INFO_S;

typedef struct PU_MEDIA_FRAME_INFO {
    PU_FRAME_TYPE_E enFrameType;
    union frameInfo {
      PU_VIDEO_FRAME_INFO_S stVideoFrameInfo;
      PU_AUDIO_FRAME_INFO_S stAudioFrameInfo;
    } unFrameInfo;
    CHAR szReserved[PU_RESERVE_EX_LEN];                         
} PU_MEDIA_FRAME_INFO_S, *LPPU_MEDIA_FRAME_INFO_S;

// ʵʱ����ṹ��
typedef struct PU_REAL_PLAY_INFO_V20 {
    ULONG ulChannelId;                             // ͨ��ID
    HWND hPlayWnd;                                 // Windows���ھ��
    PU_STREAM_TYPE_E enStreamType;                 // ��������:��������������1��������2
    PU_VIDEO_TYPE_E enVideoType;                   // �����ͣ���Ƶ������Ƶ������������¼������Ԫ������
    PU_PROTOCOL_TYPE_E enProtocolType;             // ����Э������: 0:UDP 1:TCP 2:�鲥
    PU_MEDIA_CALLBACK_TYPE_E enMediaCallbackType;  // �ص����ͣ�0:RTP���� 1:RTP������  2:Frame 3:YUV
    CHAR szLocalIp[PU_IP6_ADDR_LEN];               // �����IP��������ƽ̨���Բ��SDK���Զ���ȡ
    BOOL bKeepLive;                                // �Ƿ񱣻�
    PU_TIME_S stStartTime;                         // ����Ԥ¼��¼��ʼʱ��
    PU_TIME_S stEndTime;                           // ����Ԥ¼��¼�����ʱ��
    PU_IGT_DATA_TYPE_E enIGTDataType;              // �������ݸ�ʽ 0:XML��ʽ 1:Ԫ���ݸ�ʽ
    CHAR szMulticastIP[PU_IP6_ADDR_LEN];           // �鲥IP(�鲥����Ҫ�ò���)
    ULONG ulMulticastPort;                         // �鲥�˿�(�鲥����Ҫ�ò���)
    CHAR szReserved[PU_RESERVE_LEN];               // szReserved[0]��ʾԪ�����������ͣ�ȡֵ�ο�ö��PU_METADATA_REQUEST_TYPE_E
} PU_REAL_PLAY_INFO_V20_S, *LPPU_REAL_PLAY_INFO_V20_S;

// �����Խ�/�����㲥�ṹ��
typedef struct PU_VOICE_INFO {
    ULONG ulChannelId;                     // ͨ��ID
    CHAR szLocalAudioIp[PU_IP4_ADDR_LEN];  // ������ƵIP
    BOOL bFeedAudioData;                   // �Ƿ�ι����(�����Խ���TRUEʱ�ص���������Ϊ�գ�FLASEʱ�ص���������Ϊ��)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_VOICE_INFO_S, *LPPU_VOICE_INFO_S;

// ʵʱ����ṹ��
typedef struct PU_MEDIA_PLAY_INFO {
    ULONG ulChannelId;                             // ͨ����
    PU_BUSINESS_TYPE_E enBusinessType;             // ʵʱ����������Խ��������㲥��¼������
    PU_STREAM_TYPE_E enStreamType;                 // ��������������1��������2
    PU_PROTOCOL_TYPE_E enProtocolType;             // TCP��UDP���鲥��ʽ
    PU_VIDEO_CODE_TYPE_E enTansmitType;            // ES��PS��TS
    PU_VIDEO_TYPE_E enVideoType;                   // ��Ƶ������Ƶ����������
    CHAR szLocalIp[PU_IP4_ADDR_LEN];               // �����IP
    PU_PORT_INFO_S stLocalPortInfo;                // ����˵Ķ˿ں�
    ULONG ulLinkMode;                              // �������ͣ�0ֱ�� 1��ת
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;      // ��������
    CHAR szVideoCrypto[PU_CRYPTION_PASSWD_LEN];    // ��Ƶ��Կ
    CHAR szAudioCrypto[PU_CRYPTION_PASSWD_LEN];    // ��Ƶ��Կ
    PU_TIME_S stStartTime;                         // ����Ԥ¼��¼��ʼʱ��
    PU_TIME_S stEndTime;                           // ����Ԥ¼��¼�����ʱ��
    CHAR szSessionIDForNAT[PU_NAT_SESSIONID_LEN];  // ����NAT��Խ��Session
    CHAR szSessionUrl[PU_NAT_URL_LEN];             // ����NAT�ĻỰURL
    CHAR szReserved[PU_RESERVE_LEN];               // szReserved[0]��ʾ�Ƿ񱣻� 0:����,1:������
    // szReserved[1]��ʾ���ܷ������ݴ����ʽ 0:XML,1:Ԫ����
    // szReserved[2]~szReserved[18]��ʾAES256 CBCģʽIVֵ(16�ֽ�+1������)
    // szReserved[20]��ʾ�����Ԫ���ݷ��࣬ȡֵ�μ�ö��PU_METADATA_REQUEST_TYPE_E
} PU_MEDIA_PLAY_INFO_S, *LPPU_MEDIA_PLAY_INFO_S;

// ʵʱ����ṹ��
typedef struct PU_MEDIA_PLAY_INFO_V2 {
    ULONG ulChannelId;                             // ͨ����
    PU_BUSINESS_TYPE_E enBusinessType;             // ʵʱ����������Խ��������㲥��¼������
    PU_STREAM_TYPE_E enStreamType;                 // ��������������1��������2
    PU_PROTOCOL_TYPE_E enProtocolType;             // TCP��UDP���鲥��ʽ
    PU_VIDEO_CODE_TYPE_E enTansmitType;            // ES��PS��TS
    PU_VIDEO_TYPE_E enVideoType;                   // ��Ƶ������Ƶ����������
    CHAR szLocalIp[PU_IP4_ADDR_LEN];               // �����IP
    PU_PORT_INFO_S stLocalPortInfo;                // ����˵Ķ˿ں�
    ULONG ulLinkMode;                              // �������ͣ�0ֱ�� 1��ת
    PU_MEDIA_CRYPTO_TYPE_E enMediaCryptoType;      // ��������
    CHAR szVideoCrypto[PU_CRYPTION_PASSWD_LEN];    // ��Ƶ��Կ
    CHAR szAudioCrypto[PU_CRYPTION_PASSWD_LEN];    // ��Ƶ��Կ
    PU_TIME_S stStartTime;                         // ����Ԥ¼��¼��ʼʱ��
    PU_TIME_S stEndTime;                           // ����Ԥ¼��¼�����ʱ��
    CHAR szSessionIDForNAT[PU_NAT_SESSIONID_LEN];  // ����NAT��Խ��Session
    CHAR szSessionUrl[PU_NAT_URL_LEN];             // ����NAT�ĻỰURL
    CHAR szReserved[PU_RESERVE_LEN];               // szReserved[0]��ʾ�Ƿ񱣻� 0:����,1:������
    // szReserved[1]��ʾ���ܷ������ݴ����ʽ 0:XML,1:Ԫ����
    // szReserved[2]~szReserved[18]��ʾAES256 CBCģʽIVֵ(16�ֽ�+1������)
    // szReserved[20]��ʾ�����Ԫ���ݷ��࣬ȡֵ�μ�ö��PU_METADATA_REQUEST_TYPE_E

    CHAR szMetaCrypto[PU_CRYPTION_PASSWD_LEN];  // Ԫ������Կ
    ULONG ulVideoCryptoLen;                   // ��Ƶ��Կ����
    ULONG ulAudioCryptoLen;                   // ��Ƶ��Կ����
    ULONG ulMetaCryptoLen;                    // Ԫ������Կ����
    CHAR szNewReserved[PU_RESERVE_EX_LEN - 3 * sizeof(ULONG)];      // �����µ������ֶ�

} PU_MEDIA_PLAY_INFO_V2_S, *LPPU_MEDIA_PLAY_INFO_V2_S;

// ý������ʼ��Ӧ��¼��������Ӧ
typedef struct PU_MEDIA_PLAY_RSP {
    ULONG ulSessionId;                   // ý������Ψһ��־
    PU_PORT_INFO_S stPeerPortInfo;       // ���Ͷ˵Ķ˿���Ϣ
    CHAR szPeerIp[PU_IP4_ADDR_LEN];      // ���Ͷ˵�IP
    PU_ENCODE_TYPE_E enVideoEncodeType;  // ��Ƶ��������
    PU_ENCODE_TYPE_E enAudioEncodeType;  // ��Ƶ��������
    PU_TIME_S stStartTime;               // ¼��ʵ�ʿ�ʼʱ��
    PU_TIME_S stEndTime;                 // ¼��ʵ�ʽ���ʱ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MEDIA_PLAY_RSP_S, *LPPU_MEDIA_PLAY_RSP_S;

// ʵʱ���ACK����
typedef struct PU_MEDIA_PLAY_ACK_INFO {
    ULONG ulChannelId;                // ͨ����
    ULONG ulSessionId;                // ý������Ψһ��־
    ULONG ulVideoPayload;             // ��Ƶ����(�غ�)����
    ULONG ulAudioPayload;             // ��Ƶ����(�غ�)����
    ULONG ulIgtPayload;               // Ԫ���ݸ���(�غ�)����
    CHAR szReserved[PU_RESERVE_LEN];  // ����
} PU_MEDIA_PLAY_ACK_INFO_S;

// ʵʱ���stop����
typedef struct PU_MEDIA_PLAY_STOP_INFO {
    ULONG ulChannelId;                // ͨ����
    ULONG ulSessionId;                // ý������Ψһ��־
    CHAR szReserved[PU_RESERVE_LEN];  // ����
} PU_MEDIA_PLAY_STOP_INFO_S;

/* Ӳ����Ϣ */
typedef struct PU_HARD_DISK_PARA {
    CHAR szDiskFac[PU_FAC_NAME_LEN];
    PU_DISK_TYPE_E enDiskType;
    ULONG ulAllSpace;
    ULONG ulLeftSpace;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_HARD_DISK_PARA_S;

// ���豸����
typedef struct PU_DEVICE_ABILITY {
    ULONG ulVideoInputChannelNum;        // ��Ƶ����ͨ����
    ULONG ulAudioInputChannelNum;        // ��Ƶ����ͨ����
    ULONG ulAlarmDINum;                  // �澯������
    ULONG ulAlarmDONum;                  // �澯�����
    ULONG ulSerialPortNum;               // ������
    ULONG ulNetworkCardNum;              // ������
    ULONG ulHardDiskNum;                 // Ӳ����
    ULONG ulPTZNum;                      // ��̨��
    ULONG ulTalkbackInputNum;            // �����Խ�������
    ULONG ulTalkbackOutputNum;           // �����Խ������
    ULONG ulRTPOverFlag;                 // ����Э��: 0:RTPoverUDP 1:RTPoverTCP 2:RTPoverUDP&TCP
    PU_HARD_DISK_PARA_S stHardDiskInfo;  // Ӳ����Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DEVICE_ABILITY_S, *LPPU_DEVICE_ABILITY_S;

/* ������ */
typedef struct PU_STREAM_ABILITY_PARA {
    PU_STREAM_TYPE_E enStreamType;                        // ��Ƶ������
    PU_ENCODE_TYPE_E enVideoFormat[PU_VIDEO_FORMAT_NUM];  // ��Ƶ�����ʽ
    PU_RESOLUTION_TYPE_E enMaxResolution;                 // ���ֱ���
    ULONG ulMaxBitRate;                                   // �������
    ULONG ulMaxFrmRate;                                   // ���֡��
    ULONG ulMaxIFrameInterval;                            // ���I֡���
    PU_VIDEO_TYPE_E enVideoType;                          // ��Ƶ������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_STREAM_ABILITY_PARA_S, *LPPU_STREAM_ABILITY_PARA_S;

/* ͨ�������� */
typedef struct PU_STREAM_ABILITY {
    ULONG ulChannelId;
    CHAR szCameraName[PU_DEVICE_NAME_LEN];
    ULONG ulPTZType;
    ULONG ulPresetNum;
    ULONG ulCruiseTrackNum;
    ULONG ulMaxStreamNum;
    BOOL bPtzFastLocate;
    BOOL bPtzHorizotalScan;
    BOOL bPtzVerticalScan;
    PU_STREAM_ABILITY_PARA_S stStreamAbility[PU_STREAM_NUM];
    CHAR szReserved[PU_RESERVE_LEN];
} PU_STREAM_ABILITY_S, *LPPU_STREAM_ABILITY_S;

/* ͨ��������V2 */
typedef struct PU_STREAM_ABILITYV2 {
    ULONG ulChannelId;
    CHAR szCameraName[PU_DEVICE_NAME_LEN];
    ULONG ulPTZType;
    ULONG ulPresetNum;
    ULONG ulCruiseTrackNum;
    ULONG ulMaxStreamNum;
    BOOL bPtzFastLocate;
    BOOL bPtzHorizotalScan;
    BOOL bPtzVerticalScan;
    PU_STREAM_ABILITY_PARA_S stStreamAbility[PU_STREAM_NUM_V2];
    CHAR szReserved[PU_RESERVE_LEN];
} PU_STREAM_ABILITYV2_S, *LPPU_STREAM_ABILITYV2_S;

/* ǰ����� */
typedef struct PU_FEC_PARA {
    ULONG ulChannelId;
    BOOL bEnable;                                  // ǰ�����ʹ��
    PU_FEC_PACKET_LOSS_RATIO_E enPacketLossRatio;  // ǰ���������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_FEC_PARA_S, *LPPU_FEC_PARA_S;

/* SEC���� */
typedef struct PU_SEC_PARA {
    ULONG ulChannelId;
    BOOL bEnable;                                  // ǰ�����ʹ��
    PU_SEC_PACKET_LOSS_RATIO_E enPacketLossRatio;  // ǰ���������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SEC_PARA_S, *LPPU_SEC_PARA_S;

// ��̬����/֡��
typedef struct PU_DYNAMIC_STREAM_INFO {
    ULONG ulChannelId;
    BOOL ulEnable;                    // ��̬�����Ƿ�ʹ��
    ULONG ulDynamicFrameRate;         // ��̬֡��
    ULONG ulDynamicBitRate;           // ��̬����
    CHAR szReserved[PU_RESERVE_LEN];  // szReserved[0]��̬֡���Ƿ�ʹ��
} PU_DYNAMIC_STREAM_INFO_S, *LPPU_DYNAMIC_STREAM_INFO_S;

typedef struct PU_DEVICE_REGISTER_RSP {
    PU_ERROR_CODE_E enErrorCode;
    CHAR szRedirectIp[PU_IP4_ADDR_LEN];
    ULONG ulRedirectPort;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DEVICE_REGISTER_RSP_S, *LPPU_DEVICE_REGISTER_RSP_S;

typedef struct PU_START_SNAPSHOT
{
    ULONG ulChannelId;
    ULONG ulSnapCount;
    ULONG ulSnapInterval;
    ULONG ulSessionId;
    PU_SNAPSHOT_TYPE_E enSnapType;
    CHAR szReserved[PU_RESERVE_LEN];
}PU_START_SNAPSHOT_S,*LPUPU_START_SNAPSHOT_S;

// device common callback event struct, include: off line, upload image complete notify
typedef struct PU_EVENT_COMMON {
    PU_EVENT_TYPE_E enEventType;  // �¼�����
    ULONG ulIdentifyID;           // Ψһ��ʶ��ID��
    ULONG ulChannelId;
} PU_EVENT_COMMON_S, *LPPU_EVENT_COMMON_S;

// device stream package change callback event struct
typedef struct PU_EVENT_STEAM_PACKAGE_CHANGE {
    PU_EVENT_COMMON_S stPuEventCommon;  // ͨ���¼�
    PU_STREAM_MODE_E enStreamMode;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_EVENT_STEAM_PACKAGE_CHANGE_S, *LPPU_EVENT_STEAM_PACKAGE_CHANGE_S;

// device stream package change callback event struct
typedef struct PU_EVENT_UPLOAD_IMAGE_URL {
    PU_EVENT_COMMON_S stPuEventCommon;         // ͨ���¼�
    ULONG ulSessionId;                         // ץ�ĻỰID,VCN��Ҫ
    CHAR szContentID[PU_SNAP_IMAGE_NAME_LEN];  // ͼƬ��
    ULONG ulLocation;                          // ͼƬ�洢λ��: 0:ƽ̨  1:ǰ��
    PU_SNAPSHOT_TYPE_E enSnapshotType;
    CHAR cHttpsEnabled;                         //�Ƿ�ʹ��https�� Ԥ�����ݲ�ʹ��
    CHAR szReserved[PU_RESERVE_LEN - sizeof(CHAR)];
} PU_EVENT_UPLOAD_IMAGE_URL_S, *LPPU_EVENT_UPLOAD_IMAGE_URL_S;

typedef struct PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY {
    PU_EVENT_COMMON_S stPuEventCommon;         // ͨ���¼�
    ULONG ulSessionId;                         // ͼƬ�ϴ��ỰID��VCN��Ҫ
    CHAR szContentID[PU_SNAP_IMAGE_NAME_LEN];  // ͼƬ��
    ULONG ulContentSize;                       // ͼƬ��С
    CHAR szSnapTime[PU_TIME_TOTAL_LEN];        // ץ��ʱ�� ��ʽ��"2009-07-14 15:41:14"
    PU_SNAPSHOT_TYPE_E enSnapshotType;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S, *LPPU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S;

// device auto register callback event struct
typedef struct PU_EVENT_REGISTER {
    PU_EVENT_COMMON_S stPuEventCommon;  // ͨ���¼�
    CHAR szDeviceId[PU_MAC_ADDR_LEN];
    CHAR szDeviceIp[PU_IP4_ADDR_LEN];
    CHAR szDeviceType[PU_DEVICE_TYPE_LEN];
    ULONG ulListenPort;
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_EVENT_REGISTER_S, *LPPU_EVENT_REGISTER_S;

// ������ע��ص�
typedef struct PU_DEC_CALLBACK_INFO {
    PU_EVENT_COMMON_S stPuEventCommon;                                 // ͨ���¼�
    CHAR szDecoderID[PU_DECODER_ID_LEN + 4];                           // ������ID
    CHAR szDecIP[PU_IP4_ADDR_LEN];                                     // ������IP
    ULONG ulDecPort;                                                   // ������port
    CHAR szDeviceType[PU_DEC_CHANNEL_NAME_LEN];                        // �豸�ͺ�
    ULONG ulVideoPayloadTypeNum;                                       // ֧�ֵ���ƵPayloadType���������ֵ������16
    ULONG ulAudioPayloadTypeNum;                                       // ֧�ֵ���ƵPayloadType���������ֵ������16
    ULONG ulChannelNum;                                                // ��������Чͨ����������󲻳���
    CHAR szDecoderName[PU_DECODER_NAME_LEN + 4];                       // ����������
    CHAR szDecoderEncoding[PU_DECODER_ENCODING_LEN + 4];               // �����������ʽ
    UCHAR ucVideoPayloadTypeArray[PU_DEC_PAY_LOAD_TYPE_NUM];           // ֧�ֵ���ƵPayloadType�̶����顣Ԫ�ظ���Ϊ16��ʵ��Ԫ�ظ���ΪulVideoPayloadTypeNum
    UCHAR ucAudioPayloadTypeArray[PU_DEC_PAY_LOAD_TYPE_NUM];           // ֧�ֵ���ƵPayloadType�̶����顣Ԫ�ظ���Ϊ16��ʵ��Ԫ�ظ���ΪulAudioPayloadTypeNum
    PU_DECODER_CHANNEL_INFO_S stChannelInfoArray[PU_CHANNEL_NUM_MAX];  // ������ͨ����Ϣ������Ԫ�ظ���ΪulChannelNum
} PU_DEC_CALLBACK_INFO_S, *LPPU_DEC_CALLBACK_INFO_S;

// ����״̬�ص�
typedef struct PU_CONNECT_STATUS {
    PU_EVENT_COMMON_S stPuEventCommon;      // ͨ���¼�
    CHAR szDeviceIP[PU_IP4_ADDR_LEN];       // �豸IP
    ULONG ulDevicePort;                     // �豸port
    CHAR szDeviceFac[PU_FAC_NAME_LEN];      // �豸����,�̶�Ϊ��HUAWEI PU
    CHAR szDeviceID[PU_MAC_ADDR_LEN + 4];   // �豸ID
    CHAR szDeviceType[PU_DEVICE_NAME_LEN];  // �豸�ͺ�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_CONNECT_STATUS_S, *LPPU_CONNECT_STATUS_S;

typedef struct PU_EVENT_TRANSPARENT {
    PU_EVENT_COMMON_S stPuEventCommon;  // ͨ���¼�
    PU_TRANSPARENT_CMD_S stTransparentCmd;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_EVENT_TRANSPARENT_S, *LPPU_EVENT_TRANSPARENT_S;

typedef struct PU_WATER_MARK {
    PU_EVENT_COMMON_S stPuEventCommon;  // ͨ���¼�
    PU_ALARM_ACTION_E enAction;         // �澯����/����
} PU_WATER_MARK_S, *LPPU_WATER_MARK_S;

// ��ȷ����
typedef struct PU_PRECISE_FIGURES {
    ULONG ulIntValue;  // ������������
    ULONG ulDotValue;  // ����С������
} PU_PRECISE_FIGURES_S;

// ��ͷ��Ϣ
typedef struct PU_LENS_INFO {
    ULONG ulChnID;
    PU_PRECISE_FIGURES_S stLZoomRatio;       // ��ͷ�䱶
    PU_PRECISE_FIGURES_S stDZoomRatio;       // ���ֱ䱶
    PU_PRECISE_FIGURES_S stHorDegree;        // ˮƽ�ӳ���
    PU_PRECISE_FIGURES_S stVerDegree;        // ��ֱ�ӳ���
    PU_PRECISE_FIGURES_S stFocalMillimeter;  // ����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_LENS_INFO_S;

// ����λ����Ϣ
typedef struct PU_CAM_GEOG_POSITION {
    ULONG ulChnID;                           // ͨ����
    CHAR szAzimuth[CAM_POSITION_STR_LEN];    // ��λ��
    CHAR szPitch[CAM_POSITION_STR_LEN];      // ������
    CHAR szLongitude[CAM_POSITION_STR_LEN];  // ����
    CHAR szLatitude[CAM_POSITION_STR_LEN];   // γ��
    CHAR szReserved[PU_RESERVE_LEN];         // szReserved[0]�����ȡ��γ�ȷ�ʽ; szReserved[1] bit0��ӦnHeight, bit1��ӦfAzimuth, bit2��ӦfPitch, bit3��ӦdLongitude��bit4��ӦdLatitude
} PU_CAM_GEOG_POSITION_S;

// ����߶�
typedef struct PU_CAM_INSTALL_HEIGHT {
    ULONG ulChnID;
    ULONG ulCentimeter;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_CAM_INSTALL_HEIGHT_S;

// CMOS�ߴ�
typedef struct PU_CMOS_SIZE_PARA {
    ULONG ulChnID;
    ULONG ulIntHorSize;
    ULONG ulDotHorSize;
    ULONG ulIntVerSize;
    ULONG ulDotVerSize;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_CMOS_SIZE_PARA_S;

typedef struct PU_PTZ_REPORT_INFO {
    PU_EVENT_COMMON_S stPuEventCommon;  // ͨ���¼�
    PU_LENS_INFO_S stCamDegree;
    PU_CAM_GEOG_POSITION_S stCamPosition;
    PU_CAM_INSTALL_HEIGHT_S stCamFixHeight;
    PU_CMOS_SIZE_PARA_S stCamCMOSSize;
} PU_PTZ_REPORT_INFO_S, *LPPU_PTZ_REPORT_INFO_S;

// �����򶨵��ϱ�������������
typedef struct PU_SNAP_MOVE2FIX_INFO {
    ULONGLONG ulSnapId;  // ץ�Ĳ���ID
    // ���¶����ϱ�ʱʹ��
    ULONG uSnapTime;   // ���㷵��ʱ����ʵ��ץ��ʱ��
    ULONG uSnapCount;  // ����ʱ����ʵ��ץ����Ŀ
} PU_SNAP_MOVE2FIX_INFO_S;

typedef struct PU_MOVING2FIX_INFO {
    PU_EVENT_COMMON_S stPuEventCommon;  // ͨ���¼�
    ULONG ulCmdType;                    // �ϱ���Ϣ����
    union reportinfo {
        PU_SNAP_MOVE2FIX_INFO_S stSnapInfo;
    } unreportinfo;
} PU_MOVING2FIX_INFO_S, *LPPU_MOVING2FIX_INFO_S;

typedef union PU_EVENT_NOTIFY_BODY {
    PU_EVENT_COMMON_S stPuEventCommon;                       // ͨ���¼�
    PU_EVENT_STEAM_PACKAGE_CHANGE_S stPuStreamPackgeChange;  // IPC���ײͱ��
    PU_EVENT_UPLOAD_IMAGE_URL_S stPuUploadImageURL;          // ǰ�������ϴ�ͼƬURL
    PU_EVENT_UPLOAD_IMAGE_COMP_NOTIFY_S stUploadCompNotify;  // ǰ��ͼƬ�ϴ����֪ͨ

    PU_DEC_CALLBACK_INFO_S stPuDecRegister;             // ǰ��DEC����ע��
    PU_CONNECT_STATUS_S stPuConnetStatus;               // ǰ���豸����״̬
    PU_EVENT_REGISTER_S stPuIpcRegister;                // ǰ��IPC����ע��
    PU_EVENT_TRANSPARENT_S stTransparentChannelNotify;  // ͸��ͨ�������ϱ�
    PU_WATER_MARK_S stPuWaterMark;                      // ����ˮӡ
    PU_PTZ_REPORT_INFO_S stVisualInfo;                  // ���ӻ���Ϣ�ϱ�
    PU_MOVING2FIX_INFO_S stMoving2FixInfo;              // �����򶨵��ϱ���Ϣ
} PU_EVENT_NOTIFY_BODY_U, *LPPU_EVENT_NOTIFY_BODY_U;

// ����������
typedef struct RECORD_STRATEGY {
    ULONG ulChannelId;
    ULONG ulStrategy;            // �洢����:0ѭ������  1ֹͣ¼��
    ULONG ulMinRecordTime;       // ��СԤ¼ʱ��
    ULONG ulPreAlarmRecordTime;  // ��ǰԤ¼ʱ�� V2R3�汾 0:��Ԥ¼ 65535:�����ڴ��������ʱ��Ԥ¼ ��������豸����5-20s����
	ULONG ulMaxStorage;                     // �洢SDʹ�ÿռ�����ֵ(�ٷֱ�)0~100
    // V2R3֮ǰ�汾 <=10s
    CHAR  szReserved[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_RECORD_STRATEGY_S, *LPPU_RECORD_STRATEGY_S;

// ����λ����(��Ԥ��λ)
typedef struct GUARD_POSITION_PARA {
    ULONG ulPtzId;  // ��̨��ţ�֧����ͼ
    BOOL bEnable;
    ULONG ulPresetIndex;
    ULONG ulWaitTime;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_GUARD_POSITION_PARA_S, *LPPU_GUARD_POSITION_PARA_S;

typedef struct PU_HORIZONTAL_SCAN_PARA {
    ULONG ulSpeed;                   // �ٶ�
    PU_PTZ_DIRECTION_E enDirection;  // ����֧����/��
} PU_HORIZONTAL_SCAN_PARA_S;

typedef struct PU_RANDOM_SCAN_PARA {
    ULONG ulInterval;  // ���
} PU_RANDOM_SCAN_PARA_S;

typedef struct PU_PANORAMA_SCAN_PARA {
    ULONG ulSpeed;                   // �ٶ�
    PU_PTZ_DIRECTION_E enDirection;  // ����֧����/��
} PU_PANORAMA_SCAN_PARA_S;

typedef struct PU_VERTICAL_SCAN_PARA {
    ULONG ulSpeed;  // �ٶ�
} PU_VERTICAL_SCAN_PARA_S;

typedef struct PU_FRAME_SCAN_PARA {
    ULONG ulFrameInterval;  // ֡���
} PU_FRAME_SCAN_PARA_S;

typedef struct PU_USER_DEFINED_SCAN_PARA {
    ULONG ulUserDefineIndex;  // ����ɨ��·��
} PU_USER_DEFINED_SCAN_PARA_S;

typedef struct PU_CRUISE_SCAN_PARA {
    ULONG ulCruiseIndex;  // Ѳ���켣���к�
} PU_CRUISE_SCAN_PARA_S;

typedef struct PU_PRESET_SCAN_PARA {
    ULONG ulPresetIndex;  // Ԥ��λ���к�
} PU_PRESET_SCAN_PARA_S;

typedef union PU_GUARD_POINT_PARA {
    PU_PRESET_SCAN_PARA_S stPresetPara;             // Ԥ��λ
    PU_CRUISE_SCAN_PARA_S stCruisePara;             // Ѳ���켣
    PU_USER_DEFINED_SCAN_PARA_S stUserDefinedPara;  // ����ɨ��
    PU_HORIZONTAL_SCAN_PARA_S stHorPara;            // ˮƽɨ��
    PU_FRAME_SCAN_PARA_S stFramePara;               // ֡ɨ��
    PU_RANDOM_SCAN_PARA_S stRandomPara;             // ���ɨ��
    PU_PANORAMA_SCAN_PARA_S stPanoramePara;         // ȫ��ɨ��
    PU_VERTICAL_SCAN_PARA_S stVerticalPara;         // ��ֱɨ��
} PU_GUARD_POINT_PARA_U;

// ��������
typedef struct GUARD_POSITION_PARA_EX {
    ULONG ulPtzId;  // ��̨��ţ�֧����ͼ
    BOOL bEnable;
    ULONG ulWaitTime;
    PU_GUARD_POINT_TYPE_E enGuardType;  // ��������
    PU_GUARD_POINT_PARA_U unGuardPara;  // ���ز���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_GUARD_POSITION_PARA_EX_S, *LPPU_GUARD_POSITION_PARA_EX_S;

// ������̨����
typedef struct PU_EPTZ_PARA {
    ULONG ulChannelId;
    PU_STREAM_TYPE_E enStreamType;
    BOOL bEnable;
    ULONG ulLeftPercent;
    ULONG ulTopPercent;
    ULONG ulWidthPercent;
    ULONG ulHeightPercent;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_EPTZ_PARA_S, *LPPU_EPTZ_PARA_S;

// ����ƽ������
typedef struct PU_STREAM_SMOOTH_PARA {
    ULONG ulChannelId;
    BOOL bEnable;
    ULONG ulTcpUpperCoefficient;
    ULONG ulUdpUpperCoefficient;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_STREAM_SMOOTH_PARA_S, *LPPU_STREAM_SMOOTH_PARA_S;

typedef struct PU_STREAM_SMOOTH_PARA_EX {
    ULONG ulChannelId;
    BOOL bEnable;
    ULONG ulUpperCoefficient;  // ����ƽ������,��Χ1-8,��Ӧ�豸����1.5-5.0,����0.5
    CHAR szReserved[PU_RESERVE_LEN];
} PU_STREAM_SMOOTH_PARA_EX_S, *LPPU_STREAM_SMOOTH_PARA_EX_S;

// ��̨λ����Ϣ���ܱ䱶����1 ~ 30*12=240��
typedef struct PU_PTZ_CURRENT_LOCATION {
    LONG lPTZHorDegree;      // ˮƽ�Ƕ�(0~359)
    LONG lPTZVerDegree;      // ��ֱ�Ƕ�(-10~90)
    ULONG ulLenMultiple;     // ��ͷ�䱶��������(1~30��������ֱ䱶��Ϊ0��ͷ�䱶Ĭ��Ϊ���ֵ30)
    ULONG ulDotLenMultiple;  // ��ͷ�䱶С������(0~99��֧��С�����һλ���֣�
    ULONG ulZoomRatio;       // ���ֱ䱶��������(0~12����ͷ�䱶�ﵽ���ֵ�����ã�0��ʾ�����ã��ܱ䱶��Ϊ��˹�ϵ)
    ULONG ulDotZoomRatio;    // ���ֱ䱶С������(0~99��֧��С�����һλ���֣�
    LONG lPTZDotHorDegree;   // ˮƽ�Ƕ�С������(0~99��֧��С�����һλ���֣�
    LONG lPTZDotVerDegree;   // ��ֱ�Ƕ�С������(-99~99��֧��С�����һλ���֣�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PTZ_CURRENT_LOCATION_S, *LPPU_PTZ_CURRENT_LOCATION_S;

// ��̨λ����Ϣ��չ���ܱ䱶����1 ~ 30*12=240��
typedef struct PU_PTZ_CURRENT_LOCATION_EX {
    LONG lPTZHorDegree;      // ˮƽ�Ƕ�(0~359)
    LONG lPTZVerDegree;      // ��ֱ�Ƕ�(-10~90)
    ULONG ulLenMultiple;     // ��ͷ�䱶��������(1~30��������ֱ䱶��Ϊ0��ͷ�䱶Ĭ��Ϊ���ֵ30)
    ULONG ulDotLenMultiple;  // ��ͷ�䱶С������(0~99��֧��С�����һλ���֣�
    ULONG ulZoomRatio;       // ���ֱ䱶��������(0~12����ͷ�䱶�ﵽ���ֵ�����ã�0��ʾ�����ã��ܱ䱶��Ϊ��˹�ϵ)
    ULONG ulDotZoomRatio;    // ���ֱ䱶С������(0~99��֧��С�����һλ���֣�
    LONG lPTZDotHorDegree;   // ˮƽ�Ƕ�С������(0~99��֧��С�����һλ���֣�
    LONG lPTZDotVerDegree;   // ��ֱ�Ƕ�С������(-99~99��֧��С�����һλ���֣�
    FLOAT fAbsPTZHorDegree;  // ˮƽ���ԽǶ�
    FLOAT fAbsPTZVerDegree;  // ��ֱ���ԽǶ�
    LONG lZoomPos;           // �佹λ��
    LONG lFocusPos;          // �Խ�λ��
    BOOL bZoomFlag;          // tureʹ�ñ��ʣ�falseʹ�õ��λ��
    ULONG ulChannelId;       // ͨ��ID
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_PTZ_CURRENT_LOCATION_EX_S;

// ��̨��ǶȲ���
typedef struct PU_PTZ_MULTI_MOTOR_PARA {
    ULONG ulChannelId;            // ͨ��ID
    PU_PTZ_OPCODE_E enDirection;  // ��̨���Ʋ�����
    ULONG ulHorSpeed;             // ˮƽ�����ٶ�
    ULONG ulVerSpeed;             // ��ֱ�����ٶ�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PTZ_MULTI_MOTOR_PARA_S;

typedef struct PU_IGT_ALARM_PARA {
    ULONG ulChannelId;
    BOOL bIgtEnable;                          // �����ܿ���
    BOOL bTrackEnable;                        // Ŀ��켣����ʹ��
    PU_IGT_FIELD_TYPE_E enFieldType;          // ����ģʽ����
    PU_IGT_MINTARGET_SIZE_E enMinTargetSize;  // ǰ��Ŀ����С�ߴ��趨
    PU_IGT_SHADOW_MODE_E enShadowMode;        // ȥ��Ӱģʽ�趨
    PU_IGT_DETECT_SENS_E enDetectSens;        // Ŀ�����������趨
    BOOL bInsensitiveObject;                  // �Ƿ���ʾ������Ŀ����Ϣ
    UCHAR szReserved[PU_RESERVE_LEN];         // szReserved[0] ��ʾ��СĿ��ߴ��(5~200��С�����ߴ�)
    // szReserved[1] ��ʾ��СĿ��ߴ��(5~200��С�����ߴ�)
    // szReserved[2] ��ʾ���Ŀ��ߴ��(5~200)
    // szReserved[3] ��ʾ���Ŀ��ߴ��(5~200)
    // szReserved[4] ��ʾ������������
    // szReserved[5] ��ʾ���Ŀ�����
} PU_IGT_ALARM_PARA_S, *LPPU_IGT_ALARM_PARA_S;

typedef struct PU_IGT_POINT {
    USHORT usPointPosX; /* ��X������(0-352) */
    USHORT usPointPosY; /* ��Y������(0-288) */
} PU_IGT_POINT_S;

typedef struct PU_POINT {
    USHORT usPosX;  // X������(0-352)
    USHORT usPosY;  // Y������(0-288)
} PU_POINT_S;

typedef struct PU_IGT_TW_LINE {
    UCHAR ucDirection;                     /* ��ⷽ��: 0:both 1:Left->right 2:right->left */
    PU_IGT_POINT_S stStartPoit;            /* ������ʼ�� */
    PU_IGT_POINT_S stEndPoit;              /* ������ֹ�� */
    ULONG ulLineIndex;                     /* �������� */
    BOOL bEnable;                          /* �����Ƿ�ʹ�� */
    CHAR szLineName[PU_IGT_LINE_NAME_LEN]; /* �������� */
} PU_IGT_TW_LINE_S, *LPPU_IGT_TW_LINE_S;

typedef struct PU_IGT_TW_LINE_LIST {
    ULONG ulLineNum;
    PU_IGT_TW_LINE_S szTWLineList[PU_TRIPWIRE_LEN_NUM_MAX];
} PU_IGT_TW_LINE_LIST_S;

/* ------------���߼������ṹ��------------ */
typedef struct PU_TW_ALARM_PARA {
    ULONG ulChannelId;
    BOOL bEnable;
    ULONG ulAlarmInterval;                   // �澯�����
    PU_IGT_TARGET_MODE_E enTargetDetecMode;  // Ŀ��ʶ��ģʽ
    PU_IGT_TW_LINE_LIST_S stlineList;        /* �������飺��ȡʱ�᷵�����а���������Ϣ���������Ϊ0˵�����ٵ�ǰ��ͷ��Χ�ڣ��᷵���������� */
    /* ����ʱ�ò�����ѡ�����ulLineNum������0��ȫ���·ţ�����0ʱ���·� */
    PU_ALARM_TIME_LIST_S stTWGuardPlan;      // �����ƻ�
    // �ֶ���չ���������ֶ�ʹ��ʱ���밴���ϵ��µ��ֶ�˳����bitλ(�ӵ�����)
    USHORT usSetBitmap;
    UCHAR uiSensitivity;
    UCHAR uiObjTypeFilterFlag;  // Ŀ�����͹��˱�־(ȡֵ��ΧΪ0-7,0 ��ѡ 1 ���� 2 ������ 3 ����+������ 4 �ǻ����� 5 ����+�ǻ����� 6 ������+�ǻ����� 7 ȫѡ)
    CHAR szReserved[PU_RESERVE_LEN - sizeof(USHORT) - sizeof(UCHAR) * 2];
} PU_TW_ALARM_PARA_S, *LPPU_TW_ALARM_PARA_S;

typedef struct PU_IGT_TW_LINE_ITEM {
    ULONG ulChannelId;
    PU_IGT_OPT_TYPE_E enOptType;
    PU_IGT_TW_LINE_S stIgtTwLine;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_IGT_TW_LINE_ITEM_S, *LPPU_IGT_TW_LINE_ITEM_S;

/* ������ */
typedef struct PU_IGT_AREA {
    UINT uPointNum;                                 /* �������ζ�����Ŀ */
    PU_IGT_POINT_S stPoint[PU_IGT_AREA_POINTS_NUM]; /* ������ */
    ULONG ulAreaIndex;                              /* �������� */
    BOOL bEnable;                                   /* �������Ƿ�ʹ�� */
    CHAR szAreaName[PU_IGT_AREA_NAME_LEN];          /* �������� */
    PU_PTZ_CURRENT_LOCATION_S stLocation;           /* ��̨λ����Ϣ */
} PU_IGT_AREA_S, *LPPU_IGT_AREA_S;

typedef struct PU_IGT_AERADTC_LIST {
    ULONG ulAreaNum;
    PU_IGT_AREA_S stArea[PU_IGT_AREA_NUM];
} PU_IGT_AERADTC_LIST_S;

typedef struct PU_IGT_AEREDTC_ALARM_PARA {
    ULONG ulChannelId;
    BOOL bEnable;
    ULONG ulAlarmInterval;                   // �澯�����
    PU_IGT_TARGET_MODE_E enTargetDetecMode;  // Ŀ��ʶ��ģʽ
    ULONG ulRemainTime;                      // ͣ��ʱ��
    PU_IGT_AERADTC_LIST_S stAreaDtcList;     // �������飺��ȡʱ�᷵������������Ϣ�������������Ϊ0˵�����ٵ�ǰ��ͷ��Χ��(�᷵������)
    // ����ʱ�ò�����ѡ�����ulAreaNum������0��ȫ���·ţ�����0ʱ���·�
    PU_ALARM_TIME_LIST_S stAreaGuardPlan;    // �����ƻ�
    // �ֶ���չ���������ֶ�ʹ��ʱ���밴���ϵ��µ��ֶ�˳����bitλ(�ӵ�����)
    USHORT usSetBitmap;
    UCHAR uiSensitivity;        // �㷨������
    UCHAR uiObjTypeFilterFlag;  // Ŀ�����͹��˱�־(ȡֵ��ΧΪ0-7,0 ��ѡ 1 ���� 2 ������ 3 ����+������ 4 �ǻ����� 5 ����+�ǻ����� 6 ������+�ǻ����� 7 ȫѡ)
    CHAR szReserved[PU_RESERVE_LEN - sizeof(USHORT) - sizeof(UCHAR) * 2];
} PU_IGT_AREADTC_ALARM_PARA_S, *LPPU_IGT_AREADTC_ALARM_PARA_S;

typedef struct PU_IGT_AREA_ITEM {
    ULONG ulChannelId;
    PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType;
    PU_IGT_OPT_TYPE_E enOptType;
    PU_IGT_AREA_S stIgtArea;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_IGT_AREA_ITEM_S, *LPPU_IGT_AREA_ITEM_S;

// Discover ������Ӧ��
typedef struct PU_DISCOVER_DEVICE_INFO {
    CHAR szDeviceMac[PU_MAC_ADDR_LEN];      // �豸MAC��ַ
    CHAR szDeviceType[PU_DEVICE_TYPE_LEN];  // �豸�ͺ�
    CHAR szDeviceVersion[PU_VERSION_LEN];   // �豸�汾��
    CHAR szDeviceName[PU_DEVICE_NAME_LEN];  // �豸����
    CHAR szDeviceIp[PU_IP4_ADDR_LEN];       // �豸IP
    CHAR szDeviceMask[PU_IP4_ADDR_LEN];     // �豸����
    CHAR szDeviceGateway[PU_IP4_ADDR_LEN];  // �豸����
    CHAR szSerialNumber[PU_SERIAL_LEN];     // SN��
    UINT uDhcpEnable;                       // DHCP�Ƿ�ʹ�� 0��δʹ��  ,  1��ʹ�� ,  2��δ֪��Ϊ�����ϰ汾
	CHAR cMeshIndex;                        // ����������Ϣ  8.0.1�汾֧��
	CHAR cOMEnable;                         // ����ͨ��ʹ��  8.0.1�汾֧��
    CHAR szReserved[PU_RESERVE_LEN - 2 * sizeof(CHAR)];        // Ԥ��
} PU_DISCOVER_DEVICE_INFO_S, *LPPU_DISCOVER_DEVICE_INFO_S;

typedef struct PU_DISCOVER_DEVICE_LIST {
    ULONG ulDeviceNum;
    PU_DISCOVER_DEVICE_INFO_S stDeviceInfo[PU_DEVICE_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DISCOVER_DEVICE_LIST_S, *LPPU_DISCOVER_DEVICE_LIST_S;

/* ���ڵ�ַ���� */
typedef struct PU_DEVICE_ETHERNET_PARA {
    BOOL bDhcpEnable;                          // �Ƿ�����DHCP
    CHAR szIPAddress[PU_IP4_ADDR_LEN];         // IP��ַ
    CHAR szSubNetMask[PU_IP4_ADDR_LEN];        // ��������
    CHAR szGateWayAddress[PU_IP4_ADDR_LEN];    // ���ص�ַ
    CHAR szFirstDNSAddress[PU_IP4_ADDR_LEN];   // ��һ��DNS��ַ
    CHAR szSecondDNSAddress[PU_IP4_ADDR_LEN];  // �ڶ���DNS��ַ
    CHAR szReserved[PU_RESERVE_LEN];           // szReserved[0],��ʾ��������,0��ʾ����1,1��ʾ����2
} PU_DEVICE_ETHERNET_PARA_S, *LPPU_DEVICE_ETHERNET_PARA_S;

/* NTP���� */
typedef struct PU_NTP_PARA {
    BOOL bNTPEnable;                   // NTPʹ��
    ULONG ulSynInterval;               // NTPͬ�����
    CHAR szNTPAddress[PU_DOMAIN_LEN];  // NTP��������ַ:��������IP��ַ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_NTP_PARA_S, *LPPU_NTP_PARA_S;

/* GPSУʱ���� */
typedef struct PU_GPS_PARA {
    BOOL enGPSEnable;  // GPSʹ��
    ULONG ulInterval;  // GPSʱ��ͬ�����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_GPS_PARA_S, *LPPU_GPS_PARA_S;

// ǧѰGPS��Ϣ
typedef struct PU_QXGPS_INFO{
	ULONG ulChannelId;
	BOOL bEnable;                       // ʹ��
	CHAR szAppKey[PU_CLIENT_PWD_LEN_MAX];        // AppKey
	CHAR szAppSecert[PU_CLIENT_PWD_LEN_MAX];    // AppSecret
	CHAR szReserved[PU_RESERVE_LEN];
}PU_QXGPS_INFO_S;

// ǧѰGPS״̬
typedef struct PU_QXGPS_STATUS{
	ULONG ulChannelId;
	ULONG iStatus;
	CHAR szReserved[PU_RESERVE_LEN];
}PU_QXGPS_STATUS_S;

// �鲥����
typedef struct PU_MULTICAST_PARA {
    ULONG ulMeshIndex;                      // ��������
    CHAR szLocalIP[PU_MULTICAST_ADDR_LEN];  // �ಥ��ַ
    ULONG ulPort;                           // �ಥ�˿�
    CHAR szReserved[PU_RESERVE_LEN];        // ����
} PU_MULTICAST_PARA_S;

// ����Ʋ���
typedef struct PU_IRLIGHT_PARA {
    BOOL bEnable;        // ʹ��
    ULONG ulIRLightLum;  // ����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_IRLIGHT_PARA_S;

typedef struct PU_IRLIGHT_LIST {
    ULONG ulChannelId;
    PU_IRLIGHT_MODE_E enIRLightMode;
    PU_IRLIGHT_PARA_S stIRLightMPara[PU_IRLIGHT_NUM_MAX];  // ��������ݣ��ֶ�ģʽʱ����
    CHAR szReserved[PU_RESERVE_LEN];                       // szReserved[0] ���ܺ��⿪�أ�0:�� 1:�ر�
    // szReserved[1] ��ʾ���ܺ���ϵ�� 1-100
    // szReserved[2] ���ⰲȫ���ƿ��أ�0:�ر� 1:��
} PU_IRLIGHT_LIST_S, *LPPU_IRLIGHT_LIST_S;

/* SNMPv1v2c������Ϣ */
typedef struct PU_SNMP_COMMUNITY_INFO {
    PU_SNMP_COMMUNITY_ATTR_E enCommunityAttr;          // ��������
    CHAR szCommunityName[PU_SNMP_COMMUNITY_NAME_LEN];  // ������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNMP_COMMUNITY_INFO_S, *LPPU_SNMP_COMMUNITY_INFO_S;

/* SNMPv1v2c�����б� */
typedef struct PU_SNMP_COMMUNITY_LIST {
    ULONG ulCommunityNum;                                             // ������Ŀ
    PU_SNMP_COMMUNITY_INFO_S szCommunityInfo[PU_SNMP_COMMUNITY_NUM];  // ������Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNMP_COMMUNITY_LIST_S, *LPPU_SNMP_COMMUNITY_LIST_S;

/* SNMPv1v2c������Ϣ ��չ-֧�ָ����������� */

typedef struct PU_SNMP_COMMUNITY_INFO_EX {
    PU_SNMP_COMMUNITY_ATTR_E enCommunityAttr;             // ��������
    CHAR szCommunityName[PU_SNMP_COMMUNITY_NAME_LEN_EX];  // ������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNMP_COMMUNITY_INFO_S_EX, *LPPU_SNMP_COMMUNITY_INFO_S_EX;

/* SNMPv1v2c�����б� ��չ-֧�ָ����������� */
typedef struct PU_SNMP_COMMUNITY_LIST_EX {
    ULONG ulCommunityNum;                                                // ������Ŀ
    PU_SNMP_COMMUNITY_INFO_S_EX szCommunityInfo[PU_SNMP_COMMUNITY_NUM];  // ������Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNMP_COMMUNITY_LIST_S_EX, *LPPU_SNMP_COMMUNITY_LIST_S_EX;

/* SNMPv3�û���Ϣ */
typedef struct PU_SNMPV3_USER_INFO {
    CHAR szUserName[PU_USER_NAME_LEN];             // �û���
    BOOL bEngineIdEnable;                          // �Ƿ���Ҫָ��ENGINEID(��ʱֻ������Trapʱʹ��)
    CHAR szEngineId[PU_SNMP_ENGINEID_LEN];         // ENGINEID(��ʱֻ������Trapʱʹ��)
    BOOL bContextEnable;                           // �Ƿ���Ҫָ����������(��ʱֻ������Trapʱʹ��)
    CHAR szContextName[PU_SNMP_CONTEXT_NAME_LEN];  // ��������(��ʱֻ������Trapʱʹ��)
    CHAR szAuthPassword[PU_PASSWORD_LEN];          // ��֤Pwd(����WEB���õ�ʱ��Ϊԭ���·�;��¼�������ļ���Ϊ������ʽ)
    CHAR szPrivKey[PU_PASSWORD_LEN];               // ��Կ(����WEB���õ�ʱ��Ϊԭ���·�;��¼�������ļ���Ϊ������ʽ)
    PU_SNMPV3_SECURITY_LEVEL_E enSecurityLevel;    // ��ȫ����
    PU_SNMPV3_AUTH_PROTOCOL_E enAuthProtocol;      // ��֤Э��
    PU_SNMPV3_PRIV_PROTOCOL_E enPrivProtocol;      // ��ԿЭ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNMPV3_USER_INFO_S, *LPPU_SNMPV3_USER_INFO_S;

/* SNMPv3�û��б� */
typedef struct PU_SNMPV3_USER_LIST {
    ULONG ulUserNum;                                       // �û���Ŀ
    PU_SNMPV3_USER_INFO_S szUserInfo[PU_SNMPV3_USER_NUM];  // �û���Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNMPV3_USER_LIST_S, *LPPU_SNMPV3_USER_LIST_S;

/* SNMPv3�û����� */
typedef struct PU_SNMPV3_USER_MGMT {
    PU_OPT_TYPE_E enManipulateType;           // ��������
    PU_SNMPV3_USER_INFO_S stMgmtUserInfo;     // ������Ϣ
    CHAR szModifyVerifyPwd[PU_PASSWORD_LEN];  // ��ǰsnmp�û�����֤Pwd(��ȫ����Ϊnoauth)
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNMPV3_USER_MGMT_S, *LPPU_SNMPV3_USER_MGMT_S;

typedef union PU_SNMP_AUTH_INFO {
    CHAR szCommunityName[PU_SNMP_COMMUNITY_NAME_LEN];  // ������������v1/v2c�汾��trapʹ��
    PU_SNMPV3_USER_INFO_S stUserInfo;                  // �û���Ϣ������v3�汾��trapʹ��
} PU_SNMP_AUTH_INFO_U;

/* SNMP Trap���շ���Ϣ */
typedef struct PU_SNMP_TRAP_INFO {
    CHAR szTrapPeerIp[PU_IP4_ADDR_LEN];   // ���շ�IP
    USHORT usTrapPeerPort;                // ���շ��˿�
    PU_SNMP_VERSION_TYPE_E enSnmpVer;     // �汾
    PU_SNMP_AUTH_INFO_U unSnmmpAuthInfo;  // ��Ȩ��Ϣ
    CHAR szReserved[PU_RESERVE_LEN];      // szReserved[0],Ӧ�õ�����,0:����������1,1:����������2,�Դ�����
} PU_SNMP_TRAP_INFO_S, *LPPU_SNMP_TRAP_INFO_S;

/* SNMP Trap���շ��б� */
typedef struct PU_SNMP_TRAP_LIST {
    ULONG ulTrapNum;                                   // Trap���ն���Ŀ
    PU_SNMP_TRAP_INFO_S szTrapInfo[PU_SNMP_TRAP_NUM];  // Trap���ն���Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNMP_TRAP_LIST_S, *LPPU_SNMP_TRAP_LIST_S;

/********* 802.1x *********/
/* 802.1x������Ϣ */
typedef struct PU_DOT1X_CONFIG_INFO {
    BOOL bDot1xEnable;                        // ���ñ�־
    PU_DOT1X_EAPOL_VERSION_E enEapolVersion;  // EAPOL�汾
    CHAR szEapUserName[PU_USER_NAME_LEN];     // EAP�û���
    CHAR szEapPassWord[PU_PASSWORD_LEN];      // EAPPwd
    CHAR szReserved[PU_RESERVE_LEN];          // szReserved[0]��ʾEAP MD5���� 0:�ر� 1:����
} PU_DOT1X_CONFIG_INFO_S, *LPPU_DOT1X_CONFIG_INFO_S;

typedef struct PU_USER_INFO {
    PU_USER_TYPE_E enUserType;          // �û�����
    CHAR szUserName[PU_USER_NAME_LEN];  // �û���,�֧��16λ
    CHAR szUserPwd[PU_PASSWORD_LEN];    // Pwd
    CHAR szReserved[PU_RESERVE_LEN];    // szReserved[0]����WEB����½�û�������Χ1-10
} PU_USER_INFO_S, *LPPU_USER_INFO_S;

// �����û��б�
typedef struct PU_USER_LIST {
    ULONG ulCurrentUserNum;                             // ��ǰ�û�����
    PU_USER_INFO_S szUserList[PU_DEVICE_USER_NUM_MAX];  // ��ǰ�û��б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_USER_LIST_S, *LPPU_USER_LIST_S;

// �û�����
typedef struct PU_USER_MANAGEMENT {
    CHAR szOperaterUserName[PU_USER_NAME_LEN];  // ����������
    PU_OPT_TYPE_E enOptType;                    // ��������
    PU_USER_INFO_S stUserInfo;                  // ������Ϣ
    CHAR szVerifyPwd[PU_PASSWORD_LEN];          // ��֤Pwd
    CHAR szReserved[PU_RESERVE_LEN];
} PU_USER_MANAGEMENT_S;

typedef struct PU_LOCAL_RECORD {
    ULONG ulChannelId;              // ¼��ͨ��
    ULONG ulAction;                 // ������־ 0 ֹͣ ��0 ��ʼ
    PU_RECORD_TYPE_E enRecordType;  // ¼��ʽ, ��Ϊ��Σ�����������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_LOCAL_RECORD_S, *LPPU_LOCAL_RECORD_S;

// ���׵��ͳ����ײ���Ϣ
typedef struct PU_TYPICAL_SCENE_INFO {
    PU_TYPICAL_SCENE_MODE_E enSceneMode;             // ���ͳ�������
    CHAR szName[PU_TYPICAL_SCENE_NAME_LEN];          // ���ͳ�������������
    CHAR szDescribe[PU_TYPICAL_SCENE_DESCRIBE_LEN];  // ����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_TYPICAL_SCENE_INFO_S, *LPPU_TYPICAL_SCENE_INFO_S;

// ���׵��ͳ����ײ��б�
typedef struct PU_TYPICAL_SCENE_LIST {
    ULONG ulChannelId;                                                     // �����ĸ�ͨ��
    ULONG ulTypicalScenesNum;                                              // ���ͳ����ײ͸���
    PU_TYPICAL_SCENE_MODE_E enSceneMode;                                   // ��ǰ����ĵ��ͳ����ײ�
    PU_TYPICAL_SCENE_INFO_S stTypicalSceneInfo[PU_TYPICAL_SCENE_NUM_MAX];  // ��Ϣ�б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_TYPICAL_SCENE_LIST_S, *LPPU_TYPICAL_SCENE_LIST_S;

// ���׵��ͳ����ײ��б�
typedef struct PU_TYPICAL_SCENE_LIST_EX_OUT {
    ULONG ulChannelId;                             // �����ĸ�ͨ��
    ULONG ulTypicalScenesNum;                      // ���ͳ����ײ͸���
    PU_TYPICAL_SCENE_MODE_E enSceneMode;           // ��ǰ����ĵ��ͳ����ײ�
    PU_TYPICAL_SCENE_INFO_S *pstTypicalSceneInfo;  // ��Ϣ�б�
    CHAR szReserved[PU_RESERVE_LEN];               // Ԥ���ֶ�,[0]��ʾ�������ͣ���PU_SCENE_PARAM_TYPE_E
} PU_TYPICAL_SCENE_LIST_EX_OUT_S, *LPPU_TYPICAL_SCENE_LIST_EX_OUT_S;

// �ƻ�����ʱ������ݽṹ
typedef struct PU_TIME_QUANTUM_INFO {
    ULONG ulTimeQuantumId;                            // ʱ��� ���� 1 ~ 8
    ULONG ulStartTime;                                // ��ʼʱ��:����ʱ��
    PU_TYPICAL_SCENE_MODE_E enSceneMode;              // ���ͳ�������
    ULONG ulEndTime;                                  // ����ʱ��:����ʱ��,ռ��֮ǰ��Reserve�ֶΡ�
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];  // Ԥ���ֶ�
} PU_TIME_QUANTUM_INFO_S;

// �ƻ�������ʱ������ݽṹ�б�
typedef struct PU_TIME_QUANTUM_LIST {
    ULONG ulTimeQuantumNum;  // ��Чǰ����ʱ��Σ�һ�㶼ΪMAX_TIMEQAUMTUM_NUM ֵ
    PU_TIME_QUANTUM_INFO_S stTimeQuantumInfo[PU_PLAN_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
} PU_TIME_QUANTUM_LIST_S, *LPPU_TIME_QUANTUM_LIST_S;

// �ƻ�����һ�����ݽṹ�б�
typedef struct PU_MONTHS_PLAN {
    ULONG ulMonth;  // ��Ӧ�·ݣ����Ϊ0��ʾ12���·�ȫ��Ҫ���ã�1~12���Ӧ���·���Ҫ����
    BOOL bEnable;   // ʹ�����
    PU_TIME_QUANTUM_LIST_S stTimeQaumtumMonths[PU_MONTH_NUM];
	ULONG ulChannelID;
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];  // szReserve[0]��Ҫʹ�ã�SDK�ڲ�ʹ��
} PU_MONTHS_PLAN_S, *LPPU_MONTHS_PLAN_S;

// ��ҹ����ISP�ײ�ģʽ�ṹ��
typedef struct PU_ISP_PROFILES_LINK_MODE {
    PU_ISP_IRCUT_MODULE_E enIRCMode;  // IRCUTģʽ����
    ULONG ulISPProfilesIndex;         // ISP�ײ�����
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_ISP_PROFILES_LINK_MODE_S, *LPPU_ISP_PROFILES_LINK_MODE_S;

// ��ҹ����ISP�ײ����ýṹ��
typedef struct PU_ISP_PROFILES_LINK_INFO {
    ULONG ulChannelID;
    BOOL bEnable;                                                   // �Ƿ�����ҹ����ISP�ײ�
    PU_ISP_PROFILES_LINK_MODE_S szLinkMode[PU_IRCUT_MODE_MAX_NUM];  // �����б�
    CHAR szReserved[PU_RESERVE_LEN];                                // Ԥ���ֶ�
} PU_ISP_PROFILES_LINK_INFO_S, *LPPU_ISP_PROFILES_LINK_INFO_S;

typedef struct PU_HARD_DISK_INFO {
    CHAR szHardDiskFac[FAC_NAME_LEN_MAX];
    PU_DISK_TYPE_E enHardDiskType;
    ULONG ulAllSpace;
    ULONG ulLeftSpace;
    ULONG ulUsedSpace;
    ULONG ulUsedPercentage;
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_HARD_DISK_INFO_S, *LPPU_PU_HARD_DISK_INFO_S;

/* ����״̬ */
typedef struct PU_HARD_DISK_STATE {
    ULONG ulDiskThreshold;               // �洢�ռ������޶�
    ULONG ulDiskState;                   // Ӳ��״̬ 0-����
    PU_HARD_DISK_INFO_S stHardDiskInfo;  // ������Ϣ
    CHAR szReserved[PU_RESERVE_LEN];     // Ԥ���ֶ�,szReserved[0]��ʾDiskID 0�Ŵ���ΪSD����1�Ŵ���ΪEMMC
} PU_HARD_DISK_STATE_S, *LPPU_HARD_DISK_STATE_S;

/* ����ID */
typedef struct PU_HARD_DISK {
    ULONG ulDiskId;                   // ���̱�ţ�0�Ŵ���ΪSD����1�Ŵ���ΪEMMC
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_HARD_DISK_S, *LPPU_HARD_DISK_S;

/* ����ģʽ */
typedef struct PU_NOISE_REDUCTION {
    ULONG ulChannelId;                               // ͨ����
    PU_NOISE_REDUCTION_MODE_E enNoiseReductionMode;  // ����ģʽ
    ULONG ulNRLevel;                                 // ��ͨģʽ����ϵ��
    ULONG ulSfcLevel;                                // ר��ģʽ������ϵ��
    ULONG ulTfcLevel;                                // ר��ģʽʱ����ϵ��
    CHAR szReserved[PU_RESERVE_LEN];                 // Ԥ���ֶ�

} PU_NOISE_REDUCTION_S, *LPPU_NOISE_REDUCTION_S;

// ��˽��������
typedef struct PU_MASK_AREA_PARA {
    PU_IGT_POINT_S stAreaPara[PRIVACY_AREA_POINTS_NUM];
    ULONG ulColor;  // ��ɫ
    UCHAR ucAlpha;  // ͸����&������ �ȼ����ݲ�֧��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_MASK_AREA_PARA_S, *LPPU_MASK_AREA_PARA_S;

typedef struct PU_MASK_AREA_PARA_V20 {
    PU_IGT_POINT_S stAreaPara[PRIVACY_AREA_POINTS_NUM];  // �����˱���Ϊ����
    ULONG ulColor;
    UCHAR ucAlpha;
    ULONG ulIndex;  // ������Χ����˽����[1~16]/[19~34]��������[17/18]/[35~64]��V2�汾�ӿ�����ʱ����
    CHAR szReserve[PU_RESERVE_LEN];
} PU_MASK_AREA_PARA_V20_S, *LPPU_MASK_AREA_PARA_V20_S;

typedef struct PU_ADD_MASK_PARA {
    ULONG ulChnID;
    ULONG ulIndex;
    PU_MASK_AREA_PARA_S stMaskAreaPara;
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ADD_MASK_PARA_S;

typedef struct PU_DEL_MASK_PARA {
    ULONG ulChnID;
    ULONG ulIndex;
    CHAR szReserve[PU_RESERVE_LEN];
} PU_DEL_MASK_PARA_S;

// ��˽�����б�
typedef struct PU_PRIVACY_MASK_AREA_ARRAY {
    ULONG ulChannelID;
    ULONG ulNum;
    BOOL bEnable;
    PU_MASK_AREA_PARA_S stMaskParaEx[PU_PRIVACY_MASK_MAX];
    CHAR szReserve[PU_RESERVE_LEN];
} PU_PRIVACY_MASK_AREA_ARRAY_S, *LPPU_PRIVACY_MASK_AREA_ARRAY_S;

// ��˽�����б�
typedef struct PU_PRIVACY_MASK_AREA_LIST {
    ULONG ulChnID;
    ULONG ulTotalNum;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;
    BOOL bEnable;
    PU_MASK_AREA_PARA_V20_S stMaskPara[PU_PRIVACY_MASK_MAX];
    CHAR szReserve[PU_RESERVE_LEN];
} PU_PRIVACY_MASK_AREA_LIST_S, *LPPU_PRIVACY_MASK_AREA_LIST_S;

// ��˽�����б�
typedef struct PU_PRIVACY_MASK_AREA_LIST_V2 {
    ULONG ulChnID;
    ULONG ulTotalNum;  // ��˽����������������������Ŀ
    BOOL bEnable;
    ULONG ulBeginIndex;
    ULONG ulEndIndex;                                            //
    PU_MASK_AREA_PARA_V20_S stMaskPara[PU_PRIVACY_MASK_MAX_V2];  // ��˽������֧�������ı���
    ULONG ulMascNum;                                             // ��������������Ŀ
    PU_MASK_AREA_PARA_V20_S stMascPara[PU_PRIVACY_MOSAIC_MAX];   // �����ˣ�֧�־��Σ�ȫ������������ֵ32����֧ͨ��4��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_PRIVACY_MASK_AREA_LIST_V2_S, *LPPU_PRIVACY_MASK_AREA_LIST_V2_S;

typedef struct PU_IPCA_RULES {
    BOOL bEnable;
    ULONG ulPeriod;                     // ����
    USHORT usSrcPort;                   // Դ�˿�
    USHORT usDstPort;                   // Ŀ�Ķ˿�
    CHAR szSrcIP[PU_IP4_ADDR_LEN];      // ԴIP
    CHAR szDstIP[PU_IP4_ADDR_LEN];      // Ŀ��IP
    PU_PROTOCOL_TYPE_E enProtocolType;  // Э������
    ULONG ulInstanceId;                 // ��Ԫ�����Ψһ��ʶ
    CHAR szMcpIp[PU_IP4_ADDR_LEN];      // MAC
    CHAR szDcpIp[PU_IP4_ADDR_LEN];      // DCP
    ULONG ulTlpId;                      // TLP
    ULONG ulMcpPort;                    // MCP PORT
    CHAR szReserve[PU_RESERVE_LEN];
} PU_IPCA_RULES_S;

/*******************************************************************************************************************/
/* SDK ISP Parameter Declaration */
/*******************************************************************************************************************/

/* �عⲹ�� */
typedef struct PU_CAM_EXPCOMP_PARA {
    PU_COMMONMODE_SWITCH_E enExpComp;  // �عⲹ��(�رա���)
    LONG lExpComp;                     // ϵ�� 0~255
    CHAR szReserve[PU_RESERVE_LEN];
} PU_EXPCOMP_PARA_S;

/* ��ƽ�����ã��ֶ�ʱR��Bֵ����΢�� */
typedef struct PU_CAM_WB_MANUAL_PARA {
    PU_CAM_WB_MODE_E enWBMode;  // ��ƽ��ģʽ
    ULONG ulROffset;            // Rֵǿ���� 0~255
    ULONG ulBOffset;            // Bֵǿ���� 0~255
    ULONG ulRStrong;            // Rֵ΢���� 0~255
    ULONG ulBStrong;            // Bֵ΢���� 0~255
    ULONG ulHighTemp;           // ɫ������   1500~10000k
    ULONG ulLowTemp;            // ɫ������   1500~10000k
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG) - sizeof(ULONG)];
} PU_WB_MANUAL_PARA_S;

/* ��̬���� */
typedef struct PU_CAM_WD_PARA {
    PU_COMMONMODE_SWITCH_E enSwitchMode;  // ����(�رա��򿪡��Զ�)
    PU_VIDEO_WD_MODE_E enWDMode;          // ��̬ģʽ  ΪWD_MODE_RATIOFIXֵ��Ҫ����lExpRatio
    LONG lExpRatio;                       // ���᣺x1~x64,������127
    ULONG ulAutoModeMaxExpRatio;          // ���Զ���̬ģʽ�������ع����ֵ TI:1~16��Ĭ��8
    CHAR szReserve[PU_RESERVE_LEN];
} PU_WD_PARA_S;

/* ��ҹģʽ */
typedef struct PU_BLACKWHITE_MODE {
    PU_VIDEO_BLACKWHITE_MODE_E enBKMode;  // ��Ƶģʽ
} PU_BLACKWHITE_MODE_S;

/* ����������ģʽ */
typedef struct PU_CAM_SLOW_SHUTTER_MODE {
    PU_COMMONMODE_SWITCH_E enSlowShutterMode;  // ����������ģʽ
    PU_CAM_SHUTTER_MODE_E enShutterValue;      // ����ֵ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_SLOW_SHUTTER_MODE_S;

/* ���ò��ģʽ */
typedef struct PU_AEMETERING_MODE {
    PU_COMMONMODE_SWITCH_E enAEMeterSwitch;            // ����(�رա���)
    PU_VIDEO_AEMETERING_MODE_E enAEMetering;           // ���ģʽ(֧�����Ĳ�⡢ƽ����⡢�û��Զ���)
    UCHAR aucAreaWeight[VW_ZONE_ROW][VW_ZONE_COLUMN];  // �ع�����Ȩ��,Range:[0, 0xF]
    CHAR szReserve[PU_RESERVE_LEN];
} PU_AEMETERING_MODE_S;

/* ���ŷ�Χ */
typedef struct PU_SHUTTER_VALUE {
    PU_COMMONMODE_SWITCH_E enShutterMode;  // ����ģʽ
    PU_CAM_SHUTTER_MODE_E enShutterValue;  // ����ֵ
    LONG lShutterValueSlow;                // �Զ������ֵ(us)
    LONG lShutterValueFast;                // �Զ����������(us)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_SHUTTER_VALUE_S;

/* ���ⲹ��ģʽ */
typedef struct PU_BACKLIGHT_MODE {
    PU_COMMONMODE_SWITCH_E enBackLightMode;  // ģʽ����(�رա���)
    LONG lBackLight;                         // ������Χ0~255
    BACKLIGHT_MODE_E enMode;                 // ���ⲹ��ģʽ
    PU_AREA_INFO_S stAreaInfo;               // ���ⲹ������
    CHAR szReserve[12];
} PU_BACKLIGHT_MODE_S;

/* IRC���� */
typedef struct PU_IRC_PARA {
    PU_IRC_MODE_E enIRCMode;                  // ��ҹģʽ
    ULONG ulDayToNightThreshold;              // ��ת��������
    ULONG ulNightToDayThreshold;              // ��ת��������
    ULONG ulSwitchLevel;                      // �ⲿ�澯����ת�ڰ�0���͵�ƽ 1���ߵ�ƽ
    PU_IRC_TRIGGER_MODE_E enIRCutSwitchMode;  // ��ҹģʽ������ʽ��Ĭ��IRC_LUM_TRIGGER
    PU_COMMONMODE_SWITCH_E enPolarzerMode;    // ƫ��Ƭ����ģʽ
    CHAR szReserve[PU_RESERVE_LEN - sizeof(PU_COMMONMODE_SWITCH_E)];
} PU_IRC_PARA_S;

/* ���ƻ�о���� */
typedef struct PU_GAIN_CONTROL {
    PU_COMMONMODE_SWITCH_E enGainSwitch;  // ��о������ƿ���(�رա���)
    PU_GAIN_TYPE_E enGainType;            // ��о��������
    ULONG ulGainValue;                    // ����ֵ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_GAIN_CONTROL_S;

/* ��о�������� */
typedef struct PU_STABILIZER_PARA {
    PU_COMMONMODE_SWITCH_E enStabilizerMode;  // ģʽ����
    LONG lStabilizerLevel;                    // ��������
    LONG lEfl;                                // ��Ч����
    CHAR szReserve[PU_RESERVE_LEN];
} PU_STABILIZER_PARA_S;

/* ���ƻ�о��Ȧ */
typedef struct PU_IRIS_CONTROL {
    PU_COMMONMODE_SWITCH_E enIris;  // ���ƻ�о��Ȧ(DC)
    PU_IRIS_VALUE_E enIRISValue;    // ��Ȧֵ(P-Iris)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_IRIS_CONTROL_S;

/* ������� */
typedef struct PU_DEFOG_PARA {
    PU_COMMONMODE_SWITCH_E enDefog;  // ȥ����
    ULONG ulDefogLevel;              // ȥ��ȼ�
    ULONG ulDefogSensitivity;
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_DEFOG_PARA_S;

/* ����DRC */
typedef struct PU_IMG_DRC {
    PU_COMMONMODE_SWITCH_E enDRC;
    ULONG ulDRCStrength;  // ��˼0~255 TI 0~255
    CHAR szReserve[PU_RESERVE_LEN];
} PU_IMG_DRC_S;

/* ǿ������ */
typedef struct PU_ISP_HLC {
    PU_COMMONMODE_SWITCH_E enHlc;  // ǿ������ģʽ(�رա���)
    ULONG ulHlcLevel;              // panasonic�ȼ�1-3
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ISP_CAM_HLC_S;

// ����Ȥ����������(΢���ڳ��Ʋ��/��������������)
typedef enum PU_ROIMETER_TYPE {
    ROIMETER_TYPE_FACE = 0,  // �����ع�
    ROIMETER_TYPE_VEHICLE,   // �����ع�
    ROIMETER_TYPE_INVALID,
} PU_ROIMETER_TYPE_E;

// ΢���ڸ���Ȥ���������
typedef struct PU_ROI_METER_MODE {
    PU_COMMONMODE_SWITCH_E enRoiMeter;  // ������
    ULONG ulRoiMeterLevel;              // ����1~100
} PU_ROI_METER_MODE_S;

// P-IRIS��Ȧ������
typedef enum PU_CAM_P_IRIS_TYPE {
    CAM_P_IRIS_HV1250P = 0,   // Piris��hall��Ȧ
    CAM_P_IRIS_HV03617P = 1,  // �ͻ���ѡ��ͷ����
    CAM_P_IRIS_BUTT,
} PU_CAM_P_IRIS_TYPE_E;

/* ISP��ϸ���� */
typedef struct PU_ISP_PARTICULAR_PARA {
    ULONG ulChannelID;                          // ͨ����
    ULONG ulBitMap;                             // �޸�λ ����λ��AE�ع�ģʽ��ʼ����ISP�ײͳ���������ȫУ�飬���ֶβ���Ч
    PU_AE_MODE_E enAEMode;                      // AE�ع�ģʽ1
    LONG lAEResponseTime;                       // AE��Ӧʱ��2
    PU_EXPCOMP_PARA_S stCamExpcompPara;         // �عⲹ��3
    PU_WB_MANUAL_PARA_S stCamWBManualPara;      // ��ƽ��4
    PU_WD_PARA_S stCamWDPara;                   // ��̬5
    PU_SLOW_SHUTTER_MODE_S stSlowShutterMode;   // �����ſ���6-----ITS���͡����㷨���ͣ�����ģʽ����֧��
    PU_VIDEO_FLICKER_MODE_E enCamFlickerMode;   // ����Ƶ��7
    PU_AEMETERING_MODE_S stCamAEMeterMode;      // AE���ģʽ8
    PU_SHUTTER_VALUE_S stCamshutterValue;       // ���ŷ�Χ����ֵ9
    PU_BACKLIGHT_MODE_S stCamBackLightMode;     // ���ⲹ��ģʽ10
    PU_IRC_PARA_S stCamIRCPara;                 // ��ҹģʽ11
    LONG lAutoGainMaxValue;                     // �Զ��������ֵ12
    PU_GAIN_CONTROL_S stCamGainControl;         // ��о�������13
    PU_NOISE_REDUCTION_S stCamDenoisePara;      // ����ģʽ14
    PU_STABILIZER_PARA_S stCamStabilizerPara;   // ��о����ģʽ15
    PU_IRIS_CONTROL_S stCamIrisControl;         // ���ƻ�о��Ȧ16
    PU_DEFOG_PARA_S stISPDefogPara;             // ȥ��Ч��17
    PU_IMG_DRC_S stImgDRCPara;                  // DRC����18
    PU_MIN_FOCUS_E enMinFocusValue;             // ��С�۽�����ֵ19
    PU_ISP_CAM_HLC_S stHlc;                     // ǿ������20
    PU_IRIS_TYPE_E enIrisType;                  // Iris����21
    PU_CAM_SHUTTER_MODE_E enShutterValueLimit;  // ��������22(Υ��ץ�ķ�ʽΪ������ʱ��������)
    PU_ROI_METER_MODE_S stCamRoiMeterMode;      // ΢���ڸ���Ȥ������23
    PU_ROIMETER_TYPE_E enRoiMeterType;          // �عⲹ������
    ULONG ulFaceExposureTime;                   // �����ع�ʱ�� 10~300
    CHAR enPirisType;                           // P-IRIS��Ȧ������,�μ�PU_CAM_P_IRIS_TYPE_E
    CHAR enCamBlackWhiteMode;                   // ��ҹģʽ24���μ�PU_VIDEO_BLACKWHITE_MODE_E
    PU_ISP_GAMMA_S stImageGammaCtrl;            // GAMMA����25
    CHAR enLensType;                            // ��ͷ����26���μ�PU_LENS_TYPE_E
    CHAR enSceneType;                           // ISP����ģʽ27���μ�PU_ISP_SCENE_TYPE_E
    CHAR szReserve[PU_RESERVE_LEN - sizeof(PU_ROI_METER_MODE_S) - sizeof(PU_ROIMETER_TYPE_E) - sizeof(ULONG) - 4 * sizeof(CHAR) - sizeof(PU_ISP_GAMMA_S)];
} PU_ISP_PARTICULAR_PARA_S, *LPPU_ISP_PARTICULAR_PARA_S;

/* CVBS���� */
typedef struct PU_CVBS_PARA {
    ULONG ulChannelID;                  // ͨ��ID
    BOOL bEnable;                       // ʹ�����
    PU_RESOLUTION_TYPE_E enResolution;  // �ֱ���
} PU_CVBS_PARA_S;

/* ��Ƶ������� */
typedef struct PU_VIDEO_ENCODE_PARA {
    PU_STREAM_MODE_E enVideoStreamMode;                              // ���ײͷ�ʽ
    BOOL bDynamicFrmRateEnable;                                      // ��̬֡���Ƿ�ʹ��
    ULONG ulDynamicFrmRate;                                          // ��̬֡��
    BOOL bDynamicBitRateEnable;                                      // ��̬�����Ƿ�ʹ��
    ULONG ulDynamicBitRate;                                          // ��̬����
    PU_FRAMERATE_FORMAT_E enFrameMat;                                // ��Ƶ�ɼ�֡��ʽ
    PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_ENC_STREAM_MAX_NUM];  // ��Ƶ����
    CHAR szReserve[PU_RESERVE_LEN];                                  // szReserved[0]��ʶ��խ��ģʽ 0:���� 1:խ��
} PU_VIDEO_ENCODE_PARA_S;

/* �����ײͲ��� */
typedef struct PU_STREAM_PROFILES_PARA {
    ULONG ulIndex;                                // Ψһ��ʶ 1-4�ǻ������ò���ɾ��,0��ʾ�Զ�����
    CHAR szName[STREAMPROFILES_NAME_LEN];         // ����
    CHAR szDescrip[STREAMPROFILES_NAME_LEN * 2];  // ����
    PU_VIDEO_ENCODE_PARA_S stVideoEncodePara;     // ��Ƶ������
    PU_AUDIO_INFO_S stAudioInfo;                  // ��Ƶ����
    BOOL bAiVqeStatus;                            // ��Ƶ������ǿ
    BOOL bCorridorEnable;                         // ����ģʽ
    CHAR szReserve[PU_RESERVE_LEN];               // Ԥ��
} PU_STREAM_PROFILES_PARA_S;

/* �����ײ� */
typedef struct PU_CHANNEL_STREAM_PROFILES {
    ULONG ulChannelID;                               // ͨ��ID
    PU_STREAM_MANIPULATE_TYPE_E enStreamOptionType;  // ��������
    PU_STREAM_PROFILES_PARA_S stStreamProfilesPara;  // �����ײͲ���
    CHAR szReserve[PU_RESERVE_LEN];                  // Ԥ��
} PU_CHANNEL_STREAM_PROFILES_S;

/* ��Ƶ�������V2������ */
typedef struct PU_VIDEO_ENCODE_PARAV2 {
    PU_STREAM_MODE_E enVideoStreamMode;                                 // ���ײͷ�ʽ
    BOOL bDynamicFrmRateEnable;                                         // ��̬֡���Ƿ�ʹ��
    ULONG ulDynamicFrmRate;                                             // ��̬֡��
    BOOL bDynamicBitRateEnable;                                         // ��̬�����Ƿ�ʹ��
    ULONG ulDynamicBitRate;                                             // ��̬����
    PU_FRAMERATE_FORMAT_E enFrameMat;                                   // ��Ƶ�ɼ�֡��ʽ
    PU_STREAM_ATTRIBUTE_S stStreamAttribute[PU_ENC_STREAM_MAX_NUM_V2];  // ��Ƶ����
    CHAR szReserve[PU_RESERVE_LEN];                                     // szReserved[0]��ʶ��խ��ģʽ 0:���� 1:խ��
} PU_VIDEO_ENCODE_PARAV2_S;

/* �����ײͲ���V2������ */
typedef struct PU_STREAM_PROFILES_PARAV2 {
    ULONG ulIndex;                                // Ψһ��ʶ 1-4�ǻ������ò���ɾ��,0��ʾ�Զ�����
    CHAR szName[STREAMPROFILES_NAME_LEN];         // ����
    CHAR szDescrip[STREAMPROFILES_NAME_LEN * 2];  // ����
    PU_VIDEO_ENCODE_PARAV2_S stVideoEncodePara;   // ��Ƶ������
    PU_AUDIO_INFO_S stAudioInfo;                  // ��Ƶ����
    BOOL bAiVqeStatus;                            // ��Ƶ������ǿ
    BOOL bCorridorEnable;                         // ����ģʽ
    CHAR szReserve[PU_RESERVE_LEN];               // Ԥ��
} PU_STREAM_PROFILES_PARAV2_S;

/* �����ײ�V2������ */
typedef struct PU_CHANNEL_STREAM_PROFILESV2 {
    ULONG ulChannelID;                                 // ͨ��ID
    PU_STREAM_MANIPULATE_TYPE_E enStreamOptionType;    // ��������
    PU_STREAM_PROFILES_PARAV2_S stStreamProfilesPara;  // �����ײͲ���
    CHAR szReserve[PU_RESERVE_LEN];                    // Ԥ��
} PU_CHANNEL_STREAM_PROFILESV2_S;

/* ����https֤�� */
typedef struct PU_CREATE_HTTPS_CERT {
    CHAR szCommonName[PU_CERT_FIELD_NAME_LEN_MAX];    // ֤��CN
    CHAR szCountry[PU_CERT_FIELD_NAME_LEN_MAX];       // ����
    CHAR szState[PU_CERT_FIELD_NAME_LEN_MAX];         // ʡ/��
    CHAR szLocation[PU_CERT_FIELD_NAME_LEN_MAX];      // ����
    CHAR szOrganization[PU_CERT_FIELD_NAME_LEN_MAX];  // ��֯
    CHAR szUnit[PU_CERT_FIELD_NAME_LEN_MAX];          // ��λ
    CHAR szEmail[PU_CERT_FIELD_NAME_LEN_MAX];         // �ʼ���ַ
    ULONG ulExpiredDays;                              // ��Ч����
    CHAR szCreateCertPsw[STREAMPROFILES_NAME_LEN];    // ����֤���Pwd
    CHAR szReserve[PU_RESERVE_LEN];
} PU_CREATE_HTTPS_CERT_S;

// IP��ַ���˹���
typedef struct PU_IPFILTER_RULES {
    CHAR szIPAddress[PU_IP4_ADDR_LEN];      // ���˵�IP��ַ
    CHAR szSubNetAddress[PU_IP4_ADDR_LEN];  // ���˵���������
    ULONG ulIpBeginPort;                    // ������ʼ�˿�
    ULONG ulIpEndPort;                      // ������ֹ�˿�
    PU_IP_PROTOCOL_TYPE_E enProtocolType;   // ���˸�Э�����ݰ�
    BOOL bStatus;                           // IP���˹���״̬����Ч��δ��Ч
    CHAR szReserve[PU_RESERVE_LEN];
} PU_IPFILTER_RULES_S;
// IP��ַ����
typedef struct PU_IPFILTER_RULES_INFO {
    BOOL bIpFilterEnable;                                           // �Ƿ�����IP����
    PU_IP_FILTER_STRATEGY_E enIpFilterStrategy;                     // IP���˲���:������ or ������
    ULONG ulIpFilterRulesNum;                                       // IP��ַ������Ŀ
    PU_IPFILTER_RULES_S stIpFilterRulesList[PU_IP_FILTER_NUM_MAX];  // IP��ַ�����б�
    CHAR szReserve[PU_RESERVE_LEN];

} PU_IPFILTER_RULES_INFO_S;

// IP����ƥ�䷽ʽ
typedef enum PU_IPFILTER_MATCH_TYPE {
    MATCH_IP = 0,          // ��IPƥ��ʱ���й���
    MATCH_MAC = 1,         // ��MACƥ��ʱ���й���
    MATCH_IP_AND_MAC = 2,  // ��IP��MAC��ƥ��ʱ���й���
} PU_IPFILTER_MATCH_TYPE_E;

// IP��ַ���˹���
typedef struct PU_IPFILTER_RULESV2 {
    PU_IPFILTER_MATCH_TYPE_E enMatchType;        // ƥ�䷽ʽ
    CHAR szIPAddress[PU_IP4_ADDR_LEN];           // ���˵�IP��ַ
    CHAR szSubNetAddress[PU_IP4_ADDR_LEN];       // ���˵���������
    ULONG ulIpBeginPort;                         // ������ʼ�˿�
    ULONG ulIpEndPort;                           // ������ֹ�˿�
    PU_IP_PROTOCOL_TYPE_E enProtocolType;        // ���˸�Э�����ݰ�
    CHAR szMACAddress[PU_HEX_MAC_ADDR_LEN + 1];  // ���˵�MAC��ַ
    BOOL bStatus;                                // IP���˹���״̬����Ч��δ��Ч
    CHAR szReserve[PU_RESERVE_LEN];              // szReserve[0],Ӧ�õ�����,0:Ӧ��������1,1:Ӧ��������2,�Դ�����,
    // 64:Ӧ������������
} PU_IPFILTER_RULESV2_S;
// IP��ַ����
typedef struct PU_IPFILTER_RULES_INFOV2 {
    BOOL bIpFilterEnable;                                               // �Ƿ�����IP����
    PU_IP_FILTER_STRATEGY_E enIpFilterStrategy;                         // IP���˲���:������ or ������
    ULONG ulIpFilterRulesNum;                                           // IP��ַ������Ŀ
    PU_IPFILTER_RULESV2_S stIpFilterRulesList[PU_IP_FILTER_NUM_MAXV2];  // IP��ַ�����б�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_IPFILTER_RULES_INFOV2_S;

typedef struct PU_IPFILTER_RULES_INFOV3 {
    BOOL bIpFilterEnable;                                               // �Ƿ�����IP����
    PU_IP_FILTER_STRATEGY_E enIpFilterStrategy;                         // IP���˲���:������ or ������
    ULONG ulIpFilterRulesNum;                                           // IP��ַ������Ŀ
    PU_IPFILTER_RULESV2_S stIpFilterRulesList[PU_IP_FILTER_NUM_MAXV3];  // IP��ַ�����б�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_IPFILTER_RULES_INFOV3_S;

// �۽���������
typedef struct PU_PTZ_FOCUSAREA {
    ULONG ulChannelID;                                      // ͨ��ID
    ULONG ulFocusArea[PU_FOCUSAREA_ROW][PU_FOCUSAREA_COL];  // �Զ��۽���������
} PU_PTZ_FOCUSAREA_S;

/* 802.1x EAP-TLS֤���ϴ� */
typedef struct PU_DOT1X_TLS_CERT_UPLOAD {
    PU_DOT1X_TLS_CERT_UPLOAD_TYPE_E enAction;  // �ϴ�����
    CHAR szPassword[PU_PASSWORD_LEN];          // ˽Կ�ļ��ļ���Pwd
} PU_DOT1X_TLS_CERT_UPLOAD_S;

/* SDK TLS֤���ϴ� */
typedef struct PU_SDK_TLS_CERT_UPLOAD {
    CHAR szCaFile[PU_CONFIG_FILE_PATH_MAX];
    CHAR szCertFile[PU_CONFIG_FILE_PATH_MAX];
    CHAR szKeyFile[PU_CONFIG_FILE_PATH_MAX];
    CHAR szPassword[PU_PASSWORD_LEN];  // ˽Կ�ļ��ļ���Pwd
} PU_SDK_TLS_CERT_UPLOAD_S;

/* licence�ļ��ϴ����� */
typedef enum PU_LICENCE_UPLOAD_TYPE {
    PU_LICENCE_ITGT_UPLOAD_TYPE = 0,
    PU_LICENCE_OTHER_UPLOAD_TYPE,
    PU_LICENCE_UPLOAD_TYPE_MAX
} PU_LICENCE_UPLOAD_TYPE_E;

/* licence�ļ��ϴ� */
typedef struct PU_LICENCE_FILE_UPLOAD {
    PU_LICENCE_UPLOAD_TYPE_E enLicenceType;       // �ϴ�����
    CHAR szLicenceFile[PU_CONFIG_FILE_PATH_MAX];  // �ļ�·��
} PU_LICENCE_FILE_UPLOAD_S;

// ��ֱ��λ
typedef struct PU_VERTICAL_LIMIT {
    INT iVerticalLimit;  // ��ֱ��λ
    ULONG ulChannelId;   // ͨ��ID
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_VERTICAL_LIMIT_S;

// DDNS
typedef struct PU_DDNS_CONF_INFO {
    BOOL bEnable;
    CHAR szUserID[PU_DDNS_MAX_LEN];   // �û��˺���
    CHAR szUserPWD[PU_DDNS_MAX_LEN];  // �û�Pwd����
    CHAR szReserve[PU_RESERVE_LEN];   // szReserve[0],Ӧ�õ�����,0:����1,1:����2,�Դ�����,
} PU_DDNS_CONF_INFO_S;
// ����Ԥ��λ����ʹ��
typedef struct PU_PTZ_PRESET_FREEZE {
    ULONG ulChannelID;   // ͨ��ID
    BOOL bFreezeEnable;  // ʹ��
} PU_PTZ_PRESET_FREEZE_S;

/* ISP�ײͳ����������� */
typedef struct PU_ISP_SCENE_PARA {
    ULONG ulIndex;                                  // Ψһ��ʶ 1-4�ǻ������ò���ɾ��������ʱ��0���޸ġ�ɾ��������ָ������
    CHAR szName[PU_TYPICAL_SCENE_NAME_LEN];         // ���ͳ�������������
    CHAR szDescrip[PU_TYPICAL_SCENE_DESCRIBE_LEN];  // ����
    PU_ISP_PARTICULAR_PARA_S stSceneModeISP;        // ISP����
    PU_VIDEO_DISPLAY_INFO_S stVideoDisplayPara;     // ��ƵЧ��
    PU_IRLIGHT_LIST_S stIrLightArrayPara;           // ���������
    CHAR szReserved[PU_RESERVE_LEN];                // Ԥ���ֶ�
} PU_ISP_SCENE_PARA_S;

/* ISP������������ */
typedef enum PU_SCENE_PARAM_TYPE {
    PU_SCENE_PARAM_COMM = 0,      // ����ͨ�ó�������
    PU_SCENE_PARAM_SNAPSHOT = 1,  // ����ITSץ��/���㷨�����豸����ģʽ��΢����������	
    PU_SCENE_PARAM_HUMAN = 2,     // �������㷨�����豸�˿�ģʽ/��Ϊ����ģʽ��������	
    PU_SCENE_PARAM_VEHICLE = 3,   // �������㷨�����豸΢��ģʽ��������	
    PU_SCENE_PARAM_MAX
} PU_SCENE_PARAM_TYPE_E;

/* ISP�ײͲ������� */
typedef struct PU_ISP_PROFILES_PARA {
    ULONG ulChannelID;                          // ͨ����
    PU_OPT_TYPE_E enOptionType;                 // ��������
    PU_ISP_SCENE_PARA_S stClassiscalScenePara;  // ISP�ײͳ�������
    CHAR szReserved[PU_RESERVE_LEN];            // Ԥ���ֶ�,[0]��ʾ�������ͣ���PU_SCENE_PARAM_TYPE_E
} PU_ISP_PROFILES_PARA_S;

/* ISP���ͳ���ģʽ */
typedef struct PU_ISP_TYPICAL_SCENE_MODE {
    ULONG ulChannelID;                  // ͨ����
    PU_SCENE_PARAM_TYPE_E enParamType;  // ��������
    PU_TYPICAL_SCENE_MODE_E enMode;     // ����ģʽ
    CHAR szReserved[PU_RESERVE_LEN];    // Ԥ���ֶ�
} PU_ISP_TYPICAL_SCENE_MODE_S;

// ����۽�������Ϣ
typedef struct PU_FOCUS_COMPENSATION_S {
    ULONG ulChannelId;  // ͨ��ID
    BOOL bEnable;       // ʹ�ܿ���
} PU_FOCUS_COMPENSATION_S;

/* ץ�Ŀռ����� */
typedef struct PU_SNAPSHOT_SPACE {
    ULONG ulPercentDecimal;  // ץ�Ŀռ�ռ�ٷֱ�(С������(2λ��Ч,��ȷ���ٷ�λ,1��ʾ0.01%))
    ULONG ulPercentInt;      // ץ�Ŀռ�ռ�ٷֱ�(��������)
} PU_SNAPSHOT_SPACE_S;

/* ��ʱץ�Ĳ��� */
typedef struct PU_SNAPSHOT_TIMING_PARA {
    BOOL bEnable;                          // �Ƿ����ö�ʱץ�Ĺ���
    ULONG ulChannelID;                     // ͨ��ID
    ULONG ulStreamID;                      // ����ID
    ULONG ulSnapCount;                     // ץ�ļ��(��)
    PU_SNAPSHOT_FORMAT_E enPictureFormat;  // ͼƬ��ʽ
    CHAR szReserved[PU_RESERVE_LEN];       // Ԥ���ֶ�
} PU_SNAPSHOT_TIMING_PARA_S;

/* FTP�ϴ����� */
typedef struct PU_FTP_FILE_UPLOAD_PARA {
    BOOL bSnapPic;                                      // �Ƿ��ϴ�ץ��ͼƬ
    PU_FTP_UPLOAD_PROTOCOL_TYPE_E enProtocol;           // �ϴ�Э��
    CHAR szServerIP[PU_IP4_ADDR_LEN];                   // ������IP��ַ
    ULONG ulServerPort;                                 // �������˿�
    CHAR szUserName[PU_CLIENT_USERNAME_LEN];            // �û���
    CHAR szUserPwd[PU_PASSWORD_LEN];                    // Pwd
    PU_FTP_UPLOAD_DIR_TYPE_E enDirType;                 // �ϴ�Ŀ¼�ṹ
    PU_FTP_UPLOAD_FIRST_DIR_TYPE_E enFirstDirType;      // �ϴ�һ��Ŀ¼����
    PU_FTP_UPLOAD_SECOND_DIR_TYPE_E enSecondDirType;    // �ϴ�����Ŀ¼����
    PU_FTP_UPLOAD_FILE_NAMING_RULE_E enFileNamingRule;  // �ϴ��ļ���������
    CHAR szFirstDir[PU_FTP_UPLOAD_PATH_LEN];            // �Զ���һ��Ŀ¼��
    CHAR szSecondDir[PU_FTP_UPLOAD_PATH_LEN];           // �Զ������Ŀ¼��
    CHAR szSubPoliceCode[PU_SUBPOLICE_LEN];             // �ɳ�������ֶ�
    // CHAR szReserved[0];                                    //Ԥ���ֶ�,�ѱ�subPoliceCodeʹ�ã��ɳ������
} PU_FTP_FILE_UPLOAD_PARA_S;

/* ¼��ƻ����� */
typedef struct PU_TIME_PLAN_LIST {
    ULONG ulCycle;      // ���ڿ��ƣ�0����һ�Σ�1��ÿ�ն�����ʱ���
    ULONG ulStartTime;  // ��ʼʱ��:��0�㿪ʼ
    ULONG ulEndTime;    // ����ʱ��:��0�㿪ʼ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_TIME_PLAN_LIST_S;

/* ǰ��¼��ƻ� */
typedef struct PU_LOCAL_RECORD_PLAN {
    BOOL bEnable;                                                 // �Ƿ����üƻ�����¼��
    ULONG ulChannelID;                                            // ͨ��ID
    ULONG ulTotalNum;                                             // �ܼ�¼��
    ULONG ulBeginIndex;                                           // ��ǰ��ʼ��¼��
    ULONG ulEndIndex;                                             // ��ǰ������¼��
    PU_TIME_PLAN_LIST_S szRecordPlanList[PU_RECORD_PLAN_NUM_SD];  // ¼��ƻ�����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_LOCAL_RECORD_PLAN_S;

/* �˳�����ṹ�� */
typedef struct PU_HV_ALARM_PARA {
    ULONG ulChannelId;  // ͨ��ID
    BOOL bEnable;       // ʹ��
} PU_HV_ALARM_PARA_S;

/******************Ŀ����ɫ��ȡ�ṹ��****************************************/
typedef struct PU_COLOR_ALARM_PARA {
    ULONG ulChannelId;  // ͨ��ID
    BOOL bEnable;       // ʹ��
} PU_COLOR_ALARM_PARA_S;

// �佹���Ƽ������
typedef struct CAM_FOCUSCTRL {
    ULONG ulChannelId;  // ͨ��ID
    PU_CAMCTRL_E enFocus;
    ULONG ulFocusSpeed;  // ����0~7�ף�����31��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_CAM_FOCUSCTRL_S;

// �ֶ�ץ�Ĳ���
typedef struct SNAPSHOT_PARA {
    ULONG ulChannelID;                             // ͨ��ID
    ULONG ulStreamID;                              // ����ID(Ŀǰ��֧��������)
    PU_RESOLUTION_TYPE_E enResolution;             // �ֱ���(�ݲ�֧������,���������ֱ���Ϊ׼)
    PU_SNAPSHOT_FORMAT_E enPictureFormat;          // ͼƬ��ʽ(Ŀǰ��֧��JPEG��ʽ)
    CHAR szPicPath[PU_SNAPSHOT_PIC_PATH_LEN + 4];  // ץ���ļ�Ŀ¼
    CHAR szReserved[PU_RESERVE_LEN];               // Ԥ��
} PU_SNAPSHOT_PARA_S;

// �ֶ�ץ�Ĳ���
typedef struct SNAPSHOT_PARA_V2 {
    ULONG ulChannelID;                             // ͨ��ID
    ULONG ulStreamID;                              // ����ID(Ŀǰ��֧��������)
    PU_RESOLUTION_TYPE_E enResolution;             // �ֱ���(�ݲ�֧��ͨ���ýӿ�����,��ץ�ķֱ������õ�Ϊ׼)
    PU_SNAPSHOT_FORMAT_E enPictureFormat;          // ͼƬ��ʽ(Ŀǰ��֧��JPEG��ʽ)
    CHAR *pPicBuf;                                  // ץ��ͼƬ����(��Ԥ���㹻����)
    ULONG ulPicBufLen;                                // ץ��ͼƬ����������(��α�ʶ���������ȣ����α�ʶͼƬʵ�ʳ���)
    CHAR szReserved[PU_RESERVE_LEN];               // Ԥ��
} PU_SNAPSHOT_PARA_V2_S;

// ץ��ͼƬ��������
typedef struct PU_SNAPSHOT_QUAILTY_PARA {
    ULONG ulChannelID;                // ͨ����(�ݲ�֧��)
    PU_SNAPSHOT_QUALITY_E enQuality;  // ץ��ͼƬ����
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ��
} PU_SNAPSHOT_QUAILTY_PARA_S;

// ͼ�������ж�����
typedef struct PU_IMG_QUALITY_JUDGE {
    ULONG ulChannelId;                                // ͨ��ID
    PU_IMG_QUALITY_JUDGE_TYPE_E enImgType;            // ͼƬ����
    CHAR szJudgeResultInfo[PU_IMG_QUALITY_INFO_LEN];  // �жϽ����Ϣ
    CHAR szResultImgPath[PU_FTP_UPLOAD_PATH_LEN];     // ���ر���ͼƬ�����·��
    CHAR szReserve[PU_RESERVE_LEN];                   // Ԥ��
} PU_IMG_QUALITY_JUDGE_S;

// ץ���ش�����
typedef struct PU_SNAPSHOT_RETRANS_PARA {
    BOOL bEnable;                     // ʹ��
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ��
} PU_SNAPSHOT_RETRANS_PARA_S;

// OSDI���򶥵���Ϣ
typedef struct PU_OSDI_POINT_INFO {
    FLOAT fHorDegree;
    FLOAT fVerDegree;
} PU_OSDI_POINT_INFO_S;

// OSDI������Ϣ
typedef struct PU_OSDI_AREA_CFG_PARA {
    ULONG ulIndex;                           // ��������
    BOOL bEnable;                            // ʹ��
    ULONG ulOSDINameLen;                     // OSDI���Ƴ���
    CHAR szOSDIName[PU_OSD_STRING_LEN];      // OSDI��������
    PU_OSDI_POINT_INFO_S stLowerLeftPoint;   // ��������
    PU_OSDI_POINT_INFO_S stUpperRightPoint;  // ��������
} PU_OSDI_AREA_CFG_PARA_S;

// OSDI����
typedef struct PU_OSDI_BUSINESS_PARA {
    ULONG ulChannelID;                                          // ͨ���ţ�֧����ͼ
    BOOL bOSDIEnable;                                           // OSDI�ܿ���
    ULONG ulOSDINum;                                            // ��ǰ��������
    PU_OSDI_AREA_CFG_PARA_S stOSDIAreaPara[OSDI_AREA_NUM_MAX];  // OSDI������Ϣ
} PU_OSDI_BUSINESS_PARA_S;

// OSDI������Ϣ
typedef struct PU_OSDI_AREA_CFG_PARA_V20 {
    ULONG ulIndex;                           // ��������
    BOOL bEnable;                            // ʹ��
    ULONG ulOSDINameLen;                     // OSDI���Ƴ���
    CHAR szOSDIName[PU_OSD_STRING_LEN];      // OSDI��������
    PU_OSDI_POINT_INFO_S stLowerLeftPoint;   // ��������
    PU_OSDI_POINT_INFO_S stUpperRightPoint;  // ��������
    PU_POINT_S stOSDITopLeftPos;             // OSDI���Ͻ�����
} PU_OSDI_AREA_CFG_PARA_V20_S;

// OSDI����
typedef struct PU_OSDI_BUSINESS_PARA_V20 {
    ULONG ulChannelID;                                              // ͨ���ţ�֧����ͼ
    BOOL bOSDIEnable;                                               // OSDI�ܿ���
    ULONG ulOSDINum;                                                // ��ǰ��������
    PU_OSDI_AREA_CFG_PARA_V20_S stOSDIAreaPara[OSDI_AREA_NUM_MAX];  // OSDI������Ϣ
} PU_OSDI_BUSINESS_PARA_V20_S;

// TCP ���ٲ���
typedef struct PU_TCP_ACCELERATE_PARA {
    BOOL bEnable;                     // ʹ��
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ��
} PU_TCP_ACCELERATE_PARA_S;

// �������β���
typedef struct PU_TRAFFIC_SHAPING_PARA {
    BOOL bEnable;                       // ��������ʹ��
    PU_TS_COEFFICIENT_E enCoefficient;  // ��������ϵ��
    CHAR szReserved[PU_RESERVE_LEN];    // Ԥ��
} PU_TRAFFIC_SHAPING_PARA_S;

// �˿����ò���
typedef struct PU_DEVICE_PORT_CONFIG {
    USHORT usHTTPPort;   // HTTP�˿�
    USHORT usHTTPSPort;  // HTTPS�˿�
    USHORT usRTSPPort;   // RTSP�˿�
} PU_DEVICE_PORT_CONFIG_S;

// �˿����ò�����չ
typedef struct PU_DEVICE_PORT_CONFIG_EX {
    USHORT usHTTPPort;                // HTTP�˿�
    USHORT usHTTPSPort;               // HTTPS�˿�
    USHORT usRTSPPort;                // RTSP�˿�
    ULONG ulMeshIndex;                // ��������
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ��
} PU_DEVICE_PORT_CONFIG_EX_S;

// �˿�ӳ��
typedef struct PU_DEVICE_NAT_PORT_CONFIG {
    ULONG ulChannelID;  //
    USHORT usRtspPort;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DEVICE_NAT_PORT_CONFIG_S;

// ���ڷ�ʽʩ������ʱ����
typedef struct PU_DST_WEEK_WAY {
    UINT uiMonth;                     // [0,11],�ֱ��ʾ1-12��
    UINT uiWeek;                      // [0,4],0-��һ��,1-�ڶ���,2-������,3-������,4-���һ��
    UINT uiDayofWeek;                 // [0,6],��ʾ����X,0��ʾ������,1��ʾ����һ,�Դ�����
    UINT uiHour;                      // [0,23],��ʾһ���еĵ�X��Сʱ
    UINT uiMinute;                    // [0,59],��ʾ��X��Сʱ�ĵ�X����
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ��
} PU_DST_WEEK_WAY_S;

// ���ڷ�ʽʩ������ʱ����
typedef struct PU_DST_DATE_WAY {
    UINT uiYear;                      // ��ʾXXXX��,0-ÿ��,[2014-2024]�ֱ��ʾ��Ӧ�����
    UINT uiMonth;                     // [0,11],�ֱ��ʾ1-12��
    UINT uiDay;                       // [0,30],�ֱ��ʾ1-31��
    UINT uiHour;                      // [0,23],��ʾһ���еĵ�X��Сʱ
    UINT uiMinute;                    // [0,59],��ʾ��X��Сʱ�ĵ�X����
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ��
} PU_DST_DATE_WAY_S;

// ����ʱ��ֹʱ��
typedef struct PU_DST_DATE {
    PU_DST_WEEK_WAY_S stDSTWeekWay;   // ���ڷ�ʽʵʩ������ʱʱ���
    PU_DST_DATE_WAY_S stDSTDateWay;   // ���ڷ�ʽʵʩ������ʱʱ���
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ��
} PU_DST_DATE_S;

// ����ʱ����
typedef struct PU_DAYLIGHT_SAVING_TIME {
    PU_DST_TYPE_E enDSTType;                                    // ����ʱʵʩ��ʽ
    BOOL bEnable;                                               // ����ʱʹ��
    PU_DST_OFFSET_E enOffset;                                   // ����ʱʱ��ƫ��
    PU_DST_DATE_S stDSTStartTime;                               // ����ʱ��ʼʱ��
    PU_DST_DATE_S stDSTEndTime;                                 // ����ʱ����ʱ��
    PU_DST_OFFSET_E enDateWayOffset;                            // ����ʱ���ڷ�ʽʱ��ƫ��
	ULONG ulChannelID;                  // ͨ����101,��ͼ�豸����ȡʱͨ���ţ�101��2001��2002������ʱͨ���ţ�2000��
    CHAR szReserved[PU_RESERVE_LEN - sizeof(PU_DST_OFFSET_E) - sizeof(ULONG)];  // Ԥ��
} PU_DAYLIGHT_SAVING_TIME_S;

// ץ�ķֱ���
typedef struct PU_SNAPSHOT_RESOLUTION_PARA {
    ULONG ulChannelID;                  // ͨ����
    PU_STREAM_TYPE_E enStreamType;      // ץ������
    PU_RESOLUTION_TYPE_E enResolution;  // ץ��ͼƬ�ֱ���
    CHAR szReserved[PU_RESERVE_LEN];    // szReserved[0]��ʾ�Ƿ���΢���� 1:΢���ڣ�0:��΢����
} PU_SNAPSHOT_RESOLUTION_PARA_S;

/********* SMTP *********/
typedef enum PU_SMTP_SECURITY_TYPE {
    PU_NO_SECURITY = 0,
    PU_USE_TLS,
    PU_USE_SSL,
    PU_DO_NOT_SET
} PU_SMTP_SECURITY_TYPE_E;
// �ʼ�����
typedef enum PU_SMTP_MAIL_TYPE {
    FOR_TEST,
    FOR_EVENT
} PU_SMTP_MAIL_TYPE;

typedef struct PU_SMTP_RECVEIVER_INFO {
    CHAR szReceiverName[PU_SMTP_NAME_LEN_MAX];  // �ռ����û���
    CHAR szReceiverMail[PU_SMTP_MAIL_LEN];      // �ռ�������
} PU_SMTP_RECVEIVER_INFO_S;

typedef struct SMTP_CONFIG_INFO {
    PU_SMTP_MAIL_TYPE enMailType;                                   // ��־�������·�����or�����ռ���,0:����,1,
    BOOL bSMTPEnable;                                               // ���ñ�־
    CHAR szSenderName[PU_SMTP_NAME_LEN_MAX];                        // �������û���
    CHAR szSenderMail[PU_SMTP_MAIL_LEN];                            // ����������
    CHAR szServerIP[PU_IP4_ADDR_LEN];                               // ������IP��ַ
    ULONG ulServerPort;                                             // �������˿�
    PU_SMTP_SECURITY_TYPE_E enSecurityType;                         // ��������
    BOOL bPicEnable;                                                // ����ͼƬ����
    ULONG ulPicNum;                                                 // ͼƬ��������
    ULONG ulSnapTimeInterval;                                       // ץ�ļ��
    BOOL bServerCrtEnable;                                          // ���÷�������֤
    CHAR szServerName[PU_CLIENT_USERNAME_LEN];                      // �������û���
    CHAR szPassword[PU_PASSWORD_LEN];                               // ������Pwd
    ULONG ulReceiverNum;                                            // �ռ�����Ŀ
    PU_SMTP_RECVEIVER_INFO_S szReceiverInfo[PU_SMTP_RECV_MAX_NUM];  // �ռ����б�
    CHAR szReserved[64];                                            // Ԥ���ֶ�
} PU_SMTP_CONFIG_INFO_S, *LPPU_SMTP_CONFIG_INFO_S;

// ������Ϣ
typedef struct PU_VEHICLE_INFO {
    PU_AREA_INFO_S stVehicleLoc;        // ����λ��
    PU_VEHICLE_COLOR_E enVehicleColor;  // ������ɫ
    PU_VEHICLE_TYPE_E enVehicleType;    // ��������
    PU_AREA_INFO_S stVehicleFaceLoc;    // ����λ��
    CHAR szReserved[64];                // Ԥ���ֶ�
} PU_VEHICLE_INFO_S;

// ������Ϣ
typedef struct PU_PLATE_INFO {
    BOOL bHavePlate;                // �Ƿ�ץ�ĵ�����
    INT iConfidence;                // �������Ŷ�
    INT iPlateCharNum;              // �����ַ���
    CHAR szPlateChar[36];           // �����ַ�����24���䵽36�ֽ�
    PU_AREA_INFO_S stPlateLoc;      // ����λ��
    PU_PLATE_TYPE_E enPlateType;    // ��������
    PU_PLATE_COLOR_E enPlateColor;  // ������ɫ
    PU_PLATE_DIR_E enMoveDir;       // �����ƶ�����
    CHAR szReserved[64 - 12];       // Ԥ���ֶΣ����ڳ����ַ�szPlateChar����12�ֽڣ��˴�����12�ֽ�
} PU_PLATE_INFO_S;

typedef struct LPR_CAPTURE_RES {
    CHAR szLocalTime[32];             // ץ��ʱ��
    INT iLaneID;                      // ������
    PU_VEHICLE_INFO_S stVehicleInfo;  // ������Ϣ
    PU_PLATE_INFO_S stPlateInfo;      // ������Ϣ
    CHAR *pPicBuffer;                 // ȫ��ͼƬBuffer
    UINT uiPicSize;                   // ȫ��ͼƬ��С
    CHAR *pLPBuffer;                  // ������дͼƬBuffer
    UINT uiLPPicSize;                 // ������дͼƬ��С
    CHAR szReserved[512];             // Ԥ���ֶ�szReserved[0]-szReserved[32]Ԥ����485�������к�
} LPR_CAPTURE_RES_S;

typedef struct AREA_CROP_PARA {
    ULONG ulChnID;                      // ͨ����
    BOOL bEnable;                       // ʹ��
    PU_STREAM_TYPE_E enStreamType;      // ��������
    PU_RESOLUTION_TYPE_E enResolution;  // �ֱ���
    PU_AREA_INFO_S stAreaInfo;          // ������Ϣ
    CHAR szReserved[64];
} PU_AREA_CROP_PARA_S;

typedef struct PU_AUTOTRANS_PIC_RES
{
    CHAR szSnapTime[32];                               //ץ��ʱ��
    CHAR *pPicBuffer;                                   //ͼƬBuffer
    ULONG uiPicSize;                                    //ͼƬ��С
    ULONG ulPicID;                                      //ͼƬID
    CHAR szReserved[32];                                //Ԥ���ֶ�
}PU_AUTOTRANS_PIC_RES_S;

// �ֶ�����ץ�Ĳ���
typedef struct MANUAL_LPR_CAPTURE_S {
    ULONG ulSnapNum;
    ULONG aulSnapInterval[MAX_BURST_SHOOTING_NUM - 1];
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MANUAL_LPR_CAPTURE_S;

// EPTZ����
typedef struct PU_EPTZ_CTRL {
    ULONG ulChnID;
    PU_STREAM_TYPE_E enStreamType;
    BOOL bMoveEnable;
    LONG lHorizonalSpeed;
    LONG lVerticalSpeed;
    LONG lZoomSpeed;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_EPTZ_CTRL_S;

// ��������
typedef struct PU_AEC_ENABLE {
    ULONG ulChnID;
    BOOL bEnable;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_AEC_ENABLE_S;

// ����������
typedef struct PU_IMRS_LINE {
    PU_IGT_POINT_S stStartPoint;
    PU_IGT_POINT_S stEndPoint;
} PU_IMRS_LINE_S;

// ���Ʋ���
typedef struct PU_VLP_PARA {
    CHAR szPlateLocalZH[MAX_PLATE_LOCAL_ZH_LEN];  // ���ȳ������ͣ����6��������6��ȡ6�����硰�������(��ǰ��֧��һ��)
    BOOL bInclineRectify;                         // ������б����
    INT iPlateSize;                               // ��С�������ã�0С���ƣ�1���ƣ�2΢С���ƣ�С����[40,200]������[200,400]
} PU_VLP_PARA_S;

// ����ȫ�ֲ�������
typedef struct PU_VLPR_PARA {
    ULONG ulChnID;                           // ͨ��ID
    BOOL bEnable;                            // �Ƿ�ʹ��
    INT iLaneNum;                            // ��������
    PU_IMRS_LINE_S stLane[MAX_AREA_VERTEX];  // ������ = ������+1
    PU_VEHICLE_DIR_E enVehicleDir;           // ��������Ĭ�ϳ�ͷ
    PU_VLPR_CATCH_MODE_E enCatchMode;        // ץ������ 0:������ 1:������
    PU_VLP_PARA_S stVLPParam;                // ���Ʋ���
    BOOL bVColorDetection;                   // ������ɫ�������
    BOOL bVTypeDetection;                    // �������ͼ������
    BOOL bSendPanoramaPic;                   // �Ƿ���ȫ��ͼ
    BOOL bSendPlatePic;                      // �Ƿ��ͳ���Сͼ
} PU_VLPR_PARA_S;

// ����ȫ�ֲ������ã���չ�����㷨�����ֶ�
typedef struct PU_VLPR_PARA_V2 {
    ULONG ulChnID;                           // ͨ��ID
    BOOL bEnable;                            // �Ƿ�ʹ��
    INT iLaneNum;                            // ��������
    PU_IMRS_LINE_S stLane[MAX_AREA_VERTEX];  // ������ = ������+1
    PU_VEHICLE_DIR_E enVehicleDir;           // ��������Ĭ�ϳ�ͷ
    PU_VLPR_CATCH_MODE_E enCatchMode;        // ץ������ 0:������ 1:������
    PU_VLP_PARA_S stVLPParam;                // ���Ʋ���
    BOOL bVColorDetection;                   // ������ɫ�������
    BOOL bVTypeDetection;                    // �������ͼ������
    BOOL bSendPanoramaPic;                   // �Ƿ���ȫ��ͼ
    BOOL bSendPlatePic;                      // �Ƿ��ͳ���Сͼ
    PU_VLPR_ALG_MODE_E enAlgMode;            // �����㷨����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_VLPR_PARA_V2_S;

// ���Ʋ���� ʱ�䲼���ṹ��
typedef struct PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO {
    ULONG ulStartTime;  // ��ʼʱ��
    ULONG ulEndTime;    // ����ʱ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO_S;

typedef enum PU_CAPLAMPCTRL_TYPE {
    TYPE_CTRLTYPE_IO = 0,     // IO����
    TYPE_CTRLTYPE_RS485 = 1,  // 485����
    TYPE_CTRLTYPE_PWM = 2,    // PWM����
    TYPE_CTRLTYPE_MAX
} PU_CAPLAMPCTRL_TYPE_E;

// ����Ʋ���
typedef struct PU_SUPPLEMENT_LIGHT_LAMP_INFO {
    ULONG ulOutputId;
    ULONG ulLampGroupLum;  // �������ȿ���1-100
    ULONG ulSensitivity;   // ��������ƻ�������������0-2
    PU_SUPPLEMENT_LIGHT_LAMP_IO_MODE_E enIOMode;
    PU_SUPPLEMENT_LIGHT_LAMP_CTRL_MODE_E enControlMode;
    PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO_S stTimePlan;
    CHAR szReserved[PU_RESERVE_LEN];  // szReserver[0]��ʾ���������1-100,Ĭ��50
} PU_SUPPLEMENT_LIGHT_LAMP_INFO_S;

// �������
typedef struct PU_SUPPLEMENT_LIGHT_INFO {
    ULONG ulChannelId;  // ͨ��ID
    ULONG ulActiveNum;
    PU_SUPPLEMENT_LIGHT_LAMP_INFO_S stLampInfo[MAX_SUPPLEMENT_LIGHT_LAMP_NUM];
    CHAR szReserved[PU_RESERVE_LEN];  // szReserved[0]��ʾ��������� PU_SUPPLEMENTLAMP_TYPE_E
    // szReserved[1]��ʾ������֡��Զ�ģʽ��������PU_LAMP_CTRL_MODE_E
    // szReserved[2]��ʾ����ƿ�������PU_CAPLAMPCTRL_TYPE_E
    // szReserved[3]��ʾ���ܺ���ȼ�0~100Ĭ��50
} PU_SUPPLEMENT_LIGHT_INFO_S;

// ֤�鵽�����ڲ���
typedef struct PU_CERT_EXPIRE_PERIOD_PARA {
    ULONG ulCheckPeriod;          // �������(��ǰ��֧������)
    ULONG ulAdvancedAlarmPeriod;  // ��ǰ�澯����
} PU_CERT_EXPIRE_PERIOD_PARA_S;

// I/P֡�������
typedef struct PU_KF_CODING_STRATEGY_PARA {
    ULONG ulChnID;
    BOOL bEnable;
    PU_STREAM_TYPE_E enStreamType;
    ULONG ulLevel;
} PU_KF_CODING_STRATEGY_PARA_S;

// OSD�߾�
typedef struct PU_OSD_MARGIN_INFO {
    ULONG ulChnID;
    ULONG ulDirect;  // OSD�߾෽��,0:�� 1:�� 2:�� 3:��
    BOOL bEnable;
    ULONG ulMarginLength;  // �߾���,�ַ�����(0~2)
} PU_OSD_MARGIN_INFO_S;

typedef struct FD_AREA {
    BOOL bEnable;
    UINT uiPointNum;
    PU_SQUARE_PARA_S stPoint[FD_AREA_POINT_NUM];
    CHAR szAreaName[FD_AREA_NAME_LEN];
} FD_AREA_S;

typedef struct PU_FD_AREA_LIST {
    ULONG ulAreaNum;
    FD_AREA_S szAreaList[FD_AREA_NUM];
} PU_FD_AREA_LIST_S;

typedef struct PU_FACE_DETC_PARA {
    ULONG ulAlarmTime;    // �澯���ʱ��
    BOOL bEnable;         // ʹ��
    ULONG ulSensitivity;  // ���������
    ULONG ulMinDectFace;  // ��С�����������Χ66-486���е�Զ��ģʽ��������С����70���������180���е�����ģʽ��������С����131���������273
    ULONG ulMaxDectFace;  // �������������Χ66-486���е�Զ��ģʽ��������С����70���������180���е�����ģʽ��������С����131���������273
    ULONG ulDectMode;     // ���ģʽ 0��Զ��ģʽ  1������ģʽ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_FACE_DETC_PARA_S;

typedef struct PU_FACE_TRACKING_PARAMETER {
    BOOL bFilter;   // ���ø��ٽ���ģʽ(Ҳ��Ϊ������ģʽ)
    BOOL bCrowded;  // ������Ա�ܼ�ģʽ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_FACE_TRACKING_PARAMETER_S;

typedef struct PU_FACE_PROCESS_PARAM {
    BOOL bSendFaceImg;                // ����������ͼ
    BOOL bSendPanorama;               // ����ȫ��ͼ
    ULONG ulImgQuality;               // ͼ��ץ������(1-10)
    CHAR szReserved[PU_RESERVE_LEN];  // szReserved[0]��ʾ������ͼ������1-5����Ĭ��Ϊ1
    // szReserved[1]��ʾͼ����ǿ
    // szReserved[2]��ʾ����ͼץ������(1-10)��Ĭ��Ϊ10
    // szReserved[3]��ʾȫ��ͼץ������(1-10)��Ĭ��Ϊ5
    // szReserved[4]��ʾ�������Կ���
    // szReserved[5]��ʾ�����������DetectErrFilter (0�ر�,1����)
    // szReserved[6]��ʾ����������������DtEFSen (1-10)��Ĭ��Ϊ5
} PU_FACE_PROCESS_PARAM_S;

// �������
typedef struct PU_SCENECHANGE_PARA {
    ULONG ulChnID;                         // ͨ���� ֧����ͼ
    BOOL bEnable;                          // ʹ��
    ULONG ulSensitivity;                   // ������
    ULONG ulCheckInterval;                 // �����
    ULONG ulAlarmInterval;                 // �澯�ϱ����
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SCENECHANGE_PARA_S;

// �齹���
typedef struct PU_OUTOFFOCUS_DETECT_PARA {
    ULONG ulChnID;                         // ͨ���� ֧����ͼ
    BOOL bEnable;                          // ʹ��
    ULONG ulSensitivity;                   // ������
    ULONG ulAlarmInterval;                 // �澯�ϱ����
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_OUTOFFOCUS_DETECT_PARA_S;

// �ۼ����
typedef struct PU_GATHER_CHECK_PARA {
    ULONG ulChnID;                         // ͨ���� ֧����ͼ
    BOOL bEnable;                          // ʹ��
    ULONG ulSensitivity;                   // ������
    ULONG ulAlarmInterval;                 // �����
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ����ʱ���б�
    PU_IGT_AERADTC_LIST_S szAreaList;      // ��������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_GATHER_CHECK_PARA_S;

// �����澯������ϡ������������涳�ᡱ��ѩ�������������������������ȡ���ƫɫ������̨ʧ�ء�
// �Ĳ����������齹������������ͬ����ͬһ���ṹ�� + by g00380004

typedef enum PU_ALARM_VIDEODIAGNOSIS_TYPE {
    // ALARM_BLUR = 0,    // ģ�������
    ALARM_SHAKE = 0,    // �������
    ALARM_FROZEN,       // ���涳�����
    ALARM_NOISE,        // ѩ���������
    ALARM_STRIPENOISE,  // �����������
    ALARM_BRIGHT,       // �������
    ALARM_COLORCAST,    // ƫɫ���
    // ALARM_VIDEOLOSE,      //�źŶ�ʧ
    // ALARM_SHELTE,           //��Ƶ�ڵ�
    // ALARM_PTZLOSECONTROL,      //��̨ʧ��

    ALARM_VIDEODIAGNOSIS_TYPE_MAX
} PU_ALARM_VIDEODIAGNOSIS_TYPE_E;

// ��Ƶ���
typedef struct PU_VIDEODIAGNOSIS_PARA {
    ULONG ulChnID;                               // ͨ���� ֧����ͼ
    PU_ALARM_VIDEODIAGNOSIS_TYPE_E enAlarmType;  // �澯����
    BOOL bEnable;                                // ʹ��
    ULONG ulSensitivity;                         // ������
    ULONG ulAlarmInterval;                       // �澯�ϱ����
    PU_ALARM_TIME_LIST_S stAlarmTimeList;        // ����ʱ���б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_VIDEODIAGNOSIS_PARA_S;

/**************** ��Ƶ���ʹ����Ϣ����***************************/
typedef struct PU_VIDEODIAGNOSIS_ENABLE_PARAM {
    ULONG ulChnID;                         // ͨ��ID
    BOOL bEnable;                          // �㷨ʹ��
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ��ʱû�ã���Ӧ�ӿ�

} PU_VIDEODIAGNOSIS_ENABLE_PARAM_S;

// �������
typedef struct PU_FACE_DETC_ALARM_PARA {
    ULONG ulChnID;                               // ͨ��ID
    ULONG ulBitMap;                              // 0000,���һλ��1����ʾ���õ�һ���ṹ���ڲ���
    PU_FACE_DETC_PARA_S stFDPara;                // ����������
    PU_FACE_TRACKING_PARAMETER_S stFDTrackPara;  // �������ٲ���
    PU_FACE_PROCESS_PARAM_S stFDProcPara;        // �����������
    PU_FD_AREA_LIST_S stAreaList;                // �����������
    PU_ALARM_TIME_LIST_S stFDGuardPlan;          // ������Ⲽ���ƻ�
} PU_FACE_DETC_ALARM_PARA_S;

typedef enum FACE_DT_CAP_MODE {
    FACE_CAP_DEFAULT_MODE = 0,  // Ĭ��ץ��ģʽ,Ŀ���뿪��ץ��
    FACE_CAP_QUICK_MODE,        // ����ץ��ģʽ
    FACE_CAP_TIMED_MODE,        // ��ʱץ��ģʽ(��-E��-Q����֧��)
    FACE_CAP_CROWD_MODE,        // ����ģʽ
} FACE_DT_CAP_MODE_E;

// �����������㷨����
typedef struct PU_FACE_DETC_DL_PARA {
    BOOL bEnable;                        // ʹ��
    ULONG ulAlarmTime;                   // �澯���ʱ��
    ULONG ulSensitivity;                 // ���������
    ULONG ulFaceSensitivity;             // �������������
    ULONG ulBodySensitivity;             // ������������
    ULONG ulFaceKpsSensitivity;          // ������������������(��֧��)
    ULONG ulBodyKpsSensitivity;          // ������������������(��֧��)
    ULONG ulMinPupilDist;                // ��С����
    ULONG ulMaxPupilDist;                // �������
    PU_FACE_DETECTION_DL_MODE_E enMode;  // ���ģʽ
    BOOL bFaceExposure;                  // �����ع�
    ULONG ulROIMeterLevel;               // �����ع�������
    FACE_DT_CAP_MODE_E enFaceCapMode;    // ץ��ģʽ
    UCHAR ulFaceCapSensitivity;          // ����ץ��������
    UCHAR uchFaceExposureTime;           // �����ع�ʱ��
    BOOL bSensitivityFlage;              // ���������ȿ��� ��Ӧ��������������(��֧��)
    UINT ulTimedCapture;                 // ������ⶨʱץ��
    USHORT ulSelectTime;                 // ��ѡģʽ��������ѡʱ����0-600�����á���ѡʱ�� 0����Ŀ����ֻ���ʱ������������
    BOOL filterNoFaceEnable;             // ����������Ŀ��ʹ��
    CHAR szReserved[PU_RESERVE_LEN - sizeof(FACE_DT_CAP_MODE_E) - sizeof(UCHAR) * 2 - sizeof(BOOL)*2 - sizeof(UINT) - sizeof(USHORT)];
} PU_FACE_DETC_DL_PARA_S;

// ���������⴦�����
typedef struct PU_FACE_PROCESS_DL_PARAM {
    BOOL bSendFaceImg;           // ����������ͼ
    BOOL bSendBodyImg;           // ���������ͼ
    BOOL bSendPanorama;          // ����ȫ��ͼ
    BOOL bFaceEnhancement;       // ͼ����ǿ
    ULONG ulFaceImgQuality;      // ����ͼץ������(1-10)
    ULONG ulBodyImgQuality;      // �����ͼ����(1-10)
    ULONG ulPanoramaImgQuality;  // ȫ��ͼץ������(1-10)
    ULONG ulSendFaceNum;         // ���͵�����Сͼ����
    ULONG ulSendBodyNum;         // ���͵�����Сͼ����
    BOOL bIsNeedFaceRectOverlay; // ȫ��ͼ����������
    CHAR szReserved[PU_RESERVE_LEN-sizeof(BOOL)];
} PU_FACE_PROCESS_DL_PARAM_S;

// ����������
typedef struct PU_FACE_DETC_DL_ALARM_PARA {
    ULONG ulChnID;                            // ͨ��ID
    ULONG ulBitMap;                           // 0000,���һλ��1����ʾ���õ�һ���ṹ���ڲ���
    PU_FACE_DETC_DL_PARA_S stFDPara;          // ����������
    PU_FACE_PROCESS_DL_PARAM_S stFDProcPara;  // �����������
    PU_FD_AREA_LIST_S stAreaList;             // �����������
    PU_FD_AREA_LIST_S stUnGuardAreaList;      // �������������
    PU_ALARM_TIME_LIST_S stFDGuardPlan;       // ������Ⲽ���ƻ�
} PU_FACE_DETC_DL_ALARM_PARA_S;

// ����ʶ��
typedef struct PU_FACE_RECOGNITION_PARA {
    BOOL bEnable;       // �㷨ʹ��
    ULONG ulChannelId;  // ͨ��ID
    ULONG ulAlarmTime;  // �澯�ϱ����
} PU_FACE_RECOGNITION_PARA_S;

// �����˲���
typedef struct PU_VHD_PARA {
    ULONG ulChannelId;                            // ͨ��ID
    BOOL bEnable;                                 // �Ƿ�ʹ��
    BOOL bSendSnapPicture;                        // �ϴ�Ŀ��Сͼ
    BOOL bSendPanorama;                           // �ϴ�ȫ��
    BOOL bLaneLineEnable;                         // �������Ƿ�ʹ��
    PU_VLPR_ALG_MODE_E enAlgMode;                 // ץ���㷨����
    INT iWidth;                                   // ����ͼ����
    INT iHeight;                                  // ����ͼ��߶�
    INT iLaneNum;                                 // ��������
    PU_IMRS_LINE_S stLane[MAX_AREA_VERTEX];       // ������ = ������+1
    CHAR szPlateLocalZH[MAX_PLATE_LOCAL_ZH_LEN];  // ���ȳ������ͣ����6��������6��ȡ6�����硰�����㡱

    BOOL bExposureEnable;  // �ع�ʹ��
    CHAR ulROIMeterLevel;  // �ع�ϵ��

    CHAR szReserved[PU_RESERVE_LEN - sizeof(BOOL) - sizeof(BOOL) - sizeof(BOOL) - sizeof(CHAR)];  //
} PU_VHD_PARA_S, *LPPU_VHD_PARA_S;

/* ����¼����Ϣ */
typedef struct PU_ASSOCIATE_RECORD_INFO {
    BOOL bRecordExist;  // �Ƿ���ڹ���¼��
    ULONG ulStartTime;  // ����¼�����ʼʱ��
    ULONG ulEndTime;    // ����¼��Ľ���ʱ��
} PU_ASSOCIATE_RECORD_INFO_S;

// ͼƬ��Ϣ
typedef struct PU_IMAGE_INFO_LIST {
    ULONG ulSnapTime;                                // ץ��ʱ��
    ULONG ulContentSize;                             // ͼƬ��С
    CHAR szContentID[PU_SNAPSHOT_PICTURE_NAME_LEN];  // ͼƬ��
    PU_ASSOCIATE_RECORD_INFO_S stRecordInfo;         // ����¼����Ϣ(�����Ӿ����豸��Ч,��IVS_PU_GetITSSnapshotPicList��ָ��Υ������)
    CHAR szReserved[PU_RESERVE_LEN - sizeof(PU_ASSOCIATE_RECORD_INFO_S)];
} PU_IMAGE_INFO_LIST_S;

// ��ѯץ������
typedef enum PU_GET_SNAPSHOT_LIST_TYPE
{
    GET_SNAPSHOT_LIST_BY_LOCALTIME = 0,     // ͨ������ʱ���ѯץ��
    GET_SNAPSHOT_LIST_BY_UTCTIME = 1,       // ͨ��UTC��ѯץ��
} PU_GET_SNAPSHOT_LIST_TYPE_E;

// ͼƬ��ѯ����
typedef struct PU_SNAPSHOT_INQUIRE {
    ULONG ulChnID;
    ULONG ulBeginIndex;                 // ��ǰ��ʼ��¼����(>=1)
    ULONG ulBeginTime;                  // ��ʼʱ��(time_t/localTime=GMT+ʱ��)
    ULONG ulEndTime;                    // ����ʱ��
    PU_SNAPSHOT_TYPE_E enSnapShotType;  // ץ������
    PU_GET_SNAPSHOT_LIST_TYPE_E enSnapTimeType;  //ץ��ʱ���ʽ ���ػ���UTC
    CHAR szReserved[PU_RESERVE_LEN - sizeof(PU_GET_SNAPSHOT_LIST_TYPE_E)];    // szReserved[0]��ҳ��ѯflag
} PU_SNAPSHOT_INQUIRE_S;

// ͼƬ��ѯ���
typedef struct PU_SNAPSHOT_LIST {
    ULONG ulTotalNum;                                               // �ܼ�¼��
    ULONG ulBeginIndex;                                             // ��ǰ��ʼ��¼��
    ULONG ulEndIndex;                                               // ��ǰ������¼��
    PU_IMAGE_INFO_LIST_S szImageInfoList[PU_SNAPSHOT_INQUIRE_NUM];  // ͼƬ��Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNAPSHOT_LIST_S;

// һ�źϳɷ�ʽ
typedef enum PU_ONE_PIC_SYNTHESIS_TYPE {
    PU_ONE_PIC_SYNTHESIS_TYPE1 = 0,  // ��д����
    PU_ONE_PIC_SYNTHESIS_TYPE2,      // ��д����
    PU_ONE_PIC_SYNTHESIS_TYPE3,      // ��д����
    PU_ONE_PIC_SYNTHESIS_TYPE4,      // ��д����
    PU_ONE_PIC_NO_SYNTHESIS,         // ���ϳ�
    PU_ONE_PIC_SYNTHESIS_TYPE_MAX
} PU_ONE_PIC_SYNTHESIS_TYPE_E;

// ���źϳɷ�ʽ
typedef enum PU_TWO_PIC_SYNTHESIS_TYPE {
    PU_TWO_PIC_SYNTHESIS_TYPE1 = 0,  // ���ºϳ�
    PU_TWO_PIC_SYNTHESIS_TYPE2,      // ���Һϳ�
    PU_TWO_PIC_SYNTHESIS_TYPE3,      // ����ͼƬ�������У���дͼ�����Ϸ�
    PU_TWO_PIC_SYNTHESIS_TYPE4,      // ����ͼƬ�������У���дͼ�����·�
    PU_TWO_PIC_SYNTHESIS_TYPE5,      // ����ͼƬ�������У���дͼ������
    PU_TWO_PIC_SYNTHESIS_TYPE6,      // ����ͼƬ�������У���дͼ�����ҷ�
    PU_TWO_PIC_SYNTHESIS_TYPE7,      // ����ͼƬƷ�������У���дͼ�����Ϸ�
    PU_TWO_PIC_SYNTHESIS_TYPE8,      // ����ͼƬƷ�������У���дͼ�����·�
    PU_TWO_PIC_SYNTHESIS_TYPE9,      // ����ͼƬƷ�������У���дͼ������
    PU_TWO_PIC_SYNTHESIS_TYPE10,     // ����ͼƬƷ�������У���дͼ�����ҷ�
    PU_TWO_PIC_NO_SYNTHESIS,         // ���ϳ�
    PU_TWO_PIC_SYNTHESIS_TYPE_MAX
} PU_TWO_PIC_SYNTHESIS_TYPE_E;

// ���źϳɷ�ʽ
typedef enum PU_THREE_PIC_SYNTHESIS_TYPE {
    PU_THREE_PIC_SYNTHESIS_TYPE1 = 0,  // ���ºϳ�
    PU_THREE_PIC_SYNTHESIS_TYPE2,      // ���Һϳ�
    PU_THREE_PIC_SYNTHESIS_TYPE3,      // ����+��д���ֺϳ��������У���дͼ�����Ϸ�
    PU_THREE_PIC_SYNTHESIS_TYPE4,      // ����+��д���ֺϳ��������У���дͼ�����Ϸ�
    PU_THREE_PIC_SYNTHESIS_TYPE5,      // ����+��д���ֺϳ��������У���дͼ�����·�
    PU_THREE_PIC_SYNTHESIS_TYPE6,      // ����+��д���ֺϳ��������У���дͼ�����·�
    PU_THREE_PIC_SYNTHESIS_TYPE7,      // ����Ʒ���Σ��ڶ�������
    PU_THREE_PIC_SYNTHESIS_TYPE8,      // ����Ʒ���Σ��ڶ�������
    PU_THREE_PIC_NO_SYNTHESIS,         // ���ϳ�
    PU_THREE_PIC_SYNTHESIS_TYPE_MAX
} PU_THREE_PIC_SYNTHESIS_TYPE_E;

// PU_PIC_SYNTHESIS_PARA_S �½ӿ�ʹ�õ�ö������
typedef enum PU_COMBINE_TYPE {
    PU_COMB_SIGNEL_NOROI, /* ץ��һ������д */
    PU_COMB_SIGNEL_HOR,   /* һ��ץ�ģ�ԭͼ����д��ˮƽ�ϳ� */
    PU_COMB_SIGNEL_VER,   /* һ��ץ�ģ�ԭͼ����д����ֱ�ϳ� */

    PU_COMB_DOUBLE_HOR_NOROI,       /* ץ����������д��ˮƽ�ϳ� */
    PU_COMB_DOUBLE_VER_NOROI,       /* ץ����������д����ֱ�ϳ� */
    PU_COMB_DOUBLE_HOR,             /* ����ץ�ģ�ԭͼ����д��ˮƽ�ϳ� */
    PU_COMB_DOUBLE_VER,             /* ����ץ�ģ�ԭͼ����д����ֱ�ϳ� */
    PU_COMB_DOUBLE_PYRAMIDAL_TOP,   /* ����ץ�ģ�ԭͼ����д��Ʒ���κϳ� */
    PU_COMB_DOUBLE_PYRAMIDAL_BUTT,  /* ����ץ�ģ�ԭͼ����д����Ʒ���κϳ� */
    PU_COMB_DOUBLE_PYRAMIDAL_LEFT,  /* ����ץ�ģ�ԭͼ����д��Ʒ����ͷ����ϳ� */
    PU_COMB_DOUBLE_PYRAMIDAL_RIGHT, /* ����ץ�ģ�ԭͼ����д��Ʒ����ͷ���Һϳ� */

    PU_COMB_TREBLE_HOR_NOROI,       /* ץ����������д��ˮƽ�ϳ� */
    PU_COMB_TREBLE_VER_NOROI,       /* ץ����������д����ֱ�ϳ� */
    PU_COMB_TREBLE_HOR,             /* ����ץ�ģ�ԭͼ����д��ˮƽ�ϳ� */
    PU_COMB_TREBLE_VER,             /* ����ץ�ģ�ԭͼ����д����ֱ�ϳ� */
    PU_COMB_TREBLE_PYRAMIDAL_TOP,   /* ����ץ�ģ�ԭͼ����д��Ʒ���κϳ� */
    PU_COMB_TREBLE_PYRAMIDAL_BUTT,  /* ����ץ�ģ�ԭͼ����д����Ʒ���κϳ� */
    PU_COMB_TREBLE_PYRAMIDAL_LEFT,  /* ����ץ�ģ�ԭͼ����д��Ʒ����ͷ����ϳ� */
    PU_COMB_TREBLE_PYRAMIDAL_RIGHT, /* ����ץ�ģ�ԭͼ����д��Ʒ����ͷ���Һϳ� */
    PU_COMB_TREBLE_SQUARE,          /* ����ץ�ģ�ԭͼ����д�������κϳ� */
    PU_COMB_TREBLE_SQUARE_NOROI,    /* ץ����������д�������κϳ� */

    PU_COMB_SIX_IN_ONE_HOR, /* ITS�羯6��1����������*3 ��*2 */
    PU_COMB_SIX_IN_ONE_VER, /* ITS�羯6��1����������*2 ��*3 */

    // ��������1�źϳɷ�ʽö��ֵ����50��ʼ

    // ����2�źϳɷ�ʽö��ֵ����100��ʼ
    PU_COMB_DOUBLE_PYRAMIDAL_TOP_ADAPT = 100, /* ����ץ�ģ�ԭͼ����д��Ʒ���κϳɵ�����С */
    PU_COMB_DOUBLE_PYRAMIDAL_BUTT_ADAPT,      /* ����ץ�ģ�ԭͼ����д����Ʒ���κϳɵ�����С */
    PU_COMB_DOUBLE_PYRAMIDAL_LEFT_ADAPT,      /* ����ץ�ģ�ԭͼ����д��Ʒ����ͷ����ϳɵ�����С */
    PU_COMB_DOUBLE_PYRAMIDAL_RIGHT_ADAPT,     /* ����ץ�ģ�ԭͼ����д��Ʒ����ͷ���Һϳ� ������С */

    // ����3�źϳɷ�ʽö��ֵ����150��ʼ
    PU_COMB_TREBLE_PYRAMIDAL_TOP_ADAPT = 150, /* ����ץ�ģ�����д��Ʒ���κϳ� ������С */
    PU_COMB_TREBLE_PYRAMIDAL_BUTT_ADAPT,      /* ����ץ�ģ�����д����Ʒ���κϳɵ�����С */
    PU_COMB_TREBLE_PYRAMIDAL_LEFT_ADAPT,      /* ����ץ�ģ�����д��Ʒ����ͷ����ϳɵ�����С */
    PU_COMB_TREBLE_PYRAMIDAL_RIGHT_ADAPT,     /* ����ץ�ģ�����д��Ʒ����ͷ���Һϳɵ�����С */

    PU_COMB_TREBLE_BUTT,
} PU_COMBINE_TYPE_E;

typedef enum PU_COMBINE_IMG_ROI {
    PU_COMBINE_IMG0_ORI, /* ��0��ץ��ԭͼ */
    PU_COMBINE_IMG0_ROI, /* ��0��ץ�Ŀ�ͼ, ��֧�� */
    PU_COMBINE_IMG1_ORI, /* ��1��ץ��ԭͼ */
    PU_COMBINE_IMG1_ROI, /* ��1��ץ�Ŀ�ͼ����֧�� */
    PU_COMBINE_IMG2_ORI, /* ��2��ץ��ԭͼ */
    PU_COMBINE_IMG2_ROI, /* ��2��ץ�Ŀ�ͼ����֧�� */
    PU_COMBINE_IMG3_ORI, /* ��3��ץ��ԭͼ */
    PU_COMBINE_IMGS_ROI, /* ��дͼ���������ŵ���дͼ�����ܶ� */

    PU_COMB_IMG_GW_ORI, /* 6��1����ץ��ԭͼ */
    PU_COMB_IMG_GW_ROI, /* 6��1����ץ����дͼ */

    PU_COMBINE_IMG_BUTT,
} PU_COMBINE_IMG_ROI_E;

typedef enum PU_COMBINE_SCALE {
    PU_COMB_SIZE_ORG,      // ԭͼ�ߴ�
    PU_COMB_SIZE_QUARTER,  // �ķ�֮һ
    PU_COMB_SIZE_RESERVE,
} PU_COMBINE_SCALE_E;

typedef enum PU_PIC_OSD_LOCATION {
    PU_PIC_IN_TOP = 0,
    PU_PIC_IN_BOTTOM,
    PU_PIC_OUT_TOP,
    PU_PIC_OUT_BOTTOM,
    PU_PIC_OSD_LOCATION_MAX
} PU_PIC_OSD_LOCATION_E;

// ����ͼƬ����
typedef enum PU_OVERLAY_PIC_TYPE {
    PU_ORG_PIC = 0,    // ԭͼ
    PU_SYNTHESIS_PIC,  // �ϳ�ͼ
    PU_OVERLAY_PIC_TYPE_MAX
} PU_OVERLAY_PIC_TYPE_E;

typedef enum {
    PU_OSD_FONT_SIZE_SMALL = 0,
    PU_OSD_FONT_SIZE_MEDIUM,
    PU_OSD_FONT_SIZE_LARGE,
    PU_OSD_FONT_SIZE_GAT_NORM,   // �����׼
    PU_OSD_FONT_SIZE_GAT_SMALL,  // ����С��
    PU_OSD_FONT_SIZE_MAX
} PU_FONT_SIZE_E;

typedef enum PU_FONT_SIZE_EXT {
    PU_OSD_FONT_SIZE_16,
    PU_OSD_FONT_SIZE_24,
    PU_OSD_FONT_SIZE_32,
    PU_OSD_FONT_SIZE_48,
    PU_OSD_FONT_SIZE_64,
    PU_OSD_FONT_SIZE_96,
    PU_OSD_FONT_SIZE_128,
    PU_OSD_FONT_SIZE_EXT_MAX,
} PU_FONT_SIZE_EXT_E;

// ͼƬOSD����
typedef enum PU_PIC_OSD_TYPE {
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
    PU_PRE_BRAND_TYPE_OSD,    // ����
    PU_SUB_BRAND_TYPE_OSD,    // �ӿ�
    PU_YEAR_BRAND_TYPE_OSD,   // ���
    PU_LOCATE_DESC_OSD,       // ·����Ϣλ������
    PU_MONITOR_INFO_OSD,      // �����Ϣ��
    PU_BRAND_INFO_OSD,        // Ʒ����Ϣ
    PU_VEHICLE_SPEED_OSD,     // ����
    PU_LANE_DESC_OSD,         // ��������
    PU_SNAP_SERIAL_NUM_OSD,   // ץ�����
    PU_ILLEGAL_NUM_OSD,       // Υ������
    PU_ILLEGAL_DESC_OSD,      // Υ����������
    PU_SPEED_LIMIT_OSD,       // ������Ϣ
    PU_ILLEGAL_SPEED_OSD,     // ����/���ٵ�Υ���ٶȱȼ���
    PU_LANE_DIR_DESC_OSD,     // ������������
    PU_VEHICLE_LEN_DESC_OSD,  // ����
    PU_REDLIGHT_START_OSD,    // ��ƿ�ʼʱ��
    PU_REDLIGHT_END_OSD,      // ��ƽ���ʱ��
    PU_REDLIGHT_PERIOD_OSD,   // ��Ƴ���ʱ��

    PU_SNAPTRIG_OSD,          // ץ�Ĵ���Դ
    PU_VEHICLE_MFR_TYPE_OSD,  // ��������������
    PU_RADAR_CHECK_DIR_OSD,   // �״���ٷ���
    PU_VEHICLE_DIR_OSD,       // ������ʻ����
    PU_VEHICLE_TYPE_EXT_OSD,  // ��չ����
    PU_SHELTER_PLATE_OSD,     // �ڵ�����
    PU_SCENCE_INFO,           // ������Ϣosd��Ŀǰֻ����Υͣ��    
    PU_PIC_OSD_TYPE_MAX
} PU_PIC_OSD_TYPE_E;

typedef enum PU_ITS_PIC_SYNTHESIS_TYPE {
    ITS_TYPE_EPOLICE_PIC_SYNTHESIS = 0,     // �羯
    ITS_TYPE_TGATEWAY_PIC_SYNTHESIS = 1,    // ����
    ITS_TYPE_PASSAGEWAY_PIC_SYNTHESIS = 2,  // �����
    ITS_TYPE_PEDRUNRED_PIC_SYNTHESIS = 3,   // ���˴����
    ITS_TYPE_PIC_SYNTHESIS_MAX,
} PU_ITS_PIC_SYNTHESIS_TYPE;

typedef enum PU_FACE_SYN_SCALE_TYPE {
    FACE_SYN_SCALE_LAYER1 = 0,  // С
    FACE_SYN_SCALE_LAYER2 = 1,  // ��
    FACE_SYN_SCALE_LAYER3 = 2,  // ��
    FACE_SYN_SCALE_MAX,
} PU_FACE_SYN_SCALE_TYPE_E;

// �°汾ͼƬ�ϳ����ݽṹ
typedef struct PU_PIC_SYNTHESIS_PARA_V3 {
    ULONG ulChnID;  // ͨ��ID
    BOOL bEnable;   // �Ƿ����úϳ�

    // �ɰ汾ʹ�ó�Ա����(Ϊ��ǰ����)    //�°���ͣʹ��
    PU_ONE_PIC_SYNTHESIS_TYPE_E enOnePicSynthesisType;
    PU_TWO_PIC_SYNTHESIS_TYPE_E enTwoPicSynthesisType;
    PU_THREE_PIC_SYNTHESIS_TYPE_E enThreePicSynthesisType;

    // �°汾ʹ�õĳ�Ա����
    PU_COMBINE_TYPE_E astCombineType[PU_SNAP_NUM_MAX2];
    PU_COMBINE_IMG_ROI_E astOnePicROI[2];
    PU_COMBINE_IMG_ROI_E astTwoPicROI[3];
    PU_COMBINE_IMG_ROI_E astThreePicROI[6];
    PU_COMBINE_SCALE_E enCombineScale;              // �ϳ�ͼ�ߴ�
    ULONG ulJpegQuality;                            // �ϳ�ͼ��������
    ULONG ulPicSynthesisEnableMask[2];              // ����[2~2^32)��ÿһλ��ӦPU_ITS_REGULA_TYPE_E��Υ���Ƿ�����ͼƬ�ϳɣ�Υ������0(�ֶ�ץ��)��֧�ֺϳ�
    BOOL bFaceSynthesisEnable;                      // �Ƿ����������ϳ�
    PU_FACE_SYN_SCALE_TYPE_E enFaceSynthesisScale;  // ������ͼ��С
    // �ֶ���չ���������ֶ�ʹ��ʱ���밴���ϵ��µ��ֶ�˳����bitλ(�ӵ�����)
    USHORT usSetBitmap;
    UINT ulPicSynthesisEnableMaskEx[30];  // ������չ�������±�ֵ������ PU_ITS_PIC_SYNTHESIS_TYPE ö�ٶ�Ӧ��ҵ��
    CHAR szReserved[PU_RESERVE_EX_LEN - sizeof(USHORT) - sizeof(UINT) * 30];
} PU_PIC_SYNTHESIS_PARA_V3_S;

// �ɰ汾ͼƬ�ϳ����ݽṹ
typedef struct PU_PIC_SYNTHESIS_PARA_V2 {
    ULONG ulChnID;  // ͨ��ID
    BOOL bEnable;   // �Ƿ����úϳ�

    // �ɰ汾ʹ�ó�Ա����(Ϊ��ǰ����)    //�°���ͣʹ��
    PU_ONE_PIC_SYNTHESIS_TYPE_E enOnePicSynthesisType;
    PU_TWO_PIC_SYNTHESIS_TYPE_E enTwoPicSynthesisType;
    PU_THREE_PIC_SYNTHESIS_TYPE_E enThreePicSynthesisType;

    // �°汾ʹ�õĳ�Ա����
    PU_COMBINE_TYPE_E astCombineType[PU_SNAP_NUM_MAX];
    PU_COMBINE_IMG_ROI_E astOnePicROI[2];
    PU_COMBINE_IMG_ROI_E astTwoPicROI[3];
    PU_COMBINE_IMG_ROI_E astThreePicROI[4];
    PU_COMBINE_SCALE_E enCombineScale;              // �ϳ�ͼ�ߴ�
    ULONG ulJpegQuality;                            // �ϳ�ͼ��������
    ULONG ulPicSynthesisEnableMask[2];              // ����[2~2^32)��ÿһλ��ӦPU_ITS_REGULA_TYPE_E��Υ���Ƿ�����ͼƬ�ϳ�,�ֶ�ץ��(0)��֧�ֺϳ�
    BOOL bFaceSynthesisEnable;                      // �Ƿ����������ϳ�
    PU_FACE_SYN_SCALE_TYPE_E enFaceSynthesisScale;  // ������ͼ��С
    CHAR szReserved[PU_RESERVE_LEN - (sizeof(ULONG) * 2) - sizeof(BOOL) - sizeof(PU_FACE_SYN_SCALE_TYPE_E)];
} PU_PIC_SYNTHESIS_PARA_V2_S;

// �ɰ汾ͼƬ�ϳ����ݽṹ
typedef struct PU_PIC_SYNTHESIS_PARA {
    ULONG ulChnID;  // ͨ��ID
    BOOL bEnable;   // �Ƿ����úϳ�

    // �ɰ汾ʹ�ó�Ա����(Ϊ��ǰ����)
    PU_ONE_PIC_SYNTHESIS_TYPE_E enOnePicSynthesisType;
    PU_TWO_PIC_SYNTHESIS_TYPE_E enTwoPicSynthesisType;
    PU_THREE_PIC_SYNTHESIS_TYPE_E enThreePicSynthesisType;

} PU_PIC_SYNTHESIS_PARA_S;

typedef struct PU_PIC_OSD_INFO_S {
    UINT uPicOSDNum;                                            // ����ӵ�OSD��Ŀ
    PU_PIC_OSD_TYPE_E aenPicOSDType[PU_VLPR_PIC_OSD_TYPE_MAX];  // ���ӵ�����
    PU_PIC_OSD_LOCATION_E enPicOSDLocation;                     // OSD����λ��
    PU_FONT_SIZE_E enFontSize;                                  // �����С
    ULONG ulFgColor;                                            // ǰ��(����)ɫ�ʸ�ʽ0xRRGGBB�����ʮ����
    UCHAR ucFgAlpha;                                            // ǰ�������֣�͸���� ��Χ0~128
    ULONG ulBgColor;                                            // ����ɫ�� ��ʽ0xRRGGBB �����ʮ����
    UCHAR ucBgAlpha;                                            // ����͸���� ��Χ0~128(��˼)
} PU_PIC_OSD_INFO_S;

typedef struct PU_PIC_OSD_INFO_EX_S {
    UINT uPicOSDNum;                                               // ����ӵ�OSD��Ŀ
    PU_PIC_OSD_TYPE_E aenPicOSDType[PU_VLPR_PIC_OSD_TYPE_MAX_EX];  // ���ӵ�����
    PU_PIC_OSD_LOCATION_E enPicOSDLocation;                        // OSD����λ��
    PU_FONT_SIZE_E enFontSize;                                     // �����С
    PU_FONT_SIZE_EXT_E enFontSizeExt;                              // ��չOSD�����С������ö��
    ULONG ulFgColor;                                               // ǰ��(����)ɫ�ʸ�ʽ0xRRGGBB�����ʮ����
    UCHAR ucFgAlpha;                                               // ǰ�������֣�͸���� ��Χ0~128
    ULONG ulBgColor;                                               // ����ɫ�� ��ʽ0xRRGGBB �����ʮ����
    UCHAR ucBgAlpha;                                               // ����͸���� ��Χ0~128(��˼)
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_PIC_OSD_INFO_EX_S;

typedef struct PU_TIME_OSD_PARA {
    BOOL bNeedAccurateToMs;  // �Ƿ�ȷ��ms
} PU_TIME_OSD_PARA_S;

typedef struct PU_CUSTOM_OSD_PARA {
    CHAR acOSDContent[PU_OSD_MAX_LENGTH];  // OSD����
} PU_CUSTOM_OSD_PARA_S;

typedef struct PU_CUSTOM_OSD_PARA_EX {
    CHAR acOSDContent[PU_OSD_MAX_LENGTH_EX];  // OSD����
} PU_CUSTOM_OSD_PARA_EX_S;

typedef struct PU_PIC_OSD_PARA {
    ULONG ulChnID;                           // ͨ��ID
    PU_OVERLAY_PIC_TYPE_E enOverlayPicType;  // ����OSD��ͼƬ����
    PU_PIC_OSD_INFO_S stPicOSDInfo;          // ͼƬ������Ϣ
    PU_TIME_OSD_PARA_S stTimeOSDPara;        // ʱ��OSD����
    PU_CUSTOM_OSD_PARA_S stRoadIdOSDPara;    // ·�ڱ�Ų���
    PU_CUSTOM_OSD_PARA_S stDevIdOSDPara;     // �豸��Ų���
    PU_CUSTOM_OSD_PARA_S stDirIdOSDPara;     // �����Ų���
    PU_CUSTOM_OSD_PARA_S stDirOSDPara;       // ����OSD����
    PU_CUSTOM_OSD_PARA_S stCustomOSDPara;    // �Զ���OSD����
} PU_PIC_OSD_PARA_S;

typedef struct PU_PIC_OSD_PARA_V2 {
    ULONG ulChnID;                           // ͨ��ID
    PU_OVERLAY_PIC_TYPE_E enOverlayPicType;  // ����OSD��ͼƬ����
    PU_PIC_OSD_INFO_S stPicOSDInfo;          // ͼƬ������Ϣ
    PU_TIME_OSD_PARA_S stTimeOSDPara;        // ʱ��OSD����
    PU_CUSTOM_OSD_PARA_S stRoadIdOSDPara;    // ·�ڱ�Ų���
    PU_CUSTOM_OSD_PARA_S stDevIdOSDPara;     // �豸��Ų���
    PU_CUSTOM_OSD_PARA_S stDirIdOSDPara;     // �����Ų���
    PU_CUSTOM_OSD_PARA_S stDirOSDPara;       // ����OSD����
    PU_CUSTOM_OSD_PARA_S stCustomOSDPara;    // �Զ���OSD����
    BOOL bDirOSDParaEn;                      // ��ʻ�������ʹ�ܣ�1:��ʾITS�������÷���OSD���� 0:���������÷���OSD����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PIC_OSD_PARA_V2_S;

typedef struct PU_PIC_OSD_PARA_V3 {
    ULONG ulChnID;                                 // ͨ��ID
    PU_OVERLAY_PIC_TYPE_E enOverlayPicType;        // ����OSD��ͼƬ����
    PU_PIC_OSD_INFO_EX_S stPicOSDInfo;             // ͼƬ������Ϣ
    PU_TIME_OSD_PARA_S stTimeOSDPara;              // ʱ��OSD����
    PU_CUSTOM_OSD_PARA_EX_S stRoadIdOSDPara;       // ·�ڱ�Ų���
    PU_CUSTOM_OSD_PARA_EX_S stDevIdOSDPara;        // �豸��Ų���
    PU_CUSTOM_OSD_PARA_EX_S stDirIdOSDPara;        // �����Ų���
    PU_CUSTOM_OSD_PARA_EX_S stDirOSDPara;          // ����OSD����
    PU_CUSTOM_OSD_PARA_EX_S stCustomOSDPara;       // �Զ���OSD����
    PU_CUSTOM_OSD_PARA_EX_S stLocateDescOSDPara;   // ·��λ����������
    PU_CUSTOM_OSD_PARA_EX_S stMonitorInfoOSDPara;  // ����λ����������
    PU_CUSTOM_OSD_PARA_EX_S stLaneDescOSDPara;     // ��������
    PU_CUSTOM_OSD_PARA_EX_S stLaneDirDescOSDPara;  // ������������
    BOOL bDirOSDParaEn;                            // ��ʻ�������ʹ�ܣ�1:��ʾITS�������÷���OSD���� 0:���������÷���OSD����
    PU_OSD_DATE_TYPE_E      enOsdDateType;         // OSD�������ͣ���ʱ��OSD stTimeOSDPara�ṩ
    BOOL                    bEnableLiveOSD;        // �Ƿ���ʵ��OSD
    CHAR szReserved[PU_RESERVE_EX_LEN-sizeof(PU_OSD_DATE_TYPE_E)-sizeof(BOOL)];
} PU_PIC_OSD_PARA_V3_S;

// ����OSD��������
typedef enum PU_FACE_OSD_TYPE {
    FACE_TIME_OSD = 0,      // ʱ�����
    FACE_DEV_ID_OSD,        // �豸���
    FACE_MONITOR_INFO_OSD,  // ������Ϣ
    FACE_OSD_TYPE_MAX
} PU_FACE_OSD_TYPE_E;

// ����OSD��Ϣ
typedef struct PU_FACE_OSD_INFO {
    ULONG uPicOSDNum;                                     // ����ӵ�OSD��Ŀ
    PU_FACE_OSD_TYPE_E aenPicOSDType[FACE_OSD_TYPE_MAX];  // ���ӵ�����
    PU_PIC_OSD_LOCATION_E enPicOSDLocation;               // OSD����λ��
    PU_FONT_SIZE_E enFontSize;                            // �����С
    PU_FONT_SIZE_EXT_E enFontSizeExt;                     // ��չOSD�����С������ö�٣��ݲ�֧��
    ULONG ulFgColor;                                      // ǰ��(����)ɫ�ʸ�ʽ0xRRGGBB�����ʮ����
    UCHAR ucFgAlpha;                                      // ǰ�������֣�͸���� ��Χ0~128���ݲ�֧��
    ULONG ulBgColor;                                      // ����ɫ�� ��ʽ0xRRGGBB �����ʮ����
    UCHAR ucBgAlpha;                                      // ����͸���� ��Χ0~128(��˼)���ݲ�֧��
} PU_FACE_OSD_INFO_S;

// ����OSD���Ӳ���
typedef struct PU_FACE_OSD_PARA {
    ULONG ulChannelId;  // ͨ��ID
    // BOOL bEnablePicOSD;                     // �Ƿ���ͼƬOSD����
    BOOL bEnableLiveOSD;                           // �Ƿ���ʵ��OSD����
    PU_OVERLAY_PIC_TYPE_E enOverlayPicType;        // ����OSD��ͼƬ����
    PU_FACE_OSD_INFO_S stPicOSDInfo;               // ͼƬ������Ϣ
    PU_TIME_OSD_PARA_S stTimeOSDPara;              // ʱ��OSD����
    PU_CUSTOM_OSD_PARA_EX_S stDevIdOSDPara;        // �豸��Ų���
    PU_CUSTOM_OSD_PARA_EX_S stMonitorInfoOSDPara;  // ����λ����������
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_FACE_OSD_PARA_S;

// ������OSD���Ӳ���
typedef struct PU_VHD_OSD_PARA{
    ULONG  ulChannelId;                     // ͨ��ID
    BOOL   bEnableLiveOSD;                   // �Ƿ���ʵ��OSD����
    CHAR   szReserved[PU_RESERVE_EX_LEN];
} PU_VHD_OSD_PARA_S;

// ��̨����λPT�ٶ�
typedef struct PU_PTZ_GEAR_SPEED {
    INT nGear;       // ��λ
    INT nPanSpeed;   // ˮƽ�ٶ�
    INT nTiltSpeed;  // ��ֱ�ٶ�
} PU_PTZ_GEAR_SPEED_S;

// ��̨����λPT�ٶ���չ
typedef struct PU_PTZ_GEAR_SPEED_EX {
    INT nGear;          // ��λ
    INT nPanSpeed;      // ˮƽ�ٶ���������
    INT nDotPanSpeed;   // ˮƽ�ٶ�С������
    INT nTiltSpeed;     // ��ֱ�ٶ���������
    INT nDotTiltSpeed;  // ��ֱ�ٶ�С������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PTZ_GEAR_SPEED_EX_S;

// ��̨�ٶ�
typedef struct PU_PTZ_GEARS_SPEED {
    PU_PTZ_GEAR_SPEED_S stPtzGearSpeed[PU_PTZ_GEAR_NUM_MAX];
} PU_PTZ_SPEED_S;

// ��̨�ٶ���չ
typedef struct PU_PTZ_SPEED_EX {
    PU_PTZ_GEAR_SPEED_EX_S stPtzGearSpeed[PU_PTZ_GEAR_NUM_MAX];
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PTZ_SPEED_EX_S;

// �澯¼����Ϣ
typedef struct PU_ALARM_REC_INFO {
    PU_ALARM_REPORT_S stAlarmReport;  // ¼���Ӧ�澯��Ϣ
    PU_TIME_S stBeginTime;            // ¼����ʼʱ��(UTCʱ��)
    PU_TIME_S stEndTime;              // ¼�����ʱ��(UTCʱ��)
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ALARM_REC_INFO_S;

// �澯¼���ѯ����
typedef struct PU_ALARM_REC_INQ_REQ {
    ULONG ulChnID;                // ͨ����
    PU_ALARM_TYPE_E enAlarmType;  // �澯���� 0��ʾ���и澯
    PU_TIME_S stBeginTime;        // ��ʼʱ��(UTCʱ��)
    PU_TIME_S stEndTime;          // ��ֹʱ��(UTCʱ��)
    ULONG ulBeginIndex;           // ��ʼ����(��1��ʼ)
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ALARM_REC_INQ_REQ_S;

// �澯¼���ѯ��Ӧ����
typedef struct PU_ALARM_REC_INQ_RSP {
    ULONG ulTotalNum;                                                 // �澯¼������
    ULONG ulBeginIndex;                                               // ��ʼ����
    ULONG ulEndIndex;                                                 // ��������
    PU_ALARM_REC_INFO_S astAlarmRecInfoList[PU_RECORD_INFO_NUM_MAX];  // �澯¼����Ϣ�б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ALARM_REC_INQ_RSP_S;

// ��̨�ٶ�����
typedef struct PU_PTZ_SPEED_LIMIT {
    ULONG ulPanSpeedLimit;   // ˮƽ�ٶ�����(��λ:��/��)
    ULONG ulTiltSpeedLimit;  // ��ֱ�ٶ�����(��λ:��/��)
} PU_PTZ_SPEED_LIMIT_S;

// ��̨�ٶ�����
typedef struct PU_PTZ_SPEED_ABILITY {
    ULONG ulPanSpeedMax;   // ˮƽ����ٶ�(��λ:��/��)
    ULONG ulTiltSpeedMax;  // ��ֱ����ٶ�(��λ:��/��)
} PU_PTZ_SPEED_ABILITY;

// OSDIλ��
typedef struct PU_OSDI_POSITION {
    ULONG ulChnID;                // ͨ����
    ULONG ulOSDIIndex;            // OSDI����
    PU_POINT_S stOSDITopLeftPos;  // OSDI���Ͻ�����
} PU_OSDI_POSITION_S;

// �Զ�ARP�㲥
typedef struct PU_AUTO_ARP_BROADCAST_PARA {
    BOOL bEnable;      // ����
    ULONG ulCycleDay;  // ����(��λ:1~120��)
    CHAR szReserved[PU_RESERVE_LEN];
} PU_AUTO_ARP_BROADCAST_PARA_S;

// SSHʹ��
typedef struct PU_SSH_ENABLE_PARA {
    BOOL bEnable;  // ����
} PU_SSH_ENABLE_PARA_S;

// SFTPʹ��
typedef struct PU_SFTP_ENABLE_PARA {
    BOOL bEnable;  // ����
} PU_SFTP_ENABLE_PARA_S;

/*** ONVIFý�屣��ʱ�� ***/
typedef struct ONVIF_RTSP_SESSION_TIMEOUT {
    ULONG ulChannelId;
    PU_STREAM_TYPE_E enStreamId;  // ��������������1��������2
    ULONG ulTimeOut;
} PU_ONVIF_RTSP_SESSION_TIMEOUT_PARA_S;

// �澯����ptz�˶������ȼ�
typedef struct PU_ALARM_LINK_PRIORITY_PARA {
    ULONG ulChannelId;                             // ͨ����
    PU_ALARM_LINK_PTZ_PRIORITY_E enAlarmPriority;  // ���ȼ�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ALARM_LINK_PRIORITY_PARA_S, *LPPU_ALARM_LINK_PRIORITY_PARA_S;

/****ͣ�������Ϣ�ṹ��****/
typedef struct PU_CARDETECT_PARAM {
    ULONG ulChannelId;                     // ͨ��ID  ֧����ͼ
    BOOL bEnable;                          // �㷨ʹ��
    ULONG ulSensitivity;                   // �㷨���������
    ULONG ulAlarmTime;                     // �澯�ϱ����
    ULONG ulParkTimeThr;                   // ͣ����ֵ
    PU_IGT_AERADTC_LIST_S stAreaList;      // ͣ�����������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ͣ����Ⲽ���ƻ�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_CARDETECT_PARAM_S, *LPPU_CARDETECT_PARAM_S;

/****��Ϊ�������ܸ���****/
typedef struct PU_VA_LINK_AT {
    ULONG ulChannelId;            // ͨ����
    BOOL bEnable;                 // �㷨ʹ��
    PU_ALARM_TYPE_E enAlarmType;  // ��Ҫ�����Զ����ٵĸ澯
    CHAR szReserved[PU_RESERVE_LEN];
} PU_VA_LINK_AT_S, *LPPU_VA_LINK_AT_S;

/****�Զ�������Ϣ�ṹ��****/
typedef struct PU_VW_ITGT_AUTOTRACKING_PARAM {
    ULONG ulChannelId;                     // ͨ��ID ֧����ͼ
    BOOL bEnable;                          // �㷨ʹ��
    ULONG ulSensitivity;                   // �㷨���������
    ULONG ulAlarmTime;                     // �澯�ϱ����
    ULONG ulMaxTraceTime;                  // ������ʱ��
    PU_ALARM_TIME_LIST_S stAlarmTimeList;  // ������������ƻ�
    PU_IGT_AERADTC_LIST_S szAreaList;      // ��������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_VW_ITGT_AUTOTRACKING_PARAM_S, *LPPU_VW_ITGT_AUTOTRACKING_PARAM_S;

/****�Զ������ֶ�����Ŀ��****/
typedef struct PU_VW_ITGT_AT_MANUAL_TARGET {
    ULONG ulX;
    ULONG ulY;
    ULONG ulWidth;
    ULONG ulHeight;
} PU_VW_ITGT_AT_MANUAL_TARGET_S, *LPPU_VW_ITGT_AT_MANUAL_TARGET_S;

// �߶νṹ��
typedef struct PU_HC_LINE {
    PU_POINT_S stPtS;  // �߶���ʼ�˵�
    PU_POINT_S stPtE;  // �߶ν�ֹ�˵�
} PU_HC_LINE_S;

// ���νṹ��
typedef struct PU_HC_RECT {
    USHORT startX;
    USHORT startY;
    USHORT width;
    USHORT height;
} PU_HC_RECT_S;

/******************���߼����㷨�����ṹ��********************************/
typedef struct PU_HUMANCOUNT_ALG_PARAM {
    BOOL enHCEnable;            // ���߼����㷨ʹ��
    BOOL enOSDEnable;           // OSD����ʹ��
    BOOL enClearAtZero;         // �������ʹ��
    PU_POINT_S stOSDLocation;   // OSD����λ��
    ULONG ulSensitivity;        // �㷨���������
    ULONG ulAlarmTime;          // �澯�ϱ����
    ULONG ulAlarmHumanNum;      // �澯������������ֵ�����澯��
    ULONG ulMinHeadSize;        // ��ͷ��С�ߴ�
    PU_HC_LINE_S stRefLine;     // �����ο��ߣ��Ƽ������ڻ�������, �߶νӽ�ˮƽ��ֱ
    PU_TRIPWIRE_DIR_E enInDir;  // ���뷽��(��˳ʱ��Խ��Ϊ��,����ʱ��Խ��Ϊ��)
    BOOL  timingReportEnable;   // ��ʱ�ϱ�ʹ��
    USHORT reportTime;          // ��ʱ�ϱ�ʱ����(1-600)
    CHAR szReserved[PU_RESERVE_LEN-sizeof(BOOL)-sizeof(USHORT)];
} PU_HUMANCOUNT_ALG_PARAM_S;

/******************���߼�����Ϣ�ṹ��************************************/
typedef struct PU_HUMANCOUNT_PARAM {
    ULONG ulChannelId;                      // ͨ��ID ֧����ͼ
    PU_HUMANCOUNT_ALG_PARAM_S stAlgParams;  // ���߼����㷨����
    PU_IGT_AERADTC_LIST_S stGuardAreaList;  // ���߼����������
    PU_ALARM_TIME_LIST_S stHCGuardPlan;     // ���߼��������ƻ�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_HUMANCOUNT_PARAM_S;

typedef struct PU_HUMANCOUT_RECORD {
    ULONG ulStartTime;  // ��ѯ��ʼʱ��
    ULONG ulEndTime;    // ��ѯ����ʱ��
    ULONG HumanNum;     // ��������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_HUMANCOUT_RECORD;

/******************���߼�������ṹ��************************************/
typedef struct PU_HUMANCOUNT_TABLE {
    ULONG ulChannelId;                                          // ͨ��ID
    PU_TABLE_TYPE_E enTableType;                                // ��������
    PU_TRIPWIRE_DIR_E enInDir;                                  // ���뷽��(��˳ʱ��Խ��Ϊ��,����ʱ��Խ��Ϊ��)
    ULONG ulRecordNum;                                          // ��ѯ��¼������
    PU_HUMANCOUT_RECORD astTable[PU_HUMANCOUNT_TABLE_LEN_MAX];  // ��ʱ��ι���������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_HUMANCOUNT_TABLE_S;

/*************��������3559��������*************/
typedef struct PU_ATTRI_DL_PARAMETER {
    ULONG ulChannelId;   // ͨ��ID
    BOOL enEnableAttri;  // �������Է���ʹ��(ԭʼ���Է���ʹ�ܣ���ʾ����������)
    BOOL enEnableBodyAttri;    // �������Է���ʹ��
    // BOOL     enEnableFaceAttri;    // �������Է���ʹ��
    // BOOL     enEnableBodyAttri;    // �������Է���ʹ��
    CHAR szReserved[PU_RESERVE_LEN - sizeof(BOOL)];
} PU_ATTRI_DL_PARAMETER_S;

/*************����Լ�*************/
typedef struct PU_PTZ_CHECK_PARA {
    BOOL enEnable;
    ULONG ulInterval;   // �Լ���
    ULONG ulChannelID;  // ͨ��ID
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_PTZ_CHECK_PARA_S;

/*************�ֶ�����***************/
typedef struct PU_MANAUL_DEFOG_ENABLE {
    BOOL bEnable;
    ULONG ulChannelId;  // ͨ��ID
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_MANAUL_DEFOG_ENABLE_S;

// ���Ʋ���� ʱ�䲼���ṹ��
typedef struct PU_SUPPLEMENTLAMP_TIME_INFO {
    ULONG ulStartTime;  // ��ʼʱ��:
    ULONG ulEndTime;    // ����ʱ��:
} PU_SUPPLEMENTLAMP_TIME_INFO_S;

// �ع�Ʋ���
typedef struct ITS_EXPOSURE_LAMP_ATTR {
    PU_EXT_LAMP_WORK_MODE_E enExtLampWorkMode;    // ���õƹ���ģʽ
    ULONG ulPulseWidth;                           // ����
    ULONG ulDelayTime;                            // �Ӻ�ʱ�䣬���ڵ���ͬ��
    PU_EXP_LAMP_TRIG_LEVEL_E enExpLampTrigLevel;  // �����ƴ�����ƽ
    ULONG ulLightThreshold;                       // ������ֵ���Զ�ģʽʱ��Ч
    PU_SUPPLEMENTLAMP_TIME_INFO_S stTimePlan;     // ʱ��ƻ�
    CHAR szReserved[PU_RESERVE_LEN - sizeof(PU_SUPPLEMENTLAMP_TIME_INFO_S)];
} PU_EXPOSURE_LAMP_ATTR_S;

// Ƶ���Ʋ���
typedef struct PU_STROBE_LAMP_ATTR {
    PU_EXT_LAMP_WORK_MODE_E enExtLampWorkMode;    // ���õƹ���ģʽ
    ULONG ulPulseWidth;                           // ����
    ULONG ulDelayTime;                            // �Ӻ�ʱ�䣬���ڵ���ͬ��
    PU_EXT_LAMP_FREQ_E enFrequency;               // Ƶ����Ƶ��
    ULONG ulLightThreshold;                       // ������ֵ���Զ�ģʽʱ��Ч
    PU_EXP_LAMP_TRIG_LEVEL_E enExpLampTrigLevel;  // Ƶ���ƴ�����ƽ
    PU_SUPPLEMENTLAMP_TIME_INFO_S stTimePlan;     // ʱ��ƻ�
    CHAR szReserved[PU_RESERVE_LEN - sizeof(PU_SUPPLEMENTLAMP_TIME_INFO_S) - sizeof(PU_EXP_LAMP_TRIG_LEVEL_E)];
} PU_STROBE_LAMP_ATTR_S;

/* 485Ƶ�������� */
typedef struct PU_485STROBE_LAMP_ATTR {
    PU_EXT_LAMP_WORK_MODE_E enExtLampWorkMode;   /* �ƹ���ģʽ */
    ULONG uPortId;                               /* 485���ں� */
    ULONG ulPulseWidth;                          /* ���� */
    ULONG ulDelayTime;                           /* �Ӻ�ʱ�䣬���ڵ���ͬ�� */
    PU_EXT_LAMP_FREQ_E enStrobeLampFreq;         /* Ƶ����Ƶ�� */
    PU_EXP_LAMP_TRIG_LEVEL_E enExpLampTrigLevel; /* Ƶ���ƴ�����ƽ */
    ULONG ulLightThreshold;                      /* ������ֵ���Զ�ģʽʱ��Ч */
    char szReserved[PU_RESERVE_LEN];
} PU_485STROBE_LAMP_ATTR_S;

/* 485���õ����� */
typedef struct PU_485LAMP_ATTR {
    ULONG uPortId;                          // ���ں�
    BOOL bEnable;                           // ����ʹ��
    PU_EXT_LAMP_WORK_MODE_E enLampWorkMode; /* �ƹ���ģʽ: ���գ��������Զ� */
    ULONG ulLightLum;                       /* ��������� ȡֵ0-100 */
    ULONG ulLightThreshold;                 /* ������ֵ���Զ�ģʽʱ��Ч ȡֵ0-100 */
    char szReserved[PU_RESERVE_LEN];
} PU_EXT_485LAMP_ATTR_S;

// ���õƲ���
typedef struct PU_EXT_LAMP_ATTR {
    PU_EXT_LAMP_TYPE_E enExtLampType;            // ���õ�����
    PU_EXPOSURE_LAMP_ATTR_S stExposureLampAttr;  // �ع������
    PU_STROBE_LAMP_ATTR_S stStrobeLampAttr;      // Ƶ��������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_EXT_LAMP_ATTR_S;

// ���õƲ�����չ,�¼�485Ƶ����
typedef struct PU_EXT_LAMP_ATTR_EX {
    PU_EXT_LAMP_TYPE_E enExtLampType;            // ���õ�����
    PU_EXPOSURE_LAMP_ATTR_S stExposureLampAttr;  // �ع������
    PU_STROBE_LAMP_ATTR_S stStrobeLampAttr;      // Ƶ��������
    PU_485STROBE_LAMP_ATTR st485StrobeLampAttr;  // 485Ƶ����
    CHAR szReserved[PU_RESERVE_EX_LEN];          // Ԥ���ֶ�����
} PU_EXT_LAMP_ATTR_EX_S;

typedef struct PU_SUPPLEMENT_LAMP_ATTR_EX {
    ULONG ulChannelId;                                               // ͨ��ID
    PU_STROBE_LAMP_ATTR_S stStrobeLampAttr[PU_MAX_INNER_LAMP_NUM];   // ����Ƶ��������
    PU_EXT_LAMP_ATTR_EX_S stExtLampAttr[PU_MAX_EXT_LAMP_NUM];        // ���õ�����
    PU_EXT_485LAMP_ATTR_S stExt485LampAttr[PU_MAX_EXT_485LAMP_NUM];  // 485���ò��������
    CHAR szReserved[PU_RESERVE_EX_LEN];                              // Ԥ���ֶ�����,szReserved[0]������ʹ��
} PU_SUPPLEMENT_LAMP_ATTR_EX_S;

// 485������
typedef enum PU_STR_485LAMP_TYPE {
    ITS_485_STROBE = 0,  // 485Ƶ����
    ITS_485_LAMP_MAX
} PU_STR_485LAMP_TYPE_S;

// 485��״̬
typedef struct PU_STR_485LAMP_STATUS {
    ULONG uPortId;                           // 485�˿ں�
    PU_STR_485LAMP_TYPE_S enIts485LampType;  // 485���������
    BOOL bLampStatus;                        // �����״̬
    char szReserved[PU_RESERVE_LEN];         // Ԥ���ֶ�����
} PU_STR_485LAMP_STATUS_S;

// 485��״̬��Ϣ
typedef struct PU_STR_485LAMP_STATUS_INFO {
    ULONG uIts485LampNum;                                                     // 485�Ƹ���
    PU_STR_485LAMP_STATUS_S astIts485LampStatusPara[PU_MAX_ITS_485LAMP_NUM];  // 485��״̬����
    char szReserved[PU_RESERVE_LEN];                                          // Ԥ���ֶ�����
} PU_STR_485LAMP_STATUS_INFO_S;

// ����Ʋ���
typedef struct PU_SUPPLEMENT_LAMP_ATTR {
    ULONG ulChannelId;                                              // ͨ��ID
    PU_STROBE_LAMP_ATTR_S stStrobeLampAttr[PU_MAX_INNER_LAMP_NUM];  // ����Ƶ��������
    PU_EXT_LAMP_ATTR_S stExtLampAttr[PU_MAX_EXT_LAMP_NUM];          // ���õ�����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SUPPLEMENT_LAMP_ATTR_S;

// AE�ع�ģʽ
typedef struct PU_CAM_AE_MODE {
    PU_AE_MODE_E enAEMode;  // AE�ع�ģʽ
} PU_CAM_AE_MODE_S;

/* AE��Ӧʱ�� */
typedef struct PU_CAM_AE_RESPONSE_TIME {
    LONG lAEResponseTime;
} PU_CAM_AE_RESPONSE_TIME_S;

/* GAMMA���� */
typedef struct PU_GAMMA {
    PU_COMMONMODE_SWITCH_E enGammaMode;
    ULONG ulStrength;
} PU_GAMMA_S;

/* ����Ƶ�� */
typedef struct PU_FLICKER_MODE {
    PU_VIDEO_FLICKER_MODE_E enFlicker;  // ����Ƶ��
} PU_FLICKER_MODE_S;

// ��ͷ���Ͳ���
typedef struct PU_CAM_LENS_TYPE {
    PU_LENS_TYPE_E enLensType;
} PU_CAM_LENS_TYPE_S;

// �������ֵ����
typedef struct PU_AUTOGAIN_MAXVALUE {
    LONG lMaxAutoGain;  // �Զ��������ֵ
} PU_AUTOGAIN_MAXVALUE_S;

// �������
typedef struct PU_DENOISE_PARA {
    PU_DENOISE_MODE_E enDenoiseMode;  // ģʽ����
    LONG lNRLevel;                    // ��Χ������1~5 ����1~3
    ULONG ulTfcLevel;                 // ʱ����
    ULONG ulSfcLevel;                 // ������
} PU_DENOISE_PARA_S;

// ��С�۽��������
typedef struct PU_MIN_FOCUS_VALUE {
    PU_MIN_FOCUS_E enMinFocus;  // ��С�۽�����
} PU_MIN_FOCUS_VALUE_S;

/* ץ����ϸ���������㷨���ж��ģʽISP���� */
typedef struct PU_SNAPSHOT_PARTICULAR_PARA {
    ULONG ulChannelID;                              // ͨ����
    ULONG ulBitMap;                                 // �޸�λ ����λ��AE�ع�ģʽ��ʼ��
    PU_CAM_AE_MODE_S stCamAEMode;                   // AE�ع�ģʽ1
    PU_CAM_AE_RESPONSE_TIME_S stCamAEResponseTime;  // AE��Ӧʱ��2(V2R2�豸�˲�����Ч)
    PU_EXPCOMP_PARA_S stCamExpcompPara;             // �عⲹ��3
    PU_WB_MANUAL_PARA_S stCamWBManualPara;          // ��ƽ��4
    PU_WD_PARA_S stCamWDPara;                       // ��̬5
    PU_BLACKWHITE_MODE_S stCamBlackWhiteMode;       // ��ҹģʽ6
    PU_SLOW_SHUTTER_MODE_S stSlowShutterMode;       // �����ſ���7
    PU_GAMMA_S stImageGammaCtrl;                    // GAMMA����8
    PU_FLICKER_MODE_S stCamFlickerMode;             // ����Ƶ��9
    PU_AEMETERING_MODE_S stCamAEMeterMode;          // AE���ģʽ10
    PU_SHUTTER_VALUE_S stCamshutterValue;           // ���ŷ�Χ����ֵ11
    PU_BACKLIGHT_MODE_S stCamBackLightMode;         // ���ⲹ��ģʽ12
    PU_IRC_PARA_S stCamIRCPara;                     // ��ҹģʽ���ؼ���ֵ(��ֵΪ��ҹ������)13
    PU_CAM_LENS_TYPE_S stCamLensType;               // ��ͷ����14
    PU_AUTOGAIN_MAXVALUE_S stAutoGainMaxValue;      // �Զ��������ֵ15
    PU_GAIN_CONTROL_S stCamGainControl;             // ��о�������16
    PU_DENOISE_PARA_S stCamDenoisePara;             // ����ģʽ17
    PU_STABILIZER_PARA_S stCamStabilizerPara;       // ��о����ģʽ18
    PU_IRIS_CONTROL_S stCamIrisControl;             // ���ƻ�о��Ȧ19
    PU_DEFOG_PARA_S stISPDefogPara;                 // ȥ��Ч��20
    PU_ROI_METER_MODE_S stCamRoiMeterMode;          // ΢���ڸ���Ȥ������21
    PU_IMG_DRC_S stImgDRCPara;                      // TIǹ����DRC����25
    PU_MIN_FOCUS_VALUE_S stMinFocusValue;           // ��С�۽�����ֵ26
    PU_ISP_CAM_HLC_S stHlc;                         // ǿ������27
    PU_IRIS_TYPE_E enIrisType;                      // Iris����28
    PU_CAM_SHUTTER_MODE_E enShutterValueLimit;      // ��������29
    PU_ISP_SCENE_TYPE_E enSceneType;                // ISP����ģʽ30
} PU_SNAPSHOT_PARTICULAR_PARA_S;

// ISP��ϸ��������
typedef enum PU_ISP_PARTICULAR_PARA_TYPE {
    PU_ISP_HUMAN,            // ���㷨�����豸��ģʽ�˿�����Ϊ����ISP����
    PU_ISP_HUMAN_DEFAULT,    // ���㷨�����豸��ģʽ�˿�����Ϊ����ISPĬ�ϲ�����ֻ֧�ֻ�ȡ
    PU_ISP_VEHICLE,          // ���㷨�����豸��ģʽ΢��ISP����
    PU_ISP_VEHICLE_DEFAULT,  // ���㷨�����豸��ģʽ΢��ISPĬ�ϲ�����ֻ֧�ֻ�ȡ
    PU_ISP_NORMAL,           // ��ͨISP ����
    PU_ISP_DEFAULT           // Ĭ��ISP����
} PU_ISP_PARTICULAR_PARA_TYPE_E;

// ISP��ϸ������չ
typedef struct PU_ISP_PARTICULAR_PARA_EX {
    PU_ISP_PARTICULAR_PARA_TYPE_E enISPParamType;  // ������ISP��������
    PU_SNAPSHOT_PARTICULAR_PARA_S stISPParam;      // ISP����
} PU_ISP_PARTICULAR_PARA_EX_S;

/*************BEGIN:΢����FTP/SFTP�ϴ�����***************/
/*************�ָ�������***************/
typedef enum PU_SEPARATOR_TYPE {
    PU_SEPARATOR_TYPE_DOT = 0,    // '.'
    PU_SEPARATOR_TYPE_PLUS,       // '+'
    PU_SEPARATOR_TYPE_MINUS,      // '-'
    PU_SEPARATOR_TYPE_UNDERLINE,  // '_'
    PU_SEPARATOR_TYPE_EQUAL,      // '='
    PU_SEPARATOR_TYPE_MAX
} PU_SEPARATOR_TYPE_E;

/*************ͼƬ��������***************/
typedef enum PU_PIC_NAMING_TYPE {
    // ������_������
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
    PU_PIC_NAMING_TYPE_YEAR,            // ���
    PU_PIC_NAMING_TYPE_OBJ_ID,          // ��׷��ID
    PU_PIC_NAMING_TYPE_VEHICLE_SIZE,    // ������С
    PU_PIC_NAMING_TYPE_REGULATION_NUM,  // Υ�±��
    PU_PIC_NAMING_TYPE_PIC_NUM,         // ͼƬ���
    PU_PIC_NAMING_TYPE_VEHICLE_DIRECTION,
    PU_PIC_NAMING_TYPE_VEHICLE_SPEED,     // �����ٶ�
    PU_PIC_NAMING_TYPE_VERSION,           // ƽ̨�汾�ţ���Զ���ƽ̨���Ӵ����
    PU_PIC_NAMING_TYPE_VEHICLE_RECT,      // ����λ��
    PU_PIC_NAMING_TYPE_PLATE_RECT,        // ����λ��
    PU_PIC_NAMING_TYPE_VEHICLE_BRAND_ID,  // ������Ʒ��ID
    PU_PIC_NAMING_TYPE_SUB_BRAND_ID,      // ������Ʒ��ID
    // ��������
    PU_PIC_NAMING_TYPE_GENDER = 50,   // �Ա�
    PU_PIC_NAMING_TYPE_AGE,           // ����
    PU_PIC_NAMING_TYPE_EXPRESSION,    // ����
    PU_PIC_NAMING_TYPE_GLASESS,       // �۾�
    PU_PIC_NAMING_TYPE_MOUTHMASK,     // ����
    PU_PIC_NAMING_TYPE_AGEGROUP,      // �����
    PU_PIC_NAMING_TYPE_SHAPE,         // ����
    PU_PIC_NAMING_TYPE_HAIR,          // ����
    PU_PIC_NAMING_TYPE_UMBRELLA,      // ��ɡ
    PU_PIC_NAMING_TYPE_BACKPACK,      // ����
    PU_PIC_NAMING_TYPE_FRONTPACK,     // ǰ�汳��
    PU_PIC_NAMING_TYPE_SATCHEL,       // ���
    PU_PIC_NAMING_TYPE_LUGGAGE,       // ����
    PU_PIC_NAMING_TYPE_CARRY,         // ������
    PU_PIC_NAMING_TYPE_MOVESPEED,     // �н��ٶ�
    PU_PIC_NAMING_TYPE_MOVEDIRECT,    // �н�����
    PU_PIC_NAMING_TYPE_UPPERTEXTURE,  // ��������
    PU_PIC_NAMING_TYPE_UPPERSTYLE,    // ���¿���
    PU_PIC_NAMING_TYPE_UPPERCOLOR,    // ������ɫ
    PU_PIC_NAMING_TYPE_LOWERSTYLE,    // ���¿���
    PU_PIC_NAMING_TYPE_LOWERCOLOR,    // ������ɫ
    PU_PIC_NAMING_TYPE_HUMANDEV_IP,   // ���豸ip
    PU_PIC_NAMING_TYPE_HUMANTIME,     // ��ʱ��
    PU_PIC_NAMING_TYPE_HUMANOBJ_ID,   // ��׷��ID
    PU_PIC_NAMING_TYPE_HUMANCUSTOM,   // ���Զ���
	PU_PIC_NAMING_TYPE_HAT,        //����ñ��
	PU_PIC_NAMING_TYPE_MUSTACHE,   //����
	PU_PIC_NAMING_TYPE_VIEW,       //��̬
    // ������_������
    PU_PIC_NAMING_TYPE_RIDERMAN_GENDER = 80,  // �������Ա�
    PU_PIC_NAMING_TYPE_RIDERMAN_AGE,          // ����������
    PU_PIC_NAMING_TYPE_RIDERMAN_UPPERSTYLE,   // ���������¿�ʽ
    PU_PIC_NAMING_TYPE_RIDERMAN_UPPERCOLOR,   // ������������ɫ
    PU_PIC_NAMING_TYPE_RIDERMAN_HELMET,       // ͷ��
    PU_PIC_NAMING_TYPE_RIDERMAN_HELMETCOLOR,  // ͷ����ɫ
    PU_PIC_NAMING_TYPE_RIDERMAN_OBJID,        // ������׷��ID
    PU_PIC_NAMING_TYPE_RIDERMAN_IP,           // �������豸ip
    PU_PIC_NAMING_TYPE_RIDERMAN_TIME,         // ������ʱ��
    PU_PIC_NAMING_TYPE_RIDERMAN_CUSTOM,       // �������Զ���

	PU_PIC_NAMING_TYPE_MOTOR_COLOR,           // ���й�����ɫ
	PU_PIC_NAMING_TYPE_MOTOR_SUNSAHDE,        // ���й�������ɡ
	PU_PIC_NAMING_TYPE_MOTOR_SUNSAHDE_COLOR,  // ���й�������ɡ��ɫ
	PU_PIC_NAMING_TYPE_MOTOR_CARRY,           // ���й���Я����
	PU_PIC_NAMING_TYPE_MOTOR_LICENSELPATE,    // ���й��߳���

    PU_PIC_NAMING_TYPE_MAX
} PU_PIC_NAMING_TYPE_E;

// FTP��ʽ��΢���ںͻ����˲�ͬ
typedef enum PU_FTP_TYPE {
    PU_VHD_FTP,         // ������
    PU_BAYONET_FTP,     // ΢����
    PU_ITS_FTP,         // ���ܽ�ͨ
    PU_COMMON_FTP,      // ����
    PU_IBALL_FTP,       // Υͣ��
    PU_EAST_SOFT_FTP,   // ����
    PU_HUMANFACE_FTP,   // ����
    PU_VEHFACEMIX_FTP,  // ����
    PU_FTP_TYPE_MAX
} PU_FTP_TYPE_E;

// ͼƬ����
typedef struct PU_PIC_NAMING_ELEM {
    PU_PIC_NAMING_TYPE_E enPicNamingType;             // ��������
    CHAR acCustomContent[PU_MAX_CUSTOM_CONTENT_LEN];  // �Զ�������
    CHAR szReserved[PU_RESERVE_LEN];                  // Ԥ���ֶ�
} PU_PIC_NAMING_ELEM_S;

typedef struct PU_PIC_NAMING_PARA {
    PU_SEPARATOR_TYPE_E enSeparatorType;  // �ָ�������
    PU_PIC_NAMING_ELEM_S astPicNamingElem[PU_MAX_PIC_NAMING_ELEM];
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_PIC_NAMING_PARA_S;

typedef struct PU_PIC_NAMING_PARA_EX {
    PU_SEPARATOR_TYPE_E enSeparatorType;  // �ָ�������
    PU_PIC_NAMING_ELEM_S astPicNamingElem[PU_MAX_PIC_NAMING_ELEM_EX];
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_PIC_NAMING_PARA_EX_S;

typedef enum PU_VLPR_FTP_DIR_NAMING_TYPE_E {
    VLPR_FTP_DIR_NAMING_TYPE_DEV_IP = 0,    // �豸IP
    VLPR_FTP_DIR_NAMING_TYPE_DEV_ID,        // �豸ID
    VLPR_FTP_DIR_NAMING_TYPE_TIME_YM,       // ʱ��(����)
    VLPR_FTP_DIR_NAMING_TYPE_TIME_YMD,      // ʱ��(������)
    VLPR_FTP_DIR_NAMING_TYPE_DIR,           // ����
    VLPR_FTP_DIR_NAMING_TYPE_LANE_ID,       // ������
    VLPR_FTP_DIR_NAMING_TYPE_CUSTOM,        // �Զ���
    VLPR_FTP_DIR_NAMING_TYPE_CHANNEL,       // ͨ����
    VLPR_FTP_DIR_NAMING_TYPE_REGULATION,    // Υ������
    VLPR_FTP_DIR_NAMING_TYPE_HOSTSLAVE_IP,  // ���ӻ�IP
    VLPR_FTP_DIR_NAMING_TYPE_DEV_IP_ONE,    // ����1IP
    VLPR_FTP_DIR_NAMING_TYPE_DEV_IP_TWO,    // ����2IP
    VLPR_FTP_DIR_NAMING_TYPE_INTELLIGENT,   // ���ܷ���
} PU_VLPR_FTP_DIR_NAMING_TYPE_E;

typedef struct PU_VLPR_FTP_DIR_NAMING_ELEM_S {
    PU_VLPR_FTP_DIR_NAMING_TYPE_E enFtpDirNamingType;
    CHAR acCustomContent[PU_MAX_CUSTOM_CONTENT_LEN];  // �Զ�������
    CHAR szReserved[PU_RESERVE_LEN];                  // Ԥ���ֶ�
} PU_VLPR_FTP_DIR_NAMING_ELEM_S;

typedef struct PU_VLPR_FTP_DIR_PARA_S {
    PU_FTP_UPLOAD_DIR_TYPE_E enDirType;
    PU_VLPR_FTP_DIR_NAMING_ELEM_S astDirNamingElem[PU_MAX_DIR_NAMING_ELEM];
    CHAR szReserved[PU_RESERVE_LEN];  // Ԥ���ֶ�
} PU_VLPR_FTP_DIR_PARA_S;

/*************΢����FTP�ϴ�����**************/
typedef struct PU_VLPR_FTP_UPLOAD_PARA {
    BOOL bSnapPicEnable;                       // ʹ��
    BOOL bSendPlatePic;                        // �Ƿ��ͳ���Сͼ
    PU_FTP_UPLOAD_PROTOCOL_TYPE_E enProtocol;  // �ϴ�Э��
    CHAR szServerIP[PU_IP4_ADDR_LEN];          // ������IP��ַ
    ULONG ulServerPort;                        // �������˿�
    CHAR szUserName[PU_CLIENT_USERNAME_LEN];   // �û���
    PU_VLPR_FTP_DIR_PARA_S stDirNameingPara;   // Ŀ¼��������
    PU_PIC_NAMING_PARA_S stPicNamingPara;      // ͼƬ��������
    PU_FTP_TYPE_E eFtpType;
    BOOL bSendFacePic;                               // �Ƿ�������Сͼ
    CHAR szReserved[PU_RESERVE_LEN - sizeof(BOOL)];  // Ԥ���ֶ�
    CHAR szUserPwd[PU_PASSWORD_LEN];                 // Pwd
} PU_VLPR_FTP_UPLOAD_PARA_S;

typedef struct PU_VLPR_FTP_UPLOAD_PARA_V2 {
    BOOL bSnapPicEnable;                       // ʹ��
    BOOL bSendPlatePic;                        // �Ƿ��ͳ���Сͼ
    PU_FTP_UPLOAD_PROTOCOL_TYPE_E enProtocol;  // �ϴ�Э��
    CHAR szServerIP[PU_IP4_ADDR_LEN];          // ������IP��ַ
    ULONG ulServerPort;                        // �������˿�
    CHAR szUserName[PU_CLIENT_USERNAME_LEN];   // �û���
    PU_VLPR_FTP_DIR_PARA_S stDirNameingPara;   // Ŀ¼��������
    PU_PIC_NAMING_PARA_EX_S stPicNamingPara;   // ͼƬ��������
    PU_FTP_TYPE_E eFtpType;
    BOOL bSendFacePic;                               // �Ƿ�������Сͼ
    CHAR szReserved[PU_RESERVE_LEN - sizeof(BOOL)];  // Ԥ���ֶ�
    CHAR szUserPwd[PU_PASSWORD_LEN];                 // Pwd
} PU_VLPR_FTP_UPLOAD_PARA_V2_S;

/*************END:΢����FTP/SFTP�ϴ�����***************/

// ���볬�ڸ澯
typedef struct PU_ALARM_REPORT_PWD_EXP_ALARM {
    CHAR szUsrName[PU_USER_NAME_LEN];
} PU_ALARM_REPORT_PWD_EXP_ALARM_S;

// 485Ƶ���Ƹ澯
typedef struct PU_ALARM_REPORT_ITS485STORBE {
    ULONG ulIt485LampId;
} PU_ALARM_REPORT_ITS485STORBE_S;

// ITS�ֶ�ץ�Ĳ���
typedef struct PU_ITS_MANUAL_SNAPSHOT_PARA {
    ULONG ulSnapNum;                                    // ץ������,���ֵMAX_BURST_SHOOTING_NUM  (Ŀǰֻ֧��1,����ֵ��Ч)
    ULONG aulSnapInterval[MAX_BURST_SHOOTING_NUM - 1];  // ץ�ļ��(ms) ��Χ[MIN_ITS_SNAPSHOT_INTERVAL, MAX_ITS_SNAPSHOT_INTERVAL]
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ITS_MANUAL_SNAPSHOT_PARA_S;

/* ͨ���µ�͸������Ӧ */
typedef struct PU_VW_FOG_ADAPT_PARA {
    ULONG ulChannelID;      // ͨ����
    BOOL enFogAdaptEnable;  // ͸������Ӧ�Ƿ�ʹ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_VW_FOG_ADAPT_PARA_S;

/* ͨ���µ���Ӱ(�ٶ�)����Ӧ */
typedef struct PU_VW_SPEED_ADAPT_PARA {
    ULONG ulChannelID;        // ͨ����
    BOOL enSpeedAdaptEnable;  // ��Ӱ(�ٶ�)����Ӧ�Ƿ�ʹ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_VW_SPEED_ADAPT_PARA_S;

/* ͨ���µı�������Ӧ */
typedef struct PU_VW_BACKLIGHT_ADAPT_PARA {
    ULONG ulChannelID;                     // ͨ����
    BOOL enBackLightAdaptEnable;           // ��������Ӧ�Ƿ�ʹ��
    BACKLIGHT_MODE_E enBackLightMode;      // �����������͡� ���豸�汾onetrack8.1.0�Ժ��ֶμ����µĲ�֧������;��Ϊ��̬�Զ���̬
    PU_AREA_INFO_S stBackLightAdaptStart;  // ��������Ӧ������Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_VW_BACKLIGHT_ADAPT_PARA_S;

typedef enum PU_ALARM_LEVEL {
    PU_ALARM_LEVEL_INFO,      // ��ʾ
    PU_ALARM_LEVEL_GENERAL,   // һ��
    PU_ALARM_LEVEL_CRITICAL,  // ����
    PU_ALARM_LEVEL_FATAL,     // ����
    PU_ALARM_LEVEL_MAX
} PU_ALARM_LEVEL_E;

// �澯�ϱ���Ϣ�ṹ
typedef struct PU_DEV_ALARM_INFO_REPORT {
    ULONG ulIdentifyID;             // �豸����ID
    ULONG ulAlarmModID;             // �澯ģ��ID
    BOOL IsIntact;                  // �Ƿ����, 1:��ã�0:�����
    PU_ALARM_LEVEL_E enAlarmLevel;  // �澯����
    PU_ALARM_TYPE_E enAlarmType;    // �澯����
    PU_TIME_S stTime;               // �澯����/����ʱ��UTC ʱ��
    PU_ALARM_ACTION_E enAction;     // �澯����/����
    ULONG ulAlarmId;                // �澯���к�
    CHAR szAlarmDesc[64];           // �澯����
    CHAR szAlarmCleanDesc[64];      // �澯�������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_DEV_ALARM_INFO_REPORT_S, *LPPU_DEV_ALARM_INFO_REPORT_S;

// �豸���ò���ö������
typedef enum PU_DEV_CONFIG_TYPE {
    PU_DEV_CONFIG_TYPE_IP_FILTER,           // IP ����
    PU_DEV_CONFIG_TYPE_DEV_PORT,            // �豸�˿�
    PU_DEV_CONFIG_TYPE_TCP_ACCELERATE,      // �������ܼ���
    PU_DEV_CONFIG_TYPE_DDNS,                // DDNS
    PU_DEV_CONFIG_TYPE_802DOT1x,            // 802.1x
    PU_DEV_CONFIG_TYPE_SSH,                 // SSH
    PU_DEV_CONFIG_TYPE_SFTP,                // SFTP
    PU_DEV_CONFIG_TYPE_SNMP_COMMUNITY,      // SNMPv1v2c�����б�
    PU_DEV_CONFIG_TYPE_SNMPV3_USER_MANAGE,  // SNMP v3�û�����
    PU_DEV_CONFIG_TYPE_SNMPV3_USER,         // SNMP v3�û��б�
    PU_DEV_CONFIG_TYPE_SNMPV3_TRAP,         // SNMP Trap���շ��б�
    PU_DEV_CONFIG_TYPE_MAX
} PU_DEV_CONFIG_TYPE_E;

// �豸������Ϣ
typedef union PU_DEV_CONFIG_PARA {
    PU_IPFILTER_RULES_INFOV2_S stIPFilterPara;     // IP ����
    PU_TCP_ACCELERATE_PARA_S stTcpAcceleratePara;  // �������ܼ���
    PU_DEVICE_PORT_CONFIG_S stDevPortConfig;       // �豸�˿�
    PU_DDNS_CONF_INFO_S stDDNSpara;                // DDNS
    PU_DOT1X_CONFIG_INFO_S stDot1xInfo;            // 802.1x
    PU_SSH_ENABLE_PARA_S stSshPara;                // SSH
    PU_SFTP_ENABLE_PARA_S stSftpPara;              // SFTP
    PU_SNMP_COMMUNITY_LIST_S_EX stCommunityList;   // SNMPv1v2c�����б�
    PU_SNMPV3_USER_MGMT_S stUserMgmtInfo;          // SNMP v3�û�������Ϣ
    PU_SNMPV3_USER_LIST_S stUserList;              // SNMP v3�û��б�
    PU_SNMP_TRAP_LIST_S stTrapList;                // SNMP Trap���շ��б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DEV_CONFIG_PARA_U, *LPPU_DEV_CONFIG_PARA_U;

// �豸������Ϣ����get
typedef struct PU_DEV_CONFIG_INFO {
    PU_IPFILTER_RULES_INFOV2_S stIPFilterPara;     // IP ����
    PU_TCP_ACCELERATE_PARA_S stTcpAcceleratePara;  // �������ܼ���
    PU_DEVICE_PORT_CONFIG_S stDevPortConfig;       // �豸�˿�
    PU_DDNS_CONF_INFO_S stDDNSpara;                // DDNS
    PU_DOT1X_CONFIG_INFO_S stDot1xInfo;            // 802.1x
    PU_SSH_ENABLE_PARA_S stSshPara;                // SSH
    PU_SFTP_ENABLE_PARA_S stSftpPara;              // SFTP
    PU_SNMP_COMMUNITY_LIST_S_EX stCommunityList;   // SNMPv1v2c�����б�
    PU_SNMPV3_USER_LIST_S stUserList;              // SNMP v3�û��б�
    PU_SNMPV3_USER_MGMT_S stUserMgmtInfo;          // SNMPv3�û�����
    PU_SNMP_TRAP_LIST_S stTrapList;                // SNMP Trap���շ��б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DEV_CONFIG_INFO_S, *LPPU_DEV_CONFIG_INFO_S;

// �豸��Ƶ�ֱ��ʲ���
typedef struct PU_RESOLUTION_BASIC_PARA {
    BOOL bdevIsHD;                      // �Ƿ����
    PU_RESOLUTION_TYPE_E enResolution;  // �豸��Ƶ�ֱ���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_RESOLUTION_BASIC_PARA_S, *PPU_RESOLUTION_BASIC_PARA_S;

// �豸��Ƶ�ֱ�����Ϣ
typedef struct PU_RESOLUTION_INFO {
    PU_RESOLUTION_BASIC_PARA_S astResolutionPara[PU_VIEDO_STREAM_TRIPLE];  // �豸��Ƶ�ֱ��ʻ�������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_RESOLUTION_INFO_S, *PPU_RESOLUTION_INFO_S;

typedef struct PU_DEVICE_INFO_EX {
    PU_DEVICEINFO_S stDeviceInfo;                    // �豸������Ϣ
    PU_DEVICE_ETHERNET_PARA_S stDeviceEthernetPara;  // �������
    PU_DEV_CONFIG_INFO_S stConfigPara;               // �豸������Ϣ
    PU_RESOLUTION_INFO_S stResolution;               // �豸��Ƶ�ֱ�����Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DEVICEINFO_EX_S, *LPPU_DEVICEINFO_EX_S;

typedef struct PU_DEV_REALSTATUS_INFO {
    LONG lCurretTemp;                         // �¶�
    PU_SYS_STATUS_INFO_S stSysStatusInfo;     // CPU���ڴ�
    PU_HARD_DISK_STATE_S stDiskState;         // SDCard ����״̬
    PU_CAM_GEOG_POSITION_S stCamGeogPostion;  // ����λ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DEV_REALSTATUS_INFO_S, *LPPU_DEV_REALSTATUS_INFO_S;

#define PU_OPERATE_3RD_APP_NAME_LEN 32  // ������APP ������󳤶�
#define PU_OPERATE_3RD_APP_PATH_LEN 64  // ������APP �ļ�·������
#define PU_OPERATE_3RD_APP_CMD_LEN  128 // ������APP ����������󳤶�
#define PU_MANAGE_3RD_APP_NUM_MAX   1   // ������APP ��Ϣ������
#define PU_MANAGE_3RD_APP_URL_MAX   64  // ������APP url ��󳤶�

typedef enum {
    PU_STATUS_3RD_APP_UNKNOWN = 0,
    PU_STATUS_3RD_APP_STOP,
    PU_STATUS_3RD_APP_RUN,
    PU_STATUS_3RD_APP_MAX
} PU_VW_3RD_APP_STATUS;

typedef enum {
    PU_ACTION_3RD_APP_START = 0,
    PU_ACTION_3RD_APP_STOP,
    PU_ACTION_3RD_APP_MAX
} PU_VW_3RD_APP_ACTION;

typedef struct PU_3RD_APP_BASIC_INFO {
    CHAR szAppName[PU_OPERATE_3RD_APP_NAME_LEN];
    CHAR szVersion[PU_OPERATE_3RD_APP_NAME_LEN];
    CHAR szURL[PU_MANAGE_3RD_APP_URL_MAX];
    PU_VW_3RD_APP_STATUS enAppStatus;
    PU_VW_3RD_APP_ACTION enAction;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_3RD_APP_BASIC_INFO_S, *LPPU_3RD_APP_BASIC_INFO_S;

typedef struct PU_MANAGE_3RD_APP_INFO {
    UINT uiValidCount;                                          // ��Ч���㷨App����
    PU_3RD_APP_BASIC_INFO_S ast3RdAppInfo[PU_3RD_APP_MAX_NUM];  // �����㷨App��Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MANAGE_3RD_APP_INFO_S, *LPPU_MANAGE_3RD_APP_INFO_S;

typedef enum {
    PU_OPERATE_3RD_APP_START = 0,
    PU_OPERATE_3RD_APP_STOP,
    PU_OPERATE_3RD_APP_UNINSTALL,
    PU_OPERATE_3RD_APP_MAX
} PU_VW_OPERATE_3RD_APP_TYPE;

typedef struct PU_VW_OPERATE_3RD_APP {
    PU_VW_OPERATE_3RD_APP_TYPE enOperateType;
    CHAR szAppName[PU_OPERATE_3RD_APP_NAME_LEN];
} PU_VW_OPERATE_3RD_APP_S, *LPPU_VW_OPERATE_3RD_APP_S;

typedef enum PU_LICENSE_TYPE {
    PU_LICENSE_TYPE_IGTALTHM,  // �����㷨license
    PU_LICENSE_TYPE_MAX
} PU_LICENSE_TYPE_E;

typedef struct PU_LICENSE_INFO {
    PU_LICENSE_TYPE_E emLicenseType;  // �㷨license����
    CHAR FileName[128];               // Licnese�ļ�·��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_LICENSE_INFO_S, *LPPU_LICENSE_INFO_S;

typedef enum PU_UPGRADE_ITGT_TYPE {
    PU_UPGRADE_ITGT_TYPE_APP = 0,                           // APP��
    PU_UPGRADE_ITGT_TYPE_FACE_BODY_DETECT = 1,              // �����������㷨��  Face and body detection algorithms
    PU_UPGRADE_ITGT_TYPE_FACE_RECOGTION = 2,                // ����ʶ���㷨��Facial recognition algorithms
    PU_UPGRADE_ITGT_TYPE_ILLEG_PARK_DETECT = 4,             // Υͣ����㷨��Illegal parking detection algorithms
    PU_UPGRADE_ITGT_TYPE_OBJ_CLASSIFICATION = 8,            // �����˳��Ƽ���㷨��Object classification algorithms
    PU_UPGRADE_ITGT_TYPE_NON_CHINA_VEHICLE_RECOGTION = 16,  // ���⳵�Ƽ���㷨��Non-China vehicle recognition algorithms
    PU_UPGRADE_ITGT_TYPE_SCENE_ADAPTATION = 32,             // ��������Ӧ�㷨��Scene adaptation algorithms
    PU_UPGRADE_ITGT_TYPE_QUEUE_LENTH_CROWD_COUNT,           // �ɶԳ�����Ⱥ�ܶȹ����㷨��The Queue of Party crowd  count algorithms
    PU_UPGRADE_ITGT_3RD_TYPE_APP = 64,                      // ����APP��
    PU_UPGRADE_LET_4G_MODEL,                                // 4G�����
    PU_UPGRADE_DCHIP_TYPE_APP,                              // DоƬ���������豸Ҫ����
    PU_UPGRADE_DCHIP_TYPE_ALG,                              // DоƬ�㷨��, ���������ȫ���Ұ汾һ�·���Ч
    PU_UPGRADE_EBI_TYPE_APP,                                // BEI�ܽ�ר�ÿ����㷨��
    PU_UPGRADE_ITGT_TYPE_OMNI,                              // ��ͼ�㷨�������ڻ����˺��������
    PU_UPGRADE_ITGT_TYPE_FACEDL_OMNI,                       // ��ͼ1+2  �����㷨��
    PU_UPGRADE_ITGT_TYPE_COMPLEX_BEH,                       // ������Ϊ�㷨��
    PU_UPGRADE_TYPE_MAX = 127                               // �������������ֵ
} PU_UPGRADE_ITGT_TYPE_E;

typedef struct PU_UPGRADE_ITGT_MODEL_PARA {
    PU_UPGRADE_ITGT_TYPE_E enUpgradeItgtType;   // ��������������
    CHAR szModelPath[PU_UPGRADE_FILE_LEN_MAX];  // ����������·��
	INT nMaxCpu;                                //���CPUռ�� (�ٷ�֮һ)   //enUpgradeItgtTypeΪPU_UPGRADE_ITGT_3RD_TYPE_APP ��Ч
	INT nMaxMem;                                //����ڴ�ռ��(��λMB)     //enUpgradeItgtTypeΪPU_UPGRADE_ITGT_3RD_TYPE_APP ��Ч
    CHAR szReserve[PU_RESERVE_LEN - 2 * sizeof(INT)];
} PU_UPGRADE_ITGT_MODEL_PARA_S, *LPPU_UPGRADE_ITGT_MODEL_PARA_S;

typedef struct PU_UPGRADE_ITGT_FILE_INFO {
    PU_UPGRADE_ITGT_MODEL_PARA_S astItgtModelPara[PU_UPGRADE_FILE_NUM_MAX];  // �����㷨������ģ����Ϣ
    ULONG ulChannelID;														//��ͼ�������� 2000
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_UPGRADE_ITGT_FILE_INFO_S, *LPPU_UPGRADE_ITGT_FILE_INFO_S;

#define PU_SAVE_FILE_PATH_MAX 128  // �����ļ������·��

// ֤��·������
typedef struct PU_CERT_FILE_PATH_PARA {
    CHAR szCACertFilePath[PU_CERT_FILE_PATH_MAX];  // CA�ļ�·��
    CHAR szKeyFilePath[PU_CERT_FILE_PATH_MAX];     // �ͻ��˶�˽Կ·��
    CHAR szCertFilePath[PU_CERT_FILE_PATH_MAX];    // �ͻ��˶�֤��·��
    CHAR szKeyPasswd[PU_PASSWORD_LEN];             // ˽Կ����
    CHAR cForbidRSA;                              // �Ƿ����RSA �����׼��� 0:�����ã� 1:����
    CHAR szReserve[PU_RESERVE_LEN - 1];
} PU_CERT_FILE_PATH_PARA_S;

//// 4G �������úͻ�ȡ
typedef enum DIAL_MODE {
    MANUL_DIAL = 0,
    AUTO_DIAL,
    DIAL_MAX
} DIAL_MODE_E;

typedef enum WIRELESS_NET_MODE {
    WL_NET_TYPE_AUTO = 0,
    WL_NET_TYPE_4G,
    WL_NET_TYPE_3G,
    WL_NET_TYPE_MAX
} WIRELESS_NET_MODE_E;

typedef enum DIAL_AUTH_TYPE {
    DIAL_AUTH_NONE = 0x00,    /* ����Ȩ */
    DIAL_AUTH_PAP = 0x01,     /* PAP��Ȩ */
    DIAL_AUTH_CHAP = 0x02,    /* CHAP��Ȩ */
    DIAL_AUTH_CHAP_PAP = 0x03 /* �ȳ���CHAP��Ȩ��ʧ�ܺ��ٳ���PAP��Ȩ */
} DIAL_AUTH_TYPE_E;

/******** DIAL   ********/
#define DIAL_APP_LEN_MAX        (32 + 1)
#define DIAL_USR_NAME_LEN_MAX   (32 + 1)
#define DIAL_PASSWD_LEN_MAX     (32 + 1)
#define DIAL_PLAN_AREA_MAX      (8)
#define DIAL_SMS_WHITE_LIST_MAX (8)
#define DIAL_RC_NUM_LEN_MAX     (4 + 1)
#define DIAL_PHONE_NUM_LEN      (16)
#define IPV4_ADDR_LEN           (16)  // ���ʮ����IP��ַ����
#define DAYS_PER_WEEK           (7)
#define DIAL_PLMN_NAME_MAX      (40)

typedef struct PU_DIALING_PARA {
    DIAL_AUTH_TYPE_E enAuthType; /* ��Ȩ���ͣ�Ϊ����Ȩʱ�û����������Ϊ�� */
    CHAR szApn[DIAL_APP_LEN_MAX];
    CHAR szUserName[DIAL_USR_NAME_LEN_MAX];
    CHAR szPassWd[DIAL_PASSWD_LEN_MAX];
} PU_DIALING_PARA_S;

/* ʹ�� */
typedef enum PU_ENABLE_TYPE {
    /* ö��ֵ������Ӵ�С���У��������ÿ��ö��ֵ��ֵ */
    PU_ENABLE_FALSE = 0,  // ��ʹ��
    PU_ENABLE_TRUE = 1,   // ʹ��
    PU_ENABLE_MAX
} PU_ENABLE_TYPE_E;

typedef struct PU_DIALING_CONFIG_INFO {
    PU_ENABLE_TYPE_E enEnable;
    DIAL_MODE_E enDialingMode;
    WIRELESS_NET_MODE_E enWirelessNetMode;
    PU_DIALING_PARA_S stDialingPara;
} PU_DIALING_CONFIG_INFO_S;

typedef enum DIAL_SIM_STATUS_TYPE {
    DIAL_SIM_STATUS_ABSENT = 0,          /* �޿�״̬ */
    DIAL_SIM_STATUS_READY,               /* ��״̬����״̬ */
    DIAL_SIM_STATUS_FAILURE,             /* ��״̬�쳣 */
    DIAL_SIM_STATUS_PIN_REQUIRED,        /* ������PIN����� */
    DIAL_SIM_STATUS_PIN2_REQUIRED,       /* ������PIN2����� */
    DIAL_SIM_STATUS_PUK_REQUIRED,        /* ������PUK����� */
    DIAL_SIM_STATUS_PUK2_REQUIRED,       /* ������PUK2����� */
    DIAL_SIM_STATUS_OPERATION_NOT_ALLOW, /* ���������� */
    DIAL_SIM_STATUS_INCORRECT_PASSWORD,  /* ������� */
    DIAL_SIM_STATUS_PIN_ERROR_MAX
} DIAL_SIM_STATUS_TYPE_E;

typedef enum DIAL_NET_ACT_TYPE {
    DIAL_REGISTER_ST_NO_SERVICE = 0x00,
    DIAL_REGISTER_ST_GSM = 0x01,
    DIAL_REGISTER_ST_WCDMA = 0x02,
    DIAL_REGISTER_ST_LTE = 0x03,
    DIAL_REGISTER_ST_MAX,
} DIAL_NET_ACT_TYPE_E;

typedef enum DIAL_CONNECT {
    DIAL_DISCONNECT = 0,
    DIAL_CONNECT,
    DIAL_CONNECT_MAX
} DIAL_CONNECT_E;

typedef struct PU_DIALING_STATUS_INFO {
    DIAL_SIM_STATUS_TYPE_E enSimStatus;  // SIM��״̬
    DIAL_NET_ACT_TYPE_E enActType;       // ������ʽ
    INT nSignalStrength;                 // �ź�ǿ��
    DIAL_CONNECT_E enIPv4ConnectStat;    /* IPV4����״̬ */
    CHAR szIPv4Address[IPV4_ADDR_LEN];   /* IPV4��ַ */
    CHAR szIPv4NetMask[IPV4_ADDR_LEN];   /* IPV4�������� */
    CHAR szIPv4NetGate[IPV4_ADDR_LEN];   /* IPV4�������� */
    CHAR szIPv4pDnsAddr[IPV4_ADDR_LEN];  /* IPV4��DNS */
    CHAR szIPv4sDnsAddr[IPV4_ADDR_LEN];  /* IPV4��DNS */
    CHAR szPLMNName[DIAL_PLMN_NAME_MAX]; /* ��Ӫ��״̬ */
} PU_DIALING_STATUS_INFO_S;

typedef struct PU_MANUL_DIALING {
    DIAL_CONNECT_E enDialConnect;
} PU_MANUL_DIALING_S;

typedef struct PU_TIME_RANGE_MIN {
    SHORT sStartTime;
    SHORT sEndTime;
} PU_TIME_RANGE_MIN_S;

typedef struct PU_DIALING_PLAN_DAY {
    PU_TIME_RANGE_MIN_S szTimeRange[DIAL_PLAN_AREA_MAX];
} PU_DIALING_PLAN_DAY_S;

typedef struct PU_AUTO_DIALING_PLAN {
    PU_DIALING_PLAN_DAY_S szDalingPlan[DAYS_PER_WEEK];
} PU_AUTO_DIALING_PLAN_S;

typedef struct PU_SMS_CMD_INFO {
    CHAR szRcNum[DIAL_RC_NUM_LEN_MAX];
    CHAR szPeerNum[DIAL_PHONE_NUM_LEN];
    PU_ENABLE_TYPE_E enRestartEnable;
    PU_ENABLE_TYPE_E enDialEnable;
} PU_SMS_CMD_INFO_S;

typedef struct PU_SMS_WHITE_LISTS {
    PU_SMS_CMD_INFO_S szSmsWhiteList[DIAL_SMS_WHITE_LIST_MAX];
} PU_SMS_WHITE_LISTS_S;

// ***************************************************************************************************************************************************************

// �����㷨license����״̬
typedef enum PU_ITGT_LIC_STATUS {
    PU_ITGT_LIC_STATUS_DEFAULT = 0,  // �������Ĭ��״̬
    PU_ITGT_LIC_STATUS_TRIAL,        // ������ڿ�����״̬
    PU_ITGT_LIC_STATUS_NORMAL,       // �����������״̬
    PU_ITGT_LIC_STATUS_EMERGENCY,    // ������ڽ���״̬
    PU_ITGT_LIC_STATUS_NO_USE,       // ��ʹ��
    PU_ITGT_LIC_STATUS_NA            // ���漰
} PU_ITGT_LIC_STATUS_E;

typedef struct PU_ITGT_ALTHM_BASIC_INFO {
    PU_ITGT_TYPE_E enAlthmType;                   // �㷨����
    PU_ITGT_LIC_STATUS_E enAlthmStatus;           // �㷨����״̬
    BOOL bEnableAlthm;                            // �㷨�Ƿ����� 0���ر� 1:����
    CHAR szAlthmVer[PU_ITGT_ALTHM_VERSION_LEN];   // �㷨�汾
    CHAR szAlthmOwner[PU_ITGT_ALTHM_VENDOR_LEN];  // �㷨����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ITGT_ALTHM_BASIC_INFO_S, *LPPU_ITGT_ALTHM_BASIC_INFO_S;

typedef struct PU_ITGT_ALTHM_INFO {
    UINT ulChannelID;                                                      // ͨ����
    UINT uiValidCount;                                                     // ��Ч���㷨����
    PU_ITGT_ALTHM_BASIC_INFO_S astItgtAlthmBasInfo[PU_ITGT_TYPE_MAX_NUM];  // ������㷨��Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ITGT_ALTHM_INFO_S, *LPPU_ITGT_ALTHM_INFO_S;

typedef struct PU_ITGT_ALTHM_INFO_EX {
    UINT ulChannelID;                                                         // ͨ����
    UINT uiValidCount;                                                        // ��Ч���㷨����
    PU_ITGT_ALTHM_BASIC_INFO_S astItgtAlthmBasInfo[PU_ITGT_TYPE_MAX_EX_NUM];  // ������㷨��Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ITGT_ALTHM_INFO_EX_S, *LPPU_ITGT_ALTHM_INFO_EX_S;

// �����㷨license������Ϣ
typedef struct PU_ITGT_LIC_CONTROL_INFO {
    PU_ITGT_TYPE_E enItgtType;
    PU_ITGT_LIC_STATUS_E enItgtStatus;
    CHAR szLicExpiryDate[PU_LIC_DATE_MAX_LEN];
} PU_ITGT_LIC_CONTROL_INFO_S, *LPPU_ITGT_LIC_CONTROL_INFO_S;

// license ������Ϣ�ṹ��
typedef struct PU_ITGT_LIC_SERVICE_INFO {
    UINT uiLicItgtNum;                                                   // license ����������㷨����
    CHAR szLicCreatDate[PU_LIC_DATE_MAX_LEN];                            // license�ļ���������
    CHAR szLicServiceAge[PU_LIC_SERVICE_AGE_MAX_LEN];                    // �������
    PU_ITGT_LIC_CONTROL_INFO_S astLicControlInfo[PU_ITGT_TYPE_MAX_NUM];  // �����㷨license������Ϣ
} PU_ITGT_LIC_SERVICE_INFO_S, *LPPU_ITGT_LIC_SERVICE_INFO_S;

// license ������Ϣ�ṹ������(16->64)
typedef struct PU_ITGT_LIC_SERVICE_INFO_EX {
    UINT uiLicItgtNum;                                                      // license ����������㷨����
    CHAR szLicCreatDate[PU_LIC_DATE_MAX_LEN];                               // license�ļ���������
    CHAR szLicServiceAge[PU_LIC_SERVICE_AGE_MAX_LEN];                       // �������
    PU_ITGT_LIC_CONTROL_INFO_S astLicControlInfo[PU_ITGT_TYPE_MAX_EX_NUM];  // �����㷨license������Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ITGT_LIC_SERVICE_INFO_EX_S, *LPPU_ITGT_LIC_SERVICE_INFO_EX_S;

// ʧЧ��
typedef struct PU_ITGT_LIC_REVOKE_INFO {
    CHAR szRevokeKey[PU_LIC_REVOKE_KEY_LEN];
} PU_ITGT_LIC_REVOKE_INFO_S, *LPPU_ITGT_LIC_REVOKE_INFO_S;

/*************begin:������������ݽṹ**************/
// �������������:��ɾ��
typedef enum PU_FACELIB_OPERATE {
    FACELIB_ADD = 1,
    FACELIB_MODIFY,
    FACELIB_DEL,
    FACELIB_DEL_ALL,        // ����,δʹ��

    FACELIB_MAX,
} PU_FACELIB_OPERATE_E;

// ��������������
typedef enum PU_FACE_LIB_TYPE {
    FACE_LIB_DEFAULT = 0,
    FACE_LIB_BLACK,  // ������
    FACE_LIB_WHITE,  // ������

    FACE_LIB_MAX,
} PU_FACE_LIB_TYPE_E;

// ��Ա�Ա�
typedef enum PU_GENDER {
    PU_GENDER_ALL = -1,  // ȫ��������ʱר�ã���ӡ��޸�ʱ��ֹ
    PU_MALE = 0,         // ��
    PU_FEMALE,           // Ů
    PU_GENDER_UNKNOW,    // δ֪
    PU_GENDER_MAX,
} PU_GENDER_E;

// ��Ա֤������
typedef enum PU_CARDTYPE {
    CARDTYPE_ALL = -1,  // ȫ��������ʱר�ã���ӡ��޸�ʱ��ֹ
    IDENTITY = 0,       // ���֤
    PASSPORT,           // ����
    OFFICER,            // ����֤
    DRIVING,            // ��ʻ֤
    OTHERS,             // ����
    MAX
} PU_CARDTYPE_E;

typedef enum PU_FEATURE_STATUS_TYPE {
    FEATURE_STATUS_UNKNOWN = 0,       // �½�������״̬
    FEATURE_STATUS_QUERY_ALL,         // ��ѯȫ��
    FEATURE_STATUS_REEXTRACT,         // ������ȡ������������״̬���㷨����ʱ����
    FEATURE_STATUS_UNEXTRACT,         // δ��ȡ
    FEATURE_STATUS_EXTRACTED,         // ����ȡ
    FEATURE_STATUS_FAILED,            // ��ȡʧ�ܣ����ڲ�ѯʧ�ܵ�����ͼƬ
    FEATURE_STATUS_ERRIMGSIZE,        // ͼƬ�ߴ粻�淶
    FEATURE_STATUS_DECODE_FAIL,       // ͼƬ����ʧ��
    FEATURE_STATUS_DETECTION_FAIL,    // �������ʧ��
    FEATURE_STATUS_EXTRACT_FAIL,      // ������ȡʧ��
    FEATURE_STATUS_ADD_FEATURE_FAIL,  // ����д��ʧ��
    FEATURE_STATUS_MAX,
} PU_FEATURE_STATUS_TYPE_E;

// ���������Ϣ
typedef struct PU_FACE_RECORD {
    ULONG ulFaceId;                              // ����ID
    CHAR szName[PU_MAX_RECORD_LEN_64];           // ����
    PU_GENDER_E enGender;                        // �Ա�
    CHAR szBirthday[PU_MAX_RECORD_LEN_32];       // ����
    CHAR szProvince[PU_MAX_RECORD_LEN_32];       // ʡ��
    CHAR szCity[PU_MAX_RECORD_LEN_48];           // ����
    PU_CARDTYPE_E enCardType;                    // ֤������
    CHAR szCardID[PU_MAX_RECORD_LEN_32];         // ֤����
    CHAR szExtensionField[PU_MAX_EX_FIELD_LEN];  // ������Ϣ�����ֶΣ�Ԥ��
    CHAR szPicPath[PU_SAVE_FILE_PATH_MAX];       // ͼƬ·�����ͻ��������ϴ�ͼƬ���豸�ϱ���ͼƬ��ȫ·������sdkserverд����
    // example��/tmp/mmcblk0/face_basic/test_sdk.jpg
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_RECORD_S;

// ������
typedef struct PU_FACE_LIB_S {
    ULONG ulFaceLibID;                         // ������ID
    PU_FACE_LIB_TYPE_E enLibType;              // ����������
    BOOL isControl;                            // �Ƿ񲼿�
    ULONG uiThreshold;                         // ������ֵ
    CHAR szLibName[PU_MAX_RECORD_LEN_64 + 1];  // ����������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_LIB_S;

// ��������Ϣ����
typedef struct PU_FACE_LIB_SET_S {
    ULONG ulChannelId;               // ͨ��ID
    PU_FACELIB_OPERATE_E enOptType;  // ��������
    PU_FACE_LIB_S stFacelib;         // ������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_LIB_SET_S;

// ��������Ϣ��ȡ
typedef struct PU_FACE_LIB_GET_S {
    ULONG ulChannelId;                             // ͨ��ID
    ULONG ulFaceLibNum;                            // ������
    CHAR szFindResultPath[PU_SAVE_FILE_PATH_MAX];  // ��ѯ���·�����ͻ������ڱ��ص�һ��Ŀ¼���豸����һ��json�ļ�·���������ṩ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_LIB_GET_S;

// �����������
typedef struct PU_FACE_LIB_IMPORT_S {
    ULONG ulChannelId;                            // ͨ��ID
    PU_FACE_PACKET_TYPE_E enPacketType;           // ������
    PU_FACE_LIB_S stFacelib;                      // ������
    CHAR szPath[PU_IMPORT_FILE_LEN_MAX];          // �ļ�·�����ļ���
    CHAR szFileName[PU_IMPORT_FILENAME_LEN_MAX];  // �ļ���
    CHAR szImportResult[PU_IMPORT_FILE_LEN_MAX];  // �������CSV����·������IVS_PU_ImportFaceLibEx�ӿ��и��ֶβ�ʹ��
    ULONG taskID;                                 // ������������ID
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_FACE_LIB_IMPORT_S;
   
typedef struct PU_PIC_FEATURE_EXTRACT {
    ULONG ulChannelId;                            // ͨ��ID
    PU_PIC_EXTRACT_TYPE_E enPicType;              // ͼƬ���ͣ���ǰֻ֧������
    CHAR* szJsonFmtContentBuff;                   // json��ʽ������
    UINT  unContentLengh;                         // ���ݳ���
    CHAR szReserve[PU_RESERVE_EX_LEN];
} PU_PIC_FEATURE_EXTRACT_S;

// �������⡢������ȡ����������״̬��ѯ
typedef struct PU_FACE_LIB_STATUS_S {
    ULONG ulChannelId;                             // ͨ��ID
    PU_FACE_LIB_S stFacelib;                       // ������
    ULONG taskID;                                  // �������⡢������ȡ��������������ID,����
    BOOL status;                                   // ���롢������ȡ״̬ 1:��� 0:δ���
    ULONG totalPicNum;                             // ���е��롢������ȡ����
    ULONG finishPicNum;                            // �ɹ����롢������ȡ����
    CHAR szResultCsvPath[PU_IMPORT_FILE_LEN_MAX];  // ���롢������ȡ���CSV����·��; �����������zip�ļ�·��
	PU_FACE_LIB_IO_TYPE_E enIOType;				   // ��ѯ��ҵ�����, ��������ʱ����
    CHAR szReserve[PU_RESERVE_LEN - sizeof(PU_FACE_LIB_IO_TYPE_E)];
} PU_FACE_LIB_STATUS_S;

// �����������
typedef struct PU_FACE_INFO_ADD_S {
    ULONG ulChannelId;          // ͨ��ID
    PU_FACE_LIB_S stFacelib;    // ������
    PU_FACE_RECORD_S stRecord;  // ��Ϣ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_INFO_ADD_S;

// ���������Ϣ
typedef struct FACE_FIND_CONDITION {
    CHAR szName[PU_MAX_RECORD_LEN_64];           // ����
    PU_GENDER_E enGender;                        // �Ա�, ȫ����¼��Ҫ����ѯ�����е�Gender��CardType����ֵΪ-1
    CHAR szProvince[PU_MAX_RECORD_LEN_32];       // ʡ��
    CHAR szCity[PU_MAX_RECORD_LEN_48];           // ����
    PU_CARDTYPE_E enCardType;                    // ֤������
    CHAR szCardID[PU_MAX_RECORD_LEN_32];         // ֤����
    CHAR szBirthdayStart[PU_MAX_RECORD_LEN_32];  // ���տ�ʼ
    CHAR szBirthdayEnd[PU_MAX_RECORD_LEN_32];    // ���ս���
    PU_FEATURE_STATUS_TYPE_E enFeatureStatus;    // ����ֵ״̬
    CHAR szReserve[PU_RESERVE_LEN - sizeof(PU_FEATURE_STATUS_TYPE_E)];
} PU_FACE_FIND_CONDITION_S;

// ������Ϣ��ѯ
typedef struct PU_FACE_INFO_FIND_S {
    ULONG ulChannelId;                                 // ͨ��ID
    PU_FACE_LIB_S stFacelib;                           // ������
    PU_FACE_FIND_CONDITION_S stCondition;              // ��ѯ����
    UINT uFindNum;                                     // ��ѯ�����Ŀ
    UINT uStartIndex;                                  // ��ʼ��ѯID
    CHAR szFindResultPath[PU_SAVE_FILE_PATH_MAX + 1];  // ��ѯ���·�� �豸����һ��json�ļ�·��/tmp/mmcblk0/facelist.json�����ԶԿͻ��˲��ɼ�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_INFO_FIND_S;

// ������Ϣ�޸�
typedef struct PU_FACE_INFO_MODIFY_S {
    ULONG ulChannelId;          // ͨ��ID
    PU_FACE_LIB_S stFacelib;    // ������
    PU_FACE_RECORD_S stRecord;  // �޸ĺ�Ľ��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_INFO_MODIFY_S;

// ������Ϣɾ��
typedef struct PU_FACE_INFO_DELETE_S {
    ULONG ulChannelId;                // ͨ��ID
    PU_FACE_LIB_S stFacelib;          // ������
    UINT uFaceNum;                    // ��Ҫɾ������Ŀ
    UINT uFaceID[PU_MAX_DELETE_NUM];  // ��Ҫɾ��������id
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_INFO_DELETE_S;

// ����ͼƬ��ȡ
typedef struct PU_FACE_PIC_GET_S {
    ULONG ulChannelId;                                 // ͨ��ID
    PU_FACE_LIB_S stFacelib;                           // ������
    ULONG uFaceID;                                     // ����ID
    CHAR szFindResultPath[PU_SAVE_FILE_PATH_MAX + 1];  // ��ѯ���·�� (SDK����)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_PIC_GET_S;

typedef struct PU_FACE_FEATURE_GET_S {
    ULONG ulChannelId;                              // ͨ��ID
    PU_FACE_LIB_S stFacelib;                        // ������
    CHAR szFeatureFilePath[PU_SAVE_FILE_PATH_MAX];  // �����������ļ�·��
    // CHAR              szExportCsvPath[PU_SAVE_FILE_PATH_MAX];     //�������CSV·��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_FEATURE_GET_S;

// ����������ȡ
typedef struct PU_FACE_FEATURE_EXTRACT_S {
    ULONG ulChannelId;        // ͨ��ID
    PU_FACE_LIB_S stFacelib;  // ������
    ULONG taskID;             // ����ID
    CHAR szReserve[PU_RESERVE_LEN];
} PU_FACE_FEATURE_EXTRACT_S;

// ����������һ���ȶ�
typedef struct PU_FACE_FEATURE_MATCH {
	FLOAT fMatchRate;                                 // ����ƥ���ʣ�����
	INT*  pnFaceFeatValues;                           // ץ��ͼ�����������޶���������256��
    UINT  unFaceFeatLen;                              // �������� 256
	INT*  pnLibFeatValues;                            // �׿�ͼ�����������޶���������256��
    UINT  unLibFeatLen;                               // �������� 256
	CHAR szReserve[PU_RESERVE_EX_LEN];
} PU_FACE_FEATURE_MATCH_S;

/*************end:������������ݽṹ**************/

/* ITS ������ͳ�Ʋ��� */
typedef struct PU_ITS_FLOW_RATE_PARA {
    ULONG ulChannelId;               // ͨ��IDF
    PU_ENABLE_TYPE_E bEnable;        // �Ƿ�����
    ULONG uInterval;                 // ͳ������(����)
    ULONG uCameraFromIntersection;   // ���λ�þ���·�ھ���(��)
    ULONG uDetectionAreaLength;      // ������򳤶�(��)
    ULONG uCongestionLaneThreshold;  // ӵ���ϱ���ֵ
    ULONG uCongestionThreshold;      // ӵ����ֵ(Km/h)
    ULONG uSlowThreshold;            // ������ֵ(Km/h)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_FLOW_RATE_PARA_S;

// ���νṹ��
typedef struct PU_RECTANGLE {
    ULONG ulStartX;
    ULONG ulStartY;
    ULONG ulWeight;  // ȡֵ��ΧΪ2~30
    ULONG ulHeight;  // ȡֵ��ΧΪ2~30
} PU_RECTANGLE_S;

/* �������Ϣ */
typedef struct PU_RL_LIGHTINFOS_PARA {
    PU_RECTANGLE_S stRLCropStart;         // ���������ʼ����
    PU_RL_LIGHT_TYPE_E enType;            // �������
    BOOL bEnable;                         // ����ʹ�ܿ���
    PU_RL_LIGHT_WAIT_TYPE_E enLightWait;  // �źŵƵ���
    CHAR szReserve[PU_RESERVE_LEN - sizeof(PU_RL_LIGHT_WAIT_TYPE_E)];
} PU_RL_LIGHTINFOS_PARA_S;

/* ����֡����Ϣ */
typedef struct PU_RL_FRAME_PARA {
    PU_RL_LIGHTINFOS_PARA_S stLightInfo[PU_RL_NUM_MAX];  // ���״̬(��Ҫ4��ͬʱ����)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_RL_FRAME_PARA_S;

/* ���������ǿ���� */
typedef struct PU_RL_CROP_ENHANCE_PARA {
    ULONG ulChannelID;               // ͨ����
    INT iLevel;                      // ǿ��(0-100)
    INT iEnable;                     // ʹ�ܿ���
    PU_RL_FRAME_PARA_S stFrameInfo;  // ֡��Ϣ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_RL_CROP_ENHANCE_PARA_S;

/* ����֡����Ϣ��չ */
typedef struct PU_RL_FRAME_PARA_V2 {
    PU_RL_LIGHTINFOS_PARA_S stLightInfo[PU_RL_NUM_MAX8];  // ���״̬
    CHAR szReserve[PU_RESERVE_LEN];
} PU_RL_FRAME_PARA_V2_S;

/* ���������ǿ������չ */
typedef struct PU_RL_CROP_ENHANCE_PARA_V2 {
    ULONG ulChannelID;                  // ͨ����
    INT iLevel;                         // ǿ��(0-100)
    INT iEnable;                        // ʹ�ܿ���
    PU_RL_FRAME_PARA_V2_S stFrameInfo;  // ֡��Ϣ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_RL_CROP_ENHANCE_PARA_V2_S;

// ��������
typedef struct PU_ITS_SPEED_MEASURE_PARAM {
    ULONG ulChannelId;          // ͨ��ID
    INT iCameraHeightH;         // ����������������H
    INT iImageBottom2CameraL1;  // ��Ұͼ�����ص���������ڵ������L1
    INT iImageCenter2CameraL2;  // ��Ұͼ���м䵽��������ڵ������L2
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_SPEED_MEASURE_PARAM_S;

typedef enum tagEN_ITS_TYPE {
    ITS_TYPE_EPOLICE = 0,     // �羯
    ITS_TYPE_TGATEWAY = 1,    // ����				
    ITS_TYPE_IBALL = 2,       // Υͣ��(Υ����)	�ݲ�֧��
    ITS_TYPE_PASSAGEWAY = 3,  // �����
    ITS_TYPE_VLPR = 4,        // ΢��				�ݲ�֧��
    ITS_TYPE_PEDRUNRED = 5,   // ���˴����
    ITS_TYPE_MAX,
} EN_ITS_TYPE;

/* ITSҵ�����ͽṹ�� */
typedef struct PU_ITS_BUSINESS_TYPE_PARA {
    ULONG ulChannelID;              // ͨ��ID
    EN_ITS_TYPE enITSBusinessType;  // ITSҵ������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ITS_BUSINESS_TYPE_PARA_S;

// ������
typedef enum PU_ITS_ROAD_DIR_TYPE {
    ITS_ROAD_UNKNOW,          // δ֪
    ITS_ROAD_EAST_TO_WEST,    // ������
    ITS_ROAD_WEST_TO_EAST,    // ����
    ITS_ROAD_SOUTH_TO_NORTH,  // ����
    ITS_ROAD_NORTH_TO_SOUTH,  // ������
    ITS_ROAD_ES_TO_WN,        // ����������
    ITS_ROAD_WN_TO_ES,        // ��������
    ITS_ROAD_EN_TO_WS,        // ����������
    ITS_ROAD_WS_TO_EN         // �����򶫱�
} PU_ITS_ROAD_DIR_TYPE_E;

// ��������ʻ����
typedef enum PU_ITS_ROAD_DRV_DIR {
    ITS_ROAD_DRV_DIR_UNKNOW,       // δ֪
    ITS_ROAD_DRV_DIR_LEFT,         // ��ת
    ITS_ROAD_DRV_DIR_STRAIGHT,     // ֱ��
    ITS_ROAD_DRV_DIR_LFT_STR,      // ��ת+ֱ��
    ITS_ROAD_DRV_DIR_RIGHT,        // ��ת
    ITS_ROAD_DRV_DIR_RHT_LFT,      // ��ת+��ת
    ITS_ROAD_DRV_DIR_RHT_STR,      // ��ת+ֱ��
    ITS_ROAD_DRV_DIR_RHT_STR_LFT,  // ��ת+��ת+ֱ��
    ITS_ROAD_DRV_DIR_LFT_WAIT      // ��ת����
} PU_ITS_ROAD_DRV_DIR_E;

// ��������Ƶ�е��˶�����
typedef enum PU_ITS_CAR_DRV_DIR {
    ITS_CAR_UNKNOW,         // δ֪
    ITS_CAR_BOTTOM_TO_TOP,  // ��������
    ITS_CAR_TOP_TO_BOTTOM,  // ��������
} PU_ITS_CAR_DRV_DIR_E;

// ������;
typedef enum PU_ITS_ROAD_PURPOSE {
    ITS_UNKNOW_ROAD,         // δ֪����
    ITS_COMMON_ROAD,         // ��ͨ����
    ITS_BUS_ROAD,            // ��������
    ITS_FAST_ROAD,           // �쳵��
    ITS_SLOW_ROAD,           // ������
    ITS_MOTOR_ROAD,          // Ħ�г���
    ITS_NONMOTOR_ROAD,       // �ǻ�������
    ITS_REVERSE_ROAD,        // ���򳵵�
    ITS_FORBIT_BIGCAR_ROAD,  // ��ֹ�󳵵�
    ITS_EMERGENCY            // Ӧ������
} PU_ITS_ROAD_PURPOSE_E;

// ��������
typedef enum PU_ITS_ROAD_ATTRIBUTE {
    ITS_ROAD_HIGHWAY,     // ���ٹ�·
    ITS_ROAD_EXPRESSWAY,  // ���п���·
    ITS_ROAD_OTHER,       // ������·
} PU_ITS_ROAD_ATTRIBUTE_E;

// �����Ա߳�������
typedef enum tagRoadSideScene {
    ITS_MEDIAN_ROAD_SIDE,       // ���������
    ITS_REALLINE_ROAD_SIDE,     // ʵ������
    ITS_DOTLINE_ROAD_SIDE,      // ��������
    ITS_UNKNOWN_ROAD_SIDE = 10  // δ֪��������
} ITS_ROAD_SIDE_SCENE_E;

// ����������Ϣ
typedef struct PU_ITS_LANE_INFO_BASE_UNIT {
    PU_ITS_ROAD_DIR_TYPE_E enLaneDirType;     // ������������
    PU_ITS_ROAD_DRV_DIR_E enLaneDrvDir;       // ������ʻ����
    PU_ITS_CAR_DRV_DIR_E enCarDrvDir;         // ��������Ƶ���˶�����
    PU_ITS_ROAD_PURPOSE_E enLanePurpose;      // ������;
    PU_ITS_ROAD_ATTRIBUTE_E enLaneAttribute;  // ��������
    INT iOSDLaneNO;                           // ���ӳ�����, OSD ���ӣ�һ����ʵ�ʳ���ƥ��
    INT iBindingDeviceCode;                   // ����������, ���ڶ�Ӧ�״��������IO ����
    INT iPreRecordStart;                      // Ԥ¼��ʼʱ��
    ITS_ROAD_SIDE_SCENE_E enLaneSideScene;    // �����������ͣ����ڵ�ͷΥ���жϣ� SDC8.0����֮��İ汾����֧�Ÿò���
    CHAR szReserve[PU_RESERVE_LEN - 1];
} PU_ITS_LANE_INFO_BASE_UNIT_S;

// ����ֵ
typedef struct PU_ITS_SPEED_LIMIT {
    INT iNormalSignSpeed;      // С����־�ٶ�(����ֵ��ΧΪ0~255km/h)
    INT iNormalLowSpeed;       // С�����Ƶ���(����ֵ��ΧΪ0~255km/h)
    INT iNormalHighSpeed;      // С�����Ƹ���(����ֵ��ΧΪ0~255km/h)
    INT iBigVehicleSignSpeed;  // �󳵱�־�ٶ�(����ֵ��ΧΪ0~255km/h)
    INT iBigVehicleLowSpeed;   // �����Ƶ���(����ֵ��ΧΪ0~255km/h)
    INT iBigVehicleHighSpeed;  // �����Ƹ���(����ֵ��ΧΪ0~255km/h)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_SPEED_LIMIT_S;

// ����������Ԫ
typedef struct PU_ITS_LANE_PARAM_UNIT {
    PU_ITS_LANE_INFO_BASE_UNIT_S stLaneInfoBaseU;  // ����������Ϣ
    PU_ITS_SPEED_LIMIT_S stSpeedLimit;             // �ٶ���������
    BOOL bRegulationRecord;                        // Υ��¼��ʹ��
    INT iExterLampBitMap;                          // ���õƹ���BitMap
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_LANE_PARAM_UNIT_S;

// ��Ƶ�羯��������
typedef struct PU_ITS_EPOLICE_LANE_PARAM {
    ULONG ulChannelId;                                        // ͨ��ID
    EN_ITS_TYPE enITSType;                                    // ITSҵ������
    INT iLaneNum;                                             // ��������
    PU_ITS_LANE_PARAM_UNIT_S astLaneParamU[MAX_AREA_VERTEX];  // ��������
    INT pauseTime;                                          // ��ϫ�����л��ȴ�ʱ��
    CHAR szReserve[PU_RESERVE_LEN - sizeof(INT)];
} PU_ITS_LANE_PARAM_S, PU_ITS_EPOLICE_LANE_PARAM_S, PU_ITS_TGATEWAY_LANE_PARAM_S, PU_ITS_PASSAGEWAY_LANE_PARAM_S;

#define ITS_REGULATION_TYPE_NUM_MAX 32
#define ITS_SNAP_NUM_MAX            4

// Υ�����ͼ�ⷽʽ
typedef enum ITS_REGULA_DT_TYPE {
    ITS_REGULA_DT_TYPE_EXTDEV,        // �������
    ITS_REGULA_DT_TYPE_VIDEODT,       // ��Ƶ���
    ITS_REGULA_DT_TYPE_EXTDEV_FIRST,  // ��������
    ITS_REGULA_DT_TYPE_MIXED,         // ���ģʽ
    ITS_REGULA_DT_TYPE_MAX
} EN_ITS_REGULA_DT_TYPE;

// Υ������
typedef enum PU_ITS_REGULA_TYPE {
    ITS_REGULA_NULL = 0,                          /* ��Υ���ж�, ��ʼֵ */
    ITS_REGULA_PASS_SNAP = 1,                     /* ����ץ�� */
    ITS_REGULA_RUNNINGRED = 2,                    /* �����     1625 */
    ITS_REGULA_EXCEET_SPEED = 3,                  /* ���� */
    ITS_REGULA_UNDER_SPEED = 4,                   /* ����    4306 */
    ITS_REGULA_WRONG_DIRECTION = 5,               /* ����������ʻ, ��ת/ֱ��/��ת 1208 */
    ITS_REGULA_REVERSE_DIRECTION = 6,             /* ���� 1301 */
    ITS_REGULA_LICENCE_RESTRICTE = 7,             /* β������ */
    ITS_REGULA_OVER_LANE_LINE = 8,                /* ѹ������ 1345 */
    ITS_REGULA_CHANGE_LANE = 9,                   /* Υ����� 13453 */
    ITS_REGULA_MOTOR_IN_BICYCLE_LANE = 10,        /* ��ռ�� 1018 */
    ITS_REGULA_ACCOMMODATION_LANE = 11,           /* ռ��ר�ó���  1019 */
    ITS_REGULA_PROHIBITION = 12,                  /* �����������ݲ�ʹ�� */
    ITS_REGULA_REMAIN_CROSS = 13,                 /* ·������ 1228 */
    ITS_REGULA_STOP_LIGHT_GREEN = 14,             /* �̵�ͣ�� 16251 */
    ITS_REGULA_EMERGENCY = 15,                    /* ռ��Ӧ������ */
    ITS_REGULA_SAFETY_BELT = 16,                  /* δϵ��ȫ�� 1240 */
    ITS_REGULA_U_TURN = 17,                       /* Υ�µ�ͷ 1044 */
    ITS_REGULA_PORT_VEHICLE_DRIVER_CALL = 18,     /* ����ʻ��绰 �����豸���� */
    ITS_REGULA_PORT_VEHICLE_COPILOT_NO_BELT = 19, /* ����ʻδϵ��ȫ�� �����豸���� */
    ITS_REGULA_PORT_VEHICLE_NO_YEAR_LOG = 20,     /* ������ �����豸���� */
    ITS_REGULA_ILLEGAL_PARKING = 21,              /* ������Υͣ */
    ITS_REGULA_IMPOLITE_PEDESTRIANS = 22,         /* ���������� */
    ITS_REGULA_OCCUPANCY_BUSLANE = 23,            /* Υ��ռ�ù������� */
    ITS_REGULA_LARGER_VEHICLE_OUTOFLANE = 24,     /* �󳵲���������ʻ */
    ITS_REGULA_IBALL_ILLEGAL_PARKING = 25,        /* Υ��ͣ�� */
    ITS_REGULA_VEHICLEBAN = 26,                   /* ������ */
    ITS_REGULA_NOVEHICLE_IN_LANE = 27,            /* ��ռ�� */
    ITS_REGULA_PED_RUN_RED = 28,                  /* ���˴���� */

    ITS_REGULA_RECOGNIZE_ONLY = 30, /* �羯����һ,��������ֻ��ʶ�����ϴ�Ԫ���ݵ��ô�ö�� */
    ITS_REGULA_ALL = 31,            /* �ں�ջ�ռ����ֻ֧��32��Υ�� */
    ITS_REGULA_BUTT = 32,

} PU_ITS_REGULA_TYPE_E;

// �������ȼ�
typedef enum PU_ITS_RUNLIGHT_PRIORITY {
    ITS_RUNLIGHT_NONE_PRIORITY,  // ��
    ITS_RUNLIGHT_RED_PRIORITY    // ���������
} PU_ITS_RUNLIGHT_PRIORITY_E;

// ����Υ���߼�
typedef enum PU_ITS_RUNLIGHT_RULE {
    ITS_RUNLIGHT_BYLANE,  // ������
    ITS_RUNLIGHT_BYDIR    // ������
} PU_ITS_RUNLIGHT_RULE_E;

// ���Ʋ���
typedef struct tagITSRunLightPara {
    PU_ITS_RUNLIGHT_PRIORITY_E enRunLightPriority;  // ���ȼ���
    PU_ITS_RUNLIGHT_RULE_E enRunLightRule;          // Υ���߼�
    INT iSecondSnapOffset;                          // �ڶ���ץͼƫ��
    INT iPicMinOffset;                              // ͼƬ��Сƫ��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_RUNLIGHT_PARA_S;

// ѹ��Υ��ץ�ĸ��Ӳ���
typedef struct tagITSRegulationCfgAttchPressLine {
    INT nSensitivity;  // ѹ�������ȣ�0~100ms��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_REGULATION_CFG_ATTCH_PRESS_LINE_UNIT_S;

// ��ռ��Υ��ץ�ĸ��Ӳ���
typedef struct tagITSRegulationCfgAttchInvadeDriverWay {
    INT nStayTime;  // ͣ��ʱ�䣨0~180ms��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S;

typedef union tagITSRegulationCfgAttch {
    PU_ITS_RUNLIGHT_PARA_S stRunningRed;                                            // Ԥ������ǰ��ʹ��, �����ץ�Ĳ���,��ӦΥ������ITS_REGULA_RUNNINGRED
    PU_ITS_REGULATION_CFG_ATTCH_PRESS_LINE_UNIT_S stPressLine;                      // ѹ��,��ӦΥ������ITS_REGULA_OVER_LANE_LINE
    PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S stInvadeDriverWay;          // ��ռ��,��ӦΥ������ITS_REGULA_MOTOR_IN_BICYCLE_LANE
    PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S stInvadeBusLane;            // �Ƿ�ռ�ù�������,��ӦΥ������ITS_REGULA_OCCUPANCY_BUSLANE
    PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S stIllegalParkTime;          // ������Υͣʱ��,��ӦΥ������ITS_REGULA_ILLEGAL_PARKING
    PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S stImpolitePedestriansTime;  // ���˵ȴ�ʱ��

} PU_ITS_REGULATION_CFG_ATTCH_UNIT_S;

// Υ��ץ�Ĳ�����Ԫ
typedef struct tagRegulationSnapConfigUnit {
    PU_ITS_REGULA_TYPE_E enRegulationType;         // ץ������
    BOOL bEnable;                                  // ץ��ʹ��
    INT iSnapNum;                                  // ץ������
    PU_ITS_REGULATION_CFG_ATTCH_UNIT_S uniAttach;  // ������Ϣ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_REGULATION_SNAP_CONFIG_UNIT_S;

// ��Ƶ�羯���ץ������
typedef struct tagItsEPoliceSnapType {
    ULONG ulChannelId;                          // ͨ��ID
    EN_ITS_TYPE enITSType;                      // ITSҵ������
    EN_ITS_REGULA_DT_TYPE enRegulaDtType;       // Υ�����ͼ�ⷽʽ
    INT aiMultiSnapInterval[ITS_SNAP_NUM_MAX];  // ���ļ��, ��λʱ�� ms

    /* �羯��1���� 2����� 3���� 4���� 5����������ʻ 6���� 7β������ 8ѹ������ 9Υ�����
     *       10��ռ�� 21������Υͣ 22���������� 23Υ��ռ�ù������� 24�󳵲���������ʻ
     *
     * ���ڣ�1���� 3���� 4���� 6���� 7β������ 8ѹ������ 9Υ����� 10��ռ�� 18�������ֻ�
     *      19��ϵ��ȫ�� 21������Υͣ 22���������� 23Υ��ռ�ù������� 24�󳵲���������ʻ
     *
 */
    INT iRegulationNum;                                                                       // Υ��ץ���������羯14������15��
    PU_ITS_REGULATION_SNAP_CONFIG_UNIT_S astRegulationSnapCfgU[ITS_REGULATION_TYPE_NUM_MAX];  // Υ��ץ������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_SNAP_TYPE_PARAM_S, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_S, PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_S;

// ץ��ʱ������ⷽʽ
typedef enum tagItsSnapItervalType {
    PU_ITS_SNAP_INTERVAL,           // �̶�ץ�ļ��
    PU_ITS_ADAPTIVE_SNAP_INTERVAL,  // ����Ӧץ�ļ��
    PU_ITS_SNAP_INTERVAL_TYPE_MAX
} PU_ITS_SNAP_INTERVAL_TYPE;

#define ITS_ADAPT_SNAP_INTERVAL_NUM_MAX 2
// Υ��ץ�ķ�ʽ(�����š�˫����)
typedef enum tagItsRegulaSnapType {
    PU_ITS_REGULA_SNAP_SINGLE_SHUTTER,  // ������
    PU_ITS_REGULA_SNAP_DOUBLE_SHUTTER,  // ˫����
    PU_ITS_REGULA_SNAP_TYPE_MAX
} PU_ITS_REGULA_SNAP_TYPE;

// ����Ӧץ�ļ������
typedef struct tagItsAdaptSnapIntervalType {
    ULONG uiLowSpeedMax;                                            // ����Ӧ�������ֵ
    ULONG uiMidSpeedMax;                                            // ����Ӧ�������ֵ
    INT aiAdaptLowSpeedInterval[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX];   // ����Ӧ�������ļ��, ��λʱ�� ms
    INT aiAdaptMidSpeedInterval[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX];   // ����Ӧ�������ļ��, ��λʱ�� ms
    INT aiAdaptHighSpeedInterval[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX];  // ����Ӧ���� ���ļ��, ��λʱ�� ms
} PU_ITS_ADAPT_INTERVAL_PARAM_S;
// ��Ƶ�羯���ץ����������
typedef struct tagItsEPoliceSnapType_V2 {
    ULONG ulChannelId;                          // ͨ��ID������
    EN_ITS_TYPE enITSType;                      // ITSҵ�����ͣ�����
    EN_ITS_REGULA_DT_TYPE enRegulaDtType;       // Υ�����ͼ�ⷽʽ
    INT aiMultiSnapInterval[ITS_SNAP_NUM_MAX];  // ���ļ��, ��λʱ�� ms

    /* �羯��1���� 2����� 3���� 4���� 5����������ʻ 6���� 7β������ 8ѹ������ 9Υ�����
     *       10��ռ�� 21������Υͣ 22���������� 23Υ��ռ�ù������� 24�󳵲���������ʻ
     *
     * ���ڣ�1���� 3���� 4���� 6���� 7β������ 8ѹ������ 9Υ����� 10��ռ�� 16����ʻ��ϵ��ȫ�� 18�������ֻ�
     *      19����ʻ��ϵ��ȫ�� 21������Υͣ 22���������� 23Υ��ռ�ù������� 24�󳵲���������ʻ
     *
 */
    INT iRegulationNum;                                                                       // Υ��ץ���������羯14������15��
    PU_ITS_REGULATION_SNAP_CONFIG_UNIT_S astRegulationSnapCfgU[ITS_REGULATION_TYPE_NUM_MAX];  // Υ��ץ������

    PU_ITS_SNAP_INTERVAL_TYPE enITSSnapIntervalType;    // ץ�ļ������
    PU_ITS_ADAPT_INTERVAL_PARAM_S stAdaptSnapInterval;  // ����Ӧץ�ļ������
    PU_ITS_REGULA_SNAP_TYPE enRegulaSnapType;           // Υ��ץ�ķ�ʽ(�����š�˫����)
    CHAR szReserve[PU_RESERVE_EX_LEN - sizeof(PU_ITS_REGULA_SNAP_TYPE)];
} PU_ITS_SNAP_TYPE_PARAM_V2_S, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_V2_S, PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_V2_S,
PU_ITS_PASSAGEWAY_SNAP_TYPE_PARAM_S;

#define MAX_AREA_POINTS_NUM 10  // ���򶥵������Ŀ

// ��Ƶ�羯�����ʹ��
typedef struct tagItsEPoliceDtLineEnable {
    BOOL abRoadLane[MAX_LANE_NUM];  // ������ʹ��
    BOOL abStopLine[MAX_LANE_NUM];  // ֹͣ��ʹ��
    BOOL abTripLine[MAX_LANE_NUM];  // ����ʹ��
    BOOL bLaneRhtBorderLine;        // �����ұ߽���
    BOOL bLftBorderLine;            // ��ת�߽���
    BOOL bRhtBorderLine;            // ��ת�߽���
    BOOL bStrightTrigger;           // ֱ�д�����
    BOOL bRunningRedTrigger;        // ����ƴ�����
    BOOL bTurnAroundLine;           // ��ͷ�����  SDC8.0����֮��İ汾����֧�Ÿò���
    BOOL bPosBox;                   // ��λ��
} PU_ITS_EPOLICE_DT_LINE_ENABLE_S;

typedef struct PU_VIM_POINT {
    INT lPointPosX;
    INT lPointPosY;
} PU_VIM_POINT_ST;

/* ͼ�������ת��ʽ */
typedef enum VIDEO_VENC_ROTATION {
    VIDEO_ROTATION_NORMAL = 0,  // ����ͼ��
    VIDEO_ROTATION_MIRROR,      // ���Ҿ���
    VIDEO_ROTATION_FILP,        // ����
    VIDEO_ROTATION_BOTH,        // ��������
    VIDEO_ROTATION_MAX
} VIDEO_VENC_ROTATION_E;

typedef struct LOCATION_INFO {
    FLOAT fxDegree;  // ����Ƕ�
    FLOAT fyDegree;
    FLOAT fDZoomRatio;
    INT lPOS;                               // POS
    VIDEO_VENC_ROTATION_E enVideoRotation;  // ��Ƶ����ģʽ
} LOCATION_INFO_S;

/* ������ */
typedef struct PU_AREA {
    ULONG ulIndex;
    PU_ENABLE_TYPE_E enEnable;
    ULONG uPointNum;                              /* �������ζ�����Ŀ */
    PU_VIM_POINT_ST stPoint[MAX_AREA_POINTS_NUM]; /* ������ */
    LOCATION_INFO_S stLocation;                   // ��̨λ����Ϣ
    CHAR stAreaName[PU_IGT_AREA_NAME_LEN];        // ��������
} PU_AREA_S;

typedef enum tagLaneDirection {
    LANE_DIRECTION_DOWN,  /* �����˶� */
    LANE_DIRECTION_UP,    /* �����˶� */
    LANE_DIRECTION_UNDEF, /* δ�����˶�����, �޷��ж�����, ֻ���ٶ�ֵ */
} LANE_DIRECTION_E;

typedef enum tagDirectionSignType {
    DERICTION_TYPE_LEFT,                /* ��ת */
    DERICTION_TYPE_STRAIGHT,            /* ֱ�� */
    DERICTION_TYPE_LEFT_STRAIGHT,       /* ��תֱ�� */
    DERICTION_TYPE_RIGHT,               /* ��ת */
    DERICTION_TYPE_LEFT_RIGHT,          /* ��ת��ת */
    DERICTION_TYPE_RIGHT_STRAIGHT,      /* ��תֱ�� */
    DERICTION_TYPE_LEFT_RIGHT_STRAIGHT, /* ��ת��תֱ�� */
    DERICTION_TYPE_LEFT_STAY,           /* ��ת���� */
    DERICTION_TYPE_STRAIGHT_STAY,       /* ֱ�д��� */
    DERICTION_TYPE_RIGHT_STAY,          /* ��ת���� */
    DERICTION_TYPE_BUTT
} DERICTION_SIGN_TYPE_E;

typedef enum tagITSRoadLineType {
    ITS_ROAD_LINE_TYPE_WHITE_SOLOD,   /* ��ʵ�� */
    ITS_ROAD_LINE_TYPE_WHITE_DOTTED,  /* ������ */
    ITS_ROAD_LINE_TYPE_SINGLE_YELLOW, /* ������ */
    ITS_ROAD_LINE_TYPE_DOUBLE_YELLOW, /* ˫���� */
    ITS_ROAD_LINE_TYPE_GUARD_BAR,     /* �л��������� */
} ITS_ROAD_LINE_TYPE_E;

typedef struct tagRoadPropertyUnit {
    PU_ITS_CAR_DRV_DIR_E enLaneDirection;  /* ������ʻ����: ����ȥ��, ������������������ */
    PU_ITS_ROAD_DRV_DIR_E enSignDirection; /* ��־������ʻ����: ����ת��ֱ�е� */
    ITS_ROAD_LINE_TYPE_E enLineType;       /* ���������� */
    ITS_ROAD_SIDE_SCENE_E enLaneSideScene; /* �����������ͣ����ڵ�ͷΥ���ж� */
    PU_IMRS_LINE_S stLine;                 /* ������ */
} ROAD_PROPERTY_UNIT_S;

typedef enum tagPositionBoxType {
    ITS_POS_BOX_TYPE_BIG,
    ITS_POS_BOX_TYPE_MID,
    ITS_POS_BOX_TYPE_SMALL
} PU_ITS_POS_BOX_TYPE_E;

typedef struct AERADTC_LIST {
    ULONG ulAreaNum;
    PU_AREA_S stArea[MAX_AREA_NUM];
} AERADTC_LIST_S;

// ��Ƶ�羯����߲���
typedef struct tagItsEPoliceDtLineParam {
    PU_ITS_EPOLICE_DT_LINE_ENABLE_S stEnableList;  // �߲���ʹ�ܱ�
    INT iLaneNum;                                  // ����������
    ROAD_PROPERTY_UNIT_S stLane[MAX_LANE_NUM];     // ������ = ������+1
    ROAD_PROPERTY_UNIT_S stLaneRhtBorderLine;      // �����ұ߽���
    INT iStopNum;                                  // ֹͣ������
    PU_IMRS_LINE_S stStopLine[MAX_LANE_NUM];       // ֹͣ��
    PU_IMRS_LINE_S stTripLine[MAX_LANE_NUM];       // ����ߣ�������ߣ�����ģʽ����ץ�ģ�
    PU_IMRS_LINE_S stLftBorderLine;                // ��ת�߽���
    PU_IMRS_LINE_S stRhtBorderLine;                // ��ת�߽���
    PU_IMRS_LINE_S stStrightTrigger;               // ֱ�д�����
    PU_IMRS_LINE_S stRunningRedTrigger;            // ����ƴ�����
    PU_IMRS_LINE_S stTurnAroundLine;               // ��ͷ�����  SDC8.0����֮��İ汾����֧�Ÿò���

    PU_ITS_POS_BOX_TYPE_E enPosBoxType;                 // ��λ��
    AERADTC_LIST_S stVLPRAreaList;                      // ��ѳ���ʶ������
    AERADTC_LIST_S stIllegalParkAreaList;               // ����������
    AERADTC_LIST_S stImpolitePedestriansAreaList;       // ���˼�����
    CHAR aucLocalPlate[MAX_RESTRICTED_LOCALPLATE_LEN];  // ����ʡ���У�
} PU_ITS_EPOLICE_DT_LINE_PARAM_S;

/* ITS����߲����ṹ�� */
typedef struct PU_ITS_DT_LINE_PARAM {
    ULONG ulChannelId;      // ͨ��ID
    EN_ITS_TYPE enITSType;  // ITSҵ������
    BOOL bEnable;           // ITSҵ���Ƿ�ʹ��
    // ����ҵ��ṹ�����𡿴˴�ȡ�������壬ֱ�Ӷ�������ṹ��
    PU_ITS_EPOLICE_DT_LINE_PARAM_S stEPolice;  // ITS��Ƶ�羯����߲���

} PU_ITS_DT_LINE_PARAM_S;

typedef struct PU_ATTRIBUT_LINE {
    BOOL bUsing;            // �Ƿ�����(ֻ���õ羯ģʽ)
    PU_IMRS_LINE_S stLine;  // �����
} PU_ATTRIBUT_LINE_S;

/* ITS����߲����ṹ������ */
typedef struct PU_ITS_DT_LINE_PARAM_V2 {
    ULONG ulChannelId;      // ͨ��ID
    EN_ITS_TYPE enITSType;  // ITSҵ������
    BOOL bEnable;           // ITSҵ���Ƿ�ʹ��
    // ����ҵ��ṹ�����𡿴˴�ȡ�������壬ֱ�Ӷ�������ṹ��
    PU_ITS_EPOLICE_DT_LINE_PARAM_S stEPolice;  // ITS��Ƶ�羯����߲���
    PU_ATTRIBUT_LINE_S stPreTestLine;          // ǰ�ü����
    CHAR szReserve[PU_RESERVE_EX_LEN];         // Ԥ��

} PU_ITS_DT_LINE_PARAM_V2_S;

// ���˴������������
typedef struct PU_PEDRUNRED_FACE_PARAM {
    ULONG ulChannelId;                    // ͨ��ID
    PU_FACE_DETC_DL_PARA_S stFaceDtPara;  // ����������
    BOOL bFaceEnhancement;                // ����������ǿ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PEDRUNRED_FACE_PARAM_S;
// ���˴���Ƽ���߲���
typedef struct PU_ITS_PEDRUNRED_DT_LINE_PARAM {
    ULONG ulChannelId;                             // ͨ��ID
    PU_IMRS_LINE_S stLines[PED_RUN_RED_LINE_NUM];  // ���˴���ƴ�����
    AERADTC_LIST_S stAreaList;                     // ���˴��������
} PU_ITS_PEDRUNRED_DT_LINE_PARAM_S;

// ITSͼƬ��ѯ����
typedef struct PU_ITS_SNAPSHOT_INQUIRE {
    ULONG ulChnID;
    ULONG ulBeginIndex;                            // ��ǰ��ʼ��¼����(>=1)
    ULONG ulBeginTime;                             // ��ʼʱ��(time_t/localTime=GMT+ʱ��)
    ULONG ulEndTime;                               // ����ʱ��
    PU_SNAPSHOT_TYPE_E enSnapShotType;             // ץ������
    ULONG ulLaneID;                                // ������
    PU_VEHICLE_TYPE_E enVehicleType;               // ��������
    PU_ITS_REGULA_TYPE_E enVehicleRegulationType;  // Υ������
    ULONG ulRegulationRecordTime;                  // Υ��¼��ʱ�䳤��
    BOOL bOnceInquireFlag;                         // ��ҳ��ѯ��ǣ�TRUE ��ʾͼƬ��ѯֻ����һҳ��ѯ�������	
    PU_GET_SNAPSHOT_LIST_TYPE_E enSnapTimeType;    //ץ��ʱ���ʽ ���ػ���UTC
    CHAR szReserved[PU_RESERVE_LEN - sizeof(PU_GET_SNAPSHOT_LIST_TYPE_E)];
} PU_ITS_SNAPSHOT_INQUIRE_S;

// ���̵ƽ��뷽ʽ
typedef enum PU_ItS_LIGHT_DT_TYPE {
    ITS_LIGHT_DT_TYPE_485,    // 485����
    ITS_LIGHT_DT_TYPE_VIDEO,  // ��Ƶ����
    ITS_LIGHT_DT_TYPE_UNKNOW,
} PU_ITS_LIGHT_DT_TYPE_S;

// �źŵƵ���
typedef struct PU_ITS_LIGHT_DIR {
    BOOL bLeft;      // ��ת
    BOOL bStraight;  // ֱ��
    BOOL bRight;     // ��ת
} PU_ITS_LIGHT_DIR_S;
// �źŵ���ɫ
typedef struct PU_ITS_LIGHT_COLOR {
    BOOL bRed;     // ���
    BOOL bGreen;   // �̵�
    BOOL bYellow;  // �Ƶ�
} PU_ITS_LIGHT_COLOR_S;
// �źŵƷ�ʽ��ʽ
typedef enum PU_ITS_LIGHT_ARRANGE_TYPE {
    ITS_LIGHT_ARRANGE_TYPE_BROADWISE, /* ���� */
    ITS_LIGHT_ARRANGE_TYPE_ENDWISE,   /* ���� */
    ITS_LIGHT_ARRANGE_TYPE_UNKOWN,
} PU_ITS_LIGHT_ARRANGE_TYPE_E;

/**************����********************/
typedef struct PU_MD_AREA {
    FLOAT fX1;
    FLOAT fY1;
    FLOAT fX2;
    FLOAT fY2;
} PU_MD_AREA_S;
// �źŵ��������
typedef struct PU_ITS_SIGNAL_LIGHT_AREA_PARAM {
    PU_ITS_LIGHT_DIR_S stLightDir;                   // �źŵƵ���
    PU_ITS_LIGHT_COLOR_S stLightColor;               // �źŵ���ɫ
    INT iLightNum;                                   // �Ƹ�����ֻ������1����3��
    PU_ITS_LIGHT_ARRANGE_TYPE_E enLightArrangeType;  // �źŵư�װ��ʽ
    INT iYellowTime;                                 // �ƵƳ���ʱ��(��Χ��0~15��Ĭ��ֵ��3)
    PU_MD_AREA_S stLightArea;                        // �źŵ�λ�ÿ�
    CHAR szReserve[PU_RESERVE_LEN];                  // szReserve[0]: ���Ƶ�ʹ�ܱ�־��szReserve[1]: ѡ���ʹ�ܱ�־
    // szReserve[2]:�źŵƵ��򣬵�ͷ
} PU_ITS_SIGNAL_LIGHT_AREA_PARAM_S;

// �羯�źŵƲ���
typedef struct PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM {
    ULONG ulChannelId;                                                              // ͨ��ID
    PU_ITS_LIGHT_DT_TYPE_S enLightDtType;                                           // ���̵Ƽ����뷽ʽ
    INT iSignalLightAreaNum;                                                        // �źŵ����������ȡֵֻ����4���̶�����4���źŵ�����
    PU_ITS_SIGNAL_LIGHT_AREA_PARAM_S astSignalLightList[PU_ITS_MAX_LIGHTAREA_NUM];  // �źŵƲ���
    EN_ITS_TYPE enITSType;                                                          // ITSҵ������
    CHAR szReserve[PU_RESERVE_LEN - sizeof(EN_ITS_TYPE)];
} PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM_S;

// ��Ƶ�羯ģ����̵Ʋ���
typedef struct PU_ITS_SIM_TRAFFIC_LIGHT_PARAM {
    ULONG ulChannelId;  // ͨ��ID
    BOOL bLeftTurn;     // ��ת�źŵ�
    BOOL bRightTurn;    // ��ת�źŵ�
    BOOL bGoStraight;   // ֱ���źŵ�
    BOOL bTurnAround;   // ��ͷ�źŵ�
    CHAR szReserve[PU_RESERVE_LEN - sizeof(BOOL)];
} PU_ITS_SIM_TRAFFIC_LIGHT_PARAM_S;

/* ����Υ���ֵ��е�Υ������ */
typedef struct PU_ITS_ILLEGAI_DIC_PARA_UNIT {
    CHAR szIllTypeString[PU_ITS_ILLEGAL_TYPE_LEN_MAX];  // Υ�����ͣ��޸���Ч,��󳤶�PU_ITS_ILLEGAL_TYPE_LEN_MAX - 4
    CHAR szIllCodeString[PU_ITS_ILLEGAL_NUM_LEN_MAX];   // Υ�����룬��󳤶�PU_ITS_ILLEGAL_NUM_LEN_MAX - 1
    CHAR szIllNameString[PU_ITS_ILLEGAL_NAME_LEN_MAX];  // Υ���������ƣ���󳤶�PU_ITS_ILLEGAL_NAME_LEN_MAX - 4
} PU_ITS_ILLEGAI_DIC_PARA_UNIT_S;

/* Υ���ֵ���� */
typedef struct PU_ITS_ILLEGAI_DIC_PARA {
    ULONG ulChannelID;                                                        // ͨ��ID
    PU_LANGUAGE_TYPE_E enLanguageType;                                        // ���ԣ���ȡ����ʱ��ʹ��
    ULONG ulIllegalNum;                                                       // Υ���ֵ�����
    PU_ITS_ILLEGAI_DIC_PARA_UNIT_S astIllegals[PU_ITS_ILLEGAL_TYPE_NUM_MAX];  // Υ����
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_ILLEGAI_DIC_PARAM_S;

/*************begin:��ͨ���**************/
// ץ��ͼƬ����
typedef enum PU_IBALL_FRAME_TYPE {
    PU_IBALL_FRAME_TYPE_FAR = 0,  // Զ��ͼ
    PU_IBALL_FRAME_TYPE_NEAR,     // ����ͼ
    PU_IBALL_FRAME_TYPE_FEATURE,  // ����ͼ
    PU_IBALL_FRAME_TYPE_MAX
} PU_IBALL_FRAME_TYPE_E;

// ��ͨ���Υ��ͣ������
typedef enum PU_TD_ILLEGAL_TYPE {
    TDOME_ILLEGAL_TYPE_A = 0,  // ������Υ���涨ͣ��
    TDOME_ILLEGAL_TYPE_B,      // ������Υ����ͣ��־
    TDOME_ILLEGAL_TYPE_C,      // �ǽ����������Ӧ���������г���ͣ��
    TDOME_ILLEGAL_TYPE_D,      // δʹ��
    TDOME_ILLEGAL_TYPE_MAX
} PU_TD_ILLEGAL_TYPE_E;

// ��ͨ����㷨����
typedef struct PU_TD_ALG_PARAMS {
    ULONG ulChannelId;                   // ͨ��ID
    BOOL bEnable;                        // �㷨ʹ��
    ULONG ulFilterThreshold;             // Υ�¹�����ֵ����λ:���ӣ���Χ:1-1440
    LONG lPTZCalibrationHorizontal;      // ��̨У׼����(ˮƽ)����Χ:-2 - 2
    LONG lPTZCalibrationVertical;        // ��̨У׼����(��ֱ)����Χ:-2 - 2
    BOOL bRecordEnable;                  // ¼����ʹ��
    PU_TD_ILLEGAL_TYPE_E enIllegalType;  // Υ��ͣ������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_TD_ALG_PARAMS_S;

// ��ͨ����㷨����
typedef struct PU_TD_ALG_PARAMSV2 {
    ULONG ulChannelId;  // ͨ��ID
    BOOL bEnable;       // �㷨ʹ��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_TD_ALG_PARAMSV2_S;

// ��ͨ����ֶ������Ļλ��
typedef struct PU_TD_MANUAL_DETECTION_POSITION {
    ULONG ulChannelId;          // ͨ��ID
    PU_RECTANGLE_S stRectArea;  // �ֶ������λ�ã�355*288����ϵ
    CHAR szReserve[PU_RESERVE_LEN];
} PU_TD_MANUAL_DETECTION_POS_S;

// ��ͨ�����ʱ��������
typedef struct PU_TD_TIMING_LOCK_PARAMS {
    BOOL bEnable;  // ʹ��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_TD_TIMING_LOCK_PARAMS_S;

// ��ͨ�����������
typedef struct PU_TD_UNLOCK_PARAMS_S {
    BOOL bEnable;  // ʹ��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_TD_UNLOCK_PARAMS_S;

// ��ͨ���ת������������
typedef struct PU_TD_SCENE_MOVE_TO_SCENE {
    ULONG ulChannelId;  // ͨ��ID
    ULONG ulIndex;      // �������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_TD_SCENE_MOVE_TO_SCENE_S;

// Υͣ���ץ�Ĺ���
typedef struct PU_TD_ILLEGAL_PARKINK_SNAP_RULE {
    ULONG ulFrameNum;                                          // ץ������
    PU_IBALL_FRAME_TYPE_E enFrameType[TD_MAX_SNAP_FRAME_NUM];  // ץ��ͼƬ����
    ULONG ulInterval[TD_MAX_SNAP_FRAME_NUM];                   // ץ�ļ��
} PU_TD_ILLEGAL_PARKINK_SNAP_RULE_S;

// Υͣ������
typedef struct PU_TD_ILLEGAL_PARKINK_PARAMS {
    BOOL bEnable;                                   // Υͣ���ʹ��
    BOOL abRelatedLane[MAX_LANE_NUM];               // ��������
    ULONG ulDetectInterval;                         // �����(Ŀǰ��������ץ�Ĺ���)
    PU_TD_ILLEGAL_PARKINK_SNAP_RULE_S stSnapRules;  // ץ�Ĺ���
} PU_TD_ILLEGAL_PARKINK_PARAMS_S;

// ��ͨ����ֶ�Υͣ����㷨����
typedef struct PU_TD_MANUAL_DETECTION_PARAMS {
    ULONG ulChannelId;                                // ͨ��ID
    PU_TD_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;  // Υͣ������
} PU_TD_MANUAL_DETECTION_PARAMS_S;

// ѭ��ģʽ
typedef enum PU_CYCLIC_MODE {
    PU_E_NOT_CYCLIC = 0,  // ��ѭ��
    PU_E_WEEK_CYCLIC,     // ��ѭ��
} PU_CYCLIC_MODE_E;

// Ѳ��ģʽ
typedef enum PU_TOUR_MODE {
    PU_E_DETECT_PRIORITY = 0,  // �������
    PU_E_SCENE_PRIORITY,       // ��������
} PU_TOUR_MODE_E;

// Ѳ���켣��
typedef struct PU_TD_TOUR_TRACK_POINT_PARAMS {
    ULONG ulIndex;         // �������, �볡��������ĳ���ѡ��ID һ��
    ULONG ulStayDruation;  // ����ͣ��ʱ��(����)
} PU_TD_TOUR_TRACK_POINT_PARAMS_S;

// ÿ��Ѳ���ƻ�����
typedef struct PU_TD_TOUR_PLAN_ONE_DAY_PARAMS {
    ULONG ulBeginTime;                                                   // Ѳ����ʼʱ��(����)
    ULONG ulEndTime;                                                     // Ѳ������ʱ�� (����)
    ULONG ulSceneNum;                                                    // ÿ��Ѳ���ƻ�������Ѳ���켣�����
    PU_TD_TOUR_TRACK_POINT_PARAMS_S stTourTrackPoint[TD_MAX_SCENE_NUM];  // ÿ��Ѳ���ƻ�
} PU_TD_TOUR_PLAN_ONE_DAY_PARAMS_S;

// ��ͨ���Ѳ���ƻ�����
typedef struct PU_TD_TOUR_PLAN_PARAMS {
    ULONG ulChannelId;                                                    // ͨ��ID
    BOOL bTourPlanEnable;                                                 // Ѳ���ƻ�ʹ��
    PU_CYCLIC_MODE_E enCyclicMode;                                        // ѭ��ģʽ
    PU_TOUR_MODE_E enTourMode;                                            // Ѳ��ģʽ
    PU_TD_TOUR_PLAN_ONE_DAY_PARAMS_S stTourPlanDay[TD_MAX_DAY_ONE_WEEK];  // Ѳ���ƻ�����
} PU_TD_TOUR_PLAN_PARAMS_S;

// ��ͨ��������ʹ��
typedef struct PU_TD_DTLINE_ENABLE {
    BOOL abRoadLane[MAX_LANE_NUM];  // ������ʹ��
    BOOL bLaneRhtBorderLine;        // �����ұ߽���
} PU_TD_DTLINE_ENABLE_S;

// ��ͨ��������ʹ��
typedef struct PU_TD_DTLINE_ENABLEV2 {
    BOOL abRoadLane[TDOME_MAX_LANE_NUM];  // ������ʹ��
    BOOL bLaneRhtBorderLine;              // �����ұ߽���
} PU_TD_DTLINE_ENABLEV2_S;

// ��ͨ�����������
typedef struct PU_TD_LINE_PARAM {
    ULONG ulLaneNum;                            // ����������
    PU_TD_DTLINE_ENABLE_S stEnableList;         // �߲���ʹ�ܱ�
    ROAD_PROPERTY_UNIT_S stLane[MAX_LANE_NUM];  // ������ = ������+1
    ROAD_PROPERTY_UNIT_S stLaneRhtBorderLine;   // �����ұ߽���
} PU_TD_LINE_PARAM_S;

// ��ͨ�����������
typedef struct PU_TD_LINE_PARAMV2 {
    ULONG ulLaneNum;                                  // ����������
    PU_TD_DTLINE_ENABLEV2_S stEnableList;             // �߲���ʹ�ܱ�
    ROAD_PROPERTY_UNIT_S stLane[TDOME_MAX_LANE_NUM];  // ������ = ������+1
    ROAD_PROPERTY_UNIT_S stLaneRhtBorderLine;         // �����ұ߽���
} PU_TD_LINE_PARAMV2_S;

// ��ͨ�������Ӧ�ò���
typedef struct PU_TD_SCENE_APP_PARAMS {
    ULONG ulChannelId;                                // ͨ��ID
    ULONG ulIndex;                                    // �������
    PU_TD_LINE_PARAM_S stLaneLine;                    // �����߲���
    PU_TD_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;  // Υͣ������
} PU_TD_SCENE_APP_PARAMS_S;

typedef struct PU_TD_MD_AREA {
    ULONG ulX1;
    ULONG ulY1;
    ULONG ulX2;
    ULONG ulY2;
} PU_TD_MD_AREA_S;

// ��ͨ���ֶ�����ȡ֤Ŀ����Ϣ
typedef struct PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_TARGET {
    ULONG ulChannelId;           // ͨ��ID
    ULONG ulObjID;               // ������Ŀ��ID
    PU_TD_MD_AREA_S stRectArea;  // Ŀ������λ��
} PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_TARGET_S;

// ��ͨ���ֶ�����ȡ֤����
typedef struct PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_SWITCH {
    ULONG ulChannelId;  // ͨ��ID
    BOOL bEnable;       // �򿪻�ر�
} PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_SWITCH_S;

// ͼƬ����������Ϣ
typedef struct PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO {
    BOOL bNearSnapAddTargetInfoFlag;  // ����ץͼ����Ŀ����Ϣ
    BOOL bNearSnapAddRuleInfoFlag;    // ����ץͼ���ӹ�����Ϣ
    BOOL bFarSnapAddTargetInfoFlag;   // Զ��ͼ����Ŀ����Ϣ
    BOOL bFarSnapAddRuleInfoFlag;     // Զ��ͼ���ӹ�����Ϣ
} PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO_S;

// ��ͨ��Υ�����ܷ�������
typedef struct PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS {
    ULONG ulChannelId;                                                 // ͨ��ID
    CHAR szPlateLocalZH[MAX_PLATE_LOCAL_ZH_LEN];                       // ���ȳ�������
    PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO_S stOverlayIntelInfo;  // ͼƬ����������Ϣ
    BOOL bPlateSmallPic;                                               // ����Сͼ��Ĭ��FALSE
    BOOL bEventUploadFlag;                                             // Υ���¼������ϴ�    Ĭ��TRUE
    BOOL bEvidenceUploadFlag;                                          // Υ��ȡ֤�����ϴ�   Ĭ��TRUE
    ULONG ulFilterThreshold;                                           // Υ�¹�����ֵ            Ĭ�������ֵ
    LONGLONG lPTZCalibrationHorizontal;                                // ��̨У׼����(ˮƽ)
    LONGLONG lPTZCalibrationVertical;                                  // ��̨У׼����(��ֱ)
    PU_TD_ILLEGAL_TYPE_E enIllegalType;                                // Υ��ͣ������
    BOOL bRecordEnable;                                                // ¼����ʹ��      Ĭ����FALSE
} PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS_S;

// ��ͨ���Ӧ�ò��� - Υͣ���
typedef struct PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS {
    BOOL bEnable;                                   // ���ʹ��
    ULONG ulSnapFrameNum;                           // ץ������
    ULONG ulSensitivity;                            // ������
    ULONG ulContinuousDuration;                     // ����ʱ��
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];         // ��������
    ULONG ulDetectInterval;                         // �����(Ŀǰ��������ץ�Ĺ���)
    ULONG ulPlateMatchRate;                         // ����ƥ����
    PU_TD_ILLEGAL_PARKINK_SNAP_RULE_S stSnapRules;  // V2�ӿ������ýṹ�壬������д
} PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S;

// ��ͨ����ֶ�Υͣ����㷨����
typedef struct PU_TD_MANUAL_DETECTION_PARAMSV2 {
    ULONG ulChannelId;  // ͨ��ID
    INT iVersion;       /* �ӿڰ汾�ţ��û�������д */
    PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;
} PU_TD_MANUAL_DETECTION_PARAMSV2_S;

// ��ͨ����ֶ�Υͣ����㷨����
typedef struct tagTRAFFIC_DOME_MANUAL_DETECTION_PARAMS_S {
    ULONG ulChannelId;  // ͨ��ID
    PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;
} PU_TD_TRAFFIC_DOME_MANUAL_DETECTION_PARAMS_S;

// ===Begin ��ͨ�������Ӧ�ò���===
// ��ͨ���Ӧ�ò��� - Υͣ���
// TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S

// ��ͨ���Ӧ�ò���- ���м��
typedef struct PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS {
    BOOL bEnable;                            // ���ʹ��
    ULONG ulSnapFrameNum;                    // ץ������
    ULONG ulSensitivity;                     // ������
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];  // ��������
} PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS_S;

// ��ͨ���Ӧ�ò���- ��ͷ���
typedef struct PU_TD_TRAFFIC_DOME_U_TURN_PARAMS {
    BOOL bEnable;                            // ���ʹ��
    ULONG ulSnapFrameNum;                    // ץ������
    ULONG ulSensitivity;                     // ������
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];  // ��������
} PU_TD_TRAFFIC_DOME_U_TURN_PARAMS_S;

// ��ͨ���Ӧ�ò���- ѹ�߼��
typedef struct PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS {
    BOOL bEnable;                            // ���ʹ��
    ULONG ulSnapFrameNum;                    // ץ������
    ULONG ulSensitivity;                     // ������
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];  // ��������
} PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS_S;

// ��ͨ���Ӧ�ò���- ������
typedef struct PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS {
    BOOL bEnable;                            // ���ʹ��
    ULONG ulSnapFrameNum;                    // ץ������
    ULONG ulSensitivity;                     // ������
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];  // ��������
} PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS_S;

// ��ͨ���Ӧ�ò���- ��ռ�Ǽ��
typedef struct PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS {
    BOOL bEnable;                            // ���ʹ��
    ULONG ulSnapFrameNum;                    // ץ������
    ULONG ulSensitivity;                     // ������
    ULONG ulContinuousDuration;              // ����ʱ��
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];  // ��������
} PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS_S;

// ��ͨ���Ӧ�ò��� - Υ��ȡ֤
typedef struct PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS {
    PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S stIllegalParkingParams;  // Υͣ������
    PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS_S stRevDirectParams;     // ���м��ץ�Ĺ���
    PU_TD_TRAFFIC_DOME_U_TURN_PARAMS_S stUTurnParams;                    // Υ����ͷץ�Ĺ���
    PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS_S stOverLaneLineParams;     // ѹ�߼��ץ�Ĺ���
    PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS_S stChangeLaneParams;          // Υ�����ץ�Ĺ���
    PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS_S stMiBLaneParams;   // ��ռ��ץ�Ĺ���
} PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS_S;

// ��ͨ���Ӧ�ò���- ��ͨ�¼����˼�����
typedef struct PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS {
    BOOL bEnable;                            // ���ʹ��
    ULONG ulSensitivity;                     // ������
    ULONG ulContinuousDuration;              // ����ʱ��
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];  // ��������
} PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS_S;

// ��ͨ���Ӧ�ò���- ��ͨ�¼�ӵ�¼�����
typedef struct PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS {
    BOOL bEnable;                            // ���ʹ��
    ULONG ulSensitivity;                     // ������
    ULONG ulContinuousDuration;              // ����ʱ��
    ULONG ulFilterDuration;                  // ����ʱ��
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];  // ��������
} PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS_S;

// ��ͨ���Ӧ�ò��� - ��ͨ�¼�
typedef struct PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS {
    PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS_S stPedDtParams;                // ���˼��
    PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS_S stCongestionDtParams;  // ӵ�¼��
} PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS_S;

// ��ͨ���Ӧ�ò��� - ��ͨ���ݲɼ�
typedef struct PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS {
    BOOL bEnable;                            // ���ʹ��
    ULONG ulStatisticsInterval;              // ͳ�Ƽ��
    BOOL abRelatedLane[TDOME_MAX_LANE_NUM];  // ��������
} PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS_S;

// ��ͨ�������Ӧ�ò���
typedef struct PU_TD_SCENE_APP_PARAMSV2 {
    ULONG ulChannelId;                                                            // ͨ��ID
    ULONG ulIndex;                                                                // �������
    PU_TD_LINE_PARAMV2_S stLaneLine;                                              // �����߲���
    PU_TD_ILLEGAL_PARKINK_PARAMS_S stIllegalParking;                              // ��ʹ�ã���Ҫ���Ǽ������豸ʹ��
    PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS_S stIllegalEviParams;              // Υ��ȡ֤����
    PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS_S stTrafficEventParams;               // ��ͨ�¼�����
    PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS_S stTrafficDataCollectParams;  // ��ͨ���ݲɼ�����
} PU_TD_SCENE_APP_PARAMSV2_S;

// ��ͨ�����������
typedef enum PU_TD_SCENE_DIRECTION {
    PU_TD_SCENE_DIRECTION_SINGLE = 0,  // ����
    PU_TD_SCENE_DIRECTION_DOUBLE,      // ˫��
    PU_TD_SCENE_DIRECTION_MAX
} PU_TD_SCENE_DIRECTION_E;

// ��ͨ���������������
typedef struct PU_TD_SCENE_BASE_PARAMS {
    ULONG ulChannelId;                           // ͨ��ID
    ULONG ulIndex;                               // �������
    BOOL bEnable;                                // ����ʹ��
    PU_TD_SCENE_DIRECTION_E enDirection;         // ��������
    CHAR szSceneName[TD_MAX_STRING_LENGTH];      // ��������
    CHAR szSceneSite[TD_MAX_STRING_LENGTH];      // ����λ������
    PU_PTZ_CURRENT_LOCATION_EX_S stPtzLocation;  // ��̨λ����Ϣ
} PU_TD_SCENE_BASE_PARAMS_S;

// ��ͨ���������������
typedef struct PU_TD_SCENE_BASE_PARAMSV2 {
    ULONG ulChannelId;                           // ͨ��ID
    ULONG ulIndex;                               // �������
    BOOL bEnable;                                // ����ʹ��
    PU_TD_SCENE_DIRECTION_E enDirection;         // ��������
    CHAR szSceneName[TD_MAX_STRING_LENGTH];      // ��������
    CHAR szSceneSite[TD_MAX_STRING_LENGTH];      // ����λ������
    PU_PTZ_CURRENT_LOCATION_EX_S stPtzLocation;  // ��̨λ����Ϣ
    BOOL bOSDEnable;                             // ��ƵOSD����ʹ��
    PU_POINT_S stOSDLocation;                    // OSD����λ��
    CHAR szReserve[PU_RESERVE_LEN];              // Ԥ���ֶ�
} PU_TD_SCENE_BASE_PARAMSV2_S;

// ��ͨ�������ʹ����Ϣ
typedef struct PU_TD_SCENE_ENABLE_INFO {
    ULONG ulChannelId;                                         // ͨ��ID
    BOOL abSceneEnable[TD_MAX_SCENE_NUM];                      // ����ʹ��
    CHAR szSceneName[TD_MAX_SCENE_NUM][TD_MAX_STRING_LENGTH];  // ��������
} PU_TD_SCENE_ENABLE_INFO_S;

/*************end:��ͨ���**************/

/*************begin:���Эͬ**************/
typedef enum PU_AI_LEVEL {
    PU_AI_LEVEL_ONLY = 0,
    PU_AI_LEVEL_PU_PU,  // ���Э��
    // PU_AI_LEVEL_CLOUD,    //ȫ������
} PU_AI_LEVEL_E;

// ���Эͬ����
typedef enum PU_MMC_TYPE {
    PU_MMC_FACE_RECOG = 0,
    // MMC_XXX_RECOG, // ��չʹ��
    PU_MMC_MAX,
} PU_MMC_TYPE_E;

// ���Эͬ����
typedef enum PU_AI_NAME {
    PU_PU_AI_SUBS = 0,    // ���Ľӿڣ�������IPC����
    PU_PU_AI_TRANS_DATA,  // ת���ӿ�
} PU_AI_NAME_E;
// ���Эͬ����ת��
typedef struct PU_PU_AI_TRANS_DATA_PARAM {
    VOID *pucData;
    UINT uiLen;  // ���ݵĳ���
} PU_PU_AI_TRANS_DATA_PARAM_S, *LPPU_PU_AI_TRANS_DATA_PARAM_S;

typedef LONG (CALLBACK *pfGetPuPuInfoCallBack)(ULONG ulIdentifyID,
             const PU_PU_AI_TRANS_DATA_PARAM_S *pstTransData, VOID *ctx);
// ���Эͬ���Ĳ���
typedef struct PU_PU_AI_SUBS_PARAM {
    ULONG ulChannelId;
    PU_MMC_TYPE_E enMMCType;       // ���Эͬ����(Ŀǰֻ֧������ʶ��) ����ʶ��=0
    ULONG ulComparisonNumMax;      // �������ȶ�����
    ULONG ulRecallRateWarningMax;  // �ٻ��ʸ澯ֵ
    ULONG ulRecallRateWarningMin;  // �ٻ���Ԥ������ֵ
    ULONG ulCacheDuration;         // �㲥�ĺ��������ڱ�IPC�Ļ���ʱ��(��λ:���ӣ�Ĭ��ֵ��60���ӣ�ȡֵ��Χ10 - 240)
    BOOL bOnOff;                   // �رմ˹���
    pfGetPuPuInfoCallBack puCallBack;
    void *pUsrData;
} PU_PU_AI_SUBS_PARAM_S, *LPPU_PU_AI_SUBS_PARAM_S;

/*************end:���Эͬ**************/

/******************�Ŷӳ����㷨�����ṹ��********************************/
typedef struct PU_ITGT_QUEUEDETECT_ALG_PARAM {
    PU_ENABLE_TYPE_E enEnable;       // �㷨ʹ��
    ULONG ulTimeThreshold;           // �Ŷ�ʱ���澯��ֵ
    ULONG ulAlarmTime;               // �澯�ϱ����
    ULONG ulSensitivity;             // �����ֵ(1-5)
    ULONG ulAverTimePerCapita;       // ���˳�����ƽ��ʱ��
    CHAR szReserve[PU_RESERVE_LEN];  // ����������������Ȳ���
} PU_ITGT_QUEUEDETECT_ALG_PARAM_S;

/******************�Ŷӳ�����Ϣ�ṹ��****************************************/
typedef struct PU_ITGT_QUEUE_DETECT_PARAM {
    ULONG ulChannelId;                            // ͨ��ID
    PU_ITGT_QUEUEDETECT_ALG_PARAM_S stAlgParams;  // �Ŷӳ����㷨����
    PU_IGT_AERADTC_LIST_S stAreaList;             // �Ŷӳ��ȼ������
    PU_ALARM_TIME_LIST_S stGuardPlan;             // �����ƻ�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITGT_QUEUE_DETECT_PARAM_S;

// ��ͨӵ�²����ṹ��
typedef struct PU_VLPR_TRAFFIC_CONGESTION_PARA {
    ULONG ulChannelId;                 // ͨ��ID
    PU_ENABLE_TYPE_E enEnable;         // ʹ��
    ULONG ulAlarmTime;                 // �澯�ϱ����
    PU_ALARM_TIME_LIST_S stGuardPlan;  // �����ƻ�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_VLPR_TRAFFIC_CONGESTION_PARA_S;

/******************��ͨӵ���㷨�����ṹ��********************************/
typedef struct PU_ITGT_TRAFFIC_CONGESTION_ALG_PARAM {
    PU_ENABLE_TYPE_E enEnable;  // �㷨ʹ��
    ULONG ulAlarmTime;          // �澯�ϱ����
} PU_ITGT_TRAFFIC_CONGESTION_PARAM_S;

typedef struct PU_ITS_TRAFFIC_CONGESTION_PARAM {
    ULONG ulChannelId;                               // ͨ��ID
    PU_ITGT_TRAFFIC_CONGESTION_PARAM_S stAlgParams;  // �㷨����
    PU_ALARM_TIME_LIST_S stGuardPlan;                // �����ƻ�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_TRAFFIC_CONGESTION_PARAM_S;

/******************��Ⱥ�ܶ��㷨�����ṹ��********************************/
typedef struct PU_ITGT_CROWD_DENSITY_DETECT_ALG_PARAM {
    PU_ENABLE_TYPE_E enEnable;  // �㷨ʹ��
    ULONG fPeopleNumThreshold;  // ����������ֵ
    ULONG ulAlarmTime;          // �澯�ϱ����
    ULONG ulSensitivity;        // �����ֵ(1-5)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITGT_CROWD_DENSITY_DETECT_ALG_PARAM_S;

/******************��Ⱥ�ܶ���Ϣ�ṹ��****************************************/
typedef struct PU_ITGT_CROWD_DENSITY_DETECT_PARAM {
    ULONG ulChannelId;                                     // ͨ��ID
    PU_ITGT_CROWD_DENSITY_DETECT_ALG_PARAM_S stAlgParams;  // ��Ⱥ�ܶ��㷨����
    PU_IGT_AERADTC_LIST_S stAreaList;                      // ��Ⱥ�ܶȼ������
    PU_ALARM_TIME_LIST_S stGuardPlan;                      // �����ƻ�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITGT_CROWD_DENSITY_DETECT_PARAM_S;

/********** BEGIN: ITS������� **********/
// ������
typedef enum {
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

// ����λ
typedef enum {
    ITS_RS_CSIZE_CS5 = 0,
    ITS_RS_CSIZE_CS6,
    ITS_RS_CSIZE_CS7,
    ITS_RS_CSIZE_CS8,
    ITS_RS_CSIZE_MAX
} PU_ITS_RS_CSIZE_E;

// ֹͣλ
typedef enum {
    ITS_RS_STOPBIT_ONE = 0,
    ITS_RS_STOPBIT_TWO,
    ITS_RS_STOPBIT_MAX
} PU_ITS_RS_STOPBIT_E;

// ��żУ��λ
typedef enum {
    ITS_RS_PARITY_NONE = 0,
    ITS_RS_PARITY_ODD,
    ITS_RS_PARITY_EVEN,
    ITS_RS_PARITY_MARK,
    ITS_RS_PARITY_SPACE,
    ITS_RS_PARITY_MAX
} PU_ITS_RS_PARITY_E;

// ����
typedef enum {
    ITS_RS_FLOWCTL_NONE = 0,
    ITS_RS_FLOWCTL_SW,
    ITS_RS_FLOWCTL_HW,
    ITS_RS_FLOWCTL_MAX
} PU_ITS_RS_FLOWCTL_E;

// ���ڲ����ṹ��
typedef struct
{
    PU_ITS_RS_BAUD_E RS485Baud;
    PU_ITS_RS_CSIZE_E RS485CSize;
    PU_ITS_RS_STOPBIT_E RS485StopBit;
    PU_ITS_RS_PARITY_E RS485Parity;
    PU_ITS_RS_FLOWCTL_E RS485FlowCtl;
} PU_ITS_RS_PARA_S;

// �豸����
typedef enum {
    EP_VIDEO_MODE = 0,  // ��Ƶ�羯
    GT_VIDEO_MODE,      // ��Ƶ����
    ITS_MODE_MAX
} PU_DEVICE_MODE_E;

// ���������
typedef enum {
    ITS_DEVICE_NONE,     // ������
    ITS_DEVICE_RADAR,    // �״�����
    ITS_DEVICE_VEHICLE,  // ��������
    ITS_DEVICE_IO,       // IO����
} PU_ITS_EXTRA_DEVICE_TYPE_E;

// IO������ʽ
typedef enum {
    DEVICE_IO_NONE,  // ������
    DEVICE_IO_RISE,  // �����ش���
    DEVICE_IO_DOWN,  // �½��ش���
    DEVICE_IO_BOTH,  // ������
} PU_DEVICE_IO_TYPE_E;

// ��������������
typedef enum {
    ITS_EQUIP_TYPE_INVALID = 0,

    ITS_EQUIP_RS485_RADAR_CSR_1K,  // �������ٹ�˾��CSR-IK�������״�
    ITS_EQUIP_RS485_RADAR_CSR_IN,  // �������ٹ�˾��CSR-IN�������״�
    ITS_EQUIP_RS485_RADAR_CSR_IM,  // �������ٹ�˾��CSR-IM�೵���״�
    ITS_EQUIP_RS485_RADAR_MPR_LV,  // �Ϻ��۲���˾��MPR-LV�����״�

    ITS_EQUIP_RS485_RADAR_HT_MTTR,  // 802��HT-MTTR�������״�
    ITS_EQUIP_RS485_RADAR_STJ1,     // ɭ˼̩��STJ1�������״�

    ITS_EQUIP_RS485_COIL_TULI_PK600K = 100,  // �Ϻ�ͼ����˾����Ȧ������

    ITS_EQUIP_RS485_LIGHT_DTOR_TL01 = 200,  // ������·����˾�ĺ��̵Ƽ����

    ITS_EQUIP_IO = 300,  // IOЭ��

    ITS_EQUIP_TYPE_MAX
} PU_EXTRA_DEVICE_TYPE_E;

// ���ں�
typedef enum {
    SERIAL_PORT_485_1 = 0,     // 485-1
    SERIAL_PORT_485_2,         // 485-2
    SERIAL_PORT_485_3,         // 485-3
    SERIAL_PORT_485_4,         // 485-4
    ITS_SERIAL_PORT_MAX = 255  // ������
} PU_ITS_SERIAL_PORT_E;

// �״���Ϣ�ķ��ͷ�ʽ
typedef enum {
    ITS_RADAR_MSG_SEND_SINGLE,     // ���η���(�г��������ϱ���Ϣ)
    ITS_RADAR_MSG_SEND_CONTINOUS,  // ��������(�����Ƿ��г������ϱ���Ϣ)
    ITS_RADAR_MSG_SEND_MANUAL,     // �ֹ���ѯģʽ(��ѯһ�Σ���һ����Ϣ)

    ITS_RADAR_MSG_SENDTYPE_MAX
} PU_ITS_RADAR_MSG_SENDTYPE_E;

// �״�����
typedef enum {
    ITS_RADAR_TYPE_SINGLE_DIR_DETECT,  // ����̽��
    ITS_RADAR_TYPE_DOUBLE_DIR_DETECT,  // ˫��̽��

    ITS_RADAR_TYPE_MAX
} PU_ITS_RADAR_WORK_TYPE_E;

// �״��ⷽ��
typedef enum {
    ITS_DETECT_DIR_UNKNOWN = 0,
    ITS_DETECT_DIR_COMING,  // ����
    ITS_DETECT_DIR_GOING,   // ȥ��
    ITS_DETECT_DIR_BOTH,    // ˫��
} PU_ITS_DETECT_DIR_E;

// �״ﴥ��ģʽ
typedef enum {
    ITS_TRIG_MODE_UNKNOWN = 0,
    ITS_TRIG_MODE_COMING = 1,     // ����(��ͷ)����
    ITS_TRIG_MODE_GOING = 2,      // ȥ��(��β)����
    ITS_TRIG_MODE_BOTH = 3,       // ˫�򴥷�
    ITS_TRIG_MODE_CONTINUUM = 4,  // ��������

    ITS_TRIG_MODE_MAX
} PU_ITS_RADAR_TRIG_MODE_E;

/* ��Ȧץ�ķ��� */
typedef enum {
    ITS_COIL_SNAP_SINGLE_NONE = 0,       // ��ץ��
    ITS_COIL_SNAP_SINGLE_IN1,            // ��_��1ץ��
    ITS_COIL_SNAP_SINGLE_OUT1,           // ��_��1ץ��
    ITS_COIL_SNAP_DOUBLE_HEAD_IN2 = 21,  // ˫_��ͷ_��2ץ��
    ITS_COIL_SNAP_DOUBLE_TAIL_OUT1_IN2,  // ˫_��β_��1��2ץ��
    ITS_COIL_SNAP_DOUBLE_TAIL_OUT2,      // ˫_��β_��2ץ��
    ITS_COIL_SNAP_TRIPLE_HEAD_IN3,       // ��_��ͷ_��3ץ��
    ITS_COIL_SNAP_TRIPLE_TAIL_OUT2_IN3,  // ��_��β_��2��3ץ��
    ITS_COIL_SNAP_TRIPLE_TAIL_OUT3,      // ��_��β_��3ץ��

    ITS_COIL_SNAP_DOUBLE_OUT1_OUT2_OUT2DELAY = 41,  // ˫_��1_��2_��2��ʱץ��
    ITS_COIL_SNAP_DOUBLE_IN1_OUT2_OUT2DELAY,        // ˫_��1_��2_��2��ʱץ��
    ITS_COIL_SNAP_DOUBLE_IN2_OUT2_OUT2DELAY,        // ˫_��2_��2_��2��ʱץ��
    ITS_COIL_SNAP_TRIPLE_OUT1_OUT2_OUT3,            // ��_��1_��2_��3ץ��
    ITS_COIL_SNAP_TRIPLE_OUT1_OUT2_OUT3DELAY,       // ��_��1_��2_��3��ʱץ��

    ITS_COIL_SNAP_TYPE_MAX
} PU_ITS_COIL_SNAP_TYPE_E;

// һ������
typedef enum PU_ITGT_MODE {
    COMMON_MODE = 0,                  // ��ͨ�����ģʽ
    FACE_DETECTION_MODE = 1,          // �������ģʽ/C30�˿�ģʽ
    FACE_RECOGNITION_MODE = 2,        // ����ʶ��ģʽ
    BAYONET_MODE = 3,                 // ΢����ģʽ
    MOTOR_DETECTION_MODE = 4,         // ������ģʽ/C30΢��ģʽ
    ITS_MODE = 5,                     // ITSģʽ
    VHD_FACE_MODE = 6,                // һ������(������+ �������)/C30����ģʽ
    BA_MODE = 7,                      // ��Ϊ����ģʽ/C30����
    CLOSE_ALG_MODE = 8,               // һ��N��ȫȥʹ��ģʽ
    ITS_EPOLICE_SINGLE_PIPE = 9,      // ITS�羯��·��ģʽ
    ITS_EPOLICE_DOUBLE_PIPE = 10,     // ITS�羯˫·��ģʽ
    ITS_TGATEWAY_SINGLE_PIPE = 11,    // ITS���ڵ�·��ģʽ
    ITS_TGATEWAY_DOUBLE_PIPE = 12,    // ITS����˫·��ģʽ
    ITS_PEDRUNRED_MODE = 13,          // ITS���˴����ģʽ
    ITS_PASSAGEWAY_SINGLE_PIPE = 14,  // ITS����ڵ�·��ģʽ
    ITS_PASSAGEWAY_DOUBLE_PIPE = 15,  // ITS�����˫·��ģʽ
    ITGT_MODE_MAX,
} PU_ITGE_MODE_E;

typedef struct PU_ITGT_MODE_E {
    PU_ITGE_MODE_E enITGEMode;
    ULONG ulChannelId;  // ͨ��ID
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_ITGT_MODE_S;

// �����״������
typedef struct PU_RADA_PARA_CHUANSU {
    PU_ITS_RADAR_WORK_TYPE_E enRadarWorkType;   // �״﹤������
    PU_ITS_RADAR_MSG_SENDTYPE_E enMsgSendType;  // �״���Ϣ���ͷ�ʽ
    PU_ITS_DETECT_DIR_E enDetectDir;            // ̽�ⷽ��
    ULONG uiFixedAngle;                         // �����Ƕ�, ����״���ٺ�ʵ���ٶȲ�һ�£���Ҫ�����Ƕ�
    ULONG uiSensitivity;                        // �״�������
    ULONG uiTrigMinInterval;                    // ��������С����
    ULONG uiTrigMinSpeed;                       // ��������С�ٶȣ����ٵ������޽����ᴥ��
    ULONG uiHardwareHeight;                     // ��װ�߶�
} PU_RADA_PARA_CHUANSU_S;

// ���ٶ೵���״������
typedef struct PU_ITS_RADA_CTRL_CSRIM {
    PU_ITS_SERIAL_PORT_E enSerialPortId;  // ���ں�
    ULONG uiRoadEnable;                   // �����Ƿ�ʹ��
    ULONG uiLaneId;                       // ��·ID��ʹ��bitmap 0λ��1��ʾ1����ʹ�ܣ��Դ�����
    ULONG uiLaneIdBase;                   // ��ʼ�������
    ULONG uiLaneNum;                      // ��������
    ULONG uiLaneWidth[4];                 // ������ȣ�WEB����ʹ��cm������ת������
    ULONG uiTrigMinInterval;              // ��������С���룬WEB����ʹ��cm������ת������
    ULONG uiInstallHeight;                // ��װ�߶ȣ� WEB����ʹ��cm������ת������
    LONG iInstallHOffset;                 // �״���복�����ĵ��ƫ��, WEB����ʹ��cm������ת������
    // ʹ���״����䷽����ӽǣ������ĵ����ߣ�ƫ��Ϊ����������֮Ϊ������
    LONG iDeflectionAngle;                // �״����䷽��ͳ���֮���ƫת�Ƕ�
    // ���䷽������ƫ�ƣ���ֵΪ����������֮Ϊ������
    ULONG uiSensitivity;                  // �״�������
    ULONG uiSensitiveBase;                // �״������ȵĻ���
    ULONG uiTrigMinSpeed;                 // �������ޣ����ٵ������޽����ᴥ��(km/h)
    ULONG uiTrigMaxSpeed;                 // �������ޣ����ٸ������޽����������ٶȱ���
    PU_ITS_DETECT_DIR_E eDetectDir;       // ̽�ⷽ�����
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_RADA_CTRL_CSRIM_S;

// ��·��TL-01-8���̵��źż����
typedef struct PU_ITS_XLW_DETECTOR_INFO {
    ULONG uiTotalNum;          // �ܹ��м�·�˿�
    ULONG uiLeftLightNo;       // ��ת�ƶ�ӦID
    ULONG uiStraitLightNo;     // ֱ�еƶ�ӦID
    ULONG uiRightLightNo;      // ��ת�ƶ�ӦID
    ULONG uiTurnRoundLightNo;  // ��ͷ�ȵƶ�ӦID
} PU_ITS_XLW_DETECTOR_INFO_S;

// ��Ȧ����������
typedef struct PU_ITS_COIL_DETECTOR_INFO {
    PU_ITS_COIL_SNAP_TYPE_E enSnapType;
    ULONG uiDelayTime;     // ��ʱʱ�䣬0~80ms
    ULONG uiCoilNum;       // ��Ȧ�ĸ��� 1 2 3
    ULONG uiCoilInterval;  // ��Ȧ���ĵļ�� ����
    ULONG uiCoilWidth;     // ��Ȧ�Ŀ��      ����
} PU_ITS_COIL_DETECTOR_INFO_S;

// ��Ȧ����������
typedef struct PU_ITS_IO_DETECTOR_INFO {
    PU_ITS_COIL_SNAP_TYPE_E enSnapType;  // ץ������
    PU_DEVICE_IO_TYPE_E enTrigType;      // GPIO������ʽ
} PU_ITS_IO_DETECTOR_INFO_S;

// ���̵Ƽ������Ϣ
typedef struct PU_LIGHT_DETECTOR_INFO {
    PU_EXTRA_DEVICE_TYPE_E enDeviceProtelType;      // ����Э������
    ULONG uiLightRoadEnable;                        // �������Ƿ�ʹ��
    ULONG uiLightLaneId;                            // ���踲�ǵĳ�����ʹ��bitmap 0λ��1��ʾ1����ʹ�ܣ��Դ�����
    PU_ITS_SERIAL_PORT_E enLightSerialPortId;       // ������ʹ�õĴ��ں�
    PU_ITS_RS_PARA_S stLightDevSerialCfg;           // ��������
    PU_ITS_XLW_DETECTOR_INFO_S stCfgLightDetector;  // ��·��TL-01-8���̵��źż����
    CHAR szReserve[PU_RESERVE_LEN];
} PU_LIGHT_DETECTOR_INFO_S;

// ���������Ϣ
typedef struct PU_VEHICLE_DETECTOR_INFO {
    ULONG uiDetectRoadEnable;                       // �������Ƿ�ʹ��
    ULONG uiDetectLaneId;                           // ���踲�ǵĳ�����ʹ��bitmap 0λ��1��ʾ1����ʹ�ܣ��Դ�����
    PU_ITS_SERIAL_PORT_E enDetecSerialPortId;       // ������ʹ�õĴ��ں�
    PU_ITS_RS_PARA_S stDetectDevSerialCfg;          // ��������
    PU_ITS_COIL_DETECTOR_INFO_S stCfgCoilDetector;  // ��Ȧ������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_VEHICLE_DETECTOR_INFO_S;

// ���������Ϣ
typedef struct PU_IO_DETECTOR_INFO {
    BOOL uiIOEnable;                            // �������Ƿ�ʹ��
    ULONG uiIOLaneId;                           // ���踲�ǵĳ�����ʹ��bitmap 0λ��1��ʾ1����ʹ�ܣ��Դ�����
    PU_ITS_IO_DETECTOR_INFO_S stCfgIODetector;  // ��Ȧ������
    ULONG uiIOPortId;                           // IO�˿ںţ�ITS�豸�澯���������IO��Ȧ���ã�����
    CHAR szReserve[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_IO_DETECTOR_INFO_S;

// �����״�Ŀ�����Ϣ
typedef struct PU_RADAR_CTRL_INFO {
    ULONG uiRoadEnable;                   // �����Ƿ�ʹ��
    ULONG uiLaneId;                       // ��·ID��ʹ��bitmap 0λ��1��ʾ1����ʹ�ܣ��Դ�����
    PU_ITS_SERIAL_PORT_E enSerialPortId;  // ���ں�

    PU_ITS_RS_PARA_S stDevSerialCfg;              // ��������
    PU_RADA_PARA_CHUANSU_S stCfgChuanshu;         // �����״�
    PU_ITS_RADA_CTRL_CSRIM_S stCfgMultiChuanshu;  // ���ٶ೵���״�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_RADAR_CTRL_INFO_S;

// ITS����ĸ�Ҫ��Ϣ
typedef struct PU_ITS_DEV_INFO {
    PU_EXTRA_DEVICE_TYPE_E enDeviceProtelType;         // ����Э������
    PU_RADAR_CTRL_INFO_S stRadarInfo;                  // �״��豸��Ϣ
    PU_VEHICLE_DETECTOR_INFO_S stVehicleDetectorInfo;  // ������Э��
    PU_IO_DETECTOR_INFO_S stIODetectorInfo;            // IOЭ��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_DEV_INFO_S;

// ITS�������
typedef struct PU_ITS_DEV_SPEC {
    ULONG ulChannelId;                                     // ͨ��ID
    PU_DEVICE_MODE_E enDeviceMode;                         // �豸ץ��ģʽ
    ULONG ulTotalRoadNum;                                  // �豸��������
    PU_ITS_EXTRA_DEVICE_TYPE_E enExtraType;                // ��������:0 ������ 1 �״2��������3 IO�����߻���(�·�Э�����Ͳ���,���������ƥ��,���״��豸,Э����ѡ���״��������)
    PU_ITS_DEV_INFO_S stDevSpecInfo[PU_ITS_MAX_ROAD_NUM];  // �������������
    PU_LIGHT_DETECTOR_INFO_S stLightDetectorInfo;          // ���̵Ƽ����,���ͳ�������
    BOOL bInputState;                                      // �澯����ʹ��״̬(��֧��)
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_DEV_SPEC_S;

// �Ϻ�����htmttr�״������
typedef struct PU_ITS_tagRADA_CTRL_HTMTTR_S {
    UINT uiSensitivity;               // �״������ȣ���Χ��50~1000 Ĭ��ֵ��300��
    UINT uiTrigInterval;              // �����ľ��루��Χ��1000~4000           Ĭ��ֵ��2400     ��λ�����ף�
    UINT uiLargeVehiclesEnergyValue;  // ���������ޣ���Χ��1500~6000            Ĭ��ֵ��5000��
    UINT uiLargeVehiclesTrigCnt;      // �󳵹��޴�������Χ��1~5            Ĭ��ֵ��3��
    UINT uiSmallVehiclesEnergyValue;  // С���������ޣ���Χ��300~1500            Ĭ��ֵ��500��
    UINT uiSmallVehiclesTrigCnt;      // С�����޴�������Χ��1~5            Ĭ��ֵ��3��
    UINT uiNonmotorVehicleFilter;     // �ǻ������˳���1���˳��ǻ����� 0�����˳��ǻ�������
    PU_ITS_DETECT_DIR_E enDetectDir;  // ̽�ⷽ����� Ĭ��ֵ������
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_RADA_CTRL_HTMTTR_S;

// ɭ˼̩��STJ01�״������
typedef struct PU_ITS_tagRADA_CTRL_STJ01_S {
    FLOAT fSensitivity;                   // �״������ȣ���Χ��0-1  Ĭ��ֵ��0.4        Խ��Խ��������
    UINT uiTrigInterval;                  // �����ľ��루��Χ��1500~3500            Ĭ��ֵ��2400      ��λ�����ף�
    UINT uiSpeedTrigMax;                  // ��󴥷��ٶȣ���Χ��0~255            Ĭ��ֵ��250 km/h��
    UINT uiSpeedTrigMin;                  // ��С�����ٶȣ���Χ��0~255            Ĭ��ֵ��5 km/h��
    INT iSpeedCorrection;                 // �ٶ���������Χ��-50~50            Ĭ��ֵ��-2��
    PU_ITS_RADAR_TRIG_MODE_E enTrigMode;  // ����ģʽ                          Ĭ��ֵ������(��ͷ)����
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_RADA_CTRL_STJ01_S;

typedef struct PU_RADAR_CTRL_INFO_V2 {
    ULONG uiRoadEnable;                   // �����Ƿ�ʹ��
    ULONG uiLaneId;                       // ��·ID��ʹ��bitmap 0λ��1��ʾ1����ʹ�ܣ��Դ�����
    PU_ITS_SERIAL_PORT_E enSerialPortId;  // ���ں�

    PU_ITS_RS_PARA_S stDevSerialCfg;              // ��������
    PU_RADA_PARA_CHUANSU_S stCfgChuanshu;         // �����״�
    PU_ITS_RADA_CTRL_CSRIM_S stCfgMultiChuanshu;  // ���ٶ೵���״�
    PU_ITS_RADA_CTRL_HTMTTR_S stCfgHtmttr;
    PU_ITS_RADA_CTRL_STJ01_S stCfgStj01;
    CHAR szReserve[PU_RESERVE_EX_LEN];
} PU_RADAR_CTRL_INFO_V2_S;

// ITS����ĸ�Ҫ��Ϣ
typedef struct PU_ITS_DEV_INFO_V2 {
    PU_EXTRA_DEVICE_TYPE_E enDeviceProtelType;         // ����Э������
    PU_RADAR_CTRL_INFO_V2_S stRadarInfo;               // �״��豸��Ϣ
    PU_VEHICLE_DETECTOR_INFO_S stVehicleDetectorInfo;  // ������Э��
    PU_IO_DETECTOR_INFO_S stIODetectorInfo;            // IOЭ��
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_DEV_INFO_V2_S;

// ITS�������
typedef struct PU_ITS_DEV_SPEC_V2 {
    ULONG ulChannelId;                                        // ͨ��ID
    PU_DEVICE_MODE_E enDeviceMode;                            // �豸ץ��ģʽ
    ULONG ulTotalRoadNum;                                     // �豸��������
    PU_ITS_EXTRA_DEVICE_TYPE_E enExtraType;                   // ��������:0 ������ 1 �״2��������3 IO�����߻���(�·�Э�����Ͳ���,���������ƥ��,���״��豸,Э����ѡ���״��������)
    PU_ITS_DEV_INFO_V2_S stDevSpecInfo[PU_ITS_MAX_ROAD_NUM];  // �������������
    PU_LIGHT_DETECTOR_INFO_S stLightDetectorInfo;             // ���̵Ƽ����,���ͳ�������
    BOOL bInputState;                                         // �澯����ʹ��״̬(��֧��)
    UINT uVertion;                                            // ����ӿڰ汾���û����������ֶ�
    CHAR szReserve[PU_RESERVE_LEN];
} PU_ITS_DEV_SPEC_V2_S;

/********** END: ITS������� **********/

// ����SIM������
typedef struct PU_SIM_PHONE_NUM_S {
    CHAR szPhoneNum[DIAL_PHONE_NUM_LEN];
    CHAR szReserve[PU_RESERVE_LEN];
} PU_SIM_PHONE_NUM_S;

// �豸ESN��
typedef struct PU_DEVICE_ESN_INFO {
    CHAR szDeviceESNInfo[PU_ESN_INFO_LEN];
    CHAR szReserved[PU_RESERVE_LEN];
} PU_DEVICE_ESN_INFO_S;

// master slave role enum
typedef enum PU_MASTER_SLAVE_ROLE {
    PU_ROLE_NONE = 0,  // ����ɾ�����ӹ�ϵ
    PU_ROLE_MASTRE,    // ���ӹ����е�����
    PU_ROLE_SLAVE,     // ���ӹ����еĴӻ�
    PU_ROLE_MAX,
} PU_MASTER_SLAVE_ROLE_E;

// �������ӹ�������
typedef struct PU_MASTER_SLAVE_PER_GROUP_PARA {
    PU_MASTER_SLAVE_ROLE_E enRole;     // ���ӽ�ɫ
    ULONG ulGroupID;                   // ���ӹ���ID, ��չԤ������ǰ��ʹ��
    CHAR szMasterIP[PU_IP4_ADDR_LEN];  // ����IP
    CHAR szSlaveIP[PU_IP4_ADDR_LEN];   // �ӻ�IP
    INT iSlavePort;                    // �ӻ��˿ں�
    INT restTransProtocol;             // rest����Э��0:http,1:https,ȱʡʹ��http
    CHAR szReserved[PU_RESERVE_LEN - sizeof(INT)];
} PU_MASTER_SLAVE_PER_GROUP_PARA_S;

// ���ӹ�������
typedef struct PU_MASTER_SLAVE_GROUP_PARA {
    INT iMasterSlaveGroupNum;  // ���������Ŀ
    PU_MASTER_SLAVE_PER_GROUP_PARA_S *stGroupPara;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVE_GROUP_PARA_S;

// ��������û�������
typedef struct PU_MASTER_SLAVE_AUTH_PARA {
    ULONG ulChannelID;                  // ͨ��ID, ��չԤ������ǰ��ʹ��
    CHAR szUserName[PU_USER_NAME_LEN];  // �û���
    CHAR szUserPwd[PU_PASSWORD_LEN];    // ����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVE_AUTH_PARA_S;

// ����ͨ�Ŷ˿�
typedef struct PU_MASTER_SLAVE_COMMUNICATION_PARA {
    ULONG ulGroupID;                // ���ӹ���ID, ��չԤ������ǰ��ʹ��
    PU_MASTER_SLAVE_ROLE_E enRole;  // ���ӽ�ɫ
    INT iPort;                      // ����ͨ�Ŷ˿�
    INT nHttpsPort;                 // ��չhttpsЭ��˿ں�
    CHAR szReserved[PU_RESERVE_LEN - sizeof(INT)];
} PU_MASTER_SLAVE_COMMUNICATION_PARA_S;

// ���Ӹ��ٲ���
typedef enum PU_MASTER_SLAVE_TRACK_MODE {
    PU_MODE_OBJ_DISAPPEAR = 0,  // Ŀ����ʧ������ֱ��Ŀ���뿪ǹ������
    PU_MODE_TIME_FIXED          // �̶�ʱ�䣬����Ŀ��ָ��ʱ�䣬��ʱ����л�Ŀ��
} PU_MASTER_SLAVE_TRACK_MODE_E;

// ����Ŀ��ռ�������
typedef enum PU_TRACK_OBJECT_SIZE {
    PU_OBJECT_SIZE_HALF = 0,   // Ŀ��ռ�������֮һ
    PU_OBJECT_SIZE_ONE_THIRD,  // Ŀ��ռ��������֮һ
    PU_OBJECT_SIZE_QUARTER,    // Ŀ��ռ�����ķ�֮һ
    PU_OBJECT_SIZE_FIFTH,      // Ŀ��ռ�������֮һ
} PU_TRACK_OBJECT_SIZE_E;

// ���Ӹ�������
typedef struct PU_MASTER_SLAVE_TRACK_PARA {
    BOOL bEnable;                         // ���Ӹ����Ƿ�ʹ��
    ULONG ulGroupID;                      ////���ӹ���ID, ��չԤ������ǰ��ʹ��
    PU_MASTER_SLAVE_TRACK_MODE_E enMode;  // ���ٲ���
    PU_TRACK_OBJECT_SIZE_E enObjectSize;  // Ŀ���Сռ�ӻ�����ı���
    INT iTrackTime;                       // ����ʱ��,��λs
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVE_TRACK_PARA_S;

typedef enum PU_LOCATE_TYPE {
    PU_LOCATE_POINT,  // �㶨λ
    PU_LOCATE_RECT,   // ��λ
} PU_LOCATE_TYPE_E;

// ������
typedef enum PU_DRAW_DIR {
    PU_DIR_TOP_LEFT_TO_RIGHT_BOTTOM,  // �����ϵ����»���
    PU_DIR_RIGHT_BOTTOM_TO_TOP_LEFT,  // �����µ����ϻ���
} PU_DRAW_DIR_E;

// ���ӿ�λ����
typedef struct PU_RECT_LOCATE_PARA {
    PU_DRAW_DIR_E enDirection;  // ������
    PU_AREA_INFO_S stRect;      // ����Ϣ				0~8192 ��һ������
} PU_RECT_LOCATE_PARA_S;

// ��ͼ��λ����
typedef struct PU_RECT_LCT_ST_PARA {
    PU_VIM_POINT_ST stStartPoint;  // ����Ϣ, ��ʼ
    PU_VIM_POINT_ST stEndPoint;    // ��ֹ
} PU_RECT_LCT_ST_PARA_S;

// ��ͼ��λ��������
typedef struct PU_RECT_LCT_ST_PARAS {
	PU_DRAW_DIR_E noDirection;           // �����򡪡�ռλ
	PU_RECT_LCT_ST_PARA_S stRc;      // ����Ϣ	
} PU_RECT_LCT_ST_PARAS_S;

// ��ͼ����ͨ��
typedef enum PU_MVPOINT_CHANNEL_INFO {
    PU_INTERNAL_CHANNEL_XT_ID_ALL = 2000,  // �ڲ�����IPC����ͨ��
    PU_INTERNAL_CHANNEL_XT_ID_1,           // �ڲ�IPCͨ��1
    PU_INTERNAL_CHANNEL_XT_ID_2,           // �ڲ�IPCͨ��2
    PU_INTERNAL_CHANNEL_XT_MAX
} PU_MVPOINT_CHANNEL_INFO_E;

// ���ӡ���ͼ��λ����
typedef struct PU_MASTER_SLAVE_LOCATE_PARA {
    ULONG ulGroupID;          // �����Ķ���ͨ��ID(2001��2002), ��ͼ������Ч
    PU_LOCATE_TYPE_E enType;  // ���Ӷ�λ����
    union {
        PU_POINT_S stPointLocate;            // �㶨λ����
        PU_RECT_LOCATE_PARA_S stRectLocate;  // ��λ����������
		PU_RECT_LCT_ST_PARAS_S stRcLocate;     // ��λ����, ��ͼ2
    } config;
} PU_MASTER_SLAVE_LOCATE_PARA_S;

// ���Ӷ�λ����
typedef struct PU_MASTER_SLAVE_LOCATE_CONFIG {
    ULONG ulGroupID;  // ���ӹ���ID, ��չԤ������ǰ��ʹ��
    BOOL bEnable;     // �Ƿ�ʹ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVE_LOCATE_CONFIG_S;

// �궨����
typedef enum PU_CALIBRATION_TYPE {
    PU_CALIBRATION_MANUAL = 0,  // �ֶ�
    PU_CALIBRATION_AUTO,        // �Զ�
    PU_CALIBRATION_MAX
} PU_CALIBRATION_TYPE_E;

typedef struct PU_MANUAL_CALIBRATION_PAIR {
    PU_POINT_S stMaster;                // ǹ���궨������
    PU_PTZ_CURRENT_LOCATION_S stSlave;  // ����궨������
} PU_MANUAL_CALIBRATION_PAIR_S;

typedef struct PU_MANUAL_CALIBRATION_CONFIG {
    INT iPairNum;  // �궨����Ը���
    PU_MANUAL_CALIBRATION_PAIR_S stPair[PU_CALIBRATION_POINT_MAX_NUM];
} PU_MANUAL_CALIBRATION_CONFIG_S;

typedef struct PU_AUTO_CALIBRATION_CONFIG {
    PU_PTZ_CURRENT_LOCATION_S stCenter;                        // �Զ��궨ʱ������ĵ�ptz
    CHAR szMasterScreenPicPath[PU_SNAPSHOT_PICTURE_NAME_LEN];  // ��������ͼ�洢·��
    CHAR szSlaveScreenPicPath[PU_SNAPSHOT_PICTURE_NAME_LEN];   // �ӻ������ͼ�洢·��
} PU_AUTO_CALIBRATION_CONFIG_S;

// ͼƬ�ߴ�
typedef struct PU_PIC_SIZE {
    ULONG ulWidth;   // ͼƬ���
    ULONG ulHeight;  // ͼƬ�߶�
} PU_PIC_SIZE_S;

// �궨�þ�ͷ��Ϣ
typedef struct PU_CALIBRATION_LEN_INFO {
    PU_PIC_SIZE_S stPicSize;      // ������
    PU_PRECISE_FIGURES_S stZoom;  // ��ͷ����
} PU_CALIBRATION_LEN_INFO_S;

// ���ӡ���ͼ�궨���ò���	
typedef struct PU_MASTER_SLAVE_CALIBRATION {
    ULONG ulGroupID;                        // ���ӹ���ID, ��չԤ������ǰ��ʹ�á���ͼ�궨ʹ�ã��ֶ�����2001������1,2002������2
    PU_CALIBRATION_TYPE_E enType;           // �궨����
    PU_CALIBRATION_LEN_INFO_S stMasterLen;  // ����ͷ��Ϣ����ͼ������Ҫ
    PU_CALIBRATION_LEN_INFO_S stSlaveLen;   // �Ӿ�ͷ��Ϣ����ͼ������Ҫ
    union {
        PU_MANUAL_CALIBRATION_CONFIG_S stManual;  // �ֶ��궨����
        PU_AUTO_CALIBRATION_CONFIG_S stAuto;      // �Զ��궨���ã���֧�ִ�����ͼ�Զ��궨����������ӿ�
    } config;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVE_CALIBRATION_S;

// ���ӱ궨״̬
typedef enum PU_CALIBRATION_STATUS {
    CALIBRATION_INIT = 0,  // δ���б궨
    CALIBRATION_COMPLETE,  // �궨�����
    CALIBRATION_ING,       // �궨�����У���ͼ�����Զ��궨ʱ��Ч
    CALIBRATION_MAX
} PU_CALIBRATION_STATUS_E;
// ��ͼ�궨˲��״̬
typedef enum PU_CALIBRATION_INSTANCE_STATUS {
    PU_CALIBRATION_ING = 0,
    PU_CALIBRATION_SUCCESS = 1,  // �궨�ɹ�
    PU_CALIBRATION_FAIL,         // �궨ʧ��
    PU_CALIBRATION_INSTANCE_MAX
} PU_CALIBRATION_INSTANCE_STATUS_E;

// �궨״̬��ѯ����
typedef struct PU_MASTER_SLAVE_CALIBRATION_STATUS {
    ULONG ulGroupID;  // ���ӡ���ͼ�Զ��궨�������0����ͼ�ֶ�������
    PU_CALIBRATION_STATUS_E enStatus;
    // ��ͼ
    UCHAR bGetTaskID;  // TRUE���Զ��궨��ʼǰ����һ�Σ����ڻ�ȡTaskId;��������FALSE
    ULONG ulTaskID;
    PU_CALIBRATION_TYPE_E enType;                     // �궨����
    PU_CALIBRATION_INSTANCE_STATUS enInstanceStatus;  // �궨˲��״̬����ͼʹ��
    CHAR szReserved[PU_RESERVE_LEN - sizeof(UCHAR) - sizeof(ULONG) - sizeof(PU_CALIBRATION_INSTANCE_STATUS) * 2];
} PU_MASTER_SLAVE_CALIBRATION_STATUS_S;

// �ֶ����ٲ���
typedef struct PU_MASTER_SLAVE_MANUAL_TRACK_PARA {
    ULONG ulGroupID;  ////���ӹ���ID, ��չԤ������ǰ��ʹ��
    INT iObjectId;    // �ֶ�����Ŀ��ID
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVE_MANUAL_TRACK_PARA_S;

// �Զ��궨��ֻ����ͼ����ʹ��
typedef struct PU_OMNI_CALIBRATE_SWITCH {
    ULONG ulChannleID;      // ͨ��ID, ��չԤ������ǰ��ʹ��
    BOOL bCancelCalibrate;  // ֪ͨȡ���궨
    CHAR szReserved[PU_RESERVE_LEN];
} PU_OMNI_CALIBRATE_SWITCH_S;
// ��ѯ�궨���ȣ���ͼ����ʹ��
typedef struct PU_OMNI_CALIBRATION_RATE {
    ULONG ulChannleID;  // ͨ��ID, ��չԤ������ǰ��ʹ��
    UINT unOmniRate;    // �궨����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_OMNI_CALIBRATION_RATE_S;

// ץ��ģʽ
typedef enum PU_TRACK_SNAP_TYPE {
    PU_TRACK_SNAP_COMMON = 0,  // Ŀ��ץ��
    PU_TRACK_SNAP_BEH,         // �ܽ�ץ��
} PU_TRACK_SNAP_TYPE_E;

// ץ����Ϣ
typedef struct PU_TRACK_SNAP_TYPE_INFO {
    ULONG ulChannleID;  // ͨ��ID, ��չԤ������ǰ��ʹ��
    PU_TRACK_SNAP_TYPE_E type;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_TRACK_SNAP_TYPE_INFO_S;

// ������Ϣ
typedef struct PU_TRACK_INFO {
    ULONG ulChnID;  // ͨ����
    BOOL bEnable;   // �Ƿ�������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_TRACK_INFO_S;

/********** BEGIN: ���豸���� **********/
// ���豸��������
typedef struct PU_SLAVE_DEVICE_INFO {
    ULONG ulSlaveID;                           // ���豸ID
    BOOL bValid;                               // �Ƿ���Ч��־λ
    CHAR szIPAddress[PU_IP4_ADDR_LEN];         // ���豸IP��ַ
    CHAR szSlaveName[PU_CLIENT_USERNAME_LEN];  // ���豸����,������32�ֽ��ַ�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SLAVE_DEVICE_INFO_S;

// ���豸���������б�
typedef struct PU_SLAVE_DEVICE_LIST {
    PU_SLAVE_DEVICE_INFO_S astSlaveInfo[PU_SLAVE_NUM_MAX];  // ���豸�б�
    ULONG ulSlaveCap;                                       // ���豸������֧�ֵ������豸��
    CHAR szReserved[PU_RESERVE_LEN - sizeof(ULONG)];
} PU_SLAVE_DEVICE_LIST_S;

// ���豸Onvif����
typedef struct PU_SLAVE_ONVIF_PARAM {
    ULONG ulSlaveID;                          // ���豸ID
    BOOL bEnable;                             // ʹ��
    ULONG ulChannelId;                        // ���豸ͨ��id
    ULONG ulOnvifPort;                        // ���豸Onvif�˿�
    CHAR szUserName[PU_CLIENT_USERNAME_LEN];  // ���豸Onvif�û���
    CHAR szPassWord[PU_PASSWORD_LEN];         // ���豸Onvif����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SLAVE_ONVIF_PARAM_S;

// ���豸Rtsp����
typedef struct PU_SLAVE_RTSP_PARAM {
    ULONG ulSlaveID;                          // ���豸ID
    BOOL bEnable;                             // ʹ��
    ULONG ulChannelId;                        // ���豸ͨ��id
    ULONG ulRtspPort;                         // ���豸RTSP�˿�
    CHAR szUserName[PU_CLIENT_USERNAME_LEN];  // ���豸RTSP�û���
    CHAR szPassWord[PU_PASSWORD_LEN];         // ���豸RTSP����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SLAVE_RTSP_PARAM_S;

// ���豸onvif״̬
typedef enum PU_SLAVE_ONVIF_STATUS_TYPE {
    SLAVE_ONVIF_STATUS_NORMAL,                         // ����
    SLAVE_ONVIF_STATUS_USER_ERROR,                     // �û����������
    SLAVE_ONVIF_STATUS_ABNORMAL,                       // �쳣
    SLAVE_ONVIF_STATUS_FRAMERATE_INAPPROPRIATE,        // ֡�ʲ�����
    SLAVE_ONVIF_STATUS_RESOLUTION_INAPPROPRIATE,       // �ֱ��ʲ�����
    SLAVE_ONVIF_STATUS_MEDIA_ENCODING_INAPPROPRIATE,   // ������MEDIAģʽ�ı���ģʽ
    SLAVE_ONVIF_STATUS_MEDIA2_ENCODING_INAPPROPRIATE,  // ������MEDIA2ģʽ�ı���ģʽ
    SLAVE_ONVIF_STATUS_MAX
} PU_SLAVE_ONVIF_STATUS_TYPE_E;

// ���豸onvif״̬
typedef struct PU__SLAVE_ONVIF_STATUS {
    ULONG ulSlaveID;                        // ���豸id��Ψһ��ʶ
    PU_SLAVE_ONVIF_STATUS_TYPE_E enStatus;  // ״ֵ̬
} PU_SLAVE_ONVIF_STATUS_S;

// ���豸rtsp״̬
typedef enum PU_SLAVE_RTSP_STATUS_TYPE {
    SLAVE_RTSP_STATUS_NORMAL,    // ����
    SLAVE_RTSP_STATUS_URL_ERR,   // rtsp url�쳣
    SLAVE_RTSP_STATUS_USER_ERR,  // �û����������
    SLAVE_RTSP_STATUS_ABNORMAL,  // �����쳣
    SLAVE_RTSP_STATUS_MAX
} PU_SLAVE_RTSP_STATUS_TYPE_E;

// ���豸rtsp״̬
typedef struct PU_SLAVE_RTSP_STATUS {
    ULONG ulSlaveID;                       // ���豸id��Ψһ��ʶ
    PU_SLAVE_RTSP_STATUS_TYPE_E enStatus;  // ״ֵ̬
} PU_SLAVE_RTSP_STATUS_S;

/********** END: ���豸���� **********/
// 1��N��������
typedef enum PU_1TN_SUPPORT_MODE {
    TN_COMMON_SUPPORT_MODE = 0,             // ��֧������ģʽ
    TN_FACE_TWO_SUPPORT_MODE = 1,           // ��·����ģʽ
    TN_VHD_TWO_SUPPORT_MODE = 2,            // ��·������ģʽ
    TN_FACE_VHD_SUPPORT_MODE = 3,           // ��·��һ·����һ·������
    TN_FACE_THREE_SUPPORT_MODE = 4,         // ��·����
    TN_VHD_THREE_SUPPORT_MODE = 5,          // ��·������ģʽ
    TN_FACE_VHD_TWO_SUPPORT_MODE = 6,       // ��·��һ·������·������
    TN_FACE_TWO_VHD_SUPPORT_MODE = 7,       // ��·����·����һ·������
    TN_FACE_FIVE_SUPPORT_MODE = 8,          // 5·����+һ·ʶ��
    TN_FACE_TWO_VHD_TWO_SUPPORT_MODE = 9,   // 2������+2����ģʽ
    TN_VHD_FOUR_SUPPORT_MODE = 10,          // 4������ģʽ
    TN_VHDFACE_TWO_SUPPORT_MODE = 11,       // 2·����
    TN_VHDFACE_FACE_TWO_SUPPORT_MODE = 12,  // 1·����, 2·����
    TN_VHDFACE_VHD_TWO_SUPPORT_MODE = 13,   // 1·���ͣ�2·������
    TN_VHDFACE_VHD_FACE_SUPPORT_MODE = 14,  // 1·���ͣ�1·������1·������
    TN_ITGT_SUPPORT_MODE_MAX = 64
} PU_1TN_SUPPORT_MODE_E;

// ����������豸ʹ�ܲ���
typedef struct PU_SLAVE_DEVICE_ENABLE {
    ULONG ulSlaveID;  // ���豸ID
    BOOL bEnable;     // ʹ�ܱ�־λ
} PU_SLAVE_DEVICE_ENABLE_S;

// 1��N����ʹ��
typedef struct PU_1TN_ENABLE {
    BOOL bEnable;  // ʹ��
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_1TN_ENABLE_S;

// 1��N,�ϵķ�ʽ
typedef struct PU_1TN_SUPPORT_MODE_SWITCH {
    ULONG ulChannelId;  // ͨ����
    PU_1TN_SUPPORT_MODE_E enMode;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_1TN_SUPPORT_MODE_SWITCH_S;

// 1��N,�豸֧���ϵ����������б�
typedef struct PU_1TN_SupportModeLIST {
    ULONG ulChannelId;                                               // ͨ����
    ULONG uSupportModeNum;                                           // ����
    PU_1TN_SUPPORT_MODE_E enSpptModelist[TN_ITGT_SUPPORT_MODE_MAX];  // �豸֧�ֵ�������������б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_1TN_SUPPORT_MODE_LIST_S;

// ͨ��״̬
typedef enum PU_CHANNEL_STATUS {
    CHANNEL_STATUS_ERR = 0,  // �쳣
    CHANNEL_STATUS_NORMAL,   // ����
    CHANNEL_STATUS_MAX
} PU_CHANNEL_STATUS_E;

// ����ͨ����Ϣ
typedef struct PU_PRE_CHANNEL_INFO {
    ULONG ulChannelID;                      // ͨ��id
    PU_CHANNEL_STATUS_E enSlaveChanStatus;  // ͨ��״̬
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PRE_CHANNEL_INFO_S;

// ͨ����Ϣ
typedef struct PU_MASTER_SLAVER_CHANNEL_INFO {
    ULONG ulMasterChanCap;                                       // ��ͨ������
    ULONG ulSlaveChanCap;                                        // ��ͨ����������֧�ֵĴ�ͨ�������
    ULONG ulMasterChanNum;                                       // ��ͨ����
    ULONG ulSlaveChanNum;                                        // ��ͨ����
    PU_PRE_CHANNEL_INFO_S astMasterChanInfo[PU_MASTER_NUM_MAX];  // ��ͨ����Ϣ
    PU_PRE_CHANNEL_INFO_S astSlaveChanInfo[PU_SLAVE_NUM_MAX];    // ��ͨ����Ϣ
    CHAR szReserved[PU_RESERVE_LEN];
} PU_MASTER_SLAVER_CHANNEL_INFO_S;

/*****************  �����¼����******************/

// Υ��ͣ�������ṹ��
typedef struct PU_VEHICLEEVENTS_ILLEGALPARKING_PARA {
    ULONG ulChannelId;                 // ͨ��ID
    BOOL enEnable;                     // �㷨ʹ��
    BOOL enSnapEnable;                 // ץ��ʹ��
    ULONG ulParkTimeThr;               // ͣ������ʱ��
    ULONG ulAlarmTime;                 // �澯�ϱ����
    AERADTC_LIST_S stAreaList;         // Υ��ͣ���������
    PU_ALARM_TIME_LIST_S stGuardPlan;  // �����ƻ�
    UINT ulVehicleStopSensitivity;     // ͣ��������
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_VEHICLEEVENTS_ILLEGALPARKING_PARA_S;

// ��ռ�������ṹ��
typedef struct PU_VEHICLEEVENTS_ONVEHICLELANE_PARA {
    ULONG ulChannelId;                 // ͨ��ID
    BOOL enEnable;                     // �㷨ʹ��
    BOOL enSnapEnable;                 // ץ��ʹ��
    UINT unVehicleSensitivity;         // ����������1~100
    UINT unOccupiedTime;               // ռ��ʱ�䵥λ��0~10
    ULONG ulAlarmTime;                 // �澯�ϱ����
    AERADTC_LIST_S stAreaList;         // ��������
    PU_ALARM_TIME_LIST_S stGuardPlan;  // �����ƻ�
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_VEHICLEEVENTS_ONVEHICLELANE_PARA_S;

// ��ռ�ǲ����ṹ��
typedef struct PU_VEHICLEEVENTS_ONBICYCLELANE_PARA {
    ULONG ulChannelId;                 // ͨ��ID
    BOOL enEnable;                     // �㷨ʹ��
    BOOL enSnapEnable;                 // ץ��ʹ��
    UINT unVehicleSensitivity;         // ����������1~100
    UINT unOccupiedTime;               // ռ��ʱ�䵥λ��0~10
    ULONG ulAlarmTime;                 // �澯�ϱ����
    AERADTC_LIST_S stAreaList;         // ��������
    PU_ALARM_TIME_LIST_S stGuardPlan;  // �����ƻ�
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_VEHICLEEVENTS_ONBICYCLELANE_PARA_S;

// ���е��������ṹ��
typedef struct PU_VEHICLEEVENTS_WRONGDIRECTION_PARA {
    ULONG ulChannelId;                 // ͨ��ID
    BOOL enEnable;                     // �㷨ʹ��
    BOOL enSnapEnable;                 // ץ��ʹ��
    UINT ulSensitivity;                // �����ҵ�񣬸���Υ���жϣ����ڵ���Υ�´����������ȵ������˴���Ҫ��Գ������µ���Ϊ��⣬�������
    ULONG ulAlarmTime;                 // �澯�ϱ����
    AERADTC_LIST_S stAreaList;         // ��������
    PU_ALARM_TIME_LIST_S stGuardPlan;  // �����ƻ�
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_VEHICLEEVENTS_WRONGDIRECTION_PARA_S;

// ѹ�߲����ṹ��
typedef struct PU_VEHICLEEVENTS_COVERLINE_PARA {
    ULONG ulChannelId;                 // ͨ��ID
    BOOL enEnable;                     // �㷨ʹ��
    BOOL enSnapEnable;                 // ץ��ʹ��
    UINT unVehicleSensitivity;         // ����������1~100
    ULONG ulAlarmTime;                 // �澯�ϱ����
    AERADTC_LIST_S stAreaList;         // ��������
    PU_ALARM_TIME_LIST_S stGuardPlan;  // �����ƻ�
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_VEHICLEEVENTS_COVERLINE_PARA_S;

// �쳣���Ʋ����ṹ��
typedef struct PU_VEHICLEEVENTS_ABNORMALPLATE_PARA {
    ULONG ulChannelId;  // ͨ��ID
    BOOL enEnable;      // �㷨ʹ��
    BOOL enSnapEnable;  // ץ��ʹ��
    // PU_PLATE_TYPE_E                enPlateType;                // ��������
    ULONG ulAlarmTime;                 // �澯�ϱ����
    PU_ALARM_TIME_LIST_S stGuardPlan;  // �����ƻ�
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_VEHICLEEVENTS_ABNORMALPLATE_PARA_S;

/**********begin:΢����/�����˲����ٴ��޸�*****************/

// �������Բ���
typedef struct PU_LANE_ATTR_PARA {
    PU_ITS_ROAD_PURPOSE_E enLanePurpose;   // ��������/��;
    PU_ITS_CAR_DRV_DIR_E enLaneDirection;  // ��������
} PU_LANE_ATTR_PARA_S;

// ��������ö��ֵ
typedef enum PU_CAMPUS_TRIG_TYPE {
    PU_CAMPUS_TRIG_MODE_GROUND = 0,  // �ظ���Ȧ����
    PU_CAMPUS_TRIG_MODE_DT_LINE,     // ��Ƶ���ߴ���
    PU_CAMPUS_TRIG_MODE_HYBRID,      // ��ϴ���ģʽ(��Ȧ�������ȣ����ߴ���Ϊ��)

    PU_CAMPUS_TRIG_MODE_MAX
} PU_CAMPUS_TRIG_TYPE_E;

// ԰������ڲ�������
typedef struct PU_CAMPUS_MODE_PARA {
    BOOL bEnable;                      // ԰�������ҵ����ʹ�ܿ���
    PU_CAMPUS_TRIG_TYPE_E enTrigType;  // ��������                         // ��������:0-��Ȧ����  1-��Ƶ���ߴ���   2-���ģʽ����
    BOOL bEnableNoPlateVeh;            // �Ƿ��ϱ����Ƴ�
    BOOL bEnableDataAck;               // �������ݻش�
} PU_CAMPUS_MODE_PARA_S;

// ����ȫ�ֲ����������䳵������
typedef struct PU_VLPR_PARA_V3 {
    ULONG ulChnID;                           // ͨ��ID
    BOOL bEnable;                            // �Ƿ�ʹ��
    LONG iLaneNum;                           // ��������
    PU_IMRS_LINE_S stLane[MAX_AREA_VERTEX];  // ������ = ������+1����������������

    PU_VEHICLE_DIR_E enVehicleDir;     // ��������Ĭ�ϳ�ͷ
    PU_VLPR_CATCH_MODE_E enCatchMode;  // ץ������ 0:������ 1:������
    PU_VLP_PARA_S stVLPParam;          // ���Ʋ���
    BOOL bVColorDetection;             // ������ɫ�������
    BOOL bVTypeDetection;              // �������ͼ������
    BOOL bSendPanoramaPic;             // �Ƿ���ȫ��ͼ
    BOOL bSendPlatePic;                // �Ƿ��ͳ���Сͼ
    PU_VLPR_ALG_MODE_E enAlgMode;      // �����㷨����

    BOOL bExposureEnable;   // �����ع�ʹ��
    ULONG ulROIMeterLevel;  // �����ع�ϵ��
    BOOL bVlprEnhancement;
    PU_LANE_ATTR_PARA_S stLaneAttr[MAX_LANE_NUM];  // ��������
    AERADTC_LIST_S stAreaList;                     // ROI�������
    PU_IMRS_LINE_S stDetectLine[MAX_AREA_VERTEX];  // �����
    BOOL bEnableVehicleMfrType;                    // �Ƿ����ö�������
    BOOL bEnableFacePic;                           // �Ƿ�����������ͼ
    PU_CAMPUS_MODE_PARA_S stCampusModePara;

    ULONG ulPlateExposureTime;  // �������ȳ�������ʱ��
    BOOL enEnhanceMeter;        // ������ǿ����  ����ΪFALSEʱ����ON������ΪTRUEʱ����OFF
    UINT ulEnhanceLevel;        // ������ǿǿ�� 1~100
    CHAR szReserved[PU_RESERVE_EX_LEN - (sizeof(BOOL) * 3) - sizeof(PU_CAMPUS_MODE_PARA_S) - sizeof(ULONG) - sizeof(UINT)];
} PU_VLPR_PARA_V3_S;

// �����˲�������
typedef struct PU_VHD_PARA_EX {
    ULONG ulChannelId;                            // ͨ��ID
    BOOL bEnable;                                 // �Ƿ�ʹ��
    BOOL bSendSnapPicture;                        // �ϴ�Ŀ��Сͼ
    BOOL bSendPanorama;                           // �ϴ�ȫ��
    BOOL bLaneLineEnable;                         // �������Ƿ�ʹ��
    PU_VLPR_ALG_MODE_E enAlgMode;                 // ץ���㷨����
    INT iWidth;                                   // ����ͼ����
    INT iHeight;                                  // ����ͼ��߶�
    INT iLaneNum;                                 // ��������
    PU_IMRS_LINE_S stLane[MAX_AREA_VERTEX];       // ������ = ������+1
    CHAR szPlateLocalZH[MAX_PLATE_LOCAL_ZH_LEN];  // ���ȳ������ͣ����6��������6��ȡ6�����硰�����㡱

    BOOL bExposureEnable;  // �ع�ʹ��
    CHAR ulROIMeterLevel;  // �ع�ϵ��

    PU_LANE_ATTR_PARA_S stLaneAttr[MAX_LANE_NUM];  // ��������
    AERADTC_LIST_S stAreaList;                     // ROI�������

    ULONG ulPlateExposureTime;  // �������ȳ�������ʱ��
    BOOL enEnhanceMeter;        // ������ǿ����  ����ΪFALSEʱ����ON������ΪTRUEʱ����OFF
    UINT ulEnhanceLevel;        // ������ǿǿ�� 1~100
    UCHAR sdkVersion;           // ��ʶ�Ƿ�ʹ��IVS_PU_SetVHDParaEx�ӿ�(SDK�ڲ�ʹ�ã�����������)
    CHAR szReserved[PU_RESERVE_EX_LEN - sizeof(ULONG) - sizeof(BOOL) - sizeof(UINT) - sizeof(UCHAR)];
} PU_VHD_PARA_EX_S, *LPPU_VHD_PARA_EX_S;

/**********end:΢����/�����˲����ٴ��޸�*****************/

/* β������������ʽ */
typedef enum PU_ITS_RESTRICTED_INDEX_TYPE {
    RESTRICTE_INDEX_BY_WEEK,  // ����������
    RESTRICTE_INDEX_BY_DATE,  // ����������
    RESTRICTE_INDEX_MAX
} PU_ITS_RESTRICTED_INDEX_TYPE_E;

/* β�����еı��س��� */
typedef struct PU_ITS_RESTRICTED_REGION {
    char aucLocalPlate[MAX_RESTRICTED_LOCALPLATE_LEN];  // ���س���-ʡ,����A����C...
} PU_ITS_RESTRICTED_REGION_S;

/* β�����е�ʱ��� */
typedef struct PU_ITS_RESTRICTED_DATA {
    PU_ITS_RESTRICTED_INDEX_TYPE_E enIndexType;   // ������ʽ������β�Ż�������
    BOOL abRestrictedU[MAX_RESTRICTED_DATE_NUM];  // ʹ��, ������ 7 ��, ������10��
    ULONG ulStartTime;                            // β��������ʼʱ��
    ULONG ulEndTime;                              // β�����н���ʱ��
} PU_ITS_RESTRICTED_DATA_S;

/* β������һ��Լ����Ľṹ�� */
typedef struct PU_ITS_RESTRICTED_PARA_UNIT {
    BOOL abRestrictedNum[MAX_RESTRICTED_NUM];                                 /* ���Ƶ�β�ţ�֧��0~9һ��10�� */
    PU_ITS_RESTRICTED_DATA_S stRestrictedDate;                                // ���Ƶ����ں�ʱ���
    PU_ITS_RESTRICTED_REGION_S astLocalPlate[MAX_RESTRICTED_LOCALPLATE_NUM];  // ���س���
    BOOL abLocalRestrictedNum[MAX_RESTRICTED_NUM];                            // �������Ƶ�β�ţ�֧��0~9һ��10��
    BOOL abNonLocalRestrictedNum[MAX_RESTRICTED_NUM];                         // ������Ƶ�β�ţ�֧��0~9һ��10��

} PU_ITS_RESTRICTED_PARA_UNIT_S;

/* β��������Լ����ṹ�� */
typedef struct PU_ITS_RESTRICTED_PARA {
    ULONG ulChannelId;                                                       // ͨ��ID
    INT iRestrictedNum;                                                      // ���õ�β����������
    PU_ITS_RESTRICTED_PARA_UNIT_S astRestricteds[MAX_RESTRICTED_EVENT_NUM];  // β������������
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_ITS_RESTRICTED_PARAM_S;
/*********end:β������*********/

// ������ͳ��
typedef struct PU_VLPR_TRAFFIC_STATISTICS {
    ULONG ulChannelId;                   // ͨ��ID
    BOOL bEnable;                        // �Ƿ�ʹ��
    ULONG ulInterval;                    // ͳ�Ƽ��
    ULONG uDistanceToCrossing;           // �������·�ھ���
    ULONG uDetectAreaLength;             // ������򳤶�
    ULONG uCongestionLaneThreshold;      // ӵ�³�������ֵ����ӵ�³��������ڵ��ڴ���ֵʱ���ж���·ӵ��
    FLOAT fCongestThreholdForUnblocked;  // ӵ����ֵ----��ͨ
    FLOAT fCongestThreholdForAmble;      // ӵ����ֵ------����
    FLOAT fCongestThreholdForCongest;    // ӵ����ֵ------ӵ��
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_VLPR_TRAFFIC_STATISTICS_S;

// �ȶ�ͼ�������
typedef struct PU_HOTMAP_AERADTC_LIST {
    ULONG ulAreaNum;
    PU_IGT_AREA_S stArea[PU_HOTMAP_AREA_NUM];
} PU_HOTMAP_AERADTC_LIST_S;

// �ȶ�ͼ����
typedef struct PU_HOTMAP_PARA {
    ULONG ulChannelId;                    // ͨ��ID
    PU_ENABLE_TYPE_E enEnable;            // �㷨ʹ��
    PU_ENABLE_TYPE_E enSendMeta;          // ����Ԫ���ݣ�Ĭ�Ͽ���
    PU_PTZ_CURRENT_LOCATION_S stPtzPara;  // PTZλ��
    PU_HOTMAP_AERADTC_LIST_S stAreaList;  // �ȶ�ͼ�������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_HOTMAP_PARA_S;

// �ȶ�ͼ��ѯ����
typedef enum PU_HOTMAP_TYPE {
    TYPE_HOTMAP_SPACE,  // �ռ�ά���ȶ�ͼ
    TYPE_HOTMAP_TIME    // ʱ��ά���ȶ�ͼ
} PU_HOTMAP_TYPE_E;

// �ȶ�ͼ�Ҷ�ͼ����
typedef struct PU_HOTMAP_TABLE_SPACE {
    USHORT usWidth;   // �Ҷ�ͼ��
    USHORT usHeight;  // �Ҷ�ͼ��
} PU_HOTMAP_TABLE_SPACE_S;

// �ȶ�ͼʱ�䱨��
typedef struct PU_HOTMAP_TABLE_TIME {
    USHORT usHotMapRecordNum;  // ���ݳ���
    union {
        USHORT ausHotMapTableYear[PU_MONTH_NUM_PER_YEAR];  // �걨���ؽ��
        USHORT ausHotMapTableMonth[PU_DAY_NUM_PER_MONTH];  // �±����ؽ��
        USHORT ausHotMapTableWeek[PU_DAY_NUM_PER_WEEK];    // �ܱ����ؽ��
        USHORT ausHotMapTableDay[PU_HOUR_NUM_PER_DAY];     // �ձ����ؽ��
    } map;
} PU_HOTMAP_TABLE_TIME_S;

// �ȶ�ͼ��ѯ����
typedef struct PU_HOTMAP_TABLE_PARA {
    ULONG ulChannelId;                       // ͨ��ID
    PU_HOTMAP_TYPE_E enHotmapType;           // ��ѯ����
    PU_TABLE_TYPE_E enTableType;             // ��������
    PU_TIME_S stBeginTime;                   // ��ʼʱ��,����ʱ��
    CHAR szPath[PU_SAVE_FILE_PATH_MAX + 1];  // �����ļ��洢·���������߶��� ��
    // �ռ��ȶ�ͼΪ�Ҷ�ͼ��ʱ���ȶ�ͼΪCSV��ʽ�ļ�
    union {
        PU_HOTMAP_TABLE_SPACE_S stHotMapSapceTable;  // ��Ӧ��ѯ����ΪTYPE_HOTMAP_SPACE
        PU_HOTMAP_TABLE_TIME_S stHotMapTimeTable;    // ��Ӧ��ѯ����ΪTYPE_HOTMAP_TIME
    } hotMapTable;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_HOTMAP_TABLE_PARA_S;

// ÿ�ղ����ƻ��ƻ�
typedef struct PU_TIME_PLAN_PER_DAY {
    ULONG ulStartTime;  // ��ʼʱ��,��0���ʱ��,��λ:��
    ULONG ulEndTime;    // ����ʱ��,��0���ʱ��,��λ:��
} PU_TIME_PLAN_PER_DAY_S;

// �ȶ�ͼ�����ƻ�ʱ��
typedef struct PU_HOTMAP_TIME_PLAN {
    ULONG ulGuardNum;                                                     // �����ƻ��������PU_GUARD_PLAN_NUM_PER_DAY
    PU_TIME_PLAN_PER_DAY_S astTimePalnPerDay[PU_GUARD_PLAN_NUM_PER_DAY];  // ÿ�첼���ƻ�ʱ���
} PU_HOTMAP_TIME_PLAN_S;

// �ȶ�ͼ�����ƻ�����
typedef struct GUARD_PLAN_PARA {
    ULONG ulChannelId;                                       // ͨ��ID��Ԥ��
    PU_HOTMAP_TIME_PLAN_S astGuadTime[PU_DAY_NUM_PER_WEEK];  // һ�ܲ����ƻ�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_HOTMAP_GUARD_PLAN_PARA_S;

// 3559����ʶ��Ԫ���ݷ����������ýṹ��
typedef struct PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA {
    ULONG ulChannelId;                   // ͨ��ID
    PU_ENABLE_TYPE_E enAnonymousEnable;  // Ԫ���ݷ�������ʹ�ܿ���
    ULONG ulAlarmTime;                   // �澯�ϱ����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S;

typedef struct PU_DEVICES_SUPPORT_HISTORY {
    ULONG ulChannelId;            // ͨ����
    BOOL bSupportHistoryAbility;  // �Ƿ�֧����ʷ��¼
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_DEVICES_SUPPORT_HISTORY_S;

typedef struct PU_SUPPORT_ITGT_TYPE {
    ULONG usupportItgtTypeNum;       // ����
    PU_ITGE_MODE_E supportItgtType;  // ��������
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_SUPPORT_ITGT_TYPE_S;

typedef struct PU_SUPPORT_ITGT_TYPE_LIST {
    ULONG supportItgtTypelistNum;                               // ����
    PU_SUPPORT_ITGT_TYPE_S supportItgtTypelist[ITGT_MODE_MAX];  // �����Կ����������ͼ�����
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_SUPPORT_ITGT_TYPE_LIST_S;

typedef enum PU_DATA_BASE_TYPE {
    PU_COMMON_DATA_BASE = 0,             // ��ͨ
    PU_FACE_DETECTION_DATA_BASE,         // �������
    PU_BODY_DETECTION_DATA_BASE,         // ����
    PU_FACE_RECOGNITION_DATA_BASE,       // ����ʶ��
    PU_FACE_SUP_RECOGNITION_DATA_BASE,   // ����ʶ��
    PU_BODY_FACE_DATA_BASE,              // ����+����
    PU_BODY_FACE_RECOGNITION_DATA_BASE,  // ����+����+ʶ��
    PU_VEH_DATA_BASE,                    // ����
    PU_RIDER_DATA_BASE,                  // ������
    PU_DATA_BASE_MAX,
} PU_DATA_BASE_TYPE_E;

typedef struct PU_HISTORY_SUPPORT_QDB_LIST {
    ULONG uHistorySupportQDBNum;                           // ����
    PU_DATA_BASE_TYPE_E supportQDBlist[PU_DATA_BASE_MAX];  // �豸֧�ֵĲ�ѯ������
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_HISTORY_SUPPORT_QDB_LIST_S;

/* ͼ���㷨���� */
typedef enum PU_IPS_ALGORITHM_TYPE {
    ISP_ALG_TYPE_ADPAT = 0,  // ��������Ӧ�㷨
    ISP_ALG_TYPE_MAX_EX
} PU_IPS_ALGORITHM_TYPE_E;

/* �㷨�汾��Ϣ */
typedef struct PU_ALG_INFO {
    PU_IPS_ALGORITHM_TYPE_E enAlgType;           // �㷨����
    CHAR szAlgVer[PU_ITGT_ALTHM_VERSION_LEN];    // �㷨�汾
    CHAR szAlgOwner[PU_ITGT_ALTHM_VERSION_LEN];  // �㷨����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ALG_INFO_S;

/********* ͼ���㷨��Ϣ*********/
typedef struct PU_ISP_ALG_INFO {
    ULONG ulChannelId;                              // Ԥ��ͨ��ID
    PU_ALG_INFO_S szAlgInfos[PU_ISP_TYPE_MAX_NUM];  // �㷨�汾��Ϣ��Ϊ�Ժ����俼�ǣ�Ԥ��64���㷨��Ŀǰֻ�г�������Ӧһ���㷨
    CHAR szReserved[PU_RESERVE_LEN];
} PU_ISP_ALG_INFO_S;

/********* �����˶�������*********/
typedef enum PU_ITGT_VHD_OBJ_TYPE {
    PU_OBJ_VEH,  // Vehicle
    PU_OBJ_PED,  // Pedestrian
    PU_OBJ_NMV   // Non-Motorized Vehicle
} PU_ITGT_VHD_OBJ_TYPE_E;

/********* �������Զ��������ȼ�*********/
typedef struct PU_ITGT_VHD_OBJECT_ITEM {
    PU_ITGT_VHD_OBJ_TYPE_E objType;  // Ŀ������
    BOOL enable;                     // ʹ��
    ULONG priority;                  // ���ȼ�
} PU_ITGT_VHD_OBJECT_ITEM_S;

/********* �������Զ�����*********/
typedef struct PU_ITGT_VHD_AUTO_TRACK_PARA {
    ULONG ulChannelID;                                                          // ͨ��ID
    BOOL bEnable;                                                               // �㷨ʹ��
    ULONG ulSensitivity;                                                        // �㷨���������
    ULONG ulAlarmTime;                                                          // �澯�ϱ����
    ULONG ulMaxTraceTime;                                                       // ������ʱ��
    AERADTC_LIST_S stAreaList;                                                  // ��������
    PU_ALARM_TIME_LIST_S stAlarmTimeList;                                       // �����ƻ�
    PU_ITGT_VHD_OBJECT_ITEM_S objItem[PU_ITGT_AUTOTRACKING_PRIORITY_ITEM_NUM];  // �Զ��������ȼ�
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_ITGT_VHD_AUTO_TRACK_PARA_S;

/********* �������ֶ�����*********/
typedef struct PU_ITGT_VHD_MANUAL_TRACK_PARA {
    ULONG ulChannelID;  // Ԥ��ͨ��ID
    ULONG ulTargetID;   // ���ٶ���ID
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_ITGT_VHD_MANUAL_TRACK_PARA_S;

/********* �۽�ģʽ*********/
typedef struct PU_PTZ_FOCUS_MODE {
    ULONG ulPtzId;                // ��̨���
    PU_FOCUS_MODE_E enFocusMode;  // �۽�ģʽ
    ULONG ulFocusSensitivity;     // �۽�������(�����Զ��۽�ģʽ��Ч)����Χ0~2
    CHAR szReserved[PU_RESERVE_EX_LEN];
} PU_PTZ_FOCUS_MODE_S;

/*****************************��Կ�Զ�����***********************************/
typedef struct PU_AESKEY_AUTO_UPDATE_PARA
{
	PU_ENABLE_TYPE_E enAutoUpdateEnable;	//�Զ�����ʹ�ܣ�0���رգ�1������
	ULONG uAutoUpdateCycle;			//�Զ��������ڣ���λ���죬��Χ30-360
	ULONG ulLastUpdatetime;			//�ϴθ���ʱ�䣬setʱ���踳ֵ
}PU_AESKEY_AUTO_UPDATE_PARA_S;

#ifdef _WIN32
typedef enum PLAYER_COLOR {
    PLAYER_COLOR_GREEN = 0,   // ��ɫ
    PLAYER_COLOR_PURPLE = 1,  // ��ɫ
    PLAYER_COLOR_RED = 2,     // ��ɫ
    PLAYER_COLOR_YELLOW = 3,  // ��ɫ
    PLAYER_COLOR_WHITE = 4,   // ��ɫ
    PLAYER_COLOR_BLACK = 5,   // ��ɫ
    PLAYER_COLOR_MAX,
} PLAYER_COLOR_E;

typedef struct PLAYER_POINT {
    double x;
    double y;
} PLAYER_POINT_S;

typedef struct PU_CROSS_INFO {
    PLAYER_POINT_S stCenter;      // ʮ�����ĵ�
    ULONG ulGraphID;              // ������
    ULONG ulFrom;                 // �������Ի棬������web���룬����Ϊ0
    PLAYER_COLOR_E enCrossColor;  // ͼ����ɫ
} PU_CROSS_INFO_S;

typedef struct PU_GRAPH_INFO {
    double dPointX;
    double dPointY;
    ULONG ulWidth;  // 3d��λʱ�˴�Ϊ�ڶ����������
    ULONG ulHeight;
    ULONG ulType;  // ����RT_NORMAL  = 0, RT_PRIVACY = 1, RT_ROI = 2
    ULONG ulGraphID;
    LONG lROIQuality;
    ULONG ulFrom;
    ULONG ulRectangleType;
} PU_GRAPH_INFO_S;

typedef enum PU_CURSOR_SHAPE {
    PU_CURSOR_TOPDOWN = 0,    // �����״Ϊ������
    PU_CURSOR_LEFTRIGHT = 1,  // �����״Ϊ������
    PU_CURSOR_NWSE = 2,       // �����״Ϊ���ϻ���������
    PU_CURSOR_NESW = 3,       // �����״Ϊ���ϻ��߶�����
    PU_CURSOR_HAND = 4,       // �����״Ϊ����
    PU_CURSOR_ARROW = 5,
    PU_CURSOR_START_BIG = 6,
    PU_CURSOR_END_BIG = 7,
} PU_CURSOR_SHAPE_E;

#endif

// ͸���ӿ���������ṹ��
typedef struct PU_CONFIG_JSON_INPUT {
    VOID *pRequestUrl;                   // ��������ַ�����ʽ
    ULONG ulRequestUrlLen;               // ��������ȣ��ַ�������
    VOID *pInBuffer;                     // ���������������JSON��ʽ
    ULONG ulInBufferSize;                // ���������������С
    ULONG ulRecvTimeOut;                 // ���ճ�ʱʱ�䣬��λ��ms����0��ʹ��Ĭ�ϳ�ʱ5s
    CHAR szReserved[PU_RESERVE_EX_LEN];  // ��������Ϊ0
} PU_CONFIG_JSON_INPUT_ST, *LPPU_CONFIG_JSON_INPUT_ST;

// ͸���ӿ���������ṹ��
typedef struct PU_CONFIG_JSON_OUTPUT {
    VOID *pOutBuffer;                    // ���������������JSON��ʽ��ע�⣺Ӧ�ò���Ҫ�����㹻���ڴ�,����û������ڴ治����ӿڷ��ض�Ӧ�����롣
    ULONG ulInputBufferSize;             // �û����� ���������������С(�ڴ��С)
    ULONG ulRealBufferSize;              // ʵ�����������������С
    CHAR szReserved[PU_RESERVE_EX_LEN];  // ��������Ϊ0
} PU_CONFIG_JSON_OUTPUT_ST, *LPPU_CONFIG_JSON_CONFIG_OUTPUT_ST;

// ��������������ṹ��
typedef struct PU_UPGARDE_JSON_INPUT {
    CHAR *pInBuffer;                     // ���������������JSON��ʽ���������ݸ����ڴ�
    ULONG ulInBufferSize;                // ���������������С
    ULONG ulRealBufferSize;              // ʵ�ʷ����ַ�������
    CHAR szReserved[PU_RESERVE_EX_LEN];  // ��������Ϊ0
} PU_UPGARDE_JSON_INPUT_ST, *LPPU_UPGARDE_JSON_INPUT_ST;

// RSA����֧�ֽṹ��
typedef struct PU_RSA_ABILITY {
    ULONG ulChannelId;                   // ͨ����
    BOOL isSupport;                      // �汾�Ƿ�֧���°淽ʽ���ܣ�����ֵ
    CHAR szReserved[PU_RESERVE_EX_LEN];  // ��������Ϊ0
} PU_RSA_ABILITY_S, *LPPU_RSA_ABILITY_S;

typedef enum PU_OPR_METHOD
{
    PU_OPR_METHOD_GET = 0, // Get����
    PU_OPR_METHOD_SET = 1, // Set����
    PU_OPR_METHOD_MAX,
}PU_OPR_METHOD_E;

// TLS1.1����
typedef struct PU_TLS_SWITCH{
    ULONG ulChannelId;                // ͨ����
    BOOL enable;                      // ����ʹ��
    PU_OPR_METHOD_E enMethod;         // ��������
    CHAR szReserved[PU_RESERVE_LEN];  // ����
} PU_TLS_SWITCH_S, *LPPU_TLS_SWITCH_S;

// ***************************************************************************************************************************************************************
#pragma pack(pop)

/*******************************************************************************************************************/
/* SDK Function Declaration */
/*******************************************************************************************************************/

/******************************************************************************************************/
/* Common Use Function */
/******************************************************************************************************/

// initialize sdk resources
_HW_PU_API BOOL __stdcall IVS_PU_Init(ULONG ulLinkMode, CHAR *szLocalIP, ULONG ulLocalPort);
_HW_PU_API BOOL __stdcall IVS_PU_InitEx(ULONG ulLinkMode, CHAR *szLocalIP, ULONG ulLocalPort, ULONG ulLocalTlsPort,
                                        PU_CERT_FILE_PATH_PARA_S *pstCertFilePath);

// д��־�ص�ע��
typedef LONG (CALLBACK *pfWriteLogCallBack)(PU_SDK_LOG_LEVEL_E enLogLevel, const CHAR *pFile, ULONG ulLine,
             CHAR *pcLogString);
_HW_PU_API BOOL __stdcall IVS_PU_WriteLogCallBack(pfWriteLogCallBack pfLogCallBack);

_HW_PU_API BOOL __stdcall IVS_PU_MutualAuth(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

// set local ip for login
_HW_PU_API BOOL __stdcall IVS_PU_SetValidLocalIp(CHAR *szLocalIP);

// set  for reconnect
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoReconnect(BOOL bEnable);

// login to device
_HW_PU_API ULONG __stdcall IVS_PU_Login(CHAR *szLoginIP, ULONG ulLoginPort, CHAR *szUserName, CHAR *szPasswd);

// login to device
_HW_PU_API BOOL __stdcall IVS_PU_LoginByID(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

// logout from device
_HW_PU_API BOOL __stdcall IVS_PU_Logout(ULONG ulIdentifyID);

// ��������ע�����
_HW_PU_API BOOL __stdcall IVS_PU_StartAcceptRegister(CHAR *szLocalIP, ULONG ulLocalPort, ULONG ulLocalTlsPort);
// �ر�����ע�����
_HW_PU_API BOOL __stdcall IVS_PU_StopAcceptRegister();

// sdk event callback function type
typedef LONG (CALLBACK *pfGetEventInfoCallBack)(VOID *arg);

// register sdk event callback
_HW_PU_API BOOL __stdcall IVS_PU_EventStatesCallBack(pfGetEventInfoCallBack fEventResportCallBack);

// release sdk resources
_HW_PU_API BOOL __stdcall IVS_PU_Cleanup();

// get device version info
_HW_PU_API BOOL __stdcall IVS_PU_GetVersion(ULONG *pulVersion);

// get sdk last error
_HW_PU_API ULONG __stdcall IVS_PU_GetLastError();

// get sdk last login lock time
_HW_PU_API BOOL __stdcall IVS_PU_GetLastLoginLockTime(ULONG *pulLockTime);

// get error message by error number
_HW_PU_API CONST CHAR *__stdcall IVS_PU_GetErrorMsg(ULONG ulErrorNo);

// get device log info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceLogInfo(ULONG ulIdentifyID, PU_LOG_TYPE_E enLogType,
                                                  LPPU_LOG_REQ_PARA_S pstLogReqPara, LPPU_LOG_INFO_S pstDeviceLogInfo);

// get device log info ex
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceLogInfoEx(ULONG ulIdentifyID, LPPU_LOG_REQ_PARA_EX_S pstLogReqPara,
                                                    LPPU_LOG_INFO_EX_S pstDeviceLogInfo);

// device time
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceTime(ULONG ulIdentifyID, LPPU_SYSTEM_TIME_S pstSystemTime);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceTime(ULONG ulIdentifyID, LPPU_SYSTEM_TIME_S pstSystemTime);

// daylight saving time para
_HW_PU_API BOOL __stdcall IVS_PU_GetDaylightSavingTimePara(ULONG ulIdentifyID,
                                                           PU_DAYLIGHT_SAVING_TIME_S *pstDSTPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetDaylightSavingTimePara(ULONG ulIdentifyID,
                                                           PU_DAYLIGHT_SAVING_TIME_S *pstDSTPara);

// reboot device
_HW_PU_API BOOL __stdcall IVS_PU_Reboot(ULONG ulIdentifyID);

// restore device default config (keep IP address)
_HW_PU_API BOOL __stdcall IVS_PU_Restore(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

// restore device default config (set IP to default IP)
_HW_PU_API BOOL __stdcall IVS_PU_TotallyRestore(ULONG ulIdentifyID, CHAR *szUserName, CHAR *szPasswd);

// get device info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceInfo(ULONG ulIdentifyID, LPPU_DEVICEINFO_S pstDeviceInfo);
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceInfo_V2(ULONG ulIdentifyID, LPPU_DEVICEINFO_V2_S pstDeviceInfo);

// �����豸���ƣ��256�ֽ�(��'\0')
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceName(ULONG ulIdentifyID, CHAR *pcDeviceName);

// get device system status info
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceStatusInfo(ULONG ulIdentifyID, LPPU_SYS_STATUS_INFO_S pstSysStatusInfo);

// ���õ�����־����
_HW_PU_API BOOL __stdcall IVS_PU_SetDebugSwitch(ULONG ulIdentifyID, PU_DEBUG_SWITCH_S *pstDebugSwitch);

// remote upgrade device
_HW_PU_API BOOL __stdcall IVS_PU_Upgrade(ULONG ulIdentifyID, LPPU_UPGRADE_FILE_INFO_S pstFileInfo);

// upgrade schedule callback function
typedef BOOL (CALLBACK *pfUpgradeScheduleCallBack)(LPPU_UPGRADE_CALLBACK_S pstUpgradeData,
             VOID *pUsrData);  // ���뵱ǰ�ϴ��ļ��Ľ��ȣ�����ֵ���ΪTRUE����ʾҪȡ������
_HW_PU_API BOOL __stdcall IVS_PU_UpgradeWithSchedule(ULONG ulIdentifyID, LPPU_UPGRADE_FILE_INFO_S pstFileInfo,
                                                     pfUpgradeScheduleCallBack fScheduleCallBack, VOID *pUsrData);
// write sdk log to file
_HW_PU_API BOOL __stdcall IVS_PU_WriteLogToFile(ULONG ulLogEnable, CHAR *szFileName, ULONG ulFileNum,
                                                ULONG ulSizePerFile);

// device config file
_HW_PU_API BOOL __stdcall IVS_PU_GetConfigFile(ULONG ulIdentifyID, CHAR szConfigFile[PU_CONFIG_FILE_PATH_MAX],
                                               CHAR *pszLoadUpKey);
_HW_PU_API BOOL __stdcall IVS_PU_SetConfigFile(ULONG ulIdentifyID, CHAR szConfigFile[PU_CONFIG_FILE_PATH_MAX],
                                               CHAR *pszUserName, CHAR *pszPasswd, CHAR *pszLoadUpKey);

// 802.1x֤�鵼�뵼��
_HW_PU_API BOOL __stdcall IVS_PU_SetDot1xTlsCert(ULONG ulIdentifyID, CHAR szCertFileFirst[PU_CONFIG_FILE_PATH_MAX],
                                                 CHAR szCertFileSecond[PU_CONFIG_FILE_PATH_MAX], PU_DOT1X_TLS_CERT_UPLOAD_S stDot1xTlsCert);

// ֤����Ч�����ڲ���
_HW_PU_API BOOL __stdcall IVS_PU_GetCertExpirePeriodPara(ULONG ulIdentifyID,
                                                         PU_CERT_EXPIRE_PERIOD_PARA_S *pstCertExpirePeriodPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetCertExpirePeriodPara(ULONG ulIdentifyID,
                                                         PU_CERT_EXPIRE_PERIOD_PARA_S *pstCertExpirePeriodPara);

// device log language
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceLogLanguage(ULONG ulIdentifyID, PU_LANGUAGE_TYPE_E *penLanguage);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceLogLanguage(ULONG ulIdentifyID, PU_LANGUAGE_TYPE_E enLanguage);

_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceLogLanguage_V20(ULONG ulIdentifyID, PU_LOG_LANGUAGE_INFO_S *pstLanguage);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceLogLanguage_V20(ULONG ulIdentifyID, PU_LOG_LANGUAGE_INFO_S *pstLanguage);


// device list info by auto discovery
_HW_PU_API BOOL __stdcall IVS_PU_DiscoveryLocalDeviceList(LPPU_DISCOVER_DEVICE_LIST_S pstDeviceList);

// change device IP address by MAC, szSrcNetMac can NULL, szDstMac must be filled such as: "12:34:56:78:9a:bc"
_HW_PU_API BOOL __stdcall IVS_PU_ModifyIPByLocalMac(CHAR *szSrcNetMac, CHAR *szDstMac, CHAR *szPwd, char *szDstIP,
                                                    char *szMask, char *szGateway);
#ifdef _WIN32
// Check if IP conflicts, return non-conflicting IP list and number
_HW_PU_API BOOL __stdcall IVS_PU_PingIPLocal(ULONG ulStartIP, ULONG ulEndIP, ULONG ulNeedNum, ULONG *out_pIPList,
                                             ULONG *out_pulIPNum);
#endif

// search device list info by UDP connect
_HW_PU_API BOOL __stdcall IVS_PU_DiscoveryDeviceByIpAddresses(CHAR *pszStartIpAddr, CHAR *pszEndIpAddr,
                                                              ULONG ulSearchNum, PU_DISCOVER_DEVICE_INFO_S *pszDeviceList, ULONG *pulDeviceNum);
_HW_PU_API BOOL __stdcall IVS_PU_DiscoveryDeviceByIpAddrSet(ULONG *pulIPSet, ULONG ulSearchNum,
                                                            PU_DISCOVER_DEVICE_INFO_S *pszDeviceList, ULONG *pulDeviceNum);

// change device password
_HW_PU_API BOOL __stdcall IVS_PU_ChangeDevicePassword(ULONG ulIdentifyID, CHAR *pszUserName, CHAR *pszOldPasswd,
                                                      CHAR *pszNewPasswd);

// change destination module admin password
_HW_PU_API BOOL __stdcall IVS_PU_ChangeAdminPassword(ULONG ulIdentifyID, CHAR *pszOldPasswd, CHAR *pszNewPasswd,
                                                     PU_IPC_MODULE_E enDstModule);

// change device ip address
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceEthernetPara(ULONG ulIdentifyID,
                                                       LPPU_DEVICE_ETHERNET_PARA_S pstDeviceEthernetPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceEthernetPara(ULONG ulIdentifyID,
                                                       LPPU_DEVICE_ETHERNET_PARA_S pstDeviceEthernetPara);

// ���IP�Ƿ��ͻ
_HW_PU_API BOOL __stdcall IVS_PU_CheckIPConflict(ULONG ulIdentifyID,
                                                 LPPU_DEVICE_ETHERNET_PARA_S pstDeviceEthernetPara);

// ����IP��ַ����
_HW_PU_API BOOL __stdcall IVS_PU_SetIPFilterPara(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFO_S stIPFilterPara);
// ��ȡIP��ַ����
_HW_PU_API BOOL __stdcall IVS_PU_GetIPFilterPara(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFO_S *pstIPFilterPara);

// ����IP��ַ����
_HW_PU_API BOOL __stdcall IVS_PU_SetIPFilterParaV2(ULONG ulIdentifyID, PU_IPFILTER_RULES_INFOV2_S stIPFilterPara);
// ��ȡIP��ַ����
_HW_PU_API BOOL __stdcall IVS_PU_GetIPFilterParaV2(ULONG ulIdentifyID,
                                                   PU_IPFILTER_RULES_INFOV2_S *pstIPFilterPara);

// ����IP��ַ����
_HW_PU_API BOOL __stdcall IVS_PU_SetIPFilterParaV3(ULONG ulIdentifyID,
                                                   PU_IPFILTER_RULES_INFOV3_S *pstIPFilterPara);
// ��ȡIP��ַ����
_HW_PU_API BOOL __stdcall IVS_PU_GetIPFilterParaV3(ULONG ulIdentifyID,
                                                   PU_IPFILTER_RULES_INFOV3_S *pstIPFilterPara);

// response pu register message
_HW_PU_API BOOL __stdcall IVS_PU_ResponseDeviceRegister(ULONG ulIdentifyID,
                                                        LPPU_DEVICE_REGISTER_RSP_S pstDevRegisterRsp);

// device rsa secret key length
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceRSASecretKeyLen(ULONG ulIdentifyID, ULONG *pulSecretKeyLen);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceRSASecretKeyLen(ULONG ulIdentifyID, ULONG ulSecretKeyLen);

// one key collection device informations: logs, system information, ssh information, etc.
_HW_PU_API BOOL __stdcall IVS_PU_OneKeyCollectionDeviceInfo(ULONG ulIdentifyID, CHAR *szFilePath);

// device user management
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceUserList(ULONG ulIdentifyID, PU_USER_LIST_S *pstUserList);

// ����WEB����½�û�������ע��:�ӿڷ�����SDK�ӿڲ�֧��
_HW_PU_API BOOL __stdcall IVS_PU_SetMultiLoginNum(ULONG ulIdentifyID, CHAR *szUserNmae, CHAR *szPassword,
                                                  ULONG ulMultiLoginNum, CHAR *szTargetName);
// ���������ײ�
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamProfile(ULONG ulIdentifyID, ULONG ulChannelId,
                                                  PU_STREAM_PROFILE_E enStreamProfile);
// ��ȡ�����ײ��б�
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamProfileList(ULONG ulIdentifyID,
                                                      PU_STREAMPROFILES_INFO_LIST_S *pstStreamProfilesInfo);
// ����iPCA����
_HW_PU_API BOOL __stdcall IVS_PU_SetIPCAPara(ULONG ulIdentifyID, PU_IPCA_RULES_S stIPCARulePara);

// ���������ײͲ���
_HW_PU_API BOOL __stdcall IVS_PU_SetChannelStreamProfilesPara(ULONG ulIdentifyID,
                                                              PU_CHANNEL_STREAM_PROFILES_S stStreamProfile);

// ��ȡ�����ײͲ���
_HW_PU_API BOOL __stdcall IVS_PU_GetChannelStreamProfilesPara(ULONG ulIdentifyID,
                                                              PU_CHANNEL_STREAM_PROFILES_S *pstStreamProfile);

// ���������ײͲ���V2������
_HW_PU_API BOOL __stdcall IVS_PU_SetChannelStreamProfilesParaV2(ULONG ulIdentifyID,
                                                                PU_CHANNEL_STREAM_PROFILESV2_S stStreamProfile);
// ��ȡ�����ײͲ���V2������
_HW_PU_API BOOL __stdcall IVS_PU_GetChannelStreamProfilesParaV2(ULONG ulIdentifyID,
                                                                PU_CHANNEL_STREAM_PROFILESV2_S *pstStreamProfile);

// ��ȡ/������Ƶ��Ͽ���
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoDiagnosisEnableInfo(ULONG ulIdentifyID,
                                                             PU_VIDEODIAGNOSIS_ENABLE_PARAM_S *pstVideoDiagnosisEnableInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoDiagnosisEnableInfo(ULONG ulIdentifyID,
                                                             PU_VIDEODIAGNOSIS_ENABLE_PARAM_S *pstVideoDiagnosisEnableInfo);

// SMTP����
_HW_PU_API BOOL __stdcall IVS_PU_GetSMTPConfig(ULONG ulIdentifyID, LPPU_SMTP_CONFIG_INFO_S pstSMTPConfig);
_HW_PU_API BOOL __stdcall IVS_PU_SetSMTPConfig(ULONG ulIdentifyID, LPPU_SMTP_CONFIG_INFO_S pstSMTPConfig);

// ����ARP�㲥����
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoARPBroadcastPara(ULONG ulIdentifyID, ULONG ulEthIndex,
                                                         PU_AUTO_ARP_BROADCAST_PARA_S *pstAutoARPBroadcastPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoARPBroadcastPara(ULONG ulIdentifyID, ULONG ulEthIndex,
                                                         PU_AUTO_ARP_BROADCAST_PARA_S *pstAutoARPBroadcastPara);

// SSHʹ��
_HW_PU_API BOOL __stdcall IVS_PU_SetSSHEnable(ULONG ulIdentifyID, PU_SSH_ENABLE_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSSHEnable(ULONG ulIdentifyID, PU_SSH_ENABLE_PARA_S *pstPara);

// SFTPʹ��
_HW_PU_API BOOL __stdcall IVS_PU_SetSFTPEnable(ULONG ulIdentifyID, PU_SFTP_ENABLE_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSFTPEnable(ULONG ulIdentifyID, PU_SFTP_ENABLE_PARA_S *pstPara);

// ONVIF-RTSPý�屣��ʱ��
_HW_PU_API BOOL __stdcall IVS_PU_SetOnvifRtspSessionTimeOut(ULONG ulIdentifyID,
                                                            PU_ONVIF_RTSP_SESSION_TIMEOUT_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetOnvifRtspSessionTimeOut(ULONG ulIdentifyID,
                                                            PU_ONVIF_RTSP_SESSION_TIMEOUT_PARA_S *pstPara);

// AES ��Կ����
_HW_PU_API BOOL __stdcall IVS_PU_UpdateAesKey(ULONG ulIdentifyID, PU_AES_KEY_MODULE_E enAesKeyModule,
                                              CHAR *pszUserName, CHAR *pszPasswd);
//��ȡ��Կ�ļ�
_HW_PU_API BOOL __stdcall IVS_PU_GetResetPasswordKeyFile (ULONG ulIdentifyID, PU_PWD_RESET_OPTAIN_S *pWebUserPwdInfo);

//ͨ����Կ�������� 
_HW_PU_API BOOL __stdcall IVS_PU_ResetPasswordByKeyFile (PU_PWD_RESET_WORK_S *pNewPwdInfo);


// H264 dec
_HW_PU_API HWND __stdcall IVS_PU_H264DecCreate(PU_H264_DEC_ATTR_S *pstDecAttr);
_HW_PU_API VOID __stdcall IVS_PU_H264DecDestroy(HWND pH264Handle);
_HW_PU_API INT __stdcall IVS_PU_H264DecAU(HWND pH264Handle, UCHAR *pucStream, UINT iStreamLen, ULONGLONG ullPTS,
                                          UINT iFlags, PU_H264_DEC_FRAME_S *pstDecFrame);

// H265 dec
_HW_PU_API INT __stdcall IVS_PU_H265DecCreate(HWND *ppH265Handle, PU_H265D_INIT_PARAM_S *pstInitParam);
_HW_PU_API INT __stdcall IVS_PU_H265DecDestroy(HWND pH265Handle);
_HW_PU_API INT __stdcall IVS_PU_H265DecAU(HWND pH265Handle, PU_H265DEC_INARGS_S *pstInArgs,
                                          PU_H265DEC_OUTARGS_S *pstOutArgs);

// ���á���ȡ���豸��������
_HW_PU_API BOOL __stdcall IVS_PU_SetSlaveDeviceBasePara(ULONG ulIdentifyID, PU_SLAVE_DEVICE_INFO_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceBaseParaList(ULONG ulIdentifyID,
                                                            PU_SLAVE_DEVICE_LIST_S *pstParaList);

// ���á���ȡ���豸Onvif����
_HW_PU_API BOOL __stdcall IVS_PU_SetSlaveDeviceOnvifPara(ULONG ulIdentifyID,
                                                         PU_SLAVE_ONVIF_PARAM_S *pstSlaveOnvifPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceOnvifPara(ULONG ulIdentifyID,
                                                         PU_SLAVE_ONVIF_PARAM_S *pstSlaveOnvifPara);

// ���á���ȡ���豸Rtsp����
_HW_PU_API BOOL __stdcall IVS_PU_SetSlaveDeviceRtspPara(ULONG ulIdentifyID,
                                                        PU_SLAVE_RTSP_PARAM_S *pstSlaveRtspPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceRtspPara(ULONG ulIdentifyID,
                                                        PU_SLAVE_RTSP_PARAM_S *pstSlaveRtspPara);

// ��ȡ���豸Onvif״̬
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceOnvifStatus(ULONG ulIdentifyID,
                                                           PU_SLAVE_ONVIF_STATUS_S *pstSlaveOnvifStatus);

// ��ȡ���豸Rtsp״̬
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceRtspStatus(ULONG ulIdentifyID,
                                                          PU_SLAVE_RTSP_STATUS_S *pstSlaveRtspStatus);

// ���á���ȡ����������豸ʹ�ܲ���
_HW_PU_API BOOL __stdcall IVS_PU_SetSlaveDeviceEnablePara(ULONG ulIdentifyID, PU_SLAVE_DEVICE_ENABLE_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetSlaveDeviceEnablePara(ULONG ulIdentifyID, PU_SLAVE_DEVICE_ENABLE_S *pstPara);

// ���á���ȡ1��N����ʹ��
// ע���л�1��N����ʹ�ܻᵼ���豸����
_HW_PU_API BOOL __stdcall IVS_PU_Set1TNEnable(ULONG ulIdentifyID, PU_1TN_ENABLE_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_Get1TNEnable(ULONG ulIdentifyID, PU_1TN_ENABLE_S *pstPara);

// ��ȡ�����������ͨ����Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveChannelInfo(ULONG ulIdentifyID,
                                                           PU_MASTER_SLAVER_CHANNEL_INFO_S *pstPara);

// 1��N�ķ�ʽ�б��ȡ������ǰ���͵�״̬��ȡ���л�
_HW_PU_API BOOL __stdcall IVS_PU_Get1TNSpptModeList(ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_LIST_S *pstParaList);

//��ע��:�ӿڷ�����SDK�ӿڲ�֧��
_HW_PU_API BOOL __stdcall IVS_PU_Set1TNSpptMode(ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_SWITCH_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_Get1TNSpptMode(ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_SWITCH_S *pstPara);

/******************************************************************************************************/
/* IPC Dedicated Functions */
/******************************************************************************************************/

/************************           Device Parameters Functions     ******************************/

// device video stream infos
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoStreamInfo(ULONG ulIdentifyID,
                                                    LPPU_VIDEO_STREAM_INFO_S pstVideoStreamInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoStreamInfo(ULONG ulIdentifyID,
                                                    LPPU_VIDEO_STREAM_INFO_S pstVideoStreamInfo);

// device video stream infos v2
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoStreamInfoV2(ULONG ulIdentifyID,
                                                      LPPU_VIDEO_STREAM_INFO_V2_S pstVideoStreamInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoStreamInfoV2(ULONG ulIdentifyID,
                                                      LPPU_VIDEO_STREAM_INFO_V2_S pstVideoStreamInfo);

// area crop parameter
_HW_PU_API BOOL __stdcall IVS_PU_GetAreaCropPara(ULONG ulIdentifyID, PU_AREA_CROP_PARA_S *pstAreaCropPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetAreaCropPara(ULONG ulIdentifyID, PU_AREA_CROP_PARA_S *pstAreaCropPara);
// ���ûָ�����ü��İ�ť
_HW_PU_API BOOL __stdcall IVS_PU_SetAreaCropRestore(ULONG ulIdentifyID, PU_AREA_CROP_PARA_S *pstAreaCropPara);

// EPTZ control
_HW_PU_API BOOL __stdcall IVS_PU_EPTZControl(ULONG ulIdentifyID, PU_EPTZ_CTRL_S *pstEPTZCtrl);

// device audio stream infos
_HW_PU_API BOOL __stdcall IVS_PU_GetAudioStreamInfo(ULONG ulIdentifyID, LPPU_AUDIO_INFO_S pstAudioInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetAudioStreamInfo(ULONG ulIdentifyID, LPPU_AUDIO_INFO_S pstAudioInfo);

// ��Ƶ������ǿ
_HW_PU_API BOOL __stdcall IVS_PU_SetAiVqeStatus(ULONG ulIdentifyID, BOOL bAiVqeStatus);
_HW_PU_API BOOL __stdcall IVS_PU_GetAiVqeStatus(ULONG ulIdentifyID, BOOL *pbAiVqeStatus);

// ��������
_HW_PU_API BOOL __stdcall IVS_PU_SetEchoCancelEnable(ULONG ulIdentifyID, PU_AEC_ENABLE_S *pstEchoCancelEnable);
_HW_PU_API BOOL __stdcall IVS_PU_GetEchoCancelEnable(ULONG ulIdentifyID, PU_AEC_ENABLE_S *pstEchoCancelEnable);

// device video display infos, and restore default display params
_HW_PU_API BOOL __stdcall IVS_PU_GetVideoDisplayInfo(ULONG ulIdentifyID,
                                                     LPPU_VIDEO_DISPLAY_INFO_S pstVideoDisplayInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetVideoDisplayInfo(ULONG ulIdentifyID,
                                                     LPPU_VIDEO_DISPLAY_INFO_S pstVideoDisplayInfo);
_HW_PU_API BOOL __stdcall IVS_PU_RestoreDefaultDisplayPara(ULONG ulIdentifyID, ULONG ulChannelId);

// device ROI params
_HW_PU_API BOOL __stdcall IVS_PU_GetROIInfo(ULONG ulIdentifyID, LPPU_ROI_INFO_S pstROIInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetROIInfo(ULONG ulIdentifyID, LPPU_ROI_INFO_S pstROIInfo);

// device OSD params extern, can set at most 7 OSD strings
_HW_PU_API BOOL __stdcall IVS_PU_GetOsdText(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetOsdText(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara);

// device OSD margin
_HW_PU_API BOOL __stdcall IVS_PU_GetOSDMargin(ULONG ulIdentifyID, PU_OSD_MARGIN_INFO_S *pstOSDMarginInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetOSDMargin(ULONG ulIdentifyID, PU_OSD_MARGIN_INFO_S *pstOSDMarginInfo);

_HW_PU_API BOOL __stdcall IVS_PU_GetOsdTextEx(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara,
                                              PU_CHAR_ENCODE_TYPE_E enCharEncodeType);
_HW_PU_API BOOL __stdcall IVS_PU_SetOsdTextEx(ULONG ulIdentifyID, LPPU_OSD_PARTICULAR_PARA_S pstOsdPartcularPara,
                                              PU_CHAR_ENCODE_TYPE_E enCharEncodeType);

_HW_PU_API BOOL __stdcall IVS_PU_GetOsdTextExV2(ULONG ulIdentifyID,
                                                LPPU_OSD_PARTICULAR_PARA_EX_OUT_S pstOsdPartcularPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);
_HW_PU_API BOOL __stdcall IVS_PU_SetOsdTextExV2(ULONG ulIdentifyID,
                                                LPPU_OSD_PARTICULAR_PARA_EX_OUT_S pstOsdPartcularPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);

_HW_PU_API BOOL __stdcall IVS_PU_GetOsdTextExV3(ULONG ulIdentifyID,
                                                LPPU_OSD_PARTICULAR_PARA_EX3_OUT_S pstOsdPartcularPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);
_HW_PU_API BOOL __stdcall IVS_PU_SetOsdTextExV3(ULONG ulIdentifyID,
                                                LPPU_OSD_PARTICULAR_PARA_EX3_OUT_S pstOsdPartcularPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);

// device OSDI parameters setting
_HW_PU_API BOOL __stdcall IVS_PU_SetOSDIConfig(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA_S *pstOSDIConfig);
_HW_PU_API BOOL __stdcall IVS_PU_GetOSDIConfig(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA_S *pstOSDIConfig);
_HW_PU_API BOOL __stdcall IVS_PU_GetOSDIConfigV20(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA_V20_S *pstOSDIConfig);
_HW_PU_API BOOL __stdcall IVS_PU_MoveToOSDIArea(ULONG ulIdentifyID, ULONG ulChnID, ULONG ulIndex);
_HW_PU_API BOOL __stdcall IVS_PU_SetOSDIPosition(ULONG ulIdentifyID, PU_OSDI_POSITION_S *pstOSDIPostion);

// device privacy mask
_HW_PU_API BOOL __stdcall IVS_PU_GetPrivacyMask(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_ARRAY_S pstPrivacyMaskArray);
_HW_PU_API BOOL __stdcall IVS_PU_SetPrivacyMask(ULONG ulIdentifyID, LPPU_PRIVACY_MASK_ARRAY_S pstPrivacyMaskArray);

// device privacy mask with color
_HW_PU_API BOOL __stdcall IVS_PU_GetPrivacyMaskEx(ULONG ulIdentifyID,
                                                  LPPU_PRIVACY_MASK_ARRAY_EX_S pstPrivacyMaskArrayEx);
_HW_PU_API BOOL __stdcall IVS_PU_SetPrivacyMaskEx(ULONG ulIdentifyID,
                                                  LPPU_PRIVACY_MASK_ARRAY_EX_S pstPrivacyMaskArrayEx);

// device privacy mask
_HW_PU_API BOOL __stdcall IVS_PU_GetPrivacyMaskArea(ULONG ulIdentifyID,
                                                    LPPU_PRIVACY_MASK_AREA_ARRAY_S pstPrivacyMaskAreaArray);
_HW_PU_API BOOL __stdcall IVS_PU_SetPrivacyMaskArea(ULONG ulIdentifyID,
                                                    LPPU_PRIVACY_MASK_AREA_ARRAY_S pstPrivacyMaskAreaArray);

_HW_PU_API BOOL __stdcall IVS_PU_AddPrivacyMaskArea(ULONG ulIdentifyID, PU_ADD_MASK_PARA_S *pstPrivacyMaskArea);
_HW_PU_API BOOL __stdcall IVS_PU_DelPrivacyMaskArea(ULONG ulIdentifyID, PU_DEL_MASK_PARA_S *pstPrivacyMaskArea);
_HW_PU_API BOOL __stdcall IVS_PU_PagedQueryPrivacyMask(ULONG ulIdentifyID,
                                                       PU_PRIVACY_MASK_AREA_LIST_S *pstPrivacyMaskList);
_HW_PU_API BOOL __stdcall IVS_PU_PagedQueryPrivacyMaskV2(ULONG ulIdentifyID,
                                                         PU_PRIVACY_MASK_AREA_LIST_V2_S *pstPrivacyMaskList);

#ifdef _WIN32
// set platform params
_HW_PU_API BOOL __stdcall IVS_PU_SetPlatformPara(ULONG ulIdentifyID, PU_PLATFORM_TYPE_E enPlatform, VOID *arg);
#endif

// IVS platform params ��ע��:�ӿڷ���,SDK�ӿڲ�֧��
_HW_PU_API BOOL __stdcall IVS_PU_GetIVSPlatformPara(ULONG ulIdentifyID,
                                                    LPPU_PLATFORM_IVS_PARA_S pstIvsPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIVSPlatformPara(ULONG ulIdentifyID,
                                                    LPPU_PLATFORM_IVS_PARA_S pstIvsPlatformPara);

// GBT 28281 platform params
_HW_PU_API BOOL __stdcall IVS_PU_GetGBTPlatformPara(ULONG ulIdentifyID,
                                                    LPPU_PLATFORM_GBT_PARA_S pstGbtPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGBTPlatformPara(ULONG ulIdentifyID,
                                                    LPPU_PLATFORM_GBT_PARA_S pstGbtPlatformPara);

_HW_PU_API BOOL __stdcall IVS_PU_GetGBTPlatformPara_V2(ULONG ulIdentifyID,
                                                       LPPU_PLATFORM_GBT_PARA_V2_S pstGbtPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGBTPlatformPara_V2(ULONG ulIdentifyID,
                                                       LPPU_PLATFORM_GBT_PARA_V2_S pstGbtPlatformPara);

// SDK platform params
_HW_PU_API BOOL __stdcall IVS_PU_GetSDKPlatformPara(ULONG ulIdentifyID,
                                                    LPPU_PLATFORM_SDK_PARA_S pstSdkPlatformPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSDKPlatformPara(ULONG ulIdentifyID,
                                                    LPPU_PLATFORM_SDK_PARA_S pstSdkPlatformPara);
// ����/��ȡ GA/T 1400
_HW_PU_API BOOL __stdcall IVS_PU_GetGAPlatformParam(ULONG ulIdentifyID, PU_GAT1400_ENABLE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGAPlatformParam(ULONG ulIdentifyID, PU_GAT1400_ENABLE_PARAM_S *pstPara);

// get/set device dynamic stream info
_HW_PU_API BOOL __stdcall IVS_PU_GetDynamicStreamInfo(ULONG ulIdentifyID,
                                                      LPPU_DYNAMIC_STREAM_INFO_S pstDynamicStreamInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetDynamicStreamInfo(ULONG ulIdentifyID,
                                                      LPPU_DYNAMIC_STREAM_INFO_S pstDynamicStreamInfo);

// device watermark params
_HW_PU_API BOOL __stdcall IVS_PU_SetWaterMark(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enStreamType,
                                              BOOL bWaterMarkEnable);
_HW_PU_API BOOL __stdcall IVS_PU_GetWaterMark(ULONG ulIdentifyID, ULONG ulChannelId, PU_STREAM_TYPE_E enStreamType,
                                              BOOL *pbWaterMarkEnable);

// device record plans (��ע��:�ӿڷ���,SDK�ӿڲ�֧��)
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordPlanList(ULONG ulIdentifyID, LPPU_RECORD_PLAN_S pstRecordPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordPlanList(ULONG ulIdentifyID, LPPU_RECORD_PLAN_S pstRecordPlan);

// get device record info
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordInfoList(ULONG ulIdentifyID, LPPU_RECORD_INQUIRE_S pstRecordInquire,
                                                   LPPU_RECORD_LIST_S pstRecordList);
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordInfoListByUTC(ULONG ulIdentifyID, LPPU_RECORD_INQUIRE_S pstRecordInquire,
                                                        LPPU_RECORD_LIST_S pstRecordList);
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmRecInfoList(ULONG ulIdentifyID, PU_ALARM_REC_INQ_REQ_S *pstAlarmRecInqReq,
                                                     PU_ALARM_REC_INQ_RSP_S *pstAlarmRecInqRsp);

// delect device record file
_HW_PU_API BOOL __stdcall IVS_PU_DelRecordFile(ULONG ulIdentifyID, ULONG ulChannelId, CHAR *pszRecordFileName);

// device record full strategy
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordFullStrategy(ULONG ulIdentifyID,
                                                       LPPU_RECORD_STRATEGY_S pstRecordStrategy);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordFullStrategy(ULONG ulIdentifyID,
                                                       LPPU_RECORD_STRATEGY_S pstRecordStrategy);

// set cache record enable
_HW_PU_API BOOL __stdcall IVS_PU_SetCacheRecordType(ULONG ulIdentifyID, PU_CACHERECORD_E enCacheRecType);
_HW_PU_API BOOL __stdcall IVS_PU_GetCacheRecordType(ULONG ulIdentifyID, PU_CACHERECORD_E *penCacheRecType);

// set device stream layer code mode
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamLayerCodeMode(ULONG ulIdentifyID, ULONG ulChannelId,
                                                        PU_STREAM_TYPE_E enStreamType, BOOL bEnable);
// get device stream layer code mode
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamLayerCodeMode(ULONG ulIdentifyID, ULONG ulChannelId,
                                                        PU_STREAM_TYPE_E enStreamType, BOOL *pbEnable);

// set device stream function params
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamFunctionPara(ULONG ulIdentifyID, ULONG ulChannelId,
                                                       PU_STREAM_TYPE_E enPURecordStream, PU_STREAM_TYPE_E enPlatRecordStream);

// get device ability params
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceAbility(ULONG ulIdentifyID, LPPU_DEVICE_ABILITY_S pstDeviceAbility);

// get device stream ability params
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamAbility(ULONG ulIdentifyID, LPPU_STREAM_ABILITY_S pstStreamAbilityPara);

// get device stream abilityV2 params
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamAbilityV2(ULONG ulIdentifyID,
                                                    LPPU_STREAM_ABILITYV2_S pstStreamAbilityPara);
// device snapshot
_HW_PU_API BOOL __stdcall IVS_PU_StartSnapShot(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulSnapCount,
                                               ULONG ulSnapInterval, PU_SNAPSHOT_TYPE_E enSnapType);
_HW_PU_API BOOL __stdcall IVS_PU_ResponseUploadImageURL(ULONG ulIdentifyID, ULONG ulSessionId,
                                                        PU_ERROR_CODE_E enErrorCode, CHAR *pszUploadURL);
_HW_PU_API BOOL __stdcall IVS_PU_ResponseUploadImageCompleteNotify(ULONG ulIdentifyID, ULONG ulSessionId,
                                                                   PU_ERROR_CODE_E enErrorCode);
// device snapshot expansion
_HW_PU_API BOOL __stdcall IVS_PU_StartSnapShotEx(ULONG ulIdentifyID,LPUPU_START_SNAPSHOT_S pstSnapShotPara);


// Manual snapshot
_HW_PU_API BOOL __stdcall IVS_PU_ManualSnapshot(ULONG ulIdentifyID, PU_SNAPSHOT_PARA_S *pstSnapshotPara);

// Manual snapshot V2
_HW_PU_API BOOL __stdcall IVS_PU_ManualSnapshotV2(ULONG ulIdentifyID, PU_SNAPSHOT_PARA_V2_S *pstSnapshotPara);

// Snapshot quality parameters
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotQuality(ULONG ulIdentifyID,
                                                    PU_SNAPSHOT_QUAILTY_PARA_S *pstSnapshotQuality);
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotQuality(ULONG ulIdentifyID,
                                                    PU_SNAPSHOT_QUAILTY_PARA_S *pstSnapshotQuality);

// Snapshot resolution parameters
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotResolution(ULONG ulIdentifyID,
                                                       PU_SNAPSHOT_RESOLUTION_PARA_S *pstSnapshotRes);
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotResolution(ULONG ulIdentifyID,
                                                       PU_SNAPSHOT_RESOLUTION_PARA_S *pstSnapshotRes);

// Snapshot retrans enable
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotRetransPara(ULONG ulIdentifyID,
                                                        PU_SNAPSHOT_RETRANS_PARA_S *pstSnapshotRetrans);
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotRetransPara(ULONG ulIdentifyID,
                                                        PU_SNAPSHOT_RETRANS_PARA_S *pstSnapshotRetrans);

_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotPicList(ULONG ulIdentifyID, PU_SNAPSHOT_INQUIRE_S *pstSnapshotInquire,
                                                    PU_SNAPSHOT_LIST_S *pstSnapshotList);
_HW_PU_API BOOL __stdcall IVS_PU_DownloadSnapshotPic(ULONG ulIdentifyID, ULONG ulChnID, CHAR *szContentID,
                                                     CHAR *szDownloadPath);

// ͼ�������ж�
_HW_PU_API BOOL __stdcall IVS_PU_GetImgQualityJudgeResult(ULONG ulIdentifyID, PU_IMG_QUALITY_JUDGE_S *pstImgInfo);

// device FEC params  ��ע��:�ӿڷ���,SDK�ӿڲ�֧��
_HW_PU_API BOOL __stdcall IVS_PU_GetFECPara(ULONG ulIdentifyID, LPPU_FEC_PARA_S pstFecPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetFECPara(ULONG ulIdentifyID, LPPU_FEC_PARA_S pstFecPara);

// device SEC params
_HW_PU_API BOOL __stdcall IVS_PU_GetSECPara(ULONG ulIdentifyID, LPPU_SEC_PARA_S pstSecPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSECPara(ULONG ulIdentifyID, PU_SEC_PARA_S stSecPara);

// device EPTZ params  ��ע��:�ӿڷ���,SDK�ӿڲ�֧��
_HW_PU_API BOOL __stdcall IVS_PU_GetEPTZPara(ULONG ulIdentifyID, LPPU_EPTZ_PARA_S pstEPTZPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetEPTZPara(ULONG ulIdentifyID, LPPU_EPTZ_PARA_S pstEPTZPara);

// device ONVIF protocol
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFSwitch(ULONG ulIdentifyID, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFSwitch(ULONG ulIdentifyID, BOOL bEnable);

// ONVIF ��Ϣ��Ч�ڿ���
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFExpiresSwitch(ULONG ulIdentifyID, PU_ONVIF_SWITCH_S *pstONVIFSwitch);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFExpiresSwitch(ULONG ulIdentifyID, PU_ONVIF_SWITCH_S *pstONVIFSwitch);

// ONVIF �汾��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFVersionType(ULONG ulIdentifyID,
                                                     PU_ONVIF_VERSION_TYPE_S *pstONVIFVersionType);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFVersionType(ULONG ulIdentifyID,
                                                     PU_ONVIF_VERSION_TYPE_S *pstONVIFVersionType);

// device ONVIF params
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFPwdPara(ULONG ulIdentifyID, LPPU_ONVIF_PWD_PARA_S pstOnvifPwdPara);

// device ONVIF stream params
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFStreamCodeType(ULONG ulIdentifyID,
                                                        PU_VIDEO_CODE_TYPE_E *penVideoCodeType);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFStreamCodeType(ULONG ulIdentifyID, PU_VIDEO_CODE_TYPE_E enVideoCodeType);

// device ONVIF authentication type
_HW_PU_API BOOL __stdcall IVS_PU_GetONVIFAuthType(ULONG ulIdentifyID, PU_ONVIF_AUTH_TYPE_E *penOnvifAuthType);
_HW_PU_API BOOL __stdcall IVS_PU_SetONVIFAuthType(ULONG ulIdentifyID, PU_ONVIF_AUTH_TYPE_E enOnvifAuthType);

// device Genetec protocol switch(��ע��:�ӿڷ���,SDK�ӿڲ�֧��)
_HW_PU_API BOOL __stdcall IVS_PU_GetGenetecSwitch(ULONG ulIdentifyID, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetGenetecSwitch(ULONG ulIdentifyID, BOOL bEnable);

// device Genetec protocol digest authentication switch(��ע��:�ӿڷ���,SDK�ӿڲ�֧��)
_HW_PU_API BOOL __stdcall IVS_PU_GetGenetecDigestAuthSwitch(ULONG ulIdentifyID, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetGenetecDigestAuthSwitch(ULONG ulIdentifyID, BOOL bEnable);

// device stream buffering params (��ע��:�ӿڷ���,SDK�ӿڲ�֧��)
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamSmoothPara(ULONG ulIdentifyID,
                                                     LPPU_STREAM_SMOOTH_PARA_S pstStreamSmoothPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamSmoothPara(ULONG ulIdentifyID,
                                                     LPPU_STREAM_SMOOTH_PARA_S pstStreamSmoothPara);

// I/P֡�������
_HW_PU_API BOOL __stdcall IVS_PU_GetKFCodingStrategyPara(ULONG ulIdentifyID,
                                                         PU_KF_CODING_STRATEGY_PARA_S *pstKFCodingStrategyPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetKFCodingStrategyPara(ULONG ulIdentifyID,
                                                         PU_KF_CODING_STRATEGY_PARA_S *pstKFCodingStrategyPara);

// device stream buffering params (��ע��:�ӿڷ���,SDK�ӿڲ�֧��)
_HW_PU_API BOOL __stdcall IVS_PU_GetStreamSmoothParaEx(ULONG ulIdentifyID,
                                                       LPPU_STREAM_SMOOTH_PARA_EX_S pstStreamSmoothPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetStreamSmoothParaEx(ULONG ulIdentifyID,
                                                       LPPU_STREAM_SMOOTH_PARA_EX_S pstStreamSmoothPara);

// device traffic shaping parameter
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficShapingPara(ULONG ulIdentifyID,
                                                       PU_TRAFFIC_SHAPING_PARA_S *pstTrafficShapingPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficShapingPara(ULONG ulIdentifyID,
                                                       PU_TRAFFIC_SHAPING_PARA_S *pstTrafficShapingPara);

// HTTP/HTTPS/RTSP port setting
_HW_PU_API BOOL __stdcall IVS_PU_GetDevicePortConfig(ULONG ulIdentifyID,
                                                     PU_DEVICE_PORT_CONFIG_S *pstDevPortConfig);
_HW_PU_API BOOL __stdcall IVS_PU_SetDevicePortConfig(ULONG ulIdentifyID,
                                                     PU_DEVICE_PORT_CONFIG_S *pstDevPortConfig);

// HTTP/HTTPS/RTSP port setting ex
_HW_PU_API BOOL __stdcall IVS_PU_GetDevicePortConfigEx(ULONG ulIdentifyID,
                                                       PU_DEVICE_PORT_CONFIG_EX_S *pstDevPortConfig);
_HW_PU_API BOOL __stdcall IVS_PU_SetDevicePortConfigEx(ULONG ulIdentifyID,
                                                       PU_DEVICE_PORT_CONFIG_EX_S *pstDevPortConfig);

// RSTP NAT port setting
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceNATPortConfig(ULONG ulIdentifyID,
                                                        PU_DEVICE_NAT_PORT_CONFIG_S *pstNATPort);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceNATPortConfig(ULONG ulIdentifyID,
                                                        PU_DEVICE_NAT_PORT_CONFIG_S *pstNATPort);

// device qos dscp params
_HW_PU_API BOOL __stdcall IVS_PU_GetQosDscpPara(ULONG ulIdentifyID, PU_DSCP_TYPE_E *penDscpType,
                                                ULONG *pulDscpValue);
_HW_PU_API BOOL __stdcall IVS_PU_SetQosDscpPara(ULONG ulIdentifyID, PU_DSCP_TYPE_E enDscpType, ULONG ulDscpValue);

// device MTU value
_HW_PU_API BOOL __stdcall IVS_PU_GetMTUPara(ULONG ulIdentifyID, ULONG *pulMtuValue);
_HW_PU_API BOOL __stdcall IVS_PU_SetMTUPara(ULONG ulIdentifyID, ULONG ulMtuValue);

// device record upload band width
_HW_PU_API BOOL __stdcall IVS_PU_GetRecordUploadBandwidth(ULONG ulIdentifyID, BOOL *pbEnable,
                                                          ULONG *pulMaxUploadRate);
_HW_PU_API BOOL __stdcall IVS_PU_SetRecordUploadBandwidth(ULONG ulIdentifyID, BOOL bEnable, ULONG ulMaxUploadRate);

// device band width self adaption
_HW_PU_API BOOL __stdcall IVS_PU_GetBandwidthSelfAdaption(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetBandwidthSelfAdaption(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);

// device NTP params
_HW_PU_API BOOL __stdcall IVS_PU_GetNTPPara(ULONG ulIdentifyID, LPPU_NTP_PARA_S pstNtpPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetNTPPara(ULONG ulIdentifyID, LPPU_NTP_PARA_S pstNtpPara);

// device GPS params
_HW_PU_API BOOL __stdcall IVS_PU_GetGPSPara(ULONG ulIdentifyID, LPPU_GPS_PARA_S pstGPSPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGPSPara(ULONG ulIdentifyID, LPPU_GPS_PARA_S pstGPSPara);

// device TCP Accelerate Parameter
_HW_PU_API BOOL __stdcall IVS_PU_SetTCPAcceleratePara(ULONG ulIdentifyID,
                                                      PU_TCP_ACCELERATE_PARA_S *pstTcpAcceleratePara);
_HW_PU_API BOOL __stdcall IVS_PU_GetTCPAcceleratePara(ULONG ulIdentifyID,
                                                      PU_TCP_ACCELERATE_PARA_S *pstTcpAcceleratePara);

// device corridor mode
_HW_PU_API BOOL __stdcall IVS_PU_GetCorridorMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetCorridorMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);

// device OSD picture info
_HW_PU_API BOOL __stdcall IVS_PU_GetOSDPicturePara(ULONG ulIdentifyID, LPPU_OSD_PICTURE_PARA_S pstPicturePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetOSDPicturePara(ULONG ulIdentifyID, LPPU_OSD_PICTURE_PARA_S pstPicturePara);

// device snmp protocol params for v1/v2c
_HW_PU_API BOOL __stdcall IVS_PU_GetSnmpCommunityList(ULONG ulIdentifyID,
                                                      LPPU_SNMP_COMMUNITY_LIST_S pstCommunityList);
_HW_PU_API BOOL __stdcall IVS_PU_SetSnmpCommunityList(ULONG ulIdentifyID,
                                                      LPPU_SNMP_COMMUNITY_LIST_S pstCommunityList);

// device snmp protocol params for v1/v2c
_HW_PU_API BOOL __stdcall IVS_PU_GetSnmpCommunityListEx(ULONG ulIdentifyID,
                                                        LPPU_SNMP_COMMUNITY_LIST_S_EX pstCommunityList);
_HW_PU_API BOOL __stdcall IVS_PU_SetSnmpCommunityListEx(ULONG ulIdentifyID,
                                                        LPPU_SNMP_COMMUNITY_LIST_S_EX pstCommunityList);

// device snmp protocol params for v3
_HW_PU_API BOOL __stdcall IVS_PU_GetSnmpUserList(ULONG ulIdentifyID, LPPU_SNMPV3_USER_LIST_S pstUserList);
_HW_PU_API BOOL __stdcall IVS_PU_SetSnmpUserInfo(ULONG ulIdentifyID, LPPU_SNMPV3_USER_MGMT_S pstUserMgmtInfo);

// device snmp protocol trap params
_HW_PU_API BOOL __stdcall IVS_PU_GetSnmpTrapList(ULONG ulIdentifyID, LPPU_SNMP_TRAP_LIST_S pstTrapList);
_HW_PU_API BOOL __stdcall IVS_PU_SetSnmpTrapList(ULONG ulIdentifyID, LPPU_SNMP_TRAP_LIST_S pstTrapList);

// device 802.1x protocol params
_HW_PU_API BOOL __stdcall IVS_PU_Get802Dot1xConfig(ULONG ulIdentifyID, LPPU_DOT1X_CONFIG_INFO_S pstDot1xInfo);
_HW_PU_API BOOL __stdcall IVS_PU_Set802Dot1xConfig(ULONG ulIdentifyID, LPPU_DOT1X_CONFIG_INFO_S pstDot1xInfo);

// device web http/https
_HW_PU_API BOOL __stdcall IVS_PU_GetWebHttpMode(ULONG ulIdentifyID, PU_WEB_HTTP_MODE_E *penHttpMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetWebHttpMode(ULONG ulIdentifyID, PU_WEB_HTTP_MODE_E enHttpMode);

// web������Ч��
_HW_PU_API BOOL __stdcall IVS_PU_GetWebPwdPeriodPara(ULONG ulIdentifyID, PU_WEB_PWD_PERIOD_PARA_S *pstPwdPeriod);
_HW_PU_API BOOL __stdcall IVS_PU_SetWebPwdPeriodPara(ULONG ulIdentifyID, PU_WEB_PWD_PERIOD_PARA_S *pstPwdPeriod);

// ������HTTPS֤��
_HW_PU_API BOOL __stdcall IVS_PU_SetHttpsCertificate(ULONG ulIdentifyID, PU_CREATE_HTTPS_CERT_S stHttpsCert);

// device onvif media keeplive
_HW_PU_API BOOL __stdcall IVS_PU_GetOnvifMediaKeepAliveMode(ULONG ulIdentifyID, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetOnvifMediaKeepAliveMode(ULONG ulIdentifyID, BOOL bEnable);

// device disk format
_HW_PU_API BOOL __stdcall IVS_PU_DiskFormat(ULONG ulIdentifyID);

// device disk format Ex
_HW_PU_API BOOL __stdcall IVS_PU_DiskFormatEx(ULONG ulIdentifyID, LPPU_HARD_DISK_S pstDisk);

// device sd card record status
_HW_PU_API BOOL __stdcall IVS_PU_GetSDCardRecordStatus(ULONG ulIdentifyID, LPPU_LOCAL_RECORD_S pstLocalRecord);
_HW_PU_API BOOL __stdcall IVS_PU_SetSDCardRecordStatus(ULONG ulIdentifyID, LPPU_LOCAL_RECORD_S pstLocalRecord);

// device sd card record time
_HW_PU_API BOOL __stdcall IVS_PU_GetSDCardRecordTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulSeconds);
_HW_PU_API BOOL __stdcall IVS_PU_SetSDCardRecordTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulSeconds);

// ��ѯSD��״̬
_HW_PU_API BOOL __stdcall IVS_PU_GetDiskState(ULONG ulIdentifyID, PU_HARD_DISK_STATE_S *pstDiskState);

// device video format
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceVideoFormat(ULONG ulIdentifyID, ULONG ulChannelId,
                                                      PU_VIDEO_FORMAT_E *penVideoFormat);
_HW_PU_API BOOL __stdcall IVS_PU_SetDeviceVideoFormat(ULONG ulIdentifyID, ULONG ulChannelId,
                                                      PU_VIDEO_FORMAT_E enVideoFormat);

// �����հ���������
_HW_PU_API BOOL __stdcall IVS_PU_SetRecvRateLimit(ULONG ulIdentifyID, ULONG ulRecvRateLimit);
// ��ȡ�հ���������
_HW_PU_API BOOL __stdcall IVS_PU_GetRecvRateLimit(ULONG ulIdentifyID, ULONG *pulRecvRateLimit);

// ����CVBS����
_HW_PU_API BOOL __stdcall IVS_PU_SetCVBSPara(ULONG ulIdentifyID, PU_CVBS_PARA_S stCVBSResolution);
// ��ȡCVBS����
_HW_PU_API BOOL __stdcall IVS_PU_GetCVBSPara(ULONG ulIdentifyID, PU_CVBS_PARA_S *pstCVBSResolution);

// ����ץ�Ŀռ�
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotSpace(ULONG ulIdentifyID, PU_SNAPSHOT_SPACE_S stSnapshotSpace);
// ��ȡץ�Ŀռ�
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotSpace(ULONG ulIdentifyID, PU_SNAPSHOT_SPACE_S *pstSnapshotSpace);

// ���ö�ʱץ��
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotTiming(ULONG ulIdentifyID, PU_SNAPSHOT_TIMING_PARA_S stSnapshotTiming);
// ��ȡ��ʱץ��
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotTiming(ULONG ulIdentifyID,
                                                   PU_SNAPSHOT_TIMING_PARA_S *pstSnapshotTiming);

// ����ץ��ͼƬͨ��FTP/SFTP�ϴ�����
_HW_PU_API BOOL __stdcall IVS_PU_SetFTPFileUploadPara(ULONG ulIdentifyID,
                                                      PU_FTP_FILE_UPLOAD_PARA_S stFTPFileUpload);
// ��ȡץ��ͼƬͨ��FTP/SFTP�ϴ�����
_HW_PU_API BOOL __stdcall IVS_PU_GetFTPFileUploadPara(ULONG ulIdentifyID,
                                                      PU_FTP_FILE_UPLOAD_PARA_S *pstFTPFileUpload);

// ����SD��¼��ƻ�
_HW_PU_API BOOL __stdcall IVS_PU_SetSDCardRecordPlan(ULONG ulIdentifyID, PU_LOCAL_RECORD_PLAN_S stLocalRecordPlan);
// ��ȡSD��¼��ƻ�
_HW_PU_API BOOL __stdcall IVS_PU_GetSDCardRecordPlan(ULONG ulIdentifyID,
                                                     PU_LOCAL_RECORD_PLAN_S *pstLocalRecordPlan);

// ����ABF��FOCUS�仯������FOCUS��FAR����NEAR�����˶�����ɺ󲻻��Զ��۽�
_HW_PU_API BOOL __stdcall IVS_PU_SetABFFocusAction(ULONG ulIdentifyID, PU_CAM_FOCUSCTRL_S *pstFocus);
// ����ABF���Զ��۽�
_HW_PU_API BOOL __stdcall IVS_PU_SetABFAutoBackFocus(ULONG ulIdentifyID, ULONG ulChannelId);
// ����ABF�󽹳�ʼ��
_HW_PU_API BOOL __stdcall IVS_PU_SetABFInitialPos(ULONG ulIdentifyID, ULONG ulChannelId);

// ��ȡCMOS�ߴ�
_HW_PU_API BOOL __stdcall IVS_PU_GetCMOSSize(ULONG ulIdentifyID, PU_CMOS_SIZE_PARA_S *pstCMOSSizePara);

// ����߶�
_HW_PU_API BOOL __stdcall IVS_PU_SetInstallHeight(ULONG ulIdentifyID, PU_CAM_INSTALL_HEIGHT_S *pstInstallHeight);
_HW_PU_API BOOL __stdcall IVS_PU_GetInstallHeight(ULONG ulIdentifyID, PU_CAM_INSTALL_HEIGHT_S *pstInstallHeight);

// ����λ��
_HW_PU_API BOOL __stdcall IVS_PU_SetCamGeogPostion(ULONG ulIdentifyID, PU_CAM_GEOG_POSITION_S *pstCamGeogPostion);
_HW_PU_API BOOL __stdcall IVS_PU_GetCamGeogPostion(ULONG ulIdentifyID, PU_CAM_GEOG_POSITION_S *pstCamGeogPostion);

/******************************           Stream Functions     **********************************/

// key frame request
_HW_PU_API BOOL __stdcall IVS_PU_KeyFrameRequest(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulStreamId);

// real play callback function type
typedef VOID (CALLBACK *pfRealDataCallBack)(CHAR *szBuffer, LONG lSize, VOID *pUsrData);
// real play callback functionEx type
typedef VOID (CALLBACK *pfRealDataCallBackEx)(CHAR *szBuffer, LONG lSize, PU_MEDIA_FRAME_INFO_S *pstRealPlayInfo, VOID *pUsrData);

// real play
_HW_PU_API ULONG __stdcall IVS_PU_RealPlay(ULONG ulIdentifyID, LPPU_REAL_PLAY_INFO_S pstRealPlayInfo,
                                           pfRealDataCallBack fRealDataCallBack, VOID *pUsrData);
_HW_PU_API ULONG __stdcall IVS_PU_RealPlay_V20(ULONG ulIdentifyID, PU_REAL_PLAY_INFO_V20_S *pstRealPlayInfo,
                                               PU_MEDIA_ENC_PARA_S *pstMediaEncPara, pfRealDataCallBack fRealDataCallBack, VOID *pUsrData);
_HW_PU_API ULONG __stdcall IVS_PU_RealPlay_V30(ULONG ulIdentifyID, PU_REAL_PLAY_INFO_V20_S *pstRealPlayInfo,
                                               PU_MEDIA_ENC_PARA_S *pstMediaEncPara, pfRealDataCallBackEx fRealDataCallBackEx, VOID *pUsrData);

_HW_PU_API BOOL __stdcall IVS_PU_StopRealPlay(ULONG ulIdentifyID, ULONG ulRealHandle);
_HW_PU_API BOOL __stdcall IVS_PU_StopAllRealPlay(ULONG ulIdentifyID);

// voice broadcast
_HW_PU_API ULONG __stdcall IVS_PU_StartVoiceBroadcast(ULONG ulIdentifyID, LPPU_VOICE_INFO_S pstVoiceBroadcastInfo);
_HW_PU_API BOOL __stdcall IVS_PU_StopVoiceBroadcast(ULONG ulIdentifyID, ULONG ulVBHandle);

// voice talk back callback function type
typedef VOID (CALLBACK *pfVoiceTBCallBack)(CHAR *szBuffer, LONG lSize, VOID *pUsrData);

// voice talk back
_HW_PU_API ULONG __stdcall IVS_PU_StartVoiceTB(ULONG ulIdentifyID, LPPU_VOICE_INFO_S pstVoiceTBInfo,
                                               pfVoiceTBCallBack fVoiceTBCallBack, VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_StopVoiceTB(ULONG ulIdentifyID, ULONG ulVoiceTBHandle);

// Feed voice data for voice talk back and broadcast
_HW_PU_API BOOL __stdcall IVS_PU_FeedVoiceData(ULONG ulIdentifyID, ULONG ulVBHandle, CHAR *pSendBuf,
                                               ULONG ulBufSize, ULONG ulType);

// save real play data
_HW_PU_API BOOL __stdcall IVS_PU_SaveRealData(ULONG ulIdentifyID, ULONG ulRealHandle,
                                              LPPU_SAVE_REALDATA_INFO_S pstSaveRealDataInfo);
_HW_PU_API BOOL __stdcall IVS_PU_StopSaveRealData(ULONG ulIdentifyID, ULONG ulRealHandle);

// save local snapshot picture
_HW_PU_API BOOL __stdcall IVS_PU_SavePicture(ULONG ulIdentifyID, ULONG ulRealHandle,
                                             LPPU_SAVE_PICTURE_INFO_S pstSavePictureInfo);

// media signal
_HW_PU_API BOOL __stdcall IVS_PU_MediaPlay(ULONG ulIdentifyID, LPPU_MEDIA_PLAY_INFO_S pstMediaPlayReqInfo,
                                           LPPU_MEDIA_PLAY_RSP_S pstMediaPlayRspInfo);
_HW_PU_API BOOL __stdcall IVS_PU_MeidaPlayAck(ULONG ulIdentifyID, ULONG ulSessionId, ULONG ulVideoPayload,
                                              ULONG ulAudioPayload, ULONG ulIgtPayload);
_HW_PU_API BOOL __stdcall IVS_PU_MeidaStop(ULONG ulIdentifyID, ULONG ulSessionId);
// �½ӿڣ�������IVS_PU_MeidaPlayAck��IVS_PU_MeidaStopһ��
_HW_PU_API BOOL __stdcall IVS_PU_MediaPlayAck(ULONG ulIdentifyID, ULONG ulSessionId, ULONG ulVideoPayload,
                                              ULONG ulAudioPayload, ULONG ulIgtPayload);
_HW_PU_API BOOL __stdcall IVS_PU_MediaStop(ULONG ulIdentifyID, ULONG ulSessionId);

// IVS_PU_MediaPlay�ӿڵ����䣬����Ԫ������Կ
_HW_PU_API BOOL __stdcall IVS_PU_MediaPlay_V2(ULONG ulIdentifyID, LPPU_MEDIA_PLAY_INFO_V2_S pstMediaPlayReqInfo,
                                              LPPU_MEDIA_PLAY_RSP_S pstMediaPlayRspInfo);
// IVS_PU_MediaPlayAck�ӿڵ����䣬����ͨ��ID
_HW_PU_API BOOL __stdcall IVS_PU_MediaPlayAck_V2(ULONG ulIdentifyID, PU_MEDIA_PLAY_ACK_INFO_S *pstMediaPlayAckInfo);

//IVS_PU_MediaStop�ӿڵ����䣬����ͨ��ID
_HW_PU_API BOOL __stdcall IVS_PU_MediaStop_V2(ULONG ulIdentifyID, PU_MEDIA_PLAY_STOP_INFO_S *pstMediaPlayStopInfo);

// Set Multicast IP Address & Port
_HW_PU_API BOOL __stdcall IVS_PU_SetMulticastPara(ULONG ulIdentifyID, CHAR *szLocalIP, ULONG ulVideoPort);
_HW_PU_API BOOL __stdcall IVS_PU_GetMulticastPara(ULONG ulIdentifyID, CHAR *szLocalIP, ULONG *ulVideoPort);

// Set Multicast IP Address & Port ex
_HW_PU_API BOOL __stdcall IVS_PU_SetMulticastParaEx(ULONG ulIdentifyID, PU_MULTICAST_PARA_S *pstParam);
_HW_PU_API BOOL __stdcall IVS_PU_GetMulticastParaEx(ULONG ulIdentifyID, PU_MULTICAST_PARA_S *pstParam);

// Start Multicast
_HW_PU_API ULONG __stdcall IVS_PU_StartMulticast(ULONG ulIdentifyID, CHAR *szLocalIP, ULONG ulVideoPort);
_HW_PU_API BOOL __stdcall IVS_PU_StopMulticast(ULONG ulIdentifyID, ULONG ulSessionId);

// Set Sound Switch
_HW_PU_API BOOL __stdcall IVS_PU_SetSoundSwitch(ULONG ulIdentifyID, ULONG ulRealHandle, BOOL bEnable);

/***************************           ISP Parameters Functions     *********************************/

// device ISP parameter
_HW_PU_API BOOL __stdcall IVS_PU_SetISPPara(ULONG ulIdentifyID, LPPU_ISP_PARTICULAR_PARA_S pstISPPara,
                                            ULONG *ulBitmap);
_HW_PU_API BOOL __stdcall IVS_PU_GetISPPara(ULONG ulIdentifyID, LPPU_ISP_PARTICULAR_PARA_S pstISPPara);

// device iris emendation
_HW_PU_API BOOL __stdcall IVS_PU_IrisEmendation(ULONG ulIdentifyID, LPPU_IRIS_EMENDATION_S pstIrisEmendation);

// device flicker mode
_HW_PU_API BOOL __stdcall IVS_PU_GetFlickerMode(ULONG ulIdentifyID, ULONG ulChannelId,
                                                PU_VIDEO_FLICKER_MODE_E *penFlickerMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetFlickerMode(ULONG ulIdentifyID, ULONG ulChannelId,
                                                PU_VIDEO_FLICKER_MODE_E enFlickerMode);

// device AE metering mode
_HW_PU_API BOOL __stdcall IVS_PU_GetAEMeteringMode(ULONG ulIdentifyID, ULONG ulChannelId,
                                                   PU_VIDEO_AEMETERING_MODE_E *penAEMeteringMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetAEMeteringMode(ULONG ulIdentifyID, ULONG ulChannelId,
                                                   PU_VIDEO_AEMETERING_MODE_E enAEMeteringMode);

// device WDR enable state
_HW_PU_API BOOL __stdcall IVS_PU_GetWDR(ULONG ulIdentifyID, ULONG ulChannelId, PU_WDR_SWITCH_MODE_E *penSwitchMode,
                                        ULONG *pulAutoType, ULONG *pulSensitivity);
_HW_PU_API BOOL __stdcall IVS_PU_SetWDR(ULONG ulIdentifyID, ULONG ulChannelId, PU_WDR_SWITCH_MODE_E enSwitchMode,
                                        ULONG ulAutoType, ULONG ulSensitivity);

// device white balance mode  ��ע��:�ӿڷ�����ʹ��IVS_PU_GetISPPara/IVS_PU_SetISPPara���ð�ƽ��
_HW_PU_API BOOL __stdcall IVS_PU_GetWhiteBalanceMode(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulWBMode,
                                                     ULONG *pulRedOffset, ULONG *pulBlueOffset);
_HW_PU_API BOOL __stdcall IVS_PU_SetWhiteBalanceMode(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulWBMode,
                                                     ULONG ulRedOffset, ULONG ulBlueOffset);

// device slow shutter mode
_HW_PU_API BOOL __stdcall IVS_PU_GetSlowShutterMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetSlowShutterMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);

// device automatic exposure response time ��ע��:�ӿڷ���,SDK�ӿڲ�֧��
_HW_PU_API BOOL __stdcall IVS_PU_GetAEResponseTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG *pulAERspTime);
_HW_PU_API BOOL __stdcall IVS_PU_SetAEResponseTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulAERspTime);

// device exposure compensation
_HW_PU_API BOOL __stdcall IVS_PU_GetExposureCompensation(ULONG ulIdentifyID, ULONG ulChannelId,
                                                         ULONG *pulCoefficient);
_HW_PU_API BOOL __stdcall IVS_PU_SetExposureCompensation(ULONG ulIdentifyID, ULONG ulChannelId,
                                                         ULONG ulCoefficient);

// device typical scene
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalSceneMode(ULONG ulIdentifyID, ULONG ulChannelId,
                                                     PU_TYPICAL_SCENE_MODE_E *penMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetTypicalSceneMode(ULONG ulIdentifyID, ULONG ulChannelId,
                                                     PU_TYPICAL_SCENE_MODE_E enMode);

// device typical scene extension
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalSceneModeEx(ULONG ulIdentifyID, PU_ISP_TYPICAL_SCENE_MODE_S *pstParam);
_HW_PU_API BOOL __stdcall IVS_PU_SetTypicalSceneModeEx(ULONG ulIdentifyID, PU_ISP_TYPICAL_SCENE_MODE_S *pstParam);

// device typical scene information
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalSceneList(ULONG ulIdentifyID,
                                                     LPPU_TYPICAL_SCENE_LIST_S pstTypecalSceneList);

// device typical scene information
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalSceneListEx(ULONG ulIdentifyID,
                                                       LPPU_TYPICAL_SCENE_LIST_EX_OUT_S pstTypecalSceneList);

// device typical scene parameter
_HW_PU_API BOOL __stdcall IVS_PU_SetISPProfilePara(ULONG ulIdentifyID, PU_ISP_PROFILES_PARA_S *pstIspProfilePara);
_HW_PU_API BOOL __stdcall IVS_PU_GetISPProfilePara(ULONG ulIdentifyID, PU_ISP_PROFILES_PARA_S *pstIspProfilePara);

// device typical scene plan
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalScenePlan(ULONG ulIdentifyID, LPPU_MONTHS_PLAN_S pstMonthPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetTypicalScenePlan(ULONG ulIdentifyID, LPPU_MONTHS_PLAN_S pstMonthPlan);
// ���ͳ����ƻ����䣬����EndTime
_HW_PU_API BOOL __stdcall IVS_PU_GetTypicalScenePlanV2(ULONG ulIdentifyID, LPPU_MONTHS_PLAN_S pstMonthPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetTypicalScenePlanV2(ULONG ulIdentifyID, LPPU_MONTHS_PLAN_S pstMonthPlan);

// isp profiles link
_HW_PU_API BOOL __stdcall IVS_PU_GetIspProfilesLink(ULONG ulIdentifyID,
                                                    LPPU_ISP_PROFILES_LINK_INFO_S pstIspProfileLink);
_HW_PU_API BOOL __stdcall IVS_PU_SetIspProfilesLink(ULONG ulIdentifyID,
                                                    LPPU_ISP_PROFILES_LINK_INFO_S pstIspProfileLink);

// device blaze restrain
_HW_PU_API BOOL __stdcall IVS_PU_GetBlazeRestrain(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable,
                                                  ULONG *pulBlazeRestrainLevel);
_HW_PU_API BOOL __stdcall IVS_PU_SetBlazeRestrain(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable,
                                                  ULONG ulBlazeRestrainLevel);

// device defog type
_HW_PU_API BOOL __stdcall IVS_PU_GetDefogType(ULONG ulIdentifyID, ULONG ulChannelId,
                                              PU_DEFOG_TYPE_E *penDefogType);
_HW_PU_API BOOL __stdcall IVS_PU_SetDefogType(ULONG ulIdentifyID, ULONG ulChannelId, PU_DEFOG_TYPE_E enDefogType);

// device Noise reduction switch
_HW_PU_API BOOL __stdcall IVS_PU_GetNoiseReductionMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable,
                                                       ULONG *pulCoefficient);
_HW_PU_API BOOL __stdcall IVS_PU_SetNoiseReductionMode(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable,
                                                       ULONG ulCoefficient);

// ���ý���ģʽ
_HW_PU_API BOOL __stdcall IVS_PU_GetNoiseReductionModeEx(ULONG ulIdentifyID,
                                                         PU_NOISE_REDUCTION_S *pstNoiseReduction);
_HW_PU_API BOOL __stdcall IVS_PU_SetNoiseReductionModeEx(ULONG ulIdentifyID,
                                                         PU_NOISE_REDUCTION_S stNoiseReduction);

// �Զ���Ȧ����
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoAperturePara(ULONG ulIdentifyID,
                                                     PU_AUTO_APERTURE_PARA_S *pstAutoAperturePara);
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoAperturePara(ULONG ulIdentifyID,
                                                     PU_AUTO_APERTURE_PARA_S *pstAutoAperturePara);

// �۽��������ù���
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoFocusArea(ULONG ulIdentifyID, PU_PTZ_FOCUSAREA_S stAutoFocusArea);
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoFocusArea(ULONG ulIdentifyID, PU_PTZ_FOCUSAREA_S *pstAutoFocusArea);

/***************************           PTZ Parameters Functions     *********************************/

// device serial port info
_HW_PU_API BOOL __stdcall IVS_PU_GetSerialPortInfo(ULONG ulIdentifyID, LPPU_SERIAL_PORT_PARA_S pstSerialPortPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSerialPortInfo(ULONG ulIdentifyID, LPPU_SERIAL_PORT_PARA_S pstSerialPortPara);

// device ptz preset
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_Preset(ULONG ulIdentifyID, LPPU_PTZ_PRESET_PARA_S pstPtzPresetPara);
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_PresetWithFocusInfo(ULONG ulIdentifyID,
                                                         LPPU_PTZ_PRESET_PARA_EX_S pstPtzPresetPara);
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_GetPresetList(ULONG ulIdentifyID,
                                                   LPPU_PTZ_PRESET_LIST_PARA_S pstPtzPresetList);
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_GetPresetListWithFocusInfo(ULONG ulIdentifyID,
                                                                LPPU_PTZ_PRESET_LIST_PARA_EX_S pstPtzPresetList);

// device ptz control
_HW_PU_API BOOL __stdcall IVS_PU_PTZControl(ULONG ulIdentifyID, LPPU_PTZ_CONTROL_PARA_S pstPtzControlPara);

// device ptz cruise track
_HW_PU_API BOOL __stdcall IVS_PU_PTZ_CruiseTrack(ULONG ulIdentifyID,
                                                 LPPU_PTZ_CRUISE_TRACK_PARA_S pstPtzCruiseTrack);

// device ptz info
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZInfo(ULONG ulIdentifyID, LPPU_PTZ_PARA_S pstPtzPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZInfo(ULONG ulIdentifyID, LPPU_PTZ_PARA_S pstPtzPara);

// device guard position params(only guard preset)
_HW_PU_API BOOL __stdcall IVS_PU_GetGuardPositionPara(ULONG ulIdentifyID,
                                                      LPPU_GUARD_POSITION_PARA_S pstGuardPositionPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetGuardPositionPara(ULONG ulIdentifyID,
                                                      LPPU_GUARD_POSITION_PARA_S pstGuardPositionPara);

// delete device guard position
_HW_PU_API BOOL __stdcall IVS_PU_DelGuardPosition(ULONG ulIdentifyID);

// device guard position params
_HW_PU_API BOOL __stdcall IVS_PU_GetGuardPositionParaEx(ULONG ulIdentifyID,
                                                        LPPU_GUARD_POSITION_PARA_EX_S pstGuardPositionParaEx);
_HW_PU_API BOOL __stdcall IVS_PU_SetGuardPositionParaEx(ULONG ulIdentifyID,
                                                        LPPU_GUARD_POSITION_PARA_EX_S pstGuardPositionParaEx);

// device ptz current location
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCurrentLocation(ULONG ulIdentifyID,
                                                       LPPU_PTZ_CURRENT_LOCATION_S pstCurrentLocation);
_HW_PU_API BOOL __stdcall IVS_PU_RotatePTZLocation(ULONG ulIdentifyID, LPPU_PTZ_CURRENT_LOCATION_S pstDstLocation);

// device ptz current location ex
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCurrentLocationEx(ULONG ulIdentifyID,
                                                         PU_PTZ_CURRENT_LOCATION_EX_S *pstCurrentLocation);
_HW_PU_API BOOL __stdcall IVS_PU_RotatePTZLocationEx(ULONG ulIdentifyID,
                                                     PU_PTZ_CURRENT_LOCATION_EX_S *pstDstLocation);

// device ptz multi motor
_HW_PU_API BOOL __stdcall IVS_PU_PTZMultiMotor(ULONG ulIdentifyID, PU_PTZ_OPCODE_E enDirection, ULONG ulHorSpeed,
                                               ULONG ulVerSpeed);
_HW_PU_API BOOL __stdcall IVS_PU_MultiDirectionMove(ULONG ulIdentifyID, PU_PTZ_OPCODE_E enDirection,
                                                    ULONG ulHorSpeed, ULONG ulVerSpeed);
_HW_PU_API BOOL __stdcall IVS_PU_MultiDirectionMove_V20(ULONG ulIdentifyID,
                                                        PU_PTZ_MULTI_MOTOR_PARA_S *pstPTZMultiMotor);

// device transparent channel
_HW_PU_API BOOL __stdcall IVS_PU_GetTransparentChannelPara(ULONG ulIdentifyID, ULONG ulSerialPort, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetTransparentChannelPara(ULONG ulIdentifyID, ULONG ulSerialPort, BOOL bEnable);
_HW_PU_API BOOL __stdcall IVS_PU_InvokeTransparentCmd(ULONG ulIdentifyID,
                                                      LPPU_TRANSPARENT_CMD_S pstTransparentCmdInfo);

typedef VOID (CALLBACK *pfTransChnDataCallBack)(LONG lHandle, CHAR *szBuffer, LONG lSize, VOID *pUsrData);
_HW_PU_API LONG __stdcall IVS_PU_RecvTransChnDataStart(ULONG ulIdentifyID, ULONG ulSerialPort,
                                                       pfTransChnDataCallBack pfTransChnCBFunc, VOID *pUserData);
_HW_PU_API LONG __stdcall IVS_PU_RecvTransChnDataStop(ULONG ulIdentifyID);

// device infrared light params
_HW_PU_API BOOL __stdcall IVS_PU_GetInfraredLightPara(ULONG ulIdentifyID, LPPU_IRLIGHT_LIST_S pstIRLightPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetInfraredLightPara(ULONG ulIdentifyID, LPPU_IRLIGHT_LIST_S pstIRLightPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetInfraredLightStatus(ULONG ulIdentifyID, LPPU_IRLIGHT_LIST_S pstIRLightPara);

// ����Ʋ���
_HW_PU_API BOOL __stdcall IVS_PU_GetSupplementLightPara(ULONG ulIdentifyID,
                                                        PU_SUPPLEMENT_LIGHT_INFO_S *pstSupplementLightInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetSupplementLightPara(ULONG ulIdentifyID,
                                                        PU_SUPPLEMENT_LIGHT_INFO_S *pstSupplementLightInfo);

// device ptz relative location
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZRelativeLocation(ULONG ulIdentifyID, ULONG ulPtzId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZRelativeLocation(ULONG ulIdentifyID, ULONG ulPtzId, BOOL bEnable);

// device ptz aux mode
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZAuxMode(ULONG ulIdentifyID, ULONG ulPtzId, PU_PTZ_AUX_MODE_E *penAuxMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZAuxMode(ULONG ulIdentifyID, ULONG ulPtzId, PU_PTZ_AUX_MODE_E enAuxMode);

// device ptz camera information
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCameraInfoMode(ULONG ulIdentifyID, ULONG ulPtzId, BOOL *pbEnable);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZCameraInfoMode(ULONG ulIdentifyID, ULONG ulPtzId, BOOL bEnable);

_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCameraInfoModeV20(ULONG ulIdentifyID, ULONG ulPtzId,
                                                         PTZ_OSD_MODE_E *penOSDMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZCameraInfoModeV20(ULONG ulIdentifyID, ULONG ulPtzId,
                                                         PTZ_OSD_MODE_E *penOSDMode);

// device ptz focus mode
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZFocusMode(ULONG ulIdentifyID, ULONG ulPtzId, PU_FOCUS_MODE_E *penFocusMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZFocusMode(ULONG ulIdentifyID, ULONG ulPtzId, PU_FOCUS_MODE_E enFocusMode);

_HW_PU_API BOOL __stdcall IVS_PU_GetPTZFocusModeV20(ULONG ulIdentifyID, PU_PTZ_FOCUS_MODE_S *pstFocusMode);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZFocusModeV20(ULONG ulIdentifyID, PU_PTZ_FOCUS_MODE_S *pstFocusMode);

_HW_PU_API BOOL __stdcall IVS_PU_GetPTZSpeed(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_S *pstPTZSpeed);
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZSpeedEx(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_EX_S *pstPTZSpeed);
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZSpeedAbility(ULONG ulIdentifyID, ULONG ulPTZId,
                                                    PU_PTZ_SPEED_ABILITY *pstPTZSpeedAbility);
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZSpeedLimit(ULONG ulIdentifyID, ULONG ulPTZId,
                                                  PU_PTZ_SPEED_LIMIT_S *pstPTZSpeedLimit);
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZSpeedLimit(ULONG ulIdentifyID, ULONG ulPTZId,
                                                  PU_PTZ_SPEED_LIMIT_S *pstPTZSpeedLimit);

// device ptz presetting_position camera freeze
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZPresetFreezing(ULONG ulIdentifyID, ULONG ulChannelId, BOOL bEnable);
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZPresetFreezing(ULONG ulIdentifyID, ULONG ulChannelId, BOOL *pbEnable);

// ��ֱ��λ
_HW_PU_API BOOL __stdcall IVS_PU_SetVerticalLimit(ULONG ulIdentifyID, PU_VERTICAL_LIMIT_S stVerticalLimit);
_HW_PU_API BOOL __stdcall IVS_PU_GetVerticalLimit(ULONG ulIdentifyID, PU_VERTICAL_LIMIT_S *pstVerticalLimit);

// DDNS
_HW_PU_API BOOL __stdcall IVS_PU_SetDDNSPara(ULONG ulIdentifyID, PU_DDNS_CONF_INFO_S stDDNSpara);
_HW_PU_API BOOL __stdcall IVS_PU_GetDDNSPara(ULONG ulIdentifyID, PU_DDNS_CONF_INFO_S *pstDDNSpara);

// �۽�������Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_SetFocusCompensation(ULONG ulIdentifyID,
                                                      PU_FOCUS_COMPENSATION_S stFocusCompensation);
_HW_PU_API BOOL __stdcall IVS_PU_GetFocusCompensation(ULONG ulIdentifyID,
                                                      PU_FOCUS_COMPENSATION_S *pstFocusCompensation);

// ��ȡ��ͷ��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetCurrentLensInfo(ULONG ulIdentifyID, PU_LENS_INFO_S *pstLensInfo);

/************************      Intelligent Traffic System Functions     ******************************/

// ���Ʋ�����Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPara(ULONG ulIdentifyID, PU_VLPR_PARA_S *pstVLPRPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPara(ULONG ulIdentifyID, PU_VLPR_PARA_S *pstVLPRPara);
// ���Ʋ�����Ϣ����չ�㷨����
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRParaV2(ULONG ulIdentifyID, PU_VLPR_PARA_V2_S *pstVLPRPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRParaV2(ULONG ulIdentifyID, PU_VLPR_PARA_V2_S *pstVLPRPara);
// ���Ʋ�����Ϣ��������չ
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRParaV3(ULONG ulIdentifyID, PU_VLPR_PARA_V3_S *pstVLPRPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRParaV3(ULONG ulIdentifyID, PU_VLPR_PARA_V3_S *pstVLPRPara);

// �ֶ���������ץ��
_HW_PU_API BOOL __stdcall IVS_PU_ManualLicensePlateCapture(ULONG ulIdentifyID,
                                                           PU_MANUAL_LPR_CAPTURE_S *pstManualLprCapture);

// ͼƬ���Ӳ���
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicSynthesisPara(ULONG ulIdentifyID,
                                                         PU_PIC_SYNTHESIS_PARA_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicSynthesisPara(ULONG ulIdentifyID,
                                                         PU_PIC_SYNTHESIS_PARA_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicSynthesisParaV2(ULONG ulIdentifyID,
                                                           PU_PIC_SYNTHESIS_PARA_V2_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicSynthesisParaV2(ULONG ulIdentifyID,
                                                           PU_PIC_SYNTHESIS_PARA_V2_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicSynthesisParaV3(ULONG ulIdentifyID,
                                                           PU_PIC_SYNTHESIS_PARA_V3_S *pstVLPRPicSynthesisPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicSynthesisParaV3(ULONG ulIdentifyID,
                                                           PU_PIC_SYNTHESIS_PARA_V3_S *pstVLPRPicSynthesisPara);

// OSD���Ӳ���(��֧�ֵ羯����)
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicOSDPara(ULONG ulIdentifyID, PU_PIC_OSD_PARA_S *pstVLPRPicOSDPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicOSDPara(ULONG ulIdentifyID, PU_PIC_OSD_PARA_S *pstVLPRPicOSDPara);

_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicOSDParaV2(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V2_S *pstVLPRPicOSDPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicOSDParaV2(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V2_S *pstVLPRPicOSDPara);

_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRPicOSDParaV3(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V3_S *pstVLPRPicOSDPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRPicOSDParaV3(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V3_S *pstVLPRPicOSDPara);

// ͼƬ����ˮӡУ��
_HW_PU_API BOOL __stdcall IVS_PU_CheckVLPRPicWaterMark(CHAR *szFilePath);

// ����ץ�����ݶ���
_HW_PU_API BOOL __stdcall IVS_PU_RecvVLPRDataStart(ULONG ulIdentifyID);
_HW_PU_API BOOL __stdcall IVS_PU_RecvVLPRDataStop(ULONG ulIdentifyID);

/************************      Intelligent outoffocus Functions     ******************************/
// �齹���궨ֵ����
_HW_PU_API BOOL __stdcall IVS_PU_SetOFDStandValueCal(ULONG ulIdentifyID, PU_OUTOFFOCUS_DETECT_PARA_S *pstPara);

/***************************          Alarm Parameters Functions     ********************************/

// device alarm callback function type
typedef LONG (CALLBACK *pfGetAlarmInfoCallBack)(LPPU_ALARM_REPORT_S pstAlarmReport, VOID *pUsrData);
// register device alarm callback function
_HW_PU_API BOOL __stdcall IVS_PU_AlarmInfoStatesCallBack(ULONG ulIdentifyID,
                                                         pfGetAlarmInfoCallBack fAlarmResportCallBack, VOID *pUsrData);

typedef LONG (CALLBACK *pfGetAlarmInfoCallBack_V20)(LPPU_ALARM_REPORT_S pstAlarmReport, VOID *pAlarmInfo,
             ULONG ulAlarmInfoSize, VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_AlarmInfoStatesCallBack_V20(ULONG ulIdentifyID,
                                                             pfGetAlarmInfoCallBack_V20 fAlarmResportCallBack, VOID *pUsrData);

// device alarm params, include: temperature alarm, motion detection alarm, hide alarm
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmPara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, VOID *arg);
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmPara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType, VOID *arg);

_HW_PU_API BOOL __stdcall IVS_PU_SetTemperatureAlarmPara(ULONG ulIdentifyID,
                                                         LPPU_TEMPERATURE_ALARM_PARA_V2_S pstTemperature);
_HW_PU_API BOOL __stdcall IVS_PU_GetTemperatureAlarmPara(ULONG ulIdentifyID,
                                                         LPPU_TEMPERATURE_ALARM_PARA_V2_S pstTemperature);

// set device guard
_HW_PU_API BOOL __stdcall IVS_PU_GuardAlarm(ULONG ulIdentifyID, LPPU_GUARD_PARA_S pstGuardPara);

// get device guard state
_HW_PU_API BOOL __stdcall IVS_PU_GetGuardState(ULONG ulIdentifyID, LPPU_GUARD_STATE_S pstGuardStates);

// get device current temperature
_HW_PU_API BOOL __stdcall IVS_PU_GetTemperature(ULONG ulIdentifyID, LONG *plCurretTemp);

_HW_PU_API BOOL __stdcall IVS_PU_GetTemperature_V20(ULONG ulIdentifyID, LPPU_CURRENT_TEMPERATURE_S pstCurretTemp);

// device switch input and output params
_HW_PU_API BOOL __stdcall IVS_PU_GetDIOPara(ULONG ulIdentifyID, LPPU_DIO_PARA_S pstSwitchDioPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetDIOPara(ULONG ulIdentifyID, LPPU_DIO_PARA_S pstSwitchDioPara);

// device DI state
_HW_PU_API BOOL __stdcall IVS_PU_GetDIState(ULONG ulIdentifyID, ULONG ulInputId, LONG *plInputState);

// device DO state
_HW_PU_API BOOL __stdcall IVS_PU_GetDOState(ULONG ulIdentifyID, ULONG ulOutputId, LONG *plOutputState);
_HW_PU_API BOOL __stdcall IVS_PU_SetDOState(ULONG ulIdentifyID, ULONG ulOutputId, LONG lOutputState);

// device alarm linkage para with alarm type
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmLinkagePara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType,
                                                     ULONG ulAlarmId, LPPU_ALARM_LINKAGE_PARA_S pstAlarmLinkagePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmLinkagePara(ULONG ulIdentifyID, PU_ALARM_TYPE_E enAlarmType,
                                                     ULONG ulAlarmId, LPPU_ALARM_LINKAGE_PARA_S pstAlarmLinkagePara);

// �˳�����
// �����ӿ�δ���ڣ��������ڴ�ԭ�򣬻��ڸýӿڵĲ������˳�����룩ĳЩ�ͺŲ�֧�֡�����֧���������:
// ��1����ɫ��ȡ����IPC6125-WDL-Fb��IPC6126-WDL-E��IPC6224-VRZ-B��IPC6325-WD-VRZ-B��IPC6256-VRZ��IPC6355-VRZ�����⣬�������;���֧�ָù��ܣ�Ԫ���ݷ��͵���ɫ������ΪĬ��ֵ0;
// ��2���˳�����룺
// <1> Cϵ�У���IPC6125-WDL-Fb��IPC6126-WDL-E��IPC6224-VRZ-B��IPC6325-WD-VRZ-B��IPC6256-VRZ��IPC6355-VRZ�����⣬�������;���֧���˳�����빦�ܣ�Ԫ���ݷ��͵���ɫ������ΪĬ��ֵ0;
// <2> Xϵ�к�Mϵ�о���֧���˳�����빦�ܣ�Ԫ���ݷ��͵���ɫ������ΪĬ��ֵ0��

_HW_PU_API BOOL __stdcall IVS_PU_SetHVAlarmPara(ULONG ulIdentifyID, PU_HV_ALARM_PARA_S stAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetHVAlarmPara(ULONG ulIdentifyID, PU_HV_ALARM_PARA_S *pstAlarmPara);

/************************      Intelligent Parameters Functions     ******************************/

// device intelligent switch params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtPara(ULONG ulIdentifyID, LPPU_IGT_ALARM_PARA_S pstIgtAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtPara(ULONG ulIdentifyID, LPPU_IGT_ALARM_PARA_S pstIgtAlarmPara);

// device intelligent tripwire alarm params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtTripwireAlarmPara(ULONG ulIdentifyID,
                                                         LPPU_TW_ALARM_PARA_S pstIgtTwAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtTripwireAlarmPara(ULONG ulIdentifyID,
                                                         LPPU_TW_ALARM_PARA_S pstIgtTwAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_IgtTripwireLineItem(ULONG ulIdentifyID, LPPU_IGT_TW_LINE_ITEM_S pstLineItem);

// device intelligent area detection alarm params
_HW_PU_API BOOL __stdcall IVS_PU_GetIgtAreaDtcAlarmPara(ULONG ulIdentifyID,
                                                        PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType, LPPU_IGT_AREADTC_ALARM_PARA_S pstIgtAreaDtcAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetIgtAreaDtcAlarmPara(ULONG ulIdentifyID,
                                                        PU_IGT_AREA_ALARM_TYPE_E enAlarmAeraType, LPPU_IGT_AREADTC_ALARM_PARA_S pstIgtAreaDtcAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_IgtAreaItem(ULONG ulIdentifyID, LPPU_IGT_AREA_ITEM_S pstAreaItem);

// �ýӿ��ǻ���ѧϰ�������ӿڣ�������V5R19C20�汾֮ǰ���п��ͣ��Լ�V5R19C20�汾֮��Cϵ�п��͵��������
// ������V5R19C20��֮��汾���������͵��øù��ܣ���ʹ��IVS_PU_GetAlarmPara��IVS_PU_SetAlarmPara (�澯���ͣ�PU_ALARM_TYPE_FD_DL)��
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceDetectPara(ULONG ulIdentifyID, PU_FACE_DETC_ALARM_PARA_S *pstFDAlarmPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceDetectPara(ULONG ulIdentifyID, PU_FACE_DETC_ALARM_PARA_S *pstFDAlarmPara);

// ������
_HW_PU_API BOOL __stdcall IVS_PU_GetVHDPara(ULONG ulIdentifyID, PU_VHD_PARA_S *pstVHDPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVHDPara(ULONG ulIdentifyID, PU_VHD_PARA_S *pstVHDPara);

// ����������,����
_HW_PU_API BOOL __stdcall IVS_PU_GetVHDParaEx(ULONG ulIdentifyID, PU_VHD_PARA_EX_S *pstVHDPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVHDParaEx(ULONG ulIdentifyID, PU_VHD_PARA_EX_S *pstVHDPara);

// ��������3559��������
_HW_PU_API BOOL __stdcall IVS_PU_Get3559FaceAttribute(ULONG ulIdentifyID,
                                                      PU_ATTRI_DL_PARAMETER_S *pstFaceAttribute);
_HW_PU_API BOOL __stdcall IVS_PU_Set3559FaceAttribute(ULONG ulIdentifyID,
                                                      PU_ATTRI_DL_PARAMETER_S *pstFaceAttribute);

// 3559����ʶ��Ԫ���ݷ�����������
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceRecogDLAnonymousPara(ULONG ulIdentifyID,
                                                             PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S *pstFaceRecogDLAnonymous);
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceRecogDLAnonymousPara(ULONG ulIdentifyID,
                                                             PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S *pstFaceRecogDLAnonymous);

// ����ʶ�����
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceRecogPara(ULONG ulIdentifyID,
                                                  PU_FACE_RECOGNITION_PARA_S *pstFaceRecogPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceRecogPara(ULONG ulIdentifyID,
                                                  PU_FACE_RECOGNITION_PARA_S *pstFaceRecogPara);

// ����Լ�
_HW_PU_API BOOL __stdcall IVS_PU_SetPTZCheck(ULONG ulIdentifyID, PU_PTZ_CHECK_PARA_S *pstPTZCheck);

_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCheck(ULONG ulIdentifyID, PU_PTZ_CHECK_PARA_S *pstPTZCheck);

// ��ȡ֧����ʷ��¼ʹ��
_HW_PU_API BOOL __stdcall IVS_PU_GetSupportHistory(ULONG ulIdentifyID, PU_DEVICES_SUPPORT_HISTORY_S *pstPara);

// ���á���ȡYTNģʽ�����Կ����������ͼ�����
_HW_PU_API BOOL __stdcall IVS_PU_SetItgtTypeList(ULONG ulIdentifyID, PU_SUPPORT_ITGT_TYPE_LIST_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetItgtTypeList(ULONG ulIdentifyID, PU_SUPPORT_ITGT_TYPE_LIST_S *pstPara);

// ��ȡ�豸֧�ֵĲ�ѯ������
_HW_PU_API BOOL __stdcall IVS_PU_GetSupportQDBList(ULONG ulIdentifyID, PU_HISTORY_SUPPORT_QDB_LIST_S *pstPara);

// ��ȡʵ��OSD��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetRealOsdText(ULONG ulIdentifyID,
                                                LPPU_OSD_PARTICULAR_PARA_EX_OUT_S pstRealOsdPara, PU_CHAR_ENCODE_TYPE_E enCharEncodeType);

// ��ȡ�澯�������ȼ�
_HW_PU_API BOOL __stdcall IVS_PU_GetAlarmLinkPriority(ULONG ulIdentifyID,
                                                      LPPU_ALARM_LINK_PRIORITY_PARA_S pstAlarmLinkPriority);

// ���ø澯�������ȼ�
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmLinkPriority(ULONG ulIdentifyID,
                                                      LPPU_ALARM_LINK_PRIORITY_PARA_S pstAlarmLinkPriority);

// ��ȡ��Ϊ�����������ܸ���
_HW_PU_API BOOL __stdcall IVS_PU_GetVALinkAT(ULONG ulIdentifyID, LPPU_VA_LINK_AT_S pstVALinkAT);

// ������Ϊ�����������ܸ���
_HW_PU_API BOOL __stdcall IVS_PU_SetVALinkAT(ULONG ulIdentifyID, LPPU_VA_LINK_AT_S pstVALinkAT);

// ���ó�ʼ����λ��
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoTrackStartPos(ULONG ulIdentifyID);

// �����ֶ�����Ŀ��
_HW_PU_API BOOL __stdcall IVS_PU_SetATManualTarget(ULONG ulIdentifyID,
                                                   LPPU_VW_ITGT_AT_MANUAL_TARGET_S pstATManualTarget);

// ��ȡ��ͷ��������
_HW_PU_API BOOL __stdcall IVS_PU_GetHumanCountTable(ULONG ulIdentifyID, PU_HUMANCOUNT_TABLE_S *pstHCTable);

// ���������ͷ����
_HW_PU_API BOOL __stdcall IVS_PU_SetHumanCountClear(ULONG ulIdentifyID);

// ��ȡ�ֶ�����/��ѩ
_HW_PU_API BOOL __stdcall IVS_PU_GetManualDefog(ULONG ulIdentifyID, PU_MANAUL_DEFOG_ENABLE_S *pstManualDefog);
// �����ֶ�����/��ѩ
_HW_PU_API BOOL __stdcall IVS_PU_SetManualDefog(ULONG ulIdentifyID, PU_MANAUL_DEFOG_ENABLE_S *pstManualDefog);
// licence�ļ�����
_HW_PU_API BOOL __stdcall IVS_PU_UploadLicenceFile(ULONG ulIdentifyID, PU_LICENCE_FILE_UPLOAD_S *pstLicenceFile);

// ����SDK ֤�鵼��
_HW_PU_API BOOL __stdcall IVS_PU_SetSdkTlsCert(ULONG ulIdentifyID, PU_SDK_TLS_CERT_UPLOAD_S *pstSdkTlsCert);

// ����΢���ڿ���ͼƬFTP�ϴ�����
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRFTPFileUploadPara(ULONG ulIdentifyID,
                                                          PU_VLPR_FTP_UPLOAD_PARA_S *pstFTPFileUpload);
// ��ȡ΢���ڿ���ͼƬFTP�ϴ�����
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRFTPFileUploadPara(ULONG ulIdentifyID,
                                                          PU_VLPR_FTP_UPLOAD_PARA_S *pstFTPFileUpload);

// ����΢���ڿ���ͼƬFTP�ϴ���������
_HW_PU_API BOOL __stdcall IVS_PU_SetVLPRFTPFileUploadParaV2(ULONG ulIdentifyID,
                                                            PU_VLPR_FTP_UPLOAD_PARA_V2_S *pstFTPFileUpload);
// ��ȡ΢���ڿ���ͼƬFTP�ϴ���������
_HW_PU_API BOOL __stdcall IVS_PU_GetVLPRFTPFileUploadParaV2(ULONG ulIdentifyID,
                                                            PU_VLPR_FTP_UPLOAD_PARA_V2_S *pstFTPFileUpload);

// ��ȡITSץ��ͼƬ�б�
_HW_PU_API BOOL __stdcall IVS_PU_GetITSSnapshotPicList(ULONG ulIdentifyID,
                                                       PU_ITS_SNAPSHOT_INQUIRE_S *pstSnapshotInquire, PU_SNAPSHOT_LIST_S *pstSnapshotList);

// ��ȡ�����ò���Ʋ��� ��ע��:�ӿڷ���,SDK�ӿڲ�֧��(SDC 8.0.0֮ǰ�汾��֧��)
_HW_PU_API BOOL __stdcall IVS_PU_GetLampPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LAMP_ATTR_S *pstLampPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetLampPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LAMP_ATTR_S *pstLampPara);

// ��ȡ����Ʋ���(����485�������Ϣ)
_HW_PU_API BOOL __stdcall IVS_PU_GetLampParaEx(ULONG ulIdentifyID, PU_SUPPLEMENT_LAMP_ATTR_EX_S *pstLampPara);
// ���ò���Ʋ���(����485�������Ϣ)
_HW_PU_API BOOL __stdcall IVS_PU_SetLampParaEx(ULONG ulIdentifyID, PU_SUPPLEMENT_LAMP_ATTR_EX_S *pstLampPara);

// ��ȡ485�����״̬
_HW_PU_API BOOL __stdcall IVS_PU_Get485LampStatusPara(ULONG ulIdentifyID,
                                                      PU_STR_485LAMP_STATUS_INFO_S *pstLampPara);

// ��ȡץ����ϸ����/΢��ISP����
_HW_PU_API BOOL __stdcall IVS_PU_GetSnapshotParticularPara(ULONG ulIdentifyID,
                                                           PU_SNAPSHOT_PARTICULAR_PARA_S *pstSnapshotPara);

// ����ץ����ϸ����/΢��ISP����
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapshotParticularPara(ULONG ulIdentifyID,
                                                           PU_SNAPSHOT_PARTICULAR_PARA_S *pstSnapshotPara);

// ITS�ֶ�ץ��(ʹ�����ܴ�����������ͼƬ)
_HW_PU_API BOOL __stdcall IVS_PU_ITSManualSnapshot(ULONG ulIdentifyID,
                                                   PU_ITS_MANUAL_SNAPSHOT_PARA_S *pstManualSnapshotPara);

// ISP��ϸ������չ
_HW_PU_API BOOL __stdcall IVS_PU_GetISPParticularParamEx(ULONG ulIdentifyID,
                                                         PU_ISP_PARTICULAR_PARA_EX_S *pstParam);
_HW_PU_API BOOL __stdcall IVS_PU_SetISPParticularParamEx(ULONG ulIdentifyID,
                                                         PU_ISP_PARTICULAR_PARA_EX_S *pstParam);

// ����ͨ���µ�͸������Ӧ����
_HW_PU_API BOOL __stdcall IVS_PU_SetVWFogAdaptPara(ULONG ulIdentifyID, PU_VW_FOG_ADAPT_PARA_S *pstVWFogAdaptPara);
// ��ȡͨ���µ�͸������Ӧ����
_HW_PU_API BOOL __stdcall IVS_PU_GetVWFogAdaptPara(ULONG ulIdentifyID, PU_VW_FOG_ADAPT_PARA_S *pstVWFogAdaptPara);

// ����ͨ���µ���Ӱ���ٶȣ�����Ӧ����
_HW_PU_API BOOL __stdcall IVS_PU_SetVWSpeedAdaptPara(ULONG ulIdentifyID,
                                                     PU_VW_SPEED_ADAPT_PARA_S *pstVWSpeedAdaptPara);
// ��ȡͨ���µ���Ӱ���ٶȣ�����Ӧ����
_HW_PU_API BOOL __stdcall IVS_PU_GetVWSpeedAdaptPara(ULONG ulIdentifyID,
                                                     PU_VW_SPEED_ADAPT_PARA_S *pstVWSpeedAdaptPara);

// ����ͨ���µı�������Ӧ����
_HW_PU_API BOOL __stdcall IVS_PU_SetVWBacklightAdaptPara(ULONG ulIdentifyID,
                                                         PU_VW_BACKLIGHT_ADAPT_PARA_S *pstVWBacklightAdaptPara);
// ��ȡͨ���µı�������Ӧ����
_HW_PU_API BOOL __stdcall IVS_PU_GetVWBacklightAdaptPara(ULONG ulIdentifyID,
                                                         PU_VW_BACKLIGHT_ADAPT_PARA_S *pstVWBacklightAdaptPara);

// ��ȡǰ���豸��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceInfoEx(ULONG ulIdentifyID, LPPU_DEVICEINFO_EX_S pstDeviceInfo);

// ��ȡǰ��ʵʱ״̬��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceRealStatusInfo(ULONG ulIdentifyID,
                                                         LPPU_DEV_REALSTATUS_INFO_S pstRealStatusInfo);

// Զ������ǰ���豸���ò���
_HW_PU_API BOOL __stdcall IVS_PU_SetDevConfigPara(ULONG ulIdentifyID, PU_DEV_CONFIG_TYPE_E enConfigType,
                                                  VOID *arg);

// Զ�̻�ȡǰ���豸���ò���
_HW_PU_API BOOL __stdcall IVS_PU_GetDevConfigPara(ULONG ulIdentifyID, LPPU_DEV_CONFIG_INFO_S pstDevConfigInfo);

// Զ�̲���ǰ���豸
_HW_PU_API BOOL __stdcall IVS_PU_OptDevice(ULONG ulIdentifyID, PU_DEV_OPT_TYPE_E enOptType);

// �����豸�澯�¼��ص�����
typedef LONG (CALLBACK *pfGetDevAlarmInfoCallBack)(LPPU_DEV_ALARM_INFO_REPORT_S pstDevAlarmReport,
             VOID *pUsrData);
_HW_PU_API BOOL __stdcall IVS_PU_SetAlarmEnventCallBack(ULONG ulIdentifyID,
                                                        pfGetDevAlarmInfoCallBack fDevAlarmResportCallBack, VOID *pUsrData);

// ��ȡ�����㷨��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetItgtAlthmInfo(ULONG ulIdentifyID, LPPU_ITGT_ALTHM_INFO_S pstItgtAlthmInfo);

// ��ȡ�����㷨��Ϣ����
_HW_PU_API BOOL __stdcall IVS_PU_GetItgtAlthmInfoV2(ULONG ulIdentifyID,
                                                    LPPU_ITGT_ALTHM_INFO_EX_S pstItgtAlthmInfo);

// ��ȡISP�㷨��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetISPAlthmInfo(ULONG ulIdentifyID, PU_ISP_ALG_INFO_S *pstISPAlthmInfo);

// ��ȡ�����㷨��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_Get3RdAppAlthmInfo(ULONG ulIdentifyID,
                                                    LPPU_MANAGE_3RD_APP_INFO_S pst3RdAppManageInfo);

// ���������㷨App
_HW_PU_API BOOL __stdcall IVS_PU_Set3RdAppAlthmOptInfo(ULONG ulIdentifyID,
                                                       LPPU_VW_OPERATE_3RD_APP_S pst3RdAppOperateInfo);

// ��ȡlicense������Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetLicServiceInfo(ULONG ulIdentifyID,
                                                   LPPU_ITGT_LIC_SERVICE_INFO_S pstLicServiceInfo);

// ��ȡlicense������Ϣ����
_HW_PU_API BOOL __stdcall IVS_PU_GetLicServiceInfoV2(ULONG ulIdentifyID,
                                                     LPPU_ITGT_LIC_SERVICE_INFO_EX_S pstLicServiceInfo);

// ȥ����license������ȡʧЧ����Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_DeactLicForRevokeKey(ULONG ulIdentifyID,
                                                      LPPU_ITGT_LIC_REVOKE_INFO_S pstLicRevokeInfo);

// ���ܰ�����
_HW_PU_API BOOL __stdcall IVS_PU_ItgtUpgrade(ULONG ulIdentifyID, LPPU_UPGRADE_ITGT_FILE_INFO_S pstItgtFileInfo);
_HW_PU_API BOOL __stdcall IVS_PU_ItgtUpgradeWithSchedule(ULONG ulIdentifyID,
                                                         LPPU_UPGRADE_ITGT_FILE_INFO_S pstItgtFileInfo, pfUpgradeScheduleCallBack fScheduleCallBack, VOID *pUsrData);

// DоƬ����(��ע��:�ӿڷ���,ʹ��IVS_PU_ItgtUpgrade�ӿ�����DоƬ)
_HW_PU_API BOOL __stdcall IVS_PU_DminiUpgrade(ULONG ulIdentifyID, CHAR *pszModelPath);

// 4G �������úͻ�ȡ
_HW_PU_API BOOL __stdcall IVS_PU_GetDialingInfo(ULONG ulIdentifyID,
                                                PU_DIALING_CONFIG_INFO_S *pstDialingConfigInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetDialingInfo(ULONG ulIdentifyID,
                                                PU_DIALING_CONFIG_INFO_S *pstDialingConfigInfo);
_HW_PU_API BOOL __stdcall IVS_PU_GetDialingStatus(ULONG ulIdentifyID, PU_DIALING_STATUS_INFO_S *pstDialingStatus);
_HW_PU_API BOOL __stdcall IVS_PU_SetManualDialing(ULONG ulIdentifyID, PU_MANUL_DIALING_S *pstManulDialing);
_HW_PU_API BOOL __stdcall IVS_PU_GetAutoDialingPlan(ULONG ulIdentifyID,
                                                    PU_AUTO_DIALING_PLAN_S *pstAutoDialingPlan);
_HW_PU_API BOOL __stdcall IVS_PU_SetAutoDialingPlan(ULONG ulIdentifyID,
                                                    PU_AUTO_DIALING_PLAN_S *pstAutoDialingPlan);
_HW_PU_API BOOL __stdcall IVS_PU_GetWhiteLists(ULONG ulIdentifyID, PU_SMS_WHITE_LISTS_S *pstSmsWhiteLists);
_HW_PU_API BOOL __stdcall IVS_PU_SetWhiteLists(ULONG ulIdentifyID, PU_SMS_WHITE_LISTS_S *pstSmsWhiteLists);
// 4G����(��ע��:�ӿڷ���,ʹ��IVS_PU_ItgtUpgrade�ӿ�����4G)
_HW_PU_API BOOL __stdcall IVS_PU_LTEUpgrade(ULONG ulIdentifyID, CHAR *pszModelPath);

// �����⵼�룬����IPC�汾:V5R19C30 TR5�汾�Լ�֮ǰ
_HW_PU_API BOOL __stdcall IVS_PU_ImportFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_IMPORT_S *pstFaceLibInfo);

// �����⵼��ӿ�����(�����������ٶ�)����IVS_PU_CheckImportStatus���ʹ�ã�����IPC�汾:V5R19C30 TR6�汾�Լ�֮��
_HW_PU_API BOOL __stdcall IVS_PU_ImportFaceLibEx(ULONG ulIdentifyID, PU_FACE_LIB_IMPORT_S *pstFaceLibInfo);
// ����������ȡ�����IVS_PU_CheckImportStatus���ʹ��
_HW_PU_API BOOL __stdcall IVS_PU_FeatureExtract(ULONG ulIdentifyID, PU_FACE_FEATURE_EXTRACT_S *pstExtractStatus);
// �����������������IVS_PU_CheckImportStatus���ʹ��
_HW_PU_API BOOL __stdcall IVS_PU_ExportFaceLibFeature(ULONG ulIdentifyID, PU_FACE_FEATURE_EXTRACT_S *pstExtractFeat);

// ��ʱ��ѯ�����⵼��״̬����ʱ��ѯ������ȡ״̬
_HW_PU_API BOOL __stdcall IVS_PU_CheckImportStatus(ULONG ulIdentifyID, PU_FACE_LIB_STATUS_S *pstFaceLibStatus);

// ����ʶ��ƥ���ʼ��㺯��
_HW_PU_API BOOL __stdcall IVS_PU_CalcAdvanceFeatureMatch(PU_FACE_FEATURE_MATCH_S *pstFaceMatch);

//ͼƬ����ֵ��ȡ������ֵͨ��Ԫ�����ϱ�
_HW_PU_API BOOL __stdcall IVS_PU_PicFeatureExtract(ULONG ulIdentifyID, PU_PIC_FEATURE_EXTRACT_S *pstPicExtract);

// ��ӵ�������
_HW_PU_API BOOL __stdcall IVS_PU_AddOneFace(ULONG ulIdentifyID, PU_FACE_INFO_ADD_S *pstOneFaceInfo);

// ��ӵ�����������չͼƬ���ֶ�
_HW_PU_API BOOL __stdcall IVS_PU_AddOneFaceV2(ULONG ulIdentifyID, PU_FACE_INFO_ADD_S *pstOneFaceInfo,
                                              CHAR *pcPicname);

// ��ȡ��������Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_GET_S *pstGetFaceLib);

// ��ѯ������Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_FindFaceInfo(ULONG ulIdentifyID, PU_FACE_INFO_FIND_S *pstFindFaceInfo);

// ������������Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_SET_S *faceLibInfo);

// ɾ��������Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_DelFaceInfo(ULONG ulIdentifyID, PU_FACE_INFO_DELETE_S *delFaceInfo);

// �޸�������Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_FaceInfoModify(ULONG ulIdentifyID, PU_FACE_INFO_MODIFY_S *modifyFaceInfo);

// ��ȡ����ͼƬ
_HW_PU_API BOOL __stdcall IVS_PU_GetFacePicture(ULONG ulIdentifyID, PU_FACE_PIC_GET_S *pstGetFacePic);

// ��ȡ���������⣬��ע��:�ӿڷ�����SDK�ӿڲ�֧��
// _HW_PU_API BOOL __stdcall IVS_PU_GetFeatureLib(ULONG ulIdentifyID, PU_FACE_FEATURE_GET_S *pstGetFeature);

// ��ȡITS�������
_HW_PU_API BOOL __stdcall IVS_PU_GetITSExtraDevicePara(ULONG ulIdentifyID, PU_ITS_DEV_SPEC_S *pstExtraDevPara);

// ����ITS�������
_HW_PU_API BOOL __stdcall IVS_PU_SetITSExtraDevicePara(ULONG ulIdentifyID, PU_ITS_DEV_SPEC_S *pstExtraDevPara);

// ��ȡITS�������
_HW_PU_API BOOL __stdcall IVS_PU_GetITSExtraDeviceParaV2(ULONG ulIdentifyID,
                                                         PU_ITS_DEV_SPEC_V2_S *pstExtraDevPara);

// ����ITS�������
_HW_PU_API BOOL __stdcall IVS_PU_SetITSExtraDeviceParaV2(ULONG ulIdentifyID,
                                                         PU_ITS_DEV_SPEC_V2_S *pstExtraDevPara);

// ��ȡ/���ó�����ͳ��
_HW_PU_API BOOL __stdcall IVS_PU_GetITSFlowRateParam(ULONG ulIdentifyID, PU_ITS_FLOW_RATE_PARA_S *pstFlowRatePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSFlowRateParam(ULONG ulIdentifyID, PU_ITS_FLOW_RATE_PARA_S *pstFlowRatePara);

/************add ���***************/
// ��ȡ/���ú����ǿ����
_HW_PU_API BOOL __stdcall IVS_PU_GetRLCropEnhancePara(ULONG ulIdentifyID, PU_RL_CROP_ENHANCE_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetRLCropEnhancePara(ULONG ulIdentifyID, PU_RL_CROP_ENHANCE_PARA_S *pstPara);
// ��ȡ/���ú����ǿ��������
_HW_PU_API BOOL __stdcall IVS_PU_GetRLCropEnhanceParaV2(ULONG ulIdentifyID, PU_RL_CROP_ENHANCE_PARA_V2_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetRLCropEnhanceParaV2(ULONG ulIdentifyID, PU_RL_CROP_ENHANCE_PARA_V2_S *pstPara);

// ��ȡ/���ò������ò���
_HW_PU_API BOOL __stdcall IVS_PU_GetITSSpeedMeasureParam(ULONG ulIdentifyID,
                                                         PU_ITS_SPEED_MEASURE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSSpeedMeasureParam(ULONG ulIdentifyID,
                                                         PU_ITS_SPEED_MEASURE_PARAM_S *pstPara);

// ��ȡ/������Ƶ�羯��������
_HW_PU_API BOOL __stdcall IVS_PU_GetITSTGateWayLaneParam(ULONG ulIdentifyID,
                                                         PU_ITS_TGATEWAY_LANE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSTGateWayLaneParam(ULONG ulIdentifyID,
                                                         PU_ITS_TGATEWAY_LANE_PARAM_S *pstPara);

// ��ȡ/������Ƶ�羯���ץ�Ĳ���
_HW_PU_API BOOL __stdcall IVS_PU_GetITSTGateWaySnapTypeParam(ULONG ulIdentifyID,
                                                             PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSTGateWaySnapTypeParam(ULONG ulIdentifyID,
                                                             PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_S *pstPara);

// ��ȡ/������Ƶ�羯���ץ�Ĳ�������
_HW_PU_API BOOL __stdcall IVS_PU_GetITSTGateWaySnapTypeParamV2(ULONG ulIdentifyID,
                                                               PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_V2_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSTGateWaySnapTypeParamV2(ULONG ulIdentifyID,
                                                               PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_V2_S *pstPara);

// ��ȡ/���û��Ƽ���߲���
_HW_PU_API BOOL __stdcall IVS_PU_GetITSDtLineParam(ULONG ulIdentifyID, PU_ITS_DT_LINE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSDtLineParam(ULONG ulIdentifyID, PU_ITS_DT_LINE_PARAM_S *pstPara);

// ��ȡ/���û��Ƽ�����������
_HW_PU_API BOOL __stdcall IVS_PU_GetITSDtLineParamV2(ULONG ulIdentifyID, PU_ITS_DT_LINE_PARAM_V2_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSDtLineParamV2(ULONG ulIdentifyID, PU_ITS_DT_LINE_PARAM_V2_S *pstPara);

// ��ȡ/���ñ���SIM������
_HW_PU_API BOOL __stdcall IVS_PU_GetSIMPhoneNum(ULONG ulIdentifyID, PU_SIM_PHONE_NUM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetSIMPhoneNum(ULONG ulIdentifyID, PU_SIM_PHONE_NUM_S *pstPara);

// ��ȡ�豸ESN��
_HW_PU_API BOOL __stdcall IVS_PU_GetDeviceESNInfo(ULONG ulIdentifyID, PU_DEVICE_ESN_INFO_S *pstPara);
// һ�����ö��㷨�л�
_HW_PU_API BOOL __stdcall IVS_PU_SetITGEMode(ULONG ulIdentifyID, PU_ITGT_MODE_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetITGEMode(ULONG ulIdentifyID, PU_ITGT_MODE_S *pstPara);

/************add Ф���𡢳³�***************/
// ��ȡ�羯�����˴�����źŵƲ���
_HW_PU_API BOOL __stdcall IVS_PU_GetEpoliceSigLightPara(ULONG ulIdentifyID,
                                                        PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM_S *pstPara);
// ���õ羯�����˴�����źŵƲ���
_HW_PU_API BOOL __stdcall IVS_PU_SetEpoliceSigLightPara(ULONG ulIdentifyID,
                                                        PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM_S *pstPara);

// ��ȡ�羯ģ����̵Ʋ���
_HW_PU_API BOOL __stdcall IVS_PU_GetITSEpoliceSimTrafficLightParam(ULONG ulIdentifyID,
                                                                   PU_ITS_SIM_TRAFFIC_LIGHT_PARAM_S *pstPara);

// ���õ羯ģ����̵Ʋ���
_HW_PU_API BOOL __stdcall IVS_PU_SetITSEpoliceSimTrafficLightParam(ULONG ulIdentifyID,
                                                                   PU_ITS_SIM_TRAFFIC_LIGHT_PARAM_S *pstPara);

// ��ȡ�羯ץ�����Ͳ���
_HW_PU_API BOOL __stdcall IVS_PU_GetEPoliceSnapTypePara(ULONG ulIdentifyID,
                                                        PU_ITS_EPOLICE_SNAP_TYPE_PARAM_S *pstEPoliceSnapTypePara);

// ���õ羯ץ�����Ͳ���
_HW_PU_API BOOL __stdcall IVS_PU_SetEPoliceSnapTypePara(ULONG ulIdentifyID,
                                                        PU_ITS_EPOLICE_SNAP_TYPE_PARAM_S *pstEPoliceSnapTypePara);

// ��ȡ�羯�����˴����ץ�����Ͳ�������
_HW_PU_API BOOL __stdcall IVS_PU_GetEPoliceSnapTypeParaV2(ULONG ulIdentifyID,
                                                          PU_ITS_EPOLICE_SNAP_TYPE_PARAM_V2_S *pstEPoliceSnapTypePara);

// ���õ羯�����˴����ץ�����Ͳ�������
_HW_PU_API BOOL __stdcall IVS_PU_SetEPoliceSnapTypeParaV2(ULONG ulIdentifyID,
                                                          PU_ITS_EPOLICE_SNAP_TYPE_PARAM_V2_S *pstEPoliceSnapTypePara);

// ��ȡ�����ץ�����Ͳ�������
_HW_PU_API BOOL __stdcall IVS_PU_GetPassageWaySnapTypePara(ULONG ulIdentifyID,
                                                           PU_ITS_PASSAGEWAY_SNAP_TYPE_PARAM_S *pstPassageWaySnapTypePara);

// ���ó����ץ�����Ͳ�������
_HW_PU_API BOOL __stdcall IVS_PU_SetPassageWaySnapTypePara(ULONG ulIdentifyID,
                                                           PU_ITS_PASSAGEWAY_SNAP_TYPE_PARAM_S *pstPassageWaySnapTypePara);

// ��ȡ�羯��������
_HW_PU_API BOOL __stdcall IVS_PU_GetEPoliceLanePara(ULONG ulIdentifyID, PU_ITS_LANE_PARAM_S *pstEPoliceLanePara);

// ���õ羯��������
_HW_PU_API BOOL __stdcall IVS_PU_SetEPoliceLanePara(ULONG ulIdentifyID, PU_ITS_LANE_PARAM_S *pstEPoliceLanePara);

// ��ȡ����ڳ�������
_HW_PU_API BOOL __stdcall IVS_PU_GetPassageWayLanePara(ULONG ulIdentifyID,
                                                       PU_ITS_PASSAGEWAY_LANE_PARAM_S *pstPassageWayLanePara);

// ���ó���ڳ�������
_HW_PU_API BOOL __stdcall IVS_PU_SetPassageWayLanePara(ULONG ulIdentifyID,
                                                       PU_ITS_PASSAGEWAY_LANE_PARAM_S *pstPassageWayLanePara);

// ��ȡ���������˴������������
_HW_PU_API BOOL __stdcall IVS_PU_GetEPoliceFaceDetectPara(ULONG ulIdentifyID, PU_PEDRUNRED_FACE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetEPoliceFaceDetectPara(ULONG ulIdentifyID, PU_PEDRUNRED_FACE_PARAM_S *pstPara);

// ��ȡ���������˴���Ƽ���߲���
_HW_PU_API BOOL __stdcall IVS_PU_GetPedRunRedDtLinePara(ULONG ulIdentifyID,
                                                        PU_ITS_PEDRUNRED_DT_LINE_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetPedRunRedDtLinePara(ULONG ulIdentifyID,
                                                        PU_ITS_PEDRUNRED_DT_LINE_PARAM_S *pstPara);

// ��ȡITS Ӧ��ģʽ����
_HW_PU_API BOOL __stdcall IVS_PU_GetITSBusinessTypePara(ULONG ulIdentifyID,
                                                        PU_ITS_BUSINESS_TYPE_PARA_S *pstITSBusinessTypePara);

// ��ȡ/����Υ���ֵ����
_HW_PU_API BOOL __stdcall IVS_PU_GetITSIllegalDicPara(ULONG ulIdentifyID, PU_ITS_ILLEGAI_DIC_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSIllegalDicPara(ULONG ulIdentifyID, PU_ITS_ILLEGAI_DIC_PARAM_S *pstPara);

// ��ȡΥ���ֵ�Ĭ�ϲ���
_HW_PU_API BOOL __stdcall IVS_PU_GetDefaultITSIllegalDicPara(ULONG ulIdentifyID,
                                                             PU_ITS_ILLEGAI_DIC_PARAM_S *pstPara);

// ��ȡ/���ý�ͨ����㷨����
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeAlgParams(ULONG ulIdentifyID, PU_TD_ALG_PARAMS_S *pstAlgParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeAlgParams(ULONG ulIdentifyID, PU_TD_ALG_PARAMS_S *pstAlgParams);

// ��ȡ/���ý�ͨ����㷨����V2
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeAlgParamsV2(ULONG ulIdentifyID, PU_TD_ALG_PARAMSV2_S *pstAlgParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeAlgParamsV2(ULONG ulIdentifyID, PU_TD_ALG_PARAMSV2_S *pstAlgParams);

// ���ý�ͨ����ֶ������Ļλ��
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeManualDetectionPos(ULONG ulIdentifyID,
                                                                  PU_TD_MANUAL_DETECTION_POS_S *pstPosParams);

// ���ý�ͨ�����ʱ��������
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeTimingLockParam(ULONG ulIdentifyID,
                                                               PU_TD_TIMING_LOCK_PARAMS_S *pstTimingLockPara);

// ���ý�ͨ�����������
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeUlockParam(ULONG ulIdentifyID, PU_TD_UNLOCK_PARAMS_S *pstUlockPara);

// ��ͨ���ת����ĳ����
_HW_PU_API BOOL __stdcall IVS_PU_TrafficDomeMoveToScene(ULONG ulIdentifyID,
                                                        PU_TD_SCENE_MOVE_TO_SCENE_S *pstMoveToScene);

// ��ȡ/���ý�ͨ����ֶ�Υͣ����㷨����
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeManualDetectionParams(ULONG ulIdentifyID,
                                                                     PU_TD_MANUAL_DETECTION_PARAMS_S *pstManualDecetionParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeManualDetectionParams(ULONG ulIdentifyID,
                                                                     PU_TD_MANUAL_DETECTION_PARAMS_S *pstManualDecetionParams);

// ��ȡ/���ý�ͨ����ֶ�Υͣ����㷨����V2
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeManualDetectionParamsV2(ULONG ulIdentifyID,
                                                                       PU_TD_MANUAL_DETECTION_PARAMSV2_S *pstManualDecetionParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeManualDetectionParamsV2(ULONG ulIdentifyID,
                                                                       PU_TD_MANUAL_DETECTION_PARAMSV2_S *pstManualDecetionParams);

// ��ȡ/���ý�ͨ���Ѳ���ƻ�����
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeTourPlanParams(ULONG ulIdentifyID,
                                                              PU_TD_TOUR_PLAN_PARAMS_S *pstTourPlanParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeTourPlanParams(ULONG ulIdentifyID,
                                                              PU_TD_TOUR_PLAN_PARAMS_S *pstTourPlanParams);

// ��ȡ/���ý�ͨ�������Ӧ�ò���
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneAppParams(ULONG ulIdentifyID,
                                                              PU_TD_SCENE_APP_PARAMS_S *pstSceneAppParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeSceneAppParams(ULONG ulIdentifyID,
                                                              PU_TD_SCENE_APP_PARAMS_S *pstSceneAppParams);

// ��ȡ/���ý�ͨ�������Ӧ�ò���V2
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneAppParamsV2(ULONG ulIdentifyID,
                                                                PU_TD_SCENE_APP_PARAMSV2_S *pstSceneAppParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeSceneAppParamsV2(ULONG ulIdentifyID,
                                                                PU_TD_SCENE_APP_PARAMSV2_S *pstSceneAppParams);

// ��ȡ/���ý�ͨ��Υ�����ܷ�������
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeIllegalIntelligentParams(ULONG ulIdentifyID,
                                                                        PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS_S *pstTDomeIllegalIntelligentParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeIllegalIntelligentParams(ULONG ulIdentifyID,
                                                                        PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS_S *pstTDomeIllegalIntelligentParams);

// ��ȡ��ͨ��Υ�����ܷ���Ĭ�ϲ���
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeIllegalIntelligentDeFaultParams(ULONG ulIdentifyID,
                                                                               PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS_S *pstTDomeIllegalIntelligentParams);

// ��ȡ/���ý�ͨ���������������
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneBaseParams(ULONG ulIdentifyID,
                                                               PU_TD_SCENE_BASE_PARAMS_S *pstSceneBaseParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeSceneBaseParams(ULONG ulIdentifyID,
                                                               PU_TD_SCENE_BASE_PARAMS_S *pstSceneBaseParams);

// ��ȡ/���ý�ͨ�����������������չ
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneBaseParamsV2(ULONG ulIdentifyID,
                                                                 PU_TD_SCENE_BASE_PARAMSV2_S *pstSceneBaseParams);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrafficDomeSceneBaseParamsV2(ULONG ulIdentifyID,
                                                                 PU_TD_SCENE_BASE_PARAMSV2_S *pstSceneBaseParams);

// ��ȡ��ͨ���Ѳ������ʹ����Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetTrafficDomeSceneEnableInfo(ULONG ulIdentifyID,
                                                               PU_TD_SCENE_ENABLE_INFO_S *pstSceneEnableInfo);
/* ǹ������ */
// master slave group para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveGroupPara(ULONG ulIdentifyID,
                                                         PU_MASTER_SLAVE_GROUP_PARA_S *pstMasterSlaveGroupPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveGroupPara(ULONG ulIdentifyID,
                                                         PU_MASTER_SLAVE_PER_GROUP_PARA_S *pstMasterSlavePerGroupPara);

// master slave auth para
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveAuthPara(ULONG ulIdentifyID,
                                                        PU_MASTER_SLAVE_AUTH_PARA_S *pstMasterSlaveAuthPara);

// master slave communication para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveCommunicationPara(ULONG ulIdentifyID,
                                                                 PU_MASTER_SLAVE_COMMUNICATION_PARA_S *pstMasterSlaveCommunicationPara);

// master slave track para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveTrackPara(ULONG ulIdentifyID,
                                                         PU_MASTER_SLAVE_TRACK_PARA_S *pstMasterSlaveTrackPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveTrackPara(ULONG ulIdentifyID,
                                                         PU_MASTER_SLAVE_TRACK_PARA_S *pstMasterSlaveTrackPara);

// master slave watch point para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveWatchPointPara(ULONG ulIdentifyID,
                                                              PU_PTZ_CURRENT_LOCATION_S *pstMasterSlaveWatchPointPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveWatchPointPara(ULONG ulIdentifyID,
                                                              PU_PTZ_CURRENT_LOCATION_S *pstMasterSlaveWatchPointPara);

// master slave locate para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveLocateConfig(ULONG ulIdentifyID,
                                                            PU_MASTER_SLAVE_LOCATE_CONFIG_S *pstMasterSlaveLocateConfig);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveLocateConfig(ULONG ulIdentifyID,
                                                            PU_MASTER_SLAVE_LOCATE_CONFIG_S *pstMasterSlaveLocateConfig);

// start master slave locate
_HW_PU_API BOOL __stdcall IVS_PU_StartMasterSlaveLocate(ULONG ulIdentifyID,
                                                        PU_MASTER_SLAVE_LOCATE_PARA_S *pstMasterSlaveLocatePara);

// master slave calibration para
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveCalibrationPara(ULONG ulIdentifyID,
                                                               PU_MASTER_SLAVE_CALIBRATION_S *pstMasterSlaveCalibrationPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterSlaveCalibrationPara(ULONG ulIdentifyID,
                                                               PU_MASTER_SLAVE_CALIBRATION_S *pstMasterSlaveCalibrationPara);

// master slave calibration status
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterSlaveCalibrationStatus(ULONG ulIdentifyID,
                                                                 PU_MASTER_SLAVE_CALIBRATION_STATUS_S *pstMasterSlaveCalibrationStatus);

// master slave track para
_HW_PU_API BOOL __stdcall IVS_PU_MasterSlaveManualTrack(ULONG ulIdentifyID,
                                                        PU_MASTER_SLAVE_MANUAL_TRACK_PARA_S *pstMasterSlaveManualTrackPara);

// ��ͼ �Զ��궨ʹ��: ��ʼ�궨��ȡ���궨
_HW_PU_API BOOL __stdcall IVS_PU_StartCalibration(ULONG ulIdentifyID, PU_OMNI_CALIBRATE_SWITCH_S *pstSwitchPara);

// ������Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetTrackInfo(ULONG ulIdentifyID, PU_TRACK_INFO_S *pstInfo);
_HW_PU_API BOOL __stdcall IVS_PU_SetTrackInfo(ULONG ulIdentifyID, PU_TRACK_INFO_S *pstInfo);

// ITSβ�����в���
_HW_PU_API BOOL __stdcall IVS_PU_GetITSRestrictPara(ULONG ulIdentifyID, PU_ITS_RESTRICTED_PARAM_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetITSRestrictPara(ULONG ulIdentifyID, PU_ITS_RESTRICTED_PARAM_S *pstPara);
// ������ͳ��
_HW_PU_API BOOL __stdcall IVS_PU_GetVlprTrafficStat(ULONG ulIdentifyID, PU_VLPR_TRAFFIC_STATISTICS_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVlprTrafficStat(ULONG ulIdentifyID, PU_VLPR_TRAFFIC_STATISTICS_S *pstPara);

// hot map para
_HW_PU_API BOOL __stdcall IVS_PU_GetHotMapPara(ULONG ulIdentifyID, PU_HOTMAP_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetHotMapPara(ULONG ulIdentifyID, PU_HOTMAP_PARA_S *pstPara);

// hot map guard plan
_HW_PU_API BOOL __stdcall IVS_PU_GetHotMapPlan(ULONG ulIdentifyID, PU_HOTMAP_GUARD_PLAN_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetHotMapPlan(ULONG ulIdentifyID, PU_HOTMAP_GUARD_PLAN_PARA_S *pstPara);

// query hot map table
_HW_PU_API BOOL __stdcall IVS_PU_QueryHotMapTable(ULONG ulIdentifyID, PU_HOTMAP_TABLE_PARA_S *pstPara);

// clear hot map table
_HW_PU_API BOOL __stdcall IVS_PU_ClearHotMapData(ULONG ulIdentifyID, ULONG ulChannelId);
/* �������Զ����� */
_HW_PU_API BOOL __stdcall IVS_PU_GetVHDAutoTrackPara(ULONG ulIdentifyID, PU_ITGT_VHD_AUTO_TRACK_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetVHDAutoTrackPara(ULONG ulIdentifyID, PU_ITGT_VHD_AUTO_TRACK_PARA_S *pstPara);
/* �������ֶ����� */
_HW_PU_API BOOL __stdcall IVS_PU_SetVHDManualTrackPara(ULONG ulIdentifyID,
                                                       PU_ITGT_VHD_MANUAL_TRACK_PARA_S *pstPara);
/* ����OSD���� */
_HW_PU_API BOOL __stdcall IVS_PU_SetFaceOsdPara(ULONG ulIdentifyID, PU_FACE_OSD_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetFaceOsdPara(ULONG ulIdentifyID, PU_FACE_OSD_PARA_S *pstPara);

/* ������OSD���� */
_HW_PU_API BOOL __stdcall IVS_PU_SetVhdOsdPara(ULONG ulIdentifyID, PU_VHD_OSD_PARA_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_GetVhdOsdPara(ULONG ulIdentifyID, PU_VHD_OSD_PARA_S *pstPara);

/*******************************************************************************************************************/
/* SDK Function Declaration */
/*******************************************************************************************************************/
//����Ԫ���ݽ����ӿ�(���������ͽ�����һ��ֻ������һ�ֶ������Ͱ��������ݣ��������taget֮�䲻���֣�һ��ȫ������)
_HW_PU_API BOOL __stdcall IVS_User_GetMetaData(CHAR *pFBuffer, ULONG ulFBLength, LAYER_TWO_TYPE eLayTwo,
                                               PU_META_DATA **pstMetaData);
_HW_PU_API VOID __stdcall IVS_User_FreeMetaData(PU_META_DATA **ppstMetaData);

//����Ԫ���ݽ����ӿ�(һ�ν�����Ԫ����֡����������, ���target֮���������)
_HW_PU_API BOOL __stdcall IVS_User_GetMetaDataAll(CHAR *pFBuffer, ULONG ulFBLength, PU_META_DATA_ALL *pstMetaData);
_HW_PU_API VOID __stdcall IVS_User_FreeMetaDataAll(PU_META_DATA_ALL *pstMetaData);

// ���Эͬ
_HW_PU_API ULONG __stdcall IVS_PU_AI_SetOption(ULONG ulIdentifyID, PU_AI_LEVEL_E bussLevel, PU_AI_NAME_E bussName,
                                               const void *param, UINT param_len);

_HW_PU_API ULONG __stdcall IVS_PU_AI_GetOption(ULONG ulIdentifyID, PU_AI_LEVEL_E bussLevel, PU_AI_NAME_E bussName,
                                               void *param, UINT *pparam_len);

// ����/��ȡONVIF����Э������
_HW_PU_API ULONG __stdcall IVS_PU_SetOnvifTransProtocol(ULONG ulIdentifyID,
                                                        PU_ONVIF_TRANS_PROTOCOL_TYPE_S *pstPara);
_HW_PU_API ULONG __stdcall IVS_PU_GetOnvifTransProtocol(ULONG ulIdentifyID,
                                                        PU_ONVIF_TRANS_PROTOCOL_TYPE_S *pstPara);

// ����/��ȡREST����Э������
_HW_PU_API ULONG __stdcall IVS_PU_SetRestTransProtocol(ULONG ulIdentifyID,
                                                       PU_REST_SUPPORT_PROTOCOL_PARAM_S *pstPara);
_HW_PU_API ULONG __stdcall IVS_PU_GetRestTransProtocol(ULONG ulIdentifyID,
                                                       PU_REST_SUPPORT_PROTOCOL_PARAM_S *pstPara);
// JSON��ʽ������ȡ���������������Ƿ�֧��
_HW_PU_API ULONG __stdcall IVS_PU_GetUpgradeAbility(ULONG ulIdentifyID, LPPU_UPGARDE_JSON_INPUT_ST pInputParam);

// �°汾RSA�����Ƿ�֧��
_HW_PU_API BOOL __stdcall IVS_PU_GetRsaAbility(ULONG ulIdentifyID, LPPU_RSA_ABILITY_S pstPara);

// ��ȡTLS 433����״̬
_HW_PU_API BOOL __stdcall IVS_PU_OprTlsSwitch(ULONG ulIdentifyID, LPPU_TLS_SWITCH_S pstPara);

// JSON��ʽ�������û�ȡ�ӿ�
_HW_PU_API ULONG __stdcall IVS_PU_JsonConfig_Option(ULONG ulIdentifyID, LPPU_CONFIG_JSON_INPUT_ST pInputParam,
                                                    LPPU_CONFIG_JSON_CONFIG_OUTPUT_ST pOutputParam);

// JSON��ʽ�澯�ص�����
typedef LONG (CALLBACK *pfJsonMsgCallBack)(ULONG ulIdentifyID, CHAR *pMsginfo, DWORD dwBufLen,
             void *pUserData);
_HW_PU_API ULONG __stdcall IVS_PU_SetJsonMessageCallBack(ULONG ulIdentifyID, pfJsonMsgCallBack fMessageCallBack,
                                                         void *pUserData);

// ��ɽJSON��Ϣ͸��ͨ��
_HW_PU_API ULONG __stdcall IVS_PU_PlatformTaskAccept(ULONG ulIdentifyID, CHAR *pTaskInfo);

//���Ķ����ش�ͼƬ�ӿ�
_HW_PU_API BOOL __stdcall IVS_PU_SubsribeAutoTransPic(ULONG ulIdentifyID);
//ȡ�����Ķ����ش�ͼƬ�ӿ�
_HW_PU_API BOOL __stdcall IVS_PU_CancelAutoTransPic(ULONG ulIdentifyID);

// ����/��ȡǧѰGPS��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetQXGPSInfo(ULONG ulIdentifyID, PU_QXGPS_INFO_S *pstPara);
_HW_PU_API BOOL __stdcall IVS_PU_SetQXGPSInfo(ULONG ulIdentifyID, PU_QXGPS_INFO_S *pstPara);

// ��ȡǧѰGPS״̬
_HW_PU_API BOOL __stdcall IVS_PU_GetQXGPSStatus(ULONG ulIdentifyID, PU_QXGPS_STATUS_S *pstPara);

//��ȡ������ ����Կ �Զ����²���
_HW_PU_API BOOL __stdcall IVS_PU_GetMasterKeyAutoUpdatePara(ULONG ulIdentifyID, PU_AESKEY_AUTO_UPDATE_PARA_S *stAeskeyAutoUpdatePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetMasterKeyAutoUpdatePara(ULONG ulIdentifyID, PU_AESKEY_AUTO_UPDATE_PARA_S stAeskeyAutoUpdatePara);

//��ȡ������ ������Կ �Զ����²���
_HW_PU_API BOOL __stdcall IVS_PU_GetWorkKeyAutoUpdatePara(ULONG ulIdentifyID, PU_AESKEY_AUTO_UPDATE_PARA_S *stAeskeyAutoUpdatePara);
_HW_PU_API BOOL __stdcall IVS_PU_SetWorkKeyAutoUpdatePara(ULONG ulIdentifyID,  PU_AESKEY_AUTO_UPDATE_PARA_S stAeskeyAutoUpdatePara);

_HW_PU_API BOOL __stdcall IVS_PU_SetRestPwdPara(ULONG ulIdentifyID, LPPU_REST_PWD_PARA_S pstRestPwdPara);

/*******************************************************************************************************************/
/* ��ͼ������ؽӿ� */
/*******************************************************************************************************************/
#pragma pack(push, 1)

#define PU_CRUISE_NUM_MAX       8        // Ѳ���켣�����
#define PU_CRUISE_NAME_LEN      (32 + 4) // Ѳ���켣������󳤶�
#define PU_VIDEO_MODE_NUM  5             // ��������

// Homeλ��Ϣ
typedef struct PU_PTZ_HOME_INFO {
    ULONG ulPtzId;
    BOOL bEnableFocusInfo;  // ������۽�����ʹ�ܿ���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PTZ_HOME_INFO_S;

// Home ���� ����״̬
typedef enum PU_HOME_GUARD_PARA {
    PU_DEAULT_STATE,  // δ���ù�
    PU_HOME_STATE,    // ���ù�����λ��Ϊ HOME
    PU_GUARD_STATE,   // ���ù�����Ԥ��λ
    PU_HOME_GUARD_MAX
} PU_HOME_GUARD_PARA_E;

// home���ù���״̬��Ϣ
typedef struct PU_PTZ_HOME_GUARD_STATE {
    ULONG ulPtzId;                          // ��̨���
    PU_HOME_GUARD_PARA_E enHomeGuardState;  // Home ���� ����״̬
    BOOL bEnableFocusInfo;                  // ������۽�����ʹ�ܿ���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PTZ_HOME_GUARD_STATE_S;

// ����λ���ð�Homeλ��Ԥ��λIndex��Ϣ
typedef struct PU_PTZ_HOME_PRESET_PARA {
    ULONG ulPtzId;        // ��̨���
    ULONG ulPresetIndex;  // ��Home��Ԥ��λ���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PTZ_HOME_PRESET_PARA_S;

// ����Ѳ���켣��Ϣ
typedef struct PU_SIMPLE_CRUISE_TRACK {
    ULONG ulNumber;                   // �켣���
    CHAR szName[PU_CRUISE_NAME_LEN];  // �켣����
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SIMPLE_CRUISE_TRACK_S;

// Ѳ���켣�б�
typedef struct PU_PTZ_CRUISE_TRACK_LIST {
    ULONG ulPtzId;                                               // ��̨���
    ULONG ulCruiseTrackNum;                                      // Ѳ���켣����
    PU_SIMPLE_CRUISE_TRACK_S astCruiseTrack[PU_CRUISE_NUM_MAX];  // �켣��Ϣ�б�
    CHAR szReserved[PU_RESERVE_LEN];
} PU_PTZ_CRUISE_TRACK_LIST_S;

// ��̨��ǰ״̬
typedef enum PU_PTZ_CURRENT_STATE {
    PU_PTZ_STATE_IDLE = 0,               // ����
    PU_PTZ_STATE_MOVE,                   // �������
    PU_PTZ_STATE_PRESET,                 // Ԥ��λ
    PU_PTZ_STATE_ZOOM,                   // ���ڱ䱶
    PU_PTZ_STATE_FOCAL,                  // ���ڱ佹
    PU_PTZ_STATE_LENS,                   // ���ڿ��ƹ�Ȧ
    PU_PTZ_STATE_LOCATION,               // 3D��λ
    PU_PTZ_STATE_FAST_MOVE,              // ���ٶ�λ
    PU_PTZ_STATE_CRUISE,                 // Ѳ��
    PU_PTZ_STATE_VERTICAL_SCAN,          // ��ֱɨ��
    PU_PTZ_STATE_HORIZONTAL_SCAN,        // ˮƽɨ��
    PU_PTZ_STATE_VERTICAL_LIMIT_SCAN,    // ��ֱ��λɨ��
    PU_PTZ_STATE_HORIZONTAL_LIMIT_SCAN,  // ˮƽ��λɨ��
    PU_PTZ_STATE_PATTERN_SCAN,           // ����ɨ��
    PU_PTZ_STATE_FRAME_SCAN,             // ֡ɨ��
    PU_PTZ_STATE_PANOR_SCAN,             // ȫ��ɨ��
    PU_PTZ_STATE_RANDOM_SCAN,            // ���ɨ��
    PU_PTZ_CALIBRATE_MAGENTIC,           // ����У׼
    PU_PTZ_STATE_PATTERN_REC,            // ����ɨ��¼��

    PU_PTZ_STATE_MAX
} PU_PTZ_CURRENT_STATE_E;

// ѭ��״̬����
typedef struct PU_PTZ_CRUISE_STATUS {
    ULONG ulCruiseIndex;              // ����Ѳ����Ѳ���켣���
    CHAR szName[PU_CRUISE_NAME_LEN];  // Ѳ���켣����
} PU_PTZ_CRUISE_STATUS_S;

// ����ɨ��״̬����
typedef struct PU_PATTERN_SCAN_STATUS {
    ULONG ulPatternIndex;
} PU_PATTERN_SCAN_STATUS_S;

// ��̨״̬
typedef union PU_PTZ_STATE_INFO {
    PU_PTZ_CRUISE_STATUS_S stCuiseStatus;
    PU_PATTERN_SCAN_STATUS_S stPatternStatus;
} PU_PTZ_STATE_INFO;

// ��ǰ״̬
typedef struct PU_PTZ_CURRENT_STATUS {
    ULONG ulPtzId;                       // ��̨��ţ�֧����ͼ
    PU_PTZ_CURRENT_STATE_E enPtzStatus;  // ��̨״̬
    PU_PTZ_STATE_INFO unStateInfo;       // ״̬����
} PU_PTZ_CURRENT_STATUS_S;

// ץ����Ϣ���ӿ��ڲ�ʹ�ã��ṹ���������
typedef struct PU_SNAP_INFO {
    ULONG ulChannelId;                        // ͨ��ID
    ULONGLONG ulSnapId;                       // ץ�Ĳ���ID
    ULONG ulTimeOut;                          // ץ�ĳ�ʱʱ�� ��������ʱ�� 0�Ƿ���
    ULONG ulMaxSnapCount;                     // ���ץ����Ŀ��0 ���������ƣ�
    PU_PTZ_CURRENT_LOCATION_EX_S stLocation;  // ��λ����
    PU_RECTANGLE_S  stRectangle;              // ����λ��
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SNAP_INFO_S;

// sensor�ֱ���
typedef struct PU_SENSOR_RESOLUTION {
    ULONG ulWidth;
    ULONG ulHeight;
} PU_SENSOR_RESOLUTION_S;

// ��Ԫ�ߴ�
typedef struct PU_SENSOR_SCALE {
    FLOAT fWidth;
    FLOAT fHeight;
} PU_SENSOR_SCALE_S;

// sensor��ͷ��Ϣ
typedef struct PU_SENSOR_LEN_INFO {
    PU_SENSOR_RESOLUTION_S stSensorResolution;  // Sensor�ֱ���
    PU_SENSOR_SCALE_S stSensorScale;            // ��Ԫ�ߴ�
    ULONG ulMinFocusLength;                     // ������С���ʻ�ȡ��С����
    ULONG ulMaxFocusLength;                     // ��������ʻ�ȡ��󽹾�
    ULONG ulDeclareZoom;                        // ���ƣ���󣩱���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_SENSOR_LEN_INFO_S;

// ��ͼ����ptz��Ϣ�ṹ��
typedef struct PU_OMNI_CONTROL_PTZ_INFO{
    ULONG ptzId;    // ��̨Id��Ĭ��101
    BOOL enable;   // TRUE:�������������µ�Ѳ����ɨ��ȹ���; FALSE:�ر����������µ�Ѳ��������ɨ��ȹ���
    CHAR szReserved[PU_RESERVE_LEN];
} PU_OMNI_CONTROL_PTZ_INFO_S;

typedef void (*CbParaUserValue)(PU_META_TLV *pstMetaTLV, PU_UserData *pstUserData);

typedef enum PU_OMNI_BIT_RATE_TYPE {
    PU_OMNI_BIT_RATE_TYPE_FIXED = 0,  // ������
    PU_OMNI_BIT_RATE_TYPE_VARIABLE,   // ������
    PU_OMNI_BIT_RATE_TYPE_MAX
} PU_OMNI_BIT_RATE_TYPE_E;

typedef enum PU_MEDIA_TYPE {
    PU_MEDIA_VIDEO_STREAM = 0,    // ��Ƶ��
    PU_MEDIA_AUDIO_STREAM,        // ��Ƶ��
    PU_MEDIA_MUX_STREAM,          // ������(��Ƶ����Ƶ���������������豸���������ܽ��)
    PU_MEDIA_METADATA_STREAM,     // ���ܽ����
    PU_MEDIA_VIDEO_META_STREAM,   // ��Ƶ������ ��
    PU_MEDIA_VIDEO_AUDIO_STREAM,  // ��Ƶ����Ƶ��
    PU_MEDIA_TYPE_MAX,            // ���ֵ
} PU_MEDIA_TYPE_E;

// ��Ƶ��������Ϣ
typedef struct PU_VIDEO_PARA {
    PU_STREAM_TYPE_E enStreamId;            // ��������������1��������2
    PU_MEDIA_TYPE_E enMainStreamType;       // ����������Ƶ��
    PU_ENCODE_TYPE_E enMainVideoPt;         // ��������
    ULONG ulMainFrameRate;                  // ֡��
    ULONG ulMainBitRate;                    // ��������
    PU_OMNI_BIT_RATE_TYPE_E enBitRateType;  // ��������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_VIDEO_PARA_S;

typedef struct PU_AUDIO_PARA {
    PU_ENCODE_TYPE_E enAudioPt;  // ��ƵЭ��
    ULONG ulMainFrameRate;       // ֡��
    ULONG ulMainBitRate;         // ��������
    ULONG ulSampleRate;          // ��������
    CHAR szReserved[PU_RESERVE_LEN];
} PU_AUDIO_PARA_S;

typedef struct PU_OMNI_MEDIA_PARA {
    ULONG ulChannelId;
    ULONG ulVideoSize;
    PU_ENABLE_TYPE_E enDynamicBitRateEnable;  // ��̬�����Ƿ�ʹ��
    PU_VIDEO_PARA_S szVideoPara[PU_VIDEO_MODE_NUM];
    PU_AUDIO_PARA_S stAudioPara;
    CHAR szReserved[PU_RESERVE_LEN];
} PU_OMNI_MEDIA_PARA_S;

#pragma pack(pop)

// ���õ�ǰλΪHOMEλ
_HW_PU_API BOOL __stdcall IVS_PU_SetHome(ULONG ulIdentifyID, PU_PTZ_HOME_INFO_S *pstHomeInfo);

// ��ȡ��ǰhome���ù���״̬��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetHomeGuardSetState(ULONG ulIdentifyID, PU_PTZ_HOME_GUARD_STATE_S *pstHomeState);

// ��ȡ����λ���ð�Homeλ��Ԥ��λIndex
_HW_PU_API BOOL __stdcall IVS_PU_GetHomeGuardSetIndex(ULONG ulIdentifyID, PU_PTZ_HOME_PRESET_PARA_S *pstHomeIndex);

// ��ȡѲ���켣�б�
_HW_PU_API BOOL __stdcall IVS_PU_GetCruiseTrackList(ULONG ulIdentifyID, PU_PTZ_CRUISE_TRACK_LIST_S *pstList);

// ��̨��ǰ״̬��ѯ
_HW_PU_API BOOL __stdcall IVS_PU_GetPTZCurrentStatus(ULONG ulIdentifyID, PU_PTZ_CURRENT_STATUS_S *pstStatus);

// ��ͷ��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetCalibrationLenInfo(ULONG ulIdentifyID, PU_CALIBRATION_LEN_INFO_S *pstInfo);

// seneor��ͷ��Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_GetSensorLenInfo(ULONG ulIdentifyID, PU_SENSOR_LEN_INFO_S *pstInfo);

// ץ����Ϣ
_HW_PU_API BOOL __stdcall IVS_PU_SetSnapInfo(ULONG ulIdentifyID, PU_SNAP_INFO_S *pstInfo);

//��ͼ����ptz
_HW_PU_API BOOL __stdcall IVS_PU_SetOmniControlPtz(ULONG ulIdentifyID, PU_OMNI_CONTROL_PTZ_INFO_S *pstInfo);

// ý��������
_HW_PU_API BOOL __stdcall IVS_PU_SetMediaPara(ULONG ulIdentifyID, PU_OMNI_MEDIA_PARA_S *pstInfo);
_HW_PU_API BOOL __stdcall IVS_PU_GetMediaPara(ULONG ulIdentifyID, PU_OMNI_MEDIA_PARA_S *pstInfo);

/*******************************************************************************************************************/
/* �ؼ��ӿ� */
/*******************************************************************************************************************/
#ifdef _WIN32
// ����������/�������ǵ�
_HW_PU_API BOOL __stdcall IVS_Player_SetCrossInfo(ULONG ulIdentifyID, ULONG ulRealHandle,
                                                  PU_CROSS_INFO_S *pstIACross, ULONG ulNum);

// ��ȡ������/�������ǵ�
_HW_PU_API BOOL __stdcall IVS_Player_GetCrossInfo(ULONG ulIdentifyID, ULONG ulRealHandle,
                                                  PU_CROSS_INFO_S *pstIACrossInfo, ULONG &ulCrossNum, bool bIsActivated);

// �ƶ���ǵ�
_HW_PU_API BOOL __stdcall IVS_Player_MoveGraph(ULONG ulIdentifyID, ULONG ulRealHandle, double dOldX, double dOldY,
                                               double dNewX, double dNewY, PU_CURSOR_SHAPE_E enCursorShape, INT &position);

// �жϵ��Ƿ���ĳ��ͼ����
_HW_PU_API BOOL __stdcall IVS_Player_IsPointOnOneGraph(ULONG ulIdentifyID, ULONG ulRealHandle, FLOAT pointX,
                                                       FLOAT pointY, ULONG ulGraphID);

// ѡ�б�ǵ�
_HW_PU_API BOOL __stdcall IVS_Player_SelectGraph(ULONG ulIdentifyID, ULONG ulRealHandle, FLOAT pointX,
                                                 FLOAT pointY, INT &position);

// ɾ����ǵ�
_HW_PU_API BOOL __stdcall IVS_Player_ClearSelectGraph(ULONG ulIdentifyID, ULONG ulRealHandle, FLOAT pointX,
                                                      FLOAT pointY, INT &position);

// ���ӷŴ�
_HW_PU_API BOOL __stdcall IVS_Player_StartImageMagnify(ULONG ulIdentifyID, ULONG ulRealHandle, LONG ptStartX,
                                                       LONG ptStartY, LONG ptEndX, LONG ptEndY);

// �رյ��ӷŴ�
_HW_PU_API BOOL __stdcall IVS_Player_StopImageMagnify(ULONG ulIdentifyID, ULONG ulRealHandle);

// ��ѡԪ���ݿ򣬷���ID	
_HW_PU_API BOOL __stdcall IVS_Player_SelectTargrtRect(ULONG ulIdentifyID, ULONG ulRealHandle, LONG lPointX,
                                                      LONG lPointY, ULONG &ulID);

// �����͹ر�Ԫ������ʾ
_HW_PU_API BOOL __stdcall IVS_Player_ShowMetaGraphics(ULONG ulIdentifyID, ULONG ulRealHandle, ULONG ulGraphicsType,
                                                      ULONG ulEnable);

// ���û��ƹ��򼸺�ͼ����ʼ��
_HW_PU_API BOOL __stdcall IVS_Player_SetShapeStartPoint(ULONG ulIdentifyID, ULONG ulRealHandle, ULONG ulShapeType,
                                                        FLOAT x, FLOAT y);
// ���û��ƹ��򼸺�ͼ��
_HW_PU_API BOOL __stdcall IVS_Player_DrawIAShape(ULONG ulIdentifyID, ULONG ulRealHandle, ULONG ulShapeType,
                                                 FLOAT x, FLOAT y, bool &bPolyFinish, bool bIsMoving);
// ��ȡ���ܷ���ͼ����Ϣ
_HW_PU_API BOOL __stdcall IVS_Player_GetIAGraphInfo(ULONG ulIdentifyID, ULONG ulRealHandle, ULONG ulGraphicsType,
                                                    PU_GRAPH_INFO_S *pIARectInfo, ULONG &ulIAGraphNum);
// ���3D��λͼ��
_HW_PU_API BOOL __stdcall IVS_Player_Clear3DLocationGraph(ULONG ulIdentifyID, ULONG ulRealHandle);
// ����Ԫ����չʾ����
_HW_PU_API BOOL __stdcall IVS_Player_SetPlayType(ULONG ulIdentifyID, ULONG ulRealHandle, ULONG ulPlayType);
// ɾ���Զ��궨��
_HW_PU_API BOOL __stdcall IVS_Player_ClearAutoCalibCross(ULONG ulIdentifyID, ULONG ulRealHandle);
// �������ܷ���ͼ��
_HW_PU_API BOOL __stdcall IVS_Player_SetIAGraphics(ULONG ulIdentifyID, ULONG ulRealHandle,
                                                   PU_GRAPH_INFO_S *pGraphics, ULONG ulNum, ULONG ulDrawType);
// �������ͼ��
_HW_PU_API BOOL __stdcall IVS_Player_ClearAllIAGraph(ULONG ulIdentifyID, ULONG ulRealHandle);
_HW_PU_API BOOL __stdcall IVS_Player_StartAlarmChan(ULONG ulIdentifyID, ULONG ulRealHandle, INT nCaptureType,
                                                    CHAR *pScenePicPath, CHAR *pDevIp, bool bRecvPic = true);

_HW_PU_API BOOL __stdcall IVS_Player_StopAlarmChanEx(ULONG ulIdentifyID, ULONG ulRealHandle, INT nCaptureType);

/*******************************************************************************************************************/
/* SIMS ���нӿ� */
/*******************************************************************************************************************/
// ʵ�����Žӿڣ���SIMS�ṩ(֧������APP���ܽ����ʾ)
_HW_PU_API ULONG __stdcall IVS_PU_RealPlay_ForSIMS(ULONG ulIdentifyID, LPPU_REAL_PLAY_INFO_S pstRealPlayInfo,
                                                   pfRealDataCallBack fRealDataCallBack, VOID *pUsrData, CHAR *pAppName);
// ʵ�����Žӿ����䣬��SIMS�ṩ(֧������APP���ܽ����ʾ)
_HW_PU_API ULONG __stdcall IVS_PU_RealPlay_V20_ForSIMS(ULONG ulIdentifyID,
                                                       PU_REAL_PLAY_INFO_V20_S *pstRealPlayInfo, PU_MEDIA_ENC_PARA_S *pstMediaEncPara,
                                                       pfRealDataCallBack fRealDataCallBack, VOID *pUsrData, CHAR *pAppName);

#endif

#endif
