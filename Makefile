cmod = aswrite.c
obj = boot.o gdt.o idt.o kb.o pic.o kernel.o io.o interrupt.o irq.o fb.o serial.o panic.o comm.o
cc = i686-x0r3d-elf
flags = -std=gnu99 -ffreestanding -O2 -Wall -Wextra -Idrivers
TDIR = ~/i686-x0r3d-elf/bin/
all:
	mkdir -p bin
	nasm -f elf kernel/arch/x86-asm/boot.nasm -o boot.o
	nasm -f elf kernel/arch/x86-asm/assembly_interface.nasm -o io.o
	nasm -f elf kernel/arch/x86-asm/interrupt.nasm -o interrupt.o
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/idt.c -o idt.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/gdt.c -o gdt.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/keyboard.c -o kb.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/pic.c -o pic.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/kernel.c -o kernel.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/irq.c -o irq.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/fb.c -o fb.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/serialport.c -o serial.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/panic.c -o panic.o $(flags)
	$(TDIR)$(cc)-gcc -c kernel/arch/x86-c/stdio.c -o comm.o $(flags)
	$(TDIR)$(cc)-gcc -T kernel/linker.ld -o tyler.bin $(obj) -lgcc -ffreestanding -O2 -nostdlib
	mkdir -p isodir/boot/grub
	cp tyler.bin isodir/boot/myos.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir
