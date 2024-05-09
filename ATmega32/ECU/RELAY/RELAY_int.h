/*
 * RELAY_int.h
 *
 *  Created on: Jan 14, 2024
 *      Author: Zbook
 */

#ifndef ECU_RELAY_RELAY_INT_H_
#define ECU_RELAY_RELAY_INT_H_
/******************************includes****************************************************************/
#include "RELAY_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"
/******************************* macros **********************************************************/
#define  RELAY_ON_STATUS   0X01U
#define  RELAY_OFF_STATUS  0X00U
/*************************************************************************************************/
/*************************data type declarations***********************************************************/


typedef struct {
	u8 port		  :  2;
	u8 pin  	  :  3;
	u8 status 	  :  1;
}RELAY_t;
/***************************************************************************************************/


/*****************************function declarations***********************************************/
/*Name:			RELAY_pin_init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType RELAY_pin_init (void);
/*********************************************************************************************************/
/* name   RELAY_on
 * description   turn RELAY ON
 * arguments     first =>  RELAY : pointer to the RELAY pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType RELAY_on(const RELAY_t *RELAY);
/***********************************************************************************************************************/
/* name   RELAY_off
 * description   turn RELAY off
 * arguments     first =>  LED : pointer to the RELAY pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType RELAY_off (const RELAY_t *RELAY);
/*****************************************************************************************************************************/

#endif /* ECU_RELAY_RELAY_INT_H_ */
