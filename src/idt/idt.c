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

#include "idt.h"

__attribute__((alligned(0x10)))
struct idt_entry idt_en[256];
struct idt_ptr idtp;
void idt_set_desc(uint8_t num, uint64_t base, uint16_t segment, uint8_t flags){
    idt_en[num].base_hi = (base >> 16) & 0xFFFF;
    idt_en[num].base_lo = base & 0xFFFF;
    idt_en[num].null = 0;
    idt_en[num].segment = segment;
    idt_en[num].flags = flags;
}


void idt_init() {
    idtp.base = &idt_en;
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    memset(&idt_en, 0, sizeof(struct idt_entry) * 256);
    idt_loader();
    isr_init();
    print("IDT successfully loaded!\n");
}
