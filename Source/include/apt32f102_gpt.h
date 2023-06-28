/*
  ******************************************************************************
  * @file    apt32f102_gpt.h
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
#ifndef _apt32f102_gpt_H
#define _apt32f102_gpt_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


#define GPT_RESET_VALUE  (0x00000000)
//--------------------------------------------------------------------------------
//-----------------------------GPT  value enum define--------------------------
//--------------------------------------------------------------------------------
/**
  * @brief  GPT CLK EN register
  */
typedef enum
{
    GPTCLK_DIS = 0,
	GPTCLK_EN = 1,
}GPT_CLK_TypeDef;
/**
  * @brief  GPT CLK SOURCE register
  */
typedef enum
{
    GPT_PCLK = (0<<2),
	GPT_TRGUSR3 = (1<<2),
}GPT_CSS_TypeDef;
/**
  * @brief  GPT START SHADOW register
  */
typedef enum
{
    GPT_SHADOW = (0<<6),
	GPT_IMMEDIATE= (1<<6),
}GPT_SHDWSTP_TypeDef;
/**
  * @brief  GPT COUNT EDGE register
  */
typedef enum
{
    DIR_INCREASE = (0<<3),
	DIR_DECREASE= (1<<3),
}GPT_CNTDIR_TypeDef;
/**
  * @brief  GPT COUNT EDGE register
  */
typedef enum
{
    GPT_INCREASE = (0<<0),
	GPT_DECREASE= (1<<0),
	GPT_IN_DECREASE= (2<<0),
}GPT_CNTMD_TypeDef;
/**
  * @brief  GPT START SYN EN register
  */
typedef enum
{
    GPT_SWSYNDIS= (0<<2),
	GPT_SWSYNEN= (1<<2),
}GPT_SWSYN_TypeDef;
/**
  * @brief  GPT ILDE IO Status register
  */
typedef enum
{
    GPT_IDLE_Z= (0<<3),
	GPT_IDLE_LOW= (1<<3),
}GPT_IDLEST_TypeDef;
/**
  * @brief  GPT PRDLD register
  */
typedef enum
{
	GPT_PRDLD_PEND= (0<<4),	
	GPT_PRDLD_LOAD_SYNC= (1<<4),	
	GPT_PRDLD_ZERO_LOAD_SYNC= (2<<4),	
	GPT_PRDLD_IMMEDIATELY= (3<<4),         
}GPT_PRDLD0_TypeDef;
/**
  * @brief  GPT CAPLDEN register
  */
typedef enum
{
    GPT_CAP_DIS= (0<<8),
	GPT_CAP_EN= (1<<8),
}GPT_CAPLDEN_TypeDef;
/**
  * @brief  GPT BURST register
  */
typedef enum
{
    GPT_BURST_DIS= (0<<9),
	GPT_BURST_EN= (1<<9),
}GPT_BURST_TypeDef;
/**
  * @brief  GPT BURST register
  */
typedef enum
{
    GPT_CG_CHAX= (0<<11),
	GPT_CG_CHBX= (1<<11),
}GPT_CGSRC_TypeDef;
/**
  * @brief  GPT CGFLT register
  */
typedef enum
{
    GPT_CGFLT_00= (0<<13),
	GPT_CGFLT_02= (1<<13),
	GPT_CGFLT_03= (2<<13),
	GPT_CGFLT_04= (3<<13),
	GPT_CGFLT_06= (4<<13),
	GPT_CGFLT_08= (5<<13),
	GPT_CGFLT_16= (6<<13),
	GPT_CGFLT_32= (7<<13),
}GPT_CGFLT_TypeDef;
/**
  * @brief  GPT PSCLD register
  */
typedef enum
{
	GPT_PRDLD_ZERO= (0<<16),	
	GPT_PRDLD_PRD= (1<<16),	
	GPT_PRDLD_ZERO_PRD= (2<<16),	
	GPT_PRDLD_NONE= (3<<16),         
}GPT_PSCLD_TypeDef;
/**
  * @brief  GPT CAPMD register
  */
