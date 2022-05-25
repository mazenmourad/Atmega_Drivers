/* 
 * File:   MKIT.h
 * Author: cyber
 *
 * Created on March 1, 2022, 6:44 PM
 */

#ifndef MKIT_H
#define	MKIT_H

#define LED1    0
#define LED2    1
#define LED3    2

#define BTN0    0
#define BTN1    1

void init_LEDs (void);
void LED_ON (int LED);
void LED_OFF (int LED);
void LED_TOGGLE(int LED);
int  LED_CHECK (int LED);

void init_BTNs (void);
int IS_BTN_PRESSED (int BTN_NUM);

#endif	/* MKIT_H */

