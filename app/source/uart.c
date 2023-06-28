/*******************************************************************************
程 序 名:
*******************************************************************************/
#include "define.h"

#include "apt32f102.h"
#include "apt32f102_uart.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"
#include "apt32f102_ifc.h"
//#define PRODUCT_KEY "nw94tgwbz5omq0rc"
//#define PRODUCT_KEY "dgtqvdrj0qw5jte5"
#define PRODUCT_KEY  "dtrdpsd3ggcua7sn"
#define MCU_VER     "2.4.2"
#define CONFIG_MODE "0"
#define PRODUCTS_INF   "{\"p\":\"" PRODUCT_KEY "\",\"v\":\"" MCU_VER "\",\"m\":" CONFIG_MODE "}"
char PidCom[]  = {0x55,0xAA,0x3,0x01,0x00,0x2a};
char PidCode[] = {PRODUCTS_INF};

/*******************************************************************************
心跳:mcu第一次返回
*******************************************************************************/
uchar Mcu_Ret_Front_Tab[]=//8
{
	0x55,0xaa,0x03,0x00,
	0x00,0x01,0x00,0x03
};
/*******************************************************************************
心跳:除第一次外，正常返回
*******************************************************************************/
uchar Mcu_Ret_Back_Tab[]=//8
{
	0x55,0xaa,0x03,0x00,
	0x00,0x01,0x01,0x04
};

/*******************************************************************************
查询MCU，设定模块的工作模式 MCU回
*******************************************************************************/
uchar Mcu_WorkMode_Tab[]=//7
{
	0x55,0xaa,0x03,0x02,
	0x00,0x00,0x04
};
/*******************************************************************************
报告 WIFI 工作状态-命令字:0x03
*******************************************************************************/
uchar Mcu_WifiState_Tab[]=//7
{
	0x55,0xaa,0x03,0x03,
	0x00,0x00,0x05
};
/*******************************************************************************
重置 WIFI MCU发-命令字:0x04
*******************************************************************************/
uchar Mcu_ReWifi_Tab[]=//7
{
	0x55,0xaa,0x03,0x04,
	0x00,0x00,0x06
};
/*******************************************************************************
/快连配网 MCU发-命令字:0x05
*******************************************************************************/
uchar Mcu_RstToSmart_Tab[]=//8
{
	0x55,0xaa,0x03,0x05,
	0x00,0x01,0x00,0x8
};
/*******************************************************************************
/热点配网
*******************************************************************************/
uchar Mcu_RstToAp_Tab[]=//8
{
	0x55,0xaa,0x03,0x05,
	0x00,0x01,0x01,0x9
};
/*******************************************************************************
重置 WIFI 模块回
*******************************************************************************/
uchar Mod_ReWifi_Tab[]=//12
{
	0x55,0xaa,0x03,0x04,
	0x00,0x05,0x01,0x01,
	0x00,0x01,0x01,0x3c
};
/*******************************************************************************
加热开关数据
*******************************************************************************/
uchar Mcu_Hot_Tab[]=//10
{
	0x55,0xaa,0x03,0x07,
	0x00,0x05,0x01,0x01,
	0x00,0x1
};
/*******************************************************************************
设置温度数据
*******************************************************************************/
uchar Mcu_STTemp_Tab[]=//13
{
	0x55,0xaa,0x03,0x07,
	0x00,0x08,0x02,0x02,
	0x00,0x04,0x00,0x00,
	0x00
};
/*******************************************************************************
室温数据
*******************************************************************************/
uchar Mcu_RTTemp_Tab[]=//13
{
	0x55,0xaa,0x03,0x07,
	0x00,0x08,0x03,0x02,
	0x00,0x04,0x00,0x00,
	0x00
};
/*******************************************************************************
预约时间数据
*******************************************************************************/
uchar Mcu_TimerOn_Tab[]=//12
{
	0x55,0xaa,0x03,0x07,
	0x00,0x08,0x05,0x02,
	0x00,0x04,0x00,0x00
};
/*******************************************************************************
MCU查询WIFI信号
*******************************************************************************/
uchar Mcu_Wifi_Tab[]=//7
{
	0x55,0xaa,0x03,0x0e,
	0x00,0x00,0x10
};
/*******************************************************************************
温度传感器正常:0 出错:1
*******************************************************************************/
uchar Mcu_Sence_Tab[]=//10
{
	0x55,0xaa,0x03,0x07,
	0x00,0x05,0x06,0x05,
	0x00,0x1
};

