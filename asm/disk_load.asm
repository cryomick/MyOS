; load dh sectors from drive dl
disk_load:
    pusha

    ; inputs for this functions are in dx, but we need that to do the actual
    ; disk read. So we save it in stack for now
    push dx
    mov ah, 0x02

    ; BIOS sets dl to our boot disk by default
    mov al, dh ; number of bytes to read
    mov cl, 0x02; cl -> sector ( 1 indexed, 1 is boot sector, 2 is next available)
    mov ch, 0x00; ch -> cylinder head
    ; dl -> drive number 0 = floppy, 1 = floppy2, 0x80 = hdd, 0x81 hdd2
    mov dh, 0x00; dh -> head number (0x0 - 0xF)
    
    int 0x13 ; read to es:bx
    jc disk_error

    pop dx
    cmp al, dh
    jne sectors_error
    popa
    ret

disk_error:
    mov bx, DISK_ERROR
    call print
    call print_nl
    mov dh, ah
    call print_hex
    call print_nl
    jmp disk_loop

sectors_error:
    mov bx, SECTORS_ERROR
    call print
    call print_nl

disk_loop:
    jmp $

DISK_ERROR: db "Disk read error", 0
SECTORS_ERROR: db "Incorrect number of sectors read", 0

