/*
  ******************************************************************************
  * @file    apt32f102_CORET.h
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
#ifndef _apt32f102_CORET_H
#define _apt32f102_CORET_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"

/******************************************************************************
************************* syscon Registers Definition *************************
******************************************************************************/
#define CORET_CSR_RST     	((CSP_REGISTER_T)0x00000004)
#define CORET_RVR_RST     	((CSP_REGISTER_T)0x00000000)
#define CORET_CVR_RST     	((CSP_REGISTER_T)0x00000000)
#define CORET_CALIB_RST     ((CSP_REGISTER_T)0x00000000)




extern void CORET_DeInit(void);
extern void CORET_Int_Enable(void);
extern void CORET_Int_Disable(void);
extern void CORET_WakeUp_Enable(void);
extern void CORET_WakeUp_Disable(void);
extern void CORET_start(void);
extern void CORET_stop(void);
extern void CORET_CLKSOURCE_EX(void);
extern void CORET_CLKSOURCE_IN(void);
extern void CORET_TICKINT_Enable(void);
extern void CORET_TICKINT_Disable(void);
extern void CORET_reload(void);

#endif   /**< apt32f102_coret_H */

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/