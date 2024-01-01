#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include"timer0.h"
#include "magnetic.h"    

void OutSignal(uint32_t value);
uint32_t measureDistanceOnce(void);
void US_Timer0_init(void);
void delay_Microsecond(uint32_t time);
void UART1_init(void);
#endif