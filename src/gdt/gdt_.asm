global gdt_flush
extern gdt_pointer
gdt_flush:
    mov ax, 0x10
    lgdt [gdt_pointer]
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush

flush: 
    ret
