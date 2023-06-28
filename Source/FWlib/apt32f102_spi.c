/*
  ******************************************************************************
  * @file    apt32f102_spi.c
  * @author  APT AE Team
  * @version V0.55
  * @date    2020/06/08
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

/* Define to prevent recursive inclusion -------------------------------------*/ 
#include "apt32f102_spi.h"
/* defines -------------------------------------------------------------------*/

/* -------- variables ---------------------------------------------------------*/

/* externs--------------------------------------------------------------------*/
extern void delay_nus(unsigned int t);
/*************************************************************/
//SPI RESET,CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_DeInit(void)
{
    SPI0->CR0   	= SPI_CR0_RST;
    SPI0->CR1   	= SPI_CR1_RST;
    //SPI0->DR   	 	= SPI_DR_RST;
    SPI0->SR   	 	= SPI_SR_RST;
    SPI0->CPSR   	= SPI_CPSR_RST;
    SPI0->IMSCR   	= SPI_IMSCR_RST;
    SPI0->RISR   	= SPI_RISR_RST;
    SPI0->MISR   	= SPI_MISR_RST;
    SPI0->ICR	 	= SPI_ICR_RST;
}
/*************************************************************/
//SPI NSS IO Initial
//ReturnValue:NONE
/*************************************************************/
void SPI_NSS_IO_Init(U8_T SPI_NSS_IO_GROUP)
{
	if(SPI_NSS_IO_GROUP==0)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XF0FFFFFF)  | 0x05000000;				//PA0.6
	}
	else if(SPI_NSS_IO_GROUP==1)
	{
		GPIOB0->CONLR = (GPIOB0->CONLR&0XFF0FFFFF)  | 0x00800000;				//PB0.5
	}
}
/*************************************************************/
//SPI Master Init 	
//EntryParameter:SPI_IO,SPI_DATA_SIZE_x,SPI_SPO_X,SPI_SPH_X,SPI_LBM_X,SPI_SCR,SPI_CPSDVSR
//SPI_IO:SPI_G0,SPI_G1,SPI_G2
//SPI_DATA_SIZE_x:SPI_DATA_SIZE_4BIT~SPI_DATA_SIZE_16BIT
//SPI_SPO_X:SPI_SPO_0,SPI_SPO_1
//SPI_SPH_X:SPI_SPH_0,SPI_SPH_1
//SPI_LBM_X:SPI_LBM_0,SPI_LBM_1
//SPI_RXIFLSEL_X:SPI_RXIFLSEL_1_8,SPI_RXIFLSEL_1_4,SPI_RXIFLSEL_1_2
//SPI_SCR:0~255
//SPI_CPSDVSR:2~254,Must be an even number between 2 and 254
//ReturnValue:NONE
/*************************************************************/
//SPI波特率:FSSPCLK = FPCLK / (CPSDVR × (1 + SCR))
//FPCLK (max) → 2 × FSSPCLKOUT (max)主机	Fastest speed
void SPI_Master_Init(SPI_IO_TypeDef SPI_IO , SPI_DATA_SIZE_TypeDef SPI_DATA_SIZE_x , SPI_SPO_TypeDef SPI_SPO_X , SPI_SPH_TypeDef SPI_SPH_X , SPI_LBM_TypeDef SPI_LBM_X , SPI_RXIFLSEL_TypeDef SPI_RXIFLSEL_X , U8_T SPI_SCR , U8_T SPI_CPSDVSR )
{
	if (SPI_IO==SPI_G0)
    {
		GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFF00FF)  | 0x00008800;
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)  | 0x00000008;            //PB0.2->SPI_SCK,PB0.3->SPI_MOSI,PA0.8->SPI_MIS0
    }
    else if(SPI_IO==SPI_G1)
    {
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFF000F)  | 0x00004440;            //PA0.9->SPI_SCK,PA0.10->SPI_MOSI,PA0.11->SPI_MIS0
    }
	else if(SPI_IO==SPI_G2)
	{
		GPIOB0->CONLR = (GPIOB0->CONLR&0XFFF0FFFF)  | 0x00080000;			//SPI_SCK->PB0.4
		GPIOA0->CONHR = (GPIOA0->CONHR&0X00FFFFFF)  | 0x88000000;			//SPI_MOSI->PA0.14,SPI_MISO->PA0.15
	}
	SPI0->CPSR=SPI_CPSDVSR;
	
	SPI0->CR0|=SPI_DATA_SIZE_x|(SPI_SPO_X<<6)|(SPI_SPH_X<<7)|(SPI_SCR<<8);
	SPI0->CR1|=0X02|SPI_LBM_X|(SPI_RXIFLSEL_X<<4);
}
/*************************************************************/
//SPI Slave Init 	
//EntryParameter:SPI_IO,SPI_DATA_SIZE_x,SPI_RXIFLSEL_X,SPI_SCR,SPI_CPSDVSR
//SPI_DATA_SIZE_x:SPI_DATA_SIZE_4BIT~SPI_DATA_SIZE_16BIT
//SPI_RXIFLSEL_X:SPI_RXIFLSEL_1_8,SPI_RXIFLSEL_1_4,SPI_RXIFLSEL_1_2
//SPI_SCR:0~255
//SPI_CPSDVSR:2~254,Must be an even number between 2 and 254
//ReturnValue:NONE
/*************************************************************/
//SPI波特率:FSSPCLK = FPCLK / (CPSDVR × (1 + SCR))
//FPCLK (max) → 12 × FSSPCLKIN (max)从机	Fastest speed
void SPI_Slave_Init(SPI_IO_TypeDef SPI_IO , SPI_DATA_SIZE_TypeDef SPI_DATA_SIZE_x , SPI_SPH_TypeDef SPI_SPH_X , SPI_RXIFLSEL_TypeDef SPI_RXIFLSEL_X , U8_T SPI_SCR , U8_T SPI_CPSDVSR)
{
	if (SPI_IO==SPI_G0)
    {
		GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFF00FF)  | 0x00008800;
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFF0)  | 0x00000008;            //PB0.2->SPI_SCK,PB0.3->SPI_MISO,PA0.8->SPI_MOSI
    }
    else if(SPI_IO==SPI_G1)
    {
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFF000F)  | 0x00004440;            //PA0.9->SPI_SCK,PA0.10->SPI_MISO,PA0.11->SPI_MOSI
    }
	else if(SPI_IO==SPI_G2)
	{
		GPIOB0->CONLR = (GPIOB0->CONLR&0XFFF0FFFF)  | 0x00080000;			//SPI_SCK->PB0.4
		GPIOA0->CONHR = (GPIOA0->CONHR&0XF00FFFFF)  | 0x08800000;			//SPI_MOSIO->PA0.14,SPI_MISO->PA0.15
	}
	SPI0->CR0|=SPI_DATA_SIZE_x|(SPI_SPH_X<<7)|(SPI_SCR<<8);
	SPI0->CPSR=SPI_CPSDVSR;
	SPI0->CR1|=0X06|(SPI_RXIFLSEL_X<<4);
}
/*************************************************************/
//SPI WRITE BYTE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_WRITE_BYTE(U16_T wdata)
{
	while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	
	SPI0->DR = wdata;
	while(((SPI0->SR) & SSP_BSY) == SSP_BSY);		//wait for transmition finish
}
/*************************************************************/
//SPI READ BYTE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_READ_BYTE(U16_T wdata , volatile U16_T *rdata , U8_T Longth)
{
	U8_T i;
	while(((SPI0->SR) & SSP_TNF) != SSP_TNF);		//发送FIFO是否满？
	SPI0->DR = wdata;
	while(((SPI0->SR) & SSP_BSY) == SSP_BSY);		//发送或接收是否完成？
	delay_nus(1);
	*rdata = SPI0->DR;
	for(i=0;i<Longth;i++)
	{
		while(((SPI0->SR) & SSP_TNF) != SSP_TNF);	
		SPI0->DR=0;
		while(((SPI0->SR) & SSP_BSY) == SSP_BSY);
		*(rdata+i) = SPI0->DR;  	//get data from FIFO
	}
}
/*************************************************************/
//SPI inturrpt Configure
//EntryParameter:SPI_IMSCR_X,NewState
//SPI_IMSCR_X:SPI_PORIM,SPI_RTIM,SPI_RXIM,SPI_TXIM
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void SPI_ConfigInterrupt_CMD(FunctionalStatus NewState,SPI_IMSCR_TypeDef SPI_IMSCR_X)
{
	if (NewState != DISABLE)
	{
		SPI0->IMSCR  |= SPI_IMSCR_X;						//SET
	}
	else
	{
		SPI0->IMSCR  &= ~SPI_IMSCR_X;					//CLR
	}
}   
/*************************************************************/
//SPI Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_Int_Enable(void)
{
    INTC_ISER_WRITE(SPI_INT);    
}
/*************************************************************/
//SPI Interrupt disalbe
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_Int_Disable(void)
{
    INTC_ICER_WRITE(SPI_INT);    
}
/*************************************************************/
//SPI Interrupt wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_Wakeup_Enable(void)
{
    INTC_IWER_WRITE(SPI_INT);    
}

/*************************************************************/
//SPI Interrupt wake up disalbe
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SPI_Wakeup_Disable(void)
{
    INTC_IWDR_WRITE(SPI_INT);    
}


/******************* (C) COPYRIGHT 2018 APT Chip *****END OF FILE****/