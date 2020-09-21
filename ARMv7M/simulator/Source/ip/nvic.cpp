#include <common.h>
#include "nvic.h"

static U32 io(U8 read, U32 addr, U32 value)
{
	return 0;
}

void ip_nvic_attach(void)
{
	struct memory_region region;

	region.addr = 0x00000000;
	region.size = NVIC_ADDR_SIZE;
	region.io = io;

	memory_region_register(&region);
}