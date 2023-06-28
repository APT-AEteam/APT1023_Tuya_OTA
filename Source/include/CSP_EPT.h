/******************************************************************************
************************** EPT Registers Definition ****************************
******************************************************************************/

/******************************************************************************
* EPT Regiser
******************************************************************************/
//CEDR
#define EPT_CLKEN           (1ul)
#define EPT_DBGEN           (1ul << 1)
#define EPT_CKSRC_EXT       (1ul << 2)
#define EPT_TIN_BT0         (1ul << 4)
#define EPT_TIN_BT1         (2ul << 4)
#define EPT_START_IMMD      (1ul << 6)
//CR
#define EPT_CNTM_UP    (0ul)
#define EPT_CNTM_DN    (1ul)
#define EPT_CNTM_UD    (2ul)
#define EPT_STARTSYNC  (1ul << 2)
#define EPT_IDLE_LOW   (1ul << 3)
#define EPT_PRDLD_IMMD (0ul << 4)       
#define EPT_PRDLD_ZRO  (1ul << 4)       
#define EPT_PRDLD_SYNC (2ul << 4)       
#define EPT_PRDLD_LDSN (3ul << 4)       
#define EPT_OPM        (1ul << 6)
#define EPT_PHSEN      (1ul << 7)
#define EPT_CAPEN      (1ul << 8)
#define EPT_BURST      (1ul << 9)
#define EPT_CKS_DIV2   (1ul << 10)
#define EPT_CG_TIOA    (0ul << 11)
#define EPT_CG_TIOB    (1ul << 11)
#define EPT_CG_TIN     (2ul << 11)
#define EPT_CGCNT2     (1ul << 13)
#define EPT_CGCNT3     (2ul << 13)
#define EPT_CGCNT4     (3ul << 13)
#define EPT_CGCNT6     (4ul << 13)
#define EPT_CGCNT8     (5ul << 13)
#define EPT_CGCNT16    (6ul << 13)
#define EPT_CGCNT32    (7ul << 13)
#define EPT_PSCLD_DIS  (0ul << 16)
#define EPT_PSCLD_ZRO  (1ul << 16)
#define EPT_PSCLD_PRD  (2ul << 16)
#define EPT_PSCLD_ZOP  (3ul << 16)
#define EPT_WAVEMD     (1ul << 18)
#define EPT_CAPREARM   (1ul << 19)
#define EPT_CAP_OST    (1ul << 20)
#define EPT_CAP_WRAP(n) ((n)<<21)
#define EPT_CAP_RSTA    (1ul << 23)
#define EPT_CAP_RSTB    (1ul << 24)
#define EPT_CAP_RSTC    (1ul << 25)
#define EPT_CAP_RSTD    (1ul << 26)

//AQCR
#define CMPA_AS_CA     (0ul<<20)
#define CMPB_AS_CA     (1ul<<20)
#define CMPC_AS_CA     (2ul<<20)
#define CMPD_AS_CA     (3ul<<20)

#define CMPA_AS_CB     (0ul<<22)
#define CMPB_AS_CB     (1ul<<22)
#define CMPC_AS_CB     (2ul<<22)
#define CMPD_AS_CB     (3ul<<22)

#define HI_AT_ZRO      (2ul<<0)
#define LO_AT_ZRO      (1ul<<0)
#define TG_AT_ZRO      (3ul<<0)
#define NA_AT_ZRO      (0ul<<0)

#define HI_AT_PRD      (2ul<<2)
#define LO_AT_PRD      (1ul<<2)
#define TG_AT_PRD      (3ul<<2)
#define NA_AT_PRD      (0ul<<2)

#define HI_AT_CAU      (2ul<<4)
#define LO_AT_CAU      (1ul<<4)
#define TG_AT_CAU      (3ul<<4)
#define NA_AT_CAU      (0ul<<4)
#define HI_AT_CAD      (2ul<<6)
#define LO_AT_CAD      (1ul<<6)
#define TG_AT_CAD      (3ul<<6)
#define NA_AT_CAD      (0ul<<6)

