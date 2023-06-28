/*
  ******************************************************************************
  * @file    define.c
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

#include "define.h"

//-----------升级---------------//
U8_T  g_byUpgradeflag = 0;
U32_T g_dwFirmwareSize = 0;
//-------------------------------//

U32_T Flag1;
U32_T Flag2;

U8_T BeepLen;
U8_T Run_Step;
U8_T SetDly;
U8_T Time2500us;
U8_T Time_10mS;
U8_T Time100ms;
U8_T Time_50mS;
U8_T FlashTime;
U8_T Time_500mS;
U8_T Time1s;
U8_T Time_1d2S;
U8_T Time_1Min;
U8_T Reset_1Min;
U8_T Disp_Temp;
U8_T DispBuf[9];
U8_T Timer_On_Buf;
U8_T TimerH;
U8_T TimerM;
U8_T Time1h;
U8_T SetCnt;
U8_T Flash_Step;
U8_T KeyVal;
U8_T Flash_Lengh;
U8_T Time_Tx;
U16_T  DlyOffBled;
U16_T  Timer_Swi;

//---------------------------WIFI
U8_T Rx_Buf_Sum;
U8_T Tx_Buf_Sum;
U16_T Rx_Count;
U8_T Tx_Count;
U8_T RxDoneCnt;
U8_T Sms_Buf;
U8_T Wifi_State;
U8_T Led_Cnt;
U8_T TxSTRT_Cnt;
//-----------------
//---------------------------AD
U8_T Set_Temp_Buf;
signed char Room_Temp_Buf;
U8_T Goto_Temp;
U8_T Index;
U8_T AD_Count;
U8_T AD_Dly;
//-----------------
U16_T  AD_Buf;
U16_T  AD_Value[2];
U16_T  TempVer;
U16_T  Temp16;
U32_T AD_Data_Sum;
//---------------------------
U8_T Tx_Buf[64];
U8_T Rx_Buf[MAX_BUFF];
signed char AdjTmp;
U8_T Time1m;
U16_T  HotOnTimeSum;
U16_T  HotOffTimeSum;
U8_T ClkH;
U8_T ClkM;
U8_T GetClkTimeOut;
U8_T SysTime;
U8_T PeiWangTimer;
U8_T Rx_Code_Data[2];
U8_T Rx_Code_Buf[3];
U8_T CdData[3];//
U8_T CdDataBak[3];
U8_T CdSample,CdBitCn;//












U8_T FlagGetBit(U8_T index)
{
	U32_T flag = 0;
	if(index < 32)
	{
		flag = Flag1;
		return ((flag >> index) & 1ul);
	}
	else
	{
		flag = Flag2;
		return ((flag >> (index - 32)) & 1ul);
	}
}


void FlagSetBit(U8_T index)
{
	U32_T flag = 0;
	if(index < 32)
	{
		flag = Flag1;
		Flag1 = flag | (1ul << index);
	}
	else
	{
		flag = Flag2;
		Flag2 = flag | (1ul << (index-32));
	}
}

void FlagClearBit(U8_T index)
{
	U32_T flag = 0;
	if(index < 32)
	{
		flag = Flag1;
		Flag1 = flag & (~(1ul << index));
	}
	else
	{
		flag = Flag2;
		Flag2 = flag & (~(1ul << (index - 32)));
	}
}

void FlagReverseBit(U8_T index)
{
	U32_T flag = 0;
	if(index < 32)
	{
		flag = Flag1;
		Flag1 = flag ^ (1ul << index);
	}
	else
	{
		flag = Flag2;
		Flag2 = flag ^ (1ul << (index - 32));
	}
}