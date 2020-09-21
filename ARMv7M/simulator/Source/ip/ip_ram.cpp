#include <common.h>

static U8 ram[SIZE_1MB];

// TODO: byte mask
U32 ram_io(U8 read, U32 addr, U32 value)
{
	if (read) {
		return *(U32 *)&ram[addr];
	}
	else {
		*(U32 *)&ram[addr] = value;
		return 0;
	}
}

void ip_ram_attach(void)
{
	struct memory_region region;

	region.addr = 0x20000000;
	region.size = sizeof(ram);
	region.io = ram_io;

	memory_region_register(&region);
}