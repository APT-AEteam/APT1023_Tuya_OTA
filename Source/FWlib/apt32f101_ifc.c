/*
  ******************************************************************************
  * @file    apt32f102_ifc.c
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
#include "apt32f102_ifc.h"
volatile unsigned int R_INT_FlashAdd;
volatile unsigned char f_Drom_write_complete=0;
volatile unsigned char f_Drom_writing=0;
volatile unsigned char ifc_step;
/* define --------------------------------------------------------------------*/
extern void delay_nms(unsigned int t); 
/* externs--------------------------------------------------------------------*/
/*************************************************************
//ChipErase fuction
//EntryParameter:NONE
//ReturnValue:NONE
*************************************************************/
void ChipErase(void)
{
	SetUserKey;
	EnChipErase;
	StartErase;
	while(IFC->CR!=0x0);			//等待操作完成
}
/*************************************************************
//PageErase fuction
//EntryParameter:XROM_PageAdd
//XROM_PageAdd:PROM_PageAdd0~PROM_PageAdd255
//DROM_PageAdd0~DROM_PageAdd31
//ReturnValue:NONE
*************************************************************/
void PageErase(IFC_ROMSELETED_TypeDef XROM_PageAdd)
{
	SetUserKey;
	EnPageErase;
	IFC->FM_ADDR=XROM_PageAdd;
	StartErase;
	while(IFC->CR!=0x0);
}
/*************************************************************
//Enable or Disable IFC Interrupt when Operate FlashData 
//EntryParameter:FlashAdd、DataSize、*BufArry
//ReturnValue:NONE
*************************************************************/
//PROM一次最多写256BYTE
//DROM一次最多写64BYTE
//中断模式需要多个循环查询才能完成
void Page_ProgramData_int(unsigned int FlashAdd,unsigned int DataSize,volatile unsigned char *BufArry)
{
//	int i,DataBuffer;
//	if(!f_Drom_writing)
//	{
//		f_Drom_writing=1;
//		R_INT_FlashAdd=FlashAdd;
//		ifc_step=0;
//		//页缓存擦除 1
//		SetUserKey;
//		IFC->CMR=0x07;					//页缓存擦除
//		IFC->FM_ADDR=FlashAdd;
//		IFC->CR=0X01;					//Start Program
//		while(IFC->CR!=0x0);			//等待操作完成
//		//向写缓存中写数据 2
//		for(i=0;i<((DataSize+3)/4);i++)   //sizeof structure
//		{
//			DataBuffer=*BufArry+(*(BufArry+1)<<8)+(*(BufArry+2)<<16)+(*(BufArry+3)<<24);
//			*(volatile unsigned int *)(FlashAdd+4*i)=DataBuffer;
//			BufArry  +=4;
//		}
//		//预编程操作设定 3
//		SetUserKey;
//		IFC->CMR=0x06;					//预编程操作设定
//		IFC->FM_ADDR=FlashAdd;
//		IFC->CR=0X01;					//Start Program
//		while(IFC->CR!=0x0);			//等待操作完成
//		//执行预编程 4
//		SetUserKey;
//		IFC->CMR=0x01;					//执行预编程
//		IFC->FM_ADDR=FlashAdd;			//
//		IFC->CR=0X01;					//Start Program
//	}
}
//一般模式，调用一次完成，会在程序中延时4.2MS
void Page_ProgramData(unsigned int FlashAdd,unsigned int DataSize,volatile unsigned char *BufArry)
{
//	int i,DataBuffer;
//
//	//页缓存擦除 1
//	SetUserKey;
//	IFC->CMR=0x07;					//页缓存擦除
//	IFC->FM_ADDR=FlashAdd;
//	IFC->CR=0X01;					//Start Program
//	while(IFC->CR!=0x0);			//等待操作完成
//	//向写缓存中写数据 2
//	for(i=0;i<((DataSize+3)/4);i++)   //sizeof structure
//	{
//		DataBuffer=*BufArry+(*(BufArry+1)<<8)+(*(BufArry+2)<<16)+(*(BufArry+3)<<24);
//		*(volatile unsigned int *)(FlashAdd+4*i)=DataBuffer;
//		BufArry  +=4;
//	}
//	//预编程操作设定 3
//	SetUserKey;
//	IFC->CMR=0x06;					//预编程操作设定
//	IFC->FM_ADDR=FlashAdd;
//	IFC->CR=0X01;					//Start Program
//	while(IFC->CR!=0x0);			//等待操作完成
//	//执行预编程 4
//	SetUserKey;
//	IFC->CMR=0x01;					//执行预编程
//	IFC->FM_ADDR=FlashAdd;			//
//	IFC->CR=0X01;					//Start Program
//	while(IFC->RISR!=PEP_END_INT);			//等待操作完成
//	//页擦除 5
//	SetUserKey;
//	IFC->CMR=0x02;					//页擦除
//	IFC->FM_ADDR=FlashAdd;			//
//	IFC->CR=0X01;					//Start Program
//	while(IFC->RISR!=ERS_END_INT);			//等待操作完成
//	//将页缓存的数据写入闪存中 6
//	SetUserKey;
//	IFC->CMR=0x01;					//将页缓存的数据写入闪存中
//	IFC->FM_ADDR=FlashAdd;		//
//	IFC->CR=0X01;					//Start Program
//	while(IFC->RISR!=RGM_END_INT);			//等待操作完成
}



