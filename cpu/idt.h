#ifndef B7696D03_DFF4_4B4B_B073_A671B013CC05
#define B7696D03_DFF4_4B4B_B073_A671B013CC05

#include "types.h"

#define KERNEL_CS 0x08

// Definition for Interrupt Gate (handler)
typedef struct {
    u16 low_offset; // Lower 16 bits of handler function address
    u16 sel; // Kernel segment selector
    u8 always0;
    /*
        Bit 7: "Interrupt is present"
        Bits 6 - 5: Privilege level of caller (0 = kernel ... 3 = user)
        Bit 4: Set to 0 for interrupt gates
        Bits 3 - 0: bits 1110 = decimal 14 = "32 bit interrupt gate"
    */
   u8 flags;
   u16 high_offset
} __attribute__((packed)) idt_gate_t;

// A pointer to the array of interrupt handlers.
// Assembly instructio lidt will read it
typedef struct {
    u16 limit;
    u32 base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
static inline idt_gate_t idt[IDT_ENTRIES];
static inline idt_register_t idt_reg;


void set_idt_gate(int n, u32 handler);
void set_idt();

#endif /* B7696D03_DFF4_4B4B_B073_A671B013CC05 */
