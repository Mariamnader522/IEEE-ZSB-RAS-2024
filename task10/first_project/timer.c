/*
 * timer.c
 *
 */ 
 
#include "std_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
void timer_CTC_init_interrupt(void)
{
	SET_BIT(TCCR0,WGM01);
	OCR0=80;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	sei();
	SET_BIT(TIMSK,OCIE0);
}


void timer_wave_nonPWM(void)
{
	SET_BIT(DDRB,3);
	SET_BIT(TCCR0,WGM01);
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
}

void timer_wave_fastPWM(void)
{

	SET_BIT(DDRB,3);
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void timer_wave_phasecorrectPWM(void)
{
	SET_BIT(DDRB,3);
	SET_BIT(TCCR0,WGM00);
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}

