#include <common.h>

static void INSTRUCTION_LSL_IMM(U16 instruction)
{
	U8 imm5;
	U8 Rm;
	U8 Rd;

	imm5 = BITGET(instruction, 6, 10);
	Rm = BITGET(instruction, 3, 5);
	Rd = BITGET(instruction, 0, 2);

	assert(0 != imm5);

	core.reg[Rd] = core.reg[Rm] << imm5;

	core.apsr.N = BIT(31) & core.reg[Rd] ? 1 : 0;
	core.apsr.Z = (0 == core.reg[Rd]) ? 1 : 0;
	core.apsr.C = (BIT(31) & (core.reg[Rm] << (imm5 - 1))) ? 1 : 0;

	printf("r%d, r%d, #%d\n", Rm, Rd, imm5);
}

static void INSTRUCTION_LSL_REG(U16 instruction)
{
	U8 Rm;
	U8 Rdn;
	U8 shift_n;

	Rm = BITGET(instruction, 3, 5);
	Rdn = BITGET(instruction, 0, 2);

	shift_n = BITGET(core.reg[Rm], 0, 7);

	assert(0 != shift_n);

	core.reg[Rdn] = core.reg[Rdn] << shift_n;

	core.apsr.N = BIT(31) & core.reg[Rdn] ? 1 : 0;
	core.apsr.Z = (0 == core.reg[Rdn]) ? 1 : 0;
	core.apsr.C = (BIT(31) & (core.reg[Rdn] << (shift_n - 1))) ? 1 : 0;

	printf("r%d, r%d\n", Rdn, Rm);
}

void INSTRUCTION_LSL(U16 instruction)
{
	if (0 == BITGET(instruction, 11, 15)) {
		INSTRUCTION_LSL_IMM(instruction);
	}
	else {
		INSTRUCTION_LSL_REG(instruction);
	}
}
