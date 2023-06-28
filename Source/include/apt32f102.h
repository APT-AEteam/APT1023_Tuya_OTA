/*
  ******************************************************************************
  * @file    apt32f102_initial.c
  * @author  APT AE Team
  * @version V1.07
  * @date    2018/11/01
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

/* Define to prevent recursive inclusion -------------------------------------*/ 
#ifndef _apt32f102_H
#define _apt32f102_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102_types_local.h"
#include "apt32f102_ck801.h"

/**
@brief CK801 bits Structure
*/
typedef struct {
	volatile unsigned int ReservedA[4];		//0xE000E000
	volatile unsigned int CORET_CSR;			//0xE000E010
	volatile unsigned int CORET_RVR;			//0xE000E014
	volatile unsigned int CORET_CVR;			//0xE000E018
	volatile unsigned int CORET_CALIB;		//0xE000E01C
	volatile unsigned int ReservedB[56];		//0xE000E020
	volatile unsigned int ISER;				//0xE000E100
	volatile unsigned int ReservedC[15];		//
	volatile unsigned int IWER;				//0xE000E140
	volatile unsigned int ReservedD[15];		//
	volatile unsigned int ICER;				//0xE000E180
	volatile unsigned int ReservedE[15];		//
	volatile unsigned int IWDR;				//0xE000E1C0
	volatile unsigned int ReservedF[15];		//
	volatile unsigned int ISPR;				//0xE000E200
	volatile unsigned int ReservedG[31];		//
	volatile unsigned int ICPR;				//0xE000E280
	volatile unsigned int ReservedH[31];		//
	volatile unsigned int IABR;				//0xE000E300
	volatile unsigned int ReservedI[63];		//
	volatile unsigned int IPR[8];			//0xE000E400 ~ 0xE000E41C
	volatile unsigned int ReservedJ[504];	//
	volatile unsigned int ISR; 				//0xE000EC00
	volatile unsigned int IPTR; 				//0xE000EC04
} CSP_CK801_T;
/**
@brief IFC bits Structure
*/
typedef volatile struct {
	volatile unsigned int IDR ;
	volatile unsigned int CEDR ;
	volatile unsigned int SRR ;
	volatile unsigned int CMR ;
	volatile unsigned int CR ;
	volatile unsigned int MR ;
	volatile unsigned int FM_ADDR ;
	volatile unsigned int Reserved ;
	volatile unsigned int KR ;
	volatile unsigned int IMCR ;
	volatile unsigned int RISR ;
	volatile unsigned int MISR ;
	volatile unsigned int ICR ;
} CSP_IFC_T ;
/**
@brief SYSCON bits Structure
*/
typedef volatile struct {                   			/*!< SYSCON Structure                         */
	volatile unsigned int IDCCR;                        /*!< 0x000: Identification & System Controller Clock Control Register */
	volatile unsigned int GCER;                         /*!< 0x004: System Controller General Control Enable Register */
	volatile unsigned int GCDR;                         /*!< 0x008: System Controller General Control Disable Register */
	volatile unsigned int GCSR;                         /*!< 0x00C: System Controller General Control Status Register */
	volatile unsigned int CKST;                         /*!< 0x010*/
	volatile unsigned int RAMCHK;                       /*!< 0x014*/
	volatile unsigned int EFLCHK;                       	/*!< 0x018*/
	volatile unsigned int SCLKCR;                       /*!< 0x01C: System Controller System Clock Selection & Division Register */
	volatile unsigned int PCLKCR;                       /*!< 0x020: System Controller Peripheral Clock Selection & Division Register */
	volatile unsigned int _RSVD0;                       /*!< 0x024*/
	volatile unsigned int PCER0;                        /*!< 0x028: System Controller Peripheral Clock Enable Register */
	volatile unsigned int PCDR0;                        /*!< 0x02C: System Controller Peripheral Clock Disable Register */
	volatile unsigned int PCSR0;                        /*!< 0x030: System Controller Peripheral Clock Status Register */
	volatile unsigned int PCER1;                        /*!< 0x034: System Controller Peripheral Clock Enable Register */
	volatile unsigned int PCDR1;                        /*!< 0x038: System Controller Peripheral Clock Disable Register */
	volatile unsigned int PCSR1;                        /*!< 0x03C: System Controller Peripheral Clock Status Register */
	volatile unsigned int OSTR;                         /*!< 0x040: System Controller External OSC Stable Time Control Register */
	volatile unsigned int _RSVD1;                       /*!< 0x044: System Controller PLL Stable Time Control Register */
	volatile unsigned int _RSVD2;                       /*!< 0x048: System Controller PLL PMS Value Control Register */
	volatile unsigned int LVDCR;                        /*!< 0x04C: System Controller LVD Control Register */
	volatile unsigned int CLCR;                         /*!< 0x050: System Controller IMOSC Fine Adjustment Register*/
	volatile unsigned int PWRCR;                        /*!< 0x054: System Controller Power Control Register */
	volatile unsigned int PWRKEY;                       /*!< 0x058: System Controller Power Control Register */
	volatile unsigned int _RSVD3;                       /*!< 0x05C: */
	volatile unsigned int _RSVD4;                       /*!< 0x060: */
	volatile unsigned int OPT1;                         /*!< 0x064: System Controller OSC Trim Control Register */
	volatile unsigned int OPT0;                         /*!< 0x068: System Controller Protection Control Register */
	volatile unsigned int WKCR;                         /*!< 0x06C: System Controller Clock Quality Check Control Register */
	volatile unsigned int _RSVD5;                       /*!< 0x070: System Controller Clock Quality Check Control Register */
	volatile unsigned int IMER;                         /*!< 0x074: System Controller Interrupt Enable Register */
	volatile unsigned int IMDR;                         /*!< 0x078: System Controller Interrupt Disable Register */
	volatile unsigned int IMCR;                         /*!< 0x07C: System Controller Interrupt Mask Register */
	volatile unsigned int IAR;                          /*!< 0x080: System Controller Interrupt Active Register */
	volatile unsigned int ICR;                          /*!< 0x084: System Controller Clear Status Register */
	volatile unsigned int RISR;                         /*!< 0x088: System Controller Raw Interrupt Status Register */
	volatile unsigned int MISR;                          /*!< 0x08C: System Controller Raw Interrupt Status Register */
	volatile unsigned int RSR;                          /*!< 0x090: System Controller Raw Interrupt Status Register */
	volatile unsigned int EXIRT;                        /*!< 0x094: System Controller Reset Status Register */
	volatile unsigned int EXIFT;                        /*!< 0x098: System Controller External Interrupt Mode 1 (Positive Edge) Register */
	volatile unsigned int EXIER;                        /*!< 0x09C: System Controller External Interrupt Mode 2 (Negative Edge) Register */
	volatile unsigned int EXIDR;                        /*!< 0x0A0: System Controller External Interrupt Enable Register */
	volatile unsigned int EXIMR;                        /*!< 0x0A4: System Controller External Interrupt Disable Register */
	volatile unsigned int EXIAR;                        /*!< 0x0A8: System Controller External Interrupt Mask Register */
	volatile unsigned int EXICR;                        /*!< 0x0AC: System Controller External Interrupt Active Register */
	volatile unsigned int EXIRS;                        /*!< 0x0B0: System Controller External Interrupt Clear Status Register */
	volatile unsigned int IWDCR;                        /*!< 0x0B4: System Controller Independent Watchdog Control Register */
	volatile unsigned int IWDCNT;                       /*!< 0x0B8: SystCem Controller Independent Watchdog Counter Value Register */
	volatile unsigned int IWDEDR;                       /*!< 0x0BC: System Controller Independent Watchdog Enable/disable Register*/
	volatile unsigned int IOMAP0;                        /*!< 0x0C0: Customer Information Content mirror of 1st byte*/
	volatile unsigned int IOMAP1;                        /*!< 0x0C4: Customer Information Content mirror of 1st byte*/
	volatile unsigned int CINF0;                        /*!< 0x0C8: Customer Information Content mirror of 1st byte*/
	volatile unsigned int CINF1;                        /*!< 0x0CC: Customer Information Content mirror of 1st byte*/
	volatile unsigned int FINF0;                        /*!< 0x0D0: Customer Information Content mirror of 1st byte*/
	volatile unsigned int FINF1;                        /*!< 0x0D4: Customer Information Content mirror of 1st byte*/
	volatile unsigned int FINF2;                        /*!< 0x0D8: Customer Information Content mirror of 1st byte*/
	volatile unsigned int _RSVD6;                        /*!< 0x0DC: Customer Information Content mirror of 1st byte*/
	volatile unsigned int ERRINF;                       /*!< 0x0E0:*/
	volatile unsigned int UID0 ;                        /*!< 0x0E4: Customer Information Content mirror of 1st byte*/
	volatile unsigned int UID1 ;                        /*!< 0x0E8: Customer Information Content mirror of 1st byte*/
	volatile unsigned int UID2 ;                        /*!< 0x0EC: Customer Information Content mirror of 1st byte*/
	volatile unsigned int PWROPT;                       /*!< 0x0F0: Power recovery timmming control */
	volatile unsigned int EVTRG;                       /*!< 0x0F4: Trigger gen                                    */
	volatile unsigned int EVPS;                       /*!< 0x0F8: Trigger prs                                    */
	volatile unsigned int EVSWF;                       /*!< 0x0FC: Trigger software force                         */
	volatile unsigned int UREG0;                       /*!< 0x100: User defined reg0                              */
	volatile unsigned int UREG1;                       /*!< 0x104: User defined reg1                              */
	volatile unsigned int UREG2;                       /*!< 0x108: User defined reg0                              */
	volatile unsigned int UREG3;                       /*!< 0x10C: User defined reg1                              */
} CSP_SYSCON_T;  
/**
@brief ETCB  bits Structure
*/
 typedef volatile struct
 {
    volatile unsigned int  EN;            /* ETCB Enable                            */
    volatile unsigned int  SWTRG;         /* ETCB Software Trigger Generator         */
    volatile unsigned int  CH0CON0;       /* ETCB Channel 0 Control Register 0       */
    volatile unsigned int  CH0CON1;       /* ETCB Channel 0 Control Register 1       */
    volatile unsigned int  CH1CON0;       /* ETCB Channel 1 Control Register 0       */
    volatile unsigned int  CH1CON1;       /* ETCB Channel 1 Control Register 1       */
    volatile unsigned int  CH2CON0;       /* ETCB Channel 2 Control Register 0       */
    volatile unsigned int  CH2CON1;       /* ETCB Channel 2 Control Register 1       */
	volatile unsigned int  _RSVD0;
	volatile unsigned int  _RSVD1;
	volatile unsigned int  _RSVD2;
	volatile unsigned int  _RSVD3;
    volatile unsigned int  CH3CON;       /*  ETCB Channel 3 Control Register        */
	volatile unsigned int  CH4CON;       /*  ETCB Channel 3 Control Register        */
	volatile unsigned int  CH5CON;       /*  ETCB Channel 3 Control Register        */
	volatile unsigned int  CH6CON;       /*  ETCB Channel 3 Control Register        */
	volatile unsigned int  CH7CON;       /*  ETCB Channel 3 Control Register        */
 } CSP_ETCB_T, *CSP_ETCB_PTR;    
