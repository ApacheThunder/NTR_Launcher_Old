.extern arm7_bin_size
.extern arm7_bin

	.section .text
	.balign 4
	.global _start

_start:
	ldr	r1, =arm7_bin
	ldr	r0, =jump_pos
	ldmia r0!, {r2}
	ldr r0, =arm7_bin_size
	ldmia r0!, {r3}
copyloop:
	ldmia	r1!, {r0}
	stmia	r2!, {r0}
	subs	r3, r3, #4
	bne	copyloop
	ldr	r0, =jump_pos
	ldmia	r0!, {r1}
	mov pc, r1

	.section .rodata
	.balign 4

jump_pos:
	.int 0x037F8000
