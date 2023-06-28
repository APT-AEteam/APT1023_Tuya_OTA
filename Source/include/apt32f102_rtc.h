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
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _apt32f102_rtc_H
#define _apt32f102_rtc_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"
/******************************************************************************
************************* rtc Registers Definition *************************
******************************************************************************/
/** @addtogroup RTC Registers Reset Value
  * @{
  */

#define RTC_TIMR_RST     	((CSP_REGISTER_T)0x00000000)
#define RTC_DATR_RST     	((CSP_REGISTER_T)0x00000000)
#define RTC_CR_RST     		((CSP_REGISTER_T)0x00000001)
#define RTC_CCR_RST     	((CSP_REGISTER_T)0x00800000)
#define RTC_ALRAR_RST		((CSP_REGISTER_T)0x00000000)
#define	RTC_ALRBR_RST		((CSP_REGISTER_T)0x00000000)
#define RTC_SSR_RST			((CSP_REGISTER_T)0x00000000)
#define RTC_CAL_RST			((CSP_REGISTER_T)0x00000000)
#define RTC_IMCR_RST		((CSP_REGISTER_T)0x00000000)
#define RTC_EVTRG_RST		((CSP_REGISTER_T)0x00000000)
#define RTC_EVPS_RST		((CSP_REGISTER_T)0x00000000)

//RTC KEY
#define  RTC_KEY 	(0XCA53ul)

/**
  * @brief  RTC DIVS Control
  */
typedef enum
{
	CLKSRC_ISOSC				=	 	(CSP_REGISTER_T)(0x00ul<<24),
	CLKSRC_IMOSC_4div			=	 	(CSP_REGISTER_T)(0x01ul<<24),
	CLKSRC_EMOSC				=	 	(CSP_REGISTER_T)(0x02ul<<24),
	CLKSRC_EMOSC_4div			=	 	(CSP_REGISTER_T)(0x03ul<<24)
}RTC_CLKSRC_TypeDef;
	

/**
  * @brief  RTC INT register 
  */
typedef enum
{
	//RISR IMCR MISR ICR
	ALRA_INT        	=		((CSP_REGISTER_T)(0x01ul << 0)),  
	ALRB_INT      		=		((CSP_REGISTER_T)(0x01ul << 1)),    
	CPRD_INT        	=		((CSP_REGISTER_T)(0x01ul << 2)),   
	RTC_TRGEV0_INT      =		((CSP_REGISTER_T)(0x01ul << 3)),    
	RTC_TRGEV1_INT      =		((CSP_REGISTER_T)(0x01ul << 4))     
}RTC_INT_TypeDef;

/**
  * @brief  RTC Alarm SEC MIN DAY mask
  */
 typedef enum
{
	Alarm_Second_Compare_EN			=		((CSP_REGISTER_T)(0x00ul << 7)),  
	Alarm_Second_Compare_DIS		=		((CSP_REGISTER_T)(0x01ul << 7)),  
} RTC_Alarm_Second_mask_TypeDef;	
 typedef enum
{
	Alarm_Minute_Compare_EN			=		((CSP_REGISTER_T)(0x00ul << 15)),  
	Alarm_Minute_Compare_DIS		=		((CSP_REGISTER_T)(0x01ul << 15)), 
} RTC_Alarm_Minute_mask_TypeDef;
 typedef enum
{	 
	Alarm_Hour_Compare_EN			=		((CSP_REGISTER_T)(0x00ul << 23)),  
	Alarm_Hour_Compare_DIS			=		((CSP_REGISTER_T)(0x01ul << 23)), 
} RTC_Alarm_Hour_mask_TypeDef;		
 typedef enum
{
	Alarm_DataOrWeek_Compare_EN		=		((CSP_REGISTER_T)(0x00ul << 31)), 
	Alarm_DataOrWeek_Compare_DIS	=		((CSP_REGISTER_T)(0x01ul << 31)) 
} RTC_Alarm_DataOrWeek_mask_TypeDef;	;
/**
  * @brief  RTC Alarm week data select
  */
 typedef enum
{
	Alarm_data_selecte		=		((CSP_REGISTER_T)(0x00ul << 30)),  
	Alarm_week_selecte		=		((CSP_REGISTER_T)(0x01ul << 30))  
} RTC_Alarm_WeekData_select_TypeDef;
/**
  * @brief  RTC Alarm Register select
  */
 typedef enum
{
	Alarm_A		=		0,  
	Alarm_B		=		1 
}RTC_Alarm_Register_select_TypeDef;  

