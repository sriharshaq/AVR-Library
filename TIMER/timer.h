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

#define ENABLE_TIMER0_COUNT
#define ENABLE_TIMER1_COUNT
#define ENABLE_TIMER2_COUNT
#define ENABLE_TIMER3_COUNT
#define ENABLE_TIMER4_COUNT

#define HW_TIMER0 0
#define HW_TIMER1 1
#define HW_TIMER2 1
#define HW_TIMER3 1

#ifdef ENABLE_TIMER0_COUNT
extern volatile unsigned int timerCount0;
#endif
#ifdef ENABLE_TIMER1_COUNT
extern volatile unsigned int timerCount1;
#endif
#ifdef ENABLE_TIMER2_COUNT
extern volatile unsigned int timerCount2;
#endif
#ifdef ENABLE_TIMER3_COUNT
extern volatile unsigned int timerCount3;
#endif

#if defined (__AVR_ATmega16U2__ ) || (__AVR_ATmega32U2__) || (__AVR_ATmega8__)
#define TIMER_NO_CLOCK_SOURCE   TCCR0 &= ~(1 << CS02) | ~(1 << CS01) | ~(1 << CS00)                           // 000
#define TIMER_NO_PRESCALAR      TCCR0 |= (TCCR0 & ~(1 << CS02)) | (TCCR0 & ~(1 << CS01)) | (1 << CS00)        // 001
#define TIMER_8_PRESCALAR       TCCR0 |= (TCCR0 & ~(1 << CS02)) | (1 << CS01) | (TCCR0 & ~(1 << CS00)         // 010
#define TIMER_64_PRESCALAR      TCCR0 |= (TCCR0 & ~(1 << CS02)) | (1 << CS01) | (1 << CS00)                   // 011
#define TIMER_256_PRESCALAR     TCCR0 |= (1 << CS02) | (TCCR0 & ~(1 << CS01))| (TCCR0 & ~(1 << CS00))         // 100
#define TIMER_1024_PRESCALAR    TCCR0 |= (1 << CS02) | (TCCR0 & ~(1 << CS01))| (1 << CS00)                    // 101

#elif defined (__AVR_ATmega328__) || (__AVR_ATmega328P__)
#define TIMER_NO_CLOCK_SOURCE   TCCR0B &= ~(1 << CS02) | ~(1 << CS01) | ~(1 << CS00)                             // 000
#define TIMER_NO_PRESCALAR      TCCR0B |= (TCCR0B & ~(1 << CS02)) | (TCCR0B & ~(1 << CS01)) | (1 << CS00)        // 001
#define TIMER_8_PRESCALAR       TCCR0B |= (TCCR0B & ~(1 << CS02)) | (1 << CS01) | (TCCR0B & ~(1 << CS00)         // 010
#define TIMER_64_PRESCALAR      TCCR0B |= (TCCR0B & ~(1 << CS02)) | (1 << CS01) | (1 << CS00)                    // 011
#define TIMER_256_PRESCALAR     TCCR0B |= (1 << CS02) | (TCCR0B & ~(1 << CS01))| (TCCR0B & ~(1 << CS00))         // 100
#define TIMER_1024_PRESCALAR    TCCR0B |= (1 << CS02) | (TCCR0B & ~(1 << CS01))| (1 << CS00)                     // 101
#endif

// External clock is pending

#define DEFAULT_TIMER_PRESCALAR TIMER_1024_PRESCALAR

#define TIMER_DIV 1024

// Prototypes
extern void timerBegin(unsigned long,unsigned long,unsigned char);
extern void timerStart(unsigned char);
extern void timerStop(unsigned char);

#endif