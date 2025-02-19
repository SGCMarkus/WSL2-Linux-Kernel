/* SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause */
/* Copyright(c) 2007 - 2012 Realtek Corporation. */

#ifndef _WIFI_H_
#define _WIFI_H_

#include <linux/ieee80211.h>

#ifdef BIT
/* error	"BIT define occurred earlier elsewhere!\n" */
#undef BIT
#endif
#define BIT(x)	(1 << (x))

#define WLAN_ETHHDR_LEN		14
#define WLAN_HDR_A3_LEN		24
#define WLAN_HDR_A3_QOS_LEN	26
#define WLAN_SSID_MAXLEN	32

enum WIFI_FRAME_TYPE {
	WIFI_CTRL_TYPE =	(BIT(2)),
	WIFI_DATA_TYPE =	(BIT(3)),
	WIFI_QOS_DATA_TYPE	= (BIT(7)|BIT(3)),	/*  QoS Data */
};

enum WIFI_FRAME_SUBTYPE {
	/*  below is for mgt frame */
	WIFI_ASSOCREQ       = (0 | IEEE80211_FTYPE_MGMT),
	WIFI_ASSOCRSP       = (BIT(4) | IEEE80211_FTYPE_MGMT),
	WIFI_REASSOCREQ     = (BIT(5) | IEEE80211_FTYPE_MGMT),
	WIFI_REASSOCRSP     = (BIT(5) | BIT(4) | IEEE80211_FTYPE_MGMT),
	WIFI_PROBEREQ       = (BIT(6) | IEEE80211_FTYPE_MGMT),
	WIFI_PROBERSP       = (BIT(6) | BIT(4) | IEEE80211_FTYPE_MGMT),
	WIFI_BEACON         = (BIT(7) | IEEE80211_FTYPE_MGMT),
	WIFI_ATIM           = (BIT(7) | BIT(4) | IEEE80211_FTYPE_MGMT),
	WIFI_DISASSOC       = (BIT(7) | BIT(5) | IEEE80211_FTYPE_MGMT),
	WIFI_AUTH           = (BIT(7) | BIT(5) | BIT(4) | IEEE80211_FTYPE_MGMT),
	WIFI_DEAUTH         = (BIT(7) | BIT(6) | IEEE80211_FTYPE_MGMT),
	WIFI_ACTION         = (BIT(7) | BIT(6) | BIT(4) | IEEE80211_FTYPE_MGMT),

	/*  below is for control frame */
	WIFI_PSPOLL         = (BIT(7) | BIT(5) | WIFI_CTRL_TYPE),
	WIFI_RTS            = (BIT(7) | BIT(5) | BIT(4) | WIFI_CTRL_TYPE),
	WIFI_CTS            = (BIT(7) | BIT(6) | WIFI_CTRL_TYPE),
	WIFI_ACK            = (BIT(7) | BIT(6) | BIT(4) | WIFI_CTRL_TYPE),
	WIFI_CFEND          = (BIT(7) | BIT(6) | BIT(5) | WIFI_CTRL_TYPE),
	WIFI_CFEND_CFACK    = (BIT(7) | BIT(6) | BIT(5) | BIT(4) |
	WIFI_CTRL_TYPE),

	/*  below is for data frame */
	WIFI_DATA           = (0 | WIFI_DATA_TYPE),
	WIFI_DATA_CFACK     = (BIT(4) | WIFI_DATA_TYPE),
	WIFI_DATA_CFPOLL    = (BIT(5) | WIFI_DATA_TYPE),
	WIFI_DATA_CFACKPOLL = (BIT(5) | BIT(4) | WIFI_DATA_TYPE),
	WIFI_DATA_NULL      = (BIT(6) | WIFI_DATA_TYPE),
	WIFI_CF_ACK         = (BIT(6) | BIT(4) | WIFI_DATA_TYPE),
	WIFI_CF_POLL        = (BIT(6) | BIT(5) | WIFI_DATA_TYPE),
	WIFI_CF_ACKPOLL     = (BIT(6) | BIT(5) | BIT(4) | WIFI_DATA_TYPE),
	WIFI_QOS_DATA_NULL	= (BIT(6) | WIFI_QOS_DATA_TYPE),
};

enum WIFI_REASON_CODE	{
	_RSON_RESERVED_			= 0,
	_RSON_UNSPECIFIED_		= 1,
	_RSON_AUTH_NO_LONGER_VALID_	= 2,
	_RSON_DEAUTH_STA_LEAVING_	= 3,
	_RSON_INACTIVITY_		= 4,
	_RSON_UNABLE_HANDLE_		= 5,
	_RSON_CLS2_			= 6,
	_RSON_CLS3_			= 7,
	_RSON_DISAOC_STA_LEAVING_	= 8,
	_RSON_ASOC_NOT_AUTH_		= 9,

	/*  WPA reason */
	_RSON_INVALID_IE_		= 13,
	_RSON_MIC_FAILURE_		= 14,
	_RSON_4WAY_HNDSHK_TIMEOUT_	= 15,
	_RSON_GROUP_KEY_UPDATE_TIMEOUT_	= 16,
	_RSON_DIFF_IE_			= 17,
	_RSON_MLTCST_CIPHER_NOT_VALID_	= 18,
	_RSON_UNICST_CIPHER_NOT_VALID_	= 19,
	_RSON_AKMP_NOT_VALID_		= 20,
	_RSON_UNSUPPORT_RSNE_VER_	= 21,
	_RSON_INVALID_RSNE_CAP_		= 22,
	_RSON_IEEE_802DOT1X_AUTH_FAIL_	= 23,

