/*
 * G_INT_prg.c
 *
 *  Created on: Jan 22, 2024
 *      Author: Zbook
 */

/********************************includes********************************************************/

#include "EXT_INT_int.h"
/******************************************************************************************/
/********************************macros***********************************************************/

/***********************************************************************************************/
/************************* data type declarations ***********************************************************/

/**************************************************************************************************************/
static Std_ReturnType EXT_INT_INTX_enable(const EXT_INT_CONF_t *interrupt);
static Std_ReturnType EXT_INT_INTX_disable(const EXT_INT_CONF_t *interrupt);
static Std_ReturnType EXT_INT_INTX_mode_init(const EXT_INT_CONF_t *interrupt);
static Std_ReturnType EXT_INT_INTX_pin_inint(const EXT_INT_CONF_t *interrupt);
static Std_ReturnType EXT_INT_INTX_CBF(const EXT_INT_CONF_t *interrupt);

/*****************************Function definitions ***********************************************************/

/*Name         :			EXT_INT_Enable
 * Description :      Enable External interrupt peripherals
 * Arguments   : 	  interrupt -> pointer to Ext interrupt configurations
 * Return      :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType EXT_INT_Enable(const EXT_INT_CONF_t *interrupt) {
	Std_ReturnType return_value = E_NOK;
	if (interrupt == NULL) {
		return_value = E_NOK;
	}

	else {
		return_value = G_INT_Enable();
		return_value = EXT_INT_INTX_pin_inint(interrupt);
		return_value = EXT_INT_INTX_enable(interrupt);
		return_value = EXT_INT_INTX_mode_init(interrupt);
		return_value = EXT_INT_INTX_CBF(interrupt);
	}
	return return_value;
}
	/************************************************************************************************************************/
/*Name         :			EXT_INT_Enable
 * Description :      Disable External interrupt peripherals
 * Arguments   : 	  interrupt -> pointer to Ext interrupt configurations
 * Return      :	  	return_value {E_ok,E-NOK}
  */
	Std_ReturnType EXT_INT_disable(EXT_INT_CONF_t *interrupt) {
		Std_ReturnType return_value = E_NOK;
		if (interrupt == NULL) {
			return_value = E_NOK;
		} else {

			return_value = EXT_INT_INTX_disable(interrupt);

		}

		return return_value;
	}

