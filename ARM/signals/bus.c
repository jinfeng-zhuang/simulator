#define DEBUG

#include <simulator.h>

extern unsigned int __start_bus;
extern unsigned int __stop_bus;

static struct signal_bus *bus_begin = (void *)&__start_bus;
static struct signal_bus *bus_end = (void *)&__stop_bus;

void signal_bus_init(void)
{
}

int bus_request(unsigned int addr, unsigned char *buffer, unsigned int len, int dir)
{
	assert(NULL != buffer);

	struct signal_bus *item;

	for (item = bus_begin; item < bus_end; item++) {
		if ((item->addr <= addr) && (item->addr + item->size > addr)) {
			if (BUS_DIR_READ == dir) {
				assert(NULL != item->read);
				DBG("read @%08x: %s\n", addr, item->name);
				item->read(addr - item->addr, buffer, len);
				return 0;
			}
			else {
				assert(NULL != item->write);
				DBG("read @%08x: %s\n", addr, item->name);
				item->write(addr - item->addr, buffer, len);
				return 0;
			}
		}
	}

	return -1;
}
