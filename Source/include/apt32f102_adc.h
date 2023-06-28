/*
  ******************************************************************************
  * @file    apt32f102_adc.h
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
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _apt32f102_adc_H
#define _apt32f102_adc_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


/******************************************************************************
************************* ADC12 Registers reset value ************************
******************************************************************************/
 #define ADC_ECR_RST          (0x00000000ul)          /**< ECR  reset value  */
 #define ADC_DCR_RST          (0x00000000ul)          /**< DCR  reset value  */
 #define ADC_PMSR_RST         (0x00000000ul)   		  /**< PMSR reset value  */
 #define ADC_CR_RST           (0x80000000ul)          /**< CR   reset value  */
 #define ADC_MR_RST           (0x00000000ul)          /**< MR   reset value  */
 #define ADC_CSR_RST		  (0x00000000ul)		  /**< CSR   reset value  */
 #define ADC_SR_RST           (0x00000000ul)          /**< SR   reset value  */
 #define ADC_IER_RST          (0x00000000ul)          /**< IER  reset value  */
 #define ADC_IDR_RST          (0x00000000ul)          /**< IDR  reset value  */
 #define ADC_IMR_RST          (0x00000000ul)          /**< IMR  reset value  */
 #define ADC_SEQx_RST         (0x00000080ul)          /**< SEQx  reset value */
 #define ADC_DR_RST           (0x00000000ul)          /**< DR   reset value  */
 #define ADC_CMP0_RST         (0x00000000ul)          /**< CMP0 reset value  */
 #define ADC_CMP1_RST         (0x00000000ul)          /**< CMP1 reset value  */
/**
  * @brief  ADC12 Control register
  */
typedef enum
{
	ADC12_SWRST     =		((CSP_REGISTER_T)(0x01ul << 0)),            /**< Software Reset        */
	ADC12_ADCEN     =		((CSP_REGISTER_T)(0x01ul << 1)),            /**< ADC Enable            */
	ADC12_ADCDIS    =		((CSP_REGISTER_T)(0x01ul << 2)),            /**< ADC Disable           */
	ADC12_START     =		((CSP_REGISTER_T)(0x01ul << 3)),            /**< Start Conversion      */
	ADC12_STOP      =		((CSP_REGISTER_T)(0x01ul << 4)),            /**< Stop Conversion       */
	ADC12_SWTRG      =		((CSP_REGISTER_T)(0x01ul << 5)),            /**< Stop Conversion       */
	ADC12_AVGEN		=		((CSP_REGISTER_T)(0x01ul << 12)),            /**< Conversion data get average      */
	ADC12_AVGDIS	=		((CSP_REGISTER_T)(0x00ul << 12)),            /**< Conversion data get last one     */
}ADC12_Control_TypeDef;
/**
  * @brief  ADC12 IMR register 
  */
