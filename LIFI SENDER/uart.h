#ifndef UART_H
#define UART_H

#include"types.h"
#include"tm4c123gh6pm.h"
#include"bitwise_operation.h"

//#define UART_OVERRUN_ERR( (uint32_t) 1 << 3 )
//#define UART_BREAK_ERR	( (uint32_t) 1 << 2 )
//#define UART_PARITY_ERR	( (uint32_t) 1 << 1 )
//#define UART_FRAMING_ERR( (uint32_t) 1 << 0 )
//#define UART_ERR_CLEAR	( (uint8_t) 0xFF )

/* UART Flag (FR) */
#define UART_TXFE ( (uint32_t) 1 << 7 )		// Transmit FIFO empty
#define UART_RXFF ( (uint32_t) 1 << 6 )		// Receive FIFO full
#define UART_TXFF ( (uint32_t) 1 << 5 )		// Transmit FIFO full
#define UART_RXFE ( (uint32_t) 1 << 4 )		// Receive FIFO empty
#define UART_BUSY ( (uint32_t) 1 << 3 )		// UART busy
#define UART_CTS  ( (uint32_t) 1 << 0 )		// Clear to send

/* UART Line Control (LCRH) */
#define UART_SPS  ( (uint32_t) 1 << 7 )		// Stick parity set
#define UART_FEN  ( (uint32_t) 1 << 4 )		// Enable FIFO 
#define UART_STP2 ( (uint32_t) 1 << 3 )		// Two stop bits select
#define UART_EPS  ( (uint32_t) 1 << 2 )		// Even parity select
#define UART_PEN  ( (uint32_t) 1 << 1 )		// Parity enable
#define UART_BRK  ( (uint32_t) 1 << 0 )		// Send break

#define UART_WLEN_5BIT ( (uint32_t) 0x0 ) 	// 5 bit word length
#define UART_WLEN_6BIT ( (uint32_t) 0x1 )      // 6 bit word length
#define UART_WLEN_7BIT ( (uint32_t) 0x2 )     // 7 bit word length
#define UART_WLEN_8BIT ( (uint32_t) 0x3 )    // 8 bit word length

/* UART Control (CTL) */
#define UART_CTSEN  ( (uint32_t) 1 << 15 )		// Enable Clear to send
#define UART_RTSEN  ( (uint32_t) 1 << 14 )		// Enable Request to Send 
#define UART_RTS    ( (uint32_t) 1 << 11 )		// Request to Send
#define UART_RXE    ( (uint32_t) 1 << 9 )		// Receive enable
#define UART_TXE    ( (uint32_t) 1 << 8 )		// Transmit enable
#define UART_LBE    ( (uint32_t) 1 << 7 )		// Loopback enable
#define UART_HSE    ( (uint32_t) 1 << 5 )		// High-speed enable
#define UART_EOT    ( (uint32_t) 1 << 4 )		// End of transmission
#define UART_SMART  ( (uint32_t) 1 << 3 )		// ISO 7816 smart card support
#define UART_SIRLP  ( (uint32_t) 1 << 2 )		// SIR low power mode
#define UART_SIREN  ( (uint32_t) 1 << 1 )		// SIR enable
#define UART_ENABLE ( (uint32_t) 1 << 0 )		// UART enable

/* UART FIFO Level Select (IFLS) */
#define UART_RX_7_8_FULL ( (uint32_t) 0x4 )		// Rx FIFO 7/8 full
#define UART_RX_3_4_FULL ( (uint32_t) 0x3 )		// Rx FIFO 3/4 full
#define UART_RX_1_2_FULL ( (uint32_t) 0x2 )		// Rx FIFO 1/2 full
#define UART_RX_1_4_FULL ( (uint32_t) 0x1 )		// Rx FIFO 1/4 full
#define UART_RX_1_8_FULL ( (uint32_t) 0x0 )		// Rx FIFO 1/8 full

#define UART_TX_7_8_EMPTY ( (uint32_t) 0x0 )		// Rx FIFO 7/8 full
#define UART_TX_3_4_EMPTY ( (uint32_t) 0x1 )		// Rx FIFO 3/4 full
#define UART_TX_1_2_EMPTY ( (uint32_t) 0x2 )		// Rx FIFO 1/2 full
#define UART_TX_1_4_EMPTY ( (uint32_t) 0x3 )		// Rx FIFO 1/4 full
#define UART_TX_1_8_EMPTY ( (uint32_t) 0x4 )		// Rx FIFO 1/8 full

