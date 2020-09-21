#include <common.h>

void pipeline_execute_thumb16(U16 instruction)
{
	int i;

	for (i = 0; ; i++) {
		if (0 == ISA_Array[i].mask) {
			assert(0);
			break;
		}
		if ((instruction & ISA_Array[i].mask) == ISA_Array[i].value) {
			printf("0x%08X\t%04x\t%s\t", core.reg[PC]-2, instruction, ISA_Array[i].name);
			ISA_Array[i].proc(instruction);
			break;
		}
	}
}

U16 pipeline_fetch_thumb16(void)
{
	U16 inst;

	inst = mmio_read(core.reg[PC]) & 0xFFFF;

	core.reg[PC] += 2; // TODO +4 or +2?

	return inst;
}