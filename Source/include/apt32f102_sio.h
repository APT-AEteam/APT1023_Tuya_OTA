/*
  ******************************************************************************
  * @file    apt32f102_sio.h
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
#ifndef _apt32f102_sio_H
#define _apt32f102_sio_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"


#define SIO_RESET_VALUE  (0x00000000)


//--------------------------------------------------------------------------------
//-----------------------------SIO  value enum define--------------------------
//--------------------------------------------------------------------------------
/**
  * @brief  SIO IO group register
  */
typedef enum
{
    SIO_PA02  = 0,
	SIO_PA03  = 1,
	SIO_PA012 = 2,
	SIO_PB01  = 3,
}SIO_IOG_TypeDef;
/**
  * @brief  SIO CLK EN register
  */
typedef enum
{
    SIOCLK_DIS = 0,
	SIOCLK_EN = 1,
}SIO_CLK_TypeDef;
/**
  * @brief  SIO TXDEB register
  */
typedef enum
{
    SIO_TXDEB_1CYCLE = (0<<1),
	SIO_TXDEB_2CYCLE = (1<<1),
	SIO_TXDEB_3CYCLE = (2<<1),
	SIO_TXDEB_4CYCLE = (3<<1),
	SIO_TXDEB_5CYCLE = (4<<1),
	SIO_TXDEB_6CYCLE = (5<<1),
	SIO_TXDEB_7CYCLE = (6<<1),
	SIO_TXDEB_8CYCLE = (7<<1),
}SIO_RXDEB_TypeDef;
/**
  * @brief  SIO IO IDLE STATUS register
  */
typedef enum
{
    SIO_IDLE_Z = 0,
	SIO_IDLE_HIGH = 1,
	SIO_IDLE_LOW = 2,
}SIO_IDLEST_TypeDef;
/**
  * @brief  SIO TX DIR register
  */
typedef enum
{
    SIO_TX_LSB = (0<<2),
	SIO_TX_MSB = (1<<2),
}SIO_TXDIR_TypeDef;
/**
  * @brief  SIO LENOBH register
  */
typedef enum
{
    SIO_OBH_1BIT = (0<<8),
	SIO_OBH_2BIT = (1<<8),
	SIO_OBH_3BIT = (2<<8),
	SIO_OBH_4BIT = (3<<8),
	SIO_OBH_5BIT = (4<<8),
	SIO_OBH_6BIT = (5<<8),
	SIO_OBH_7BIT = (6<<8),
	SIO_OBH_8BIT = (7<<8),
}SIO_LENOBH_TypeDef;
/**
  * @brief  SIO LENOBL register
  */
typedef enum
{
    SIO_OBL_1BIT = (0<<11),
	SIO_OBL_2BIT = (1<<11),
	SIO_OBL_3BIT = (2<<11),
	SIO_OBL_4BIT = (3<<11),
	SIO_OBL_5BIT = (4<<11),
	SIO_OBL_6BIT = (5<<11),
	SIO_OBL_7BIT = (6<<11),
	SIO_OBL_8BIT = (7<<11),
}SIO_LENOBL_TypeDef;
/**
  * @brief  SIO RX EDGE register
  */
typedef enum
{
    SIO_RX_RISE = 0,
	SIO_RX_FALL = 1,
	SIO_RX_RISE_FALL = 2,
}SIO_BSTSEL_TypeDef;
/**
  * @brief  SIO RX TRG MODE register
  */
typedef enum
{
    SIO_RX_DEB = (0<<3),
	SIO_RX_FLT30NS = (1<<3),
}SIO_TRGMODE_TypeDef;
/**
  * @brief  SIO RX ALIGNEN register
  */
typedef enum
{
    SIO_RX_ALIGNDIS = (0<<28),
	SIO_RX_ALIGNEN = (1<<28),
}SIO_ALIGNEN_TypeDef;
/**
  * @brief  SIO RX DIR register
  */
