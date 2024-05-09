/*
 * LCD_prg.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Zbook
 */
/********************************includes**********************************************************/
#include "LCD_int.h"
static Std_ReturnType convert_int_to_string(u32 value, u8 *str);
static Std_ReturnType LCD_send_4bits(const LCD_4bit_t *LCD, u8 data_command);
static Std_ReturnType LCD_send_4bit_enable(const LCD_4bit_t *LCD);
static Std_ReturnType LCD_send_8bit_enable(const LCD_8bit_t *LCD);
static Std_ReturnType LCD_8bit_set_cursor(const LCD_8bit_t *LCD, u8 row,
		u8 column);
static Std_ReturnType LCD_4bit_set_cursor(const LCD_4bit_t *LCD, u8 row,
		u8 column);
/********************************macros************************************************************/

/******************************************************************************************************/
/*******************************function definitions***************************************************/

//#if LCD_BIT_MODE == LCD_4BIT_MODE
Std_ReturnType LCD_4bit_init(const LCD_4bit_t *LCD) {
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		DIO_init();
		_delay_ms(20);
		return_value = LCD_4bit_send_command(LCD, LCD_8BIT_MODE_2LINE);
		_delay_ms(5);
		return_value = LCD_4bit_send_command(LCD, LCD_8BIT_MODE_2LINE);
		_delay_us(150);
		return_value = LCD_4bit_send_command(LCD, LCD_8BIT_MODE_2LINE);
		/*************optional************************/
		return_value = LCD_4bit_send_command(LCD, LCD_CLEAR);
		return_value = LCD_4bit_send_command(LCD, LCD_RETURN_HOME);
		return_value = LCD_4bit_send_command(LCD, LCD_ENTRY_MODE);
		return_value = LCD_4bit_send_command(LCD, LCD_CURSOR_OFF_DISPLAY_ON);
		return_value = LCD_4bit_send_command(LCD, LCD_4BIT_MODE_2LINE);
		return_value = LCD_4bit_send_command(LCD, LCD_DDRAM_START);

	}

	return return_value;
}

Std_ReturnType LCD_4bit_send_command(const LCD_4bit_t *LCD, u8 command) {
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		return_value = DIO_write_pin_logic(&(LCD->LCD_rs), DIO_LOW);
		return_value = LCD_send_4bits(LCD, (command >> 4));
		return_value = LCD_send_4bit_enable(LCD);
		return_value = LCD_send_4bits(LCD, command);
		return_value = LCD_send_4bit_enable(LCD);

	}

	return return_value;
}
/*************************************************************************************************************/
Std_ReturnType LCD_4bit_send_char_data(const LCD_4bit_t *LCD, u8 data) {

	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		return_value = DIO_write_pin_logic(&(LCD->LCD_rs), DIO_HIGH);
		return_value = LCD_send_4bits(LCD, (data >> 4));
		return_value = LCD_send_4bit_enable(LCD);
		return_value = LCD_send_4bits(LCD, data);
		return_value = LCD_send_4bit_enable(LCD);

	}

	return return_value;
}
/******************************************************************************************************************/
Std_ReturnType LCD_4bit_send_char_data_pos(const LCD_4bit_t *LCD, u8 row,
		u8 column, u8 data) {
	Std_ReturnType return_value = E_NOK;
	if ((NULL == LCD) || (row > LCD_ROWS_MAX_NUM)
			|| (column > LCD_COLUMNS_MAX_NUM)) {
		return_value = E_NOK;
	} else {
		return_value = LCD_4bit_set_cursor(LCD, row, column);
		return_value = LCD_4bit_send_char_data(LCD, data);
	}
	return return_value;
}

Std_ReturnType LCD_4bit_send_string(const LCD_4bit_t *LCD, u8 *str) {
	Std_ReturnType return_value = E_NOK;
	if ((NULL == LCD) || (NULL == str)) {
		return_value = E_NOK;
	} else {
		while (*str != '\0') {
			return_value = LCD_4bit_send_char_data(LCD, *str++);
		}
	}
	return return_value;

}