/**
  * @brief  RTC Alarm io output mode
  */
 typedef enum
{
	Alarm_A_pulse_output 	=	((CSP_REGISTER_T)(0x00ul << 10)),  
	Alarm_A_High			=	((CSP_REGISTER_T)(0x01ul << 10)),  
	Alarm_A_Low				=	((CSP_REGISTER_T)(0x02ul << 10)),  
	Alarm_B_pulse_output	=	((CSP_REGISTER_T)(0x04ul << 10)),  
	Alarm_B_High			=	((CSP_REGISTER_T)(0x05ul << 10)), 
	Alarm_B_Low				=	((CSP_REGISTER_T)(0x06ul << 10)), 
}Rtc_Output_Mode_TypeDef;
/**
  * @brief  RTC Alarm IO clock outpu
  */
 typedef enum
{
	COSEL_Cali_512hz 		=	((CSP_REGISTER_T)(0x00ul << 8)),  
	COSEL_Cali_1hz			=	((CSP_REGISTER_T)(0x01ul << 8)),  
	COSEL_NoCali_512hz		=	((CSP_REGISTER_T)(0x02ul << 8)),  
	COSEL_NoCali_1hz		=	((CSP_REGISTER_T)(0x03ul << 8)),  
}
Rtc_ClockOutput_Mode_TypeDef;
/**
  * @brief  RTC AlarmA cmd select
  */
 typedef enum
{
	Alarm_A_EN 			=	((CSP_REGISTER_T)(0x01ul << 3)),  
	Alarm_A_DIS			=	((CSP_REGISTER_T)(0x00ul << 3)),  

}RTC_AlarmA_CMD_TypeDef;
/**
  * @brief  RTC AlarmB cmd  select
  */
 typedef enum
{
	Alarm_B_EN			=	((CSP_REGISTER_T)(0x01ul << 4)),  
	Alarm_B_DIS			=	((CSP_REGISTER_T)(0x00ul << 4)),  
}RTC_AlarmB_CMD_TypeDef;
/**
  * @brief  RTC FMT mode select
  */
 typedef enum
{
	RTC_24H			=	((CSP_REGISTER_T)(0x00ul << 5)),  
	RTC_12H			=	((CSP_REGISTER_T)(0x01ul << 5)),  
}RTC_FMT_MODE_TypeDef;
/**
  * @brief  RTC CPRD  select
  */
 typedef enum
{
	CPRD_NONE				=	((CSP_REGISTER_T)(0x00ul << 13)),  
	CPRD_05S				=	((CSP_REGISTER_T)(0x01ul << 13)),  
	CPRD_1S					=	((CSP_REGISTER_T)(0x02ul << 13)),  
	CPRD_1MIN				=	((CSP_REGISTER_T)(0x03ul << 13)),  
	CPRD_1HOUR				=	((CSP_REGISTER_T)(0x04ul << 13)),  
	CPRD_1DAY				=	((CSP_REGISTER_T)(0x05ul << 13)),  
	CPRD_1MONTH				=	((CSP_REGISTER_T)(0x06ul << 13)),  
}RTC_CPRD_TypeDef;
/**
  * @brief  RTC EVTRG TRGSRC0 SET
  */
 typedef enum
{	
	RTC_EVTRG_TRGSRC0_DIS		=	((CSP_REGISTER_T)(0x00ul )),  
	RTC_EVTRG_TRGSRC0_AlarmA	=	((CSP_REGISTER_T)(0x01ul )),  
	RTC_EVTRG_TRGSRC0_AlarmB	=	((CSP_REGISTER_T)(0x02ul )),  
	RTC_EVTRG_TRGSRC0_AlarmAB	=	((CSP_REGISTER_T)(0x03ul )),  
	RTC_EVTRG_TRGSRC0_CPRD		=	((CSP_REGISTER_T)(0x04ul )),  
}RTC_EVTRG_TRGSRC0_TypeDef;	
/**
  * @brief  RTC EVTRG TRGSRC1 SET
  */
 typedef enum
{	
	RTC_EVTRG_TRGSRC1_DIS		=	((CSP_REGISTER_T)(0x00ul<<4 )),  
	RTC_EVTRG_TRGSRC1_AlarmA	=	((CSP_REGISTER_T)(0x01ul<<4 )),  
	RTC_EVTRG_TRGSRC1_AlarmB	=	((CSP_REGISTER_T)(0x02ul<<4 )),  
	RTC_EVTRG_TRGSRC1_AlarmAB	=	((CSP_REGISTER_T)(0x03ul<<4 )),  
	RTC_EVTRG_TRGSRC1_CPRD		=	((CSP_REGISTER_T)(0x04ul<<4 )),  
}RTC_EVTRG_TRGSRC1_TypeDef;	
 typedef enum
{
	RTC_TRGSRC0_EN	=	((CSP_REGISTER_T)(0x00ul<<20 )),  
	RTC_TRGSRC0_DIS	=	((CSP_REGISTER_T)(0x01ul<<20 )),  
	RTC_TRGSRC1_EN	=	((CSP_REGISTER_T)(0x00ul<<21 )),  
	RTC_TRGSRC1_DIS	=	((CSP_REGISTER_T)(0x01ul<<21 )),  
}RTC_TRGSRCX_CMD_TypeDef;
typedef struct 
{
	uint8_t  u8Second; ///<闹钟分钟
    uint8_t  u8Minute; ///<闹钟分钟
    uint8_t  u8Hour;   ///<闹钟小时
    uint8_t  u8WeekOrData;   ///<闹钟周
}RTC_Alarmset_T;

