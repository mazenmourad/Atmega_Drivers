/*
 * File:   LCD_8bits_Mode.c
 * Author: cyber
 *
 * Created on March 14, 2022, 5:00 PM
 */


#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "LCD_8bits_Mode.h"

void init_8bits_LCD(){
    LCD_8bits_DATA_DIR = 0xFF;
    LCD_8bits_CONTROL_DIR |= (1 << EN) | (1 << RW) | (1 << RS);
    LCD_8bits_CONTROL &= ~ (1<< RW);
    _delay_ms(50);
   LCD_8bits_CLEAR(); // CLEAR
   LCD_8bits_cmd(0x38); //FUNCTION        *****LCD DATASHEET CMDS 
   LCD_8bits_cmd(0x0C); // DISPALY ON  CURSOR OFF 
   LCD_8bits_cmd(0x06); // Entry MODE 

    _delay_ms(100);
}
void LCD_8bits_write(char data){
     LCD_8bits_CONTROL |=  (1<<RS);
    LCD_8bits_DATA = data ;
    LCD_8bits_EN();
}
void LCD_8bits_cmd(char cmd){
    
    LCD_8bits_CONTROL &= ~ (1<<RS);
    LCD_8bits_DATA = cmd ;
    LCD_8bits_EN();
    
}
void LCD_8bits_EN(){
    LCD_8bits_CONTROL |= (1<< EN);
    _delay_ms(10);
    LCD_8bits_CONTROL &= ~ (1<< EN);
}
void LCD_8bits_CLEAR(){
    LCD_8bits_cmd(0x01);
}
void LCD_8bits_str(char *str){
      for(int i = 0 ; str[i]!='\0'; i++)
      {
        LCD_8bits_write(str[i]);
}
}
void LCD_8bits_NUM(int num){
    char BUFFER [11];
    itoa(num ,BUFFER , 10 );
    LCD_8bits_str(BUFFER);
    
}




