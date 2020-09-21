#include <simulator.h>

void delay_1s(void)
{
	static time_t cur = 0;

	while (cur == time(NULL));

	cur = time(NULL);
}

int main(int argc, char *argv[])
{
	DBG("simulator %s\n", VERSION);

	DBG("build %s %s\n", __DATE__, __TIME__);

	signal_clock_init();
	
	/* one loop = one cycle */
	while (1) {
		signal_clock_posedge();
		delay_1s();
	}
	
	return 0;
}
