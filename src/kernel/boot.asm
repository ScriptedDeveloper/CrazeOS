bits 32

section .bss
resb 0x8000
stack_bottom:
resb 0x4000
stack_top:
section    .text
    align    4
    dd    0x1BADB002
    dd    0x00000002
    dd    - (0x1BADB002+0x00000002)

global    start
extern    kmain
start:
    mov esp, stack_top
    cli        ; clears the interrupts
    push eax
    push ebx
    call kmain
    hlt
