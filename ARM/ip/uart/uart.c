// The file has been auto generated

//------------------------------------------------------------------------------
//				Header
//------------------------------------------------------------------------------
#include <simulator.h>

#include "config.h"

static unsigned int register_action_dr(unsigned int value, unsigned int option);
static unsigned int register_action_int_en(unsigned int value, unsigned int option);
static unsigned int register_action_int_id(unsigned int value, unsigned int option);
static unsigned int register_action_fifo_ctl(unsigned int value, unsigned int option);
static unsigned int register_action_line_ctl(unsigned int value, unsigned int option);
static unsigned int register_action_modem_ctl(unsigned int value, unsigned int option);
static unsigned int register_action_line_sts(unsigned int value, unsigned int option);
static unsigned int register_action_modem_sts(unsigned int value, unsigned int option);
static unsigned int register_action_divisor0(unsigned int value, unsigned int option);
static unsigned int register_action_divisor1(unsigned int value, unsigned int option);

//------------------------------------------------------------------------------
//				Registers
//------------------------------------------------------------------------------

enum {
	REG_DR,
	REG_INT_EN,
	REG_INT_ID,
	REG_FIFO_CTL,
	REG_LINE_CTL,
	REG_MODEM_CTL,
	REG_LINE_STS,
	REG_MODEM_STS,
	REG_DIVISOR0,
	REG_DIVISOR1
};

#define REG_RESET_VALUE_DR		0
#define REG_RESET_VALUE_INT_EN		0
#define REG_RESET_VALUE_INT_ID		0
#define REG_RESET_VALUE_FIFO_CTL	0
#define REG_RESET_VALUE_LINE_CTL	0
#define REG_RESET_VALUE_MODEM_CTL	0
#define REG_RESET_VALUE_LINE_STS	0
#define REG_RESET_VALUE_MODEM_STS	0
#define REG_RESET_VALUE_DIVISOR0	0
#define REG_RESET_VALUE_DIVISOR1	0

static const unsigned int register_reset_value[] = {
	REG_RESET_VALUE_DR,
	REG_RESET_VALUE_INT_EN,
	REG_RESET_VALUE_INT_ID,
	REG_RESET_VALUE_FIFO_CTL,
	REG_RESET_VALUE_LINE_CTL,
	REG_RESET_VALUE_MODEM_CTL,
	REG_RESET_VALUE_LINE_STS,
	REG_RESET_VALUE_MODEM_STS,
	REG_RESET_VALUE_DIVISOR0,
	REG_RESET_VALUE_DIVISOR1
};

static unsigned int register_value[] = {
	REG_RESET_VALUE_DR,
	REG_RESET_VALUE_INT_EN,
	REG_RESET_VALUE_INT_ID,
	REG_RESET_VALUE_FIFO_CTL,
	REG_RESET_VALUE_LINE_CTL,
	REG_RESET_VALUE_MODEM_CTL,
	REG_RESET_VALUE_LINE_STS,
	REG_RESET_VALUE_MODEM_STS,
	REG_RESET_VALUE_DIVISOR0,
	REG_RESET_VALUE_DIVISOR1
};

static register_action_t register_action[] = {
	register_action_dr,
	register_action_int_en,
	register_action_int_id,
	register_action_fifo_ctl,
	register_action_line_ctl,
	register_action_modem_ctl,
	register_action_line_sts,
	register_action_modem_sts,
	register_action_divisor0,
	register_action_divisor1
};

//------------------------------------------------------------------------------
//									Signals
//------------------------------------------------------------------------------

/*
 * 1. send data out
 * 2. receive data
 * 3. send interrupt signal
 */
static void signal_clock(void)
{
	static unsigned int count = 0;
	
	count++;
}

#ifdef UART_SUPPORT_RESET_SIGNAL
static void signal_reset(void)
{
	memcpy(registers, register_reset_value, sizeof(registers));
}
#endif

static int signal_read(unsigned int addr, unsigned char *data, unsigned int length)
{
	assert(NULL != data);
	assert(addr < sizeof(register_value));
	assert(MACHINE_WIDTH == length);

	register_action[addr](0, BUS_DIR_READ);

	*(unsigned int *)data = register_value[addr];

	return 0;
}

static int signal_write(unsigned int addr, unsigned char *data, unsigned int length)
{
	assert(NULL != data);
	assert(addr < sizeof(register_value));
	assert(MACHINE_WIDTH == length);

	unsigned int value = *(unsigned int *)data;

	register_action[addr](value, BUS_DIR_WRITE);

	register_value[addr] = *(unsigned int *)data;

	return 0;
}

// TODO register signals here
// TODO how to support multi-instance
SIGNAL_CLOCK_REGISTER("uart", signal_clock);
SIGNAL_BUS_REGISTER("uart", 0x40000000, 1024, signal_read, signal_write);

//------------------------------------------------------------------------------
//									Internals definition
//------------------------------------------------------------------------------

static unsigned int register_action_dr(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_int_en(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_int_id(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_fifo_ctl(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_line_ctl(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_modem_ctl(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_line_sts(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_modem_sts(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_divisor0(unsigned int value, unsigned int option)
{
	return 0;
}

static unsigned int register_action_divisor1(unsigned int value, unsigned int option)
{
	return 0;
}

