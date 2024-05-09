/*
 * BTN_prg.c
 *
 *  Created on: Jan 14, 2024
 *      Author: Zbook
 */


#include "BTN_int.h"
/*****************************function declarations***********************************************/
/*Name:			BTN_init
 * Description: Initialize switch pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType BTN_init (void){
	Std_ReturnType return_value= E_OK;
	DIO_init();
	return return_value;
}
/*********************************************************************************************************/
/* name   BTN_read_state
 * description   Read switch state
 * arguments     first =>  BTN : pointer to the switch pin configurations
 * 				 Second => BTN_state : pointer to return switch stae
 * return        (E_OK,E_NOK)
 */
Std_ReturnType BTN_read_state(const BTN_t *BTN,BTN_status_t *BTN_state ){
	Std_ReturnType return_value = E_NOK;
	DIO_logic_t BTN_pin_logic = DIO_LOW;
	if ((BTN ==  NULL)||(BTN_state == NULL)){
		return_value = E_NOK;
	}
	else {
		DIO_read_pin_logic(&BTN->BTN_pin,&BTN_pin_logic);
		if (BTN_ACTIVE_HIGH == BTN->BTN_connection){
			if (DIO_LOW == BTN_pin_logic){
				*BTN_state = BTN_PRESSED;
			}
			else if (DIO_HIGH == BTN_pin_logic){
				*BTN_state = BTN_RELEASED;
			}
		}
		else if (BTN_ACTIVE_LOW == BTN->BTN_connection ){
			if (DIO_LOW == BTN_pin_logic){
							*BTN_state = BTN_RELEASED;
						}
						else if (DIO_HIGH == BTN_pin_logic){
							*BTN_state = BTN_PRESSED;
						}

		}
		else {/*nothing to do */}
		return_value = E_OK;
	}

	return return_value;
}

/***********************************************************************************************************************/
