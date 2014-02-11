

#ifndef __spi_h__
#define __spi_h__

#include <avr/io.h>

#define SPI_PORT_REG PORTB

#define MOSI 6
#define MISO 5
#define SCK  4
#define CS   3

#define CHIP_SELECT    SPI_PORT_REG |=   SPI_PORT_REG << CS
#define CHIP_DESELECT  SPI_PORT_REG &= ~(SPI_PORT_REG << CS)