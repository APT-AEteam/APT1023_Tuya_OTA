/*
  ******************************************************************************
  * @file    apt32f102_ept.h
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
#ifndef _apt32f102_ept_H
#define _apt32f102_ept_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"
/******************************************************************************
************************* ept Registers Definition *************************
******************************************************************************/
/**
  * @brief  EPT io Mode set
  */
typedef enum
{
	EPT_IO_CHAX			=	 	0,
	EPT_IO_CHAY			=	 	1,
	EPT_IO_CHBX			=	 	2,
	EPT_IO_CHBY			=	 	3,	
	EPT_IO_CHCX			=	 	4,
	EPT_IO_CHCY			=	 	5,
	EPT_IO_CHD			=	 	6,
	EPT_IO_EPI			=	 	7
}EPT_IO_Mode_Type;
/**
  * @brief  EPT io NUM set
  */
typedef enum
{
	IO_NUM_PA07			=		0X10,
	IO_NUM_PA10			=		0X11,
	IO_NUM_PA15			=		0X12,
	IO_NUM_PB03			=		0X13,
	IO_NUM_PB05			=		0X14,
	IO_NUM_PA12			=		0X15,
	IO_NUM_PB02			=		0X16,
	IO_NUM_PA11			=		0X17,
	IO_NUM_PA14			=		0X18,
	IO_NUM_PB04			=		0X19,
	IO_NUM_PA05			=		0X1A,
	IO_NUM_PA08			=		0X1B,
	IO_NUM_PA03			=		0X1C,
	IO_NUM_PB00			=		0X1D,
	IO_NUM_PA04			=		0X1E,
	IO_NUM_PA09			=		0X1F,
	IO_NUM_PA013		=		0X20
}EPT_IO_NUM_Type;	
/**
  * @brief  EPT TCLK selected
  */
typedef enum
{
	EPT_Selecte_PCLK		=	0<<3,
	EPT_Selecte_SYNCUSR3	=	1<<3
}EPT_TCLK_Selecte_Type;
/**
  * @brief  EPT TIN selected
  */
typedef enum
{
	TIN_DIS				=	0<<4,
	TIN_BT0OUT			=	1<<4,
	TIN_BT1OUT			=	2<<4
}EPT_TIN_Selecte_Type;
/**
  * @brief  EPT CNTMD selected
  */
typedef enum		
{
	EPT_CNTMD_increase 				=  ((CSP_REGISTER_T)(0x00ul << 0)),
	EPT_CNTMD_decrease  			=  ((CSP_REGISTER_T)(0x01ul << 0)),
	EPT_CNTMD_increaseTOdecrease	=  ((CSP_REGISTER_T)(0x02ul << 0))
}EPT_CNTMD_SELECTE_Type;	
/**
  * @brief  EPT OPM selected
  */
typedef enum		
{
	EPT_OPM_Once 				=  ((CSP_REGISTER_T)(0x01ul << 6)),
	EPT_OPM_Continue  			=  ((CSP_REGISTER_T)(0x00ul << 6))
}EPT_OPM_SELECTE_Type;	
/**
  * @brief  EPT CAP CMD
  */
typedef enum		
{	
	EPT_CAP_EN			=			((CSP_REGISTER_T)(0x01ul << 8)),	
	EPT_CAP_DIS			=			((CSP_REGISTER_T)(0x00ul << 8))
}EPT_CAPLDEN_CMD_Type;
	
/**
  * @brief  EPT CAPMD selected
  */
typedef enum		
{
	EPT_CAPMD_Once 					=  ((CSP_REGISTER_T)(0x01ul << 20)),
	EPT_CAPMD_Continue  			=  ((CSP_REGISTER_T)(0x00ul << 20))
}EPT_CAPMD_SELECTE_Type;

/**
  * @brief  EPT CMPA RST CMD
  */
typedef enum		
{
	EPT_LDARST_EN 					=  ((CSP_REGISTER_T)(0x00ul << 23)),
	EPT_LDARST_DIS  				=  ((CSP_REGISTER_T)(0x01ul << 23))
}EPT_LOAD_CMPA_RST_CMD_Type;	
/**
  * @brief  EPT CMPB RST CMD
  */
typedef enum		
{
	EPT_LDBRST_EN 					=  ((CSP_REGISTER_T)(0x00ul << 24)),
	EPT_LDBRST_DIS  				=  ((CSP_REGISTER_T)(0x01ul << 24))
}EPT_LOAD_CMPB_RST_CMD_Type;		
/**
  * @brief  EPT CMPC RST CMD
  */
typedef enum		
{
	EPT_LDCRST_EN 					=  ((CSP_REGISTER_T)(0x00ul << 25)),
	EPT_LDCRST_DIS  				=  ((CSP_REGISTER_T)(0x01ul << 25))
}EPT_LOAD_CMPC_RST_CMD_Type;	
/**
  * @brief  EPT CMPD RST CMD
  */
typedef enum		
{
	EPT_LDDRST_EN 					=  ((CSP_REGISTER_T)(0x00ul << 26)),
	EPT_LDDRST_DIS  				=  ((CSP_REGISTER_T)(0x01ul << 26))
}EPT_LOAD_CMPD_RST_CMD_Type;	
/**
  * @brief  EPT FLT CMD
  */
typedef enum		
{
	EPT_FLT_DIS 					=  ((CSP_REGISTER_T)(0x00ul << 10)),
	EPT_FLT_EN  					=  ((CSP_REGISTER_T)(0x01ul << 10))
}EPT_FLT_CMD_Type;		
/**
  * @brief  EPT FLT CGFLT
  */
