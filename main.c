/*
 * main.c
 *
 *  Created on: 24 paü 2020r
 *      Author: Dom
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "default/default.h"


//************-Progarm-************************//

int
main(void) {
//************- inicjalizacja, konfiguracja -****//

	DDRB = (1<<PB5);
	sei(); //globalne zezwolenie na przerwania

	_initPWM_T0();

	while(1)	//pÍtal g≥Ûwna
	{

		DriveOperation(200);

		DemoDriverMotor();



	}

}


 ISR(PCINT0_vect)
	{


	}




