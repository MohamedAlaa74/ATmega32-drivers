/*
 * UART_prg.c
 *
 *  Created on: Feb 6, 2024
 *      Author: Zbook
 */

/************************************includes ********************************************/
#include "UART_int.h"
/***********************function definitions ********************************************/
/*
 * Name        : UART_init
 * Description : initialize UART module
 * Arguments   :  UART : pointer to UART post-build configurations
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType UART_init(UART_CONF_t *UART){
	Std_ReturnType return_value = E_OK;
		if (UART == NULL){
			return_value = E_NOK;
		}
		else {


	switch (UART->UART_mode) {
		case UART_MODE_SYNC :SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
							 SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UMSEL_BIT);
			break;
		case UART_MODE_ASYNC:SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
							 CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UMSEL_BIT);
			break;
	}


	switch (UART->UART_parity) {
			case UART_NO_PARITY :      SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
								       CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UPM0_BIT);
								       CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UPM1_BIT);break;

			case UART_ODD_PARITY:      SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
		     	   	   	   	   	   	   CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UPM0_BIT);
		       	   	   	   	   	   	   SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UPM1_BIT);break;

			case UART_EVEN_PARITY:     SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
									   SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UPM0_BIT);
									   SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UPM1_BIT);break;
		}
	switch (UART->UART_stop_bits) {
				case UART_STOP_BITS_1 :     SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
									        CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_USBS_BIT);break;


				case UART_STOP_BITS_2:      SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
			     	   	   	   	   	   	    SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_USBS_BIT); break;

			}
	switch (UART->UART_data_size) {
			case UART_DATA_SIZE_5_BIT :     SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
											CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ0_BIT);
											CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ1_BIT);
											CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);break;


			case UART_DATA_SIZE_6_BIT:      SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
											SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ0_BIT);
											CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ1_BIT);
											CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);break;

			case UART_DATA_SIZE_7_BIT:      SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
											CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ0_BIT);
											SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ1_BIT);
											CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);break;

			case UART_DATA_SIZE_8_BIT:      SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
										    SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ0_BIT);
										    SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ1_BIT);
										    CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);break;

			case UART_DATA_SIZE_9_BIT:      SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
											SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ0_BIT);
											SET_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_UCSZ1_BIT);
											SET_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_UCSZ2_BIT);break;
		}
	switch (UART->UART_baud) {
					case UART_BR_2400 :   CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
					                      ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_2400 >>8));
										  ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_2400);break;

					case UART_BR_4800:     CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
										   ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_4800);
										   ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_4800 >>8));break;

					case UART_BR_9600:      CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
					   	   	   	   	   	   	ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_9600);
											ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_9600 >>8));break;

					case UART_BR_14400 :   CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
										   ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_14400);
										   ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_14400 >>8));break;

					case UART_BR_19200:     CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
										    ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_19200);
											ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_19200 >>8));break;

					case UART_BR_28800:      CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
					   	   	   	   	   	     ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_28800);
											 ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_28800 >>8));break;

					case UART_BR_38400 :      CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
											  ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_38400);
											  ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_38400 >>8));break;


					case UART_BR_57600:     CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
											ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_57600);
										    ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_57600 >>8));break;


					case UART_BR_76800:      CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
						   	   	   	   	   	 ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_76800);
											 ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_76800 >>8));break;

					case UART_BR_115200 :   CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
											ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_115200);
									        ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_115200 >>8));break;



					case UART_BR_250000:      CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
								   	   	      ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_250000);
											  ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_250000 >>8));break;

					case UART_BR_500000:      CLR_BIT(UART_u8_UCSRC_REG,UART_u8_UCSRC_URSEL_BIT);
										      ASSIGN_REG(UART_u8_UBRRL_REG,UART_BR_500000);
											  ASSIGN_REG(UART_u8_UBRRH_REG,(UART_BR_500000 >>8));break;
				}

		}
		return return_value;
}
/**************************************************************************************************/
/*
 * Name        : UART_ASYNC_write_byte
 * Description : send data at TX pin
 * Arguments   :  UART : pointer to UART post-build configurations
 * 				Copy_u16Data :  DATA will be send
 * Return      :  E_OK,E_NOK
 */

