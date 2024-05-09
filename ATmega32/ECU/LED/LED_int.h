/*
 * LED_int.h
 *
 *  Created on: Jan 12, 2024
 *      Author: Zbook
 */

#ifndef ECU_LED_LED_INT_H_
#define ECU_LED_LED_INT_H_
/*******************************************includes******************************************************/
#include "LED_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"
/******************************* macros **********************************************************/

/*************************************************************************************************/
/*************************data type declarations***********************************************************/
typedef enum {
	LED_LOW,
	LED_HIGH
}LED_status;

typedef struct {
	u8 port		  :  2;
	u8 pin  	  :  3;
	u8 logic 	  :  1;
	u8 direction  :  1;
}LED_t;
/***************************************************************************************************/


/*****************************function declarations***********************************************/
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType LED_pin_init (void);
/*********************************************************************************************************/



/* name   LED_on
 * description   turn LED ON
 * arguments     first =>  LED : pointer to the LED pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType LED_on(LED_t *LED);
/***********************************************************************************************************************/
/* name   LED_off
 * description   turn LED off
 * arguments     first =>  LED : pointer to the LED pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType LED_off (LED_t *LED);

/****************************************************************************************************************************/
/* name   LED_toggle
 * description   toggle LED logic
 * arguments     first =>  LED   pointer to the LED pin configurations
 * return   (E_OK,E_NOK)
 */
Std_ReturnType LED_toggle (LED_t *LED);
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/





#endif /* ECU_LED_LED_INT_H_ */
