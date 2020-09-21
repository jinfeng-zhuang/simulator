#define DEBUG

#include <simulator.h>

extern unsigned int __start_reset;
extern unsigned int __stop_reset;

static struct signal_reset *reset_begin = (void *)&__start_reset;
static struct signal_reset *reset_end = (void *)&__stop_reset;

void signal_reset(void)
{
	struct signal_reset *item;

	for (item = reset_begin; item < reset_end; item++) {
		if (item->cb) {
			DBG("reset posedge: %s\n", item->name);
			item->cb();
		}
	}
}
