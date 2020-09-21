#ifndef CORE_H
#define CORE_H

#include <types.h>
#include <bitops.h>

extern VU32 R[];

#define SP	R[13]
#define LR	R[14]
#define PC	R[15]

/*
 * Usage:
 *   SET/CLR BITS
 *   SET/CLR BIT
 */
extern VU32 APSR;
extern VU32 IPSR;
extern VU32 EPSR;

#define APSR_N		(31)
#define APSR_Z		(30)
#define APSR_C		(29)
#define APSR_V		(28)

#define IPSR_NO		(0)

#endif