/*
 * LED_prg.c
 *
 *  Created on: Jan 12, 2024
 *      Author: Zbook
 */
#include "LED_int.h"




/*****************************function declarations***********************************************/
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType LED_pin_init (void){
Std_ReturnType return_value= E_OK;
DIO_init();
return return_value;

}
/*********************************************************************************************************/



/* name   LED_on
 * description   turn LED ON
 * arguments     first =>  LED : pointer to the LED pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType LED_on(LED_t *LED){
	DIO_pin_config_t pin_config ={ .port = LED->port, .pin=LED->pin , .direction = LED->direction, .logic = LED->logic
	};
	Std_ReturnType return_value= E_OK;
	if (LED == NULL){
		return_value = E_NOK;
	}
	else {
		//DIO_write_pin_direction(&pin_config);
		DIO_write_pin_logic(&pin_config,LED_HIGH);
	}
	return return_value;

}
/***********************************************************************************************************************/
/* name   LED_off
 * description   turn LED off
 * arguments     first =>  LED : pointer to the LED pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType LED_off (LED_t *LED){
	DIO_pin_config_t pin_config ={ .port = LED->port, .pin=LED->pin , .direction = LED->direction, .logic = LED->logic

		};
		Std_ReturnType return_value= E_OK;
		if (LED == NULL){
			return_value = E_NOK;
		}
		else {
			//DIO_write_pin_direction(&pin_config);
			DIO_write_pin_logic(&pin_config,LED_LOW);
		}
		return return_value;

	}




/****************************************************************************************************************************/
/* name   LED_toggle
 * description   toggle LED logic
 * arguments     first =>  LED   pointer to the LED pin configurations
 * return   (E_OK,E_NOK)
 */
Std_ReturnType LED_toggle (LED_t *LED){
	DIO_pin_config_t pin_config ={ .port = LED->port, .pin=LED->pin , .direction = LED->direction, .logic = LED->logic

		};
		Std_ReturnType return_value= E_OK;
		if (LED == NULL){
			return_value = E_NOK;
		}
		else {
			//DIO_write_pin_direction(&pin_config);
			DIO_toggle_pin_logic(&pin_config);
		}
		return return_value;

	}




/*****************************************************************************************************************************/
