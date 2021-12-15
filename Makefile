# $^ is all the dependencies
# $@ is the target
# $< is the first dependency
# Format: target: dependency
#		  	instructions
# Adding build as a target to create the build directory
# Specifying it as a plain target will affect $^, so we use | to mark it

C_SOURCES = $(wildcard drivers/*.c cpu/*.c kernel/*.c)
HEADERS = $(wildcard drivers/*.h cpu/*.h kernel/*.h)
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o}
CC = i686-elf-gcc
GDB = i386-elf-gdb
LD = i686-elf-ld
QEMU = qemu-system-i386
CFLAGS = -g -fcommon

all: target/MyOS.bin | target

target:
	mkdir $@

run: all
	${QEMU} -fda target/MyOS.bin

target/MyOS.bin: boot/bootsect.bin kernel/kernel.bin | target
	cat $^ > $@

kernel/kernel.elf: kernel/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^

kernel/kernel.bin: kernel/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 --oformat binary $^

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -I './asm/' -o $@

debug: target/MyOS.bin kernel/kernel.elf
	${QEMU} -s -fda target/MyOS.bin & 
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel/kernel.elf"

clean:
	rm -rf target/
	rm -rf kernel/*.o kernel/*.elf kernel/*.bin drivers/*.o boot/*.o boot/*.bin cpu/*.o cpu/*.bin