#include"uart.h"
void Delay_UART(uint32_t  counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter; i++);
}

void Bluetooth_Write(uint8_t  data)  
{
    while((UART1_FR_R & (1<<5)) != 0); /* wait until Tx buffer not full */
    UART1_DR_R = data;                  /* before giving it another byte */
}

void Bluetooth_Write_String(char *str)
{
  while(*str)
	{
		Bluetooth_Write(*(str++));
	}
}

//void UARTInit(uint32_t uartNumber,uint8_t RXE,uint8_t TXE,uint32_t busclk,uint32_t baudrate,uint8_t FifoEN, uint32_t WidthLength)
void UARTInit(uint32_t uartNumber,uint16_t RXE,uint16_t TXE,uint16_t Idivisor,uint16_t Fdivisor, uint16_t FifoEN,  uint32_t WidthLength)
{
  if ((uartNumber <= 7))
    {
        //SET_BIT(SYSCTL_RCGCUART_R, uartNumber);
      
        SYSCTL_RCGCUART_R |= (1<<uartNumber);
        SYSCTL_GPIO_INIT(uartNumber);
        Delay_UART(1);
        
        UARTDisable(uartNumber);
      
        //INT_FRAC_SET(uartNumber,busclk,baudrate);
        
        UARTBaudIntDivSet(uartNumber, Idivisor);
        UARTBaudFracDivSet(uartNumber, Fdivisor);
        UartCC(uartNumber);
        
        if(FifoEN)
          {
            UARTFIFOEnable(uartNumber);
          }
        
        UARTWordWidthSet(uartNumber, WidthLength);
        
        UARTEnable(uartNumber);
        if(RXE)
          {
             UARTReceiveEnable(uartNumber);
          }
        if(TXE)
          {
             UARTTransmitEnable(uartNumber);
          }
        
        GPIO_DEN(uartNumber, RXE, TXE);
        GPIO_Alternate(uartNumber,RXE,TXE);
       
        GPIO_PORTB_AMSEL_R = 0; /*..*/
        GPIO_PORT_CONTROL(uartNumber,RXE,TXE);
        
    }
  else 
  {
  }
}
void UartCC (uint32_t uartNumber)
{
  switch(uartNumber)
  {
    
  case 0: 
  UART0_CC_R=0;
  break;
  
  case 1:
    UART1_CC_R=0;
    break;
    
  case 2:
   UART2_CC_R=0;
   break;
   
  case 3:
  UART3_CC_R=0;
  break;
  
  case 4:
   UART4_CC_R=0;
   break;
   
  case 5:
   UART5_CC_R=0;
   break;
   
  case 6:
  UART6_CC_R=0;
  break;
     
  case 7: 
    UART7_CC_R=0;
    break;
  default:
    
    break;
   
  }
}

void UARTEnable(uint32_t uartNumber){
  //UART0_CTL_R |= UART_ENABLE;
  switch(uartNumber)
  {
    
  case 0: 
  UART0_CTL_R |= UART_ENABLE;
  break;
  
  case 1:
    UART1_CTL_R |= UART_ENABLE;
    break;
    
  case 2:
   UART2_CTL_R |= UART_ENABLE;
   break;
   
  case 3:
  UART3_CTL_R |= UART_ENABLE;
  break;
  
  case 4:
   UART4_CTL_R |= UART_ENABLE;
   break;
   
  case 5:
   UART5_CTL_R |= UART_ENABLE;
   break;
   
  case 6:
   UART6_CTL_R |= UART_ENABLE;
   break;
   
  case 7: 
    UART7_CTL_R |= UART_ENABLE;
    break;
  default:
    
    break;
   
  }
  
  
}

