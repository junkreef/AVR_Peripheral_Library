//<one line to give the i2c.c name and a brief idea of what it does.>
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

#include <avr/io.h>
#include "i2c.h"



void i2c_init(){
	TWBR=32;//16MHz‚Ì‚Æ‚«‚É200KHz‚É‚È‚é‚æ‚¤‚É
	TWSR=0;//•ªŽü’l1
}

uint8_t i2c_wait(){
	uint16_t __count=0;
	while(!(TWCR&(1<<TWINT))){
		__count++;
		if(__count>=I2C_TIMEOUT){
			return 255;
		}
	}
	return 0;
}

uint8_t i2c_start(){
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	return i2c_wait();
}

uint8_t i2c_send(uint8_t data){
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	return i2c_wait();
}

uint8_t i2c_stop(){
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<TWEN);
	return i2c_wait();
}

inline uint8_t i2c_restart(){
	return i2c_start();
}
