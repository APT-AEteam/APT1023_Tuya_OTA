/***************************************************************
	disp.c
***************************************************************/
#include  "define.h"
/***************************************************************
Define global variable
***************************************************************/

#define	CDispo	0x0
#define	CDispF	0xf
#define	CDispn	0x19
#define CDisp_  0x17
/***************************************************************
***************************************************************/
uchar DispTab[]=
{
	//a f E x B G C D 
	0xEB,/*0*/
	0x0A,/*1*/
	0xAD,/*2*/
	0x8F,/*3*/
	0x4E,/*4*/
	0xC7,/*5*/
	0xE7,/*6*/
	0x8A,/*7*/
	0xEF,/*8*/
	0xCF,/*9*/
	0xEE,/*A*/
	0x67,/*b*/
	0x25,/*c*/
	0x2F,/*d*/
	0xE5,/*E*/
	0xE4,/*F*/
	0x66,/*h*/
	0x6E,/*H*/
	0x27,/*o*/
	0xEC,/*P*/
	0x61,/*L*/
	0x24,/*r*/
	0x4F,/*Y*/
	0x04,/*-*/
	0x01,/*_*/
	0xea,/*N*/
};

//**************************************************************
//**************************************************************
void	GetTmpDisp(void)
{
	
	DispBuf[2]=DispTab[Room_Temp_Buf/10];
	DispBuf[3]=DispTab[Room_Temp_Buf%10];
	SetBit(DispBuf[2],4); 		//RT
	SetBit(DispBuf[3],4); 		//摄氏度 S4
	

}	
//**************************************************************
//**************************************************************
void	SetClkDisp(void)
{
	if(FlagGetBit(FgClkRxOk) == 1)
	{
		if(ClkH>=10)
			DispBuf[4]=DispTab[ClkH/10];
		DispBuf[5]=DispTab[ClkH%10];
		DispBuf[6]=DispTab[ClkM/10];
		DispBuf[7]=DispTab[ClkM%10];
	}
	else
	{
		DispBuf[4]=DispTab[CDisp_];
		DispBuf[5]=DispTab[CDisp_];
		DispBuf[6]=DispTab[CDisp_];
		DispBuf[7]=DispTab[CDisp_];
	}
	
	if(FlagGetBit(FgCol) == 1)
		SetBit(DispBuf[6],4);
}

//**************************************************************
//**************************************************************

void	GetTmrDisp(void)
{
	if(TimerH>=10)
		DispBuf[4]=DispTab[TimerH/10];
	DispBuf[5]=DispTab[TimerH%10];
	DispBuf[6]=DispTab[TimerM/10];
	DispBuf[7]=DispTab[TimerM%10];
	if(FlagGetBit(FgCol) == 1)
		SetBit(DispBuf[6],4);
	SetBit(DispBuf[4],4); //lock
}

//**************************************************************
//**************************************************************

void	GetWiFiDisp(void)
{
	if(PeiWangTimer)
	{
		if(FlagGetBit(FgPeiWangMode)==CPeiWangSmart)
		{
			if(FlagGetBit(FgFlash100ms) == 0) //快闪
				SetBit(DispBuf[8],3);
		}
		else
		{
			if(FlagGetBit(FgFlash1s) == 0) //慢闪
				SetBit(DispBuf[8],3);
		}
		return;
	}
	
	if(FlagGetBit(FgTx_First) == 1)//接收到心跳后
		return;
	
	if(Wifi_State==0)
	{
		if(FlagGetBit(FgFlash100ms) == 0) //快闪
		{
			SetBit(DispBuf[8],3); 
		}
		
	}
	else	if(Wifi_State==1)
	{
		if(FlagGetBit(FgFlash1s)==0) //慢闪
		{
			SetBit(DispBuf[8],3);
		}
	}
	else	if(Wifi_State==2)
	{
	
	}
	else	if((Wifi_State==3)||(Wifi_State==4))
	{
		SetBit(DispBuf[8],3);
	}
	
}
//**************************************************************
//**************************************************************
void	GetLockDisp(void)
{
	if(FlagGetBit(FgLock) == 1)
	{
		SetBit(DispBuf[8],2); //lock
	}
}

//**************************************************************
//定时图标
//**************************************************************