/* UART Interrupts */
#define UART_9BIT   ( (uint32_t) 1 << 12 ) // 9-bit mode
#define UART_OE_INT ( (uint32_t) 1 << 10 ) // Overrun error interrupt
#define UART_BE_INT ( (uint32_t) 1 << 9 )  // Break error interrupt
#define UART_PE_INT ( (uint32_t) 1 << 8 )  // Parity error interrupt
#define UART_FE_INT ( (uint32_t) 1 << 7 )  // Frame error interrupt
#define UART_RT_INT ( (uint32_t) 1 << 6 )  // Receive time-out error interrupt
#define UART_TX_INT ( (uint32_t) 1 << 5 )  // Transmit interrupt
#define UART_RX_INT ( (uint32_t) 1 << 4 )  // Receive interrupt
//#define UART_CTS_INT( (uint32_t) 1 << 1 )  // Clear to send interrupt


#define UART_9BITEN  ( (uint32_t) 1 << 15 ) // 9-bit address enable




/* UART Peripheral Properties */
#define UART_9BIT_SUP ( (uint32_t) 1 << 1 ) // 9-bit support
#define UART_SMART_SUP ( (uint32_t) 1 << 0 ) // Smart card support



/* UART Clock Configuration */
#define UART_SYS_CLK ( (uint32_t) 0x0 ) // System clock
#define UART_PIOSC   ( (uint32_t) 0x5 ) // PIOSC



/***************************Clock Init Macros*****************************/
#define RCC_UART_CLK_ENABLE(uint32_t, n)      volatile unsigned long delay0;\
                                              SYSCTL->RCGCUART |= (0x01 << n);\
                                              delay0 = SYSCTL->RCGCUART;

/****************************************************************************
 *                                                                          *
 *                          Driver Exposed APIs     	                    	*
 *                                                                          *
 ****************************************************************************/ 


void Bluetooth_Write(uint8_t  data);
void Bluetooth_Write_String(char *str);
                                              
                                              
                                              
void UARTInit(uint32_t uartNumber,uint16_t RXE,uint16_t TXE,uint16_t Idivisor,uint16_t Fdivisor, uint16_t FifoEN,  uint32_t WidthLength);
void UARTEnable(uint32_t uartNumber);
void UARTDisable(uint32_t uartNumber);
void UARTTransmitEnable(uint32_t uartNumber);
void UARTTransmitDisable(uint32_t uartNumber);
void UARTReceiveEnable(uint32_t uartNumber);
void UARTReceiveDisable(uint32_t uartNumber);
void SYSCTL_GPIO_INIT(uint32_t uartNumber);
void INT_FRAC_SET(uint32_t uartNumber,uint32_t busclk, uint32_t baudrate); /*habdaya */
void UARTFIFOEnable(uint32_t uartNumber);
void UARTFIFODisable(uint32_t uartNumber);
void GPIO_Alternate(uint32_t uartNumber,uint16_t RXE,uint16_t TXE);
void GPIO_DEN(uint32_t uartNumber,uint16_t RXE,uint16_t TXE);
void UartCC (uint32_t uartNumber);
void GPIO_PORT_CONTROL(uint32_t uartNumber,uint16_t RXE,uint16_t TXE);
void Delay_UART(uint32_t  counter);
/*
 * @brief: Write a byte of data to the data register
 * @param: *UARTx: Base address of the UART module
 * @param: data: The byte of data to send
 * @return: None
 */
void UARTWriteByte(uint32_t uartNumber, uint16_t data);

/*
 * @brief: Read a byte of data from the data register
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTReadByte(uint32_t uartNumber,uint16_t data);

/*
 * @brief: Check for receive error
 * @param: *UARTx: Base address of the UART module
 * @param: error: The receive error to check
 * @return: Whether the specified error has occured
 */
//bool UARTReceiveErrorCheck(uint32_t uartNumber, uint32_t error);




/*
 * @brief: Set the integer baud rate dividor
 * @param: *UARTx: Base address of the UART module
 * @param: divisor: The divisor to set
 * @return: None
 */
void UARTBaudIntDivSet(uint32_t uartNumber, uint16_t Idivisor);






/*
 * @brief: Get the integer baud rate dividor
 * @param: *UARTx: Base address of the UART module
 * @return: The integer baud rate dividor
 */