typedef enum		
{
	EPT_FLT_Bypass 					=  ((CSP_REGISTER_T)(0x00ul << 13)),
	EPT_FLT_2  						=  ((CSP_REGISTER_T)(0x01ul << 13)),
	EPT_FLT_3  						=  ((CSP_REGISTER_T)(0x02ul << 13)),
	EPT_FLT_4  						=  ((CSP_REGISTER_T)(0x03ul << 13)),
	EPT_FLT_6  						=  ((CSP_REGISTER_T)(0x04ul << 13)),
	EPT_FLT_8  						=  ((CSP_REGISTER_T)(0x05ul << 13)),
	EPT_FLT_16  					=  ((CSP_REGISTER_T)(0x06ul << 13)),
	EPT_FLT_32  					=  ((CSP_REGISTER_T)(0x07ul << 13))
}EPT_FLT_CGFLT_Type;
/**
  * @brief  EPT Triggle Mode 
  */
typedef enum		
{
	EPT_Triggle_Continue 					=  ((CSP_REGISTER_T)(0x00ul << 8)),
	EPT_Triggle_Once  						=  ((CSP_REGISTER_T)(0x01ul << 8))
}EPT_Triggle_Mode_Type;
/**
  * @brief  EPT Rearm select
  */
typedef enum		
{
	EPT_REARM_SYNCEN0 					=  ((CSP_REGISTER_T)(0x01ul << 16)),
	EPT_REARM_SYNCEN1 					=  ((CSP_REGISTER_T)(0x02ul << 16)),
	EPT_REARM_SYNCEN2 					=  ((CSP_REGISTER_T)(0x04ul << 16)),
	EPT_REARM_SYNCEN3 					=  ((CSP_REGISTER_T)(0x08ul << 16)),
	EPT_REARM_SYNCEN4 					=  ((CSP_REGISTER_T)(0x10ul << 16)),
	EPT_REARM_SYNCEN5 					=  ((CSP_REGISTER_T)(0x20ul << 16))
}EPT_REARMX_Type;
/**
  * @brief  EPT Rearm select
  */
typedef enum		
{
	EPT_REARM_Selected_DIS				=	((CSP_REGISTER_T)(0x00ul << 30)),
	EPT_REARM_Selected_ZRO_AUTO			=	((CSP_REGISTER_T)(0x01ul << 30)),
	EPT_REARM_Selected_PRD_AUTO			=	((CSP_REGISTER_T)(0x02ul << 30)),
	EPT_REARM_Selected_ZRO_PRD_AUTO		=	((CSP_REGISTER_T)(0x03ul << 30))
}EPT_REARM_MODE_Type;
/**
  * @brief  EPT Syncusr0 Trig select 
  */
typedef enum		
{
	EPT_SYNCUSR0_REARMTrig_DIS			=	((CSP_REGISTER_T)(0x00ul << 22)),
	EPT_SYNCUSR0_REARMTrig_T1			=	((CSP_REGISTER_T)(0x01ul << 22)),
	EPT_SYNCUSR0_REARMTrig_T2			=	((CSP_REGISTER_T)(0x02ul << 22)),
	EPT_SYNCUSR0_REARMTrig_T1T2			=	((CSP_REGISTER_T)(0x03ul << 22))
}EPT_SYNCUSR0_REARMTrig_Selecte_Type;
/**
  * @brief  EPT TRGSRC0 ExtSync Selected
  */
typedef enum		
{
	EPT_TRGSRC0_ExtSync_SYNCUSR0			=	((CSP_REGISTER_T)(0x00ul << 24)),
	EPT_TRGSRC0_ExtSync_SYNCUSR1			=	((CSP_REGISTER_T)(0x01ul << 24)),
	EPT_TRGSRC0_ExtSync_SYNCUSR2			=	((CSP_REGISTER_T)(0x02ul << 24)),
	EPT_TRGSRC0_ExtSync_SYNCUSR3			=	((CSP_REGISTER_T)(0x03ul << 24)),
	EPT_TRGSRC0_ExtSync_SYNCUSR4			=	((CSP_REGISTER_T)(0x04ul << 24)),
	EPT_TRGSRC0_ExtSync_SYNCUSR5			=	((CSP_REGISTER_T)(0x05ul << 24))
}EPT_TRGSRC0_ExtSync_Selected_Type;
/**
  * @brief  EPT TRGSRC1 ExtSync Selected
  */
typedef enum		
{
	EPT_TRGSRC1_ExtSync_SYNCUSR0			=	((CSP_REGISTER_T)(0x00ul << 27)),
	EPT_TRGSRC1_ExtSync_SYNCUSR1			=	((CSP_REGISTER_T)(0x01ul << 27)),
	EPT_TRGSRC1_ExtSync_SYNCUSR2			=	((CSP_REGISTER_T)(0x02ul << 27)),
	EPT_TRGSRC1_ExtSync_SYNCUSR3			=	((CSP_REGISTER_T)(0x03ul << 27)),
	EPT_TRGSRC1_ExtSync_SYNCUSR4			=	((CSP_REGISTER_T)(0x04ul << 27)),
	EPT_TRGSRC1_ExtSync_SYNCUSR5			=	((CSP_REGISTER_T)(0x05ul << 27))
}EPT_TRGSRC1_ExtSync_Selected_Type;
/**
  * @brief  EPT PHSEN CMD
  */
typedef enum		
{
	EPT_PHSEN_DIS			=	((CSP_REGISTER_T)(0x00ul << 8)),
	EPT_PHSEN_EN			=	((CSP_REGISTER_T)(0x01ul << 8))
}EPT_PHSEN_CMD_Type;
/**
  * @brief  EPT PHSDIR selecte
  */
