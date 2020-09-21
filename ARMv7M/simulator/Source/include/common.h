#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bitops.h>
#include <const.h>
#include <core.h>
#include <isa.h>
#include <memory.h>
#include <types.h>

#define ALIGN4(x) ((x + 3) & 0xFFFFFFFC)

extern void load_rom(const char *romfile);
extern void core_start(void);
extern void ip_rom_attach(void);
extern void ip_ram_attach(void);

#endif