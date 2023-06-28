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
#include "apt32f102_lpt.h"

/*************************************************************/
//LPT RESET CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void LPT_DeInit(void)
{
	LPT->CEDR 		= 0xBE980000;
	LPT->RSSR 		= LPT_RESET_VALUE;
	LPT->PSCR 		= LPT_RESET_VALUE;
	LPT->CR	  		= 0X00010010;
	LPT->SYNCR 		= LPT_RESET_VALUE;
	LPT->PRDR 		= LPT_RESET_VALUE;
	LPT->CMP 		= LPT_RESET_VALUE;
	LPT->CNT 		= LPT_RESET_VALUE;
	LPT->TRGFTCR 	= LPT_RESET_VALUE;
	LPT->TRGFTWR 	= LPT_RESET_VALUE;
	LPT->EVTRG 		= LPT_RESET_VALUE;
	LPT->EVPS		= LPT_RESET_VALUE;
	LPT->EVSWF 		= LPT_RESET_VALUE;
	LPT->RISR 		= LPT_RESET_VALUE;
	LPT->MISR 		= LPT_RESET_VALUE;
	LPT->IMCR 		= LPT_RESET_VALUE;
	LPT->ICR 		= LPT_RESET_VALUE;
}
/*************************************************************/
//LPT IO Init
//EntryParameter:LPT_OUT_PA09,LPT_OUT_PB01,LPT_IN_PA10,
//ReturnValue:NONE
/*************************************************************/
void LPT_IO_Init(LPT_IOSET_TypeDef IONAME)
{
	if(IONAME==LPT_OUT_PA09)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFFF0F)|0x00000080;
	}
	if(IONAME==LPT_OUT_PB01)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFF0F)|0x00000080;
	}
	if(IONAME==LPT_IN_PA10)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFF0FF)|0x00000800;
	}
}
/*************************************************************/
//LPT Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void LPT_Configure(LPT_CLK_TypeDef CLKX,LPT_CSS_TypeDef CSSX,LPT_SHDWSTP_TypeDef SHDWSTPX,LPT_PSCDIV_TypeDef PSCDIVX,U8_T FLTCKPRSX,LPT_OPM_TypeDef OPMX)
{
	LPT->CEDR |=CLKX| CSSX| SHDWSTPX| (FLTCKPRSX<<8);
	LPT->PSCR = PSCDIVX;
	LPT->CR |=OPMX;
}
/*************************************************************/
//LPT DEBUG MODE
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void LPT_Debug_Mode(FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		LPT->CEDR  |= LPT_DEBUG_MODE;						
	}
	else
	{
		LPT->CEDR  &= ~LPT_DEBUG_MODE;					
	}
}
/*************************************************************/
//LPT Period / Compare set
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void LPT_Period_CMP_Write(U16_T PRDR_DATA,U16_T CMP_DATA)
{
	LPT->PRDR =PRDR_DATA;
	LPT->CMP =CMP_DATA;
}
/*************************************************************/
//LPT COUNTER set
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void LPT_CNT_Write(U16_T CNT_DATA)
{
	LPT->CNT =CNT_DATA;
}
/*************************************************************/
//LPT read counters
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
U16_T LPT_PRDR_Read(void)
{
    return LPT->PRDR;
}
U16_T LPT_CMP_Read(void)
{
    return LPT->CMP;
}
U16_T LPT_CNT_Read(void)
{
    return LPT->CNT;
}
/*************************************************************/
//LPT ControlSet Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void LPT_ControlSet_Configure(LPT_SWSYN_TypeDef SWSYNX,LPT_IDLEST_TypeDef IDLESTX,LPT_PRDLD_TypeDef PRDLDX,LPT_POL_TypeDef POLX,
							 LPT_FLTDEB_TypeDef FLTDEBX,LPT_PSCLD_TypeDef PSCLDX,LPT_CMPLD_TypeDef CMPLDX)
{
	LPT->CR |= SWSYNX| IDLESTX| PRDLDX| POLX| FLTDEBX| FLTDEBX| CMPLDX;
}
/*************************************************************/
//LPT SYNC Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void LPT_SyncSet_Configure(LPT_TRGENX_TypeDef TRGENX,LPT_OSTMDX_TypeDef OSTMDX,LPT_AREARM_TypeDef AREARMX)
{
	LPT->SYNCR |= TRGENX| OSTMDX| AREARMX;
}
/*************************************************************/
//LPT Trigger Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void LPT_Trigger_Configure(LPT_SRCSEL_TypeDef SRCSELX,LPT_BLKINV_TypeDef BLKINVX,LPT_CROSSMD_TypeDef CROSSMDX,LPT_TRGSRC0_TypeDef TRGSRC0X,
						LPT_ESYN0OE_TypeDef ESYN0OEX,U16_T OFFSET_DATA,U16_T WINDOW_DATA,U8_T TRGEC0PRD_DATA)
{
	LPT->TRGFTCR |= SRCSELX| BLKINVX| CROSSMDX;
	LPT->TRGFTWR |= OFFSET_DATA |(WINDOW_DATA<<16);
	LPT->EVTRG |= TRGSRC0X |ESYN0OEX;
	LPT->EVPS |=TRGEC0PRD_DATA;
}
void LPT_Trigger_EVPS(U8_T TRGEC0PRD_DATA,U8_T TRGEV0CNT_DATA)
{
	LPT->EVPS |= TRGEC0PRD_DATA |(TRGEV0CNT_DATA<<16);
}
void LPT_Trigger_Cnt(U8_T TRGEV0CNT_DATA)
{
	LPT->EVPS |= (TRGEV0CNT_DATA<<16);
}
void LPT_Soft_Trigger(void)
{
	LPT->EVSWF = 0X01;
}
/*************************************************************/
// LPT start
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void LPT_Start(void)
{
	LPT->RSSR |= 0X01;
}
/*************************************************************/
// LPT stop
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void LPT_Stop(void)
{
	LPT->RSSR &= 0XFFFFFFFE;
}
/*************************************************************/
// LPT soft reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void LPT_Soft_Reset(void)
{
	LPT->RSSR |= (0X5<<12);
}
/*************************************************************/
// LPT soft reset at once sync mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void LPT_REARM_Write(void)
{
	LPT->SYNCR |= (0X1<<16);
}
/*************************************************************/
// LPT soft read at once sync mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
U8_T LPT_REARM_Read(void)
{
	uint8_t value = 0;
    uint32_t dat = 0;
    dat=(LPT->SYNCR)&(1<<16);
    if (dat)								
	{
	    value = 1;
	} 
    return value;
}
/*************************************************************/
//LPT inturrpt Configure
//EntryParameter:LPT_IMSCR_X,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void LPT_ConfigInterrupt_CMD(FunctionalStatus NewState,LPT_IMSCR_TypeDef LPT_IMSCR_X)
{
	if (NewState != DISABLE)
	{
		LPT->IMCR  |= LPT_IMSCR_X;						
	}
	else
	{
		LPT->IMCR  &= ~LPT_IMSCR_X;					
	}
}

/*************************************************************/
//LPT Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LPT_INT_ENABLE(void)
{
	INTC_ISER_WRITE(LPT_INT);
}
/*************************************************************/
//LPT Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void LPT_INT_DISABLE(void)
{
	INTC_ICER_WRITE(LPT_INT);
}