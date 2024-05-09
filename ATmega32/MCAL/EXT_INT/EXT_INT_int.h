/*
 * G_INT_int.h
 *
 *  Created on: Jan 22, 2024
 *      Author: Zbook
 */

#ifndef MCAL_EXT_INT_EXT_INT_INT_H_
#define MCAL_EXT_INT_EXT_INT_INT_H_




/********************************includes********************************************************/
#include "../../LIBRARIES/BIT_MATHS.h"
#include "../../LIBRARIES/STD_TYPES.h"
#include "EXT_INT_prv.h"
#include "EXT_INT_cfg.h"
#include "../G_INT/G_INT_int.h"
#include "../../MCAL/DIO/DIO_int.h"
/******************************************************************************************/
/********************************macros***********************************************************/

/***********************************************************************************************/
/************************* data type declarations ***********************************************************/

typedef struct {

	func_ptr EXT_INT0_handler;
	func_ptr EXT_INT1_handler;
	func_ptr EXT_INT2_handler;

}EXT_INT_handler_t;

EXT_INT_handler_t EXT_INT_handler;
typedef enum {
	EXT_INT_u8_LOW_LEVEL,
	EXT_INT_u8_ANY_CHANGE,
	EXT_INT_u8_FALLING_EDGE,
	EXT_INT_u8_RISING_EDGE,
}EXT_INT_MODE;


typedef enum {
	EXT_INT_0,
	EXT_INT_1,
	EXT_INT_2
}EXT_INT_TYPE;


typedef struct {
	DIO_pin_config_t pin;
	func_ptr APP_INT_handler;
	EXT_INT_TYPE  type;
	EXT_INT_MODE  mode;
}EXT_INT_CONF_t;





/**************************************************************************************************************/
/*****************************Function declarations***********************************************************/

/*Name         :			EXT_INT_Enable
 * Description :      Enable External interrupt peripherals
 * Arguments   : 	  interrupt -> pointer to Ext interrupt configurations
 * Return      :	  	return_value {E_ok,E-NOK}
  */
   Std_ReturnType EXT_INT_Enable (const EXT_INT_CONF_t *interrupt);


/************************************************************************************************************************/
   /*Name         :			EXT_INT_Enable
    * Description :      disable External interrupt peripherals
    * Arguments   : 	  interrupt -> pointer to Ext interrupt configurations
    * Return      :	  	return_value {E_ok,E-NOK}
     */
   Std_ReturnType EXT_INT_disable (EXT_INT_CONF_t *interrupt);

/***************************************************************************************************************/
#endif /* MCAL_EXT_INT_EXT_INT_INT_H_ */
