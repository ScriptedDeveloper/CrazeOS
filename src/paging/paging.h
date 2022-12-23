#pragma once
#include <stdint.h>
#include "../multiboot/multiboot.h"

typedef struct {
  uint32_t base_addr;
  uint32_t length;
  uint32_t type;
} memory_region_t;

void init_paging(multiboot_info_t *map);
void *allocate_page();
void deallocate_page(void *base_addr);
