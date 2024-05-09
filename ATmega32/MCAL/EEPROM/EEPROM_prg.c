/*
 * EEPROM_prg.c
 *
 *  Created on: Jan 26, 2024
 *      Author: Zbook
 */

/**********************includes*******************************************************/
#include "EEPROM_int.h"
#include "util/delay.h"
/**************************************************************************************/
/*************************macros*******************************************************/
/**************************************************************************************/

/***********************function defintitions ********************************************/
/*
 * Name        : EEPROM_WriteByte
 * Description : Write byte in specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_u8Data     : Data will be written in EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType EEPROM_WriteByte( u16 Copy_u16Address , u8 Copy_u8Data) {
	Std_ReturnType return_value = E_OK;
	if ((Copy_u16Address > EEPROM_MAX_ADDRESS)||(Copy_u8Data>255)){
		return_value = E_NOK;
	}
	else {
		while (GET_BIT(EEPROM_u8_EECR_REG,EEPROM_u8_EECR_EEWE_BIT));

		EEPROM_u16_EEARL_REG =  Copy_u16Address ;
		EEPROM_u16_EEARH_REG =  ((Copy_u16Address >>8) &0x03);
		EEPROM_u8_EEDR_REG =Copy_u8Data;

		__asm__
		(
				"sbi 0x1c, 2;"
		);
		__asm__
		(
				"sbi 0x1c, 1;"
		);

	}

	return return_value ;
}

/*
 * Name        : EEPROM_ReadByte
 * Description : read byte from specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_pu8Data : pointer to address of Data will be read from EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType EEPROM_ReadByte( u16 Copy_u16Address, u8 *Copy_pu8Data){

	Std_ReturnType return_value = E_OK;
	if ((Copy_u16Address > EEPROM_MAX_ADDRESS)||(Copy_pu8Data==NULL)){
		return_value = E_NOK;
	}
	else {
		while (GET_BIT(EEPROM_u8_EECR_REG,EEPROM_u8_EECR_EEWE_BIT));
				EEPROM_u16_EEARL_REG =  Copy_u16Address ;
				EEPROM_u16_EEARH_REG =  ((Copy_u16Address >>8) &0x03);
				SET_BIT(EEPROM_u8_EECR_REG,EEPROM_u8_EECR_EERE_BIT);
				*Copy_pu8Data = EEPROM_u8_EEDR_REG;

	}

	return return_value ;
}
