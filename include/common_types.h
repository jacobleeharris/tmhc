#ifndef _TMHC_COMMON_TYPES_H
#define _TMHC_COMMON_TYPES_H

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

struct _plane {
    _fvector3 norm;
    float d;
};

#endif
