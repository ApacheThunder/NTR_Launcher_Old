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

#include "errorsplash.h"
#include "bios_decompress_callback.h"

#include "fade00.h"
#include "fade01.h"
#include "fade02.h"
#include "fade03.h"
#include "fade04.h"

#include "suberror00.h"
#include "suberror01.h"
#include "suberror02.h"
#include "suberror03.h"
#include "suberror04.h"
#include "suberror05.h"
#include "suberror06.h"

#include "toperror1_00.h"
#include "toperror1_01.h"
#include "toperror1_02.h"
#include "toperror1_03.h"
#include "toperror1_04.h"
#include "toperror1_05.h"
#include "toperror1_06.h"

#include "toperror2_00.h"
#include "toperror2_01.h"
#include "toperror2_02.h"
#include "toperror2_03.h"
#include "toperror2_04.h"
#include "toperror2_05.h"
#include "toperror2_06.h"

void vramcpy3 (void* dest, const void* src, int size) 
{
	u16* destination = (u16*)dest;
	u16* source = (u16*)src;
	while (size > 0) {
		*destination++ = *source++;
		size-=2;
	}
}

void FadeFX() {

 	swiDecompressLZSSVram ((void*)fade00Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)fade00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], fade00Pal, fade00PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], fade00Pal, fade00PalLen);

	swiWaitForVBlank();
	
 	swiDecompressLZSSVram ((void*)fade01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)fade01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], fade01Pal, fade01PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], fade01Pal, fade01PalLen);

	swiWaitForVBlank();
	
 	swiDecompressLZSSVram ((void*)fade02Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)fade02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], fade02Pal, fade02PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], fade02Pal, fade02PalLen);

	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)fade03Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)fade03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], fade03Pal, fade03PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], fade03Pal, fade03PalLen);

	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)fade04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)fade04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], fade04Pal, fade04PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], fade04Pal, fade04PalLen);	

	swiWaitForVBlank();
}


void ErrorNoBit31() {
	
	FadeFX();

 	swiDecompressLZSSVram ((void*)toperror1_00Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror1_00Pal, toperror1_00PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror00Pal, suberror00PalLen);
	
	swiWaitForVBlank();
	
 	swiDecompressLZSSVram ((void*)toperror1_01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror1_01Pal, toperror1_01PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror01Pal, suberror01PalLen);
	
	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)toperror1_02Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror1_02Pal, toperror1_02PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror02Pal, suberror02PalLen);
	
	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)toperror1_03Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror1_03Pal, toperror1_03PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror03Pal, suberror03PalLen);
	
	swiWaitForVBlank();
	
	// Wait for input, then fade out
	do { swiWaitForVBlank(); scanKeys(); } while (!keysDown());

 	swiDecompressLZSSVram ((void*)toperror1_04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror1_04Pal, toperror1_04PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror04Pal, suberror04PalLen);
	
	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)toperror1_05Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror1_05Pal, toperror1_05PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror05Pal, suberror05PalLen);
	
 	swiDecompressLZSSVram ((void*)toperror1_06Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror06Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror1_06Pal, toperror1_06PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror06Pal, suberror06PalLen);
	
	swiWaitForVBlank();
	
	swiDecompressLZSSVram ((void*)fade04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)fade04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], fade04Pal, fade04PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], fade04Pal, fade04PalLen);
	
	swiWaitForVBlank();
}

void ErrorNoCard() {
	
	FadeFX();

 	swiDecompressLZSSVram ((void*)toperror2_00Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror2_00Pal, toperror2_00PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror00Pal, suberror00PalLen);
	
	swiWaitForVBlank();
	
 	swiDecompressLZSSVram ((void*)toperror2_01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror2_01Pal, toperror2_01PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror01Pal, suberror01PalLen);
	
	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)toperror2_02Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror2_02Pal, toperror2_02PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror02Pal, suberror02PalLen);
	
	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)toperror2_03Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror2_03Pal, toperror2_03PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror03Pal, suberror03PalLen);
	
	swiWaitForVBlank();
	
	// Wait for input, then fade out
	do { swiWaitForVBlank(); scanKeys(); } while (!keysDown());

 	swiDecompressLZSSVram ((void*)toperror2_04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror2_04Pal, toperror2_04PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror04Pal, suberror04PalLen);
	
	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)toperror2_05Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror2_05Pal, toperror2_05PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror05Pal, suberror05PalLen);
	
 	swiDecompressLZSSVram ((void*)toperror2_06Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)suberror06Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], toperror2_06Pal, toperror2_06PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], suberror06Pal, suberror06PalLen);
	
	swiWaitForVBlank();
	
	swiDecompressLZSSVram ((void*)fade04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)fade04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy3 (&BG_PALETTE[0], fade04Pal, fade04PalLen);
	vramcpy3 (&BG_PALETTE_SUB[0], fade04Pal, fade04PalLen);
	
	swiWaitForVBlank();
}

