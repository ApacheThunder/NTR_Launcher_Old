#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/ds_rules

#---------------------------------------------------------------------------------
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing extra header files
# DATA is a list of directories containing binary files
# all directories are relative to this makefile
#---------------------------------------------------------------------------------
BUILD		:=	build
IMAGES		:=	graphics
SOURCES		:=	source $(IMG_DATA)
INCLUDES	:=	include
DATA		:=	data

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
ARCH	:=	-mthumb -mthumb-interwork

CFLAGS	:=	-g -Wall -O2\
 			-march=armv5te -mtune=arm946e-s -fomit-frame-pointer\
			-ffast-math \
			$(ARCH)

CFLAGS	+=	$(INCLUDE) -DARM9 -fno-strict-aliasing
CXXFLAGS	:=	$(CFLAGS)

ASFLAGS	:=	-g $(ARCH) -march=armv5te -mtune=arm946e-s

LDFLAGS	=	-specs=ds_arm9.specs -g $(ARCH) -Wl,-Map,$(notdir $*.map)

#---------------------------------------------------------------------------------
# any extra libraries we wish to link with the project
#---------------------------------------------------------------------------------
LIBS	:= -lfat -lnds9
 
#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
LIBDIRS	:=	$(LIBNDS)
 
#---------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------
 
export ARM9BIN	:=	$(TOPDIR)/$(TARGET).arm9
export ARM9ELF	:=	$(CURDIR)/$(TARGET).arm9.elf
export DEPSDIR := $(CURDIR)/$(BUILD)

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
					$(foreach dir,$(DATA),$(CURDIR)/$(dir))
 
CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))

BMPFILES	:=	$(foreach dir,$(IMAGES),$(notdir $(wildcard $(dir)/*.bmp)))

#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#---------------------------------------------------------------------------------
	export LD	:=	$(CC)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
	export LD	:=	$(CXX)
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

export OFILES	:=	$(addsuffix .o,$(BINFILES)) $(BMPFILES:.bmp=.o) \
					$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
 
export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
			$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
			-I$(CURDIR)/$(BUILD)
 
export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L$(dir)/lib)
 
.PHONY: $(BUILD) clean
 
#---------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile
 
#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(BUILD) *.elf *.nds* *.bin 
 
#---------------------------------------------------------------------------------
else
 
DEPENDS	:=	$(OFILES:.o=.d)
 
#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
$(ARM9BIN)	:	$(ARM9ELF) 
	@$(OBJCOPY) -O binary $< $@
	@echo built ... $(notdir $@)

$(ARM9ELF)	:	$(OFILES)
	@echo linking $(notdir $@)
	@$(LD)  $(LDFLAGS) $(OFILES) $(LIBPATHS) $(LIBS) -o $@


#---------------------------------------------------------------------------------
# graphics
#---------------------------------------------------------------------------------
bgtop.s			:	../$(IMAGES)/bgtop.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q
	
bgtop2.s		:	../$(IMAGES)/bgtop2.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

bgtop3.s		:	../$(IMAGES)/bgtop3.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

bgsub.s			:	../$(IMAGES)/bgsub.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

bgsub2.s		:	../$(IMAGES)/bgsub2.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot00.s			:	../$(IMAGES)/Bot00.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot01.s			:	../$(IMAGES)/Bot01.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot02.s			:	../$(IMAGES)/Bot02.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot03.s			:	../$(IMAGES)/Bot03.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot04.s			:	../$(IMAGES)/Bot04.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot05.s			:	../$(IMAGES)/Bot05.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot06.s			:	../$(IMAGES)/Bot06.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot07.s			:	../$(IMAGES)/Bot07.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot08.s			:	../$(IMAGES)/Bot08.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot09.s			:	../$(IMAGES)/Bot09.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Bot10.s			:	../$(IMAGES)/Bot10.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top00.s			:	../$(IMAGES)/Top00.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top01.s			:	../$(IMAGES)/Top01.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top02.s			:	../$(IMAGES)/Top02.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top03.s			:	../$(IMAGES)/Top03.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top04.s			:	../$(IMAGES)/Top04.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top05.s			:	../$(IMAGES)/Top05.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top06.s			:	../$(IMAGES)/Top06.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top07.s			:	../$(IMAGES)/Top07.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top08.s			:	../$(IMAGES)/Top08.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top09.s			:	../$(IMAGES)/Top09.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top10.s			:	../$(IMAGES)/Top10.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top11.s			:	../$(IMAGES)/Top11.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top12.s			:	../$(IMAGES)/Top12.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top13.s			:	../$(IMAGES)/Top13.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top14.s			:	../$(IMAGES)/Top14.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top15.s			:	../$(IMAGES)/Top15.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top16.s			:	../$(IMAGES)/Top16.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top17.s			:	../$(IMAGES)/Top17.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top18.s			:	../$(IMAGES)/Top18.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top19.s			:	../$(IMAGES)/Top19.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top20.s			:	../$(IMAGES)/Top20.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top21.s			:	../$(IMAGES)/Top21.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top22.s			:	../$(IMAGES)/Top22.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top23.s			:	../$(IMAGES)/Top23.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top24.s			:	../$(IMAGES)/Top24.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top25.s			:	../$(IMAGES)/Top25.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top26.s			:	../$(IMAGES)/Top26.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top27.s			:	../$(IMAGES)/Top27.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top28.s			:	../$(IMAGES)/Top28.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top29.s			:	../$(IMAGES)/Top29.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top30.s			:	../$(IMAGES)/Top30.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top31.s			:	../$(IMAGES)/Top31.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top32.s			:	../$(IMAGES)/Top32.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top33.s			:	../$(IMAGES)/Top33.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top34.s			:	../$(IMAGES)/Top34.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top35.s			:	../$(IMAGES)/Top35.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top36.s			:	../$(IMAGES)/Top36.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

Top37.s			:	../$(IMAGES)/Top37.bmp
	grit	$< -gB8 -gzl -fts -o $@ -q

#---------------------------------------------------------------------------------
# you need a rule like this for each extension you use as binary data 
#---------------------------------------------------------------------------------
%.bin.o	:	%.bin
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

-include $(DEPENDS)
 
#---------------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------------
