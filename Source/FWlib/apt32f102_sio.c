/*
  ******************************************************************************
  * @file    apt32f102_sio.c
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
#include "apt32f102_sio.h"


/*************************************************************/
//SIO RESET CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void SIO_DeInit(void)
{
	SIO0->CR 		= SIO_RESET_VALUE;
	SIO0->TXCR0 	= SIO_RESET_VALUE;
	SIO0->TXCR1 	= SIO_RESET_VALUE;
	//SIO0->TXBUF 	= SIO_RESET_VALUE;
	SIO0->RXCR0 	= SIO_RESET_VALUE;
	SIO0->RXCR1 	= SIO_RESET_VALUE;
	SIO0->RXCR1 	= SIO_RESET_VALUE;
	//SIO0->RXBUF 	= SIO_RESET_VALUE;
	SIO0->RISR 		= SIO_RESET_VALUE;
	SIO0->MISR 		= SIO_RESET_VALUE;
	SIO0->IMCR 		= SIO_RESET_VALUE;
	SIO0->ICR 		= SIO_RESET_VALUE;
}
/*************************************************************/
//SIO IO Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void SIO_IO_Init(SIO_IOG_TypeDef IOGx)
{
	if(IOGx==SIO_PA02)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFFF0FF)|0x00000400;
	}
	if(IOGx==SIO_PA03)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFFFF0FFF)|0x00008000;
	}
	if(IOGx==SIO_PA012)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFF0FFFF)|0x00080000;
	}
	if(IOGx==SIO_PB01)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFF0F)|0x00000070;
	}
}
/*************************************************************/
//SIO TX Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void SIO_TX_Init(SIO_CLK_TypeDef CLKX,U8_T TCKPRSX)
{
	SIO0->CR =CLKX | (TCKPRSX<<16) |(0X00<<8);
	
}
/*************************************************************/
//SIO TX Configure
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void SIO_TX_Configure(SIO_IDLEST_TypeDef IDLEX,SIO_TXDIR_TypeDef TXDIRX,U8_T TXBUFLENX,U8_T TXCNTX,U8_T D0DURX,U8_T D1DURX,SIO_LENOBH_TypeDef LENOBHX,
					SIO_LENOBL_TypeDef LENOBLX,U8_T HSQX,U8_T LSQX)
{
	SIO0->TXCR0 =IDLEX | TXDIRX | (TXBUFLENX<<4) |(TXCNTX<<8);
	SIO0->TXCR1=(D0DURX<<2)|(D1DURX<<5)|LENOBHX|LENOBLX|(HSQX<<16)|(LSQX<<24);
}
/*************************************************************/
//SIO TX BUFFER SET
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void SIO_TXBUF_Set(U8_T D30,U8_T D28,U8_T D26,U8_T D24,U8_T D22,U8_T D20,U8_T D18,U8_T D16,
					U8_T D14,U8_T D12,U8_T D10,U8_T D08,U8_T D06,U8_T D04,U8_T D02,U8_T D00)
{
	SIO0->TXBUF=(D30<<30)|(D28<<28)|(D26<<26)|(D24<<24)|(D22<<22)|(D20<<20)|(D18<<18)|(D16<<16)|
				(D14<<14)|(D12<<12)|(D10<<10)|(D08<<8)|(D06<<6)|(D04<<4)|(D02<<2)|(D00<<0);
}
/*************************************************************/
//SIO RX Initial
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void SIO_RX_Init(SIO_CLK_TypeDef CLKX,SIO_RXDEB_TypeDef RXDEBX,U8_T DEBCKSX)
{
	SIO0->CR =CLKX | RXDEBX |(0X01<<8) | (DEBCKSX<<4);
}
/*************************************************************/
//SIO RX Basic Configure
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void SIO_RX_Configure0(SIO_BSTSEL_TypeDef BSTSELX,SIO_TRGMODE_TypeDef TRGMX,U8_T SPLCNTX,U8_T EXTRACTX,U8_T HITHRX,
					SIO_ALIGNEN_TypeDef ALIGNX,SIO_RXDIR_TypeDef RXDIRX,SIO_RXMODE_TypeDef RXMODEX,U8_T RXLENX,U8_T RXBUFLENX,U8_T RXKPRSX)
{
	SIO0->RXCR0=BSTSELX|TRGMX|(SPLCNTX<<4)|(EXTRACTX<<10)|(HITHRX<<16)|(ALIGNX)|RXDIRX|RXMODEX;			
	SIO0->RXCR1=(RXLENX)|(RXBUFLENX<<8)|(RXKPRSX<<16);												
}
/*************************************************************/
//SIO RX Configure 1
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void SIO_RX_Configure1(SIO_BREAKEN_TypeDef BREAKX,SIO_BREAKLVL_TypeDef BREAKLVLX,U8_T BREKCNTX,SIO_TORSTEN_TypeDef TORSTX,U8_T TOCNTX)
{
	SIO0->RXCR2=BREAKX|BREAKLVLX|BREKCNTX|TORSTX|TOCNTX;	
}
/*************************************************************/
//SIO inturrpt Configure
//EntryParameter:LPT_IMSCR_X,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void SIO_ConfigInterrupt_CMD(FunctionalStatus NewState,SIO_IMSCR_TypeDef SIO_IMSCR_X)
{
	if (NewState != DISABLE)
	{
		SIO0->IMCR  |= SIO_IMSCR_X;						
	}
	else
	{
		SIO0->IMCR  &= ~SIO_IMSCR_X;					
	}
}
/*************************************************************/
//SIO Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SIO_INT_ENABLE(void)
{
	INTC_ISER_WRITE(SIO_INT);
}
/*************************************************************/
//SIO  Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SIO_INT_DISABLE(void)
{
	INTC_ICER_WRITE(SIO_INT);
}