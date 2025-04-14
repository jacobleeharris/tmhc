/* SCE CONFIDENTIAL
 * "PlayStation 2" Programmer Tool Runtime Library NTGUI package (Release 3.0 version)
 */
/*
 *	Network Setting Application Library 2
 *
 *      Copyright (C) 2002 Sony Computer Entertainment Inc.
 *	                 All Rights Reserved.
 *
 *                          ntgui2.h
 *
 *        Version       Date            Design     Log
 *  --------------------------------------------------------------------
 *        0.10
 */

#ifndef __sceNtgui2_H_
#define __sceNtgui2_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <libpkt.h>
#include <libvu0.h>

#define SCE_NTGUI2_STR_SIZE (256)
#define SCE_NTGUI2_DEFAULT_COLOR {{{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0}}}

#define SCENTGUI2_MSG_MAX               334


/* �}�E�X�̓���|�C���g */
enum
{
    SCE_NTGUI2_MOUSE_MESSAGE_TYPE__PRESS = 0,
    SCE_NTGUI2_MOUSE_MESSAGE_TYPE__RELEASE,
    SCE_NTGUI2_MOUSE_MESSAGE_TYPE__MOVE,
};

/* �\�t�g�E�F�A�L�[�{�[�h�̃L�[��Ԑݒ�^�C�v */
enum
{
    SCE_NTGUI2_ENABLE_KEY_TYPE_ENABLE_LISTED_AND_DISABLE_NOTLISTED = 0,
    SCE_NTGUI2_ENABLE_KEY_TYPE_ENABLE_ALL,
    SCE_NTGUI2_ENABLE_KEY_TYPE_DISABLE_LISTED,
};

/* �\�t�g�E�F�A�L�[�{�[�h�̓��͗��^�C�v */
enum
{
    SCE_NTGUI2_SKB_CONFIG_NAME=0,
    SCE_NTGUI2_SKB_USER_NAME,
    SCE_NTGUI2_SKB_PASSWORD,
    SCE_NTGUI2_SKB_DHCP_HOSTNAME,

    SCE_NTGUI2_SKB_IP_ADDRESS,
    SCE_NTGUI2_SKB_NETMASK,
    SCE_NTGUI2_SKB_GATEWAY,
    SCE_NTGUI2_SKB_PRIMARY_DNS,
    SCE_NTGUI2_SKB_SECONDARY_DNS,

    SCE_NTGUI2_SKB_AT_COMMAND,
    SCE_NTGUI2_SKB_OUTSIDE_LINE,
    SCE_NTGUI2_SKB_TIMEOUT,

    SCE_NTGUI2_SKB_TEL1,
    SCE_NTGUI2_SKB_TEL2,
    SCE_NTGUI2_SKB_TEL3,
};

/* �}�E�X�̃{�^����� */
enum
{
    SCE_NTGUI2_MOUSE_BUTTON_LEFT   = 1<<0,
    SCE_NTGUI2_MOUSE_BUTTON_RIGHT  = 1<<1,
    SCE_NTGUI2_MOUSE_BUTTON_MIDDLE = 1<<2,
};

/* �N���I�v�V���� */
enum
{
    SCE_NTGUI2_FLAG_USE_HDD           = 1<<0,
    SCE_NTGUI2_FLAG_USE_USB_MOUSE     = 1<<1,
    SCE_NTGUI2_FLAG_USE_USB_KB        = 1<<2,
    SCE_NTGUI2_FLAG_PAD_REVERSE       = 1<<3,
    SCE_NTGUI2_FLAG_MC_SLOT1_ONLY     = 1<<4,
    SCE_NTGUI2_FLAG_MENU_BTN_SWING    = 1<<5,
};

/* dialing_type */
enum
{
    SCE_NTGUI2_DIALINGTYPE_TONE = 0,
    SCE_NTGUI2_DIALINGTYPE_PULSE,
};

/* type */
enum
{
    SCE_NTGUI2_TYPE_ETH = 1,
    SCE_NTGUI2_TYPE_PPP,
    SCE_NTGUI2_TYPE_NIC,
};

/* phy_config */
enum
{
    SCE_NTGUI2_PHYCONFIG_AUTO  = 1,
    SCE_NTGUI2_PHYCONFIG_10    = 2,
    SCE_NTGUI2_PHYCONFIG_10_FD = 3,
    SCE_NTGUI2_PHYCONFIG_TX    = 5,
    SCE_NTGUI2_PHYCONFIG_TX_FD = 6,
};

