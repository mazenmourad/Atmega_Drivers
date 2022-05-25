/* 
 * File:   LCD_4bits_Mode.h
 * Author: cyber
 *
 * Created on March 14, 2022, 5:34 PM
 */

#ifndef LCD_4BITS_MODE_H
#define	LCD_4BITS_MODE_H

#define LCD_4bits_DATA        PORTD
#define LCD_4bits_DATA_DIR    DDRD
#define LCD_4bits_CONTROL     PORTD
#define LCD_4bits_CONTROL_DIR DDRD


#define EN  2
#define RW  1
#define RS  0


void init_4bits_LCD();
void LCD_4bits_write(char data);
void LCD_4bits_cmd(char cmd);
void LCD_4bits_EN();
void LCD_4bits_CLEAR();
void LCD_4bits_str(char *str);
void LCD_4bits_NUM(int num);


#endif	/* LCD_4BITS_MODE_H */

