/*******************************************************************************
程 序 名:
*******************************************************************************/
#include "define.h"
//#define PRODUCT_KEY "nw94tgwbz5omq0rc"
//#define PRODUCT_KEY "dgtqvdrj0qw5jte5"
//#define PRODUCT_KEY  "dtrdpsd3ggcua7sn"
//#define MCU_VER     "1.0.0"
//#define CONFIG_MODE "0"
//#define PRODUCTS_INF   "{\"p\":\"" PRODUCT_KEY "\",\"v\":\"" MCU_VER "\",\"m\":" CONFIG_MODE "}"
//char PidCom[]  = {0x55,0xAA,0x3,0x01,0x00,0x2a};
//char PidCode[] = {PRODUCTS_INF};


/*******************************************************************************
发送一组数据//发送同时也要接收数据-全双工模式
*******************************************************************************/
void Uart_Send_String(uchar *s,uchar num)
{
	uchar i;
	for (i=0; i<num; i++)
	{
		UARTTxByte(UART2, s[i]);
	}
}
/*******************************************************************************
发送数据总和
*******************************************************************************/
void Tx_Data_Sum(uchar num)
{
	uchar i;
	Tx_Buf_Sum=0;
	for(i=0;i<num;i++)
	{
		Tx_Buf_Sum+=Tx_Buf[i];
	}
}


/*******************************************************************************
计算校验和
*******************************************************************************/
uchar Get_Sum(uchar cnt,uchar len)
{
	uchar sum = 0;
	uchar i;
	
	for(i = 0; i < len + 6; i ++)
	{
		sum += Rx_Buf[cnt + i];
	}
	return sum;
}
/*******************************************************************************
接收处理程序
*******************************************************************************/
void Uart_Rx(void)
{
	U16_T cnt=0,i,len;
	uchar cmd;
	while(cnt < Rx_Count)
	{
		feed_IWDT();//CLRWDT=1;//清看门狗
		if(Rx_Buf[cnt]==0x55 && Rx_Buf[cnt+1]==0xaa && Rx_Buf[cnt+2]==0x00)
		{
			len = (Rx_Buf[cnt+4] << 8) | Rx_Buf[cnt+5];
			if(Rx_Buf[cnt+6+len] == Get_Sum(cnt,len))
			{
				//数据处理
				cmd = Rx_Buf[cnt+3];
				switch(cmd)
				{
					/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					心跳返回-命令字:0x00
					*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//					case 0:
//					if(FlagGetBit(FgTx_First) == 1)
//					{
//						Uart_Send_String(Mcu_Ret_Front_Tab,8);
//						FlagClearBit(FgTx_First);//FgTx_First=0;
//					}
//					else
//						Uart_Send_String(Mcu_Ret_Back_Tab,8);
//					break;
					
				}
				cnt += (7 + len);
			}
			else//如校验码不符,计数器加一
			{
				cnt ++;
			}
		}
		else//如帧头不符,计数器加一
		{
			cnt ++;
		}
	}
	
	for(i=0;i<Rx_Count;i++)
	{
		Rx_Buf[i]=0;
	}
	Rx_Count=0;
	FlagClearBit(FgRx_End);//FgRx_End=0;
}

//***************************************************
/*******************************************************************************
	串行通信收发
*******************************************************************************/
void Uart_Tx_Rx(void)
{
	/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
	接收时,不发送:	FgRx_End=0:正在在接收数据或等待接收数据
					        FgRx_End=1:已接收完一组数据
	接收完数据后,解码
	*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
		
	if(FlagGetBit(FgRx_End) == 1)
	{
		feed_IWDT();
		Uart_Rx();
	}
	
	/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
	发送入口:只在空闲时发送数据
	*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
	else if(FlagGetBit(FgRxDone) == 0)
	{

	
	}
}
/*******************************************************************************
	END
*******************************************************************************/