	/* belowing are Realtek definition */
	_RSON_PMK_NOT_AVAILABLE_	= 24,
	_RSON_TDLS_TEAR_TOOFAR_		= 25,
	_RSON_TDLS_TEAR_UN_RSN_		= 26,
};

enum WIFI_STATUS_CODE {
	_STATS_SUCCESSFUL_		= 0,
	_STATS_FAILURE_			= 1,
	_STATS_CAP_FAIL_		= 10,
	_STATS_NO_ASOC_			= 11,
	_STATS_OTHER_			= 12,
	_STATS_NO_SUPP_ALG_		= 13,
	_STATS_OUT_OF_AUTH_SEQ_		= 14,
	_STATS_CHALLENGE_FAIL_		= 15,
	_STATS_AUTH_TIMEOUT_		= 16,
	_STATS_UNABLE_HANDLE_STA_	= 17,
	_STATS_RATE_FAIL_		= 18,
};

/* entended */
/* IEEE 802.11b */
#define WLAN_STATUS_ASSOC_DENIED_NOSHORT 19
#define WLAN_STATUS_ASSOC_DENIED_NOPBCC 20
#define WLAN_STATUS_ASSOC_DENIED_NOAGILITY 21
/* IEEE 802.11h */
#define WLAN_STATUS_SPEC_MGMT_REQUIRED 22
#define WLAN_STATUS_PWR_CAPABILITY_NOT_VALID 23
#define WLAN_STATUS_SUPPORTED_CHANNEL_NOT_VALID 24
/* IEEE 802.11g */
#define WLAN_STATUS_ASSOC_DENIED_NO_SHORT_SLOT_TIME 25
#define WLAN_STATUS_ASSOC_DENIED_NO_ER_PBCC 26
#define WLAN_STATUS_ASSOC_DENIED_NO_DSSS_OFDM 27
/* IEEE 802.11w */
#define WLAN_STATUS_ASSOC_REJECTED_TEMPORARILY 30
#define WLAN_STATUS_ROBUST_MGMT_FRAME_POLICY_VIOLATION 31
/* IEEE 802.11i */
#define WLAN_STATUS_INVALID_IE 40
#define WLAN_STATUS_GROUP_CIPHER_NOT_VALID 41
#define WLAN_STATUS_PAIRWISE_CIPHER_NOT_VALID 42
#define WLAN_STATUS_AKMP_NOT_VALID 43
#define WLAN_STATUS_UNSUPPORTED_RSN_IE_VERSION 44
#define WLAN_STATUS_INVALID_RSN_IE_CAPAB 45
#define WLAN_STATUS_CIPHER_REJECTED_PER_POLICY 46
#define WLAN_STATUS_TS_NOT_CREATED 47
#define WLAN_STATUS_DIRECT_LINK_NOT_ALLOWED 48
#define WLAN_STATUS_DEST_STA_NOT_PRESENT 49
#define WLAN_STATUS_DEST_STA_NOT_QOS_STA 50
#define WLAN_STATUS_ASSOC_DENIED_LISTEN_INT_TOO_LARGE 51
/* IEEE 802.11r */
#define WLAN_STATUS_INVALID_FT_ACTION_FRAME_COUNT 52
#define WLAN_STATUS_INVALID_PMKID 53
#define WLAN_STATUS_INVALID_MDIE 54
#define WLAN_STATUS_INVALID_FTIE 55

enum WIFI_REG_DOMAIN {
	DOMAIN_FCC	= 1,
	DOMAIN_IC	= 2,
	DOMAIN_ETSI	= 3,
	DOMAIN_SPA	= 4,
	DOMAIN_FRANCE	= 5,
	DOMAIN_MKK	= 6,
	DOMAIN_ISRAEL	= 7,
	DOMAIN_MKK1	= 8,
	DOMAIN_MKK2	= 9,
	DOMAIN_MKK3	= 10,
	DOMAIN_MAX
};

#define _TO_DS_		BIT(8)
#define _FROM_DS_	BIT(9)
#define _MORE_FRAG_	BIT(10)
#define _RETRY_		BIT(11)
#define _PWRMGT_	BIT(12)
#define _MORE_DATA_	BIT(13)
#define _PRIVACY_	BIT(14)
#define _ORDER_		BIT(15)

#define SetToDs(pbuf)	\
	*(__le16 *)(pbuf) |= cpu_to_le16(_TO_DS_)

#define GetToDs(pbuf)	(((*(__le16 *)(pbuf)) & cpu_to_le16(_TO_DS_)) != 0)

#define ClearToDs(pbuf)	\
	*(__le16 *)(pbuf) &= (~cpu_to_le16(_TO_DS_))

#define SetFrDs(pbuf)	\
	*(__le16 *)(pbuf) |= cpu_to_le16(_FROM_DS_)

#define GetFrDs(pbuf)	(((*(__le16 *)(pbuf)) & cpu_to_le16(_FROM_DS_)) != 0)

#define ClearFrDs(pbuf)	\
	*(__le16 *)(pbuf) &= (~cpu_to_le16(_FROM_DS_))

#define get_tofr_ds(pframe)	((GetToDs(pframe) << 1) | GetFrDs(pframe))

#define SetMFrag(pbuf)	\
	*(__le16 *)(pbuf) |= cpu_to_le16(_MORE_FRAG_)

#define ClearMFrag(pbuf)	\
	*(__le16 *)(pbuf) &= (~cpu_to_le16(_MORE_FRAG_))

#define SetRetry(pbuf)	\
	*(__le16 *)(pbuf) |= cpu_to_le16(_RETRY_)

#define GetRetry(pbuf)	(((*(__le16 *)(pbuf)) & cpu_to_le16(_RETRY_)) != 0)

