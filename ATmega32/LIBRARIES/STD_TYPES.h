/*
 * STD_TYPES.h
 *
 *  Created on: Jan 8, 2024
 *      Author: Mohamed ALAA
 */

#ifndef LIBRARIES_STD_TYPES_H_
#define LIBRARIES_STD_TYPES_H_
#include <string.h>
typedef    				void (*func_ptr)(void);

typedef unsigned char 			u8;
typedef unsigned short int 		u16;
typedef unsigned long int 		u32;
typedef signed char 			s8;
typedef signed short int 		s16;
typedef signed long int 		s32;
typedef float					f32;
typedef u8    		 Std_ReturnType;


/* macros */
//#define NULL	        ((void*)0)
#define STD_HIGH 0x01
#define STD_LOW 0x00

#define STD_ON 0x01
#define STD_OFF 0x00

#define STD_ACTIVE 0x01
#define STD_IDLE 0x00


#define E_NOK    0x00
#define E_OK     0x01
#define ZERO_INIT     0










#endif /* LIBRARIES_STD_TYPES_H_ */
