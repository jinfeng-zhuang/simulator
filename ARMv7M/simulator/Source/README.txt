## Parallel

The IP's process are parallel.

## Memory Address Space

IO read/write will trigger the IP's behaviour in polling mode.
It is recommanded that each module registers its own io function.

TODO: need sort them, to search more quick.

* mmio_read
* mmio_write

## CPU Address Space

* core_read
* core_write

## Code Style

make each module individual! use some global varibales, follow hardware rules.