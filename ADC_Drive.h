/* 
 * File:   ADC_Drive.h
 * Author: cyber
 *
 * Created on March 14, 2022, 7:14 PM
 */

#ifndef ADC_DRIVE_H
#define	ADC_DRIVE_H

#define AREF        0
#define AVCC        1
#define INTERNAL    3  // 2.56V

#define ADC_CH0     0
#define ADC_CH1     1
#define ADC_CH2     2
#define ADC_CH3     3
#define ADC_CH4     4
#define ADC_CH5     5
#define ADC_CH6     6
#define ADC_CH7     7
#define ADC_CH0_CH1 16

#define  ADC_Pre_2       1
#define  ADC_Pre_4       2
#define  ADC_Pre_8       3
#define  ADC_Pre_16      4
#define  ADC_Pre_32      5
#define  ADC_Pre_64      6
#define  ADC_Pre_128     7

#define  ADC_Booling      1
#define  ADC_Non_Booling  0

// ADMUX
void ADC_selectRef(char Voltage_REF);
void ADC_selectCH(char CH_Num);

//ADCSA
void ADC_selectPRE(char PRE);
void ADC_enable();
void ADC_SC(); // Start Conversion
void ADC_INT_enable();  // Enable ADC Interrupt
void ADC_INT_disable();
void ADC_wait();
int ADC_read();

void Init_ADC (char CH_Num ,char Voltage_REF,char PRE,char Choose_Booling );



#endif	/* ADC_DRIVE_H */

