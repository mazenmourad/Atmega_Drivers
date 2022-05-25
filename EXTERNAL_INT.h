/* 
 * File:   EXTERNAL_INT.h
 * Author: cyber
 *
 * Created on March 2, 2022, 5:35 PM
 */

#ifndef EXTERNAL_INT_H
#define	EXTERNAL_INT_H

#define INT_LOW_level     0//00
#define ANY_CHANGE        1//01
#define FALLING_EDGE      2//10
#define RISING_EDGE       3//11
#define EXINT2_FALLING `  0
#define EXINT2_RISING     1

 
void INT0_SELECT_MODE(char INT_mode);
void INT1_SELECT_MODE(char INT_mode);
void INT2_SELECT_MODE(char EXINT2_mode);
void INT0_ENABLE  ();
void INT1_ENABLE  ();
void INT2_ENABLE  ();
void INT0_DISABLE ();
void INT1_DISABLE ();
void INT2_DISABLE ();
void ENABLE_GLOBAL_INTERRUPT();
void INT0_init (char INT_mode);
void INT1_init (char INT_mode);
void INT2_init (char EXINT2_mode);









 

#endif	/* EXTERNAL_INT_H */

