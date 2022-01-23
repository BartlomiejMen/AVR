/*
 * main.c
 *
 *  Created on: 9 sty 2022
 *      Author: bmendyk
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define RESET &=~
#define SET |=

#define TIMER_PRESCALER 2

int main(void)
{

	TCCR2A |= (1<<WGM21); // CTC OCRA 328p
	TCCR2B |= ((1<< CS20)|(1<< CS21)|(1<< CS22));	//( 16*10^6 Hz / 1024 presc / 100 Hz) -1  = 155 uint8_t
	OCR2A = 155;
	OCR2B = 100;
	TIMSK2 |= (1<< OCIE2A);


	sei();

	void InitInputCapture(void)
	{


#if TIMER_PRESCALER == 1
		TCCR1B SET (1<<CS10); //1
#endif

#if TIMER_PRESCALER == 2
		TCCR1B SET (1<<CS11); //8
#endif

#if TIMER_PRESCALER == 3
		TCCR1B SET ((1<<CS10) | (1<<CS11)); //64
#endif

#if TIMER_PRESCALER == 4
		TCCR1B SET (1<<CS12); // 256
#endif

#if TIMER_PRESCALER == 5
		TCCR1B SET (1<<CS10 | 1<<CS12); //1024
#endif

		TCCR1B RESET ((1<<ICES1) | (1<<ICNC1));
		TIMSK1 SET (1<<ICIE1); //OCIE1
		//TCNT1

	}




	DDRD SET (1<<PD3);

	while(1)
	{

	}
}
ISR(TIMER2_COMPA_vect){

}
ISR(TIMER2_COMPB_vect){

}

ISR(TIMER1_CAPT_vect){

}


