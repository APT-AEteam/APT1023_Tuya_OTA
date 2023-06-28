/*
  ******************************************************************************
  * @file    apt32f102_adc.c
  * @author  APT AE Team
  * @version V0.5
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
#include "apt32f102_adc.h"

/* defines -------------------------------------------------------------------*/
/* externs--------------------------------------------------------------------*/
/*************************************************************/
//ADC12 RESET VALUE 
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void ADC12_RESET_VALUE(void)
{
	 ADC0->ECR	=	ADC_ECR_RST;     				/**< ECR  reset value  */
	 ADC0->DCR	=	ADC_DCR_RST;                  	/**< DCR  reset value  */
	 ADC0->PMSR	= 	ADC_PMSR_RST;       		  	/**< PMSR reset value  */
	 ADC0->CR	=	ADC_CR_RST;             		/**< CR   reset value  */
	 ADC0->MR	=   ADC_MR_RST;                  	/**< MR   reset value  */
	 ADC0->CSR	=   ADC_CSR_RST;                  	/**< CSR  reset value  */
	 ADC0->SR 	=	ADC_SR_RST;                   	/**< SR   reset value  */
	 ADC0->IER 	=	ADC_IER_RST;                	/**< IER  reset value  */
	 ADC0->IDR 	=	ADC_IDR_RST;              		/**< IDR  reset value  */
	 ADC0->IMR  	=	ADC_IMR_RST;               		/**< IMR  reset value  */
	 ADC0->SEQ[0]=	ADC_SEQx_RST;             		/**< SEQ0  reset value */
	 ADC0->SEQ[1]=	ADC_SEQx_RST;             		/**< SEQ1  reset value */
	 ADC0->SEQ[2]=	ADC_SEQx_RST;             		/**< SEQ2  reset value */
	 ADC0->SEQ[3]=	ADC_SEQx_RST;             		/**< SEQ3  reset value */
	 ADC0->SEQ[4]=	ADC_SEQx_RST;             		/**< SEQ4  reset value */
	 ADC0->SEQ[5]=	ADC_SEQx_RST;             		/**< SEQ5  reset value */
	 ADC0->SEQ[6]=	ADC_SEQx_RST;             		/**< SEQ6  reset value */
	 ADC0->SEQ[7]=	ADC_SEQx_RST;             		/**< SEQ7  reset value */
	 ADC0->SEQ[8]=	ADC_SEQx_RST;             		/**< SEQ8  reset value */
	 ADC0->SEQ[9]=	ADC_SEQx_RST;             		/**< SEQ9  reset value */
	 ADC0->SEQ[10]=	ADC_SEQx_RST;             		/**< SEQ10  reset value */
	 ADC0->SEQ[11]=	ADC_SEQx_RST;             		/**< SEQ11  reset value */
	 ADC0->SEQ[12]=	ADC_SEQx_RST;             		/**< SEQ12  reset value */
	 ADC0->SEQ[13]=	ADC_SEQx_RST;             		/**< SEQ13  reset value */
	 ADC0->SEQ[14]=	ADC_SEQx_RST;             		/**< SEQ14  reset value */
	 ADC0->SEQ[15]=	ADC_SEQx_RST;             		/**< SEQ15  reset value */
	 ADC0->DR[0]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[1]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[2]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[3]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[4]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[5]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[6]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[7]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[8]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[9]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[10]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[11]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[12]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[13]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[14]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->DR[15]  =	ADC_DR_RST;                		/**< DR   reset value  */
	 ADC0->CMP0   =	ADC_CMP0_RST;               	/**< CMP1 reset value  */
	 ADC0->CMP1   =	ADC_CMP1_RST;                	/**< CMP2 reset value  */
}  
/*************************************************************/
//ADC12 Control
//EntryParameter:ADC12_Control_x 
//ADC12_Control_x:ADC12_SWRST , ADC12_ADCEN , ADC12_ADCDIS, ADC12_START, ADC12_STOP,ADC12_SWTRG
//ReturnValue:NONE
/*************************************************************/  
  //control:ADC enable/disable ,start/stop,swrst
void ADC12_Control(ADC12_Control_TypeDef ADC12_Control_x )
{
	ADC0->CR |= ADC12_Control_x;							// 
}
/*************************************************************/
//ADC12 Interrupt ENABLE AND DISABLE
//EntryParameter:ADC_IMR_X,NewState
//ADC_IMR_X:ADC12_EOC,ADC12_READY,ADC12_OVR,ADC12_CMP0H,ADC12_CMP0L,ADC12_CMP1H,ADC12_CMP1L,ADC12_SEQ_END0~15
//NewState:ENABLE , DISABLE
//ReturnValue:NONE
/*************************************************************/    
  //ADC12_EOC:End of conversion interrupt
  //ADC12_READY:ADC ready for conversion interrupt
  //ADC12_OVR:Overrun interrupt
  //ADC12_CMP0H:Higher than ADC_CMP1 interrupt
  //ADC12_CMP0L:Lower than ADC_CMP1 interrupt
  //ADC12_CMP1H:Higher than ADC_CMP2 interrupt
  //ADC12_CMP1L:Lower than ADC_CMP2 interrupt
  //ADC12_SEQ_END0~15:SEQx convert end interrupt
