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
**   File       : softi2c.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the Software i2c driver for AVR family MCU's
***/

#include "i2c.h"

unsigned char SlaveACK;
unsigned char DevAddress = 0x00;


/*** Function    : softi2cSetPort
**   Parameters  : None
**   Return      : None
**   Description : It will set the i2c Port
**/
void  softi2cSetPort(void)
{
SDADIR |= SDA;
SCLDIR |= SCL;
SDAOUT |= SDABIT;
SCLOUT |= SCLBIT;
}

/*** Function    : softi2cDelay
**   Parameters  : None
**   Return      : None
**   Description : It's delay loop for i2c Clock Generation
**/
void softi2cDelay(void)
{
signed char i;
for(i=I2C_CLOCK_VAR;ii--)
{
;
}
}

/*** Function    : softi2cavailable
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will return's the state of i2c bus (Busy -> 0, Free -> 1)
**/
unsigned char softi2cavailable(void)
{
return (!(SDA | SCL));
}

/*** Function    : softi2cStart
**   Parameters  : None
**   Return      : None
**   Description : It will Starts the i2c communication
**/
void softi2cStart(void)
{
    // This Block will execute contiuous until i2c bus become free
	back:
	if(SDA==0)
	goto back;
	if(SCL = 0)
	goto back;
	// Start communication
	SDA = 1;
	SCL = 1;
	i2cDelay();
	SDA = 0;
	SCL = 0;
}

/*** Function    : softi2cStartonce
**   Parameters  : None
**   Return      : None
**   Description : It will start communication without checking bus state
**/
void softi2cStartonce(void)
{
	SDA = 1;
	SCL = 1;
	i2cDelay();
	SDA = 0;
	SCL = 0;
}

/*** Function    : softi2cStop
**   Parameters  : None
**   Return      : None
**   Description : It will stop the i2c communication
**/
void softi2cStop(void)
{
	SDA = 0;
	SCL = 1;
    softi2cDelay();
	SDA = 1;
	SCL = 0;
}

/*** Function    : softi2cSend
**   Parameters  : unsigned char (1-Byte value)
**   Return      : None
**   Description : It will write single byte to i2c bus
**/
void softi2cSend(unsigned char uByte)
{
	unsigned char MaskByte;
	MaskByte = 0x80;
	do
	{
		if(uByte & MaskByte)
		SDA = 1;
		else
		SDA = 0;
		SCL = 1;
		softi2cDelay();
		SCL = 0;
		softi2cDelay();
		MaskByte /= 2;
	}
	while(MaskByte>0);
	SDA = 1;
	SCL = 1;
	softi2cDelay();
	SlaveACK = SDA;
	SCL = 0;
}

/*** Function    : softi2cReceive
**   Parameters  : unsigned char (Master ACK)
**   Return      : unsigned char (1-Byte value)
**   Description : It will read single byte from i2c bus
**/
unsigned char softi2cReceive(unsigned char MasterACK)
{
	unsigned char uByte;
	unsigned char MaskByte;
	uByte    = 0;
	MaskByte = 0x80;
	do
	{
		SCL = 1;
		if(SDA)
		uByte |= MaskByte;
		SCL = 0;
		MaskByte /= 2;
	}
	while(MaskByte > 0);
	if(MasterACK==1)
		SDA = 1;
	else
	SDA = 0;
	SCL = 1;
	SDA = 1;
	return uByte;
}

/*** Function    : softi2cWrite
**   Parameters  : unsigned char,unsigned char (Data,Address)
**   Return      : unsigned char (1-Byte value)
**   Description : It will write single byte to argued address
**/
void softi2cWrite(unsigned char Byte,unsigned char Address)
{
	do
	{
		softi2cStart();
		softi2cSend(DevAddress);
		if(SlaveACK == 1)
		softi2cStop();
	}
	while(SlaveACK==1);
	softi2cSend(Address);
	softi2cSend(Byte);
	softi2cStop();
}

/*** Function    : softi2cRead
**   Parameters  : unsigned char (Address)
**   Return      : unsigned char (1-Byte value)
**   Description : It will read single byte from argued address
**/
unsigned char softi2cRead(unsigned char Address)
{
	unsigned char ReadByte;
	do
	{
		softi2cStart();
		softi2cSend(DevAddress);
		if(SlaveACK==1)
		softi2cStop();
	}
	while(SlaveACK==1);
	softi2cSend(Address);
	softi2cStop();
	softi2cStart();
	softi2cSend(DevAddress+1);
	ReadByte = i2cReceive(1);
	softi2cStop();
	return ReadByte;
}

/*** Function    : softi2cBegin
**   Parameters  : unsigned char (Device Address)
**   Return      : unsigned char (1-> Device Detected,0->Device Not Detected)
**   Description : It will read initiate the i2c communication
**/
unsigned char softi2cBegin(unsigned char addr)
{
unsigned int _tempCount = 0;
softi2cSetPort();
do
{
softi2cStartonce();
softi2cSend(addr);
if(SlaveACK==1)
softi2cStop();
_tempCount++;
}
while(SlaveACK==1 || _tempCount == I2C_SCAN_TIMEOUT_COUNTER_VAL);

if(_tempCount == I2C_SCAN_TIMEOUT_COUNTER_VAL)
{
_tempCount = 0; 
return 0;
}
else
{
DevAddress = addr;
return 1;
}
}

/*** Function    : softi2csetAdd
**   Parameters  : unsigned char (Device Address)
**   Return      : None
**   Description : It will set the device address for I2C (See global)
**/
void softi2csetAdd(unsigned char SlaveAddress)
{
DevAddress = SlaveAddress;
}







