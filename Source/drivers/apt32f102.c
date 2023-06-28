/*
  ******************************************************************************
  * @file    apt32f102.c
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

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


/**
  * @addtogroup Struct pointer assignment Functions
  * @{
  */
CSP_CK801_T   	*CK801 = (CSP_CK801_T   *)CK801_BASEADDR ;

CSP_IFC_T   	*IFC     = (CSP_IFC_T    *)APB_IFCBase ;
CSP_SYSCON_T 	*SYSCON = (CSP_SYSCON_T *)APB_SYSCONBase ;

CSP_TKEY_T  	*TKEY    = (CSP_TKEY_T  *)APB_TKEYBase ;
CSP_ADC12_T 	*ADC0    = (CSP_ADC12_T  *)APB_ADC0Base ;

CSP_GPIO_T  	*GPIOA0   = (CSP_GPIO_T  *)APB_GPIOA0Base ; // A0
CSP_GPIO_T  	*GPIOB0   = (CSP_GPIO_T  *)APB_GPIOB0Base ; // B0
CSP_IGRP_T  	*GPIOGRP  = (CSP_IGRP_T *)APB_IGRPBase;

CSP_UART_T  	*UART0    = (CSP_UART_T  *)APB_UART0Base ;
CSP_UART_T  	*UART1    = (CSP_UART_T  *)APB_UART1Base ;
CSP_UART_T  	*UART2    = (CSP_UART_T  *)APB_UART2Base ;
CSP_SSP_T   	*SPI0     = (CSP_SSP_T   *)APB_SPI0Base ;
CSP_I2C_T   	*I2C0     = (CSP_I2C_T   *)APB_I2C0Base ;
CSP_SIO_T   	*SIO0     = (CSP_SIO_T   *)APB_SIO0Base ;
CSP_CA_T    	*CA0      = (CSP_CA_T    *)APB_CNTABase ;

CSP_GPT_T		*GPT0	  =	(CSP_GPT_T *)APB_GPT0Base;
CSP_EPT_T   	*EPT0     = (CSP_EPT_T  *)APB_EPT0Base ;
CSP_ETCB_T  	*ETCB     = (CSP_ETCB_T *)APB_ETCBBase ;
CSP_RTC_T   	*RTC      = (CSP_RTC_T  *)APB_RTCBase ;
CSP_LPT_T   	*LPT      = (CSP_LPT_T  *)APB_LPTBase ;
CSP_WWDT_T   	*WWDT      = (CSP_WWDT_T  *)APB_WWDTBase ;
CSP_BT_T    	*BT0      = (CSP_BT_T   *)APB_BT0Base ;
CSP_BT_T    	*BT1      = (CSP_BT_T   *)APB_BT1Base ;
CSP_CRC_T   	*CRC      = (CSP_CRC_T  *)AHB_CRCBase ;
CSP_HWD_T   	*HWD      = (CSP_HWD_T  *)APB_HWDBase ;

int __divsi3 (  int a,   int b)
{   
	int PSR;
	__asm volatile(
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );

	HWD->CR = 0;
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
	__asm volatile(
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);
					
	return HWD->QUOTIENT;
}
 unsigned int __udivsi3 ( unsigned int a,  unsigned int b)
{   
	int PSR;
	__asm volatile(
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );
	
	HWD->CR = 1;
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
	__asm volatile(
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);

	return HWD->QUOTIENT;
}

int __modsi3 ( int a,  int b)
{   
	int PSR;
	__asm volatile(
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );
	
	HWD->CR = 0;
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
	__asm volatile(
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);	
	return HWD->REMAIN;
}

unsigned int __umodsi3 ( unsigned int a,  unsigned int b)
{   
	int PSR;
	__asm volatile(
					"mfcr %0 , psr \n\r"
					"psrclr ie \n\r"
					: "=r"(PSR)
				   );
	
	HWD->CR = 1;
	HWD->DIVIDENT = a;
	HWD->DIVISOR = b;

	PSR |= 0x80000000;
	__asm volatile(
					 "mtcr %0 , psr \n\r"
					 : 
					 :"r"(PSR)
					);	
	return HWD->REMAIN;
}

/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/