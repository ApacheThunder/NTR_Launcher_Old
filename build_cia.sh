cp NTR_Launcher.nds NTR_Launcher_Release.nds

python patch_ndsheader_dsiware.py --mode ds --title "NTR LAUNCHER" --maker 01 --code AKGJ NTR_Launcher_Release.nds

./make_cia.exe --srl=NTR_Launcher_Release.nds