typedef enum
{
	GPT_CAPMD_CONTINUOUS= (0<<20),	
	GPT_CAPMD_ONCE= (1<<20),	        
}GPT_CAPMD_TypeDef;
/**
  * @brief  GPT LDARST register
  */
typedef enum
{
	GPT_LDARST_EN= (0<<23),	
	GPT_LDARST_DIS= (1<<23),	        
}GPT_LDARST_TypeDef;
/**
  * @brief  GPT LDBRST register
  */
typedef enum
{
	GPT_LDBRST_EN= (0<<23),	
	GPT_LDBRST_DIS= (1<<23),	        
}GPT_LDBRST_TypeDef;
/**
  * @brief  GPT OPM register
  */
typedef enum
{
	GPT_OPM_CONTINUOUS= (0<<6),	
	GPT_OPM_ONCE= (1<<6),	        
}GPT_OPM_TypeDef;
/**
  * @brief  GPT CKS register
  */
typedef enum
{
	GPT_CKS_PCLK= (0<<10),	
	GPT_CKS_PCLKDIV2= (1<<10),	        
}GPT_CKS_TypeDef;
/**
  * @brief  GPT WAVE register
  */
typedef enum
{
	GPT_CAPTURE_MODE= (0<<18),	
	GPT_WAVE_MODE= (1<<18),	        
}GPT_WAVE_TypeDef;
/**
  * @brief  GPT OSTMDX register
  */
typedef enum
{
	GPT_OST_CONTINUOUS= (0<<8),	
	GPT_OST_ONCE= (1<<8),	        
}GPT_OSTMDX_TypeDef;
/**
  * @brief  GPT TXREARM0 register
  */
typedef enum
{
	GPT_REARM_DIS= (0<<22),	
	GPT_REARM_T1= (1<<22),	
	GPT_REARM_T2= (2<<22),   
	GPT_REARM_T1_T2= (3<<22),  
}GPT_TXREARM0_TypeDef;

/**
  * @brief  GPT TRGO0SEL register
  */
typedef enum
{
	GPT_TRGO0SEL_SR0= (0<<24),	
	GPT_TRGO0SEL_SR1= (1<<24),	
	GPT_TRGO0SEL_SR2= (2<<24),   
	GPT_TRGO0SEL_SR3= (3<<24), 
	GPT_TRGO0SEL_SR4= (4<<24),   
	GPT_TRGO0SEL_SR5= (5<<24), 
}GPT_TRGO0SEL_TypeDef;

/**
  * @brief  GPT TRGO0SEL register
  */
typedef enum
{
	GPT_TRG10SEL_SR0= (0<<24),	
	GPT_TRG10SEL_SR1= (1<<24),	
	GPT_TRG10SEL_SR2= (2<<24),   
	GPT_TRG10SEL_SR3= (3<<24), 
	GPT_TRG10SEL_SR4= (4<<24),   
	GPT_TRG10SEL_SR5= (5<<24), 
}GPT_TRGO1SEL_TypeDef;
/**
  * @brief  GPT AREARM register
  */
typedef enum
{
	GPT_AREARM_DIS= (0<<30),	
	GPT_AREARM_ZERO= (1<<30),		
	GPT_AREARM_PRD= (2<<30),	   
	GPT_AREARM_ZERO_PRD= (3<<30),	
}GPT_AREARM_TypeDef;
/**
  * @brief  BT INT MASK SET/CLR  Set
  */
typedef enum
{
	GPT_TRGEV0    	=	(0x01 << 0), 
	GPT_TRGEV1    	=	(0x01 << 1),     
	GPT_TRGEV2     	=	(0x01 << 2),  
	GPT_TRGEV3     =	(0x01 << 3), 
}GPT_IMSCR_TypeDef;  
/**
  * @brief  GPT IO  Set
  */
