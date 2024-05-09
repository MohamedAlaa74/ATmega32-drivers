/*
 * UART_int.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Zbook
 */

#ifndef MCAL_USART_UART_INT_H_
#define MCAL_USART_UART_INT_H_

/**********************includes*******************************************************/
#include "../../LIBRARIES/STD_TYPES.h"
#include "../../LIBRARIES/BIT_MATHS.h"
#include "UART_prv.h"
#include "UART_cfg.h"
#include "../G_INT/G_INT_int.h"
/**************************************************************************************/
/*************************macros*******************************************************/

/*************************data type declarations ************************************************************/
#define UART_ECU_F_8M    8
#define UART_ECU_F_16M   16






#if UART_ECU_F == UART_ECU_F_8M  && UART_ECU_CLK_MODE == UART_ECU_CLK_ASYNC
typedef enum {
	UART_BR_2400 =207,
	UART_BR_4800 =103,
    UART_BR_9600 =51 ,
	UART_BR_14400 = 34,
	UART_BR_19200 = 25,
	UART_BR_28800 = 16,
	UART_BR_38400 = 12,
	UART_BR_57600 = 8,
	UART_BR_76800 = 6,
	UART_BR_115200 = 3,
	UART_BR_250000 = 1,
	UART_BR_500000 = 0,
}UART_BAUD_t;
#endif

#if UART_ECU_F == UART_ECU_F_16M && UART_ECU_CLK_MODE == UART_ECU_CLK_ASYNC

typedef enum {
	UART_BR_2400 = 416,
	UART_BR_4800 = 207,
	UART_BR_9600 = 103,
	UART_BR_14400 = 68,
	UART_BR_19200 = 51,
	UART_BR_28800 = 34,
	UART_BR_38400 = 25,
	UART_BR_57600 = 16,
	UART_BR_76800 = 12,
	UART_BR_115200 = 8,
	UART_BR_250000 = 3,
	UART_BR_500000 = 1,
}UART_BAUD_t;
#endif


typedef enum {
	UART_MODE_ASYNC,
	UART_MODE_SYNC,
}UART_mode_t;

typedef enum {
	UART_STOP_BITS_1,
	UART_STOP_BITS_2,
}UART_stop_bits_t;

typedef enum {
UART_NO_PARITY,
UART_EVEN_PARITY = 2,
UART_ODD_PARITY
}UART_parity_bits_t;

typedef enum {

UART_DATA_SIZE_5_BIT = 	0,
UART_DATA_SIZE_6_BIT =	1,
UART_DATA_SIZE_7_BIT =	2,
UART_DATA_SIZE_8_BIT =	3,
UART_DATA_SIZE_9_BIT =	7,
}UART_data_bits_t;



typedef struct {
UART_mode_t UART_mode;
UART_BAUD_t UART_baud;
UART_data_bits_t UART_data_size;
UART_parity_bits_t UART_parity;
UART_stop_bits_t   UART_stop_bits;
}UART_CONF_t;


/***********************function prototypes********************************************/
/*
 * Name        : UART_init
 * Description : initialize UART module
 * Arguments   :  UART : pointer to UART post-build configurations
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType UART_init(UART_CONF_t *UART);
/*********************************************************************************************/
/*
 * Name        : UART_ASYNC_write_byte
 * Description : deinit UART module
 * Arguments   :  UART : pointer to UART post-build configurations
 * Return      :  E_OK,E_NOK
 */

Std_ReturnType UART_ASYNC_write_byte(UART_CONF_t *UART,u16 Copy_u16Data);
/***************************************************************************************/
/*
 * Name        : UART_ASYNC_read_byte
 * Description : receive data at RX pin
 * Arguments   :  UART : pointer to UART post-build configurations
 * 					Copy_Pu16Data => pointer to variable store received data
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType UART_ASYNC_read_byte(UART_CONF_t *UART,u16 *Copy_Pu16Data);



/***************************************************************************************/
/*
 * Name        : UART_ASYNC_write_string
 * Description : send string at uart tx pin
 * Arguments   :  UART : pointer to UART post-build configurations
 * 					Copy_Pu8Str => pointer to string will be sent
 * Return      :  E_OK,E_NOK
 */

Std_ReturnType UART_ASYNC_write_string(UART_CONF_t *UART,u16 *Copy_Pu8Str);
/***************************************************************************************/
/***************************************************************************************/
/*
 * Name        : UART_ASYNC_read_string
 * Description : receive string at RX pin
 * Arguments   :  UART : pointer to UART post-build configurations
 * 					Copy_Pu8Str => pointer to string store received data
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType UART_ASYNC_read_string(UART_CONF_t *UART,u16 *Copy_Pu8Str);
/***************************************************************************************/

#endif /* MCAL_USART_UART_INT_H_ */
