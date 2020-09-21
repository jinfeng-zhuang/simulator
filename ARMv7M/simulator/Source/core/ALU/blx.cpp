#include <common.h>

void INSTRUCTION_BLX(U16 instruction)
{
	U8 Rm;

	Rm = BITGET(instruction, 3, 6);

	if (PC == Rm) {
		assert(0);
	}

	core.reg[LR] = core.reg[PC] + 1; // THUMB

									 // TODO: check the destination's validation

	core.reg[PC] = core.reg[Rm] & 0xFFFFFFFE;

	printf("r%d\n", Rm);
}