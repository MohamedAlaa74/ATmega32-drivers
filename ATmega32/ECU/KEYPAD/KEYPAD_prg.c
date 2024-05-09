/*
 * KEYPAD_prg.c
 *
 *  Created on: Jan 16, 2024
 *      Author: Zbook
 */
/****************************includes*************************************************************/
#include "KEYPAD_int.h"

/****************************data types definitions***********************************************/

static const u8 KEYPAD_values [KEYPAD_ROWS][KEYPAD_COLUMNS] = {
																{'7','8','9','/'},
																{'4','5','6','*'},
																{'1','2','3','-'},
																{'#','0','=','+'},
															};
/*****************************function definitions ***********************************************/
/*Name:			KEYPAD_init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */
Std_ReturnType KEYPAD_init(void) {

	Std_ReturnType return_value = E_OK;

	DIO_init();

	return return_value;

}
/*********************************************************************************************************/
/* name   KEYPAD_read_value
 * description   read value of keypad buttons
 * arguments     first =>  KEYPAD : pointer to the SEGMANT pin configurations
 * 				 second => value  : pointer to return value
 * return        (E_OK,E_NOK)
 */
Std_ReturnType KEYPAD_read_value(const KEYPAD_t *KEYPAD,u8 *value){
	Std_ReturnType return_value = E_NOK;
	u8 l_rows_counter = ZERO_INIT, l_columns_counter = ZERO_INIT, l_counter = ZERO_INIT;
	u8 column_logic ;
	if ((NULL==KEYPAD)||(NULL == value)){
		return_value = E_NOK;
	}
	else {
		for (l_rows_counter = ZERO_INIT;l_rows_counter<KEYPAD_ROWS;l_rows_counter++){
			for (l_counter = ZERO_INIT;l_counter<KEYPAD_ROWS;l_counter++){
				return_value =  DIO_write_pin_logic(&(KEYPAD->keypad_row_pins[l_counter]),DIO_HIGH);
			}
			return_value = DIO_write_pin_logic(&(KEYPAD->keypad_row_pins[l_rows_counter]),DIO_LOW);
			for (l_columns_counter = ZERO_INIT;l_columns_counter<KEYPAD_COLUMNS;l_columns_counter++){
					return_value =	DIO_read_pin_logic(&(KEYPAD->keypad_columns_pins[l_columns_counter]),&column_logic);
					if (DIO_LOW == column_logic){
						*value = KEYPAD_values [l_rows_counter][l_columns_counter];
					}
				}
		}


	}



return return_value;
}
/***********************************************************************************************************************/