/**
@brief TKEY  bits Structure
*/
typedef volatile struct
{
   volatile unsigned int  TCH_CCR;               /* Control Register */
   volatile unsigned int  TCH_CON0;               /* Control Register */
   volatile unsigned int  TCH_CON1;               /* Control Register */
   volatile unsigned int  TCH_SCCR;               /* Hardmacro control    */
   volatile unsigned int  TCH_SENPRD;            /* Sensing target value */
   volatile unsigned int  TCH_VALBUF;            /* Reference value capture value*/
   volatile unsigned int  TCH_SENCNT;            /* Sensing counter value*/
   volatile unsigned int  TCH_TCHCNT;            /* Reference counter value*/
   volatile unsigned int  TCH_THR;                /* Match Status           */
   volatile unsigned int  Reserved0;			
   volatile unsigned int  TCH_RISR;               /* Interrupt Enable       */
   volatile unsigned int  TCH_IER;               /* Interrupt Clear        */
   volatile unsigned int  TCH_ICR;            /* Sensing target value */
   volatile unsigned int  TCH_RWSR;            /* Reference value capture value*/
   volatile unsigned int  TCH_OVW_THR;            /* Sensing counter value*/
   volatile unsigned int  TCH_OVF;            /* Reference counter value*/
   volatile unsigned int  TCH_OVT;                /* Match Status           */
   volatile unsigned int  TCH_SYNCR;               /* Interrupt Enable       */
   volatile unsigned int  TCH_EVTRG;               /* Interrupt Clear        */
   volatile unsigned int  TCH_EVPS;            /* Sensing target value */
   volatile unsigned int  TCH_EVSWF;            /* Reference value capture value*/
   volatile unsigned int  TCH_CHVAL[18];            /* Sensing counter value*/
   volatile unsigned int  TCH_SEQCON[18];            /* Reference counter value*/
} CSP_TKEY_T, *CSP_TKEY_PTR;  
/**
@brief ADC0  bits Structure
*/    
 typedef volatile struct
 {
    volatile unsigned int  ECR;              /**< Clock Enable Register             */
    volatile unsigned int  DCR;              /**< Clock Disable Register            */
    volatile unsigned int  PMSR;             /**< Power Management Status Register  */
    volatile unsigned int  Reserved0;
    volatile unsigned int  CR;               /**< Control Register                  */
    volatile unsigned int  MR;               /**< Mode Register                     */
    volatile unsigned int  SHR;
    volatile unsigned int  CSR;              /**< Clear Status Register             */
    volatile unsigned int  SR;               /**< Status Register                   */
    volatile unsigned int  IER;              /**< Interrupt Enable Register         */
    volatile unsigned int  IDR;              /**< Interrupt Disable Register        */
    volatile unsigned int  IMR;              /**< Interrupt Mask Register           */
    volatile unsigned int  SEQ[16];          /**< Conversion Mode Register 0~11     */
    volatile unsigned int  PRI;              /**< Conversion Priority Register      */
    volatile unsigned int  TDL0;             /**< Trigger Delay control Register    */
    volatile unsigned int  TDL1;             /**< Trigger Delay control Register    */
    volatile unsigned int  SYNCR;            /**< Sync Control Register             */
    volatile unsigned int  Reserved1;           /**< Trigger Filter Control Register   */
    volatile unsigned int  Reserved2;           /**< Trigger Filter Window  Register   */
    volatile unsigned int  EVTRG;            /**< Event Trigger Control  Register   */
    volatile unsigned int  EVPS;             /**< Event Prescale Register           */
    volatile unsigned int  EVSWF;            /**< Event Softtrig Register           */
    volatile unsigned int  ReservedD[27];
    volatile unsigned int  DR[16];           /**< Convert Data Register             */
    volatile unsigned int  CMP0;             /**< Comparison Data Register             */
    volatile unsigned int  CMP1;             /**< Comparison Data Register             */
	volatile unsigned int  DRMASK; 
 } CSP_ADC12_T, *CSP_ADC12_PTR;
