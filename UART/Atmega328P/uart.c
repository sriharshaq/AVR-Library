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
**   File       : uart.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the uart driver for AVR family MCU's
***/

#include "uart.h"

// Globals

// Oscillator Frequency (Default 1MHz)
unsigned long OscillatorFrequency = 1000000;


#ifdef SERIAL_RX_INTERRUPT_ENABLE

// Uart New Line Flag (Set when new line received)
 volatile unsigned char uartNewLineFlag = 0;
// UART Read Buffer to store Received Data
 volatile char uartReadBuffer[UART_RX_BUFFER_SIZE];
// Uart Byte Count
 volatile unsigned int  uartReadCount    = 0;
// Uart New Line Count
 volatile unsigned char uartNewLineCount = 0;
// It holds every new line index
 volatile unsigned char uartNewLineIndexes[NEW_LINE_INDEX_BUFFER_SIZE];

#endif


/*** Function    : Serialbegin
**   Parameters  : unsigned long(Oscillator Freq in Hz),unsigned long (Standard BaudRate)
**   Return      : None
**   Description : It will Set the baud rate for serial communication
**/
void Serialbegin(unsigned long OscillatorFrequency,unsigned long baudRate)
{
	unsigned long autoReloadvalue = (((OscillatorFrequency / (baudRate * 16))) - 1);
	UBRR0L = autoReloadvalue;
	UBRR0H = autoReloadvalue >> 8;
	UCSR0B = ((1<<TXEN0)|(1<<RXEN0)) | (1<<RXCIE0);
    UCSR0C = ((1<<UCSZ00)|(1<<UCSZ01));
}

/*** Function    : Serialavailable
**   Parameters  : None
**   Return      : __bit (If byte is available in receive buffer returns 1, else returns 0)
**   Description : It will give the whether Receiver is available or not
**/
unsigned char Serialavailable(void)
{
	if((UCSR0A &(1<<RXC0)) == 1)
	return 1;
	else
	return 0;
}


/*** Function    : Serialwrite
**   Parameters  : unsigned char (Single character that will send to UART)
**   Return      : None
**   Description : It will write single character to UART
**/
void Serialwrite(char Byte)
{
 while((UCSR0A &(1<<UDRE0)) == 0);
 // Transmit data
 UDR0 = Byte;
}

/*** Function    : Serialread
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will read single byte from uart
**/
char Serialread(void)
{
	 while((UCSR0A &(1<<RXC0)) == 0);
	 return UDR0;
}

/*** Function    : Serialprint
**   Parameters  : unsigned char *
**   Return      : None
**   Description : It will send the string to UART
**/
void Serialprint(char *sPtr)
{
	for(;*sPtr!='\0';Serialwrite(*(sPtr++)));
}


/*** Function    : SerialIntWrite
**   Parameters  : unsigned char *
**   Return      : None
**   Description : It will write integer on uart
**/
void SerialIntWrite(signed int num,unsigned char __RADIX)
{
char __buffer[20];
itoa(num,__buffer,__RADIX);
Serialprint(__buffer);
}


/*** Function    : SerialDoubleWrite
**   Parameters  : double,unsigned char 
**   Return      : None
**   Description : It will write double on uart
**/
void SerialDoubleWrite(double __f,unsigned char __dec)
{
char __buffer[20];
char *__bPtr;
__bPtr = dtostrf(__f,10,2,__buffer);
Serialprint(__bPtr);
}

#ifdef SERIAL_RX_INTERRUPT_ENABLE

/*** Function    : setSerialinterrupt
**   Parameters  : None
**   Return      : None
**   Description : It sets the Serial Interrupt
**/
 void setSerialinterrupt(void)
 {
	 sei();
 }

/*** Function    : ISR (This is routine)
**   Parameters  : None
**   Return      : None
**   Description : It is ISR for UART Receive (It will trigger if any byte is received)
**/
ISR(USART_RX_vect)
{
volatile char temp = UDR0;
uartReadBuffer[uartReadCount++] = temp;
if(temp == LF)
{
uartNewLineFlag = 1;
uartNewLineIndexes[uartNewLineCount] = uartReadCount;
uartNewLineCount++;
}
}

/*** Function    : Serialflush
**   Parameters  : None
**   Return      : None
**   Description : It clears the UART buffer,Index Buffer and Flags
**/
void Serialflush(void)
{
	    unsigned char i;
		uartNewLineCount = 0;
		uartNewLineFlag = 0;
		uartReadCount = 0;
		for(i=0;i<UART_RX_BUFFER_SIZE;i++)
		uartReadBuffer[i] = CHAR_NULL;
}


 

#endif

/************************* EOF **************************************/



