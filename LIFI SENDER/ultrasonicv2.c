#include"ultrasonicv2.h"

uint32_t duration1 = 0;
uint32_t distance1 = 0;
uint32_t duration2 = 0;
uint32_t distance2 = 0;

uint32_t ultrasonic_1 ( void )
{
  DIO_WritePin(PORT_A, 3, LOW);
  delay_ms_timer0(10);
  DIO_WritePin(PORT_A,3,HIGH);
  delay_ms_timer0(10);
  DIO_WritePin(PORT_A, 3, LOW);
  
  duration1 = Timer3_Count_Ret();
  distance1 = (((float) duration1*(float)0.00340000))/2;
   return distance1;
}


//uint32_t ultrasonic_2 (void){
//    DIO_WritePin(PORT_A, 2, LOW);             //Trigger LOW
//    delay_ms_timer0(10);                           //10 micro-seconds delay
//    DIO_WritePin(PORT_A,2,HIGH);            //Trigger High
//    delay_ms_timer0(10);                           //10 micro-seconds delay
//    DIO_WritePin(PORT_A,2,HIGH);              //Trigger-Low
//    // Clearing Trigger finished
//
//    duration2 = Timer2_Count_Ret();                          //Return counts of trigger detected by timer2
//    distance2 = (((float)duration2*(float)0.00340000))/2;   //calculate the distance with the constant speed of sound
//
//    return  distance2;
//}
//
//
//
//
//
//uint32_t ultrasonic_2 ( void );