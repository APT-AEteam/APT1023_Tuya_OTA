/*
  ******************************************************************************
  * @file    main.c
  * @author  APT AE Team
  * @version V0.50
  * @date    2020/11
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

#include "apt32f102.h"
#include "apt32f102_syscon.h"
#include "apt32f102_coret.h"
#include "apt32f102_bt.h"
#include "apt32f102_gpio.h"
#include "apt32f102_crc.h"
#include "apt32f102_wwdt.h"
#include "apt32f102_lpt.h"
#include "apt32f102_countera.h"
#include "apt32f102_bt.h"
#include "apt32f102_hwdiv.h"
#include "apt32f102_sio.h"
#include "apt32f102_uart.h"
#include "apt32f102_i2c.h"
#include "apt32f102_spi.h"
#include "apt32f102_rtc.h"
#include "apt32f102_ept.h"
#include "apt32f102_gpt.h"
#include "apt32f102_et.h"
#include "apt32f102_adc.h"
#include "apt32f102_ifc.h"
#include "apt32f102_types_local.h"
#include "delay.h"
#include "iostring.h"
#include "define.h"
#include<stdbool.h>


extern void APT32F102_init(void);	
extern void BT_CONFIG(void);	
extern void IFC_CONFIG(void);


void	IoInit(void)
{
	 PwrKeyDir;
	 UpKeyDir;
	 DownKeyDir;
 #ifdef FOR_DEBUG
     UART1_CONFIG();
 #else
	 WiFiKeyDir;
 #endif
	 TmrKeyDir;
	 BLedDir;
	 HotDir;
	 RfInDir;
}



void	Wait(U8_T	i)
{
	SysTime=0;
	do
	{
		feed_IWDT();//喂狗//CLRWDT=1;//清看门狗
	}
	while(SysTime<i);
	
}

void jump_app(void)
{
	volatile U32_T EIPaddr = APP_EIP_ADDR;
	asm("mov r0,%0\n"::"r"(EIPaddr):);
//	asm(" lrw r0,0x2104 ");  // APP入口地址 __start label的值
	asm(" jmp r0 ");
}

void rst_mcu(void)
{
	SYSCON -> RSR = 0xFFFFFFFF;
	SYSCON -> IDCCR = 0xE11E0081; //系统软复位
 }
 
 
 void feed_IWDT(void)
 {
	SYSCON -> IWDCNT = 0x5A000000;
}

void enable_IWDT(void)
{
	SYSCON ->IMER = 0x100; // enable IWDT_INT
	SYSCON -> IWDCR = 0x87780000 | (0x7<<8) | (0x6<<2);
	SYSCON -> IWDCNT = 0x5A000000;
	SYSCON -> IWDEDR = 0x78870000;
}


/***************************************************************************************************
	RamInit
***************************************************************************************************/
void Ram_Init(void)
{
	U16_T i;
	for(i = 0; i < sizeof(Rx_Buf); i ++)
	{
		Rx_Buf[i]=0;
	}
	feed_IWDT();//喂狗CLRWDT=1;//清看门狗
	
	for(i = 0; i <sizeof(Tx_Buf); i ++)
	{
		Tx_Buf[i]=0;
	}
	Set_Temp_Buf=37;
	Wifi_State=2;
}

void clock_init(void)
{
	GPIOA0 -> CONLR = 0x88000200;
	GPIOA0->CONLR = (GPIOA0->CONLR&0XFFFFF0FF) | 0X00000700;
	SYSCON -> OPT1 = 0x4800;
	SYSCON -> IWDEDR = 0x78870000 | 0x5555; 		// disable watch dog
}


int main(void)
{
	Hot_off;
	HotDir;
	Hot_off;
	BT_CONFIG();             //定时器初始化 0.125ms
	Bled_On();
	IoInit();
	Wait(20);		            //延时200ms
	Ram_Init();
	LcdInit();
	BLedDir;
	BLed_on;
	UART2_CONFIG();         //UART2 115200 for upgrade
	IFC_CONFIG();
	Set_Temp_Buf = 37;
	FlagSetBit(FgTx_First);    //FgTx_First = 1;
	Room_Temp_Buf = 25;
	
	ReadDataArry(FLAG_VERSION_ADDR ,1 , &g_byVersionflag);
	

	
 #ifdef FOR_DEBUG
	my_printf("\r\n--->this is OTA App now!\r\n");
#endif

	while(1)
	{
		feed_IWDT();
		//------------------------------
		if(FlagGetBit(Fg2500us) == 1)
		{
			feed_IWDT();
			SetDisplay();
			Lcd_Disp();
			Uart_Tx_Rx();
		}
	
		if(FlagGetBit(Fg10mS) == 1)
		{
			FlagClearBit(Fg10mS);
			ScanKey();
			if(FlagGetBit(FgTx_ST_RT) == 1)
			{
				if(++Time_1d2S==150)
				{
					FlagSetBit(FgTx_RTTemp);
				}
				else if(Time_1d2S>=250)
				{
					FlagSetBit(FgTx_STTemp);
					Time_1d2S = 0;
					if(++TxSTRT_Cnt >= 24)
					{
						TxSTRT_Cnt=0;
						FlagClearBit(FgTx_ST_RT);
					}
				}
			}
			/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			背光延时10秒关
			*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
			if(BLed)
			{
				if(++DlyOffBled>=1000)
				{
					BLed_off;
				}
			}
		}
	
		if(FlagGetBit(Fg100ms) == 1 )
		{
			FlagClearBit(Fg100ms);
			//SetDlyDec();
			
			if(FlagGetBit(FgTx_First) == 0)//收到心跳包之后发送版本信息
			{
				if(g_byVersionflag == 1)
				{
					Send_Data_Pid();
					g_byVersionflag = 0;
					ProgramData_Word(FLAG_VERSION_ADDR,1, &g_byVersionflag);
#ifdef FOR_DEBUG
					my_printf("Step 5: Send new app verison to Tuya\r\n");
#endif
				}
			}
		}
		
		if(FlagGetBit(Fg1s) == 1)
		{
			FlagClearBit(Fg1s);
			
			if(PeiWangTimer)
			{
				--PeiWangTimer;
			}
			
			if(FlagGetBit(FgTx_Test) ==0)//未产测
			{
				FlagSetBit(FgTxGetClk);
			}
		}
	}
	
	return 0;
}