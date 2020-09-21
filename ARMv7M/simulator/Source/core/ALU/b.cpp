#include <common.h>

static void B_T1(U16 inst)
{
	U8 cond;
	U8 imm8;
	U32 imm32;

	cond = BITGET(inst, 8, 11);
	imm8 = BITGET(inst, 0, 7);

	imm32 = (imm8 & 0x7F) | (imm8 & 0x80 ? BIT(31) : 0);

	core.reg[PC] = core.reg[PC] + imm32;
}

static void B_T2(U16 inst)
{
	U8 imm11;
	U32 imm32;

	imm11 = BITGET(inst, 0, 10);

	imm32 = BITGET(imm11, 0, 9) | (BITGET(imm11, 10, 10) ? BIT(31) : 0);

	core.reg[PC] = core.reg[PC] + imm32;
}

void INSTRUCTION_B(U16 inst)
{
	if (0xD == BITGET(inst, 12, 15)) {
		B_T1(inst);
	}
	else if (0xE == BITGET(inst, 11, 15)) {
		B_T2(inst);
	}
	else {
		assert(0);
	}
}