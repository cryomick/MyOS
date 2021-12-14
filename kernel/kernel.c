#include "kernel.h"

void init_vga(void) {
    vga_buffer = (uint16_t*)VGA_ADDRESS;
    clear_vga_buffer(&vga_buffer);
}

void clear_vga_buffer(uint16_t **vga_buffer) {
    for(int i = 0; i < VGA_BUF_SIZE; i++) {
        (*vga_buffer)[i] = NULL;
    }
}

void kprintf(const char* _str) {
    while((*_str) != 0) {
        uint16_t val = (0x0f << 8) | (*_str);
        *vga_buffer++ = val;
        _str++;
    }
}

void main() {
    init_vga();
    kprintf("Hello from MyOS!!!");
    kprintf("Hello from MyOS!!!");
    kprintf("Hello from MyOS!!!");
}

