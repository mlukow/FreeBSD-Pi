#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>

#include "pi_dht_read.h"

int main(int argc, char **argv) {
	float temperature, humidity;
	int ret = pi_dht_read(11, 17, &humidity, &temperature);
	switch (ret) {
		case DHT_ERROR_TIMEOUT:
			fprintf(stderr, "Read timeout\n");
			break;
		case DHT_ERROR_CHECKSUM:
			fprintf(stderr, "Checksum error\n");
			break;
		case DHT_ERROR_ARGUMENT:
			fprintf(stderr, "Argument error\n");
			break;
		case DHT_ERROR_GPIO:
			fprintf(stderr, "GPIO error\n");
			break;
		default:
			printf("temperature: %f, humidity: %f\n", temperature, humidity);
	}

	return EXIT_SUCCESS;
}
