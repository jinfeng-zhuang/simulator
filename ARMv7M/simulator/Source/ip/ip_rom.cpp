#include <common.h>

static U8 rom[SIZE_1MB];

void load_rom(const char *romfile)
{
	FILE *fp;
	errno_t err;
	int ret;
	long file_size;
	size_t byte_read;

	err = fopen_s(&fp, romfile, "rb");
	assert(NULL != fp);

	ret = fseek(fp, 0, SEEK_END);
	assert(0 == ret);

	file_size = ftell(fp);
	assert(file_size >= 0);

	ret = fseek(fp, 0, SEEK_SET);
	assert(0 == ret);

	byte_read = fread(rom, 1, file_size, fp);
	assert(byte_read == file_size);

	ret = fclose(fp);
	assert(0 == ret);
}

// TODO: byte mask
U32 rom_io(U8 read, U32 addr, U32 value)
{
	if (read) {
		return *(U32 *)&rom[addr];
	}
	else {
		*(U32 *)&rom[addr] = value;
		return 0;
	}
}

void ip_rom_attach(void)
{
	struct memory_region region;

	region.addr = 0x00000000;
	region.size = sizeof(rom);
	region.io = rom_io;

	memory_region_register(&region);
}