CC=/usr/bin/cc

CFLAGS= -std=iso9899:1999 -pedantic -g -O0 -fno-builtin \
				-mtune=cortex-a72 -mlittle-endian

CPPFLAGS = -D_TS_ERRNO -D_POSIX_PTHREAD_SEMANTIX -D_LARGEFILE64_SOURCE \
					 -D_XOPEN_SOURCE=600

LDFLAGS = -lgpio

all: hcsr04

hcsr04:
	$(CC) -o $@ *.c ../common/*.c -I../common $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -rf hcsr04 *.o
