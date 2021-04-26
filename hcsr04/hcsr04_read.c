#include <sys/time.h>
#include <sys/types.h>
#include <libgpio.h>
#include <stdlib.h>
#include <unistd.h>

#include <common.h>

#include "hcsr04_read.h"

// 10 microseconds of high state on the TRIGGER pin initiates a readout.
#define SIGNAL_TTL 10

int hcsr04_read(int pin_echo, int pin_trigger, float *distance) {
	*distance = 0.0f;

	// Initialize GPIO library.
	gpio_handle_t handle = gpio_open(0);
	if (handle == GPIO_INVALID_HANDLE) {
		return EXIT_FAILURE;
	}

	// Set ECHO pin to input.
	gpio_pin_input(handle, pin_echo);

	// Set TRIGGER pin to output.
	gpio_pin_output(handle, pin_trigger);

	// Bump up process priority and change scheduler to try to make process more
	// 'real time'.
	set_max_priority();

	// Set TRIGGER pin to high to initiate a readout.
	gpio_pin_high(handle, pin_trigger);
	busy_wait_microseconds(SIGNAL_TTL);
	gpio_pin_low(handle, pin_trigger);

	struct timeval start, end;

	// Wait for low state on ECHO.
	gettimeofday(&start, NULL);
	while (gpio_pin_get(handle, pin_echo)) {
		gettimeofday(&start, NULL);
	}

	// Measure the time spent in high state on ECHO.
	gettimeofday(&end, NULL);
	while (!gpio_pin_get(handle, pin_echo)) {
		gettimeofday(&end, NULL);
	}

	gpio_close(handle);

	// Calculate time difference in seconds.
	float diff = (end.tv_sec - start.tv_sec);
	diff += (end.tv_usec - start.tv_usec) / 1000000.0f;
	// Sonic speec = 343 cm/s.
	diff *= 34300;
	// There and back travel.
	diff /= 2.0f;
	// Convert centimeters to meters.
	*distance = diff / 100.0f;

	return EXIT_SUCCESS;
}
