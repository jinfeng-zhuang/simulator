#ifndef BITOPS_H
#define BITOPS_H

#include <assert.h>

#define BIT(nr)				(1ULL<<(nr))

#define BITMASK(width)			(BIT(width) - 1)

#define BITCLR(reg, b, a)						\
	(reg) = ((reg) & (~(BITMASK((b) - (a) + 1) << (a))))

#define BITSET(reg, b, a, value)					\
	do {								\
		assert(BITMASK(b - a + 1) >= value);			\
		reg = 	(BITCLR(reg, b, a)) |				\
			(((value) & BITMASK(b - a + 1)) << (a));	\
	} while (0)

#define BITGET(reg, b, a)						\
	(((reg) >> (a)) & BITMASK(b - a + 1))

#endif
