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

#include "ui.h"
#include "nds_card.h"
#include "launch_engine.h"
#include "crc.h"
#include "version.h"


int main(int argc, const char* argv[])
{
	u32* cheatDest;
	int curCheat = 0;
	char gameid[4];
	uint32_t headerCRC;
	
	// 3 second delay before continuing.
	for (int i = 0; i < 60; i++) {
		swiWaitForVBlank();
	}
	
	// Set arm9 speed to DSi speeds. Only works with patched dev Launcher. Else has no effect.
	// This is set on arm7 side as well.
		unsigned int * SCFG_ROM=	(unsigned int*)0x4004000;
		unsigned int * SCFG_CLK=	(unsigned int*)0x4004004; 
		unsigned int * SCFG_EXT=	(unsigned int*)0x4004008;

			if(*SCFG_EXT==0) {
				// Display no text here. Graphics for general status. Text not enabled in this exmaple.		
				*SCFG_EXT = 0x830F0100;
			}
	
		*SCFG_CLK=	*SCFG_CLK | 1;

		// Attempt to return to NTR mode if in TWL mode. Untested at the moment. Probably doensn't do anything.
		if(*SCFG_EXT & 0x80000000 != 0)  {
				if (*SCFG_ROM & 0x03==0x01) {
					*SCFG_ROM = 0;
				}
			}

	// Now using stripped down "launch engine" instead of cheat engine system.
	runLaunchEngine ();
}

