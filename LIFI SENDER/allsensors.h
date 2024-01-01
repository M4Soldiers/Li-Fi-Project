#ifndef ALL_SENSORS
#define ALL_SENSORS
#include"timer.h"
#include"ultrasonic.h"
#include "uart.h"

void sensors_start(uint32_t ultrasonic_value);
void delay_sw(unsigned long counter);
void LDR_Delay(uint32_t us_delay);
void smoke_bluetooth(void);
void ultrasonic_bluetooth(void);
void magnetic_bluetooth(void);
void and_bluetooth(void);

#endif