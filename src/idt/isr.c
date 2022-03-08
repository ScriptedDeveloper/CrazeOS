#include "isr.h"

__attribute__((noreturn))
void throw_exception1() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : DIVIDED BY ZERO");
    __asm__ volatile ("cli; hlt");
}

void throw_exception2() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : DEBUG");
    __asm__ volatile ("cli; hlt");
}

void throw_exception3() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : NON-MASKABLE INTERRUPT");
    __asm__ volatile ("cli; hlt");
}

void throw_exception4() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : BREAKPOINT");
    __asm__ volatile ("cli; hlt");
}
void throw_exception5() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : OVERFLOW");
    __asm__ volatile ("cli; hlt");
}

void throw_exception6() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : BOUND RANGE EXCEEDED");
    __asm__ volatile ("cli; hlt");
}

void throw_exception7() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : INVALID OPCODE");
    __asm__ volatile ("cli; hlt");
}

void throw_exception8() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : DEVICE NOT AVAILABLE");
    __asm__ volatile ("cli; hlt");
}

void throw_exception9() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : DOUBLE FAULT");
    __asm__ volatile ("cli; hlt");
}

void throw_exception11() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : INVALID TSS");
    __asm__ volatile ("cli; hlt");
}

void throw_exception12() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : SEGMENT NOT PRESENT");
    __asm__ volatile ("cli; hlt");
}

void throw_exception13() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : STACK-SEGMENT FAULT");
    __asm__ volatile ("cli; hlt");
}

void throw_exception14() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : GENERAL PROTECTION FAULT");
    __asm__ volatile ("cli; hlt");
}

void throw_exception15() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : PAGE FAULT");
    __asm__ volatile ("cli; hlt");
}

void throw_exception17() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : X87 FLOATING-POINT EXCEPTION");
    __asm__ volatile ("cli; hlt");
}

void throw_exception18() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : ALIGNMENT CHECK");
    __asm__ volatile ("cli; hlt");
}

void throw_exception19() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : MACHINE CHECK");
    __asm__ volatile ("cli; hlt");
}

void throw_exception20() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : SIMD FLOATING-POINT-EXCEPTION");
    __asm__ volatile ("cli; hlt");
}

void throw_exception21() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : VIRTUALIZATION EXCEPTION");
    __asm__ volatile ("cli; hlt");
}

void throw_exception22() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : CONTROL PROTECTION EXCEPTION");
    __asm__ volatile ("cli; hlt");
}

void throw_exception24() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : HYPERVISOR INJECTION EXCEPTION");
    __asm__ volatile ("cli; hlt");
}

void throw_exception25() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : VMM COMMUNICATION EXCEPTION");
    __asm__ volatile ("cli; hlt");
}

void throw_exception26() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : TRIPLE FAULT");
    __asm__ volatile ("cli; hlt");
}

void throw_exception27() {
    terminal_clear_screen();
    print("KERNEL PANIC! ERROR MESSAGE : FPU ERROR INTERRUPT");
    __asm__ volatile ("cli; hlt");
}


void isr_init() { // Will change this someday to something better
    idt_set_desc(0, (uint32_t)throw_exception1, 0x08, 0x8E);
    idt_set_desc(1, (uint32_t)throw_exception2, 0x08, 0x8E);
    idt_set_desc(2, (uint32_t)throw_exception3, 0x08, 0x8E);
    idt_set_desc(3, (uint32_t)throw_exception4, 0x08, 0x8E);
    idt_set_desc(4, (uint32_t)throw_exception5, 0x08, 0x8E);
    idt_set_desc(5, (uint32_t)throw_exception6, 0x08, 0x8E);
    idt_set_desc(6, (uint32_t)throw_exception7, 0x08, 0x8E);
    idt_set_desc(7, (uint32_t)throw_exception8, 0x08, 0x8E);
    idt_set_desc(8, (uint32_t)throw_exception9, 0x08, 0x8E);
    idt_set_desc(10, (uint32_t)throw_exception11, 0x08, 0x8E);
    idt_set_desc(11, (uint32_t)throw_exception12, 0x08, 0x8E);
    idt_set_desc(12, (uint32_t)throw_exception13, 0x08, 0x8E);
    idt_set_desc(13, (uint32_t)throw_exception14, 0x08, 0x8E);
    idt_set_desc(14, (uint32_t)throw_exception15, 0x08, 0x8E);
    idt_set_desc(16, (uint32_t)throw_exception17, 0x08, 0x8E);
    idt_set_desc(17, (uint32_t)throw_exception18, 0x08, 0x8E);
    idt_set_desc(18, (uint32_t)throw_exception19, 0x08, 0x8E);
    idt_set_desc(19, (uint32_t)throw_exception20, 0x08, 0x8E);
    idt_set_desc(20, (uint32_t)throw_exception21, 0x08, 0x8E);
    idt_set_desc(21, (uint32_t)throw_exception22, 0x08, 0x8E);
    idt_set_desc(23, (uint32_t)throw_exception24, 0x08, 0x8E);
    idt_set_desc(24, (uint32_t)throw_exception25, 0x08, 0x8E);
    idt_set_desc(25, (uint32_t)throw_exception26, 0x08, 0x8E);
    idt_set_desc(26, (uint32_t)throw_exception27, 0x08, 0x8E);
}