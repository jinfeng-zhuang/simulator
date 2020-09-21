#ifndef BIT_H
#define BIT_H

#define BIT(n)	(1 << (n))

#define BITMASK(s, e)	(((1 << ((e) - (s) + 1)) - 1) << (s))

#define BITGET(inst, s, e)		((inst & BITMASK(s, e)) >> (s))
#define BITCLR(inst, s, e)		(inst & (~BITMASK(s, e)))
#define BITSET(inst, s, e, v)	(BITCLR(inst, s, e) | (v) << (s))

#define BITVAL(v, o) (((v) & BIT(o)) ? 1 : 0) 

#endif