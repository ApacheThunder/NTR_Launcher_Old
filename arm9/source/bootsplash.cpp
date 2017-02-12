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

#include "soundbank.h"
#include "soundbank_bin.h"
 
#include "bios_decompress_callback.h"

#include "CartPrompt01.h"
#include "CartPrompt02.h"
#include "CartPrompt03.h"
#include "CartPrompt04.h"

#include "DSiCartPrompt01.h"
#include "DSiCartPrompt02.h"
#include "DSiCartPrompt03.h"
#include "DSiCartPrompt04.h"

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

#include "BotDSi00.h"
#include "BotDSi01.h"
#include "BotDSi02.h"
#include "BotDSi03.h"
#include "BotDSi04.h"
#include "BotDSi05.h"
#include "BotDSi06.h"
#include "BotDSi07.h"
#include "BotDSi08.h"
#include "BotDSi09.h"
#include "BotDSi10.h"
#include "BotDSi11.h"

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

#include "DSi01.h"
#include "DSi02.h"
#include "DSi03.h"
#include "DSi04.h"
#include "DSi05.h"
#include "DSi06.h"
#include "DSi07.h"
#include "DSi08.h"
#include "DSi09.h"
#include "DSi10.h"
#include "DSi11.h"
#include "DSi12.h"
#include "DSi13.h"
#include "DSi14.h"
#include "DSi15.h"
#include "DSi16.h"
#include "DSi17.h"
#include "DSi18.h"
#include "DSi19.h"
#include "DSi20.h"
#include "DSi21.h"
#include "DSi22.h"
#include "DSi23.h"
#include "DSi24.h"
#include "DSi25.h"
#include "DSi26.h"
#include "DSi27.h"
#include "DSi28.h"
#include "DSi29.h"
#include "DSi30.h"
#include "DSi31.h"
#include "DSi32.h"
#include "DSi33.h"
#include "DSi34.h"
#include "DSi35.h"

#include "errorsplash.h"

#include "bootsplash.h"

#define CONSOLE_SCREEN_WIDTH 32
#define CONSOLE_SCREEN_HEIGHT 24

#define REG_SCFG_MC		(*(vu32*)0x4004010)

void vramcpy_ui (void* dest, const void* src, int size) 
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
	
	mmLoadEffect( SFX_DSBOOT );

	mm_sound_effect dsboot = {
		{ SFX_DSBOOT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};
	
	mmEffectEx(&dsboot);
}

void BootJingleDSi() {
	
	mmInitDefaultMem((mm_addr)soundbank_bin);

	mmLoadEffect( SFX_DSIBOOT );

	mm_sound_effect dsiboot = {
		{ SFX_DSIBOOT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};
	
	mmEffectEx(&dsiboot);
}

void CartridgePrompt() {
	
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	for (int i = 0; i < 20; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)CartPrompt04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], CartPrompt04Pal, CartPrompt04PalLen);

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)CartPrompt03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], CartPrompt03Pal, CartPrompt03PalLen);

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)CartPrompt02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], CartPrompt02Pal, CartPrompt02PalLen);	

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)CartPrompt01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], CartPrompt01Pal, CartPrompt01PalLen);	

	for (int i = 0; i < 40; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)CartPrompt02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], CartPrompt02Pal, CartPrompt02PalLen);	

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)CartPrompt03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], CartPrompt03Pal, CartPrompt03PalLen);

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)CartPrompt04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], CartPrompt04Pal, CartPrompt04PalLen);

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	for (int i = 0; i < 20; i++) { swiWaitForVBlank(); }

}