#define HI_AT_CBU      (2ul<<8)
#define LO_AT_CBU      (1ul<<8)
#define TG_AT_CBU      (3ul<<8)
#define NA_AT_CBU      (0ul<<8)
#define HI_AT_CBD      (2ul<<10)
#define LO_AT_CBD      (1ul<<10)
#define TG_AT_CBD      (3ul<<10)
#define NA_AT_CBD      (0ul<<10)

#define HI_AT_CCU      (2ul<<4)
#define LO_AT_CCU      (1ul<<4)
#define TG_AT_CCU      (3ul<<4)
#define NA_AT_CCU      (0ul<<4)
#define HI_AT_CCD      (2ul<<6)
#define LO_AT_CCD      (1ul<<6)
#define TG_AT_CCD      (3ul<<6)
#define NA_AT_CCD      (0ul<<6)

#define HI_AT_CDU      (2ul<<8)
#define LO_AT_CDU      (1ul<<8)
#define TG_AT_CDU      (3ul<<8)
#define NA_AT_CDU      (0ul<<8)
#define HI_AT_CDD      (2ul<<10)
#define LO_AT_CDD      (1ul<<10)
#define TG_AT_CDD      (3ul<<10)
#define NA_AT_CDD      (0ul<<10)

#define HI_AT_T1U      (2ul<<12)
#define LO_AT_T1U      (1ul<<12)
#define TG_AT_T1U      (3ul<<12)
#define NA_AT_T1U      (0ul<<12)
#define HI_AT_T1D      (2ul<<14)
#define LO_AT_T1D      (1ul<<14)
#define TG_AT_T1D      (3ul<<14)
#define NA_AT_T1D      (0ul<<14)

#define HI_AT_T2U      (2ul<<16)
#define LO_AT_T2U      (1ul<<16)
#define TG_AT_T2U      (3ul<<16)
#define NA_AT_T2U      (0ul<<16)
#define HI_AT_T2D      (2ul<<18)
#define LO_AT_T2D      (1ul<<18)
#define TG_AT_T2D      (3ul<<18)
#define NA_AT_T2D      (0ul<<18)

//DBCR
#define DB_CHA_A2RA2F    (0ul<<4)
#define DB_CHA_B2RA2F    (1ul<<4)
#define DB_CHA_A2RB2F    (2ul<<4)
#define DB_CHA_B2RB2F    (3ul<<4)

#define DB_CHA_INVX     (1ul<<2)
#define DB_CHA_INVY     (2ul<<2)
#define DB_CHA_INVXY    (3ul<<2)

#define DB_CHA_ENX      (1ul<<0)
#define DB_CHA_ENY      (2ul<<0)
#define DB_CHA_ENXY     (3ul<<0)

#define DB_CHB_B2RB2F    (0ul<<12)
#define DB_CHB_C2RB2F    (1ul<<12)
#define DB_CHB_B2RC2F    (2ul<<12)
#define DB_CHB_C2RC2F    (3ul<<12)

#define DB_CHB_INVX     (1ul<<10)
#define DB_CHB_INVY     (2ul<<10)
#define DB_CHB_INVXY    (3ul<<10)

#define DB_CHB_ENX      (1ul<<8)
#define DB_CHB_ENY      (2ul<<8)
#define DB_CHB_ENXY     (3ul<<8)

#define DB_CHC_C2RC2F    (0ul<<20)
#define DB_CHC_D2RC2F    (1ul<<20)
#define DB_CHC_C2RD2F    (2ul<<20)
#define DB_CHC_D2RD2F    (3ul<<20)

#define DB_CHC_INVX     (1ul<<18)
#define DB_CHC_INVY     (2ul<<18)
#define DB_CHC_INVXY    (3ul<<18)

#define DB_CHC_ENX      (1ul<<16)
#define DB_CHC_ENY      (2ul<<16)
#define DB_CHC_ENXY     (3ul<<16)


