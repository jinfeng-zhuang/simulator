#ifndef ISA_H
#define ISA_H

#include <types.h>

struct ISA {
	U16 mask;
	U16 value;
	void (*proc)(U16 instruction);
	const char *name;
};

extern struct ISA ISA_Array[];

extern void INSTRUCTION_LSL(U16 instruction);
extern void INSTRUCTION_LSR(U16 instruction);
extern void INSTRUCTION_ASR(U16 instruction);
extern void INSTRUCTION_ADD(U16 instruction);
extern void INSTRUCTION_SUB(U16 instruction);
extern void INSTRUCTION_MOV(U16 instruction);
extern void INSTRUCTION_CMP(U16 instruction);
extern void INSTRUCTION_AND(U16 instruction);
extern void INSTRUCTION_EOR(U16 instruction);
extern void INSTRUCTION_LSL(U16 instruction);
extern void INSTRUCTION_ADC(U16 instruction);
extern void INSTRUCTION_SBC(U16 instruction);
extern void INSTRUCTION_ROR(U16 instruction);
extern void INSTRUCTION_TST(U16 instruction);
extern void INSTRUCTION_RSB(U16 instruction);
extern void INSTRUCTION_CMN(U16 instruction);
extern void INSTRUCTION_ORR(U16 instruction);
extern void INSTRUCTION_MUL(U16 instruction);
extern void INSTRUCTION_BIC(U16 instruction);
extern void INSTRUCTION_MVN(U16 instruction);
extern void INSTRUCTION_UNPREDICTABLE(U16 instruction);
extern void INSTRUCTION_BX(U16 instruction);
extern void INSTRUCTION_BLX(U16 instruction);
extern void INSTRUCTION_LDR(U16 instruction);
extern void INSTRUCTION_STR(U16 instruction);
extern void INSTRUCTION_STRH(U16 instruction);
extern void INSTRUCTION_STRB(U16 instruction);
extern void INSTRUCTION_LDRSB(U16 instruction);
extern void INSTRUCTION_LDRH(U16 instruction);
extern void INSTRUCTION_LDRB(U16 instruction);
extern void INSTRUCTION_LDRSH(U16 instruction);
extern void INSTRUCTION_ADR(U16 instruction);
extern void INSTRUCTION_CPS(U16 instruction);
extern void INSTRUCTION_CBNZ(U16 instruction);
extern void INSTRUCTION_SXTH(U16 instruction);
extern void INSTRUCTION_SXTB(U16 instruction);
extern void INSTRUCTION_UXTH(U16 instruction);
extern void INSTRUCTION_UXTB(U16 instruction);
extern void INSTRUCTION_PUSH(U16 instruction);
extern void INSTRUCTION_REV(U16 instruction);
extern void INSTRUCTION_REV16(U16 instruction);
extern void INSTRUCTION_REVSH(U16 instruction);
extern void INSTRUCTION_POP(U16 instruction);
extern void INSTRUCTION_BKPT(U16 instruction);
extern void INSTRUCTION_IT(U16 instruction);
extern void INSTRUCTION_NOP(U16 instruction);
extern void INSTRUCTION_YIELD(U16 instruction);
extern void INSTRUCTION_WFE(U16 instruction);
extern void INSTRUCTION_WFI(U16 instruction);
extern void INSTRUCTION_SEV(U16 instruction);
extern void INSTRUCTION_STM(U16 instruction);
extern void INSTRUCTION_LDM(U16 instruction);
extern void INSTRUCTION_B(U16 instruction);
extern void INSTRUCTION_UNDEFINED(U16 instruction);
extern void INSTRUCTION_SVC(U16 instruction);

#endif
