#ifndef TIMER_0
#define TIMER_0
#include "dio.h"
void timer1_init(void);
void timer1_enable(void);
void delay_ms_timer1(uint32_t time);
void delay_ms_timer0(uint32_t time);
void timer0_init(void);

uint32_t Timer3_Count_Ret(void);
void Timer3_Count_Init(void);
//uint32_t Timer2_Count_Ret(void);
//void Timer2_Count_Init(void);
#endif

/*
Credits to alegich
*/