#include <common.h>

void INSTRUCTION_LSL(U16 instruction)
{
	U8 imm5;
	U8 Rm;
	U8 Rd;

	imm5 = BITGET(instruction, 6, 10);
	Rm = BITGET(instruction, 3, 5);
	Rd = BITGET(instruction, 0, 2);

	core.reg[Rd] = core.reg[Rm] << imm5;

	core.apsr.N = BIT(31) & core.reg[Rd] ? 1 : 0;
	core.apsr.Z = (0 == core.reg[Rd]) ? 1 : 0;
	core.apsr.C = (BIT(31) & (core.reg[Rm] << (imm5 - 1))) ? 1 : 0;

	printf("r%d, r%d, #%d\n", Rm, Rd, imm5);
}

void INSTRUCTION_LSR(U16 instruction)
{

}

void INSTRUCTION_ASR(U16 instruction)
{

}

void INSTRUCTION_ADD(U16 instruction)
{

}

void INSTRUCTION_SUB(U16 instruction)
{

}

void INSTRUCTION_MOV(U16 instruction)
{

}

void INSTRUCTION_CMP(U16 instruction)
{

}

void INSTRUCTION_AND(U16 instruction)
{

}

void INSTRUCTION_EOR(U16 instruction)
{

}

void INSTRUCTION_ADC(U16 instruction)
{

}

void INSTRUCTION_SBC(U16 instruction)
{

}

void INSTRUCTION_ROR(U16 instruction)
{

}

void INSTRUCTION_TST(U16 instruction)
{

}

void INSTRUCTION_RSB(U16 instruction)
{

}

void INSTRUCTION_CMN(U16 instruction)
{

}

void INSTRUCTION_ORR(U16 instruction)
{

}

void INSTRUCTION_MUL(U16 instruction)
{

}

void INSTRUCTION_BIC(U16 instruction)
{

}

void INSTRUCTION_MVN(U16 instruction)
{

}

void INSTRUCTION_UNPREDICTABLE(U16 instruction)
{

}

void INSTRUCTION_BX(U16 instruction)
{
	U8 Rm;

	Rm = BITGET(instruction, 3, 6);

	core.reg[PC] = core.reg[Rm] & 0xFFFFFFFE;

	printf("r%d\n", Rm);
}

void INSTRUCTION_BLX(U16 instruction)
{
	U8 Rm;

	Rm = BITGET(instruction, 3, 6);

	if (PC == Rm) {
		assert(0);
	}

	core.reg[LR] = core.reg[PC] + 1; // THUMB

	// TODO: check the destination's validation

	core.reg[PC] = core.reg[Rm] & 0xFFFFFFFE;

	printf("r%d\n", Rm);
}

void INSTRUCTION_LDR(U16 instruction)
{
	U8 imm8;
	U8 Rt;
	U32 base;
	U32 addr;

	// Align PC to 4 bytes
	base = ALIGN4(core.reg[PC]);

	imm8 = BITGET(instruction, 0, 7);
	Rt = BITGET(instruction, 8, 10);

	addr = base + imm8 * 4;
	core.reg[Rt] = mmio_read(addr);

	printf("r%d,[pc,#%d]\t; @0x%08X\n", Rt, imm8 * 4, addr);
}

void INSTRUCTION_STR(U16 instruction)
{
	U8 imm5;
	U8 imm8;
	U8 Rm;
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

void INSTRUCTION_STRH(U16 instruction)
{

}

void INSTRUCTION_STRB(U16 instruction)
{

}

void INSTRUCTION_LDRSB(U16 instruction)
{

}

void INSTRUCTION_LDRH(U16 instruction)
{

}

void INSTRUCTION_LDRB(U16 instruction)
{

}

void INSTRUCTION_LDRSH(U16 instruction)
{

}

void INSTRUCTION_ADR(U16 instruction)
{

}

void INSTRUCTION_CPS(U16 instruction)
{

}

void INSTRUCTION_CBNZ(U16 instruction)
{

}

void INSTRUCTION_SXTH(U16 instruction)
{

}

void INSTRUCTION_SXTB(U16 instruction)
{

}

void INSTRUCTION_UXTH(U16 instruction)
{

}

void INSTRUCTION_UXTB(U16 instruction)
{

}

void INSTRUCTION_PUSH(U16 instruction)
{

}

void INSTRUCTION_REV(U16 instruction)
{

}

void INSTRUCTION_REV16(U16 instruction)
{

}

void INSTRUCTION_REVSH(U16 instruction)
{

}

void INSTRUCTION_POP(U16 instruction)
{

}

void INSTRUCTION_BKPT(U16 instruction)
{

}

void INSTRUCTION_IT(U16 instruction)
{

}

void INSTRUCTION_NOP(U16 instruction)
{

}

void INSTRUCTION_YIELD(U16 instruction)
{

}

void INSTRUCTION_WFE(U16 instruction)
{

}

void INSTRUCTION_WFI(U16 instruction)
{

}

void INSTRUCTION_SEV(U16 instruction)
{

}

void INSTRUCTION_STM(U16 instruction)
{

}

void INSTRUCTION_LDM(U16 instruction)
{

}

void INSTRUCTION_B(U16 instruction)
{

}

void INSTRUCTION_UNDEFINED(U16 instruction)
{

}

void INSTRUCTION_SVC(U16 instruction)
{

}

