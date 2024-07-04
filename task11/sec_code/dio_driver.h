/*
 * dio_driver.h
 *
 *  Created on: Jul 4, 2024
 *      Author: Utente
 */
#ifndef DIO_DRIVER_H
#define DIO_DRIVER_H

#include "STD_TYPES.h"
#include <avr/io.h>


#define DIO_PORT_A 0
#define DIO_PORT_B 1
#define DIO_PORT_C 2
#define DIO_PORT_D 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

void DIO_Init(u8 port, u8 pin, u8 direction);
void DIO_Write(u8 port, u8 pin, u8 value);
u8 DIO_Read(u8 port, u8 pin);

#endif /* DIO_DRIVER_H_ */
