/*
  ******************************************************************************
  * @file    apt32f102_ept.c
  * @author  APT AE Team
  * @version V0.50
  * @date    2020/05/29
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
#include "apt32f102_ept.h"
/* define --------------------------------------------------------------------*/
/* externs--------------------------------------------------------------------*/
/*************************************************************/
//Deinitializes the EPT Software prg
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/    
void EPT_Software_Prg(void)
{
	EPT0->CEDR|=0X01;
	EPT0->RSSR=(EPT0->RSSR&0XFFFF0FFF)|(0X05<<12);
}
/*************************************************************/
//Deinitializes the EPT start prg
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/   
void EPT_Start(void)
{
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->RSSR|=0X01;
	while(!(EPT0->RSSR&0x01));
} 
/*************************************************************/
//Deinitializes the EPT stop prg
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/   
void EPT_Stop(void)
{
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->RSSR&=0Xfe;
	while(EPT0->RSSR&0x01);
}
/*************************************************************/
//Deinitializes the EPT IO Config,IO_Num_X
//EntryParameter:EPT_IO_Mode_Type
//EPT_IO_X:EPT_IO_CHAX,EPT_IO_CHAY,EPT_IO_CHBX,EPT_IO_CHBY,EPT_IO_CHCX,EPT_IO_CHCX,EPT_IO_CHD,EPT_IO_EPI
//ReturnValue:NONE
/*************************************************************/    
void EPT_IO_SET(EPT_IO_Mode_Type EPT_IO_X , EPT_IO_NUM_Type IO_Num_X)
{
	if(EPT_IO_X==EPT_IO_CHAX)
	{
		if(IO_Num_X==IO_NUM_PA07)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF)|0X60000000;				//PA0.7
		}
		else if(IO_Num_X==IO_NUM_PA10)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFF0FF)|0X00000500;				//PA0.10
		}
		else if(IO_Num_X==IO_NUM_PA15)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0X0FFFFFFF)|0X40000000;				//PA0.15
		}
	}
	else if(EPT_IO_X==EPT_IO_CHAY)
	{
		if(IO_Num_X==IO_NUM_PB03)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFF0FFF)|0X00005000;				//PB0.3
		}
		else if(IO_Num_X==IO_NUM_PB05)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFF0FFFFF)|0X00400000;				//PB0.5
		}
		else if(IO_Num_X==IO_NUM_PA12)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFF0FFFF)|0X00050000;				//PA0.12
		}
	}
	else if(EPT_IO_X==EPT_IO_CHBX)
	{
		if(IO_Num_X==IO_NUM_PB02)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFF0FF)|0X00000600;				//PB0.2
		}
		else if(IO_Num_X==IO_NUM_PA11)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFF0FFF)|0X00005000;				//PA0.11
		}
		else if(IO_Num_X==IO_NUM_PA14)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XF0FFFFFF)|0X04000000;				//PA0.14
		}
	}
	else if(EPT_IO_X==EPT_IO_CHBY)
	{
		if(IO_Num_X==IO_NUM_PB04)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFF0FFFF)|0X00050000;				//PB0.4
		}
		else if(IO_Num_X==IO_NUM_PA05)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFF0FFFFF)|0X00800000;				//PA0.5
		}
		else if(IO_Num_X==IO_NUM_PA08)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)|0X00000005;				//PA0.8
		}
	}
	else if(EPT_IO_X==EPT_IO_CHCX)
	{
		if(IO_Num_X==IO_NUM_PB05)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFF0FFFFF)|0X00400000;				//PB0.5
		}
		else if(IO_Num_X==IO_NUM_PA03)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)|0X00005000;				//PA0.3
		}
		else if(IO_Num_X==IO_NUM_PB03)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFF0FFF)|0X00004000;				//PB0.3
		}
		else if(IO_Num_X==IO_NUM_PB00)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFF0)|0X00000005;				//PB0.0
		}
	}
	else if(EPT_IO_X==EPT_IO_CHCY)
	{
		if(IO_Num_X==IO_NUM_PB04)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFF0FFFF)|0X00040000;				//PB0.4
		}
		else if(IO_Num_X==IO_NUM_PA04)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF0FFFF)|0X00050000;				//PA0.4
		}
		else if(IO_Num_X==IO_NUM_PA09)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFF0F)|0X00000070;				//PA0.9
		}
		else if(IO_Num_X==IO_NUM_PA013)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFF0FFFFF)|0X00500000;				//PA0.13
		}
	}
	else if(EPT_IO_X==EPT_IO_CHD)
	{
		if(IO_Num_X==IO_NUM_PB03)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFF0FFF)|0X00006000;				//PB0.3
		}
		else if(IO_Num_X==IO_NUM_PA08)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)|0X00000004;				//PA0.8
		}
	}
	else if(EPT_IO_X==EPT_IO_EPI)
	{
		if(IO_Num_X==IO_NUM_PA07)
		{
			GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF)|0X50000000;				//PA0.7 EPI0
		}
		else if(IO_Num_X==IO_NUM_PA013)
		{
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFF0FFFFF)|0X00400000;				//PA0.13 EPI1
		}
		else if(IO_Num_X==IO_NUM_PB03)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFF0FFF)|0X00007000;				//PB0.3 EPI2
		}
		else if(IO_Num_X==IO_NUM_PB02)
		{
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFF0FF)|0X00000700;				//PB0.2 EPI3
		}
	}
}
/*************************************************************/
//Deinitializes the EPT PWM Config
//EntryParameter:EPT_TCLK_Selecte_X,EPT_CNTMD_SELECTE_X,EPT_OPM_SELECTE_X,EPT_PSCR
//EPT_TCLK_Selecte_X:EPT_Selecte_PCLK,EPT_Selecte_SYNCUSR3
//EPT_CNTMD_SELECTE_X:EPT_CNTMD_increase,EPT_CNTMD_decrease,EPT_CNTMD_increaseTOdecrease
//EPT_OPM_SELECTE_X:EPT_OPM_Once,EPT_OPM_Continue
//EPT_PSCR:0~0XFFFF
//ReturnValue:NONE
/*************************************************************/  
//Fclk=Fpclk/(PSC+1)
void EPT_PWM_Config(EPT_TCLK_Selecte_Type EPT_TCLK_Selecte_X , EPT_CNTMD_SELECTE_Type EPT_CNTMD_SELECTE_X  , EPT_OPM_SELECTE_Type EPT_OPM_SELECTE_X
					, U16_T EPT_PSCR)		