typedef enum
{
	//CSR SR, IER, IDR, IMR Registers
	ADC12_EOC        =		((CSP_REGISTER_T)(0x01ul << 0)),     /**< End Of Conversion           */
	ADC12_READY      =		((CSP_REGISTER_T)(0x01ul << 1)),     /**< Ready to Start              */
	ADC12_OVR        =		((CSP_REGISTER_T)(0x01ul << 2)),     /**< Over Run                    */
	ADC12_CMP0H      =		((CSP_REGISTER_T)(0x01ul << 4)),     /**< Higher than CMP1            */
	ADC12_CMP0L      =		((CSP_REGISTER_T)(0x01ul << 5)),     /**< Lower than CMP1             */
	ADC12_CMP1H      =		((CSP_REGISTER_T)(0x01ul << 6)),     /**< Higher than CMP2            */
	ADC12_CMP1L      =		((CSP_REGISTER_T)(0x01ul << 7)),     /**< Lower than CMP2              */
	ADC12_SEQ_END0   =		((CSP_REGISTER_T)(0x01ul << 16)),     /**< SEQ0 Convert end              */
	ADC12_SEQ_END1   =		((CSP_REGISTER_T)(0x01ul << 17)),     /**< SEQ1 Convert end              */
	ADC12_SEQ_END2   =		((CSP_REGISTER_T)(0x01ul << 18)),     /**< SEQ2 Convert end              */
	ADC12_SEQ_END3   =		((CSP_REGISTER_T)(0x01ul << 19)),     /**< SEQ3 Convert end              */
	ADC12_SEQ_END4   =		((CSP_REGISTER_T)(0x01ul << 20)),     /**< SEQ4 Convert end              */
	ADC12_SEQ_END5   =		((CSP_REGISTER_T)(0x01ul << 21)),     /**< SEQ5 Convert end              */
	ADC12_SEQ_END6   =		((CSP_REGISTER_T)(0x01ul << 22)),     /**< SEQ6 Convert end              */
	ADC12_SEQ_END7   =		((CSP_REGISTER_T)(0x01ul << 23)),     /**< SEQ7 Convert end              */
	ADC12_SEQ_END8   =		((CSP_REGISTER_T)(0x01ul << 24)),     /**< SEQ8 Convert end              */
	ADC12_SEQ_END9   =		((CSP_REGISTER_T)(0x01ul << 25)),     /**< SEQ9 Convert end              */
	ADC12_SEQ_END10   =		((CSP_REGISTER_T)(0x01ul << 26)),     /**< SEQ10 Convert end              */
	ADC12_SEQ_END11   =		((CSP_REGISTER_T)(0x01ul << 27)),     /**< SEQ11 Convert end              */
	ADC12_SEQ_END12   =		((CSP_REGISTER_T)(0x01ul << 28)),     /**< SEQ12 Convert end              */
	ADC12_SEQ_END13   =		((CSP_REGISTER_T)(0x01ul << 29)),     /**< SEQ13 Convert end              */
	ADC12_SEQ_END14   =		((CSP_REGISTER_T)(0x01ul << 30)),     /**< SEQ14 Convert end              */
	ADC12_SEQ_END15   =		((CSP_REGISTER_T)(0x01ul << 31)),     /**< SEQ15 Convert end              */
	/* SR Register Only                                                          */
	ADC12_ADCENS     =		((CSP_REGISTER_T)(0x01ul << 8)),     /**< ADC Enable Status           */
	ADC12_CTCVS      =		((CSP_REGISTER_T)(0x01ul << 9))      /**< Continuous Conversion Status*/
}
ADC12_IMR_TypeDef;
/**
  * @brief  ADC12 CLK ENABLE AND DISABLE 
  */
typedef enum
{
	ADC_CLK_CR 			=		((CSP_REGISTER_T)(0x01ul << 1)),				/**< ADC Clock             */
	ADC12_IPIDCODE_MASK =		((CSP_REGISTER_T)(0x3FFFFFFul << 4)),			/**< ADC IPIDCODE mask     */
	ADC_DEBUG_MODE		=		((CSP_REGISTER_T)(0x01ul << 31))				/**< Debug Mode Enable     */
}
ADC12_CLK_TypeDef;
/**
  * @brief  ADC12 Bit slection
  */
typedef enum
{
	ADC12_12BIT     	=		1,           								/**< 12bit mode            */
	ADC12_10BIT    	 	=		0,           								/**< 10bit mode            */
	ADC12_10BITor12BIT	=		((CSP_REGISTER_T)(0x01ul<<31))
}ADC12_10bitor12bit_TypeDef;
/**
  * @brief  ADC12 Convertion mode
  */
typedef enum
{
	One_shot_mode	=	0,
	Continuous_mode =	1,
	CONTCV			=	(CSP_REGISTER_T)0x01<<31					//Continuous Conversion	 0: One shot mode.  1: Continuous mode.
}ADC12_ConverMode_TypeDef;
/**
  * @brief  ADC12 NBRCMPx selection 
  */
typedef enum
{
	NBRCMP0_TypeDef		=	0,
	NBRCMP1_TypeDef		=	1
}
ADC12_NBRCMPx_TypeDef;
/**
  * @brief  ADC12 NBRCMPx_HorL selection 
  */
typedef enum
{
	NBRCMPX_L_TypeDef	=	0,
	NBRCMPX_H_TypeDef	=	1
}
ADC12_NBRCMPx_HorL_TypeDef;
/**
  * @brief  ADC12 SEQx register
  */
