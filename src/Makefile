override NASM 		:= nasm
override CC			:= gcc
override LD			:= i686-elf-ld

CFLAGS				:= -I ../src/
CFLAGS				+= -ffreestanding
CFLAGS				+= -m32
CFLAGS				+= -fno-stack-protector


LDFLAGS				+= -m elf_i386

S_SRC				:= $(shell find . -type f -name '*.asm')
C_SRC				:= $(shell find . -type f -name '*.c')

OBJ					:= $(S_SRC:.asm=.o) $(C_SRC:.c=.o)

all: kernel.bin

kernel.bin: $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $^ -T ../link.ld

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -T ../link.ld

%.o: %.asm
	$(NASM) -felf32 $^ -o $@


run: kernel.bin
	qemu-system-x86_64 -kernel $<

.PHONY: run all clean