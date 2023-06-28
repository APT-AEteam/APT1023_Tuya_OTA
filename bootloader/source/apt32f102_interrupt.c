/*
  ******************************************************************************
  * @file    apt32f102_interrupt.c
  * @author  APT AE Team
  * @version V0.50
  * @date    2020/05/14
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
#include "apt32f102.h"
#include "apt32f102_syscon.h"
#include "apt32f102_coret.h"
#include "apt32f102_gpio.h"
#include "apt32f102_crc.h"
#include "apt32f102_wwdt.h"
#include "apt32f102_lpt.h"
#include "apt32f102_countera.h"
//#include "apt32f102_bt.h"
#include "apt32f102_hwdiv.h"
#include "apt32f102_sio.h"
#include "apt32f102_uart.h"
#include "apt32f102_i2c.h"
#include "apt32f102_spi.h"
#include "apt32f102_rtc.h"
#include "apt32f102_ept.h"
#include "apt32f102_gpt.h"
#include "apt32f102_et.h"
#include "apt32f102_adc.h"
#include "apt32f102_ifc.h"
#include "apt32f102_types_local.h"
#include "apt32f102_bt.h"
#include "define.h"
/* externs--------------------------------------------------------------------*/
extern void delay_nms(unsigned int t);
//volatile int R_CMPA_BUF,R_CMPB_BUF;
//volatile U8_T ifc_step,f_Drom_write_complete;
//volatile int R_SIOTX_count,R_SIORX_count;
//volatile int R_SIORX_buf[10];
//volatile int SPI_DATA[8];
//volatile U8_T r_uart_buf[9];
//volatile U8_T r_urat_cont;
//
//volatile U8_T f_io_toggle;

