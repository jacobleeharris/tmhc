/* SCE CONFIDENTIAL
"PlayStation 2" Programmer Tool Runtime Library libeyetoy Version 1.4
*/
/* 
 *     -  EyeToy USB Camera (for PlayStation 2) Library (libeyetoy) -
 *
 *                         Version 1.3
 *
 *      Copyright (C) 2004 Sony Computer Entertainment Inc
 *                        All Rights Reserved.
 *
 *                    libeyetoy - libeyetoy.h
 *    Header for EyeToy USB Camera (for PlayStation 2) Library (libeyetoy)
 *  
 *       Version        Date            Design      Log
 *  --------------------------------------------------------------------
 *      1.0             10-29-03        rmarks      the first version
 *      1.2             02-18-04        bwiggins
 *    - Added sceEyeToyGetAttribute()
 *    - Removed compression_level from sceEyeToyIpuHeader 
 *    - Corrected num_frames offset in sceEyeToyIpuHeader
 *    - Modified comments for default buffer sizes
 *
 */
#ifndef _LIBEYETOY_H_
#define _LIBEYETOY_H_

#include <eetypes.h>
#include <eeregs.h>
#include <sceerrno.h>

typedef enum
{
    SCE_EYETOY_GAIN=0,          /* 0..255 default auto */
    SCE_EYETOY_REDBLUEGAIN,     /* 0..255 default auto */
    SCE_EYETOY_SATURATION,      /* 0..255, default 0xa4 */
    SCE_EYETOY_EXPOSURE,        /* 0..255 default auto */
    SCE_EYETOY_BRIGHTNESS,      /* 0..255 default 0x60 */
    SCE_EYETOY_AEC,             /* automatic exposure control, 0 or 1, default 1 */
    SCE_EYETOY_AGC,             /* automatic gain control, 0 or 1, default 1 */
    SCE_EYETOY_AWB,             /* automatic white balance, 0 or 1, default 1 */
    SCE_EYETOY_ABC,             /* automatic brightness, 0 or 1, default 0 */
    SCE_EYETOY_LED,             /* arg1=frames on, arg2=frames off, default 0,0 */
    SCE_EYETOY_AUDIOGAIN,       /* 0..7, default 5 */
    SCE_EYETOY_QS,              /* minimum compression level 0..30, default 0 */
    SCE_EYETOY_NONZEROCOEFFS,   /* lum 0..64,chrom 0..64 default 40,40 */
    SCE_EYETOY_YUVFLAG,         /* 0 for YCbCr, 1 for YUV */
    SCE_EYETOY_JPEGFLAG,        /* 0 for IPU stream, 1 for JPEG stream */
    SCE_EYETOY_BACKLIGHTCOMP,   /* 0 for no backlight comp, 1 for backlight comp */
    SCE_EYETOY_MIRRORFLAG,      /* 1 for mirror-style, 0 for camera style, def 1 */
    SCE_EYETOY_MEASUREDQS,       /* The measured compression level */
	SCE_EYETOY_MAKESTEADYCOUNT  /* The number of latent frames that pass before the most recent frame becomes the curront frame*/
} sceEyeToyAttribute;

typedef enum
{
    SCE_EYETOY_STANDARDRES=0, /* 320x240 */
    SCE_EYETOY_LOWRES,        /* 160x112 */
    SCE_EYETOY_HIGHRES,       /* 640x480 */
} sceEyeToyResolution;

typedef enum
{
    SCE_EYETOY_NOCAMERA,       /* camera is not currently plugged in */
    SCE_EYETOY_CLOSED,         /* video stream has not been opened */
    SCE_EYETOY_STOPPED,        /* video stream is initialized but not streaming */
    SCE_EYETOY_STARTED,        /* video is streaming */
} sceEyeToyState;

/* IPU stream identifier */
#define IPU_HDR_STRING 0x6d757069 

/* IPU bitstream header description */
typedef struct
{
    unsigned int ipu_identifier;  /* Always IPU_HDR_STRING */
    int bytesize;                 /* Total bitstream size */
    unsigned short width;         /* Width of the frame in pixels */
    unsigned short height;        /* Height of the frame in pixels */
    unsigned short num_frames;    /* Always 1 for USB camera */
    unsigned short reserved;      /* Reserved area */
} sceEyeToyIpuHeader;

/* Equivalent of sceEyeToyGetBufferSize() (for defining static buffer)
   Use same values as cmd line args to IOP module
   When using default parameters: SCE_EYETOY_GETBUFFERSIZE( 20, 4 ) */
#define SCE_EYETOY_GETBUFFERSIZE( framesize, micsize ) (((framesize)*1024*3) + ((micsize)*256*2))

/* Equivalent of sceEyeToyGetMaxVideoSize() (for defining static buffer)
   Use same value as cmd line arg to IOP module
   When using default parameters: SCE_EYETOY_GETMAXVIDEOSIZE( 20 ) */
#define SCE_EYETOY_GETMAXVIDEOSIZE( framesize ) ((framesize)*1024)

/* Equivalent of sceEyeToyGetMaxAudioSize() (for defining static buffer)
   Use same value as cmd line arg to IOP module
   When using default parameters: SCE_EYETOY_GETMAXAUDIOSIZE( 4 ) */
#define SCE_EYETOY_GETMAXAUDIOSIZE( micsize )   ((micsize)*256)

#if defined(__LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif

int sceEyeToyInit(void); 
int sceEyeToyGetMicSampleRate(void);
int sceEyeToyEnd(void); 
int sceEyeToyOpen(int camnum, sceEyeToyResolution res, int framerate, char *data);
int sceEyeToyClose(int camnum);
int sceEyeToyStartCamera(int camnum);
int sceEyeToyStopCamera(int camnum);
int sceEyeToyStartMic(int camnum);
int sceEyeToyStopMic(int camnum);
sceEyeToyState sceEyeToyGetState(int camnum);
int sceEyeToyGetAttribute(int camnum, sceEyeToyAttribute attrib, int *arg1, int *arg2 );
int sceEyeToySetAttribute(int camnum, sceEyeToyAttribute attrib, int arg1, int arg2 );
int sceEyeToyGetBufferSize( void );
int sceEyeToyGetMaxVideoSize( void );
int sceEyeToyGetMaxAudioSize( void );
int sceEyeToyGetFramerate(int camnum);
int sceEyeToyGetWidth(int camnum);
int sceEyeToyGetHeight(int camnum);
int sceEyeToyReadCamera(int camnum, void* data);
int sceEyeToyReadMic(int camnum, void* data, int max_bytes);
int sceEyeToySetUsbLoad(int load); 
int sceEyeToyGetUsbLoad(void);
void *sceEyeToyGetErxEntries(void);

#if defined(__LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
}
#endif

#endif /* _LIBEYETOY_H */
