#include "magnetic.h"

void magnetic_sensor_init(void)
{  
  DIO_Init(PORT_F, 2,OUT);
   DIO_Init(PORT_A, 5, IN);
}