/**
@brief GPIOX   bits Structure
*/   
 typedef volatile struct
 {
    volatile unsigned int  CONLR;                /**< Control Low  Register                */
    volatile unsigned int  CONHR;                /**< Control High Register                */
    volatile unsigned int  WODR;                 /**< Write Output Data Register           */              
    volatile unsigned int  SODR;                 /**< Set Output Data (bit-wise) Register  */
    volatile unsigned int  CODR;                 /**< Clear Output Data (bit-wise) Register*/
    volatile unsigned int  ODSR;                 /**< Output Data Status Register          */
    volatile unsigned int  PSDR;                 /**< Pin Data Status Register             */              
    volatile unsigned int  FLTEN;         
    volatile unsigned int  PUDR;                 /**< IO Pullup_Pulldown Register          */
    volatile unsigned int  DSCR;                 /**< Output Driving Strength Register     */
    volatile unsigned int  OMCR;                 /**< Slew-rate, Open-Drain Control        */  
    volatile unsigned int  IECR;                 /**< EXI enable control                   */  
	volatile unsigned int  IEER;
	volatile unsigned int  IEDR;
 } CSP_GPIO_T, *CSP_GPIO_PTR; 

 typedef volatile struct
 {
	volatile unsigned int  IGRPL;                	/**< EXI group control                   */
    volatile unsigned int  IGRPH;	                /**< EXI group control               */
	volatile unsigned int  IGREX;
    volatile unsigned int  IO_CLKEN;	
 } CSP_IGRP_T, *CSP_IGRP_PTR;     
