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
**   File       : i2c.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware i2c driver for AVR family MCU's
***/

#include "i2c.h"


/*** Function    : i2cBegin
**   Parameters  : unsigned long (Osc Freq in Hz), unsigned long (Speed in Hz)
**   Return      : None
**   Description : It will Initiate the I2C device speed
**/
void i2cBegin(unsigned long OscFreq,unsigned long Speed)
{
unsigned char preScalar = 2; 
I2C_SPEED_REG = I2C_SPEED_CALC(OscFreq,Speed,preScalar);
}

/*** Function    : i2cSetMode
**   Parameters  : unsigned char (MODE)
**   Return      : None
**   Description : It will configure I2C Mode (Master/Slave)
**/
void i2cSetMode(unsigned char __Mode)
{
if(__Mode == I2C_MASTER_MODE)
{
// Configure Device as Master
}
else
{
// Configure Device as Slave
}
}

/*** Function    : i2cDetect
**   Parameters  : unsigned char (Device Address)
**   Return      : 1 -> Detected, 0 -> Not Detected
**   Description : It will configure I2C Mode (Master/Slave)
**/
unsigned char i2cDetect(unsigned char __DevAddress)
{

}

/*** Function    : i2cavailable
**   Parameters  : None
**   Return      : 1 -> Available (Free), 0 -> Busy
**   Description : It will check the status of i2c bus
**/
unsigned char i2cavailable(void)
{

}








