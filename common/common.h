#ifndef COMMON_DHT_READ_H
#define COMMON_DHT_READ_H

#include <stdint.h>

// Busy wait delay for most accurate timing, but high CPU usage.
// Only use this for times shorter than one millisecond!
void busy_wait_microseconds(uint32_t micros);

// Busy wait delay for most accurate timing, but high CPU usage.
// Only use this for short periods of time (a few hundred milliseconds at most)!
void busy_wait_milliseconds(uint32_t millis);

// General delay that sleeps so CPU usage is low, but accuracy is potentially bad.
void sleep_milliseconds(uint32_t millis);

// Increase scheduling priority and algorithm to try to get 'real time' results.
void set_max_priority(void);

// Drop scheduling priority back to normal/default.
void set_default_priority(void);

#endif
