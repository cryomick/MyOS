#include "../drivers/screen.h"
#include "util.h"
#include "../cpu/idt.h"
#include "../cpu/isr.h"

void main() {
    clear_screen();
    isr_install();
    __asm__ __volatile__("int $5");
    __asm__ __volatile__("int $6");
}

