#ifndef __DHT11_READ_H__
#define __DHT11_READ_H__

#include <common.h>

// Read DHT sensor connected to GPIO pin (using BCM numbering).  Humidity and
// temperature will be returned in the provided parameters. If a successful
// reading could be made a value of 0  (EXIT_SUCCESS) will be returned.  If
// there was an error reading the sensor a value of 1 (EXIT_FAILURE) will be
// returned.
int dht11_read(int sensor, int pin, float* humidity, float* temperature);

#endif /* __DHT11_READ_H__ */
