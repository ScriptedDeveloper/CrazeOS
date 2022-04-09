#include "isr.h"

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

__attribute__((noreturn))
void throw_exception1() {
    kpanic("DIVIDED BY ZERO");
}

void throw_exception2() {
    kpanic("DEBUG");
}

void throw_exception3() {
    kpanic("NON-MASKABLE INTERRUPT");
}

void throw_exception4() {
    kpanic("BREAKPOINT");
}
void throw_exception5() {
    kpanic("OVERFLOW");
}

void throw_exception6() {
    kpanic("BOUND RANGE EXCEEDED");
}

void throw_exception7() {
    kpanic("INVALID OPCODE");
}

void throw_exception8() {
    kpanic("DEVICE NOT AVAILABLE");
}

void throw_exception9() {
    kpanic("DOUBLE FAULT");
}

void throw_exception11() {
    kpanic("INVALID TSS");
}

void throw_exception12() {
    kpanic("SEGMENT NOT PRESENT");
}

void throw_exception13() {
    kpanic("STACK-SEGMENT FAULT");
}

void throw_exception14() {
    kpanic("GENERAL PROTECTION FAULT");
}

void throw_exception15() {
    kpanic("PAGE FAULT");
}

void throw_exception17() {
    kpanic("X87 FLOATING-POINT EXCEPTION");
}

void throw_exception18() {
    kpanic("ALIGNMENT CHECK");
}

void throw_exception19() {
    kpanic("MACHINE CHECK");
}

void throw_exception20() {
    kpanic("SIMD FLOATING-POINT-EXCEPTION");
}

void throw_exception21() {
    kpanic("VIRTUALIZATION EXCEPTION");
}

void throw_exception22() {
    kpanic("CONTROL PROTECTION EXCEPTION");
}

void throw_exception24() {
    kpanic("HYPERVISOR INJECTION EXCEPTION");
}

void throw_exception25() {
    kpanic("VMM COMMUNICATION EXCEPTION");
}

void throw_exception26() {
    kpanic("TRIPLE FAULT");
}

void throw_exception27() {
    terminal_clear_screen();
    kpanic("FPU ERROR INTERRUPT");
}


void isr_init() { // Will change this someday to something better
    idt_set_desc(0, (uint32_t)throw_exception1, 0x08, 0x8E);
    idt_set_desc(1, (uint32_t)throw_exception2, 0x08, 0x8E);
    idt_set_desc(2, (uint32_t)throw_exception3, 0x08, 0x8E);
    idt_set_desc(3, (uint32_t)throw_exception4, 0x08, 0x8E);
    idt_set_desc(4, (uint32_t)throw_exception5, 0x08, 0x8E);
    idt_set_desc(5, (uint32_t)throw_exception6, 0x08, 0x8E);
    idt_set_desc(6, (uint32_t)throw_exception7, 0x08, 0x8E);
    idt_set_desc(7, (uint32_t)throw_exception8, 0x08, 0x8E);
    idt_set_desc(8, (uint32_t)throw_exception9, 0x08, 0x8E);
    idt_set_desc(10, (uint32_t)throw_exception11, 0x08, 0x8E);
    idt_set_desc(11, (uint32_t)throw_exception12, 0x08, 0x8E);
    idt_set_desc(12, (uint32_t)throw_exception13, 0x08, 0x8E);
    idt_set_desc(13, (uint32_t)throw_exception14, 0x08, 0x8E);
    idt_set_desc(14, (uint32_t)throw_exception15, 0x08, 0x8E);
    idt_set_desc(16, (uint32_t)throw_exception17, 0x08, 0x8E);
    idt_set_desc(17, (uint32_t)throw_exception18, 0x08, 0x8E);
    idt_set_desc(18, (uint32_t)throw_exception19, 0x08, 0x8E);
    idt_set_desc(19, (uint32_t)throw_exception20, 0x08, 0x8E);
    idt_set_desc(20, (uint32_t)throw_exception21, 0x08, 0x8E);
    idt_set_desc(21, (uint32_t)throw_exception22, 0x08, 0x8E);
    idt_set_desc(23, (uint32_t)throw_exception24, 0x08, 0x8E);
    idt_set_desc(24, (uint32_t)throw_exception25, 0x08, 0x8E);
    idt_set_desc(25, (uint32_t)throw_exception26, 0x08, 0x8E);
    idt_set_desc(26, (uint32_t)throw_exception27, 0x08, 0x8E);
}
