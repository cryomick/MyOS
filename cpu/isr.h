#ifndef DA83188E_8D20_4393_9A0A_0DE4F9C9E3C3
#define DA83188E_8D20_4393_9A0A_0DE4F9C9E3C3

#include "types.h"

static inline char* exception_messages[]  = {
    "Division By Zero",            // 0
    "Debug",                       // 1
    "Non Maskable Interrupt",      // 2
    "Breakpoint",                  // 3
    "Into Detected Overflow",      // 4
    "Out Of Bounds",               // 5
    "Invalid Opcode",              // 6
    "No Coprocesor",               // 7

    "Double Fault",                // 8
    "Coprocessor Segment Overrun", // 9
    "Bad TSS",                     // 10
    "Segment Not Present",         // 11
    "Stack Fault",                 // 12
    "General Protection fault",    // 13
    "Page Fault",                  // 14
    "Unknown Interrupt",           // 15

    "Coprocessor Fault",           // 16
    "Alignment Check",             // 17
    "Machine Check",               // 18
    "Reserved",                    // 19
    "Reserved",                    // 20
    "Reserved",                    // 21
    "Reserved",                    // 22
    "Reserved",                    // 23

    "Reserved",                    // 24
    "Reserved",                    // 25
    "Reserved",                    // 26
    "Reserved",                    // 27
    "Reserved",                    // 28
    "Reserved",                    // 29
    "Reserved",                    // 30
    "Reserved",                    // 31
};

// ISRs reserved for CPU exceptions
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

// Struct that aggregates many registers
typedef struct {
    u32 ds; // Data segment selector
    u32 edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha
    u32 int_no, err_code; // Interript number and error_code
    u32 eip, cs, eflags, useresp, ss; // Pushed by the processor automatically
} registers_t;

void isr_install();
void isr_handler(registers_t r);

#endif /* DA83188E_8D20_4393_9A0A_0DE4F9C9E3C3 */
