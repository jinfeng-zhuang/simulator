PREFIX = riscv64-unknown-elf

CC = $(PREFIX)-gcc
LD = $(PREFIX)-ld
OBJCOPY = $(PREFIX)-objcopy
OBJDUMP = $(PREFIX)-objdump

CFLAGS = -c
LDFLAGS = -T layout.lds

all:
	$(CC) $(CFLAGS) -o start.o start.S
	$(LD) $(LDFLAGS) -o start.elf start.o
	$(OBJDUMP) -S start.elf > start.dump
	$(OBJCOPY) -O binary start.elf start.bin

clean:
	rm *.o *.dump *.bin *.elf
