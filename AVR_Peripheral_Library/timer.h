//<one line to give the timer.h name and a brief idea of what it does.>
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

#ifndef TIMER_H_
#define TIMER_H_

typedef enum {
	timer_mode_Normal, timer_mode_CTC, timer_mode_PWM, timer_mode_STOP
} _timer_mode;

#ifdef __AVR_ATmega644P__
/*Private Function*/
void timer0_init(_timer_mode timer_mode);
void timer1_init(_timer_mode timer_mode);
void timer2_init(_timer_mode timer_mode);
#endif /* __AVR_ATmega644P__ */

#ifdef __AVR_ATmega1284P__
/*Private Function*/
void timer0_init(_timer_mode timer_mode);
void timer1_init(_timer_mode timer_mode);
void timer2_init(_timer_mode timer_mode);
#endif /* __AVR_ATmega1284P__ */

#ifdef __AVR_ATmega168P__
/*Private Function*/
void timer0_init(_timer_mode timer_mode);
void timer1_init(_timer_mode timer_mode);
void timer2_init(_timer_mode timer_mode);
#endif /* __AVR_ATmega168P__ */

#ifdef __AVR_ATmega328P__
/*Private Function*/
void timer0_init(_timer_mode timer_mode);
void timer1_init(_timer_mode timer_mode);
void timer2_init(_timer_mode timer_mode);
#endif /* __AVR_ATmega328P__ */

#endif /* TIMER_H_ */
