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
**   File       : twi.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware two wire driver include file for AVR family MCU's
***/
#ifndef __i2c_h__
#define __i2c_h__

#include <math.h>


#define ENABLE_TWI_INTERRUPT

#define TWI_DEFAULT_PRESCALE 2

#define TWI_MASTER 0
#define TWI_SLAVE  1

#define TWI_REG_SPEED   TWBR
#define TWI_REG_CONTROL TWCR

#define TWI_REG_START  TWSTA
#define TWI_REG_INT    TWINT
#define TWI_REG_EN     TWEN
#define TWI_REG_STOP   TWSTO

#define TWI_WAIT_FLAG  !(TWI_REG_CONTROL & (1 << TWI_REG_INT))

#define TWI_SPEED_CALC(__OscFreq,__Speed,__PreScalar) ((OscFreq/__Speed) - 16 - (pow(4,__PreScalar)))


/*#ifdef ENABLE_TWI_INTERRUPT
#define __twiStart     TWI_REG_CONTROL = (1 << TWI_REG_INT) | (1 << TWI_REG_START) | (1 << TWI_REG_EN) 
#define __twiStop()    TWI_REG_CONTROL = (1 << TWI_REG_INT) | (1 << TWI_REG_STOP)  | (1 << TWI_REG_EN)
#else
#define __twiStart     TWI_REG_CONTROL =  (1 << TWI_REG_START) | (1 << TWI_REG_EN) 
#define __twiStop()    TWI_REG_CONTROL =  (1 << TWI_REG_STOP)  | (1 << TWI_REG_EN)
#endif*/ 

/***************** Prototypes ******************************/
extern void           twiSetspeed(unsigned long,unsigned long);        // Oscillator Frequency in Hz, Speed in Hz
extern void           twiStart(void);
extern void           twiStop(void);
extern void           twiBegin(unsigned char);
extern void           twiWriteByte(unsigned char);
extern char           twiReadByte(void);
extern void           twiWrite(unsigned char,unsigned char);
extern char           twiRead(unsigned char);           
extern void           twiWriteBlock(unsigned char,unsigned char,char*);
extern void           twiReadBlock(unsigned char,unsigned char,char*);
extern void           twiScan(char*);
/***********************************************************/

#endif
