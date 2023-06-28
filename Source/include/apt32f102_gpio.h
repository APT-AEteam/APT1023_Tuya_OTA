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
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _apt32f102_gpio_H
#define _apt32f102_gpio_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


#define GPIO_RESET_VALUE  (0x00000000)
//--------------------------------------------------------------------------------
//-----------------------------GPIO  value enum define--------------------------
//--------------------------------------------------------------------------------
/**
  * @brief  GPIO pin numbner
  */
typedef enum
{
  PIN_0    = 0,  	/*!< Pin 0 selected */
  PIN_1    = 4,  	/*!< Pin 1 selected */
  PIN_2    = 8,  	/*!< Pin 2 selected */
  PIN_3    = 12,   	/*!< Pin 3 selected */
  PIN_4    = 16,  	/*!< Pin 4 selected */
  PIN_5    = 20,  	/*!< Pin 5 selected */
  PIN_6    = 24,  	/*!< Pin 6 selected */
  PIN_7    = 28,  	/*!< Pin 7 selected */
  PIN_8    = 0,  	/*!< Pin 8 selected */
  PIN_9    = 4,  	/*!< Pin 9 selected */
  PIN_10   = 8,  	/*!< Pin 10 selected */
  PIN_11   = 12,   	/*!< Pin 11 selected */
  PIN_12   = 16,  	/*!< Pin 12 selected */
  PIN_13   = 20,  	/*!< Pin 13 selected */
  PIN_14   = 24,  	/*!< Pin 13 selected */
  PIN_15   = 28,  	/*!< Pin 13 selected */
}GPIO_Pin_TypeDef;
/**
  * @brief  GPIO  high/low register
  */
typedef enum
{
    LowByte = 0,
    HighByte = 1,
}GPIO_byte_TypeDef;
/**
  * @brief  GPIO  IO status
  */
typedef enum
{
    Intput = 1,
    Output = 0,
}GPIO_Dir_TypeDef;
/**
  * @brief  GPIO  IO mode
  */
typedef enum
{
    PUDR = 0,                       //pull high or low
    DSCR =1,                        //drive strenth
    OMCR =2,                        //open drain
    IECR =3,                        //int
}GPIO_Mode_TypeDef;
/**
  * @brief  GPIO  IO Group
  */
typedef enum
{
    PA0 = 0,
    PB0 = 2,
    GPIOA = 0,
    GPIOB = 2,
}GPIO_Group_TypeDef;
/**
  * @brief  GPIO  exi number
  */
typedef enum
{
    EXI0 = 0,
    EXI1 = 1,
    EXI2 = 2,
    EXI3 = 3,
    EXI4 = 4,
    EXI5 = 5,
    EXI6 = 6,
    EXI7 = 7,
    EXI8 = 8,
    EXI9 = 9,
    EXI10 = 10,
    EXI11 = 11,
    EXI12 = 12,
    EXI13 = 13,
	EXI14 = 14,
	EXI15 = 15,
}GPIO_EXI_TypeDef;

/**
  * @brief  EXI PIN
  */
typedef enum
{
	Selete_EXI_PIN0		=		(CSP_REGISTER_T)(0),						
	Selete_EXI_PIN1		=		(CSP_REGISTER_T)(1),
	Selete_EXI_PIN2		=		(CSP_REGISTER_T)(2),
	Selete_EXI_PIN3		=		(CSP_REGISTER_T)(3),
	Selete_EXI_PIN4		=		(CSP_REGISTER_T)(4),
	Selete_EXI_PIN5		=		(CSP_REGISTER_T)(5),
	Selete_EXI_PIN6		=		(CSP_REGISTER_T)(6),
	Selete_EXI_PIN7		=		(CSP_REGISTER_T)(7),
	Selete_EXI_PIN8		=		(CSP_REGISTER_T)(8),
	Selete_EXI_PIN9		=		(CSP_REGISTER_T)(9),
	Selete_EXI_PIN10		=		(CSP_REGISTER_T)(10),
	Selete_EXI_PIN11		=		(CSP_REGISTER_T)(11),
	Selete_EXI_PIN12		=		(CSP_REGISTER_T)(12),
	Selete_EXI_PIN13		=		(CSP_REGISTER_T)(13),
	Selete_EXI_PIN14		=		(CSP_REGISTER_T)(14),
	Selete_EXI_PIN15		=		(CSP_REGISTER_T)(15),
	Selete_EXI_PIN16		=		(CSP_REGISTER_T)(16),
	Selete_EXI_PIN17		=		(CSP_REGISTER_T)(17),
	Selete_EXI_PIN18		=		(CSP_REGISTER_T)(18),
	Selete_EXI_PIN19		=		(CSP_REGISTER_T)(19)
}GPIO_EXIPIN_TypeDef;


/**
  * @brief  GPIO INPUT MODE SETECTED
  */