#define DB_HCLK        (1ul<<24)
#define DB_CHA_EDEB    (1ul<<25)
#define DB_CHB_EDEB    (1ul<<26)
#define DB_CHC_EDEB    (1ul<<27)

//CPCR
#define CP_ENAX        (1ul<<16)
#define CP_ENAY        (1ul<<17)
#define CP_ENBX        (1ul<<18)
#define CP_ENBY        (1ul<<19)
#define CP_ENCX        (1ul<<20)
#define CP_ENCY        (1ul<<21)
#define CP_END         (1ul<<22)

#define CP_OSPW(n)     ((n)<<2)
#define CP_CDIV(n)     ((n)<<7)
#define CP_1_8DUTY     (0ul<<11)
#define CP_2_8DUTY     (1ul<<11)
#define CP_3_8DUTY     (2ul<<11)
#define CP_4_8DUTY     (3ul<<11)
#define CP_5_8DUTY     (4ul<<11)
#define CP_6_8DUTY     (5ul<<11)
#define CP_7_8DUTY     (6ul<<11)

// EPI
#define EP0_EPI(n)     ((n+1))
#define EP1_EPI(n)     ((n+1)<<4)
#define EP2_EPI(n)     ((n+1)<<8)
#define EP3_EPI(n)     ((n+1)<<12)
#define EP4_EPI(n)     ((n+1)<<16)
#define EP5_EPI(n)     ((n+1)<<20)
#define EP6_EPI(n)     ((n+1)<<24)
#define EP7_EPI(n)     ((n+1)<<28)

#define EP0_SL         (1ul << 0)
#define EP0_HL         (2ul << 0)
#define EP1_SL         (1ul << 2)
#define EP1_HL         (2ul << 2)
#define EP2_SL         (1ul << 4)
#define EP2_HL         (2ul << 4)
#define EP3_SL         (1ul << 6)
#define EP3_HL         (2ul << 6)
#define EP4_SL         (1ul << 8)
#define EP4_HL         (2ul << 8)

#define OSR_SHDW       (1ul << 21)
#define OSR_IMMD       (0ul << 21)

#define OSR_LD_ZRO     (1ul << 22)
#define OSR_LD_PRD     (2ul << 22)
#define OSR_LD_ZOP     (3ul << 22)

#define SL_CLR_AT_ZRO  (0ul << 24)
#define SL_CLR_AT_PRD  (1ul << 24)
#define SL_CLR_AT_ZOP  (2ul << 24)
#define SL_CLR_AT_SFT  (3ul << 24)

#define EPASYNC        (1ul << 26)
#define HL_CPUFAULT    (1ul << 28)
#define HL_MEMFAULT    (1ul << 29)
#define HL_EOMFAULT    (1ul << 30)

