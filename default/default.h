/*
 * default.h
 *
 *  Created on: 9 lis 2020
 *      Author: Dom
 */

#ifndef DEFAULT_DEFAULT_H_
#define DEFAULT_DEFAULT_H_
#include <avr/io.h>
#include <util/delay.h>

//************-Definicje-***********************//

#define xLedPin (1<<PB5)
#define LEDon PORTB |= xLedPin
#define LEDoff PORTB &=~ xLedPin
#define LEDtogg PORTB ^= xLedPin


//************- Deklaracje-********************//


void _initPWM_T0(void);

uint8_t DriveOperation(uint8_t velocity);

void DemoDriverMotor(void);




#endif /* DEFAULT_DEFAULT_H_ */
