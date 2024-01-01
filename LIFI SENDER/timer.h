//
// Created by George Welson on 23-Dec-23.
//

#ifndef PROJECT_TIMER_H
#define PROJECT_TIMER_H

#include"types.h"
#include"tm4c123gh6pm.h"
//void Timer_delay(uint32_t delay);
//void timer0_init(void);
void Timer0_init_ultrasonic(void);
void Timer1_delay_ultrasonic(uint32_t delay);
void Timer1_init_ultrasonic(void);
void Timer2_init_ldr(uint32_t ms_delay);

#endif //PROJECT_TIMER_H