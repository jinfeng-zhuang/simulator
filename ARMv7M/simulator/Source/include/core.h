#ifndef CORE_H
#define CORE_H

#include <types.h>

#define SP (13)
#define LR (14)
#define PC (15)

#define VTOR (*(VU32 *)0xe000e200)

/*
 * APSR:
 *   N	- Negative, 1 means result is negative
 *   Z	- Zero, 1 means result is 0
 *   C	- Carry, different meaning in add/sub/cmp/shift operations
 *   V	- oVerflow, apply to signed number, BIT(31) is the symbol bit.
 *				BIT(31).1 + BIT(31).1 => BIT(31).0, or 
 *				BIT(30).1 + BIT(30).1 => BIT(31) change
 *   Q	-
 *   GE	-
 */

struct apsr {
	U32 N : 1;
	U32 Z : 1;
	U32 C : 1;
	U32 V : 1;
	U32 RSVD : 28;
};

struct core {
	 U32 reg[16];
	 U32 epsr;
	 struct apsr apsr;
};

enum vector_table {
	VECTOR_STACK,
	VECTOR_RESET,
	VECTOR_NMI,
	VECTOR_HARD_FAULT,
	VECTOR_MEM_MANAGE,
	VECTOR_BUS_FAULT,
	VECTOR_USAGE_FAULT,
	VECTOR_SVC = 11,
	VECTOR_DEBUG_MONITOR,
	VECTOR_PENDSV = 14,
	VECTOR_SYSTICK,
};

extern struct core core;

extern U16 pipeline_fetch_thumb16(void);
extern void pipeline_execute_thumb16(U16 instruction);

#endif