#ifndef CORE_PSEUDO_H
#define CORE_PSEUDO_H

#define Uint(x)	((U32)(x))
#define Sint(x)	((S32)(x))

extern U32 result;
extern U32 carry;
extern U32 overflow;

extern void AddWithCarry(U32 x, U32 y, U32 carry_in);
extern void ALUWritePC(U32 addr);
extern void BranchTo(U32 addr);
extern void BranchWritePC(U32 addr);
extern void LoadWritePC(U32 addr);
extern void BXWritePC(U32 addr);
extern void BLXWritePC(U32 addr);
extern U32 BitCount(U32 v);

#endif