#include"tm4c123gh6pm.h"
#include"bitwise_operation.h"
#include"types.h"

#include"application.h"
#include <stdio.h>
#define LED_RED (1u << 1) //0010
#define LED_BLUE (1u << 2) //0100
#define LED_GREEN (1u << 3) //1000

void TIMER1A_Handler()
{
  if(TIMER1_MIS_R & 0x1) 
       GPIO_PORTF_DATA_R  ^= LED_BLUE; /* toggle Blue LED*/
       TIMER1_ICR_R = 0x1;          /* Timer1A timeout flag bit clears*/
  
}

void TIMER0A_Handler()
{
  if(TIMER0_MIS_R & 0x1) 
       GPIO_PORTF_DATA_R  ^= LED_BLUE; /* toggle Blue LED*/
       TIMER0_ICR_R = 0x1;          /* Timer1A timeout flag bit clears*/
  
}

void TIMER2A_Handler()
{
  if(TIMER2_MIS_R & 0x1) 
       TIMER2_ICR_R = 0x1;          /* Timer1A timeout flag bit clears*/
  
}


volatile int systemState = 0;
void GPIOPortF_Handler(void)
{	
  if (GPIO_PORTF_MIS_R & 0x10) /* check if interrupt causes by PF4/SW1*/
    {   
      systemState = 0;
      GPIO_PORTF_ICR_R |= 0x10; /* clear the interrupt flag */
     } 
    else if (GPIO_PORTF_MIS_R & 0x01) /* check if interrupt causes by PF0/SW2 */
    {   
     systemState = 1;
     GPIO_PORTF_ICR_R |= 0x01; /* clear the interrupt flag */
    }
}


int main()
{

   APP_INIT();
    while(1){
      if(systemState == 1){
        APP_START();
      }
      else if (systemState == 0) 
      {
      }
 
  }
}