#include <stdio.h>
#include <stdint.h>
#include "db_buf.h"


int main(int argc, char **argv) {
	int i;

	((void)argc);
	((void)argv);

	DB_BUF_INIT(uint16_t, sensor);

	for(i=0; i<10; i++) {
		DB_BUF_SET(sensor, i*2);
		printf("%d: %04X\n", i, DB_BUF_GET(sensor));
	}

	return 0;
}
