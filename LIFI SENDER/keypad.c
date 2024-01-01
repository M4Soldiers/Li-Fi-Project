#include"keypad.h"

uint8_t map[KEYPAD_SIZE][KEYPAD_SIZE]={
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'*','0','#','D'}
};

void KeyPad_Init (void) 
{
    DIO_Init(PORT_E, 0, OUT); //rows
    DIO_Init(PORT_E, 1, OUT); //rows
    DIO_Init(PORT_E, 2, OUT); //rows
    DIO_Init(PORT_E, 3, OUT); //rows

    GPIO_PORTE_ODR_R |= 0xF;

    DIO_Init(PORT_C, 4, IN);  //cols
    DIO_Init(PORT_C, 5, IN);  //cols
    DIO_Init(PORT_C, 6, IN);  //cols
    DIO_Init(PORT_C, 7, IN);  //cols
    
    
/* First for the initialization of the ports, configure Port E pins 3-0 to be used for rows 
and configured as output digital pin. These pins are also configured as open drain 
output, which means they are driven low actively but not driven high. Open drain 
output prevents port damage when two keys of the same column are pressed at 
the same time. If output pins are driven high and low and two keys of the same 
column are pressed, it will short the output low to output high of the adjacent pin 
and cause damages to the output pins. Then configure Port C pins 7-4 are 
configured as input digital pin with the internal pull-up resistors enabled. This will 
ensure that the input pins read 1 when no key is pressed 
*/ 
}


uint8_t KeyPad_Read (void)
{

    uint8_t any_btn_pressed = NOT_PRESSED;
    uint8_t col = 0;
    uint8_t row = 0;
    DIO_WritePort(PORT_E,0x00000000);
    uint32_t val = 0;
    DIO_ReadPort(PORT_C,&val);
    val = (val>>4);
    if(val == 0xF){
        return 'Z';
    }
    else if(val == 0xE){
      any_btn_pressed = PRESSED;
      col = 3;
      
    }
    else if(val == 0xD){
      any_btn_pressed = PRESSED;
      col = 2;
    }
    else if(val == 0xB){
      any_btn_pressed = PRESSED;
      col = 1;
    }
    else if(val == 0x7){
      any_btn_pressed = PRESSED;
      col = 0;
    }
    for(row=0;row<KEYPAD_SIZE;row++){
        DIO_WritePort(PORT_E,0xF);
        DIO_WritePin(PORT_E,row,LOW);
        DIO_ReadPort(PORT_C,&val);
        val = (val>>4);
        if(val != 0xF)
            return map[row][col];
            
    }

        any_btn_pressed = NOT_PRESSED;
        return 0;
}

/* The key scanning function is a non-blocking function, meaning the function returns 
regardless of whether there is a key pressed or not. The function first drives all rows 
low and check to see if any key pressed. If no key is pressed, a zero is returned. 
Otherwise the code will proceed to check one row at a time by driving only one row 
low at a time and read the columns. If one of the columns is active, it will find out 
which column it is. With the combination of the active row and active column, the 
code will find out the key that is pressed and using the lookup table keymap to return 
the ASCII key label and print it on the terminal. 
*/ 
