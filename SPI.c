/*
 * File:   SPI.c
 * Author: cyber
 *
 * Created on March 27, 2022, 7:57 PM
 */


#define F_CPU 16000000UL
#include <avr/io.h>
#include "SPI.h"
#include <stdlib.h>


void Init_SPI(unsigned char mode){
    if(mode){
        //Master
        //Data Direction 
         DDRB |= (1<<MOSI)|(1<<SS)|(1<<SCK); // Alternative Function ON
         // ENABLE SPI, SELECT CLK, ENABLE MASTER MODE
        SPCR |= (1<<SPE)|(1<<MSTR)|SPI_CLK;
        
    }else{
         // SLAVE
        // DATA DIRECTION
        DDRB |= (1<<MISO);
        SPCR |= (1<<SPE);
    }
}
void SPI_send(unsigned char data){
    SPDR = data;
    while(!(SPSR & (1<<SPIF)));  // waiting for 8 clocks.
}
char SPI_read(void){
    while(!(SPSR & (1<<SPIF)));
    return SPDR;
}

void SPI_send_str(char * str){
    for (int i =0 ; str[i] != '\0'; i++){
        SPI_send(str[i]);
    }
}
void SPI_send_num(int num){
     char buffer[11];
    itoa(num, buffer, 10);
    SPI_send_str(buffer);
    
}