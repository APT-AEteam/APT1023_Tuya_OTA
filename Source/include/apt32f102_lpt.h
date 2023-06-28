/*
  ******************************************************************************
  * @file    apt32f102_lpt.h
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
#ifndef _apt32f102_lpt_H
#define _apt32f102_lpt_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


#define LPT_RESET_VALUE  (0x00000000)
//--------------------------------------------------------------------------------
//-----------------------------LPT  value enum define--------------------------
//--------------------------------------------------------------------------------
/**
  * @brief  LPT CLK EN register
  */
typedef enum
{
    LPTCLK_DIS = 0,
	LPTCLK_EN = 1,
}LPT_CLK_TypeDef;
/**
  * @brief  LPT CLK source register
  */
typedef enum
{
	LPT_PCLK_DIV4= (0<<2),
    LPT_ISCLK = (1<<2),
	LPT_IMCLK_DIV4 = (2<<2),
	LPT_EMCLK = (3<<2),
	LPT_IN_RISE = (4<<2),
	LPT_IN_FALL = (5<<2),	
}LPT_CSS_TypeDef;
/**
  * @brief  LPT START SHADOW register
  */
typedef enum
{
    LPT_SHADOW = (0<<6),
	LPT_IMMEDIATE= (1<<6),
}LPT_SHDWSTP_TypeDef;
/**
  * @brief  LPT CLK div register
  */
typedef enum
{
	LPT_PSC_DIV0= 0,
	LPT_PSC_DIV2= 1,
	LPT_PSC_DIV4= 2,
    LPT_PSC_DIV8= 3,
	LPT_PSC_DIV16= 4,
	LPT_PSC_DIV32= 5,
	LPT_PSC_DIV64= 6,
	LPT_PSC_DIV128= 7,
    LPT_PSC_DIV256= 8,
	LPT_PSC_DIV512= 9,
	LPT_PSC_DIV1024= 0X0A,
	LPT_PSC_DIV2048= 0X0B,
	LPT_PSC_DIV4096= 0X0C,	
}LPT_PSCDIV_TypeDef;
/**
  * @brief  LPT START SYN EN register
  */
typedef enum
{
    LPT_SWSYNDIS= (0<<2),
	LPT_SWSYNEN= (1<<2),
}LPT_SWSYN_TypeDef;
/**
  * @brief  LPT IO stop status register
  */
typedef enum
{
    LPT_IDLE_Z= (0<<3),         //High-impedance output
	LPT_IDLE_LOW= (1<<3),	
}LPT_IDLEST_TypeDef;
/**
  * @brief  LPT PRDLD register
  */
typedef enum
{
    LPT_PRDLD_IMMEDIATELY= (0<<4),         
	LPT_PRDLD_DUTY_END= (1<<4),	
}LPT_PRDLD_TypeDef;
/**
  * @brief  LPT POL register
  */
typedef enum
{
    LPT_POL_HIGH= (0<<5),         
	LPT_POL_LOW= (1<<5),	
}LPT_POL_TypeDef;
/**
  * @brief  LPT OPM register
  */
typedef enum
{
    LPT_OPM_CONTINUOUS= (0<<6),         
	LPT_OPM_ONCE= (1<<6),	
}LPT_OPM_TypeDef;
/**
  * @brief  LPT FLTIPSCLD register
  */
typedef enum
{
    LPT_FLTIPSCLD_NULL= (0<<10),         
	LPT_FLTIPSCLD_EN= (1<<10),	
}LPT_FLTIPSCLD_TypeDef;
/**
  * @brief  LPT FLTDEB register
  */
typedef enum
{
    LPT_FLTDEB_00= (0<<13),         
	LPT_FLTDEB_02= (1<<13), 
    LPT_FLTDEB_03= (2<<13),         
	LPT_FLTDEB_04= (3<<13), 
    LPT_FLTDEB_06= (4<<13),         
	LPT_FLTDEB_08= (5<<13), 
    LPT_FLTDEB_16= (6<<13),         
	LPT_FLTDEB_32= (7<<13), 	
}LPT_FLTDEB_TypeDef;
/**
  * @brief  LPT PSCLD register
  */
typedef enum
{
    LPT_PSCLD_0= (0<<16),  		//PSCR        
	LPT_PSCLD_1= (1<<16),	
}LPT_PSCLD_TypeDef;
/**
  * @brief  LPT CMPLD register
  */
typedef enum
{
    LPT_CMPLD_IMMEDIATELY= (0<<17),  	       
	LPT_CMPLD_DUTY_END= (1<<17),	
}LPT_CMPLD_TypeDef;
/**
  * @brief  LPT TRGENX register
  */
typedef enum
{
    LPT_TRGEN_DIS= (0<<0),  	       
	LPT_TRGEN_EN= (1<<0),	
}LPT_TRGENX_TypeDef;
/**
  * @brief  LPT OSTMDX register
  */
typedef enum
{
    LPT_OSTMD_CONTINUOUS= (0<<8),  	       
	LPT_OSTMD_ONCE= (1<<8),	
}LPT_OSTMDX_TypeDef;
/**
  * @brief  LPT AREARM register
  */
