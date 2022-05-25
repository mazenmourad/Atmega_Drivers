/*
 * File:   MKIT.c
 * Author: cyber
 *
 * Created on March 2, 2022, 3:59 PM
 */


#include <avr/io.h>
#include "MKIT.h"


void init_LEDs (void){
    DDRB |=(1 << LED1) | (1 << LED2) | (1 << LED3);
}

void LED_ON (int LED){
        PORTB |= (1<<LED);
   
}

void LED_OFF (int LED){
        PORTB &= ~ (1<<LED);
  
}

void LED_TOGGLE(int LED){
    PORTB ^= (1 << LED);
}
int  LED_CHECK (int LED){
    if (PORTB & (1 << LED)) {
            return 1;
        } else {
            return 0;
        }
}

void init_BTNs (void){
    DDRA &= ~ (1 << BTN0) |(1 << BTN1);
}
int IS_BTN_PRESSED (int BTN_NUM){
     if (PINA & (1 << BTN_NUM)) {
            return 1;
        } else {
            return 0;
        }
}
