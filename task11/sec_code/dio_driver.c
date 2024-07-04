/*
 * dio_driver.c
 *
 *  Created on: Jul 4, 2024
 *      Author: Utente
 */

#include "dio_driver.h"
#include "STD_TYPES.h"
#include <avr/io.h>

void DIO_Init(u8 port, u8 pin, u8 direction) {
    switch (port) {
        case DIO_PORT_A:
            if (direction == 0) {
                DDRA &= ~(1 << pin);  // Set pin as input
            } else {
                DDRA |= (1 << pin);   // Set pin as output
            }
            break;
        case DIO_PORT_B:
            if (direction == 0) {
                DDRB &= ~(1 << pin);  // Set pin as input
            } else {
                DDRB |= (1 << pin);   // Set pin as output
            }
            break;
        case DIO_PORT_C:
            if (direction == 0) {
                 DDRC &= ~(1 << pin);  // Set pin as input
            } else {
                 DDRC |= (1 << pin);   // Set pin as output
            }
            break;
        case DIO_PORT_D:
             if (direction == 0) {
                 DDRD &= ~(1 << pin);  // Set pin as input
            } else {
                 DDRD |= (1 << pin);   // Set pin as output
            }
            break;
        default:
        	break;

    }
}

void DIO_Write(u8 port, u8 pin, u8 value) {
    switch (port) {
        case DIO_PORT_A:
            if (value == 0) {
                PORTA &= ~(1 << pin);  // Clear bit
            } else {
                PORTA |= (1 << pin);   // Set bit
            }
            break;
        case DIO_PORT_B:
            if (value == 0) {
                PORTB &= ~(1 << pin);  // Clear bit
            } else {
                PORTB |= (1 << pin);   // Set bit
            }
            break;
        case DIO_PORT_C:
            if (value == 0) {
                PORTC &= ~(1 << pin);  // Clear bit
            } else {
                PORTC |= (1 << pin);   // Set bit
            }
            break;
        case DIO_PORT_D:
            if (value == 0) {
                PORTD &= ~(1 << pin);  // Clear bit
            } else {
                PORTD |= (1 << pin);   // Set bit
            }
            break;
            default: break ;
    }
}

u8 DIO_Read(u8 port, u8 pin) {
    switch (port) {
        case DIO_PORT_A:
            return (PINA & (1 << pin)) >> pin;
        case DIO_PORT_B:
            return (PINB & (1 << pin)) >> pin;
        case DIO_PORT_C:
            return (PINC & (1 << pin)) >> pin;
        case DIO_PORT_D:
            return (PIND & (1 << pin)) >> pin;
        default:
            return 0;
    }
}
