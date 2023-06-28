 /*
 * Filename : define.h
 *
 * apt32f102 fifo funcitons header file
 *
 * Copyrights 2015 @ APTCHIP
 *
 * Date             Author          Description
 * ----------       ----------      ------------
 * 2023/04/26      LHY           Initial release
 *
 */
#ifndef __DEFINE__H
#define __DEFINE__H


#include "apt32f102.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"
#include "apt32f102_gpio.h"
#include "apt32f102_uart.h"
#include "iostring.h"


//typedef union FLAGG
//{
//        U16_T Flags;        
//        //位域定义部分 
//        struct  
//        {
//			U16_T B0:1;
//			U16_T B1:1;
//			U16_T B2:1;
//			U16_T B3:1;               
//			U16_T B4:1;
//			U16_T B5:1;
//			U16_T B6:1;
//			U16_T B7:1;
//			U16_T B8:1;
//			U16_T B9:1;
//			U16_T B10:1;
//			U16_T B11:1;
//			U16_T B12:1;
//			U16_T B13:1;
//			U16_T B14:1;
//			U16_T B15:1;          
//        }bit;
//}Flagg;
//
//Flagg Flagggg;
//
//#define FgTestOk             Flagggg.bit.B0
//#define FgFlash                Flagggg.bit.B1
//#define Fg100ms              Flagggg.bit.B2
//#define FgFlash100ms       Flagggg.bit.B3
//#define FgFlash1s             Flagggg.bit.B4
//#define FgClkRxOk            Flagggg.bit.B5
//#define FgKey                   Flagggg.bit.B6
//#define Fg2500us              Flagggg.bit.B7
//#define Fg10mS                Flagggg.bit.B8
//#define Fg1s                     Flagggg.bit.B9
//#define FgWrong              Flagggg.bit.B10
//#define FgBeep                Flagggg.bit.B11
//#define FgWrongDone1     Flagggg.bit.B12
//#define FgWrongDone2     Flagggg.bit.B13
//#define FgTimer_Run         Flagggg.bit.B14
//#define FgTx_TimerOff       Flagggg.bit.B15


#define FOR_DEBUG     1 //调试

#define SYSCLOCK       24 //MHz


/********************************/
/*      CPU无关性定义           */
/********************************/
#define ulong	unsigned long
#define	uint	    unsigned int
#define	uchar	unsigned char
#define	u16		unsigned int
#define	u08		unsigned char
#define	u8		unsigned char	




/********************************/
/*                 升级              */
/********************************/
#define MAX_BUFF                           300
#define PACKAGE_SIZE                      0x100

#define ROM_SIZE	                             0xffff               //rom总大小64KB
#define PROM_PAGE_SIZE                    0x100              //prom页大小256 Bytes
#define DROM_PAGE_SIZE                   0x40                //drom页大小64   Bytes
#define RAM_START                            0x20000000ul
#define RAM_SIZE                               0x1000
#define APP_START_ADDR                    0x1000ul         //app 代码存储起始地址
#define APP_END_ADDR                       0x87FFul         //app 代码存储结束地址
#define TEMP_APP_START_ADDR          0x8800ul          //temp_app 代码存储起始地址
#define TEMP_APP_END_ADDR             0xFFFFul           //temp_app 代码存储结束地址

#define APP_EIP_ADDR                        0x110cul          //app main函数的入口地址
#define ROM_END_ADDR                    ROM_SIZE 

//drom里面存储了升级标志，固件总大小，发送版本升级标志，方便boot和app都能操作的到
#define UPGRADEFLAG_ADDR              0x10000000     //升级标志，占4个字节  0x10000000 --- 0x10000003
#define FIRMWAE_SIZE_ADDR              0x10000004     //固件总大小， 占4个字节  0x10000004 --- 0x10000007
#define FLAG_VERSION_ADDR              0x10000008     //发送版本标志， 占4个字节  0x10000008 --- 0x1000000B
#define FLAG_TEST_ADDR                    0x1000000C     //测试， 占4个字节  0x10000008 --- 0x1000000B





	
/********************************/
#define CTmr0		 533//1120/2  //0.125ms
#define SetBit(Reg,Bits)	Reg|=1<<Bits
#define ClrBit(Reg,Bits)  Reg&=~(1<<Bits) 
/********************************/
#define NOP			__asm{NOP}
//#define CLRWDT()	__asm{CLRWDT}//清看门狗
/********************************/
#define InMode    1 
#define OutMode   0
#define FAIL      0
#define SUCCESS   1
#define RIGHT     1
#define ERROR     0
/***********************************************************************
Define Constant
***********************************************************************/
#define	CsTime250ms		125//125*2=0.25s
#define	CsTime1Min		240//240*0.25=60s
#define	CsTime1Hour		60//60
#define	CsTime1Day		24//24
#define	CsTimexDay		90//90
#define	CsSleepTemp		33//33
#define	csAddr_Pro		2//256]0x08
#define	csData_Pro		0x55

