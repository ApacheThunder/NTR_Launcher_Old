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
#include <fat.h>
#include <nds/fifocommon.h>

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <list>

#include "inifile.h"
#include "bootsplash.h"
#include "nds_card.h"
#include "launch_engine.h"
#include "crc.h"
#include "version.h" 

// #define REG_ROMCTRL		(*(vu32*)0x40001A4)
// #define REG_SCFG_ROM	(*(vu32*)0x4004000)
#define REG_SCFG_CLK	(*(vu32*)0x4004004)
#define REG_SCFG_EXT	(*(vu32*)0x4004008)
#define REG_SCFG_MC		(*(vu32*)0x4004010)


int main(int argc, const char* argv[]) {

	// volatile u32* REG_SCFG_EXT = (volatile u32*)0x4004008;
	// volatile u32* REG_SCFG_CLK = (volatile u32*)0x4004004;
	// volatile u32* REG_SCFG_MC = (volatile u32*)0x4004010;
	// volatile u32* REG_SCFG_ROM = (volatile u32*)0x4004000;

	// REG_SCFG_EXT = 0x8307F100;
	
	// NTR Mode/Splash used by default
	bool UseNTRSplash = true;
	bool EnableSD = false;

	REG_SCFG_CLK = 0x85;

	swiWaitForVBlank();

	// If slot is powered off, tell Arm7 slot power on is required.
	if(REG_SCFG_MC == 0x11) { fifoSendValue32(FIFO_USER_02, 1); }
	if(REG_SCFG_MC == 0x10) { fifoSendValue32(FIFO_USER_02, 1); }

	// Will wait till implemented in official libnds
	// dsi_forceTouchDsmode();

	u32 ndsHeader[0x80];
	char gameid[4];
	uint32_t headerCRC;
	
	scanKeys();
	int pressed = keysDown();

	if (fatInitDefault()) {
		CIniFile ntrlauncher_config( "sd:/nds/ntr_launcher.ini" );
		
		if(ntrlauncher_config.GetInt("NTRLAUNCHER_ALT","NTRCLOCK",0) == 0) { UseNTRSplash = false; }

		if(ntrlauncher_config.GetInt("NTRLAUNCHER_ALT","DISABLEANIMATION",0) == 0) {
			if( pressed & KEY_B ) { if(REG_SCFG_MC == 0x11) { BootSplashInit(UseNTRSplash); } } else { BootSplashInit(UseNTRSplash); }
		} else {
			if(REG_SCFG_MC == 0x11) { BootSplashInit(UseNTRSplash); }
		}

		if( UseNTRSplash == true ) {
			fifoSendValue32(FIFO_USER_04, 1);
			REG_SCFG_CLK = 0x80;
			swiWaitForVBlank();
		}

		if(ntrlauncher_config.GetInt("NTRLAUNCHER_ALT","ENABLESD",0) == 1) {
			EnableSD = true;
			// Tell Arm7 to use alternate SCFG_EXT values.
			fifoSendValue32(FIFO_USER_05, 1);
		}

		if(ntrlauncher_config.GetInt("NTRLAUNCHER_ALT","TWLMODE",0) == 1) {
			// Tell Arm7 not to switch into NTR mode (this will only work on alt build of NTR Launcher)
			fifoSendValue32(FIFO_USER_06, 1);
		}

		if(ntrlauncher_config.GetInt("NTRLAUNCHER_ALT","RESETSLOT1",0) == 1) {
			fifoSendValue32(FIFO_USER_02, 1);
			fifoSendValue32(FIFO_USER_07, 1);
		}

	} else {
		if ( pressed & KEY_B ) { if(REG_SCFG_MC == 0x11) { BootSplashInit(UseNTRSplash); } } else { BootSplashInit(UseNTRSplash); }
	}

	// Tell Arm7 it's ready for card reset (if card reset is nessecery)
	fifoSendValue32(FIFO_USER_01, 1);
	// Waits for Arm7 to finish card reset (if nessecery)
	fifoWaitValue32(FIFO_USER_03);


	// Wait for card to stablize before continuing
	for (int i = 0; i < 20; i++) { swiWaitForVBlank(); }

	sysSetCardOwner (BUS_OWNER_ARM9);

	getHeader (ndsHeader);

	for (int i = 0; i < 20; i++) { swiWaitForVBlank(); }
	
	memcpy (gameid, ((const char*)ndsHeader) + 12, 4);
	headerCRC = crc32((const char*)ndsHeader, sizeof(ndsHeader));

	while(1) {
		if(REG_SCFG_MC == 0x11) { 
		break; } else {
			runLaunchEngine (UseNTRSplash, EnableSD);
		}
	}
	return 0;
}

