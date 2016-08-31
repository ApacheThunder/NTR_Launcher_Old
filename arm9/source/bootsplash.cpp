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
#include <maxmod9.h>
#include <stdio.h>

#include "soundbank.h"
#include "soundbank_bin.h"
 
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

void BootJingle() {
	mmInitDefaultMem((mm_addr)soundbank_bin);
	
	mmLoadEffect( SFX_BOOM );

	mm_sound_effect boom = {
		{ SFX_BOOM } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};
	
	mmEffectEx(&boom);
}

void BootSplashNormal() {

	swiWaitForVBlank();

 	swiDecompressLZSSVram ((void*)Top00Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top00Pal, Top00PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot00Pal, Bot00PalLen);

	// Using just swiWaitForVblank results in the perfect timing.
	// With current code, this appears to be nearly 16FPS exactly.
	// for (int i = 0; i < 3; i++) { swiWaitForVBlank(); }
	swiWaitForVBlank();
	
	swiDecompressLZSSVram ((void*)Top01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top01Pal, Top01PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot01Pal, Bot01PalLen);
		
	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top02Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top02Pal, Top02PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot02Pal, Bot02PalLen);
	
	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top03Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top03Pal, Top03PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot03Pal, Bot03PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top04Pal, Top04PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot04Pal, Bot04PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top05Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top05Pal, Top05PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	swiWaitForVBlank();

	// Once frame 8 is reached boot jingle sound effect plays
	BootJingle();

	swiDecompressLZSSVram ((void*)Top06Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top06Pal, Top06PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top07Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top07Pal, Top07PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top08Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top08Pal, Top08PalLen);

	swiWaitForVBlank();
	
	swiDecompressLZSSVram ((void*)Top09Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top09Pal, Top09PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top10Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top10Pal, Top10PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top11Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top11Pal, Top11PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top12Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top12Pal, Top12PalLen);
	
	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top13Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top13Pal, Top13PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top14Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top14Pal, Top14PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top15Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top15Pal, Top15PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top16Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top16Pal, Top16PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top17Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top17Pal, Top17PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top18Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top18Pal, Top18PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top19Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top19Pal, Top19PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top20Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top20Pal, Top20PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top21Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top21Pal, Top21PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top22Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top22Pal, Top22PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top23Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top23Pal, Top23PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top24Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top24Pal, Top24PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top25Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top25Pal, Top25PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top26Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top27Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top27Pal, Top27PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top28Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top28Pal, Top28PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top29Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top29Pal, Top29PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top30Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top30Pal, Top30PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top31Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top31Pal, Top31PalLen);

	// Pause on frame 31 for a second
	for (int i = 0; i < 60; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)Top32Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot06Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top32Pal, Top32PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot06Pal, Bot06PalLen);

	swiWaitForVBlank();
	
	swiDecompressLZSSVram ((void*)Top33Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot07Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top33Pal, Top33PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot07Pal, Bot07PalLen);

	swiWaitForVBlank();	

	swiDecompressLZSSVram ((void*)Top34Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot08Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top34Pal, Top34PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot08Pal, Bot08PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top35Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot09Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top35Pal, Top35PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot09Pal, Bot09PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top36Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot10Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top36Pal, Top36PalLen);
	vramcpy2 (&BG_PALETTE_SUB[0], Bot10Pal, Bot10PalLen);

	swiWaitForVBlank();

	swiDecompressLZSSVram ((void*)Top37Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy2 (&BG_PALETTE[0], Top37Pal, Top37PalLen);

	swiWaitForVBlank();
}