/**
@brief UART0~UART1  bits Structure
*/    
 typedef volatile struct
 {
    volatile unsigned int  DATA;               /**< Write and Read Data Register    */
    volatile unsigned int  SR;                 /**< Status Register                 */
    volatile unsigned int  CTRL;                /**< Control Register                */
    volatile unsigned int  ISR;                /**< Interrupt Status Register       */
    volatile unsigned int  BRDIV;               /**< Baud Rate Generator Register    */
    volatile unsigned int  ReservedA[20];
 } CSP_UART_T, *CSP_UART_PTR;   
/**
@brief SPI0  bits Structure
*/  
typedef struct
{
	volatile unsigned int  CR0;			/**< Control Register 0 */
	volatile unsigned int  CR1;			/**< Control Register 1 */
	volatile unsigned int  DR; 			/**< Receive FIFO(read) and transmit FIFO data register(write) */
	volatile unsigned int  SR;				/**< Status register */
	volatile unsigned int  CPSR;			/**< Clock prescale register */
	volatile unsigned int  IMSCR;			/**< Interrupt mask set and clear register */
	volatile unsigned int  RISR;			/**< Raw interrupt status register */
	volatile unsigned int  MISR;			/**< Masked interrupt status register */
	volatile unsigned int  ICR;			/**< Interrupt clear register */
} CSP_SSP_T, *CSP_SSP_PTR;
/**
@brief SIO0  bits Structure
*/
typedef struct
{
	volatile unsigned int  CR;			
	volatile unsigned int  TXCR0;			
	volatile unsigned int  TXCR1; 			
	volatile unsigned int  TXBUF;			
	volatile unsigned int  RXCR0;			
	volatile unsigned int  RXCR1;	
	volatile unsigned int  RXCR2;		
	volatile unsigned int  RXBUF;			
	volatile unsigned int  RISR;			
	volatile unsigned int  MISR;
	volatile unsigned int  IMCR;
	volatile unsigned int  ICR;		
} CSP_SIO_T, *CSP_SIO_PTR;
/**
@brief I2C0  bits Structure
*/      
 typedef volatile struct
 {
    unsigned int  CR;           /* I2C Control                            */
    unsigned int  TADDR;           /* I2C Target Address                     */
    unsigned int  SADDR;           /* I2C Slave Address                      */
    unsigned int  ReservedD;      
    unsigned int  DATA_CMD;      /* I2C Rx/Tx Data Buffer and Command      */
    unsigned int  SS_SCLH;       /* I2C Standard Speed SCL High Count      */
    unsigned int  SS_SCLL;       /* I2C Standard Speed SCL Low  Count      */
    unsigned int  FS_SCLH;       /* I2C Fast mode and Fast Plus SCL High Count*/
    unsigned int  FS_SCLL;       /* I2C Fast mode and Fast Plus SCL Low  Count*/
    unsigned int  ReservedA;      /* I2C High Speed SCL High Count          */
    unsigned int  ReservedC;      /* I2C High Speed SCL Low  Count          */
    unsigned int  RX_FLSEL;      /* I2C Receive FIFO Threshold             */
    unsigned int  TX_FLSEL;      /* I2C Transmit FIFO Threshold            */
    unsigned int  RX_FL;         /* I2C Receive  FIFO Level                */
    unsigned int  TX_FL;         /* I2C Transmit FIFO Level                */
    unsigned int  ENABLE;        /* I2C Enable                             */
    unsigned int  STATUS;        /* I2C Status                             */
    unsigned int  ReservedB;    /* I2C Enable Status                      */
    unsigned int  SDA_TSETUP;    /* I2C SDA Setup Time                     */
    unsigned int  SDA_THOLD;     /* I2C SDA hold time length               */
    unsigned int  SPKLEN;     /* I2C SS and FS Spike Suppression Limit  */
    //unsigned int  HS_SPKLEN;     /* I2C HS Spike Suppression Limit         */
    unsigned int  ReservedE;
	unsigned int  MISR;          /* I2C Masked Interrupt Status            */
    unsigned int  IMSCR;         /* I2C Interrupt Enable                   */
    unsigned int  RISR;          /* I2C Raw Interrupt Status               */
    unsigned int  ICR;           /* I2C Interrupt Clear                    */
    unsigned int  ReservedF;
    unsigned int  SCL_TOUT; 	/* I2C SCL Stuck at Low Timeout           */
    unsigned int  SDA_TOUT; 	/* I2C SDA Stuck at Low Timeout           */
    unsigned int  TX_ABRT;   	/* I2C Transmit Abort Status              */
    unsigned int  GCALL;     	/* I2C ACK General Call                   */
    unsigned int  NACK; 		/* I2C Generate SLV_DATA_NACK             */
 } CSP_I2C_T, *CSP_I2C_PTR;
/**
@brief CA0   bits Structure
*/      
 typedef struct
 {
    volatile unsigned int      CADATAH;        /**< DATA High Register            */
    volatile unsigned int      CADATAL;        /**< DATA Low Register             */
    volatile unsigned int      CACON;          /**< Control Register              */
    volatile unsigned int      INTMASK;        /**< Interrupt Mask CR             */
 } CSP_CA_T, *CSP_CA_PTR;  
