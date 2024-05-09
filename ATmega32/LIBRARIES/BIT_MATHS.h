/*
 * BIT_MATHS.h
 *
 *  Created on: Jan 8, 2024
 *      Author: Mohamed ALAA
 */

#ifndef LIBRARIES_BIT_MATHS_H_
#define LIBRARIES_BIT_MATHS_H_
#define SET_BIT(REG,BIT_NUM) 			(REG|=(1<<BIT_NUM))
#define CLR_BIT(REG,BIT_NUM) 			(REG&=~(1<<BIT_NUM))
#define TGL_BIT(REG,BIT_NUM) 			(REG^=(1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM) 			((REG>>BIT_NUM)&0x01)
#define ASSIGN_BIT(REG,BIT_NUM,VALUE) 	(REG|=(VALUE<<BIT_NUM))


#define ASSIGN_REG(REG,VALUE) 			(REG|=VALUE)
#define SET_REG(REG) 					(REG=0xFF)
#define CLR_REG(REG) 					(REG=0x00)
#define GET_REG(REG)                    (REG &= 0xFF)
#define TGL_REG(REG) 			        (REG^=0xFF)


#define CONC_HELP(b7, b6, b5, b4, b3, b2, b1, b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7, b6, b5, b4, b3, b2, b1, b0)		CONC_HELP(b7, b6, b5, b4, b3, b2, b1, b0)



#endif /* LIBRARIES_BIT_MATHS_H_ */
