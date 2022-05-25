/*
 * File:   Timer0.c
 * Author: cyber
 *
 * Created on March 16, 2022, 6:47 PM
 */


#include <avr/io.h>
#include "Timer0.h"


void Timer0_OFF(){
    TCCR0 &= 0xF8 ; // 11111000  *** Zeros in 3 bits of PRE
}

void Timer0_selectCLK(char Timer0_clock_pre){
    Timer0_OFF();
    TCCR0 |= Timer0_clock_pre;
}
void Timer0_selectMode(char Timer0_Mode){
    TCCR0 &= ~ (1<<WGM00) | (1<<WGM01);
    TCCR0 |= Timer0_Mode ;
}
// Interrupt Enable
void Timer0_enableINT(char Timer0_INT){
    
    TIMSK |= Timer0_INT;
}
void Timer0_disableINT(char Timer0_INT){
 
        TIMSK &= ~ Timer0_INT;

}
void Init_Timer0 (char Timer0_Mode,char Timer0_clock_pre, char Timer0_INT ) {
    Timer0_selectMode(Timer0_Mode);
    Timer0_enableINT(Timer0_INT);
    Timer0_selectCLK(Timer0_clock_pre);
}

void Timer0_setComp(char value){
    OCR0 |= value ;
}

void Timer0_setDutyCyle(char percentage){
    OCR0 = percentage*255/100.0;
}
void Timer0_OC0_FPWM(char mode){
    DDRB |= (1<<3);
    TCCR0 |= (mode<<COM00);
}
void Timer0_OC0_PWM(char mode){
    DDRB |= (1<<3);
    TCCR0 |= (mode<<COM00);
}

