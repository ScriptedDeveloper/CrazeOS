/*
CrazeOS, an unix-based, work-in-progess amateurish OS.
Copyright (C) 2022  ScriptedDev

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "gdt.h"

// Written thanks to https://www.viralpatel.net/taj/tutorial/gdt.php

struct gdt_ptr gdt_pointer;
struct gdt_entry gdt[3];

void gdt_set_desc(int num, uint64_t base, uint64_t limit, uint8_t access, uint8_t granularity){
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity =	((limit >> 16) & 0x0F);
    gdt[num].granularity |= (granularity & 0xF0);
    gdt[num].access = access;
}

void gdt_init() {
    gdt_pointer.base = (uint32_t)&gdt;
    gdt_pointer.limit = (sizeof(struct gdt_entry) * 5) - 1;
    gdt_set_desc(0, 0, 0, 0, 0);
    gdt_set_desc(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_desc(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    gdt_set_desc(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
    gdt_set_desc(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
    
    gdt_flush();
    print("GDT successfully loaded!\n");
}
