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
**   File       : adc.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware ADC driver include file for AVR family MCU's
***/

#ifndef __adc_h__
#define __adc_h__

#include <avr/io.h>
#include <avr/interrupts.h>


//#define ENABLE_ADC_INTERRUPT

// Reference Voltage Settings
#define VREF_EXT_AREF 0x00    // External Ref Voltage at Aref Pin
#define VREF_EXT_AVCC 0x40    // External Ref Voltage at AVCC Pin with Capacitor
#define VREF_INT_256  0xE0    // Internal 2.56V Reference

// Analog Channels
#define ADC_MUX_CH0   0x00
#define ADC_MUX_CH1   0x01
#define ADC_MUX_CH2   0x02
#define ADC_MUX_CH3   0x03
#define ADC_MUX_CH4   0x04
#define ADC_MUX_CH5   0x05
#define ADC_MUX_CH6   0x06
#define ADC_MUX_CH7   0x07


#define VrefMilliVolts     5   
#define Vref               (VrefMilliVolts * 1000)    

#define EXTERNAL_AREF 0
#define EXTERNAL_AVCC 1
#define INTERNAL256   2

#define ADC_MUX_REGISTER             ADMUX
#define ADC_STATUS_CONTROL_REGISTER  ADCSRA

#define ADC_ENABLE                  ADC_STATUS_CONTROL_REGISTER |=  _BV(7)
#define ADC_DISABLE                 ADC_STATUS_CONTROL_REGISTER &= ~_BV(7)

#define ADC_START_CONVERSION        ADC_STATUS_CONTROL_REGISTER |=  _BV(6)
#define ADC_STOP_CONVERSION         ADC_STATUS_CONTROL_REGISTER &= ~_BV(6)

#define ADC_AUTO_TRIGGER_ENABLE     ADC_STATUS_CONTROL_REGISTER |=  _BV(5)
#define ADC_AUTO_TRIGGER_DISABLE    ADC_STATUS_CONTROL_REGISTER &= ~_BV(5)

//#define ADC_INTERRUPT_FLAG_ENABLE   ADC_STATUS_CONTROL_REGISTER & 0x10

#define ADC_INTERRUPT_ENABLE        ADC_STATUS_CONTROL_REGISTER |=  _BV(3)
#define ADC_INTERRUPT_DISABLE       ADC_STATUS_CONTROL_REGISTER &= ~_BV(3)

#define ADC_PRESCALAR_CLEAR         ADC_STATUS_CONTROL_REGISTER &= ~(_BV(0) | _BV(1) | _BV(2))
#define ADC_PRESCALAR_2             ADC_STATUS_CONTROL_REGISTER |= _BV(0)
#define ADC_PRESCALAR_4             ADC_STATUS_CONTROL_REGISTER |= _BV(1)
#define ADC_PRESCALAR_8             ADC_STATUS_CONTROL_REGISTER |= _BV(0) | _BV(1)
#define ADC_PRESCALAR_16            ADC_STATUS_CONTROL_REGISTER |= _BV(2)
#define ADC_PRESCALAR_32            ADC_STATUS_CONTROL_REGISTER |= _BV(0) | _BV(2)
#define ADC_PRESCALAR_64            ADC_STATUS_CONTROL_REGISTER |= _BV(1) | _BV(2)
#define ADC_PRESCALAR_128           ADC_STATUS_CONTROL_REGISTER |= _BV(0) | _BV(1) | _BV(2)

#define ADC_CONVERSION_COMPLETE     ADC_STATUS_CONTROL_REGISTER & _BV(7)

#define ADC_REF_VOLTAGE             2.56

#define ADC_RESOLUTION_VALUE        1023

#define ADC_RAW_TO_VOLTAGE(val)     val * (ADC_REF_VOLTAGE/ADC_RESOLUTION_VALUE)     

int analogRead(int);

#endif