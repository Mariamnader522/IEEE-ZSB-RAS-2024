/*
 * main.c
 *
 *  Created on: Jul 4, 2024
 *      Author: Utente
 */
#include "dio_driver.h"
#include "STD_TYPES.h"
#include <avr/io.h>

#define SET_BUTTON DIO_PORT_C, DIO_PIN7
#define RESET_BUTTON DIO_PORT_C, DIO_PIN6

int main(void) {
    DIO_Init(SET_BUTTON, 0);  //set buttons as inputs with pull-ups
    DIO_Init(RESET_BUTTON, 0);
    DIO_Write(DIO_PORT_C, DIO_PIN7, 1);
    DIO_Write(DIO_PORT_C, DIO_PIN6, 1);

    while (1) {
        if (DIO_Read(SET_BUTTON) == 1) {
            DIO_Write(DIO_PORT_C, DIO_PIN0, 1);
        }
        if (DIO_Read(RESET_BUTTON) == 1) {
            DIO_Write(DIO_PORT_C, DIO_PIN0, 0);
        }
    }

    return 0;
}
