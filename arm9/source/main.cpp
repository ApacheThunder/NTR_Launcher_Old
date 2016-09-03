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

#include "ui.h"
#include "nds_card.h"
#include "launch_engine.h"
#include "crc.h"
#include "version.h" 

// volatile u32* SCFG_EXT = (volatile u32*)0x4004008;
// volatile u32* SCFG_MC = (volatile u32*)0x4004010;
// volatile u32* SCFG_ROM = (volatile u32*)0x4004000;

int main() {
	
	REG_SCFG_CLK=0x85;
	
	// Waits for arm7 to power off slot before continuing
	fifoWaitValue32(FIFO_USER_01);
	
	swiWaitForVBlank();

	main_ui();

	swiWaitForVBlank();

while(1) {
	// For now, program stops here if slot is detected as ejected (booted when no cartridge was inserted)
	if(REG_SCFG_MC == 0x11) { 
	break;
	// Do nothing. Card init fails and code from NitroHax that fixes this doesn't work here yet.
	} else { 
		// SCFG_EXT is never actually all zero in NTR mode (just not readable in NTR mode).
		// If it reports as zero that means bit31 was not patched out.
		// We'll indicate to the user that they have not patched it out correctly.
		if(REG_SCFG_EXT == 0x00000000) {
			// Do nothing
			break;
		} else {
				runLaunchEngine ();
			}
		}
	}
	return 0;
}

