//
// bitwise_operation.h
#ifndef BITWISE_OPERATION_H
#define BITWISE_OPERATION_H

//
#include"types.h"
#define SET_BIT(Register,Bit)   ((Register) |= (1<<(Bit)))
#define CLEAR_BIT(Register,Bit) ((Register) &= ~(1<<(Bit)))
#define TOGGLE_BIT(Register,Bit)  ((Register) ^= (1<<(Bit)))
#define GET_BIT(Register,Bit) (((Register) &= (1<<(Bit))))

#define IN 0
#define OUT 1
#define HIGH 1
#define LOW 0

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5
 
#define REG_MAX 0xFFFFFFFF
#define REG_MIN 0x00000000



#endif


//#define READ_BIT(byte,nbit)    ((byte>>nbit)&1)