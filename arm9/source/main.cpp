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
	
	unsigned int * SCFG_CLK=(unsigned int*)0x4004004; 
 	
 	// No Speed boost for now
	// *SCFG_CLK=	*SCFG_CLK | 1; 		

	// 3 second delay before continuing. If new CPU boost code is enabled, load screen is black.
	// Not sure why that happens. Timing for this is a bit narrower if CPU clock speeds boosted but withen pratical limits for testing purposes.
	for (int i = 0; i < 60; i++) {
		swiWaitForVBlank();
	}
	// Now using stripped down "launch engine" instead of cheat engine system.
	runLaunchEngine ();

}

