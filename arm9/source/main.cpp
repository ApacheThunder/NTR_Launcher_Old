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
#include <fat.h>
#include <string.h>
#include <malloc.h>
#include <list>
// #include <nds/fifocommon.h>

#include "ui.h"
#include "nds_card.h"
#include "launch_engine.h"
#include "crc.h"
#include "version.h" 

int main() {

	unsigned int * SCFG_EXT=(unsigned int*)0x4004008;
	unsigned int * SCFG_MC=(unsigned int*)0x4004010;
	
	// fifoWaitValue32(FIFO_USER_01);

	main_ui();
	
	// For now, program stops here if slot is detected as ejected (booted when no cartridge was inserted)
	if(*SCFG_MC == 0x11) { 
	// Do nothing. Card init fails and code from NitroHax that fixes this doesn't work here yet.
	} else { 
		// SCFG_EXT is never actually all zero in NTR mode (just not readable in NTR mode).
		// If it reports as zero that means bit31 was not patched out.
		// We'll indicate to the user that they have not patched it out correctly.
		if(*SCFG_EXT == 0x00000000) {
			// Do nothing
		} else {
				runLaunchEngine ();
			}
	}

}

