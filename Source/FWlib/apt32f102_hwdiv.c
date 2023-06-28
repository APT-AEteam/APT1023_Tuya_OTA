/*
  ******************************************************************************
  * @file    apt32f102_gpio.c
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
#include "apt32f102_hwdiv.h"

/* define --------------------------------------------------------------------*/
/* externs--------------------------------------------------------------------*/
/*************************************************************/
//HWDIV RESET CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void HWDIV_DeInit(void)
{
    HWD->DIVIDENT = HWDIV_RESET_VALUE;                     
    HWD->DIVISOR = HWDIV_RESET_VALUE;
    HWD->QUOTIENT = HWDIV_RESET_VALUE;                     
    HWD->REMAIN = HWDIV_RESET_VALUE;
    HWD->CR  = HWDIV_RESET_VALUE; 
}
/*************************************************************/
//HWDIV UNSIGN Configure
//EntryParameter:NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void HWDIV_UNSIGN_CMD(FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		HWD->CR  |= HWDIV_UNSIGN_BIT;						
	}
	else
	{
		HWD->CR &= ~HWDIV_UNSIGN_BIT;					
	}
}
/*************************************************************/
//HWDIV Calculate
//EntryParameter:NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void HWDIV_Calc_UNSIGN(U32_T DIVIDENDx,U32_T DIVISOR_x)
{
	HWD->DIVIDENT=DIVIDENDx;
	HWD->DIVISOR=DIVISOR_x;
}
/*************************************************************/
//HWDIV Calculate result
//EntryParameter:NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
U32_T HWDIV_Calc_Quotient(void)
{
	return HWD->QUOTIENT;
}
/*************************************************************/
//HWDIV Calculate result
//EntryParameter:NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
U32_T HWDIV_Calc_Remain(void)
{
	return HWD->REMAIN;
}
/*************************************************************/ 
void HWDIV_Calc_SIGN(long DIVIDENDx,long DIVISOR_x)
{
	HWD->DIVIDENT=DIVIDENDx;
	HWD->DIVISOR=DIVISOR_x;
}
