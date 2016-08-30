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

#include "bios_decompress_callback.h"

#define CONSOLE_SCREEN_WIDTH 32
#define CONSOLE_SCREEN_HEIGHT 24

#include "bootsplash.h"


#include "Bot00.h"
#include "Bot01.h"
#include "Bot02.h"
#include "Bot03.h"
#include "Bot04.h"
#include "Bot05.h"
#include "Bot06.h"
#include "Bot07.h"
#include "Bot08.h"
#include "Bot09.h"
#include "Bot10.h"

#include "Top00.h"
#include "Top01.h"
#include "Top02.h"
#include "Top03.h"
#include "Top04.h"
#include "Top05.h"
#include "Top06.h"
#include "Top07.h"
#include "Top08.h"
#include "Top09.h"
#include "Top10.h"
#include "Top11.h"
#include "Top12.h"
#include "Top13.h"
#include "Top14.h"
#include "Top15.h"
#include "Top16.h"
#include "Top17.h"
#include "Top18.h"
#include "Top19.h"
#include "Top20.h"
#include "Top21.h"
#include "Top22.h"
#include "Top23.h"
#include "Top24.h"
#include "Top25.h"
#include "Top26.h"
#include "Top27.h"
#include "Top28.h"
#include "Top29.h"
#include "Top30.h"
#include "Top31.h"
#include "Top32.h"
#include "Top33.h"
#include "Top34.h"
#include "Top35.h"
#include "Top36.h"
#include "Top37.h"

void vramcpy2 (void* dest, const void* src, int size) 
{
	u16* destination = (u16*)dest;
	u16* source = (u16*)src;
	while (size > 0) {
		*destination++ = *source++;
		size-=2;
	}
}

void BootSplashNormal() {
 	swiDecompressLZSSVram ((void*)Top00Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top00Pal, Top00PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot00Pal, Bot00PalLen);

	u16* bgMapTop00 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub00 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop00[i] = (u16)i;
		bgMapSub00[i] = (u16)i;
	}
	
	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top01Pal, Top01PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot01Pal, Bot01PalLen);

	u16* bgMapTop01 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub01 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop01[i] = (u16)i;
		bgMapSub01[i] = (u16)i;
	}
	
	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top02Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top02Pal, Top02PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot02Pal, Bot02PalLen);
	
	u16* bgMapTop02 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub02 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop02[i] = (u16)i;
		bgMapSub02[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top03Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top03Pal, Top03PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot03Pal, Bot03PalLen);


	u16* bgMapTop03 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub03 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop03[i] = (u16)i;
		bgMapSub03[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top04Pal, Top04PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot04Pal, Bot04PalLen);

	u16* bgMapTop04 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub04 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop04[i] = (u16)i;
		bgMapSub04[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top05Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top05Pal, Top05PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop05 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub05 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop05[i] = (u16)i;
		bgMapSub05[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top06Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top06Pal, Top06PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop06 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub06 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop06[i] = (u16)i;
		bgMapSub06[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top07Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top07Pal, Top07PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop07 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub07 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop07[i] = (u16)i;
		bgMapSub07[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top08Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top08Pal, Top08PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop08 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub08 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop08[i] = (u16)i;
		bgMapSub08[i] = (u16)i;
	}

	swiDecompressLZSSVram ((void*)Top09Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top09Pal, Top09PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop09 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub09 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop09[i] = (u16)i;
		bgMapSub09[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top10Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top10Pal, Top10PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop10 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub10 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop10[i] = (u16)i;
		bgMapSub10[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top11Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top11Pal, Top11PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop11 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub11 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop11[i] = (u16)i;
		bgMapSub11[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top12Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top12Pal, Top12PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop12 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub12 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop12[i] = (u16)i;
		bgMapSub12[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top13Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top13Pal, Top13PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop13 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub13 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop13[i] = (u16)i;
		bgMapSub13[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top14Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top14Pal, Top14PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop14 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub14 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop14[i] = (u16)i;
		bgMapSub14[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top15Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top15Pal, Top15PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop15 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub15 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop15[i] = (u16)i;
		bgMapSub15[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top16Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top16Pal, Top16PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop16 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub16 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop16[i] = (u16)i;
		bgMapSub16[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top17Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top17Pal, Top17PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop17 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub17 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop17[i] = (u16)i;
		bgMapSub17[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top18Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top18Pal, Top18PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop18 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub18 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop18[i] = (u16)i;
		bgMapSub18[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top19Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top19Pal, Top19PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop19 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub19 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop19[i] = (u16)i;
		bgMapSub19[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top20Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top20Pal, Top20PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop20 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub20 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop20[i] = (u16)i;
		bgMapSub20[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top21Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top21Pal, Top21PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop21 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub21 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop21[i] = (u16)i;
		bgMapSub21[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top22Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top22Pal, Top22PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop22 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub22 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop22[i] = (u16)i;
		bgMapSub22[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top23Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top23Pal, Top23PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop23 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub23 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop23[i] = (u16)i;
		bgMapSub23[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top24Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top24Pal, Top24PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop24 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub24 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop24[i] = (u16)i;
		bgMapSub24[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top25Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top25Pal, Top25PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop25 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub25 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop25[i] = (u16)i;
		bgMapSub25[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top26Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top26Pal, Top26PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop26 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub26 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop26[i] = (u16)i;
		bgMapSub26[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top27Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top27Pal, Top27PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop27 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub27 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop27[i] = (u16)i;
		bgMapSub27[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top28Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top28Pal, Top28PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop28 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub28 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop28[i] = (u16)i;
		bgMapSub28[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top29Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top29Pal, Top29PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop29 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub29 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop29[i] = (u16)i;
		bgMapSub29[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top30Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top30Pal, Top30PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop30 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub30 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop30[i] = (u16)i;
		bgMapSub30[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top31Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top31Pal, Top31PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	u16* bgMapTop31 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub31 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop31[i] = (u16)i;
		bgMapSub31[i] = (u16)i;
	}

	for (int i = 0; i < 80; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top32Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot06Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top32Pal, Top32PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot06Pal, Bot06PalLen);

	u16* bgMapTop32 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub32 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop32[i] = (u16)i;
		bgMapSub32[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}
	
	// Pause here for a second
	swiDecompressLZSSVram ((void*)Top33Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot07Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top33Pal, Top33PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot07Pal, Bot07PalLen);

	u16* bgMapTop33 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub33 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop33[i] = (u16)i;
		bgMapSub33[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top34Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot08Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top34Pal, Top34PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot08Pal, Bot08PalLen);

	u16* bgMapTop34 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub34 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop34[i] = (u16)i;
		bgMapSub34[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top35Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot09Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top35Pal, Top35PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot09Pal, Bot09PalLen);

	u16* bgMapTop35 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub35 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop35[i] = (u16)i;
		bgMapSub35[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top36Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot10Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top36Pal, Top36PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot10Pal, Bot10PalLen);

	u16* bgMapTop36 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub36 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop36[i] = (u16)i;
		bgMapSub36[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

	swiDecompressLZSSVram ((void*)Top37Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot10Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top37Pal, Top37PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot10Pal, Bot10PalLen);

	u16* bgMapTop37 = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub37 = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop37[i] = (u16)i;
		bgMapSub37[i] = (u16)i;
	}

	for (int i = 0; i < 3.75; i++) {
		swiWaitForVBlank();
	}

}