typedef enum		
{
	EPT_PHSDIR_increase			=	((CSP_REGISTER_T)(0x01ul << 31)),
	EPT_PHSEN_decrease			=	((CSP_REGISTER_T)(0x00ul << 31))
}EPT_PHSDIR_Type;
/**
  * @brief  EPT GLDCR Config
  */
typedef enum		
{
	EPT_GLDMD_Selecte_ZRO						=	((CSP_REGISTER_T)(0x00ul << 1)),
	EPT_GLDMD_Selecte_PRD						=	((CSP_REGISTER_T)(0x01ul << 1)),
	EPT_GLDMD_Selecte_ZRO_PRD					=	((CSP_REGISTER_T)(0x02ul << 1)),
	EPT_GLDMD_Selecte_ZRO_ExiLoad_SYNC			=	((CSP_REGISTER_T)(0x03ul << 1)),
	EPT_GLDMD_Selecte_PRD_ExiLoad_SYNC			=	((CSP_REGISTER_T)(0x04ul << 1)),
	EPT_GLDMD_Selecte_ZRO_PRD_ExiLoad_SYNC		=	((CSP_REGISTER_T)(0x05ul << 1)),
	EPT_GLDMD_Selecte_SW						=	((CSP_REGISTER_T)(0x0Ful << 1))
}EPT_GLDMD_Selecte_Type;
/**
  * @brief  EPT PRDR Event Load
  */
typedef enum		
{
	EPT_PRDR_EventLoad_PEND						=	((CSP_REGISTER_T)(0x00ul << 4)),
	EPT_PRDR_EventLoad_ExiLoad_SYNC				=	((CSP_REGISTER_T)(0x01ul << 4)),
	EPT_PRDR_EventLoad_Zro_ExiLoad_SYNC			=	((CSP_REGISTER_T)(0x02ul << 4)),
	EPT_PRDR_EventLoad_Immediate				=	((CSP_REGISTER_T)(0x03ul << 4))
} EPT_PRDR_EventLoad_Type;

/**
  * @brief  EPT CMPX Event load 
  */
typedef enum		
{
	EPT_CMPX_EventLoad_DIS							=		0,
	EPT_CMPX_EventLoad_Immediate					=		1,
	EPT_CMPX_EventLoad_ZRO							=		2,
	EPT_CMPX_EventLoad_PRD							=		3,
	EPT_CMPX_EventLoad_ExiLoad_SYNC					=		4
}EPT_CMPX_EventLoad_Type;
/**
  * @brief  EPT AQCRX Event load 
  */
typedef enum		
{
	EPT_AQCRX_EventLoad_DIS							=		0,
	EPT_AQCRX_EventLoad_Immediate					=		1,
	EPT_AQCRX_EventLoad_ZRO							=		2,
	EPT_AQCRX_EventLoad_PRD							=		3,
	EPT_AQCRX_EventLoad_ExiLoad_SYNC				=		4
}EPT_AQCRX_EventLoad_Type;
/**
  * @brief  EPT PWMX Selecte 
  */
typedef enum		
{
	EPT_PWMA				=			0,
	EPT_PWMB				=			1,
	EPT_PWMC				=			2,
	EPT_PWMD				=			3
}EPT_PWMX_Selecte_Type;
/**
  * @brief  EPT CA Selecte
  */
typedef enum		
{
	EPT_CA_Selecte_CMPA				=			((CSP_REGISTER_T)(0x00ul << 20)),
	EPT_CA_Selecte_CMPB				=			((CSP_REGISTER_T)(0x01ul << 20)),
	EPT_CA_Selecte_CMPC				=			((CSP_REGISTER_T)(0x02ul << 20)),
	EPT_CA_Selecte_CMPD				=			((CSP_REGISTER_T)(0x03ul << 20))
}EPT_CA_Selecte_Type;
/**
  * @brief  EPT CB Selecte
  */
typedef enum		
{
	EPT_CB_Selecte_CMPA				=			((CSP_REGISTER_T)(0x00ul << 22)),
	EPT_CB_Selecte_CMPB				=			((CSP_REGISTER_T)(0x01ul << 22)),
	EPT_CB_Selecte_CMPC				=			((CSP_REGISTER_T)(0x02ul << 22)),
	EPT_CB_Selecte_CMPD				=			((CSP_REGISTER_T)(0x03ul << 22))
}EPT_CB_Selecte_Type;
/**
  * @brief  EPT PWM ZRO Output
  */
typedef enum		
{
	EPT_PWM_ZRO_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul )),
	EPT_PWM_ZRO_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul )),
	EPT_PWM_ZRO_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul )),
	EPT_PWM_ZRO_Event_Negate				=	((CSP_REGISTER_T)(0x03ul ))
}EPT_PWM_ZRO_Output_Type;
/**
  * @brief  EPT PWM PRD Output
  */
typedef enum		
{
	EPT_PWM_PRD_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<2 )),
	EPT_PWM_PRD_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<2 )),
	EPT_PWM_PRD_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<2 )),
	EPT_PWM_PRD_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<2 ))
}EPT_PWM_PRD_Output_Type;
/**
  * @brief  EPT PWM CAU Output
  */
typedef enum		
{
	EPT_PWM_CAU_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<4 )),
	EPT_PWM_CAU_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<4 )),
	EPT_PWM_CAU_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<4 )),
	EPT_PWM_CAU_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<4 ))
}EPT_PWM_CAU_Output_Type;
/**
  * @brief  EPT PWM CAD Output
  */