Std_ReturnType LCD_4bit_send_string_pos(const LCD_4bit_t *LCD, u8 row,
		u8 column, u8 *str) {
	Std_ReturnType return_value = E_NOK;
	if ((NULL == LCD) || (NULL == str) || (row > LCD_ROWS_MAX_NUM)
			|| (column > LCD_COLUMNS_MAX_NUM)) {
		return_value = E_NOK;
	} else {
		LCD_4bit_set_cursor(LCD, row, column);
		while (*str != '\0') {
			return_value = LCD_4bit_send_char_data(LCD, *str++);

		}

	}

	return return_value;

}

Std_ReturnType LCD_4bit_send_number(const LCD_4bit_t *LCD, u32 number) {

	u8 str[11];
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		convert_int_to_string(number, str);
		LCD_4bit_send_string(LCD, str);
	}
	return return_value;
}
/*********************************************************************************************************************/
Std_ReturnType LCD_4bit_send_number_pos(const LCD_4bit_t *LCD, u8 row,
		u8 column, u32 number) {
	u8 str[11];
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		LCD_4bit_set_cursor(LCD, row, column);
		convert_int_to_string(number, str);
		LCD_4bit_send_string(LCD, str);
	}
	return return_value;
}
/*******************************************************************************************************************/
Std_ReturnType LCD_4bit_send_custom_char(const LCD_4bit_t *LCD, u8 row,u8 column, const u8 cus_char[], u8 mem_pos) {
	u8 l_counter = 0;
		Std_ReturnType return_value = E_NOK;
		if ((NULL == LCD)|| (row > LCD_ROWS_MAX_NUM)|| (column > LCD_COLUMNS_MAX_NUM)||(NULL ==cus_char )|| (mem_pos >7)) {
			return_value = E_NOK;
		} else {
			return_value = LCD_4bit_send_command(LCD,(LCD_CGRAM_START+(mem_pos*8)));
			for (l_counter=0;l_counter<8;l_counter++){
			return_value = LCD_4bit_send_char_data(LCD,cus_char[l_counter]);
			}
			return_value = LCD_4bit_send_char_data_pos(LCD,row,column, mem_pos);

		}

		return return_value;

	}



