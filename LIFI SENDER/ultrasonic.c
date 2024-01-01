#include"ultrasonic.h"
#include<math.h>
//#include<stdio.h>

const double _16MHz_1clock = 0.0625; // Value of 1clock cycle in mikroseconds
 
#define ECHO (1U << 6) //PB6
#define TRIGGER (1U << 4) //PA4(OUTPUT)
#define BLUE_LED (1U << 2) //PF2 onboard Blue LED
#define GREEN_LED (1U << 3) //PF3 onboard Green LED
#define RED_LED (1U << 1) //PF1 onboard Red LED


uint32_t measureDistanceOnce(void) { 
		int lastEdge,thisEdge;
GPIO_PORTA_DATA_R &= ~(1u << 4);  // Clear bit 4
delay_Microsecond(10);
GPIO_PORTA_DATA_R |= (1u << 4);   // Set bit 4
delay_Microsecond(10);
GPIO_PORTA_DATA_R &= ~(1u << 4);  // Clear bit 4
// Capture first edge (rising edge)
while (1) {
    TIMER0_ICR_R = 4;  // Clear Timer0A Capture flag
    //delay_Microsecond(200);
    while ((TIMER0_RIS_R & 4) == 0);  // Wait until captured
    if (GPIO_PORTB_DATA_R & (1u << 6)) {
        lastEdge = TIMER0_TAR_R;

        // Capture second edge (falling edge)
        TIMER0_ICR_R = 4;  // Clear Timer0A Capture flag
        while ((TIMER0_RIS_R & 4) == 0);  // Wait until captured
        thisEdge = TIMER0_TAR_R;

        return (thisEdge - lastEdge);
    }
}

}





void OutSignal(uint32_t value)
{
GPIO_PORTF_DATA_R &= ~(RED_LED | GREEN_LED | BLUE_LED);
	
  if(value < 20) { 
    
        Bluetooth_Write('U');
        Bluetooth_Write('L');
        Bluetooth_Write('T');
        Bluetooth_Write('R');
        Bluetooth_Write('A');
        Bluetooth_Write('S');
        Bluetooth_Write('O');
        Bluetooth_Write('N');
        Bluetooth_Write('I');
        Bluetooth_Write('C');
        Bluetooth_Write(' ');
        Bluetooth_Write('D');
        Bluetooth_Write('E');
        Bluetooth_Write('T');
        Bluetooth_Write('E');
        Bluetooth_Write('C');
        Bluetooth_Write('T');
        Bluetooth_Write('E');
        Bluetooth_Write('D');
        Bluetooth_Write('\n');
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(5000);
          DIO_WritePin(PORT_F,2, 0);
	}
 
	else {
		GPIO_PORTF_DATA_R &= ~(RED_LED | GREEN_LED | BLUE_LED);
	}
}

void delay_Microsecond(uint32_t time)
{
  int i;
    SYSCTL_RCGCTIMER_R |= 2; /*enable clock Timer1 subtimer A in run mode */
    TIMER1_CTL_R = 0; /* disable timer1 output */
    TIMER1_CFG_R = 0x04;  /*select 16-bit configuration option */
    TIMER1_TAMR_R = 0x02; /*select periodic down counter mode of timer1 */
    //TIMER1_TAPR_R = 250-1; /* TimerA prescaler value */
    TIMER1_TAILR_R = 16-1; /* TimerA counter starting count down value  */
    TIMER1_ICR_R = 0x1;  /* TimerA timeout flag bit clears*/
    TIMER1_CTL_R |= 0x01;  /* Enable TimerA module */
 
    for(i=0; i<time; i++)
    {
      while((TIMER1_RIS_R & 0x1)==0){};
      TIMER1_ICR_R = 0x1;
    }
    
    //TIMER1_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */
    //NVIC_EN0_R |= (1u<<21);
}

void US_Timer0_init(void)
{
   SYSCTL_RCGCTIMER_R |= 1; /*enable clock Timer0 subtimer A in run mode */
   SYSCTL_RCGCGPIO_R |= 2;
   GPIO_PORTB_DIR_R &= ~0x40;
   GPIO_PORTB_DEN_R |= 0x40;
   GPIO_PORTB_AFSEL_R |= 0x40;
   GPIO_PORTB_PCTL_R &= ~0x0F000000;
    GPIO_PORTB_PCTL_R |= 0x07000000;
   /* PB2 as a digital output signal to provide trigger signal */
     SYSCTL_RCGCGPIO_R |= 1;  /* enable clock to PORTA */
     GPIO_PORTA_DIR_R |= (1u <<4);
      GPIO_PORTA_DEN_R |= (1u <<4);  
      
   TIMER0_CTL_R &= ~1; /* disable timer0 output */
    TIMER0_CFG_R = 4;  /*select 16-bit configuration option */
    TIMER0_TAMR_R = 0x17; /*select periodic down counter mode of timer0 */
  // TIMER0_ICR_R = 0x04;
   TIMER0_CTL_R |= 0x0C;
    TIMER0_CTL_R |= (1u<<0);  /* Enable Timer0A module */
   //TIMER0_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */
    //NVIC_EN0_R |= (1u<<19);
  	
}


void UART1_init(void)
{
	  SYSCTL_RCGCUART_R |= 0x20;  /* enable clock to UART1 */
    SYSCTL_RCGCGPIO_R |= 0x10;  /* enable clock to PORTE for PE4/Rx and RE5/Tx */
    /* UART0 initialization */
    UART5_CTL_R = 0;         /* UART5 module disbable */
    UART5_IBRD_R = 104;      /* for 9600 baud rate, integer = 104 */
    UART5_FBRD_R = 11;       /* for 9600 baud rate, fractional = 11*/
    UART5_CC_R = 0;          /*select system clock*/
    UART5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */

    /* UART5 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function */
    GPIO_PORTE_DEN_R = 0x30;      /* set PB0 and PB1 as digital */
    GPIO_PORTE_AFSEL_R |= 0x30;    /* Use PB0,PB1 alternate function */
    GPIO_PORTE_AMSEL_R |= 0;    /* Turn off analg function*/
    GPIO_PORTE_PCTL_R |= 0x00110000;     /* configure PB0 and PB1 for UART */
}
