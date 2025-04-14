/* SCE CONFIDENTIAL
"PlayStation 2" Programmer Tool Runtime Library usbpspcm package Version 1.5.2
 */
/* 
 *                 USB "PSP" Communication Library
 *                        Version 1.0
 *                         Shift-JIS
 *
 *      Copyright (C) 2004 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                        libusbpspcm.h
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *       1.0            2004/09/27      khikita     Initial version
 */

#ifndef _SCE_LIBUSBPSPCM_H
#define _SCE_LIBUSBPSPCM_H

#include <sif.h>
#include <sifcmd.h>
#include <sifrpc.h>

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif

/*J �f�o�C�X�t�@�C���� */
/*E Device file name */
#define SCE_USBPSPCM_DEVNAME    "usbpspcm:"

/*J �f�o�C�X�t�@�C�����̒��� */
/*E Maximum length of device file name */
#define SCE_USBPSPCM_DEVNAME_LENGTH  16


#define USBPSPCM_CTL_CMD(x)   (('U' << 24) | ('P' << 16) | ('C' << 8) | (x))

/*J Devctl�R�}���h */
/*E Devctl command */
#define SCE_USBPSPCM_GET_ADDR      USBPSPCM_CTL_CMD(1)
#define SCE_USBPSPCM_BIND          USBPSPCM_CTL_CMD(2)
#define SCE_USBPSPCM_CANCEL_BIND   USBPSPCM_CTL_CMD(3)
/*J Ioctl�R�}���h */
/*E Ioctl command */
#define SCE_USBPSPCM_RESET         USBPSPCM_CTL_CMD(4)
#define SCE_USBPSPCM_RDWR_MODE     USBPSPCM_CTL_CMD(5)

/*J Read/Write���[�h */
/*E Read/Write mode */
#define SCE_USBPSPCM_RDWR_NORMAL     0x00
#define SCE_USBPSPCM_RDWR_RD_SEQ     0x01
#define SCE_USBPSPCM_RDWR_WR_SEQ     0x02


/*J �}����� */
/*E Connection state */
#define SCE_USBPSPCM_MAX_TITLE_LENGTH      64
typedef struct SceUsbPspcmConnect {
	int    addr;
	u_int  stat;
    u_char title[SCE_USBPSPCM_MAX_TITLE_LENGTH];
} SceUsbPspcmConnect;

typedef enum {
	SCE_USBPSPCM_DISCONNECTED,   /*J �ؒf */
                                 /*E Disconnected */
	SCE_USBPSPCM_CONNECTED       /*J �ڑ� */
                                 /*E Connected */
} SceUsbPspcmConnectStat;

/*J �ʐM�J�n�v�� */
/*E Communication start demand */
typedef struct SceUsbPspcmBind {
	int  addr;
    int  reserved;
} SceUsbPspcmBind;


/*J �v���g�^�C�v�錾 */
/*E Prototype declaration */
int sceUsbPspcmRegister(sceSifRpcFunc func);
int sceUsbPspcmUnregister(sceSifRpcFunc func);
void *sceUsbPspcmGetErxEntries(void);


#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
}
#endif

#endif /* _SCE_LIBUSBPSPCM_H */
