/*
 * main.c
 *
 *  Created on: Jul 4, 2024
 *      Author: Utente
 */

#include <avr/io.h>
#define setButton (PINC&0b10000000)
#define resetButton (PINC&0b01000000)
int main(void)
{
    DDRC=0b00111111; //define buttons as inputs
    PORTC=0b11000000; //set PORT=1 activate internal pull up
    while (1)
    {
        if (setButton==0) PORTC=0b11000001;
        if (resetButton==0)  PORTC=0b11000000;
        /* if setButton is pressed make PORTC
        for PC0=1 (high output) so coil will attract frather
        and current will pass through the lamp */
    }
}
