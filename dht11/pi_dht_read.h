#ifndef PI_DHT_READ_H
#define PI_DHT_READ_H

#include "common_dht_read.h"

// Read DHT sensor connected to GPIO pin (using BCM numbering).  Humidity and temperature will be 
// returned in the provided parameters. If a successfull reading could be made a value of 0 
// (DHT_SUCCESS) will be returned.  If there was an error reading the sensor a negative value will
// be returned.  Some errors can be ignored and retried, specifically DHT_ERROR_TIMEOUT or DHT_ERROR_CHECKSUM.
int pi_dht_read(int sensor, int pin, float* humidity, float* temperature);

#endif
