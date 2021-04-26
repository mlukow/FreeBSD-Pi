# HC-SR04

<img width="379" alt="hcsr04" src="https://user-images.githubusercontent.com/82239121/116139229-16c2a800-a6d6-11eb-804a-0e3077491453.png">


A program demonstrating how to take measurements with an ultrasonic distance sensor. It is assumed that the sensor's TRIGGER pin is connected to the BCM pin 17 (physical pin 11) and ECHO pin is connected via a 300/470 Ohm divider (in order to make the output 5V into 3.3V) to the BCM pin 27 (physical pin 13) of the Raspberry Pi.

You can find the datasheet for HC-SR04 [here](http://web.eece.maine.edu/~zhu/book/lab/HC-SR04%20User%20Manual.pdf).

# Usage

In order to build the executable file, run `make`. Run as root!
