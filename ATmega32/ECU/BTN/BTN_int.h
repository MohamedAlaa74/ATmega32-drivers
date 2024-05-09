/*
 * BTN_int.h
 *
 *  Created on: Jan 14, 2024
 *      Author: Zbook
 */

#ifndef ECU_BTN_BTN_INT_H_
#define ECU_BTN_BTN_INT_H_

/*
 * BTN_int.h
 *
 *  Created on: Jan 13, 2024
 *      Author: Mohamed ALAA
 */


#include "../../LIBRARIES/BIT_MATHS.h"
#include "../../LIBRARIES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
/******************************* macros **********************************************************/

/*************************************************************************************************/
/*************************data type declarations***********************************************************/
typedef enum {
	BTN_PRESSED,
	BTN_RELEASED
}BTN_status_t;

typedef enum {
	BTN_ACTIVE_HIGH,
	BTN_ACTIVE_LOW

}BTN_active_t;

typedef struct {
	DIO_pin_config_t BTN_pin;
	 BTN_status_t    BTN_status;
	 BTN_active_t    BTN_connection;

}BTN_t;
/***************************************************************************************************/


/*****************************function declarations***********************************************/
/*Name:			BTN_init
 * Description: Initialize switch pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType BTN_init (void);
/*********************************************************************************************************/



/* name   BTN_read_state
 * description   Read switch state
 * arguments     first =>  BTN : pointer to the switch pin configurations
 * 				 Second => BTN_state : pointer to return switch stae
 * return        (E_OK,E_NOK)
 */
Std_ReturnType BTN_read_state(const BTN_t *BTN,BTN_status_t *BTN_state );
/***********************************************************************************************************************/


#endif /* ECU_BTN_BTN_INT_H_ */