typedef enum
{
	GPT_CHA_PB01    =	0,  
	GPT_CHA_PA09   	=	1,      
	GPT_CHA_PA010    =	2, 
	GPT_CHB_PA010    =	3,  
	GPT_CHB_PA011   	=	4,      
	GPT_CHB_PB00    =	5,
	GPT_CHB_PB01    =	5,
}GPT_IOSET_TypeDef; 
/**
  * @brief  CMPA SHADOW/IMMEDIATE
  */
typedef enum
{
	GPT_CMPA_SHADOW    	=	(0x00 << 0), 
	GPT_CMPA_IMMEDIATE    =	(0x01 << 0),     
}GPT_SHDWCMPA_TypeDef;  
/**
  * @brief  CMPB SHADOW/IMMEDIATE
  */
typedef enum
{
	GPT_CMPB_SHADOW    	=	(0x00 << 1), 
	GPT_CMPB_IMMEDIATE    =	(0x01 << 1),     
}GPT_SHDWCMPB_TypeDef; 
/**
  * @brief  CMPA LOAD MODE
  */
typedef enum
{
	GPT_LoadA_ZERO   	=	(0x01 << 4), 
	GPT_LoadA_PRD    	=	(0x02 << 4),    
	GPT_LoadA_EXT_SYNC  =	(0x04 << 4),  
	GPT_LoadA_NONE		=	(0x00 << 4),
}GPT_LDAMD_TypeDef;  
/**
  * @brief  CMPB LOAD MODE
  */
typedef enum
{
	GPT_LoadB_ZERO   	=	(0x01 << 4), 
	GPT_LoadB_PRD    	=	(0x02 << 4),    
	GPT_LoadB_EXT_SYNC  =	(0x04 << 4),  
	GPT_LoadB_NONE		=	(0x00 << 4),
}GPT_LDBMD_TypeDef;  

/**
  * @brief  WAVEA SHADOW/IMMEDIATE
  */
typedef enum
{
	GPT_WAVEA_SHADOW    	=	(0x00 << 0), 
	GPT_WAVEA_IMMEDIATE    =	(0x01 << 0),     
}GPT_SHDWAQA_TypeDef;  
/**
  * @brief  WAVEB SHADOW/IMMEDIATE
  */
typedef enum
{
	GPT_WAVEB_SHADOW    	=	(0x00 << 1), 
	GPT_WAVEB_IMMEDIATE    =	(0x01 << 1),     
}GPT_SHDWAQB_TypeDef; 
/**
  * @brief  ACTIVE A LOAD MODE
  */
typedef enum
{
	GPT_AQLDA_ZERO   	=	(0x01 << 2), 
	GPT_AQLDA_PRD    	=	(0x02 << 2),    
	GPT_AQLDA_EXT_SYNC  =	(0x04 << 2),  
	GPT_AQLDA_NONE		=	(0x00 << 2),
}GPT_AQLDA_TypeDef;  
/**
  * @brief  ACTIVE B LOAD MODE
  */
typedef enum
{
	GPT_AQLDB_ZERO   	=	(0x01 << 5), 
	GPT_AQLDB_PRD    	=	(0x02 << 5),    
	GPT_AQLDB_EXT_SYNC  =	(0x04 << 5),  
	GPT_AQLDB_NONE		=	(0x00 << 5),
}GPT_AQLDB_TypeDef; 
/**
  * @brief CASEL MODE
  */
typedef enum
{
	GPT_CASEL_CMPA   	=	(0x00 << 20), 
	GPT_CASEL_CMPB  	=	(0x01 << 20), 
}GPT_CASEL_TypeDef; 
/**
  * @brief CBSEL MODE
  */
typedef enum
{
	GPT_CBSEL_CMPA    	=	(0x00 << 22), 
	GPT_CBSEL_CMPB     	=	(0x01 << 22), 
}GPT_CBSEL_TypeDef; 
/**
  * @brief CBSEL MODE
  */
typedef enum
{
	GPT_CHA    	=	0, 
	GPT_CHB     =	1, 
}GPT_GPTCHX_TypeDef; 
/**
  * @brief A FORCE ENABLE
  */