//start选immediate模式,debug挂起PWM输出高阻,pwm停止时输出高阻,start控制位同步触发,ZRO载入PSCR(bit17:bit16)
{
	EPT0->CEDR=(EPT0->CEDR&0XFFFFFF00)|(0X01|EPT_TCLK_Selecte_X|(0X01<<1)|(0X00<<6));
	if(EPT_TCLK_Selecte_X==EPT_Selecte_PCLK)
	{
		EPT0->PSCR=EPT_PSCR;
	}
	EPT0->CR=(EPT0->CR&0xfff8ffc0)|EPT_CNTMD_SELECTE_X|(0x1<<2)|(0x0<<3)|(0x0<<4)|EPT_OPM_SELECTE_X|(0X0<<16)|(0x1<<18);
} 
/*************************************************************/
//Deinitializes the EPT Caputer Config
//EntryParameter:EPT_TCLK_Selecte_X,EPT_CNTMD_SELECTE_X,EPT_CAPMD_SELECTE_X,EPT_LOAD_CMPA_RST_CMD~EPT_LOAD_CMPD_RST_CMD,EPT_STOP_WRAP,EPT_PSCR
//EPT_TCLK_Selecte_X:EPT_Selecte_PCLK,EPT_Selecte_SYNCUSR3
//EPT_CNTMD_SELECTE_X:EPT_CNTMD_increase,EPT_CNTMD_decrease,EPT_CNTMD_increaseTOdecrease
//EPT_CAPMD_SELECTE_X:EPT_CAPMD_Once,EPT_CAPMD_Continue
//EPT_LOAD_CMPA_RST_CMD:EPT_LDARST_EN,EPT_LDARST_DIS
//EPT_LOAD_CMPB_RST_CMD:EPT_LDBRST_EN,EPT_LDBRST_DIS
//EPT_LOAD_CMPC_RST_CMD:EPT_LDCRST_EN,EPT_LDCRST_DIS
//EPT_LOAD_CMPD_RST_CMD:EPT_LDDRST_EN,EPT_LDDRST_DIS
//EPT_STOP_WRAP:0~3
//EPT_PSCR:0~0XFFFF
//ReturnValue:NONE
/*************************************************************/  
void EPT_Capture_Config(EPT_TCLK_Selecte_Type EPT_TCLK_Selecte_X , EPT_CNTMD_SELECTE_Type EPT_CNTMD_SELECTE_X  , EPT_CAPMD_SELECTE_Type EPT_CAPMD_SELECTE_X , EPT_CAPLDEN_CMD_Type CAP_CMD 
					, EPT_LOAD_CMPA_RST_CMD_Type EPT_LOAD_CMPA_RST_CMD , EPT_LOAD_CMPB_RST_CMD_Type EPT_LOAD_CMPB_RST_CMD , EPT_LOAD_CMPC_RST_CMD_Type EPT_LOAD_CMPC_RST_CMD
					, EPT_LOAD_CMPD_RST_CMD_Type EPT_LOAD_CMPD_RST_CMD , U8_T EPT_STOP_WRAP , U16_T EPT_PSCR)
{
	EPT0->CEDR=(EPT0->CEDR&0XFFFFFF00)|(0X01|EPT_TCLK_Selecte_X|(0X01<<1)|(0X00<<6));
	if(EPT_TCLK_Selecte_X==EPT_Selecte_PCLK)
	{
		EPT0->PSCR=EPT_PSCR;
	}
	EPT0->CR=(EPT0->CR&0xf800fec0)|EPT_CNTMD_SELECTE_X|(0x0<<2)|(0x0<<3)|(0x0<<4)|CAP_CMD|EPT_CAPMD_SELECTE_X|(0X0<<16)|(0x0<<18)|(EPT_STOP_WRAP<<21)|
				EPT_LOAD_CMPA_RST_CMD|EPT_LOAD_CMPB_RST_CMD|EPT_LOAD_CMPC_RST_CMD|EPT_LOAD_CMPD_RST_CMD;
}
/*************************************************************/
//Deinitializes the EPT FLT Config
//EntryParameter:FLTCKPRS,EPT_FLT_CMD,EPT_FLT_X
//FLTCKPRS:0~0XFF
//EPT_FLT_CMD:EPT_FLT_EN,EPT_FLT_DIS
//EPT_FLT_X:EPT_FLT_BYPASS,EPT_FLT_2,EPT_FLT_3,EPT_FLT_4,EPT_FLT_6,EPT_FLT_8,EPT_FLT_16,EPT_FLT_32
//ReturnValue:NONE
/*************************************************************/  
//FLTCLK=PCLK/(FLTCKPRS+1)
void EPT_FLT_Config(EPT_FLT_CMD_Type EPT_FLT_CMD , EPT_FLT_CGFLT_Type  EPT_FLT_X , U8_T FLTCKPRS)
{
	EPT0->CEDR=(EPT0->CEDR&0XFFFF00FF)|(FLTCKPRS<<8);
	EPT0->CR=(EPT0->CR&0xFFFF1DFF)|EPT_FLT_CMD|EPT_FLT_X;
}
/*************************************************************/
//Deinitializes the EPT SYNCR Config
//EntryParameter:EPT_Triggle_X,EPT_SYNCR_EN,EPT_SYNCUSR0_REARMTrig_Selecte,EPT_TRGSRC0_ExtSync_Selected,EPT_TRGSRC1_ExtSync_Selected
//EPT_Triggle_X:EPT_Triggle_Continue,EPT_Triggle_Once
//EPT_SYNCUSR0_REARMTrig_Selecte:EPT_SYNCUSR0_REARMTrig_DIS,EPT_SYNCUSR0_REARMTrig_T1,EPT_SYNCUSR0_REARMTrig_T2
//EPT_SYNCUSR0_REARMTrig_T1T2
//EPT_TRGSRC0_ExtSync_Selected:EPT_TRGSRC0_ExtSync_SYNCUSR0~EPT_TRGSRC0_ExtSync_SYNCUSR5
//EPT_TRGSRC1_ExtSync_Selected:EPT_TRGSRC1_ExtSync_SYNCUSR0~EPT_TRGSRC1_ExtSync_SYNCUSR5
//EPT_SYNCR_EN:0~0X3F
//ReturnValue:NONE
/*************************************************************/  
void EPT_SYNCR_Config(EPT_Triggle_Mode_Type EPT_Triggle_X , EPT_SYNCUSR0_REARMTrig_Selecte_Type EPT_SYNCUSR0_REARMTrig_Selecte , EPT_TRGSRC0_ExtSync_Selected_Type EPT_TRGSRC0_ExtSync_Selected ,
					  EPT_TRGSRC1_ExtSync_Selected_Type EPT_TRGSRC1_ExtSync_Selected , U8_T EPT_SYNCR_EN)
{
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->SYNCR = (EPT0->SYNCR&0XC03F0000) |EPT_SYNCR_EN|EPT_Triggle_X|EPT_SYNCUSR0_REARMTrig_Selecte|EPT_TRGSRC0_ExtSync_Selected|EPT_TRGSRC1_ExtSync_Selected;
}
/*************************************************************/
//Deinitializes the EPT EP0~EP7 Config
//EntryParameter:EPT_EPX,EPT_Input_selecte_x,EPT_FLT_PACE0_x,EPT_FLT_PACE1_x,EPT_EPIX_POL
//EPT_EPX:EPT_EP0,EPT_EP1,EPT_EP2,EPT_EP3,EPT_EP4,EPT_EP5,EPT_EP6,EPT_EP7
//EPT_Input_selecte_x:EPT_Input_selecte_EPI0~EPT_Input_selecte_EPI5,EPT_Input_selecte_ORL0,EPT_Input_selecte_ORL1
//EPT_FLT_PACE0_x:EPT_FLT_PACE0_DIS~EPT_FLT_PACE0_4CLK(EP0~EP3)
//EPT_FLT_PACE1_x:EPT_FLT_PACE1_DIS~EPT_FLT_PACE1_4CLK(EP4~EP7)
//EPT_EPIX_POL:BIT0->EPI0(0:高电平有效 1:低电平有效),BIT1->EPI1(0:高电平有效 1:低电平有效),
//BIT2->EPI2(0:高电平有效 1:低电平有效),BIT3->EPI3(0:高电平有效 1:低电平有效),BIT4->EPI4(0:高电平有效 1:低电平有效)
//ReturnValue:NONE
/*************************************************************/   
void EPT_EPX_Config(EPT_EPX_Type EPT_EPX , EPT_Input_selecte_Type EPT_Input_selecte_x , EPT_FLT_PACE0_Type EPT_FLT_PACE0_x , EPT_FLT_PACE1_Type EPT_FLT_PACE1_x , U8_T EPT_EPIX_POL)
{
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	if(EPT_EPX==EPT_EP0)
	{
		EPT0->EMSRC=(EPT0->EMSRC&0XFFFFFFF0)|(EPT_Input_selecte_EPI0<<0);
	}
	else if(EPT_EPX==EPT_EP1)
	{
		EPT0->EMSRC=(EPT0->EMSRC&0XFFFFFF0F)|(EPT_Input_selecte_EPI0<<4);
	}
	else if(EPT_EPX==EPT_EP2)
	{
		EPT0->EMSRC=(EPT0->EMSRC&0XFFFFF0FF)|(EPT_Input_selecte_EPI0<<8);
	}
	else if(EPT_EPX==EPT_EP3)
	{
		EPT0->EMSRC=(EPT0->EMSRC&0XFFFF0FFF)|(EPT_Input_selecte_EPI0<<12);
	}
	else if(EPT_EPX==EPT_EP4)
	{
		EPT0->EMSRC=(EPT0->EMSRC&0XFFF0FFFF)|(EPT_Input_selecte_EPI0<<16);
	}
	else if(EPT_EPX==EPT_EP5)
	{
		EPT0->EMSRC=(EPT0->EMSRC&0XFF0FFFFF)|(EPT_Input_selecte_EPI0<<20);
	}
	else if(EPT_EPX==EPT_EP6)
	{
		EPT0->EMSRC=(EPT0->EMSRC&0XF0FFFFFF)|(EPT_Input_selecte_EPI0<<24);
	}
	else if(EPT_EPX==EPT_EP7)
	{
		EPT0->EMSRC=(EPT0->EMSRC&0X0FFFFFFF)|(EPT_Input_selecte_EPI0<<28);
	}
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->EMSRC2=0XFF00FF|EPT_FLT_PACE0_x|EPT_FLT_PACE1_x;
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->EMPOL=EPT_EPIX_POL;
}
/*************************************************************/
//Deinitializes the EPT CPCR Config
//EntryParameter:EPT_CPCR_CMD,EPT_CPCR_Source_X,EPT_CDUTY_X,EPT_CPCR_OSPWTH,EPT_CPCR_CDIV
//EPT_CPCR_CMD:EPT_CPCR_ENALBE,EPT_CPCR_Disable
//EPT_CPCR_Source_X:EPT_CPCR_Source_TCLK,EPT_CPCR_Source_TIN_BT0OUT,EPT_CPCR_Source_TIN_BT1OUT
//EPT_CDUTY_X:EPT_CDUTY_7_8~EPT_CDUTY_DIS
//EPT_CPCR_OSPWTH:0~0X1F
//EPT_CPCR_CDIV:0~0xf
//ReturnValue:NONE
/*************************************************************/ 
//Fchop=PCLK/((CDIV+1)/8)载波频率
//Twidth=Tchop*OSPWTH 首脉冲宽度  
void EPT_CPCR_Config(EPT_CPCR_CMD_Type EPT_CPCR_CMD , EPT_CPCR_Source_Selecte_Type EPT_CPCR_Source_X , EPT_CDUTY_Type EPT_CDUTY_X , U8_T EPT_CPCR_OSPWTH , U8_T EPT_CPCR_CDIV)
{
	if(EPT_CPCR_Source_X==EPT_CPCR_Source_TCLK)
	{
		EPT0->CPCR=EPT_CPCR_CMD|(EPT_CPCR_CDIV<<7)|(EPT_CPCR_OSPWTH<<2)|EPT_CDUTY_X|(0x00<<14);
	}
	else
	{
		EPT0->CPCR=EPT_CPCR_CMD|(EPT_CPCR_CDIV<<7)|(EPT_CPCR_OSPWTH<<2)|EPT_CDUTY_X|(0x01<<14);
		if(EPT_CPCR_Source_X==EPT_CPCR_Source_TIN_BT0OUT)
		{
			EPT0->CEDR=(EPT0->CEDR&0xffffffcf)|(0x01<<4);
		}
		if(EPT_CPCR_Source_X==EPT_CPCR_Source_TIN_BT1OUT)
		{
			EPT0->CEDR=(EPT0->CEDR&0xffffffcf)|(0x02<<4);
		}
	}
}
/*************************************************************/
//Deinitializes the EPT DBCR Config
//EntryParameter:EPT_CHX_Selecte,EPT_INSEL_X,EPT_OUTSEL_X,EPT_OUT_POLARITY_X,EPT_OUT_SWAP_X
//EPT_CHX_Selecte:EPT_CHA_Selecte,EPT_CHB_Selecte,EPT_CHC_Selecte
//EPT_INSEL_X:EPT_PWMA_RISE_FALL,EPT_PWMB_RISE_PWMA_FALL,EPT_PWMA_RISE_PWMB_FALL,EPT_PWMB_RISE_FALL
//EPT_OUTSEL_X:EPT_OUTSEL_PWMA_PWMB_Bypass,EPT_OUTSEL_DisRise_EnFall,EPT_OUTSEL_EnRise_DisFall,EPT_OUTSEL_EnRise_EnFall
//EPT_OUT_POLARITY_X:EPT_PA_PB_OUT_Direct,EPT_PA_OUT_Reverse,EPT_PB_OUT_Reverse,EPT_PA_PB_OUT_Reverse
//EPT_OUT_SWAP_X:EPT_PAtoCHX_PBtoCHY,EPT_PBtoCHX_PBtoCHY,EPT_PAtoCHX_PAtoCHY,EPT_PBtoCHX_PAtoCHY
//ReturnValue:NONE
/*************************************************************/   
void EPT_DBCR_Config(EPT_CHX_Selecte_Type EPT_CHX_Selecte , EPT_INSEL_Type EPT_INSEL_X , EPT_OUTSEL_Type EPT_OUTSEL_X , EPT_OUT_POLARITY_Type EPT_OUT_POLARITY_X , EPT_OUT_SWAP_Type EPT_OUT_SWAP_X)
{	
	if(EPT_CHX_Selecte==EPT_CHA_Selecte)
	{
		EPT0->DBCR=(EPT0->DBCR&0XFFFFFF00)|EPT_INSEL_X|EPT_OUTSEL_X|(EPT_OUT_POLARITY_X<<2)|(EPT_OUT_SWAP_X<<6);
	}
	else if(EPT_CHX_Selecte==EPT_CHB_Selecte)
	{
		EPT0->DBCR=(EPT0->DBCR&0XFFFF00FF)|EPT_INSEL_X|EPT_OUTSEL_X|(EPT_OUT_POLARITY_X<<10)|(EPT_OUT_SWAP_X<<14);
	}
	else if(EPT_CHX_Selecte==EPT_CHC_Selecte)
	{
		EPT0->DBCR=(EPT0->DBCR&0XFF00FFFF)|EPT_INSEL_X|EPT_OUTSEL_X|(EPT_OUT_POLARITY_X<<18)|(EPT_OUT_SWAP_X<<22);
	}
	EPT0->DBCR|=0x01<<24;
}
/*************************************************************/
//Deinitializes the EPT DB CLK Config
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/   
//Fdbclk=Fhclk/(DPSC+1)
void EPT_DB_CLK_Config(U16_T DPSC , U16_T DTR , U16_T DTF)
{
	EPT0->DPSCR=DPSC;
	EPT0->DBDTR=DTR;
	EPT0->DBDTF=DTF;
}
/*************************************************************/
//Deinitializes the EPT PWMA~PWMD Control
//EntryParameter:EPT_PWMX_Selecte,EPT_CA_Selecte_X,EPT_CB_Selecte_X,
//EPT_PWMX_Selecte:EPT_PWMA,EPT_PWMB,EPT_PWMC,EPT_PWMD
//EPT_CA_Selecte_X:EPT_CA_Selecte_CMPA,EPT_CA_Selecte_CMPB,EPT_CA_Selecte_CMPC,EPT_CA_Selecte_CMPD
//EPT_CB_Selecte_X:EPT_CB_Selecte_CMPA,EPT_CB_Selecte_CMPB,EPT_CB_Selecte_CMPC,EPT_CB_Selecte_CMPD
//ReturnValue:NONE
/*************************************************************/   
void EPT_PWMX_Output_Control(
							 EPT_PWMX_Selecte_Type EPT_PWMX_Selecte ,EPT_CA_Selecte_Type EPT_CA_Selecte_X , EPT_CB_Selecte_Type EPT_CB_Selecte_X ,
							 EPT_PWM_ZRO_Output_Type EPT_PWM_ZRO_Event_Output , EPT_PWM_PRD_Output_Type EPT_PWM_PRD_Event_Output , 
							 EPT_PWM_CAU_Output_Type EPT_PWM_CAU_Event_Output , EPT_PWM_CAD_Output_Type EPT_PWM_CAD_Event_Output ,
							 EPT_PWM_CBU_Output_Type EPT_PWM_CBU_Event_Output , EPT_PWM_CBD_Output_Type EPT_PWM_CBD_Event_Output ,
							 EPT_PWM_T1U_Output_Type EPT_PWM_T1U_Event_Output , EPT_PWM_T1D_Output_Type EPT_PWM_T1D_Event_Output ,
							 EPT_PWM_T2U_Output_Type EPT_PWM_T2U_Event_Output , EPT_PWM_T2D_Output_Type EPT_PWM_T2D_Event_Output 
							 )
{
	if(EPT_PWMX_Selecte==EPT_PWMA)
	{
		EPT0->AQCRA=EPT_CA_Selecte_X|EPT_CB_Selecte_X|EPT_PWM_ZRO_Event_Output|EPT_PWM_PRD_Event_Output|EPT_PWM_CAU_Event_Output|EPT_PWM_CAD_Event_Output|
					EPT_PWM_CBU_Event_Output|EPT_PWM_CBD_Event_Output|EPT_PWM_T1U_Event_Output|EPT_PWM_T1D_Event_Output|EPT_PWM_T2U_Event_Output|EPT_PWM_T2D_Event_Output;
	}
	else if(EPT_PWMX_Selecte==EPT_PWMB)
	{
		EPT0->AQCRB=EPT_CA_Selecte_X|EPT_CB_Selecte_X|EPT_PWM_ZRO_Event_Output|EPT_PWM_PRD_Event_Output|EPT_PWM_CAU_Event_Output|EPT_PWM_CAD_Event_Output|
					EPT_PWM_CBU_Event_Output|EPT_PWM_CBD_Event_Output|EPT_PWM_T1U_Event_Output|EPT_PWM_T1D_Event_Output|EPT_PWM_T2U_Event_Output|EPT_PWM_T2D_Event_Output;
	}
	else if(EPT_PWMX_Selecte==EPT_PWMC)
	{
		EPT0->AQCRC=EPT_CA_Selecte_X|EPT_CB_Selecte_X|EPT_PWM_ZRO_Event_Output|EPT_PWM_PRD_Event_Output|EPT_PWM_CAU_Event_Output|EPT_PWM_CAD_Event_Output|
					EPT_PWM_CBU_Event_Output|EPT_PWM_CBD_Event_Output|EPT_PWM_T1U_Event_Output|EPT_PWM_T1D_Event_Output|EPT_PWM_T2U_Event_Output|EPT_PWM_T2D_Event_Output;
	}
	else if(EPT_PWMX_Selecte==EPT_PWMD)
	{
		EPT0->AQCRD=EPT_CA_Selecte_X|EPT_CB_Selecte_X|EPT_PWM_ZRO_Event_Output|EPT_PWM_PRD_Event_Output|EPT_PWM_CAU_Event_Output|EPT_PWM_CAD_Event_Output|
					EPT_PWM_CBU_Event_Output|EPT_PWM_CBD_Event_Output|EPT_PWM_T1U_Event_Output|EPT_PWM_T1D_Event_Output|EPT_PWM_T2U_Event_Output|EPT_PWM_T2D_Event_Output;
	}
	
}
/*************************************************************/
//Deinitializes the EPT Tevent selecte
//EntryParameter:EPT_T1_Selecte,EPT_T2_Selecte 
//EPT_T1_Selecte:0->SYNCUSR4,1->EP0,2->EP1,3->EP2,4->EP3,5->EP4,6->EP5,7->EP6
//EPT_T2_Selecte:0->SYNCUSR5,1->EP0,2->EP1,3->EP2,4->EP3,5->EP4,6->EP5,7->EP6
//ReturnValue:NONE
/*************************************************************/
void EPT_Tevent_Selecte( U8_T EPT_T1_Selecte, U8_T EPT_T2_Selecte)
{
	EPT0->AQTSCR=EPT_T1_Selecte|(EPT_T2_Selecte<<4);
}
/*************************************************************/
//Deinitializes the EPT PHSEN Config
//EntryParameter:EPT_PHSEN_CMD,EPT_PHSDIR,PHSR
//EPT_PHSEN_CMD:EPT_PHSEN_EN,EPT_PHSEN_DIS
//EPT_PHSDIR:EPT_PHSDIR_increase,EPT_PHSEN_decrease
//PHSR:0~0xffff
//ReturnValue:NONE
/*************************************************************/  
void EPT_PHSEN_Config(EPT_PHSEN_CMD_Type EPT_PHSEN_CMD , EPT_PHSDIR_Type EPT_PHSDIR , U16_T PHSR)
{
	EPT0->CR=(EPT0->CR&0xffffff7f)|EPT_PHSEN_CMD;
	EPT0->PHSR=PHSR|EPT_PHSDIR;
}
/*************************************************************/
//Deinitializes the EPT PRDR CMPA CMPB CMPC CMPD_Config
//EntryParameter:EPT_PRDR_Value,EPT_CMPA_Value,EPT_CMPB_Value,EPT_CMPC_Value,EPT_CMPD_Value
//EPT_PRDR_Value:0~0xff
//EPT_CMPA_Value:0~0xff
//EPT_CMPB_Value:0~0xff
//EPT_CMPC_Value:0~0xff
//EPT_CMPD_Value:0~0xff
/*************************************************************/ 
void EPT_PRDR_CMPA_CMPB_CMPC_CMPD_Config(U16_T EPT_PRDR_Value , U16_T EPT_CMPA_Value , U16_T EPT_CMPB_Value , U16_T EPT_CMPC_Value , U16_T EPT_CMPD_Value)
{
	EPT0->PRDR=EPT_PRDR_Value;
	EPT0->CMPA=EPT_CMPA_Value;
	EPT0->CMPB=EPT_CMPB_Value;
	EPT0->CMPC=EPT_CMPC_Value;
	EPT0->CMPD=EPT_CMPD_Value;
}
/*************************************************************/
//Deinitializes the EPT SYNCR Rearm
//EntryParameter:EPT_REARMX,EPT_REARM_MODE
//EPT_REARMX:EPT_REARM_SYNCEN0,EPT_REARM_SYNCEN1,EPT_REARM_SYNCEN2,EPT_REARM_SYNCEN3,EPT_REARM_SYNCEN4,EPT_REARM_SYNCEN5
//EPT_REARM_MODE:EPT_REARM_Selected_DIS,EPT_REARM_Selected_ZRO_AUTO,EPT_REARM_Selected_PRD_AUTO,EPT_REARM_Selected_ZRO_PRD_AUTO
//ReturnValue:NONE
/*************************************************************/  
void EPT_SYNCR_Rearm(EPT_REARMX_Type EPT_REARMX , EPT_REARM_MODE_Type EPT_REARM_MODE)
{
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->SYNCR = (EPT0->SYNCR&0X3FC0FFFF)|EPT_REARMX|EPT_REARM_MODE;
}
/*************************************************************/
//Deinitializes the EPT Caputer Rearm
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/  
//重置捕捉：捕捉事件计数器被清零， 自动打开CAPLDEN
void EPT_Caputure_Rearm(void)
{
	EPT0->CR=(EPT0->CR&0xfffdffff)|(0x01<<19);
}
/*************************************************************/
//Deinitializes the EPT Globle Event Load
//EntryParameter:EPT_GLDMD_Selecte_X,GLDCFG_EN
//EPT_GLDMD_Selecte_X:EPT_GLDMD_Selecte_ZRO,EPT_GLDMD_Selecte_PRD,EPT_GLDMD_Selecte_ZRO_PRD,EPT_GLDMD_Selecte_ZRO_ExiLoad_SYNC
//EPT_GLDMD_Selecte_PRD_ExiLoad_SYNC,EPT_GLDMD_Selecte_ZRO_PRD_ExiLoad_SYNC,
//GLDCFG_EN:0~0x3fff
//ReturnValue:NONE
/*************************************************************/  
//PRDR/CMPA/CMPB/CMPC/CMPD/DBDTR/DBCR/AQCRA/AQCRB/AQCRD/AQCSF/EMPSR 载入配置
void EPT_Globle_Eventload_Config(EPT_GLDMD_Selecte_Type EPT_GLDMD_Selecte_X , U16_T GLDCFG_EN)
{
	EPT0->GLDCR=0X01|EPT_GLDMD_Selecte_X;
	EPT0->GLDCFG=GLDCFG_EN;
	if(EPT_GLDMD_Selecte_X==EPT_GLDMD_Selecte_SW)
	{
		EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
		EPT0->GLDCR2=0X02;
	}
}
/*************************************************************/
//Deinitializes the EPT Globle SW Load
//EntryParameter:GLDCFG_EN
//GLDCFG_EN:0X0~0X3FFF
//EPT_GLDMD_Selecte_X:
/*************************************************************/ 
//PRDR/CMPA/CMPB/CMPC/CMPD/DBDTR/DBCR/AQCRA/AQCRB/AQCRD/AQCSF/EMPSR 载入配置
void EPT_Globle_SwLoad_Config(U16_T GLDCFG_EN)
{
	EPT0->GLDCR=0X01|EPT_GLDMD_Selecte_SW;
	EPT0->GLDCFG=GLDCFG_EN;
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->GLDCR2=0X02;
}
/*************************************************************/
//Deinitializes the EPT PRDR Load 
//EntryParameter:EPT_PRDR_EventLoad_x
//EPT_PRDR_EventLoad_x:EPT_PRDR_EventLoad_PEND,EPT_PRDR_EventLoad_ExiLoad_SYNC,EPT_PRDR_EventLoad_Zro_ExiLoad_SYNC,
//EPT_PRDR_EventLoad_Immediate
/*************************************************************/ 
void EPT_PRDR_EventLoad_Config(EPT_PRDR_EventLoad_Type EPT_PRDR_EventLoad_x)
{
	EPT0->GLDCR&=0XFFFFFFFE;	//使用独立单个配置
	EPT0->CR=(EPT0->CR&0xffffffcf)|EPT_PRDR_EventLoad_x;
}
/*************************************************************/
//Deinitializes the EPT CMPX Load Config
//EntryParameter:EPT_CMPX_EventLoad_x
//EPT_CMPX_EventLoad_x:EPT_CMPX_EventLoad_DIS,EPT_CMPX_EventLoad_Immediate,EPT_CMPX_EventLoad_ZRO,
//EPT_CMPX_EventLoad_PRD,EPT_CMPX_EventLoad_ExiLoad_SYNC
/*************************************************************/ 
//统一载入寄存器:CMPA,CMPB,CMPC,CMPD
void EPT_CMP_EventLoad_Config(EPT_CMPX_EventLoad_Type EPT_CMPX_EventLoad_x)
{
	EPT0->GLDCR&=0XFFFFFFFE;		//使用独立单个配置
	if(EPT_CMPX_EventLoad_x==EPT_CMPX_EventLoad_DIS)
	{
		EPT0->CMPLDR=0;
	}
	else if(EPT_CMPX_EventLoad_x==EPT_CMPX_EventLoad_Immediate)
	{
		EPT0->CMPLDR=0xf;
	}
	else if(EPT_CMPX_EventLoad_x==EPT_CMPX_EventLoad_ZRO)
	{
		EPT0->CMPLDR=0x2410;	
	}
	else if(EPT_CMPX_EventLoad_x==EPT_CMPX_EventLoad_PRD)
	{
		EPT0->CMPLDR=0x4920;
	}
	else if(EPT_CMPX_EventLoad_x==EPT_CMPX_EventLoad_ExiLoad_SYNC)
	{
		EPT0->CMPLDR=0x8240;
	}
}
/*************************************************************/
//Deinitializes the EPT AQCRX Load Config
//EntryParameter:EPT_AQCRX_EventLoad_X
//EPT_AQCRX_EventLoad_X:EPT_AQCRX_EventLoad_DIS,EPT_AQCRX_EventLoad_Immediate,EPT_AQCRX_EventLoad_ZRO,
//EPT_AQCRX_EventLoad_PRD,EPT_AQCRX_EventLoad_ExiLoad_SYNC
/*************************************************************/ 
//统一载入寄存器:AQCRA,AQCRB,AQCRC,AQCRD
void EPT_AQCR_Eventload_Config(EPT_AQCRX_EventLoad_Type EPT_AQCRX_EventLoad_X)
{
	EPT0->GLDCR&=0XFFFFFFFE;		//使用独立单个配置
	if(EPT_AQCRX_EventLoad_X==EPT_AQCRX_EventLoad_DIS)
	{
		EPT0->AQLDR=0;
	}
	else if(EPT_AQCRX_EventLoad_X==EPT_AQCRX_EventLoad_Immediate)
	{
		EPT0->AQLDR=0x303;
	}
	else if(EPT_AQCRX_EventLoad_X==EPT_AQCRX_EventLoad_ZRO)
	{
		EPT0->AQLDR=0x2424;	
	}
	else if(EPT_AQCRX_EventLoad_X==EPT_AQCRX_EventLoad_PRD)
	{
		EPT0->AQLDR=0x4848;
	}
	else if(EPT_AQCRX_EventLoad_X==EPT_AQCRX_EventLoad_ExiLoad_SYNC)
	{
		EPT0->AQLDR=0x9090;
	}
}
/*************************************************************/
//Deinitializes the EPT DB Load Config
//EntryParameter:EPT_DB_EventLoad_X
//EPT_DB_EventLoad_X:EPT_DB_EventLoad_DIS,EPT_DB_EventLoad_Immediate,EPT_DB_EventLoad_ZRO,
//EPT_DB_EventLoad_PRD,EPT_DB_EventLoad_ZRO_PRD
/*************************************************************/ 
//统一载入寄存器:DBCR,DBDTR,DBDTF,DPSCR
void EPT_DB_Eventload_Config(EPT_DB_EventLoad_Type EPT_DB_EventLoad_X)
{
	EPT0->GLDCR&=0XFFFFFFFE;		//使用独立单个配置
	if(EPT_DB_EventLoad_X==EPT_DB_EventLoad_DIS)
	{
		EPT0->DBLDR=0X249;
	}
	else if(EPT_DB_EventLoad_X==EPT_DB_EventLoad_Immediate)
	{
		EPT0->DBLDR=0;
	}
	else if(EPT_DB_EventLoad_X==EPT_DB_EventLoad_ZRO)
	{
		EPT0->DBLDR=0X249|(0X01<<1)|(0X01<<4)|(0X01<<7)|(0X01<<10);
	}
	else if(EPT_DB_EventLoad_X==EPT_DB_EventLoad_PRD)
	{
		EPT0->DBLDR=0X249|(0X02<<1)|(0X02<<4)|(0X02<<7)|(0X02<<10);
	}
	else if(EPT_DB_EventLoad_X==EPT_DB_EventLoad_ZRO_PRD)
	{
		EPT0->DBLDR=0X249|(0X03<<1)|(0X03<<4)|(0X03<<7)|(0X03<<10);
	}
}
/*************************************************************/
//EPT EVTRG Config
//EntryParameter:EPT_TRGSRCX_Select,EPT_EVTRG_TRGSRCX_X,EPT_TRGSRCX_CMD,TRGEVXPRD
//EPT_TRGSRCX_Select:EPT_TRGSRC0,EPT_TRGSRC1,EPT_TRGSRC2,EPT_TRGSRC3
//EPT_EVTRG_TRGSRCX_X:
//EPT_TRGSRCX_CMD:
//TRGEVXPRD:0~0xf
//ReturnValue: NONE
/*************************************************************/
void EPT_TRGSRCX_Config(EPT_TRGSRCX_Select_Type EPT_TRGSRCX_Select , EPT_EVTRG_TRGSRCX_TypeDef EPT_EVTRG_TRGSRCX_X , EPT_TRGSRCX_CMD_TypeDef EPT_TRGSRCX_CMD , U8_T TRGEVXPRD)
{
	if(EPT_TRGSRCX_Select==EPT_TRGSRC0)
	{
		EPT0->EVTRG=(EPT0->EVTRG&0xffeffff0)|(EPT_EVTRG_TRGSRCX_X<<0)|(EPT_TRGSRCX_CMD<20);
	}
	else if(EPT_TRGSRCX_Select==EPT_TRGSRC1)
	{
		EPT0->EVTRG=(EPT0->EVTRG&0xffdfff0f)|(EPT_EVTRG_TRGSRCX_X<<4)|(EPT_TRGSRCX_CMD<21);
	}
	else if(EPT_TRGSRCX_Select==EPT_TRGSRC2)
	{
		EPT0->EVTRG=(EPT0->EVTRG&0xffbff0ff)|(EPT_EVTRG_TRGSRCX_X<<8)|(EPT_TRGSRCX_CMD<22);
	}
	else if(EPT_TRGSRCX_Select==EPT_TRGSRC3)
	{
		EPT0->EVTRG=(EPT0->EVTRG&0xff7f0fff)|(EPT_EVTRG_TRGSRCX_X<<12)|(EPT_TRGSRCX_CMD<23);
	}
	EPT0->EVTRG|=0x0f0f0000;
}
/*************************************************************/
//EPT EVTRG SWFTRG
//EntryParameter:EPT_TRGSRCX_Select
//EPT_TRGSRCX_Select:EPT_TRGSRC0,EPT_TRGSRC1,EPT_TRGSRC2,EPT_TRGSRC3
//ReturnValue: NONE
/*************************************************************/
void EPT_TRGSRCX_SWFTRG(EPT_TRGSRCX_Select_Type EPT_TRGSRCX_Select)
{
	if(EPT_TRGSRCX_Select==EPT_TRGSRC0)
	{
		EPT0->EVSWF|=0X01;
	}
	else if(EPT_TRGSRCX_Select==EPT_TRGSRC1)
	{
		EPT0->EVSWF|=0X02;
	}
	else if(EPT_TRGSRCX_Select==EPT_TRGSRC2)
	{
		EPT0->EVSWF|=0X04;
	}
	else if(EPT_TRGSRCX_Select==EPT_TRGSRC3)
	{
		EPT0->EVSWF|=0X08;
	}
}
/*************************************************************/
//EPT INT ENABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void EPT_Int_Enable(EPT_INT_TypeDef EPT_X_INT)
{
	EPT0->ICR 	= EPT_X_INT;							//clear LVD INT status
	EPT0->IMCR  |= EPT_X_INT;
}
/*************************************************************/
//EPT INT DISABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void EPT_Int_Disable(EPT_INT_TypeDef EPT_X_INT)
{
	EPT0->IMCR  &= ~EPT_X_INT;
}
/*************************************************************/
//EPT EMINT ENABLE.
//EntryParameter:EPT_X_EMINT
//EPT_X_EMINT:EPT_EP0_EMINT~EPT_EP7_EMINT,EPT_CPU_FAULT_EMINT,EPT_MEM_FAULT_EMINT,EPT_EOM_FAULT_EMINT
//ReturnValue: NONE
/*************************************************************/
void EPT_EMInt_Enable(EPT_EMINT_TypeDef EPT_X_EMINT)
{
	EPT0->EMICR = EPT_X_EMINT;							//clear LVD INT status
	EPT0->EMIMCR  |= EPT_X_EMINT;
}
/*************************************************************/
//EPT EMINT DISABLE.
//EntryParameter:EPT_X_EMINT
//EPT_X_EMINT:EPT_EP0_EMINT~EPT_EP7_EMINT,EPT_CPU_FAULT_EMINT,EPT_MEM_FAULT_EMINT,EPT_EOM_FAULT_EMINT
//ReturnValue: NONE
/*************************************************************/
void EPT_EMInt_Disable(EPT_EMINT_TypeDef EPT_X_EMINT)
{
	EPT0->EMIMCR  &= ~EPT_X_EMINT;
}
/*************************************************************/
//EPT INT VECTOR enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EPT_Vector_Int_Enable(void)
{
	INTC_ISER_WRITE(EPT0_INT);    
}
/*************************************************************/
//EPT INT VECTOR disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EPT_Vector_Int_Disable(void)
{
    INTC_ICER_WRITE(EPT0_INT);    
}
/*************************************************************/
//EPT EM Config
//EntryParameter:EPT_LKCR_TRG_X,EPT_LKCR_Mode_X
//EPT_LKCR_TRG_X:EPT_LKCR_TRG_EP0~EPT_LKCR_TRG_EP7,EPT_LKCR_TRG_CPU_FAULT,EPT_LKCR_TRG_MEM_FAULT,EPT_LKCR_TRG_EOM_FAULT
//EPT_LKCR_Mode_X:EPT_LKCR_Mode_LOCK_DIS,EPT_LKCR_Mode_SLOCK_EN,EPT_LKCR_Mode_HLOCK_EN,EPT_LKCR_TRG_X_FAULT_HLOCK_EN,EPT_LKCR_TRG_X_FAULT_HLOCK_DIS
//ReturnValue:NONE
/*************************************************************/
void EPT_LKCR_TRG_Config(EPT_LKCR_TRG_Source_Type EPT_LKCR_TRG_X , EPT_LKCR_Mode_Type EPT_LKCR_Mode_X)
{
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->EMECR=(0X01<<21)|(0X01<<22)|(0X02<<24);			//EMOSR CNT=ZRO时载入，CNT=ZRO和PRD时软锁止自动清除
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	if(EPT_LKCR_TRG_X==EPT_LKCR_TRG_CPU_FAULT)
	{
		if(EPT_LKCR_Mode_X==EPT_LKCR_TRG_X_FAULT_HLOCK_EN)
		{
			EPT0->EMECR|=(0x01<<28);
		}
		else if(EPT_LKCR_Mode_X==EPT_LKCR_TRG_X_FAULT_HLOCK_DIS)
		{
			EPT0->EMECR&=~(0x01<<28);
		}
	}
	else if(EPT_LKCR_TRG_X==EPT_LKCR_TRG_MEM_FAULT)
	{
		if(EPT_LKCR_Mode_X==EPT_LKCR_TRG_X_FAULT_HLOCK_EN)
		{
			EPT0->EMECR|=(0x01<<29);
		}
		else if(EPT_LKCR_Mode_X==EPT_LKCR_TRG_X_FAULT_HLOCK_DIS)
		{
			EPT0->EMECR&=~(0x01<<29);
		}
	}
	else if(EPT_LKCR_TRG_X==EPT_LKCR_TRG_EOM_FAULT)
	{
		if(EPT_LKCR_Mode_X==EPT_LKCR_TRG_X_FAULT_HLOCK_EN)
		{
			EPT0->EMECR|=(0x01<<30);
		}
		else if(EPT_LKCR_Mode_X==EPT_LKCR_TRG_X_FAULT_HLOCK_DIS)
		{
			EPT0->EMECR&=~(0x01<<30);
		}
	}
	else
	{
		EPT0->EMECR|=(EPT_LKCR_Mode_X<<(EPT_LKCR_TRG_X*2))|(0X01<<26);
	}
}
/*************************************************************/
//EPT EM Config
//EntryParameter:EPT_OUTPUT_Channel_X,EPT_SHLOCK_OUTPUT_X
//EPT_OUTPUT_Channel_X:EPT_OUTPUT_Channel_CHAX,EPT_OUTPUT_Channel_CHAY,EPT_OUTPUT_Channel_CHBX,EPT_OUTPUT_Channel_CHBY
//EPT_OUTPUT_Channel_CHCX,EPT_OUTPUT_Channel_CHCY,EPT_OUTPUT_Channel_CHD
//EPT_SHLOCK_OUTPUT_X:EPT_SHLOCK_OUTPUT_HImpedance,EPT_SHLOCK_OUTPUT_High,EPT_SHLOCK_OUTPUT_Low,EPT_SHLOCK_OUTPUT_Nochange
//ReturnValue:NONE
/*************************************************************/
void EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Channel_Type EPT_OUTPUT_Channel_X , EPT_SHLOCK_OUTPUT_Statue_Type EPT_SHLOCK_OUTPUT_X)
{
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->EMOSR=EPT_SHLOCK_OUTPUT_X<<EPT_OUTPUT_Channel_X;
}
/*************************************************************/
//EPT software lock clr
//EntryParameter:EPT_X_EMINT
//EPT_X_EMINT:EPT_EP0_EMINT~EPT_EP7_EMINT,EPT_CPU_FAULT_EMINT,EPT_MEM_FAULT_EMINT,EPT_EOM_FAULT_EMINT
//ReturnValue:NONE
/*************************************************************/
void EPT_SLock_CLR(EPT_EMINT_TypeDef EPT_X_EMINT)
{
	EPT0->EMSLCLR|=EPT_X_EMINT;
}
/*************************************************************/
//EPT H lock clr
//EntryParameter:EPT_X_EMINT
//EPT_X_EMINT:EPT_EP0_EMINT~EPT_EP7_EMINT,EPT_CPU_FAULT_EMINT,EPT_MEM_FAULT_EMINT,EPT_EOM_FAULT_EMINT
//ReturnValue:NONE
/*************************************************************/
void EPT_HLock_CLR(EPT_EMINT_TypeDef EPT_X_EMINT)
{
	EPT0->EMHLCLR|=EPT_X_EMINT;
}
/*************************************************************/
//EPT software lock SET
//EntryParameter:EPT_X_EMINT
//EPT_X_EMINT:EPT_EP0_EMINT~EPT_EP7_EMINT,EPT_CPU_FAULT_EMINT,EPT_MEM_FAULT_EMINT,EPT_EOM_FAULT_EMINT
//ReturnValue:NONE
/*************************************************************/
void EPT_SW_Set_lock(EPT_EMINT_TypeDef EPT_X_EMINT)
{
	EPT0->REGPROT = (0xA55A<<16) | 0xC73A;
	EPT0->EMFRCR|=EPT_X_EMINT;
}
/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/