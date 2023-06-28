/* Includes ------------------------------------------------------------------*/
#include "apt32f102_countera.h"
/* defines -------------------------------------------------------------------*/

/* externs--------------------------------------------------------------------*/


/*************************************************************/
//Count A RESET,CLEAR ALL REGISTER
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/  
void COUNT_DeInit(void)
{
    CA0->CADATAH = CA_RESET_VALUE;
    CA0->CADATAL = CA_RESET_VALUE;
    CA0->CACON   = CA_RESET_VALUE;
    CA0->INTMASK = CA_RESET_VALUE;
}

/*************************************************************/
//CountA Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void COUNTA_Int_Enable(void)
{
    INTC_ISER_WRITE(CA_INT);    
}
/*************************************************************/
//CountA Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void COUNTA_Int_Disable(void)
{
    INTC_ICER_WRITE(CA_INT);    
}
/*************************************************************/
//CountA Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void COUNTA_Wakeup_Enable(void)
{
    INTC_IWER_WRITE(CA_INT);    
}
/*************************************************************/
//CountA Interrupt enable
//EntryParameter:NONE
//ReturnValue:NONE
/*************************************************************/
void COUNTA_Wakeup_Disable(void)
{
    INTC_IWDR_WRITE(CA_INT);    
}
/*************************************************************/
//CountA Init
//EntryParameter:Data_H,Data_L,INT_Mode,DIVx,Mode,Carrier,OSP_Mode
//Data_H,Data_L:0x0000~0xFFFF
//INT_MODE:Period_NA/Period_H/Period_L/Period_H_L
//DIVx:DIV1/DIV2/DIV4/DIV8
//Mode:ONESHOT_MODE / REPEAT_MODE
//Carrier:CARRIER_OFF / CARRIER_ON
//OSP_Mode:OSP_LOW /OSP_HIGH
//ReturnValue:NONE
/*************************************************************/  
void COUNTA_Init(uint32_t Data_H,uint32_t Data_L,CA_INT_TypeDef INT_Mode,
                     CA_CLKDIV_TypeDef DIVx,CA_Mode_TypeDef Mode,CA_CARRIER_TypeDef Carrier,
                     CA_OSP_TypeDef OSP_Mode)  
{
	COUNT_DeInit();
    CA0->CADATAH = Data_H;//0x0000~0xFFFF      time(us)/(1/F Mhz) eg:10us/(1/4)=10us/0.25us=40,Data_H=40
	CA0->CADATAL = Data_L;//0x0000~0xFFFF
    CA0->CACON = DIVx | Mode | Carrier  | OSP_Mode ;
    CA0->INTMASK = INT_Mode ;
}
/*************************************************************/
//CountA config
//EntryParameter:STROBE,Pend_val,Match_val,Stat_val,ENVELOPE
//ReturnValue:NONE
/*************************************************************/  
void COUNTA_Config(CA_STROBE_TypeDef STROBE,CA_PENDREM_TypeDef Pend_CON,
                        CA_MATCHREM_TypeDef Match_CON,CA_REMSTAT_TypeDef Stat_CON,CA_ENVELOPE_TypeDef ENVELOPE )
{
    CA0->CACON = CA0->CACON | STROBE | Pend_CON | Match_CON | Stat_CON | ENVELOPE;
}
/*************************************************************/
//CountA Start
//EntryParameter:none
//ReturnValue:NONE
/*************************************************************/  
void COUNTA_Start(void)
{
    CA0->CACON=(CA0->CACON&0xFFFFFFF3)|0X04;                    //bit 2,This bit be cleared automatically
}
/*************************************************************/
//CountA Stop
//EntryParameter:none
//ReturnValue:NONE
/*************************************************************/  
void COUNTA_Stop(void)
{
    CA0->CACON=(CA0->CACON&0xFFFFFFF7)|0X08;                    //bit 4
}
/*************************************************************/
//CountA data update
//EntryParameter:none
//ReturnValue:NONE
/*************************************************************/  
void COUNTA_Data_Update(uint32_t Data_H,uint32_t Data_L)
{
    CA0->CADATAH = Data_H;//0x0000~0xFFFF      					time(us)/(1/F Mhz) eg:10us/(1/4)=10us/0.25us=40,Data_H=40
	CA0->CADATAL = Data_L;//0x0000~0xFFFF
	CA0->CACON = CA0->CACON | (1ul<<16);
}
/*************************************************************/
//CountA Stop
//EntryParameter:COUNTA_IO_G0
//COUNTA_IO_G:0 PA0.07  1 PA0.03  2 PB0.02
//ReturnValue:NONE
/*************************************************************/  
void COUNTA_IO_Init(CA_COUNTAIO_TypeDef COUNTA_IO_G)
{
	if(COUNTA_IO_G==0)
	{
		GPIOB0->CONLR=(GPIOA0->CONLR & 0XFFFFFF0F)|0x00000040;									//BUZZ (PB0.01->AF1)
	}
	else if(COUNTA_IO_G==1)
	{
		GPIOA0->CONLR=(GPIOA0->CONLR & 0XFF0FFFFF)|0x00600000;									//BUZZ (PA0.05->AF4)
	}
	else if(COUNTA_IO_G==2)
	{
		GPIOA0->CONHR=(GPIOA0->CONHR & 0XFFFF0FFF)|0x00007000;									//BUZZ (PA0.11->AF3)
	}
}