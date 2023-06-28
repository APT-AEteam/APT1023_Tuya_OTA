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
/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"
#include "apt32f102_syscon.h"
#include "apt32f102_coret.h"
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


/* externs function-------------------------------------------------------------------*/
extern void delay_nms(unsigned int t);
extern void APT32F102_init(void);	


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


int main(void) 
{
	U16_T i = 0;
	U16_T j = 0;
	U16_T move_page = 0;
	U16_T move_remainsize = 0;
	U8_T temp_buff[300] = {0};
	
	APT32F102_init();
	
	
	SYSCON -> IWDEDR = 0x78870000 | 0x5555; 		// disable watch dog
    SYSCON->PCER0=0xFFFFFFFF;                            //PCLK Enable
    SYSCON->PCER1=0xFFFFFFFF;                            //PCLK Enable
	ReadDataArry(UPGRADEFLAG_ADDR ,1 , &g_byUpgradeflag);
	
#ifdef FOR_DEBUG	
	my_printf("\r\n--->this is OTA Boatloader now! The g_byUpgradeflag is 0x%x\r\n", g_byUpgradeflag);
#endif


	while(1)
	{
		feed_IWDT();
		
		if(g_byUpgradeflag == 1)//搬运emp_app到pp
		{
			ReadDataArry(FIRMWAE_SIZE_ADDR ,4 , &temp_buff[0]);
			g_dwFirmwareSize = (U32_T)(temp_buff[0] << 24) | (U32_T)(temp_buff[1] << 16) | (U32_T)(temp_buff[2] << 8) | (U32_T)temp_buff[3];

			for(j = 0; j < PACKAGE_SIZE; j++)
			{
				temp_buff[j] = 0;
			}
			
			
			//搬运
			move_page = g_dwFirmwareSize / PACKAGE_SIZE;
			move_remainsize = g_dwFirmwareSize % PACKAGE_SIZE;
			
			for(i = 0; i < move_page; i++)
			{
				ReadDataArry((TEMP_APP_START_ADDR + i*PACKAGE_SIZE), PACKAGE_SIZE, &temp_buff[0]);
				ProgramData_Word((APP_START_ADDR + i*PACKAGE_SIZE), PACKAGE_SIZE, &temp_buff[0]);
				
				for(j = 0; j < PACKAGE_SIZE; j++)
				{
					temp_buff[j] = 0;
				}
			}
			
			ReadDataArry((TEMP_APP_START_ADDR + move_page*PACKAGE_SIZE), move_remainsize, &temp_buff[0]);
			ProgramData_Word((APP_START_ADDR + move_page*PACKAGE_SIZE), move_remainsize, &temp_buff[0]);
			
			//升级标志位清零
			g_byUpgradeflag = 0;
			ProgramData_Word(UPGRADEFLAG_ADDR,1, &g_byUpgradeflag);//把升级标志存入相应地址
#ifdef FOR_DEBUG	
			my_printf("Step 4: Move the data from temp_app to app successfully!!! the total size is 0x%x\r\n", g_dwFirmwareSize);
#endif
		}
		else//跳转
		{
#ifdef FOR_DEBUG	
			 my_printf("Start jump to App...\r\n");
 #endif
			delayms_Bycode(100);
			jump_app();
			delayms_Bycode(10);
		}
	}
	
}
/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/