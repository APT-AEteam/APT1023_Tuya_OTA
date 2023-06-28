##
## Auto Generated makefile by CDK
## Do not modify this file, and any manual changes will be erased!!!   
##
## BuildSet
ProjectName            :=bootloader
ConfigurationName      :=BuildSet
WorkspacePath          :=./
ProjectPath            :=./
IntermediateDirectory  :=Obj
OutDir                 :=$(IntermediateDirectory)
User                   :=luhy
Date                   :=09/06/2023
CDKPath                :=D:/C-Sky/CDK
ToolchainPath          :=D:/C-Sky/CDKRepo/Toolchain/CKV2ElfMinilib/V3.10.29/R/
LinkerName             :=csky-elfabiv2-gcc
LinkerNameoption       :=
SIZE                   :=csky-elfabiv2-size
READELF                :=csky-elfabiv2-readelf
CHECKSUM               :=crc32
SharedObjectLinkerName :=
ObjectSuffix           :=.o
DependSuffix           :=.d
PreprocessSuffix       :=.i
DisassemSuffix         :=.asm
IHexSuffix             :=.ihex
BinSuffix              :=.bin
ExeSuffix              :=.elf
LibSuffix              :=.a
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
ElfInfoSwitch          :=-hlS
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
UnPreprocessorSwitch   :=-U
SourceSwitch           :=-c 
ObjdumpSwitch          :=-S
ObjcopySwitch          :=-O ihex
ObjcopyBinSwitch       :=-O binary
OutputFile             :=$(ProjectName)
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=bootloader.txt
MakeDirCommand         :=mkdir
LinkOptions            := -mcpu=e801  -nostartfiles -Wl,--gc-sections -T"$(ProjectPath)/arch/ckcpu.ld"
LinkOtherFlagsOption   :=-Wl,-zmax-page-size=1024
IncludePackagePath     :=
IncludeCPath           := $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)"$../(ProjectPath)/Source/include" $(IncludeSwitch)../Source/include  
IncludeAPath           := $(IncludeSwitch). $(IncludeSwitch)include  
Libs                   := -Wl,--start-group  -Wl,--end-group  
ArLibs                 := 
PackagesLibPath        :=
LibPath                := $(PackagesLibPath) 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       :=csky-elfabiv2-ar rcu
CXX      :=csky-elfabiv2-g++
CC       :=csky-elfabiv2-gcc
AS       :=csky-elfabiv2-gcc
OBJDUMP  :=csky-elfabiv2-objdump
OBJCOPY  :=csky-elfabiv2-objcopy
CXXFLAGS := -mcpu=e801    -Os  -g3  -Wall  -ffunction-sections -ffunction-sections  
CFLAGS   := -mcpu=e801    -Os  -g3  -Wall  -ffunction-sections -ffunction-sections  
ASFLAGS  := -mcpu=e801    -Wa,--gdwarf2    


Objects0=$(IntermediateDirectory)/FWlib_apt32f101_adc$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f101_ifc$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_bt$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_coret$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_countera$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_ept$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_et$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_gpio$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_gpt$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_hwdiv$(ObjectSuffix) \
	$(IntermediateDirectory)/FWlib_apt32f102_i2c$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_lpt$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_rtc$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_syscon$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_uart$(ObjectSuffix) $(IntermediateDirectory)/FWlib_apt32f102_wwdt$(ObjectSuffix) $(IntermediateDirectory)/drivers_apt32f102$(ObjectSuffix) $(IntermediateDirectory)/drivers_apt32f102_ck801$(ObjectSuffix) $(IntermediateDirectory)/arch_crt0$(ObjectSuffix) $(IntermediateDirectory)/arch_mem_init$(ObjectSuffix) \
	$(IntermediateDirectory)/source_apt32f102_initial$(ObjectSuffix) $(IntermediateDirectory)/source_apt32f102_interrupt$(ObjectSuffix) $(IntermediateDirectory)/source_delay$(ObjectSuffix) $(IntermediateDirectory)/source_iostring$(ObjectSuffix) $(IntermediateDirectory)/source_main$(ObjectSuffix) $(IntermediateDirectory)/source_define$(ObjectSuffix) $(IntermediateDirectory)/source_uart$(ObjectSuffix) $(IntermediateDirectory)/__rt_entry$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all
all: $(IntermediateDirectory)/$(OutputFile)

