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
#include <vector>
#include <stack>
#include <algorithm>
#include <unistd.h>
#include <dirent.h>
#include "ui.h"
#include "bios_decompress_callback.h"

#include "font.h"
#include "bgtop.h"
#include "bgtop2.h"
#include "bgtop3.h"
#include "bgsub.h"
#include "bgsub2.h"

#define CONSOLE_SCREEN_WIDTH 32
#define CONSOLE_SCREEN_HEIGHT 24

using namespace std;


UserInterface ui;

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
 	swiDecompressLZSSVram ((void*)bgtop2Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)bgsub2Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy (&BG_PALETTE[0], bgtop2Pal, bgtop2PalLen);
	vramcpy (&BG_PALETTE_SUB[0], bgsub2Pal, bgsub2PalLen);
	u16* bgMapTop2 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub2 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
		for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
			bgMapTop2[i] = (u16)i;
			bgMapSub2[i] = (u16)i;
		}
}

void ErrorNoBit31() {
 	swiDecompressLZSSVram ((void*)bgtop3Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)bgsub2Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy (&BG_PALETTE[0], bgtop3Pal, bgtop3PalLen);
	vramcpy (&BG_PALETTE_SUB[0], bgsub2Pal, bgsub2PalLen);
	u16* bgMapTop3 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub2 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
		for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
			bgMapTop3[i] = (u16)i;
			bgMapSub2[i] = (u16)i;
		}
}

 void NormalUI() {
 	swiDecompressLZSSVram ((void*)bgtopTiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)bgsubTiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy (&BG_PALETTE[0], bgtopPal, bgtopPalLen);
	vramcpy (&BG_PALETTE_SUB[0], bgsubPal, bgsubPalLen);
	u16* bgMapTop = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub = (u16*)SCREEN_BASE_BLOCK_SUB(0);
		for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
			bgMapTop[i] = (u16)i;
			bgMapSub[i] = (u16)i;
		}
}


UserInterface::UserInterface (void) {
	unsigned int * SCFG_MC=(unsigned int*)0x4004010;
	unsigned int * SCFG_EXT=(unsigned int*)0x4004008;

	videoSetMode(MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE);
	// BG0 = backdrop
	// BG1 = text box background & border
	// BG2 = text
	vramSetBankA (VRAM_A_MAIN_BG_0x06000000);
	REG_BG0CNT = BG_MAP_BASE(0) | BG_COLOR_16 | BG_TILE_BASE(2) | BG_PRIORITY(2);
	REG_BG1CNT = BG_MAP_BASE(2) | BG_COLOR_16 | BG_TILE_BASE(4) | BG_PRIORITY(1);
	REG_BG2CNT = BG_MAP_BASE(4) | BG_COLOR_16 | BG_TILE_BASE(6) | BG_PRIORITY(0);
	BG_PALETTE[0]=0;   
	BG_PALETTE[255]=0xffff;

	videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE); // | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D);
	// BG0 = backdrop
	// BG1 = scrollbar & highlights
	// BG2 = text
	vramSetBankC (VRAM_C_SUB_BG_0x06200000);
	REG_BG0CNT_SUB = BG_MAP_BASE(0) | BG_COLOR_16 | BG_TILE_BASE(2) | BG_PRIORITY(2);
	REG_BG1CNT_SUB = BG_MAP_BASE(2) | BG_COLOR_16 | BG_TILE_BASE(4) | BG_PRIORITY(1);
	REG_BG2CNT_SUB = BG_MAP_BASE(4) | BG_COLOR_16 | BG_TILE_BASE(6) | BG_PRIORITY(0);

	// Load alternate UI with an error occured. Currently 2 error screns and one normal.
	// (normal screen always last in this chain)
	if(*SCFG_MC == 0x11) {
		ErrorNoCard();
		} else { 
			if(*SCFG_EXT == 0x0) { 
				ErrorNoBit31();
			} else {
				NormalUI(); } 
		}
}

UserInterface::~UserInterface () {
}

