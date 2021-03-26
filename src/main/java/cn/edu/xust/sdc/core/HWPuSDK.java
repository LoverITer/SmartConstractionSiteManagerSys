package cn.edu.xust.sdc.core;

import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.CAR_PRE_BRAND;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.CAR_SUB_BRAND;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.CAR_YEAR_BRAND;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.ITS_TRAFFIC_SNAP_TIME;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.LANE_ID;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_AVG_SPEED;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_CONGESTION_DEGREE;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_LANE_COUNT;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_LANE_INDEX;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_LANE_SPACE_USED_RATIO;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_LANE_TIME_USED_RATIO;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_QUEUE_LENGTH;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_COUNT;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_DENSITY;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_HEAD_INTERVAL;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_HEAD_SPACE_INTERVAL;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE1_COUNT;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE2_COUNT;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE3_COUNT;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.PANORAMA_PIC;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.PIC_SNAPSHOT_TIME;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.PLATE_CHAR;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.PLATE_COLOR;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.PLATE_PIC;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.PLATE_TYPE;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.REGULATION_TYPE;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.VEHICLE_COLOR;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.VEHICLE_DIRECTION;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.VEHICLE_PIC;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.VEHICLE_SPEED;
import static cn.edu.xust.sdc.core.HWPuSDK.LAYER_THREE_TYPE_E.VEHICLE_TYPE;

import java.awt.Point;
import java.util.Arrays;
import java.util.List;

import com.sun.jna.IntegerType;
import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.NativeLong;
import com.sun.jna.Platform;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.Union;
import com.sun.jna.platform.win32.WinDef;
import com.sun.jna.platform.win32.WinDef.BOOL;
import com.sun.jna.platform.win32.WinDef.UINT;
import com.sun.jna.platform.win32.WinDef.ULONG;
import com.sun.jna.platform.win32.WinDef.USHORT;
import com.sun.jna.ptr.ByteByReference;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.LongByReference;
import com.sun.jna.ptr.PointerByReference;
import com.sun.jna.win32.StdCallLibrary.StdCallCallback;

/**
 * SDK interface after JNA mechanism conversion JNA转换后的SDK接口
 */
public interface HWPuSDK extends Library {

	public static class AERADTC_LIST extends Structure {
		public long ulAreaNum;
		public PU_AREA[] stArea = new PU_AREA[MAX_AREA_NUM];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulAreaNum", "stArea");
		}
	}

	public static class AREA_CROP_PARA extends Structure {
		public ULONG ulChnID; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.
		public int enStreamType; // Stream type.
		public int enResolution; // Resolution. c :type PU_RESOLUTION_TYPE
		public PU_AREA_INFO stAreaInfo; // Area information.
		public byte[] szReserved = new byte[64];

		public AREA_CROP_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "enStreamType", "enResolution", "stAreaInfo", "szReserved");
		}
	}

	public interface BACKLIGHT_MODE {
		public static final int VIDEO_MODE_AVERAGE = 0; // Use the default setting for the backlight area.
		public static final int VIDEO_MODE_CENTER = 1; // The backlight area is the central area in the image.
		public static final int VIDEO_MODE_UP = 2; // The backlight area is the upper part of the image (this variable
													// is reserved).
		public static final int VIDEO_MODE_DOWN = 3; // The backlight area is the lower part of the image (this variable
														// is reserved).
		public static final int VIDEO_MODE_LEFT = 4; // The backlight area is the left part of the image (this variable
														// is reserved).
		public static final int VIDEO_MODE_RIGHT = 5; // The backlight area is the right part of the image (this
														// variable is reserved).
		public static final int VIDEO_MODE_USER = 6; // The backlight area is a customized area.
	}

	// Focus control parameters.
	public static class CAM_FOCUSCTRL extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int enFocus; // c type:PU_CamControl
		public ULONG ulFocusSpeed; // Focus speed. For Sony devices, the value ranges from 0 to 7. For Hitachi
									// devices, the value is 31.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public CAM_FOCUSCTRL() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enFocus", "ulFocusSpeed", "szReserved");
		}
	}

	public interface DERICTION_SIGN_TYPE_E {
		int DERICTION_TYPE_LEFT = 0; /* Turn-left. */
		int DERICTION_TYPE_STRAIGHT = 1; /* Straight-through. */
		int DERICTION_TYPE_LEFT_STRAIGHT = 2; /* Turn-left + Straight-through. */
		int DERICTION_TYPE_RIGHT = 3; /* Turn-right. */
		int DERICTION_TYPE_LEFT_RIGHT = 4; /* Turn-left and turn-right. */
		int DERICTION_TYPE_RIGHT_STRAIGHT = 5; /* Turn-right + Straight-through. */
		int DERICTION_TYPE_LEFT_RIGHT_STRAIGHT = 6; /* Turn-left, turn-right, and straight-through. */
		int DERICTION_TYPE_LEFT_STAY = 7; /* Waiting to turn left. */
		int DERICTION_TYPE_STRAIGHT_STAY = 8; /* Waiting to go straight ahead. */
		int DERICTION_TYPE_RIGHT_STAY = 9; /* Waiting to turn right. */
		int DERICTION_TYPE_BUTT = 10;
	}

	public interface DIAL_AUTH_TYPE_E {
		int DIAL_AUTH_NONE = 0x00; /* No authentication. */
		int DIAL_AUTH_PAP = 0x01; /* PAP authentication. */
		int DIAL_AUTH_CHAP = 0x02; /* CHAP authentication. */
		int DIAL_AUTH_CHAP_PAP = 0x03; /*
										 * Try CHAP authentication and then PAP authentication (if CHAP authentication
										 * fails).
										 */
	}

	public interface DIAL_CONNECT_E {
		int DIAL_DISCONNECT = 0;
		int DIAL_CONNECT = 1;
		int DIAL_CONNECT_MAX = 2;
	}

	//// Setting and obtaining 4G wireless information.
	public interface DIAL_MODE_E {
		int MANUL_DIAL = 0;
		int AUTO_DIAL = 1;
		int DIAL_MAX = 2;
	}

	public interface DIAL_NET_ACT_TYPE_E {
		int DIAL_REGISTER_ST_NO_SERVICE = 0x00;
		int DIAL_REGISTER_ST_GSM = 0x01;
		int DIAL_REGISTER_ST_WCDMA = 0x02;
		int DIAL_REGISTER_ST_LTE = 0x03;
	}

	public interface DIAL_SIM_STATUS_TYPE_E {
		int DIAL_SIM_STATUS_ABSENT = 0; /* No SIM card. */
		int DIAL_SIM_STATUS_READY = 1; /* The SIM card is normal. */
		int DIAL_SIM_STATUS_FAILURE = 2; /* The SIM card is abnormal. */
		int DIAL_SIM_STATUS_PIN_REQUIRED = 3; /* To enter PIN for unlocking. */
		int DIAL_SIM_STATUS_PIN2_REQUIRED = 4; /* To enter PIN2 for unlocking. */
		int DIAL_SIM_STATUS_PUK_REQUIRED = 5; /* To enter PUK for unlocking. */
		int DIAL_SIM_STATUS_PUK2_REQUIRED = 6; /* To enter PUK2 for unlocking. */
		int DIAL_SIM_STATUS_OPERATION_NOT_ALLOW = 7; /* Operation not allowed. */
		int DIAL_SIM_STATUS_INCORRECT_PASSWORD = 8; /* The password is incorrect. */
	}

	// Violation detection mode.
	public interface EN_ITS_REGULA_DT_TYPE {
		int ITS_REGULA_DT_TYPE_EXTDEV = 0; // External device-based detection.
		int ITS_REGULA_DT_TYPE_VIDEODT = 1; // Video-based detection.
		int ITS_REGULA_DT_TYPE_EXTDEV_FIRST = 2; // External device-based detection preferred.
		int ITS_REGULA_DT_TYPE_MAX = 3;
	}

	public interface EN_ITS_TYPE {
		int ITS_TYPE_EPOLICE = 0; // ePolice.
		int ITS_TYPE_TGATEWAY = 1; // Checkpoint.
		int ITS_TYPE_MAX = 2;
	}

	/************************** Macro Definition Ends ***************************/
	/********************************
	 * Enumerated Type
	 **********************************************/
	public interface ERROR_CODE {
		public final int PU_ERROR_CODE_NOERROR = 0; // Common error.
		public final int PU_ERROR_CODE_COMMON_ERROR = 1; // Incorrect user name or password.
		public final int PU_ERROR_CODE_PASSWORD_ERROR = 2; // No operation permission.
		public final int PU_ERROR_CODE_NO_PRIORITY = 3; // The SDK is not initialized.
		public final int PU_ERROR_CODE_NO_INIT = 4; // The SDK has been initialized.
		public final int PU_ERROR_CODE_HAS_INIT = 5; // The SDK does not match the device version.
		public final int PU_ERROR_CODE_VERSION_NO_MATCH = 6; // Network startup error.
		public final int PU_ERROR_CODE_STARTUP_NETWORK_ERROR = 7; // Network socket error.
		public final int PU_ERROR_CODE_SOCKET_ERROR = 8; // Network connection error.
		public final int PU_ERROR_CODE_CONNECT_ERROR = 9; // Message sending timed out.
		public final int PU_ERROR_CODE_SEND_TIMEOUT = 10; // Message receiving timed out.
		public final int PU_ERROR_CODE_RECV_TIMEOUT = 11; // Device operation timed out.
		public final int PU_ERROR_CODE_OPERATION_TIMEOUT = 12; // Failed to allocate the memory due to insufficient
																// memory space.
		public final int PU_ERROR_CODE_OUT_OF_MEMORY = 13; // The link is disconnected on the server.
		public final int PU_ERROR_CODE_SERVER_IS_SHUTDOWN = 14; // The number of live video channels exceeded the
																// maximum.
		public final int PU_ERROR_CODE_TOO_MANY_REALPLAY = 15; // Log error.
		public final int PU_ERROR_CODE_LOG_ERROR = 16; // Insufficient port resources.
		public final int PU_ERROR_CODE_NO_FREE_PORT = 17; // The event callback function has been registered.
		public final int PU_ERROR_CODE_HAS_REG_EVENT_CALLBACK = 18; // Failed to register the PU with the platform.
		public final int PU_ERROR_CODE_REGISTER_FAIL = 19; // Proactive PU registration with the platform is redirected.
		public final int PU_ERROR_CODE_REGISTER_REDIRECT = 20; // The input parameter is a null pointer.
		public final int PU_ERROR_CODE_INPUT_NULL_PTR = 21; // Failed to operate the local file.
		public final int PU_ERROR_CODE_OPR_LOCAL_FILE_FAIL = 22; // Incorrect file format.
		public final int PU_ERROR_CODE_FILE_FORMAT_INVALID = 23; // Failed to verify the digital watermark of the
																	// snapshot.
		public final int PU_ERROR_CODE_VLPR_WATERMARK_INVALID = 24; // Incorrect REST packet format.
		public final int PU_ERROR_CODE_REST_PKG_TYPE_ERROR = 25; //
		// API invoking error.
		public static final int PU_ERROR_CODE_SDKINIT_LINK_MODE_ERROR = 101; // A connection mode error occurred during
																				// SDK initialization.
		public static final int PU_ERROR_CODE_SDKINIT_LOCALIP_ERROR = 102; // A local IP address error occurred during
																			// SDK initialization.
		public static final int PU_ERROR_CODE_SDKLOGIN_PARA_ERROR = 103; // Login parameter error.
		public static final int PU_ERROR_CODE_CODE_IS_INVALID = 104; // Invalid error code.
		public static final int PU_ERROR_CODE_SDKGETVERSION_PARA_ERROR = 105; // An error occurred when obtaining the
																				// version.
		public static final int PU_ERROR_CODE_IDENTIFYID_ERROR = 106; // Incorrect user ID.
		public static final int PU_ERROR_CODE_SDKGETDEVICE_PARA_ERROR = 107; // An error occurred when obtaining the
																				// device parameter settings.
		public static final int PU_ERROR_CODE_ALARMREPORT_CB_IS_NULL = 108; // The alarm reporting callback function is
																			// empty.
		public static final int PU_ERROR_CODE_VOICETB_CB_IS_NULL = 109; // The voice intercom callback function is
																		// empty.
		public static final int PU_ERROR_CODE_REALPLAY_CB_IS_NULL = 110; // The live video viewing callback function is
																			// empty.
		public static final int PU_ERROR_CODE_LOAD_PLAYDLL_ERROR = 111; // An error occurred when loading the video
																		// library.
		public static final int PU_ERROR_CODE_CFGFILE_ERROR = 112; // The configuration is incorrect.
		public static final int PU_ERROR_CODE_UNSUPPORT_ALARM_TYPE = 113; // Unknown alarm type.
		public static final int PU_ERROR_CODE_SDKUPGRADE_PARA_ERROR = 114; // Upgrade parameter error.
		public static final int PU_ERROR_CODE_SDKUPGRADE_ERROR = 115; // Upgrade error.
		public static final int PU_ERROR_CODE_SDKUPGRADE_FILE_ERROR = 116; // Incorrect upgrade file.
		public static final int PU_ERROR_CODE_UNSUPPORT_PLATFORM_TYPE = 117; // Unknown platform type.
		public static final int PU_ERROR_CODE_SDKSETPLATFORM_PARA_ERROR = 118; // An error occurred when setting
																				// platform parameters.
		public static final int PU_ERROR_CODE_UNSUPPORT_ENCODE_TYPE = 119; // Unknown audio and video encoding type.
		public static final int PU_ERROR_CODE_UNSUPPORT_STREAM_TYPE = 120; // Unknown stream type.
		public static final int PU_ERROR_CODE_UNSUPPORT_BITRATE_TYPE = 121; // Unknown bit rate type.
		public static final int PU_ERROR_CODE_UNSUPPORT_PTZ_CMD = 122; // Unknown PTZ control command.
		public static final int PU_ERROR_CODE_CRUISE_PARA_ERROR = 123; // Tour parameter error.
		public static final int PU_ERROR_CODE_ALARM_TMP_PARA_ERROR = 124; // Temperature alarm parameter error.
		public static final int PU_ERROR_CODE_ALARM_MOTION_DETEC_PARA_ERROR = 125; // Motion detection alarm parameter
																					// error.
		public static final int PU_ERROR_CODE_ALARM_INPUT_PARA_ERROR = 126; // Boolean value input alarm parameter
																			// error.
		public static final int PU_ERROR_CODE_ALARM_HIDE_PARA_ERROR = 127; // Lens blocking alarm parameter error.
		public static final int PU_ERROR_CODE_ALARM_INVADE_PARA_ERROR = 128; // Intrusion detection alarm parameter
																				// error.
		public static final int PU_ERROR_CODE_ALARM_COUNT_PARA_ERROR = 129; // Object counting alarm parameter error.
		public static final int PU_ERROR_CODE_ALARM_DISTURB_PARA_ERROR = 130; // Interference alarm parameter error.
		public static final int PU_ERROR_CODE_PRIVACY_PARA_ERROR = 131; // Privacy mask parameter error.
		public static final int PU_ERROR_CODE_OSD_PARA_ERROR = 132; // OSD parameter error.
		public static final int PU_ERROR_CODE_PTZ_PARA_ERROR = 133; // PTZ control parameter error.
		public static final int PU_ERROR_CODE_SDKGUARD_PARA_ERROR = 134; // Alert deployment and withdrawal parameter
																			// error.
		public static final int PU_ERROR_CODE_SDKGETALARAM_PARA_ERROR = 135; // An error occurred when obtaining alarm
																				// parameter settings.
		public static final int PU_ERROR_CODE_PARA_ERROR = 136; // Parameter error.
		public static final int PU_ERROR_CODE_PLAYER_FUNC_ERROR = 137; // An error occurred when invoking the video
																		// library function.
		public static final int PU_ERROR_CODE_SDKSAVEREALDATA_ERROR = 138; // Save live video data.
		public static final int PU_ERROR_CODE_SDKGETGUARDSTATE_PARA_ERROR = 139; // An error occurred when obtaining the
																					// alert deployment status
																					// parameter.
		public static final int PU_ERROR_CODE_MUTUALLYEXCLUSIVE_RELATIONSHIP = 140; // The setting fails because of
																					// mutual exclusion.
		public static final int PU_ERROR_CODE_DEVICE_RELOGIN = 141; // You have logged in to the device.
		public static final int PU_ERROR_CODE_INVALID_CONFIG_FILE = 142; // The configuration file is invalid.
		public static final int PU_ERROR_CODE_WRONG_RSP_TYPE = 143; // The response message type is incorrect.
		public static final int PU_ERROR_CODE_RSP_MEG_PARSE_ERROR = 144; // Failed to parse the response message.
		public static final int PU_ERROR_CODE_MISMATCH_PWD_COMPLEXITY = 145; // The password does not meet the
																				// complexity requirements.
		public static final int PU_ERROR_CODE_ALARM_AUDIO_UP_PARA_ERROR = 146; // Sudden volume increase alarm parameter
																				// error.
		public static final int PU_ERROR_CODE_ALARM_AUDIO_DOWN_PARA_ERROR = 147; // Sudden volume decrease alarm
																					// parameter error.
		public static final int PU_ERROR_CODE_TRANSPARENT_CHANNEL_DATA_CB_IS_NULL = 148; // The data callback function
																							// of the transparent
																							// channel is empty.
		public static final int PU_ERROR_CODE_NO_ENOUGH_CONTINUOUS_MEM = 149; // Insufficient continuous memory.*/
		public static final int PU_ERROR_CODE_IRCMODE_PARA_ERROR = 150; // Incorrect IR Cut type.*/
		public static final int PU_ERROR_CODE_CERT_PARA_ERROR = 151; // Incorrect certificate path.*/
		public static final int PU_ERROR_CODE_IMPORT_FACELIBRARY_ERROR = 152; // An error occurred when importing face
																				// images into the face library.*/
		public static final int PU_ERROR_CODE_IMPORTING_FACELIB_ERROR = 153; // Importing face images into a face
																				// library...*/
		public static final int PU_ERROR_CODE_UNKNOWN_SV_TYPE = 154; // Unknown service type.*/
		public static final int PU_ERROR_CODE_NOT_OPEN_TLS = 155; // Operations related to the face library cannot be
																	// performed because the TLS is not enabled.*/
		public static final int PU_ERROR_INVALID_UPDATEFILE_NUM = 156; // The number of upgrade files exceeded the
																		// maximum.*/
		public static final int PU_ERROR_USER_CANCEL_UPGRADE = 157; // Upgrade canceled.*/
		public static final int PU_ERROR_NOT_ENOUGH_MEMORY_ALLOCATED = 160; // JSON data cannot be loaded because the
																			// input receive cache is too small.*/

		// Decoder error codes
		public static final int PU_ERROR_CODE_DEC_INITDEC_ERROR = 1001; // Decoding initialization failure.
		public static final int PU_ERROR_CODE_DEC_STARTDEC_ERROR = 1002; // Failed to start decoding.
		public static final int PU_ERROR_CODE_DEC_STOPDEC_ERROR = 1003; // Failed to stop decoding.
		public static final int PU_ERROR_CODE_DEC_TOO_MANY_CHANNEL = 1004; // There are too many decoding channels.
		public static final int PU_ERROR_CODE_DEC_ERROR_PORT_NUM = 1005; // Incorrect port quantity.
		public static final int PU_ERROR_CODE_DEC_ERROR_DEC_HANDEL = 1006; // Incorrect decoding handle.
		public static final int PU_ERROR_CODE_DEC_ERROR_UNSUPPORT_DECODE_TYPE = 1007; // Unsupported decoding type.
		public static final int PU_ERROR_CODE_DEC_ERROR_INVALID_CHANNEL_ID = 1008; // Invalid channel ID.

		// Server error codes
		public static final int PU_ERROR_CODE_SERVER_COMMON_ERROR = 10001; // Common error.
		public static final int PU_ERROR_CODE_SYNTAX_ERROR = 10002; // Configuration syntax error.
		public static final int PU_ERROR_CODE_UNSUPPORT_ERROR = 10003; // Unsupported request.
		public static final int PU_ERROR_CODE_PARAMETER_ERROR = 10004; // Parameter error.
		public static final int PU_ERROR_CODE_INVALID_VCU_ID = 10005; // Incorrect device ID.
		public static final int PU_ERROR_CODE_INVALID_CHANNEL = 10006; // Incorrect channel ID.
		public static final int PU_ERROR_CODE_INVALID_SERIAL_NO = 10007; // Incorrect serial port number.
		public static final int PU_ERROR_CODE_INVALID_ALARM_NO = 10008; // Incorrect alarm port number.
		public static final int PU_ERROR_CODE_UNSUPPORTED_MEDIA_TYPE = 10009; // Unsupported media type.
		public static final int PU_ERROR_CODE_PARTLY_SUPPORT = 10011; // Only some parameters are set successfully.
		public static final int PU_ERROR_CODE_TOO_MANY_PLANS = 10012; // The number of plans exceeded the maximum.
		public static final int PU_ERROR_CODE_NO_DISK = 10013; // The device does not have a hard disk.
		public static final int PU_ERROR_CODE_OPEN_SOUND_FAIL = 10014; // Failed to enable the audio device.
		public static final int PU_ERROR_CODE_VOICE_OPEND = 10015; // The server's voice intercom is in use.
		public static final int PU_ERROR_CODE_DEVICE_BUSY = 10016; // The device is busy.
		public static final int PU_ERROR_CODE_OPERATE_FLASH_ERROR = 10019; // Flash error.
		public static final int PU_ERROR_CODE_UNSUPPORTED_VIDEO_FORMAT = 10020; // Unsupported video standard.
		public static final int PU_ERROR_CODE_IP_ADDRESS_CONFLICT = 10022; // IP address conflict.
		public static final int PU_ERROR_CODE_LTE_DHCP_CONFLICT = 10023; // LTH setting conflicts with DHCP setting.
		public static final int PU_ERROR_CODE_SIP_STACK_ERROR = 10024; // SIP protocol stack error.
		public static final int PU_ERROR_CODE_NULL_ELEMENT = 10101; // The XML file does not have the corresponding
																	// node.
		public static final int PU_ERROR_CODE_INVALID_VERIFICATION = 10102; // Incorrect user name or password.
		public static final int PU_ERROR_CODE_INVALID_VERSION_FILE = 10103; // Failed to verify the version file.
		public static final int PU_ERROR_CODE_INVALID_KERNEL_FILE = 10104; // Failed to verify the kernel upgrade file.
		public static final int PU_ERROR_CODE_INVALID_ROOTFS_FILE = 10105; // Failed to verify the file system upgrade
																			// file.
		public static final int PU_ERROR_CODE_FIRST_LOGIN = 10106; // First login.
		public static final int PU_ERROR_CODE_CLIENT_ALREADY_LOGIN = 10107; // A client has logged in.
		public static final int PU_ERROR_CODE_USER_LOCKED = 10108; // The user is locked.
		public static final int PU_ERROR_CODE_MANY_USER = 10109; // The number of users exceeded the maximum.
		public static final int PU_ERROR_CODE_USER_NAME_CONFLICT = 10110; // Duplicate user name.
		public static final int PU_ERROR_CODE_NO_USER_NAME = 10111; // The user does not exist.
		public static final int PU_ERROR_CODE_USER_NOPOWER = 10112; // The user does not have the permission.
		public static final int PU_ERROR_CODE_NOT_NEED_UPDATE = 10113; // No upgrade is required because the versions
																		// are consistent.
		public static final int PU_ERROR_CODE_NOT_SUPPORT_ABILITY = 10114; // The capability parameter is not supported.
		public static final int PU_ERROR_CODE_PRESET_IN_GUARD_POSITION = 10115; // The preset position has been
																				// configured as the home position.
		public static final int PU_ERROR_CODE_PRESET_IN_CRUISE_TRACK = 10116; // The preset position has been added to
																				// the tour.
		public static final int PU_ERROR_CODE_SET_ETHPHY_OUTPUT_TYPE_ERROR = 10117; // Failed to set the network port
																					// type.
		public static final int PU_ERROR_CODE_SET_ETHMODE_ERROR = 10118; // Failed to set the network port rate.
		public static final int PU_ERROR_CODE_UPLOAD_CONFIG_TYPE_ERROR = 10119; // The type of the configuration file to
																				// upload is incorrect.
		public static final int PU_ERROR_CODE_DNS_SERVER_UNREACH = 10120; // The DNS server is unreachable.
		public static final int PU_ERROR_CODE_DNS_SERVER_NO_DOMAIN = 10121; // The DNS server failed to obtain the
																			// domain name.
		public static final int PU_ERROR_CODE_THE_CRUISE_IS_RUNNING = 10122; // The tour is being executed.
		public static final int PU_ERROR_CODE_SD_FORMATTING = 10124; // The SD card is being formatted.
		public static final int PU_ERROR_CODE_UPDATE = 10125; // The system is being upgraded.
		public static final int PU_ERROR_CODE_REBOOT = 10126; // The system is being restarted.
		public static final int PU_ERROR_CODE_RESTORE = 10127; // The device is restoring default settings.
		public static final int PU_ERROR_CODE_RECOVER_OPRATE_FORBIDDEN = 10128; // Configuration operations cannot be
																				// performed during default setting
																				// restoration.
		public static final int PU_ERROR_CODE_ROI_ERROR_BY_MJPEG = 10129; // Failed to set the ROI in the MJPEG
																			// standard.
		public static final int PU_ERROR_CODE_ROI_ERROR_BY_NOSUBSTREAM = 10130; // The ROI failed to be set for the
																				// secondary stream when only the
																				// primary stream is available.
		public static final int PU_ERROR_CODE_TZ_ERROR_BY_CONFLICT = 10131; // A conflict occurred when tripwire
																			// crossing detection is enabled.
		public static final int PU_ERROR_CODE_OC_ERROR_BY_CONFLICT = 10132; // A conflict occurred when object counting
																			// is enabled.
		public static final int PU_ERROR_CODE_MD_ERROR_BY_CONFLICT = 10133; // A conflict occurred when motion detection
																			// is enabled.
		public static final int PU_ERROR_CODE_TW_ERROR_BY_CONFLICT = 10134; // A conflict occurred when tripwire
																			// crossing detection is enabled.
		public static final int PU_ERROR_CODE_AREA_ERROR_BY_CONFLICT = 10135; // A conflict occurred when intrusion
																				// detection, abandoned object
																				// detection, or removed object
																				// detection is enabled.
		public static final int PU_ERROR_CODE_VD_ERROR_BY_CONFLICT = 10136; // A conflict occurred when video
																			// interference detection is enabled.
		public static final int PU_ERROR_CODE_IGT_ENABLE_CONFLICT = 10137; // Failed to enable illumination enhancement
																			// or lens blocking detection because the
																			// intelligent analysis function has been
																			// enabled.
		public static final int PU_ERROR_CODE_ILLUMINATION_ENABLE_CONFLICT = 10138; // Failed to enable intelligent
																					// analysis or lens blocking
																					// detection because the
																					// illumination enhancement function
																					// has been enabled.
		public static final int PU_ERROR_CODE_VIDEOBLOCK_ENABLE_CONFLICT = 10139; // Failed to enable intelligent
																					// analysis or illumination
																					// enhancement because the lens
																					// blocking detection function has
																					// been enabled.
		public static final int PU_ERROR_CODE_IGT_FAIL_BY_SWITCHOFF = 10140; // Failed to set the intelligent service
																				// because the intelligent analysis
																				// function is not enabled.
		public static final int PU_ERROR_CODE_TW_ERROR_BY_OVER_NUM = 10141; // The number of tripwires exceeded the
																			// maximum.
		public static final int PU_ERROR_CODE_AREA_ERROR_BY_OVER_NUM = 10142; // The number of areas exceeded the
																				// maximum value, 4.
		public static final int PU_ERROR_CODE_AREA_ERROR_BY_OVER_TOTAL_NUM = 10143; // The number of areas exceeded the
																					// maximum value, 10.
		public static final int PU_ERROR_CODE_AREA_ERROR_BY_ZERO_NUM = 10144; // The number of areas is 0.
		public static final int PU_ERROR_CODE_AREA_POINT_ERROR_BY_OVER_NUM = 10145; // The number of area vertexes
																					// exceeded the maximum.
		public static final int PU_ERROR_CODE_AREA_ABN_ERROR_BY_CONFLICT = 10146; // A conflict occurred when abandoned
																					// object detection is enabled. The
																					// removed object detection has been
																					// enabled.
		public static final int PU_ERROR_CODE_AREA_RMV_ERROR_BY_CONFLICT = 10147; // A conflict occurred when removed
																					// object detection is enabled. The
																					// abandoned object detection has
																					// been enabled.
		public static final int PU_ERROR_CODE_VIM_GLOBAL_PARA_ERROR = 10148; // Failed to set global parameters for the
																				// intelligent analysis algorithm.
		public static final int PU_ERROR_CODE_AREA_NOTSURPORT_ERROR = 10149; // Invalid intelligent analysis area.
		public static final int PU_ERROR_CODE_PRIVACY_MASK_AREA_BEYOND = 10150; // The privacy mask area exceeds the
																				// total area.
		public static final int PU_ERROR_CODE_MEDIA_ADAPT_BW_MUTEX = 10151; // The adaptive bandwidth function conflicts
																			// with the encoding type or bit rate type.
		public static final int PU_ERROR_CODE_IP_FILTER_RULE_SAME = 10152; // Duplicate IP address filtering rule.
		public static final int PU_ERROR_CODE_WD_FRAME_CONFLICT = 10153; // If the WDR mode is set to manual or auto,
																			// the collection frame rate cannot be set
																			// to 50 or 60 fps.
		public static final int PU_ERROR_CODE_FRAME_WD_CONFLICT = 10154; // If the collection frame rate is set to 50 or
																			// 60 fps, the WDR mode cannot be set to
																			// manual or auto.
		public static final int PU_ERROR_CODE_CONFLICT_VIDEOBLOCK_OR_IGT_IS_ENABLE = 10155; // Failed to set the
																							// illuminance enhancement
																							// because the lens blocking
																							// detection or behavior
																							// analysis function is
																							// enabled.
		public static final int PU_ERROR_CODE_BUSY_CURISE = 10156; // Failed to set tour parameters during a tour.
		public static final int PU_ERROR_CODE_DEVICE_CLOSE = 10157; // The device is not started.
		public static final int PU_ERROR_CODE_BUSY_PRESET = 10158; // Failed to delete the preset position in use.
		public static final int PU_ERROR_CODE_INVALID_IGT_AREA_ID = 10159; // The intelligent analysis area does not
																			// exist.
		public static final int PU_ERROR_CODE_INVALID_IGT_LINE_ID = 10160; // The intelligent analysis line does not
																			// exist.
		public static final int PU_ERROR_CODE_INVALID_PRIVACY_ID = 10161; // The privacy mask area does not exist.
		public static final int PU_ERROR_CODE_IN_USER_DEFINE_SCAN = 10162; // Pattern scan is in progress (many
																			// functions are unavailable).
		public static final int PU_ERROR_CODE_SET_DRC_BACKLIGHT_CONFLICT = 10163; // The backlight compensation and DRC
																					// functions cannot be enabled at
																					// the same time.
		public static final int PU_ERROR_CODE_CURISE_IN_GUARD_POSITION = 10164; // A preset position in the tour has
																				// been configured as the home position.
		public static final int PU_ERROR_CODE_DISK_ABNORMAL = 10165; // SD card exception.
		public static final int PU_ERROR_CODE_PRIVACYMASK_REGION_INTERSECT = 10166; // Privacy mask areas overlapped.
		public static final int PU_ERROR_CODE_INVALID_SAMEPASSWD = 10167; // The new password must be different from the
																			// old password.
		public static final int PU_ERROR_CODE_NOT_SUPPORTED_UPDATE = 10168; // The version of the upgrade file is too
																			// early. Upgrade the file to a later
																			// version.
		public static final int PU_ERROR_CODE_MANY_RECORD_FILES = 10169; // Too many recording files.
		public static final int PU_ERROR_CODE_CONFLICT_WITH_MOSAIC = 10170; // The operation conflicts with the mosaic
																			// setting.
		public static final int PU_ERROR_CODE_CONFLICT_WITH_OSD = 10171; // The operation conflicts with the OSD
																			// setting.
		public static final int PU_ERROR_CODE_CONFLICT_WITH_PIC = 10172; // The operation conflicts with image overlay.
		public static final int PU_ERROR_CODE_VIDEO_ENC_CLOSE = 10173; // The video encoder is not started.
		public static final int PU_ERROR_CODE_ISP_PARA_CONFLICT = 10174; // ISP parameter conflict.
		public static final int PU_ERROR_CODE_WB_HIGH_TEMP_LOWER = 10175; // The lower limit of the color temperature
																			// must be less than the upper limit in
																			// automatic tracking white balance mode.
		public static final int PU_ERROR_CODE_MJPEG_UNSUPPORT_WATERMARK = 10176; // The MJPEG does not support the
																					// digital watermark function.
		public static final int PU_ERROR_CODE_ISP_CONFLICT_WITH_FRAMERATE = 10177; // WDR or backlight compensation is
																					// mutually exclusive with the full
																					// frame rate.
		public static final int PU_ERROR_CODE_FRAMERATE_CONFLICT_WITH_ISP = 10178; // Full frame rate is mutually
																					// exclusive with WDR or backlight
																					// compensation.
		public static final int PU_ERROR_CODE_OSD_STRING_LEN_ERR = 10179; // The OSD character length is incorrect.
		public static final int PU_ERROR_CODE_DISK_MOUNT_ERROR = 10183; // The disk is not mounted.
		public static final int PU_ERROR_CODE_IMPORTING_FACE_LIB = 10184; // Importing data into the face library...
																			// Please wait.
		public static final int PU_ERROR_CODE_ADDING_ONE_FACE = 10185; // Adding faces... Please wait.
		public static final int PU_ERROR_CODE_AUDIO_DETECT_MIC_NOT_SUPPORT = 10200; // Audio exception detection is not
																					// supported in the case of MIC
																					// connection.
		public static final int PU_ERROR_CODE_CIF_CONFLICT = 10202; // The CIF cannot be set because it is mutually
																	// exclusive with the corridor mode.
		public static final int PU_ERROR_CODE_CORRIDOR_CONFLICT = 10203; // The corridor cannot be set because it is
																			// mutually exclusive with the CIF.
		public static final int PU_RESULT_ERR_POINT_OUTOF_RANGE = 10211;
		public static final int PU_RESULT_ERR_LINE_BECOME_POINT = 10212;
		public static final int PU_RESULT_ERR_LINE_CROSS = 10213;
		public static final int PU_ERROR_ISP_AE_MANUAL_CONFLICT_WD = 10214; // Manual exposure and WDR are mutually
																			// exclusive.
		public static final int PU_ERROR_ISP_AE_MANUAL_CONFLICT_FLICKER = 10215; // The manual exposure and background
																					// frequency are mutually exclusive.
		public static final int PU_ERROR_ISP_AE_MANUAL_CONFLICT_HLC = 10216; // Manual exposure and highlight
																				// compensation are mutually exclusive.
		public static final int PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_WD = 10217; // Manual exposure and WDR are mutually
																				// exclusive.
		public static final int PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_FLICKER = 10218; // The shutter priority exposure mode
																					// and background frequency are
																					// mutually exclusive.
		public static final int PU_ERROR_ISP_AE_SHUTPRI_CONFLICT_HLC = 10219; // The shutter priority exposure mode and
																				// highlight compensation are mutually
																				// exclusive.
		public static final int PU_ERROR_ISP_BACKLIGHT_CONFLICT_WD = 10220; // Backlight compensation and WDR are
																			// mutually exclusive.
		public static final int PU_ERROR_ISP_BACKLIGHT_CONFLICT_HLC = 10221; // Backlight compensation and highlight
																				// compensation are mutually exclusive.
		public static final int PU_ERROR_ISP_WD_CONFLICT_HLC = 10222; // WDR and highlight compensation are mutually
																		// exclusive.
		public static final int PU_ERROR_ISP_DEFOG_CONFLICT_WD = 10223; // The defogging mode and WDR are mutually
																		// exclusive.
		public static final int PU_ERROR_ISP_HLC_CONFLICT_FRAMERATE = 10224; // Highlight compensation is mutually
																				// exclusive with the frame rate of 50
																				// or 60 fps.
		public static final int PU_ERROR_ISP_WD_CONFLICT_FRAMERATE = 10225; // WDR is mutually exclusive with the frame
																			// rate of 50 or 60 fps.
		public static final int PU_ERROR_ISP_AE_MANUAL_CONFLICT_BACKLIGHT = 10226; // Manual exposure and backlight
																					// compensation are mutually
																					// exclusive.
		public static final int PU_ERROR_ISP_HLC_CONFLICT_SLOW_SHUTTER = 10227; // Highlight compensation and slow
																				// shutter are mutually exclusive.
		public static final int PU_ERROR_ISP_WD_CONFLICT_SLOW_SHUTTER = 10228; // WDR and slow shutter are mutually
																				// exclusive.
		public static final int PU_ERROR_CODE_DOWNLOAD_FILE_ERROR = 10300; // File download failed.
		public static final int PU_ERROR_CODE_CONNECTION_SERVER_INTERRUPTED = 10301; // Disconnected from the server.
		public static final int PU_ERROR_CODE_REQUEST_OVERTIME = 10302; // Request timeout.
		public static final int PU_ERROR_CODE_CONNECTION_SERVER_FAIL = 10303; // Server connection failure.
		public static final int PU_ERROR_CODE_CONNECTION_NOT_FOUND = 10304; // The connection is not found.
		public static final int PU_ERROR_CODE_RECONNECTING_TO_SERVER = 10305; // Reconnecting to the server...
		public static final int PU_ERROR_CODE_FILE_NOT_EXIST = 10306; // The file does not exist.
		public static final int PU_ERROR_CODE_INVALID_UPDATEFILE = 10310; // Invalid upgrade file.
		public static final int PU_ERROR_CODE_UPDATEFILE_BAD = 10311; // The file is corrupted.
		public static final int PU_ERROR_CODE_INVALID_FILE_FORMAT = 10312; // Incorrect file format.
		public static final int PU_ERROR_CODE_UPGRADE_TYPE_ERR = 10350; // The upgrade file type does not match the
																		// request type.
		public static final int PU_ERROR_CODE_UPGRADE_PARAM_NULL = 10351; // The upgrade parameter is empty.
		public static final int PU_ERROR_CODE_UPGRADE_NOT_UPLOAD = 10352; // The upgrade file is not uploaded.
		public static final int PU_ERROR_CODE_UPGRADE_VERIFY_FAIL = 10353; // Failed to verify the integrity of the
																			// upgrade file.
		public static final int PU_ERROR_CODE_UPGRADE_SIGN_FAIL = 10354; // Failed to verify the digital signature of
																			// the upgrade file.
		public static final int PU_ERROR_CODE_UPGRADE_SPACE_FULL = 10355; // The upgrade storage space is full.
		public static final int PU_ERROR_CODE_UPGRADE_DEVICE_FAIL = 10356; // Failed to adapt the device list.
		public static final int PU_ERROR_RESULT_ALG_VER_ERR_U = 10357; // The algorithm package version is incorrect.
																		// The algorithm package version must be
																		// consistent with the VRC version of the
																		// software package.
		public static final int PU_ERROR_RESULT_ALG_VER_NEED_UPGRADE_U = 10358; // The algorithm package needs to be
																				// upgraded after the version package is
																				// upgraded.
		public static final int PU_ERROR_SD_NOT_FORMAT = 10601; // The SD card is not formatted.
		public static final int PU_ERROR_CODE_CUSTOM_PACKAGE_UNDEFINED = 10602; // The customized profile is not
																				// defined.
		public static final int PU_ERROR_CODE_PTZ_BUSY = 10603; // The PTZ is not stopped.
		public static final int PU_ERROR_CODE_OSDI_AREA_NOT_EXIST = 10700; // The area does not exist. The index value
																			// is incorrect.
		public static final int PU_ERROR_CODE_OSDI_AREA_TOO_LARGE = 10701; // The horizontal width of the area exceeds
																			// 180 degrees.
		public static final int PU_ERROR_CODE_OSDI_AREA_INVALID_VERDEGREE = 10702; // The area coordinate does not
																					// comply with the lower-left and
																					// upper-right rules.
		public static final int PU_ERROR_CODE_OSDI_INDEX_AlREADY_EXIST = 10705; // The index number of the new area is
																				// invalid. The index already exists.
		public static final int PU_ERROR_CODE_OSDI_HOR_OR_VER_EQUAL = 10708; // The horizontal coordinate and vertical
																				// coordinate of the area are the same.
		public static final int PU_ERROR_CODE_OSDI_INDEX_INVALID = 10709; // The area index number is invalid. It must
																			// be smaller than 1.
		public static final int PU_ERROR_CODE_OSDI_INDEX_EQUAL = 10710; // Duplicate index number of the area.
		public static final int PU_ERROR_CODE_DST_ALREADY_OPEN = 10800; // The DST has been enabled.
		public static final int PU_STABILIZER_CONFLICT_AREA_CROP = 10900; // Failed to enable the electronic image
																			// stabilization function. This function is
																			// mutually exclusive with area cropping.
		public static final int PU_AREA_CROP_CONFLICT_STABILIZER = 10901; // Failed to enable area cropping. This
																			// function is mutually exclusive with the
																			// electronic image stabilization function.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_POINT_NULL = 10950; // Null pointer.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_READ_FILE = 10951; // Failed to read the file.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_XML_PARSER = 10952; // XML parsing.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_IMG_TPYE = 10953; // Image type.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_RESOLUTION_DIFF = 10954; // The resolution is different from
																						// the initial resolution.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_VERTEX_ILLEGAL = 10955; // Improper coordinates.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_RESOLUTION_UNSUPPORT = 10956; // Unsupported resolution.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_PARAM_ERR = 10957; // Parameter error.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_MALLOC_FAILED = 10958; // Memory allocation failed.
		// Control error.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_NOT_CONFIG = 10961; // Configuration error.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_PARAM_SET = 10962; // The parameter is set incorrectly.
		// Incorrect lane line.
		public static final int PU_ERROR_CODE_ITGT_IMRS_ERR_LANE_OVERLAP = 10963; // Incorrect lane line.
		public static final int PU_ERROR_RESULT_VLPR_ERR_LINE_OUTOF_RANGE = 10964; // Setting failed. The detection line
																					// is out of the lane line.
		public static final int PU_ERROR_CODE_SHORT_KEY = 11001; // The certificate key is too short.
		public static final int PU_ERROR_CODE_WEAK_CERT = 11002; // The certificate key is too weak.
		public static final int PU_ERROR_CODE_GET_TEMPERTURE_VW_RET_FAIL = 11024; // Failed to invoke the VM interface.
																					// For example, the driver is
																					// invoked to obtain the
																					// temperature.
		public static final int PU_RESULT_ITS_ERR_INVALID_LANE_TYPE = 11100; // The lane line type is out of range.
		public static final int PU_RESULT_ITS_ERR_INVALID_LANE_NUM = 11101; // The number of lanes is out of range.
		public static final int PU_RESULT_ITS_ERR_INVALID_LANE_DIR = 11102; // Invalid lane direction.
		public static final int PU_RESULT_ITS_ERR_INVALID_LANE_DRV_DIR = 11103; // Invalid regulated driving direction
																				// of the lane.
		public static final int PU_RESULT_ITS_ERR_INVALID_LANE_PURPOSE = 11104; // Invalid lane usage.
		public static final int PU_RESULT_ITS_ERR_INVALID_LANE_ATTR = 11105; // Invalid lane attribute.
		public static final int PU_RESULT_ITS_ERR_INVALID_CAR_DRV_DIR = 11106; // Invalid driving direction.
		public static final int PU_RESULT_ITS_ERR_INVALID_SIGN_DIR = 11107; // Invalid marked direction.
		public static final int PU_RESULT_ITS_ERR_INVALID_NORMAL_SIGN_SPEED = 11108; // Invalid marked speed for small
																						// vehicles.
		public static final int PU_RESULT_ITS_ERR_INVALID_NORMAL_LOW_SPEED = 11109; // Invalid lower speed limit for
																					// small vehicles.
		public static final int PU_RESULT_ITS_ERR_INVALID_NORMAL_HIGH_SPEED = 11110; // Invalid upper speed limit for
																						// small vehicles.
		public static final int PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SIGN_SPEED = 11111; // Invalid marked speed for
																							// large vehicles.
		public static final int PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_LOW_SPEED = 11112; // Invalid lower speed limit for
																						// large vehicles.
		public static final int PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_HIGH_SPEED = 11113; // Invalid upper speed limit
																							// for large vehicles.
		public static final int PU_RESULT_ITS_ERR_INVALID_EXTERN_LAMP_BITMAP = 11114; // Invalid external illuminator
																						// association.
		public static final int PU_RESULT_ITS_ERR_INVALID_SNAP_INTERVAL = 11115; // The snapshot interval is out of
																					// range.
		public static final int PU_RESULT_ITS_ERR_INVALID_DT_TYPE = 11116; // The detection mode is out of range.
		public static final int PU_RESULT_ITS_ERR_INVALID_REGULATION_NUM = 11117; // The number of violations exceeded
																					// the maximum.
		public static final int PU_RESULT_ITS_ERR_INVALID_REGULATION_TYPE = 11118; // Invalid violation type.
		public static final int PU_RESULT_ITS_ERR_INVALID_SNAP_NUM = 11119; // The number of traffic violation snapshots
																			// is out of range.
		public static final int PU_RESULT_ITS_ERR_INVALID_RUNNINGRED_PRIORITY = 11120; // Invalid red-light-running
																						// detection priority.
		public static final int PU_RESULT_ITS_ERR_INVALID_OVER_LANE_SENSITIVITY = 11121; // The sensitivity for
																							// detecting marked lanes
																							// violations is invalid.
		public static final int PU_RESULT_ITS_ERR_INVALID_VINBIKELANE_STAYTIME = 11122; // The dwell duration for
																						// detecting motor vehicles on
																						// non-motor vehicle lanes is
																						// invalid.
		public static final int PU_RESULT_ITS_ERR_INVALID_OVER_BUSLANE_STAYTIME = 11123; // Invalid bus lane occupation
																							// time.
		public static final int PU_RESULT_ITS_ERR_INVALID_PARKINGTIME = 11124; // Invalid dwell duration for detecting
																				// parking in yellow zones.
		public static final int PU_RESULT_ITS_ERR_INVALID_LIGHT_DT_TYPE = 11125; // The traffic light access mode is out
																					// of range.
		public static final int PU_RESULT_ITS_ERR_INVALID_LIGHT_AREA_NUM = 11126; // Invalid number of traffic light
																					// areas.
		public static final int PU_RESULT_ITS_ERR_INVALID_LIGHT_NUM = 11127; // Invalid number of traffic lights.
		public static final int PU_RESULT_ITS_ERR_INVALID_LIGHT_ARRANGE_TYPE = 11128; // Invalid traffic light
																						// direction.
		public static final int PU_RESULT_ITS_ERR_INVALID_YELLOW_TIME = 11129; // Invalid duration of the yellow light.
		public static final int PU_RESULT_ITS_ERR_INVALID_LIGHT_AREA = 11130; // Invalid traffic light area.
		public static final int PU_RESULT_ITS_ERR_LINE_OUTOF_RANGE = 11131; // The detection line or stop line is out of
																			// the lane line or right boundary line
																			// range.
		public static final int PU_RESULT_ITS_ERR_INVALID_NORMAL_SPEED_RANGE_CONFIG = 11132; // If the lower speed limit
																								// for small vehicles is
																								// greater than the
																								// upper speed limit, an
																								// error is returned.
		public static final int PU_RESULT_ITS_ERR_INVALID_NORMAL_SIGN_SPEED_CONFIG = 11133; // If the marked speed for
																							// small vehicles is out of
																							// range, an error is
																							// returned.
		public static final int PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SPEED_RANGE_CONFIG = 11134; // If the lower speed
																									// limit for large
																									// vehicles is
																									// greater than the
																									// upper speed
																									// limit, an error
																									// is returned.
		public static final int PU_RESULT_ITS_ERR_INVALID_BIGVEHICLE_SIGN_SPEED_CONFIG = 11135; // If the marked speed
																								// for large vehicles is
																								// out of range, an
																								// error is returned.
		public static final int PU_RESULT_ITS_ERR_INVALID_RETURNDATA = 11136;
		public static final int PU_RESULT_ITS_ERR_INVALID_CONGESTION_THRESHOLD = 11137;
		public static final int PU_RESULT_ITS_ERR_INVALID_SNAP_INTERVAL_TYPE = 11138; // Invalid snapshot interval type.
		public static final int PU_RESULT_ITS_ERR_INVALID_ADAPT_SNAP_LOWSPEED = 11139; // The maximum low speed of the
																						// adaptive snapshot interval is
																						// invalid.
		public static final int PU_RESULT_ITS_ERR_INVALID_ADAPT_SNAP_MIDSPEED = 11140; // The maximum medium speed of
																						// the adaptive snapshot
																						// interval is invalid.
		public static final int PU_RESULT_ITS_ERR_INVALID_ADAPT_LOWSPEED_INTERVAL = 11141; // The adaptive low-speed
																							// snapshot interval is
																							// invalid.
		public static final int PU_RESULT_ITS_ERR_INVALID_ADAPT_MIDSPEED_INTERVAL = 11142; // The adaptive medium-speed
																							// snapshot interval is
																							// invalid.
		public static final int PU_RESULT_ITS_ERR_INVALID_ADAPT_HISPEED_INTERVAL = 11143; // The adaptive high-speed
																							// snapshot interval is
																							// invalid.
		public static final int PU_RESULT_ITS_ERR_INVALID_LANE_ORDER = 11144; // Setting failed. Draw lane lines and the
																				// right lane boundary from left to
																				// right in sequence.

		// Algorithm conflict error codes
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_LRPR = 12000; // Failed to set license plate recognition
																			// because it conflicts with facial
																			// recognition, behavior analysis, or
																			// parking detection.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_FD = 12001; // Failed to set face detection because it
																			// conflicts with license plate recognition
																			// or parking detection.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_CD = 12002; // Failed to set parking detection because it
																			// conflicts with facial recognition,
																			// license plate recognition, or behavior
																			// analysis.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_VA = 12003; // Failed to set behavior analysis because it
																			// conflicts with license plate recognition
																			// or behavior analysis.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_HC = 12004; // Failed to set head counting because it
																			// conflicts with license plate recognition,
																			// facial recognition, parking detection, or
																			// automatic tracking.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_AT = 12005; // Failed to set automatic tracking because it
																			// conflicts with license plate recognition,
																			// facial recognition, parking detection, or
																			// head counting.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_VHD = 12006; // Disable the object classification function
																			// first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_ITS = 12007; // Disable the ITS function first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_QD = 12008; // Disable the queue detection function first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_CDD = 12009; // Disable the crowd density detection
																			// function first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_IBALL = 12010; // Disable the traffic violation detection
																				// of the PTZ dome camera first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_VHDFACE = 12011; // Disable the full intelligence mode
																				// first.
		public static final int PU_RESULT_ITGT_MODE_NOTSUPPORT_ALG = 12012; // This algorithm is not supported in the
																			// current mode.
		public static final int PU_RESULT_TGT_VHD_DETECTION_ERR_WRONG_VIDEO_MODE = 12013; // Object classification does
																							// not support the corridor
																							// mode. Disable the
																							// corridor mode first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_BEH = 12014; // Disable the behavior analysis function in
																			// enhanced mode.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_CAMPUS_TRAFFICEVENT = 12015; // Disable vehicle detection
																							// at entrances and exits
																							// first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_CAMPUS_ALG_TYPE = 12016; // The vehicle detection at
																						// entrances and exits supports
																						// only Chinese license plate
																						// recognition algorithms.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_MD = 12017; // Disable the motion detection function
																			// first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_OD = 12018; // Disable the lens blocking detection
																			// function first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_SC = 12019; // Disable the scene change detection
																			// function.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_OOD = 12020; // Disable the defocus detection function
																			// first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_CA = 12021; // Disable the crowd gathering detection
																			// function first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_HM = 12022; // Disable the heat map function first.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_TRAFFICEVENT_CAMPUS = 12023; // Disable all vehicle event
																							// detection functions.
		public static final int PU_RESULT_TGT_FUNCTION_MUTUAL_TRAFFIC_STATISTIC_CAMPUS = 12024; // Disable the traffic
																								// flow statistics
																								// function first.

		// Error codes related to face images and face libraries
		public static final int PU_RESULT_ITGT_ERR_FACE_SUCCESS = 12100; // Face library imported successfully.
		public static final int PU_RESULT_ITGT_ERR_FACEREC_DISABLE = 12101; // Facial recognition is not enabled.
		public static final int PU_RESULT_ITGT_ERR_DATA_UPDATE = 12102; // Failed to update the data.
		public static final int PU_RESULT_ITGT_ERR_OPREATION_NOTSUPPORT = 12103; // The operation is not supported.
		public static final int PU_RESULT_ITGT_ERR_OPREATION_UNFINISHED = 12104; // The batch import operation is not
																					// complete.
		public static final int PU_RESULT_ITGT_ERR_FACELIB_OVERSIZE = 12105; // The number of face libraries exceeds the
																				// upper limit.
		public static final int PU_RESULT_ITGT_ERR_FACinterface_OVERSIZE = 12106; // The number of faces exceeds the
																					// upper limit.
		public static final int PU_RESULT_ITGT_ERR_DB_ERROR = 12107; // Failed to operate the database.
		public static final int PU_RESULT_ITGT_ERR_FACELIST_REPAT = 12108; // Duplicate face library.
		public static final int PU_RESULT_ITGT_ERR_FACEPIC_OVERSIZE = 12109; // The image width or height is out of
																				// range.
		public static final int PU_RESULT_ITGT_ERR_FACE_DECODE = 12110; // Image decoding failure.
		public static final int PU_RESULT_ITGT_ERR_FACE_DETECTION = 12111; // Face detection failure.
		public static final int PU_RESULT_ITGT_ERR_FACE_FEATURE = 12112; // Failed to extract facial features.
		public static final int PU_RESULT_ITGT_ERR_FACE_DAO = 12113; // Failed to write face data into the database.
		public static final int PU_RESULT_ITGT_ERR_FACE_FILE = 12114; // Failed to write face data into the file.
		public static final int PU_RESULT_ITGT_ERR_FACE_ALGDISABLE = 12115; // The face-related algorithm is disabled.
		public static final int PU_RESULT_ITGT_ERR_FACE_NOFEATURE = 12116; // There is no feature in the face library.
		public static final int PU_RESULT_ITGT_ERR_FACE_UZIP = 12117; // Failed to decompress the ZIP package.
		public static final int PU_RESULT_ITGT_ERR_FACE_CSV = 12118; // Failed to parse the CSV file.
		public static final int PU_RESULT_ITGT_ERR_FACE_ENCRYPT = 12119; // Failed to encrypt or decrypt face data.
		public static final int PU_RESULT_ITGT_ERR_FACE_TASKUNKNOW = 12120; // The task is not processed.
		public static final int PU_RESULT_ITGT_ERR_FEATURE_EXTRACT_SUCCESS = 12121; // Features extracted successfully.
		public static final int PU_RESULT_ITGT_ERR_FEATURE_EXTRACTED = 12122; // Features extracted.
		public static final int PU_RESULT_ITGT_ERR_FACEREC_ENABLE_FAIL = 12123; // The facial recognition function fails
																				// to be enabled because the algorithm
																				// package does not exist or the version
																				// does not match.
		public static final int PU_RESULT_ITGT_ERR_FACE_FEATURE_LOAD_PROCESSING = 12124; // Facial recognition has
																							// historical alert
																							// deployment. Features need
																							// to be loaded when the
																							// system is started.
		public static final int PU_RESULT_ITGT_ERR_FACE_FEATURE_PAC_IMPORT_PROCESSING = 12125; // The feature package is
																								// being imported.
		public static final int PU_RESULT_ITGT_ERR_FACE_PIC_PAC_IMPORT_PROCESSING = 12126; // The image package is being
																							// imported.
		public static final int PU_RESULT_ITGT_ERR_FACE_FEATURE_GET_PROCESSING = 12127; // Features are being exported.
		public static final int PU_RESULT_ITGT_ERR_FACE_FEATURE_EXTRACT_PROCESSING = 12128; // Features are being
																							// extracted.

		// Parking detection error codes
		public static final int PU_RESULT_TGT_CAR_DATECTION_ERR_WRONG_VIDEO_MODE = 12200; // When parking detection is
																							// enabled, the corridor
																							// mode and mirroring mode
																							// must be disabled.
		public static final int PU_RESULT_ITGT_VHD_ERR_WRONG_VIDEO_MODE = 12201; // The object classification and the
																					// corridor mode cannot be enabled
																					// at the same time.
		public static final int PU_RESULT_ITGT_VLPR_ERR_WRONG_VIDEO_MODE = 12202; // The vehicle recognition and the
																					// corridor mode cannot be enabled
																					// at the same time.
		public static final int PU_RESULT_ITGT_NOT_FACE_DETETION_MODE_ERR_WRONG_VIDEO_MODE = 12203; // (The corridor
																									// mode must be
																									// disabled for -H
																									// camera models in
																									// non-face
																									// checkpoint mode
																									// (not supported in
																									// full
																									// intelligence,
																									// micro checkpoint,
																									// and behavior
																									// analysis modes).)
		public static final int PU_RESULT_LIC_INVALID = 12300; // Failed to obtain the license content due to the
																// invalid license.
		public static final int PU_RESULT_LIC_REPEATED_ESN_VER_MISMATCH = 12301; // The ESN cannot be loaded repeatedly
																					// or the license file that does not
																					// match the device version cannot
																					// be loaded.
		public static final int PU_RESULT_LIC_FORMAT_ERROR = 12302; // Invalid license file.
		public static final int PU_RESULT_LIC_NO_PRD_FEATURES_PRESENT = 12303; // The license file does not contain the
																				// product feature segment.
		public static final int PU_RESULT_LIC_PRODUCT_INVALID = 12304; // Invalid product name.
		public static final int PU_RESULT_LIC_EXPIRED = 12305; // The license file has expired.
		public static final int PU_RESULT_LIC_GET_CONFIG_ERROR = 12306; // Failed to obtain the control item
																		// configuration.
		public static final int PU_RESULT_LIC_LSN_REVOKED = 12307; // The license file has expired.
		public static final int PU_RESULT_LIC_ESNANY_AND_SIX_MON_VLDITY_NOT_ALLOWED = 12308; // You are not allowed to
																								// repeatedly load a
																								// commissioning license
																								// file whose ESN is ANY
																								// and validity period
																								// is six months.
		public static final int PU_RESULT_LIC_MAX_FEATURES_REACHED = 12309; // The number of features in the license
																			// file exceeds the maximum.
		public static final int PU_RESULT_LIC_INVALID_FEATURE_TYPE = 12310; // The feature type in the license file is
																			// incorrect.
		public static final int PU_RESULT_LIC_LM_NOT_ENABLED = 12311; // The license component is not started.
		public static final int PU_RESULT_LIC_NO_FEATURES_IN_NORMAL_STATE = 12312; // All features in the license file
																					// expired or are in the trial
																					// period.
		public static final int PU_RESULT_LIC_ESN_MISMATCH = 12313; // The ESN in the license file is different from the
																	// actual ESN.
		public static final int PU_RESULT_LIC_VERSION_MISMATCH = 12314; // The device version in the license file is
																		// different from the actual version.
		public static final int PU_RESULT_LIC_NO_LICENSE_ACTIVITED = 12315; // No activated license.

		public static final int PU_RESULT_MTU_ERR_WITH_IPV6_OPEN = 12520; // The MTU is incorrect in the IPv6 scenario.
		public static final int PU_RESULT_ITGT_ERR_INVALID = 12600; // Invalid intelligent analysis license.
		public static final int PU_RESULT_MEDIA_UTGT_NOT_ENABLED = 12780; /*
																			 * An intelligent analysis channel needs to
																			 * be created for media streams, but the
																			 * intelligent analysis module is not
																			 * enabled.
																			 */
		// Algorithm switchover
		public static final int PU_RESULT_TGT_SWITCH_MODE_ERR_WRONG_VIDEO_MODE = 12800; // The switched mode does not
																						// support the corridor mode.
		public static final int PU_RESULT_TGT_SWITCH_MODE_ERR_ENABLE_ALG = 12801; // Failed to enable the algorithm for
																					// the switched mode. Check the
																					// model.
		public static final int PU_RESULT_TGT_SWITCH_MODE_FTP_NEED_RECONFIG = 12802; // The mode is switched
																						// successfully. The FTP needs
																						// to be reconfigured.
		public static final int PU_ERROR_MAX = 20000;
	}

	public interface FACE_DT_CAP_MODE_E {
		int FACE_CAP_DEFAULT_MODE = 0; // Default snapshot mode. A snapshot is taken after the object leaves the
										// surveillance view.
		int FACE_CAP_QUICK_MODE = 1; // Fast snapshot mode.
	}

	public static class FD_AREA_S extends Structure {
		public BOOL bEnable;
		public int uiPointNum;
		public PU_SQUARE_PARA[] stPoint = new PU_SQUARE_PARA[FD_AREA_POINT_NUM];
		public byte[] szAreaName = new byte[FD_AREA_NAME_LEN];

		public FD_AREA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "uiPointNum", "stPoint", "szAreaName");
		}
	}

	// Park action parameters setting
	public class GUARD_PARA extends Structure {
		public WinDef.ULONG ulPtzId;

		public WinDef.BOOL bEnable;
		public WinDef.ULONG ulWaitTime;
		public int enGuardType; // Park actions.
		public PU_GUARD_POINT_PARA unGuardPara = new PU_GUARD_POINT_PARA(); // Park action parameters.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public GUARD_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPtzId", "bEnable", "ulWaitTime", "enGuardType", "unGuardPara", "szReserved");
		}

		@Override
		public void write() {
			super.write();
			switch (enGuardType) {
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_PRESET:
				unGuardPara.setType(unGuardPara.stPresetPara.getClass());
				unGuardPara.write();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_CRUISE:
				unGuardPara.setType(unGuardPara.stCruisePara.getClass());
				unGuardPara.write();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_USER_DEFINED:
				unGuardPara.setType(unGuardPara.stUserDefinedPara.getClass());
				unGuardPara.write();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_HORIZONTAL:
				unGuardPara.setType(unGuardPara.stHorPara.getClass());
				unGuardPara.write();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_FRAME:
				unGuardPara.setType(unGuardPara.stFramePara.getClass());
				unGuardPara.write();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_RANDOM:
				unGuardPara.setType(unGuardPara.stRandomPara.getClass());
				unGuardPara.write();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_PANORAMA:
				unGuardPara.setType(unGuardPara.stPanoramePara.getClass());
				unGuardPara.write();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_VERTICAL:
				unGuardPara.setType(unGuardPara.stVerticalPara.getClass());
				unGuardPara.write();
				break;

			default:
				break;
			}
		}
	}

	// Home position parameters (only for preset positions).
	public class GUARD_POSITION_PARA extends Structure {
		public WinDef.ULONG ulPtzId;

		public WinDef.BOOL bEnable;
		public WinDef.ULONG ulPresetIndex;
		public WinDef.ULONG ulWaitTime;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public GUARD_POSITION_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPtzId", "bEnable", "ulPresetIndex", "ulWaitTime", "szReserved");
		}
	}

	// Park action parameters setting
	public class GUARD_POSITION_PARA_EX extends Structure {
		public WinDef.ULONG ulPtzId;

		public WinDef.BOOL bEnable;
		public WinDef.ULONG ulWaitTime;
		public int enGuardType; // Park actions.
		public PU_GUARD_POINT_PARA unGuardPara = new PU_GUARD_POINT_PARA(); // Park action parameters.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public GUARD_POSITION_PARA_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPtzId", "bEnable", "ulWaitTime", "enGuardType", "unGuardPara", "szReserved");
		}

		@Override
		public void read() {
			super.read();
			switch (enGuardType) {
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_PRESET:
				unGuardPara.setType(unGuardPara.stPresetPara.getClass());
				unGuardPara.read();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_CRUISE:
				unGuardPara.setType(unGuardPara.stCruisePara.getClass());
				unGuardPara.read();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_USER_DEFINED:
				unGuardPara.setType(unGuardPara.stUserDefinedPara.getClass());
				unGuardPara.read();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_HORIZONTAL:
				unGuardPara.setType(unGuardPara.stHorPara.getClass());
				unGuardPara.read();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_FRAME:
				unGuardPara.setType(unGuardPara.stFramePara.getClass());
				unGuardPara.read();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_RANDOM:
				unGuardPara.setType(unGuardPara.stRandomPara.getClass());
				unGuardPara.read();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_PANORAMA:
				unGuardPara.setType(unGuardPara.stPanoramePara.getClass());
				unGuardPara.read();
				break;
			case PU_GUARD_POINT_TYPE.PU_GUARD_POINT_VERTICAL:
				unGuardPara.setType(unGuardPara.stVerticalPara.getClass());
				unGuardPara.read();
				break;

			default:
				break;
			}
		}
	}

	// IPC module.
	public interface IPC_MODULE {
		public static final int IPC_WEB_MODULE = 0; // Web module.
		public static final int IPC_SDK_MODULE = 1; // SDK module.
	}

	public interface ITS_ROAD_LINE_TYPE_E {
		int ITS_ROAD_LINE_TYPE_WHITE_SOLOD = 0; /* Solid white line. */
		int ITS_ROAD_LINE_TYPE_WHITE_DOTTED = 1; /* Broken white line. */
		int ITS_ROAD_LINE_TYPE_SINGLE_YELLOW = 2; /* Single yellow line. */
		int ITS_ROAD_LINE_TYPE_DOUBLE_YELLOW = 3; /* Double yellow lines. */
		int ITS_ROAD_LINE_TYPE_GUARD_BAR = 4; /* Lane line with guardrail. */
	}

	// Lane scene.
	public interface ITS_ROAD_SIDE_SCENE_E {
		int ITS_MEDIAN_ROAD_SIDE = 0; // Isolation belt.
		int ITS_REALLINE_ROAD_SIDE = 1; // Solid line.
		int ITS_DOTLINE_ROAD_SIDE = 2; // Dashed line.
		int ITS_UNKNOWN_ROAD_SIDE = 10; // Unknown scene.
	}

	public interface LANE_DIRECTION_E {
		int LANE_DIRECTION_DOWN = 0; /* From top to bottom. */
		int LANE_DIRECTION_UP = 1; /* From bottom to top. */
		int LANE_DIRECTION_UNDEF = 2; /*
										 * The direction is not defined, so wrong-way driving cannot be detected. Only
										 * the vehicle speed is provided.
										 */
	}

	// Null pointer.
	// public interface
	// {
	// SINGLE_PACKET = 0xAA;
	// SLICE_HEAD_PACKET = 0xBB;
	// SLICE_MID_PACKET = 0xCC;
	// SLICE_TAIL_PACKET = 0xDD;
	// META_DATA_PACKET_TYPE_MAX = 0xFF
	// }
	/// <summary>
	/// Layer-1 metadata type.
	/// </summary>
	public interface LAYER_ONE_TYPE {
		public static final int METADATA_TYPE = 0x4154454D; // M'' E' 'T'' A' little endian.
	}

	public interface LAYER_THREE_TYPE_E {
		public static final int PTS = 0x09000001; // Timestamp.
		public static final int ITGT_TYPE = 0x07000011; // Intelligent type.
		public static final int IMG_WIDTH = 0x07000100; // Image width.
		public static final int IMG_HEIGHT = 0x07000101; // Image height.
		public static final int FACE_SCORE = 0x04000013; // Face confidence.
		public static final int FACE_ANGLE = 0x04000014; // Face angle.
		public static final int FACE_ID = 0x07000016; // Face ID.
		public static final int FACE_PANOPIC_SIZE = 0x07000018; // Full face image size.
		public static final int FACE_FACEPIC_SIZE = 0x07000019; // Face cutout image size.
		public static final int FACE_PIC_TIME = 0x08000015; // Time when a face cutout is generated.
		public static final int FACE_PIC_TZONE = 0x08000020; // Time zone of the face cutout device, in milliseconds. +
																// indicates an eastern time zone, and - indicates a
																// western time zone.
		public static final int HUMAN_FEATURE = 0x10000002; // Personal attribute recognition.
		public static final int FACE_FEATURE = 0x11000003; // Facial attribute recognition.
		public static final int PANORAMA_PIC = 0x0A00000A; // Full image.
		public static final int FACE_PIC = 0x0A000012; // Face cutout.
		public static final int FACE_PIC_KPS = 0x07000012; // Quality filtering flag of the face cutout KPS.
		public static final int HUMAN_PIC = 0x0A000013; // Person cutout.
		public static final int HUMAN_PIC_KPS = 0x07000013; // Quality filtering flag of the person cutout KPS.
		public static final int HUMAN_PIC_ROI = 0x0B000017; // Frame for person cutout.
		public static final int FACE_PANORAMA = 0x0A000017; // Full face image.
		public static final int FACE_PIC_POSITION = 0x0B000011; // Position of the frame for face cutout.
		public static final int FACE_POS = 0x0B000012; // Face position (real-time frame position).
		public static final int HUMAN_RECT = 0x0B000013; // Person position (real-time frame position).
		public static final int HUMAN_RECT_POSITION = 0x0B000014; // Position of the frame for person cutout.
		public static final int FACE_MATCH = 0x0A000014; // Matching image in the face library.
		public static final int FACELIB_RECORDID = 0x07000017; // Face ID in the face library, which is used to maintain
																// the consistency of feature records.
		public static final int FACE_MATCHRATE = 0x07000020; // Face match rate.
		public static final int FACE_INFO = 0x12000001; // Face information, corresponding to the information in the
														// database.
		public static final int FACE_LIB_TYPE = 0x07000022; // Face library type.
		public static final int FACE_LIB_NAME = 0x0A000015; // Face library name.
		public static final int TARGET_TYPE = 0x07000023; // Object type, which is used to differentiate face cutout,
															// facial recognition, and facial recognition in
															// multi-camera collaboration mode.
		public static final int FACE_LIB_ID = 0x07000024; // Face library ID.
		public static final int MMC_FACE_COMPARE_NUM_MAX = 0x07000025; // Multi-camera collaboration algorithm parameter
																		// (face match data).
		public static final int MMC_FACE_WARNING_RECALL_RATE_MAX = 0x07000026; // Multi-camera collaboration algorithm
																				// parameter (maximum face alarm recall
																				// rate).
		public static final int MMC_FACE_WARNING_RECALL_RATE_MIN = 0x07000027; // Multi-camera collaboration algorithm
																				// parameter (minimum face alarm recall
																				// rate).
		public static final int OBJ_ID = 0x07000021; // Object ID.
		public static final int OBJ_STATUS = 0x06000022; // Object status.
		public static final int OBJ_POS = 0x0B000023; // Object position.
		public static final int OBJ_TYPE = 0x06000024; // Object type.
		public static final int OBJ_SPEED = 0x0C000025; // Object speed.
		public static final int OBJ_UPHALF_COLOR = 0x0F000026; // Object tops color.
		public static final int OBJ_DOWNHALF_COLOR = 0x0F000027; // Object bottoms color.
		public static final int RULE_TYPE = 0x07000031; // Rule type.
		public static final int RULE_LINE_POS = 0x0D000032; // Rule line position.
		public static final int RULE_LINE_DIR = 0x07000033; // Rule line direction.
		public static final int RULE_AREA_POS = 0x0E000034; // Rule frame position.
		public static final int OBJ_POS_R = 0x0B000035; // Object position (relative position).
		public static final int OBJ_SPEED_R = 0x0C000036; // Object speed (relative position).
		public static final int RULE_LINE_POS_R = 0x0D000037; // Rule line position (relative position).
		public static final int RULE_AREA_POS_R = 0x0E000038; // Rule frame position (relative position).
		public static final int LANE_ID = 0x07000002; // Lane ID.
		public static final int VEHICLE_TYPE = 0x07000003; // Vehicle type.
		public static final int VEHICLE_TYPE_EXT = 0x07000406; // C50 vehicle type.
		public static final int VEHICLE_COLOR = 0x07000004; // Vehicle color.
		public static final int VEHICLE_DIRECTION = 0x07000005; // Vehicle driving direction.
		public static final int VEHICLE_POS = 0x0B000005; // Vehicle position.
		public static final int PLATE_TYPE = 0x07000006; // License plate type.
		public static final int PLATE_POS = 0x0B000007; // License plate position.
		public static final int PLATE_CHAR = 0x0A000008; // License plate characters.
		public static final int PLATE_PIC = 0x0A000009; // License plate cutout.
		public static final int PLATE_CONFIDENCE = 0x07000061; // License plate confidence.
		public static final int PLATE_COLOR = 0x07000062; // License plate color.
		public static final int PLATE_CHAR_POS = 0x0B000063; // License plate character position.
		public static final int PLATE_FACE_POS = 0x0B000064; // Vehicle front position.
		public static final int PLATE_MOVE_DIR = 0x07000065; // License plate movement direction.
		public static final int PLATE_SNAPSHOT_TYPE = 0x07000066; // License plate snapshot type.
		public static final int VEHICLE_PIC = 0x0A000067; // Close-up vehicle image.
		public static final int PIC_SNAPSHOT_TIMEMS = 0x09000003; // Snapshot time (unit: ms).
		public static final int PIC_SNAPSHOT_TIME = 0x07000068; // Snapshot time.
		public static final int PIC_SNAPSHOT_TZONE = 0x08000069; // Time zone of the device, in milliseconds. +
																	// indicates an eastern time zone, and - indicates a
																	// western time zone.
		public static final int DEVICE_ID = 0x0A000025; // Device ID.
		public static final int ROID_ID = 0x0A000026; // Road ID.
		public static final int DIR_ID = 0x0A000027; // Direction ID.
		public static final int DIR_INFO = 0x0A000028; // Direction information.
		public static final int PANORAMA_PIC_SIZE = 0x07000073; // Full image size.
		public static final int PLATE_PIC_SIZE = 0x07000074; // License plate image size.
		public static final int VLPR_ALG_TYPE = 0x07000079; // License plate algorithm type.
		public static final int REGULATION_CODE = 0x0A000029;// Violation code character string.
		public static final int ITS_TYPE = 0x04000032; // ITS application mode.
		public static final int VEHICLE_TL_X = 0x0400002A; // X coordinate of the upper left corner of the vehicle
															// position.
		public static final int VEHICLE_TL_Y = 0x0400002B; // Y coordinate of the upper left corner of the vehicle
															// position.
		public static final int VEHICLE_BR_X = 0x0400002C; // X coordinate of the lower right corner of the vehicle
															// position.
		public static final int VEHICLE_BR_Y = 0x0400002D; // Y coordinate of the lower right corner of the vehicle
															// position.
		public static final int PLATE_TL_X = 0x0400002E; // X coordinate of the upper left corner of the license plate
															// position.
		public static final int PLATE_TL_Y = 0x0400002F; // Y coordinate of the upper left corner of the license plate
															// position.
		public static final int PLATE_BR_X = 0x04000030; // X coordinate of the lower right corner of the license plate
															// position.
		public static final int PLATE_BR_Y = 0x04000031; // Y coordinate of the lower right corner of the license plate
															// position.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS = 0x070000A0;// Traffic flow statistics parameter.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_LANE_COUNT = 0x070000A1;// Number of lanes for vehicle
																						// traffic statistics of the
																						// micro checkpoint camera.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_LANE_INDEX = 0x070000A2;// Current lane for vehicle
																						// traffic statistics of the
																						// micro checkpoint camera.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_COUNT = 0x070000A3;// Vehicle quantity
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_AVG_SPEED = 0x070000A4;// Average vehicle speed.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_LANE_TIME_USED_RATIO = 0x070000A5;// Time occupancy.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_DENSITY = 0x070000A6;// Vehicle density.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_HEAD_INTERVAL = 0x070000A7;// Time headway.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_HEAD_SPACE_INTERVAL = 0x070000A8;// Space headway.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_CONGESTION_DEGREE = 0x070000A9;// Traffic status.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE1_COUNT = 0x070000AA;// Number of large
																								// vehicles.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE2_COUNT = 0x070000AB;// Number of medium
																								// vehicles.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE3_COUNT = 0x070000AC;// Number of small
																								// vehicles.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_QUEUE_LENGTH = 0x070000AD;// Queue length detection.
		public static final int MICRO_PORT_TRAFFIC_STATISTICS_LANE_SPACE_USED_RATIO = 0x070000AE;// Space occupancy.
		public static final int ITS_TRAFFIC_LEFT_VEHICLE_COUNT = 0x070000AF; // Number of left-turn vehicles (ITS).
		public static final int ITS_TRAFFIC_STRAIGHT_VHEICLE_COUNT = 0x070000B0; // Number of straight-through vehicles
																					// (ITS).
		public static final int ITS_TRAFFIC_RIGHT_VHEICLE_COUNT = 0x070000B1; // Number of right-turn vehicles (ITS).
		public static final int ITS_TRAFFIC_TIME_ZONE = 0x070000B2; // Vehicle traffic statistics time zone (ITS).
		public static final int ITS_TRAFFIC_SNAP_TIME = 0x070000B3; // Vehicle traffic statistics snapshot time (ITS).
		public static final int VEHICLE_SPEED = 0x07000075; // Vehicle speed.
		public static final int REGULATION_TYPE = 0x07000076; // Violation type.
		public static final int ITS_FLOWRATE_FEATURE = 0x07000077; // ITS traffic statistics attribute.
		public static final int VEHICLE_MFR_TYPE = 0x07000078; // Secondary motor vehicle feature.
		public static final int ITS_VEHICLE_FLOWRATE_FEATURE = 0x0700009A; // Vehicle traffic statistics attribute
																			// (ITS).
		public static final int MFR_MAIN_CALL = 0x06000025; // Hands-free device infraction (driver).
		public static final int MFR_MAIN_BELT = 0x06000026; // Seat belt infraction (driver).
		public static final int MFR_VICE_EXIST = 0x06000027; // Front passenger existence.
		public static final int MFR_VICE_BELT = 0x06000035; // Seat belt infraction (front passenger).
		public static final int MFR_YEAR_LOG = 0x06000036; // Annual inspection sticker.
		public static final int MFR_MAIN_SUN_VISOR = 0x06000030; // Sun visor (driver).
		public static final int MFR_VICE_SUN_VISOR = 0x06000031; // Sun visor (front passenger).
		public static final int MFR_NAP_KIN_BOX = 0x06000032; // Tissue box.
		public static final int MFR_CAR_PENDANT = 0x06000034; // Hanging accessory.
		public static final int ITS_TRAFFIC_STATE = 0x07000079; // Lane traffic status.
		public static final int CARDETECTION_POS = 0x0B000015; // Parking location.
		public static final int HUMANCOUNT_NUM = 0x0B000016; // Head count.
		public static final int VEHICLE_BODY_RECT = 0x0B000008; // Vehicle position.
		public static final int NOMOTOR_BODY_RECT = 0x0B000009; // Non-motor vehicle position.
		public static final int CAR_PRE_BRAND = 0x0A000007; // Vehicle brand, for example, Volkswagen.
		public static final int CAR_SUB_BRAND = 0x0A000022; // Vehicle model, for example, Santana.
		public static final int CAR_TYPE_BRAND = 0x0A000023; // Vehicle type, for example, car.
		public static final int CAR_YEAR_BRAND = 0x0A000024; // Model year, for example, 2011.
		public static final int VHD_OBJ_ID = 0x09000006; // Object (motor vehicle, non-motor vehicle, and pedestrian)
															// ID.
		public static final int CAR_PRE_BRAND_INDEX = 0x06000028; // Vehicle brand index, for example, Volkswagen.
		public static final int CAR_SUB_BRAND_INDEX = 0x06000029; // Vehicle model index, for example, Santana.
		public static final int DEV_CNT = 0x03000070; // Number of devices.
		public static final int CHAN_ID = 0x03000071; // Channel ID.
		public static final int SHOULDER_RECT = 0x0B000018; // Head and shoulder position (queue length).
		public static final int SHOULDER_NUM = 0x06000001; // Head count (queue length).
		public static final int QUEUE_TIME = 0x06000002; // Queuing duration.
		public static final int PEOPLE_NUM = 0X07000087; // Number of persons returned by the crowd density detection
															// algorithm.
		public static final int HEADSHOULDER_POS = 0X0B000088; // Frame position returned by the crowd density detection
																// algorithm.
		public static final int AREARATIO = 0X07000089; // Crowd density returned by the crowd density detection
														// algorithm.
		public static final int TRACK_OBJECT = 0x07000028; // Tracking object ID.
		public static final int SEX = 0X0700008A; // Sex.
		public static final int AGE = 0X0700008B; // Age.
		public static final int META_GLASSES = 0X0700008C; // Glasses.
		public static final int MOUTHMASK = 0X0700008D; // Mouth mask.
		public static final int UMBRELLA = 0X0700008E; // Umbrella.
		public static final int BACKPACK = 0X0700008F; // Backpack.
		public static final int SHAPE = 0X07000090; // Figure.
		public static final int HAIR = 0X07000091; // Hairstyle.
		public static final int SATCHEL = 0X07000092; // Satchel.
		public static final int LUGGAGE = 0X07000093; // Luggage.
		public static final int CARRY = 0X07000094; // Carrying object.
		public static final int MOVEDIRECT = 0X07000095; // Movement direction.
		public static final int UPPERSTYLE = 0X07000096; // Tops style.
		public static final int UPPERCOLOR = 0X07000097; // Tops color.
		public static final int LOWERSTYLE = 0X07000098; // Bottoms style.
		public static final int LOWERCOLOR = 0X07000099; // Bottoms color.
		public static final int RIDERMAN_FEATURE = 0x13000001;// 骑行人属性
		public static final int RIDERMAN_AGE = 0X07000400; // Age (juvenile, youth, elderly).
		public static final int RIDERMAN_GENDER = 0X07000401; // Sex (male, female).
		public static final int RIDERMAN_UPPERSTYLE = 0X07000402; // Tops style (long sleeves, short sleeves).
		public static final int RIDERMAN_UPPERCOLOR = 0X07000403; // Tops color (black, blue, green, white/gray,
																	// yellow/orange/brown, red/pink/purple).
		public static final int RIDERMAN_HELMET = 0X07000404; // Helmet.
		public static final int RIDERMAN_HELMETCOLOR = 0X07000405; // Helmet color.
		public static final int CHANNEL_ID = 0x09000078; // Camera channel ID.
	}

	/// <summary>
	/// Layer 2 metadata type.
	/// </summary>
	public interface LAYER_TWO_TYPE {
		public static final int COMMON = 0x00000001; // Universal.
		public static final int TARGET = 0x00000002; // Object (such as vehicles, persons, and faces).
		public static final int RULE = 0x00000003; // Rule (rule frame).
		public static final int TALARM = 0x00000004; // Intelligent alarm.
		public static final int TRECORD = 0x00000005; // Intelligent analysis–triggered recording.
	}

	public static class LLong extends IntegerType {
		private static final long serialVersionUID = 1L;

		/** Size of a native long, in bytes. */
		public static int size;
		static {
			size = Native.LONG_SIZE;
			if (Platform.isWindows()) {
				size = 4;
			} else {
				size = 8;
			}
		}

		/** Create a zero-valued LLong. */
		public LLong() {
			this(0);
		}

		/** Create a LLong with the given value. */
		public LLong(long value) {
			super(size, value);
		}
	}

	public static class LOCATION_INFO extends Structure {
		public float fxDegree; // PTZ dome camera angle.
		public float fyDegree;
		public float fDZoomRatio;
		public int lPOS; // POS
		public int enVideoRotation; // Video mirroring mode.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("fxDegree", "fyDegree", "fDZoomRatio", "lPOS", "enVideoRotation");
		}
	}

	// Alarm reporting information structure.
	public class LPPU_ALARM_REPORT_S extends Structure {
		public ULONG ulDeviceId; // Alarm device ID.

		public int enAlarmType; // Alarm Type:PU_ALARM_TYPE_E
		public PU_TIME_S.ByValue stTime; // Alarm occurrence time.
		public int enAction; // Alarm occurred or cleared.
		public ULONG ulAlarmId; // Alarm ID
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public LPPU_ALARM_REPORT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulDeviceId", "enAlarmType", "stTime", "enAction", "ulAlarmId", "szReserve");
		}
	}

	// Transparent transmission API output parameter structure.
	public static class LPPU_CONFIG_JSON_CONFIG_OUTPUT_ST extends Structure {
		public Pointer pOutBuffer; // Output parameter buffer, in JSON format. Note: The application layer must
									// apply for sufficient memory. If the memory is insufficient, the API returns
									// the corresponding error code.

		public ULONG ulInputBufferSize;// Output parameter buffer size (memory size) input by users.
		public ULONG ulRealBufferSize; // Actual output parameter buffer size.
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN]; // Reserved field. Set it to 0.

		public LPPU_CONFIG_JSON_CONFIG_OUTPUT_ST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("pOutBuffer", "ulInputBufferSize", "ulRealBufferSize", "szReserved");
		}
	}

	// Transparent transmission API input parameter structure.
	public static class LPPU_CONFIG_JSON_INPUT_ST extends Structure {
		public Pointer pRequestUrl; // Request signaling, which is a character string.

		public ULONG ulRequestUrlLen; // Request signaling length.
		public Pointer pInBuffer; // Input parameter buffer, in JSON format.
		public ULONG ulInBufferSize; // Input parameter buffer size.
		public ULONG ulRecvTimeOut; // Receiving timeout duration, in milliseconds. The value 0 indicates the
									// default timeout duration 5s.
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN]; // Reserved field. Set it to 0.

		public LPPU_CONFIG_JSON_INPUT_ST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("pRequestUrl", "ulRequestUrlLen", "pInBuffer", "ulInBufferSize", "ulRecvTimeOut",
					"szReserved");
		}
	}

	// Device information structure.
	public static class LPPU_DEVICEINFO_S extends Structure {
		public byte[] szDeviceName = new byte[PU_DEVICE_NAME_LEN]; // Device name. The device name can contain a maximum
																	// of 32 characters.

		public byte[] szDeviceFac = new byte[PU_FAC_NAME_LEN]; // Device vendor.

		public byte[] szDeviceType = new byte[PU_DEVICE_TYPE_LEN]; // Device model, which can be queried but cannot be
																	// set.

		public byte[] szSerialNumber = new byte[PU_SERIAL_LEN]; // Hardware SN.

		public PU_DEVICE_VERSION stDeviceVersion; // Device version.

		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // BOM code.

		public LPPU_DEVICEINFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szDeviceName", "szDeviceFac", "szDeviceType", "szSerialNumber", "stDeviceVersion",
					"szReserved");
		}
	}

	// PU log information.
	public static class LPPU_LOG_INFO_S extends Structure {
		public WinDef.ULONG ulTotalNum;

		public WinDef.ULONG ulBeginIndex;

		public WinDef.ULONG ulEndIndex;

		public byte[][] szLogInfoList = new byte[PU_LOG_INFO_NUM][PU_LOG_INFO_LEN];

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public LPPU_LOG_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulTotalNum", "ulBeginIndex", "ulEndIndex", "szLogInfoList", "szReserved");
		}
	}

	public static class LPPU_LOG_REQ_PARA_S extends Structure {
		public PU_TIME_S stStartTime;

		public PU_TIME_S stEndTime;

		public WinDef.ULONG ulStartIndex;

		public WinDef.ULONG ulPrePageNum;

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public LPPU_LOG_REQ_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stStartTime", "stEndTime", "ulStartIndex", "ulPrePageNum", "szReserved");
		}
	}

	// OSD array.
	public class LPPU_OSD_PARTICULAR_PARA_S extends Structure {
		public WinDef.ULONG ulChannelID; // Channel ID.

		public PU_OSD_DATETIME_PARA_S stOsdDateTimePara; // OSD time parameter.
		public WinDef.ULONG ulOSDStringNum; // Number of OSD character strings.
		public PU_OSD_STRING_PARA_S[] szStringPara = new PU_OSD_STRING_PARA_S[PU_OSD_STRING_NUM];

		public LPPU_OSD_PARTICULAR_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "stOsdDateTimePara", "ulOSDStringNum", "szStringPara");
		}
	}

	public class LPPU_PTZ_CONTROL_PARA_S extends Structure {
		public int ulChannel = 0; // Channel ID.

		public int ulOpCode = 0; // PTZ control code.
		public int ulParam1 = 0; // Parameter 1.
		public int ulParam2 = 0; // Parameter 2.

		public LPPU_PTZ_CONTROL_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannel", "ulOpCode", "ulParam1", "ulParam2");
		}
	}

	// System information structure.
	public static class LPPU_SYS_STATUS_INFO_S extends Structure {
		public float fCpuOccupancyRate; // CPU usage.

		public WinDef.ULONG ulMemTotal; // Total memory of the device (KB).

		public WinDef.ULONG ulMemFree; // Available memory (KB).

		public WinDef.ULONG ulMemBuffer; // Buffer (KB).

		public WinDef.ULONG ulMemCache; // Cache memory (KB).

		public WinDef.ULONG ulRecvRate; // Network receiving rate (byte).

		public WinDef.ULONG ulSendRate; // Network sending rate (byte).

		public WinDef.ULONG ulFlashTotal; // Total size of the flash memory (KB).

		public WinDef.ULONG ulFlashFree; // Available size of the flash memory (KB).

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public LPPU_SYS_STATUS_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("fCpuOccupancyRate", "ulMemTotal", "ulMemFree", "ulMemBuffer", "ulMemCache",
					"ulRecvRate", "ulSendRate", "ulFlashTotal", "ulFlashFree", "szReserve");
		}
	}

	// System time structure.
	public static class LPPU_SYSTEM_TIME_S extends Structure {
		public PU_TIME_S stSystime; // UTC time.

		public WinDef.LONG lTimeZone; // Integral part of the time zone.

		public WinDef.ULONG ulDotTimeZone; // Decimal part of the time zone.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public LPPU_SYSTEM_TIME_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stSystime", "lTimeZone", "ulDotTimeZone", "szReserve");
		}
	}

	// Upgrade callback data structure. Currently, only the transferred file size
	// and total file size are included.
	public static class LPPU_UPGRADE_CALLBACK_S extends Structure {
		public WinDef.ULONG ulCurrentSize; // Size of the current file to be transferred.

		public WinDef.ULONG ulTotalSize; // Total size of current files.

		public WinDef.ULONG ulCurrentFileNum; // Sequence number of the current file to be transferred.

		public WinDef.ULONG ulTotalFileNum; // Total number of current files.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public LPPU_UPGRADE_CALLBACK_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCurrentSize", "ulTotalSize", "ulCurrentFileNum", "ulTotalFileNum", "szReserve");
		}
	}

	// Upgrade file path structure.
	public static class LPPU_UPGRADE_FILE_INFO_S extends Structure {
		public byte[] cFileNum = new byte[PU_UPGRADE_FILE_NUM_MAX]; // Number of files. The maximum number of files is
																	// UPGRADE_FILE_NUM_MAX.

		public byte[][] szFileName = new byte[PU_UPGRADE_FILE_NUM_MAX][PU_UPGRADE_FILE_LEN_MAX]; // File path and file
																									// name. The first
																									// one is uImage,
																									// the second one is
																									// jffs2, and the
																									// third and fourth
																									// are reserved for
																									// extension.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public LPPU_UPGRADE_FILE_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("cFileNum", "szFileName", "szReserve");
		}
	}

	public static class LPR_CAPTURE_RES_S extends Structure {
		public byte[] szLocalTime = new byte[32]; // Snapshot time.

		public int iLaneID; // Lane ID.
		public PU_VEHICLE_INFO_S stVehicleInfo; // Vehicle information.
		public PU_PLATE_INFO_S stPlateInfo; // License plate information.
		public Pointer pPicBuffer; // Full image buffer.
		public int uiPicSize; // Full image size.
		public Pointer pLPBuffer; // Close-up license plate image buffer.
		public int uiLPPicSize; // Close-up license plate image size.
		public byte[] szReserved = new byte[512]; // Reserved field. szReserved[0] to szReserved[32] are reserved for
													// RS-485 external device serial numbers.

		public LPR_CAPTURE_RES_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szLocalTime", "iLaneID", "stVehicleInfo", "stPlateInfo", "pPicBuffer", "uiPicSize",
					"pLPBuffer", "uiLPPicSize", "szReserved");
		}
	}

	// Color.
	public static class META_COLOR_S extends Structure {

		public byte[] auc_r = new byte[3];

		public byte[] auc_g = new byte[3];
		public byte[] auc_b = new byte[3];
		public byte[] auc_ConfLev = new byte[3]; // Confidence.
		public byte[] auc_ColorID = new byte[3]; // ID

		public META_COLOR_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("auc_r", "auc_g", "auc_b", "auc_ConfLev", "auc_ColorID");
		}
	}

	public static class META_FACE_ATTRIBUTES_S extends Structure {
		public boolean isValid;

		public int glasses;
		public int gender;
		public int age;
		public int mouthmask;
		public int exspression;

		public META_FACE_ATTRIBUTES_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("isValid", "glasses", "gender", "age", "mouthmask", "exspression");
		}
	}

	public static class META_FACE_INFO_S extends Structure {
		public byte[] name = new byte[64];

		public int iGender;
		public byte[] birthday = new byte[32];
		public byte[] province = new byte[32];
		public byte[] city = new byte[48];
		public int iCardType;
		public byte[] cardID = new byte[32];

		public META_FACE_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("name", "iGender", "birthday", "province", "city", "iCardType", "cardID");
		}
	}

	public static class META_HUMAN_ATTRIBUTES_S extends Structure {
		public boolean isVaild;

		public int age;
		public int gender;
		public int upperStyle;
		public int upperColor;
		public int upperTexture;
		public int lowerStyle;
		public int lowerColor;
		public int shape;
		public int mouthmask;
		public int hair;
		public int backpack;
		public int carry;
		public int satchel;
		public int umbrella;
		public int frontpack;
		public int luggage;
		public int enMoveDirect;
		public int enMoveSpeed;

		public META_HUMAN_ATTRIBUTES_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("isVaild", "age", "gender", "upperStyle", "upperColor", "upperTexture", "lowerStyle",
					"lowerColor", "shape", "mouthmask", "hair", "backpack", "carry", "satchel", "umbrella", "frontpack",
					"luggage", "enMoveDirect", "enMoveSpeed");
		}
	}

	// Line.
	public static class META_LINE_S extends Structure {
		public META_POINT_S stStartPoint; // Start point.

		public META_POINT_S stEndPoint; // End point.

		public META_LINE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stStartPoint", "stEndPoint");
		}
	}

	// Movement direction.
	public interface META_MOVE_DIRECT {
		public static final int DIRECT_UNKNOWN = 0; // Unknown.
		public static final int DIRECT_FORWARD = 1; // Front.
		public static final int DIRECT_BACKWARD = 2; // Back.
	}

	// Movement speed.
	public interface META_MOVE_SPEED {
		public static final int SPEED_UNKNOWN = 0; // Unknown.
		public static final int SPEED_SLOW = 1; // Slow.
		public static final int SPEED_FAST = 2; // Fast.
	}

	// Point.
	public static class META_POINT_S extends Structure {
		public WinDef.USHORT usX; // x

		public WinDef.USHORT usY; // y

		public META_POINT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usX", "usY");
		}
	}

	// Polygon.
	public static class META_POLYGON_S extends Structure {
		public WinDef.UINT uPointNum; // Number of points.

		public META_POINT_S[] astPts = new META_POINT_S[MAX_POINT_NUM]; // Points List

		public META_POLYGON_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uPointNum", "astPts");
		}
	}

	// Rectangle.
	public static class META_RECT_S extends Structure {
		public WinDef.USHORT usX; // X coordinate of the upper left vertex of a rectangle.

		public WinDef.USHORT usY; // Y coordinate of the upper left vertex of a rectangle.
		public WinDef.USHORT usWidth; // Rectangle width.
		public WinDef.USHORT usHeight; // Rectangle height.

		public META_RECT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usX", "usY", "usWidth", "usHeight");
		}
	}

	/*** ONVIF media keep-alive time** */
	public static class ONVIF_RTSP_SESSION_TIMEOUT extends Structure {
		public ULONG ulChannelId;
		public int enStreamId; // Code stream type (primary stream, secondary stream 1, secondary stream 2). c
								// type:PU_STREAM_TYPE
		public ULONG ulTimeOut;

		public ONVIF_RTSP_SESSION_TIMEOUT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enStreamId", "ulTimeOut");
		}
	}

	// device alarm callback function type
	interface pfGetAlarmInfoCallBack extends StdCallCallback {
		long inovke(LPPU_ALARM_REPORT_S pstAlarmReport, Pointer pUsrData);
	}

	interface pfGetAlarmInfoCallBack_V20 extends StdCallCallback {
		long inovke(LPPU_ALARM_REPORT_S pstAlarmReport, Pointer pAlarmInfo, ULONG ulAlarmInfoSize, Pointer pUsrData);
	}

	interface pfGetDevAlarmInfoCallBack extends StdCallCallback {
		long inovke(PU_DEV_ALARM_INFO_REPORT pstDevAlarmReport, Pointer pUsrData);
	}

	// sdk event callback function type
	public interface pfGetEventInfoCallBack extends StdCallCallback {
		long eventStatus(Pointer arg);
	}

	interface pfJsonMsgCallBack extends StdCallCallback {
		long inovke(ULONG ulIdentifyID, Pointer pMsginfo, WinDef.DWORD dwBufLen, Pointer pUserData);
	}

	// real play callback function type
	public interface pfRealDataCallBack extends StdCallCallback {
		Pointer invoke(Pointer szBuffer, NativeLong lSize, String pUsrData);
	}

	interface pfTransChnDataCallBack extends StdCallCallback {
		void inovke(NativeLong lHandle, String szBuffer, NativeLong lSize, Pointer pUsrData);
	}

	public interface pfUpgradeScheduleCallBack extends StdCallCallback {
		WinDef.BOOL eventStatus(LPPU_UPGRADE_CALLBACK_S pstUpgradeData, Pointer arg);
	}

	// voice talk back callback function type
	public interface pfVoiceTBCallBack extends StdCallCallback {
		void invoke(String szBuffer, NativeLong lSize, Pointer pUsrData);
	}

	public interface PTZ_OSD_MODE {
		public static final int PTZ_OSD_NONE = 0; // None.
		public static final int PTZ_OSD_PTZ_INFO = 1; // PTZ information mode.
		public static final int PTZ_OSD_ORIENTATION = 2; // Azimuth mode.
		public static final int PTZ_OSD_POSITION = 3; // Latitude and longitude mode.
		public static final int PTZ_OSD_ZOOM = 4; // Zoom information mode.
	}

	public static class PU_1TN_ENABLE_S extends Structure {
		public static class ByReference extends PU_1TN_ENABLE_S implements Structure.ByReference {
		}

		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.

		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szReserved");
		}
	}

	/**
	 * 1 + N scene type.
	 */
	public interface PU_1TN_SUPPORT_MODE {
		public int TN_COMMON_SUPPORT_MODE = 0; // The intelligent mode is not supported.
		public int TN_FACE_TWO_SUPPORT_MODE = 1; // 2-channel face checkpoint.
		public int TN_VHD_TWO_SUPPORT_MODE = 2; // 2-channel object classification.
		public int TN_VHD_THREE_SUPPORT_MODE = 3; // 3-channel object classification.
		public int TN_FACE_THREE_SUPPORT_MODE = 4; // 3-channel face checkpoint.
		public int TN_FACE_OR_VHD_TWO_SUPPORT_MODE = 5; // 2-channel object classification/face checkpoint (any
														// combinations).
		public int TN_FACE_OR_VHD_THREE_SUPPORT_MODE = 6; // 3-channel object classification/face checkpoint (any
															// combinations).
		public int TN_FACE_FOUR_SUPPORT_MODE = 7; // 4-channel face checkpoint + 1-channel recognition.
		public int TN_FACE_FIVE_SUPPORT_MODE = 8; // 5-channel face checkpoint + 1-channel recognition.
		public int TN_FACE_TWO_VHD_TWO_SUPPORT_MODE = 9; // 2-channel object classification + 2-channel face checkpoint
															// + 1-channel recognition.
		public int TN_VHD_FOUR_SUPPORT_MODE = 10; // 4-channel object classification.
		public int TN_ITGT_SUPPORT_MODE_MAX = 64;
	}

	// List of intelligent capabilities supported by 1+N devices.
	public static class PU_1TN_SUPPORT_MODE_LIST_S extends Structure {
		public static class ByReference extends PU_1TN_SUPPORT_MODE_LIST_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulChannelId; // Channel ID.
		public WinDef.ULONG uSupportModeNum; // Quantity.
		public int[] enSpptModelist = new int[PU_1TN_SUPPORT_MODE.TN_ITGT_SUPPORT_MODE_MAX];// List of intelligent
																							// capabilities supported by
																							// 1+N devices.

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "uSupportModeNum", "enSpptModelist", "szReserved");
		}
	}

	// 1+N mode.
	public static class PU_1TN_SUPPORT_MODE_SWITCH_S extends Structure {
		public static class ByReference extends PU_1TN_SUPPORT_MODE_SWITCH_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulChannelId; // Channel ID.
		public int enMode; // mode

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enMode", "szReserved");
		}
	}

	public static class PU_3RD_APP_BASIC_INFO extends Structure {
		public byte[] szAppName = new byte[PU_OPERATE_3RD_APP_NAME_LEN];
		public byte[] szVersion = new byte[PU_OPERATE_3RD_APP_NAME_LEN];
		public byte[] szURL = new byte[PU_MANAGE_3RD_APP_URL_MAX];
		/* C type : PU_VW_3RD_APP_STATUS */
		public int enAppStatus;
		/* C type : PU_VW_3RD_APP_ACTION */
		public int enAction;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szAppName", "szVersion", "szURL", "enAppStatus", "enAction", "szReserved");
		}
	}

	public static class PU_ADD_MASK_PARA extends Structure {
		public ULONG ulChnID;
		public ULONG ulIndex;
		public PU_MASK_AREA_PARA stMaskAreaPara;
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ADD_MASK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulIndex", "stMaskAreaPara", "szReserve");
		}
	}

	/* AE exposure mode. */
	public interface PU_AE_MODE {
		public static final int PU_AE_MODE_AUTO = 0; // Auto exposure, auto aperture gain, and fixed shutter speed.
		public static final int PU_AE_MODE_MANUAL = 1; // Manual exposure.
		public static final int PU_AE_MODE_SHUTTER_PRI = 2; // Shutter priority.
		public static final int PU_AE_MODE_IRIS_PRI = 3; // Aperture priority.
		public static final int PU_AE_MODE_LOW_NOISE = 4; // Noise priority.
		public static final int PU_AE_MODE_FRAME_RATE = 5; // Frame rate priority.
		public static final int PU_AE_MODE_BRIGHT = 6; // Brightness priority.
		public static final int PU_AE_MODE_MAX = 7;
	}

	// Echo cancellation.
	public static class PU_AEC_ENABLE extends Structure {
		public ULONG ulChnID;
		public WinDef.BOOL bEnable;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_AEC_ENABLE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "szReserved");
		}
	}

	/* Metering mode. */
	public static class PU_AEMETERING_MODE extends Structure {
		public int enAEMeterSwitch; // Indicates whether to enable the metering mode (enable/disable). c
									// type:PU_COMMONMODE_SWITCH
		public int enAEMetering; // Metering mode (center-weighted metering, average metering, and user-defined
									// metering). c type:PU_VIDEO_AEMETERING_MODE
		public char[][] aucAreaWeight = new char[VW_ZONE_ROW][VW_ZONE_COLUMN]; // Exposure area weight (range: [0,
																				// 0xF]).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_AEMETERING_MODE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enAEMeterSwitch", "enAEMetering", "aucAreaWeight", "szReserve");
		}
	}

	/* Metering mode. */
	public static class PU_AEMETERING_MODE_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enAEMeterSwitch; // Indicates whether to enable the metering mode (enable/disable). c
									// type:PU_COMMONMODE_SWITCH
		/* C type : PU_VIDEO_AEMETERING_MODE_E */
		public int enAEMetering; // Metering mode (center-weighted metering, average metering, and user-defined
									// metering). c type:PU_VIDEO_AEMETERING_MODE
		public byte[] aucAreaWeight = new byte[VW_ZONE_ROW * VW_ZONE_COLUMN]; // Exposure area weight (range: [0, 0xF]).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enAEMeterSwitch", "enAEMetering", "aucAreaWeight", "szReserve");
		}
	}

	/* AES key type. */
	public interface PU_AES_KEY_MODULE {
		public static final int PU_AES_KEY_MODULE_WEB = 0; // WEB
		public static final int PU_AES_KEY_MODULE_ONVIF = 1; // ONVIF
		public static final int PU_AES_KEY_MODULE_T28181 = 2; // T28181
		public static final int PU_AES_KEY_MODULE_CA_PWD = 3; // CA certificate.
		public static final int PU_AES_KEY_MODULE_8021X = 4; // 8021X
		public static final int PU_AES_KEY_MODULE_SNMP = 5; // SNMP
		public static final int PU_AES_KEY_MODULE_DDNS = 6; // DDNS
		public static final int PU_AES_KEY_MODULE_SDK = 7; // SDK
		public static final int PU_AES_KEY_MODULE_FACE_REC_DATABASE = 15; // Facial recognition database.
		public static final int PU_AES_KEY_MODULE_MAX = 16;
	}

	// Alert deployment.
	public interface PU_ALARM_ACTION {
		public static final int PU_ALARM_ACTION_MOVE = 1; // Alarm cleared.
		public static final int PU_ALARM_ACTION_HAPPEN = 2; // Alarm occurred.
		public static final int PU_ALARM_ACTION_MAX = 3;
	}

	// Alarm type.
	public interface PU_ALARM_CATEGORY_TYPE {
		public static final int PU_ALARM_CATEGORY_TYPE_ALL = 0; // Service and device alarms.
		public static final int PU_ALARM_CATEGORY_TYPE_DEVICE = 1; // Device alarms.
		public static final int PU_ALARM_CATEGORY_TYPE_SERVICE = 2; // Service alarms.
		public static final int PU_ALARM_CATEGORY_TYPE_MAX = 3;
	}

	public interface PU_ALARM_LEVEL_E {
		int PU_ALARM_LEVEL_INFO = 0; // Warning.
		int PU_ALARM_LEVEL_GENERAL = 1; // Good
		int PU_ALARM_LEVEL_CRITICAL = 2; // Major.
		int PU_ALARM_LEVEL_FATAL = 3; // Critical.
		int PU_ALARM_LEVEL_MAX = 4;
	}

	// PTZ rotation priority in the case of alarm linkage.
	public static class PU_ALARM_LINK_PRIORITY_PARA extends Structure {
		public ULONG ulChannelId; // Channel ID.
		/* C type : PU_ALARM_LINK_PTZ_PRIORITY_E */
		public int enAlarmPriority; // Priority.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ALARM_LINK_PRIORITY_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enAlarmPriority", "szReserved");
		}
	}

	// Alarm linkage PTZ priority.
	public interface PU_ALARM_LINK_PTZ_PRIORITY {
		public static final int PU_GUARD_FIRST = 0; // Park action first. (When the park waiting time elapses, the park
													// action is triggered no matter whether any alarm is generated.)
		public static final int PU_ALARM_FIRST = 1; // Alarm linkage first. (During the alarming period, the park action
													// does not take effect.)
		public static final int PU_LINK_MAX = 2;
	}

	// Alarm linkage PTZ priority.
	public interface PU_ALARM_LINK_PTZ_PRIORITY_E {
		int PU_GUARD_FIRST = 0; // Park action first. (When the park waiting time elapses, the park action is
								// triggered no matter whether any alarm is generated.)
		int PU_ALARM_FIRST = 1; // Alarm linkage first. (During the alarming period, the park action does not
								// take effect.)
		int PU_LINK_MAX = 2;
	}

	public static class PU_ALARM_LINKAGE_CAMERA_INFO extends Structure {
		public ULONG ulChannelId;

		public ULONG ulPreId;
		public ULONG ulCruiseId;
		public ULONG ulRecord;
		public ULONG ulSnap;
		public ULONG ulSnapInterval; // Snapshot interval (ms).
		public ULONG ulDesignScan; // The options are as follows: 0: invalid; 1 to 5: scan paths.
		public NativeLong lHorizontalScan; // The options are as follows: 0: invalid; 1 to 10: forward scanning speed
											// level; -1 to -10: backward scanning speed level.
		public ULONG ulFrameScan; // The options are as follows: 0: invalid; 5 to 3600: scan interval.
		public ULONG ulRandomScan; // The options are as follows: 0: invalid; 5 to 3600: scan interval.
		public NativeLong lPanormaScan; // The options are as follows: 0: invalid; 1 to 10: forward scanning speed
										// level; -1 to -10: backward scanning speed level.
		public ULONG ulVerticalScan; // The options are as follows: 0: invalid; 1 to 10: scanning speed level.
		public BOOL bMailSend; // Indicates whether to link email sending. The options are as follows: 0: no;
								// 1: yes.

		public PU_ALARM_LINKAGE_CAMERA_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulPreId", "ulCruiseId", "ulRecord", "ulSnap", "ulSnapInterval",
					"ulDesignScan", "lHorizontalScan", "ulFrameScan", "ulRandomScan", "lPanormaScan", "ulVerticalScan",
					"bMailSend");
		}
	}

	// Alarm linkage
	public static class PU_ALARM_LINKAGE_PARA extends Structure {
		public ULONG ulChannelNum; // Number of linked cameras.

		public ULONG ulDoNum; // Number of Boolean value outputs.
		public PU_ALARM_LINKAGE_CAMERA_INFO[] stCameraList = new PU_ALARM_LINKAGE_CAMERA_INFO[PU_ALARM_CAMERA_MAX]; // Linked
																													// camera
																													// information
																													// list.
		public ULONG[] szDoIdList = new ULONG[PU_ALARM_DO_MAX]; // Linked Boolean value output ID.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0]: Indicates whether to link email sending.
																// The options are as follows: 0: no; 1: yes.

		public PU_ALARM_LINKAGE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelNum", "ulDoNum", "stCameraList", "szDoIdList", "szReserved");
		}
	}

	// Alarm-triggered recording information.
	public static class PU_ALARM_REC_INFO extends Structure {
		public PU_ALARM_REPORT stAlarmReport; // Alarm information corresponding to a recording.
		public PU_TIME_S stBeginTime; // Recording start time (UTC time).
		public PU_TIME_S stEndTime; // Recording end time (UTC time).
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ALARM_REC_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stAlarmReport", "stBeginTime", "stEndTime", "szReserved");
		}
	}

	// Alarm-triggered recording query parameters.
	public static class PU_ALARM_REC_INQ_REQ extends Structure {
		public ULONG ulChnID; // Channel ID.
		public int enAlarmType; // Alarm type. The value 0 indicates all alarms. c type:PU_ALARM_TYPE
		public PU_TIME_S stBeginTime; // Start time (UTC time).
		public PU_TIME_S stEndTime; // End time (UTC time).
		public ULONG ulBeginIndex; // Start index (starting from 1).
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ALARM_REC_INQ_REQ() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "enAlarmType", "stBeginTime", "stEndTime", "ulBeginIndex", "szReserved");
		}
	}

	// Response parameters of alarm-triggered recording query.
	public static class PU_ALARM_REC_INQ_RSP extends Structure {
		public ULONG ulTotalNum; // Total number of alarm-triggered recordings.
		public ULONG ulBeginIndex; // Start index.
		public ULONG ulEndIndex; // End index.
		public PU_ALARM_REC_INFO[] astAlarmRecInfoList = (PU_ALARM_REC_INFO[]) new PU_ALARM_REC_INFO()
				.toArray(PU_RECORD_INFO_NUM_MAX); // Alarm-triggered recording list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ALARM_REC_INQ_RSP() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulTotalNum", "ulBeginIndex", "ulEndIndex", "astAlarmRecInfoList", "szReserved");
		}
	}

	// Alarm reporting information structure.
	public static class PU_ALARM_REPORT extends Structure {
		public ULONG ulDeviceId; // Alarm device ID.
		public int enAlarmType; // Alarm type. c type:PU_ALARM_TYPE
		public PU_TIME_S stTime; // Alarm occurrence time.
		public int enAction; // Alarm occurred or cleared. c type:PU_ALARM_ACTION
		public ULONG ulAlarmId; // Alarm ID.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ALARM_REPORT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulDeviceId", "enAlarmType", "stTime", "enAction", "ulAlarmId", "szReserve");
		}
	}

	// Password expiration alarm.
	public static class PU_ALARM_REPORT_PWD_EXP_ALARM_S extends Structure {
		public byte[] szUsrName = new byte[PU_USER_NAME_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szUsrName");
		}
	}

	// Alert deployment time.
	public static class PU_ALARM_TIME extends Structure {
		public ULONG ulCycleType; // Cycle mode. The options are as follows: 0: none (one-time); 1: weekly.

		public ULONG ulPeriod; // 0: everyday; 1-7: Monday to Sunday
		public PU_TIME_S stStart; // Start time.
		public PU_TIME_S stEnd; // End time.

		public PU_ALARM_TIME() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCycleType", "ulPeriod", "stStart", "stEnd");
		}
	}

	// Alert deployment time list.
	public static class PU_ALARM_TIME_LIST extends Structure {
		public class ByValue extends PU_ALARM_TIME_LIST implements Structure.ByValue {
		}

		public ULONG ulNum; // Number of alert deployment time segments.
		public PU_ALARM_TIME[] stAlarmTime = new PU_ALARM_TIME[PU_ALARM_TIME_MAX]; // Alert deployment time segment
																					// array.

		public PU_ALARM_TIME_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulNum", "stAlarmTime");
		}
	}

	// Alert deployment time list.
	public static class PU_ALARM_TIME_LIST_S extends Structure {
		public ULONG ulNum; // Number of alert deployment time segments.

		public PU_ALARM_TIME_S[] stAlarmTime = (PU_ALARM_TIME_S[]) new PU_ALARM_TIME_S().toArray(PU_ALARM_TIME_MAX); // Alert
																														// deployment
																														// time
																														// segment
																														// array.

		public PU_ALARM_TIME_LIST_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulNum", "stAlarmTime");
		}
	}

	// Alert deployment time list.
	public static class PU_ALARM_TIME_PARA_LIST extends Structure {
		public ULONG ulNum; // Number of alert deployment time segments.

		public PU_ALARM_TIME[] stAlarmTime = (PU_ALARM_TIME[]) new PU_ALARM_TIME().toArray(PU_ALARM_TIME_MAX); // Alert
																												// deployment
																												// time
																												// segment
																												// array.

		public PU_ALARM_TIME_PARA_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCycleType", "ulPeriod", "stStart", "stEnd");
		}
	}

	public static class PU_ALARM_TIME_S extends Structure {
		// Cycle mode. The options are as follows: 0: none (one-time); 1: weekly.
		public NativeLong ulCycleType;
		// 0: everyday; 1-7: Monday to Sunday
		public NativeLong ulPeriod;
		// startTime
		public PU_TIME_S stStart;
		// end Time
		public PU_TIME_S stEnd;

		public PU_ALARM_TIME_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCycleType", "ulPeriod", "stStart", "stEnd");
		}
	}

	// Alarm type. Note: The enumerated type is the same as the ALARM_TYPE_E.
	public interface PU_ALARM_TYPE {
		public static final int PU_ALARM_TYPE_DI = 1; // Boolean value input.
		public static final int PU_ALARM_TYPE_DISK_FULL = 2; // Full disk.
		public static final int PU_ALARM_TYPE_NO_SIGNAL = 3; // Video signal loss.
		public static final int PU_ALARM_TYPE_MOVE_DECTION = 4; // Motion detection alarm.
		public static final int PU_ALARM_TYPE_DISK_FAULT = 5; // Disk fault.
		public static final int PU_ALARM_TYPE_SHIELD = 6; // Lens blocking alarm, including the intelligent lens
															// blocking detection alarm.
		public static final int PU_ALARM_TYPE_NETWORK_INTERRUPT = 7; // Network disconnection.
		public static final int PU_ALARM_TYPE_IP_ADDRESS_CONFLICT = 8; // IP address conflict.
		public static final int PU_ALARM_TYPE_TEMPERATURE = 9; // Temperature alarm.
		public static final int PU_ALARM_TYPE_FACE_DETECTION = 10; // Face detection.
		public static final int PU_ALARM_TYPE_INVADE = 11; // Tripwire crossing detection.
		public static final int PU_ALARM_TYPE_COUNT = 12; // Object counting.
		public static final int PU_ALARM_TYPE_DISTURB = 13; // Interference detection.
		/* Intelligent alarming. */
		public static final int PU_ALARM_TYPE_TRIPWIRE = 14; // Tripwire crossing detection.
		public static final int PU_ALARM_TYPE_INTRUSION = 15; // Intrusion detection.
		public static final int PU_ALARM_TYPE_HOVER = 16; // Loitering detection.
		public static final int PU_ALARM_TYPE_LEGACY = 17; // Abandoned object detection.
		public static final int PU_ALARM_TYPE_REMOVE = 18; // Removed object detection.
		public static final int PU_ALARM_TYPE_MEDIA_INTERRUPT = 30; // Media stream interrupted.
		public static final int PU_ALARM_TYPE_DISK_EXCEPTION = 31; // SD card exception.
		public static final int PU_ALARM_TYPE_AUDIO_EXCEPTION = 32; // Audio exception detection.
		public static final int PU_ALARM_TYPE_STORAGE_FAIL = 33; // Drive memory alarm.
		public static final int PU_ALARM_TYPE_RECORDING_JOBSTATE = 34; // Recording task status change.
		public static final int PU_ALARM_TYPE_DEV_TEMPE = 35; // Temperature chip error alarm.
		public static final int PU_ALARM_TYPE_LOG_WR = 36; // Log read and write alarm.
		public static final int PU_ALARM_TYPE_PTZ_CONFIG_WR = 37; // PTZ protocol configuration alarm.
		public static final int PU_ALARM_TYPE_FAN_PWR_BLOCKED = 38; // The fan for the power module of a fixed dome
																	// camera is faulty.
		public static final int PU_ALARM_TYPE_FAN_HEC_BLOCKED = 39; // The fan for the coding module of a fixed dome
																	// camera is faulty.
		public static final int PU_ALARM_TYPE_SFP_TEMP_HIGH = 40; // Overheat alarm of the optical module.
		public static final int PU_ALARM_TYPE_SFP_TEMP_LOW = 41; // Low heat alarm of the optical module.
		public static final int PU_ALARM_TYPE_SFP_VOL_HIGH = 42; // Overvoltage alarm of the optical module.
		public static final int PU_ALARM_TYPE_SFP_VOL_LOW = 43; // Low voltage alarm of the optical module.
		public static final int PU_ALARM_TYPE_SFP_BIAS_HIGH = 44; // Over-high bias current alarm of the optical module.
		public static final int PU_ALARM_TYPE_SFP_BIAS_LOW = 45; // Over-low bias current alarm of the optical module.
		public static final int PU_ALARM_TYPE_SFP_TX_PWR_HIGH = 46; // Over-high transmission power alarm of the optical
																	// module.
		public static final int PU_ALARM_TYPE_SFP_TX_PWR_LOW = 47; // Over-low transmission power alarm of the optical
																	// module.
		public static final int PU_ALARM_TYPE_SFP_RX_PWR_HIGH = 48; // Over-high received power alarm of the optical
																	// module.
		public static final int PU_ALARM_TYPE_SFP_RX_PWR_LOW = 49; // Over-low received power alarm of the optical
																	// module.
		public static final int PU_ALARM_TYPE_SFP_LASER_TEMP_HIGH = 50; // Over-heat laser alarm of the optical module.
		public static final int PU_ALARM_TYPE_SFP_LASER_TEMP_LOW = 51; // Low heat laser alarm of the optical module.
		public static final int PU_ALARM_TYPE_SFP_TEC_CURRENT_HIGH = 52; // Over-high TEC current alarm of the optical
																			// module.
		public static final int PU_ALARM_TYPE_SFP_TEC_CURRENT_LOW = 53; // Over-low TEC current alarm of the optical
																		// module.
		public static final int PU_ALARM_TYPE_DISC_PULLOUT = 54; // Hard disk removal.
		public static final int PU_ALARM_TYPE_LIGHT_SENSOR_INCVALID = 55; // Ambient light sensor failure alarm.
		public static final int PU_ALARM_TYPE_EXTERNAL_POWER_DOWN = 56; // Power-off of the external power supply.
		public static final int PU_ALARM_TYPE_WIPER_FAILURE_ALARM = 57; // Wiper failure alarm.
		public static final int PU_ALARM_TYPE_SFP_NOT_EXIST = 58; // Optical module not in position.
		public static final int PU_ALARM_TYPE_TYPE_PTOPT_HOR_FAIL = 59; // Horizontal optocoupler failure.
		public static final int PU_ALARM_TYPE_TYPE_PTOPT_VER_FAIL = 60; // Vertical optocoupler failure.

		public static final int PU_ALARM_TYPE_ITS_RADAR_EXCEPTION_ALARM = 62; // ITS radar exception.
		public static final int PU_ALARM_TYPE_ITS_IOCOIL_EXCEPTION_ALARM = 63; // ITS I/O loop exception.
		public static final int PU_ALARM_TYPE_ITS_485COIL_EXCEPTION_ALARM = 64; // ITS RS-485 loop exception.
		public static final int PU_ALARM_TYPE_ITS_REDTOR_EXCEPTION_ALARM = 65; // ITS traffic light detector exception.
		public static final int PU_ALARM_TYPE_LENS_FAILURE_ALARM = 66; // Lens PT optocoupler failure.
		/* Hardware module alarms. The value cannot exceed 200. */
		public static final int PU_ALARM_TYPE_AUDIO_UP = 100; // Sudden volume increase detection.
		public static final int PU_ALARM_TYPE_AUDIO_DOWN = 101; // Sudden volume decrease detection.
		public static final int PU_ALARM_TYPE_ENTER = 102; // Area entry detection.
		public static final int PU_ALARM_TYPE_EXIT = 103; // Area exit detection.
		public static final int PU_ALARM_TYPE_FASTMOVE = 104; // Fast movement detection.
		public static final int PU_ALARM_TYPE_CPU_HIGHT = 105; // Over-high CPU usage alarm.
		public static final int PU_ALARM_TYPE_MEM_HIGHT = 106; // Over-high memory usage alarm.
		public static final int PU_ALARM_TYPE_SCENECHANGE = 107; // Scene change detection.
		public static final int PU_ALARM_TYPE_AUTOTRACKING = 108; // Auto tracking.
		public static final int PU_ALARM_TYPE_OUTOFFOCUS_DETECT = 109; // Defocus detection.
		public static final int PU_ALARM_TYPE_CROWD_ANALYSIS = 110; // Crowd gathering detection.
		public static final int PU_ALARM_TYPE_SHAKE_DIAGNOSIS = 111; // Image shaking detection.
		public static final int PU_ALARM_TYPE_FROZEN_DIAGNOSIS = 112; // Image freezing.
		public static final int PU_ALARM_TYPE_SNOW_NOISE_DIAGNOSIS = 113; // Static noise detection.
		public static final int PU_ALARM_TYPE_STRIPENOISE_DIAGNOSIS = 114; // Stripe noise detection.
		public static final int PU_ALARM_TYPE_BRIGHT_DIAGNOSIS = 115; // Gain imbalance.
		public static final int PU_ALARM_TYPE_COLORCAST_DIAGNOSIS = 116; // Color cast.
		public static final int PU_ALARM_TYPE_CAR_DETECTION = 117; // Parking detection.
		public static final int PU_ALARM_TYPE_HUMAN_COUNT = 118; // Head counting.
		public static final int PU_ALARM_TYPE_FD_DL = 119; // 3559 face detection.
		public static final int PU_ALARM_TYPE_QUEUE_DETECT = 121; // Queue length detection.
		public static final int PU_ALARM_TYPE_CROWD_DENSITY_DETECT = 122; // Crowd density detection.
		public static final int PU_ALARM_TYPE_ILLEGAL_PARKING = 123; // PTZ dome camera that supports parking violation
																		// detection.
		public static final int PU_ALARM_TYPE_VLPR_TRAFFIC_CONGESTION = 124; // Traffic congestion alarm.
		public static final int PU_ALARM_TYPE_TRAFFIC_CONGESTION = 125; // ITS traffic congestion alarm.
		public static final int PU_ALARM_TYPE_FACE_RECOGNITION = 130; // 3559 facial recognition.
		public static final int PU_LPR_CAPTURE_RES = 200; // License plate snapshot result.
		public static final int PU_MANUAL_LPR_CAPTURE_RES = 201; // Manual license plate snapshot result.
		public static final int PU_ALARM_TYPE_HTTPS_CERT_EXPIRE = 300; // HTTPS certificate expiration alarm.
		public static final int PU_ALARM_TYPE_HTTPS_CERT_WILL_EXPIRE = 301; // Alarm of the HTTPS certificate about to
																			// expire.
		public static final int PU_ALARM_TYPE_DOT1X_CERT_EXPIRE = 302; // 802.1X certificate expiration alarm.
		public static final int PU_ALARM_TYPE_DOT1X_CERT_WILL_EXPIRE = 303; // Alarm of the 802.1X certificate about to
																			// expire.
		public static final int PU_ALARM_TYPE_SDK_PWD_STILL_INITIAL_PWD = 304; // SDK password not changed
		public static final int PU_AlARM_TYPE_PTZ_MOVE = 305; // PTZ rotation (GENETEC).
		public static final int PU_ALARM_TYPE_SSH_OPEN = 306; // SSH enabled.
		public static final int PU_ALARM_TYPE_SDK_USR_LOCK = 307; // SDK user locked.
		public static final int PU_ALARM_TYPE_WEB_USR_LOCK = 308; // Web user locked.
		public static final int PU_ALARM_TYPE_ONVIF_USR_LOCK = 309; // ONVIF user locked.
		public static final int PU_ALARM_TYPE_GENETEC_USR_LOCK = 310; // GENETEC user locked.
		public static final int PU_ALARM_TYPE_DOT1X_CA_CERT_EXPIRE = 311; // 802.1X CA certificate expiration alarm.
		public static final int PU_ALARM_TYPE_DOT1X_CA_CERT_WILL_EXPIRE = 312; // Alarm of the 802.1X CA certificate
																				// about to expire.
		public static final int PU_ALARM_TYPE_WEB_PWD_EXPIRE = 313; // Web password expiration alarm.
		public static final int PU_ALARM_TYPE_ATTITUDE_ABNORMAL = 314; // Abnormal posture.
		public static final int PU_ALARM_TYPE_VE_ILLEGAL_PARKING = 400; // Parking violation.
		public static final int PU_ALARM_TYPE_VE_ON_VEHICLE_LANE = 401; // Non-motor vehicles driving on motor vehicle
																		// lanes.
		public static final int PU_ALARM_TYPE_VE_ON_NONEVEHICLE_LANE = 402; // Motor vehicles driving on non-motor
																			// vehicle lanes.
		public static final int PU_ALARM_TYPE_VE_PRESSING_LINE = 403; // Marked lanes violation.
		public static final int PU_ALARM_TYPE_VE_WRONG_DIRECTION = 404; // Illegal backing/Wrong-way driving.
		// Abnormal license plate alarm (reserved).c
		// type：PU_ALARM_TYPE_VE_ABNORMAL_PLATE
		public static final int PU_ALARM_TYPE_VE_REVERSE = 406; // Illegal backing. Since the abnormal license plate is
																// not deleted, the value is fixed at 406.
		// Master-slave camera surveillance (1+N).
		public static final int PU_ALARM_TYPE_SLAVE_RTSP_KEEP_ALIVE_FAIL = 500; // Alarm of the RTSP keepalive operation
																				// failure of the slave device.
		public static final int PU_ALARM_TYPE_SLAVE_STREAM_NORMAL = 506; // Normal RTSP stream of the slave device.
		public static final int PU_ALARM_TYPE_WIFI_ALARM = 550; // Wi-Fi exception.
		public static final int PU_ALARM_TYPE_UPDATE_ROLLBACK_ALARM = 560; // Version rollback upon upgrade failure.
		public static final int PU_ALARM_TYPE_ALL = 561; // All alarms.
		public static final int PU_ALARM_TYPE_MAX = 562; // Reserved.
	}

	/* Algorithm version information. */
	public static class PU_ALG_INFO_S extends Structure {
		/* C type : PU_IPS_ALGORITHM_TYPE_E */
		public int enAlgType; // Algorithm type.
		public byte[] szAlgVer = new byte[PU_ITGT_ALTHM_VERSION_LEN]; // Algorithm version.
		public byte[] szAlgOwner = new byte[PU_ITGT_ALTHM_VERSION_LEN]; // Algorithm vendor.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enAlgType", "szAlgVer", "szAlgOwner", "szReserved");
		}
	}

	// Transparency.
	public interface PU_ALPHA_TYPE {
		public static final int PU_ALPHA_NONE = 0;
		public static final int PU_ALPHA_HALF = 1;
		public static final int PU_ALPHA_ALL = 2;
		public static final int PU_ALPHA_MAX = 3;
	}

	// Area-based detection.
	public static class PU_AREA extends Structure {
		public int ulIndex;
		public int enEnable;
		public int uPointNum; // Number of vertexes in a polygon.
		public PU_VIM_POINT[] stPoint = new PU_VIM_POINT[MAX_AREA_POINTS_NUM]; // Point coordinates.
		public LOCATION_INFO stLocation = new LOCATION_INFO(); // PTZ location information.
		public byte[] stAreaName = new byte[IGT_AREA_NAME_LEN]; // Area name.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "enEnable", "uPointNum", "stPoint", "stLocation", "stAreaName");
		}
	}

	// Rectangular area information.
	public static class PU_AREA_INFO extends Structure {
		public ULONG ulStartX; // X coordinate of the upper left corner of the rectangle.
		public ULONG ulStartY; // Y coordinate of the upper left corner of the rectangle.
		public ULONG ulWidth;
		public ULONG ulHeight;

		public PU_AREA_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartX", "ulStartY", "ulWidth", "ulHeight");
		}
	}

	public static class PU_AREA_INFO_S extends Structure {
		public static class ByReference extends PU_AREA_INFO_S implements Structure.ByReference {
		}

		public static class ByValue extends PU_AREA_INFO_S implements Structure.ByValue {
		}

		public ULONG ulStartX; // X coordinate of the upper left corner of the rectangle.
		public ULONG ulStartY; // Y coordinate of the upper left corner of the rectangle.

		public ULONG ulWidth;

		public ULONG ulHeight;

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartX", "ulStartY", "ulWidth", "ulHeight");
		}
	}

	// Associated recording information.
	public static class PU_ASSOCIATE_RECORD_INFO_S extends Structure {

		public static class ByReference extends PU_ASSOCIATE_RECORD_INFO_S implements Structure.ByReference {
		}

		public static class ByValue extends PU_ASSOCIATE_RECORD_INFO_S implements Structure.ByValue {
		}

		public boolean bRecordExist; // Indicates whether there is an associated recording.

		public WinDef.UINT ulStartTime; // Start time of the associated recording.

		public WinDef.UINT ulEndTime; // End time of the associated recording.

		public PU_ASSOCIATE_RECORD_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bRecordExist", "ulStartTime", "ulEndTime");
		}
	}

	/************* 3559 facial attribute recognition *************/
	public static class PU_ATTRI_DL_PARAMETER_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public WinDef.BOOL enEnableAttri; // Indicates whether to enable attribute recognition.
		// BOOL enEnableAttri; // Indicates whether to enable facial attribute
		// recognition.
//BOOL enEnableBodyAttri; // Indicates whether to enable personal attribute recognition.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ATTRI_DL_PARAMETER_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enEnableAttri", "szReserved");
		}
	}

	// Audio detection alarm parameters.
	public static class PU_AUDIO_DECT_ALARM_PARA extends Structure {
		public ULONG ulChannelId; // Channel ID.

		public PU_AUDIO_DECT_PARA stAudioDectPara; // Audio detection parameters.
		public PU_ALARM_TIME_LIST stAlarmTimeList; // Alert deployment time list.

		public PU_AUDIO_DECT_ALARM_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stAudioDectPara", "stAlarmTimeList");
		}
	}

	// Audio detection parameters.
	public static class PU_AUDIO_DECT_PARA extends Structure {
		public BOOL bEnable; // Indicates whether to enable the ROI.

		public ULONG ulSensitivity; // Detection sensitivity.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_AUDIO_DECT_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSensitivity", "szReserve");
		}
	}

	// Bit rate of streams in G.726 encoding format.
	public interface PU_AUDIO_G726_BPS {
		public static final int PU_AUDIO_G726_16K = 0; /* G726 16kbps */
		public static final int PU_AUDIO_G726_24K = 1; /* G726 24kbps */
		public static final int PU_AUDIO_G726_32K = 2; /* G726 32kbps */
		public static final int PU_AUDIO_G726_40K = 3; /* G726 40kbps */
		public static final int PU_AUDIO_G726_64K = 4; /* G726 64kbps */
		public static final int PU_AUDIO_G726_96K = 5; /* G726 96kbps */
		public static final int PU_AUDIO_G726_128K = 6; /* G726 128kbps */
		public static final int PU_AUDIO_G726_160K = 7; /* G726 160kbps */
		public static final int PU_AUDIO_G726_192K = 8; /* G726 192kbps */
		public static final int PU_AUDIO_G726_224K = 9; /* G726 224kbps */
		public static final int PU_AUDIO_G726_256K = 10; /* G726 256kbps */
		public static final int PU_AUDIO_G726_288K = 11; /* G726 288kbps */
		public static final int PU_AUDIO_G726_320K = 12; /* G726 320kbps */
		public static final int PU_AUDIO_G726_352K = 13; /* G726 352kbps */
		public static final int PU_AUDIO_G726_384K = 14; /* G726 384kbps */
		public static final int PU_AUDIO_G726_416K = 15; /* G726 416kbps */
		public static final int PU_AUDIO_G726_448K = 16; /* G726 448kbps */
		public static final int PU_AUDIO_G726_480K = 17; /* G726 480kbps */
		public static final int PU_AUDIO_G726_512K = 18; /* G726 512kbps */
		public static final int PU_AUDIO_G726_48K = 19; /* G726 48kbps */
		public static final int PU_AUDIO_G726_22K = 20; /* G726 22kbps */
		public static final int PU_AUDIO_G726_MAX = 21;
	}

	// Audio stream information.
	public static class PU_AUDIO_INFO extends Structure {
		public ULONG ulAudioChannelId; // Audio channel ID.

		public int enAudioEncodeMode; // Audio encoding type.
		public ULONG ulInputVolume; // Input volume.
		public ULONG ulOutputVolume; // Output volume.
		public int enAudioRate; // Audio bit rate in G.726 format.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // SzReserved[0]: sampling rate. The options are as
																// follows: 0 (8 kHz), 1 (12 kHz), 2 (16 kHz), 3 (24
																// kHz), 4 (48 kHz), 5 (22.05 kHz), 6 (32 kHz), and 7
																// (44.1 kHz).

		public PU_AUDIO_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		// szReserved[1]: audio input port type. The options are 0 (LINE IN) and 1 (MIC
		// IN).
		// szReserved[2]: indicates whether to enable automatic audio gain. The options
		// are 0 (no) and 1 (yes).
		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulAudioChannelId", "enAudioEncodeMode", "ulInputVolume", "ulOutputVolume",
					"enAudioRate", "szReserved");
		}
	}

	// Audio port type.
	public interface PU_AUDIO_PORT_TYPE {
		public static final int PU_AUDIO_PORT_TYPE_BNC_PLAY = 0; // BNC port.
		public static final int PU_AUDIO_PORT_TYPE_HDMI_PLAY = 1; // HDMI port.
		public static final int PU_AUDIO_PORT_TYPE_MAX = 2;
	}

	// Audio sampling rate.
	public interface PU_AUDIO_SAMPLERATE {
		public static final int PU_AUDIO_SAMPLERATE_8000 = 8000;
		public static final int PU_AUDIO_SAMPLERATE_12000 = 12000;
		public static final int PU_AUDIO_SAMPLERATE_11025 = 11025;
		public static final int PU_AUDIO_SAMPLERATE_16000 = 16000;
		public static final int PU_AUDIO_SAMPLERATE_22050 = 22050;
		public static final int PU_AUDIO_SAMPLERATE_24000 = 24000;
		public static final int PU_AUDIO_SAMPLERATE_32000 = 32000;
		public static final int PU_AUDIO_SAMPLERATE_44100 = 44100;
		public static final int PU_AUDIO_SAMPLERATE_48000 = 48000;
		public static final int PU_AUDIO_SAMPLERATE_MAX = 48001;
	}

	/* Auto iris parameter. */
	public static class PU_AUTO_APERTURE_PARA extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable auto iris. The options are as follows: 0: yes; 1:
									// no.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_AUTO_APERTURE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "szReserved");
		}
	}

	// Automatic ARP broadcast.
	public static class PU_AUTO_ARP_BROADCAST_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable automatic ARP broadcast.
		public ULONG ulCycleDay; // Period, 1–120 days.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_AUTO_ARP_BROADCAST_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulCycleDay", "szReserved");
		}
	}

	public static class PU_AUTO_CALIBRATION_CONFIG extends Structure {
		public PU_PTZ_CURRENT_LOCATION stCenter; // Central point of the PTZ dome camera during automatic calibration.
		public byte[] szMasterScreenPicPath = new byte[PU_SNAPSHOT_PICTURE_NAME_LEN]; // Path for storing snapshots
																						// taken by the PTZ dome camera.
		public byte[] szSlaveScreenPicPath = new byte[PU_SNAPSHOT_PICTURE_NAME_LEN]; // Path for storing snapshots taken
																						// by the slave camera.

		public PU_AUTO_CALIBRATION_CONFIG() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stCenter", "szMasterScreenPicPath", "szSlaveScreenPicPath");
		}
	}

	public static class PU_AUTO_DIALING_PLAN_S extends Structure {
		public PU_DIALING_PLAN_DAY_S[] szDalingPlan = (PU_DIALING_PLAN_DAY_S[]) new PU_DIALING_PLAN_DAY_S()
				.toArray(DAYS_PER_WEEK);

		public PU_AUTO_DIALING_PLAN_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szDalingPlan");
		}
	}

	// Maximum gain.
	public static class PU_AUTOGAIN_MAXVALUE_S extends Structure {
		public NativeLong lMaxAutoGain; // Maximum auto gain value.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("lMaxAutoGain");
		}
	}

	/* Backlight compensation mode. */
	public static class PU_BACKLIGHT_MODE extends Structure {
		public int enBackLightMode; // Indicates whether to enable backlight compensation (enable/disable). c
									// type:PU_COMMONMODE_SWITCH
		public NativeLong lBackLight; // Compensation level: 0–255.
		public int enMode; // Backlight compensation mode. c type:BACKLIGHT_MODE
		public PU_AREA_INFO stAreaInfo; // Backlight compensation area.
		public byte[] szReserve = new byte[12];

		public PU_BACKLIGHT_MODE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enBackLightMode", "lBackLight", "enMode", "stAreaInfo", "szReserve");
		}
	}

	/* Backlight compensation mode. */
	public static class PU_BACKLIGHT_MODE_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enBackLightMode; // Indicates whether to enable backlight compensation (enable/disable). c
									// type:PU_COMMONMODE_SWITCH
		public NativeLong lBackLight; // Compensation level: 0–255.
		/* C type : BACKLIGHT_MODE_E */
		public int enMode; // Backlight compensation mode. c type:BACKLIGHT_MODE
		public PU_AREA_INFO stAreaInfo; // Backlight compensation area.
		public byte[] szReserve = new byte[12];

		public PU_BACKLIGHT_MODE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enBackLightMode", "lBackLight", "enMode", "stAreaInfo", "szReserve");
		}
	}

	// Baud rate.
	public interface PU_BAUD_RATE {
		public static final int PU_BAUD_R2400 = 0;
		public static final int PU_BAUD_R4800 = 2;
		public static final int PU_BAUD_R9600 = 3;
		public static final int PU_BAUD_R19200 = 4;
		public static final int PU_BAUD_R38400 = 5;
		public static final int PU_BAUD_R57600 = 6;
		public static final int PU_BAUD_R115200 = 7;
		public static final int PU_BAUD_R230400 = 8;
		public static final int PU_BAUD_R460800 = 9;
		public static final int PU_BAUD_R921600 = 10;
		public static final int PU_BAUD_MAX = 11;
	}

	// Bit rate type.
	public interface PU_BIT_RATE_TYPE {
		public static final int PU_BIT_RATE_TYPE_FIXED = 0; // Constant bit rate (CBR).
		public static final int PU_BIT_RATE_TYPE_VARIABLE = 1; // Variable bit rate (VBR).
		public static final int PU_BIT_RATE_TYPE_QP = 2; // MJPEG stream.
		public static final int PU_BIT_RATE_TYPE_MAX = 3;
	}

	/* Day/Night mode. */
	public static class PU_BLACKWHITE_MODE_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enBKMode; // Video mode.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enBKMode");
		}
	}

	// Service type.
	public interface PU_BUSINESS_TYPE {
		public static final int PU_BUSINESS_REAL_VIDEO = 0; // Live video viewing.
		public static final int PU_BUSINESS_AUDIO_TALK = 1; // Voice intercom.
		public static final int PU_BUSINESS_AUDIO_BROADCAST = 2; // Voice broadcast.
		public static final int PU_BUSINESS_RECORD_DOWNLOAD = 3; // Recording download.
		public static final int PU_BUSINESS_RECORD_PLAY_BACK = 4; // Recording playback.
		public static final int PU_BUSINESS_SNAPSHOT_DOWNLOAD = 5; // Image download.
		public static final int PU_BUSINESS_TYPE_MAX = 6;
	}

	public interface PU_CACHERECORD {
		public static final int PU_RECORD_CLOSE = 0;
		public static final int PU_RECORD_OFFLINE = 1;
		public static final int PU_RECORD_MAX = 2;
	}

	// AE exposure mode.
	public static class PU_CAM_AE_MODE_S {
		/* C TYPE : PU_AE_MODE_E */
		public int enAEMode; // AE exposure mode.

		protected List<String> getFieldOrder() {
			return Arrays.asList("enAEMode");
		}
	}

	/* AE response time. */
	public static class PU_CAM_AE_RESPONSE_TIME_S extends Structure {
		public NativeLong lAEResponseTime;

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("lAEResponseTime");
		}
	}

	/* Exposure compensation. */
	public static class PU_CAM_EXPCOMP_PARA extends Structure {
		public int enExpComp; // Exposure compensation (enable/disable). C type：PU_COMMONMODE_SWITCH
		public NativeLong lExpComp; // Compensation coefficient (0–255).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_CAM_EXPCOMP_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enExpComp", "lExpComp", "szReserved");
		}
	}

	// Geographic location information.
	public static class PU_CAM_GEOG_POSITION extends Structure {
		public ULONG ulChnID; // Channel ID.
		public byte[] szAzimuth = new byte[CAM_POSITION_STR_LEN]; // Azimuth.
		public byte[] szPitch = new byte[CAM_POSITION_STR_LEN]; // Tilt angle.
		public byte[] szLongitude = new byte[CAM_POSITION_STR_LEN]; // Longitude.
		public byte[] szLatitude = new byte[CAM_POSITION_STR_LEN]; // Latitude.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates the mode of obtaining the
																// longitude and latitude. In the value of
																// szReserved[1], bit0 to bit4 respectively correspond
																// to nHeight, fAzimuth, fPitch, dLongitude, and
																// dLatitude.

		public PU_CAM_GEOG_POSITION() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "szAzimuth", "szPitch", "szLongitude", "szLatitude", "szReserved");
		}
	}

	// Geographic location information.
	public static class PU_CAM_GEOG_POSITION_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public byte[] szAzimuth = new byte[CAM_POSITION_STR_LEN]; // Azimuth.
		public byte[] szPitch = new byte[CAM_POSITION_STR_LEN]; // Tilt angle.
		public byte[] szLongitude = new byte[CAM_POSITION_STR_LEN]; // Longitude.
		public byte[] szLatitude = new byte[CAM_POSITION_STR_LEN]; // Latitude.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates the mode of obtaining the
																// longitude and latitude. In the value of
																// szReserved[1], bit0 to bit4 respectively correspond
																// to nHeight, fAzimuth, fPitch, dLongitude, and
																// dLatitude.

		public PU_CAM_GEOG_POSITION_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "szAzimuth", "szPitch", "szLongitude", "szLatitude", "szReserved");
		}
	}

	// Installation height.
	public static class PU_CAM_INSTALL_HEIGHT extends Structure {
		public ULONG ulChnID;
		public ULONG ulCentimeter;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_CAM_INSTALL_HEIGHT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulCentimeter", "szReserved");
		}
	}

	// Lens type.
	public static class PU_CAM_LENS_TYPE_S extends Structure {
		/* C TYPE : PU_LENS_TYPE */
		public int enLensType;

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enLensType");
		}
	}

	// P-iris subtype.
	public interface PU_CAM_P_IRIS_TYPE_E {
		int CAM_P_IRIS_HV1250P = 0; // P-iris or hall iris.
		int CAM_P_IRIS_HV03617P = 1; // Customer-selected lens type.
		int CAM_P_IRIS_BUTT = 2;
	}

	// Shutter settings.
	public interface PU_CAM_SHUTTER_MODE {
		public static final int PU_SHUTTER_MODE_1 = 0; // Shutter speed: 1s.
		public static final int PU_SHUTTER_MODE_2 = 1; // Shutter speed: 1/2s.
		public static final int PU_SHUTTER_MODE_4 = 2; // Shutter speed: 1/4s.
		public static final int PU_SHUTTER_MODE_8 = 3;
		public static final int PU_SHUTTER_MODE_12 = 4;
		public static final int PU_SHUTTER_MODE_15 = 5;
		public static final int PU_SHUTTER_MODE_25 = 6;
		public static final int PU_SHUTTER_MODE_30 = 7;
		public static final int PU_SHUTTER_MODE_50 = 8;
		public static final int PU_SHUTTER_MODE_60 = 9;
		public static final int PU_SHUTTER_MODE_90 = 10;
		public static final int PU_SHUTTER_MODE_100 = 11;
		public static final int PU_SHUTTER_MODE_120 = 12;
		public static final int PU_SHUTTER_MODE_125 = 13;
		public static final int PU_SHUTTER_MODE_180 = 14;
		public static final int PU_SHUTTER_MODE_250 = 15;
		public static final int PU_SHUTTER_MODE_350 = 16;
		public static final int PU_SHUTTER_MODE_500 = 17;
		public static final int PU_SHUTTER_MODE_725 = 18;
		public static final int PU_SHUTTER_MODE_1000 = 19;
		public static final int PU_SHUTTER_MODE_1500 = 20;
		public static final int PU_SHUTTER_MODE_2000 = 21;
		public static final int PU_SHUTTER_MODE_3000 = 22;
		public static final int PU_SHUTTER_MODE_4000 = 23;
		public static final int PU_SHUTTER_MODE_6000 = 24;
		public static final int PU_SHUTTER_MODE_10000 = 25;
		public static final int PU_SHUTTER_MODE_30000 = 26;
		public static final int PU_SHUTTER_MODE_100000 = 27;
		public static final int PU_SHUTTER_MODE_3 = 28; // Shutter speed: 1/3s.
		public static final int PU_SHUTTER_MODE_MAX = 29;
	}

	/* Slow shutter mode settings. */
	public static class PU_CAM_SLOW_SHUTTER_MODE extends Structure {
		public int enSlowShutterMode; // Slow shutter mode. c type:PU_COMMONMODE_SWITCH
		public int enShutterValue; // Shutter speed.c type:PU_CAM_SHUTTER_MODE
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_CAM_SLOW_SHUTTER_MODE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSlowShutterMode", "enShutterValue", "szReserve");
		}
	}

	/*
	 * White balance setting. The values of R and B can be fine-tuned in manual
	 * mode.
	 */
	public static class PU_CAM_WB_MANUAL_PARA extends Structure {
		public int enWBMode; // White balance mode. c type:PU_CAM_WB_MODE
		public ULONG ulROffset; // Red tuning, ranging from 0 to 255.
		public ULONG ulBOffset; // Blue tuning, ranging from 0 to 255.
		public ULONG ulRStrong; // Red fine-tuning, ranging from 0 to 255.
		public ULONG ulBStrong; // Blue fine-tuning, ranging from 0 to 255.
		public ULONG ulHighTemp; // Color temperature upper limit, ranging from 1500 to 10000K.
		public ULONG ulLowTemp; // Color temperature lower limit, ranging from 1500 to 10000K.
		public byte[] szReserve = new byte[PU_RESERVE_LEN - LLong.size - LLong.size];

		public PU_CAM_WB_MANUAL_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enWBMode", "ulROffset", "ulBOffset", "ulRStrong", "ulBStrong", "ulHighTemp",
					"ulLowTemp", "szReserve");
		}
	}

	/* White balance mode. */
	public interface PU_CAM_WB_MODE {
		public static final int PU_WB_MODE_AUTO = 0; // Automatic (stable environment and sharp colors).
		public static final int PU_WB_MODE_ATW = 1; // Automatic tracking (area where the white balance difference is
													// large).
		public static final int PU_WB_MODE_INDOOR = 2; // Indoor.
		public static final int PU_WB_MODE_OUTDOOR = 3; // Outdoor.
		public static final int PU_WB_MODE_ONEPUSH_TRIGGER = 4; // OnePush.
		public static final int PU_WB_MODE_MANUAL = 5; // Manual.
		public static final int PU_WB_MODE_OUTDOOR_AUTO = 6; // Outdoor automatic.
		public static final int PU_WB_MODE_SODIUM_VAPOR_LAMP_AUTO = 7; // Automatic sodium lamp.
		public static final int PU_WB_MODE_SODIUM_VAPOR_LAMP = 8; // Fixed sodium lamp.
		public static final int PU_WB_MODE_MERCURE_VAPOR_LAMP = 9; // Mercury lamp.
		public static final int PU_WB_MODE_FLUO_4200k = 10; // 4200k
		public static final int PU_WB_MODE_FLUORESCENTLAMP1 = 11; // Fluorescent lamp 1 (2500-3500 K).
		public static final int PU_WB_MODE_FLUORESCENTLAMP2 = 12; // Fluorescent lamp 2 (3500-4500 K).
		public static final int PU_WB_MODE_INCANDESCENTLAMP = 13; // Incandescent lamp (2700-2900 K).
		public static final int PU_WB_MODE_SUNLIGHT = 14; // Sunlight.
		public static final int PU_WB_MODE_MAX = 15;
	}

	/* WDR parameters. */
	public static class PU_CAM_WD_PARA extends Structure {
		public int enSwitchMode; // Indicates whether to enable the WDR (enable/disable/auto). c
									// type:PU_COMMONMODE_SWITCH
		public int enWDMode; // WDR mode. If this parameter is set to WD_MODE_RATIOFIX, lExpRatio needs to be
								// set. c type:PU_VIDEO_WD_MODE
		public NativeLong lExpRatio; // Sony: x1–x64; Hitachi: 127
		public ULONG ulAutoModeMaxExpRatio; // Maximum exposure ratio in auto WDR mode. T1: 1–16. The default value is
											// 8.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_CAM_WD_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSwitchMode", "enWDMode", "lExpRatio", "ulAutoModeMaxExpRatio", "szReserve");
		}
	}

	// Zoom and focus control.
	public interface PU_CamControl {
		public static final int PU_CAM_CONTROL_UP = 0;
		public static final int PU_CAM_CONTROL_DOWN = 1;
		public static final int PU_CAM_CONTROL_STOP = 2;
	}

	// Campus entrance and exit parameter settings.
	public static class PU_CAMPUS_MODE_PARA_S extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable license plate detection at the campus entrance
									// and exit.

		public int enTrigType; // Trigger type. The options are as follows: 0: loop; 1: tripwire; 2: hybrid.c
								// type:PU_CAMPUS_TRIG_TYPE_E
		public WinDef.BOOL bEnableNoPlateVeh; // Indicates whether to report unlicensed vehicles.
		public WinDef.BOOL bEnableDataAck; // Indicates whether to enable data backhaul.

		public PU_CAMPUS_MODE_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "enTrigType", "bEnableNoPlateVeh", "bEnableDataAck");
		}
	}

	public interface PU_CAPLAMPCTRL_TYPE_E {
		int TYPE_CTRLTYPE_IO = 0; // I/O control.
		int TYPE_CTRLTYPE_RS485 = 1; // RS-485 control.
		int TYPE_CTRLTYPE_PWM = 2; // PWM control.
		int TYPE_CTRLTYPE_MAX = 3;
	}

	// ID type.
	public interface PU_CARDTYPE_E {
		int CARDTYPE_ALL = -1; // All: This field is used only for search.
		int IDENTITY = 0; // ID card.
		int PASSPORT = 1; // Passport.
		int OFFICER = 2; // Military ID card.
		int DRIVING = 3; // Driver's license.
		int OTHERS = 4; // Others.
		int MAX = 5;
	}

	// Certificate validity period parameters.
	public static class PU_CERT_EXPIRE_PERIOD_PARA_S extends Structure {
		public NativeLong ulCheckPeriod; // Detection period (not configurable currently).

		public NativeLong ulAdvancedAlarmPeriod; // Advance alarm period.

		public PU_CERT_EXPIRE_PERIOD_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCheckPeriod", "ulAdvancedAlarmPeriod");
		}
	}

	// Certificate path parameters.
	public static class PU_CERT_FILE_PATH_PARA_S extends Structure {
		public static class ByReference extends PU_CERT_FILE_PATH_PARA_S implements Structure.ByReference {
		}

		public byte[] szCACertFilePath = new byte[PU_CERT_FILE_PATH_MAX];

		public byte[] szKeyFilePath = new byte[PU_CERT_FILE_PATH_MAX];

		public byte[] szCertFilePath = new byte[PU_CERT_FILE_PATH_MAX];

		public byte[] szKeyPasswd = new byte[PU_PASSWORD_LEN + 4];

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_CERT_FILE_PATH_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szCACertFilePath", "szKeyFilePath", "szCertFilePath", "szKeyPasswd", "szReserve");
		}
	}

	/**
	 * Channel status.
	 */
	public interface PU_CHANNEL_STATUS_E {
		public int CHANNEL_STATUS_ERR = 0; // Abnormal.
		public int CHANNEL_STATUS_NORMAL = 1; // Normal.
		public int CHANNEL_STATUS_MAX = 2;
	}

	/* Stream profile. */
	public static class PU_CHANNEL_STREAM_PROFILES extends Structure {
		public ULONG ulChannelID; // Channel ID.

		public PU_STREAM_MANIPULATE_TYPE enStreamOptionType; // Operation type. c type : PU_OPT_TYPE_E
		public PU_STREAM_PROFILES_PARA stStreamProfilesPara; // Stream profile parameters.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_CHANNEL_STREAM_PROFILES() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulPeriod", "usSrcPort", "usDstPort", "szSrcIP", "szDstIP",
					"enProtocolType", "ulInstanceId", "szMcpIp", "szDcpIp", "ulTlpId", "ulMcpPort", "szReserve");
		}
	}

	/* Stream profile V2 (five streams). */
	public static class PU_CHANNEL_STREAM_PROFILESV2 extends Structure {
		public ULONG ulChannelID; // Channel ID.

		public int enStreamOptionType; // Operation type. c type : PU_OPT_TYPE_E
		public PU_STREAM_PROFILES_PARAV2 stStreamProfilesPara; // Stream profile parameters.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_CHANNEL_STREAM_PROFILESV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enStreamOptionType", "stStreamProfilesPara", "szReserve");
		}
	}

	public interface PU_CHAR_ENCODE_TYPE {
		public static final int PU_CHAR_ENCODE_ANSI = 0; // ANSI code.
		public static final int PU_CHAR_ENCODE_UTF_8 = 1; // UTF-8 code.
		public static final int PU_CHAR_ENCODE_MAX = 2;
	}

	// CMOS sensor size.
	public static class PU_CMOS_SIZE_PARA extends Structure {
		public ULONG ulChnID;
		public ULONG ulIntHorSize;
		public ULONG ulDotHorSize;
		public ULONG ulIntVerSize;
		public ULONG ulDotVerSize;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_CMOS_SIZE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulIntHorSize", "ulDotHorSize", "ulIntVerSize", "ulDotVerSize",
					"szReserved");
		}
	}

	// Color.
	public interface PU_COLOR_TYPE {
		public static final int PU_COLOR_BLACK = 0;
		public static final int PU_COLOR_WHITE = 1;
		public static final int PU_COLOR_MAX = 2;
	}

	public interface PU_COMBINE_IMG_ROI_E {
		int PU_COMBINE_IMG0_ORI = 0; /* Original snapshot 0. */
		int PU_COMBINE_IMG0_ROI = 1; /* Snapshot for snapshot 0; Not supported */
		int PU_COMBINE_IMG1_ORI = 2; /* Original snapshot 1. */
		int PU_COMBINE_IMG1_ROI = 3; /* Snapshot cutout 1, not supported. */
		int PU_COMBINE_IMG2_ORI = 4; /* Original snapshot 2. */
		int PU_COMBINE_IMG2_ROI = 5; /* Snapshot cutout 2, not supported. */
		int PU_COMBINE_IMG3_ORI = 6; /* Original snapshot 3. */
		int PU_COMBINE_IMGS_ROI = 7; /*
										 * Close-up image. The specific close-up image is determined by the intelligent
										 * service.
										 */

		int PU_COMB_IMG_GW_ORI = 8; /* Original image of six-in-one checkpoint snapshot. */
		int PU_COMB_IMG_GW_ROI = 9; /* Close-up image of six-in-one checkpoint snapshot. */

		int PU_COMBINE_IMG_BUTT = 10;
	}

	public interface PU_COMBINE_SCALE_E {
		int PU_COMB_SIZE_ORG = 0; // Size of the original image.
		int PU_COMB_SIZE_QUARTER = 1; // One fourth of the original image.
		int PU_COMB_SIZE_RESERVE = 2;
	}

	// Enumerated type used by the new interface PU_PIC_SYNTHESIS_PARA_S.
	public interface PU_COMBINE_TYPE_E {
		int PU_COMB_SIGNEL_NOROI = 0; /* One snapshot without close-up. */
		int PU_COMB_SIGNEL_HOR = 1; /* One snapshot with close-up; horizontal synthesis. */
		int PU_COMB_SIGNEL_VER = 2; /* One snapshot with close-up; vertical synthesis. */

		int PU_COMB_DOUBLE_HOR_NOROI = 3; /* Two snapshots without close-up; horizontal synthesis. */
		int PU_COMB_DOUBLE_VER_NOROI = 4; /* Two snapshots without close-up; vertical synthesis. */
		int PU_COMB_DOUBLE_HOR = 5; /* Two snapshots with close-up; horizontal synthesis. */
		int PU_COMB_DOUBLE_VER = 6; /* Two snapshots with close-up; vertical synthesis. */
		int PU_COMB_DOUBLE_PYRAMIDAL_TOP = 7; /* Two snapshots with close-up; triangle synthesis. */
		int PU_COMB_DOUBLE_PYRAMIDAL_BUTT = 8; /* Two snapshots with close-up; inverted-triangle synthesis. */
		int PU_COMB_DOUBLE_PYRAMIDAL_LEFT = 9; /* Two snapshots with close-up; leftward triangle synthesis. */
		int PU_COMB_DOUBLE_PYRAMIDAL_RIGHT = 10; /* Two snapshots with close-up; rightward triangle synthesis. */

		int PU_COMB_TREBLE_HOR_NOROI = 11; /* Three snapshots without close-up; horizontal synthesis. */
		int PU_COMB_TREBLE_VER_NOROI = 12; /* Three snapshots without close-up; vertical synthesis. */
		int PU_COMB_TREBLE_HOR = 13; /* Three snapshots with close-up; horizontal synthesis. */
		int PU_COMB_TREBLE_VER = 14; /* Three snapshots with close-up; vertical synthesis. */
		int PU_COMB_TREBLE_PYRAMIDAL_TOP = 15; /* Three snapshots with close-up; triangle synthesis. */
		int PU_COMB_TREBLE_PYRAMIDAL_BUTT = 16; /* Three snapshots with close-up; inverted-triangle synthesis. */
		int PU_COMB_TREBLE_PYRAMIDAL_LEFT = 17; /* Three snapshots with close-up; leftward triangle synthesis. */
		int PU_COMB_TREBLE_PYRAMIDAL_RIGHT = 18; /* Three snapshots with close-up; rightward triangle synthesis. */
		int PU_COMB_TREBLE_SQUARE = 19; /* Three snapshots with close-up; cross-shaped synthesis. */
		int PU_COMB_TREBLE_SQUARE_NOROI = 20; /* Four snapshots without close-up; cross-shaped synthesis. */

		int PU_COMB_SIX_IN_ONE_HOR = 21; /* ITS ePolice six-in-one, horizontal arrangement, frame x 3, height x 2 */
		int PU_COMB_SIX_IN_ONE_VER = 22; /* ITS ePolice six-in-one, vertical arrangement, frame x 2, height x 3 */

		// If an enumeration value of the single-image synthesis mode needs to be added,
		// the value starts from 50.

		// If an enumeration value of the two-image synthesis mode needs to be added,
		// the value starts from 100.
		int PU_COMB_DOUBLE_PYRAMIDAL_TOP_ADAPT = 100; /*
														 * Two snapshots with close-up, inverted-triangle synthesis
														 * size.
														 */
		int PU_COMB_DOUBLE_PYRAMIDAL_BUTT_ADAPT = 101; /*
														 * Two snapshots with close-up, inverted-triangle synthesis
														 * size.
														 */
		int PU_COMB_DOUBLE_PYRAMIDAL_LEFT_ADAPT = 102; /*
														 * Two snapshots with close-up, leftward triangle synthesis
														 * size.
														 */
		int PU_COMB_DOUBLE_PYRAMIDAL_RIGHT_ADAPT = 103; /*
														 * Two snapshots with close-up, rightward triangle synthesis
														 * size.
														 */

		// If an enumeration value of the three-image synthesis mode needs to be added,
		// the value starts from 150.
		int PU_COMB_TREBLE_PYRAMIDAL_TOP_ADAPT = 150; /* Three snapshots without close-up, triangle synthesis size. */
		int PU_COMB_TREBLE_PYRAMIDAL_BUTT_ADAPT = 151; /*
														 * Three snapshots without close-up, inverted-triangle synthesis
														 * size.
														 */
		int PU_COMB_TREBLE_PYRAMIDAL_LEFT_ADAPT = 152; /*
														 * Three snapshots without close-up, leftward triangle synthesis
														 * size.
														 */
		int PU_COMB_TREBLE_PYRAMIDAL_RIGHT_ADAPT = 153; /*
														 * Three snapshots without close-up, rightward triangle
														 * synthesis size.
														 */

		int PU_COMB_TREBLE_BUTT = 154;
	}

	/* Indicates whether to enable ISP. */
	public interface PU_COMMONMODE_SWITCH {
		public static final int MODE_OPEN = 0; // Enable.
		public static final int MODE_CLOSE = 1; // Disable.
		public static final int MODE_AUTO = 2; // Auto mode.
		public static final int MODE_MANUAL = 3; // Manual mode.
		public static final int MODE_MAX = 4;
	}

	public interface PU_CONNECT_TYPE {
		public static final int PU_CONNECT_TYPE_PWD = 0;
		public static final int PU_CONNECT_TYPE_SSL_PWD = 1;
		public static final int PU_CONNECT_TYPE_MAX = 2;
	}

	/* HTTPS certificate creation. */
	public static class PU_CREATE_HTTPS_CERT extends Structure {
		public byte[] szCommonName = new byte[PU_CERT_FIELD_NAME_LEN_MAX]; // Certificate CN.
		public byte[] szCountry = new byte[PU_CERT_FIELD_NAME_LEN_MAX]; // Country.
		public byte[] szState = new byte[PU_CERT_FIELD_NAME_LEN_MAX]; // Province/State.
		public byte[] szLocation = new byte[PU_CERT_FIELD_NAME_LEN_MAX]; // Region.
		public byte[] szOrganization = new byte[PU_CERT_FIELD_NAME_LEN_MAX]; // Organization.
		public byte[] szUnit = new byte[PU_CERT_FIELD_NAME_LEN_MAX]; // Unit.
		public byte[] szEmail = new byte[PU_CERT_FIELD_NAME_LEN_MAX]; // Mail address.
		public ULONG ulExpiredDays; // Number of days in the validity period.
		public byte[] szCreateCertPsw = new byte[STREAMPROFILES_NAME_LEN]; // Password for creating a certificate.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_CREATE_HTTPS_CERT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szCommonName", "szCountry", "szState", "szLocation", "szOrganization", "szUnit",
					"szEmail", "ulExpiredDays", "szCreateCertPsw", "szReserve");
		}
	}

	// Information about preset positions in a tour.
	public class PU_CRUISE_POINT extends Structure {
		public WinDef.ULONG ulPresetIndex; // Preset position ID.

		public WinDef.ULONG ulDwellTime; // Dwell duration at a preset position (3-3600s).
		public WinDef.ULONG ulSpeed; // Speed of rotating to the next preset position (1-10).

		public PU_CRUISE_POINT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPresetIndex", "ulDwellTime", "ulSpeed");
		}
	}

	// Tour track.
	public class PU_CRUISE_SCAN_PARA extends Structure {
		public WinDef.ULONG ulCruiseIndex; // Tour track ID.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCruiseIndex");
		}
	}

	// CU quantity information of each frame.
	public static class PU_CU_OUTPUT_INFO extends Structure {
		public int uiCuNumIntra4; // intra 4x4 CU number
		public int uiCuNumIntra8; // intra 8x8 CU number
		public int uiCuNumIntra16; // intra 16x16 CU number
		public int uiCuNumIntra32; // intra 32x32 CU number
		public int uiCuNumIntra64; // intra 64x64 CU number
		public int uiCuNumPcm4; // IPCM 4x4 CU number
		public int uiCuNumPcm8; // IPCM 8x8 CU number
		public int uiCuNumPcm16; // IPCM 16x16 CU number
		public int uiCuNumPcm32; // IPCM 32x32 CU number
		public int uiCuNumPcm64; // IPCM 64x64 CU number
		public int uiCuNumInter8; // inter 8x8 CU number
		public int uiCuNumInter16; // inter 16x16 CU number
		public int uiCuNumInter32; // inter 32x32 CU number
		public int uiCuNumInter64; // inter 64x64 CU number
		public int uiCuNumSkip8; // skip 8x8 CU number
		public int uiCuNumSkip16; // skip 16x16 CU number
		public int uiCuNumSkip32; // skip 32x32 CU number
		public int uiCuNumSkip64; // skip 64x64 CU number

		public PU_CU_OUTPUT_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiCuNumIntra4", "uiCuNumIntra8", "uiCuNumIntra16", "uiCuNumIntra32", "uiCuNumIntra64",
					"uiCuNumPcm4", "uiCuNumPcm8", "uiCuNumPcm16", "uiCuNumPcm32", "uiCuNumPcm64", "uiCuNumInter8",
					"uiCuNumInter16", "uiCuNumInter32", "uiCuNumInter64", "uiCuNumSkip8", "uiCuNumSkip16",
					"uiCuNumSkip32", "uiCuNumSkip64");
		}
	}

	public class PU_CUSTOM_OSD_PARA_EX extends Structure {
		public byte[] acOSDContent = new byte[176 + 1]; // OSD Content

		public PU_CUSTOM_OSD_PARA_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("acOSDContent");
		}
	}

	public static class PU_CUSTOM_OSD_PARA_S extends Structure {
		public byte[] acOSDContent = new byte[PU_OSD_MAX_LENGTH]; // OSD内容

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("acOSDContent");
		}
	}

	/* CVBS parameters. */
	public static class PU_CVBS_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable the OSD.
		public int enResolution; // Resolution. c :type PU_RESOLUTION_TYPE

		public PU_CVBS_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "bEnable", "enResolution");
		}
	}

	// Cyclic mode.
	public interface PU_CYCLIC_MODE_E {
		int PU_E_NOT_CYCLIC = 0; // None.
		int PU_E_WEEK_CYCLIC = 1; // Weekly.
	}

	// Data bit.
	public interface PU_DATA_BIT {
		public static final int PU_DATA_BIT_CS5 = 0;
		public static final int PU_DATA_BIT_CS6 = 1;
		public static final int PU_DATA_BIT_CS7 = 2;
		public static final int PU_DATA_BIT_CS8 = 3;
		public static final int PU_DATA_BIT_MAX = 4;
	}

	// DST parameters.
	public static class PU_DAYLIGHT_SAVING_TIME_S extends Structure {
		public int enDSTType; // DST implementation mode. c type:PU_DST_TYPE_E

		public WinDef.BOOL bEnable; // Indicates whether to enable DST.
		public int enOffset; // DST offset. c type:PU_DST_OFFSET_E
		public PU_DST_DATE_S stDSTStartTime; // DST start time.
		public PU_DST_DATE_S stDSTEndTime; // DST end time.
		public int enDateWayOffset; // Time offset of the DST implemented by date. c type:PU_DST_OFFSET_E
		public byte[] szReserved = new byte[PU_RESERVE_LEN - 4]; // Reserved.

		public PU_DAYLIGHT_SAVING_TIME_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDSTType", "bEnable", "enOffset", "stDSTStartTime", "stDSTEndTime",
					"enDateWayOffset", "szReserved");
		}
	}

	// DDNS
	public static class PU_DDNS_CONF_INFO_S {
		public BOOL bEnable;
		public byte[] szUserID = new byte[PU_DDNS_MAX_LEN]; // User name.
		public byte[] szUserPWD = new byte[PU_DDNS_MAX_LEN]; // User password in plaintext mode.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // szReserve[0] indicates the applied network adapter. The
															// value 0 indicates network adapter 1. The value 1
															// indicates network adapter 2. The rest can be deducted by
															// analogy.

		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szUserID", "szUserPWD", "szUserPWD");
		}
	}

	/* Channel capability: audio and video. */
	/*
	 * exp：2 ----1 BNC1+D1 1 VGA1||HDMI1 + 1080P 5 ----1 BNC1+D1 4 VGA1||HDMI1 + D1
	 * 3 ----1 BNC1+D1 1 VGA1+720P 1 HDMI1+720P ==== From different sources 2 ----1
	 * VGA1+720P 1 HDMI1+720P ==== From different sources
	 */
	public static class PU_DEC_CHANNEL_ABILITY extends Structure {
		public PU_DEC_CHANNEL_PORT_MAP stChannelPortMap;// Mapping.
		/* C type : PU_ENCODE_TYPE_E */
		public int[] enVideoDecFormats = new int[PU_DECODE_TYPE_MAX]; // Decoding video format.
		/* C type : PU_ENCODE_TYPE_E */
		public int[] enAudioDecFormats = new int[PU_DECODE_TYPE_MAX]; // Decoding audio format.
		/* C type : PU_RESOLUTION_TYPE_E */
		public int enMaxDecResolution; // Maximum output resolution.
		/* C type : PU_FRAME_RATE_E */
		public int enMaxFrameRate; // Maximum frame rate: 30 fps or 60 fps.
		public WinDef.BOOL bSupportDecryption; // 0: no support 1: support
		public WinDef.BOOL bSupportWaterMark; // 0: no support 1: support

		// BOOL bAudioFlag; // Audio switch. A decoder supports only one audio output
		// channel. If the audio device has been enabled in a decoder channel, it will
		// be disabled in other channels by default.
		public PU_DEC_CHANNEL_ABILITY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stChannelPortMap", "enVideoDecFormats", "enAudioDecFormats", "enMaxDecResolution",
					"enMaxFrameRate", "bSupportDecryption", "bSupportWaterMark");
		}
	}

	// Channel capability list.
	public static class PU_DEC_CHANNEL_ABILITY_LIST extends Structure {
		public ULONG ulChannelNums; // Number of channels.
		public PU_DEC_CHANNEL_ABILITY[] stChnAttri = new PU_DEC_CHANNEL_ABILITY[PU_CHANNEL_NUM_MAX]; // Channel
																										// attribute.

		public PU_DEC_CHANNEL_ABILITY_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelNums", "stChnAttri");
		}
	}

	// Mapping between channels and ports.
	public static class PU_DEC_CHANNEL_PORT_MAP extends Structure {
		public ULONG ulChannelID; // Channel ID.
		/* C typ : PU_PORT_TYPE_E */
		public int enPortType; // Port type.
		public ULONG ulPortIndex; // Port index.
		public ULONG ulLayoutIndex; // Channel layout index.

		public PU_DEC_CHANNEL_PORT_MAP() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enPortType", "ulPortIndex", "ulLayoutIndex");
		}
	}

	/* Defogging parameters. */
	public static class PU_DEFOG_PARA extends Structure {
		public int enDefog; // Indicates whether to enable the defogging function. c
							// type:PU_COMMONMODE_SWITCH
		public ULONG ulDefogLevel; // Defogging level.
		public ULONG ulDefogSensitivity;
		public byte[] szReserve = new byte[PU_RESERVE_LEN - LLong.size];

		public PU_DEFOG_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDefog", "ulDefogLevel", "ulDefogSensitivity", "szReserve");
		}
	}

	/* Defogging parameters. */
	public static class PU_DEFOG_PARA_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enDefog; // Indicates whether to enable the defogging function. c
							// type:PU_COMMONMODE_SWITCH
		public ULONG ulDefogLevel; // Defogging level.
		public ULONG ulDefogSensitivity;
		public byte[] szReserve = new byte[PU_RESERVE_LEN - LLong.size];

		public PU_DEFOG_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDefog", "ulDefogLevel", "ulDefogSensitivity", "szReserve");
		}
	}

	/* Defogging level. */
	public interface PU_DEFOG_TYPR {
		public static final int PU_DEFOG_TYPE_CLOSE = 0; // Disabled.
		public static final int PU_DEFOG_TYPE_LOW = 1; // Low-level defogging.
		public static final int PU_DEFOG_TYPE_MIDDLING = 2; // Medium-level defogging.
		public static final int PU_DEFOG_TYPE_HIGH = 3; // High-level defogging.
		public static final int PU_DEFOG_TYPE_AUTO = 4; // Automatic defogging.
		public static final int PU_DEFOG_TYPE_MAX = 5;
	}

	public static class PU_DEL_MASK_PARA extends Structure {
		public ULONG ulChnID;
		public ULONG ulIndex;
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_DEL_MASK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulIndex", "szReserve");
		}
	}

	/* Noise reduction mode */
	public interface PU_DENOISE_MODE {
		public static final int DENOISE_NORMOL = 0; // Common mode.
		public static final int DENOISE_CLOSE = 1; // Disabled.
		public static final int DENOISE_EXPERT = 2; // Expert mode.
		public static final int DENOISE_MAX = 3;
	}

	// Noise reduction parameters.
	public static class PU_DENOISE_PARA_S extends Structure {
		/* C TYPE : PU_DENOISE_MODE_E */
		public int enDenoiseMode; // Indicates whether to enable image stabilization. c type:PU_COMMONMODE_SWITCH
		public NativeLong lNRLevel; // Noise reduction level. For Sony devices, the value ranges from 1 to 5; for
									// Hitachi devices, the value ranges from 1 to 3.
		public ULONG ulTfcLevel; // Temporal noise reduction.
		public ULONG ulSfcLevel; // Spatial noise reduction.

		public PU_DENOISE_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDenoiseMode", "lNRLevel", "ulTfcLevel", "ulSfcLevel");
		}
	}

	// Motion detection/Lens blocking detection rectangle parameters.
	public static class PU_DETECTION_AREA extends Structure {
		public ULONG ulNum; // 检测矩形个数

		public PU_MASK_PARA[] stMaskPara = new PU_MASK_PARA[PU_ALARM_AREA_MAX]; // 矩形参数

		public PU_DETECTION_AREA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulNum", "stMaskPara");
		}
	}

	// Alarm reporting information structure.
	public static class PU_DEV_ALARM_INFO_REPORT extends Structure {
		public ULONG ulIdentifyID; // Device login ID.
		public ULONG ulAlarmModID; // Alarm module ID.
		public BOOL IsIntact; // Indicates whether a device is intact. The options are as follows: 1: yes; 0:
								// no.
		public PU_ALARM_LEVEL_E enAlarmLevel; // Alarm severity.
		/* c Type : PU_ALARM_TYPE_E */
		public int enAlarmType; // Alarm type.
		public PU_TIME_S stTime; // Alarm generation or clearance time (UTC time).
		/* c Type : PU_ALARM_ACTION_E */
		public int enAction; // Alarm occurred or cleared.
		public ULONG ulAlarmId; // Alarm serial number.
		public byte[] szAlarmDesc = new byte[64]; // Alarm description.
		public byte[] szAlarmCleanDesc = new byte[64]; // Alarm clearance description.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_DEV_ALARM_INFO_REPORT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIdentifyID", "ulAlarmModID", "IsIntact", "enAlarmLevel", "enAlarmType", "stTime",
					"enAction", "ulAlarmId", "szAlarmDesc", "szAlarmCleanDesc", "szReserve");
		}
	}

	// Device configuration information.
	public static class PU_DEV_CONFIG_INFO extends Structure {
		public PU_IPFILTER_RULES_INFOV2_S stIPFilterPara; // IP address filtering.
		public PU_TCP_ACCELERATE_PARA_S stTcpAcceleratePara; // Intelligent network acceleration.
		public PU_DEVICE_PORT_CONFIG_S stDevPortConfig; // Device port.
		public PU_DDNS_CONF_INFO_S stDDNSpara; // DDNS
		public PU_DOT1X_CONFIG_INFO stDot1xInfo; // 802.1x
		public PU_SSH_ENABLE_PARA_S stSshPara; // SSH
		public PU_SFTP_ENABLE_PARA_S stSftpPara; // SFTP
		public PU_SNMP_COMMUNITY_LIST_EX stCommunityList; // SNMPv1v2c community list.
		public PU_SNMPV3_USER_LIST stUserList; // SNMPv3 user list.
		public PU_SNMPV3_USER_MGMT stUserMgmtInfo; // SNMPv3 user management.
		public PU_SNMP_TRAP_LIST stTrapList; // SNMP Trap receiver list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_DEV_CONFIG_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stIPFilterPara", "stTcpAcceleratePara", "stDevPortConfig", "stDDNSpara",
					"stDot1xInfo", "stSshPara", "stSftpPara", "stCommunityList", "stUserList", "stUserMgmtInfo",
					"stTrapList", "szReserved");
		}
	}

	// Device configuration information.
	public static class PU_DEV_CONFIG_PARA extends Union {
		public static class ByReference extends PU_DEV_CONFIG_PARA implements com.sun.jna.Structure.ByReference {

		}

		public static class ByValue extends PU_DEV_CONFIG_PARA implements com.sun.jna.Structure.ByValue {

		}

		/**
		 * IP address filtering.<br>
		 */
		public PU_IPFILTER_RULES_INFOV2_S stIPFilterPara;
		/**
		 * Intelligent network acceleration.<br>
		 */
		public PU_TCP_ACCELERATE_PARA_S stTcpAcceleratePara;
		/**
		 * Device port.<br>
		 */
		public PU_DEVICE_PORT_CONFIG_S stDevPortConfig;
		/**
		 * DDNS<br>
		 * C type : PU_DDNS_CONF_INFO_S
		 */
		public PU_DDNS_CONF_INFO_S stDDNSpara;
		/**
		 * 802.1x<br>
		 */
		public PU_DOT1X_CONFIG_INFO stDot1xInfo;
		/**
		 * SSH<br>
		 */
		public PU_SSH_ENABLE_PARA_S stSshPara;
		/**
		 * SFTP<br>
		 */
		public PU_SFTP_ENABLE_PARA_S stSftpPara;
		/**
		 * SNMPv1v2c community list.<br>
		 */
		public PU_SNMP_COMMUNITY_LIST_EX stCommunityList;
		/**
		 * SNMPv3 user management information.<br>
		 */
		public PU_SNMPV3_USER_MGMT stUserMgmtInfo;
		/**
		 * SNMPv3 user list.<br>
		 */
		public PU_SNMPV3_USER_LIST stUserList;

		/**
		 * SNMP Trap receiver list.<br>
		 */
		public PU_SNMP_TRAP_LIST stTrapList;

		public byte[] szReserved = new byte[32];

		public PU_DEV_CONFIG_PARA() {
			super();
		}

		/**
		 * @param szReserved C type : CHAR[32]
		 */
		public PU_DEV_CONFIG_PARA(byte szReserved[]) {
			super();
			if ((szReserved.length != this.szReserved.length))
				throw new IllegalArgumentException("Wrong array size !");
			this.szReserved = szReserved;
			setType(byte[].class);
		}

		public PU_DEV_CONFIG_PARA(Pointer peer) {
			super(peer);
		}

		/**
		 * @param stDDNSpara DDNS<br>
		 *                   C type : PU_DDNS_CONF_INFO_S
		 */
		public PU_DEV_CONFIG_PARA(PU_DDNS_CONF_INFO_S stDDNSpara) {
			super();
			this.stDDNSpara = stDDNSpara;
			setType(PU_DDNS_CONF_INFO_S.class);
		}

		/**
		 * @param stDevPortConfig Device port.<br>
		 *                        C type : PU_DEVICE_PORT_CONFIG_S
		 */
		public PU_DEV_CONFIG_PARA(PU_DEVICE_PORT_CONFIG_S stDevPortConfig) {
			super();
			this.stDevPortConfig = stDevPortConfig;
			setType(PU_DEVICE_PORT_CONFIG_S.class);
		}

		/**
		 * @param stDot1xInfo 802.1x<br>
		 *                    C type : PU_DOT1X_CONFIG_INFO_S
		 */
		public PU_DEV_CONFIG_PARA(PU_DOT1X_CONFIG_INFO stDot1xInfo) {
			super();
			this.stDot1xInfo = stDot1xInfo;
			setType(PU_DOT1X_CONFIG_INFO.class);
		}

		/**
		 * @param stIPFilterPara IP address filtering.<br>
		 *                       C type : PU_IPFILTER_RULES_INFOV2_S
		 */
		public PU_DEV_CONFIG_PARA(PU_IPFILTER_RULES_INFOV2_S stIPFilterPara) {
			super();
			this.stIPFilterPara = stIPFilterPara;
			setType(PU_IPFILTER_RULES_INFOV2_S.class);
		}

		/**
		 * @param stSftpPara SFTP<br>
		 *                   C type : PU_SFTP_ENABLE_PARA_S
		 */
		public PU_DEV_CONFIG_PARA(PU_SFTP_ENABLE_PARA_S stSftpPara) {
			super();
			this.stSftpPara = stSftpPara;
			setType(PU_SFTP_ENABLE_PARA_S.class);
		}

		/**
		 * @param stCommunityList SNMPv1v2c community list.<br>
		 *                        C type : PU_SNMP_COMMUNITY_LIST_S_EX
		 */
		public PU_DEV_CONFIG_PARA(PU_SNMP_COMMUNITY_LIST_EX stCommunityList) {
			super();
			this.stCommunityList = stCommunityList;
			setType(PU_SNMP_COMMUNITY_LIST_EX.class);
		}

		/**
		 * @param stTrapList SNMP Trap receiver list.<br>
		 *                   C type : PU_SNMP_TRAP_LIST_S
		 */
		public PU_DEV_CONFIG_PARA(PU_SNMP_TRAP_LIST stTrapList) {
			super();
			this.stTrapList = stTrapList;
			setType(PU_SNMP_TRAP_LIST.class);
		}

		/**
		 * @param stUserList SNMPv3 user list.<br>
		 *                   C type : PU_SNMPV3_USER_LIST_S
		 */
		public PU_DEV_CONFIG_PARA(PU_SNMPV3_USER_LIST stUserList) {
			super();
			this.stUserList = stUserList;
			setType(PU_SNMPV3_USER_LIST.class);
		}

		/**
		 * @param stUserMgmtInfo SNMPv3 user management information.<br>
		 *                       C type : PU_SNMPV3_USER_MGMT_S
		 */
		public PU_DEV_CONFIG_PARA(PU_SNMPV3_USER_MGMT stUserMgmtInfo) {
			super();
			this.stUserMgmtInfo = stUserMgmtInfo;
			setType(PU_SNMPV3_USER_MGMT.class);
		}

		/**
		 * @param stSshPara SSH<br>
		 *                  C type : PU_SSH_ENABLE_PARA_S
		 */
		public PU_DEV_CONFIG_PARA(PU_SSH_ENABLE_PARA_S stSshPara) {
			super();
			this.stSshPara = stSshPara;
			setType(PU_SSH_ENABLE_PARA_S.class);
		}

		/**
		 * @param stTcpAcceleratePara Intelligent network acceleration.<br>
		 *                            C type : PU_TCP_ACCELERATE_PARA_S
		 */
		public PU_DEV_CONFIG_PARA(PU_TCP_ACCELERATE_PARA_S stTcpAcceleratePara) {
			super();
			this.stTcpAcceleratePara = stTcpAcceleratePara;
			setType(PU_TCP_ACCELERATE_PARA_S.class);
		}

	}

	// Enumerated types of device configuration parameters.
	public interface PU_DEV_CONFIG_TYPE_E {
		int PU_DEV_CONFIG_TYPE_IP_FILTER = 0; // IP address filtering.
		int PU_DEV_CONFIG_TYPE_DEV_PORT = 1; // Device port.
		int PU_DEV_CONFIG_TYPE_TCP_ACCELERATE = 2; // Intelligent network acceleration.
		int PU_DEV_CONFIG_TYPE_DDNS = 3; // DDNS
		int PU_DEV_CONFIG_TYPE_802DOT1x = 4; // 802.1x
		int PU_DEV_CONFIG_TYPE_SSH = 5; // SSH
		int PU_DEV_CONFIG_TYPE_SFTP = 6; // SFTP
		int PU_DEV_CONFIG_TYPE_SNMP_COMMUNITY = 7; // SNMPv1v2c community list.
		int PU_DEV_CONFIG_TYPE_SNMPV3_USER_MANAGE = 8; // SNMPv3 user management.
		int PU_DEV_CONFIG_TYPE_SNMPV3_USER = 9; // SNMPv3 user list.
		int PU_DEV_CONFIG_TYPE_SNMPV3_TRAP = 10; // SNMP Trap receiver list.
		int PU_DEV_CONFIG_TYPE_MAX = 11;
	}

	public interface PU_DEV_OPT_TYPE {
		public static final int PU_DEV_OPT_TYPE_REBOOT = 0; // Restart.
		public static final int PU_DEV_OPT_TYPE_FORMAT = 1; // Format a disk.
		public static final int PU_DEV_OPT_TYPE_MAX = 2;
	}

	public static class PU_DEV_REALSTATUS_INFO extends Structure {
		public NativeLong lCurretTemp; // Temperature.
		public PU_SYS_STATUS_INFO stSysStatusInfo; // CPU and memory information.
		public PU_HARD_DISK_STATE stDiskState; // SD card status.
		public PU_CAM_GEOG_POSITION_S stCamGeogPostion; // Geographical location.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_DEV_REALSTATUS_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("lCurretTemp", "stSysStatusInfo", "stDiskState", "stCamGeogPostion", "szReserved");
		}
	}

	// Master device capability.
	public static class PU_DEVICE_ABILITY extends Structure {
		public ULONG ulVideoInputChannelNum; // Number of video input channels.
		public ULONG ulAudioInputChannelNum; // Number of audio input channels.
		public ULONG ulAlarmDINum; // Number of alarm input channels.
		public ULONG ulAlarmDONum; // Number of alarm output channels.
		public ULONG ulSerialPortNum; // Number of serial ports.
		public ULONG ulNetworkCardNum; // Number of network ports.
		public ULONG ulHardDiskNum; // Number of hard disks.
		public ULONG ulPTZNum; // Number of PTZ devices.
		public ULONG ulTalkbackInputNum; // Number of voice intercom input channels.
		public ULONG ulTalkbackOutputNum; // Number of voice intercom output channels.
		public ULONG ulRTPOverFlag; // Transmission protocol. The options are as follows: 0: RTP over UDP; 1: RTP
									// over TCP; 2: RTP over UDP&TCP.
		public PU_HARD_DISK_PARA stHardDiskInfo; // Disk information.
		byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_DEVICE_ABILITY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulVideoInputChannelNum", "ulAudioInputChannelNum", "ulAlarmDINum", "ulAlarmDONum",
					"ulSerialPortNum", "ulNetworkCardNum", "ulHardDiskNum", "ulPTZNum", "ulTalkbackInputNum",
					"ulTalkbackOutputNum", "ulRTPOverFlag", "stHardDiskInfo", "szReserved");
		}
	}

	// 设备ESN号
	public static class PU_DEVICE_ESN_INFO_S extends Structure {
		public byte[] szDeviceESNInfo = new byte[PU_ESN_INFO_LEN];
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_DEVICE_ESN_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szDeviceESNInfo", "szReserved");
		}
	}

	/* Network port IP address. */
	public static class PU_DEVICE_ETHERNET_PARA extends Structure {
		public WinDef.BOOL bDhcpEnable; // Indicates whether to enable DHCP.

		public byte[] szIPAddress = new byte[PU_IP4_ADDR_LEN]; // IP address.
		public byte[] szSubNetMask = new byte[PU_IP4_ADDR_LEN]; // Subnet mask.
		public byte[] szGateWayAddress = new byte[PU_IP4_ADDR_LEN]; // Gateway IP address.
		public byte[] szFirstDNSAddress = new byte[PU_IP4_ADDR_LEN]; // First group of DNS addresses.
		public byte[] szSecondDNSAddress = new byte[PU_IP4_ADDR_LEN]; // Second group of DNS addresses.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0]: network port index. The value 0 indicates
																// network adapter 1. The value 1 indicates network
																// adapter 2.

		public PU_DEVICE_ETHERNET_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bDhcpEnable", "szIPAddress", "szSubNetMask", "szGateWayAddress", "szFirstDNSAddress",
					"szSecondDNSAddress", "szReserved");
		}

	}

	// Device information structure.
	public static class PU_DEVICE_INFO extends Structure {
		public byte[] szDeviceName = new byte[PU_DEVICE_NAME_LEN]; // Device name. The device name can contain a maximum
																	// of 32 characters.
		public byte[] szDeviceFac = new byte[PU_FAC_NAME_LEN]; // Device vendor.
		public byte[] szDeviceType = new byte[PU_DEVICE_TYPE_LEN]; // Device model, which can be queried but cannot be
																	// set.
		public byte[] szSerialNumber = new byte[PU_SERIAL_LEN]; // Hardware SN.
		public PU_DEVICE_VERSION stDeviceVersion; // Device version.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // BOM code.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szDeviceName", "szDeviceFac", "szDeviceType", "szSerialNumber", "stDeviceVersion",
					"szReserved");
		}
	}

	public static class PU_DEVICE_INFO_EX extends Structure {
		public PU_DEVICE_INFO stDeviceInfo; // Basic device information.
		public PU_DEVICE_ETHERNET_PARA stDeviceEthernetPara; // Network parameters.
		public PU_DEV_CONFIG_INFO stConfigPara; // Device configuration information.
		public PU_RESOLUTION_INFO stResolution; // Video resolution information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_DEVICE_INFO_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stDeviceInfo", "stDeviceEthernetPara", "stConfigPara", "stResolution", "szReserved");
		}
	}

	// I/O trigger mode.
	public interface PU_DEVICE_IO_TYPE_E {
		int DEVICE_IO_NONE = 0; // Not triggered.
		int DEVICE_IO_RISE = 1; // Triggered by rising edge.
		int DEVICE_IO_DOWN = 2; // Triggered by falling edge.
		int DEVICE_IO_BOTH = 3; // Both.
	}

	// Device type.
	public interface PU_DEVICE_MODE_E {
		int EP_VIDEO_MODE = 0; // ePolice.
		int GT_VIDEO_MODE = 1; // Checkpoint.
		int ITS_MODE_MAX = 2;
	}

	// Port configuration parameters.
	public static class PU_DEVICE_PORT_CONFIG extends Structure {
		public WinDef.USHORT usHTTPPort; // HTTP port.
		public WinDef.USHORT usHTTPSPort; // HTTPS port.
		public WinDef.USHORT usRTSPPort; // RTSP port.

		public PU_DEVICE_PORT_CONFIG() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usHTTPPort", "usHTTPSPort", "usRTSPPort");
		}
	}

	// Extended port configuration parameters.
	public static class PU_DEVICE_PORT_CONFIG_EX extends Structure {
		public WinDef.USHORT usHTTPPort; // HTTP port.
		public WinDef.USHORT usHTTPSPort; // HTTPS port.
		public WinDef.USHORT usRTSPPort; // RTSP port.
		public ULONG ulMeshIndex; // Network port index.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_DEVICE_PORT_CONFIG_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usHTTPPort", "usHTTPSPort", "usRTSPPort", "ulMeshIndex", "szReserved");
		}
	}

	// Extended port configuration parameters.
	public static class PU_DEVICE_PORT_CONFIG_EX_S extends Structure {
		public short usHTTPPort; // HTTP port.
		public short usHTTPSPort; // HTTPS port.
		public short usRTSPPort; // RTSP port.
		public ULONG ulMeshIndex; // Network port index.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_DEVICE_PORT_CONFIG_EX_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usHTTPPort", "usHTTPSPort", "usRTSPPort", "ulMeshIndex", "szReserved");
		}
	}

	// Port configuration parameters.
	public static class PU_DEVICE_PORT_CONFIG_S extends Structure {
		public short usHTTPPort; // HTTP port.
		public short usHTTPSPort; // HTTPS port.
		public short usRTSPPort; // RTSP port.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usHTTPPort", "usHTTPSPort", "usRTSPPort");
		}
	}

	public static class PU_DEVICE_REGISTER_RSP extends Structure {
		public int enErrorCode; // ERROR_CODE

		public byte[] szRedirectIp = new byte[PU_IP4_ADDR_LEN];
		public ULONG ulRedirectPort;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_DEVICE_REGISTER_RSP() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enErrorCode", "szRedirectIp", "ulRedirectPort", "szReserved");
		}
	}

	// Device version.
	public static class PU_DEVICE_VERSION extends Structure {
		public byte[] szVerSoftware = new byte[PU_VERSION_LEN]; // Software version.

		public byte[] szVerUboot = new byte[PU_VERSION_LEN]; // UBoot version.

		public byte[] szVerKernel = new byte[PU_VERSION_LEN]; // Kernel version.

		public byte[] szVerHardware = new byte[PU_VERSION_LEN]; // Hardware version.

		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // The first 24 bytes indicate the MAC address.
		// szReserved[24]: input parameter, indicating the network port index. The value
		// 0 indicates network adapter 1. The value 1 indicates network adapter 2.
		// szReserved[25]: output parameter, indicating the number of network ports.

		public PU_DEVICE_VERSION() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szVerSoftware", "szVerUboot", "szVerKernel", "szVerHardware", "szReserved");
		}
	}

	public static class PU_DIALING_CONFIG_INFO_S extends Structure {
		public PU_ENABLE_TYPE_E enEnable;
		// C type : DIAL_MODE_E
		public int enDialingMode;
		// C type : WIRELESS_NET_MODE_E
		public int enWirelessNetMode;
		public PU_DIALING_PARA_S stDialingPara;

		public PU_DIALING_CONFIG_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enEnable", "enDialingMode", "enWirelessNetMode", "stDialingPara");
		}
	}

	/******** DIAL ********/
	public static class PU_DIALING_PARA_S extends Structure {
		// C type: DIAL_AUTH_TYPE_E
		public int enAuthType; /*
								 * Authentication type (The user name and password can be left empty if no
								 * authentication is required.).
								 */
		public byte[] szApn = new byte[DIAL_APP_LEN_MAX];
		public byte[] szUserName = new byte[DIAL_USR_NAME_LEN_MAX];
		public byte[] szPassWd = new byte[DIAL_PASSWD_LEN_MAX];

		public PU_DIALING_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enAuthType", "szApn", "szUserName", "szPassWd");
		}
	}

	public static class PU_DIALING_PLAN_DAY_S extends Structure {
		public PU_TIME_RANGE_MIN_S[] szTimeRange = (PU_TIME_RANGE_MIN_S[]) new PU_TIME_RANGE_MIN_S()
				.toArray(DIAL_PLAN_AREA_MAX);

		public PU_DIALING_PLAN_DAY_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szTimeRange");
		}
	}

	public static class PU_DIALING_STATUS_INFO_S extends Structure {
		// C Type : DIAL_SIM_STATUS_TYPE_E
		public DIAL_SIM_STATUS_TYPE_E enSimStatus; // SIM card status.
		// C Type : DIAL_NET_ACT_TYPE_E
		public DIAL_NET_ACT_TYPE_E enActType; // Network standard.
		public int nSignalStrength; // Signal strength.
		// C Type : DIAL_CONNECT_E
		public DIAL_CONNECT_E enIPv4ConnectStat; /* IPv4 dial-up status. */
		public byte[] szIPv4Address = new byte[IPV4_ADDR_LEN]; /* IPv4 address. */
		public byte[] szIPv4NetMask = new byte[IPV4_ADDR_LEN]; /* IPv4 subnet mask. */
		public byte[] szIPv4NetGate = new byte[IPV4_ADDR_LEN]; /* IPv4 gateway. */
		public byte[] szIPv4pDnsAddr = new byte[IPV4_ADDR_LEN]; /* Primary IPv4 DNS. */
		public byte[] szIPv4sDnsAddr = new byte[IPV4_ADDR_LEN]; /* Secondary IPv4 DNS. */
		public byte[] szPLMNName = new byte[DIAL_PLMN_NAME_MAX]; /* Carrier status. */

		public PU_DIALING_STATUS_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSimStatus", "enActType", "nSignalStrength", "enIPv4ConnectStat", "szIPv4Address",
					"szIPv4NetMask", "szIPv4NetGate", "szIPv4pDnsAddr", "szIPv4sDnsAddr", "szPLMNName");
		}
	}

	/************************
	 * Boolean value input and output parameters
	 **********************/
	public static class PU_DIO_PARA extends Structure {
		public PU_SWITCH_INPUT_PARA[] stInput = new PU_SWITCH_INPUT_PARA[PU_DIO_NUM_MAX];
		public PU_SWITCH_OUTPUT_PARA[] stOutput = new PU_SWITCH_OUTPUT_PARA[PU_DIO_NUM_MAX];
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_DIO_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stInput", "stOutput", "szReserved");
		}
	}

	// Response packet discover.
	public static class PU_DISCOVER_DEVICE_INFO_S extends Structure {
		public byte[] szDeviceMac = new byte[PU_MAC_ADDR_LEN]; // Device MAC address.

		public byte[] szDeviceType = new byte[PU_DEVICE_TYPE_LEN]; // Device model.
		public byte[] szDeviceVersion = new byte[PU_VERSION_LEN]; // Device version number.
		public byte[] szDeviceName = new byte[PU_DEVICE_NAME_LEN]; // Device name.
		public byte[] szDeviceIp = new byte[PU_IP4_ADDR_LEN]; // Device IP address.
		public byte[] szDeviceMask = new byte[PU_IP4_ADDR_LEN]; // Device mask.
		public byte[] szDeviceGateway = new byte[PU_IP4_ADDR_LEN]; // Device gateway.
		public byte[] szSerialNumber = new byte[PU_SERIAL_LEN]; // SN.
		public WinDef.UINT uDhcpEnable; // Indicates whether to enable DHCP. The options are as follows: 0: no; 1: yes;
										// 2 (for compatibility with earlier version): unknown.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_DISCOVER_DEVICE_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szDeviceMac", "szDeviceType", "szDeviceVersion", "szDeviceName", "szDeviceIp",
					"szDeviceMask", "szDeviceGateway", "szSerialNumber", "uDhcpEnable", "szReserved");
		}
	}

	public static class PU_DISCOVER_DEVICE_LIST extends Structure {
		public NativeLong ulDeviceNum;

		public PU_DISCOVER_DEVICE_INFO_S[] stDeviceInfo = new PU_DISCOVER_DEVICE_INFO_S[PU_DEVICE_NUM_MAX];
		byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_DISCOVER_DEVICE_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulDeviceNum", "stDeviceInfo", "szReserved");
		}
	}

	/* Disk type. */
	public interface PU_DISK_TYPE {
		public static final int PU_DISK_TYPE_IDE = 1; // IDE hard disk.
		public static final int PU_DISK_TYPE_SATA = 2; // Hard disk with serial interfaces.
		public static final int PU_DISK_TYPE_FLASH = 3; // Flash memory, such as SD and CF.
		public static final int PU_DISK_TYPE_UNKNOWN = 4;
	}

	// Decoder type.
	// Resolution mode.
	public interface PU_DISRESOLUTION_MODE {
		public static final int PU_VGA_NOT_AVALIABLE = 0;
		public static final int PU_VGA_MODE_SVGA_60HZ = 1;
		public static final int PU_VGA_MODE_SVGA_75HZ = 2;
		public static final int PU_VGA_MODE_XGA_60HZ = 3;
		public static final int PU_VGA_MODE_XGA_70HZ = 4;
		public static final int PU_VGA_MODE_SXGA_60HZ = 5;
		public static final int PU_VGA_MODE_720P_60HZ = 6;
		public static final int PU_VGA_MODE_1080I_60HZ = 7;
		public static final int PU_VGA_MODE_1080P_30HZ = 8;
		public static final int PU_VGA_MODE_UXGA_30HZ = 9;
		public static final int PU_HDMI_MODE_XGA_60HZ = 21;
		public static final int PU_HDMI_MODE_SXGA_60HZ = 22;
		public static final int PU_HDMI_MODE_SXGA2_60HZ = 23;
		public static final int PU_HDMI_MODE_720P_60HZ = 24;
		public static final int PU_HDMI_MODE_720P_50HZ = 25;
		public static final int PU_HDMI_MODE_1080I_60HZ = 26;
		public static final int PU_HDMI_MODE_1080I_50HZ = 27;
		public static final int PU_HDMI_MODE_1080P_25HZ = 28;
		public static final int PU_HDMI_MODE_1080P_30HZ = 29;
		public static final int PU_HDMI_MODE_1080P_50HZ = 30;
		public static final int PU_HDMI_MODE_1080P_60HZ = 31;
		public static final int PU_HDMI_MODE_UXGA_60HZ = 32;
		public static final int PU_DVI_MODE_XGA_60HZ = 41;
		public static final int PU_DVI_MODE_SXGA_60HZ = 42;
		public static final int PU_DVI_MODE_SXGA2_60HZ = 43;
		public static final int PU_DVI_MODE_720P_60HZ = 44;
		public static final int PU_DVI_MODE_720P_50HZ = 45;
		public static final int PU_DVI_MODE_1080I_60HZ = 46;
		public static final int PU_DVI_MODE_1080I_50HZ = 47;
		public static final int PU_DVI_MODE_1080P_25HZ = 48;
		public static final int PU_DVI_MODE_1080P_30HZ = 49;
		public static final int PU_DVI_MODE_1080P_50HZ = 50;
		public static final int PU_DVI_MODE_1080P_60HZ = 51;
		public static final int PU_DVI_MODE_UXGA_60HZ = 52;
		public static final int PU_BNC_MODE_D1PAL_60HZ = 61;
		public static final int PU_BNC_MODE_D1PAL_50HZ = 62;
		public static final int PU_BNC_MODE_D1NTSC_60HZ = 63;
		public static final int PU_BNC_MODE_D1NTSC_50HZ = 64;
		public static final int PU_DISRESOLUTION_MODE_MAX = 65;
	}

	/* 802.1X EAP TLS certificate upload type. */
	/* 802.1X configuration information. */
	public static class PU_DOT1X_CONFIG_INFO extends Structure {
		public WinDef.BOOL bDot1xEnable; // Indicates whether to enable 802.1X.
		public int enEapolVersion; // EAPOL version. c type:PU_DOT1X_EAPOL_VERSION
		public byte[] szEapUserName = new byte[PU_USER_NAME_LEN]; // EAP user name.
		public byte[] szEapPassWord = new byte[PU_PASSWORD_LEN]; // EAPPwd
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates whether to enable EAP MD5. The
																// options are 0 (no) and 1 (yes).

		public PU_DOT1X_CONFIG_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bDot1xEnable", "enEapolVersion", "szEapUserName", "szEapPassWord", "szReserved");
		}
	}

	/* 802.1X EAP TLS certificate upload type. */
	/* EAPOL version number. */
	public interface PU_DOT1X_EAPOL_VERSION {
		public static final int PU_DOT1X_EAPOL_VERSION_1 = 1;
		public static final int PU_DOT1X_EAPOL_VERSION_2 = 2;
		public static final int PU_DOT1X_EAPOL_VERSION_MAX = 3;
	}

	/* 802.1X EAP TLS certificate upload. */
	public static class PU_DOT1X_TLS_CERT_UPLOAD_S extends Structure {
		public int enAction; // Upload type.

		public byte[] szPassword = new byte[PU_PASSWORD_LEN]; // Password for encrypting the private key file.

		public PU_DOT1X_TLS_CERT_UPLOAD_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enAction", "szPassword");
		}
	}

	/* 802.1X EAP TLS certificate upload type. */
	public interface PU_DOT1X_TLS_CERT_UPLOAD_TYPE {
		public static final int PU_DOT1X_TLS_CA_CERT_UPLOAD_TYPE = 0;
		public static final int PU_DOT1X_TLS_CLIENT_CERT_UPLOAD_TYPE = 1;
		public static final int PU_DOT1X_TLS_CERT_UPLOAD_TYPE_MAX = 2;
	}

	/* 802.1X EAP TLS certificate upload type. */
	public interface PU_DOT1X_TLS_CERT_UPLOAD_TYPE_E {
		public static final int PU_DOT1X_TLS_CA_CERT_UPLOAD_TYPE = 0;
		public static final int PU_DOT1X_TLS_CLIENT_CERT_UPLOAD_TYPE = 1;
		public static final int PU_DOT1X_TLS_CERT_UPLOAD_TYPE_MAX = 2;
	}

	public interface PU_DSCP_TYPE {
		public static final int PU_DSCP_TYPE_MEDIA = 0; // Media differentiated services code point (DSCP) value (the
														// media include audio and video).
		public static final int PU_DSCP_TYPE_CMD = 1; // Signaling DSCP value (the signaling includes alarms).
		public static final int PU_DSCP_TYPE_MAX = 2;
	}

	// DST start and end time.
	public static class PU_DST_DATE_S extends Structure {
		public PU_DST_WEEK_WAY_S stDSTWeekWay; // DST time implemented by week.

		public PU_DST_DATE_WAY_S stDSTDateWay; // DST time implemented by date.

		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_DST_DATE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stDSTWeekWay", "stDSTDateWay", "szReserved");
		}
	}

	// Implementing DST by date.
	public static class PU_DST_DATE_WAY_S extends Structure {
		public WinDef.UINT uiYear; // The value 0 indicates every year, and [2014,2024] indicates the corresponding
									// years.

		public WinDef.UINT uiMonth; // Month in a year. The value ranges from 0 to 11, indicating January to
									// December.

		public WinDef.UINT uiDay; // Day in a month. The value ranges from 0 to 30, indicating the first day to
									// the last day in a month.

		public WinDef.UINT uiHour; // Hour in a day. The value ranges from 0 to 23.

		public WinDef.UINT uiMinute; // Minute in an hour. The value ranges from 0 to 59.

		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_DST_DATE_WAY_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiYear", "uiMonth", "uiDay", "uiHour", "uiMinute", "szReserved");
		}
	}

	// DST offset.
	public interface PU_DST_OFFSET {
		public static final int OFFSET_NONE = 0;
		public static final int OFFSET_30_MIN = 30;
		public static final int OFFSET_60_MIN = 60;
		public static final int OFFSET_90_MIN = 90;
		public static final int OFFSET_120_MIN = 120;
	}

	// DST offset.
	public interface PU_DST_OFFSET_E {
		public final int OFFSET_NONE = 0;
		public final int OFFSET_30_MIN = 30;
		public final int OFFSET_60_MIN = 60;
		public final int OFFSET_90_MIN = 90;
		public final int OFFSET_120_MIN = 120;
	}

	// DST implementation mode.
	public interface PU_DST_TYPE {
		public static final int DST_WEEK_WAY = 0;
		public static final int DST_DATE_WAY = 1;
		public static final int DST_TYPE_MAX = 2;
	}

	// DST implementation mode.
	public interface PU_DST_TYPE_E {
		public final int DST_WEEK_WAY = 0;
		public final int DST_DATE_WAY = 1;
		public final int DST_TYPE_MAX = 2;
	}

	// Implementing DST by week.
	public static class PU_DST_WEEK_WAY_S extends Structure {
		public WinDef.UINT uiMonth; // Month in a year. The value ranges from 0 to 11, indicating January to
									// December.

		public WinDef.UINT uiWeek; // Week in a month. The options are as follows: 0: first week; 1: second week,
									// 2: third week; 3: fourth week; 4: last week.

		public WinDef.UINT uiDayofWeek; // Day in a week. The value ranges from 0 to 6, indicating Sunday to Saturday.

		public WinDef.UINT uiHour; // Hour in a day. The value ranges from 0 to 23.

		public WinDef.UINT uiMinute; // Minute in an hour. The value ranges from 0 to 59.

		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_DST_WEEK_WAY_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiMonth", "uiWeek", "uiDayofWeek", "uiHour", "uiMinute", "szReserved");
		}
	}

	// Variable bit rate/Dynamic frame rate.
	public static class PU_DYNAMIC_STREAM_INFO extends Structure {
		public ULONG ulChannelId;
		public WinDef.BOOL ulEnable; // Indicates whether to enable variable bit rate.
		public ULONG ulDynamicFrameRate; // Dynamic frame rate.
		public ULONG ulDynamicBitRate; // VBR.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates whether to enable dynamic frame
																// rate.

		public PU_DYNAMIC_STREAM_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulEnable", "ulDynamicFrameRate", "ulDynamicBitRate", "szReserved");
		}
	}

	/* Indicates whether to enable the dial-up function. */
	public interface PU_ENABLE_TYPE_E {
		/*
		 * Enumeration parameters must be arranged in descending order. Otherwise, a
		 * value is automatically assigned to each enumeration parameter.
		 */
		int PU_ENABLE_FALSE = 0; // Disable.
		int PU_ENABLE_TRUE = 1; // Indicates whether to enable the ROI.
		int PU_ENABLE_MAX = 2;
	}

	// Audio and video encoding standards.
	public interface PU_ENCODE_TYPE {
		public static final int PU_ENC_PCMU = 0;
		public static final int PU_ENC_1016 = 1;
		public static final int PU_ENC_G721 = 2;
		public static final int PU_ENC_GSM = 3;
		public static final int PU_ENC_G723 = 4;
		public static final int PU_ENC_DVI4_8K = 5;
		public static final int PU_ENC_DVI4_16K = 6;
		public static final int PU_ENC_LPC = 7;
		public static final int PU_ENC_PCMA = 8;
		public static final int PU_ENC_G722 = 9;
		public static final int PU_ENC_S16BE_STEREO = 10;
		public static final int PU_ENC_S16BE_MONO = 11;
		public static final int PU_ENC_QCELP = 12;
		public static final int PU_ENC_CN = 13;
		public static final int PU_ENC_MPEGAUDIO = 14;
		public static final int PU_ENC_G728 = 15;
		public static final int PU_ENC_DVI4_3 = 16;
		public static final int PU_ENC_DVI4_4 = 17;
		public static final int PU_ENC_G729 = 18;
		public static final int PU_ENC_G711A = 19; // g711a
		public static final int PU_ENC_G711U = 20; // g711u
		public static final int PU_ENC_G726 = 21; // g726
		public static final int PU_ENC_G729A = 22;
		public static final int PU_ENC_LPCM = 23;
		public static final int PU_ENC_CelB = 25;
		public static final int PU_ENC_JPEG = 26;
		public static final int PU_ENC_CUSM = 27;
		public static final int PU_ENC_NV = 28;
		public static final int PU_ENC_PICW = 29;
		public static final int PU_ENC_CPV = 30;
		public static final int PU_ENC_H261 = 31;
		public static final int PU_ENC_MPEGVIDEO = 32;
		public static final int PU_ENC_MPEG2TS = 33;
		public static final int PU_ENC_H263 = 34;
		public static final int PU_ENC_SPEG = 35;
		public static final int PU_ENC_MPEG2VIDEO = 36;
		public static final int PU_ENC_AAC = 37;
		public static final int PU_ENC_WMA9STD = 38;
		public static final int PU_ENC_HEAAC = 39;
		public static final int PU_ENC_PCM_VOICE = 40;
		public static final int PU_ENC_PCM_AUDIO = 41;
		public static final int PU_ENC_AACLC = 42;
		public static final int PU_ENC_MP3 = 43;
		public static final int PU_ENC_ADPCMA = 49;
		public static final int PU_ENC_AEC = 50;
		public static final int PU_ENC_X_LD = 95;
		public static final int PU_ENC_H264 = 96;
		public static final int PU_ENC_D_GSM_HR = 200;
		public static final int PU_ENC_D_GSM_EFR = 201;
		public static final int PU_ENC_D_L8 = 202;
		public static final int PU_ENC_D_RED = 203;
		public static final int PU_ENC_D_VDVI = 204;
		public static final int PU_ENC_D_BT656 = 220;
		public static final int PU_ENC_D_H263_1998 = 221;
		public static final int PU_ENC_D_MP1S = 222;
		public static final int PU_ENC_D_MP2P = 223;
		public static final int PU_ENC_D_BMPEG = 224;
		public static final int PU_ENC_MP4VIDEO = 230; // mepg-4
		public static final int PU_ENC_MP4AUDIO = 237;
		public static final int PU_ENC_VC1 = 238;
		public static final int PU_ENC_JVC_ASF = 255;
		public static final int PU_ENC_D_AVI = 256;
		public static final int PU_ENC_OPUS = 258; // opus
		public static final int PU_ENC_H265 = 265;
		public static final int PU_ENC_AMR = 1001;
		public static final int PU_ENC_MJPEG = 1002; // motion jpeg
		public static final int PU_ENC_MAX = 1003;
	}

	// Stream encryption mode.
	public interface PU_ENCRYPT_TYPE {
		public static final int PU_ENCRYPT_TYPE_HUAWEI_VIDEO = 0; // Uses Huawei stream encryption algorithm to encrypt
																	// video.
		public static final int PU_ENCRYPT_TYPE_HUAWEI_AUDIO = 1; // Uses Huawei stream encryption algorithm to encrypt
																	// audio.
		public static final int PU_ENCRYPT_TYPE_HUAWEI_MUX = 2; // Uses Huawei stream encryption algorithm to encrypt
																// hybrid streams.
		public static final int PU_ENCRYPT_TYPE_NONE = 3; // Does not encrypt streams.
		public static final int PU_ENCRYPT_TYPE_MAX = 4;
	}

	// ePTZ control.
	public static class PU_EPTZ_CTRL extends Structure {
		public ULONG ulChnID;
		public int enStreamType; // c type:PU_STREAM_TYPE
		public WinDef.BOOL bMoveEnable;
		public NativeLong lHorizonalSpeed;
		public NativeLong lVerticalSpeed;
		public NativeLong lZoomSpeed;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_EPTZ_CTRL() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "enStreamType", "bMoveEnable", "lHorizonalSpeed", "lVerticalSpeed",
					"lZoomSpeed", "szReserved");
		}
	}

	// ePTZ parameters.
	public static class PU_EPTZ_PARA extends Structure {
		public ULONG ulChannelId;
		public int enStreamType; // c type:PU_STREAM_TYPE
		public WinDef.BOOL bEnable;
		public ULONG ulLeftPercent;
		public ULONG ulTopPercent;
		public ULONG ulWidthPercent;
		public ULONG ulHeightPercent;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_EPTZ_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enStreamType", "bEnable", "ulLeftPercent", "ulTopPercent",
					"ulWidthPercent", "ulHeightPercent", "szReserved");
		}
	}

	// device common callback event struct, include: off line, upload image complete
	// notify
	public static class PU_EVENT_COMMON extends Structure {
		public int enEventType; // 事件类型 /* C type is PU_EVENT_TYPE */
		public ULONG ulIdentifyID; // 唯一标识的ID号
		public ULONG ulChannelId;

		public PU_EVENT_COMMON() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enEventType", "ulIdentifyID", "ulChannelId");
		}
	}

	// device event callback type
	public interface PU_EVENT_TYPE {
		/* Connection status callback. */
		public static final int PU_EVENT_TYPE_CONNCET = 1; // The PU proactively connects to the network.
		public static final int PU_EVENT_TYPE_REGISTER = 2; // Proactive PU registration.
		public static final int PU_EVENT_TYPE_NOT_REGISTER = 3; // The PU is not registered with the platform after
																// proactively connecting to the network.
		public static final int PU_EVENT_TYPE_UNREGISTER = 4; // Proactive PU deregistration.
		public static final int PU_EVENT_TYPE_DISCONNECT = 5; // The PU is disconnected from the network.
		public static final int PU_EVENT_TYPE_SEND_RECV_ERROR = 6; // Sending or receiving failed.
		public static final int PU_EVENT_TYPE_KEEPLIVE_FAIL = 7; // PU keepalive failure.
		/* Event notification callback. */
		public static final int PU_EVENT_TYPE_STREAM_PACKAGE_CHANGE = 8; // Stream profile change.
		public static final int PU_EVENT_TYPE_WATERMARK_ERR = 9; // Digital watermark verification error.
		public static final int PU_EVENT_TYPE_UPLOAD_IMAGE_URL = 10; // The PU proactively obtains the URL for uploading
																		// snapshots.
		public static final int PU_EVENT_TYPE_UPLOAD_IMAGE_COMP_NOTIFY = 11; // Send a PU-triggered snapshot upload
																				// completion notification.
		public static final int PU_EVENT_TYPE_TRANSPARENT_CHANNEL_NOTIFY = 12; // Report transparent channel data.
		public static final int PU_EVENT_TYPE_REALPALY_ERROR = 13; // The live video is abnormal.
		public static final int PU_EVENT_TYPE_REPORT_VISUAL_INFO = 14; // Report visualized information.
		public static final int PU_EVENT_TYPE_PUPU_INFO = 15; // Report multi-camera collaboration data.
		public static final int PU_EVENT_TYPE_RECORD_COMP_NOTIFY = 16; // Send a recording download completion
																		// notification.
		public static final int PU_EVENT_TYPE_SLAVE_DEVICE_ADD = 17; // Event for adding a slave device.
		public static final int PU_EVENT_TYPE_SLAVE_DEVICE_MODIFY = 18; // Event for modifying a slave device.
		public static final int PU_EVENT_TYPE_SLAVE_DEVICE_DELETE = 19; // Event for deleting a slave device.
		public static final int PU_EVENT_TYPE_SLAVE_DEVICE_ONLINE = 20; // Slave device going online event.
		public static final int PU_EVENT_TYPE_SLAVE_DEVICE_OFFLINE = 21; // Slave device going offline event.
		public static final int PU_EVENT_TYPE_MAX = 22;
	}

	// Flash light triggering level.
	public interface PU_EXP_LAMP_TRIG_LEVEL {
		public static final int PU_TRIG_HIGH_LEVEL = 0; // Triggered by high electrical level.
		public static final int PU_TRIG_LOW_LEVEL = 1; // Triggered by low electric level.
	}

	/* Exposure compensation. */
	public static class PU_EXPCOMP_PARA_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enExpComp; // Exposure compensation (enable/disable). C type：PU_COMMONMODE_SWITCH
		public NativeLong lExpComp; // Compensation coefficient (0–255).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_EXPCOMP_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enExpComp", "lExpComp", "szReserve");
		}
	}

	// Flash light parameters.
	public static class PU_EXPOSURE_LAMP_ATTR_S extends Structure {
		/* C type : PU_EXT_LAMP_WORK_MODE_E */
		public int enExtLampWorkMode; // External illuminator work mode.
		public ULONG ulPulseWidth; // Pulse width.
		public ULONG ulDelayTime; // Delay time used for synchronization adjustment.
		/* C type : PU_EXP_LAMP_TRIG_LEVEL_E */
		public int enExpLampTrigLevel; // Flash light triggering level.
		public ULONG ulLightThreshold; // Luminance threshold. This parameter is valid in automatic mode.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_EXPOSURE_LAMP_ATTR_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enExtLampWorkMode", "ulPulseWidth", "ulDelayTime", "enExpLampTrigLevel",
					"ulLightThreshold", "szReserved");
		}
	}

	// External illuminator parameters.
	public static class PU_EXT_LAMP_ATTR_S extends Structure {
		/* C type PU_EXT_LAMP_TYPE */
		public int enExtLampType; // External illuminator type.
		public PU_EXPOSURE_LAMP_ATTR_S stExposureLampAttr; // Flash light attribute.
		public PU_STROBE_LAMP_ATTR_S stStrobeLampAttr; // Strobe light attribute.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enExtLampType", "stExposureLampAttr", "stStrobeLampAttr", "szReserved");
		}
	}

	/* Strobe light frequency. */
	public interface PU_EXT_LAMP_FREQ {
		public static final int PU_FREQ_50 = 0; /* 50hz */
		public static final int PU_FREQ_60 = 1; /* 60hz */
		public static final int PU_FREQ_100 = 2; /* 100hz */
		public static final int PU_FREQ_120 = 3; /* 120hz */
	}

	// External illuminator type.
	public interface PU_EXT_LAMP_TYPE {
		public static final int PU_EXPOSURE_LAMP = 0; // Flash light.
		public static final int PU_STROBE_LAMP = 1; // Strobe light.
	}

	// External illuminator work mode.
	public interface PU_EXT_LAMP_WORK_MODE {
		public static final int PU_WORK_MODE_OFF = 0; // Always off.
		public static final int PU_WORK_MODE_ON = 1; // Always on.
	}

	// External detector type.
	public interface PU_EXTRA_DEVICE_TYPE_E {
		int ITS_EQUIP_TYPE_INVALID = 0;

		int ITS_EQUIP_RS485_RADAR_CSR_1K = 1; // CSR-IK single-lane radar detector of Beijing TransMicrowave.
		int ITS_EQUIP_RS485_RADAR_CSR_IN = 2; // CSR-IN single-lane radar detector of Beijing TransMicrowave.
		int ITS_EQUIP_RS485_RADAR_CSR_IM = 3; // CSR-IM multi-lane radar detector of Beijing TransMicrowave.
		int ITS_EQUIP_RS485_RADAR_MPR_LV = 4; // MPR-LV traffic radar detector of Shanghai Huichang Company.

		int ITS_EQUIP_RS485_COIL_TULI_PK600K = 100; // Loop vehicle detector of Shanghai TORYWAY.

		int ITS_EQUIP_RS485_LIGHT_DTOR_TL01 = 200; // Traffic signal detector of Beijing Signalway.

		int ITS_EQUIP_IO = 300; // I/O protocol.
	}

	// Face detection.
	public static class PU_FACE_DETC_ALARM_PARA_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public ULONG ulBitMap; // 0000. If the last bit is set to 1, the first structure body parameter is set.
		public PU_FACE_DETC_PARA_S stFDPara; // Face detection parameter.
		public PU_FACE_TRACKING_PARAMETER_S stFDTrackPara; // Face tracking parameter.
		public PU_FACE_PROCESS_PARAM_S stFDProcPara; // Face processing parameter.
		public PU_FD_AREA_LIST_S stAreaList; // Face detection area.
		public PU_ALARM_TIME_LIST_S stFDGuardPlan; // Face detection alert plan.

		public PU_FACE_DETC_ALARM_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulBitMap", "stFDPara", "stFDTrackPara", "stFDProcPara", "stAreaList",
					"stFDGuardPlan");
		}
	}

	// Face/Person detection.
	public static class PU_FACE_DETC_DL_ALARM_PARA_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public ULONG ulBitMap; // 0000. If the last bit is set to 1, the first structure body parameter is set.
		public PU_FACE_DETC_DL_PARA_S stFDPara; // Face detection parameter.
		public PU_FACE_PROCESS_DL_PARAM_S stFDProcPara; // Face processing parameter.
		public PU_FD_AREA_LIST_S stAreaList; // Face detection area.
		public PU_FD_AREA_LIST_S stUnGuardAreaList; // Area where face detection is disabled.
		public PU_ALARM_TIME_LIST_S stFDGuardPlan; // Face detection alert plan.

		public PU_FACE_DETC_DL_ALARM_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulBitMap", "stFDPara", "stFDProcPara", "stAreaList", "stUnGuardAreaList",
					"stFDGuardPlan");
		}
	}

	// Parameters of face and person detection algorithms.
	public static class PU_FACE_DETC_DL_PARA_S extends Structure {
		public BOOL bEnable; // Indicates whether to enable snapshot retransmission.
		public ULONG ulAlarmTime; // Alarm check interval.
		public ULONG ulSensitivity; // Detection sensitivity.
		public ULONG ulFaceSensitivity; // Face detection sensitivity.
		public ULONG ulBodySensitivity; // Person detection sensitivity.
		public ULONG ulFaceKpsSensitivity; // Face image quality filtering sensitivity.
		public ULONG ulBodyKpsSensitivity; // Person image quality filtering sensitivity.
		public ULONG ulMinPupilDist; // Minimum face size.
		public ULONG ulMaxPupilDist; // Maximum face size.
		// C Type : PU_FACE_DETECTION_DL_MODE
		public int enMode; // Detection mode.
		public BOOL bFaceExposure; // Face exposure.
		public ULONG ulROIMeterLevel; // Face exposure sensitivity.
		// C Type : FACE_DT_CAP_MODE_E
		public int enFaceCapMode; // Snapshot mode.
		public char ulFaceCapSensitivity; // Fast snapshot sensitivity.
		public char uchFaceExposureTime; // Face exposure time.
		public BOOL bSensitivityFlage; // Quality sensitivity switch, corresponding to the preceding face/person image
										// quality filtering sensitivity.
		public byte[] szReserved = new byte[PU_RESERVE_LEN - 4 - 4 * 2 - 4];

		public PU_FACE_DETC_DL_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulAlarmTime", "ulSensitivity", "ulFaceSensitivity", "ulBodySensitivity",
					"ulFaceKpsSensitivity", "ulBodyKpsSensitivity", "ulMinPupilDist", "ulMaxPupilDist", "enMode",
					"bFaceExposure", "ulROIMeterLevel", "enFaceCapMode", "ulFaceCapSensitivity", "uchFaceExposureTime",
					"bSensitivityFlage", "szReserved");
		}
	}

	public static class PU_FACE_DETC_PARA_S extends Structure {
		public ULONG ulAlarmTime; // Alarm check interval.
		public BOOL bEnable; // Indicates whether to enable snapshot retransmission.
		public ULONG ulSensitivity; // Detection sensitivity.
		public ULONG ulMinDectFace; // Minimum face size that can be detected. The value ranges from 66 to 486
									// pixels. It is recommended that the minimum face width be 70 pixels and the
									// maximum face width be 180 pixels in distant view mode. It is recommended that
									// the minimum face width be 131 pixels and the maximum face width be 273 pixels
									// in close-up view mode.
		public ULONG ulMaxDectFace; // Maximum face that can be detected. The value ranges from 66 to 486 pixels. It
									// is recommended that the minimum face width be 70 pixels and the maximum face
									// width be 180 pixels in distant view mode. It is recommended that the minimum
									// face width be 131 pixels and the maximum face width be 273 pixels in close-up
									// view mode.
		public ULONG ulDectMode; // Detection mode. The options are as follows: 0 distant view mode; 1: close-up
									// view mode.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_FACE_DETC_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulAlarmTime", "bEnable", "ulSensitivity", "ulMinDectFace", "ulMaxDectFace",
					"ulDectMode", "szReserved");
		}
	}

	// Face/Person detection mode.
	public interface PU_FACE_DETECTION_DL_MODE {
		public static final int FACE_MODE = 0; // Face detection.
		public static final int BODY_MODE = 1; // Person detection.
		public static final int FACE_BODY_MODE = 2; // Face/Person detection.
	}

	// Facial feature extraction.
	public static class PU_FACE_FEATURE_EXTRACT_S extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public PU_FACE_LIB_S stFacelib; // Face list.

		public WinDef.ULONG taskID; // Task ID.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_FEATURE_EXTRACT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stFacelib", "taskID", "szReserve");
		}

	}

	public static class PU_FACE_FEATURE_GET_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public PU_FACE_LIB_S stFacelib; // Face list.
		public byte[] szFeatureFilePath = new byte[PU_SAVE_FILE_PATH_MAX]; // Path of saving the exported feature file.
		public byte[] szExportCsvPath = new byte[PU_SAVE_FILE_PATH_MAX]; // Path of the CSV file for storing the
																			// exported results.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_FEATURE_GET_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stFacelib", "szFeatureFilePath", "szExportCsvPath", "szReserve");
		}
	}

	// Face-related information.
	public static class PU_FACE_FIND_CONDITION_S extends Structure {
		public static class ByValue extends PU_FACE_FIND_CONDITION_S implements Structure.ByValue {
		}

		public byte[] szName = new byte[PU_MAX_RECORD_LEN_64]; // Name.

		public int enGender; // Sex.

		public byte[] szProvince = new byte[PU_MAX_RECORD_LEN_32]; // Province.

		public byte[] szCity = new byte[PU_MAX_RECORD_LEN_48]; // City.

		public int enCardType; // ID type.

		public byte[] szCardID = new byte[PU_MAX_RECORD_LEN_32]; // ID number.

		public byte[] szBirthdayStart = new byte[PU_MAX_RECORD_LEN_32]; // Start time of birth date.

		public byte[] szBirthdayEnd = new byte[PU_MAX_RECORD_LEN_32]; // End time of birth date.

		public int enFeatureStatus = 1; // Feature status.

		public byte[] szReserve = new byte[PU_RESERVE_LEN - 4];

		public PU_FACE_FIND_CONDITION_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szName", "enGender", "szProvince", "szCity", "enCardType", "szCardID",
					"szBirthdayStart", "szBirthdayEnd", "enFeatureStatus", "szReserve");
		}
	}

	// Operation for adding a single face image.
	public static class PU_FACE_INFO_ADD_S extends Structure {
		public WinDef.ULONG ulChannelId;// Channel ID.

		public PU_FACE_LIB_S.ByValue stFacelib;// Face list.

		public PU_FACE_RECORD_S.ByValue stRecord;// Information.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_INFO_ADD_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList(new String[] { "ulChannelId", "stFacelib", "stRecord", "szReserve" });
		}
	}

	// Delete face information.
	public static class PU_FACE_INFO_DELETE_S extends Structure {
		public WinDef.ULONG ulChannelId;

		public PU_FACE_LIB_S.ByValue stFacelib;

		public int uFaceNum;

		public int[] uFaceID = new int[PU_MAX_DELETE_NUM];

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_INFO_DELETE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stFacelib", "uFaceNum", "uFaceID", "szReserve");
		}
	}

	// Searching for face information.
	public static class PU_FACE_INFO_FIND_S extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public PU_FACE_LIB_S.ByValue stFacelib; // Face list.

		public PU_FACE_FIND_CONDITION_S.ByValue stCondition; // Search criteria.

		public int uFindNum; // Number of records in the search result.

		public int uStartIndex; // Start index for the search.

		public byte[] szFindResultPath = new byte[PU_SAVE_FILE_PATH_MAX + 1];// Query result path (a local directory for
																				// the client; a JSON file path for the
																				// device).

		public byte[] szReserve = new byte[PU_RESERVE_LEN];//

		public PU_FACE_INFO_FIND_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stFacelib", "stCondition", "uFindNum", "uStartIndex",
					"szFindResultPath", "szReserve");
		}
	}

	// Modify face information.
	public static class PU_FACE_INFO_MODIFY_S extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public PU_FACE_LIB_S.ByValue stFacelib; // Face list.

		public PU_FACE_RECORD_S.ByValue stRecord; // Result after modification.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_INFO_MODIFY_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stFacelib", "stRecord", "szReserve");
		}
	}

	public static class PU_FACE_LIB_GET_S extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public WinDef.ULONG ulFaceLibNum; // Total number of libraries.

		public byte[] szFindResultPath = new byte[PU_SAVE_FILE_PATH_MAX]; // Query result path (a local directory for
																			// the client; a JSON file path for the
																			// device).

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_LIB_GET_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulFaceLibNum", "szFindResultPath", "szReserve");
		}
	}

	// Importing face images into a face library.
	public static class PU_FACE_LIB_IMPORT_S extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public int enPacketType; // Package type. c type:PU_FACE_PACKET_TYPE

		public PU_FACE_LIB_S.ByValue stFacelib; // Face list.

		public byte[] szPath = new byte[PU_IMPORT_FILE_LEN_MAX]; // File path and name.

		public byte[] szFileName = new byte[PU_IMPORT_FILENAME_LEN_MAX]; // File name.

		public byte[] szImportResult = new byte[PU_IMPORT_FILE_LEN_MAX]; // Path for saving the exported file in CSV
																			// format. This field is not used in
																			// IVS_PU_ImportFaceLibEx.

		public WinDef.ULONG taskID;// Face library import task ID.

		public byte[] szReserve = new byte[PU_RESERVE_LEN]; //

		public PU_FACE_LIB_IMPORT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enPacketType", "stFacelib", "szPath", "szFileName", "szImportResult",
					"taskID", "szReserve");
		}
	}

	// Face list.
	public static class PU_FACE_LIB_S extends Structure {
		public static class ByValue extends PU_FACE_LIB_S implements Structure.ByValue {
		}

		// Face library ID.
		public WinDef.ULONG ulFaceLibID;

		// Face library type.
		public int enLibType;

		// Indicates whether to deploy alert.
		public int isControl;

		// Alert deployment threshold.
		public WinDef.ULONG uiThreshold;

		// Face list name.
		public byte[] szLibName = new byte[PU_MAX_RECORD_LEN_64 + 1];

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_LIB_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulFaceLibID", "enLibType", "isControl", "uiThreshold", "szLibName", "szReserve");
		}
	}

	public static class PU_FACE_LIB_SET_S extends Structure {
		public WinDef.ULONG ulChannelId; // 101

		public int enOptType;// Operation type.

		public PU_FACE_LIB_S.ByValue stFacelib;

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_LIB_SET_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enOptType", "stFacelib", "szReserve");
		}
	}

	// Facial library import and feature extraction status query.
	public static class PU_FACE_LIB_STATUS_S extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public PU_FACE_LIB_S stFacelib; // Face list.

		public WinDef.ULONG taskID; // Face library import and feature extraction task ID.

		public WinDef.BOOL status; // Import and feature extraction status. The options are as follows: 1:
									// finished; 0: not finished.

		public WinDef.ULONG totalPicNum; // Total number of imported files and extracted features.

		public WinDef.ULONG finishPicNum; // Number of successfully imported files and files from which features are
											// successfully extracted.

		public byte[] szResultCsvPath = new byte[PU_IMPORT_FILE_LEN_MAX]; // Path for saving the import and feature
																			// extraction results in CSV format.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_LIB_STATUS_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stFacelib", "taskID", "status", "totalPicNum", "finishPicNum",
					"szResultCsvPath", "szReserve");
		}
	}

	// Face library list type.
	public interface PU_FACE_LIB_TYPE_E {
		int FACE_LIB_DEFAULT = 0;
		int FACE_LIB_BLACK = 1; // Blacklist.
		int FACE_LIB_WHITE = 2; // Whitelist.

		int FACE_LIB_MAX = 3;
	}

	public static class PU_FACE_OSD_INFO extends Structure {
		// Number of OSDs to be superimposed.
		public NativeLong uPicOSDNum;

		// Overlay type.
		// C type : PU_FACE_OSD_TYPE_E[FACE_OSD_TYPE_MAX]
		public int[] aenPicOSDType = new int[PU_FACE_OSD_TYPE_E.FACE_OSD_TYPE_MAX];
		// OSD overlay location.
		// C type : PU_PIC_OSD_LOCATION_E
		public int enPicOSDLocation;
		// Font size.
		// C type : PU_FONT_SIZE_E
		public int enFontSize;
		// Extended OSD font size (new enumerated value); not supported currently.
		// C type : PU_FONT_SIZE_EXT_E
		public int enFontSizeExt;
		// Foreground (text) color format: 0xRRGGBB or converted into decimal.
		public NativeLong ulFgColor;
		// Foreground (text) transparency, ranging from 0 to 128; not supported
		// currently.
		public WinDef.UCHAR ucFgAlpha;
		// Background color format: 0xRRGGBB or converted into decimal.
		public NativeLong ulBgColor;
		// Background transparency, ranging from 0 to 128 (HiSilicon); not supported
		// currently.
		public WinDef.UCHAR ucBgAlpha;

		public PU_FACE_OSD_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uPicOSDNum", "aenPicOSDType", "enPicOSDLocation", "enFontSize", "enFontSizeExt",
					"ulFgColor", "ucFgAlpha", "ulBgColor", "ucBgAlpha");
		}
	}

	public static class PU_FACE_OSD_PARA_S extends Structure {
		// Channel ID.
		public NativeLong ulChannelId;

		// Indicates whether to enable OSD overlay for live video.
		public boolean bEnableLiveOSD;
		/////
		// Type of the image where OSD is to be superimposed.
		///
		public int enOverlayPicType;
		// Image overlay information.
		public PU_FACE_OSD_INFO stPicOSDInfo;
		// Time OSD parameters.
		public PU_TIME_OSD_PARA stTimeOSDPara;
		// Device ID.
		public PU_CUSTOM_OSD_PARA_EX stDevIdOSDPara;
		// Surveillance site position description.
		public PU_CUSTOM_OSD_PARA_EX stMonitorInfoOSDPara;
		public byte[] szReserved = new byte[256];

		public PU_FACE_OSD_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnableLiveOSD", "enOverlayPicType", "stPicOSDInfo", "stTimeOSDPara",
					"stDevIdOSDPara", "stMonitorInfoOSDPara", "szReserved");
		}

	}

	// Face OSD overlay type.
	public interface PU_FACE_OSD_TYPE_E {
		int FACE_TIME_OSD = 0; // Time overlay.
		int FACE_DEV_ID_OSD = 1; // Device ID.
		int FACE_MONITOR_INFO_OSD = 2; // Surveillance site information.
		int FACE_OSD_TYPE_MAX = 3;
	}

	public interface PU_FACE_PACKET_TYPE {
		public static final int FACE_PACKET_TYPE_PICMODE = 0; // Image + personnel information.
		public static final int FACE_PACKET_TYPE_FEATUREMODE = 1; // Facial features only; SDK mode only; must be used
																	// with the platform.
		public static final int FACE_PACKET_TYPE_ALLPACKET = 2; // Entire package (image + personnel information +
																// facial features).
		public static final int FACE_PACKET_TYPE_MAX = 3;
	}

	// Obtaining face images.
	public static class PU_FACE_PIC_GET_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public PU_FACE_LIB_S stFacelib; // Face list.
		public ULONG uFaceID; // Face ID.
		public byte[] szFindResultPath = new byte[PU_SAVE_FILE_PATH_MAX + 1]; // Search result path (SDK server).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_FACE_PIC_GET_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stFacelib", "uFaceID", "szFindResultPath", "szReserve");
		}
	}

	// Face and person detection processing parameters.
	public static class PU_FACE_PROCESS_DL_PARAM_S extends Structure {
		public BOOL bSendFaceImg; // Send face cutout.
		public BOOL bSendBodyImg; // Send person cutout.
		public BOOL bSendPanorama; // Send full image.
		public BOOL bFaceEnhancement; // Image enhancement.
		public ULONG ulFaceImgQuality; // Face image quality (1-10).
		public ULONG ulBodyImgQuality; // Person image quality (1-10).
		public ULONG ulPanoramaImgQuality; // Full image quality (1-10).
		public ULONG ulSendFaceNum; // Number of face images sent.
		public ULONG ulSendBodyNum; // Number of person images sent.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_FACE_PROCESS_DL_PARAM_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bSendFaceImg", "bSendBodyImg", "bSendPanorama", "bFaceEnhancement",
					"ulFaceImgQuality", "ulBodyImgQuality", "ulPanoramaImgQuality", "ulSendFaceNum", "ulSendBodyNum",
					"szReserved");
		}
	}

	public static class PU_FACE_PROCESS_PARAM_S extends Structure {
		public BOOL bSendFaceImg; // Send face cutout.
		public BOOL bSendPanorama; // Send full image.
		public ULONG ulImgQuality; // Snapshot quality, ranging from 1 to 10.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates the number of face images. The
																// value ranges from 1 to 5. The default value is 1.

		// szReserved[1] indicates image enhancement.
		// szReserved[2] indicates the face image quality. The value ranges from 1 to
		// 10. The default value is 10.
		// szReserved[3] indicates the full image quality. The value ranges from 1 to
		// 10. The default value is 5.
		// szReserved[4] indicates whether to enable facial attribute recognition.
		// szReserved[5] indicates whether to enable face detection error filtration.
		// The options are 0 (no) and 1 (yes).
		// szReserved[6] indicates the face detection error filtration sensitivity. The
		// value ranges from 1 to 10. The default value is 5.
		public PU_FACE_PROCESS_PARAM_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bSendFaceImg", "bSendPanorama", "ulImgQuality", "szReserved");
		}
	}

	/**********
	 * end: Micro checkpoint/Object classification parameter modification
	 *****************/

	// Structure for setting anonymous sending of 3559 facial recognition metadata.
	public static class PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		/* C type : PU_ENABLE_TYPE_E */
		public int enAnonymousEnable; // Indicates whether to send metadata in anonymous mode.
		public ULONG ulAlarmTime; // Alarm reporting interval.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enAnonymousEnable", "ulAlarmTime", "szReserved");
		}
	}

	// Facial recognition parameters.
	public static class PU_FACE_RECOGNITION_PARA_S extends Structure {

		public WinDef.BOOL bEnable; // Indicates whether to enable the algorithm.
		public WinDef.ULONG ulChannelId = new WinDef.ULONG(101); // Channel ID.
		public WinDef.ULONG ulAlarmTime; // Alarm reporting interval.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulChannelId", "ulAlarmTime");
		}
	}

	// Face-related information.
	public static class PU_FACE_RECORD_S extends Structure {
		public static class ByValue extends PU_FACE_RECORD_S implements Structure.ByValue {
		}

		public WinDef.ULONG ulFaceId; // Face ID.

		public byte[] szName = new byte[PU_MAX_RECORD_LEN_64]; // Name.

		public int enGender; // Sex.

		public byte[] szBirthday = new byte[PU_MAX_RECORD_LEN_32]; // Date of birth.

		public byte[] szProvince = new byte[PU_MAX_RECORD_LEN_32]; // Province.

		public byte[] szCity = new byte[PU_MAX_RECORD_LEN_48]; // City.

		public int enCardType; // ID type.

		public byte[] szCardID = new byte[PU_MAX_RECORD_LEN_32]; // ID number.

		public byte[] szExtensionField = new byte[PU_MAX_EX_FIELD_LEN]; // Field reserved for face information.

		public byte[] szPicPath = new byte[PU_SAVE_FILE_PATH_MAX]; // Path for uploading images on the client and full
																	// path for storing images on the device, which is
																	// specified on the SDK server.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];// Reserved.

		public PU_FACE_RECORD_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulFaceId", "szName", "enGender", "szBirthday", "szProvince", "szCity", "enCardType",
					"szCardID", "szExtensionField", "szPicPath", "szReserve");
		}
	}

	public interface PU_FACE_SYN_SCALE_TYPE_E {
		int FACE_SYN_SCALE_LAYER1 = 0; // Small.
		int FACE_SYN_SCALE_LAYER2 = 1; // Medium.
		int FACE_SYN_SCALE_LAYER3 = 2; // Large.
		int FACE_SYN_SCALE_MAX = 3;
	}

	public static class PU_FACE_TRACKING_PARAMETER_S extends Structure {
		public BOOL bFilter; // Indicates whether to enable the tracking correction mode (also called
								// detection error filtration).
		public BOOL bCrowded; // Indicates whether to enable the crowd gathering detection mode.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_FACE_TRACKING_PARAMETER_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bFilter", "bCrowded", "szReserved");
		}
	}

	/************* begin: Data structure related to the face library **************/
	// Type of operations on the face library: add, delete, and modify.
	public interface PU_FACELIB_OPERATE_E {
		int FACELIB_ADD = 1;
		int FACELIB_MODIFY = 2;
		int FACELIB_DEL = 3;
		int FACELIB_DEL_ALL = 4;

		int FACELIB_MAX = 5;
	}

	public static class PU_FD_AREA_LIST_S extends Structure {
		public ULONG ulAreaNum;
		public FD_AREA_S[] szAreaList = new FD_AREA_S[FD_AREA_NUM];

		public PU_FD_AREA_LIST_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulAreaNum", "szAreaList");
		}
	}

	public interface PU_FEATURE_STATUS_TYPE_E {
		int FEATURE_STATUS_UNKNOWN = 0; // New face library.
		int FEATURE_STATUS_QUERY_ALL = 1; // Query all.
		int FEATURE_STATUS_REEXTRACT = 2; // Feature re-extraction, triggered upon algorithm upgrade.
		int FEATURE_STATUS_UNEXTRACT = 3; // Not extracted.
		int FEATURE_STATUS_EXTRACTED = 4; // Extracted.
		int FEATURE_STATUS_FAILED = 5; // Extraction failure; used to query face images whose features fail to be
										// extracted.
		int FEATURE_STATUS_ERRIMGSIZE = 6; // The image size does not meet requirements.
		int FEATURE_STATUS_DECODE_FAIL = 7; // Image decoding failure.
		int FEATURE_STATUS_DETECTION_FAIL = 8; // Face detection failure.
		int FEATURE_STATUS_EXTRACT_FAIL = 9; // Feature extraction failure.
		int FEATURE_STATUS_ADD_FEATURE_FAIL = 10; // Failed to write features.
		int FEATURE_STATUS_MAX = 11;
	}

	public interface PU_FEC_PACKET_LOSS_RATIO {
		public static final int PU_FEC_PACKET_LOSS_RATIO_1 = 0;
		/**
		 * < 0: 1% packet loss
		 */
		public static final int PU_FEC_PACKET_LOSS_RATIO_2 = 1;
		/**
		 * < 1: 2% packet loss
		 */
		public static final int PU_FEC_PACKET_LOSS_RATIO_3 = 2;
		/**
		 * < 2: 3% packet loss
		 */
		public static final int PU_FEC_PACKET_LOSS_RATIO_4 = 3;
		/**
		 * < 3: 4% packet loss
		 */
		public static final int PU_FEC_PACKET_LOSS_RATIO_5 = 4;
		/**
		 * < 4: 5% packet loss
		 */
		public static final int PU_FEC_PACKET_LOSS_RATIO_MAX = 5;
	}

	/* Background frequency. */
	public static class PU_FLICKER_MODE_S extends Structure {
		/* C TYPE : PU_VIDEO_FLICKER_MODE_E */
		public int enFlicker; // Background frequency.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enFlicker");
		}
	}

	// Serial port flow control type.
	public interface PU_FLOW_CONTROL {
		public static final int PU_FLOW_CONTROL_NONE = 0;
		public static final int PU_FLOW_CONTROL_SOFT = 1;
		public static final int PU_FLOW_CONTROL_HARD = 2;
		public static final int PU_FLOW_CONTROL_MAX = 3;
	}

	// Infrared focus compensation information.
	public static class PU_FOCUS_COMPENSATION_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable infrared focus compensation.

		public PU_FOCUS_COMPENSATION_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable");
		}
	}

	// Focus mode.
	public interface PU_FOCUS_MODE {
		public static final int PU_FOCUS_MODE_AUTO = 0; // Auto focus.
		public static final int PU_FOCUS_MODE_MANUAL = 1; // Manual focus.
		public static final int PU_FOCUS_MODE_TRIGGER = 2; // Semi-auto focus.
		public static final int PU_FOCUS_MODE_MAX = 3;
	}

	public interface PU_FONT_SIZE_E {
		int PU_OSD_FONT_SIZE_SMALL = 0;
		int PU_OSD_FONT_SIZE_MEDIUM = 1;
		int PU_OSD_FONT_SIZE_LARGE = 2;
		int PU_OSD_FONT_SIZE_MAX = 3;
	}

	public interface PU_FONT_SIZE_EXT_E {
		int PU_OSD_FONT_SIZE_16 = 0;
		int PU_OSD_FONT_SIZE_24 = 1;
		int PU_OSD_FONT_SIZE_32 = 2;
		int PU_OSD_FONT_SIZE_48 = 3;
		int PU_OSD_FONT_SIZE_64 = 4;
		int PU_OSD_FONT_SIZE_96 = 5;
		int PU_OSD_FONT_SIZE_128 = 6;
		int PU_OSD_FONT_SIZE_EXT_MAX = 7;
	}

	// Frame rate.
	public interface PU_FRAME_RATE {
		public static final int PU_FRAME_RATE_30 = 0;
		public static final int PU_FRAME_RATE_50 = 1;
		public static final int PU_FRAME_RATE_60 = 2;
	}

	// Frame scan.
	public class PU_FRAME_SCAN_PARA extends Structure {
		public WinDef.ULONG ulFrameInterval; // Frame interval.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulFrameInterval");
		}
	}

	/* Video collection frame format. */
	public interface PU_FRAMERATE_FORMAT {
		public static final int PU_FRAME_RATE_25F = 1; // 25 fps.
		public static final int PU_FRAME_RATE_30F = 2; // 30 fps.
		public static final int PU_FRAME_RATE_50F = 3; // 50 fps.
		public static final int PU_FRAME_RATE_60F = 4; // 60 fps.
		public static final int PU_FRAME_RATE_MAX = 5;
	}

	/* FTP upload parameters. */
	public static class PU_FTP_FILE_UPLOAD_PARA extends Structure {
		public WinDef.BOOL bSnapPic; // Indicates whether to upload snapshots.
		public int enProtocol; // Upload protocol. c type:PU_FTP_UPLOAD_PROTOCOL_TYPE
		public byte[] szServerIP = new byte[PU_IP4_ADDR_LEN]; // Server IP address.
		public ULONG ulServerPort; // Server port.
		public byte[] szUserName = new byte[PU_CLIENT_USERNAME_LEN]; // User name.
		public byte[] szUserPwd = new byte[PU_PASSWORD_LEN]; // Pwd
		public int enDirType; // Upload directory structure. PU_FTP_UPLOAD_DIR_TYPE
		public int enFirstDirType; // Type of the level-1 upload directory. PU_FTP_UPLOAD_FIRST_DIR_TYPE
		public int enSecondDirType; // Type of the level-2 upload directory. PU_FTP_UPLOAD_SECOND_DIR_TYPE
		public int enFileNamingRule; // Image naming rule. PU_FTP_UPLOAD_FILE_NAMING_RULE
		public byte[] szFirstDir = new byte[PU_FTP_UPLOAD_PATH_LEN]; // Customized level-1 directory name.
		public byte[] szSecondDir = new byte[PU_FTP_UPLOAD_PATH_LEN]; // Customized level-2 directory name.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_FTP_FILE_UPLOAD_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "enProtocol", "szServerIP", "ulServerPort", "szUserName", "szUserPwd",
					"enDirType", "enFirstDirType", "enSecondDirType", "enFileNamingRule", "szFirstDir", "szSecondDir",
					"szReserved");
		}
	}

	// FTP mode, which is different for micro checkpoint and object classification.
	public interface PU_FTP_TYPE_E {
		int PU_VHD_FTP = 0; // Object classification.
		int PU_BAYONET_FTP = 1;// Micro checkpoint.
		int PU_ITS_FTP = 2; // ITS.
		int PU_COMMON_FTP = 3; // Others.
		int PU_IBALL_FTP = 4; // PTZ dome camera that supports parking violation detection.
		int PU_EAST_SOFT_FTP = 5; // Neusoft.
		int PU_HUMANFACE_FTP = 6; // Face.
		int PU_VEHFACEMIX_FTP = 7;// Full intelligence.
		int PU_FTP_TYPE_MAX = 8;
	}

	/* Directory structure. */
	public interface PU_FTP_UPLOAD_DIR_TYPE {
		public static final int PU_FTP_UPLOAD_DIR_TYPE_ROOT_DIR = 0; // Upload to the root directory.
		public static final int PU_FTP_UPLOAD_DIR_TYPE_FIRST_DIR = 1; // Upload to the level-1 directory.
		public static final int PU_FTP_UPLOAD_DIR_TYPE_SECOND_DIR = 2; // Upload to the level-2 directory.
		public static final int PU_FTP_UPLOAD_DIR_TYPE_THIRD_DIR = 3; // Upload to the level-3 directory.
		public static final int PU_FTP_UPLOAD_DIR_TYPE_FOURTH_DIR = 4; // Upload to the level-4 directory.
		public static final int FTP_UPLOAD_DIR_TYPE_MAX = 5;
	}

	/* Image naming rule. */
	public interface PU_FTP_UPLOAD_FILE_NAMING_RULE {
		public static final int PU_FTP_UPLOAD_FILE_NAMING_RULE_DATE = 0; // Named by time.
		public static final int PU_FTP_UPLOAD_FILE_NAMING_RULE_MAX = 1;
	}

	/* Level-1 directory type. */
	public interface PU_FTP_UPLOAD_FIRST_DIR_TYPE {
		public static final int PU_FTP_UPLOAD_FIRST_DIR_TYPE_IP = 0; // The level-1 directory is named by device IP
																		// address.
		public static final int PU_FTP_UPLOAD_FIRST_DIR_TYPE_SELF = 1; // The level-1 directory name is customized.
		public static final int FTP_UPLOAD_FIRST_DIR_TYPE_MAX = 2;
	}

	/* Upload type. */
	public interface PU_FTP_UPLOAD_PROTOCOL_TYPE {
		public static final int PU_FTP_UPLOAD_PROTOCOL_TYPE_FTP = 0;
		public static final int PU_FTP_UPLOAD_PROTOCOL_TYPE_SFTP = 1;
		public static final int FTP_UPLOAD_PROTOCOL_TYPE_MAX = 2;
	}

	/* Level-2 directory type. */
	public interface PU_FTP_UPLOAD_SECOND_DIR_TYPE {
		public static final int PU_FTP_UPLOAD_SECOND_DIR_TYPE_CHANNEL = 0; // The level-2 directory is named by channel
																			// ID.
		public static final int PU_FTP_UPLOAD_SECOND_DIR_TYPE_SELF = 1; // The level-2 directory name is customized.
		public static final int PU_FTP_UPLOAD_SECOND_DIR_TYPE_MAX = 2;
	}

	/* Gain control. */
	public static class PU_GAIN_CONTROL extends Structure {
		public int enGainSwitch; // Indicates whether to enable gain control (enable/disable). c
									// type:PU_COMMONMODE_SWITCH
		public int enGainType; // Gain type. c type:PU_GAIN_TYPE
		public ULONG ulGainValue; // Gain value.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_GAIN_CONTROL() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enBackLightMode", "lBackLight", "enMode", "stAreaInfo", "szReserve");
		}
	}

	/* Gain control. */
	public static class PU_GAIN_CONTROL_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enGainSwitch; // Indicates whether to enable gain control (enable/disable). c
									// type:PU_COMMONMODE_SWITCH
		/* C type : PU_GAIN_TYPE_E */
		public int enGainType; // Gain type. c type:PU_GAIN_TYPE
		public ULONG ulGainValue; // Gain value.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_GAIN_CONTROL_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enGainSwitch", "enGainType", "ulGainValue", "szReserve");
		}
	}

	/* Gain type. */
	public interface PU_GAIN_TYPE {
		public static final int PU_GAIN_TYPE_AUTO = 0; // Automatic gain.
		public static final int PU_GAIN_TYPE_DIGITAL = 1; // Digital gain.
		public static final int PU_GAIN_TYPE_ANALOG = 2; // Analog signal.
		public static final int PU_GAIN_TYPE_MAX = 3;
	}

	/* Gamma parameters. */
	public static class PU_GAMMA_S extends Structure {
		/* C TYPE : PU_COMMONMODE_SWITCH_E */
		public int enGammaMode;
		public NativeLong ulStrength;

		public PU_GAMMA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enGammaMode", "ulStrength");
		}
	}

	// Sex.
	public interface PU_GENDER_E {
		int PU_GENDER_ALL = -1; // All: This field is used only for search.
		int PU_MALE = 0; // Male.
		int PU_FEMALE = 1; // Female.
		int PU_GENDER_UNKNOW = 2; // Unknown.
		int PU_GENDER_MAX = 3;
	}

	/* GPS time calibration parameters. */
	public static class PU_GPS_PARA extends Structure {
		public WinDef.BOOL enGPSEnable; // Indicates whether to enable GPS.
		public ULONG ulInterval; // GPS time synchronization interval.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_GPS_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enGPSEnable", "ulInterval", "szReserved");
		}
	}

	// Alert deployment parameters.
	public static class PU_GUARD_PARA extends Structure {
		public ULONG ulDeviceId; // Device ID. The value 0 indicates all alarm devices.

		public ULONG ulState; // 0: alert deployment; 1: alert withdrawal

		public PU_GUARD_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulDeviceId", "ulState");
		}
	}

	// Park action parameters.
	public static class PU_GUARD_POINT_PARA extends Union {
		public PU_PRESET_SCAN_PARA stPresetPara; // Preset position.
		public PU_CRUISE_SCAN_PARA stCruisePara; // Tour track.
		public PU_USER_DEFINED_SCAN_PARA stUserDefinedPara;// Pattern scan.
		public PU_HORIZONTAL_SCAN_PARA stHorPara; // Horizontal scan.
		public PU_FRAME_SCAN_PARA stFramePara; // Frame scan.
		public PU_RANDOM_SCAN_PARA stRandomPara; // Random scan.
		public PU_PANORAMA_SCAN_PARA stPanoramePara; // Panorama scan.
		public PU_VERTICAL_SCAN_PARA stVerticalPara; // Vertical scan.
//        @Override
//        protected List<String> getFieldOrder()
//        {
//            return Arrays.asList(new String[] {"stPresetPara", "stCruisePara", "stUserDefinedPara", "stHorPara", "stFramePara", "stRandomPara", "stPanoramePara", "stVerticalPara"});
//        }
	}

	/********* Home Position (All) *********/
	public interface PU_GUARD_POINT_TYPE {
		public static final int PU_GUARD_POINT_PRESET = 0; // Preset position.
		public static final int PU_GUARD_POINT_CRUISE = 1; // Tour track.
		public static final int PU_GUARD_POINT_USER_DEFINED = 2; // Pattern scan.
		public static final int PU_GUARD_POINT_HORIZONTAL = 3; // Horizontal scan.
		public static final int PU_GUARD_POINT_FRAME = 4; // Frame scan.
		public static final int PU_GUARD_POINT_RANDOM = 5; // Random scan.
		public static final int PU_GUARD_POINT_PANORAMA = 6; // Panorama scan.
		public static final int PU_GUARD_POINT_VERTICAL = 7; // Vertical scan.
		public static final int PU_GUARD_POINT_MAX = 8;
	}

	// alert deployment
	public static class PU_GUARD_STATE extends Structure {
		public PU_GUARD_PARA[] szChannelStateList = new PU_GUARD_PARA[PU_CAMERA_NUM_MAX]; // Alert deployment status.
																							// The parameter is invalid
																							// when the value of
																							// ulDeviceId is 0.

		public PU_GUARD_PARA[] szInputStateList = new PU_GUARD_PARA[PU_DIO_NUM_MAX]; // Alarm status of the input
																						// device. The parameter is
																						// invalid when the value of
																						// ulDeviceId is 0.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_GUARD_STATE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szChannelStateList", "szInputStateList", "szReserve");
		}
	}

	// H.264 decoding initialization parameter.
	public static class PU_H264_DEC_ATTR extends Structure {
		public int uPictureFormat; // Output image format. The options are 0x00 (YUV420), 0x01 (YUV422), and 0x02
									// (YUV444).
		public int uStreamInType; // Input stream type.
		public int uPicWidthInMB; // Maximum image width that is supported, in MB.
		public int uPicHeightInMB; // Maximum image height that is supported, in MB.
		public int uBufNum; // Maximum number of reference frame buffers.
		public int uWorkMode; // Decoding mode.
		public PU_H264_USERDATA pUserData; // User data.
		public int uReserved; // Reserved.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_H264_DEC_ATTR() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uPictureFormat", "uStreamInType", "uPicWidthInMB", "uPicHeightInMB", "uBufNum",
					"uWorkMode", "pUserData", "uReserved", "szReserved");
		}
	}

	// H.264 frame information.
	public static class PU_H264_DEC_FRAME extends Structure {

		public ByteByReference pY; // Address of the Y component.
		public ByteByReference pU; // Address of the U component.
		public ByteByReference pV; // Address of the V component.
		public int uWidth; // Output image width, in pixels.
		public int uHeight; // Output image height, in pixels.
		public int uYStride; // Stride of the output Y component.
		public int uUVStride; // Stride of the output U/Y component.
		public int uCroppingLeftOffset; // Left cropping offset of the output image, in pixels.
		public int uCroppingRightOffset; // Right cropping offset of the output image, in pixels.
		public int uCroppingTopOffset; // Top cropping offset of the output image, in pixels.
		public int uCroppingBottomOffset;// Bottom cropping offset of the output image, in pixels.
		public int uDpbIdx; // Sequence number of the output image buffer.
		public int uPicFlag; // Output image attribute. The options are as follows: 0: frame; 1: top field;
								// 2: bottom field.
		public int uError; // Indicates whether an error occurs on the output image. The options are as
							// follows: 0: no; 1: yes.
		public int uIntra; // Indicates whether the output image is an IDR frame. The options are as
							// follows: 0: no; 1: yes.
		public long ullPTS; // Timestamp.
		public int uPictureID; // Output image sequence number.
		public int uReserved; // Reserved.
		public PU_H264_USERDATA pUserData; // User data.
		public PU_H264_DEC_OUTPUT_INFO stFrameInfo; // Current frame information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_H264_DEC_FRAME() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("pY", "pU", "pV", "uWidth", "uHeight", "uYStride", "uUVStride", "uCroppingLeftOffset",
					"uCroppingRightOffset", "uCroppingTopOffset", "uCroppingBottomOffset", "uDpbIdx", "uPicFlag",
					"uError", "uIntra", "ullPTS", "uPictureID", "uReserved", "pUserData", "stFrameInfo", "szReserved");
		}
	}

	// H.264 decoding frame information.
	public static class PU_H264_DEC_OUTPUT_INFO extends Structure {
		public int uPicBytes; // Number of bytes in the current frame.
		public int uI4MbNum; // Number of I4x4 macroblocks in the current frame.
		public int uI8MbNum; // Number of I8x8 macroblocks in the current frame.
		public int uI16MbNum; // Number of I16x16 macroblocks in the current frame.
		public int uP16MbNum; // Number of P16x16 macroblocks in the current frame.
		public int uP16x8MbNum; // Number of P16x8 macroblocks in the current frame.
		public int uP8x16MbNum; // Number of P8x16 macroblocks in the current frame.
		public int uP8MbNum; // Number of P8x8 macroblocks in the current frame.
		public int uPskipMbNum; // Number of PSkip macroblocks in the current frame.
		public int uIpcmMbNum; // Number of IPCM macroblocks in the current frame.

		public PU_H264_DEC_OUTPUT_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uPicBytes", "uI4MbNum", "uI8MbNum", "uI16MbNum", "uP16MbNum", "uP16x8MbNum",
					"uP8x16MbNum", "uP8MbNum", "uPskipMbNum", "uIpcmMbNum");
		}
	}

	/* Frame rate or bit rate priority. */
	public interface PU_H264_RC_PRI {
		public static final int PU_H264_RC_FRAMERATE_PRI = 1; // Frame rate priority.
		public static final int PU_H264_RC_BITRATE_PRI = 2; // Stream first.
		public static final int PU_H264_RC_PRI_MAX = 3;
	}

	// User data of H.264 decoding initialization parameters.
	public static class PU_H264_USERDATA extends Structure {
		public int uUserDataType; // User data.
		public int uUserDataSize; // User data length.
		public ByteByReference pData; // User data buffer.
		public Point pNext; // Next segment of user data.

		public PU_H264_USERDATA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uUserDataType", "uUserDataSize", "pData", "pNext");
		}
	}

	// H.265 decoding mode.
	public interface PU_H265D_DECODEMODE {
		public static final int PU_H265D_DECODE = 0; // Normal decoding.
		public static final int PU_H265D_DECODE_END = 1; // Decoding is complete, and the decoder is required to output
															// the remaining images.
	}

	// H.265 decoding type.
	public interface PU_H265D_DECODESTATUS {
		public static final int PU_H265_DEC_GETDISPLAY = 0; // One frame has been decoded and output, and can be used
															// for display.
		public static final int PU_H265_DEC_NEED_MORE_BITS = 1; // The decoder has no image output and requires more
																// streams.
		public static final int PU_H265_DEC_NO_PICTURE = 2; // Decoding is complete. All images have been output.
		public static final int PU_H265_DEC_ERR_HANDLE = 3; // Handle error.
	}

	// H.265 frame type.
	public interface PU_H265D_FRAMETYPE {
		public static final int PU_H265D_FRAME_I = 0; // I-frame.
		public static final int PU_H265D_FRAME_P = 1; // P-frame.
		public static final int PU_H265D_FRAME_B = 2; // B-frame.
		public static final int PU_H265D_FRAME_UNKNOWN = 3;
	}

	// H.265 decoder initialization parameters.
	public static class PU_H265D_INIT_PARAM extends Structure {
		public int uiChannelID; // Channel ID, which is used to identify the channel information.
		public int iMaxWidth; // Maximum width.
		public int iMaxHeight; // Maximum height.
		public int iMaxRefNum; // Maximum number of reference frames.
		public int enThreadType; // Thread type. TODO: Currently, multiple threads are not supported. The
									// partitioning modes of multiple threads, such as by tile, slice, and LCU line,
									// will be added.
		public int enOutputOrder;// Output sequence. TODO: This parameter is valid only for DecodeFrame but not
									// for DecodeAU.
		public PU_H265D_USERDATA pstUserData; // User data.
		public PU_VIDEO_ALG_MALLOC_FXN MallocFxn; // Memory allocation callback.
		public PU_VIDEO_ALG_FREE_FXN FreeFxn; // Memory release callback.
		public PU_VIDEO_ALG_LOG_FXN LogFxn; // Log output callback function.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_H265D_INIT_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiChannelID", "iMaxWidth", "iMaxHeight", "iMaxRefNum", "enThreadType",
					"enOutputOrder", "pstUserData", "MallocFxn", "FreeFxn", "LogFxn");
		}
	}

	// Output sequence.
	public interface PU_H265D_OUTPUTORDER {
		public static final int PU_H265D_DECODE_ORDER = 0; // Output in the decoding sequence.
		public static final int PU_H265D_DISPLAY_ORDER = 1; // Output in the display sequence.
	}

	// Thread type.
	public interface PU_H265D_THREADTYPE {
		public static final int PU_H265D_SINGLE_THREAD = 0; // Single-thread.
		public static final int PU_H265D_MULTI_THREAD = 1; // Multi-thread.
	}

	// User data.
	public static class PU_H265D_USERDATA extends Structure {
		public int uiUserDataType; /* User data type. */
		public int uiUserDataSize; /* User data length. */
		public ByteByReference pucData; /* User data buffer. */
		public Point pNext; /* Point to the next segment of user data. */

		public PU_H265D_USERDATA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiUserDataType", "uiUserDataSize", "pucData", "pNext");
		}
	}

	// H.265 decoding input parameters.
	public static class PU_H265DEC_INARGS extends Structure {
		public ByteByReference pStream; // Address of the frame to be decoded.
		public int uiStreamLen; // Length of the frame to be decoded.
		public long uiTimeStamp; // Timestamp.
		public int enDecodeMode; // Decoding mode.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_H265DEC_INARGS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("pStream", "uiStreamLen", "uiTimeStamp", "enDecodeMode", "szReserved");
		}
	}

	// H.265 decoding output parameters.
	public static class PU_H265DEC_OUTARGS extends Structure {
		public int uiChannelID; // Channel ID.
		public int uiBytsConsumed; // Number of consumed bytes.
		public long uiTimeStamp; // Timestamp.
		public int enFrameType; // Frame type.
		public int enDecodeStatus; // Decoder status.
		public int uiDecWidth; // Image width.
		public int uiDecHeight; // Image height.
		public int uiYStride; // Stride of the Y component.
		public int uiUVStride; // Stride of the U/V component.
		public ByteByReference[] pucOutYUV = new ByteByReference[3]; // YUV address, which is used to store YUV data.
		public int uiCodingBytesOfCurFrm; // Original stream length.
		public PU_H265D_USERDATA stUserData; // User data.
		public int uiAspectRatioIdc; // Aspect ratio information.
		public int uiSarWidth; // Width of the aspect ratio. This parameter is valid only when uiAspectRatioIdc
								// is set to 255.
		public int uiSarHeight; // Height of the aspect ratio. This parameter is valid only when
								// uiAspectRatioIdc is set to 255.
		public int uiVpsNumUnitsInTick; // Frame rate information.
		public int uiVpsTimeScale; // Frame rate information.
		public PU_CU_OUTPUT_INFO stCuOutInfo; // Output the current frame information, including the number of CUs of
												// various types in a frame.
		public int iIsError; // Indicates whether an error occurs on the frame. The options are as follows:
								// 0: no; 1: yes.

		public PU_H265DEC_OUTARGS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiChannelID", "uiBytsConsumed", "uiTimeStamp", "enFrameType", "enDecodeStatus",
					"uiDecWidth", "uiDecHeight", "uiYStride", "uiUVStride", "pucOutYUV", "uiCodingBytesOfCurFrm",
					"stUserData", "uiAspectRatioIdc", "uiSarWidth", "uiSarHeight", "uiVpsNumUnitsInTick",
					"uiVpsTimeScale", "stCuOutInfo", "iIsError");
		}
	}

	/* Disk ID. */
	public static class PU_HARD_DISK extends Structure {
		public ULONG ulDiskId; // Disk ID. The options are as follows: 0: SD card; 1: eMMC.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_HARD_DISK() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulDiskId", "szReserved");
		}
	}

	public static class PU_HARD_DISK_INFO extends Structure {
		public byte[] szHardDiskFac = new byte[FAC_NAME_LEN_MAX];
		public int enHardDiskType; // c type:PU_DISK_TYPE
		public ULONG ulAllSpace;
		public ULONG ulLeftSpace;
		public ULONG ulUsedSpace;
		public ULONG ulUsedPercentage;
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_HARD_DISK_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szHardDiskFac", "enHardDiskType", "ulAllSpace", "ulLeftSpace", "ulUsedSpace",
					"ulUsedPercentage", "szReserved");
		}
	}

	/* Disk information. */
	public static class PU_HARD_DISK_PARA extends Structure {
		public byte[] szDiskFac = new byte[PU_FAC_NAME_LEN];
		public int enDiskType; // c type:PU_DISK_TYPE
		public ULONG ulAllSpace;
		public ULONG ulLeftSpace;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_HARD_DISK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szDiskFac", "enDiskType", "ulAllSpace", "ulLeftSpace", "szReserved");
		}
	}

	/* Disk status. */
	public static class PU_HARD_DISK_STATE extends Structure {
		public ULONG ulDiskThreshold; // Storage space threshold.
		public ULONG ulDiskState; // Disk status. 0: normal.
		public PU_HARD_DISK_INFO stHardDiskInfo; // Disk information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field. szReserved[0] indicates that disk ID.
																// The options are as follows: 0: SD card; 1: eMMC card.

		public PU_HARD_DISK_STATE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulDiskThreshold", "ulDiskState", "stHardDiskInfo", "szReserved");
		}
	}

	// Lens blocking detection alarm parameters.
	public static class PU_HIDE_ALARM_PARA extends Structure {
		public ULONG ulChannel; // Video channel ID.

		public NativeLong lEnable; // Indicates whether to enable lens blocking detection.
		public ULONG ulDeteInterval; // Alarm check interval (1–256s). The system checks the alarm status at a
										// specified interval.
		public ULONG ulSensitivity; // Motion detection sensitivity. The value ranges from 1 to 5. A larger value
									// indicates a higher sensitivity.
		public PU_DETECTION_AREA stDetectionArea; // Alarm detection area.
		public PU_ALARM_TIME_LIST stAlarmTimeList; // Alert deployment time list.

		public PU_HIDE_ALARM_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannel", "lEnable", "ulDeteInterval", "ulSensitivity", "stDetectionArea",
					"stAlarmTimeList");
		}
	}

	// Horizontal scan.
	public class PU_HORIZONTAL_SCAN_PARA extends Structure {
		public WinDef.ULONG ulSpeed; // Speed.
		public int enDirection; // Direction. The value can be left or right.

		public PU_HORIZONTAL_SCAN_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSpeed", "enDirection");
		}
	}

	// Heat map detection area.
	public static class PU_HOTMAP_AERADTC_LIST extends Structure {
		public ULONG ulAreaNum;
		public PU_IGT_AREA[] stArea = (PU_IGT_AREA[]) new PU_IGT_AREA().toArray(PU_HOTMAP_AREA_NUM);

		public PU_HOTMAP_AERADTC_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulAreaNum", "stArea");
		}
	}

	// Heat map alert plan parameters.
	public static class PU_HOTMAP_GUARD_PLAN_PARA_S extends Structure {
		public ULONG ulChannelId; // Channel ID, which is reserved.
		public PU_HOTMAP_TIME_PLAN[] astGuadTime = (PU_HOTMAP_TIME_PLAN[]) new PU_HOTMAP_TIME_PLAN()
				.toArray(PU_DAY_NUM_PER_WEEK); // Weekly alert plan.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_HOTMAP_GUARD_PLAN_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "astGuadTime", "szReserved");
		}
	}

	// Heat map parameter.
	public static class PU_HOTMAP_PARA extends Structure {
		public NativeLong ulChannelId; // Channel ID.
		// C type : PU_ENABLE_TYPE_E
		public int enEnable; // Indicates whether to enable the algorithm.
		// C type : PU_ENABLE_TYPE_E
		public int enSendMeta; // Indicates whether to enable the function of sending metadata. This function
								// is enabled by default.
		public PU_PTZ_CURRENT_LOCATION stPtzPara; // PTZ position.
		public PU_HOTMAP_AERADTC_LIST stAreaList; // Heat map detection area.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_HOTMAP_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enEnable", "enSendMeta", "stPtzPara", "stAreaList", "szReserved");
		}
	}

	public static class PU_HOTMAP_TABLE_PARA extends Structure {
		public static class ByReference extends PU_HOTMAP_TABLE_PARA implements Structure.ByReference {

		}

		public static class ByValue extends PU_HOTMAP_TABLE_PARA implements Structure.ByValue {

		}

		/**
		 * <i>native declaration : include\HWPuSDK.h:50</i>
		 */
		public static class hotMapTable_union extends Union {
			public static class ByReference extends hotMapTable_union implements Structure.ByReference {

			}

			public static class ByValue extends hotMapTable_union implements Structure.ByValue {

			}

			/**
			 * C type is TYPE_HOTMAP_SPACE<br>
			 */
			public PU_HOTMAP_TABLE_SPACE stHotMapSapceTable;

			/**
			 * C tyep is TYPE_HOTMAP_TIME<br>
			 */
			public PU_HOTMAP_TABLE_TIME stHotMapTimeTable;

			public hotMapTable_union() {
				super();
			}

			public hotMapTable_union(Pointer peer) {
				super(peer);
			}

			/**
			 * @param stHotMapSapceTable C type is TYPE_HOTMAP_SPACE<br>
			 *                           C type : PU_HOTMAP_TABLE_SPACE_S
			 */
			public hotMapTable_union(PU_HOTMAP_TABLE_SPACE stHotMapSapceTable) {
				super();
				this.stHotMapSapceTable = stHotMapSapceTable;
				setType(PU_HOTMAP_TABLE_SPACE.class);
			}

			/**
			 * @param stHotMapTimeTable C type is TYPE_HOTMAP_TIME<br>
			 *                          C type : PU_HOTMAP_TABLE_TIME_S
			 */
			public hotMapTable_union(PU_HOTMAP_TABLE_TIME stHotMapTimeTable) {
				super();
				this.stHotMapTimeTable = stHotMapTimeTable;
				setType(PU_HOTMAP_TABLE_TIME.class);
			}
		}

		/**
		 * Channel ID.
		 */
		public NativeLong ulChannelId;
		/**
		 * Query type. C type : PU_HOTMAP_TYPE_E
		 */
		public int enHotmapType;
		/**
		 * Report type. C type : PU_TABLE_TYPE_E
		 */
		public int enTableType;
		/**
		 * Start time (local time). C type : PU_TIME_S
		 */
		public PU_TIME_S stBeginTime;

		/**
		 * Report file storage path, which is defined by the invoker. C type : CHAR[128
		 * + 1]
		 */
		public byte[] szPath = new byte[128 + 1];

		/**
		 * C type : hotMapTable_union
		 */
		public hotMapTable_union hotMapTable;

		/**
		 * C type : CHAR[PU_RESERVE_LEN]
		 */
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_HOTMAP_TABLE_PARA() {
			super();
		}

		public PU_HOTMAP_TABLE_PARA(NativeLong ulChannelId, int enHotmapType, int enTableType, PU_TIME_S stBeginTime,
				byte szPath[], hotMapTable_union hotMapTable, byte szReserved[]) {
			super();
			this.ulChannelId = ulChannelId;
			this.enHotmapType = enHotmapType;
			this.enTableType = enTableType;
			this.stBeginTime = stBeginTime;
			if ((szPath.length != this.szPath.length))
				throw new IllegalArgumentException("Wrong array size !");
			this.szPath = szPath;
			this.hotMapTable = hotMapTable;
			if ((szReserved.length != this.szReserved.length))
				throw new IllegalArgumentException("Wrong array size !");
			this.szReserved = szReserved;
		}

		public PU_HOTMAP_TABLE_PARA(Pointer peer) {
			super(peer);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enHotmapType", "enTableType", "stBeginTime", "szPath", "hotMapTable",
					"szReserved");
		}
	}

	public static class PU_HOTMAP_TABLE_SPACE extends Structure {
		/**
		 * Grayscale image width.
		 */
		public short usWidth;
		/**
		 * Grayscale image height.
		 */
		public short usHeight;

		public PU_HOTMAP_TABLE_SPACE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usWidth", "usHeight");
		}
	}

	public static class PU_HOTMAP_TABLE_TIME extends Structure {
		public static class map_union extends Union {

			public static class ByReference extends map_union implements Structure.ByReference {

			}

			public static class ByValue extends map_union implements Structure.ByValue {

			}

			/**
			 * Annual report return result.
			 */
			public short[] ausHotMapTableYear = new short[12];
			/**
			 * Monthly report return result.
			 */
			public short[] ausHotMapTableMonth = new short[31];

			/**
			 * Weekly report return result.
			 */
			public short[] ausHotMapTableWeek = new short[7];

			/**
			 * Daily report return result.
			 */
			public short[] ausHotMapTableDay = new short[24];

			public map_union() {
				super();
			}

			public map_union(Pointer peer) {
				super(peer);
				this.setAlignType(ALIGN_NONE);
			}

			public map_union(
					short ausHotMapTableYear_or_ausHotMapTableMonth_or_ausHotMapTableWeek_or_ausHotMapTableDay[]) {
				super();
				this.ausHotMapTableDay = this.ausHotMapTableWeek = this.ausHotMapTableMonth = this.ausHotMapTableYear = ausHotMapTableYear_or_ausHotMapTableMonth_or_ausHotMapTableWeek_or_ausHotMapTableDay;
				setType(short[].class);
			}

		}

		/**
		 * Data length.
		 */
		public short usHotMapRecordNum;

		public map_union map;

		public PU_HOTMAP_TABLE_TIME() {
			super();
			this.setAlignType(ALIGN_NONE);
		}

		public PU_HOTMAP_TABLE_TIME(Pointer peer) {
			super(peer);
		}

		public PU_HOTMAP_TABLE_TIME(short usHotMapRecordNum, map_union map) {
			super();
			this.usHotMapRecordNum = usHotMapRecordNum;
			this.map = map;
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usHotMapRecordNum", "map");
		}
	}

	// Heat map alert plan time.
	public static class PU_HOTMAP_TIME_PLAN extends Structure {
		public ULONG ulGuardNum; // Number of alert plans. Maximum value: PU_GUARD_PLAN_NUM_PER_DAY.
		public PU_TIME_PLAN_PER_DAY[] astTimePalnPerDay = (PU_TIME_PLAN_PER_DAY[]) new PU_TIME_PLAN_PER_DAY()
				.toArray(PU_GUARD_PLAN_NUM_PER_DAY); // Time period of a daily alert plan.

		public PU_HOTMAP_TIME_PLAN() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulGuardNum", "astTimePalnPerDay");
		}
	}

	public static class PU_HUMANCOUNT_TABLE extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public int enTableType; // Report type.
		public int enInDir; // Entering direction. (The clockwise direction is regarded as enter, and the
							// counterclockwise direction is regarded as exit.)
		public WinDef.ULONG ulRecordNum; // Number of records to query.
		public PU_HUMANCOUT_RECORD[] astTable = (PU_HUMANCOUT_RECORD[]) new PU_HUMANCOUT_RECORD().toArray(32); // Table
																												// displaying
																												// the
																												// head
																												// count
																												// statistics
																												// in
																												// each
																												// time
																												// segment.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_HUMANCOUNT_TABLE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enTableType", "enInDir", "ulRecordNum", "astTable", "szReserved");
		}
	}

	/******************
	 * Head counting report structure
	 ************************************/
	public static class PU_HUMANCOUNT_TABLE_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		// C type : PU_TABLE_TYPE_E
		public int enTableType; // Report type.
		// C type : PU_TRIPWIRE_DIR_E
		public int enInDir; // Entering direction. (The clockwise direction is regarded as enter, and the
							// counterclockwise direction is regarded as exit.)
		public ULONG ulRecordNum; // Number of records to query.
		public PU_HUMANCOUT_RECORD[] astTable = new PU_HUMANCOUT_RECORD[PU_HUMANCOUNT_TABLE_LEN_MAX]; // Table
																										// displaying
																										// the head
																										// count
																										// statistics in
																										// each time
																										// segment.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_HUMANCOUNT_TABLE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enTableType", "enInDir", "ulRecordNum", "astTable", "szReserved");
		}
	}

	/******************
	 * Head counting message structure
	 ************************************/
	public static class PU_HUMANCOUT_RECORD extends Structure {
		public ULONG ulStartTime; // Query start time.
		public ULONG ulEndTime; // Query end time.
		public ULONG HumanNum; // Head count.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_HUMANCOUT_RECORD() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartTime", "ulEndTime", "HumanNum", "szReserved");
		}
	}

	/* Pedestrian and vehicle separation structure. */
	public static class PU_HV_ALARM_PARA_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable the ROI.

		public PU_HV_ALARM_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable");
		}
	}

	/************* Begin: Traffic PTZ dome camera **************/
//Snapshot type.
	public interface PU_IBALL_FRAME_TYPE_E {
		int PU_IBALL_FRAME_TYPE_FAR = 0; // Distant image.
		int PU_IBALL_FRAME_TYPE_NEAR = 1; // Close-up image.
		int PU_IBALL_FRAME_TYPE_FEATURE = 2; // Feature image.
		int PU_IBALL_FRAME_TYPE_MAX = 3;
	}

	public static class PU_IGT_AERADTC_LIST_S extends Structure {
		public ULONG ulAreaNum;
		public PU_IGT_AREA[] stArea = (PU_IGT_AREA[]) new PU_IGT_AREA().toArray(PU_IGT_AREA_NUM);

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulAreaNum", "stArea");
		}
	}

	public static class PU_IGT_AEREDTC_ALARM_PARA extends Structure {
		public ULONG ulChannelId;
		public BOOL bEnable;
		public ULONG ulAlarmInterval; // Alarm check interval.
		/* C type : PU_IGT_TARGET_MODE */
		public int enTargetDetecMode; // Object recognition mode.
		public ULONG ulRemainTime; // Dwell time.
		public PU_IGT_AERADTC_LIST_S stAreaDtcList; // Area list: When you obtain the area list, the coordinates of all
													// areas are returned. If the area coordinates are 0, the area is
													// out of the camera's surveillance range (an index is returned).
		// This parameter is optional. If ulAreaNum is not set to 0, all areas are
		// delivered. If ulAreaNum is set to 0, no area is delivered.
		public PU_ALARM_TIME_LIST_S stAreaGuardPlan; // Alert plan.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_IGT_AEREDTC_ALARM_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "ulAlarmInterval", "enTargetDetecMode", "ulRemainTime",
					"stAreaDtcList", "stAreaGuardPlan", "szReserved");
		}
	}

	public static class PU_IGT_ALARM_PARA extends Structure {
		public ULONG ulChannelId;
		public BOOL bIgtEnable; // Indicates whether to enable intelligent analysis.
		public BOOL bTrackEnable; // Indicates whether to enable object tracking.
		/* C type : PU_IGT_OPT_TYPE */
		public int enFieldType; // Scene type.
		/* C type : PU_IGT_OPT_TYPE */
		public int enMinTargetSize;// Minimum size of the foreground object.
		/* C type : PU_IGT_OPT_TYPE */
		public int enShadowMode; // Shadow removal mode.
		/* C type : PU_IGT_OPT_TYPE */
		public int enDetectSens; // Object detection sensitivity.
		public BOOL bInsensitiveObject; // Indicates whether to display insensitive object information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] 表示最小目标尺寸宽(5~200且小于最大尺寸)

		// szReserved[1] indicates the minimum object height (5–200 pixels and smaller
		// than the maximum height).
		// szReserved[2] indicates the maximum object width (5–200 pixels).
		// szReserved[3] indicates the maximum object height (5–200 pixels).
		// szReserved[4] indicates the background update rate.
		// szReserved[5] indicates the maximum number of objects.
		public PU_IGT_ALARM_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bIgtEnable", "bTrackEnable", "enFieldType", "enMinTargetSize",
					"enShadowMode", "enDetectSens", "bInsensitiveObject", "szReserved");
		}
	}

	/* Area-based detection. */
	public static class PU_IGT_AREA extends Structure {
		public int uPointNum; /* Number of vertexes in a polygon. */
		public PU_IGT_POINT_S[] stPoint = new PU_IGT_POINT_S[PU_IGT_AREA_POINTS_NUM]; /* Point coordinates. */
		public ULONG ulAreaIndex; /* Area index. */
		public WinDef.BOOL bEnable; /* Indicates whether to enable the detection area. */
		public byte[] szAreaName = new byte[PU_IGT_AREA_NAME_LEN]; /* Area name. */
		public PU_PTZ_CURRENT_LOCATION stLocation; /* PTZ location information. */

		public PU_IGT_AREA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uPointNum", "stPoint", "ulAreaIndex", "bEnable", "szAreaName", "stLocation");
		}
	}

	/* Intelligent area-based detection type. */
	public interface PU_IGT_AREA_ALARM_TYPE {
		public static final int PU_IGT_TYPE_INTRUSION = 0; // Intrusion detection.
		public static final int PU_IGT_TYPE_HOVER = 1; // Loitering detection.
		public static final int PU_IGT_TYPE_LEGACY = 2; // Abandoned object detection.
		public static final int PU_IGT_TYPE_REMOVE = 3; // Removed object detection.
		public static final int PU_IGT_TYPE_ENTER = 4; // Area entry detection.
		public static final int PU_IGT_TYPE_EXIT = 5; // Area exit detection.
		public static final int PU_IGT_TYPE_FASTMOVE = 6; // Fast movement detection.
		public static final int PU_IGT_TYPE_MAX = 7;
	}

	public static class PU_IGT_AREA_ITEM extends Structure {
		public ULONG ulChannelId;
		/* C type : PU_IGT_AREA_ALARM_TYPE */
		public int enAlarmAeraType;
		/* C type : PU_IGT_OPT_TYPE */
		public int enOptType;
		public PU_IGT_AREA stIgtArea;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_IGT_AREA_ITEM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enAlarmAeraType", "enOptType", "stIgtArea", "szReserved");
		}
	}

	/* Background update rate. */
	public interface PU_IGT_BG_UPDATE {
		public static final int PU_BGUPDATE_LOW = 0;
		public static final int PU_BGUPDATE_MID = 1;
		public static final int PU_BGUPDATE_HIGH = 2;
		public static final int PU_BGUPDATE_MAX = 3;
	}

	// Intelligent data packaging format.
	public interface PU_IGT_DATA_TYPE {
		public static final int XML_TYPE = 0;
		public static final int META_TYPE = 1;
	}

	/* Sensitivity. */
	public interface PU_IGT_DETECT_SENS {
		public static final int PU_IGT_SENS_LOW = 0; // Low sensitivity.
		public static final int PU_IGT_SENS_MIDDLE = 1; // Medium sensitivity.
		public static final int PU_IGT_SENS_HIGH = 2; // High sensitivity.
		public static final int PU_IGT_SENS_LOWER = 3; // Lower sensitivity.
		public static final int PU_IGT_SENS_LOWEST = 4; // Lowest sensitivity.
		public static final int PU_IGT_SENS_MAX = 5;
	}

	/* Intelligent detection scene. */
	public interface PU_IGT_FIELD_TYPE {
		public static final int PU_IGT_FIELD_LONGSHOT = 0; // Distant object.
		public static final int PU_IGT_FIELD_CLOSESHOT = 1; // Close-up object.
		public static final int PU_IGT_FIELD_MAX = 2;
	}

	/* Foreground object size. */
	public interface PU_IGT_MINTARGET_SIZE {
		public static final int PU_IGT_TARGETSIZE_SMALL = 0; // Small object.
		public static final int PU_IGT_TARGETSIZE_MIDDLE = 1; // Medium object.
		public static final int PU_IGT_TARGETSIZE_BIG = 2; // Large object.
		public static final int PU_IGT_TARGETSIZE_MAX = 3;
	}

	public interface PU_IGT_OBJ_TRACK {
		public static final int PU_OBJTRACK_LOW = 0;
		public static final int PU_OBJTRACK_MID = 1;
		public static final int PU_OBJTRACK_HIGH = 2;
		public static final int PU_OBJTRACK_MAX = 3;
	}

	public interface PU_IGT_OPT_TYPE {
		public static final int PU_IGT_OPT_TYPE_ADD = 0; // New: All information containing LPPU_IGT_TW_LINE_S or
															// LPPU_IGT_AREA_S
		public static final int PU_IGT_OPT_TYPE_MOD = 1; // Modified: All information containing LPPU_IGT_TW_LINE_S or
															// LPPU_IGT_AREA_S
		public static final int PU_IGT_OPT_TYPE_DEL = 2; // Deleted: Only the channelid and index with
															// LPPU_IGT_TW_LINE_S or LPPU_IGT_AREA_S
		public static final int PU_IGT_OPT_TYPE_MOV = 3; /*
															 * Move to the view when you want to add a tripwire or area.
															 * Only the channelid and index with LPPU_IGT_TW_LINE_S or
															 * LPPU_IGT_AREA_S
															 */
		/*
		 * The tripwire or coordinate information will be returned as an output
		 * parameter.
		 */
		public static final int PU_IGT_OPT_TYPE_MAX = 4;
	}

	public static class PU_IGT_POINT_S extends Structure {
		public short usPointPosX; /* X coordinate of the point (0-352). */

		public short usPointPosY; /* Y coordinate of the point (0-288). */

		public PU_IGT_POINT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usPointPosX", "usPointPosY");
		}
	}

	/* Shadow removal mode. */
	public interface PU_IGT_SHADOW_MODE {
		public static final int PU_IGT_SHADOW_WEAK = 0; // Weak shadow.
		public static final int PU_IGT_SHADOW_COMMON = 1; // Common shadow.
		public static final int PU_IGT_SHADOW_STRONG = 2; // Strong shadow.
		public static final int PU_IGT_SHADOW_MAX = 3;
	}

	/* Intelligent object recognition mode. */
	public interface PU_IGT_TARGET_MODE_E {
		public static final int PU_IGT_TARGETMODE_CENTRE = 0; // Center.
		public static final int PU_IGT_TARGETMODE_BOTTOM = 1; // Bottom.
		public static final int PU_IGT_TARGETMODE_TOP = 2; // Top.
		public static final int PU_IGT_TARGETMODE_MAX = 3;
	}

	public static class PU_IGT_TW_LINE extends Structure {
		public WinDef.UCHAR ucDirection; /*
											 * Detection direction. 0: both; 1: from left to right; 2: from right to
											 * left.
											 */

		public PU_IGT_POINT_S stStartPoit; /* Start point of a tripwire. */
		public PU_IGT_POINT_S stEndPoit; /* End point of a tripwire. */
		public NativeLong ulLineIndex; /* Tripwire index. */
		public WinDef.BOOL bEnable; /* Indicates whether to enable the tripwire. */
		public byte[] szLineName = new byte[PU_IGT_LINE_NAME_LEN]; /* Tripwire name. */

		public PU_IGT_TW_LINE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ucDirection", "stStartPoit", "stEndPoit", "ulLineIndex", "bEnable", "szLineName");
		}

	}

	public static class PU_IGT_TW_LINE_ITEM extends Structure {
		public ULONG ulChannelId;
		/* C type : PU_IGT_OPT_TYPE */
		public int enOptType;
		public PU_IGT_TW_LINE stIgtTwLine;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_IGT_TW_LINE_ITEM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enOptType", "stIgtTwLine", "szReserved");
		}
	}

	public static class PU_IGT_TW_LINE_LIST extends Structure {
		public NativeLong ulLineNum;

		public PU_IGT_TW_LINE[] szTWLineList = new PU_IGT_TW_LINE[PU_TRIPWIRE_LEN_NUM_MAX];

		public PU_IGT_TW_LINE_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulLineNum", "szTWLineList");
		}
	}

	public static class PU_IGT_TW_LINE_LIST_S extends Structure {
		public ULONG ulLineNum;
		public PU_IGT_TW_LINE[] szTWLineList = new PU_IGT_TW_LINE[PU_TRIPWIRE_LEN_NUM_MAX];

		public PU_IGT_TW_LINE_LIST_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulLineNum", "szTWLineList");
		}
	}

	// Image information.
	public static class PU_IMAGE_INFO_LIST_S extends Structure {
		public static class ByReference extends PU_IMAGE_INFO_LIST_S implements Structure.ByReference {
		}

		public static class ByValue extends PU_IMAGE_INFO_LIST_S implements Structure.ByValue {
		}

		public WinDef.ULONG ulSnapTime; // Snapshot time.

		public WinDef.ULONG ulContentSize; // Image size.

		public byte[] szContentID = new byte[PU_SNAPSHOT_PICTURE_NAME_LEN]; // Image name.

		public PU_ASSOCIATE_RECORD_INFO_S stRecordInfo; // Associated recording information (valid only for ePolice
														// devices when a violation type is specified by
														// IVS_PU_GetITSSnapshotPicList).

		public byte[] szReserve = new byte[PU_RESERVE_LEN - 12];

		public PU_IMAGE_INFO_LIST_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSnapTime", "ulContentSize", "szContentID", "stRecordInfo", "szReserve");
		}
	}

	/* DRC settings. */
	public static class PU_IMG_DRC extends Structure {
		public int enDRC; // c type:PU_COMMONMODE_SWITCH
		public ULONG ulDRCStrength; // HiSilicon: 0–255; TI: 0–255.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IMG_DRC() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDRC", "ulDRCStrength", "szReserve");
		}
	}

	/* DRC settings. */
	public static class PU_IMG_DRC_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enDRC;
		public ULONG ulDRCStrength; // HiSilicon: 0–255; TI: 0–255.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IMG_DRC_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDRC", "ulDRCStrength", "szReserve");
		}
	}

	// Lane line parameters.
	public static class PU_IMRS_LINE extends Structure {
		public PU_IGT_POINT_S stStartPoint;
		public PU_IGT_POINT_S stEndPoint;

		public PU_IMRS_LINE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stStartPoint", "stEndPoint");
		}
	}

	public static class PU_IMRS_LINE_S extends Structure {
		public PU_IGT_POINT_S stStartPoint = new PU_IGT_POINT_S();
		public PU_IGT_POINT_S stEndPoint = new PU_IGT_POINT_S();

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stStartPoint", "stEndPoint");
		}
	}

	// Boolean value (input) alarm parameters.
	public static class PU_INPUT_ALARM_PARA extends Structure {
		public ULONG ulDeviceId; // Alarm device ID.

		public byte[] szName = new byte[PU_DIO_NAME_LEN]; // Alarm device name.
		public NativeLong lEnable; // Indicates whether to enable the ROI.
		public ULONG ulType; // Boolean value output status. The options are as follows: 0: normally open; 1:
								// normally close.
		public ULONG ulDeteInterval; // Alarm check interval (1–256s). The system checks the alarm status at a
										// specified interval.
		public PU_ALARM_TIME_LIST stAlarmTimeList;

		public PU_INPUT_ALARM_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulDeviceId", "szName", "lEnable", "ulType", "ulDeteInterval", "stAlarmTimeList");
		}
	}

	// New interface type used by public interface functions.
	public interface PU_INTERFACE_TYPE {
		public static final int PU_ITF_TYPE_SIM_PHONE_NUM = 1; // SIM mobile number.
		public static final int PU_ITF_TYPE_MAX = 2; // Reserved.
	}

	// Vehicle detector information.
	public static class PU_IO_DETECTOR_INFO_S extends Structure {
		public BOOL uiIOEnable; // Indicates whether to enable the external device.
		public ULONG uiIOLaneId; // ID of the lane covered by the external device. The value 1 indicates that
									// detection for lane 1 is enabled, and the rest may be deduced by analogy.
		public PU_ITS_IO_DETECTOR_INFO_S stCfgIODetector; // Loop vehicle detector.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IO_DETECTOR_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiIOEnable", "uiIOLaneId", "stCfgIODetector", "szReserve");
		}
	}

	// IP address filtering policy.
	public interface PU_IP_FILTER_STRATEGY {
		public static final int PU_IP_FILTER_STRATEGY_ALLOW = 0; // Whitelist mode.
		public static final int PU_IP_FILTER_STRATEGY_DENY = 1; // Whitelist mode.
		public static final int PU_IP_FILTER_STRATEGY_MAX = 2;
	}

	// IP address filtering protocol.
	public interface PU_IP_PROTOCOL_TYPE {
		public static final int PU_IP_PROTOCOL_TYPE_UDP = 0; // UDP.
		public static final int PU_IP_PROTOCOL_TYPE_TCP = 1; // TCP.
		public static final int PU_IP_PROTOCOL_TYPE_ICMP = 2; // ICMP.
		public static final int PU_IP_PROTOCOL_TYPE_ALL = 3; // All protocols.
		public static final int PU_IP_PROTOCOL_TYPE_MAX = 4;
	}

	public static class PU_IPCA_RULES extends Structure {
		public WinDef.BOOL bEnable;

		public ULONG ulPeriod; // Period.
		public WinDef.USHORT usSrcPort; // Source port.
		public WinDef.USHORT usDstPort; // Destination port.
		public byte[] szSrcIP = new byte[PU_IP4_ADDR_LEN]; // Source IP address.
		public byte[] szDstIP = new byte[PU_IP4_ADDR_LEN]; // Destination IP address.
		public int enProtocolType; // Protocol type.
		public ULONG ulInstanceId; // Unique ID of a quintuple rule.
		public byte[] szMcpIp = new byte[PU_IP4_ADDR_LEN]; // MAC
		public byte[] szDcpIp = new byte[PU_IP4_ADDR_LEN]; // DCP
		public ULONG ulTlpId; // TLP
		public ULONG ulMcpPort; // MCP PORT
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IPCA_RULES() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulPeriod", "usSrcPort", "usDstPort", "szSrcIP", "szDstIP",
					"enProtocolType", "ulInstanceId", "szMcpIp", "szDcpIp", "ulTlpId", "ulMcpPort", "szReserve");
		}
	}

	// IP filtering mode.
	public interface PU_IPFILTER_MATCH_TYPE {
		public static final int MATCH_IP = 0; // Filters packets based on IP addresses.
		public static final int MATCH_MAC = 1; // Filters packets based on MAC addresses.
		public static final int MATCH_IP_AND_MAC = 2; // Filters packets based on IP and MAC addresses.
	}

	// Data packet filtering rules.
	public static class PU_IPFILTER_RULES extends Structure {
		public byte[] szIPAddress = new byte[PU_IP4_ADDR_LEN]; // IP address by which data packets are to be filtered
																// out.

		public byte[] szSubNetAddress = new byte[PU_IP4_ADDR_LEN]; // Subnet mask by which data packets are to be
																	// filtered out.
		public NativeLong ulIpBeginPort; // Start port by which data packets are to be filtered out.
		public NativeLong ulIpEndPort; // End port by which data packets are to be filtered out.
		public int enProtocolType; // Protocol by which data packets are to be filtered out.
		public WinDef.BOOL bStatus; // Data packet filtering rule status, effective or not effective.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IPFILTER_RULES() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szIPAddress", "szSubNetAddress", "ulIpBeginPort", "ulIpEndPort", "enProtocolType",
					"bStatus", "szReserve");
		}
	}

	// IP address filtering.
	public static class PU_IPFILTER_RULES_INFO extends Structure {
		public WinDef.BOOL bIpFilterEnable; // Indicates whether to enable IP address filtering.

		public int enIpFilterStrategy; // IP address filtering policy: whitelist or blacklist. c
										// type:PU_IP_FILTER_STRATEGY
		public NativeLong ulIpFilterRulesNum; // IP address filtering rule item.
		public PU_IPFILTER_RULES[] stIpFilterRulesList = new PU_IPFILTER_RULES[PU_IP_FILTER_NUM_MAX]; // IP address
																										// filtering
																										// rule list.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IPFILTER_RULES_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bIpFilterEnable", "enIpFilterStrategy", "ulIpFilterRulesNum", "stIpFilterRulesList",
					"szReserve");
		}
	}

	// IP address filtering.
	public static class PU_IPFILTER_RULES_INFOV2 extends Structure {
		public WinDef.BOOL bIpFilterEnable; // Indicates whether to enable IP address filtering.

		public int enIpFilterStrategy; // IP address filtering policy: whitelist or blacklist. c
										// type:PU_IP_FILTER_STRATEGY
		public ULONG ulIpFilterRulesNum; // IP address filtering rule item.
		public PU_IPFILTER_RULESV2[] stIpFilterRulesList = new PU_IPFILTER_RULESV2[PU_IP_FILTER_NUM_MAXV2]; // IP
																											// address
																											// filtering
																											// rule
																											// list.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IPFILTER_RULES_INFOV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bIpFilterEnable", "enIpFilterStrategy", "ulIpFilterRulesNum", "stIpFilterRulesList",
					"szReserve");
		}
	}

	// IP address filtering.
	public static class PU_IPFILTER_RULES_INFOV2_S extends Structure {
		public BOOL bIpFilterEnable; // Indicates whether to enable IP address filtering.
		/* C type : PU_IP_FILTER_STRATEGY */
		public int enIpFilterStrategy; // IP address filtering policy: whitelist or blacklist.
		public ULONG ulIpFilterRulesNum; // IP address filtering rule item.
		public PU_IPFILTER_RULESV2_S[] stIpFilterRulesList = new PU_IPFILTER_RULESV2_S[PU_IP_FILTER_NUM_MAXV2]; // IP
																												// address
																												// filtering
																												// rule
																												// list.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IPFILTER_RULES_INFOV2_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bIpFilterEnable", "enIpFilterStrategy", "ulIpFilterRulesNum", "stIpFilterRulesList",
					"szReserve");
		}
	}

	public static class PU_IPFILTER_RULES_INFOV3_S extends Structure {
		public WinDef.BOOL bIpFilterEnable; // Indicates whether to enable IP address filtering.

		public int enIpFilterStrategy; // IP address filtering policy: whitelist or blacklist. c
										// type:PU_IP_FILTER_STRATEGY
		public NativeLong ulIpFilterRulesNum; // IP address filtering rule item.
		public PU_IPFILTER_RULESV2[] stIpFilterRulesList = new PU_IPFILTER_RULESV2[PU_IP_FILTER_NUM_MAXV3]; // IP
																											// address
																											// filtering
																											// rule
																											// list.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IPFILTER_RULES_INFOV3_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bIpFilterEnable", "enIpFilterStrategy", "ulIpFilterRulesNum", "stIpFilterRulesList",
					"szReserve");
		}
	}

	// Data packet filtering rules.
	public static class PU_IPFILTER_RULESV2 extends Structure {
		public int enMatchType; // 匹配方式 C type:PU_IPFILTER_MATCH_TYPE

		public byte[] szIPAddress = new byte[PU_IP4_ADDR_LEN]; // IP address by which data packets are to be filtered
																// out.
		public byte[] szSubNetAddress = new byte[PU_IP4_ADDR_LEN]; // Subnet mask by which data packets are to be
																	// filtered out.
		public NativeLong ulIpBeginPort; // Start port by which data packets are to be filtered out.
		public NativeLong ulIpEndPort; // End port by which data packets are to be filtered out.
		public int enProtocolType; // Protocol by which data packets are to be filtered out.
		public byte[] szMACAddress = new byte[PU_HEX_MAC_ADDR_LEN + 1]; // MAC address by which data packets are to be
																		// filtered out.
		public WinDef.BOOL bStatus; // Data packet filtering rule status, effective or not effective.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // szReserve[0] indicates the applied network adapter. The
															// value 0 indicates network adapter 1. The value 1
															// indicates network adapter 2. The rest can be deducted by
															// analogy.
		// 64: Applies to all network adapters.

		public PU_IPFILTER_RULESV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enMatchType", "szIPAddress", "szSubNetAddress", "ulIpBeginPort", "ulIpEndPort",
					"enProtocolType", "szMACAddress", "bStatus", "szReserve");
		}
	}

	// Data packet filtering rules.
	public static class PU_IPFILTER_RULESV2_S extends Structure {
		/* C type : PU_IPFILTER_MATCH_TYPE_E */
		public int enMatchType; // Matching mode. c type:PU_IPFILTER_MATCH_TYPE
		public byte[] szIPAddress = new byte[PU_IP4_ADDR_LEN]; // IP address by which data packets are to be filtered
																// out.
		public byte[] szSubNetAddress = new byte[PU_IP4_ADDR_LEN]; // Subnet mask by which data packets are to be
																	// filtered out.
		public ULONG ulIpBeginPort; // Start port by which data packets are to be filtered out.
		public ULONG ulIpEndPort; // End port by which data packets are to be filtered out.
		/* C type : PU_IP_PROTOCOL_TYPE */
		public int enProtocolType; // Protocol by which data packets are to be filtered out.
		public byte[] szMACAddress = new byte[PU_HEX_MAC_ADDR_LEN + 1]; // MAC address by which data packets are to be
																		// filtered out.
		public BOOL bStatus; // Data packet filtering rule status, effective or not effective.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // szReserve[0] indicates the applied network adapter. The
															// value 0 indicates network adapter 1. The value 1
															// indicates network adapter 2. The rest can be deducted by
															// analogy.

		// 64: Applies to all network adapters.
		public PU_IPFILTER_RULESV2_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enMatchType", "szIPAddress", "szSubNetAddress", "ulIpBeginPort", "ulIpEndPort",
					"enProtocolType", "szMACAddress", "bStatus", "szReserve");
		}
	}

	/*************
	 * End: Parameters for uploading images captured by micro checkpoint cameras
	 * through FTP or SFTP
	 ***************/

	/* Image algorithm type. */
	public interface PU_IPS_ALGORITHM_TYPE_E {
		int ISP_ALG_TYPE_ADPAT = 0; // Scene adaptation algorithm.
		int ISP_ALG_TYPE_MAX_EX = 1;
	}

	/* Day/Night mode. */
	public interface PU_IRC_MODE {
		public static final int PU_IRC_MODE_COLOR = 0; // Color mode.
		public static final int PU_IRC_MODE_GRAY = 1; // B/W mode.
		public static final int PU_IRC_MODE_AUTO = 2; // Auto mode.
		public static final int PU_IRC_MODE_MAX = 3;
	}

	/* IRC parameters. */
	public static class PU_IRC_PARA extends Structure {
		public int enIRCMode; // Day/Night mode. c type:PU_IRC_MODE
		public ULONG ulDayToNightThreshold; // Color-to-B/W sensitivity.
		public ULONG ulNightToDayThreshold; // B/W-to-Color sensitivity.
		public ULONG ulSwitchLevel; // Switch to B/W triggered by external alarms. The options are as follows: 0:
									// low level; 1: high level. c type:PU_IRC_TRIGGER_MODE
		public int enIRCutSwitchMode; // Day/Night trigger mode. The default value is IRC_LUM_TRIGGER.
		public int enPolarzerMode; // Indicated whether to enable the polarizer. c type:PU_COMMONMODE_SWITCH
		public byte[] szReserve = new byte[PU_RESERVE_LEN - 4];

		public PU_IRC_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enBackLightMode", "lBackLight", "enMode", "stAreaInfo", "szReserve");
		}
	}

	/* IRC parameters. */
	public static class PU_IRC_PARA_S extends Structure {
		/* C type : PU_IRC_MODE_E */
		public int enIRCMode; // Day/Night mode. c type:PU_IRC_MODE
		public ULONG ulDayToNightThreshold; // Color-to-B/W sensitivity.
		public ULONG ulNightToDayThreshold; // B/W-to-Color sensitivity.
		public ULONG ulSwitchLevel; // Switch to B/W triggered by external alarms. The options are as follows: 0:
									// low level; 1: high level. c type:PU_IRC_TRIGGER_MODE
		/* C type : PU_IRC_TRIGGER_MODE_E */
		public int enIRCutSwitchMode; // Day/Night trigger mode. The default value is IRC_LUM_TRIGGER.
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enPolarzerMode; // Indicated whether to enable the polarizer. c type:PU_COMMONMODE_SWITCH
		public byte[] szReserve = new byte[PU_RESERVE_LEN - 4];

		public PU_IRC_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enIRCMode", "ulDayToNightThreshold", "ulNightToDayThreshold", "ulSwitchLevel",
					"enIRCutSwitchMode", "enPolarzerMode", "szReserve");
		}
	}

	/* Day/Night mode triggers. */
	public interface PU_IRC_TRIGGER_MODE {
		public static final int PU_IRC_CAM_TRIGGER = 0; // Triggered by chip.
		public static final int PU_IRC_LUM_TRIGGER = 1; // Triggered by photosensitive sensor, which is the default
														// trigger mode.
		public static final int PU_IRC_SWITCH_TRIGGER = 2; // Triggered by external alarms.
		public static final int PU_IRC_TRIGGER_MAX = 3;
	}

	/* Iris control. */
	public static class PU_IRIS_CONTROL extends Structure {
		public int enIris; // Iris control (DC iris). c type:PU_COMMONMODE_SWITCH
		public int enIRISValue; // Aperture value (P-iris). c type:PU_IRIS_VALUE
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_IRIS_CONTROL() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enIris", "enIRISValue", "szReserve");
		}
	}

	/* Iris control. */
	public static class PU_IRIS_CONTROL_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enIris; // Iris control (DC iris). c type:PU_COMMONMODE_SWITCH
		/* C type : PU_IRIS_VALUE_E */
		public int enIRISValue; // Aperture value (P-iris). c type:PU_IRIS_VALUE
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enIris", "enIRISValue", "szReserve");
		}
	}

	// Iris correction structure.
	public static class PU_IRIS_EMENDATION extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int enLanguageType; // Language type. c type:PU_LANGUAGE_TYPE
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_IRIS_EMENDATION() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enLanguageType", "szReserved");
		}
	}

	public interface PU_IRIS_TYPE {
		public static final int PU_IRIS_TYPE_DC = 0; // DC iris.
		public static final int PU_IRIS_TYPE_P_IRIS = 1; // P-iris.
		public static final int PU_IRIS_TYPE_MANUAL = 2; // Manual.
		public static final int PU_IRIS_TYPE_BUTT = 3;
	}

	// Aperture parameter.
	public interface PU_IRIS_VALUE {
		public static final int IRIS_VALUE_1_2 = 0;
		public static final int IRIS_VALUE_1_4 = 1;
		public static final int IRIS_VALUE_1_6 = 2; // The f-number is F1.6.
		public static final int IRIS_VALUE_2_0 = 3; // The f-number is F2.0. The rest can be deduced by analogy.
		public static final int IRIS_VALUE_2_3 = 4;
		public static final int IRIS_VALUE_2_4 = 5;
		public static final int IRIS_VALUE_2_8 = 6;
		public static final int IRIS_VALUE_3_2 = 7;
		public static final int IRIS_VALUE_3_4 = 8;
		public static final int IRIS_VALUE_4_0 = 9;
		public static final int IRIS_VALUE_4_5 = 10;
		public static final int IRIS_VALUE_4_8 = 11;
		public static final int IRIS_VALUE_5_6 = 12;
		public static final int IRIS_VALUE_6_4 = 13;
		public static final int IRIS_VALUE_6_8 = 14;
		public static final int IRIS_VALUE_8_0 = 15;
		public static final int IRIS_VALUE_9_1 = 16;
		public static final int IRIS_VALUE_9_6 = 17;
		public static final int IRIS_VALUE_11_0 = 18;
		public static final int IRIS_VALUE_14_0 = 19;
		public static final int IRIS_VALUE_16_0 = 20;
		public static final int IRIS_VALUE_22_0 = 21;
		public static final int IRIS_VALUE_32_0 = 22;
		public static final int IRIS_VALUE_CLOSE = 23; // Close the iris.
		public static final int IRIS_VALUE_MAX = 24;
	}

	public static class PU_IRLIGHT_LIST extends Structure {
		public ULONG ulChannelId;
		public int enIRLightMode; // c type:PU_IRLIGHT_MODE
		public PU_IRLIGHT_PARA[] stIRLightMPara = (PU_IRLIGHT_PARA[]) new PU_IRLIGHT_PARA().toArray(PU_IRLIGHT_NUM_MAX); // Infrared
																															// illuminator
																															// data.
																															// This
																															// parameter
																															// is
																															// mandatory
																															// in
																															// manual
																															// mode.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates whether to enable the
																// intelligent infrared illuminator. The options are 0
																// (yes) and 1 (no).
		// szReserved[1] indicates the infrared coefficient that ranges from 1 to 100.
		// szReserved[2] indicates whether to enable safety restriction. The options are
		// 0 (no) and 1 (yes).

		public PU_IRLIGHT_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulIRLightLum", "szReserved");
		}
	}

	public interface PU_IRLIGHT_MODE {
		public static final int PU_IRLIGHT_MODE_ATUO = 0; // Automatic.
		public static final int PU_IRLIGHT_MODE_MANUAL = 1; // Manual.
		public static final int PU_IRLIGHT_MODE_MAX = 2;
	}

	// Infrared illuminator parameters.
	public static class PU_IRLIGHT_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.
		public ULONG ulIRLightLum; // Brightness.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_IRLIGHT_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulIRLightLum", "szReserved");
		}
	}

	// Infrared illuminator parameters.
	public static class PU_IRLIGHT_PARA_S extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.
		public ULONG ulIRLightLum; // Brightness.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_IRLIGHT_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulIRLightLum", "szReserved");
		}
	}

	/********* Image algorithm information *********/
	public static class PU_ISP_ALG_INFO_S extends Structure {
		public ULONG ulChannelId; // Reserved channel ID.
		public PU_ALG_INFO_S[] szAlgInfos = new PU_ALG_INFO_S[PU_ISP_TYPE_MAX_NUM]; // Algorithm version information.
																					// For further expansion, 64
																					// algorithms are reserved.
																					// Currently, only the scene
																					// adaptation algorithm is
																					// supported.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ISP_ALG_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "szAlgInfos", "szReserved");
		}
	}

	/* Highlight Compensation (HLC). */
	public static class PU_ISP_CAM_HLC_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enHlc; // Indicates whether to enable the HLC (enable/disable). c
							// type:PU_COMMONMODE_SWITCH
		public ULONG ulHlcLevel; // HLC level for Panasonic devices, ranging from 1 to 3.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ISP_CAM_HLC_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enHlc", "ulHlcLevel", "szReserve");
		}
	}

	/* Highlight Compensation (HLC). */
	public static class PU_ISP_HLC extends Structure {
		public int enHlc; // Indicates whether to enable the HLC (enable/disable). c
							// type:PU_COMMONMODE_SWITCH
		public ULONG ulHlcLevel; // HLC level for Panasonic devices, ranging from 1 to 3.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ISP_HLC() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDRC", "ulDRCStrength", "szReserve");
		}
	}

	public interface PU_ISP_IRCUT_MODULE {
		public static final int PU_IRCUT_MODE_DUMMY = 0; // Color mode.
		public static final int PU_IRCUT_MODE_NIGHT = 1; // B/W mode.
		public static final int PU_IRCUT_MODE_DEFOG = 2; // Optical defogging (supported only by some devices).
		public static final int PU_IRCUT_MODE_MAX = 3;
	}

	/* Detailed ISP parameters. */
	public static class PU_ISP_PARTICULAR_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public ULONG ulBitMap; // Modify bit (The lower bit indicates the AE mode.)
		public int enAEMode; // 1: AE exposure mode. c type:PU_AE_MODE
		public NativeLong lAEResponseTime; // 2: AE response time.
		public PU_CAM_EXPCOMP_PARA stCamExpcompPara; // 3: exposure compensation.
		public PU_CAM_WB_MANUAL_PARA stCamWBManualPara; // 4: white balance.
		public PU_CAM_WD_PARA stCamWDPara; // 5: WDR.
		public PU_CAM_SLOW_SHUTTER_MODE stSlowShutterMode; // 6: whether to enable slow shutter (not supported by ITS
															// cameras and multi-algorithm models (full intelligence
															// mode)).
		public int enCamFlickerMode; // 7: background frequency. c type: PU_VIDEO_FLICKER_MODE
		public PU_AEMETERING_MODE stCamAEMeterMode; // 8: AE metering mode.
		public PU_SHUTTER_VALUE stCamshutterValue; // 9: shutter speed range and its value.
		public PU_BACKLIGHT_MODE stCamBackLightMode; // 10: backlight compensation mode.
		public PU_IRC_PARA stCamIRCPara; // 11: day/night mode.
		public NativeLong lAutoGainMaxValue; // 12: maximum auto gain value.
		public PU_GAIN_CONTROL stCamGainControl; // 13: gain control.
		public PU_NOISE_REDUCTION stCamDenoisePara; // 14: noise reduction mode.
		public PU_STABILIZER_PARA stCamStabilizerPara; // 15: image stabilization mode.
		public PU_IRIS_CONTROL stCamIrisControl; // 16: iris control.
		public PU_DEFOG_PARA stISPDefogPara; // 17: defogging mode.
		public PU_IMG_DRC stImgDRCPara; // 18: DRC parameter.
		public int enMinFocusValue; // 19: minimum focus distance.c type：PU_MIN_FOCUS
		public PU_ISP_HLC stHlc; // 20: highlight compensation.
		public int enIrisType; // 21: iris type.c type: PU_IRIS_TYPE
		public int enShutterValueLimit; // 22: shutter limit.c type: PU_CAM_SHUTTER_MODE
		public PU_ROI_METER_MODE stCamRoiMeterMode; // ROI metering of micro checkpoint cameras.
		public int enRoiMeterType; // Exposure compensation type.c type: PU_ROIMETER_TYPE
		public ULONG ulFaceExposureTime; // Face exposure time, ranging from 10 to 300.
		public char enPirisType; // P-iris subtype. For details, see PU_CAM_P_IRIS_TYPE_E.
		public byte[] szReserve = new byte[PU_RESERVE_LEN - 4 - 4 - LLong.size - 4];

		public PU_ISP_PARTICULAR_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulBitMap", "enAEMode", "lAEResponseTime", "stCamExpcompPara",
					"stCamWBManualPara", "stCamWDPara", "stSlowShutterMode", "enCamFlickerMode", "stCamAEMeterMode",
					"stCamshutterValue", "stCamBackLightMode", "stCamIRCPara", "lAutoGainMaxValue", "stCamGainControl",
					"stCamDenoisePara", "stCamStabilizerPara", "stCamIrisControl", "stISPDefogPara", "stImgDRCPara",
					"enMinFocusValue", "stHlc", "enIrisType", "enShutterValueLimit", "stCamRoiMeterMode",
					"enRoiMeterType", "ulFaceExposureTime", "enPirisType", "szReserve");
		}

	}

	// Extended ISP parameters.
	public static class PU_ISP_PARTICULAR_PARA_EX_S extends Structure {
		/* C typ : PU_ISP_PARTICULAR_PARA_TYPE_E */
		public int enISPParamType; // ISP parameter type.
		public PU_SNAPSHOT_PARTICULAR_PARA_S stISPParam; // ISP parameters.

		public PU_ISP_PARTICULAR_PARA_EX_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enISPParamType", "stISPParam");
		}
	}

	// ISP parameter types.
	public interface PU_ISP_PARTICULAR_PARA_TYPE_E {
		int PU_ISP_HUMAN = 0; // ISP parameter of the multi-algorithm concurrency camera in face capture or
								// behavior analysis mode.
		int PU_ISP_HUMAN_DEFAULT = 1; // Default ISP parameter of the multi-algorithm concurrency camera in face
										// capture or behavior analysis mode. The parameter can be obtained only.
		int PU_ISP_VEHICLE = 2; // ISP parameter of the multi-algorithm concurrency camera in micro checkpoint
								// mode.
		int PU_ISP_VEHICLE_DEFAULT = 3; // Default ISP parameter of the multi-algorithm concurrency camera in micro
										// checkpoint mode. The parameter can be obtained only.
		int PU_ISP_NORMAL = 4; // Common ISP parameters.
	}

	// Structuring for setting ISP profiles linked in day/night mode.
	public static class PU_ISP_PROFILES_LINK_INFO extends Structure {
		public ULONG ulChannelID;
		public WinDef.BOOL bEnable; // Indicates whether to enable ISP profile linkage in day/night mode.
		public PU_ISP_PROFILES_LINK_MODE[] szLinkMode = (PU_ISP_PROFILES_LINK_MODE[]) new PU_ISP_PROFILES_LINK_MODE()
				.toArray(PU_IRCUT_MODE_MAX_NUM); // Linkage list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_ISP_PROFILES_LINK_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "bEnable", "szLinkMode", "szReserved");
		}
	}

	// ISP profile linked in day/night mode.
	public static class PU_ISP_PROFILES_LINK_MODE extends Structure {
		public int enIRCMode; // IR CUT mode. c type:PU_ISP_IRCUT_MODULE
		public ULONG ulISPProfilesIndex; // ISP profile index.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_ISP_PROFILES_LINK_MODE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enIRCMode", "ulISPProfilesIndex", "szReserved");
		}
	}

	/* ISP profile parameters. */
	public static class PU_ISP_PROFILES_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public int enOptionType; // Operation type. c type : PU_OPT_TYPE_E
		public PU_ISP_SCENE_PARA stClassiscalScenePara; // ISP profile scene parameter.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field. [0] indicates the parameter type. For
																// details, see PU_SCENE_PARAM_TYPE_E.

		public PU_ISP_PROFILES_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enOptionType", "stClassiscalScenePara", "szReserved");
		}
	}

	/* Basic parameters for the ISP profile scenes. */
	public static class PU_ISP_SCENE_PARA extends Structure {
		public ULONG ulIndex; // Unique ID. The digits 1-4 indicate basic settings and cannot be deleted. Set
								// this parameter to 0 when adding an ISP profile. To modify or delete an ISP
								// profile, enter the specified index.
		public byte[] szName = new byte[PU_TYPICAL_SCENE_NAME_LEN]; // Typical scene profile name.
		public byte[] szDescrip = new byte[PU_TYPICAL_SCENE_DESCRIBE_LEN]; // Description.
		public PU_ISP_PARTICULAR_PARA stSceneModeISP; // ISP parameters.
		public PU_VIDEO_DISPLAY_INFO stVideoDisplayPara; // Video effect.
		public PU_IRLIGHT_LIST stIrLightArrayPara; // Infrared illuminator setting.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_ISP_SCENE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "szName", "szDescrip", "stSceneModeISP", "stVideoDisplayPara",
					"stIrLightArrayPara", "szReserved");
		}
	}

	/* ISP scene. */
	public interface PU_ISP_SCENE_TYPE {
		public static final int ISP_SCNEN_NORMAL = 0; // Common scene.
		public static final int ISP_SCENE_OBJECT = 1; // Objective scene, used for type inspection.
		public static final int ISP_SCENE_INDOOR = 2; // Indoor.
		public static final int ISP_SCENE_OUTDOOR = 3; // Outdoor.
		public static final int ISP_SCENE_LOW_BRIGHT = 4; // Dimly lit.
		public static final int ISP_SCENE_BACK_LIGHT = 5; // Backlit scene.
		public static final int ISP_SCENE_VIRTUAL_BAYONET = 6; // Virtual checkpoint scene.
		public static final int ISP_SCENE_FOG = 7; // Overcast scene.
		public static final int ISP_SCENE_FACE = 8; // Facial application scene (for face checkpoint cameras only).
		public static final int ISP_SCENE_MAX = 9;
	}

	/* Typical ISP scenes. */
	public static class PU_ISP_TYPICAL_SCENE_MODE extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public int enParamType; // Parameter type. c type:PU_SCENE_PARAM_TYPE
		public int enMode; // Scene mode. c type:PU_TYPICAL_SCENE_MODE
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_ISP_TYPICAL_SCENE_MODE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enParamType", "enMode", "szReserved");
		}
	}

	// Multi-purpose camera.
	public static class PU_ITGE_MODE_E {
		int COMMON_MODE = 0; // Common camera.
		int FACE_DETECTION_MODE = 1; // Face detection/C30 face checkpoint.
		int FACE_RECOGNITION_MODE = 2; // Facial recognition.
		int BAYONET_MODE = 3; // Micro checkpoint.
		int MOTOR_DETECTION_MODE = 4; // Object classification/C30 micro checkpoint.
		int ITS_MODE = 5; // ITS mode.
		int VHD_FACE_MODE = 6; // Multi-purpose camera (object classification mode + face detection)/C30 full
								// intelligence.
		int BA_MODE = 7; // Behavior analysis mode, added in C30.
		int CLOSE_ALG_MODE = 8; // 1 + N (all disabled).
		int ITS_EPOLICE_SINGLE_PIPE = 9; // ePolice single-channel stream mode.
		int ITS_EPOLICE_DOUBLE_PIPE = 10; // ePolice dual-channel stream mode.
		int ITS_TGATEWAY_SINGLE_PIPE = 11; // Checkpoint single-channel stream mode.
		int ITS_TGATEWAY_DOUBLE_PIPE = 12; // Checkpoint dual-channel stream mode.
	}

	public static class PU_ITGT_ALTHM_BASIC_INFO extends Structure {
		// C type : PU_ITGT_TYPE_E
		public int enAlthmType; // Algorithm type.
		public PU_ITGT_LIC_STATUS_E enAlthmStatus; // Algorithm control status.
		public BOOL bEnableAlthm; // Indicates whether to enable the algorithm. The options are as follows: 0: no;
									// 1: yes.
		public byte[] szAlthmVer = new byte[PU_ITGT_ALTHM_VERSION_LEN]; // Algorithm version.
		public byte[] szAlthmOwner = new byte[PU_ITGT_ALTHM_VENDOR_LEN]; // Algorithm vendor.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enAlthmType", "enAlthmStatus", "bEnableAlthm", "szAlthmVer", "szAlthmOwner",
					"szReserved");
		}
	}

	public static class PU_ITGT_ALTHM_INFO extends Structure {
		public int ulChannelID; // Channel ID.
		public int uiValidCount; // Number of valid algorithms.
		public PU_ITGT_ALTHM_BASIC_INFO[] astItgtAlthmBasInfo = new PU_ITGT_ALTHM_BASIC_INFO[PU_ITGT_TYPE_MAX_NUM]; // Detailed
																													// algorithm
																													// information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "uiValidCount", "astItgtAlthmBasInfo", "szReserved");
		}
	}

	public static class PU_ITGT_ALTHM_INFO_EX extends Structure {
		public int ulChannelID; // Channel ID.
		public int uiValidCount; // Number of valid algorithms.
		public PU_ITGT_ALTHM_BASIC_INFO[] astItgtAlthmBasInfo = new PU_ITGT_ALTHM_BASIC_INFO[PU_ITGT_TYPE_MAX_EX_NUM]; // Detailed
																														// algorithm
																														// information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "uiValidCount", "astItgtAlthmBasInfo", "szReserved");
		}
	}

	// Intelligent algorithm license control information.
	public static class PU_ITGT_LIC_CONTROL_INFO extends Structure {
		// C type : PU_ITGT_TYPE_E
		public int enItgtType;
		// C type : PU_ITGT_LIC_STATUS_E
		public int enItgtStatus;
		public byte[] szLicExpiryDate = new byte[PU_LIC_DATE_MAX_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enItgtType", "enItgtStatus", "szLicExpiryDate");
		}
	}

	// Revocation code.
	public static class PU_ITGT_LIC_REVOKE_INFO extends Structure {
		public byte[] szRevokeKey = new byte[PU_LIC_REVOKE_KEY_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szRevokeKey");
		}
	}

	// License service message structure.
	public static class PU_ITGT_LIC_SERVICE_INFO extends Structure {
		public int uiLicItgtNum; // Number of intelligent algorithms in a license.
		public byte[] szLicCreatDate = new byte[PU_LIC_DATE_MAX_LEN]; // License file creation date.
		public byte[] szLicServiceAge = new byte[PU_LIC_SERVICE_AGE_MAX_LEN]; // Service lifespan.
		public PU_ITGT_LIC_CONTROL_INFO[] astLicControlInfo = new PU_ITGT_LIC_CONTROL_INFO[PU_ITGT_TYPE_MAX_NUM]; // Intelligent
																													// algorithm
																													// license
																													// control
																													// information.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiLicItgtNum", "szLicCreatDate", "szLicServiceAge", "astLicControlInfo");
		}
	}

	// License service message structure extension (16->64).
	public static class PU_ITGT_LIC_SERVICE_INFO_EX extends Structure {
		public int uiLicItgtNum; // Number of intelligent algorithms in a license.
		public int[] szLicCreatDate = new int[PU_LIC_DATE_MAX_LEN]; // License file creation date.
		public byte[] szLicServiceAge = new byte[PU_LIC_SERVICE_AGE_MAX_LEN]; // Service lifespan.
		public PU_ITGT_LIC_CONTROL_INFO[] astLicControlInfo = new PU_ITGT_LIC_CONTROL_INFO[PU_ITGT_TYPE_MAX_EX_NUM]; // Intelligent
																														// algorithm
																														// license
																														// control
																														// information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiLicItgtNum", "szLicCreatDate", "szLicServiceAge", "astLicControlInfo",
					"szReserved");
		}
	}

	// Intelligent algorithm license control status.
	public interface PU_ITGT_LIC_STATUS_E {
		int PU_ITGT_LIC_STATUS_DEFAULT = 0; // The control item is in default state.
		int PU_ITGT_LIC_STATUS_TRIAL = 1; // The control item is in the grace period.
		int PU_ITGT_LIC_STATUS_NORMAL = 2; // The control item is in normal state.
		int PU_ITGT_LIC_STATUS_EMERGENCY = 3; // The control item is in emergency state.
		int PU_ITGT_LIC_STATUS_NO_USE = 4; // Not used.
		int PU_ITGT_LIC_STATUS_NA = 5; // Not involved.
	}

	public static class PU_ITGT_MODE_S extends Structure {
		// C type PU_ITGE_MODE_E
		public int enITGEMode;
		public ULONG ulChannelId; // Channel ID.
		public byte[] szReserve = new byte[PU_RESERVE_LEN - LLong.size];

		public PU_ITGT_MODE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enITGEMode", "ulChannelId", "szReserve");
		}
	}

	public interface PU_ITGT_TYPE {
		public static final int PU_ITGT_TYPE_FACE_BODY_DETECT = 1; // Face and body detection
		public static final int PU_ITGT_TYPE_FACE_RECOGTION = 2; // Facial recognition
		public static final int PU_ITGT_TYPE_OBJ_CLASSIFICATION = 3; // Object classification
		public static final int PU_ITGT_TYPE_ILLEG_PARK_DETECT = 4; // Parking violation detection.
		// PU_ITGT_TYPE_NON_CHINA_VEH_RECOGTION, // Non-Chinese license plate
		// recognition (incorporated).
		public static final int PU_ITGT_TYPE_VLPR_VEH_RECOGTION = 6; // License plate recognition, incorporating
																		// non-Chinese license plate recognition and
																		// Chinese and Indonesian license plate
																		// recognition.
		public static final int PU_ITGT_TYPE_SCENE_ADAPT_FOG = 7; // Overcast adaptation.
		public static final int PU_ITGT_TYPE_SCENE_ADAPT_SPEED = 8; // Trailing adaptation.
		public static final int PU_ITGT_TYPE_SCENE_ADAPT_BACK_LIGHT = 9; // Backlight adaptation.
		public static final int PU_ITGT_TYPE_FACE_ATTRIBUTE = 10; // Facial attribute recognition.
		public static final int PU_ITGT_TYPE_BODY_ATTRIBUTE = 11; // Personal attribute recognition.
		public static final int PU_ITGT_TYPE_QUEUE_DETECT = 12; // Queue length detection.
		public static final int PU_ITGT_TYPE_CROWD_DENSITY_DETECITON = 13; // Crowd density detection.
		public static final int PU_ITGT_TYPE_CHINA_INDO_VEH_RECOGTION = 14; // Chinese and Indonesian license plate
																			// recognition (incorporated).
		public static final int PU_ITGT_TYPE_STRATEGY_MMC = 15; // Multi-camera collaboration.
		public static final int PU_ITGT_TYPE_STRATEGY_YTN = 16; // 1 + N network.
		public static final int PU_ITGT_TYPE_STRATEGY_ONLINELEARNING = 17; // Online learning.
		public static final int PU_ITGT_TYPE_STRATEGY_PORTTRAIT_VALUE_BASIC = 18; // Face image base.
		public static final int PU_ITGT_TYPE_STRATEGY_PORTTRAIT_VALUE_ENHANCED = 19;// Face image enhancement.
		public static final int PU_ITGT_TYPE_STRATEGY_VEHICLE_VALUE_BASE = 20; // Vehicle image base.
		public static final int PU_ITGT_TYPE_STRATEGY_VEHICLE_VALUE_enhanced = 21; // Vehicle image enhancement.
		public static final int PU_ITGT_TYPE_STRATEGY_BEHAVIOR_ANALYSIS = 22; // Behavior analysis.
		public static final int PU_GB35114SW = 23; // GB 35114 software SDK license.
		public static final int PU_ITGT_TYPE_EBI_TYPE = 24; // BEI perimeter intrusion detection camera.
		public static final int PU_ITGT_TYPE_MAX = 25;

	}

	/********* Automatic object tracking priority *********/
	public static class PU_ITGT_VHD_AUTO_TRACK_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.

		public WinDef.BOOL bEnable; // Indicates whether to enable the algorithm.
		public ULONG ulSensitivity; // Algorithm detection sensitivity.
		public ULONG ulAlarmTime; // Alarm reporting interval.
		public ULONG ulMaxTraceTime; // Maximum tracking duration.
		public AERADTC_LIST stAreaList; // Alert deployment area.
		public PU_ALARM_TIME_LIST_S stAlarmTimeList;// Alert plan.
		public PU_ITGT_VHD_OBJECT_ITEM[] objItem = (PU_ITGT_VHD_OBJECT_ITEM[]) new PU_ITGT_VHD_OBJECT_ITEM()
				.toArray(PU_ITGT_AUTOTRACKING_PRIORITY_ITEM_NUM); // Automatic tracking priority.
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_ITGT_VHD_AUTO_TRACK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "bEnable", "ulSensitivity", "ulAlarmTime", "ulMaxTraceTime",
					"stAreaList", "stAlarmTimeList", "objItem", "szReserved");
		}
	}

	/********* Manual object tracking *********/
	public static class PU_ITGT_VHD_MANUAL_TRACK_PARA extends Structure {
		public ULONG ulChannelID; // Reserved channel ID.

		public ULONG ulTargetID; // ID of the tracked object.
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_ITGT_VHD_MANUAL_TRACK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulTargetID", "szReserved");
		}
	}

	/********* Automatic object tracking priority *********/
	public static class PU_ITGT_VHD_OBJECT_ITEM extends Structure {
		public int objType; // Object type. C type is PU_ITGT_VHD_OBJ_TYPE_E

		public WinDef.BOOL enable; // Indicates whether to enable snapshot retransmission.
		public ULONG priority; // Priority.

		public PU_ITGT_VHD_OBJECT_ITEM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("objType", "enable", "priority");
		}
	}

	/* ITS service type structure. */
	public static class PU_ITS_BUSINESS_TYPE_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public int enITSBusinessType; // ITS service type. c type:EN_ITS_TYPE
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enITSBusinessType", "szReserved");
		}
	}

	// Vehicle direction in video.
	public interface PU_ITS_CAR_DRV_DIR_E {
		int ITS_CAR_UNKNOW = 0; // Unknown.
		int ITS_CAR_BOTTOM_TO_TOP = 1; // From bottom to top (leaving).
		int ITS_CAR_TOP_TO_BOTTOM = 2; // From top to bottom (approaching).
	}

	// Loop vehicle detector configuration.
	public static class PU_ITS_COIL_DETECTOR_INFO_S extends Structure {
		public PU_ITS_COIL_SNAP_TYPE_E enSnapType;
		public ULONG uiDelayTime; // Delay, ranging from 0 to 80 milliseconds.
		public ULONG uiCoilNum; // Number of loops (1, 2, or 3).
		public ULONG uiCoilInterval; // Loop spacing (cm).
		public ULONG uiCoilWidth; // Loop width (cm).

		public PU_ITS_COIL_DETECTOR_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSnapType", "uiDelayTime", "uiCoilNum", "uiCoilInterval", "uiCoilWidth");
		}
	}

	/* Loop detector snapshot scheme. */
	public interface PU_ITS_COIL_SNAP_TYPE_E {
		int ITS_COIL_SNAP_SINGLE_NONE = 0; // No snapshot.
		int ITS_COIL_SNAP_SINGLE_IN1 = 1; // One_Into loop 1.
		int ITS_COIL_SNAP_SINGLE_OUT1 = 2; // One_Out of loop 1.
		int ITS_COIL_SNAP_DOUBLE_HEAD_IN2 = 21; // Two_Front_Into loop 2.
		int ITS_COIL_SNAP_DOUBLE_TAIL_OUT1_IN2 = 22; // Two_Rear_Out of loop 1 and into loop 2.
		int ITS_COIL_SNAP_DOUBLE_TAIL_OUT2 = 23; // Two_Rear_Out of loop 2.
		int ITS_COIL_SNAP_TRIPLE_HEAD_IN3 = 24; // Three_Front_Into loop 3.
		int ITS_COIL_SNAP_TRIPLE_TAIL_OUT2_IN3 = 25; // Three_Rear_Out of loop 2 and Into loop 3.
		int ITS_COIL_SNAP_TRIPLE_TAIL_OUT3 = 26; // Three_Rear_Out of loop 3.

		int ITS_COIL_SNAP_DOUBLE_OUT1_OUT2_OUT2DELAY = 41; // Two_Out of loop 1_Out of loop 2_Out of loop 2 delay.
		int ITS_COIL_SNAP_DOUBLE_IN1_OUT2_OUT2DELAY = 42; // Two_Into loop 1_Out of loop 2_Out of loop 2 delay.
		int ITS_COIL_SNAP_DOUBLE_IN2_OUT2_OUT2DELAY = 43; // Two_Into loop 2_Out of loop 2_Out of loop 2 delay.
		int ITS_COIL_SNAP_TRIPLE_OUT1_OUT2_OUT3 = 44; // Three_Out of loop 1_Out of loop 2_Out of loop 3.
		int ITS_COIL_SNAP_TRIPLE_OUT1_OUT2_OUT3DELAY = 45; // Three_Out of loop 1_Out of loop 2_Out of loop 3 delay.
	}

	// Radar detection direction.
	public interface PU_ITS_DETECT_DIR_E {
		int ITS_DETECT_DIR_UNKNOWN = 0;
		int ITS_DETECT_DIR_COMING = 1; // Approaching.
		int ITS_DETECT_DIR_GOING = 2; // Leaving.
		int ITS_DETECT_DIR_BOTH = 3; // Bidirectional.
	}

	// Brief information about ITS external devices.
	public static class PU_ITS_DEV_INFO_S extends Structure {
		// enDeviceProtelType 对应PU_EXTRA_DEVICE_TYPE_E
		public int enDeviceProtelType; // Protocol type of the external device.
		public PU_RADAR_CTRL_INFO_S stRadarInfo; // Radar device information.
		public PU_VEHICLE_DETECTOR_INFO_S stVehicleDetectorInfo; // Vehicle detector information.
		public PU_IO_DETECTOR_INFO_S stIODetectorInfo; // I/O protocol.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_DEV_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enDeviceMode", "ulTotalRoadNum", "enExtraType", "stDevSpecInfo",
					"stLightDetectorInfo", "bInputState", "szReserve");
		}
	}

	// ITS external device parameters.
	public static class PU_ITS_DEV_SPEC_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		// C Type : PU_DEVICE_MODE_E
		public int enDeviceMode; // Device snapshot mode.
		public ULONG ulTotalRoadNum; // Total number of lanes.
		// C Type :PU_ITS_EXTRA_DEVICE_TYPE_E
		public int enExtraType; // External device type. The options are as follows: 0: no external device; 1:
								// radar; 2: vehicle detector; 3: I/O detector. The devices are mutually
								// exclusive. (The protocol type must match the device type specified by this
								// parameter.)
		public PU_ITS_DEV_INFO_S[] stDevSpecInfo = (PU_ITS_DEV_INFO_S[]) new PU_ITS_DEV_INFO_S()
				.toArray(PU_ITS_MAX_ROAD_NUM); // Parameter configuration based on lanes.
		public PU_LIGHT_DETECTOR_INFO_S stLightDetectorInfo; // Traffic light detector, not associated with lanes.
		public BOOL bInputState; // Alarm input state.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_DEV_SPEC_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enDeviceMode", "ulTotalRoadNum", "enExtraType", "stDevSpecInfo",
					"stLightDetectorInfo", "bInputState", "szReserve");
		}
	}

	;

	/* ITS detection line parameter structure. */
	public static class PU_ITS_DT_LINE_PARAM extends Structure {
		public ULONG ulChannelId; // Channel ID.
		// C Type ： EN_ITS_TYPE
		public int enITSType; // ITS service type.
		public BOOL bEnable; // Indicates whether to enable ITS services.
		// [Difference from the service structure] The union is deleted and the
		// parameter structure is directly defined.
		public tagItsEPoliceDtLineParam stEPolice; // ePolice detection line parameter.

		public PU_ITS_DT_LINE_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enITSType", "bEnable", "stEPolice");
		}
	}

	;

	// ITS lane parameters.
	public static class PU_ITS_EPOLICE_LANE_PARAM extends Structure {
		public ULONG ulChannelId; // Channel ID.

		public int enITSType; // ITS service type. c type:EN_ITS_TYPE
		public int iLaneNum; // Lane quantity.
		public PU_ITS_LANE_PARAM_UNIT[] astLaneParamU = (PU_ITS_LANE_PARAM_UNIT[]) new PU_ITS_LANE_PARAM_UNIT()
				.toArray(MAX_AREA_VERTEX); // Lane parameters.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_EPOLICE_LANE_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enITSType", "iLaneNum", "astLaneParamU", "szReserve");
		}
	}

	// Traffic light parameters in ePolice mode.
	public static class PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM extends Structure {
		public ULONG ulChannelId; // Channel ID.
		// C Type : PU_ITS_LIGHT_DT_TYPE_S
		public int enLightDtType; // Traffic light detection access mode.
		public int iSignalLightAreaNum; // Number of traffic light areas.
		public PU_ITS_SIGNAL_LIGHT_AREA_PARAM[] astSignalLightList = (PU_ITS_SIGNAL_LIGHT_AREA_PARAM[]) new PU_ITS_SIGNAL_LIGHT_AREA_PARAM()
				.toArray(PU_ITS_MAX_LIGHTAREA_NUM); // Traffic light parameters.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enLightDtType", "iSignalLightAreaNum", "astSignalLightList",
					"szReserve");
		}
	}

	// External device type.
	public interface PU_ITS_EXTRA_DEVICE_TYPE_E {
		int ITS_DEVICE_NONE = 0; // No external device.
		int ITS_DEVICE_RADAR = 1; // Radar.
		int ITS_DEVICE_VEHICLE = 2; // Vehicle detector.
		int ITS_DEVICE_IO = 3; // I/O detector.
	}

	/* ITS ???????????? */
	public static class PU_ITS_FLOW_RATE_PARA extends Structure {
		public ULONG ulChannelId; // Channel IDF.
		// C Type : PU_ENABLE_TYPE_E
		public int bEnable; // Indicates whether to enable traffic flow statistics.
		public ULONG uInterval; // Statistical period (minute).
		public ULONG uCameraFromIntersection; // Distance between the camera and the intersection (m).
		public ULONG uDetectionAreaLength; // Detection area length (m).
		public ULONG uCongestionLaneThreshold;// Congestion alarm reporting threshold.
		public ULONG uCongestionThreshold; // Congestion threshold (km/h).
		public ULONG uSlowThreshold; // Slow driving threshold (km/h).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "uInterval", "uCameraFromIntersection",
					"uDetectionAreaLength", "uCongestionLaneThreshold", "uCongestionThreshold", "uSlowThreshold",
					"szReserve");
		}
	}

	/* Violation dictionary parameter. */
	public static class PU_ITS_ILLEGAI_DIC_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		// C Type: PU_LANGUAGE_TYPE_E
		public int enLanguageType; // Language, which is used to obtain the parameter setting.
		public ULONG ulIllegalNum; // Number of violation dictionary items.
		public PU_ITS_ILLEGAI_DIC_PARA_UNIT_S[] astIllegals = (PU_ITS_ILLEGAI_DIC_PARA_UNIT_S[]) new PU_ITS_ILLEGAI_DIC_PARA_UNIT_S()
				.toArray(PU_ITS_ILLEGAL_TYPE_NUM_MAX); // Violation item.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_ILLEGAI_DIC_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enLanguageType", "ulIllegalNum", "astIllegals", "szReserve");
		}
	}

	/* Violation type in a single violation dictionary. */
	public static class PU_ITS_ILLEGAI_DIC_PARA_UNIT extends Structure {
		public byte[] szIllTypeString = new byte[PU_ITS_ILLEGAL_TYPE_LEN_MAX]; // Violation type, which cannot be
																				// modified. The maximum length is as
																				// follows: PU_ITS_ILLEGAL_TYPE_LEN_MAX
																				// – 4.
		public byte[] szIllCodeString = new byte[PU_ITS_ILLEGAL_NUM_LEN_MAX]; // Violation code. The maximum length is
																				// as follows:
																				// PU_ITS_ILLEGAL_NUM_LEN_MAX – 1.
		public byte[] szIllNameString = new byte[PU_ITS_ILLEGAL_NAME_LEN_MAX]; // Superimposed violation name. The
																				// maximum length is as follows:
																				// PU_ITS_ILLEGAL_NAME_LEN_MAX – 4.

		public PU_ITS_ILLEGAI_DIC_PARA_UNIT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szIllTypeString", "szIllCodeString", "szIllNameString");
		}
	}

	/* Violation type in a single violation dictionary. */
	public static class PU_ITS_ILLEGAI_DIC_PARA_UNIT_S extends Structure {
		public byte[] szIllTypeString = new byte[PU_ITS_ILLEGAL_TYPE_LEN_MAX]; // Violation type, which cannot be
																				// modified. The maximum length is as
																				// follows: PU_ITS_ILLEGAL_TYPE_LEN_MAX
																				// – 4.
		public byte[] szIllCodeString = new byte[PU_ITS_ILLEGAL_NUM_LEN_MAX]; // Violation code. The maximum length is
																				// as follows:
																				// PU_ITS_ILLEGAL_NUM_LEN_MAX – 1.
		public byte[] szIllNameString = new byte[PU_ITS_ILLEGAL_NAME_LEN_MAX]; // Superimposed violation name. The
																				// maximum length is as follows:
																				// PU_ITS_ILLEGAL_NAME_LEN_MAX – 4.

		public PU_ITS_ILLEGAI_DIC_PARA_UNIT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szIllTypeString", "szIllCodeString", "szIllNameString");
		}
	}

	/* Violation dictionary parameter. */
	public static class PU_ITS_ILLEGAI_DIC_PARAM_S extends Structure {
		public ULONG ulChannelID; // Channel ID.
		// C type : PU_LANGUAGE_TYPE_E
		public int enLanguageType; // Language, which is used to obtain the parameter setting.
		public ULONG ulIllegalNum; // Number of violation dictionary items.
		public PU_ITS_ILLEGAI_DIC_PARA_UNIT_S[] astIllegals = (PU_ITS_ILLEGAI_DIC_PARA_UNIT_S[]) new PU_ITS_ILLEGAI_DIC_PARA_UNIT_S()
				.toArray(PU_ITS_ILLEGAL_TYPE_NUM_MAX); // Violation item.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_ILLEGAI_DIC_PARAM_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enLanguageType", "ulIllegalNum", "astIllegals", "szReserve");
		}
	}

	// Loop vehicle detector configuration.
	public static class PU_ITS_IO_DETECTOR_INFO_S extends Structure {
		// C Type PU_ITS_COIL_SNAP_TYPE_E
		public int enSnapType; // Snapshot type.
		// C type PU_DEVICE_IO_TYPE_E
		public int enTrigType; // GPIO triggering mode.

		public PU_ITS_IO_DETECTOR_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSnapType", "enTrigType");
		}
	}

	// Basic lane information.
	public static class PU_ITS_LANE_INFO_BASE_UNIT extends Structure {
		public int enLaneDirType; // Lane direction. c type:PU_ITS_ROAD_DIR_TYPE_E

		public int enLaneDrvDir; // Regulated driving direction of the lane. c type:PU_ITS_ROAD_DRV_DIR_E
		public int enCarDrvDir; // Vehicle direction in video. c type:PU_ITS_CAR_DRV_DIR_E
		public int enLanePurpose; // Lane usage. c type:PU_ITS_ROAD_PURPOSE_E
		public int enLaneAttribute; // Lane attribute. c type：PU_ITS_ROAD_ATTRIBUTE_E
		public int iOSDLaneNO; // Superimposed lane ID (OSD, generally matching the actual lane).
		public int iBindingDeviceCode; // Associated lane ID, used by radars, vehicle detectors, and external I/O
										// devices.
		public int iPreRecordStart; // Pre-recording start time.
		public int enLaneSideScene; // Lane scene, which is used to determine whether an illegal U-turn occurs.c
									// type:ITS_ROAD_SIDE_SCENE_E
		public byte[] szReserve = new byte[PU_RESERVE_LEN - 1];

		public PU_ITS_LANE_INFO_BASE_UNIT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enLaneDirType", "enLaneDrvDir", "enCarDrvDir", "enLanePurpose", "enLaneAttribute",
					"iOSDLaneNO", "iBindingDeviceCode", "iPreRecordStart", "enLaneSideScene", "szReserve");
		}
	}

	// Lane parameter unit.
	public static class PU_ITS_LANE_PARAM_UNIT extends Structure {
		public PU_ITS_LANE_INFO_BASE_UNIT stLaneInfoBaseU; // Basic lane information.
		public PU_ITS_SPEED_LIMIT stSpeedLimit; // Speed limit configuration.
		public BOOL bRegulationRecord; // Indicates whether to enable the violation recording function.
		public int iExterLampBitMap; // Bitmap associated with an external illuminator.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_LANE_PARAM_UNIT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stLaneInfoBaseU", "stSpeedLimit", "bRegulationRecord", "iExterLampBitMap",
					"szReserve");
		}
	}

	// Traffic light arrangement mode.
	public interface PU_ITS_LIGHT_ARRANGE_TYPE_S {
		int ITS_LIGHT_ARRANGE_TYPE_BROADWISE = 0; /* Horizontal. */
		int ITS_LIGHT_ARRANGE_TYPE_ENDWISE = 1; /* Vertical. */
		int ITS_LIGHT_ARRANGE_TYPE_UNKOWN = 2;
	}

	// Traffic light color.
	public static class PU_ITS_LIGHT_COLOR extends Structure {
		public BOOL bRed; // Red light.
		public BOOL bGreen; // Green light.
		public BOOL bYellow; // Yellow light.

		public PU_ITS_LIGHT_COLOR() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bRed", "bGreen", "bYellow");
		}
	}

	// Traffic light direction.
	public static class PU_ITS_LIGHT_DIR extends Structure {
		public BOOL bLeft; // Turn-left.
		public BOOL bStraight; // Straight-through.
		public BOOL bRight; // Turn-right.

		public PU_ITS_LIGHT_DIR() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bLeft", "bStraight", "bRight");
		}
	}

	// Traffic light access mode.
	public interface PU_ITS_LIGHT_DT_TYPE_S {
		int ITS_LIGHT_DT_TYPE_485 = 0; // RS-485 access.
		int ITS_LIGHT_DT_TYPE_VIDEO = 1; // Video access.
		int ITS_LIGHT_DT_TYPE_UNKNOW = 2;
	}

	// Maximum number of ITS traffic light areas.
	public static class PU_ITS_MANUAL_SNAPSHOT_PARA extends Structure {
		public ULONG ulSnapNum; // ???????,????MAX_BURST_SHOOTING_NUM (??????1,???????Ч)
		public ULONG[] aulSnapInterval = new ULONG[MAX_BURST_SHOOTING_NUM - 1]; // ?????(ms)
																				// ??Χ[MIN_ITS_SNAPSHOT_INTERVAL,
																				// MAX_ITS_SNAPSHOT_INTERVAL]
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSnapNum", "aulSnapInterval", "szReserved");
		}
	}

	// ITS manual snapshot parameters.
	public static class PU_ITS_MANUAL_SNAPSHOT_PARA_S extends Structure {
		public ULONG ulSnapNum; // Maximum number of snapshots (MAX_BURST_SHOOTING_NUM). Currently, only one
								// snapshot is supported.
		public ULONG[] aulSnapInterval = new ULONG[MAX_BURST_SHOOTING_NUM - 1]; // Snapshot interval, in milliseconds.
																				// The value ranges from
																				// MIN_ITS_SNAPSHOT_INTERVAL to
																				// MAX_ITS_SNAPSHOT_INTERVAL.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ITS_MANUAL_SNAPSHOT_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSnapNum", "aulSnapInterval", "szReserved");
		}
	}

	public interface PU_ITS_PIC_SYNTHESIS_TYPE {
		int ITS_TYPE_EPOLICE_PIC_SYNTHESIS = 0; // ePolice.
		int ITS_TYPE_TGATEWAY_PIC_SYNTHESIS = 1; // Checkpoint.
		int ITS_TYPE_PIC_SYNTHESIS_MAX = 2;
	}

	public interface PU_ITS_POS_BOX_TYPE_E {
		int ITS_POS_BOX_TYPE_BIG = 0;
		int ITS_POS_BOX_TYPE_MID = 1;
		int ITS_POS_BOX_TYPE_SMALL = 2;
	}

	// TransMicrowave multi-lane radar configuration.
	public static class PU_ITS_RADA_CTRL_CSRIM_S extends Structure {
		// C type PU_ITS_SERIAL_PORT_E
		public int enSerialPortId; // Serial port number.
		public ULONG uiRoadEnable; // Indicates whether to enable the detection for the lane.
		public ULONG uiLaneId; // Lane ID. The value 1 indicates that lane 1 is enabled, and the rest may be
								// deduced by analogy.
		public ULONG uiLaneIdBase; // Start lane ID.
		public ULONG uiLaneNum; // Number of lanes.
		public ULONG[] uiLaneWidth = new ULONG[4]; // Lane width. The value is in centimeters in the web configurations
													// and is converted into meters in actual scenarios.
		public ULONG uiTrigMinInterval; // Minimum triggering distance. The value is in centimeters in the web
										// configurations and is converted into meters in actual scenarios.
		public ULONG uiInstallHeight; // Installation height. The value is in centimeters in the web configurations
										// and is converted into meters in actual scenarios.
		public NativeLong iInstallHOffset; // Offset between the radar irradiation point and the lane center. The value
											// is in centimeters in the web configurations and is converted into meters
											// in actual scenarios.
		// If the radar irradiation point is on the left of the lane center, the offset
		// is a negative integer. If the radar irradiation point is on the right of the
		// lane center, the offset is a positive integer.
		public NativeLong iDeflectionAngle; // Angle between the radar irradiation direction and a lane.
		// If the radar irradiation direction deviates leftward, the value is a negative
		// integer. If the radar irradiation direction deviates rightward, the value is
		// a positive integer.
		public ULONG uiSensitivity; // Radar sensitivity.
		public ULONG uiSensitiveBase; // Radar sensitivity base.
		public ULONG uiTrigMinSpeed; // Minimum speed (km/h). If the vehicle movement speed is lower than this value,
										// radar detection is not triggered.
		public ULONG uiTrigMaxSpeed; // Maximum speed (km/h). If the vehicle movement speed is higher than this
										// value, the maximum speed is reported.
		// C type PU_ITS_DETECT_DIR_E
		public int eDetectDir; // Detection direction filtering.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_RADA_CTRL_CSRIM_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSerialPortId", "uiRoadEnable", "uiLaneId", "uiLaneIdBase", "uiLaneNum",
					"uiLaneWidth", "uiTrigMinInterval", "uiInstallHeight", "iInstallHOffset", "iDeflectionAngle",
					"uiSensitivity", "uiSensitiveBase", "uiTrigMinSpeed", "uiTrigMaxSpeed", "eDetectDir", "szReserve");
		}
	}

	// Radar information sending mode.
	public interface PU_ITS_RADAR_MSG_SENDTYPE_E {
		int ITS_RADAR_MSG_SEND_SINGLE = 0; // Single (messages are reported when a vehicle passes).
		int ITS_RADAR_MSG_SEND_CONTINOUS = 1; // Continuous (messages are reported regardless of whether a vehicle
												// passes).
		int ITS_RADAR_MSG_SEND_MANUAL = 2; // Manual (one message is reported for one query).
	}

	// Radar type.
	public interface PU_ITS_RADAR_WORK_TYPE_E {
		int ITS_RADAR_TYPE_SINGLE_DIR_DETECT = 0; // Unidirectional detection.
		int ITS_RADAR_TYPE_DOUBLE_DIR_DETECT = 1; // Bidirectional detection.
	}

	// Violation snapshot mode (single-shutter or dual-shutter).
	public interface PU_ITS_REGULA_SNAP_TYPE {
		int PU_ITS_REGULA_SNAP_SINGLE_SHUTTER = 0; // Single-shutter.
		int PU_ITS_REGULA_SNAP_DOUBLE_SHUTTER = 1; // Dual-shutter.
		int PU_ITS_REGULA_SNAP_TYPE_MAX = 2;
	}

	// Violation type.
	public interface PU_ITS_REGULA_TYPE_E {
		int ITS_REGULA_NULL = 0; /* No violation, initial value */
		int ITS_REGULA_PASS_SNAP = 1; /* Checkpoint snapshot. */
		int ITS_REGULA_RUNNINGRED = 2; /* Red light running (1625). */
		int ITS_REGULA_EXCEET_SPEED = 3; /* Speeding */
		int ITS_REGULA_UNDER_SPEED = 4; /* Low-speed (4306). */
		int ITS_REGULA_WRONG_DIRECTION = 5; /*
											 * Not following lane markings, including
											 * left-turn/straight-through/right-turn (1208).
											 */
		int ITS_REGULA_REVERSE_DIRECTION = 6; /* Wrong-way driving (1301). */
		int ITS_REGULA_LICENCE_RESTRICTE = 7; /* End-number policy violation. */
		int ITS_REGULA_OVER_LANE_LINE = 8; /* Marked lanes violation (1345). */
		int ITS_REGULA_CHANGE_LANE = 9; /* Unsafe lane change (13453). */
		int ITS_REGULA_MOTOR_IN_BICYCLE_LANE = 10; /* Motor vehicles on non-motor vehicle lanes (1018). */
		int ITS_REGULA_ACCOMMODATION_LANE = 11; /* Exclusive lane violation (1019). */
		int ITS_REGULA_PROHIBITION = 12; /* Prohibitory traffic sign violation (1344). */
		int ITS_REGULA_REMAIN_CROSS = 13; /* Stop at intersections (1228). */
		int ITS_REGULA_STOP_LIGHT_GREEN = 14; /* Parking at green light (16251). */
		int ITS_REGULA_EMERGENCY = 15; /* Emergency lane violation */
		int ITS_REGULA_SAFETY_BELT = 16; /* Seat belt infraction (1240). */
		int ITS_REGULA_U_TURN = 17; /* Illegal U-turn (1044). */
		int ITS_REGULA_PORT_VEHICLE_DRIVER_CALL = 18; /*
														 * Hands-free device infraction (driver), triggered by
														 * checkpoint devices.
														 */
		int ITS_REGULA_PORT_VEHICLE_COPILOT_NO_BELT = 19; /*
															 * Seat belt infraction (front passenger), triggered by
															 * checkpoint devices.
															 */
		int ITS_REGULA_PORT_VEHICLE_NO_YEAR_LOG = 20; /*
														 * No annual inspection sticker, triggered by checkpoint
														 * devices.
														 */
		int ITS_REGULA_ILLEGAL_PARKING = 21; /* Parking in the yellow zone. */
		int ITS_REGULA_IMPOLITE_PEDESTRIANS = 22; /* Vehicles that fail to give right-of-way to pedestrians. */
		int ITS_REGULA_OCCUPANCY_BUSLANE = 23; /* Bus lane violation. */
		int ITS_REGULA_LARGER_VEHICLE_OUTOFLANE = 24; /* Driving large vehicles on a prohibited lane. */
		int ITS_REGULA_IBALL_ILLEGAL_PARKING = 25; /* Parking violation. */
		int ITS_REGULA_VEHICLEBAN = 26; /* Prohibitory traffic sign violation. */
		int ITS_REGULA_NOVEHICLE_IN_LANE = 27; /* Non-motor vehicles driving on motor vehicle lanes. */
		int ITS_REGULA_RECOGNIZE_ONLY = 30; /*
											 * ePolice six-in-one function. This enumeration parameter is used when
											 * traffic flow only needs to be recognized and metadata does not need to be
											 * uploaded.
											 */
		int ITS_REGULA_ALL = 31; /* The kernel stack space allows at most 32 traffic violations. */
		int ITS_REGULA_BUTT = 32;

	}

	// Additional parameters for snapshots of motor vehicles driving on non-motor
	// vehicle lanes.
	public static class PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S extends Structure {
		public int nStayTime; // Dwell duration, ranging from 0 to 180 milliseconds.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("nStayTime", "szReserve");
		}
	}

	// Additional parameters for marked lanes violation snapshots.
	public static class PU_ITS_REGULATION_CFG_ATTCH_PRESS_LINE_UNIT_S extends Structure {
		public int nSensitivity; // Marked lanes violation detection sensitivity (0-100 ms).

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_REGULATION_CFG_ATTCH_PRESS_LINE_UNIT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("nSensitivity", "szReserve");
		}
	}

	public static class PU_ITS_REGULATION_CFG_ATTCH_UNIT_S extends Union {
		public PU_ITS_RUNLIGHT_PARA_S stRunningRed; // Running-red-light snapshot parameter (ITS_REGULA_RUNNINGRED),
													// which is a reserved field.

		public PU_ITS_REGULATION_CFG_ATTCH_PRESS_LINE_UNIT_S stPressLine; // Marked lanes violation
																			// (ITS_REGULA_OVER_LANE_LINE).
		public PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S stInvadeDriverWay; // Motor vehicles driving on
																						// non-motor vehicle lanes
																						// (ITS_REGULA_MOTOR_IN_BICYCLE_LANE).
		public PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S stInvadeBusLane; // Bus lane violation
																					// (ITS_REGULA_OCCUPANCY_BUSLANE).
		public PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S stIllegalParkTime; // Parking in yellow zones
																						// (ITS_REGULA_ILLEGAL_PARKING).
		public PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S stImpolitePedestriansTime;// Pedestrian waiting time.
		/*
		 * @Override protected List<String> getFieldOrder() { return
		 * Arrays.asList("stRunningRed","stPressLine","stInvadeDriverWay",
		 * "stInvadeBusLane", "stIllegalParkTime","stImpolitePedestriansTime"); }
		 */

		public PU_ITS_REGULATION_CFG_ATTCH_UNIT_S() {
			this.setAlignType(ALIGN_NONE);
		}
	}

	/* Time period during which the end-number policy is used. */
	public static class PU_ITS_RESTRICTED_DATA extends Structure {
		public int enIndexType; // Index mode, by date end number or by weekday. C type is
								// PU_ITS_RESTRICTED_INDEX_TYPE_E

		public WinDef.BOOL[] abRestrictedU = new WinDef.BOOL[MAX_RESTRICTED_DATE_NUM]; // Indicates whether to enable
																						// the end-number policy. If the
																						// end-number policy is
																						// implemented by weekday, there
																						// are seven options. If the
																						// end-number policy is
																						// implemented by date end
																						// number, there are 10 options.
		public ULONG ulStartTime; // Start time for implementing the end-number policy.
		public ULONG ulEndTime; // End time for implementing the end-number policy.

		public PU_ITS_RESTRICTED_DATA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enIndexType", "abRestrictedU", "ulStartTime", "ulEndTime");
		}
	}

	/* Structure of a restriction item of the end-number policy. */
	public static class PU_ITS_RESTRICTED_PARA_UNIT extends Structure {
		public WinDef.BOOL[] abRestrictedNum = new WinDef.BOOL[MAX_RESTRICTED_NUM]; /*
																					 * End number that is restricted.
																					 * The value ranges from 0 to 9.
																					 */

		public PU_ITS_RESTRICTED_DATA stRestrictedDate; // Restricted date and time segment.
		public PU_ITS_RESTRICTED_REGION[] astLocalPlate = (PU_ITS_RESTRICTED_REGION[]) new PU_ITS_RESTRICTED_REGION()
				.toArray(MAX_RESTRICTED_LOCALPLATE_NUM); // Local license plate.
		public WinDef.BOOL[] abLocalRestrictedNum = new WinDef.BOOL[MAX_RESTRICTED_NUM]; // Local end number that is
																							// restricted. The value
																							// ranges from 0 to 9.
		public WinDef.BOOL[] abNonLocalRestrictedNum = new WinDef.BOOL[MAX_RESTRICTED_NUM]; // External end number that
																							// is restricted. The value
																							// ranges from 0 to 9.

		public PU_ITS_RESTRICTED_PARA_UNIT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("abRestrictedNum", "stRestrictedDate", "astLocalPlate", "abLocalRestrictedNum",
					"abNonLocalRestrictedNum");
		}
	}

	/* Structure of total restriction items of the end-number policy. */
	public static class PU_ITS_RESTRICTED_PARAM extends Structure {
		public ULONG ulChannelId; // Channel ID.

		public int iRestrictedNum; // Number of items configured for the end-number policy.
		public PU_ITS_RESTRICTED_PARA_UNIT[] astRestricteds = (PU_ITS_RESTRICTED_PARA_UNIT[]) new PU_ITS_RESTRICTED_PARA_UNIT()
				.toArray(MAX_RESTRICTED_EVENT_NUM); // 尾号限行项总数
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_ITS_RESTRICTED_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "iRestrictedNum", "astRestricteds", "szReserved");
		}
	}

	/* Local license plate restricted based on the end-number policy. */
	public static class PU_ITS_RESTRICTED_REGION extends Structure {
		public byte[] aucLocalPlate = new byte[MAX_RESTRICTED_LOCALPLATE_LEN]; // Local license plate.

		public PU_ITS_RESTRICTED_REGION() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("aucLocalPlate");
		}
	}

	// Lane attribute.
	public interface PU_ITS_ROAD_ATTRIBUTE_E {
		int ITS_ROAD_HIGHWAY = 0; // Highway.
		int ITS_ROAD_EXPRESSWAY = 1; // Urban freeway.
		int ITS_ROAD_OTHER = 2; // Others.
	}

	// Direction ID.
	public interface PU_ITS_ROAD_DIR_TYPE_E {
		int ITS_ROAD_UNKNOW = 0; // Unknown.
		int ITS_ROAD_EAST_TO_WEST = 1; // From east to west.
		int ITS_ROAD_WEST_TO_EAST = 2; // From west to east.
		int ITS_ROAD_SOUTH_TO_NORTH = 3; // From south to north.
		int ITS_ROAD_NORTH_TO_SOUTH = 4; // From north to south.
		int ITS_ROAD_ES_TO_WN = 5; // From southeast to northwest.
		int ITS_ROAD_WN_TO_ES = 6; // From northwest to southeast.
		int ITS_ROAD_EN_TO_WS = 7; // From northeast to southwest.
		int ITS_ROAD_WS_TO_EN = 8; // From southwest to northeast.
	}

	// Lane direction.
	public interface PU_ITS_ROAD_DRV_DIR_E {
		int ITS_ROAD_DRV_DIR_UNKNOW = 0; // Unknown.
		int ITS_ROAD_DRV_DIR_LEFT = 1; // Turn-left.
		int ITS_ROAD_DRV_DIR_STRAIGHT = 2; // Straight-through.
		int ITS_ROAD_DRV_DIR_LFT_STR = 3; // Turn-left + Straight-through.
		int ITS_ROAD_DRV_DIR_RIGHT = 4; // Turn-right.
		int ITS_ROAD_DRV_DIR_RHT_LFT = 5; // Turn-right + Turn-left.
		int ITS_ROAD_DRV_DIR_RHT_STR = 6; // Turn-right + Straight-through.
		int ITS_ROAD_DRV_DIR_RHT_STR_LFT = 7; // Turn-right + Turn-left + Straight-through.
		int ITS_ROAD_DRV_DIR_LFT_WAIT = 8; // Waiting to turn left.
	}

	// Lane usage.
	public interface PU_ITS_ROAD_PURPOSE_E {
		int ITS_UNKNOW_ROAD = 0; // Unknown.
		int ITS_COMMON_ROAD = 1; // Common lane.
		int ITS_BUS_ROAD = 2; // Bus lane.
		int ITS_FAST_ROAD = 3; // Fast lane.
		int ITS_SLOW_ROAD = 4; // Slow lane.
		int ITS_MOTOR_ROAD = 5; // Motorcycle lane.
		int ITS_NONMOTOR_ROAD = 6; // Non-motor vehicle lane.
		int ITS_REVERSE_ROAD = 7; // Opposite lane.
		int ITS_FORBIT_BIGCAR_ROAD = 8; // No-large-vehicle lane.
		int ITS_EMERGENCY = 9; // Emergency lane.
	}

	/********** BEGIN: ITS external device parameters **********/
	// Baud rate.
	public interface PU_ITS_RS_BAUD_E {
		int ITS_RS_BAUD_B2400 = 0;
		int ITS_RS_BAUD_B4800 = 1;
		int ITS_RS_BAUD_B9600 = 2;
		int ITS_RS_BAUD_B19200 = 3;
		int ITS_RS_BAUD_B38400 = 4;
		int ITS_RS_BAUD_B57600 = 5;
		int ITS_RS_BAUD_B115200 = 6;
		int ITS_RS_BAUD_B230400 = 7;
		int ITS_RS_BAUD_B460800 = 8;
		int ITS_RS_BAUD_B921600 = 9;
		int ITS_RS_BAUD_MAX = 10;
	}

	// Data bit.
	public interface PU_ITS_RS_CSIZE_E {
		int ITS_RS_CSIZE_CS5 = 0;
		int ITS_RS_CSIZE_CS6 = 1;
		int ITS_RS_CSIZE_CS7 = 2;
		int ITS_RS_CSIZE_CS8 = 3;
		int ITS_RS_CSIZE_MAX = 4;
	}

	// Flow control.
	public interface PU_ITS_RS_FLOWCTL_E {
		int ITS_RS_FLOWCTL_NONE = 0;
		int ITS_RS_FLOWCTL_SW = 1;
		int ITS_RS_FLOWCTL_HW = 2;
		int ITS_RS_FLOWCTL_MAX = 3;
	}

	// Serial port parameter structure.
	public static class PU_ITS_RS_PARA_S {
		public PU_ITS_RS_BAUD_E RS485Baud;
		public PU_ITS_RS_CSIZE_E RS485CSize;
		public PU_ITS_RS_STOPBIT_E RS485StopBit;
		public PU_ITS_RS_PARITY_E RS485Parity;
		public PU_ITS_RS_FLOWCTL_E RS485FlowCtl;

	}

	// Parity bit.
	public interface PU_ITS_RS_PARITY_E {
		int ITS_RS_PARITY_NONE = 0;
		int ITS_RS_PARITY_ODD = 1;
		int ITS_RS_PARITY_EVEN = 2;
		int ITS_RS_PARITY_MARK = 3;
		int ITS_RS_PARITY_SPACE = 4;
		int ITS_RS_PARITY_MAX = 5;
	}

	// Stop bit.
	public interface PU_ITS_RS_STOPBIT_E {
		int ITS_RS_STOPBIT_ONE = 0;
		int ITS_RS_STOPBIT_TWO = 1;
		int ITS_RS_STOPBIT_MAX = 2;
	}

	// Traffic light violation parameters.
	public static class PU_ITS_RUNLIGHT_PARA_S extends Structure {
		public int enRunLightPriority; // Priority. c type:PU_ITS_RUNLIGHT_PRIORITY_E

		public int enRunLightRule; // Violation rule. c type:PU_ITS_RUNLIGHT_RULE_E
		public int iSecondSnapOffset; // Offset for the second snapshot.
		public int iPicMinOffset; // Minimum image offset.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_RUNLIGHT_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enRunLightPriority", "enRunLightRule", "iSecondSnapOffset", "iPicMinOffset",
					"szReserve");
		}
	}

	// Traffic light violation priority.
	public interface PU_ITS_RUNLIGHT_PRIORITY_E {
		int ITS_RUNLIGHT_NONE_PRIORITY = 0; // None.
		int ITS_RUNLIGHT_RED_PRIORITY = 1; // Running-red-light priority.
	}

	// Traffic light violation rule.
	public interface PU_ITS_RUNLIGHT_RULE_E {
		int ITS_RUNLIGHT_BYLANE = 0; // By lane.
		int ITS_RUNLIGHT_BYDIR = 1; // By direction.
	}

	// Serial port number.
	public interface PU_ITS_SERIAL_PORT_E {
		int SERIAL_PORT_485_1 = 0; // 485-1
		int SERIAL_PORT_232_1 = 1; // 485-2
		int SERIAL_PORT_485_2 = 2; // 232-1
		int SERIAL_PORT_485_3 = 3; // 485-3
		int ITS_SERIAL_PORT_MAX = 255; // No serial port.
	}

	// Traffic light area parameters.
	public static class PU_ITS_SIGNAL_LIGHT_AREA_PARAM extends Structure {
		public PU_ITS_LIGHT_DIR stLightDir; // Traffic light direction.
		public PU_ITS_LIGHT_COLOR stLightColor; // Traffic light color.
		public int iLightNum; // Number of traffic lights.
		// C type :PU_ITS_LIGHT_ARRANGE_TYPE_E
		public int enLightArrangeType; // Traffic light installation mode.
		public int iYellowTime; // Yellow light duration.
		public PU_MD_AREA stLightArea; // Traffic light location.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // szReserve[0] indicates whether to enable drawing and
															// szReserve[1] indicates whether to enable selection.

		public PU_ITS_SIGNAL_LIGHT_AREA_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stLightDir", "stLightColor", "iLightNum", "enLightArrangeType", "iYellowTime",
					"stLightArea", "szReserve");
		}
	}

	// Traffic light simulation parameters in ePolice mode.
	public static class PU_ITS_SIM_TRAFFIC_LIGHT_PARAM extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public BOOL bLeftTurn; // Left-turn traffic light.
		public BOOL bRightTurn; // Right-turn traffic light.
		public BOOL bGoStraight; // Straight-through traffic light.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_SIM_TRAFFIC_LIGHT_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bLeftTurn", "bRightTurn", "bGoStraight", "szReserve");
		}
	}

	// Snapshot interval detection mode.
	public interface PU_ITS_SNAP_INTERVAL_TYPE {
		int PU_ITS_SNAP_INTERVAL = 0; // Fixed snapshot interval.
		int PU_ITS_ADAPTIVE_SNAP_INTERVAL = 1; // Adaptive snapshot interval.
		int PU_ITS_SNAP_INTERVAL_TYPE_MAX = 2;
	}

	// ITS image query parameters.
	public static class PU_ITS_SNAPSHOT_INQUIRE extends Structure {
		public ULONG ulChnID;
		public ULONG ulBeginIndex; // Start record index (≥ 1).
		public ULONG ulBeginTime; // Start time (time_t/localTime = GMT + time zone).
		public ULONG ulEndTime; // End time.
		// C Type : PU_SNAPSHOT_TYPE_E
		public int enSnapShotType; // Snapshot type.
		public ULONG ulLaneID;// Lane ID.
		// C Type :PU_VEHICLE_TYPE_E
		public int enVehicleType; // Vehicle type.
		// C Type : PU_ITS_REGULA_TYPE_E
		public int enVehicleRegulationType; // Violation type.
		public ULONG ulRegulationRecordTime; // Violation recording length.
		public BOOL bOnceInquireFlag; // Indicates whether to display search results on one page. The value TRUE
										// indicates that search results are displayed on one page.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ITS_SNAPSHOT_INQUIRE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulBeginIndex", "ulBeginTime", "ulEndTime", "enSnapShotType", "ulLaneID",
					"enVehicleType", "enVehicleRegulationType", "ulRegulationRecordTime", "bOnceInquireFlag",
					"szReserved");
		}
	}

	// Speed limit.
	public static class PU_ITS_SPEED_LIMIT extends Structure {
		public int iNormalSignSpeed; // Marked speed for small vehicles (0 to 255 km/h).

		public int iNormalLowSpeed; // Lowest speed for small vehicles (0 to 255 km/h).
		public int iNormalHighSpeed; // Highest speed for small vehicles (0 to 255 km/h).
		public int iBigVehicleSignSpeed; // Marked speed for large vehicles (0 to 255 km/h).
		public int iBigVehicleLowSpeed; // Lowest speed for large vehicles (0 to 255 km/h).
		public int iBigVehicleHighSpeed; // Highest speed for large vehicles (0 to 255 km/h).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_SPEED_LIMIT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("iNormalSignSpeed", "iNormalLowSpeed", "iNormalHighSpeed", "iBigVehicleSignSpeed",
					"iBigVehicleLowSpeed", "iBigVehicleHighSpeed", "szReserve");
		}
	}

	// Speed estimation configuration.
	public static class PU_ITS_SPEED_MEASURE_PARAM extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int iCameraHeightH; // Height between the camera and the ground (H).
		public int iImageBottom2CameraL1; // Distance from FoV lower edge to ground edge (L1).
		public int iImageCenter2CameraL2; // Distance from FoV center to ground edge (L2).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ITS_SPEED_MEASURE_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "iCameraHeightH", "iImageBottom2CameraL1", "iImageCenter2CameraL2",
					"szReserve");
		}
	}

	// Signalway TL-01-8 traffic light signal detector.
	public static class PU_ITS_XLW_DETECTOR_INFO_S extends Structure {
		public ULONG uiTotalNum; // Total number of ports.
		public ULONG uiLeftLightNo; // Left-turn light ID.
		public ULONG uiStraitLightNo; // Straight-through light ID.
		public ULONG uiRightLightNo; // Right-turn light ID.
		public ULONG uiTurnRoundLightNo; // U-turn light ID.

		public PU_ITS_XLW_DETECTOR_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiTotalNum", "uiLeftLightNo", "uiStraitLightNo", "uiRightLightNo",
					"uiTurnRoundLightNo");
		}
	}

	// I- or P-frame encoding policy.
	public static class PU_KF_CODING_STRATEGY_PARA extends Structure {
		public ULONG ulChnID;
		public WinDef.BOOL bEnable;
		public int enStreamType; // c type:PU_STREAM_TYPE
		public ULONG ulLevel;

		public PU_KF_CODING_STRATEGY_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "enStreamType", "ulLevel");
		}
	}

	// Illuminator control mode.
	public interface PU_LAMP_CTRL_MODE {
		public static final int LAMP_CTRL_MODE_AUTO = 0; // Automatic.
		public static final int LAMP_CTRL_MODE_MANUAL = 1; // Manual.
	}

	// Lane attribute parameters.
	public static class PU_LANE_ATTR_PARA extends Structure {
		public int enLanePurpose; // Lane type/usage.
		public int enLaneDirection; // Lane direction.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enLanePurpose", "enLaneDirection");
		}
	}

	// Language type. c type:PU_LANGUAGE_TYPE
	public interface PU_LANGUAGE_TYPE {
		public static final int PU_LANGUAGE_TYPE_CHINESE = 0; // Chinese
		public static final int PU_LANGUAGE_TYPE_ENGLISH = 1; // English
		public static final int PU_LANGUAGE_TYPE_MAX = 2;
	}

	// Lens information.
	public static class PU_LENS_INFO_S extends Structure {
		public ULONG ulChnID;
		public PU_PRECISE_FIGURES_S stLZoomRatio; // Lens zoom.
		public PU_PRECISE_FIGURES_S stDZoomRatio; // Digital zoom.
		public PU_PRECISE_FIGURES_S stHorDegree; // Horizontal field of view.
		public PU_PRECISE_FIGURES_S stVerDegree; // Vertical field of view.
		public PU_PRECISE_FIGURES_S stFocalMillimeter; // Focal length.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_LENS_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "stLZoomRatio", "stDZoomRatio", "stHorDegree", "stVerDegree",
					"stFocalMillimeter", "szReserved");
		}
	}

	/* Lens type. */
	public interface PU_LENS_TYPE {
		public static final int PU_LENS_TYPE_SA = 0; // Fuji lens(DV3.4x3.8SA-SA1L)
		public static final int PU_LENS_TYPE_SE = 1; // Fuji lens(D8x7.8A-SE2N)
	}

	/* Licence file upload. */
	public static class PU_LICENCE_FILE_UPLOAD_S extends Structure {
		/* C type : PU_LICENCE_UPLOAD_TYPE_E */
		public int enLicenceType; // Upload type.
		public byte[] szLicenceFile = new byte[PU_CONFIG_FILE_PATH_MAX]; // File path.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enLicenceType", "szLicenceFile");
		}
	}

	/* License file upload type. */
	public interface PU_LICENCE_UPLOAD_TYPE_E {
		int PU_LICENCE_ITGT_UPLOAD_TYPE = 0;
		int PU_LICENCE_OTHER_UPLOAD_TYPE = 1;
		int PU_LICENCE_UPLOAD_TYPE_MAX = 2;
	}

	public static class PU_LICENSE_INFO extends Structure {
		/* C Type : PU_LICENSE_TYPE_E */
		public int emLicenseType; // Algorithm license type.
		public byte[] FileName = new byte[128]; // Licnese File path.

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("emLicenseType", "FileName", "szReserve");
		}
	}

	public interface PU_LICENSE_TYPE_E {
		int PU_LICENSE_TYPE_IGTALTHM = 0; // Intelligent algorithm license.
		int PU_LICENSE_TYPE_MAX = 1;
	}

	// Traffic light detector information.
	public static class PU_LIGHT_DETECTOR_INFO_S extends Structure {
		// C type PU_EXTRA_DEVICE_TYPE_E
		public int enDeviceProtelType; // Protocol type of the external device.
		public ULONG uiLightRoadEnable; // Indicates whether to enable the external device.
		public ULONG uiLightLaneId; // ID of the lane covered by the external device. The value 1 indicates that
									// detection for lane 1 is enabled, and the rest may be deduced by analogy.
		// C type PU_ITS_SERIAL_PORT_E
		public int enLightSerialPortId; // Serial port number used by the external device.
		public PU_ITS_RS_PARA_S stLightDevSerialCfg; // Serial port configuration.
		public PU_ITS_XLW_DETECTOR_INFO_S stCfgLightDetector; // Signalway TL-01-8 traffic light signal detector.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_LIGHT_DETECTOR_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDeviceProtelType", "uiLightRoadEnable", "uiLightLaneId", "enLightSerialPortId",
					"stLightDevSerialCfg", "stCfgLightDetector", "szReserve");
		}
	}

	// PU registration mode.
	public interface PU_LINK_MODE {
		public static final int PU_AUTOLOGIN_MODE = 0; // Proactive login mode. After the initialization, the PU
														// proactively logs in to the SDK. Only the decoder supports
														// this mode.
		public static final int PU_MANUALLOGIN_MODE = 1; // In manual login mode, you need to manually invoke the
															// IVS_PU_Login to log in to the PU.
		public static final int PU_BOTHLOGIN_MODE = 3; // The preceding two login modes are supported only by SDCs.
		public static final int PU_LINK_MODE_MAX = 4;
	}

	public static class PU_LOCAL_RECORD extends Structure {
		public ULONG ulChannelId; // Recording channel.
		public ULONG ulAction; // Start or stop recording. The options are as follows: 0: stop; other digits:
								// start.
		public PU_RECORD_TYPE enRecordType; // Recording mode. PU_RECORD_TYPE
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_LOCAL_RECORD() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulAction", "enRecordType", "szReserved");
		}
	}

	;

	/* PU-based recording plan. */
	public static class PU_LOCAL_RECORD_PLAN extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable scheduled recording.
		public ULONG ulChannelID; // Channel ID.
		public ULONG ulTotalNum; // Total number of records.
		public ULONG ulBeginIndex; // Start record index.
		public ULONG ulEndIndex; // End record index.
		public PU_TIME_PLAN_LIST[] szRecordPlanList = (PU_TIME_PLAN_LIST[]) new PU_TIME_PLAN_LIST()
				.toArray(PU_RECORD_PLAN_NUM_SD);// Recording plan list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_LOCAL_RECORD_PLAN() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulChannelID", "ulTotalNum", "ulBeginIndex", "ulEndIndex",
					"szRecordPlanList", "szReserved");
		}
	}

	// log type.
	public interface PU_LOG_TYPE {
		public static final int PU_LOG_TYPE_OPERATION = 1; // Operation log.
		public static final int PU_LOG_TYPE_EXCEPT = 2; // Error log.
		public static final int PU_LOG_TYPE_ALARM = 3; // Alarm log.
		public static final int PU_LOG_TYPE_MAX = 4;
	}

	// License plate color.
	public interface PU_LPR_PLATE_COLOR {
		public static final int PU_LPR_LC_UNKNOWN = 0; // Unknown.
		public static final int PU_LPR_LC_BLUE = 1; // Blue.
		public static final int PU_LPR_LC_YELLOW = 2; // Yellow.
		public static final int PU_LPR_LC_WHITE = 3; // White.
		public static final int PU_LPR_LC_BLACK = 4; // Black.
		public static final int PU_LPR_LC_GREEN = 5; // Green.
		public static final int PU_LPR_LC_GRADIENT_GREEN = 6;// Black text on gradient green background.
		public static final int PU_LPR_LC_YELLOW_GREEN = 7;// Black text on yellow and green background.
	}

	// License plate type.
	public interface PU_LPR_PLATE_TYPE {
		public static final int PU_LPR_PLT_UNKNOWN = 0; // Unknown.
		public static final int PU_LPR_PLT_NORMBLUE = 1; // Single-layer blue plate.
		public static final int PU_LPR_PLT_NORMBLACK = 2; // Single-layer black plate.
		public static final int PU_LPR_PLT_NORMYELLOW = 3; // Single-layer yellow plate.
		public static final int PU_LPR_PLT_DBLYELLOW = 4; // Double-layer yellow plate.
		public static final int PU_LPR_PLT_POLICE = 5; // White plate for police.
		public static final int PU_LPR_PLT_WJ = 6; // White plate for armed police.
		public static final int PU_LPR_PLT_DBLWJ = 7; // Double-layer white plate for armed police.
		public static final int PU_LPR_PLT_ARMY = 8; // Single-layer plate for military.
		public static final int PU_LPR_PLT_DBLARMY = 9; // Double-layer plate for military.
		public static final int PU_LPR_PLT_EMBASSY = 10; // Plate for embassy vehicles.
		public static final int PU_LPR_PLT_HK = 11; // Hong Kong plate.
		public static final int PU_LPR_PLT_MACAU = 13; // Macau plate.
		public static final int PU_LPR_PLT_AGRICULTURE = 14; // Agricultural conveyance plate (tractor).
		public static final int PU_LPR_PLT_CHANGNEI = 15; // Factory plate.
		public static final int PU_LPR_PLT_INDIVI = 16; // Personalized plate.
		public static final int PU_LPR_PLT_NEWNENRGY = 17; // Plate for new-energy vehicles.
		public static final int PU_LPR_PLT_OTHER = 18; // Others.
		public static final int PU_VLPR_LPT_INA_PRIVATE = 100; // Plate for Indonesian private vehicles.
		public static final int PU_VLPR_LPT_INA_PUBLIC = 101; // Plate for Indonesian public transportation vehicles.
		public static final int PU_VLPR_LPT_INA_EMBASSY = 102; // Plate for Indonesian embassy vehicles.
		public static final int PU_VLPR_LPT_KSA_PRIVATE = 110; // Saudi Arabia plate.
		public static final int PU_VLPR_LPT_HK_PRIVATE = 120; // Hong Kong plate.
	}

	public static class PU_MANAGE_3RD_APP_INFO extends Structure {
		public int uiValidCount; // Number of valid algorithm apps.
		public PU_3RD_APP_BASIC_INFO[] ast3RdAppInfo = (PU_3RD_APP_BASIC_INFO[]) new PU_3RD_APP_BASIC_INFO()
				.toArray(PU_3RD_APP_MAX_NUM); // Third-party algorithm app information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiValidCount", "ast3RdAppInfo", "szReserved");
		}
	}

	/************** Manual defogging ****************/
	public static class PU_MANAUL_DEFOG_ENABLE_S extends Structure {
		public WinDef.BOOL bEnable;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szReserved");
		}
	}

	// Parameters for manual license plate snapshot.
	public static class PU_MANUAL_LPR_CAPTURE_S extends Structure {
		public ULONG ulSnapNum;
		public ULONG[] aulSnapInterval = new ULONG[MAX_BURST_SHOOTING_NUM - 1];
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MANUAL_LPR_CAPTURE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSnapNum", "aulSnapInterval", "szReserved");
		}
	}

	public static class PU_MANUL_DIALING_S extends Structure {
		// C type DIAL_CONNECT_E
		public int enDialConnect;

		public PU_MANUL_DIALING_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDialConnect");
		}
	}

	// Privacy mask area.
	public static class PU_MASK_AREA_PARA extends Structure {
		public PU_IGT_POINT_S[] stAreaPara = (PU_IGT_POINT_S[]) new PU_IGT_POINT_S().toArray(PRIVACY_AREA_POINTS_NUM);
		public ULONG ulColor; // Color.
		public char ucAlpha; // Transparency. This parameter is not supported currently.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_MASK_AREA_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stAreaPara", "ulColor", "ucAlpha", "szReserve");
		}
	}

	public static class PU_MASK_AREA_PARA_V20 extends Structure {
		public PU_IGT_POINT_S[] stAreaPara = (PU_IGT_POINT_S[]) new PU_IGT_POINT_S().toArray(PRIVACY_AREA_POINTS_NUM);
		public ULONG ulColor;
		public char ucAlpha;
		public ULONG ulIndex;
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_MASK_AREA_PARA_V20() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stAreaPara", "ulColor", "ucAlpha", "szReserve");
		}
	}

	// Privacy mask area.
	public static class PU_MASK_PARA extends Structure {
		public ULONG ulStartX; // X coordinate of the upper left corner of the privacy mask area.
		public ULONG ulStartY; // Y coordinate of the upper left corner of the privacy mask area.
		public ULONG ulWidth;
		public ULONG ulHeight;

		public PU_MASK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartX", "ulStartY", "ulWidth", "ulHeight");
		}
	}

	// Privacy mask area.
	public static class PU_MASK_PARA_EX extends Structure {
		public ULONG ulStartX; // X coordinate of the upper left corner of the privacy mask area.
		public ULONG ulStartY; // Y coordinate of the upper left corner of the privacy mask area.
		public ULONG ulWidth;
		public ULONG ulHeight;
		public ULONG ulColor; // Color.
		public char ucAlpha; // Transparency. This parameter is not supported currently.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_MASK_PARA_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartX", "ulStartY", "ulWidth", "ulHeight", "ulColor", "ucAlpha", "szReserve");
		}
	}

	// User name and password for master and slave camera interactions.
	public static class PU_MASTER_SLAVE_AUTH_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID, which is reserved and not used currently.
		public byte[] szUserName = new byte[PU_USER_NAME_LEN]; // User name.
		public byte[] szUserPwd = new byte[PU_PASSWORD_LEN]; // Password.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MASTER_SLAVE_AUTH_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "szUserName", "szUserPwd", "szReserved");
		}
	}

	// Parameters for querying the master and slave camera calibration status.
	public static class PU_MASTER_SLAVE_CALIBRATION_STATUS extends Structure {
		public ULONG ulGroupID; // ID of the master/slave device association. This parameter is reserved and is
								// not used currently.

		// enStatus C type: PU_CALIBRATION_STATUS_E
		public int enStatus;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MASTER_SLAVE_CALIBRATION_STATUS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulGroupID", "enStatus", "szReserved");
		}
	}

	// Port for communication between the master and slave cameras.
	public static class PU_MASTER_SLAVE_COMMUNICATION_PARA extends Structure {
		public ULONG ulGroupID; // ID of the master/slave device association. This parameter is reserved and is
								// not used currently.
		// enRole C type PU_MASTER_SLAVE_ROLE_E
		public int enRole; // Master/Slave role.
		public int iPort; // Port for communication between the master and slave cameras.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MASTER_SLAVE_COMMUNICATION_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulGroupID", "enRole", "iPort", "szReserved");
		}
	}

	// Master/Slave device association parameter.
	public static class PU_MASTER_SLAVE_GROUP_PARA extends Structure {
		public int iMasterSlaveGroupNum; // Number of master/slave camera combinations.
		public PU_MASTER_SLAVE_PER_GROUP_PARA stGroupPara;
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MASTER_SLAVE_GROUP_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("iMasterSlaveGroupNum", "stGroupPara", "szReserved");
		}
	}

	// Master and slave camera locating parameter.
	public static class PU_MASTER_SLAVE_LOCATE_CONFIG extends Structure {
		public ULONG ulGroupID; // ID of the master/slave device association. This parameter is reserved and is
								// not used currently.
		public WinDef.BOOL bEnable; // Indicates whether to enable PTZ control.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MASTER_SLAVE_LOCATE_CONFIG() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulGroupID", "bEnable", "szReserved");
		}
	}

	public static class PU_MASTER_SLAVE_LOCATE_PARA extends Structure {
		public static class ByReference extends PU_MASTER_SLAVE_LOCATE_PARA implements Structure.ByReference {

		}

		public static class ByValue extends PU_MASTER_SLAVE_LOCATE_PARA implements Structure.ByValue {

		}

		/**
		 * <i>native declaration : include\HWPuSDK.h:11</i>
		 */
		public static class config_union extends Union {
			public static class ByReference extends config_union implements Structure.ByReference {

			}

			public static class ByValue extends config_union implements Structure.ByValue {

			}

			/**
			 * Point-based locating parameter.<br>
			 * C type : PU_POINT_S
			 */
			public PU_POINT stPointLocate;

			/**
			 * Frame-based locating parameter.<br>
			 * C type : PU_RECT_LOCATE_PARA_S
			 */
			public PU_RECT_LOCATE_PARA stRectLocate;

			public config_union() {
				super();
			}

			public config_union(Pointer peer) {
				super(peer);
			}

			/**
			 * @param stPointLocate Point-based locating parameter.<br>
			 *                      C type : PU_POINT_S
			 */
			public config_union(PU_POINT stPointLocate) {
				super();
				this.stPointLocate = stPointLocate;
				setType(PU_POINT.class);
			}

			/**
			 * @param stRectLocate Frame-based locating parameter.<br>
			 *                     C type : PU_RECT_LOCATE_PARA_S
			 */
			public config_union(PU_RECT_LOCATE_PARA stRectLocate) {
				super();
				this.stRectLocate = stRectLocate;
				setType(PU_RECT_LOCATE_PARA.class);
			}
		}

		/**
		 * ID of the master/slave device association. This parameter is reserved and is
		 * not used currently.
		 */
		public NativeLong ulGroupID;

		/**
		 * Master and slave camera locating type. C type : PU_LOCATE_TYPE_E
		 */
		public int enType;

		/**
		 * C type : config_union
		 */
		public config_union config;

		public PU_MASTER_SLAVE_LOCATE_PARA() {
			super();
		}

		/**
		 * @param ulGroupID ID of the master/slave device association. This parameter is
		 *                  reserved and is not used currently.<br>
		 * @param enType    Master and slave camera locating type.<br>
		 *                  C type : PU_LOCATE_TYPE_E<br>
		 * @param config    C type : config_union
		 */
		public PU_MASTER_SLAVE_LOCATE_PARA(NativeLong ulGroupID, int enType, config_union config) {
			super();
			this.ulGroupID = ulGroupID;
			this.enType = enType;
			this.config = config;
		}

		public PU_MASTER_SLAVE_LOCATE_PARA(Pointer peer) {
			super(peer);
		}

		;

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulGroupID", "enType", "config");
		}

		;
	}

	// Manual tracking parameter.
	public static class PU_MASTER_SLAVE_MANUAL_TRACK_PARA extends Structure {
		public ULONG ulGroupID; // ID of the master/slave device association. This parameter is reserved and is
								// not used currently.

		public int iObjectId; // Manual tracking object ID.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MASTER_SLAVE_MANUAL_TRACK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulGroupID", "iObjectId", "szReserved");
		}
	}

	// Parameter of a single mater/slave device association.
	public static class PU_MASTER_SLAVE_PER_GROUP_PARA extends Structure {
		public PU_MASTER_SLAVE_ROLE_E enRole; // Master/Slave role.
		public ULONG ulGroupID; // ID of the master/slave device association. This parameter is reserved and is
								// not used currently.
		public byte[] szMasterIP = new byte[PU_IP4_ADDR_LEN]; // Master camera IP address.
		public byte[] szSlaveIP = new byte[PU_IP4_ADDR_LEN]; // Slave camera IP address.
		public int iSlavePort; // Slave camera port number.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MASTER_SLAVE_PER_GROUP_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enRole", "ulGroupID", "szMasterIP", "szSlaveIP", "iSlavePort", "szReserved");
		}
	}

	// master slave role enum
	public interface PU_MASTER_SLAVE_ROLE_E {
		int PU_ROLE_NONE = 0; // Used to delete the master/slave relationship.
		int PU_ROLE_MASTRE = 1; // Master camera in the master/slave association.
		int PU_ROLE_SLAVE = 2; // Slave camera in the master/slave association.
		int PU_ROLE_MAX = 3;
	}

	;

	// Master/Slave camera tracking configuration.
	public static class PU_MASTER_SLAVE_TRACK_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable the master/slave camera tracking function.
		public ULONG ulGroupID; // ID of the master/slave device association. This parameter is reserved and is
								// not used currently.
		// enMode C类型 PU_MASTER_SLAVE_TRACK_MODE_E
		public int enMode; // Tracking policy.
		// enObjectSize C类型 PU_TRACK_OBJECT_SIZE_E
		public int enObjectSize; // Proportion of the object to the slave camera image.
		public int iTrackTime; // Tracking duration, in seconds.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MASTER_SLAVE_TRACK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulGroupID", "enMode", "enObjectSize", "iTrackTime", "szReserved");
		}
	}

	public static class PU_MASTER_SLAVER_CHANNEL_INFO_S extends Structure {
		public static class ByReference extends PU_MASTER_SLAVER_CHANNEL_INFO_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulMasterChanCap; // Master channel capability.
		public WinDef.ULONG ulSlaveChanCap; // Slave channel capability, that is, the maximum number of supported slave
											// channels.
		public WinDef.ULONG ulMasterChanNum; // Number of master channels.
		public WinDef.ULONG ulSlaveChanNum; // Number of slave channels.
		public PU_PRE_CHANNEL_INFO_S[] astMasterChanInfo = (PU_PRE_CHANNEL_INFO_S[]) new PU_PRE_CHANNEL_INFO_S()
				.toArray(PU_MASTER_NUM_MAX); // Master channel information.
		public PU_PRE_CHANNEL_INFO_S[] astSlaveChanInfo = (PU_PRE_CHANNEL_INFO_S[]) new PU_PRE_CHANNEL_INFO_S()
				.toArray(PU_SLAVE_NUM_MAX); // Slave channel information.

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulMasterChanCap", "ulSlaveChanCap", "ulMasterChanNum", "ulSlaveChanNum",
					"astMasterChanInfo", "astSlaveChanInfo", "szReserved");
		}
	}

	/* Maximum number of area vertexes. */
	public static class PU_MD_AREA extends Structure {
		public float fX1;
		public float fY1;
		public float fX2;
		public float fY2;

		public PU_MD_AREA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("fX1", "fY1", "fX2", "fY2");
		}
	}

	// Media callback type.
	public interface PU_MEDIA_CALLBACK_TYPE_E {
		public static final int PU_MEDIA_CALLBACK_TYPE_RTP = 0; // Real-Time Transport Protocol (RTP) packet.
		public static final int PU_MEDIA_CALLBACK_TYPE_RTP_CRYPTO = 1; // RTP packet without decryption.
		public static final int PU_MEDIA_CALLBACK_TYPE_FRAME = 2; // Frame callback mode.
		public static final int PU_MEDIA_CALLBACK_TYPE_YUV = 3; // YUV (not supported by Linux).
		public static final int PU_MEDIA_CALLBACK_TYPE_FOR_STORAGE = 4;
		public static final int PU_MEDIA_CALLBACK_TYPE_META_FRAME = 5;
		public static final int PU_MEDIA_CALLBACK_TYPE_MAX = 6;
	}

	// Media stream encryption type.
	public interface PU_MEDIA_CRYPTO_TYPE {
		public static final int PU_MEDIA_CRYPTO_NONE = 0; // No encryption.
		public static final int PU_MEDIA_CRYPTO_HW_SIMPLE = 1; // Huawei encryption.
		public static final int PU_MEDIA_CRYPTO_AES_128BIT = 2; // 128-bit AES encryption.
		public static final int PU_MEDIA_CRYPTO_AES_192BIT = 3; // 192-bit AES encryption.
		public static final int PU_MEDIA_CRYPTO_AES_256BIT = 4; // 256-bit AES encryption.
		public static final int PU_MEDIA_CRYPTO_AES256_CBC = 5; // 256-bit AES CBC encryption.
		public static final int PU_MEDIA_CRYPTO_MAX = 6;
	}

	// Media encryption parameter
	public static class PU_MEDIA_ENC_PARA_S extends Structure {
		public int enMediaCryptoType;// Encryption type. Currently, only the AES256 CBC mode is supported.

		public Pointer pstEncPara; // Pointer to the structure corresponding to the encryption type.

		public PU_MEDIA_ENC_PARA_S() {
			this.setAlignType(ALIGN_NONE);// Forced bytes are not filled
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enMediaCryptoType", "pstEncPara");
		}

	}

	// Parameter for sending live video viewing ACK requests.
	public static class PU_MEDIA_PLAY_ACK_INFO extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulSessionId; // Unique ID of a media stream.
		public ULONG ulVideoPayload; // Video load type.
		public ULONG ulAudioPayload; // Audio load type.
		public ULONG ulIgtPayload; // Metadata load type.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_MEDIA_PLAY_ACK_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulSessionId", "ulVideoPayload", "ulAudioPayload", "ulIgtPayload",
					"szReserved");
		}
	}

	// Live video viewing structure.
	public static class PU_MEDIA_PLAY_INFO extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int enBusinessType; // Live video viewing, voice intercom, voice broadcast, and recording download.
									// c type:PU_BUSINESS_TYPE
		public int enStreamType; // Code stream type (primary stream, secondary stream 1, secondary stream 2). c
									// type:PU_STREAM_TYPE
		public int enProtocolType; // TCP, UDP, and multicast modes. c type:PU_PROTOCOL_TYPE
		public int enTansmitType; // ES、PS、TS c type:PU_VIDEO_CODE_TYPE
		public int enVideoType; // Video stream, audio stream, and hybrid stream. c type:PU_VIDEO_TYPE
		public byte[] szLocalIp = new byte[PU_IP4_ADDR_LEN]; // IP address of the request end.
		public PU_PORT_INFO stLocalPortInfo; // Port number of the request end.
		public ULONG ulLinkMode; // Connection type. The options are 0 (direct connection) and 1 (forwarding).
		public int enMediaCryptoType; // Encryption type. c type:PU_MEDIA_CRYPTO_TYPE
		public byte[] szVideoCrypto = new byte[PU_CRYPTION_PASSWD_LEN]; // Video cipher key.
		public byte[] szAudioCrypto = new byte[PU_CRYPTION_PASSWD_LEN]; // Audio cipher key.
		public PU_TIME_S stStartTime; // Start time of requested pre-recording or video recording.
		public PU_TIME_S stEndTime; // End time of requested pre-recording or video recording.
		public byte[] szSessionIDForNAT = new byte[PU_NAT_SESSIONID_LEN]; // Session used for NAT traversal.
		public byte[] szSessionUrl = new byte[PU_NAT_URL_LEN]; // Session URL used for NAT traversal.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates whether to enable the keep-alive
																// function. The options are as follows: 0: yes; 1: no.
		// szReserved[1] indicates the packaging format of the intelligent analysis
		// data. The value 0 indicates XML, and the value 1 indicates metadata.
		// szReserved[2] to szReserved[18] indicate the IV value of the AES256 CBC mode
		// (16 bytes +1 end character).
		// szReserved[20] indicates the type of requested metadata. For details about
		// the value, see the enumerated values of PU_METADATA_REQUEST_TYPE_E.

		public PU_MEDIA_PLAY_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulInterLeavedPort", "ulVideoRtpPort", "ulVideoRtcpPort", "ulAudioRtpPort",
					"ulAudioRtcpPort", "ulIgtRtpPort", "ulIgtRtcpPort", "szReserved");
		}
	}

	// Media stream start response and video download response.
	public static class PU_MEDIA_PLAY_RSP extends Structure {
		public ULONG ulSessionId; // Unique ID of a media stream.
		public PU_PORT_INFO stPeerPortInfo; // Information about the port at the sending end.
		public byte[] szPeerIp = new byte[PU_IP4_ADDR_LEN]; // IP address of the sending end.
		public int enVideoEncodeType; // Video encoding type.
		public int enAudioEncodeType; // Audio encoding type.
		public PU_TIME_S stStartTime; // Actual recording start time.
		public PU_TIME_S stEndTime; // Actual recording end time.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_MEDIA_PLAY_RSP() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSessionId", "stPeerPortInfo", "szPeerIp", "enVideoEncodeType", "enAudioEncodeType",
					"stStartTime", "stEndTime", "szReserved");
		}
	}

	// Parameter for stopping live video viewing.
	public static class PU_MEDIA_PLAY_STOP_INFO extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulSessionId; // Unique ID of a media stream.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_MEDIA_PLAY_STOP_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulSessionId", "szReserved");
		}
	}

	public static class PU_META_DATA extends Structure {
		public WinDef.USHORT usCapacity;

		public USHORT usValidNumber;
		public PU_UserData.ByReference pstMetaUserData = new PU_UserData.ByReference();

		public PU_META_DATA() {
			this.setAlignType(ALIGN_NONE);
		}

		public PU_META_DATA(Pointer p) {
			super(p);
			read();
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usCapacity", "usValidNumber", "pstMetaUserData");
		}
	}

	// Minimum focus distance (unit: mm).
	public interface PU_MIN_FOCUS {
		public static final int PU_MIN_FOCUS_10 = 10; // 1cm
		public static final int PU_MIN_FOCUS_100 = 100;
		public static final int PU_MIN_FOCUS_300 = 300;
		public static final int PU_MIN_FOCUS_500 = 500;
		public static final int PU_MIN_FOCUS_1000 = 1000; // 1m
		public static final int PU_MIN_FOCUS_1500 = 1500;
		public static final int PU_MIN_FOCUS_2000 = 2000;
		public static final int PU_MIN_FOCUS_3000 = 3000;
		public static final int PU_MIN_FOCUS_5000 = 5000;
		public static final int PU_MIN_FOCUS_6000 = 6000;
		public static final int PU_MIN_FOCUS_10000 = 10000; // 10m
		public static final int PU_MIN_FOCUS_20000 = 20000;
		public static final int PU_MIN_FOCUS_50000 = 50000;
		public static final int PU_MIN_FOCUS_100000 = 100000; // 100m
		public static final int PU_MIN_FOCUS_MAX = 100001;
	}

	// Minimum focus distance parameters.
	public static class PU_MIN_FOCUS_VALUE_S extends Structure {
		/* C TYPE : PU_MIN_FOCUS_E */
		public int enMinFocus; // Minimum focus distance.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enMinFocus");
		}
	}

	// List of scheduled tasks in one year.
	public static class PU_MONTHS_PLAN extends Structure {
		public ULONG ulMonth; // Month. If the value is 0, all the 12 months need to be set. If the value is
								// from 1 to 12, data of the corresponding month needs to be saved.
		public WinDef.BOOL bEnable; // Indicates whether to enable the OSD.
		public PU_TIME_QUANTUM_LIST[] stTimeQaumtumMonths = (PU_TIME_QUANTUM_LIST[]) new PU_TIME_QUANTUM_LIST()
				.toArray(PU_MONTH_NUM);
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field. It is used in the SDK.

		public PU_MONTHS_PLAN() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulMonth", "bEnable", "stTimeQaumtumMonths", "szReserved");
		}
	}

	// Motion detection alarm parameters.
	public static class PU_MOTION_DETECTION_PARA extends Structure {
		public ULONG ulChannelId; // Video channel ID.

		public NativeLong lEnable; // Indicates whether to enable the ROI.
		public ULONG ulInterval; // Interval for detecting events. The value ranges from 1 to 30, in seconds.
									// Motions detected in the interval are considered as the same motion.
		public ULONG ulSensitivity; // Motion detection sensitivity. The value ranges from 1 to 5. A larger value
									// indicates a higher sensitivity.
		public ULONG ulDeteInterval; // Alarm check interval (1–256s). The system checks the alarm status at a
										// specified interval.
		public PU_DETECTION_AREA stDetectionArea; // Alarm detection area.
		public PU_ALARM_TIME_LIST stAlarmTimeList; // Alert deployment time list.

		public PU_MOTION_DETECTION_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "lEnable", "ulInterval", "ulSensitivity", "ulDeteInterval",
					"stDetectionArea", "stAlarmTimeList");
		}
	}

	// Multicast parameters.
	public static class PU_MULTICAST_PARA extends Structure {
		public ULONG ulMeshIndex; // Network adapter index.
		public byte[] szLocalIP = new byte[PU_MULTICAST_ADDR_LEN]; // Multicast IP address.
		public ULONG ulPort; // Multicast port.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_MULTICAST_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulMeshIndex", "szLocalIP", "ulPort", "szReserved");
		}
	}

	/* Noise reduction mode */
	public static class PU_NOISE_REDUCTION extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int enNoiseReductionMode; // Noise reduction mode. c type:PU_NOISE_REDUCTION_MODE
		public ULONG ulNRLevel; // Noise reduction coefficient in common mode.
		public ULONG ulSfcLevel; // Spatial noise reduction coefficient in expert mode.
		public ULONG ulTfcLevel; // Temporal noise reduction coefficient in expert mode.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_NOISE_REDUCTION() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enNoiseReductionMode", "ulNRLevel", "ulSfcLevel", "ulTfcLevel",
					"szReserved");
		}
	}

	/* Noise reduction mode */
	public interface PU_NOISE_REDUCTION_MODE {
		public static final int PU_NOISE_REDUCTION_CLOSE = 0; // Disabled.
		public static final int PU_NOISE_REDUCTION_NORMAL = 1; // Common mode.
		public static final int PU_NOISE_REDUCTION_EXPERT = 2; // Expert mode.
		public static final int PU_NOISE_REDUCTION_MAX = 3;
	}

	/* NTP parameters. */
	public static class PU_NTP_PARA extends Structure {
		public WinDef.BOOL bNTPEnable; // Indicates whether to enable NTP.
		public ULONG ulSynInterval; // NTP synchronization interval.
		public byte[] szNTPAddress = new byte[PU_DOMAIN_LEN]; // Domain name or IP address of the NTP server.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_NTP_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bNTPEnable", "ulSynInterval", "szNTPAddress", "szReserved");
		}
	}

	// One-image synthesis.
	public interface PU_ONE_PIC_SYNTHESIS_TYPE_E {
		int PU_ONE_PIC_SYNTHESIS_TYPE1 = 0; // Close-up image at the top.
		int PU_ONE_PIC_SYNTHESIS_TYPE2 = 1; // Close-up image at the bottom.
		int PU_ONE_PIC_SYNTHESIS_TYPE3 = 2; // Close-up image on the left.
		int PU_ONE_PIC_SYNTHESIS_TYPE4 = 3; // Close-up image on the right.
		int PU_ONE_PIC_NO_SYNTHESIS = 4; // Not synthesized.
		int PU_ONE_PIC_SYNTHESIS_TYPE_MAX = 5;
	}

	// ONVIF authentication type.
	public interface PU_ONVIF_AUTH_TYPE {
		public static final int AUTH_TYPE_DIGGEST = 0; // Only Digest authentication is supported.
		public static final int AUTH_TYPE_DIGGEST_AND_WSSE = 1; // Digest authentication and WSSE authentication are
																// supported. Digest authentication takes precedence
																// over WSSE authentication.
		public static final int AUTH_TYPE_NONE = 2; // No authentication.
		public static final int AUTH_TYPE_WSSE = 3; // Only WSSE authentication is supported.
		public static final int AUTH_TYPE_MAX = 4;
	}

	// ONVIF password.
	public static class PU_ONVIF_PWD_PARA extends Structure {
		public byte[] szUserName = new byte[PU_USER_NAME_LEN];
		public byte[] szOldPassword = new byte[PU_PASSWORD_LEN];
		public byte[] szNewPassword = new byte[PU_PASSWORD_LEN];
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ONVIF_PWD_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szUserName", "szOldPassword", "szNewPassword", "szReserve");
		}
	}

	// Indicates whether to enable ONVIF.
	public static class PU_ONVIF_SWITCH extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable ONVIF.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ONVIF_SWITCH() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szReserve");
		}
	}

	public interface PU_ONVIF_VERSION_ENUM {
		public static final int ONVIF_VERSION_2_6 = 0;
		public static final int ONVIF_VERSION_2_6_1 = 1;
		public static final int ONVIF_VERSION_MAX = 2;
	}

	/*** ONVIF version ***/
	public static class PU_ONVIF_VERSION_TYPE extends Structure {
		public ULONG ulChannelId; // Channel ID (reserved).
		public PU_ONVIF_VERSION_ENUM enOnvifVersionType; // ONVIF version.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_ONVIF_VERSION_TYPE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enOnvifVersionType", "szReserve");
		}
	}

	public interface PU_OPT_TYPE {
		public static final int PU_OPT_TYPE_ADD = 0; // Add.
		public static final int PU_OPT_TYPE_DEL = 1; // Delete.
		public static final int PU_OPT_TYPE_MOD = 2; // Modify.
		public static final int PU_OPT_TYPE_MAX = 3;
	}

	public interface PU_OSD_DATE_TYPE {
		public static final int PU_YYYY_MM_DD = 0; // YYYY-MM-DD
		public static final int PU_MM_DD_YYYY = 1; // MM-DD-YYYY
		public static final int PU_YYYY_MM_DD_CH = 2; // YYYY-MM-DD
		public static final int PU_MM_DD_YYYY_CH = 3; // MM-DD-YYYY
		public static final int PU_DD_MM_YYYY = 4; // DD-MM-YYYY
		public static final int PU_DD_MM_YYY_CH = 5; // dd-mm-yyyy (Chinese)
		public static final int PU_OSD_DATA_TYPE_MAX = 6;
	}

	/* OSD time parameter. */
	public static class PU_OSD_DATETIME_PARA extends Structure {
		public WinDef.BOOL bShowWeekday; // Indicates whether to display the weekday.
		public WinDef.BOOL bDateEnable; // Indicates whether to display the time on video images.
		public int enDateType; // Date format.
		public int enLanguageType; // OSD language. The options are as follows: 0: simplified Chinese; 1: English.
									// C type:PU_LANGUAGE_TYPE_E
		public PU_OSD_INFO stOsdPara; // OSD location and color.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_OSD_DATETIME_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bShowWeekday", "bDateEnable", "enDateType", "enLanguageType", "stOsdPara",
					"szReserve");
		}
	}

	// OSD time parameter.
	public class PU_OSD_DATETIME_PARA_S extends Structure {
		public WinDef.BOOL bShowWeekday; // Indicates whether to display the weekday.

		public WinDef.BOOL bDateEnable; // Indicates whether to display the time on video images.
		public int enDateType; // Date format.
		public int enLanguageType; // OSD language. The options are as follows: 0: simplified Chinese; 1: English.
									// C type:PU_LANGUAGE_TYPE_E
		public PU_OSD_INFO_S stOsdPara; // OSD location and color.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_OSD_DATETIME_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bShowWeekday", "bDateEnable", "enDateType", "enLanguageType", "stOsdPara",
					"szReserve");
		}
	}

	/* OSD position and color. */
	public static class PU_OSD_INFO extends Structure {
		public ULONG ulStartX;
		public ULONG ulStartY;
		public ULONG ulTextColor; // Font color (0x00RGB).
		public int enBackgroundColor; // Background color. C type:PU_COLOR_TYPE
		public int enBackgroundAlpha; // Background transparency. C type:PU_ALPHA_TYPE
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Bit [0] indicates whether the color is inverted (0: no;
															// 1: yes).
		// Bit [1] indicates the OSD font size (0: small; 1: medium; 2: large).

		public PU_OSD_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartX", "ulStartY", "ulTextColor", "enBackgroundColor", "enBackgroundAlpha",
					"szReserve");
		}
	}

	// OSD position and color.
	public class PU_OSD_INFO_S extends Structure {
		public WinDef.ULONG ulStartX; // StartX pos 0^351

		public WinDef.ULONG ulStartY; // StartY pos 0^281
		public WinDef.ULONG ulTextColor; // Font color (0x00RGB).
		public int enBackgroundColor; // Background color. C type:PU_COLOR_TYPE
		public int enBackgroundAlpha; // Background transparency. C type:PU_ALPHA_TYPE
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Bit [0] indicates whether the color is inverted (0: no;
															// 1: yes).

		public PU_OSD_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		// Bit [1] indicates the OSD font size (0: small; 1: medium; 2: large).
		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartX", "ulStartY", "ulTextColor", "enBackgroundColor", "enBackgroundAlpha",
					"szReserve");
		}
	}

	// OSD margin.
	public static class PU_OSD_MARGIN_INFO extends Structure {
		public ULONG ulChnID;
		public ULONG ulDirect; // OSD margin direction. The options are as follows: 0: upward; 1: downward; 2:
								// leftward; 3: rightward.
		public WinDef.BOOL bEnable;
		public ULONG ulMarginLength; // Margin width. The options include 0, 1, and 2.

		public PU_OSD_MARGIN_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulDirect", "bEnable", "ulMarginLength");
		}
	}

	public class PU_OSD_PARTICULAR_PARA_EX_OUT_S extends Structure {
		public WinDef.ULONG ulChannelID; // Channel ID.

		public PU_OSD_DATETIME_PARA_S stOsdDateTimePara; // OSD time parameter.
		public WinDef.ULONG ulOSDStringNum; // Number of OSD character strings.
		public PU_OSD_STRING_PARA_S[] pszStringPara = new PU_OSD_STRING_PARA_S[PU_OSD_STRING_NUM];

		public PU_OSD_PARTICULAR_PARA_EX_OUT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "stOsdDateTimePara", "ulOSDStringNum", "pszStringPara");
		}
	}

	/* Image overlay parameter structure. */
	public static class PU_OSD_PICTURE_PARA extends Structure {
		public ULONG ulChannelID;
		public WinDef.BOOL bEnable; // Indicates whether to enable the OSD.
		public PU_AREA_INFO stAreaInfo; // Image area information.
		public byte[] szPicFileName = new byte[PU_SAVE_FILE_PATH_MAX]; // Image path and name.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_OSD_PICTURE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "bEnable", "stAreaInfo", "szPicFileName", "szReserve");
		}
	}

	/* OSD数组 */
	public static class PU_OSD_STRING_ARRAY extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public PU_OSD_DATETIME_PARA stOsdDateTimePara; // OSD time parameter.
		public ULONG ulOSDStringNum; // Number of valid character strings.
		public PU_OSD_STRING_PARA[] szStringPara = (PU_OSD_STRING_PARA[]) new PU_OSD_STRING_PARA()
				.toArray(PU_OSD_STRING_NUM); // OSD character string parameters.

		public PU_OSD_STRING_ARRAY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "stOsdDateTimePara", "ulOSDStringNum", "szStringPara");
		}
	}

	/* OSD array extension. */
	public static class PU_OSD_STRING_ARRAY_EX_OUT extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public PU_OSD_DATETIME_PARA stOsdDateTimePara; // OSD time parameter.
		public ULONG ulOSDStringNum; // Number of valid character strings.
		public PU_OSD_STRING_PARA pszStringPara; // OSD character string parameter pointer.

		public PU_OSD_STRING_ARRAY_EX_OUT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "stOsdDateTimePara", "ulOSDStringNum", "pszStringPara");
		}
	}

	/* OSD character string parameters. */
	public static class PU_OSD_STRING_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable the OSD.
		public PU_OSD_INFO stOSDInfo;
		public ULONG ulStringLen; // Length of the character string.
		public byte[] szString = new byte[PU_OSD_STRING_LEN]; // Character string content.

		public PU_OSD_STRING_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "stOSDInfo", "ulStringLen", "szString");
		}
	}

	// OSD character string parameters.
	public class PU_OSD_STRING_PARA_S extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable the OSD.

		public PU_OSD_INFO_S stOSDInfo; // OSD position and color.
		public WinDef.ULONG ulStringLen; // Length of the character string.
		public byte[] szString = new byte[PU_OSD_STRING_LEN]; // Character string content.

		public PU_OSD_STRING_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "stOSDInfo", "ulStringLen", "szString");
		}
	}

	// OSDI area information.
	public static class PU_OSDI_AREA_CFG_PARA extends Structure {
		public ULONG ulIndex; // Area index.
		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.
		public ULONG ulOSDINameLen; // OSDI name length.
		public byte[] szOSDIName = new byte[PU_OSD_STRING_LEN]; // OSDI name.
		public PU_OSDI_POINT_INFO stLowerLeftPoint; // Coordinate of the lower-left corner of the OSDI area.
		public PU_OSDI_POINT_INFO stUpperRightPoint; // Coordinate of the lower-right corner of the OSDI area.

		public PU_OSDI_AREA_CFG_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "bEnable", "ulOSDINameLen", "szOSDIName", "stLowerLeftPoint",
					"stUpperRightPoint");
		}
	}

	// OSDI area information.
	public static class PU_OSDI_AREA_CFG_PARA_V20 extends Structure {
		public ULONG ulIndex; // Area index.
		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.
		public ULONG ulOSDINameLen; // OSDI name length.
		public byte[] szOSDIName = new byte[PU_OSD_STRING_LEN]; // OSDI name.
		public PU_OSDI_POINT_INFO stLowerLeftPoint; // Coordinate of the lower-left corner of the OSDI area.
		public PU_OSDI_POINT_INFO stUpperRightPoint; // Coordinate of the lower-right corner of the OSDI area.
		public PU_POINT stOSDITopLeftPos; // Coordinate of the upper-left corner of the OSDI area.

		public PU_OSDI_AREA_CFG_PARA_V20() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "bEnable", "ulOSDINameLen", "szOSDIName", "stLowerLeftPoint",
					"stUpperRightPoint", "stOSDITopLeftPos");
		}
	}

	// OSDI parameters.
	public static class PU_OSDI_BUSINESS_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public WinDef.BOOL bOSDIEnable; // Indicates whether to enable the OSDI function.
		public ULONG ulOSDINum; // Current number of OSDI areas.
		public PU_OSDI_AREA_CFG_PARA[] stOSDIAreaPara = (PU_OSDI_AREA_CFG_PARA[]) new PU_OSDI_AREA_CFG_PARA()
				.toArray(OSDI_AREA_NUM_MAX); // OSDI area information.

		public PU_OSDI_BUSINESS_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "bOSDIEnable", "ulOSDINum", "stOSDIAreaPara");
		}
	}

	// OSDI parameters.
	public static class PU_OSDI_BUSINESS_PARA_V20 extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public WinDef.BOOL bOSDIEnable; // Indicates whether to enable the OSDI function.
		public ULONG ulOSDINum; // Current number of OSDI areas.
		public PU_OSDI_AREA_CFG_PARA_V20[] stOSDIAreaPara = (PU_OSDI_AREA_CFG_PARA_V20[]) new PU_OSDI_AREA_CFG_PARA_V20()
				.toArray(OSDI_AREA_NUM_MAX); // OSDI area information.

		public PU_OSDI_BUSINESS_PARA_V20() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "bOSDIEnable", "ulOSDINum", "stOSDIAreaPara");
		}
	}

	// OSDI operation type.
	public interface PU_OSDI_OPTYPE {
		public static final int PU_OSDI_AREA_ADD = 0; // Add an OSDI area.
		public static final int PU_OSDI_AREA_DEL = 1; // Delete an OSDI area.
		public static final int PU_OSDI_AREA_MOD = 2; // Modify an OSDI area.
		public static final int PU_OSDI_AREA_ENABLE = 3; // Enable an OSDI area.
		public static final int PU_OSDI_MOVE_TO_AREA = 4; // Move to an OSDI area.
		public static final int PU_OSDI_BUSINESS_ENABLE = 5; // Indicates whether to enable OSDI.
		public static final int PU_OSDI_GET_CUR_CONFIG = 6; // Obtain the current OSDI configuration.
	}

	public static class PU_OSDI_POINT_INFO extends Structure {
		public float fHorDegree;
		public float fVerDegree;

		public PU_OSDI_POINT_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("fHorDegree", "fVerDegree");
		}
	}

	// OSDI position.
	public static class PU_OSDI_POSITION extends Structure {
		public ULONG ulChnID; // Channel ID.
		public ULONG ulOSDIIndex; // OSDI index.
		public PU_POINT stOSDITopLeftPos; // Coordinate of the upper-left corner of the OSDI area.

		public PU_OSDI_POSITION() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulOSDIIndex", "stOSDITopLeftPos");
		}
	}

	// Defocus detection.
	public static class PU_OUTOFFOCUS_DETECT_PARA_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable the ROI.
		public ULONG ulSensitivity; // Detection sensitivity.
		public ULONG ulAlarmInterval; // Alarm reporting interval.
		public PU_ALARM_TIME_LIST_S stAlarmTimeList; // Alert deployment time list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_OUTOFFOCUS_DETECT_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "ulSensitivity", "ulAlarmInterval", "stAlarmTimeList",
					"szReserved");
		}
	}

	// Superimposed image type.
	public interface PU_OVERLAY_PIC_TYPE_E {
		int PU_ORG_PIC = 0; // Original image.
		int PU_SYNTHESIS_PIC = 1; // Synthesized image.
		int PU_OVERLAY_PIC_TYPE_MAX = 2;
	}

	// Panorama scan.
	public class PU_PANORAMA_SCAN_PARA extends Structure {
		public WinDef.ULONG ulSpeed; // Speed.
		public int enDirection; // Direction. The value can be left or right.

		public PU_PANORAMA_SCAN_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSpeed", "enDirection");
		}
	}

	// Parity bit.
	public interface PU_PARITY_BIT {
		public static final int PU_PARITY_BIT_NONE = 0;
		public static final int PU_PARITY_BIT_ODD = 1;
		public static final int PU_PARITY_BIT_EVEN = 2;
		public static final int PU_PARITY_BIT_MARK = 3;
		public static final int PU_PARITY_BIT_SPACE = 4;
		public static final int PU_PARITY_BIT_MAX = 5;
	}

	// Image parameters.
	public static class PU_PIC_NAMING_ELEM_S extends Structure {
		/* C type : PU_PIC_NAMING_TYPE_E */
		public int enPicNamingType; // Naming type.
		public byte[] acCustomContent = new byte[PU_MAX_CUSTOM_CONTENT_LEN]; // User-defined content.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enPicNamingType", "acCustomContent", "szReserved");
		}
	}

	public static class PU_PIC_NAMING_PARA_EX_S extends Structure {
		/* c Type : PU_SEPARATOR_TYPE_E */
		public int enSeparatorType; // Separator type.
		public PU_PIC_NAMING_ELEM_S[] astPicNamingElem = new PU_PIC_NAMING_ELEM_S[PU_MAX_PIC_NAMING_ELEM_EX];
		public byte[] szReserved = new byte[PU_RESERVE_LEN];// Reserved field.

		public PU_PIC_NAMING_PARA_EX_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSeparatorType", "astPicNamingElem", "szReserved");
		}
	}

	public static class PU_PIC_NAMING_PARA_S extends Structure {
		/* C type : PU_SEPARATOR_TYPE_E */
		public int enSeparatorType; // Separator type.
		public PU_PIC_NAMING_ELEM_S[] astPicNamingElem = new PU_PIC_NAMING_ELEM_S[PU_MAX_PIC_NAMING_ELEM];
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_PIC_NAMING_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSeparatorType", "astPicNamingElem", "szReserved");
		}
	}

	/************* Image naming rule ***************/
	public interface PU_PIC_NAMING_TYPE_E {
		// Object classification_Motor vehicle
		int PU_PIC_NAMING_TYPE_NO = 0;
		int PU_PIC_NAMING_TYPE_DEV_IP = 1;
		int PU_PIC_NAMING_TYPE_DEV_ID = 2;
		int PU_PIC_NAMING_TYPE_TIME = 3;
		int PU_PIC_NAMING_TYPE_PLATE_ID = 4;
		int PU_PIC_NAMING_TYPE_PLATE_COLOR = 5;
		int PU_PIC_NAMING_TYPE_LANE_ID = 6;
		int PU_PIC_NAMING_TYPE_VEHICLE_TYPE = 7;
		int PU_PIC_NAMING_TYPE_VEHICLE_COLOR = 8;
		int PU_PIC_NAMING_TYPE_ROAD_ID = 9;
		int PU_PIC_NAMING_TYPE_DIR_ID = 10;
		int PU_PIC_NAMING_TYPE_DIR = 11;
		int PU_PIC_NAMING_TYPE_CUSTOM = 12;
		int PU_PIC_NAMING_TYPE_PLATE_TYPE = 13;
		int PU_PIC_NAMING_TYPE_VEHICLE_BRAND = 14;
		int PU_PIC_NAMING_TYPE_SUB_BRAND = 15;
		int PU_PIC_NAMING_TYPE_YEAR = 16; // Model year.
		int PU_PIC_NAMING_TYPE_OBJ_ID = 17; // Vehicle tracking ID.
		int PU_PIC_NAMING_TYPE_VEHICLE_SIZE = 18;// Vehicle size.
		int PU_PIC_NAMING_TYPE_REGULATION_NUM = 19;// Violation ID.
		int PU_PIC_NAMING_TYPE_PIC_NUM = 20;// Image ID.
		int PU_PIC_NAMING_TYPE_VEHICLE_DIRECTION = 21;
		int PU_PIC_NAMING_TYPE_VEHICLE_SPEED = 22;// Vehicle speed.
		int PU_PIC_NAMING_TYPE_VERSION = 23;// Platform version number. This function is added for the Neusoft platform.
		int PU_PIC_NAMING_TYPE_VEHICLE_RECT = 24;// Vehicle position.
		int PU_PIC_NAMING_TYPE_PLATE_RECT = 25;// License plate position.
		int PU_PIC_NAMING_TYPE_VEHICLE_BRAND_ID = 26;// Vehicle brand ID.
		int PU_PIC_NAMING_TYPE_SUB_BRAND_ID = 27;// Vehicle model ID.
		// Face and person.
		int PU_PIC_NAMING_TYPE_GENDER = 50;// Sex.
		int PU_PIC_NAMING_TYPE_AGE = 51; // Age.
		int PU_PIC_NAMING_TYPE_EXPRESSION = 52; // Expression.
		int PU_PIC_NAMING_TYPE_GLASESS = 53; // Glasses.
		int PU_PIC_NAMING_TYPE_MOUTHMASK = 54; // Mouth mask.
		int PU_PIC_NAMING_TYPE_AGEGROUP = 55; // Age group.
		int PU_PIC_NAMING_TYPE_SHAPE = 56;// Figure.
		int PU_PIC_NAMING_TYPE_HAIR = 57;// Hairstyle.
		int PU_PIC_NAMING_TYPE_UMBRELLA = 58;// Umbrella.
		int PU_PIC_NAMING_TYPE_BACKPACK = 59;// Backpack.
		int PU_PIC_NAMING_TYPE_FRONTPACK = 60;// Front pack.
		int PU_PIC_NAMING_TYPE_SATCHEL = 61;// Satchel.
		int PU_PIC_NAMING_TYPE_LUGGAGE = 62;// Luggage.
		int PU_PIC_NAMING_TYPE_CARRY = 63;// Carrying object.
		int PU_PIC_NAMING_TYPE_MOVESPEED = 64;// Movement speed.
		int PU_PIC_NAMING_TYPE_MOVEDIRECT = 65;// Movement direction.
		int PU_PIC_NAMING_TYPE_UPPERTEXTURE = 66; // Tops pattern.
		int PU_PIC_NAMING_TYPE_UPPERSTYLE = 67;// Tops style.
		int PU_PIC_NAMING_TYPE_UPPERCOLOR = 68;// Tops color.
		int PU_PIC_NAMING_TYPE_LOWERSTYLE = 69;// Bottoms style.
		int PU_PIC_NAMING_TYPE_LOWERCOLOR = 70;// Bottoms color.
		int PU_PIC_NAMING_TYPE_HUMANDEV_IP = 71;// Device IP address (face checkpoint).
		int PU_PIC_NAMING_TYPE_HUMANTIME = 72; // Time (face checkpoint).
		int PU_PIC_NAMING_TYPE_HUMANOBJ_ID = 73;// Tracking ID (face checkpoint).
		int PU_PIC_NAMING_TYPE_HUMANCUSTOM = 74; // Custom (face checkpoint).
		// Object classification_Rider
		int PU_PIC_NAMING_TYPE_RIDERMAN_GENDER = 80;// Rider sex.
		int PU_PIC_NAMING_TYPE_RIDERMAN_AGE = 81;// Rider age.
		int PU_PIC_NAMING_TYPE_RIDERMAN_UPPERSTYLE = 82; // Rider tops style.
		int PU_PIC_NAMING_TYPE_RIDERMAN_UPPERCOLOR = 83;// Rider tops color.
		int PU_PIC_NAMING_TYPE_RIDERMAN_HELMET = 84; // Helmet.
		int PU_PIC_NAMING_TYPE_RIDERMAN_HELMETCOLOR = 85; // Helmet color.
		int PU_PIC_NAMING_TYPE_RIDERMAN_OBJID = 86;// Rider tracking ID.
		int PU_PIC_NAMING_TYPE_RIDERMAN_IP = 87;// Device IP address (rider).
		int PU_PIC_NAMING_TYPE_RIDERMAN_TIME = 88; // Time (rider).
		int PU_PIC_NAMING_TYPE_RIDERMAN_CUSTOM = 89;// Custom (rider).
		int PU_PIC_NAMING_TYPE_MAX = 90;
	}

	public static class PU_PIC_OSD_INFO_EX_S extends Structure {
		public int uPicOSDNum; // Number of OSDs to be superimposed.
		// C type : PU_PIC_OSD_TYPE_E
		public int[] aenPicOSDType = new int[PU_VLPR_PIC_OSD_TYPE_MAX_EX]; // Overlay type.
		/* C type : PU_PIC_OSD_LOCATION_E */
		public int enPicOSDLocation; // OSD overlay location.
		/* C type : PU_FONT_SIZE_E */
		public int enFontSize; // Font size.
		/* C type : PU_FONT_SIZE_EXT_E */
		public int enFontSizeExt; // Extended OSD font size (new enumerated value).
		public ULONG ulFgColor; // Foreground (text) color format: 0xRRGGBB or converted into decimal.
		public char ucFgAlpha; // Foreground (text) transparency, ranging from 0 to 128.
		public ULONG ulBgColor; // Background color format: 0xRRGGBB or converted into decimal.
		public char ucBgAlpha; // Background transparency, ranging from 0 to 128 (HiSilicon).
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_PIC_OSD_INFO_EX_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uPicOSDNum", "aenPicOSDType", "enPicOSDLocation", "enFontSize", "enFontSizeExt",
					"ulFgColor", "ucFgAlpha", "ulBgColor", "ucBgAlpha", "szReserved");
		}
	}

	public static class PU_PIC_OSD_INFO_S extends Structure {
		public int uPicOSDNum; // Number of OSDs to be superimposed.
		// C type : PU_PIC_OSD_TYPE_E
		public int[] aenPicOSDType = new int[PU_VLPR_PIC_OSD_TYPE_MAX]; // Overlay type.
		/* C type : PU_PIC_OSD_LOCATION_E */
		public int enPicOSDLocation; // OSD overlay location.
		/* C type : PU_FONT_SIZE_E */
		public int enFontSize; // Font size.
		public ULONG ulFgColor; // Foreground (text) color format: 0xRRGGBB or converted into decimal.
		public char ucFgAlpha; // Foreground (text) transparency, ranging from 0 to 128.
		public ULONG ulBgColor; // Background color format: 0xRRGGBB or converted into decimal.
		public char ucBgAlpha; // Background transparency, ranging from 0 to 128 (HiSilicon).

		public PU_PIC_OSD_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uPicOSDNum", "aenPicOSDType", "enPicOSDLocation", "enFontSize", "ulFgColor",
					"ucFgAlpha", "ulBgColor", "ucBgAlpha");
		}
	}

	public interface PU_PIC_OSD_LOCATION_E {
		int PU_PIC_IN_TOP = 0;
		int PU_PIC_IN_BOTTOM = 1;
		int PU_PIC_OUT_TOP = 2;
		int PU_PIC_OUT_BOTTOM = 3;
		int PU_PIC_OSD_LOCATION_MAX = 4;
	}

	public static class PU_PIC_OSD_PARA_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		/* C type : PU_OVERLAY_PIC_TYPE_E */
		public int enOverlayPicType; // Type of the image where OSD is to be superimposed.
		public PU_PIC_OSD_INFO_S stPicOSDInfo; // Image overlay information.
		public PU_TIME_OSD_PARA stTimeOSDPara; // Time OSD parameters.
		public PU_CUSTOM_OSD_PARA_S stRoadIdOSDPara; // Intersection ID.
		public PU_CUSTOM_OSD_PARA_S stDevIdOSDPara; // Device ID.
		public PU_CUSTOM_OSD_PARA_S stDirIdOSDPara; // Direction ID.
		public PU_CUSTOM_OSD_PARA_S stDirOSDPara; // Direction OSD.
		public PU_CUSTOM_OSD_PARA_S stCustomOSDPara; // Customized OSD.

		public PU_PIC_OSD_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "enOverlayPicType", "stPicOSDInfo", "stTimeOSDPara", "stRoadIdOSDPara",
					"stDevIdOSDPara", "stDirIdOSDPara", "stDirOSDPara", "stCustomOSDPara");
		}
	}

	public static class PU_PIC_OSD_PARA_V2_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		/* C type : PU_OVERLAY_PIC_TYPE_E */
		public int enOverlayPicType; // Type of the image where OSD is to be superimposed.
		public PU_PIC_OSD_INFO_S stPicOSDInfo; // Image overlay information.
		public PU_TIME_OSD_PARA stTimeOSDPara; // Time OSD parameters.
		public PU_CUSTOM_OSD_PARA_S stRoadIdOSDPara; // Intersection ID.
		public PU_CUSTOM_OSD_PARA_S stDevIdOSDPara; // Device ID.
		public PU_CUSTOM_OSD_PARA_S stDirIdOSDPara; // Direction ID.
		public PU_CUSTOM_OSD_PARA_S stDirOSDPara; // Direction OSD.
		public PU_CUSTOM_OSD_PARA_S stCustomOSDPara; // Customized OSD.
		public BOOL bDirOSDParaEn; // Indicates whether to enable or disable driving direction OSD. The value 1
									// indicates that driving direction OSD is disabled (ITS cameras). The value 0
									// indicates driving direction OSD is enabled.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_PIC_OSD_PARA_V2_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "enOverlayPicType", "stPicOSDInfo", "stTimeOSDPara", "stRoadIdOSDPara",
					"stDevIdOSDPara", "stDirIdOSDPara", "stDirOSDPara", "stCustomOSDPara", "bDirOSDParaEn",
					"szReserved");
		}
	}

	public static class PU_PIC_OSD_PARA_V3_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public PU_OVERLAY_PIC_TYPE_E enOverlayPicType; // Type of the image where OSD is to be superimposed.
		public PU_PIC_OSD_INFO_EX_S stPicOSDInfo; // Image overlay information.
		public PU_TIME_OSD_PARA stTimeOSDPara; // Time OSD parameters.
		public PU_CUSTOM_OSD_PARA_EX stRoadIdOSDPara; // Intersection ID.
		public PU_CUSTOM_OSD_PARA_EX stDevIdOSDPara; // Device ID.
		public PU_CUSTOM_OSD_PARA_EX stDirIdOSDPara; // Direction ID.
		public PU_CUSTOM_OSD_PARA_EX stDirOSDPara; // Direction OSD.
		public PU_CUSTOM_OSD_PARA_EX stCustomOSDPara; // Customized OSD.
		public PU_CUSTOM_OSD_PARA_EX stLocateDescOSDPara; // Intersection position description.
		public PU_CUSTOM_OSD_PARA_EX stMonitorInfoOSDPara; // Surveillance site position description.
		public PU_CUSTOM_OSD_PARA_EX stLaneDescOSDPara; // Lane description.
		public PU_CUSTOM_OSD_PARA_EX stLaneDirDescOSDPara; // Lane direction description.
		public BOOL bDirOSDParaEn; // Indicates whether to enable or disable driving direction OSD. The value 1
									// indicates that driving direction OSD is disabled (ITS cameras). The value 0
									// indicates driving direction OSD is enabled.
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_PIC_OSD_PARA_V3_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "enOverlayPicType", "stPicOSDInfo", "stTimeOSDPara", "stRoadIdOSDPara",
					"stDevIdOSDPara", "stDirIdOSDPara", "stDirOSDPara", "stCustomOSDPara", "stLocateDescOSDPara",
					"stMonitorInfoOSDPara", "stLaneDescOSDPara", "stLaneDirDescOSDPara", "bDirOSDParaEn", "szReserved");
		}
	}

	// Image OSD type.
	public interface PU_PIC_OSD_TYPE_E {
		int PU_TIME_OSD = 0;
		int PU_PLATE_ID_OSD = 1;
		int PU_VEHICLE_TYPE_OSD = 2;
		int PU_LANE_ID_OSD = 3;
		int PU_PLATE_COLOR_OSD = 4;
		int PU_VEHICLE_COLOR_OSD = 5;
		int PU_ROAD_ID_OSD = 6;
		int PU_DEV_ID_OSD = 7;
		int PU_DIR_ID_OSD = 8;
		int PU_DIR_OSD = 9;
		int PU_CUSTOM_OSD = 10;
		int PU_SECURITY_CODE_OSD = 11;
		int PU_PRE_BRAND_TYPE_OSD = 12; // Vehicle brand.
		int PU_SUB_BRAND_TYPE_OSD = 13; // Vehicle model.
		int PU_YEAR_BRAND_TYPE_OSD = 14; // Model year.
		int PU_LOCATE_DESC_OSD = 15; // Intersection position description.
		int PU_MONITOR_INFO_OSD = 16; // Surveillance site information.
		int PU_BRAND_INFO_OSD = 17; // Brand.
		int PU_VEHICLE_SPEED_OSD = 18; // Vehicle speed.
		int PU_LANE_DESC_OSD = 19; // Lane description.
		int PU_SNAP_SERIAL_NUM_OSD = 20; // Snapshot ID.
		int PU_ILLEGAL_NUM_OSD = 21; // Violation code.
		int PU_ILLEGAL_DESC_OSD = 22; // Violation code description.
		int PU_SPEED_LIMIT_OSD = 23; // Speed limit information.
		int PU_ILLEGAL_SPEED_OSD = 24; // Violation speed percentage in the case of speeding/low speed.
		int PU_LANE_DIR_DESC_OSD = 25; // Lane direction description.
		int PU_VEHICLE_LEN_DESC_OSD = 26; // Vehicle length.
		int PU_REDLIGHT_START_OSD = 27; // Time when the red light is on.
		int PU_REDLIGHT_END_OSD = 28; // Time when the red light is off.
		int PU_REDLIGHT_PERIOD_OSD = 29; // Red light duration.

		int PU_SNAPTRIG_OSD = 30; // Snapshot triggering source.
		int PU_VEHICLE_MFR_TYPE_OSD = 31; // Secondary motor vehicle feature.
		int PU_RADAR_CHECK_DIR_OSD = 32; // Radar-based speed estimation direction.
		int PU_VEHICLE_DIR_OSD = 33; // Vehicle driving direction.
		int PU_VEHICLE_TYPE_EXT_OSD = 34; // Extended vehicle type.
		int PU_PIC_OSD_TYPE_MAX = 35;
	}

	// Image quality.
	public interface PU_PIC_QUALITY {
		public static final int PU_PIC_QUALITY_BEST = 0; // Supreme
		public static final int PU_PIC_QUALITY_MORE_BETTER = 1; // Excellent
		public static final int PU_PIC_QUALITY_BETTER = 2; // Great
		public static final int PU_PIC_QUALITY_ORDINARY = 3; // Good
		public static final int PU_PIC_QUALITY_BAD = 4; // Average
		public static final int PU_PIC_QUALITY_BADEST = 5; // Poor
		public static final int PU_PIC_QUALITY_MAX = 6;
	}

	// Image synthesis data structure in the earlier versions.
	public static class PU_PIC_SYNTHESIS_PARA_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable image synthesis.

		// Member variables used in earlier versions (forward compatible).
		/* C type : PU_ONE_PIC_SYNTHESIS_TYPE_E */
		public int enOnePicSynthesisType;
		/* C type : PU_TWO_PIC_SYNTHESIS_TYPE_E */
		public int enTwoPicSynthesisType;
		/* C type : PU_THREE_PIC_SYNTHESIS_TYPE_E */
		public int enThreePicSynthesisType;

		public PU_PIC_SYNTHESIS_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "enOnePicSynthesisType", "enTwoPicSynthesisType",
					"enThreePicSynthesisType");
		}
	}

	// Image synthesis data structure in the earlier versions.
	public static class PU_PIC_SYNTHESIS_PARA_V2_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable image synthesis.

		// Member variables used in earlier versions (forward compatible). // Suspended
		// in the new version.
		/* C type : PU_ONE_PIC_SYNTHESIS_TYPE_E */
		public int enOnePicSynthesisType;
		/* C type : PU_TWO_PIC_SYNTHESIS_TYPE_E */
		public int enTwoPicSynthesisType;
		/* C type : PU_THREE_PIC_SYNTHESIS_TYPE_E */
		public int enThreePicSynthesisType;

		// Member variables used in the new version.
		/* C type : PU_COMBINE_TYPE_E */
		public int[] astCombineType = new int[PU_SNAP_NUM_MAX];
		/* C type : PU_COMBINE_IMG_ROI_E */
		public int[] astOnePicROI = new int[2];
		/* C type : PU_COMBINE_IMG_ROI_E */
		public int[] astTwoPicROI = new int[3];
		/* C type : PU_COMBINE_IMG_ROI_E */
		public int[] astThreePicROI = new int[4];
		/* C type : PU_COMBINE_SCALE_E */
		public int enCombineScale; // Synthesized image size.
		public ULONG ulJpegQuality; // 合成图编码质量
		public ULONG[] ulPicSynthesisEnableMask = new ULONG[PU_ITS_PIC_SYNTHESIS_TYPE.ITS_TYPE_PIC_SYNTHESIS_MAX]; // 掩码[2~2^32)，每一位对应PU_ITS_REGULA_TYPE_E中违章是否启用图片合成,手动抓拍(0)不支持合成
		public BOOL bFaceSynthesisEnable; // Indicates whether to enable face synthesis.
		public PU_FACE_SYN_SCALE_TYPE_E enFaceSynthesisScale; // Size of a face cutout.
		public byte[] szReserved = new byte[PU_RESERVE_LEN
				- (LLong.size * PU_ITS_PIC_SYNTHESIS_TYPE.ITS_TYPE_PIC_SYNTHESIS_MAX) - 4 - 4];

		public PU_PIC_SYNTHESIS_PARA_V2_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "enOnePicSynthesisType", "enTwoPicSynthesisType",
					"enThreePicSynthesisType", "astCombineType", "astOnePicROI", "astTwoPicROI", "astThreePicROI",
					"enCombineScale", "ulJpegQuality", "ulPicSynthesisEnableMask", "bFaceSynthesisEnable",
					"enFaceSynthesisScale", "szReserved");
		}
	}

	// Image synthesis data structure in the new version.
	public static class PU_PIC_SYNTHESIS_PARA_V3_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable image synthesis.

		// Member variables used in earlier versions (forward compatible). // Suspended
		// in the new version.
		/* C type : PU_ONE_PIC_SYNTHESIS_TYPE_E */
		public int enOnePicSynthesisType;
		/* C type : PU_TWO_PIC_SYNTHESIS_TYPE_E */
		public int enTwoPicSynthesisType;
		/* C type : PU_THREE_PIC_SYNTHESIS_TYPE_E */
		public int enThreePicSynthesisType;

		// Member variables used in the new version.
		/* C type : PU_COMBINE_TYPE_E */
		public int[] astCombineType = new int[PU_SNAP_NUM_MAX2];
		/* C type : PU_COMBINE_IMG_ROI_E */
		public int[] astOnePicROI = new int[2];
		/* C type : PU_COMBINE_IMG_ROI_E */
		public int[] astTwoPicROI = new int[3];
		/* C type : PU_COMBINE_IMG_ROI_E */
		public int[] astThreePicROI = new int[6];
		/* C type : PU_COMBINE_SCALE_E */
		public int enCombineScale; // Synthesized image size.
		public ULONG ulJpegQuality; // Synthesized image encoding quality.
		public ULONG ulPicSynthesisEnableMask[] = new ULONG[PU_ITS_PIC_SYNTHESIS_TYPE.ITS_TYPE_PIC_SYNTHESIS_MAX]; // 掩码[2~2^32)，每一位对应PU_ITS_REGULA_TYPE_E中违章是否启用图片合成,手动抓拍(0)不支持合成
		public BOOL bFaceSynthesisEnable; // Indicates whether to enable face synthesis.
		public PU_FACE_SYN_SCALE_TYPE_E enFaceSynthesisScale; // Size of a face cutout.
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_PIC_SYNTHESIS_PARA_V3_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "enOnePicSynthesisType", "enTwoPicSynthesisType",
					"enThreePicSynthesisType", "astCombineType", "astOnePicROI", "astTwoPicROI", "astThreePicROI",
					"enCombineScale", "ulJpegQuality", "ulPicSynthesisEnableMask", "bFaceSynthesisEnable",
					"enFaceSynthesisScale", "szReserved");
		}
	}

	// License plate movement direction.
	public interface PU_PLATE_DIR {
		public static final int PU_LPR_UNKNOWN = 0; // Unknown.
		public static final int PU_LPR_LEFT = 1; // Left.
		public static final int PU_LPR_RIGHT = 2; // Right.
		public static final int PU_LPR_UP = 3; // Up.
		public static final int PU_LPR_DOWN = 4; // Down.
	}

	public static class PU_PLATE_INFO_S extends Structure {
		public boolean bHavePlate; // Indicates whether to take a snapshot of a license plate.

		public int iConfidence; // License plate confidence.
		public int iPlateCharNum;
		public byte[] szPlateChar = new byte[36];
		public PU_AREA_INFO_S.ByValue stPlateLoc;
		public int enPlateType;
		public int enPlateColor;
		public int enMoveDir;
		public byte[] szReserved = new byte[64 - 12];

		public PU_PLATE_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bHavePlate", "iConfidence", "iPlateCharNum", "szPlateChar", "stPlateLoc",
					"enPlateType", "enPlateColor", "enMoveDir", "szReserved");
		}
	}

	// GB/T 28281 platform parameters.
	public static class PU_PLATFORM_GBT_PARA extends Structure {
		public WinDef.BOOL bEnable;
		public byte[] szLoginDomain = new byte[PU_PLATFORM_INFO_LEN];
		public byte[] szLoginName = new byte[PU_PLATFORM_INFO_LEN]; // The device ID is the same as the login name.
		public byte[] szPlatformId = new byte[PU_PLATFORM_INFO_LEN]; // Server code.
		public byte[] szPassword = new byte[PU_PLATFORM_INFO_LEN];
		public byte[] szServerIp = new byte[PU_IP4_ADDR_LEN];
		public ULONG ulServerPort;
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // szReserve[0]: network adapter index.
		// szReserve[1]: input parameter, indicating the platform type. The options are
		// as follows: 0: GB/T 28181-1, 1: GB/T 28181-2.

		public PU_PLATFORM_GBT_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szLoginDomain", "szLoginName", "szPlatformId", "szPassword", "szServerIp",
					"ulServerPort", "szReserve");
		}
	}

	// Active SDK registration address.
	public static class PU_PLATFORM_SDK_PARA extends Structure {
		public WinDef.BOOL bEnable;
		public PU_SDK_PLATFORM_MODE_E enSdkPlatformMode;
		public byte[] szDeviceId = new byte[PU_PLATFORM_INFO_LEN];
		public byte[] szPlatformIp = new byte[PU_IP4_ADDR_LEN];
		public ULONG szPlatformPort;
		public byte[] szBackupPlatformIp = new byte[PU_IP4_ADDR_LEN];
		public ULONG szBackupPlatformPort;
		public PU_CONNECT_TYPE enConnectType;
		public ULONG ulMeshIndex; // Network adapter index.
		public byte[] szReserve = new byte[PU_RESERVE_LEN - 4 - LLong.size];

		public PU_PLATFORM_SDK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "enSdkPlatformMode", "szDeviceId", "szPlatformIp", "szPlatformPort",
					"szBackupPlatformIp", "szBackupPlatformPort", "enConnectType", "ulMeshIndex", "szReserve");
		}
	}

	// Platform type (platform configuration).
	public interface PU_PLATFORM_TYPE {
		public static final int PU_PLATFORM_TYPE_NVS = 1; // NVS platform.
		public static final int PU_PLATFORM_TYPE_IVS = 2; // IVS platform.
		public static final int PU_PLATFORM_TYPE_GBT = 3; // GB/T 28281 platform.
		public static final int PU_PLATFORM_TYPE_IVS_ENABLE = 4; // IVS platform (can be enabled or disabled).
		public static final int PU_PLATFORM_TYPE_GBT_ENABLE = 5; // GB/T 28281 (can be enabled or disabled).
		public static final int PU_PLATFORM_TYPE_SDK_ENABLE = 6; // SDK platform (can be enabled or disabled).
		public static final int PU_PLATFORM_TYPE_OTHERS = 7;
		public static final int PU_PLATFORM_TYPE_MAX = 8;
	}

	public static class PU_POINT extends Structure {
		public WinDef.USHORT usPosX; // X coordinate (0-352).
		public WinDef.USHORT usPosY; // Y coordinate (0-288).

		public PU_POINT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("usPosX", "usPosY");
		}
	}

	// Media port information.
	public static class PU_PORT_INFO extends Structure {
		public ULONG ulInterLeavedPort; // Interleaving port.
		public ULONG ulVideoRtpPort; // Video RTP port.
		public ULONG ulVideoRtcpPort; // Video RTCP port.
		public ULONG ulAudioRtpPort; // Audio RTP port.
		public ULONG ulAudioRtcpPort; // Audio RTCP port.
		public ULONG ulIgtRtpPort; // Intelligent RTP port.
		public ULONG ulIgtRtcpPort; // Intelligent RTCP port.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_PORT_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulInterLeavedPort", "ulVideoRtpPort", "ulVideoRtcpPort", "ulAudioRtpPort",
					"ulAudioRtcpPort", "ulIgtRtpPort", "ulIgtRtcpPort", "szReserved");
		}
	}

	// Port mode.
	public interface PU_PORT_MODE {
		public static final int PU_PORT_MODE_1 = 1; // 1-pane.
		public static final int PU_PORT_MODE_2 = 2; // 2-pane.
		public static final int PU_PORT_MODE_4 = 4; // 4-pane.
		public static final int PU_PORT_MODE_9 = 9; // 9-pane.
		public static final int PU_PORT_MODE_16 = 16; // 16-pane.
		public static final int PU_PORT_MODE_MAX = 17;
	}

	// Port type.
	public interface PU_PORT_TYPE {
		public static final int PU_PORT_TYPE_HDMI = 0;
		public static final int PU_PORT_TYPE_VGA = 1;
		public static final int PU_PORT_TYPE_BNC = 2;
		public static final int PU_PORT_TYPE_DVI = 3;
		public static final int PU_PORT_TYPE_MAX = 4;
	}

	// Single-channel information.
	public static class PU_PRE_CHANNEL_INFO_S extends Structure {
		public static class ByReference extends PU_PRE_CHANNEL_INFO_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulChannelID; // Channel ID.
		public int enSlaveChanStatus; // Channel status.

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enSlaveChanStatus", "szReserved");
		}
	}

	// Exact number.
	public static class PU_PRECISE_FIGURES_S extends Structure {
		public ULONG ulIntValue; // Integer part of the number.
		public ULONG ulDotValue; // Decimal part of the number.

		public PU_PRECISE_FIGURES_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIntValue", "ulDotValue");
		}
	}

	/*
	 * SNMPv1v2c community information extension (longer community name supported).
	 */

	// Preset position.
	public class PU_PRESET_SCAN_PARA extends Structure {
		public NativeLong ulPresetIndex; // Preset position ID.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPresetIndex");
		}
	}

	// Privacy mask area list.
	public static class PU_PRIVACY_MASK_AREA_ARRAY extends Structure {
		public ULONG ulChannelID;
		public ULONG ulNum;
		public WinDef.BOOL bEnable;
		public PU_MASK_AREA_PARA[] stMaskParaEx = (PU_MASK_AREA_PARA[]) new PU_MASK_AREA_PARA()
				.toArray(PU_PRIVACY_MASK_MAX);
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_PRIVACY_MASK_AREA_ARRAY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulNum", "bEnable", "stMaskParaEx");
		}
	}

	// Privacy mask area list.
	public static class PU_PRIVACY_MASK_AREA_LIST extends Structure {
		public ULONG ulChnID;
		public ULONG ulTotalNum;
		public ULONG ulBeginIndex;
		public ULONG ulEndIndex;
		public WinDef.BOOL bEnable;
		public PU_MASK_AREA_PARA_V20[] stMaskPara = (PU_MASK_AREA_PARA_V20[]) new PU_MASK_AREA_PARA_V20()
				.toArray(PU_PRIVACY_MASK_MAX);
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_PRIVACY_MASK_AREA_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulIndex", "stMaskAreaPara", "szReserve");
		}
	}

	// Privacy mask area list.
	public static class PU_PRIVACY_MASK_ARRAY extends Structure {
		public ULONG ulChannelID;
		public ULONG ulNum;
		public WinDef.BOOL bEnable;
		public PU_MASK_PARA[] stMaskPara = (PU_MASK_PARA[]) new PU_MASK_PARA().toArray(PU_PRIVACY_MASK_MAX);

		public PU_PRIVACY_MASK_ARRAY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulNum", "bEnable", "stMaskPara");
		}
	}

	// Privacy mask area list.
	public static class PU_PRIVACY_MASK_ARRAY_EX extends Structure {
		public ULONG ulChannelID;
		public ULONG ulNum;
		public WinDef.BOOL bEnable;
		public PU_MASK_PARA_EX[] stMaskParaEx = (PU_MASK_PARA_EX[]) new PU_MASK_PARA_EX().toArray(PU_PRIVACY_MASK_MAX);
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_PRIVACY_MASK_ARRAY_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulNum", "bEnable", "stMaskParaEx", "szReserve");
		}
	}

	// Transmission type.
	public interface PU_PROTOCOL_TYPE_E {
		public static final int PU_PROTOCOL_TYPE_UDP = 0; // UDP mode.
		public static final int PU_PROTOCOL_TYPE_TCP = 1; // TCP mode.
		public static final int PU_PROTOCOL_TYPE_MULTICAST = 2; // Multicast mode.
		public static final int PU_PROTOCOL_TYPE_MAX = 3;
	}

	public interface PU_PTZ_AUX_MODE {
		public static final int PU_AUX_MODE_PROTOCOL = 0; // Wiper protocol mode.
		public static final int PU_AUX_MODE_ALARMOUT = 1; // Boolean value output mode.
		public static final int PU_AUX_MODE_TORRENTIAL_RAIN = 2; // Wiper torrential rain mode.
		public static final int PU_AUX_MODE_MODERATE_RAIN = 3; // Wiper moderate rain mode.
		public static final int PU_AUX_MODE_BRUSH_FIVE_TIMES = 4; // Swipe for five times consecutively.
		public static final int PU_AUX_MODE_MAX = 5;
	}

	/************* PTZ dome camera self-check *************/
	public static class PU_PTZ_CHECK_PARA_S extends Structure {
		public WinDef.BOOL enEnable;
		public ULONG ulInterval; // Self-check interval.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_PTZ_CHECK_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enEnable", "ulInterval", "szReserved");
		}
	}

	// Direction control.
	public interface PU_PTZ_CONTROL_MODE {
		public static final int PU_PTZ_CONTROL_MODE_FORWARD = 1;
		public static final int PU_PTZ_CONTROL_MODE_BACK = 2;
		public static final int PU_PTZ_CONTROL_MODE_MAX = 3;
	}

	// Tour track operation command word.
	public interface PU_PTZ_CRUISE_TRACK {
		public static final int PU_PTZ_CRUISE_TRACK_SET = 1; // Setting the tour track.
		public static final int PU_PTZ_CRUISE_TRACK_GET = 2; // Obtain tour tacks.
		public static final int PU_PTZ_CRUISE_TRACK_CLR = 3; // Clear a tour track.
		public static final int PU_PTZ_CRUISE_TRACK_GOTO = 4; // Invoke a tour track.
		public static final int PU_PTZ_CRUISE_TRACK_STOP = 5; // Stop tour.
		public static final int PU_PTZ_CRUISE_TRACK_MAX = 6;
	}

	// Tour information.
	public class PU_PTZ_CRUISE_TRACK_PARA extends Structure {
		public WinDef.ULONG ulPtzId; // PTZ ID.

		public WinDef.ULONG ulCruiseTrackIndex; // Tour ID.
		public WinDef.ULONG ulCruiseType; // Tour mode (1: track scan; 2: pattern scan).
		public byte[] szCuriseTrackName = new byte[PU_PTZ_CRUISE_LEN]; // Tour name.
		public WinDef.ULONG ulPointNum; // Number of preset positions in a tour.
		public PU_CRUISE_POINT[] stCruisePoint = new PU_CRUISE_POINT[PU_PTZ_CRUISE_POINT_MAX]; // List of preset
																								// positions in a tour.
		public int enPtzCruiseTrack; // Tour track operation command word.

		public PU_PTZ_CRUISE_TRACK_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPtzId", "ulCruiseTrackIndex", "ulCruiseType", "szCuriseTrackName", "ulPointNum",
					"stCruisePoint", "enPtzCruiseTrack");
		}
	}

	// PTZ location information: total zoom ratio (1–30 x 12 = 240).
	public class PU_PTZ_CURRENT_LOCATION extends Structure {
		public NativeLong lPTZHorDegree; // Horizontal angle (0° to 359°).

		public NativeLong lPTZVerDegree; // Vertical angle (–10° to +90°).
		public int ulLenMultiple; // Integral part of the lens zoom ratio (1–30. If the digital zoom is not 0, the
									// lens zoom ratio is the maximum value 30 by default.).
		public int ulDotLenMultiple; // Decimal part of the lens zoom ratio (0–99; accurate only to one decimal
										// place).
		public int ulZoomRatio; // Integral part of the digital zoom (0–12. The parameter is set when the lens
								// zoom ratio reaches the maximum value. The value 0 indicates that this
								// parameter is not set. The total zoom ratio is the multiplication of zoom
								// ratios.)
		public int ulDotZoomRatio; // Decimal part of the digital zoom (0–99; accurate only to one decimal place).
		public int lPTZDotHorDegree; // Decimal part of the horizontal angle (0–99; accurate only to one decimal
										// place).
		public NativeLong lPTZDotVerDegree; // Decimal part of the vertical angle (–99 to +99; accurate only to one
											// decimal place).
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_PTZ_CURRENT_LOCATION() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("lPTZHorDegree", "lPTZVerDegree", "ulLenMultiple", "ulDotLenMultiple", "ulZoomRatio",
					"ulDotZoomRatio", "lPTZDotHorDegree", "lPTZDotVerDegree", "szReserved");
		}
	}

	// 云台位置信息扩展：总变倍数（1 ~ 30*12=240）
	public static class PU_PTZ_CURRENT_LOCATION_EX extends Structure {
		public NativeLong lPTZHorDegree; // Horizontal angle (0° to 359°).
		public NativeLong lPTZVerDegree; // Vertical angle (–10° to +90°).
		public ULONG ulLenMultiple; // Integral part of the lens zoom ratio (1–30. If the digital zoom is not 0, the
									// lens zoom ratio is the maximum value 30 by default.).
		public ULONG ulDotLenMultiple; // Decimal part of the lens zoom ratio (0–99; accurate only to one decimal
										// place).
		public ULONG ulZoomRatio; // Integral part of the digital zoom (0–12. The parameter is set when the lens
									// zoom ratio reaches the maximum value. The value 0 indicates that this
									// parameter is not set. The total zoom ratio is the multiplication of zoom
									// ratios.)
		public ULONG ulDotZoomRatio; // Decimal part of the digital zoom (0–99; accurate only to one decimal place).
		public NativeLong lPTZDotHorDegree; // Decimal part of the horizontal angle (0–99; accurate only to one decimal
											// place).
		public NativeLong lPTZDotVerDegree; // Decimal part of the vertical angle (–99 to +99; accurate only to one
											// decimal place).
		public float fAbsPTZHorDegree; // Absolute horizontal angle.
		public float fAbsPTZVerDegree; // Absolute vertical angle.
		public NativeLong lZoomPos; // Zoom position.
		public NativeLong lFocusPos; // Focus position.
		public BOOL bZoomFlag; // true: zoom ratio; false: motor position.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_PTZ_CURRENT_LOCATION_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("lPTZHorDegree", "lPTZVerDegree", "ulLenMultiple", "ulDotLenMultiple", "ulZoomRatio",
					"ulDotZoomRatio", "lPTZDotHorDegree", "lPTZDotVerDegree", "fAbsPTZHorDegree", "fAbsPTZVerDegree",
					"lZoomPos", "lFocusPos", "bZoomFlag", "szReserved");
		}
	}

	// PTZ decoder type.
	public interface PU_PTZ_DECODER_TYPE {
		public static final int PU_PTZ_DECODER_PELCO_P = 1;
		public static final int PU_PTZ_DECODER_PELCO_D = 2;
		public static final int PU_PTZ_DECODER_YAAN = 3;
		public static final int PU_PTZ_DECODER_SAMSUNG = 4;
		public static final int PU_PTZ_DECODER_REDAPPLE_5052 = 5;
		public static final int PU_PTZ_DECODER_TAISHUO = 6;
		public static final int PU_PTZ_DECODER_REDAPPLE_5051 = 7;
		public static final int PU_PTZ_DECODER_USER_DEF = 8;
		public static final int PU_PTZ_DECODER_MAX = 9;
	}

	public interface PU_PTZ_DIRECTION {
		public static final int PU_PTZ_DIRECTION_UP = 0; // Up.
		public static final int PU_PTZ_DIRECTION_DOWN = 1; // Down.
		public static final int PU_PTZ_DIRECTION_LEFT = 2; // Left.
		public static final int PU_PTZ_DIRECTION_RIGHT = 3; // Right.
		public static final int PU_PTZ_DIRECTION_MAX = 4;
	}

	/********* Focus mode *********/
	public static class PU_PTZ_FOCUS_MODE_S extends Structure {
		public ULONG ulPtzId; // PTZ ID.
		/* C type : PU_FOCUS_MODE */
		public int enFocusMode; // Focus mode.
		public ULONG ulFocusSensitivity;// 聚焦灵敏度(仅在自动聚焦模式有效)，范围0~2
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_PTZ_FOCUS_MODE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPtzId", "enFocusMode", "ulFocusSensitivity", "szReserved");
		}
	}

	// Focus area settings.
	public static class PU_PTZ_FOCUSAREA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public ULONG[][] ulFocusArea = new ULONG[PU_FOCUSAREA_ROW][PU_FOCUSAREA_COL]; // Automatic focus environment
																						// data.

		public PU_PTZ_FOCUSAREA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulFocusArea");
		}
	}

	// PTZ PT speed at each level.
	public static class PU_PTZ_GEAR_SPEED_S extends Structure {
		public int nGear; // Level.
		public int nPanSpeed; // Pan speed.
		public int nTiltSpeed; // Tilt speed.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("nGear", "nPanSpeed", "nTiltSpeed");
		}
	}

	// PTZ rotation mode.
	public interface PU_PTZ_MOTION_MODE {
		public static final int PU_PTZ_MOTION_MODE_BURST = 1; // Step mode.
		public static final int PU_PTZ_MOTION_MODE_CONTINUOUS = 2; // Continuous mode.
		public static final int PU_PTZ_MOTION_MODE_MAX = 3;
	}

	// PTZ control.
	public interface PU_PTZ_OPCODE {
		public static final int PU_PTZ_STOP = 1; // The PTZ stops. Ignore para1 and para2.
		public static final int PU_PTZ_UP = 2; // Rotate the PTZ upward. The param1 parameter indicates the rotation
												// mode. The value 1 indicates the step mode. The value 2 indicates the
												// continuous mode. The param2 parameter specifies the PTZ rotation
												// speed. The value ranges from 1 to 10.
		public static final int PU_PTZ_DOWN = 3; // Rotate the PTZ downward. The param1 parameter indicates the rotation
													// mode. The value 1 indicates the step mode. The value 2 indicates
													// the continuous mode. The param2 parameter specifies the PTZ
													// rotation speed. The value ranges from 1 to 10.
		public static final int PU_PTZ_LEFT = 4; // Rotate the PTZ leftward. The param1 parameter indicates the rotation
													// mode. The value 1 indicates the step mode. The value 2 indicates
													// the continuous mode. The param2 parameter specifies the PTZ
													// rotation speed. The value ranges from 1 to 10.
		public static final int PU_PTZ_UP_LEFT = 5; // Rotate the PTZ upper leftward. The param1 parameter indicates the
													// rotation mode. The value 1 indicates the step mode. The value 2
													// indicates the continuous mode. The param2 parameter specifies the
													// PTZ rotation speed. The value ranges from 1 to 10.
		public static final int PU_PTZ_DOWN_LEFT = 6; // Rotate the PTZ lower leftward. The param1 parameter indicates
														// the rotation mode. The value 1 indicates the step mode. The
														// value 2 indicates the continuous mode. The param2 parameter
														// specifies the PTZ rotation speed. The value ranges from 1 to
														// 10.
		public static final int PU_PTZ_RIGHT = 7; // Rotate the PTZ rightward. The param1 parameter indicates the
													// rotation mode. The value 1 indicates the step mode. The value 2
													// indicates the continuous mode. The param2 parameter specifies the
													// PTZ rotation speed. The value ranges from 1 to 10.
		public static final int PU_PTZ_UP_RIGHT = 8; // Rotate the PTZ upper rightward. The param1 parameter indicates
														// the rotation mode. The value 1 indicates the step mode. The
														// value 2 indicates the continuous mode. The param2 parameter
														// specifies the PTZ rotation speed. The value ranges from 1 to
														// 10.
		public static final int PU_PTZ_DOWN_RIGHT = 9; // Rotate the PTZ lower rightward. The param1 parameter indicates
														// the rotation mode. The value 1 indicates the step mode. The
														// value 2 indicates the continuous mode. The param2 parameter
														// specifies the PTZ rotation speed. The value ranges from 1 to
														// 10.
		public static final int PU_PTZ_AUTO = 10; // The PTZ control is automatic. Ignore para1 and para2.
		public static final int PU_PTZ_PRESET_RUN = 11; // Rotate to a preset position. The para1 parameter indicates
														// the preset position ID. Ignore para2.
		public static final int PU_PTZ_CRUISE_RUN = 12; // Rotate along the tour track. The para1 parameter indicates
														// the tour track ID. Ignore para2.
		public static final int PU_PTZ_CRUISE_STOP = 13; // Moving along the tour track stops. Ignore para1 and para2.
		public static final int PU_PTZ_FLIP = 17; // The PTZ rotates 180 degrees. Ignore para1 and para2.
		public static final int PU_PTZ_HOMING = 18; // The camera returns to the home position. Ignore para1 and para2.
		// Lens control.
		public static final int PU_PTZ_LENS_APERTURE_OPEN = 19; // Opens up the aperture. Ignore para1 and para2.
		public static final int PU_PTZ_LENS_APERTURE_CLOSE = 20; // Close down the aperture. Ignore para1 and para2.
		public static final int PU_PTZ_LENS_ZOOM_WIDE = 21; // Enlarge the field of view, that is, ZOOM OUT. The param1
															// parameter indicates the rotation mode. The value is fixed
															// at 2, indicating the continuous mode. The param2
															// parameter indicates the speed.
		public static final int PU_PTZ_LENS_ZOOM_TELESCOPE = 22; // Narrow the field of view, that is, ZOOM IN. The
																	// param1 parameter indicates the rotation mode. The
																	// value is fixed at 2, indicating the continuous
																	// mode. The param2 parameter indicates the speed.

		/* This parameter is not recommended in the new version. */
		public static final int PU_PTZ_LENS_ZOOM_IN = 21; // (You are advised to use PU_PTZ_LENS_ZOOM_WIDE instead of
															// this parameter in the new version.)
		public static final int PU_PTZ_LENS_ZOOM_OUT = 22; // (You are advised to use PU_PTZ_LENS_ZOOM_TELESCOPE instead
															// of this parameter in the new version.)

		public static final int PU_PTZ_LENS_ZOOM_STOP = 23; // Stop zooming.
		public static final int PU_PTZ_LENS_FOCAL_NEAR = 24; // Focus near. The param1 parameter indicates the rotation
																// mode. The value is fixed at 2, indicating the
																// continuous mode. The param2 parameter indicates the
																// speed. The value ranges from 1 to 10.
		public static final int PU_PTZ_LENS_FOCAL_FAR = 25; // Focus far. The param1 parameter indicates the rotation
															// mode. The value is fixed at 2, indicating the continuous
															// mode. The param2 parameter indicates the speed. The value
															// ranges from 1 to 10.
		public static final int PU_PTZ_LENS_FOCAL_STOP = 26; // Stop adjusting the focus.
		public static final int PU_PTZ_AUX_OPEN = 27; // The auxiliary device is enabled. para1 indicates the device
														// name. Ignore para2.
		public static final int PU_PTZ_AUX_STOP = 28; // The auxiliary device is disabled. para1 indicates the device
														// name. Ignore para2.
		public static final int PU_PTZ_HORIZONTAL_SCAN = 29; // Horizontal scan. The para1 parameter indicates the
																// direction, and para2 indicates the speed (range:
																// 1-10).
		public static final int PU_PTZ_VERTICAL_SCAN = 30; // Vertical scan. Ignore para1. The para2 parameter indicates
															// the speed (range: 1-10).
		public static final int PU_PTZ_MODE_SET_START = 31; // Start recording the pattern scan path.
		public static final int PU_PTZ_MODE_SET_STOP = 32; // Stop recording the pattern scan path.
		public static final int PU_PTZ_FAST_LOCATE = 33; // 3D positioning.
		public static final int PU_PTZ_FAST_RETURN = 34; // 3D return.
		public static final int PU_PTZ_REBOOT = 35; // Restart the electromechanics board.
		public static final int PU_PTZ_RESTORE = 36; // Restore the electromechanics board to default settings.
		public static final int PU_PTZ_SET_LEFT_LIMIT = 37; // Set the left limit.
		public static final int PU_PTZ_SET_RIGHT_LIMIT = 38; // Set the right limit.
		public static final int PU_PTZ_MODE_CRUISE_START = 39; // Pattern scan starts.The para1 parameter indicates the
																// tour track ID. Ignore para2.
		public static final int PU_PTZ_MODE_CRUISE_STOP = 40; // Pattern scan stops. The para1 parameter indicates the
																// tour track ID. Ignore para2.
		public static final int PU_PTZ_FAST_MOVE = 41; // Select a point for quick positioning. The para1 parameter
														// indicates the x coordinate, and the para2 parameter indicates
														// the y coordinate.
		public static final int PU_PTZ_HORIZONTAL_LIMIT_SCAN = 51; // Horizontal limit scan. The param1 parameter
																	// indicates the rotation mode. The value is fixed
																	// at 2, indicating the continuous mode. The param2
																	// parameter indicates the speed. The value ranges
																	// from 1 to 10.
		public static final int PU_PTZ_LENS_AUTO_FOCAL = 52; // Auto focus.
		public static final int PU_PTZ_GOTO_HOME = 53; // Rotate to the home position.
		public static final int PU_PTZ_ONE_PUSH = 54; // OnePush focus of the bullet camera.
		public static final int PTZ_VERTICAL_LIMIT_SCAN = 55; // Vertical limit scan. The param1 parameter indicates the
																// rotation mode. The value is fixed at 2, indicating
																// the continuous mode. The param2 parameter indicates
																// the speed. The value ranges from 1 to 10.
		public static final int PTZ_SET_UP_LIMIT = 56; // Set the upper limit.
		public static final int PTZ_SET_DOWN_LIMIT = 57; // Set the lower limit.
		public static final int PU_PTZ_CMD_MAX = 58;
	}

	// PTZ parameters.
	public static class PU_PTZ_PARA extends Structure {
		public ULONG ulPtzId; // PTZ ID.
		public ULONG ulSerialPort; // Serial port number.
		/* C type : PU_PTZ_DECODER_TYPE */
		public int enDecoderType; // Decoder type.
		public ULONG ulDecoderAddress; // Decoder IP address.
		/* C type : PU_PTZ_CONTROL_MODE */
		public int enPtzControlMode; // Direction control (forward or backward).
		public WinDef.BOOL bEnable; // Indicates whether to enable PTZ control.

		public PU_PTZ_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPtzId", "ulSerialPort", "enDecoderType", "ulDecoderAddress", "enPtzControlMode",
					"bEnable");
		}
	}

	// Preset position operation command word.
	public interface PU_PTZ_PRESET_CMD {
		public static final int PU_PTZ_PRESET_SET = 1; // Set preset positions.
		public static final int PU_PTZ_PRESET_GET = 2; // Obtain the preset position.
		public static final int PU_PTZ_PRESET_CLR = 3; // Delete a preset position.
		public static final int PU_PTZ_PRESET_GOTO = 4; // Rotate to a preset position.
		public static final int PU_PTZ_PRESET_MAX = 5;
	}

	// Preset position information.
	public class PU_PTZ_PRESET_INFO extends Structure {
		public WinDef.ULONG ulIndex;
		public byte[] szPresetName = new byte[PU_PTZ_NAME_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "szPresetName");
		}
	}

	// Preset position information (including the function of enabling or disabling
	// focus memory).
	public static class PU_PTZ_PRESET_INFO_EX extends Structure {
		public ULONG ulIndex;
		public byte[] szPresetName = new byte[PU_PTZ_NAME_LEN];
		public WinDef.BOOL bEnableFocusInfo; // Indicates whether to enable focus memory.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_PTZ_PRESET_INFO_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "szPresetName", "bEnableFocusInfo", "szReserve");
		}
	}

	// Preset position list.
	public class PU_PTZ_PRESET_LIST_PARA extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public WinDef.ULONG ulBeginIndex; // Start ID of preset positions.
		public WinDef.ULONG ulEndIndex; // End ID of preset positions.
		public WinDef.ULONG ulTotalNum; // Actual number of preset positions that are returned.
		public PU_PTZ_PRESET_INFO[] stPtzPresetInfo = new PU_PTZ_PRESET_INFO[PU_PTZ_PRESET_NUM]; // Preset position
																									// information.

		public PU_PTZ_PRESET_LIST_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulBeginIndex", "ulEndIndex", "ulTotalNum", "stPtzPresetInfo");
		}
	}

	// PTZ preset position list (including the function of enabling or disabling
	// focus memory).
	public static class PU_PTZ_PRESET_LIST_PARA_EX extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulBeginIndex; // Start ID of preset positions.
		public ULONG ulEndIndex; // End ID of preset positions.
		public ULONG ulTotalNum; // Actual number of preset positions that are returned.
		public PU_PTZ_PRESET_INFO_EX[] stPtzPresetInfo = new PU_PTZ_PRESET_INFO_EX[PU_PTZ_PRESET_NUM]; // Preset
																										// position
																										// information.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_PTZ_PRESET_LIST_PARA_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulBeginIndex", "ulEndIndex", "ulTotalNum", "stPtzPresetInfo",
					"szReserve");
		}
	}

	// PTZ preset position.
	public class PU_PTZ_PRESET_PARA extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public byte[] szPresetName = new byte[PU_PTZ_NAME_LEN]; // Preset position name.
		public WinDef.ULONG ulIndex; // Preset position index.
		public int enPresetCmd; // Preset position command word.

		public PU_PTZ_PRESET_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "szPresetName", "ulIndex", "enPresetCmd");
		}
	}

	// PTZ preset position (including the function of enabling or disabling focus
	// memory).
	public static class PU_PTZ_PRESET_PARA_EX extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public byte[] szPresetName = new byte[PU_PTZ_NAME_LEN]; // Preset position name.
		public ULONG ulIndex; // Preset position index.
		/* C type : PU_PTZ_PRESET_CMD_E */
		public int enPresetCmd; // Preset position command word.
		public WinDef.BOOL bEnableFocusInfo; // Indicates whether to enable focus memory. The options are as follows: 0:
												// disable; 1: enable.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_PTZ_PRESET_PARA_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "szPresetName", "ulIndex", "enPresetCmd", "bEnableFocusInfo",
					"szReserve");
		}
	}

	// PTZ speed capability.
	public static class PU_PTZ_SPEED_ABILITY extends Structure {
		public ULONG ulPanSpeedMax; // Maximum pan speed (unit: degree/second).
		public ULONG ulTiltSpeedMax; // Maximum tilt speed (unit: degree/second).

		public PU_PTZ_SPEED_ABILITY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPanSpeedMax", "ulTiltSpeedMax");
		}
	}

	// PTZ speed limit.
	public static class PU_PTZ_SPEED_LIMIT_S extends Structure {
		public ULONG ulPanSpeedLimit; // Pan speed limit (unit: degree/second).
		public ULONG ulTiltSpeedLimit; // Tilt speed limit (unit: degree/second).

		public PU_PTZ_SPEED_LIMIT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPanSpeedLimit", "ulTiltSpeedLimit");
		}
	}

	// PTZ speed.
	public static class PU_PTZ_SPEED_S extends Structure {
		public PU_PTZ_GEAR_SPEED_S[] stPtzGearSpeed = (PU_PTZ_GEAR_SPEED_S[]) new PU_PTZ_GEAR_SPEED_S()
				.toArray(PU_PTZ_GEAR_NUM_MAX);

		public PU_PTZ_SPEED_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stPtzGearSpeed");
		}
	}

	// TransMicrowave radar configuration.
	public static class PU_RADA_PARA_CHUANSU_S extends Structure {
		// C Type PU_ITS_RADAR_WORK_TYPE_E
		public int enRadarWorkType; // Radar work mode.
		// C Type PU_ITS_RADAR_MSG_SENDTYPE_E
		public int enMsgSendType; // Radar information sending mode.
		// C type PU_ITS_DETECT_DIR_E
		public int enDetectDir; // Detection direction.
		public ULONG uiFixedAngle; // Angle to be corrected. If the speed estimated by radar is inconsistent with
									// the actual speed, correct the angle.
		public ULONG uiSensitivity; // Radar sensitivity.
		public ULONG uiTrigMinInterval; // Minimum triggering distance.
		public ULONG uiTrigMinSpeed; // Minimum triggering speed. If the vehicle speed is below the lower limit,
										// radar detection will not be triggered.
		public ULONG uiHardwareHeight; // Installation height.

		public PU_RADA_PARA_CHUANSU_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enRadarWorkType", "enMsgSendType", "enDetectDir", "uiFixedAngle", "uiSensitivity",
					"uiTrigMinInterval", "uiTrigMinSpeed", "uiHardwareHeight");
		}
	}

	// TransMicrowave radar control information.
	public static class PU_RADAR_CTRL_INFO_S extends Structure {
		public ULONG uiRoadEnable; // Indicates whether to enable the detection for the lane.
		public ULONG uiLaneId; // Lane ID. The value 1 indicates that lane 1 is enabled, and the rest may be
								// deduced by analogy.
		// C Type : PU_ITS_SERIAL_PORT_E
		public int enSerialPortId; // Serial port number.

		public PU_ITS_RS_PARA_S stDevSerialCfg; // Serial port configuration.
		public PU_RADA_PARA_CHUANSU_S stCfgChuanshu; // TransMicrowave radar.
		public PU_ITS_RADA_CTRL_CSRIM_S stCfgMultiChuanshu; // TransMicrowave multi-lane radar.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_RADAR_CTRL_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiRoadEnable", "uiLaneId", "enSerialPortId", "stDevSerialCfg", "stCfgChuanshu",
					"stCfgMultiChuanshu", "szReserve");
		}
	}

	// Random scan.
	public class PU_RANDOM_SCAN_PARA extends Structure {
		public WinDef.ULONG ulInterval; // Interval.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulInterval");
		}
	}

	// Live video viewing structure.
	public static class PU_REAL_PLAY_INFO_S extends Structure {
		public static class ByReference extends PU_REAL_PLAY_INFO_S implements Structure.ByReference {
		}

		public static class ByValue extends PU_REAL_PLAY_INFO_S implements Structure.ByValue {
		}

		public ULONG ulChannelId; // Channel ID.
		public WinDef.HWND hPlayWnd; // Windows window handle.
		public int enStreamType; // Code stream type (primary stream or secondary stream).PU_STREAM_TYPE_E
		public int enVideoType; // Stream type (video, audio, hybrid, or recording).PU_VIDEO_TYPE_E
		public int enProtocolType; // Transmission protocol type (UDP or TCP).PU_PROTOCOL_TYPE_E
		public int enMediaCallbackType; // Callback type. 0: RTP decryption; 1: no RTP decryption; 2: frame; 3:
										// YUV.PU_MEDIA_CALLBACK_TYPE_E
		public byte[] szLocalIp = new byte[PU_IP4_ADDR_LEN]; // IP address of the request end.
		public boolean bKeepLive; // Indicates whether to enable the keep-alive function.
		public PU_TIME_S.ByValue stStartTime; // Start time of requested pre-recording or video recording.
		public PU_TIME_S.ByValue stEndTime; // End time of requested pre-recording or video recording.
		public int enMediaCryptoType; // Encryption type. Only AES encryption is supported.
		public byte[] szMediaCrypto = new byte[PU_CRYPTION_PASSWD_LEN]; // Encryption key.

		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[22] indicates the packaging format of the
																// intelligent analysis data. The value 0 indicates XML,
																// and the value 1 indicates metadata.

		public PU_REAL_PLAY_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "hPlayWnd", "enStreamType", "enVideoType", "enProtocolType",
					"enMediaCallbackType", "szLocalIp", "bKeepLive", "stStartTime", "stEndTime", "enMediaCryptoType",
					"szMediaCrypto", "szReserved");
		}
	}

	// Live video viewing structure.
	public static class PU_REAL_PLAY_INFO_V20 extends Structure {
		public static class ByReference extends PU_REAL_PLAY_INFO_V20 implements Structure.ByReference {
		}

		public static class ByValue extends PU_REAL_PLAY_INFO_V20 implements Structure.ByValue {
		}

		public ULONG ulChannelId; // Channel ID.
		public WinDef.HWND hPlayWnd; // Windows window handle.
		public int enStreamType; // Code stream type (primary stream or secondary stream).PU_STREAM_TYPE_E
		public int enVideoType; // Stream type (video, audio, hybrid, or recording).PU_VIDEO_TYPE_E
		public int enProtocolType; // Transmission protocol type (UDP or TCP).PU_PROTOCOL_TYPE_E
		public int enMediaCallbackType; // Callback type. 0: RTP decryption; 1: no RTP decryption; 2: frame; 3:
										// YUV.PU_MEDIA_CALLBACK_TYPE_E
		public byte[] szLocalIp = new byte[PU_IP6_ADDR_LEN]; // IP address of the request end.
		public boolean bKeepLive; // Indicates whether to enable the keep-alive function.
		public PU_TIME_S.ByValue stStartTime; // Start time of requested pre-recording or video recording.
		public PU_TIME_S.ByValue stEndTime; // End time of requested pre-recording or video recording.
		public int enIGTDataType; // Intelligent data format. 0: XML; 1: metadata.
		public byte[] szMulticastIP = new byte[PU_IP6_ADDR_LEN]; // Multicast IP address (This parameter is required for
																	// multicast streams.)
		public ULONG ulMulticastPort; // Multicast port (This parameter is required for multicast streams.)

		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[22] indicates the packaging format of the
																// intelligent analysis data. The value 0 indicates XML,
																// and the value 1 indicates metadata.

		public PU_REAL_PLAY_INFO_V20() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "hPlayWnd", "enStreamType", "enVideoType", "enProtocolType",
					"enMediaCallbackType", "szLocalIp", "bKeepLive", "stStartTime", "stEndTime", "enIGTDataType",
					"szMulticastIP", "ulMulticastPort", "szReserved");
		}
	}

	// Live video viewing structure.
	public static class PU_REAL_PLAY_INFO_V20_S extends Structure {
		public NativeLong ulChannelId; // Channel ID.

		public WinDef.HWND hPlayWnd; // Windows window handle.

		public int enStreamType; // Code stream type (primary stream or secondary stream).PU_STREAM_TYPE_E

		public int enVideoType; // Stream type (video, audio, hybrid, or recording).PU_VIDEO_TYPE_E

		public int enProtocolType; // Transmission protocol type (UDP or TCP).PU_PROTOCOL_TYPE_E

		public int enMediaCallbackType; // Callback type. 0: RTP decryption; 1: no RTP decryption; 2: frame; 3:
										// YUV.PU_MEDIA_CALLBACK_TYPE_E

		public byte[] szLocalIp = new byte[PU_IP6_ADDR_LEN]; // IP address of the request end.

		public boolean bKeepLive; // Indicates whether to enable the keep-alive function.

		public PU_TIME_S.ByValue stStartTime; // Start time of requested pre-recording or video recording.

		public PU_TIME_S.ByValue stEndTime; // End time of requested pre-recording or video recording.

		public int enIGTDataType = PU_IGT_DATA_TYPE.META_TYPE; // Intelligent data format. 0: XML; 1: metadata.

		public byte[] szMulticastIP = new byte[PU_IP6_ADDR_LEN];// Multicast IP address (This parameter is required for
																// multicast streams.)

		public NativeLong ulMulticastPort; // Multicast port (This parameter is required for multicast streams.)

		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[22] indicates the packaging format of the
																// intelligent analysis data. The value 0 indicates XML,
																// and the value 1 indicates metadata.

		public PU_REAL_PLAY_INFO_V20_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "hPlayWnd", "enStreamType", "enVideoType", "enProtocolType",
					"enMediaCallbackType", "szLocalIp", "bKeepLive", "stStartTime", "stEndTime", "enIGTDataType",
					"szMulticastIP", "ulMulticastPort", "szReserved");
		}
	}

	/* PU-based recording information. */
	public static class PU_RECORD_INFO extends Structure {
		public PU_RECORD_TYPE enRecordType; // Recording type.C type：PU_RECORD_TYPE
		public PU_TIME_S stBeginTime; // Start time segment.
		public PU_TIME_S stEndTime; // End time segment.
		public ULONG ulContentSize; // Recording file size.
		public byte[] szContentID = new byte[PU_RECORD_CONTENTID_LEN]; // Recording file name.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_RECORD_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enRecordType", "stBeginTime", "stEndTime", "ulContentSize", "szContentID",
					"szReserved");
		}
	}

	/* Recording information query. */
	public static class PU_RECORD_INQUIRE extends Structure {
		public ULONG ulChannelId;
		public PU_TIME_S stBeginTime;
		public PU_TIME_S stEndTime;
		public ULONG ulBeginIndex;
		public int[] enRecordTypeList = new int[PU_RECORD_TYPE_NUM]; // PU_RECORD_TYPE
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_RECORD_INQUIRE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stBeginTime", "stEndTime", "ulBeginIndex", "enRecordTypeList",
					"szReserved");
		}
	}

	/* PU-based recording information list. */
	public static class PU_RECORD_LIST extends Structure {
		public ULONG ulTotalNum;
		public ULONG ulBeginIndex;
		public ULONG ulEndIndex;
		public PU_RECORD_INFO[] szRecordInfoList = (PU_RECORD_INFO[]) new PU_RECORD_INFO()
				.toArray(PU_RECORD_INFO_NUM_MAX);
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_RECORD_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulTotalNum", "ulBeginIndex", "ulEndIndex", "szRecordInfoList", "szReserved");
		}
	}

	/* Channel recording plan. */
	public static class PU_RECORD_PLAN extends Structure {
		public ULONG ulChannelId;
		public ULONG ulTotalPlanNum; // Total number of records.
		public PU_TIME_PLAN[] szRecordPlanList = (PU_TIME_PLAN[]) new PU_TIME_PLAN().toArray(PU_RECORD_PLAN_NUM); // Recording
																													// plan
																													// list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_RECORD_PLAN() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulTotalPlanNum", "szRecordPlanList", "szReserved");
		}
	}

	public interface PU_RECORD_TYPE {
		public static final int PU_RECORD_TYPE_ALARM = 0; // Alarm-triggered recording.
		public static final int PU_RECORD_TYPE_MANUAL = 1; // Manual recording.
		public static final int PU_RECORD_TYPE_TIMING = 2; // Scheduled recording.
		public static final int PU_RECORD_METHOD_ADD = 3; // Video buffering.
		public static final int PU_RECORD_METHOD_ALL = 4; // All recording types.
		public static final int PU_RECORD_TYPE_MAX = 5;
	}

	public static class PU_RECT_LOCATE_PARA extends Structure {
		/**
		 * Frame drawing direction.<br>
		 * C type : PU_DRAW_DIR_E
		 */
		public int enDirection;
		/**
		 * Frame information.<br>
		 */
		public PU_AREA_INFO stRect;

		public PU_RECT_LOCATE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDirection", "stRect");
		}
	}

	// Rectangle structure.
	public static class PU_RECTANGLE extends Structure {
		public ULONG ulStartX;
		public ULONG ulStartY;
		public ULONG ulWeight;
		public ULONG ulHeight;

		public PU_RECTANGLE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartX", "ulStartY", "ulWeight", "ulHeight");
		}
	}

	// The request type REQ_NULL indicates the situation that no value is assigned
	// after initialization.
	public interface PU_REQ_TYPE {
		public static final int REQ_NULL = 0;
		public static final int REQ_GET = 1;
		public static final int REQ_SET = 2;
	}

	// Video resolution.
	public static class PU_RESOLUTION_BASIC_PARA extends Structure {
		public WinDef.BOOL bdevIsHD; // Indicates whether the video is of high definition.
		/* C type : PU_RESOLUTION_TYPE_E */
		public int enResolution; // Video resolution.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_RESOLUTION_BASIC_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bdevIsHD", "enResolution", "szReserved");
		}
	}

	// Video resolution information.
	public static class PU_RESOLUTION_INFO extends Structure {
		public PU_RESOLUTION_BASIC_PARA[] astResolutionPara = new PU_RESOLUTION_BASIC_PARA[PU_STREAM_MODE_E.PU_VIEDO_STREAM_TRIPLE]; // Basic
																																		// video
																																		// resolution
																																		// parameter.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_RESOLUTION_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("astResolutionPara", "szReserved");
		}
	}

	// Video resolution type.
	public interface PU_RESOLUTION_TYPE {
		public static final int PU_RESOLUTION_480I = 0;
		public static final int PU_RESOLUTION_576I = 1;
		public static final int PU_RESOLUTION_QCIF_PAL = 2;
		public static final int PU_RESOLUTION_QCIF_NTSC = 3;
		public static final int PU_RESOLUTION_CIF_PAL = 4;
		public static final int PU_RESOLUTION_CIF_NTSC = 5;
		public static final int PU_RESOLUTION_2CIF = 6;
		public static final int PU_RESOLUTION_HD1 = 7;
		public static final int PU_RESOLUTION_D1_PAL = 8; // 720 * 576
		public static final int PU_RESOLUTION_D1_NTSC = 9;
		public static final int PU_RESOLUTION_QVGA = 10; // 320 * 240
		public static final int PU_RESOLUTION_VGA = 11; // 640 * 480
		public static final int PU_RESOLUTION_XGA = 12; // 1024 * 768
		public static final int PU_RESOLUTION_SXGA = 13; // 1400 * 1050
		public static final int PU_RESOLUTION_UXGA = 14; // 1600 * 1200
		public static final int PU_RESOLUTION_QXGA = 15; // 2048 * 1536
		public static final int PU_RESOLUTION_WVGA = 16; // 854 * 480
		public static final int PU_RESOLUTION_WSXGA = 17; // 1680 * 1050
		public static final int PU_RESOLUTION_WUXGA = 18; // 1920 * 1200
		public static final int PU_RESOLUTION_WQXGA = 19; // 2560 * 1600
		public static final int PU_RESOLUTION_HD720 = 20; // 1280 * 720
		public static final int PU_RESOLUTION_HD1080 = 21; // 1920 * 1080
		public static final int PU_RESOLUTION_HD1080I = 22;
		public static final int PU_RESOLUTION_HD960 = 23; // 1280 * 960
		public static final int PU_RESOLUTION_HD1024 = 24; // 1280 * 1024
		public static final int PU_RESOLUTION_HD1296P = 25; // 2304 * 1296
		public static final int PU_RESOLUTION_HD1440P = 26; // 2560 * 1440
		public static final int PU_RESOLUTION_HD1728P = 27; // 3072 * 1728
		public static final int PU_RESOLUTION_HD4K = 28; // 3840 * 2160
		public static final int PU_RESOLUTION_HD1536P = 29; // 2048 * 1536
		public static final int PU_RESOLUTION_HD1920P = 30; // 2560 * 1920
		public static final int PU_RESOLUTION_HD1944P = 31; // 2592 * 1944
		public static final int PU_RESOLUTION_HD2448P = 32; // 3264 * 2448
		public static final int PU_RESOLUTION_HD2160P = 33; // 4096 * 2160
		public static final int PU_RESOLUTION_HD2736P = 34; // 3648 * 2736
		public static final int PU_RESOLUTION_2592_1520P = 35; /* 2592*1520 400W */
		public static final int PU_RESOLUTION_2560_2048 = 36; /* 2560*2048 5:4 500W */
		public static final int PU_RESOLUTION_3072_2048 = 37; /* 3072*2048 3:2 600W */
		public static final int PU_RESOLUTION_MAX = 38;
	}

	/* Red light enhancement parameters. */
	public static class PU_RL_CROP_ENHANCE_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public int iLevel; // Strength (0-100).
		public int iEnable; // Indicates whether to enable red light enhancement.
		public PU_RL_FRAME_PARA stFrameInfo; // Frame information.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_RL_CROP_ENHANCE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "iLevel", "iEnable", "stFrameInfo", "szReserve");
		}
	}

	/* Processed frame information. */
	public static class PU_RL_FRAME_PARA extends Structure {
		public PU_RL_LIGHTINFOS_PARA[] stLightInfo = (PU_RL_LIGHTINFOS_PARA[]) new PU_RL_LIGHTINFOS_PARA()
				.toArray(PU_RL_NUM_MAX); // Red light status.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_RL_FRAME_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stLightInfo", "szReserve");
		}
	}

	/* Traffic light status. */
	public interface PU_RL_LIGHT_STATUS {
		public static final int RL_STATUS_GREEN = 0; // Green light.
		public static final int RL_STATUS_RED = 1; // Red light.
		public static final int RL_STATUS_MAX = 2;
	}

	public interface PU_RL_LIGHT_TYPE {
		public static final int RL_TYPE_DISC = 1; // Ball traffic light.
		public static final int RL_TYPE_ARROW = 2; // Arrow traffic light.
		public static final int RL_TYPE_NUMBER = 3; // Countdown traffic light.
		public static final int RL_TYPE_MAX = 4;
	}

	/* Traffic light group information. */
	public static class PU_RL_LIGHTINFOS_PARA extends Structure {
		public PU_RECTANGLE stRLCropStart; // Start coordinates of the red light area.
		// C type : PU_RL_LIGHT_TYPE_E
		public int enType; // Red light type.
		public BOOL bEnable; // Indicates whether to enable the light group.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_RL_LIGHTINFOS_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stRLCropStart", "enType", "bEnable", "szReserve");
		}
	}

	// ROI rectangle parameter structure.
	public static class PU_ROI_AREA_INFO extends Structure {
		public NativeLong lQuality; // Image quality.
		public ULONG ulPointX; // X coordinate of the ROI.
		public ULONG ulPointY; // Y coordinate of the ROI.
		public ULONG ulWidth; // Width of the ROI.
		public ULONG ulHeight; // Height of the ROI.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ROI_AREA_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("lQuality", "ulPointX", "ulPointY", "ulWidth", "ulHeight", "szReserved");
		}
	}

	// ROI parameter structure.
	public static class PU_ROI_INFO extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int enStreamId; // Stream ID.
		public NativeLong lEnable; // Indicates whether to enable the ROI.
		public ULONG ulROINum; // Number of valid ROIs.
		public PU_ROI_AREA_INFO[] stROIAreaInfo = (PU_ROI_AREA_INFO[]) new PU_ROI_AREA_INFO()
				.toArray(PU_ROI_AREA_NUM_MAX); // ROI rectangle parameters.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_ROI_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "lBrightValue", "lHueValue", "lSaturationValue", "lContrastValue",
					"lSharpValue", "enSharpSwitch", "ulBitMap", "ulBitMap");
		}
	}

	// ROI metering parameters of micro checkpoint cameras.
	public static class PU_ROI_METER_MODE extends Structure {
		public int enRoiMeter; // Indicates whether to enable ROI metering.c type:PU_COMMONMODE_SWITCH
		public ULONG ulRoiMeterLevel; // Metering level, ranging from 1 to 100.

		public PU_ROI_METER_MODE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enRoiMeter", "ulRoiMeterLevel");
		}
	}

	// ROI metering parameters of micro checkpoint cameras.
	public static class PU_ROI_METER_MODE_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enRoiMeter; // Indicates whether to enable ROI metering.c type:PU_COMMONMODE_SWITCH
		public ULONG ulRoiMeterLevel; // Metering level, ranging from 1 to 100.

		public PU_ROI_METER_MODE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enRoiMeter", "ulRoiMeterLevel");
		}
	}

	// ROI metering type (license plate metering of micro cameras/face metering of
	// face detection cameras).
	public interface PU_ROIMETER_TYPE_E {
		int ROIMETER_TYPE_FACE = 0; // Face exposure.
		int ROIMETER_TYPE_VEHICLE = 1; // License plate exposure.
		int ROIMETER_TYPE_INVALID = 2;
	}

	// Image storage structure.
	public static class PU_SAVE_PICTURE_INFO extends Structure {
		public byte[] szFilePath = new byte[PU_SAVE_FILE_PATH_MAX]; // File save path + file name.
		public int enSavePicType; // Save mode. c type:PU_SAVE_REALDATA_TYPE

		public PU_SAVE_PICTURE_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szFilePath", "enSavePicType");
		}
	}

	// Local image storage mode.
	public interface PU_SAVE_PICTURE_TYPE {
		public static final int PU_SAVE_PICTURE_TYPE_BMP = 0; // BMP file.
		public static final int PU_SAVE_PICTURE_TYPE_JEPG = 1; // JPEG file.
		public static final int PU_SAVE_PICTURE_TYPE_MAX = 2;
	}

	// Live video data storage structure.
	public static class PU_SAVE_REALDATA_INFO extends Structure {
		public byte[] szFilePath = new byte[PU_SAVE_FILE_PATH_MAX]; // File save path.
		public int enSaveType; // Save mode. c type:PU_SAVE_REALDATA_TYPE
		public ULONG ulSaveSize; // Size of the file to be saved or recording length (determined by enSaveType).

		public PU_SAVE_REALDATA_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szFilePath", "enSaveType", "ulSaveSize");
		}
	}

	// Local recording storage mode.
	public interface PU_SAVE_REALDATA_TYPE {
		public static final int PU_SAVE_REALDATA_TYPE_TIME = 0; // Storage by time (unit: minute).
		public static final int PU_SAVE_REALDATA_TYPE_SIZE = 1; // Storage by size (unit: MB).
		public static final int PU_SAVE_REALDATA_TYPE_MAX = 2;
	}

	/* ISP scene parameter type. */
	public interface PU_SCENE_PARAM_TYPE {
		public static final int PU_SCENE_PARAM_COMM = 0; // Common scene parameter.
		public static final int PU_SCENE_PARAM_SNAPSHOT = 1; // Scene parameter of the ITS camera or multi-algorithm
																// concurrency camera in full intelligence or micro
																// checkpoint mode.
		public static final int PU_SCENE_PARAM_HUMAN = 2; // Scene parameter of the multi-algorithm concurrency camera
															// in face capture or behavior analysis mode.
		public static final int PU_SCENE_PARAM_VEHICLE = 3; // Scene parameter of the multi-algorithm concurrency camera
															// in micro checkpoint mode.
		public static final int PU_SCENE_PARAM_MAX = 4;
	}

	public interface PU_SDK_PLATFORM_MODE_E {
		public static final int PU_SDK_PALTFORM_MODE_SINGEL = 1; // Single-server mode.
		public static final int PU_SDK_PLATFORM_MODE_DUAL = 2; // Dual-server mode.
		public static final int PU_SDK_PLATFORM_MODE_MAX = 3;
	}

	/* SDK TLS certificate upload. */
	public static class PU_SDK_TLS_CERT_UPLOAD_S extends Structure {
		public byte[] szCaFile = new byte[PU_CONFIG_FILE_PATH_MAX];
		public byte[] szCertFile = new byte[PU_CONFIG_FILE_PATH_MAX];
		public byte[] szKeyFile = new byte[PU_CONFIG_FILE_PATH_MAX];
		public byte[] szPassword = new byte[PU_PASSWORD_LEN]; // Password for encrypting the private key file.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szCaFile", "szCertFile", "szKeyFile", "szPassword");
		}
	}

	/* SDK-TLS certificate upload type. */
	public interface PU_SDK_TLS_CERT_UPLOAD_TYPE {
		public static final int PU_SDK_TLS_CA_CERT_UPLOAD_TYPE = 0;
		public static final int PU_SDK_TLS_CLIENT_CERT_UPLOAD_TYPE = 1;
		public static final int PU_SDK_TLS_CERT_UPLOAD_TYPE_MAX = 2;
	}

	// SEC packet loss rate.
	public interface PU_SEC_PACKET_LOSS_RATIO {
		public static final int PU_SEC_PACKET_LOSS_RATIO_1 = 0; /* 0: 4% packet loss */
		public static final int PU_SEC_PACKET_LOSS_RATIO_2 = 1; /* 1: 8% packet loss */
		public static final int PU_SEC_PACKET_LOSS_RATIO_3 = 2; /* 2: 12% packet loss */
		public static final int PU_SEC_PACKET_LOSS_RATIO_4 = 3; /* 3: 16% packet loss */
		public static final int PU_SEC_PACKET_LOSS_RATIO_5 = 4; /* 4: 20% packet loss */
		public static final int PU_SEC_PACKET_LOSS_RATIO_MAX = 5;
	}

	/* Super Error Concealment (SEC) parameters. */
	public static class PU_SEC_PARA extends Structure {
		public ULONG ulChannelId;
		public WinDef.BOOL bEnable; // Indicates whether to enable the FEC function.
		public int enPacketLossRatio; // Packet loss rate. c type:PU_SEC_PACKET_LOSS_RATIO
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SEC_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "enPacketLossRatio", "szReserved");
		}
	}

	/*************
	 * BEGIN: Parameters for uploading images captured by micro checkpoint cameras
	 * through FTP or SFTP
	 ***************/
	/************* Separator type ***************/
	public interface PU_SEPARATOR_TYPE_E {
		int PU_SEPARATOR_TYPE_DOT = 0; // '.'
		int PU_SEPARATOR_TYPE_PLUS = 1; // '+'
		int PU_SEPARATOR_TYPE_MINUS = 2; // '-'
		int PU_SEPARATOR_TYPE_UNDERLINE = 3; // '_'
		int PU_SEPARATOR_TYPE_EQUAL = 4; // '='
		int PU_SEPARATOR_TYPE_MAX = 5;
	}

	// Serial port type.
	public interface PU_SERIAL_PORT_MODE {
		public static final int PU_SERIAL_PORT_RS232 = 0; // RS-232 serial port.
		public static final int PU_SERIAL_PORT_RS422 = 1; // RS-422 serial port.
		public static final int PU_SERIAL_PORT_RS485 = 2; // RS-485 serial port.
		public static final int PU_SERIAL_PORT_MAX = 3;
	}

	// Serial port parameters.
	public static class PU_SERIAL_PORT_PARA extends Structure {
		public ULONG ulSerialPort; // Serial port number.
		/* C type is PU_SERIAL_PORT_MODE */
		public int enPortMode; // Serial port type.
		/* C type is PU_BAUD_RATE */
		public int enBaudRate; // Baud rate.
		/* C type is PU_DATA_BIT */
		public int enDataBit; // Data bit.
		/* C type is PU_PARITY_BIT */
		public int enParityBit; // Parity bit.
		/* C type is PU_STOP_BIT */
		public int enStopBit; // Stop bit.
		/* C type is PU_FLOW_CONTROL */
		public int enFlowControl; // Serial port flow control.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSerialPort", "enPortMode", "enBaudRate", "enDataBit", "enParityBit", "enStopBit",
					"enFlowControl");
		}
	}

	// Enable or disable SFTP.
	public static class PU_SFTP_ENABLE_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable automatic ARP broadcast.

		public PU_SFTP_ENABLE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable");
		}
	}

	// Enable or disable SFTP.
	public static class PU_SFTP_ENABLE_PARA_S extends Structure {
		public BOOL bEnable; // Indicates whether to enable automatic ARP broadcast.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable");
		}
	}

	/* Shutter speed range. */
	public static class PU_SHUTTER_VALUE extends Structure {
		public int enShutterMode; // Shutter mode. c type:PU_COMMONMODE_SWITCH
		public int enShutterValue; // Shutter speed.c type:PU_CAM_SHUTTER_MODE
		public NativeLong lShutterValueSlow;
		public NativeLong lShutterValueFast;
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_SHUTTER_VALUE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enShutterMode", "enShutterValue", "lShutterValueSlow", "lShutterValueFast",
					"szReserve");
		}
	}

	/* Shutter speed range. */
	public static class PU_SHUTTER_VALUE_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enShutterMode; // Shutter mode. c type:PU_COMMONMODE_SWITCH
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enShutterValue; // Shutter speed.c type:PU_CAM_SHUTTER_MODE
		public NativeLong lShutterValueSlow;
		public NativeLong lShutterValueFast;
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_SHUTTER_VALUE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enShutterMode", "enShutterValue", "lShutterValueSlow", "lShutterValueFast",
					"szReserve");
		}
	}

	/********** END: ITS external device parameters **********/

//Local SIM card number.
	public static class PU_SIM_PHONE_NUM_S extends Structure {
		public byte[] szPhoneNum = new byte[DIAL_PHONE_NUM_LEN];
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_SIM_PHONE_NUM_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szPhoneNum", "szReserve");
		}
	}

	// Slave camera enabling parameters in master-slave camera surveillance (1+N).
	public static class PU_SLAVE_DEVICE_ENABLE_S extends Structure {
		public static class ByReference extends PU_SLAVE_DEVICE_ENABLE_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulSlaveID; // Slave camera ID.

		public WinDef.BOOL bEnable; // Indicates whether to enable the slave camera.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSlaveID", "bEnable");
		}
	}

	// Basic slave camera parameters.
	public static class PU_SLAVE_DEVICE_INFO_S extends Structure {

		public static class ByReference extends PU_SLAVE_DEVICE_INFO_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulSlaveID = new WinDef.ULONG(0); // Slave camera ID.
		public WinDef.BOOL bValid; // Indicates whether the device is valid.
		public byte[] szIPAddress = new byte[PU_IP4_ADDR_LEN]; // IP address of the slave camera.
		public byte[] szSlaveName = new byte[PU_CLIENT_USERNAME_LEN]; // Name of the slave camera, which cannot exceed
																		// 32 characters.

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSlaveID", "bValid", "szIPAddress", "szSlaveName", "szReserved");
		}
	}

	// List of basic slave camera parameters.
	public static class PU_SLAVE_DEVICE_LIST_S extends Structure {
		public static class ByReference extends PU_SLAVE_DEVICE_LIST_S implements Structure.ByReference {
		}

		public PU_SLAVE_DEVICE_INFO_S[] astSlaveInfo = (PU_SLAVE_DEVICE_INFO_S[]) new PU_SLAVE_DEVICE_INFO_S()
				.toArray(PU_SLAVE_NUM_MAX); // Slave camera list.
		public WinDef.ULONG ulSlaveCap; // Maximum number of slave cameras supported.

		public byte[] szReserved = new byte[PU_RESERVE_LEN - 4];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("astSlaveInfo", "ulSlaveCap", "szReserved");
		}

	}

	// ONVIF parameter of the slave camera.
	public static class PU_SLAVE_ONVIF_LIST extends Structure {
		public static class ByReference extends PU_SLAVE_ONVIF_LIST implements Structure.ByReference {
		}

		public PU_SLAVE_ONVIF_PARAM_S[] astOnvifClient = (PU_SLAVE_ONVIF_PARAM_S[]) new PU_SLAVE_ONVIF_PARAM_S()
				.toArray(PU_SLAVE_NUM_MAX); // onvif parameter

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("astOnvifClient", "szReserved");
		}

	}

	// ONVIF parameter of the slave camera.
	public static class PU_SLAVE_ONVIF_PARAM_S extends Structure {
		public static class ByReference extends PU_SLAVE_ONVIF_PARAM_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulSlaveID = new WinDef.ULONG(0); // Slave camera ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.
		public WinDef.ULONG ulChannelId; // Channel ID of the slave camera.
		public WinDef.ULONG ulOnvifPort; // ONVIF port of the slave camera.
		public byte[] szUserName = new byte[PU_CLIENT_USERNAME_LEN]; // ONVIF user name of the slave camera.
		public byte[] szPassWord = new byte[PU_PASSWORD_LEN]; // ONVIF password of the slave camera.

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSlaveID", "bEnable", "ulChannelId", "ulOnvifPort", "szUserName", "szPassWord",
					"szReserved");
		}
	}

	// ONVIF status of the slave camera.
	public static class PU_SLAVE_ONVIF_STATUS_S extends Structure {
		public static class ByReference extends PU_SLAVE_ONVIF_STATUS_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulSlaveID = new WinDef.ULONG(0); // Unique ID of the slave camera.

		public int enStatus; // Status value.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSlaveID", "enStatus");
		}
	}

	/**
	 * ONVIF status of the slave camera.
	 */
	public interface PU_SLAVE_ONVIF_STATUS_TYPE {
		int SLAVE_ONVIF_STATUS_NORMAL = 0; // Normal.
		int SLAVE_ONVIF_STATUS_USER_ERROR = 1; // Incorrect user name or password.
		int SLAVE_ONVIF_STATUS_ABNORMAL = 2; // Abnormal.
		int SLAVE_ONVIF_STATUS_FRAMERATE_INAPPROPRIATE = 3; // Inappropriate frame rate.
		int SLAVE_ONVIF_STATUS_RESOLUTION_INAPPROPRIATE = 4; // Inappropriate resolution.
		int SLAVE_ONVIF_STATUS_MEDIA_ENCODING_INAPPROPRIATE = 5; // The encoding mode does not comply with the MEDIA
																	// mode.
		int SLAVE_ONVIF_STATUS_MEDIA2_ENCODING_INAPPROPRIATE = 6;// The encoding mode does not comply with the MEDIA2
																	// mode.
		int SLAVE_ONVIF_STATUS_MAX = 7;
	}

	// RTSP parameters of the slave camera.
	public static class PU_SLAVE_RTSP_LIST_S extends Structure {
		public static class ByReference extends PU_SLAVE_RTSP_LIST_S implements Structure.ByReference {
		}

		public PU_SLAVE_RTSP_PARAM_S[] astRtspClient = (PU_SLAVE_RTSP_PARAM_S[]) new PU_SLAVE_RTSP_PARAM_S()
				.toArray(PU_SLAVE_NUM_MAX); // rtsp parameters

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("astRtspClient", "szReserved");
		}
	}

	public static class PU_SLAVE_RTSP_PARAM_S extends Structure {
		public static class ByReference extends PU_SLAVE_RTSP_PARAM_S implements Structure.ByReference {
		}; // Slave camera ID.

		public WinDef.ULONG ulSlaveID = new WinDef.ULONG(0);
		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.
		public WinDef.ULONG ulChannelId; // Channel ID of the slave camera.
		public WinDef.ULONG ulRtspPort; // RTSP port of the slave camera.
		public byte[] szUserName = new byte[PU_CLIENT_USERNAME_LEN]; // RTSP user name of the slave camera.
		public byte[] szPassWord = new byte[PU_PASSWORD_LEN]; // RTSP password of the slave camera.

		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSlaveID", "bEnable", "ulChannelId", "ulRtspPort", "szUserName", "szPassWord",
					"szReserved");
		}
	}

	;

	// RTSP status of the slave camera.
	public static class PU_SLAVE_RTSP_STATUS_S extends Structure {
		public static class ByReference extends PU_SLAVE_RTSP_STATUS_S implements Structure.ByReference {
		}

		public WinDef.ULONG ulSlaveID = new WinDef.ULONG(0); // Unique ID of the slave camera.

		public int enStatus; // Status value.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSlaveID", "enStatus");
		}
	}

	;

	public interface PU_SLAVE_RTSP_STATUS_TYPE {
		public final int SLAVE_RTSP_STATUS_NORMAL = 0; // Normal.
		public final int SLAVE_RTSP_STATUS_URL_ERR = 1; // RTSP URL error.
		public final int SLAVE_RTSP_STATUS_USER_ERR = 2; // Incorrect user name or password.
		public final int SLAVE_RTSP_STATUS_ABNORMAL = 3; // Other exceptions.
		public final int SLAVE_RTSP_STATUS_MAX = 4;
	}

	;

	/* Slow shutter mode settings. */
	public static class PU_SLOW_SHUTTER_MODE_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enSlowShutterMode; // Slow shutter mode. c type:PU_COMMONMODE_SWITCH
		/* C type : PU_CAM_SHUTTER_MODE_E */
		public int enShutterValue; // Shutter speed.c type:PU_CAM_SHUTTER_MODE
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSlowShutterMode", "enShutterValue", "szReserve");
		}
	}

	;

	public static class PU_SMS_CMD_INFO_S extends Structure {
		public byte[] szRcNum = new byte[DIAL_RC_NUM_LEN_MAX];
		public byte[] szPeerNum = new byte[DIAL_PHONE_NUM_LEN];
		// C type PU_ENABLE_TYPE_E
		public int enRestartEnable;
		// C type PU_ENABLE_TYPE_E
		public int enDialEnable;

		public PU_SMS_CMD_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szRcNum", "szPeerNum", "enRestartEnable", "enDialEnable");
		}
	}

	;

	public static class PU_SMS_WHITE_LISTS_S extends Structure {
		public PU_SMS_WHITE_LISTS_S[] szSmsWhiteList = (PU_SMS_WHITE_LISTS_S[]) new PU_SMS_WHITE_LISTS_S()
				.toArray(DIAL_SMS_WHITE_LIST_MAX);

		public PU_SMS_WHITE_LISTS_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szSmsWhiteList");
		}
	}

	;

	public interface PU_SMTP_MAIL_TYPE {
		public static final int FOR_TEST = 0;
		public static final int FOR_EVENT = 1;
	}

	;

	public static class PU_SMTP_RECVEIVER_INFO extends Structure {

		public byte[] szReceiverName = new byte[PU_SMTP_NAME_LEN_MAX]; // Recipient name.
		public byte[] szReceiverMail = new byte[PU_SMTP_MAIL_LEN]; // Recipient email address.

		public PU_SMTP_RECVEIVER_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szReceiverName", "szReceiverMail");
		}
	}

	;

	public interface PU_SMTP_SECURITY_TYPE {
		public static final int PU_NO_SECURITY = 0;
		public static final int PU_USE_TLS = 1;
		public static final int PU_USE_SSL = 2;
		public static final int PU_DO_NOT_SET = 3;
	}

	;

	/* Snapshot format. */
	public interface PU_SNAPSHOT_FORMAT {
		public static final int PU_SNAPSHOT_FORMAT_BMP = 0;
		public static final int PU_SNAPSHOT_FORMAT_JPEG = 1;
	}

	;

	// Face snapshot picture search
	public static class PU_SNAPSHOT_INQUIRE_S extends Structure {

		public WinDef.ULONG ulChnID;

		public WinDef.ULONG ulBeginIndex;

		public WinDef.ULONG ulBeginTime;

		public WinDef.ULONG ulEndTime;

		public int enSnapShotType;

		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_SNAPSHOT_INQUIRE_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "ulBeginIndex", "ulBeginTime", "ulEndTime", "enSnapShotType", "szReserve");
		}

	}

	;

	// Image search result.
	public static class PU_SNAPSHOT_LIST_S extends Structure {
		public static class ByReference extends PU_SNAPSHOT_LIST_S implements Structure.ByReference {
		}

		public static class ByValue extends PU_SNAPSHOT_LIST_S implements Structure.ByValue {
		}

		public WinDef.ULONG ulTotalNum;// Total number of records.

		public WinDef.ULONG ulBeginIndex;// Start record index.

		public WinDef.ULONG ulEndIndex;// End record index.

		public PU_IMAGE_INFO_LIST_S[] szImageInfoList = (PU_IMAGE_INFO_LIST_S[]) new PU_IMAGE_INFO_LIST_S()
				.toArray(PU_SNAPSHOT_INQUIRE_NUM); // Image information.

		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_SNAPSHOT_LIST_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulTotalNum", "ulBeginIndex", "ulEndIndex", "szImageInfoList", "szReserve");
		}
	}

	;

	/*
	 * Snapshot parameters and ISP parameters in multi-algorithm concurrency mode.
	 */
	public static class PU_SNAPSHOT_PARTICULAR_PARA_S extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public ULONG ulBitMap; // Modify bit (The lower bit indicates the AE mode.)
		public PU_CAM_AE_MODE_S stCamAEMode; // 1: AE exposure mode. c type:PU_AE_MODE
		public PU_CAM_AE_RESPONSE_TIME_S stCamAEResponseTime; // 2: AE response time (This parameter is invalid for
																// V200R002 devices.)
		public PU_EXPCOMP_PARA_S stCamExpcompPara; // 3: exposure compensation.
		public PU_WB_MANUAL_PARA_S stCamWBManualPara; // 4: white balance.
		public PU_WD_PARA_S stCamWDPara; // 5: WDR.
		public PU_BLACKWHITE_MODE_S stCamBlackWhiteMode; // 6: day/night mode.
		public PU_SLOW_SHUTTER_MODE_S stSlowShutterMode; // 7: slow shutter switch.
		public PU_GAMMA_S stImageGammaCtrl; // 8: gamma parameter.
		public PU_FLICKER_MODE_S stCamFlickerMode; // 9: background frequency.
		public PU_AEMETERING_MODE_S stCamAEMeterMode; // 10: AE metering mode.
		public PU_SHUTTER_VALUE_S stCamshutterValue; // 11: shutter speed range and its value.
		public PU_BACKLIGHT_MODE_S stCamBackLightMode; // 12: backlight compensation mode.
		public PU_IRC_PARA_S stCamIRCPara; // 13: day/night mode switch and threshold (sensitivity).
		public PU_CAM_LENS_TYPE_S stCamLensType; // 14: lens type.
		public PU_AUTOGAIN_MAXVALUE_S stAutoGainMaxValue; // 15: maximum auto gain value.
		public PU_GAIN_CONTROL_S stCamGainControl; // 16: gain control.
		public PU_DENOISE_PARA_S stCamDenoisePara; // 17: noise reduction mode.
		public PU_STABILIZER_PARA_S stCamStabilizerPara; // 18: image stabilization mode.
		public PU_IRIS_CONTROL_S stCamIrisControl; // 19: iris control.
		public PU_DEFOG_PARA_S stISPDefogPara; // 20: defogging mode.
		public PU_ROI_METER_MODE_S stCamRoiMeterMode; // 21: ROI metering of micro checkpoint cameras.
		public PU_IMG_DRC_S stImgDRCPara; // 25: TI box camera DRC parameters.
		public PU_MIN_FOCUS_VALUE_S stMinFocusValue; // 26: minimum focus distance.
		public PU_ISP_CAM_HLC_S stHlc; // 27: highlight compensation.
		/* C Type : PU_IRIS_TYPE_E */
		public int enIrisType; // 28: iris type.
		/* C Type : PU_CAM_SHUTTER_MODE_E */
		public int enShutterValueLimit; // 29: shutter limit.
		/* C Type : PU_ISP_SCENE_TYPE_E */
		public int enSceneType; // 30: ISP scene mode.

		public PU_SNAPSHOT_PARTICULAR_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulBitMap", "stCamAEMode", "stCamAEResponseTime", "stCamExpcompPara",
					"stCamWBManualPara", "stCamWDPara", "stCamBlackWhiteMode", "stSlowShutterMode", "stImageGammaCtrl",
					"stCamFlickerMode", "stCamAEMeterMode", "stCamshutterValue", "stCamBackLightMode", "stCamIRCPara",
					"stCamLensType", "stAutoGainMaxValue", "stCamGainControl", "stCamDenoisePara",
					"stCamStabilizerPara", "stCamIrisControl", "stISPDefogPara", "stCamRoiMeterMode", "stImgDRCPara",
					"stMinFocusValue", "stHlc", "enIrisType", "enShutterValueLimit", "enSceneType");
		}
	}

	;

	// Snapshot quality.
	public static class PU_SNAPSHOT_QUAILTY_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID (not supported currently).
		public int enQuality; // Snapshot quality. c type:PU_SNAPSHOT_QUALITY
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_SNAPSHOT_QUAILTY_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulStreamID", "enResolution", "enPictureFormat", "szPicPath",
					"szReserved");
		}
	}

	;

	// Snapshot quality.
	public interface PU_SNAPSHOT_QUALITY {
		public static final int PU_QUAILTY_BEST = 0;
		public static final int PU_QUAILTY_MORE_BETTER = 1;
		public static final int PU_QUAILTY_BETTER = 2;
		public static final int PU_QUAILTY_ORDINARY = 3;
		public static final int PU_QUAILTY_LOW = 4;
		public static final int PU_QUAILTY_WORST = 5;
		public static final int PU_QUAILTY_MAX = 6;
	}

	;

	// Snapshot resolution.
	public static class PU_SNAPSHOT_RESOLUTION_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public int enStreamType; // Snapshot stream. c type:PU_STREAM_TYPE
		public int enResolution; // Snapshot resolution. c type:PU_RESOLUTION_TYPE
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates whether the camera is a micro
																// checkpoint camera. The options are 1 (yes) and 0
																// (no).

		public PU_SNAPSHOT_RESOLUTION_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enStreamType", "enResolution", "szReserved");
		}
	}

	;

	// Snapshot retransmission parameters.
	public static class PU_SNAPSHOT_RETRANS_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable snapshot retransmission.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_SNAPSHOT_RETRANS_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szReserved");
		}
	}

	;

	/* Snapshot storage space settings. */
	public static class PU_SNAPSHOT_SPACE extends Structure {
		public ULONG ulPercentDecimal; // Percentage of the snapshot storage space (decimal part containing two digits.
										// The value 1 indicates 0.01%.).
		public ULONG ulPercentInt; // Percentage of the snapshot storage space (integer part).

		public PU_SNAPSHOT_SPACE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulPercentDecimal", "ulPercentInt");
		}
	}

	;

	/* Scheduled snapshot parameters. */
	public static class PU_SNAPSHOT_TIMING_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable the scheduled snapshot function.
		public ULONG ulChannelID; // Channel ID.
		public ULONG ulStreamID; // Stream ID.
		public ULONG ulSnapCount; // Snapshot interval, in seconds.
		public int enPictureFormat; // Image format. c type:PU_SNAPSHOT_FORMAT
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		public PU_SNAPSHOT_TIMING_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulChannelID", "ulStreamID", "ulSnapCount", "enPictureFormat",
					"szReserved");
		}
	}

	;

	/* Snapshot type. */
	public interface PU_SNAPSHOT_TYPE {
		public static final int PU_SNAPSHOT_TYPE_MANUAL = 0; // Manual snapshot.
		public static final int PU_SNAPSHOT_TYPE_ALARM = 1; // Alarm-triggered snapshot.
		public static final int PU_SNAPSHOT_TYPE_TIMER = 2; // Scheduled snapshot.
		public static final int PU_SNAPSHOT_TYPE_MANUAL_EX = 3; //
		public static final int PU_SNAPSHOT_TYPE_FACEDT = 4; // Face snapshot.
		public static final int PU_SNAPSHOT_TYPE_ITGT = 5; // Intelligent analysis–triggered snapshot.
		public static final int PU_SNAPSHOT_TYPE_ITS = 6; // ITS snapshot.
		public static final int PU_SNAPSHOT_TYPE_VEHICLE = 7; // Vehicle event–triggered snapshot.
		public static final int PU_SNAPSHOT_TYPE_MAX = 8;
	}

	;

	public static class PU_SNMP_AUTH_INFO extends Union {
		public byte[] szCommunityName = new byte[PU_SNMP_COMMUNITY_NAME_LEN]; // Community name, which is used to send
																				// SNMP v1/v2c trap messages.
		public PU_SNMPV3_USER_INFO stUserInfo; // User information, which is used to send SNMPv3 trap messages.

		public PU_SNMP_AUTH_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szCommunityName", "stUserInfo");
		}
	}

	;

	/* SNMP v1/v2c community property. */
	public interface PU_SNMP_COMMUNITY_ATTR {
		public static final int PU_SNMP_COMMUNITY_READONLY = 0;
		public static final int PU_SNMP_COMMUNITY_READWRITE = 1;
		public static final int PU_SNMP_COMMUNITY_MAX = 2;
	}

	;

	/* SNMPv1v2c community information. */
	public static class PU_SNMP_COMMUNITY_INFO extends Structure {
		public int enCommunityAttr; // Community attribute. c type:PU_SNMP_COMMUNITY_ATTR
		public byte[] szCommunityName = new byte[PU_SNMP_COMMUNITY_NAME_LEN]; // Community name.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SNMP_COMMUNITY_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enCommunityAttr", "szCommunityName", "szReserved");
		}
	}

	;

	public static class PU_SNMP_COMMUNITY_INFO_EX extends Structure {
		public int enCommunityAttr; // Community attribute. c type:PU_SNMP_COMMUNITY_ATTR
		public byte[] szCommunityName = new byte[PU_SNMP_COMMUNITY_NAME_LEN_EX]; // Community name.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SNMP_COMMUNITY_INFO_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enCommunityAttr", "szCommunityName", "szReserved");
		}
	}

	;

	/* SNMPv1v2c community list. */
	public static class PU_SNMP_COMMUNITY_LIST extends Structure {
		public ULONG ulCommunityNum; // Number of communities.
		public PU_SNMP_COMMUNITY_INFO[] szCommunityInfo = (PU_SNMP_COMMUNITY_INFO[]) new PU_SNMP_COMMUNITY_INFO()
				.toArray(PU_SNMP_COMMUNITY_NUM); // Community information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SNMP_COMMUNITY_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCommunityNum", "szCommunityInfo", "szReserved");
		}
	}

	;

	/* SNMPv1v2c community list extension (longer community name supported). */
	public static class PU_SNMP_COMMUNITY_LIST_EX extends Structure {
		public ULONG ulCommunityNum; // Number of communities.
		public PU_SNMP_COMMUNITY_INFO_EX[] szCommunityInfo = (PU_SNMP_COMMUNITY_INFO_EX[]) new PU_SNMP_COMMUNITY_INFO_EX()
				.toArray(PU_SNMP_COMMUNITY_NUM); // Community information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SNMP_COMMUNITY_LIST_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCommunityNum", "szCommunityInfo", "szReserved");
		}
	}

	;

	/* SNMP Trap receiver information. */
	public static class PU_SNMP_TRAP_INFO extends Structure {
		public byte[] szTrapPeerIp = new byte[PU_IP4_ADDR_LEN]; // Receiver IP address.
		public WinDef.USHORT usTrapPeerPort; // Receiver port number.
		public int enSnmpVer; // Version. c type:PU_SNMP_VERSION_TYPE
		public PU_SNMP_AUTH_INFO unSnmmpAuthInfo; // Authentication information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0]: applied network adapter. The value 0
																// indicates network adapter 1. The value 1 indicates
																// network adapter 2. The rest can be deducted by
																// analogy.

		public PU_SNMP_TRAP_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szTrapPeerIp", "usTrapPeerPort", "enSnmpVer", "unSnmmpAuthInfo", "szReserved");
		}
	}

	;

	/* SNMP Trap receiver list. */
	public static class PU_SNMP_TRAP_LIST extends Structure {
		public ULONG ulTrapNum; // Number of trap receivers.
		public PU_SNMP_TRAP_INFO[] szTrapInfo = (PU_SNMP_TRAP_INFO[]) new PU_SNMP_TRAP_INFO().toArray(PU_SNMP_TRAP_NUM); // Information
																															// about
																															// the
																															// trap
																															// receiver.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SNMP_TRAP_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulTrapNum", "szTrapInfo", "szReserved");
		}
	}

	;

	/* SNMP version. */
	public interface PU_SNMP_VERSION_TYPE {
		public static final int PU_SNMP_VERSION_V1 = 0;
		public static final int PU_SNMP_VERSION_V2C = 1;
		public static final int PU_SNMP_VERSION_V3 = 2;
		public static final int PU_SNMP_VERSION_MAX = 3;
	}

	;

	/* SNMP v3 password authentication protocol. */
	public interface PU_SNMPV3_AUTH_PROTOCOL {
		public static final int PU_SNMPV3_AUTH_MD5 = 0;
		public static final int PU_SNMPV3_AUTH_SHA = 1;
		public static final int PU_SNMPV3_AUTH_NONE = 2;
		public static final int PU_SNMPV3_AUTH_MAX = 3;
	}

	;

	/* SNMP v3 private key protocol. */
	public interface PU_SNMPV3_PRIV_PROTOCOL {
		public static final int PU_SNMPV3_PRIV_DES = 0;
		public static final int PU_SNMPV3_PRIV_AES = 1;
		public static final int PU_SNMPV3_PRIV_NONE = 2;
		public static final int PU_SNMPV3_PRIV_MAX = 3;
	}

	/* SNMPv3 user security level. */
	public interface PU_SNMPV3_SECURITY_LEVEL {
		public static final int PU_SNMPV3_SECURITY_NOAUTH = 0; // Unauthorized.
		public static final int PU_SNMPV3_SECURITY_AUTH = 1; // Authorized.
		public static final int PU_SNMPV3_SECURITY_PRIV = 2; // Private key encryption and authorization.
		public static final int PU_SNMPV3_SECURITY_MAX = 3;
	}

	;

	/* SNMPv3 user information. */
	public static class PU_SNMPV3_USER_INFO extends Structure {
		public byte[] szUserName = new byte[PU_USER_NAME_LEN]; // User name.

		public WinDef.BOOL bEngineIdEnable; // Indicates whether to specify the ENGINEID (used only when Trap is
											// configured).
		public byte[] szEngineId = new byte[PU_SNMP_ENGINEID_LEN]; // ENGINEID (used only when Trap is configured).
		public WinDef.BOOL bContextEnable; // Indicates whether to specify the context name (used only when Trap is
											// configured).
		public byte[] szContextName = new byte[PU_SNMP_CONTEXT_NAME_LEN]; // Context name (used only when Trap is
																			// configured).
		public byte[] szAuthPassword = new byte[PU_PASSWORD_LEN]; // Authentication password. If the authentication
																	// password is configured on the web page, the
																	// password is delivered in the original text. If
																	// the authentication password is recorded in the
																	// configuration file, the authentication password
																	// is in cipher text.
		public byte[] szPrivKey = new byte[PU_PASSWORD_LEN]; // Private key. If the private key is configured on the web
																// page, the private key is delivered in the original
																// text. If the private key is recorded in the
																// configuration file, the private key is in cipher
																// text.
		public int enSecurityLevel; // Security level. c type :PU_SNMPV3_SECURITY_LEVEL
		public int enAuthProtocol; // Authentication protocol. c type :PU_SNMPV3_AUTH_PROTOCOL
		public int enPrivProtocol; // Private key protocol. c type :PU_SNMPV3_PRIV_PROTOCOL
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SNMPV3_USER_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szUserName", "bEngineIdEnable", "szEngineId", "bContextEnable", "szAuthPassword",
					"szPrivKey", "enSecurityLevel", "enAuthProtocol", "enPrivProtocol");
		}
	}

	;

	/* SNMPv3 user list. */
	public static class PU_SNMPV3_USER_LIST extends Structure {
		public ULONG ulUserNum; // Number of users.
		public PU_SNMPV3_USER_INFO[] szUserInfo = (PU_SNMPV3_USER_INFO[]) new PU_SNMPV3_USER_INFO()
				.toArray(PU_SNMPV3_USER_NUM); // User information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SNMPV3_USER_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulUserNum", "szUserInfo", "szReserved");
		}
	}

	;

	/* SNMPv3 user management. */
	public static class PU_SNMPV3_USER_MGMT extends Structure {
		public int enManipulateType; // Operation type. c type : PU_OPT_TYPE_E

		public PU_SNMPV3_USER_INFO stMgmtUserInfo; // Operation information.
		public byte[] szModifyVerifyPwd = new byte[PU_PASSWORD_LEN]; // Authentication password of the current SNMP user
																		// (the security level is not noauth).
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SNMPV3_USER_MGMT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enManipulateType", "stMgmtUserInfo", "szModifyVerifyPwd", "szReserved");
		}

	}

	// Coordinate information.
	public static class PU_SQUARE_PARA extends Structure {
		public ULONG ulX;
		public ULONG ulY;

		public PU_SQUARE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulX", "ulY");
		}
	}

	// Enable or disable SSH.
	public static class PU_SSH_ENABLE_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable automatic ARP broadcast.

		public PU_SSH_ENABLE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable");
		}
	}

	// Enable or disable SSH
	public static class PU_SSH_ENABLE_PARA_S extends Structure {
		public BOOL bEnable; // Indicates whether to enable automatic ARP broadcast.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable");
		}
	}

	;

	/* Image stabilization function. */
	public static class PU_STABILIZER_PARA extends Structure {
		public int enStabilizerMode; // Indicates whether to enable image stabilization. c type:PU_COMMONMODE_SWITCH
		public NativeLong lStabilizerLevel; // Image stabilization level.
		public NativeLong lEfl; // Equivalent focal length.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_STABILIZER_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enStabilizerMode", "lStabilizerLevel", "lEfl", "szReserve");
		}
	}

	;

	/* Image stabilization function. */
	public static class PU_STABILIZER_PARA_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enStabilizerMode; // Indicates whether to enable image stabilization. c type:PU_COMMONMODE_SWITCH
		public NativeLong lStabilizerLevel; // Image stabilization level.
		public NativeLong lEfl; // Equivalent focal length.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_STABILIZER_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enStabilizerMode", "lStabilizerLevel", "lEfl", "szReserve");
		}
	}

	;

	// Stop bit.
	public interface PU_STOP_BIT {
		public static final int PU_STOP_BIT_OFF = 0;
		public static final int PU_STOP_BIT_ON = 1;
		public static final int PU_STOP_BIT_MAX = 2;
	}

	;

	/* Channel stream capability. */
	public static class PU_STREAM_ABILITY extends Structure {
		public ULONG ulChannelId;
		public byte[] szCameraName = new byte[PU_DEVICE_NAME_LEN];
		public ULONG ulPTZType;
		public ULONG ulPresetNum;
		public ULONG ulCruiseTrackNum;
		public ULONG ulMaxStreamNum;
		public WinDef.BOOL bPtzFastLocate;
		public WinDef.BOOL bPtzHorizotalScan;
		public WinDef.BOOL bPtzVerticalScan;
		public PU_STREAM_ABILITY_PARA[] stStreamAbility = (PU_STREAM_ABILITY_PARA[]) new PU_STREAM_ABILITY_PARA()
				.toArray(PU_STREAM_NUM);
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_STREAM_ABILITY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "szCameraName", "ulPTZType", "ulPresetNum", "ulCruiseTrackNum",
					"ulMaxStreamNum", "bPtzFastLocate", "bPtzHorizotalScan", "bPtzVerticalScan", "stStreamAbility",
					"szReserved");
		}
	}

	/* Stream capability. */
	public static class PU_STREAM_ABILITY_PARA extends Structure {
		public int enStreamType; // Stream type. PU_STREAM_TYPE
		public int[] enVideoFormat = new int[PU_VIDEO_FORMAT_NUM]; // Video encoding format. PU_ENCODE_TYPE
		public int enMaxResolution; // Maximum resolution. PU_RESOLUTION_TYPE
		public ULONG ulMaxBitRate; // Maximum bit rate.
		public ULONG ulMaxFrmRate; // Maximum frame rate.
		public ULONG ulMaxIFrameInterval; // Maximum I-frame interval.
		public int enVideoType; // Video stream type. PU_VIDEO_TYPE
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_STREAM_ABILITY_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enStreamType", "enVideoFormat", "enMaxResolution", "ulMaxBitRate", "ulMaxFrmRate",
					"ulMaxIFrameInterval", "enVideoType", "szReserved");
		}
	}

	;

	/* Channel stream capability V2. */
	public static class PU_STREAM_ABILITYV2 extends Structure {
		public ULONG ulChannelId;
		public byte[] szCameraName = new byte[PU_DEVICE_NAME_LEN];
		public ULONG ulPTZType;
		public ULONG ulPresetNum;
		public ULONG ulCruiseTrackNum;
		public ULONG ulMaxStreamNum;
		public WinDef.BOOL bPtzFastLocate;
		public WinDef.BOOL bPtzHorizotalScan;
		public WinDef.BOOL bPtzVerticalScan;
		public PU_STREAM_ABILITY_PARA[] stStreamAbility = (PU_STREAM_ABILITY_PARA[]) new PU_STREAM_ABILITY_PARA()
				.toArray(PU_STREAM_NUM_V2);
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_STREAM_ABILITYV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "szCameraName", "ulPTZType", "ulPresetNum", "ulCruiseTrackNum",
					"ulMaxStreamNum", "bPtzFastLocate", "bPtzHorizotalScan", "bPtzVerticalScan", "stStreamAbility",
					"szReserved");
		}
	}

	// Video stream information structure.
	public static class PU_STREAM_ATTRIBUTE extends Structure {
		public int enStreamId; // Stream type.

		public PU_VIDEO_ATTRIBUTE stVideoAttribute; // Video stream parameter.

		public PU_STREAM_ATTRIBUTE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enStreamId", "stVideoAttribute", "ulFrameRate", "enVideoEncodeMode", "enResolution",
					"enBitRateType", "enPicQuality", "enVideoFormat", "enRcPriMode", "enMirrorMode", "szReserve");
		}
	}

	/* Stream profile operations. */
	public interface PU_STREAM_MANIPULATE_TYPE {
		public static final int PU_STREAM_MANIPULATE_ADD = 0; // Add.
		public static final int PU_STREAM_MANIPULATE_DELETE = 1; // Delete.
		public static final int PU_STREAM_MANIPULATE_MODIFY = 2; // Modify.
		public static final int PU_STREAM_MANIPULATE_MAX = 3;
	}

	// Video stream mode.
	public interface PU_STREAM_MODE_E {
		public static final int PU_VIEDO_STREAM_NONE = 0; // No stream profile is configured.
		public static final int PU_VIEDO_STREAM_SINGLE = 1; // Single video stream.
		public static final int PU_VIEDO_STREAM_DOUBLE = 2; // Dual video streams.
		public static final int PU_VIEDO_STREAM_TRIPLE = 3; // Triple video streams.
		public static final int PU_VIEDO_STREAM_FOUR = 4; // Four video streams.
		public static final int PU_VIEDO_STREAM_FIVE = 5; // Five video streams.
		public static final int PU_VIEDO_STREAM_MAX = 6;
	}

	;

	/* Stream profile. */
	public interface PU_STREAM_PROFILE_MODE {
		public static final int PU_STREAM_PROFILE_DEFAULT = 0; /* Default. */
		public static final int PU_STREAM_PROFILE_HIGH_QUALITY = 1; /* HD. */
		public static final int PU_STREAM_PROFILE_BALANCED = 2; /* Smooth bandwidth. */
		public static final int PU_STREAM_PROFILE_LOW_BANDWIDTH = 3; /* Low bandwidth. */
		public static final int PU_STREAM_PROFILE_MOBILE_DEVICE = 4; /* Mobile device. */
		public static final int PU_STREAM_PROFILE_USER_1 = 5; /* User-defined scene 1. */
		public static final int PU_STREAM_PROFILE_USER_2 = 6; /* User-defined scene 2. */
		public static final int PU_STREAM_PROFILE_USER_3 = 7; /* User-defined scene 3. */
		public static final int PU_STREAM_PROFILE_USER_4 = 8; /* User-defined scene 4. */
		public static final int PU_STREAM_PROFILE_MAX = 9;
	}

	/* Stream profile parameters. */
	public static class PU_STREAM_PROFILES_PARA extends Structure {
		public ULONG ulIndex; // Unique ID. The digits 1-4 indicate basic settings and cannot be deleted. The
								// value 0 indicates automatic adaptation.

		public byte[] szName = new byte[STREAMPROFILES_NAME_LEN]; // Name.
		public byte[] szDescrip = new byte[STREAMPROFILES_NAME_LEN * 2]; // Description.
		public PU_VIDEO_ENCODE_PARA stV4ideoEncodePara; // Video stream parameter.
		public PU_AUDIO_INFO stAudioInfo; // Audio parameters.
		public WinDef.BOOL bAiVqeStatus; // Audio quality enhancement.
		public WinDef.BOOL bCorridorEnable; // Corridor mode.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_STREAM_PROFILES_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "szName", "szDescrip", "stV4ideoEncodePara", "stAudioInfo", "bAiVqeStatus",
					"bCorridorEnable", "szReserve");
		}

	}

	;

	/* Stream profile parameters V2 (five streams). */
	public static class PU_STREAM_PROFILES_PARAV2 extends Structure {
		public ULONG ulIndex; // Unique ID. The digits 1-4 indicate basic settings and cannot be deleted. The
								// value 0 indicates automatic adaptation.

		public byte[] szName = new byte[STREAMPROFILES_NAME_LEN]; // Name.
		public byte[] szDescrip = new byte[STREAMPROFILES_NAME_LEN * 2]; // Description.
		public PU_VIDEO_ENCODE_PARAV2 stVideoEncodePara; // Video stream parameter.
		public PU_AUDIO_INFO stAudioInfo; // Audio parameters.
		public WinDef.BOOL bAiVqeStatus; // Audio quality enhancement.
		public WinDef.BOOL bCorridorEnable; // Corridor mode.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_STREAM_PROFILES_PARAV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "szName", "szDescrip", "stVideoEncodePara", "stAudioInfo", "bAiVqeStatus",
					"bCorridorEnable", "szReserve");
		}
	}

	// Video stream type. PU_VIDEO_TYPE
	public interface PU_STREAM_TYPE_E {
		public static final int PU_VIDEO_MAIN_STREAM = 0; // Primary stream.
		public static final int PU_VIDEO_SUB_STREAM1 = 1; // Secondary stream 1.
		public static final int PU_VIDEO_SUB_STREAM2 = 2; // Secondary stream 2.
		public static final int PU_VIDEO_SUB_STREAM3 = 3; // Secondary stream 3.
		public static final int PU_VIDEO_SUB_STREAM4 = 4; // Secondary stream 4.
		public static final int PU_VIDEO_SUB_STREAM5 = 5; //
		public static final int PU_VIDEO_STREAM_MAX = 6;
	}

	// Stream profile information.
	public static class PU_STREAMPROFILES_INFO extends Structure {
		public ULONG ulIndex; // ID.

		public byte[] szName = new byte[STREAMPROFILES_NAME_LEN]; // Profile name.
		public byte[] szDescrip = new byte[STREAMPROFILES_NAME_LEN * 2]; // Description.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_STREAMPROFILES_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "szName", "szDescrip", "szReserved");
		}
	}

	// Stream profile list.
	public static class PU_STREAMPROFILES_INFO_LIST extends Structure {
		public ULONG ulStreamProfilesNum; // Number of stream profiles.

		public ULONG ulStreamId; // ID of the currently activated stream profile.
		public PU_STREAMPROFILES_INFO[] szStreamProfile = (PU_STREAMPROFILES_INFO[]) new PU_STREAMPROFILES_INFO()
				.toArray(STREAM_PROFILES_MAX); // Information list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_STREAMPROFILES_INFO_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStreamProfilesNum", "ulStreamId", "szStreamProfile", "szReserved");
		}
	}

	// Strobe light parameters.
	public static class PU_STROBE_LAMP_ATTR_S extends Structure {
		// C type : PU_EXT_LAMP_WORK_MODE
		public int enExtLampWorkMode; // External illuminator work mode.
		public ULONG ulPulseWidth; // Pulse width.
		public ULONG ulDelayTime; // Delay time used for synchronization adjustment.
		/* C type : PU_EXT_LAMP_FREQ_E */
		public int enFrequency; // Strobe light frequency.
		public ULONG ulLightThreshold; // Luminance threshold. This parameter is valid in automatic mode.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_STROBE_LAMP_ATTR_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enExtLampWorkMode", "ulPulseWidth", "ulDelayTime", "enFrequency", "ulLightThreshold",
					"szReserved");
		}
	}

	// Illuminator parameters.
	public static class PU_SUPPLEMENT_LAMP_ATTR_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public PU_STROBE_LAMP_ATTR_S[] stStrobeLampAttr = new PU_STROBE_LAMP_ATTR_S[PU_MAX_INNER_LAMP_NUM]; // Internal
																											// strobe
																											// light
																											// attribute.
		public PU_EXT_LAMP_ATTR_S[] stExtLampAttr = new PU_EXT_LAMP_ATTR_S[PU_MAX_EXT_LAMP_NUM]; // External illuminator
																									// attribute.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SUPPLEMENT_LAMP_ATTR_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stStrobeLampAttr", "stExtLampAttr", "szReserved");
		}
	}

	// Illuminator parameters.
	public static class PU_SUPPLEMENT_LIGHT_INFO_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulActiveNum;
		public PU_SUPPLEMENT_LIGHT_LAMP_INFO_S[] stLampInfo = new PU_SUPPLEMENT_LIGHT_LAMP_INFO_S[MAX_SUPPLEMENT_LIGHT_LAMP_NUM];
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates the illuminator type. For
																// details, see PU_SUPPLEMENTLAMP_TYPE_E.

		// szReserved[1] indicates the illuminator control mode. For details, see
		// PU_LAMP_CTRL_MODE_E.
		// szReserved[2] indicates the illuminator control type. For details, see
		// PU_CAPLAMPCTRL_TYPE_E.
		// szReserved[3] indicates the intelligent infrared level. The value ranges from
		// 0 to 100. The default value is 50.
		public PU_SUPPLEMENT_LIGHT_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulActiveNum", "stLampInfo", "szReserved");
		}
	}

	// Illuminator control mode.
	public interface PU_SUPPLEMENT_LIGHT_LAMP_CTRL_MODE {
		public static final int PU_CONTROL_DISABLE_MODE = 0;
		public static final int PU_CONTROL_AUTO_MODE = 1;
		public static final int PU_CONTROL_TIME_MODE = 2;
		public static final int PU_CONTROL_MODE_MAX = 3;
	}

	// Illuminators for license plates (alert deployment time structure).
	public static class PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO_S extends Structure {
		public ULONG ulStartTime; // Start time.
		public ULONG ulEndTime; // End time.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartTime", "ulEndTime", "szReserved");
		}
	}

	// Illuminator parameters.
	public static class PU_SUPPLEMENT_LIGHT_LAMP_INFO_S extends Structure {
		public ULONG ulOutputId;
		public ULONG ulLampGroupLum; // Illuminator group brightness control. The value ranges from 1 to 100.
		public ULONG ulSensitivity; // Brightness detection sensitivity, ranging from 0 to 2.
		/* C type : PU_SUPPLEMENT_LIGHT_LAMP_IO_MODE */
		public int enIOMode;
		/* C type : PU_SUPPLEMENT_LIGHT_LAMP_CTRL_MODE */
		public int enControlMode;
		public PU_SUPPLEMENT_LIGHT_LAMP_GUARD_INFO_S stTimePlan;
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserver[0] indicates the illuminator brightness. The
																// value ranges from 1 to 100. The default value is 50.

		public PU_SUPPLEMENT_LIGHT_LAMP_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulOutputId", "ulLampGroupLum", "ulSensitivity", "enIOMode", "enControlMode",
					"stTimePlan", "szReserved");
		}
	}

	// Illuminator I/O mode.
	public interface PU_SUPPLEMENT_LIGHT_LAMP_IO_MODE {
		public static final int PU_IO_CONTINUE_MODE = 0;
		public static final int PU_IO_MODE_MAX = 1;
	}

	public interface PU_SUPPLEMENTLAMP_TYPE {
		public static final int PU_TYPE_LAMP_WHITE = 0; // White-light illuminator.
		public static final int PU_TYPE_LAMP_RED = 1; // Infrared illuminator.
		public static final int PU_TYPE_LAMP_MAX = 2;
	}

	/************************
	 * Boolean value input parameters
	 **************************/
	public static class PU_SWITCH_INPUT_PARA extends Structure {
		public ULONG ulInputId;
		public byte[] szInputName = new byte[PU_DIO_NAME_LEN]; // Name that supports a maximum of 32 bytes.
		public ULONG ulSwitchType; // Boolean value output status. The options are as follows: 0: normally open; 1:
									// normally close.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SWITCH_INPUT_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulInputId", "szInputName", "ulSwitchType", "szReserved");
		}
	}

	/************************
	 * Boolean value output parameters
	 **************************/
	public static class PU_SWITCH_OUTPUT_PARA extends Structure {
		public ULONG ulOutputId;
		public byte[] szOutputName = new byte[PU_DIO_NAME_LEN]; // Name that supports a maximum of 32 bytes.
		public ULONG ulHoldTime; // Hold duration that ranges from 1s to 600s. The default value is 10s.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SWITCH_OUTPUT_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulOutputId", "szOutputName", "ulHoldTime", "szReserved");
		}
	}

	/************************
	 * Boolean value output status
	 **************************/
	public static class PU_SWITCH_OUTPUT_STATE extends Structure {
		public ULONG ulOutputId;
		public ULONG ulSwitchType; // Boolean value output status. The options are as follows: 0: normally open; 1:
									// normally close.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_SWITCH_OUTPUT_STATE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulOutputId", "ulSwitchType", "szReserved");
		}
	}

	// System information structure.
	public static class PU_SYS_STATUS_INFO extends Structure {
		public float fCpuOccupancyRate; // CPU usage.
		public ULONG ulMemTotal; // Total memory of the device (KB).
		public ULONG ulMemFree; // Available memory (KB).
		public ULONG ulMemBuffer; // Buffer (KB).
		public ULONG ulMemCache; // Cache memory (KB).
		public ULONG ulRecvRate; // Network receiving rate (byte).
		public ULONG ulSendRate; // Network sending rate (byte).
		public ULONG ulFlashTotal; // Total size of the flash memory (KB).
		public ULONG ulFlashFree; // Available size of the flash memory (KB).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_SYS_STATUS_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("fCpuOccupancyRate", "ulMemTotal", "ulMemFree", "ulMemBuffer", "ulMemCache",
					"ulRecvRate", "ulSendRate", "ulFlashTotal", "ulFlashFree", "szReserve");
		}
	}

	public interface PU_TABLE_TYPE {
		public static final int PU_TABLE_DAY = 0; // Daily report.
		public static final int PU_TABLE_WEEK = 1; // Weekly report.
		public static final int PU_TABLE_MONTH = 2; // Monthly report.
		public static final int PU_TABLE_YEAR = 3; // Annual report.
	}

	// TCP acceleration parameters.
	public static class PU_TCP_ACCELERATE_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable the ROI.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_TCP_ACCELERATE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szReserved");
		}
	}

	// TCP acceleration parameters.
	public static class PU_TCP_ACCELERATE_PARA_S extends Structure {
		public BOOL bEnable; // Indicates whether to enable the ROI.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_TCP_ACCELERATE_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szReserved");
		}
	}

	// Traffic PTZ dome camera algorithm parameter.
	public static class PU_TD_ALG_PARAMS extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable the algorithm.
		public ULONG ulFilterThreshold; // Violation filtering threshold, in minutes. The value ranges from 1 to 1440.
		public NativeLong lPTZCalibrationHorizontal; // PTZ calibration parameter (horizontal). The value ranges from –2
														// to 2.
		public NativeLong lPTZCalibrationVertical; // PTZ calibration parameter (vertical). The value ranges from –2 to
													// 2.
		public BOOL bRecordEnable; // Indicates whether to enable recording.
		// C Type: PU_TD_ILLEGAL_TYPE_E
		public int enIllegalType; // Parking violation type.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_TD_ALG_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "ulFilterThreshold", "lPTZCalibrationHorizontal",
					"lPTZCalibrationVertical", "bRecordEnable", "enIllegalType", "szReserve");
		}
	}

	// Traffic PTZ dome camera algorithm parameter.
	public static class PU_TD_ALG_PARAMSV2 extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable the algorithm.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_TD_ALG_PARAMSV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "szReserve");
		}
	}

	// Parameter for enabling detection lines of traffic PTZ dome cameras.
	public static class PU_TD_DTLINE_ENABLE extends Structure {
		public BOOL[] abRoadLane = new BOOL[MAX_LANE_NUM]; // Indicates whether to enable the lane line.
		public BOOL bLaneRhtBorderLine; // Right lane boundary.

		public PU_TD_DTLINE_ENABLE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("abRoadLane", "bLaneRhtBorderLine");
		}
	}

	// Parameter for enabling detection lines of traffic PTZ dome cameras.
	public static class PU_TD_DTLINE_ENABLEV2 extends Structure {
		public BOOL[] abRoadLane = new BOOL[TDOME_MAX_LANE_NUM]; // Indicates whether to enable the lane line.
		public BOOL bLaneRhtBorderLine; // Right lane boundary.

		public PU_TD_DTLINE_ENABLEV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("abRoadLane", "bLaneRhtBorderLine");
		}
	}

	// Parking violation detection parameter.
	public static class PU_TD_ILLEGAL_PARKINK_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable parking violation detection.
		public BOOL[] abRelatedLane = new BOOL[MAX_LANE_NUM]; // Associated lane.
		public ULONG ulDetectInterval; // Detection interval (currently used to replace the snapshot rule).
		public PU_TD_ILLEGAL_PARKINK_SNAP_RULE stSnapRules; // Snapshot rule.

		public PU_TD_ILLEGAL_PARKINK_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "abRelatedLane", "ulDetectInterval", "stSnapRules");
		}
	}

	// Parking violation snapshot rule.
	public static class PU_TD_ILLEGAL_PARKINK_SNAP_RULE extends Structure {
		public ULONG ulFrameNum; // Number of snapshots.
		// C Type :PU_IBALL_FRAME_TYPE_E
		public int[] enFrameType = new int[TD_MAX_SNAP_FRAME_NUM]; // Snapshot type.
		public NativeLong[] ulInterval = new NativeLong[TD_MAX_SNAP_FRAME_NUM]; // Snapshot interval.

		public PU_TD_ILLEGAL_PARKINK_SNAP_RULE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulFrameNum", "enFrameType", "ulInterval");
		}
	}

	// Parking violation types supported by the traffic PTZ dome camera.
	public interface PU_TD_ILLEGAL_TYPE_E {
		int TDOME_ILLEGAL_TYPE_A = 0; // The motor vehicle is parked against traffic regulations.
		int TDOME_ILLEGAL_TYPE_B = 1; // The motor vehicle is parked against no-parking signs.
		int TDOME_ILLEGAL_TYPE_C = 2; // Highway emergency lane or driveway parking in non-emergency situations.
		int TDOME_ILLEGAL_TYPE_D = 3; // This field is not used.
		int TDOME_ILLEGAL_TYPE_MAX = 4;
	}

	;

	// Lane parameters of traffic PTZ dome cameras.
	public static class PU_TD_LINE_PARAM extends Structure {
		public ULONG ulLaneNum; // Number of lane lines.
		public PU_TD_DTLINE_ENABLE stEnableList; // Lane line enabling list.
		public ROAD_PROPERTY_UNIT_S[] stLane = (ROAD_PROPERTY_UNIT_S[]) new ROAD_PROPERTY_UNIT_S()
				.toArray(MAX_LANE_NUM); // Number of lane lines = Number of lanes + 1
		public ROAD_PROPERTY_UNIT_S stLaneRhtBorderLine; // Right lane boundary.

		public PU_TD_LINE_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulLaneNum", "stEnableList", "stLane", "stLaneRhtBorderLine");
		}
	}

	;

	// Lane parameters of traffic PTZ dome cameras.
	public static class PU_TD_LINE_PARAMV2 extends Structure {
		public ULONG ulLaneNum; // Number of lane lines.
		public PU_TD_DTLINE_ENABLEV2 stEnableList; // Lane line enabling list.
		public ROAD_PROPERTY_UNIT_S[] stLane = (ROAD_PROPERTY_UNIT_S[]) new ROAD_PROPERTY_UNIT_S()
				.toArray(TDOME_MAX_LANE_NUM); // Number of lane lines = Number of lanes + 1
		public ROAD_PROPERTY_UNIT_S stLaneRhtBorderLine; // Right lane boundary.

		public PU_TD_LINE_PARAMV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulLaneNum", "stEnableList", "stLane", "stLaneRhtBorderLine");
		}
	}

	;

	// Manual parking violation detection parameters of traffic PTZ dome cameras.
	public static class PU_TD_MANUAL_DETECTION_PARAMS extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public PU_TD_ILLEGAL_PARKINK_PARAMS stIllegalParking; // Parking violation detection parameter.

		public PU_TD_MANUAL_DETECTION_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stIllegalParking");
		}
	}

	// Manual parking violation detection parameters of traffic PTZ dome cameras.
	public static class PU_TD_MANUAL_DETECTION_PARAMSV2 extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int iVersion; /* API version number, which does not need to be set. */
		public PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS stIllegalParking;

		public PU_TD_MANUAL_DETECTION_PARAMSV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "iVersion", "stIllegalParking");
		}
	}

	// Manual detection screen position of traffic PTZ dome cameras.
	public static class PU_TD_MANUAL_DETECTION_POSITION extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public PU_RECTANGLE stRectArea; // Position of the rectangle area in the 355 x 288 coordinate system.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_TD_MANUAL_DETECTION_POSITION() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stRectArea", "szReserve");
		}
	}

	public static class PU_TD_MD_AREA extends Structure {
		public ULONG ulX1;
		public ULONG ulY1;
		public ULONG ulX2;
		public ULONG ulY2;

		public PU_TD_MD_AREA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulX1", "ulY1", "ulX2", "ulY2");
		}
	}

	// Scene application parameters of traffic PTZ dome cameras.
	public static class PU_TD_SCENE_APP_PARAMS extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulIndex; // Scene ID.
		public PU_TD_LINE_PARAM stLaneLine; // Lane line parameter.
		public PU_TD_ILLEGAL_PARKINK_PARAMS stIllegalParking; // Parking violation detection parameter.

		public PU_TD_SCENE_APP_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulIndex", "stLaneLine", "stIllegalParking");
		}
	}

	// Scene application parameters of traffic PTZ dome cameras.
	public static class PU_TD_SCENE_APP_PARAMSV2 extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulIndex; // Scene ID.
		public PU_TD_LINE_PARAMV2 stLaneLine; // Lane line parameter.
		public PU_TD_ILLEGAL_PARKINK_PARAMS stIllegalParking; // This parameter is not used and is for compatibility
																// with old devices.
		public PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS stIllegalEviParams; // Violation evidence collection
																				// parameter.
		public PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS stTrafficEventParams; // Traffic event parameter.
		public PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS stTrafficDataCollectParams; // Traffic data collection
																							// parameter.

		public PU_TD_SCENE_APP_PARAMSV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulIndex", "stLaneLine", "stIllegalParking", "stIllegalEviParams",
					"stTrafficEventParams", "stTrafficDataCollectParams");
		}
	}

	// Basic scene parameters of traffic PTZ dome cameras.
	public static class PU_TD_SCENE_BASE_PARAMS extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulIndex; // Scene ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable a scene.
		public PU_TD_SCENE_DIRECTION_E enDirection; // Scenario direction.
		public byte[] szSceneName = new byte[TD_MAX_STRING_LENGTH]; // Scene name.
		public byte[] szSceneSite = new byte[TD_MAX_STRING_LENGTH]; // Scene position description.
		public PU_PTZ_CURRENT_LOCATION_EX stPtzLocation; // PTZ location information.

		public PU_TD_SCENE_BASE_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulIndex", "bEnable", "enDirection", "szSceneName", "szSceneSite",
					"stPtzLocation");
		}
	}

	// Scene direction of traffic PTZ dome cameras.
	public interface PU_TD_SCENE_DIRECTION_E {
		int PU_TD_SCENE_DIRECTION_SINGLE = 0; // Unidirectional.
		int PU_TD_SCENE_DIRECTION_DOUBLE = 1; // Bidirectional.
		int PU_TD_SCENE_DIRECTION_MAX = 2;
	}

	// Scene enabling information about traffic PTZ dome cameras.
	public static class PU_TD_SCENE_ENABLE_INFO extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public WinDef.BOOL[] abSceneEnable = new BOOL[TD_MAX_SCENE_NUM]; // Indicates whether to enable a scene.
		// public byte[][] szSceneName = new
		// byte[TD_MAX_SCENE_NUM][TD_MAX_STRING_LENGTH]; // Scene name.
		public byte[] szSceneName = new byte[TD_MAX_SCENE_NUM * TD_MAX_STRING_LENGTH]; // Scene name.

		public PU_TD_SCENE_ENABLE_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "abSceneEnable", "szSceneName");
		}
	}

	// Parameters for rotating traffic PTZ dome cameras to a scene.
	public static class PU_TD_SCENE_MOVE_TO_SCENE extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulIndex; // Scene ID.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_TD_SCENE_MOVE_TO_SCENE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulIndex", "szReserve");
		}
	}

	// Scheduled lock parameters of traffic PTZ dome cameras.
	public static class PU_TD_TIMING_LOCK_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable the ROI.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_TD_TIMING_LOCK_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szReserve");
		}
	}

	// Daily tour plan parameters.
	public static class PU_TD_TOUR_PLAN_ONE_DAY_PARAMS extends Structure {
		public ULONG ulBeginTime; // Tour start time, accurate to minute.
		public ULONG ulEndTime; // Tour end time, accurate to minute.
		public ULONG ulSceneNum; // Number of preset positions involved in a daily tour plan.
		public PU_TD_TOUR_TRACK_POINT_PARAMS[] stTourTrackPoint = (PU_TD_TOUR_TRACK_POINT_PARAMS[]) new PU_TD_TOUR_TRACK_POINT_PARAMS()
				.toArray(TD_MAX_SCENE_NUM);// Daily tour plan.

		public PU_TD_TOUR_PLAN_ONE_DAY_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulBeginTime", "ulEndTime", "ulSceneNum", "stTourTrackPoint");
		}
	}

	;

	// Tour plan parameters of traffic PTZ dome cameras.
	public static class PU_TD_TOUR_PLAN_PARAMS extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public BOOL bTourPlanEnable; // Indicates whether to enable a tour plan.
		// C type : PU_CYCLIC_MODE_E
		public int enCyclicMode; // Cyclic mode.
		// C type : PU_TOUR_MODE_E
		public int enTourMode; // Tour mode.
		public PU_TD_TOUR_PLAN_ONE_DAY_PARAMS[] stTourPlanDay = (PU_TD_TOUR_PLAN_ONE_DAY_PARAMS[]) new PU_TD_TOUR_PLAN_ONE_DAY_PARAMS()
				.toArray(TD_MAX_DAY_ONE_WEEK); // Tour plan parameter.

		public PU_TD_TOUR_PLAN_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bTourPlanEnable", "enCyclicMode", "enTourMode", "stTourPlanDay");
		}
	}

	;

	// Preset position in a tour.
	public static class PU_TD_TOUR_TRACK_POINT_PARAMS extends Structure {
		public ULONG ulIndex; // Scene ID, which is the same as that set in the scene configuration.
		public ULONG ulStayDruation; // Dwell duration, in minutes.

		public PU_TD_TOUR_TRACK_POINT_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulIndex", "ulStayDruation");
		}
	}

	// Application parameters of traffic PTZ dome cameras (unsafe lane change
	// detection).
	public static class PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulSnapFrameNum; // Number of snapshots.
		public ULONG ulSensitivity; // Detection sensitivity.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.

		public PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSnapFrameNum", "ulSensitivity", "abRelatedLane");
		}
	}

	// Application parameters of traffic PTZ dome cameras (traffic violation
	// evidence collection).
	public static class PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS extends Structure {
		public PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS stIllegalParkingParams; // Parking violation detection
																					// parameter.
		public PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS stRevDirectParams; // Wrong-way driving snapshot rule.
		public PU_TD_TRAFFIC_DOME_U_TURN_PARAMS stUTurnParams; // Illegal U-turn snapshot rule.
		public PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS stOverLaneLineParams; // Marked lanes violation snapshot rule.
		public PU_TD_TRAFFIC_DOME_CHANGE_LANE_PARAMS stChangeLaneParams; // Unsafe lane change snapshot rule.
		public PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS stMiBLaneParams; // Snapshot rule for detection of motor
																				// vehicles driving on non-motor vehicle
																				// lanes.

		public PU_TD_TRAFFIC_DOME_ILLEGAL_EVIDENCE_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stIllegalParkingParams", "stRevDirectParams", "stUTurnParams", "stOverLaneLineParams",
					"stChangeLaneParams", "stMiBLaneParams");
		}
	}

	// Intelligent violation analysis parameter of the traffic PTZ dome camera.
	public static class PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public byte[] szPlateLocalZH = new byte[MAX_PLATE_LOCAL_ZH_LEN]; // Preferential city type.
		public PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO stOverlayIntelInfo; // Information superimposed on images.
		public BOOL bPlateSmallPic; // License plate image. The default value is FALSE.
		public BOOL bEventUploadFlag; // Traffic violation event data upload. The default value is TRUE.
		public BOOL bEvidenceUploadFlag; // Traffic violation evidence data upload. The default value is TRUE.
		public ULONG ulFilterThreshold; // Violation filtering threshold. The default value is the maximum value.
		public long lPTZCalibrationHorizontal; // PTZ calibration parameter (horizontal).
		public long lPTZCalibrationVertical; // PTZ calibration parameter (vertical).
		// enIllegalType C type PU_TD_ILLEGAL_TYPE_E
		public int enIllegalType; // Parking violation type.
		public BOOL bRecordEnable; // Indicates whether to enable the recording function. The default value is
									// FALSE.

		public PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "szPlateLocalZH", "stOverlayIntelInfo", "bPlateSmallPic",
					"bEventUploadFlag", "bEvidenceUploadFlag", "ulFilterThreshold", "lPTZCalibrationHorizontal",
					"lPTZCalibrationVertical", "enIllegalType", "bRecordEnable");
		}
	}

	// Application parameters of traffic PTZ dome cameras (parking violation
	// detection).
	public static class PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulSnapFrameNum; // Number of snapshots.
		public ULONG ulSensitivity; // Detection sensitivity.
		public ULONG ulContinuousDuration; // Duration.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.
		public ULONG ulDetectInterval; // Detection interval (currently used to replace the snapshot rule).
		public PU_TD_ILLEGAL_PARKINK_SNAP_RULE stSnapRules; // Structure discarded in the V2 API, which does not need to
															// be set.

		public PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSnapFrameNum", "ulSensitivity", "ulContinuousDuration", "abRelatedLane",
					"ulDetectInterval", "stSnapRules");
		}
	}

	// Manual tracking switch of traffic PTZ dome cameras.
	public static class PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_SWITCH extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public BOOL bEnable; // Indicates whether to enable manual tracking.

		public PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_SWITCH() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable");
		}
	}

	// Manual tracking object information of traffic PTZ dome cameras.
	public static class PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_TARGET extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public ULONG ulObjID; // Object ID.
		public PU_TD_MD_AREA stRectArea; // Rectangular object frame position.

		public PU_TD_TRAFFIC_DOME_MANUAL_TRACK_EVIDENCE_TARGET() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulObjID", "stRectArea");
		}
	}

	// Application parameters of traffic PTZ dome cameras (detection of motor
	// vehicles driving on non-motor vehicle lanes).
	public static class PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulSnapFrameNum; // Number of snapshots.
		public ULONG ulSensitivity; // Detection sensitivity.
		public ULONG ulContinuousDuration; // Duration.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.

		public PU_TD_TRAFFIC_DOME_MOTOR_IN_BICYCLE_LANE_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSnapFrameNum", "ulSensitivity", "ulContinuousDuration", "abRelatedLane");
		}
	}

	// Application parameters of traffic PTZ dome cameras (marked lanes violation
	// detection).
	public static class PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulSnapFrameNum; // Number of snapshots.
		public ULONG ulSensitivity; // Detection sensitivity.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.

		public PU_TD_TRAFFIC_DOME_OVER_LANE_LINE_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSnapFrameNum", "ulSensitivity", "abRelatedLane");
		}
	}

	// Information superimposed on images.
	public static class PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO extends Structure {
		public BOOL bNearSnapAddTargetInfoFlag; // Object information superimposed on alarm-triggered snapshots.
		public BOOL bNearSnapAddRuleInfoFlag; // Rule information superimposed on alarm-triggered snapshots.
		public BOOL bFarSnapAddTargetInfoFlag; // Object information superimposed on distant images.
		public BOOL bFarSnapAddRuleInfoFlag; // Rule information superimposed on distant images.

		public PU_TD_TRAFFIC_DOME_OVERLAY_INTELLIGENT_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bNearSnapAddTargetInfoFlag", "bNearSnapAddRuleInfoFlag", "bFarSnapAddTargetInfoFlag",
					"bFarSnapAddRuleInfoFlag");
		}
	}

	// Application parameters of traffic PTZ dome cameras (wrong-way driving
	// detection)
	public static class PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulSnapFrameNum; // Number of snapshots.
		public ULONG ulSensitivity; // Detection sensitivity.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.

		public PU_TD_TRAFFIC_DOME_REVERSE_DIRECTION_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSnapFrameNum", "ulSensitivity", "abRelatedLane");
		}
	}

	;

	// Application parameters of traffic PTZ dome cameras (traffic data collection).
	public static class PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulStatisticsInterval; // Statistical interval.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.

		public PU_TD_TRAFFIC_DOME_TRAFFIC_DATA_COLLECT_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulStatisticsInterval", "abRelatedLane");
		}
	}

	;

	// Application parameters of traffic PTZ dome cameras (congestion detection
	// parameters).
	public static class PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulSensitivity; // Detection sensitivity.
		public ULONG ulContinuousDuration; // Duration.
		public ULONG ulFilterDuration; // Filtering duration.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.

		public PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSensitivity", "ulContinuousDuration", "ulFilterDuration",
					"abRelatedLane");
		}
	}

	;

	// Application parameters of traffic PTZ dome cameras (traffic event).
	public static class PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS extends Structure {
		public PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS stPedDtParams; // Pedestrian detection.
		public PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_CONGESTION_DT_PARAMS stCongestionDtParams; // Congestion detection.

		public PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stPedDtParams", "stCongestionDtParams");
		}
	}

	;

	// Application parameters of traffic PTZ dome cameras (pedestrian detection
	// parameters).
	public static class PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulSensitivity; // Detection sensitivity.
		public ULONG ulContinuousDuration; // Duration.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.

		public PU_TD_TRAFFIC_DOME_TRAFFIC_EVENT_PED_DT_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSensitivity", "ulContinuousDuration", "abRelatedLane");
		}
	}

	;

	// Application parameters of traffic PTZ dome cameras (illegal U-turn
	// detection).
	public static class PU_TD_TRAFFIC_DOME_U_TURN_PARAMS extends Structure {
		public BOOL bEnable; // Indicates whether to enable detection.
		public ULONG ulSnapFrameNum; // Number of snapshots.
		public ULONG ulSensitivity; // Detection sensitivity.
		public BOOL[] abRelatedLane = new BOOL[TDOME_MAX_LANE_NUM]; // Associated lane.

		public PU_TD_TRAFFIC_DOME_U_TURN_PARAMS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "ulSnapFrameNum", "ulSensitivity", "abRelatedLane");
		}
	}

	;

	// Unlock parameters of traffic PTZ dome cameras.
	public static class PU_TD_UNLOCK_PARAMS_S extends Structure {
		public BOOL bEnable; // Indicates whether to enable the ROI.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_TD_UNLOCK_PARAMS_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "szReserve");
		}
	}

	;

	// Temperature alarm parameters.
	public static class PU_TEMPERATURE_ALARM_PARA extends Structure {
		public NativeLong lEnable; // Indicates whether to enable the ROI.

		public ULONG ulDeteInterval; // Alarm check interval (1–256s). The system checks the alarm status at a
										// specified interval.
		public NativeLong lTemperatureMax;
		public NativeLong lTemperatureMin;

		public PU_TEMPERATURE_ALARM_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("lEnable", "ulDeteInterval", "lTemperatureMax", "lTemperatureMin");
		}
	}

	;

	// Three-image synthesis.
	public interface PU_THREE_PIC_SYNTHESIS_TYPE_E {
		int PU_THREE_PIC_SYNTHESIS_TYPE1 = 0; // Up-and-down arrangement.
		int PU_THREE_PIC_SYNTHESIS_TYPE2 = 1; // Left-and-right arrangement.
		int PU_THREE_PIC_SYNTHESIS_TYPE3 = 2; // Up-and-down arrangement of three images and one close-up image in cross
												// mode, with the close-up image at the upper left.
		int PU_THREE_PIC_SYNTHESIS_TYPE4 = 3; // Up-and-down arrangement of three images and one close-up image in cross
												// mode, with the close-up image at the upper right.
		int PU_THREE_PIC_SYNTHESIS_TYPE5 = 4; // Up-and-down arrangement of three images and one close-up image in cross
												// mode, with the close-up image at the lower left.
		int PU_THREE_PIC_SYNTHESIS_TYPE6 = 5; // Up-and-down arrangement of three images and one close-up image in cross
												// mode, with the close-up image at the lower right.
		int PU_THREE_PIC_SYNTHESIS_TYPE7 = 6; // Arrangement of three images in triangle mode, with the second image at
												// the top.
		int PU_THREE_PIC_SYNTHESIS_TYPE8 = 7; // Arrangement of three images in triangle mode, with the second image at
												// the bottom.
		int PU_THREE_PIC_NO_SYNTHESIS = 8; // Not synthesized.
		int PU_THREE_PIC_SYNTHESIS_TYPE_MAX = 9;
	}

	public static class PU_TIME_OSD_PARA extends Structure {
		public boolean bNeedAccurateToMs; // Indicates whether the time is accurate to millisecond.

		public PU_TIME_OSD_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bNeedAccurateToMs");
		}
	}

	;

	public static class PU_TIME_PLAN extends Structure {
		public ULONG ulCycle; // Cycle control. The options are as follows: 0: one-time; 1: in the specified
								// time segment every week.
		public ULONG ulPeriod; // Period. The options are as follows: 0: through a week; 1-7: a week day.
		public PU_TIME_S stStartTime; // Start time (UTC).
		public PU_TIME_S stEndTime; // End time (UTC).
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_TIME_PLAN() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCycle", "ulPeriod", "stStartTime", "stEndTime", "szReserved");
		}
	}

	/* Recording plan list. */
	public static class PU_TIME_PLAN_LIST extends Structure {
		public ULONG ulCycle; // Cycle control. The options are as follows: 0: one-time; 1: in the specified
								// time segment every week.
		public ULONG ulStartTime; // Start time: from 00:00:00.
		public ULONG ulEndTime; // End time: from 00:00:00.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_TIME_PLAN_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "enProtocol", "szServerIP", "ulServerPort", "szUserName", "szUserPwd",
					"enDirType", "enFirstDirType", "enSecondDirType", "enFileNamingRule", "szFirstDir", "szSecondDir",
					"szReserved");
		}
	}

	// Daily alert plan.
	public static class PU_TIME_PLAN_PER_DAY extends Structure {
		public ULONG ulStartTime; // Start time, which is the time from 00:00, in seconds.
		public ULONG ulEndTime; // End time, which is the time from 00:00, in seconds.

		public PU_TIME_PLAN_PER_DAY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulStartTime", "ulEndTime");
		}

	}

	// Scheduled task execution time segment.
	public static class PU_TIME_QUANTUM_INFO extends Structure {
		public ULONG ulTimeQuantumId; // Time segment indexes 1–8.
		public ULONG ulStartTime; // Start time (local time).
		public int enSceneMode; // Typical scene type. c type:PU_TYPICAL_SCENE_MODE
		public ULONG ulEndTime; // End time (local time), which occupies the reserved field.
		public byte[] szReserved = new byte[PU_RESERVE_LEN - LLong.size]; // Reserved field.

		public PU_TIME_QUANTUM_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulTimeQuantumId", "ulStartTime", "enSceneMode", "ulEndTime", "szReserved");
		}
	}

	// List of scheduled task execution time segments.
	public static class PU_TIME_QUANTUM_LIST extends Structure {
		public ULONG ulTimeQuantumNum; // Number of the first several valid time segments. Generally, the value is
										// specified by MAX_TIMEQAUMTUM_NUM.
		public PU_TIME_QUANTUM_INFO[] stTimeQuantumInfo = (PU_TIME_QUANTUM_INFO[]) new PU_TIME_QUANTUM_INFO()
				.toArray(PU_PLAN_NUM_MAX);
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_TIME_QUANTUM_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulTimeQuantumNum", "stTimeQuantumInfo", "szReserved");
		}
	}

	;

	public static class PU_TIME_RANGE_MIN_S extends Structure {
		public short sStartTime;
		public short sEndTime;

		public PU_TIME_RANGE_MIN_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("sStartTime", "sEndTime");
		}
	}

	/**
	 * //Time in the HHMMSS format (24-hour time system).
	 */
	public static class PU_TIME_S extends Structure {
		public static class ByValue extends PU_TIME_S implements Structure.ByValue {
		}

		public byte[] szYear = new byte[PU_TIME_YEAR_LEN];

		public byte[] szMonth = new byte[PU_TIME_OTHERS_LEN];

		public byte[] szDay = new byte[PU_TIME_OTHERS_LEN];

		public byte[] szHour = new byte[PU_TIME_OTHERS_LEN];

		public byte[] szMinute = new byte[PU_TIME_OTHERS_LEN];

		public byte[] szSecond = new byte[PU_TIME_OTHERS_LEN];

		public PU_TIME_S() {
			this.setAlignType(ALIGN_NONE);// Forced bytes are not filled
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szYear", "szMonth", "szDay", "szHour", "szMinute", "szSecond");
		}
	}

	// Tour mode.
	public interface PU_TOUR_MODE_E {
		int PU_E_DETECT_PRIORITY = 0; // Detection priority.
		int PU_E_SCENE_PRIORITY = 1; // Scene priority.
	}

	// Traffic shaping parameters.
	public static class PU_TRAFFIC_SHAPING_PARA extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable traffic shaping.
		public int enCoefficient; // Traffic shaping coefficient. c type:PU_TS_COEFFICIENT
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public PU_TRAFFIC_SHAPING_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "enCoefficient", "szReserved");
		}
	}

	// Traffic shaping parameters.
	public static class PU_TRAFFIC_SHAPING_PARA_S extends Structure {
		public WinDef.BOOL bEnable; // Indicates whether to enable traffic shaping.
		public PU_TS_COEFFICIENT enCoefficient; // Traffic shaping coefficient.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bEnable", "enCoefficient", "szReserved");
		}
	}

	// Transparent channel command.
	public static class PU_TRANSPARENT_CMD extends Structure {
		public ULONG ulSerialPort; // Serial port number.
		public ULONG ulCmdLen; // Length of the transparent channel command.
		public byte[] szTransparentCmd = new byte[PU_TRANSPARENT_CMD_MAX]; // Transparent channel command.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_TRANSPARENT_CMD() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSerialPort", "ulCmdLen", "szTransparentCmd", "szReserve");
		}
	}

	// Tripwire crossing direction.
	public interface PU_TRIPWIRE_DIR {
		public static final int PU_TRIPWIRE_CLOCKWISE = 0; // Clockwise tripwire crossing.
		public static final int PU_TRIPWIRE_ANTICLOCKWISE = 1; // Counterclockwise tripwire crossing.
		public static final int PU_TRIPWIRE_MAX = 2;
	}

	// Traffic shaping coefficient. c type:PU_TS_COEFFICIENT
	public interface PU_TS_COEFFICIENT {
		public static final int PU_TS_COEFFICIENT_11 = 11;
		public static final int PU_TS_COEFFICIENT_12 = 12;
		public static final int PU_TS_COEFFICIENT_13 = 13;
		public static final int PU_TS_COEFFICIENT_14 = 14;
		public static final int PU_TS_COEFFICIENT_15 = 15;
		public static final int PU_TS_COEFFICIENT_16 = 16;
		public static final int PU_TS_COEFFICIENT_17 = 17;
		public static final int PU_TS_COEFFICIENT_18 = 18;
		public static final int PU_TS_COEFFICIENT_19 = 19;
		public static final int PU_TS_COEFFICIENT_20 = 20;
		public static final int PU_TS_COEFFICIENT_21 = 21;
		public static final int PU_TS_COEFFICIENT_22 = 22;
		public static final int PU_TS_COEFFICIENT_23 = 23;
		public static final int PU_TS_COEFFICIENT_24 = 24;
		public static final int PU_TS_COEFFICIENT_25 = 25;
		public static final int PU_TS_COEFFICIENT_26 = 26;
		public static final int PU_TS_COEFFICIENT_27 = 27;
		public static final int PU_TS_COEFFICIENT_28 = 28;
		public static final int PU_TS_COEFFICIENT_29 = 29;
		public static final int PU_TS_COEFFICIENT_30 = 30;
		public static final int PU_TS_COEFFICIENT_31 = 31;
		public static final int PU_TS_COEFFICIENT_32 = 32;
		public static final int PU_TS_COEFFICIENT_33 = 33;
		public static final int PU_TS_COEFFICIENT_34 = 34;
		public static final int PU_TS_COEFFICIENT_35 = 35;
		public static final int PU_TS_COEFFICIENT_36 = 36;
		public static final int PU_TS_COEFFICIENT_37 = 37;
		public static final int PU_TS_COEFFICIENT_38 = 38;
		public static final int PU_TS_COEFFICIENT_39 = 39;
		public static final int PU_TS_COEFFICIENT_40 = 40;
	}

	/*------------ Tripwire crossing detection parameter structure ------------*/
	public static class PU_TW_ALARM_PARA extends Structure {
		public ULONG ulChannelId;
		public BOOL bEnable;
		public ULONG ulAlarmInterval; // Alarm check interval.
		/* c type : PU_IGT_TARGET_MODE */
		public int enTargetDetecMode;// Object recognition mode.
		public PU_IGT_TW_LINE_LIST_S stlineList; /*
													 * Tripwire list: When you obtain the tripwire list, the coordinates
													 * of all tripwires are returned. If the tripwire coordinates are 0,
													 * the tripwire is out of the camera's surveillance range (an index
													 * is returned).
													 */
		/*
		 * This parameter is optional. If ulLineNum is not set to 0, all tripwires are
		 * delivered. If ulLineNum is set to 0, no tripwire is delivered.
		 */
		public PU_ALARM_TIME_LIST_S stTWGuardPlan; // Alert plan.
		public ULONG ulSensitivity;
		public byte[] szReserved = new byte[PU_RESERVE_LEN - LLong.size];

		public PU_TW_ALARM_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "ulAlarmInterval", "enTargetDetecMode", "stlineList",
					"stTWGuardPlan", "ulSensitivity", "szReserved");
		}
	}

	// Two-image synthesis.
	public interface PU_TWO_PIC_SYNTHESIS_TYPE_E {
		int PU_TWO_PIC_SYNTHESIS_TYPE1 = 0; // Up-and-down arrangement.
		int PU_TWO_PIC_SYNTHESIS_TYPE2 = 1; // Left-and-right arrangement.
		int PU_TWO_PIC_SYNTHESIS_TYPE3 = 2; // Up-and-down arrangement of three images (including one close-up image),
											// with the close-up image at the top.
		int PU_TWO_PIC_SYNTHESIS_TYPE4 = 3; // Up-and-down arrangement of three images (including one close-up image),
											// with the close-up image at the bottom.
		int PU_TWO_PIC_SYNTHESIS_TYPE5 = 4; // Left-and-right arrangement of three images (including one close-up
											// image), with the close-up image at the leftmost.
		int PU_TWO_PIC_SYNTHESIS_TYPE6 = 5; // Left-and-right arrangement of three images (including one close-up
											// image), with the close-up image at the rightmost.
		int PU_TWO_PIC_SYNTHESIS_TYPE7 = 6; // Arrangement of three images (including one close-up image) in triangle
											// mode, with the close-up image at the top.
		int PU_TWO_PIC_SYNTHESIS_TYPE8 = 7; // Arrangement of three images (including one close-up image) in triangle
											// mode, with the close-up image at the bottom.
		int PU_TWO_PIC_SYNTHESIS_TYPE9 = 8; // Arrangement of three images (including one close-up image) in triangle
											// mode, with the close-up image at the leftmost.
		int PU_TWO_PIC_SYNTHESIS_TYPE10 = 9; // Arrangement of three images (including one close-up image) in triangle
												// mode, with the close-up image at the rightmost.
		int PU_TWO_PIC_NO_SYNTHESIS = 10; // Not synthesized.
		int PU_TWO_PIC_SYNTHESIS_TYPE_MAX = 11;
	}

	// Profiles for typical scenes.
	public static class PU_TYPICAL_SCENE_INFO extends Structure {
		public int enSceneMode; // Typical scene type. c type:PU_TYPICAL_SCENE_MODE
		public byte[] szName = new byte[PU_TYPICAL_SCENE_NAME_LEN]; // Typical scene profile name.
		public byte[] szDescribe = new byte[PU_TYPICAL_SCENE_DESCRIBE_LEN]; // Description.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_TYPICAL_SCENE_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSceneMode", "szName", "szDescribe", "szReserved");
		}
	}

	// List of profiles for typical scenes.
	public static class PU_TYPICAL_SCENE_LIST extends Structure {
		public ULONG ulChannelId; // Channel.
		public ULONG ulTypicalScenesNum; // Number of profiles for typical scenes.
		public int enSceneMode; // Currently activated typical scene profile. c type:PU_TYPICAL_SCENE_MODE
		public PU_TYPICAL_SCENE_INFO[] stTypicalSceneInfo = (PU_TYPICAL_SCENE_INFO[]) new PU_TYPICAL_SCENE_INFO()
				.toArray(PU_TYPICAL_SCENE_NUM_MAX); // Information list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_TYPICAL_SCENE_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulTypicalScenesNum", "enSceneMode", "stTypicalSceneInfo",
					"szReserved");
		}
	}

	// List of profiles for typical scenes.
	public static class PU_TYPICAL_SCENE_LIST_EX_OUT extends Structure {
		public ULONG ulChannelId; // Channel.
		public ULONG ulTypicalScenesNum; // Number of profiles for typical scenes.
		public int enSceneMode; // Currently activated typical scene profile. c type:PU_TYPICAL_SCENE_MODE
		public PU_TYPICAL_SCENE_INFO pstTypicalSceneInfo; // Information list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field. [0] indicates the parameter type. For
																// details, see PU_SCENE_PARAM_TYPE_E.

		public PU_TYPICAL_SCENE_LIST_EX_OUT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulTypicalScenesNum", "enSceneMode", "pstTypicalSceneInfo",
					"szReserved");
		}
	}

	/* Typical scene. */
	public interface PU_TYPICAL_SCENE_MODE {
		public static final int PU_TYPICAL_SCENE_DEFAULT = 0;/* Default scene. */
		public static final int PU_TYPICAL_SCENE_OUT_DOOR = 1; /* Outdoor. */
		public static final int PU_TYPICAL_SCENE_IN_DOOR = 2; /* Indoor. */
		public static final int PU_TYPICAL_SCENE_LOW_LIGHT = 3; /* Dimly lit. */
		public static final int PU_TYPICAL_SCENE_MOVE = 4; /* Motion scene. */
		public static final int PU_TYPICAL_SCENE_BACKLIGHT = 5; /* Backlit scene. */
		public static final int PU_TYPICAL_SCENE_USER_1 = 6; /* User-defined scene 1. */
		public static final int PU_TYPICAL_SCENE_USER_2 = 7; /* User-defined scene 2. */
		public static final int PU_TYPICAL_SCENE_USER_3 = 8; /* User-defined scene 3. */
		public static final int PU_TYPICAL_SCENE_USER_4 = 9; /* User-defined scene 4. */
		public static final int PU_TYPICAL_SCENE_USER_5 = 10; /* User-defined scene 5. */
		public static final int PU_TYPICAL_SCENE_USER_6 = 11; /* User-defined scene 6. */
		public static final int PU_TYPICAL_SCENE_USER_7 = 12; /* User-defined scene 7. */
		public static final int PU_TYPICAL_SCENE_USER_8 = 13; /* User-defined scene 8. */
		public static final int PU_TYPICAL_SCENE_FOGGY = 14; /* Overcast scene. */
		public static final int PU_TYPICAL_SCENE_FACE = 15; /* Face scene. */
		public static final int PU_TYPICAL_SCENE_NONE = 128; /* No scene is specified. */
		public static final int PU_TYPICAL_SCENE_MAX = 129;
	}

	public static class PU_UPGRADE_ITGT_FILE_INFO extends Structure {
		public PU_UPGRADE_ITGT_MODEL_PARA[] astItgtModelPara = new PU_UPGRADE_ITGT_MODEL_PARA[PU_UPGRADE_FILE_NUM_MAX]; // Intelligent
																														// algorithm
																														// upgrade
																														// package
																														// information.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_UPGRADE_ITGT_FILE_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("astItgtModelPara", "szReserve");
		}
	}

	;

	public static class PU_UPGRADE_ITGT_MODEL_PARA extends Structure {
		// C type : PU_UPGRADE_ITGT_TYPE_E
		public int enUpgradeItgtType; // Intelligent upgrade package type.
		public byte[] szModelPath = new byte[PU_UPGRADE_FILE_LEN_MAX]; // Intelligent upgrade package path.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_UPGRADE_ITGT_MODEL_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enUpgradeItgtType", "szModelPath", "szReserve");
		}
	}

	public interface PU_UPGRADE_ITGT_TYPE_E {
		int PU_UPGRADE_ITGT_TYPE_APP = 0; // App package.
		int PU_UPGRADE_ITGT_TYPE_FACE_BODY_DETECT = 1; // Face and person detection algorithm package.
		int PU_UPGRADE_ITGT_TYPE_FACE_RECOGTION = 2; // Facial recognition algorithm package.
		int PU_UPGRADE_ITGT_TYPE_ILLEG_PARK_DETECT = 4; // Parking violation detection algorithm package.
		int PU_UPGRADE_ITGT_TYPE_OBJ_CLASSIFICATION = 8; // Object classification and license plate detection algorithm
															// package.
		int PU_UPGRADE_ITGT_TYPE_NON_CHINA_VEHICLE_RECOGTION = 16; // Non-Chinese license plate detection algorithm
																	// package.
		int PU_UPGRADE_ITGT_TYPE_SCENE_ADAPTATION = 32; // Scene adaptation algorithm package.
		int PU_UPGRADE_ITGT_TYPE_QUEUE_LENTH_CROWD_COUNT = 33; // Queue length/Crowd density detection algorithm
																// package.
		int PU_UPGRADE_ITGT_3RD_TYPE_APP = 64; // Third-party app package.
		int PU_UPGRADE_LET_4G_MODEL = 65; // 4G software package.
		int PU_UPGRADE_DCHIP_TYPE_APP = 66; // DaVinci Mini chip (Ascend 310) upgrade package. The device needs to be
											// restarted.
		int PU_UPGRADE_DCHIP_TYPE_ALG = 67; // DaVinci Mini chip (Ascend 310) algorithm package, containing multiple
											// algorithms. All the algorithms must be upgraded to the same version.
		int PU_UPGRADE_EBI_TYPE_APP = 68; // Algorithm package dedicated to BEI perimeter intrusion detection cameras.
		int PU_UPGRADE_TYPE_MAX = 127; // Maximum number of upgrade package types.
	}

	;

	// Pattern scan.
	public class PU_USER_DEFINED_SCAN_PARA extends Structure {
		public WinDef.ULONG ulUserDefineIndex; // Pattern scan path.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulUserDefineIndex");
		}
	}

	public static class PU_USER_INFO extends Structure {
		public int enUserType; // User type.

		public byte[] szUserName = new byte[PU_USER_NAME_LEN]; // User name, which contains a maximum of 16 characters.
		public byte[] szUserPwd = new byte[PU_PASSWORD_LEN]; // Pwd
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates the maximum number of users
																// allowed to simultaneously log in to the web system.
																// The value ranges from 1 to 10.

		public PU_USER_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enUserType", "szUserName", "szUserPwd", "szReserved");
		}
	}

	// All users.
	public static class PU_USER_LIST extends Structure {
		public ULONG ulCurrentUserNum; // Number of current users.

		public PU_USER_INFO[] szUserList = new PU_USER_INFO[PU_DEVICE_USER_NUM_MAX]; // Current user list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_USER_LIST() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulCurrentUserNum", "szUserList", "szReserved");
		}
	}

	;

	// User type.
	public interface PU_USER_TYPE {
		public static final int PU_USER_TYPE_SYSTEM_ADMIN = 0; // Administrator.
		public static final int PU_USER_TYPE_ADVANCED_OPERATOR = 1; // Advanced operator.
		public static final int PU_USER_TYPE_COMMON_OPERATOR = 2; // Common operator.
		public static final int PU_USER_TYPE_MAX = 3;
	}

	public static class PU_UserData extends Structure {
		public static class ByReference extends PU_UserData implements Structure.ByReference {
		}

		public int eType; // LAYER_THREE_TYPE_E
		public unMetaData unMetaData = new unMetaData();

		public PU_UserData() {
			this.setAlignType(ALIGN_NONE);
		}

		public PU_UserData(Pointer p) {
			super(p);
			read();
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("eType", "unMetaData");
		}

		@Override
		public void read() {
			super.read();
			switch (eType) // Set the association type according to the value of eType.
			{
			case VEHICLE_SPEED: { // 速度
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS: { // =0x070000A0,//车流量统计参数
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_LANE_COUNT: { // =0x070000A1,//微卡口车流量统计车道数量
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_LANE_INDEX: { // =0x070000A2,//微卡口车流量统计当前车道
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_COUNT: { // =0x070000A3,//车辆计数
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_AVG_SPEED: { // =0x070000A4,//平均速度
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_LANE_TIME_USED_RATIO: { // =0x070000A5,//车道时间占有率
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_DENSITY: { // =0x070000A6,//车流密度
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_HEAD_INTERVAL: { // =0x070000A7,//车头时间间隔
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_HEAD_SPACE_INTERVAL: { // =0x070000A8,//车头间隔
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_CONGESTION_DEGREE: { // =0x070000A9,//交通状态
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE1_COUNT: { // = 0x070000AA,//大型车数量
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE2_COUNT: { // = 0x070000AB,//中型车数量
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_VEHICLE_TYPE3_COUNT: { // = 0x070000AC,//小型车数量
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_QUEUE_LENGTH: { // =0x070000AD,//排队长度
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case MICRO_PORT_TRAFFIC_STATISTICS_LANE_SPACE_USED_RATIO: { // = 0x070000AE,//车道空间占有率
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case ITS_TRAFFIC_SNAP_TIME: { // = 0x070000B3, //its车流量统计抓拍时间
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case REGULATION_TYPE: { // 违章类型
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
			}
				break;
			case PLATE_PIC: {
				unMetaData.setType(unMetaData.stBinay.getClass());
				unMetaData.read();
			}
				break;
			case PLATE_CHAR:
				unMetaData.setType(unMetaData.stBinay.getClass());
				unMetaData.read();
				break;
			case VEHICLE_PIC:
				unMetaData.setType(unMetaData.stBinay.getClass());
				unMetaData.read();
				break;
			case CAR_YEAR_BRAND:
				unMetaData.setType(unMetaData.stBinay.getClass());
				unMetaData.read();
				break;
			case CAR_SUB_BRAND:
				unMetaData.setType(unMetaData.stBinay.getClass());
				unMetaData.read();
				break;
			case CAR_PRE_BRAND:
				unMetaData.setType(unMetaData.stBinay.getClass());
				unMetaData.read();
				break;
			case PANORAMA_PIC:
				unMetaData.setType(unMetaData.stBinay.getClass());
				unMetaData.read();
				break;
			case PIC_SNAPSHOT_TIME:
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
				break;
			case PLATE_TYPE:
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
				break;
			case PLATE_COLOR:
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
				break;
			case VEHICLE_DIRECTION:
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
				break;
			case VEHICLE_TYPE:
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
				break;
			case VEHICLE_COLOR:
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
				break;
			case LANE_ID:
				unMetaData.setType(unMetaData.uIntValue.getClass());
				unMetaData.read();
				break;
			default:
				String t = Long.toHexString(eType).toUpperCase();
				System.out.println("Unprocessed data types(eType): 0x" + (t.length() <= 7 ? "0" : "") + t);
				break;
			}
		}
	}

	/**** Behavior analysis linkage with intelligent tracking ****/
	public static class PU_VA_LINK_AT extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable the algorithm.
		/* C type : PU_ALARM_TYPE_E */
		public int enAlarmType; // Alarms that need to be linked to automatic tracking.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_VA_LINK_AT() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "enAlarmType", "szReserved");
		}
	}

	// Vehicle color.
	public interface PU_VEHICLE_COLOR {
		public static final int PU_LPR_VC_NOT = 0; // Unknown.
		public static final int PU_LPR_VC_WHITE = 1; // White.
		public static final int PU_LPR_VC_GRAY = 2; // Gray (silver).
		public static final int PU_LPR_VC_YELLOW = 3; // Yellow.
		public static final int PU_LPR_VC_PINK = 4; // Pink.
		public static final int PU_LPR_VC_RED = 5; // Red.
		public static final int PU_LPR_VC_GREEN = 6; // Green.
		public static final int PU_LPR_VC_BLUE = 7; // Blue.
		public static final int PU_LPR_VC_BROWN = 8; // Brown.
		public static final int PU_LPR_VC_BLACK = 9; // Black.
		public static final int PU_LPR_VC_PURPLE = 10; // Purple.
		public static final int PU_LPR_VC_ORANGE = 11; // Orange.
		public static final int PU_LPR_VC_CYAN = 12; // Cyan.
		public static final int PU_LPR_VC_GOLDEN = 13; // Golden.
		public static final int PU_LPR_VC_SILVER = 14; // Silver.
	}

	// Vehicle detector information.
	public static class PU_VEHICLE_DETECTOR_INFO_S extends Structure {
		public ULONG uiDetectRoadEnable; // Indicates whether to enable the external device.
		public ULONG uiDetectLaneId; // ID of the lane covered by the external device. The value 1 indicates that
										// detection for lane 1 is enabled, and the rest may be deduced by analogy.
		// C Type : PU_ITS_SERIAL_PORT_E
		public int enDetecSerialPortId; // Serial port number used by the external device.
		public PU_ITS_RS_PARA_S stDetectDevSerialCfg; // Serial port configuration.
		public PU_ITS_COIL_DETECTOR_INFO_S stCfgCoilDetector; // Loop vehicle detector.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_VEHICLE_DETECTOR_INFO_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiDetectRoadEnable", "uiDetectLaneId", "enDetecSerialPortId", "stDetectDevSerialCfg",
					"stCfgCoilDetector", "szReserve");
		}
	}

	// Vehicle direction.
	public interface PU_VEHICLE_DIR {
		public static final int PU_VLPR_VD_HEAD = 0; // Vehicle front.
		public static final int PU_VLPR_VD_TAIL = 1; // Vehicle rear.
		public static final int PU_VLPR_VD_HEAD_AND_TAIL = 2; // Bidirectional.
	}

	public static class PU_VEHICLE_INFO_S extends Structure {
		public PU_AREA_INFO_S.ByValue stVehicleLoc; // Vehicle position.
		public int enVehicleColor; // Vehicle color.
		public int enVehicleType; // Vehicle type.
		public PU_AREA_INFO_S.ByValue stVehicleFaceLoc; // Vehicle front position.
		public byte[] szReserved = new byte[64]; // Reserved field.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stVehicleLoc", "enVehicleColor", "enVehicleType", "stVehicleFaceLoc", "szReserved");
		}
	}

	// Vehicle type.
	public interface PU_VEHICLE_TYPE {
		public static final int PU_LPR_VT_PEDESTRAIN = 9; // Pedestrian.
		public static final int PU_LPR_VT_SCHOOL_BUS = 10; // School bus.
		public static final int PU_LPR_VT_HEAVY_TRUCK = 11; // Dump truck.
		public static final int PU_LPR_VT_TANKER = 12; // High-risk vehicle.
		public static final int PU_LPR_VT_RIDEMAN = 13; // Rider.
		// =================The preceding types are supported by old versions.
		public static final int PU_VLPR_VT_CAR_M = 14; // Mini car.
		public static final int PU_VLPR_VT_CAR_L = 15; // Small car.
		public static final int PU_VLPR_VT_CAR_S = 16; // Compact car.
		public static final int PU_VLPR_VT_CAR_TWO = 17; // Two-box car.
		public static final int PU_VLPR_VT_CAR_THR = 18; // Three-box car.
		public static final int PU_VLPR_VT_SUV_QINGKE = 19; // Light bus.
		public static final int PU_VLPR_VT_SUV_L = 20; // Small SUV.
		public static final int PU_VLPR_VT_SUV_S = 21; // Compact SUV.
		public static final int PU_VLPR_VT_SUV_Z = 22; // Medium SUV.
		public static final int PU_VLPR_VT_SUV_M = 23; // Medium and large SUV.
		public static final int PU_VLPR_VT_SUV_B = 24; // Large SUV.
		public static final int PU_VLPR_VT_WEIMIAN = 25; // Mini van.
		public static final int PU_VLPR_VT_MPV = 26; // MPV
		public static final int PU_VLPR_VT_JP = 27; // Coupe.
		public static final int PU_VLPR_VT_WEIKA = 28; // Mini truck.
		public static final int PU_VLPR_VT_SUV_PIKA = 29; // Pickup truck.
		public static final int PU_VLPR_VT_TRUCK_Z = 30; // Medium truck.
		public static final int PU_VLPR_VT_TRUCK_KEI = 31; // Light truck.
		public static final int PU_VLPR_VT_ZHONGKA = 32; // Heavy truck.
		public static final int PU_VLPR_VT_TAXI = 33; // Taxi.
		public static final int PU_VLPR_VT_TANK = 34; // Tank truck.
		public static final int PU_VLPR_VT_CRANE = 35; // Mobile crane.
		public static final int PU_LPR_VT_ALL = 512; // All.
	}

	// Vertical limit.
	public static class PU_VERTICAL_LIMIT_S extends Structure {
		public int iVerticalLimit; // Vertical limit.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("iVerticalLimit", "szReserve");
		}
	}

	// Vertical scan.
	public class PU_VERTICAL_SCAN_PARA extends Structure {
		public WinDef.ULONG ulSpeed; // Speed.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulSpeed");
		}
	}

	// Object classification parameters.
	public static class PU_VHD_PARA extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable global configuration of license plate parameters.
		public WinDef.BOOL bSendSnapPicture; // Upload small images.
		public WinDef.BOOL bSendPanorama; // Upload full images.
		public WinDef.BOOL bLaneLineEnable; // Indicates whether to enable lane lines.
		// C type : PU_VLPR_ALG_MODE
		public int enAlgMode; // Snapshot algorithm type.
		public int iWidth; // Image width.
		public int iHeight; // Image height.
		public int iLaneNum; // Lane quantity.
		public PU_IMRS_LINE_S[] stLane = new PU_IMRS_LINE_S[MAX_AREA_VERTEX]; // Number of lane lines = Number of lanes
																				// + 1
		public byte[] szPlateLocalZH = new byte[MAX_PLATE_LOCAL_ZH_LEN]; // Preferred city type. A maximum of six city
																			// types can be selected. If the number of
																			// types exceeds six, six are preferred. For
																			// example, Shanghai, Jiangsu, and Zhejiang.

		public WinDef.BOOL bExposureEnable; // Indicates whether to enable the exposure function.
		public byte[] ulROIMeterLevel; // Exposure coefficient.

		public byte[] szReserved = new byte[PU_RESERVE_LEN - 4 - 4 - 4 - 4];//

		public PU_VHD_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "bSendSnapPicture", "bSendPanorama", "bLaneLineEnable",
					"enAlgMode", "iWidth", "iHeight", "iLaneNum", "stLane", "szPlateLocalZH", "bExposureEnable",
					"ulROIMeterLevel");
		}
	}

	// Extended object parameters.
	public static class PU_VHD_PARA_EX extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable global configuration of license plate parameters.
		public WinDef.BOOL bSendSnapPicture; // Upload small images.
		public WinDef.BOOL bSendPanorama; // Upload full images.
		public WinDef.BOOL bLaneLineEnable; // Indicates whether to enable lane lines.
		// C type : PU_VLPR_ALG_MODE
		public int enAlgMode; // Snapshot algorithm type.
		public int iWidth; // Image width.
		public int iHeight; // Image height.
		public int iLaneNum; // Lane quantity.
		public PU_IMRS_LINE_S[] stLane = new PU_IMRS_LINE_S[MAX_AREA_VERTEX]; // Number of lane lines = Number of lanes
																				// + 1
		public byte[] szPlateLocalZH = new byte[MAX_PLATE_LOCAL_ZH_LEN]; // Preferred city type. A maximum of six city
																			// types can be selected. If the number of
																			// types exceeds six, six are preferred. For
																			// example, Shanghai, Jiangsu, and Zhejiang.

		public WinDef.BOOL bExposureEnable; // Indicates whether to enable the exposure function.
		public char ulROIMeterLevel; // Exposure coefficient.

		public PU_LANE_ATTR_PARA[] stLaneAttr = new PU_LANE_ATTR_PARA[MAX_LANE_NUM]; // Lane attribute.
		public AERADTC_LIST stAreaList; // ROI detection area.

		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_VHD_PARA_EX() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "bSendSnapPicture", "bSendPanorama", "bLaneLineEnable",
					"enAlgMode", "iWidth", "iHeight", "iLaneNum", "stLane", "szPlateLocalZH", "bExposureEnable",
					"ulROIMeterLevel", "stLaneAttr", "stAreaList", "szReserved");
		}
	}

	/* Metering mode. */
	public interface PU_VIDEO_AEMETERING_MODE {
		public static final int PU_VIDEO_AEMETERING_CENTER = 0; // Center-weighted average metering (not supported).
		public static final int PU_VIDEO_AEMETERING_SPOT = 1; // Spot metering (not supported).
		public static final int PU_VIDEO_AEMETERING_AVERAGE = 2; // Average metering.
		public static final int PU_VIDEO_AEMETERING_BACKLIGHT = 3; // Backlight metering (not supported).
		public static final int PU_VIDEO_AEMETERING_CLOSE = 4; // Disabled (not supported).
		public static final int PU_VIDEO_AEMETERING_USER = 5; // User-defined.
		public static final int PU_VIDEO_AEMETERING_MAX = 6;
	}

	/******************************************************************************
	 * Note: Type of the memory release callback function. Parameter: uiChannelID -
	 * [in] channel ID pMem - [in] memory address Return value: None
	 *******************************************************************************/
	interface PU_VIDEO_ALG_FREE_FXN extends StdCallCallback {
		void invoke(UINT uiChannelID, Pointer pMem);
	}

	/******************************************************************************
	 * Note: Log callback function type Parameter: uiChannelID - [in] channel ID
	 * eLevel - [in] Log level pszMsg - [in] Log content (character string). ... -
	 * [in] Variable parameter Return value: None
	 *******************************************************************************/
	interface PU_VIDEO_ALG_LOG_FXN extends StdCallCallback {
		void invoke(UINT uiChannelID, PU_VIDEO_ALG_LOG_LEVEL eLevel, String pszMsg);
	}

	// Log level.
	public interface PU_VIDEO_ALG_LOG_LEVEL {
		public static final int PU_VIDEO_ALG_LOG_ERROR = 0; // Log generated when an error occurs.
		public static final int PU_VIDEO_ALG_LOG_WARNING = 1; // Log generated when an alarm occurs.
		public static final int PU_VIDEO_ALG_LOG_INFO = 2; // Auxiliary information.
		public static final int PU_VIDEO_ALG_LOG_DEBUG = 3; // Debug information, which provides reference for R&D
															// personnel to perform debugging.
	}

	/******************************************************************************
	 * Note : Type of the memory allocation callback function. Parameter:
	 * uiChannelID - [in] channel ID uiSize - [in] memory size Return value: If the
	 * operation succeeds, the memory address is returned. If the operation fails,
	 * NULL is returned.
	 *******************************************************************************/
	interface PU_VIDEO_ALG_MALLOC_FXN extends StdCallCallback {
		void invoke(UINT uiChannelID, UINT uiSize);
	}

	// Video parameter structure.
	public static class PU_VIDEO_ATTRIBUTE extends Structure {

		public ULONG ulBitRate; // Bit rate.

		public ULONG ulIFrameInterval; // I-frame interval.
		public ULONG ulFrameRate; // Frame rate.
		public int enVideoEncodeMode; // Video encoding type.
		public int enResolution; // Resolution. c :type PU_RESOLUTION_TYPE
		public int enBitRateType; // Bit rate type.
		public int enPicQuality; // Image quality.
		public int enVideoFormat; // Image standard.
		public int enRcPriMode; // Frame rate or bit rate priority mode (valid only in H.264format).
		public int enMirrorMode; // Mirroring mode (The mirroring mode of the primary stream takes effect.).
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // szReserve[0] indicates the encoding complexity. H264: 0:
															// BP, 1: MP, 2: HP;
		// H265: 0: Main, 1: Main10, 2: MainSP (Currently, only Main is supported.).
		// szReserve[1] indicates the MJPEG quality value [2,99].
		// szReserve[2] indicates whether to enable layered encoding. 0: disable; 1:
		// enable (valid only when setting or obtaining stream profiles).
		// szReserve[3] indicates the intelligent encoding level. The value 0 indicates
		// that intelligent encoding is disabled. The value 1-5 indicates levels 1 to 5.
		// szReserve[4] indicates whether to enable multi-slice encoding. 0: disable; 1:
		// enable.

		public PU_VIDEO_ATTRIBUTE() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulBitRate", "ulIFrameInterval", "ulFrameRate", "enVideoEncodeMode", "enResolution",
					"enBitRateType", "enPicQuality", "enVideoFormat", "enRcPriMode", "enMirrorMode", "szReserve");
		}
	}

	/* Day/Night mode. */
	public interface PU_VIDEO_BLACKWHITE_MODE {
		public static final int PU_VIDEO_MODE_AUTO = 0; // Auto mode.
		public static final int PU_VIDEO_MODE_COLOR = 1; // Color mode.
		public static final int PU_VIDEO_MODE_GRAY = 2; // B/W mode.
		public static final int PU_VIDEO_MODE_NEGART = 3;
	}

	// Video stream transmission type.
	public interface PU_VIDEO_CODE_TYPE {
		public static final int PU_VIDEO_CODE_TYPE_ES = 0; // Elementary stream (ES).
		public static final int PU_VIDEO_CODE_TYPE_PS = 1; // Program stream (PS).
		public static final int PU_VIDEO_CODE_TYPE_TS = 2; // Transport stream (TS).
		public static final int PU_VIDEO_CODE_TYPE_MAX = 3;
	}

	;

	/* Video day/night mode. */
	public interface PU_VIDEO_DAYNIGHT_MODE {
		public static final int PU_VIDEO_DAYNIGHT_MODE_AUTO = 0; // Auto mode.
		public static final int PU_VIDEO_DAYNIGHT_MODE_COLOR = 1; // Color mode.
		public static final int PU_VIDEO_DAYNIGHT_MODE_GRAY = 2; // B/W mode.
		public static final int PU_VIDEO_DAYNIGHT_MODE_MAX = 3;
	}

	// Video display effect structure.
	public static class PU_VIDEO_DISPLAY_INFO extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public NativeLong lBrightValue; // Brightness.
		public NativeLong lHueValue; // Hue.
		public NativeLong lSaturationValue; // Saturation.
		public NativeLong lContrastValue; // Contrast.
		public NativeLong lSharpValue; // Sharpness.
		public int enSharpSwitch; // Indicates whether to enable sharpness.
		public ULONG ulBitMap; // Modify bit. The five bits (for example, 00000) indicate the sharpness, hue,
								// saturation, contrast, and brightness from the lowest bit to the highest bit
								// respectively. The value 1 indicates modification. The value 0 indicates no
								// modification.
		public byte[] szReserved = new byte[PU_RESERVE_LEN - LLong.size - 4];

		public PU_VIDEO_DISPLAY_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "lBrightValue", "lHueValue", "lSaturationValue", "lContrastValue",
					"lSharpValue", "enSharpSwitch", "ulBitMap", "ulBitMap");
		}
	}

	/* Video encoding parameters. */
	public static class PU_VIDEO_ENCODE_PARA extends Structure {
		public PU_STREAM_MODE_E enVideoStreamMode; // Stream profile mode.

		public WinDef.BOOL bDynamicFrmRateEnable; // Indicates whether to enable the dynamic frame rate.
		public ULONG ulDynamicFrmRate; // Dynamic frame rate.
		public WinDef.BOOL bDynamicBitRateEnable; // Indicates whether to enable the variable bit rate (VBR).
		public ULONG ulDynamicBitRate; // VBR.
		public int enFrameMat; // Video collection frame format.
		public PU_STREAM_ATTRIBUTE[] stStreamAttribute = (PU_STREAM_ATTRIBUTE[]) new PU_STREAM_ATTRIBUTE()
				.toArray(PU_ENC_STREAM_MAX_NUM); // Video attribute.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];// szReserved[0] indicates the narrow or wide screen mode.
															// The options are as follows: 0: wide screen; 1: narrow
															// screen.

		public PU_VIDEO_ENCODE_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enVideoStreamMode", "bDynamicFrmRateEnable", "ulDynamicFrmRate",
					"bDynamicBitRateEnable", "ulDynamicBitRate", "enFrameMat", "stStreamAttribute", "szReserve");
		}
	}

	;

	/* Video encoding parameters V2 (five streams). */
	public static class PU_VIDEO_ENCODE_PARAV2 extends Structure {
		public int enVideoStreamMode; // Stream profile mode.

		public WinDef.BOOL bDynamicFrmRateEnable; // Indicates whether to enable the dynamic frame rate.
		public ULONG ulDynamicFrmRate; // Dynamic frame rate.
		public WinDef.BOOL bDynamicBitRateEnable; // Indicates whether to enable the variable bit rate (VBR).
		public ULONG ulDynamicBitRate; // VBR.
		public PU_FRAMERATE_FORMAT enFrameMat; // Video collection frame format.
		public PU_STREAM_ATTRIBUTE[] stStreamAttribute = (PU_STREAM_ATTRIBUTE[]) new PU_STREAM_ATTRIBUTE()
				.toArray(PU_ENC_STREAM_MAX_NUM_V2); // Video attribute.
		public byte[] szReserve = new byte[PU_RESERVE_LEN]; // szReserved[0] indicates the narrow or wide screen mode.
															// The options are as follows: 0: wide screen; 1: narrow
															// screen.

		public PU_VIDEO_ENCODE_PARAV2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulAudioChannelId", "enAudioEncodeMode", "ulInputVolume", "ulOutputVolume",
					"enAudioRate", "szReserved");
		}
	}

	/* Background frequency. */
	public interface PU_VIDEO_FLICKER_MODE {
		public static final int PU_VIDEO_FLICKER_NONE = 0; // Disabled.
		public static final int PU_VIDEO_FLICKER_50HZ = 1; // 50HZ
		public static final int PU_IDEO_FLICKER_60HZ = 2; // 60HZ
		public static final int PU_VIDEO_FLICKER_MAX = 3;
	}

	// Video standard.
	public interface PU_VIDEO_FORMAT {
		public static final int PU_VIDEO_FORMAT_PAL = 0; // PAL standard.
		public static final int PU_VIDEO_FORMAT_NTSC = 1; // NTSC standard.
		public static final int PU_VIDEO_FORMAT_MAX = 2;
	}

	/* Image mirroring and flip mode. */
	public interface PU_VIDEO_MIRROR_MODE {
		public static final int PU_VIDEO_MIRROR_MODE_NORMAL = 0; // Normal.
		public static final int PU_VIDEO_MIRROR_MODE_MIRROR = 1; // Left and right mirroring.
		public static final int PU_VIDEO_MIRROR_MODE_FLIP = 2; // Up and down mirroring.
		public static final int PU_VIDEO_MIRROR_MODE_BOTH = 3; // Up/down and left/right mirroring.
		public static final int PU_VIDEO_MIRROR_MODE_MAX = 4;
	}

	// Video stream information.
	public static class PU_VIDEO_STREAM_INFO extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int enStreamMode; // Video stream type. PU_VIDEO_TYPE
		public PU_STREAM_ATTRIBUTE[] stStreamAttribute = (PU_STREAM_ATTRIBUTE[]) new PU_STREAM_ATTRIBUTE()
				.toArray(PU_STREAM_MODE_E.PU_VIEDO_STREAM_TRIPLE);// Video attribute.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserve[0] indicates the full frame rate.
		// szReserve[1] indicates the narrow or wide screen.

		public PU_VIDEO_STREAM_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enStreamMode", "stStreamAttribute", "szReserved");
		}
	}

	// Video stream information.
	public static class PU_VIDEO_STREAM_INFO_V2 extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public int enStreamMode; // Video stream type. PU_VIDEO_TYPE
		public PU_STREAM_ATTRIBUTE[] stStreamAttribute = (PU_STREAM_ATTRIBUTE[]) new PU_STREAM_ATTRIBUTE()
				.toArray(PU_STREAM_MODE_E.PU_VIEDO_STREAM_FIVE);// Video attribute.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // szReserve[0] indicates the full frame rate. 25: 25 fps;
																// 30: 30 fps; 50: 50 fps; 60: 60 fps.
		// szReserve[1] indicates the narrow or wide screen. 0: wide screen; 1: narrow
		// screen.

		public PU_VIDEO_STREAM_INFO_V2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enStreamMode", "stStreamAttribute", "szReserved");
		}
	}

	// Stream type. PU_STREAM_TYPE
	public interface PU_VIDEO_TYPE_E {
		public static final int PU_VIDEO_TYPE_VIDEO = 0; // Video stream.
		public static final int PU_VIDEO_TYPE_AUDIO = 1; // Audio stream.
		public static final int PU_VIDEO_TYPE_MUX = 2; // Hybrid stream.
		public static final int PU_VIDEO_TYPE_RECORD = 3; // Recording.
		public static final int PU_VIDEO_TYPE_META = 4; // Metadata.
		public static final int PU_VIDEO_TYPE_VIDEO_META = 5; // Video+metadata stream.
		public static final int PU_VIDEO_TYPE_MAX = 6;
	}

	/* WDR mode. */
	public interface PU_VIDEO_WD_MODE {
		public static final int PU_WD_MODE_AUTO_WDR = 0; // Normal WDR.
		public static final int PU_WD_MODE_AUTO_ADWDR = 1; // Brighten the dark area; increase the WDR by 10 dB.
		public static final int PU_WD_MODE_AUTO_CNT = 2; // Used in image processing.
		public static final int PU_WD_MODE_AUTO_WDR_CNT = 3; // Increase the WDR level through offset comparison.
		public static final int PU_WD_MODE_AUTO_ADWDR_CNT = 4; // Increase 10 dB based on the offset comparison.
		public static final int PU_WD_MODE_RATIOFIX = 5; // The short exposure shutter speed is fixed. Set the ratio to
															// determine the long exposure.
		public static final int PU_WD_MODE_HISTOGRAM = 6; // Use the histogram to correct the over-bright and over-dark
															// areas.
		public static final int PU_WD_MODE_OFF_MODE = 7; // Dedicated to the TI chip; disabled.
		public static final int PU_WD_MODE_FRAMESWITCH = 8; // Dedicated to the TI chip; frame switching.
		public static final int PU_WD_MODE_STATIC_CHECK = 9; // Dedicated to the TI chip; static mode.
		public static final int PU_WD_MODE_DYNAMIC_CHECK = 10; // Dedicated to the TI chip; dynamic mode.
		public static final int PU_WD_MODE_MAX = 11; // Fluorescent lamp 1 (2500-3500 K).
	}

	public static class PU_VIDEODIAGNOSIS_ENABLE_PARAM extends Structure {

		public ULONG ulChnID; // Channel ID.

		public WinDef.BOOL bEnable; // Indicates whether to enable the algorithm.
		public PU_ALARM_TIME_PARA_LIST stAlarmTimeList;// This field is not used currently.

		public PU_VIDEODIAGNOSIS_ENABLE_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "stAlarmTimeList");
		}
	}

	public static class PU_VIM_POINT extends Structure {
		public int lPointPosX;
		public int lPointPosY;

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("lPointPosX", "lPointPosY");
		}
	}

	public static class PU_VLP_PARA_S extends Structure {
		public byte[] szPlateLocalZH = new byte[MAX_PLATE_LOCAL_ZH_LEN]; // Preferential city type.
		public WinDef.BOOL bInclineRectify; // Enable slant correction.
		public int iPlateSize; // License plate type. The options are as follows: 0: small license plate; 1:
								// large license plate; 2: micro license plate. The resolution of a small
								// license plate ranges from 40 to 200 pixels and that of a large license plate
								// ranges from 200 to 400 pixels.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("szPlateLocalZH", "bInclineRectify", "iPlateSize");
		}
	}

	// License plate snapshot algorithm type.
	public interface PU_VLPR_ALG_MODE {
		public static final int PU_VLPR_ALG_CHINESE = 0; // Chinese license plate.
		public static final int PU_VLPR_ALG_EURO = 1; // European license plate.
		public static final int PU_VLPR_ALG_INA = 2; // Indonesian license plate.
		public static final int PU_VLPR_ALG_MAX = 3;
	}

	public interface PU_VLPR_CATCH_MODE {
		public static final int PU_VLPR_MODE_MOTORWAY = 0; // Motor vehicle detection mode.
		public static final int PU_VLPR_MODE_COEXISTED = 1; // Motor vehicle, non-motor vehicle, and pedestrian
															// detection mode.
	}

	public static class PU_VLPR_FTP_DIR_NAMING_ELEM_S extends Structure {
		/* C type : PU_VLPR_FTP_DIR_NAMING_TYPE_E */
		public int enFtpDirNamingType;
		public byte[] acCustomContent = new byte[PU_MAX_CUSTOM_CONTENT_LEN]; // User-defined content.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enFtpDirNamingType", "acCustomContent", "szReserved");
		}
	}

	public interface PU_VLPR_FTP_DIR_NAMING_TYPE_E {
		int VLPR_FTP_DIR_NAMING_TYPE_DEV_IP = 0; // Device IP address.
		int VLPR_FTP_DIR_NAMING_TYPE_DEV_ID = 1; // Device ID.
		int VLPR_FTP_DIR_NAMING_TYPE_TIME_YM = 2; // Time (year/month).
		int VLPR_FTP_DIR_NAMING_TYPE_TIME_YMD = 3; // Time (year/month/day).
		int VLPR_FTP_DIR_NAMING_TYPE_DIR = 4; // Direction.
		int VLPR_FTP_DIR_NAMING_TYPE_LANE_ID = 5; // Lane ID.
		int VLPR_FTP_DIR_NAMING_TYPE_CUSTOM = 6; // Custom.
		int VLPR_FTP_DIR_NAMING_TYPE_CHANNEL = 7; // Channel ID.
		int VLPR_FTP_DIR_NAMING_TYPE_REGULATION = 8; // Violation type.
	}

	public static class PU_VLPR_FTP_DIR_PARA_S extends Structure {
		/* C type : PU_FTP_UPLOAD_DIR_TYPE_E */
		public int enDirType;
		public PU_VLPR_FTP_DIR_NAMING_ELEM_S[] astDirNamingElem = (PU_VLPR_FTP_DIR_NAMING_ELEM_S[]) new PU_VLPR_FTP_DIR_NAMING_ELEM_S()
				.toArray(PU_MAX_DIR_NAMING_ELEM);
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved field.

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enDirType", "astDirNamingElem", "szReserved");
		}
	}

	/************* FTP upload parameters of micro checkpoint cameras **************/
	public static class PU_VLPR_FTP_UPLOAD_PARA_S extends Structure {
		public BOOL bSnapPicEnable; // Indicates whether to enable snapshot retransmission.
		public BOOL bSendPlatePic; // Indicates whether to send license plate images.
		/* C type : PU_FTP_UPLOAD_PROTOCOL_TYPE_E */
		public int enProtocol; // Upload protocol.
		public byte[] szServerIP = new byte[PU_IP4_ADDR_LEN]; // Server IP address.
		public ULONG ulServerPort; // Server port.
		public byte[] szUserName = new byte[PU_CLIENT_USERNAME_LEN]; // User name.
		public PU_VLPR_FTP_DIR_PARA_S stDirNameingPara; // Directory naming parameters.
		public PU_PIC_NAMING_PARA_S stPicNamingPara; // Image naming parameters.
		/* c type : PU_FTP_TYPE_E */
		public int eFtpType;
		public BOOL bSendFacePic; // Indicates whether to send face images.
		public byte[] szReserved = new byte[PU_RESERVE_LEN - 4]; // Reserved field.
		public byte[] szUserPwd = new byte[PU_PASSWORD_LEN]; // Pwd

		public PU_VLPR_FTP_UPLOAD_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bSnapPicEnable", "bSendPlatePic", "enProtocol", "szServerIP", "ulServerPort",
					"szUserName", "stDirNameingPara", "stPicNamingPara", "eFtpType", "bSendFacePic", "szReserved",
					"szUserPwd");
		}
	}

	public static class PU_VLPR_FTP_UPLOAD_PARA_V2_S extends Structure {
		public BOOL bSnapPicEnable; // Indicates whether to enable snapshot retransmission.
		public BOOL bSendPlatePic; // Indicates whether to send license plate images.
		/* C type : PU_FTP_UPLOAD_PROTOCOL_TYPE_E */
		public int enProtocol; // Upload protocol.
		public byte[] szServerIP = new byte[PU_IP4_ADDR_LEN]; // Server IP address.
		public ULONG ulServerPort; // Server port.
		public byte[] szUserName = new byte[PU_CLIENT_USERNAME_LEN]; // User name.
		public PU_VLPR_FTP_DIR_PARA_S stDirNameingPara; // Directory naming parameters.
		public PU_PIC_NAMING_PARA_EX_S stPicNamingPara; // Image naming parameters.
		/* c Type : PU_FTP_TYPE_E */
		public int eFtpType;
		public WinDef.BOOL bSendFacePic; // Indicates whether to send face images.
		public byte[] szReserved = new byte[PU_RESERVE_LEN - 4]; // Reserved field.
		public byte[] szUserPwd = new byte[PU_PASSWORD_LEN]; // Pwd

		public PU_VLPR_FTP_UPLOAD_PARA_V2_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("bSnapPicEnable", "bSendPlatePic", "enProtocol", "szServerIP", "ulServerPort",
					"szUserName", "stDirNameingPara", "stPicNamingPara", "eFtpType", "bSendFacePic", "szReserved",
					"szUserPwd");
		}
	}

	// Global license plate parameters.
	public static class PU_VLPR_PARA_S extends Structure {
		public ULONG ulChnID; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable global configuration of license plate parameters.
		public int iLaneNum; // Lane quantity.
		public PU_IMRS_LINE_S[] stLane = new PU_IMRS_LINE_S[MAX_AREA_VERTEX];// Number of lane lines = Number of lanes +
																				// 1
		// C type : PU_VEHICLE_DIR
		public int enVehicleDir; // Vehicle direction (vehicle front direction by default).
		// C type : PU_VLPR_CATCH_MODE
		public int enCatchMode; // Snapshot type. The options are as follows: 0: motor vehicle; 1: motor
								// vehicle, non-motor vehicle, and pedestrian.
		public PU_VLP_PARA_S stVLPParam; // License plate parameters.
		public WinDef.BOOL bVColorDetection; // Indicates whether to enable vehicle color recognition.
		public WinDef.BOOL bVTypeDetection; // Indicates whether to enable vehicle type recognition.
		public WinDef.BOOL bSendPanoramaPic; // Indicates whether to send full images.
		public WinDef.BOOL bSendPlatePic; // Indicates whether to send license plate images.

		public PU_VLPR_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "iLaneNum", "stLane", "enVehicleDir", "enCatchMode",
					"stVLPParam", "bVColorDetection", "bVTypeDetection", "bSendPanoramaPic", "bSendPlatePic");
		}
	}

	public static class PU_VLPR_PARA_V2_S extends Structure {
		public ULONG ulChnID; // Channel ID.

		public WinDef.BOOL bEnable; // Indicates whether to enable global configuration of license plate parameters.
		public int iLaneNum; // Lane quantity.
		public PU_IMRS_LINE_S[] stLane = new PU_IMRS_LINE_S[5];
		public int enVehicleDir; // Vehicle direction (vehicle front direction by default).
		public int enCatchMode; // Snapshot type. The options are as follows: 0: motor vehicle; 1: motor
								// vehicle, non-motor vehicle, and pedestrian.
		public PU_VLP_PARA_S.ByValue stVLPParam; // License plate parameters.
		public WinDef.BOOL bVColorDetection; // Indicates whether to enable vehicle color recognition.
		public WinDef.BOOL bVTypeDetection; // Indicates whether to enable vehicle type recognition.
		public WinDef.BOOL bSendPanoramaPic; // Indicates whether to send full images.
		public WinDef.BOOL bSendPlatePic; // Indicates whether to send license plate images.
		public int enAlgMode; // License plate algorithm type.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_VLPR_PARA_V2_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "iLaneNum", "stLane", "enVehicleDir", "enCatchMode",
					"stVLPParam", "bVColorDetection", "bVTypeDetection", "bSendPanoramaPic", "bSendPlatePic",
					"enAlgMode", "szReserved");
		}
	}

	// Extended lane attributes.
	public static class PU_VLPR_PARA_V3_S extends Structure {
		public ULONG ulChnID; // Channel ID.

		public WinDef.BOOL bEnable; // Indicates whether to enable global license plate parameter settings.
		public int iLaneNum; // Lane quantity.
		public PU_IMRS_LINE_S[] stLane = new PU_IMRS_LINE_S[MAX_AREA_VERTEX]; // Number of lane lines = Number of lanes
																				// + 1
		public int enVehicleDir; // Vehicle direction (vehicle front direction by default).
		public int enCatchMode; // Snapshot type. The options are as follows: 0: motor vehicle; 1: motor
								// vehicle, non-motor vehicle, and pedestrian.
		public PU_VLP_PARA_S stVLPParam = new PU_VLP_PARA_S(); // License plate parameters.
		public WinDef.BOOL bVColorDetection; // Indicates whether to enable vehicle color recognition.
		public WinDef.BOOL bVTypeDetection; // Indicates whether to enable vehicle type recognition.
		public WinDef.BOOL bSendPanoramaPic; // Indicates whether to send full images.
		public WinDef.BOOL bSendPlatePic; // Indicates whether to send license plate images.
		public int enAlgMode; // License plate algorithm type.
		public WinDef.BOOL bExposureEnable; // Indicates whether to enable license plate exposure.
		public ULONG ulROIMeterLevel; // License plate exposure coefficient.
		public WinDef.BOOL bVlprEnhancement;
		public PU_LANE_ATTR_PARA[] stLaneAttr = new PU_LANE_ATTR_PARA[MAX_LANE_NUM]; // Lane attribute.
		public AERADTC_LIST stAreaList = new AERADTC_LIST(); // ROI detection area.
		public PU_IMRS_LINE_S[] stDetectLine = new PU_IMRS_LINE_S[MAX_AREA_VERTEX]; // Detection line.
		public WinDef.BOOL bEnableVehicleMfrType; // Indicates whether to enable secondary feature recognition.
		public WinDef.BOOL bEnableFacePic; // Indicates whether to enable face cutout.
		public PU_CAMPUS_MODE_PARA_S stCampusModePara;
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN - 28];

		public PU_VLPR_PARA_V3_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChnID", "bEnable", "iLaneNum", "stLane", "enVehicleDir", "enCatchMode",
					"stVLPParam", "bVColorDetection", "bVTypeDetection", "bSendPanoramaPic", "bSendPlatePic",
					"enAlgMode", "bExposureEnable", "ulROIMeterLevel", "bVlprEnhancement", "stLaneAttr", "stAreaList",
					"stDetectLine", "bEnableVehicleMfrType", "bEnableFacePic", "stCampusModePara", "szReserved");
		}
	}

	// Traffic flow statistics.
	public static class PU_VLPR_TRAFFIC_STATISTICS extends Structure {
		public NativeLong ulChannelId; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable PTZ control.
		public ULONG ulInterval; // Statistical interval.
		public ULONG uDistanceToCrossing; // Distance between the camera and the intersection.
		public ULONG uDetectAreaLength; // Detection area length.
		public ULONG uCongestionLaneThreshold; // Minimum number of congested lanes. When the number of congested lanes
												// is greater than or equal to the threshold, the road is determined as
												// congested.
		public float fCongestThreholdForUnblocked; // Congestion threshold: smooth.
		public float fCongestThreholdForAmble; // Congestion threshold: slow.
		public float fCongestThreholdForCongest; // Congestion threshold: congested.
		public byte[] szReserved = new byte[PU_RESERVE_EX_LEN];

		public PU_VLPR_TRAFFIC_STATISTICS() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "ulInterval", "uDistanceToCrossing", "uDetectAreaLength",
					"uCongestionLaneThreshold", "fCongestThreholdForUnblocked", "fCongestThreholdForAmble",
					"fCongestThreholdForCongest", "szReserved");
		}
	}

	// Voice intercom/broadcast structure.
	public static class PU_VOICE_INFO extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public byte[] szLocalAudioIp = new byte[PU_IP4_ADDR_LEN]; // Local audio IP address.
		public WinDef.BOOL bFeedAudioData; // Indicates whether to feed data. (Voice intercom: When this parameter is
											// set to TRUE, the callback function cannot be empty. When this parameter
											// is set to FALSE, the callback function must be empty.)
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public PU_VOICE_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "szLocalAudioIp", "bFeedAudioData", "szReserve");
		}
	}

	public interface PU_VW_3RD_APP_ACTION {
		int PU_ACTION_3RD_APP_START = 0;
		int PU_ACTION_3RD_APP_STOP = 1;
		int PU_ACTION_3RD_APP_MAX = 2;
	}

	public interface PU_VW_3RD_APP_STATUS {
		int PU_STATUS_3RD_APP_UNKNOWN = 0;
		int PU_STATUS_3RD_APP_STOP = 1;
		int PU_STATUS_3RD_APP_RUN = 2;
		int PU_STATUS_3RD_APP_MAX = 3;
	}

	/* Backlight adaptation under a channel. */
	public static class PU_VW_BACKLIGHT_ADAPT_PARA_S extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public BOOL enBackLightAdaptEnable; // Indicates whether to enable backlight adaptation.
		/* C type : BACKLIGHT_MODE_E */
		public int enBackLightMode; // Backlight area type.
		public PU_AREA_INFO stBackLightAdaptStart; // Backlight adaptation area information.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_VW_BACKLIGHT_ADAPT_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enBackLightAdaptEnable", "enBackLightMode", "stBackLightAdaptStart",
					"szReserved");
		}
	}

	/* Overcast adaptation under a channel. */
	public static class PU_VW_FOG_ADAPT_PARA_S extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public BOOL enFogAdaptEnable; // Indicates whether to enable overcast adaptation.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_VW_FOG_ADAPT_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enFogAdaptEnable", "szReserved");
		}
	}

	/**** Automatic or manual tracking object ****/
	public static class PU_VW_ITGT_AT_MANUAL_TARGET extends Structure {
		public ULONG ulX;
		public ULONG ulY;
		public ULONG ulWidth;
		public ULONG ulHeight;

		public PU_VW_ITGT_AT_MANUAL_TARGET() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulX", "ulY", "ulWidth", "ulHeight");
		}
	}

	/**** Automatic tracking message structure ****/
	public static class PU_VW_ITGT_AUTOTRACKING_PARAM extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public WinDef.BOOL bEnable; // Indicates whether to enable the algorithm.
		public ULONG ulSensitivity; // Algorithm detection sensitivity.
		public ULONG ulAlarmTime; // Alarm reporting interval.
		public ULONG ulMaxTraceTime; // Maximum tracking duration.
		public PU_ALARM_TIME_LIST_S stAlarmTimeList;// Scene change detection alert plan.
		public PU_IGT_AERADTC_LIST_S szAreaList; // Area list.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_VW_ITGT_AUTOTRACKING_PARAM() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "bEnable", "ulSensitivity", "ulAlarmTime", "ulMaxTraceTime",
					"stAlarmTimeList", "szAreaList", "szReserved");
		}
	}

	public static class PU_VW_OPERATE_3RD_APP extends Structure {
		/* C Type : PU_VW_OPERATE_3RD_APP_TYPE */
		public int enOperateType;
		public byte[] szAppName = new byte[PU_OPERATE_3RD_APP_NAME_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enOperateType", "szAppName");
		}
	}

	public interface PU_VW_OPERATE_3RD_APP_TYPE {
		int PU_OPERATE_3RD_APP_START = 0;
		int PU_OPERATE_3RD_APP_STOP = 1;
		int PU_OPERATE_3RD_APP_UNINSTALL = 2;
		int PU_OPERATE_3RD_APP_MAX = 3;
	}

	/* Trailing (speed) adaptation under a channel. */
	public static class PU_VW_SPEED_ADAPT_PARA_S extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public BOOL enSpeedAdaptEnable; // Indicates whether to enable trailing (speed) adaptation.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public PU_VW_SPEED_ADAPT_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "enSpeedAdaptEnable", "szReserved");
		}
	}

	/*
	 * White balance setting. The values of R and B can be fine-tuned in manual
	 * mode.
	 */
	public static class PU_WB_MANUAL_PARA_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enWBMode; // White balance mode. c type:PU_CAM_WB_MODE
		public ULONG ulROffset; // Red tuning, ranging from 0 to 255.
		public ULONG ulBOffset; // Blue tuning, ranging from 0 to 255.
		public ULONG ulRStrong; // Red fine-tuning, ranging from 0 to 255.
		public ULONG ulBStrong; // Blue fine-tuning, ranging from 0 to 255.
		public ULONG ulHighTemp; // Color temperature upper limit, ranging from 1500 to 10000K.
		public ULONG ulLowTemp; // Color temperature lower limit, ranging from 1500 to 10000K.
		public byte[] szReserve = new byte[PU_RESERVE_LEN - LLong.size - LLong.size];

		public PU_WB_MANUAL_PARA_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enWBMode", "ulROffset", "ulBOffset", "ulRStrong", "ulBStrong", "ulHighTemp",
					"ulLowTemp", "szReserve");
		}
	}

	/* WDR parameters. */
	public static class PU_WD_PARA_S extends Structure {
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enSwitchMode; // Indicates whether to enable the WDR (enable/disable/auto). c
									// type:PU_COMMONMODE_SWITCH
		/* C type : PU_COMMONMODE_SWITCH_E */
		public int enWDMode; // WDR mode. If this parameter is set to WD_MODE_RATIOFIX, lExpRatio needs to be
								// set. c type:PU_VIDEO_WD_MODE
		public NativeLong lExpRatio; // Sony: x1–x64; Hitachi: 127
		public ULONG ulAutoModeMaxExpRatio; // Maximum exposure ratio in auto WDR mode. T1: 1–16. The default value is
											// 8.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enSwitchMode", "enWDMode", "lExpRatio", "ulAutoModeMaxExpRatio", "szReserve");
		}
	}

	// WDR mode.
	public interface PU_WDR_SWITCH_MODE {
		public static final int PU_WDR_SWITCH_AUTO = 0; // Auto mode.
		public static final int PU_WDR_SWITCH_CLOSE = 1; // Disabled.
		public static final int PU_WDR_SWITCH_MANUAL = 2; // Manual mode.
		public static final int PU_WDR_SWITCH_MAX = 3;
	}

	public interface PU_WEB_HTTP_MODE {
		public static final int PU_WEB_HTTPS_HTTP = 0; // Support for HTTPS and HTTP.
		public static final int PU_WEB_HTTPS_ONLY = 1; // Support for only HTTPS.
		public static final int PU_WEB_HTTP_MAX = 2;
	}

	// Storage policy upon full disk.
	public static class RECORD_STRATEGY extends Structure {
		public ULONG ulChannelId;
		public ULONG ulStrategy; // Storage policy. The options are as follows: 0: Overwrite the earliest
									// recording; 1: Stop recording.
		public ULONG ulMinRecordTime; // Minimum pre-recording time.
		public ULONG ulPreAlarmRecordTime; // Pre-recording time. V200R003: 0: no pre-recording; 65535: maximum
											// pre-recording duration based on the memory capability; 5s to 20s based on
											// the device capability.
		// Versions earlier than V200R003: less than 10s.
		public byte[] szReserved = new byte[PU_RESERVE_LEN];

		public RECORD_STRATEGY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "ulStrategy", "ulMinRecordTime", "ulPreAlarmRecordTime", "szReserved");
		}
	}

	public static class ROAD_PROPERTY_UNIT_S extends Structure {
		// C type : PU_ITS_CAR_DRV_DIR_E
		public int enLaneDirection; /* Lane direction in video (leaving or approaching). */
		// C type : PU_ITS_ROAD_DRV_DIR_E
		public int enSignDirection; /* Vehicle direction (turn-left, turn-right, or straight-through). */
		// C type : ITS_ROAD_LINE_TYPE_E
		public int enLineType; /* Lane line type. */
		// C type : ITS_ROAD_SIDE_SCENE_E
		public int enLaneSideScene; /*
									 * Lane scene type, which is used to determine whether an illegal U-turn occurs.
									 */
		public PU_IMRS_LINE stLine; /* Lane line. */

		public ROAD_PROPERTY_UNIT_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enLaneDirection", "enSignDirection", "enLineType", "enLaneSideScene", "stLine");
		}
	}

	public static class SMTP_CONFIG_INFO extends Structure {
		public int enMailType; // Indicates whether the email is a parameter delivery email or a test email.
								// The options are as follows: 0: test; 1: parameter delivery.
		public WinDef.BOOL bSMTPEnable; // Indicates whether to enable 802.1X.
		public byte[] szSenderName = new byte[PU_SMTP_NAME_LEN_MAX]; // Sender name.
		public byte[] szSenderMail = new byte[PU_SMTP_MAIL_LEN]; // Sender email address.
		public byte[] szServerIP = new byte[PU_IP4_ADDR_LEN]; // Server IP address.
		public ULONG ulServerPort; // Server port.
		public int enSecurityType; // Encryption type. c type:PU_MEDIA_CRYPTO_TYPE
		public WinDef.BOOL bPicEnable; // Indicates whether to support image attachments.
		public ULONG ulPicNum; // Number of image attachments.
		public ULONG ulSnapTimeInterval; // Snapshot interval.
		public WinDef.BOOL bServerCrtEnable; // Indicates whether to enable server authentication.
		public byte[] szServerName = new byte[PU_CLIENT_USERNAME_LEN]; // Server user name.
		public byte[] szPassword = new byte[PU_PASSWORD_LEN]; // Server password.
		public ULONG ulReceiverNum; // Number of recipients.
		public PU_SMTP_RECVEIVER_INFO[] szReceiverInfo = (PU_SMTP_RECVEIVER_INFO[]) new PU_SMTP_RECVEIVER_INFO()
				.toArray(PU_SMTP_RECV_MAX_NUM); // Recipient list.
		public byte[] szReserved = new byte[64]; // Reserved field.

		public SMTP_CONFIG_INFO() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enMailType", "bSMTPEnable", "szSenderName", "szSenderMail", "szServerIP",
					"ulServerPort", "enSecurityType", "bPicEnable", "ulPicNum", "ulSnapTimeInterval",
					"bServerCrtEnable", "szServerName", "szPassword", "ulReceiverNum", "szReceiverInfo", "szReserved");
		}
	}

	// Manual snapshot parameters.
	public static class SNAPSHOT_PARA extends Structure {
		public ULONG ulChannelID; // Channel ID.
		public ULONG ulStreamID; // Stream ID. Currently, only the primary stream is supported.
		public int enResolution; // Resolution (The resolution cannot be set currently. The resolution of the
									// primary stream is used.). c type:PU_RESOLUTION_TYPE
		public int enPictureFormat; // Image format (Only the JPEG format is supported currently.). c type:
									// PU_SNAPSHOT_FORMAT
		public byte[] szPicPath = new byte[PU_SNAPSHOT_PIC_PATH_LEN + 4]; // Snapshot file directory.
		public byte[] szReserved = new byte[PU_RESERVE_LEN]; // Reserved.

		public SNAPSHOT_PARA() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelID", "ulStreamID", "enResolution", "enPictureFormat", "szPicPath",
					"szReserved");
		}
	}

	// Color.
	public static class ST_BINARY extends Structure {
		public int ulBinaryLenth;

		public Pointer pBinaryData;// UCHAR

		public ST_BINARY() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulBinaryLenth", "pBinaryData");
		}
	}

	// Adaptive snapshot interval.
	public static class tagItsAdaptSnapIntervalType extends Structure {
		public WinDef.ULONG uiLowSpeedMax; // Maximum snapshot interval in low speed scenarios.

		public WinDef.ULONG uiMidSpeedMax; // Maximum snapshot interval in medium speed scenarios.
		public int[] aiAdaptLowSpeedInterval = new int[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX]; // Continuous snapshot interval
																							// in low speed scenarios,
																							// in milliseconds.
		public int[] aiAdaptMidSpeedInterval = new int[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX]; // Continuous snapshot interval
																							// in medium speed
																							// scenarios, in
																							// milliseconds.
		public int[] aiAdaptHighSpeedInterval = new int[ITS_ADAPT_SNAP_INTERVAL_NUM_MAX]; // Continuous snapshot
																							// interval in high speed
																							// scenarios, in
																							// milliseconds.

		public tagItsAdaptSnapIntervalType() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("uiLowSpeedMax", "uiMidSpeedMax", "aiAdaptLowSpeedInterval", "aiAdaptMidSpeedInterval",
					"aiAdaptHighSpeedInterval");
		}
	}

	// Enable or disable the ePolice detection line.
	public static class tagItsEPoliceDtLineEnable extends Structure {
		public BOOL[] abRoadLane = new BOOL[MAX_LANE_NUM]; // Indicates whether to enable the lane line.
		public BOOL[] abStopLine = new BOOL[MAX_LANE_NUM]; // Indicates whether to enable the stop line.
		public BOOL[] abTripLine = new BOOL[MAX_LANE_NUM]; // Indicates whether to enable the tripwire.
		public BOOL bLaneRhtBorderLine; // Right lane boundary.
		public BOOL bLftBorderLine; // Left-turn boundary.
		public BOOL bRhtBorderLine; // Right-turn boundary.
		public BOOL bStrightTrigger; // Straight-through trigger line.
		public BOOL bRunningRedTrigger; // Red-light-running trigger line.
		public BOOL bTurnAroundLine; // U-turn detection line.
		public BOOL bPosBox; // Locating frame.

		public tagItsEPoliceDtLineEnable() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("abRoadLane", "abStopLine", "abTripLine", "bLaneRhtBorderLine", "bLftBorderLine",
					"bRhtBorderLine", "bStrightTrigger", "bRunningRedTrigger", "bTurnAroundLine", "bPosBox");
		}
	}

	// ePolice detection line parameter.
	public static class tagItsEPoliceDtLineParam extends Structure {
		public tagItsEPoliceDtLineEnable stEnableList; // Lane line enabling list.
		public int iLaneNum; // Number of lane lines.
		public ROAD_PROPERTY_UNIT_S[] stLane = (ROAD_PROPERTY_UNIT_S[]) new ROAD_PROPERTY_UNIT_S()
				.toArray(MAX_LANE_NUM); // Number of lane lines = Number of lanes + 1
		public ROAD_PROPERTY_UNIT_S stLaneRhtBorderLine; // Right lane boundary.
		public int iStopNum; // Number of stop lines.
		public PU_IMRS_LINE[] stStopLine = (PU_IMRS_LINE[]) new PU_IMRS_LINE().toArray(MAX_LANE_NUM); // Stop line.
		public PU_IMRS_LINE[] stTripLine = (PU_IMRS_LINE[]) new PU_IMRS_LINE().toArray(MAX_LANE_NUM); // Detection line
																										// (virtual
																										// tripwire),
																										// across which
																										// snapshots are
																										// taken in
																										// checkpoint
																										// mode.
		public PU_IMRS_LINE stLftBorderLine; // Left-turn boundary.
		public PU_IMRS_LINE stRhtBorderLine; // Right-turn boundary.
		public PU_IMRS_LINE stStrightTrigger; // Straight-through trigger line.
		public PU_IMRS_LINE stRunningRedTrigger; // Red-light-running trigger line.
		public PU_IMRS_LINE stTurnAroundLine; // U-turn detection line.
		// C type : PU_ITS_POS_BOX_TYPE_E
		public int enPosBoxType; // Locating frame.
		public AERADTC_LIST stVLPRAreaList; // Best license plate recognition area.
		public AERADTC_LIST stIllegalParkAreaList; // Yellow zone.
		public AERADTC_LIST stImpolitePedestriansAreaList; // Pedestrian surveillance area.
		public byte[] aucLocalPlate = new byte[MAX_RESTRICTED_LOCALPLATE_LEN]; // Priority province (city).

		public tagItsEPoliceDtLineParam() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("stEnableList", "iLaneNum", "stLane", "stLaneRhtBorderLine", "iStopNum", "stStopLine",
					"stTripLine", "stLftBorderLine", "stRhtBorderLine", "stStrightTrigger", "stRunningRedTrigger",
					"stTurnAroundLine", "enPosBoxType", "stVLPRAreaList", "stIllegalParkAreaList",
					"stImpolitePedestriansAreaList", "aucLocalPlate");
		}
	}

	// Snapshot type in ePolice mode.
	public static class tagItsEPoliceSnapType extends Structure {
		public ULONG ulChannelId; // Channel ID.
		// C type : EN_ITS_TYPE
		public int enITSType; // ITS service type.
		// c Type : EN_ITS_REGULA_DT_TYPE
		public int enRegulaDtType; // Violation detection mode.
		public int[] aiMultiSnapInterval = new int[ITS_SNAP_NUM_MAX]; // Continuous snapshot interval, in milliseconds.

		/*
		 * ePolice:1: checkpoint; 3: speeding; 4: low-speed; 6: wrong-way driving; 7:
		 * end-number policy violation; 8: marked lanes violation; 9: unsafe lane
		 * change; 10: motor vehicles on non-motor vehicle lanes 21: parking in yellow
		 * zones; 22: failure to give right-of-way to pedestrians; 23: bus lane
		 * violation; 24: driving large vehicles on prohibited lanes;
		 *
		 * Checkpoint: 1: checkpoint; 3: speeding; 4: low-speed; 6: wrong-way driving;
		 * 7: end-number policy violation; 8: marked lanes violation; 9: unsafe lane
		 * change; 10: motor vehicles on non-motor vehicle lanes; 18: hands-free device
		 * infraction; * 19: Seat belt infraction; 21: parking in yellow zones; 22:
		 * failure to give right-of-way pedestrians; 23: bus lane violation; 24: driving
		 * large vehicles on prohibited lanes;
		 *
		 */
		public int iRegulationNum; // Number of violation snapshots (ePolice: 14; checkpoint: 15).
		public tagRegulationSnapConfigUnit[] astRegulationSnapCfgU = (tagRegulationSnapConfigUnit[]) new tagRegulationSnapConfigUnit()
				.toArray(ITS_REGULATION_TYPE_NUM_MAX); // Violation snapshot type.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public tagItsEPoliceSnapType() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enITSType", "enRegulaDtType", "aiMultiSnapInterval", "iRegulationNum",
					"astRegulationSnapCfgU", "szReserve");
		}
	}// PU_ITS_SNAP_TYPE_PARAM_S, PU_ITS_EPOLICE_SNAP_TYPE_PARAM_S,
		// PU_ITS_TGATEWAY_SNAP_TYPE_PARAM_S;

	// Extended ePolice snapshot types.
	public static class tagItsEPoliceSnapType_V2 extends Structure {
		public WinDef.ULONG ulChannelId; // Channel ID.

		public int enITSType; // ITS业务类型 EN_ITS_TYPE
		public int enRegulaDtType; // 违章类型检测方式 EN_ITS_REGULA_DT_TYPE
		public int[] aiMultiSnapInterval = new int[ITS_SNAP_NUM_MAX]; // Continuous snapshot interval, in milliseconds.
		/*
		 * ePolice:1: checkpoint; 3: speeding; 4: low-speed; 6: wrong-way driving; 7:
		 * end-number policy violation; 8: marked lanes violation; 9: unsafe lane
		 * change; 10: motor vehicles on non-motor vehicle lanes 21: parking in yellow
		 * zones; 22: failure to give right-of-way to pedestrians; 23: bus lane
		 * violation; 24: driving large vehicles on prohibited lanes;
		 *
		 * Checkpoint: 1: checkpoint; 3: speeding; 4: low-speed; 6: wrong-way driving;
		 * 7: end-number policy violation; 8: marked lanes violation; 9: unsafe lane
		 * change; 10: motor vehicles on non-motor vehicle lanes; 18: hands-free device
		 * infraction; * 19: Seat belt infraction; 21: parking in yellow zones; 22:
		 * failure to give right-of-way pedestrians; 23: bus lane violation; 24: driving
		 * large vehicles on prohibited lanes;
		 *
		 */
		public int iRegulationNum; // Number of violation snapshots (ePolice: 14; checkpoint: 15).

		public tagRegulationSnapConfigUnit[] astRegulationSnapCfgU = (tagRegulationSnapConfigUnit[]) new tagRegulationSnapConfigUnit()
				.toArray(ITS_REGULATION_TYPE_NUM_MAX); // Violation snapshot type.
		public int enITSSnapIntervalType; // Snapshot interval type. c type:PU_ITS_SNAP_INTERVAL_TYPE

		public tagItsAdaptSnapIntervalType stAdaptSnapInterval; // Adaptive snapshot interval.
		public int enRegulaSnapType; // Violation snapshot mode (single-shutter or dual-shutter).c
										// type:PU_ITS_REGULA_SNAP_TYPE
		public byte[] szReserve = new byte[PU_RESERVE_EX_LEN - 4];/* PU_ITS_REGULA_SNAP_TYPE */

		public tagItsEPoliceSnapType_V2() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "enITSType", "enRegulaDtType", "aiMultiSnapInterval", "iRegulationNum",
					"astRegulationSnapCfgU", "enITSSnapIntervalType", "stAdaptSnapInterval", "enRegulaSnapType",
					"szReserve");
		}
	}

	public class tagITSRegulationCfgAttch extends Union {
		/**
		 * Running-red-light snapshot parameter (ITS_REGULA_RUNNINGRED), which is a
		 * reserved field.<br>
		 */
		public tagITSRunLightPara stRunningRed;
		/**
		 * Marked lanes violation (ITS_REGULA_OVER_LANE_LINE).<br>
		 */
		public tagITSRegulationCfgAttchPressLine stPressLine;
		/**
		 * Motor vehicles driving on non-motor vehicle lanes
		 * (ITS_REGULA_MOTOR_IN_BICYCLE_LANE).<br>
		 */
		public tagITSRegulationCfgAttchInvadeDriverWay stInvadeDriverWay;
		/**
		 * Bus lane violation (ITS_REGULA_OCCUPANCY_BUSLANE).<br>
		 */
		public tagITSRegulationCfgAttchInvadeDriverWay stInvadeBusLane;
		/**
		 * Parking in yellow zones (ITS_REGULA_ILLEGAL_PARKING).<br>
		 */
		public tagITSRegulationCfgAttchInvadeDriverWay stIllegalParkTime;
		/**
		 * Pedestrian waiting time.<br>
		 */
		public tagITSRegulationCfgAttchInvadeDriverWay stImpolitePedestriansTime;

		public tagITSRegulationCfgAttch() {
			super();
		}

		public tagITSRegulationCfgAttch(Pointer peer) {
			super(peer);
		}

		/**
		 * @param stInvadeDriverWay_or_stInvadeBusLane_or_stIllegalParkTime_or_stImpolitePedestriansTime Motor
		 *                                                                                               vehicles
		 *                                                                                               driving
		 *                                                                                               on
		 *                                                                                               non-motor
		 *                                                                                               vehicle
		 *                                                                                               lanes
		 *                                                                                               (ITS_REGULA_MOTOR_IN_BICYCLE_LANE).
		 *                                                                                               C
		 *                                                                                               type
		 *                                                                                               :
		 *                                                                                               PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S,
		 *                                                                                               or
		 *                                                                                               Bus
		 *                                                                                               lane
		 *                                                                                               violation
		 *                                                                                               (ITS_REGULA_OCCUPANCY_BUSLANE).
		 *                                                                                               C
		 *                                                                                               type
		 *                                                                                               :
		 *                                                                                               PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S,
		 *                                                                                               or
		 *                                                                                               Parking
		 *                                                                                               in
		 *                                                                                               yellow
		 *                                                                                               zones
		 *                                                                                               (ITS_REGULA_ILLEGAL_PARKING).
		 *                                                                                               C
		 *                                                                                               type
		 *                                                                                               :
		 *                                                                                               PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S,
		 *                                                                                               or
		 *                                                                                               Pedestrian
		 *                                                                                               waiting
		 *                                                                                               time.
		 *                                                                                               C
		 *                                                                                               type
		 *                                                                                               :
		 *                                                                                               PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S
		 */
		public tagITSRegulationCfgAttch(
				tagITSRegulationCfgAttchInvadeDriverWay stInvadeDriverWay_or_stInvadeBusLane_or_stIllegalParkTime_or_stImpolitePedestriansTime) {
			super();
			this.stImpolitePedestriansTime = this.stIllegalParkTime = this.stInvadeBusLane = this.stInvadeDriverWay = stInvadeDriverWay_or_stInvadeBusLane_or_stIllegalParkTime_or_stImpolitePedestriansTime;
			setType(tagITSRegulationCfgAttchInvadeDriverWay.class);
		}

		/**
		 * @param stPressLine Marked lanes violation (ITS_REGULA_OVER_LANE_LINE). C type
		 *                    : PU_ITS_REGULATION_CFG_ATTCH_PRESS_LINE_UNIT_S
		 */
		public tagITSRegulationCfgAttch(tagITSRegulationCfgAttchPressLine stPressLine) {
			super();
			this.stPressLine = stPressLine;
			setType(tagITSRegulationCfgAttchPressLine.class);
		}

		/**
		 * @param stRunningRed Running-red-light snapshot parameter
		 *                     (ITS_REGULA_RUNNINGRED), which is a reserved field. C
		 *                     type : PU_ITS_RUNLIGHT_PARA_S
		 */
		public tagITSRegulationCfgAttch(tagITSRunLightPara stRunningRed) {
			super();
			this.stRunningRed = stRunningRed;
			setType(tagITSRunLightPara.class);
		}
	}

	// Additional parameters for snapshots of motor vehicles driving on non-motor
	// vehicle lanes.
	public static class tagITSRegulationCfgAttchInvadeDriverWay extends Structure {
		public int nStayTime; // 停留时间（0~180ms）
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public tagITSRegulationCfgAttchInvadeDriverWay() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("nStayTime", "szReserve");
		}
	} // PU_ITS_REGULATION_CFG_ATTCH_INVADE_DRIVERWAY_UNIT_S;

	// Additional parameters for marked lanes violation snapshots.
	public static class tagITSRegulationCfgAttchPressLine extends Structure {
		public int nSensitivity; // Marked lanes violation detection sensitivity (0-100 ms).
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public tagITSRegulationCfgAttchPressLine() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("nSensitivity", "szReserve");
		}
	}

	// Traffic light violation parameters.
	public static class tagITSRunLightPara extends Structure {
		/**
		 * Priority.<br>
		 * C type : PU_ITS_RUNLIGHT_PRIORITY_E
		 */
		public int enRunLightPriority;
		/**
		 * Violation rule.<br>
		 * C type : PU_ITS_RUNLIGHT_RULE_E
		 */
		public int enRunLightRule;
		/**
		 * Offset for the second snapshot.
		 */
		public int iSecondSnapOffset;
		/**
		 * Minimum image offset.
		 */
		public int iPicMinOffset;
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public tagITSRunLightPara() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enRunLightPriority", "enRunLightRule", "iSecondSnapOffset", "iPicMinOffset",
					"szReserve");
		}
	}

	// Violation snapshot parameter unit.
	public static class tagRegulationSnapConfigUnit extends Structure {
		public int enRegulationType; // Snapshot type. c type:PU_ITS_REGULA_TYPE_E

		public WinDef.BOOL bEnable; // Indicates whether to enable snapshot taking.
		public int iSnapNum; // Number of snapshots.
		public PU_ITS_REGULATION_CFG_ATTCH_UNIT_S uniAttach = new PU_ITS_REGULATION_CFG_ATTCH_UNIT_S(); // Additional
																										// information.
		public byte[] szReserve = new byte[PU_RESERVE_LEN];

		public tagRegulationSnapConfigUnit() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enRegulationType", "bEnable", "iSnapNum", "uniAttach", "szReserve");
		}

		@Override
		public void read() {
			super.read();
			switch (enRegulationType) {
			/*
			 * case 0:{ uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
			 * uniAttach.read(); } break;
			 */
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_OVER_LANE_LINE: {
				uniAttach.setType(uniAttach.stPressLine.getClass());
				uniAttach.read();
			}
				break;
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_MOTOR_IN_BICYCLE_LANE: {
				uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
				uniAttach.read();
			}
				break;
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_OCCUPANCY_BUSLANE: {
				uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
//                    uniAttach.setType(uniAttach.stInvadeBusLane.getClass());
				uniAttach.read();
			}
				break;
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_ILLEGAL_PARKING: {
				uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
//                    uniAttach.setType(uniAttach.stIllegalParkTime.getClass());
				uniAttach.read();
			}
				break;
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_IMPOLITE_PEDESTRIANS: {
				uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
//                    uniAttach.setType(uniAttach.stInvadeBusLane.getClass());
				uniAttach.read();
			}
				break;
			default:
				break;
			}
		}

		@Override
		public void write() {
			super.write();
			switch (enRegulationType) {
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_OVER_LANE_LINE: {
				uniAttach.setType(uniAttach.stPressLine.getClass());
				uniAttach.write();
			}
				break;
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_MOTOR_IN_BICYCLE_LANE: {
				uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
				uniAttach.write();
			}
				break;
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_OCCUPANCY_BUSLANE: {
				uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
//                    uniAttach.setType(uniAttach.stInvadeBusLane.getClass());
				uniAttach.write();
			}
				break;
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_ILLEGAL_PARKING: {
				uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
//                    uniAttach.setType(uniAttach.stIllegalParkTime.getClass());
				uniAttach.write();
			}
				break;
			case PU_ITS_REGULA_TYPE_E.ITS_REGULA_IMPOLITE_PEDESTRIANS: {
				uniAttach.setType(uniAttach.stInvadeDriverWay.getClass());
//                    uniAttach.setType(uniAttach.stImpolitePedestriansTime.getClass());
				uniAttach.write();
			}
				break;
			default:
				break;
			}
		}
	}

	;

	public static class tagRoadPropertyUnit extends Structure {
		/**
		 * Lane direction in video (leaving or approaching). C type :
		 * PU_ITS_CAR_DRV_DIR_E
		 */
		public int enLaneDirection;
		/**
		 * Vehicle direction (turn-left, turn-right, or straight-through). C type :
		 * PU_ITS_ROAD_DRV_DIR_E
		 */
		public int enSignDirection;
		/**
		 * Lane line type. C type : ITS_ROAD_LINE_TYPE_E
		 */
		public int enLineType;
		/**
		 * Lane scene type, which is used to determine whether an illegal U-turn occurs.
		 * C type : ITS_ROAD_SIDE_SCENE_E
		 */
		public int enLaneSideScene;
		/**
		 * Lane line. C type : PU_IMRS_LINE_S
		 */
		public PU_IMRS_LINE stLine;

		public tagRoadPropertyUnit() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("enLaneDirection", "enSignDirection", "enLineType", "enLaneSideScene", "stLine");
		}
	}

	;

	// Manual parking violation detection parameters of traffic PTZ dome cameras.
	public static class tagTRAFFIC_DOME_MANUAL_DETECTION_PARAMS_S extends Structure {
		public ULONG ulChannelId; // Channel ID.
		public PU_TD_TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS stIllegalParking;

		public tagTRAFFIC_DOME_MANUAL_DETECTION_PARAMS_S() {
			this.setAlignType(ALIGN_NONE);
		}

		@Override
		protected List<String> getFieldOrder() {
			return Arrays.asList("ulChannelId", "stIllegalParking");
		}
	}

	public static class unMetaData extends Union {
		public WinDef.BOOL bBoolValue;

		public String charValue;
		public String ucharValue;
		public WinDef.SHORT shortValue;
		public WinDef.USHORT ushortValue;
		public int IntValue;
		public UINT uIntValue;
		public long longlongValue;
		public WinDef.ULONGLONG uLonglongValue;
		public ST_BINARY stBinay;
		public META_RECT_S stRec;
		public META_POINT_S stPoint;
		public META_LINE_S stLine;
		public META_POLYGON_S stPolyGon;
		public META_COLOR_S stColor;
		public META_HUMAN_ATTRIBUTES_S stHuamanAttr;
		public META_FACE_ATTRIBUTES_S stFaceAttr;
		public META_FACE_INFO_S stFaceInfo;
		public byte[] szUserData = new byte[1];

		public unMetaData() {
			this.setAlignType(ALIGN_NONE);
		}
	}

	/* Image mirroring and flip mode. */
	public interface VIDEO_VENC_ROTATION_E {
		int VIDEO_ROTATION_NORMAL = 0; // Normal.
		int VIDEO_ROTATION_MIRROR = 1; // Left and right mirroring.
		int VIDEO_ROTATION_FILP = 2; // Up and down mirroring.
		int VIDEO_ROTATION_BOTH = 3; // Up/down and left/right mirroring.
		int VIDEO_ROTATION_MAX = 4;
	}

	public interface WIRELESS_NET_MODE_E {
		int WL_NET_TYPE_AUTO = 0;
		int WL_NET_TYPE_4G = 1;
		int WL_NET_TYPE_3G = 2;
		int WL_NET_TYPE_MAX = 3;
	}

	HWPuSDK SSL_INSTANCE = Native.load((Platform.isWindows() ? "lib\\HWPuSDK" : "ssl"), HWPuSDK.class);

	;

	HWPuSDK INSTANCE = Native.load((Platform.isWindows() ? "lib\\HWPuSDK" : "hwpusdk"), HWPuSDK.class);

	public static final int CHANNEL_ID = 101;

	/********************************
	 * Macro Definition
	 **********************************************/
	public static final int PU_RESERVE_LEN = 32;

	public static final int PU_RESERVE_EX_LEN = 256;

	public static final int PU_VERSION_LEN = 32;

	public static final int PU_DEVICE_NAME_LEN = 32;

	public static final int PU_FAC_NAME_LEN = 12;

	public static final int PU_DEVICE_TYPE_LEN = 32;

	public static final int PU_SERIAL_LEN = 32;

	public static final int PU_ESN_INFO_LEN = 32;

	public static final int PU_IP4_ADDR_LEN = 16;

	public static final int PU_MULTICAST_ADDR_LEN = 32;

	public static final int PU_IP6_ADDR_LEN = 40;

	public static final int PU_HEX_MAC_ADDR_LEN = 18;

	public static final int PU_PLATFORM_INFO_LEN = 32;

	public static final int PU_PTZ_NAME_LEN = 32;

	public static final int PU_PTZ_CRUISE_LEN = 32;

	public static final int PU_PTZ_CRUISE_POINT_MAX = 32;

	public static final int PU_PTZ_PRESET_NUM = 10;

	public static final int PU_PTZ_GEAR_NUM_MAX = 10;

	public static final int PU_PRIVACY_MASK_MAX = 10;

	public static final int PU_ALARM_TIME_MAX = 8;

	public static final int PU_ALARM_AREA_MAX = 16;

	public static final int PU_CRUISE_DWELL_MIN = 3;

	public static final int PU_CRUISE_DWELL_MAX = 3600;

	public static final int PU_CRUISE_SPEED_MIN = 1;

	public static final int PU_CRUISE_SPEED_MAX = 10;

	public static final int PU_TIME_YEAR_LEN = 5;

	public static final int PU_TIME_OTHERS_LEN = 3;

	public static final int PU_TIME_TOTAL_LEN = 32;

	public static final int PU_UPGRADE_FILE_NUM_MAX = 16;

	public static final int PU_UPGRADE_FILE_LEN_MAX = 300;

	public static final int PU_INVADE_LINE_NUM_MAX = 5;

	public static final int PU_SAVE_FILE_PATH_MAX = 128;

	public static final int PU_ALARM_CAMERA_MAX = 4;

	public static final int PU_ALARM_DO_MAX = 4;

	public static final int PU_USER_NAME_LEN = 32;

	public static final int PU_PASSWORD_LEN = (64 + 4);

	public static final int PU_CLIENT_USERNAME_LEN = (32 + 4);

	public static final int PU_FTP_UPLOAD_PATH_LEN = (128 + 4);

	public static final int PU_CAMERA_NUM_MAX = 4;

	public static final int PU_TRIPWIRE_LEN_NUM_MAX = 5;

	public static final int PU_IGT_AREA_POINTS_NUM = 10;

	public static final int PU_IGT_AREA_NUM = 4;

	public static final int PU_IGT_LINE_NAME_LEN = (32 + 4);

	public static final int PU_IGT_AREA_NAME_LEN = (32 + 4);

	public static final int PU_DEVICE_NUM_MAX = 1000;

	public static final int PU_DEVICE_LOGIN_NUM_MAX = 20000;

	public static final int PU_TRANSPARENT_CMD_MAX = 256;

	public static final int PU_DOMAIN_LEN = 256;

	public static final int PU_IRLIGHT_NUM_MAX = 4;

	public static final int PU_DIO_NAME_LEN = (32 + 4);

	public static final int PU_DIO_NUM_MAX = 8;

	public static final int PU_RECORD_PLAN_NUM = 28;

	public static final int PU_RECORD_PLAN_NUM_SD = 24;

	public static final int MAX_RECORD_CONTENTID_LEN = 64;

	public static final int PU_LOG_INFO_LEN = 256;

	public static final int PU_LOG_INFO_NUM = 100;

	public static final int PU_NAT_SESSIONID_LEN = 32;

	public static final int PU_NAT_URL_LEN = 256;

	public static final int PU_RECORD_TYPE_NUM = 4;

	public static final int PU_RECORD_INFO_NUM_MAX = 5;

	public static final int PU_RECORD_CONTENTID_LEN = 40;

	public static final int PU_VIDEO_FORMAT_NUM = 4;

	public static final int PU_STREAM_NUM = 4;

	public static final int PU_STREAM_NUM_V2 = 5;

	public static final int PU_OSD_STRING_LEN = (96 + 4);

	public static final int PU_OSD_STRING_NUM = 7;

	public static final int PU_OSD_STRING_EX_NUM = 10;

	public static final int PU_MAC_ADDR_LEN = 30;

	public static final int PU_SNAP_IMAGE_NAME_LEN = 24;

	public static final int PU_MAX_URL_LEN = 512;

	public static final int PU_CONFIG_FILE_PATH_MAX = 512;

	public static final int PU_CONFIG_LOAD_UP_KEY_LEN = (32 + 1);

	public static final int PU_SNAPSHOT_PIC_PATH_LEN = 512;

	public static final int PU_DEVICE_USER_NUM_MAX = 10;

	public static final int PU_CERT_FILE_PATH_MAX = 512;

	public static final int PU_TYPICAL_SCENE_NUM_MAX = 12;

	public static final int PU_TYPICAL_SCENE_NUM_MAX_EX = 15;

	public static final int PU_TYPICAL_SCENE_NAME_LEN = (64 + 4);

	public static final int PU_TYPICAL_SCENE_DESCRIBE_LEN = 128;

	public static final int PU_PLAN_NUM_MAX = 8;

	public static final int PU_MONTH_NUM = 12;

	public static final int FAC_NAME_LEN_MAX = 12;

//===Begin: Scene application parameters of traffic PTZ dome cameras ===
//Application parameters of traffic PTZ dome cameras (parking violation detection).
// TRAFFIC_DOME_ILLEGAL_PARKINK_PARAMS_S

	public static final int STREAM_PROFILES_MAX = 8;

	public static final int STREAMPROFILES_NAME_LEN = (64 + 4);

	public static final int PRIVACY_AREA_POINTS_NUM = 4;

	public static final int VW_ZONE_ROW = 15;

	public static final int VW_ZONE_COLUMN = 17;

	public static final int ISP_PARA_NUM = 22;

	public static final int ETH_RECV_RATE_MAX = 16000;

	public static final int ETH_RECV_RATE_MIN = 2000;

	public static final int PU_ENC_STREAM_MAX_NUM = 3;

	public static final int PU_ENC_STREAM_MAX_NUM_V2 = 5;

	public static final int PU_FOCUSREGION_NUM_MAX = 256;

	public static final int PU_FOCUSAREA_ROW = 15;

	public static final int PU_FOCUSAREA_COL = 17;

	public static final int VW_VIM_MAX_AREA_POINTS_NUM = 10;

	public static final int GATHER_AREA_NAME_LEN = 32;

	public static final int MAX_AREA_NUM = 4;

	public static final int MAX_BURST_SHOOTING_NUM = 5;

	public static final int MAX_LANE_NUM = 4;

	public static final int TDOME_MAX_LANE_NUM = 6;

	public static final int MAX_AREA_VERTEX = (MAX_LANE_NUM + 1);

	public static final int MAX_PLATE_LOCAL_ZH_LEN = 24;

	public static final int CAM_POSITION_STR_LEN = 15;

	public static final int MAX_SUPPLEMENT_LIGHT_LAMP_NUM = 8;

	public static final int FD_AREA_NUM = 16;

	public static final int FD_AREA_POINT_NUM = 12;

	public static final int FD_AREA_NAME_LEN = 36;

	public static final int PU_SNAPSHOT_INQUIRE_NUM = 10;

	public static final int PU_SNAPSHOT_PICTURE_NAME_LEN = 64;

	public static final int PU_VLPR_PIC_OSD_TYPE_MAX = 15;

	public static final int PU_VLPR_PIC_OSD_TYPE_MAX_EX = 50;

	public static final int PU_MEDIA_ENC_AES_KEY_STR_LEN = 65;

	public static final int PU_MEDIA_ENC_AES_CBC_IV_LEN = 17;

	public static final int MAX_ITS_SNAPSHOT_INTERVAL = 60000;

	public static final int MIN_ITS_SNAPSHOT_INTERVAL = 67;

	/********* SNMP *********/
	public static final int PU_SNMPV3_USER_NUM = 3;

	public static final int PU_SNMP_COMMUNITY_NUM = 3;

	public static final int PU_SNMP_COMMUNITY_NAME_LEN = (16 + 1);

	public static final int PU_SNMP_COMMUNITY_NAME_LEN_EX = (32 + 1);

	public static final int PU_SNMP_TRAP_NUM = 3;

	public static final int PU_SNMP_ENGINEID_LEN = (32 + 1);

	public static final int PU_SNMP_CONTEXT_NAME_LEN = (16 + 1);

	public static final int PU_ROI_AREA_NUM_MAX = 8;

	public static final int PU_PORT_MODE_NUM_MAX = 16;

	public static final int PU_BNC_PORT_MAX = 32;

	public static final int PU_VGA_PORT_MAX = 8;

	public static final int PU_DVI_PORT_MAX = 8;

	public static final int PU_HDMI_PORT_MAX = 8;

	public static final int PU_DECODE_TYPE_MAX = 4;

	public static final int PU_PORT_NUM_MAX = 32;

	public static final int PU_CHANNEL_NUM_MAX = 32;

	public static final int PU_OSD_MAX_LENGTH = (96 + 1);

	public static final int PU_OSD_MAX_LENGTH_EX = (176 + 1);

	public static final int PU_CRYPTION_PASSWD_LEN = 44;

	public static final int PU_DEC_CHANNEL_NAME_LEN = 32;

	public static final int PU_DECODER_ID_LEN = 20;

	public static final int PU_DECODER_NAME_LEN = 32;

	public static final int PU_DEC_PAY_LOAD_TYPE_NUM = 16;

	public static final int PU_DECODER_ENCODING_LEN = 16;

	public static final int PU_CERT_FIELD_NAME_LEN_MAX = (128 + 4);

	public static final int PU_IP_FILTER_NUM_MAX = 3;

	public static final int PU_IP_FILTER_NUM_MAXV2 = 48;

	public static final int PU_IP_FILTER_NUM_MAXV3 = 100;

	public static final int PU_DDNS_MAX_LEN = 256;

	public static final int OSDI_AREA_NUM_MAX = 8;

	public static final int PU_H264DEC_OK = 0;

	public static final int PU_H264DEC_NEED_MORE_BITS = -1;

	public static final int PU_H264DEC_NO_PICTURE = -2;

	public static final int PU_H264DEC_ERR_HANDLE = -3;

	;

	/******* SMTP ********/
	public static final int PU_SMTP_NAME_LEN_MAX = (32 + 4);

	public static final int PU_SMTP_MAIL_LEN = 128;

	public static final int PU_SMTP_RECV_MAX_NUM = 3;

	public static final int PU_IRCUT_MODE_MAX_NUM = 3;

	public static final int PU_HUMANCOUNT_TABLE_LEN_MAX = 32;

	public static final int PU_MAX_CUSTOM_CONTENT_LEN = 24;

	public static final int PU_MAX_DIR_NAMING_ELEM = 4;

	;

	public static final int PU_MAX_PIC_NAMING_ELEM = 20;

	public static final int PU_MAX_PIC_NAMING_ELEM_EX = 90;

	public static final int PU_ITS_MAX_ROAD_NUM = 5;

	public static final int PU_MAX_EXT_LAMP_NUM = 8;

	public static final int PU_MAX_INNER_LAMP_NUM = 3;

	public static final int PU_LIC_SERVICE_AGE_MAX_LEN = 256;

	public static final int PU_LIC_REVOKE_KEY_LEN = 136;

	public static final int PU_LIC_DATE_MAX_LEN = 72;

	public static final int PU_3RD_APP_MAX_NUM = 16;

	public static final int PU_ITGT_TYPE_MAX_NUM = 16;

	public static final int PU_ITGT_TYPE_MAX_EX_NUM = 64;

	public static final int PU_ITGT_ALTHM_VERSION_LEN = 48;

	public static final int PU_ITGT_ALTHM_VENDOR_LEN = 48;

	public static final int PU_ISP_TYPE_MAX_NUM = 64;

	public static final int PU_IMPORT_FILE_LEN_MAX = 256;

	public static final int PU_IMPORT_FILENAME_LEN_MAX = 128;

	public static final int PU_SNAP_NUM_MAX = 3;

	public static final int PU_SNAP_NUM_MAX2 = 4;

	public static final int PU_RL_NUM_MAX = 4;

	public static final int PU_ITS_MAX_LIGHTAREA_NUM = 4;

	public static final int PU_ITS_ILLEGAL_TYPE_NUM_MAX = 96;

	public static final int PU_ITS_ILLEGAL_TYPE_LEN_MAX = (64 + 4);

	public static final int PU_ITS_ILLEGAL_NUM_LEN_MAX = (8 + 1);

	public static final int PU_ITS_ILLEGAL_NAME_LEN_MAX = (64 + 4);

	public static final int PU_MIN_GPS_SYNC_INTERVAL = 5 * 60;

	public static final int PU_MAX_GPS_SYNC_INTERVAL = (1000 * 60);

	public static final int TD_MAX_SNAP_FRAME_NUM = 4;

	public static final int TD_MAX_SCENE_NUM = 16;

	public static final int TD_MAX_DAY_ONE_WEEK = 7;

	public static final int TD_MAX_STRING_LENGTH = (64 + 1);

	public static final int PU_CALIBRATION_POINT_MAX_NUM = 14;

	public static final int PU_MASTER_SLAVE_GROUP_MAX_NUM = 4;

	public static final int PU_MASTER_NUM_MAX = 8;

	public static final int PU_SLAVE_NUM_MAX = 8;

	public static final int PU_1TN_SLAVE_NUM_MAX = 8;

	/******* hot map ********/
	public static final int PU_MONTH_NUM_PER_YEAR = 12;

	public static final int PU_DAY_NUM_PER_MONTH = 31;

	public static final int PU_DAY_NUM_PER_WEEK = 7;

	public static final int PU_HOUR_NUM_PER_DAY = 24;

	public static final int PU_GUARD_PLAN_NUM_PER_DAY = 8;

	public static final int PU_HOTMAP_AREA_NUM = 8;

	public static final int PU_ITGT_AUTOTRACKING_PRIORITY_ITEM_NUM = 3;

	public static final int PU_MAX_RECORD_LEN_16 = 16;

	public static final int PU_MAX_RECORD_LEN_32 = 32;

	public static final int PU_MAX_RECORD_LEN_48 = 48;

	;

	public static final int PU_MAX_RECORD_LEN_64 = 64;

	public static final int PU_MAX_EX_FIELD_LEN = 512;

	public static final int PU_MAX_DELETE_NUM = 100;

	/********* begin:End-Number Policy *********/
	public static final int MAX_RESTRICTED_NUM = 10;

	public static final int MAX_RESTRICTED_EVENT_NUM = 30;

	public static final int MAX_RESTRICTED_DATE_NUM = 10;

	public static final int MAX_RESTRICTED_LOCALPLATE_LEN = 5;

	public static final int MAX_RESTRICTED_LOCALPLATE_NUM = 32;

	public static final int MAX_RESTRICTED_LOCALPLATE_ALL_NUM = 26;

	/************************** Macro Definition Ends ***************************/
	public static final int MAX_POINT_NUM = 10;

	public static final int PU_OPERATE_3RD_APP_NAME_LEN = 32;

	public static final int PU_OPERATE_3RD_APP_PATH_LEN = 64;

	public static final int PU_OPERATE_3RD_APP_CMD_LEN = 128;

	public static final int PU_MANAGE_3RD_APP_NUM_MAX = 1;

	;

	public static final int PU_MANAGE_3RD_APP_URL_MAX = 64;

	public static final int DIAL_APP_LEN_MAX = (32 + 1);

	public static final int DIAL_USR_NAME_LEN_MAX = (32 + 1);

	public static final int DIAL_PASSWD_LEN_MAX = (32 + 1);

	public static final int DIAL_PLAN_AREA_MAX = 8;

	public static final int DIAL_SMS_WHITE_LIST_MAX = 8;

	public static final int DIAL_RC_NUM_LEN_MAX = (4 + 1);

	public static final int DIAL_PHONE_NUM_LEN = 16;

	public static final int IPV4_ADDR_LEN = 16;

	public static final int DAYS_PER_WEEK = 7;

	public static final int DIAL_PLMN_NAME_MAX = 40;

	public static final int ITS_REGULATION_TYPE_NUM_MAX = 32;

	public static final int ITS_SNAP_NUM_MAX = 4;

	public static final int ITS_ADAPT_SNAP_INTERVAL_NUM_MAX = 2;

	public static final int MAX_AREA_POINTS_NUM = 10;

	public static final int IGT_AREA_NAME_LEN = (32 + 4);

	// Add a single face.
	boolean IVS_PU_AddOneFace(ULONG ulIdentifyID, PU_FACE_INFO_ADD_S pstOneFaceInfo);

	// Add a single face and extend the image name field.
	boolean IVS_PU_AddOneFaceV2(ULONG ulIdentifyID, PU_FACE_INFO_ADD_S pstOneFaceInfo, String pcPicname);

	boolean IVS_PU_AddPrivacyMaskArea(ULONG ulIdentifyID, PU_ADD_MASK_PARA pstPrivacyMaskArea);

	// pparam_len C type is UINT *pparam_len
	long IVS_PU_AI_GetOption(ULONG ulIdentifyID, int bussLevel, int bussName, Pointer param, IntByReference pparam_len);

	// Multi-camera collaboration.
	// bussLevel C type is PU_AI_LEVEL_E， bussName c type is PU_AI_NAME_E, param C
	// type is const void*
	long IVS_PU_AI_SetOption(ULONG ulIdentifyID, int bussLevel, int bussName, Pointer param, int param_len);

	/***************************
	 * Alarm Parameters Functions
	 ********************************/
	// register device alarm callback function
	boolean IVS_PU_AlarmInfoStatesCallBack(ULONG ulIdentifyID, pfGetAlarmInfoCallBack fAlarmResportCallBack,
			Pointer pUsrData);

	boolean IVS_PU_AlarmInfoStatesCallBack_V20(ULONG ulIdentifyID, pfGetAlarmInfoCallBack_V20 fAlarmResportCallBack,
			Pointer pUsrData);

	// change destination module admin password
	// enDstModule -> C type:IPC_MODULE
	boolean IVS_PU_ChangeAdminPassword(NativeLong ulIdentifyID, String pszOldPasswd, String pszNewPasswd,
			int enDstModule);

	// change device password
	boolean IVS_PU_ChangeDevicePassword(NativeLong ulIdentifyID, String pszUserName, String pszOldPasswd,
			String pszNewPasswd);

	// Periodically query the status of importing data into the face library and the
	// feature extraction status.
	boolean IVS_PU_CheckImportStatus(ULONG ulIdentifyID, PU_FACE_LIB_STATUS_S pstFaceLibStatus);

	// Check whether IP address conflict occurs.
	boolean IVS_PU_CheckIPConflict(NativeLong ulIdentifyID, PU_DEVICE_ETHERNET_PARA pstDeviceEthernetPara);

	// Verify the image digital watermark.
	boolean IVS_PU_CheckVLPRPicWaterMark(String szFilePath);

	// release sdk resources
	public boolean IVS_PU_Cleanup();

	// clear hot map table
	boolean IVS_PU_ClearHotMapData(ULONG ulIdentifyID, ULONG ulChannelId);

	// SDK General API.
	// enGetOrSet C Type is PU_REQ_TYPE, enServiceType C type is PU_INTERFACE_TYPE_E
	long IVS_PU_CommonOption(ULONG ulIdentifyID, int enGetOrSet, int enServiceType, Pointer pstParam,
			ULONG ulParam_len);

	// Deactivate the license and obtain the revoke code.
	boolean IVS_PU_DeactLicForRevokeKey(ULONG ulIdentifyID, PU_ITGT_LIC_REVOKE_INFO pstLicRevokeInfo);

	// Delete face information.
	boolean IVS_PU_DelFaceInfo(ULONG ulIdentifyID, PU_FACE_INFO_DELETE_S delFaceInfo);

	// delete device guard position
	boolean IVS_PU_DelGuardPosition(ULONG ulIdentifyID);

	boolean IVS_PU_DelPrivacyMaskArea(ULONG ulIdentifyID, PU_DEL_MASK_PARA pstPrivacyMaskArea);

	// delect device record file
	boolean IVS_PU_DelRecordFile(ULONG ulIdentifyID, ULONG ulChannelId, String pszRecordFileName);

	// search device list info by UDP connect
	boolean IVS_PU_DiscoveryDeviceByIpAddresses(String pszStartIpAddr, String pszEndIpAddr, NativeLong ulSearchNum,
			PU_DISCOVER_DEVICE_INFO_S[] pszDeviceList, LongByReference pulDeviceNum);

	// device list info by auto discovery
	boolean IVS_PU_DiscoveryLocalDeviceList(PU_DISCOVER_DEVICE_LIST pstDeviceList);

	// device disk format
	boolean IVS_PU_DiskFormat(ULONG ulIdentifyID);

	// device disk format Ex
	boolean IVS_PU_DiskFormatEx(ULONG ulIdentifyID, PU_HARD_DISK pstDisk);

	boolean IVS_PU_DownloadSnapshotPic(ULONG ulIdentifyID, ULONG ulChnID, String szContentID, String szDownloadPath);

	// EPTZ control
	boolean IVS_PU_EPTZControl(ULONG ulIdentifyID, PU_EPTZ_CTRL pstEPTZCtrl);

	// register sdk event callback
	public boolean IVS_PU_EventStatesCallBack(pfGetEventInfoCallBack fEventResportCallBack);

	// Modify face information.
	boolean IVS_PU_FaceInfoModify(ULONG ulIdentifyID, PU_FACE_INFO_MODIFY_S modifyFaceInfo);

	boolean IVS_PU_FeatureExtract(ULONG ulIdentifyID, PU_FACE_FEATURE_EXTRACT_S pstExtractStatus);

	// Feed voice data for voice talk back and broadcast
	boolean IVS_PU_FeedVoiceData(ULONG ulIdentifyID, ULONG ulVBHandle, String pSendBuf, ULONG ulBufSize, ULONG ulType);

	// Search for face images.
	boolean IVS_PU_FindFaceInfo(ULONG ulIdentifyID, PU_FACE_INFO_FIND_S pstFindFaceInfo);

	public boolean IVS_PU_Get1TNEnable(WinDef.ULONG ulIdentifyID, PU_1TN_ENABLE_S pstPara);

	public boolean IVS_PU_Get1TNSpptMode(WinDef.ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_SWITCH_S pstPara); // ------------->Num.98

	// Obtain the list of 1+N modes and current 1+N mode.
	public boolean IVS_PU_Get1TNSpptModeList(WinDef.ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_LIST_S pstParaList);

	// Add 3559 facial attribute recognition.
	boolean IVS_PU_Get3559FaceAttribute(ULONG ulIdentifyID, PU_ATTRI_DL_PARAMETER_S pstFaceAttribute);

	// Obtain the third-party algorithm information.
	boolean IVS_PU_Get3RdAppAlthmInfo(ULONG ulIdentifyID, PU_MANAGE_3RD_APP_INFO pst3RdAppManageInfo);

	// device 802.1x protocol params
	boolean IVS_PU_Get802Dot1xConfig(ULONG ulIdentifyID, PU_DOT1X_CONFIG_INFO pstDot1xInfo);

	// device AE metering mode
	// enAEMeteringMode -> c type:PU_VIDEO_AEMETERING_MODE
	boolean IVS_PU_GetAEMeteringMode(ULONG ulIdentifyID, ULONG ulChannelId, IntByReference penAEMeteringMode);

	boolean IVS_PU_GetAiVqeStatus(ULONG ulIdentifyID, WinDef.BOOLByReference pbAiVqeStatus);

	// device alarm linkage para with alarm type
	// enAlarmType type : PU_ALARM_TYPE
	boolean IVS_PU_GetAlarmLinkagePara(ULONG ulIdentifyID, int enAlarmType, ULONG ulAlarmId,
			PU_ALARM_LINKAGE_PARA pstAlarmLinkagePara);

	// Obtain the alarm linkage priority.
	boolean IVS_PU_GetAlarmLinkPriority(ULONG ulIdentifyID, PU_ALARM_LINK_PRIORITY_PARA pstAlarmLinkPriority);

	boolean IVS_PU_GetAlarmPara(ULONG ulIdentifyID, int enAlarmType, Pointer arg);

	boolean IVS_PU_GetAlarmRecInfoList(ULONG ulIdentifyID, PU_ALARM_REC_INQ_REQ pstAlarmRecInqReq,
			PU_ALARM_REC_INQ_RSP pstAlarmRecInqRsp);

	// area crop parameter
	boolean IVS_PU_GetAreaCropPara(ULONG ulIdentifyID, AREA_CROP_PARA pstAreaCropPara);

	// device audio stream infos
	boolean IVS_PU_GetAudioStreamInfo(ULONG ulIdentifyID, PU_AUDIO_INFO pstAudioInfo);

	boolean IVS_PU_GetAutoAperturePara(ULONG ulIdentifyID, PU_AUTO_APERTURE_PARA pstAutoAperturePara);

	// Active ARP broadcast parameter.
	boolean IVS_PU_GetAutoARPBroadcastPara(NativeLong ulIdentifyID, NativeLong ulEthIndex,
			PU_AUTO_ARP_BROADCAST_PARA pstAutoARPBroadcastPara);

	boolean IVS_PU_GetAutoDialingPlan(ULONG ulIdentifyID, PU_AUTO_DIALING_PLAN_S pstAutoDialingPlan);

	boolean IVS_PU_GetAutoFocusArea(ULONG ulIdentifyID, PU_PTZ_FOCUSAREA pstAutoFocusArea); // -------->Num.325

	// device band width self adaption
	boolean IVS_PU_GetBandwidthSelfAdaption(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOLByReference pbEnable);

	// device blaze restrain
	boolean IVS_PU_GetBlazeRestrain(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOLByReference pbEnable,
			LongByReference pulBlazeRestrainLevel);

	boolean IVS_PU_GetCacheRecordType(ULONG ulIdentifyID, int penCacheRecType);

	boolean IVS_PU_GetCamGeogPostion(ULONG ulIdentifyID, PU_CAM_GEOG_POSITION pstCamGeogPostion); // ------>Num.257

	// Certificate validity period.
	boolean IVS_PU_GetCertExpirePeriodPara(NativeLong ulIdentifyID,
			PU_CERT_EXPIRE_PERIOD_PARA_S pstCertExpirePeriodPara);

	// Obtain stream profile parameter settings.
	boolean IVS_PU_GetChannelStreamProfilesPara(NativeLong ulIdentifyID, PU_CHANNEL_STREAM_PROFILES pstStreamProfile);

	// Obtain stream profile parameter V2 (five streams) settings.
	boolean IVS_PU_GetChannelStreamProfilesParaV2(NativeLong ulIdentifyID,
			PU_CHANNEL_STREAM_PROFILESV2 pstStreamProfile);

	// Obtain the CMOS sensor size.
	boolean IVS_PU_GetCMOSSize(ULONG ulIdentifyID, PU_CMOS_SIZE_PARA pstCMOSSizePara);

	// device config file
	// szConfigFile length is PU_CONFIG_FILE_PATH_MAX=512。
	boolean IVS_PU_GetConfigFile(NativeLong ulIdentifyID, byte[] szConfigFile, String pszLoadUpKey);

	// device corridor mode
	boolean IVS_PU_GetCorridorMode(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOLByReference pbEnable);

	// Obtain lens information.
	boolean IVS_PU_GetCurrentLensInfo(ULONG ulIdentifyID, PU_LENS_INFO_S pstLensInfo);

	// Obtain CVBS parameter settings.
	boolean IVS_PU_GetCVBSPara(ULONG ulIdentifyID, PU_CVBS_PARA pstCVBSResolution);

	// daylight saving time para
	boolean IVS_PU_GetDaylightSavingTimePara(NativeLong ulIdentifyID, PU_DAYLIGHT_SAVING_TIME_S pstDSTPara);

	boolean IVS_PU_GetDDNSPara(ULONG ulIdentifyID, PU_DDNS_CONF_INFO_S pstDDNSpara);

	/* DEC Dedicated Functions */
	// Obtain the decoder channel capability list.
	boolean IVS_PU_GetDecChannelAbility(ULONG ulIdentifyID, PU_DEC_CHANNEL_ABILITY pstDecChannelAbilityList);

	// Obtain the default violation dictionary parameter setting.
	boolean IVS_PU_GetDefaultITSIllegalDicPara(ULONG ulIdentifyID, PU_ITS_ILLEGAI_DIC_PARAM_S pstPara);

	// device defog type
	// enDefogType -> c type:PU_DEFOG_TYPR
	boolean IVS_PU_GetDefogType(ULONG ulIdentifyID, ULONG ulChannelId, IntByReference penDefogType);

	// Remotely obtain device configurations.
	boolean IVS_PU_GetDevConfigPara(ULONG ulIdentifyID, PU_DEV_CONFIG_INFO pstDevConfigInfo);

	// get device ability params
	boolean IVS_PU_GetDeviceAbility(ULONG ulIdentifyID, PU_DEVICE_ABILITY pstDeviceAbility);

	// Obtain the device ESN.
	boolean IVS_PU_GetDeviceESNInfo(ULONG ulIdentifyID, PU_DEVICE_ESN_INFO_S pstPara);

	// change device ip address
	boolean IVS_PU_GetDeviceEthernetPara(NativeLong ulIdentifyID, PU_DEVICE_ETHERNET_PARA pstDeviceEthernetPara);

	// get device info
	boolean IVS_PU_GetDeviceInfo(NativeLong ulIdentifyID, LPPU_DEVICEINFO_S pstDeviceInfo);

	// Obtain the device information.
	boolean IVS_PU_GetDeviceInfoEx(ULONG ulIdentifyID, PU_DEVICE_INFO_EX pstDeviceInfo);

	// get device log info
	boolean IVS_PU_GetDeviceLogInfo(NativeLong ulIdentifyID, PU_LOG_TYPE enLogType, LPPU_LOG_REQ_PARA_S pstLogReqPara,
			LPPU_LOG_INFO_S pstDeviceLogInfo);

	// device log language
	// penLanguage -> C type : VIDEO_VENC_ROTATION_E
	boolean IVS_PU_GetDeviceLogLanguage(NativeLong ulIdentifyID, int penLanguage);

	// HTTP/HTTPS/RTSP port setting
	boolean IVS_PU_GetDevicePortConfig(ULONG ulIdentifyID, PU_DEVICE_PORT_CONFIG pstDevPortConfig);

	// HTTP/HTTPS/RTSP port setting ex
	boolean IVS_PU_GetDevicePortConfigEx(ULONG ulIdentifyID, PU_DEVICE_PORT_CONFIG_EX pstDevPortConfig);

	// Obtain real-time device status.
	boolean IVS_PU_GetDeviceRealStatusInfo(ULONG ulIdentifyID, PU_DEV_REALSTATUS_INFO pstRealStatusInfo);

	// device rsa secret key length
	boolean IVS_PU_GetDeviceRSASecretKeyLen(NativeLong ulIdentifyID, LongByReference pulSecretKeyLen);

	// get device system status info
	boolean IVS_PU_GetDeviceStatusInfo(NativeLong ulIdentifyID, LPPU_SYS_STATUS_INFO_S pstSysStatusInfo);

	// device time
	boolean IVS_PU_GetDeviceTime(NativeLong ulIdentifyID, LPPU_SYSTEM_TIME_S pstSystemTime);

	// device user management
	boolean IVS_PU_GetDeviceUserList(NativeLong ulIdentifyID, PU_USER_LIST pstUserList);

	// device video format
	// enVideoFormat -> c type:PU_VIDEO_FORMAT_E
	boolean IVS_PU_GetDeviceVideoFormat(ULONG ulIdentifyID, ULONG ulChannelId, IntByReference penVideoFormat);

	boolean IVS_PU_GetDialingInfo(ULONG ulIdentifyID, PU_DIALING_CONFIG_INFO_S pstDialingConfigInfo);

	boolean IVS_PU_GetDialingStatus(ULONG ulIdentifyID, PU_DIALING_STATUS_INFO_S pstDialingStatus);

	// device switch input and output params
	boolean IVS_PU_GetDIOPara(ULONG ulIdentifyID, PU_DIO_PARA pstSwitchDioPara);

	/******************************************************************************************************/
	/* IPC Dedicated Functions */
	/******************************************************************************************************/

	// Query the SD card status.
	boolean IVS_PU_GetDiskState(ULONG ulIdentifyID, PU_HARD_DISK_STATE pstDiskState);

	// device DI state
	boolean IVS_PU_GetDIState(ULONG ulIdentifyID, ULONG ulInputId, LongByReference plInputState);

	// device DO state
	boolean IVS_PU_GetDOState(ULONG ulIdentifyID, ULONG ulOutputId, LongByReference plOutputState);

	// get/set device dynamic stream info
	boolean IVS_PU_GetDynamicStreamInfo(ULONG ulIdentifyID, PU_DYNAMIC_STREAM_INFO pstDynamicStreamInfo);

	boolean IVS_PU_GetEchoCancelEnable(ULONG ulIdentifyID, PU_AEC_ENABLE pstEchoCancelEnable);

	// Obtain the lane parameter setting in ePolice mode.
	boolean IVS_PU_GetEPoliceLanePara(ULONG ulIdentifyID, PU_ITS_EPOLICE_LANE_PARAM pstEPoliceLanePara);

	// Set the button for restoring area cropping.

	/************ Add (Xiao Zengrui and Chen Chao) ***************/
	// Obtain the setting of the traffic light parameter in ePolice mode.
	boolean IVS_PU_GetEpoliceSigLightPara(ULONG ulIdentifyID, PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM pstPara);

	// Obtain the snapshot type in ePolice mode.
	boolean IVS_PU_GetEPoliceSnapTypePara(ULONG ulIdentifyID, tagItsEPoliceSnapType pstEPoliceSnapTypePara);

	// Obtain the extended snapshot type in ePolice mode.
	boolean IVS_PU_GetEPoliceSnapTypeParaV2(ULONG ulIdentifyID, tagItsEPoliceSnapType_V2 pstEPoliceSnapTypePara);

	// get error message by error number
	public String IVS_PU_GetErrorMsg(long ulErrorNo);

	// device exposure compensation
	boolean IVS_PU_GetExposureCompensation(ULONG ulIdentifyID, ULONG ulChannelId, LongByReference pulCoefficient);

	// This API is the face detection interface. It is applicable to all models
	// earlier than V500R019C20 and C series cameras later than V500R019C20.
	// To invoke this function on camera models of V500R019C20 and later versions,
	// use IVS_PU_GetAlarmPara and IVS_PU_SetAlarmPara (alarm type:
	// PU_ALARM_TYPE_FD_DL).
	boolean IVS_PU_GetFaceDetectPara(ULONG ulIdentifyID, PU_FACE_DETC_ALARM_PARA_S pstFDAlarmPara);

	// Obtain face library information.
	boolean IVS_PU_GetFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_GET_S pstGetFaceLib);

	boolean IVS_PU_GetFaceOsdPara(ULONG ulIdentifyID, PU_FACE_OSD_PARA_S pstPara);

	// Obtain face images.
	boolean IVS_PU_GetFacePicture(ULONG ulIdentifyID, PU_FACE_PIC_GET_S pstGetFacePic);

	// Set the parameter for sending 3559 facial recognition metadata in anonymous
	// mode.
	boolean IVS_PU_GetFaceRecogDLAnonymousPara(ULONG ulIdentifyID,
			PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S pstFaceRecogDLAnonymous);

	// Facial recognition parameters.
	boolean IVS_PU_GetFaceRecogPara(ULONG ulIdentifyID, PU_FACE_RECOGNITION_PARA_S pstFaceRecogPara);

	// device flicker mode
	// enFlickerMode -> c type:PU_VIDEO_FLICKER_MODE
	boolean IVS_PU_GetFlickerMode(ULONG ulIdentifyID, ULONG ulChannelId, IntByReference penFlickerMode);

	boolean IVS_PU_GetFocusCompensation(ULONG ulIdentifyID, PU_FOCUS_COMPENSATION_S pstFocusCompensation);

	// Obtain the value of the parameter for uploading snapshots through FTP or
	// SFTP.
	boolean IVS_PU_GetFTPFileUploadPara(ULONG ulIdentifyID, PU_FTP_FILE_UPLOAD_PARA pstFTPFileUpload);

	// GBT 28281 platform params
	boolean IVS_PU_GetGBTPlatformPara(ULONG ulIdentifyID, PU_PLATFORM_GBT_PARA pstGbtPlatformPara);

	// device GPS params
	boolean IVS_PU_GetGPSPara(ULONG ulIdentifyID, PU_GPS_PARA pstGPSPara);

	// device guard position params(only guard preset)
	boolean IVS_PU_GetGuardPositionPara(ULONG ulIdentifyID, GUARD_POSITION_PARA pstGuardPositionPara);

	// device guard position params
	boolean IVS_PU_GetGuardPositionParaEx(ULONG ulIdentifyID, GUARD_POSITION_PARA_EX pstGuardPositionParaEx);

	// get device guard state
	boolean IVS_PU_GetGuardState(ULONG ulIdentifyID, PU_GUARD_STATE pstGuardStates);

	// hot map para
	boolean IVS_PU_GetHotMapPara(ULONG ulIdentifyID, PU_HOTMAP_PARA pstPara);

	// hot map guard plan
	boolean IVS_PU_GetHotMapPlan(ULONG ulIdentifyID, PU_HOTMAP_GUARD_PLAN_PARA_S pstPara);

	// Obtain the head counting report.
	boolean IVS_PU_GetHumanCountTable(ULONG ulIdentifyID, PU_HUMANCOUNT_TABLE_S pstHCTable);

	boolean IVS_PU_GetHVAlarmPara(ULONG ulIdentifyID, PU_HV_ALARM_PARA_S pstAlarmPara);

	// device intelligent area detection alarm params
	// enAlarmAeraType C Type is PU_IGT_AREA_ALARM_TYPE
	boolean IVS_PU_GetIgtAreaDtcAlarmPara(ULONG ulIdentifyID, int enAlarmAeraType,
			PU_IGT_AEREDTC_ALARM_PARA pstIgtAreaDtcAlarmPara);

	/************************
	 * Intelligent Parameters Functions
	 ******************************/

	// device intelligent switch params
	boolean IVS_PU_GetIgtPara(ULONG ulIdentifyID, PU_IGT_ALARM_PARA pstIgtAlarmPara);

	// device intelligent tripwire alarm params
	boolean IVS_PU_GetIgtTripwireAlarmPara(ULONG ulIdentifyID, PU_TW_ALARM_PARA pstIgtTwAlarmPara);

	// device infrared light params
	boolean IVS_PU_GetInfraredLightPara(ULONG ulIdentifyID, PU_IRLIGHT_LIST pstIRLightPara);

	boolean IVS_PU_GetInfraredLightStatus(ULONG ulIdentifyID, PU_IRLIGHT_LIST pstIRLightPara);

	boolean IVS_PU_GetInstallHeight(ULONG ulIdentifyID, PU_CAM_INSTALL_HEIGHT pstInstallHeight);

	// Obtain IP address filtering parameter settings.
	boolean IVS_PU_GetIPFilterPara(NativeLong ulIdentifyID, PU_IPFILTER_RULES_INFO pstIPFilterPara);

	// Obtain IP address filtering parameter settings.
	boolean IVS_PU_GetIPFilterParaV2(NativeLong ulIdentifyID, PU_IPFILTER_RULES_INFOV2 pstIPFilterPara);

	// Obtain IP address filtering parameter settings.
	boolean IVS_PU_GetIPFilterParaV3(NativeLong ulIdentifyID, PU_IPFILTER_RULES_INFOV3_S pstIPFilterPara);

	// Obtain ISP algorithm information.
	boolean IVS_PU_GetISPAlthmInfo(ULONG ulIdentifyID, PU_ISP_ALG_INFO_S pstISPAlthmInfo);

	boolean IVS_PU_GetISPPara(ULONG ulIdentifyID, PU_ISP_PARTICULAR_PARA pstISPPara);

	// Extended ISP parameters.
	boolean IVS_PU_GetISPParticularParamEx(ULONG ulIdentifyID, PU_ISP_PARTICULAR_PARA_EX_S pstParam);

	boolean IVS_PU_GetISPProfilePara(ULONG ulIdentifyID, PU_ISP_PROFILES_PARA pstIspProfilePara);

	// isp profiles link
	boolean IVS_PU_GetIspProfilesLink(ULONG ulIdentifyID, PU_ISP_PROFILES_LINK_INFO pstIspProfileLink);

	boolean IVS_PU_GetITGEMode(ULONG ulIdentifyID, PU_ITGT_MODE_S pstPara);

	// Obtain the intelligent algorithm information.
	boolean IVS_PU_GetItgtAlthmInfo(ULONG ulIdentifyID, PU_ITGT_ALTHM_INFO pstItgtAlthmInfo);

	// Obtain extended intelligent algorithm information.
	boolean IVS_PU_GetItgtAlthmInfoV2(ULONG ulIdentifyID, PU_ITGT_ALTHM_INFO_EX pstItgtAlthmInfo);

	// Obtain the ITS application mode.
	boolean IVS_PU_GetITSBusinessTypePara(ULONG ulIdentifyID, PU_ITS_BUSINESS_TYPE_PARA pstITSBusinessTypePara);

	// Obtain/Set detection line parameters.
	boolean IVS_PU_GetITSDtLineParam(ULONG ulIdentifyID, PU_ITS_DT_LINE_PARAM pstPara);

	// Obtain the setting of the traffic light simulation parameter in ePolice mode.
	boolean IVS_PU_GetITSEpoliceSimTrafficLightParam(ULONG ulIdentifyID, PU_ITS_SIM_TRAFFIC_LIGHT_PARAM pstPara);

	// Obtain the external device parameter settings in ITS mode.
	boolean IVS_PU_GetITSExtraDevicePara(ULONG ulIdentifyID, PU_ITS_DEV_SPEC_S pstExtraDevPara);

	// Obtain and set traffic flow statistics.
	boolean IVS_PU_GetITSFlowRateParam(ULONG ulIdentifyID, PU_ITS_FLOW_RATE_PARA pstFlowRatePara);

	// Obtain/Set violation dictionary parameters.
	boolean IVS_PU_GetITSIllegalDicPara(ULONG ulIdentifyID, PU_ITS_ILLEGAI_DIC_PARAM_S pstPara);

	// ITS end-number policy.
	boolean IVS_PU_GetITSRestrictPara(ULONG ulIdentifyID, PU_ITS_RESTRICTED_PARAM pstPara);

	// Obtain the ITS snapshot list.
	boolean IVS_PU_GetITSSnapshotPicList(ULONG ulIdentifyID, PU_ITS_SNAPSHOT_INQUIRE pstSnapshotInquire,
			PU_SNAPSHOT_LIST_S pstSnapshotList);

	// Obtain/Set speed estimation parameters.
	boolean IVS_PU_GetITSSpeedMeasureParam(ULONG ulIdentifyID, PU_ITS_SPEED_MEASURE_PARAM pstPara);

	// Obtain/Set lane parameters in ePolice mode.
	boolean IVS_PU_GetITSTGateWayLaneParam(ULONG ulIdentifyID, PU_ITS_EPOLICE_LANE_PARAM pstPara);

	// Obtain/Set snapshot parameters in ePolice mode.
	boolean IVS_PU_GetITSTGateWaySnapTypeParam(ULONG ulIdentifyID, tagItsEPoliceSnapType pstPara);

	// Obtain/Set extended snapshot parameters in ePolice mode.
	boolean IVS_PU_GetITSTGateWaySnapTypeParamV2(ULONG ulIdentifyID, tagItsEPoliceSnapType_V2 pstPara);

	// I- or P-frame encoding policy.
	boolean IVS_PU_GetKFCodingStrategyPara(ULONG ulIdentifyID, PU_KF_CODING_STRATEGY_PARA pstKFCodingStrategyPara);

	// Obtain illuminator parameter settings.
	boolean IVS_PU_GetLampPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LAMP_ATTR_S pstLampPara);

	// get sdk last error
	public long IVS_PU_GetLastError();

	// get sdk last login lock time
	boolean IVS_PU_GetLastLoginLockTime(NativeLong pulLockTime);

	// Obtain the license service information.
	boolean IVS_PU_GetLicServiceInfo(ULONG ulIdentifyID, PU_ITGT_LIC_SERVICE_INFO pstLicServiceInfo);

	// Obtain the extended license service information.
	boolean IVS_PU_GetLicServiceInfoV2(ULONG ulIdentifyID, PU_ITGT_LIC_SERVICE_INFO_EX pstLicServiceInfo);

	// Obtain the manual defogging setting (enabled or disabled).
	boolean IVS_PU_GetManualDefog(ULONG ulIdentifyID, PU_MANAUL_DEFOG_ENABLE_S pstManualDefog);

	// master slave calibration para
	boolean IVS_PU_GetMasterSlaveCalibrationPara(ULONG ulIdentifyID,
			PU_MASTER_SLAVE_CALIBRATION_STATUS pstMasterSlaveCalibrationPara);

	// master slave calibration status
	boolean IVS_PU_GetMasterSlaveCalibrationStatus(ULONG ulIdentifyID,
			PU_MASTER_SLAVE_CALIBRATION_STATUS pstMasterSlaveCalibrationStatus);

	// Obtain information about the master and slave channels in master-slave camera
	// surveillance mode.
	public boolean IVS_PU_GetMasterSlaveChannelInfo(WinDef.ULONG ulIdentifyID, PU_MASTER_SLAVER_CHANNEL_INFO_S pstPara);

	// master slave communication para
	boolean IVS_PU_GetMasterSlaveCommunicationPara(ULONG ulIdentifyID,
			PU_MASTER_SLAVE_COMMUNICATION_PARA pstMasterSlaveCommunicationPara);

	/*
	 * Smart tracking (linkage between a box or bullet camera and a PTZ dome
	 * camera).
	 */
	// master slave group para
	boolean IVS_PU_GetMasterSlaveGroupPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_GROUP_PARA pstMasterSlaveGroupPara);

	// master slave locate para
	boolean IVS_PU_GetMasterSlaveLocateConfig(ULONG ulIdentifyID,
			PU_MASTER_SLAVE_LOCATE_CONFIG pstMasterSlaveLocateConfig);

	// master slave track para
	boolean IVS_PU_GetMasterSlaveTrackPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_TRACK_PARA pstMasterSlaveTrackPara);

	// master slave watch point para
	boolean IVS_PU_GetMasterSlaveWatchPointPara(ULONG ulIdentifyID,
			PU_PTZ_CURRENT_LOCATION pstMasterSlaveWatchPointPara);

	// device MTU value
	boolean IVS_PU_GetMTUPara(ULONG ulIdentifyID, LongByReference pulMtuValue);

	boolean IVS_PU_GetMulticastPara(ULONG ulIdentifyID, String szLocalIP, LongByReference ulVideoPort);

	boolean IVS_PU_GetMulticastParaEx(ULONG ulIdentifyID, PU_MULTICAST_PARA pstParam);

	// device Noise reduction switch
	boolean IVS_PU_GetNoiseReductionMode(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOLByReference pbEnable,
			LongByReference pulCoefficient);

	// Set the noise reduction mode.
	boolean IVS_PU_GetNoiseReductionModeEx(ULONG ulIdentifyID, PU_NOISE_REDUCTION pstNoiseReduction);

	// device NTP params
	boolean IVS_PU_GetNTPPara(ULONG ulIdentifyID, PU_NTP_PARA pstNtpPara);

	// device ONVIF authentication type
	// enOnvifAuthType -> c type:PU_ONVIF_AUTH_TYPE
	boolean IVS_PU_GetONVIFAuthType(ULONG ulIdentifyID, IntByReference penOnvifAuthType);

	// Indicates whether the ONVIF message validity period expiration function is
	// enabled.
	boolean IVS_PU_GetONVIFExpiresSwitch(ULONG ulIdentifyID, PU_ONVIF_SWITCH pstONVIFSwitch);

	// device onvif media keeplive
	boolean IVS_PU_GetOnvifMediaKeepAliveMode(ULONG ulIdentifyID, WinDef.BOOLByReference pbEnable);

	boolean IVS_PU_GetOnvifRtspSessionTimeOut(NativeLong ulIdentifyID, ONVIF_RTSP_SESSION_TIMEOUT pstPara);

	// device ONVIF stream params
	// enVideoCodeType -> c type:PU_VIDEO_CODE_TYPE
	boolean IVS_PU_GetONVIFStreamCodeType(ULONG ulIdentifyID, IntByReference penVideoCodeType);

	// device ONVIF protocol
	boolean IVS_PU_GetONVIFSwitch(ULONG ulIdentifyID, WinDef.BOOLByReference pbEnable);

	// ONVIF version
	boolean IVS_PU_GetONVIFVersionType(ULONG ulIdentifyID, PU_ONVIF_VERSION_TYPE pstONVIFVersionType);

	boolean IVS_PU_GetOSDIConfig(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA pstOSDIConfig);

	boolean IVS_PU_GetOSDIConfigV20(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA_V20 pstOSDIConfig);

	// device OSD margin
	boolean IVS_PU_GetOSDMargin(ULONG ulIdentifyID, PU_OSD_MARGIN_INFO pstOSDMarginInfo);

	// device OSD picture info
	boolean IVS_PU_GetOSDPicturePara(ULONG ulIdentifyID, PU_OSD_PICTURE_PARA pstPicturePara);

	// device OSD params extern, can set at most 7 OSD strings
	boolean IVS_PU_GetOsdText(ULONG ulIdentifyID, PU_OSD_STRING_ARRAY pstOsdPartcularPara);

	// enCharEncodeType -> C type:PU_CHAR_ENCODE_TYPE
	boolean IVS_PU_GetOsdTextEx(ULONG ulIdentifyID, PU_OSD_STRING_ARRAY pstOsdPartcularPara, int enCharEncodeType);

	// enCharEncodeType -> C type:PU_CHAR_ENCODE_TYPE
	boolean IVS_PU_GetOsdTextExV2(ULONG ulIdentifyID, PU_OSD_STRING_ARRAY_EX_OUT pstOsdPartcularPara,
			int enCharEncodeType);

	// device privacy mask
	boolean IVS_PU_GetPrivacyMask(ULONG ulIdentifyID, PU_PRIVACY_MASK_ARRAY pstPrivacyMaskArray);

	// device privacy mask
	boolean IVS_PU_GetPrivacyMaskArea(ULONG ulIdentifyID, PU_PRIVACY_MASK_AREA_ARRAY pstPrivacyMaskAreaArray);

	// device privacy mask with color
	boolean IVS_PU_GetPrivacyMaskEx(ULONG ulIdentifyID, PU_PRIVACY_MASK_ARRAY_EX pstPrivacyMaskArrayEx);

	// device ptz aux mode enAuxMode C type is PU_PTZ_AUX_MODE, penAuxMode c Type is
	// PU_PTZ_AUX_MODE*
	boolean IVS_PU_GetPTZAuxMode(ULONG ulIdentifyID, ULONG ulPtzId, IntByReference penAuxMode);

	// device ptz camera information
	boolean IVS_PU_GetPTZCameraInfoMode(ULONG ulIdentifyID, ULONG ulPtzId, WinDef.BOOLByReference pbEnable);

	// penOSDMode C Type is PTZ_OSD_MODE
	boolean IVS_PU_GetPTZCameraInfoModeV20(ULONG ulIdentifyID, ULONG ulPtzId, PTZ_OSD_MODE penOSDMode);

	boolean IVS_PU_GetPTZCheck(ULONG ulIdentifyID, PU_PTZ_CHECK_PARA_S pstPTZCheck);

	// device ptz current location
	boolean IVS_PU_GetPTZCurrentLocation(ULONG ulIdentifyID, PU_PTZ_CURRENT_LOCATION pstCurrentLocation);

	// device ptz focus mode penFocusMode C type is PU_FOCUS_MODE* , enFocusMode C
	// type is PU_FOCUS_MODE
	boolean IVS_PU_GetPTZFocusMode(ULONG ulIdentifyID, ULONG ulPtzId, IntByReference penFocusMode);

	boolean IVS_PU_GetPTZFocusModeV20(ULONG ulIdentifyID, PU_PTZ_FOCUS_MODE_S pstFocusMode);

	// device ptz info
	boolean IVS_PU_GetPTZInfo(ULONG ulIdentifyID, PU_PTZ_PARA pstPtzPara);

	boolean IVS_PU_GetPTZPresetFreezing(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOLByReference pbEnable);

	// device ptz relative location
	boolean IVS_PU_GetPTZRelativeLocation(ULONG ulIdentifyID, ULONG ulPtzId, WinDef.BOOLByReference pbEnable);

	boolean IVS_PU_GetPTZSpeed(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_S pstPTZSpeed);

	boolean IVS_PU_GetPTZSpeedAbility(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_ABILITY pstPTZSpeedAbility);

	boolean IVS_PU_GetPTZSpeedLimit(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_LIMIT_S pstPTZSpeedLimit);

	// device qos dscp params
	// enDscpType -> c type:PU_DSCP_TYPE
	boolean IVS_PU_GetQosDscpPara(ULONG ulIdentifyID, IntByReference penDscpType, LongByReference pulDscpValue);

	// Obtain the actual OSD information, enCharEncodeType C type is
	// PU_CHAR_ENCODE_TYPE_E
	boolean IVS_PU_GetRealOsdText(ULONG ulIdentifyID, PU_OSD_PARTICULAR_PARA_EX_OUT_S pstRealOsdPara,
			int enCharEncodeType);

	// device record full strategy
	boolean IVS_PU_GetRecordFullStrategy(ULONG ulIdentifyID, RECORD_STRATEGY pstRecordStrategy);

	// get device record info
	boolean IVS_PU_GetRecordInfoList(ULONG ulIdentifyID, PU_RECORD_INQUIRE pstRecordInquire,
			PU_RECORD_LIST pstRecordList);

	boolean IVS_PU_GetRecordInfoListByUTC(ULONG ulIdentifyID, PU_RECORD_INQUIRE pstRecordInquire,
			PU_RECORD_LIST pstRecordList);

	// device record upload band width
	boolean IVS_PU_GetRecordUploadBandwidth(ULONG ulIdentifyID, WinDef.BOOLByReference pbEnable,
			LongByReference pulMaxUploadRate); // ----->Num.200

	// Obtain the maximum packet receiving rate.
	boolean IVS_PU_GetRecvRateLimit(ULONG ulIdentifyID, LongByReference pulRecvRateLimit);

	// Obtain/Set red light enhancement parameters.
	boolean IVS_PU_GetRLCropEnhancePara(ULONG ulIdentifyID, PU_RL_CROP_ENHANCE_PARA pstPara);

	// device ROI params
	boolean IVS_PU_GetROIInfo(ULONG ulIdentifyID, PU_ROI_INFO pstROIInfo);

	// Obtain the SD card-based recording plan.
	boolean IVS_PU_GetSDCardRecordPlan(ULONG ulIdentifyID, PU_LOCAL_RECORD_PLAN pstLocalRecordPlan);

	// device sd card record status
	boolean IVS_PU_GetSDCardRecordStatus(ULONG ulIdentifyID, PU_LOCAL_RECORD pstLocalRecord);

	// device sd card record time
	boolean IVS_PU_GetSDCardRecordTime(ULONG ulIdentifyID, ULONG ulChannelId, LongByReference pulSeconds);

	// SDK platform params
	boolean IVS_PU_GetSDKPlatformPara(ULONG ulIdentifyID, PU_PLATFORM_SDK_PARA pstSdkPlatformPara);

	// device SEC params
	boolean IVS_PU_GetSECPara(ULONG ulIdentifyID, PU_SEC_PARA pstSecPara);

	/***************************
	 * PTZ Parameters Functions
	 *********************************/

	// device serial port info
	boolean IVS_PU_GetSerialPortInfo(ULONG ulIdentifyID, PU_SERIAL_PORT_PARA pstSerialPortPara);

	boolean IVS_PU_GetSFTPEnable(NativeLong ulIdentifyID, PU_SFTP_ENABLE_PARA pstPara);

	// Obtain/Set the local SIM card number.
	boolean IVS_PU_GetSIMPhoneNum(ULONG ulIdentifyID, PU_SIM_PHONE_NUM_S pstPara);

	public boolean IVS_PU_GetSlaveDeviceBaseParaList(WinDef.ULONG ulIdentifyID, PU_SLAVE_DEVICE_LIST_S pstParaList);

	public boolean IVS_PU_GetSlaveDeviceEnablePara(WinDef.ULONG ulIdentifyID, PU_SLAVE_DEVICE_ENABLE_S pstPara);

	public boolean IVS_PU_GetSlaveDeviceOnvifPara(WinDef.ULONG ulIdentifyID, PU_SLAVE_ONVIF_PARAM_S pstSlaveOnvifPara);

	// Obtain the ONVIF status of slave cameras.
	public boolean IVS_PU_GetSlaveDeviceOnvifStatus(WinDef.ULONG ulIdentifyID,
			PU_SLAVE_ONVIF_STATUS_S pstSlaveOnvifStatus);

	public boolean IVS_PU_GetSlaveDeviceRtspPara(WinDef.ULONG ulIdentifyID, PU_SLAVE_RTSP_PARAM_S pstSlaveRtspPara);

	// Obtain the RTSP status of slave cameras.
	public boolean IVS_PU_GetSlaveDeviceRtspStatus(WinDef.ULONG ulIdentifyID,
			PU_SLAVE_RTSP_STATUS_S pstSlaveRtspStatus);

	// device slow shutter mode
	boolean IVS_PU_GetSlowShutterMode(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOLByReference pbEnable);

	// SMTP parameter.
	boolean IVS_PU_GetSMTPConfig(NativeLong ulIdentifyID, SMTP_CONFIG_INFO pstSMTPConfig);

	// Obtain the value of the detailed snapshot parameter or ISP parameter of the
	// micro checkpoint camera.
	boolean IVS_PU_GetSnapshotParticularPara(ULONG ulIdentifyID, PU_SNAPSHOT_PARTICULAR_PARA_S pstSnapshotPara);

	boolean IVS_PU_GetSnapshotPicList(ULONG ulIdentifyID, PU_SNAPSHOT_INQUIRE_S pstSnapshotInquire,
			PU_SNAPSHOT_LIST_S pstSnapshotList);

	boolean IVS_PU_GetSnapshotQuality(ULONG ulIdentifyID, PU_SNAPSHOT_QUAILTY_PARA pstSnapshotQuality);

	boolean IVS_PU_GetSnapshotResolution(ULONG ulIdentifyID, PU_SNAPSHOT_RESOLUTION_PARA pstSnapshotRes);

	boolean IVS_PU_GetSnapshotRetransPara(ULONG ulIdentifyID, PU_SNAPSHOT_RETRANS_PARA pstSnapshotRetrans);

	// Obtain the snapshot storage space.
	boolean IVS_PU_GetSnapshotSpace(ULONG ulIdentifyID, PU_SNAPSHOT_SPACE pstSnapshotSpace);

	// Obtain scheduled snapshot.
	boolean IVS_PU_GetSnapshotTiming(ULONG ulIdentifyID, PU_SNAPSHOT_TIMING_PARA pstSnapshotTiming);

	// device snmp protocol params for v1/v2c
	boolean IVS_PU_GetSnmpCommunityList(ULONG ulIdentifyID, PU_SNMP_COMMUNITY_LIST pstCommunityList);

	// device snmp protocol params for v1/v2c
	boolean IVS_PU_GetSnmpCommunityListEx(ULONG ulIdentifyID, PU_SNMP_COMMUNITY_LIST_EX pstCommunityList);

	// device snmp protocol trap params
	boolean IVS_PU_GetSnmpTrapList(ULONG ulIdentifyID, PU_SNMP_TRAP_LIST pstTrapList);

	// device snmp protocol params for v3
	boolean IVS_PU_GetSnmpUserList(ULONG ulIdentifyID, PU_SNMPV3_USER_LIST pstUserList);

	boolean IVS_PU_GetSSHEnable(NativeLong ulIdentifyID, PU_SSH_ENABLE_PARA pstPara);

	// get device stream ability params
	boolean IVS_PU_GetStreamAbility(ULONG ulIdentifyID, PU_STREAM_ABILITY pstStreamAbilityPara);

	// get device stream abilityV2 params
	boolean IVS_PU_GetStreamAbilityV2(ULONG ulIdentifyID, PU_STREAM_ABILITYV2 pstStreamAbilityPara);

	// get device stream layer code mode
	boolean IVS_PU_GetStreamLayerCodeMode(ULONG ulIdentifyID, ULONG ulChannelId, int enStreamType,
			WinDef.BOOLByReference pbEnable);

	// Obtain the stream profile list.
	boolean IVS_PU_GetStreamProfileList(NativeLong ulIdentifyID, PU_STREAMPROFILES_INFO_LIST pstStreamProfilesInfo);

	// Illuminator parameters.
	boolean IVS_PU_GetSupplementLightPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LIGHT_INFO_S pstSupplementLightInfo);

	boolean IVS_PU_GetTCPAcceleratePara(ULONG ulIdentifyID, PU_TCP_ACCELERATE_PARA pstTcpAcceleratePara);

	// get device current temperature
	boolean IVS_PU_GetTemperature(ULONG ulIdentifyID, LongByReference plCurretTemp);

	// Obtain/Set algorithm parameters of traffic PTZ dome cameras.
	boolean IVS_PU_GetTrafficDomeAlgParams(ULONG ulIdentifyID, PU_TD_ALG_PARAMS pstAlgParams);

	// Obtain/Set algorithm parameters V2 of traffic PTZ dome cameras.
	boolean IVS_PU_GetTrafficDomeAlgParamsV2(ULONG ulIdentifyID, PU_TD_ALG_PARAMSV2 pstAlgParams);

	// Obtain the default intelligent violation analysis parameter setting of the
	// traffic PTZ dome camera.
	boolean IVS_PU_GetTrafficDomeIllegalIntelligentDeFaultParams(ULONG ulIdentifyID,
			PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS pstTDomeIllegalIntelligentParams);

	// Obtain/Set intelligent analysis parameters of the traffic PTZ dome camera.
	boolean IVS_PU_GetTrafficDomeIllegalIntelligentParams(ULONG ulIdentifyID,
			PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS pstTDomeIllegalIntelligentParams);

	// Obtain/Set parking violation detection parameters of the traffic PTZ dome
	// camera.
	boolean IVS_PU_GetTrafficDomeManualDetectionParams(ULONG ulIdentifyID,
			PU_TD_MANUAL_DETECTION_PARAMS pstManualDecetionParams);

	// Obtain/Set parking violation detection parameters V2 of the traffic PTZ dome
	// camera.
	boolean IVS_PU_GetTrafficDomeManualDetectionParamsV2(ULONG ulIdentifyID,
			PU_TD_MANUAL_DETECTION_PARAMSV2 pstManualDecetionParams);

	// Obtain/Set scene application parameters of the traffic PTZ dome camera.
	boolean IVS_PU_GetTrafficDomeSceneAppParams(ULONG ulIdentifyID, PU_TD_SCENE_APP_PARAMS pstSceneAppParams);

	// Obtain/Set scene application parameters V2 of the traffic PTZ dome camera.
	boolean IVS_PU_GetTrafficDomeSceneAppParamsV2(ULONG ulIdentifyID, PU_TD_SCENE_APP_PARAMSV2 pstSceneAppParams);

	// Obtain/Set basic scene parameters of the traffic PTZ dome camera.
	boolean IVS_PU_GetTrafficDomeSceneBaseParams(ULONG ulIdentifyID, PU_TD_SCENE_BASE_PARAMS pstSceneBaseParams);

	// Obtain the tour scene status (enabled or disabled) of the traffic PTZ dome
	// camera.
	boolean IVS_PU_GetTrafficDomeSceneEnableInfo(ULONG ulIdentifyID, PU_TD_SCENE_ENABLE_INFO pstSceneEnableInfo);

	// Obtain/Set tour plan parameters of the traffic PTZ dome camera.
	boolean IVS_PU_GetTrafficDomeTourPlanParams(ULONG ulIdentifyID, PU_TD_TOUR_PLAN_PARAMS pstTourPlanParams);

	// device traffic shaping parameter
	boolean IVS_PU_GetTrafficShapingPara(ULONG ulIdentifyID, PU_TRAFFIC_SHAPING_PARA pstTrafficShapingPara);

	// device transparent channel
	boolean IVS_PU_GetTransparentChannelPara(ULONG ulIdentifyID, ULONG ulSerialPort, WinDef.BOOLByReference pbEnable);

	// device typical scene information
	boolean IVS_PU_GetTypicalSceneList(ULONG ulIdentifyID, PU_TYPICAL_SCENE_LIST pstTypecalSceneList);

	// device typical scene information
	boolean IVS_PU_GetTypicalSceneListEx(ULONG ulIdentifyID, PU_TYPICAL_SCENE_LIST_EX_OUT pstTypecalSceneList);

	// device typical scene
	// enMode -> c type:PU_TYPICAL_SCENE_MODE
	boolean IVS_PU_GetTypicalSceneMode(ULONG ulIdentifyID, ULONG ulChannelId, IntByReference penMode); // ---------->Num.300

	// device typical scene extension
	boolean IVS_PU_GetTypicalSceneModeEx(ULONG ulIdentifyID, PU_ISP_TYPICAL_SCENE_MODE pstParam);

	// device typical scene plan
	boolean IVS_PU_GetTypicalScenePlan(ULONG ulIdentifyID, PU_MONTHS_PLAN pstMonthPlan);

	// Extended typical scene plan (added the EndTime field).
	boolean IVS_PU_GetTypicalScenePlanV2(ULONG ulIdentifyID, PU_MONTHS_PLAN pstMonthPlan);

	// Obtain the setting of linking behavior analysis with intelligent tracking.
	boolean IVS_PU_GetVALinkAT(ULONG ulIdentifyID, PU_VA_LINK_AT pstVALinkAT);

	// get device version info
	boolean IVS_PU_GetVersion(NativeLong pulVersion);

	boolean IVS_PU_GetVerticalLimit(ULONG ulIdentifyID, PU_VERTICAL_LIMIT_S pstVerticalLimit);

	/********* Automatic object tracking ********/
	boolean IVS_PU_GetVHDAutoTrackPara(ULONG ulIdentifyID, PU_ITGT_VHD_AUTO_TRACK_PARA pstPara);

	// Object classification.
	boolean IVS_PU_GetVHDPara(ULONG ulIdentifyID, PU_VHD_PARA pstVHDPara);

	// Extended object classification parameters.
	boolean IVS_PU_GetVHDParaEx(ULONG ulIdentifyID, PU_VHD_PARA_EX pstVHDPara);

	// Obtain and set video quality diagnosis enabling parameters.
	boolean IVS_PU_GetVideoDiagnosisEnableInfo(NativeLong ulIdentifyID,
			PU_VIDEODIAGNOSIS_ENABLE_PARAM pstVideoDiagnosisEnableInfo);

	// device video display infos, and restore default display params
	boolean IVS_PU_GetVideoDisplayInfo(ULONG ulIdentifyID, PU_VIDEO_DISPLAY_INFO pstVideoDisplayInfo);

	/************************
	 * Device Parameters Functions
	 ******************************/

	// device video stream infos
	boolean IVS_PU_GetVideoStreamInfo(ULONG ulIdentifyID, PU_VIDEO_STREAM_INFO pstVideoStreamInfo);

	// device video stream infos v2
	boolean IVS_PU_GetVideoStreamInfoV2(ULONG ulIdentifyID, PU_VIDEO_STREAM_INFO_V2 pstVideoStreamInfo);

	// Obtain the value of the parameter for uploading images captured by a micro
	// checkpoint camera in FTP mode.
	boolean IVS_PU_GetVLPRFTPFileUploadPara(ULONG ulIdentifyID, PU_VLPR_FTP_UPLOAD_PARA_S pstFTPFileUpload);

	// Obtain the value of the extended parameter for uploading images captured by a
	// micro checkpoint camera in FTP mode.
	boolean IVS_PU_GetVLPRFTPFileUploadParaV2(ULONG ulIdentifyID, PU_VLPR_FTP_UPLOAD_PARA_V2_S pstFTPFileUpload);

	boolean IVS_PU_GetVLPRPara(ULONG ulIdentifyID, PU_VLPR_PARA_S pstVLPRPara);

	// License plate parameters (extended algorithm type).
	boolean IVS_PU_GetVLPRParaV2(ULONG ulIdentifyID, PU_VLPR_PARA_V2_S pstVLPRPara);

	// License plate parameters (extended).
	boolean IVS_PU_GetVLPRParaV3(ULONG ulIdentifyID, PU_VLPR_PARA_V3_S pstVLPRPara);

	boolean IVS_PU_GetVLPRPicOSDPara(ULONG ulIdentifyID, PU_PIC_OSD_PARA_S pstVLPRPicOSDPara);

	boolean IVS_PU_GetVLPRPicOSDParaV2(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V2_S pstVLPRPicOSDPara);

	boolean IVS_PU_GetVLPRPicOSDParaV3(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V3_S pstVLPRPicOSDPara);

	boolean IVS_PU_GetVLPRPicSynthesisPara(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_S pstVLPRPicSynthesisPara);

	boolean IVS_PU_GetVLPRPicSynthesisParaV2(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_V2_S pstVLPRPicSynthesisPara);

	boolean IVS_PU_GetVLPRPicSynthesisParaV3(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_V3_S pstVLPRPicSynthesisPara);

	// Traffic flow statistics.
	boolean IVS_PU_GetVlprTrafficStat(ULONG ulIdentifyID, PU_VLPR_TRAFFIC_STATISTICS pstPara);

	// Obtain backlight adaptation parameter settings.
	boolean IVS_PU_GetVWBacklightAdaptPara(ULONG ulIdentifyID, PU_VW_BACKLIGHT_ADAPT_PARA_S pstVWBacklightAdaptPara);

	// Obtain overcast adaptation parameter settings.
	boolean IVS_PU_GetVWFogAdaptPara(ULONG ulIdentifyID, PU_VW_FOG_ADAPT_PARA_S pstVWFogAdaptPara);

	// Obtain trailing (speed) adaptation parameter settings.
	boolean IVS_PU_GetVWSpeedAdaptPara(ULONG ulIdentifyID, PU_VW_SPEED_ADAPT_PARA_S pstVWSpeedAdaptPara);

	boolean IVS_PU_GetWaterMark(ULONG ulIdentifyID, ULONG ulChannelId, int enStreamType,
			WinDef.BOOLByReference pbWaterMarkEnable);

	// device WDR enable state
	// enSwitchMode -> C type:PU_WDR_SWITCH_MODE
	boolean IVS_PU_GetWDR(ULONG ulIdentifyID, ULONG ulChannelId, IntByReference penSwitchMode,
			LongByReference pulAutoType, LongByReference pulSensitivity);

	// device web http/https
	// enHttpMode -> c type:PU_WEB_HTTP_MODE
	boolean IVS_PU_GetWebHttpMode(ULONG ulIdentifyID, IntByReference penHttpMode);

	boolean IVS_PU_GetWhiteLists(ULONG ulIdentifyID, PU_SMS_WHITE_LISTS_S pstSmsWhiteLists);

	// set device guard
	boolean IVS_PU_GuardAlarm(ULONG ulIdentifyID, PU_GUARD_PARA pstGuardPara);

	public int IVS_PU_H264DecAU(WinDef.HWND pH264Handle, WinDef.UCHAR pucStream, WinDef.UINT iStreamLen, long ullPTS,
			WinDef.UINT iFlags, PU_H264_DEC_FRAME pstDecFrame);

	// H264 dec
	public WinDef.HWND IVS_PU_H264DecCreate(PU_H264_DEC_ATTR pstDecAttr);

	public void IVS_PU_H264DecDestroy(WinDef.HWND pH264Handle);

	public int IVS_PU_H265DecAU(WinDef.HWND pH265Handle, PU_H265DEC_INARGS pstInArgs, PU_H265DEC_OUTARGS pstOutArgs);

	// H265 dec
	public int IVS_PU_H265DecCreate(WinDef.HWND ppH265Handle, PU_H265D_INIT_PARAM pstInitParam);

	public int IVS_PU_H265DecDestroy(WinDef.HWND pH265Handle);

	boolean IVS_PU_IgtAreaItem(ULONG ulIdentifyID, PU_IGT_AREA_ITEM pstAreaItem);

	boolean IVS_PU_IgtTripwireLineItem(ULONG ulIdentifyID, PU_IGT_TW_LINE_ITEM pstLineItem);

	// Import the facial library. The mapping camera version is V5R19C30 TR5 and
	// earlier versions.
	boolean IVS_PU_ImportFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_IMPORT_S pstFaceLibInfo);

	// Extended interface for importing the face library (the import speed can be
	// improved). This interface is used with IVS_PU_CheckImportStatus (camera
	// version: V500R019C30 TR6 or later).
	boolean IVS_PU_ImportFaceLibEx(ULONG ulIdentifyID, PU_FACE_LIB_IMPORT_S pstFaceLibInfo);

	// initialize sdk resources
	public boolean IVS_PU_Init(NativeLong ulLinkMode, String szLocalIP, NativeLong ulLocalPort);

	public boolean IVS_PU_InitEx(ULONG ulLinkMode, String szLocalIP, ULONG ulLocalPort, ULONG ulLocalTlsPort,
			PU_CERT_FILE_PATH_PARA_S pstCertFilePath);

	boolean IVS_PU_InvokeTransparentCmd(ULONG ulIdentifyID, PU_TRANSPARENT_CMD pstTransparentCmdInfo);

	// device iris emendation
	boolean IVS_PU_IrisEmendation(ULONG ulIdentifyID, PU_IRIS_EMENDATION pstIrisEmendation);

	// Intelligent algorithm package upgrade.
	boolean IVS_PU_ItgtUpgrade(ULONG ulIdentifyID, PU_UPGRADE_ITGT_FILE_INFO pstItgtFileInfo);

	boolean IVS_PU_ItgtUpgradeWithSchedule(ULONG ulIdentifyID, PU_UPGRADE_ITGT_FILE_INFO pstItgtFileInfo,
			pfUpgradeScheduleCallBack fScheduleCallBack, Pointer pUsrData);

	// ITS manual snapshot (searching for snapshots triggered through intelligent
	// analysis).
	boolean IVS_PU_ITSManualSnapshot(ULONG ulIdentifyID, PU_ITS_MANUAL_SNAPSHOT_PARA_S pstManualSnapshotPara);

	// Interface for setting and obtaining parameters in JSON format.
	long IVS_PU_JsonConfig_Option(ULONG ulIdentifyID, LPPU_CONFIG_JSON_INPUT_ST pInputParam,
			LPPU_CONFIG_JSON_CONFIG_OUTPUT_ST pOutputParam);

	/******************************
	 * Stream Functions
	 **********************************/

	// key frame request
	boolean IVS_PU_KeyFrameRequest(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulStreamId);

	// login to device
	public long IVS_PU_Login(String pchLoginIP, ULONG ulLoginPort, String szUserName, String szPasswd);

	// login to device
	boolean IVS_PU_LoginByID(NativeLong ulIdentifyID, String szUserName, String szPasswd);

	// logout from device
	boolean IVS_PU_Logout(ULONG ulIdentifyID);

	// Manually triggered license plate snapshot.
	boolean IVS_PU_ManualLicensePlateCapture(ULONG ulIdentifyID, PU_MANUAL_LPR_CAPTURE_S pstManualLprCapture);

	// Manual snapshot
	boolean IVS_PU_ManualSnapshot(ULONG ulIdentifyID, SNAPSHOT_PARA pstSnapshotPara);

	// master slave track para
	boolean IVS_PU_MasterSlaveManualTrack(ULONG ulIdentifyID,
			PU_MASTER_SLAVE_MANUAL_TRACK_PARA pstMasterSlaveManualTrackPara);

	// Send data streams to the decoder. Data streams can be sent only at 25 fps.
	boolean IVS_PU_MatrixSendData(ULONG ulPassiveHandle, String pSendBuf, ULONG ulBufSize, ULONG ulType);

	// Send data streams to the decoder. The frame rate can be dynamically adjusted.
	boolean IVS_PU_MatrixSendDataEx(ULONG ulPassiveHandle, String pSendBuf, ULONG ulBufSize, ULONG ulType,
			ULONG ulFrameRate);

	// media signal
	boolean IVS_PU_MediaPlay(ULONG ulIdentifyID, PU_MEDIA_PLAY_INFO pstMediaPlayReqInfo,
			PU_MEDIA_PLAY_RSP pstMediaPlayRspInfo);

	// New API whose function is the same as that of IVS_PU_MeidaPlayAck and
	// IVS_PU_MeidaStop.
	boolean IVS_PU_MediaPlayAck(ULONG ulIdentifyID, ULONG ulSessionId, ULONG ulVideoPayload, ULONG ulAudioPayload,
			ULONG ulIgtPayload);

	boolean IVS_PU_MediaStop(ULONG ulIdentifyID, ULONG ulSessionId);

	boolean IVS_PU_MeidaPlayAck(ULONG ulIdentifyID, ULONG ulSessionId, ULONG ulVideoPayload, ULONG ulAudioPayload,
			ULONG ulIgtPayload);

	boolean IVS_PU_MeidaStop(ULONG ulIdentifyID, ULONG ulSessionId);

	// change device IP address by MAC
	boolean IVS_PU_ModifyIPByLocalMac(String szSrcNetMac, String szDstMac, String szPwd, String szDstIP, String szMask,
			String szGateway);

	boolean IVS_PU_MoveToOSDIArea(ULONG ulIdentifyID, ULONG ulChnID, ULONG ulIndex);

	boolean IVS_PU_MultiDirectionMove(ULONG ulIdentifyID, int enDirection, ULONG ulHorSpeed, ULONG ulVerSpeed);

	boolean IVS_PU_MutualAuth(NativeLong ulIdentifyID, String szUserName, String szPasswd);

	// one key collection device informations: logs, system information, ssh
	// information, etc.
	boolean IVS_PU_OneKeyCollectionDeviceInfo(NativeLong ulIdentifyID, String szFilePath);

	// Remotely operate the device, enOptType C type is PU_DEV_OPT_TYPE_E
	boolean IVS_PU_OptDevice(ULONG ulIdentifyID, int enOptType);

	boolean IVS_PU_PagedQueryPrivacyMask(ULONG ulIdentifyID, PU_PRIVACY_MASK_AREA_LIST pstPrivacyMaskList);

	// Check if IP conflicts, return non-conflicting IP list and number
	boolean IVS_PU_PingIPLocal(NativeLong ulStartIP, NativeLong ulEndIP, NativeLong ulNeedNum, NativeLong out_pIPList,
			NativeLong out_pulIPNum);

	// device ptz cruise track
	boolean IVS_PU_PTZ_CruiseTrack(ULONG ulIdentifyID, PU_PTZ_CRUISE_TRACK_PARA pstPtzCruiseTrack);

	boolean IVS_PU_PTZ_GetPresetList(ULONG ulIdentifyID, PU_PTZ_PRESET_LIST_PARA pstPtzPresetList);

	boolean IVS_PU_PTZ_GetPresetListWithFocusInfo(ULONG ulIdentifyID, PU_PTZ_PRESET_LIST_PARA_EX pstPtzPresetList);

	// device ptz preset
	boolean IVS_PU_PTZ_Preset(ULONG ulIdentifyID, PU_PTZ_PRESET_PARA pstPtzPresetPara);

	boolean IVS_PU_PTZ_PresetWithFocusInfo(ULONG ulIdentifyID, PU_PTZ_PRESET_PARA_EX pstPtzPresetPara);

	// device ptz control
	boolean IVS_PU_PTZControl(ULONG ulIdentifyID, LPPU_PTZ_CONTROL_PARA_S pstPtzControlPara);

	// device ptz multi motor enDirection C type is PU_PTZ_OPCODE
	boolean IVS_PU_PTZMultiMotor(ULONG ulIdentifyID, int enDirection, ULONG ulHorSpeed, ULONG ulVerSpeed);

	// query hot map table
	boolean IVS_PU_QueryHotMapTable(ULONG ulIdentifyID, PU_HOTMAP_TABLE_PARA pstPara);

	// real play
	public ULONG IVS_PU_RealPlay(ULONG ulIdentifyID, PU_REAL_PLAY_INFO_S pstRealPlayInfo,
			pfRealDataCallBack fRealDataCallBack, Pointer pUsrData);

	public int IVS_PU_RealPlay_V20(ULONG ulIdentifyID, PU_REAL_PLAY_INFO_V20.ByReference pstRealPlayInfo,
			PU_MEDIA_ENC_PARA_S.ByReference pstMediaEncPara, pfRealDataCallBack fRealDataCallBack, Pointer pUsrData);

	// reboot device
	boolean IVS_PU_Reboot(NativeLong ulIdentifyID);

	long IVS_PU_RecvTransChnDataStart(ULONG ulIdentifyID, ULONG ulSerialPort, pfTransChnDataCallBack pfTransChnCBFunc,
			Pointer pUserData);

	long IVS_PU_RecvTransChnDataStop(ULONG ulIdentifyID);

	// License plate snapshot data subscription.
	boolean IVS_PU_RecvVLPRDataStart(ULONG ulIdentifyID);

	boolean IVS_PU_RecvVLPRDataStop(ULONG ulIdentifyID);

	// response pu register message
	boolean IVS_PU_ResponseDeviceRegister(NativeLong ulIdentifyID, PU_DEVICE_REGISTER_RSP pstDevRegisterRsp);

	boolean IVS_PU_ResponseUploadImageCompleteNotify(ULONG ulIdentifyID, ULONG ulSessionId, int enErrorCode);

	boolean IVS_PU_ResponseUploadImageURL(ULONG ulIdentifyID, ULONG ulSessionId, int enErrorCode, String pszUploadURL);

	// restore device default config (keep IP address)
	boolean IVS_PU_Restore(NativeLong ulIdentifyID, String szUserName, String szPasswd);

	boolean IVS_PU_RestoreDefaultDisplayPara(ULONG ulIdentifyID, ULONG ulChannelId);

	boolean IVS_PU_RotatePTZLocation(ULONG ulIdentifyID, PU_PTZ_CURRENT_LOCATION pstDstLocation);

	// save local snapshot picture
	boolean IVS_PU_SavePicture(ULONG ulIdentifyID, ULONG ulRealHandle, PU_SAVE_PICTURE_INFO pstSavePictureInfo);

	// save real play data
	boolean IVS_PU_SaveRealData(ULONG ulIdentifyID, ULONG ulRealHandle, PU_SAVE_REALDATA_INFO pstSaveRealDataInfo);

	// Set and obtain the 1+N enabling parameter.
	// Enabling or disabling the 1+N function will restart the device.
	public boolean IVS_PU_Set1TNEnable(WinDef.ULONG ulIdentifyID, PU_1TN_ENABLE_S pstPara);

	public boolean IVS_PU_Set1TNSpptMode(WinDef.ULONG ulIdentifyID, PU_1TN_SUPPORT_MODE_SWITCH_S pstPara);

	boolean IVS_PU_Set3559FaceAttribute(ULONG ulIdentifyID, PU_ATTRI_DL_PARAMETER_S pstFaceAttribute);

	// Set the third-party algorithm app.
	boolean IVS_PU_Set3RdAppAlthmOptInfo(ULONG ulIdentifyID, PU_VW_OPERATE_3RD_APP pst3RdAppOperateInfo);

	boolean IVS_PU_Set802Dot1xConfig(ULONG ulIdentifyID, PU_DOT1X_CONFIG_INFO pstDot1xInfo);

	// Enable auto focus for an ABF camera.
	boolean IVS_PU_SetABFAutoBackFocus(ULONG ulIdentifyID, ULONG ulChannelId);

	// Adjust the focus for an ABF camera (moving towards FAR or NEAR). After the
	// adjustment, the focus is not automatically focused.
	boolean IVS_PU_SetABFFocusAction(ULONG ulIdentifyID, CAM_FOCUSCTRL pstFocus);

	// Initialize ABF.
	boolean IVS_PU_SetABFInitialPos(ULONG ulIdentifyID, ULONG ulChannelId);

	boolean IVS_PU_SetAEMeteringMode(ULONG ulIdentifyID, ULONG ulChannelId, int enAEMeteringMode);

	// Audio quality enhancement.
	boolean IVS_PU_SetAiVqeStatus(ULONG ulIdentifyID, WinDef.BOOL bAiVqeStatus);

	// Set the alarm or event callback function.
	boolean IVS_PU_SetAlarmEnventCallBack(ULONG ulIdentifyID, pfGetDevAlarmInfoCallBack fDevAlarmResportCallBack,
			Pointer pUsrData);

	boolean IVS_PU_SetAlarmLinkagePara(ULONG ulIdentifyID, int enAlarmType, ULONG ulAlarmId,
			PU_ALARM_LINKAGE_PARA pstAlarmLinkagePara);

	// Set the alarm linkage priority.
	boolean IVS_PU_SetAlarmLinkPriority(ULONG ulIdentifyID, PU_ALARM_LINK_PRIORITY_PARA pstAlarmLinkPriority);

	// device alarm params, include: temperature alarm, motion detection alarm, hide
	// alarm
	// enAlarmType Type : PU_ALARM_TYPE
	boolean IVS_PU_SetAlarmPara(ULONG ulIdentifyID, int enAlarmType, Pointer arg);

	boolean IVS_PU_SetAreaCropPara(ULONG ulIdentifyID, AREA_CROP_PARA pstAreaCropPara);

	boolean IVS_PU_SetAreaCropRestore(ULONG ulIdentifyID, AREA_CROP_PARA pstAreaCropPara);

	// Set the manual tracking object.
	boolean IVS_PU_SetATManualTarget(ULONG ulIdentifyID, PU_VW_ITGT_AT_MANUAL_TARGET pstATManualTarget);

	boolean IVS_PU_SetAudioStreamInfo(ULONG ulIdentifyID, PU_AUDIO_INFO pstAudioInfo);

	// Auto iris parameter.
	boolean IVS_PU_SetAutoAperturePara(ULONG ulIdentifyID, PU_AUTO_APERTURE_PARA pstAutoAperturePara);

	boolean IVS_PU_SetAutoARPBroadcastPara(NativeLong ulIdentifyID, NativeLong ulEthIndex,
			PU_AUTO_ARP_BROADCAST_PARA pstAutoARPBroadcastPara);

	boolean IVS_PU_SetAutoDialingPlan(ULONG ulIdentifyID, PU_AUTO_DIALING_PLAN_S pstAutoDialingPlan);

	// Set the focus area.
	boolean IVS_PU_SetAutoFocusArea(ULONG ulIdentifyID, PU_PTZ_FOCUSAREA stAutoFocusArea);

	// Set the initial tracking position.
	boolean IVS_PU_SetAutoTrackStartPos(ULONG ulIdentifyID);

	boolean IVS_PU_SetBandwidthSelfAdaption(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOL bEnable);

	boolean IVS_PU_SetBlazeRestrain(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOL bEnable,
			ULONG ulBlazeRestrainLevel);

	// set cache record enable
	// enCacheRecType -> C type:PU_CACHERECORD
	boolean IVS_PU_SetCacheRecordType(ULONG ulIdentifyID, int enCacheRecType);

	// Geographical location.
	boolean IVS_PU_SetCamGeogPostion(ULONG ulIdentifyID, PU_CAM_GEOG_POSITION pstCamGeogPostion);

	boolean IVS_PU_SetCertExpirePeriodPara(NativeLong ulIdentifyID,
			PU_CERT_EXPIRE_PERIOD_PARA_S pstCertExpirePeriodPara);

	// Set stream profile parameters.
	boolean IVS_PU_SetChannelStreamProfilesPara(NativeLong ulIdentifyID, PU_CHANNEL_STREAM_PROFILES stStreamProfile);

	// Set stream profile parameters V2 (five streams).
	boolean IVS_PU_SetChannelStreamProfilesParaV2(NativeLong ulIdentifyID,
			PU_CHANNEL_STREAM_PROFILESV2 stStreamProfile);

	boolean IVS_PU_SetConfigFile(NativeLong ulIdentifyID, byte[] szConfigFile, String pszUserName, String pszPasswd,
			String pszLoadUpKey);

	boolean IVS_PU_SetCorridorMode(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOL bEnable);

	// Set CVBS parameters.
	boolean IVS_PU_SetCVBSPara(ULONG ulIdentifyID, PU_CVBS_PARA stCVBSResolution);

	boolean IVS_PU_SetDaylightSavingTimePara(NativeLong ulIdentifyID, PU_DAYLIGHT_SAVING_TIME_S pstDSTPara);

	// DDNS
	boolean IVS_PU_SetDDNSPara(ULONG ulIdentifyID, PU_DDNS_CONF_INFO_S stDDNSpara);

	boolean IVS_PU_SetDefogType(ULONG ulIdentifyID, ULONG ulChannelId, int enDefogType);

	// Remotely set device parameters, enConfigType C type is PU_DEV_CONFIG_TYPE_E
	boolean IVS_PU_SetDevConfigPara(ULONG ulIdentifyID, int enConfigType, Pointer arg);

	boolean IVS_PU_SetDeviceEthernetPara(NativeLong ulIdentifyID, PU_DEVICE_ETHERNET_PARA pstDeviceEthernetPara);

	boolean IVS_PU_SetDeviceLogLanguage(NativeLong ulIdentifyID, int enLanguage);

	// Device name that contains a maximum of 28 bytes (including the backslash and
	// 0).
	boolean IVS_PU_SetDeviceName(NativeLong ulIdentifyID, String pcDeviceName);

	boolean IVS_PU_SetDevicePortConfig(ULONG ulIdentifyID, PU_DEVICE_PORT_CONFIG pstDevPortConfig);

	boolean IVS_PU_SetDevicePortConfigEx(ULONG ulIdentifyID, PU_DEVICE_PORT_CONFIG_EX pstDevPortConfig);

	boolean IVS_PU_SetDeviceRSASecretKeyLen(NativeLong ulIdentifyID, NativeLong ulSecretKeyLen);

	boolean IVS_PU_SetDeviceTime(NativeLong ulIdentifyID, LPPU_SYSTEM_TIME_S pstSystemTime);

	boolean IVS_PU_SetDeviceVideoFormat(ULONG ulIdentifyID, ULONG ulChannelId, int enVideoFormat);

	boolean IVS_PU_SetDialingInfo(ULONG ulIdentifyID, PU_DIALING_CONFIG_INFO_S pstDialingConfigInfo);

	boolean IVS_PU_SetDIOPara(ULONG ulIdentifyID, PU_DIO_PARA pstSwitchDioPara);

	boolean IVS_PU_SetDOState(ULONG ulIdentifyID, ULONG ulOutputId, NativeLong lOutputState);

	// 802.1X certificate import and export.
	// szCertFileFirst length is PU_CONFIG_FILE_PATH_MAX=512。
	boolean IVS_PU_SetDot1xTlsCert(NativeLong ulIdentifyID, byte[] szCertFileFirst[], byte[] szCertFileSecond[],
			PU_DOT1X_TLS_CERT_UPLOAD_S stDot1xTlsCert);

	boolean IVS_PU_SetDynamicStreamInfo(ULONG ulIdentifyID, PU_DYNAMIC_STREAM_INFO pstDynamicStreamInfo);

	// Echo cancellation.
	boolean IVS_PU_SetEchoCancelEnable(ULONG ulIdentifyID, PU_AEC_ENABLE pstEchoCancelEnable);

	// Set the lane parameter in ePolice mode.
	boolean IVS_PU_SetEPoliceLanePara(ULONG ulIdentifyID, PU_ITS_EPOLICE_LANE_PARAM pstEPoliceLanePara);

	// Set the traffic light parameter in ePolice mode.
	boolean IVS_PU_SetEpoliceSigLightPara(ULONG ulIdentifyID, PU_ITS_EPOLICE_SIGNAL_LIGHT_PARAM pstPara);

	// Set the snapshot type in ePolice mode.
	boolean IVS_PU_SetEPoliceSnapTypePara(ULONG ulIdentifyID, tagItsEPoliceSnapType pstEPoliceSnapTypePara);

	// Pedestrian and vehicle separation.
	// The function interface does not expire. However, due to memory reasons, some
	// models does not support object (people, vehicles, and articles) separation.
	// The details are as follows:
	// (1) Color extraction: Other models except IPC6125-WDL-Fb, IPC6126-WDL-E,
	// IPC6224-VRZ-B, IPC6325-WD-VRZ-B, IPC6256-VRZ, and IPC6355-VRZ do not support
	// this function. The default value of the color parameter is 0.
	// (2) Object separation:
	// (1) C series: Other models except IPC6125-WDL-Fb, IPC6126-WDL-E,
	// IPC6224-VRZ-B, IPC6325-WD-VRZ-B, IPC6256-VRZ, and IPC6355-VRZ do not support
	// this function. The default value of the color parameter is 0.
	// (2) X series and M series do not support object separation. The default value
	// of the color parameter is 0.

	// Set the extended snapshot type in ePolice mode.
	boolean IVS_PU_SetEPoliceSnapTypeParaV2(ULONG ulIdentifyID, tagItsEPoliceSnapType_V2 pstEPoliceSnapTypePara);

	boolean IVS_PU_SetExposureCompensation(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulCoefficient);

	boolean IVS_PU_SetFaceDetectPara(ULONG ulIdentifyID, PU_FACE_DETC_ALARM_PARA_S pstFDAlarmPara);

	// Set face library information.
	boolean IVS_PU_SetFaceLib(ULONG ulIdentifyID, PU_FACE_LIB_SET_S faceLibInfo);

	/* Face OSD text overlay. */
	boolean IVS_PU_SetFaceOsdPara(ULONG ulIdentifyID, PU_FACE_OSD_PARA_S pstPara);

	boolean IVS_PU_SetFaceRecogDLAnonymousPara(ULONG ulIdentifyID,
			PU_FACE_RECOGNITION_DL_ANONYMOUS_PARA_S pstFaceRecogDLAnonymous);

	boolean IVS_PU_SetFaceRecogPara(ULONG ulIdentifyID, PU_FACE_RECOGNITION_PARA_S pstFaceRecogPara);

	boolean IVS_PU_SetFlickerMode(ULONG ulIdentifyID, ULONG ulChannelId, int enFlickerMode);

	// Focus compensation information.
	boolean IVS_PU_SetFocusCompensation(ULONG ulIdentifyID, PU_FOCUS_COMPENSATION_S stFocusCompensation);

	// Set the parameter for uploading snapshots through FTP or SFTP.
	boolean IVS_PU_SetFTPFileUploadPara(ULONG ulIdentifyID, PU_FTP_FILE_UPLOAD_PARA stFTPFileUpload);

	boolean IVS_PU_SetGBTPlatformPara(ULONG ulIdentifyID, PU_PLATFORM_GBT_PARA pstGbtPlatformPara);

	boolean IVS_PU_SetGPSPara(ULONG ulIdentifyID, PU_GPS_PARA pstGPSPara);

	boolean IVS_PU_SetGuardPositionPara(ULONG ulIdentifyID, GUARD_POSITION_PARA pstGuardPositionPara);

	boolean IVS_PU_SetGuardPositionParaEx(ULONG ulIdentifyID, GUARD_POSITION_PARA_EX pstGuardPositionParaEx);

	boolean IVS_PU_SetHotMapPara(ULONG ulIdentifyID, PU_HOTMAP_PARA pstPara);

	boolean IVS_PU_SetHotMapPlan(ULONG ulIdentifyID, PU_HOTMAP_GUARD_PLAN_PARA_S pstPara);

	// Create an HTTPS certificate.
	boolean IVS_PU_SetHttpsCertificate(ULONG ulIdentifyID, PU_CREATE_HTTPS_CERT stHttpsCert);

	// Clear the head counting statistics.
	boolean IVS_PU_SetHumanCountClear(ULONG ulIdentifyID);

	boolean IVS_PU_SetHVAlarmPara(ULONG ulIdentifyID, PU_HV_ALARM_PARA_S stAlarmPara);

	boolean IVS_PU_SetIgtAreaDtcAlarmPara(ULONG ulIdentifyID, int enAlarmAeraType,
			PU_IGT_AEREDTC_ALARM_PARA pstIgtAreaDtcAlarmPara);

	boolean IVS_PU_SetIgtPara(ULONG ulIdentifyID, PU_IGT_ALARM_PARA pstIgtAlarmPara);

	boolean IVS_PU_SetIgtTripwireAlarmPara(ULONG ulIdentifyID, PU_TW_ALARM_PARA pstIgtTwAlarmPara);

	boolean IVS_PU_SetInfraredLightPara(ULONG ulIdentifyID, PU_IRLIGHT_LIST pstIRLightPara);

	// Installation height.
	boolean IVS_PU_SetInstallHeight(ULONG ulIdentifyID, PU_CAM_INSTALL_HEIGHT pstInstallHeight);

	// Set the iPCA parameter.
	boolean IVS_PU_SetIPCAPara(NativeLong ulIdentifyID, PU_IPCA_RULES stIPCARulePara);

	// Set IP address filtering parameters.
	boolean IVS_PU_SetIPFilterPara(NativeLong ulIdentifyID, PU_IPFILTER_RULES_INFO stIPFilterPara);

	// Set IP address filtering parameters.
	boolean IVS_PU_SetIPFilterParaV2(NativeLong ulIdentifyID, PU_IPFILTER_RULES_INFOV2 stIPFilterPara);

	// Set IP address filtering parameters.
	boolean IVS_PU_SetIPFilterParaV3(NativeLong ulIdentifyID, PU_IPFILTER_RULES_INFOV3_S pstIPFilterPara);

	/***************************
	 * ISP Parameters Functions
	 *********************************/

	// device ISP parameter
	boolean IVS_PU_SetISPPara(ULONG ulIdentifyID, PU_ISP_PARTICULAR_PARA pstISPPara, LongByReference ulBitmap);

	boolean IVS_PU_SetISPParticularParamEx(ULONG ulIdentifyID, PU_ISP_PARTICULAR_PARA_EX_S pstParam);

	// device typical scene parameter
	boolean IVS_PU_SetISPProfilePara(ULONG ulIdentifyID, PU_ISP_PROFILES_PARA pstIspProfilePara);

	boolean IVS_PU_SetIspProfilesLink(ULONG ulIdentifyID, PU_ISP_PROFILES_LINK_INFO pstIspProfileLink);

	// Switch among multiple algorithms.
	boolean IVS_PU_SetITGEMode(ULONG ulIdentifyID, PU_ITGT_MODE_S pstPara);

	boolean IVS_PU_SetITSDtLineParam(ULONG ulIdentifyID, PU_ITS_DT_LINE_PARAM pstPara);

	// Set the traffic light simulation parameter in ePolice mode.
	boolean IVS_PU_SetITSEpoliceSimTrafficLightParam(ULONG ulIdentifyID, PU_ITS_SIM_TRAFFIC_LIGHT_PARAM pstPara);

	// Set the external device parameters in ITS mode.
	boolean IVS_PU_SetITSExtraDevicePara(ULONG ulIdentifyID, PU_ITS_DEV_SPEC_S pstExtraDevPara);

	boolean IVS_PU_SetITSFlowRateParam(ULONG ulIdentifyID, PU_ITS_FLOW_RATE_PARA pstFlowRatePara);

	boolean IVS_PU_SetITSIllegalDicPara(ULONG ulIdentifyID, PU_ITS_ILLEGAI_DIC_PARAM_S pstPara);

	boolean IVS_PU_SetITSRestrictPara(ULONG ulIdentifyID, PU_ITS_RESTRICTED_PARAM pstPara);

	boolean IVS_PU_SetITSSpeedMeasureParam(ULONG ulIdentifyID, PU_ITS_SPEED_MEASURE_PARAM pstPara);

	boolean IVS_PU_SetITSTGateWayLaneParam(ULONG ulIdentifyID, PU_ITS_EPOLICE_LANE_PARAM pstPara);

	boolean IVS_PU_SetITSTGateWaySnapTypeParam(ULONG ulIdentifyID, tagItsEPoliceSnapType pstPara);

	boolean IVS_PU_SetITSTGateWaySnapTypeParamV2(ULONG ulIdentifyID, tagItsEPoliceSnapType_V2 pstPara);

	// Function of setting JSON alarm callback.
	// dwBufLen is Monitoring handle dwEventType C type is
	// EM_REALPLAY_DISCONNECT_EVENT_TYPE pMsginfo,pUserData C type is void*
	long IVS_PU_SetJsonMessageCallBack(ULONG ulIdentifyID, pfJsonMsgCallBack fMessageCallBack, Pointer pUserData);

	boolean IVS_PU_SetKFCodingStrategyPara(ULONG ulIdentifyID, PU_KF_CODING_STRATEGY_PARA pstKFCodingStrategyPara);

	// Set illuminator parameters.
	boolean IVS_PU_SetLampPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LAMP_ATTR_S pstLampPara);

	// Set manual defogging (enable or disable).
	boolean IVS_PU_SetManualDefog(ULONG ulIdentifyID, PU_MANAUL_DEFOG_ENABLE_S pstManualDefog);

	boolean IVS_PU_SetManualDialing(ULONG ulIdentifyID, PU_MANUL_DIALING_S pstManulDialing);

	// master slave auth para
	boolean IVS_PU_SetMasterSlaveAuthPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_AUTH_PARA pstMasterSlaveAuthPara);

	boolean IVS_PU_SetMasterSlaveCalibrationPara(ULONG ulIdentifyID,
			PU_MASTER_SLAVE_CALIBRATION_STATUS pstMasterSlaveCalibrationPara);

	boolean IVS_PU_SetMasterSlaveGroupPara(ULONG ulIdentifyID,
			PU_MASTER_SLAVE_PER_GROUP_PARA pstMasterSlavePerGroupPara);

	boolean IVS_PU_SetMasterSlaveLocateConfig(ULONG ulIdentifyID,
			PU_MASTER_SLAVE_LOCATE_CONFIG pstMasterSlaveLocateConfig);

	boolean IVS_PU_SetMasterSlaveTrackPara(ULONG ulIdentifyID, PU_MASTER_SLAVE_TRACK_PARA pstMasterSlaveTrackPara);

	boolean IVS_PU_SetMasterSlaveWatchPointPara(ULONG ulIdentifyID,
			PU_PTZ_CURRENT_LOCATION pstMasterSlaveWatchPointPara);

	boolean IVS_PU_SetMTUPara(ULONG ulIdentifyID, ULONG ulMtuValue);

	// Set Multicast IP Address & Port
	boolean IVS_PU_SetMulticastPara(ULONG ulIdentifyID, String szLocalIP, ULONG ulVideoPort);

	// Set Multicast IP Address & Port ex
	boolean IVS_PU_SetMulticastParaEx(ULONG ulIdentifyID, PU_MULTICAST_PARA pstParam);

	boolean IVS_PU_SetNoiseReductionMode(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOL bEnable,
			ULONG ulCoefficient);

	boolean IVS_PU_SetNoiseReductionModeEx(ULONG ulIdentifyID, PU_NOISE_REDUCTION tNoiseReduction);

	boolean IVS_PU_SetNTPPara(ULONG ulIdentifyID, PU_NTP_PARA pstNtpPara);

	/************************
	 * Intelligent outoffocus Functions
	 ******************************/
	// Set the calibration value for defocus detection.
	boolean IVS_PU_SetOFDStandValueCal(ULONG ulIdentifyID, PU_OUTOFFOCUS_DETECT_PARA_S pstPara);

	boolean IVS_PU_SetONVIFAuthType(ULONG ulIdentifyID, int enOnvifAuthType);

	boolean IVS_PU_SetONVIFExpiresSwitch(ULONG ulIdentifyID, PU_ONVIF_SWITCH pstONVIFSwitch);

	boolean IVS_PU_SetOnvifMediaKeepAliveMode(ULONG ulIdentifyID, WinDef.BOOL bEnable);

	// device ONVIF params
	boolean IVS_PU_SetONVIFPwdPara(ULONG ulIdentifyID, PU_ONVIF_PWD_PARA pstOnvifPwdPara);

	// ONVIF-RTSP media keep-alive time.
	boolean IVS_PU_SetOnvifRtspSessionTimeOut(NativeLong ulIdentifyID, ONVIF_RTSP_SESSION_TIMEOUT pstPara);

	boolean IVS_PU_SetONVIFStreamCodeType(ULONG ulIdentifyID, int enVideoCodeType);

	boolean IVS_PU_SetONVIFSwitch(ULONG ulIdentifyID, WinDef.BOOL bEnable);

	boolean IVS_PU_SetONVIFVersionType(ULONG ulIdentifyID, PU_ONVIF_VERSION_TYPE pstONVIFVersionType);

	// device OSDI parameters setting
	boolean IVS_PU_SetOSDIConfig(ULONG ulIdentifyID, PU_OSDI_BUSINESS_PARA pstOSDIConfig);

	boolean IVS_PU_SetOSDIPosition(ULONG ulIdentifyID, PU_OSDI_POSITION pstOSDIPostion);

	boolean IVS_PU_SetOSDMargin(ULONG ulIdentifyID, PU_OSD_MARGIN_INFO pstOSDMarginInfo);

	boolean IVS_PU_SetOSDPicturePara(ULONG ulIdentifyID, PU_OSD_PICTURE_PARA pstPicturePara);

	boolean IVS_PU_SetOsdText(ULONG ulIdentifyID, PU_OSD_STRING_ARRAY pstOsdPartcularPara);

	boolean IVS_PU_SetOsdTextEx(ULONG ulIdentifyID, PU_OSD_STRING_ARRAY pstOsdPartcularPara, int enCharEncodeType);

	// Set and obtain 4G wireless information.

	boolean IVS_PU_SetOsdTextExV2(ULONG ulIdentifyID, PU_OSD_STRING_ARRAY_EX_OUT pstOsdPartcularPara,
			int enCharEncodeType);

	// set platform params
	// enPlatform -> c type:PU_PLATFORM_TYPE
	boolean IVS_PU_SetPlatformPara(ULONG ulIdentifyID, PU_PLATFORM_TYPE enPlatform, Point arg);

	boolean IVS_PU_SetPrivacyMask(ULONG ulIdentifyID, PU_PRIVACY_MASK_ARRAY pstPrivacyMaskArray);

	boolean IVS_PU_SetPrivacyMaskArea(ULONG ulIdentifyID, PU_PRIVACY_MASK_AREA_ARRAY pstPrivacyMaskAreaArray);

	boolean IVS_PU_SetPrivacyMaskEx(ULONG ulIdentifyID, PU_PRIVACY_MASK_ARRAY_EX pstPrivacyMaskArrayEx);

	boolean IVS_PU_SetPTZAuxMode(ULONG ulIdentifyID, ULONG ulPtzId, int enAuxMode);

	boolean IVS_PU_SetPTZCameraInfoMode(ULONG ulIdentifyID, ULONG ulPtzId, WinDef.BOOL bEnable);

	boolean IVS_PU_SetPTZCameraInfoModeV20(ULONG ulIdentifyID, ULONG ulPtzId, PTZ_OSD_MODE penOSDMode);

	// PTZ dome camera self-check.
	boolean IVS_PU_SetPTZCheck(ULONG ulIdentifyID, PU_PTZ_CHECK_PARA_S pstPTZCheck);

	boolean IVS_PU_SetPTZFocusMode(ULONG ulIdentifyID, ULONG ulPtzId, int enFocusMode);

	boolean IVS_PU_SetPTZFocusModeV20(ULONG ulIdentifyID, PU_PTZ_FOCUS_MODE_S pstFocusMode);

	boolean IVS_PU_SetPTZInfo(ULONG ulIdentifyID, PU_PTZ_PARA pstPtzPara);

	// device ptz presetting_position camera freeze
	boolean IVS_PU_SetPTZPresetFreezing(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOL bEnable);

	boolean IVS_PU_SetPTZRelativeLocation(ULONG ulIdentifyID, ULONG ulPtzId, WinDef.BOOL bEnable);

	boolean IVS_PU_SetPTZSpeedLimit(ULONG ulIdentifyID, ULONG ulPTZId, PU_PTZ_SPEED_LIMIT_S pstPTZSpeedLimit);

	boolean IVS_PU_SetQosDscpPara(ULONG ulIdentifyID, int enDscpType, ULONG ulDscpValue);

	boolean IVS_PU_SetRecordFullStrategy(ULONG ulIdentifyID, RECORD_STRATEGY pstRecordStrategy);

	boolean IVS_PU_SetRecordUploadBandwidth(ULONG ulIdentifyID, WinDef.BOOL bEnable, ULONG ulMaxUploadRate);

	// Set the maximum packet receiving rate.
	boolean IVS_PU_SetRecvRateLimit(ULONG ulIdentifyID, ULONG ulRecvRateLimit);

	boolean IVS_PU_SetRLCropEnhancePara(ULONG ulIdentifyID, PU_RL_CROP_ENHANCE_PARA pstPara);

	boolean IVS_PU_SetROIInfo(ULONG ulIdentifyID, PU_ROI_INFO pstROIInfo);

	// Set the SD card-based recording plan.
	boolean IVS_PU_SetSDCardRecordPlan(ULONG ulIdentifyID, PU_LOCAL_RECORD_PLAN stLocalRecordPlan);

	boolean IVS_PU_SetSDCardRecordStatus(ULONG ulIdentifyID, PU_LOCAL_RECORD pstLocalRecord);

	boolean IVS_PU_SetSDCardRecordTime(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulSeconds);

	boolean IVS_PU_SetSDKPlatformPara(ULONG ulIdentifyID, PU_PLATFORM_SDK_PARA pstSdkPlatformPara);

	// SDK certificate import.
	boolean IVS_PU_SetSdkTlsCert(ULONG ulIdentifyID, PU_SDK_TLS_CERT_UPLOAD_S pstSdkTlsCert);

	boolean IVS_PU_SetSECPara(ULONG ulIdentifyID, PU_SEC_PARA stSecPara);

	boolean IVS_PU_SetSerialPortInfo(ULONG ulIdentifyID, PU_SERIAL_PORT_PARA pstSerialPortPara);

	// Enable or disable SFTP.
	boolean IVS_PU_SetSFTPEnable(NativeLong ulIdentifyID, PU_SFTP_ENABLE_PARA pstPara);

	boolean IVS_PU_SetSIMPhoneNum(ULONG ulIdentifyID, PU_SIM_PHONE_NUM_S pstPara);

	// Set and obtain basic parameters of the slave camera.
	public boolean IVS_PU_SetSlaveDeviceBasePara(WinDef.ULONG ulIdentifyID, PU_SLAVE_DEVICE_INFO_S pstPara);

	// Set and obtain the slave camera enabling parameter.
	public boolean IVS_PU_SetSlaveDeviceEnablePara(WinDef.ULONG ulIdentifyID, PU_SLAVE_DEVICE_ENABLE_S pstPara);

	// Set and obtain the ONVIF parameters of the slave camera.
	public boolean IVS_PU_SetSlaveDeviceOnvifPara(WinDef.ULONG ulIdentifyID, PU_SLAVE_ONVIF_PARAM_S pstSlaveOnvifPara);

	// Set and obtain the RTSP parameters of the slave camera.
	public boolean IVS_PU_SetSlaveDeviceRtspPara(WinDef.ULONG ulIdentifyID, PU_SLAVE_RTSP_PARAM_S pstSlaveRtspPara);

	boolean IVS_PU_SetSlowShutterMode(ULONG ulIdentifyID, ULONG ulChannelId, WinDef.BOOL bEnable);

	boolean IVS_PU_SetSMTPConfig(NativeLong ulIdentifyID, SMTP_CONFIG_INFO pstSMTPConfig);

	// Set the detailed snapshot parameter or ISP parameter of the micro checkpoint
	// camera.
	boolean IVS_PU_SetSnapshotParticularPara(ULONG ulIdentifyID, PU_SNAPSHOT_PARTICULAR_PARA_S pstSnapshotPara);

	// Snapshot quality parameters
	boolean IVS_PU_SetSnapshotQuality(ULONG ulIdentifyID, PU_SNAPSHOT_QUAILTY_PARA pstSnapshotQuality);

	// Snapshot resolution parameters
	boolean IVS_PU_SetSnapshotResolution(ULONG ulIdentifyID, PU_SNAPSHOT_RESOLUTION_PARA pstSnapshotRes);

	// Snapshot retrans enable
	boolean IVS_PU_SetSnapshotRetransPara(ULONG ulIdentifyID, PU_SNAPSHOT_RETRANS_PARA pstSnapshotRetrans);

	// Set the snapshot storage space.
	boolean IVS_PU_SetSnapshotSpace(ULONG ulIdentifyID, PU_SNAPSHOT_SPACE stSnapshotSpace);

	// Set scheduled snapshot.
	boolean IVS_PU_SetSnapshotTiming(ULONG ulIdentifyID, PU_SNAPSHOT_TIMING_PARA stSnapshotTiming);

	boolean IVS_PU_SetSnmpCommunityList(ULONG ulIdentifyID, PU_SNMP_COMMUNITY_LIST pstCommunityList);

	boolean IVS_PU_SetSnmpCommunityListEx(ULONG ulIdentifyID, PU_SNMP_COMMUNITY_LIST_EX pstCommunityList);

	boolean IVS_PU_SetSnmpTrapList(ULONG ulIdentifyID, PU_SNMP_TRAP_LIST pstTrapList);

	boolean IVS_PU_SetSnmpUserInfo(ULONG ulIdentifyID, PU_SNMPV3_USER_LIST pstUserMgmtInfo);

	// Set Sound Switch
	boolean IVS_PU_SetSoundSwitch(ULONG ulIdentifyID, ULONG ulRealHandle, WinDef.BOOL bEnable); // ------->Num.286

	// Enable or disable SSH.
	boolean IVS_PU_SetSSHEnable(NativeLong ulIdentifyID, PU_SSH_ENABLE_PARA pstPara);

	// set device stream function params
	// enPURecordStream & enPlatRecordStream -> C Type:PU_STREAM_TYPE
	boolean IVS_PU_SetStreamFunctionPara(ULONG ulIdentifyID, ULONG ulChannelId, int enPURecordStream,
			int enPlatRecordStream);

	// set device stream layer code mode
	// enStreamType -> c Type:PU_STREAM_TYPE
	boolean IVS_PU_SetStreamLayerCodeMode(ULONG ulIdentifyID, ULONG ulChannelId, int enStreamType, WinDef.BOOL bEnable);

	// Set stream profiles.
	// enStreamProfile -> C type:PU_STREAM_PROFILE_MODE
	boolean IVS_PU_SetStreamProfile(NativeLong ulIdentifyID, NativeLong ulChannelId, int enStreamProfile);

	boolean IVS_PU_SetSupplementLightPara(ULONG ulIdentifyID, PU_SUPPLEMENT_LIGHT_INFO_S pstSupplementLightInfo);

	// device TCP Accelerate Parameter
	boolean IVS_PU_SetTCPAcceleratePara(ULONG ulIdentifyID, PU_TCP_ACCELERATE_PARA pstTcpAcceleratePara);

	boolean IVS_PU_SetTrafficDomeAlgParams(ULONG ulIdentifyID, PU_TD_ALG_PARAMS pstAlgParams);

	boolean IVS_PU_SetTrafficDomeAlgParamsV2(ULONG ulIdentifyID, PU_TD_ALG_PARAMSV2 pstAlgParams);

	boolean IVS_PU_SetTrafficDomeIllegalIntelligentParams(ULONG ulIdentifyID,
			PU_TD_TRAFFIC_DOME_ILLEGAL_INTELLIGENT_PARAMS pstTDomeIllegalIntelligentParams);

	boolean IVS_PU_SetTrafficDomeManualDetectionParams(ULONG ulIdentifyID,
			PU_TD_MANUAL_DETECTION_PARAMS pstManualDecetionParams);

	boolean IVS_PU_SetTrafficDomeManualDetectionParamsV2(ULONG ulIdentifyID,
			PU_TD_MANUAL_DETECTION_PARAMSV2 pstManualDecetionParams);

	// Set the manual detection screen position of the traffic PTZ dome camera.
	boolean IVS_PU_SetTrafficDomeManualDetectionPos(ULONG ulIdentifyID, PU_TD_MANUAL_DETECTION_POSITION pstPosParams);

	boolean IVS_PU_SetTrafficDomeSceneAppParams(ULONG ulIdentifyID, PU_TD_SCENE_APP_PARAMS pstSceneAppParams);

	boolean IVS_PU_SetTrafficDomeSceneAppParamsV2(ULONG ulIdentifyID, PU_TD_SCENE_APP_PARAMSV2 pstSceneAppParams);

	boolean IVS_PU_SetTrafficDomeSceneBaseParams(ULONG ulIdentifyID, PU_TD_SCENE_BASE_PARAMS pstSceneBaseParams);

	// Set the scheduled lock parameter of the traffic PTZ dome camera.
	boolean IVS_PU_SetTrafficDomeTimingLockParam(ULONG ulIdentifyID, PU_TD_TIMING_LOCK_PARAMS pstTimingLockPara);

	boolean IVS_PU_SetTrafficDomeTourPlanParams(ULONG ulIdentifyID, PU_TD_TOUR_PLAN_PARAMS pstTourPlanParams);

	// Set the unlock parameter of the traffic PTZ dome camera.
	boolean IVS_PU_SetTrafficDomeUlockParam(ULONG ulIdentifyID, PU_TD_UNLOCK_PARAMS_S pstUlockPara);

	boolean IVS_PU_SetTrafficShapingPara(ULONG ulIdentifyID, PU_TRAFFIC_SHAPING_PARA pstTrafficShapingPara);

	boolean IVS_PU_SetTransparentChannelPara(ULONG ulIdentifyID, ULONG ulSerialPort, WinDef.BOOL bEnable);

	boolean IVS_PU_SetTypicalSceneMode(ULONG ulIdentifyID, ULONG ulChannelId, int enMode);

	boolean IVS_PU_SetTypicalSceneModeEx(ULONG ulIdentifyID, PU_ISP_TYPICAL_SCENE_MODE pstParam);

	boolean IVS_PU_SetTypicalScenePlan(ULONG ulIdentifyID, PU_MONTHS_PLAN pstMonthPlan);

	boolean IVS_PU_SetTypicalScenePlanV2(ULONG ulIdentifyID, PU_MONTHS_PLAN pstMonthPlan);

	// set local ip for login
	boolean IVS_PU_SetValidLocalIp(String szLocalIP);

	// Link behavior analysis with intelligent tracking.
	boolean IVS_PU_SetVALinkAT(ULONG ulIdentifyID, PU_VA_LINK_AT pstVALinkAT);

	// Vertical limit.
	boolean IVS_PU_SetVerticalLimit(ULONG ulIdentifyID, PU_VERTICAL_LIMIT_S stVerticalLimit);

	boolean IVS_PU_SetVHDAutoTrackPara(ULONG ulIdentifyID, PU_ITGT_VHD_AUTO_TRACK_PARA pstPara);

	/********* Manual object tracking *********/
	boolean IVS_PU_SetVHDManualTrackPara(ULONG ulIdentifyID, PU_ITGT_VHD_MANUAL_TRACK_PARA pstPara);

	boolean IVS_PU_SetVHDPara(ULONG ulIdentifyID, PU_VHD_PARA pstVHDPara);

	boolean IVS_PU_SetVHDParaEx(ULONG ulIdentifyID, PU_VHD_PARA_EX pstVHDPara);

	boolean IVS_PU_SetVideoDiagnosisEnableInfo(NativeLong ulIdentifyID,
			PU_VIDEODIAGNOSIS_ENABLE_PARAM pstVideoDiagnosisEnableInfo);

	boolean IVS_PU_SetVideoDisplayInfo(ULONG ulIdentifyID, PU_VIDEO_DISPLAY_INFO pstVideoDisplayInfo);

	boolean IVS_PU_SetVideoStreamInfo(ULONG ulIdentifyID, PU_VIDEO_STREAM_INFO pstVideoStreamInfo); // ------------->Num.100

	boolean IVS_PU_SetVideoStreamInfoV2(ULONG ulIdentifyID, PU_VIDEO_STREAM_INFO_V2 pstVideoStreamInfo);

	// Set the parameter for uploading images captured by a micro checkpoint camera
	// in FTP mode.
	boolean IVS_PU_SetVLPRFTPFileUploadPara(ULONG ulIdentifyID, PU_VLPR_FTP_UPLOAD_PARA_S pstFTPFileUpload);

	// Set the extended parameter for uploading images captured by a micro
	// checkpoint camera in FTP mode.
	boolean IVS_PU_SetVLPRFTPFileUploadParaV2(ULONG ulIdentifyID, PU_VLPR_FTP_UPLOAD_PARA_V2_S pstFTPFileUpload);

	/************************
	 * Intelligent Traffic System Functions
	 ******************************/
	// License plate parameters.
	boolean IVS_PU_SetVLPRPara(ULONG ulIdentifyID, PU_VLPR_PARA_S pstVLPRPara);

	boolean IVS_PU_SetVLPRParaV2(ULONG ulIdentifyID, PU_VLPR_PARA_V2_S pstVLPRPara);

	boolean IVS_PU_SetVLPRParaV3(ULONG ulIdentifyID, PU_VLPR_PARA_V3_S pstVLPRPara);

	// OSD overlay parameters (not supported by ePolice models).
	boolean IVS_PU_SetVLPRPicOSDPara(ULONG ulIdentifyID, PU_PIC_OSD_PARA_S pstVLPRPicOSDPara);

	boolean IVS_PU_SetVLPRPicOSDParaV2(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V2_S pstVLPRPicOSDPara);

	boolean IVS_PU_SetVLPRPicOSDParaV3(ULONG ulIdentifyID, PU_PIC_OSD_PARA_V3_S pstVLPRPicOSDPara);

	// Image overlay parameters.
	boolean IVS_PU_SetVLPRPicSynthesisPara(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_S pstVLPRPicSynthesisPara);

	boolean IVS_PU_SetVLPRPicSynthesisParaV2(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_V2_S pstVLPRPicSynthesisPara);

	boolean IVS_PU_SetVLPRPicSynthesisParaV3(ULONG ulIdentifyID, PU_PIC_SYNTHESIS_PARA_V3_S pstVLPRPicSynthesisPara);

	boolean IVS_PU_SetVlprTrafficStat(ULONG ulIdentifyID, PU_VLPR_TRAFFIC_STATISTICS pstPara);

	// Set backlight adaptation parameters.
	boolean IVS_PU_SetVWBacklightAdaptPara(ULONG ulIdentifyID, PU_VW_BACKLIGHT_ADAPT_PARA_S pstVWBacklightAdaptPara);

	// Set overcast adaptation parameters.
	boolean IVS_PU_SetVWFogAdaptPara(ULONG ulIdentifyID, PU_VW_FOG_ADAPT_PARA_S pstVWFogAdaptPara);

	// Set trailing (speed) adaptation parameters.
	boolean IVS_PU_SetVWSpeedAdaptPara(ULONG ulIdentifyID, PU_VW_SPEED_ADAPT_PARA_S pstVWSpeedAdaptPara);

	// device watermark params
	// enStreamType -> C type:PU_STREAM_TYPE
	boolean IVS_PU_SetWaterMark(ULONG ulIdentifyID, ULONG ulChannelId, int enStreamType, WinDef.BOOL bWaterMarkEnable);

	boolean IVS_PU_SetWDR(ULONG ulIdentifyID, ULONG ulChannelId, int enSwitchMode, ULONG ulAutoType,
			ULONG ulSensitivity);

	boolean IVS_PU_SetWebHttpMode(ULONG ulIdentifyID, int enHttpMode);

	boolean IVS_PU_SetWhiteLists(ULONG ulIdentifyID, PU_SMS_WHITE_LISTS_S pstSmsWhiteLists);

	// start master slave locate
	boolean IVS_PU_StartMasterSlaveLocate(ULONG ulIdentifyID, PU_MASTER_SLAVE_LOCATE_PARA pstMasterSlaveLocatePara);

	// Start Multicast
	public ULONG IVS_PU_StartMulticast(ULONG ulIdentifyID, String szLocalIP, ULONG ulVideoPort);

	// device snapshot
	// enSnapType -> c type:PU_SNAPSHOT_TYPE
	// enErrorCode -> c Type:PU_ERROR_CODE_E
	boolean IVS_PU_StartSnapShot(ULONG ulIdentifyID, ULONG ulChannelId, ULONG ulSnapCount, ULONG ulSnapInterval,
			int enSnapType);

	// voice broadcast
	public ULONG IVS_PU_StartVoiceBroadcast(ULONG ulIdentifyID, PU_VOICE_INFO pstVoiceBroadcastInfo);

	// voice talk back
	public ULONG IVS_PU_StartVoiceTB(ULONG ulIdentifyID, PU_VOICE_INFO pstVoiceTBInfo,
			pfVoiceTBCallBack fVoiceTBCallBack, Pointer pUsrData);

	public boolean IVS_PU_StopAllRealPlay(ULONG ulIdentifyID);

	boolean IVS_PU_StopMulticast(ULONG ulIdentifyID, ULONG ulSessionId);

	public boolean IVS_PU_StopRealPlay(ULONG ulIdentifyID, ULONG ulRealPlayHnd);

	/*******************************************************************************************************************/
	/* SDK Function Declaration */

	boolean IVS_PU_StopSaveRealData(ULONG ulIdentifyID, ULONG ulRealHandle);

	boolean IVS_PU_StopVoiceBroadcast(ULONG ulIdentifyID, ULONG ulVBHandle);

	boolean IVS_PU_StopVoiceTB(ULONG ulIdentifyID, ULONG ulVoiceTBHandle);

	// restore device default config (set IP to default IP)
	boolean IVS_PU_TotallyRestore(NativeLong ulIdentifyID, String szUserName, String szPasswd);

	// Rotate the traffic PTZ dome camera to a scene.
	boolean IVS_PU_TrafficDomeMoveToScene(ULONG ulIdentifyID, PU_TD_SCENE_MOVE_TO_SCENE pstMoveToScene);

	// Update the AES key.
	// enAesKeyModule -> c type:PU_AES_KEY_MODULE
	boolean IVS_PU_UpdateAesKey(NativeLong ulIdentifyID, int enAesKeyModule, String szUserName, String szPasswd);

	// remote upgrade device
	boolean IVS_PU_Upgrade(NativeLong ulIdentifyID, LPPU_UPGRADE_FILE_INFO_S pstFileInfo);

	// upgrade schedule callback function
	boolean IVS_PU_UpgradeWithSchedule(NativeLong ulIdentifyID, LPPU_UPGRADE_FILE_INFO_S pstFileInfo,
			pfUpgradeScheduleCallBack fScheduleCallBack, Pointer pUsrData);

	// License file import.
	boolean IVS_PU_UploadLicenceFile(ULONG ulIdentifyID, PU_LICENCE_FILE_UPLOAD_S pstLicenceFile);

	// write sdk log to file
	boolean IVS_PU_WriteLogToFile(NativeLong ulLogEnable, String szFileName, NativeLong ulFileNum,
			NativeLong ulSizePerFile);

	boolean IVS_User_FreeMetaData(PointerByReference ppstMetaData);

	/*******************************************************************************************************************/
	// eLayTwo C type is LAYER_TWO_TYPE， pstMetaData c type is PU_META_DATA
	// **pstMetaData
	boolean IVS_User_GetMetaData(Pointer pFBuffer, ULONG ulFBLength, int eLayTwo, PointerByReference pstMetaData);
}