#ifndef _TMHC_COMMON_H
#define _TMHC_COMMON_H

#include "include_asm.h"
#include "common_types.h"
#include "common_funcs.h"

typedef char s8;
typedef short s16;
typedef int s32;
typedef long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef float f32;

#define UNK_TYPE s32
#define UNK_PTR void*
#define UNK_RET void
#define UNK_FUN_ARG void(*)(void)
#define UNK_FUN_PTR(name) void(*name)(void)
#define UNK_ARGS

#define NULL 0
#define TRUE 1
#define FALSE 0

#define ARRAYSIZEU(arr) (sizeof(arr) / sizeof(arr[0]))
#define ARRAYSIZE(arr)  (s32)(sizeof(arr) / sizeof(arr[0]))
#define CLEAR(x) { uint i; char *p = (char*)&x; for (i = 0; i < sizeof(x); i++) *p++ = 0; }

#endif /* _TMHC_COMMON_H */
