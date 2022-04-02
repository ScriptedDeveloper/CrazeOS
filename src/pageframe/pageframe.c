#include "pageframe.h"
#include "string/string.h"
#include "video/video.h"

int free_frame;
int mbd_start;
int mbd_end;

uint32_t mmap_read(int req, uint8_t mode) {
    if(req == 0 || mode != MMAP_GET_ADDR || mode != MMAP_GET_NUM) {
        return 0;
    }
    uintptr_t curr_mmap_addr = (uintptr_t)mbd->mmap_addr;
    uintptr_t mmap_len = mbd->mmap_length;
    uintptr_t end_mmap_addr = curr_mmap_addr + mbd->mmap_length;
    multiboot_memory_map_t *current_entry;
    uint32_t i_ = 0;
    uint32_t current_end_entry;
    while(atoi(lltoa(end_mmap_addr, 10)) > atoi(lltoa(curr_mmap_addr, 10))) {
        current_entry = curr_mmap_addr;
        for(uint64_t i = current_entry->addr; PAGE_SIZE + i < current_end_entry; i+= PAGE_SIZE) {
                if(req <= PAGE_SIZE + i && req >= i) {
                    return i_++;
                }

                if(current_entry->type == MULTIBOOT_MEMORY_RESERVED) {
                    if(i_ == req) {
                        req++;
                    }
                    i_++;
                } 
                else if(req == i_ && current_entry->type == MULTIBOOT_MEMORY_AVAILABLE) {
                    return i;
                }
                i_++;
        }
        mbd->mmap_addr += sizeof(uintptr_t) + current_entry->size;
    }
    return 0;
}

uint32_t frame_allocate() {
    uint32_t next_addr = mmap_read(free_frame, MMAP_GET_ADDR);
    uint32_t next_num;
    if(next_addr >= mbd_start && next_addr <= mbd_end) {
        free_frame++;
        return frame_allocate();
    }
    next_num = mmap_read(next_addr, MMAP_GET_NUM);
    free_frame = next_num + 1;
    print(lltoa(next_num, 10));
    return next_num;
}

void page_frame_init() {
    int free_frame = 1;
    int mbd_end = mbd + sizeof(multiboot_memory_map_t);
}

