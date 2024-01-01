#ifndef DIO_H
#define DIO_H

#include "types.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"


void DIO_Init(uint32_t portNumber, uint32_t pinNumber, uint32_t direction);
void DIO_WritePort(uint32_t portNumber, uint32_t value);
void DIO_WritePin(uint32_t portNumber, uint32_t pinNumber, uint32_t pinValue);
void DIO_ReadPin(uint32_t portNumber, uint32_t pinNumber, uint32_t* value);
void DIO_ReadPort(uint32_t portNumber, uint32_t* value);
void DIO_toggle(uint32_t portNumber, uint32_t pinNumber);

#endif