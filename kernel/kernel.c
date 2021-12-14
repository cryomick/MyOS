#include "../drivers/screen.h"

void main() {
    clear_screen();
    kprint_at("X", 1, 6);
    kprint_at("This text spans multiple lines", 75, 10);
    char* message = "There is a line\nbreak";
    kprint_at(message, 0, 20);
    kprint("Regular print\nworking fine");
    kprint_at("What happens when we run out of space?", 45, 24);
}