void UARTDisable(uint32_t uartNumber){
  

  switch(uartNumber)
  {
    
  case 0: 
    UART0_CTL_R = 0;
    break;
  case 1:
   UART1_CTL_R = 0;
   
   break;
  case 2:
   UART2_CTL_R =0;
   break;
  case 3:
   UART3_CTL_R =0;
   break;
  case 4:
  UART4_CTL_R =0;
  break;
  case 5:
   UART5_CTL_R =0;
   break;
  case 6:
   UART6_CTL_R =0;
   break;
  case 7: 
    UART7_CTL_R =0;
    break;
  default:
    
    break;
   
  }
}

void UARTTransmitEnable(uint32_t uartNumber){
   switch(uartNumber)
  {
    
  case 0: 
   
   UART0_CTL_R |=UART_TXE;
   break;
  case 1:
    
    UART1_CTL_R |= UART_TXE;
    break;
  case 2:
   
    UART2_CTL_R |=UART_TXE;
    break;
  case 3:
    
    UART3_CTL_R |=UART_TXE;
    break;
  case 4:
    
    UART4_CTL_R |= UART_TXE;
    break;
  case 5:
    
    UART5_CTL_R |= UART_TXE;
    break;
  case 6:
   UART6_CTL_R |= UART_TXE;
    break;
  case 7: 
    UART7_CTL_R |= UART_TXE;
    break;
  default:
    
    break;
  
    
  }




}
void UARTTransmitDisable(uint32_t uartNumber){
  
   switch(uartNumber)
  {
    
  case 0: 
   
   UART0_CTL_R &= ~(UART_TXE);
   break;
  case 1:
    UART1_CTL_R &= ~(UART_TXE);
    break;
  case 2:
    UART2_CTL_R &= ~(UART_TXE);
    break;
  case 3:
    UART3_CTL_R &= ~(UART_TXE);
    break;
  case 4:
    UART4_CTL_R &= ~(UART_TXE);
    break;
  case 5:
    UART5_CTL_R &= ~(UART_TXE);
    break;
  case 6:
    UART6_CTL_R &= ~(UART_TXE);
    break;
  case 7: 
    UART7_CTL_R &= ~(UART_TXE);
    break;
  default:
    
    break;
  
    
  }
}

void UARTReceiveEnable(uint32_t uartNumber){
  
  switch(uartNumber)
  {
    
  case 0: 
   
   UART0_CTL_R |=UART_RXE;
   break;
  case 1:
    UART1_CTL_R |=UART_RXE;
    break;
  case 2:
    UART2_CTL_R |=UART_RXE;
    break;
  case 3:
    UART3_CTL_R |=UART_RXE;
    break;
  case 4:
    UART4_CTL_R |=UART_RXE;
    break;
  case 5:
    UART5_CTL_R |=UART_RXE;
    break;
  case 6:
    UART6_CTL_R |=UART_RXE;
    break;
  case 7: 
    UART7_CTL_R |=UART_RXE;
    break;
  default:
    
    break;
  
    
  }
  
}
void UARTReceiveDisable(uint32_t uartNumber){
  
  switch(uartNumber)
  {
    
  case 0: 
   
   UART0_CTL_R &= ~(UART_RXE);
   break;
  case 1:
   UART1_CTL_R &= ~(UART_RXE);
   break;
  case 2:
    UART2_CTL_R &= ~(UART_RXE);
    break;
  case 3:
    UART3_CTL_R &= ~(UART_RXE);
    break;
  case 4:
    UART4_CTL_R &= ~(UART_RXE);
    break;
  case 5:
    UART5_CTL_R &= ~(UART_RXE);
    break;
  case 6:
    UART6_CTL_R &= ~(UART_RXE);
    break;
  case 7: 
   
    UART7_CTL_R &= ~(UART_RXE);
    break;
  default:
    
    break;
  
    
  }



}



