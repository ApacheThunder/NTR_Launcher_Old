OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

SECTIONS {
	.main 0x02380000 :
	{
		*(.text)
		*(.rodata .rodata.*)
	}
	/DISCARD/ :
	{
		*(.ARM.attributes)
	}
}
