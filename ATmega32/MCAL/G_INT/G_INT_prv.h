/*
 * G_INT_prv.h
 *
 *  Created on: Jan 22, 2024
 *      Author: Zbook
 */

#ifndef MCAL_G_INT_G_INT_PRV_H_
#define MCAL_G_INT_G_INT_PRV_H_

/********************************* registers addresses macros **************************************/

#define G_INT_u8_SREG_REG   (*((volatile G_INT_u8_SREG_BITS_t*)  0x5F ))
/********************************macros***********************************************************/
#define G_INT_u8_SREG_I_BIT   7
/***********************************************************************************************/
/************************* data type declarations ***********************************************************/
typedef union {
	struct {
		u8       :     7;
		u8 I_bit :     1;
	};
	    u8 G_INT_u8_SREG ;
}G_INT_u8_SREG_BITS_t;




#endif /* MCAL_G_INT_G_INT_PRV_H_ */
