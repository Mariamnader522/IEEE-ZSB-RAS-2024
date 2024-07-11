/*
 * KeyPad_program.c

 *
 *  Created on: Jul 11, 2024
 *      Author: Utente
 */
#include "KeyPad_interface.h"
#include "KeyPad_config.h"
#include <util/delay.h>

static const u8 Calcolator[keypad_rows][keypad_cols] = {
                                                                        {7, 8, 9, '/'},
                                                                        {4, 5, 6, '*'},
                                                                        {1, 2, 3, '-'},
                                                                        {'&',  0, '=', '+'}
                                                       };

u8 GetPressed()
{
	u8 Rows =0;
	u8 Cols =0;
	u8 PortCounter =0;
	Dio_state_t state=LOW;
	u8 PressedButton=0;
	for(Rows =0;Rows<keypad_rows;Rows++)
	{
		for(PortCounter=keypad_R1;PortCounter<keypad_R1+keypad_rows;PortCounter++)
		{
			Dio_Write(PortCounter,LOW);  //to set as output
		}
		Dio_Write(Rows + keypad_R1, HIGH);
		_delay_ms(10);
		for(Cols=0;Cols<keypad_C1+keypad_cols;Cols++)
		{
			state = Dio_Read(Cols);
			if (state == HIGH)
			{
				PressedButton = Calcolator[Rows][Cols-keypad_C1];
			}
		}
	}
	return PressedButton;
}
