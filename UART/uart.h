#ifndef __uart_h__
#define __uart_h__

#define ENABLE_UART_RX_INTERRUT 1

#define CHAR_NULL   '\0'
#define TERMIN_LF   '\n'
#define TERMIN_CR   '\r'

#include <avr/io.h>


#ifdef ENABLE_UART_RX_INTERRUT
#include <avr/interrupt.h>

#ifndef RECV_BUFFER_SIZE
#define RECV_BUFFER_SIZE 64
#warning "RECV_BUFFER_SIZE not defined, default '64' bytes allocated"
#endif
#if RECV_BUFFER_SIZE > 255
#error "Invalid Buffer Size"
#elif RECV_BUFFER_SIZE < 1
#error "Invalid Buffer Size"
#endif

#define MAX_NL_INDEX 28

extern volatile unsigned char uartNewLineFlag;
extern volatile unsigned char uartReadBuffer[RECV_BUFFER_SIZE];
extern volatile unsigned int  uartReadCount;
extern volatile unsigned char uartNewLineCount;
extern volatile unsigned char uartNewLineCountMax;
extern volatile unsigned char uartNewLineIndexes[MAX_NL_INDEX];
extern volatile unsigned char uartLfCr;

extern  void enableSerialinterrupt(void);
extern  void setNewline(volatile unsigned char);

#endif

/***************** Prototypes ****************************/
extern void          Serialbegin(unsigned long);
extern unsigned char Serialavailable(void);
extern void          Serialwrite(unsigned char);
extern void          Serialprint(unsigned char *);
extern volatile unsigned char Serialread(void);
extern void          SerialIntWrite(unsigned char num);
extern void          SetOsc(unsigned long OscFreq);
extern void          Serialflush(void);
/*********************************************************/


#endif

