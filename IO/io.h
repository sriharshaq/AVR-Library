/***************************************************************************************************************
    This file is part of Library for AVR.

    Library for AVR is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Library for AVR is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Library for AVR. If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/


/***
**   File       : io.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is include file for io library for AVR family MCU's
***/
#ifndef __io_h__
#define __io_h__

#include <avr/io.h>

#define PORT0DIR DDRA
#define PORT1DIR DDRB
#define PORT2DIR DDRC
#define PORT3DIR DDRD

#define PORT0OUT PORTA
#define PORT1OUT PORTB
#define PORT2OUT PORTC
#define PORT3OUT PORTD

#define PORT0IN  PINA
#define PORT1IN  PINB
#define PORT2IN  PINC
#define PORT3IN  PIND

#define HIGH     1
#define LOW      0
#define OUTPUT   1
#define INPUT    0

#define IO_MAX 7

// Prototypes

extern void          digitalWrite(unsigned char,unsigned char);         // Pin Number, Pin State (HIGH,LOW)
extern unsigned char digitalRead(unsigned char);                        // Pin Number
extern void          pinMode(unsigned char,unsigned char);              // Pin Number, Mode-> OUTPUT,INPUT

#endif
