#include <common.h>

int main()
{
	load_rom("rom.bin");

	/* attach IPs to BUS */
	ip_ram_attach();
	ip_rom_attach();

	core_start();

    return 0;
}
