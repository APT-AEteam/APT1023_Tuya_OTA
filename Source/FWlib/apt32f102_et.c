/*
  ******************************************************************************
  * @file    apt32f102_et.c
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
#include "apt32f102_et.h"


/*************************************************************/
//ET RESET CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void ET_DeInit(void)
{
	ETCB->EN 			= ET_RESET_VALUE;
	ETCB->SWTRG 		= ET_RESET_VALUE;
	ETCB->CH0CON0 		= ET_RESET_VALUE;
	ETCB->CH0CON1	  	= ET_RESET_VALUE;
	ETCB->CH1CON0 		= ET_RESET_VALUE;
	ETCB->CH1CON1 		= ET_RESET_VALUE;
	ETCB->CH2CON0 		= ET_RESET_VALUE;
	ETCB->CH2CON1 		= ET_RESET_VALUE;
	ETCB->CH3CON	 	= ET_RESET_VALUE;
	ETCB->CH4CON	 	= ET_RESET_VALUE;
	ETCB->CH5CON	 	= ET_RESET_VALUE;
	ETCB->CH6CON	 	= ET_RESET_VALUE;
	ETCB->CH7CON	 	= ET_RESET_VALUE;
}
/*************************************************************/
//ET ENABLE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void ET_ENABLE(void)
{
	ETCB->EN	=	0x01;
}
/*************************************************************/
//ET DISABLE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void ET_DISABLE(void)
{
	ETCB->EN	=	0x00;
}
/*************************************************************/
//ET SWTRG Configure
//EntryParameter:ETSWTRG_X,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ET_SWTRG_CMD(CRC_ETSWTRG_TypeDef ETSWTRG_X,FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		ETCB->SWTRG  |= ETSWTRG_X;						
	}
	else
	{
		ETCB->SWTRG  &= ~ETSWTRG_X;					
	}
}
/*************************************************************/
//ET CH0 source selection Configure
//EntryParameter:ETSWTRG_X,NewState,SRCSEL_X
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ET_CH0_SRCSEL(CRC_ESRCSEL_TypeDef ESRCSEL_X,FunctionalStatus NewState,U8_T SRCSEL_X)
{
	if (NewState != DISABLE)
	{
		if(ESRCSEL_X==0)
		{
			ETCB->CH0CON0  |= 0X01| (SRCSEL_X<<1);
		}
		if(ESRCSEL_X==1)
		{
			ETCB->CH0CON0  |= (0X01<<10)| (SRCSEL_X<<11);
		}
		if(ESRCSEL_X==2)
		{
			ETCB->CH0CON0  |= (0X01<<20)| (SRCSEL_X<<21);
		}
	}
	else
	{
		if(ESRCSEL_X==0)
		{
			ETCB->CH0CON0  &= 0X01| (SRCSEL_X<<1);
		}
		if(ESRCSEL_X==1)
		{
			ETCB->CH0CON0  &= (0X00<<10)| (SRCSEL_X<<11);
		}
		if(ESRCSEL_X==2)
		{
			ETCB->CH0CON0  &= (0X00<<20)| (SRCSEL_X<<21);
		}				
	}
}
/*************************************************************/
//ET CHO CONTROL Configure
//EntryParameter:NewState,TRIGMODEX,DSTSEL_X
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ET_CH0_CONTROL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T DSTSEL_X)
{
	if (NewState != DISABLE)
	{
		ETCB->CH0CON1  |= 0x01| (DSTSEL_X<<26)| TRIGMODEX;
	}
	else
	{
		ETCB->CH0CON1  &= 0x00| (DSTSEL_X<<26)| TRIGMODEX;
	}
	
}
/*************************************************************/
//ET CHI1 source selection Configure
//EntryParameter:ETSWTRG_X,NewState,SRCSEL_X
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ET_CH1_SRCSEL(CRC_DSTSEL_TypeDef DST_X,FunctionalStatus NewState,U8_T DSTSEL_X)
{
	if (NewState != DISABLE)
	{
		if(DST_X==0)
		{
			ETCB->CH1CON0  |= 0X01| (DSTSEL_X<<1);
		}
		if(DST_X==1)
		{
			ETCB->CH1CON0  |= (0X01<<10)| (DSTSEL_X<<11);
		}
		if(DST_X==2)
		{
			ETCB->CH1CON0  |= (0X01<<20)| (DSTSEL_X<<21);
		}
	}
	else
	{
		if(DST_X==0)
		{
			ETCB->CH1CON0  &= 0X01| (DSTSEL_X<<1);
		}
		if(DST_X==1)
		{
			ETCB->CH1CON0  &= (0X00<<10)| (DSTSEL_X<<11);
		}
		if(DST_X==2)
		{
			ETCB->CH1CON0  &= (0X00<<20)| (DSTSEL_X<<21);
		}				
	}
}
/*************************************************************/
//ET CH1 CONTROL Configure
//EntryParameter:NewState,TRIGMODEX,SRCSEL_X
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ET_CH1_CONTROL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T DSTSEL_X)
{
	if (NewState != DISABLE)
	{
		ETCB->CH1CON1  |= 0x01| (DSTSEL_X<<26)| TRIGMODEX;
	}
	else
	{
		ETCB->CH1CON1  &= 0x00| (DSTSEL_X<<26)| TRIGMODEX;
	}
	
}
/*************************************************************/
//ET CHI2 source selection Configure
//EntryParameter:ETSWTRG_X,NewState,SRCSEL_X
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ET_CH2_SRCSEL(CRC_DSTSEL_TypeDef DST_X,FunctionalStatus NewState,U8_T DSTSEL_X)
{
	if (NewState != DISABLE)
	{
		if(DST_X==0)
		{
			ETCB->CH2CON0  |= 0X01| (DSTSEL_X<<1);
		}
		if(DST_X==1)
		{
			ETCB->CH2CON0  |= (0X01<<10)| (DSTSEL_X<<11);
		}
		if(DST_X==2)
		{
			ETCB->CH2CON0  |= (0X01<<20)| (DSTSEL_X<<21);
		}
	}
	else
	{
		if(DST_X==0)
		{
			ETCB->CH2CON0  &= 0X01| (DSTSEL_X<<1);
		}
		if(DST_X==1)
		{
			ETCB->CH2CON0  &= (0X00<<10)| (DSTSEL_X<<11);
		}
		if(DST_X==2)
		{
			ETCB->CH2CON0  &= (0X00<<20)| (DSTSEL_X<<21);
		}				
	}
}
/*************************************************************/
//ET CH2 CONTROL Configure
//EntryParameter:NewState,TRIGMODEX,SRCSEL_X
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ET_CH2_CONTROL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T DSTSEL_X)
{
	if (NewState != DISABLE)
	{
		ETCB->CH2CON1  |= 0x01| (DSTSEL_X<<26)| TRIGMODEX;
	}
	else
	{
		ETCB->CH2CON1  &= 0x00| (DSTSEL_X<<26)| TRIGMODEX;
	}
	
}
/*************************************************************/
//ET CH3~7 source selection/CONTROL Configure
//EntryParameter:NewState,TRIGMODEX,SRCSEL_X
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ET_CHx_CONTROL(CRC_ETCHX_TypeDef ETCHX,FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T SRCSEL_X,U8_T DSTSEL_X)
{
	if (NewState != DISABLE)
	{
		if(ETCHX==0)ETCB->CH3CON  |= 0x01|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
		if(ETCHX==1)ETCB->CH4CON  |= 0x01|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
		if(ETCHX==2)ETCB->CH5CON  |= 0x01|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
		if(ETCHX==3)ETCB->CH6CON  |= 0x01|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
		if(ETCHX==4)ETCB->CH7CON  |= 0x01|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
	}
	else
	{
		if(ETCHX==0)ETCB->CH3CON  &= 0x00|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
		if(ETCHX==1)ETCB->CH4CON  &= 0x00|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
		if(ETCHX==2)ETCB->CH5CON  &= 0x00|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
		if(ETCHX==3)ETCB->CH6CON  &= 0x00|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
		if(ETCHX==4)ETCB->CH7CON  &= 0x00|(SRCSEL_X<<12)| (DSTSEL_X<<26)| TRIGMODEX;
	}
}