void SYSCTL_GPIO_INIT(uint32_t uartNumber){
  switch(uartNumber)
  {
    
  case 0: 
   //SET_BIT(SYSCTL_RCGCGPIO_R, 0); //UART0-PORT A 
   SYSCTL_RCGCGPIO_R |= 1<<0;
   break;
  case 1:
    //SET_BIT(SYSCTL_RCGCGPIO_R, 1); //UART1-PORT B
    SYSCTL_RCGCGPIO_R |= 1<<1;
    break;
  case 2:
   // SET_BIT(SYSCTL_RCGCGPIO_R, 3); //UART2 -PORT D
    SYSCTL_RCGCGPIO_R |= 1<<3;
    break;
  case 3:
    //SET_BIT(SYSCTL_RCGCGPIO_R, 2); //UART3 - PORT C 
    SYSCTL_RCGCGPIO_R |= 1<<2;
    break;
  case 4:
   // SET_BIT(SYSCTL_RCGCGPIO_R, 2); //UART4 - PORT C 
    SYSCTL_RCGCGPIO_R |= 1<<2;
    break;
  case 5: 
    //SET_BIT(SYSCTL_RCGCGPIO_R, 4); //UART5 - PORT E
    SYSCTL_RCGCGPIO_R |= 1<<4;
    break;
  case 6:
   // SET_BIT(SYSCTL_RCGCGPIO_R, 2);  //UART6 - PORT D
    SYSCTL_RCGCGPIO_R |= 1<<2;
    break;
  case 7: 
    //SET_BIT(SYSCTL_RCGCGPIO_R, 4); //UART7 - PORT E
    SYSCTL_RCGCGPIO_R |= 1<<4;
    break;
  default:
    
    break;
   
  }
}

void GPIO_DEN(uint32_t uartNumber,uint16_t RXE,uint16_t TXE){
  uint16_t value;
  if(RXE && TXE) value =0x3;
  else if (RXE) value= 0x1;
  else if(TXE) value= 0x2;
  switch(uartNumber)
  {
    
  case 0: 
   GPIO_PORTA_DEN_R|=value;    //UART0-PORTA    A0-A1 
    break;
  case 1:
    GPIO_PORTB_DEN_R |=value;  //UART1-PORTB    B0-B1
     break;
  case 2:
    value= value << 6;
    GPIO_PORTD_DEN_R |=value;  //UART2 -PORTD    D6-D7
     break;
  case 3:
    value= value << 6;
    GPIO_PORTC_DEN_R |=value;   //UART3 - PORTC  C6-C7
     break;
  case 4:
    value= value << 4;
    GPIO_PORTC_DEN_R |=value;   //UART4 - PORTC  C4-C5
     break;
  case 5:
   value= value << 4;
   GPIO_PORTE_DEN_R|=value;     //UART5 - PORTE  E4-E5
     break;
  case 6:
    value= value << 4;
    GPIO_PORTD_DEN_R |=value;    //UART6 - PORTD   D4-D5
     break;
  case 7: 
   GPIO_PORTE_DEN_R |=value;    //UART7 - PORTE   E0-E1
     break;
  default:
    
    break;
   
  }
  
}
void GPIO_Alternate(uint32_t uartNumber,uint16_t RXE,uint16_t TXE){
  uint16_t value;
  if(RXE && TXE) value =0x3;
  else if (RXE) value= 0x1;
  else if(TXE) value= 0x2;
  switch(uartNumber)
  {
    
  case 0: 
   GPIO_PORTA_AFSEL_R |=value;    //UART0-PORTA    A0-A1 
    break;
  case 1:
    GPIO_PORTB_AFSEL_R |=value;  //UART1-PORTB    B0-B1
     break;
  case 2:
    value= value << 6;
    GPIO_PORTD_AFSEL_R |=value;  //UART2 -PORTD    D6-D7
     break;
  case 3:
    value= value << 6;
    GPIO_PORTD_AFSEL_R |=value;   //UART3 - PORTC  C6-C7
     break;
  case 4:
    value= value << 4;
    GPIO_PORTC_AFSEL_R |=value;   //UART4 - PORTC  C4-C5
     break;
  case 5:
   value= value << 4;
    GPIO_PORTE_AFSEL_R |=value;     //UART5 - PORTE  E4-E5
     break;
  case 6:
    value= value << 4;
    GPIO_PORTD_AFSEL_R |=value;    //UART6 - PORTD   D4-D5
     break;
  case 7: 
    GPIO_PORTE_AFSEL_R |=value;    //UART7 - PORTE   E0-E1
     break;
  default:
    
    break;
   
  }
  
}