typedef struct 
{
    uint8_t  u8Second;      ///<秒    
    uint8_t  u8Minute;      ///<分
    uint8_t  u8Hour;        ///<时
    uint8_t  u8DayOfWeek;   ///<周
    uint8_t  u8Day;         ///<日    
    uint8_t  u8Month;       ///<月
    uint8_t  u8Year;        ///<年
} RTC_time_t;


/** @addtogroup RTC_Exported_functions
  * @{
  */	
extern void RTC_RST_VALUE(void);
extern void RTCCLK_CONFIG(U16_T DIVS , U16_T DIVA , RTC_CLKSRC_TypeDef CLKSRC_X);
extern void RTC_ALM_IO_SET(Rtc_Output_Mode_TypeDef Rtc_Output_Mode_x );
extern void RTC_TIMR_DATR_SET(RTC_time_t *RTC_TimeDate);
extern void RTC_TIMR_DATR_Read(RTC_time_t *RTC_TimeDate);
extern void RTC_Alarm_TIMR_DATR_SET(RTC_Alarm_Register_select_TypeDef Alarm_x  , RTC_Alarmset_T *RTC_AlarmA , RTC_Alarm_Second_mask_TypeDef RTC_Alarm_Second_x ,
						RTC_Alarm_Minute_mask_TypeDef RTC_Alarm_Minute_x , RTC_Alarm_Hour_mask_TypeDef RTC_Alarm_Hour_x,
						RTC_Alarm_DataOrWeek_mask_TypeDef RTC_Alarm_DataOrWeek_x,
						RTC_Alarm_WeekData_select_TypeDef Alarm_x_selecte);
extern void RTC_Function_Config(RTC_FMT_MODE_TypeDef RTC_FMT_MODE , RTC_CPRD_TypeDef RTC_CPRD_x , Rtc_ClockOutput_Mode_TypeDef Rtc_ClockOutput_x);
extern void RTC_TRGSRC0_Config(RTC_EVTRG_TRGSRC0_TypeDef RTC_EVTRG_TRGSRC0_x , RTC_TRGSRCX_CMD_TypeDef RTC_TRGSRCX_CMD , U8_T Trgev0Prd);
extern void RTC_TRGSRC1_Config(RTC_EVTRG_TRGSRC1_TypeDef RTC_EVTRG_TRGSRC1_x , RTC_TRGSRCX_CMD_TypeDef RTC_TRGSRCX_CMD , U8_T Trgev1Prd);
extern void RTC_TRGSRC0_SWFTRG(void);
extern void RTC_TRGSRC1_SWFTRG(void);
extern void RTC_Start(void);
extern void RTC_Stop(void);					
extern void RTC_AlarmA_TIMR_DATR_Read(RTC_Alarmset_T *RTC_AlarmA);						
extern void RTC_AlarmB_TIMR_DATR_Read(RTC_Alarmset_T *RTC_AlarmB);
extern void RTC_Int_Enable(RTC_INT_TypeDef RTC_X_INT);
extern void RTC_Int_Disable(RTC_INT_TypeDef RTC_X_INT);
extern void RTC_Vector_Int_Enable(void);
extern void RTC_Vector_Int_Disable(void);
extern void RTC_WakeUp_Enable(void);
extern void RTC_WakeUp_Disable(void);
extern RTC_time_t  RTC_TimeDate_buf;
extern RTC_Alarmset_T RTC_AlarmA_buf;
extern RTC_Alarmset_T RTC_AlarmB_buf;	
	
#endif   /**< apt32f102_rtc_H */

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/