#define ClearRetry(pbuf)	\
	*(__le16 *)(pbuf) &= (~cpu_to_le16(_RETRY_))

#define SetPwrMgt(pbuf)	\
	*(__le16 *)(pbuf) |= cpu_to_le16(_PWRMGT_)

#define GetPwrMgt(pbuf)	(((*(__le16 *)(pbuf)) & cpu_to_le16(_PWRMGT_)) != 0)

#define ClearPwrMgt(pbuf)	\
	*(__le16 *)(pbuf) &= (~cpu_to_le16(_PWRMGT_))

#define SetMData(pbuf)	\
	*(__le16 *)(pbuf) |= cpu_to_le16(_MORE_DATA_)

#define ClearMData(pbuf)	\
	*(__le16 *)(pbuf) &= (~cpu_to_le16(_MORE_DATA_))

#define SetPrivacy(pbuf)	\
	*(__le16 *)(pbuf) |= cpu_to_le16(_PRIVACY_)

#define GetPrivacy(pbuf)					\
	(((*(__le16 *)(pbuf)) & cpu_to_le16(_PRIVACY_)) != 0)

#define ClearPrivacy(pbuf)	\
	*(__le16 *)(pbuf) &= (~cpu_to_le16(_PRIVACY_))

#define GetFrameType(pbuf)				\
	(le16_to_cpu(*(__le16 *)(pbuf)) & (BIT(3) | BIT(2)))

#define SetFrameType(pbuf, type)	\
	do {	\
		*(unsigned short *)(pbuf) &= __constant_cpu_to_le16(~(BIT(3) | BIT(2))); \
		*(unsigned short *)(pbuf) |= __constant_cpu_to_le16(type); \
	} while (0)

#define GetFrameSubType(pbuf)	(le16_to_cpu(*(__le16 *)(pbuf)) & (BIT(7) |\
	 BIT(6) | BIT(5) | BIT(4) | BIT(3) | BIT(2)))

#define SetFrameSubType(pbuf, type) \
	do {    \
		*(__le16 *)(pbuf) &= cpu_to_le16(~(BIT(7) | BIT(6) |	\
		 BIT(5) | BIT(4) | BIT(3) | BIT(2))); \
		*(__le16 *)(pbuf) |= cpu_to_le16(type); \
	} while (0)

#define GetSequence(pbuf)			\
	(le16_to_cpu(*(__le16 *)((size_t)(pbuf) + 22)) >> 4)

#define GetFragNum(pbuf)			\
	(le16_to_cpu(*(__le16 *)((size_t)(pbuf) + 22)) & 0x0f)

#define GetTupleCache(pbuf)			\
	(cpu_to_le16(*(unsigned short *)((size_t)(pbuf) + 22)))

#define SetFragNum(pbuf, num) \
	do {    \
		*(unsigned short *)((size_t)(pbuf) + 22) = \
			((*(unsigned short *)((size_t)(pbuf) + 22)) &	\
			le16_to_cpu(~(0x000f))) | \
			cpu_to_le16(0x0f & (num));     \
	} while (0)

#define SetSeqNum(pbuf, num) \
	do {    \
		*(__le16 *)((size_t)(pbuf) + 22) = \
			((*(__le16 *)((size_t)(pbuf) + 22)) & cpu_to_le16((unsigned short)0x000f)) | \
			cpu_to_le16((unsigned short)(0xfff0 & (num << 4))); \
	} while (0)

#define SetDuration(pbuf, dur) \
	*(__le16 *)((size_t)(pbuf) + 2) = cpu_to_le16(0xffff & (dur))

#define SetPriority(pbuf, tid)	\
	*(__le16 *)(pbuf) |= cpu_to_le16(tid & 0xf)

#define GetPriority(pbuf)	((le16_to_cpu(*(__le16 *)(pbuf))) & 0xf)

#define SetEOSP(pbuf, eosp)	\
		*(__le16 *)(pbuf) |= cpu_to_le16((eosp & 1) << 4)

#define SetAckpolicy(pbuf, ack)	\
	*(__le16 *)(pbuf) |= cpu_to_le16((ack & 3) << 5)

#define GetAckpolicy(pbuf) (((le16_to_cpu(*(__le16 *)pbuf)) >> 5) & 0x3)

#define GetAMsdu(pbuf) (((le16_to_cpu(*(__le16 *)pbuf)) >> 7) & 0x1)

#define SetAMsdu(pbuf, amsdu)	\
	*(__le16 *)(pbuf) |= cpu_to_le16((amsdu & 1) << 7)

#define GetAid(pbuf)	(le16_to_cpu(*(__le16 *)((size_t)(pbuf) + 2)) & 0x3fff)

#define GetTid(pbuf)	(le16_to_cpu(*(__le16 *)((size_t)(pbuf) +	\
			(((GetToDs(pbuf)<<1) | GetFrDs(pbuf)) == 3 ?	\
			30 : 24))) & 0x000f)

#define GetAddr1Ptr(pbuf)	((unsigned char *)((size_t)(pbuf) + 4))

#define GetAddr2Ptr(pbuf)	((unsigned char *)((size_t)(pbuf) + 10))

#define GetAddr3Ptr(pbuf)	((unsigned char *)((size_t)(pbuf) + 16))

#define GetAddr4Ptr(pbuf)	((unsigned char *)((size_t)(pbuf) + 24))

static inline int IS_MCAST(unsigned char *da)
{
	if ((*da) & 0x01)
		return true;
	else
		return false;
}