typedef enum		
{
	EPT_PWM_CAD_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<6 )),
	EPT_PWM_CAD_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<6 )),
	EPT_PWM_CAD_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<6 )),
	EPT_PWM_CAD_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<6 ))
}EPT_PWM_CAD_Output_Type;
/**
  * @brief  EPT PWM CBU Output
  */
typedef enum		
{
	EPT_PWM_CBU_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<8 )),
	EPT_PWM_CBU_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<8 )),
	EPT_PWM_CBU_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<8 )),
	EPT_PWM_CBU_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<8 ))
}EPT_PWM_CBU_Output_Type;
/**
  * @brief  EPT PWM CBD Output
  */
typedef enum		
{
	EPT_PWM_CBD_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<10 )),
	EPT_PWM_CBD_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<10 )),
	EPT_PWM_CBD_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<10 )),
	EPT_PWM_CBD_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<10 ))
}EPT_PWM_CBD_Output_Type;
/**
  * @brief  EPT PWM T1U Output
  */
typedef enum		
{
	EPT_PWM_T1U_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<12 )),
	EPT_PWM_T1U_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<12 )),
	EPT_PWM_T1U_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<12 )),
	EPT_PWM_T1U_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<12 ))
}EPT_PWM_T1U_Output_Type;
/**
  * @brief  EPT PWM T1D Output
  */
typedef enum		
{
	EPT_PWM_T1D_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<14 )),
	EPT_PWM_T1D_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<14 )),
	EPT_PWM_T1D_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<14 )),
	EPT_PWM_T1D_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<14 ))
}EPT_PWM_T1D_Output_Type;
/**
  * @brief  EPT PWM T2U Output
  */
typedef enum		
{
	EPT_PWM_T2U_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<16 )),
	EPT_PWM_T2U_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<16 )),
	EPT_PWM_T2U_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<16 )),
	EPT_PWM_T2U_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<16 ))
}EPT_PWM_T2U_Output_Type;
/**
  * @brief  EPT PWM T2D Output
  */
typedef enum		
{
	EPT_PWM_T2D_Event_Nochange				=	((CSP_REGISTER_T)(0x00ul<<18 )),
	EPT_PWM_T2D_Event_OutLow				=	((CSP_REGISTER_T)(0x01ul<<18 )),
	EPT_PWM_T2D_Event_OutHigh				=	((CSP_REGISTER_T)(0x02ul<<18 )),
	EPT_PWM_T2D_Event_Negate				=	((CSP_REGISTER_T)(0x03ul<<18 ))
}EPT_PWM_T2D_Output_Type;
/**
  * @brief  EPT CPCR CMD
  */
typedef enum		
{
	EPT_CPCR_ENALBE		=	((CSP_REGISTER_T)(0x01ul<<16 )),
	EPT_CPCR_Disable	=	((CSP_REGISTER_T)(0x00ul<<16 ))
}EPT_CPCR_CMD_Type;
/**
  * @brief  EPT CPCR Source Selecte
  */
typedef enum		
{
	EPT_CPCR_Source_TCLK			=		((CSP_REGISTER_T)(0)),
	EPT_CPCR_Source_TIN_BT0OUT		=		((CSP_REGISTER_T)(1)),
	EPT_CPCR_Source_TIN_BT1OUT		=		((CSP_REGISTER_T)(2))
}EPT_CPCR_Source_Selecte_Type;
/**
  * @brief  EPT CPCR CDUTY
  */
typedef enum		
{
	EPT_CDUTY_DIS			=			((CSP_REGISTER_T)(0<<11)),	
	EPT_CDUTY_7_8			=			((CSP_REGISTER_T)(1<<11)),
	EPT_CDUTY_6_8			=			((CSP_REGISTER_T)(2<<11)),
	EPT_CDUTY_5_8			=			((CSP_REGISTER_T)(3<<11)),
	EPT_CDUTY_4_8			=			((CSP_REGISTER_T)(4<<11)),
	EPT_CDUTY_3_8			=			((CSP_REGISTER_T)(5<<11)),
	EPT_CDUTY_2_8			=			((CSP_REGISTER_T)(6<<11)),
	EPT_CDUTY_1_8			=			((CSP_REGISTER_T)(7<<11))
}EPT_CDUTY_Type;
/**
  * @brief  EPT EPX 
  */
typedef enum		
{
	EPT_EP0		=		0,	
	EPT_EP1		=		1,	
	EPT_EP2		=		2,	
	EPT_EP3		=		3,	
	EPT_EP4		=		4,	
	EPT_EP5		=		5,	
	EPT_EP6		=		6,	
	EPT_EP7		=		7
}EPT_EPX_Type;
/**
  * @brief  EPT Input selecte  
  */
typedef enum	
{
	EPT_Input_selecte_EPI0			=		((CSP_REGISTER_T)(1)),		
	EPT_Input_selecte_EPI1			=		((CSP_REGISTER_T)(2)),
	EPT_Input_selecte_EPI2			=		((CSP_REGISTER_T)(3)),
	EPT_Input_selecte_EPI3			=		((CSP_REGISTER_T)(4)),
	EPT_Input_selecte_EPI4			=		((CSP_REGISTER_T)(5)),
	EPT_Input_selecte_ORL0			=		((CSP_REGISTER_T)(0XE)),
	EPT_Input_selecte_ORL1			=		((CSP_REGISTER_T)(0XF))	
}EPT_Input_selecte_Type;
/**
  * @brief  EPT FLT PACE0 
  */
