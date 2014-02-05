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
**   File       : adc.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware adc driver for AVR family MCU's
***/

#include "adc.h"

#ifdef ENABLE_ADC_INTERRUPT
volatile int adcReadval = 0;
#endif


int analogRead(int MuxCh)
{
ADC_MUX_REGISTER |= MuxCh;
ADC_START_CONVERSION;
#ifndef ENABLE_ADC_INTERRUPT
while(ADC_CONVERSION_COMPLETE);
ADC_STOP_CONVERSION;
return ADC;
#endif
}

double analogReadVoltage(int MuxCh)
{
double _val = ADC_RAW_TO_VOLTAGE(analogRead(MuxCh));
return _val;
}

void analogReference(unsigned char ref)
{
// External Aref
if(ref == EXTERNAL_AREF)
ADC_MUX_REGISTER |= VREF_EXT_AREF;
// External Avcc (Capacitor should connect)
else if(ref == VREF_EXT_AVCC)
ADC_MUX_REGISTER |= VREF_EXT_AVCC;
// Internal 2.56
else if(ref == VREF_INT_256)
ADC_MUX_REGISTER |= VREF_INT_256;
}

void setPrescalar(unsigned char __preScalarVal)
{
// Clear Mux Prescalar Register
ADC_PRESCALAR_CLEAR;
switch(__preScalarVal)
{
case 2  :   ADC_PRESCALAR_2;
            break;
case 4  :   ADC_PRESCALAR_4;
            break;
case 8  :   ADC_PRESCALAR_8;
            break;
case 16  :  ADC_PRESCALAR_16;
            break;
case 32  :  ADC_PRESCALAR_32;
            break;
case 64  :  ADC_PRESCALAR_64;
            break;
case 128 :  ADC_PRESCALAR_128;
            break;
default  :  ADC_PRESCALAR_2;
            break;
}
}

#ifdef ENABLE_ADC_INTERRUPT
ISR(ADC_vect)
{
ADC_STOP_CONVERSION;
}
#endif

