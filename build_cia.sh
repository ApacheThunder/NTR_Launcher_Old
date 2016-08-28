cp NTR_Launcher.nds NTR_Launcher-ds.nds

python patch_ndsheader_dsiware.py --mode ds --title "NitroHax" --maker EB --code ADLE NTR_Launcher-ds.nds

./make_cia.exe --srl=NTR_Launcher-ds.nds