typedef enum	
{
	EPT_FLT_PACE0_DIS			=			((CSP_REGISTER_T)(0<<8)),
	EPT_FLT_PACE0_2CLK			=			((CSP_REGISTER_T)(1<<8)),
	EPT_FLT_PACE0_3CLK			=			((CSP_REGISTER_T)(2<<8)),
	EPT_FLT_PACE0_4CLK			=			((CSP_REGISTER_T)(3<<8))
}EPT_FLT_PACE0_Type;
/**
  * @brief  EPT FLT PACE1 
  */
typedef enum	
{
	EPT_FLT_PACE1_DIS			=			((CSP_REGISTER_T)(0<<10)),
	EPT_FLT_PACE1_2CLK			=			((CSP_REGISTER_T)(1<<10)),
	EPT_FLT_PACE1_3CLK			=			((CSP_REGISTER_T)(2<<10)),
	EPT_FLT_PACE1_4CLK			=			((CSP_REGISTER_T)(3<<10))
}EPT_FLT_PACE1_Type;
/**
  * @brief  EPT DB EventLoad
  */
typedef enum	
{
	EPT_DB_EventLoad_DIS							=		0,
	EPT_DB_EventLoad_Immediate						=		1,
	EPT_DB_EventLoad_ZRO							=		2,
	EPT_DB_EventLoad_PRD							=		3,
	EPT_DB_EventLoad_ZRO_PRD						=		4
}EPT_DB_EventLoad_Type;
/**
  * @brief  EPT CHX Selecte
  */
typedef enum	
{
	EPT_CHA_Selecte 		=		0,
	EPT_CHB_Selecte 		=		1,
	EPT_CHC_Selecte 		=		2,
}EPT_CHX_Selecte_Type;
/**
  * @brief  EPT INSEL
  */
typedef enum	
{
	EPT_CHA_PWMA_RISE_FALL			=		((CSP_REGISTER_T)(0<<4)),
	EPT_CHA_PWMB_RISE_PWMA_FALL		=		((CSP_REGISTER_T)(1<<4)),
	EPT_CHA_PWMA_RISE_PWMB_FALL		=		((CSP_REGISTER_T)(2<<4)),
	EPT_CHA_PWMB_RISE_FALL			=		((CSP_REGISTER_T)(3<<4)),	
	EPT_CHB_PWMB_RISE_FALL			=		((CSP_REGISTER_T)(0<<12)),
	EPT_CHB_PWMC_RISE_PWMB_FALL		=		((CSP_REGISTER_T)(1<<12)),
	EPT_CHB_PWMB_RISE_PWMC_FALL		=		((CSP_REGISTER_T)(2<<12)),
	EPT_CHB_PWMC_RISE_FALL			=		((CSP_REGISTER_T)(3<<12)),	
	EPT_CHC_PWMC_RISE_FALL			=		((CSP_REGISTER_T)(0<<20)),
	EPT_CHC_PWMD_RISE_PWMC_FALL		=		((CSP_REGISTER_T)(1<<20)),
	EPT_CHC_PWMC_RISE_PWMD_FALL		=		((CSP_REGISTER_T)(2<<20)),
	EPT_CHC_PWMD_RISE_FALL			=		((CSP_REGISTER_T)(3<<20))	
}EPT_INSEL_Type;
/**
  * @brief  EPT OUTSEL
  */
typedef enum	
{
	EPT_CHA_OUTSEL_PWMA_PWMB_Bypass			=		((CSP_REGISTER_T)(0)),
	EPT_CHA_OUTSEL_DisRise_EnFall			=		((CSP_REGISTER_T)(1)),
	EPT_CHA_OUTSEL_EnRise_DisFall			=		((CSP_REGISTER_T)(2)),
	EPT_CHA_OUTSEL_EnRise_EnFall			=		((CSP_REGISTER_T)(3)),
	EPT_CHB_OUTSEL_PWMB_PWMC_Bypass			=		((CSP_REGISTER_T)(0<<8)),
	EPT_CHB_OUTSEL_DisRise_EnFall			=		((CSP_REGISTER_T)(1<<8)),
	EPT_CHB_OUTSEL_EnRise_DisFall			=		((CSP_REGISTER_T)(2<<8)),
	EPT_CHB_OUTSEL_EnRise_EnFall			=		((CSP_REGISTER_T)(3<<8)),
	EPT_CHC_OUTSEL_PWMC_PWMD_Bypass			=		((CSP_REGISTER_T)(0<<16)),
	EPT_CHC_OUTSEL_DisRise_EnFall			=		((CSP_REGISTER_T)(1<<16)),
	EPT_CHC_OUTSEL_EnRise_DisFall			=		((CSP_REGISTER_T)(2<<16)),
	EPT_CHC_OUTSEL_EnRise_EnFall			=		((CSP_REGISTER_T)(3<<16))
}EPT_OUTSEL_Type;
/**
  * @brief  EPT OUT POLARITY
  */
typedef enum	
{
	EPT_PA_PB_OUT_Direct				=		((CSP_REGISTER_T)(0)),
	EPT_PA_OUT_Reverse					=		((CSP_REGISTER_T)(1)),
	EPT_PB_OUT_Reverse					=		((CSP_REGISTER_T)(2)),
	EPT_PA_PB_OUT_Reverse				=		((CSP_REGISTER_T)(3))
}EPT_OUT_POLARITY_Type;
/**
  * @brief  EPT OUT SWAP
  */
typedef enum	
{
	EPT_PAtoCHX_PBtoCHY					=		((CSP_REGISTER_T)(0)),
	EPT_PBtoCHX_PBtoCHY					=		((CSP_REGISTER_T)(1)),
	EPT_PAtoCHX_PAtoCHY					=		((CSP_REGISTER_T)(2)),
	EPT_PBtoCHX_PAtoCHY					=		((CSP_REGISTER_T)(3))
}EPT_OUT_SWAP_Type;
/**
  * @brief  EPT TRGSRCX Selecte
  */
