/*
 * RELAY_prg.c

 *
 *  Created on: Jan 14, 2024
 *      Author: MOhamed ALAA
 */

/***********************************************includes*********************************************************************************/
#include "RELAY_int.h"
/********************************************function definitios*********************************************/
/*Name:			RELAY_pin_init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */
Std_ReturnType RELAY_pin_init(void) {
	Std_ReturnType return_value = E_OK;
	DIO_init();
	return return_value;
}
/*********************************************************************************************************/
/* name   RELAY_on
 * description   turn RELAY ON
 * arguments     first =>  RELAY : pointer to the RELAY pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType RELAY_on(const RELAY_t *RELAY) {
	Std_ReturnType return_value = E_NOK;
	DIO_pin_config_t pin_config = {.port = RELAY->port, .pin = RELAY->pin,.logic = RELAY->status
	};
	if (NULL == RELAY){
		return_value = E_NOK;
	}
	else {

		DIO_write_pin_logic(&pin_config,DIO_HIGH);


		return_value = E_OK;
	}
	return return_value ;
}
/***********************************************************************************************************************/
/* name   RELAY_off
 * description   turn RELAY off
 * arguments     first =>  RELAY : pointer to the RELAY pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType RELAY_off(const  RELAY_t *RELAY){
	Std_ReturnType return_value = E_NOK;
		DIO_pin_config_t pin_config = {.port = RELAY->port, .pin = RELAY->pin,.logic = RELAY->status
		};
		if (NULL == RELAY){
			return_value = E_NOK;
		}
		else {

			DIO_write_pin_logic(&pin_config,DIO_LOW);


			return_value = E_OK;
		}
	return	return_value;
}
/*****************************************************************************************************************************/
