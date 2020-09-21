# Difference between WFI and WFE

The WFE/WFI always be implemented to make CPU enter standby(clock off, keep
power) mode.

The WFE/SEV can be used in multicore processor, for example, to implement the
spinlock.

Actually it is not a good example, as spinlock take a very short CPU time. WFE
can be used to sync multicore's events.



