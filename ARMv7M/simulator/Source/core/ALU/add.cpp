#include <common.h>
#include "../pseudo.h"

static void ADD_IMM_T1(U16 inst)
{
	U8 imm3;
	U8 Rn;
	U8 Rd;
	U32 imm32;

	imm3 = BITGET(inst, 6, 8);
	Rn = BITGET(inst, 3, 5);
	Rd = BITGET(inst, 0, 2);

	imm32 = imm3;

	AddWithCarry(core.reg[Rn], imm32, 0);

	core.reg[Rd] = result;

	core.apsr.N = core.reg[Rd] & BIT(31) ? 1 : 0;
	core.apsr.Z = core.reg[Rd] ? 1 : 0;
	core.apsr.C = carry;
	core.apsr.V = overflow;
}

static void ADD_IMM_T2(U16 inst)
{
	U8 imm8;
	U8 Rdn;
	U32 imm32;

	imm8 = BITGET(inst, 0, 7);
	Rdn = BITGET(inst, 8, 9);

	imm32 = imm8;

	AddWithCarry(core.reg[Rdn], imm32, 0);

	core.reg[Rdn] = result;

	core.apsr.N = core.reg[Rdn] & BIT(31) ? 1 : 0;
	core.apsr.Z = core.reg[Rdn] ? 1 : 0;
	core.apsr.C = carry;
	core.apsr.V = overflow;
}

static void ADD_REG_T1(U16 inst)
{
	U8 Rm;
	U8 Rn;
	U8 Rd;

	Rm = BITGET(inst, 6, 8);
	Rn = BITGET(inst, 3, 5);
	Rd = BITGET(inst, 0, 2);

	AddWithCarry(core.reg[Rn], core.reg[Rm], 0);

	if (Rd == PC) {
		ALUWritePC(result);
	}
	else {
		core.reg[Rd] = result;
		core.apsr.N = BITVAL(result, 31);
		core.apsr.Z = result ? 0 : 1;
		core.apsr.C = carry;
		core.apsr.V = overflow;
	}
}

static void ADD_REG_T2(U16 inst)
{
	U8 Rm;
	U8 Rdn;
	U8 DN;

	Rm = BITGET(inst, 3, 6);
	Rdn = BITGET(inst, 0, 2);
	DN = BITGET(inst, 7, 7);

	Rdn |= DN ? BIT(3) : 0;

	// TODO: ADD_SP_REG
	assert(Rm != 0xD);
	assert(!(Rdn == 0xD));

	AddWithCarry(core.reg[Rdn], core.reg[Rm], 0);

	if (Rdn == PC) {
		ALUWritePC(result);
	}
	else {
		core.reg[Rdn] = result;
	}
}

static void ADD_SP_IMM_T1(U16 inst)
{
	U8 imm8;
	U8 Rd;
	U32 imm32;

	imm8 = BITGET(inst, 0, 7);
	Rd = BITGET(inst, 8, 10);

	imm32 = imm8;

	AddWithCarry(core.reg[SP], imm32, 0);

	core.reg[Rd] = result;
}

static void ADD_SP_IMM_T2(U16 inst)
{
	U8 imm7;
	U8 Rd;
	U32 imm32;

	imm7 = BITGET(inst, 0, 6);
	Rd = BITGET(inst, 8, 10);

	imm32 = imm7;

	AddWithCarry(core.reg[SP], imm32, 0);

	core.reg[Rd] = result;
}

static void ADD_SP_REG_T1(U16 inst)
{
	U8 Rdm;
	U8 DM;

	Rdm = BITGET(inst, 0, 2);
	DM = BITGET(inst, 7, 7);

	Rdm |= DM ? BIT(3) : 0;

	AddWithCarry(core.reg[SP], core.reg[Rdm], 0);
	
	if (Rdm == PC) {
		ALUWritePC(result);
	}
	else {
		core.reg[Rdm] = result;
	}
}

static void ADD_SP_REG_T2(U16 inst)
{
	U8 Rm;

	Rm = BITGET(inst, 3, 6);

	AddWithCarry(core.reg[SP], core.reg[Rm], 0);

	if (Rm == PC) {
		ALUWritePC(result);
	}
	else {
		core.reg[Rm] = result;
	}
}

void INSTRUCTION_ADD(U16 inst)
{

}