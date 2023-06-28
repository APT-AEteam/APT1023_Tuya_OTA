 /***********************************************************************
程 序 名:按键扫描
***********************************************************************/
#include "define.h"
/***********************************************************************
***********************************************************************/
void	SetBeep(void)
{
	if(FlagGetBit(FgKeyLx) == 0)
	{
		BeepLen=CBeepLen;
	}
}
/***********************************************************************
***********************************************************************/
void  Bled_On(void)
{
	BLed_on;
	DlyOffBled=0;
}
//*********************************************************************
//*********************************************************************
void	PwrOff(void)
{
	FlagClearBit(FgPwr);//FgPwr=0;
	FlagSetBit(FgTx_Swi);//FgTx_Swi=1;//上报加热开关状态
	TimerH=0;
	TimerM=0;
	FlagClearBit(FgTimer_Run);//FgTimer_Run=0;//停止运行
}

/***********************************************************************
	 加热开关
***********************************************************************/
void Key_Power_Switch(void)
{
	if(FlagGetBit(FgLock) == 1)
		return;
	Bled_On();
	FlagSetBit(FgKey);//FgKey=1;
	FlagReverseBit(FgPwr);//FgPwr=!FgPwr;
	FlagSetBit(FgTx_Swi);//FgTx_Swi=1;//上报加热开关状态
	SetCnt=0;
	FlagClearBit(FgTimer_Run);//FgTimer_Run=0;//停止运行
	
	TimerH=0;
	TimerM=0;
	SetBeep();
	
}

/***********************************************************************
	加一
***********************************************************************/
void Key_Add(void)
{
	if(FlagGetBit(FgPwr) == 0)
		return;
	if(FlagGetBit(FgLock) == 1)
		return;
	Bled_On();
	SetBeep();
	FlagSetBit(FgKey);//FgKey=1;
	if(SetCnt==0)
	{
		SetCnt=1;
		SetDly=CSetDly;
	}
	if(SetCnt==1)
	{
		if(Set_Temp_Buf<37)
		{
			Set_Temp_Buf++;
			FlagSetBit(FgTx_STTemp);//FgTx_STTemp=1;
		}
		FlashTime=0;
		FlagClearBit(FgFlash);//FgFlash=0;
		SetDly=CSetDly;
	}

	
 }
/***********************************************************************
	减一
***********************************************************************/
void Key_Dec(void)
{

	if(FlagGetBit(FgPwr) == 0)
		return;
	if(FlagGetBit(FgLock) == 1)
		return;
	Bled_On();
	SetBeep();
	FlagSetBit(FgKey);//FgKey=1;
	if(SetCnt==0)
	{
		SetCnt=1;
		SetDly=CSetDly;
	}
	else	if(SetCnt==1)
	{
		if(Set_Temp_Buf>0)
		{
			Set_Temp_Buf--;
			FlagSetBit(FgTx_STTemp);//FgTx_STTemp=1;
		}
		FlashTime=0;
		FlagClearBit(FgFlash);//FgFlash=0;
		SetDly=CSetDly;
	}

	
}
//**********************************************************************
//**********************************************************************
//**********************************************************************

void	Key_WifiRst(void)
{
	if(FlagGetBit(FgLock) == 1)
		return;
	
	FlagSetBit(FgKey);//FgKey=1;
	SetBeep();
	Bled_On();

	FlagReverseBit(FgPeiWangMode);//FgPeiWangMode^=1;
	if(FlagGetBit(FgPeiWangMode) == CPeiWangApp)
	{	
			FlagSetBit(FgRstToAp);//FgRstToAp=1;
			FlagClearBit(FgRstToSmart);//FgRstToSmart=0;
	}
	else
	{
			FlagSetBit(FgRstToSmart);//FgRstToSmart=1;
			FlagClearBit(FgRstToAp);//FgRstToAp=0;
	}	
	PeiWangTimer=CPeiWangTimer;	

}


/***********************************************************************
	按键扫描 10ms call
***********************************************************************/
void ScanKey(void)
{
	//static	uchar	KeyOld;
	static	uint	KeyCnt;
	static	uchar	KeySpeed;
	KeyVal=0;
	if(PwrKey==0)
		KeyVal=1;
	if(WiFiKey==0)
		KeyVal=2;
	if(TmrKey==0)
		KeyVal=4;
	if(DownKey==0)
		KeyVal=8;
	if(UpKey==0)
		KeyVal=0x10;

	if(KeyVal>0)
	{
		++KeyCnt;
		++KeySpeed;
		//KeyOld=KeyVal;
		if(KeyCnt>=5)
		{
			if(FlagGetBit(FgKey)==0)
			{
				if(KeyVal==0x1)
				{
					Key_Power_Switch();//开关
				}
				else	if(KeyVal==0x8)
				{
					Key_Add();
				}
				else	if(KeyVal==0x10)
				{
					Key_Dec();
				}
			}
		}
		
		if((KeyCnt>=50)&&(KeyVal&0x18))
		{
			KeyCnt=50;
			FlagSetBit(FgKeyLx);//FgKeyLx=1;
			if(KeySpeed>=30)
			{
				KeySpeed=0;
				FlagClearBit(FgKey);//FgKey=0;
			}
		}
		//-----------------------------------------
	

		if((KeyCnt>=450)&&(KeyVal&0x2))//重置
		{
			KeyCnt=0;
			Key_WifiRst();
		}
	}
	else
	{
		
		KeyCnt=0;
		KeySpeed=0;
		FlagClearBit(FgKey);//FgKey=0;
		FlagClearBit(FgKeyLx);//FgKeyLx=0;
	}
}
/***********************************************************************
	END
***********************************************************************/