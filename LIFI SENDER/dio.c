#include "dio.h"

void DIO_Init(uint32_t portNumber, uint32_t pinNumber, uint32_t direction)
{
    if ((portNumber <= PORT_F))
    {
        SET_BIT(SYSCTL_RCGCGPIO_R, portNumber);
        while ((GET_BIT(SYSCTL_PRGPIO_R, portNumber)) == 0) {};
        switch (portNumber)
        {
            /******************** PORT A *******************/
        case PORT_A:
            if (direction == IN)
            {
                CLEAR_BIT(GPIO_PORTA_DIR_R, pinNumber);
//                SET_BIT(GPIO_PORTA_PUR_R, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(GPIO_PORTA_DIR_R, pinNumber);
            }
            GPIO_PORTA_DEN_R |= (1u<<pinNumber); //used to digital enable
            break;

            /******************** PORT B *******************/
        case PORT_B:
            if (direction == IN)
            {
                CLEAR_BIT(GPIO_PORTB_DIR_R, pinNumber);
               // SET_BIT(GPIO_PORTB_PDR_R, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(GPIO_PORTB_DIR_R, pinNumber);
            }
            GPIO_PORTB_DEN_R |= (1u<<pinNumber);; //used to digital enable
            break;

            /******************** PORT C *******************/
        case PORT_C:
            GPIO_PORTC_LOCK_R = 0x4C4F434B;// to unlock button
            GPIO_PORTC_CR_R = 0x1F;  // used with lock to unlock buttons

            if (direction == IN)
            {
                CLEAR_BIT(GPIO_PORTC_DIR_R, pinNumber);
                SET_BIT(GPIO_PORTC_PDR_R, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(GPIO_PORTC_DIR_R, pinNumber);
            }
            GPIO_PORTC_DEN_R |= (1u<<pinNumber); //used to digital enable
            break;


            /******************** PORT D *******************/
        case PORT_D:
            GPIO_PORTD_LOCK_R = 0x4C4F434B;// to unlock button
            GPIO_PORTD_CR_R = 0x1F;  // used with lock to unlock buttons

            if (direction == IN)
            {
                CLEAR_BIT(GPIO_PORTD_DIR_R, pinNumber);
                SET_BIT(GPIO_PORTD_PDR_R, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(GPIO_PORTD_DIR_R, pinNumber);
            }
            GPIO_PORTD_DEN_R |= (1u<<pinNumber); //used to digital enable
            break;

            /******************** PORT E *******************/
        case PORT_E:
         
            if (direction == IN)
            {
                CLEAR_BIT(GPIO_PORTE_DIR_R, pinNumber);
                //SET_BIT(GPIO_PORTE_PDR_R, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(GPIO_PORTE_DIR_R, pinNumber);
            }
            GPIO_PORTE_DEN_R |= (1u<<pinNumber); //used to digital enable
            break;

            /******************** PORT F *******************/
        case PORT_F:
            GPIO_PORTF_LOCK_R = 0x4C4F434B;// to unlock button
            GPIO_PORTF_CR_R = 0x1F;  // used with lock to unlock buttons

            if (direction == IN)
            {
                CLEAR_BIT(GPIO_PORTF_DIR_R, pinNumber);
                SET_BIT(GPIO_PORTF_PUR_R, pinNumber);

            }
            else if (direction == OUT)
            {
                SET_BIT(GPIO_PORTF_DIR_R, pinNumber);
            }
            GPIO_PORTF_DEN_R |= (1u<<pinNumber); //used to digital enable
            break;

        default:
            // do nothing
            break;
        }
    }
    else
    {
       //wrong portNumber
    }
}

void DIO_WritePort(uint32_t portNumber, uint32_t value) // This function is used to write in the whole port
{
    switch (portNumber) {

    case PORT_A:
        GPIO_PORTA_DATA_R = value; 
        break;

    case PORT_B:
        GPIO_PORTB_DATA_R = value; 
        break;

    case PORT_C:
        GPIO_PORTC_DATA_R = value; 
        break;

    case PORT_D:
        GPIO_PORTD_DATA_R = value; 
        break;
        
    case PORT_E:
        GPIO_PORTE_DATA_R = value; 
        break;
     /******************** PORT F *******************/
    case PORT_F:
        GPIO_PORTF_DATA_R = value; 
        break;

    default:
        // do nothing
        break;
    }
}


void DIO_WritePin(uint32_t portNumber, uint32_t pinNumber, uint32_t pinValue)
{
    switch (portNumber)
    {
        /******************** PORT A *******************/
    case PORT_A:
        if (pinValue == 1)
        {
            SET_BIT(GPIO_PORTA_DATA_R, pinNumber);
        }
        else if (pinValue == 0)
        {
            CLEAR_BIT(GPIO_PORTA_DATA_R, pinNumber);
        }
        break;
        /******************** PORT B *******************/
    case PORT_B:
        if (pinValue == 1)
        {
            SET_BIT(GPIO_PORTB_DATA_R, pinNumber);
        }
        else if (pinValue == 0)
        {
            CLEAR_BIT(GPIO_PORTB_DATA_R, pinNumber);
        }
        break;
        /******************** PORT C *******************/
    case PORT_C:
        if (pinValue == 1)
        {
            SET_BIT(GPIO_PORTC_DATA_R, pinNumber);
        }
        else if (pinValue == 0)
        {
            CLEAR_BIT(GPIO_PORTC_DATA_R, pinNumber);
        }
        break;
        /******************** PORT D *******************/
    case PORT_D:
        if (pinValue == 1)
        {
            SET_BIT(GPIO_PORTD_DATA_R, pinNumber);
        }
        else if (pinValue == 0)
        {
            CLEAR_BIT(GPIO_PORTD_DATA_R, pinNumber);
        }
        break;
        /******************** PORT E *******************/
    case PORT_E:
        if (pinValue == 1)
        {
            SET_BIT(GPIO_PORTE_DATA_R, pinNumber);
        }
        else if (pinValue == 0)
        {
            CLEAR_BIT(GPIO_PORTE_DATA_R, pinNumber);
        }
        break;
        /******************** PORT F *******************/
    case PORT_F:
        if (pinValue == 1)
        {
            SET_BIT(GPIO_PORTF_DATA_R, pinNumber);
        }
        else if (pinValue == 0)
        {
            CLEAR_BIT(GPIO_PORTF_DATA_R, pinNumber);
        }
    default:
        // do nothing
        break;
    }
 }

void DIO_ReadPin(uint32_t portNumber, uint32_t pinNumber, uint32_t* value)
{
    switch (portNumber) {
        /******************** PORT A *******************/
    case PORT_A: 
        *value = GET_BIT(GPIO_PORTA_DATA_R,pinNumber);
        break;
        /******************** PORT B *******************/
    case PORT_B: 
        *value = GET_BIT(GPIO_PORTB_DATA_R,pinNumber);
        break;
        /******************** PORT C *******************/
    case PORT_C: 
        *value = GET_BIT(GPIO_PORTC_DATA_R,pinNumber);
        break;
        /******************** PORT D *******************/
    case PORT_D: 
        *value = GET_BIT(GPIO_PORTD_DATA_R,pinNumber);
        break;
        /******************** PORT E *******************/
    case PORT_E: 
        *value = GET_BIT(GPIO_PORTE_DATA_R,pinNumber);
        break;
        /******************** PORT F *******************/
    case PORT_F: 
        *value = GET_BIT(GPIO_PORTF_DATA_R,pinNumber);
        break;
    
    default: 
       //do nothing
        break;
    
    }
}
  
void DIO_ReadPort(uint32_t portNumber, uint32_t* value)
{
    switch (portNumber) {
        /******************** PORT A *******************/
    case PORT_A:
        *value = GPIO_PORTA_DATA_R;
        break;
        /******************** PORT B *******************/
    case PORT_B:
        *value = GPIO_PORTB_DATA_R;
        break;
        /******************** PORT C *******************/
    case PORT_C:
        *value = GPIO_PORTC_DATA_R;
        break;
        /******************** PORT D *******************/
    case PORT_D:
        *value = GPIO_PORTD_DATA_R;
        break;
        /******************** PORT E *******************/
    case PORT_E:
        *value = GPIO_PORTE_DATA_R;
        break;
        /******************** PORT F *******************/
    case PORT_F:
        *value = GPIO_PORTF_DATA_R;
        break;

    default:
        //do nothing
        break;

    }


}

  
  void DIO_toggle(uint32_t portNumber, uint32_t pinNumber)
{
  
  switch (portNumber)
    {
        /******************** PORT A *******************/
    case PORT_A:
       
        TOGGLE_BIT(GPIO_PORTA_DATA_R, pinNumber); 
        break;
        /******************** PORT B *******************/
    case PORT_B:
        TOGGLE_BIT(GPIO_PORTB_DATA_R, pinNumber);
        break;
        /******************** PORT C *******************/
    case PORT_C:
       
        TOGGLE_BIT(GPIO_PORTC_DATA_R, pinNumber);
        break;
        /******************** PORT D *******************/
    case PORT_D:
       
        TOGGLE_BIT(GPIO_PORTD_DATA_R, pinNumber);
        break;
        /******************** PORT E *******************/
    case PORT_E:
        
        TOGGLE_BIT(GPIO_PORTE_DATA_R, pinNumber);      
        break;
        /******************** PORT F *******************/
    case PORT_F:
        
         TOGGLE_BIT(GPIO_PORTF_DATA_R, pinNumber);      

        break;
       
    default:
        // do nothing
        break;
    }
 }

  
  
  
  
  
