cp NTR_Launcher.nds NTR_Launcher-ds.nds

python patch_ndsheader_dsiware.py --mode ds --title "NTR Launcher" --maker 01 --code YZYE NTR_Launcher-ds.nds

./make_cia.exe --srl=NTR_Launcher-ds.nds