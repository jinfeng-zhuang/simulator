#define DEBUG

#include "core.h"

static void clock_posedge(void)
{
	unsigned short instruction;
	unsigned short instruction32;

	instruction = core_read16(regfile.pc);

	if (core_isa_is_thumb(instruction))
		core_isa_thumb_execute(instruction);
	else {
		instruction32 = instruction << 16 | core_read16(regfile.pc + 2);
		core_isa_thumb2_execute(instruction32);
	}
}

static void reset_negedge(void)
{
	regfile.r0 = 0;
	regfile.r1 = 0;
	regfile.r2 = 0;
	regfile.r3 = 0;
	regfile.r4 = 0;
	regfile.r5 = 0;
	regfile.r6 = 0;
	regfile.r7 = 0;
	regfile.r8 = 0;
	regfile.r9 = 0;
	regfile.r10 = 0;
	regfile.r11 = 0;
	regfile.r12 = 0;

	regfile.sp = core_read32(VECTOR_BASE + 0);
	regfile.lr = CORE_EXCEPTION_RETURN_ADDR;
	regfile.pc = core_read32(VECTOR_BASE + 0x4);
}

SIGNAL_CLOCK_REGISTER("core", clock_posedge);
SIGNAL_RESET_REGISTER("core", reset_negedge);