static inline unsigned char *get_da(unsigned char *pframe)
{
	unsigned char	*da;
	unsigned int to_fr_ds = (GetToDs(pframe) << 1) | GetFrDs(pframe);

	switch (to_fr_ds) {
	case 0x00:	/*  ToDs=0, FromDs=0 */
		da = GetAddr1Ptr(pframe);
		break;
	case 0x01:	/*  ToDs=0, FromDs=1 */
		da = GetAddr1Ptr(pframe);
		break;
	case 0x02:	/*  ToDs=1, FromDs=0 */
		da = GetAddr3Ptr(pframe);
		break;
	default:	/*  ToDs=1, FromDs=1 */
		da = GetAddr3Ptr(pframe);
		break;
	}
	return da;
}

static inline unsigned char *get_sa(unsigned char *pframe)
{
	unsigned char	*sa;
	unsigned int	to_fr_ds = (GetToDs(pframe) << 1) | GetFrDs(pframe);

	switch (to_fr_ds) {
	case 0x00:	/*  ToDs=0, FromDs=0 */
		sa = GetAddr2Ptr(pframe);
		break;
	case 0x01:	/*  ToDs=0, FromDs=1 */
		sa = GetAddr3Ptr(pframe);
		break;
	case 0x02:	/*  ToDs=1, FromDs=0 */
		sa = GetAddr2Ptr(pframe);
		break;
	default:	/*  ToDs=1, FromDs=1 */
		sa = GetAddr4Ptr(pframe);
		break;
	}
	return sa;
}

static inline unsigned char *get_hdr_bssid(unsigned char *pframe)
{
	unsigned char	*sa;
	unsigned int	to_fr_ds = (GetToDs(pframe) << 1) | GetFrDs(pframe);

	switch (to_fr_ds) {
	case 0x00:	/*  ToDs=0, FromDs=0 */
		sa = GetAddr3Ptr(pframe);
		break;
	case 0x01:	/*  ToDs=0, FromDs=1 */
		sa = GetAddr2Ptr(pframe);
		break;
	case 0x02:	/*  ToDs=1, FromDs=0 */
		sa = GetAddr1Ptr(pframe);
		break;
	case 0x03:	/*  ToDs=1, FromDs=1 */
		sa = GetAddr1Ptr(pframe);
		break;
	default:
		sa = NULL; /*  */
		break;
	}
	return sa;
}

static inline int IsFrameTypeCtrl(unsigned char *pframe)
{
	if (WIFI_CTRL_TYPE == GetFrameType(pframe))
		return true;
	else
		return false;
}
/*-----------------------------------------------------------------------------
			Below is for the security related definition
------------------------------------------------------------------------------*/
#define _RESERVED_FRAME_TYPE_		0
#define _SKB_FRAME_TYPE_		2
#define _PRE_ALLOCMEM_			1
#define _PRE_ALLOCHDR_			3
#define _PRE_ALLOCLLCHDR_		4
#define _PRE_ALLOCICVHDR_		5
#define _PRE_ALLOCMICHDR_		6

#define _SIFSTIME_				\
	(priv->pmib->dot11BssType.net_work_type = 10)
#define _ACKCTSLNG_		14	/* 14 bytes long, including crclng */
#define _CRCLNG_		4

#define _ASOCREQ_IE_OFFSET_	4	/*  excluding wlan_hdr */
#define	_ASOCRSP_IE_OFFSET_	6
#define _REASOCREQ_IE_OFFSET_	10
#define _REASOCRSP_IE_OFFSET_	6
#define _PROBEREQ_IE_OFFSET_	0
#define	_PROBERSP_IE_OFFSET_	12
#define _AUTH_IE_OFFSET_	6
#define _DEAUTH_IE_OFFSET_	0
#define _BEACON_IE_OFFSET_	12
#define _PUBLIC_ACTION_IE_OFFSET_	8

#define _FIXED_IE_LENGTH_	_BEACON_IE_OFFSET_

#define _SSID_IE_		0
#define _SUPPORTEDRATES_IE_	1
#define _DSSET_IE_		3
#define _TIM_IE_		5
#define _IBSS_PARA_IE_		6
#define _COUNTRY_IE_		7
#define _CHLGETXT_IE_		16
#define _SUPPORTED_CH_IE_	36
#define _CH_SWTICH_ANNOUNCE_	37	/* Secondary Channel Offset */
#define _RSN_IE_2_		48
#define _SSN_IE_1_		221
#define _ERPINFO_IE_		42
#define _EXT_SUPPORTEDRATES_IE_	50

#define _HT_CAPABILITY_IE_	45
#define _FTIE_			55
#define _TIMEOUT_ITVL_IE_	56
#define _SRC_IE_		59
#define _HT_EXTRA_INFO_IE_	61
#define _HT_ADD_INFO_IE_	61 /* _HT_EXTRA_INFO_IE_ */
#define _WAPI_IE_		68

#define	EID_BSSCoexistence	72 /*  20/40 BSS Coexistence */
#define	EID_BSSIntolerantChlReport	73
#define _RIC_Descriptor_IE_	75

#define _LINK_ID_IE_		101
#define _CH_SWITCH_TIMING_	104
#define _PTI_BUFFER_STATUS_	106
#define _EXT_CAP_IE_		127
#define _VENDOR_SPECIFIC_IE_	221

#define	_RESERVED47_		47

/* ---------------------------------------------------------------------------
					Below is the fixed elements...
-----------------------------------------------------------------------------*/
#define _AUTH_ALGM_NUM_		2
#define _AUTH_SEQ_NUM_		2
#define _BEACON_ITERVAL_	2
#define _CAPABILITY_		2
#define _CURRENT_APADDR_	6
#define _LISTEN_INTERVAL_	2
#define _RSON_CODE_		2
#define _ASOC_ID_		2
#define _STATUS_CODE_		2
#define _TIMESTAMP_		8

