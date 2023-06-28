/*
  ******************************************************************************
  * @file    apt32f102_lpt.c
  * @author  APT AE Team
  * @version V1.24
  * @date    2018/10/15
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
#include "apt32f102_crc.h"

/*************************************************************/
// CRC enable/disable
//EntryParameter:ENABLE/DISABLE
//ReturnValue:NONE
/*************************************************************/ 
void CRC_CMD(FunctionalStatus NewState)
{
	if (NewState != DISABLE)
	{
		CRC->CEDR  =0X01;						//SET
	}
	else
	{
		CRC->CEDR  =0X00;						//CLR
	}
}

/*************************************************************/
//CRC RESET
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void CRC_Soft_Reset(void)
{
	CRC->SRR = 0X01;
}

/*************************************************************/
//CRC CONTROL
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void CRC_Configure(CRC_COMPIN_TypeDef COMPINX,CRC_COMPOUT_TypeDef COMPOUTX,CRC_ENDIANIN_TypeDef ENDIANINX,
				   CRC_ENDIANOUT_TypeDef ENDIANOUT,CRC_POLY_TypeDef POLYX)
{
	CRC->CR |= COMPINX |COMPOUTX |ENDIANINX |ENDIANOUT| POLYX;
}

/*************************************************************/
//CRC seed write
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void CRC_Seed_Write(U32_T seed_data)
{
	CRC->SEED = seed_data;
}

/*************************************************************/
//CRC seed read
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
U32_T CRC_Seed_Read(void)
{
	return CRC->SEED;
}

/*************************************************************/
//CRC datain
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
void CRC_Datain(U32_T data_in)
{
	CRC->DATAIN=data_in;
}

/*************************************************************/
//CRC Result read
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
U32_T CRC_Result_Read(void)
{
	return CRC->DATAOUT;
}
/*************************************************************/
//CRC calc 32bit input
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/ 
U32_T Chip_CRC_CRC32(U32_T *data, U32_T words)
{
	while (words > 0) {
		CRC_Datain(*data);
		data++;
		words--;
	}
	return CRC_Result_Read();
}