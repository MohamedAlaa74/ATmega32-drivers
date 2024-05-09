/*
 * EEPROM_int.h
 *
 *  Created on: Jan 26, 2024
 *      Author: Zbook
 */

#ifndef MCAL_EEPROM_EEPROM_INT_H_
#define MCAL_EEPROM_EEPROM_INT_H_
/**********************includes*******************************************************/
#include "../../LIBRARIES/STD_TYPES.h"
#include "../../LIBRARIES/BIT_MATHS.h"
#include "EEPROM_prv.h"
/**************************************************************************************/
/*************************macros*******************************************************/
#define EEPROM_START_ADDRESS  0x00
#define  EEPROM_MAX_ADDRESS   0x3FF


#define EEPROM_u8_EECR_EERIE_BIT	3
#define EEPROM_u8_EECR_EEMWE_BIT	2
#define EEPROM_u8_EECR_EEWE_BIT    1
#define EEPROM_u8_EECR_EERE_BIT		0
/**************************************************************************************/

/***********************function prototypes********************************************/
/*
 * Name        : EEPROM_WriteByte
 * Description : Write byte in specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_u8Data     : Data will be written in EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType EEPROM_WriteByte( u16 Copy_u16Address , u8 Copy_u8Data) ;
/*********************************************************************************************/
/*
 * Name        : EEPROM_ReadByte
 * Description : read byte from specific address in EEPROM
 * Arguments   :  Copy_u16Address : Address to write data in  RANGE (0x000: 0x3FF)
 * 				  Copy_pu8Data : pointer to address of Data will be read from EEPROM ADDRESS
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType EEPROM_ReadByte( u16 Copy_u16Address, u8 *Copy_pu8Data);

/***************************************************************************************/


#endif /* MCAL_EEPROM_EEPROM_INT_H_ */
