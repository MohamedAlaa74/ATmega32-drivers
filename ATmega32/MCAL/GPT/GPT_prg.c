/*
 * GPT_prg.c
 *
 *  Created on: Feb 3, 2024
 *      Author: Zbook
 */


/********************************includes********************************************************/

#include "GPT_int.h"
/******************************************************************************************/
/********************************macros***********************************************************/

/***********************************************************************************************/
/************************* data type declarations ***********************************************************/
typedef struct {
	func_ptr GPT_0_INT_OVF_HANDLER;
	func_ptr GPT_0_INT_CTC_HANDLER;
	func_ptr GPT_1_INT_OVF_HANDLER;
	func_ptr GPT_1_INT_CTC_HANDLER;
	func_ptr GPT_2_INT_OVF_HANDLER;
	func_ptr GPT_2_INT_CTC_HANDLER;
}GPT_INT_HANDLER_t;
GPT_INT_HANDLER_t GPT_INT_HANDLER;
/**************************************************************************************************************/
static Std_ReturnType GPT_set_prescaler(GPT_t *GPT);
static Std_ReturnType GPT_disable(GPT_t *GPT);
static Std_ReturnType GPT_INT_enable(GPT_t *GPT);
static Std_ReturnType GPT_set_cbf(const GPT_t *GPT);
static Std_ReturnType GPT_set_mode(GPT_t *GPT);
/*****************************Function definitions ***********************************************************/

Std_ReturnType GPT_init (GPT_t *GPT){
	Std_ReturnType return_value = E_OK;
	if (GPT == NULL){
		return_value = E_NOK;
	}
	else {
		G_INT_Enable();
		GPT_INT_enable (GPT);
		GPT_set_mode(GPT);
		GPT_set_cbf(GPT);
	}
	return return_value;
}
/****************************************************************************************************************************************/
Std_ReturnType GPT_start_timer (GPT_t *GPT){
	Std_ReturnType return_value = E_OK;
		if (GPT == NULL){
			return_value = E_NOK;
		}
		else {
			GPT_set_prescaler(GPT);
			}
		return return_value;
		}


Std_ReturnType GPT_stop_timer (GPT_t *GPT){
	Std_ReturnType return_value = E_OK;
			if (GPT == NULL){
				return_value = E_NOK;
			}
			else {
				GPT_disable(GPT);
}
			return return_value;
}

Std_ReturnType GPT_write_value (GPT_t *GPT,u16 value){
	Std_ReturnType return_value = E_OK;
		if (GPT == NULL){
			return_value = E_NOK;
		}
		else {
			switch (GPT->GPT_num) {
				case GPT_TIMER0:
					switch (GPT->GPT_mode) {
						case GPT_NORMAL_MODE:
							GPT_u8_TCNT0_REG = (u8)value;
							break;
						case GPT_CTC_MODE:
							GPT_u8_OCR0_REG = (u8)value;
							break;
						default : return_value = E_NOK;  break;
					}
					break;
			}
			}
		return return_value;
		}


Std_ReturnType GPT_read_value (GPT_t *GPT,u16 *value){
	Std_ReturnType return_value = E_OK;
		if (GPT == NULL){
			return_value = E_NOK;
		}
		else {
			switch (GPT->GPT_num) {
				case GPT_TIMER0:
					switch (GPT->GPT_mode) {
						case GPT_NORMAL_MODE:
							*(u8*)value = GPT_u8_TCNT0_REG ;
							break;
						case GPT_CTC_MODE:
							*(u8*)value =	GPT_u8_OCR0_REG ;
							break;
						default : return_value = E_NOK;  break;
					}
					break;
			}
			}
		return return_value;
		}






/******************** timer0 overflow ISR *****************************************************/
void __vector_11(void) __attribute((signal,used));
void __vector_11(void)
{
 GPT_INT_HANDLER.GPT_0_INT_OVF_HANDLER ();
}
/******************** timer0 CTC ISR *********************************************************/
void __vector_10(void) __attribute((signal,used));
void __vector_10(void){
	 GPT_INT_HANDLER.GPT_0_INT_CTC_HANDLER ();

}






