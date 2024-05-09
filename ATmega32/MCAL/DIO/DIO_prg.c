/*
 * DIO_prg.c
 *
 *  Created on: Jan 8, 2024
 *      Author: Zbook
 */
/********************includes*****************************************************************/
#include "DIO_int.h"
/********************************************************************************************/

Std_ReturnType volatile *DDR_registers[] = { DIO_u8_DDRA_REG, DIO_u8_DDRB_REG,
DIO_u8_DDRC_REG, DIO_u8_DDRD_REG };
Std_ReturnType volatile *PORT_registers[] = { DIO_u8_PORTA_REG,
DIO_u8_PORTB_REG, DIO_u8_PORTC_REG, DIO_u8_PORTD_REG };
Std_ReturnType volatile *PIN_registers[] = { DIO_u8_PINA_REG, DIO_u8_PINB_REG,
DIO_u8_PINC_REG, DIO_u8_PIND_REG };

/*Name:			DIO_u8Init
 * Description: Initialize all MCU Pins
 * Arguments: 	vid
 * Return :	  	return_value {E_ok,E-NOK}
 */
Std_ReturnType DIO_init(void) {
	Std_ReturnType return_value = E_OK;
	/*Old Values
	 * DIO_u8_OUTPUT_LOW		-->0
	 * DIO_u8_OUTPUT_HIGH		-->1
	 * DIO_u8_INPUT_FLOATING	-->2
	 * DIO_u8_INPUT_PULLUP		-->3
	 *
	 * */

	//Undefine old values
#undef DIO_u8_OUTPUT_LOW
#undef DIO_u8_OUTPUT_HIGH
#undef DIO_u8_INPUT_FLOATING
#undef DIO_u8_INPUT_PULLUP

	//Define new values
#define DIO_u8_OUTPUT_LOW		1
#define DIO_u8_OUTPUT_HIGH		1
#define DIO_u8_INPUT_FLOATING	0
#define DIO_u8_INPUT_PULLUP		0
	*DDR_registers[DIO_PORTA] = CONC(DIO_u8_PORTA_PIN7, DIO_u8_PORTA_PIN6,
			DIO_u8_PORTA_PIN5, DIO_u8_PORTA_PIN4, DIO_u8_PORTA_PIN3,
			DIO_u8_PORTA_PIN2, DIO_u8_PORTA_PIN1, DIO_u8_PORTA_PIN0);
	*DDR_registers[DIO_PORTB] = CONC(DIO_u8_PORTB_PIN7, DIO_u8_PORTB_PIN6,
			DIO_u8_PORTB_PIN5, DIO_u8_PORTB_PIN4, DIO_u8_PORTB_PIN3,
			DIO_u8_PORTB_PIN2, DIO_u8_PORTB_PIN1, DIO_u8_PORTB_PIN0);
	*DDR_registers[DIO_PORTC] = CONC(DIO_u8_PORTC_PIN7, DIO_u8_PORTC_PIN6,
			DIO_u8_PORTC_PIN5, DIO_u8_PORTC_PIN4, DIO_u8_PORTC_PIN3,
			DIO_u8_PORTC_PIN2, DIO_u8_PORTC_PIN1, DIO_u8_PORTC_PIN0);
	*DDR_registers[DIO_PORTD] = CONC(DIO_u8_PORTD_PIN7, DIO_u8_PORTD_PIN6,
			DIO_u8_PORTD_PIN5, DIO_u8_PORTD_PIN4, DIO_u8_PORTD_PIN3,
			DIO_u8_PORTD_PIN2, DIO_u8_PORTD_PIN1, DIO_u8_PORTD_PIN0);

	/*Old Value
	 * DIO_u8_OUTPUT_LOW		-->1
	 * DIO_u8_OUTPUT_HIGH		-->1
	 * DIO_u8_INPUT_FLOATING	-->0
	 * DIO_u8_INPUT_PULLUP		-->0
	 *
	 * */
	//Undefine old values
#undef DIO_u8_OUTPUT_LOW
#undef DIO_u8_OUTPUT_HIGH
#undef DIO_u8_INPUT_FLOATING
#undef DIO_u8_INPUT_PULLUP

	//Define new values
#define DIO_u8_OUTPUT_LOW		0
#define DIO_u8_OUTPUT_HIGH		1
#define DIO_u8_INPUT_FLOATING	0
#define DIO_u8_INPUT_PULLUP		1

*PORT_registers[DIO_PORTA]=CONC(DIO_u8_PORTA_PIN7,DIO_u8_PORTA_PIN6
		,DIO_u8_PORTA_PIN5,DIO_u8_PORTA_PIN4
		,DIO_u8_PORTA_PIN3,DIO_u8_PORTA_PIN2
		,DIO_u8_PORTA_PIN1,DIO_u8_PORTA_PIN0);
*PORT_registers[DIO_PORTB]=CONC(DIO_u8_PORTB_PIN7,DIO_u8_PORTB_PIN6
		,DIO_u8_PORTB_PIN5,DIO_u8_PORTB_PIN4
		,DIO_u8_PORTB_PIN3,DIO_u8_PORTB_PIN2
		,DIO_u8_PORTB_PIN1,DIO_u8_PORTB_PIN0);
*PORT_registers[DIO_PORTC]=CONC(DIO_u8_PORTC_PIN7,DIO_u8_PORTC_PIN6
		,DIO_u8_PORTC_PIN5,DIO_u8_PORTC_PIN4
		,DIO_u8_PORTC_PIN3,DIO_u8_PORTC_PIN2
		,DIO_u8_PORTC_PIN1,DIO_u8_PORTC_PIN0);
*PORT_registers[DIO_PORTD]=CONC(DIO_u8_PORTD_PIN7,DIO_u8_PORTD_PIN6
		,DIO_u8_PORTD_PIN5,DIO_u8_PORTD_PIN4
		,DIO_u8_PORTD_PIN3,DIO_u8_PORTD_PIN2
		,DIO_u8_PORTD_PIN1,DIO_u8_PORTD_PIN0);
#undef DIO_u8_OUTPUT_LOW
#undef DIO_u8_OUTPUT_HIGH
#undef DIO_u8_INPUT_FLOATING
#undef DIO_u8_INPUT_PULLUP
/*redefine old values */
#define DIO_u8_OUTPUT_LOW		0
#define DIO_u8_OUTPUT_HIGH		1
#define DIO_u8_INPUT_FLOATING	2
#define DIO_u8_INPUT_PULLUP		3


return return_value;
}

