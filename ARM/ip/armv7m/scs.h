#ifndef _ARMV7M_SCS_H
#define _ARMV7M_SCS_H

volatile struct scs {
	// E000E000: interrupt ctrl and aux ctrl
	unsigned int RSVD_E000;
	unsigned int ICTR;
	unsigned int ACTLR;
	unsigned int RSVD_E00C;

	// E000E010: systick
	unsigned int SYST_CSR;
	unsigned int SYST_RVR;
	unsigned int SYST_CVR;
	unsigned int SYST_CALIB;
	unsigned int RSVD_E020_E100[(0xE100 - 0xE020) >> 2];

	// E000E100: nvic
	unsigned int NVIC_ISER[16];
	unsigned int RSVD_E140_E180[(0xE180 - 0xE140) >> 2];
	unsigned int NVIC_ICER[16];
	unsigned int RSVD_E1C0_E200[(0xE200 - 0xE1C0) >> 2];
	unsigned int NVIC_ISPR[16];
	unsigned int RSVD_E240_E280[(0xE280 - 0xE240) >> 2];
	unsigned int NVIC_ICPR[16];
	unsigned int RSVD_E2C0_E300[(0xE300 - 0xE2C0) >> 2];
	unsigned int NVIC_IABR[16];
	unsigned int RSVD_E340_E400[(0xE400 - 0xE340) >> 2];
	unsigned int NVIC_IPR[124];
	unsigned int RSVD_E5F0_ED00[(0xED00 - 0xE5F0) >> 2];

	// E000ED00: scb
	unsigned int CPUID;
	unsigned int ICSR;
	unsigned int VTOR;
	unsigned int AIRCR;
	unsigned int SCR;
	unsigned int CCR;
	unsigned int SHPR1;
	unsigned int SHPR2;
	unsigned int SHPR3;
	unsigned int SHCSR;
	unsigned int CFSR;
	unsigned int HFSR;
	unsigned int DFSR;
	unsigned int MMFAR;
	unsigned int BFAR;
	unsigned int AFSR;
	unsigned int RSVD_ED40_ED88[(0xED88 - 0xED40) >> 2];
	unsigned int CPACR;
	unsigned int RSVD_ED8C;

	// E000ED90: mpu
	unsigned int MPU_TYPE;
	unsigned int MPU_CTRL;
	unsigned int MPU_RNR;
	unsigned int MPU_RBAR;
	unsigned int MPU_RASR;
	unsigned int MPU_RBAR_A1;
	unsigned int MPU_RBSR_A1;
	unsigned int MPU_RBAR_A2;
	unsigned int MPU_RBSR_A2;
	unsigned int MPU_RBAR_A3;
	unsigned int MPU_RBSR_A3;
	unsigned int RSVD_EDBC_EDF0[(0xEDF0 - 0xEDBC) >> 2];

	// E000EDF0: debug
	unsigned int DHCSR;
	unsigned int DCRSR;
	unsigned int DCRDR;
	unsigned int DEMCR;
	unsigned int RSVD_EE00_EF00[(0xEF00 - 0xEE00) >> 2];

	// E000EF00: swi
	unsigned int STIR;
	unsigned int RSVD_EF04_EF34[(0xEF34 - 0xEF04) >> 2];
	unsigned int RSVD_EF34_EF4C[(0xEF4C - 0xEF34) >> 2];
	unsigned int RSVD_EF4C;

	// E000EF50: cache and bp
	unsigned int ICIALLU;
	unsigned int RSVD_EF54;
	unsigned int ICIMVAU;
	unsigned int DCIMVAC;
	unsigned int DCISW;
	unsigned int DCCMVAU;
	unsigned int DCCMVAC;
	unsigned int DCCSW;
	unsigned int DCCIMVAC;
	unsigned int DCCISW;
	unsigned int BPIALL;
	unsigned int RSVD_EF7C;
	unsigned int RSVD_EF80;

	unsigned int RSVD_EF84_EF90[(0xEF90 - 0xEF84) >> 2];

	// E000EF90: reserved for implementation
	unsigned int RSVD_EF90_EFD0[(0xEFD0 - 0xEF90) >> 2];

	// E000EFD0: id space
	unsigned int PID4;
	unsigned int PID5;
	unsigned int PID6;
	unsigned int PID7;
	unsigned int PID0;
	unsigned int PID1;
	unsigned int PID2;
	unsigned int PID3;
	unsigned int CID0;
	unsigned int CID1;
	unsigned int CID2;
	unsigned int CID3;
};

#endif

