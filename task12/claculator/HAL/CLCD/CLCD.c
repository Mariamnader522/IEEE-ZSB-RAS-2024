/*
 * CLCD.c
 *
 *  Created on: Jul 11, 2024
 *      Author: Utente
 */

#include "CLCD_interface.h"

static void Trigger_Enable();
static void Set_Cursor_Pos(u8 row,u8 column);
void LCD_Init(void)
{
	_delay_ms(20);
	LCD_Send_Command(0x33);
	LCD_Send_Command(0x32);
	LCD_Send_Command(FOUR_BITS);
	LCD_Send_Command(lcd_DisplayOn_CursorOn);
	LCD_Send_Command(lcd_EntryMode);
	LCD_Send_Command(_LCD_DDRAM_START);
	LCD_Send_Command(lcd_clear);
}
void LCD_Send_Command(u8 command)
{
	Dio_Write(RS, LOW);
	Dio_Write(RW, LOW);

	(READ_BIT(command,7)) ? Dio_Write(D7,HIGH) : Dio_Write(D7,LOW);
	(READ_BIT(command,6)) ? Dio_Write(D6,HIGH) : Dio_Write(D6,LOW);
	(READ_BIT(command,5)) ? Dio_Write(D5,HIGH) : Dio_Write(D5,LOW);
	(READ_BIT(command,4)) ? Dio_Write(D4,HIGH) : Dio_Write(D4,LOW);
	//Trigger Enable
	Trigger_Enable();
	(READ_BIT(command,3)) ? Dio_Write(D7,HIGH) : Dio_Write(D7,LOW);
	(READ_BIT(command,2)) ? Dio_Write(D6,HIGH) : Dio_Write(D6,LOW);
	(READ_BIT(command,1)) ? Dio_Write(D5,HIGH) : Dio_Write(D5,LOW);
	(READ_BIT(command,0)) ? Dio_Write(D4,HIGH) : Dio_Write(D4,LOW);
	//Trigger Enable
	Trigger_Enable();
}
void LCD_Send_Char(u8 _char)
{
	Dio_Write(RS, HIGH);
	Dio_Write(RW, LOW);

	(READ_BIT(_char,7)) ? Dio_Write(D7,HIGH) : Dio_Write(D7,LOW);
	(READ_BIT(_char,6)) ? Dio_Write(D6,HIGH) : Dio_Write(D6,LOW);
	(READ_BIT(_char,5)) ? Dio_Write(D5,HIGH) : Dio_Write(D5,LOW);
	(READ_BIT(_char,4)) ? Dio_Write(D4,HIGH) : Dio_Write(D4,LOW);
	//Trigger Enable
	Trigger_Enable();
	(READ_BIT(_char,3)) ? Dio_Write(D7,HIGH) : Dio_Write(D7,LOW);
	(READ_BIT(_char,2)) ? Dio_Write(D6,HIGH) : Dio_Write(D6,LOW);
	(READ_BIT(_char,1)) ? Dio_Write(D5,HIGH) : Dio_Write(D5,LOW);
	(READ_BIT(_char,0)) ? Dio_Write(D4,HIGH) : Dio_Write(D4,LOW);
	//Trigger Enable
	Trigger_Enable();
}
void LCD_Send_Char_Pos(u8 _char,u8 row,u8 column)
{
	Set_Cursor_Pos(row,column);
	LCD_Send_Char(_char);
}
void LCD_Send_String(u8 *string)
{
	while(*string !='\0')
	{
		LCD_Send_Char(*string++);
	}
}
void LCD_Send_String_Pos(u8 *string,u8 row,u8 column)
{
	Set_Cursor_Pos(row,column);
	LCD_Send_String(string);
}

void LCD_Send_Number(u32 num)
{
	 u8 arr[10],i=0,j=0;
		   if(num == 0)
		   {
			   LCD_Send_Char('0');
		   }
		   else
		   {
			   while(num)
			   {
					arr[i]=num%10+'0';
					num/=10;
					i++;
			   }
			   for(j=i;j>0;j--)
			   {
				   LCD_Send_Char(arr[j-1]);
			   }
		   }
}
void LCD_Send_Number_Pos(u32 num,u8 row,u8 column)
{
	Set_Cursor_Pos(row,column);
	LCD_Send_Number(num);
}

static void Trigger_Enable()
{
	Dio_Write(EN,HIGH);
	_delay_us(10);
	Dio_Write(EN,LOW);
	_delay_us(2000);
}
static void Set_Cursor_Pos(u8 row,u8 column)
{
	column--;
	switch(row){
	            case ROW1: LCD_Send_Command((0x80 + column)); break;
	            case ROW2: LCD_Send_Command((0xc0 + column)); break;
	            default:;
	        }
}

