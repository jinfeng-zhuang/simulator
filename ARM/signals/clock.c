#define DEBUG

#include <simulator.h>

extern unsigned int __start_clock;
extern unsigned int __stop_clock;

static struct signal_clock *clock_begin = (void *)&__start_clock;
static struct signal_clock *clock_end = (void *)&__stop_clock;

unsigned int sys_clock_count;

void signal_clock_init(void)
{
}

void signal_clock_posedge(void)
{
	struct signal_clock *clock;

	sys_clock_count++;

	for (clock = clock_begin; clock < clock_end; clock++) {
		if (clock->cb) {
			DBG("clock posedge: %s\n", clock->name);
			clock->cb();
		}
	}
}

