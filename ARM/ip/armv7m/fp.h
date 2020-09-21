#ifndef _ARMV7M_FP_H
#define _ARMV7M_FP_H

struct fp_single_precision_registers {
	volatile unsigned int S0;
	volatile unsigned int S1;
	volatile unsigned int S2;
	volatile unsigned int S3;
	volatile unsigned int S4;
	volatile unsigned int S5;
	volatile unsigned int S6;
	volatile unsigned int S7;
	volatile unsigned int S8;
	volatile unsigned int S9;
	volatile unsigned int S10;
	volatile unsigned int S11;
	volatile unsigned int S12;
	volatile unsigned int S13;
	volatile unsigned int S14;
	volatile unsigned int S15;
	volatile unsigned int S16;
	volatile unsigned int S17;
	volatile unsigned int S18;
	volatile unsigned int S19;
	volatile unsigned int S20;
	volatile unsigned int S21;
	volatile unsigned int S22;
	volatile unsigned int S23;
	volatile unsigned int S24;
	volatile unsigned int S25;
	volatile unsigned int S26;
	volatile unsigned int S27;
	volatile unsigned int S28;
	volatile unsigned int S29;
	volatile unsigned int S30;
	volatile unsigned int S31;
};

struct fp_double_precision_registers {
	volatile unsigned long long D0;
	volatile unsigned long long D1;
	volatile unsigned long long D2;
	volatile unsigned long long D3;
	volatile unsigned long long D4;
	volatile unsigned long long D5;
	volatile unsigned long long D6;
	volatile unsigned long long D7;
	volatile unsigned long long D8;
	volatile unsigned long long D9;
	volatile unsigned long long D10;
	volatile unsigned long long D11;
	volatile unsigned long long D12;
	volatile unsigned long long D13;
	volatile unsigned long long D14;
	volatile unsigned long long D15;
};

#endif

