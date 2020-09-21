#include <common.h>

void INSTRUCTION_LDR(U16 instruction)
{
	U8 imm8;
	U8 Rt;
	U32 base;
	U32 addr;

	// Align PC to 4 bytes
	base = ALIGN4(core.reg[PC]);

	imm8 = BITGET(instruction, 0, 7);
	Rt = BITGET(instruction, 8, 10);

	addr = base + imm8 * 4;
	core.reg[Rt] = mmio_read(addr);

	printf("r%d,[pc,#%d]\t; @0x%08X\n", Rt, imm8 * 4, addr);
}