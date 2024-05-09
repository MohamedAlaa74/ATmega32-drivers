/*
 * app.h
 *
 *  Created on: Jan 18, 2024
 *      Author: MOHAMED ALAA
 */

#ifndef APP_APP_H_
#define APP_APP_H_
#include "../ECU/ECU_init/ECU_init.h"
#include <util/delay.h>

void app_init(void);
extern LCD_8bit_t	 lcd1;

extern LCD_4bit_t	 lcd2;
extern LED_t         led1;
extern LED_t         led2;
extern LED_t         led3;

#endif /* APP_APP_H_ */
