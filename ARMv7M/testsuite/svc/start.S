	.global vector

vector:
	.word stack_top
	.word isr_reset
	.word isr_nmi
	.word isr_hard_fault
	.word isr_mem_manage
	.word isr_bus_fault
	.word isr_usage_fault
	.word 0
	.word 0
	.word 0
	.word 0
	.word isr_svc
	.word isr_debug_monitor
	.word 0
	.word isr_pendsv
	.word isr_systick

isr_reset:
	svc $0

isr_nmi:
isr_hard_fault:
isr_mem_manage:
isr_bus_fault:
isr_usage_fault:
isr_svc:
isr_debug_monitor:
isr_pendsv:
isr_systick:
	b .