/*******************************************************************************/
//请求本地时钟
/*******************************************************************************/
uchar Mcu_GetClk_Tab[]=//7
{
	0x55,0xaa,0x03,0x1c,
	0x00,0x0,0x1e
};

/*******************************************************************************/
//升级启动返回
/*******************************************************************************/
uchar Mcu_UpgradeStart_Tab[]=//8
{
	0x55,0xaa,0x03,0x0a,0x00,0x01,0x00,0x0d
};

/*******************************************************************************/
//升级包下发返回
/*******************************************************************************/
uchar Mcu_UpgradeTransmit_Tab[]=//7
{
	0x55,0xaa,0x03,0x0b,
	0x00,0x00,0x0d
};


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

//*******************************************************************************
//*******************************************************************************
void Send_Data_Pid(void)
{
	uchar i;
	uchar j,k;
	//Sum=0;
	j=sizeof(PidCom);
	for(i=0;i<j;i++)
	{
		Tx_Buf[i]=PidCom[i];
	}

	k= sizeof(PidCode)-1;
	for(i=0;i<k;i++)
	{
		Tx_Buf[j+i]=PidCode[i];
	}

	Tx_Data_Sum(j+k);
	Tx_Buf[j+k]=Tx_Buf_Sum;
	Uart_Send_String(Tx_Buf,j+k+1);
}



