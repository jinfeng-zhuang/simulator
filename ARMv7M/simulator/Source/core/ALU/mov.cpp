#include <common.h>
#include "../pseudo.h"

void INSTRUCTION_MOV_IMM_T1(U16 inst)
{
	U8 imm8;
	U8 Rd;
	U32 imm32;

	imm8 = BITGET(inst, 0, 7);
	Rd = BITGET(inst, 8, 10);

	imm32 = imm8;

	core.reg[Rd] = imm32;

	core.apsr.N = BITVAL(imm32, 31);
	core.apsr.Z = imm32 ? 0 : 1;
	core.apsr.C = core.apsr.C;
}

void INSTRUCTION_MOV_REG_T1(U16 inst)
{
	U8 Rm;
	U8 Rd;
	U8 D;

	D = BITGET(inst, 7, 7);
	Rm = BITGET(inst, 3, 6);
	Rd = BITGET(inst, 0, 2);

	Rd |= D ? BIT(3) : 0;

	result = core.reg[Rm];

	if (Rd == PC) {
		ALUWritePC(result);
	}
	else {
		core.reg[Rd] = result;
	}
}

void INSTRUCTION_MOV_REG_T2(U16 inst)
{
	U8 Rm;
	U8 Rd;

	Rm = BITGET(inst, 3, 5);
	Rd = BITGET(inst, 0, 2);

	result = core.reg[Rm];

	if (Rd == PC) {
		ALUWritePC(result);
	}
	else {
		core.reg[Rd] = result;
	}
}

void INSTRUCTION_MOV(U16 inst)
{

}