CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c ../lib/signal_functions.c

all: display_env env_t reboot_t
	echo "build all..."

env_t: env_t.c
	$(CC) -g env_t.c $(INCLUDE) -o env_t

kill_t: kill_t.c
	$(CC) -g kill_t.c $(INCLUDE) -o kill_t

ouch: ouch.c
	$(CC) -g ouch.c $(INCLUDE) -o ouch

reboot_t: reboot_t.c
	$(CC) -g reboot_t.c $(INCLUDE) -o reboot_t

clean:
	rm -rf *.a *.o display_env env_t reboot_t