/* dhcp */
enum
{
    SCE_NTGUI2_NOUSE_DHCP = 0,
    SCE_NTGUI2_USE_DHCP,
};

/* pppoe */
enum
{
    SCE_NTGUI2_NOUSE_PPPOE = 0,
    SCE_NTGUI2_USE_PPPOE,
};

/* �{�^���K�C�h�\�������� */
enum
{
	SCE_NTGUI2_BTNGD_STR_NULL=0,
	SCE_NTGUI2_BTNGD_STR_BACK,
	SCE_NTGUI2_BTNGD_STR_ENTER,
	SCE_NTGUI2_BTNGD_STR_INPUT,
	SCE_NTGUI2_BTNGD_STR_DELETE,
	SCE_NTGUI2_BTNGD_STR_OPSETTING,
	SCE_NTGUI2_BTNGD_STR_OPVIEW,
	SCE_NTGUI2_BTNGD_STR_NEXT,
	SCE_NTGUI2_BTNGD_STR_TRANS,
	SCE_NTGUI2_BTNGD_STR_SPACE,
	SCE_NTGUI2_BTNGD_STR_DISPLAY,
};

/* BG�̃X�N���[������ */
enum
{
	SCE_NTGUI2_BG_DIRECTION_UP    = 0,
	SCE_NTGUI2_BG_DIRECTION_LEFT  = 1,
	SCE_NTGUI2_BG_DIRECTION_DOWN  = 2,
	SCE_NTGUI2_BG_DIRECTION_RIGHT = 3,
};

/* �L�[�{�[�h�̓��̓��[�h */
enum
{
	SCE_NTGUI2_KEY_MODE_ALPHABET = 0,
	SCE_NTGUI2_KEY_MODE_RHIRAGANA,
	SCE_NTGUI2_KEY_MODE_HIRAGANA,
	SCE_NTGUI2_KEY_MODE_RKATAKANA,
	SCE_NTGUI2_KEY_MODE_KATAKANA,
};

enum
{
	SCE_NTGUI2_VIDEO_MODE_NTSC = 0,
	SCE_NTGUI2_VIDEO_MODE_PAL,
};


typedef void * (*sceNtgui2Callback_Malloc)( size_t size );
typedef void * (*sceNtgui2Callback_Memalign)( size_t align, size_t size );
typedef void * (*sceNtgui2Callback_Realloc)( void * old_ptr, size_t new_size );
typedef void   (*sceNtgui2Callback_Free)( void * ptr );
typedef void   (*sceNtgui2Callback_SKBInit)(void);
typedef void   (*sceNtgui2Callback_SKBDestroy)(void);
typedef void   (*sceNtgui2Callback_SKBOpen)( int input_type, char* str );
typedef void   (*sceNtgui2Callback_SKBClose)( char* str );
typedef void * (*sceNtgui2Callback_SKBGetVif1PktTopAddr)(void);
typedef void   (*sceNtgui2Callback_SKBGetStatus)( int * w, int * h );
typedef int    (*sceNtgui2Callback_SKBSendMouseMessage)( int type, int x, int y );
typedef void   (*sceNtgui2Callback_SKBEnableKey)( int type, unsigned char * keynames[], int keynames_size );
typedef void   (*sceNtgui2Callback_SKBEveryFrame)(void);
typedef void   (*sceNtgui2Callback_UsbKBChangeMode )(int mode);
typedef void   (*sceNtgui2Callback_UsbMouseRead )( int * delta_x, int * delta_y, int * buttons, int * wheel );
typedef void   (*sceNtgui2Callback_UsbKbRead )(void);
typedef void   (*sceNtgui2Callback_PadRead )( unsigned int * paddata );

typedef void   (*sceNtgui2Callback_SOUNDInit)(void);
typedef void   (*sceNtgui2Callback_SOUNDDestroy)(void);
typedef void   (*sceNtgui2Callback_SOUNDEveryFrame)(void);

typedef void   (*sceNtgui2Callback_SOUNDPlayLaunch)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlaySlide)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayGoSub)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayRetSub)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayPushBtn)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayFocusBtn)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayMsgboxOpen_Normal)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayMsgboxClose_Normal)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayMsgboxOpen_Wait)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayMsgboxClose_Wait)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayMsgboxOpen_Warning)(void);
typedef void   (*sceNtgui2Callback_SOUNDPlayMsgboxClose_Warning)(void);

typedef struct sceNtgui2_Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} sceNtgui2_Color_t;

typedef struct sceNtgui2_Color4 {
    sceNtgui2_Color_t aColor[4];
} sceNtgui2_Color4_t;

