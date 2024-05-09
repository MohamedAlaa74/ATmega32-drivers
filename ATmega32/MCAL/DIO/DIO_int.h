/*
 * DIO_int.h
 *
 *  Created on: Jan 8, 2024
 *      Author: Zbook
 */

#ifndef MCAL_DIO_INT_H_
#define MCAL_DIO_INT_H_

#include "../../LIBRARIES/BIT_MATHS.h"
#include "../../LIBRARIES/STD_TYPES.h"

#include "DIO_cfg.h"
#include "DIO_prv.h"

/******************************* macros **********************************************************/
#define DIO_u8_HIGH 0xFF
#define DIO_u8_LOW 0x00
/*************************************************************************************************/
/*************************data type declarations***********************************************************/
typedef enum {
	DIO_LOW,
	DIO_HIGH
}DIO_logic_t;

typedef enum {
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
}DIO_pin_index_t;

typedef enum {
	DIO_INPUT,
	DIO_OUTPUT
}DiO_direction_t;

typedef enum {
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_port_index_t;

typedef struct {
	u8 port		  :  2;
	u8 pin  	  :  3;
	u8 logic 	  :  1;
	u8 direction  :  1;
}DIO_pin_config_t;
/***************************************************************************************************/


/*****************************function declarations***********************************************/
/*Name:			DIO_u8Init
 * Description: Initialize all MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType DIO_init (void);
/*********************************************************************************************************/


/* name          DIO_write_pin_direction
 * description   Set PIN Direction
 * arguments     first =>  pinconfig : pointer to struct of pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DIO_write_pin_direction (const DIO_pin_config_t *pinconfig);
/*****************************************************************************************************************/
/* name   DIO_read_pin_direction
 * description   READ PIN Direction
 * arguments     first =>  pinconfig
 *               second => direction_status
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_read_pin_direction (DIO_pin_config_t *pinconfig, DiO_direction_t *direction_status);
/*******************************************************************************************************************/
/* name   DIO_write_pin_logic
 * description   Set PIN logic
 * arguments     first =>  pinconfig
 *               second => logic
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_write_pin_logic (const DIO_pin_config_t *pinconfig,DIO_logic_t logic);
/***********************************************************************************************************************/

/* name   DIO_enuSetPinDirection
 * description   read PIN logic
 * arguments     first =>  Copy_u8Port      options (PORTA, PORTB,PORTC,PORTD)
 *               second => Copu_u8Pin       options (from PIN0 to PIN7)
 *               third =>  Copy_u8Value     options (INPUT,OUTPUT)
 * return   (DIO_OK,DIO_NOK)
 */
Std_ReturnType DIO_read_pin_logic (const DIO_pin_config_t *pinconfig, DIO_logic_t *logic);
/****************************************************************************************************************************/
/* name   DIO_toggle_pin_logic
 * description   toggle PIN logic
 * arguments     first =>  pinconfig      options (PORTA, PORTB,PORTC,PORTD)
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_toggle_pin_logic (DIO_pin_config_t *pinconfig);
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/




/* name          DIO_write_port_direction
 * description   Set port Direction
 * arguments     first =>  port :
 * 				 second=>  direction :
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DIO_write_port_direction (DIO_port_index_t port,u8 direction);
/*****************************************************************************************************************/
/* name   DIO_read_port_direction
 * description   READ PORT Direction
 * arguments     first =>  port
 *               second => direction_status
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_read_port_direction (DIO_port_index_t port,u8 *direction_status);
/*******************************************************************************************************************/
/* name   DIO_write_port_logic
 * description   Set PIN logic
 * arguments     first =>  pinconfig
 *               second => logic
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_write_port_logic (DIO_port_index_t port,u8 logic);
/***********************************************************************************************************************/

/* name   DIO_read_port_logic
 * description   read PIN logic
 * arguments     first =>  port      options (PORTA, PORTB,PORTC,PORTD)
 *               second => *logic_status
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_read_port_logic (DIO_port_index_t port,u8 *logic_status);
/****************************************************************************************************************************/
/* name   DIO_toggle_port_logic
 * description   toggle port logic
 * arguments     first =>  port
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_toggle_port_logic (DIO_port_index_t port);
/*****************************************************************************************************************************/










#endif /* MCAL_DIO_INT_H_ */
