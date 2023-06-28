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

/* Includes ------------------------------------------------------------------*/
#include "apt32f102_gpio.h"

/* define --------------------------------------------------------------------*/

/* externs--------------------------------------------------------------------*/
/*************************************************************/
//IO RESET CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void GPIO_DeInit(void)
{
    GPIOA0->CONLR = GPIO_RESET_VALUE;                     
    GPIOA0->CONHR = GPIO_RESET_VALUE;
    GPIOB0->CONLR = GPIO_RESET_VALUE;                     
    GPIOB0->CONHR = GPIO_RESET_VALUE;
    GPIOA0->WODR  = GPIO_RESET_VALUE; 
    GPIOB0->WODR  = GPIO_RESET_VALUE;
    GPIOA0->SODR  = GPIO_RESET_VALUE; 
    GPIOB0->SODR  = GPIO_RESET_VALUE;
    GPIOA0->CODR  = GPIO_RESET_VALUE; 
    GPIOB0->CODR  = GPIO_RESET_VALUE;
	GPIOA0->ODSR  =	GPIO_RESET_VALUE;
	GPIOB0->ODSR  =	GPIO_RESET_VALUE;
	GPIOA0->PSDR  =	GPIO_RESET_VALUE;
	GPIOB0->PSDR  =	GPIO_RESET_VALUE;
	GPIOA0->FLTEN = 0xffff;
	GPIOB0->FLTEN = 0x3f;
    GPIOA0->PUDR  = GPIO_RESET_VALUE; 
    GPIOB0->PUDR  = GPIO_RESET_VALUE;
    GPIOA0->DSCR  = GPIO_RESET_VALUE;
    GPIOB0->DSCR  = GPIO_RESET_VALUE;
	GPIOA0->OMCR  = GPIO_RESET_VALUE;
    GPIOB0->OMCR  = GPIO_RESET_VALUE;
    GPIOA0->IECR  = GPIO_RESET_VALUE;
    GPIOB0->IECR  = GPIO_RESET_VALUE;
    GPIOGRP->IGRPL  = GPIO_RESET_VALUE;
	GPIOGRP->IGRPH  = GPIO_RESET_VALUE;
	GPIOGRP->IGREX  = GPIO_RESET_VALUE;
	GPIOGRP->IO_CLKEN = 0xf;
}  
/*************************************************************/
//IO OUTPUT INPUT SET 2
//EntryParameter:GPIOx,byte,val
//GPIOx:GPIOA0,GPIOB0
//byte:Lowbyte(PIN_0~7),Highbyte(PIN_8~15)
//val:0x0000000~0xFFFFFFFF
//val=0x11111111 all IO as input
//val=0x22222222 all IO as output
//ReturnValue:NONE
/*************************************************************/  
void GPIO_Init2(CSP_GPIO_T *GPIOx,GPIO_byte_TypeDef byte,uint32_t val)
{
    if (byte==0)
    {
        (GPIOx)->CONLR=val;
    }
    else if(byte==1)
    {
        (GPIOx)->CONHR=val;
    }
}
/*************************************************************/
//IO OUTPUT INPUT SET 1
//EntryParameter:GPIOx,GPIO_Pin(0~15),byte,Dir
//GPIOx:GPIOA0,GPIOB0
//GPIO_Pin:PIN_0~15
//byte:Lowbyte(PIN_0~7),Highbyte(PIN_8~15)
//Dir:0:output 1:input
//ReturnValue:NONE
/*************************************************************/  
void GPIO_Init(CSP_GPIO_T *GPIOx,uint8_t PinNum,GPIO_Dir_TypeDef Dir)
{
    uint32_t data_temp = 0;
    uint8_t GPIO_Pin = 0;
    if(PinNum<8)
    {
    switch (PinNum)
    {
        case 0:data_temp=0xfffffff0;GPIO_Pin=0;break;
        case 1:data_temp=0xffffff0f;GPIO_Pin=4;break;
        case 2:data_temp=0xfffff0ff;GPIO_Pin=8;break;
        case 3:data_temp=0xffff0fff;GPIO_Pin=12;break;
        case 4:data_temp=0xfff0ffff;GPIO_Pin=16;break;
        case 5:data_temp=0xff0fffff;GPIO_Pin=20;break;
        case 6:data_temp=0xf0ffffff;GPIO_Pin=24;break;
        case 7:data_temp=0x0fffffff;GPIO_Pin=28;break;
    }
        if (Dir)
        {
          (GPIOx)->CONLR =((GPIOx)->CONLR & data_temp) | 1<<GPIO_Pin;
        }
        else
        {
         (GPIOx)->CONLR = ((GPIOx)->CONLR & data_temp) | 2<<GPIO_Pin; 
        }
    }
    else if (PinNum<16)
    {
        switch (PinNum)
    {
        case 8:data_temp=0xfffffff0;GPIO_Pin=0;break;
        case 9:data_temp=0xffffff0f;GPIO_Pin=4;break;
        case 10:data_temp=0xfffff0ff;GPIO_Pin=8;break;
        case 11:data_temp=0xffff0fff;GPIO_Pin=12;break;
        case 12:data_temp=0xfff0ffff;GPIO_Pin=16;break;
        case 13:data_temp=0xff0fffff;GPIO_Pin=20;break;
        case 14:data_temp=0xf0ffffff;GPIO_Pin=24;break;
        case 15:data_temp=0x0fffffff;GPIO_Pin=28;break;
    } 
      if (Dir)
        {
        (GPIOx)->CONHR = ((GPIOx)->CONHR & data_temp) | 1<<GPIO_Pin;  
        }
        else
        {
         (GPIOx)->CONHR = ((GPIOx)->CONHR & data_temp) | 2<<GPIO_Pin;    
        }
    }
}
/*************************************************************/
//IO OUTPUT INPUT Disable
//EntryParameter:GPIOx,GPIO_Pin(0~15)
//GPIOx:GPIOA0,GPIOB0
//GPIO_Pin:PIN_0~15
//byte:Lowbyte(PIN_0~7),Highbyte(PIN_8~15)
//ReturnValue:NONE
/*************************************************************/  
void GPIO_InPutOutPut_Disable(CSP_GPIO_T *GPIOx,uint8_t PinNum)
{
    uint32_t data_temp = 0;
    if(PinNum<8)
    {
    switch (PinNum)
    {
        case 0:data_temp=0xfffffff0;break;
        case 1:data_temp=0xffffff0f;break;
        case 2:data_temp=0xfffff0ff;break;
        case 3:data_temp=0xffff0fff;break;
        case 4:data_temp=0xfff0ffff;break;
        case 5:data_temp=0xff0fffff;break;
        case 6:data_temp=0xf0ffffff;break;
        case 7:data_temp=0x0fffffff;break;
    }
         (GPIOx)->CONLR = (GPIOx)->CONLR & data_temp;
    }
    else if (PinNum<16)
    {
        switch (PinNum)
    {
        case 8:data_temp=0xfffffff0;break;
        case 9:data_temp=0xffffff0f;break;
        case 10:data_temp=0xfffff0ff;break;
        case 11:data_temp=0xffff0fff;break;
        case 12:data_temp=0xfff0ffff;break;
        case 13:data_temp=0xff0fffff;break;
        case 14:data_temp=0xf0ffffff;break;
        case 15:data_temp=0x0fffffff;break;
    } 
         (GPIOx)->CONHR = (GPIOx)->CONHR & data_temp;    
    }
}
/*************************************************************/
//IO OUTPUT INPUT SET
//EntryParameter:IO_MODE,GPIOx,val
//GPIOx:GPIOA0,GPIOB0
//IO_MODE:PUDR(IO PULL HIGH/LOW)
//IO_MODE:DSCR(IO DRIVE STRENGHT)
//IO_MODE:OMCR(OUTPUT MODE SET)
//IO_MODE:IECR(IO INT ENABLE)
//ReturnValue:NONE
/*************************************************************/  
void GPIO_MODE_Init(CSP_GPIO_T *GPIOx,GPIO_Mode_TypeDef IO_MODE,uint32_t val)
{
        switch (IO_MODE)
        {
            case PUDR:(GPIOx)->PUDR  = val;break;               
            case DSCR:(GPIOx)->DSCR  = val;break;
            case OMCR:(GPIOx)->OMCR  = val;break;
            case IECR:(GPIOx)->IECR  = val;break;
        }
}
/*************************************************************/
//Write GPIO pull high/low
//EntryParameter:GPIOx,uint8_t bit
//GPIOx:GPIOA0,GPIOB0
//bit:0~15
//ReturnValue:VALUE
/*************************************************************/
void GPIO_PullHigh_Init(CSP_GPIO_T *GPIOx,uint8_t bit)
{
	(GPIOx)->PUDR  = (((GPIOx)->PUDR) & ~(0x03<<(bit*2))) | (0x01<<(bit*2));
}
void GPIO_PullLow_Init(CSP_GPIO_T *GPIOx,uint8_t bit)
{
	(GPIOx)->PUDR  = (((GPIOx)->PUDR) & ~(0x03<<(bit*2))) | (0x02<<(bit*2));
}
void GPIO_PullHighLow_DIS(CSP_GPIO_T *GPIOx,uint8_t bit)
{
	(GPIOx)->PUDR  = ((GPIOx)->PUDR) & ~(0x03<<(bit*2));
}
/*************************************************************/
//Write GPIO open drain init
//EntryParameter:GPIOx,uint8_t bit
//GPIOx:GPIOA0,GPIOB0
//bit:0~15
//ReturnValue:VALUE
/*************************************************************/
void GPIO_OpenDrain_EN(CSP_GPIO_T *GPIOx,uint8_t bit)
{
	(GPIOx)->OMCR  = ((GPIOx)->OMCR) | (0x01<<bit);
}
void GPIO_OpenDrain_DIS(CSP_GPIO_T *GPIOx,uint8_t bit)
{
	(GPIOx)->OMCR  = ((GPIOx)->OMCR) & ~(0x01<<bit);
}
/*************************************************************/
//Write GPIO open drain init
//EntryParameter:GPIOx,uint8_t bit,INPUT_MODE_SETECTED_X
//GPIOx:GPIOA0,GPIOB0
//bit:0~15
//INPUT_MODE_SETECTED_X:INPUT_MODE_TTL1,INPUT_MODE_SETECTED_TTL2,INPUT_MODE_SETECTED_CMOSS
//ReturnValue:VALUE
/*************************************************************/
//默认cmos口
void GPIO_TTL_COSM_Selecte(CSP_GPIO_T *GPIOx,uint8_t bit,INPUT_MODE_SETECTED_TypeDef INPUT_MODE_SETECTED_X)
{
	if(INPUT_MODE_SETECTED_X==INPUT_MODE_SETECTED_CMOS)
	{
		(GPIOx)->DSCR  = ((GPIOx)->DSCR) & ~(0x01<<(bit*2+1));
	}
	else
	{
		(GPIOx)->DSCR  = ((GPIOx)->DSCR) | (0x01<<(bit*2+1));
		if(INPUT_MODE_SETECTED_X==INPUT_MODE_SETECTED_TTL1)
		{
			(GPIOx)->OMCR  = ((GPIOx)->OMCR) | (0x01<<(bit+16));
		}
		else if(INPUT_MODE_SETECTED_X==INPUT_MODE_SETECTED_TTL2)
		{
			(GPIOx)->OMCR  = ((GPIOx)->OMCR) & ~(0x01<<(bit+16));
		}
	}
}
/*************************************************************/
//Write GPIO Drive Strength init
//EntryParameter:GPIOx,uint8_t bit
//GPIOx:GPIOA0,GPIOB0
//bit:0~15
//ReturnValue:VALUE
/*************************************************************/
void GPIO_DriveStrength_EN(CSP_GPIO_T *GPIOx,uint8_t bit)
{
	(GPIOx)->DSCR  = ((GPIOx)->DSCR) | (0x01<<(bit*2));
}
void GPIO_DriveStrength_DIS(CSP_GPIO_T *GPIOx,uint8_t bit)
{
	(GPIOx)->DSCR  = ((GPIOx)->DSCR) & ~(0x01<<(bit*2));
}
/*************************************************************/
//IO OUTPUT INPUT SET
//EntryParameter:
//IO_MODE:IGRP(IO INT GROUP)
//PinNumï¼0~15
//SYSCON_EXIPIN_TypeDef:EXI_PIN0~EXI_PIN19
//EXI0~EXI15:GPIOA0,GPIOB0
//EXI16~EXI17:GPIOA0.0~GPIOA0.7
//EXI18~EXI19:GPIOB0.0~GPIOB0.3
//ReturnValue:NONE
/*************************************************************/  
void GPIO_IntGroup_Set(GPIO_Group_TypeDef IO_MODE , uint8_t PinNum , GPIO_EXIPIN_TypeDef Selete_EXI_x)
{
	volatile unsigned int  R_data_temp;
    volatile unsigned char R_GPIO_Pin;
	if(Selete_EXI_x<16)
	{
		if((Selete_EXI_x==0)||(Selete_EXI_x==8))
		{
			R_data_temp=0xfffffff0;
			R_GPIO_Pin=0;
		}
		else if((Selete_EXI_x==1)||(Selete_EXI_x==9))
		{
			R_data_temp=0xffffff0f;
			R_GPIO_Pin=4;
		}
		else if((Selete_EXI_x==2)||(Selete_EXI_x==10))
		{
			R_data_temp=0xfffff0ff;
			R_GPIO_Pin=8;
		}
		else if((Selete_EXI_x==3)||(Selete_EXI_x==11))
		{
			R_data_temp=0xffff0fff;
			R_GPIO_Pin=12;
		}
		else if((Selete_EXI_x==4)||(Selete_EXI_x==12))
		{
			R_data_temp=0xfff0ffff;
			R_GPIO_Pin=16;
		}
		else if((Selete_EXI_x==5)||(Selete_EXI_x==13))
		{
			R_data_temp=0xff0fffff;
			R_GPIO_Pin=20;
		}
		else if((Selete_EXI_x==6)||(Selete_EXI_x==14))
		{
			R_data_temp=0xf0ffffff;
			R_GPIO_Pin=24;
		}
		else if((Selete_EXI_x==7)||(Selete_EXI_x==15))
		{
			R_data_temp=0x0fffffff;
			R_GPIO_Pin=28;
		}
		if(Selete_EXI_x<8)
		{
			GPIOGRP->IGRPL =(GPIOGRP->IGRPL & R_data_temp) | (IO_MODE<<R_GPIO_Pin);
		}
		else if((Selete_EXI_x<16)&&(Selete_EXI_x>=8))
		{
			GPIOGRP->IGRPH =(GPIOGRP->IGRPH & R_data_temp) | (IO_MODE<<R_GPIO_Pin);    
		}
	}
	else if(Selete_EXI_x<20)
	{
		if((IO_MODE==0)&&((Selete_EXI_x==16)||((Selete_EXI_x==17))))						//PA0.0~PA0.7
		{
			if(Selete_EXI_x==16)
			{
				GPIOGRP->IGREX =(GPIOGRP->IGREX)|PinNum;
			}
			else if(Selete_EXI_x==17)
			{
				GPIOGRP->IGREX=(GPIOGRP->IGREX)|(PinNum<<4);
			}
		}
		else if((IO_MODE==1)&&((Selete_EXI_x==18)||(Selete_EXI_x==19)))					//PB0.0~PB0.3
		{
			if(Selete_EXI_x==18)
			{
				GPIOGRP->IGREX=(GPIOGRP->IGREX)|(PinNum<<8);
			}
			else if(Selete_EXI_x==19)
			{
				GPIOGRP->IGREX=(GPIOGRP->IGREX)|(PinNum<<12);
			}
		}
	}
}
/*************************************************************/
//IO EXI SET 
//EntryParameter:EXI_IO(EXI0~EXI13)
//ReturnValue:NONE
/*************************************************************/  
void GPIOA0_EXI_Init(GPIO_EXI_TypeDef EXI_IO)
{
    switch (EXI_IO)
    {
        case 0:GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFFF0) | 0X00000001;break;
        case 1:GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFFF0F) | 0X00000010;break;
        case 2:GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF) | 0X00000100;break;
        case 3:GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFF0FFF) | 0X00001000;break;
        case 4:GPIOA0->CONLR = (GPIOA0->CONLR&0XFFF0FFFF) | 0X00010000;break;
        case 5:GPIOA0->CONLR = (GPIOA0->CONLR&0XFF0FFFFF) | 0X00100000;break;
        case 6:GPIOA0->CONLR = (GPIOA0->CONLR&0XF0FFFFFF) | 0X01000000;break;
        case 7:GPIOA0->CONLR = (GPIOA0->CONLR&0X0FFFFFFF) | 0X10000000;break;
        case 8:GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFFF0) | 0X00000001;break;
        case 9:GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFFF0F) | 0X00000010;break;
        case 10:GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFFF0FF) | 0X00000100;break;
        case 11:GPIOA0->CONHR = (GPIOA0->CONHR&0XFFFF0FFF) | 0X00001000;break;
        case 12:GPIOA0->CONHR = (GPIOA0->CONHR&0XFFF0FFFF) | 0X00010000;break;
        case 13:GPIOA0->CONHR = (GPIOA0->CONHR&0XFF0FFFFF) | 0X00100000;break;
		case 14:GPIOA0->CONHR = (GPIOA0->CONHR&0XF0FFFFFF) | 0X01000000;break;
		case 15:GPIOA0->CONHR = (GPIOA0->CONHR&0X0FFFFFFF) | 0X10000000;break;
    }
}
void GPIOB0_EXI_Init(GPIO_EXI_TypeDef EXI_IO)
{
    switch (EXI_IO)
    {
        case 0:GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFFF0) | 0X00000001;break;
        case 1:GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFFF0F) | 0X00000010;break;
        case 2:GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFFF0FF) | 0X00000100;break;
        case 3:GPIOB0->CONLR = (GPIOB0->CONLR&0XFFFF0FFF) | 0X00001000;break;
		case 4:GPIOB0->CONLR = (GPIOB0->CONLR&0XFFF0FFFF) | 0X00010000;break;
		case 5:GPIOB0->CONLR = (GPIOB0->CONLR&0XFF0FFFFF) | 0X00100000;break;
        default:break;
    }
}
void GPIO_EXI_EN(CSP_GPIO_T *GPIOx,GPIO_EXI_TypeDef EXI_IO)
{
    (GPIOx)->IECR  |= 1<<EXI_IO;
}
/*************************************************************/
//Write GPIO 
//EntryParameter:GPIOx,uint8_t bit
//GPIOx:GPIOA0,GPIOB0
//bit:0~15
//ReturnValue:VALUE
/*************************************************************/
void GPIO_Write_High(CSP_GPIO_T *GPIOx,uint8_t bit)
{
        (GPIOx)->SODR = (1ul<<bit);
}
void GPIO_Write_Low(CSP_GPIO_T *GPIOx,uint8_t bit)
{
        (GPIOx)->CODR = (1ul<<bit);
}
/*************************************************************/
//Write GPIO 
//EntryParameter:GPIOx,uint8_t bitposi bitval
//GPIOx:GPIOA0,GPIOB0
//bitposi:0~15 bitval:0~1 0=low 1=high
//ReturnValue:VALUE
/*************************************************************/
void GPIO_Set_Value(CSP_GPIO_T *GPIOx,uint8_t bitposi,uint8_t bitval)
{
    if (bitval==1)
    {
        (GPIOx)->SODR = (1ul<<bitposi);
    }
    else if ((bitval==0))
    {
        (GPIOx)->CODR = (1ul<<bitposi);
    }
}
/*************************************************************/
//Write GPIO reverse
//EntryParameter:GPIOx,uint8_t bit
//GPIOx:GPIOA0,GPIOB0
//bit:0~15
//ReturnValue:VALUE
/*************************************************************/
void GPIO_Reverse(CSP_GPIO_T *GPIOx,uint8_t bit)
{
     uint32_t dat = 0;
     dat=((GPIOx)->ODSR>>bit)&1ul;
     {
       if (dat==1)  
       {
           (GPIOx)->CODR = (1ul<<bit);
           return;
       }
       if (dat==0)
       {
           (GPIOx)->SODR = (1ul<<bit);
           return;
       }
     }
}
/*************************************************************/
//READ PA IO STATUS
//EntryParameter:GPIOx,uint8_t bit
//GPIOx:GPIOA0,GPIOB0
//bit:0~15
//ReturnValue:VALUE
/*************************************************************/
uint8_t GPIO_Read_Status(CSP_GPIO_T *GPIOx,uint8_t bit)
{
    uint8_t value = 0;
    uint32_t dat = 0;
    dat=((GPIOx)->PSDR)&(1<<bit);
    if (dat == (1<<bit))								
	{
	    value = 1;
	} 
    return value;
}
/*************************************************************/
//READ PA OUTPUT STATUS
//EntryParameter:GPIOx,uint8_t bit
//GPIOx:GPIOA0,GPIOB0
//bit:0~15
//ReturnValue:VALUE
/*************************************************************/
uint8_t GPIO_Read_Output(CSP_GPIO_T *GPIOx,uint8_t bit)
{
    uint8_t value = 0;
    uint32_t dat = 0;
    dat=((GPIOx)->ODSR)&(1<<bit);
    if (dat == (1<<bit))								
	{
	    value = 1;
	} 
    return value;
}

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/