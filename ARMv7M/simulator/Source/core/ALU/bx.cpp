#include <common.h>

void INSTRUCTION_BX(U16 instruction)
{
	U8 Rm;

	Rm = BITGET(instruction, 3, 6);

	core.reg[PC] = core.reg[Rm] & 0xFFFFFFFE;

	printf("r%d\n", Rm);
}