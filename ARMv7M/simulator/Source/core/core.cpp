#include <common.h>

struct core core;
struct core *ARMv7MCore = &core;

void core_start(void)
{
	U32 vector_base;
	U16 thumb16;
	U32 thumb32;
	
	vector_base  = 0; // TODO

	core.reg[SP] = mmio_read(vector_base + 4 * VECTOR_STACK);
	core.reg[PC] = mmio_read(vector_base + 4 * VECTOR_RESET);

	core.reg[PC] &= 0xFFFE; // THUMB

	while (1) {
		thumb16 = pipeline_fetch_thumb16();

		if (
			((thumb16 & 0xF800) == 0xE800) ||
			((thumb16 & 0xF800) == 0xF000) ||
			((thumb16 & 0xF800) == 0xF800)
			)
		{
			printf("THUMB32 NOT SUPPORTED\n");
			thumb32 = thumb16 << 16 | pipeline_fetch_thumb16();
		}
		else
		{
			pipeline_execute_thumb16(thumb16);
		}
	}
}