//#define EP0_CA_HZ      (0ul << 0)
//#define EP0_CA_HI      (1ul << 0)
//#define EP0_CA_LO      (2ul << 0)
//#define EP0_CA_NA      (3ul << 0)
//#define EP0_CB_HZ      (0ul << 2)
//#define EP0_CB_HI      (1ul << 2)
//#define EP0_CB_LO      (2ul << 2)
//#define EP0_CB_NA      (3ul << 2)
//#define EP0_CC_HZ      (0ul << 4)
//#define EP0_CC_HI      (1ul << 4)
//#define EP0_CC_LO      (2ul << 4)
//#define EP0_CC_NA      (3ul << 4)
//#define EP0_CD_HZ      (0ul << 6)
//#define EP0_CD_HI      (1ul << 6)
//#define EP0_CD_LO      (2ul << 6)
//#define EP0_CD_NA      (3ul << 6)
//
//#define EP1_CA_HZ      (0ul << 8)
//#define EP1_CA_HI      (1ul << 8)
//#define EP1_CA_LO      (2ul << 8)
//#define EP1_CA_NA      (3ul << 8)
//#define EP1_CB_HZ      (0ul << 10)
//#define EP1_CB_HI      (1ul << 10)
//#define EP1_CB_LO      (2ul << 10)
//#define EP1_CB_NA      (3ul << 10)
//#define EP1_CC_HZ      (0ul << 12)
//#define EP1_CC_HI      (1ul << 12)
//#define EP1_CC_LO      (2ul << 12)
//#define EP1_CC_NA      (3ul << 12)
//#define EP1_CD_HZ      (0ul << 14)
//#define EP1_CD_HI      (1ul << 14)
//#define EP1_CD_LO      (2ul << 14)
//#define EP1_CD_NA      (3ul << 14)
//
//#define EP2_CA_HZ      (0ul << 16)
//#define EP2_CA_HI      (1ul << 16)
//#define EP2_CA_LO      (2ul << 16)
//#define EP2_CA_NA      (3ul << 16)
//#define EP2_CB_HZ      (0ul << 18)
//#define EP2_CB_HI      (1ul << 18)
//#define EP2_CB_LO      (2ul << 18)
//#define EP2_CB_NA      (3ul << 18)
//#define EP2_CC_HZ      (0ul << 20)
//#define EP2_CC_HI      (1ul << 20)
//#define EP2_CC_LO      (2ul << 20)
//#define EP2_CC_NA      (3ul << 20)
//#define EP2_CD_HZ      (0ul << 22)
//#define EP2_CD_HI      (1ul << 22)
//#define EP2_CD_LO      (2ul << 22)
//#define EP2_CD_NA      (3ul << 22)
//
//#define EP3_CA_HZ      (0ul << 24)
//#define EP3_CA_HI      (1ul << 24)
//#define EP3_CA_LO      (2ul << 24)
//#define EP3_CA_NA      (3ul << 24)
//#define EP3_CB_HZ      (0ul << 26)
//#define EP3_CB_HI      (1ul << 26)
//#define EP3_CB_LO      (2ul << 26)
//#define EP3_CB_NA      (3ul << 26)
//#define EP3_CC_HZ      (0ul << 28)
//#define EP3_CC_HI      (1ul << 28)
//#define EP3_CC_LO      (2ul << 28)
//#define EP3_CC_NA      (3ul << 28)
//#define EP3_CD_HZ      (0ul << 30)
//#define EP3_CD_HI      (1ul << 30)
//#define EP3_CD_LO      (2ul << 30)
//#define EP3_CD_NA      (3ul << 30)
//
//#define EP47_CA_HZ     (0ul << 0)
//#define EP47_CA_HI     (1ul << 0)
//#define EP47_CA_LO     (2ul << 0)
//#define EP47_CA_NA     (3ul << 0)
//#define EP47_CB_HZ     (0ul << 2)
//#define EP47_CB_HI     (1ul << 2)
//#define EP47_CB_LO     (2ul << 2)
//#define EP47_CB_NA     (3ul << 2)
//#define EP47_CC_HZ     (0ul << 4)
//#define EP47_CC_HI     (1ul << 4)
//#define EP47_CC_LO     (2ul << 4)
//#define EP47_CC_NA     (3ul << 4)
//#define EP47_CD_HZ     (0ul << 6)
//#define EP47_CD_HI     (1ul << 6)
//#define EP47_CD_LO     (2ul << 6)
//#define EP47_CD_NA     (3ul << 6)
//
//#define SYS_CA_HZ      (0ul << 8) 
//#define SYS_CA_HI      (1ul << 8) 
//#define SYS_CA_LO      (2ul << 8) 
//#define SYS_CA_NA      (3ul << 8) 
//#define SYS_CB_HZ      (0ul << 10)
//#define SYS_CB_HI      (1ul << 10)
//#define SYS_CB_LO      (2ul << 10)
//#define SYS_CB_NA      (3ul << 10)
//#define SYS_CC_HZ      (0ul << 12)
//#define SYS_CC_HI      (1ul << 12)
//#define SYS_CC_LO      (2ul << 12)
//#define SYS_CC_NA      (3ul << 12)
//#define SYS_CD_HZ      (0ul << 14)
//#define SYS_CD_HI      (1ul << 14)
//#define SYS_CD_LO      (2ul << 14)
//#define SYS_CD_NA      (3ul << 14)

