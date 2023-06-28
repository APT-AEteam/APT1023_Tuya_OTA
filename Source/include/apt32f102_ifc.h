/*
  ******************************************************************************
  * @file    apt32f102_ifc.h
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
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _apt32f102_ifc_H
#define _apt32f102_ifc_H

/* Includes ------------------------------------------------------------------*/
#include "apt32f102.h"

/******************************************************************************
************************ ifc Registers Definition *************************
******************************************************************************/

#define   IFC_CLK_EN          (0x01ul)
#define   IFC_CLK_DIS         (0xfeul)
#define   EnIFCClk            (IFC->CEDR = (IFC_CLK_EN))
#define   DisIFCClk           (IFC->CEDR = (IFC_CLK_DIS))

#define   USER_KEY            (0x5A5A5A5Aul)
#define   SetUserKey          (IFC->KR = (USER_KEY))
#define   StartOp             (0x01ul)

#define  IFC_CLKEN  (0x01ul) //IFC CLKEN
#define  IFC_SWRST  (0x01ul) //IFC SWRST 

#define  HIDM0  ((0x0ul)<<8) //HID0
#define  HIDM1  ((0x1ul)<<8) //HID1
#define  HIDM2  ((0x2ul)<<8) //HID2
#define  HIDM3  ((0x3ul)<<8) //HID3

// IFC Command
#define  PROGRAM    (0x01ul)
#define  PAGE_ERASE (0x02ul)
#define  CHIP_ERASE (0x04ul)
#define  OPTION_ERASE (0x05ul)
#define  PEP_ENABLE (0x06ul)			//预编程设定
#define  PAGE_BUF_CLR (0x07ul)			//页缓存清除
#define  DIS_SWD_SET (0x0Dul)			//SWD 禁止重映射
#define  EN_SWD_SET (0x0Eul)			//SWD 使能重映射
#define  USER_OPTION (0x0Ful)			//User OPTION操作

#define  USER_KEY (0x5A5A5A5Aul)
#define  CSP_IFC_SET_KR(ifc, val) (ifc->KR = (val))

//
#define   StartErase          (IFC->CR=(StartOp))
#define   EnChipErase         (IFC->CMR=(CHIP_ERASE|HIDM1))
#define   EnPageErase         (IFC->CMR=(PAGE_ERASE|HIDM0))

/**
  * @brief  IFC page address
  */
