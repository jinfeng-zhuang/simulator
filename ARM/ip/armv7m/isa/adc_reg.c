#include "../core.h"

#define OPERATION						\
	Shift(R[m], shift_t, shift_n, APSR.C);			\
	AddWithCarry(R[n], shifted, APSR.C);			\
	R[d] = result;						\
	ISA_SET_FLAGS;

static void adc_reg_t1(unsigned short inst)
{
	ISA_LOCAL_VARS;

	d = BITGET(inst, 2, 0);
	n = d;
	m = BITGET(inst, 5, 3);
	setflags = !InITBlock();

	OPERATION;
}

ISA_THUMB_REGISTER(adc_reg_t1, 0, 0);

static void adc_reg_t2(unsigned int inst)
{
	ISA_LOCAL_VARS;

	S = BITGET(inst, HIGH(4), HIGH(4));
	imm3 = BITGET(inst, 14, 12);
	imm2 = BITGET(inst, 7, 6);
	type = BITGET(inst, 5, 4);

	d = BITGET(inst, 11, 8);
	n = BITGET(inst, HIGH(3), HIGH(0));
	m = BITGET(inst, 3, 0);
	setflags = (S == 1);

	DecodeImmShift(type, imm3<<2 | imm2);

	ISA_UNPREDICTABLE_IN_R13_R15(d);
	ISA_UNPREDICTABLE_IN_R13_R15(n);
	ISA_UNPREDICTABLE_IN_R13_R15(m);

	OPERATION;
}

ISA_THUMB2_REGISTER(adc_reg_t2, 0, 0);