$(IntermediateDirectory)/$(OutputFile):  $(Objects) Always_Link 
	$(LinkerName) $(OutputSwitch) $(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) $(LinkerNameoption) $(LinkOtherFlagsOption)  -Wl,--ckmap=$(ProjectPath)/Lst/$(OutputFile).map  @$(ObjectsFileList)  $(LinkOptions) $(LibPath) $(Libs)
	@mv $(ProjectPath)/Lst/$(OutputFile).map $(ProjectPath)/Lst/$(OutputFile).temp && $(READELF) $(ElfInfoSwitch) $(ProjectPath)/Obj/$(OutputFile)$(ExeSuffix) > $(ProjectPath)/Lst/$(OutputFile).map && echo ====================================================================== >> $(ProjectPath)/Lst/$(OutputFile).map && cat $(ProjectPath)/Lst/$(OutputFile).temp >> $(ProjectPath)/Lst/$(OutputFile).map && rm -rf $(ProjectPath)/Lst/$(OutputFile).temp
	$(OBJCOPY) $(ObjcopySwitch) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix)  $(ProjectPath)/Obj/$(OutputFile)$(IHexSuffix) 
	@echo size of target:
	@$(SIZE) $(ProjectPath)$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) 
	@echo -n checksum value of target:  
	@$(CHECKSUM) $(ProjectPath)/$(IntermediateDirectory)/$(OutputFile)$(ExeSuffix) 
	@$(ProjectName).modify.bat $(IntermediateDirectory) $(OutputFile)$(ExeSuffix) 

Always_Link:


##
## Objects
##
$(IntermediateDirectory)/FWlib_apt32f101_adc$(ObjectSuffix): ../Source/FWlib/apt32f101_adc.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f101_adc.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f101_adc$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f101_adc$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f101_adc$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f101_adc$(PreprocessSuffix): ../Source/FWlib/apt32f101_adc.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f101_adc$(PreprocessSuffix) ../Source/FWlib/apt32f101_adc.c

$(IntermediateDirectory)/FWlib_apt32f101_ifc$(ObjectSuffix): ../Source/FWlib/apt32f101_ifc.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f101_ifc.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f101_ifc$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f101_ifc$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f101_ifc$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f101_ifc$(PreprocessSuffix): ../Source/FWlib/apt32f101_ifc.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f101_ifc$(PreprocessSuffix) ../Source/FWlib/apt32f101_ifc.c

$(IntermediateDirectory)/FWlib_apt32f102_bt$(ObjectSuffix): ../Source/FWlib/apt32f102_bt.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_bt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_bt$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_bt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_bt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_bt$(PreprocessSuffix): ../Source/FWlib/apt32f102_bt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_bt$(PreprocessSuffix) ../Source/FWlib/apt32f102_bt.c

$(IntermediateDirectory)/FWlib_apt32f102_coret$(ObjectSuffix): ../Source/FWlib/apt32f102_coret.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_coret.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_coret$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_coret$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_coret$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_coret$(PreprocessSuffix): ../Source/FWlib/apt32f102_coret.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_coret$(PreprocessSuffix) ../Source/FWlib/apt32f102_coret.c

$(IntermediateDirectory)/FWlib_apt32f102_countera$(ObjectSuffix): ../Source/FWlib/apt32f102_countera.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_countera.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_countera$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_countera$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_countera$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_countera$(PreprocessSuffix): ../Source/FWlib/apt32f102_countera.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_countera$(PreprocessSuffix) ../Source/FWlib/apt32f102_countera.c

$(IntermediateDirectory)/FWlib_apt32f102_ept$(ObjectSuffix): ../Source/FWlib/apt32f102_ept.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_ept.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_ept$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_ept$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_ept$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_ept$(PreprocessSuffix): ../Source/FWlib/apt32f102_ept.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_ept$(PreprocessSuffix) ../Source/FWlib/apt32f102_ept.c

$(IntermediateDirectory)/FWlib_apt32f102_et$(ObjectSuffix): ../Source/FWlib/apt32f102_et.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_et.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_et$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_et$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_et$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_et$(PreprocessSuffix): ../Source/FWlib/apt32f102_et.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_et$(PreprocessSuffix) ../Source/FWlib/apt32f102_et.c

$(IntermediateDirectory)/FWlib_apt32f102_gpio$(ObjectSuffix): ../Source/FWlib/apt32f102_gpio.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_gpio.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_gpio$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_gpio$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_gpio$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_gpio$(PreprocessSuffix): ../Source/FWlib/apt32f102_gpio.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_gpio$(PreprocessSuffix) ../Source/FWlib/apt32f102_gpio.c

$(IntermediateDirectory)/FWlib_apt32f102_gpt$(ObjectSuffix): ../Source/FWlib/apt32f102_gpt.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_gpt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_gpt$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_gpt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_gpt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_gpt$(PreprocessSuffix): ../Source/FWlib/apt32f102_gpt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_gpt$(PreprocessSuffix) ../Source/FWlib/apt32f102_gpt.c

