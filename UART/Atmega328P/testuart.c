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
**   File       : testuart.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the test code for AVR uart driver
***/

#include "uart.h"

const unsigned long OSC_FREQ = 16000000;
#define BAUD_RATE              9600

#define NEW_LINE_THRESHOLD  1


/*** Function    : main
**   Parameters  : None
**   Return      : int
**   Description : It is the entry point of program
**/
int main(void)
{
//SetOsc(OSC_FREQ);             // Set Oscillator Freq
Serialbegin(OSC_FREQ,BAUD_RATE);       // Set Baud Rate
Serialflush();                // Clear the buffers
Serialprint("uart test\n\r"); // Print a string
setSerialinterrupt();         // Enable Serial Interrupt
while(1)
{
 while(uartNewLineFlag == 0); // Wait until new line count reaches threshold
 Serialprint(uartReadBuffer);                // Print the uart read buffer
 Serialflush();                              // Flush the buffer
}
}