void GPIO_PORT_CONTROL(uint32_t uartNumber,uint16_t RXE,uint16_t TXE){

  switch(uartNumber)
  {
    
   case 0:  //UART0-PORTA    A0-A1 
    
     if(RXE && TXE) GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00)  +  0x00000011;
     else if (RXE) GPIO_PORTA_PCTL_R =  (GPIO_PORTA_PCTL_R & 0xFFFFFFF0)  +  0x00000001;
     else if(TXE)   GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF0F)  +  0x00000010; 
     break;
     
  case 1: //UART1-PORTB    B0-B1
     if(RXE && TXE) GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0xFFFFFF00)  +  0x00000011;
     else if (RXE) GPIO_PORTB_PCTL_R =  (GPIO_PORTB_PCTL_R & 0xFFFFFFF0)  +  0x00000001;
     else if(TXE)   GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0xFFFFFF0F)  +  0x00000010; 
     break;
     
  case 2: //UART2 -PORTD    D6-D7
    if(RXE && TXE) GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0x00FFFFFF)  +   0x11000000;
     else if (RXE) GPIO_PORTD_PCTL_R =  (GPIO_PORTD_PCTL_R & 0xF0FFFFFFF) +  0x01000000;
     else if(TXE)   GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0x0FFFFFFF)  +  0x10000000; 
     break;
      
  case 3: //UART3 - PORTC  C6-C7
     if(RXE && TXE) GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0x00FFFFFF)  +   0x11000000;
     else if (RXE) GPIO_PORTC_PCTL_R =  (GPIO_PORTC_PCTL_R & 0xF0FFFFFFF) +  0x01000000;
     else if(TXE)   GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0x0FFFFFFF)  +  0x10000000;
     break;
      
  case 4: //UART4 - PORTC  C4-C5
   if(RXE && TXE) GPIO_PORTC_PCTL_R =    (GPIO_PORTC_PCTL_R & 0xFF00FFFF)  +   0x00110000;
     else if (RXE) GPIO_PORTC_PCTL_R =   (GPIO_PORTC_PCTL_R & 0xFFF0FFFFF) +  0x00010000;
     else if(TXE)   GPIO_PORTC_PCTL_R =  (GPIO_PORTC_PCTL_R & 0xFF0FFFFF)  +  0x00100000; 
     break;
      
  case 5: //UART5 - PORTE  E4-E5
   if(RXE && TXE) GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & 0xFF00FFFF)  +   0x00110000;
     else if (RXE) GPIO_PORTE_PCTL_R =  (GPIO_PORTE_PCTL_R & 0xFFF0FFFFF) +  0x00010000;
     else if(TXE)   GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & 0xFF0FFFFF)  +  0x00100000;
     break;
      
  case 6: //UART6 - PORTD   D4-D5
     if(RXE && TXE) GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0xFF00FFFF)  +   0x00110000;
     else if (RXE) GPIO_PORTD_PCTL_R =  (GPIO_PORTD_PCTL_R & 0xFFF0FFFFF) +  0x00010000;
     else if(TXE)   GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0xFF0FFFFF)  +  0x00100000;
     break;
  case 7: //UART7 - PORTE   E0-E1
    if(RXE && TXE) GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & 0xFFFFFF00)  +  0x00000011;
     else if (RXE) GPIO_PORTE_PCTL_R =  (GPIO_PORTE_PCTL_R & 0xFFFFFFF0)  +  0x00000001;
     else if(TXE)   GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & 0xFFFFFF0F)  +  0x00000010; 
     break;
  default:
    
    break;
   
  }
  
}




