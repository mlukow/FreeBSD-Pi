#ifndef __ILI9340_DRIVER__
#define __ILI9340_DRIVER__

#include <sys/types.h>

typedef struct ili9340_t ili9340_t;

uint16_t get_color(uint8_t r, uint8_t g, uint8_t b);

void ili9340_clear(struct ili9340_t * /* tft */);

void ili9340_draw_pixel(
		struct ili9340_t * /* tft */,
		uint16_t /* x */,
		uint16_t /* y */,
		uint32_t /* color */);

struct ili9340_t *ili9340_init(
		uint8_t /* pin_cs */,
		uint8_t /* pin_rst */,
		uint8_t /* pin_dc */,
		uint8_t /* pin_sck */,
		uint8_t /* pin_mosi */,
		uint8_t /* pin_miso */);

void ili9340_printf(
		struct ili9340_t * /* tft */,
		const char * /* fmt */,
		... /* args */);

void ili9340_putc(
		struct ili9340_t * /* tft */,
		char /* c */,
		uint16_t /* x */,
		uint16_t /* y */,
		uint32_t /* fg */,
		uint32_t /* bg */);

void ili9340_puts(
		struct ili9340_t * /* tft */,
		const char * /* s */,
		uint16_t /* x */,
		uint16_t /* y */,
		uint32_t /* fg */,
		uint32_t /* bg */);

#endif /* __ILI9340_DRIVER__ */
