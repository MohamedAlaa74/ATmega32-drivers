/*
 * SEGMANT_prg.c


 *
 *  Created on: Jan 16, 2024
 *      Author: MO ALAA
 */

/******************************includes***********************************************************/
#include "../SEGMANT/SEGMANT_int.h"
/******************************* macros **********************************************************/
#define SEGMANT_pin0 0
#define SEGMANT_pin1 1
#define SEGMANT_pin2 2
#define SEGMANT_pin3 3
#define SEGMANT_MAX_NUMBER 9

/*************************************************************************************************/
/*************************data type declarations***********************************************************/
/***************************************************************************************************/

/*****************************function definitions ***********************************************/

/*Name:			SEGMANT_init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */
Std_ReturnType SEGMANT_init(void) {

	Std_ReturnType return_value = E_OK;
	DIO_init();
	return return_value;
}
/*********************************************************************************************************/
/* name   SEGMANT_write_number
 * description   write number on 7 segment
 * arguments     first =>  SEGMANT : pointer to the SEGMANT pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType SEGMANT_write_number(const SEGMANT_t *SEGMANT, u8 number) {
	Std_ReturnType return_value = E_NOK;
	if ((NULL == SEGMANT)|| (number > SEGMANT_MAX_NUMBER)){
		return_value = E_NOK;
	}
	else {
		return_value = DIO_write_pin_logic(&SEGMANT->segmant_pins[SEGMANT_pin0],(number&STD_HIGH)),
		return_value = DIO_write_pin_logic(&SEGMANT->segmant_pins[SEGMANT_pin1],((number>>SEGMANT_pin1)&STD_HIGH));
		return_value = DIO_write_pin_logic(&SEGMANT->segmant_pins[SEGMANT_pin2],((number>>SEGMANT_pin2)&STD_HIGH));
		return_value = DIO_write_pin_logic(&SEGMANT->segmant_pins[SEGMANT_pin3],((number>>SEGMANT_pin3)&STD_HIGH));
	}
return return_value ;
}
/***********************************************************************************************************************/
