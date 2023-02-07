/*
 * default.c
 *
 *  Created on: 9 lis 2020
 *      Author: Dom
 */

#include "default.h"




void _initPWM_T0(void)
{
	DDRD |=(1<<PD5) | (1<<PD6);

	TCCR0A |= (1<<WGM00) | (1<<WGM01);	//FastPWM
	TCCR0B |= (1<<CS00) | (1<<CS02);	//dzielnie 16Mhz przez 1024
	TCCR0A |= (1<<COM0A1)  | (1<<COM0B1); //SET | (1<<COM0A0)  | (1<<COM0B0)
	//TIMSK0 |= (1<<OCIE0A) | (1<<OCIE0B);
}

uint8_t DriveOperation(uint8_t velocity)
{

	//OCR0A = velocity;
	//OCR0B = velocity;
	return velocity;
}

void DemoDriverMotor(void)
{

	for(uint8_t i = 20; i<60; i++)
	{
		OCR0A = i;
		OCR0B = i;
		_delay_ms(100);
	}

	LEDon;

	for(uint8_t i = 60; i>20; i--)
			{
				OCR0A = i;
				OCR0B = i;
				_delay_ms(100);
			}

	LEDoff;
	_delay_ms(500);

}
