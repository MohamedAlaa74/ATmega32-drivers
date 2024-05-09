/*
 * DC_MOTOR_int.h
 *
 *  Created on: Jan 15, 2024
 *      Author: Zbook
 */

#ifndef ECU_DC_MOTOR_DC_MOTOR_INT_H_
#define ECU_DC_MOTOR_DC_MOTOR_INT_H_
/*************************includes*****************************************************************/
#include "DC_MOTOR_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"
/******************************* macros **********************************************************/
#define  DC_MOTOR_ON_STATUS   0X01U
#define  DC_MOTOR_OFF_STATUS  0X00U
#define  DC_MOTOR_PIN1   0X00U
#define  DC_MOTOR_PIN2   0X01U
/*************************************************************************************************/
/*************************data type declarations***********************************************************/


typedef struct {
	u8 port		  :  2;
	u8 pin  	  :  3;
	u8 status 	  :  1;
}DC_MOTOR_pin_t;

typedef struct {
	DC_MOTOR_pin_t dc_motor [2];
}DC_MOTOR_t;
/***************************************************************************************************/


/*****************************function declarations***********************************************/
/*Name:			DC_MOTOR_pin_init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType DC_MOTOR_pin_init (void);
/*********************************************************************************************************/
/* name   DC_MOTOR_move_Right
 * description   Move motor right direction
 * arguments     first =>  MOTOR : pointer to the MOTOR pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DC_MOTOR_move_Right( const DC_MOTOR_t *MOTOR);
/***********************************************************************************************************************/
/* name   DC_MOTOR_move_left
 * description   Move motor right direction
 * arguments     first =>  MOTOR : pointer to the MOTOR pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DC_MOTOR_move_left( const DC_MOTOR_t *MOTOR);
/***********************************************************************************************************************/

/* name   DC_MOTOR_stop
 * description   stop motor movement
 * arguments     first =>  MOTOR : pointer to the MOTOR pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DC_MOTOR_stop ( const DC_MOTOR_t *MOTOR);
/*****************************************************************************************************************************/

#endif /* ECU_DC_MOTOR_DC_MOTOR_INT_H_ */