typedef enum
{
    LPT_AREARM_DIS= (0<<30),  	       
	LPT_AREARM_EN= (1<<30),	
}LPT_AREARM_TypeDef;
/**
  * @brief  LPT SRCSEL register
  */
typedef enum
{
    LPT_SRCSEL_DIS= (0<<0),  	       
	LPT_SRCSEL_EN= (1<<0),	
}LPT_SRCSEL_TypeDef;
/**
  * @brief  LPT BLKINV register
  */
typedef enum
{
    LPT_BLKINV_DIS= (0<<4),  	       
	LPT_BLKINV_EN= (1<<4),	
}LPT_BLKINV_TypeDef;
/**
  * @brief  LPT CROSSMD register
  */
typedef enum
{
    LPT_CROSSMD_DIS= (0<<7),  	       
	LPT_CROSSMD_EN= (1<<7),	
}LPT_CROSSMD_TypeDef;
/**
  * @brief  LPT TRGSRC0 register
  */
typedef enum
{
    LPT_TRGSRC0_DIS= (0<<0),  	       
	LPT_TRGSRC0_ZRO= (1<<0),
	LPT_TRGSRC0_PRD= (2<<0),
	LPT_TRGSRC0_ZRO_PRD= (3<<0),
	LPT_TRGSRC0_CMP= (4<<0),
}LPT_TRGSRC0_TypeDef;
/**
  * @brief  LPT ESYN0OE register
  */
typedef enum
{
    LPT_ESYN0OE_DIS= (0<<20),  	       
	LPT_ESYN0OE_EN= (1<<20),	
}LPT_ESYN0OE_TypeDef;

/**
  * @brief  LPT INT MASK SET/CLR  Set
  */
typedef enum
{
	LPT_TRGEV0     	=	(0x01 << 0),  
	LPT_MATCH    	=	(0x01 << 1),      
	LPT_PEND    	=	(0x01 << 2), 
}LPT_IMSCR_TypeDef;  

/**
  * @brief  LPT IO  Set
  */
typedef enum
{
	LPT_OUT_PA09    =	0,  
	LPT_OUT_PB01   	=	1,      
	LPT_IN_PA10    =	2, 
}LPT_IOSET_TypeDef; 


#define LPT_DEBUG_MODE (0X01<<1)


extern void LPT_DeInit(void);
extern void LPT_IO_Init(LPT_IOSET_TypeDef IONAME);
extern void LPT_Configure(LPT_CLK_TypeDef CLKX,LPT_CSS_TypeDef CSSX,LPT_SHDWSTP_TypeDef SHDWSTPX,
						LPT_PSCDIV_TypeDef PSCDIVX,U8_T FLTCKPRSX,LPT_OPM_TypeDef OPMX);
extern void LPT_Debug_Mode(FunctionalStatus NewState);
extern void LPT_Period_CMP_Write(U16_T PRDR_DATA,U16_T CMP_DATA);
extern void LPT_CNT_Write(U16_T CNT_DATA);
extern U16_T LPT_PRDR_Read(void);
extern U16_T LPT_CMP_Read(void);
extern U16_T LPT_CNT_Read(void);
extern void LPT_ControlSet_Configure(LPT_SWSYN_TypeDef SWSYNX,LPT_IDLEST_TypeDef IDLESTX,LPT_PRDLD_TypeDef PRDLDX,LPT_POL_TypeDef POLX,
							 LPT_FLTDEB_TypeDef FLTDEBX,LPT_PSCLD_TypeDef PSCLDX,LPT_CMPLD_TypeDef CMPLDX);
extern void LPT_SyncSet_Configure(LPT_TRGENX_TypeDef TRGENX,LPT_OSTMDX_TypeDef OSTMDX,LPT_AREARM_TypeDef AREARMX);
extern void LPT_Trigger_Configure(LPT_SRCSEL_TypeDef SRCSELX,LPT_BLKINV_TypeDef BLKINVX,LPT_CROSSMD_TypeDef CROSSMDX,LPT_TRGSRC0_TypeDef TRGSRC0X,
						LPT_ESYN0OE_TypeDef ESYN0OEX,U16_T OFFSET_DATA,U16_T WINDOW_DATA,U8_T TRGEC0PRD_DATA);
extern void LPT_Trigger_Cnt(U8_T TRGEV0CNT_DATA);
extern void LPT_Trigger_EVPS(U8_T TRGEC0PRD_DATA,U8_T TRGEV0CNT_DATA);
extern void LPT_Soft_Trigger(void);
extern void LPT_Start(void);
extern void LPT_Stop(void);
extern void LPT_Soft_Reset(void);
extern void LPT_REARM_Write(void);
extern U8_T LPT_REARM_Read(void);
extern void LPT_ConfigInterrupt_CMD(FunctionalStatus NewState,LPT_IMSCR_TypeDef LPT_IMSCR_X);
extern void LPT_INT_ENABLE(void);
extern void LPT_INT_DISABLE(void);



/*************************************************************/

#endif   /**< apt32f102_lpt_H */

/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/