typedef enum
{
	PROM_PageAdd0           =  ((CSP_REGISTER_T)0x00000000),					//PROM 每页256BYTE
	PROM_PageAdd1         =  ((CSP_REGISTER_T)0x00000100),
	PROM_PageAdd2          =  ((CSP_REGISTER_T)0x00000200),
	PROM_PageAdd3          =  ((CSP_REGISTER_T)0x00000300),
	PROM_PageAdd4          =  ((CSP_REGISTER_T)0x00000400),
	PROM_PageAdd5          =  ((CSP_REGISTER_T)0x00000500),
	PROM_PageAdd6          =  ((CSP_REGISTER_T)0x00000600),
	PROM_PageAdd7          =  ((CSP_REGISTER_T)0x00000700),
	PROM_PageAdd8          =  ((CSP_REGISTER_T)0x00000800),
	PROM_PageAdd9          =  ((CSP_REGISTER_T)0x00000900),
	
	PROM_PageAdd10          =  ((CSP_REGISTER_T)0x00000A00),
	PROM_PageAdd11          =  ((CSP_REGISTER_T)0x00000B00),
	PROM_PageAdd12          =  ((CSP_REGISTER_T)0x00000C00),
	PROM_PageAdd13          =  ((CSP_REGISTER_T)0x00000D00),
	PROM_PageAdd14          =  ((CSP_REGISTER_T)0x00000E00),
	PROM_PageAdd15          =  ((CSP_REGISTER_T)0x00000F00),
	PROM_PageAdd16          =  ((CSP_REGISTER_T)0x00001000),
	PROM_PageAdd17          =  ((CSP_REGISTER_T)0x00001100),
	PROM_PageAdd18          =  ((CSP_REGISTER_T)0x00001200),
	PROM_PageAdd19          =  ((CSP_REGISTER_T)0x00001300),
	
	PROM_PageAdd20          =  ((CSP_REGISTER_T)0x00001400),
	PROM_PageAdd21          =  ((CSP_REGISTER_T)0x00001500),
	PROM_PageAdd22          =  ((CSP_REGISTER_T)0x00001600),
	PROM_PageAdd23          =  ((CSP_REGISTER_T)0x00001700),
	PROM_PageAdd24          =  ((CSP_REGISTER_T)0x00001800),
	PROM_PageAdd25          =  ((CSP_REGISTER_T)0x00001900),
	PROM_PageAdd26          =  ((CSP_REGISTER_T)0x00001A00),
	PROM_PageAdd27          =  ((CSP_REGISTER_T)0x00001B00),
	PROM_PageAdd28          =  ((CSP_REGISTER_T)0x00001C00),
	PROM_PageAdd29          =  ((CSP_REGISTER_T)0x00001D00),
	
	PROM_PageAdd30          =  ((CSP_REGISTER_T)0x00001E00),
	PROM_PageAdd31          =  ((CSP_REGISTER_T)0x00001F00),
	PROM_PageAdd32          =  ((CSP_REGISTER_T)0x00002000),
	PROM_PageAdd33          =  ((CSP_REGISTER_T)0x00002100),
	PROM_PageAdd34          =  ((CSP_REGISTER_T)0x00002200),
	PROM_PageAdd35          =  ((CSP_REGISTER_T)0x00002300),
	PROM_PageAdd36          =  ((CSP_REGISTER_T)0x00002400),
	PROM_PageAdd37          =  ((CSP_REGISTER_T)0x00002500),
	PROM_PageAdd38          =  ((CSP_REGISTER_T)0x00002600),
	PROM_PageAdd39          =  ((CSP_REGISTER_T)0x00002700),
	
	PROM_PageAdd40          =  ((CSP_REGISTER_T)0x00002800),
	PROM_PageAdd41          =  ((CSP_REGISTER_T)0x00002900),
	PROM_PageAdd42          =  ((CSP_REGISTER_T)0x00002A00),
	PROM_PageAdd43          =  ((CSP_REGISTER_T)0x00002B00),
	PROM_PageAdd44          =  ((CSP_REGISTER_T)0x00002C00),
	PROM_PageAdd45          =  ((CSP_REGISTER_T)0x00002D00),
	PROM_PageAdd46          =  ((CSP_REGISTER_T)0x00002E00),
	PROM_PageAdd47          =  ((CSP_REGISTER_T)0x00002F00),
	PROM_PageAdd48          =  ((CSP_REGISTER_T)0x00003000),
	PROM_PageAdd49          =  ((CSP_REGISTER_T)0x00003100),
	
	PROM_PageAdd50          =  ((CSP_REGISTER_T)0x00003200),
	PROM_PageAdd51          =  ((CSP_REGISTER_T)0x00003300),
	PROM_PageAdd52          =  ((CSP_REGISTER_T)0x00003400),
	PROM_PageAdd53          =  ((CSP_REGISTER_T)0x00003500),
	PROM_PageAdd54          =  ((CSP_REGISTER_T)0x00003600),
	PROM_PageAdd55          =  ((CSP_REGISTER_T)0x00003700),
	PROM_PageAdd56          =  ((CSP_REGISTER_T)0x00003800),
	PROM_PageAdd57          =  ((CSP_REGISTER_T)0x00003900),
	PROM_PageAdd58          =  ((CSP_REGISTER_T)0x00003A00),
	PROM_PageAdd59          =  ((CSP_REGISTER_T)0x00003B00),
	
	PROM_PageAdd60          =  ((CSP_REGISTER_T)0x00003C00),
	PROM_PageAdd61          =  ((CSP_REGISTER_T)0x00003D00),
	PROM_PageAdd62          =  ((CSP_REGISTER_T)0x00003E00),
	PROM_PageAdd63          =  ((CSP_REGISTER_T)0x00003F00),
	PROM_PageAdd64          =  ((CSP_REGISTER_T)0x00004000),
	PROM_PageAdd65          =  ((CSP_REGISTER_T)0x00004100),
	PROM_PageAdd66          =  ((CSP_REGISTER_T)0x00004200),
	PROM_PageAdd67          =  ((CSP_REGISTER_T)0x00004300),
	PROM_PageAdd68          =  ((CSP_REGISTER_T)0x00004400),
	PROM_PageAdd69          =  ((CSP_REGISTER_T)0x00004500),
	
	PROM_PageAdd70          =  ((CSP_REGISTER_T)0x00004600),
	PROM_PageAdd71          =  ((CSP_REGISTER_T)0x00004700),
	PROM_PageAdd72          =  ((CSP_REGISTER_T)0x00004800),
	PROM_PageAdd73          =  ((CSP_REGISTER_T)0x00004900),
	PROM_PageAdd74          =  ((CSP_REGISTER_T)0x00004A00),
	PROM_PageAdd75          =  ((CSP_REGISTER_T)0x00004B00),
	PROM_PageAdd76          =  ((CSP_REGISTER_T)0x00004C00),
	PROM_PageAdd77          =  ((CSP_REGISTER_T)0x00004D00),
	PROM_PageAdd78          =  ((CSP_REGISTER_T)0x00004E00),
	PROM_PageAdd79          =  ((CSP_REGISTER_T)0x00004F00),
	
	PROM_PageAdd80          =  ((CSP_REGISTER_T)0x00005000),
	PROM_PageAdd81          =  ((CSP_REGISTER_T)0x00005100),
	PROM_PageAdd82          =  ((CSP_REGISTER_T)0x00005200),
	PROM_PageAdd83          =  ((CSP_REGISTER_T)0x00005300),
	PROM_PageAdd84          =  ((CSP_REGISTER_T)0x00005400),
	PROM_PageAdd85          =  ((CSP_REGISTER_T)0x00005500),
	PROM_PageAdd86          =  ((CSP_REGISTER_T)0x00005600),
	PROM_PageAdd87          =  ((CSP_REGISTER_T)0x00005700),
	PROM_PageAdd88          =  ((CSP_REGISTER_T)0x00005800),
	PROM_PageAdd89          =  ((CSP_REGISTER_T)0x00005900),
	
	PROM_PageAdd90          =  ((CSP_REGISTER_T)0x00005A00),
	PROM_PageAdd91          =  ((CSP_REGISTER_T)0x00005B00),
	PROM_PageAdd92          =  ((CSP_REGISTER_T)0x00005C00),
	PROM_PageAdd93          =  ((CSP_REGISTER_T)0x00005D00),
	PROM_PageAdd94          =  ((CSP_REGISTER_T)0x00005E00),
	PROM_PageAdd95          =  ((CSP_REGISTER_T)0x00005F00),
	PROM_PageAdd96          =  ((CSP_REGISTER_T)0x00006000),
	PROM_PageAdd97          =  ((CSP_REGISTER_T)0x00006100),
	PROM_PageAdd98          =  ((CSP_REGISTER_T)0x00006200),
	PROM_PageAdd99          =  ((CSP_REGISTER_T)0x00006300),
	
	PROM_PageAdd100          =  ((CSP_REGISTER_T)0x00006400),
	PROM_PageAdd101          =  ((CSP_REGISTER_T)0x00006500),
	PROM_PageAdd102          =  ((CSP_REGISTER_T)0x00006600),
	PROM_PageAdd103          =  ((CSP_REGISTER_T)0x00006700),
	PROM_PageAdd104          =  ((CSP_REGISTER_T)0x00006800),
	PROM_PageAdd105          =  ((CSP_REGISTER_T)0x00006900),
	PROM_PageAdd106          =  ((CSP_REGISTER_T)0x00006A00),
	PROM_PageAdd107          =  ((CSP_REGISTER_T)0x00006B00),
	PROM_PageAdd108          =  ((CSP_REGISTER_T)0x00006C00),
	PROM_PageAdd109          =  ((CSP_REGISTER_T)0x00006D00),
	
	PROM_PageAdd110          =  ((CSP_REGISTER_T)0x00006E00),
	PROM_PageAdd111          =  ((CSP_REGISTER_T)0x00006F00),
	PROM_PageAdd112          =  ((CSP_REGISTER_T)0x00007000),
	PROM_PageAdd113          =  ((CSP_REGISTER_T)0x00007100),
	PROM_PageAdd114          =  ((CSP_REGISTER_T)0x00007200),
	PROM_PageAdd115          =  ((CSP_REGISTER_T)0x00007300),
	PROM_PageAdd116          =  ((CSP_REGISTER_T)0x00007400),
	PROM_PageAdd117          =  ((CSP_REGISTER_T)0x00007500),
	PROM_PageAdd118          =  ((CSP_REGISTER_T)0x00007600),
	PROM_PageAdd119          =  ((CSP_REGISTER_T)0x00007700),
	
	PROM_PageAdd120          =  ((CSP_REGISTER_T)0x00007800),
	PROM_PageAdd121          =  ((CSP_REGISTER_T)0x00007900),
	PROM_PageAdd122          =  ((CSP_REGISTER_T)0x00007A00),
	PROM_PageAdd123          =  ((CSP_REGISTER_T)0x00007B00),
	PROM_PageAdd124          =  ((CSP_REGISTER_T)0x00007C00),
	PROM_PageAdd125          =  ((CSP_REGISTER_T)0x00007D00),
	PROM_PageAdd126          =  ((CSP_REGISTER_T)0x00007E00),
	PROM_PageAdd127          =  ((CSP_REGISTER_T)0x00007F00),
	PROM_PageAdd128          =  ((CSP_REGISTER_T)0x00008000),
	PROM_PageAdd129          =  ((CSP_REGISTER_T)0x00008100),
	
	PROM_PageAdd130          =  ((CSP_REGISTER_T)0x00008200),
	PROM_PageAdd131          =  ((CSP_REGISTER_T)0x00008300),
	PROM_PageAdd132          =  ((CSP_REGISTER_T)0x00008400),
	PROM_PageAdd133          =  ((CSP_REGISTER_T)0x00008500),
	PROM_PageAdd134          =  ((CSP_REGISTER_T)0x00008600),
	PROM_PageAdd135          =  ((CSP_REGISTER_T)0x00008700),
	PROM_PageAdd136          =  ((CSP_REGISTER_T)0x00008800),
	PROM_PageAdd137          =  ((CSP_REGISTER_T)0x00008900),
	PROM_PageAdd138          =  ((CSP_REGISTER_T)0x00008A00),
	PROM_PageAdd139          =  ((CSP_REGISTER_T)0x00008B00),
	
	PROM_PageAdd140          =  ((CSP_REGISTER_T)0x00008C00),
	PROM_PageAdd141          =  ((CSP_REGISTER_T)0x00008D00),
	PROM_PageAdd142          =  ((CSP_REGISTER_T)0x00008E00),
	PROM_PageAdd143          =  ((CSP_REGISTER_T)0x00008F00),
	PROM_PageAdd144          =  ((CSP_REGISTER_T)0x00009000),
	PROM_PageAdd145          =  ((CSP_REGISTER_T)0x00009100),
	PROM_PageAdd146          =  ((CSP_REGISTER_T)0x00009200),
	PROM_PageAdd147          =  ((CSP_REGISTER_T)0x00009300),
	PROM_PageAdd148          =  ((CSP_REGISTER_T)0x00009400),
	PROM_PageAdd149          =  ((CSP_REGISTER_T)0x00009500),
	
	PROM_PageAdd150          =  ((CSP_REGISTER_T)0x00009600),
	PROM_PageAdd151          =  ((CSP_REGISTER_T)0x00009700),
	PROM_PageAdd152          =  ((CSP_REGISTER_T)0x00009800),
	PROM_PageAdd153          =  ((CSP_REGISTER_T)0x00009900),
	PROM_PageAdd154          =  ((CSP_REGISTER_T)0x00009A00),
	PROM_PageAdd155          =  ((CSP_REGISTER_T)0x00009B00),
	PROM_PageAdd156          =  ((CSP_REGISTER_T)0x00009C00),
	PROM_PageAdd157          =  ((CSP_REGISTER_T)0x00009D00),
	PROM_PageAdd158          =  ((CSP_REGISTER_T)0x00009E00),
	PROM_PageAdd159          =  ((CSP_REGISTER_T)0x00009F00),
	
	PROM_PageAdd160          =  ((CSP_REGISTER_T)0x0000A000),
	PROM_PageAdd161          =  ((CSP_REGISTER_T)0x0000A100),
	PROM_PageAdd162          =  ((CSP_REGISTER_T)0x0000A200),
	PROM_PageAdd163          =  ((CSP_REGISTER_T)0x0000A300),
	PROM_PageAdd164          =  ((CSP_REGISTER_T)0x0000A400),
	PROM_PageAdd165          =  ((CSP_REGISTER_T)0x0000A500),
	PROM_PageAdd166          =  ((CSP_REGISTER_T)0x0000A600),
	PROM_PageAdd167          =  ((CSP_REGISTER_T)0x0000A700),
	PROM_PageAdd168          =  ((CSP_REGISTER_T)0x0000A800),
	PROM_PageAdd169          =  ((CSP_REGISTER_T)0x0000A900),
	
	PROM_PageAdd170          =  ((CSP_REGISTER_T)0x0000AA00),
	PROM_PageAdd171          =  ((CSP_REGISTER_T)0x0000AB00),
	PROM_PageAdd172          =  ((CSP_REGISTER_T)0x0000AC00),
	PROM_PageAdd173          =  ((CSP_REGISTER_T)0x0000AD00),
	PROM_PageAdd174          =  ((CSP_REGISTER_T)0x0000AE00),
	PROM_PageAdd175          =  ((CSP_REGISTER_T)0x0000AF00),
	PROM_PageAdd176          =  ((CSP_REGISTER_T)0x0000B000),
	PROM_PageAdd177          =  ((CSP_REGISTER_T)0x0000B100),
	PROM_PageAdd178          =  ((CSP_REGISTER_T)0x0000B200),
	PROM_PageAdd179          =  ((CSP_REGISTER_T)0x0000B300),
	
	PROM_PageAdd180          =  ((CSP_REGISTER_T)0x0000B400),
	PROM_PageAdd181          =  ((CSP_REGISTER_T)0x0000B500),
	PROM_PageAdd182          =  ((CSP_REGISTER_T)0x0000B600),
	PROM_PageAdd183          =  ((CSP_REGISTER_T)0x0000B700),
	PROM_PageAdd184          =  ((CSP_REGISTER_T)0x0000B800),
	PROM_PageAdd185          =  ((CSP_REGISTER_T)0x0000B900),
	PROM_PageAdd186          =  ((CSP_REGISTER_T)0x0000BA00),
	PROM_PageAdd187          =  ((CSP_REGISTER_T)0x0000BB00),
	PROM_PageAdd188          =  ((CSP_REGISTER_T)0x0000BC00),
	PROM_PageAdd189          =  ((CSP_REGISTER_T)0x0000BD00),
	
	PROM_PageAdd190          =  ((CSP_REGISTER_T)0x0000BE00),
	PROM_PageAdd191          =  ((CSP_REGISTER_T)0x0000BF00),
	PROM_PageAdd192          =  ((CSP_REGISTER_T)0x0000C000),
	PROM_PageAdd193          =  ((CSP_REGISTER_T)0x0000C100),
	PROM_PageAdd194          =  ((CSP_REGISTER_T)0x0000C200),
	PROM_PageAdd195          =  ((CSP_REGISTER_T)0x0000C300),
	PROM_PageAdd196          =  ((CSP_REGISTER_T)0x0000C400),
	PROM_PageAdd197          =  ((CSP_REGISTER_T)0x0000C500),
	PROM_PageAdd198          =  ((CSP_REGISTER_T)0x0000C600),
	PROM_PageAdd199          =  ((CSP_REGISTER_T)0x0000C700),
	
	PROM_PageAdd200          =  ((CSP_REGISTER_T)0x0000C800),
	PROM_PageAdd201          =  ((CSP_REGISTER_T)0x0000C900),
	PROM_PageAdd202          =  ((CSP_REGISTER_T)0x0000CA00),
	PROM_PageAdd203          =  ((CSP_REGISTER_T)0x0000CB00),
	PROM_PageAdd204          =  ((CSP_REGISTER_T)0x0000CC00),
	PROM_PageAdd205          =  ((CSP_REGISTER_T)0x0000CD00),
	PROM_PageAdd206          =  ((CSP_REGISTER_T)0x0000CE00),
	PROM_PageAdd207          =  ((CSP_REGISTER_T)0x0000CF00),
	PROM_PageAdd208          =  ((CSP_REGISTER_T)0x0000D000),
	PROM_PageAdd209          =  ((CSP_REGISTER_T)0x0000D100),
	
	PROM_PageAdd210          =  ((CSP_REGISTER_T)0x0000D200),
	PROM_PageAdd211          =  ((CSP_REGISTER_T)0x0000D300),
	PROM_PageAdd212          =  ((CSP_REGISTER_T)0x0000D400),
	PROM_PageAdd213          =  ((CSP_REGISTER_T)0x0000D500),
	PROM_PageAdd214          =  ((CSP_REGISTER_T)0x0000D600),
	PROM_PageAdd215          =  ((CSP_REGISTER_T)0x0000D700),
	PROM_PageAdd216          =  ((CSP_REGISTER_T)0x0000D800),
	PROM_PageAdd217          =  ((CSP_REGISTER_T)0x0000D900),
	PROM_PageAdd218          =  ((CSP_REGISTER_T)0x0000DA00),
	PROM_PageAdd219          =  ((CSP_REGISTER_T)0x0000DB00),
	
	PROM_PageAdd220          =  ((CSP_REGISTER_T)0x0000DC00),
	PROM_PageAdd221          =  ((CSP_REGISTER_T)0x0000DD00),
	PROM_PageAdd222          =  ((CSP_REGISTER_T)0x0000DE00),
	PROM_PageAdd223          =  ((CSP_REGISTER_T)0x0000DF00),
	PROM_PageAdd224          =  ((CSP_REGISTER_T)0x0000E000),
	PROM_PageAdd225          =  ((CSP_REGISTER_T)0x0000E100),
	PROM_PageAdd226          =  ((CSP_REGISTER_T)0x0000E200),
	PROM_PageAdd227          =  ((CSP_REGISTER_T)0x0000E300),
	PROM_PageAdd228          =  ((CSP_REGISTER_T)0x0000E400),
	PROM_PageAdd229          =  ((CSP_REGISTER_T)0x0000E500),
	
	PROM_PageAdd230          =  ((CSP_REGISTER_T)0x0000E600),
	PROM_PageAdd231          =  ((CSP_REGISTER_T)0x0000E700),
	PROM_PageAdd232          =  ((CSP_REGISTER_T)0x0000E800),
	PROM_PageAdd233          =  ((CSP_REGISTER_T)0x0000E900),
	PROM_PageAdd234          =  ((CSP_REGISTER_T)0x0000EA00),
	PROM_PageAdd235          =  ((CSP_REGISTER_T)0x0000EB00),
	PROM_PageAdd236          =  ((CSP_REGISTER_T)0x0000EC00),
	PROM_PageAdd237          =  ((CSP_REGISTER_T)0x0000ED00),
	PROM_PageAdd238          =  ((CSP_REGISTER_T)0x0000EE00),
	PROM_PageAdd239          =  ((CSP_REGISTER_T)0x0000EF00),
	
	PROM_PageAdd240          =  ((CSP_REGISTER_T)0x0000F000),
	PROM_PageAdd241          =  ((CSP_REGISTER_T)0x0000F100),
	PROM_PageAdd242          =  ((CSP_REGISTER_T)0x0000F200),
	PROM_PageAdd243          =  ((CSP_REGISTER_T)0x0000F300),
	PROM_PageAdd244          =  ((CSP_REGISTER_T)0x0000F400),
	PROM_PageAdd245          =  ((CSP_REGISTER_T)0x0000F50),
	PROM_PageAdd246          =  ((CSP_REGISTER_T)0x0000F600),
	PROM_PageAdd247          =  ((CSP_REGISTER_T)0x0000F700),
	PROM_PageAdd248          =  ((CSP_REGISTER_T)0x0000F800),
	PROM_PageAdd249          =  ((CSP_REGISTER_T)0x0000F900),
	
	PROM_PageAdd250          =  ((CSP_REGISTER_T)0x0000FA00),
	PROM_PageAdd251          =  ((CSP_REGISTER_T)0x0000FB00),
	PROM_PageAdd252          =  ((CSP_REGISTER_T)0x0000FC00),
	PROM_PageAdd253          =  ((CSP_REGISTER_T)0x0000FD00),
	PROM_PageAdd254          =  ((CSP_REGISTER_T)0x0000FE00),
	PROM_PageAdd255          =  ((CSP_REGISTER_T)0x0000FF00),

	DROM_PageAdd0           =  ((CSP_REGISTER_T)0x10000000),					//DROM 每页64BYTE
	DROM_PageAdd1           =  ((CSP_REGISTER_T)0x10000040),
	DROM_PageAdd2           =  ((CSP_REGISTER_T)0x10000080),
	DROM_PageAdd3           =  ((CSP_REGISTER_T)0x100000C0),
	DROM_PageAdd4           =  ((CSP_REGISTER_T)0x10000100),					
	DROM_PageAdd5           =  ((CSP_REGISTER_T)0x10000140),
	DROM_PageAdd6           =  ((CSP_REGISTER_T)0x10000180),
	DROM_PageAdd7           =  ((CSP_REGISTER_T)0x100001C0),
	DROM_PageAdd8           =  ((CSP_REGISTER_T)0x10000200),
	DROM_PageAdd9           =  ((CSP_REGISTER_T)0x10000240),
	
	DROM_PageAdd10           =  ((CSP_REGISTER_T)0x10000280),	
	DROM_PageAdd11           =  ((CSP_REGISTER_T)0x100002C0),
	DROM_PageAdd12           =  ((CSP_REGISTER_T)0x10000300),
	DROM_PageAdd13           =  ((CSP_REGISTER_T)0x10000340),
	DROM_PageAdd14           =  ((CSP_REGISTER_T)0x10000380),	
	DROM_PageAdd15           =  ((CSP_REGISTER_T)0x100003C0),
	DROM_PageAdd16           =  ((CSP_REGISTER_T)0x10000400),
	DROM_PageAdd17           =  ((CSP_REGISTER_T)0x10000440),
	DROM_PageAdd18           =  ((CSP_REGISTER_T)0x10000480),
	DROM_PageAdd19           =  ((CSP_REGISTER_T)0x100004C0),
	
	DROM_PageAdd20           =  ((CSP_REGISTER_T)0x10000500),	
	DROM_PageAdd21           =  ((CSP_REGISTER_T)0x10000540),
	DROM_PageAdd22           =  ((CSP_REGISTER_T)0x10000580),
	DROM_PageAdd23           =  ((CSP_REGISTER_T)0x100005C0),
	DROM_PageAdd24           =  ((CSP_REGISTER_T)0x10000600),	
	DROM_PageAdd25           =  ((CSP_REGISTER_T)0x10000640),
	DROM_PageAdd26           =  ((CSP_REGISTER_T)0x10000680),
	DROM_PageAdd27           =  ((CSP_REGISTER_T)0x100006C0),
	DROM_PageAdd28           =  ((CSP_REGISTER_T)0x10000700),
	DROM_PageAdd29           =  ((CSP_REGISTER_T)0x10000740),
	
	DROM_PageAdd30           =  ((CSP_REGISTER_T)0x10000780),	
	DROM_PageAdd31           =  ((CSP_REGISTER_T)0x100007C0)
}IFC_ROMSELETED_TypeDef;

