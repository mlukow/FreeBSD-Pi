# HC-SR04

A program demonstrating how to take measurements with an ultrasonic distance sensor. It is assumed that the sensor's TRIGGER pin is connected to the BCM pin 17 (physical pin 11) and ECHO pin is connected via a 300/470 Ohm divider (in order to make the output 5V into 3.3V) to the BCM pin 27 (physical pin 13) of the Raspberry Pi.

You can find the datasheetfor HC-SR04 [here](https://web.eece.maine.edu/~zhu/book/lab/HC-SR04%20User%20Manual.pdf);

# Usage

In order to build the executable file, run `make`. Run as root!
