
#include"lcd.h"




/* LCD and GPIOB initialization Function */
void LCD_init(void) {
    SYSCTL_RCGCGPIO_R |= 0x01; /* Enable Clock to GPIOB and GPIOA */
    SYSCTL_RCGCGPIO_R |= 0x02; /* Enable Clock to GPIOB and GPIOA */
    GPIO_PORTA_DIR_R |= 0xE0;
    GPIO_PORTA_DEN_R |= 0xE0;
    GPIO_PORTB_DIR_R |= 0xFF;
    GPIO_PORTB_DEN_R |= 0xFF;
     
    
    delayMs(20);
    LCD_command(0x30);
    delayMs(5);
    LCD_command(0x30);
    delayUs(100);
    LCD_command(0x30);
    LCD_command(0x38);
    LCD_command(0x06);
    LCD_command(0x01);
    LCD_command(0x0F);
}
void LCD_command(unsigned char command){
    GPIO_PORTA_DATA_R =0;
    GPIO_PORTB_DATA_R = command;
    GPIO_PORTA_DATA_R = EN;
    delayUs(0);
    GPIO_PORTA_DATA_R = 0;
    if (command < 4)
        delayMs(2);         /* command 1 and 2 needs up to 1.64ms */
    else
        delayUs(40);

}
void delayMs(int n){
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++)
        {}  /* do nothing for 1 ms */
}
void delayUs(int n) {
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < 3; j++)
        {} }
}
void LCD_nibble_write(unsigned char data, unsigned char control)
{
    data &= 0xF0;
    control &= 0x0F;
    GPIO_PORTA_DATA_R = data | control;
    GPIO_PORTA_DATA_R = data | control | EN;
    delayUs(0);
    GPIO_PORTA_DATA_R = data;
    GPIO_PORTA_DATA_R = 0;

}




// DATA B
// Control A
void LCD_data(unsigned char data)
{
    GPIO_PORTA_DATA_R = RS;    /* RS = 1, R/W = 0 */
    GPIO_PORTB_DATA_R = data;
    GPIO_PORTA_DATA_R = EN | RS;   /* pulse E */
    delayUs(0);
    GPIO_PORTA_DATA_R = 0;
    delayUs(40);
}