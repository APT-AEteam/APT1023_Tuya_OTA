/*
  ******************************************************************************
  * @file    main.c
  * @author  APT AE Team
  * @version V0.50
  * @date    2020/05/18
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
#include "apt32f102_syscon.h"

/* define --------------------------------------------------------------------*/

/* externs--------------------------------------------------------------------*/

/*************************************************************/
//Deinitializes the syscon registers to their default reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/    
void SYSCON_RST_VALUE(void)									//reset value
{
	//SYSCON->IDCCR=SYSCON_IDCCR_RST;
	//SYSCON->GCER=SYSCON_GCER_RST;
	//SYSCON->GCDR=SYSCON_GCDR_RST;
	//SYSCON->GCSR=SYSCON_GCSR_RST;
	//SYSCON->CKST=SYSCON_CKST_RST;
	SYSCON->RAMCHK=SYSCON_RAMCHK_RST;
	SYSCON->EFLCHK=SYSCON_EFLCHK_RST;
	//SYSCON->SCLKCR=SYSCON_SCLKCR_RST;
	//SYSCON->PCLKCR=SYSCON_PCLKCR_RST;
	//SYSCON->PCER0=SYSCON_PCER0_RST;
	//SYSCON->PCDR0=SYSCON_PCDR0_RST;
	//SYSCON->PCSR0=SYSCON_PCSR0_RST;
	//SYSCON->PCER1=SYSCON_PCER1_RST;
	//SYSCON->PCDR1=SYSCON_PCDR1_RST;
	//SYSCON->PCSR1=SYSCON_PCSR1_RST;
	SYSCON->OSTR=SYSCON_OSTR_RST;
	SYSCON->LVDCR=SYSCON_LVDCR_RST;
	//SYSCON->CLCR=SYSCON_CLCR_RST;
	//SYSCON->PWRCR=SYSCON_PWRCR_RST;
	//SYSCON->IMER=SYSCON_IMER_RST;
	//SYSCON->IMDR=SYSCON_IMDR_RST;
	//SYSCON->IMCR=SYSCON_IMCR_RST;
	//SYSCON->IAR=SYSCON_IAR_RST;
	//SYSCON->ICR=SYSCON_ICR_RST;
	//SYSCON->RISR=SYSCON_RISR_RST;
	//SYSCON->MISR=SYSCON_MISR_RST;
	SYSCON->EXIRT=SYSCON_EXIRT_RST;
	SYSCON->EXIFT=SYSCON_EXIFT_RST;
	//SYSCON->EXIER=SYSCON_EXIER_RST;
	//SYSCON->EXIDR=SYSCON_EXIDR_RST;
	//SYSCON->EXIMR=SYSCON_EXIMR_RST;
	//SYSCON->EXIAR=SYSCON_EXIAR_RST;
	//SYSCON->EXICR=SYSCON_EXICR_RST;
	//SYSCON->EXIRS=SYSCON_EXIRS_RST;
	SYSCON->IWDCR=SYSCON_IWDCR_RST;
	SYSCON->IWDCNT=SYSCON_IWDCNT_RST;
	//SYSCON->PWROPT=SYSCON_PWROPT_RST;
	SYSCON->EVTRG=SYSCON_EVTRG_RST;
	SYSCON->EVPS=SYSCON_EVPS_RST;
	SYSCON->EVSWF=SYSCON_EVSWF_RST;
	SYSCON->UREG0=SYSCON_UREG0_RST;
	SYSCON->UREG1=SYSCON_UREG1_RST;
	SYSCON->UREG2=SYSCON_UREG2_RST;
	SYSCON->UREG3=SYSCON_UREG3_RST;
}
/*************************************************************/
//EMOSC OSTR Config
//EM_CNT:0~0X3FF
//EM_GM:0~0X1F
//EM_FLEN;EM_FLEN_DIS,EM_FLEN_EN
//EM_FLSEL:EM_FLSEL_5ns,EM_FLSEL_10ns,EM_FLSEL_15ns,EM_FLSEL_20ns
/*************************************************************/  
void EMOSC_OSTR_Config(U16_T EM_CNT, U8_T EM_GM,EM_LFSEL_TypeDef EM_LFSEL_X, EM_Filter_CMD_TypeDef EM_FLEN_X, EM_Filter_TypeDef EM_FLSEL_X)
{
	SYSCON->OSTR=EM_CNT|(EM_GM<<11)|EM_LFSEL_X|EM_FLEN_X|EM_FLSEL_X;
}
/*************************************************************/
//SYSCON General Control
//EntryParameter:NewState:,ENDIS_X
//NewState:ENABLE,DISABLE
//ENDIS_X:ENDIS_ISOSC,ENDIS_IMOSC,ENDIS_EMOSC,ENDIS_HFOSC
//ReturnValue:NONE
/*************************************************************/  
void SYSCON_General_CMD(FunctionalStatus NewState, SYSCON_General_CMD_TypeDef ENDIS_X )
{
	if (NewState != DISABLE)
	{
		if(ENDIS_X==ENDIS_EMOSC) 
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFF00FFF)|0x00044000;					//使能对应PIN
		SYSCON->GCER|=ENDIS_X;													//enable SYSCON General Control
		while(!(SYSCON->GCSR&ENDIS_X));											//check  Enable?	
		switch(ENDIS_X)
		{
			case ENDIS_IMOSC:
				while (!(SYSCON->CKST & ENDIS_IMOSC)); 	
				break;
			case ENDIS_EMOSC:
				while (!(SYSCON->CKST & ENDIS_EMOSC)); 
				break;	
			case ENDIS_ISOSC:
				while (!(SYSCON->CKST & ENDIS_ISOSC)); 
				break;
			case ENDIS_HFOSC:
				while (!(SYSCON->CKST & ENDIS_HFOSC)); 
				break;	
			case ENDIS_IDLE_PCLK:
				break;	
			case ENDIS_SYSTICK:
				break;	
		}
	}
	else
	{
		SYSCON->GCDR|=ENDIS_X;													//disable SYSCON General Control
		while(SYSCON->GCSR&ENDIS_X);											//check  Disable?
		SYSCON->ICR|=ENDIS_X;													// Clear ENDIS_X stable bit
	}
}
/*************************************************************/
//Seleted system clk and seleted clk div
//EntryParameter:SYSCLK_X,HCLK_DIV_X,PCLK_DIV_X
//SYSCLK_X:SYSCLK_IMOSC,SYSCLK_EMOSC,SYSCLK_ISOSC,SYSCLK_HFOSC
//HCLK_DIV_X:HCLK_DIV_1/2/3/4/5/6/7/8/12/16/24/32/64/128/256
//PCLK_DIV_X:PCLK_DIV_1,PCLK_DIV_2,PCLK_DIV_4,PCLK_DIV_8,PCLK_DIV_16
//SystemClk_data_x:EMOSC_24M,EMOSC_16M,EMOSC_12M,EMOSC_8M,EMOSC_4M,EMOSC_36K,
//ISOSC,IMOSC,HFOSC_48M,HFOSC_24M,HFOSC_12M,HFOSC_6M
//ReturnValue:NONE
/*************************************************************/ 
void SystemCLK_HCLKDIV_PCLKDIV_Config(SystemCLK_TypeDef SYSCLK_X , SystemCLK_Div_TypeDef HCLK_DIV_X , PCLK_Div_TypeDef PCLK_DIV_X , SystemClk_data_TypeDef SystemClk_data_x )
{
	if(SystemClk_data_x==HFOSC_48M)
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X02|(0X01<<16);			//高速模式
	}
	if((SystemClk_data_x==EMOSC_24M)||(SystemClk_data_x==EMOSC_16M)||(SystemClk_data_x==HFOSC_24M))
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X01|(0X01<<16);			//中速模式
	}
	if((SystemClk_data_x==EMOSC_12M)||(SystemClk_data_x==EMOSC_8M)||(SystemClk_data_x==EMOSC_4M)||(SystemClk_data_x==EMOSC_36K)
		||(SystemClk_data_x==IMOSC)||(SystemClk_data_x==ISOSC)||(SystemClk_data_x==HFOSC_12M)||(SystemClk_data_x==HFOSC_6M))
	{
		IFC->CEDR=0X01;						//CLKEN
		IFC->MR=0X00|(0X00<<16);			//低速
	}
	SYSCON->SCLKCR=SYSCLK_KEY | HCLK_DIV_X| SYSCLK_X;
	while (!(SYSCON->CKST & (1<<8))); 											// waiting for sysclk stable
	SYSCON->PCLKCR=PCLK_KEY|PCLK_DIV_X;											//PCLK DIV 1 2 4 6 8 16		
	while(SYSCON->PCLKCR!=PCLK_DIV_X);											//Wait PCLK DIV
}
/*************************************************************/
//SYSCON IMOSC SELECTE
//EntryParameter:IMOSC_SELECTE_X
//IMOSC_SELECTE_X:IMOSC_SELECTE_5556K,IMOSC_SELECTE_4194K;IMOSC_SELECTE_2097K;IMOSC_SELECTE_131K
//ReturnValue:NONE
/*************************************************************/  
void SYSCON_IMOSC_SELECTE(IMOSC_SELECTE_TypeDef IMOSC_SELECTE_X)
{		
	SYSCON_General_CMD(DISABLE,ENDIS_IMOSC);					//disalbe IMOSC
	SYSCON->OPT1 = (SYSCON->OPT1 & 0XFFFFFFFC)|IMOSC_SELECTE_X;	//IMOSC CLK selected
	SYSCON_General_CMD(ENABLE,ENDIS_IMOSC);						//enable IMOSC
}
/*************************************************************/
//SYSCON HFOSC SELECTE
//EntryParameter:HFOSC_SELECTE_X
//HFOSC_SELECTE_X:HFOSC_SELECTE_48M,HFOSC_SELECTE_24M;HFOSC_SELECTE_12M;HFOSC_SELECTE_6M
//ReturnValue:NONE
/*************************************************************/  
void SYSCON_HFOSC_SELECTE(HFOSC_SELECTE_TypeDef HFOSC_SELECTE_X)
{		
	SYSCON_General_CMD(DISABLE,ENDIS_HFOSC);					//disable HFOSC
	SYSCON->OPT1 = (SYSCON->OPT1 & 0XFFFFFFCF)|HFOSC_SELECTE_X;
	SYSCON_General_CMD(ENABLE,ENDIS_HFOSC);						//enable HFOSC
}
/*************************************************************/
//WDT enable and disable 
//EntryParameter:,NewState
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_WDT_CMD(FunctionalStatus NewState)
{
	if(NewState != DISABLE)
	{
		SYSCON->IWDEDR=IWDTEDR_KEY|Enable_IWDT;
		while(!(SYSCON->IWDCR&Check_IWDT_BUSY));
	}
	else
	{
		SYSCON->IWDEDR=IWDTEDR_KEY|Disable_IWDT;
		while(SYSCON->IWDCR&Check_IWDT_BUSY);
	}
}
/*************************************************************/
//reload WDT CN
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void SYSCON_IWDCNT_Reload(void)
{
	SYSCON->IWDCNT=CLR_IWDT;
}
/*************************************************************/
//IWDCNT Config
//EntryParameter:NewStateE_IWDT_SHORT,IWDT_TIME_X,IWDT_INTW_DIV_X
//NewStateE_IWDT_SHORT:ENABLE_IWDT_SHORT,DISABLE_IWDT_SHORT
//IWDT_TIME_X:IWDT_TIME_128MS,IWDT_TIME_256MS,IWDT_TIME_500MS,IWDT_TIME_1S,IWDT_TIME_2S,IWDT_TIME_3S,IWDT_TIME_4S,IWDT_TIME_8S
//IWDT_INTW_DIV_X:IWDT_INTW_DIV_1/2/3/4/4/5/6
//ReturnValue: NONE
/*************************************************************/
void SYSCON_IWDCNT_Config(IWDT_TIME_TypeDef IWDT_TIME_X , IWDT_TIMEDIV_TypeDef IWDT_INTW_DIV_X )
{
	SYSCON->IWDCR=IWDT_KEY|IWDT_TIME_X|IWDT_INTW_DIV_X;
}
/*************************************************************/
//LVD Config  and set LVD INT
//EntryParameter:X_LVDEN,INTDET_LVL_X,RSTDET_LVL_X,X_LVD_INT
//X_LVDEN:ENABLE_LVDEN,DISABLE_LVDEN
//INTDET_LVL_X:INTDET_LVL_1_8V,INTDET_LVL_2_1V,INTDET_LVL_2_5V,INTDET_LVL_2_9V,INTDET_LVL_3_3V,INTDET_LVL_3_7V,INTDET_LVL_4_1V,INTDET_LVL_4_5V
//RSTDET_LVL_X:RSTDET_LVL_1_6V,RSTDET_LVL_2_0V,RSTDET_LVL_2_4V,RSTDET_LVL_2_8V,RSTDET_LVL_3_2V,RSTDET_LVL_3_6V,RSTDET_LVL_4_0V,RSTDET_LVL_4_4V
//X_LVD_INT:ENABLE_LVD_INT,DISABLE_LVD_INT
//INTDET_POL_X:INTDET_POL_fall,INTDET_POL_X_rise,INTDET_POL_X_riseORfall
//ReturnValue: NONE
/*************************************************************/
void SYSCON_LVD_Config(X_LVDEN_TypeDef X_LVDEN , INTDET_LVL_X_TypeDef INTDET_LVL_X , RSTDET_LVL_X_TypeDef RSTDET_LVL_X , X_LVD_INT_TypeDef X_LVD_INT , INTDET_POL_X_TypeDef INTDET_POL_X)
{
	//SYSCON->LVDCR=LVD_KEY;
	SYSCON->LVDCR=LVD_KEY|X_LVDEN|INTDET_LVL_X|RSTDET_LVL_X|X_LVD_INT|INTDET_POL_X;
}
/*************************************************************/
//LVD INT ENABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void LVD_Int_Enable(void)
{
	SYSCON->ICR = LVD_INT_ST;				//clear LVD INT status
	SYSCON->IMER  |= LVD_INT_ST;
}
/*************************************************************/
//LVD INT DISABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void LVD_Int_Disable(void)
{
	SYSCON->IMDR  |= LVD_INT_ST;
}
/*************************************************************/
//WDT INT ENABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void IWDT_Int_Enable(void)
{
	SYSCON->ICR = IWDT_INT_ST;				//clear LVD INT status
	SYSCON->IMER  |= IWDT_INT_ST;
}
/*************************************************************/
//WDT INT DISABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void IWDT_Int_Disable(void)
{
	SYSCON->IMDR  |= IWDT_INT_ST;
}
/*************************************************************/
//Reset status.
//EntryParameter:NONE
//ReturnValue: rsr_dat
//rsr_dat=0x01 power on reset
//rsr_dat=0x02 low voltage reset
//rsr_dat=0x04 ex-pin reset
//rsr_dat=0x10 wdt reset
//rsr_dat=0x40 ex clock invalid reset
//rsr_dat=0x80 cpu request reset
//rsr_dat=0x100 software reset
/*************************************************************/
U32_T Read_Reset_Status(void)
{
	return (SYSCON->RSR & 0x1ff);
}
/*************************************************************/
//external trigger  Mode Selection Functions
//EntryParameter:NewState,EXIPIN,EXI_tringer_mode
//NewState:ENABLE,DISABLE
//EXIPIN:EXI_PIN0/1/2/3/4/5/6/7/8/9/10/11/12/13
//EXI_tringer_mode:_EXIRT,_EXIFT
//ReturnValue: LVD detection flag
/*************************************************************/
void EXTI_trigger_CMD(FunctionalStatus NewState , SYSCON_EXIPIN_TypeDef  EXIPIN , EXI_tringer_mode_TypeDef EXI_tringer_mode)
{
	switch(EXI_tringer_mode)
	{
		case _EXIRT:
		if(NewState != DISABLE)
		{
			SYSCON->EXIRT |=EXIPIN;
		}
		else
		{
			SYSCON->EXIRT &=~EXIPIN;	
		}
		break;
		case _EXIFT:
		if(NewState != DISABLE)
		{
			SYSCON->EXIFT |=EXIPIN;
		}
		else
		{
			SYSCON->EXIFT &=~EXIPIN;	
		}
		break;
	}	
}
/*************************************************************/
//external interrupt enable and disable 
//EntryParameter:NewState,EXIPIN,* GPIOX
//* GPIOX:GPIOA,GPIOB
//EXIPIN:EXI_PIN0/1/2/3/4/5/6/7/8/9/10/11/12/13
//NewState:ENABLE,DISABLE
//ReturnValue:NONE
/*************************************************************/
void EXTI_interrupt_CMD(FunctionalStatus NewState , SYSCON_EXIPIN_TypeDef  EXIPIN)
{
	SYSCON->EXICR = 0X3FFF;									//Claer EXI INT status
	if(NewState != DISABLE)
	{
		SYSCON->EXIER|=EXIPIN;								//EXI4 interrupt enable
		while(!(SYSCON->EXIMR&EXIPIN));						//Check EXI is enabled or not
		SYSCON->EXICR |=EXIPIN;								// Clear EXI status bit
	}
	else
	{
		SYSCON->EXIDR|=EXIPIN;
	}
}
/*************************************************************/
//GPIO EXTI interrupt
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void GPIO_EXTI_interrupt(CSP_GPIO_T * GPIOX,U32_T GPIO_IECR_VALUE)
{
	GPIOX->IECR=GPIO_IECR_VALUE;
}
/*************************************************************/
//PLCK goto SLEEP mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void PCLK_goto_idle_mode(void)
{
	asm ("doze");											// Enter sleep mode
}  
/*************************************************************/
//PLCK goto SLEEP mode
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void PCLK_goto_deepsleep_mode(void)
{
	SYSCON->WKCR=0X3F<<8;
	asm ("stop");
}  
/*************************************************************/
//EXI0 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI0_INT);    
}

