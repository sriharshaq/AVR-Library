#include "uart.h"

#ifdef ENABLE_UART_RX_INTERRUT
volatile unsigned char uartNewLineFlag = 0;
volatile unsigned char uartReadBuffer[RECV_BUFFER_SIZE];
volatile unsigned int  uartReadCount = 0;
volatile unsigned char uartNewLineCount = 0;
volatile unsigned char uartNewLineCountMax = 0;
volatile unsigned char uartNewLineIndexes[MAX_NL_INDEX];
volatile unsigned char uartLfCr = 0;
#endif

unsigned long OscillatorFrequency = 1000000;
/********************************************************************
*
*	Function	:	SetOsc
*
*	Description	:	Sets the Oscillator Frequency
*
*	Input       :	unsigned long
*
*	Returnvalue	:	none
*
*********************************************************************/
void SetOsc(unsigned long OscFreq)
{
	OscillatorFrequency = OscFreq;
}

/********************************************************************
*
*	Function	:	Serialbegin
*
*	Description	:	Initilizes UART (8 bit,no parity,1 stop)
*
*	Input       :	unsigned long ( baud rate)
*
*	Returnvalue	:	none
*
*********************************************************************/
void Serialbegin(unsigned long baudRate)
{
	unsigned long autoReloadvalue = (((OscillatorFrequency / (baudRate * 16))) - 1);
	UBRRL = autoReloadvalue;
	UBRRH = autoReloadvalue >> 8;
	UCSRB = ((1<<TXEN)|(1<<RXEN)) | (1<<RXCIE);
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); 
}

/********************************************************************
*
*	Function	:	Serialavailable
*
*	Description	:	Returns weather RI flag set or not
*
*	Input       :	none
*
*	Returnvalue	:	__bit RI flag
*
*********************************************************************/
unsigned char Serialavailable(void)
{
	if((UCSRA &(1<<RXC)) == 1)
	return 1;
	else
	return 0;
}


/********************************************************************
*
*	Function	:	Serialwrite
*
*	Description	:	Sends single byte to uart
*
*	Input       :	unsigned char(Byte)
*
*	Returnvalue	:	none
*
*********************************************************************/
void Serialwrite(unsigned char Byte)
{
 while((UCSRA &(1<<UDRE)) == 0);
 // Transmit data
 UDR = Byte;
}

/********************************************************************
*
*	Function	:	Serialread
*
*	Description	:	Receives single byte from uart
*
*	Input       :	none
*
*	Returnvalue	:	unsigned char(Byte)
*
*********************************************************************/
volatile unsigned char Serialread(void)
{
	 while((UCSRA &(1<<RXC)) == 0);
	 return UDR;
}

/********************************************************************
*
*	Function	:	Serialprint
*
*	Description	:	Sends string to uart
*
*	Input       :	unsigned char*
*
*	Returnvalue	:	none
*
*********************************************************************/
void Serialprint(unsigned char *sPtr)
{
	for(;*sPtr!='\0';Serialwrite(*(sPtr++)));
}


/********************************************************************
*
*	Function	:	SerialIntWrite
*
*	Description	:	Sends integer to uart
*
*	Input       :	unsigned char
*
*	Returnvalue	:	none
*
*********************************************************************/
void SerialIntWrite(unsigned char num)
{
	unsigned char Div = 10;
	Serialwrite((num / Div)+48);
	Serialwrite((num % Div)+48);
}

#ifdef ENABLE_UART_RX_INTERRUT
ISR(USART_RXC_vect)
{
	 uartReadBuffer[uartReadCount] = UDR;
	 if(uartReadBuffer[uartReadCount]  == TERMIN_LF || uartReadBuffer[uartReadCount]  == TERMIN_CR)
	 {
		 if(uartReadBuffer[uartReadCount]  == TERMIN_LF)
		 {
				 uartNewLineIndexes[uartNewLineCount] = uartReadCount;
				 if(uartNewLineCount == uartNewLineCountMax)
				 uartNewLineFlag = 1;
				 else
				 uartNewLineCount++;	 
		 }
		 uartLfCr++;
	 }
	 uartReadCount++;
}

void Serialflush(void)
{
	    unsigned char i;
		uartNewLineCount = 0;
		uartNewLineFlag = 0;
		uartReadCount = 0;
		uartLfCr = 0;
		for(i=0;i<RECV_BUFFER_SIZE;i++)
		uartReadBuffer[i] = CHAR_NULL;
}

 void enableSerialinterrupt(void)
 {
	 sei();
 }
 
 void setNewline(volatile unsigned char count)
 {
	 uartNewLineCountMax = count;
 }
#endif

/************************* EOF **************************************/



