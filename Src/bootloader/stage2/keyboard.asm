bits 16

section _TEXT class=CODE

global _getch
_getch:
    xor ah, ah
    int 16h
    ret

global _x86_clear
_x86_clear:
    pusha
    mov ah, 0x00
    mov al, 0x03  ; text mode 80x25 16 colours
    int 0x10
    popa
    ret
