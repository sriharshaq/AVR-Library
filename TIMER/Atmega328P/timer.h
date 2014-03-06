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

// Prototypes
extern void timerBegin(unsigned long,unsigned long,unsigned char);
extern void timerStart(unsigned char);
extern void timerStop(unsigned char);

#endif