#define EM_CHAX_HZ     (0ul << 0)
#define EM_CHAX_HI     (1ul << 0)
#define EM_CHAX_LO     (2ul << 0)
#define EM_CHAX_NA     (3ul << 0)
#define EM_CHBX_HZ     (0ul << 2)
#define EM_CHBX_HI     (1ul << 2)
#define EM_CHBX_LO     (2ul << 2)
#define EM_CHBX_NA     (3ul << 2)
#define EM_CHCX_HZ     (0ul << 4)
#define EM_CHCX_HI     (1ul << 4)
#define EM_CHCX_LO     (2ul << 4)
#define EM_CHCX_NA     (3ul << 4)
#define EM_CHDX_HZ     (0ul << 6)
#define EM_CHDX_HI     (1ul << 6)
#define EM_CHDX_LO     (2ul << 6)
#define EM_CHDX_NA     (3ul << 6)

#define EM_CHAY_HZ     (0ul << 8)
#define EM_CHAY_HI     (1ul << 8)
#define EM_CHAY_LO     (2ul << 8)
#define EM_CHAY_NA     (3ul << 8)
#define EM_CHBY_HZ     (0ul << 10)
#define EM_CHBY_HI     (1ul << 10)
#define EM_CHBY_LO     (2ul << 10)
#define EM_CHBY_NA     (3ul << 10)
#define EM_CHCY_HZ     (0ul << 12)
#define EM_CHCY_HI     (1ul << 12)
#define EM_CHCY_LO     (2ul << 12)
#define EM_CHCY_NA     (3ul << 12)

#define EP0            (1ul << 0)
#define EP1            (1ul << 1)
#define EP2            (1ul << 2)
#define EP3            (1ul << 3)
#define EP4            (1ul << 4)
#define EP5            (1ul << 5)
#define EP6            (1ul << 6)
#define EP7            (1ul << 7)
#define CPUFAULT       (1ul << 8)
#define MEMFAULT       (1ul << 9)
#define EOMFAULT       (1ul << 10)



#define DIVM(val)      ((0xFFFul & val)  <<  8)      /**< DIVM value                   */
#define DIVN(val)      ((  0x7ul & val)  <<  5)      /**< DIVN value                   */
#define CMODE(val)     ((  0x3ul & val)  <<  3)      /**< CMODE value                  */
#define S_RST          (0x01ul <<  2)      	     /**< Software reset               */
#define PWMSTOP        (0x01ul <<  1)      	     /**< Stop counter                 */
#define PWMSTART       (0x01ul <<  0)      	     /**< Start counter                */

//LKCR
#define EXI7LKM(val)   ((  0x3ul & val)  << 30)      /**< EXI7 link mode               */
#define EXI6LKM(val)   ((  0x3ul & val)  << 28)      /**< EXI6 link mode               */
#define EXI5LKM(val)   ((  0x3ul & val)  << 26)      /**< EXI5 link mode               */
#define EXI4LKM(val)   ((  0x3ul & val)  << 24)      /**< EXI4 link mode               */
#define EXI3LKM(val)   ((  0x7ul & val)  << 22)      /**< EXI3 link mode               */
#define EXI2LKM(val)   ((  0x7ul & val)  << 20)      /**< EXI2 link mode               */
#define EXI1LKM(val)   ((  0x7ul & val)  << 18)      /**< EXI1 link mode               */
#define EXI0LKM(val)   ((  0x7ul & val)  << 16)      /**< EXI0 link mode               */
#define CPULKM(val)    ((  0x7ul & val)  <<  2)      /**< CPU  link mode               */
#define LVDLKM(val)    ((  0x7ul & val)  <<  0)      /**< LVD  link mode               */

//LKTRG
#define TRGTDL(val)    ((  0xFul & val)  <<  8)      /**< Trigger delay value          */
#define TRGIVT(val)    (( 0xFFul & val)  <<  0)      /**< Anti-trigger interval        */