$(IntermediateDirectory)/FWlib_apt32f102_hwdiv$(ObjectSuffix): ../Source/FWlib/apt32f102_hwdiv.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_hwdiv.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_hwdiv$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_hwdiv$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_hwdiv$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_hwdiv$(PreprocessSuffix): ../Source/FWlib/apt32f102_hwdiv.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_hwdiv$(PreprocessSuffix) ../Source/FWlib/apt32f102_hwdiv.c

$(IntermediateDirectory)/FWlib_apt32f102_i2c$(ObjectSuffix): ../Source/FWlib/apt32f102_i2c.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_i2c.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_i2c$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_i2c$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_i2c$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_i2c$(PreprocessSuffix): ../Source/FWlib/apt32f102_i2c.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_i2c$(PreprocessSuffix) ../Source/FWlib/apt32f102_i2c.c

$(IntermediateDirectory)/FWlib_apt32f102_lpt$(ObjectSuffix): ../Source/FWlib/apt32f102_lpt.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_lpt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_lpt$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_lpt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_lpt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_lpt$(PreprocessSuffix): ../Source/FWlib/apt32f102_lpt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_lpt$(PreprocessSuffix) ../Source/FWlib/apt32f102_lpt.c

$(IntermediateDirectory)/FWlib_apt32f102_rtc$(ObjectSuffix): ../Source/FWlib/apt32f102_rtc.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_rtc.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_rtc$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_rtc$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_rtc$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_rtc$(PreprocessSuffix): ../Source/FWlib/apt32f102_rtc.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_rtc$(PreprocessSuffix) ../Source/FWlib/apt32f102_rtc.c

$(IntermediateDirectory)/FWlib_apt32f102_syscon$(ObjectSuffix): ../Source/FWlib/apt32f102_syscon.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_syscon.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_syscon$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_syscon$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_syscon$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_syscon$(PreprocessSuffix): ../Source/FWlib/apt32f102_syscon.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_syscon$(PreprocessSuffix) ../Source/FWlib/apt32f102_syscon.c

$(IntermediateDirectory)/FWlib_apt32f102_uart$(ObjectSuffix): ../Source/FWlib/apt32f102_uart.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_uart.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_uart$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_uart$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_uart$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_uart$(PreprocessSuffix): ../Source/FWlib/apt32f102_uart.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_uart$(PreprocessSuffix) ../Source/FWlib/apt32f102_uart.c

$(IntermediateDirectory)/FWlib_apt32f102_wwdt$(ObjectSuffix): ../Source/FWlib/apt32f102_wwdt.c  
	$(CC) $(SourceSwitch) ../Source/FWlib/apt32f102_wwdt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/FWlib_apt32f102_wwdt$(ObjectSuffix) -MF$(IntermediateDirectory)/FWlib_apt32f102_wwdt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/FWlib_apt32f102_wwdt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/FWlib_apt32f102_wwdt$(PreprocessSuffix): ../Source/FWlib/apt32f102_wwdt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/FWlib_apt32f102_wwdt$(PreprocessSuffix) ../Source/FWlib/apt32f102_wwdt.c

$(IntermediateDirectory)/drivers_apt32f102$(ObjectSuffix): ../Source/drivers/apt32f102.c  
	$(CC) $(SourceSwitch) ../Source/drivers/apt32f102.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/drivers_apt32f102$(ObjectSuffix) -MF$(IntermediateDirectory)/drivers_apt32f102$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/drivers_apt32f102$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/drivers_apt32f102$(PreprocessSuffix): ../Source/drivers/apt32f102.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/drivers_apt32f102$(PreprocessSuffix) ../Source/drivers/apt32f102.c

$(IntermediateDirectory)/drivers_apt32f102_ck801$(ObjectSuffix): ../Source/drivers/apt32f102_ck801.c  
	$(CC) $(SourceSwitch) ../Source/drivers/apt32f102_ck801.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/drivers_apt32f102_ck801$(ObjectSuffix) -MF$(IntermediateDirectory)/drivers_apt32f102_ck801$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/drivers_apt32f102_ck801$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/drivers_apt32f102_ck801$(PreprocessSuffix): ../Source/drivers/apt32f102_ck801.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/drivers_apt32f102_ck801$(PreprocessSuffix) ../Source/drivers/apt32f102_ck801.c

$(IntermediateDirectory)/arch_crt0$(ObjectSuffix): arch/crt0.S  
	$(AS) $(SourceSwitch) arch/crt0.S $(ASFLAGS) -MMD -MP -MT$(IntermediateDirectory)/arch_crt0$(ObjectSuffix) -MF$(IntermediateDirectory)/arch_crt0$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/arch_crt0$(ObjectSuffix) $(IncludeAPath) $(IncludePackagePath)
