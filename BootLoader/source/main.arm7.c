/*
 main.arm7.c
 
 By Michael Chisholm (Chishm)
 
 All resetMemory and startBinary functions are based 
 on the MultiNDS loader by Darkain.
 Original source available at:
 http://cvs.sourceforge.net/viewcvs.py/ndslib/ndslib/examples/loader/boot/main.cpp

 License:
    NitroHax -- Cheat tool for the Nintendo DS
    Copyright (C) 2008  Michael "Chishm" Chisholm

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ARM7
# define ARM7
#endif
#include <nds/ndstypes.h>
#include <nds/system.h>
#include <nds/interrupts.h>
#include <nds/timers.h>
#include <nds/dma.h>
#include <nds/arm7/audio.h>
#include <nds/ipc.h>
#include <nds/registers_alt.h>
#include <nds/memory.h>
#include <nds/card.h>
#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif

#include "common.h"
#include "read_card.h"

void arm7_clearmem (void* loc, size_t len);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Important things
#define NDS_HEAD 0x027FFE00
tNDSHeader* ndsHeader = (tNDSHeader*)NDS_HEAD;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Used for debugging purposes
/* Disabled for now. Re-enable to debug problems
static void errorOutput (u32 code) {
	// Wait until the ARM9 is ready
	while (arm9_stateFlag != ARM9_READY);
	// Set the error code, then tell ARM9 to display it
	arm9_errorCode = code;
	arm9_errorClearBG = true;
	arm9_stateFlag = ARM9_DISPERR;
	// Stop
	while(1);
}
*/