void INT_FRAC_SET(uint32_t uartNumber,uint32_t busclk, uint32_t baudrate){
  f64_t DIVISOR  = busclk/(16 * baudrate);
  uint16_t INT_DIVISOR = busclk/(16 * baudrate);
  uint16_t  FRAC_DIVISOR = ((DIVISOR - INT_DIVISOR) * 64.0);
  
  UARTBaudIntDivSet(uartNumber, INT_DIVISOR);
  UARTBaudFracDivSet(uartNumber, FRAC_DIVISOR);
}


void UARTBaudIntDivSet(uint32_t uartNumber, uint16_t Idivisor){
   
   switch(uartNumber)
  {
    
  case 0: 
   UART0_IBRD_R = Idivisor;
   break;
  case 1:
    UART1_IBRD_R = Idivisor;
    break;
  case 2:
    UART2_IBRD_R = Idivisor;
    break;
  case 3:
    UART3_IBRD_R = Idivisor;
    break;
  case 4:
    UART4_IBRD_R = Idivisor;
    break;
  case 5:
   UART5_IBRD_R = Idivisor;
   break;
  case 6:
    UART6_IBRD_R = Idivisor;
    break;
  case 7: 
    UART7_IBRD_R = Idivisor;
    break;
  default:
    
    break;
   
  }
}
uint16_t UARTBaudIntDivGet(uint32_t uartNumber){
  uint16_t divisor;
    switch(uartNumber)
  {
    
  case 0: 
   divisor = UART0_IBRD_R ;
   break;
  case 1:
    divisor = UART1_IBRD_R ;
    break;
  case 2:
    divisor = UART2_IBRD_R ;
    break;
  case 3:
    divisor = UART3_IBRD_R ;
    break;
  case 4:
    divisor = UART4_IBRD_R ;
    break;
  case 5:
   divisor = UART5_IBRD_R ;
   break;
  case 6:
    divisor = UART6_IBRD_R ;
    break;
  case 7: 
   divisor =  UART7_IBRD_R;
   break;
  default:
    
    break;
   
  }
  
 
  
  return divisor;
}


void UARTBaudFracDivSet(uint32_t uartNumber, uint16_t Fdivisor){

  switch(uartNumber)
  {
    
  case 0: 
   UART0_FBRD_R = Fdivisor;
   break;
  case 1:
    UART1_FBRD_R = Fdivisor;
    break;
  case 2:
    UART2_FBRD_R = Fdivisor;
    break;
  case 3:
    UART3_FBRD_R = Fdivisor;
    break;
  case 4:
    UART4_FBRD_R = Fdivisor;
    break;
  case 5:
   UART5_FBRD_R = Fdivisor;
   break;
  case 6:
    UART6_FBRD_R = Fdivisor;
    break;
  case 7: 
    UART7_FBRD_R = Fdivisor;
    break;
  default:
    
    break;
   
  }


}



uint16_t UARTBaudFracDivGet(uint32_t uartNumber){

   uint16_t divisor;
 switch(uartNumber)
  {
    
  case 0: 
   divisor = UART0_FBRD_R ;
   break;
  case 1:
    divisor = UART1_FBRD_R ;
    break;
  case 2:
    divisor = UART2_FBRD_R ;
    break;
  case 3:
    divisor = UART3_FBRD_R ;
    break;
  case 4:
    divisor = UART4_FBRD_R ;
    break;
  case 5:
   divisor = UART5_FBRD_R ;
   break;
  case 6:
    divisor = UART6_FBRD_R ;
    break;
  case 7: 
   divisor =  UART7_FBRD_R;
   break;
  default:
    
    break;
   
  }
  
  
  
  return divisor;


}