Lst/arch_crt0$(PreprocessSuffix): arch/crt0.S
	$(CC) $(CFLAGS)$(IncludeAPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/arch_crt0$(PreprocessSuffix) arch/crt0.S

$(IntermediateDirectory)/arch_mem_init$(ObjectSuffix): arch/mem_init.c  
	$(CC) $(SourceSwitch) arch/mem_init.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/arch_mem_init$(ObjectSuffix) -MF$(IntermediateDirectory)/arch_mem_init$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/arch_mem_init$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/arch_mem_init$(PreprocessSuffix): arch/mem_init.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/arch_mem_init$(PreprocessSuffix) arch/mem_init.c

$(IntermediateDirectory)/source_apt32f102_initial$(ObjectSuffix): source/apt32f102_initial.c  
	$(CC) $(SourceSwitch) source/apt32f102_initial.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/source_apt32f102_initial$(ObjectSuffix) -MF$(IntermediateDirectory)/source_apt32f102_initial$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/source_apt32f102_initial$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/source_apt32f102_initial$(PreprocessSuffix): source/apt32f102_initial.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/source_apt32f102_initial$(PreprocessSuffix) source/apt32f102_initial.c

$(IntermediateDirectory)/source_apt32f102_interrupt$(ObjectSuffix): source/apt32f102_interrupt.c  
	$(CC) $(SourceSwitch) source/apt32f102_interrupt.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/source_apt32f102_interrupt$(ObjectSuffix) -MF$(IntermediateDirectory)/source_apt32f102_interrupt$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/source_apt32f102_interrupt$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/source_apt32f102_interrupt$(PreprocessSuffix): source/apt32f102_interrupt.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/source_apt32f102_interrupt$(PreprocessSuffix) source/apt32f102_interrupt.c

$(IntermediateDirectory)/source_delay$(ObjectSuffix): source/delay.c  
	$(CC) $(SourceSwitch) source/delay.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/source_delay$(ObjectSuffix) -MF$(IntermediateDirectory)/source_delay$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/source_delay$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/source_delay$(PreprocessSuffix): source/delay.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/source_delay$(PreprocessSuffix) source/delay.c

$(IntermediateDirectory)/source_iostring$(ObjectSuffix): source/iostring.c  
	$(CC) $(SourceSwitch) source/iostring.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/source_iostring$(ObjectSuffix) -MF$(IntermediateDirectory)/source_iostring$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/source_iostring$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/source_iostring$(PreprocessSuffix): source/iostring.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/source_iostring$(PreprocessSuffix) source/iostring.c

$(IntermediateDirectory)/source_main$(ObjectSuffix): source/main.c  
	$(CC) $(SourceSwitch) source/main.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/source_main$(ObjectSuffix) -MF$(IntermediateDirectory)/source_main$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/source_main$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/source_main$(PreprocessSuffix): source/main.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/source_main$(PreprocessSuffix) source/main.c

$(IntermediateDirectory)/source_define$(ObjectSuffix): source/define.c  
	$(CC) $(SourceSwitch) source/define.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/source_define$(ObjectSuffix) -MF$(IntermediateDirectory)/source_define$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/source_define$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/source_define$(PreprocessSuffix): source/define.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/source_define$(PreprocessSuffix) source/define.c

$(IntermediateDirectory)/source_uart$(ObjectSuffix): source/uart.c  
	$(CC) $(SourceSwitch) source/uart.c $(CFLAGS) -MMD -MP -MT$(IntermediateDirectory)/source_uart$(ObjectSuffix) -MF$(IntermediateDirectory)/source_uart$(DependSuffix) $(ObjectSwitch)$(IntermediateDirectory)/source_uart$(ObjectSuffix) $(IncludeCPath) $(IncludePackagePath)
Lst/source_uart$(PreprocessSuffix): source/uart.c
	$(CC) $(CFLAGS)$(IncludeCPath) $(PreprocessOnlySwitch) $(OutputSwitch) Lst/source_uart$(PreprocessSuffix) source/uart.c


$(IntermediateDirectory)/__rt_entry$(ObjectSuffix): $(IntermediateDirectory)/__rt_entry$(DependSuffix)
	@$(AS) $(SourceSwitch) $(ProjectPath)/$(IntermediateDirectory)/__rt_entry.S $(ASFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/__rt_entry$(ObjectSuffix) $(IncludeAPath)
$(IntermediateDirectory)/__rt_entry$(DependSuffix):
	@$(CC) $(CFLAGS) $(IncludeAPath) -MG -MP -MT$(IntermediateDirectory)/__rt_entry$(ObjectSuffix) -MF$(IntermediateDirectory)/__rt_entry$(DependSuffix) -MM $(ProjectPath)/$(IntermediateDirectory)/__rt_entry.S

-include $(IntermediateDirectory)/*$(DependSuffix)
