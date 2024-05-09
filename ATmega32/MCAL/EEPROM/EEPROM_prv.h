/*
 * EEPROM_prv.h
 *
 *  Created on: Jan 26, 2024
 *      Author: Zbook
 */

#ifndef MCAL_EEPROM_EEPROM_PRV_H_
#define MCAL_EEPROM_EEPROM_PRV_H_


#define EEPROM_u16_EEARL_REG 		*((volatile u8*)	0x3E)
#define EEPROM_u16_EEARH_REG 		*((volatile u8*)	0x3F)
#define EEPROM_u8_EEDR_REG 			*((volatile u8*)	0x3D)
#define EEPROM_u8_EECR_REG 			*((volatile u8*)	0x3C)



#endif /* MCAL_EEPROM_EEPROM_PRV_H_ */
