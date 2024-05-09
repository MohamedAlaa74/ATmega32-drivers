/*
 * app.c
 *
 *  Created on: Jan 8, 2024
 *      Author: Zbook
 */


#include "app.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/G_INT/G_INT_int.h"
#include "../MCAL/EXT_INT/EXT_INT_int.h"
#include "../MCAL/EEPROM/EEPROM_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/GPT/GPT_int.h"
#include "../MCAL/USART/UART_int.h"
void tim0_handler (void);
void isr_init(void);

volatile u8 adc_flag = 0;
u8 customChar[] = {
  0x1F,
  0x11,
  0x11,
  0x11,
  0x1F,
  0x1F,
  0x1F,
  0x00
};

ADC_CONF_t adc = {
		.ADC_channel= ADC_CHANNEL0,
		.ADC_trigger_src = ADC_FREE_RUNNING,
		.ADC_prescaler = ADC_PRESCALER_64,
		.ADC_pin.port= DIO_PORTA,
		.ADC_pin.pin= DIO_PIN0,
		.ADC_pin.direction= DIO_INPUT,
		.ADC_V_reference = ADC_V_REFERENCE_AVCC	,
		.ADC_adjust =ADC_RIGHT_ADJUST,


};
EXT_INT_CONF_t ext = {
		.pin.port = DIO_PORTD,
		.pin.pin = DIO_PIN3,
		.pin.direction = DIO_INPUT,
		.type = EXT_INT_1,
		.mode = EXT_INT_u8_RISING_EDGE,
		.APP_INT_handler = isr_init
};
 GPT_t tim0 = {
	.GPT_num = GPT_TIMER0,
	.GPT_mode = GPT_CTC_MODE,
	.GPT_clk = GPT_PRESCALER_8,
	.GPT_compare_match_value = 100,
	.APP_TIMER0_INT_HANDLER = tim0_handler,
};

 UART_CONF_t uart = {
		 .UART_baud = UART_BR_9600,
		 .UART_mode = UART_MODE_ASYNC,

		 .UART_data_size = UART_DATA_SIZE_8_BIT,
		 .UART_stop_bits = UART_STOP_BITS_1,

 };

u16 x;
u8 flag=1;
int main() {
 *DIO_u8_DDRD_REG |= 0XFF;

	UART_init(&uart);

	while (1){
		UART_ASYNC_write_byte(&uart,'a');
}
}





	/*
	LED_pin_init();
	DC_MOTOR_pin_init();
	KEYPAD_init();
	u8 kee ;
	while (1) {

		KEYPAD_read_value(&key,&kee);
		if ('7' == kee){
				LED_on(&led1);
		}
		else if ('8' == kee){
			LED_off(&led1);
		}


	}
	*/

/*
 DIO_write_port_direction(DIO_PORTD,DIO_OUTPUT);
 DIO_write_port_logic(DIO_PORTD,DIO_LOW);
 while(1){
 DIO_read_port_logic(DIO_PORTD,&stat);
 if (stat == DIO_u8_LOW){
 DIO_write_port_logic(DIO_PORTA,DIO_HIGH);
 _delay_ms(200);
 }
 DIO_write_port_logic(DIO_PORTA,DIO_LOW);
 */

/*
 DIO_write_pin_direction(&led1);
 DIO_write_pin_logic(&led1,DIO_HIGH);
 _delay_ms(500);
 DIO_toggle_pin_logic(&led1);
 _delay_ms(500);
 */

/*while (1){
 DIO_read_pin_logic(&led2,&stat);
 if (stat == DIO_HIGH){
 DIO_write_pin_logic(&led1,DIO_HIGH);

 }
 else {
 DIO_write_pin_logic(&led1,DIO_LOW);
 }*/
void app_init(void){
ECU_init();
}
void isr_init(void){
	DIO_toggle_port_logic(DIO_PORTB);
}
void tim0_handler (void){
	DIO_toggle_port_logic(DIO_PORTA);
}


