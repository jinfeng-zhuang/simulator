#ifndef SIGNAL_H
#define SIGNAL_H

struct signal_clock {
	const char *name;
	void (*cb)(void);
};

struct signal_reset {
	const char *name;
	void (*cb)(void);
};

struct signal_bus {
	const char *name;
	unsigned int addr;
	unsigned int size;
	int (*read)(unsigned int addr, unsigned char *buf, unsigned int len);
	int (*write)(unsigned int addr, unsigned char *buf, unsigned int len);
};

// TODO add {...} for it
// used: warning: 'clock' defined but not used
// don't use ".clock" as I will use __start_clock
#define SIGNAL_CLOCK_REGISTER(name, callback)			\
	static struct signal_clock				\
		_clock						\
		__attribute__ ((used, section("clock"))) =	\
		{name, callback};

#define SIGNAL_RESET_REGISTER(name, callback)			\
	static struct signal_reset				\
		_reset						\
		__attribute__ ((used, section("reset"))) =	\
		{name, callback};

#define SIGNAL_BUS_REGISTER(name, start, size, read, write)	\
	static struct signal_bus				\
		_io						\
		__attribute__ ((used, section("bus"))) =	\
		{name, start, size, read, write};

extern void signal_clock_init(void);
extern void signal_reset_init(void);
extern void signal_bus_init(void);

extern void signal_clock_posedge(void);
extern void signal_reset_negedge(void);

enum {
	BUS_DIR_READ = 0,
	BUS_DIR_WRITE = 1
};

extern int bus_request(
	unsigned int addr,
	unsigned char *val,
	unsigned int len,
	int dir
	);

#endif