void ADC12_ConfigInterrupt_CMD( ADC12_IMR_TypeDef ADC_IMR_X , FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		ADC0->IER  |= ADC_IMR_X;						//SET
	}
	else
	{
		ADC0->IDR  |= ADC_IMR_X;						//CLR
	}
} 
/*************************************************************/
//Read ADC12 Interrupt ENABLE status
//EntryParameter:EnStatus_bit
//EnStatus_bit:ADC12_EOC,ADC12_READY,ADC12_OVR,ADC12_CMP1H,ADC12_CMP1L,ADC12_CMP2H,ADC12_CMP2L,ADC12_SEQ_END0~15
//ReturnValue:1=enabled/0=disabled
/*************************************************************/   
uint8_t ADC12_Read_IntEnStatus(ADC12_IMR_TypeDef EnStatus_bit)
{
	uint8_t value = 0;
    uint32_t dat = 0;
    dat= ADC0->IMR&EnStatus_bit;
    if (dat == EnStatus_bit)								
	{
	    value = 1;
	} 
    return value;
}
/*************************************************************/
//ADC12 CLK ENABLE AND DISABLE
//EntryParameter:ADC_CLK_CMD,NewState
//ADC_CLK_CMD:ADC_CLK_CR,ADC_DEBUG_MODE
//NewState:ENABLE , DISABLE
//ReturnValue:NONE
/*************************************************************/      
void ADC12_CLK_CMD(ADC12_CLK_TypeDef ADC_CLK_CMD , FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		ADC0->ECR  |= ADC_CLK_CMD;						//ENABLE
		while(!(ADC0->PMSR&ADC_CLK_CMD));
	}
	else
	{
		ADC0->DCR  |= ADC_CLK_CMD;						//DISABLE
		while(ADC0->PMSR&ADC_CLK_CMD);
	}
}
/*************************************************************/
//ADC12 software reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/    
void ADC12_Software_Reset(void)
{
	ADC12_Control(ADC12_SWRST);
}
/*************************************************************/
//ADC12 ENABLE
//EntryParameter:NewState
//NewState:ENABLE , DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void ADC12_CMD(FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		ADC12_Control(ADC12_ADCEN);						//ADC12 ENABLE
		while(!(ADC0->SR &ADC12_ADCENS));
	}
	else
	{
		ADC12_Control(ADC12_ADCDIS);					//ADC12 DISABLE
		while(ADC0->SR&ADC12_ADCENS);
	}
}
/*************************************************************/
//ADC12 READY wait
//EntryParameter:NONE
//ReturnValue:ADC12 READ FLAG
/*************************************************************/ 
void ADC12_ready_wait(void)  
{
	while(!(ADC0->SR&ADC12_READY));   					// Waiting for ADC0 Ready
}
/*************************************************************/
//ADC12 End of conversion wait
//EntryParameter:NONE
//ReturnValue:ADC12 EOC
/*************************************************************/ 
void ADC12_EOC_wait(void)
{
	while(!(ADC0->SR & ADC12_EOC));			// EOC wait
}
/*************************************************************/
//ADC12 End of conversion wait
//EntryParameter:NONE
//ReturnValue:ADC12 EOC
/*************************************************************/ 
void ADC12_SEQEND_wait(U8_T val)
{
	while(!(ADC0->SR & (0x01ul << (16+val))));			// EOC wait
}  
/*************************************************************/
//ADC12 Data Register output
//EntryParameter:NONE
//ReturnValue:ADC12 DR
/*************************************************************/ 
U16_T ADC12_DATA_OUPUT(U16_T Data_index )
{
	return(ADC0->DR[Data_index]);
} 
/*************************************************************/
//ADC12 Configure
//EntryParameter:ADC12_BIT_SELECTED,ADC12_ConverMode,ADC12_DIV,NumConver
//ADC12_BIT_SELECTED:ADC12_12BIT,ADC12_10BIT
//ADC12_ConverMode:One_shot_mode,Continuous_mode
//ADC12_PRI:0~15
//adc12_SHR:0~255
//ADC12_DIV:0~31
//NumConver:Number of Conversions value=(1~12);
//ReturnValue:NONE
/*************************************************************/ 
  //10BIT or 12BIT adc ;
  //ADC12_BIT_SELECTED:ADC12_12BIT/ADC12_10BIT;
  //ADC12_ConverMode:One_shot_mode/Continuous_mode;
  //adc date output=last number of Conversions;