#define cap_ESS		BIT(0)
#define cap_IBSS	BIT(1)
#define cap_CFPollable	BIT(2)
#define cap_CFRequest	BIT(3)
#define cap_Privacy	BIT(4)
#define cap_ShortPremble BIT(5)
#define cap_PBCC	BIT(6)
#define cap_ChAgility	BIT(7)
#define cap_SpecMgmt	BIT(8)
#define cap_QoSi	BIT(9)
#define cap_ShortSlot	BIT(10)

/*-----------------------------------------------------------------------------
				Below is the definition for 802.11i / 802.1x
------------------------------------------------------------------------------*/
#define _IEEE8021X_MGT_			1	/*  WPA */
#define _IEEE8021X_PSK_			2	/*  WPA with pre-shared key */

/*-----------------------------------------------------------------------------
				Below is the definition for WMM
------------------------------------------------------------------------------*/
#define _WMM_IE_Length_				7  /*  for WMM STA */
#define _WMM_Para_Element_Length_		24

/*-----------------------------------------------------------------------------
				Below is the definition for 802.11n
------------------------------------------------------------------------------*/

#define SetOrderBit(pbuf)	\
	do	{	\
		*(unsigned short *)(pbuf) |= cpu_to_le16(_ORDER_); \
	} while (0)

#define GetOrderBit(pbuf)			\
	(((*(unsigned short *)(pbuf)) & le16_to_cpu(_ORDER_)) != 0)

/**
 * struct rtw_ieee80211_bar - HT Block Ack Request
 *
 * This structure refers to "HT BlockAckReq" as
 * described in 802.11n draft section 7.2.1.7.1
 */
struct rtw_ieee80211_bar {
	__le16 frame_control;
	__le16 duration;
	unsigned char ra[ETH_ALEN];
	unsigned char ta[ETH_ALEN];
	__le16 control;
	__le16 start_seq_num;
} __packed;

/**
 * struct ieee80211_ht_cap - HT additional information
 *
 * This structure refers to "HT information element" as
 * described in 802.11n draft section 7.3.2.53
 */
struct ieee80211_ht_addt_info {
	unsigned char	control_chan;
	unsigned char	ht_param;
	__le16	operation_mode;
	__le16	stbc_param;
	unsigned char	basic_set[16];
} __packed;

struct HT_caps_element {
	union {
		struct {
			__le16	HT_caps_info;
			unsigned char	AMPDU_para;
			unsigned char	MCS_rate[16];
			__le16	HT_ext_caps;
			__le16	Beamforming_caps;
			unsigned char	ASEL_caps;
		} HT_cap_element;
		unsigned char HT_cap[26];
	} u;
} __packed;

struct HT_info_element {
	unsigned char	primary_channel;
	unsigned char	infos[5];
	unsigned char	MCS_rate[16];
} __packed;

struct AC_param {
	unsigned char		ACI_AIFSN;
	unsigned char		CW;
	__le16	TXOP_limit;
} __packed;

struct WMM_para_element {
	unsigned char		QoS_info;
	unsigned char		reserved;
	struct AC_param	ac_param[4];
} __packed;

struct ADDBA_request {
	unsigned char	action_code;
	unsigned char	dialog_token;
	__le16	BA_para_set;
	__le16	BA_timeout_value;
	__le16	BA_starting_seqctrl;
} __packed;

#define MAX_AMPDU_FACTOR_64K	3

/* Spatial Multiplexing Power Save Modes */
#define WLAN_HT_CAP_SM_PS_STATIC	0
#define WLAN_HT_CAP_SM_PS_DYNAMIC	1
#define WLAN_HT_CAP_SM_PS_INVALID	2
#define WLAN_HT_CAP_SM_PS_DISABLED	3

#define OP_MODE_PURE                    0
#define OP_MODE_MAY_BE_LEGACY_STAS      1
#define OP_MODE_20MHZ_HT_STA_ASSOCED    2
#define OP_MODE_MIXED                   3

#define HT_INFO_HT_PARAM_SECONDARY_CHNL_OFF_MASK	((u8) BIT(0) | BIT(1))
#define HT_INFO_HT_PARAM_SECONDARY_CHNL_ABOVE		((u8) BIT(0))
#define HT_INFO_HT_PARAM_SECONDARY_CHNL_BELOW		((u8) BIT(0) | BIT(1))
#define HT_INFO_HT_PARAM_REC_TRANS_CHNL_WIDTH		((u8) BIT(2))
#define HT_INFO_HT_PARAM_RIFS_MODE			((u8) BIT(3))
#define HT_INFO_HT_PARAM_CTRL_ACCESS_ONLY		((u8) BIT(4))
#define HT_INFO_HT_PARAM_SRV_INTERVAL_GRANULARITY	((u8) BIT(5))

#define HT_INFO_OPERATION_MODE_OP_MODE_MASK	\
		((u16) (0x0001 | 0x0002))
#define HT_INFO_OPERATION_MODE_OP_MODE_OFFSET		0
#define HT_INFO_OPERATION_MODE_NON_GF_DEVS_PRESENT	((u8) BIT(2))
#define HT_INFO_OPERATION_MODE_TRANSMIT_BURST_LIMIT	((u8) BIT(3))
#define HT_INFO_OPERATION_MODE_NON_HT_STA_PRESENT	((u8) BIT(4))

