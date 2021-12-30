bits	32
section	.text
	align	4
	dd	0x1BADB002
	dd	0x00
	dd	- (0x1BADB002+0x00)

global	start
extern	kmain
start:
	cli		; clears the interrupts
	call kmain
	%macro isr_err_stub 1
	isr_stub_%+%1:
    call exception_handler
    iret 
	%endmacro
	hlt