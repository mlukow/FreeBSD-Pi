#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>

#include "dht11_read.h"

int main(int argc, char **argv) {
	float temperature, humidity;
	int ret = dht11_read(11, 17, &humidity, &temperature);

	if (ret == EXIT_SUCCESS) {
		printf("temperature: %f, humidity: %f\n", temperature, humidity);
	} else {
		fprintf(stderr, "Read error\n");
	}

	return ret;
}