/**
  * @brief  IFC INT mode
  */
typedef enum
{
	ERS_END_INT          =  (0x01ul),
	RGM_END_INT          =  ((0x01ul)<<1),
	PEP_END_INT      	 =  ((0x01ul)<<2),
	PROT_ERR_INT         =  ((0x01ul)<<12),
	UDEF_ERR_INT     	 =  ((0x01ul)<<13),
	ADDR_ERR_INT     	 =  ((0x01ul)<<14),
	OVW_ERR_INT     	 =  ((0x01ul)<<15)
}IFC_INT_TypeDef;


extern void ChipErase(void);
extern void PageErase(IFC_ROMSELETED_TypeDef XROM_PageAd);
extern void IFC_interrupt_CMD(FunctionalStatus NewState ,IFC_INT_TypeDef IFC_INT_x);
extern void IFC_Int_Enable(void);
extern void IFC_Int_Disable(void);
extern void ProgramData_Word(unsigned int  FlashAdd,unsigned int DataSize,volatile unsigned char *BufArry);
extern void Page_ProgramData(unsigned int FlashAdd,unsigned int DataSize,volatile unsigned char *BufArry);
extern void Page_ProgramData_int(unsigned int FlashAdd,unsigned int DataSize,volatile unsigned char *BufArry);
extern void ReadDataArry(unsigned int RdStartAdd,unsigned int DataLength,volatile unsigned char *DataArryPoint);
extern volatile unsigned int R_INT_FlashAdd;
extern volatile unsigned char f_Drom_write_complete;
extern volatile unsigned char f_Drom_writing;
extern volatile unsigned char ifc_step;

#endif   /**< apt32f102_ifc_H */

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/