/**
@brief	GPTX   bits Structure
*/   
 typedef struct
 {
	volatile unsigned int	CEDR;  		//0x0000	Clock control & ID
	volatile unsigned int	RSSR;		//0x0004	Start & Stop Ctrl
	volatile unsigned int	PSCR;		//0x0008	Clock prescaler
	volatile unsigned int	CR;  		//0x000C	Control register
	volatile unsigned int	SYNCR;		//0x0010	Synchronization control reg
	volatile unsigned int	GLDCR;		//0x0014	Global load control reg
	volatile unsigned int	GLDCFG; 	//0x0018	Global load config
	volatile unsigned int	GLDCR2;		//0x001C	Global load control reg2
	volatile unsigned int	Reserved0;		//0x0020
	volatile unsigned int	PRDR;   	//0x0024	Period reg
	volatile unsigned int	Reserved1;		//0x0028
	volatile unsigned int	CMPA;  		//0x002C	Compare Value A
	volatile unsigned int	CMPB;   	//0x0030	Compare Value B
	volatile unsigned int	Reserved2;		//0x0034
	volatile unsigned int	Reserved3;		//0x0038
	volatile unsigned int	CMPLDR;	    //0x003C	Cmp reg load control
	volatile unsigned int	CNT;      	//0x0040	Counter reg
	volatile unsigned int	AQLDR; 		//0x0044	AQ reg load control
	volatile unsigned int	AQCRA;      //0x0048	Action qualify of ch-A
	volatile unsigned int	AQCRB;    	//0x004C	Action qualify of ch-B
	volatile unsigned int	Reserved4;		//0x0050
	volatile unsigned int	Reserved5;		//0x0054
	volatile unsigned int	Reserved6;		//0x0058
	volatile unsigned int	AQOSF; 		//0x005C	AQ output one-shot software forcing
	volatile unsigned int	AQCSF;      //0x0060	AQ output conti-software forcing
	volatile unsigned int	Reserved7;		//0x0064
	volatile unsigned int	Reserved8;		//0x0068
	volatile unsigned int	Reserved9;		//0x006c
	volatile unsigned int	Reserved10;		//0x0070
	volatile unsigned int	Reserved11;		//0x0074
	volatile unsigned int	Reserved12;		//0x0078
	volatile unsigned int	Reserved13;		//0x007c
	volatile unsigned int	Reserved14;		//0x0080
	volatile unsigned int	Reserved15;		//0x0084
	volatile unsigned int	Reserved16;		//0x0088
	volatile unsigned int	Reserved17;		//0x008c
	volatile unsigned int	Reserved18;		//0x0090
	volatile unsigned int	Reserved19;		//0x0094
	volatile unsigned int	Reserved20;		//0x0098
	volatile unsigned int	Reserved21;		//0x009c
	volatile unsigned int	Reserved22;		//0x00a0
	volatile unsigned int	Reserved23;		//0x00a4
	volatile unsigned int	Reserved24;		//0x00a8
	volatile unsigned int	Reserved25;		//0x00ac
	volatile unsigned int	Reserved26;		//0x00b0
	volatile unsigned int	Reserved27;		//0x00b4
	volatile unsigned int  TRGFTCR;    //0x00B8    Trigger Filter control reg
	volatile unsigned int  TRGFTWR;    //0x00BC    Trigger filter window
	volatile unsigned int  EVTRG;      //0x00C0    Event trigger setting
	volatile unsigned int  EVPS;       //0x00C4    Event presaler
	volatile unsigned int  EVCNTINIT;	//0x00C8
	volatile unsigned int  EVSWF;      //0x00CC    Event software forcing
	volatile unsigned int  RISR;       //0x00D0    Interrupt RISR
	volatile unsigned int  MISR;       //0x00D4    Interrupt MISR
	volatile unsigned int  IMCR;       //0x00D8    Interrupt IMCR
	volatile unsigned int  ICR;        //0x00DC    Interrupt clear
	volatile unsigned int  REGLINK;    //0x00E0    Register link
	
 }CSP_GPT_T,*CSP_GPT_PTR;
