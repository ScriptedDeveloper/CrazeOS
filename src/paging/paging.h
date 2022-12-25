#pragma once
#define MAX_ENTRIES_PER_DIR 1024
#include <stdint.h>
#include <stdbool.h>
#include "../multiboot/multiboot.h"

typedef struct {
  uint32_t base_addr;
  uint32_t length;
  uint32_t type;
} memory_region_t;


typedef struct {
    uint32_t present : 1, // is it available?
             rw      : 1,    // true for writing, false for read-only
             other      : 10,    // true for writing, false for read-only
             frame_addr     : 20;    // true for writing, false for read-only
} page_entry;

typedef struct {
	page_entry *entries[MAX_ENTRIES_PER_DIR];

} page_table;

typedef struct {
	page_table* entries[MAX_ENTRIES_PER_DIR];

} page_directory;

void init_paging(page_directory *pd);
void *allocate_page(int pages);
void deallocate_page(void *base_addr);
void init_page_frame_allocator(multiboot_info_t *map);
void *malloc(size_t size);
void free(void *ptr);
