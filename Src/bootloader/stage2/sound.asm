bits 16

section _TEXT class=CODE

global _beep
_beep:
    ; Enable PC speaker
    mov al, 0b3h       ; Set the command to enable the speaker
    out 43h, al        ; Send command to port 43h
    in  al, 61h        ; Read the current value of port 61h
    or  al, 3          ; Set the 2 least significant bits
    out 61h, al        ; Write the new value to port 61h

    ; Set frequency
    mov al, 10111100b  ; Command to set counter 2, LSB/MSB, mode 3 (square wave generator)
    out 43h, al        ; Send command to port 43h
    mov ax, 182        ; Set initial frequency value (you can adjust this for different pitches)
    out 42h, al        ; Send LSB
    mov al, ah
    out 42h, al        ; Send MSB

    ; Wait for a while
    call delay

    ; Disable PC speaker
    in  al, 61h        ; Read the current value of port 61h
    and al, 0fch       ; Clear the 2 least significant bits
    out 61h, al        ; Write the new value to port 61h

    ; Exit program
    mov eax, 1         ; Exit syscall number
    xor ebx, ebx       ; Exit status 0
    int 0x80           ; Call kernel
    ret

delay:
    mov cx, 0xFFFF
.delay_loop:
    loop .delay_loop
    ret
