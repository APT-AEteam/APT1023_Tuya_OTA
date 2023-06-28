/*
  ******************************************************************************
  * @file    apt32f102_interrupt.c
  * @author  APT AE Team
  * @version V0.50
  * @date    2020/05/14
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
#include "apt32f102_rtc.h"
/* define --------------------------------------------------------------------*/
RTC_time_t  RTC_TimeDate_buf;
RTC_Alarmset_T RTC_AlarmA_buf;
RTC_Alarmset_T RTC_AlarmB_buf;
/* externs--------------------------------------------------------------------*/

/*************************************************************/
//Deinitializes the RTC registers to their default reset
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/    
void RTC_RST_VALUE(void)									//reset value
{
	RTC->TIMR=RTC_TIMR_RST;
	RTC->DATR=RTC_DATR_RST;
	RTC->CR=RTC_CR_RST;
	RTC->CCR=RTC_CCR_RST;
	RTC->ALRAR=RTC_ALRAR_RST;
	RTC->ALRBR=RTC_ALRBR_RST;
	RTC->SSR=RTC_SSR_RST;
	RTC->CAL=RTC_CAL_RST;
	RTC->IMCR=RTC_IMCR_RST;
	RTC->EVTRG=RTC_EVTRG_RST;
	RTC->EVPS=RTC_EVPS_RST;
}
/*************************************************************/
//Deinitializes the RTC GPIO
//EntryParameter:Rtc_Output_Mode_TypeDef
//Rtc_Output_Mode_x:Alarm_A_pulse_output,Alarm_A_High,Alarm_A_Low,Alarm_B_pulse_output,Alarm_B_High,Alarm_B_Low
//ReturnValue:NONE
/*************************************************************/ 
void RTC_ALM_IO_SET(Rtc_Output_Mode_TypeDef Rtc_Output_Mode_x )
{
	GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF)|0X00000500;
	RTC->KEY=0XCA53;
	RTC->CR=(RTC->CR&0XFFFFE3FF)|Rtc_Output_Mode_x;
}
/*************************************************************/
//Deinitializes the RTC clk config
//EntryParameter:CLKSRC_X,DIVS,DIVA
//CLKSRC_X:CLKSRC_ISOSC,CLKSRC_IMOSC,CLKSRC_EMOSC
//DIVS:0~0X7FFF
//DIVA:0~0X7F
//ReturnValue:NONE
/*************************************************************/ 
//RTC CLK=(EMCLK/4)/(DIVS+1)/(DIVA+1)/4
//		  (ISCLK)/(DIVS+1)/(DIVA+1)/4
//		  (IMCLK/4)/(DIVS+1)/(DIVA+1)/4
void RTCCLK_CONFIG(U16_T DIVS , U16_T DIVA , RTC_CLKSRC_TypeDef CLKSRC_X)
{
	RTC->KEY=0XCA53;
	RTC->CCR|=(0X01<<27);
	while(!(RTC->CCR&0x04000000));													//等待RTC稳定
	RTC->CCR=(RTC->CCR&0xfc000000)|DIVS|(DIVA<<16)|(0X01<<23)|CLKSRC_X;
	while(!(RTC->CCR&0x04000000));													//等待RTC稳定
}
/*************************************************************/
//Deinitializes the RTC function config
//EntryParameter:RTC_FMT_MODE_TypeDef,RTC_CPRD_TypeDef,Rtc_ClockOutput_Mode_TypeDe
//RTC_FMT_MODE:RTC_24H,RTC_12H
//RTC_CPRD_x:CPRD_NONE,CPRD_05S,CPRD_1S,CPRD_1MIN,CPRD_1HOUR,CPRD_1DAY,CPRD_1MONTH
//Rtc_ClockOutput_x:COSEL_Cali_512hz,COSEL_Cali_1hz,COSEL_NoCali_512hz,COSEL_NoCali_1hz
//ReturnValue:NONE
/*************************************************************/ 
void RTC_Function_Config(RTC_FMT_MODE_TypeDef RTC_FMT_MODE , RTC_CPRD_TypeDef RTC_CPRD_x , Rtc_ClockOutput_Mode_TypeDef Rtc_ClockOutput_x)
{
	RTC->KEY=0XCA53;
	RTC->CR=(RTC->CR&0xffff1cdf)|RTC_FMT_MODE|RTC_CPRD_x|Rtc_ClockOutput_x|0X01<<16;//enable read									
}
/*************************************************************/
//Deinitializes the RTC Start
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/ 
void RTC_Start(void)
{
	RTC->KEY=0XCA53;
	RTC->CR=RTC->CR&0xfffffffe;													
	while((RTC->CR&0x01)!=0||(RTC->CR&0x02)==2);
}
/*************************************************************/
//Deinitializes the RTC Stop
//EntryParameter:
//ReturnValue:NONE
/*************************************************************/ 
void RTC_Stop(void)
{
	RTC->KEY=0XCA53;
	RTC->CR=RTC->CR|0x01;
	while((RTC->CR&0x01)!=1||(RTC->CR&0x02)==2);
}
/*************************************************************/
//Deinitializes the RTC timer date set
//EntryParameter:*RTC_TimeDate
//ReturnValue:NONE
/*************************************************************/ 
void RTC_TIMR_DATR_SET(RTC_time_t *RTC_TimeDate)
{
	RTC->KEY=0XCA53;
	RTC->TIMR=(RTC_TimeDate->u8Hour<<16)|(RTC_TimeDate->u8Minute<<8)|(RTC_TimeDate->u8Second);			//Hour bit6->0:am 1:pm
	RTC->DATR=(RTC_TimeDate->u8DayOfWeek<<24)|(RTC_TimeDate->u8Year<<16)|(RTC_TimeDate->u8Month<<8)|(RTC_TimeDate->u8Day<<0);		
	while(RTC->CR&0x02);//busy 判断TIMR DATR ALRAR ALRBR数据写完
}
/*************************************************************/
//Deinitializes the RTC timer date Read
//EntryParameter:*RTC_TimeDate
//ReturnValue:NONE
/*************************************************************/ 
void RTC_TIMR_DATR_Read(RTC_time_t *RTC_TimeDate)
{
	RTC->KEY=0XCA53;
	//RTC->CR|=0X01<<16;								//enable read
	//while(RTC->CR&0x02);//busy 判断TIMR DATR ALRAR ALRBR数据写完
	RTC_TimeDate->u8Second=(RTC->TIMR)&0x7f;
	RTC_TimeDate->u8Minute=(RTC->TIMR>>8)&0x7f;
	RTC_TimeDate->u8Hour=(RTC->TIMR>>16)&0x7f;
	RTC_TimeDate->u8Day=(RTC->DATR)&0x7f;
	RTC_TimeDate->u8Month=(RTC->DATR>>8)&0x7f;
	RTC_TimeDate->u8Year=(RTC->DATR>>16)&0x7f;
	RTC_TimeDate->u8DayOfWeek=(RTC->DATR>>24)&0x7f;
	//RTC->CR&=0XFFFEFFFF;							//disable read
}
/*************************************************************/
//Deinitializes the RTC AlarmA set
//EntryParameter:*RTC_AlarmA,RTC_Alarm_Second_mask_TypeDef,RTC_Alarm_Minute_mask_TypeDef,
//				 RTC_Alarm_Hour_mask_TypeDef,RTC_Alarm_DataOrWeek_mask_TypeDef,RTC_Alarm_WeekData_select_TypeDef,
//				 RTC_Alarm_Register_select_TypeDef
//RTC_Alarm_Second_x:Alarm_Second_EN,Alarm_Second_DIS
//RTC_Alarm_Minute_x:Alarm_Minute_EN,Alarm_Minute_DIS
//RTC_Alarm_Hour_x:Alarm_Hour_EN,Alarm_Hour_DIS
//RTC_Alarm_DataOrWeek_x:Alarm_DataOrWeek_EN,Alarm_DataOrWeek_DIS
//Alarm_x_selecte:Alarm_data_selecte,Alarm_week_selecte
//Alarm_x:Alarm_A,Alarm_B
//ReturnValue:NONE
/*************************************************************/ 
void RTC_Alarm_TIMR_DATR_SET(RTC_Alarm_Register_select_TypeDef Alarm_x  , RTC_Alarmset_T *RTC_AlarmA , RTC_Alarm_Second_mask_TypeDef RTC_Alarm_Second_x ,
						RTC_Alarm_Minute_mask_TypeDef RTC_Alarm_Minute_x , RTC_Alarm_Hour_mask_TypeDef RTC_Alarm_Hour_x,
						RTC_Alarm_DataOrWeek_mask_TypeDef RTC_Alarm_DataOrWeek_x,
						RTC_Alarm_WeekData_select_TypeDef Alarm_x_selecte)
{
	RTC->KEY=0XCA53;
	if(Alarm_x==Alarm_A)
	{
		RTC->CR=RTC->CR&0xfffffff7;
		RTC->ALRAR=(Alarm_x_selecte)|(RTC_Alarm_DataOrWeek_x)|(RTC_Alarm_Hour_x)|(RTC_Alarm_Minute_x)|(RTC_Alarm_Second_x)|
				(RTC_AlarmA->u8WeekOrData<<24)|(RTC_AlarmA->u8Hour<<16)|(RTC_AlarmA->u8Minute<<8)|(RTC_AlarmA->u8Second);		
		RTC->CR|=Alarm_A_EN;		
	}
	if(Alarm_x==Alarm_B)
	{
		RTC->CR=RTC->CR&0xffffffef;
		RTC->ALRBR=(Alarm_x_selecte)|(RTC_Alarm_DataOrWeek_x)|(RTC_Alarm_Hour_x)|(RTC_Alarm_Minute_x)|(RTC_Alarm_Second_x)|
				(RTC_AlarmA->u8WeekOrData<<24)|(RTC_AlarmA->u8Hour<<16)|(RTC_AlarmA->u8Minute<<8)|(RTC_AlarmA->u8Second);		
		RTC->CR|=Alarm_B_EN;				
	}
		
	while(RTC->CR&0x02);//busy 判断TIMR DATR ALRAR ALRBR数据写完
}
/*************************************************************/
//Deinitializes the RTC AlarmA read
//EntryParameter:*RTC_AlarmA
//ReturnValue:NONE
/*************************************************************/
void RTC_AlarmA_TIMR_DATR_Read(RTC_Alarmset_T *RTC_AlarmA)
{
	RTC->KEY=0XCA53;
	//RTC->CR|=0X01<<16;									//enable read
	//while(RTC->CR&0x02);//busy 判断TIMR DATR ALRAR ALRBR数据写完
	RTC_AlarmA->u8Second=(RTC->ALRAR)&0x7f;
	RTC_AlarmA->u8Minute=(RTC->ALRAR>>8)&0x7f;
	RTC_AlarmA->u8Hour=(RTC->ALRAR>>16)&0x7f;
	RTC_AlarmA->u8WeekOrData=(RTC->ALRAR>>24)&0x3f;
	//RTC->CR&=0XFFFEFFFF;								//disable read
}		
/*************************************************************/
//Deinitializes the RTC AlarmB read
//EntryParameter:*RTC_AlarmB
//ReturnValue:NONE
/*************************************************************/
void RTC_AlarmB_TIMR_DATR_Read(RTC_Alarmset_T *RTC_AlarmB)
{
	RTC->KEY=0XCA53;
	//RTC->CR|=0X01<<16;								//enable read
	//while(RTC->CR&0x02);//busy 判断TIMR DATR ALRAR ALRBR数据写完
	RTC_AlarmB->u8Second=(RTC->ALRBR)&0x7f;
	RTC_AlarmB->u8Minute=(RTC->ALRBR>>8)&0x7f;
	RTC_AlarmB->u8Hour=(RTC->ALRBR>>16)&0x7f;
	RTC_AlarmB->u8WeekOrData=(RTC->ALRBR>>24)&0x3f;
	//RTC->CR&=0XFFFEFFFF;							//disable read
}
/*************************************************************/
//RTC EVTRG Config
//EntryParameter:RTC_EVTRG_TRGSRC0_x,RTC_TRGSRCX_CMD,Trgev0Prd
//RTC_EVTRG_TRGSRC0_x:RTC_EVTRG_TRGSRC0_DIS,RTC_EVTRG_TRGSRC0_AlarmA,
//RTC_EVTRG_TRGSRC0_AlarmB,RTC_EVTRG_TRGSRC0_AlarmAB,RTC_EVTRG_TRGSRC0_CPRD
//RTC_TRGSRCX_CMD:RTC_TRGSRC0_EN,RTC_TRGSRC0_DIS
//Trgev0Prd:0~0x0f
//ReturnValue: NONE
/*************************************************************/
void RTC_TRGSRC0_Config(RTC_EVTRG_TRGSRC0_TypeDef RTC_EVTRG_TRGSRC0_x , RTC_TRGSRCX_CMD_TypeDef RTC_TRGSRCX_CMD , U8_T Trgev0Prd)
{
	RTC->EVTRG=(RTC->EVTRG&0XFFEFFFF0)|RTC_EVTRG_TRGSRC0_x|RTC_TRGSRCX_CMD;
	RTC->EVPS=(RTC->EVPS&0XFFFFFFF0)|Trgev0Prd;
}
/*************************************************************/
//RTC EVTRG SWFTRG
//EntryParameter:RTC_EVTRG_TRGSRC1_x,RTC_TRGSRCX_CMD,Trgev1Prd
//RTC_EVTRG_TRGSRC1_x:RTC_EVTRG_TRGSRC1_DIS,RTC_EVTRG_TRGSRC1_AlarmA,
//RTC_EVTRG_TRGSRC1_AlarmB,RTC_EVTRG_TRGSRC1_AlarmAB,RTC_EVTRG_TRGSRC1_CPRD
//RTC_TRGSRCX_CMD:RTC_TRGSRC1_EN,RTC_TRGSRC1_DIS
//Trgev1Prd:0~0x0f
//ReturnValue: NONE
/*************************************************************/
void RTC_TRGSRC1_Config(RTC_EVTRG_TRGSRC1_TypeDef RTC_EVTRG_TRGSRC1_x , RTC_TRGSRCX_CMD_TypeDef RTC_TRGSRCX_CMD , U8_T Trgev1Prd)
{
	RTC->EVTRG=(RTC->EVTRG&0XFFDFFF0F)|RTC_EVTRG_TRGSRC1_x|RTC_TRGSRCX_CMD;
	RTC->EVPS=(RTC->EVPS&0XFFFFFF0F)|Trgev1Prd<<4;
}
/*************************************************************/
//RTC EVTRG SWFTRG
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void RTC_TRGSRC0_SWFTRG(void)
{
	RTC->EVSWF|=0X01;
}
/*************************************************************/
//RTC EVTRG SWFTRG
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void RTC_TRGSRC1_SWFTRG(void)
{
	RTC->EVSWF|=0X02;
}
/*************************************************************/
//RTC INT ENABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void RTC_Int_Enable(RTC_INT_TypeDef RTC_X_INT)
{
	RTC->ICR = RTC_X_INT;							//clear LVD INT status
	RTC->IMCR  |= RTC_X_INT;
}
/*************************************************************/
//RTC INT DISABLE.
//EntryParameter:NONE
//ReturnValue: NONE
/*************************************************************/
void RTC_Int_Disable(RTC_INT_TypeDef RTC_X_INT)
{
	RTC->IMCR  &= ~RTC_X_INT;
}
/*************************************************************/
//RTC Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void RTC_Vector_Int_Enable(void)
{
	INTC_ISER_WRITE(RTC_INT);    
}
/*************************************************************/
//RTC Interrupt disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void RTC_Vector_Int_Disable(void)
{
    INTC_ICER_WRITE(RTC_INT);    
}
/*************************************************************/
//RTC Wake up enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void RTC_WakeUp_Enable(void)
{
    INTC_IWER_WRITE(RTC_INT);    
}

/*************************************************************/
//RTC Wake up disable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void RTC_WakeUp_Disable(void)
{
    INTC_IWDR_WRITE(RTC_INT);    
}

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/