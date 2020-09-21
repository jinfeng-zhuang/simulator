# Simulator

## Why

I prefer to work with software and a little hardware development, however,
the gap between sw & hw prevent me to do a great job.

This is why I am here.

## Implementation Suggestions

* NO-status machine, all the action should affect on registers

## Architecture

The clock posedge drives all the IPs' internal logic, while the bus serves an
channel for memory mapped area data access.

Instruction bus and data bus are uniform, otherwise, there may exist a data
bus, an instruction bus, an IO bus.

If multiple buses supported, there will exist AXI, AHB and APB buses.

The UART/SPI/GPIO will communicate with devices by TCP/IP, the devices can be
an adapter which drives real hardware device.

The IO protocol is a common framework on signal.

![architecture-pure](./img/pure.png)

### Clock

### BUS

Features:

* Byte, half, word, double word access
* Support burst transfer
* All types of transfer completes in one cycle

### Reset

## Debug

## Reference

* https://github.com/riscv/riscv-opcodes