typedef struct sceNtgui2DefaultData {
    char address[SCE_NTGUI2_STR_SIZE];         /* IP�A�h���X                       */
    char netmask[SCE_NTGUI2_STR_SIZE];         /* �l�b�g�}�X�N                     */
    char gateway[SCE_NTGUI2_STR_SIZE];         /* �f�t�H���g���[�^�A�h���X         */
    char dns1_address[SCE_NTGUI2_STR_SIZE];    /* �v���C�}��DNS�T�[�o�A�h���X      */
    char dns2_address[SCE_NTGUI2_STR_SIZE];    /* �Z�J���_��DNS�T�[�o�A�h���X      */
    char phone_numbers1[SCE_NTGUI2_STR_SIZE];  /* �ڑ���d�b�ԍ�1                  */
    char phone_numbers2[SCE_NTGUI2_STR_SIZE];  /* �ڑ���d�b�ԍ�2                  */
    char phone_numbers3[SCE_NTGUI2_STR_SIZE];  /* �ڑ���d�b�ԍ�3                  */
    char auth_name[SCE_NTGUI2_STR_SIZE];       /* ���[�UID                         */
    char auth_key[SCE_NTGUI2_STR_SIZE];        /* �p�X���[�h                       */
    char chat_additional[SCE_NTGUI2_STR_SIZE]; /* �ǉ�AT�R�}���h                   */
    char outside_number[SCE_NTGUI2_STR_SIZE];  /* �O�����M�ԍ��ݒ�                 */
    char outside_delay[SCE_NTGUI2_STR_SIZE];   /* �O�����M�ԍ��ݒ�                 */
    char dhcp_host_name[SCE_NTGUI2_STR_SIZE];  /* DHCP�p�z�X�g��                   */
    int dialing_type;                          /* �_�C�A�����@                     */
    int phy_config;                            /* �C�[�T�l�b�g�ڑ��@��̓��샂�[�h */
    int idle_timeout;                          /* ����ؒf�ݒ�                     */
    unsigned char dhcp;                        /* DHCP�g�p�E�s�g�p                 */
    unsigned char pppoe;                       /* PPPoE�g�p�E�s�g�p                */
} sceNtgui2DefaultData_t;

typedef struct  sceNtgui2FontInfo {
	char  name[64];
	short max_ascent16;
	short max_descent16;
} sceNtgui2FontInfo_t;

typedef struct sceNtgui2FontColor1 {
	unsigned char r, g, b, a;
} sceNtgui2FontColor1_t;

typedef struct sceNtgui2FontColor4{
	sceNtgui2FontColor1_t aColor[4];
} sceNtgui2FontColor4_t;

typedef struct sceNtgui2FontRect{
	float top;
	float bottom;
	float left;
	float right;
} sceNtgui2FontRect_t;

typedef struct sceNtgui2FontCharInfo
{
	short base_x;
	short base_y;
	short l_bearing;
	short r_bearing;
	short ascent;
	short descent;
	short width;
	short kerning;
} sceNtgui2FontCharInfo_t;

typedef struct sceNtgui2FontCallback {
	float (*GetRatio)( void );
	void (*Create)( void );
	void (*Destroy)( void );
	int  (*Open)( void );
	void (*Close)( void );
	int (*GetInfo)( sceNtgui2FontInfo_t* );
	int (*GetCharInfo)( unsigned int , sceNtgui2FontCharInfo_t*  );
	int (*GetRect)( float, int , const unsigned char*, sceNtgui2FontRect_t* );
	void (*SetLocate)( int, int );
	int  (*GetLocateX)(void);
	int  (*GetLocateY)(void);
	void (*SetRGBA4)( sceNtgui2FontColor4_t* );
	void (*Flip)( void );
	sceVif1Packet* 
	(*DrawText)( float fScale, int X16, int Y16, int Pitch16,
				 int Start, int End,
				 const unsigned char *pString );
} sceNtgui2FontCallback_t;

