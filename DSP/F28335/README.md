# README

1. What is Page 0 and Page 1

	It is similar to code section(rx) and data section(rw), no size limit.
	There is a register to store section number - PT. The section number range
	is (0, 255).

2. Sections

	.text
	.cinit global and static var
	.const string ...
	.econst string
	.print ?
	.switch table
	.bss
	.ebss ?
	.stack
	.system heap
	.esystem heap

	#pragma CODE_SECTION(symbol, "my section")
	#pragma DATA_SECTION(symbol, "my section")
