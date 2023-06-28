
//*******************************************************
//*******************************************************
//*****************************************************
/*						  ---------------- 
		        AD14/P23 | 1			24|P15/AD9
	            AD15/P24 | 2			23|P17/AD12
	  			     P30 | 3			22|P16/AD10
	  				 P31 | 4			21|P14/AD8
  	 			AD17/P06 | 5			20|P13/AD7
   				AD18/P07 | 6			19|P12/AD6
  				INT0/P32 | 7			18|P11/AD5
    			INT1/P33 | 8			17|P10/AD4
   					 VSS | 9			16|P37
  					 Vdd | 10			15|P21/AD3
  				AD21/P02 | 11			14|P20/AD2
   		 		AD22/P03 | 12			13|P04/AD0
		  				 ------------------
*/
//*****************************************************
//*******************************************************
//*******************************************************

#include "define.h"

	
#define  HtCs_set		    GPIO_Write_High(GPIOB0, 5)
#define  HtCs_clear	    GPIO_Write_Low(GPIOB0, 5)
#define  HtCsDirOut   	GPIO_Init(GPIOB0, 5,0)         // PB0_05输出口

#define  HtWr_set		    GPIO_Write_High(GPIOA0, 14)
#define  HtWr_clear	    GPIO_Write_Low(GPIOA0, 14)
#define  HtWrDirOut	    GPIO_Init(GPIOA0, 14, 0)    // PA0_14输出口

#define  HtDt_set		    GPIO_Write_High(GPIOA0, 15)
#define  HtDt_clear	    GPIO_Write_Low(GPIOA0, 15)
#define  HtDtDirOut	    GPIO_Init(GPIOA0, 15, 0)      // PA0_15输出口



#define	 LCD_ON					0x8060		/* */
#define	 LCD_OFF				0x8040		/* */
#define	 SYS_DIS				0x8000		/* */
#define	 SYS_EN					0x8020		/* */
#define	 TONE_ON				0x8120		/* */
#define	 TONE_OFF				0x8100		/* */
#define	 RC_INT 				0x8300		/* */
#define	 TONE_ON				0x8120		/* */
#define	 BISE3COM4      		0x8520		/* */
#define	 BISE3COM3     			0x84a0		/* */

//***************************************************
//***************************************************

void	HtBitsWr(unsigned int Val,unsigned char  Bits)
{	
    HtDtDirOut;
    HtWrDirOut;
    HtCsDirOut;
	HtCs_clear;//HtCs=0;
	HtWr_set;//HtWr=1;
	for(;Bits>0;Bits--)
	{
        if(Val&0x8000)
         {
			 HtDt_set;//HtDt=1; 
		 }
        else
         {
			 HtDt_clear;//HtDt=0; 
		 }
		HtWr_clear;//HtWr=0;
		Val<<=1;
		HtWr_set;//HtWr=1;
	}
	HtCs_set;//HtCs=1;
}

//***************************************************
//***************************************************

void	ht_wr_4bit(uchar addr,uchar m_data)
{
    uint i;
    m_data&=0xf;
    i=addr;
    i<<=7;
    i|=0xa000;
    i|=(m_data<<3);
    HtBitsWr(i,13);
}

//***********************************************
//***********************************************
void  LcdInit(void)
{
  HtBitsWr(RC_INT,12);
  HtBitsWr(SYS_EN,12);
  HtBitsWr(BISE3COM4,12);
  HtBitsWr(LCD_ON,12);
}
//***********************************************
//***********************************************

