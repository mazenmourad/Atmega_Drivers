/*
 * File:   ADC_Drive.c
 * Author: cyber
 *
 * Created on March 14, 2022, 7:15 PM
 */


#include <avr/io.h>
#include"ADC_Drive.h"

void ADC_selectRef(char Voltage_REF){
    switch (Voltage_REF){
        case AREF :
            ADMUX &= ~ (1<< REFS0) | (1<< REFS1) ;
            break ;
            case AVCC :
            ADMUX &= ~ (1<<REFS1);
            ADMUX |= (1<< REFS0) ;
            break ;
            case INTERNAL :
            ADMUX |= (1<< REFS0) | (1<< REFS1) ;
            break ;
    }
    
}
void ADC_selectCH(char CH_Num){
  ADMUX  &=  0xE0 ;
  ADMUX  |=  CH_Num;
  
}
void ADC_selectPRE(char PRE){
    ADCSRA &= 0xF8;
    ADCSRA |= PRE & 0x07;
}
void ADC_enable(){
    ADCSRA |= (1<< ADEN);
}
void ADC_SC(){
        ADCSRA |= (1<< ADSC);

} // Start Conversion

void ADC_INT_enable(){
    ADCSRA |= (1<< ADIE);
}  // Enable ADC Interrupt
void ADC_INT_disable(){
        ADCSRA &=  ~(1<< ADIE);
}
void ADC_wait(){
    // Booling of ADC //
    while (!(ADCSRA & (1<<ADIF)));
}

int ADC_read(){
    return ADCW ;
}

void Init_ADC (char CH_Num ,char Voltage_REF,char PRE,char Choose_Booling ){
    
   ADC_selectCH(CH_Num);
   ADC_selectRef(Voltage_REF);
   ADC_selectPRE(PRE);
    
    // Booling or Interrupt //
    
    Choose_Booling? ADC_INT_disable(): ADC_INT_enable();
     ADC_enable();
}