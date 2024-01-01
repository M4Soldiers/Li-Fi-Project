include"ldr.h"

void ldr_init(void)
{
  
  DIO_Init(PORT_F, 1, OUT);
  DIO_Init(PORT_D, 2, IN);
  
}

void ldr_test(void)
{
  uint32_t value = 0;
  DIO_ReadPin(PORT_D, 2, &value);
  
  if(value == LOW) // law magnetic tnwr, law HIGH -> law magnetic ttfy el led
  {
    DIO_WritePin(PORT_F,1, 1);
  }
  else 
  {
    DIO_WritePin(PORT_F,1, 0);
  }
  
}

void ldr_adc_test(void)
{
  
//   unsigned int adc_value;
//	
//    /* Enable Clock to ADC0 and GPIO pins*/
//    SYSCTL_RCGCGPIO_R |= (1<<4);   /* Enable Clock to GPIOE or PE3/AN0 */
//    SYSCTL_RCGCADC_R |= (1<<0);    /* AD0 clock enable*/
//    
//    /* initialize PE3 for AIN0 input  */
//    GPIO_PORTE_AFSEL_R |= (1<<3);       /* enable alternate function */
//    GPIO_PORTE_DEN_R &= ~(1<<3);        /* disable digital function */
//    GPIO_PORTE_AMSEL_R |= (1<<3);       /* enable analog function */
//   
//    /* initialize sample sequencer3 */
//    ADC0_ACTSS_R &= ~(1<<3);        /* disable SS3 during configuration */
//    ADC0_EMUX_R &= ~0xF000;    /* software trigger conversion */
//    ADC0_SSMUX3_R = 0;         /* get input from channel 0 */
//    ADC0_SSCTL3_R |= (1<<1)|(1<<2);        /* take one sample at a time, set flag at 1st sample */
//    ADC0_ACTSS_R |= (1<<3);         /* enable ADC0 sequencer 3 */
//    
//	  /*Iniitialize PF3 as a digital output pin */
//	  	 
//   SYSCTL_RCGCGPIO_R |= 0x20; // turn on bus clock for GPIOF
//   GPIO_PORTF_DATA_R |= 0x08; //set GREEN pin as a digital output pin
//   GPIO_PORTA_DEN_R      |= 0x08;  // Enable PF3 pin as a digital pin
  
  
}