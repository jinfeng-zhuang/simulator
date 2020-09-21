#include <common.h>

void INSTRUCTION_STR(U16 instruction)
{
	U8 imm5;
	U8 imm8;
	U8 Rn;
	U8 Rt;
	U32 addr;

	// immediate
	if (BITGET(instruction, 11, 15) == 0x0C) {
		imm5 = BITGET(instruction, 6, 10);
		Rn = BITGET(instruction, 3, 5);
		Rt = BITGET(instruction, 0, 2);
		addr = core.reg[Rn] + imm5 * 4;
		mmio_write(addr, core.reg[Rt]);
		printf("r%d,[r%d,#%d]\t; @0x%08X\n", Rt, Rn, imm5 * 4, addr);
	}
	else if (BITGET(instruction, 11, 15) == 0x12) {
		Rt = BITGET(instruction, 8, 10);
		imm8 = BITGET(instruction, 0, 7);
		addr = core.reg[SP] + imm8 * 4;
		mmio_write(addr, core.reg[Rt]);
		printf("r%d,[SP,#%d]\t; @0x%08X\n", Rt, imm8 * 4, addr);
	}
	else if (BITGET(instruction, 9, 15) == 0x28) {
	}
	else {
		assert(0);
	}
}