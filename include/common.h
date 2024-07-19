#ifndef _TMHC_COMMON
#define _TMHC_COMMON

// Common types
struct _fvector {
    float x;
    float y;
    float z;
    float w;
};

struct _fvector2 {
    float x;
    float y;
};

struct _fvector3 {
    float x;
    float y;
    float z;
};

struct _fvector4 {
    float x;
    float y;
    float z;
    float w;
};

struct _hierhead {
    unsigned int opcode: 5;
    unsigned int isRelocated: 1;
    unsigned int id2: 12;
    unsigned int id1: 14;
} __attribute__((packed));

// Temporary types
typedef float undefined4;

#endif