/*************************************************************/
//CORET Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CORETHandler(void) 
{
    // ISR content ...
	CK801->CORET_CVR = 0x0;							// Clear counter and flag
	nop;
}
/*************************************************************/
//SYSCON Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCONIntHandler(void) 
{
    // ISR content ...
	if((SYSCON->MISR&ISOSC_ST)==ISOSC_ST)
	{
		SYSCON->ICR = ISOSC_ST;
	} 
}
/*************************************************************/
//IFC Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void IFCIntHandler(void) 
{

}
/*************************************************************/
//ADC Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void ADCIntHandler(void) 
{
    // ISR content ...
}
/*************************************************************/
//EPT0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EPT0IntHandler(void) 
{
    
}
/*************************************************************/
//WWDT Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void WWDTHandler(void)
{
	WWDT->ICR=0X01;
	WWDT_CNT_Load(0xFF);
	GPIO_Init(GPIOA0,4,0);
	GPIO_Reverse(GPIOA0,4);
	
	if((WWDT->MISR&WWDT_EVI)==WWDT_EVI)
	{
		WWDT->ICR = WWDT_EVI;
	} 
}
/*************************************************************/
//GPT0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPT0IntHandler(void) 
{
    // ISR content ...
	//Interupt
//	if((GPT0->MISR&GPT_INT_TRGEV0)==GPT_INT_TRGEV0)
//	{
//		GPT0->ICR = GPT_INT_TRGEV0;
//	} 
//	else if((GPT0->MISR&GPT_INT_TRGEV1)==GPT_INT_TRGEV1)
//	{
//		GPT0->ICR = GPT_INT_TRGEV1;
//	}
//	else if((GPT0->MISR&GPT_INT_TRGEV2)==GPT_INT_TRGEV2)
//	{
//		GPT0->ICR = GPT_INT_TRGEV0;
//	}
//	else if((GPT0->MISR&GPT_TRGEV3)==GPT_INT_TRGEV3)
//	{
//		GPT0->ICR = GPT_INT_TRGEV3;
//	}
//	else if((GPT0->MISR&GPT_INT_CAPLD0)==GPT_INT_CAPLD0)
//	{
//		GPT0->ICR = GPT_INT_CAPLD0;
//	}
//	else if((GPT0->MISR&GPT_INT_CAPLD1)==GPT_INT_CAPLD1)
//	{
//		GPT0->ICR = GPT_INT_CAPLD1;
//	}
//	else if((GPT0->MISR&GPT_INT_CAPLD2)==GPT_INT_CAPLD2)
//	{
//		GPT0->ICR = GPT_INT_CAPLD2;
//	}
//	else if((GPT0->MISR&GPT_INT_CAPLD3)==GPT_INT_CAPLD3)
//	{
//		GPT0->ICR = GPT_INT_CAPLD3;
//	}
//	else if((GPT0->MISR&GPT_INT_CAU)==GPT_INT_CAU)
//	{
//		GPT0->ICR = GPT_INT_CAU;
//	}
//	else if((GPT0->MISR&GPT_INT_CAD)==GPT_INT_CAD)
//	{
//		GPT0->ICR = GPT_INT_CAD;
//	}
//	else if((GPT0->MISR&GPT_INT_CBU)==GPT_INT_CBU)
//	{
//		GPT0->ICR = GPT_INT_CBU;
//	}
//	else if((GPT0->MISR&GPT_INT_CBD)==GPT_INT_CBD)
//	{
//		GPT0->ICR = GPT_INT_CBD;
//	}
//	else if((GPT0->MISR&GPT_INT_PEND)==GPT_INT_PEND)
//	{
//		GPT0->ICR = GPT_INT_PEND;
//	}
}
/*************************************************************/
//RTC Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void RTCIntHandler(void) 
{
    // ISR content ...
//	if((RTC->MISR&ALRA_INT)==ALRA_INT)			//ALRAR 
//	{
//		RTC->ICR=ALRA_INT;
//		RTC->KEY=0XCA53;
//		RTC->CR=RTC->CR|0x01;
//		RTC->TIMR=(0x10<<16)|(0x00<<8)|(0x00);			//Hour bit6->0:am 1:pm	
//		while(RTC->CR&0x02);//busy 判断TIMR DATR ALRAR ALRBR数据写完
//		RTC->CR &= ~0x1;
//	}
//	else if((RTC->MISR&ALRB_INT)==ALRB_INT)			//ALRBR				
//	{
//		RTC->ICR=ALRB_INT;
//	}
//	else if((RTC->IMCR&CPRD_INT)==CPRD_INT)			//CPRD
//	{
//		RTC->ICR=CPRD_INT;
//	}
//	else if((RTC->IMCR&RTC_TRGEV0_INT)==RTC_TRGEV0_INT)
//	{
//		RTC->ICR=RTC_TRGEV0_INT;
//	}
//	else if((RTC->IMCR&RTC_TRGEV1_INT)==RTC_TRGEV1_INT)
//	{
//		RTC->ICR=RTC_TRGEV1_INT;
//	}
}
/*************************************************************/
//UART0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART0IntHandler(void) 
{
    // ISR content ...
	//Interupt
//	if ((UART0->ISR&UART_RX_INT_S)==UART_RX_INT_S)
//	{
//		UART0->ISR=UART_RX_INT_S;
//
//	}
//	else if( (UART0->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 
//    {
//		UART0->ISR=UART_TX_INT_S;
//
//	}
//	else if ((UART0->ISR&UART_RX_IOV_S)==UART_RX_IOV_S)
//	{
//		UART0->ISR=UART_RX_IOV_S;
//	}
//	else if ((UART0->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)
//	{
//		UART0->ISR=UART_TX_IOV_S;
//	}
}
/*************************************************************/
//UART1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void UART1IntHandler(void) 
{
	if( CSP_UART_GET_ISR(UART1) & UART_RX_INT_S ) 
	{
		CSP_UART_SET_ISR(UART1, UART_RX_INT_S);
	}
	else if( (UART1->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 
    {
		UART1->ISR=UART_TX_INT_S;

	}
}
/*************************************************************/ 
//UART2 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
U8_T g_RxData = 0;
void UART2IntHandler(void) 
{
    // ISR content ...
	//Interupt
//	if ((UART2->ISR&UART_RX_INT_S)==UART_RX_INT_S)
//	{
//		g_RxData = (U8_T)(UART2->DATA);
//		Rx_Buf[Rx_Count] = g_RxData;
//		if(++Rx_Count>=MAX_BUFF)
//		{
//			Rx_Count=0;
//		}
//		FlagSetBit(FgRxDone);//FgRxDone=1;//接收标志置位
//		RxDoneCnt=0;
//		
//		UART2->ISR=UART_RX_INT_S;
//	}
//	else if( (UART2->ISR&UART_TX_INT_S)==UART_TX_INT_S ) 
//    {
//		UART2->ISR=UART_TX_INT_S;
//
//	}
//	else if ((UART2->ISR&UART_RX_IOV_S)==UART_RX_IOV_S)
//	{
//		UART2->ISR=UART_RX_IOV_S;
//	}
//	else if ((UART2->ISR&UART_TX_IOV_S)==UART_TX_IOV_S)
//	{
//		UART2->ISR=UART_TX_IOV_S;
//	}
}
/*************************************************************/
//I2C Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void I2CIntHandler(void) 
{
    // ISR content ...
	//I2C_Slave_Receive();
}
/*************************************************************/
//SPI Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI0IntHandler(void) 
{
    // ISR content ...
//	if((SPI0->MISR&SPI_PORIM)==SPI_PORIM)					//Receive Overrun Interrupt
//	{
//		SPI0->ICR = SPI_PORIM;
//	} 
//	else if((SPI0->MISR&SPI_RTIM)==SPI_RTIM)				//Receive Timeout Interrupt
//	{
//		SPI0->ICR = SPI_RTIM;
//	}
//	else if((SPI0->MISR&SPI_RXIM)==SPI_RXIM)				//Receive FIFO Interrupt,FIFO can be set 1/8,1/4,1/2 FIFO Interrupt
//	{
//		SPI0->ICR = SPI_RXIM;
//		/*if(SPI0->DR==0xaa)
//		{
//			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
//			SPI0->DR = 0x11;
//			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
//			
//			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
//			SPI0->DR = 0x12;
//			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
//			
//			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
//			SPI0->DR = 0x13;
//			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
//			
//			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
//			SPI0->DR = 0x14;
//			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
//			
//			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
//			SPI0->DR = 0x15;
//			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
//			
//			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
//			SPI0->DR = 0x16;
//			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
//			
//			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
//			SPI0->DR = 0x17;
//			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
//			
//			while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	//FIFO未满？
//			SPI0->DR = 0x18;
//			while(((SPI0->SR) & SSP_BSY) == SSP_BSY);	//发送或接收完成？
//		}
//		else
//		{
//			if(((SPI0->SR) & SSP_TFE)!=SSP_TFE)
//			{
//				SPI0->DR=0x0;								//FIFO空
//				SPI0->DR=0x0;								//FIFO空
//				SPI0->DR=0x0;								//FIFO空
//				SPI0->DR=0x0;								//FIFO空
//				SPI0->DR=0x0;								//FIFO空
//				SPI0->DR=0x0;								//FIFO空
//				SPI0->DR=0x0;								//FIFO空
//				SPI0->DR=0x0;								//FIFO空
//				while(((SPI0->SR) & SSP_BSY) == SSP_BSY);		//发送或接收是否完成？
//			}
//		}*/
//	}
//	else if((SPI0->MISR&SPI_TXIM)==SPI_TXIM)				//Transmit FIFO Interrupt
//	{
//		SPI0->ICR = SPI_TXIM;
//	}

}
/*************************************************************/
//SIO Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SIO0IntHandler(void) 
{
//    // ISR content ...
//	//序列超过16bit法发送程序方法，1.在主循环查询吧中断关掉 2.在中断里面做且把优先级设置最高
//	/*CK801->IPR[0]=0X40404040;
//	CK801->IPR[1]=0X40404040;
//	CK801->IPR[2]=0X40404040;
//	CK801->IPR[3]=0X40404040;
//	CK801->IPR[4]=0X40404040;
//	CK801->IPR[5]=0X40404000;
//	CK801->IPR[6]=0X40404040;
//	CK801->IPR[7]=0X40404040;*/
//	/*if(SIO0->MISR&0X04)					//TXBUFEMPT 一个序列长度内超过15bit后的数据需要更新进此中断
//	{
//		SIO0->ICR=0X04;
//		if(R_SIOTX_count<1)
//		{
//			SIO0->TXBUF=(0x00<<30)|(0x00<<28)|(0x00<<26)|(0x00<<24)|(0x00<<22)|(0x00<<20)|(0x00<<18)|(0x00<<16)|
//				(0x01<<14)|(0x00<<12)|(0x01<<10)|(0x00<<8)|(0x01<<6)|(0x01<<4)|(0x01<<2)|(0x1<<0);		//0:D0,1:D1,2:DL,3:DH; 
//				R_SIOTX_count++;
//		}
//	}
//	if(SIO0->MISR&0X01)					//TXDNE
//	{
//		SIO0->ICR=0X01;
//		if(R_SIOTX_count>=1)
//		{
//			delay_nms(10);
//			SIO0->TXBUF=(0x03<<30)|(0x02<<28)|(0x03<<26)|(0x02<<24)|(0x03<<22)|(0x02<<20)|(0x03<<18)|(0x02<<16)|
//				(0x01<<14)|(0x00<<12)|(0x01<<10)|(0x00<<8)|(0x01<<6)|(0x00<<4)|(0x01<<2)|(0x0<<0);		//0:D0,1:D1,2:DL,3:DH;
//			R_SIOTX_count=0;
//		}	
//	}*/
//	
//	//序列小于16bit发送程序
//	/*if(SIO0->MISR&0X01)					//TXDNE
//	{
//		SIO0->ICR=0X01;
//		delay_nms(10);
//		SIO0->TXBUF=(0x03<<30)|(0x02<<28)|(0x03<<26)|(0x02<<24)|(0x03<<22)|(0x02<<20)|(0x03<<18)|(0x02<<16)|
//				(0x01<<14)|(0x00<<12)|(0x01<<10)|(0x00<<8)|(0x01<<6)|(0x00<<4)|(0x01<<2)|(0x0<<0);		//0:D0,1:D1,2:DL,3:DH;	
//	}*/
//	
//	if(SIO0->MISR&0X02)					//RXDNE
//	{
//		SIO0->ICR=0X02;
////		if(R_SIORX_count>=1)
////		{
////			R_SIORX_buf[R_SIORX_count]=SIO0->RXBUF&0xff000000;			//8bit
////			nop;
////			R_SIORX_count=0;
////		}
//	}
//	else if(SIO0->MISR&0X08)					//RXBUFFULL	
//	{
//		SIO0->ICR=0X08;
////		if(R_SIORX_count<1)
////		{
////			R_SIORX_buf[R_SIORX_count]=SIO0->RXBUF;				//32bit
////			R_SIORX_count++;
////		}
//	}
//	else if(SIO0->MISR&0X010)				//BREAK
//	{
//		SIO0->ICR=0X10;
//	}
//	else if(SIO0->MISR&0X020)				//TIMEOUT
//	{
//		SIO0->ICR=0X20;
//	}
}
/*************************************************************/
//EXT0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0IntHandler(void) 
{
    // ISR content ...
//	if ((SYSCON->EXIRS&EXI_PIN0)==EXI_PIN0) 
//	{
//		SYSCON->EXICR = EXI_PIN0;
//	}
}
/*************************************************************/
//EXT1Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1IntHandler(void) 
{
    // ISR content ...
//	if ((SYSCON->EXIRS&EXI_PIN1)==EXI_PIN1) 
//	{
//		SYSCON->EXICR = EXI_PIN1;
//	}
}
/*************************************************************/
//EXI2 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2to3IntHandler(void) 
{
    // ISR content ...
//	if ((SYSCON->EXIRS&EXI_PIN2)==EXI_PIN2) 
//	{
//		SYSCON->EXICR = EXI_PIN2;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN3)==EXI_PIN3) 
//	{
//		SYSCON->EXICR = EXI_PIN3;
//	}
}
/*************************************************************/
//EXI3 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4to8IntHandler(void) 
{
    // ISR content ...
//	if ((SYSCON->EXIRS&EXI_PIN4)==EXI_PIN4) 
//	{
//		SYSCON->EXICR = EXI_PIN4;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN5)==EXI_PIN5) 
//	{
//		SYSCON->EXICR = EXI_PIN5;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN6)==EXI_PIN6) 
//	{
//		SYSCON->EXICR = EXI_PIN6;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN7)==EXI_PIN7) 
//	{
//		SYSCON->EXICR = EXI_PIN7;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN8)==EXI_PIN8) 
//	{
//		SYSCON->EXICR = EXI_PIN8;
//	}

}
/*************************************************************/
//EXI4 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI9to13IntHandler(void) 
{
    // ISR content ...
//	if ((SYSCON->EXIRS&EXI_PIN9)==EXI_PIN9) 
//	{
//		SYSCON->EXICR = EXI_PIN9;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN10)==EXI_PIN10) 
//	{
//		SYSCON->EXICR = EXI_PIN10;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN11)==EXI_PIN11) 
//	{
//		SYSCON->EXICR = EXI_PIN11;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN12)==EXI_PIN12) 
//	{
//		SYSCON->EXICR = EXI_PIN12;
//	} 
//	else if ((SYSCON->EXIRS&EXI_PIN13)==EXI_PIN13) 
//	{
//		SYSCON->EXICR = EXI_PIN13;
//	}
}
/*************************************************************/
//CONTA Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void CNTAIntHandler(void) 
{
    // ISR content ...
}
extern volatile unsigned int s_tkey;
/*************************************************************/
//TKEY Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void TKEYIntHandler(void) 
{
    // ISR content ...
	//TKEY->TCH_ICR = TKEY_SINDNE;

}
/*************************************************************/
//LPT Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LPTIntHandler(void) 
{
    // ISR content ...
	//Interupt
//	if((LPT->MISR&LPT_TRGEV0)==LPT_TRGEV0)
//	{
//		LPT->ICR = LPT_TRGEV0;
//	} 
//	else if((BT0->MISR&LPT_MATCH)==LPT_MATCH)
//	{
//		LPT->ICR = LPT_MATCH;
//	}
//	else if((BT0->MISR&LPT_PEND)==LPT_PEND)
//	{
//		LPT->ICR = LPT_PEND;
//	}
}
/*************************************************************/
//BT0 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT0IntHandler(void) 
{
    // ISR content ...
	if((BT0->MISR&BT_PEND)==BT_PEND)
	{
//		//-------------------------------------------------
//		//有数据接收时,如4MS内无数据,则结束此次接收
//		if(FgRxDone)
//		{
//			if(++RxDoneCnt>=32)//
//			{
//				FlagClearBit(FgRxDone);//FgRxDone=0;
//				RxDoneCnt=0;
//				FlagSetBit(FgRx_End);//FgRx_End=1;
//			}
//		}
//		
//		if(++Time2500us>=20)
//		{
//			Time2500us=0;
//			FlagSetBit(Fg2500us);//Fg2500us=1;
//		}
//		
//		//-------------------------------------------------
		BT0->ICR = BT_PEND;
	} 
	else if((BT0->MISR&BT_CMP)==BT_CMP)
	{
		BT0->ICR = BT_CMP;
	}
	else if((BT0->MISR&BT_OVF)==BT_OVF)
	{
		BT0->ICR = BT_OVF;
	} 
	else if((BT0->MISR&BT_EVTRG)==BT_EVTRG)
	{
		BT0->ICR = BT_EVTRG;
	} 
}
/*************************************************************/
//BT1 Interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void BT1IntHandler(void) 
{
    // ISR content ...
//	if((BT1->MISR&BT_PEND)==BT_PEND)
//	{
//		BT1->ICR = BT_PEND;
//	} 
//	else if((BT0->MISR&BT_CMP)==BT_CMP)
//	{
//		BT1->ICR = BT_CMP;
//	}
//	else if((BT0->MISR&BT_OVF)==BT_OVF)
//	{
//		BT1->ICR = BT_OVF;
//	} 
//	else if((BT0->MISR&BT_EVTRG)==BT_EVTRG)
//	{
//		BT1->ICR = BT_EVTRG;
//	} 
}
/*************************************************************/
/*************************************************************/
/*************************************************************/
void PriviledgeVioHandler(void) 
{
    // ISR content ...

}

void SystemDesPtr(void) 
{
    // ISR content ...

}

void MisalignedHandler(void) 
{
    // ISR content ...

}

void IllegalInstrHandler(void) 
{
    // ISR content ...

}

void AccessErrHandler(void) 
{
    // ISR content ...

}

void BreakPointHandler(void) 
{
    // ISR content ...

}

void UnrecExecpHandler(void) 
{
    // ISR content ...

}

void Trap0Handler(void) 
{
    // ISR content ...

}

void Trap1Handler(void) 
{
    // ISR content ...

}

void Trap2Handler(void) 
{
    // ISR content ...

}

void Trap3Handler(void) 
{
    // ISR content ...

}

void PendTrapHandler(void) 
{
    // ISR content ...

}
/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/