/*	===============WPS Section=============== */
/*	For WPSv1.0 */
#define WPSOUI					0x0050f204
/*	WPS attribute ID */
#define WPS_ATTR_VER1				0x104A
#define WPS_ATTR_SIMPLE_CONF_STATE		0x1044
#define WPS_ATTR_RESP_TYPE			0x103B
#define WPS_ATTR_UUID_E				0x1047
#define WPS_ATTR_MANUFACTURER			0x1021
#define WPS_ATTR_MODEL_NAME			0x1023
#define WPS_ATTR_MODEL_NUMBER			0x1024
#define WPS_ATTR_SERIAL_NUMBER			0x1042
#define WPS_ATTR_PRIMARY_DEV_TYPE		0x1054
#define WPS_ATTR_SEC_DEV_TYPE_LIST		0x1055
#define WPS_ATTR_DEVICE_NAME			0x1011
#define WPS_ATTR_CONF_METHOD			0x1008
#define WPS_ATTR_RF_BANDS			0x103C
#define WPS_ATTR_DEVICE_PWID			0x1012
#define WPS_ATTR_REQUEST_TYPE			0x103A
#define WPS_ATTR_ASSOCIATION_STATE		0x1002
#define WPS_ATTR_CONFIG_ERROR			0x1009
#define WPS_ATTR_VENDOR_EXT			0x1049
#define WPS_ATTR_SELECTED_REGISTRAR		0x1041

/*	Value of WPS attribute "WPS_ATTR_DEVICE_NAME */
#define WPS_MAX_DEVICE_NAME_LEN			32

/*	Value of WPS Request Type Attribute */
#define WPS_REQ_TYPE_ENROLLEE_INFO_ONLY		0x00
#define WPS_REQ_TYPE_ENROLLEE_OPEN_8021X	0x01
#define WPS_REQ_TYPE_REGISTRAR			0x02
#define WPS_REQ_TYPE_WLAN_MANAGER_REGISTRAR	0x03

/*	Value of WPS Response Type Attribute */
#define WPS_RESPONSE_TYPE_INFO_ONLY	0x00
#define WPS_RESPONSE_TYPE_8021X		0x01
#define WPS_RESPONSE_TYPE_REGISTRAR	0x02
#define WPS_RESPONSE_TYPE_AP		0x03

/*	Value of WPS WiFi Simple Configuration State Attribute */
#define WPS_WSC_STATE_NOT_CONFIG	0x01
#define WPS_WSC_STATE_CONFIG		0x02

/*	Value of WPS Version Attribute */
#define WPS_VERSION_1			0x10

/*	Value of WPS Configuration Method Attribute */
#define WPS_CONFIG_METHOD_FLASH		0x0001
#define WPS_CONFIG_METHOD_ETHERNET	0x0002
#define WPS_CONFIG_METHOD_LABEL		0x0004
#define WPS_CONFIG_METHOD_DISPLAY	0x0008
#define WPS_CONFIG_METHOD_E_NFC		0x0010
#define WPS_CONFIG_METHOD_I_NFC		0x0020
#define WPS_CONFIG_METHOD_NFC		0x0040
#define WPS_CONFIG_METHOD_PBC		0x0080
#define WPS_CONFIG_METHOD_KEYPAD	0x0100
#define WPS_CONFIG_METHOD_VPBC		0x0280
#define WPS_CONFIG_METHOD_PPBC		0x0480
#define WPS_CONFIG_METHOD_VDISPLAY	0x2008
#define WPS_CONFIG_METHOD_PDISPLAY	0x4008

/*	Value of Category ID of WPS Primary Device Type Attribute */
#define WPS_PDT_CID_DISPLAYS		0x0007
#define WPS_PDT_CID_MULIT_MEDIA		0x0008
#define WPS_PDT_CID_RTK_WIDI		WPS_PDT_CID_MULIT_MEDIA

/*	Value of Sub Category ID of WPS Primary Device Type Attribute */
#define WPS_PDT_SCID_MEDIA_SERVER	0x0005
#define WPS_PDT_SCID_RTK_DMP		WPS_PDT_SCID_MEDIA_SERVER

/*	Value of Device Password ID */
#define WPS_DPID_P			0x0000
#define WPS_DPID_USER_SPEC		0x0001
#define WPS_DPID_MACHINE_SPEC		0x0002
#define WPS_DPID_REKEY			0x0003
#define WPS_DPID_PBC			0x0004
#define WPS_DPID_REGISTRAR_SPEC		0x0005

/*	Value of WPS RF Bands Attribute */
#define WPS_RF_BANDS_2_4_GHZ		0x01
#define WPS_RF_BANDS_5_GHZ		0x02

/*	Value of WPS Association State Attribute */
#define WPS_ASSOC_STATE_NOT_ASSOCIATED		0x00
#define WPS_ASSOC_STATE_CONNECTION_SUCCESS	0x01
#define WPS_ASSOC_STATE_CONFIGURATION_FAILURE	0x02
#define WPS_ASSOC_STATE_ASSOCIATION_FAILURE	0x03
#define WPS_ASSOC_STATE_IP_FAILURE		0x04

/*	=====================P2P Section===================== */
/*	For P2P */
#define	P2POUI					0x506F9A09

/*	P2P Attribute ID */
#define	P2P_ATTR_STATUS				0x00
#define	P2P_ATTR_MINOR_REASON_CODE		0x01
#define	P2P_ATTR_CAPABILITY			0x02
#define	P2P_ATTR_DEVICE_ID			0x03
#define	P2P_ATTR_GO_INTENT			0x04
#define	P2P_ATTR_CONF_TIMEOUT			0x05
#define	P2P_ATTR_LISTEN_CH			0x06
#define	P2P_ATTR_GROUP_BSSID			0x07
#define	P2P_ATTR_EX_LISTEN_TIMING		0x08
#define	P2P_ATTR_INTENTED_IF_ADDR		0x09
#define	P2P_ATTR_MANAGEABILITY			0x0A
#define	P2P_ATTR_CH_LIST			0x0B
#define	P2P_ATTR_NOA				0x0C
#define	P2P_ATTR_DEVICE_INFO			0x0D
#define	P2P_ATTR_GROUP_INFO			0x0E
#define	P2P_ATTR_GROUP_ID			0x0F
#define	P2P_ATTR_INTERFACE			0x10
#define	P2P_ATTR_OPERATING_CH			0x11
#define	P2P_ATTR_INVITATION_FLAGS		0x12