void UARTWordWidthSet(uint32_t uartNumber, uint16_t width){
  
  switch(uartNumber) 
  {
    
  case 0: 
   UART0_LCRH_R |= (width << 5);
   break;
  case 1:
    UART1_LCRH_R |= (width << 5);
    break;
  case 2:
    UART2_LCRH_R |= (width << 5);
    break;
  case 3:
    UART3_LCRH_R |= (width << 5);
    break;
  case 4:
    UART4_LCRH_R |= (width << 5);
    break;
  case 5:
   UART5_LCRH_R |= (width << 5);
   break;
  case 6:
    UART6_LCRH_R |= (width << 5);
    break;
  case 7: 
    UART7_LCRH_R |= (width << 5);
    break;
  default:
    
    break;
   
  }

}



uint32_t UARTWordWidthGet(uint32_t uartNumber){
  uint16_t width;
  switch(uartNumber)
  {
    
  case 0: 
   width=  (UART0_LCRH_R & (0x3 << 5) >> 5);
   break;
  case 1:
   width=  (UART1_LCRH_R & (0x3 << 5) >> 5);
   break;
  case 2:
   width=  (UART2_LCRH_R & (0x3 << 5) >> 5);
   break;
  case 3:
   width=  (UART3_LCRH_R & (0x3 << 5) >> 5);
   break;
  case 4:
    width= (UART4_LCRH_R & (0x3 << 5) >> 5);
    break;
  case 5:
   width=  (UART5_LCRH_R & (0x3 << 5) >> 5);
   break;
  case 6:
    width= (UART6_LCRH_R & (0x3 << 5) >> 5);
    break;
  case 7: 
    width= (UART7_LCRH_R & (0x3 << 5) >> 5);
    break;
  default:
    
    break;
   
  }
  return width;
}


void UARTFIFOEnable(uint32_t uartNumber){
  switch(uartNumber)
  {
    
  case 0: 
   //SET_BIT(UART0_LCRH_R, UART_FEN);
   UART0_LCRH_R |=UART_FEN;
   break;
  case 1:
   // SET_BIT(UART1_LCRH_R, UART_FEN);
    UART1_LCRH_R |=UART_FEN;
    break;
  case 2:
    //SET_BIT(UART2_LCRH_R, UART_FEN);
    UART2_LCRH_R |=UART_FEN;
    break;
  case 3:
    //SET_BIT(UART3_LCRH_R, UART_FEN);
    UART3_LCRH_R |=UART_FEN;
    break;
  case 4:
    //SET_BIT(UART4_LCRH_R, UART_FEN);
    UART4_LCRH_R |=UART_FEN;
    break;
  case 5:
    //SET_BIT(UART5_LCRH_R, UART_FEN);
    UART5_LCRH_R |=UART_FEN;
    break;
  case 6:
    //SET_BIT(UART6_LCRH_R, UART_FEN);
    UART6_LCRH_R |=UART_FEN;
    break;
  case 7: 
    //SET_BIT(UART7_LCRH_R, UART_FEN);
    UART7_LCRH_R |=UART_FEN;
    break;
  default:
    
    break;
  
    
  }

}



void UARTFIFODisable(uint32_t uartNumber){
   switch(uartNumber)
  {
    
  case 0: 
   CLEAR_BIT(UART0_LCRH_R, UART_FEN);
   break;
  case 1:
    CLEAR_BIT(UART1_LCRH_R, UART_FEN);
    break;
  case 2:
    CLEAR_BIT(UART2_LCRH_R, UART_FEN);
    break;
  case 3:
    CLEAR_BIT(UART3_LCRH_R, UART_FEN);
    break;
  case 4:
    CLEAR_BIT(UART4_LCRH_R, UART_FEN);
    break;
  case 5:
    CLEAR_BIT(UART5_LCRH_R, UART_FEN);
    break;
  case 6:
    CLEAR_BIT(UART6_LCRH_R, UART_FEN);
    break;
  case 7: 
    CLEAR_BIT(UART7_LCRH_R, UART_FEN);
    break;
  default:
    
    break;
  
    
  }
}








