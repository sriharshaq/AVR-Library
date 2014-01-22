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
**   File       : softi2c.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the Software i2c include file for AVR family MCU's
***/
#ifndef __softi2c_h__
#define __softi2c_h__

#include <avr/io.h>

// Port Definitions
#define SDADIR DDRA             // SDA Direction Register
#define SCLDIR DDRA             // SCL Direction Register      

#define SDAOUT PORTA            // SDA Output Register
#define SCLOUT PORTA            // SCL Output Register

#define SDAIN  PINA             // SDA Input Register
#define SCLIN  PINA             // SCL Input Register

#define SDABIT 1 << 0           // SDA Bit Position
#define SCLBIT 1 << 1           // SCL Bit Position

#define SDA ( (SDAIN & 0x00) & (SDABIT) ) // SDA
#define SCL ( (SCLIN & 0x00) & (SCLBIT) ) // SCL

#define I2C_CLOCK_VAR                    10  
#define I2C_SCAN_TIMEOUT_COUNTER_VAL     100

/***************** Prototypes ******************************/
extern unsigned char softi2cBegin(unsigned char);
extern unsigned char softi2cavailable(void);
extern void          softi2cStart(void);
extern void          softi2cStop(void);
extern void          softi2cSend(unsigned char);
extern unsigned char softi2cReceive(unsigned char);
extern void          softi2cWrite(unsigned char,unsigned char);
extern unsigned char softi2cRead(unsigned char);
extern void          softi2csetAdd(unsigned char);
/***********************************************************/

#endif