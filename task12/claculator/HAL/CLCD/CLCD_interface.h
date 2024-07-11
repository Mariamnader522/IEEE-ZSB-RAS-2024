/*
 * CLCD_interface.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Utente
 */

#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_

#include "CLCD_config.h"
#include "../../MCAL/Dio/Dio.h"


#define FOUR_BITS  0x28
#define EIGHT_BITS  0x38

#define lcd_DisplayOn_CursorOff             0x0C
#define lcd_DisplayOn_CursorOn              0x0E
#define lcd_clear                           0x01
#define lcd_EntryMode                       0x06 //shift from left to right
#define lcd_Home                            0x02
#define lcd_SetCursor                       0x80          // set cursor position
#define lcd_FunctionReset                   0x30          // reset the LCD

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80


#define ROW1   1
#define ROW2   2

void LCD_Init(void);
void LCD_Send_Command(u8 command);
void LCD_Send_Char(u8 _char);
void LCD_Send_Char_Pos(u8 _char,u8 row,u8 column);
void LCD_Send_String(u8 *string);
void LCD_Send_String_Pos(u8 *string,u8 row,u8 column);
void LCD_Send_Number(u32 num);
void LCD_Send_Number_Pos(u32 num,u8 row,u8 column);

#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
