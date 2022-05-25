/*
 * File:   EXTERNAL_INT.c
 * Author: cyber
 *
 * Created on March 2, 2022, 5:47 PM
 */


#include <avr/io.h>
#include "EXTERNAL_INT.h"
#include <avr/interrupt.h>

void INT0_SELECT_MODE(char INT_mode){
    MCUCR &= 0xFC;
    MCUCR |= INT_mode & 0x03;
}
void INT1_SELECT_MODE(char INT_mode){
    MCUCR &= 0xF3;
    MCUCR |= INT_mode & 0x0C;
}
void INT2_SELECT_MODE(char EXINT2_mode){
    MCUCSR &= 0xBF;
    MCUCSR |= 0x40;
}

void INT0_ENABLE  (){
    GICR |= (1<<INT0);
}
void INT1_ENABLE  (){
        GICR |= (1<<INT1);

}
void INT2_ENABLE  (){
        GICR |= (1<<INT2);

}
void INT0_DISABLE (){
        GICR &= ~ (1<<INT0);

}
void INT1_DISABLE (){
        GICR &= ~ (1<<INT1);

}
void INT2_DISABLE (){
        GICR &= ~ (1<<INT2);

}
void ENABLE_GLOBAL_INTERRUPT(){
    sei();
}
void INT0_init (char INT_mode){
    INT0_SELECT_MODE(INT_mode);
    INT0_ENABLE();
    
}

void INT1_init (char INT_mode){
    INT1_SELECT_MODE(INT_mode);
    INT1_ENABLE();
}
void INT2_init (char EXINT2_mode){
   INT2_SELECT_MODE(EXINT2_mode);
   INT2_ENABLE();  
}