/**
@brief EPT0    bits Structure
*/   
 typedef struct
 {
   volatile unsigned int	CEDR;  		//0x0000	Clock control & ID
   volatile unsigned int	RSSR;		//0x0004	Start & Stop Ctrl
   volatile unsigned int	PSCR;		//0x0008	Clock prescaler
   volatile unsigned int	CR;  		//0x000C	Control register
   volatile unsigned int	SYNCR;		//0x0010	Synchronization control reg
   volatile unsigned int	GLDCR;		//0x0014	Global load control reg
   volatile unsigned int	GLDCFG; 	//0x0018	Global load config
   volatile unsigned int	GLDCR2;		//0x001C	Global load control reg2
   volatile unsigned int    HRCFG;      //0x0020
   volatile unsigned int	PRDR;   	//0x0024	Period reg
   volatile unsigned int	PHSR;     	//0x0028	Phase control reg
   volatile unsigned int	CMPA;  		//0x002C	Compare Value A
   volatile unsigned int	CMPB;   	//0x0030	Compare Value B
   volatile unsigned int	CMPC;     	//0x0034	Compare Value C 
   volatile unsigned int	CMPD;  		//0x0038	Compare Value D
   volatile unsigned int	CMPLDR;	    //0x003C	Cmp reg load control
   volatile unsigned int	CNT;      	//0x0040	Counter reg
   volatile unsigned int	AQLDR; 		//0x0044	AQ reg load control
   volatile unsigned int	AQCRA;      //0x0048	Action qualify of ch-A
   volatile unsigned int	AQCRB;    	//0x004C	Action qualify of ch-B
   volatile unsigned int	AQCRC; 		//0x0050	Action qualify of ch-C
   volatile unsigned int	AQCRD;  	//0x0054	Action qualify of ch-D
   volatile unsigned int	AQTSCR;   	//0x0058	T event selection
   volatile unsigned int	AQOSF; 		//0x005C	AQ output one-shot software forcing
   volatile unsigned int	AQCSF;      //0x0060	AQ output conti-software forcing
   volatile unsigned int	DBLDR;    	//0x0064	Deadband control reg load control
   volatile unsigned int	DBCR;       //0x0068	Deadband control reg
   volatile unsigned int	DPSCR;		//0x006C	Deadband clock prescaler
   volatile unsigned int	DBDTR;		//0x0070	Deadband rising delay control
   volatile unsigned int	DBDTF; 		//0x0074	Deadband falling delay control
   volatile unsigned int	CPCR;  		//0x0078	Chop control
   volatile unsigned int	EMSRC; 		//0x007C	EM source setting
   volatile unsigned int	EMSRC2;		//0x0080	EM source setting
   volatile unsigned int	EMPOL; 		//0x0084	EM polarity setting
   volatile unsigned int	EMECR; 		//0x0088	EM enable control
   volatile unsigned int	EMOSR;     	//0x008C	EM trip out status setting
   volatile unsigned int	Reserved;	//0x0090	Reserved
   volatile unsigned int	EMSLSR;     //0x0094	Softlock status
   volatile unsigned int	EMSLCLR;    //0x0098	Softlock clear
   volatile unsigned int   EMHLSR;     //0x009C    Hardlock status
   volatile unsigned int   EMHLCLR;    //0x00A0    Hardlock clear
   volatile unsigned int   EMFRCR;     //0x00A4    Software forcing EM
   volatile unsigned int   EMRISR;     //0x00A8    EM RISR
   volatile unsigned int   EMMISR;     //0x00AC    EM MISR
   volatile unsigned int   EMIMCR;     //0x00B0    EM masking enable
   volatile unsigned int   EMICR;      //0x00B4    EM pending clear
   volatile unsigned int   TRGFTCR;    //0x00B8    Trigger Filter control reg
   volatile unsigned int   TRGFTWR;    //0x00BC    Trigger filter window
   volatile unsigned int   EVTRG;      //0x00C0    Event trigger setting
   volatile unsigned int   EVPS;       //0x00C4    Event presaler
   volatile unsigned int   EVCNTINIT;     //0x00C8    
   volatile unsigned int   EVSWF;      //0x00CC    Event software forcing
   volatile unsigned int   RISR;       //0x00D0    Interrupt RISR
   volatile unsigned int   MISR;       //0x00D4    Interrupt MISR
   volatile unsigned int   IMCR;       //0x00D8    Interrupt IMCR
   volatile unsigned int   ICR;        //0x00DC    Interrupt clear
   volatile unsigned int   REGLINK;    //0x00E0    Register link
   volatile unsigned int   REGLINK2;   //0x00E4    Register link2
   volatile unsigned int   REGPROT;    //0x00E8    Register protection
} CSP_EPT_T, *CSP_EPT_PTR; 
/**
@brief LPT     bits Structure
*/  
 typedef volatile struct
 {
   volatile unsigned int    	CEDR;  		//0x0000	Clock control & ID
   volatile unsigned int    	RSSR;		//0x0004	Start & Stop Ctrl
   volatile unsigned int    	PSCR;		//0x0008	Clock prescaler
   volatile unsigned int    	CR;  		//0x000C	Control register
   volatile unsigned int    	SYNCR;		//0x0010	Synchronization control reg
   volatile unsigned int    	PRDR;   	//0x0024	Period reg
   volatile unsigned int    	CMP;   		//0x002C	Compare Value A
   volatile unsigned int    	CNT;      	//0x0040	Counter reg
   volatile unsigned int       TRGFTCR;    //0x00B8    Trigger Filter control reg
   volatile unsigned int       TRGFTWR;    //0x00BC    Trigger filter window
   volatile unsigned int       EVTRG;      //0x00C0    Event trigger setting
   volatile unsigned int       EVPS;       //0x00C4    Event presaler
   volatile unsigned int       EVSWF;      //0x00C8    Event software forcing
   volatile unsigned int       RISR;       //0x00CC    Interrupt RISR
   volatile unsigned int       MISR;       //0x00D0    Interrupt MISR
   volatile unsigned int       IMCR;       //0x00D4    Interrupt IMCR
   volatile unsigned int       ICR;        //0x00D8    Interrupt clear
} CSP_LPT_T, *CSP_LPT_PTR;
/**
@brief BT0     bits Structure
*/       
 typedef struct
 {
   volatile unsigned int	RSSR;  		//0x0000	Reset/Start Control
   volatile unsigned int	CR;		    //0x0004	General Control
   volatile unsigned int	PSCR;		//0x0008	Prescaler
   volatile unsigned int	PRDR; 		//0x000C	Period
   volatile unsigned int	CMP;		//0X0010
   volatile unsigned int	CNT;		//0x0014	Counter
   volatile unsigned int	EVTRG;		//0x0018	Event Trigger
   volatile unsigned int	EVPS;   	//0x001C	Event Prescaler
   volatile unsigned int	EVCNTINTI;  //0x0020	Event Counter
   volatile unsigned int   EVSWF;      //0x0024    Software force Event Trigger
   volatile unsigned int	RISR;   	//0x0028    
   volatile unsigned int	IMCR;     	//0x002C
   volatile unsigned int	MISR;  		//0x0030
   volatile unsigned int	ICR;    	//0x0034
} CSP_BT_T, *CSP_BT_PTR; 
/**
@brief CRC     bits Structure
*/ 
typedef struct
{
   volatile unsigned int  IDR;             /**< ID Register	                     */
   volatile unsigned int  CEDR;            /**< Clock Enable/Disable Register	     */
   volatile unsigned int  SRR;             /**< Software Reset Register	     */
   volatile unsigned int  CR;              /**< Control Register	             */
   volatile unsigned int  SEED;            /**< Seed Value Register	             */
   volatile unsigned int  DATAIN;          /**< Data in Value Register	             */
   volatile unsigned int  DATAOUT;         /**< Data out Value Register	     */
  //  TBD... //
} CSP_CRC_T, *CSP_CRC_PTR;
/**
@brief RTC     bits Structure
*/ 
 typedef struct
 {
   volatile unsigned int	TIMR;  		//0x0000	Time Control Register
   volatile unsigned int	DATR;		//0x0004	Date Control Register
   volatile unsigned int	CR;  		//0x0008	Control Register
   volatile unsigned int	CCR;  		//0x000C	Clock Control register
   volatile unsigned int	ALRAR;		//0x0010	Alarm A
   volatile unsigned int	ALRBR;		//0x0014	Alarm B
   volatile unsigned int	SSR;    	//0x0018	Sub second
   volatile unsigned int	CAL;   		//0x001C	Calibration
   volatile unsigned int   RISR;       //0x0020
   volatile unsigned int	IMCR;   	//0x0024
   volatile unsigned int	MISR;     	//0x0028
   volatile unsigned int	ICR;   		//0x002C
   volatile unsigned int	KEY;    	//0x0030
   volatile unsigned int	EVTRG;  	//0x0034
   volatile unsigned int	EVPS;   	//0x0038
   volatile unsigned int	EVSWF;  	//0x003C
} CSP_RTC_T, *CSP_RTC_PTR; 	
    