/************************************************************************************************************************************************************/
/*************************************************************************************************************************************************************/
//#elif LCD_BIT_MODE == LCD_8BIT_MODE
Std_ReturnType LCD_8bit_init(const LCD_8bit_t *LCD) {
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		return_value = DIO_init();
		_delay_ms(20);
		return_value = LCD_8bit_send_command(LCD, LCD_8BIT_MODE_2LINE);
		_delay_ms(5);
		return_value = LCD_8bit_send_command(LCD, LCD_8BIT_MODE_2LINE);
		_delay_us(150);
		return_value = LCD_8bit_send_command(LCD, LCD_8BIT_MODE_2LINE);
		/*************optional************************/

		return_value = LCD_8bit_send_command(LCD, LCD_CLEAR);
		return_value = LCD_8bit_send_command(LCD, LCD_RETURN_HOME);
		return_value = LCD_8bit_send_command(LCD, LCD_ENTRY_MODE);
		return_value = LCD_8bit_send_command(LCD, LCD_CURSOR_OFF_DISPLAY_ON);
		return_value = LCD_8bit_send_command(LCD, LCD_8BIT_MODE_2LINE);
		return_value = LCD_8bit_send_command(LCD, LCD_DDRAM_START);

	}

	return return_value;
}
/****************************************************************************************************************************************/
Std_ReturnType LCD_8bit_send_char_data(const LCD_8bit_t *LCD, u8 data) {
	u8 l_pin_counter = ZERO_INIT;
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		return_value = DIO_write_pin_logic(&(LCD->LCD_rs), DIO_HIGH);
		for (l_pin_counter = 0; l_pin_counter < 8; l_pin_counter++) {
			return_value = DIO_write_pin_logic(&(LCD->LCD_data[l_pin_counter]),
					(data >> l_pin_counter) & 0x01);
		}
		LCD_send_8bit_enable(LCD);
	}

	return return_value;

}
/**********************************************************************************************************************************/
Std_ReturnType LCD_8bit_send_command(const LCD_8bit_t *LCD, u8 command) {
	Std_ReturnType return_value = E_NOK;
	u8 l_pin_counter = ZERO_INIT;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		return_value = DIO_write_pin_logic(&(LCD->LCD_rs), DIO_LOW);
		for (l_pin_counter = 0; l_pin_counter < 8; l_pin_counter++) {
			return_value = DIO_write_pin_logic(&(LCD->LCD_data[l_pin_counter]),
					(command >> l_pin_counter) & 0x01);
		}
		LCD_send_8bit_enable(LCD);
	}

	return return_value;
}
/**********************************************************************************************************************************/
Std_ReturnType LCD_8bit_send_char_data_pos(const LCD_8bit_t *LCD, u8 row,
		u8 column, u8 data) {
	Std_ReturnType return_value = E_NOK;
	if ((NULL == LCD) || (row > LCD_ROWS_MAX_NUM)
			|| (column > LCD_COLUMNS_MAX_NUM)) {
		return_value = E_NOK;
	} else {
		return_value = LCD_8bit_set_cursor(LCD, row, column);
		return_value = LCD_8bit_send_char_data(LCD, data);
	}
	return return_value;
}
/*************************************************************************************************************************************/
Std_ReturnType LCD_8bit_send_string(const LCD_8bit_t *LCD, u8 *str) {
	Std_ReturnType return_value = E_NOK;
	if ((NULL == LCD) || (NULL == str)) {
		return_value = E_NOK;
	} else {
		while (*str != '\0') {
			return_value = LCD_8bit_send_char_data(LCD, *str++);

		}

	}

	return return_value;
}
/***********************************************************************************************************************************/
Std_ReturnType LCD_8bit_send_string_pos(const LCD_8bit_t *LCD, u8 row,
		u8 column, u8 *str) {
	Std_ReturnType return_value = E_NOK;
	if ((NULL == LCD) || (NULL == str) || (row > LCD_ROWS_MAX_NUM)
			|| (column > LCD_COLUMNS_MAX_NUM)) {
		return_value = E_NOK;
	} else {
		return_value = LCD_8bit_set_cursor(LCD, row, column);
		return_value = LCD_8bit_send_string(LCD, str);
	}

	return return_value;
}
/************************************************************************************************************************************/
Std_ReturnType LCD_8bit_send_number(const LCD_8bit_t *LCD, u32 number) {

	u8 str[11];
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		convert_int_to_string(number, str);
		LCD_8bit_send_string(LCD, str);
	}
	return return_value;
}
/***************************************************************************************************************************/
Std_ReturnType LCD_8bit_send_number_pos(const LCD_8bit_t *LCD, u8 row,
		u8 column, u32 number) {

	u8 str[11];
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		LCD_8bit_set_cursor(LCD, row, column);
		convert_int_to_string(number, str);
		LCD_8bit_send_string(LCD, str);
	}
	return return_value;
}
/***************************************************************************************************************************************/
Std_ReturnType LCD_8bit_send_custom_char(const LCD_8bit_t *LCD, u8 row,

		u8 column, const u8 cus_char[], u8 mem_pos) {
	u8 l_counter = 0;
	Std_ReturnType return_value = E_NOK;
	if ((NULL == LCD)|| (row > LCD_ROWS_MAX_NUM)|| (column > LCD_COLUMNS_MAX_NUM)||(NULL ==cus_char )|| (mem_pos >7)) {
		return_value = E_NOK;
	} else {
		return_value = LCD_8bit_send_command(LCD,(LCD_CGRAM_START+(mem_pos*8)));
		for (l_counter=0;l_counter<8;l_counter++){
		return_value = LCD_8bit_send_char_data(LCD,cus_char[l_counter]);
		}
		return_value = LCD_8bit_send_char_data_pos(LCD,row,column, mem_pos);

	}

	return return_value;

}
//#endif

