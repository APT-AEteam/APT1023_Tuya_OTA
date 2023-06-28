/*
  ******************************************************************************
  * @file    apt32f102_et.h
  * @author  APT AE Team
  * @version V0.50
  * @date    2019/04/05
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
#ifndef _apt32f102_et_H
#define _apt32f102_et_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


#define ET_RESET_VALUE  (0x00000000)
//--------------------------------------------------------------------------------
//-----------------------------ET  value enum define--------------------------
//--------------------------------------------------------------------------------
/**
  * @brief  ET SWTRG register
  */
typedef enum
{
    ET_SWTRG_CH0 = 0,
	ET_SWTRG_CH1 = (1<<1),
	ET_SWTRG_CH2 = (1<<2),
	ET_SWTRG_CH3 = (1<<3),
	ET_SWTRG_CH4 = (1<<4),
	ET_SWTRG_CH5 = (1<<5),
	ET_SWTRG_CH6 = (1<<6),
	ET_SWTRG_CH7 = (1<<7),
}CRC_ETSWTRG_TypeDef;
/**
  * @brief  SRCSEL register
  */
typedef enum
{
    ET_SRC0 = 0,
	ET_SRC1 = 1,
	ET_SRC2 = 2,
}CRC_ESRCSEL_TypeDef;
/**
  * @brief  SRCSEL register
  */
typedef enum
{
    ET_DST0 = 0,
	ET_DST1 = 1,
	ET_DST2 = 2,
}CRC_DSTSEL_TypeDef;
/**
  * @brief  SRCSEL register
  */
typedef enum
{
    ET_CH3 = 0,
	ET_CH4 = 1,
	ET_CH5 = 2,
	ET_CH6 = 3,
	ET_CH7 = 4,
}CRC_ETCHX_TypeDef;
/**
  * @brief  TRIG MODE register
  */
typedef enum
{
    TRG_HW = (0X00<<1),
	TRG_SW = (0X01<<1),
}CRC_TRIGMODE_TypeDef;

//Source IP Event
#define ET_LPT_SYNC  (0X0)
#define ET_EXI_SYNC0 (0X4)
#define ET_EXI_SYNC1 (0X5)
#define ET_EXI_SYNC2 (0X6)
#define ET_EXI_SYNC3 (0X7)
#define ET_EXI_SYNC4 (0X8)
#define ET_EXI_SYNC5 (0X9)
#define ET_RTC_SYNC0 (0XA)
#define ET_RTC_SYNC1 (0XB)
#define ET_BT_SYNC0 (0XC)
#define ET_BT_SYNC1 (0XD)
#define ET_EPT0_SYNC0 (0X10)
#define ET_EPT0_SYNC1 (0X11)
#define ET_EPT0_SYNC2 (0X12)
#define ET_EPT0_SYNC3 (0X13)
#define ET_GPT0_SYNC0 (0X20)
#define ET_GPT0_SYNC1 (0X21)
#define ET_ADC_SYNC0 (0X30)
#define ET_ADC_SYNC1 (0X31)
#define ET_TOUCH_SYNC (0X3C)
//Destination IP Event
#define ET_LPT_TRGSRC  (0X0)
#define ET_BT0_TRGSRC0  (0X2)
#define ET_BT0_TRGSRC1  (0X3)
#define ET_BT1_TRGSRC0  (0X4)
#define ET_BT1_TRGSRC1  (0X5)
#define ET_ADC_TRGSRC0  (0X6)
#define ET_ADC_TRGSRC1  (0X7)
#define ET_ADC_TRGSRC2  (0X8)
#define ET_ADC_TRGSRC3  (0X9)
#define ET_ADC_TRGSRC4  (0XA)
#define ET_ADC_TRGSRC5  (0XB)
#define ET_EPT0_TRGSRC0  (0X10)
#define ET_EPT0_TRGSRC1  (0X11)
#define ET_EPT0_TRGSRC2  (0X12)
#define ET_EPT0_TRGSRC3  (0X13)
#define ET_EPT0_TRGSRC4  (0X14)
#define ET_EPT0_TRGSRC5  (0X15)
#define ET_GPT0_TRGSRC0  (0X24)
#define ET_GPT0_TRGSRC1  (0X25)
#define ET_GPT0_TRGSRC2  (0X26)
#define ET_GPT0_TRGSRC3  (0X27)
#define ET_GPT0_TRGSRC4  (0X28)
#define ET_GPT0_TRGSRC5  (0X29)
#define ET_TOUCH_TRGSRC  (0X3C)




extern void ET_DeInit(void);
extern void ET_ENABLE(void);
extern void ET_DISABLE(void);
extern void ET_SWTRG_CMD(CRC_ETSWTRG_TypeDef ETSWTRG_X,FunctionalStatus NewState);
extern void ET_CH0_SRCSEL(CRC_ESRCSEL_TypeDef ESRCSEL_X,FunctionalStatus NewState,U8_T SRCSEL_X);
extern void ET_CH0_CONTROL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T DSTSEL_X);
extern void ET_CH1_SRCSEL(CRC_DSTSEL_TypeDef DST_X,FunctionalStatus NewState,U8_T DSTSEL_X);
extern void ET_CH1_CONTROL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T DSTSEL_X);
extern void ET_CH2_SRCSEL(CRC_DSTSEL_TypeDef DST_X,FunctionalStatus NewState,U8_T DSTSEL_X);
extern void ET_CH2_CONTROL(FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T DSTSEL_X);
extern void ET_CHx_CONTROL(CRC_ETCHX_TypeDef ETCHX,FunctionalStatus NewState,CRC_TRIGMODE_TypeDef TRIGMODEX,U8_T SRCSEL_X,U8_T DSTSEL_X);



#endif   /**< apt32f102_crc_H */