void CartridgePromptDSi() {
	
	swiDecompressLZSSVram ((void*)BotDSi05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi05Pal, Bot05PalLen);

	for (int i = 0; i < 20; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)DSiCartPrompt04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], DSiCartPrompt04Pal, DSiCartPrompt04PalLen);

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSiCartPrompt03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], DSiCartPrompt03Pal, DSiCartPrompt03PalLen);

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSiCartPrompt02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], DSiCartPrompt02Pal, DSiCartPrompt02PalLen);	

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSiCartPrompt01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], DSiCartPrompt01Pal, DSiCartPrompt01PalLen);	

	for (int i = 0; i < 40; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSiCartPrompt02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], DSiCartPrompt02Pal, DSiCartPrompt02PalLen);	

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSiCartPrompt03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], DSiCartPrompt03Pal, DSiCartPrompt03PalLen);

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSiCartPrompt04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], DSiCartPrompt04Pal, DSiCartPrompt04PalLen);

	for (int i = 0; i < 4; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)BotDSi05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi05Pal, BotDSi05PalLen);

	for (int i = 0; i < 20; i++) { swiWaitForVBlank(); }

}

void BootSplashDSi() {

	swiDecompressLZSSVram ((void*)DSi01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi01Pal, DSi01PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi00Pal, BotDSi00PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi02Pal, DSi02PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi01Pal, BotDSi01PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi02Pal, DSi02PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi01Pal, BotDSi01PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)DSi01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi02Pal, DSi02PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi02Pal, BotDSi02PalLen);
	
	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)DSi02Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi03Pal, DSi03PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi03Pal, BotDSi03PalLen);
	
	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi03Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi03Pal, DSi03PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi03Pal, BotDSi03PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi04Pal, DSi04PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi04Pal, BotDSi04PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi05Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi05Pal, DSi05PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi05Pal, BotDSi05PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)DSi06Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi06Pal, DSi06PalLen);
	
	BootJingleDSi();
	
	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi07Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi07Pal, DSi07PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi08Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi08Pal, DSi08PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)DSi09Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi09Pal, DSi09PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi10Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi10Pal, DSi10PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi11Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi11Pal, DSi11PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi12Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi12Pal, DSi12PalLen);
	
	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi13Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi13Pal, DSi13PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi14Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi14Pal, DSi14PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi15Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi15Pal, DSi15PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi16Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi16Pal, DSi16PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi17Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi17Pal, DSi17PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)DSi18Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi18Pal, DSi18PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi19Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi19Pal, DSi19PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi20Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi20Pal, DSi20PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi21Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi21Pal, DSi21PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi22Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi22Pal, DSi22PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi23Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi23Pal, DSi23PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi24Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi24Pal, DSi24PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi25Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi25Pal, DSi25PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi26Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi26Pal, DSi26PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi27Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi27Pal, DSi27PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi28Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi28Pal, DSi28PalLen);

	// Display Cartridge Prompt animation until cartridge inserted. (skipped if one already inserted)
	if(REG_SCFG_MC == 0x11) { 
		do { CartridgePromptDSi(); } 
		while (REG_SCFG_MC == 0x11);
	}

	// Pause on frame 31 for a second		
	for (int i = 0; i < 80; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi29Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi06Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi29Pal, DSi29PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi06Pal, BotDSi06PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi30Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi07Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi30Pal, DSi30PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi07Pal, BotDSi07PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi31Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi08Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi31Pal, DSi31PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi08Pal, BotDSi08PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)DSi32Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi09Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi32Pal, DSi32PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi09Pal, BotDSi09PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)DSi33Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi10Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi33Pal, DSi33PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi10Pal, BotDSi10PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }	

	swiDecompressLZSSVram ((void*)DSi34Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi11Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi34Pal, DSi34PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi11Pal, BotDSi11PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)DSi35Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)BotDSi00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi35Pal, DSi35PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], BotDSi00Pal, BotDSi00PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }	

	swiDecompressLZSSVram ((void*)DSi01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], DSi01Pal, DSi01PalLen);

	if(REG_SCFG_MC == 0x11) { ErrorNoCard(); }
}

