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

void runLaunchEngineCheck (void)
{
	if(*((vu32*)0x027FFE24) == (u32)0x027FFE04)
	{

		// SCFG_CLK
		// 0x0180 : NTR
		// 0x0187 : TWL
		// Check if Arm9 wants TWL mode clock speeds. If so, SCFG_CLK on arm7 won't get set to keep twl clk on arm7.
		// Arm9 SCFG_CLK is set on Arm9 refer to bootsplash.cpp. That's where it will get set
		if(fifoCheckValue32(FIFO_USER_02)) { REG_SCFG_CLK=0x0180; } else { /* Do nothing */ }
		
		REG_SCFG_ROM=0x703;
		REG_SCFG_EXT = 0x12A00000;

		irqDisable (IRQ_ALL);
		*((vu32*)0x027FFE34) = (u32)0x06000000;

		swiSoftReset();
	} 
}

