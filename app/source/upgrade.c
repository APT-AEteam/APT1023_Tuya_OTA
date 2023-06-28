#include "upgrade.h"
#include "apt32f102_uart.h"
#include "iostring.h"
#include "apt32f102_ifc.h"
#include "delay.h"
#include "define.h"

U8_T  g_byUpgradeflag = 0;
U32_T g_dwFirmwareSize = 0;

U8_T  g_byRxfinishflag = 0;
U8_T  g_byTimeoutflag = 0;
U8_T  g_byReadbuff[256] = {0};
U16_T g_wTimecount = 0;

U8_T check_sum(U8_T * buff, U16_T len)
{
	U8_T result = 0;
	U32_T i = 0;
	
	for(i = 0; i < len; i++)
	{
		result += buff[i];
	}
	
	result = result % 256;
	return result;
}

U8_T protocol_check(U8_T *buff)
{
	U16_T frameHead  = 0;
	U16_T framelength = 0;
	U8_T   frameVer = 0;
	U8_T   framechecksum = 0;
	
	frameHead = (U16_T)(buff[0]<< 8) | (U16_T)buff[1];
	frameVer    = buff[2];
	framelength = (U16_T)(buff[4]<< 8) | (U16_T)buff[5];
	framechecksum = check_sum(buff, (6 +framelength));
	
	if(frameHead != FRAME_HEAD)
	{
		my_printf("Frame head is wrong!!! \r\n");
		return 1;
	}
	
	if(frameVer != FRAME_VER)
	{
		my_printf("Frame version is wrong!!! \r\n");
		return 1;
	}
	
	if(framechecksum != buff[6+framelength])
	{
		my_printf("Frame checksum is wrong!!! \r\n");
		return 1;
	}
	
	return 0;
}

void mcu_atk(U8_T cmd)
{
		U8_T buff[16] = {0};
		U8_T i = 0;
		U8_T len = 0;
		
		switch(cmd)
		{
				case CMD_UPGRADE_START:
							buff[0] = 0x55;
							buff[1] = 0xAA;
							buff[2] = 0x03;
							buff[3] = CMD_UPGRADE_START;
							buff[4] = 0x00;
							buff[5] = 0x01;
							buff[6] = PACKAGE_SIZE;
							buff[7] = check_sum(buff, 7);
							
							len = 8;
				break;
				
				case CMD_UPGRADE_TRANSMIT:
							buff[0] = 0x55;
							buff[1] = 0xAA;
							buff[2] = 0x03;
							buff[3] = CMD_UPGRADE_TRANSMIT;
							buff[4] = 0x00;
							buff[5] = 0x00;
							buff[6] = check_sum(buff, 6);
							
							len  = 7;
				break;
				
				case CMD_GET_VERSION:
							buff[0] = 0x55;
							buff[1] = 0xAA;
							buff[2] = 0x03;
							buff[3] = CMD_GET_VERSION;
							buff[4] = 0x00;
							buff[5] = 0x04;
							buff[6] = (U8_T)((APP_VER & 0xFF000000) >> 24);
							buff[7] = (U8_T)((APP_VER & 0x00FF0000) >> 16);
							buff[8] = (U8_T)((APP_VER & 0x0000FF00) >> 8);
							buff[9] = (U8_T)(APP_VER & 0x000000FF);
							buff[10] = check_sum(buff, 10);
							
							len  = 11;
				break;
				
				default:
				break;
		}
		
		for(i = 0; i < len; i++)
		{
				UARTTxByte(UART1, buff[i]);
		}
}

void protocol_analysis(U8_T *buff)
{
	U8_T   frameCmd = 0;
	//U16_T framelength = 0;
	
	if(buff == NULL)
	{
		my_printf("In ProtocolAnalysis, buff is null\r\n");
		return;
	}
	
	if(0 != protocol_check(buff))
	{
			return;
	}
	
	frameCmd  = buff[3];
	//framelength = (U16_T)(buff[4]<< 8) | (U16_T)buff[5];
	
	if(frameCmd == CMD_UPGRADE_START)
	{
		g_dwFirmwareSize = (U32_T)(buff[6] << 24) | (U32_T)(buff[7] << 16) | (U32_T)(buff[8] << 8) | (U32_T)buff[9];
		my_printf("the g_dwFirmwareSize is %x\r\n", g_dwFirmwareSize);
		if(g_dwFirmwareSize > (ROM_END_ADDR - APP_START_ADDR + 1))
		{
			my_printf("The firmware size is more than App size!!! the FirmwareSize is %x\r\n", g_dwFirmwareSize);
			return;
		}
		
		g_byUpgradeflag = 1;
		ProgramData_Word(UPGRADEFLAG_ADDR,1,&g_byUpgradeflag);
		delayms_Bycode(100);
		ProgramData_Word(FIRMWAE_SIZE_ADDR,4,&buff[6]);
		
		rst_mcu();
	}
	else if(frameCmd == CMD_UPGRADE_TRANSMIT)
	{
		
	}
	else if(frameCmd == CMD_GET_VERSION)
	{
		delayms_Bycode(100);
		mcu_atk(CMD_GET_VERSION);
	}
	else;
}