//WGCR
#define PCB(val)       ((0x3FFul & val)  << 10)      /**< PWM engine B control         */
#define PCA(val)       ((0x3FFul & val)  <<  0)      /**< PWM engine A control         */
#define AZERO_O0       (0x00ul << 20)      	     /**< PWM A output @ZERO CMP Value */
#define AZERO_O1       (0x01ul << 20)      	     /**< PWM A output @ZERO CMP Value */
#define AFULL_O0       (0x00ul << 21)      	     /**< PWM A output @FULL CMP Value */
#define AFULL_O1       (0x01ul << 21)      	     /**< PWM A output @FULL CMP Value */
#define BZERO_O0       (0x00ul << 22)      	     /**< PWM B output @ZERO CMP Value */
#define BZERO_O1       (0x01ul << 22)      	     /**< PWM B output @ZERO CMP Value */
#define BFULL_O0       (0x00ul << 23)      	     /**< PWM B output @FULL CMP Value */
#define BFULL_O1       (0x01ul << 23)      	     /**< PWM B output @FULL CMP Value */

//OUTCR
#define DTF(val)       ((0x1FFul & val)  << 15)      /**< fall dead time               */
#define DTR(val)       ((0x1FFul & val)  <<  6)      /**< rise dead time               */
#define SRC_PX         (0x00ul <<  4)      	     /**< Source select                */
#define SRC_PY         (0x01ul <<  4)      	     /**< Source select                */
#define POLARITY(val)  ((  0x3ul & val)  <<  2)      /**< Polarity control             */
#define OUTSEL(val)    ((  0x3ul & val)  <<  0)      /**< output selection control     */

//CFCR
#define CFEN           (0x01ul <<  0)      	     /**< Carrier enable               */
#define CFSEL(val)     ((  0x7ul & val)  <<  1)      /**< Carrier Freq Selection       */
#define OSW(val)       ((  0xFul & val)  <<  4)      /**< One-shot pulse width         */
#define CDIV(val)      ((  0x7ul & val)  <<  8)      /**< Carrier Divider              */
#define DUTY(val)      ((  0x7ul & val)  << 12)      /**< Carrier Duty                 */

//EMR
#define S_ONE          (0x01ul <<  31)     	     /**< Softlock once                */
#define SL_P2YS(val)   ((  0x3ul & val)  << 24)      /**< output status @soft-lock     */
#define SL_P2XS(val)   ((  0x3ul & val)  << 22)      /**< output status @soft-lock     */
#define HL_P2YS(val)   ((  0x3ul & val)  << 20)      /**< output status @hard-lock     */
#define HL_P2XS(val)   ((  0x3ul & val)  << 18)      /**< output status @hard-lock     */
#define SL_P1YS(val)   ((  0x3ul & val)  << 16)      /**< output status @soft-lock     */
#define SL_P1XS(val)   ((  0x3ul & val)  << 14)      /**< output status @soft-lock     */
#define HL_P1YS(val)   ((  0x3ul & val)  << 12)      /**< output status @hard-lock     */
#define HL_P1XS(val)   ((  0x3ul & val)  << 10)      /**< output status @hard-lock     */
#define SL_P0YS(val)   ((  0x3ul & val)  <<  8)      /**< output status @soft-lock     */
#define SL_P0XS(val)   ((  0x3ul & val)  <<  6)      /**< output status @soft-lock     */
#define HL_P0YS(val)   ((  0x3ul & val)  <<  4)      /**< output status @hard-lock     */
#define HL_P0XS(val)   ((  0x3ul & val)  <<  2)      /**< output status @hard-lock     */
#define CLR_HLOCK      (0x01ul << 31)      	     /**< Clear hard-lock status       */
#define CLR_SLOCK      (0x01ul << 30)      	     /**< Clear soft-lock status       */
#define HLOCK          (0x01ul << 31)      	     /**< Hard-lock status             */
#define SLOCK          (0x01ul << 30)      	     /**< Soft-lock status             */


