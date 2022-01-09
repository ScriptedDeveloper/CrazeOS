#include "idt.h"
#define DIVIDE_BY_ZERO 0


__attribute__((noreturn))
void exception_handler(){
    __asm__ volatile("cli; hlt"); // Stops everything
}

void idt_set_desc(uint8_t vector, void* isr, uint8_t flags){
    IDTDesc* descriptor = &idt_desc[vector];
    descriptor->isr_low        = (uint32_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08;
    descriptor->attributes     = flags;
    descriptor->isr_high       = (uint32_t)isr >> 16;
    descriptor->reserved       = 0;
}
    
void idt_init(){
    idtr_t_struct.base = (uintptr_t)&idt_desc;
    idtr_t_struct.limit = (uint16_t)sizeof(IDTDesc) * INTERRUPTS_COUNT - 1;
    for(uint8_t vector = 0; vector < 32; vector++){
        idt_set_desc(vector, isr_stub_table[vector], 0x8E);
        vector[&vector] = true;
        __asm__ volatile ("lidt %0" : : "m"(idtr_t_struct)); // load the new IDT
        __asm__ volatile ("sti"); // set the interrupt flag
    }

}