typedef enum
{
	 ADC12_ADCIN0       =	(CSP_REGISTER_T)(0x0ul),                   /**< ADC Analog Input 0 */
	 ADC12_ADCIN1       =	(CSP_REGISTER_T)(0x1ul),                    /**< ADC Analog Input 1 */
	 ADC12_ADCIN2       =	(CSP_REGISTER_T)(0x2ul),                   /**< ADC Analog Input 2 */
	 ADC12_ADCIN3       =	(CSP_REGISTER_T)(0x3ul),                    /**< ADC Analog Input 3 */
	 ADC12_ADCIN4       =	(CSP_REGISTER_T)(0x4ul),                   /**< ADC Analog Input 4 */
	 ADC12_ADCIN5       =	(CSP_REGISTER_T)(0x5ul),                    /**< ADC Analog Input 5 */
	 ADC12_ADCIN6       =	(CSP_REGISTER_T)(0x6ul),                    /**< ADC Analog Input 6 */
	 ADC12_ADCIN7       =	(CSP_REGISTER_T)(0x7ul),                    /**< ADC Analog Input 7 */
	 ADC12_ADCIN8       =	(CSP_REGISTER_T)(0x8ul),                   /**< ADC Analog Input 8 */
	 ADC12_ADCIN9       =	(CSP_REGISTER_T)(0x9ul),                    /**< ADC Analog Input 9 */
	 ADC12_ADCIN10      =	(CSP_REGISTER_T)(0x0Aul),                   /**< ADC Analog Input 10 */
	 ADC12_ADCIN11      =	(CSP_REGISTER_T)(0x0Bul),                    /**< ADC Analog Input 11 */
	 ADC12_ADCIN12      =	(CSP_REGISTER_T)(0x0Cul),                    /**< ADC Analog Input 12 */
	 ADC12_ADCIN13       =	(CSP_REGISTER_T)(0x0Dul),                   /**< ADC Analog Input 13 */
	 ADC12_ADCIN14       =	(CSP_REGISTER_T)(0x0Eul),                    /**< ADC Analog Input 14 */
	 ADC12_ADCIN15       =	(CSP_REGISTER_T)(0x0Ful),                   /**< ADC Analog Input 15 */
	 //ADC12_ADCIN16       =	(CSP_REGISTER_T)(0x10ul),                    /**< ADC Analog Input 16 */
	 //ADC12_ADCIN17      =	(CSP_REGISTER_T)(0x11ul),                   /**< ADC Analog Input 17 */
	 //ADC12_ADCIN18       =	(CSP_REGISTER_T)(0x12ul),                    /**< ADC Analog Input 18 */
	 //ADC12_ADCIN19       =	(CSP_REGISTER_T)(0x13ul),                    /**< ADC Analog Input 19 */
	 //ADC12_ADCIN20       =	(CSP_REGISTER_T)(0x14ul),                    /**< ADC Analog Input 20 */
	 //ADC12_ADCIN21       =	(CSP_REGISTER_T)(0x15ul),                   /**< ADC Analog Input 21 */
	 //ADC12_ADCIN22       =	(CSP_REGISTER_T)(0x16ul),                    /**< ADC Analog Input 22 */
	 //ADC12_ADCIN23      =	(CSP_REGISTER_T)(0x17ul),                   /**< ADC Analog Input 23 */
	 //ADC12_ADCIN24      =	(CSP_REGISTER_T)(0x18ul),                    /**< ADC Analog Input 24 */
	 //ADC12_ADCIN25      =	(CSP_REGISTER_T)(0x19ul),                    /**< ADC Analog Input 25 */
	 //ADC12_ADCIN26      =	(CSP_REGISTER_T)(0x1Aul),                    /**< ADC Analog Input 26 */
	 //ADC12_ADCIN27      =	(CSP_REGISTER_T)(0x1Bul)                    /**< ADC Analog Input 27 */
	 ADC12_INTVREF		      =	(CSP_REGISTER_T)(0x1Cul), 
	 ADC12_DIV4_VDD		  =	(CSP_REGISTER_T)(0x1Dul),
	 ADC12_VSS		  	  =	(CSP_REGISTER_T)(0x1Eul),
}
ADC12_InputSet_TypeDef;

/**
  * @brief  ADC12 Convertion repeat number
  */
