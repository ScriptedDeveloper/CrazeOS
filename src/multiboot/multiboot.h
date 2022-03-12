#ifndef MULTIBOOT_H
#define MULTIBOOT_H
// The following was copied from https://www.gnu.org/software/grub/manual/multiboot/html_node/multiboot.h.html

/* multiboot.h - the header for Multiboot */
/* Copyright (C) 1999, 2001  Free Software Foundation, Inc.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

/* Macros. */

/* The magic number for the Multiboot header. */
#define MULTIBOOT_HEADER_MAGIC          0x1BADB002

/* The flags for the Multiboot header. */
#ifdef __ELF__
# define MULTIBOOT_HEADER_FLAGS         0x00000003
#else
# define MULTIBOOT_HEADER_FLAGS         0x00010003
#endif

/* The magic number passed by a Multiboot-compliant boot loader. */
#define MULTIBOOT_BOOTLOADER_MAGIC      0x2BADB002

/* The size of our stack (16KB). */
#define STACK_SIZE                      0x4000

/* C symbol format. HAVE_ASM_USCORE is defined by configure. */
#ifdef HAVE_ASM_USCORE
# define EXT_C(sym)                     _ ## sym
#else
# define EXT_C(sym)                     sym
#endif

#ifndef ASM
/* Do not include here in boot.S. */

#include "kernel/kernel.h"

/* Types. */

/* The Multiboot header. */
typedef struct multiboot_header
{
 uint64_t magic;
 uint64_t flags;
 uint64_t checksum;
 uint64_t header_addr;
 uint64_t load_addr;
 uint64_t load_end_addr;
 uint64_t bss_end_addr;
 uint64_t entry_addr;
} multiboot_header_t;

/* The symbol table for a.out. */
typedef struct aout_symbol_table
{
 uint64_t tabsize;
 uint64_t strsize;
 uint64_t addr;
 uint64_t reserved;
} aout_symbol_table_t;

/* The section header table for ELF. */
typedef struct elf_section_header_table
{
 uint64_t num;
 uint64_t size;
 uint64_t addr;
 uint64_t shndx;
} elf_section_header_table_t;

/* The Multiboot information. */
typedef struct multiboot_info
{
 uint64_t flags;
 uint64_t mem_lower;
 uint64_t mem_upper;
 uint64_t boot_device;
 uint64_t cmdline;
 uint64_t mods_count;
 uint64_t mods_addr;
 union
 {
   aout_symbol_table_t aout_sym;
   elf_section_header_table_t elf_sec;
 } u;
 uint64_t mmap_length;
 uint64_t mmap_addr;
} multiboot_info_t;

/* The module structure. */
typedef struct module
{
 uint64_t mod_start;
 uint64_t mod_end;
 uint64_t string;
 uint64_t reserved;
} module_t;

/* The memory map. Be careful that the offset 0 is base_addr_low
  but no size. */
typedef struct memory_map
{
 uint64_t size;
 uint64_t base_addr_low;
 uint64_t base_addr_high;
 uint64_t length_low;
 uint64_t length_high;
 uint64_t type;
} memory_map_t;

#endif /* ! ASM */

#endif /* MULTIBOOT_H */