typedef enum
{
	INPUT_MODE_SETECTED_CMOS			=		0,
	INPUT_MODE_SETECTED_TTL1			=		1,
	INPUT_MODE_SETECTED_TTL2			=		2
}INPUT_MODE_SETECTED_TypeDef;

#define nop      asm ("nop")

#define SetPA0(n)   (GPIOA0->SODR = (1ul<<n))
#define ClrPA0(n)   (GPIOA0->CODR = (1ul<<n))

#define SetPB0(n)   (GPIOB0->SODR = (1ul<<n))
#define ClrPB0(n)   (GPIOB0->CODR = (1ul<<n))

#define PA0in(n)    (((GPIOA0->PSDR)>>n) & 1ul)
#define PB0in(n)    (((GPIOB0->PSDR)>>n) & 1ul)


#define CSP_GPIO_SET_CONLR(cm,val) ((cm)->CONLR = val)
#define CSP_GPIO_GET_CONLR(cm)     ((cm)->CONLR)

#define CSP_GPIO_SET_CONHR(cm,val) ((cm)->CONHR = val)
#define CSP_GPIO_GET_CONHR(cm)     ((cm)->CONHR)

#define CSP_GPIO_SET_WODR(cm,val) ((cm)->WODR = val)
#define CSP_GPIO_SET_SODR(cm,val) ((cm)->SODR = val)
#define CSP_GPIO_SET_CODR(cm,val) ((cm)->CODR = val)
#define CSP_GPIO_GET_PSDR(cm)     ((cm)->PSDR)

#define CSP_GPIO_SET_PUDR(cm,val) ((cm)->PUDR = val)
#define CSP_GPIO_GET_PUDR(cm)     ((cm)->PUDR)

#define CSP_GPIO_SET_DSCR(cm,val) ((cm)->DSCR = val)
#define CSP_GPIO_GET_DSCR(cm)     ((cm)->DSCR)

#define CSP_GPIO_SET_OMCR(cm,val) ((cm)->OMCR = val)
#define CSP_GPIO_GET_OMCR(cm)     ((cm)->OMCR)

#define CSP_GPIO_SET_IECR(cm,val) ((cm)->IECR = val)
#define CSP_GPIO_GET_IECR(cm)     ((cm)->IECR)

#define CSP_GPIO_SET_IGRP(cm,val) ((cm)->IGRP = val)
#define CSP_GPIO_GET_IGRP(cm)     ((cm)->IGRP)

/******************************************************************************
************************** Exported functions ************************
******************************************************************************/
extern void GPIOA0_DeInit(GPIO_Pin_TypeDef GPIO_Pin);
extern void GPIO_DeInit(void);
extern void GPIO_TTL_COSM_Selecte(CSP_GPIO_T *GPIOx,uint8_t bit,INPUT_MODE_SETECTED_TypeDef INPUT_MODE_SETECTED_X);
extern void GPIO_Init2(CSP_GPIO_T *GPIOx,GPIO_byte_TypeDef byte,uint32_t val);
extern void GPIO_InPutOutPut_Disable(CSP_GPIO_T *GPIOx,uint8_t PinNum);
extern void GPIO_Init(CSP_GPIO_T *GPIOx,uint8_t PinNum,GPIO_Dir_TypeDef Dir);
extern void GPIO_Write_Low(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_Write_High(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_MODE_Init(CSP_GPIO_T *GPIOx,GPIO_Mode_TypeDef IO_MODE,uint32_t val);
extern uint8_t GPIO_Read_Status(CSP_GPIO_T *GPIOx,uint8_t bit);
extern uint8_t GPIO_Read_Output(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_Reverse(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_Set_Value(CSP_GPIO_T *GPIOx,uint8_t bitposi,uint8_t bitval);
extern void GPIOA0_EXI_Init(GPIO_EXI_TypeDef EXI_IO);
extern void GPIOB0_EXI_Init(GPIO_EXI_TypeDef EXI_IO);
extern void GPIO_EXI_EN(CSP_GPIO_T *GPIOx,GPIO_EXI_TypeDef EXI_IO);
extern void GPIO_Debug_IO_12_13(void);
extern void GPIO_Debug_IO_01_02(void);
extern void GPIO_IntGroup_Set(GPIO_Group_TypeDef IO_MODE , uint8_t PinNum , GPIO_EXIPIN_TypeDef EXIPIN_x);
extern void GPIOA00_Set_ResetPin();
extern void GPIO_PullHigh_Init(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_PullLow_Init(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_PullHighLow_DIS(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_OpenDrain_EN(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_OpenDrain_DIS(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_DriveStrength_EN(CSP_GPIO_T *GPIOx,uint8_t bit);
extern void GPIO_DriveStrength_DIS(CSP_GPIO_T *GPIOx,uint8_t bit);
/*************************************************************/

#endif   /**< apt32f102_gpio_H */

/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/