void UARTWriteByte(uint32_t uartNumber, uint16_t data){
  
  switch(uartNumber)
  {
    
  case 0: 
    UART0_DR_R = data;
    break;
  case 1:
    UART1_DR_R = data;
    break;
  case 2:
    UART2_DR_R = data;
    break;
  case 3:
    UART3_DR_R = data;
    break;
  case 4:
    UART4_DR_R = data;
    break;
  case 5:
    UART5_DR_R = data;
    break;
  case 6:
    UART6_DR_R = data;
    break;
  case 7: 
    UART7_DR_R = data;
    break;
  default:
    
    break;
  
    
  }
  
}

void UARTReadByte(uint32_t uartNumber, uint16_t data){
  
 
  switch(uartNumber)
  {
    
  case 0: 
    data = UART0_DR_R ;
    break;
  case 1:
    data = UART1_DR_R ;
    break;
  case 2:
   data =  UART2_DR_R ;
   break;
  case 3:
   data =  UART3_DR_R;
   break;
  case 4:
   data =  UART4_DR_R;
   break;
  case 5:
   data =  UART5_DR_R;
   break;
  case 6:
    data = UART6_DR_R;
    break;
  case 7: 
    data = UART7_DR_R;
    break;
  default:
    
    break;
   
  }
 
}










//bool UARTReceiveErrorCleared(uint32_t uartNumber, uint32_t error);
//void UARTClearReceiveError(uint32_t uartNumber, uint32_t error);
//bool UARTFlagCheck(uint32_t uartNumber, uint32_t flag);
uint8_t UARTIrDALPDivGet(uint32_t uartNumber);
void UARTLineControlSet(uint32_t uartNumber, uint32_t lineControl);




void UARTClearToSendEnable(uint32_t uartNumber);
void UARTClearToSendDisable(uint32_t uartNumber);
void UARTReqToSendEnable(uint32_t uartNumber);
void UARTReqToSendDisable(uint32_t uartNumber);
void UARTReqToSendSet(uint32_t uartNumber);
void UARTReqToSendClear(uint32_t uartNumber);

void UARTLoopBackEnable(uint32_t uartNumber);
void UARTLoopBackDisable(uint32_t uartNumber);
void UARTHighSpeedEnable(uint32_t uartNumber);
void UARTHighSpeedDisable(uint32_t uartNumber);
void UARTEndOfTxEnable(uint32_t uartNumber);
void UARTEndOfTxDisable(uint32_t uartNumber);
void UARTSmartEnable(uint32_t uartNumber);
void UARTSmartDisable(uint32_t uartNumber);
void UARTSIRLowPwrEnable(uint32_t uartNumber);
void UARTSIRLowPwrEDisable(uint32_t uartNumber);
void UARTSIREnable(uint32_t uartNumber);
void UARTSIRDisable(uint32_t uartNumber);

void UARTTxIntFIFOLvlSet(uint32_t uartNumber);
uint32_t UARTTxIntFIFOLvlGet(uint32_t uartNumber);
void UARTRxIntFIFOLvlSet(uint32_t uartNumber, uint32_t IFL);
uint32_t UARTRxIntFIFOLvlGet(uint32_t uartNumber);
void UARTInterruptEnable(uint32_t uartNumber, uint32_t interrupt);
void UARTInterruptDisable(uint32_t uartNumber, uint32_t interrupt);
//bool UARTRawInterruptGet(uint32_t uartNumber, uint32_t interrupt);
//bool UARTMaskedInterruptGet(uint32_t uartNumber, uint32_t interrupt);
void UARTInterruptClear(uint32_t uartNumber, uint32_t interrupt);
void UARTDMASet(uint32_t uartNumber, uint32_t param);
//void UART9BitAdrSet(uint32_t uartNumber, uint8_t addr, bool enable);
uint8_t UART9BitAdrGet(uint32_t uartNumber);
void UART9BitAdrMask(uint32_t uartNumber, uint8_t mask);

void UARTPeriPropSet(uint32_t uartNumber, uint32_t prop);
void UARTClkConfig(uint32_t uartNumber, uint8_t clock);

