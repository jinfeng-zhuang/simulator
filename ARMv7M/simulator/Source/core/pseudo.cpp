// Refer to Chapter D7

#include <common.h>
#include "pseudo.h"

U32 result;
U32 carry;
U32 overflow;

void AddWithCarry(U32 x, U32 y, U32 carry_in)
{
	U64 u_sum = Uint(x) + Uint(y) + Uint(carry_in);
	S64 s_sum = Sint(x) + Sint(y) + Uint(carry_in);

	result = BITGET(u_sum, 0, 31);
	carry = Uint(result) == u_sum ? 0 : 1;
	overflow = Sint(result) == s_sum ? 0 : 1;
}

void BranchTo(U32 addr)
{
	core.reg[PC] = addr;
}

void BranchWritePC(U32 addr)
{
	BranchTo(addr & (~BIT(0)));
}

void ALUWritePC(U32 addr)
{
	BranchWritePC(addr);
}

void BLXWritePC(U32 addr)
{
	BranchTo(addr & (~BIT(0)));
}

void BXWritePC(U32 addr)
{
	BranchTo(addr & (~BIT(0)));
}

void LoadWritePC(U32 addr)
{
	BXWritePC(addr);
}

U32 BitCount(U32 v)
{
	U32 count = 0;

	for (int i = 0; i < 32; i++) {
		if (v & BIT(i)) {
			count++;
		}
	}

	return count;
}