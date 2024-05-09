/*
 * ADC_int.h
 *
 *  Created on: Jan 28, 2024
 *      Author: Zbook
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

/**********************includes*******************************************************/
#include "../../LIBRARIES/STD_TYPES.h"
#include "../../LIBRARIES/BIT_MATHS.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../G_INT/G_INT_int.h"
/**************************************************************************************/
/*************************macros*******************************************************/

/*************************data type declarations ************************************************************/

#if ADC_INTERRUPT_FEATURE == ADC_INT_ON
 func_ptr ADC_INT_handler;
#endif



typedef enum {
	ADC_CHANNEL0,
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7,
}ADC_channel_t;

typedef enum {
	ADC_V_REFERENCE_AREF,
	ADC_V_REFERENCE_AVCC,
    ADC_V_REFERENCE_INTERNAL_2_56 = 3,

}ADC_v_reference_t;

typedef enum {
	ADC_RIGHT_ADJUST,
	ADC_LEFT_ADJUST,
}ADC_adjust_t;


typedef enum {
	ADC_PRESCALER_2=1,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128,
}ADC_prescaler_t;

typedef enum {
	ADC_FREE_RUNNING,
	ADC_ANALOG_COMP,
	ADC_EXT_INT0,
	ADC_TIM0_COMP_MATCH,
	ADC_TIM0_OVF,
	ADC_TIM1_COMP_MATCH,
	ADC_TIM1_OVF,
	ADC_TIM1_CAPTURE,
}ADC_trigger_source_t;




typedef struct {
#if ADC_INTERRUPT_FEATURE == ADC_INT_ON
	func_ptr  ADC_APP_INT_handler;
#endif
	DIO_pin_config_t   ADC_pin;
	ADC_channel_t      ADC_channel;
	ADC_v_reference_t  ADC_V_reference;
	ADC_prescaler_t    ADC_prescaler;
	ADC_adjust_t       ADC_adjust;
	ADC_trigger_source_t ADC_trigger_src;
}ADC_CONF_t;


/***********************function prototypes********************************************/
/*
 * Name        : EEPROM_WriteByte
 * Description : Write byte in specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_u8Data     : Data will be written in EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType ADC_init(ADC_CONF_t *ADC);
/*********************************************************************************************/
/*
 * Name        : EEPROM_ReadByte
 * Description : read byte from specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_pu8Data : pointer to address of Data will be read from EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */

Std_ReturnType ADC_read_value_polling(ADC_CONF_t *ADC,u16 *Copy_pu16DigitalValue);
/***************************************************************************************/



/*
 * Name        : EEPROM_ReadByte
 * Description : read byte from specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_pu8Data : pointer to address of Data will be read from EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */



Std_ReturnType ADC_read_value_INTERRUPT(ADC_CONF_t *ADC,u16 *Copy_pu16DigitalValue);
/******************************************helper functions***********************************************/



#endif /* MCAL_ADC_ADC_INT_H_ */
