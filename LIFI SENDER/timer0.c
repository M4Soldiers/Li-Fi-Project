#include "timer0.h"

#define ECHO (1U << 6) //PB6


void timer1_init(void) //this is used for 1 sec delay
{
  
    SYSCTL_RCGCTIMER_R |= (1u<<1); /*enable clock Timer1 subtimer A in run mode */
    TIMER1_CTL_R = 0x0; /* disable timer1 output */
    TIMER1_CFG_R = 0x04;  /*select 16-bit configuration option */
    TIMER1_TAMR_R = 0x02; /*select periodic down counter mode of timer1 */
    TIMER1_TAPR_R = 250-1; /* TimerA prescaler value */
    TIMER1_TAILR_R = 64000-1; /* TimerA counter starting count down value  */
    TIMER1_ICR_R = 0x1;  /* TimerA timeout flag bit clears*/
    TIMER1_CTL_R |= (1u<<0);  /* Enable TimerA module */
  TIMER1_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */
  NVIC_EN0_R |= (1u<<21);
  	
}



void timer0_init(void)
{
  
   SYSCTL_RCGCTIMER_R |= (1u<<0); /*enable clock Timer0 subtimer A in run mode */
   SYSCTL_RCGCGPIO_R |= (1u <<1);
   GPIO_PORTB_DIR_R &= ~ECHO;
   GPIO_PORTB_DEN_R |=ECHO;
   GPIO_PORTB_AFSEL_R |= ECHO;
   GPIO_PORTB_PCTL_R &= ~0x0F000000;
    GPIO_PORTB_PCTL_R |= 0x07000000;
   
   TIMER0_CTL_R &= ~1; /* disable timer0 output */
    TIMER0_CFG_R = 0x04;  /*select 16-bit configuration option */
    TIMER0_TAMR_R = 0x17; /*select periodic down counter mode of timer0 */
    //TIMER0_TAPR_R = 250-1; /* TimerA prescaler value */
    //TIMER0_TAILR_R = 64000-1; /* TimerA counter starting count down value  */
    //TIMER0_ICR_R = 0x1;  /* TimerA timeout flag bit clears*/
   TIMER0_CTL_R |= 0x0C;
    TIMER0_CTL_R |= (1u<<0);  /* Enable TimerA module */
  //TIMER1_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */
  //NVIC_EN0_R |= (1u<<21);
  	
}

void delay_ms_timer1(uint32_t time)
{
  int i;
    SYSCTL_RCGCTIMER_R |= (1u<<1); /*enable clock Timer1 subtimer A in run mode */
    TIMER1_CTL_R = 0x0; /* disable timer1 output */
    TIMER1_CFG_R = 0x04;  /*select 16-bit configuration option */
    TIMER1_TAMR_R = 0x02; /*select periodic down counter mode of timer1 */
    //TIMER1_TAPR_R = 250-1; /* TimerA prescaler value */
    TIMER1_TAILR_R = 16-1; /* TimerA counter starting count down value  */
    TIMER1_ICR_R = 0x1;  /* TimerA timeout flag bit clears*/
    TIMER1_CTL_R |= 0x01;  /* Enable TimerA module */
 
    for(i=0; i<time; i++)
    {
      while((TIMER1_RIS_R & 0x1)==0){}
      TIMER1_ICR_R = 0x1;
    }
    
    //TIMER1_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */
    //NVIC_EN0_R |= (1u<<21);
}

int i;
void delay_ms_timer0(uint32_t time)
{
 
    SYSCTL_RCGCTIMER_R |= (1u<<0); /*enable clock Timer1 subtimer A in run mode */
    TIMER0_CTL_R = 0x0; /* disable timer1 output */
    TIMER0_CFG_R = 0x04;  /*select 16-bit configuration option */
    TIMER0_TAMR_R = 0x02; /*select periodic down counter mode of timer1 */
    //TIMER1_TAPR_R = 250-1; /* TimerA prescaler value */
    TIMER0_TAILR_R = 16-1; /* TimerA counter starting count down value  */
    TIMER0_ICR_R = 0x1;  /* TimerA timeout flag bit clears*/
    TIMER0_CTL_R |= 0x01;  /* Enable TimerA module */
       
    for(i=0; i<(time/2); i++)
    {
      while((TIMER1_RIS_R & 0x1)==0){}
      TIMER1_ICR_R = 0x1;
    }
    
    //TIMER1_IMR_R |=(1u<<0); /*enables TimerA time-out  interrupt mask */
    //NVIC_EN0_R |= (1u<<21);
}

uint32_t Timer3_Count_Ret(void){

    SET_BIT(TIMER3_ICR_R,2);
    while(GET_BIT(TIMER3_RIS_R, 2)==0){}
    uint32_t duration1 =  TIMER3_TAR_R;


    SET_BIT(TIMER3_ICR_R,2);
    while(GET_BIT(TIMER3_RIS_R, 2)==0){}
    uint32_t duration2 =   TIMER3_TAR_R;


    return (duration2 - duration1) &0x00FFFFFF;

}

void Timer3_Count_Init(void)
{
  
   SET_BIT(SYSCTL_RCGCTIMER_R,3);    //Enable clock for timer3
    SET_BIT(SYSCTL_RCGCGPIO_R,1);        //enable GPIO clock

    CLEAR_BIT(GPIO_PORTB_DIR_R,2);        //enable GPIO clock
    SET_BIT(GPIO_PORTB_DEN_R,2);        //enable GPIO clock
    SET_BIT(GPIO_PORTB_AFSEL_R,2);        //enable GPIO clock

    GPIO_PORTB_PCTL_R &= ~0x00000F00;
    GPIO_PORTB_PCTL_R |= 0x00000700;
  

    CLEAR_BIT(TIMER3_CTL_R,0);      //Disable timer0 during configuration


    TIMER3_CFG_R=0x04;

    TIMER3_TAMR_R = 0x17;     //Select one shot timer& Down count selection
//    GPTAMATCHR3 = 0xFFFF;
  //  GPTMTAPMR3 = 0xFF;
    SET_BIT(TIMER3_CTL_R, 2);
    SET_BIT(TIMER3_CTL_R, 3);
    //clear 3
    SET_BIT(TIMER3_CTL_R,0);        //Enable timer3 to start counting
  	
}




//void timer1_enable(void)
//{
//  TIMER1_IMR_R |=(1<<0); /*enables TimerA time-out  interrupt mask */
//  NVIC_EN0_R |= (1u<<19);
//}