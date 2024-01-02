//
// Created by George Welson on 02-Dec-23.
//
#include"systick.h"

uint32_t TICKTIME = 1/(16000000);

void SysTickDisable (void){
    NVIC_ST_CTRL_R &= ~(0x01);
}

void SysTickEnable (void){
    NVIC_ST_CTRL_R |=0x5; //enable clock and let CLK_SRC = system clock
}

uint32_t SysTickPeriodGet (void){
    uint32_t ticks = NVIC_ST_RELOAD_R;
    ticks &= 0x00FFFFFF;
    return TICKTIME * ticks;

}
void SysTickPeriodSet (uint32_t ui32Period){
    uint32_t ticks = (ui32Period /TICKTIME)-1;
    ticks &= 0x00FFFFFF;
    NVIC_ST_RELOAD_R|=ticks;
}

void SysTickPeriodSet_ms (uint32_t ui32Period){
    uint32_t ticks = (ui32Period*(16000))-1;
    ticks &= 0x00FFFFFF;
    NVIC_ST_RELOAD_R|=ticks;
}

uint32_t SysTickValueGet (void){
    uint32_t time = NVIC_ST_CURRENT_R & 0x00FFFFFF;
    return time;
}
uint8_t SysTick_Is_Time_out(void){
    uint32_t count_flag = 0;
    uint32_t ticks = NVIC_ST_CTRL_R;
    count_flag = (ticks>>15)&& 0x00000001;
    if(count_flag == 0x0){
        return 0;
    } else
        return 1;
}