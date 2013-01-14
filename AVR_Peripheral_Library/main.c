//<one line to give the main.c name and a brief idea of what it does.>
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
#include <util/delay.h>
#include "uart.h"
#include "timer.h"
#include "adc.h"

int main(void){
	uart_init(9600);
	uart_putstr("//***********************************//\n\r"
				"//     AVR Peripheral Library        //\n\r"
				"//***********************************//\n\r");
	adc_init();
	while(1){
		uart_putdec(adc_convert(ADC0));
		uart_putstr("\n\r");
	}
	return 0;
}
