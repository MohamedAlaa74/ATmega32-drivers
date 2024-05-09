/*
 * SEGMANT_int.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Zbook
 */

#ifndef ECU_SEGMANT_SEGMANT_INT_H_
#define ECU_SEGMANT_SEGMANT_INT_H_
/******************************includes***********************************************************/
#include "../../MCAL/DIO/DIO_int.h"
#include "../SEGMANT/SEGMANT_cfg.h"
/******************************* macros **********************************************************/
#define SEGMENT_PINS_NUMBER   4
/*************************************************************************************************/
/*************************data type declarations***********************************************************/
typedef enum {
	SEGMANT_COMMON_ANODE,
	SEGMANT_COMMON_CATHODE
}SEGMANT_type_t;

typedef struct {
	DIO_pin_config_t  segmant_pins[SEGMENT_PINS_NUMBER];
	SEGMANT_type_t    segmant_type;
}SEGMANT_t;
/***************************************************************************************************/


/*****************************function declarations***********************************************/
/*Name:			SEGMANT_init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType SEGMANT_init (void);
/*********************************************************************************************************/



/* name   SEGMANT_write_number
 * description   write number on 7 segment
 * arguments     first =>  SEGMANT : pointer to the SEGMANT pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType SEGMANT_write_number(const SEGMANT_t *SEGMANT,u8 number);
/***********************************************************************************************************************/


#endif /* ECU_SEGMANT_SEGMANT_INT_H_ */
