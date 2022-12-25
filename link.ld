OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

MEMORY 
{
	heap : ORIGIN = 0x200000, LENGTH = 0x100000 
	text : ORIGIN = 0x300000, LENGTH = 0x100000
	data : ORIGIN = 0x400000, LENGTH = 0x100000
	bss : ORIGIN = 0x500000, LENGTH = 0x100000
}

SECTIONS
{
	. = 0x100000;
	kernel_start = .;
	.text : { *(.text) } > text
	.data : { *(.data) } > data
	.bss : { *(.bss) } > bss
	kernel_end = .;
}

