#include "application.h"

void Start_stop(void)
{
  
     /* configure PORTF4, 0 for falling edge trigger interrupt */
    GPIO_PORTF_IS_R  &= ~(1<<4)|~(1<<0);        /* make bit 4, 0 edge sensitive */
    GPIO_PORTF_IBE_R &=~(1<<4)|~(1<<0);         /* trigger is controlled by IEV */
    GPIO_PORTF_IEV_R &= ~(1<<4)|~(1<<0);        /* falling edge trigger */
    GPIO_PORTF_ICR_R |= (1<<4)|(1<<0);          /* clear any prior interrupt */
    GPIO_PORTF_IM_R  |= (1<<4)|(1<<0);          /* unmask interrupt */
     NVIC_PRI30_R = 3<<5;
    NVIC_EN0_R |= (1<<30);
   
}


void APP_INIT()
{
  
    US_Timer0_init();
    UART1_init();
    UARTInit(1,1,1,104,11,0, 3);
    smoke_sensor_init();  
    magnetic_sensor_init();

    DIO_Init(PORT_F,0,IN);
    DIO_Init(PORT_F,4,IN);   
    Start_stop();
  
}

void Delay(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter*1000; i++);
}


uint32_t time = 0; /*stores pulse on time */
uint32_t distance=0; /* stores measured distance value */


void APP_START()
{
    time = measureDistanceOnce();
    distance = (time* 10625)/10000000;
    sensors_start(distance); 
    Delay(100);

}