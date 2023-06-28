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
#include "apt32f102_gpt.h"


/*************************************************************/
//GPT RESET CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void GPT_DeInit(void)
{
	GPT0->CEDR 		= 0xBE980000;
	GPT0->RSSR 		= GPT_RESET_VALUE;
	GPT0->PSCR 		= GPT_RESET_VALUE;
	GPT0->CR 		= 0X00010010;
	GPT0->SYNCR 	= GPT_RESET_VALUE;
	GPT0->GLDCR 	= GPT_RESET_VALUE;
	GPT0->GLDCFG 	= GPT_RESET_VALUE;
	GPT0->GLDCR2 	= GPT_RESET_VALUE;
	GPT0->PRDR 		= GPT_RESET_VALUE;
	GPT0->CMPA 		= GPT_RESET_VALUE;
	GPT0->CMPB 		= GPT_RESET_VALUE;
	GPT0->CMPLDR 	= 0X00002490;
	GPT0->CNT 		= GPT_RESET_VALUE;
	GPT0->AQLDR 	= 0X00000024;
	GPT0->AQCRA 	= GPT_RESET_VALUE;
	GPT0->AQCRB 	= GPT_RESET_VALUE;
	GPT0->AQOSF	 	= 0X00000100;
	GPT0->AQCSF 	= GPT_RESET_VALUE;
	GPT0->TRGFTCR 	= GPT_RESET_VALUE;
	GPT0->TRGFTWR	= GPT_RESET_VALUE;
	GPT0->EVTRG 	= GPT_RESET_VALUE;
	GPT0->EVPS 		= GPT_RESET_VALUE;
	GPT0->EVCNTINIT = GPT_RESET_VALUE;
	GPT0->EVSWF 	= GPT_RESET_VALUE;
	GPT0->RISR		= GPT_RESET_VALUE;
	GPT0->MISR 		= GPT_RESET_VALUE;
	GPT0->IMCR 		= GPT_RESET_VALUE;
	GPT0->ICR 		= GPT_RESET_VALUE;
	GPT0->REGLINK 	= GPT_RESET_VALUE;
}
/*************************************************************/
//GPT IO Init
//EntryParameter:GPT_CHA_PB01,GPT_CHA_PA09,GPT_CHA_PA010,GPT_CHB_PA010,GPT_CHB_PA011,GPT_CHB_PB00,GPT_CHB_PB01
//ReturnValue:NONE
/*************************************************************/
void GPT_IO_Init(GPT_IOSET_TypeDef IONAME)
{
	if(IONAME==GPT_CHA_PB01)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFF0F)|0x00000050;
	}
	if(IONAME==GPT_CHA_PA09)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFFF0F)|0x00000050;
	}
	if(IONAME==GPT_CHA_PA010)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFF0FF)|0x00000600;
	}
	if(IONAME==GPT_CHB_PA010)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFFF0FF)|0x00000700;
	}
	if(IONAME==GPT_CHB_PA011)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFF0FFF)|0x00006000;
	}
	if(IONAME==GPT_CHB_PB00)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFFF0)|0x00000004;
	}
	if(IONAME==GPT_CHB_PB01)
	{
		GPIOB0->CONLR=(GPIOB0->CONLR & 0XFFFFFF0F)|0x00000060;
	}
}

