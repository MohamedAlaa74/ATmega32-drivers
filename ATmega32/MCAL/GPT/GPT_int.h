/*
 * GPT_int.h
 *
 *  Created on: Feb 3, 2024
 *      Author: Zbook
 */

#ifndef MCAL_GPT_GPT_INT_H_
#define MCAL_GPT_GPT_INT_H_
  /********************************includes********************************************************/

#include "../G_INT/G_INT_int.h"
#include "GPT_cfg.h"
#include "GPT_prv.h"

/******************************************************************************************/
/********************************macros***********************************************************/

/***********************************************************************************************/
/************************* data type declarations ***********************************************************/


typedef enum {
	GPT_TIMER0,
	GPT_TIMER1,
	GPT_TIMER2
}GPT_NUMBER_t;


typedef enum {
	GPT_NORMAL_MODE,
	GPT_CTC_MODE = 2
}GPT_MODE_t;

typedef enum {
	GPT_NO_CLK,
	GPT_PRESCALER_1,
	GPT_PRESCALER_8,
	GPT_PRESCALER_64,
	GPT_PRESCALER_256,
	GPT_PRESCALER_1024,
	GPT_EXT_CLK_FALLING,
	GPT_EXT_CLK_RISING,
}GPT_CLK_t;


typedef struct {
	func_ptr APP_TIMER0_INT_HANDLER;
	GPT_NUMBER_t  GPT_num;
	GPT_MODE_t    GPT_mode;
	GPT_CLK_t     GPT_clk;
	u8 GPT_preload_value;
	u8 GPT_compare_match_value;
}GPT_t;
/**************************************************************************************************************/


/*****************************Function declarations  ***********************************************************/

Std_ReturnType GPT_init (GPT_t *GPT);

Std_ReturnType GPT_start_timer (GPT_t *GPT);

Std_ReturnType GPT_stop_timer (GPT_t *GPT);

Std_ReturnType GPT_write_value (GPT_t *GPT,u16 value);

Std_ReturnType GPT_read_value (GPT_t *GPT,u16 *value);

Std_ReturnType GPT_delay_s (GPT_t *GPT,u16 delay_value);



#endif /* MCAL_GPT_GPT_INT_H_ */
