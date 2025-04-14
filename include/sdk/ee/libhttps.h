/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library libhttps package (Release 3.0.2 version)
 */
/* 
 *                      Emotion Engine Library
 *                          Version 1.00
 *                           Shift-JIS
 *
 *      Copyright (C) 2001-2002 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                      <libhttps - libhttps.h>
 *                     <header for https library>
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *       1.00           Nov,05,2001     komaki      first version
 */

#ifndef _LIBHTTPS_H
#define _LIBHTTPS_H
 
#ifdef __cplusplus
extern "C" {
#endif

#include <libhttp.h>

/* flags for HTTPS connection */
#define sceHTTPSFlagServerVerify	0x01
#define sceHTTPSFlagClientVerify	0x02
#define sceHTTPSFlagCNCheck			0x04
#define sceHTTPSFlagNotAfterCheck	0x08
#define sceHTTPSFlagNotBeforeCheck	0x10
#define sceHTTPSFlagUseLocalCertForExpirationCheck	0x20
#define sceHTTPSFlagEnableDebugPrint	0x40

/* SSL errnum */
#define	sceHTTPSError_HANDSHAKE	-2001
#define	sceHTTPSError_IO	-2002
#define	sceHTTPSError_INTERNAL	-2003
#define	sceHTTPSError_NOTAFTER	-2004
#define	sceHTTPSError_NOTBEFORE	-2005
#define	sceHTTPSError_NOCERT	-2006
#define	sceHTTPSError_CNCHECK	-2007

/* HTTPS data */
typedef struct sceHTTPSData{
	char *ptr;
	unsigned int size;
} sceHTTPSData_t;

/* SSL version */
#define sceHTTPSSLv23	0
#define sceHTTPSSLv2	1
#define sceHTTPSSLv3	2
#define sceHTTPTLSv1	3

/* erx export */
void *sceHTTPSGetErxEntries(void);
 
/* Library initialization */
extern int sceHTTPSInit(int ssl_version, char **CA_file_list,
			const char *cert_file, const char *priv_key_file);
extern int sceHTTPSInitCertFromMemory(int ssl_version, int CA_cert_num,
	const struct sceHTTPSData *CA_list, const struct sceHTTPSData *cert,
	const struct sceHTTPSData *priv_key);
 
/* Library termination */
extern int sceHTTPSTerminate(void);
 
/* SSL error */
extern int sceHTTPGetSSLError(sceHTTPClient_t *client);

#ifdef __cplusplus
}
#endif

#endif /* _LIBHTTPS_H */