/*************************************************************/
//GPT Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPT_Configure(GPT_CLK_TypeDef GPTCLKX,GPT_CSS_TypeDef GCSSX,GPT_SHDWSTP_TypeDef GSHDWSTPX,U16_T GPSCX)
{
	GPT0->CEDR = GPTCLKX| GCSSX|GSHDWSTPX;
	GPT0->PSCR=GPSCX;
}
/*************************************************************/
//GPT Wave control Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
//GPT0->CR = (0X0<<0)|(0x00<<2)|(0x01<<3)|(0x00<<4)|(0X00<<6)|(0x01<<18)|(0x00<<9)|(0X00<<10)|(0x00<<11)|(0x00<<13) ;	
//GPT0->CMPLDR=(0X00<<0)|(0X00<<1)|(0X03<<4)|(0X03<<7);
void GPT_WaveCtrl_Configure(GPT_CNTMD_TypeDef GCNTMDX,GPT_SWSYN_TypeDef GSWSYNX,GPT_IDLEST_TypeDef GIDLEX,GPT_PRDLD0_TypeDef GPRDLD0,GPT_OPM_TypeDef GOPMX,
						GPT_BURST_TypeDef GBURSTX,GPT_CKS_TypeDef GCKS,GPT_CGSRC_TypeDef CGSRCX,GPT_CGFLT_TypeDef CGFLT,GPT_PSCLD_TypeDef PSCLDX)
{
	GPT0->CR =GCNTMDX|GSWSYNX|GIDLEX|GPRDLD0|GOPMX|GBURSTX|GCKS|CGSRCX|CGFLT|PSCLDX|GPT_WAVE_MODE;
}
/*************************************************************/
//GPT Wave control Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPT_WaveLoad_Configure(GPT_SHDWAQA_TypeDef SHDWAQAX,GPT_SHDWAQB_TypeDef SHDWAQBX,GPT_AQLDA_TypeDef AQLDAX, GPT_AQLDB_TypeDef AQLDBX)
{
	GPT0->AQLDR=SHDWAQAX|SHDWAQBX|AQLDAX|AQLDBX;
}
/*************************************************************/
//GPT Wave A OUT Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPT_WaveOut_Configure(GPT_GPTCHX_TypeDef GPTCHX,GPT_CASEL_TypeDef CASELX,GPT_CBSEL_TypeDef CBSELX,U8_T ZROX,U8_T PRDX,U8_T CAUX,
						U8_T CADX,U8_T CBUX,U8_T CBDX,U8_T T1UX,U8_T T1DX,U8_T T2UX,U8_T T2DX)
{
	if(GPTCHX==GPT_CHA)
	{
	GPT0->AQCRA=CASELX|CBSELX|(ZROX<<0)|(PRDX<<2)|(CAUX<<4)|(CADX<<6)|(CBUX<<8)|(CBDX<<10)|(T1UX<<12)|(T1DX<<14)|(T2UX<<16)|(T2DX<<18);
	}
	if(GPTCHX==GPT_CHB)
	{
	GPT0->AQCRB=CASELX|CBSELX|(ZROX<<0)|(PRDX<<2)|(CAUX<<4)|(CADX<<6)|(CBUX<<8)|(CBDX<<10)|(T1UX<<12)|(T1DX<<14)|(T2UX<<16)|(T2DX<<18);
	}
}
/*************************************************************/
//GPT OneceForce Out
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPT_OneceForce_Out(GPT_CHAFORCE_TypeDef CHAFORCEX,U8_T AFORCE_STATUS,GPT_CHBFORCE_TypeDef CHBFORCEX,U8_T BFORCE_STATUS,GPT_FORCELD_TypeDef FORCELDX)
{
	GPT0->AQOSF =CHAFORCEX|CHBFORCEX|FORCELDX|(AFORCE_STATUS<<1)|(BFORCE_STATUS<<5);
}
/*************************************************************/
//GPT Continue Force Out
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPT_Force_Out(GPT_FORCEA_TypeDef FORCEAX,GPT_FORCEB_TypeDef FORCEBX)
{
	GPT0->AQCSF =FORCEAX|FORCEBX;
}
/*************************************************************/
//GPT Wave Compare Load Init
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPT_CmpLoad_Configure(GPT_SHDWCMPA_TypeDef SHDWCMPAX,GPT_SHDWCMPB_TypeDef SHDWCMPBX,GPT_LDAMD_TypeDef LDAMDX,GPT_LDBMD_TypeDef LDBMDX)
{
	GPT0->CMPLDR=SHDWCMPAX|SHDWCMPBX|LDAMDX|LDBMDX;
}
/*************************************************************/
//GPT DEBUG MODE
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPT_Debug_Mode(FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		GPT0->CEDR  |= GPT_DEBUG_MODE;						
	}
	else
	{
		GPT0->CEDR  &= ~GPT_DEBUG_MODE;					
	}
}
/*************************************************************/
// GPT start
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_Start(void)
{
	GPT0->RSSR |= 0X01;
}
/*************************************************************/
// GPT stop
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_Stop(void)
{
	GPT0->RSSR &= 0XFFFFFFFE;
}
/*************************************************************/
// GPT soft reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_Soft_Reset(void)
{
	GPT0->RSSR |= (0X5<<12);
}
/*************************************************************/
// GPT Capture rearm
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_Cap_Rearm(void)
{
	GPT0->CR |= (0X01<<19);
}
/*************************************************************/
// GPT MODE
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_Mode_CMD(GPT_WAVE_TypeDef WAVEX)
{
	GPT0->CR |= WAVEX;
}
/*************************************************************/
// GPT soft reset at once sync mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_REARM_Write(void)
{
	GPT0->SYNCR |= (0X1<<16);
}
/*************************************************************/
// GPT soft read at once sync mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
U8_T GPT_REARM_Read(void)
{
	uint8_t value = 0;
    uint32_t dat = 0;
    dat=(GPT0->SYNCR)&(1<<16);
    if (dat)								
	{
	    value = 1;
	} 
    return value;
}
/*************************************************************/
//GPT Period / Compare set
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
void GPT_Period_CMP_Write(U16_T PRDR_DATA,U16_T CMPA_DATA,U16_T CMPB_DATA)
{
	GPT0->PRDR =PRDR_DATA;
	GPT0->CMPA =CMPA_DATA;
	GPT0->CMPB =CMPB_DATA;
}
/*************************************************************/
//GPT read counters
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/
U16_T GPT_PRDR_Read(void)
{
    return GPT0->PRDR;
}
U16_T GPT_CMPA_Read(void)
{
    return GPT0->CMPA;
}
U16_T GPT_CMPB_Read(void)
{
    return GPT0->CMPB;
}
U16_T GPT_CNT_Read(void)
{
    return GPT0->CNT;
}
/*************************************************************/
//GPT inturrpt Configure
//EntryParameter:LPT_IMSCR_X,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void GPT_ConfigInterrupt_CMD(FunctionalStatus NewState,U32_T GPT_IMSCR_X)
{
	if (NewState != DISABLE)
	{
		GPT0->IMCR  |= GPT_IMSCR_X;						
	}
	else
	{
		GPT0->IMCR  &= ~GPT_IMSCR_X;					
	}
}

/*************************************************************/
//GPT Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPT_INT_ENABLE(void)
{
	INTC_ISER_WRITE(GPT0_INT);
}
/*************************************************************/
//LPT Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPT_INT_DISABLE(void)
{
	INTC_ICER_WRITE(GPT0_INT);
}

	