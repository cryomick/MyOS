// Read a single byte from the specified port
unsigned char port_byte_in(unsigned short port) {
    unsigned char result;
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
void port_byte_out(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data) , "d" (port));
}

unsigned short port_word_in(unsigned short port) {
    unsigned short result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

void port_word_out(unsigned short port, unsigned short data) {
    __asm__("out %%ax, %%dx" : : "a" (data) , "d" (port));
}