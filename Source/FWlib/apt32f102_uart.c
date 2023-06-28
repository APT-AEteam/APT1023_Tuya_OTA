/*
  ******************************************************************************
  * @file    apt32f102_lpt.c
  * @author  APT AE Team
  * @version V1.24
  * @date    2018/10/15
  ******************************************************************************
  *THIS SOFTWARE WHICH IS FOR ILLUSTRATIVE PURPOSES ONLY WHICH PROVIDES 
  *CUSTOMER WITH CODING INFORMATION REGARDING THEIR PRODUCTS.
  *APT CHIP SHALL NOT BE HELD RESPONSIBILITY ADN LIABILITY FOR ANY DIRECT, 
  *INDIRECT DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF 
  *SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION 
  *CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.AND APT CHIP RESERVES 
  *THE RIGHT TO MAKE CHANGES IN THE SOFTWARE WITHOUT NOTIFICATION
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "apt32f102_uart.h"


/* define --------------------------------------------------------------------*/
volatile U8_T RxDataFlag=0;
volatile U8_T TxDataFlag=0;
/* externs--------------------------------------------------------------------*/


/*************************************************************/
//UART RESET,CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_DeInit(void)
{
    UART0->DATA = UART_RESET_VALUE;
    UART0->SR   = UART_RESET_VALUE;
    UART0->CTRL = UART_RESET_VALUE;
    UART0->ISR  = UART_RESET_VALUE;
    UART0->BRDIV =UART_RESET_VALUE;
}
void UART1_DeInit(void)
{
    UART1->DATA = UART_RESET_VALUE;
    UART1->SR   = UART_RESET_VALUE;
    UART1->CTRL = UART_RESET_VALUE;
    UART1->ISR  = UART_RESET_VALUE;
    UART1->BRDIV =UART_RESET_VALUE;
}
void UART2_DeInit(void)
{
	UART2->DATA = UART_RESET_VALUE;
    UART2->SR   = UART_RESET_VALUE;
    UART2->CTRL = UART_RESET_VALUE;
    UART2->ISR  = UART_RESET_VALUE;
    UART2->BRDIV =UART_RESET_VALUE;
}
/*************************************************************/
//UART0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_Int_Enable(void)
{
    UART0->ISR=0x0F;									//clear UART0 INT status
	INTC_ISER_WRITE(UART0_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_Int_Disable(void)
{
	INTC_ICER_WRITE(UART0_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART1 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1_Int_Enable(void)
{
    UART1->ISR=0x0F;									//clear UART1 INT status
	INTC_ISER_WRITE(UART1_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART1 Interrupt Disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1_Int_Disable(void)
{
    INTC_ICER_WRITE(UART1_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART1 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2_Int_Enable(void)
{
    UART2->ISR=0x0F;									//clear UART1 INT status
	INTC_ISER_WRITE(UART2_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART1 Interrupt Disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2_Int_Disable(void)
{
    INTC_ICER_WRITE(UART2_INT);							//INT Vector Enable UART0/1 Interrupt in CK802
}
/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(UART0_INT);    
}

/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(UART0_INT);    
}
/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(UART1_INT);    
}

/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(UART1_INT);    
}
/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(UART2_INT);    
}

/*************************************************************/
//UART0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART2_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(UART2_INT);    
}
/*************************************************************/
//UART IO Init
//EntryParameter:IO_UARTX,UART_IO_G
//IO_UARTX:IO_UART0,IO_UART1
//UART_IO_G:0 1
//ReturnValue:NONE
/*************************************************************/
void UART_IO_Init(UART_NUM_TypeDef IO_UART_NUM , U8_T UART_IO_G)
{
    if (IO_UART_NUM==IO_UART0)
    {
		if(UART_IO_G==0)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFF00)  | 0x00000044;       //PA0.1->RXD0, PA0.0->TXD0
		}
		else if(UART_IO_G==1)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFF0FFFFF)  | 0x00700000;      //PA0.5->RXD0, PA0.12->TXD0
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFF0FFFF)  | 0x00070000;      
		}
    }
     if (IO_UART_NUM==IO_UART1)
    {
        if(UART_IO_G==0)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFF0)  | 0x00000007;       //PA0.13->RXD1, PB0.0->TXD1
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFF0FFFFF)  | 0x00700000;       
		}
		else if(UART_IO_G==1)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF00FFF) | 0X00077000;        //PA0.4->RXD1, PA0.3->TXD1
		}
		else if(UART_IO_G==2)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF) | 0X77000000;        //PA0.15->RXD1, PA0.14->TXD1
		}
    }
	 if (IO_UART_NUM==IO_UART2)
    {
        if(UART_IO_G==0)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFF00)  | 0x00000077;       //PA0.0->RXD2, PA0.1->TXD2
		}
		else if(UART_IO_G==1)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0X00FFFFFF) | 0X77000000;        //PA0.7->RXD2, PA0.6->TXD2
		}
		else if(UART_IO_G==2)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFF00FFFF) | 0X00660000;        //PB0.5->RXD2, PB0.4->TXD2
		}
    }
}
/*************************************************************/
//UART Init
//EntryParameter:UART0,UART1 ,baudrate_u16 
//e.g:
//sys_clk@24MHz, 24/4(div)=6MHz, 6000000/115200bps=52,baudrate_u16=52
//sys_clk@24MHz, 24/2(div)=12MHz, 12000000/115200bps=104,baudrate_u16=104
//ReturnValue:NONE
/*************************************************************/
void UARTInit(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT)
{
   // Set Transmitter Enable
   CSP_UART_SET_CTRL(uart, UART_TX | UART_RX);
   // Set Baudrate
   CSP_UART_SET_BRDIV(uart, baudrate_u16);
    uart->CTRL|=PAR_DAT|(0X01<<31);
}
/*************************************************************/
//UART init and enable RX,TX interrupt
//EntryParameter:UART0,UART1 ,baudrate_u16 
//ReturnValue:NONE
/*************************************************************/
void UARTInitRxTxIntEn(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT)
{
   // Set Transmitter Enable
   CSP_UART_SET_CTRL(uart, UART_TX | UART_RX | UART_RX_INT | UART_TX_INT);
   // Set Baudrate
   CSP_UART_SET_BRDIV(uart, baudrate_u16);

   uart->CTRL|=PAR_DAT|(0X01<<31);
}
/*************************************************************/
//UART init and enable RX interrupt
//EntryParameter:UART0,UART1 ,baudrate_u16 
//ReturnValue:NONE
/*************************************************************/
void UARTInitRxIntEn(CSP_UART_T *uart,U16_T baudrate_u16,UART_PAR_TypeDef PAR_DAT)
{
   // Set Transmitter Enable
   CSP_UART_SET_CTRL(uart, UART_TX | UART_RX | UART_RX_INT);
   // Set Baudrate
   CSP_UART_SET_BRDIV(uart, baudrate_u16);
   uart->CTRL|=PAR_DAT|(0X01<<31);
}
/*************************************************************/
//UART Close
//EntryParameter:UART0,UART1
//ReturnValue:NONE
/*************************************************************/
void UARTClose(CSP_UART_T *uart)
{
	// Set Transmitter Disable
	CSP_UART_SET_CTRL(uart, 0x00);
}

