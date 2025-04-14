/* SCE CONFIDENTIAL
 "PlayStation 2" Programmer Tool Runtime Library Release 3.0.2
 */
/* 
 *                      Emotion Engine Library
 *                          Version 1.00
 *                           Shift-JIS
 *
 *      Copyright (C) 2003 Sony Computer Entertainment Inc.
 *                        All Rights Reserved.
 *
 *                       <eenet46 - eenet46.h>
 *                       <eenet general header>
 *
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *       1.00           Feb,05,2003     komaki      first version
 */

#ifndef _EENET46_H_
#define _EENET46_H_

#define EENET46

#include <libeenet.h>

#ifdef __cplusplus
extern "C" {
#endif

/* erx export */
void *sceEENet6GetErxEntries(void);

int sceEENetRtsold(const char *ifname, char *stackptr, int stacksize, int priority, int timeout);
int sceEENetGetaddrinfoTO(const char *hostname, const char *servname,
	const struct sceEENetAddrinfo *hints, struct sceEENetAddrinfo **res,
	int retrans, int retry);
int sceEENetGetnameinfoTO(const struct sceEENetSockaddr *sa,
	sceEENetSocklen_t salen, char *host, size_t hostlen, char *serv,
	size_t servlen, int flags, int retrans, int retry);

#ifdef __cplusplus
}
#endif

#endif /* _EENET46_H_ */
