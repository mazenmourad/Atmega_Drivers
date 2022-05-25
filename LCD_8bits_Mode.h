/* 
 * File:   LCD_8bits_Mode.h
 * Author: cyber
 *
 * Created on March 14, 2022, 4:09 PM
 */

#ifndef LCD_8BITS_MODE_H
#define	LCD_8BITS_MODE_H

#define LCD_8bits_DATA        PORTD
#define LCD_8bits_DATA_DIR    DDRD
#define LCD_8bits_CONTROL     PORTC
#define LCD_8bits_CONTROL_DIR DDRC


#define EN  2
#define RW  1
#define RS  0


void init_8bits_LCD();
void LCD_8bits_write(char data);
void LCD_8bits_cmd(char cmd);
void LCD_8bits_EN();
void LCD_8bits_CLEAR();
void LCD_8bits_str(char *str);
void LCD_8bits_NUM(int num);









#endif	/* LCD_8BITS_MODE_H */