/*	Value of Status Attribute */
#define	P2P_STATUS_SUCCESS				0x00
#define	P2P_STATUS_FAIL_INFO_UNAVAILABLE		0x01
#define	P2P_STATUS_FAIL_INCOMPATIBLE_PARAM		0x02
#define	P2P_STATUS_FAIL_LIMIT_REACHED			0x03
#define	P2P_STATUS_FAIL_INVALID_PARAM			0x04
#define	P2P_STATUS_FAIL_REQUEST_UNABLE			0x05
#define	P2P_STATUS_FAIL_PREVOUS_PROTO_ERR		0x06
#define	P2P_STATUS_FAIL_NO_COMMON_CH			0x07
#define	P2P_STATUS_FAIL_UNKNOWN_P2PGROUP		0x08
#define	P2P_STATUS_FAIL_BOTH_GOINTENT_15		0x09
#define	P2P_STATUS_FAIL_INCOMPATIBLE_PROVSION		0x0A
#define	P2P_STATUS_FAIL_USER_REJECT			0x0B

/*	Value of Inviation Flags Attribute */
#define	P2P_INVITATION_FLAGS_PERSISTENT			BIT(0)

#define	DMP_P2P_DEVCAP_SUPPORT	(P2P_DEVCAP_SERVICE_DISCOVERY | \
				P2P_DEVCAP_CLIENT_DISCOVERABILITY | \
				P2P_DEVCAP_CONCURRENT_OPERATION | \
				P2P_DEVCAP_INVITATION_PROC)

#define	DMP_P2P_GRPCAP_SUPPORT	(P2P_GRPCAP_INTRABSS)

/*	Value of Device Capability Bitmap */
#define	P2P_DEVCAP_SERVICE_DISCOVERY		BIT(0)
#define	P2P_DEVCAP_CLIENT_DISCOVERABILITY	BIT(1)
#define	P2P_DEVCAP_CONCURRENT_OPERATION		BIT(2)
#define	P2P_DEVCAP_INFRA_MANAGED		BIT(3)
#define	P2P_DEVCAP_DEVICE_LIMIT			BIT(4)
#define	P2P_DEVCAP_INVITATION_PROC		BIT(5)

/*	Value of Group Capability Bitmap */
#define	P2P_GRPCAP_GO				BIT(0)
#define	P2P_GRPCAP_PERSISTENT_GROUP		BIT(1)
#define	P2P_GRPCAP_GROUP_LIMIT			BIT(2)
#define	P2P_GRPCAP_INTRABSS			BIT(3)
#define	P2P_GRPCAP_CROSS_CONN			BIT(4)
#define	P2P_GRPCAP_PERSISTENT_RECONN		BIT(5)
#define	P2P_GRPCAP_GROUP_FORMATION		BIT(6)

/*	P2P Public Action Frame (Management Frame) */
#define	P2P_PUB_ACTION_ACTION			0x09

/*	P2P Public Action Frame Type */
#define	P2P_GO_NEGO_REQ				0
#define	P2P_GO_NEGO_RESP			1
#define	P2P_GO_NEGO_CONF			2
#define	P2P_INVIT_REQ				3
#define	P2P_INVIT_RESP				4
#define	P2P_DEVDISC_REQ				5
#define	P2P_DEVDISC_RESP			6
#define	P2P_PROVISION_DISC_REQ			7
#define	P2P_PROVISION_DISC_RESP			8

/*	P2P Action Frame Type */
#define	P2P_NOTICE_OF_ABSENCE			0
#define	P2P_PRESENCE_REQUEST			1
#define	P2P_PRESENCE_RESPONSE			2
#define	P2P_GO_DISC_REQUEST			3

#define	P2P_MAX_PERSISTENT_GROUP_NUM		10

#define	P2P_PROVISIONING_SCAN_CNT		3

#define	P2P_WILDCARD_SSID_LEN			7

/* default value, used when: (1)p2p disabed or (2)p2p enabled
 * but only do 1 scan phase */
#define	P2P_FINDPHASE_EX_NONE		0
/*  used when p2p enabled and want to do 1 scan phase and
 *  P2P_FINDPHASE_EX_MAX-1 find phase */
#define	P2P_FINDPHASE_EX_FULL		1
#define	P2P_FINDPHASE_EX_SOCIAL_FIRST	(P2P_FINDPHASE_EX_FULL+1)
#define	P2P_FINDPHASE_EX_MAX		4
#define	P2P_FINDPHASE_EX_SOCIAL_LAST	P2P_FINDPHASE_EX_MAX

/* 5 seconds timeout for sending the provision discovery request */
#define	P2P_PROVISION_TIMEOUT		5000
/* 3 seconds timeout for sending the prov disc request concurrent mode */
#define	P2P_CONCURRENT_PROVISION_TIME	3000
/* 5 seconds timeout for receiving the group negotiation response */
#define	P2P_GO_NEGO_TIMEOUT		5000
/* 3 seconds timeout for sending the negotiation request under concurrent mode */
#define	P2P_CONCURRENT_GO_NEGO_TIME	3000
/* 100ms */
#define	P2P_TX_PRESCAN_TIMEOUT		100
/* 5 seconds timeout for sending the invitation request */
#define	P2P_INVITE_TIMEOUT		5000
/* 3 seconds timeout for sending the invitation request under concurrent mode */
#define	P2P_CONCURRENT_INVITE_TIME	3000
/* 25 seconds timeout to reset the scan channel (based on channel plan) */
#define	P2P_RESET_SCAN_CH		25000
#define	P2P_MAX_INTENT			15