/**********************************************helper functions********************************************************/
static Std_ReturnType convert_int_to_string(u32 value, u8 *str) {
	Std_ReturnType return_value = E_OK;
	if (NULL == str) {
		return_value = E_NOK;
	} else {
		memset(str, '\0', 11);
		sprintf(str, "%lu", value);
	}
	return return_value;
}

/************************************************ helper function *********************************************************/
static Std_ReturnType LCD_4bit_set_cursor(const LCD_4bit_t *LCD, u8 row,
		u8 column) {
	Std_ReturnType return_value = E_OK;
	if ((NULL == LCD) || (row > LCD_ROWS_MAX_NUM)
			|| (column > LCD_COLUMNS_MAX_NUM)) {
		return_value = E_NOK;
	} else {
		column--;
		switch (row) {
		case LCD_ROW1:
			return_value = LCD_4bit_send_command(LCD,
					(LCD_DDRAM_START + column));
			break;
		case LCD_ROW2:
			return_value = LCD_4bit_send_command(LCD, (0xc0 + column));
			break;
		case LCD_ROW3:
			return_value = LCD_4bit_send_command(LCD, (0x94 + column));
			break;
		case LCD_ROW4:
			return_value = LCD_4bit_send_command(LCD, (0xd4 + column));
			break;
		}
	}
	return return_value;
}
/**************************************************************************************************************************/
static Std_ReturnType LCD_send_4bits(const LCD_4bit_t *LCD, u8 data_command) {
	Std_ReturnType return_value = E_NOK;
	if (NULL == LCD) {
		return_value = E_NOK;
	} else {
		return_value = DIO_write_pin_logic(&(LCD->LCD_data[LCD_BIT0]),
				(data_command >> LCD_BIT0) & 0x01);
		return_value = DIO_write_pin_logic(&(LCD->LCD_data[LCD_BIT1]),
				(data_command >> LCD_BIT1) & 0x01);
		return_value = DIO_write_pin_logic(&(LCD->LCD_data[LCD_BIT2]),
				(data_command >> LCD_BIT2) & 0x01);
		return_value = DIO_write_pin_logic(&(LCD->LCD_data[LCD_BIT3]),
				(data_command >> LCD_BIT3) & 0x01);
	}
	return return_value;
}
/***************************************************************************************************************************/
static Std_ReturnType LCD_send_4bit_enable(const LCD_4bit_t *LCD) {
	Std_ReturnType return_value = E_NOK;
	return_value = DIO_write_pin_logic(&(LCD->LCD_en), DIO_HIGH);
	_delay_us(5);
	return_value = DIO_write_pin_logic((&LCD->LCD_en), DIO_LOW);
	return return_value;
}
/*****************************************************************************************************************************/
static Std_ReturnType LCD_send_8bit_enable(const LCD_8bit_t *LCD) {
	Std_ReturnType return_value = E_NOK;
	return_value = DIO_write_pin_logic(&(LCD->LCD_en), DIO_HIGH);
	_delay_us(5);
	return_value = DIO_write_pin_logic((&LCD->LCD_en), DIO_LOW);
	return return_value;
}
/*****************************************************************************************************************************/
static Std_ReturnType LCD_8bit_set_cursor(const LCD_8bit_t *LCD, u8 row,
		u8 column) {
	Std_ReturnType return_value = E_OK;
	if ((NULL == LCD) || (row > LCD_ROWS_MAX_NUM)
			|| (column > LCD_COLUMNS_MAX_NUM)) {
		return_value = E_NOK;
	} else {
		column--;
		switch (row) {
		case LCD_ROW1:
			return_value = LCD_8bit_send_command(LCD,
					(LCD_DDRAM_START + column));
			break;
		case LCD_ROW2:
			return_value = LCD_8bit_send_command(LCD, (0xc0 + column));
			break;
		case LCD_ROW3:
			return_value = LCD_8bit_send_command(LCD, (0x94 + column));
			break;
		case LCD_ROW4:
			return_value = LCD_8bit_send_command(LCD, (0xd4 + column));
			break;
		}
	}
	return return_value;
}
/*****************************************************************************************************************************/
/*****************************************************************************************************************************/

