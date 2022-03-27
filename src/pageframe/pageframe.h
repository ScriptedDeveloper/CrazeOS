#pragma once
#include "kernel/kernel.h"
#define MMAP_GET_ADDR 1
#define MMAP_GET_NUM 1
#define PAGE_SIZE 4096

void page_frame_init(multiboot_info_t *mbd);
uint32_t mmap_read(int req, uint8_t mode);
uint32_t frame_allocate();
extern int mbd_start;
extern int mbd_end;
extern int free_frame;