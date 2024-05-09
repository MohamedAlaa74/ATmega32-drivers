/*

 * ADC_prg.c
 *
 *  Created on: Jan 28, 2024
 *      Author: Zbook
 */

/************************includess*****************************************************/
#include "ADC_int.h"

/**************************************************************************************/
/*************************macros*******************************************************/

/**************************************************************************************/
static Std_ReturnType ADC_set_ch(ADC_CONF_t *ADC);
static Std_ReturnType ADC_enable(void);
static Std_ReturnType ADC_start_conversion(void);
static Std_ReturnType ADC_INT_enable(ADC_CONF_t *ADC);
static Std_ReturnType ADC_set_prescaler(ADC_CONF_t *ADC);
static Std_ReturnType ADC_set_adjusment(ADC_CONF_t *ADC);
static Std_ReturnType ADC_set_v_ref(ADC_CONF_t *ADC);
static Std_ReturnType ADC_set_trigger_source(ADC_CONF_t *ADC);
static Std_ReturnType ADC_pin_init(ADC_CONF_t *ADC);
static Std_ReturnType ADC_set_cbf(const ADC_CONF_t *ADC);
/***********************function prototypes********************************************/
/*
 * Name        : EEPROM_WriteByte
 * Description : Write byte in specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_u8Data     : Data will be written in EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */

Std_ReturnType ADC_init(ADC_CONF_t *ADC){
	Std_ReturnType return_value = E_OK;
	if (ADC == NULL) {
		return_value = E_NOK;
	}
	else {
		ADC_pin_init(ADC);
		ADC_set_ch(ADC);
		ADC_set_v_ref(ADC);
		ADC_set_adjusment(ADC);
		ADC_set_prescaler(ADC);
		ADC_set_trigger_source(ADC);
		ADC_enable();
#if ADC_INTERRUPT_FEATURE == ADC_INT_ON
		G_INT_Enable();
		ADC_INT_enable(ADC);
#endif
	}
	return return_value;
}
/********************************************************************************************************/
/*
 * Name        : EEPROM_ReadByte
 * Description : read byte from specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_pu8Data : pointer to address of Data will be read from EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */

Std_ReturnType ADC_read_value_polling(ADC_CONF_t *ADC,u16 *Copy_pu16DigitalValue){

	Std_ReturnType return_value = E_OK;
		if ((ADC == NULL)||(Copy_pu16DigitalValue == NULL)){
			return_value = E_NOK;
		}
		else {
	ADC_start_conversion();
	while (GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADSC_BIT)==ZERO_INIT);
	*Copy_pu16DigitalValue = (u16)ADC_u8_ADCL_REG |(ADC_u8_ADCH_REG<<8) ;
}
		return return_value;
}
/*************************************************************************************************************************/
/*
 * Name        : EEPROM_ReadByte
 * Description : read byte from specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_pu8Data : pointer to address of Data will be read from EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */

Std_ReturnType ADC_read_value_INTERRUPT(ADC_CONF_t *ADC,u16 *Copy_pu16DigitalValue){
	Std_ReturnType return_value = E_OK;
		if (ADC == NULL){
			return_value = E_NOK;
		}
		else {
	        ADC_start_conversion();
	        ADC_set_cbf(ADC);
	        *Copy_pu16DigitalValue = (u16)ADC_u8_ADCL_REG |(ADC_u8_ADCH_REG<<8) ;

}
		return return_value;
}
/*********************************************************************************************/
/*
 * Name        : EEPROM_ReadByte
 * Description : read byte from specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_pu8Data : pointer to address of Data will be read from EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */






/**********************************************************************************************************************/
/******************************************helper functions************************************************************/
static Std_ReturnType ADC_pin_init(ADC_CONF_t *ADC) {
	Std_ReturnType return_value = E_OK;
	if (ADC == NULL) {
		return_value = E_NOK;
	} else {
		DIO_write_pin_direction(&ADC->ADC_pin);
	}
	return return_value;
}
/**********************************************************************************************************************/

