/*
 main.arm9.c
 
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

#define ARM9
#undef ARM7
#include <nds/memory.h>
#include <nds/arm9/video.h>
#include <nds/arm9/input.h>
#include <nds/interrupts.h>
#include <nds/dma.h>
#include <nds/timers.h>
#include <nds/system.h>
#include <nds/ipc.h>

#include "common.h"

volatile int arm9_stateFlag = ARM9_BOOT;
volatile u32 arm9_errorCode = 0xFFFFFFFF;
volatile bool arm9_errorClearBG = false;
volatile u32 arm9_BLANK_RAM = 0;

/*-------------------------------------------------------------------------
External functions
--------------------------------------------------------------------------*/
extern void arm9_clearCache (void);

/*-------------------------------------------------------------------------
arm9_errorOutput
Displays an error code on screen.
Written by Chishm
--------------------------------------------------------------------------*/
/* Re-enable for debug purposes
static void arm9_errorOutput (u32 code, bool clearBG) {
	int i, j, k;
	u16 colour;
	
	REG_POWERCNT = POWER_LCD | POWER_2D_A;
	REG_DISPCNT = MODE_FB0;
	VRAM_A_CR = VRAM_ENABLE;
	
	if (clearBG) {
		// Clear display
		for (i = 0; i < 256*192; i++) {
			VRAM_A[i] = 0x0000;
		}
	}
	
	// Draw boxes of colour, signifying error codes
	
	if ((code >> 16) != 0) {
		// high 16 bits
		for (i = 0; i < 8; i++) {						// Pair of bits to use
			if (((code>>(30-2*i))&3) == 0) {
				colour = 0x001F; // Red
			} else if (((code>>(30-2*i))&3) == 1) {
				colour = 0x03FF; // Yellow
			} else if (((code>>(30-2*i))&3) == 2) {
				colour = 0x03E0; // Green
			} else {
				colour = 0x7C00; // Blue
			}
			for (j = 71; j < 87; j++) { 				// Row
				for (k = 32*i+8; k < 32*i+24; k++) {	// Column
					VRAM_A[j*256+k] = colour;
				}
			}
		}
	}

	if ((code >> 8) != 0) {
		// Low 16 bits
		for (i = 0; i < 8; i++) {						// Pair of bits to use
			if (((code>>(14-2*i))&3) == 0) {
				colour = 0x001F; // Red
			} else if (((code>>(14-2*i))&3) == 1) {
				colour = 0x03FF; // Yellow
			} else if (((code>>(14-2*i))&3) == 2) {
				colour = 0x03E0; // Green
			} else {
				colour = 0x7C00; // Blue
			}
			for (j = 103; j < 119; j++) { 				// Row
				for (k = 32*i+8; k < 32*i+24; k++) {	// Column
					VRAM_A[j*256+k] = colour;
				}
			}
		}
	} else {
		// Low 8 bits
		for (i = 0; i < 4; i++) {						// Pair of bits to use
			if (((code>>(6-2*i))&3) == 0) {
				colour = 0x001F; // Red
			} else if (((code>>(6-2*i))&3) == 1) {
				colour = 0x03FF; // Yellow
			} else if (((code>>(6-2*i))&3) == 2) {
				colour = 0x03E0; // Green
			} else {
				colour = 0x7C00; // Blue
			}
			for (j = 87; j < 103; j++) { 				// Row
				for (k = 32*i+72; k < 32*i+88; k++) {	// Column
					VRAM_A[j*256+k] = colour;
				}
			}
		}
	}		
}
*/

/*-------------------------------------------------------------------------
arm9_main
Clears the ARM9's icahce and dcache
Clears the ARM9's DMA channels and resets video memory
Jumps to the ARM9 NDS binary in sync with the display and ARM7
Written by Darkain, modified by Chishm
--------------------------------------------------------------------------*/
void arm9_main (void) {

	// volatile u32* SCFG_EXT = (volatile u32*)0x4004008;
	// volatile u32* SCFG_CLK = (volatile u32*)0x4004004;

	register int i;
	
	//set shared ram to ARM7
	WRAM_CR = 0x03;
	REG_EXMEMCNT = 0xE880;

	arm9_stateFlag = ARM9_START;
	
	REG_IME = 0;
	REG_IE = 0;
	REG_IF = ~0;

	arm9_clearCache();

	for (i=0; i<16*1024; i+=4) {  //first 16KB
		(*(vu32*)(i+0x00000000)) = 0x00000000;      //clear ITCM
		(*(vu32*)(i+0x00800000)) = 0x00000000;      //clear DTCM
	}
	
	for (i=16*1024; i<32*1024; i+=4) {  //second 16KB
		(*(vu32*)(i+0x00000000)) = 0x00000000;      //clear ITCM
	}

	arm9_stateFlag = ARM9_MEMCLR;

	(*(vu32*)0x00803FFC) = 0;   //IRQ_HANDLER ARM9 version
	(*(vu32*)0x00803FF8) = ~0;  //VBLANK_INTR_WAIT_FLAGS ARM9 version

	//clear out ARM9 DMA channels
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

	VRAM_A_CR = 0x80;
	VRAM_B_CR = 0x80;
// Don't mess with the VRAM used for execution
//	VRAM_C_CR = 0;
	VRAM_D_CR = 0x80;
	VRAM_E_CR = 0x80;
	VRAM_F_CR = 0x80;
	VRAM_G_CR = 0x80;
	VRAM_H_CR = 0x80;
	VRAM_I_CR = 0x80;
	BG_PALETTE[0] = 0xFFFF;
	dmaFill((void*)&arm9_BLANK_RAM, BG_PALETTE+1, (2*1024)-2);
	dmaFill((void*)&arm9_BLANK_RAM, OAM,     2*1024);
	dmaFill((void*)&arm9_BLANK_RAM, (void*)0x04000000, 0x56);  //clear main display registers
	dmaFill((void*)&arm9_BLANK_RAM, (void*)0x04001000, 0x56);  //clear sub  display registers
	dmaFill((void*)&arm9_BLANK_RAM, VRAM_A,  256*1024);		// Banks A, B
	dmaFill((void*)&arm9_BLANK_RAM, VRAM_D,  272*1024);		// Banks D, E, F, G, H, I

	REG_DISPSTAT = 0;
	videoSetMode(0);
	videoSetModeSub(0);
	VRAM_A_CR = 0;
	VRAM_B_CR = 0;
// Don't mess with the VRAM used for execution
//	VRAM_C_CR = 0;
	VRAM_D_CR = 0;
	VRAM_E_CR = 0;
	VRAM_F_CR = 0;
	VRAM_G_CR = 0;
	VRAM_H_CR = 0;
	VRAM_I_CR = 0;
	REG_POWERCNT  = 0x820F;

	// set ARM9 state to ready and wait for it to change again
	arm9_stateFlag = ARM9_READY;
	while ( arm9_stateFlag != ARM9_BOOTBIN ) {
		if (arm9_stateFlag == ARM9_DISPERR) {
			// arm9_errorOutput (arm9_errorCode, arm9_errorClearBG);
			if ( arm9_stateFlag == ARM9_DISPERR) {
				arm9_stateFlag = ARM9_READY;
			}
		}
	}
	
	// wait for vblank then boot
	while(REG_VCOUNT!=191);
	while(REG_VCOUNT==191);
	
	u32 first = *(u32*)(0x27FFE34);
	
	// arm9_errorOutput (*(u32*)(first), true);

	void (*newReset)() = *(u32*)(0x27FFE24);

	newReset();
}

