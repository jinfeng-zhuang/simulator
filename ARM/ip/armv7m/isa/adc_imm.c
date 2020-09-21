#include "../core.h"

static void adc_imm(unsigned int inst)
{
	ISA_LOCAL_VARS;

	i = BITGET(inst, HIGH(10), HIGH(10));
	S = BITGET(inst, HIGH(4), HIGH(4));
	imm3 = BITGET(inst, 14, 12);
	imm8 = BITGET(inst, 7, 0);

	d = BITGET(inst, 11, 8);
	n = BITGET(inst, HIGH(3), HIGH(0));
	setflags = S ? 1 : 0;
	imm32 = i << 11 | imm3 << 8 | imm8;

	ISA_UNPREDICTABLE_IN_R13_R15(d);
	ISA_UNPREDICTABLE_IN_R13_R15(n);

	AddWithCarry(regfile.reg[n], imm32, APSR.C);

	regfile.reg[d] = result;

	ISA_SET_FLAGS;
}

ISA_THUMB2_REGISTER(adc_imm, 0, 0);

