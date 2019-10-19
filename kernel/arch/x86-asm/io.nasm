global outb
global inb
global halt
global lgdt

outb:
    mov al, [esp + 8]
    mov dx, [esp + 4]
    out dx, al
    ret
inb:
    mov dx, [esp + 4]
    in al, dx 
    ret

lgdt:
  mov edx, [esp + 4]
  lgdt [edx]
  ret

halt:
  cli
  hlt
  jmp $
global  load_idt

load_idt:
  mov eax, [esp+4]
  lidt[eax]
  ret

global interrupt
interrupt:
  mov eax, [esp+4]
  int 49