typedef enum	
{
	EPT_TRGSRC0			=		0,
	EPT_TRGSRC1			=		1,
	EPT_TRGSRC2			=		2,
	EPT_TRGSRC3			=		3
}EPT_TRGSRCX_Select_Type;
/**
  * @brief  EPT EVTRG TRGSRCX SET
  */
 typedef enum
{	
	EPT_EVTRG_TRGSRCX_DIS			=	((CSP_REGISTER_T)(0x00ul )),  
	EPT_EVTRG_TRGSRCX_ZRO			=	((CSP_REGISTER_T)(0x01ul )),  
	EPT_EVTRG_TRGSRCX_PRD			=	((CSP_REGISTER_T)(0x02ul )),  
	EPT_EVTRG_TRGSRCX_ZROorPRD		=	((CSP_REGISTER_T)(0x03ul )),
	EPT_EVTRG_TRGSRCX_CMPAU			=	((CSP_REGISTER_T)(0x04ul )),
	EPT_EVTRG_TRGSRCX_CMPAD			=	((CSP_REGISTER_T)(0x05ul )),
	EPT_EVTRG_TRGSRCX_CMPBU			=	((CSP_REGISTER_T)(0x06ul )),
	EPT_EVTRG_TRGSRCX_CMPBD			=	((CSP_REGISTER_T)(0x07ul )),
	EPT_EVTRG_TRGSRCX_CMPCU			=	((CSP_REGISTER_T)(0x08ul )),
	EPT_EVTRG_TRGSRCX_CMPCD			=	((CSP_REGISTER_T)(0x09ul )),
	EPT_EVTRG_TRGSRCX_CMPDU			=	((CSP_REGISTER_T)(0x0Aul )),
	EPT_EVTRG_TRGSRCX_CMPDD			=	((CSP_REGISTER_T)(0x0Bul )),
	EPT_EVTRG_TRGSRC01_ExtSync		=	((CSP_REGISTER_T)(0x0Cul )),
	EPT_EVTRG_TRGSRC23_PeriodEnd	=	((CSP_REGISTER_T)(0x0Cul )),
	EPT_EVTRG_TRGSRCX_PE0			=	((CSP_REGISTER_T)(0x0Dul )),
	EPT_EVTRG_TRGSRCX_PE1			=	((CSP_REGISTER_T)(0x0Eul )),
	EPT_EVTRG_TRGSRCX_PE2			=	((CSP_REGISTER_T)(0x0Ful ))
}EPT_EVTRG_TRGSRCX_TypeDef;	
 typedef enum
{
	EPT_TRGSRC0_EN	=	((CSP_REGISTER_T)0x00ul),  
	EPT_TRGSRC0_DIS	=	((CSP_REGISTER_T)0x01ul)  
}EPT_TRGSRCX_CMD_TypeDef;
/**
  * @brief  EPT INT register 
  */
typedef enum
{
	//RISR IMCR MISR ICR
	EPT_TRGEV0_INT        		=		((CSP_REGISTER_T)(0x01ul << 0)),  
	EPT_TRGEV1_INT      		=		((CSP_REGISTER_T)(0x01ul << 1)),    
	EPT_TRGEV2_INT        		=		((CSP_REGISTER_T)(0x01ul << 2)),   
	EPT_TRGEV3_INT      		=		((CSP_REGISTER_T)(0x01ul << 3)),   
	EPT_CAP_LD0					=		((CSP_REGISTER_T)(0x01ul << 4)),   
	EPT_CBP_LD1					=		((CSP_REGISTER_T)(0x01ul << 5)),
	EPT_CCP_LD2					=		((CSP_REGISTER_T)(0x01ul << 6)),
	EPT_CDP_LD3					=		((CSP_REGISTER_T)(0x01ul << 7)),
	EPT_CAU						=		((CSP_REGISTER_T)(0x01ul <<8)),
	EPT_CAD						=		((CSP_REGISTER_T)(0x01ul <<9)),
	EPT_CBU						=		((CSP_REGISTER_T)(0x01ul <<10)),
	EPT_CBD						=		((CSP_REGISTER_T)(0x01ul <<11)),
	EPT_CCU						=		((CSP_REGISTER_T)(0x01ul <<12)),
	EPT_CCD						=		((CSP_REGISTER_T)(0x01ul <<13)),
	EPT_CDU						=		((CSP_REGISTER_T)(0x01ul <<14)),
	EPT_CDD						=		((CSP_REGISTER_T)(0x01ul <<15)),
	EPT_PEND					=		((CSP_REGISTER_T)(0x01ul <<16))
}EPT_INT_TypeDef;
/**
  * @brief  EPT EMINT register 
  */
typedef enum
{
	//EMRISR EMIMCR EMMISR EMICR
	EPT_EP0_EMINT        		=		((CSP_REGISTER_T)(0x01ul << 0)),  
	EPT_EP1_EMINT      			=		((CSP_REGISTER_T)(0x01ul << 1)),    
	EPT_EP2_EMINT        		=		((CSP_REGISTER_T)(0x01ul << 2)),   
	EPT_EP3_EMINT      			=		((CSP_REGISTER_T)(0x01ul << 3)),
	EPT_EP4_EMINT        		=		((CSP_REGISTER_T)(0x01ul << 4)),  
	EPT_EP5_EMINT      			=		((CSP_REGISTER_T)(0x01ul << 5)),    
	EPT_EP6_EMINT        		=		((CSP_REGISTER_T)(0x01ul << 6)),   
	EPT_EP7_EMINT      			=		((CSP_REGISTER_T)(0x01ul << 7)),
	EPT_CPU_FAULT_EMINT      	=		((CSP_REGISTER_T)(0x01ul << 8)),
	EPT_MEM_FAULT_EMINT      	=		((CSP_REGISTER_T)(0x01ul << 9)),
	EPT_EOM_FAULT_EMINT      	=		((CSP_REGISTER_T)(0x01ul << 10))
}EPT_EMINT_TypeDef;
/**
  * @brief  EPT LKCR TRG Source
  */
