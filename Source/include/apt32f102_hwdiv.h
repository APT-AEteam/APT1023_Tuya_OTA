/*
  ******************************************************************************
  * @file    apt32f102_hwdiv.h
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
#ifndef _apt32f102_hwdiv_H
#define _apt32f102_hwdiv_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


#define HWDIV_RESET_VALUE  (0x00000000)
//--------------------------------------------------------------------------------
//-----------------------------HWDIV  value enum define--------------------------
//--------------------------------------------------------------------------------
#define HWDIV_UNSIGN_BIT (0X01<<0)

extern U32_T HWDIV_Calc_Remain(void);
extern U32_T HWDIV_Calc_Quotient(void);
extern void HWDIV_Calc_UNSIGN(U32_T DIVIDENDx,U32_T DIVISOR_x);
extern void HWDIV_UNSIGN_CMD(FunctionalStatus NewState);
extern void HWDIV_DeInit(void);
extern void HWDIV_Calc_SIGN(long DIVIDENDx,long DIVISOR_x);
extern void HWDIV_Calc_float(float DIVIDENDx,float DIVISOR_x);










#endif   /**< apt32f102_hwdiv_H */

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/