#define	P2P_MAX_NOA_NUM			2

/*	WPS Configuration Method */
#define	WPS_CM_NONE			0x0000
#define	WPS_CM_LABEL			0x0004
#define	WPS_CM_DISPLYA			0x0008
#define	WPS_CM_EXTERNAL_NFC_TOKEN	0x0010
#define	WPS_CM_INTEGRATED_NFC_TOKEN	0x0020
#define	WPS_CM_NFC_INTERFACE		0x0040
#define	WPS_CM_PUSH_BUTTON		0x0080
#define	WPS_CM_KEYPAD			0x0100
#define	WPS_CM_SW_PUHS_BUTTON		0x0280
#define	WPS_CM_HW_PUHS_BUTTON		0x0480
#define	WPS_CM_SW_DISPLAY_P		0x2008
#define	WPS_CM_LCD_DISPLAY_P		0x4008

enum P2P_ROLE {
	P2P_ROLE_DISABLE = 0,
	P2P_ROLE_DEVICE = 1,
	P2P_ROLE_CLIENT = 2,
	P2P_ROLE_GO = 3
};

enum P2P_STATE {
	P2P_STATE_NONE = 0,			/* P2P disable */
	/* P2P had enabled and do nothing */
	P2P_STATE_IDLE = 1,
	P2P_STATE_LISTEN = 2,			/* In pure listen state */
	P2P_STATE_SCAN = 3,			/* In scan phase */
	/* In the listen state of find phase */
	P2P_STATE_FIND_PHASE_LISTEN = 4,
	/* In the search state of find phase */
	P2P_STATE_FIND_PHASE_SEARCH = 5,
	/* In P2P provisioning discovery */
	P2P_STATE_TX_PROVISION_DIS_REQ = 6,
	P2P_STATE_RX_PROVISION_DIS_RSP = 7,
	P2P_STATE_RX_PROVISION_DIS_REQ = 8,
	/* Doing the group owner negoitation handshake */
	P2P_STATE_GONEGO_ING = 9,
	/* finish the group negoitation handshake with success */
	P2P_STATE_GONEGO_OK = 10,
	/* finish the group negoitation handshake with failure */
	P2P_STATE_GONEGO_FAIL = 11,
	/* receiving the P2P Inviation request and match with the profile. */
	P2P_STATE_RECV_INVITE_REQ_MATCH = 12,
	/* Doing the P2P WPS */
	P2P_STATE_PROVISIONING_ING = 13,
	/* Finish the P2P WPS */
	P2P_STATE_PROVISIONING_DONE = 14,
	/* Transmit the P2P Invitation request */
	P2P_STATE_TX_INVITE_REQ = 15,
	/* Receiving the P2P Invitation response */
	P2P_STATE_RX_INVITE_RESP_OK = 16,
	/* receiving the P2P Inviation request and dismatch with the profile. */
	P2P_STATE_RECV_INVITE_REQ_DISMATCH = 17,
	/* receiving the P2P Inviation request and this wifi is GO. */
	P2P_STATE_RECV_INVITE_REQ_GO = 18,
	/* receiving the P2P Inviation request to join an existing P2P Group. */
	P2P_STATE_RECV_INVITE_REQ_JOIN = 19,
	/* recveing the P2P Inviation response with failure */
	P2P_STATE_RX_INVITE_RESP_FAIL = 20,
	/* receiving p2p negoitation response with information is not available */
	P2P_STATE_RX_INFOR_NOREADY = 21,
	/* sending p2p negoitation response with information is not available */
	P2P_STATE_TX_INFOR_NOREADY = 22,
};

enum P2P_WPSINFO {
	P2P_NO_WPSINFO				= 0,
	P2P_GOT_WPSINFO_PEER_DISPLAY_PIN	= 1,
	P2P_GOT_WPSINFO_SELF_DISPLAY_PIN	= 2,
	P2P_GOT_WPSINFO_PBC			= 3,
};

#define	P2P_PRIVATE_IOCTL_SET_LEN		64

enum P2P_PROTO_WK_ID {
	P2P_FIND_PHASE_WK = 0,
	P2P_RESTORE_STATE_WK = 1,
	P2P_PRE_TX_PROVDISC_PROCESS_WK = 2,
	P2P_PRE_TX_NEGOREQ_PROCESS_WK = 3,
	P2P_PRE_TX_INVITEREQ_PROCESS_WK = 4,
	P2P_AP_P2P_CH_SWITCH_PROCESS_WK = 5,
	P2P_RO_CH_WK = 6,
};

enum P2P_PS_STATE {
	P2P_PS_DISABLE = 0,
	P2P_PS_ENABLE = 1,
	P2P_PS_SCAN = 2,
	P2P_PS_SCAN_DONE = 3,
	P2P_PS_ALLSTASLEEP = 4, /*  for P2P GO */
};

enum P2P_PS_MODE {
	P2P_PS_NONE = 0,
	P2P_PS_CTWINDOW = 1,
	P2P_PS_NOA	 = 2,
	P2P_PS_MIX = 3, /*  CTWindow and NoA */
};

#define IP_MCAST_MAC(mac)				\
	((mac[0] == 0x01) && (mac[1] == 0x00) && (mac[2] == 0x5e))
#define ICMPV6_MCAST_MAC(mac)				\
	((mac[0] == 0x33) && (mac[1] == 0x33) && (mac[2] != 0xff))

#endif /*  _WIFI_H_ */