typedef struct sceNtgui2_Arg
{
	int size;
	const char *pMessageList[SCENTGUI2_MSG_MAX];
	/* initial thread priority */
	int threadPrio;
	int videomode;
    /* �N���I�v�V���� */
    int flag;

    /* v-blank �J�n��҂Z�}�t�H */
    int _sema_vsync;

	/* semaphore used to wait for dma transfer to finish */
	int _sema_dmawait;

    /* �ǉ����̃f�t�H���g�f�[�^�ւ̃|�C���^ */
    sceNtgui2DefaultData_t *default_env_data;

    /* �������A���P�[�V���� �R�[���o�b�N�֐��|�C���^ */
    sceNtgui2Callback_Malloc               cb_malloc;
    sceNtgui2Callback_Memalign             cb_memalign;
    sceNtgui2Callback_Realloc              cb_realloc;
    sceNtgui2Callback_Free                 cb_free;

    /* �\�t�g�E�F�A�L�[�{�[�h �R�[���o�b�N�֐��|�C���^ */
    sceNtgui2Callback_SKBInit              cb_skb_init;
    sceNtgui2Callback_SKBDestroy           cb_skb_destroy;
    sceNtgui2Callback_SKBOpen              cb_skb_open;
    sceNtgui2Callback_SKBClose             cb_skb_close;
    sceNtgui2Callback_SKBGetVif1PktTopAddr cb_skb_getvif1pkttopaddr;
    sceNtgui2Callback_SKBGetStatus         cb_skb_getstatus;
    sceNtgui2Callback_SKBSendMouseMessage  cb_skb_sendmousemessage;
    sceNtgui2Callback_SKBEnableKey         cb_skb_enablekey;
    sceNtgui2Callback_SKBEveryFrame        cb_skb_everyframe;

    /* �L�[�{�[�h ���̓��[�h�؊����R�[���o�b�N�֐��|�C���^ */
    sceNtgui2Callback_UsbKBChangeMode      cb_kb_changemode;

    /* USB�}�E�X�� ���͂��󂯂�֐��ւ̃|�C���^ */
    sceNtgui2Callback_UsbMouseRead         cb_mouse_read;

    /* �p�b�h�� ���͂��󂯂�֐��ւ̃|�C���^ */
    sceNtgui2Callback_PadRead              cb_pad_read;

    /* USB�L�[�{�[�h�̓��͂��󂯂�֐��ւ̃|�C���^ */
    sceNtgui2Callback_UsbKbRead            cb_kb_read;

	/* �V�X�e���̃A�X�y�N�g��̐ݒ���g�p���Ȃ��ꍇ�̃A�X�y�N�g��̒l */
	int set_aspect;

	/* ����̐ݒ� */
	int set_language;

	/* Sound�֌W�̃R�[���o�b�N�֐��ւ̃|�C���^ */
    sceNtgui2Callback_SOUNDInit                    cb_sound_init;
	sceNtgui2Callback_SOUNDDestroy                 cb_sound_destroy;
    sceNtgui2Callback_SOUNDEveryFrame              cb_sound_everyframe;

	/* Sound */
	/* �N�� */
	sceNtgui2Callback_SOUNDPlayLaunch              cb_sound_play_launch;
	/* �y�[�W�X���C�h(�K�C�h���[�h) */
	sceNtgui2Callback_SOUNDPlaySlide               cb_sound_play_slide;
	/* �y�[�W�`�F���W(�ڍ׉�ʂȂǂɈڂ�Ƃ�) */
	sceNtgui2Callback_SOUNDPlayGoSub               cb_sound_play_gosub;
	/* �y�[�W�`�F���W(�ڍ׉�ʂȂǂ���߂�Ƃ�) */
	sceNtgui2Callback_SOUNDPlayRetSub              cb_sound_play_retsub;
	/* �v�b�V�� �{�^�� */
	sceNtgui2Callback_SOUNDPlayPushBtn             cb_sound_play_push_btn;
	/* �t�H�[�J�X�ړ� */
	sceNtgui2Callback_SOUNDPlayFocusBtn            cb_sound_play_focus_btn;
	/* ���b�Z�[�W�{�b�N�X �I�[�v�� �N���[�Y */
	sceNtgui2Callback_SOUNDPlayMsgboxOpen_Normal   cb_sound_play_msgbox_open_normal;
	sceNtgui2Callback_SOUNDPlayMsgboxClose_Normal  cb_sound_play_msgbox_close_normal;
	sceNtgui2Callback_SOUNDPlayMsgboxOpen_Wait     cb_sound_play_msgbox_open_wait;
	sceNtgui2Callback_SOUNDPlayMsgboxClose_Wait    cb_sound_play_msgbox_close_wait;
	sceNtgui2Callback_SOUNDPlayMsgboxOpen_Warning  cb_sound_play_msgbox_open_warning;
	sceNtgui2Callback_SOUNDPlayMsgboxClose_Warning cb_sound_play_msgbox_close_warning;

    /* �w�i���t�@�C�����炩��ǂݍ��ނ��߂̃p�X */
    char * str_path_bg;
    char * str_path_bg2;

	/* �w�i�̃A���t�@�̗L�� */
	int bg_has_alpha;
	int bg_has_alpha2;

	/* �w�i�X�N���[���̗L�� */
	int bg_scroll_do_flag;
	int bg_scroll_do_flag2;
	/* �w�i�̃X�N���[��������� */
	int bg_scroll_direction;
	int bg_scroll_direction2;
	/* �w�i�X�N���[���̑��x */
	int bg_scroll_speed;
	int bg_scroll_speed2;

    /* �F */
    sceNtgui2_Color4_t       color_pointer;                         /* �|�C���^ */
    sceNtgui2_Color4_t       color_pointer_center;                  /* �|�C���^�̒��� */
    sceNtgui2_Color4_t       color_pointer_select;                  /* �|�C���^�̑I�𕔕� */
    sceNtgui2_Color4_t       color_select_cursor;                   /* �I���J�[�\�� */
    sceNtgui2_Color4_t       color_decision_cursor;                 /* ����J�[�\�� */
    sceNtgui2_Color4_t       color_font;                            /* �t�H���g */
    sceNtgui2_Color4_t       color_scrollbar_slider;                /* �X�N���[���o�[�̃X���C�_�[ */
    sceNtgui2_Color4_t       color_msgbox_back;                     /* �_�C�A���O�\�����̔w�i */
    sceNtgui2_Color4_t       color_msgbox_normal_title;             /* ����_�C�A���O�̃^�C�g�� */
    sceNtgui2_Color4_t       color_msgbox_normal_button;            /* ����_�C�A���O�̃{�^�� */
    sceNtgui2_Color4_t       color_msgbox_normal_select;            /* ����_�C�A���O�̑I���{�^�� */
    sceNtgui2_Color4_t       color_msgbox_normal_bg;                /* ����_�C�A���O�̔w�i */
    sceNtgui2_Color4_t       color_msgbox_warning_title;            /* �G���[�_�C�A���O�̃^�C�g�� */
    sceNtgui2_Color4_t       color_msgbox_warning_button;           /* �G���[�_�C�A���O�̃{�^�� */
    sceNtgui2_Color4_t       color_msgbox_warning_select;           /* �G���[�_�C�A���O�̑I���{�^�� */
    sceNtgui2_Color4_t       color_msgbox_warning_bg;               /* �G���[�_�C�A���O�̔w�i */
    sceNtgui2_Color4_t       color_msgbox_wait_title;               /* �������_�C�A���O�̃^�C�g�� */
    sceNtgui2_Color4_t       color_msgbox_wait_button;              /* �������_�C�A���O�̃{�^�� */
    sceNtgui2_Color4_t       color_msgbox_wait_select;              /* �������_�C�A���O�̑I���{�^�� */
    sceNtgui2_Color4_t       color_msgbox_wait_bg;                  /* �������_�C�A���O�̔w�i */
    sceNtgui2_Color4_t       color_softkb_bg;                       /* �\�t�g�E�F�A�L�[�{�[�h�̔w�i */
    int                      color_transparency;                    /* �������p�[�c�̓����x(-5�`5 0:default) */
    sceNtgui2FontCallback_t  font_callback;                         /* �t�H���g�R�[���o�b�N�\���� */
	u_char reserved[120];
} sceNtgui2_Arg_t;

void *sceNtgui2GetErxEntries(void);

int sceNtgui2_Do( sceNtgui2_Arg_t * arg );

/* SendKBMessage �� �v�� */
enum
{
    SCE_NTGUI2_KBMSG_TYPE_SOFTKB,
    SCE_NTGUI2_KBMSG_TYPE_HARDKB,
    SCE_NTGUI2_KBMSG_TYPE_KBCMD=4,
};

/*  SoftKB */
void sceNtgui2_SendKBMessage( int type, unsigned char * keyname );

void sceNtgui2_SKB_GetClosePos(int* x, int* y);
void sceNtgui2_SKB_SetClosePos(int x, int y);
void sceNtgui2_SKB_GetOpenPos(int* x, int* y);
void sceNtgui2_SKB_SetOpenPos(int x, int y);

/*  Pointer */
void sceNtgui2_SetPointerAlpha(int alpha);
void sceNtgui2_ResetPointerAlpha( void );

void sceNtgui2_SetBtnGuide(int code4kaku, int codeBatsu, int codeMaru, int code3kaku);
void sceNtgui2_ResetBtnGuide(void);



#ifdef __cplusplus
}
#endif

#endif /* __sceNtgui2_H_ */