/*******************************************************************************/
/*******************************************************************************
加热开关数据12 模块查询MCU工作状态或MCU上报数据
*******************************************************************************/
void Send_Data_Hot(void)
{
	uchar i;
	for(i=0;i<10;i++)
	{
		Tx_Buf[i]=Mcu_Hot_Tab[i];
	}
	if(FlagGetBit(FgPwr) == 1)
		Tx_Buf[10]=1;
	else
		Tx_Buf[10]=0;
	Tx_Data_Sum(11);
	Tx_Buf[11]=Tx_Buf_Sum;
}
/*******************************************************************************
加热开关数据12  模块下发MCU收到后,上报
*******************************************************************************/
void Send_Data_Hot_Ack(void)
{
	uchar i;
	for(i=0;i<10;i++)
	{
		Tx_Buf[i]=Mcu_Hot_Tab[i];
	}
	Tx_Buf[10]=Rx_Buf[10];
	if(Tx_Buf[10]==1)
	{
		FlagSetBit(FgPwr);//FgPwr=1;
	}
	else
	{
		FlagClearBit(FgPwr);//FgPwr=0;
	}
	Tx_Data_Sum(11);
	Tx_Buf[11]=Tx_Buf_Sum;
	//开关后
	Bled_On();
	SetCnt=0;
	TimerH=0;
	FlagClearBit(FgTimer_Run);//FgTimer_Run=0;//停止运行
	FlagSetBit(FgTx_TimerOff);//FgTx_TimerOff=1;
	SetBeep();
}
/*******************************************************************************
设置温度数据15 模块查询MCU工作状态或MCU上报数据
*******************************************************************************/
void Send_Data_STTemp(void)
{
	uchar i;
	for(i=0;i<13;i++)
	{
		Tx_Buf[i]=Mcu_STTemp_Tab[i];
	}
	Tx_Buf[13]=Set_Temp_Buf;
	Tx_Data_Sum(14);
	Tx_Buf[14]=Tx_Buf_Sum;
}
/*******************************************************************************
设置温度数据15  模块下发MCU收到后,上报
*******************************************************************************/
void Send_Data_STTemp_Ack(void)
{
	uchar i;
	for(i=0;i<13;i++)
	{
		Tx_Buf[i]=Mcu_STTemp_Tab[i];
	}
	Tx_Buf[13]=Rx_Buf[13];
	Set_Temp_Buf=Rx_Buf[13];
	Tx_Data_Sum(14);
	Tx_Buf[14]=Tx_Buf_Sum;
	Bled_On();
	SetBeep();
}
/*******************************************************************************
室温数据15 查询应答上报
*******************************************************************************/
void Send_Data_RTTemp(void)
{
	uchar i;
	for(i=0;i<13;i++)
	{
		Tx_Buf[i]=Mcu_RTTemp_Tab[i];
	}
	Tx_Buf[13]=Room_Temp_Buf;
	Tx_Data_Sum(14);
	Tx_Buf[14]=Tx_Buf_Sum;
}
/*******************************************************************************
预约时间数据15 模块查询MCU工作状态或MCU上报数据
*******************************************************************************/
void Send_Data_TimerOn(void)
{
	uchar i;
	for(i=0;i<12;i++)
	{
		Tx_Buf[i]=Mcu_TimerOn_Tab[i];
	}

	Timer_Swi=TimerH*60;
	Tx_Buf[12]=Timer_Swi/256;
	Tx_Buf[13]=Timer_Swi%256;
	Tx_Data_Sum(14);
	Tx_Buf[14]=Tx_Buf_Sum;

}
/*******************************************************************************
预约时间数据15 上报预约关,数据为00
*******************************************************************************/
void Send_Data_TimerOff(void)
{
	uchar i;
	for(i=0;i<12;i++)
	{
		Tx_Buf[i]=Mcu_TimerOn_Tab[i];
	}
	Tx_Buf[12]=0;
	Tx_Buf[13]=0;
	Tx_Data_Sum(14);
	Tx_Buf[14]=Tx_Buf_Sum;
}
/*******************************************************************************
预约时间数据15  模块下发MCU收到后,上报
*******************************************************************************/
void Send_Data_TimerOn_Ack(void)
{
	uchar i;
	for(i=0;i<12;i++)
	{
		Tx_Buf[i]=Mcu_TimerOn_Tab[i];
	}
	if(FlagGetBit(FgPwr) == 1) //定时关
	{
		SetCnt=3;//Flash_Bit=3;
		SetDly=CSetDly;
		SetBeep();
		
		Timer_Swi=Rx_Buf[12]*256+Rx_Buf[13];
		Timer_Swi=Timer_Swi/60;
		TimerH=Timer_Swi;
		TimerM=0;
		FlagClearBit(FgTimer_Run);//FgTimer_Run=0;
		Tx_Buf[12]=Rx_Buf[12];
		Tx_Buf[13]=Rx_Buf[13];
		Tx_Data_Sum(14);
		Tx_Buf[14]=Tx_Buf_Sum;
	}
	else
	{
		/*
		SetCnt=0;//Flash_Bit=2;
	
		FgOn=1;//延时开
		FgOff=0;
		Timer_Swi=Rx_Buf[12]*256+Rx_Buf[13];
		Timer_Swi=Timer_Swi/60;
		//Timer_On_Buf=Timer_Swi;
		Tx_Buf[12]=Rx_Buf[12];
		Tx_Buf[13]=Rx_Buf[13];
		Tx_Data_Sum(14);
		Tx_Buf[14]=Tx_Buf_Sum;*/
	}
}
/*******************************************************************************
时间变化一分钟  
*******************************************************************************/
void Send_Data_TimerOn_1Min(void)
{
	uchar i;
	for(i=0;i<12;i++)
	{
		Tx_Buf[i]=Mcu_TimerOn_Tab[i];
	}
	if(FlagGetBit(FgTimer_Run) == 1)
	{
		Timer_Swi=TimerH;
		Timer_Swi*=60;
		Timer_Swi+=TimerM;
		Tx_Buf[12]=Timer_Swi/256;
		Tx_Buf[13]=Timer_Swi%256;
		Tx_Data_Sum(14);
		Tx_Buf[14]=Tx_Buf_Sum;
	}
}
/*******************************************************************************
传感器
*******************************************************************************/
void Send_Data_Sence(void)
{
	uchar i;
	for(i=0;i<10;i++)
	{
		Tx_Buf[i]=Mcu_Sence_Tab[i];
	}
	if(FlagGetBit(FgWrong) == 1)
		Tx_Buf[10]=1;
	else
		Tx_Buf[10]=0;
	Tx_Data_Sum(11);
	Tx_Buf[11]=Tx_Buf_Sum;
}
/*******************************************************************************
*******************************************************************************/
/*******************************************************************************
计算校验和
*******************************************************************************/
uchar Get_Sum(U16_T cnt,U16_T len)
{
	uchar sum = 0;
	U16_T i;
	
	for(i = 0; i < len + 6; i ++)
	{
		sum += Rx_Buf[cnt + i];
	}
	return sum;
}