/*************************************************************/
//EXI0 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI0_INT);    
}

/*************************************************************/
//EXI1 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI1_INT);    
}

/*************************************************************/
//EXI1 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI1_INT);    
}

/*************************************************************/
//EXI2 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI2_INT);    
}

/*************************************************************/
//EXI2 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI2_INT);    
}

/*************************************************************/
//EXI3 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI3_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI3_INT);    
}

/*************************************************************/
//EXI3 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI3_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI3_INT);    
}

/*************************************************************/
//EXI4 Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4_Int_Enable(void)
{
	INTC_ISER_WRITE(EXI4_INT);    
}

/*************************************************************/
//EXI4 Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4_Int_Disable(void)
{
    INTC_ICER_WRITE(EXI4_INT);    
}
/*************************************************************/
//EXI0 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI0_INT);    
}

/*************************************************************/
//EXI0 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI0_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI0_INT);    
}

/*************************************************************/
//EXI1 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI1_INT);    
}

/*************************************************************/
//EXI1 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI1_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI1_INT);    
}

/*************************************************************/
//EXI2 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI2_INT);    
}

/*************************************************************/
//EXI2 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI2_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI2_INT);    
}

/*************************************************************/
//EXI3 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI3_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI3_INT);    
}

/*************************************************************/
//EXI3 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI3_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI3_INT);    
}