Std_ReturnType UART_ASYNC_write_byte(UART_CONF_t *UART,u16 Copy_u16Data){
	Std_ReturnType return_value = E_OK;
		if ((Copy_u16Data > 0xFFFF )||(UART == NULL)){
			return_value = E_NOK;
		}
		else {
			SET_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_TXEN_BIT);
			if (UART->UART_data_size == UART_DATA_SIZE_9_BIT){
				while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_UCSRA_UDRE_BIT)==0);
				ASSIGN_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_TXB8_BIT,((Copy_u16Data>>8)&0x01));
				UART_u8_UDR_REG = (u8)Copy_u16Data;
			}
			else {
				while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_UCSRA_UDRE_BIT)==0);
				UART_u8_UDR_REG = Copy_u16Data;
			}
		 }
				return return_value;
}
/***************************************************************************************/
/*
 * Name        : UART_ASYNC_read_byte
 * Description : receive data at RX pin
 * Arguments   :  UART : pointer to UART post-build configurations
 * 					Copy_Pu16Data => pointer to variable store received data
 * Return      :  E_OK,E_NOK
 */

Std_ReturnType UART_ASYNC_read_byte(UART_CONF_t *UART,u16 *Copy_Pu16Data){
	Std_ReturnType return_value = E_OK;
			if ((Copy_Pu16Data == NULL )||(UART == NULL)){
				return_value = E_NOK;
			}
			else {
				SET_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_RXEN_BIT);
				if (UART->UART_data_size == UART_DATA_SIZE_9_BIT){
					while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_UCSRA_RXC_BIT== 0));
				*Copy_Pu16Data =  GET_BIT(UART_u8_UCSRB_REG,UART_u8_UCSRB_RXB8_BIT);
				*Copy_Pu16Data = (u8)UART_u8_UDR_REG;

				}
				else {
					while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_UCSRA_RXC_BIT)==0);

					 *Copy_Pu16Data = (u8) UART_u8_UDR_REG ;
				}
			 }
					return return_value;
	}
/*********************************************************************************************************************************/
/*
 * Name        : UART_ASYNC_write_string
 * Description : send string at uart tx pin
 * Arguments   :  UART : pointer to UART post-build configurations
 * 					Copy_Pu8Str => pointer to string will be sent
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType UART_ASYNC_write_string(UART_CONF_t *UART, u16 *Copy_Pu8Str){
	Std_ReturnType return_value = E_OK;
	if ((Copy_Pu8Str == NULL )||(UART == NULL)){
				return_value = E_NOK;
			}
			else {
				while (*Copy_Pu8Str != '\0'){
					UART_ASYNC_write_byte(UART,*Copy_Pu8Str);
		                 Copy_Pu8Str++;
				}
				}


					return return_value;
}
/****************************************************************************************************************/
/*
 * Name        : UART_ASYNC_read_string
 * Description : receive string at RX pin
 * Arguments   :  UART : pointer to UART post-build configurations
 * 					Copy_Pu8Str => pointer to string store received data
 * Return      :  E_OK,E_NOK
 */
Std_ReturnType UART_ASYNC_read_string(UART_CONF_t *UART ,u16 *Copy_Pu8Str){
	Std_ReturnType return_value = E_OK;
	if ((Copy_Pu8Str == NULL )||(UART == NULL)){
				return_value = E_NOK;
			}
	else {
		while (*Copy_Pu8Str != '\0'){
						UART_ASYNC_read_byte(UART,Copy_Pu8Str);
						Copy_Pu8Str++;
						}
						}


					return return_value;
}
/***************************************************************************************/
