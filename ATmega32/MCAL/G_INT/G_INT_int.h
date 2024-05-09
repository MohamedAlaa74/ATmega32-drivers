/*
 * G_INT_int.h
 *
 *  Created on: Jan 22, 2024
 *      Author: Zbook
 */

#ifndef MCAL_G_INT_G_INT_INT_H_
#define MCAL_G_INT_G_INT_INT_H_

/********************************includes********************************************************/

#include "../../LIBRARIES/BIT_MATHS.h"
#include "../../LIBRARIES/STD_TYPES.h"
#include "G_INT_prv.h"
#include "G_INT_cfg.h"
/******************************************************************************************/
/********************************macros***********************************************************/

/***********************************************************************************************/
/************************* data type declarations ***********************************************************/

/**************************************************************************************************************/
/*****************************Function declarations***********************************************************/

/*Name:			G_INT_Enable
 * Description: Enable Global Interrupts
 * Arguments: 	Std_ReturnType
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType G_INT_Enable(void);
/************************************************************************************************************************/
 /*Name:		G_INT_Disable
 * Description: disable Global Interrupts
 * Arguments: 	Std_ReturnType
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType G_INT_Disable(void);
/***************************************************************************************************************/
#endif /* MCAL_G_INT_G_INT_INT_H_ */
