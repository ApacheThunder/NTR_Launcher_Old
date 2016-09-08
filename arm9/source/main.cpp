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
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <list>
#include <nds/fifocommon.h>

#include "bootsplash.h"

#include "nds_card.h"
#include "launch_engine.h"
#include "crc.h"
#include "version.h"


int main() {

	//volatile u32* SCFG_EXT = (volatile u32*)0x4004008;
	//volatile u32* SCFG_CLK = (volatile u32*)0x4004004;
	//volatile u32* SCFG_MC = (volatile u32*)0x4004010; 	
	
	dsi_forceTouchDsmode();

	REG_SCFG_CLK = 0x85;
	REG_SCFG_EXT = 0x8307F100; // NAND/SD Access

	BootSplashNormal();

	// Waits for arm7 to power off slot before continuing
	fifoWaitValue32(FIFO_USER_01);

	swiWaitForVBlank();

	while(1) {
		if(REG_SCFG_MC == 0x11) { 
		break; } else {
			runLaunchEngine ();
		}
	}
	return 0;
}

