// written for CrazeOS
#include <stdint.h>
#include <stddef.h>
#include "paging.h"
#include "../multiboot/multiboot.h"
#include "../string/string.h"
#include "../video/video.h"
#include "../kernel/kernel.h"
#define PAGE_SIZE 4096
#define MAX_PAGES 50
 
memory_region_t *available_regions[MAX_PAGES];
memory_region_t *taken_regions[MAX_PAGES];
int regions = 0;
 
void init_paging(multiboot_info_t *map) {
	int count_regions = 0;
	size_t kernel_length = kernel_end - kernel_start;
	for(int i = 0; i < map->mmap_length; i += sizeof(multiboot_memory_map_t)) {
		multiboot_memory_map_t *mmmt = (multiboot_memory_map_t*) (map->mmap_addr + i);
		if(mmmt->type == MULTIBOOT_MEMORY_AVAILABLE) {
			if(mmmt->addr + mmmt->len <= kernel_start || mmmt->addr >= kernel_end) {
				if(count_regions > 50) {
					break;
				}
				available_regions[count_regions] = (memory_region_t*)mmmt;
				count_regions++;
				print(itoa(available_regions[count_regions]->base_addr, 16));
				print("\n");
			}
		}
		print(itoa(mmmt->addr, 16));
	}
	regions = count_regions;
	print("\n");
	printf("%s", "Successfully loaded paging!");

}
 
void* allocate_page(int pages) {
	if(regions == 0 || pages < MAX_PAGES) {
		return NULL;
	}
	int selected_region = 0;
	while(available_regions[selected_region] == NULL) {
		if(selected_region > MAX_PAGES) {
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
		if(taken_regions[i]->base_addr == (uint32_t)base_addr && taken_regions[i] != NULL) {
			available_regions[i] = taken_regions[i];
			taken_regions[i] = NULL;
			base_addr = (void*)NULL;
			regions++;	
			break;
		}
	}
}