typedef enum
{	
	 ADC12_CV_RepeatNum1   	   =	(CSP_REGISTER_T)(0x0ul<<8)|(0x0ul<<13),                   /**< ADC Convertion number 1 */
	 ADC12_CV_RepeatNum2       =	(CSP_REGISTER_T)(0x1ul<<8)|(0x1ul<<13),                    /**< ADC Convertion number 2 */
	 ADC12_CV_RepeatNum4       =	(CSP_REGISTER_T)(0x2ul<<8)|(0x2ul<<13),                   /**< ADC Convertion number 4 */
	 ADC12_CV_RepeatNum8       =	(CSP_REGISTER_T)(0x3ul<<8)|(0x3ul<<13),                    /**< ADC Convertion number 8 */
	 ADC12_CV_RepeatNum16      =	(CSP_REGISTER_T)(0x4ul<<8)|(0x4ul<<13),                   /**< ADC Convertion number 16 */
	 ADC12_CV_RepeatNum32      =	(CSP_REGISTER_T)(0x5ul<<8)|(0x5ul<<13),                    /**< ADC Convertion number 32 */
	 ADC12_CV_RepeatNum64      =	(CSP_REGISTER_T)(0x6ul<<8)|(0x6ul<<13),                    /**< ADC Convertion number 64 */
	 ADC12_CV_RepeatNum128     =	(CSP_REGISTER_T)(0x7ul<<8)|(0x7ul<<13),                    /**< ADC Convertion number 128 */
	 ADC12_CV_RepeatNum256     =	(CSP_REGISTER_T)(0x8ul<<8)|(0x8ul<<13),                    /**< ADC Convertion number 256 */
	 ADC12_CV_RepeatNum512     =	(CSP_REGISTER_T)(0x9ul<<8)|(0x9ul<<13)                     /**< ADC Convertion number 512 */
}ADC12_CV_RepeatNum_TypeDef;

/**
  * @brief  ADC12 VREFP VREFN Selecte
  */
typedef enum
{
	ADC12_VREFP_VDD_VREFN_VSS				=		0,
	ADC12_VREFP_EXIT_VREFN_VSS				=		1,
	ADC12_VREFP_FVR2048_VREFN_VSS			=		2,
	ADC12_VREFP_FVR4096_VREFN_VSS			=		3,
	//ADC12_VREFP_INTVREF0750_VREFN_VSS		=		4,
	ADC12_VREFP_INTVREF1000_VREFN_VSS		=		5,
	ADC12_VREFP_VDD_VREFN_EXIT				=		6,
	ADC12_VREFP_EXIT_VREFN_EXIT				=		7,
	ADC12_VREFP_FVR2048_VREFN_EXIT			=		8,
	ADC12_VREFP_FVR4096_VREFN_EXIT			=		9,
	//ADC12_VREFP_INTVREF0750_VREFN_EXIT		=		10,
	ADC12_VREFP_INTVREF1000_VREFN_EXIT		=		11
}ADC12_VREFP_VREFN_Selected_TypeDef;

extern void ADC12_RESET_VALUE(void);
extern void ADC12_Control(ADC12_Control_TypeDef ADC12_Control_x );
extern void ADC12_ConfigInterrupt_CMD( ADC12_IMR_TypeDef ADC_IMR_X , FunctionalStatus NewState);
extern uint8_t ADC12_Read_IntEnStatus(ADC12_IMR_TypeDef EnStatus_bit);
extern void ADC12_CLK_CMD(ADC12_CLK_TypeDef ADC_CLK_CMD , FunctionalStatus NewState);
extern void ADC12_Software_Reset(void);
extern void ADC12_CMD(FunctionalStatus NewState);
extern void ADC12_ready_wait(void);  
extern void ADC12_EOC_wait(void);
extern void ADC12_SEQEND_wait(U8_T val);
extern U16_T ADC12_DATA_OUPUT(U16_T Data_index );
extern void  ADC12_Configure_Mode(ADC12_10bitor12bit_TypeDef ADC12_BIT_SELECTED  , ADC12_ConverMode_TypeDef  ADC12_ConverMode  , U8_T ADC12_PRI, U8_T adc12_SHR , U8_T ADC12_DIV , U8_T NumConver );
extern void ADC12_Configure_VREF_Selecte(ADC12_VREFP_VREFN_Selected_TypeDef ADC12_VREFP_X_VREFN_X );
extern void ADC12_CompareFunction_set(U8_T ConverNum_CM0 , U8_T ConverNum_CM1 , U16_T CMP0_data , U16_T CMP1_data );
extern void ADC12_ConversionChannel_Config(ADC12_InputSet_TypeDef ADC12_ADCINX ,
						ADC12_CV_RepeatNum_TypeDef CV_RepeatTime, ADC12_Control_TypeDef AVG_Set, U8_T SEQx);
extern U8_T ADC12_Compare_statue(ADC12_NBRCMPx_TypeDef ADC12_NBRCMPx, ADC12_NBRCMPx_HorL_TypeDef ADC12_NBRCMPx_HorL);
extern void ADC_Int_Enable(void);		
extern void ADC_Int_Disable(void);	
extern void ADC12_CONFIG(void);	
extern void adc12_SHR_SET(U8_T adc12_SHR);		

#endif   /**< apt32f102_adc_H */

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/