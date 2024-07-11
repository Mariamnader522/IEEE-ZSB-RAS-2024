/*
 * KeyPad_config.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Utente
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_
#include "Dio_types.h"

#define PIN_COUNT 19

typedef struct{
	Dio_port_t port;
	Dio_pin_t pin;
	Dio_dir_t direction;
}Dio_pin_config;

#endif /* MCAL_DIO_DIO_CONFIG_H_ */
