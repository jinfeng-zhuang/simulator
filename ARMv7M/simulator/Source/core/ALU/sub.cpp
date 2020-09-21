#include <common.h>
#include "../pseudo.h"

static void SUB_IMM_T1(U16 inst)
{
	U8 imm3;
	U8 Rn;
	U8 Rd;
	U32 imm32;

	imm3 = BITGET(inst, 6, 8);
	Rn = BITGET(inst, 3, 5);
	Rd = BITGET(inst, 0, 2);

	imm32 = imm3;

	AddWithCarry(core.reg[Rn], ~imm32, 1);

	core.reg[Rd] = result;

	core.apsr.N = core.reg[Rd] & BIT(31) ? 1 : 0;
	core.apsr.Z = core.reg[Rd] ? 1 : 0;
	core.apsr.C = carry;
	core.apsr.V = overflow;
}

static void SUB_IMM_T2(U16 inst)
{
	U8 imm8;
	U8 Rdn;
	U32 imm32;

	imm8 = BITGET(inst, 0, 7);
	Rdn = BITGET(inst, 8, 9);

	imm32 = imm8;

	AddWithCarry(core.reg[Rdn], ~imm32, 1);

	core.reg[Rdn] = result;

	core.apsr.N = core.reg[Rdn] & BIT(31) ? 1 : 0;
	core.apsr.Z = core.reg[Rdn] ? 1 : 0;
	core.apsr.C = carry;
	core.apsr.V = overflow;
}

static void SUB_REG_T1(U16 inst)
{
	U8 Rm;
	U8 Rn;
	U8 Rd;

	Rm = BITGET(inst, 6, 8);
	Rn = BITGET(inst, 3, 5);
	Rd = BITGET(inst, 0, 2);

	AddWithCarry(core.reg[Rn], ~core.reg[Rm], 1);

	core.reg[Rd] = result;

	core.apsr.N = BITVAL(result, 31);
	core.apsr.Z = result ? 0 : 1;
	core.apsr.C = carry;
	core.apsr.V = overflow;
}

static void SUB_SP_IMM_T1(U16 inst)
{
	U8 imm7;
	U8 Rd;
	U32 imm32;

	imm7 = BITGET(inst, 0, 6);

	imm32 = imm7;

	AddWithCarry(core.reg[SP], ~imm32, 1);

	core.reg[Rd] = result;
}

void INSTRUCTION_SUB(U16 inst)
{

}