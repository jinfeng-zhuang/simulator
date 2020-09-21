#ifndef MEMORY_H
#define MEMORY_H

#include <types.h>

struct memory_region {
	U32 addr;
	U32 size;
	U32 (*io)(U8 read, U32 addr, U32 value);
};

extern void memory_region_register(struct memory_region *region);
extern U32 mmio_read(U32 addr);
extern void mmio_write(U32 addr, U32 data);

#endif