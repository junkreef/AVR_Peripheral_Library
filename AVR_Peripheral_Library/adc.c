//<one line to give the adc.c name and a brief idea of what it does.>
// Copyright (C) 2013 Junpei Kishi
//
//
//This program is free software; you can redistribute it and/or modify it under the terms of
// the GNU General Public License as published by the Free Software Foundation; either version 3 of the License,
// or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License along with this program.
// If not, see <http://www.gnu.org/licenses/>.


#include "adc.h"
//*** Private Function ***//
void adc_init(){
	ADCSRB=0;
	ADCSRA=(1<<ADEN)|(1<<ADIF)|ADC_Prescaler;
	_delay_ms(10);
	ADCSRA=ADC_START;

	//First Convert *25 ADC Clock*
	adc_wait();
}

uint16_t adc_convert(uint8_t type){
	ADMUX=ADMUX_DEF|type;
#ifdef ADC_CONVERT_TYPE_SLEEP
	set_sleep_mode(SLEEP_MODE_ADC);
	sei();
	sleep_mode();
#else
	ADCSRA=ADC_START;
	adc_wait();
#endif
	return ADC;
}

inline void adc_wait(void){
	while(!(ADCSRA&(1<<ADSC)));
}

ISR(ADC_vect){
	//Dummy
}
