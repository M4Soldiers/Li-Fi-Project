#ifndef KEYPAD_H
#define KEYPAD_H
#include"types.h"
#include"bitwise_operation.h"
#include"dio.h"

#define PRESSED 1
#define NOT_PRESSED 0


#define KEYPAD_SIZE 4

void KeyPad_Init (void);
uint8_t KeyPad_Read (void);
#endif