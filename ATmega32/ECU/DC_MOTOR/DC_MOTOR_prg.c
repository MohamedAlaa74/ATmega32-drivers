/*
 * DC_MOTOR_prg.c
 *
 *  Created on: Jan 15, 2024
 *      Author: Zbook
 */

/**********************************************includes**********************************************************/
#include "DC_MOTOR_int.h"
/**********************************************data type Definitions *********************************************************************/
static DIO_pin_config_t motor_pin1;
static DIO_pin_config_t motor_pin2;

/**************************************** function definitions ***********************************************/
/*Name:			DC_MOTOR_pin_init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType DC_MOTOR_pin_init (void){
	Std_ReturnType return_value = E_OK;
	DIO_init();
	return return_value;
}
/********************************************************************************************************************/
/* name   DC_MOTOR_move_Right
 * description   Move motor right direction
 * arguments     first =>  MOTOR : pointer to the MOTOR pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DC_MOTOR_move_Right( const DC_MOTOR_t *MOTOR){
	Std_ReturnType return_value = E_NOK;
motor_pin1.port = MOTOR->dc_motor[DC_MOTOR_PIN1].port;
motor_pin1.pin = MOTOR->dc_motor[DC_MOTOR_PIN1].pin;
//motor_pin1.logic = MOTOR->dc_motor[DC_MOTOR_PIN1].status;
motor_pin2.port = MOTOR->dc_motor[DC_MOTOR_PIN2].port;
motor_pin2.pin = MOTOR->dc_motor[DC_MOTOR_PIN2].pin;
//motor_pin1.logic = MOTOR->dc_motor[DC_MOTOR_PIN2].status;
	if (NULL == MOTOR){
		return_value = E_NOK;
	}
	else {
		DIO_write_pin_logic(&motor_pin1,DIO_HIGH);
		DIO_write_pin_logic(&motor_pin2,DIO_LOW);
	}
	return return_value;
}
/***********************************************************************************************************************/
/* name   DC_MOTOR_move_left
 * description   Move motor right direction
 * arguments     first =>  MOTOR : pointer to the MOTOR pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DC_MOTOR_move_left( const DC_MOTOR_t *MOTOR){
	Std_ReturnType return_value = E_NOK;
motor_pin1.port = MOTOR->dc_motor[0].port;
motor_pin1.pin = MOTOR->dc_motor[0].pin;
//motor_pin1.logic = MOTOR->dc_motor[0].status;
motor_pin2.port = MOTOR->dc_motor[1].port;
motor_pin2.pin = MOTOR->dc_motor[1].pin;
//motor_pin1.logic = MOTOR->dc_motor[1].status;
	if (NULL == MOTOR){
		return_value = E_NOK;
	}
	else {
		DIO_write_pin_logic(&motor_pin1,DIO_LOW);
		DIO_write_pin_logic(&motor_pin2,DIO_HIGH);
	}
	return return_value;
}
/***********************************************************************************************************************/
/* name   DC_MOTOR_stop
 * description   stop motor movement
 * arguments     first =>  MOTOR : pointer to the MOTOR pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DC_MOTOR_stop ( const DC_MOTOR_t *MOTOR){
	Std_ReturnType return_value = E_NOK;
motor_pin1.port = MOTOR->dc_motor[0].port;
motor_pin1.pin = MOTOR->dc_motor[0].pin;
//motor_pin1.logic = MOTOR->dc_motor[0].status;
motor_pin2.port = MOTOR->dc_motor[1].port;
motor_pin2.pin = MOTOR->dc_motor[1].pin;
//motor_pin1.logic = MOTOR->dc_motor[1].status;
	if (NULL == MOTOR){
		return_value = E_NOK;
	}
	else {
		DIO_write_pin_logic(&motor_pin1,DIO_HIGH);
		DIO_write_pin_logic(&motor_pin2,DIO_HIGH);
	}
	return return_value;
}
/*****************************************************************************************************************************/
