#pragma once
#ifndef GDT_H_LOADED
#define GDT_H_LOADED
#include <stdint.h>

typedef struct{
    uint16_t limit;
    uint64_t base;
}__attribute__((packed)) idtr_t;

typedef struct{
    uint16_t    isr_low;      // The lower 16 bits of the ISR's address
	uint16_t    kernel_cs;    // The GDT segment selector that the CPU will load into CS before calling the ISR
	uint8_t	    ist;          // The IST in the TSS that the CPU will load into RSP; set to zero for now
	uint8_t     attributes;   // Type and attributes; see the IDT page
	uint16_t    isr_mid;      // The higher 16 bits of the lower 32 bits of the ISR's address
	uint32_t    isr_high;     // The higher 32 bits of the ISR's address
	uint32_t    reserved;
}__attribute__((packed)) IDTDesc;

void interrupts_init_desc(int index, int addr);
void exception_handler(void);
void idt_set_desc(uint8_t vector, void* isr, uint8_t flags);
void idt_init(void);
#endif