uint16_t UARTBaudIntDivGet(uint32_t uartNumber);




/*
 * @brief: Set the fractional baud rate dividor
 * @param: *UARTx: Base address of the UART module
 * @param: divisor: The divisor to set
 * @return: None
 */
void UARTBaudFracDivSet(uint32_t uartNumber, uint16_t  Fdivisor);





/*
 * @brief: Get the fractional baud rate dividor
 * @param: *UARTx: Base address of the UART module
 * @return: The fractional baud rate dividor
 */
uint16_t UARTBaudFracDivGet(uint32_t uartNumber);



/*
 * @brief: Set the word width
 * @param: *UARTx: Base address of the UART module
 * @param: width: The word width to set
 * @return: None
 */
void UARTWordWidthSet(uint32_t uartNumber, uint16_t width);




/*
 * @brief: Get the word width
 * @param: *UARTx: Base address of the UART module
 * @return: Word width
 */
uint32_t UARTWordWidthGet(uint32_t uartNumber);



/*......................................................................................*/










/*
 * @brief: Check if the receive error has been cleared
 * @param: *UARTx: Base address of the UART module
 * @param: error: The receive error to check
 * @return: Whether the specified error has been cleared
 */
//bool UARTReceiveErrorCleared(uint32_t uartNumber, uint32_t error);





/*
 * @brief: Clear all receive errors
 * @param: *UARTx: Base address of the UART module
 * @param: error: The receive error to clear
 * @return: None
 */
void UARTClearReceiveError(uint32_t uartNumber, uint32_t error);




/*
 * @brief: Check the UART flags
 * @param: *UARTx: Base address of the UART module
 * @param: flag: The flag to check
 * @return: Whether the specified flag is set
 */
//bool UARTFlagCheck(uint32_t uartNumber, uint32_t flag);







/*
 * @brief: Set the IrDA low power dividor
 * @param: *UARTx: Base address of the UART module
 * @param: divisor: The divisor to set
 * @return: None
 */
void UARTIrDALPDivSet(uint32_t uartNumber, uint8_t divisor);




/*
 * @brief: Get the IrDA low power dividor
 * @param: *UARTx: Base address of the UART module
 * @return: The IrDA low power dividor
 */
uint8_t UARTIrDALPDivGet(uint32_t uartNumber);





/*
 * @brief: Set the line control parameters
 * @param: *UARTx: Base address of the UART module
 * @param: lineControl: The line control param to set
 * @return: None
 */
void UARTLineControlSet(uint32_t uartNumber, uint32_t lineControl);









/*
 * @brief: Enable clear to send
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTClearToSendEnable(uint32_t uartNumber);




/*
 * @brief: Disable clear to send
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTClearToSendDisable(uint32_t uartNumber);

/*
 * @brief: Enable request to send
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTReqToSendEnable(uint32_t uartNumber);




/*
 * @brief: Disable request to send
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTReqToSendDisable(uint32_t uartNumber);





/*
 * @brief: Enable request to send
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTReqToSendSet(uint32_t uartNumber);





/*
 * @brief: Disable request to send
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTReqToSendClear(uint32_t uartNumber);









/*
 * @brief: Enable loop back
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTLoopBackEnable(uint32_t uartNumber);




/*
 * @brief: Disable loop back
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTLoopBackDisable(uint32_t uartNumber);




/*
 * @brief: Enable high speed
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTHighSpeedEnable(uint32_t uartNumber);



/*
 * @brief: Disable high speed
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTHighSpeedDisable(uint32_t uartNumber);



/*
 * @brief: Enable EOT
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTEndOfTxEnable(uint32_t uartNumber);




/*
 * @brief: Disable EOT
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTEndOfTxDisable(uint32_t uartNumber);





/*
 * @brief: Enable smart card support
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTSmartEnable(uint32_t uartNumber);





/*
 * @brief: Disable smart card support
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTSmartDisable(uint32_t uartNumber);







/*
 * @brief: Enable SIR low power
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTSIRLowPwrEnable(uint32_t uartNumber);





/*
 * @brief: Disable SIR low power
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTSIRLowPwrEDisable(uint32_t uartNumber);





/*
 * @brief: Enable SIR
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTSIREnable(uint32_t uartNumber);





/*
 * @brief: Disable SIR
 * @param: *UARTx: Base address of the UART module
 * @return: None
 */
void UARTSIRDisable(uint32_t uartNumber);








