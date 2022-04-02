#pragma once
#include "kernel/kernel.h"

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute((packed));

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute((packed));

extern void gdt_flush();
extern struct gdt_ptr gdt_pointer;
void gdt_set_desc(int num, uint64_t base, uint64_t limit, uint8_t access, uint8_t granularity);
void gdt_init();
