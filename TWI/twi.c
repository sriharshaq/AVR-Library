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
**   File       : twi.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware two wire  driver for AVR family MCU's
***/

#include "twi.h"

volatile unsigned char DeviceAddress = 0;

/*** Function    : twiSetspeed
**   Parameters  : unsigned long (Osc Freq in Hz), unsigned long (Speed in Hz)
**   Return      : None
**   Description : It will set the speed of the two wire module
**/
void twiSetspeed(unsigned long OscFreq,unsigned long Speed)
{
TWI_REG_SPEED = TWI_REG_SPEED(OscFreq,Speed,TWI_DEFAULT_PRESCALE);
}

void twiStart(void)
{
 TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
 while ((TWCR & (1<<TWINT)) == 0);
}

void twiStop(void)
{
 TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

/*** Function    : twiBegin
**   Parameters  : unsigned char (Device Address)
**   Return      : None
**   Description : It will set the address of Two Wire Interface
**/
void twiBegin(unsigned char __Address)
{
DeviceAddress = __Address;
}

char twiReadByte(void)
{
 TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
 while ((TWCR & (1<<TWINT)) == 0);
 return TWDR;
 }




