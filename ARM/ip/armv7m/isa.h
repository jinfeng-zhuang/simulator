#ifndef _ARMV7M_ISA_H
#define _ARMV7M_ISA_H

#define HIGH(nr)	((nr)+16)

struct thumb_instruction {
	const char *name;
	unsigned short mask;
	unsigned short value;
	void (*cb)(unsigned short inst);
};

struct thumb2_instruction {
	const char *name;
	unsigned int mask;
	unsigned int value;
	void (*cb)(unsigned int inst);
};

// TODO distinguish multiple register in a same file
#define ISA_THUMB_REGISTER(name,mask,value)			\
	static struct thumb_instruction				\
		_instruction_##name				\
		__attribute__ ((used, section("thumb"))) =	\
		{#name, mask, value, name};

#define ISA_THUMB2_REGISTER(name,mask,value)			\
	static struct thumb2_instruction			\
		_instruction_##name				\
		__attribute__ ((used, section("thumb2"))) =	\
		{#name, mask, value, name};

#define ISA_UNPREDICTABLE_IN_R13_R15(x)	assert(x < 13)

#endif
