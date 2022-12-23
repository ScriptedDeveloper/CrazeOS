// written for CrazeOS
#include <stdint.h>
#include <stddef.h>
#include "paging.h"
#include "../multiboot/multiboot.h"
#include "../string/string.h"
#include "../video/video.h"
#define MAX_PAGES 50
#define PAGE_SIZE 4096
 
 
memory_region_t *available_regions[MAX_PAGES];
memory_region_t *taken_regions[MAX_PAGES];
int regions = 0;
 
void init_paging(multiboot_info_t *map) {
	int count_regions = 0;
	for(int i = 0; i < map->mmap_length; i += sizeof(multiboot_memory_map_t)) {
		multiboot_memory_map_t *mmmt = (multiboot_memory_map_t*) (map->mmap_addr + i);
		if(mmmt->type == MULTIBOOT_MEMORY_AVAILABLE) {
			if(i > 50) {
				break;
			}
			available_regions[i]->base_addr = mmmt->addr;
			available_regions[i]->length = mmmt->len;
			available_regions[i]->type = mmmt->type;
			count_regions++;
		}
	}
	regions = count_regions;
	printf("%s", "Successfully loaded paging!");
}
 
void* allocate_page(int pages) {
	if(regions == 0) {
		return NULL;
	}
	int selected_region = MAX_PAGES - 1;
	while(available_regions[selected_region]->length < pages * PAGE_SIZE || available_regions[selected_region] == NULL) {
		selected_region--;
		if(selected_region < 0) {
			return NULL;
		}
	}
	taken_regions[selected_region] = available_regions[selected_region];
	available_regions[selected_region] = NULL;
	taken_regions[selected_region]->base_addr += PAGE_SIZE * pages;
	taken_regions[selected_region]->length += PAGE_SIZE * pages;
	return (void*)taken_regions[selected_region]->base_addr;
}
 
void deallocate_page(void *base_addr) {
	for(int i = 0; i <= MAX_PAGES; i++) {
		if(taken_regions[i]->base_addr == (uint32_t)base_addr) {
			available_regions[i] = taken_regions[i];
			taken_regions[i] = NULL;
			regions--;
			break;
		}
	}

}