typedef enum
{
	GPT_CHA_FORCE_DIS    =	0, 
	GPT_CHA_FORCE_EN     =	1, 
}GPT_CHAFORCE_TypeDef; 
/**
  * @brief B FORCE ENABLE
  */
typedef enum
{
	GPT_CHB_FORCE_DIS    =	0<<4, 
	GPT_CHB_FORCE_EN     =	1<<4, 
}GPT_CHBFORCE_TypeDef; 
/**
  * @brief FORCE LOAD
  */
typedef enum
{
	GPT_FORCELD_ZERO    =	(0<<16), 
	GPT_FORCELD_PRD    =	(1<<16), 
	GPT_FORCELD__ZERO_PRD    =	(3<<16), 
}GPT_FORCELD_TypeDef; 
/**
  * @brief FORCE A
  */
typedef enum
{
	GPT_FORCECHA_LOW    =	(1<<0), 
	GPT_FORCECHA_HIGH    =	(2<<0), 
}GPT_FORCEA_TypeDef;
/**
  * @brief FORCE B
  */
typedef enum
{
	GPT_FORCECHB_LOW    =	(1<<2), 
	GPT_FORCECHB_HIGH    =	(2<<2), 
}GPT_FORCEB_TypeDef;

#define CH_ZRO_NONE	(0X00)
#define CH_ZRO_LOW	(0X01)
#define CH_ZRO_HIGH	(0X02)
#define CH_ZRO_REVS	(0X03)
#define CH_PRD_NONE	(0X00)
#define CH_PRD_LOW	(0X01)
#define CH_PRD_HIGH	(0X02)
#define CH_PRD_REVS	(0X03)
#define CH_CAU_NONE	(0X00)
#define CH_CAU_LOW	(0X01)
#define CH_CAU_HIGH	(0X02)
#define CH_CAU_REVS	(0X03)
#define CH_CAD_NONE	(0X00)
#define CH_CAD_LOW	(0X01)
#define CH_CAD_HIGH	(0X02)
#define CH_CAD_REVS	(0X03)
#define CH_CBU_NONE	(0X00)
#define CH_CBU_LOW	(0X01)
#define CH_CBU_HIGH	(0X02)
#define CH_CBU_REVS	(0X03)
#define CH_CBD_NONE	(0X00)
#define CH_CBD_LOW	(0X01)
#define CH_CBD_HIGH	(0X02)
#define CH_CBD_REVS	(0X03)
#define CH_T1U_NONE	(0X00)
#define CH_T1U_LOW	(0X01)
#define CH_T1U_HIGH	(0X02)
#define CH_T1U_REVS	(0X03)
#define CH_T1D_NONE	(0X00)
#define CH_T1D_LOW	(0X01)
#define CH_T1D_HIGH	(0X02)
#define CH_T1D_REVS	(0X03)
#define CH_T2U_NONE	(0X00)
#define CH_T2U_LOW	(0X01)
#define CH_T2U_HIGH	(0X02)
#define CH_T2U_REVS	(0X03)
#define CH_T2D_NONE	(0X00)
#define CH_T2D_LOW	(0X01)
#define CH_T2D_HIGH	(0X02)
#define CH_T2D_REVS	(0X03)


#define FORCE_ACT_NONE 0
#define FORCE_ACT_LOW 1
#define FORCE_ACT_HIGH 2
#define FORCE_ACT_REVS 3


#define GPT_INT_TRGEV0 	(0X01)
#define GPT_INT_TRGEV1 	(0X01<<1)
#define GPT_INT_TRGEV2 	(0X01<<2)
#define GPT_INT_TRGEV3 	(0X01<<3)
#define GPT_INT_CAPLD0 	(0X01<<4)
#define GPT_INT_CAPLD1 	(0X01<<5)
#define GPT_INT_CAPLD2 	(0X01<<6)
#define GPT_INT_CAPLD3 	(0X01<<7)
#define GPT_INT_CAU 	(0X01<<8)
#define GPT_INT_CAD 	(0X01<<9)
#define GPT_INT_CBU 	(0X01<<10)
#define GPT_INT_CBD 	(0X01<<11)
#define GPT_INT_PEND 	(0X01<<16)