/**
@brief WWDT     bits Structure
*/ 	
 typedef struct
 {
	 volatile unsigned int	CR;
	 volatile unsigned int	CFGR;
	 volatile unsigned int	RISR;
	 volatile unsigned int MISR;
	 volatile unsigned int	IMCR;
	 volatile unsigned int	ICR;
 }CSP_WWDT_T,*CSP_WWDT_PTR;
/**
@brief HWD     bits Structure
*/ 	
 typedef struct
 {
	 volatile S32_T	DIVIDENT;
	 volatile S32_T	DIVISOR;
	 volatile S32_T	QUOTIENT;
	 volatile S32_T	REMAIN;
	 volatile unsigned int	CR;
 }CSP_HWD_T,*CSP_HWD_PTR; 
	
 #define FLASHBase 0x00000000
 #define FLASHSize 0x00010000
 #define FLASHLimit (FLASHBase + FLASHSize) 
 #define DFLASHBase 0x10000000
 #define DFLASHSize 0x10001000
 #define DFLASHLimit (FLASHBase + FLASHSize) 

#ifdef REMAP
  #define SRAMBase 0x00000000
  #define SRAMSize 0x00000800
  #define SRAMLimit (SRAMBase + SRAMSize) 
  #define MEMVectorBase 0x00000700
  #define MEMVectorSize (0x50<<2)
#else
  #define SRAMBase 0x20000000
  #define SRAMSize 0x00001000
  #define SRAMLimit (SRAMBase + SRAMSize) 
  #define MEMVectorBase 0x20000F00
  #define MEMVectorSize (0x50<<2)
#endif

//--Peripheral Address Setting
#define APBPeriBase     0x40000000 

//--Each Peripheral Address Setting
//#define APB_SFMBase     (APBPeriBase + 0x10000)
#define APB_IFCBase    	(APBPeriBase + 0x10000)
#define APB_SYSCONBase  (APBPeriBase + 0x11000)
#define APB_ETCBBase    (APBPeriBase + 0x12000)

#define APB_TKEYBase    (APBPeriBase + 0x20000)
#define APB_ADC0Base    (APBPeriBase + 0x30000)

#define AHBGPIOBase 	0x60000000
#define APB_GPIOA0Base  (AHBGPIOBase + 0x0000) //A0  
#define APB_GPIOB0Base  (AHBGPIOBase + 0x2000) //B0 
#define APB_IGRPBase	(AHBGPIOBase + 0xF000)

#define APB_BT1Base      (APBPeriBase + 0x52000)
#define APB_BT0Base      (APBPeriBase + 0x51000)
#define APB_CNTABase    (APBPeriBase + 0x50000)

#define APB_GPT0Base    (APBPeriBase + 0x55000)

#define APB_EPT0Base    (APBPeriBase + 0x59000)

#define APB_RTCBase     (APBPeriBase + 0x60000)
#define APB_LPTBase     (APBPeriBase + 0x61000)
#define APB_WWDTBase	(APBPeriBase + 0x62000)

#define APB_UART0Base   (APBPeriBase + 0x80000)
#define APB_UART1Base   (APBPeriBase + 0x81000)
#define APB_UART2Base   (APBPeriBase + 0x82000)

#define APB_SPI0Base    (APBPeriBase + 0x90000)
#define APB_SIO0Base    (APBPeriBase + 0xB0000)

#define APB_I2C0Base    (APBPeriBase + 0xA0000)



#define AHB_CRCBase     0x50000000
#define APB_HWDBase		0x70000000		

