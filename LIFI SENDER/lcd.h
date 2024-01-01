//
// Created by George Welson on 27-Nov-23.
//

#ifndef FSM_EMBEDDED_LCD_H
#define FSM_EMBEDDED_LCD_H
#include"tm4c123gh6pm.h"
#include"types.h"
#include"dio.h"

#define LCD_DATA GPIO_PORTB_DATA_BITS_R
#define LCD_CTRL GPIO_PORTA_DATA_BITS_R
#define RS 0x20
#define RW 0x40
#define EN 0x80
void delayMs(int n);
void delayUs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);

#endif //FSM_EMBEDDED_LCD_H
