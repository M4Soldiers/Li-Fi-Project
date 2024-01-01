#include"smoke.h"

void smoke_sensor_init(void)
{
  DIO_Init(PORT_A, 2, IN);
 }

void delay_smoke(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter*1000; i++);
}

void smoke_sensor_test(void)
{
  uint32_t value_smoke = 4;
  DIO_ReadPin(PORT_D, 2, &value_smoke);
  
  if(value_smoke == LOW) // law magnetic tnwr, law HIGH -> law magnetic ttfy el led
  {
   DIO_WritePin(PORT_D,3, 1);
    //delay_smoke(300);
      //DIO_WritePin(PORT_F,2, 0);
    
  }
  else 
  {
    DIO_WritePin(PORT_F,1, 0);
  }
  
}