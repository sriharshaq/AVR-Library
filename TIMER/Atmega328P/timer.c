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
**   File       : timer.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware timer driver for AVR family MCU's
***/

#include "timer.h"


// Globals
#ifdef ENABLE_TIMER0_ISR
volatile unsigned int timerCount0 = 0;
#endif
#ifdef ENABLE_TIMER1_ISR
volatile unsigned int timerCount1 = 0;
#endif
#ifdef ENABLE_TIMER2_ISR
volatile unsigned int timerCount2 = 0;
#endif

/*** Function    : timerBegin
**   Parameters  : unsigned long(Oscillator Freq in Hz),unsigned long time in micro seconds,unsigned char timerNo
**   Return      : None
**   Description : It will initiate hardware timer
**/
void timerBegin(unsigned long __OscFreq,unsigned long timeuSec,unsigned char TimerNo)
{
	unsigned char reloadVal;
	reloadVal = (timeuSec / (__OscFreq / TIMER_DIV)) - 1;
// Normal Mode
//	TCCR0A &= ~(1 << WGM00) | ~(1 << WGM01);
//	TCCR0B &= ~(1 << WGM02);

// Prescalar
DEFAULT_TIMER_PRESCALAR;

if(TimerNo == HW_TIMER0)
{
TCNT0 = reloadVal;
}
else if(TimerNo == HW_TIMER2)
{
TCNT2 = reloadVal;
}

}

/*** Function    : timerStart
**   Parameters  : unsigned char TimerNo (Timer Number)
**   Return      : None
**   Description : It will start hardware timer
**/
void timerStart(unsigned char TimerNo)
{

}

/*** Function    : timerStop
**   Parameters  : unsigned char TimerNo (Timer Number)
**   Return      : None
**   Description : It will stop hardware timer
**/
void timerStop(unsigned char TimerNo)
{

}

/*** Function    : timerClearCount
**   Parameters  : unsigned char TimerNo (Timer Number)
**   Return      : None
**   Description : It will clear counter of timer
**/
void timerClearCount(unsigned char TimerNo)
{
	#ifdef ENABLE_TIMER0_ISR
	if(TimerNo == HW_TIMER0)
	timerCount0 = 0;
	#endif
	#ifdef ENABLE_TIMER1_ISR
	if(TimerNo == HW_TIMER1)
	timerCount1 = 0;
	#endif
	#ifdef ENABLE_TIMER2_ISR
	if(TimerNo == HW_TIMER2)
	timerCount2 = 0;
	#endif
}

void timerEnableInterrupt(unsigned char TimerNo)
{
	if(TimerNo == HW_TIMER0)
	{
	TIMSK0 |= 1 << TOIE0;
	}
	else if(TimerNo == HW_TIMER1)
	{
	TIMSK1 |= 1 << TOIE1;		
	}
	else if(TimerNo == HW_TIMER2)
	{
	TIMSK2 |= 1 << TOIE2;	
	}
	
	// Enable Global Interrupts
	sei();
}

void timerDisableInterrupt(unsigned char TimerNo)
{
	if(TimerNo == HW_TIMER0)
	{
		TIMSK0 &= ~(1 << TOIE0);
	}
	else if(TimerNo == HW_TIMER1)
	{
		TIMSK1 &= ~(1 << TOIE1);
	}
	else if(TimerNo == HW_TIMER2)
	{
		TIMSK2 &= ~(1 << TOIE2);
	}
}

// ISR
#ifdef ENABLE_TIMER0_ISR
ISR(TIMER0_OVF_vect) 
{
	timerCount0++;
}
#endif

#ifdef ENABLE_TIMER1_ISR
ISR(TIMER1_OVF_vect)
{
	timerCount1++;
}
#endif

#ifdef ENABLE_TIMER2_ISR
ISR(TIMER1_OVF_vect)
{
	timerCount2++;
}
#endif