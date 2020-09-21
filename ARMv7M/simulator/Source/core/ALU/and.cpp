#include <common.h>
#include "../pseudo.h"

void THUMB16_AND_REG(U16 inst)
{
	U8 Rdn;
	U8 Rm;

	Rdn = BITGET(inst, 0, 2);
	Rm = BITGET(inst, 3, 5);

	result = core.reg[Rdn] & core.reg[Rm];

	core.reg[Rdn] = result;

	core.apsr.N = BITVAL(result, 31);
	core.apsr.Z = result ? 0 : 1;
}

void INSTRUCTION_AND(U16 inst)
{
	
}