//--Interrupt Bit Position
#define CORET_INT   (0x01ul<<0)       //IRQ0
#define SYSCON_INT  (0x01ul<<1)       //IRQ1
#define IFC_INT     (0x01ul<<2)       //IRQ2
#define ADC_INT     (0x01ul<<3)       //IRQ3
#define EPT0_INT    (0x01ul<<4)       //IRQ4
//DUMMY       //IRQ5
#define WWDT_INT    (0x01ul<<6)       //IRQ6
#define EXI0_INT    (0x01ul<<7)       //IRQ7
#define EXI1_INT    (0x01ul<<8)       //IRQ8
#define GPT0_INT    (0x01ul<<9)       //IRQ9 
//DUMMY      //IRQ10
//DUMMY      //IRQ11
#define RTC_INT     (0x01ul<<12)      //IRQ12
#define UART0_INT   (0x01ul<<13)      //IRQ13
#define UART1_INT   (0x01ul<<14)      //IRQ14
#define UART2_INT   (0x01ul<<15)      //IRQ15
//DUMMY      //IRQ16
#define I2C_INT     (0x01ul<<17)      //IRQ17
//DUMMY      //IRQ18
#define SPI_INT     (0x01ul<<19)      //IRQ19
#define SIO_INT      (0x01ul<<20)      //IRQ20
#define EXI2_INT    (0x01ul<<21)      //IRQ21
#define EXI3_INT    (0x01ul<<22)      //IRQ22
#define EXI4_INT    (0x01ul<<23)      //IRQ23
#define CA_INT      (0x01ul<<24)      //IRQ24
#define TKEY_INT    (0x01ul<<25)      //IRQ25
#define LPT_INT     (0x01ul<<26)      //IRQ26
//DUMMY      //IRQ27
#define BT0_INT      (0x01ul<<28)      //IRQ28
#define BT1_INT      (0x01ul<<29)      //IRQ29
//DUMMY      //IRQ30
//DUMMY      //IRQ31


extern CSP_CK801_T  *CK801     ;

extern CSP_IFC_T 	*IFC     ;
extern CSP_SYSCON_T *SYSCON   ;
extern CSP_ETCB_T   *ETCB ;

extern CSP_TKEY_T 	*TKEY     ;
extern CSP_ADC12_T 	*ADC0     ;

extern CSP_GPIO_T 	*GPIOA0   ;
extern CSP_GPIO_T 	*GPIOB0   ;
extern CSP_IGRP_T	*GPIOGRP  ;

extern CSP_UART_T 	*UART0    ;
extern CSP_UART_T 	*UART1    ;
extern CSP_UART_T 	*UART2    ;
extern CSP_SSP_T  	*SPI0     ;
extern CSP_SIO_T  	*SIO0     ;
extern CSP_I2C_T  	*I2C0     ;
extern CSP_CA_T  	*CA0      ;

extern CSP_GPT_T 	*GPT0     ;

extern CSP_EPT_T 	*EPT0     ;

extern CSP_LPT_T 	*LPT      ;
extern CSP_HWD_T 	*HWD      ;
extern CSP_WWDT_T 	*WWDT      ;
extern CSP_BT_T  	*BT0      ;
extern CSP_BT_T  	*BT1      ;

extern CSP_CRC_T 	*CRC      ;
extern CSP_RTC_T 	*RTC      ;

//ISR Define for generating special interrupt related ASM (CK802), with compile option -mistack
void MisalignedHandler(void) __attribute__((isr));
void IllegalInstrHandler(void) __attribute__((isr));
void AccessErrHandler(void) __attribute__((isr));
void BreakPointHandler(void) __attribute__((isr));
void UnrecExecpHandler(void) __attribute__((isr));
void Trap0Handler(void) __attribute__((isr));
void Trap1Handler(void) __attribute__((isr));
void Trap2Handler(void) __attribute__((isr));
void Trap3Handler(void) __attribute__((isr));
void PendTrapHandler(void) __attribute__((isr));

void CORETHandler(void) __attribute__((isr));
void SYSCONIntHandler(void) __attribute__((isr));
void IFCIntHandler(void) __attribute__((isr));
void ADCIntHandler(void) __attribute__((isr));
void EPT0IntHandler(void) __attribute__((isr));
void WWDTHandler(void) __attribute__((isr));
void EXI0IntHandler(void) __attribute__((isr));
void EXI1IntHandler(void) __attribute__((isr));
void EXI2to3IntHandler(void) __attribute__((isr));
void EXI4to8IntHandler(void) __attribute__((isr));
void EXI9to13IntHandler(void) __attribute__((isr));
void UART0IntHandler(void) __attribute__((isr));
void UART1IntHandler(void) __attribute__((isr));
void UART2IntHandler(void) __attribute__((isr));
void I2CIntHandler(void) __attribute__((isr));
void GPT0IntHandler(void) __attribute__((isr));
void LEDIntHandler(void) __attribute__((isr));
void TKEYIntHandler(void) __attribute__((isr));
void SPI0IntHandler(void) __attribute__((isr));
void SIO0IntHandler(void) __attribute__((isr));
void CNTAIntHandler(void) __attribute__((isr));
void RTCIntHandler(void) __attribute__((isr));
void LPTIntHandler(void) __attribute__((isr));
void BT0IntHandler(void) __attribute__((isr));
void BT1IntHandler(void) __attribute__((isr));

extern int __divsi3 (int a, int b);
extern unsigned int __udivsi3 (unsigned int a, unsigned int b);
extern int __modsi3 (int a, int b);
extern unsigned int __umodsi3 (unsigned int a, unsigned int b);
extern void delay_nms(unsigned int t);
extern void delay_nus(unsigned int t);

#endif

/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/