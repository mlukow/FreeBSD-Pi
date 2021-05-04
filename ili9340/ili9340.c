#include <stdio.h>
#include <stdlib.h>

#include "ili9340_driver.h"

int main(int argc, char **argv) {
	// 320x240
	// font 5x7
	// 64x30
	ili9340_t *tft = ili9340_init(8, 0, 25, 11, 10, 9);
	if (!tft) {
		fprintf(stderr, "Could not initialize GPIO\n");
		return EXIT_FAILURE;
	}

	ili9340_clear(tft);
	ili9340_printf(tft, "Hello %s", "world");
	ili9340_printf(tft, ". Will this work?\n");
	ili9340_printf(tft, "Yup!");

	ili9340_puts(
			tft,
			"Hello world",
			100,
			100,
			get_color(0xff, 0x00, 0x00),
			0x00);

	return EXIT_SUCCESS;
}
