#include "../cpu/types.h"

// Read a single byte from the specified port
u8 port_byte_in(u16 port) {
    u8 result;
    // GCC Assembly Syntax
    // operands ordering reversed
    // in %dx, %ax => read input from dx into ax (al in our case)
    // "=a" (result) => get the contents of al into result
    // "d" (port) => since no equals symbol, move port into edx

    // If we are writing data, and have an input, like port_byte_out
    // there is not output
    // <asm> : : <input 1>, <input 2>
    // The other case
    // <asm> : <=output> : <input>
    // Ref: ("assembly code" : output locations : input operands : changed registers)


    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

// Write a single byte to the specified port
void port_byte_out(u16 port, u8 data) {
    __asm__("out %%al, %%dx" : : "a" (data) , "d" (port));
}

u16 port_word_in(u16 port) {
    u16 result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

void port_word_out(u16 port, u16 data) {
    __asm__("out %%ax, %%dx" : : "a" (data) , "d" (port));
}