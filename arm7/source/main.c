/*
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

#include <nds.h>
#include <nds/arm7/input.h>
#include <nds/system.h>

#include <maxmod7.h>

#include "launch_engine_arm7.h"

void VcountHandler() {
	inputGetAndSend();
}

void VblankHandler(void) {
}

// volatile u32* ROMCTRL = (volatile u32*)0x40001A4;
// volatile u32* SCFG_ROM = (volatile u32*)0x4004000;
// volatile u32* SCFG_CLK = (volatile u32*)0x4004004;
// volatile u32* SCFG_EXT = (volatile u32*)0x4004008; 
// volatile u32* SCFG_MC = (volatile u32*)0x4004010; 

int main(void) {

	irqInit();
	fifoInit();

	REG_SCFG_CLK = 0x0187;
	REG_SCFG_EXT = 0x93FFFB00; // NAND/SD Access
	// REG_SCFG_EXT=0x92A00000;

	// read User Settings from firmware
	readUserSettings();

	// Start the RTC tracking IRQ
	initClockIRQ();

	mmInstall(FIFO_MAXMOD);

	SetYtrigger(80);

	installSoundFIFO();
	installSystemFIFO();

	irqSet(IRQ_VCOUNT, VcountHandler);
	irqSet(IRQ_VBLANK, VblankHandler);

	irqEnable( IRQ_VBLANK | IRQ_VCOUNT);

	// ResetSlot();
	dsi_resetSlot1();
	fifoSendValue32(FIFO_USER_01, 1); 

	while (1) {
		runLaunchEngineCheck();
		swiWaitForVBlank();
	}
}

