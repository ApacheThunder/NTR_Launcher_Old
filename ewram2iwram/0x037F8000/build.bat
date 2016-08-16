bin2s arm7.bin > arm7.S
arm-none-eabi-gcc -march=armv4t -mthumb -mthumb-interwork -s -c arm7.S
arm-none-eabi-gcc -march=armv4t -mthumb -mthumb-interwork -s -c armShit.S
arm-none-eabi-ld -o a.elf -S -T a.ld arm7.o armShit.o
arm-none-eabi-objdump -x a.elf
arm-none-eabi-objcopy a.elf -Obinary -S a.bin
del a.elf
del arm7.o
del armShit.o
del arm7.s
del arm7.bin
ren a.bin arm7.bin