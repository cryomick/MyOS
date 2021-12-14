#ifndef KERNEL_H_
#define KERNEL_H

typedef unsigned char uint8_t;
typedef char int8_t;
typedef unsigned int uint_t;
typedef unsigned short uint16_t;
typedef short int16_t;

#define VGA_ADDRESS 0xB8000
#define VGA_BUF_SIZE 2200

uint16_t *vga_buffer;

#define NULL 0

void init_vga(void);
void clear_vga_buffer(uint16_t **vga_buffer);
void kprintf(const char* _str);
//void kprintf(const char& _str, const uint8_t _color);

enum vga_color {
    BLACK = 0,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

#endif