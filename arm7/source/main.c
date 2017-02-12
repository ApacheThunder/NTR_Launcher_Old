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

#define REG_ROMCTRL		(*(vu32*)0x40001A4)
#define REG_SCFG_ROM	(*(vu32*)0x4004000)
#define REG_SCFG_CLK	(*(vu32*)0x4004004)
#define REG_SCFG_EXT	(*(vu32*)0x4004008)
#define REG_SCFG_MC		(*(vu32*)0x4004010)

void VcountHandler() {
	inputGetAndSend();
}

void VblankHandler(void) {
}

void PowerOnSlot() {
	// Power On Slot
	while(REG_SCFG_MC&0x0C !=  0x0C); // wait until state<>3
	if(REG_SCFG_MC&0x0C != 0x00) return; //  exit if state<>0
	
	REG_SCFG_MC = 0x04;    // wait 1ms, then set state=1
	while(REG_SCFG_MC&0x0C != 0x04);
	
	REG_SCFG_MC = 0x08;    // wait 10ms, then set state=2      
	while(REG_SCFG_MC&0x0C != 0x08);
	
	REG_ROMCTRL = 0x20000000; // wait 27ms, then set ROMCTRL=20000000h
	
	while(REG_ROMCTRL&0x8000000 != 0x8000000);
	
}

void PowerOffSlot() {
	while(REG_SCFG_MC&0x0C !=  0x0C); // wait until state<>3
	if(REG_SCFG_MC&0x0C != 0x08) return 1; // exit if state<>2      
	
	REG_SCFG_MC = 0x0C; // set state=3 
	while(REG_SCFG_MC&0x0C != 0x00); // wait until state=0
}

void TWL_ResetSlot1() {
	PowerOffSlot();
	for (int i = 0; i < 30; i++) { swiWaitForVBlank(); }
	PowerOnSlot(); 
}

int main(void) {

	REG_SCFG_CLK = 0x0187;
	
	irqInit();
	fifoInit();

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
	
	// Make sure Arm9 had a chance to check slot status
	fifoWaitValue32(FIFO_USER_01);
	// If Arm9 reported slot is powered off, have Arm7 wait for Arm9 to be ready before card reset. This makes sure arm7 doesn't try card reset too early.
	if(fifoCheckValue32(FIFO_USER_02)) { 
		if(fifoCheckValue32(FIFO_USER_07)) { TWL_ResetSlot1(); } else { PowerOnSlot(); }
	}
	fifoSendValue32(FIFO_USER_03, 1);
	
	while (1) {
		runLaunchEngineCheck();
		swiWaitForVBlank();
	}
}

