cmod = aswrite.c
obj = boot.o kernel.o
cc = i686-x0r3d-elf
flags = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Idrivers
TDIR = ~/i686-x0r3d-elf/bin/
all: kernel mod link

kernel:
	mkdir -p bin
	nasm -f elf kernel/arch/x86-asm/boot.nasm -o boot.o
	$(TDIR)$(cc)-gcc -c kernel/kernel.c -o kernel.o $(flags)

link:
	$(TDIR)$(cc)-gcc -T kernel/linker.ld -o tyler.bin $(obj) -lgcc -ffreestanding -O2 -nostdlib
mod: cmod asmod
asmod:
	echo asmod
cmod:
	echo cmod