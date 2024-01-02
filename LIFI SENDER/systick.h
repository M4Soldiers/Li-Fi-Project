//
// Created by George Welson on 02-Dec-23.
//

#ifndef LAB_7_SYSTICK_H
#define LAB_7_SYSTICK_H
#include"types.h"
#include"dio.h"

void SysTickDisable (void);
void SysTickEnable (void);
uint32_t SysTickPeriodGet (void);
void SysTickPeriodSet (uint32_t ui32Period);
void SysTickPeriodSet_ms (uint32_t ui32Period);
uint32_t SysTickValueGet (void);
uint8_t SysTick_Is_Time_out(void);
#endif //LAB_7_SYSTICK_H
