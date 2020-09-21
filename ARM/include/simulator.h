#ifndef SIMULATOR_H
#define SIMULATOR_H

// standard c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// linux platform
#include <time.h>
#include <assert.h>

// internal
#include "signal.h"
#include "bitops.h"

#define VERSION "0.0.0"

#define MACHINE_WIDTH	(32)

extern unsigned int sys_clock_count;

#ifdef DEBUG
#define DBG(fmt, ...) printf("[Simulator] [%d] " fmt, sys_clock_count, ##__VA_ARGS__);
#else
#define DBG(fmt, ...)
#endif

typedef unsigned int (*register_action_t)(unsigned int val, unsigned int opt);

#endif