void  ADC12_Configure_Mode(ADC12_10bitor12bit_TypeDef ADC12_BIT_SELECTED  , ADC12_ConverMode_TypeDef  ADC12_ConverMode  , U8_T ADC12_PRI, U8_T adc12_SHR , U8_T ADC12_DIV , U8_T NumConver ) 
{
	ADC0->MR=ADC12_DIV|((NumConver-1)<<10);
	if(ADC12_ConverMode==One_shot_mode)
	{
		ADC0->MR&=~CONTCV;								//one short mode
		while(ADC0->SR&ADC12_CTCVS);							
	}
	else if(ADC12_ConverMode==Continuous_mode)
	{
		ADC0->MR|=CONTCV;								//Continuous mode
		while(!(ADC0->SR&ADC12_CTCVS));							
	}
	ADC12_CMD(ENABLE);									//ADC0 enable
	if(ADC12_BIT_SELECTED)
	{
		ADC0->CR|=ADC12_10BITor12BIT;
	}
	else
	{
		ADC0->CR&=~ADC12_10BITor12BIT;
	}
	//ADC0->CR|=ADC12_VREF_VDD | ADC12_FVR_DIS;
	ADC0->PRI=ADC12_PRI;
	ADC0->SHR=adc12_SHR;						//采样保持周期
} 
/*************************************************************/
//ADC12 VREF slection=VDD
//EntryParameter:NONE
//ReturnValue:None
/*************************************************************/ 
void ADC12_Configure_VREF_Selecte(ADC12_VREFP_VREFN_Selected_TypeDef ADC12_VREFP_X_VREFN_X )
{
	if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_VDD_VREFN_VSS)
	{
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x00<<6);
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_EXIT_VREFN_VSS)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF)  | 0x00000800;							
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x01<<6);
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_FVR2048_VREFN_VSS)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF)  | 0x00000800;							
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x02<<6)|(0X01<<24)|(0X00<<25);
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_FVR4096_VREFN_VSS)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF)  | 0x00000800;							
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x03<<6)|(0X01<<24)|(0X01<<25);
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_INTVREF1000_VREFN_VSS)
	{								
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x04<<6)|(0X00<<16)|(0X02<<17);
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_VDD_VREFN_EXIT)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00008000;	
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x08<<6);
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_EXIT_VREFN_EXIT)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00008000;
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF)  | 0x00000800;			
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x09<<6);
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_FVR2048_VREFN_EXIT)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00008000;	
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF)  | 0x00000800;
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x0A<<6)|(0X01<<24)|(0X00<<25);			
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_FVR4096_VREFN_EXIT)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00008000;	
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF)  | 0x00000800;
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x0B<<6)|(0X01<<24)|(0X01<<25);	
	}
	else if(ADC12_VREFP_X_VREFN_X==ADC12_VREFP_INTVREF1000_VREFN_EXIT)
	{
		GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00008000;					
		ADC0->CR=(ADC0->CR&0xfcfefc3f)|(0x0C<<6)|(0X00<<16)|(0X02<<17);	
	}
}
/*************************************************************/
//ADC12 Compare function set
//EntryParameter:ConverNum_CM0,ConverNum_CM1,CMP0_data,CMP1_data
//ConverNum_CM0:VALUE=(0~15)
//ConverNum_CM1:VALUE=(0~15)
//CMP0_data:VALUE=(1~(0X3FF/0XFFF))
//CMP1_data:VALUE=(1~(0X3FF/0XFFF))
//ReturnValue:NONE
/*************************************************************/ 
  //ConverNum_CM0:Number of Conversions for Compare Function
  //ConverNum_CM1:Number of Conversions for Compare Function
  //ADC will generate a CMPxH/CMPxL interrupt when result of this number of conversion is higher/lower than data set in ADC_CMPx register.
  //ConverNum_CM1Number of Conversions for Compare Function
  //ADC will generate a CMP1H/CMP1L interrupt when result of this number of conversion is greater/less than data set in ADC_CMP1 register.
  
