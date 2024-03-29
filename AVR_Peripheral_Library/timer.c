//<one line to give the timer.c name and a brief idea of what it does.>
// Copyright (C) 2012 Junpei Kishi
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

#include <avr/io.h>
#include "timer.h"

inline void timer0_set(uint8_t valueA,uint8_t valueB){
	OCR0A=valueA;
	OCR0B=valueB;
}

inline void timer1_set(uint16_t valueA,uint16_t valueB){
	OCR1A=valueA;
	OCR1B=valueB;
}

inline void timer2_set(uint8_t valueA,uint8_t valueB){
	OCR2A=valueA;
	OCR2B=valueB;
}

#ifdef __AVR_ATmega644P__
void timer0_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
		TCCR0A = 0x00;
		TCCR0B = 0x05;
		break;
		case timer_mode_CTC:
		TCCR0A = 0x02;
		TCCR0B = 0x05;
		break;
		case timer_mode_PWM:
		TCCR0A = 0xa3;
		TCCR0B = 0x05;
		break;
		case timer_mode_STOP:
		TCCR0A = 0x00;
		TCCR0B = 0x00;
		break;
	}
}

void timer1_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
		TCCR1A = 0x00;
		TCCR1B = 0x05;
		break;
		case timer_mode_CTC:
		TCCR1A = 0x00;
		TCCR1B = 0x0D;
		break;
		case timer_mode_PWM:
		TCCR1A = 0x01;
		TCCR1B = 0x0D;
		break;
		case timer_mode_STOP:
		TCCR1A = 0;
		TCCR1B = 0;
		break;
	}
	TCCR1C = 0;
}

void timer2_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
		TCCR2A = 0x00;
		TCCR2B = 0x05;
		break;
		case timer_mode_CTC:
		TCCR2A = 0x02;
		TCCR2B = 0x05;
		break;
		case timer_mode_PWM:
		TCCR2A = 0xa3;
		TCCR2B = 0x05;
		break;
		case timer_mode_STOP:
		TCCR2A = 0x00;
		TCCR2B = 0x00;
		break;
	}
}
#endif /* __AVR_ATmega644P__ */

#ifdef __AVR_ATmega1284P__
void timer0_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
			TCCR0A = 0x00;
			TCCR0B = 0x05;
			break;
		case timer_mode_CTC:
			TCCR0A = 0x02;
			TCCR0B = 0x05;
			break;
		case timer_mode_PWM:
			TCCR0A = 0xa3;
			TCCR0B = 0x05;
			break;
		case timer_mode_STOP:
			TCCR0A = 0x00;
			TCCR0B = 0x00;
			break;
	}
}

void timer1_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
			TCCR1A = 0x00;
			TCCR1B = 0x05;
			break;
		case timer_mode_CTC:
			TCCR1A = 0x00;
			TCCR1B = 0x0D;
			break;
		case timer_mode_PWM:
			TCCR1A = 0x01;
			TCCR1B = 0x0D;
			break;
		case timer_mode_STOP:
			TCCR1A = 0;
			TCCR1B = 0;
			break;
	}
	TCCR1C = 0;
}

void timer2_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
			TCCR2A = 0x00;
			TCCR2B = 0x05;
			break;
		case timer_mode_CTC:
			TCCR2A = 0x02;
			TCCR2B = 0x05;
			break;
		case timer_mode_PWM:
			TCCR2A = 0xa3;
			TCCR2B = 0x05;
			break;
		case timer_mode_STOP:
			TCCR2A = 0x00;
			TCCR2B = 0x00;
			break;
	}
}
#endif /* __AVR_ATmega1284P__ */

#ifdef __AVR_ATmega168P__
void timer0_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
		TCCR0A = 0x00;
		TCCR0B = 0x05;
		break;
		case timer_mode_CTC:
		TCCR0A = 0x02;
		TCCR0B = 0x05;
		break;
		case timer_mode_PWM:
		TCCR0A = 0xa3;
		TCCR0B = 0x05;
		break;
		case timer_mode_STOP:
		TCCR0A = 0x00;
		TCCR0B = 0x00;
		break;
	}
}

void timer1_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
			TCCR1A = 0x00;
			TCCR1B = 0x05;
			break;
		case timer_mode_CTC:
			TCCR1A = 0x00;
			TCCR1B = 0x0D;
			break;
		case timer_mode_PWM:
			TCCR1A = 0x01;
			TCCR1B = 0x0D;
			break;
		case timer_mode_STOP:
			TCCR1A = 0;
			TCCR1B = 0;
			break;
	}
	TCCR1C = 0;
}

void timer2_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
			TCCR2A = 0x00;
			TCCR2B = 0x05;
			break;
		case timer_mode_CTC:
			TCCR2A = 0x02;
			TCCR2B = 0x05;
			break;
		case timer_mode_PWM:
			TCCR2A = 0xa3;
			TCCR2B = 0x05;
			break;
		case timer_mode_STOP:
			TCCR2A = 0x00;
			TCCR2B = 0x00;
			break;
	}
}

#endif /* __AVR_ATmega168P__ */

#ifdef __AVR_ATmega328P__
void timer0_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
		TCCR0A = 0x00;
		TCCR0B = 0x05;
		break;
		case timer_mode_CTC:
		TCCR0A = 0x02;
		TCCR0B = 0x05;
		break;
		case timer_mode_PWM:
		TCCR0A = 0xa3;
		TCCR0B = 0x05;
		break;
		case timer_mode_STOP:
		TCCR0A = 0x00;
		TCCR0B = 0x00;
		break;
	}
}

void timer1_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
			TCCR1A = 0x00;
			TCCR1B = 0x05;
			break;
		case timer_mode_CTC:
			TCCR1A = 0x00;
			TCCR1B = 0x0D;
			break;
		case timer_mode_PWM:
			TCCR1A = 0x01;
			TCCR1B = 0x0D;
			break;
		case timer_mode_STOP:
			TCCR1A = 0;
			TCCR1B = 0;
			break;
	}
	TCCR1C = 0;
}

void timer2_init(_timer_mode timer_mode){
	switch(timer_mode){
		case timer_mode_Normal:
			TCCR2A = 0x00;
			TCCR2B = 0x05;
			break;
		case timer_mode_CTC:
			TCCR2A = 0x02;
			TCCR2B = 0x05;
			break;
		case timer_mode_PWM:
			TCCR2A = 0xa3;
			TCCR2B = 0x05;
			break;
		case timer_mode_STOP:
			TCCR2A = 0x00;
			TCCR2B = 0x00;
			break;
	}
}

#endif /* __AVR_ATmega328P__ */
