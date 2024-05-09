/*
 * G_INT_prg.c
 *
 *  Created on: Jan 22, 2024
 *      Author: Zbook
 */


/****************************************includes**************************************************/
#include "G_INT_int.h"



/***************************************function definitions**************************************/
/*Name:			G_INT_Enable
 * Description: Enable Global Interrupts
 * Arguments: 	void
 * Return :	  	return_value {E_ok,E-NOK}
  */
Std_ReturnType G_INT_Enable(void){
	Std_ReturnType return_value = E_OK;
	G_INT_u8_SREG_REG.I_bit = 1;


	return return_value;
}
/******************************************************************************************************************/

/*Name:		G_INT_Disable
* Description: disable Global Interrupts
* Arguments: 	void
* Return :	  	return_value {E_ok,E-NOK}
 */
Std_ReturnType G_INT_Disable(void){
	Std_ReturnType return_value = E_OK;
	CLR_BIT  (G_INT_u8_SREG_REG.G_INT_u8_SREG,G_INT_u8_SREG_I_BIT);

		return return_value;
}
/************************************************************************************************************************/
