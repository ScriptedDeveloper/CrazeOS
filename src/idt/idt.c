#include "idt.h"
#define INTERRUPTS_COUNT 256
#define DIVIDE_BY_ZERO 0

static idtr_t idtr_t_struct;
static IDTDesc idt_desc[INTERRUPTS_COUNT];

__attribute__((noreturn))
void exception_handler(){
    __asm__ volatile("cli; hlt"); // Stops everything
}

void idt_set_desc(uint8_t vector, void* isr, uint8_t flags){
    IDTDesc* descriptor = &idt_desc[vector];
    descriptor->isr_low        = (uint32_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08; // this value can be whatever offset your kernel code selector is in your GDT
    descriptor->attributes     = flags;
    descriptor->isr_high       = (uint32_t)isr >> 16;
    descriptor->reserved       = 0;
}
    