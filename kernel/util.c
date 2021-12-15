#include "../cpu/types.h"

void memory_copy(u8* source, u8* dest, int nbytes) {
    for(int i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8* dest, u8 val, u32 len) {
    for(int i = 0; i < len; i++) {
        dest[i] = val;
    }
}

void int_to_ascii(int n, char str[]) {
    int i , sign;
    if((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while((n/=10) > 0);
    if(sign < 0) {
        str[i++] = '-';
    }
    str[i] = '\0';
}