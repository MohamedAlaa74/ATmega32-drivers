/*
x * LCD_int.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Zbook
 */

#ifndef ECU_LCD_LCD_INT_H_
#define ECU_LCD_LCD_INT_H_

/*******************************************includes******************************************************/
#include "LCD_cfg.h"
#include "LCD_prv.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include <stdio.h>

/******************************* macros **********************************************************/
#define LCD_CLEAR							0x01
#define LCD_RETURN_HOME						0x02
#define LCD_ENTRY_MODE      				0x06
#define LCD_CURSOR_OFF_DISPLAY_ON           0x0C
#define LCD_CURSOR_OFF_DISPLAY_OFF    	    0x08
#define LCD_CURSOR_ON_DISPLAY_ON      	 	0x0F
#define LCD_CURSOR_ON_DISPLAY_OFF     	    0x0E
#define LCD_DISPLAY_SHIFT_RIGHT      	    0x1C
#define LCD_DISPLAY_SHIFT_LEFT      	    0x18
#define LCD_8BIT_MODE_2LINE        		    0X38
#define LCD_4BIT_MODE_2LINE         	    0X28

#define LCD_CGRAM_START       			    0x40
#define LCD_DDRAM_START        				0x80
#define LCD_8BIT_MODE                         0
#define LCD_4BIT_MODE                         1


#define LCD_BIT0							0x00
#define LCD_BIT1							0x01
#define LCD_BIT2							0x02
#define LCD_BIT3							0x03
#define LCD_BIT4							0x04
#define LCD_BIT5							0x05
#define LCD_BIT6							0x06
#define LCD_BIT7							0x07
#define LCD_ROW1                            0x01
#define LCD_ROW2                            0x02
#define LCD_ROW3                            0x03
#define LCD_ROW4                            0x04

/*************************************************************************************************/
/*************************data type declarations***********************************************************/
typedef struct {
	DIO_pin_config_t LCD_rs;
	DIO_pin_config_t LCD_en;
	DIO_pin_config_t LCD_data[4];

} LCD_4bit_t;
typedef struct {
	DIO_pin_config_t LCD_rs;
	DIO_pin_config_t LCD_en;
	DIO_pin_config_t LCD_data[8];
} LCD_8bit_t;
/***************************************************************************************************/



 /*****************************function declarations***********************************************/
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_4bit_init(const LCD_4bit_t *LCD);
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */
Std_ReturnType LCD_4bit_send_command(const LCD_4bit_t *LCD, u8 command);
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_4bit_send_char_data(const LCD_4bit_t *LCD, u8 data);

/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_4bit_send_char_data_pos(const LCD_4bit_t *LCD, u8 row,
		u8 column, u8 command);

/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_4bit_send_string(const LCD_4bit_t *LCD, u8 *str);

/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_4bit_send_string_pos(const LCD_4bit_t *LCD, u8 row,
		u8 column, u8 *str);

/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */
Std_ReturnType LCD_4bit_send_number(const LCD_4bit_t *LCD, u32 number);
/****************************************************************************************************************/
Std_ReturnType LCD_4bit_send_number_pos(const LCD_4bit_t *LCD, u8 row, u8 column, u32 number);
/*****************************************************************************************************************/

Std_ReturnType LCD_4bit_send_custom_char(const LCD_4bit_t *LCD, u8 row,
		u8 column, const u8 cus_char[], u8 mem_pos);
/****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_8bit_init(const LCD_8bit_t *LCD);
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_8bit_send_command(const LCD_8bit_t *LCD, u8 command);

/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_8bit_send_char_data(const LCD_8bit_t *LCD, u8 data);
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_8bit_send_char_data_pos(const LCD_8bit_t *LCD, u8 row,
		u8 column, u8 command);
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_8bit_send_string(const LCD_8bit_t *LCD, u8 *str);

/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */

Std_ReturnType LCD_8bit_send_string_pos(const LCD_8bit_t *LCD, u8 row,
		u8 column, u8 *str);
/*Name:			LED_Init
 * Description: Initialize MCU Pins
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
 */
Std_ReturnType LCD_8bit_send_number_pos(const LCD_8bit_t *LCD, u8 row, u8 column, u32 number);

Std_ReturnType LCD_8bit_send_number(const LCD_8bit_t *LCD, u32 number);

Std_ReturnType LCD_8bit_send_custom_char(const LCD_8bit_t *LCD, u8 row,
		u8 column, const u8 cus_char[], u8 mem_pos);

/*********************************************************************************************************************************/
#endif /* ECU_LCD_LCD_INT_H_ */
