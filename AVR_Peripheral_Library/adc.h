//<one line to give the adc.h name and a brief idea of what it does.>
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

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

/* Reference = AREF_Pin */
//	#define REF_SELECT 0
/* Reference = AVCC_Pin(Recommanded on X1) */
	#define REF_SELECT 1
/* Reference = 1.1V */
//	#define REF_SELECT 2
/* Reference = 2.56V(Recommanded on X10 or X200) */
//	#define REF_SELECT 3

/* ADC Left Adjust Result = DISABLE(Recommanded) */
#define ADMUX_DEF (REF_SELECT<<REFS0)
/* ADC Left Adjust Result = Enable */
//#define ADMUX_DEF (REF_SELECT<<REFS0)|0x20

//*** Set ADC Prescaler ***//
/* F_CPU <= 1MHz*/
//#define ADC_Prescaler 3
/* F_CPU <= 3MHz*/
//#define ADC_Prescaler 4
/* F_CPU <= 6MHz */
//#define ADC_Prescaler 5
/* F_CPU <= 12MHz */
//#define ADC_Prescaler 6
/* F_CPU <= 20MHz */
#define ADC_Prescaler 7

#define ADC_CONVERT_TYPE_SLEEP

//*** Private Macro ***//
#define ADC_START ADCSRA|(1<<ADSC)|(1<<ADIF)

//*** Private Function Prototype ***//
void adc_init();
uint16_t adc_convert(uint8_t);
inline void adc_wait(void);


#endif /* ADC_H_ */
