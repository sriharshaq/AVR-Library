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
    along with Library for AVR.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/

/***
**   File       : timer.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the include file for AVR hardware timer driver
***/

#ifndef __timer_h__
#define __timer_h__

#include <avr/io.h>
#include <avr/interrupt.h>

#define ENABLE_TIMER0_ISR
//#define ENABLE_TIMER1_ISR
//#define ENABLE_TIMER2_ISR

#define HW_TIMER0 0
#define HW_TIMER1 1
#define HW_TIMER2 2

#ifdef ENABLE_TIMER0_ISR
extern volatile unsigned int timerCount0;
#endif
#ifdef ENABLE_TIMER1_ISR
extern volatile unsigned int timerCount1;
#endif
#ifdef ENABLE_TIMER2_ISR
extern volatile unsigned int timerCount2;
#endif


#define TIMER_NO_CLOCK_SOURCE   TCCR0B &= ~(1 << CS02) | ~(1 << CS01) | ~(1 << CS00)                             // 000
#define TIMER_NO_PRESCALAR      TCCR0B |= (TCCR0B & ~(1 << CS02)) | (TCCR0B & ~(1 << CS01)) | (1 << CS00)        // 001
#define TIMER_8_PRESCALAR       TCCR0B |= (TCCR0B & ~(1 << CS02)) | (1 << CS01) | (TCCR0B & ~(1 << CS00)         // 010
#define TIMER_64_PRESCALAR      TCCR0B |= (TCCR0B & ~(1 << CS02)) | (1 << CS01) | (1 << CS00)                    // 011
#define TIMER_256_PRESCALAR     TCCR0B |= (1 << CS02) | (TCCR0B & ~(1 << CS01))| (TCCR0B & ~(1 << CS00))         // 100
#define TIMER_1024_PRESCALAR    TCCR0B |= (1 << CS02) | (TCCR0B & ~(1 << CS01))| (1 << CS00)                     // 101

// External clock is pending

#define DEFAULT_TIMER_PRESCALAR TIMER_256_PRESCALAR

#define TIMER_DIV 256

// Prototypes
extern void timerBegin(unsigned long,unsigned long,unsigned char);
extern void timerStart(unsigned char);
extern void timerStop(unsigned char);
extern void timerClearCount(unsigned char);
extern void timerEnableInterrupt(unsigned char);
extern void timerDisableInterrupt(unsigned char);


#ifdef ENABLE_TIMER1_ISR
#warning "Timer1 is 16-bit development is pending use 0 and 2 8 bit"
#endif

#endif