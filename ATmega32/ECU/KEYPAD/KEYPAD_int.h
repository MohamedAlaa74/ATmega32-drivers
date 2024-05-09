/*
 * KEYPAD_int.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Zbook
 */

#ifndef ECU_KEYPAD_KEYPAD_INT_H_
#define ECU_KEYPAD_KEYPAD_INT_H_

/******************************includes***********************************************************/
#include "KEYPAD_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"
/******************************* macros **********************************************************/
#define KEYPAD_ROWS   4
#define KEYPAD_COLUMNS   4

/*************************************************************************************************/
/*************************data type declarations***********************************************************/

typedef struct {
	DIO_pin_config_t  keypad_row_pins[KEYPAD_ROWS];
	DIO_pin_config_t    keypad_columns_pins[KEYPAD_COLUMNS];
}KEYPAD_t;
/***************************************************************************************************/


/*****************************function declarations***********************************************/
/*Name:			KEYPAD_init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType KEYPAD_init (void);
/*********************************************************************************************************/



/* name   KEYPAD_read_value
 * description   read value of keypad buttons
 * arguments     first =>  KEYPAD : pointer to the SEGMANT pin configurations
 * 				 second => value  : pointer to return value
 * return        (E_OK,E_NOK)
 */
Std_ReturnType KEYPAD_read_value(const KEYPAD_t *KEYPAD,u8 *value);
/***********************************************************************************************************************/


#endif /* ECU_KEYPAD_KEYPAD_INT_H_ */
