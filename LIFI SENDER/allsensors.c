#include "allsensors.h"

void delay_sw(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter*1000; i++);
}

void LDR_Delay(uint32_t us_delay)
{
    Timer2_init_ldr(us_delay);
    while((TIMER2_RIS_R & 0x1) == 0){};
  
  
}

void sensors_start(uint32_t ultrasonic_value)
{
  uint32_t magnet_value = 4;
  uint32_t smoke_value = 4;
       
  DIO_ReadPin(PORT_A, 5, &magnet_value);
  DIO_ReadPin(PORT_A, 2, &smoke_value);


        if(ultrasonic_value < 20 && magnet_value == LOW && smoke_value == LOW) //ULTRASONIC AND MAGNET AND SMOKE
        {
        ultrasonic_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(5000);
        DIO_WritePin(PORT_F,2, 0);
        /************************/
        magnet_value = 4;
        delay_sw(1000);
        magnetic_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(1000);
        DIO_WritePin(PORT_F,2, 0);
        /************************/
        smoke_value = 4;
        delay_sw(1000);
        smoke_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(3000);
        DIO_WritePin(PORT_F,2, 0);
        }
        else if(magnet_value == LOW && smoke_value == LOW) // MAGNET AND SMOKE
        {
        magnet_value = 4;        
        magnetic_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(1000);
        DIO_WritePin(PORT_F,2, 0);
        /***********************/
        smoke_value = 4;
        smoke_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(3000);
        DIO_WritePin(PORT_F,2, 0);
        }
        else  if(ultrasonic_value < 20 && smoke_value == LOW) //ULTRASONIC AND SMOKE
        {
        ultrasonic_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(5000);
        DIO_WritePin(PORT_F,2, 0);
        /************************/
        smoke_value = 4;
        delay_sw(1000);
        smoke_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(3000);
        DIO_WritePin(PORT_F,2, 0);
        }
        else  if(ultrasonic_value < 20 && magnet_value == LOW) //ULTRASONIC AND MAGNET
        {
        ultrasonic_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(5000);
        DIO_WritePin(PORT_F,2, 0);
        /************************/
        magnet_value = 4;
        delay_sw(1000);
        magnetic_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(1000);
        DIO_WritePin(PORT_F,2, 0);
        }
        else if(ultrasonic_value < 20) { //ULTRASONIC ONLY

        ultrasonic_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(5000);
        DIO_WritePin(PORT_F,2, 0);
        }

        else if (smoke_value == LOW) //SMOKE ONLY
        {
        smoke_value = 4;
        delay_sw(1000);
        smoke_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(3000);
        DIO_WritePin(PORT_F,2, 0);

        }
        else  if(magnet_value == LOW) //MAGNET ONLY 
        {
        magnet_value = 4;
        delay_sw(1000);
        magnetic_bluetooth();
        DIO_WritePin(PORT_F,2, 1);
        LDR_Delay(1000);
        DIO_WritePin(PORT_F,2, 0);

        }      
        else 
        {
        DIO_WritePin(PORT_F,2, 0);
        }

}

void and_bluetooth(void)
{
  Bluetooth_Write('A');
  Bluetooth_Write('N');
  Bluetooth_Write('D');
  Bluetooth_Write('\n');  
}
void smoke_bluetooth(void)
{
        Bluetooth_Write('S');
        Bluetooth_Write('M');
        Bluetooth_Write('O');
        Bluetooth_Write('K');
        Bluetooth_Write('E');
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
}
void ultrasonic_bluetooth(void)
{
 
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
}
void magnetic_bluetooth(void)
{
     Bluetooth_Write('M');
        Bluetooth_Write('A');
        Bluetooth_Write('G');
        Bluetooth_Write('N');
        Bluetooth_Write('E');
        Bluetooth_Write('T');
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
}