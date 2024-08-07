/*
 * KeyPad_config.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Utente
 */
#include "Dio_Config.h"


Dio_pin_config pin[PIN_COUNT]={
		{PORT_D,PIN_7,OUTPUT},
		//pins of lcd
		{PORT_A,PIN_4,OUTPUT},
		{PORT_A,PIN_5,OUTPUT},
		{PORT_A,PIN_6,OUTPUT},
		{PORT_A,PIN_7,OUTPUT},
		{PORT_B,PIN_0,OUTPUT},
		{PORT_B,PIN_1,OUTPUT},
		{PORT_B,PIN_2,OUTPUT},
		//pins of keypad
		{PORT_C,PIN_0,OUTPUT},
		{PORT_C,PIN_1,OUTPUT},
		{PORT_C,PIN_2,OUTPUT},
		{PORT_C,PIN_3,OUTPUT},
		{PORT_C,PIN_4,INPUT},
		{PORT_C,PIN_5,INPUT},
		{PORT_C,PIN_6,INPUT},
		{PORT_C,PIN_7,INPUT},

};

