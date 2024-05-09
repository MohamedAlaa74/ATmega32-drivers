/*
 * ECU_init.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Zbook
 */

#include "ECU_init.h"
#include "../LCD/LCD_int.h"
LED_t led1 = { .port = DIO_PORTC, .pin = DIO_PIN6,

};
u8 stat;
LED_t led2 = { .port = DIO_PORTD, .pin = DIO_PIN4,

};
LED_t led3 = { .port = DIO_PORTA, .pin = DIO_PIN6,

};
BTN_t btn_low = { .BTN_pin.port = DIO_PORTD, .BTN_pin.pin = DIO_PIN7,
		.BTN_connection = BTN_ACTIVE_HIGH, .BTN_status = BTN_RELEASED };
BTN_status_t btn_state = BTN_RELEASED;
RELAY_t Relay = { .port = DIO_PORTC, .pin = DIO_PIN0 };

DC_MOTOR_t motor1 = { .dc_motor[0].port = DIO_PORTB,
		.dc_motor[0].pin = DIO_PIN0, .dc_motor[1].port = DIO_PORTB,
		.dc_motor[1].pin = DIO_PIN1, };
DC_MOTOR_t motor2 = { .dc_motor[0].port = DIO_PORTB,
		.dc_motor[0].pin = DIO_PIN2, .dc_motor[1].port = DIO_PORTB,
		.dc_motor[1].pin = DIO_PIN3, };

SEGMANT_t seg1 = {
		.segmant_pins[0].port = DIO_PORTA,
		.segmant_pins[0].pin = DIO_PIN0,
		.segmant_pins[1].port = DIO_PORTA,
		.segmant_pins[1].pin = DIO_PIN1,
		.segmant_pins[2].port = DIO_PORTA,
		.segmant_pins[2].pin = DIO_PIN2,
		.segmant_pins[3].port = DIO_PORTA,
		.segmant_pins[3].pin = DIO_PIN3,
		.segmant_type = SEGMANT_COMMON_ANODE
};

KEYPAD_t key = {
	.keypad_row_pins[0].port = DIO_PORTD,
	.keypad_row_pins[0].pin = DIO_PIN0,
	.keypad_row_pins[1].port = DIO_PORTD,
	.keypad_row_pins[1].pin = DIO_PIN1,
	.keypad_row_pins[2].port = DIO_PORTD,
	.keypad_row_pins[2].pin = DIO_PIN2,
	.keypad_row_pins[3].port = DIO_PORTD,
	.keypad_row_pins[3].pin = DIO_PIN3,

		.keypad_columns_pins[0].port = DIO_PORTD,
		.keypad_columns_pins[0].pin = DIO_PIN4,
		.keypad_columns_pins[1].port = DIO_PORTD,
		.keypad_columns_pins[1].pin = DIO_PIN5,
		.keypad_columns_pins[2].port = DIO_PORTD,
		.keypad_columns_pins[2].pin = DIO_PIN6,
		.keypad_columns_pins[3].port = DIO_PORTD,
		.keypad_columns_pins[3].pin = DIO_PIN7,


};
LCD_8bit_t lcd1 = {
		.LCD_rs.port = DIO_PORTC,
		.LCD_rs.pin = DIO_PIN4,
		.LCD_en.port = DIO_PORTC,
		.LCD_en.pin = DIO_PIN5,
		.LCD_data [0].port = DIO_PORTD,
		.LCD_data [0].pin = DIO_PIN0,
		.LCD_data [1].port = DIO_PORTD,
		.LCD_data [1].pin = DIO_PIN1,
		.LCD_data [2].port = DIO_PORTD,
		.LCD_data [2].pin = DIO_PIN2,
		.LCD_data [3].port = DIO_PORTD,
		.LCD_data [3].pin = DIO_PIN3,
		.LCD_data [4].port = DIO_PORTD,
		.LCD_data [4].pin = DIO_PIN4,
		.LCD_data [5].port = DIO_PORTD,
		.LCD_data [5].pin = DIO_PIN5,
		.LCD_data [6].port = DIO_PORTD,
		.LCD_data [6].pin = DIO_PIN6,
		.LCD_data [7].port = DIO_PORTD,
	    .LCD_data [7].pin = DIO_PIN7,



};
LCD_4bit_t lcd2 = {
		.LCD_rs.port = DIO_PORTC,
		.LCD_rs.pin = DIO_PIN6,
		.LCD_en.port = DIO_PORTC,
		.LCD_en.pin = DIO_PIN7,
		.LCD_data [0].port = DIO_PORTC,
		.LCD_data [0].pin = DIO_PIN0,
		.LCD_data [1].port = DIO_PORTC,
		.LCD_data [1].pin = DIO_PIN1,
		.LCD_data [2].port = DIO_PORTC,
		.LCD_data [2].pin = DIO_PIN2,
		.LCD_data [3].port = DIO_PORTC,
		.LCD_data [3].pin = DIO_PIN3,
};
void ECU_init(void){
	DIO_init();
	LED_pin_init();


}
