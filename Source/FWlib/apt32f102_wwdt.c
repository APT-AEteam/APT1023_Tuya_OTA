/*
  ******************************************************************************
  * @file    apt32f102_wwdt.c
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
#include "apt32f102_wwdt.h"


/*************************************************************/
//WWDT RESET CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void WWDT_DeInit(void)
{
	WWDT->CR 	= 0x000000FF;
	WWDT->CFGR 	= 0x000000FF;
	WWDT->RISR 	= WWDT_RESET_VALUE;
	WWDT->MISR	= WWDT_RESET_VALUE;
	WWDT->IMCR 	= WWDT_RESET_VALUE;
	WWDT->ICR 	= WWDT_RESET_VALUE;
}
/*************************************************************/
//WWDT CONFIG
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void WWDT_CONFIG(WWDT_PSCDIV_TypeDef PSCDIVX,U8_T WND_DATA,WWDT_DBGEN_TypeDef DBGENX)
{
	WWDT->CFGR =WND_DATA;
	WWDT->CFGR |= PSCDIVX |DBGENX;
}
/*************************************************************/
//WWDT ENABLE/DISABLE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void WWDT_CMD(FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		WWDT->CR  |= 0x01<<8;						
	}
	else
	{
		WWDT->CR  &= 0xfffffeff;					
	}
}
/*************************************************************/
//WWDT load data
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void WWDT_CNT_Load(U8_T cnt_data)
{
	WWDT->CR  |= cnt_data;						//SET
}
/*************************************************************/
//WWDT INT ENABLE/DISABLE
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void WWDT_Int_Config(FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		WWDT->ICR = WWDT_EVI;				
		WWDT->IMCR  |= WWDT_EVI;
		INTC_ISER_WRITE(WWDT_INT);  
	}
	else
	{
		WWDT->IMCR  &= ~WWDT_EVI;					//CLR
		INTC_ICER_WRITE(WWDT_INT);  
	}
}