static void debugOutput (u32 code) {
	// Wait until the ARM9 is ready
	while (arm9_stateFlag != ARM9_READY);
	// Set the error code, then tell ARM9 to display it
	arm9_errorCode = code;
	arm9_errorClearBG = false;
	arm9_stateFlag = ARM9_DISPERR;
	// Wait for completion
	while (arm9_stateFlag != ARM9_READY);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Firmware stuff

#define FW_READ        0x03

void arm7_readFirmware (uint32 address, uint8 * buffer, uint32 size) {
  uint32 index;

  // Read command
  while (REG_SPICNT & SPI_BUSY);
  REG_SPICNT = SPI_ENABLE | SPI_CONTINUOUS | SPI_DEVICE_NVRAM;
  REG_SPIDATA = FW_READ;
  while (REG_SPICNT & SPI_BUSY);

  // Set the address
  REG_SPIDATA =  (address>>16) & 0xFF;
  while (REG_SPICNT & SPI_BUSY);
  REG_SPIDATA =  (address>>8) & 0xFF;
  while (REG_SPICNT & SPI_BUSY);
  REG_SPIDATA =  (address) & 0xFF;
  while (REG_SPICNT & SPI_BUSY);

  for (index = 0; index < size; index++) {
    REG_SPIDATA = 0;
    while (REG_SPICNT & SPI_BUSY);
    buffer[index] = REG_SPIDATA & 0xFF;
  }
  REG_SPICNT = 0;
}

/*-------------------------------------------------------------------------
arm7_resetMemory
Clears all of the NDS's RAM that is visible to the ARM7
Written by Darkain.
Modified by Chishm:
 * Added STMIA clear mem loop
--------------------------------------------------------------------------*/
void arm7_resetMemory (void) {
	int i;
	u8 settings1, settings2;
	
	REG_IME = 0;

	for (i=0; i<16; i++) {
		SCHANNEL_CR(i) = 0;
		SCHANNEL_TIMER(i) = 0;
		SCHANNEL_SOURCE(i) = 0;
		SCHANNEL_LENGTH(i) = 0;
	}
	SOUND_CR = 0;

	// Clear out ARM7 DMA channels and timers
	for (i=0; i<4; i++) {
		DMA_CR(i) = 0;
		DMA_SRC(i) = 0;
		DMA_DEST(i) = 0;
		TIMER_CR(i) = 0;
		TIMER_DATA(i) = 0;
	}

	// Clear out FIFO
	REG_IPC_SYNC = 0;
	REG_IPC_FIFO_CR = IPC_FIFO_ENABLE | IPC_FIFO_SEND_CLEAR;
	REG_IPC_FIFO_CR = 0;

	// clear IWRAM - 037F:8000 to 0380:FFFF, total 96KiB
	arm7_clearmem ((void*)0x037F8000, 96*1024);
	
	// clear most of EXRAM - except after 0x023FD800, which has the ARM9 code
	arm7_clearmem ((void*)0x02000000, 0x003FD800);

	// clear last part of EXRAM, skipping the ARM9's section
	arm7_clearmem ((void*)0x023FE000, 0x2000);

	REG_IE = 0;
	REG_IF = ~0;
	(*(vu32*)(0x04000000-4)) = 0;  //IRQ_HANDLER ARM7 version
	(*(vu32*)(0x04000000-8)) = ~0; //VBLANK_INTR_WAIT_FLAGS, ARM7 version
	REG_POWERCNT = 1;  //turn off power to stuffs
	
	// Reload DS Firmware settings
	arm7_readFirmware((u32)0x03FE70, &settings1, 0x1);
	arm7_readFirmware((u32)0x03FF70, &settings2, 0x1);
	
	if (settings1 > settings2) {
		arm7_readFirmware((u32)0x03FE00, (u8*)0x027FFC80, 0x70);
		arm7_readFirmware((u32)0x03FF00, (u8*)0x027FFD80, 0x70);
	} else {
		arm7_readFirmware((u32)0x03FF00, (u8*)0x027FFC80, 0x70);
		arm7_readFirmware((u32)0x03FE00, (u8*)0x027FFD80, 0x70);
	}
	
	// Load FW header 
	arm7_readFirmware((u32)0x000000, (u8*)0x027FF830, 0x20);
}

int arm7_loadBinary (void) {
	u32 chipID;
	u32 errorCode;
	
	// Init card
	errorCode = cardInit(ndsHeader, &chipID);
	if (errorCode) {
		return errorCode;
	}

	// Set memory values expected by loaded NDS	
	*((u32*)0x027ff800) = chipID;					// CurrentCardID
	*((u32*)0x027ff804) = chipID;					// Command10CardID
	*((u16*)0x027ff808) = ndsHeader->headerCRC16;	// Header Checksum, CRC-16 of [000h-15Dh]
	*((u16*)0x027ff80a) = ndsHeader->secureCRC16;	// Secure Area Checksum, CRC-16 of [ [20h]..7FFFh]
	*((u16*)0x027ffc40) = 0x1;						// Booted from card -- EXTREMELY IMPORTANT!!! Thanks to cReDiAr
	
	cardRead(ndsHeader->arm9romOffset, (u32*)ndsHeader->arm9destination, ndsHeader->arm9binarySize);	cardRead(ndsHeader->arm7romOffset, (u32*)ndsHeader->arm7destination, ndsHeader->arm7binarySize);
	return ERR_NONE;
}


/*-------------------------------------------------------------------------
arm7_startBinary
Jumps to the ARM7 NDS binary in sync with the display and ARM9
Written by Darkain, modified by Chishm.
--------------------------------------------------------------------------*/
void arm7_startBinary (void)
{
	// Wait until the ARM9 is ready
	while (arm9_stateFlag != ARM9_READY);

	while(REG_VCOUNT!=191);
	while(REG_VCOUNT==191);
	
	// Get the ARM9 to boot
	arm9_stateFlag = ARM9_BOOTBIN;

	while(REG_VCOUNT!=191);
	while(REG_VCOUNT==191);
	// Start ARM7
	
	void (*foo)() = *(u32*)(0x27FFE34);
	
	foo();
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Main function

void arm7_main (void) {
	
	// No longer set here.
	// volatile u32* SCFG_ROM = (volatile u32*)0x4004000;
	// volatile u32* SCFG_CLK = (volatile u32*)0x4004004;
	// volatile u32* SCFG_EXT = (volatile u32*)0x4004008;

	
	// REG_SCFG_ROM = 0x703;
	// REG_SCFG_CLK = 0x180;
	// REG_SCFG_EXT = 0x80000000;
	// REG_SCFG_EXT=0x12A00000;

	int errorCode;
	
	// Wait for ARM9 to at least start
	while (arm9_stateFlag < ARM9_START);

	debugOutput (ERR_STS_CLR_MEM);
	
	// Get ARM7 to clear RAM
	arm7_resetMemory();	

	debugOutput (ERR_STS_LOAD_BIN);

	// Load the NDS file
	errorCode = arm7_loadBinary();
	if (errorCode) {
		debugOutput(errorCode);
	}

	debugOutput (ERR_STS_HOOK_BIN);

	arm7_startBinary();
	
	return;
}

