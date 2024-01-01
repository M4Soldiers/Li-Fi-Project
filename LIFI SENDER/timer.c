//
// Created by George Welson on 23-Dec-23.
//
#include "timer.h"

//void Timer0_delay(uint32_t delay)
//{
//   SYSCTL_RCGCTIMER_R |= (1u<<0); /*enable clock Timer0 subtimer A in run mode */
//    TIMER0_CTL_R = 0x0; /* disable timer0 output */
//    TIMER0_CFG_R = 0x0;  /*select 32-bit configuration option */
//    TIMER0_TAMR_R = 0x01; /*select one shot mode */
//    TIMER0_TAPR_R = 0; /* TimerA prescaler value */
//    TIMER0_TAILR_R = (delay*(16000))-1; /* TimerA counter starting count down value (1 sec) */
//    TIMER0_ICR_R = 0x1;  /* TimerA timeout flag bit clears*/
//    TIMER0_CTL_R |= (1u<<0);  /* Enable TimerA module */
//    TIMER0_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */
//    NVIC_EN0_R |= (1u<<19);
//
//}


void Timer1_init_ultrasonic(void)
{
    SYSCTL_RCGCTIMER_R |= (1u<<1); /*enable clock Timer1 subtimer A in run mode */
    TIMER1_CTL_R = 0x0; /* disable timer1 output */
    TIMER1_CFG_R = 0x04;  /*select 16-bit configuration option */
    TIMER1_TAMR_R = 0x02; /*select periodic mode */
    TIMER0_TAPR_R = 0; /* TimerA prescaler value */
//    TIMER0_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */
//    NVIC_EN0_R |= (1u<<19);

}

void Timer1_delay_ultrasonic(uint32_t delay)
{
    TIMER1_TAILR_R = 16-1; /* TimerA counter starting count down value  */
    TIMER1_ICR_R = 0x1;  /* TimerA timeout flag bit clears*/
    TIMER1_CTL_R |= 0x01;  /* Enable TimerA module */

    for(int i=0; i<delay; i++)
    {
        while((TIMER1_RIS_R & 0x1)==0){};
        TIMER1_ICR_R = 0x1;
    }

}

void Timer0_init_ultrasonic(void)
{
    SYSCTL_RCGCTIMER_R |= 0x01; /*enable clock Timer0 subtimer A in run mode */
    SYSCTL_RCGCGPIO_R |= 2;
    GPIO_PORTB_DIR_R &= ~0x40;
    GPIO_PORTB_DEN_R |= 0x40;
    GPIO_PORTB_AFSEL_R |= 0x40;
    GPIO_PORTB_PCTL_R &= ~0x0F000000;
    GPIO_PORTB_PCTL_R |= 0x07000000;
    /* PB2 as a digital output signal to provide trigger signal */
    SYSCTL_RCGCGPIO_R |= 1;  /* enable clock to PORTA */
    GPIO_PORTA_DIR_R |= (1u <<4);/* set PB2 as a digial output pin */
    GPIO_PORTA_DEN_R |= (1u <<4);  /* make PB2 as digital pin */

    TIMER0_CTL_R &= ~1; /* disable timer0 output */
    TIMER0_CFG_R = 0x04;  /*select 16-bit configuration option */
    TIMER0_TAMR_R = 0x17; /*select periodic down counter mode of timer0 */

    TIMER0_CTL_R |= 0x0C;
    TIMER0_CTL_R |= (1<<0);  /* Enable Timer0A module */


}



void Timer2_init_ldr(uint32_t ms_delay)
{
    SYSCTL_RCGCTIMER_R |= (1u<<2); /*enable clock Timer2 in run mode */
    TIMER2_CTL_R = 0x0; /* disable timer0 output */
    TIMER2_CFG_R = 0x0;  /*select 32-bit configuration option */
    TIMER2_TAMR_R = 0x04; /*select one shot mode */
    TIMER2_TAPR_R = 0; /* TimerA prescaler value */
    TIMER2_TAILR_R = (ms_delay*(16000))-1; /* TimerA counter starting count down value (1 sec) */
    TIMER2_ICR_R = 0x1;  /* TimerA timeout flag bit clears*/
    TIMER2_CTL_R |= (1u<<0);  /* Enable TimerA module */
    TIMER2_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */

    NVIC_EN0_R |= (1u<<23);

}