//////////////////////////lhy test //////////////////////////////////////
//////////////////////////write one word/////////////////////////////
void ProgramData_Word(unsigned int  FlashAdd,unsigned int DataSize,volatile unsigned char *BufArry)
{
	int i,DataBuffer;
	
	U8_T tempbuff[256] = {0};
	unsigned int  PageStartAddr  = 0;
	unsigned int  PageSize = 0;
	
	if((FlashAdd & 0x10000000) == 0x10000000)//drom 页大小64 Bytes
	{
		PageSize = 0x40;
	}
	else//prom  页大小256 Bytes
	{
		PageSize = 0x100;
	}
	
	//先把当前页的数据都读出来保存至临时buff
	PageStartAddr = FlashAdd / PageSize * PageSize;
	ReadDataArry(PageStartAddr, PageSize, tempbuff);
	
	//替换索要写入的数据位置
	for(i = FlashAdd - PageStartAddr; i < DataSize+(FlashAdd - PageStartAddr); i++ )
	{
		tempbuff[i] = *(BufArry+i- (FlashAdd - PageStartAddr));
	}

	//页缓存擦除 1
	SetUserKey;
	IFC->CMR=0x07;					//页缓存擦除
	IFC->FM_ADDR=FlashAdd;
	IFC->CR=0X01;					//Start Program
	while(IFC->CR!=0x0);			//等待操作完成
	
	
	//向写缓存中写数据 2
	for(i = 0; i < ((PageSize+3)/4); i++)   //sizeof structure
	{
		DataBuffer = tempbuff[0+4*i] + (tempbuff[1+4*i]<<8) + (tempbuff[2+4*i]<<16) + (tempbuff[3+4*i]<<24);
		*(volatile unsigned int  *)(PageStartAddr+4*i) = DataBuffer;
		//tempbuff  += 4;
	}
	
	
	//预编程操作设定 3
	SetUserKey;
	IFC->CMR=0x06;					//预编程操作设定
	IFC->FM_ADDR=FlashAdd;
	IFC->CR=0X01;					//Start Program
	while(IFC->CR!=0x0);			//等待操作完成
	//执行预编程 4
	SetUserKey;
	IFC->CMR=0x01;					//执行预编程
	IFC->FM_ADDR=FlashAdd;			//
	IFC->CR=0X01;					//Start Program
	while(IFC->RISR!=PEP_END_INT);			//等待操作完成
	//页擦除 5
	SetUserKey;
	IFC->CMR=0x02;					//页擦除
	IFC->FM_ADDR=FlashAdd;			//
	IFC->CR=0X01;					//Start Program
	while(IFC->RISR!=ERS_END_INT);			//等待操作完成
	//将页缓存的数据写入闪存中 6
	SetUserKey;
	IFC->CMR=0x01;					//将页缓存的数据写入闪存中
	IFC->FM_ADDR=FlashAdd;		//
	IFC->CR=0X01;					//Start Program
	while(IFC->RISR!=RGM_END_INT);			//等待操作完成
}








/*************************************************************
// ReadFlashData fuction return Data arry save in Flash
//EntryParameter:RdStartAdd、DataLength、*DataArryPoint
//ReturnValue:NONE
*************************************************************/
void ReadDataArry(unsigned int RdStartAdd,unsigned int DataLength,volatile unsigned char *DataArryPoint)
{
	unsigned int i,Buffer;
	//delay_nms(1);
	for(i=0;i<((DataLength+3)/4);i++)
	{
		Buffer=*(volatile unsigned int *)RdStartAdd;
		*DataArryPoint=Buffer;
		*(DataArryPoint+1)=Buffer>>8;
		*(DataArryPoint+2)=Buffer>>16;
		*(DataArryPoint+3)=Buffer>>24;
		RdStartAdd +=4;
		DataArryPoint +=4;
	}
}
/*************************************************************
//Enable or Disable IFC Interrupt when Operate FlashData 
//EntryParameter:IFC_INT_x
//IFC_INT_x:ERS_END_INT,RGM_END_INT,PEP_END_INT,PROT_ERR_INT,UDEF_ERR_INT,ADDR_ERR_INT,OVW_ERR_INT
//ReturnValue:NONE
*************************************************************/
void IFC_interrupt_CMD(FunctionalStatus NewState ,IFC_INT_TypeDef IFC_INT_x)
{
	if(NewState != DISABLE)
	{
		IFC->IMCR =IFC->IMCR|IFC_INT_x;
	}
	else 
	{
		IFC->IMCR =IFC->IMCR & (~IFC_INT_x);
	}
}
/*************************************************************/
//IFC Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void IFC_Int_Enable(void)
{
    IFC->ICR=0Xf007;					//CLAER IFC INT status
	INTC_ISER_WRITE(IFC_INT);    
}

/*************************************************************/
//IFC Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void IFC_Int_Disable(void)
{
    INTC_ICER_WRITE(IFC_INT);    
}
/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/