void ADC12_CompareFunction_set(U8_T ConverNum_CM0 , U8_T ConverNum_CM1 , U16_T CMP0_data , U16_T CMP1_data ) 
{
	ADC0->MR|=((ConverNum_CM0-0)<<16)|((ConverNum_CM1-0)<<22);
	ADC0->CMP0=CMP0_data;
	ADC0->CMP1=CMP1_data;
}
/*************************************************************/
//ADC12 Conversion chanle seting
//EntryParameter:ADC12_3/4/6/8CYCLES,SEQx,ADC12_ADCINX,ADC12_CV_RepeatNum1/2/4/8/16/32/64/128
//SEQx:VALUE=(1~18)
//ADC12_ADCINX:ADC12_ADCIN0~ADC12_ADCIN17,ADC12_INTVREF,ADC12_DIV4_VDD,ADC12_VSS
//ReturnValue:NONE
/*************************************************************/ 
void ADC12_ConversionChannel_Config(ADC12_InputSet_TypeDef ADC12_ADCINX ,
						ADC12_CV_RepeatNum_TypeDef CV_RepeatTime, ADC12_Control_TypeDef AVG_Set, U8_T SEQx)
{
	switch(ADC12_ADCINX)
	{
		case 0:	
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC0 PB0.1
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFF0F)  | 0x00000010;			
			break;
		case 1:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFF0)  | 0x00000001;							//ADC1 PA0.0
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;						
			break;
		case 2:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFF0F)  | 0x00000010;							//ADC2 PA0.1
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;	
			break;
		case 3:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF)  | 0x00001000;							//ADC3 PA0.3
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;	
			break;
		case 4:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFF0FFFFF)  | 0x00100000;							//ADC4 PA0.5
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;
			break;
		case 5:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XF0FFFFFF)  | 0x01000000;							//ADC5 PA0.6
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;		
			break;
		case 6:
			GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF)  | 0x10000000;							//ADC6 PA0.7
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;
			break;
		case 7:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC7 PB0.2
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFF0FF)  | 0x00000100;
			break;
		case 8:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC8 PB0.3
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFFF)  | 0x00000000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFF0FFF)  | 0x00001000;
			break;
		case 9:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC9 PA0.8
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)  | 0x00000001;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;	
			break;
		case 10:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC10 PA0.9
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFF0F)  | 0x00000010;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;
			break;
		case 11:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC11 PA0.10
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFF0FF)  | 0x00000100;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;			
			break;
		case 12:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC12 PA0.11
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFF0FFF)  | 0x00001000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;	
			break;
		case 13:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC13 PA0.12
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFF0FFFF)  | 0x00010000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;		
			break;
		case 14:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC14 PA0.13	
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFF0FFFFF)  | 0x00100000;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;		
			break;
		case 15:
			GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFFF)  | 0x00000000;							//ADC15 PA0.8
			GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0)  | 0x00000001;	
			GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFFF)  | 0x00000000;		
			break;
		//case 18: break;
		//case 19: break;
		//case 20: break;
		//case 21: break;
		//case 22: break;
		//case 23: break;
		//case 24: break;
		//case 25: break;
		//case 26: break;
		//case 27: break;
		case 0x1Cul: break;
		case 0x1Dul: break;
		case 0x1Eul: break;
	}
	ADC0->SEQ[SEQx] = ADC0->SEQ[SEQx] & 0;
	ADC0->SEQ[SEQx] = ADC0->SEQ[SEQx] | ADC12_ADCINX  | CV_RepeatTime | AVG_Set;
}
/*************************************************************/
//ADC12 Compare statue output
//EntryParameter:NBRCMPx_TypeDef,NBRCMPX_L_TypeDef
//NBRCMPx_TypeDef:NBRCMP0_TypeDef,NBRCMP1_TypeDef
//NBRCMPX_L_TypeDef:NBRCMPX_L_TypeDef,NBRCMPX_H_TypeDef
//ReturnValue:ADC12 Compare result flag
/*************************************************************/ 
  //output statue:ADC-SR(ADC12_CMP0H/ADC12_CMP0L/ADC12_CMP1H/ADC12_CMP1L)
U8_T ADC12_Compare_statue(ADC12_NBRCMPx_TypeDef ADC12_NBRCMPx, ADC12_NBRCMPx_HorL_TypeDef ADC12_NBRCMPx_HorL)
{
	if(ADC12_NBRCMPx==NBRCMP0_TypeDef)
	{
		if(ADC12_NBRCMPx_HorL==NBRCMPX_L_TypeDef)
		{
			return((ADC0->SR)&ADC12_CMP0L);
		}
		else
		{
			return((ADC0->SR)&ADC12_CMP0H);
		}
		
	}
	else
	{
		if(ADC12_NBRCMPx_HorL==NBRCMPX_L_TypeDef)
		{
			return((ADC0->SR)&ADC12_CMP1L);
		}
		else
		{
			return((ADC0->SR)&ADC12_CMP1H);
		}
	}
}
/*************************************************************/
//ADC Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void ADC_Int_Enable(void)
{
    ADC0->CSR=0xFFFFFFFF;
	INTC_ISER_WRITE(ADC_INT);    
}
/*************************************************************/
//ADC Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void ADC_Int_Disable(void)
{
    INTC_ICER_WRITE(ADC_INT);    
}