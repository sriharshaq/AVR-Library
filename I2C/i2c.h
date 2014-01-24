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
**   File       : i2c.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware i2c driver include file for AVR family MCU's
***/
#ifndef __i2c_h__
#define __i2c_h__


#define I2C_MASTER_MODE 0
#define I2C_SLAVE_MODE  1

/***************** Prototypes ******************************/
extern void           i2cBegin(unsigned long,unsigned long);        // Oscillator Frequency in Hz, Speed in Hz
extern void           i2cSetMode(unsigned char);
extern unsigned char  i2cDetect(unsigned char);                       // Device Address
extern unsigned char  i2cavailable(void);

extern void           i2cStart(void);
extern void           i2cStop(void);
extern void           i2cWritebyte(unsigned char);
extern unsigned char  i2cReadbyte(unsigned char);
extern void           i2cWrite(unsigned char,unsigned char);
extern unsigned char  i2cRead(unsigned char);

extern void           i2cWriteBlock(unsigned char,unsigned char,unsigned char*);
extern void           i2cReadBlock(unsigned char,unsigned char,unsigned char*);

extern void           i2csetAdd(unsigned char);
extern unsigned char* i2cScan(unsigned char ,unsigned char);
/***********************************************************/

#endif
