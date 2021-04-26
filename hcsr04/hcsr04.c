#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>

#include "hcsr04_read.h"

int main(int argc, char **argv) {
	float distance;
	int ret = hcsr04_read(27, 17, &distance);
	if (ret == EXIT_SUCCESS) {
		printf("Distance: %.2fm\n", distance);
	} else {
		fprintf(stderr, "Could not read distance: %d\n", ret);
		return ret;
	}

	return EXIT_SUCCESS;
}
