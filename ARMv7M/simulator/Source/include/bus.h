#ifndef BUS_H
#define BUS_H

/* default is read */
#define BUS_IO_WRITE	(BIT(0))
#define BUS_IO_BYTE	(BIT(1))
#define BUS_IO_HALF	(BIT(1) | BIT(2))
#define BUS_IO_WORD	(BIT(1) | BIT(2) | BIT(3) | BIT(4))

/* IO CTRL can be extend to support burst transfer */

/*
 * if the slave is DMA or PCI device, it can also be master
 * name: the name will be used to match memory map table
 */
struct bus_slave {
	const char *name;
	void (*clock)(void);
	void (*reset)(void);

	/* why design like this, annouce the IO may failed */
	int (*io)(U32 addr, U8 *data, U32 ctrl);
};

/*
 * attach a slave device to bus
 */
extern int bus_attatch(struct bus_slave *slave);

extern int bus_io(U32 addr, U8 *data, U32 ctrl);

/*
 * for masters only
 */
static inline int bus_write_byte(U32 addr, U8 data)
{
	return bus_io(addr, (U8 *)&data, BUS_IO_WRITE | BUS_IO_BYTE);
}

static inline int bus_write_half(U32 addr, U16 data)
{
	return bus_io(addr, (U8 *)&data, BUS_IO_WRITE | BUS_IO_HALF);
}

static inline int bus_write_word(U32 addr, U32 data)
{
	return bus_io(addr, (U8 *)&data, BUS_IO_WRITE | BUS_IO_WORD);
}

static inline int bus_read_byte(U32 addr, U8 *data)
{
	return bus_io(addr, (U8 *)data, BUS_IO_BYTE);
}

static inline int bus_read_half(U32 addr, U16 *data)
{
	return bus_io(addr, (U8 *)data, BUS_IO_HALF);
}

static inline int bus_read_word(U32 addr, U32 *data)
{
	return bus_io(addr, (U8 *)data, BUS_IO_WORD);
}

#endif