typedef enum
{
    SIO_RX_MSB = (0<<29),
	SIO_RX_LSB = (1<<29),
}SIO_RXDIR_TypeDef;
/**
  * @brief  SIO RX MODE register
  */
typedef enum
{
    SIO_RMODE0 = (0<<30),
	SIO_RMODE1 = (1<<30),
}SIO_RXMODE_TypeDef;
/**
  * @brief  SIO BREAKEN register
  */
typedef enum
{
    SIO_BREAKDIS = (0<<0),
	SIO_BREAKEN = (1<<0),
}SIO_BREAKEN_TypeDef;
/**
  * @brief  SIO BREAKLVL register
  */
typedef enum
{
    SIO_BREAKLVL_LOW = (0<<1),
	SIO_BREAKLVL_HIGH = (1<<1),
}SIO_BREAKLVL_TypeDef;
/**
  * @brief  SIO TORSTEN register
  */
typedef enum
{
    SIO_TORSTDIS = (0<<15),
	SIO_TORSTEN = (1<<15),
}SIO_TORSTEN_TypeDef;
/**
  * @brief  LPT INT MASK SET/CLR  Set
  */
typedef enum
{
	SIO_TXDNE     	=	(0x01 << 0),  
	SIO_RXDNE    	=	(0x01 << 1),      
	SIO_TXBUFEMPT   =	(0x01 << 2), 
	SIO_RXBUFEMPT	=	(0x01 << 3), 
	SIO_BREAK		=	(0x01 << 4), 
	SIO_TIME		=	(0x01 << 5), 
}SIO_IMSCR_TypeDef;  



#define TX_D0 (0X00)
#define TX_D1 (0X01)
#define TX_DL (0X02)
#define TX_DH (0X03)


extern void SIO_DeInit(void);
extern void SIO_IO_Init(SIO_IOG_TypeDef IOGx);
extern void SIO_TX_Init(SIO_CLK_TypeDef CLKX,U8_T TCKPRSX);
extern void SIO_TX_Configure(SIO_IDLEST_TypeDef IDLEX,SIO_TXDIR_TypeDef TXDIRX,U8_T TXBUFLENX,U8_T TXCNTX,U8_T D0DURX,U8_T D1DURX,SIO_LENOBH_TypeDef LENOBHX,
					SIO_LENOBL_TypeDef LENOBLX,U8_T HSQX,U8_T LSQX);
extern void SIO_TXBUF_Set(U8_T D30,U8_T D28,U8_T D26,U8_T D24,U8_T D22,U8_T D20,U8_T D18,U8_T D16,
					U8_T D14,U8_T D12,U8_T D10,U8_T D08,U8_T D06,U8_T D04,U8_T D02,U8_T D00);
extern void SIO_RX_Init(SIO_CLK_TypeDef CLKX,SIO_RXDEB_TypeDef RXDEBX,U8_T DEBCKSX);
extern void SIO_RX_Configure0(SIO_BSTSEL_TypeDef BSTSELX,SIO_TRGMODE_TypeDef TRGMX,U8_T SPLCNTX,U8_T EXTRACTX,U8_T HITHRX,
					SIO_ALIGNEN_TypeDef ALIGNX,SIO_RXDIR_TypeDef RXDIRX,SIO_RXMODE_TypeDef RXMODEX,U8_T RXLENX,U8_T RXBUFLENX,U8_T RXKPRSX);
extern void SIO_RX_Configure1(SIO_BREAKEN_TypeDef BREAKX,SIO_BREAKLVL_TypeDef BREAKLVLX,U8_T BREKCNTX,SIO_TORSTEN_TypeDef TORSTX,U8_T TOCNTX);
extern void SIO_ConfigInterrupt_CMD(FunctionalStatus NewState,SIO_IMSCR_TypeDef SIO_IMSCR_X);
extern void SIO_INT_ENABLE(void);
extern void SIO_INT_DISABLE(void);
/*************************************************************/

#endif   /**< apt32f102_sio_H */