/*********************************************helper functions************************************************************/

static Std_ReturnType GPT_disable(GPT_t *GPT){
	Std_ReturnType return_value = E_OK;
		if (GPT == NULL){
			return_value = E_NOK;
		}
		else {
			switch (GPT->GPT_num) {
				case GPT_TIMER0:
				CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
				CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
				CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
				break;
			}

		}
		return return_value;
}

static Std_ReturnType GPT_set_mode(GPT_t *GPT){
	Std_ReturnType return_value = E_OK;
			if (GPT == NULL){
				return_value = E_NOK;
			}
	switch (GPT->GPT_num) {
		case GPT_TIMER0:
			switch (GPT->GPT_mode) {
				case GPT_NORMAL_MODE:

					CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_WGM00_BIT);
					CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_WGM01_BIT);
					ASSIGN_REG(GPT_u8_TCNT0_REG,(u8)GPT->GPT_preload_value);

					break;
				case GPT_CTC_MODE:
					CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_WGM00_BIT);
					SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_WGM01_BIT);
					ASSIGN_REG(GPT_u8_OCR0_REG,(u8)GPT->GPT_compare_match_value);
					break;
				default : return_value = E_NOK;  break;
			}
			break;
	}
	return return_value ;
}

static Std_ReturnType GPT_set_prescaler(GPT_t *GPT){
	Std_ReturnType return_value = E_OK;

	if (GPT == NULL){
			return_value = E_NOK;
		}
		else {
		switch (GPT->GPT_num) {
			case GPT_TIMER0:
			switch (GPT->GPT_clk) {
				case  GPT_NO_CLK :
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
									break;
				case  GPT_PRESCALER_1 :
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
									break;
				case  GPT_PRESCALER_8 :
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
									break;
				case  GPT_PRESCALER_64 :
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
									break;

				case  GPT_PRESCALER_256 :
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
									break;
				case  GPT_PRESCALER_1024 :
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
									break;
				case  GPT_EXT_CLK_FALLING :
									CLR_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
									break;
				case  GPT_EXT_CLK_RISING :
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS00_BIT);
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS01_BIT);
									SET_BIT(GPT_u8_TCCR0_REG,GPT_u8_TCCR0_CS02_BIT);
									break;
}
			break;
		}
		}
	return return_value ;
}

static Std_ReturnType GPT_INT_enable(GPT_t *GPT){
	Std_ReturnType return_value = E_OK;
			if (GPT == NULL){
				return_value = E_NOK;
			}
			else {
				switch (GPT->GPT_num) {
					case GPT_TIMER0:
						switch(GPT->GPT_mode){
						case GPT_NORMAL_MODE: SET_BIT(GPT_u8_TIMSK_REG,GPT_u8_TIMSK_TOIE0_BIT);break;
						case GPT_CTC_MODE:    SET_BIT(GPT_u8_TIMSK_REG,GPT_u8_TIMSK_OCIE0_BIT);break;
						}
					break;
				}

			}
			return return_value;
	}

static Std_ReturnType GPT_set_cbf(const GPT_t *GPT){
	Std_ReturnType return_value = E_OK;
			if (GPT == NULL){
				return_value = E_NOK;
			}
			else {
				switch (GPT->GPT_num) {
					case GPT_TIMER0:
						switch(GPT->GPT_mode){
						case GPT_NORMAL_MODE: GPT_INT_HANDLER.GPT_0_INT_OVF_HANDLER = GPT->APP_TIMER0_INT_HANDLER; break;
						case GPT_CTC_MODE:    GPT_INT_HANDLER.GPT_0_INT_CTC_HANDLER = GPT->APP_TIMER0_INT_HANDLER ;break ;
						}
					break;
				}

			}
			return return_value;
	}
