//**************************************************************
/*
void	GetECODisp(void)
{
	if(Set_Temp_Buf==25)  //ECo
	{
		SetBit(DispBuf[8],1);
	}
}*/

/***************************************************************
	Display()
***************************************************************/
void SetDisplay(void)
{
	uchar	i;
	for(i=0;i<sizeof(DispBuf);i++)
	{
		DispBuf[i]=0x0;
	}
	
	if(FlagGetBit(FgPwr) == 0)
	{
		GetTmpDisp();
		SetClkDisp();
		GetWiFiDisp();
		GetLockDisp();
		return;
	}
		
	//----------------------------------------
	if(FlagGetBit(FgRx_TestOK) == 1)//产测成功,显示信号质量
	{
		DispBuf[2]=DispTab[Sms_Buf/10];
		DispBuf[3]=DispTab[Sms_Buf%10];
	}
	else	//工作状态,显示室温
	{
		DispBuf[2]=DispTab[Room_Temp_Buf/10];
		DispBuf[3]=DispTab[Room_Temp_Buf%10];
		SetBit(DispBuf[2],4); 		//RT
		SetBit(DispBuf[3],4); 		//摄氏度 S4
	}
	//-----------------------------------------
	switch(SetCnt)
	{
		/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
		FlashBit=0;正常显示
		*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
		case 0:
		{
			DispBuf[0]=DispTab[Set_Temp_Buf/10];
			DispBuf[1]=DispTab[Set_Temp_Buf%10];
			SetBit(DispBuf[8],0); 		//ST
			SetBit(DispBuf[1],4); 		//摄氏度 s3
	
			if(FlagGetBit(FgTimer_Run) == 1)
			{
				GetTmrDisp();
				
			}
			else
				SetClkDisp();
		
		}break;
		/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
		FlashBit=1调节温度
		*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
		case 1:
		{
			if(FlagGetBit(FgFlash) == 0)//设定温度闪烁,定时开时显示,定时开分显示
			{
				DispBuf[0]=DispTab[Set_Temp_Buf/10];
				DispBuf[1]=DispTab[Set_Temp_Buf%10];
			}
			SetBit(DispBuf[8],0); 		//ST
			SetBit(DispBuf[1],4); 		//摄氏度 s3
			
			if(FlagGetBit(FgTimer_Run) == 1)
				GetTmrDisp();
			else
				SetClkDisp();

		}break;
		
		/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
		FlashBit=3调节定时关时间
		*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
		case 3:
		{
			DispBuf[0]=DispTab[Set_Temp_Buf/10];
			DispBuf[1]=DispTab[Set_Temp_Buf%10];
			SetBit(DispBuf[8],0); 		//ST
			SetBit(DispBuf[1],4); 		//摄氏度 s3
			if(FlagGetBit(FgFlash) == 0)
			{
				GetTmrDisp();
				SetBit(DispBuf[6],4); //col
			}
			SetBit(DispBuf[4],4);	 //定时图标

		}break;
	}

	GetWiFiDisp();
	GetLockDisp();
}

//**************************************************************
//**************************************************************
void	Lcd_Disp(void)
{

	ht_wr_4bit(9,DispBuf[0]>>4);
	ht_wr_4bit(10,DispBuf[0]);
	
	ht_wr_4bit(11,DispBuf[1]>>4);
	ht_wr_4bit(12,DispBuf[1]);
	
	ht_wr_4bit(13,DispBuf[2]>>4);
	ht_wr_4bit(14,DispBuf[2]);
	
	ht_wr_4bit(15,DispBuf[3]>>4);
	ht_wr_4bit(16,DispBuf[3]);
	
	ht_wr_4bit(1,DispBuf[4]>>4);
	ht_wr_4bit(2,DispBuf[4]);
	
	ht_wr_4bit(3,DispBuf[5]>>4);
	ht_wr_4bit(4,DispBuf[5]);
	
	ht_wr_4bit(5,DispBuf[6]>>4);
	ht_wr_4bit(6,DispBuf[6]);
	
	ht_wr_4bit(7,DispBuf[7]>>4);
	ht_wr_4bit(8,DispBuf[7]);
	
	ht_wr_4bit(0,DispBuf[8]);

}

//**************************************************************
/***************************************************************
	END
***************************************************************/