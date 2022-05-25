/*
 * File:   LCD_4bits_Mode.c
 * Author: cyber
 *
 * Created on March 14, 2022, 5:34 PM
 */


#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "LCD_4bits_Mode.h"

void init_4bits_LCD(){
    LCD_4bits_DATA_DIR = 0xF0;
    LCD_4bits_CONTROL_DIR |= (1 << EN) | (1 << RW) | (1 << RS);
    LCD_4bits_CONTROL &= ~ (1<< RW);
    _delay_ms(50);
   LCD_4bits_CLEAR(); // CLEAR
   LCD_4bits_cmd(0x02); //FUNCTION        *****LCD DATASHEET CMDS 
   LCD_4bits_cmd(0x0C); // DISPALY ON  CURSOR OFF 
   LCD_4bits_cmd(0x06); // Entry MODE 

    _delay_ms(100);
}
void LCD_4bits_write(char data){
     LCD_4bits_CONTROL |=  (1<<RS);
    LCD_4bits_DATA = (LCD_4bits_DATA & 0x0F)|(data & 0xF0) ;
    LCD_4bits_EN();
   LCD_4bits_DATA = (LCD_4bits_DATA & 0x0F)|(data << 4);
    LCD_4bits_EN();   
}
void LCD_4bits_cmd(char cmd){
    LCD_4bits_CONTROL &= ~  (1<<RS);
    LCD_4bits_DATA = (LCD_4bits_DATA & 0x0F)|(cmd & 0xF0) ;
    LCD_4bits_EN();
    LCD_4bits_DATA = (LCD_4bits_DATA & 0x0F)|(cmd << 4);
    LCD_4bits_EN();   
}
void LCD_4bits_EN(){
    LCD_4bits_CONTROL |= (1<< EN);
    _delay_ms(10);
    LCD_4bits_CONTROL &= ~ (1<< EN);
}
void LCD_4bits_CLEAR(){
    LCD_4bits_cmd(0x01);
}
void LCD_4bits_str(char *str){
      for(int i = 0 ; str[i]!='\0'; i++)
      {
        LCD_4bits_write(str[i]);
}
}
void LCD_4bits_NUM(int num){
    char BUFFER [11];
    itoa(num ,BUFFER , 10 );
    LCD_4bits_str(BUFFER);
    
}