/* name          DIO_write_pin_direction
 * description   Set PIN Direction
 * arguments     first =>  pinconfig : pointer to struct of pin configurations
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DIO_write_pin_direction(const DIO_pin_config_t *pinconfig) {
Std_ReturnType return_value = E_OK;
if ((NULL == pinconfig) || (pinconfig->port > DIO_PORTD)
		|| (pinconfig->pin > DIO_PIN7)) {
	return_value = E_NOK;
} else {
	switch (pinconfig->direction) {
	case DIO_OUTPUT:
		SET_BIT(*DDR_registers[pinconfig->port], pinconfig->pin);
		break;
	case DIO_INPUT:
		CLR_BIT(*DDR_registers[pinconfig->port], pinconfig->pin);
		break;
	default:
		return_value = E_NOK;
	}
}

return return_value;
}
/*******************************************************************************************************************/
/* name   DIO_read_pin_direction
 * description   READ PIN Direction
 * arguments     first =>  pinconfig
 *               second => direction_status
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_read_pin_direction(DIO_pin_config_t *pinconfig,
	DiO_direction_t *direction_status) {
Std_ReturnType return_value = E_OK;
if ((pinconfig == NULL) || (direction_status == NULL)
		|| (pinconfig->pin > DIO_PIN7) || (pinconfig->port > DIO_PORTD)) {
	return_value = E_NOK;
} else {
	*direction_status = GET_BIT(*DDR_registers[pinconfig->port],
			pinconfig->pin);
}

return return_value;
}
/***************************************************************************************************************************************/
/* name   DIO_write_pin_logic
 * description   Set PIN Direction
 * arguments     first =>  pinconfig
 *               second => logic
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_write_pin_logic(const DIO_pin_config_t *pinconfig,
	DIO_logic_t logic) {
Std_ReturnType return_value = E_OK;
if ((NULL == pinconfig) || (pinconfig->port > DIO_PORTD)
		|| (pinconfig->pin > DIO_PIN7)) {
	return_value = E_NOK;
} else {
	switch (logic) {
	case DIO_HIGH:
		SET_BIT(*PORT_registers[pinconfig->port], pinconfig->pin);
		break;
	case DIO_LOW:
		CLR_BIT(*PORT_registers[pinconfig->port], pinconfig->pin);
		break;
	default:
		return_value = E_NOK;
	}
}

return return_value;
}
/*******************************************************************************************************************************/
Std_ReturnType DIO_read_pin_logic(const DIO_pin_config_t *pinconfig,
	DIO_logic_t*logic_status) {
Std_ReturnType return_value = E_OK;
if ((pinconfig == NULL) || (logic_status == NULL) || (pinconfig->pin > DIO_PIN7)
		|| (pinconfig->port > DIO_PORTD)) {
	return_value = E_NOK;
} else {
	*logic_status = GET_BIT(*PIN_registers[pinconfig->port], pinconfig->pin);
}

return return_value;
}
/************************************************************************************************************************************/
/* name   DIO_toggle_pin_logic
 * description   toggle PIN logic
 * arguments     first =>  pinconfig      options (PORTA, PORTB,PORTC,PORTD)
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_toggle_pin_logic	(DIO_pin_config_t *pinconfig) {
Std_ReturnType return_value = E_OK;
if ((pinconfig == NULL) || (pinconfig->pin > DIO_PIN7)
		|| (pinconfig->port > DIO_PORTD)) {
	return_value = E_NOK;
} else {
	TGL_BIT(*PORT_registers[pinconfig->port], pinconfig->pin);
}
return return_value;
}
/************************************************************************************************************************************************/
/* name          DIO_write_port_direction
 * description   Set port Direction
 * arguments     first =>  port :
 * 				 second=>  direction :
 * return        (E_OK,E_NOK)
 */