typedef enum
{
	EPT_LKCR_TRG_EP0			=		0,
	EPT_LKCR_TRG_EP1			=		2,
	EPT_LKCR_TRG_EP2			=		4,
	EPT_LKCR_TRG_EP3			=		6,
	EPT_LKCR_TRG_EP4			=		8,
	EPT_LKCR_TRG_EP5			=		10,
	EPT_LKCR_TRG_EP6			=		12,
	EPT_LKCR_TRG_EP7			=		14,
	EPT_LKCR_TRG_CPU_FAULT		=		15,
	EPT_LKCR_TRG_MEM_FAULT		=		16,
	EPT_LKCR_TRG_EOM_FAULT		=		17
}EPT_LKCR_TRG_Source_Type;
/**
  * @brief  EPT LKCR Mode Selecte	
  */
typedef enum
{
	EPT_LKCR_Mode_LOCK_DIS		=		((CSP_REGISTER_T)0x00ul),
	EPT_LKCR_Mode_SLOCK_EN		=		((CSP_REGISTER_T)0x01ul),
	EPT_LKCR_Mode_HLOCK_EN		=		((CSP_REGISTER_T)0x02ul),
	EPT_LKCR_TRG_X_FAULT_HLOCK_EN		=		((CSP_REGISTER_T)0x03ul),
	EPT_LKCR_TRG_X_FAULT_HLOCK_DIS		=		((CSP_REGISTER_T)0x04ul),
}EPT_LKCR_Mode_Type;
/**
  * @brief  EPT OUTPUT Channel	
  */
typedef enum
{
	EPT_OUTPUT_Channel_CHAX		=		0,
	EPT_OUTPUT_Channel_CHBX		=		2,
	EPT_OUTPUT_Channel_CHCX		=		4,
	EPT_OUTPUT_Channel_CHD		=		6,
	EPT_OUTPUT_Channel_CHAY		=		8,
	EPT_OUTPUT_Channel_CHBY		=		10,
	EPT_OUTPUT_Channel_CHCY		=		12
}EPT_OUTPUT_Channel_Type;
/**
  * @brief  EPT SHLOCK OUTPUT Statue
  */
typedef enum
{
	EPT_SHLOCK_OUTPUT_HImpedance		=	0,
	EPT_SHLOCK_OUTPUT_High				=	1,
	EPT_SHLOCK_OUTPUT_Low				=	2,
	EPT_SHLOCK_OUTPUT_Nochange			=	3
}EPT_SHLOCK_OUTPUT_Statue_Type;

/** @addtogroup EPT_Exported_functions
  * @{
  */
extern void EPT_Software_Prg(void);
extern void EPT_Start(void);  
extern void EPT_Stop(void);  
extern void EPT_IO_SET(EPT_IO_Mode_Type EPT_IO_X , EPT_IO_NUM_Type IO_Num_X);
extern void EPT_PWM_Config(EPT_TCLK_Selecte_Type EPT_TCLK_Selecte_X , EPT_CNTMD_SELECTE_Type EPT_CNTMD_SELECTE_X  , EPT_OPM_SELECTE_Type EPT_OPM_SELECTE_X
					, U16_T EPT_PSCR);	
extern void EPT_Capture_Config(EPT_TCLK_Selecte_Type EPT_TCLK_Selecte_X , EPT_CNTMD_SELECTE_Type EPT_CNTMD_SELECTE_X  , EPT_CAPMD_SELECTE_Type EPT_CAPMD_SELECTE_X , EPT_CAPLDEN_CMD_Type CAP_CMD 
					, EPT_LOAD_CMPA_RST_CMD_Type EPT_LOAD_CMPA_RST_CMD , EPT_LOAD_CMPB_RST_CMD_Type EPT_LOAD_CMPB_RST_CMD , EPT_LOAD_CMPC_RST_CMD_Type EPT_LOAD_CMPC_RST_CMD
					, EPT_LOAD_CMPD_RST_CMD_Type EPT_LOAD_CMPD_RST_CMD , U8_T EPT_STOP_WRAP , U16_T EPT_PSCR);
extern void EPT_FLT_Config(EPT_FLT_CMD_Type EPT_FLT_CMD , EPT_FLT_CGFLT_Type  EPT_FLT_X , U8_T FLTCKPRS);
extern void EPT_SYNCR_Config(EPT_Triggle_Mode_Type EPT_Triggle_X , EPT_SYNCUSR0_REARMTrig_Selecte_Type EPT_SYNCUSR0_REARMTrig_Selecte , EPT_TRGSRC0_ExtSync_Selected_Type EPT_TRGSRC0_ExtSync_Selected ,
					  EPT_TRGSRC1_ExtSync_Selected_Type EPT_TRGSRC1_ExtSync_Selected , U8_T EPT_SYNCR_EN);
