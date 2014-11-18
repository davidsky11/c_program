CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c 
CFLAGS = -lcrypt

all: catch_SIGHUP disc_SIGHUP setsid_t
	echo "build all..."

catch_SIGHUP: catch_SIGHUP.c
	$(CC) -g catch_SIGHUP.c $(INCLUDE) -o catch_SIGHUP

disc_SIGHUP: disc_SIGHUP.c
	$(CC) -g disc_SIGHUP.c $(INCLUDE) -o disc_SIGHUP

setsid_t: setsid_t.c
	$(CC) -g setsid_t.c $(INCLUDE) -o setsid_t

clean:
	rm -rf *.a *.o catch_SIGHUP disc_SIGHUP setsid_t
