OUTPUT_ARCH( "riscv" )

ENTRY( _start )

STACK_SIZE = 0x1000;

MEMORY
{
	FLASH : ORIGIN = 0x80000000, LENGTH = 0x00020000
	RAM : ORIGIN = 0x80020000, LENGTH = 0x00020000
}

SECTIONS
{
	.text : {
		*(.text)
	} > FLASH

	.rodata : {
		. = ALIGN(8);
		*(.rodata)
		*(.rodata.*)
	} > RAM

	.data :	{
		. = ALIGN(8);
		*(.data)
		*(.data.*)
	} > RAM

	.sbss : {
		. = ALIGN(8);
		*(.sbss)
		*(.sbss.*)
	} > RAM

	.bss : {
		. = ALIGN(8);
		*(.bss)
		*(.bss.*)
	} > RAM

	.stack : {
		stack_bottom = .;
		. += STACK_SIZE;
		. = ALIGN(8);
		stack_top = .;
	} > RAM
}