extern void EPT_PHSEN_Config(EPT_PHSEN_CMD_Type EPT_PHSEN_CMD , EPT_PHSDIR_Type EPT_PHSDIR , U16_T PHSR);			  
extern void EPT_SYNCR_Rearm(EPT_REARMX_Type EPT_REARMX , EPT_REARM_MODE_Type EPT_REARM_MODE);
extern void EPT_Caputure_Rearm(void);  
extern void EPT_Globle_Eventload_Config(EPT_GLDMD_Selecte_Type EPT_GLDMD_Selecte_X , U16_T GLDCFG_EN);  
extern void EPT_Globle_SwLoad_Config(U16_T GLDCFG_EN); 
extern void EPT_CPCR_Config(EPT_CPCR_CMD_Type EPT_CPCR_CMD , EPT_CPCR_Source_Selecte_Type EPT_CPCR_Source_X , EPT_CDUTY_Type EPT_CDUTY_X , U8_T EPT_CPCR_OSPWTH , U8_T EPT_CPCR_CDIV);
extern void EPT_PWMX_Output_Control(
							 EPT_PWMX_Selecte_Type EPT_PWMX_Selecte ,EPT_CA_Selecte_Type EPT_CA_Selecte_X , EPT_CB_Selecte_Type EPT_CB_Selecte_X ,
							 EPT_PWM_ZRO_Output_Type EPT_PWM_ZRO_Event_Output , EPT_PWM_PRD_Output_Type EPT_PWM_PRD_Event_Output , 
							 EPT_PWM_CAU_Output_Type EPT_PWM_CAU_Event_Output , EPT_PWM_CAD_Output_Type EPT_PWM_CAD_Event_Output ,
							 EPT_PWM_CBU_Output_Type EPT_PWM_CBU_Event_Output , EPT_PWM_CBD_Output_Type EPT_PWM_CBD_Event_Output ,
							 EPT_PWM_T1U_Output_Type EPT_PWM_T1U_Event_Output , EPT_PWM_T1D_Output_Type EPT_PWM_T1D_Event_Output ,
							 EPT_PWM_T2U_Output_Type EPT_PWM_T2U_Event_Output , EPT_PWM_T2D_Output_Type EPT_PWM_T2D_Event_Output 
							 );
extern void EPT_Tevent_Selecte( U8_T EPT_T1_Selecte, U8_T EPT_T2_Selecte);						 
extern void EPT_PRDR_CMPA_CMPB_CMPC_CMPD_Config(U16_T EPT_PRDR_Value , U16_T EPT_CMPA_Value , U16_T EPT_CMPB_Value , U16_T EPT_CMPC_Value , U16_T EPT_CMPD_Value);
extern void EPT_PRDR_EventLoad_Config(EPT_PRDR_EventLoad_Type EPT_PRDR_EventLoad_x);
extern void EPT_CMP_EventLoad_Config(EPT_CMPX_EventLoad_Type EPT_CMPX_EventLoad_x);  
extern void EPT_AQCR_Eventload_Config(EPT_AQCRX_EventLoad_Type EPT_AQCRX_EventLoad_X);
extern void EPT_EPX_Config(EPT_EPX_Type EPT_EPX , EPT_Input_selecte_Type EPT_Input_selecte_x , EPT_FLT_PACE0_Type EPT_FLT_PACE0_x , EPT_FLT_PACE1_Type EPT_FLT_PACE1_x , U8_T EPT_EPIX_POL);
extern void EPT_DB_Eventload_Config(EPT_DB_EventLoad_Type EPT_DB_EventLoad_X);  
extern void EPT_DBCR_Config(EPT_CHX_Selecte_Type EPT_CHX_Selecte , EPT_INSEL_Type EPT_INSEL_X , EPT_OUTSEL_Type EPT_OUTSEL_X , EPT_OUT_POLARITY_Type EPT_OUT_POLARITY_X , EPT_OUT_SWAP_Type EPT_OUT_SWAP_X);
extern void EPT_DB_CLK_Config(U16_T DPSC , U16_T DTR , U16_T DTF);
extern void EPT_TRGSRCX_Config(EPT_TRGSRCX_Select_Type EPT_TRGSRCX_Select , EPT_EVTRG_TRGSRCX_TypeDef EPT_EVTRG_TRGSRCX_X , EPT_TRGSRCX_CMD_TypeDef EPT_TRGSRCX_CMD , U8_T TRGEVXPRD);  
extern void EPT_TRGSRCX_SWFTRG(EPT_TRGSRCX_Select_Type EPT_TRGSRCX_Select); 
extern void EPT_Int_Enable(EPT_INT_TypeDef EPT_X_INT);
extern void EPT_Int_Disable(EPT_INT_TypeDef EPT_X_INT);
extern void EPT_EMInt_Enable(EPT_EMINT_TypeDef EPT_X_EMINT);
extern void EPT_EMInt_Disable(EPT_EMINT_TypeDef EPT_X_EMINT);
extern void EPT_Vector_Int_Enable(void);
extern void EPT_Vector_Int_Disable(void);
extern void EPT_SLock_CLR(EPT_EMINT_TypeDef EPT_X_EMINT);
extern void EPT_HLock_CLR(EPT_EMINT_TypeDef EPT_X_EMINT);
extern void EPT_SW_Set_lock(EPT_EMINT_TypeDef EPT_X_EMINT);  
extern void EPT_LKCR_TRG_Config(EPT_LKCR_TRG_Source_Type EPT_LKCR_TRG_X , EPT_LKCR_Mode_Type EPT_LKCR_Mode_X);
extern void EPT_SHLOCK_OUTPUT_Config(EPT_OUTPUT_Channel_Type EPT_OUTPUT_Channel_X , EPT_SHLOCK_OUTPUT_Statue_Type EPT_SHLOCK_OUTPUT_X);

#endif   /**< apt32f102_ept_H */

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/