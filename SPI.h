/* 
 * File:   SPI.h
 * Author: cyber
 *
 * Created on March 27, 2022, 7:42 PM
 */

#ifndef SPI_H
#define	SPI_H

#define Master   1
#define Slave    0

#define  SPI_CLK 3   // ** Freq/128 ** Prescaler //

#define  MOSI   5 
#define  MISO   6 
#define  SCK    7
#define  SS     4


void Init_SPI(unsigned char mode);
void SPI_send(unsigned char data);
char SPI_read(void);
void SPI_send_str(char * str);
void SPI_send_num(int num);


#endif	/* SPI_H */