#define	CAdDly			50  
#define	CTime60s		60  
#define	CBeepLen		80
#define	CSetDly			30
#define	CPeiWangTimer  120 //s
#define	CPeiWangApp    1
#define	CPeiWangSmart  0
/***********************************************************************/


#define FgTestOk               0
#define FgFlash                  1
#define Fg100ms                2
#define FgFlash100ms         3
#define FgFlash1s               4
#define FgClkRxOk             5
#define FgKey                    6//按键有效
#define Fg2500us               7//周期
#define Fg10mS                 8//
#define Fg1s                      9//
#define FgWrong              10//热敏电阻错误
#define FgBeep                 11
#define FgWrongDone1     12
#define FgWrongDone2     13
#define FgTimer_Run         14
#define FgTx_TimerOff       15//
#define FgTx_TimerOn       16//
#define FgPwr                   17//工作
#define FgDP                    18//
//--------接收标志
#define FgRx_End              19//
#define FgTx_End              20//
#define FgRxDone              21//
#define FgTx_RTTemp        22//
#define FgTx_STTemp        23//
#define FgTx_ST_RT           24//
#define FgTx_Swi               25//
#define FgTx_Wrong          26//
#define FgWifi                   27//
#define FgTx_ReSet            28//
#define FgTxGetClk            29
#define FgReSet_Dly           30//
#define FgLock                  31//
#define FgTx_Lock             32//
#define FgTx_1Min             33//
#define FgTx_First              34//
#define FgTx_Test              35//
#define FgRx_TestOK          36//
#define FgProdTest            37//
#define Fg1m                     38
#define FgCol                    39
#define Fg10ms_Rm           40
#define FgKeyLx                 41
#define FgPeiWangMode    42
#define FgRstToAp             43
#define FgRstToSmart         44




#define	CBeepLen		80

 // PA0_12输入口
#define  PwrKey		GPIO_Read_Status(GPIOA0, 12)
#define  PwrKeyDir	{GPIO_Init(GPIOA0,12,1);GPIO_PullHigh_Init(GPIOA0, 12);}           
// PB0_00输入口
#define  WiFiKey	    GPIO_Read_Status(GPIOB0, 0)
#define  WiFiKeyDir	{GPIO_Init(GPIOB0, 0,1);GPIO_PullHigh_Init(GPIOB0, 0);}           
// PB0_01输入口
#define  TmrKey		GPIO_Read_Status(GPIOB0, 1)
#define  TmrKeyDir	{GPIO_Init(GPIOB0, 1,1);GPIO_PullHigh_Init(GPIOB0, 1);}       
// PA0_05输入口
#define  DownKey	    GPIO_Read_Status(GPIOA0, 5)
#define  DownKeyDir	{GPIO_Init(GPIOA0, 5,1);GPIO_PullHigh_Init(GPIOA0, 5);}    
 // PA0_11输入口
#define  UpKey		    GPIO_Read_Status(GPIOA0, 11)
#define  UpKeyDir	   {GPIO_Init(GPIOA0,11,1);GPIO_PullHigh_Init(GPIOA0, 11);}       
// PB0_02输出口
#define  BEEP_on		GPIO_Write_High(GPIOB0, 2)	
#define  BEEP_off	    GPIO_Write_Low(GPIOB0, 2)	
#define  BEEPDir_OUT	GPIO_Init(GPIOB0, 2,0)         
//#define  BEEPDir_Ad		SET_PORT_AD(2,4)

// PB0_03输出口
#define  Hot_on		  GPIO_Write_High(GPIOB0, 3)	
#define  Hot_off	  GPIO_Write_Low(GPIOB0, 3)	
#define  HotDir		  GPIO_Init(GPIOB0, 3,0)            
// PA0_13输出口
#define  BLed_on	  GPIO_Write_High(GPIOA0,13)		
#define  BLed_off	  GPIO_Write_Low(GPIOA0,13)	
#define  BLed	      GPIO_Read_Output(GPIOA0, 13)
#define  BLedDir	  GPIO_Init(GPIOA0,13,0)            