//EXTRG
#define START_TRG(val)   ((  0x3ul & val)  <<  0)       /**< Trigger source               */
#define STOP_TRG(val)    ((  0x3ul & val)  <<  2)       /**< Trigger source               */
#define PEND_TRG(val)    ((  0x3ul & val)  <<  4)       /**< Trigger source               */
#define CENTER_TRG(val)  ((  0x3ul & val)  <<  6)       /**< Trigger source               */

#define CMPAUM0_TRG(val) ((  0x3ul & val)  <<  0)       /**< Trigger source               */
#define CMPADM0_TRG(val) ((  0x3ul & val)  <<  2)       /**< Trigger source               */
#define CMPBUM0_TRG(val) ((  0x3ul & val)  <<  4)       /**< Trigger source               */
#define CMPBDM0_TRG(val) ((  0x3ul & val)  <<  6)       /**< Trigger source               */
#define CMPAUM1_TRG(val) ((  0x3ul & val)  <<  8)       /**< Trigger source               */
#define CMPADM1_TRG(val) ((  0x3ul & val)  << 10)       /**< Trigger source               */
#define CMPBUM1_TRG(val) ((  0x3ul & val)  << 12)       /**< Trigger source               */
#define CMPBDM1_TRG(val) ((  0x3ul & val)  << 14)       /**< Trigger source               */
#define CMPAUM2_TRG(val) ((  0x3ul & val)  << 16)       /**< Trigger source               */
#define CMPADM2_TRG(val) ((  0x3ul & val)  << 18)       /**< Trigger source               */
#define CMPBUM2_TRG(val) ((  0x3ul & val)  << 20)       /**< Trigger source               */
#define CMPBDM2_TRG(val) ((  0x3ul & val)  << 22)       /**< Trigger source               */


/******************************************************************************
* Interrupt Related
******************************************************************************/
#define INT_START       (0x01ul <<  0)     /**< Normal Interrupt source     */
#define INT_STOP        (0x01ul <<  1)     /**< Normal Interrupt source     */
#define INT_PEND        (0x01ul <<  2)     /**< Normal Interrupt source     */
#define INT_CENTER      (0x01ul <<  3)     /**< Normal Interrupt source     */
#define INT_CMPAUM0     (0x01ul <<  4)     /**< Normal Interrupt source     */
#define INT_CMPADM0     (0x01ul <<  5)     /**< Normal Interrupt source     */
#define INT_CMPBUM0     (0x01ul <<  6)     /**< Normal Interrupt source     */
#define INT_CMPBDM0     (0x01ul <<  7)     /**< Normal Interrupt source     */
#define INT_CMPAUM1     (0x01ul <<  8)     /**< Normal Interrupt source     */
#define INT_CMPADM1     (0x01ul <<  9)     /**< Normal Interrupt source     */
#define INT_CMPBUM1     (0x01ul << 10)     /**< Normal Interrupt source     */
#define INT_CMPBDM1     (0x01ul << 11)     /**< Normal Interrupt source     */
#define INT_CMPAUM2     (0x01ul << 12)     /**< Normal Interrupt source     */
#define INT_CMPADM2     (0x01ul << 13)     /**< Normal Interrupt source     */
#define INT_CMPBUM2     (0x01ul << 14)     /**< Normal Interrupt source     */
#define INT_CMPBDM2     (0x01ul << 15)     /**< Normal Interrupt source     */

/** Set IER register                                                     */
#define CSP_EPWM_SET_IER(epwm, val)    ((epwm)->INTIER = (val))
/** Get IER register                                                     */
#define CSP_EPWM_GET_IER(epwm)         ((epwm)->INTIER)


/** Get RISR register (Status)                                              */
#define CSP_EPWM_GET_RISR(epwm)         ((epwm)->RISR)

/** Get MISR register (Status)                                              */
#define CSP_EPWM_GET_MISR(epwm)         ((epwm)->MISR)

/** Set ICR register (Status)                                            */
#define CSP_EPWM_SET_ICR(epwm, val)     ((epwm)->ICR = (val))
