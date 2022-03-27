override NASM 		:= nasm
override CC			:= gcc
override LD			:= i686-elf-ld

CFLAGS				:= -I ../src/
CFLAGS				+= -ffreestanding
CFLAGS				+= -m32
CFLAGS				+= -fno-stack-protector
CFLAGS				+= -fno-PIE 
CFLAGS				+= -g


LDFLAGS				+= -m32
LDFLAGS				+= -fno-PIE
LDFLAGS				+= -g
LDFLAGS				+= -nostartfiles
LDFLAGS				+= -nostdlib

S_SRC				:= $(shell find . -type f -name '*.asm')
C_SRC				:= $(shell find . -type f -name '*.c')
LIBGCC 				:= $(shell $(CC) $(CFLAGS) --print-libgcc-file-name)

OBJ					:= $(S_SRC:.asm=.o) $(C_SRC:.c=.o)

all: kernel.bin

kernel.bin: $(OBJ)
	$(CC) -T ../link.ld $(LDFLAGS) -o $@ $^ $(LIBGCC)

%.o: %.c
	$(CC) $(CFLAGS)  -c $^ -o $@

%.o: %.asm
	$(NASM) -felf32 $^ -o $@


run: kernel.bin
	qemu-system-x86_64 -s -S -m 16M -kernel $< 

.PHONY: run all clean