//#define  UART_RX	P3_1
//#define  UART_TX	P3_0
// PB0_04输入口
#define  RfIn	          GPIO_Read_Status(GPIOB0, 4)
#define  RfInDir	      {GPIO_Init(GPIOB0, 4,1);GPIO_PullHigh_Init(GPIOB0, 4);}            

extern U8_T  g_byTransmmitflag;
extern U8_T  g_byUpgradeflag;
extern U32_T g_dwFirmwareSize;
extern U8_T  g_byVersionflag;
extern U32_T Flag1;
extern U32_T Flag2;
extern U8_T BeepLen;
extern U8_T Run_Step;
extern U8_T SetDly;
extern U8_T Time2500us;
extern U8_T Time_10mS;
extern U8_T Time100ms;
extern U8_T Time_50mS;
extern U8_T FlashTime;
extern U8_T Time_500mS;
extern U8_T Time1s;
extern U8_T Time_1d2S;
extern U8_T Time_1Min;
extern U8_T Reset_1Min;
extern U8_T Disp_Temp;
extern U8_T DispBuf[9];
extern U8_T Timer_On_Buf;
extern U8_T TimerH;
extern U8_T TimerM;
extern U8_T Time1h;
extern U8_T SetCnt;
extern U8_T Flash_Step;
extern U8_T KeyVal;
extern U8_T Flash_Lengh;
extern U8_T Time_Tx;
extern U16_T  DlyOffBled;
extern U16_T  Timer_Swi;

//---------------------------WIFI
extern U8_T Rx_Buf_Sum;
extern U8_T Tx_Buf_Sum;
extern U16_T Rx_Count;
extern U8_T Tx_Count;
extern U8_T RxDoneCnt;
extern U8_T Sms_Buf;
extern U8_T Wifi_State;
extern U8_T Led_Cnt;
extern U8_T TxSTRT_Cnt;
//-----------------
//---------------------------AD
extern U8_T Set_Temp_Buf;
extern signed char Room_Temp_Buf;
extern U8_T Goto_Temp;
extern U8_T Index;
extern U8_T AD_Count;
extern U8_T AD_Dly;
//-----------------
extern U16_T  AD_Buf;
extern U16_T  AD_Value[2];
extern U16_T  TempVer;
extern U16_T  Temp16;
extern U32_T AD_Data_Sum;
//---------------------------
extern U8_T Tx_Buf[64];
extern U8_T Rx_Buf[MAX_BUFF];
extern signed char AdjTmp;
extern U8_T Time1m;
extern U16_T  HotOnTimeSum;
extern U16_T  HotOffTimeSum;
extern U8_T ClkH;
extern U8_T ClkM;
extern U8_T GetClkTimeOut;
extern U8_T SysTime;
extern U8_T PeiWangTimer;
extern U8_T Rx_Code_Data[2];
extern U8_T Rx_Code_Buf[3];
extern U8_T CdData[3];//
extern U8_T CdDataBak[3];
extern U8_T CdSample,CdBitCn;//



extern U8_T FlagGetBit(U8_T index);
extern void FlagSetBit(U8_T index);
extern void FlagClearBit(U8_T index);
extern void FlagReverseBit(U8_T index);


/***********************************************************************
Function Statement
***********************************************************************/
void Sfr_Init();
void Ram_Init();
void Delay_Xus(void);
void Bled_On(void);
void SetDisplay(void);
void KeySleep(void);
void ScanKey(void);
void Uart_Rx(void);
void Uart_Tx(void);
extern	void Uart_Tx_Temp(void);
extern	void Uart_Tx_Rx(void);
void Uart_Tx_Time(void);
void Uart_Tx_Swi(void);
void Uart_Tx_SetTemp(void);
void ht_wr_4bit(unsigned char addr, unsigned char m_data);
void LcdInit(void);
void Lcd_Disp(void);
void Key_Power_Switch(void);
void SetBeep(void);
void Key_Add(void);//
void Key_Dec(void);//
void PwrOff(void);
void Send_Data_Pid(void);

void jump_app(void);
void rst_mcu(void);
void feed_IWDT(void);
void enable_IWDT(void);

#endif