Std_ReturnType DIO_write_port_direction(DIO_port_index_t port, u8 direction) {
Std_ReturnType return_value = E_OK;
if ((direction > DIO_OUTPUT) || (port > DIO_PORTD)) {
	return_value = E_NOK;
} else {
	switch (direction) {
	case DIO_INPUT:
		*DDR_registers[port] = DIO_u8_LOW;
		break;
	case DIO_OUTPUT:
		*DDR_registers[port] = DIO_u8_HIGH;
		break;
	}
}
return return_value;

}
/*******************************************************************************************************************/

/* name   DIO_read_port_direction
 * description   READ PORT Direction
 * arguments     first =>  port
 *               second => direction_status
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_read_port_direction(DIO_port_index_t port,
	u8 *direction_status) {
Std_ReturnType return_value = E_OK;
if (port > DIO_PORTD) {
	return_value = E_NOK;
} else {
	*direction_status = GET_REG(*DDR_registers[port]);

}
return return_value;
}

/* name   DIO_write_port_logic
 * description   Set PIN logic
 * arguments     first =>  pinconfig
 *               second => logic
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_write_port_logic(DIO_port_index_t port, u8 logic) {
Std_ReturnType return_value = E_OK;
if ((logic > DIO_u8_HIGH) || (port > DIO_PORTD)) {
	return_value = E_NOK;
} else {
	switch (logic) {
	case DIO_u8_HIGH:
		*PORT_registers[port] = DIO_u8_HIGH;
		break;
	case DIO_u8_LOW:
		*PORT_registers[port] = DIO_u8_LOW;
		break;
	}
}

return return_value;

}
/**********************************************************************************************************************/
/* name   DIO_read_port_logic
 * description   read PIN logic
 * arguments     first =>  port      options (PORTA, PORTB,PORTC,PORTD)
 *               second => *logic_status
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_read_port_logic(DIO_port_index_t port, u8 *logic_status) {

Std_ReturnType return_value = E_OK;
if (port > DIO_PORTD) {
	return_value = E_NOK;
} else {
	*logic_status = GET_REG(*PIN_registers[port]);

}
return return_value;
}
/*************************************************************************************************************/
/* name   DIO_toggle_port_logic
 * description   toggle port logic
 * arguments     first =>  port
 * return   (E_OK,E_NOK)
 */
Std_ReturnType DIO_toggle_port_logic(DIO_port_index_t port) {
Std_ReturnType return_value = E_OK;
if (port > DIO_PORTD) {
	return_value = E_NOK;
} else {
	TGL_REG(*PORT_registers[port]);
}
return return_value;
}


/***************************************************************************************************************/

