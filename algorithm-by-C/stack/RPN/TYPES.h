/*
 ************************************************************************
 *File Name: TYPES.h
 *Author   : 
 *Date     : 2017年04月07日 星期五 18时57分06秒
 *Brief    : 
 ************************************************************************
 */
#ifndef _TYPES_H
#define _TYPES_H

#ifdef __cplusplus
 extern "C" {
#endif


typedef unsigned char       UCHAR8;                   /* defined for unsigned 8-bits integer variable   ÎÞ·ûºÅ8Î»ÕûÐÍ±äÁ¿  */
typedef signed   char       SCHAR8;                    /* defined for signed 8-bits integer variableÓÐ·ûºÅ8Î»ÕûÐÍ±äÁ¿  */
typedef unsigned short      USHORT16;                  /* defined for unsigned 16-bits integer variable     ÎÞ·ûºÅ16Î»ÕûÐÍ±äÁ¿ */
typedef signed   short      SSHORT16;                   /* defined for signed 16-bits integer variable      ÓÐ·ûºÅ16Î»ÕûÐÍ±äÁ¿ */
typedef unsigned int        UINT32;                  /* defined for unsigned 32-bits integer variable   ÎÞ·ûºÅ32Î»ÕûÐÍ±äÁ¿ */
typedef int                 SINT32;                   /* defined for signed 32-bits integer variable        ÓÐ·ûºÅ32Î»ÕûÐÍ±äÁ¿ */
typedef float               FP32;                    /* single precision floating point variable (32bits)*/
typedef double              DB64;                    /* double precision floating point variable (64bits) */

typedef enum
{
    FALSE = 0,
    TRUE = 1

}BOOL;





#ifdef __cplusplus
}
#endif


#endif
