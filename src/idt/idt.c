#include "idt.h"

__attribute__((alligned(0x10)))
struct idt_entry idt_en[256];
struct idt_ptr idtp;
void idt_set_desc(uint8_t num, uint64_t base, uint16_t segment, uint8_t flags){
    idt_en[num].base_hi = (base >> 16) & 0xFFFF;
    idt_en[num].base_lo = base & 0xFFFF;
    idt_en[num].null = 0;
    idt_en[num].segment = segment;
    idt_en[num].flags = flags;
}


void idt_init() {
    idtp.base = &idt_en;
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    memset(&idt_en, 0, sizeof(struct idt_entry) * 256);
    idt_loader();
    isr_init();
    print("IDT successfully loaded!\n");
}