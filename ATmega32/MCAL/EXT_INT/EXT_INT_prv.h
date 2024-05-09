/*
 * G_INT_prv.h
 *
 *  Created on: Jan 22, 2024
 *      Author: Zbook
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRV_H_
#define MCAL_EXT_INT_EXT_INT_PRV_H_
/*************************macros*******************************************/
#define EXT_INT_u8_GICR_REG   (*((volatile EXT_INT_u8_GICR_BITS_t*)   0x5B ))
#define EXT_INT_u8_MCUCR_REG  (*((volatile EXT_INT_u8_MCUCR_BITS_t*)  0x55 ))
#define EXT_INT_u8_MCUCSR_REG (*((volatile EXT_INT_u8_MCUCSR_BITS_t*) 0x54 ))
#define EXT_INT_u8_GIFR_REG   (*((volatile EXT_INT_u8_GIFR_BITS_t*)   0x5A ))

/*MCUCR*/
#define ISC11_Bit   3
#define ISC10_Bit   2
#define ISC01_Bit   1
#define ISC00_Bit   0

/* MCUCSR */
#define ISC2_Bit    6

/* GICR */
#define INT1_Bit    7
#define INT0_Bit    6
#define INT2_Bit    5

/* GIFR */
#define INTF1_Bit   7
#define INTF0_Bit   6
#define INTF2_Bit   5
/*************************************************************************************************/
typedef union {
	struct {
		u8 IVCE    : 1;
		u8 IVSEL   : 1;
		u8         : 3;
		u8 INT2    : 1;
		u8 INT0    : 1;
		u8 INT1    : 1;
	};
	u8 EXT_INT_u8_GICR;
}EXT_INT_u8_GICR_BITS_t;


typedef union {
	struct {
		u8 ISC00   : 1;
		u8 ISC01   : 1;
		u8 ISC10   : 1;
		u8 ISC11   : 1;
		u8         : 4;
	};
	u8 EXT_INT_u8_MCUCR;
}EXT_INT_u8_MCUCR_BITS_t;


typedef union {
	struct {
		u8 	       : 5;
		u8 ISC2    : 1;
		u8         : 2;
	};
	u8 EXT_INT_u8_MCUCSR;
}EXT_INT_u8_MCUCSR_BITS_t;

typedef union {
	struct {
		u8         : 5;
		u8 INTF2   : 1;
		u8 INTF0   : 1;
		u8 INTF1   : 1;
	};
	u8 EXT_INT_u8_GIFR;
}EXT_INT_u8_GIFR_BITS_t;

#endif /* MCAL_EXT_INT_EXT_INT_PRV_H_ */