/*************************************************************/
//UART TX Byte 
//EntryParameter:UART0,UART1,txdata_u8
//ReturnValue:NONE
/*************************************************************/
void UARTTxByte(CSP_UART_T *uart,U8_T txdata_u8)
{
	unsigned int  DataI;
	// Write the transmit buffer
	CSP_UART_SET_DATA(uart,txdata_u8);
	do
	{
		DataI = CSP_UART_GET_SR(uart);
		DataI = DataI & UART_TX_FULL;
	}
	while(DataI == UART_TX_FULL);    //Loop  when tx is full
	
	// Write the transmit buffer
	/*CSP_UART_SET_DATA(uart,txdata_u8);

	// Wait for the transmit done
	while ( (CSP_UART_GET_ISR(uart) & UART_TX_INT_S) != UART_TX_INT_S ) {}

	// Clear status bit for the next transmit
	CSP_UART_SET_ISR(uart, UART_TX_INT_S);*/

}
/*************************************************************/
//UART Transmit 
//EntryParameter:UART0,UART1,sourceAddress_u16,length_u16
//ReturnValue:NONE
/*************************************************************/
void UARTTransmit(CSP_UART_T *uart,U8_T *sourceAddress_u16,U16_T length_u16)
{
	unsigned int  DataI,DataJ;
	for(DataJ = 0;DataJ < length_u16 ;DataJ ++)
	{
		CSP_UART_SET_DATA(uart,*sourceAddress_u16++);
		do{
			DataI = CSP_UART_GET_SR(uart);
			DataI = DataI & UART_TX_FULL;
		}while(DataI == UART_TX_FULL);    //Loop  when tx is full
	}
}

/*************************************************************/
//UART RX Byte 
//EntryParameter:UART0,UART1,Rxdata_u16
//ReturnValue:NONE
/*************************************************************/
U16_T UARTRxByte(CSP_UART_T *uart,U8_T *Rxdata_u16)
{
	unsigned int  DataI;

	DataI = CSP_UART_GET_SR(uart);
	DataI = DataI & UART_RX_FULL;
	if(DataI != UART_RX_FULL)    //Loop  when rx is not full
		return FALSE;
	else
	{
		*Rxdata_u16 = CSP_UART_GET_DATA(uart);
	    return TRUE;
	}
}

/*************************************************************/
//UART RX Return Byte 
//EntryParameter:UART0,UART1
//ReturnValue:(uart)->DATA
/*************************************************************/
U8_T UART_ReturnRxByte(CSP_UART_T *uart)
{
	RxDataFlag = FALSE;
	while(RxDataFlag != TRUE);
	return CSP_UART_GET_DATA(uart);
}

/*************************************************************/
//UART Receive
//EntryParameter:UART0,UART1，destAddress_u16，length_u16
//ReturnValue:FALSE/TRUE
/*************************************************************/
U16_T UARTReceive(CSP_UART_T *uart,U8_T *destAddress_u16,U16_T length_u16)
{
	unsigned int  DataI,DataJ,LoopTime;

	DataJ = 0;
	LoopTime = 0;
	do{
		DataI = CSP_UART_GET_SR(uart);
		DataI = DataI & UART_RX_FULL;
		if(DataI == UART_RX_FULL)    //Loop  when rx is full
		{
			*destAddress_u16++ = CSP_UART_GET_DATA(uart);
			DataJ++;
			LoopTime = 0;
		}
		if(LoopTime ++ >= 0xfff0)
			return FALSE;
	}while(DataJ < length_u16);
	return TRUE;
}