void BootSplashDS() {

	// offsetting palletes by one frame during the fade in seems to fix black flicker at start.	
	// only did this for about 5 frames. (time it takes for bottom screen to fade in)
	swiDecompressLZSSVram ((void*)Top00Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top01Pal, Top01PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot01Pal, Bot01PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top00Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top00Pal, Top00PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot00Pal, Bot00PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top00Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot00Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top00Pal, Top00PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot00Pal, Bot00PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)Top01Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot01Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top02Pal, Top02PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot02Pal, Bot02PalLen);
	
	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)Top02Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot02Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top03Pal, Top03PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot03Pal, Bot03PalLen);
	
	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top03Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot03Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top04Pal, Top04PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot04Pal, Bot04PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top04Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot04Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top05Pal, Top05PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot04Pal, Bot04PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top05Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot05Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top05Pal, Top05PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot05Pal, Bot05PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	BootJingle();
	
	swiDecompressLZSSVram ((void*)Top06Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top06Pal, Top06PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top07Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top07Pal, Top07PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top08Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top08Pal, Top08PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)Top09Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top09Pal, Top09PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top10Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top10Pal, Top10PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top11Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top11Pal, Top11PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top12Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top12Pal, Top12PalLen);
	
	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top13Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top13Pal, Top13PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top14Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top14Pal, Top14PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top15Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top15Pal, Top15PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top16Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top16Pal, Top16PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top17Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top17Pal, Top17PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)Top18Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top18Pal, Top18PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top19Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top19Pal, Top19PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top20Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top20Pal, Top20PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top21Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top21Pal, Top21PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top22Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top22Pal, Top22PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top23Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top23Pal, Top23PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top24Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top24Pal, Top24PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top25Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top25Pal, Top25PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top26Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top26Pal, Top26PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top27Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top27Pal, Top27PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top28Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top28Pal, Top28PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top29Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top29Pal, Top29PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top30Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top30Pal, Top30PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top31Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top31Pal, Top31PalLen);

	// Display Cartridge Prompt animation until cartridge inserted. (skipped if one already inserted)
	if(REG_SCFG_MC == 0x11) { 
		do { CartridgePrompt(); } 
		while (REG_SCFG_MC == 0x11);
	}

	// Pause on frame 31 for a second		
	for (int i = 0; i < 80; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top32Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot06Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top32Pal, Top32PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot06Pal, Bot06PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
	
	swiDecompressLZSSVram ((void*)Top33Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot07Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top33Pal, Top33PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot07Pal, Bot07PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }	

	swiDecompressLZSSVram ((void*)Top34Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot08Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top34Pal, Top34PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot08Pal, Bot08PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top35Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot09Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top35Pal, Top35PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot09Pal, Bot09PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top36Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	swiDecompressLZSSVram ((void*)Bot10Tiles, (void*)CHAR_BASE_BLOCK_SUB(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top36Pal, Top36PalLen);
	vramcpy_ui (&BG_PALETTE_SUB[0], Bot10Pal, Bot10PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }

	swiDecompressLZSSVram ((void*)Top37Tiles, (void*)CHAR_BASE_BLOCK(2), 0, &decompressBiosCallback);
	vramcpy_ui (&BG_PALETTE[0], Top37Pal, Top37PalLen);

	for (int i = 0; i < 2; i++) { swiWaitForVBlank(); }
		
	swiWaitForVBlank();
		
	if(REG_SCFG_MC == 0x11) { ErrorNoCard(); }

	swiWaitForVBlank();

}

void BootSplashInit(bool UseNTRSplash) {
	
	videoSetMode(MODE_0_2D | DISPLAY_BG0_ACTIVE);
	videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE);
	vramSetBankA (VRAM_A_MAIN_BG_0x06000000);
	vramSetBankC (VRAM_C_SUB_BG_0x06200000);
	REG_BG0CNT = BG_MAP_BASE(0) | BG_COLOR_256 | BG_TILE_BASE(2);
	REG_BG0CNT_SUB = BG_MAP_BASE(0) | BG_COLOR_256 | BG_TILE_BASE(2);
	BG_PALETTE[0]=0;
	BG_PALETTE[255]=0xffff;
	u16* bgMapTop = (u16*)SCREEN_BASE_BLOCK(0);
	u16* bgMapSub = (u16*)SCREEN_BASE_BLOCK_SUB(0);
	for (int i = 0; i < CONSOLE_SCREEN_WIDTH*CONSOLE_SCREEN_HEIGHT; i++) {
		bgMapTop[i] = (u16)i;
		bgMapSub[i] = (u16)i;
	}
	
	int pressed = keysDown();

	if ( pressed & KEY_A ) {
		BootSplashDSi();
	} else {
		if( UseNTRSplash ) {
			BootSplashDS();
		} else {
			BootSplashDSi();
		}
	}
}

