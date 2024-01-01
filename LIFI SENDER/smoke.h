#ifndef SMOKE_H
#define SMOKE_H
#include"dio.h"

//PORT D PIN 2

void smoke_sensor_init(void);
void smoke_sensor_test(void);
void delay_smoke(unsigned long counter);
#endif