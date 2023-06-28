/*
  ******************************************************************************
  * @file    apt32f102_countera.h
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
#ifndef _apt32f102_countera_H
#define _apt32f102_lpt_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


#define CA_RESET_VALUE  (0x00000000)
//--------------------------------------------------------------------------------
//-----------------------------countA  value enum define--------------------------
//--------------------------------------------------------------------------------
/**
  * @brief  countA Period int 
  */
typedef enum
{
    Period_NA  = 0,                            //Interrupt enable/disable for High/low period elapsed              
    Period_H   = 1,
    Period_L   = 2,
    Period_H_L = 3,                                                  
}CA_INT_TypeDef;
/**
  * @brief  countA DIV 
  */
typedef enum
{
    DIV1    =	((0 & 0x03ul)<<4) ,            //Counter A input clock frequency selection 
    DIV2    =	((1 & 0x03ul)<<4) ,
    DIV4    =	((2 & 0x03ul)<<4) ,
    DIV8    =	((3 & 0x03ul)<<4) ,
}CA_CLKDIV_TypeDef;
/**
  * @brief  countA mode
  */
typedef enum
{
    ONESHOT_MODE    =	(0x00ul << 1),          //Mode Selection:oneshotmode/repeat mode
    REPEAT_MODE     =	(0x01ul << 1),
}CA_Mode_TypeDef;
/**
  * @brief  countA carrier setting 
  */
typedef enum
{
    CARRIER_OFF 	=	(0x00ul << 25),         //Carrier signal
    CARRIER_ON  	=	(0x01ul << 25),
}CA_CARRIER_TypeDef;
/**
  * @brief  Carrier Waveform Output Starting Polarity
  */
typedef enum
{
    OSP_LOW 	=	0,                          //Carrier Waveform Output Starting Polarity
    OSP_HIGH    =	1,
}CA_OSP_TypeDef;
/**
  * @brief  Carrier register load
  */
typedef enum
{
    HW_STROBE_0 =   (0x01ul<<17),               //Counter A data register Hardware/software load enable.  
    HW_STROBE_1 =   (0x01ul<<18),
    SW_STROBE   =   (0x01ul<<16), 
}CA_STROBE_TypeDef;
/**
  * @brief  Carrier rem output signal
  */
typedef enum
{
    ENVELOPE_0    =	(0x00ul << 24),             //REM output signal selection bit
    ENVELOPE_1    =	(0x01ul << 24),
}CA_ENVELOPE_TypeDef;
/**
  * @brief  Carrier PENDREM 
  */
typedef enum
{
    PENDREM_OFF  =	((0 & 0x03ul)<<21),
    PENDREM_1    =	((1 & 0x03ul)<<21),
    PENDREM_2    =	((2 & 0x03ul)<<21),
}CA_PENDREM_TypeDef;
/**
  * @brief  Carrier ATCHREM 
  */
typedef enum
{
    MATCHREM_OFF  =	((0 & 0x03ul)<<19),
    MATCHREM_1    =	((1 & 0x03ul)<<19),
    MATCHREM_2    =	((2 & 0x03ul)<<19),
}CA_MATCHREM_TypeDef;
/**
  * @brief  Carrier REMSTAT
  */
typedef enum
{
   REMSTAT_0   =	((0 & 0x01ul)<<23),
   REMSTAT_1   =	((1 & 0x01ul)<<23),
}CA_REMSTAT_TypeDef;
/**
  * @brief  counterA IO
  */
typedef enum
{
   COUNTA_PB01   =	0,
   COUNTA_PA05   =	1,
   COUNTA_PA11   =	2,
}CA_COUNTAIO_TypeDef;



extern void COUNTA_Init(uint32_t Data_H,uint32_t Data_L,CA_INT_TypeDef INT_Mode,
                     CA_CLKDIV_TypeDef DIVx,CA_Mode_TypeDef Mode,CA_CARRIER_TypeDef Carrier,
                     CA_OSP_TypeDef OSP_Mode) ;
extern void COUNTA_Config(CA_STROBE_TypeDef STROBE,CA_PENDREM_TypeDef Pend_CON,
                        CA_MATCHREM_TypeDef Match_CON,CA_REMSTAT_TypeDef Stat_CON,CA_ENVELOPE_TypeDef ENVELOPE );
extern void COUNT_DeInit(void);
extern void COUNTA_Start(void);
extern void COUNTA_Stop(void);
extern void COUNTA_Int_Disable(void);
extern void COUNTA_Int_Enable(void);
extern void COUNTA_Wakeup_Disable(void);
extern void COUNTA_Wakeup_Enable(void);
extern void COUNTA_IO_Init(CA_COUNTAIO_TypeDef COUNTA_IO_G);
extern void COUNTA_Data_Update(uint32_t Data_H,uint32_t Data_L);



/*************************************************************/

#endif   /**< apt32f102_countera_H */

/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/