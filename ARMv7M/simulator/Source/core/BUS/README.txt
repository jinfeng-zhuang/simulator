# Memory Model

## Endian Support

### Restrictions

* The endianness setting only applies to data accesses. Instruction fetches are always little endian.
* All accesses to the SCS are little endian

The AIRCR.ENDIANNESS bit indicates the endianness, 0 = Little, 1 = Big.

## Synchronization

A Load-Exclusive instruction tags a small block of memory for exclusive access. The size of the tagged block is
IMPLEMENTATION DEFINED, see Tagging and the size of the tagged memory block on page A3-75.

## Memory Types

## Access Right

## Order

## Hierarchy

## Reference

* Chapter A3
* Memory Model.vsdx