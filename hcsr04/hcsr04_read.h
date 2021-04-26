#ifndef __HCSR04_READ__
#define __HCSR04_READ__

// Read HCSR04 sensor connected to GPIO pins (using BCM numbering). Distance
// will be returned in the provided parameter. If a successful readin could be
// made a value of 0 (EXIT_SUCCESS) will be returned. If there was an error
// reading the sensor a value of 1 (EXIT_FAILURE) will be returned.
int hcsr04_read(int pin_echo, int pin_trigger, float *distance);

#endif /* __HCSR04_READ__ */
