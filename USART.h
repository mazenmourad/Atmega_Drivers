/* 
 * File:   USART.h
 * Author: cyber
 *
 * Created on March 19, 2022, 12:04 AM
 */

#ifndef USART_H
#define	USART_H



void init_UART(int BaudRate);
void UART_send(char data);
char UART_read(void);
void UART_send_str(char * str);
void UART_send_num(int num);





#endif	/* USART_H */

