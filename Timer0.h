/* 
 * File:   Timer0.h
 * Author: cyber
 *
 * Created on March 16, 2022, 6:29 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

#define TimerOFF         0
#define NoPrescalar      1
#define Timer0_Pre_8     2
#define Timer0_Pre_64    3
#define Timer0_Pre_256   4
#define Timer0_Pre_1024  5
#define External_Falling 6
#define External_Rising  7


#define Normal      0x00    // Bec,the two bits are far from each othe *** 00000000//
#define PWM         0x40    // 01000000//
#define CTC         0x08    // 00001000//
#define FPWM        0x48    //010001000//

#define Timer0_OVI  0x01
#define Timer0_OCI  0x02


#define OC0_PWM_ClearUpSetDown   0x02
#define OC0_PWM_SetUpClearDown   0x03

#define OC0_FPWM_ClearSet        0x02
#define OC0_FPWM_SetClear        0x03

void Timer0_OFF();
void Timer0_selectCLK(char Timer0_clock_pre);
void Timer0_selectMode(char Timer0_Mode);
void Timer0_OC0_FPWM(char mode);
void Timer0_OC0_PWM(char mode);
// Interrupt Enable
void Timer0_enableINT(char Timer0_INT);
void Timer0_disableINT(char Timer0_INT);

// DutyCycle
void Timer0_setDutyCyle(char percentage);

// Setting Compare Value 
void Timer0_setComp(char value);

// Full Initiation 

void Init_Timer0 (char Timer0_Mode,char Timer0_clock_pre,char Timer0_INT ) ; 





#endif	/* TIMER0_H */

