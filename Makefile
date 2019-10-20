cmod = aswrite.c
obj = boot.o kernel.o io.o interrupt.o irq.o
cc = i686-x0r3d-elf
flags = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Idrivers
TDIR = ~/i686-x0r3d-elf/bin/
all:
	mkdir -p bin
	nasm -f elf kernel/arch/x86-asm/boot.nasm -o boot.o
	nasm -f elf kernel/arch/x86-asm/io.nasm -o io.o
	nasm -f elf kernel/arch/x86-asm/interrupt.nasm -o interrupt.o
	$(TDIR)$(cc)-gcc -c kernel/kernel.c -o kernel.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/x86-c/irq.c -o irq.o $(flags)
	$(TDIR)$(cc)-gcc -T kernel/linker.ld -o tyler.bin $(obj) -lgcc -ffreestanding -O2 -nostdlib

