#include "../core.h"

#define OPERATION						\
	AddWithCarry(R[n], imm32, 0);				\
	R[d] = result;						\
	ISA_SET_FLAGS;

static void add_imm_t1(unsigned short inst)
{
	ISA_LOCAL_VARS;

	imm3 = BITGET(inst, 8, 6);

	d = BITGET(inst, 2, 0);
	d = BITGET(inst, 5, 3);
	setflags = !InITBlock();

	ZeroExtend(imm3, 32);

	OPERATION;
}

ISA_THUMB_REGISTER(add_imm_t1, 0, 0);

static void add_imm_t2(unsigned short inst)
{
	ISA_LOCAL_VARS;

	imm8 = BITGET(inst, 7, 0);

	d = BITGET(inst, 10, 8);
	n = d;
	setflags = !InITBlock();

	ZeroExtend(imm8, 32);

	OPERATION;
}

ISA_THUMB_REGISTER(add_imm_t2, 0, 0);

static void adc_reg_t3(unsigned int inst)
{
	ISA_LOCAL_VARS;

	i = BITGET(inst, HIGH(10), HIGH(10));
	S = BITGET(inst, HIGH(4), HIGH(4));
	imm3 = BITGET(inst, 14, 12);
	imm8 = BITGET(inst, 7, 0);

	d = BITGET(inst, 11, 8);
	n = BITGET(inst, HIGH(3), HIGH(0));
	m = BITGET(inst, 3, 0);
	setflags = (S == 1);

	// TODO CMN / ADD_SP_PLUS_IMM

	ThumbExpandImm(i << 11 | imm3 << 8 | imm8);

	ISA_UNPREDICTABLE_IN_R13_R15(d); // TODO and S == '0'
	ISA_UNPREDICTABLE_IN_R13_R15(n);
	ISA_UNPREDICTABLE_IN_R13_R15(m);

	OPERATION;
}

ISA_THUMB2_REGISTER(adc_reg_t3, 0, 0);

static void adc_reg_t4(unsigned int inst)
{
	ISA_LOCAL_VARS;

	i = BITGET(inst, HIGH(10), HIGH(10));
	imm3 = BITGET(inst, 14, 12);
	imm8 = BITGET(inst, 7, 0);

	d = BITGET(inst, 11, 8);
	n = BITGET(inst, HIGH(3), HIGH(0));
	m = BITGET(inst, 3, 0);
	setflags = false;

	// TODO ADR / ADD_SP_PLUS_IMM

	ThumbExpandImm(i << 11 | imm3 << 8 | imm8);

	ISA_UNPREDICTABLE_IN_R13_R15(d); // TODO and S == '0'
	ISA_UNPREDICTABLE_IN_R13_R15(n);
	ISA_UNPREDICTABLE_IN_R13_R15(m);

	OPERATION;
}

ISA_THUMB2_REGISTER(adc_reg_t4, 0, 0);