#define GPT_SYNCUSR0 (0X01)
#define GPT_SYNCUSR1 (0X01<<1)
#define GPT_SYNCUSR2 (0X01<<2)
#define GPT_SYNCUSR3 (0X01<<3)
#define GPT_SYNCUSR4 (0X01<<4)
#define GPT_SYNCUSR5 (0X01<<5)
#define GPT_DEBUG_MODE (0x01<<1)



extern void GPT_DeInit(void);
extern void GPT_IO_Init(GPT_IOSET_TypeDef IONAME);
extern void GPT_Configure(GPT_CLK_TypeDef GPTCLKX,GPT_CSS_TypeDef GCSSX,GPT_SHDWSTP_TypeDef GSHDWSTPX,U16_T GPSCX);
extern void GPT_WaveCtrl_Configure(GPT_CNTMD_TypeDef GCNTMDX,GPT_SWSYN_TypeDef GSWSYNX,GPT_IDLEST_TypeDef GIDLEX,GPT_PRDLD0_TypeDef GPRDLD0,GPT_OPM_TypeDef GOPMX,
						GPT_BURST_TypeDef GBURSTX,GPT_CKS_TypeDef GCKS,GPT_CGSRC_TypeDef CGSRCX,GPT_CGFLT_TypeDef CGFLT,GPT_PSCLD_TypeDef PSCLDX);
extern void GPT_WaveLoad_Configure(GPT_SHDWAQA_TypeDef SHDWAQAX,GPT_SHDWAQB_TypeDef SHDWAQBX,GPT_AQLDA_TypeDef AQLDAX, GPT_AQLDB_TypeDef AQLDBX);
extern void GPT_WaveOut_Configure(GPT_GPTCHX_TypeDef GPTCHX,GPT_CASEL_TypeDef CASELX,GPT_CBSEL_TypeDef CBSELX,U8_T ZROX,U8_T PRDX,U8_T CAUX,
						U8_T CADX,U8_T CBUX,U8_T CBDX,U8_T T1UX,U8_T T1DX,U8_T T2UX,U8_T T2DX);
extern void GPT_OneceForce_Out(GPT_CHAFORCE_TypeDef CHAFORCEX,U8_T AFORCE_STATUS,GPT_CHBFORCE_TypeDef CHBFORCEX,U8_T BFORCE_STATUS,GPT_FORCELD_TypeDef FORCELDX);
extern void GPT_Force_Out(GPT_FORCEA_TypeDef FORCEAX,GPT_FORCEB_TypeDef FORCEBX);
extern void GPT_CmpLoad_Configure(GPT_SHDWCMPA_TypeDef SHDWCMPAX,GPT_SHDWCMPB_TypeDef SHDWCMPBX,GPT_LDAMD_TypeDef LDAMDX,GPT_LDBMD_TypeDef LDBMDX);
extern void GPT_Debug_Mode(FunctionalStatus NewState);
extern void GPT_Start(void);
extern void GPT_Stop(void);
extern void GPT_Soft_Reset(void);
extern void GPT_Cap_Rearm(void);
extern void GPT_REARM_Write(void);
extern U8_T GPT_REARM_Read(void);
extern void GPT_Period_CMP_Write(U16_T PRDR_DATA,U16_T CMPA_DATA,U16_T CMPB_DATA);
extern U16_T GPT_PRDR_Read(void);
extern U16_T GPT_CMPA_Read(void);
extern U16_T GPT_CMPB_Read(void);
extern U16_T GPT_CNT_Read(void);
extern void GPT_ConfigInterrupt_CMD(FunctionalStatus NewState,U32_T GPT_IMSCR_X);
extern void GPT_INT_ENABLE(void);
extern void GPT_INT_DISABLE(void);
/*************************************************************/

#endif   /**< apt32f102_gpt_H */

/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/