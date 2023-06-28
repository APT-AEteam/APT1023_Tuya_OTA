/*
  ******************************************************************************
  * @file    apt32f102_crc.h
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
#ifndef _apt32f102_crc_H
#define _apt32f102_crc_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"

#define CRC_RESET_VALUE  (0x00000000)
//--------------------------------------------------------------------------------
//-----------------------------CRC  value enum define--------------------------
//--------------------------------------------------------------------------------
/**
  * @brief  CRC COMPIN register
  */
typedef enum
{
    XORIN_DIS = 0,
	XORIN_EN = 1,
}CRC_COMPIN_TypeDef;
/**
  * @brief  CRC COMPOUT register
  */
typedef enum
{
    XOROUT_DIS = (0<<1),
	XOROUT_EN = (1<<1),
}CRC_COMPOUT_TypeDef;
/**
  * @brief  CRC ENDIANIN register
  */
typedef enum
{
    REFIN_DIS = (0<<2),
	REFIN_EN = (1<<2),
}CRC_ENDIANIN_TypeDef;
/**
  * @brief  CRC ENDIANOUT register
  */
typedef enum
{
    REFOUT_DIS = (0<<3),
	REFOUT_EN = (1<<3),
}CRC_ENDIANOUT_TypeDef;
/**
  * @brief  CRC poly register
  */
typedef enum
{
    POLY_CCITT = (0<<4),
	POLY_16 = (2<<4),
	POLY_32 = (3<<4),
}CRC_POLY_TypeDef;


extern void CRC_CMD(FunctionalStatus NewState);
extern void CRC_Soft_Reset(void);
extern void CRC_Configure(CRC_COMPIN_TypeDef COMPINX,CRC_COMPOUT_TypeDef COMPOUTX,CRC_ENDIANIN_TypeDef ENDIANINX,
				   CRC_ENDIANOUT_TypeDef ENDIANOUT,CRC_POLY_TypeDef POLYX);
extern void CRC_Seed_Write(U32_T seed_data);
extern U32_T CRC_Seed_Read(void);
extern void CRC_Datain(U32_T data_in);
extern U32_T CRC_Result_Read(void);
extern U32_T Chip_CRC_CRC32(U32_T *data, U32_T words);
/*************************************************************/

#endif   /**< apt32f102_crc_H */

/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/