/*************************************************************/
//EXI4 Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(EXI4_INT);    
}

/*************************************************************/
//EXI4 Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void EXI4_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(EXI4_INT);    
}
/*************************************************************/
//SYSCON Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_Int_Enable(void)
{
    INTC_ISER_WRITE(SYSCON_INT);    
}

/*************************************************************/
//SYSCON Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_Int_Disable(void)
{
    INTC_ICER_WRITE(SYSCON_INT);    
}
/*************************************************************/
//SYSCON Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(SYSCON_INT);    
}
/*************************************************************/
//set PA0.0/PA0.8 as CLO output 
//EntryParameter:CLO_PA02/CLO_PA08
//ReturnValue:NONE
/*************************************************************/
void SYSCON_CLO_CONFIG(CLO_IO_TypeDef clo_io)
{
	if (clo_io==CLO_PA02)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF) | 0X00000700;
	}
	if (clo_io==CLO_PA08)
	{
		GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0) | 0X00000007;
	}
	
}
/*************************************************************/
//SYSCON Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void SYSCON_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(SYSCON_INT);    
}
/*************************************************************/
//READ CIF0 data
//EntryParameter:None
//ReturnValue:VALUE
/*************************************************************/
U32_T SYSCON_Read_CINF0(void)
{
    U32_T value = 0;
    value=SYSCON->CINF0;
    return value;
}
/*************************************************************/
//READ CIF1 data
//EntryParameter:None
//ReturnValue:VALUE
/*************************************************************/
U32_T SYSCON_Read_CINF1(void)
{
    U32_T value = 0;
    value=SYSCON->CINF1;
    return value;
}
/*************************************************************/
//Software_Reset
//EntryParameter:None
//ReturnValue:MCU reset
/*************************************************************/
void SYSCON_Software_Reset(void)
{
	SYSCON->IDCCR=IDCCR_KEY|SWRST;
}
/*************************************************************/
//Interrupt Priority setting
//EntryParameter:00/40/80/C0
//Coret_INT   IQR0
//SYSCON_INT  IQR1
//IFC_INT     IRQ2
//ADC_INT     IRQ3
//GPT0_INT    IRQ4
//GPT1_INT    IRQ5
//GPT2_INT    IRQ6
//EXI0_INT    IRQ7
//EXI1_INT    IRQ8
//GPT0_INT    IRQ9
//GPT1_INT    IRQ10
//RTC_INT	  IRQ12
//UART0_INT   IRQ13
//UART1_INT   IRQ14
//USART0_INT  IRQ15
//I2C_INT     IRQ17
//SPI_INT     IRQ19
//EXI2_INT    IRQ21
//EXI3_INT    IRQ22
//EXI4_INT    IRQ23
//CA_INT      IRQ24
//TKEY_INT    IRQ25
//LPT_INT     IRQ26
//BT_INT 	  IRQ30
//ReturnValue:None
/*************************************************************/
void SYSCON_INT_Priority(void)
{
	INTC_IPR0_WRITE(0X40404040);   //IQR0-3
	INTC_IPR1_WRITE(0X40404000);   //IQR4-7  
	INTC_IPR2_WRITE(0X40404040);   //IQR8-11  
	INTC_IPR3_WRITE(0X40404040);   //IQR12-15  
	INTC_IPR4_WRITE(0X40404040);   //IQR16-19  
	INTC_IPR5_WRITE(0X40404040);   //IQR20-23 
	INTC_IPR6_WRITE(0X40404040);   //IQR24-27  
	INTC_IPR7_WRITE(0X40404040);   //IQR28-31
}
/******************* (C) COPYRIGHT 2018 APT Chip *****END OF FILE****/