/*
 * @brief: Set the Tx FIFO interrupt level
 * @param: *UARTx: Base address of the UART module
 * @param: IFL: The Tx FIFO interrupt level to set
 * @return: None
 */
void UARTTxIntFIFOLvlSet(uint32_t uartNumber);




/*
 * @brief: Get the Tx FIFO interrupt level
 * @param: *UARTx: Base address of the UART module
 * @return: Tx FIFO interrupt level
 */
uint32_t UARTTxIntFIFOLvlGet(uint32_t uartNumber);




/*
 * @brief: Set the Rx FIFO interrupt level
 * @param: *UARTx: Base address of the UART module
 * @param: IFL: The Tx FIFO interrupt level to set
 * @return: None
 */
void UARTRxIntFIFOLvlSet(uint32_t uartNumber, uint32_t IFL);



/*
 * @brief: Get the Rx FIFO interrupt level
 * @param: *UARTx: Base address of the UART module
 * @return: Tx FIFO interrupt level
 */
uint32_t UARTRxIntFIFOLvlGet(uint32_t uartNumber);




/*
 * @brief: Enable UART interrupts
 * @param: *UARTx: Base address of the UART module
 * @param: interrupt: Interrupt to enable
 * @return: None
 */
void UARTInterruptEnable(uint32_t uartNumber, uint32_t interrupt);






/*
 * @brief: Disable UART interrupts
 * @param: *UARTx: Base address of the UART module
 * @param: interrupt: Interrupt to disable
 * @return: None
 */
void UARTInterruptDisable(uint32_t uartNumber, uint32_t interrupt);






/*
 * @brief: Get UART raw interrupt status
 * @param: *UARTx: Base address of the UART module
 * @param: interrupt: Raw Interrupt status to check
 * @return: Whether the interrupt is set
 */
//bool UARTRawInterruptGet(uint32_t uartNumber, uint32_t interrupt);






/*
 * @brief: Get UART masked interrupt status
 * @param: *UARTx: Base address of the UART module
 * @param: interrupt: Masked Interrupt status to check
 * @return: Whether the nterrupt is set
 */
//bool UARTMaskedInterruptGet(uint32_t uartNumber, uint32_t interrupt);




/*
 * @brief: Clear UART interrupts
 * @param: *UARTx: Base address of the UART module
 * @param: interrupt: Interrupt to clear
 * @return: None
 */
void UARTInterruptClear(uint32_t uartNumber, uint32_t interrupt);






/*
 * @brief: Set DMA control
 * @param: *UARTx: Base address of the UART module
 * @param: param: DMA params to set
 * @return: None
 */
void UARTDMASet(uint32_t uartNumber, uint32_t param);





/*
 * @brief: Set 9-bit address
 * @param: *UARTx: Base address of the UART module
 * @param: addr: address to set
 * @param: enable: whether to enable 9-bit addr
 * @return: None
 */
//void UART9BitAdrSet(uint32_t uartNumber, uint8_t addr, bool enable);




/*
 * @brief: Get 9-bit address
 * @param: *UARTx: Base address of the UART module
 * @return: The 9-bit address
 */
uint8_t UART9BitAdrGet(uint32_t uartNumber);




/*
 * @brief: Mask 9-bit address
 * @param: *UARTx: Base address of the UART module
 * @param: mask: address mask
 * @return: None
 */
void UART9BitAdrMask(uint32_t uartNumber, uint8_t mask);






/*
 * @brief: Set peripheral properties
 * @param: *UARTx: Base address of the UART module
 * @param: prop: properties to set
 * @return: None
 */
void UARTPeriPropSet(uint32_t uartNumber, uint32_t prop);








/*
 * @brief: Config clock
 * @param: *UARTx: Base address of the UART module
 * @param: clock: clock to use
 * @return: None
 */
void UARTClkConfig(uint32_t uartNumber, uint8_t clock);












/*
 * @brief: Initialize UART
 * @param: *UARTx: Base address of the UART module
 * @param: tsm_buffer: pointer to data buffer
 * @return: None
 */
//void UARTTransmit(uint32_t uartNumber, uint8_t *tsm_buffer);

/*
 * @brief: Initialize UART
 * @param: *UARTx: Base address of the UART module
 * @param: rcv_buffer: receive buffer
 * @return: None
 */
//void UARTReceive(uint32_t uartNumber, uint8_t *rcv_buffer);

#endif