static Std_ReturnType ADC_set_ch(ADC_CONF_t *ADC) {
	Std_ReturnType return_value = E_OK;
	if (ADC == NULL) {
		return_value = E_NOK;
	} else {
		switch (ADC->ADC_channel) {
		case ADC_CHANNEL0:
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX0_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX1_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX2_BIT);
			break;
		case ADC_CHANNEL1:
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX0_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX1_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX2_BIT);

			break;
		case ADC_CHANNEL2:
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX0_BIT);
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX1_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX2_BIT);
			break;

		case ADC_CHANNEL3:
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX0_BIT);
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX1_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX2_BIT);
			break;
		case ADC_CHANNEL4:
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX0_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX1_BIT);
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX2_BIT);
			break;
		case ADC_CHANNEL5:
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX0_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX1_BIT);
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX2_BIT);

			break;
		case ADC_CHANNEL6:
			CLR_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX0_BIT);
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX1_BIT);
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX2_BIT);
			break;
		case ADC_CHANNEL7:
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX0_BIT);
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX1_BIT);
			SET_BIT(ADC_u8_ADMUX_REG,ADC_u8_ADMUX_MUX2_BIT);

			break;
		default:
			return_value = E_NOK;
			break;
		}

	}
	return return_value;
}
/**********************************************************************************************************************/
static Std_ReturnType ADC_set_adjusment(ADC_CONF_t *ADC) {
	Std_ReturnType return_value = E_OK;
	if (ADC == NULL) {
		return_value = E_NOK;
	} else {
		switch (ADC->ADC_adjust) {
		case ADC_RIGHT_ADJUST:
			CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_ADLAR_BIT);
			break;
		case ADC_LEFT_ADJUST:
			SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_ADLAR_BIT);
			break;
		default:
			return_value = E_NOK;
			break;
		}
	}
	return return_value;
}
/********************************************************************************************************************/
static Std_ReturnType ADC_set_v_ref(ADC_CONF_t *ADC) {
	Std_ReturnType return_value = E_OK;
	if (ADC == NULL) {
		return_value = E_NOK;
	} else {
		switch (ADC->ADC_V_reference) {
		case ADC_V_REFERENCE_AREF:
			CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS1_BIT);
			break;
		case ADC_V_REFERENCE_AVCC:
			SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0_BIT);
			CLR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS1_BIT);
			break;
		case ADC_V_REFERENCE_INTERNAL_2_56:
			SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS0_BIT);
			SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADMUX_REFS1_BIT);
			break;
		default:
			return_value = E_NOK;
			break;
		}

	}
	return return_value;
}
/*********************************************************************************************************************/
static Std_ReturnType ADC_set_trigger_source(ADC_CONF_t *ADC)
{
	Std_ReturnType return_value = E_OK;
	if (ADC == NULL) {
		return_value = E_NOK;
	} else {
		switch (ADC->ADC_trigger_src) {

	case ADC_FREE_RUNNING:
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS0_BIT);
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS1_BIT);
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS2_BIT);
		break;
	case ADC_ANALOG_COMP:
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS0_BIT);
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS1_BIT);
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS2_BIT);
		break;

	case ADC_EXT_INT0:
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS0_BIT);
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS1_BIT);
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS2_BIT);
		break;
	case ADC_TIM0_COMP_MATCH:
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS0_BIT);
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS1_BIT);
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS2_BIT);
		break;
	case ADC_TIM0_OVF:
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS0_BIT);
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS1_BIT);
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS2_BIT);

		break;
	case ADC_TIM1_COMP_MATCH:
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS0_BIT);
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS1_BIT);
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS2_BIT);
		break;
	case ADC_TIM1_OVF:
		CLR_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS0_BIT);
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS1_BIT);
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS2_BIT);
		break;
	case ADC_TIM1_CAPTURE:
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS0_BIT);
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS1_BIT);
		SET_BIT(ADC_u8_SFIOR_REG,ADC_u8_SFIOR_ADTS2_BIT);
		break;
	default:
		return_value = E_NOK;
		break;
	}
	}
	return return_value;
}

/****************************************************************************************************************************/
static Std_ReturnType ADC_set_prescaler(ADC_CONF_t *ADC) {
	Std_ReturnType return_value = E_OK;
	if (ADC == NULL) {
		return_value = E_NOK;
	} else {
		switch (ADC->ADC_prescaler) {
		case ADC_PRESCALER_2:
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS0_BIT);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS1_BIT);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS2_BIT);
			break;
		case ADC_PRESCALER_4:
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS0_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS1_BIT);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS2_BIT);
			break;

		case ADC_PRESCALER_8:
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS0_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS1_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS2_BIT);
			break;
		case ADC_PRESCALER_16:
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS0_BIT);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS1_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS2_BIT);
			break;
		case ADC_PRESCALER_32:
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS0_BIT);
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS1_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS2_BIT);

			break;
		case ADC_PRESCALER_64:
			CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS0_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS1_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS2_BIT);
			break;
		case ADC_PRESCALER_128:
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS0_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS1_BIT);
			SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADPS2_BIT);

			break;
		default:
			return_value = E_NOK;
			break;
		}

	}
	return return_value;
}
/***********************************************************************************************************/
static Std_ReturnType ADC_INT_enable(ADC_CONF_t *ADC) {
	Std_ReturnType return_value = E_OK;
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADIE_BIT);
	return return_value;
}
/*************************************************************************************************************/
static Std_ReturnType ADC_start_conversion(void) {
	Std_ReturnType return_value = E_OK;
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADSC_BIT);
	return return_value;
}
/*************************************************************************************************************/
static Std_ReturnType ADC_enable(void) {
	Std_ReturnType return_value = E_OK;
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADCSRA_ADEN_BIT);
	return return_value;
}
/**************************************************************************************************************/
static Std_ReturnType ADC_set_cbf(const ADC_CONF_t *ADC){
	Std_ReturnType return_value = E_OK;
				if (ADC == NULL){
					return_value = E_NOK;
				}
				else {
					ADC_INT_handler = ADC->ADC_APP_INT_handler;

				}
return return_value;
}
/*******************************************************************************************************************/
void __vector_16(void) __attribute((signal,used));
void __vector_16(void)
{

		 if (ADC_INT_handler != NULL){
			 ADC_INT_handler();
		 }
		 SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADCSRA_ADIF_BIT);
	 }
