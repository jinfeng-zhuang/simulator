#include <common.h>
#include "config.h"

static struct memory_region memory_region_array[MEMORY_REGION_NUMBER];

static U32 memory_region_index;

void memory_region_register(struct memory_region *region)
{
	assert(NULL != region);
	assert(memory_region_index < MEMORY_REGION_NUMBER);

	memory_region_array[memory_region_index].addr = region->addr;
	memory_region_array[memory_region_index].size = region->size;
	memory_region_array[memory_region_index].io = region->io;

	memory_region_index++;
}

U32 mmio_read(U32 addr)
{
	int i;
	U32 offset;
	struct memory_region *mem;

	for (i = 0; i < MEMORY_REGION_NUMBER; i++) {
		mem = &memory_region_array[i];
		if ((addr >= mem->addr) && (addr < (mem->addr + mem->size))) {
			offset = addr - mem->addr;
			return mem->io(TRUE, offset, 0); // END
		}
	}

	assert(0);

	return 0;
}

void mmio_write(U32 addr, U32 data)
{
	int i;
	U32 offset;
	struct memory_region *mem;

	for (i = 0; i < MEMORY_REGION_NUMBER; i++) {
		mem = &memory_region_array[i];
		if ((addr >= mem->addr) && (addr < (mem->addr + mem->size))) {
			offset = addr - mem->addr;
			mem->io(FALSE, offset, 0);
			return; // END
		}
	}

	assert(0);
}