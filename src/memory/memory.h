#pragma once
#include "kernel/kernel.h"

typedef struct {
    uint32_t size;
    uint32_t base_addr_low, base_addr_high;
    uint32_t len_low, len_high;
    uint32_t type;
} mmap_entry_t;