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

#include "ui.h"

#include "bios_decompress_callback.h"

#include "bootsplash.h"

#include "bgtop.h"
#include "bgtop2.h"
#include "bgsub.h"

#define CONSOLE_SCREEN_WIDTH 32
#define CONSOLE_SCREEN_HEIGHT 24


void vramcpy (void* dest, const void* src, int size) 
{
	u16* destination = (u16*)dest;
	u16* source = (u16*)src;
	while (size > 0) {
		*destination++ = *source++;
		size-=2;
	}
}


void ErrorNoCard() {
 	swiDecompressLZSSVram ((void*)bgtopTiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)bgsubTiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy (&BG_PALETTE[0], bgtopPal, bgtopPalLen);
	vramcpy (&BG_PALETTE_SUB[0], bgsubPal, bgsubPalLen);
	u16* bgMapTop2 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub2 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
		for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
			bgMapTop2[i] = (u16)i;
			bgMapSub2[i] = (u16)i;
		}
	for (int i = 0; i < 320; i++) { swiWaitForVBlank(); }
}

void ErrorNoBit31() {
 	swiDecompressLZSSVram ((void*)bgtop2Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)bgsubTiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy (&BG_PALETTE[0], bgtop2Pal, bgtop2PalLen);
	vramcpy (&BG_PALETTE_SUB[0], bgsubPal, bgsubPalLen);
	u16* bgMapTop = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub = (u16*)SCREEN_BASE_BLOCK_SUB(0);
		for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
			bgMapTop[i] = (u16)i;
			bgMapSub[i] = (u16)i;
		}
	for (int i = 0; i < 320; i++) { swiWaitForVBlank(); }
}

void main_ui() {
	unsigned int * SCFG_MC=(unsigned int*)0x4004010;
	unsigned int * SCFG_EXT=(unsigned int*)0x4004008;

	videoSetMode(MODE_0_2D | DISPLAY_BG0_ACTIVE);
	videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE);
	vramSetBankA (VRAM_A_MAIN_BG_0x06000000);
	vramSetBankC (VRAM_C_SUB_BG_0x06200000);
	REG_BG0CNT = BG_MAP_BASE(0) | BG_COLOR_256| BG_TILE_BASE(2) | BG_PRIORITY(2);
	REG_BG0CNT_SUB = BG_MAP_BASE(0) | BG_COLOR_256 | BG_TILE_BASE(2) | BG_PRIORITY(2);
	BG_PALETTE[0]=0;   
	BG_PALETTE[255]=0xffff;

	// Boot Splash will always play.
	BootSplashNormal();
	
	// Load alternate UI with an error occured. Currently 2 error screns and one normal.
	if(*SCFG_EXT == 0x0) { ErrorNoBit31(); }
	if(*SCFG_MC == 0x11) { ErrorNoCard(); }
}