/**************************************************helper functions********************************************************************************************/
/*******************************************************************************************************************************************/
	static Std_ReturnType EXT_INT_INTX_enable(const EXT_INT_CONF_t *interrupt) {

		Std_ReturnType return_value = E_NOK;
		switch (interrupt->type) {
		case EXT_INT_0:
			SET_BIT(EXT_INT_u8_GICR_REG.EXT_INT_u8_GICR, INT0_Bit);
			break;
		case EXT_INT_1:
			SET_BIT(EXT_INT_u8_GICR_REG.EXT_INT_u8_GICR, INT1_Bit);
			break;
		case EXT_INT_2:
			SET_BIT(EXT_INT_u8_GICR_REG.EXT_INT_u8_GICR, INT2_Bit);
			break;
		default:
			return_value = E_NOK;

		}
		return return_value;
	}

	/***************************************************************************************************************/
	static Std_ReturnType EXT_INT_INTX_disable(const EXT_INT_CONF_t *interrupt) {

		Std_ReturnType return_value = E_NOK;
		switch (interrupt->type) {
		case EXT_INT_0:
			CLR_BIT(EXT_INT_u8_GICR_REG.EXT_INT_u8_GICR, INT0_Bit);
			break;
		case EXT_INT_1:
			CLR_BIT(EXT_INT_u8_GICR_REG.EXT_INT_u8_GICR, INT1_Bit);
			break;
		case EXT_INT_2:
			CLR_BIT(EXT_INT_u8_GICR_REG.EXT_INT_u8_GICR, INT2_Bit);
			break;
		default:
			return_value = E_NOK;

		}
		return return_value;
	}
	/********************************************************************************************************************/
	static Std_ReturnType EXT_INT_INTX_mode_init(const EXT_INT_CONF_t *interrupt) {
		Std_ReturnType return_value = E_NOK;
		switch (interrupt->type) {

		case EXT_INT_0:
			switch (interrupt->mode) {
			case EXT_INT_u8_LOW_LEVEL:
				CLR_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC00_Bit);
				CLR_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC01_Bit);
				break;

			case EXT_INT_u8_ANY_CHANGE:
				SET_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC00_Bit);
				CLR_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC01_Bit);
				break;

			case EXT_INT_u8_FALLING_EDGE:
				CLR_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC00_Bit);
				SET_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC01_Bit);
				break;

			case EXT_INT_u8_RISING_EDGE:
				SET_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC00_Bit);
				SET_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC01_Bit);


				break;
			}
			break;

		case EXT_INT_1:
			switch (interrupt->mode) {
			case EXT_INT_u8_LOW_LEVEL:
				CLR_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC00_Bit);
				CLR_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC01_Bit);
				break;

			case EXT_INT_u8_ANY_CHANGE:
				SET_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC00_Bit);
				CLR_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC01_Bit);
				break;

			case EXT_INT_u8_FALLING_EDGE:
				CLR_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC00_Bit);
				SET_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC01_Bit);
				break;

			case EXT_INT_u8_RISING_EDGE:
				SET_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC00_Bit);
				SET_BIT(EXT_INT_u8_MCUCR_REG.EXT_INT_u8_MCUCR, ISC01_Bit);
				break;
			}
			break;

		case EXT_INT_2:
			switch (interrupt->mode) {

			case EXT_INT_u8_FALLING_EDGE:
				CLR_BIT(EXT_INT_u8_MCUCSR_REG.EXT_INT_u8_MCUCSR, ISC2_Bit);

				break;

			case EXT_INT_u8_RISING_EDGE:
				SET_BIT(EXT_INT_u8_MCUCSR_REG.EXT_INT_u8_MCUCSR, ISC2_Bit);

				break;
			default:
				return_value = E_NOK;

			}
			break;
		}

		return return_value;
	}

	/***************************************************************************************************************************/
	static Std_ReturnType EXT_INT_INTX_pin_inint(
			const EXT_INT_CONF_t *interrupt) {
		Std_ReturnType return_value = E_NOK;
		return_value = DIO_write_pin_direction(&interrupt->pin);
		return return_value;}

	static Std_ReturnType EXT_INT_INTX_CBF(const EXT_INT_CONF_t *interrupt) {

			Std_ReturnType return_value = E_OK;
			if (interrupt == NULL){
				return_value = E_NOK;
			}
			else {


			switch (interrupt->type) {
			case EXT_INT_0:
				EXT_INT_handler.EXT_INT0_handler = interrupt->APP_INT_handler;

				break;
			case EXT_INT_1:
				EXT_INT_handler.EXT_INT1_handler = interrupt->APP_INT_handler;

				break;
			case EXT_INT_2:
				EXT_INT_handler.EXT_INT2_handler = interrupt->APP_INT_handler;

				break;
			default:
				return_value = E_NOK;
			}
			}
			return return_value;
		}
	/***************************************************************************************************************/

	void __vector_1(void) __attribute((signal,used));
	 void __vector_1(void){
	 if (EXT_INT_handler.EXT_INT0_handler != NULL){;
	 EXT_INT_handler.EXT_INT0_handler();
		 }
	 }
	 /*INT1 ISR*/
	 void __vector_2(void) __attribute((signal,used));
	 void __vector_2(void)
	 {
		 if (EXT_INT_handler.EXT_INT1_handler != NULL){;
	 EXT_INT_handler.EXT_INT1_handler();
		 }
	 }
	 /*INT2 ISR*/
	 void __vector_3(void) __attribute((signal,used));
	 void __vector_3(void)
	 {
		 if (EXT_INT_handler.EXT_INT2_handler != NULL){;
		 EXT_INT_handler.EXT_INT2_handler();
			 }
		 }