/*******************************************************************************
读写比较
*******************************************************************************/
U8_T rw_compare(U8_T *r_buff, U8_T *w_buff, U8_T len)
{
		U8_T i = 0;
		
		for(i = 0; i < len; i++)
		{
				if(r_buff[i] != w_buff[i])
				{
						return 1;
				}
		}
		
		return 0;
}

/*******************************************************************************
接收处理程序
*******************************************************************************/
void Uart_Rx(void)
{
	U8_T   readbuff[300] = {0};
	U8_T   ret = 0;
	U16_T cnt=0,i,len;
	uchar cmd;
	U32_T packageOffset = 0;
	while(cnt < Rx_Count)
	{
		feed_IWDT();//CLRWDT=1;//清看门狗
		if(Rx_Buf[cnt]==0x55 && Rx_Buf[cnt+1]==0xaa && Rx_Buf[cnt+2]==0x00)
		{
			len = (U16_T)(Rx_Buf[cnt+4] << 8) | (U16_T)Rx_Buf[cnt+5];
			if(Rx_Buf[cnt+6+len] == Get_Sum(cnt,len))
			{
#ifdef FOR_DEBUG
				for(i = 0; i < Rx_Count; i++)
				{
						my_printf("Rx_Buf[%d] = 0x%x\r\n", i, Rx_Buf[i]);
				}
						my_printf("/**************************/\r\n");
#endif
				//数据处理
				cmd = Rx_Buf[cnt+3];
				switch(cmd)
				{
					/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					心跳返回-命令字:0x00
					*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
					case 0:
					if(FlagGetBit(FgTx_First) == 1)
					{
						Uart_Send_String(Mcu_Ret_Front_Tab,8);
						FlagClearBit(FgTx_First);//FgTx_First=0;
					}
					else
					{
						Uart_Send_String(Mcu_Ret_Back_Tab,8);
					}
					break;
					/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					PID上报-命令字:0x01
					*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
					case 1:
						
						if(g_byUpgradeflag == 0)
						{
							Send_Data_Pid();
						}
						else
						{
#ifdef FOR_DEBUG
                            my_printf("Step 3: Start reset mcu now... \r\n");
#endif
							g_byVersionflag = 1;
							ProgramData_Word(FLAG_VERSION_ADDR,1,&g_byVersionflag);//把升级标志存入相应地址
							rst_mcu();
						}
						
						break;
					/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					设置工作模式-命令字:0x02
					*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
					case 2:						
					Uart_Send_String(Mcu_WorkMode_Tab,7);
					break;
					/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					模块下发报告WIFI工作状态-命令字:0x03
					*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
					case 3:
					Wifi_State=Rx_Buf[cnt+6];
					Uart_Send_String(Mcu_WifiState_Tab,7);
					if(Wifi_State>=3)
					{
						TxSTRT_Cnt=0;   //配网成功
						FlagSetBit(FgTx_ST_RT);//FgTx_ST_RT=1;
						PeiWangTimer=0;
					}
					break;
					/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					手机操作下发,MCU回复-命令字:0x06
					*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
					case 6://模块下发,MCU上报
					//APP设置加热开关
					if(Rx_Buf[cnt+6]==0x01)
					{
						Send_Data_Hot_Ack();
						Uart_Send_String(Tx_Buf,12);
				
					}
				
					//APP设置温度
					if(Rx_Buf[cnt+6]==0x2)
					{
						Send_Data_STTemp_Ack();
						Uart_Send_String(Tx_Buf,15);
					}
				
					
					break;
					/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					模块查询所有,MCU上报-命令字:0x08
					*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
					case 8://模块查询所有,MCU上报
					//MCU加热开关上报
					Send_Data_Hot();
					Uart_Send_String(Tx_Buf,12);
					
					//MCU设定温度上报
					Send_Data_STTemp();
					Uart_Send_String(Tx_Buf,15);
					//MCU室温上报
					Send_Data_RTTemp();
					Uart_Send_String(Tx_Buf,15);
					
					
					break;
					/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
					产测,信号查询,MCU上报-命令字:0x0e
					*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
					case 0x0e://产测,信号查询
					Sms_Buf=Rx_Buf[cnt+7];
					if(Sms_Buf>0)
					{
						FlagSetBit(FgRx_TestOK);//FgRx_TestOK=1;
						if(FlagGetBit(FgTestOk) == 0)
						{	
							FlagSetBit(FgTestOk);//FgTestOk=1;
						}
						Wifi_State=3;//产测成功,WIFI灯亮,显示信号质量
					}
					else
					{
						FlagClearBit(FgRx_TestOK);//FgRx_TestOK=0;
						Wifi_State=2;
					}
					if(Sms_Buf>99)
						Sms_Buf=99;
					break;
					//---------------------------------
				
					case	0x1c:  //获取时钟(不用应答
						if(Rx_Buf[6]==1)
						{
						
							ClkH=Rx_Buf[10];
							ClkM=Rx_Buf[11];
							if(ClkH>=24)
							{
								ClkH=0;
								ClkM=0;
								FlagClearBit(FgClkRxOk);//FgClkRxOk=0;
							}
							else
								FlagGetBit(FgClkRxOk);//FgClkRxOk=1;
							GetClkTimeOut=CTime60s;
						}
						else
						{
							if(GetClkTimeOut==0)
								FlagClearBit(FgClkRxOk);//FgClkRxOk=0;
						}
						break;
						
					case	0x0a:  //升级启动命令
					    g_dwFirmwareSize = (U32_T)(Rx_Buf[6] << 24) | (U32_T)(Rx_Buf[7] << 16) | (U32_T)(Rx_Buf[8] << 8) | (U32_T)Rx_Buf[9];
						ProgramData_Word(FIRMWAE_SIZE_ADDR, 4, &Rx_Buf[6]);//把升级文件总大小存入相应地址
						Uart_Send_String(Mcu_UpgradeStart_Tab,8);
#ifdef FOR_DEBUG
						my_printf("Step 1: Recieve the command of upgrade successfully!!!\r\n");
#endif
						break;
						
					case 0x0b: //升级包下发指令
					
						g_byTransmmitflag = 1;
						packageOffset = (U32_T)(Rx_Buf[6] << 24) | (U32_T)(Rx_Buf[7] << 16) | (U32_T)(Rx_Buf[8] << 8) | (U32_T)Rx_Buf[9];

						if((len == 0x4) && (packageOffset >= g_dwFirmwareSize))
						{
							ret = 0;
						}
						else if((len > 0x4) && ((len - 0x4) <= PACKAGE_SIZE))
						 {
							ProgramData_Word((TEMP_APP_START_ADDR + packageOffset), (len - 4), &Rx_Buf[10]);
							ReadDataArry((TEMP_APP_START_ADDR + packageOffset) ,(len - 4) , &readbuff[0]);
							if(0 != rw_compare(&readbuff[0], &Rx_Buf[10], (len - 4)))
							{
#ifdef FOR_DEBUG
								my_printf("Compare wrong, upgrade fail!!!\r\n");
#endif
								ret = 1;
							}
							else
							{
								ret = 0;
							}
							
							if(((len - 0x4) +packageOffset)  == g_dwFirmwareSize)
							{
								g_byTransmmitflag = 0;
								g_byUpgradeflag = 1;
								ProgramData_Word(UPGRADEFLAG_ADDR,1,&g_byUpgradeflag);//把升级标志存入相应地址
#ifdef FOR_DEBUG
								my_printf("Step 2: Recieve all the package of upgrade successfully!!!\r\n");
#endif
							}
						 }
						 else
						 {
							 ret = 1;
#ifdef FOR_DEBUG
							 my_printf("Lenth is wrong, upgrade fail!!!\r\n");
#endif
						 }
							 
						if(ret == 0)
						{
							Uart_Send_String(Mcu_UpgradeTransmit_Tab,7);
						}
						
						break;
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
		if(g_byTransmmitflag == 0)
		{
			/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			产测
			*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
			if(FlagGetBit(FgTx_Test) == 1)
			{
				FlagClearBit(FgTx_Test);//FgTx_Test=0;
				Uart_Send_String(Mcu_Wifi_Tab,7);
			}
			/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			WIFI重置
			*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
			else if(FlagGetBit(FgTx_ReSet) == 1)
			{
				FlagClearBit(FgTx_ReSet);//FgTx_ReSet=0;
				Uart_Send_String(Mcu_ReWifi_Tab,7);
			}
			else	if(FlagGetBit(FgRstToSmart) == 1)
			{
				FlagClearBit(FgRstToSmart);//FgRstToSmart=0;
				Uart_Send_String(Mcu_RstToSmart_Tab,8);
				
			}
			else	if(FlagGetBit(FgRstToAp) == 1)
			{
				FlagClearBit(FgRstToAp);//FgRstToAp=0;
				Uart_Send_String(Mcu_RstToAp_Tab,8);
			}
			/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			查看WIFI工作状态
			*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
			else if(FlagGetBit(FgTx_Wrong) == 1)
			{
				FlagClearBit(FgTx_Wrong);//FgTx_Wrong=0;
				Send_Data_Sence();
				Uart_Send_String(Tx_Buf,12);
			}
			/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			加热开关上报
			*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
			else if(FlagGetBit(FgTx_Swi) == 1)
			{
				FlagClearBit(FgTx_Swi);//FgTx_Swi=0;
				Send_Data_Hot();
				Uart_Send_String(Tx_Buf,12);
			}
			/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			设定温度上报
			*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
			else if(FlagGetBit(FgTx_STTemp) == 1)
			{
				FlagClearBit(FgTx_STTemp);//FgTx_STTemp=0;
				//设置温度
				Send_Data_STTemp();
				Uart_Send_String(Tx_Buf,15);
			}
			/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
			室温变化上报
			*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
			else if(FlagGetBit(FgTx_RTTemp) == 1)
			{
				FlagClearBit(FgTx_RTTemp);//FgTx_RTTemp=0;
				Send_Data_RTTemp();
				Uart_Send_String(Tx_Buf,15);
			}
		}
	}
}
/*******************************************************************************
	END
*******************************************************************************/