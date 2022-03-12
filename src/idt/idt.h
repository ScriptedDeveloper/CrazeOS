#pragma once
#include "kernel/kernel.h"

struct idt_entry {
	uint16_t base_lo;
	uint16_t segment;
	uint8_t null;
	uint8_t flags;
	uint16_t base_hi;
} __attribute__((packed));

struct idt_ptr {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

void idt_set_desc(uint8_t num, uint64_t base, uint16_t segment, uint8_t flags);
void idt_init();

extern void idt_loader();
extern void* isr_stub_table[];
extern struct idt_entry idt_en[256];
extern struct idt_ptr idtp;
void exception_handler();